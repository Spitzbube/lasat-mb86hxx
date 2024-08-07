/*****************************************************************************/
/* Montage Technology (Shanghai) Co., Ltd                                    */
/* MONTAGE PROPRIETARY AND CONFIDENTIAL                                      */
/* Copyright (c) 2014 Montage Technology Group Limited. All Rights Reserved. */
/*****************************************************************************/

/*
 * Filename:		mt_fe_tn_tc2800.c
 *
 * Description:		Montage M88TC2800 Digital Tuner IC driver.
 *
 *
 * Author:			YZ.Huang
 *
 * Version:			3.00.31
 * Date:			2014-09-01
 ****************************************************************************/
#include "sys_types.h"
#include "mtos_misc.h"
#include "mtos_sem.h"
#include "mtos_task.h"
#include "mtos_printk.h"

#include "drv_dev.h"
#include "i2c.h"
#include "nim.h"

#include "mt_fe_i2c.h"
#include "mt_fe_tn_tc2800.h"
#include "mt_fe_def.h"

#include "nim_m88dc2800.h"
void _mt_fe_tn_set_RF_front_tc2800(MT_FE_DC2800_Device_Handle handle)
{
	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);

	const U32 freq_KHz = tuner_handle->tuner_freq;

	if (tuner_handle->tuner_mtt == 0xD1)		// D1
	{
		if (freq_KHz <= 123000)
		{
			if (freq_KHz <= 56000)
			{
				_mt_fe_tn_set_reg(handle, 0x58, 0x9b);
				_mt_fe_tn_set_reg(handle, 0x59, 0x00);
				_mt_fe_tn_set_reg(handle, 0x5d, 0x00);
				_mt_fe_tn_set_reg(handle, 0x5e, 0x00);
			}
			else if (freq_KHz <= 64000)
			{
				_mt_fe_tn_set_reg(handle, 0x58, 0x9b);
				_mt_fe_tn_set_reg(handle, 0x59, 0x10);
				_mt_fe_tn_set_reg(handle, 0x5d, 0x01);
				_mt_fe_tn_set_reg(handle, 0x5e, 0x08);
			}
			else if (freq_KHz <= 72000)
			{
				_mt_fe_tn_set_reg(handle, 0x58, 0x9b);
				_mt_fe_tn_set_reg(handle, 0x59, 0x20);
				_mt_fe_tn_set_reg(handle, 0x5d, 0x02);
				_mt_fe_tn_set_reg(handle, 0x5e, 0x10);
			}
			else if (freq_KHz <= 80000)
			{
				_mt_fe_tn_set_reg(handle, 0x58, 0x9b);
				_mt_fe_tn_set_reg(handle, 0x59, 0x30);
				_mt_fe_tn_set_reg(handle, 0x5d, 0x03);
				_mt_fe_tn_set_reg(handle, 0x5e, 0x18);
			}
			else if (freq_KHz <= 88000)
			{
				_mt_fe_tn_set_reg(handle, 0x58, 0x9b);
				_mt_fe_tn_set_reg(handle, 0x59, 0x40);
				_mt_fe_tn_set_reg(handle, 0x5d, 0x04);
				_mt_fe_tn_set_reg(handle, 0x5e, 0x20);
			}
			else if (freq_KHz <= 96000)
			{
				_mt_fe_tn_set_reg(handle, 0x58, 0x9b);
				_mt_fe_tn_set_reg(handle, 0x59, 0x50);
				_mt_fe_tn_set_reg(handle, 0x5d, 0x05);
				_mt_fe_tn_set_reg(handle, 0x5e, 0x28);
			}
			else if (freq_KHz <= 104000)
			{
				_mt_fe_tn_set_reg(handle, 0x58, 0x9b);
				_mt_fe_tn_set_reg(handle, 0x59, 0x60);
				_mt_fe_tn_set_reg(handle, 0x5d, 0x06);
				_mt_fe_tn_set_reg(handle, 0x5e, 0x30);
			}
			else //if (freq_KHz <= 112000)
			{
				_mt_fe_tn_set_reg(handle, 0x58, 0x9b);
				_mt_fe_tn_set_reg(handle, 0x59, 0x70);
				_mt_fe_tn_set_reg(handle, 0x5d, 0x07);
				_mt_fe_tn_set_reg(handle, 0x5e, 0x38);
			}

			_mt_fe_tn_set_reg(handle, 0x5a, 0x75);
			_mt_fe_tn_set_reg(handle, 0x73, 0x0c);
		}
		else //if (freq_KHz > 112000)
		{
			_mt_fe_tn_set_reg(handle, 0x58, 0x7b);

			if (freq_KHz <= 304000)
			{
				if (freq_KHz <= 136000)
				{
					_mt_fe_tn_set_reg(handle, 0x5e, 0x40);
				}
				else if (freq_KHz <= 160000)
				{
					_mt_fe_tn_set_reg(handle, 0x5e, 0x48);
				}
				else if (freq_KHz <= 184000)
				{
					_mt_fe_tn_set_reg(handle, 0x5e, 0x50);
				}
				else if (freq_KHz <= 208000)
				{
					_mt_fe_tn_set_reg(handle, 0x5e, 0x58);
				}
				else if (freq_KHz <= 232000)
				{
					_mt_fe_tn_set_reg(handle, 0x5e, 0x60);
				}
				else if (freq_KHz <= 256000)
				{
					_mt_fe_tn_set_reg(handle, 0x5e, 0x68);
				}
				else if (freq_KHz <= 280000)
				{
					_mt_fe_tn_set_reg(handle, 0x5e, 0x70);
				}
				else //if (freq_KHz <= 304000)
				{
					_mt_fe_tn_set_reg(handle, 0x5e, 0x78);
				}

				if (freq_KHz <= 171000)
				{
					_mt_fe_tn_set_reg(handle, 0x73, 0x08);
				}
				else if (freq_KHz <= 211000)
				{
					_mt_fe_tn_set_reg(handle, 0x73, 0x0a);
				}
				else
				{
					_mt_fe_tn_set_reg(handle, 0x73, 0x0e);
				}
			}
			else //if (freq_KHz > 304000)
			{
				_mt_fe_tn_set_reg(handle, 0x5e, 0x88);

				if (freq_KHz <= 400000)
				{
					_mt_fe_tn_set_reg(handle, 0x73, 0x0c);
				}
				else if (freq_KHz <= 450000)
				{
					_mt_fe_tn_set_reg(handle, 0x73, 0x09);
				}
				else if (freq_KHz <= 550000)
				{
					_mt_fe_tn_set_reg(handle, 0x73, 0x0e);
				}
				else if (freq_KHz <= 650000)
				{
					_mt_fe_tn_set_reg(handle, 0x73, 0x0d);
				}
				else //if (freq_KHz > 650000)
				{
					_mt_fe_tn_set_reg(handle, 0x73, 0x0e);
				}
			}
		}

		if (freq_KHz > 800000)
			_mt_fe_tn_set_reg(handle, 0x87, 0x24);
		else if (freq_KHz > 700000)
			_mt_fe_tn_set_reg(handle, 0x87, 0x34);
		else if (freq_KHz > 500000)
			_mt_fe_tn_set_reg(handle, 0x87, 0x44);
		else if (freq_KHz > 300000)
			_mt_fe_tn_set_reg(handle, 0x87, 0x43);
		else if (freq_KHz > 220000)
			_mt_fe_tn_set_reg(handle, 0x87, 0x54);
		else if (freq_KHz > 110000)
			_mt_fe_tn_set_reg(handle, 0x87, 0x14);
		else
			_mt_fe_tn_set_reg(handle, 0x87, 0x54);

		if (freq_KHz > 600000)
			_mt_fe_tn_set_reg(handle, 0x6a, 0x53);
		else if (freq_KHz > 500000)
			_mt_fe_tn_set_reg(handle, 0x6a, 0x57);
		else
			_mt_fe_tn_set_reg(handle, 0x6a, 0x59);

		if (freq_KHz < 200000)
		{
			_mt_fe_tn_set_reg(handle, 0x20, 0x5d);
		}
		else if (freq_KHz < 500000)
		{
			_mt_fe_tn_set_reg(handle, 0x20, 0x7d);
		}
		else
		{
			_mt_fe_tn_set_reg(handle, 0x20, 0xfd);
		}
	}	// end of 0xD1
	else if (tuner_handle->tuner_mtt == 0xE1)	// E1
	{
		if (freq_KHz <= 99000)
		{
			if (freq_KHz <= 56000)
			{
				_mt_fe_tn_set_reg(handle, 0x5c, 0x01);
			}
			else if (freq_KHz <= 64000)
			{
				_mt_fe_tn_set_reg(handle, 0x5c, 0x09);
			}
			else if (freq_KHz <= 72000)
			{
				_mt_fe_tn_set_reg(handle, 0x5c, 0x11);
			}
			else if (freq_KHz <= 80000)
			{
				_mt_fe_tn_set_reg(handle, 0x5c, 0x19);
			}
			else if (freq_KHz <= 88000)
			{
				_mt_fe_tn_set_reg(handle, 0x5c, 0x21);
			}
			else if (freq_KHz <= 96000)
			{
				_mt_fe_tn_set_reg(handle, 0x5c, 0x29);
			}
			else
			{
				_mt_fe_tn_set_reg(handle, 0x5c, 0x31);
			}

			_mt_fe_tn_set_reg(handle, 0x5b, 0x30);
		}
		else //if (freq_KHz > 112000)
		{

			if (freq_KHz <= 339000)
			{
				if (freq_KHz <= 136000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0x41);
				}
				else if (freq_KHz <= 160000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0x49);
				}
				else if (freq_KHz <= 184000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0x51);
				}
				else if (freq_KHz <= 208000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0x59);
				}
				else if (freq_KHz <= 232000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0x61);
				}
				else if (freq_KHz <= 256000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0x69);
				}
				else if (freq_KHz <= 280000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0x71);
				}
				else //if (freq_KHz <= 304000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0x79);
				}

				if (freq_KHz <= 150000)
				{
					_mt_fe_tn_set_reg(handle, 0x5b, 0x18);
				}
				else if (freq_KHz <= 256000)
				{
					_mt_fe_tn_set_reg(handle, 0x5b, 0x29);
				}
				else if (freq_KHz <= 304000)
				{
					_mt_fe_tn_set_reg(handle, 0x5b, 0x2a);
				}
				else
				{
					_mt_fe_tn_set_reg(handle, 0x5b, 0x2f);
				}
			}
			else //if (freq_KHz > 304000)
			{
				if (freq_KHz <= 400000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0x89);
				}
				else if (freq_KHz <= 450000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0x91);
				}
				else if (freq_KHz <= 650000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0x98);
				}
				else if (freq_KHz <= 850000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0xa0);
				}
				else //if (freq_KHz > 850000)
				{
					_mt_fe_tn_set_reg(handle, 0x5c, 0xa8);
				}

				_mt_fe_tn_set_reg(handle, 0x5b, 0x08);
			}
		}
	}	// end of 0xE1

	return;
}


