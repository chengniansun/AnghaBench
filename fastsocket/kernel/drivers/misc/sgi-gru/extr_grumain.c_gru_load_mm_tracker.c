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
struct gru_thread_state {int ts_ctxnum; struct gru_mm_struct* ts_gms; } ;
struct gru_state {size_t gs_gid; scalar_t__ gs_asid_gen; int /*<<< orphan*/  gs_asid_lock; } ;
struct gru_mm_tracker {int mt_asid; unsigned short mt_ctxbitmap; scalar_t__ mt_asid_gen; } ;
struct gru_mm_struct {int /*<<< orphan*/ * ms_asidmap; int /*<<< orphan*/  ms_asid_lock; struct gru_mm_tracker* ms_asids; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (unsigned short) ; 
 int /*<<< orphan*/  STAT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __set_bit (size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  asid_new ; 
 int /*<<< orphan*/  asid_reuse ; 
 int gru_assign_asid (struct gru_state*) ; 
 int /*<<< orphan*/  gru_dbg (int /*<<< orphan*/ ,char*,size_t,struct gru_thread_state*,struct gru_mm_struct*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  grudev ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_bit (size_t,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int gru_load_mm_tracker(struct gru_state *gru,
					struct gru_thread_state *gts)
{
	struct gru_mm_struct *gms = gts->ts_gms;
	struct gru_mm_tracker *asids = &gms->ms_asids[gru->gs_gid];
	unsigned short ctxbitmap = (1 << gts->ts_ctxnum);
	int asid;

	spin_lock(&gms->ms_asid_lock);
	asid = asids->mt_asid;

	spin_lock(&gru->gs_asid_lock);
	if (asid == 0 || (asids->mt_ctxbitmap == 0 && asids->mt_asid_gen !=
			  gru->gs_asid_gen)) {
		asid = gru_assign_asid(gru);
		asids->mt_asid = asid;
		asids->mt_asid_gen = gru->gs_asid_gen;
		STAT(asid_new);
	} else {
		STAT(asid_reuse);
	}
	spin_unlock(&gru->gs_asid_lock);

	BUG_ON(asids->mt_ctxbitmap & ctxbitmap);
	asids->mt_ctxbitmap |= ctxbitmap;
	if (!test_bit(gru->gs_gid, gms->ms_asidmap))
		__set_bit(gru->gs_gid, gms->ms_asidmap);
	spin_unlock(&gms->ms_asid_lock);

	gru_dbg(grudev,
		"gid %d, gts %p, gms %p, ctxnum %d, asid 0x%x, asidmap 0x%lx\n",
		gru->gs_gid, gts, gms, gts->ts_ctxnum, asid,
		gms->ms_asidmap[0]);
	return asid;
}