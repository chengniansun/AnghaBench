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
struct power_supply {scalar_t__ type; } ;

/* Variables and functions */
 scalar_t__ POWER_SUPPLY_TYPE_BATTERY ; 
 int /*<<< orphan*/  power_supply_update_bat_leds (struct power_supply*) ; 
 int /*<<< orphan*/  power_supply_update_gen_leds (struct power_supply*) ; 

void power_supply_update_leds(struct power_supply *psy)
{
	if (psy->type == POWER_SUPPLY_TYPE_BATTERY)
		power_supply_update_bat_leds(psy);
	else
		power_supply_update_gen_leds(psy);
}