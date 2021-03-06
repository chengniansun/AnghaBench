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
struct TYPE_4__ {int /*<<< orphan*/  mmgr; struct TYPE_4__* value; } ;
typedef  TYPE_1__* HPDF_Binary ;

/* Variables and functions */
 int /*<<< orphan*/  HPDF_FreeMem (int /*<<< orphan*/ ,TYPE_1__*) ; 

void
HPDF_Binary_Free  (HPDF_Binary  obj)
{
    if (!obj)
        return;

    if (obj->value)
        HPDF_FreeMem (obj->mmgr, obj->value);

    HPDF_FreeMem (obj->mmgr, obj);
}