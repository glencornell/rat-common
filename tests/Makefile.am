#
# Makefile for the tests
#
noinst_PROGRAMS = test-libcommon

test_libcommon_SOURCES = \
	test_base64.c \
	test_des.c \
	test_md5.c \
	test_net_udp.c \
	test_memory.c \
	test_mbus_parser.c \
	test_mbus_addr.c \
	test_aes.c \
	test.c

test_libcommon_LDADD =  $(top_builddir)/src/libuclmmbase.la
test_libcommon_LDFLAGS = $(all_libraries)

AM_CPPFLAGS = $(all_includes)
