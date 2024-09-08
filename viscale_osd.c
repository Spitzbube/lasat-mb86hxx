
#include "data.h"
#include "sys_services.h"
#include "viscale_osd.h"


const int Data_23489b1c[] = //23489b1c
{
	0x00000000, 0xf0000000, 0xff000000, 0xfff00000,
	0xffff0000, 0xfffff000, 0xffffff00, 0xfffffff0
};


//23492654
OS_EVENT* Data_23492654/*sema*/ = 0; //23492654 +0
int Data_23492658 = 0; //23492658 +4


typedef struct
{
	int Data_0; //0
	Viscale_Osd_Params Data_4; //4
	uint16_t wData_24; //24 = 0x18
	uint16_t wData_26; //26 = 0x1a
	//28
} Struct_235f3094;

Struct_235f3094 Data_235f3094[2];

static void sub_2342e2d8(void* a, uint32_t* b, uint8_t c, int d);

typedef struct 
{
	int fill_0[2]; //0
	uint16_t wData_8; //8
	uint16_t wData_0xa; //10
	int fill_0xc; //12
	uint16_t wData_0x10; //16
	uint16_t wData_0x12; //18
	int fill_0x14; //20
	int Data_0x18; //24
	int fill_0x1c[4]; //28
	int Data_0x2c; //44
	uint16_t wData_0x30; //48
	uint8_t bData_0x32; //50
	int fill_0x34; //52

} Struct_2342cd1c;


/* 2342cd1c - todo */
void sub_2342cd1c(Struct_2342cd1c* a)
{
	uint32_t r2 = a->wData_0x10;
	uint32_t r1 = a->wData_8;
	uint32_t ip = a->wData_0x12;
	uint32_t r5 = r2 & 0x07;

	r1 = r1 + r5;
	int r3 = r1 + 7;
	int r8 = r1 & 0x07;
	int r7 = r3 >> 3;
	r3 = a->wData_0x30;
	r1 = a->Data_0x2c;
	r2 = r2 >> 3;
	int r6 = a->wData_0xa;
	r3 = r3 * ip;
	ip = a->Data_0x18;

	r1 = r1 + r3 * 4;
	int r4 = r1 + r2 * 4;

	int i = 8;
	while (i--)
	{
		//loc_2342cd64
		ip = ip | (ip << 4);
	}
	//sb, =0x23489b1c
	//->loc_2342ce10
	while (r6--)
	{
		//loc_2342cd78
		int* r1 = r4;
		int r2 = r7;
		int r3 = r8;
		if (r5 != 0)
		{
			//0x2342cd8c
			int lr = Data_23489b1c[r5];
			r2--;
			if (r2 == 0)
			{
				//0x2342cd98
				if (r3 != 0)
				{
					r3 = Data_23489b1c[r3];
					r3 = -r3;
					lr = lr | r3;
					r3 = 0;
				}
			}
			//loc_2342cdac
			int sl = r1[0];
			sl = sl & lr;
			lr = ip & ~lr;
			lr = lr | sl;
			*r1++ = lr;
		}
		//->loc_2342cdc0
		if (r2 != 0)
		{
			//0x2342cdc8
			if (r3 != 0)
			{
				r2--;
				//->loc_2342cddc
			}

			while (r2 != 0)
			{
				//loc_2342cdd4
				r2--;
				*r1++ = ip;
			}
		}
		//loc_2342cde4
		if (r3 != 0)
		{
			//0x2342cdec
			int r2 = Data_23489b1c[r3];
			int lr = -r2;
			r2 = *r1;
			int r3 = ip & ~lr;
			r2 = r2 & lr;
			r2 = r2 | r3;
			*r1 = r2;
		}
		//loc_2342ce08
		r4 = r4 + (a->wData_0x30 * 4);
	} //while (r6--)
}


/* 2342ce1c /  / - complete */
int viscale_osd_layer_enable(void* h)
{
#if 1
	console_send_string("viscale_osd_layer_enable (todo.c): TODO\r\n");
#endif

	Struct_235f3094* r0 = h;
	if (r0 == 0)
	{
		return 0xff;
	}

	FREG(0xCB004040 + r0->Data_4.Data_8)[0] = 1; //VO_LAYERENABLE

	return 0;
}


/* 2342ce40 /  /  - complete */
int viscale_osd_layer_disable(void* h)
{
#if 1
	console_send_string("viscale_osd_layer_disable (todo.c): TODO\r\n");
#endif

	Struct_235f3094* r0 = h;
	if (r0 == 0)
	{
		return 0xff;
	}

	FREG(0xCB004040 + r0->Data_4.Data_8)[0] = 0; //VO_LAYERENABLE

	return 0;
}


