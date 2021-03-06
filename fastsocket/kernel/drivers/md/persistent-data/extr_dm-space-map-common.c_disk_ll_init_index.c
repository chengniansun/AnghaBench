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
struct ll_disk {int /*<<< orphan*/  bitmap_root; int /*<<< orphan*/  bitmap_info; } ;

/* Variables and functions */
 int dm_btree_empty (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int disk_ll_init_index(struct ll_disk *ll)
{
	return dm_btree_empty(&ll->bitmap_info, &ll->bitmap_root);
}