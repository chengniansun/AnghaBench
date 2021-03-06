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
typedef  int /*<<< orphan*/  uint32_t ;
struct mdchain {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  le32toh (int /*<<< orphan*/ ) ; 
 int md_get_uint32 (struct mdchain*,int /*<<< orphan*/ *) ; 

int
md_get_uint32le(struct mdchain *mdp, uint32_t *x)
{
	uint32_t v;
	int error;

	error = md_get_uint32(mdp, &v);
	if (x != NULL)
		*x = le32toh(v);
	return (error);
}