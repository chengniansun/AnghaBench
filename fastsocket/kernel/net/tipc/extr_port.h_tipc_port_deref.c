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
typedef  int /*<<< orphan*/  u32 ;
struct port {int dummy; } ;

/* Variables and functions */
 scalar_t__ tipc_ref_deref (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct port* tipc_port_deref(u32 ref)
{
	return (struct port *)tipc_ref_deref(ref);
}