/* 2342ce64 - todo */
void sub_2342ce64(void)
{
#if 0
	console_send_string("sub_2342ce64 (todo.c): TODO\r\n");
#endif

	while ((FREG(0xcb0100a0)[0]/*VO_DISPPICPOS*/ & 0xfff/*CURRENTVPOS + CURRENTFIELD*/) != 
		(FREG(0xcb010008)[0]/*VO_DISPVERSIZE*/ + 0x7FB))
	{
		//wait
	}
}


/* 2342d42c - complete */
int sub_2342d42c(uint8_t a, int16_t r1, int16_t r2, int16_t r3, int16_t arg_0, uint8_t arg_4)
{
#if 0
	console_send_string("sub_2342d42c (todo.c): TODO\r\n");
#endif

	Struct_2342cd1c sp;

	Struct_235f3094* ip = &Data_235f3094[a];

	sp.wData_0x30 = 0x60;
	sp.bData_0x32 = a;
	sp.wData_8 = r3 + 1;
	sp.wData_0x10 = r1;
	sp.wData_0x12 = r2;
	sp.wData_0xa = arg_0 + 1;
	sp.Data_0x18 = arg_4;
	sp.Data_0x2c = ip->Data_4.Data_4 & ~0x3ff;

	sub_2342cd1c(&sp);

	return 0;
}


/* 2342d494 - complete */
uint32_t sub_2342d494(int a)
{
#if 0
	console_send_string("sub_2342d494 (todo.c): TODO\r\n");
#endif

    return Data_235f3094[a].wData_24;
}


/* 2342d4a8 - complete */
uint32_t sub_2342d4a8(int a)
{
#if 0
	console_send_string("sub_2342d4a8 (todo.c): TODO\r\n");
#endif

    return Data_235f3094[a].Data_4.Data_4 & ~0x3ff;
}


/* 2342d510 - complete */
static void sub_2342d510(void)
{
#if 0
	console_send_string("sub_2342d510 (todo.c): TODO\r\n");
#endif

	OSSemPost(Data_23492654);
}


/* 2342d51c - complete */
int sub_2342d51c(int a)
{
	uint8_t err;

#if 0
	console_send_string("sub_2342d51c (todo.c): TODO\r\n");
#endif

	Struct_235f3094* r2 = &Data_235f3094[a];

	uint32_t r0 = r2->Data_4.Data_4;
	uint32_t r1 = r2->Data_4.globalOffset;

	if (Data_23492654 != 0)
	{
		sub_23436900(r0, r1, r2->Data_0, sub_2342d510, 0); //->dma.c

		OSSemPend(Data_23492654, 0, &err);
	}

	return 0;
}


/* 2342d570 /  /  - todo */
void viscale_osd_layer_clear(int a)
{
#if 0
	console_send_string("viscale_osd_layer_clear (todo.c): TODO\r\n");
#endif

	Struct_235f3094* r1 = &Data_235f3094[a];
	uint32_t r0 = r1->Data_4.Data_4;

	r0 = r0 & ~0x3ff;

	memset(r0, 0, r1->Data_0);
}


/* 2342d5ac - complete */
void sub_2342d5ac(int a)
{
#if 0
	console_send_string("sub_2342d5ac (todo.c): TODO\r\n");
#endif

	Struct_235f3094* r0 = &Data_235f3094[a];

	uint32_t r1 = r0->Data_4.Data_4;
	uint32_t r2 = r0->Data_4.globalOffset;

	if (r1 != r2)
	{
		r0->Data_4.globalOffset = r1;
		r0->Data_4.Data_4 = r2;

		r1 = r1 & ~0x3ff;

		FREG(0xCB004000 + r0->Data_4.Data_8)[0] = r1; //VO_OSDGLOBALOFFSET
	}
}


/* 2342d5e4 - complete */
void sub_2342d5e4(int a, uint32_t* b, uint8_t c, int d)
{
#if 0
	console_send_string("sub_2342d5e4 (todo.c): TODO\r\n");
#endif

	Struct_235f3094* r0 = &Data_235f3094[a];

	sub_2342e2d8(0xcb007000/*VO_OSD1CLUT*/ + r0->Data_4.Data_8, b, c, d);
}


/* 2342d668 - todo */
void sub_2342d668(int a, int b, int c, int d)
{
	console_send_string("sub_2342d668 (todo.c): TODO\r\n");

}


