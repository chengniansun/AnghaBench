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
struct ov5640_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OV5640_REG_SDE_CTRL0 ; 
 int /*<<< orphan*/  OV5640_REG_SDE_CTRL1 ; 
 int ov5640_mod_reg (struct ov5640_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ov5640_write_reg16 (struct ov5640_dev*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int ov5640_set_ctrl_hue(struct ov5640_dev *sensor, int value)
{
	int ret;

	if (value) {
		ret = ov5640_mod_reg(sensor, OV5640_REG_SDE_CTRL0,
				     BIT(0), BIT(0));
		if (ret)
			return ret;
		ret = ov5640_write_reg16(sensor, OV5640_REG_SDE_CTRL1, value);
	} else {
		ret = ov5640_mod_reg(sensor, OV5640_REG_SDE_CTRL0, BIT(0), 0);
	}

	return ret;
}