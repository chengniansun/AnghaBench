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
typedef  scalar_t__ wchar_t ;

/* Variables and functions */
 size_t mbstowcs (scalar_t__*,char const*,size_t) ; 

size_t os_mbs_to_wcs(const char *str, size_t len, wchar_t *dst, size_t dst_size)
{
	size_t out_len;

	if (!str)
		return 0;

	out_len = dst ? (dst_size - 1) : mbstowcs(NULL, str, len);

	if (dst) {
		if (!dst_size)
			return 0;

		if (out_len)
			out_len = mbstowcs(dst, str, out_len + 1);

		dst[out_len] = 0;
	}

	return out_len;
}