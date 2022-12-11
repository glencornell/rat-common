#
# Makefile for the common code library project. 
#
lib_LTLIBRARIES = libuclmmbase.la

libuclmmbase_la_CFLAGS=-Wunused-result
libuclmmbase_la_SOURCES = \
	asarray.c \
	asarray.h \
	base64.c \
	base64.h \
	btree.c \
	btree.h \
	crypt_random.c \
	crypt_random.h \
	debug.c \
	debug.h \
	drand48.c \
	drand48.h \
	hmac.c \
	hmac.h \
	mbus_addr.c \
	mbus_addr.h \
	mbus_config.c \
	mbus_config.h \
	mbus.c \
	mbus.h \
	mbus_parser.c \
	mbus_parser.h \
	md5.c \
	md5.h \
	memory.c \
	memory.h \
	net_udp.c \
	net_udp.h \
	ntp.c \
	ntp.h \
	qfDES.c \
	qfDES.h \
	rijndael-alg-fst.c \
	rijndael-alg-fst.h \
	rijndael-api-fst.c \
	rijndael-api-fst.h \
	rtp.c \
	rtp.h \
	sap.c \
	sap.h \
	sdp.c \
	sdp.h \
	util.c \
	util.h

# if NEED_INET_PTON
# libuclmmbase_la_SOURCES+=inet_pton.c inet_pton.h
# endif

# if NEED_INET_NTOP
# libuclmmbase_la_SOURCES+=inet_ntop.c inet_ntop.h
# endif

nodist_libuclmmbase_la_SOURCES = version.h
BUILT_SOURCES = version.h
CLEANFILES = version.h

version.h: $(top_srcdir)/VERSION
	sed -e 's/.*/#define CCL_VERSION "v&"/' $? > $@
