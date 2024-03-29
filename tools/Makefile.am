## Copyright (C) 2005-2011 Red Hat, Inc.
## See COPYING.LIB for the License of this software

INCLUDES = \
	-I../include -I$(top_srcdir)/include \
	-I$(top_srcdir)/gnulib/lib -I../gnulib/lib	\
	-I$(top_srcdir)/src -I../src			\
	-I$(top_srcdir)/src/remote                      \
	-I$(top_srcdir)/src/util			\
	-I$(top_srcdir)					\
	-DLOCAL_STATE_DIR=\""$(localstatedir)"\"        \
	$(GETTEXT_CPPFLAGS)

POD2MAN = pod2man -c "Virtualization Support" -r "$(PACKAGE)-$(VERSION)"

ICON_FILES = \
	libvirt_win_icon_16x16.ico \
	libvirt_win_icon_32x32.ico \
	libvirt_win_icon_48x48.ico \
	libvirt_win_icon_64x64.ico \
	virsh_win_icon.rc

EXTRA_DIST = \
	$(ICON_FILES)					\
	virt-xml-validate.in				\
	virt-pki-validate.in				\
	virt-sanlock-cleanup.in				\
	virt-sanlock-cleanup.8				\
	virsh.pod					\
	libvirt-guests.sysconf

DISTCLEANFILES =

bin_SCRIPTS = virt-xml-validate virt-pki-validate
bin_PROGRAMS = virsh

if HAVE_SANLOCK
sbin_SCRIPTS = virt-sanlock-cleanup
DISTCLEANFILES += virt-sanlock-cleanup
endif

dist_man1_MANS = virt-xml-validate.1 virt-pki-validate.1 virsh.1
if HAVE_SANLOCK
dist_man8_MANS = virt-sanlock-cleanup.8
endif

virt-xml-validate: virt-xml-validate.in Makefile
	$(AM_V_GEN)sed -e 's,[@]SCHEMADIR@,$(pkgdatadir)/schemas,' < $< > $@ \
	    || (rm $@ && exit 1) && chmod +x $@

virt-xml-validate.1: virt-xml-validate.in
	$(AM_V_GEN)$(POD2MAN) $< $(srcdir)/$@

virt-pki-validate: virt-pki-validate.in Makefile
	$(AM_V_GEN)sed -e 's,[@]SYSCONFDIR@,$(sysconfdir),' < $< > $@ \
	    || (rm $@ && exit 1) && chmod +x $@

virt-pki-validate.1: virt-pki-validate.in
	$(AM_V_GEN)$(POD2MAN) $< $(srcdir)/$@

virt-sanlock-cleanup: virt-sanlock-cleanup.in Makefile
	$(AM_V_GEN)sed -e 's,[@]SYSCONFDIR@,$(sysconfdir),' \
	    -e 's,[@]LOCALSTATEDIR@,$(localstatedir),' < $< > $@ \
	    || (rm $@ && exit 1) && chmod +x $@

virt-sanlock-cleanup.8: virt-sanlock-cleanup.in
	$(AM_V_GEN)$(POD2MAN) $< $(srcdir)/$@

virsh_SOURCES =							\
		console.c console.h				\
		virsh.c

virsh_LDFLAGS = $(WARN_LDFLAGS) $(COVERAGE_LDFLAGS)
virsh_LDADD =							\
		$(STATIC_BINARIES)				\
		$(WARN_CFLAGS)					\
		../src/libvirt.la				\
		../src/libvirt-qemu.la				\
		../gnulib/lib/libgnu.la				\
		$(LIBXML_LIBS)					\
		$(VIRSH_LIBS)
virsh_CFLAGS =							\
		$(WARN_CFLAGS)					\
		$(COVERAGE_CFLAGS)				\
		$(LIBXML_CFLAGS)				\
		$(READLINE_CFLAGS)
BUILT_SOURCES = virsh-net-edit.c virsh-pool-edit.c

virsh-net-edit.c: virsh.c Makefile.am
	$(AM_V_GEN)rm -f $@-tmp && \
	echo '/* Automatically generated from: $^ */' > $@-tmp && \
	echo 'static bool' >> $@-tmp && \
	awk '/^cmdEdit/, /^}/' $< \
	  | sed -e 's/domain/network/g' \
	      -e 's/Domain/Network/g' \
	      -e 's/cmdEdit/cmdNetworkEdit/g' \
	      -e 's/dom/network/g' \
	      -e 's/int flags.*/int flags = 0;/g' \
	>> $@-tmp && \
	chmod a-w $@-tmp && \
	rm -f $@ && \
	mv $@-tmp $@

virsh-pool-edit.c: virsh.c Makefile.am
	$(AM_V_GEN)rm -f $@-tmp && \
	echo '/* Automatically generated from: $^ */' > $@-tmp && \
	echo 'static bool' >> $@-tmp && \
	awk '/^cmdEdit/, /^}/' $< \
	  | sed -e 's/domain/pool/g' \
	      -e 's/vshCommandOptDomain/vshCommandOptPool/g' \
	      -e 's/Domain %s/Pool %s/g' \
	      -e 's/(ctl, cmd, NULL);/(ctl, cmd, "pool", NULL);/' \
	      -e 's/Domain/StoragePool/g' \
	      -e 's/cmdEdit/cmdPoolEdit/g' \
	      -e 's/\(virStoragePoolDefineXML.*\));/\1, 0);/' \
	      -e 's/dom/pool/g' \
	      -e 's/int flags.*/int flags = 0;/g' \
	>> $@-tmp && \
	chmod a-w $@-tmp && \
	rm -f $@ && \
	mv $@-tmp $@


