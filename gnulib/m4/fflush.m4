# -*- buffer-read-only: t -*- vi: set ro:
# DO NOT EDIT! GENERATED AUTOMATICALLY!
# fflush.m4 serial 13

# Copyright (C) 2007-2011 Free Software Foundation, Inc.
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

dnl From Eric Blake

dnl Find out how to obey POSIX semantics of fflush(stdin) discarding
dnl unread input on seekable streams, rather than C99 undefined semantics.

AC_DEFUN([gl_FUNC_FFLUSH],
[
  AC_REQUIRE([gl_STDIO_H_DEFAULTS])
  gl_FUNC_FFLUSH_STDIN
  if test $gl_cv_func_fflush_stdin = no; then
    REPLACE_FFLUSH=1
  fi
])

dnl Determine whether fflush works on input streams.
dnl Sets gl_cv_func_fflush_stdin.

AC_DEFUN([gl_FUNC_FFLUSH_STDIN],
[
  AC_CHECK_HEADERS_ONCE([unistd.h])
  AC_CACHE_CHECK([whether fflush works on input streams],
    [gl_cv_func_fflush_stdin],
    [echo hello world > conftest.txt
     AC_RUN_IFELSE([AC_LANG_PROGRAM(
       [[
#include <stdio.h>
#if HAVE_UNISTD_H
# include <unistd.h>
#else /* on Windows with MSVC */
# include <io.h>
#endif
       ]], [[FILE *f = fopen ("conftest.txt", "r");
         char buffer[10];
         int fd;
         int c;
         if (f == NULL)
           return 1;
         fd = fileno (f);
         if (fd < 0 || fread (buffer, 1, 5, f) != 5)
           return 2;
         /* For deterministic results, ensure f read a bigger buffer.  */
         if (lseek (fd, 0, SEEK_CUR) == 5)
           return 3;
         /* POSIX requires fflush-fseek to set file offset of fd.  This fails
            on BSD systems and on mingw.  */
         if (fflush (f) != 0 || fseek (f, 0, SEEK_CUR) != 0)
           return 4;
         if (lseek (fd, 0, SEEK_CUR) != 5)
           return 5;
         /* Verify behaviour of fflush after ungetc. See
            <http://www.opengroup.org/austin/aardvark/latest/xshbug3.txt>  */
         /* Verify behaviour of fflush after a backup ungetc.  This fails on
            mingw.  */
         c = fgetc (f);
         ungetc (c, f);
         fflush (f);
         if (fgetc (f) != c)
           return 6;
         /* Verify behaviour of fflush after a non-backup ungetc.  This fails
            on glibc 2.8 and on BSD systems.  */
         c = fgetc (f);
         ungetc ('@', f);
         fflush (f);
         if (fgetc (f) != c)
           return 7;
         return 0;
       ]])], [gl_cv_func_fflush_stdin=yes], [gl_cv_func_fflush_stdin=no],
     [dnl Pessimistically assume fflush is broken.
      gl_cv_func_fflush_stdin=no])
     rm conftest.txt
    ])
])

# Prerequisites of lib/fflush.c.
AC_DEFUN([gl_PREREQ_FFLUSH],
[
  AC_REQUIRE([AC_C_INLINE])
  :
])
