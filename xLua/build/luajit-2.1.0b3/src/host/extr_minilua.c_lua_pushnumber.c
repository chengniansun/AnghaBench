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
struct TYPE_4__ {int /*<<< orphan*/  top; } ;
typedef  TYPE_1__ lua_State ;
typedef  int /*<<< orphan*/  lua_Number ;

/* Variables and functions */
 int /*<<< orphan*/  api_incr_top (TYPE_1__*) ; 
 int /*<<< orphan*/  setnvalue (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void lua_pushnumber(lua_State*L,lua_Number n){
setnvalue(L->top,n);
api_incr_top(L);
}