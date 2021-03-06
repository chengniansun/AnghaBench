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
struct buffer {int dummy; } ;
struct reliable_entry {struct buffer buf; int /*<<< orphan*/  active; } ;
struct reliable {int size; int /*<<< orphan*/  offset; struct reliable_entry* array; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  buf_init (struct buffer*,int /*<<< orphan*/ ) ; 

struct buffer *
reliable_get_buf(struct reliable *rel)
{
    int i;
    for (i = 0; i < rel->size; ++i)
    {
        struct reliable_entry *e = &rel->array[i];
        if (!e->active)
        {
            ASSERT(buf_init(&e->buf, rel->offset));
            return &e->buf;
        }
    }
    return NULL;
}