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
struct nn_hash_item {int /*<<< orphan*/  list; } ;

/* Variables and functions */
 int /*<<< orphan*/  nn_list_item_term (int /*<<< orphan*/ *) ; 

void nn_hash_item_term (struct nn_hash_item *self)
{
    nn_list_item_term (&self->list);
}