void _mt_fe_tn_fraction_calc_tc2800(S32 *pDataN, S32 *pDataF)
{
	if (*pDataF >= 59)
	{
		*pDataF = 0;
		*pDataN = *pDataN + 2;
	}
	else if (*pDataF > 53)
	{
		*pDataF = 56;
	}
	else if (*pDataF > 44)
	{
		*pDataF = 48;
	}
	else if (*pDataF > 36)
	{
		*pDataF = 40;
	}
	else if (*pDataF > 28)
	{
		*pDataF = 32;
	}
	else if (*pDataF > 20)
	{
		*pDataF = 24;
	}
	else if (*pDataF >= 11)
	{
		*pDataF = 16;
	}
	else if (*pDataF > 5)
	{
		*pDataF = 8;
	}
	else// if (*pDataF > 0)
	{
		*pDataF = 0;
	}

	return;
}


void _mt_fe_tn_cali_PLL_tc2800(MT_FE_DC2800_Device_Handle handle, U32 freq_KHz, U32 cali_freq_thres_div2, U32 cali_freq_thres_div3r, U32 cali_freq_thres_div3)
{
	S32	N, F, MUL;
	U8 buf, tmp, tmp2;

	S32 iLoop = 0;

	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);
	S32 M;
	const U32 crystal_KHz = tuner_handle->tuner_crystal;
	U32 PLLfreq01 = 0;


	if (tuner_handle->tuner_mtt == 0xD1)
	{
		M = tuner_handle->tuner_crystal / 4000;

		if (freq_KHz > cali_freq_thres_div2)
		{
			MUL = 4;
			tmp = 2;
		}
		else if (freq_KHz > 300000)
		{
			MUL = 8;
			tmp = 3;
		}
		else if (freq_KHz > (cali_freq_thres_div2 / 2))
		{
			MUL = 8;
			tmp = 4;
		}
		else if (freq_KHz > (cali_freq_thres_div2 / 4))
		{
			MUL = 16;
			tmp = 5;
		}
		else if (freq_KHz > (cali_freq_thres_div2 / 8))
		{
			MUL = 32;
			tmp = 6;
		}
		else if (freq_KHz > (cali_freq_thres_div2 / 16))
		{
			MUL = 64;
			tmp = 7;
		}
		else	// invalid
		{
			MUL = 0;
			tmp = 0;

			return;
		}

		N = (freq_KHz * MUL * M / crystal_KHz) / 2 * 2 - 256;
		F = (freq_KHz / 10 * 64 * MUL * M / (crystal_KHz  / 10) / 2) % 64;
	}
	else if (tuner_handle->tuner_mtt == 0xE1)
	{
		M = tuner_handle->tuner_crystal / 1000;

		_mt_fe_tn_set_reg(handle, 0x30, 0xff);
		_mt_fe_tn_set_reg(handle, 0x32, 0xe0);
		_mt_fe_tn_set_reg(handle, 0x33, 0x86);
		_mt_fe_tn_set_reg(handle, 0x34, 0xc0);
		_mt_fe_tn_set_reg(handle, 0x37, 0x70);
		_mt_fe_tn_set_reg(handle, 0x38, 0x20);
		_mt_fe_tn_set_reg(handle, 0x39, 0x18);
		_mt_fe_tn_set_reg(handle, 0x89, 0x83);

		if (freq_KHz > cali_freq_thres_div2)
		{
			M = M / 4;
			MUL = 4;
			tmp = 2;
			tmp2 = M + 16; //48
		}
		else if (freq_KHz > cali_freq_thres_div3r)
		{
			M = M / 3;
			MUL = 6;
			tmp = 2;
			tmp2 = M + 32; //32
		}
		else if (freq_KHz > cali_freq_thres_div3)
		{
			M = M / 3;
			MUL = 6;
			tmp = 2;
			tmp2 = M; //16
		}
		else if (freq_KHz > 339000)
		{
			M = M / 4;
			MUL = 8;
			tmp = 3;
			tmp2 = M + 16; //48
		}
		else if (freq_KHz > (cali_freq_thres_div2 / 2))
		{
			M = M / 4;
			MUL = 8;
			tmp = 4;
			tmp2 = M + 16; //48
		}
		else if (freq_KHz > (cali_freq_thres_div3r / 2))
		{
			M = M / 3;
			MUL = 12;
			tmp = 4;
			tmp2 = M + 32; //32
		}
		else if (freq_KHz > (cali_freq_thres_div3 / 2))
		{
			M = M / 3;
			MUL = 12;
			tmp = 4;
			tmp2 = M; //16
		}
		else if (freq_KHz > (cali_freq_thres_div2 / 4))
		{
			M = M / 4;
			MUL = 16;
			tmp = 5;
			tmp2 = M + 16; //48
		}
		else if (freq_KHz > (cali_freq_thres_div3r / 4))
		{
			M = M / 3;
			MUL = 24;
			tmp = 5;
			tmp2 = M + 32; //32
		}
		else if (freq_KHz > (cali_freq_thres_div3 / 4))
		{
			M = M / 3;
			MUL = 24;
			tmp = 5;
			tmp2 = M; //16
		}
		else if (freq_KHz > (cali_freq_thres_div2 / 8))
		{
			M = M / 4;
			MUL = 32;
			tmp = 6;
			tmp2 = M + 16; //48
		}
		else if (freq_KHz > (cali_freq_thres_div3r / 8))
		{
			M = M / 3;
			MUL = 48;
			tmp = 6;
			tmp2 = M + 32; //32
		}
		else if (freq_KHz > (cali_freq_thres_div3 / 8))
		{
			M = M / 3;
			MUL = 48;
			tmp = 6;
			tmp2 = M; //16
		}
		else if (freq_KHz > (cali_freq_thres_div2 / 16))
		{
			M = M / 4;
			MUL = 64;
			tmp = 7;
			tmp2 = M + 16; //48
		}
		else if (freq_KHz > (cali_freq_thres_div3r / 16))
		{
			M = M / 3;
			MUL = 96;
			tmp = 7;
			tmp2 = M + 32; //32
		}
		else if (freq_KHz > (cali_freq_thres_div3 / 16))
		{
			M = M / 3;
			MUL = 96;
			tmp = 7;
			tmp2 = M; //16
		}
		else	// invalid
		{
			M = M / 4;
			MUL = 0;
			tmp = 0;
			tmp2 = 48;

			return;
		}

		if (freq_KHz == 291000)
		{
			M = tuner_handle->tuner_crystal / 1000 / 3;
			MUL = 12;
			tmp = 4;
			tmp2 = M + 32; //32
		}


		//if (freq_KHz == 578000)
		//{
		//	M = tuner_handle->tuner_crystal / 1000 / 4;
		//	MUL = 4;
		//	tmp = 2;
		//	tmp2 = M + 16; //48
		//}

		if (freq_KHz == 690000)
		{
			M = tuner_handle->tuner_crystal / 1000 / 3;
			MUL = 4;
			tmp = 2;
			tmp2 = M + 16; //48
		}

		for (iLoop = 0; iLoop < 4; iLoop ++)
		{
			N = (freq_KHz * MUL * M / crystal_KHz) / 2 * 2 - 256;
			F = (freq_KHz / 10 * 64 * MUL * M / (crystal_KHz  / 10) / 2) % 64;

			_mt_fe_tn_fraction_calc_tc2800(&N, &F);

			if (iLoop == 0)
			{
				if ((F == 56) || (F == 8) || ((F != 0) && ((N == 254) || (N == 766))))
				{
					M --;
					tmp2 --;
				}
				else
				{
					break;
				}
			}
			else if (iLoop == 1)
			{
				if ((F == 56) || (F == 8) || ((F != 0) && ((N == 254) || (N == 766))))
				{
					M += 2;
					tmp2 +=2;
				}
				else
				{
					break;
				}
			}
			else if (iLoop == 2)
			{
				if ((F != 0) && ((N == 254) || (N == 766)))
				{
					M -= 3;
					tmp2 -=3;
				}
				else
				{
					break;
				}
			}
			else if (iLoop == 3)
			{
				if ((F != 0) && ((N == 254) || (N == 766)))
				{
					M += 4;
					tmp2 +=4;
				}
				else
				{
					break;
				}
			}
		}


		_mt_fe_tn_get_reg(handle, 0x33, &buf);
		buf &= 0xc0;
		buf += tmp2;
		_mt_fe_tn_set_reg(handle, 0x33, buf);
	}
	else
	{
		return;
	}

	_mt_fe_tn_get_reg(handle, 0x39, &buf);
	buf &= 0xf8;
	buf += tmp;
	_mt_fe_tn_set_reg(handle, 0x39, buf);

	buf = (N >> 8) & 0xcf;
	if (tuner_handle->tuner_mtt == 0xE1)
	{
		buf |= 0x10;
	}
	_mt_fe_tn_set_reg(handle, 0x34, buf);

	buf = N & 0xff;
	_mt_fe_tn_set_reg(handle, 0x35, buf);

	buf = F & 0xff;
	_mt_fe_tn_set_reg(handle, 0x36, buf);


	if (F == 0)
	{
		if (tuner_handle->tuner_mtt == 0xD1)
		{
			_mt_fe_tn_set_reg(handle, 0x3d, 0xca);
		}
		else if (tuner_handle->tuner_mtt == 0xE1)
		{
			_mt_fe_tn_set_reg(handle, 0x3d, 0xfe);
		}
		else
		{
			return;
		}
		_mt_fe_tn_set_reg(handle, 0x3e, 0x9c);
		_mt_fe_tn_set_reg(handle, 0x3f, 0x34);
	}

	if (F > 0)
	{
		if (tuner_handle->tuner_mtt == 0xD1)
		{
			if ((F == 32) || (F == 16) || (F == 48))
			{
				_mt_fe_tn_set_reg(handle, 0x3e, 0xa4);
				_mt_fe_tn_set_reg(handle, 0x3d, 0x4a);
				_mt_fe_tn_set_reg(handle, 0x3f, 0x36);
			}
			else
			{
				_mt_fe_tn_set_reg(handle, 0x3e, 0xa4);
				_mt_fe_tn_set_reg(handle, 0x3d, 0x4a);
				_mt_fe_tn_set_reg(handle, 0x3f, 0x36);
			}
		}
		else if (tuner_handle->tuner_mtt == 0xE1)
		{
			_mt_fe_tn_set_reg(handle, 0x3e, 0xa4);
			_mt_fe_tn_set_reg(handle, 0x3d, 0x7e);
			_mt_fe_tn_set_reg(handle, 0x3f, 0x36);
			_mt_fe_tn_set_reg(handle, 0x89, 0x84);
			_mt_fe_tn_get_reg(handle, 0x39, &buf);
			buf = buf & 0x1f;
			_mt_fe_tn_set_reg(handle, 0x39, buf);
			_mt_fe_tn_get_reg(handle, 0x32, &buf);
			buf = buf | 0x02;
			_mt_fe_tn_set_reg(handle, 0x32, buf);
		}
		else
		{
			return;
		}
	}

	_mt_fe_tn_set_reg(handle, 0x41, 0x00);
	if (tuner_handle->tuner_mtt == 0xD1)
	{
		_mt_sleep(5);
	}
	else if (tuner_handle->tuner_mtt == 0xE1)
	{
		_mt_sleep(2);
	}
	else
	{
		return;
	}
	_mt_fe_tn_set_reg(handle, 0x41, 0x02);

	_mt_fe_tn_set_reg(handle, 0x30, 0x7f);
	_mt_fe_tn_set_reg(handle, 0x30, 0xff);
	_mt_fe_tn_set_reg(handle, 0x31, 0x80);
	_mt_fe_tn_set_reg(handle, 0x31, 0x00);

	PLLfreq01 = (crystal_KHz * 100 / M / MUL) * (N + 256) / 100 + (crystal_KHz * 100 / M / MUL) * F / 32 / 100;
	tuner_handle->tuner_offset_KHz = freq_KHz - PLLfreq01;
}


