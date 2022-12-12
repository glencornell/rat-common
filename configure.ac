# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([librat],[1.2.19])
AC_CONFIG_SRCDIR([src/base64.c])
AC_CONFIG_HEADERS([src/uclconf.h:src/config.h.in])

AC_CONFIG_MACRO_DIRS([m4])

AM_INIT_AUTOMAKE([foreign subdir-objects])

LT_INIT

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

PKG_INSTALLDIR

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h inttypes.h malloc.h netdb.h netinet/in.h stdint.h sys/ioctl.h sys/param.h sys/socket.h sys/time.h sys/timeb.h unistd.h])
AC_CHECK_HEADERS(sys/filio.h)
AC_CHECK_HEADERS(stdint.h inttypes.h)

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UID_T
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

AC_C_INLINE

# define target endianness
AC_C_BIGENDIAN
if test "x$ac_cv_c_bigendian" = "xyes"; then
    CPPFLAGS="$CPPFLAGS -DWORDS_BIGENDIAN=1"
else
    CPPFLAGS="$CPPFLAGS -DWORDS_BIGENDIAN=0"
fi

# is char unsigned?
AC_C_CHAR_UNSIGNED
#
# Some of the codecs in rat don't with with unsigned characters. 
# Force the compiler to use signed chars, to be consistent.
if test $ac_cv_c_char_unsigned = yes
then
	if test "$GCC" = yes
	then
		CFLAGS="$CFLAGS -fsigned-char"
	else
		case "$host_os" in
		# I don't know when "-signed" was added to IRIX CC
		# so err on the side of using it.
		irix*)	CFLAGS="$CFLAGS -signed"
			;;
		# need e.g. --force-signed-chars=-signed
		*)	AC_MSG_ERROR([I don't know how to force signed chars])
			;;
		esac
	fi
fi
#  __CHAR_UNSIGNED__ will be defined; hope this is OK.

###############################################################################
# The following causes autoconf to complain.
case "$host_os" in 
    *mingw*|*mingw32*)
	    ;;
	*)
	    AC_CHECK_FILE(/dev/urandom,AC_DEFINE([HAVE_DEV_URANDOM],[],[has /dev/urandom]))
		;;
esac

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([gethostbyaddr gethostbyname gethostname gettimeofday inet_ntoa memmove memset mkdir modf select socket strcasecmp strchr strcspn strdup strrchr strstr strtol uname])

# If more files than mbus.c use vsnprintf, split it out into
# vsnprintf.c and add it to AC_REPLACE_FUNCS
# AC_CHECK_FUNC(vsnprintf,,AC_DEFINE([NEED_VSNPRINTF],[],[have vsnprintf()]))
AC_REPLACE_FUNCS(vsnprintf)

###############################################################################
# If inet_aton is actually needed somewhere, split it out into
# inet_aton.c and add it to AC_REPLACE_FUNCS 
#
# AC_CHECK_FUNC succeeds on our IRIX 6.2 boxes, but it is not 
# declared anywhere, use egrep header to check (ugh lame, but works)
dnl AC_CACHE_CHECK(for inet_pton in <arpa/inet.h>, ucl_cv_inet_pton_in_inet_h,
dnl 	AC_EGREP_HEADER(inet_pton,
dnl 			arpa/inet.h,
dnl 			ucl_cv_inet_pton_in_inet_h=yes,
dnl 			ucl_cv_inet_pton_in_inet_h=no))
dnl if test $ucl_cv_inet_pton_in_inet_h = "no"
dnl then
dnl 	AC_DEFINE([NEED_INET_PTON],[],[inet_pton in <arpa/inet.h>])
dnl fi
dnl AC_CACHE_CHECK(for inet_ntop in <arpa/inet.h>, ucl_cv_inet_ntop_in_inet_h,
dnl 	AC_EGREP_HEADER(inet_ntop,
dnl 			arpa/inet.h,
dnl 			ucl_cv_inet_ntop_in_inet_h=yes,
dnl 			ucl_cv_inet_ntop_in_inet_h=no))
dnl if test $ucl_cv_inet_ntop_in_inet_h = "no"
dnl then
dnl 	AC_DEFINE([NEED_INET_NTOP],[],[inet_ntop in <arpa/inet.h>])
dnl fi

AC_REPLACE_FUNCS([inet_pton])
AC_REPLACE_FUNCS([inet_ntop])

AC_SEARCH_LIBS(socket, socket)
AC_SEARCH_LIBS(inet_addr, nsl)

