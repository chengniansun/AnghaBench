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
typedef  int u16 ;
struct b43_wldev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  B43_PHY_OFDM (int) ; 
 int /*<<< orphan*/  b43_phy_maskset (struct b43_wldev*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static void lpphy_set_pa_gain(struct b43_wldev *dev, u16 gain)
{
	b43_phy_maskset(dev, B43_PHY_OFDM(0xFB), 0xE03F, gain << 6);
	b43_phy_maskset(dev, B43_PHY_OFDM(0xFD), 0x80FF, gain << 8);
}