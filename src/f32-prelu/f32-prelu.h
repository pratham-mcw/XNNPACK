// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
#ifndef XNN_UKERNEL_WITH_PARAMS
#define XNN_UKERNEL_WITH_PARAMS(arch_flags, ukernel, row_tile, channel_tile, datatype, params_type, init_params) \
    XNN_UKERNEL(arch_flags, ukernel, element_tile, datatype)
#define XNN_DEFINED_UKERNEL_WITH_PARAMS
#endif

#ifndef XNN_UKERNEL
#define XNN_UKERNEL(arch_flags, ukernel, row_tile, channel_tile,  datatype) \
    XNN_UKERNEL_WITH_PARAMS(arch_flags, ukernel, row_tile, channel_tile,  datatype, void, /*init_params=*/nullptr)
#define XNN_DEFINED_UKERNEL
#endif

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_prelu_ukernel__sse_2x4, 2, 4, float, struct xnn_f32_default_params, ((xnn_f32_prelu_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx2, xnn_f32_raddextexp_ukernel__avx2_p5_u64_acc2, 4,  float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx2, xnn_f32_raddextexp_ukernel__avx2_p5_u64_acc4, 4,  float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx2, xnn_f32_raddextexp_ukernel__avx2_p5_u72, 8,  float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx2, xnn_f32_raddextexp_ukernel__avx2_p5_u72_acc3, 8,  float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx2, xnn_f32_raddextexp_ukernel__avx2_p5_u80, 8,  float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx2, xnn_f32_raddextexp_ukernel__avx2_p5_u80_acc2, 8,  float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx2, xnn_f32_raddextexp_ukernel__avx2_p5_u80_acc5, 8,  float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx2, xnn_f32_raddextexp_ukernel__avx2_p5_u96, 8,  float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx2, xnn_f32_raddextexp_ukernel__avx2_p5_u96_acc2, 8,  float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx2, xnn_f32_raddextexp_ukernel__avx2_p5_u96_acc3, 8,  float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx2, xnn_f32_raddextexp_ukernel__avx2_p5_u96_acc6, 8,  float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// #endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

// #if XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx512f, xnn_f32_raddextexp_ukernel__avx512f_p5_scalef_u128, 128, float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx512f, xnn_f32_raddextexp_ukernel__avx512f_p5_scalef_u128_acc2, 128, float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx512f, xnn_f32_raddextexp_ukernel__avx512f_p5_scalef_u128_acc4, 128, float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx512f, xnn_f32_raddextexp_ukernel__avx512f_p5_scalef_u144, 144, float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx512f, xnn_f32_raddextexp_ukernel__avx512f_p5_scalef_u144_acc3, 144, float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx512f, xnn_f32_raddextexp_ukernel__avx512f_p5_scalef_u160, 160, float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx512f, xnn_f32_raddextexp_ukernel__avx512f_p5_scalef_u160_acc2, 160, float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx512f, xnn_f32_raddextexp_ukernel__avx512f_p5_scalef_u160_acc5, 160, float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx512f, xnn_f32_raddextexp_ukernel__avx512f_p5_scalef_u192, 192, float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx512f, xnn_f32_raddextexp_ukernel__avx512f_p5_scalef_u192_acc2, 192, float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx512f, xnn_f32_raddextexp_ukernel__avx512f_p5_scalef_u192_acc3, 192, float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_avx512f, xnn_f32_raddextexp_ukernel__avx512f_p5_scalef_u192_acc6, 192, float, struct xnn_f32_default_params, ((xnn_f32_raddextexp_ukernel_fn) NULL))
// #endif  // XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)

// #ifdef XNN_DEFINED_UKERNEL_WITH_PARAMS
// #undef XNN_DEFINED_UKERNEL_WITH_PARAMS
// #undef XNN_UKERNEL_WITH_PARAMS
// #endif

// #ifdef XNN_DEFINED_UKERNEL
// #undef XNN_DEFINED_UKERNEL
// #undef XNN_UKERNEL
#endif