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
struct TYPE_5__ {int /*<<< orphan*/  graph; int /*<<< orphan*/  list; } ;
typedef  TYPE_1__ hb_filter_private_t ;
struct TYPE_6__ {TYPE_1__* private_data; } ;
typedef  TYPE_2__ hb_filter_object_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  hb_avfilter_graph_close (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hb_buffer_list_close (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void avfilter_close( hb_filter_object_t * filter )
{
    hb_filter_private_t * pv = filter->private_data;
    if (pv == NULL)
    {
        // Already closed
        return;
    }

    hb_buffer_list_close(&pv->list);
    hb_avfilter_graph_close(&pv->graph);
    free(pv);
    filter->private_data = NULL;
}