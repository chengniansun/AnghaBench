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
typedef  int u64 ;
typedef  int /*<<< orphan*/  u16 ;
struct i40e_pf {int /*<<< orphan*/  hw; } ;

/* Variables and functions */
 int /*<<< orphan*/  I40E_PRTQF_FD_INSET (int /*<<< orphan*/ ,int) ; 
 int i40e_read_rx_ctl (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u64 i40e_read_fd_input_set(struct i40e_pf *pf, u16 addr)
{
	u64 val;

	val = i40e_read_rx_ctl(&pf->hw, I40E_PRTQF_FD_INSET(addr, 1));
	val <<= 32;
	val += i40e_read_rx_ctl(&pf->hw, I40E_PRTQF_FD_INSET(addr, 0));

	return val;
}