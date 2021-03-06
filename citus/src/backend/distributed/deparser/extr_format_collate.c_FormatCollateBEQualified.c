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
typedef  int /*<<< orphan*/  Oid ;

/* Variables and functions */
 int /*<<< orphan*/  FORMAT_COLLATE_FORCE_QUALIFY ; 
 char* FormatCollateExtended (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

char *
FormatCollateBEQualified(Oid collate_oid)
{
	return FormatCollateExtended(collate_oid, FORMAT_COLLATE_FORCE_QUALIFY);
}