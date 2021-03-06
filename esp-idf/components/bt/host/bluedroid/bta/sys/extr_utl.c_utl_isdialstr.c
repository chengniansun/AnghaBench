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
typedef  size_t UINT16 ;
typedef  int /*<<< orphan*/  BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 

BOOLEAN utl_isdialstr(const char *p_s)
{
    UINT16 i = 0;

    for (i = 0; p_s[i] != 0; i++) {
        if (!(((p_s[i] >= '0') && (p_s[i] <= '9'))
                || (p_s[i] == '*') || (p_s[i] == '+') || (p_s[i] == '#') || (p_s[i] == ';')
                || ((p_s[i] >= 'A') && (p_s[i] <= 'C'))
                || ((p_s[i] == 'p') || (p_s[i] == 'P')
                    || (p_s[i] == 'w') || (p_s[i] == 'W')))) {
            return FALSE;
        }
    }

    return TRUE;
}