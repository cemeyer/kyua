// Copyright 2011 Google Inc.
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

/// \file cli/filters.hpp
/// Representation and manipulation of filters for test cases.
///
/// All the filter classes in this module are supposed to be purely functional:
/// they are mere filters that decide whether they match or not the input data
/// fed to them.  User-interface filter manipulation must go somewhere else.
///
/// TODO(jmmv): This probably belongs in engine/.  However, there is no code
/// outside of the frontend that needs this at the moment, so this is why it is
/// here.

#if !defined(CLI_FILTERS_HPP)
#define CLI_FILTERS_HPP

#include <string>
#include <set>
#include <utility>

#include "utils/fs/path.hpp"
#include "utils/optional.ipp"


namespace engine {
struct test_case_id;
}  // namespace engine


namespace cli {


/// Filter for test cases.
///
/// A filter is one of: the name of a directory containing test cases, the name
/// of a test program, or the name of a test program plus the name of a test
/// case.
struct test_filter {
    /// The name of the test program or subdirectory to match.
    utils::fs::path test_program;

    /// The name of the test case to match; if empty, represents any test case.
    std::string test_case;

    test_filter(const utils::fs::path&, const std::string&);
    static test_filter parse(const std::string&);

    std::string str(void) const;

    bool contains(const test_filter&) const;
    bool matches_test_program(const utils::fs::path&) const;
    bool matches_test_case(const engine::test_case_id&) const;

    bool operator<(const test_filter&) const;
    bool operator==(const test_filter&) const;
    bool operator!=(const test_filter&) const;
};


/// Collection of user-provided filters to select test cases.
///
/// An empty collection of filters is considered to match any test case.
///
/// In general, the filters maintained by this class should be disjoint.  If
/// they are not, some filters may never have a chance to do a match, which is
/// most likely the fault of the user.  To check for non-disjoint filters before
/// constructing this object, use check_disjoint_filters.
class test_filters {
    std::set< test_filter > _filters;

public:
    test_filters(const std::set< test_filter >&);

    /// Return type of match_test_case.  Indicates whether the filters have
    /// matched a particular test case and, if they have, which filter did the
    /// match (if any).
    typedef std::pair< bool, utils::optional< test_filter > > match;

    bool match_test_program(const utils::fs::path&) const;
    match match_test_case(const engine::test_case_id&) const;

    std::set< test_filter > difference(const std::set< test_filter >&) const;
};


void check_disjoint_filters(const std::set< test_filter >&);


}  // namespace cli

#endif  // !defined(CLI_FILTERS_HPP)
