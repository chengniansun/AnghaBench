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
typedef  int /*<<< orphan*/  video_adapter_t ;
typedef  int /*<<< orphan*/  off_t ;

/* Variables and functions */
 int ENODEV ; 

__attribute__((used)) static int
vga_set_origin(video_adapter_t *adp, off_t offset)
{
    /* 
     * The standard video modes do not require window mapping; 
     * always return error.
     */
    return ENODEV;
}