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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  br_eax_context ;

/* Variables and functions */
 int /*<<< orphan*/  br_eax_check_tag_trunc (int /*<<< orphan*/ *,void const*,int) ; 

uint32_t
br_eax_check_tag(br_eax_context *ctx, const void *tag)
{
	return br_eax_check_tag_trunc(ctx, tag, 16);
}