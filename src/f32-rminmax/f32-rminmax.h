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

XNN_UKERNEL_WITH_PARAMS(0, xnn_f32_rminmax_ukernel__scalar_u1, 1, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(0, xnn_f32_rminmax_ukernel__scalar_u2_acc2, 2, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(0, xnn_f32_rminmax_ukernel__scalar_u3_acc3, 3, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(0, xnn_f32_rminmax_ukernel__scalar_u4_acc2, 4, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(0, xnn_f32_rminmax_ukernel__scalar_u4_acc4, 4, float, void, nullptr)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_f32_rminmax_ukernel__neon_u4, 4, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_f32_rminmax_ukernel__neon_u8_acc2, 8, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_f32_rminmax_ukernel__neon_u12_acc3, 12, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_f32_rminmax_ukernel__neon_u16_acc2, 16, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_f32_rminmax_ukernel__neon_u16_acc4, 16, float, void, nullptr)
#endif

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__sse_u4, 4, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__sse_u8_acc2, 8, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__sse_u12_acc3, 12, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__sse_u16_acc2, 16, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__sse_u16_acc4, 16, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__avx_u8, 8, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__avx_u16_acc2, 16, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__avx_u24_acc3, 24, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__avx_u32_acc2, 32, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__avx_u32_acc4, 32, float, void, nullptr)
#endif

#if XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__avx512f_u16, 16, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__avx512f_u32_acc2, 32, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__avx512f_u48_acc3, 48, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__avx512f_u64_acc2, 64, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_f32_rminmax_ukernel__avx512f_u64_acc4, 64, float, void, nullptr)
#endif

#if XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasm, xnn_f32_rminmax_ukernel__wasm_u1, 1, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasm, xnn_f32_rminmax_ukernel__wasm_u2_acc2, 2, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasm, xnn_f32_rminmax_ukernel__wasm_u3_acc3, 3, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasm, xnn_f32_rminmax_ukernel__wasm_u4_acc2, 4, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasm, xnn_f32_rminmax_ukernel__wasm_u4_acc4, 4, float, void, nullptr)
#endif

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_f32_rminmax_ukernel__wasmsimd_minmax_u4, 4, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_f32_rminmax_ukernel__wasmsimd_minmax_u8_acc2, 8, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_f32_rminmax_ukernel__wasmsimd_minmax_u12_acc3, 12, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_f32_rminmax_ukernel__wasmsimd_minmax_u16_acc2, 16, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_f32_rminmax_ukernel__wasmsimd_minmax_u16_acc4, 16, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_f32_rminmax_ukernel__wasmsimd_pminmax_u4, 4, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_f32_rminmax_ukernel__wasmsimd_pminmax_u8_acc2, 8, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_f32_rminmax_ukernel__wasmsimd_pminmax_u12_acc3, 12, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_f32_rminmax_ukernel__wasmsimd_pminmax_u16_acc2, 16, float, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_f32_rminmax_ukernel__wasmsimd_pminmax_u16_acc4, 16, float, void, nullptr)
#endif

#if XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV
#endif
