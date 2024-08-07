/* **************************************************** */
/*!
   @file	MN_DMD_Driver.h
   @brief	Panasonic Demodulator Driver
   @author	R.Mori
   @date	2011/6/30
   @param
		(c)	Panasonic
   */
/* **************************************************** */


#ifndef MN_DMD_DRIVER_H
#define MN_DMD_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/* **************************************************** */
/* types */
/* **************************************************** */

#include "MN_DMD_types.h"
	
/* **************************************************** */
/* Defines */
/* **************************************************** */
#define DMD_INFORMATION_MAX	512
#define DMD_INFO_VALUE_MAX	32

/* DEMOD type setting */
//< DEMOD_TYPE >
#define DMD_TYPE_MN88471 (1) //same as Chipid
#define DMD_TYPE_MN88472 (2) //same as Chipid
#define DMD_TYPE_MN88473 (3) //same as Chipid

//< TUNER_I2C_MODE >
#define TUNER_CONTROL_BY_SOC (1)
#define TUNER_CONTROL_BY_DEMOD (2)


/* Tuner I2C controlled by Demod, Demod's communication method */
//< DEMOD_CONTROL_TUNER_I2C_MODE >
#define TCB_I2C_FORMAT_REPEAT_MODE (1)// default, SoC need write bytes to certain register of demod, to communicate with Tuner indirectly
#define TCB_I2C_FORMAT_BYPASS_MODE (2)// only valid for MN88473. demod is like door, open or close, when set it open, SoC can communicate with Tuner directly.


/* Tuner type setting */
//< TUNER_TYPE>
#define MXL603 (1)
#define SI2148 (2)
#define NMI120 (3)
#define NXP18250B (4)
#define RDA5880P (5)
#define MXL301 (6)
#define NXP18275 (7)


/* --- XTAL Freq. of DMD--- [Need adjust DMD register for different XTAL and  IF]*/
//<XTAL_FREQ>
#define DMD_XTAL20480KHZ_IF5MHZ 1
#define DMD_XTAL24000KHZ_IF5MHZ 2
#define DMD_XTAL20500KHZ_IF5MHZ 3
#define DMD_XTAL25000KHZ_IF5MHZ 4 //20131220, added CONFIG for MN88473

/* **************************************************** */
/* DMD Enums */
/* **************************************************** */
/*! SYSTEM Enum */
typedef enum {
	DMD_E_ISDBT=0,
	DMD_E_ISDBS,
	DMD_E_DVBT,
	DMD_E_DVBT2,
	DMD_E_DVBC,
	DMD_E_DVBC2,
	DMD_E_ATSC,
	DMD_E_QAMB_64QAM,
	DMD_E_QAMB_256QAM,
	DMD_E_QAMC_64QAM,
	DMD_E_QAMC_256QAM,
	DMD_E_ISDBT_BRAZIL,
	DMD_E_ANALOG,
	DMD_E_NTSC_M_BTSC,
	DMD_E_PAL_M_BTSC,
	DMD_E_PAL_N_BTSC,
	DMD_E_PAL_B_G_NICAM,
	DMD_E_PAL_I_NiCAM,
	DMD_E_PAL_D_NiCAM,
	DMD_E_PAL_B_G_A2,
	DMD_E_SECAM_L_NiCAM,
	DMD_E_SECAM_L1_NiCAM,
	DMD_E_SECAM_D_K_A2,
	DMD_E_SECAM_BG_NICAM,
	DMD_E_END_OF_SYSTEM,
	DMD_E_NOT_DEFINED,
} DMD_SYSTEM_t;

/* RF Frequency Unit */
typedef enum 
{
	DMD_E_MHZ,
	DMD_E_KHZ,
	DMD_E_HZ
} DMD_FREQ_UNIT_t;

/*! Lock Status */
typedef enum {
	DMD_E_LOCKED = 0,
	DMD_E_LOCK_NOSIGNAL,
	DMD_E_LOCK_NOSYNC,
	DMD_E_LOCK_ERROR
} DMD_LOCK_STATUS_t;

/*! Return Value for API Functions */
typedef enum {
	DMD_E_OK    = 0,
	DMD_E_ERROR = 1
} DMD_ERROR_t;

/*! BAND WIDTH */
typedef enum {
	DMD_E_BW_NOT_SPECIFIED = 0,
	DMD_E_BW_6MHZ,
	DMD_E_BW_7MHZ,
	DMD_E_BW_8MHZ,
	DMD_E_BW_5MHZ,
	DMD_E_BW_1_7MHZ,
	DMD_E_BW_END_OF_BW
} DMD_BANDWIDTH_t;


/* '11/08/29 : OKAMOTO	Select TS output. */
typedef enum {
	DMD_E_TSOUT_PARALLEL_FIXED_CLOCK = 0,
	DMD_E_TSOUT_PARALLEL_VARIABLE_CLOCK,
	DMD_E_TSOUT_SERIAL_VARIABLE_CLOCK,
	DMD_E_TSOUT_SERIAL_FIXED_CLOCK, //20131211. MN88473 : Serial clock fixed at 75 Mhz, if TS rate not reach 75mbps, output null packet
} DMD_TSOUT;

typedef enum {
	DMD_E_DVBT2_BASE = 0,
	DMD_E_DVBT2_LITE = 1,
	DMD_E_DVBT2_UNDEFINED
} DMD_DVBT2_PROFILE_TYPE;//20131219, added to support T2_Lite profile, for MN88473

