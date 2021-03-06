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
struct i915_request {int /*<<< orphan*/  tail; int /*<<< orphan*/  ring; int /*<<< orphan*/  engine; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENGINE_WRITE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RING_TAIL ; 
 int /*<<< orphan*/  i915_request_submit (struct i915_request*) ; 
 int /*<<< orphan*/  intel_ring_set_tail (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void i9xx_submit_request(struct i915_request *request)
{
	i915_request_submit(request);

	ENGINE_WRITE(request->engine, RING_TAIL,
		     intel_ring_set_tail(request->ring, request->tail));
}