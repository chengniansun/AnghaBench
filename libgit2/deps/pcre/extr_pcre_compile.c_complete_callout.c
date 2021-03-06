#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  pcre_uchar ;
struct TYPE_3__ {int /*<<< orphan*/  const* start_pattern; } ;
typedef  TYPE_1__ compile_data ;

/* Variables and functions */
 int GET (int /*<<< orphan*/ *,int) ; 
 scalar_t__ LINK_SIZE ; 
 int /*<<< orphan*/  PUT (int /*<<< orphan*/ *,scalar_t__,int) ; 

__attribute__((used)) static void
complete_callout(pcre_uchar *previous_callout, const pcre_uchar *ptr, compile_data *cd)
{
int length = (int)(ptr - cd->start_pattern - GET(previous_callout, 2));
PUT(previous_callout, 2 + LINK_SIZE, length);
}