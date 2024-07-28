
#include "ucos_ii.h"
#include "gpio.h"
#include "flash.h"


uint32_t Data_234892ec[] = //234892ec
{
   0x40000000, 0x4000ffff, 0x40010000, 0x4001ffff, 0x40020000, 0x4002ffff, 0x40030000, 0x4003ffff,
   0x40040000, 0x4004ffff, 0x40050000, 0x4005ffff, 0x40060000, 0x4006ffff, 0x40070000, 0x4007ffff,
   0x40080000, 0x4008ffff, 0x40090000, 0x4009ffff, 0x400a0000, 0x400affff, 0x400b0000, 0x400bffff,
   0x400c0000, 0x400cffff, 0x400d0000, 0x400dffff, 0x400e0000, 0x400effff, 0x400f0000, 0x400fffff,
   0x40100000, 0x4010ffff, 0x40110000, 0x4011ffff, 0x40120000, 0x4012ffff, 0x40130000, 0x4013ffff,
   0x40140000, 0x4014ffff, 0x40150000, 0x4015ffff, 0x40160000, 0x4016ffff, 0x40170000, 0x4017ffff,
   0x40180000, 0x4018ffff, 0x40190000, 0x4019ffff, 0x401a0000, 0x401affff, 0x401b0000, 0x401bffff,
   0x401c0000, 0x401cffff, 0x401d0000, 0x401dffff, 0x401e0000, 0x401effff, 0x401f0000, 0x401fffff,
   0x40200000, 0x4020ffff, 0x40210000, 0x4021ffff, 0x40220000, 0x4022ffff, 0x40230000, 0x4023ffff,
   0x40240000, 0x4024ffff, 0x40250000, 0x4025ffff, 0x40260000, 0x4026ffff, 0x40270000, 0x4027ffff,
   0x40280000, 0x4028ffff, 0x40290000, 0x4029ffff, 0x402a0000, 0x402affff, 0x402b0000, 0x402bffff,
   0x402c0000, 0x402cffff, 0x402d0000, 0x402dffff, 0x402e0000, 0x402effff, 0x402f0000, 0x402fffff,
   0x40300000, 0x4030ffff, 0x40310000, 0x4031ffff, 0x40320000, 0x4032ffff, 0x40330000, 0x4033ffff,
   0x40340000, 0x4034ffff, 0x40350000, 0x4035ffff, 0x40360000, 0x4036ffff, 0x40370000, 0x4037ffff,
   0x40380000, 0x4038ffff, 0x40390000, 0x4039ffff, 0x403a0000, 0x403affff, 0x403b0000, 0x403bffff,
   0x403c0000, 0x403cffff, 0x403d0000, 0x403dffff, 0x403e0000, 0x403effff, 0x403f0000, 0x403fffff,
   0x40400000, 0x4040ffff, 0x40410000, 0x4041ffff, 0x40420000, 0x4042ffff, 0x40430000, 0x4043ffff,
   0x40440000, 0x4044ffff, 0x40450000, 0x4045ffff, 0x40460000, 0x4046ffff, 0x40470000, 0x4047ffff,
   0x40480000, 0x4048ffff, 0x40490000, 0x4049ffff, 0x404a0000, 0x404affff, 0x404b0000, 0x404bffff,
   0x404c0000, 0x404cffff, 0x404d0000, 0x404dffff, 0x404e0000, 0x404effff, 0x404f0000, 0x404fffff,
   0x40500000, 0x4050ffff, 0x40510000, 0x4051ffff, 0x40520000, 0x4052ffff, 0x40530000, 0x4053ffff,
   0x40540000, 0x4054ffff, 0x40550000, 0x4055ffff, 0x40560000, 0x4056ffff, 0x40570000, 0x4057ffff,
   0x40580000, 0x4058ffff, 0x40590000, 0x4059ffff, 0x405a0000, 0x405affff, 0x405b0000, 0x405bffff,
   0x405c0000, 0x405cffff, 0x405d0000, 0x405dffff, 0x405e0000, 0x405effff, 0x405f0000, 0x405fffff,
   0x40600000, 0x4060ffff, 0x40610000, 0x4061ffff, 0x40620000, 0x4062ffff, 0x40630000, 0x4063ffff,
   0x40640000, 0x4064ffff, 0x40650000, 0x4065ffff, 0x40660000, 0x4066ffff, 0x40670000, 0x4067ffff,
   0x40680000, 0x4068ffff, 0x40690000, 0x4069ffff, 0x406a0000, 0x406affff, 0x406b0000, 0x406bffff,
   0x406c0000, 0x406cffff, 0x406d0000, 0x406dffff, 0x406e0000, 0x406effff, 0x406f0000, 0x406fffff,
   0x40700000, 0x4070ffff, 0x40710000, 0x4071ffff, 0x40720000, 0x4072ffff, 0x40730000, 0x4073ffff,
   0x40740000, 0x4074ffff, 0x40750000, 0x4075ffff, 0x40760000, 0x4076ffff, 0x40770000, 0x4077ffff,
   0x40780000, 0x4078ffff, 0x40790000, 0x4079ffff, 0x407a0000, 0x407affff, 0x407b0000, 0x407bffff,
   0x407c0000, 0x407cffff, 0x407d0000, 0x407dffff, 0x407e0000, 0x407effff, 0x407f0000, 0x407fffff,
   0x40800000, 0x4080ffff, 0x40810000, 0x4081ffff, 0x40820000, 0x4082ffff, 0x40830000, 0x4083ffff,
   0x40840000, 0x4084ffff, 0x40850000, 0x4085ffff, 0x40860000, 0x4086ffff, 0x40870000, 0x4087ffff,
   0x40880000, 0x4088ffff, 0x40890000, 0x4089ffff, 0x408a0000, 0x408affff, 0x408b0000, 0x408bffff,
   0x408c0000, 0x408cffff, 0x408d0000, 0x408dffff, 0x408e0000, 0x408effff, 0x408f0000, 0x408fffff,
   0x40900000, 0x4090ffff, 0x40910000, 0x4091ffff, 0x40920000, 0x4092ffff, 0x40930000, 0x4093ffff,
   0x40940000, 0x4094ffff, 0x40950000, 0x4095ffff, 0x40960000, 0x4096ffff, 0x40970000, 0x4097ffff,
   0x40980000, 0x4098ffff, 0x40990000, 0x4099ffff, 0x409a0000, 0x409affff, 0x409b0000, 0x409bffff,
   0x409c0000, 0x409cffff, 0x409d0000, 0x409dffff, 0x409e0000, 0x409effff, 0x409f0000, 0x409fffff,
   0x40a00000, 0x40a0ffff, 0x40a10000, 0x40a1ffff, 0x40a20000, 0x40a2ffff, 0x40a30000, 0x40a3ffff,
   0x40a40000, 0x40a4ffff, 0x40a50000, 0x40a5ffff, 0x40a60000, 0x40a6ffff, 0x40a70000, 0x40a7ffff,
   0x40a80000, 0x40a8ffff, 0x40a90000, 0x40a9ffff, 0x40aa0000, 0x40aaffff, 0x40ab0000, 0x40abffff,
   0x40ac0000, 0x40acffff, 0x40ad0000, 0x40adffff, 0x40ae0000, 0x40aeffff, 0x40af0000, 0x40afffff,
   0x40b00000, 0x40b0ffff, 0x40b10000, 0x40b1ffff, 0x40b20000, 0x40b2ffff, 0x40b30000, 0x40b3ffff,
   0x40b40000, 0x40b4ffff, 0x40b50000, 0x40b5ffff, 0x40b60000, 0x40b6ffff, 0x40b70000, 0x40b7ffff,
   0x40b80000, 0x40b8ffff, 0x40b90000, 0x40b9ffff, 0x40ba0000, 0x40baffff, 0x40bb0000, 0x40bbffff,
   0x40bc0000, 0x40bcffff, 0x40bd0000, 0x40bdffff, 0x40be0000, 0x40beffff, 0x40bf0000, 0x40bfffff,
   0x40c00000, 0x40c0ffff, 0x40c10000, 0x40c1ffff, 0x40c20000, 0x40c2ffff, 0x40c30000, 0x40c3ffff,
   0x40c40000, 0x40c4ffff, 0x40c50000, 0x40c5ffff, 0x40c60000, 0x40c6ffff, 0x40c70000, 0x40c7ffff,
   0x40c80000, 0x40c8ffff, 0x40c90000, 0x40c9ffff, 0x40ca0000, 0x40caffff, 0x40cb0000, 0x40cbffff,
   0x40cc0000, 0x40ccffff, 0x40cd0000, 0x40cdffff, 0x40ce0000, 0x40ceffff, 0x40cf0000, 0x40cfffff,
   0x40d00000, 0x40d0ffff, 0x40d10000, 0x40d1ffff, 0x40d20000, 0x40d2ffff, 0x40d30000, 0x40d3ffff,
   0x40d40000, 0x40d4ffff, 0x40d50000, 0x40d5ffff, 0x40d60000, 0x40d6ffff, 0x40d70000, 0x40d7ffff,
   0x40d80000, 0x40d8ffff, 0x40d90000, 0x40d9ffff, 0x40da0000, 0x40daffff, 0x40db0000, 0x40dbffff,
   0x40dc0000, 0x40dcffff, 0x40dd0000, 0x40ddffff, 0x40de0000, 0x40deffff, 0x40df0000, 0x40dfffff,
   0x40e00000, 0x40e0ffff, 0x40e10000, 0x40e1ffff, 0x40e20000, 0x40e2ffff, 0x40e30000, 0x40e3ffff,
   0x40e40000, 0x40e4ffff, 0x40e50000, 0x40e5ffff, 0x40e60000, 0x40e6ffff, 0x40e70000, 0x40e7ffff,
   0x40e80000, 0x40e8ffff, 0x40e90000, 0x40e9ffff, 0x40ea0000, 0x40eaffff, 0x40eb0000, 0x40ebffff,
   0x40ec0000, 0x40ecffff, 0x40ed0000, 0x40edffff, 0x40ee0000, 0x40eeffff, 0x40ef0000, 0x40efffff,
   0x40f00000, 0x40f0ffff, 0x40f10000, 0x40f1ffff, 0x40f20000, 0x40f2ffff, 0x40f30000, 0x40f3ffff,
   0x40f40000, 0x40f4ffff, 0x40f50000, 0x40f5ffff, 0x40f60000, 0x40f6ffff, 0x40f70000, 0x40f7ffff,
   0x40f80000, 0x40f8ffff, 0x40f90000, 0x40f9ffff, 0x40fa0000, 0x40faffff, 0x40fb0000, 0x40fbffff,
   0x40fc0000, 0x40fcffff, 0x40fd0000, 0x40fdffff, 0x40fe0000, 0x40feffff, 0x40ff0000, 0x40ffffff
};

