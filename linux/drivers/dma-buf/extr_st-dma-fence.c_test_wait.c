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
struct dma_fence {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ETIME ; 
 int /*<<< orphan*/  dma_fence_put (struct dma_fence*) ; 
 int /*<<< orphan*/  dma_fence_signal (struct dma_fence*) ; 
 int /*<<< orphan*/  dma_fence_wait_timeout (struct dma_fence*,int,int /*<<< orphan*/ ) ; 
 struct dma_fence* mock_fence () ; 
 int /*<<< orphan*/  pr_err (char*) ; 

__attribute__((used)) static int test_wait(void *arg)
{
	struct dma_fence *f;
	int err = -EINVAL;

	f = mock_fence();
	if (!f)
		return -ENOMEM;

	if (dma_fence_wait_timeout(f, false, 0) != -ETIME) {
		pr_err("Wait reported complete before being signaled\n");
		goto err_free;
	}

	dma_fence_signal(f);

	if (dma_fence_wait_timeout(f, false, 0) != 0) {
		pr_err("Wait reported incomplete after being signaled\n");
		goto err_free;
	}

	err = 0;
err_free:
	dma_fence_signal(f);
	dma_fence_put(f);
	return err;
}