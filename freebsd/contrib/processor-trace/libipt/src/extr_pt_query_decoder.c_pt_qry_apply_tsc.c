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
struct pt_time_cal {int dummy; } ;
struct pt_time {int dummy; } ;
struct pt_packet_tsc {int dummy; } ;
struct pt_config {int dummy; } ;

/* Variables and functions */
 int pt_tcal_update_tsc (struct pt_time_cal*,struct pt_packet_tsc const*,struct pt_config const*) ; 
 int pt_time_update_tsc (struct pt_time*,struct pt_packet_tsc const*,struct pt_config const*) ; 
 int pte_bad_config ; 

__attribute__((used)) static int pt_qry_apply_tsc(struct pt_time *time, struct pt_time_cal *tcal,
			    const struct pt_packet_tsc *packet,
			    const struct pt_config *config)
{
	int errcode;

	/* We ignore configuration errors.  They will result in imprecise
	 * calibration which will result in imprecise cycle-accurate timing.
	 *
	 * We currently do not track them.
	 */
	errcode = pt_tcal_update_tsc(tcal, packet, config);
	if (errcode < 0 && (errcode != -pte_bad_config))
		return errcode;

	/* We ignore configuration errors.  They will result in imprecise
	 * timing and are tracked as packet losses in struct pt_time.
	 */
	errcode = pt_time_update_tsc(time, packet, config);
	if (errcode < 0 && (errcode != -pte_bad_config))
		return errcode;

	return 0;
}