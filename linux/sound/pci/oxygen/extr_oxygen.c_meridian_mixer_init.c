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
struct oxygen {int /*<<< orphan*/  card; } ;

/* Variables and functions */
 int generic_mixer_init (struct oxygen*) ; 
 int /*<<< orphan*/  meridian_dig_source_control ; 
 int snd_ctl_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_ctl_new1 (int /*<<< orphan*/ *,struct oxygen*) ; 

__attribute__((used)) static int meridian_mixer_init(struct oxygen *chip)
{
	int err;

	err = generic_mixer_init(chip);
	if (err < 0)
		return err;
	err = snd_ctl_add(chip->card,
			  snd_ctl_new1(&meridian_dig_source_control, chip));
	if (err < 0)
		return err;
	return 0;
}