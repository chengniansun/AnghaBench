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
struct sonicvibes {struct snd_pcm_substream* capture_substream; int /*<<< orphan*/  mode; } ;
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {int /*<<< orphan*/  hw; } ;

/* Variables and functions */
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
 int /*<<< orphan*/  SV_MODE_CAPTURE ; 
 int /*<<< orphan*/  snd_pcm_hw_constraint_ratdens (struct snd_pcm_runtime*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct sonicvibes* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  snd_sonicvibes_capture ; 
 int /*<<< orphan*/  snd_sonicvibes_hw_constraints_adc_clock ; 

__attribute__((used)) static int snd_sonicvibes_capture_open(struct snd_pcm_substream *substream)
{
	struct sonicvibes *sonic = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;

	sonic->mode |= SV_MODE_CAPTURE;
	sonic->capture_substream = substream;
	runtime->hw = snd_sonicvibes_capture;
	snd_pcm_hw_constraint_ratdens(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
				      &snd_sonicvibes_hw_constraints_adc_clock);
	return 0;
}