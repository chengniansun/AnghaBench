#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  n; int /*<<< orphan*/  d; } ;
typedef  TYPE_1__ RNumCalcValue ;

/* Variables and functions */

__attribute__((used)) static inline RNumCalcValue Nand(RNumCalcValue n, RNumCalcValue v) { n.d = v.d; n.n &= v.n; return n; }