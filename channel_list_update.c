
#include "data.h"
#include "nit.h"
#include "sub_23472004.h"
#include "channel_list_update.h"

#pragma thumb


const Transponder channel_list_update_initial_transponder = //23489ebc
{
		{
				{0x50000000/*{.Data_28_31 = 5}*/}, //0, 0, 0, 5, //TODO!!
				4420000, //Data_0.Data_4
				6900/*0x1AF4*/, //Data_0.wData_8
				0xffff, //Data_0.wData_0x0a
				0x26530000, //Data_0.fill_12
		},
		0xff, //uint16_t wData_0x10; //0x10 = 16
		0, //uint16_t fill_0x12; //0x12 = 18
		0, //uint16_t fill_0x14; //0x14 = 20
		0, //uint8_t bData_0x16; //0x16
		//0x18 = 24
#if 0
#if 0
		union
		{

			uint32_t Data_0;
			struct
			{
		//		uint32_t Data_0_27: 28;
				uint32_t Data_0_18: 19;
				uint8_t Data_19: 1; //bData_2 & 0xf7
				uint32_t Data_20_27: 8; //
				uint8_t Data_28_31: 4; //bData_3 & 0xf0
			} Bitfield_0;
		} Data_0; //0
		uint32_t Data_4; //4
		uint16_t wData_8; //8
		uint16_t wData_0x0a; //10 = 0x0a
		int fill_12; //12
		//16
#endif
		Struct_23491e28_Inner0 Data_0; //0
		uint16_t wData_0x10; //0x10 = 16
		uint16_t fill_0x12; //0x12 = 18
		uint16_t fill_0x14; //0x14 = 20
		uint8_t bData_0x16; //0x16
		//0x18 = 24
#endif
}; //->23489ED4

void* channel_list_update_sema; //23493108 +0
int channel_list_update_psi_status; //2349310c +4
int channel_list_update_tune_status; //23493110 +8

Transponder Data_235fdfac[200]; //235fdfac


/* 2343dcfc - complete */
static void channel_list_update_psi_callback(void* h)
{
	struct Struct_234a73e8_Inner_0x248* pPrograms;
	uint16_t numPrograms;

#if 0
	console_send_string("channel_list_update_psi_callback (todo.c): TODO\r\n");
#endif

	int res = psi_get_all_current_programs(h, &numPrograms, &pPrograms);
	int status = 1;
	
	if (res != 0)
	{
		status = -1;
	}
	
	channel_list_update_psi_status = status;
}


/* 2343dd14 - complete */
static int channel_list_update_frontend_callback(int status)
{
#if 0
	console_send_string("channel_list_update_frontend_callback (todo.c): TODO\r\n");
#endif

	if (status == 0)
	{
		channel_list_update_tune_status = 1;	
	}
	else if (status == 0x0f)
	{
		channel_list_update_tune_status = -1;
	}

	return 0;
}


