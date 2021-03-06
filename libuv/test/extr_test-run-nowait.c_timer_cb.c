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
typedef  int /*<<< orphan*/  uv_timer_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int timer_called ; 
 int /*<<< orphan*/  timer_handle ; 

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  ASSERT(handle == &timer_handle);
  timer_called = 1;
}