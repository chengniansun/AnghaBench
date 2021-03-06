#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  zBuf; int /*<<< orphan*/  bStatic; } ;
typedef  TYPE_1__ JsonString ;

/* Variables and functions */
 int /*<<< orphan*/  jsonZero (TYPE_1__*) ; 
 int /*<<< orphan*/  sqlite3_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void jsonReset(JsonString *p){
  if( !p->bStatic ) sqlite3_free(p->zBuf);
  jsonZero(p);
}