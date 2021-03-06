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
struct suffix_code_t {char* member_0; char* member_1; } ;

/* Variables and functions */
 char const* get_suffix_code (struct suffix_code_t const*,char const*) ; 

__attribute__((used)) static const char *
get_format_code(const char *suffix)
{
	/* A pair of suffix and format. */
	static const struct suffix_code_t formats[] = {
		{ ".7z",	"7zip" },
		{ ".ar",	"arbsd" },
		{ ".cpio",	"cpio" },
		{ ".iso",	"iso9960" },
		{ ".mtree",	"mtree" },
		{ ".shar",	"shar" },
		{ ".tar",	"paxr" },
		{ ".warc",	"warc" },
		{ ".xar",	"xar" },
		{ ".zip",	"zip" },
		{ NULL,		NULL }
	};

	return get_suffix_code(formats, suffix);
}