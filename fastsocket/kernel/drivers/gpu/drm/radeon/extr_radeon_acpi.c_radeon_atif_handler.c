#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct radeon_encoder_lvds {int /*<<< orphan*/  bl_dev; } ;
struct radeon_encoder_atom_dig {int /*<<< orphan*/  bl_dev; } ;
struct radeon_encoder {struct radeon_encoder_lvds* enc_priv; } ;
struct TYPE_3__ {scalar_t__ command_code; int /*<<< orphan*/  enabled; } ;
struct radeon_atif {struct radeon_encoder* encoder_for_bl; TYPE_1__ notification_cfg; } ;
struct radeon_device {scalar_t__ is_atom_bios; TYPE_2__* pdev; struct radeon_atif atif; } ;
struct atif_sbios_requests {int pending; int backlight_level; } ;
struct acpi_bus_event {scalar_t__ type; int /*<<< orphan*/  device_class; } ;
typedef  int /*<<< orphan*/  acpi_handle ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_VIDEO_CLASS ; 
 int ATIF_PANEL_BRIGHTNESS_CHANGE_REQUEST ; 
 int /*<<< orphan*/  BACKLIGHT_UPDATE_HOTKEY ; 
 int /*<<< orphan*/  DEVICE_ACPI_HANDLE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DRM_DEBUG_DRIVER (char*,int,...) ; 
 int NOTIFY_BAD ; 
 int NOTIFY_DONE ; 
 int /*<<< orphan*/  backlight_force_update (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int radeon_atif_get_sbios_requests (int /*<<< orphan*/ ,struct atif_sbios_requests*) ; 
 int /*<<< orphan*/  radeon_set_backlight_level (struct radeon_device*,struct radeon_encoder*,int) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int radeon_atif_handler(struct radeon_device *rdev,
		struct acpi_bus_event *event)
{
	struct radeon_atif *atif = &rdev->atif;
	struct atif_sbios_requests req;
	acpi_handle handle;
	int count;

	DRM_DEBUG_DRIVER("event, device_class = %s, type = %#x\n",
			event->device_class, event->type);

	if (strcmp(event->device_class, ACPI_VIDEO_CLASS) != 0)
		return NOTIFY_DONE;

	if (!atif->notification_cfg.enabled ||
			event->type != atif->notification_cfg.command_code)
		/* Not our event */
		return NOTIFY_DONE;

	/* Check pending SBIOS requests */
	handle = DEVICE_ACPI_HANDLE(&rdev->pdev->dev);
	count = radeon_atif_get_sbios_requests(handle, &req);

	if (count <= 0)
		return NOTIFY_DONE;

	DRM_DEBUG_DRIVER("ATIF: %d pending SBIOS requests\n", count);

	if (req.pending & ATIF_PANEL_BRIGHTNESS_CHANGE_REQUEST) {
		struct radeon_encoder *enc = atif->encoder_for_bl;

		if (enc) {
			DRM_DEBUG_DRIVER("Changing brightness to %d\n",
					req.backlight_level);

			radeon_set_backlight_level(rdev, enc, req.backlight_level);

#if defined(CONFIG_BACKLIGHT_CLASS_DEVICE) || defined(CONFIG_BACKLIGHT_CLASS_DEVICE_MODULE)
			if (rdev->is_atom_bios) {
				struct radeon_encoder_atom_dig *dig = enc->enc_priv;
				backlight_force_update(dig->bl_dev,
						       BACKLIGHT_UPDATE_HOTKEY);
			} else {
				struct radeon_encoder_lvds *dig = enc->enc_priv;
				backlight_force_update(dig->bl_dev,
						       BACKLIGHT_UPDATE_HOTKEY);
			}
#endif
		}
	}
	/* TODO: check other events */

	/* We've handled the event, stop the notifier chain. The ACPI interface
	 * overloads ACPI_VIDEO_NOTIFY_PROBE, we don't want to send that to
	 * userspace if the event was generated only to signal a SBIOS
	 * request.
	 */
	return NOTIFY_BAD;
}