#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u64 ;

/* Variables and functions */
 int shadow_mmio_mask ; 
 int shadow_mmio_value ; 

__attribute__((used)) static bool is_mmio_spte(u64 spte)
{
	return (spte & shadow_mmio_mask) == shadow_mmio_value;
}