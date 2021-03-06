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
typedef  int u32 ;
struct nvkm_vmm {int dummy; } ;
struct nvkm_mmu_pt {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT_ULL (int) ; 
 int /*<<< orphan*/  VMM_FO064 (struct nvkm_mmu_pt*,struct nvkm_vmm*,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
gm200_vmm_pgt_sparse(struct nvkm_vmm *vmm,
		     struct nvkm_mmu_pt *pt, u32 ptei, u32 ptes)
{
	/* VALID_FALSE + VOL tells the MMU to treat the PTE as sparse. */
	VMM_FO064(pt, vmm, ptei * 8, BIT_ULL(32) /* VOL. */, ptes);
}