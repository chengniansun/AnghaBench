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
typedef  size_t vm_offset_t ;
typedef  size_t u_int32_t ;
struct agp_nvidia_softc {size_t pg_offset; TYPE_1__* gatt; } ;
typedef  int /*<<< orphan*/  device_t ;
struct TYPE_2__ {size_t ag_entries; scalar_t__* ag_virtual; } ;

/* Variables and functions */
 size_t AGP_PAGE_SHIFT ; 
 int EINVAL ; 
 struct agp_nvidia_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
agp_nvidia_unbind_page(device_t dev, vm_offset_t offset)
{
	struct agp_nvidia_softc *sc = device_get_softc(dev);
	u_int32_t index;

	if (offset >= (sc->gatt->ag_entries << AGP_PAGE_SHIFT))
		return (EINVAL);

	index = (sc->pg_offset + offset) >> AGP_PAGE_SHIFT;
	sc->gatt->ag_virtual[index] = 0;

	return (0);
}