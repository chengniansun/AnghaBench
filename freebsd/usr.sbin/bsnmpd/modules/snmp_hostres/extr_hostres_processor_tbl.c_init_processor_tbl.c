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
 int /*<<< orphan*/  create_proc_table () ; 
 int /*<<< orphan*/  refresh_processor_tbl () ; 

void
init_processor_tbl(void)
{

	/* create the initial processor table */
	create_proc_table();
	/* and get first samples */
	refresh_processor_tbl();
}