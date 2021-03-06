#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct qset_params {int /*<<< orphan*/  coalesce_usecs; } ;
struct port_info {struct adapter* adapter; } ;
struct net_device {int dummy; } ;
struct ethtool_coalesce {int /*<<< orphan*/  rx_coalesce_usecs; } ;
struct TYPE_3__ {struct qset_params* qset; } ;
struct TYPE_4__ {TYPE_1__ sge; } ;
struct adapter {TYPE_2__ params; } ;

/* Variables and functions */
 struct port_info* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int get_coalesce(struct net_device *dev, struct ethtool_coalesce *c)
{
	struct port_info *pi = netdev_priv(dev);
	struct adapter *adapter = pi->adapter;
	struct qset_params *q = adapter->params.sge.qset;

	c->rx_coalesce_usecs = q->coalesce_usecs;
	return 0;
}