volatile uint32_t* Data_23492650 = (void*)0xc0000000; //23492650 +0

Struct_235f2e2c Data_235f2e2c[2]; //235f2e2c



/* 2342bf70 - todo */
void sub_2342bf70()
{
	console_send_string("sub_2342bf70 (flash.c): TODO\r\n");

}


/* 2342bfbc - todo */
int sub_2342bfbc(uint32_t a)
{
#if 0
	console_send_string("sub_2342bfbc (flash.c): TODO\r\n");
#endif

	int r0_;
	int r2 = 0x06;
	int r3 = 0xd8;

	Data_23492650[1] = r2;
	r0_ = Data_23492650[0];
	Data_23492650[1] = r3;
	Data_23492650[0] = a & 0xffffff;

	r2 = 0x05;
	while (1) 
	{
		Data_23492650[1] = r2;

		r0_ = Data_23492650[0];
		if ((r0_ & 1) == 0)
		{
			break;
		}
	}

	Data_23492650[1] = 0x04;

	r0_ = Data_23492650[0];

	return 0;
}


/* 2342c008 - todo */
int sub_2342c008(uint16_t* pwData, uint32_t numWords, uint32_t c)
{
#if 0
	console_send_string("sub_2342c008 (flash.c): TODO\r\n");
#endif

	numWords /= 2;

	int r4 = 0x06;
	int r5 = 0x02;
	int lr = 0x05;
	int r3;

	if (c % 0x100)
	{
		Data_23492650[1] = r4;
		r3 = Data_23492650[0];
		Data_23492650[1] = r5;
		Data_23492650[0] = c & 0xffffff;
	}
	//->loc_2342c088
	while (numWords--)
	{
		//loc_2342c040
		if ((c % 0x100) == 0)
		{
			Data_23492650[1] = r4;
			r3 = Data_23492650[0];
			Data_23492650[1] = r5;
			Data_23492650[0] = c & 0xffffff;
		}

		r3 = *pwData;
		uint16_t r6 = *(++pwData);
		pwData++;
		Data_23492650[0] = (r3 << 16) | r6;

		c += 4;

		if ((c % 0x100) == 0)
		{
			while (1)
			{
				//loc_2342c078
				Data_23492650[1] = lr;

				int r3 = Data_23492650[0];
				if ((r3 & 1) == 0)
				{
					break;
				}
			}
		}
		//loc_2342c088
	}
	//0x2342c090
	if ((c % 0x100) != 0)
	{
		while (1)
		{
			//loc_2342c098
			Data_23492650[1] = lr;

			int r0 = Data_23492650[0];
			if ((r0 & 1) == 0)
			{
				break;
			}
		}
	}
	//loc_2342c0a8
	Data_23492650[1] = 0x04;

	int r0 = Data_23492650[0];

	return 0;
}