/* 20121225 : Troy, User scan sample */
typedef enum {
	DMD_E_SCAN_INVALID = 0,
	DMD_E_SCAN_GET_CHANNEL_INFO,    // lock RF channel, then get PLP info. 
	DMD_E_SCAN_SET_CHANNEL_PLP_ID  // to find one SERVICE(programme stream), based on stored RF channel & PLP ID 
} DMD_SCAN_t;

/* 2012130123 : Troy, power mode selection */
typedef enum
{
   DMD_PWR_MODE_NORMAL	= 0,		/* default */
   DMD_PWR_MODE_STANDBY,			/* all blocks in standby, i2c, clock running, arouse by register set */
   DMD_PWR_MODE_SLEEP,	      /* i2c,clock stop, hardware reset needed */
   DMD_PWR_MODE_UNKNOWN
} DMD_PWR_MODE_t;

/* **************************************************** */
/* DMD Structures */
/* **************************************************** */
/*! DMD Parameter Sturcture */
typedef struct {
	DMD_u32_t				devid;					//!<DeviceID
	DMD_SYSTEM_t			system;					//!<Broadcast System
	DMD_u32_t				freq;					//!<RF Frequency
	DMD_FREQ_UNIT_t			funit;					//!<RF Frequency unit
	DMD_BANDWIDTH_t			bw;						//!<Band width
	DMD_u32_t				ddradr;					//!<DDR memory address
	DMD_u32_t	info[DMD_INFORMATION_MAX];			//!<Demodulator Information
    /* '11/08/29 : OKAMOTO	Select TS output. */
	DMD_TSOUT	ts_out;
	DMD_DVBT2_PROFILE_TYPE t2_profile_type;
	
} DMD_PARAMETER_t;

/* **************************************************** */
/* Public Functions */
/* **************************************************** */
/* API&LSI control Functions */
																		

/* these function is defined by MN_DMD_Driver.c */
extern DMD_ERROR_t DMD_API DMD_open			(  DMD_PARAMETER_t* param);
extern DMD_ERROR_t DMD_API DMD_set_devid	(   DMD_PARAMETER_t* param , DMD_u32_t id);
extern DMD_ERROR_t DMD_API DMD_init			(   DMD_PARAMETER_t* param);
extern DMD_ERROR_t DMD_API DMD_set_system	(   DMD_PARAMETER_t* param );
extern DMD_ERROR_t DMD_API DMD_tune			(   DMD_PARAMETER_t* param);
extern DMD_ERROR_t DMD_API DMD_scan			(   DMD_PARAMETER_t* param);
extern DMD_ERROR_t DMD_API DMD_reset		(   DMD_PARAMETER_t* param);
extern DMD_ERROR_t DMD_API DMD_term			(   DMD_PARAMETER_t* param);
extern DMD_ERROR_t DMD_API DMD_get_info		(   DMD_PARAMETER_t* param , DMD_u32_t id );
extern DMD_ERROR_t DMD_API DMD_set_info		(   DMD_PARAMETER_t* param , DMD_u32_t id , DMD_u32_t val);
extern DMD_ERROR_t DMD_API DMD_close		(   DMD_PARAMETER_t* param);

/* Function used to calculate SSI */ //troy.wangyx added, 20121205, Based on Nordig 2.3, chapter 3.4.4.6 Requirements for the signal strength indicator (SSI)
extern int Get_RF_T2_REF_PWR(  DMD_PARAMETER_t * param);
extern int Get_RF_T_REF_PWR(  DMD_PARAMETER_t * param);
extern int Calc_T_SSI(  DMD_PARAMETER_t * param);
extern int Calc_T2_SSI(  DMD_PARAMETER_t * param);

/* Floating Functions */
// To use  , define DMD_FLOATING_FUNCTION
extern DMD_float_t DMD_API DMD_get_ber(   DMD_PARAMETER_t* param );
extern DMD_float_t DMD_API DMD_get_per(   DMD_PARAMETER_t* param );
extern DMD_float_t DMD_API DMD_get_cnr(   DMD_PARAMETER_t* param );

/* Get Infomation String */
extern DMD_text_t DMD_API DMD_info_title(  DMD_SYSTEM_t sys , DMD_u32_t info_id );
extern DMD_text_t DMD_API DMD_info_value( DMD_SYSTEM_t sys , DMD_u32_t info_id , DMD_u32_t value);
extern DMD_text_t DMD_API DMD_value_text(  DMD_PARAMETER_t* param , DMD_u32_t id );

/* **************************************************** */
/* DMD Information */
/* **************************************************** */
/*! common information enum */
typedef	enum	{	DMD_E_INFO_ALL	=0	,	
			DMD_E_INFO_REGREV	=1	,	
			DMD_E_INFO_PSEQREV	=2	,	
			DMD_E_INFO_SYSTEM	=3	,	
			DMD_E_INFO_LOCK	=4	,	
			DMD_E_INFO_AGC	=5	,	
			DMD_E_INFO_BERRNUM	=6	,	
			DMD_E_INFO_BITNUM	=7	,	
			DMD_E_INFO_CNR_INT	=8	,	
			DMD_E_INFO_CNR_DEC	=9	,	
			DMD_E_INFO_PERRNUM	=10	,	
			DMD_E_INFO_PACKETNUM	=11	,	
			DMD_E_INFO_STATUS	=12	,
			DMD_E_INFO_ERRORFREE = 13,
			DMD_E_INFO_SQI = 14, //troy.wangyx, 20140211, for upper layer to call it in uniform, no need separately.
			DMD_E_INFO_COMMON_END_OF_INFORMATION
}	
	DMD_INFO_t;
