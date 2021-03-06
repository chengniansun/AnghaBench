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
struct mb_cache {int c_indexes_count; } ;

/* Variables and functions */
 int MB_CACHE_INDEXES_COUNT ; 

__attribute__((used)) static inline int
mb_cache_indexes(struct mb_cache *cache)
{
#ifdef MB_CACHE_INDEXES_COUNT
	return MB_CACHE_INDEXES_COUNT;
#else
	return cache->c_indexes_count;
#endif
}