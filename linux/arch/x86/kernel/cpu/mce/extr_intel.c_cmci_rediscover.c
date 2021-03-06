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
 int /*<<< orphan*/  cmci_rediscover_work_func ; 
 int /*<<< orphan*/  cmci_supported (int*) ; 
 int /*<<< orphan*/  on_each_cpu (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

void cmci_rediscover(void)
{
	int banks;

	if (!cmci_supported(&banks))
		return;

	on_each_cpu(cmci_rediscover_work_func, NULL, 1);
}