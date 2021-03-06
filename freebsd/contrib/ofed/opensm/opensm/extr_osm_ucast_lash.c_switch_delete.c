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
struct TYPE_4__ {struct TYPE_4__* dij_channels; } ;
typedef  TYPE_1__ switch_t ;
typedef  int /*<<< orphan*/  lash_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 

__attribute__((used)) static void switch_delete(lash_t *p_lash, switch_t * sw)
{
	if (sw->dij_channels)
		free(sw->dij_channels);
	free(sw);
}