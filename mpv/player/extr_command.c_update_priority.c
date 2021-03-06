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
struct MPOpts {scalar_t__ w32_priority; } ;
struct MPContext {struct MPOpts* opts; } ;

/* Variables and functions */
 int /*<<< orphan*/  GetCurrentProcess () ; 
 int /*<<< orphan*/  SetPriorityClass (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void update_priority(struct MPContext *mpctx)
{
#if HAVE_WIN32_DESKTOP
    struct MPOpts *opts = mpctx->opts;
    if (opts->w32_priority > 0)
        SetPriorityClass(GetCurrentProcess(), opts->w32_priority);
#endif
}