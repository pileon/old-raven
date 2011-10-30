#!/bin/sh

# source ./autogen.sh

./configure \
	--enable-gdb3 \
	--enable-pipe \
	--disable-profiling \
	--enable-warnings \
	--disable-opt \
	--enable-maintainer-mode \
	--with-mtrace \
	--with-debug \
	--with-ssl \
	--with-boost \
	--enable-c++0x \
	--enable-pedantic