/*! DVBT information enum */
typedef	enum	{	
			DMD_E_INFO_DVBT_ALL	=0	,	
			DMD_E_INFO_DVBT_REGREV	=1	,	
			DMD_E_INFO_DVBT_PSEQRV	=2	,
			DMD_E_INFO_DVBT_SYSTEM	=3	,
			DMD_E_INFO_DVBT_LOCK	=4	,
			DMD_E_INFO_DVBT_AGC	=5	,
			DMD_E_INFO_DVBT_BERRNUM	=6	,
			DMD_E_INFO_DVBT_BITNUM	=7	,
			DMD_E_INFO_DVBT_CNR_INT	=8	,
			DMD_E_INFO_DVBT_CNR_DEC	=9	,
			DMD_E_INFO_DVBT_PERRNUM	=10	,
			DMD_E_INFO_DVBT_PACKETNUM	=11	,
			DMD_E_INFO_DVBT_STATUS = 12,
			DMD_E_INFO_DVBT_ERRORFREE	,
			DMD_E_INFO_DVBT_SQI	,
			DMD_E_INFO_DVBT_HIERARCHY_SELECT		,
			DMD_E_INFO_DVBT_TPS_ALL		,
			DMD_E_INFO_DVBT_MODE		,
			DMD_E_INFO_DVBT_GI		,
			DMD_E_INFO_DVBT_LENGTH_INDICATOR		,
			DMD_E_INFO_DVBT_CONSTELLATION		,
			DMD_E_INFO_DVBT_HIERARCHY	,
			DMD_E_INFO_DVBT_HP_CODERATE		,
			DMD_E_INFO_DVBT_LP_CODERATE		,
			DMD_E_INFO_DVBT_CELLID	,
			DMD_E_INFO_DVBT_END_OF_INFORMATION
		}	DMD_INFO_DVBT_t;
/*! DVBT2 information enum */
typedef	enum	{	DMD_E_INFO_DVBT2_ALL	=0	,	
			DMD_E_INFO_DVBT2_REGREV	=1	,	
			DMD_E_INFO_DVBT2_PSEQRV	=2	,
			DMD_E_INFO_DVBT2_SYSTEM	=3	,
			DMD_E_INFO_DVBT2_LOCK	=4	,
			DMD_E_INFO_DVBT2_AGC	=5	,
			DMD_E_INFO_DVBT2_BERRNUM	=6	,
			DMD_E_INFO_DVBT2_BITNUM	=7	,
			DMD_E_INFO_DVBT2_CNR_INT	=8	,
			DMD_E_INFO_DVBT2_CNR_DEC	=9	,
			DMD_E_INFO_DVBT2_PERRNUM	=10	,
			DMD_E_INFO_DVBT2_PACKETNUM	=11	,
			DMD_E_INFO_DVBT2_STATUS	=12,
			DMD_E_INFO_DVBT2_ERRORFREE,
			DMD_E_INFO_DVBT2_SQI,
			DMD_E_INFO_DVBT2_MODE,
			DMD_E_INFO_DVBT2_GI,
			DMD_E_INFO_DVBT2_BERRNUM_C,
			DMD_E_INFO_DVBT2_BITNUM_C,
			DMD_E_INFO_DVBT2_SELECTED_PLP,
			DMD_E_INFO_DVBT2_L1_ALL,
			DMD_E_INFO_DVBT2_TYPE,
			DMD_E_INFO_DVBT2_BW_EXT,
			DMD_E_INFO_DVBT2_S1,
			DMD_E_INFO_DVBT2_S2,
			DMD_E_INFO_DVBT2_PAPR,
			DMD_E_INFO_DVBT2_L1_MOD,
			DMD_E_INFO_DVBT2_L1_COD,
			DMD_E_INFO_DVBT2_L1_FEC_TYPE,
			DMD_E_INFO_DVBT2_L1_POST_SIZE,
			DMD_E_INFO_DVBT2_L1_POST_INFO_SIZE,
			DMD_E_INFO_DVBT2_PILOT_PATTERN,
			DMD_E_INFO_DVBT2_TX_ID_AVAILABILITY,
			DMD_E_INFO_DVBT2_CELL_ID,
			DMD_E_INFO_DVBT2_NETWORK_ID,
			DMD_E_INFO_DVBT2_T2_SYSTEM_ID,
			DMD_E_INFO_DVBT2_NUM_T2_FRAMES,
			DMD_E_INFO_DVBT2_NUM_DATA_SYMBOLS,
			DMD_E_INFO_DVBT2_REGEN_FLAG,
			DMD_E_INFO_DVBT2_L1_POST_EXTENSION,
			DMD_E_INFO_DVBT2_NUM_RF,
			DMD_E_INFO_DVBT2_CURRENT_RF_IDX,
			DMD_E_INFO_DVBT2_SUB_SLICES_PER_FRAME,
			DMD_E_INFO_DVBT2_SUB_SLICE_INTERVAL,
			DMD_E_INFO_DVBT2_NUM_PLP,
			DMD_E_INFO_DVBT2_NUM_AUX,
			DMD_E_INFO_DVBT2_PLP_MODE,
			DMD_E_INFO_DVBT2_FEF_TYPE,
			DMD_E_INFO_DVBT2_FEF_LENGTH,
			DMD_E_INFO_DVBT2_FEF_INTERVAL,
			DMD_E_INFO_DVBT2_DAT_PLP_ID,
			DMD_E_INFO_DVBT2_DAT_PLP_TYPE,
			DMD_E_INFO_DVBT2_DAT_PLP_PAYLOAD_TYPE,
			DMD_E_INFO_DVBT2_DAT_PLP_GROUP_ID,
			DMD_E_INFO_DVBT2_DAT_PLP_COD,
			DMD_E_INFO_DVBT2_DAT_PLP_MOD,
			DMD_E_INFO_DVBT2_DAT_PLP_ROTATION,
			DMD_E_INFO_DVBT2_DAT_PLP_FEC_TYPE,
			DMD_E_INFO_DVBT2_DAT_PLP_NUM_BLOCKS_MAX,
			DMD_E_INFO_DVBT2_DAT_PLP_FRAME_INTEVAL,
			DMD_E_INFO_DVBT2_DAT_PLP_TIME_IL_LENGTH,
			DMD_E_INFO_DVBT2_DAT_PLP_TIME_IL_TYPE,
			DMD_E_INFO_DVBT2_DAT_FF_FLAG,
			DMD_E_INFO_DVBT2_COM_PLP_ID,
			DMD_E_INFO_DVBT2_COM_PLP_TYPE,
			DMD_E_INFO_DVBT2_COM_PLP_PAYLOAD_TYPE,
			DMD_E_INFO_DVBT2_COM_PLP_GROUP_ID,
			DMD_E_INFO_DVBT2_COM_PLP_COD,
			DMD_E_INFO_DVBT2_COM_PLP_MOD,
			DMD_E_INFO_DVBT2_COM_PLP_ROTATION,
			DMD_E_INFO_DVBT2_COM_PLP_FEC_TYPE,
			DMD_E_INFO_DVBT2_COM_PLP_NUM_BLOCKS_MAX,
			DMD_E_INFO_DVBT2_COM_PLP_FRAME_INTEVAL,
			DMD_E_INFO_DVBT2_COM_PLP_TIME_IL_LENGTH,
			DMD_E_INFO_DVBT2_COM_PLP_TIME_IL_TYPE,
			DMD_E_INFO_DVBT2_COM_FF_FLAG,
			DMD_E_INFO_DVBT2_FRAME_IDX,
			DMD_E_INFO_DVBT2_TYPE_2_START,
			DMD_E_INFO_DVBT2_L1_CHANGE_COUNTER,
			DMD_E_INFO_DVBT2_START_RF_IDX,
			DMD_E_INFO_DVBT2_DAT_FIRST_RF_IDX,
			DMD_E_INFO_DVBT2_DAT_PLP_START,
			DMD_E_INFO_DVBT2_DAT_PLP_NUM_BLOCKS,
			DMD_E_INFO_DVBT2_COM_FIRST_RF_IDX,
			DMD_E_INFO_DVBT2_COM_PLP_START,
			DMD_E_INFO_DVBT2_COM_PLP_NUM_BLOCKS,
			DMD_E_INFO_DVBT2_STATIC_FLAG,
			DMD_E_INFO_DVBT2_STATIC_PADDING_FLAG,
			DMD_E_INFO_DVBT2_IN_BAND_A_FLAG,
			DMD_E_INFO_DVBT2_IN_BAND_B_FLAG,
			DMD_E_INFO_DVBT2_L1_POST_SCRAMBLE_ENABLED_FLG, //20131219, add for indicator of L1_POST_SCRAMBLE, for MN88473
			DMD_E_INFO_DVBT2_END_OF_INFORMATION
	} DMD_INFO_DVBT2_t;