###############################################################################
#  -profile
AC_ARG_ENABLE(profile,
	[  --enable-profile        enable profiling],
	[if test $enableval = yes
	then
		if test "$GCC" = yes
		then
			CFLAGS="$CFLAGS -pg"
		else
			AC_MSG_ERROR(Don't know how to enable profiling for $CC)
		fi
	fi])

#  -bounds
#       add -fbounds-checking to CFLAGS
#       add -lcheck to LIBS
AC_ARG_ENABLE(bounds,
	[  --enable-bounds         enable bounds checking],
	[if test $enableval = yes
	then
		if test "$GCC" = yes
		then
			CFLAGS="$CFLAGS -fbounds-checking"
			LIBS="$LIBS -lcheck"
		else
			AC_MSG_ERROR(Don't know how to enable profiling for $CC)
		fi
	fi])

# -DDEBUG
# -DDEBUG_MEM
# -DNDEBUG
AC_ARG_ENABLE(debug,
	[  --enable-debug          enable debug messages and code],
	[if test $enableval = yes
	then
		AC_DEFINE([DEBUG], [], [enable debug messages and code])
	fi])
AC_ARG_ENABLE(debug-mem,
	[  --enable-debug-mem      enable memory debugging code],
	[if test $enableval = yes
	then
		AC_DEFINE([DEBUG_MEM], [], [enable memory debugging code])
	fi])

###############################################################################
# IPv6 related configuration options (using tcpdump's configure.in)
AC_MSG_CHECKING([whether to enable IPv6])
AC_ARG_ENABLE(ipv6,
        [  --enable-ipv6           enable ipv6],
	[ case "$enableval" in
	  yes)	AC_MSG_RESULT(yes)
		AC_DEFINE([HAVE_IPv6],[],[enable ipv6])
		ipv6=yes
		;;
	  *)	AC_MSG_RESULT(no)
		ipv6=no
		;;
	  esac
	],
	[ AC_MSG_RESULT(no)
	  ipv6=no
	])
ipv6type=unknown
ipv6lib=none
ipv6trylibc=no

# IPv6 Stack Type Detector
if test "$ipv6" = "yes"; then
	AC_MSG_CHECKING([ipv6 stack type])
	for i in inria kame linux-glibc linux-libinet6 toshiba v6d zeta; do
		case $i in
		inria)
			# http://www.kame.net/
			AC_EGREP_CPP(yes, [
#include <netinet/in.h>
#ifdef IPV6_INRIA_VERSION
yes
#endif],
				[ipv6type=$i;
				CFLAGS="-DINET6 $CFLAGS"])
			;;
		kame)
			# http://www.kame.net/
			AC_EGREP_CPP(yes, [
#include <netinet/in.h>
#ifdef __KAME__
yes
#endif],
				[ipv6type=$i;
				ipv6lib=inet6;
				if test -x /usr/local/v6/lib; then
					ipv6libdir=/usr/local/v6/lib;
				else
					ipv6type=freebsd/netbsd/openbsd
					ipv6libdir=/usr/lib;
				fi;
				ipv6trylibc=yes;
				CFLAGS="-DINET6 $CFLAGS"])
			;;
		linux-glibc)
			# http://www.v6.linux.or.jp/
			AC_EGREP_CPP(yes, [
#include <features.h>
#if defined(__GLIBC__) && __GLIBC__ >= 2 && __GLIBC_MINOR__ >= 1
yes
#endif],
				[ipv6type=$i;
				CFLAGS="-DINET6 $CFLAGS"])
			;;
		linux-libinet6)
			# http://www.v6.linux.or.jp/
			if test -d /usr/inet6 -o -f /usr/include/netinet/ip6.h; then
				ipv6type=$i
				ipv6lib=inet6
				ipv6libdir=/usr/inet6/lib
				ipv6trylibc=yes;
				CFLAGS="-DINET6 -I/usr/inet6/include $CFLAGS"
			fi
			;;
		toshiba)
			AC_EGREP_CPP(yes, [
#include <sys/param.h>
#ifdef _TOSHIBA_INET6
yes
#endif],
				[ipv6type=$i;
				ipv6lib=inet6;
				ipv6libdir=/usr/local/v6/lib;
				CFLAGS="-DINET6 $CFLAGS"])
			;;
		v6d)
			AC_EGREP_CPP(yes, [
#include </usr/local/v6/include/sys/v6config.h>
#ifdef __V6D__
yes
#endif],
				[ipv6type=$i;
				ipv6lib=v6;
				ipv6libdir=/usr/local/v6/lib;
				CFLAGS="-I/usr/local/v6/include $CFLAGS"])
			;;
		zeta)
			AC_EGREP_CPP(yes, [
#include <sys/param.h>
#ifdef _ZETA_MINAMI_INET6
yes
#endif],
				[ipv6type=$i;
				ipv6lib=inet6;
				ipv6libdir=/usr/local/v6/lib;
				CFLAGS="-DINET6 $CFLAGS"])
			;;
		esac
		if test "$ipv6type" != "unknown"; then
			break
		fi
	done
	AC_MSG_RESULT($ipv6type)
fi

if test "$ipv6" = "yes" -a "$ipv6lib" != "none"; then
	if test -d $ipv6libdir -a -f $ipv6libdir/lib$ipv6lib.a; then
		LIBS="-L$ipv6libdir -l$ipv6lib $LIBS"
		echo "You have $ipv6lib library, using it"
	else
		if test "$ipv6trylibc" = "yes"; then
			echo "You do not have $ipv6lib library, using libc"
		else
			echo 'Fatal: no $ipv6lib library found.  cannot continue.'
			echo "You need to fetch lib$ipv6lib.a from appropriate"
			echo 'ipv6 kit and compile beforehand.'
			exit 1
		fi
	fi
fi

# Test below are IPv6 specific.  Their result has no bearing if HAVE_IPv6 is
# not defined.  They are kept outside IPv6 enable check to keep code readable.

AC_CACHE_CHECK(for getipnodebyname in <netdb.h>, ucl_cv_getipnodebyname_in_netdb_h,
	AC_EGREP_HEADER(getipnodebyname,
		netdb.h,
		ucl_cv_getipnodebyname_in_netdb_h=yes,	
		ucl_cv_getipnodebyname_in_netdb_h=no))
if test $ucl_cv_getipnodebyname_in_netdb_h
then
	AC_DEFINE([HAVE_GETIPNODEBYNAME],[],[is getipnodebyname() in <netdb.h>]) 
fi

AC_CACHE_CHECK(for struct addrinfo in <netdb.h>, ucl_cv_st_addrinfo_in_netdb_h,
	AC_EGREP_HEADER(addrinfo,
		netdb.h,
		ucl_cv_st_addrinfo_in_netdb_h=yes,	
		ucl_cv_st_addrinfo_in_netdb_h=no))
if test $ucl_cv_st_addrinfo_in_netdb_h
then
	AC_DEFINE([HAVE_ST_ADDRINFO],[],[have struct addrinfo in <netdb.h>]) 
fi

AC_CACHE_CHECK(for sin6_len in struct sockaddr_in6, ucl_cv_sin6_len,
	[AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
		#include <netinet/in.h>
	]], [[
		struct sockaddr_in6	s_in;
		s_in.sin6_len = 0;
	]])],[ucl_cv_sin6_len=yes],[ucl_cv_sin6_len=no
	])])
