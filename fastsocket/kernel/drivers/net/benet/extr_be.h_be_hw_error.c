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
struct be_adapter {scalar_t__ hw_error; scalar_t__ eeh_error; } ;

/* Variables and functions */

__attribute__((used)) static inline bool be_hw_error(struct be_adapter *adapter)
{
	return adapter->eeh_error || adapter->hw_error;
}