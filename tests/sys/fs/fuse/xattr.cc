/*-
 * SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * Copyright (c) 2019 The FreeBSD Foundation
 *
 * This software was developed by BFF Storage Systems, LLC under sponsorship
 * from the FreeBSD Foundation.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

extern "C" {
#include <sys/types.h>
#include <sys/extattr.h>
#include <string.h>
}

#include "mockfs.hh"
#include "utils.hh"

using namespace testing;

const char FULLPATH[] = "mountpoint/some_file.txt";
const char RELPATH[] = "some_file.txt";

/* For testing filesystems without posix locking support */
class Xattr: public FuseTest {
public:
void expect_getxattr(uint64_t ino, const char *attr, ProcessMockerT r)
{
	EXPECT_CALL(*m_mock, process(
		ResultOf([=](auto in) {
			const char *a = (const char*)in->body.bytes +
				sizeof(fuse_getxattr_in);
			return (in->header.opcode == FUSE_GETXATTR &&
				in->header.nodeid == ino &&
				0 == strcmp(attr, a));
		}, Eq(true)),
		_)
	).WillOnce(Invoke(r));
}

void expect_listxattr(uint64_t ino, uint32_t size, ProcessMockerT r)
{
	EXPECT_CALL(*m_mock, process(
		ResultOf([=](auto in) {
			return (in->header.opcode == FUSE_LISTXATTR &&
				in->header.nodeid == ino &&
				in->body.listxattr.size == size);
		}, Eq(true)),
		_)
	).WillOnce(Invoke(r))
	.RetiresOnSaturation();
}

void expect_removexattr(uint64_t ino, const char *attr, int error)
{
	EXPECT_CALL(*m_mock, process(
		ResultOf([=](auto in) {
			const char *a = (const char*)in->body.bytes;
			return (in->header.opcode == FUSE_REMOVEXATTR &&
				in->header.nodeid == ino &&
				0 == strcmp(attr, a));
		}, Eq(true)),
		_)
	).WillOnce(Invoke(ReturnErrno(error)));
}

void expect_setxattr(uint64_t ino, const char *attr, const char *value,
	ProcessMockerT r)
{
	EXPECT_CALL(*m_mock, process(
		ResultOf([=](auto in) {
			const char *a = (const char*)in->body.bytes +
				sizeof(fuse_setxattr_in);
			const char *v = a + strlen(a) + 1;
			return (in->header.opcode == FUSE_SETXATTR &&
				in->header.nodeid == ino &&
				0 == strcmp(attr, a) &&
				0 == strcmp(value, v));
		}, Eq(true)),
		_)
	).WillOnce(Invoke(r));
}

};

class Getxattr: public Xattr {};
class Listxattr: public Xattr {};
class Removexattr: public Xattr {};
class Setxattr: public Xattr {};

/* 
 * If the extended attribute does not exist on this file, the daemon should
 * return ENOATTR (ENODATA on Linux, but it's up to the daemon to choose the
 * correct errror code)
 */
TEST_F(Getxattr, enoattr)
{
	char data[80];
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;
	ssize_t r;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_getxattr(ino, "user.foo", ReturnErrno(ENOATTR));

	r = extattr_get_file(FULLPATH, ns, "foo", data, sizeof(data));
	ASSERT_EQ(-1, r);
	ASSERT_EQ(ENOATTR, errno);
}

/*
 * If the filesystem returns ENOSYS, then it will be treated as a permanent
 * failure and all future VOP_GETEXTATTR calls will fail with EOPNOTSUPP
 * without querying the filesystem daemon
 */
/* https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=236557 */
TEST_F(Getxattr, DISABLED_enosys)
{
	char data[80];
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;
	ssize_t r;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_getxattr(ino, "user.foo", ReturnErrno(ENOSYS));

	r = extattr_get_file(FULLPATH, ns, "foo", data, sizeof(data));
	ASSERT_EQ(-1, r);
	EXPECT_EQ(EOPNOTSUPP, errno);

	/* Subsequent attempts should not query the filesystem at all */
	r = extattr_get_file(FULLPATH, ns, "foo", data, sizeof(data));
	ASSERT_EQ(-1, r);
	EXPECT_EQ(EOPNOTSUPP, errno);
}

/*
 * On FreeBSD, if the user passes an insufficiently large buffer then the
 * filesystem is supposed to copy as much of the attribute's value as will fit.
 *
 * On Linux, however, the filesystem is supposed to return ERANGE.
 *
 * libfuse specifies the Linux behavior.  However, that's probably an error.
 * It would probably be correct for the filesystem to use platform-dependent
 * behavior.
 *
 * This test case covers a filesystem that uses the Linux behavior
 */
