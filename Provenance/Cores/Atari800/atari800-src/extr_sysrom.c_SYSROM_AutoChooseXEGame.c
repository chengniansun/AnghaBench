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

/* Variables and functions */
 int AutoChooseROM (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  autochoose_order_xegame ; 

int SYSROM_AutoChooseXEGame(void)
{
	return AutoChooseROM(autochoose_order_xegame);
}