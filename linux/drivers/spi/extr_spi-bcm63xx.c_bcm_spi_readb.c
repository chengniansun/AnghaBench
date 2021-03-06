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
typedef  int /*<<< orphan*/  u8 ;
struct bcm63xx_spi {scalar_t__* reg_offsets; scalar_t__ regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  readb (scalar_t__) ; 

__attribute__((used)) static inline u8 bcm_spi_readb(struct bcm63xx_spi *bs,
			       unsigned int offset)
{
	return readb(bs->regs + bs->reg_offsets[offset]);
}