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
typedef  int /*<<< orphan*/  u16 ;
struct snd_soc_dai {struct snd_soc_codec* codec; } ;
struct snd_soc_codec {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WM8903_DAC_DIGITAL_1 ; 
 int /*<<< orphan*/  WM8903_DAC_MUTE ; 
 int /*<<< orphan*/  snd_soc_read (struct snd_soc_codec*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_write (struct snd_soc_codec*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int wm8903_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
	struct snd_soc_codec *codec = codec_dai->codec;
	u16 reg;

	reg = snd_soc_read(codec, WM8903_DAC_DIGITAL_1);

	if (mute)
		reg |= WM8903_DAC_MUTE;
	else
		reg &= ~WM8903_DAC_MUTE;

	snd_soc_write(codec, WM8903_DAC_DIGITAL_1, reg);

	return 0;
}