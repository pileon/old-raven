/* -*- coding: utf-8 -*- */
/* *******************************************************************
* File: raven.cpp                                  Part of The Raven *
*                                                                    *
* Copyright (C) 2011, Joachim Pileborg and individual contributors.  *
* All rights reserved.                                               *
*                                                                    *
* Redistribution and use in source and binary forms, with or without *
* modification, are permitted provided that the following conditions *
* are met:                                                           *
*                                                                    *
*   o Redistributions of source code must retain the above copyright *
*     notice, this list of conditions and the following disclaimer.  *
*   o Redistributions in binary form must reproduce the above        *
*     copyright notice, this list of conditions and the following    *
*     disclaimer in the documentation and/or other materials         *
*     provided with the distribution.                                *
*   o Neither the name of The Raven nor the names of its contributors*
*     may be used to endorse or promote products derived from this   *
*     software without specific prior written permission.            *
*                                                                    *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND             *
* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,        *
* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF           *
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE           *
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  *
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,*
* OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,           *
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR *
* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY       *
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR     *
* TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF *
* THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF    *
* SUCH DAMAGE.                                                       *
*                                                                    *
******************************************************************* */

#include "raven.h"
#include <iostream>
#include <fstream>
#include "version.h"

// #include <boost/shared_ptr.hpp>
// #include <boost/make_shared.hpp>
// #include <boost/log/core.hpp>
// #include <boost/log/trivial.hpp>
// #include <boost/log/filters.hpp>
// #include <boost/log/sinks/text_ostream_backend.hpp>
// #include <boost/log/sinks/sync_frontend.hpp>
// #include <boost/log/utility/empty_deleter.hpp>

#if WITH_MTRACE && HAVE_MCHECK_H
# include <mcheck.h>
#endif
#if HAVE___GNU_CXX____VERBOSE_TERMINATE_HANDLER
# include <exception>
#endif

namespace raven {

/* **************************************************************** */

namespace
{
    bool init(int argc, char *argv[])
    {
        log::init();
        return true;
    }

    void clean()
    {
        log::clean();
    }

    /* ************************************************************ */

    void draw_title_box()
    {
        for (int i = 0; i < 16; i++)
            std::cout << " ";
        std::cout << u8"\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\n";

        for (int i = 0; i < 16; i++)
            std::cout << u8"\u2500";
        std::cout << u8"\u2562 The Raven \u255f";
        for (int i = 0; i < 51; i++)
            std::cout << u8"\u2500";
        std::cout << "\n";

        for (int i = 0; i < 16; i++)
            std::cout << " ";
        std::cout << u8"\u255a\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255d\n";
    }

    void draw_end_title()
    {
        for (int i = 0; i < 80; i++)
            std::cout << u8"\u2500";
        std::cout << "\n";
    }

}

/* **************************************************************** */

int main(int argc, char *argv[])
{
    draw_title_box();

#if WITH_MTRACE && HAVE_MTRACE
    mtrace();
#endif

#if HAVE___GNU_CXX____VERBOSE_TERMINATE_HANDLER
    std::set_terminate(__gnu_cxx::__verbose_terminate_handler);
#endif

    if (!init(argc, argv))
    {
        clean();
        draw_end_title();
        return 1;
    }

    LOG(debug, "hello world!");
    // run();

    std::cout << std::flush;
    std::cout << std::endl;

    clean();
    draw_end_title();

    return 0;
}

void exit()
{
}

/* **************************************************************** */

} // namespace raven
