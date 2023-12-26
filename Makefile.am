#
# Makefile for the common code library project.
#
SUBDIRS=src tests examples $(OPTDOC)

ACLOCAL_AMFLAGS=-I m4

pkgconfig_DATA = libuclmmbase.pc

EXTRA_DIST = librat.spec.in VERSION

# Define the top-level directory for the RPM build
RPMBUILD ?= $(abs_top_builddir)/rpmbuild

# Define the name of the RPM spec file
specfile = $(PACKAGE_NAME).spec

.PHONY: rpmroot
rpmroot:
	mkdir -p $(RPMBUILD)/BUILD
	mkdir -p $(RPMBUILD)/RPMS
	mkdir -p $(RPMBUILD)/SOURCES
	mkdir -p $(RPMBUILD)/SPECS
	mkdir -p $(RPMBUILD)/SRPMS

.PHONY: rpm
rpm: dist-gzip rpmroot
	@cp $(distdir).tar.gz $(RPMBUILD)/SOURCES/
	@cp $(specfile) $(RPMBUILD)/SPECS/
	cd $(RPMBUILD) ; \
	rpmbuild -ba --define "_topdir $(RPMBUILD)" $(RPMBUILD)/SPECS/$(specfile)
