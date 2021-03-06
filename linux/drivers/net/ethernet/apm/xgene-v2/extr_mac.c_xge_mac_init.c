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
struct xge_pdata {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  xge_mac_reset (struct xge_pdata*) ; 
 int /*<<< orphan*/  xge_mac_set_speed (struct xge_pdata*) ; 
 int /*<<< orphan*/  xge_mac_set_station_addr (struct xge_pdata*) ; 

void xge_mac_init(struct xge_pdata *pdata)
{
	xge_mac_reset(pdata);
	xge_mac_set_speed(pdata);
	xge_mac_set_station_addr(pdata);
}