/* -*- buffer-read-only: t -*- vi: set ro: */
/* DO NOT EDIT! GENERATED AUTOMATICALLY! */
/* Wrappers that don't throw invalid parameter notifications
   with MSVC runtime libraries.
   Copyright (C) 2011 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation; either version 2.1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License along
   with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

#include <config.h>

/* Specification.  */
#include "msvc-nothrow.h"

/* Get declarations of the Win32 API functions.  */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "msvc-inval.h"

#undef _get_osfhandle

#if HAVE_MSVC_INVALID_PARAMETER_HANDLER
intptr_t
_gl_nothrow_get_osfhandle (int fd)
{
  intptr_t result;

  TRY_MSVC_INVAL
    {
      result = _get_osfhandle (fd);
    }
  CATCH_MSVC_INVAL
    {
      result = (intptr_t) INVALID_HANDLE_VALUE;
    }
  DONE_MSVC_INVAL;

  return result;
}
#endif
