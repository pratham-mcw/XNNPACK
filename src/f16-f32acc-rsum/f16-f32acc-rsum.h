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

#if XNN_ENABLE_ARM_FP16_VECTOR && (XNN_ARCH_ARM || XNN_ARCH_ARM64)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm, xnn_f16_f32acc_rsum_ukernel__neonfp16arith_u4, 4, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm, xnn_f16_f32acc_rsum_ukernel__neonfp16arith_u8, 8, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm, xnn_f16_f32acc_rsum_ukernel__neonfp16arith_u16_acc2, 16, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm, xnn_f16_f32acc_rsum_ukernel__neonfp16arith_u24_acc3, 24, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm, xnn_f16_f32acc_rsum_ukernel__neonfp16arith_u32_acc2, 32, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm, xnn_f16_f32acc_rsum_ukernel__neonfp16arith_u32_acc4, 32, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
#endif

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_f32acc_rsum_ukernel__f16c_u8, 32, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_f32acc_rsum_ukernel__f16c_u16_acc2, 16, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_f32acc_rsum_ukernel__f16c_u24_acc3, 24, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_f32acc_rsum_ukernel__f16c_u32_acc2, 32, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_f32acc_rsum_ukernel__f16c_u32_acc4, 32, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
#endif

#if XNN_ENABLE_AVX512SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_f32acc_rsum_ukernel__avx512skx_u16, 16, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_f32acc_rsum_ukernel__avx512skx_u32_acc2, 32, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_f32acc_rsum_ukernel__avx512skx_u48_acc3, 48, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_f32acc_rsum_ukernel__avx512skx_u64_acc2, 64, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_f32acc_rsum_ukernel__avx512skx_u64_acc4, 64, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f16_f32acc_rsum_ukernel__avx512skx_u128_acc4, 128, float, struct xnn_f16_f32acc_scale_params, xnn_init_f16_f32acc_scale_scalar_params)
#endif