/*! DVBC information enum */
typedef	enum	{	
			DMD_E_INFO_DVBC_ALL	=0	,	
			DMD_E_INFO_DVBC_REGREV	=1	,	
			DMD_E_INFO_DVBC_PSEQRV	=2	,
			DMD_E_INFO_DVBC_SYSTEM	=3	,
			DMD_E_INFO_DVBC_LOCK	=4	,
			DMD_E_INFO_DVBC_AGC	=5	,
			DMD_E_INFO_DVBC_BERRNUM	=6	,
			DMD_E_INFO_DVBC_BITNUM	=7	,
			DMD_E_INFO_DVBC_CNR_INT	=8	,
			DMD_E_INFO_DVBC_CNR_DEC	=9	,
			DMD_E_INFO_DVBC_PERRNUM	=10	,
			DMD_E_INFO_DVBC_PACKETNUM	=11	,
			DMD_E_INFO_DVBC_STATUS	=12	,
			DMD_E_INFO_DVBC_ERRORFREE = 13,
			DMD_E_INFO_DVBC_SQI = 14, //20130418,troy.wang added, DVBC SQI calculation, as it's has no SPEC to obey, and the coding method(conventional + RS) is same as DVB-T, so the arithmetic is same as DVB-T. 
			DMD_E_INFO_DVBC_CONSTELLATION = 15,//20130418,troy.wang added for SQI calculation.
			DMD_E_INFO_DVBC_SYMBOL_RATE = 16, //20130507,troy.wang added
			DMD_E_INFO_DVBC_END_OF_INFORMATION
		} DMD_INFO_DVBC_t;
