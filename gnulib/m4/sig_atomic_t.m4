# -*- buffer-read-only: t -*- vi: set ro:
# DO NOT EDIT! GENERATED AUTOMATICALLY!
# sig_atomic_t.m4 serial 2
dnl Copyright (C) 2003, 2009-2011 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gt_TYPE_SIG_ATOMIC_T],
[
  AC_CHECK_TYPES([sig_atomic_t], ,
    [AC_DEFINE([sig_atomic_t], [int],
       [Define as an integer type suitable for memory locations that can be
        accessed atomically even in the presence of asynchnonous signals.])],
    [#include <signal.h>])
])
