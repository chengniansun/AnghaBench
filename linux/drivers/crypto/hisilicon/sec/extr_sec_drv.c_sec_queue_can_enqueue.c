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
struct sec_queue_ring_cmd {int /*<<< orphan*/  used; } ;
struct sec_queue {struct sec_queue_ring_cmd ring_cmd; } ;

/* Variables and functions */
 int SEC_QUEUE_LEN ; 
 int atomic_read (int /*<<< orphan*/ *) ; 

bool sec_queue_can_enqueue(struct sec_queue *queue, int num)
{
	struct sec_queue_ring_cmd *msg_ring = &queue->ring_cmd;

	return SEC_QUEUE_LEN - atomic_read(&msg_ring->used) >= num;
}