void _mt_fe_tn_set_PLL_freq_tc2800(MT_FE_DC2800_Device_Handle handle)
{
	U8 buf, buf1;
	U32 freq_thres_div2_KHz, freq_thres_div3r_KHz, freq_thres_div3_KHz;

	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);
	const U32 freq_KHz = tuner_handle->tuner_freq;


	if (tuner_handle->tuner_mtt == 0xD1)
	{
		_mt_fe_tn_set_reg(handle, 0x32, 0xe1);
		_mt_fe_tn_set_reg(handle, 0x33, 0xa6);
		_mt_fe_tn_set_reg(handle, 0x37, 0x7f);
		_mt_fe_tn_set_reg(handle, 0x38, 0x20);
		_mt_fe_tn_set_reg(handle, 0x39, 0x18);
		_mt_fe_tn_set_reg(handle, 0x40, 0x40);

		freq_thres_div2_KHz = 520000;
		_mt_fe_tn_cali_PLL_tc2800(handle, freq_KHz, freq_thres_div2_KHz, 0, 0);

		_mt_sleep(10);
		_mt_fe_tn_get_reg(handle, 0x3a, &buf);
		buf1 = buf;
		buf = buf & 0x03;
		buf1 = buf1 & 0x01;
		if ((buf1 == 0) || (buf == 3))
		{
			freq_thres_div2_KHz = 420000;
			_mt_fe_tn_cali_PLL_tc2800(handle, freq_KHz, freq_thres_div2_KHz, 0, 0);
			_mt_sleep(10);

			_mt_fe_tn_get_reg(handle, 0x3a, &buf);
			buf = buf & 0x07;
			if (buf == 5)
			{
				freq_thres_div2_KHz = 520000;
				_mt_fe_tn_cali_PLL_tc2800(handle, freq_KHz, freq_thres_div2_KHz, 0, 0);
				_mt_sleep(10);
			}
		}

		_mt_fe_tn_get_reg(handle, 0x38, &buf);
		_mt_fe_tn_set_reg(handle, 0x38, buf);

		_mt_fe_tn_get_reg(handle, 0x32, &buf);
		buf = buf | 0x10;
		_mt_fe_tn_set_reg(handle, 0x32, buf);

		_mt_fe_tn_set_reg(handle, 0x30, 0x7f);
		_mt_fe_tn_set_reg(handle, 0x30, 0xff);

		_mt_fe_tn_get_reg(handle, 0x32, &buf);
		buf = buf & 0xdf;
		_mt_fe_tn_set_reg(handle, 0x32, buf);
		_mt_fe_tn_set_reg(handle, 0x40, 0x0);

		_mt_fe_tn_set_reg(handle, 0x30, 0x7f);
		_mt_fe_tn_set_reg(handle, 0x30, 0xff);
		_mt_fe_tn_set_reg(handle, 0x31, 0x80);
		_mt_fe_tn_set_reg(handle, 0x31, 0x00);
		_mt_sleep(5);

		_mt_fe_tn_get_reg(handle, 0x39, &buf);
		buf = buf >> 5;
		if (buf < 5)
		{
			_mt_fe_tn_get_reg(handle, 0x39, &buf);
			buf = buf | 0xa0;
			buf = buf & 0xbf;
			_mt_fe_tn_set_reg(handle, 0x39, buf);

			_mt_fe_tn_get_reg(handle, 0x32, &buf);
			buf = buf | 0x02;
			_mt_fe_tn_set_reg(handle, 0x32, buf);
		}

		_mt_fe_tn_get_reg(handle, 0x37, &buf);
		if (buf > 0x70)
		{
			buf = 0x7f;
			_mt_fe_tn_set_reg(handle, 0x40, 0x40);
		}
		_mt_fe_tn_set_reg(handle, 0x37, buf);


		_mt_fe_tn_get_reg(handle, 0x38, &buf);
		if (buf < 0x0f)
		{
			buf = (buf & 0x0f) << 2;
			buf = buf + 0x0f;
			_mt_fe_tn_set_reg(handle, 0x37, buf);
		}
		else if (buf < 0x1f)
		{
			buf= buf + 0x0f;
			_mt_fe_tn_set_reg(handle, 0x37, buf);
		}

		_mt_fe_tn_get_reg(handle, 0x32, &buf);
		buf = (buf | 0x20) & 0xef;
		_mt_fe_tn_set_reg(handle, 0x32, buf);

		_mt_fe_tn_set_reg(handle, 0x41, 0x00);
		_mt_sleep(5);
		_mt_fe_tn_set_reg(handle, 0x41, 0x02);
	}
	else if (tuner_handle->tuner_mtt == 0xE1)
	{
		freq_thres_div2_KHz = 580000;
		freq_thres_div3r_KHz = 500000;
		freq_thres_div3_KHz = 440000;
		_mt_fe_tn_cali_PLL_tc2800(handle, freq_KHz, freq_thres_div2_KHz, freq_thres_div3r_KHz, freq_thres_div3_KHz);

		_mt_sleep(5);

		_mt_fe_tn_get_reg(handle, 0x38, &buf);
		_mt_fe_tn_set_reg(handle, 0x38, buf);

		_mt_fe_tn_set_reg(handle, 0x30, 0x7f);
		_mt_fe_tn_set_reg(handle, 0x30, 0xff);
		_mt_fe_tn_set_reg(handle, 0x31, 0x80);
		_mt_fe_tn_set_reg(handle, 0x31, 0x00);
		_mt_sleep(3);

		_mt_fe_tn_get_reg(handle, 0x38, &buf);
		if (buf == 0)
		{
			freq_thres_div2_KHz = 550000;
			freq_thres_div3r_KHz = 500000;
			freq_thres_div3_KHz = 400000;
			_mt_fe_tn_cali_PLL_tc2800(handle, freq_KHz, freq_thres_div2_KHz, freq_thres_div3r_KHz, freq_thres_div3_KHz);

			_mt_sleep(3);

			_mt_fe_tn_get_reg(handle, 0x38, &buf);
			_mt_fe_tn_set_reg(handle, 0x38, buf);

			_mt_fe_tn_set_reg(handle, 0x30, 0x7f);
			_mt_fe_tn_set_reg(handle, 0x30, 0xff);
			_mt_fe_tn_set_reg(handle, 0x31, 0x80);
			_mt_fe_tn_set_reg(handle, 0x31, 0x00);
			_mt_sleep(3);
		}

		_mt_fe_tn_get_reg(handle, 0x38, &buf);
		_mt_fe_tn_set_reg(handle, 0x38, buf);

		_mt_fe_tn_get_reg(handle, 0x32, &buf);
		buf = buf | 0x10;
		_mt_fe_tn_set_reg(handle, 0x32, buf);

		_mt_fe_tn_set_reg(handle, 0x30, 0x7f);
		_mt_fe_tn_set_reg(handle, 0x30, 0xff);
		_mt_fe_tn_get_reg(handle, 0x32, &buf);
		buf = buf & 0xdf;
		_mt_fe_tn_set_reg(handle, 0x32, buf);
		_mt_fe_tn_set_reg(handle, 0x31, 0x80);
		_mt_fe_tn_set_reg(handle, 0x31, 0x00);
		_mt_sleep(3);

		_mt_fe_tn_get_reg(handle, 0x37, &buf);
		_mt_fe_tn_set_reg(handle, 0x37, buf);

		//if ((freq_KHz == 802000) || (freq_KHz == 826000))
		//{
		//	_mt_fe_tn_set_reg(handle, 0x37, 0x5e);
		//}

		_mt_fe_tn_get_reg(handle, 0x32, &buf);
		buf = (buf & 0xef) | 0x30;
		_mt_fe_tn_set_reg(handle, 0x32, buf);

		_mt_fe_tn_set_reg(handle, 0x41, 0x00);
		_mt_sleep(2);
		_mt_fe_tn_set_reg(handle, 0x41, 0x02);
	}
	else
	{
		return;
	}

	return;
}