/* 2342db04 - todo */
void sub_2342db04(void* a, uint32_t r0, uint32_t r5)
{
#if 0
	console_send_string("sub_2342db04 (todo.c): TODO\r\n");
#endif

	Struct_235f3094* r4 = a;
	int sp_0xc = 0;

//	int r2 = 4;
//	int r3 = 1280;

	FREG(0xCB004044 + r4->Data_4.Data_8)[0] |= (1 << 16); //VO_OSDMODE:OSDFIELDMODE
	FREG(0xCB004034 + r4->Data_4.Data_8)[0] = 4; //VO_OSDINITIALSHIFT
	FREG(0xCB00402c + r4->Data_4.Data_8)[0] = 1280; //VO_OSDHORDISPPIXEL

	if (r4->Data_4.Data_8 == 0x4000)
	{
		FREG(0xcb010024)[0] = 0x1040604; //VO_DISPOSD2HORSTARTSTOP
		FREG(0xcb010028)[0] = 0x1902e9; //VO_DISPOSD2VERSTARTSTOP

		sub_2342f28c(r0, 1280, &sp_0xc, 3, 1);

		sub_2342efac(r5, 720, 720, 3, &sp_0xc, 3, 0);
	}
	//loc_2342dbac
	else if (r4->Data_4.Data_8 == 0)
	{
		FREG(0xcb004030)[0] = r0 - 1; //VO_OSDHORREADPIXEL
		FREG(0xcb01001c)[0] = 0x1040604; //VO_DISPOSD1HORSTARTSTOP
		FREG(0xcb010020)[0] = 0x1902e9; //VO_DISPOSD1VERSTARTSTOP

		//int r2 = FREG(0xcb004044 + r4->Data_4.Data_8)[0];
		if (r0 > 720)
		{
			//0x2342dbdc
			FREG(0xcb004044)[0] = FREG(0xcb004044 + r4->Data_4.Data_8)[0] & ~(1 << 16); //interlaced

			sub_2342f28c(r0, 1280, &sp_0xc, 2, 1);

			sub_2342efac(r5 / 2, 720, 720, 0, &sp_0xc, 2, 0);
		}
		else
		{
			//loc_2342dc1c
			FREG(0xcb004044)[0] = FREG(0xcb004044 + r4->Data_4.Data_8)[0] | (1 << 16); //progressive

			sub_2342f28c(r0, 1280, &sp_0xc, 2, 1);

			sub_2342efac(r5, 720, 720, 2, &sp_0xc, 2, 0);
		}
	}
	else
	{
		//loc_2342dc74
		return;
	}

	FREG(0xCB004038 + r4->Data_4.Data_8)[0] = sp_0xc;
}


/* 2342dde4 - todo */
int sub_2342dde4(void* h, uint32_t r0, uint32_t r5)
{
#if 0
	console_send_string("sub_2342dde4 (todo.c): TODO\r\n");
#endif

	Struct_235f3094* r3 = h;
	int sp_0xc = 0;

	FREG(0xCB004034 + r3->Data_4.Data_8)[0] = 4; //VO_OSDINITIALSHIFT
	FREG(0xCB00402c + r3->Data_4.Data_8)[0] = 1920; //VO_OSDHORDISPPIXEL

	if (r3->Data_4.Data_8 == 0x4000)
	{
		//0x2342de3c
		FREG(0xCB008044)[0] |= 0x10000;
		FREG(0xcb010024)[0] = 0xc00840; //VO_DISPOSD2HORSTARTSTOP
		FREG(0xcb010028)[0] = 0x140230; //VO_DISPOSD2VERSTARTSTOP

		sub_2342f28c(r0, 1920, &sp_0xc, 3, 1);
		//r3, #0x0
		//r2, #0x3
		//->loc_2342df10
		sub_2342efac(r5, 540, 540, 2, &sp_0xc, 3, 0);

		FREG(0xCB008038)[0] = sp_0xc; //VO_OSDFILTERMODE
	}
	//loc_2342de78
	else if (r3->Data_4.Data_8 == 0)
	{
		//0x2342de80
		FREG(0xcb004030)[0] = r0 - 1; //VO_OSDHORREADPIXEL
		FREG(0xcb01001c)[0] = 0xc00840; //VO_DISPOSD1HORSTARTSTOP
		FREG(0xcb010020)[0] = 0x140230; //VO_DISPOSD1VERSTARTSTOP

		if (r0 > 720)
		{
			//0x2342dea8
			FREG(0xCB004044)[0] = FREG(0xCB004044 + r3->Data_4.Data_8)[0] & ~(1 << 16);

			sub_2342f28c(r0, 1920, &sp_0xc, 2, 1);
			//->loc_2342df28
			sub_2342efac(r5 / 2, 540, 540, 0, &sp_0xc, 2, 0);
		}
		else
		{
			//loc_2342dee8
			FREG(0xCB004044)[0] = FREG(0xCB004044 + r3->Data_4.Data_8)[0] | (1 << 16);

			sub_2342f28c(r0, 1920, &sp_0xc, 2, 1);

			sub_2342efac(r5, 540, 540, 2, &sp_0xc, 2, 0);
		}

		FREG(0xCB004038)[0] = sp_0xc; //VO_OSDFILTERMODE
	}
	//loc_2342df34
	return 0;
}


