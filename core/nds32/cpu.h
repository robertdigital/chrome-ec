/* Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Registers map and definitions for Andes cores
 */

#ifndef __CROS_EC_CPU_H
#define __CROS_EC_CPU_H

#include <stdint.h>

/* Process Status Word bits */
#define PSW_GIE		(1 << 0) /* Global Interrupt Enable */
#define PSW_INTL_SHIFT	1        /* Interrupt Stack Level */
#define PSW_INTL_MASK	(0x3 << PSW_INTL_SHIFT)

/* write Process Status Word privileged register */
static inline void set_psw(uint32_t val)
{
	asm volatile ("mtsr %0, $PSW" : : "r"(val));
}

/* read Process Status Word privileged register */
static inline uint32_t get_psw(void)
{
	uint32_t ret;
	asm volatile ("mfsr %0, $PSW" : "=r"(ret));
	return ret;
}

/* write Interruption Program Counter privileged register */
static inline void set_ipc(uint32_t val)
{
	asm volatile ("mtsr %0, $IPC" : : "r"(val));
}

/* read Interruption Program Counter privileged register */
static inline uint32_t get_ipc(void)
{
	uint32_t ret;
	asm volatile ("mfsr %0, $IPC" : "=r"(ret));
	return ret;
}

/* read Interruption Type privileged register */
static inline uint32_t get_itype(void)
{
	uint32_t ret;
	asm volatile ("mfsr %0, $ITYPE" : "=r"(ret));
	return ret;
}

/* Generic CPU core initialization */
void cpu_init(void);

#endif /* __CROS_EC_CPU_H */
