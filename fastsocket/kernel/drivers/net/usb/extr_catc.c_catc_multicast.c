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
typedef  int u8 ;
typedef  int u32 ;

/* Variables and functions */
 int ether_crc_le (int,unsigned char*) ; 

__attribute__((used)) static void catc_multicast(unsigned char *addr, u8 *multicast)
{
	u32 crc;

	crc = ether_crc_le(6, addr);
	multicast[(crc >> 3) & 0x3f] |= 1 << (crc & 7);
}