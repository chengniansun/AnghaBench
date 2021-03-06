#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct pardevice {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/ * pardev; } ;
typedef  TYPE_1__ PIA ;

/* Variables and functions */
 int /*<<< orphan*/  parport_unregister_device (struct pardevice*) ; 

__attribute__((used)) static void pi_unregister_parport(PIA * pi)
{
	if (pi->pardev) {
		parport_unregister_device((struct pardevice *) (pi->pardev));
		pi->pardev = NULL;
	}
}