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
struct ifbropreq64 {int dummy; } ;
struct bridge_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BRIDGE_IOCTL_GBPARAM ; 
 scalar_t__ bridge_in_bsd_mode (struct bridge_softc*) ; 

__attribute__((used)) static int
bridge_ioctl_gbparam64(struct bridge_softc *sc, void *arg)
{
	struct ifbropreq64 *req = arg;

	if (bridge_in_bsd_mode(sc)) {
		BRIDGE_IOCTL_GBPARAM;
	}
	return (0);
}