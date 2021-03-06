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
struct gdbarch {int /*<<< orphan*/  memory_insert_breakpoint; } ;
typedef  int /*<<< orphan*/  gdbarch_memory_insert_breakpoint_ftype ;

/* Variables and functions */

void
set_gdbarch_memory_insert_breakpoint (struct gdbarch *gdbarch,
                                      gdbarch_memory_insert_breakpoint_ftype memory_insert_breakpoint)
{
  gdbarch->memory_insert_breakpoint = memory_insert_breakpoint;
}