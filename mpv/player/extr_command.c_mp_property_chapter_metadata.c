#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct m_property {int dummy; } ;
struct TYPE_5__ {TYPE_1__* chapters; } ;
struct TYPE_4__ {int /*<<< orphan*/  metadata; } ;
typedef  TYPE_2__ MPContext ;

/* Variables and functions */
 int M_PROPERTY_UNAVAILABLE ; 
 int get_current_chapter (TYPE_2__*) ; 
 int tag_property (int,void*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mp_property_chapter_metadata(void *ctx, struct m_property *prop,
                                        int action, void *arg)
{
    MPContext *mpctx = ctx;
    int chapter = get_current_chapter(mpctx);
    if (chapter < 0)
        return M_PROPERTY_UNAVAILABLE;
    return tag_property(action, arg, mpctx->chapters[chapter].metadata);
}