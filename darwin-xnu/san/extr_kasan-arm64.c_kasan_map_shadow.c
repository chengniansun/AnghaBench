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
typedef  int /*<<< orphan*/  vm_size_t ;
typedef  int /*<<< orphan*/  vm_offset_t ;

/* Variables and functions */
 int /*<<< orphan*/  kasan_map_shadow_internal (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 

void
kasan_map_shadow(vm_offset_t address, vm_size_t size, bool is_zero)
{
	kasan_map_shadow_internal(address, size, is_zero, true);
}