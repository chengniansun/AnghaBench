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
typedef  scalar_t__ dtrace_dropkind_t ;
struct TYPE_2__ {char const* dtdrg_tag; scalar_t__ dtdrg_kind; } ;

/* Variables and functions */
 TYPE_1__* _dt_droptags ; 

__attribute__((used)) static const char *
dt_droptag(dtrace_dropkind_t kind)
{
	int i;

	for (i = 0; _dt_droptags[i].dtdrg_tag != NULL; i++) {
		if (_dt_droptags[i].dtdrg_kind == kind)
			return (_dt_droptags[i].dtdrg_tag);
	}

	return ("DTRACEDROP_UNKNOWN");
}