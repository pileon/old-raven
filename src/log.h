// -*- mode: C++; coding: utf-8 -*-
#ifndef __LOG_H__
#define __LOG_H__ 1
/* *******************************************************************
* File: log.h                                      Part of The Raven *
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

// The name "log" is also used by std::log from <cmath>
#ifdef log
# undef log
#endif

namespace raven {

//! \todo Use the future boost.log framework instead, wrapped in our
//!       own simplified framework.
//! \todo If not using boost.log, add the ability to log to both the
//!       console and a file at the same time.
namespace log {

/* **************************************************************** */

//! Initialize the logging sub-system.
//!
//! \param filename Optional filename of a file where to put the output.
//!                 If not given, will use standard output.
//!
//! \return If initialization went ok or not.
//! \retval true  Initialization was ok.
//! \retval false Initilization failed.
bool init(const std::string &filename = "");

//! Initialize the logging sub-system.
//!
//! \param file     The file to use for output.
//!
//! \return If initialization went ok or not.
//! \retval true  Initialization was ok.
//! \retval false Initilization failed.
bool init(std::ostream &file);

//! Clean up resources on shutdown.
void clean();

//! Get the output stream used for the logging.
std::ostream &get_stream();

//! Get a string for the date and time.
const std::string get_datetime();

/* **************************************************************** */

//! Logging types.
//!
//! \todo Try to make something more general? With backends and formaters
//!       and all that stuff.
namespace types
{
    class type
    {
    public:
        explicit type(const char *name) throw()
            : m_name(name)
            { }

        const std::string &name() const throw()
            { return m_name; }

    private:
        std::string m_name;

        type() = delete;
        type(const type &) = delete;
    };

    const type debug { "DEBUG" };
    const type info  { "INFO " };

    inline std::ostream &operator<<(std::ostream &os, const type &type)
    {
        os << "[" << type.name() << "]";
        return os;
    }

}

/* **************************************************************** */

#define LOG(type, stream)                                               \
    log::get_stream() << log::get_datetime() << " :: "                  \
    << log::types::type << " " << stream << '\n'

/* **************************************************************** */

} // namespace log
} // namespace raven

#endif // __LOG_H__
