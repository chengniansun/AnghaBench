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
struct ksz_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  KS8842_SWITCH_CTRL_7_OFFSET ; 
 int port_chk_shift (struct ksz_hw*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int sw_chk_unk_def_port(struct ksz_hw *hw, int port)
{
	return port_chk_shift(hw, port, KS8842_SWITCH_CTRL_7_OFFSET, 0);
}