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

/* Variables and functions */
 int /*<<< orphan*/  GDB_OSABI_SOLARIS ; 
 int /*<<< orphan*/  bfd_arch_sparc ; 
 int /*<<< orphan*/  gdbarch_register_osabi (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sparc32_sol2_init_abi ; 

void
_initialize_sparc_sol2_tdep (void)
{
  gdbarch_register_osabi (bfd_arch_sparc, 0,
			  GDB_OSABI_SOLARIS, sparc32_sol2_init_abi);
}