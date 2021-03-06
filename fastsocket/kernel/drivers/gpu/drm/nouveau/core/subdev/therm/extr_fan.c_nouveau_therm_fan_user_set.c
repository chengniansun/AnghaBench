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
struct nouveau_therm_priv {scalar_t__ mode; } ;
struct nouveau_therm {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ NOUVEAU_THERM_CTRL_MANUAL ; 
 int nouveau_therm_fan_set (struct nouveau_therm*,int,int) ; 

int
nouveau_therm_fan_user_set(struct nouveau_therm *therm, int percent)
{
	struct nouveau_therm_priv *priv = (void *)therm;

	if (priv->mode != NOUVEAU_THERM_CTRL_MANUAL)
		return -EINVAL;

	return nouveau_therm_fan_set(therm, true, percent);
}