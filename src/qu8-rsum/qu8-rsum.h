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

XNN_UKERNEL_WITH_PARAMS(0, xnn_qu8_rsum_ukernel__scalar_u1, 1, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(0, xnn_qu8_rsum_ukernel__scalar_u2, 2, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(0, xnn_qu8_rsum_ukernel__scalar_u4, 4, int8_t, void, nullptr)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_qu8_rsum_ukernel__neon_u16, 16, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_qu8_rsum_ukernel__neon_u32_acc2, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_qu8_rsum_ukernel__neon_u64_acc2, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_qu8_rsum_ukernel__neon_u64_acc4, 64, int8_t, void, nullptr)
#endif

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qu8_rsum_ukernel__sse2_u16, 16, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qu8_rsum_ukernel__sse2_u32_acc2, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qu8_rsum_ukernel__sse2_u64_acc2, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qu8_rsum_ukernel__sse2_u64_acc4, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qu8_rsum_ukernel__avx2_u32, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qu8_rsum_ukernel__avx2_u64_acc2, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qu8_rsum_ukernel__avx2_u128_acc2, 128, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qu8_rsum_ukernel__avx2_u128_acc4, 128, int8_t, void, nullptr)
#endif

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_qs8_rsum_ukernel__wasmsimd_u8, 8, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_qs8_rsum_ukernel__wasmsimd_u16_acc2, 16, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_qs8_rsum_ukernel__wasmsimd_u32_acc2, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_qs8_rsum_ukernel__wasmsimd_u32_acc4, 32, int8_t, void, nullptr)
#endif
