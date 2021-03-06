#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  buf; int /*<<< orphan*/ * reply; TYPE_1__* fn; } ;
typedef  TYPE_2__ redisReader ;
struct TYPE_5__ {int /*<<< orphan*/  (* freeObject ) (int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 int /*<<< orphan*/  sdsfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 

void redisReaderFree(redisReader *r) {
    if (r == NULL)
        return;
    if (r->reply != NULL && r->fn && r->fn->freeObject)
        r->fn->freeObject(r->reply);
    sdsfree(r->buf);
    free(r);
}