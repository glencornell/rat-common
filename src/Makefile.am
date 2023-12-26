#
# Makefile for the common code library project.
#
lib_LTLIBRARIES = libuclmmbase.la

libuclmmbase_la_CFLAGS=-Wunused-result
libuclmmbase_la_SOURCES = \
	asarray.c \
	base64.c \
	btree.c \
	crypt_random.c \
	debug.c \
	drand48.c \
	hmac.c \
	mbus_addr.c \
	mbus_config.c \
	mbus.c \
	mbus_parser.c \
	md5.c \
	memory.c \
	net_udp.c \
	ntp.c \
	qfDES.c \
	rijndael-alg-fst.c \
	rijndael-api-fst.c \
	rtp.c \
	sap.c \
	sdp.c \
	util.c

# if NEED_INET_PTON
# libuclmmbase_la_SOURCES+=inet_pton.c inet_pton.h
# endif

# if NEED_INET_NTOP
# libuclmmbase_la_SOURCES+=inet_ntop.c inet_ntop.h
# endif

nodist_libuclmmbase_la_SOURCES = version.h
BUILT_SOURCES = version.h
CLEANFILES = version.h

uclmmbaseincludedir=$(includedir)/uclmmbase
uclmmbaseinclude_HEADERS = \
	asarray.h \
	base64.h \
	btree.h \
	crypt_random.h \
	debug.h \
	drand48.h \
	hmac.h \
	mbus_addr.h \
	mbus_config.h \
	mbus.h \
	mbus_parser.h \
	md5.h \
	memory.h \
	net_udp.h \
	ntp.h \
	qfDES.h \
	rijndael-alg-fst.h \
	rijndael-api-fst.h \
	rtp.h \
	sap.h \
	sdp.h \
	util.h \
	config_unix.h \
	config_win32.h \
	gettimeofday.h \
	inet_pton.h \
	vsnprintf.h \
	inet_ntop.h

version.h: $(top_srcdir)/VERSION
	sed -e 's/.*/#define CCL_VERSION "v&"/' $? > $@
