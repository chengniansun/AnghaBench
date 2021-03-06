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
struct dmz_metadata {int /*<<< orphan*/  unmap_nr_rnd; } ;

/* Variables and functions */
 unsigned int atomic_read (int /*<<< orphan*/ *) ; 

unsigned int dmz_nr_unmap_rnd_zones(struct dmz_metadata *zmd)
{
	return atomic_read(&zmd->unmap_nr_rnd);
}