TEST_F(Getxattr, erange)
{
	char data[10];
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;
	ssize_t r;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_getxattr(ino, "user.foo", ReturnErrno(ERANGE));

	r = extattr_get_file(FULLPATH, ns, "foo", data, sizeof(data));
	ASSERT_EQ(-1, r);
	ASSERT_EQ(ERANGE, errno);
}

/*
 * If the user passes a 0-length buffer, then the daemon should just return the
 * size of the attribute
 */
TEST_F(Getxattr, size_only)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_getxattr(ino, "user.foo",
		ReturnImmediate([](auto in __unused, auto out) {
			SET_OUT_HEADER_LEN(out, getxattr);
			out->body.getxattr.size = 99;
		})
	);

	ASSERT_EQ(99, extattr_get_file(FULLPATH, ns, "foo", NULL, 0))
		<< strerror(errno);;
}

/*
 * Successfully get an attribute from the system namespace
 */
TEST_F(Getxattr, system)
{
	uint64_t ino = 42;
	char data[80];
	const char value[] = "whatever";
	ssize_t value_len = strlen(value) + 1;
	int ns = EXTATTR_NAMESPACE_SYSTEM;
	ssize_t r;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_getxattr(ino, "system.foo",
		ReturnImmediate([&](auto in __unused, auto out) {
			memcpy((void*)out->body.bytes, value, value_len);
			out->header.len = sizeof(out->header) + value_len;
		})
	);

	r = extattr_get_file(FULLPATH, ns, "foo", data, sizeof(data));
	ASSERT_EQ(value_len, r)  << strerror(errno);
	EXPECT_STREQ(value, data);
}

/*
 * Successfully get an attribute from the user namespace
 */
TEST_F(Getxattr, user)
{
	uint64_t ino = 42;
	char data[80];
	const char value[] = "whatever";
	ssize_t value_len = strlen(value) + 1;
	int ns = EXTATTR_NAMESPACE_USER;
	ssize_t r;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_getxattr(ino, "user.foo",
		ReturnImmediate([&](auto in __unused, auto out) {
			memcpy((void*)out->body.bytes, value, value_len);
			out->header.len = sizeof(out->header) + value_len;
		})
	);

	r = extattr_get_file(FULLPATH, ns, "foo", data, sizeof(data));
	ASSERT_EQ(value_len, r)  << strerror(errno);
	EXPECT_STREQ(value, data);
}

/*
 * If the filesystem returns ENOSYS, then it will be treated as a permanent
 * failure and all future VOP_LISTEXTATTR calls will fail with EOPNOTSUPP
 * without querying the filesystem daemon
 */
/* https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=236557 */
TEST_F(Listxattr, DISABLED_enosys)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_listxattr(ino, 0, ReturnErrno(ENOSYS));

	ASSERT_EQ(-1, extattr_list_file(FULLPATH, ns, NULL, 0));
	EXPECT_EQ(EOPNOTSUPP, errno);

	/* Subsequent attempts should not query the filesystem at all */
	ASSERT_EQ(-1, extattr_list_file(FULLPATH, ns, NULL, 0));
	EXPECT_EQ(EOPNOTSUPP, errno);
}

/*
 * Listing extended attributes failed because they aren't configured on this
 * filesystem
 */
TEST_F(Listxattr, enotsup)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_listxattr(ino, 0, ReturnErrno(ENOTSUP));

	ASSERT_EQ(-1, extattr_list_file(FULLPATH, ns, NULL, 0));
	ASSERT_EQ(ENOTSUP, errno);
}

/*
 * On FreeBSD, if the user passes an insufficiently large buffer then the
 * filesystem is supposed to copy as much of the attribute's value as will fit.
 *
 * On Linux, however, the filesystem is supposed to return ERANGE.
 *
 * libfuse specifies the Linux behavior.  However, that's probably an error.
 * It would probably be correct for the filesystem to use platform-dependent
 * behavior.
 *
 * This test case covers a filesystem that uses the Linux behavior
 */
TEST_F(Listxattr, erange)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_listxattr(ino, 0, ReturnErrno(ERANGE));

	ASSERT_EQ(-1, extattr_list_file(FULLPATH, ns, NULL, 0));
	ASSERT_EQ(ERANGE, errno);
}

/*
 * Get the size of the list that it would take to list no extended attributes
 */
