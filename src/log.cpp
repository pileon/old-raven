// -*- coding: utf-8 -*-
/* *******************************************************************
* File: log.cpp                                    Part of The Raven *
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
#include "log.h"

#include <chrono>
#include <iomanip>
#include <ctime>

namespace raven {
namespace log {

/* **************************************************************** */

namespace
{
    std::ostream &output = std::cout;
}

/* **************************************************************** */

bool init(const std::string &filename /* = "" */)
{
    LOG(debug, "hello world!");
    return true;
}

void clean()
{
}

std::ostream &get_stream()
{
    return output;
}

const std::string get_datetime()
{
    time_t now = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now());
    // XXX: libstdc++ doesn't implement `put_time` as of yet
    // return std::put_time(std::localtime(&now_t), "%F %T");

    char buf[32];  // Buffer must be at least 26 characters (ctime_r(3))
    std::string s = ctime_r(&now, buf);

    return s.substr(0, s.length() - 1);  // -1 to remove newline
    //! \todo -2 om Windows?
    //! \todo This might need to be put in host
}

/* **************************************************************** */

} // namespace log
} // namespace raven
