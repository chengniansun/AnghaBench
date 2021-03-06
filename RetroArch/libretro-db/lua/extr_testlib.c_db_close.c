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
typedef  int /*<<< orphan*/  lua_State ;
typedef  int /*<<< orphan*/  libretrodb_t ;

/* Variables and functions */
 int /*<<< orphan*/ * checkdb (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  libretrodb_close (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int db_close(lua_State *L)
{
	libretrodb_t *db = checkdb(L);
	libretrodb_close(db);
	return 0;
}