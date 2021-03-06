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
struct cci_pmu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __cci_pmu_enable_nosync (struct cci_pmu*) ; 
 int /*<<< orphan*/  cci_pmu_sync_counters (struct cci_pmu*) ; 

__attribute__((used)) static void __cci_pmu_enable_sync(struct cci_pmu *cci_pmu)
{
	cci_pmu_sync_counters(cci_pmu);
	__cci_pmu_enable_nosync(cci_pmu);
}