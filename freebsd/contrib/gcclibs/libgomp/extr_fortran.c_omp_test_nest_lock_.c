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
typedef  int /*<<< orphan*/  omp_nest_lock_arg_t ;
typedef  int /*<<< orphan*/  int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  omp_nest_lock_arg (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omp_test_nest_lock (int /*<<< orphan*/ ) ; 

int32_t
omp_test_nest_lock_ (omp_nest_lock_arg_t lock)
{
  return omp_test_nest_lock (omp_nest_lock_arg (lock));
}