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

XNN_UKERNEL_WITH_PARAMS(0, xnn_qs8_rsum_ukernel__scalar_u1, 1, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(0, xnn_qs8_rsum_ukernel__scalar_u2, 2, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(0, xnn_qs8_rsum_ukernel__scalar_u4, 4, int8_t, void, nullptr)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_qs8_rsum_ukernel__neon_u16, 16, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_qs8_rsum_ukernel__neon_u32_acc2, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_qs8_rsum_ukernel__neon_u64_acc2, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_qs8_rsum_ukernel__neon_u64_acc4, 64, int8_t, void, nullptr)
#endif

#if XNN_ENABLE_ARM_DOTPROD && (XNN_ARCH_ARM || XNN_ARCH_ARM64)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_qs8_rsum_ukernel__neondot_u16, 16, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_qs8_rsum_ukernel__neondot_u32_acc2, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_qs8_rsum_ukernel__neondot_u64_acc2, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm64, xnn_qs8_rsum_ukernel__neondot_u64_acc4, 64, int8_t, void, nullptr)
#endif

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__ssse3_u16, 16, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__ssse3_u32_acc2, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__ssse3_u64_acc2, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__ssse3_u64_acc4, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx2_u32, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx2_u64_acc2, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx2_u128_acc2, 128, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx2_u128_acc4, 128, int8_t, void, nullptr)
#endif

#if XNN_ENABLE_AVXVNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avxvnni_u32, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avxvnni_u64_acc2, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avxvnni_u128_acc2, 128, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avxvnni_u128_acc4, 128, int8_t, void, nullptr)
#endif

#if XNN_ENABLE_AVX256VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx256vnni_u32, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx256vnni_u64_acc2, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx256vnni_u128_acc2, 128, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx256vnni_u128_acc4, 128, int8_t, void, nullptr)
#endif

#if XNN_ENABLE_AVX256SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx256skx_u32, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx256skx_u64_acc2, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx256skx_u128_acc2, 128, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx256skx_u128_acc4, 128, int8_t, void, nullptr)
#endif

#if XNN_ENABLE_AVX512SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx512skx_u64, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx512skx_u128_acc2, 128, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx512skx_u256_acc2, 256, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx512skx_u256_acc4, 256, int8_t, void, nullptr)
#endif

#if XNN_ENABLE_AVX512VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx512vnni_u64, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx512vnni_u128_acc2, 128, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx512vnni_u256_acc2, 256, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86, xnn_qs8_rsum_ukernel__avx512vnni_u256_acc4, 256, int8_t, void, nullptr)
#endif

#if XNN_ARCH_WASMRELAXEDSIMD
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u16, 16, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u32_acc2, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc2, 64, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc4, 64, int8_t, void, nullptr)
#endif

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_qs8_rsum_ukernel__wasmsimd_u8, 8, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_qs8_rsum_ukernel__wasmsimd_u16_acc2, 16, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_qs8_rsum_ukernel__wasmsimd_u32_acc2, 32, int8_t, void, nullptr)
XNN_UKERNEL_WITH_PARAMS(xnn_arch_wasmsimd, xnn_qs8_rsum_ukernel__wasmsimd_u32_acc4, 32, int8_t, void, nullptr)
#endif
