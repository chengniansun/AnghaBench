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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  ptrdiff_t ;
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  ff_vp8_idct_dc_add_mmi (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void ff_vp8_idct_dc_add4y_mmi(uint8_t *dst, int16_t block[4][16],
        ptrdiff_t stride)
{
    ff_vp8_idct_dc_add_mmi(dst +  0, block[0], stride);
    ff_vp8_idct_dc_add_mmi(dst +  4, block[1], stride);
    ff_vp8_idct_dc_add_mmi(dst +  8, block[2], stride);
    ff_vp8_idct_dc_add_mmi(dst + 12, block[3], stride);
}