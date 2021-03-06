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
struct net_device {int dummy; } ;
struct net {int dummy; } ;
struct ip6_tnl_net {int /*<<< orphan*/ ** tnls_wc; struct net_device* fb_tnl_dev; } ;
struct ip6_tnl {int dummy; } ;

/* Variables and functions */
 struct net* dev_net (struct net_device*) ; 
 int /*<<< orphan*/  dev_put (struct net_device*) ; 
 int /*<<< orphan*/  ip6_tnl_dst_reset (struct ip6_tnl*) ; 
 int /*<<< orphan*/  ip6_tnl_lock ; 
 int /*<<< orphan*/  ip6_tnl_net_id ; 
 int /*<<< orphan*/  ip6_tnl_unlink (struct ip6_tnl_net*,struct ip6_tnl*) ; 
 struct ip6_tnl_net* net_generic (struct net*,int /*<<< orphan*/ ) ; 
 struct ip6_tnl* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  write_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  write_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
ip6_tnl_dev_uninit(struct net_device *dev)
{
	struct ip6_tnl *t = netdev_priv(dev);
	struct net *net = dev_net(dev);
	struct ip6_tnl_net *ip6n = net_generic(net, ip6_tnl_net_id);

	if (dev == ip6n->fb_tnl_dev) {
		write_lock_bh(&ip6_tnl_lock);
		ip6n->tnls_wc[0] = NULL;
		write_unlock_bh(&ip6_tnl_lock);
	} else {
		ip6_tnl_unlink(ip6n, t);
	}
	ip6_tnl_dst_reset(t);
	dev_put(dev);
}