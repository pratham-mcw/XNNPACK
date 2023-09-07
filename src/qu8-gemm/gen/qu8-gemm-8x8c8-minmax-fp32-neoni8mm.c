// Auto-generated file. Do not edit!
//   Template: src/qu8-gemm/c8-neoni8mm.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <arm_neon.h>

#include <xnnpack/gemm.h>
#include <xnnpack/intrinsics-polyfill.h>
#include <xnnpack/math.h>


void xnn_qu8_gemm_minmax_fp32_ukernel_8x8c8__neoni8mm(
    size_t mr,
    size_t nc,
    size_t kc,
    const uint8_t* restrict a,
    size_t a_stride,
    const void* restrict w,
    uint8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const union xnn_qu8_conv_minmax_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(mr != 0);
  assert(mr <= 8);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(uint8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  kc = round_up_po2(kc, 8 * sizeof(uint8_t));
  const uint8_t* a0 = a;
  uint8_t* c0 = c;
  const uint8_t* a1 = (const uint8_t*) ((uintptr_t) a0 + a_stride);
  uint8_t* c1 = (uint8_t*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    a1 = a0;
    c1 = c0;
  }
  const uint8_t* a2 = (const uint8_t*) ((uintptr_t) a1 + a_stride);
  uint8_t* c2 = (uint8_t*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    a2 = a1;
    c2 = c1;
  }
  const uint8_t* a3 = (const uint8_t*) ((uintptr_t) a2 + a_stride);
  uint8_t* c3 = (uint8_t*) ((uintptr_t) c2 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 4) {
    a3 = a2;
    c3 = c2;
  }
  const uint8_t* a4 = (const uint8_t*) ((uintptr_t) a3 + a_stride);
  uint8_t* c4 = (uint8_t*) ((uintptr_t) c3 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 4) {
    a4 = a3;
    c4 = c3;
  }
  const uint8_t* a5 = (const uint8_t*) ((uintptr_t) a4 + a_stride);
  uint8_t* c5 = (uint8_t*) ((uintptr_t) c4 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 6) {
    a5 = a4;
    c5 = c4;
  }
  const uint8_t* a6 = (const uint8_t*) ((uintptr_t) a5 + a_stride);
  uint8_t* c6 = (uint8_t*) ((uintptr_t) c5 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 6) {
    a6 = a5;
    c6 = c5;
  }
  const uint8_t* a7 = (const uint8_t*) ((uintptr_t) a6 + a_stride);
  uint8_t* c7 = (uint8_t*) ((uintptr_t) c6 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 8) {
    a7 = a6;
    c7 = c6;
  }

  const uint8x16_t vkernel_zero_point = vreinterpretq_u8_u32(vld1q_dup_u32((const void*) params->fp32_neonv8.kernel_zero_point));

  // Loop over groups of 8 columns.
  do {
    // Initialize accumulators with bias. 8 bias values are loaded from the
    // weight matrix, at the start of the group of 8 columns.
    const uint64x2x2_t vbias01x0123 = vld2q_dup_u64(w); w = (const int32_t*) w + 4;
    const uint64x2x2_t vbias01x4567 = vld2q_dup_u64(w); w = (const int32_t*) w + 4;
    uint32x4_t vpacc01x01 = vreinterpretq_u32_u64(vbias01x0123.val[0]);
    uint32x4_t vpacc01x23 = vreinterpretq_u32_u64(vbias01x0123.val[1]);
    uint32x4_t vpacc01x45 = vreinterpretq_u32_u64(vbias01x4567.val[0]);
    uint32x4_t vpacc01x67 = vreinterpretq_u32_u64(vbias01x4567.val[1]);
    uint32x4_t vpacc23x01 = vreinterpretq_u32_u64(vbias01x0123.val[0]);
    uint32x4_t vpacc23x23 = vreinterpretq_u32_u64(vbias01x0123.val[1]);
    uint32x4_t vpacc23x45 = vreinterpretq_u32_u64(vbias01x4567.val[0]);
    uint32x4_t vpacc23x67 = vreinterpretq_u32_u64(vbias01x4567.val[1]);
    uint32x4_t vpacc45x01 = vreinterpretq_u32_u64(vbias01x0123.val[0]);
    uint32x4_t vpacc45x23 = vreinterpretq_u32_u64(vbias01x0123.val[1]);
    uint32x4_t vpacc45x45 = vreinterpretq_u32_u64(vbias01x4567.val[0]);
    uint32x4_t vpacc45x67 = vreinterpretq_u32_u64(vbias01x4567.val[1]);
    uint32x4_t vpacc67x01 = vreinterpretq_u32_u64(vbias01x0123.val[0]);
    uint32x4_t vpacc67x23 = vreinterpretq_u32_u64(vbias01x0123.val[1]);
    uint32x4_t vpacc67x45 = vreinterpretq_u32_u64(vbias01x4567.val[0]);
    uint32x4_t vpacc67x67 = vreinterpretq_u32_u64(vbias01x4567.val[1]);
    uint32x4_t vnacc01 = vmovq_n_u32(0);
    uint32x4_t vnacc23 = vmovq_n_u32(0);
    uint32x4_t vnacc45 = vmovq_n_u32(0);
    uint32x4_t vnacc67 = vmovq_n_u32(0);

    uint64x2x2_t va01x0123456789ABCDEF;
    va01x0123456789ABCDEF.val[0] = vdupq_n_u64(0);
    va01x0123456789ABCDEF.val[1] = vdupq_n_u64(0);
    uint64x2x2_t va23x0123456789ABCDEF;
    va23x0123456789ABCDEF.val[0] = vdupq_n_u64(0);
    va23x0123456789ABCDEF.val[1] = vdupq_n_u64(0);
    uint64x2x2_t va45x0123456789ABCDEF;
    va45x0123456789ABCDEF.val[0] = vdupq_n_u64(0);
    va45x0123456789ABCDEF.val[1] = vdupq_n_u64(0);
    uint64x2x2_t va67x0123456789ABCDEF;
    va67x0123456789ABCDEF.val[0] = vdupq_n_u64(0);
    va67x0123456789ABCDEF.val[1] = vdupq_n_u64(0);

    // Inner accumulation loop along the 8 columns.
    size_t k = kc;
    // 2x partial unrolled loop to load 8 bytes at a time.
    while (k >= 16 * sizeof(uint8_t)) {
      // Load a 8x16 block of activations.
      va01x0123456789ABCDEF = vld2q_lane_u64((const void*) a0, va01x0123456789ABCDEF, 0); a0 += 16;
      va23x0123456789ABCDEF = vld2q_lane_u64((const void*) a2, va23x0123456789ABCDEF, 0); a2 += 16;
      va45x0123456789ABCDEF = vld2q_lane_u64((const void*) a4, va45x0123456789ABCDEF, 0); a4 += 16;
      va67x0123456789ABCDEF = vld2q_lane_u64((const void*) a6, va67x0123456789ABCDEF, 0); a6 += 16;
      va01x0123456789ABCDEF = vld2q_lane_u64((const void*) a1, va01x0123456789ABCDEF, 1); a1 += 16;
      va23x0123456789ABCDEF = vld2q_lane_u64((const void*) a3, va23x0123456789ABCDEF, 1); a3 += 16;
      va45x0123456789ABCDEF = vld2q_lane_u64((const void*) a5, va45x0123456789ABCDEF, 1); a5 += 16;
      va67x0123456789ABCDEF = vld2q_lane_u64((const void*) a7, va67x0123456789ABCDEF, 1); a7 += 16;

      // Load a 16x8 block of weights.
      const uint8x16_t vb01x01234567 = vld1q_u8(w); w = (const uint8_t*) w + 16;
      const uint8x16_t vb23x01234567 = vld1q_u8(w); w = (const uint8_t*) w + 16;
      const uint8x16_t vb45x01234567 = vld1q_u8(w); w = (const uint8_t*) w + 16;
      const uint8x16_t vb67x01234567 = vld1q_u8(w); w = (const uint8_t*) w + 16;
      const uint8x16_t vb01x89ABCDEF = vld1q_u8(w); w = (const uint8_t*) w + 16;
      const uint8x16_t vb23x89ABCDEF = vld1q_u8(w); w = (const uint8_t*) w + 16;
      const uint8x16_t vb45x89ABCDEF = vld1q_u8(w); w = (const uint8_t*) w + 16;
      const uint8x16_t vb67x89ABCDEF = vld1q_u8(w); w = (const uint8_t*) w + 16;

      // Multiply-accumulate: 8x16 * 16x8 --> 8x8.
      vnacc01 = vmmlaq_u32(vnacc01, vkernel_zero_point, vreinterpretq_u8_u64(va01x0123456789ABCDEF.val[0]));
      vpacc01x01 = vmmlaq_u32(vpacc01x01, vreinterpretq_u8_u64(va01x0123456789ABCDEF.val[0]), vb01x01234567);
      vpacc01x23 = vmmlaq_u32(vpacc01x23, vreinterpretq_u8_u64(va01x0123456789ABCDEF.val[0]), vb23x01234567);
      vpacc01x45 = vmmlaq_u32(vpacc01x45, vreinterpretq_u8_u64(va01x0123456789ABCDEF.val[0]), vb45x01234567);
      vpacc01x67 = vmmlaq_u32(vpacc01x67, vreinterpretq_u8_u64(va01x0123456789ABCDEF.val[0]), vb67x01234567);
      vnacc23 = vmmlaq_u32(vnacc23, vkernel_zero_point, vreinterpretq_u8_u64(va23x0123456789ABCDEF.val[0]));
      vpacc23x01 = vmmlaq_u32(vpacc23x01, vreinterpretq_u8_u64(va23x0123456789ABCDEF.val[0]), vb01x01234567);
      vpacc23x23 = vmmlaq_u32(vpacc23x23, vreinterpretq_u8_u64(va23x0123456789ABCDEF.val[0]), vb23x01234567);
      vpacc23x45 = vmmlaq_u32(vpacc23x45, vreinterpretq_u8_u64(va23x0123456789ABCDEF.val[0]), vb45x01234567);
      vpacc23x67 = vmmlaq_u32(vpacc23x67, vreinterpretq_u8_u64(va23x0123456789ABCDEF.val[0]), vb67x01234567);
      vnacc45 = vmmlaq_u32(vnacc45, vkernel_zero_point, vreinterpretq_u8_u64(va45x0123456789ABCDEF.val[0]));
      vpacc45x01 = vmmlaq_u32(vpacc45x01, vreinterpretq_u8_u64(va45x0123456789ABCDEF.val[0]), vb01x01234567);
      vpacc45x23 = vmmlaq_u32(vpacc45x23, vreinterpretq_u8_u64(va45x0123456789ABCDEF.val[0]), vb23x01234567);
      vpacc45x45 = vmmlaq_u32(vpacc45x45, vreinterpretq_u8_u64(va45x0123456789ABCDEF.val[0]), vb45x01234567);
      vpacc45x67 = vmmlaq_u32(vpacc45x67, vreinterpretq_u8_u64(va45x0123456789ABCDEF.val[0]), vb67x01234567);
      vnacc67 = vmmlaq_u32(vnacc67, vkernel_zero_point, vreinterpretq_u8_u64(va67x0123456789ABCDEF.val[0]));
      vpacc67x01 = vmmlaq_u32(vpacc67x01, vreinterpretq_u8_u64(va67x0123456789ABCDEF.val[0]), vb01x01234567);
      vpacc67x23 = vmmlaq_u32(vpacc67x23, vreinterpretq_u8_u64(va67x0123456789ABCDEF.val[0]), vb23x01234567);
      vpacc67x45 = vmmlaq_u32(vpacc67x45, vreinterpretq_u8_u64(va67x0123456789ABCDEF.val[0]), vb45x01234567);
      vpacc67x67 = vmmlaq_u32(vpacc67x67, vreinterpretq_u8_u64(va67x0123456789ABCDEF.val[0]), vb67x01234567);
      vnacc01 = vmmlaq_u32(vnacc01, vkernel_zero_point, vreinterpretq_u8_u64(va01x0123456789ABCDEF.val[1]));
      vpacc01x01 = vmmlaq_u32(vpacc01x01, vreinterpretq_u8_u64(va01x0123456789ABCDEF.val[1]), vb01x89ABCDEF);
      vpacc01x23 = vmmlaq_u32(vpacc01x23, vreinterpretq_u8_u64(va01x0123456789ABCDEF.val[1]), vb23x89ABCDEF);
      vpacc01x45 = vmmlaq_u32(vpacc01x45, vreinterpretq_u8_u64(va01x0123456789ABCDEF.val[1]), vb45x89ABCDEF);
      vpacc01x67 = vmmlaq_u32(vpacc01x67, vreinterpretq_u8_u64(va01x0123456789ABCDEF.val[1]), vb67x89ABCDEF);
      vnacc23 = vmmlaq_u32(vnacc23, vkernel_zero_point, vreinterpretq_u8_u64(va23x0123456789ABCDEF.val[1]));
      vpacc23x01 = vmmlaq_u32(vpacc23x01, vreinterpretq_u8_u64(va23x0123456789ABCDEF.val[1]), vb01x89ABCDEF);
      vpacc23x23 = vmmlaq_u32(vpacc23x23, vreinterpretq_u8_u64(va23x0123456789ABCDEF.val[1]), vb23x89ABCDEF);
      vpacc23x45 = vmmlaq_u32(vpacc23x45, vreinterpretq_u8_u64(va23x0123456789ABCDEF.val[1]), vb45x89ABCDEF);
      vpacc23x67 = vmmlaq_u32(vpacc23x67, vreinterpretq_u8_u64(va23x0123456789ABCDEF.val[1]), vb67x89ABCDEF);
      vnacc45 = vmmlaq_u32(vnacc45, vkernel_zero_point, vreinterpretq_u8_u64(va45x0123456789ABCDEF.val[1]));
      vpacc45x01 = vmmlaq_u32(vpacc45x01, vreinterpretq_u8_u64(va45x0123456789ABCDEF.val[1]), vb01x89ABCDEF);
      vpacc45x23 = vmmlaq_u32(vpacc45x23, vreinterpretq_u8_u64(va45x0123456789ABCDEF.val[1]), vb23x89ABCDEF);
      vpacc45x45 = vmmlaq_u32(vpacc45x45, vreinterpretq_u8_u64(va45x0123456789ABCDEF.val[1]), vb45x89ABCDEF);
      vpacc45x67 = vmmlaq_u32(vpacc45x67, vreinterpretq_u8_u64(va45x0123456789ABCDEF.val[1]), vb67x89ABCDEF);
      vnacc67 = vmmlaq_u32(vnacc67, vkernel_zero_point, vreinterpretq_u8_u64(va67x0123456789ABCDEF.val[1]));
      vpacc67x01 = vmmlaq_u32(vpacc67x01, vreinterpretq_u8_u64(va67x0123456789ABCDEF.val[1]), vb01x89ABCDEF);
      vpacc67x23 = vmmlaq_u32(vpacc67x23, vreinterpretq_u8_u64(va67x0123456789ABCDEF.val[1]), vb23x89ABCDEF);
      vpacc67x45 = vmmlaq_u32(vpacc67x45, vreinterpretq_u8_u64(va67x0123456789ABCDEF.val[1]), vb45x89ABCDEF);
      vpacc67x67 = vmmlaq_u32(vpacc67x67, vreinterpretq_u8_u64(va67x0123456789ABCDEF.val[1]), vb67x89ABCDEF);

      k -= 16 * sizeof(uint8_t);
    }
    // Handle up to 8 final positions of `k`
    if XNN_UNLIKELY(k != 0) {
      // Load a 8x8 block of activations.
      uint64x2_t va01x0123456789ABCDEF = vld1q_dup_u64((const void*) a0); a0 += 8;
      uint64x2_t va23x0123456789ABCDEF = vld1q_dup_u64((const void*) a2); a2 += 8;
      uint64x2_t va45x0123456789ABCDEF = vld1q_dup_u64((const void*) a4); a4 += 8;
      uint64x2_t va67x0123456789ABCDEF = vld1q_dup_u64((const void*) a6); a6 += 8;
      va01x0123456789ABCDEF = vld1q_lane_u64((const void*) a1, va01x0123456789ABCDEF, 1); a1 += 8;
      va23x0123456789ABCDEF = vld1q_lane_u64((const void*) a3, va23x0123456789ABCDEF, 1); a3 += 8;
      va45x0123456789ABCDEF = vld1q_lane_u64((const void*) a5, va45x0123456789ABCDEF, 1); a5 += 8;
      va67x0123456789ABCDEF = vld1q_lane_u64((const void*) a7, va67x0123456789ABCDEF, 1); a7 += 8;

      // Load a 16x8 block of weights.
      const uint8x16_t vb01x01234567 = vld1q_u8(w); w = (const uint8_t*) w + 16;
      const uint8x16_t vb23x01234567 = vld1q_u8(w); w = (const uint8_t*) w + 16;
      const uint8x16_t vb45x01234567 = vld1q_u8(w); w = (const uint8_t*) w + 16;
      const uint8x16_t vb67x01234567 = vld1q_u8(w); w = (const uint8_t*) w + 16;

      // Multiply-accumulate: 8x8 * 8x8 --> 8x8.
      vnacc01 = vmmlaq_u32(vnacc01, vkernel_zero_point, vreinterpretq_u8_u64(va01x0123456789ABCDEF));
      vpacc01x01 = vmmlaq_u32(vpacc01x01, vreinterpretq_u8_u64(va01x0123456789ABCDEF), vb01x01234567);
      vpacc01x23 = vmmlaq_u32(vpacc01x23, vreinterpretq_u8_u64(va01x0123456789ABCDEF), vb23x01234567);
      vpacc01x45 = vmmlaq_u32(vpacc01x45, vreinterpretq_u8_u64(va01x0123456789ABCDEF), vb45x01234567);
      vpacc01x67 = vmmlaq_u32(vpacc01x67, vreinterpretq_u8_u64(va01x0123456789ABCDEF), vb67x01234567);
      vnacc23 = vmmlaq_u32(vnacc23, vkernel_zero_point, vreinterpretq_u8_u64(va23x0123456789ABCDEF));
      vpacc23x01 = vmmlaq_u32(vpacc23x01, vreinterpretq_u8_u64(va23x0123456789ABCDEF), vb01x01234567);
      vpacc23x23 = vmmlaq_u32(vpacc23x23, vreinterpretq_u8_u64(va23x0123456789ABCDEF), vb23x01234567);
      vpacc23x45 = vmmlaq_u32(vpacc23x45, vreinterpretq_u8_u64(va23x0123456789ABCDEF), vb45x01234567);
      vpacc23x67 = vmmlaq_u32(vpacc23x67, vreinterpretq_u8_u64(va23x0123456789ABCDEF), vb67x01234567);
      vnacc45 = vmmlaq_u32(vnacc45, vkernel_zero_point, vreinterpretq_u8_u64(va45x0123456789ABCDEF));
      vpacc45x01 = vmmlaq_u32(vpacc45x01, vreinterpretq_u8_u64(va45x0123456789ABCDEF), vb01x01234567);
      vpacc45x23 = vmmlaq_u32(vpacc45x23, vreinterpretq_u8_u64(va45x0123456789ABCDEF), vb23x01234567);
      vpacc45x45 = vmmlaq_u32(vpacc45x45, vreinterpretq_u8_u64(va45x0123456789ABCDEF), vb45x01234567);
      vpacc45x67 = vmmlaq_u32(vpacc45x67, vreinterpretq_u8_u64(va45x0123456789ABCDEF), vb67x01234567);
      vnacc67 = vmmlaq_u32(vnacc67, vkernel_zero_point, vreinterpretq_u8_u64(va67x0123456789ABCDEF));
      vpacc67x01 = vmmlaq_u32(vpacc67x01, vreinterpretq_u8_u64(va67x0123456789ABCDEF), vb01x01234567);
      vpacc67x23 = vmmlaq_u32(vpacc67x23, vreinterpretq_u8_u64(va67x0123456789ABCDEF), vb23x01234567);
      vpacc67x45 = vmmlaq_u32(vpacc67x45, vreinterpretq_u8_u64(va67x0123456789ABCDEF), vb45x01234567);
      vpacc67x67 = vmmlaq_u32(vpacc67x67, vreinterpretq_u8_u64(va67x0123456789ABCDEF), vb67x01234567);
    }

    // Subtract zero point from accumulators.
    const uint32x4_t vnacc01x01 = vzip1q_u32(vnacc01, vnacc01);
    int32x4_t vacc01x01 = vreinterpretq_s32_u32(vsubq_u32(vpacc01x01, vnacc01x01));
    int32x4_t vacc01x23 = vreinterpretq_s32_u32(vsubq_u32(vpacc01x23, vnacc01x01));
    int32x4_t vacc01x45 = vreinterpretq_s32_u32(vsubq_u32(vpacc01x45, vnacc01x01));
    int32x4_t vacc01x67 = vreinterpretq_s32_u32(vsubq_u32(vpacc01x67, vnacc01x01));
    const uint32x4_t vnacc23x01 = vzip1q_u32(vnacc23, vnacc23);
    int32x4_t vacc23x01 = vreinterpretq_s32_u32(vsubq_u32(vpacc23x01, vnacc23x01));
    int32x4_t vacc23x23 = vreinterpretq_s32_u32(vsubq_u32(vpacc23x23, vnacc23x01));
    int32x4_t vacc23x45 = vreinterpretq_s32_u32(vsubq_u32(vpacc23x45, vnacc23x01));
    int32x4_t vacc23x67 = vreinterpretq_s32_u32(vsubq_u32(vpacc23x67, vnacc23x01));
    const uint32x4_t vnacc45x01 = vzip1q_u32(vnacc45, vnacc45);
    int32x4_t vacc45x01 = vreinterpretq_s32_u32(vsubq_u32(vpacc45x01, vnacc45x01));
    int32x4_t vacc45x23 = vreinterpretq_s32_u32(vsubq_u32(vpacc45x23, vnacc45x01));
    int32x4_t vacc45x45 = vreinterpretq_s32_u32(vsubq_u32(vpacc45x45, vnacc45x01));
    int32x4_t vacc45x67 = vreinterpretq_s32_u32(vsubq_u32(vpacc45x67, vnacc45x01));
    const uint32x4_t vnacc67x01 = vzip1q_u32(vnacc67, vnacc67);
    int32x4_t vacc67x01 = vreinterpretq_s32_u32(vsubq_u32(vpacc67x01, vnacc67x01));
    int32x4_t vacc67x23 = vreinterpretq_s32_u32(vsubq_u32(vpacc67x23, vnacc67x01));
    int32x4_t vacc67x45 = vreinterpretq_s32_u32(vsubq_u32(vpacc67x45, vnacc67x01));
    int32x4_t vacc67x67 = vreinterpretq_s32_u32(vsubq_u32(vpacc67x67, vnacc67x01));

    int32x4_t vacc0x0123 = vreinterpretq_s32_u64(vtrn1q_u64(vreinterpretq_u64_s32(vacc01x01), vreinterpretq_u64_s32(vacc01x23)));
    int32x4_t vacc1x0123 = vreinterpretq_s32_u64(vtrn2q_u64(vreinterpretq_u64_s32(vacc01x01), vreinterpretq_u64_s32(vacc01x23)));
    int32x4_t vacc0x4567 = vreinterpretq_s32_u64(vtrn1q_u64(vreinterpretq_u64_s32(vacc01x45), vreinterpretq_u64_s32(vacc01x67)));
    int32x4_t vacc1x4567 = vreinterpretq_s32_u64(vtrn2q_u64(vreinterpretq_u64_s32(vacc01x45), vreinterpretq_u64_s32(vacc01x67)));
    int32x4_t vacc2x0123 = vreinterpretq_s32_u64(vtrn1q_u64(vreinterpretq_u64_s32(vacc23x01), vreinterpretq_u64_s32(vacc23x23)));
    int32x4_t vacc3x0123 = vreinterpretq_s32_u64(vtrn2q_u64(vreinterpretq_u64_s32(vacc23x01), vreinterpretq_u64_s32(vacc23x23)));
    int32x4_t vacc2x4567 = vreinterpretq_s32_u64(vtrn1q_u64(vreinterpretq_u64_s32(vacc23x45), vreinterpretq_u64_s32(vacc23x67)));
    int32x4_t vacc3x4567 = vreinterpretq_s32_u64(vtrn2q_u64(vreinterpretq_u64_s32(vacc23x45), vreinterpretq_u64_s32(vacc23x67)));
    int32x4_t vacc4x0123 = vreinterpretq_s32_u64(vtrn1q_u64(vreinterpretq_u64_s32(vacc45x01), vreinterpretq_u64_s32(vacc45x23)));
    int32x4_t vacc5x0123 = vreinterpretq_s32_u64(vtrn2q_u64(vreinterpretq_u64_s32(vacc45x01), vreinterpretq_u64_s32(vacc45x23)));
    int32x4_t vacc4x4567 = vreinterpretq_s32_u64(vtrn1q_u64(vreinterpretq_u64_s32(vacc45x45), vreinterpretq_u64_s32(vacc45x67)));
    int32x4_t vacc5x4567 = vreinterpretq_s32_u64(vtrn2q_u64(vreinterpretq_u64_s32(vacc45x45), vreinterpretq_u64_s32(vacc45x67)));
    int32x4_t vacc6x0123 = vreinterpretq_s32_u64(vtrn1q_u64(vreinterpretq_u64_s32(vacc67x01), vreinterpretq_u64_s32(vacc67x23)));
    int32x4_t vacc7x0123 = vreinterpretq_s32_u64(vtrn2q_u64(vreinterpretq_u64_s32(vacc67x01), vreinterpretq_u64_s32(vacc67x23)));
    int32x4_t vacc6x4567 = vreinterpretq_s32_u64(vtrn1q_u64(vreinterpretq_u64_s32(vacc67x45), vreinterpretq_u64_s32(vacc67x67)));
    int32x4_t vacc7x4567 = vreinterpretq_s32_u64(vtrn2q_u64(vreinterpretq_u64_s32(vacc67x45), vreinterpretq_u64_s32(vacc67x67)));
    float32x4_t vfpacc0x0123 = vcvtq_f32_s32(vacc0x0123);
    float32x4_t vfpacc0x4567 = vcvtq_f32_s32(vacc0x4567);
    float32x4_t vfpacc1x0123 = vcvtq_f32_s32(vacc1x0123);
    float32x4_t vfpacc1x4567 = vcvtq_f32_s32(vacc1x4567);
    float32x4_t vfpacc2x0123 = vcvtq_f32_s32(vacc2x0123);
    float32x4_t vfpacc2x4567 = vcvtq_f32_s32(vacc2x4567);
    float32x4_t vfpacc3x0123 = vcvtq_f32_s32(vacc3x0123);
    float32x4_t vfpacc3x4567 = vcvtq_f32_s32(vacc3x4567);
    float32x4_t vfpacc4x0123 = vcvtq_f32_s32(vacc4x0123);
    float32x4_t vfpacc4x4567 = vcvtq_f32_s32(vacc4x4567);
    float32x4_t vfpacc5x0123 = vcvtq_f32_s32(vacc5x0123);
    float32x4_t vfpacc5x4567 = vcvtq_f32_s32(vacc5x4567);
    float32x4_t vfpacc6x0123 = vcvtq_f32_s32(vacc6x0123);
    float32x4_t vfpacc6x4567 = vcvtq_f32_s32(vacc6x4567);
    float32x4_t vfpacc7x0123 = vcvtq_f32_s32(vacc7x0123);
    float32x4_t vfpacc7x4567 = vcvtq_f32_s32(vacc7x4567);

    const float32x4_t vscale = vld1q_dup_f32(&params->fp32_neonv8.scale);
    vfpacc0x0123 = vmulq_f32(vfpacc0x0123, vscale);
    vfpacc0x4567 = vmulq_f32(vfpacc0x4567, vscale);
    vfpacc1x0123 = vmulq_f32(vfpacc1x0123, vscale);
    vfpacc1x4567 = vmulq_f32(vfpacc1x4567, vscale);
    vfpacc2x0123 = vmulq_f32(vfpacc2x0123, vscale);
    vfpacc2x4567 = vmulq_f32(vfpacc2x4567, vscale);
    vfpacc3x0123 = vmulq_f32(vfpacc3x0123, vscale);
    vfpacc3x4567 = vmulq_f32(vfpacc3x4567, vscale);
    vfpacc4x0123 = vmulq_f32(vfpacc4x0123, vscale);
    vfpacc4x4567 = vmulq_f32(vfpacc4x4567, vscale);
    vfpacc5x0123 = vmulq_f32(vfpacc5x0123, vscale);
    vfpacc5x4567 = vmulq_f32(vfpacc5x4567, vscale);
    vfpacc6x0123 = vmulq_f32(vfpacc6x0123, vscale);
    vfpacc6x4567 = vmulq_f32(vfpacc6x4567, vscale);
    vfpacc7x0123 = vmulq_f32(vfpacc7x0123, vscale);
    vfpacc7x4567 = vmulq_f32(vfpacc7x4567, vscale);

    vacc0x0123 = vcvtnq_s32_f32(vfpacc0x0123);
    vacc0x4567 = vcvtnq_s32_f32(vfpacc0x4567);
    vacc1x0123 = vcvtnq_s32_f32(vfpacc1x0123);
    vacc1x4567 = vcvtnq_s32_f32(vfpacc1x4567);
    vacc2x0123 = vcvtnq_s32_f32(vfpacc2x0123);
    vacc2x4567 = vcvtnq_s32_f32(vfpacc2x4567);
    vacc3x0123 = vcvtnq_s32_f32(vfpacc3x0123);
    vacc3x4567 = vcvtnq_s32_f32(vfpacc3x4567);
    vacc4x0123 = vcvtnq_s32_f32(vfpacc4x0123);
    vacc4x4567 = vcvtnq_s32_f32(vfpacc4x4567);
    vacc5x0123 = vcvtnq_s32_f32(vfpacc5x0123);
    vacc5x4567 = vcvtnq_s32_f32(vfpacc5x4567);
    vacc6x0123 = vcvtnq_s32_f32(vfpacc6x0123);
    vacc6x4567 = vcvtnq_s32_f32(vfpacc6x4567);
    vacc7x0123 = vcvtnq_s32_f32(vfpacc7x0123);
    vacc7x4567 = vcvtnq_s32_f32(vfpacc7x4567);

    const int16x8_t voutput_zero_point = vld1q_dup_s16(&params->fp32_neonv8.output_zero_point);
#if XNN_ARCH_ARM64
    const int16x8_t vacc0x01234567 = vqaddq_s16(vqmovn_high_s32(vqmovn_s32(vacc0x0123), vacc0x4567), voutput_zero_point);
    const int16x8_t vacc1x01234567 = vqaddq_s16(vqmovn_high_s32(vqmovn_s32(vacc1x0123), vacc1x4567), voutput_zero_point);
    const int16x8_t vacc2x01234567 = vqaddq_s16(vqmovn_high_s32(vqmovn_s32(vacc2x0123), vacc2x4567), voutput_zero_point);
    const int16x8_t vacc3x01234567 = vqaddq_s16(vqmovn_high_s32(vqmovn_s32(vacc3x0123), vacc3x4567), voutput_zero_point);
    const int16x8_t vacc4x01234567 = vqaddq_s16(vqmovn_high_s32(vqmovn_s32(vacc4x0123), vacc4x4567), voutput_zero_point);
    const int16x8_t vacc5x01234567 = vqaddq_s16(vqmovn_high_s32(vqmovn_s32(vacc5x0123), vacc5x4567), voutput_zero_point);
    const int16x8_t vacc6x01234567 = vqaddq_s16(vqmovn_high_s32(vqmovn_s32(vacc6x0123), vacc6x4567), voutput_zero_point);
    const int16x8_t vacc7x01234567 = vqaddq_s16(vqmovn_high_s32(vqmovn_s32(vacc7x0123), vacc7x4567), voutput_zero_point);

    uint8x16_t vout0x01234567_1x01234567 = vqmovun_high_s16(vqmovun_s16(vacc0x01234567), vacc1x01234567);
    uint8x16_t vout2x01234567_3x01234567 = vqmovun_high_s16(vqmovun_s16(vacc2x01234567), vacc3x01234567);
    uint8x16_t vout4x01234567_5x01234567 = vqmovun_high_s16(vqmovun_s16(vacc4x01234567), vacc5x01234567);
    uint8x16_t vout6x01234567_7x01234567 = vqmovun_high_s16(vqmovun_s16(vacc6x01234567), vacc7x01234567);
#else
    const int16x8_t vacc0x01234567 = vqaddq_s16(vcombine_s16(vqmovn_s32(vacc0x0123), vqmovn_s32(vacc0x4567)), voutput_zero_point);
    const int16x8_t vacc1x01234567 = vqaddq_s16(vcombine_s16(vqmovn_s32(vacc1x0123), vqmovn_s32(vacc1x4567)), voutput_zero_point);
    const int16x8_t vacc2x01234567 = vqaddq_s16(vcombine_s16(vqmovn_s32(vacc2x0123), vqmovn_s32(vacc2x4567)), voutput_zero_point);
    const int16x8_t vacc3x01234567 = vqaddq_s16(vcombine_s16(vqmovn_s32(vacc3x0123), vqmovn_s32(vacc3x4567)), voutput_zero_point);
    const int16x8_t vacc4x01234567 = vqaddq_s16(vcombine_s16(vqmovn_s32(vacc4x0123), vqmovn_s32(vacc4x4567)), voutput_zero_point);
    const int16x8_t vacc5x01234567 = vqaddq_s16(vcombine_s16(vqmovn_s32(vacc5x0123), vqmovn_s32(vacc5x4567)), voutput_zero_point);
    const int16x8_t vacc6x01234567 = vqaddq_s16(vcombine_s16(vqmovn_s32(vacc6x0123), vqmovn_s32(vacc6x4567)), voutput_zero_point);
    const int16x8_t vacc7x01234567 = vqaddq_s16(vcombine_s16(vqmovn_s32(vacc7x0123), vqmovn_s32(vacc7x4567)), voutput_zero_point);

    uint8x16_t vout0x01234567_1x01234567 = vcombine_u8(vqmovun_s16(vacc0x01234567), vqmovun_s16(vacc1x01234567));
    uint8x16_t vout2x01234567_3x01234567 = vcombine_u8(vqmovun_s16(vacc2x01234567), vqmovun_s16(vacc3x01234567));
    uint8x16_t vout4x01234567_5x01234567 = vcombine_u8(vqmovun_s16(vacc4x01234567), vqmovun_s16(vacc5x01234567));
    uint8x16_t vout6x01234567_7x01234567 = vcombine_u8(vqmovun_s16(vacc6x01234567), vqmovun_s16(vacc7x01234567));
#endif
    const uint8x16_t voutput_min = vld1q_dup_u8(&params->fp32_neonv8.output_min);
    const uint8x16_t voutput_max = vld1q_dup_u8(&params->fp32_neonv8.output_max);

    vout0x01234567_1x01234567 = vmaxq_u8(vout0x01234567_1x01234567, voutput_min);
    vout2x01234567_3x01234567 = vmaxq_u8(vout2x01234567_3x01234567, voutput_min);
    vout4x01234567_5x01234567 = vmaxq_u8(vout4x01234567_5x01234567, voutput_min);
    vout6x01234567_7x01234567 = vmaxq_u8(vout6x01234567_7x01234567, voutput_min);

    vout0x01234567_1x01234567 = vminq_u8(vout0x01234567_1x01234567, voutput_max);
    vout2x01234567_3x01234567 = vminq_u8(vout2x01234567_3x01234567, voutput_max);
    vout4x01234567_5x01234567 = vminq_u8(vout4x01234567_5x01234567, voutput_max);
    vout6x01234567_7x01234567 = vminq_u8(vout6x01234567_7x01234567, voutput_max);

    if (nc >= 8) {
      vst1_u8(c0, vget_low_u8(vout0x01234567_1x01234567));
      vst1_u8(c1, vget_high_u8(vout0x01234567_1x01234567));
      vst1_u8(c2, vget_low_u8(vout2x01234567_3x01234567));
      vst1_u8(c3, vget_high_u8(vout2x01234567_3x01234567));
      vst1_u8(c4, vget_low_u8(vout4x01234567_5x01234567));
      vst1_u8(c5, vget_high_u8(vout4x01234567_5x01234567));
      vst1_u8(c6, vget_low_u8(vout6x01234567_7x01234567));
      vst1_u8(c7, vget_high_u8(vout6x01234567_7x01234567));


      c0 = (uint8_t*) ((uintptr_t) c0 + cn_stride);
      c1 = (uint8_t*) ((uintptr_t) c1 + cn_stride);
      c2 = (uint8_t*) ((uintptr_t) c2 + cn_stride);
      c3 = (uint8_t*) ((uintptr_t) c3 + cn_stride);
      c4 = (uint8_t*) ((uintptr_t) c4 + cn_stride);
      c5 = (uint8_t*) ((uintptr_t) c5 + cn_stride);
      c6 = (uint8_t*) ((uintptr_t) c6 + cn_stride);
      c7 = (uint8_t*) ((uintptr_t) c7 + cn_stride);

      a0 = (const uint8_t*) ((uintptr_t) a0 - kc);
      a1 = (const uint8_t*) ((uintptr_t) a1 - kc);
      a2 = (const uint8_t*) ((uintptr_t) a2 - kc);
      a3 = (const uint8_t*) ((uintptr_t) a3 - kc);
      a4 = (const uint8_t*) ((uintptr_t) a4 - kc);
      a5 = (const uint8_t*) ((uintptr_t) a5 - kc);
      a6 = (const uint8_t*) ((uintptr_t) a6 - kc);
      a7 = (const uint8_t*) ((uintptr_t) a7 - kc);

      nc -= 8;
    } else {
      if (nc & 4) {
        vst1q_lane_u32((void*) c0, vreinterpretq_u32_u8(vout0x01234567_1x01234567), 0); c0 += 4;
        vst1q_lane_u32((void*) c1, vreinterpretq_u32_u8(vout0x01234567_1x01234567), 2); c1 += 4;
        vst1q_lane_u32((void*) c2, vreinterpretq_u32_u8(vout2x01234567_3x01234567), 0); c2 += 4;
        vst1q_lane_u32((void*) c3, vreinterpretq_u32_u8(vout2x01234567_3x01234567), 2); c3 += 4;
        vst1q_lane_u32((void*) c4, vreinterpretq_u32_u8(vout4x01234567_5x01234567), 0); c4 += 4;
        vst1q_lane_u32((void*) c5, vreinterpretq_u32_u8(vout4x01234567_5x01234567), 2); c5 += 4;
        vst1q_lane_u32((void*) c6, vreinterpretq_u32_u8(vout6x01234567_7x01234567), 0); c6 += 4;
        vst1q_lane_u32((void*) c7, vreinterpretq_u32_u8(vout6x01234567_7x01234567), 2); c7 += 4;
        vout0x01234567_1x01234567 = vextq_u8(vout0x01234567_1x01234567, vout0x01234567_1x01234567, 4);
        vout2x01234567_3x01234567 = vextq_u8(vout2x01234567_3x01234567, vout2x01234567_3x01234567, 4);
        vout4x01234567_5x01234567 = vextq_u8(vout4x01234567_5x01234567, vout4x01234567_5x01234567, 4);
        vout6x01234567_7x01234567 = vextq_u8(vout6x01234567_7x01234567, vout6x01234567_7x01234567, 4);
      }
      if (nc & 2) {
        vst1q_lane_u16((void*) c0, vreinterpretq_u16_u8(vout0x01234567_1x01234567), 0); c0 += 2;
        vst1q_lane_u16((void*) c1, vreinterpretq_u16_u8(vout0x01234567_1x01234567), 4); c1 += 2;
        vst1q_lane_u16((void*) c2, vreinterpretq_u16_u8(vout2x01234567_3x01234567), 0); c2 += 2;
        vst1q_lane_u16((void*) c3, vreinterpretq_u16_u8(vout2x01234567_3x01234567), 4); c3 += 2;
        vst1q_lane_u16((void*) c4, vreinterpretq_u16_u8(vout4x01234567_5x01234567), 0); c4 += 2;
        vst1q_lane_u16((void*) c5, vreinterpretq_u16_u8(vout4x01234567_5x01234567), 4); c5 += 2;
        vst1q_lane_u16((void*) c6, vreinterpretq_u16_u8(vout6x01234567_7x01234567), 0); c6 += 2;
        vst1q_lane_u16((void*) c7, vreinterpretq_u16_u8(vout6x01234567_7x01234567), 4); c7 += 2;
        vout0x01234567_1x01234567 = vextq_u8(vout0x01234567_1x01234567, vout0x01234567_1x01234567, 2);
        vout2x01234567_3x01234567 = vextq_u8(vout2x01234567_3x01234567, vout2x01234567_3x01234567, 2);
        vout4x01234567_5x01234567 = vextq_u8(vout4x01234567_5x01234567, vout4x01234567_5x01234567, 2);
        vout6x01234567_7x01234567 = vextq_u8(vout6x01234567_7x01234567, vout6x01234567_7x01234567, 2);
      }
      if (nc & 1) {
        vst1q_lane_u8(c0, vout0x01234567_1x01234567, 0);
        vst1q_lane_u8(c1, vout0x01234567_1x01234567, 8);
        vst1q_lane_u8(c2, vout2x01234567_3x01234567, 0);
        vst1q_lane_u8(c3, vout2x01234567_3x01234567, 8);
        vst1q_lane_u8(c4, vout4x01234567_5x01234567, 0);
        vst1q_lane_u8(c5, vout4x01234567_5x01234567, 8);
        vst1q_lane_u8(c6, vout6x01234567_7x01234567, 0);
        vst1q_lane_u8(c7, vout6x01234567_7x01234567, 8);
      }

      nc = 0;
    }
  } while (nc != 0);
}