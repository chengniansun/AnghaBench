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
struct snd_kcontrol {int dummy; } ;
struct snd_ctl_elem_info {int dummy; } ;
struct hdsp {scalar_t__ io_type; } ;

/* Variables and functions */
 scalar_t__ H9632 ; 
 int snd_ctl_enum_info (struct snd_ctl_elem_info*,int,int,char const* const*) ; 
 struct hdsp* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int snd_hdsp_info_clock_source(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
	static const char * const texts[] = {
		"AutoSync", "Internal 32.0 kHz", "Internal 44.1 kHz",
		"Internal 48.0 kHz", "Internal 64.0 kHz", "Internal 88.2 kHz",
		"Internal 96.0 kHz", "Internal 128 kHz", "Internal 176.4 kHz",
		"Internal 192.0 KHz"
	};
	struct hdsp *hdsp = snd_kcontrol_chip(kcontrol);

	return snd_ctl_enum_info(uinfo, 1, (hdsp->io_type == H9632) ? 10 : 7,
				 texts);
}