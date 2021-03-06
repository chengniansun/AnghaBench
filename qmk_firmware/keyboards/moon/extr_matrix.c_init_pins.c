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

/* Variables and functions */
 int /*<<< orphan*/  ALL_HIGH ; 
 int /*<<< orphan*/  ALL_INPUT ; 
 int /*<<< orphan*/  ALL_OUTPUT ; 
 int /*<<< orphan*/  IC1 ; 
 int /*<<< orphan*/  IC2 ; 
 int /*<<< orphan*/  PCA9555_PORT0 ; 
 int /*<<< orphan*/  PCA9555_PORT1 ; 
 int /*<<< orphan*/  pca9555_set_config (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pca9555_set_output (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void init_pins(void) {
  // init cols - IC2 port0 & IC2 port1 input
  pca9555_set_config(IC2, PCA9555_PORT0, ALL_INPUT);
  pca9555_set_config(IC2, PCA9555_PORT1, ALL_INPUT);

  // init rows - IC1 port0 output
  pca9555_set_config(IC1, PCA9555_PORT0, ALL_OUTPUT);
  pca9555_set_output(IC1, PCA9555_PORT0, ALL_HIGH);
}