
#include "data.h"
#include "vfd.h"

typedef struct
{
	uint8_t* Data_0; //0
	void (*Data_4)(); //4
	void (*Data_8)(); //8
	void (*Data_12)(); //12
	void (*Data_16)(); //16
	uint8_t bData_0x14; //20 = 0x14
	uint8_t bData_0x15; //21 = 0x15
	uint8_t bData_0x16; //22 = 0x16
	uint8_t bData_0x17; //23 = 0x17
	uint8_t bData_0x18; //24 = 0x18
	uint32_t Data_0x1c; //28 = 0x1c
	uint32_t Data_0x20; //32 = 0x20
	uint32_t Data_0x24; //36 = 0x24
	uint32_t Data_0x28; //40 = 0x28
	uint32_t Data_0x2c; //40 = 0x2c
	//48 = 0x30
} Struct_23492994;


//Forward decl.
extern Struct_23492994 Data_23492994;
extern uint8_t Data_234929f4[]; //234929f4
extern uint8_t Data_23492af4[]; //23492af4
void sub_23437834();
void sub_2343783c();
void sub_23437914();
void sub_23437924();
void sub_23437934();
void sub_23437944();
void sub_23437954();
void sub_23437964();

//23492968
Struct_23492994* Data_23492968 = &Data_23492994; //23492968


struct
{
	uint8_t Data_0[5]; //0
}
Data_2349296c[8] = //2349296c
{
   {0x0f, 0x08, 0x3e, 0x1c, 0x08},
   {0x3e, 0x00, 0x08, 0x08, 0x08},
   {0x3e, 0x00, 0x3e, 0x00, 0x08},
   {0x3e, 0x00, 0x3e, 0x00, 0x3e},
   {0x1c, 0x22, 0x22, 0x22, 0x1c},
   {0x3e, 0x1c, 0x08, 0x00, 0x00},
   {0x1c, 0x3e, 0x3e, 0x3e, 0x1c},
   {0x20, 0x30, 0x38, 0x3c, 0x3e}
}; //->23492994

Struct_23492994 Data_23492994 = //23492994
{
		&Data_234929f4[0],
		sub_23437834,
		sub_2343783c,
		sub_23437914,
		sub_23437924,
		0x10,
		0x20,
		0x70,
		0x70,
		0x71,
		0, //Data_0x1c
		0, //Data_0x20
		230, //Data_0x24
		300, //Data_0x28
		0, //Data_0x2c
}; //->234929C4

Struct_23492994 Data_234929c4 = //234929c4
{
		&Data_23492af4[0],
		sub_23437934,
		sub_23437944,
		sub_23437954,
		sub_23437964,
		0x20,
		0x40,
		0xe8,
		0xec,
		0xed,
		28, //Data_0x1c
		5, //Data_0x20
		40, //Data_0x24
		0, //Data_0x28
		0, //Data_0x2c
}; //->234929F4

