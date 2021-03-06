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
typedef  int lwpid_t ;

/* Variables and functions */
 size_t TID_BUFFER_SIZE ; 
 int alloc_unr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 
 int* tid_buffer ; 
 size_t tid_head ; 
 int /*<<< orphan*/  tid_lock ; 
 size_t tid_tail ; 
 int /*<<< orphan*/  tid_unrhdr ; 

__attribute__((used)) static lwpid_t
tid_alloc(void)
{
	lwpid_t	tid;

	tid = alloc_unr(tid_unrhdr);
	if (tid != -1)
		return (tid);
	mtx_lock(&tid_lock);
	if (tid_head == tid_tail) {
		mtx_unlock(&tid_lock);
		return (-1);
	}
	tid = tid_buffer[tid_head];
	tid_head = (tid_head + 1) % TID_BUFFER_SIZE;
	mtx_unlock(&tid_lock);
	return (tid);
}