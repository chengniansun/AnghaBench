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
struct TYPE_2__ {int /*<<< orphan*/  s; } ;
struct mtree_entry {TYPE_1__ basename; } ;
struct archive_rb_node {int dummy; } ;

/* Variables and functions */
 int strcmp (char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
mtree_entry_cmp_key(const struct archive_rb_node *n, const void *key)
{
	const struct mtree_entry *e = (const struct mtree_entry *)n;

	return (strcmp((const char *)key, e->basename.s));
}