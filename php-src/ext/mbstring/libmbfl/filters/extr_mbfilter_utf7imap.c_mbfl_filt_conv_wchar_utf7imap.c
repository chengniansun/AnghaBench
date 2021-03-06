#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int status; int cache; int /*<<< orphan*/  data; int /*<<< orphan*/  (* output_function ) (int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* filter_function ) (int,TYPE_1__*) ;} ;
typedef  TYPE_1__ mbfl_convert_filter ;

/* Variables and functions */
 int /*<<< orphan*/  CK (int /*<<< orphan*/ ) ; 
 int MBFL_WCSPLANE_SUPMAX ; 
 int MBFL_WCSPLANE_SUPMIN ; 
 int MBFL_WCSPLANE_UCS2MAX ; 
 int /*<<< orphan*/  mbfl_filt_conv_illegal_output (int,TYPE_1__*) ; 
 int* mbfl_utf7imap_base64_table ; 
 int /*<<< orphan*/  stub1 (int,TYPE_1__*) ; 
 int /*<<< orphan*/  stub10 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub11 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub12 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub13 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub14 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub15 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub16 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub17 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub18 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub19 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int,TYPE_1__*) ; 
 int /*<<< orphan*/  stub20 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub21 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub22 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub23 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub24 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub7 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub8 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub9 (int,int /*<<< orphan*/ ) ; 

int mbfl_filt_conv_wchar_utf7imap(int c, mbfl_convert_filter *filter)
{
	int n, s;

	n = 0;
	if (c == 0x26) {
		n = 1;
	} else if ((c >= 0x20 && c <= 0x7e) || c == 0) {
		n = 2;
	} else if (c >= 0 && c < MBFL_WCSPLANE_UCS2MAX) {
		;
	} else if (c >= MBFL_WCSPLANE_SUPMIN && c < MBFL_WCSPLANE_SUPMAX) {
		s = ((c >> 10) - 0x40) | 0xd800;
		CK((*filter->filter_function)(s, filter));
		s = (c & 0x3ff) | 0xdc00;
		CK((*filter->filter_function)(s, filter));
		return c;
	} else {
		CK(mbfl_filt_conv_illegal_output(c, filter));
		return c;
	}

	switch (filter->status) {
	case 0:
		if (n != 0) {	/* directly encode characters */
			CK((*filter->output_function)(c, filter->data));
			if (n == 1) {
				CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			}
		} else {	/* Modified Base64 */
			CK((*filter->output_function)(0x26, filter->data));		/* '&' */
			filter->status = 1;
			filter->cache = c;
		}
		break;

	/* encode Modified Base64 */
	case 1:
		s = filter->cache;
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 10) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 4) & 0x3f], filter->data));
		if (n != 0) {
			CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s << 2) & 0x3c], filter->data));
			CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			CK((*filter->output_function)(c, filter->data));
			if (n == 1) {
				CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			}
			filter->status = 0;
		} else {
			filter->status = 2;
			filter->cache = ((s & 0xf) << 16) | c;
		}
		break;

	case 2:
		s = filter->cache;
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 14) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 8) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 2) & 0x3f], filter->data));
		if (n != 0) {
			CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s << 4) & 0x30], filter->data));
			CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			CK((*filter->output_function)(c, filter->data));
			if (n == 1) {
				CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			}
			filter->status = 0;
		} else {
			filter->status = 3;
			filter->cache = ((s & 0x3) << 16) | c;
		}
		break;

	case 3:
		s = filter->cache;
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 12) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 6) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[s & 0x3f], filter->data));
		if (n != 0) {
			CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			CK((*filter->output_function)(c, filter->data));
			if (n == 1) {
				CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			}
			filter->status = 0;
		} else {
			filter->status = 1;
			filter->cache = c;
		}
		break;

	default:
		filter->status = 0;
		break;
	}

	return c;

}