// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
#ifndef XNN_UKERNEL_WITH_PARAMS
#define XNN_UKERNEL_WITH_PARAMS(arch_flags, ukernel, batch_tile, datatype, params_type, init_params)                   \
  XNN_UKERNEL(arch_flags, ukernel, batch_tile, datatype)
#define XNN_DEFINED_UKERNEL_WITH_PARAMS
#endif
#ifndef XNN_UKERNEL
#define XNN_UKERNEL(arch_flags, ukernel, batch_tile, datatype)                                                         \
  XNN_UKERNEL_WITH_PARAMS(arch_flags, ukernel, batch_tile, datatype, void, /*init_params=*/nullptr)
#define XNN_DEFINED_UKERNEL
#endif


XNN_UKERNEL_WITH_PARAMS(0, xnn_f16_rminmax_ukernel__scalar_u1, 1, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(0, xnn_f16_rminmax_ukernel__scalar_u2_acc2, 2, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(0, xnn_f16_rminmax_ukernel__scalar_u3_acc3, 3, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(0, xnn_f16_rminmax_ukernel__scalar_u4_acc2, 4, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(0, xnn_f16_rminmax_ukernel__scalar_u4_acc4, 4, xnn_float16, void, nullptr)

#if XNN_ENABLE_ARM_FP16_VECTOR && (XNN_ARCH_ARM || XNN_ARCH_ARM64)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm, xnn_f16_rminmax_ukernel__neonfp16arith_u8, 8, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm, xnn_f16_rminmax_ukernel__neonfp16arith_u16_acc2, 16, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm, xnn_f16_rminmax_ukernel__neonfp16arith_u24_acc3, 24, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm, xnn_f16_rminmax_ukernel__neonfp16arith_u32_acc2, 32, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm, xnn_f16_rminmax_ukernel__neonfp16arith_u32_acc4, 32, xnn_float16, void, nullptr)
#endif

#if XNN_ENABLE_AVX512FP16 && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_rminmax_ukernel__avx512fp16_u32, 32, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_rminmax_ukernel__avx512fp16_u64_acc2, 64, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_rminmax_ukernel__avx512fp16_u96_acc3, 96, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_rminmax_ukernel__avx512fp16_u128_acc2, 128, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_rminmax_ukernel__avx512fp16_u128_acc4, 128, xnn_float16, void, nullptr)
#endif

#if XNN_ENABLE_AVX512SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_rminmax_ukernel__avx512skx_u16, 16, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_rminmax_ukernel__avx512skx_u32_acc2, 32, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_rminmax_ukernel__avx512skx_u48_acc3, 48, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_rminmax_ukernel__avx512skx_u64_acc2, 64, xnn_float16, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_rminmax_ukernel__avx512skx_u64_acc4, 64, xnn_float16, void, nullptr)
#endif