TEST_F(Listxattr, size_only_empty)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_listxattr(ino, 0, ReturnImmediate([](auto i __unused, auto out) {
		out->body.listxattr.size = 0;
		SET_OUT_HEADER_LEN(out, listxattr);
	}));

	ASSERT_EQ(0, extattr_list_file(FULLPATH, ns, NULL, 0))
		<< strerror(errno);
}

/*
 * Get the size of the list that it would take to list some extended
 * attributes.  Due to the format differences between a FreeBSD and a
 * Linux/FUSE extended attribute list, fuse(4) will actually allocate a buffer
 * and get the whole list, then convert it, just to figure out its size.
 */
TEST_F(Listxattr, size_only_nonempty)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_listxattr(ino, 0, ReturnImmediate([](auto i __unused, auto out) {
		out->body.listxattr.size = 45;
		SET_OUT_HEADER_LEN(out, listxattr);
	}));

	// TODO: fix the expected size after fixing the size calculation bug in
	// fuse_vnop_listextattr.  It should be exactly 45.
	expect_listxattr(ino, 53,
		ReturnImmediate([](auto in __unused, auto out) {
			const char l[] = "user.foo";
			strlcpy((char*)out->body.bytes, l,
				sizeof(out->body.bytes));
			out->header.len = sizeof(fuse_out_header) + sizeof(l);
		})
	);

	ASSERT_EQ(4, extattr_list_file(FULLPATH, ns, NULL, 0))
		<< strerror(errno);
}

TEST_F(Listxattr, size_only_really_big)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_listxattr(ino, 0, ReturnImmediate([](auto i __unused, auto out) {
		out->body.listxattr.size = 16000;
		SET_OUT_HEADER_LEN(out, listxattr);
	}));

	// TODO: fix the expected size after fixing the size calculation bug in
	// fuse_vnop_listextattr.  It should be exactly 16000.
	expect_listxattr(ino, 16008,
		ReturnImmediate([](auto in __unused, auto out) {
			const char l[16] = "user.foobarbang";
			for (int i=0; i < 1000; i++) {
				memcpy(&out->body.bytes[16 * i], l, 16);
			}
			out->header.len = sizeof(fuse_out_header) + 16000;
		})
	);

	ASSERT_EQ(11000, extattr_list_file(FULLPATH, ns, NULL, 0))
		<< strerror(errno);
}

/* 
 * List all of the user attributes of a file which has both user and system
 * attributes
 */
TEST_F(Listxattr, user)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;
	char data[80];
	char expected[9] = {3, 'f', 'o', 'o', 4, 'b', 'a', 'n', 'g'};
	char attrs[28] = "user.foo\0system.x\0user.bang";

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_listxattr(ino, 0,
		ReturnImmediate([&](auto in __unused, auto out) {
			out->body.listxattr.size = sizeof(attrs);
			SET_OUT_HEADER_LEN(out, listxattr);
		})
	);

	// TODO: fix the expected size after fixing the size calculation bug in
	// fuse_vnop_listextattr.
	expect_listxattr(ino, sizeof(attrs) + 8,
	ReturnImmediate([&](auto in __unused, auto out) {
		memcpy((void*)out->body.bytes, attrs, sizeof(attrs));
		out->header.len = sizeof(fuse_out_header) + sizeof(attrs);
	}));

	ASSERT_EQ((ssize_t)sizeof(expected),
		extattr_list_file(FULLPATH, ns, data, sizeof(data)))
		<< strerror(errno);
	ASSERT_EQ(0, memcmp(expected, data, sizeof(expected)));
}

/* 
 * List all of the system attributes of a file which has both user and system
 * attributes
 */
TEST_F(Listxattr, system)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_SYSTEM;
	char data[80];
	char expected[2] = {1, 'x'};
	char attrs[28] = "user.foo\0system.x\0user.bang";

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_listxattr(ino, 0,
		ReturnImmediate([&](auto in __unused, auto out) {
			out->body.listxattr.size = sizeof(attrs);
			SET_OUT_HEADER_LEN(out, listxattr);
		})
	);

	// TODO: fix the expected size after fixing the size calculation bug in
	// fuse_vnop_listextattr.
	expect_listxattr(ino, sizeof(attrs) + 8,
	ReturnImmediate([&](auto in __unused, auto out) {
		memcpy((void*)out->body.bytes, attrs, sizeof(attrs));
		out->header.len = sizeof(fuse_out_header) + sizeof(attrs);
	}));

	ASSERT_EQ((ssize_t)sizeof(expected),
		extattr_list_file(FULLPATH, ns, data, sizeof(data)))
		<< strerror(errno);
	ASSERT_EQ(0, memcmp(expected, data, sizeof(expected)));
}