/*! ISDBT information enum */
typedef	enum	{	DMD_E_INFO_ISDBT_ALL	=0	,	
			DMD_E_INFO_ISDBT_REGREV	=1	,	
			DMD_E_INFO_ISDBT_PSEQRV	=2	,
			DMD_E_INFO_ISDBT_SYSTEM	=3	,
			DMD_E_INFO_ISDBT_LOCK	=4	,
			DMD_E_INFO_ISDBT_AGC	=5	,
			DMD_E_INFO_ISDBT_BERRNUM	=6	,
			DMD_E_INFO_ISDBT_BITNUM	=7	,
			DMD_E_INFO_ISDBT_CNR_INT	=8	,
			DMD_E_INFO_ISDBT_CNR_DEC	=9	,
			DMD_E_INFO_ISDBT_PERRNUM	=10	,
			DMD_E_INFO_ISDBT_PACKETNUM	=11	,
			DMD_E_INFO_ISDBT_STATUS	=12	,
			DMD_E_INFO_ISDBT_ERRORFREE = 13,
			DMD_E_INFO_ISDBT_BERRNUM_A	,
			DMD_E_INFO_ISDBT_BITNUM_A	,
			DMD_E_INFO_ISDBT_BERRNUM_B	,
			DMD_E_INFO_ISDBT_BITNUM_B	,
			DMD_E_INFO_ISDBT_BERRNUM_C	,
			DMD_E_INFO_ISDBT_BITNUM_C	,
			DMD_E_INFO_ISDBT_ERRORFREE_A	,
			DMD_E_INFO_ISDBT_ERRORFREE_B	,
			DMD_E_INFO_ISDBT_ERRORFREE_C	,
			DMD_E_INFO_ISDBT_MODE	,
			DMD_E_INFO_ISDBT_GI	,
			DMD_E_INFO_ISDBT_SYS_TMCC	,
			DMD_E_INFO_ISDBT_COUNTDOWN	,
			DMD_E_INFO_ISDBT_EMGFLG	,
			DMD_E_INFO_ISDBT_PART	,
			DMD_E_INFO_ISDBT_MAPA	,
			DMD_E_INFO_ISDBT_CRA	,
			DMD_E_INFO_ISDBT_INTA	,
			DMD_E_INFO_ISDBT_SEGA	,
			DMD_E_INFO_ISDBT_MAPB	,
			DMD_E_INFO_ISDBT_CRB	,
			DMD_E_INFO_ISDBT_INTB	,
			DMD_E_INFO_ISDBT_SEGB	,
			DMD_E_INFO_ISDBT_MAPC	,
			DMD_E_INFO_ISDBT_CRC	,
			DMD_E_INFO_ISDBT_INTC	,
			DMD_E_INFO_ISDBT_SEGC	,
			DMD_E_INFO_ISDBT_PHCOR	,
			DMD_E_INFO_ISDBT_END_OF_INFORMATION
		} DMD_INFO_ISDBT_t;
