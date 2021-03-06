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
struct http_proxy_info {char* proxy_authenticate; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (char*) ; 

__attribute__((used)) static void
store_proxy_authenticate(struct http_proxy_info *p, char *data)
{
    if (p->proxy_authenticate)
    {
        free(p->proxy_authenticate);
    }
    p->proxy_authenticate = data;
}