/* 2342c0bc - complete */
int sub_2342c0bc(void* a, uint32_t b, Struct_235f2e2c* c)
{
	uint16_t i;
	int res = 0;

#if 0
	console_send_string("sub_2342c0bc (flash.c): TODO\r\n");
#endif

	for (i = 0; i < c->numSectors; i++)
	{
		if (c->Data_0x2c[i] != 0)
		{
			sub_2342c008(a, b / 2, c->Data_0x20[i].Data_0);

			break;
		}
	}

	return res;
}


/* 2342c10c - todo */
void flash_read_dwords(uint32_t a, uint32_t b, uint8_t* c)
{
	uint32_t r1;
	uint32_t r4 = 0x03; //READ command
	uint32_t r5 = a & 0xffffff;

	b /= 4;

	Data_23492650[1] = r4; //FREG_SFLASH_COMMAND
	Data_23492650[0] = r5; //FREG_SFLASH_PORT

	while (b--)
	{
		//loc_2342c138
		r1 = Data_23492650[0]; //FREG_SFLASH_PORT

		c[0] = r1 >> 16;
		c[1] = r1 >> 24;
		c[2] = r1 >> 0;
		c[3] = r1 >> 8;

		c += 4;

#if 0
		console_send_string("flash_read_dwords (flash.c): TODO, ");
		{
			extern char debug_string[];
			sprintf(debug_string, "a=0x%x, b=%d, c=%p, r1=0x%08x\r\n", a, b, c, r1);
			console_send_string(debug_string);
		}
#endif
	}
}


