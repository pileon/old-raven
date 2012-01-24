# Process this file with automake to produce a Makefile.in template
######################################################################
# File: src/Makefile.am                            Part of The Raven #
#                                                                    #
# Copyright (C) 2011, Joachim Pileborg and individual contributors.  #
# All rights reserved.                                               #
#                                                                    #
# Redistribution and use in source and binary forms, with or without #
# modification, are permitted provided that the following conditions #
# are met:                                                           #
#                                                                    #
#   o Redistributions of source code must retain the above copyright #
#     notice, this list of conditions and the following disclaimer.  #
#   o Redistributions in binary form must reproduce the above        #
#     copyright notice, this list of conditions and the following    #
#     disclaimer in the documentation and/or other materials         #
#     provided with the distribution.                                #
#   o Neither the name of The Raven nor the names of its contributors#
#     may be used to endorse or promote products derived from this   #
#     software without specific prior written permission.            #
#                                                                    #
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND             #
# CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,        #
# INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF           #
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE           #
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  #
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,#
# OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,           #
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR #
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY       #
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR     #
# TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF #
# THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF    #
# SUCH DAMAGE.                                                       #
#                                                                    #
######################################################################

AUTOMAKE_OPTIONS = subdir-objects

SUBDIRS    = host
CLEANFILES = *~

AM_CXXFLAGS = @EXTRA_CXXFLAGS@

LDFLAGS_BOOST = \
	$(BOOST_SYSTEM_LDFLAGS) \
	$(BOOST_PROGRAM_OPTIONS_LDFLAGS) \
	$(BOOST_SIGNALS_LDFLAGS) \
	$(BOOST_DATE_TIME_LDFLAGS) \
	$(BOOST_ASIO_LDFLAGS)

LIBS_BOOST = \
	$(BOOST_SYSTEM_LIBS) \
	$(BOOST_PROGRAM_OPTIONS_LIBS) \
	$(BOOST_SIGNALS_LIBS) \
	$(BOOST_DATE_TIME_LIBS) \
	$(BOOST_ASIO_LIBS)

AM_CPPFLAGS = $(BOOST_CPPFLAGS)
AM_LDFLAGS  = $(LDFLAGS_BOOST)
LIBS       += $(LIBS_BOOST)
LIBS       += host/libhost.a

######################################################################

noinst_PROGRAMS = raven

noinst_HEADERS  = raven.h version.h log.h

raven_SOURCES   = host/posix/main.cpp raven.cpp log.cpp

raven_LDADD     = $(LIBOBJS)

raven_DEPENDENCIES = host/libhost.a

######################################################################

.PHONY: doxygen
doxygen:
	doxygen raven.doxygen

######################################################################

# TODO: count and count16k, and maybe other count targets (like sloccount)?

######################################################################
