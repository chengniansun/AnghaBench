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
struct dc_state {int dummy; } ;
struct dc {struct clk_mgr* clk_mgr; } ;
struct clk_mgr {TYPE_1__* funcs; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* update_clocks ) (struct clk_mgr*,struct dc_state*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  dce110_set_displaymarks (struct dc*,struct dc_state*) ; 
 int /*<<< orphan*/  stub1 (struct clk_mgr*,struct dc_state*,int) ; 

void dce110_optimize_bandwidth(
		struct dc *dc,
		struct dc_state *context)
{
	struct clk_mgr *dccg = dc->clk_mgr;

	dce110_set_displaymarks(dc, context);

	dccg->funcs->update_clocks(
			dccg,
			context,
			true);
}