/* 2342c170 - complete */
int sub_2342c170(Struct_235f2e2c* r0, uint32_t r1)
{
	uint16_t i;

#if 0
	console_send_string("sub_2342c170 (todo.c): TODO\r\n");
#endif

	for (i = 0; i < r0->numSectors; i++)
	{
		if (r0->Data_0x20[i].Data_0 <= r1)
		{
			if (r0->Data_0x20[i].Data_4 >= r1)
			{
				r0->Data_0x2c[i] = 1;

				return 1;
			}
		}
	}

	return 0;
}


/* 2342c1c8 - complete */
int sub_2342c1c8(Struct_235f2e2c* r7, int r5, uint32_t r6)
{
	uint32_t r4, r0;

#if 0
	console_send_string("sub_2342c1c8 (todo.c): TODO\r\n");
#endif

	memset(&r7->Data_0x2c[0], 0, sizeof(r7->Data_0x2c));

	r4 = 0;
	while (r4 < r6)
	{
		//loc_2342c1ec
		if (0 == sub_2342c170(r7, r5))
		{
			return 2;
		}

		r5 += 2;
		r4 += 2;
	}

	for (r0 = 0; r0 < r7->numSectors; r0++)
	{

	}

	return 0;
}


/* 2342c234 - complete */
int flash_init()
{
	uint32_t i;

#if 0
	console_send_string("flash_init (todo.c): TODO\r\n");
#endif

	for (i = 0; i < 2; i++)
	{
		//loc_2342c24c
		Data_235f2e2c[i].Data_4 = -1;
		Data_235f2e2c[i].sema = 0;
	}

	return 0;
}


