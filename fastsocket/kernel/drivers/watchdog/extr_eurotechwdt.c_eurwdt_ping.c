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
 int /*<<< orphan*/  eurwdt_set_timeout (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  eurwdt_timeout ; 

__attribute__((used)) static void eurwdt_ping(void)
{
	/* Write the watchdog default value */
	eurwdt_set_timeout(eurwdt_timeout);
}