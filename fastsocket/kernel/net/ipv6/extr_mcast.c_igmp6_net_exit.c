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
struct TYPE_2__ {int /*<<< orphan*/  igmp_sk; } ;
struct net {TYPE_1__ ipv6; } ;

/* Variables and functions */
 int /*<<< orphan*/  igmp6_proc_exit (struct net*) ; 
 int /*<<< orphan*/  inet_ctl_sock_destroy (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void igmp6_net_exit(struct net *net)
{
	inet_ctl_sock_destroy(net->ipv6.igmp_sk);
	igmp6_proc_exit(net);
}