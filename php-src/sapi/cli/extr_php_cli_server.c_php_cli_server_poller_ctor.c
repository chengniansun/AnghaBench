#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int max_fd; int /*<<< orphan*/  wfds; int /*<<< orphan*/  rfds; } ;
typedef  TYPE_1__ php_cli_server_poller ;

/* Variables and functions */
 int /*<<< orphan*/  FD_ZERO (int /*<<< orphan*/ *) ; 
 int SUCCESS ; 

__attribute__((used)) static int php_cli_server_poller_ctor(php_cli_server_poller *poller) /* {{{ */
{
	FD_ZERO(&poller->rfds);
	FD_ZERO(&poller->wfds);
	poller->max_fd = -1;
	return SUCCESS;
}