/* 2342c270 - todo */
int flash_open(int* pParams, Struct_235f2e2c** ppHandle)
{
	uint8_t i;
	Struct_20611068* sp_0x24;
	Struct_20401328 sp_0x18;
	Struct_235f2e2c* r4 = 0;

#if 0
	console_send_string("flash_open (todo.c): TODO\r\n");
#endif

	for (i = 0; i < 2; i++)
	{
		//loc_2342c290
		if (Data_235f2e2c[i].Data_4 == -1)
		{
			r4 = &Data_235f2e2c[i];

			r4->Data_4 = *pParams;
			r4->Data_0x20 = 0; //r7
			r4->Data_0x24 = 0; //r7
			r4->sema = OSSemCreate(1);

			memset(&r4->Data_8, 0, 24);
			//->loc_2342c2e8
			break;
		}
		//loc_2342c2d8
	}
	//loc_2342c2e8
	if (r4 == 0)
	{
		*ppHandle = 0;
		//->loc_2342c5fc
		return 0;
	}
	//0x2342c2f4
	//r5 = 0x234892ec
	//sb = 0x100
	//r6 = 0x40
	//sl = 0xff
	if (r4->Data_4 == 1)
	{
		//0x2342c310
		Struct_235f2e2c_Inner_8 sp =
		{
				flash_read_dwords,
				sub_2342c0bc,
				sub_2342bf70,
				sub_2342bfbc,
				0,
				sub_2342c008
		}; //23489b04

		sp_0x18.dwOutFunction = 0xff; //sl
		sp_0x18.dwInFunction = 2; //FAPI_GPIO_IN_SFLASH_DATA
		sp_0x18.bPin = 0x2b;
		gpio_open(&sp_0x18, &sp_0x24);

		sp_0x18.dwOutFunction = 49; //FAPI_GPIO_OUT_SFLASH_HOLD
		sp_0x18.dwInFunction = 0xff; //sl
		sp_0x18.bPin = 0x2c;
		gpio_open(&sp_0x18, &sp_0x24);

		sp_0x18.dwOutFunction = 50; //FAPI_GPIO_OUT_SFLASH_CS
		sp_0x18.dwInFunction = 0xff; //sl
		sp_0x18.bPin = 0x2d;
		gpio_open(&sp_0x18, &sp_0x24);

		sp_0x18.dwOutFunction = 51; //FAPI_GPIO_OUT_SFLASH_CLK
		sp_0x18.dwInFunction = 0xff; //sl
		sp_0x18.bPin = 0x2e;
		gpio_open(&sp_0x18, &sp_0x24);

		sp_0x18.dwOutFunction = 52; //FAPI_GPIO_OUT_SFLASH_DATA
		sp_0x18.dwInFunction = 0xff; //sl
		sp_0x18.bPin = 0x2f;
		gpio_open(&sp_0x18, &sp_0x24);

		*ppHandle = r4;

		Data_23492650[2] = 0; //r7 FREG_SFLASH_SPEED
		Data_23492650[1] = 0xab; //r7 FREG_SFLASH_COMMAND
		r4->jedec_id = Data_23492650[0]; //FREG_SFLASH_PORT

		Data_23492650[1] = 0x9f; //r7 FREG_SFLASH_COMMAND: READ ID command
		r4->jedec_id = Data_23492650[0]; //FREG_SFLASH_PORT

		Data_23492650[2] = 1; //r7 FREG_SFLASH_SPEED

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "flash_open: r4->jedec_id=0x%x\r\n", r4->jedec_id);
			console_send_string(debug_string);
		}
