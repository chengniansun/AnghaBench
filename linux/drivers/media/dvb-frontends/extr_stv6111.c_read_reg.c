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
struct stv {int /*<<< orphan*/  adr; int /*<<< orphan*/  i2c; } ;

/* Variables and functions */
 int i2c_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int read_reg(struct stv *state, u8 reg, u8 *val)
{
	return i2c_read(state->i2c, state->adr, &reg, 1, val, 1);
}