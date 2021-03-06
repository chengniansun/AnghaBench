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
struct artpec6_crypto {int pending_count; } ;

/* Variables and functions */
 int /*<<< orphan*/  artpec6_crypto_dev ; 
 struct artpec6_crypto* dev_get_drvdata (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool artpec6_crypto_busy(void)
{
	struct artpec6_crypto *ac = dev_get_drvdata(artpec6_crypto_dev);
	int fifo_count = ac->pending_count;

	return fifo_count > 6;
}