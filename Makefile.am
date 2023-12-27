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

.PHONY: dist-rpm
dist-rpm: dist-gzip rpmroot
	@cp $(distdir).tar.gz $(RPMBUILD)/SOURCES/
	@cp $(specfile) $(RPMBUILD)/SPECS/
	cd $(RPMBUILD) ; \
	rpmbuild -ba --define "_topdir $(RPMBUILD)" $(RPMBUILD)/SPECS/$(specfile)

if HAVE_DPKG
DPKG_CPU_ARCH = $(shell dpkg --print-architecture)
else
DPKG_CPU_ARCH =
endif

.PHONY: dist-deb
dist-deb:
	dpkg-buildpackage -uc -us
	mv ../$(PACKAGE_NAME)_$(PACKAGE_VERSION)_$(DPKG_CPU_ARCH).buildinfo .
	mv ../$(PACKAGE_NAME)_$(PACKAGE_VERSION)_$(DPKG_CPU_ARCH).changes .
	mv ../$(PACKAGE_NAME)_$(PACKAGE_VERSION)_$(DPKG_CPU_ARCH).deb .
	mv ../$(PACKAGE_NAME)-dev_$(PACKAGE_VERSION)_$(DPKG_CPU_ARCH).deb .
	mv ../$(PACKAGE_NAME)_$(PACKAGE_VERSION).dsc .
	mv ../$(PACKAGE_NAME)_$(PACKAGE_VERSION).tar.gz .
