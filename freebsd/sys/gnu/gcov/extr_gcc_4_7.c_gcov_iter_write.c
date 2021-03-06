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
struct sbuf {int dummy; } ;
struct gcov_iterator {scalar_t__ pos; scalar_t__ size; size_t buffer; } ;

/* Variables and functions */
 int EINVAL ; 
 size_t ITER_STRIDE ; 
 int /*<<< orphan*/  sbuf_bcat (struct sbuf*,size_t,size_t) ; 

int
gcov_iter_write(struct gcov_iterator *iter, struct sbuf *sbuf)
{
	size_t len;

	if (iter->pos >= iter->size)
		return (EINVAL);

	len = ITER_STRIDE;
	if (iter->pos + len > iter->size)
		len = iter->size - iter->pos;

	sbuf_bcat(sbuf, iter->buffer + iter->pos, len);

	return (0);
}