#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {char const* name; int type; } ;

/* Variables and functions */
 TYPE_1__* capstrmap ; 

const char *
xh_vm_capability_type2name(int type)
{
	int i;

	for (i = 0; (capstrmap[i].name != NULL); i++) {
		if (capstrmap[i].type == type) {
			return (capstrmap[i].name);
		}
	}

	return (NULL);
}