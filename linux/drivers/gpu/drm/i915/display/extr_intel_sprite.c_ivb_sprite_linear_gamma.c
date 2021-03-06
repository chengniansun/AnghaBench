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
typedef  int u16 ;

/* Variables and functions */

__attribute__((used)) static void ivb_sprite_linear_gamma(u16 gamma[18])
{
	int i;

	for (i = 0; i < 17; i++)
		gamma[i] = (i << 10) / 16;

	gamma[i] = 3 << 10;
	i++;
}