/* Fail to remove a nonexistent attribute */
TEST_F(Removexattr, enoattr)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_removexattr(ino, "user.foo", ENOATTR);

	ASSERT_EQ(-1, extattr_delete_file(FULLPATH, ns, "foo"));
	ASSERT_EQ(ENOATTR, errno);
}

/*
 * If the filesystem returns ENOSYS, then it will be treated as a permanent
 * failure and all future VOP_DELETEEXTATTR calls will fail with EOPNOTSUPP
 * without querying the filesystem daemon
 */
/* https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=236557 */
TEST_F(Removexattr, DISABLED_enosys)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_removexattr(ino, "user.foo", ENOSYS);

	ASSERT_EQ(-1, extattr_delete_file(FULLPATH, ns, "foo"));
	EXPECT_EQ(EOPNOTSUPP, errno);

	/* Subsequent attempts should not query the filesystem at all */
	ASSERT_EQ(-1, extattr_delete_file(FULLPATH, ns, "foo"));
	EXPECT_EQ(EOPNOTSUPP, errno);
}

/* Successfully remove a user xattr */
TEST_F(Removexattr, user)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_USER;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_removexattr(ino, "user.foo", 0);

	ASSERT_EQ(0, extattr_delete_file(FULLPATH, ns, "foo"))
		<< strerror(errno);
}

/* Successfully remove a system xattr */
TEST_F(Removexattr, system)
{
	uint64_t ino = 42;
	int ns = EXTATTR_NAMESPACE_SYSTEM;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_removexattr(ino, "system.foo", 0);

	ASSERT_EQ(0, extattr_delete_file(FULLPATH, ns, "foo"))
		<< strerror(errno);
}

/*
 * If the filesystem returns ENOSYS, then it will be treated as a permanent
 * failure and all future VOP_SETEXTATTR calls will fail with EOPNOTSUPP
 * without querying the filesystem daemon
 */
/* https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=236557 */
TEST_F(Setxattr, DISABLED_enosys)
{
	uint64_t ino = 42;
	const char value[] = "whatever";
	ssize_t value_len = strlen(value) + 1;
	int ns = EXTATTR_NAMESPACE_USER;
	ssize_t r;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_setxattr(ino, "user.foo", value, ReturnErrno(ENOSYS));

	r = extattr_set_file(FULLPATH, ns, "foo", (void*)value, value_len);
	ASSERT_EQ(-1, r);
	EXPECT_EQ(EOPNOTSUPP, errno);

	/* Subsequent attempts should not query the filesystem at all */
	r = extattr_set_file(FULLPATH, ns, "foo", (void*)value, value_len);
	ASSERT_EQ(-1, r);
	EXPECT_EQ(EOPNOTSUPP, errno);
}

/*
 * SETXATTR will return ENOTSUP if the namespace is invalid or the filesystem
 * as currently configured doesn't support extended attributes.
 */
TEST_F(Setxattr, enotsup)
{
	uint64_t ino = 42;
	const char value[] = "whatever";
	ssize_t value_len = strlen(value) + 1;
	int ns = EXTATTR_NAMESPACE_USER;
	ssize_t r;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_setxattr(ino, "user.foo", value, ReturnErrno(ENOTSUP));

	r = extattr_set_file(FULLPATH, ns, "foo", (void*)value, value_len);
	ASSERT_EQ(-1, r);
	EXPECT_EQ(ENOTSUP, errno);
}

/*
 * Successfully set a user attribute.
 */
TEST_F(Setxattr, user)
{
	uint64_t ino = 42;
	const char value[] = "whatever";
	ssize_t value_len = strlen(value) + 1;
	int ns = EXTATTR_NAMESPACE_USER;
	ssize_t r;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_setxattr(ino, "user.foo", value, ReturnErrno(0));

	r = extattr_set_file(FULLPATH, ns, "foo", (void*)value, value_len);
	ASSERT_EQ(value_len, r) << strerror(errno);
}

/*
 * Successfully set a system attribute.
 */
TEST_F(Setxattr, system)
{
	uint64_t ino = 42;
	const char value[] = "whatever";
	ssize_t value_len = strlen(value) + 1;
	int ns = EXTATTR_NAMESPACE_SYSTEM;
	ssize_t r;

	expect_lookup(RELPATH, ino, S_IFREG | 0644, 1);
	expect_setxattr(ino, "system.foo", value, ReturnErrno(0));

	r = extattr_set_file(FULLPATH, ns, "foo", (void*)value, value_len);
	ASSERT_EQ(value_len, r) << strerror(errno);
}
