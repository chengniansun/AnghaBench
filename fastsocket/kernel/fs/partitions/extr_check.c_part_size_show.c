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
struct hd_struct {scalar_t__ nr_sects; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 struct hd_struct* dev_to_part (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned long long) ; 

ssize_t part_size_show(struct device *dev,
		       struct device_attribute *attr, char *buf)
{
	struct hd_struct *p = dev_to_part(dev);
	return sprintf(buf, "%llu\n",(unsigned long long)p->nr_sects);
}