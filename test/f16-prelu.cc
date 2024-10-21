// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: f16-prelu
//   Generator: tools/generate-prelu-test.py


#include <gtest/gtest.h>
#include "xnnpack/common.h"
#include "xnnpack/isa-checks.h"
#include "xnnpack/prelu.h"
#include "prelu-microkernel-tester.h"
#define XNN_UKERNEL_WITH_PARAMS(arch_flags, ukernel, row_tile, channel_tile, datatype, params_type, init_params) XNN_TEST_PRELU_ROW_EQ(ukernel,arch_flags, row_tile, channel_tile, init_params);  \
XNN_TEST_PRELU_ROW_DIV(ukernel,arch_flags,  row_tile, channel_tile, init_params);                                                                                                                 \
XNN_TEST_PRELU_ROW_LT(ukernel,arch_flags,  row_tile, channel_tile, init_params);                                                                                                                  \
XNN_TEST_PRELU_ROW_GT(ukernel,arch_flags,  row_tile, channel_tile, init_params);
#include "src/f16-prelu/f16-prelu.h"
#undef XNN_UKERNEL_WITH_PARAMS
