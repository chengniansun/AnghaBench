#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ngx_ssl_session_t ;
struct TYPE_5__ {TYPE_1__* ssl; } ;
typedef  TYPE_2__ ngx_connection_t ;
struct TYPE_4__ {int /*<<< orphan*/  connection; int /*<<< orphan*/ * session; } ;

/* Variables and functions */
 int /*<<< orphan*/ * SSL_get0_session (int /*<<< orphan*/ ) ; 

ngx_ssl_session_t *
ngx_ssl_get0_session(ngx_connection_t *c)
{
    if (c->ssl->session) {
        return c->ssl->session;
    }

    return SSL_get0_session(c->ssl->connection);
}