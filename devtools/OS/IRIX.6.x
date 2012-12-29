#	$Id: IRIX.6.x,v 8.31 2012/01/21 00:07:09 ashish Exp $

dnl	DO NOT EDIT THIS FILE.
dnl	Place personal settings in devtools/Site/site.config.m4

define(`confCC', `cc -mips3 -n32 -OPT:Olimit=0')
define(`confLIBSEARCHPATH', `/lib32 /usr/lib32')
define(`confMAPDEF', `-DNDBM -DNIS -DMAP_REGEX')
define(`confENVDEF', `-DIRIX6')
define(`confSM_OS_HEADER', `sm_os_irix')
define(`confMANOWN', `root')
define(`confMANGRP', `sys')
define(`confUBINOWN', `root')
define(`confUBINGRP', `sys')
define(`confMBINDIR', `/usr/lib')
define(`confUBINDIR', `/usr/bsd')
define(`confEBINDIR', `/usr/lib')
define(`confSBINGRP', `sys')
define(`confSTDIR', `/var')
define(`confINSTALL', `${BUILDBIN}/install.sh')
define(`confDEPEND_TYPE', `CC-M')
