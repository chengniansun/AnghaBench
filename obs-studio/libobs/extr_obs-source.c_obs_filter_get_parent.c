#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {struct TYPE_5__* filter_parent; } ;
typedef  TYPE_1__ obs_source_t ;

/* Variables and functions */
 scalar_t__ obs_ptr_valid (TYPE_1__ const*,char*) ; 

obs_source_t *obs_filter_get_parent(const obs_source_t *filter)
{
	return obs_ptr_valid(filter, "obs_filter_get_parent")
		       ? filter->filter_parent
		       : NULL;
}