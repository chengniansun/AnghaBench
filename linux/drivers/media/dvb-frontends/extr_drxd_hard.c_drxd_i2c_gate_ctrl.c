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
struct dvb_frontend {int dummy; } ;

/* Variables and functions */
 int drxd_config_i2c (struct dvb_frontend*,int) ; 

__attribute__((used)) static int drxd_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
	return drxd_config_i2c(fe, enable);
}