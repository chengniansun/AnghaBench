#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {size_t index; int /*<<< orphan*/  name; } ;
typedef  TYPE_1__ PIP ;

/* Variables and functions */
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ) ; 
 TYPE_1__** protocols ; 

void paride_unregister(PIP * pr)
{
	if (!pr)
		return;
	if (protocols[pr->index] != pr) {
		printk("paride: %s not registered\n", pr->name);
		return;
	}
	protocols[pr->index] = NULL;
}