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

/* Variables and functions */
 int /*<<< orphan*/  AT_FDCWD ; 
 int readlinkat_malloc (int /*<<< orphan*/ ,char const*,char**) ; 

int readlink_malloc(const char *p, char **ret) {
        return readlinkat_malloc(AT_FDCWD, p, ret);
}