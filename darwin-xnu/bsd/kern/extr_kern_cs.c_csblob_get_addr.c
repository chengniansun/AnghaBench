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
typedef  int /*<<< orphan*/  vm_address_t ;
struct cs_blob {int /*<<< orphan*/  csb_mem_kaddr; } ;

/* Variables and functions */

vm_address_t
csblob_get_addr(struct cs_blob *blob)
{
    return blob->csb_mem_kaddr;
}