/* -*- mode: C++; coding: utf-8 -*- */
#ifndef __CONFIG_H__
#define __CONFIG_H__ 1
/* *******************************************************************
* File: config.h                                   Part of The Raven *
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

#include <map>
#include <boost/any.hpp>

namespace raven {
namespace config {

/* **************************************************************** */

// TODO: Initialization
// TODO: Function for parsing arguments
// TODO: Function for reading and parsing configuration file
// TODO: Functions to get/set configuration variables

template<typename T>
inline T &get(const std::string &name)
{
	std::map<std::string, boost::any> &get_values();

	auto valuei = get_values().find(name);
	if (valuei == get_values().end())
	{
		auto p = get_values().insert(
			std::pair<std::string, boost::any>{ name, boost::any{} });
		valuei = p.first;
	}

	return boost::any_cast<T&>((*valuei).second);
}

template<typename T>
inline void set(const std::string &name, const T &value)
{
	std::map<std::string, boost::any> &get_values();

	get_values().insert(
		std::pair<std::string, boost::any>{ name, value });
}

/* **************************************************************** */

} // namespace config
} // namespace raven

#endif // __CONFIG_H__
