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
typedef  scalar_t__ ble_npl_time_t ;

/* Variables and functions */
 int /*<<< orphan*/  mp_hal_delay_ms (scalar_t__) ; 

void ble_npl_time_delay(ble_npl_time_t ticks) {
    mp_hal_delay_ms(ticks + 1);
}