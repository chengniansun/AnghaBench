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
struct cred {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  aa_get_newest_label (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cred_label (struct cred const*) ; 
 int /*<<< orphan*/  set_cred_label (struct cred*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void apparmor_cred_transfer(struct cred *new, const struct cred *old)
{
	set_cred_label(new, aa_get_newest_label(cred_label(old)));
}