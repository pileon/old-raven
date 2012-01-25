=========
The Raven
=========

The Raven is a MUD server made in C++ using the latest C++11 standard
and elements from the Boost library.

MUD
===

What is a MUD?
--------------
A MUD is a kind of online game, where many people can connect at the
same time, socialising and adventuring together.

If it sounds like a modern-day massively online games, it's because MUDS
are the forerunners of those modern games. The biggest difference is
first that a MUD is almost always text-only while modern games are
graphical. The second difference is one of scale: A MUD mostly have
below one hundred players online at the same time, while modern games
are called massive because that's what they are.

For more information about MUDs, see http://en.wikipedia.org/wiki/MUD

The Raven
=========

The Raven MUD server is split into two parts: The server and the library.

The server
----------
The server is the actual program running on a computer. It handles all the
networking stuff, as well as parsing input from players and handling the
library.

The library
-----------
The library is the actual world; This is where the creators of the
game-world puts all their creations, be it monsters, castles or weapons.


Building
========

Building The Raven is supposed to be easy, as long as you have the right
tools.

Prerequisites
-------------

Tools
~~~~~
* GNU C++ compiler, version 4.6 or later
* GNU Make version 3.80 or later.

Libraries
~~~~~~~~~

Building
--------
Standing in the top directory, a simple `make` will be enough.
