# -*- buffer-read-only: t -*- vi: set ro:
# DO NOT EDIT! GENERATED AUTOMATICALLY!
# usleep.m4 serial 2
dnl Copyright (C) 2009-2011 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl This macro intentionally does not check for select or nanosleep;
dnl both of those modules can require external libraries.
AC_DEFUN([gl_FUNC_USLEEP],
[
  AC_REQUIRE([gl_UNISTD_H_DEFAULTS])
  dnl usleep was required in POSIX 2001, but dropped as obsolete in
  dnl POSIX 2008; therefore, it is not always exposed in headers.
  AC_REQUIRE([gl_USE_SYSTEM_EXTENSIONS])
  AC_CHECK_FUNCS_ONCE([usleep])
  AC_CHECK_TYPE([useconds_t], [],
    [AC_DEFINE([useconds_t], [unsigned int], [Define to an unsigned 32-bit
      type if <sys/types.h> lacks this type.])])
  if test $ac_cv_func_usleep = no; then
    HAVE_USLEEP=0
  else
    dnl POSIX allows implementations to reject arguments larger than
    dnl 999999, but GNU guarantees it will work.
    AC_CACHE_CHECK([whether usleep allows large arguments],
      [gl_cv_func_usleep_works],
      [AC_RUN_IFELSE([AC_LANG_PROGRAM([[
#include <unistd.h>
]], [[return !!usleep (1000000);]])],
        [gl_cv_func_usleep_works=yes], [gl_cv_func_usleep_works=no],
        [gl_cv_func_usleep_works="guessing no"])])
    if test "$gl_cv_func_usleep_works" != yes; then
      REPLACE_USLEEP=1
    fi
  fi
])
