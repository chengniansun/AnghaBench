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
struct TYPE_4__ {TYPE_1__* slot; } ;
struct nfsd4_compoundres {TYPE_2__ cstate; } ;
struct TYPE_3__ {int /*<<< orphan*/  sl_cachethis; } ;

/* Variables and functions */
 scalar_t__ nfsd4_is_solo_sequence (struct nfsd4_compoundres*) ; 

__attribute__((used)) static inline bool nfsd4_not_cached(struct nfsd4_compoundres *resp)
{
	return !resp->cstate.slot->sl_cachethis || nfsd4_is_solo_sequence(resp);
}