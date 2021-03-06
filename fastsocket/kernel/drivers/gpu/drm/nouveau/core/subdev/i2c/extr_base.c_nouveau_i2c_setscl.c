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
struct nouveau_i2c_port {TYPE_1__* func; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* drive_scl ) (struct nouveau_i2c_port*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct nouveau_i2c_port*,int) ; 

__attribute__((used)) static void
nouveau_i2c_setscl(void *data, int state)
{
	struct nouveau_i2c_port *port = data;
	port->func->drive_scl(port, state);
}