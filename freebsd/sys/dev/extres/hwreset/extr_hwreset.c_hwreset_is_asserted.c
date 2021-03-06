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
typedef  TYPE_1__* hwreset_t ;
struct TYPE_3__ {int /*<<< orphan*/  rst_id; int /*<<< orphan*/  provider_dev; } ;

/* Variables and functions */
 int HWRESET_IS_ASSERTED (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 

int
hwreset_is_asserted(hwreset_t rst, bool *value)
{

	return (HWRESET_IS_ASSERTED(rst->provider_dev, rst->rst_id, value));
}