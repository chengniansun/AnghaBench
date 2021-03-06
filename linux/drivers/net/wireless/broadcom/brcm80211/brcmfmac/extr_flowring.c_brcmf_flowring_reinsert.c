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
typedef  size_t u16 ;
struct sk_buff {int dummy; } ;
struct brcmf_flowring_ring {int /*<<< orphan*/  skblist; } ;
struct brcmf_flowring {struct brcmf_flowring_ring** rings; } ;

/* Variables and functions */
 int /*<<< orphan*/  skb_queue_head (int /*<<< orphan*/ *,struct sk_buff*) ; 

void brcmf_flowring_reinsert(struct brcmf_flowring *flow, u16 flowid,
			     struct sk_buff *skb)
{
	struct brcmf_flowring_ring *ring;

	ring = flow->rings[flowid];

	skb_queue_head(&ring->skblist, skb);
}