void _mt_fe_tn_set_BB_tc2800(MT_FE_DC2800_Device_Handle handle)
{
	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);

	U8 buf, tmp, bandwidth;
	bandwidth = tuner_handle->tuner_bandwidth;
	_mt_fe_tn_get_reg(handle, 0x53, &tmp);

	if (bandwidth == 6)			buf = 0x01 << 1;
	else if (bandwidth == 7)	buf = 0x02 << 1;
	else if (bandwidth == 8)	buf = 0x04 << 1;
	else						buf = 0x04 << 1;

	tmp &= 0xf1;
	tmp |= buf;

	_mt_fe_tn_set_reg(handle, 0x53, tmp);
}


void _mt_fe_tn_set_DAC_tc2800(MT_FE_DC2800_Device_Handle handle)
{
	U8 buf, tempnumber, buf1;
	S32	N, F;
	S32 f1f2number, f1, f2, delta1, Totalnum1;
	S32 cntT, cntin, NCOI, z0, z1, z2, tmp;
	U32 fc, fadc, fsd, f2d;
	U32 FreqTrue108_Hz;

	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);

	S32 M = tuner_handle->tuner_crystal / 4000;

	const U16 DAC_fre = 108;
	const U32 crystal_KHz = tuner_handle->tuner_crystal;
	U32 DACFreq_KHz = tuner_handle->tuner_dac;

	const U32 freq_KHz = tuner_handle->tuner_freq;

	if (tuner_handle->tuner_mtt == 0xE1)
	{
		_mt_fe_tn_get_reg(handle, 0x33, &buf);
		M = buf & 0x0f;

		if (M == 0)
		{
			M = 6;
		}
	}

	_mt_fe_tn_get_reg(handle, 0x34, &buf);
	N = buf & 0x07;

	_mt_fe_tn_get_reg(handle, 0x35, &buf);
	N = (N << 8) + buf;

	_mt_fe_tn_get_reg(handle, 0x36, &buf);
	F = buf;

	buf = ((N + 256) * crystal_KHz / M / DAC_fre + F * crystal_KHz / 32 / M / DAC_fre + (((freq_KHz % 1000) == 0) ? 500 : 0)) / 1000;

	if (tuner_handle->tuner_mtt == 0xE1)
	{
		_mt_fe_tn_set_appendix_tc2800(handle);

		buf1 = 0;

		if ((freq_KHz == 187000) || (freq_KHz == 195000) || (freq_KHz == 131000)
		 || (freq_KHz == 211000) || (freq_KHz == 219000) || (freq_KHz == 227000)
		 || (freq_KHz == 267000) || (freq_KHz == 299000) || (freq_KHz == 347000)
		 || (freq_KHz == 363000) || (freq_KHz == 395000) || (freq_KHz == 403000)
		 || (freq_KHz == 435000) || (freq_KHz == 482000) || (freq_KHz == 474000)
		 || (freq_KHz == 490000) || (freq_KHz == 610000) || (freq_KHz == 642000)
		 || (freq_KHz == 666000) || (freq_KHz == 722000) || (freq_KHz == 754000)
		 || (((freq_KHz == 379000) || (freq_KHz == 467000) || (freq_KHz == 762000))
		 && (tuner_handle->tuner_custom_cfg != 1))
		)
		{
			buf = buf + 1;
			buf1 = 1;
		}

		if ((freq_KHz == 123000) || (freq_KHz == 139000) || (freq_KHz == 147000)
		 ||	(freq_KHz == 171000) || (freq_KHz == 179000) ||	(freq_KHz == 203000)
		 || (freq_KHz == 235000) || (freq_KHz == 251000) || (freq_KHz == 259000)
		 || (freq_KHz == 283000) ||	(freq_KHz == 331000) ||	(freq_KHz == 363000)
		 || (freq_KHz == 371000) || (freq_KHz == 387000) ||	(freq_KHz == 411000)
		 || (freq_KHz == 427000) || (freq_KHz == 443000) || (freq_KHz == 451000)
		 || (freq_KHz == 459000) || (freq_KHz == 506000) || (freq_KHz == 514000)
		 || (freq_KHz == 538000) || (freq_KHz == 546000) || (freq_KHz == 554000)
		 || (freq_KHz == 562000) || (freq_KHz == 570000) ||	(freq_KHz == 578000)
		 ||	(freq_KHz == 602000) || (freq_KHz == 626000) ||	(freq_KHz == 658000)
		 || (freq_KHz == 690000) ||	(freq_KHz == 714000) || (freq_KHz == 746000)
		 || (freq_KHz == 522000) ||	(freq_KHz == 826000) || (freq_KHz == 155000)
		 || (freq_KHz == 530000)
		 ||	(((freq_KHz == 275000) || (freq_KHz == 355000)) && (tuner_handle->tuner_custom_cfg != 1))
		 || (((freq_KHz == 467000) || (freq_KHz == 762000) || (freq_KHz == 778000)
		 || (freq_KHz == 818000)) && (tuner_handle->tuner_custom_cfg == 1))
		)
		{
			buf = buf - 1;
			buf1 = 1;
		}

		if ((buf1 == 0) && (tuner_handle->tuner_offset_KHz == 0))
		{

			if ((freq_KHz >= 103000) && (freq_KHz <= 106000))
			{
				buf = buf - 1;
			}

			if (freq_KHz == 110000)
			{
				buf = buf + 1;
			}

			if ((freq_KHz >= 447000) && (freq_KHz <= 572000))
			{
				buf = buf - 1;
			}

			if ((freq_KHz >= 573000) && (freq_KHz <= 580000))
			{
				buf = buf + 1;
			}

			if ((freq_KHz >= 728000) && (freq_KHz <= 751000))
			{
				buf = buf + 1;
			}

			if ((freq_KHz >= 782000) && (freq_KHz <= 801000))
			{
				buf = buf + 1;
			}

			if ((freq_KHz >= 872000) && (freq_KHz <= 884000))
			{
				buf = buf + 1;
			}
		}
	}

	_mt_fe_tn_set_reg(handle, 0x0e, buf);
	_mt_fe_tn_set_reg(handle, 0x0d, buf);

	DACFreq_KHz = tuner_handle->tuner_dac + tuner_handle->tuner_offset_KHz;
	f1f2number = (((DACFreq_KHz * M * buf) / crystal_KHz) << 16) / (N + 256 + F / 32)
				 + (((DACFreq_KHz * M * buf) % crystal_KHz) << 16) / ((N + 256 + F / 32) * crystal_KHz);

	_mt_fe_tn_set_reg(handle, 0xf1, (U8)((f1f2number & 0xff00) >> 8));
	_mt_fe_tn_set_reg(handle, 0xf2, (U8)(f1f2number & 0x00ff));

	FreqTrue108_Hz = (N + 256) * crystal_KHz / (M * buf) * 1000 + (((N + 256) * crystal_KHz) % (M * buf)) * 1000 / (M * buf) + F * crystal_KHz / 32 / (M * buf);
	f1 = 4096;

	fc = FreqTrue108_Hz;
	fadc = fc / 4;
	fsd = 27000000;

	if ((tuner_handle->tuner_offset_KHz > 75) || (tuner_handle->tuner_offset_KHz < -75))
		f2d = tuner_handle->tuner_bandwidth * 1000 / 2;
	else
		f2d = tuner_handle->tuner_bandwidth * 1000 / 2 - 150;

	f2 = (fsd / 250) * f2d / ((fc + 500) / 1000);
	delta1 = ((f1 - f2) << 15) / f2;

	Totalnum1 = ((f1 - f2) << 15) - delta1 * f2;

	cntT = f2;
	cntin = Totalnum1;
	NCOI = delta1;

	z0 = cntin;
	z1 = cntT;
	z2 = NCOI;

	tempnumber = (z0 & 0xff00) >> 8;
	_mt_fe_tn_set_reg(handle, 0xc9, (U8)(tempnumber & 0x0f));
	tempnumber = (z0 & 0xff);
	_mt_fe_tn_set_reg(handle, 0xca, tempnumber);

	tempnumber = (z1 & 0xff00) >> 8;
	_mt_fe_tn_set_reg(handle, 0xcb, tempnumber);
	tempnumber = (z1 & 0xff);
	_mt_fe_tn_set_reg(handle, 0xcc, tempnumber);

	tempnumber = (z2 & 0xff00) >> 8;
	_mt_fe_tn_set_reg(handle, 0xcd, tempnumber);
	tempnumber = (z2 & 0xff);
	_mt_fe_tn_set_reg(handle, 0xce, tempnumber);


	tmp = f1;
	f1 = f2;
	f2 = tmp / 2;

	delta1 = ((f1 - f2) << 15) / f2;

	Totalnum1 = ((f1 - f2) << 15) - delta1 * f2;


	NCOI = (f1 << 15) / f2 - (1 << 15);

	cntT = 	f2;
	cntin = Totalnum1;

	z0 = cntin;
	z1 = cntT;
	z2 = NCOI;

	tempnumber = (z0 & 0xff00) >> 8;
	_mt_fe_tn_set_reg(handle, 0xd9, (U8)(tempnumber & 0x0f));
	tempnumber = (z0 & 0xff);
	_mt_fe_tn_set_reg(handle, 0xda, tempnumber);

	tempnumber = (z1 & 0xff00) >> 8;
	_mt_fe_tn_set_reg(handle, 0xdb, tempnumber);
	tempnumber = (z1 & 0xff);
	_mt_fe_tn_set_reg(handle, 0xdc, tempnumber);

	tempnumber = (z2 & 0xff00) >> 8;
	_mt_fe_tn_set_reg(handle, 0xdd, tempnumber);
	tempnumber = (z2 & 0xff);
	_mt_fe_tn_set_reg(handle, 0xde, tempnumber);

}


