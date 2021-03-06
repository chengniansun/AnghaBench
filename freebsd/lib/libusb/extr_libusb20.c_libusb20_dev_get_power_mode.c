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
typedef  int /*<<< orphan*/  uint8_t ;
struct libusb20_device {TYPE_1__* methods; } ;
struct TYPE_2__ {int (* get_power_mode ) (struct libusb20_device*,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  LIBUSB20_POWER_ON ; 
 int stub1 (struct libusb20_device*,int /*<<< orphan*/ *) ; 

uint8_t
libusb20_dev_get_power_mode(struct libusb20_device *pdev)
{
	int error;
	uint8_t power_mode;

	error = pdev->methods->get_power_mode(pdev, &power_mode);
	if (error)
		power_mode = LIBUSB20_POWER_ON;	/* fake power mode */
	return (power_mode);
}