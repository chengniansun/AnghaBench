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
 int PIL_DEFERRED_PCR_WORK ; 
 int /*<<< orphan*/  set_softint (int) ; 

void set_perf_event_pending(void)
{
	set_softint(1 << PIL_DEFERRED_PCR_WORK);
}