void _mt_fe_tn_preset_tc2800(MT_FE_DC2800_Device_Handle handle)
{
	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);

	if (tuner_handle->tuner_mtt == 0xD1)
	{
		_mt_fe_tn_set_reg(handle, 0x19, 0x4a);
		_mt_fe_tn_set_reg(handle, 0x1b, 0x4b);

		_mt_fe_tn_set_reg(handle, 0x04, 0x04);
		_mt_fe_tn_set_reg(handle, 0x17, 0x0d);
		_mt_fe_tn_set_reg(handle, 0x62, 0x6c);
		_mt_fe_tn_set_reg(handle, 0x63, 0xf4);
		_mt_fe_tn_set_reg(handle, 0x1f, 0x0e);
		_mt_fe_tn_set_reg(handle, 0x6b, 0xf4);
		_mt_fe_tn_set_reg(handle, 0x14, 0x01);
		_mt_fe_tn_set_reg(handle, 0x5a, 0x75);
		_mt_fe_tn_set_reg(handle, 0x66, 0x74);
		_mt_fe_tn_set_reg(handle, 0x72, 0xe0);
		_mt_fe_tn_set_reg(handle, 0x70, 0x07);
		_mt_fe_tn_set_reg(handle, 0x15, 0x7b);
		_mt_fe_tn_set_reg(handle, 0x55, 0x71);

		_mt_fe_tn_set_reg(handle, 0x75, 0x55);
		_mt_fe_tn_set_reg(handle, 0x76, 0xac);
		_mt_fe_tn_set_reg(handle, 0x77, 0x6c);
		_mt_fe_tn_set_reg(handle, 0x78, 0x8b);
		_mt_fe_tn_set_reg(handle, 0x79, 0x42);
		_mt_fe_tn_set_reg(handle, 0x7a, 0xd2);

		_mt_fe_tn_set_reg(handle, 0x81, 0x01);
		_mt_fe_tn_set_reg(handle, 0x82, 0x00);
		_mt_fe_tn_set_reg(handle, 0x82, 0x02);
		_mt_fe_tn_set_reg(handle, 0x82, 0x04);
		_mt_fe_tn_set_reg(handle, 0x82, 0x06);
		_mt_fe_tn_set_reg(handle, 0x82, 0x08);
		_mt_fe_tn_set_reg(handle, 0x82, 0x09);
		_mt_fe_tn_set_reg(handle, 0x82, 0x29);
		_mt_fe_tn_set_reg(handle, 0x82, 0x49);
		_mt_fe_tn_set_reg(handle, 0x82, 0x58);
		_mt_fe_tn_set_reg(handle, 0x82, 0x59);
		_mt_fe_tn_set_reg(handle, 0x82, 0x98);
		_mt_fe_tn_set_reg(handle, 0x82, 0x99);


		_mt_fe_tn_set_reg(handle, 0x10, 0x05);
		_mt_fe_tn_set_reg(handle, 0x10, 0x0d);
		_mt_fe_tn_set_reg(handle, 0x11, 0x95);
		_mt_fe_tn_set_reg(handle, 0x11, 0x9d);


		if (tuner_handle->tuner_loopthrough != 0)
		{
			_mt_fe_tn_set_reg(handle, 0x67, 0x25);
		}
		else
		{
			_mt_fe_tn_set_reg(handle, 0x67, 0x05);
		}
	}
	else if (tuner_handle->tuner_mtt == 0xE1)
	{
		_mt_fe_tn_set_reg(handle, 0x84, 0x04);
		_mt_fe_tn_set_reg(handle, 0x8a, 0x1f);
		_mt_fe_tn_set_reg(handle, 0x1b, 0x47);
		_mt_fe_tn_set_reg(handle, 0x42, 0x6b);
		if (tuner_handle->tuner_mode == 0)		// DVB-C
		{
			_mt_fe_tn_set_reg(handle, 0x66, 0x74);
			_mt_fe_tn_set_reg(handle, 0x62, 0x2c);
			_mt_fe_tn_set_reg(handle, 0x63, 0x54);
			_mt_fe_tn_set_reg(handle, 0x68, 0x0b);
			_mt_fe_tn_set_reg(handle, 0x14, 0x00);

			if (tuner_handle->tuner_freq < 100000)
			{
				_mt_fe_tn_set_reg(handle, 0x62, 0x5c);
				_mt_fe_tn_set_reg(handle, 0x8a, 0xa0);
				_mt_fe_tn_set_reg(handle, 0x84, 0x01);
				_mt_fe_tn_set_reg(handle, 0x87, 0x01);
			}
		}
		else if (tuner_handle->tuner_mode == 1)	// CTTB
		{
			_mt_fe_tn_set_reg(handle, 0x66, 0x74);
			_mt_fe_tn_set_reg(handle, 0x62, 0x0c);
			_mt_fe_tn_set_reg(handle, 0x63, 0x54);
			_mt_fe_tn_set_reg(handle, 0x68, 0x0b);
			_mt_fe_tn_set_reg(handle, 0x14, 0x01);
		}
		else// if (tuner_handle->tuner_mode == 2)// MMDS
		{
			_mt_fe_tn_set_reg(handle, 0x66, 0x74);
			_mt_fe_tn_set_reg(handle, 0x62, 0x2c);
			_mt_fe_tn_set_reg(handle, 0x63, 0x54);
			_mt_fe_tn_set_reg(handle, 0x68, 0x0b);
			_mt_fe_tn_set_reg(handle, 0x14, 0x01);
		}
		_mt_fe_tn_set_reg(handle, 0x6f, 0x00);

		_mt_fe_tn_set_reg(handle, 0x5e, 0xbe);
		_mt_fe_tn_set_reg(handle, 0x87, 0x07);

		_mt_fe_tn_set_reg(handle, 0x8b, 0x1f);
		_mt_fe_tn_set_reg(handle, 0x88, 0x30);
		_mt_fe_tn_set_reg(handle, 0x58, 0x34);
		_mt_fe_tn_set_reg(handle, 0x61, 0x8c);
		_mt_fe_tn_set_reg(handle, 0x6a, 0x42);
	}

	return;
}