uint8_t Data_234929f4[0x100] = //234929f4
{
   0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
   0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x08, 0x08,
   0x08, 0x21, 0x22, 0x23, 0xab, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
   0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
   0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
   0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
   0x27, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
   0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x08,
   0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xb6, 0x08, 0x08,
   0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xa5, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
   0x08, 0xb5, 0x08, 0xaa, 0x24, 0x08, 0x7c, 0xbf, 0x22, 0x08, 0xa0, 0xac, 0x08, 0x2d, 0x08, 0x7e,
   0x08, 0xb4, 0x08, 0x08, 0x27, 0xb8, 0x08, 0x08, 0x2c, 0x08, 0xb0, 0xae, 0x08, 0x08, 0x08, 0xb9,
   0x81, 0x80, 0x90, 0xb2, 0x9f, 0xa3, 0xa7, 0x8b, 0x83, 0x82, 0x92, 0x93, 0x85, 0x84, 0x94, 0x95,
   0x08, 0x8a, 0x87, 0x86, 0x96, 0x08, 0xa2, 0x08, 0xbc, 0x89, 0x88, 0x98, 0x99, 0x08, 0x08, 0x8d,
   0x81, 0x80, 0x90, 0xb2, 0x91, 0xb3, 0xbf, 0x9b, 0x83, 0x82, 0x92, 0x93, 0x85, 0x84, 0x94, 0x95,
   0x08, 0x9a, 0x87, 0x86, 0x96, 0x08, 0x97, 0xba, 0xb1, 0x89, 0x88, 0x98, 0x99, 0x08, 0x08, 0x08
};
uint8_t Data_23492af4[0x100] = //23492af4
{
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0xff, 0xff, 0xff,
   0x20, 0x21, 0x22, 0x23, 0xab, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
   0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
   0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
   0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
   0x27, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
   0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0xff,
   0xff, 0xff, 0x2c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcc, 0xff, 0xe3, 0xff, 0xcd, 0xff,
   0xff, 0xff, 0x0c, 0x13, 0x13, 0x0e, 0x5e, 0xa5, 0xff, 0xff, 0xcc, 0xff, 0xf3, 0xff, 0xdd, 0x0f,
   0xff, 0x9e, 0xff, 0xaa, 0x24, 0x08, 0x09, 0xbf, 0x22, 0xff, 0xa0, 0xac, 0x0a, 0x2d, 0xff, 0x7e,
   0x0b, 0xb4, 0xff, 0xff, 0x27, 0xb8, 0x0d, 0xff, 0x2c, 0xb2, 0xff, 0xae, 0xbc, 0xbd, 0xbe, 0xb9,
   0xc1, 0xc0, 0xd0, 0xe0, 0xd1, 0xe1, 0xe2, 0x8b, 0xc3, 0xc2, 0xd2, 0xd3, 0xc5, 0xc4, 0xd4, 0xd5,
   0xce, 0x8a, 0xc7, 0xc6, 0xd6, 0xe6, 0xd7, 0xff, 0xe7, 0xc9, 0xc8, 0xd8, 0xd9, 0xe5, 0xf8, 0x8d,
   0x81, 0x80, 0x90, 0xf0, 0x91, 0xf1, 0xf3, 0x9b, 0x83, 0x82, 0x92, 0x93, 0x85, 0x84, 0x94, 0x95,
   0xef, 0x9a, 0x87, 0x86, 0x96, 0xf6, 0x97, 0xba, 0xf7, 0x89, 0x88, 0x98, 0x99, 0xf5, 0xf8, 0xff
};

#if 0
0x23492994                        dd         0x234929f4
                              dword_23492998:
0x23492998                        dd         sub_23437834                       ; DATA XREF=sub_23437b24+36, sub_23437c3c+44
                              dword_2349299c:
0x2349299c                        dd         sub_2343783c                       ; DATA XREF=sub_23437b24+48, sub_23437c3c+56
                              dword_234929a0:
0x234929a0                        dd         sub_23437914                       ; DATA XREF=sub_23437b24+60
0x234929a4                        dd         sub_23437924
0x234929a8                        db         0x10                               ; DATA XREF=sub_23437b24+96, sub_23437c3c+92
0x234929a9                        db         0x20
0x234929aa                        db         0x70
0x234929ab                        db         0x70
0x234929ac                        dd         0x00000071                         ; DATA XREF=sub_23437d58+32
0x234929b0                        dd         0x00000000
0x234929b4                        dd         0x00000000
0x234929b8                        dd         0x000000e6
                              dword_234929bc:
0x234929bc                        dd         0x0000012c                         ; DATA XREF=sub_234377a8+56, sub_23437844+92
                              dword_234929c0:
