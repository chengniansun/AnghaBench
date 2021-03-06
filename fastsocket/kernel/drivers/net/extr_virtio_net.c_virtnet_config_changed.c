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
struct virtnet_info {int dummy; } ;
struct virtio_device {struct virtnet_info* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  virtnet_update_status (struct virtnet_info*) ; 

__attribute__((used)) static void virtnet_config_changed(struct virtio_device *vdev)
{
	struct virtnet_info *vi = vdev->priv;

	virtnet_update_status(vi);
}