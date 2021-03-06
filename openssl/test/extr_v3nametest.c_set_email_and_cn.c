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
typedef  int /*<<< orphan*/  X509 ;

/* Variables and functions */
 int /*<<< orphan*/  NID_commonName ; 
 int /*<<< orphan*/  NID_pkcs9_emailAddress ; 
 int set_cn (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int set_email_and_cn(X509 *crt, const char *name)
{
    return set_cn(crt, NID_pkcs9_emailAddress, name,
                  NID_commonName, "www.example.org", 0);
}