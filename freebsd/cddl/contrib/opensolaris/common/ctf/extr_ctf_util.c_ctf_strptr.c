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
typedef  int /*<<< orphan*/  uint_t ;
typedef  int /*<<< orphan*/  ctf_file_t ;

/* Variables and functions */
 char* ctf_strraw (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

const char *
ctf_strptr(ctf_file_t *fp, uint_t name)
{
	const char *s = ctf_strraw(fp, name);
	return (s != NULL ? s : "(?)");
}