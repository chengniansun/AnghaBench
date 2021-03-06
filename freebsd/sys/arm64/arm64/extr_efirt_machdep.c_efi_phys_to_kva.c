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
typedef  int /*<<< orphan*/  vm_paddr_t ;
typedef  int /*<<< orphan*/  vm_offset_t ;

/* Variables and functions */
 int /*<<< orphan*/  PHYS_IN_DMAP (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PHYS_TO_DMAP (int /*<<< orphan*/ ) ; 

vm_offset_t
efi_phys_to_kva(vm_paddr_t paddr)
{

	if (!PHYS_IN_DMAP(paddr))
		return (0);
	return (PHYS_TO_DMAP(paddr));
}