void _mt_fe_tn_set_appendix_tc2800(MT_FE_DC2800_Device_Handle handle)
{
	U8 buf;

	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);

	const U32 freq_KHz = tuner_handle->tuner_freq;

	if (tuner_handle->tuner_mtt == 0xD1)
	{
		if ((freq_KHz == 123000) || (freq_KHz == 147000) || (freq_KHz == 171000)
		 || (freq_KHz == 195000))
			_mt_fe_tn_set_reg(handle, 0x20, 0x1b);


		if ((freq_KHz == 371000) || (freq_KHz == 419000) || (freq_KHz == 610000)
		 || (freq_KHz == 730000) || (freq_KHz == 754000) || (freq_KHz == 826000))
		{
			_mt_fe_tn_get_reg(handle, 0x0d, &buf);
			_mt_fe_tn_set_reg(handle, 0x0d, (U8)(buf + 1));
		}


		if ((freq_KHz == 522000) || (freq_KHz == 578000) || (freq_KHz == 634000)
		 || (freq_KHz == 690000) || (freq_KHz == 834000))
		{
			_mt_fe_tn_get_reg(handle, 0x0d, &buf);
			_mt_fe_tn_set_reg(handle, 0x0d, (U8)(buf - 1));
		}
	}
	else if (tuner_handle->tuner_mtt == 0xE1)
	{
		_mt_fe_tn_set_reg(handle, 0x20, 0xfc);

		if (((freq_KHz >=  44000) && (freq_KHz <=  52000)) || ((freq_KHz >=  68000) && (freq_KHz <=  76000))
		 || ((freq_KHz >=  92000) && (freq_KHz <= 100000)) || ((freq_KHz >= 116000) && (freq_KHz <= 124000))
		 || ((freq_KHz >= 140000) && (freq_KHz <= 148000)) || ((freq_KHz >= 164000) && (freq_KHz <= 172000))
		 || ((freq_KHz >= 188000) && (freq_KHz <= 196000)) || ((freq_KHz >= 212000) && (freq_KHz <= 220000))
		 || ((freq_KHz >= 260000) && (freq_KHz <= 268000)) || ((freq_KHz >= 284000) && (freq_KHz <= 292000))
		 || ((freq_KHz >= 332000) && (freq_KHz <= 340000)) || ((freq_KHz >= 380000) && (freq_KHz <= 388000))
		 || ((freq_KHz >= 428000) && (freq_KHz <= 436000)) || ((freq_KHz >= 476000) && (freq_KHz <= 484000))
		 || ((freq_KHz >= 524000) && (freq_KHz <= 532000)) || ((freq_KHz >= 716000) && (freq_KHz <= 724000))
		 || ((tuner_handle->tuner_custom_cfg == 1) && (freq_KHz == 315000)))
		{
			_mt_fe_tn_set_reg(handle, 0x20, 0x5c);
		}
	}

	return;
}


void mt_fe_tn_wakeup_tc2800(MT_FE_DC2800_Device_Handle handle)
{
	U8 buf;

	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);

	if (tuner_handle->tuner_loopthrough != 2)
	{
		_mt_fe_tn_set_reg(handle, 0x16, 0xb1);
		_mt_fe_tn_set_reg(handle, 0x09, 0x7d);
	}
	else
	{
		_mt_fe_tn_set_reg(handle, 0x09, 0x7d);
		_mt_fe_tn_get_reg(handle, 0x16, &buf);
		if (buf != 0xb1)
		{
			_mt_fe_tn_get_reg(handle, 0x61, &buf);
			buf = buf & 0xef;
			_mt_fe_tn_set_reg(handle, 0x61, buf);

			_mt_fe_tn_set_reg(handle, 0x16, 0xb1);
			_mt_fe_tn_set_reg(handle, 0x09, 0x7d);
			_mt_fe_tn_set_reg(handle, 0x0c, 0x38);
			_mt_fe_tn_set_reg(handle, 0x71, 0x51);
			_mt_fe_tn_set_reg(handle, 0x23, 0x44);
			_mt_fe_tn_set_reg(handle, 0x70, 0x47);
			_mt_fe_tn_set_reg(handle, 0x1d, 0x03);
			_mt_fe_tn_set_reg(handle, 0x1c, 0x15);

			_mt_fe_tn_get_reg(handle, 0x1b, &buf);
			buf = buf | 0x03;
			_mt_fe_tn_set_reg(handle, 0x1b, buf);

			_mt_fe_tn_get_reg(handle, 0x21, &buf);
			buf = buf | 0x80;
			if (tuner_handle->tuner_freq > 500000)
			{
				buf = buf | 0x20;
			}
			_mt_fe_tn_set_reg(handle, 0x21, buf);

			_mt_fe_tn_get_reg(handle, 0x5e, &buf);
			buf = buf | 0x80;
			_mt_fe_tn_set_reg(handle, 0x5e, buf);

			_mt_fe_tn_get_reg(handle, 0x3e, &buf);
			buf = (buf | 0x80) & 0xfd;
			_mt_fe_tn_set_reg(handle, 0x3e, buf);

			_mt_fe_tn_get_reg(handle, 0x68, &buf);
			buf = buf | 0x08;
			_mt_fe_tn_set_reg(handle, 0x68, buf);
		}
	}
}


void mt_fe_tn_sleep_tc2800(MT_FE_DC2800_Device_Handle handle)
{
	U8 buf;

	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);

	if (tuner_handle->tuner_loopthrough != 2)
	{
		_mt_fe_tn_set_reg(handle, 0x16, 0xb0);
		_mt_fe_tn_set_reg(handle, 0x09, 0x6d);
	}
	else
	{
		_mt_fe_tn_get_reg(handle, 0x61, &buf);
		buf = buf | 0x10;
		_mt_fe_tn_set_reg(handle, 0x61, buf);

		_mt_fe_tn_set_reg(handle, 0x16, 0xb0);
		_mt_fe_tn_set_reg(handle, 0x09, 0x75);
		_mt_fe_tn_set_reg(handle, 0x0c, 0x08);
		_mt_fe_tn_set_reg(handle, 0x71, 0x50);
		_mt_fe_tn_set_reg(handle, 0x23, 0x40);
		_mt_fe_tn_set_reg(handle, 0x70, 0x45);
		_mt_fe_tn_set_reg(handle, 0x1d, 0x02);
		_mt_fe_tn_set_reg(handle, 0x1c, 0x14);

		_mt_fe_tn_get_reg(handle, 0x1b, &buf);
		buf = buf & 0xfc;
		_mt_fe_tn_set_reg(handle, 0x1b, buf);

		_mt_fe_tn_get_reg(handle, 0x21, &buf);
		buf = buf & 0x7f;
		if (tuner_handle->tuner_freq > 500000)
		{
			buf = buf & 0xdf;
		}
		_mt_fe_tn_set_reg(handle, 0x21, buf);

		_mt_fe_tn_get_reg(handle, 0x5e, &buf);
		buf = buf & 0x7f;
		_mt_fe_tn_set_reg(handle, 0x5e, buf);

		_mt_fe_tn_get_reg(handle, 0x3e, &buf);
		buf = (buf & 0x7f) | 0x02;
		_mt_fe_tn_set_reg(handle, 0x3e, buf);

		_mt_fe_tn_get_reg(handle, 0x68, &buf);
		buf = buf & 0xf7;
		_mt_fe_tn_set_reg(handle, 0x68, buf);
	}
}


void mt_fe_tn_init_tc2800(MT_FE_DC2800_Device_Handle handle)
{
	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);

	if (tuner_handle->tuner_init_OK != 1)
	{
		tuner_handle->tuner_dev_addr		 = 0xC2;	// TUNER_I2C_ADDR_TC2800

		tuner_handle->tuner_freq			 = 650000;
		tuner_handle->tuner_qam				 = 0;

        tuner_handle->tuner_bandwidth		 = handle->tuner_settings.tuner_bandwidth;
		tuner_handle->tuner_loopthrough  = handle->tuner_settings.tuner_loopthrough;
        tuner_handle->tuner_mode = handle->tuner_settings.tuner_mode;

		tuner_handle->tuner_crystal			 = 24000;
		tuner_handle->tuner_dac				 = 7200;
		tuner_handle->tuner_offset_KHz		 = 0;

		tuner_handle->tuner_mtt				 = 0x00;

		tuner_handle->tuner_custom_cfg		 = MT_TC2800_CUSTOM_CONFIG;
		tuner_handle->tuner_version			 = 30031;	// Driver version number
		tuner_handle->tuner_time			 = 14090116;

		tuner_handle->tuner_init_OK			 = 1;
	}

	_mt_fe_tn_set_reg(handle, 0x2b, 0x4f);
	_mt_fe_tn_set_reg(handle, 0x2c, 0x75);

	if (tuner_handle->tuner_mtt == 0x00)
	{
		U8 tmp = 0;

		_mt_fe_tn_get_reg(handle, 0x01, &tmp);

		switch(tmp)
		{
			case 0x0d:
				tuner_handle->tuner_mtt	 = 0xD1;
				break;

			case 0x8e:
			default:
				tuner_handle->tuner_mtt	 = 0xE1;
				_mt_fe_tn_set_reg(handle, 0x67, 0x34);
				_mt_fe_tn_set_reg(handle, 0x28, 0x00);
				break;
		}
	}

	return;
}


