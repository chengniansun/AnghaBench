#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_4__ {TYPE_1__* pdev; } ;
struct idt_ntb_dev {TYPE_2__ ntb; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ntb_msg_event (TYPE_2__*) ; 

__attribute__((used)) static void idt_msg_isr(struct idt_ntb_dev *ndev, u32 ntint_sts)
{
	/*
	 * Message IRQ status will be cleaned only when client
	 * driver unsets all the message status bits.
	 */
	dev_dbg(&ndev->ntb.pdev->dev, "Message IRQ detected %#08x", ntint_sts);

	/* Notify the client driver of possible message status change */
	ntb_msg_event(&ndev->ntb);
}