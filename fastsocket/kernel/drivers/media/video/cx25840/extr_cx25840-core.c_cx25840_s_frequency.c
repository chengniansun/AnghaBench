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
struct v4l2_subdev {int dummy; } ;
struct v4l2_frequency {int dummy; } ;
struct i2c_client {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  input_change (struct i2c_client*) ; 
 struct i2c_client* v4l2_get_subdevdata (struct v4l2_subdev*) ; 

__attribute__((used)) static int cx25840_s_frequency(struct v4l2_subdev *sd, struct v4l2_frequency *freq)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);

	input_change(client);
	return 0;
}