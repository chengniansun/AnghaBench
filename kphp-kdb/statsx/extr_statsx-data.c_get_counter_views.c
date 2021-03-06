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
struct counter {int type; int views; } ;

/* Variables and functions */
 struct counter* get_counter_old (long long,int /*<<< orphan*/ ,int) ; 

int get_counter_views (long long counter_id) {
  struct counter *C = get_counter_old (counter_id, 0, 1);
  if (!C) { return -1;}
  if (C->type == -2) { return -2;}
  return C->views;
}