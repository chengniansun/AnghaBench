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
typedef  int /*<<< orphan*/  vlc_thread_t ;

/* Variables and functions */
 int /*<<< orphan*/  thread_key ; 
 int /*<<< orphan*/  vlc_threadvar_get (int /*<<< orphan*/ ) ; 

vlc_thread_t vlc_thread_self (void)
{
    return vlc_threadvar_get (thread_key);
}