/* 2343dd2c - todo */
int channel_list_update_start(void)
{
	uint16_t i;
	uint16_t listLen;
	uint8_t r4;
	int r5;
	uint32_t r6;
	uint8_t sp_0x90; //sp_144;
	uint8_t sp_0x8c; //sp_140;
	int sp_0x88; //sp_136;
	Struct_2340bf0c sp_0x54;
	Channel channel; //sp_0x2c
	Transponder transponder; //sp_0x14

#if 0
	console_send_string("channel_list_update_start (todo.c): TODO\r\n");
#endif

	//r7 = 23493108
	if (channel_list_update_sema != 0)
	{
		//loc_2343de24 -> loc_2343de66
		return 0;
	}
	//r6, =dword_23491db4
	r5 = 0;
	sp_0x90 = 0;
	sp_0x8c = 0;
	sp_0x88 = 0;
	r4 = 1;

	if (0 != sub_2340ecc0(main_hFrontend1, &sp_0x90, &sp_0x8c))
	{
		sub_2340bf0c(&sp_0x54);
		sub_2340bf94(sp_0x54.wCurrentChannel, &channel, &transponder);

		if ((channel_list_update_initial_transponder.Data_0.frequency != transponder.Data_0.frequency) //sp24)
				|| ((channel_list_update_initial_transponder.Data_0.Data_0.Bitfield_0.Data_28_31/*bData_3 >> 4*/) !=
						(transponder.Data_0.Data_0.Bitfield_0.Data_28_31/*bData_3 >> 4*/)))
		{
			//loc_2343dd7c
			r4 = 2;
		}
		//loc_2343dd7e
	}
	//loc_2343dd7e
	sub_2340c368(1, &sp_0x88);

	//->loc_2343de1a
	fe_manager_tune(main_hFrontend1, channel_list_update_initial_transponder, 
		channel_list_update_frontend_callback/*sp12*/, 0/*sp16*/);
	//->loc_2343de56
	while (r4--)
	{
		//loc_2343dd9e
		channel_list_update_tune_status = 0;
		r6 = 25;
		//->loc_2343ddb0
		while (r6--)
		{
			//loc_2343dda6
			if (channel_list_update_tune_status > 0)
			{
				r5 = 1;
				//->loc_2343ddc2
				break;
			}
			//loc_2343ddb0
			channel_list_update_tune_status = 0;

			rtos_task_wait(10);
		}
		//0x2343ddbe
		if (r5 != 0)
		{
			//loc_2343ddc2
			psi_start(main_hPSIDecoder1, 0x40, channel_list_update_psi_callback, 0, 0, 0);
			//0x2343ddd6
			r6 = 1200;
			channel_list_update_psi_status = 0;
			//->loc_2343ddec
			while (r6--)
			{
				//loc_2343dde0
				rtos_task_wait(1);

				if (channel_list_update_psi_status != 0)
				{
					//->loc_2343ddf0
					break;
				}
			}
			//loc_2343ddf0
			psi_stop(main_hPSIDecoder1, 1);
			if (channel_list_update_psi_status <= 0)
			{
				r5 = 0;
				//loc_2343de02
			} //if (channel_list_update_psi_status <= 0)
			else
			{
				//loc_2343de26
				goto loc_2343de26;
			}
		} //if (r5 != 0)
		//loc_2343de02
		if (r4 != 0)
		{
			//0x2343de06
			fe_manager_tune(main_hFrontend1, transponder, 
				channel_list_update_frontend_callback/*sp12*/, 0/*sp16*/);
			//->loc_2343de56
		}
		else
		{
			//->loc_2343de60
			break;
			//loc_2343de24 -> loc_2343de66
loc_2343de26:
			{
				//loc_2343de26
				Struct_2344dc3c sp8;

				psi_get_network_info(&sp8, main_hPSIDecoder1);

				if (sp8.Data_4->wData_0x1a == sp_0x88)
				{
					//0x2343de3c
					powermode_set_onoff_callbacks_ex(sub_234720a4, sub_23472004);

					sub_234720a4(0);
					//->loc_2343deb0
					return 1;
				}
				else
				{
					//loc_2343de4c
					sub_23470538();

					if (r5 == 0)
					{
						//0x2343de54 -> loc_2343de60
						break;
					}
					else
					{
						//loc_2343de74
						goto loc_2343de74;
					}
				}
			}
		}
	} //while (r4--)
	//loc_2343de60
	if ((sp_0x88 + 1) != 0)
	{
		//loc_2343de66
		return 0;
	}
	//->loc_2343de6c
	sub_23406834(main_hPSIDecoder1);
	//loc_2343de74
loc_2343de74:
	listLen = channel_get_transponder_list(0xffff, Data_235fdfac, 200);
	//r0, =0x235fdfac
	//->loc_2343de9a
	for (i = 0; i < listLen; i++)
	{
		//loc_2343de86
		Data_235fdfac[i].Data_0.Data_0.Bitfield_0.Data_28_31 = 6;
	}
	//0x2343de9e
	channel_list_update_sema = OSSemCreate(1);

	sub_234701da(Data_235fdfac, listLen, channel_list_update_sema);
	//loc_2343deb0
	return 1;
}


/* 2343deb4 - complete */
int sub_2343deb4(int r1)
{
	uint8_t err;

#if 0
	console_send_string("sub_2343deb4 (todo.c): TODO\r\n");
#endif

	if (channel_list_update_sema == 0)
	{
		//loc_2343dec0
		return 0;
	}
	//loc_2343dec4
	if (r1 != 0)
	{
		channel_list_update_sema = (void*) OSSemDel(channel_list_update_sema, 1, &err);
		//->loc_2343dec0
		return 0;
	}
	//loc_2343ded4
	OSSemPend(channel_list_update_sema, 10, &err);

	if (err == 0)
	{
		channel_list_update_sema = (void*) OSSemDel(channel_list_update_sema, 1, &err);

		sub_234101e8();

		sub_2340add4(0x40300000);

		channel_load_lists();
	}
	//loc_2343defc
	return err;
}


/* 2343df02 - todo */
void sub_2343df02(Struct_2343df02* r4)
{
	Struct_2354613c sp_0x1c;
	Struct_235441b0 sp;
	uint32_t crc;
	uint32_t i;

#if 0
	console_send_string("sub_2343df02 (todo.c): TODO\r\n");
#endif

	if (r4 == 0)
	{
		//loc_2343df5e
		return;
	}
	//0x2343df0a
	sub_2340c970(1, &sp);

	memset(Data_235fdfac, 0, 200 * sizeof(Transponder));

	r4->pList = Data_235fdfac;
	r4->bData_0x10 = 1;
	r4->bData_0x11 = 1;
	r4->bData_0x12 = (sp.Data_4 << 7) >> 30;

	sub_2340ca5c(1, &sp_0x1c);

	crc = sp_0x1c.crc;
	sp_0x1c.crc = 0;

	if (crc == crc32((void*) &sp_0x1c.Data_0, sizeof(sp_0x1c)))
	{
		memcpy(&Data_235fdfac[0], &sp_0x1c, sizeof(Transponder));

		r4->listLen = 1;
		r4->wData_0x16 = sp_0x1c.wData_0x18;
		r4->wData_0x14 = sp_0x1c.wData_0x1a;
		//loc_2343df5e
		return;
	}
	else
	{
		//loc_2343df62
		r4->listLen = channel_get_transponder_list(0xffff, Data_235fdfac, 200); //get list
		r4->wData_0x16 = 0;
		r4->wData_0x14 = -1;
		//->loc_2343df8c
		for (i = 0; i < r4->listLen; i++)
		{
			//->loc_2343df7a
//			Data_235fdfac[i].bData_3 = (Data_235fdfac[i].bData_3 & 0x0f) + 0x60;
			Data_235fdfac[i].Data_0.Data_0.Bitfield_0.Data_28_31 = 6;
		}
		//->loc_2343df5e
	}
}


