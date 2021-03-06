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
struct TYPE_3__ {int /*<<< orphan*/  sock; } ;
typedef  TYPE_1__ httpd_client_t ;

/* Variables and functions */
 scalar_t__ net_GetPeerAddress (int /*<<< orphan*/ ,char*,int*) ; 
 int /*<<< orphan*/  vlc_tls_GetFD (int /*<<< orphan*/ ) ; 

char* httpd_ClientIP(const httpd_client_t *cl, char *ip, int *port)
{
    return net_GetPeerAddress(vlc_tls_GetFD(cl->sock), ip, port) ? NULL : ip;
}