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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct cxl_afu {TYPE_1__* native; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {int /*<<< orphan*/  pp_offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  scnprintf (char*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 struct cxl_afu* to_afu_chardev_m (struct device*) ; 

__attribute__((used)) static ssize_t pp_mmio_off_show(struct device *device,
				struct device_attribute *attr,
				char *buf)
{
	struct cxl_afu *afu = to_afu_chardev_m(device);

	return scnprintf(buf, PAGE_SIZE, "%llu\n", afu->native->pp_offset);
}