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
struct hclgevf_dev {int /*<<< orphan*/  rst_service_task; int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  HCLGEVF_STATE_REMOVING ; 
 int /*<<< orphan*/  HCLGEVF_STATE_RST_SERVICE_SCHED ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void hclgevf_reset_task_schedule(struct hclgevf_dev *hdev)
{
	if (!test_bit(HCLGEVF_STATE_RST_SERVICE_SCHED, &hdev->state) &&
	    !test_bit(HCLGEVF_STATE_REMOVING, &hdev->state)) {
		set_bit(HCLGEVF_STATE_RST_SERVICE_SCHED, &hdev->state);
		schedule_work(&hdev->rst_service_task);
	}
}