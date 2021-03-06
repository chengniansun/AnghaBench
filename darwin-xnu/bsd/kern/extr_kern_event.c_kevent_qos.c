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
typedef  int /*<<< orphan*/  uint64_t ;
struct proc {int dummy; } ;
struct kevent_qos_args {int /*<<< orphan*/  flags; scalar_t__ data_available; int /*<<< orphan*/  data_out; int /*<<< orphan*/  nevents; int /*<<< orphan*/  eventlist; int /*<<< orphan*/  nchanges; int /*<<< orphan*/  changelist; scalar_t__ fd; } ;
typedef  int /*<<< orphan*/  kqueue_id_t ;
typedef  int /*<<< orphan*/  int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  KEVENT_FLAG_USER ; 
 int /*<<< orphan*/  kevent_continue ; 
 int kevent_internal (struct proc*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long long,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int
kevent_qos(struct proc *p, struct kevent_qos_args *uap, int32_t *retval)
{
	/* restrict to user flags */
	uap->flags &= KEVENT_FLAG_USER;

	return kevent_internal(p,
	                       (kqueue_id_t)uap->fd, NULL,
	                       uap->changelist, uap->nchanges,
	                       uap->eventlist,	uap->nevents,
	                       uap->data_out, (uint64_t)uap->data_available,
	                       uap->flags,
	                       0ULL,
	                       kevent_continue,
	                       retval);
}