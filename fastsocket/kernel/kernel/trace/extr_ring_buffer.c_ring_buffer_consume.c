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
typedef  int /*<<< orphan*/  u64 ;
struct ring_buffer_per_cpu {int /*<<< orphan*/  reader_lock; } ;
struct ring_buffer_event {scalar_t__ type_len; } ;
struct ring_buffer {struct ring_buffer_per_cpu** buffers; int /*<<< orphan*/  cpumask; } ;

/* Variables and functions */
 scalar_t__ RINGBUF_TYPE_PADDING ; 
 int /*<<< orphan*/  cpumask_test_cpu (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/  rb_advance_reader (struct ring_buffer_per_cpu*) ; 
 struct ring_buffer_event* rb_buffer_peek (struct ring_buffer_per_cpu*,int /*<<< orphan*/ *) ; 
 int rb_ok_to_lock () ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

struct ring_buffer_event *
ring_buffer_consume(struct ring_buffer *buffer, int cpu, u64 *ts)
{
	struct ring_buffer_per_cpu *cpu_buffer;
	struct ring_buffer_event *event = NULL;
	unsigned long flags;
	int dolock;

	dolock = rb_ok_to_lock();

 again:
	/* might be called in atomic */
	preempt_disable();

	if (!cpumask_test_cpu(cpu, buffer->cpumask))
		goto out;

	cpu_buffer = buffer->buffers[cpu];
	local_irq_save(flags);
	if (dolock)
		spin_lock(&cpu_buffer->reader_lock);

	event = rb_buffer_peek(cpu_buffer, ts);
	if (event)
		rb_advance_reader(cpu_buffer);

	if (dolock)
		spin_unlock(&cpu_buffer->reader_lock);
	local_irq_restore(flags);

 out:
	preempt_enable();

	if (event && event->type_len == RINGBUF_TYPE_PADDING)
		goto again;

	return event;
}