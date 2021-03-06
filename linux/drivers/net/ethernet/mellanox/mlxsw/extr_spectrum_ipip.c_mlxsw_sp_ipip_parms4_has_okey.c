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
struct ip_tunnel_parm {int o_flags; } ;

/* Variables and functions */
 int TUNNEL_KEY ; 

__attribute__((used)) static bool mlxsw_sp_ipip_parms4_has_okey(struct ip_tunnel_parm parms)
{
	return !!(parms.o_flags & TUNNEL_KEY);
}