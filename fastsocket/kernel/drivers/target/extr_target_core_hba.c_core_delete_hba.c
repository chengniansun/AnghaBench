#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct se_hba {TYPE_1__* transport; int /*<<< orphan*/  hba_id; int /*<<< orphan*/  hba_node; int /*<<< orphan*/  dev_count; } ;
struct TYPE_2__ {scalar_t__ owner; int /*<<< orphan*/  (* detach_hba ) (struct se_hba*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hba_lock ; 
 int /*<<< orphan*/  kfree (struct se_hba*) ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  module_put (scalar_t__) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct se_hba*) ; 

int
core_delete_hba(struct se_hba *hba)
{
	WARN_ON(hba->dev_count);

	hba->transport->detach_hba(hba);

	spin_lock(&hba_lock);
	list_del(&hba->hba_node);
	spin_unlock(&hba_lock);

	pr_debug("CORE_HBA[%d] - Detached HBA from Generic Target"
			" Core\n", hba->hba_id);

	if (hba->transport->owner)
		module_put(hba->transport->owner);

	hba->transport = NULL;
	kfree(hba);
	return 0;
}