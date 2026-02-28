// Copyright 2008, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
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

//
// Google C++ Testing and Mocking Framework (Google Test)
//
// Sometimes it's desirable to build Google Test by compiling a single file.
// This file serves this purpose.

// This line ensures that gtest.h can be compiled on its own, even
// when it's fused.
// Suppress the deprecated-declarations warning that Clang emits when
// std::stable_sort internally uses std::get_temporary_buffer (deprecated in
// C++17).  The [[deprecated]] attribute lives in <bits/stl_tempbuf.h>, which
// is first parsed when <memory> is included via gtest.h.  We pre-include that
// specific header with the warning suppressed so that only declarations in
// this one header are affected—other deprecated declarations in <memory> are
// still diagnosed normally.  This works around Clang bug
// https://github.com/llvm/llvm-project/issues/76515 where #pragma diagnostic
// suppression at the call site does not propagate through template
// instantiation for [[deprecated]] attributes.
#if defined(__clang__) && __has_include(<bits/stl_tempbuf.h>)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <bits/stl_tempbuf.h>
#pragma clang diagnostic pop
#endif
#include "gtest/gtest.h"

// The following lines pull in the real gtest *.cc files.
#include "src/gtest-assertion-result.cc"
#include "src/gtest-death-test.cc"
#include "src/gtest-filepath.cc"
#include "src/gtest-matchers.cc"
#include "src/gtest-port.cc"
#include "src/gtest-printers.cc"
#include "src/gtest-test-part.cc"
#include "src/gtest-typed-test.cc"
#include "src/gtest.cc"
