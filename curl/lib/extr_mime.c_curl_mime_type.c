#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/ * mimetype; } ;
typedef  TYPE_1__ curl_mimepart ;
typedef  int /*<<< orphan*/  CURLcode ;

/* Variables and functions */
 int /*<<< orphan*/  CURLE_BAD_FUNCTION_ARGUMENT ; 
 int /*<<< orphan*/  CURLE_OK ; 
 int /*<<< orphan*/  CURLE_OUT_OF_MEMORY ; 
 int /*<<< orphan*/  Curl_safefree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * strdup (char const*) ; 

CURLcode curl_mime_type(curl_mimepart *part, const char *mimetype)
{
  if(!part)
    return CURLE_BAD_FUNCTION_ARGUMENT;

  Curl_safefree(part->mimetype);
  part->mimetype = NULL;

  if(mimetype) {
    part->mimetype = strdup(mimetype);
    if(!part->mimetype)
      return CURLE_OUT_OF_MEMORY;
  }

  return CURLE_OK;
}