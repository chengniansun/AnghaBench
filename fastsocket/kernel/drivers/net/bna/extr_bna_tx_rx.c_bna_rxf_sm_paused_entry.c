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
struct bna_rxf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  call_rxf_pause_cbfn (struct bna_rxf*) ; 

__attribute__((used)) static void
bna_rxf_sm_paused_entry(struct bna_rxf *rxf)
{
	call_rxf_pause_cbfn(rxf);
}