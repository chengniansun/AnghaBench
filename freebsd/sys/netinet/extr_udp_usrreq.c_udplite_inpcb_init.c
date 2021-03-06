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
struct inpcb {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  INP_LOCK_INIT (struct inpcb*,char*,char*) ; 

__attribute__((used)) static int
udplite_inpcb_init(void *mem, int size, int flags)
{
	struct inpcb *inp;

	inp = mem;
	INP_LOCK_INIT(inp, "inp", "udpliteinp");
	return (0);
}