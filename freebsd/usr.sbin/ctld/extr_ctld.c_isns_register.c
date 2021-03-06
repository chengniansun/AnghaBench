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
struct isns {struct conf* i_conf; } ;
struct conf {int /*<<< orphan*/  conf_targets; int /*<<< orphan*/  conf_isns_timeout; int /*<<< orphan*/  conf_portal_groups; } ;
typedef  int /*<<< orphan*/  hostname ;

/* Variables and functions */
 scalar_t__ TAILQ_EMPTY (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  gethostname (char*,int) ; 
 int isns_do_connect (struct isns*) ; 
 int /*<<< orphan*/  isns_do_deregister (struct isns*,int,char*) ; 
 int /*<<< orphan*/  isns_do_register (struct isns*,int,char*) ; 
 int /*<<< orphan*/  set_timeout (int /*<<< orphan*/ ,int) ; 

void
isns_register(struct isns *isns, struct isns *oldisns)
{
	struct conf *conf = isns->i_conf;
	int s;
	char hostname[256];

	if (TAILQ_EMPTY(&conf->conf_targets) ||
	    TAILQ_EMPTY(&conf->conf_portal_groups))
		return;
	set_timeout(conf->conf_isns_timeout, false);
	s = isns_do_connect(isns);
	if (s < 0) {
		set_timeout(0, false);
		return;
	}
	gethostname(hostname, sizeof(hostname));

	if (oldisns == NULL || TAILQ_EMPTY(&oldisns->i_conf->conf_targets))
		oldisns = isns;
	isns_do_deregister(oldisns, s, hostname);
	isns_do_register(isns, s, hostname);
	close(s);
	set_timeout(0, false);
}