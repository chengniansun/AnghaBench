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
struct soc_pcmcia_socket {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IPAQ_EGPIO_OPT_NVRAM_ON ; 
 int /*<<< orphan*/  IPAQ_EGPIO_OPT_ON ; 
 int /*<<< orphan*/  IPAQ_EGPIO_OPT_RESET ; 
 int /*<<< orphan*/  assign_h3600_egpio (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  irqs ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  soc_pcmcia_enable_irqs (struct soc_pcmcia_socket*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void h3600_pcmcia_socket_init(struct soc_pcmcia_socket *skt)
{
	/* Enable CF bus: */
	assign_h3600_egpio(IPAQ_EGPIO_OPT_NVRAM_ON, 1);
	assign_h3600_egpio(IPAQ_EGPIO_OPT_ON, 1);
	assign_h3600_egpio(IPAQ_EGPIO_OPT_RESET, 0);

	msleep(10);

	soc_pcmcia_enable_irqs(skt, irqs, ARRAY_SIZE(irqs));
}