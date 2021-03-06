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
typedef  int /*<<< orphan*/  uint64_t ;

/* Variables and functions */
 int /*<<< orphan*/  hton64 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void put64bit(uint8_t **ptr,uint64_t val)
{
    uint64_t val_n = hton64 (val);
    *((uint64_t *)(*ptr)) = val_n;
    (*ptr)+=8;
}