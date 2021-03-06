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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  __le32 ;

/* Variables and functions */
 int /*<<< orphan*/  GENMASK (int,int) ; 
 int /*<<< orphan*/  le32p_replace_bits (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void set_tx_desc_sec_type(__le32 *__txdesc, u32 __value)
{
	le32p_replace_bits((__txdesc + 1), __value, GENMASK(23, 22));
}