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
struct mlxsw_sib {int /*<<< orphan*/  core; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mlxsw_core_trap_unregister (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct mlxsw_sib*) ; 
 int /*<<< orphan*/ * mlxsw_sib_listener ; 

__attribute__((used)) static void mlxsw_sib_traps_fini(struct mlxsw_sib *mlxsw_sib)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(mlxsw_sib_listener); i++) {
		mlxsw_core_trap_unregister(mlxsw_sib->core,
					   &mlxsw_sib_listener[i], mlxsw_sib);
	}
}