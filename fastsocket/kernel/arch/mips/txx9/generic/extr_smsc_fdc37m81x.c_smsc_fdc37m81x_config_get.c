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
typedef  int /*<<< orphan*/  u8 ;

/* Variables and functions */
 scalar_t__ g_smsc_fdc37m81x_base ; 
 int /*<<< orphan*/  smsc_fdc37m81x_rd (int /*<<< orphan*/ ) ; 

u8 smsc_fdc37m81x_config_get(u8 reg)
{
	u8 val = 0;

	if (g_smsc_fdc37m81x_base)
		val = smsc_fdc37m81x_rd(reg);

	return val;
}