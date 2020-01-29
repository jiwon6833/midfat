// -*- Mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*-
// Copyright (c) 2003, Google Inc.
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
// ---
//
// Author: Lei Zhang, Sasha Levitskiy
//
// This file is an internal atomic implementation, use base/atomicops.h instead.
//
// LinuxKernelCmpxchg is from Google Gears.

#ifndef BASE_ATOMICOPS_INTERNALS_RISCV_H_
#define BASE_ATOMICOPS_INTERNALS_RISCV_H_

#include <stdio.h>
#include <stdlib.h>
#include "base/basictypes.h"

typedef int32_t Atomic32;

namespace base {
namespace subtle {

typedef int64_t Atomic64;

inline void NotImplementedFatalError(const char *function_name) {
  fprintf(stderr, "%s() not implemented on this platform\n",
          function_name);
  abort();
}

inline Atomic32 NoBarrier_CompareAndSwap(volatile Atomic32* ptr,
                                         Atomic32 old_value,
                                         Atomic32 new_value) {
  Atomic32 prev = *ptr;
  if (prev != old_value)
    goto end;
  *ptr = new_value;
 end:
  return prev;
}

inline Atomic32 NoBarrier_AtomicExchange(volatile Atomic32* ptr,
                                         Atomic32 new_value) {
  Atomic32 old = *ptr;
  *ptr = new_value;
  return old;
}

inline void MemoryBarrier() {
}

inline Atomic32 Acquire_AtomicExchange(volatile Atomic32* ptr,
                                       Atomic32 new_value) {
  NotImplementedFatalError("32-bit Acquire_AtomicExchange");
  return 0;
}

inline Atomic32 Release_AtomicExchange(volatile Atomic32* ptr,
                                       Atomic32 new_value) {
  MemoryBarrier();
  return NoBarrier_AtomicExchange(ptr, new_value);
}

inline Atomic32 Acquire_CompareAndSwap(volatile Atomic32* ptr,
                                       Atomic32 old_value,
                                       Atomic32 new_value) {
  Atomic32 res = NoBarrier_CompareAndSwap(ptr, old_value, new_value);
  MemoryBarrier();
  return res;
}

inline Atomic32 Release_CompareAndSwap(volatile Atomic32* ptr,
                                       Atomic32 old_value,
                                       Atomic32 new_value) {
  NotImplementedFatalError("32-bit Release_CompareAndSwap");
  return 0;
}

inline void NoBarrier_Store(volatile Atomic32* ptr, Atomic32 value) {
  *ptr = value;
}

inline void Acquire_Store(volatile Atomic32* ptr, Atomic32 value) {
  NotImplementedFatalError("32-bit Acquire_Store");
}

inline void Release_Store(volatile Atomic32* ptr, Atomic32 value) {
  NotImplementedFatalError("32-bit Release_Store");
}

inline Atomic32 NoBarrier_Load(volatile const Atomic32* ptr) {
  return *ptr;
}

inline Atomic32 Acquire_Load(volatile const Atomic32* ptr) {
  Atomic32 value = *ptr;
  MemoryBarrier();
  return value;
}

inline Atomic32 Release_Load(volatile const Atomic32* ptr) {
  NotImplementedFatalError("32-bit Release_Load");
  return 0;
}


// 64-bit versions are not implemented yet.

inline Atomic64 NoBarrier_CompareAndSwap(volatile Atomic64* ptr,
                                         Atomic64 old_value,
                                         Atomic64 new_value) {
  NotImplementedFatalError("NoBarrier_CompareAndSwap");
  return 0;
}

inline Atomic64 NoBarrier_AtomicExchange(volatile Atomic64* ptr,
                                         Atomic64 new_value) {
  NotImplementedFatalError("NoBarrier_AtomicExchange");
  return 0;
}

inline Atomic64 Acquire_AtomicExchange(volatile Atomic64* ptr,
                                       Atomic64 new_value) {
  NotImplementedFatalError("64-bit Acquire_AtomicExchange");
  return 0;
}

inline Atomic64 Release_AtomicExchange(volatile Atomic64* ptr,
                                       Atomic64 new_value) {
  NotImplementedFatalError("64-bit Release_AtomicExchange");
  return 0;
}

inline void NoBarrier_Store(volatile Atomic64* ptr, Atomic64 value) {
  *ptr = value;
}

inline void Acquire_Store(volatile Atomic64* ptr, Atomic64 value) {
  NotImplementedFatalError("Acquire_Store64");
}

inline void Release_Store(volatile Atomic64* ptr, Atomic64 value) {
  NotImplementedFatalError("Release_Store");
}

inline Atomic64 NoBarrier_Load(volatile const Atomic64* ptr) {
  return *ptr;
}

inline Atomic64 Acquire_Load(volatile const Atomic64* ptr) {
  Atomic64 value = *ptr;
  MemoryBarrier();
  return value;
}

inline Atomic64 Release_Load(volatile const Atomic64* ptr) {
  NotImplementedFatalError("Atomic64 Release_Load");
  return 0;
}

inline Atomic64 Acquire_CompareAndSwap(volatile Atomic64* ptr,
                                       Atomic64 old_value,
                                       Atomic64 new_value) {
  NotImplementedFatalError("Atomic64 Acquire_CompareAndSwap");
  return 0;
}

inline Atomic64 Release_CompareAndSwap(volatile Atomic64* ptr,
                                       Atomic64 old_value,
                                       Atomic64 new_value) {
  NotImplementedFatalError("Atomic64 Release_CompareAndSwap");
  return 0;
}

}  // namespace base::subtle
}  // namespace base

#endif  // BASE_ATOMICOPS_INTERNALS_ARM_GENERIC_H_
