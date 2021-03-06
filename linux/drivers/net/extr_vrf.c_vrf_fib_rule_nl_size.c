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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct fib_rule_hdr {int dummy; } ;

/* Variables and functions */
 size_t NLMSG_ALIGN (int) ; 
 scalar_t__ nla_total_size (int) ; 

__attribute__((used)) static inline size_t vrf_fib_rule_nl_size(void)
{
	size_t sz;

	sz  = NLMSG_ALIGN(sizeof(struct fib_rule_hdr));
	sz += nla_total_size(sizeof(u8));	/* FRA_L3MDEV */
	sz += nla_total_size(sizeof(u32));	/* FRA_PRIORITY */
	sz += nla_total_size(sizeof(u8));       /* FRA_PROTOCOL */

	return sz;
}