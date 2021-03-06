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
typedef  int /*<<< orphan*/  u8 ;
struct ixgbe_dcb_tc_config {TYPE_1__* path; } ;
struct ixgbe_dcb_config {struct ixgbe_dcb_tc_config* tc_config; } ;
struct TYPE_2__ {int /*<<< orphan*/  tsa; } ;

/* Variables and functions */
 int IXGBE_DCB_MAX_TRAFFIC_CLASS ; 

void ixgbe_dcb_unpack_tsa_cee(struct ixgbe_dcb_config *cfg, int direction,
			   u8 *tsa)
{
	struct ixgbe_dcb_tc_config *tc_config = &cfg->tc_config[0];
	int tc;

	for (tc = 0; tc < IXGBE_DCB_MAX_TRAFFIC_CLASS; tc++)
		tsa[tc] = tc_config[tc].path[direction].tsa;
}