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
struct ieee80211_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rtl8180_write_phy (struct ieee80211_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void rtl8225_write_phy_ofdm(struct ieee80211_hw *dev,
					  u8 addr, u8 data)
{
	rtl8180_write_phy(dev, addr, data);
}