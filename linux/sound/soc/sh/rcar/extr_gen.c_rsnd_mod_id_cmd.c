#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct rsnd_mod {TYPE_1__* ops; } ;
struct TYPE_2__ {int (* id_cmd ) (struct rsnd_mod*) ;} ;

/* Variables and functions */
 int rsnd_mod_id (struct rsnd_mod*) ; 
 int stub1 (struct rsnd_mod*) ; 

__attribute__((used)) static int rsnd_mod_id_cmd(struct rsnd_mod *mod)
{
	if (mod->ops->id_cmd)
		return mod->ops->id_cmd(mod);

	return rsnd_mod_id(mod);
}