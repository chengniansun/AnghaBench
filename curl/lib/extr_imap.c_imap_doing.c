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
struct connectdata {int /*<<< orphan*/  data; } ;
typedef  scalar_t__ CURLcode ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUGF (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ imap_dophase_done (struct connectdata*,int /*<<< orphan*/ ) ; 
 scalar_t__ imap_multi_statemach (struct connectdata*,int*) ; 
 int /*<<< orphan*/  infof (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static CURLcode imap_doing(struct connectdata *conn, bool *dophase_done)
{
  CURLcode result = imap_multi_statemach(conn, dophase_done);

  if(result)
    DEBUGF(infof(conn->data, "DO phase failed\n"));
  else if(*dophase_done) {
    result = imap_dophase_done(conn, FALSE /* not connected */);

    DEBUGF(infof(conn->data, "DO phase is complete\n"));
  }

  return result;
}