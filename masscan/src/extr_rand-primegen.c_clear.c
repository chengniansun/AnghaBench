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
typedef  scalar_t__ uint32_t ;

/* Variables and functions */
 int B32 ; 

__attribute__((used)) static void clear(register uint32_t (*buf)[B32])
{
  register int i;
  register int j;

  for (j = 0;j < 16;++j) {
    for (i = 0;i < B32;++i)
      (*buf)[i] = (uint32_t)~0;
    ++buf;
  }
}