# -*- buffer-read-only: t -*- vi: set ro:
# DO NOT EDIT! GENERATED AUTOMATICALLY!
# count-one-bits.m4 serial 2
dnl Copyright (C) 2007, 2009-2011 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_COUNT_ONE_BITS],
[
  dnl We don't need (and can't compile) count_one_bits_ll
  dnl unless the type 'unsigned long long int' exists.
  AC_REQUIRE([AC_TYPE_UNSIGNED_LONG_LONG_INT])

  dnl Prerequisites of lib/count-one-bits.h.
  AC_REQUIRE([AC_C_INLINE])
])