#endif

		if (r4->jedec_id == 0x12018) //S25FL127S
		{
			//0x2342c408
			memcpy(&r4->Data_8, &sp, 24);

			r4->Data_0x20 = (void*) Data_234892ec; //r5;
			r4->numSectors = 256; // sb;
			//->loc_2342c5fc
		}
		//loc_2342c424
		else if (r4->jedec_id == 0x1c2017) //"en25p64"
		{
			//0x2342c430
			memcpy(&r4->Data_8, &sp, 24);

			r4->Data_0x20 = (void*) Data_234892ec; //r5;
			r4->numSectors = 126;
			//->loc_2342c5fc
		}
		//loc_2342c450
		else if ((r4->jedec_id == 0x1c2016) //"en25p32"
				|| (r4->jedec_id == 0x10215) //S25FL032P
				|| (r4->jedec_id == 0xef4016) //"W25Q32BV" -> vdr110
				|| (r4->jedec_id == 0xef7016) //"w25q32jv"
				|| (r4->jedec_id == 0x1c7016) //"en25qh32"
				|| (r4->jedec_id == 0xc84016)) //"gd25q32"
		{
			//0x2342c484
			memcpy(&r4->Data_8, &sp, 24);

			r4->Data_0x20 = (void*) Data_234892ec; //r5;
			r4->numSectors = 64; //r6
			//->loc_2342c5fc
		}
		//->loc_2342c5fc
	} //if (r4->Data_4 == 1)
	else
	{
		//loc_2342c4a0

	}
	//loc_2342c5fc
	return 0;
}


/* 2342c6d4 - todo */
int flash_read(Struct_235f2e2c* r4, int r5, int r6, void* r7)
{
	uint8_t sp;

#if 0
	console_send_string("flash_read (todo.c): TODO\r\n");
#endif

	if (r4->sema != 0)
	{
		OSSemPend(r4->sema, 0, &sp);
		if (sp != 0)
		{
			return sp;
		}
	}
	//loc_2342c70c
	if (r4->Data_8.read_dwords != 0)
	{
		(r4->Data_8.read_dwords)(r5, r6, r7);
	}

	if (r4->sema != 0)
	{
		OSSemPost(r4->sema);
	}

	return 0;
}


/* 2342c738 - todo */
int flash_write(void* h, int r5, int r6, void* r7)
{
	Struct_235f2e2c* r4 = h;
	uint8_t err;

#if 0
	console_send_string("sub_2342c738 (todo.c): TODO\r\n");
#endif

	if (r4->sema != 0)
	{
		OSSemPend(r4->sema, 0, &err);
		if (err != 0)
		{
			return err;
		}
	}
	//loc_2342c770
	if (0 == sub_2342c1c8(r4, r5, r6))
	{
		//0x2342c788
		sub_2342c898(r4);

		(r4->Data_8.Data_4)(r7, r6, r4);

		if (r4->sema != 0)
		{
			OSSemPost(r4->sema);
		}

		return 0;
	}
	else
	{
		//loc_2342c7b8
		if (r4->sema != 0)
		{
			OSSemPost(r4->sema);
		}

		return 1;
	}
}


/* 2342c898 - complete */
int sub_2342c898(Struct_235f2e2c* r5)
{
	uint16_t i;

#if 0
	console_send_string("sub_2342c898 (todo.c): TODO\r\n");
#endif

	for (i = 0; i < r5->numSectors; i++)
	{
		if (r5->Data_0x2c[i] != 0)
		{
			(r5->Data_8.Data_12)(r5->Data_0x20[i].Data_0);
		}

	}

	return 0;
}



