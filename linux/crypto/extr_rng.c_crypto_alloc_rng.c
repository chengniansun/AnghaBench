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
typedef  int /*<<< orphan*/  u32 ;
struct crypto_rng {int dummy; } ;

/* Variables and functions */
 struct crypto_rng* crypto_alloc_tfm (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_rng_type ; 

struct crypto_rng *crypto_alloc_rng(const char *alg_name, u32 type, u32 mask)
{
	return crypto_alloc_tfm(alg_name, &crypto_rng_type, type, mask);
}