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
typedef  int pcre_uint32 ;
typedef  char* PCRE_PUCHAR ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 scalar_t__ PRINTABLE (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,int) ; 

__attribute__((used)) static void
print_puchar(FILE *f, PCRE_PUCHAR ptr)
{
while (*ptr != '\0')
  {
  register pcre_uint32 c = *ptr++;
  if (PRINTABLE(c)) fprintf(f, "%c", c); else fprintf(f, "\\x{%x}", c);
  }
}