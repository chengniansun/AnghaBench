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
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  svn_client_ctx_t ;
typedef  int /*<<< orphan*/  svn_client_conflict_t ;
typedef  int /*<<< orphan*/  svn_client_conflict_option_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;
typedef  int /*<<< orphan*/  apr_array_header_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  add_resolution_option (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * apr_array_make (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  assert_text_conflict (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  resolve_postpone ; 
 int /*<<< orphan*/  resolve_text_conflict ; 
 int /*<<< orphan*/  svn_client_conflict_option_base_text ; 
 int /*<<< orphan*/  svn_client_conflict_option_incoming_text ; 
 int /*<<< orphan*/  svn_client_conflict_option_incoming_text_where_conflicted ; 
 int /*<<< orphan*/  svn_client_conflict_option_merged_text ; 
 int /*<<< orphan*/  svn_client_conflict_option_postpone ; 
 int /*<<< orphan*/  svn_client_conflict_option_working_text ; 
 int /*<<< orphan*/  svn_client_conflict_option_working_text_where_conflicted ; 
 char* svn_client_conflict_text_get_mime_type (int /*<<< orphan*/ *) ; 
 scalar_t__ svn_mime_type_is_binary (char const*) ; 

svn_error_t *
svn_client_conflict_text_get_resolution_options(apr_array_header_t **options,
                                                svn_client_conflict_t *conflict,
                                                svn_client_ctx_t *ctx,
                                                apr_pool_t *result_pool,
                                                apr_pool_t *scratch_pool)
{
  const char *mime_type;

  SVN_ERR(assert_text_conflict(conflict, scratch_pool));

  *options = apr_array_make(result_pool, 7,
                            sizeof(svn_client_conflict_option_t *));

  add_resolution_option(*options, conflict,
      svn_client_conflict_option_postpone,
      _("Postpone"),
      _("skip this conflict and leave it unresolved"),
      resolve_postpone);

  mime_type = svn_client_conflict_text_get_mime_type(conflict);
  if (mime_type && svn_mime_type_is_binary(mime_type))
    {
      /* Resolver options for a binary file conflict. */
      add_resolution_option(*options, conflict,
        svn_client_conflict_option_base_text,
        _("Accept base"),
        _("discard local and incoming changes for this binary file"),
        resolve_text_conflict);

      add_resolution_option(*options, conflict,
        svn_client_conflict_option_incoming_text,
        _("Accept incoming"),
        _("accept incoming version of binary file"),
        resolve_text_conflict);

      add_resolution_option(*options, conflict,
        svn_client_conflict_option_working_text,
        _("Mark as resolved"),
        _("accept binary file as it appears in the working copy"),
        resolve_text_conflict);
  }
  else
    {
      /* Resolver options for a text file conflict. */
      add_resolution_option(*options, conflict,
        svn_client_conflict_option_base_text,
        _("Accept base"),
        _("discard local and incoming changes for this file"),
        resolve_text_conflict);

      add_resolution_option(*options, conflict,
        svn_client_conflict_option_incoming_text,
        _("Accept incoming"),
        _("accept incoming version of entire file"),
        resolve_text_conflict);

      add_resolution_option(*options, conflict,
        svn_client_conflict_option_working_text,
        _("Reject incoming"),
        _("reject all incoming changes for this file"),
        resolve_text_conflict);

      add_resolution_option(*options, conflict,
        svn_client_conflict_option_incoming_text_where_conflicted,
        _("Accept incoming for conflicts"),
        _("accept changes only where they conflict"),
        resolve_text_conflict);

      add_resolution_option(*options, conflict,
        svn_client_conflict_option_working_text_where_conflicted,
        _("Reject conflicts"),
        _("reject changes which conflict and accept the rest"),
        resolve_text_conflict);

      add_resolution_option(*options, conflict,
        svn_client_conflict_option_merged_text,
        _("Mark as resolved"),
        _("accept the file as it appears in the working copy"),
        resolve_text_conflict);
    }

  return SVN_NO_ERROR;
}