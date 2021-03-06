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
struct mps_softc {int /*<<< orphan*/ * mps_cdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  destroy_dev (int /*<<< orphan*/ *) ; 

void
mps_detach_user(struct mps_softc *sc)
{

	/* XXX: do a purge of pending requests? */
	if (sc->mps_cdev != NULL)
		destroy_dev(sc->mps_cdev);
}