/*! ISDBS information enum */
typedef	enum	{	DMD_E_INFO_ISDBS_ALL	=0	,	
			DMD_E_INFO_ISDBS_REGREV	=1	,	
			DMD_E_INFO_ISDBS_PSEQRV	=2	,
			DMD_E_INFO_ISDBS_SYSTEM	=3	,
			DMD_E_INFO_ISDBS_LOCK	=4	,
			DMD_E_INFO_ISDBS_AGC	=5	,
			DMD_E_INFO_ISDBS_BERRNUM	=6	,
			DMD_E_INFO_ISDBS_BITNUM	=7	,
			DMD_E_INFO_ISDBS_CNR_INT	=8	,
			DMD_E_INFO_ISDBS_CNR_DEC	=9	,
			DMD_E_INFO_ISDBS_PERRNUM	=10	,
			DMD_E_INFO_ISDBS_PACKETNUM	=11	,
			DMD_E_INFO_ISDBS_STATUS	=12	,
			DMD_E_INFO_ISDBS_ERRORFREE = 13,
			DMD_E_INFO_ISDBS_BERRNUM_1	,
			DMD_E_INFO_ISDBS_BITNUM_1	,
			DMD_E_INFO_ISDBS_BERRNUM_2	,
			DMD_E_INFO_ISDBS_BITNUM_2	,
			DMD_E_INFO_ISDBS_BERRNUM_3	,
			DMD_E_INFO_ISDBS_BITNUM_3	,
			DMD_E_INFO_ISDBS_ERRORFREE_0	,
			DMD_E_INFO_ISDBS_ERRORFREE_1	,
			DMD_E_INFO_ISDBS_ERRORFREE_2	,
			DMD_E_INFO_ISDBS_ERRORFREE_3	,
			DMD_E_INFO_ISDBS_ERRORFREE_T	,
			DMD_E_INFO_ISDBS_TSNO	,
			DMD_E_INFO_ISDBS_TSID	,
			DMD_E_INFO_ISDBS_MOD	,
			DMD_E_INFO_ISDBS_EMGSW	,
			DMD_E_INFO_ISDBS_UPLINK	,
			DMD_E_INFO_ISDBS_EXON	,
			DMD_E_INFO_ISDBS_CHANGE	,
			DMD_E_INFO_ISDBS_MOD0	,
			DMD_E_INFO_ISDBS_SLOT0	,
			DMD_E_INFO_ISDBS_MOD1	,
			DMD_E_INFO_ISDBS_SLOT1	,
			DMD_E_INFO_ISDBS_MOD2	,
			DMD_E_INFO_ISDBS_SLOT2	,
			DMD_E_INFO_ISDBS_MOD3	,
			DMD_E_INFO_ISDBS_SLOT3	,
			DMD_E_INFO_ISDBS_TSID0	,
			DMD_E_INFO_ISDBS_TSID1	,
			DMD_E_INFO_ISDBS_TSID2	,
			DMD_E_INFO_ISDBS_TSID3	,
			DMD_E_INFO_ISDBS_TSID4	,
			DMD_E_INFO_ISDBS_TSID5	,
			DMD_E_INFO_ISDBS_TSID6	,
			DMD_E_INFO_ISDBS_TSID7	,
			DMD_E_INFO_ISDBS_TSNO01	,
			DMD_E_INFO_ISDBS_TSNO02	,
			DMD_E_INFO_ISDBS_TSNO03	,
			DMD_E_INFO_ISDBS_TSNO04	,
			DMD_E_INFO_ISDBS_TSNO05	,
			DMD_E_INFO_ISDBS_TSNO06	,
			DMD_E_INFO_ISDBS_TSNO07	,
			DMD_E_INFO_ISDBS_TSNO08	,
			DMD_E_INFO_ISDBS_TSNO09	,
			DMD_E_INFO_ISDBS_TSNO10	,
			DMD_E_INFO_ISDBS_TSNO11	,
			DMD_E_INFO_ISDBS_TSNO12	,
			DMD_E_INFO_ISDBS_TSNO13	,
			DMD_E_INFO_ISDBS_TSNO14	,
			DMD_E_INFO_ISDBS_TSNO15	,
			DMD_E_INFO_ISDBS_TSNO16	,
			DMD_E_INFO_ISDBS_TSNO17	,
			DMD_E_INFO_ISDBS_TSNO18	,
			DMD_E_INFO_ISDBS_TSNO19	,
			DMD_E_INFO_ISDBS_TSNO20	,
			DMD_E_INFO_ISDBS_TSNO21	,
			DMD_E_INFO_ISDBS_TSNO22	,
			DMD_E_INFO_ISDBS_TSNO23	,
			DMD_E_INFO_ISDBS_TSNO24	,
			DMD_E_INFO_ISDBS_TSNO25	,
			DMD_E_INFO_ISDBS_TSNO26	,
			DMD_E_INFO_ISDBS_TSNO27	,
			DMD_E_INFO_ISDBS_TSNO28	,
			DMD_E_INFO_ISDBS_TSNO29	,
			DMD_E_INFO_ISDBS_TSNO30	,
			DMD_E_INFO_ISDBS_TSNO31	,
			DMD_E_INFO_ISDBS_TSNO32	,
			DMD_E_INFO_ISDBS_TSNO33	,
			DMD_E_INFO_ISDBS_TSNO34	,
			DMD_E_INFO_ISDBS_TSNO35	,
			DMD_E_INFO_ISDBS_TSNO36	,
			DMD_E_INFO_ISDBS_TSNO37	,
			DMD_E_INFO_ISDBS_TSNO38	,
			DMD_E_INFO_ISDBS_TSNO39	,
			DMD_E_INFO_ISDBS_TSNO40	,
			DMD_E_INFO_ISDBS_TSNO41	,
			DMD_E_INFO_ISDBS_TSNO42	,
			DMD_E_INFO_ISDBS_TSNO43	,
			DMD_E_INFO_ISDBS_TSNO44	,
			DMD_E_INFO_ISDBS_TSNO45	,
			DMD_E_INFO_ISDBS_TSNO46	,
			DMD_E_INFO_ISDBS_TSNO47	,
			DMD_E_INFO_ISDBS_TSNO48	,
			DMD_E_INFO_ISDBS_END_OF_INFORMATION
		} DMD_INFO_ISDBS_t;

/*! ATSC information enum */
typedef	enum	{	DMD_E_INFO_ATSC_ALL	=0	,	
			DMD_E_INFO_ATSC_REGREV	=1	,	
			DMD_E_INFO_ATSC_PSEQRV	=2	,
			DMD_E_INFO_ATSC_SYSTEM	=3	,
			DMD_E_INFO_ATSC_LOCK	=4	,
			DMD_E_INFO_ATSC_AGC	=5	,
			DMD_E_INFO_ATSC_BERRNUM	=6	,
			DMD_E_INFO_ATSC_BITNUM	=7	,
			DMD_E_INFO_ATSC_CNR_INT	=8	,
			DMD_E_INFO_ATSC_CNR_DEC	=9	,
			DMD_E_INFO_ATSC_PERRNUM	=10	,
			DMD_E_INFO_ATSC_PACKETNUM	=11	,
			DMD_E_INFO_ATSC_STATUS	=12	,
			DMD_E_INFO_ATSC_ERRORFREE = 13,
			DMD_E_INFO_ATSC_END_OF_INFORMATION
		} DMD_INFO_ATSC_t;
/*! QAM information enum */
typedef	enum	{	DMD_E_INFO_QAM_ALL	=0	,	
			DMD_E_INFO_QAM_REGREV	=1	,	
			DMD_E_INFO_QAM_PSEQRV	=2	,
			DMD_E_INFO_QAM_SYSTEM	=3	,
			DMD_E_INFO_QAM_LOCK	=4	,
			DMD_E_INFO_QAM_AGC	=5	,
			DMD_E_INFO_QAM_BERRNUM	=6	,
			DMD_E_INFO_QAM_BITNUM	=7	,
			DMD_E_INFO_QAM_CNR_INT	=8	,
			DMD_E_INFO_QAM_CNR_DEC	=9	,
			DMD_E_INFO_QAM_PERRNUM	=10	,
			DMD_E_INFO_QAM_PACKETNUM	=11	,
			DMD_E_INFO_QAM_STATUS	=12	,
			DMD_E_INFO_QAM_ERRORFREE = 13,
			DMD_E_INFO_QAM_END_OF_INFORMATION
		} DMD_INFO_QAM_t;
