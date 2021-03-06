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
struct scsi_tape {int /*<<< orphan*/  kref; int /*<<< orphan*/  device; } ;

/* Variables and functions */
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ scsi_device_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  scsi_tape_release ; 
 struct scsi_tape** scsi_tapes ; 
 int /*<<< orphan*/  st_dev_arr_lock ; 
 int st_dev_max ; 
 int /*<<< orphan*/  st_ref_mutex ; 
 int /*<<< orphan*/  write_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  write_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct scsi_tape *scsi_tape_get(int dev)
{
	struct scsi_tape *STp = NULL;

	mutex_lock(&st_ref_mutex);
	write_lock(&st_dev_arr_lock);

	if (dev < st_dev_max && scsi_tapes != NULL)
		STp = scsi_tapes[dev];
	if (!STp) goto out;

	kref_get(&STp->kref);

	if (!STp->device)
		goto out_put;

	if (scsi_device_get(STp->device))
		goto out_put;

	goto out;

out_put:
	kref_put(&STp->kref, scsi_tape_release);
	STp = NULL;
out:
	write_unlock(&st_dev_arr_lock);
	mutex_unlock(&st_ref_mutex);
	return STp;
}