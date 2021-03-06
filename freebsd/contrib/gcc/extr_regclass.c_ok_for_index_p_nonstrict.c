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
typedef  int /*<<< orphan*/  rtx ;

/* Variables and functions */
 unsigned int FIRST_PSEUDO_REGISTER ; 
 unsigned int REGNO (int /*<<< orphan*/ ) ; 
 scalar_t__ REGNO_OK_FOR_INDEX_P (unsigned int) ; 

__attribute__((used)) static inline bool
ok_for_index_p_nonstrict (rtx reg)
{
  unsigned regno = REGNO (reg);
  return regno >= FIRST_PSEUDO_REGISTER || REGNO_OK_FOR_INDEX_P (regno);
}