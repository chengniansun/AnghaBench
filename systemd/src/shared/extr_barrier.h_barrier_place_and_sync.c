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
typedef  int /*<<< orphan*/  Barrier ;

/* Variables and functions */
 int /*<<< orphan*/  barrier_place (int /*<<< orphan*/ *) ; 
 int barrier_sync (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool barrier_place_and_sync(Barrier *b) {
        (void) barrier_place(b);
        return barrier_sync(b);
}