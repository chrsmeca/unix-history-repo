/*
 * System call names.
 *
 * DO NOT EDIT-- this file is automatically @generated.
 * $FreeBSD$
 */

const char *syscallnames[] = {
	"syscall",			/* 0 = syscall */
	"exit",			/* 1 = exit */
	"fork",			/* 2 = fork */
	"read",			/* 3 = read */
	"write",			/* 4 = write */
	"open",			/* 5 = open */
	"close",			/* 6 = close */
	"wait4",			/* 7 = wait4 */
	"compat.creat",		/* 8 = old creat */
	"link",			/* 9 = link */
	"unlink",			/* 10 = unlink */
	"obs_execv",			/* 11 = obsolete execv */
	"chdir",			/* 12 = chdir */
	"fchdir",			/* 13 = fchdir */
	"compat11.mknod",		/* 14 = freebsd11 mknod */
	"chmod",			/* 15 = chmod */
	"chown",			/* 16 = chown */
	"break",			/* 17 = break */
	"compat4.getfsstat",		/* 18 = freebsd4 getfsstat */
	"compat.lseek",		/* 19 = old lseek */
	"getpid",			/* 20 = getpid */
	"mount",			/* 21 = mount */
	"unmount",			/* 22 = unmount */
	"setuid",			/* 23 = setuid */
	"getuid",			/* 24 = getuid */
	"geteuid",			/* 25 = geteuid */
	"ptrace",			/* 26 = ptrace */
	"recvmsg",			/* 27 = recvmsg */
	"sendmsg",			/* 28 = sendmsg */
	"recvfrom",			/* 29 = recvfrom */
	"accept",			/* 30 = accept */
	"getpeername",			/* 31 = getpeername */
	"getsockname",			/* 32 = getsockname */
	"access",			/* 33 = access */
	"chflags",			/* 34 = chflags */
	"fchflags",			/* 35 = fchflags */
	"sync",			/* 36 = sync */
	"kill",			/* 37 = kill */
	"compat.stat",		/* 38 = old stat */
	"getppid",			/* 39 = getppid */
	"compat.lstat",		/* 40 = old lstat */
	"dup",			/* 41 = dup */
	"compat10.pipe",		/* 42 = freebsd10 pipe */
	"getegid",			/* 43 = getegid */
	"profil",			/* 44 = profil */
	"ktrace",			/* 45 = ktrace */
	"compat.sigaction",		/* 46 = old sigaction */
	"getgid",			/* 47 = getgid */
	"compat.sigprocmask",		/* 48 = old sigprocmask */
	"getlogin",			/* 49 = getlogin */
	"setlogin",			/* 50 = setlogin */
	"acct",			/* 51 = acct */
	"compat.sigpending",		/* 52 = old sigpending */
	"sigaltstack",			/* 53 = sigaltstack */
	"ioctl",			/* 54 = ioctl */
	"reboot",			/* 55 = reboot */
	"revoke",			/* 56 = revoke */
	"symlink",			/* 57 = symlink */
	"readlink",			/* 58 = readlink */
	"execve",			/* 59 = execve */
	"umask",			/* 60 = umask */
	"chroot",			/* 61 = chroot */
	"compat.fstat",		/* 62 = old fstat */
	"compat.getkerninfo",		/* 63 = old getkerninfo */
	"compat.getpagesize",		/* 64 = old getpagesize */
	"msync",			/* 65 = msync */
	"vfork",			/* 66 = vfork */
	"obs_vread",			/* 67 = obsolete vread */
	"obs_vwrite",			/* 68 = obsolete vwrite */
	"sbrk",			/* 69 = sbrk */
	"sstk",			/* 70 = sstk */
	"compat.mmap",		/* 71 = old mmap */
	"compat11.vadvise",		/* 72 = freebsd11 vadvise */
	"munmap",			/* 73 = munmap */
	"mprotect",			/* 74 = mprotect */
	"madvise",			/* 75 = madvise */
	"obs_vhangup",			/* 76 = obsolete vhangup */
	"obs_vlimit",			/* 77 = obsolete vlimit */
	"mincore",			/* 78 = mincore */
	"getgroups",			/* 79 = getgroups */
	"setgroups",			/* 80 = setgroups */
	"getpgrp",			/* 81 = getpgrp */
	"setpgid",			/* 82 = setpgid */
	"setitimer",			/* 83 = setitimer */
	"compat.wait",		/* 84 = old wait */
	"swapon",			/* 85 = swapon */
	"getitimer",			/* 86 = getitimer */
	"compat.gethostname",		/* 87 = old gethostname */
	"compat.sethostname",		/* 88 = old sethostname */
	"getdtablesize",			/* 89 = getdtablesize */
	"dup2",			/* 90 = dup2 */
	"#91",			/* 91 = getdopt */
	"fcntl",			/* 92 = fcntl */
	"select",			/* 93 = select */
	"#94",			/* 94 = setdopt */
	"fsync",			/* 95 = fsync */
	"setpriority",			/* 96 = setpriority */
	"socket",			/* 97 = socket */
	"connect",			/* 98 = connect */
	"compat.accept",		/* 99 = old accept */
	"getpriority",			/* 100 = getpriority */
	"compat.send",		/* 101 = old send */
	"compat.recv",		/* 102 = old recv */
	"compat.sigreturn",		/* 103 = old sigreturn */
	"bind",			/* 104 = bind */
	"setsockopt",			/* 105 = setsockopt */
	"listen",			/* 106 = listen */
	"obs_vtimes",			/* 107 = obsolete vtimes */
	"compat.sigvec",		/* 108 = old sigvec */
	"compat.sigblock",		/* 109 = old sigblock */
	"compat.sigsetmask",		/* 110 = old sigsetmask */
	"compat.sigsuspend",		/* 111 = old sigsuspend */
	"compat.sigstack",		/* 112 = old sigstack */
	"compat.recvmsg",		/* 113 = old recvmsg */
	"compat.sendmsg",		/* 114 = old sendmsg */
	"obs_vtrace",			/* 115 = obsolete vtrace */
	"gettimeofday",			/* 116 = gettimeofday */
	"getrusage",			/* 117 = getrusage */
	"getsockopt",			/* 118 = getsockopt */
	"#119",			/* 119 = resuba */
	"readv",			/* 120 = readv */
	"writev",			/* 121 = writev */
	"settimeofday",			/* 122 = settimeofday */
	"fchown",			/* 123 = fchown */
	"fchmod",			/* 124 = fchmod */
	"compat.recvfrom",		/* 125 = old recvfrom */
	"setreuid",			/* 126 = setreuid */
	"setregid",			/* 127 = setregid */
	"rename",			/* 128 = rename */
	"compat.truncate",		/* 129 = old truncate */
	"compat.ftruncate",		/* 130 = old ftruncate */
	"flock",			/* 131 = flock */
	"mkfifo",			/* 132 = mkfifo */
	"sendto",			/* 133 = sendto */
	"shutdown",			/* 134 = shutdown */
	"socketpair",			/* 135 = socketpair */
	"mkdir",			/* 136 = mkdir */
	"rmdir",			/* 137 = rmdir */
	"utimes",			/* 138 = utimes */
	"obs_4.2",			/* 139 = obsolete 4.2 sigreturn */
	"adjtime",			/* 140 = adjtime */
	"compat.getpeername",		/* 141 = old getpeername */
	"compat.gethostid",		/* 142 = old gethostid */
	"compat.sethostid",		/* 143 = old sethostid */
	"compat.getrlimit",		/* 144 = old getrlimit */
	"compat.setrlimit",		/* 145 = old setrlimit */
	"compat.killpg",		/* 146 = old killpg */
	"setsid",			/* 147 = setsid */
	"quotactl",			/* 148 = quotactl */
	"compat.quota",		/* 149 = old quota */
	"compat.getsockname",		/* 150 = old getsockname */
	"#151",			/* 151 = sem_lock */
	"#152",			/* 152 = sem_wakeup */
	"#153",			/* 153 = asyncdaemon */
	"nlm_syscall",			/* 154 = nlm_syscall */
	"nfssvc",			/* 155 = nfssvc */
	"compat.getdirentries",		/* 156 = old getdirentries */
	"compat4.statfs",		/* 157 = freebsd4 statfs */
	"compat4.fstatfs",		/* 158 = freebsd4 fstatfs */
	"#159",			/* 159 = nosys */
	"lgetfh",			/* 160 = lgetfh */
	"getfh",			/* 161 = getfh */
	"compat4.getdomainname",		/* 162 = freebsd4 getdomainname */
	"compat4.setdomainname",		/* 163 = freebsd4 setdomainname */
	"compat4.uname",		/* 164 = freebsd4 uname */
	"sysarch",			/* 165 = sysarch */
	"rtprio",			/* 166 = rtprio */
	"#167",			/* 167 = nosys */
	"#168",			/* 168 = nosys */
	"semsys",			/* 169 = semsys */
	"msgsys",			/* 170 = msgsys */
	"shmsys",			/* 171 = shmsys */
	"#172",			/* 172 = nosys */
	"compat6.pread",		/* 173 = freebsd6 pread */
	"compat6.pwrite",		/* 174 = freebsd6 pwrite */
	"setfib",			/* 175 = setfib */
	"ntp_adjtime",			/* 176 = ntp_adjtime */
	"#177",			/* 177 = sfork */
	"#178",			/* 178 = getdescriptor */
	"#179",			/* 179 = setdescriptor */
	"#180",			/* 180 = nosys */
	"setgid",			/* 181 = setgid */
	"setegid",			/* 182 = setegid */
	"seteuid",			/* 183 = seteuid */
	"obs_lfs_bmapv",			/* 184 = obsolete lfs_bmapv */
	"obs_lfs_markv",			/* 185 = obsolete lfs_markv */
	"obs_lfs_segclean",			/* 186 = obsolete lfs_segclean */
	"obs_lfs_segwait",			/* 187 = obsolete lfs_segwait */
	"compat11.stat",		/* 188 = freebsd11 stat */
	"compat11.fstat",		/* 189 = freebsd11 fstat */
	"compat11.lstat",		/* 190 = freebsd11 lstat */
	"pathconf",			/* 191 = pathconf */
	"fpathconf",			/* 192 = fpathconf */
	"#193",			/* 193 = nosys */
	"getrlimit",			/* 194 = getrlimit */
	"setrlimit",			/* 195 = setrlimit */
	"compat11.getdirentries",		/* 196 = freebsd11 getdirentries */
	"compat6.mmap",		/* 197 = freebsd6 mmap */
	"__syscall",			/* 198 = __syscall */
	"compat6.lseek",		/* 199 = freebsd6 lseek */
	"compat6.truncate",		/* 200 = freebsd6 truncate */
	"compat6.ftruncate",		/* 201 = freebsd6 ftruncate */
	"__sysctl",			/* 202 = __sysctl */
	"mlock",			/* 203 = mlock */
	"munlock",			/* 204 = munlock */
	"undelete",			/* 205 = undelete */
	"futimes",			/* 206 = futimes */
	"getpgid",			/* 207 = getpgid */
	"#208",			/* 208 = nosys */
	"poll",			/* 209 = poll */
	"lkmnosys",			/* 210 = lkmnosys */
	"lkmnosys",			/* 211 = lkmnosys */
	"lkmnosys",			/* 212 = lkmnosys */
	"lkmnosys",			/* 213 = lkmnosys */
	"lkmnosys",			/* 214 = lkmnosys */
	"lkmnosys",			/* 215 = lkmnosys */
	"lkmnosys",			/* 216 = lkmnosys */
	"lkmnosys",			/* 217 = lkmnosys */
	"lkmnosys",			/* 218 = lkmnosys */
	"lkmnosys",			/* 219 = lkmnosys */
	"compat7.__semctl",		/* 220 = freebsd7 __semctl */
	"semget",			/* 221 = semget */
	"semop",			/* 222 = semop */
	"obs_semconfig",			/* 223 = obsolete semconfig */
	"compat7.msgctl",		/* 224 = freebsd7 msgctl */
	"msgget",			/* 225 = msgget */
	"msgsnd",			/* 226 = msgsnd */
	"msgrcv",			/* 227 = msgrcv */
	"shmat",			/* 228 = shmat */
	"compat7.shmctl",		/* 229 = freebsd7 shmctl */
	"shmdt",			/* 230 = shmdt */
	"shmget",			/* 231 = shmget */
	"clock_gettime",			/* 232 = clock_gettime */
	"clock_settime",			/* 233 = clock_settime */
	"clock_getres",			/* 234 = clock_getres */
	"ktimer_create",			/* 235 = ktimer_create */
	"ktimer_delete",			/* 236 = ktimer_delete */
	"ktimer_settime",			/* 237 = ktimer_settime */
	"ktimer_gettime",			/* 238 = ktimer_gettime */
	"ktimer_getoverrun",			/* 239 = ktimer_getoverrun */
	"nanosleep",			/* 240 = nanosleep */
	"ffclock_getcounter",			/* 241 = ffclock_getcounter */
	"ffclock_setestimate",			/* 242 = ffclock_setestimate */
	"ffclock_getestimate",			/* 243 = ffclock_getestimate */
	"clock_nanosleep",			/* 244 = clock_nanosleep */
	"#245",			/* 245 = nosys */
	"#246",			/* 246 = nosys */
	"clock_getcpuclockid2",			/* 247 = clock_getcpuclockid2 */
	"ntp_gettime",			/* 248 = ntp_gettime */
	"#249",			/* 249 = nosys */
	"minherit",			/* 250 = minherit */
	"rfork",			/* 251 = rfork */
	"obs_openbsd_poll",			/* 252 = obsolete openbsd_poll */
	"issetugid",			/* 253 = issetugid */
	"lchown",			/* 254 = lchown */
	"aio_read",			/* 255 = aio_read */
	"aio_write",			/* 256 = aio_write */
	"lio_listio",			/* 257 = lio_listio */
	"#258",			/* 258 = nosys */
	"#259",			/* 259 = nosys */
	"#260",			/* 260 = nosys */
	"#261",			/* 261 = nosys */
	"#262",			/* 262 = nosys */
	"#263",			/* 263 = nosys */
	"#264",			/* 264 = nosys */
	"#265",			/* 265 = nosys */
	"#266",			/* 266 = nosys */
	"#267",			/* 267 = nosys */
	"#268",			/* 268 = nosys */
	"#269",			/* 269 = nosys */
	"#270",			/* 270 = nosys */
	"#271",			/* 271 = nosys */
	"compat11.getdents",		/* 272 = freebsd11 getdents */
	"#273",			/* 273 = nosys */
	"lchmod",			/* 274 = lchmod */
	"obs_netbsd_lchown",			/* 275 = obsolete netbsd_lchown */
	"lutimes",			/* 276 = lutimes */
	"obs_netbsd_msync",			/* 277 = obsolete netbsd_msync */
	"compat11.nstat",		/* 278 = freebsd11 nstat */
	"compat11.nfstat",		/* 279 = freebsd11 nfstat */
	"compat11.nlstat",		/* 280 = freebsd11 nlstat */
	"#281",			/* 281 = nosys */
	"#282",			/* 282 = nosys */
	"#283",			/* 283 = nosys */
	"#284",			/* 284 = nosys */
	"#285",			/* 285 = nosys */
	"#286",			/* 286 = nosys */
	"#287",			/* 287 = nosys */
	"#288",			/* 288 = nosys */
	"preadv",			/* 289 = preadv */
	"pwritev",			/* 290 = pwritev */
	"#291",			/* 291 = nosys */
	"#292",			/* 292 = nosys */
	"#293",			/* 293 = nosys */
	"#294",			/* 294 = nosys */
	"#295",			/* 295 = nosys */
	"#296",			/* 296 = nosys */
	"compat4.fhstatfs",		/* 297 = freebsd4 fhstatfs */
	"fhopen",			/* 298 = fhopen */
	"compat11.fhstat",		/* 299 = freebsd11 fhstat */
	"modnext",			/* 300 = modnext */
	"modstat",			/* 301 = modstat */
	"modfnext",			/* 302 = modfnext */
	"modfind",			/* 303 = modfind */
	"kldload",			/* 304 = kldload */
	"kldunload",			/* 305 = kldunload */
	"kldfind",			/* 306 = kldfind */
	"kldnext",			/* 307 = kldnext */
	"kldstat",			/* 308 = kldstat */
	"kldfirstmod",			/* 309 = kldfirstmod */
	"getsid",			/* 310 = getsid */
	"setresuid",			/* 311 = setresuid */
	"setresgid",			/* 312 = setresgid */
	"obs_signanosleep",			/* 313 = obsolete signanosleep */
	"aio_return",			/* 314 = aio_return */
	"aio_suspend",			/* 315 = aio_suspend */
	"aio_cancel",			/* 316 = aio_cancel */
	"aio_error",			/* 317 = aio_error */
	"compat6.aio_read",		/* 318 = freebsd6 aio_read */
	"compat6.aio_write",		/* 319 = freebsd6 aio_write */
	"compat6.lio_listio",		/* 320 = freebsd6 lio_listio */
	"yield",			/* 321 = yield */
	"obs_thr_sleep",			/* 322 = obsolete thr_sleep */
	"obs_thr_wakeup",			/* 323 = obsolete thr_wakeup */
	"mlockall",			/* 324 = mlockall */
	"munlockall",			/* 325 = munlockall */
	"__getcwd",			/* 326 = __getcwd */
	"sched_setparam",			/* 327 = sched_setparam */
	"sched_getparam",			/* 328 = sched_getparam */
	"sched_setscheduler",			/* 329 = sched_setscheduler */
	"sched_getscheduler",			/* 330 = sched_getscheduler */
	"sched_yield",			/* 331 = sched_yield */
	"sched_get_priority_max",			/* 332 = sched_get_priority_max */
	"sched_get_priority_min",			/* 333 = sched_get_priority_min */
	"sched_rr_get_interval",			/* 334 = sched_rr_get_interval */
	"utrace",			/* 335 = utrace */
	"compat4.sendfile",		/* 336 = freebsd4 sendfile */
	"kldsym",			/* 337 = kldsym */
	"jail",			/* 338 = jail */
	"nnpfs_syscall",			/* 339 = nnpfs_syscall */
	"sigprocmask",			/* 340 = sigprocmask */
	"sigsuspend",			/* 341 = sigsuspend */
	"compat4.sigaction",		/* 342 = freebsd4 sigaction */
	"sigpending",			/* 343 = sigpending */
	"compat4.sigreturn",		/* 344 = freebsd4 sigreturn */
	"sigtimedwait",			/* 345 = sigtimedwait */
	"sigwaitinfo",			/* 346 = sigwaitinfo */
	"__acl_get_file",			/* 347 = __acl_get_file */
	"__acl_set_file",			/* 348 = __acl_set_file */
	"__acl_get_fd",			/* 349 = __acl_get_fd */
	"__acl_set_fd",			/* 350 = __acl_set_fd */
	"__acl_delete_file",			/* 351 = __acl_delete_file */
	"__acl_delete_fd",			/* 352 = __acl_delete_fd */
	"__acl_aclcheck_file",			/* 353 = __acl_aclcheck_file */
	"__acl_aclcheck_fd",			/* 354 = __acl_aclcheck_fd */
	"extattrctl",			/* 355 = extattrctl */
	"extattr_set_file",			/* 356 = extattr_set_file */
	"extattr_get_file",			/* 357 = extattr_get_file */
	"extattr_delete_file",			/* 358 = extattr_delete_file */
	"aio_waitcomplete",			/* 359 = aio_waitcomplete */
	"getresuid",			/* 360 = getresuid */
	"getresgid",			/* 361 = getresgid */
	"kqueue",			/* 362 = kqueue */
	"compat11.kevent",		/* 363 = freebsd11 kevent */
	"obs___cap_get_proc",			/* 364 = obsolete __cap_get_proc */
	"obs___cap_set_proc",			/* 365 = obsolete __cap_set_proc */
	"obs___cap_get_fd",			/* 366 = obsolete __cap_get_fd */
	"obs___cap_get_file",			/* 367 = obsolete __cap_get_file */
	"obs___cap_set_fd",			/* 368 = obsolete __cap_set_fd */
	"obs___cap_set_file",			/* 369 = obsolete __cap_set_file */
	"#370",			/* 370 = nosys */
	"extattr_set_fd",			/* 371 = extattr_set_fd */
	"extattr_get_fd",			/* 372 = extattr_get_fd */
	"extattr_delete_fd",			/* 373 = extattr_delete_fd */
	"__setugid",			/* 374 = __setugid */
	"obs_nfsclnt",			/* 375 = obsolete nfsclnt */
	"eaccess",			/* 376 = eaccess */
	"afs3_syscall",			/* 377 = afs3_syscall */
	"nmount",			/* 378 = nmount */
	"obs_kse_exit",			/* 379 = obsolete kse_exit */
	"obs_kse_wakeup",			/* 380 = obsolete kse_wakeup */
	"obs_kse_create",			/* 381 = obsolete kse_create */
	"obs_kse_thr_interrupt",			/* 382 = obsolete kse_thr_interrupt */
	"obs_kse_release",			/* 383 = obsolete kse_release */
	"__mac_get_proc",			/* 384 = __mac_get_proc */
	"__mac_set_proc",			/* 385 = __mac_set_proc */
	"__mac_get_fd",			/* 386 = __mac_get_fd */
	"__mac_get_file",			/* 387 = __mac_get_file */
	"__mac_set_fd",			/* 388 = __mac_set_fd */
	"__mac_set_file",			/* 389 = __mac_set_file */
	"kenv",			/* 390 = kenv */
	"lchflags",			/* 391 = lchflags */
	"uuidgen",			/* 392 = uuidgen */
	"sendfile",			/* 393 = sendfile */
	"mac_syscall",			/* 394 = mac_syscall */
	"compat11.getfsstat",		/* 395 = freebsd11 getfsstat */
	"compat11.statfs",		/* 396 = freebsd11 statfs */
	"compat11.fstatfs",		/* 397 = freebsd11 fstatfs */
	"compat11.fhstatfs",		/* 398 = freebsd11 fhstatfs */
	"#399",			/* 399 = nosys */
	"ksem_close",			/* 400 = ksem_close */
	"ksem_post",			/* 401 = ksem_post */
	"ksem_wait",			/* 402 = ksem_wait */
	"ksem_trywait",			/* 403 = ksem_trywait */
	"ksem_init",			/* 404 = ksem_init */
	"ksem_open",			/* 405 = ksem_open */
	"ksem_unlink",			/* 406 = ksem_unlink */
	"ksem_getvalue",			/* 407 = ksem_getvalue */
	"ksem_destroy",			/* 408 = ksem_destroy */
	"__mac_get_pid",			/* 409 = __mac_get_pid */
	"__mac_get_link",			/* 410 = __mac_get_link */
	"__mac_set_link",			/* 411 = __mac_set_link */
	"extattr_set_link",			/* 412 = extattr_set_link */
	"extattr_get_link",			/* 413 = extattr_get_link */
	"extattr_delete_link",			/* 414 = extattr_delete_link */
	"__mac_execve",			/* 415 = __mac_execve */
	"sigaction",			/* 416 = sigaction */
	"sigreturn",			/* 417 = sigreturn */
	"#418",			/* 418 = __xstat */
	"#419",			/* 419 = __xfstat */
	"#420",			/* 420 = __xlstat */
	"getcontext",			/* 421 = getcontext */
	"setcontext",			/* 422 = setcontext */
	"swapcontext",			/* 423 = swapcontext */
	"swapoff",			/* 424 = swapoff */
	"__acl_get_link",			/* 425 = __acl_get_link */
	"__acl_set_link",			/* 426 = __acl_set_link */
	"__acl_delete_link",			/* 427 = __acl_delete_link */
	"__acl_aclcheck_link",			/* 428 = __acl_aclcheck_link */
	"sigwait",			/* 429 = sigwait */
	"thr_create",			/* 430 = thr_create */
	"thr_exit",			/* 431 = thr_exit */
	"thr_self",			/* 432 = thr_self */
	"thr_kill",			/* 433 = thr_kill */
	"#434",			/* 434 = nosys */
	"#435",			/* 435 = nosys */
	"jail_attach",			/* 436 = jail_attach */
	"extattr_list_fd",			/* 437 = extattr_list_fd */
	"extattr_list_file",			/* 438 = extattr_list_file */
	"extattr_list_link",			/* 439 = extattr_list_link */
	"obs_kse_switchin",			/* 440 = obsolete kse_switchin */
	"ksem_timedwait",			/* 441 = ksem_timedwait */
	"thr_suspend",			/* 442 = thr_suspend */
	"thr_wake",			/* 443 = thr_wake */
	"kldunloadf",			/* 444 = kldunloadf */
	"audit",			/* 445 = audit */
	"auditon",			/* 446 = auditon */
	"getauid",			/* 447 = getauid */
	"setauid",			/* 448 = setauid */
	"getaudit",			/* 449 = getaudit */
	"setaudit",			/* 450 = setaudit */
	"getaudit_addr",			/* 451 = getaudit_addr */
	"setaudit_addr",			/* 452 = setaudit_addr */
	"auditctl",			/* 453 = auditctl */
	"_umtx_op",			/* 454 = _umtx_op */
	"thr_new",			/* 455 = thr_new */
	"sigqueue",			/* 456 = sigqueue */
	"kmq_open",			/* 457 = kmq_open */
	"kmq_setattr",			/* 458 = kmq_setattr */
	"kmq_timedreceive",			/* 459 = kmq_timedreceive */
	"kmq_timedsend",			/* 460 = kmq_timedsend */
	"kmq_notify",			/* 461 = kmq_notify */
	"kmq_unlink",			/* 462 = kmq_unlink */
	"abort2",			/* 463 = abort2 */
	"thr_set_name",			/* 464 = thr_set_name */
	"aio_fsync",			/* 465 = aio_fsync */
	"rtprio_thread",			/* 466 = rtprio_thread */
	"#467",			/* 467 = nosys */
	"#468",			/* 468 = nosys */
	"#469",			/* 469 = __getpath_fromfd */
	"#470",			/* 470 = __getpath_fromaddr */
	"sctp_peeloff",			/* 471 = sctp_peeloff */
	"sctp_generic_sendmsg",			/* 472 = sctp_generic_sendmsg */
	"sctp_generic_sendmsg_iov",			/* 473 = sctp_generic_sendmsg_iov */
	"sctp_generic_recvmsg",			/* 474 = sctp_generic_recvmsg */
	"pread",			/* 475 = pread */
	"pwrite",			/* 476 = pwrite */
	"mmap",			/* 477 = mmap */
	"lseek",			/* 478 = lseek */
	"truncate",			/* 479 = truncate */
	"ftruncate",			/* 480 = ftruncate */
	"thr_kill2",			/* 481 = thr_kill2 */
	"shm_open",			/* 482 = shm_open */
	"shm_unlink",			/* 483 = shm_unlink */
	"cpuset",			/* 484 = cpuset */
	"cpuset_setid",			/* 485 = cpuset_setid */
	"cpuset_getid",			/* 486 = cpuset_getid */
	"cpuset_getaffinity",			/* 487 = cpuset_getaffinity */
	"cpuset_setaffinity",			/* 488 = cpuset_setaffinity */
	"faccessat",			/* 489 = faccessat */
	"fchmodat",			/* 490 = fchmodat */
	"fchownat",			/* 491 = fchownat */
	"fexecve",			/* 492 = fexecve */
	"compat11.fstatat",		/* 493 = freebsd11 fstatat */
	"futimesat",			/* 494 = futimesat */
	"linkat",			/* 495 = linkat */
	"mkdirat",			/* 496 = mkdirat */
	"mkfifoat",			/* 497 = mkfifoat */
	"compat11.mknodat",		/* 498 = freebsd11 mknodat */
	"openat",			/* 499 = openat */
	"readlinkat",			/* 500 = readlinkat */
	"renameat",			/* 501 = renameat */
	"symlinkat",			/* 502 = symlinkat */
	"unlinkat",			/* 503 = unlinkat */
	"posix_openpt",			/* 504 = posix_openpt */
	"gssd_syscall",			/* 505 = gssd_syscall */
	"jail_get",			/* 506 = jail_get */
	"jail_set",			/* 507 = jail_set */
	"jail_remove",			/* 508 = jail_remove */
	"closefrom",			/* 509 = closefrom */
	"__semctl",			/* 510 = __semctl */
	"msgctl",			/* 511 = msgctl */
	"shmctl",			/* 512 = shmctl */
	"lpathconf",			/* 513 = lpathconf */
	"obs_cap_new",			/* 514 = obsolete cap_new */
	"__cap_rights_get",			/* 515 = __cap_rights_get */
	"cap_enter",			/* 516 = cap_enter */
	"cap_getmode",			/* 517 = cap_getmode */
	"pdfork",			/* 518 = pdfork */
	"pdkill",			/* 519 = pdkill */
	"pdgetpid",			/* 520 = pdgetpid */
	"#521",			/* 521 = pdwait4 */
	"pselect",			/* 522 = pselect */
	"getloginclass",			/* 523 = getloginclass */
	"setloginclass",			/* 524 = setloginclass */
	"rctl_get_racct",			/* 525 = rctl_get_racct */
	"rctl_get_rules",			/* 526 = rctl_get_rules */
	"rctl_get_limits",			/* 527 = rctl_get_limits */
	"rctl_add_rule",			/* 528 = rctl_add_rule */
	"rctl_remove_rule",			/* 529 = rctl_remove_rule */
	"posix_fallocate",			/* 530 = posix_fallocate */
	"posix_fadvise",			/* 531 = posix_fadvise */
	"wait6",			/* 532 = wait6 */
	"cap_rights_limit",			/* 533 = cap_rights_limit */
	"cap_ioctls_limit",			/* 534 = cap_ioctls_limit */
	"cap_ioctls_get",			/* 535 = cap_ioctls_get */
	"cap_fcntls_limit",			/* 536 = cap_fcntls_limit */
	"cap_fcntls_get",			/* 537 = cap_fcntls_get */
	"bindat",			/* 538 = bindat */
	"connectat",			/* 539 = connectat */
	"chflagsat",			/* 540 = chflagsat */
	"accept4",			/* 541 = accept4 */
	"pipe2",			/* 542 = pipe2 */
	"aio_mlock",			/* 543 = aio_mlock */
	"procctl",			/* 544 = procctl */
	"ppoll",			/* 545 = ppoll */
	"futimens",			/* 546 = futimens */
	"utimensat",			/* 547 = utimensat */
	"obs_numa_getaffinity",			/* 548 = obsolete numa_getaffinity */
	"obs_numa_setaffinity",			/* 549 = obsolete numa_setaffinity */
	"fdatasync",			/* 550 = fdatasync */
	"fstat",			/* 551 = fstat */
	"fstatat",			/* 552 = fstatat */
	"fhstat",			/* 553 = fhstat */
	"getdirentries",			/* 554 = getdirentries */
	"statfs",			/* 555 = statfs */
	"fstatfs",			/* 556 = fstatfs */
	"getfsstat",			/* 557 = getfsstat */
	"fhstatfs",			/* 558 = fhstatfs */
	"mknodat",			/* 559 = mknodat */
	"kevent",			/* 560 = kevent */
	"cpuset_getdomain",			/* 561 = cpuset_getdomain */
	"cpuset_setdomain",			/* 562 = cpuset_setdomain */
	"getrandom",			/* 563 = getrandom */
	"getfhat",			/* 564 = getfhat */
	"fhlink",			/* 565 = fhlink */
	"fhlinkat",			/* 566 = fhlinkat */
	"fhreadlink",			/* 567 = fhreadlink */
};
