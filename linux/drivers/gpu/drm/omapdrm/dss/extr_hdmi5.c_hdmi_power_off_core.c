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
struct omap_hdmi {int core_enabled; int /*<<< orphan*/  vdda_reg; } ;

/* Variables and functions */
 int /*<<< orphan*/  hdmi_runtime_put (struct omap_hdmi*) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void hdmi_power_off_core(struct omap_hdmi *hdmi)
{
	hdmi->core_enabled = false;

	hdmi_runtime_put(hdmi);
	regulator_disable(hdmi->vdda_reg);
}