if test $ucl_cv_sin6_len = yes
then
	AC_DEFINE([HAVE_SIN6_LEN],[],[have sin6_len in struct sockaddr_in6]) 
fi

AC_CACHE_CHECK(for msg_control in struct msghdr, ucl_cv_control,
        [AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
                #include <sys/types.h>
		#include <sys/socket.h>
        ]], [[
                struct msghdr msg;
                msg.msg_control = 0;
        ]])],[ucl_cv_control=yes],[ucl_cv_control=no
        ])])
if test $ucl_cv_control = yes
then
        AC_DEFINE([HAVE_MSGHDR_MSGCTRL],[],[msg_control in struct msghdr])
fi

###############################################################################
# Check whether gtk-doc is installed

AC_CHECK_PROG(GTKDOC, gtkdoc-scan, yes, no, $PATH)
if test "$GTKDOC" = yes 
then
	OPTDOC=doc
else
	OPTDOC=
fi
AC_SUBST(OPTDOC)

###############################################################################
# GCC-specific warning flags
if test "$GCC" = yes
then
        CFLAGS="$CFLAGS -W -Wall -Wwrite-strings -Wbad-function-cast -Wmissing-prototypes -Wcast-qual -Wmissing-declarations"
fi

case "$host_os" in 
  *darwin*)
	dnl Check for 64-bit host gcc - in Snow Leopard+
	AC_MSG_CHECKING([for 64-bit gcc on OSX])
	if gcc -v 2>&1 | grep host=x86_64 >& /dev/null ; then
		AC_MSG_RESULT([Building universal library - 64 and 32 bit])
		CFLAGS="$CFLAGS -arch i386 -arch x86_64"
		LDFLAGS="$LDFLAGS -arch i386 -arch x86_64 -mmacosx-version-min=10.4"
	else
		AC_MSG_RESULT([No - Only building 32-bit library])
	fi
	;;
  mingw|mingw32)
	AC_MSG_CHECKING(for winsock)
	save_LIBS="$LIBS"
	for curlib in ws2_32 wsock32; do
		LIBS="$LIBS -l$curlib"
		AC_LINK_IFELSE([AC_LANG_PROGRAM([[
			char __attribute__((stdcall)) socket(int,int,int);
				char __attribute__((stdcall)) select(int,int,int,int,int);
				char __attribute__((stdcall)) closesocket(int);
				char __attribute__((stdcall)) gethostname(int,int);
				]], [[
				socket(1,2,3);
				select(1,2,3,4,5);
				closesocket(1);
				gethostname(1,2);
				]])],[have_winsock=yes],[have_winsock=no])

		if test $have_winsock = yes; then
			ac_cv_func_select='yes'
			if test $curlib = ws2_32; then
				have_winsock=winsock2
			fi
			break
		fi
		LIBS="$save_LIBS"
	done
	AC_MSG_RESULT($have_winsock)
	LIBS="$LIBS -liphlpapi"
	;;
esac

###############################################################################
# Done, create the output files....
AC_CONFIG_FILES([Makefile
                 doc/Makefile
                 examples/Makefile
                 examples/rtp/Makefile
                 examples/sdp/Makefile
                 examples/sap/Makefile
                 src/Makefile
                 tests/Makefile
                 libuclmmbase.pc])
AC_OUTPUT
