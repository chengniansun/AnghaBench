#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ogg_int64_t ;
struct TYPE_8__ {scalar_t__ ready_state; int links; scalar_t__* pcmlengths; TYPE_1__* vi; int /*<<< orphan*/  seekable; } ;
struct TYPE_7__ {scalar_t__ rate; } ;
typedef  TYPE_2__ OggVorbis_File ;

/* Variables and functions */
 scalar_t__ OPENED ; 
 int OV_EINVAL ; 
 int OV_ENOSEEK ; 
 int ov_pcm_seek (TYPE_2__*,scalar_t__) ; 
 scalar_t__ ov_pcm_total (TYPE_2__*,int) ; 
 scalar_t__ ov_time_total (TYPE_2__*,int) ; 

int ov_time_seek(OggVorbis_File *vf,ogg_int64_t milliseconds){
  /* translate time to PCM position and call ov_pcm_seek */

  int link=-1;
  ogg_int64_t pcm_total=ov_pcm_total(vf,-1);
  ogg_int64_t time_total=ov_time_total(vf,-1);

  if(vf->ready_state<OPENED)return(OV_EINVAL);
  if(!vf->seekable)return(OV_ENOSEEK);
  if(milliseconds<0 || milliseconds>time_total)return(OV_EINVAL);
  
  /* which bitstream section does this time offset occur in? */
  for(link=vf->links-1;link>=0;link--){
    pcm_total-=vf->pcmlengths[link*2+1];
    time_total-=ov_time_total(vf,link);
    if(milliseconds>=time_total)break;
  }

  /* enough information to convert time offset to pcm offset */
  {
    ogg_int64_t target=pcm_total+(milliseconds-time_total)*vf->vi[link].rate/1000;
    return(ov_pcm_seek(vf,target));
  }
}