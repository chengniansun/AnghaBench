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
typedef  int /*<<< orphan*/  uint8_t ;
struct blake2b_xform_ctx {int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  BLAKE2B_OUTBYTES ; 
 int blake2b_final_ref (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic (char*) ; 

__attribute__((used)) static void
blake2b_xform_final(uint8_t *out, void *vctx)
{
	struct blake2b_xform_ctx *ctx = vctx;
	int rc;

	rc = blake2b_final_ref(&ctx->state, out, BLAKE2B_OUTBYTES);
	if (rc != 0)
		panic("blake2b_final: invalid");
}