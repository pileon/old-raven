dnl # Process this file with autoconf to produce a configure script.
dnl ######################################################################
dnl # File: configure.ac                               Part of The Raven #
dnl #                                                                    #
dnl # Copyright (C) 2011, Joachim Pileborg and individual contributors.  #
dnl # All rights reserved.                                               #
dnl #                                                                    #
dnl # Redistribution and use in source and binary forms, with or without #
dnl # modification, are permitted provided that the following conditions #
dnl # are met:                                                           #
dnl #                                                                    #
dnl #   o Redistributions of source code must retain the above copyright #
dnl #     notice, this list of conditions and the following disclaimer.  #
dnl #   o Redistributions in binary form must reproduce the above        #
dnl #     copyright notice, this list of conditions and the following    #
dnl #     disclaimer in the documentation and/or other materials         #
dnl #     provided with the distribution.                                #
dnl #   o Neither the name of The Raven nor the names of its contributors#
dnl #     may be used to endorse or promote products derived from this   #
dnl #     software without specific prior written permission.            #
dnl #                                                                    #
dnl # THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND             #
dnl # CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,        #
dnl # INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF           #
dnl # MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE           #
dnl # DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  #
dnl # BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,#
dnl # OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,           #
dnl # PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR #
dnl # PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY       #
dnl # THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR     #
dnl # TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF #
dnl # THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF    #
dnl # SUCH DAMAGE.                                                       #
dnl #                                                                    #
dnl ######################################################################
dnl # Information on the package