if WITH_WIN_ICON
virsh_LDADD += virsh_win_icon.$(OBJEXT)

# Before you edit virsh_win_icon.rc, please note the following
# limitations of the resource file format:
#
# (1) '..' is not permitted in the icon filename field.
# (2) '-' is not permitted in the icon filename field.
# (3) Comments are not permitted in the file.
#
# Windows appears to choose the first <= 32x32 icon it finds
# in the resource file.  Therefore you should list the available
# icons from largest to smallest, and make sure that the 32x32
# icon is the most legible.
#
# Windows .ICO is a special MS-only format.  GIMP and other
# tools can write it.  However there are several variations,
# and Windows seems to do its own colour quantization.  More
# information is needed in this area.

virsh_win_icon.$(OBJEXT): virsh_win_icon.rc
	$(AM_V_GEN)$(WINDRES) \
	  --input-format rc --input $< \
	  --output-format coff --output $@
endif

virsh.1: virsh.pod
	$(AM_V_GEN)$(POD2MAN) $< $(srcdir)/$@

install-data-local: install-init

uninstall-local: uninstall-init

install-sysconfig:
	mkdir -p $(DESTDIR)$(sysconfdir)/sysconfig
	$(INSTALL_DATA) $(srcdir)/libvirt-guests.sysconf \
	  $(DESTDIR)$(sysconfdir)/sysconfig/libvirt-guests

uninstall-sysconfig:
	rm -f $(DESTDIR)$(sysconfdir)/sysconfig/libvirt-guests

EXTRA_DIST += libvirt-guests.init.sh

if LIBVIRT_INIT_SCRIPT_RED_HAT
install-init: libvirt-guests.init install-sysconfig
	mkdir -p $(DESTDIR)$(sysconfdir)/rc.d/init.d
	$(INSTALL_SCRIPT) libvirt-guests.init \
	  $(DESTDIR)$(sysconfdir)/rc.d/init.d/libvirt-guests

uninstall-init: install-sysconfig
	rm -f $(DESTDIR)$(sysconfdir)/rc.d/init.d/libvirt-guests

BUILT_SOURCES += libvirt-guests.init

else
install-init:
uninstall-init:
endif # LIBVIRT_INIT_SCRIPT_RED_HAT

libvirt-guests.init: libvirt-guests.init.sh $(top_builddir)/config.status
	$(AM_V_GEN)sed					\
	    -e 's!\@PACKAGE\@!$(PACKAGE)!g'		\
	    -e 's!\@bindir\@!$(bindir)!g'		\
	    -e 's!\@localedir\@!$(localedir)!g'		\
	    -e 's!\@localstatedir\@!$(localstatedir)!g'	\
	    -e 's!\@sbindir\@!$(sbindir)!g'		\
	    -e 's!\@sysconfdir\@!$(sysconfdir)!g'	\
	    < $< > $@-t &&				\
	    chmod a+x $@-t &&				\
	    mv $@-t $@



EXTRA_DIST += libvirt-guests.service.in

if LIBVIRT_INIT_SCRIPT_SYSTEMD
install-systemd: libvirt-guests.service install-sysconfig
	mkdir -p $(DESTDIR)$(sysconfdir)/rc.d/systemd.d
	$(INSTALL_SCRIPT) libvirt-guests.service \
	  $(DESTDIR)$(sysconfdir)/rc.d/systemd.d/libvirt-guests

uninstall-systemd: install-sysconfig
	rm -f $(DESTDIR)$(sysconfdir)/rc.d/systemd.d/libvirt-guests

BUILT_SOURCES += libvirt-guests.service

else
install-systemd:
uninstall-systemd:
endif # LIBVIRT_INIT_SCRIPT_SYSTEMD

libvirt-guests.service: libvirt-guests.service.in $(top_builddir)/config.status
	$(AM_V_GEN)sed					\
	    -e 's!\@PACKAGE\@!$(PACKAGE)!g'		\
	    -e 's!\@bindir\@!$(bindir)!g'		\
	    -e 's!\@localedir\@!$(localedir)!g'		\
	    -e 's!\@localstatedir\@!$(localstatedir)!g'	\
	    -e 's!\@sbindir\@!$(sbindir)!g'		\
	    -e 's!\@sysconfdir\@!$(sysconfdir)!g'	\
	    < $< > $@-t &&				\
	    chmod a+x $@-t &&				\
	    mv $@-t $@


CLEANFILES = $(bin_SCRIPTS)
CLEANFILES += *.gcov .libs/*.gcda .libs/*.gcno *.gcno *.gcda *.i *.s
MAINTAINERCLEANFILES = $(dist_man1_MANS)

DISTCLEANFILES += $(BUILT_SOURCES)
