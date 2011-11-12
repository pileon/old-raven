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

#include "version.h"

// #include <boost/shared_ptr.hpp>
// #include <boost/make_shared.hpp>
// #include <boost/log/core.hpp>
// #include <boost/log/trivial.hpp>
// #include <boost/log/filters.hpp>
// #include <boost/log/sinks/text_ostream_backend.hpp>
// #include <boost/log/sinks/sync_frontend.hpp>
// #include <boost/log/utility/empty_deleter.hpp>

namespace raven {

/* **************************************************************** */


/* **************************************************************** */

int main(int argc, char *argv[])
{
    std::cout << "Hello world!\n";

    // {
    //     boost::shared_ptr<boost::log::core > core = boost::log::core::get();

    //     // Create a backend and attach a couple of streams to it
    //     boost::shared_ptr<boost::log::sinks::text_ostream_backend> backend =
    //         boost::make_shared<boost::log::sinks::text_ostream_backend>();

    //     backend->add_stream(
    //         boost::shared_ptr<std::ostream >(&std::clog, boost::log::empty_deleter()));

    //     // Enable auto-flushing after each log record written
    //     backend->auto_flush(true);

    //     // Wrap it into the frontend and register in the core.
    //     // The backend requires synchronization in the frontend.
    //     typedef boost::log::sinks::synchronous_sink<boost::log::sinks::text_ostream_backend > sink_t;
    //     boost::shared_ptr<sink_t> sink(new sink_t(backend));
    //     core->add_sink(sink);
    // }

    // BOOST_LOG_TRIVIAL(info) << "An informational severity message";

    // std::cout << "Logging done\n";

    log::init();
    log::clean();

    return 0;
}

void exit()
{
}

/* **************************************************************** */

} // namespace raven
