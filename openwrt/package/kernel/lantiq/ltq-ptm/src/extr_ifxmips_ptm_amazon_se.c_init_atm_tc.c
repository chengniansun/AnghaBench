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

/* Variables and functions */
 int /*<<< orphan*/  DREG_AR_CTRL ; 
 int /*<<< orphan*/  DREG_AR_IDLE0 ; 
 int /*<<< orphan*/  DREG_AR_IDLE1 ; 
 int /*<<< orphan*/  DREG_AT_CTRL ; 
 int /*<<< orphan*/  DREG_AT_IDLE0 ; 
 int /*<<< orphan*/  DREG_AT_IDLE1 ; 
 int /*<<< orphan*/  FFSM_CFG0 ; 
 int /*<<< orphan*/  FFSM_CFG1 ; 
 int /*<<< orphan*/  FFSM_DBA0 ; 
 int /*<<< orphan*/  FFSM_DBA1 ; 
 int /*<<< orphan*/  FFSM_IDLE_HEAD_BC0 ; 
 int /*<<< orphan*/  FFSM_IDLE_HEAD_BC1 ; 
 int /*<<< orphan*/  IFX_REG_W32 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RFBI_CFG ; 
 int /*<<< orphan*/  SFSM_CBA0 ; 
 int /*<<< orphan*/  SFSM_CBA1 ; 
 int /*<<< orphan*/  SFSM_CFG0 ; 
 int /*<<< orphan*/  SFSM_CFG1 ; 
 int /*<<< orphan*/  SFSM_DBA0 ; 
 int /*<<< orphan*/  SFSM_DBA1 ; 

__attribute__((used)) static inline void init_atm_tc(void)
{
    IFX_REG_W32(0x0F00,     DREG_AT_CTRL);
    IFX_REG_W32(0x3C00,     DREG_AR_CTRL);
    IFX_REG_W32(0x0,        DREG_AT_IDLE0);
    IFX_REG_W32(0x0,        DREG_AT_IDLE1);
    IFX_REG_W32(0x0,        DREG_AR_IDLE0);
    IFX_REG_W32(0x0,        DREG_AR_IDLE1);
    IFX_REG_W32(0x0,        RFBI_CFG);
    IFX_REG_W32(0x0200,     SFSM_DBA0);
    IFX_REG_W32(0x0800,     SFSM_DBA1);
    IFX_REG_W32(0x0321,     SFSM_CBA0);
    IFX_REG_W32(0x0921,     SFSM_CBA1);
    IFX_REG_W32(0x14011,    SFSM_CFG0);
    IFX_REG_W32(0x14011,    SFSM_CFG1);
    IFX_REG_W32(0x0332,     FFSM_DBA0);
    IFX_REG_W32(0x0932,     FFSM_DBA1);
    IFX_REG_W32(0x3000C,    FFSM_CFG0);
    IFX_REG_W32(0x3000C,    FFSM_CFG1);
    IFX_REG_W32(0xF0D10000, FFSM_IDLE_HEAD_BC0);
    IFX_REG_W32(0xF0D10000, FFSM_IDLE_HEAD_BC1);
}