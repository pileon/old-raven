######################################################################
# File: mk/clean.mk                                Part of The Raven #
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
#
# This file is to be included in all makefiles that want a target
# to clean up things.

######################################################################

GLOBAL_SOMECLEAN_FILES = *~
GLOBAL_CLEAN_FILES     =
GLOBAL_REALCLEAN_FILES =

######################################################################

.PHONY: someclean
someclean: __someclean
ifneq ($(SUBDIRS),)
	for d in $(SUBDIRS); do make -C $$d someclean; done
endif

.PHONY: clean
clean: __clean
ifneq ($(SUBDIRS),)
	for d in $(SUBDIRS); do make -C $$d clean; done
endif

.PHONY: realclean
realclean: __realclean
ifneq ($(SUBDIRS),)
	for d in $(SUBDIRS); do make -C $$d realclean; done
endif

######################################################################

.PHONY: local_someclean local_clean local_realclean
local_someclean local_clean local_realclean:

.PHONY: __someclean
__someclean:: local_someclean
ifneq ($(GLOBAL_SOMECLEAN_FILES),)
	-rm -f $(GLOBAL_SOMECLEAN_FILES)
endif
ifneq ($(local_someclean_files),)
	-rm -f $(local_someclean_files)
endif

.PHONY: __clean
__clean:: __someclean local_clean
ifneq ($(GLOBAL_CLEAN_FILES),)
	-rm -f $(GLOBAL_CLEAN_FILES)
endif
ifneq ($(local_clean_files),)
	-rm -f $(local_clean_files)
endif

.PHONY: __realclean
__realclean:: __clean local_realclean
ifneq ($(GLOBAL_REALCLEAN_FILES),)
	-rm -f $(GLOBAL_REALCLEAN_FILES)
endif
ifneq ($(local_realclean_files),)
	-rm -f $(local_realclean_files)
endif

######################################################################
