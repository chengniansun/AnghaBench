#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct task_struct {int dummy; } ;
struct TYPE_8__ {TYPE_2__* context; } ;
struct TYPE_6__ {int /*<<< orphan*/  ds; } ;
struct pebs_tracer {TYPE_3__ ds; TYPE_1__ trace; scalar_t__ ovfl; } ;
typedef  scalar_t__ pebs_ovfl_callback_t ;
struct TYPE_7__ {struct pebs_tracer* pebs_master; } ;

/* Variables and functions */
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int EPERM ; 
 struct pebs_tracer* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  ds_init_ds_trace (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*,size_t,size_t,unsigned int) ; 
 int /*<<< orphan*/  ds_install_ds_area (TYPE_2__*) ; 
 int /*<<< orphan*/  ds_lock ; 
 int /*<<< orphan*/  ds_pebs ; 
 int /*<<< orphan*/  ds_put_context (TYPE_2__*) ; 
 int ds_request (TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct task_struct*,int,void*,size_t,size_t) ; 
 int /*<<< orphan*/  ds_resume_pebs (struct pebs_tracer*) ; 
 int /*<<< orphan*/  ds_write_config (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int get_tracer (struct task_struct*) ; 
 int /*<<< orphan*/  kfree (struct pebs_tracer*) ; 
 struct pebs_tracer* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_tracer (struct task_struct*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct pebs_tracer *ds_request_pebs(struct task_struct *task, int cpu,
					   void *base, size_t size,
					   pebs_ovfl_callback_t ovfl, size_t th,
					   unsigned int flags)
{
	struct pebs_tracer *tracer;
	int error;

	/* Buffer overflow notification is not yet implemented. */
	error = -EOPNOTSUPP;
	if (ovfl)
		goto out;

	error = get_tracer(task);
	if (error < 0)
		goto out;

	error = -ENOMEM;
	tracer = kzalloc(sizeof(*tracer), GFP_KERNEL);
	if (!tracer)
		goto out_put_tracer;
	tracer->ovfl = ovfl;

	/* Do some more error checking and acquire a tracing context. */
	error = ds_request(&tracer->ds, &tracer->trace.ds,
			   ds_pebs, task, cpu, base, size, th);
	if (error < 0)
		goto out_tracer;

	/* Claim the pebs part of the tracing context we acquired above. */
	spin_lock_irq(&ds_lock);

	error = -EPERM;
	if (tracer->ds.context->pebs_master)
		goto out_unlock;
	tracer->ds.context->pebs_master = tracer;

	spin_unlock_irq(&ds_lock);

	/*
	 * Now that we own the pebs part of the context, let's complete the
	 * initialization for that part.
	 */
	ds_init_ds_trace(&tracer->trace.ds, ds_pebs, base, size, th, flags);
	ds_write_config(tracer->ds.context, &tracer->trace.ds, ds_pebs);
	ds_install_ds_area(tracer->ds.context);

	/* Start tracing. */
	ds_resume_pebs(tracer);

	return tracer;

 out_unlock:
	spin_unlock_irq(&ds_lock);
	ds_put_context(tracer->ds.context);
 out_tracer:
	kfree(tracer);
 out_put_tracer:
	put_tracer(task);
 out:
	return ERR_PTR(error);
}