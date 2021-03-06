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
struct em_sti_priv {scalar_t__ base; } ;

/* Variables and functions */
 int /*<<< orphan*/  iowrite32 (unsigned long,scalar_t__) ; 

__attribute__((used)) static inline void em_sti_write(struct em_sti_priv *p, int offs,
				unsigned long value)
{
	iowrite32(value, p->base + offs);
}