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
struct TYPE_4__ {scalar_t__ nvp_type; scalar_t__ nvp_data; } ;
typedef  TYPE_1__ nvpair_t ;
typedef  int /*<<< orphan*/  nvlist_t ;

/* Variables and functions */
 int /*<<< orphan*/  NVPAIR_ASSERT (TYPE_1__ const*) ; 
 scalar_t__ NV_TYPE_NVLIST ; 
 int /*<<< orphan*/  PJDLOG_ASSERT (int) ; 

const nvlist_t *
nvpair_get_nvlist(const nvpair_t *nvp)
{

	NVPAIR_ASSERT(nvp);
	PJDLOG_ASSERT(nvp->nvp_type == NV_TYPE_NVLIST);

	return ((const nvlist_t *)(intptr_t)nvp->nvp_data);
}