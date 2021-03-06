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
struct nvm_tgt_dev {int /*<<< orphan*/  parent; } ;
struct nvm_rq {int /*<<< orphan*/  dma_ppa_list; int /*<<< orphan*/  ppa_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  nvm_dev_dma_free (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nvm_free_rqd_ppalist(struct nvm_tgt_dev *tgt_dev,
			struct nvm_rq *rqd)
{
	if (!rqd->ppa_list)
		return;

	nvm_dev_dma_free(tgt_dev->parent, rqd->ppa_list, rqd->dma_ppa_list);
}