/* 2342e0cc / 2343c118 - complete */
void* viscale_osd_open(Viscale_Osd_Params* r5)
{
#if 0
	console_send_string("viscale_osd_open (todo.c): TODO\r\n");
#endif

	Struct_235f3094* r4 = 0;

	for (uint32_t i = 0; i < 2; i++)
	{
		//loc_2342e0e0
		if (Data_235f3094[i].Data_0 == 0)
		{
			r4 = &Data_235f3094[i];
			//->loc_2342e104
			break;
		}
	}
	//loc_2342e104
	if (r4 == 0)
	{
		return 0;
	}

	if (Data_23492654 == 0)
	{
		Data_23492654 = OSSemCreate(0);
	}
	//loc_2342e12c
	if (r5->Data_8 != 0)
	{
		r4->Data_0 = 0x36000;
		r4->Data_4 = *r5;
		r4->wData_24 = 768; //0x300;
		r4->wData_26 = 576; //0x240; //r7

		sub_2342e2d8(0xcb007000/*VO_OSD1CLUT*/ + r4->Data_4.Data_8, &Data_23492658, 0x0f, 0xff);

		FREG(0xCB004044 + r4->Data_4.Data_8)[0] = 0x2a; //VO_OSDMODE
		FREG(0xcb004010 + r4->Data_4.Data_8)[0] = 0x02; //VO_OSDHSIZE
		FREG(0xcb004014 + r4->Data_4.Data_8)[0] = 0x01; //VO_OSDBITPERPIXEL
		FREG(0xcb004030 + r4->Data_4.Data_8)[0] = 0x2CF; //VO_OSDHORREADPIXEL

		sub_2342dde4(r4, 720, 576);

		FREG(0xcb004000 + r4->Data_4.Data_8)[0] = (r4->Data_4.globalOffset & 0xFFFFFC00); //VO_OSDGLOBALOFFSET
		FREG(0xcb004040 + r4->Data_4.Data_8)[0] = 0; //r6; //VO_LAYERENABLE
		//->loc_2342e274
	}
	else
	{
		//loc_2342e210
		r4->Data_0 = 0x19e000;
		r4->Data_4 = *r5;
		r4->wData_24 = 736; //0x2e0;
		r4->wData_26 = 576; //0x240; //r7

		FREG(0xcb004044)[0] = 0x10000; //VO_OSDMODE
		FREG(0xcb004010)[0] = 0x16; //VO_OSDHSIZE
		FREG(0xcb004014)[0] = 0x08; //VO_OSDBITPERPIXEL

		sub_2342dde4(r4, 720, 576);

		FREG(0xcb004000)[0] = (r4->Data_4.globalOffset & 0xFFFFFC00); //VO_OSDGLOBALOFFSET
		FREG(0xcb004040)[0] = 0; //r6; //VO_LAYERENABLE
	}
	//loc_2342e274
	return r4;
}


/* 2342e27c - todo */
int sub_2342e27c(int a, uint16_t b, uint16_t c)
{
#if 0
	console_send_string("sub_2342e27c (todo.c): TODO\r\n");
#endif

	Struct_235f3094* r0 = &Data_235f3094[a];

	if (r0->wData_24 == b)
	{
		return 0xff;
	}

	if (r0->Data_4.Data_8 == 0)
	{
		r0->Data_0 = b * c * 4;
		r0->wData_24 = b;
		r0->wData_26 = c;

		FREG(0xcb004010)[0] = ((r0->wData_24 + 31) / 32) - 1; //VO_OSDHSIZE
	}

	return 0;
}


/* 2342e2d8 - todo */
void sub_2342e2d8(void* a, uint32_t* b, uint8_t c, int d)
{
#if 0
	console_send_string("sub_2342e2d8 (todo.c): TODO\r\n");
#endif

	volatile uint32_t* r0 = a;

	*r0++ = 0;

	while (c--)
	{
		*r0++ = *b++ + d;
	}
}


