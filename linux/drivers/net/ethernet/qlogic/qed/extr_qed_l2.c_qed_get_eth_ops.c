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
struct qed_eth_ops {int dummy; } ;

/* Variables and functions */
 struct qed_eth_ops const qed_eth_ops_pass ; 

const struct qed_eth_ops *qed_get_eth_ops(void)
{
	return &qed_eth_ops_pass;
}