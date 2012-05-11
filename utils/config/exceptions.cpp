// Copyright 2012 Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
// * Neither the name of Google Inc. nor the names of its contributors
//   may be used to endorse or promote products derived from this software
//   without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "utils/config/exceptions.hpp"

namespace config = utils::config;


/// Constructs a new error with a plain-text message.
///
/// \param message The plain-text error message.
config::error::error(const std::string& message) :
    std::runtime_error(message)
{
}


/// Destructor for the error.
config::error::~error(void) throw()
{
}


/// Constructs a new error with a plain-text message.
///
/// \param message The plain-text error message.
config::invalid_key_error::invalid_key_error(const std::string& message) :
    error(message)
{
}


/// Destructor for the error.
config::invalid_key_error::~invalid_key_error(void) throw()
{
}


/// Constructs a new error with a plain-text message.
///
/// \param message The plain-text error message.
config::unknown_key_error::unknown_key_error(const std::string& message) :
    error(message)
{
}


/// Destructor for the error.
config::unknown_key_error::~unknown_key_error(void) throw()
{
}


/// Constructs a new error with a plain-text message.
///
/// \param message The plain-text error message.
config::value_error::value_error(const std::string& message) :
    error(message)
{
}


/// Destructor for the error.
config::value_error::~value_error(void) throw()
{
}
