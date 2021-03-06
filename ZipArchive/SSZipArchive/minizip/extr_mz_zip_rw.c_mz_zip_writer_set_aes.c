#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_2__ {int /*<<< orphan*/  aes; } ;
typedef  TYPE_1__ mz_zip_writer ;

/* Variables and functions */

void mz_zip_writer_set_aes(void *handle, uint8_t aes)
{
    mz_zip_writer *writer = (mz_zip_writer *)handle;
    writer->aes = aes;
}