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
struct tcf_proto {int dummy; } ;
struct ingress_qdisc_data {struct tcf_proto* filter_list; } ;
struct Qdisc {int dummy; } ;

/* Variables and functions */
 struct ingress_qdisc_data* qdisc_priv (struct Qdisc*) ; 

__attribute__((used)) static struct tcf_proto **ingress_find_tcf(struct Qdisc *sch, unsigned long cl)
{
	struct ingress_qdisc_data *p = qdisc_priv(sch);

	return &p->filter_list;
}