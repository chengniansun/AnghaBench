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
struct pgid {int dummy; } ;
struct ccw_device {TYPE_1__* private; } ;
struct TYPE_2__ {int /*<<< orphan*/ * pgid; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,struct pgid*,int) ; 

__attribute__((used)) static void pgid_fill(struct ccw_device *cdev, struct pgid *pgid)
{
	int i;

	for (i = 0; i < 8; i++)
		memcpy(&cdev->private->pgid[i], pgid, sizeof(struct pgid));
}