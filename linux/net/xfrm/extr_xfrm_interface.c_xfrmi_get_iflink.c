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
struct TYPE_2__ {int link; } ;
struct xfrm_if {TYPE_1__ p; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct xfrm_if* netdev_priv (struct net_device const*) ; 

__attribute__((used)) static int xfrmi_get_iflink(const struct net_device *dev)
{
	struct xfrm_if *xi = netdev_priv(dev);

	return xi->p.link;
}