/* -*- buffer-read-only: t -*- vi: set ro: */
/* DO NOT EDIT! GENERATED AUTOMATICALLY! */
/* Read symbolic links without size limitation.

   Copyright (C) 2001, 2003-2004, 2007, 2009-2011 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation; either version 2.1 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* Written by Jim Meyering <jim@meyering.net>  */

#include <stddef.h>

extern char *areadlink (char const *filename);
extern char *areadlink_with_size (char const *filename, size_t size_hint);

#if GNULIB_AREADLINKAT
extern char *areadlinkat (int fd, char const *filename);
#endif

#if GNULIB_AREADLINKAT_WITH_SIZE
extern char *areadlinkat_with_size (int fd, char const *filename,
                                    size_t size_hint);
#endif
