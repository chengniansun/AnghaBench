#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  bt_file ;
struct TYPE_4__ {int /*<<< orphan*/  pFile; TYPE_1__* pVfs; } ;
struct TYPE_3__ {void (* xShmBarrier ) (int /*<<< orphan*/ ) ;} ;
typedef  TYPE_2__ BtFile ;

/* Variables and functions */
 void stub1 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void btVfsShmBarrier(bt_file *pFile){
  BtFile *p = (BtFile*)pFile;
  return p->pVfs->xShmBarrier(p->pFile);
}