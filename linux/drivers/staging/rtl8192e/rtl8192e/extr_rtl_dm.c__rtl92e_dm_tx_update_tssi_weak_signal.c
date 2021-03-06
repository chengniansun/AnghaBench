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
typedef  scalar_t__ u8 ;
struct r8192_priv {scalar_t__ rfa_txpowertrackingindex; scalar_t__ rfc_txpowertrackingindex; int rfa_txpowertrackingindex_real; int rfc_txpowertrackingindex_real; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 scalar_t__ RF_2T4R ; 
 int /*<<< orphan*/  bMaskDWord ; 
 int /*<<< orphan*/ * dm_tx_bb_gain ; 
 int /*<<< orphan*/  rOFDM0_XATxIQImbalance ; 
 int /*<<< orphan*/  rOFDM0_XCTxIQImbalance ; 
 int /*<<< orphan*/  rtl92e_set_bb_reg (struct net_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct r8192_priv* rtllib_priv (struct net_device*) ; 

__attribute__((used)) static void _rtl92e_dm_tx_update_tssi_weak_signal(struct net_device *dev,
						  u8 RF_Type)
{
	struct r8192_priv *p = rtllib_priv(dev);

	if (RF_Type == RF_2T4R) {
		if ((p->rfa_txpowertrackingindex > 0) &&
		    (p->rfc_txpowertrackingindex > 0)) {
			p->rfa_txpowertrackingindex--;
			if (p->rfa_txpowertrackingindex_real > 4) {
				p->rfa_txpowertrackingindex_real--;
				rtl92e_set_bb_reg(dev, rOFDM0_XATxIQImbalance,
						  bMaskDWord,
						  dm_tx_bb_gain[p->rfa_txpowertrackingindex_real]);
			}

			p->rfc_txpowertrackingindex--;
			if (p->rfc_txpowertrackingindex_real > 4) {
				p->rfc_txpowertrackingindex_real--;
				rtl92e_set_bb_reg(dev,
						  rOFDM0_XCTxIQImbalance,
						  bMaskDWord,
						  dm_tx_bb_gain[p->rfc_txpowertrackingindex_real]);
			}
		} else {
			rtl92e_set_bb_reg(dev, rOFDM0_XATxIQImbalance,
					  bMaskDWord,
					  dm_tx_bb_gain[4]);
			rtl92e_set_bb_reg(dev,
					  rOFDM0_XCTxIQImbalance,
					  bMaskDWord, dm_tx_bb_gain[4]);
		}
	} else {
		if (p->rfa_txpowertrackingindex > 0) {
			p->rfa_txpowertrackingindex--;
			if (p->rfa_txpowertrackingindex_real > 4) {
				p->rfa_txpowertrackingindex_real--;
				rtl92e_set_bb_reg(dev,
						  rOFDM0_XATxIQImbalance,
						  bMaskDWord,
						  dm_tx_bb_gain[p->rfa_txpowertrackingindex_real]);
			}
		} else {
			rtl92e_set_bb_reg(dev, rOFDM0_XATxIQImbalance,
					  bMaskDWord, dm_tx_bb_gain[4]);
		}
	}
}