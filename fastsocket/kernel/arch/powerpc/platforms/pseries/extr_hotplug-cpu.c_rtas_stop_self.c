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
struct rtas_args {scalar_t__ token; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 scalar_t__ RTAS_UNKNOWN_SERVICE ; 
 int /*<<< orphan*/  __pa (struct rtas_args*) ; 
 int /*<<< orphan*/  enter_rtas (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hard_smp_processor_id () ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct rtas_args rtas_stop_self_args ; 
 int /*<<< orphan*/  smp_processor_id () ; 

__attribute__((used)) static void rtas_stop_self(void)
{
	struct rtas_args *args = &rtas_stop_self_args;

	local_irq_disable();

	BUG_ON(args->token == RTAS_UNKNOWN_SERVICE);

	printk("cpu %u (hwid %u) Ready to die...\n",
	       smp_processor_id(), hard_smp_processor_id());
	enter_rtas(__pa(args));

	panic("Alas, I survived.\n");
}