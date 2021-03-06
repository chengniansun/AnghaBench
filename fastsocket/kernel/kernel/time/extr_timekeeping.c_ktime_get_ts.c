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
struct timespec {scalar_t__ tv_nsec; scalar_t__ tv_sec; } ;
typedef  scalar_t__ s64 ;
struct TYPE_2__ {struct timespec wall_to_monotonic; struct timespec xtime; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
 scalar_t__ arch_gettimeoffset () ; 
 unsigned int read_seqbegin (int /*<<< orphan*/ *) ; 
 scalar_t__ read_seqretry (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  set_normalized_timespec (struct timespec*,scalar_t__,scalar_t__) ; 
 TYPE_1__ timekeeper ; 
 scalar_t__ timekeeping_get_ns () ; 
 int /*<<< orphan*/  timekeeping_suspended ; 

void ktime_get_ts(struct timespec *ts)
{
	struct timespec tomono;
	unsigned int seq;
	s64 nsecs;

	WARN_ON(timekeeping_suspended);

	do {
		seq = read_seqbegin(&timekeeper.lock);
		*ts = timekeeper.xtime;
		tomono = timekeeper.wall_to_monotonic;
		nsecs = timekeeping_get_ns();
		/* If arch requires, add in gettimeoffset() */
		nsecs += arch_gettimeoffset();

	} while (read_seqretry(&timekeeper.lock, seq));

	set_normalized_timespec(ts, ts->tv_sec + tomono.tv_sec,
				ts->tv_nsec + tomono.tv_nsec + nsecs);
}