/*! ANALOG information enum */
typedef	enum	{	DMD_E_INFO_ANALOG_ALL	=0	,	
			DMD_E_INFO_ANALOG_REGREV	=1	,	
			DMD_E_INFO_ANALOG_PSEQRV	=2	,
			DMD_E_INFO_ANALOG_SYSTEM	=3	,
			DMD_E_INFO_ANALOG_LOCK	=4	,
			DMD_E_INFO_ANALOG_AGC	=5	,
			DMD_E_INFO_ANALOG_BERRNUM	=6	,
			DMD_E_INFO_ANALOG_BITNUM	=7	,
			DMD_E_INFO_ANALOG_CNR_INT	=8	,
			DMD_E_INFO_ANALOG_CNR_DEC	=9	,
			DMD_E_INFO_ANALOG_PERRNUM	=10	,
			DMD_E_INFO_ANALOG_PACKETNUM	=11	,
			DMD_E_INFO_ANALOG_STATUS	=12	,
			DMD_E_INFO_ANALOG_ERRORFREE = 13,
			DMD_E_INFO_ANALOG_END_OF_INFORMATION
		} DMD_INFO_ANALOG_t;

/*! enumulator for DVBT/DVBT2 information */
//common
typedef enum{	DMD_E_ERRORFREE_ERROR=0,	DMD_E_ERRORFREE_ERRORFREE	}	DMD_ERRORFREE_t;
//DVBC //troy added, 20130507, some customer want to show DVB-C constellation
typedef enum{	DMD_E_DVBC_CONST_64QAM=0,	DMD_E_DVBC_CONST_256QAM,	DMD_E_DVBC_CONST_128QAM, DMD_E_DVBC_CONST_32QAM, DMD_E_DVBC_CONST_16QAM, DMD_E_DVBC_CONST_NOT_DEFINED	}	DMD_DVBC_CONST_t;		
//DVBT
typedef enum{	DMD_E_DVBT_HIER_SEL_LP=0,	DMD_E_DVBT_HIER_SEL_HP	}	DMD_DVBT_HIER_SEL_t;
typedef enum{	DMD_E_DVBT_TPS_OBTAIN_NG=0,	DMD_E_DVBT_TPS_OBTAIN_OK	}	DMD_DVBT_TPS_OBTAIN_t;
typedef enum{	DMD_E_DVBT_MODE_2K=0,	DMD_E_DVBT_MODE_8K,	DMD_E_DVBT_MODE_4K , DMD_E_DVBT_MODE_NOT_DEFINED	}	DMD_DVBT_MODE_t;		
typedef enum{	DMD_E_DVBT_GI_1_32=0,	DMD_E_DVBT_GI_1_16,	DMD_E_DVBT_GI_1_8,	DMD_E_DVBT_GI_1_4 , DMD_E_DVBT_GI_NOT_DEFINED	}	DMD_DVBT_GI_t;	
typedef enum{	DMD_E_DVBT_CONST_QPSK=0,	DMD_E_DVBT_CONST_16QAM,	DMD_E_DVBT_CONST_64QAM	}	DMD_DVBT_CONST_t;		
typedef enum{	DMD_E_DVBT_HIERARCHY_NO=0,	DMD_E_DVBT_HIERARCHY_ALPHA_1,	DMD_E_DVBT_HIERARCHY_ALPHA_2,	DMD_E_DVBT_HIERARCHY_ALPHA_4	}	DMD_DVBT_HIERARCHY_t;	
typedef enum{	DMD_E_DVBT_CR_1_2=0,	DMD_E_DVBT_CR_2_3,	DMD_E_DVBT_CR_3_4,	DMD_E_DVBT_CR_5_6,	DMD_E_DVBT_CR_7_8	}	DMD_DVBT_CR_t;
    //troy.wang, 20131015 [select type -> 0 : CTA(Pre-deinterleave) ;  1 : CTA(Post-deinterleave)]
typedef enum{	DMD_E_DVBT_CONSTELLATION_MON_CTA=0,	DMD_E_DVBT_CONSTELLATION_MON_CTB	}	DMD_DVBT_CON_MON_t;


//DVBT2
typedef enum{	DMD_E_DVBT2_MODE_1K=0,	DMD_E_DVBT2_MODE_2K,	DMD_E_DVBT2_MODE_4K,	DMD_E_DVBT2_MODE_8K,	DMD_E_DVBT2_MODE_16K,	DMD_E_DVBT2_MODE_32K	}			DMD_DVBT2_MODE_t;
typedef enum{	DMD_E_DVBT2_GI_1_32=0,	DMD_E_DVBT2_GI_1_16,	DMD_E_DVBT2_GI_1_8,	DMD_E_DVBT2_GI_1_4,	DMD_E_DVBT2_GI_1_128,	DMD_E_DVBT2_GI_19_128,	DMD_E_DVBT2_GI_19_256,	}		DMD_DVBT2_GI_t;
typedef enum{	DMD_E_DVBT2_TYPE_TS=0,	DMD_E_DVBT2_TYPE_GS,	DMD_E_DVBT2_TYPE_TS_GS	}						DMD_DVBT2_TYPE_t;
typedef enum{	DMD_E_DVBT2_PAPR_NO=0,	DMD_E_DVBT2_PAPR_ACE,	DMD_E_DVBT2_PAPR_TR,	DMD_E_DVBT2_PAPR_ACE_TR	}					DMD_DVBT2_PAPR_t;
typedef enum{	DMD_E_DVBT2_L1_MOD_BPSK=0,	DMD_E_DVBT2_L1_MOD_QPSK,	DMD_E_DVBT2_L1_MOD_16QAM,	DMD_E_DVBT2_L1_MOD_64QAM	}					DMD_DVBT2_L1_MOD_t;
typedef enum{	DMD_E_DVBT2_CR_1_2=0,	DMD_E_DVBT2_CR_3_5,	DMD_E_DVBT2_CR_2_3,	DMD_E_DVBT2_CR_3_4,	DMD_E_DVBT2_CR_4_5,	DMD_E_DVBT2_CR_5_6	}			DMD_DVBT2_CR_t;

