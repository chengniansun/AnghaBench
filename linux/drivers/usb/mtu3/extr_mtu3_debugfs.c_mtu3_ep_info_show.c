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
struct seq_file {struct mtu3_ep* private; } ;
struct mtu3_ep {int /*<<< orphan*/  flags; int /*<<< orphan*/  slot; int /*<<< orphan*/  maxp; int /*<<< orphan*/  type; struct mtu3* mtu; } ;
struct mtu3 {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int mtu3_ep_info_show(struct seq_file *sf, void *unused)
{
	struct mtu3_ep *mep = sf->private;
	struct mtu3 *mtu = mep->mtu;
	unsigned long flags;

	spin_lock_irqsave(&mtu->lock, flags);
	seq_printf(sf, "ep - type:%d, maxp:%d, slot:%d, flags:%x\n",
		   mep->type, mep->maxp, mep->slot, mep->flags);
	spin_unlock_irqrestore(&mtu->lock, flags);

	return 0;
}