
#include "data.h"
#include "amplifier.h"

#pragma thumb

#define CS4525_I2C_ADDRESS	0x96
#define CS4525_REG_DEVICE	0x63


Struct_20611068* Data_23492d60 = 0; //23492d60
Struct_20611068* Data_23492d64 = 0; //23492d64
Struct_20611068* Data_23492d68 = 0; //23492d68
void (*Data_23492d6c)() = 0; //23492d6c / 234d8284 

struct
{
	Struct_2343b8e6 Data_235fc28c; //235fc28c

#if 0
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
	}
#endif
	Struct_2340d1f4 Data_235fc298; //235fc298 -> 235FC408

	struct
	{
		uint8_t bData_235fc408; //235FC408
		uint8_t bData_235fc409; //235FC409
		int fill_235FC40c[6]; //235FC40c
		uint16_t wData_235fc424; //235FC424
		uint8_t bData_235fc426; //235FC426
		uint8_t bData_235fc427; //235fc427
		uint8_t fill_235fc428; //235fc428
		uint8_t bData_235fc429; //235fc429

	} Data_235fc408;

} Data_235fc28c; //235fc28c -> 235FC42C

Struct_235fc42c Data_235fc42c; //235fc42c Addr??? -> 235FC468


/* 2343b174 - todo */
void sub_2343b174()
{
	console_send_string("sub_2343b174 (todo.c): TODO\r\n");

}


/* 2343b232 - todo */
void sub_2343b232()
{
	console_send_string("sub_2343b232 (todo.c): TODO\r\n");

}


/* 2343b28c - todo */
void sub_2343b28c()
{
	console_send_string("sub_2343b28c (todo.c): TODO\r\n");

}


/* 2343b2de - todo */
void sub_2343b2de()
{
	console_send_string("sub_2343b2de (todo.c): TODO\r\n");

}


/* 2343b32a - todo */
void sub_2343b32a()
{
	console_send_string("sub_2343b32a (todo.c): TODO\r\n");

}


/* 2343b364 - tood */
void sub_2343b364()
{
	console_send_string("sub_2343b364 (todo.c): TODO\r\n");

}


/* 2343b3c4 - todo */
void sub_2343b3c4()
{
	console_send_string("sub_2343b3c4 (todo.c): TODO\r\n");

}


/* 2343b4bc - todo */
void sub_2343b4bc()
{
	console_send_string("sub_2343b4bc (todo.c): TODO\r\n");

}

const uint8_t arData_23489e40[5][15] = //23489e40
{
   {0x38, 0xf9, 0x53, 0xe5, 0xc0, 0xd5, 0x1e, 0xbd, 0xb3, 0xc7, 0x06, 0xad, 0x1b, 0x81, 0x77},
   {0x29, 0x94, 0x02, 0xf1, 0x7f, 0xce, 0x39, 0x86, 0x63, 0xaa, 0x97, 0x4d, 0x20, 0xce, 0x80},
   {0x29, 0xed, 0xd4, 0xe6, 0xe6, 0x98, 0x1e, 0x47, 0x66, 0xd6, 0x12, 0x1c, 0x1a, 0xd2, 0x01},
   {0x3f, 0xe6, 0x00, 0xe0, 0x19, 0x1b, 0x20, 0x05, 0x2d, 0xc0, 0x1a, 0x00, 0x1f, 0xe1, 0xb8},
   {0x3f, 0xee, 0xb2, 0xe0, 0x0f, 0xe7, 0x1f, 0xfd, 0x10, 0xc0, 0x11, 0x4e, 0x1f, 0xf3, 0x08},
};


/* 2343b4f4 - todo */
int sub_2343b4f4(void)
{
#if 0
	console_send_string("sub_2343b4f4 (todo.c): TODO\r\n");
#endif

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x64;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x55;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x69;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x08;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x64;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x00;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x01;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x20;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc409 = 0xff;
	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x5f;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	int r0 = Data_235fc28c.Data_235fc298.Data_0xb8[Data_235fc28c.Data_235fc298.bData_16c].bData_16;

//	struct Struct_2340d1f4_Inner_4* r6 = &Data_235fc28c.Data_235fc298.Data_4[r0];
	//->loc_2343b58c
	sub_2343b174(/*r6->*/Data_235fc28c.Data_235fc298.Data_4[r0].bData_0xc);
	sub_2343b232(/*r6->*/Data_235fc28c.Data_235fc298.Data_4[r0].bData_0xe);
	sub_2343b4bc(/*r6->*/Data_235fc28c.Data_235fc298.Data_4[r0].bData_0x10);
	sub_2343b3c4(Data_235fc28c.Data_235fc298.bData_16c);
	sub_2343b9b6(/*r6->*/Data_235fc28c.Data_235fc298.Data_4[r0].bData_0x11);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x04;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x48;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x05;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x88;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x06;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x0f;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x07;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x67;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x09;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x80;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	for (uint8_t i = 0, reg = 0x0a; i < 5; i++)
	{
		//loc_2343b612
		//uint8_t* sp4 = &arData_23489e40[i];
		for (uint8_t k = 0; k < 15; k++)
		{
			//loc_2343b61e
			Data_235fc28c.Data_235fc408.bData_235fc408 = reg++;
			Data_235fc28c.Data_235fc408.bData_235fc409 = /*sp4*/arData_23489e40[i][k];

			i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
				&Data_235fc28c.Data_235fc408.bData_235fc408, 2);
		}
	}
	//0x2343b648
	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x58;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x48;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x59;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x48;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x09;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x23;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x5c;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x1d;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	sub_2343b28c(Data_235fc28c.Data_235fc298.bData_16d);

	i2c_master_read_reg(main_hI2c0, CS4525_I2C_ADDRESS, 0x62, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 1);

	return 0;
}


