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
typedef  int /*<<< orphan*/  LZ4_stream_t ;
typedef  int /*<<< orphan*/  LZ4F_CDict ;

/* Variables and functions */
 int LZ4_compress_fast_continue (int /*<<< orphan*/ *,char const*,char*,int,int,int const) ; 

__attribute__((used)) static int LZ4F_compressBlock_continue(void* ctx, const char* src, char* dst, int srcSize, int dstCapacity, int level, const LZ4F_CDict* cdict)
{
    int const acceleration = (level < 0) ? -level + 1 : 1;
    (void)cdict; /* init once at beginning of frame */
    return LZ4_compress_fast_continue((LZ4_stream_t*)ctx, src, dst, srcSize, dstCapacity, acceleration);
}