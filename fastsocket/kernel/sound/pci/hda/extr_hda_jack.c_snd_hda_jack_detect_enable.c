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
struct hda_codec {int dummy; } ;
typedef  int /*<<< orphan*/  hda_nid_t ;

/* Variables and functions */
 int snd_hda_jack_detect_enable_callback (struct hda_codec*,int /*<<< orphan*/ ,unsigned char,int /*<<< orphan*/ *) ; 

int snd_hda_jack_detect_enable(struct hda_codec *codec, hda_nid_t nid,
			       unsigned char action)
{
	return snd_hda_jack_detect_enable_callback(codec, nid, action, NULL);
}