//20131219, add code rate for T2_Lite, MN88473
typedef enum{	DMD_E_DVBT2_LITE_CR_1_2=0,	DMD_E_DVBT2_LITE_CR_3_5,	DMD_E_DVBT2_LITE_CR_2_3,	DMD_E_DVBT2_LITE_CR_3_4,	DMD_E_DVBT2_LITE_CR_RESERVED_1, DMD_E_DVBT2_LITE_CR_RESERVED_2, DMD_E_DVBT2_LITE_CR_1_3, DMD_E_DVBT2_LITE_CR_2_5 }			DMD_DVBT2_LITE_CR_t;

typedef enum{	DMD_E_DVBT2_FEC_TYPE_16K=0,	DMD_E_DVBT2_FEC_TYPE_64K	}							DMD_DVBT2_FEC_TYPE_t;
typedef enum{	DMD_E_DVBT2_PP_1=0,	DMD_E_DVBT2_PP_2,	DMD_E_DVBT2_PP_3,	DMD_E_DVBT2_PP_4,	DMD_E_DVBT2_PP_5,	DMD_E_DVBT2_PP_6,	DMD_E_DVBT2_PP_7,	DMD_E_DVBT2_PP_8	}	DMD_DVBT2_PP_t;
typedef enum{	DMD_E_DVBT2_PLP_MODE_NO=0,	DMD_E_DVBT2_PLP_MODE_NORM,	DMD_E_DVBT2_PLP_MODE_HEM	}						DMD_DVBT2_PLP_MODE_t;
typedef enum{	DMD_E_DVBT2_PLP_TYPE_COM=0,	DMD_E_DVBT2_PLP_TYPE_DAT1,	DMD_E_DVBT2_PLP_TYPE_DAT2	}						DMD_DVBT2_PLP_TYPE_t;
typedef enum{	DMD_E_DVBT2_PLP_PAYLOAD_GFPS=0,	DMD_E_DVBT2_PLP_PAYLOAD_GCS,	DMD_E_DVBT2_PLP_PAYLOAD_GSE,	DMD_E_DVBT2_PLP_PAYLOAD_TS	}					DMD_DVBT2_PLP_PAYLOAD_t;
typedef enum{	DMD_E_DVBT2_PLP_MOD_QPSK=0,	DMD_E_DVBT2_PLP_MOD_16QAM,	DMD_E_DVBT2_PLP_MOD_64QAM,	DMD_E_DVBT2_PLP_MOD_256QAM	}					DMD_DVBT2_PLP_MOD_t;
//troy.wang, 20131015 [0 : data plp ;  1 : common plp;  2 : L1pre;   3 : L1post]
typedef enum{	DMD_E_DVBT2_CONSTELLATION_MON_DATA_PLP=0,	DMD_E_DVBT2_CONSTELLATION_MON_COMMON_PLP,	DMD_E_DVBT2_CONSTELLATION_MON_L1PRE,	DMD_E_DVBT2_CONSTELLATION_MON_L1POST	}	DMD_DVBT2_CON_MON_t;

//ISDBT
typedef enum{	DMD_E_ISDBT_MODE1=0,	DMD_E_ISDBT_MODE2,	DMD_E_ISDBT_MODE3	}	DMD_ISDBT_MODE_t;	
typedef	enum{	DMD_E_ISDBT_GI_1_32=0,	DMD_E_ISDBT_GI_1_16,DMD_E_ISDBT_GI_1_8,	DMD_E_ISDBT_GI_1_4	}	DMD_ISDBT_GI_t;
typedef	enum{	DMD_E_ISDBT_SYS_ISDB_T=0,DMD_E_ISDBT_SYS_ISDBT_SB	}	DMD_ISDBT_SYS_t;			
typedef	enum{	DMD_E_ISDBT_PART_NO_PART=0,	DMD_E_ISDBT_PART_PART	}	DMD_ISDBT_PART_t;	
typedef	enum{	DMD_E_ISDBT_CONST_DQPSK=0,	DMD_E_ISDBT_CONST_QPSK,	DMD_E_ISDBT_CONST_16QAM	,DMD_E_ISDBT_CONST_64QAM	}	DMD_ISDBT_CONST_t;	
typedef	enum{	DMD_E_ISDBT_CR_1_2=0,		DMD_E_ISDBT_CR_2_3,	DMD_E_ISDBT_CR_3_4,	DMD_E_ISDBT_CR_5_6,	DMD_E_ISDBT_CR_7_8	}	DMD_ISDBT_CR_t;
//ISDBS
typedef enum{	DMD_E_ISDB_S_MOD_BPSK_1_2=0,	
				DMD_E_ISDB_S_MOD_QPSK_1_2,
				DMD_E_ISDB_S_MOD_QPSK_2_3,
				DMD_E_ISDB_S_MOD_QPSK_3_4,
				DMD_E_ISDB_S_MOD_QPSK_5_6,
				DMD_E_ISDB_S_MOD_QPSK_7_8,
				DMD_E_ISDB_S_MOD_8PSK_2_3 } DMD_ISDBS_MOD_t;

#ifdef __cplusplus
}
#endif

#endif