0x234929c0                        dd         0x00000000                         ; DATA XREF=dword_23492790+32
0x234929c4                        dd         0x23492af4                         ; DATA XREF=sub_23437974+152, dword_23437d94
0x234929c8                        dd         sub_23437934
0x234929cc                        dd         sub_23437944
0x234929d0                        dd         sub_23437954
0x234929d4                        dd         sub_23437964
0x234929d8                        db         0x20
0x234929d9                        db         0x40
0x234929da                        db         0xe8
0x234929db                        db         0xec
0x234929dc                        dd         0x000000ed
0x234929e0                        dd         0x0000001c
0x234929e4                        dd         0x00000005
0x234929e8                        dd         0x00000028
0x234929ec                        dd         0x00000000
0x234929f0                        dd         0x00000000
#endif

//0x235f3778
struct
{
	Struct_20611068* Data_0; //0
	int Data_4; //4
	int Data_8; //8

} Data_235f3778;


/* 234376f8 - complete */
int sub_234376f8(uint8_t r7)
{
	uint32_t i;
	uint32_t r4 = 1;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_234376f8: r7=0x%02x\r\n", r7);
		console_send_string(debug_string);
	}
#endif

	while (r4 < 0x100)
	{
		//loc_2343770c
		if (r7 & r4)
		{
			gpio_set(Data_235f3778.Data_8, 1);
		}
		else
		{
			gpio_set(Data_235f3778.Data_8, 0);
		}

		gpio_set(Data_235f3778.Data_4, 0);

		for (i = 0; i < Data_23492968->Data_0x1c; i++)
		{
			//loc_2343773c
	#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
			__asm { nop }
	#endif
		}
		//0x2343774c
		gpio_set(Data_235f3778.Data_4, 1);

		for (i = 0; i < Data_23492968->Data_0x20; i++)
		{
			//loc_23437768
	#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
			__asm { nop }
	#endif
		}
		//0x23437778
		r4 <<= 1;
	} //while (r4 < 0x100)
	//0x23437784
	for (i = 0; i < Data_23492968->Data_0x24; i++)
	{
		//loc_23437790
#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
		__asm { nop }
#endif
	}
	//0x234377a0
	return 0;
}


/* 234377a8 - complete */
int sub_234377a8(int r6)
{
	uint32_t i;

#if 0
	console_send_string("sub_234377a8 (todo.c): TODO\r\n");
#endif

	*((volatile uint32_t*)0xc1000020) = 0; //FPC_Config

	gpio_set(Data_235f3778.Data_0, 0);

	sub_234376f8(r6);

	for (i = 0; i < Data_23492968->Data_0x28; i++)
	{
		//loc_234377e8
#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
		__asm { nop }
#endif
	}
	//0x234377f8
	gpio_set(Data_235f3778.Data_0, 1);
	gpio_set(Data_235f3778.Data_8, 6);
	gpio_set(Data_235f3778.Data_4, 5);

	*((volatile uint32_t*)0xc1000020) = 0x21; //FPC_Config

	sub_2342e3b0(1);

	return 0;
}


/* 23437834 - todo */
void sub_23437834()
{
	sub_234377a8(0x64);
}


/* 2343783c - todo */
void sub_2343783c()
{
	sub_234377a8(0x57);
}


/* 23437844 - complete */
int sub_23437844(uint8_t r4, uint8_t r8, uint32_t r7)
{
	uint32_t i;

#if 0
	console_send_string("sub_23437844 (todo.c): TODO\r\n");
#endif

	*((volatile uint32_t*)0xc1000020) = 0x00; //FPC_Config

	gpio_set(Data_235f3778.Data_0, 0);

	sub_234376f8(r4);
	//->loc_2343788c
	for (i = 0; i < r7; i++)
	{
		//loc_23437880
		sub_234376f8(r8);
	}
	//0x23437894
	for (i = 0; i < Data_23492968->Data_0x28; i++)
	{
		//loc_234378a8
#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
		__asm { nop }
#endif
	}
	//0x234378b8
	gpio_set(Data_235f3778.Data_0, 1);
	gpio_set(Data_235f3778.Data_8, 6);
	gpio_set(Data_235f3778.Data_4, 5);

	*((volatile uint32_t*)0xc1000020) = 0x21; //FPC_Config

	sub_2342e3b0(1);

	for (i = 0; i < Data_23492968->Data_0x2c; i++)
	{
		//loc_234378fc
#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
		__asm { nop }
#endif
	}
	//0x2343790c
	return 0;
}


