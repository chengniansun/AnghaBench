#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int prot; } ;
struct TYPE_4__ {TYPE_1__ cartridge; } ;

/* Variables and functions */
 TYPE_2__ scd ; 

__attribute__((used)) static unsigned int cart_prot_read_word(unsigned int address)
{
  return (scd.cartridge.prot | 0xff00);
}