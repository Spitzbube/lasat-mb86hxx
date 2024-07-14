
#include "data.h"
#include "thumb2.h"

#pragma thumb

#if 0

Struct_20611068* Data_23492d60 = 0; //23492d60
Struct_20611068* Data_23492d64 = 0; //23492d64
Struct_20611068* Data_23492d68 = 0; //23492d68


struct
{
	Struct_2343b8e6 Data_235fc28c; //235fc28c

	struct
	{
#if 0
		int fill_0[50]; //0
		struct
		{
			uint8_t bData_0; //0
			int fill_4[4]; //4
			//20
		} Data_235fc360[8/*size???*/]; //235FC360 = 0xC8
		int fill_235FC400; //235FC400
#else
		int Data_0; //0
		struct Struct_2340d1f4_Inner_4 Data_4[9]; //4
		struct Struct_2340d1f4_Inner_0xb8 Data_0xb8[9]; //0xb8
#endif
		uint8_t bData_16c; //235fc404
		uint8_t bData_16d; //235fc405
		uint8_t bData_16e; //235fc406
		uint8_t bData_16f; //235fc407
		//0x170
	} Data_235fc298; //235fc298 -> 235FC408

	struct
	{
		uint8_t bData_235fc408; //235FC408
		int fill_235FC40c[6]; //235FC40c
		uint16_t wData_235fc424; //235FC424
		uint8_t fill_235FC426; //235FC426
		uint8_t bData_235fc427; //235fc427
		uint8_t fill_235fc428; //235fc428
		uint8_t bData_235fc429; //235fc429

	} Data_235fc408;

} Data_235fc28c; //235fc28c -> 235FC42C

#endif

Struct_235fc42c Data_235fc42c; //235fc42c Addr??? -> 235FC468

#if 0

/* 2343b822 - todo */
int sub_2343b822()
{
	Struct_235441b0 sp4;

#if 0
	console_send_string("sub_2343b822 (todo.c): TODO\r\n");
#endif

	memset(&Data_235fc42c, 0, sizeof(Data_235fc42c));
	memset(&Data_235fc28c, 0, sizeof(Data_235fc28c));

	sub_2340d1f4(1, &Data_235fc28c.Data_235fc298);

	sub_2340c970(1, &sp4);

	gpio_set(Data_23492d60, 0);

	rtos_task_wait(1);

	gpio_set(Data_23492d60, 1);

	rtos_task_wait(1);

	if (0 == i2c_master_read_reg(main_hI2c0, 0x96, 0x63, &Data_235fc28c.Data_235fc408.bData_235fc408, 1))
	{
		//0x2343b884
		Data_235fc28c.Data_235fc408.wData_235fc424 = sub_2340a650(sp4.bData_8);

		Data_235fc28c.Data_235fc408.bData_235fc427 = Data_235fc28c.Data_235fc298.bData_16c;

		Data_235fc28c.Data_235fc408.bData_235fc429 =
				Data_235fc28c.Data_235fc298.Data_0xb8[ Data_235fc28c.Data_235fc408.bData_235fc427 ].bData_16;

		if ((Data_235fc28c.Data_235fc408.bData_235fc427 > 9) ||
				(Data_235fc28c.Data_235fc408.bData_235fc429 > 9))
		{
			//loc_2343b8b2
			sub_2343b6b2();
		}
		//loc_2343b8b6
		sub_2343b9d6(0);

		sub_2343ba6a();

		if (0 == sub_2343b4f4())
		{
			//0x2343b8c8
			sub_2340d2cc(Data_235fc42c.Data_235fc454, Data_235fc42c.Data_235fc448);
		}
		//loc_2343b8d4
		return 0;
	}
	else
	{
		//loc_2343b8da
		gpio_set(Data_23492d60, 0);

		return 8;
	}
}


/* 2343b8e6 - todo */
int sub_2343b8e6(Struct_2343b8e6* a)
{
	Struct_20401328 sp;

#if 0
	console_send_string("sub_2343b8e6 (todo.c): TODO\r\n");
#endif

	if (a != 0)
	{
		Data_235fc28c.Data_235fc28c = *a;

		if (Data_235fc28c.Data_235fc28c.Data_0 != 0xff)
		{
			//0x2343b900
			sp.dwInFunction = 0xff;
			sp.dwOutFunction = 0x00;
			sp.bPin = Data_235fc28c.Data_235fc28c.Data_0;

			gpio_open(&sp, &Data_23492d60);
		}
		//loc_2343b912
		if (Data_235fc28c.Data_235fc28c.Data_4 != 0xff)
		{
			//0x2343b918
			sp.dwInFunction = 0xff;
			sp.dwOutFunction = 0x00;
			sp.bPin = Data_235fc28c.Data_235fc28c.Data_4;

			gpio_open(&sp, &Data_23492d64);
		}
		//loc_2343b92a
		if (Data_235fc28c.Data_235fc28c.Data_8 != 0xff)
		{
			//0x2343b930
			sp.dwInFunction = 0xff;
			sp.dwOutFunction = 0x00;
			sp.bPin = Data_235fc28c.Data_235fc28c.Data_8;

			gpio_open(&sp, &Data_23492d68);
		}
		//loc_2343b942
	}
	//loc_2343b942
	return 0;
}

#endif

/* 2343b946 - todo */
int sub_2343b946(Struct_235fc42c* r0, void* r6, uint8_t* r4, uint8_t* r5)
{
#if 1
	console_send_string("sub_2343b946 (todo.c): TODO\r\n");
#endif

	if (Data_235fc42c.Data_235fc444 == 0)
	{
		return 8;
	}
	//loc_2343b95c
#if 0
	if (r0 != 0)
	{
		memcpy(r0, &Data_235fc42c, sizeof(Struct_235fc42c));
	}
	//loc_2343b96a
	if (r6 != 0)
	{
		memcpy(r6, &Data_235fc28c.Data_235fc298, sizeof(Data_235fc28c.Data_235fc298));
	}
	//loc_2343b97a
	if (r4 != 0)
	{
		*r4 = Data_235fc28c.Data_235fc408.bData_235fc427;
	}
	//loc_2343b986
	if (r5 != 0)
	{
		*r5 = Data_235fc28c.Data_235fc408.bData_235fc429;
	}
#endif
	//loc_2343b98e
	return 0;
}

#if 0

/* 2343b992 - todo */
int sub_2343b992(int r0)
{
#if 0
	console_send_string("sub_2343b992 (todo.c): TODO\r\n");
#endif

	if (r0 != 0)
	{
		if (Data_235fc42c.Data_235fc42c != 0)
		{
			(Data_235fc42c.Data_235fc42c)();
		}
		//loc_2343b9aa
	}
	else
	{
		//loc_2343b9a6
		sub_2343b822();
	}
	//loc_2343b9aa
	return 0;
}

#endif
