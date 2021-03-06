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
typedef  scalar_t__ u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct nouveau_object {int dummy; } ;
struct nouveau_barobj {scalar_t__ iomem; } ;

/* Variables and functions */
 int /*<<< orphan*/  iowrite32_native (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void
nouveau_barobj_wr32(struct nouveau_object *object, u64 addr, u32 data)
{
	struct nouveau_barobj *barobj = (void *)object;
	iowrite32_native(data, barobj->iomem + addr);
}