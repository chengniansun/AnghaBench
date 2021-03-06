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
struct sshkey {int dummy; } ;

/* Variables and functions */
 int SSH_ERR_INVALID_ARGUMENT ; 

int
sshkey_set_filename(struct sshkey *k, const char *filename)
{
	if (k == NULL)
		return SSH_ERR_INVALID_ARGUMENT;
	return 0;
}