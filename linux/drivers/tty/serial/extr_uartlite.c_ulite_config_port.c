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
struct uart_port {int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  PORT_UARTLITE ; 
 int /*<<< orphan*/  ulite_request_port (struct uart_port*) ; 

__attribute__((used)) static void ulite_config_port(struct uart_port *port, int flags)
{
	if (!ulite_request_port(port))
		port->type = PORT_UARTLITE;
}