/* 23437914 - todo */
void sub_23437914()
{
	sub_23437844(0x10, 0x20, 0x0c);
}


/* 23437924 - todo */
void sub_23437924()
{
	sub_23437844(0x20, 0x00, 0x28);
}


/* 23437934 - todo */
void sub_23437934()
{
	sub_23437844(0xe0, 0x0b, 0x01);
}


/* 23437944 - todo */
void sub_23437944()
{
	sub_23437844(0xe4, 0xff, 0x01);
}


/* 23437954 - todo */
void sub_23437954()
{
	sub_23437844(0x20, 0x0c, 0x20);
}


/* 23437974 - todo */
void sub_23437964()
{
	sub_23437844(0x40, 0x00, 0x28);
}


/* 23437974 - todo */
int vfd_init(Struct_23437974* r4)
{
	Struct_20401328 gpioParams;
	Struct_20611068* sp;
	uint32_t i;
	uint32_t j;
	uint32_t k;

#if 0
	console_send_string("vfd_init (todo.c): TODO\r\n");
#endif

	if (r4 == 0)
	{
		return 1;
	}
	//loc_2343798c
	if (Data_235f3778.Data_0 == 0)
	{
		sub_23436570(&Data_235f3778.Data_8, &Data_235f3778.Data_4);

		gpioParams.dwOutFunction = 1;
		gpioParams.dwInFunction = 0xff;
		gpioParams.bPin = r4->Data_0;

		if (0 != gpio_open(&gpioParams, &Data_235f3778.Data_0))
		{
			Data_235f3778.Data_0 = 0;
			//->loc_23437980
			return 1;
		}
	}
	//loc_234379d8
	if (0 != sys_get_device_id())
	{
		Data_23492968 = &Data_23492994;
		//->loc_23437a38
	}
	else
	{
		//0x234379f0
		gpioParams.bPin = 0x5e;
		gpioParams.dwInFunction = 0;
		gpioParams.dwOutFunction = 0xff;

		if (0 != gpio_open(&gpioParams, &sp))
		{
			Data_23492968 = &Data_234929c4;
			//->loc_23437a38
		}
		else
		{
			//0x23437a1c
			if (0 != sub_2341abfc(sp))
			{
				Data_23492968 = &Data_234929c4;
			}
			else
			{
				Data_23492968 = &Data_23492994;
			}

			gpio_close(sp);
		}
	}
	//loc_23437a38
	(Data_23492968->Data_4)();
	(Data_23492968->Data_8)();
	(Data_23492968->Data_12)();
	(Data_23492968->Data_16)();

	*((volatile uint32_t*)0xc1000020) = 0; //FPC_Config

	gpio_set(Data_235f3778.Data_0, 0);

	sub_234376f8(Data_23492968->bData_0x15);

	for (i = 0; i < 8; i++)
	{
		//loc_23437a90
		for (j = 0; j < 5; j++)
		{
			//loc_23437a9c
			sub_234376f8(Data_2349296c[i].Data_0[j]);
		}
	}
	//0x23437abc
	for (k = 0; k < Data_23492968->Data_0x28; k++)
	{
		//loc_23437acc
#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
		__asm { nop }
#endif
	}

	gpio_set(Data_235f3778.Data_0, 1);
	gpio_set(Data_235f3778.Data_8, 6);
	gpio_set(Data_235f3778.Data_4, 5);

	*((volatile uint32_t*)0xc1000020) = 0x21; //FPC_Config

	sub_2342e3b0(1);

	sub_234377a8(Data_23492968->bData_0x16);

	return 0;
}


