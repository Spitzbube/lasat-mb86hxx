
#include "data.h"
#include "sys_services.h"


//23492654
OS_EVENT* Data_23492654/*sema*/ = 0; //23492654 +0
int Data_23492658 = 0; //23492658 +4


typedef struct
{
	int Data_0; //0
	Struct_2342e0cc Data_4; //4
	uint16_t wData_24; //24 = 0x18
	uint16_t wData_26; //26 = 0x1a
	//28
} Struct_235f3094;

Struct_235f3094 Data_235f3094[2];



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


/* 2342e0cc / 2343c118 - complete */
void* sub_2342e0cc(Struct_2342e0cc* r5)
{
#if 0
	console_send_string("sub_2342e0cc (todo.c): TODO\r\n");
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

