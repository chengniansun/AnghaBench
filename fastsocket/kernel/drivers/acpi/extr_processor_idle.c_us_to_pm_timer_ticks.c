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
typedef  int s64 ;

/* Variables and functions */
 int PM_TIMER_FREQUENCY ; 
 int div64_u64 (int,int) ; 

__attribute__((used)) static s64 us_to_pm_timer_ticks(s64 t)
{
	return div64_u64(t * PM_TIMER_FREQUENCY, 1000000);
}