void mt_fe_tn_set_freq_tc2800(MT_FE_DC2800_Device_Handle handle, U32 freq_KHz)
{
	U8 buf;
	U8 buf1;
	U8 buf2;
	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);

	mt_fe_tn_init_tc2800(handle);

	tuner_handle->tuner_mode = handle->tuner_settings.tuner_mode;

	tuner_handle->tuner_freq = freq_KHz;

	if (freq_KHz > 500000)
		_mt_fe_tn_set_reg(handle, 0x21, 0xb9);
	else
		_mt_fe_tn_set_reg(handle, 0x21, 0x99);

	mt_fe_tn_wakeup_tc2800(handle);

	_mt_fe_tn_set_reg(handle, 0x05, 0x7f);
	_mt_fe_tn_set_reg(handle, 0x06, 0xf8);

	_mt_fe_tn_set_RF_front_tc2800(handle);

	_mt_fe_tn_set_PLL_freq_tc2800(handle);
	_mt_fe_tn_set_DAC_tc2800(handle);
	_mt_fe_tn_set_BB_tc2800(handle);
	_mt_fe_tn_preset_tc2800(handle);

	_mt_fe_tn_set_reg(handle, 0x05, 0x00);
	_mt_fe_tn_set_reg(handle, 0x06, 0x00);

	if (tuner_handle->tuner_mtt == 0xD1)
	{
		_mt_fe_tn_set_reg(handle, 0x00, 0x01);
		_mt_fe_tn_set_reg(handle, 0x00, 0x00);

		_mt_sleep(20);

		_mt_fe_tn_get_reg(handle, 0x32, &buf);
		buf = (buf & 0xef) | 0x28;
		_mt_fe_tn_set_reg(handle, 0x32, buf);

		_mt_fe_tn_get_reg(handle, 0x33, &buf);
		buf = buf | 0x30;
		_mt_fe_tn_set_reg(handle, 0x33, buf);

		_mt_sleep(50);

		_mt_fe_tn_get_reg(handle, 0x69, &buf1);
		buf1 = buf1 & 0x0f;
		_mt_fe_tn_get_reg(handle, 0x6a, &buf2);
		buf2 = buf2 & 0x0f;

		_mt_fe_tn_get_reg(handle, 0x61, &buf);
		buf = buf & 0x0f;
		if ((buf == 0x0c) && (buf1 == buf2))
		{
			_mt_fe_tn_set_reg(handle, 0x6a, 0x59);
		}

		if (buf1 > 0x02)
		{
			if (freq_KHz > 600000)
				_mt_fe_tn_set_reg(handle, 0x66, 0x44);
			else if (freq_KHz > 500000)
				_mt_fe_tn_set_reg(handle, 0x66, 0x64);
			else
				_mt_fe_tn_set_reg(handle, 0x66, 0x74);
		}

		if (buf1 < 0x03)
		{
			if (freq_KHz > 800000)
				_mt_fe_tn_set_reg(handle, 0x87, 0x64);
			else if (freq_KHz > 600000)
				_mt_fe_tn_set_reg(handle, 0x87, 0x54);
			else if (freq_KHz > 500000)
				_mt_fe_tn_set_reg(handle, 0x87, 0x54);
			else if (freq_KHz > 300000)
				_mt_fe_tn_set_reg(handle, 0x87, 0x43);
			else if (freq_KHz > 220000)
				_mt_fe_tn_set_reg(handle, 0x87, 0x54);
			else if (freq_KHz > 110000)
				_mt_fe_tn_set_reg(handle, 0x87, 0x14);
			else
				_mt_fe_tn_set_reg(handle, 0x87, 0x54);

			_mt_sleep(5);
		}
		else if (buf < 0x0c)
		{
			_mt_fe_tn_set_reg(handle, 0x66 , 0x44);
			_mt_fe_tn_get_reg(handle, 0x7c , &buf2);
			buf2 = (buf2 & 0xf0) >> 4;

			if (freq_KHz > 800000)
				_mt_fe_tn_set_reg(handle, 0x87, 0x14);
			else if (freq_KHz >600000)
				_mt_fe_tn_set_reg(handle, 0x87, 0x14);
			else if (freq_KHz > 500000)
			{
				_mt_fe_tn_set_reg(handle, 0x87, 0x44);
				if (buf2 < 8)
				{
					_mt_fe_tn_set_reg(handle, 0x6a, 0x43);
				}
				else
				{
					_mt_fe_tn_set_reg(handle, 0x6a, 0x45);
				}
			}
			else if (freq_KHz > 300000)
			{
				_mt_fe_tn_set_reg(handle, 0x87, 0x34);
				if (buf2 < 8)
				{
					_mt_fe_tn_set_reg(handle, 0x6a, 0x43);
				}
				else
				{
					_mt_fe_tn_set_reg(handle, 0x6a, 0x45);
				}
			}
			else if (freq_KHz > 220000)
			{
				_mt_fe_tn_set_reg(handle, 0x87, 0x54);
				if (buf2 < 8)
				{
					_mt_fe_tn_set_reg(handle, 0x6a, 0x45);
				}
				else
				{
					_mt_fe_tn_set_reg(handle, 0x6a, 0x47);
				}
			}
			else if (freq_KHz > 110000)
			{
				_mt_fe_tn_set_reg(handle, 0x87, 0x14);
				if (buf2 < 8)
				{
					_mt_fe_tn_set_reg(handle, 0x6a, 0x43);
				}
				else
				{
					_mt_fe_tn_set_reg(handle, 0x6a, 0x45);
				}
			}
			else
				_mt_fe_tn_set_reg(handle, 0x87, 0x54);

			_mt_fe_tn_set_reg(handle, 0x30, 0xfb);
			_mt_fe_tn_set_reg(handle, 0x30, 0xff);
			_mt_fe_tn_set_reg(handle, 0x31, 0x04);
			_mt_fe_tn_set_reg(handle, 0x31, 0x00);
			_mt_sleep(5);

			_mt_fe_tn_set_reg(handle, 0x69, 0x02);
			_mt_fe_tn_set_reg(handle, 0x30, 0xfd);
			_mt_fe_tn_set_reg(handle, 0x30, 0xff);
			_mt_fe_tn_set_reg(handle, 0x31, 0x02);
			_mt_fe_tn_set_reg(handle, 0x31, 0x00);
			_mt_sleep(15);
		}

		_mt_fe_tn_get_reg(handle, 0x38, &buf);
		_mt_fe_tn_set_reg(handle, 0x38, buf);
		_mt_fe_tn_get_reg(handle, 0x32, &buf);
		buf = (buf & 0xf7) | 0x10;
		_mt_fe_tn_set_reg(handle, 0x32, buf);
	}
	else if ((tuner_handle->tuner_mtt == 0xE1))
	{
		_mt_fe_tn_set_reg(handle, 0x00, 0x01);
		_mt_fe_tn_set_reg(handle, 0x00, 0x00);

		_mt_sleep(20);

		_mt_fe_tn_get_reg(handle, 0x32, &buf);
		buf = (buf & 0xef) | 0x28;
		_mt_fe_tn_set_reg(handle, 0x32, buf);

		_mt_fe_tn_get_reg(handle, 0x34, &buf);
		buf = buf | 0x30;
		_mt_fe_tn_set_reg(handle, 0x34, buf);

		_mt_sleep(50);


		_mt_fe_tn_get_reg(handle, 0x69, &buf);
		buf = buf & 0x03;
		_mt_fe_tn_set_reg(handle, 0x2a, buf);

		if (buf > 0)
		{
			_mt_sleep(20);
			_mt_fe_tn_get_reg(handle, 0x84, &buf);
			buf = buf & 0x1f;
			if (tuner_handle->tuner_mode == 2)
			{
				_mt_fe_tn_set_reg(handle, 0x68, 0x0c);
			}
			else
			{
				if (freq_KHz <= 99000)
				{
					_mt_fe_tn_set_reg(handle, 0x68, 0x0b);
					_mt_fe_tn_set_reg(handle, 0x30, 0xfb);
					_mt_fe_tn_set_reg(handle, 0x30, 0xff);
					_mt_fe_tn_set_reg(handle, 0x31, 0x04);
					_mt_fe_tn_set_reg(handle, 0x31, 0x00);
				}
				else
				{
					_mt_fe_tn_set_reg(handle, 0x68, 0x0a);
				}
			}
			_mt_fe_tn_get_reg(handle, 0x88, &buf1);
			buf1 = buf1 & 0x1f;
			if (buf <= buf1)
				_mt_fe_tn_set_reg(handle, 0x66, 0x44);
			else
				_mt_fe_tn_set_reg(handle, 0x66, 0x74);
		}
		else
		{
			if (freq_KHz <= 99000)
			{
				_mt_fe_tn_set_reg(handle, 0x68, 0x0d);
			}
			else if (freq_KHz <= 600000)
			{
				_mt_fe_tn_set_reg(handle, 0x68, 0x0c);
			}
			else
			{
				_mt_fe_tn_set_reg(handle, 0x68, 0x0e);
			}
			_mt_fe_tn_set_reg(handle, 0x30, 0xfb);
			_mt_fe_tn_set_reg(handle, 0x30, 0xff);
			_mt_fe_tn_set_reg(handle, 0x31, 0x04);
			_mt_fe_tn_set_reg(handle, 0x31, 0x00);
		}

		if (tuner_handle->tuner_mode == 2)	// MMDS
		{
			_mt_sleep(20);
			_mt_fe_tn_get_reg(handle, 0x7c, &buf);
			buf = (buf >> 4) & 0x0f;
			if (buf >10)
			{
				_mt_fe_tn_set_reg(handle, 0x62, 0x2c);
				_mt_fe_tn_set_reg(handle, 0x63, 0x54);
			}
			else
			{
				_mt_fe_tn_set_reg(handle, 0x62, 0xcc);
				_mt_fe_tn_set_reg(handle, 0x63, 0xf4);
			}
		}

		if ((tuner_handle->tuner_mode == 1) || (tuner_handle->tuner_mode == 2))	// CTTB and MMDS
		{
			_mt_fe_tn_set_reg(handle, 0x14, 0x05);
		}
		_mt_fe_tn_get_reg(handle, 0x38, &buf);
		_mt_fe_tn_set_reg(handle, 0x38, buf);
		_mt_fe_tn_get_reg(handle, 0x32, &buf);
		buf = (buf & 0xf7) | 0x10;
		_mt_fe_tn_set_reg(handle, 0x32, buf);

		_mt_sleep(10);

		if (tuner_handle->tuner_loopthrough != 0)
		{
			_mt_fe_tn_get_reg(handle, 0x28, &buf);
			if (buf == 0)
			{
				_mt_fe_tn_set_reg(handle, 0x28, 0xff);
				_mt_fe_tn_get_reg(handle, 0x61, &buf);
				buf = buf & 0x0f;
				if (buf > 11)
					_mt_fe_tn_set_reg(handle, 0x67, 0x74);
				else if (buf > 10)
					_mt_fe_tn_set_reg(handle, 0x67, 0x64);
				else if (buf > 3)
					_mt_fe_tn_set_reg(handle, 0x67, 0x54);
				else
					_mt_fe_tn_set_reg(handle, 0x67, 0x44);
			}
		}
		else
		{
			_mt_fe_tn_set_reg(handle, 0x67, 0x34);
		}
	}
	else
	{
		return;
	}

	return;
}