AC_INIT(raven, [0.0.0], [raven@pileborg.org], , [https://github.com/pileon/raven])
AC_CONFIG_AUX_DIR([scripts])
AC_CONFIG_MACRO_DIR([scripts])
AM_INIT_AUTOMAKE
AC_COPYRIGHT([Parts of the configure script is copyright (C) 2011, Joachim Pileborg and individual contributors.])
AC_CONFIG_SRCDIR([src/raven.h])
AC_CONFIG_HEADERS([src/host/autoconf.h])
AC_CONFIG_LIBOBJ_DIR([src/libobj])
AC_CONFIG_FILES([Makefile src/Makefile src/host/Makefile])
LT_INIT

AC_CANONICAL_HOST

dnl ######################################################################
dnl # Automake specific checks

AM_INIT_AUTOMAKE

dnl ######################################################################
dnl # Checks for programs

dnl # The actual compiler
AC_PROG_CXX
AC_PROG_CXX_C_O
AC_PROG_CXXCPP

dnl # Set default language to C++
AC_LANG([C++])

dnl # General programs, and their arguments
dnl AC_PROG_RANLIB
AC_PROG_LIBTOOL

AC_REQUIRE_CPP

dnl ######################################################################
dnl # Checks for libraries

# AC_PATH_BOOST([1.42.0])

dnl ######################################################################
dnl # Checks for header files

AC_CHECK_HEADERS([sys/types.h sys/stat.h stdlib.h string.h memory.h strings.h])
AC_CHECK_HEADERS([inttypes.h stdint.h unistd.h errno.h signal.h sys/stat.h])

# TODO: boost header files

dnl ######################################################################
dnl # Checks for types

AC_TYPE_LONG_LONG_INT
AC_TYPE_MBSTATE_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_SIGNAL

AC_CHECK_TYPES([char16_t], [], [], [])
AC_CHECK_TYPES([char32_t], [], [], [])

# TODO: boost types

dnl ######################################################################
dnl # Checks for structures

AC_CHECK_MEMBER([struct stat.st_blksize],
                [AC_DEFINE(HAVE_STRUCT_STAT_ST_BLKSIZE, 1,
                           [Define to 1 if struct stat have a member st_blksize.])],
                [], [[#include <sys/stat.h>]])

dnl ######################################################################
dnl # Checks for compiler characteristics

AC_C_BACKSLASH_A
AC_C_BACKSLASH_E

AC_ARG_ENABLE([gdb3],
  [  --enable-gdb3           enable higher debug level option to the compiler],
  [if test $enableval = yes; then
     AC_CHECK_CXX_ARGUMENT(-ggdb3, [cxx_have_ggdb3=yes], [cxx_have_ggdb3=no])
   fi])
if test $cxx_have_ggdb3 = yes; then
  CXXFLAGS=`echo $CXXFLAGS | sed 's/\-g//'`
fi

AC_ARG_ENABLE([c++0x],
  [  --enable-c++0x          enable use of new C++ standard features],
  [if test $enableval = yes; then
     AC_CHECK_CXX_ARGUMENT(-std=c++0x)
   fi])

AC_ARG_ENABLE([pipe],
  [  --enable-pipe           enable the compilers -pipe argument],
  [if test $enableval = yes; then
     AC_CHECK_CXX_ARGUMENT(-pipe)
   fi])

AC_ARG_ENABLE([pedantic],
  [  --enable-pedantic       enable the compilers -pedantic argument],
  [if test $enableval = yes; then
     AC_CHECK_CXX_ARGUMENT(-pedantic)
   fi])

AC_ARG_ENABLE([warnings],
  [  --enable-warnings       enable extra warnings from the compiler],
  [if test $enableval = yes; then
     AC_CHECK_CXX_ARGUMENT(-Wall)
     AC_CHECK_CXX_ARGUMENT(-Wextra)
     AC_CHECK_CXX_ARGUMENT(-Weffc++)
   fi])

AC_ARG_ENABLE([opt],
  [  --disable-opt           disable compiler optimizations],
  [if test $enableval = no; then
     CXXFLAGS=`echo "$CXXFLAGS" | sed 's/-O2//'`
   fi])

AC_ARG_ENABLE([profiling],
  [  --enable-profiling      enable compiler profiling of code],
  [if test $enableval = yes; then
     :
   fi])

AC_MSG_CHECKING([if ${CXX-g++} supports __attribute__((malloc))])
AC_COMPILE_IFELSE(
  [AC_LANG_PROGRAM([void *foo() __attribute__ ((malloc)); ], [])],
  [AC_MSG_RESULT(yes)
   AC_DEFINE(HAVE___ATTRIBUTE__MALLOC, 1,
     [Define to 1 if the compilers supports __attribute__((malloc))])],
  [AC_MSG_RESULT(no)])

AC_MSG_CHECKING([if ${CXX-g++} supports __attribute__((format (printf)))])
AC_COMPILE_IFELSE(
  [AC_LANG_PROGRAM([void *foo(char *a, ...) __attribute__ ((format (printf, 1, 2))); ], [])],
  [AC_MSG_RESULT(yes)
   AC_DEFINE(HAVE___ATTRIBUTE__FORMAT_PRINTF, 1,
     [Define to 1 if the compilers supports __attribute__((format (printf)))])],
  [AC_MSG_RESULT(no)])

AC_MSG_CHECKING([if ${CXX-g++} supports __PRETTY_FUNCTION__])
AC_LINK_IFELSE(
  [AC_LANG_PROGRAM(
    [
#include <iostream>
    ],
    [[
      std::cout << __PRETTY_FUNCTION__;
    ]])],
  [AC_MSG_RESULT(yes)
   AC_DEFINE(HAVE___PRETTY_FUNCTION__, 1,
     [Define to 1 if the compiler supports the __FUNCTION__ literal])],
  [AC_MSG_RESULT(no)])

AC_MSG_CHECKING([if ${CXX-g++} supports __FUNCTION__])
AC_LINK_IFELSE(
  [AC_LANG_PROGRAM(
    [
#include <iostream>
    ],
    [[
      std::cout << __FUNCTION__;
    ]])],
  [AC_MSG_RESULT(yes)
   AC_DEFINE(HAVE___FUNCTION__, 1,
     [Define to 1 if the compiler supports the __func__ variable])],
  [AC_MSG_RESULT(no)])

AC_MSG_CHECKING([if ${CXX-g++} supports __func__])
AC_LINK_IFELSE(
  [AC_LANG_PROGRAM(
    [
#include <iostream>
    ],
    [[
      std::cout << __func__;
    ]])],
  [AC_MSG_RESULT(yes)
   AC_DEFINE(HAVE___FUNC__, 1,
     [Define to 1 if the compiler supports the __func__ variable])],
  [AC_MSG_RESULT(no)])

AC_MSG_CHECKING([if ${CXX-g++} supports nullptr])
AC_LINK_IFELSE(
  [AC_LANG_PROGRAM(
    [],
    [[
      char *char_null = nullptr;
    ]])],
  [AC_MSG_RESULT(yes)
   AC_DEFINE(HAVE_NULLPTR, 1,
     [Define to 1 if the compiler supports the nullptr C++0x constant])],
  [AC_MSG_RESULT(no)])

AC_MSG_CHECKING([if ${CXX-g++} supports computed gotos])
AC_COMPILE_IFELSE(
  [AC_LANG_PROGRAM(
    [],
    [[
      void *my_label_ptr = &&my_label;  /* GCC syntax */
      goto *my_label_ptr;
      return 1;
      my_label:
      return 0;
    ]])],
  [AC_MSG_RESULT(yes)
   AC_DEFINE(HAVE_COMPUTED_GOTOS, 1,
     [Define to 1 if the compilers supports computed gotos])],
  [AC_MSG_RESULT(no)])

# TODO: Check for: Unicode string/character support (C++11 u8"\u2018", u"\u2018" and U"\u2018")
# TODO: Check for: Raw strings (C++11 R"delim(string)delim")

dnl ######################################################################
dnl # Checks for library functions

AC_CHECK_FUNCS([signal sigaction stat fstat])

AC_MSG_CHECKING([for __gnu_cxx::__verbose_terminate_handler])
AC_LINK_IFELSE(
  [AC_LANG_PROGRAM(
     [
#include <exception>
     ],
     [[
       std::set_terminate(__gnu_cxx::__verbose_terminate_handler);
     ]])],
  [AC_MSG_RESULT(yes)
   AC_DEFINE(HAVE___GNU_CXX____VERBOSE_TERMINATE_HANDLER, 1,
             [Define to 1 if __gnu_cxx::__verbose_terminate_handler is available])],
  [AC_MSG_RESULT(no)])

dnl ######################################################################
dnl # Checks for system services

AC_FUNC_STRERROR_R
AM_MAINTAINER_MODE
AM_WITH_DMALLOC

AC_UNSAFE_CRYPT

AC_ARG_WITH(mtrace,
  [  --with-mtrace           Use the GNU C library to check potential memory leaks],
  [if test "$withval" = yes; then
     AC_DEFINE(WITH_MTRACE, 1,
       [Define if using the GNU C library mtrace memory debuging routines])
     AC_CHECK_HEADERS(mcheck.h)
     AC_CHECK_FUNCS(mtrace)
   fi])

AC_ARG_WITH(ssl,
  [  --with-ssl              use secure connections with SSL],
  [if test "$withval" = yes; then
     AC_DEFINE(USE_SSL, 1, [Define to 1 if we should use OpenSSL.])
     AC_CHECK_LIB(ssl, SSL_library_init)
     AC_CHECK_LIB(crypto, DH_new)
     AC_CHECK_HEADERS([openssl/ssl.h openssl/err.h])
     AC_CHECK_FILE([/dev/urandom],
       [AC_DEFINE(HAVE_DEV_URANDOM, 1,
       [Define to 1 if the /dev/urandom device exists.])])
   fi])

dnl ######################################################################
dnl # Check for Boost functionality

BOOST_REQUIRE([1.46.0],
	[AC_MSG_ERROR([The Raven requires Boost version 1.46.0 or higher.])])

BOOST_PROGRAM_OPTIONS
BOOST_SIGNALS
BOOST_DATE_TIME
BOOST_ASIO

dnl ######################################################################

AC_ARG_WITH(debug,
  [  --with-debug            #define DEBUG 1],
  [if test "$withval" = yes; then
     AC_DEFINE(DEBUG, 1, [Define to 1 to enable extra debugging])
   fi])

AC_ARG_WITH(trace,
  [  --with-trace            if calls should be traced],
  [if test "$withval" = yes; then
     AC_DEFINE(DO_TRACE, 1, [Define to 1 to enable call tracing])
   fi])

# TODO: autoheader templates?

AH_TOP([/* -*- C++ -*- */
/* -*- coding: utf-8 -*- */
#ifndef __HOST_AUTOCONF_H__
#define __HOST_AUTOCONF_H__ 1
/* *******************************************************************
* File: host/autoconf.h                            Part of The Raven *
*                                                                    *
* This file is automaticly generated by the configure script.        *
* All changes to this file may be lost without warning.              *
******************************************************************* */

#define RAVEN_UNIX 1

])

AH_BOTTOM([
/* **************************************************************** */
#endif /* __HOST_AUTOCONF_H__ */
])

dnl For use in makefiles, since automake can't handle it properly
AC_SUBST([IFEQ], [ifeq])
AC_SUBST([IFNEQ], [ifneq])
AC_SUBST([IFDEF], [ifdef])
AC_SUBST([ELSE], [else])
AC_SUBST([ENDIF], [endif])

AC_OUTPUT

dnl ######################################################################
