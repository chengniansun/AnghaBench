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
typedef  size_t ULONG ;
typedef  scalar_t__* LPSTR ;

/* Variables and functions */
 int /*<<< orphan*/  IsWhiteChar (scalar_t__,scalar_t__*) ; 

ULONG StrLenUpToWhiteChar(LPSTR p,LPSTR WhiteChars)
{
    ULONG i;

	for(i=0;p[i]!=0 && !IsWhiteChar(p[i],WhiteChars);i++);

	return i;
}