void mt_fe_tn_set_BB_filter_band_tc2800(MT_FE_DC2800_Device_Handle handle, U8 bandwidth)
{
	U8 buf, tmp;

	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);

	_mt_fe_tn_get_reg(handle, 0x53, &tmp);

	if (bandwidth == 6)			buf = 0x01 << 1;
	else if (bandwidth == 7)	buf = 0x02 << 1;
	else if (bandwidth == 8)	buf = 0x04 << 1;
	else						buf = 0x04 << 1;

	tmp &= 0xf1;
	tmp |= buf;

	_mt_fe_tn_set_reg(handle, 0x53, tmp);

	tuner_handle->tuner_bandwidth = bandwidth;
}


double mt_fe_tn_get_signal_strength_tc2800(MT_FE_DC2800_Device_Handle handle)
{
	double level = -107.0;

	int tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
	S32 val1, val2, val;
	S32 result2, result3, result4, result5, result6;
	S32 append;

	U8 tmp;

	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);

	S32 freq_KHz = (S32)tuner_handle->tuner_freq;

	if (tuner_handle->tuner_mtt == 0xD1)
	{
		_mt_fe_tn_get_reg(handle, 0x61, &tmp);
		tmp1 = tmp & 0x0f;

		_mt_fe_tn_get_reg(handle, 0x69, &tmp);
		tmp2 = tmp & 0x0f;

		_mt_fe_tn_get_reg(handle, 0x73, &tmp);
		tmp3 = tmp & 0x07;

		_mt_fe_tn_get_reg(handle, 0x7c, &tmp);
		tmp4 = (tmp >> 4) & 0x0f;

		_mt_fe_tn_get_reg(handle, 0x7b, &tmp);
		tmp5 = tmp & 0x0f;

		_mt_fe_tn_get_reg(handle, 0x7f, &tmp);
		tmp6 = (tmp >> 5) & 0x01;


		if (tmp1 > 6)
		{
			val1 = 0;

			if (freq_KHz <= 200000)
			{
				val2 = (tmp1 - 6) * 267;
			}
			else if (freq_KHz <= 600000)
			{
				val2 = (tmp1 - 6) * 280;
			}
			else
			{
				val2 = (tmp1 - 6) * 290;
			}

			val = val1 + val2;
		}
		else
		{
			if (tmp1 == 0)
			{
				val1 = -550;
			}
			else
			{
				val1 = 0;
			}

			if ((tmp1 < 4) && (freq_KHz >= 506000))
			{
				val1 = -850;
			}

			val2 = 0;

			val = val1 + val2;
		}


		if (freq_KHz <= 95000)
		{
			result2 = tmp2 * 289;
		}
		else if (freq_KHz <= 155000)
		{
			result2 = tmp2 * 278;
		}
		else if (freq_KHz <= 245000)
		{
			result2 = tmp2 * 267;
		}
		else if (freq_KHz <= 305000)
		{
			result2 = tmp2 * 256;
		}
		else if (freq_KHz <= 335000)
		{
			result2 = tmp2 * 244;
		}
		else if (freq_KHz <= 425000)
		{
			result2 = tmp2 * 233;
		}
		else if (freq_KHz <= 575000)
		{
			result2 = tmp2 * 222;
		}
		else if (freq_KHz <= 665000)
		{
			result2 = tmp2 * 211;
		}
		else
		{
			result2 = tmp2 * 200;
		}

		result3 = (6 - tmp3) * 100;

		result4 = 300 * tmp4;
		result5 = 50 * tmp5;
		result6 = 300 * tmp6;

		if (freq_KHz < 105000)
		{
			append = -450;
		}
		else if (freq_KHz <= 227000)
		{
			append = -4 * (freq_KHz / 1000 - 100) + 150;
		}
		else if (freq_KHz <= 305000)
		{
			append = -4 * (freq_KHz / 1000 - 100);
		}
		else if (freq_KHz <= 419000)
		{
			append = 500 - 40 * (freq_KHz / 1000 - 300) / 17 + 130;
		}
		else if (freq_KHz <= 640000)
		{
			append = 500 - 40 * (freq_KHz / 1000 - 300) / 17;
		}
		else
		{
			append = -500;
		}

		level = append - (val + result2 + result3 + result4 + result5 + result6);

		level /= 100.0;
	}
	else if (tuner_handle->tuner_mtt == 0xE1)
	{
		_mt_fe_tn_get_reg(handle, 0x61, &tmp);
		tmp1 = tmp & 0x0f;

		_mt_fe_tn_get_reg(handle, 0x84, &tmp);
		tmp2 = tmp & 0x1f;

		_mt_fe_tn_get_reg(handle, 0x69, &tmp);
		tmp3 = tmp & 0x03;

		_mt_fe_tn_get_reg(handle, 0x73, &tmp);
		tmp4 = tmp & 0x0f;

		_mt_fe_tn_get_reg(handle, 0x7c, &tmp);
		tmp5 = (tmp >> 4) & 0x0f;

		_mt_fe_tn_get_reg(handle, 0x7b, &tmp);
		tmp6 = tmp & 0x0f;

		if (freq_KHz < 151000)
		{
			result2 = (1150 - freq_KHz / 100) * 163 / 33 + 4230;
			result3 = (1150 - freq_KHz / 100) * 115 / 33 + 1850;
			result4 = -3676 * (freq_KHz / 1000) / 100 + 6115;
		}
		else if (freq_KHz < 257000)
		{
			result2 = (1540 - freq_KHz / 100) * 11 / 4 + 3870;
			result3 = (1540 - freq_KHz / 100) * 205 / 96 + 2100;
			result4 = -21 * freq_KHz / 1000 + 5084;
		}
		else if (freq_KHz < 305000)
		{
			result2 = (2620 - freq_KHz / 100) * 5 / 3 + 2770;
			result3 = (2620 - freq_KHz / 100) * 10 / 7 + 1700;
			result4 = 650;
		}
		else if (freq_KHz < 449000)
		{
			result2 = (307 - freq_KHz / 1000) * 82 / 27 + 11270;
			result3 = (3100 - freq_KHz / 100) * 5 / 3 + 10000;
			result4 = 134 * freq_KHz / 10000 + 11875;
		}
		else
		{
			result2 = (307 - freq_KHz / 1000) * 82 / 27 + 11270;
			result3 = 8400;
			result4 = 5300;
		}

		if (tmp1 > 6)
		{
			val1 = result2;
			val2 = 2900;
			val = 500;
		}
		else if (tmp1 > 0)
		{
			val1 = result3;
			val2 = 2700;
			val = 500;
		}
		else
		{
			val1 = result4;
			val2 = 2700;
			val = 400;
		}

		level = val1 - (val2 * tmp1 + 500 * tmp2 + 3000 * tmp3 - 500 * tmp4 + 3000 * tmp5 + val * tmp6) - 1000;

		level /= 1000.0;
	}

	return level;
}


void mt_fe_tn_get_diagnose_info(MT_FE_DC2800_Device_Handle handle, U32* data1, U32* data2)
{
	U8	tmp = 0;

	MT_FE_TN_TC2800_Handle tuner_handle = (MT_FE_TN_TC2800_Handle)(handle->tuner_settings.tuner_handle);

	*data1 = 0;

	_mt_fe_tn_get_reg(handle, 0x61, &tmp);
	*data1 += ((tmp & 0x0f) << 16) & 0x0f0000;

	_mt_fe_tn_get_reg(handle, 0x69, &tmp);
	if (tuner_handle->tuner_mtt == 0xD1)
	{
		*data1 += ((tmp & 0x0f) << 8) & 0x0f00;
	}
	else if (tuner_handle->tuner_mtt == 0xE1)
	{
		*data1 += ((tmp & 0x03) << 8) & 0x0700;
	}

	_mt_fe_tn_get_reg(handle, 0x7c, &tmp);
	*data1 += ((tmp & 0xf0) >> 4) & 0x000f;

	*data2 = 0;

	_mt_fe_tn_get_reg(handle, 0x37, &tmp);
	*data2 += ((tmp & 0x7f) << 16) & 0x7f0000;

	_mt_fe_tn_get_reg(handle, 0x38, &tmp);
	*data2 += ((tmp & 0x7f) << 8) & 0x7f00;

	_mt_fe_tn_get_reg(handle, 0x3a, &tmp);
	*data2 += tmp & 0xff;

	if (tuner_handle->tuner_mtt == 0xE1)
	{
		_mt_fe_tn_get_reg(handle, 0x84, &tmp);
		*data2 += ((tmp & 0x1f) << 24) & 0x1f000000;
	}


	return;
}
extern MT_FE_DC2800_SUPPORTED_TUNER dc2800_tuner_type ;
void tuner_attach_tc2800(void)
{
   dc2800_tuner_type = TN_MONTAGE_TC2800;
}
void tuner_attach_lg1x1f(void)
{
   dc2800_tuner_type = TN_LG_TDCC_G1X1F;
}


void tuner_attach_tc2800_only_self(void)
{
  MT_FE_DC2800_Device_Handle p_handle = dc_2800_get_handle();

  p_handle->tuner_settings.tuner_type = TN_MONTAGE_TC2800;
}

