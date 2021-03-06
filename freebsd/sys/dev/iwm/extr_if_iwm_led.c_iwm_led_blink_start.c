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
struct iwm_softc {int /*<<< orphan*/  sc_led_blink_to; } ;

/* Variables and functions */
 int /*<<< orphan*/  callout_reset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct iwm_softc*) ; 
 int /*<<< orphan*/  iwm_led_blink_timeout ; 

void
iwm_led_blink_start(struct iwm_softc *sc)
{
	callout_reset(&sc->sc_led_blink_to, 0, iwm_led_blink_timeout, sc);
}