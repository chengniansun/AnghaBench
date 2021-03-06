#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {double dv; } ;
struct TYPE_6__ {TYPE_1__ value; int /*<<< orphan*/  type; } ;
typedef  TYPE_2__ ucl_object_t ;

/* Variables and functions */
 int /*<<< orphan*/  UCL_FLOAT ; 
 TYPE_2__* ucl_object_new () ; 

ucl_object_t *
ucl_object_fromdouble (double dv)
{
	ucl_object_t *obj;

	obj = ucl_object_new ();
	if (obj != NULL) {
		obj->type = UCL_FLOAT;
		obj->value.dv = dv;
	}

	return obj;
}