/* 23437b24 - complete */
int sub_23437b24(uint8_t* sb)
{
#if 0
	console_send_string("sub_23437b24 (todo.c): TODO\r\n");
#endif

	if (Data_235f3778.Data_0 == 0)
	{
		return 1;
	}

	(Data_23492968->Data_4)();
	(Data_23492968->Data_8)();
	(Data_23492968->Data_12)();

	FREG(0xc1000020)[0] = 0; //FPC_Config

	gpio_set(Data_235f3778.Data_0, 0);

	sub_234376f8(Data_23492968->bData_0x14);

	uint32_t r5, i;
	for (r5 = i = 0; i < strlen(sb); i++)
	{
		//loc_23437b98
		if (r5 > 11)
		{
			//->loc_23437bd4
			break;
		}

		uint8_t ch = sb[i];
		if (ch > 0x18)
		{
			sub_234376f8(Data_23492968->Data_0[ch]);

			r5++;
		}
		//loc_23437bc0
	}
	//loc_23437bd4
	for (uint32_t i = 0; i < Data_23492968->Data_0x28; i++)
	{
		//loc_23437be4
#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
		__asm { nop }
#endif
	}
	//0x23437bf4
	gpio_set(Data_235f3778.Data_0, 1);
	gpio_set(Data_235f3778.Data_8, 6);
	gpio_set(Data_235f3778.Data_4, 5);

	FREG(0xc1000020)[0] = 0x21; //FPC_Config

	sub_2342e3b0(1);

	sub_234377a8(Data_23492968->bData_0x17);

	return 0;
}


/* 23437c3c - todo */
int vfd_display_text(uint8_t* sl, uint32_t r4, uint32_t r2)
{
	uint32_t i; //r4
	uint32_t j; //r5
	uint32_t r6;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "vfd_display_text: sl='%s', r4=%d, r2=%d\r\n", sl, r4, r2);
		console_send_string(debug_string);
	}
#endif

	if (Data_235f3778.Data_0 == 0)
	{
#if 0
		console_send_string("vfd_display_text: uninitialized!\r\n");
#endif
		return 1;
	}

	r6 = r2 - r4;

	(Data_23492968->Data_4)();
	(Data_23492968->Data_8)();

	*((volatile uint32_t*)0xc1000020) = 0x00; //FPC_Config

	gpio_set(Data_235f3778.Data_0, 0);

	sub_234376f8(r4 + Data_23492968->bData_0x14);

	//->loc_23437ce0
	for (i = 0, j = 1; i < strlen(sl); i++)
	{
		uint8_t ch;

		//loc_23437cb4
		if (j > r6)
		{
			//->loc_23437cf0
			break;
		}

		ch = sl[i];
		if (ch != 0)
		{
			sub_234376f8(Data_23492968->Data_0[ch]);

			j++;
		}
		//loc_23437cdc
	} //for (i = 0; i < strlen(sl); i++)
	//loc_23437cf0
	for (i = 0; i < Data_23492968->Data_0x28; i++)
	{
		//loc_23437d00
#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
		__asm { nop }
#endif
	}
	//0x23437d10
	gpio_set(Data_235f3778.Data_0, 1);
	gpio_set(Data_235f3778.Data_8, 6);
	gpio_set(Data_235f3778.Data_4, 5);

	*((volatile uint32_t*)0xc1000020) = 0x21; //FPC_Config

	sub_2342e3b0(1);

	sub_234377a8(Data_23492968->bData_0x17);

	return 0;
}


/* 23437d58 - complete */
int sub_23437d58()
{
#if 0
	console_send_string("sub_23437d58 (todo.c): TODO\r\n");
#endif

	if (Data_235f3778.Data_0 == 0)
	{
		return 1;
	}

	sub_234377a8(Data_23492968->bData_0x18);

	return 0;
}


