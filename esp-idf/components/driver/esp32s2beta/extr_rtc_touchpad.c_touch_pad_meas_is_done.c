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
struct TYPE_3__ {int touch_meas_done; } ;
struct TYPE_4__ {TYPE_1__ sar_touch_chn_st; } ;

/* Variables and functions */
 TYPE_2__ SENS ; 

bool touch_pad_meas_is_done(void)
{
    return SENS.sar_touch_chn_st.touch_meas_done;
}