/* 2343b6b2 - todo */
void sub_2343b6b2()
{
	console_send_string("sub_2343b6b2 (todo.c): TODO\r\n");

}


/* 2343b7b8 - todo */
void sub_2343b7b8()
{
	console_send_string("sub_2343b7b8 (todo.c): TODO\r\n");

}


/* 2343b7e6 - todo */
void sub_2343b7e6()
{
	console_send_string("sub_2343b7e6 (todo.c): TODO\r\n");

}


/* 2343b7fe - todo */
void sub_2343b7fe()
{
	console_send_string("sub_2343b7fe (todo.c): TODO\r\n");

}


/* 2343b81a - todo */
void sub_2343b81a()
{
	console_send_string("sub_2343b81a (todo.c): TODO\r\n");

}


/* 2343b822 - todo */
int sub_2343b822()
{
	User_Settings sp4;

#if 0
	console_send_string("sub_2343b822 (todo.c): TODO\r\n");
#endif

	memset(&Data_235fc42c, 0, sizeof(Data_235fc42c));
	memset(&Data_235fc28c, 0, sizeof(Data_235fc28c));

	sub_2340d1f4(1, &Data_235fc28c.Data_235fc298);

	channel_handle_user_settings(1, &sp4);

	gpio_set(Data_23492d60, 0);

	rtos_task_wait(1);

	gpio_set(Data_23492d60, 1);

	rtos_task_wait(1);

	int r0 = i2c_master_read_reg(main_hI2c0, CS4525_I2C_ADDRESS, CS4525_REG_DEVICE, 
					&Data_235fc28c.Data_235fc408.bData_235fc408, 1);

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2343b822: r0=%d, bData_235fc408=0x%02x\r\n", 
			r0, Data_235fc28c.Data_235fc408.bData_235fc408);
		console_send_string(debug_string);
	}
#endif

	if (r0 == 0)
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


/* 2343b9ae / 2345eb56 - todo */
void sub_2343b9ae(void (*p)())
{
#if 0
	console_send_string("sub_2343b9ae (todo.c): TODO\r\n");
#endif

	Data_23492d6c = p;
}


/* 2343b9b6 - todo */
void sub_2343b9b6()
{
#if 1
	console_send_string("sub_2343b9b6 (todo.c): TODO\r\n");
#endif

}


/* 2343b9d6 - todo */
void sub_2343b9d6(int r4)
{
#if 0
	console_send_string("sub_2343b9d6 (todo.c): TODO\r\n");
#endif

	memset(&Data_235fc42c, 0, sizeof(Data_235fc42c));

	if (r4 == 0)
	{
		//0x2343b9e8
		Data_235fc42c.Data_235fc430 = sub_2343b7fe;
		Data_235fc42c.Data_235fc42c = sub_2343b32a;
		Data_235fc42c.Data_235fc434 = sub_2343b174;
		Data_235fc42c.Data_235fc438 = 0;
		Data_235fc42c.Data_235fc43c = sub_2343b4bc;
		Data_235fc42c.Data_235fc440 = sub_2343b232;
		Data_235fc42c.Data_235fc444 = sub_2343b28c;
		Data_235fc42c.Data_235fc448 = sub_2343b2de;
		Data_235fc42c.Data_235fc44c = sub_2343b3c4;
		Data_235fc42c.Data_235fc450 = sub_2343b9b6;
		Data_235fc42c.Data_235fc454 = sub_2343b364;
		Data_235fc42c.Data_235fc458 = sub_2343b6b2;
		Data_235fc42c.Data_235fc464 = sub_2343b7b8;
		Data_235fc42c.Data_235fc460 = sub_2343b7e6;
		Data_235fc42c.Data_235fc45c = sub_2343b81a;
	}
	//loc_2343ba68
}


/* 2343ba6a - todo */
int sub_2343ba6a(void)
{
#if 0
	console_send_string("sub_2343ba6a (todo.c): TODO\r\n");
#endif

	int r0 = i2c_master_read_reg(main_hI2c0, 0x20, 0x7f, 
					&Data_235fc28c.Data_235fc408.bData_235fc408, 1);

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2343ba6a: r0=%d, bData_235fc408=0x%02x\r\n", 
			r0, Data_235fc28c.Data_235fc408.bData_235fc408);
		console_send_string(debug_string);
	}
#endif

	if (r0 == 0)
	{
		//0x2343ba84
		Data_235fc28c.Data_235fc408.bData_235fc426 = 0x20;
		Data_235fc28c.Data_235fc408.bData_235fc408 = 0x05;
		Data_235fc28c.Data_235fc408.bData_235fc409 = 0x05;

		i2c_master_send(main_hI2c0, 0x20, 
			&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

		Data_235fc28c.Data_235fc408.bData_235fc408 = 0x04;
		Data_235fc28c.Data_235fc408.bData_235fc409 = 0x80;

		i2c_master_send(main_hI2c0, 0x20, 
			&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

		return 0;
	}
	//loc_2343bab8
	return 8;
}


#if 0
sub_2343b174 (todo.c): TODO
sub_2343b232 (todo.c): TODO
sub_2343b4bc (todo.c): TODO
sub_2343b3c4 (todo.c): TODO
sub_2343b9b6 (todo.c): TODO
sub_2343b28c (todo.c): TODO
sub_2340d2cc (todo.c): TODO
sub_2343b946 (todo.c): TODO
#endif
