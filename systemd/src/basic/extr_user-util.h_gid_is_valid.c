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
typedef  int /*<<< orphan*/  uid_t ;
typedef  scalar_t__ gid_t ;

/* Variables and functions */
 int uid_is_valid (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool gid_is_valid(gid_t gid) {
        return uid_is_valid((uid_t) gid);
}