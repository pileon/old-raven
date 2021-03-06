######################################################################
# File: src/host/Makefile.am                       Part of The Raven #
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

AUTOMAKE_OPTIONS = subdir-objects foreign

SUBDIRS    =
CLEANFILES = *~

AM_CXXFLAGS = @EXTRA_CXXFLAGS@ -I$(top_srcdir) -I..

######################################################################

noinst_LIBRARIES   = libhost.a

noinst_HEADERS     = sysdeps.h host.h

libhost_a_SOURCES  =
@IFNEQ@ (,$(findstring linux,$(host_os)))
libhost_a_SOURCES += posix/signal.cpp
@ENDIF@

######################################################################

.PHONY: get-files
get-files:
	@echo $(SOURCES:%=host/%) $(HEADERS:%=host/%)

.PHONY: count
count:
	wc $(HEADERS) $(SOURCES) | sort -g

.PHONY: count16k
count16k:
	$(top_builddir)/scripts/16k.py -c -b -l -s $(HEADERS) $(SOURCES) | wc

.PHONY: sloccount
sloccount:
	sloccount -- .

######################################################################
