/* -*- buffer-read-only: t -*- vi: set ro: */
/* DO NOT EDIT! GENERATED AUTOMATICALLY! */
/* Pausing execution of the current thread.
   Copyright (C) 2009-2011 Free Software Foundation, Inc.
   Written by Eric Blake <ebb9@byu.net>, 2009.

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

/* This file is _intentionally_ light-weight.  Rather than using
   select or nanosleep, both of which drag in external libraries on
   some platforms, this merely rounds up to the nearest second if
   usleep() does not exist.  If sub-second resolution is important,
   then use a more powerful interface to begin with.  */

#include <config.h>

/* Specification.  */
#include <unistd.h>

#include <errno.h>

#ifndef HAVE_USLEEP
# define HAVE_USLEEP 0
#endif

/* Sleep for MICRO microseconds, which can be greater than 1 second.
   Return -1 and set errno to EINVAL on range error (about 4295
   seconds), or 0 on success.  Interaction with SIGALARM is
   unspecified.  */

int
usleep (useconds_t micro)
{
  unsigned int seconds = micro / 1000000;
  if (sizeof seconds < sizeof micro && micro / 1000000 != seconds)
    {
      errno = EINVAL;
      return -1;
    }
  if (!HAVE_USLEEP && micro % 1000000)
    seconds++;
  while ((seconds = sleep (seconds)) != 0);

#undef usleep
#if !HAVE_USLEEP
# define usleep(x) 0
#endif
  return usleep (micro % 1000000);
}
