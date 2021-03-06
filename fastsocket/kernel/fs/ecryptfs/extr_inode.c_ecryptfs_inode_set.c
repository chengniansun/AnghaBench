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
struct inode {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ecryptfs_init_inode (struct inode*,struct inode*) ; 

int ecryptfs_inode_set(struct inode *inode, void *lower_inode)
{
	ecryptfs_init_inode(inode, (struct inode *)lower_inode);
	return 0;
}