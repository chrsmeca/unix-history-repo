/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Computer Consoles Inc.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 */

#if defined(LIBC_SCCS) && !defined(lint)
_sccsid:.asciz	"@(#)nargs.s	1.2 (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */

/* C library -- nargs */

#include "DEFS.h"

ENTRY(nargs, 0)
	movw	-2(fp),r0  #  removed word
	subw2	$4,r0
	shar	$2,r0,r0  #  no. of arguments
	ret
