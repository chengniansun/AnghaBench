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
typedef  int /*<<< orphan*/  dtrace_vstate_t ;
typedef  int /*<<< orphan*/  dtrace_mstate_t ;

/* Variables and functions */
 int dtrace_canstore_remains (int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
dtrace_canstore(uint64_t addr, size_t sz, dtrace_mstate_t *mstate,
    dtrace_vstate_t *vstate)
{
	return (dtrace_canstore_remains(addr, sz, NULL, mstate, vstate));
}