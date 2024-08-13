
#include "data.h"
#include "usb_msd.h"
#include "sub_2345609c.h"


typedef struct
{
	int fill_0[3]; //0
	uint8_t fill_0xc; //0xc = 12
	uint8_t bData_0xd; //0xd = 13
	uint16_t fill_0xe; //0xe = 14
	uint8_t bData_0x10; //0x10 = 16
	int fill_0x14[107]; //0x14
	uint16_t fill_0x1c0; //0x1c0 = 448
	uint8_t bData_0x1c2; //0x1c2
} Struct_234920d8;


//234920d4 /  / 234c0530
void* Data_234920d4 = 0; //234920d4 +0 /  / 234c0530
void* Data_234920d8 = 0; //234920d8 +4 /  / 234c0534
int Data_234920dc = 0; //234920dc +8

struct
{
	int fill_0[193]; //0
	//0x304???
} Data_235af2cc; //235af2cc /  / 2361E8A4

typedef struct
{
	uint8_t bData_0; //0
	uint8_t fill_1; //1
	uint16_t wData_2; //2
	int fill_4[2]; //4
	int Data_0xc; //0xc = 12
	int Data_0x10; //0x10
	int Data_0x14; //0x14
	int Data_0x18; //0x18 = 24
	int Data_0x1c; //0x1c = 28
	int fill_0x20[6]; //0x20
	void (*Data_0x38)(); //0x38
	void (*Data_0x3c)(); //0x3c
	int fill_0x40[2]; //0x40
	void (*Data_0x48)(); //0x48
	int/*MUSB_HfiDevice*/ Data_0x4c; //0x4c
	//0x50 = 80
} Struct_235af5d0;

Struct_235af5d0 Data_235af5d0[1]; //235af5d0 /  / 2361eba8

struct
{
	int fill_0[430]; //0
	//0x6b8
} Data_235af620; //235af620 /  / 2361ebf8



uint16_t sub_23416a68(int a);


/* 23414cfc - todo */
int sub_23414cfc(int a)
{
#if 1
	console_send_string("sub_23414cfc (todo.c): TODO\r\n");
#endif

	uint8_t sp_0x48;
	uint8_t sp_0x40[8/*size???*/];
	uint8_t sp_0x3d;
	uint16_t sp_0x30;
	int sp_0x2c;
	int sp_0x28;
	int sp_0x24;
	uint16_t sp_0x20;
	uint16_t sp_0x1e;
	uint8_t sp_0x1c;
	uint16_t sp_0x1a;
	uint16_t sp_0x18;
	uint16_t sp_0x16;
	uint8_t sp_0x15;
	uint8_t sp_0xd;

	int r6 = 0;
	int sl = 0;

	Data_234920dc = 0; //r6

	(Data_235af5d0[0].Data_0x38)(Data_235af5d0[0].Data_0x4c, 0, Data_234920d8, 1);

	int sb = 510; //0x1fe; //BS_55AA

	if (0xaa55/*r8*/ != sub_23416a68(sb))
	{
		//loc_23415024
		return 3;
	}
	//0x23414d48
	uint8_t sp_0xc = ((Struct_234920d8*)Data_234920d8)->bData_0x1c2;
	if ((sp_0xc == 0x0c) || (sp_0xc == 0x0b))
	{
		r6 = sub_234145d0(0x1c6);
		//->loc_23414e2c
	}
	else
	{
		//loc_23414d70
		if (0 != sub_234145d0(0x1c))
		{
			//loc_23415024
			return 3;
		}
		int r5 = sub_23416a68(0x11);
		int fp = sub_23416a68(0x16);
		int x = sub_23416a68(0x13);
		if ((r5 | fp | x) != 0)
		{
			//loc_23415024
			return 3;
		}
		//0x23414dac
		r5 = ((Struct_234920d8*)Data_234920d8)->bData_0xd;
		int sp4 = sub_23416a68(0x0e);

		fp = ((Struct_234920d8*)Data_234920d8)->bData_0x10;
		int sp8 = sub_23416a68(0x20);

		uint32_t r0 = sub_23416a68(0x24);
		uint32_t r1 = fp * r0 + sp4; //TODO!!!
		r0 = (sp8 - r1) / r5;
		if (r0 < 0xfff5)
		{
			//loc_23415024
			return 3;
		}
		//0x23414e00
		sub_23416a88(0x52, &sp_0x40, 8);

		sp_0x40[8] = 0; //sl

		if (0 != strncmp(&sp_0x40[0], "FAT32", 5))
		{
			//loc_23415024
			return 3;
		}
		//loc_23414e2c
	}
	//loc_23414e2c
	Data_234920dc = r6;

	(Data_235af5d0[0].Data_0x38)(Data_235af5d0[0].Data_0x4c, r6, Data_234920d8, 1);

	if (0xaa55/*r8*/ != sub_23416a68(sb))
	{
		//loc_23415024
		return 3;
	}
	//0x23414e58
	uint8_t* r5 = &sp_0xc;
	sp_0x15 = 0; //sl

	sub_23416a88(0x03, &sp_0xd, 8);

	sp_0x16 = sub_23416a68(0x0b);

	sp_0x1a = sub_23416a68(0x0e);

	sp_0x1c = ((Struct_234920d8*)Data_234920d8)->bData_0x10;

	sp_0x1e = sub_23416a68(0x11);

	sp_0x20 = sub_23416a68(0x16);

	sp_0x24 = sub_234145d0(0x1c);
	if (sp_0x24 == 0)
	{
		sp_0x24 = r6;
	}

	sp_0x28 = sub_234145d0(0x24);

	sp_0x2c = sub_234145d0(0x2c);

	sp_0x30 = sub_23416a68(0x30);

	sp_0x3d = 0; //sl

	if ((sp_0xc == 0x0f) ||
			(((Struct_234920d8*)Data_234920d8)->bData_0xd == 0))
	{
		//0x23414efc
		sp_0x18 = sub_23416a68(0x18);
	}
	else
	{
		//loc_23414f04
		sp_0x18 = ((Struct_234920d8*)Data_234920d8)->bData_0xd;
	}

	sub_23416a88(0x47, &r5[0x26]/*&sp_0x32*/, 0x0b);

	sub_23416a88(0x52, &sp_0x40, 8);

	sp_0x48 = 0;
	Data_235af5d0[0].wData_2 = sp_0x18;

	int r5_ = sp_0x20;
	if (r5_ == 0)
	{
		r5_ = sp_0x28;
		Data_235af5d0[0].bData_0 = 1;
		Data_235af5d0[0].Data_0xc = sp_0x2c;
	}
	else
	{
		Data_235af5d0[0].bData_0 = 0; //sl
		Data_235af5d0[0].Data_0xc = 1;
	}

	int r0_ = (((sp_0x1e * 32) + sp_0x16) - 1) / sp_0x16;

	Data_235af5d0[0].Data_0x18 = r5_;

	Data_235af5d0[0].Data_0x1c = (sp_0x16 / 4) * r5_;

	Data_235af5d0[0].Data_0x10 = sp_0x24 + sp_0x1a;

	if (sp_0x1c == 2)
	{
		Data_235af5d0[0].Data_0x14 = Data_235af5d0[0].Data_0x10 + r5_;
	}
	else
	{
		Data_235af5d0[0].Data_0x14 = 0; //sl
	}
	//0x23414fa0

	//TODO!!!
}


/* 23415f44 /  / 2341d958 - complete */
int sub_23415f44(Struct_23415f44* r4)
{
#if 0
	console_send_string("sub_23415f44 (todo.c): TODO\r\n");
#endif

	memset(Data_235af5d0, 0, sizeof(Data_235af5d0));

	Data_235af5d0[0].Data_0x38 = r4->Data_0;
	Data_235af5d0[0].Data_0x3c = r4->Data_4;
	Data_235af5d0[0].Data_0x4c = r4->Data_0x18;
	Data_235af5d0[0].Data_0x48 = r4->Data_20;

	Data_234920d8 = &Data_235af2cc;

	if (Data_234920d4 == 0)
	{
		Data_234920d4 = OSSemCreate(1);
	}

	memset(&Data_235af620, 0, sizeof(Data_235af620));

    return 0;
}


/* 23415fb4 /  / 2341d9c8 - complete */
int sub_23415fb4(void)
{
#if 0
	console_send_string("sub_23415fb4 (todo.c): TODO\r\n");
#endif

	sub_23416a38();

	if (0 != sub_23414cfc(0))
	{
		OSSemPost(Data_234920d4);

		return 0xff;
	}
	else
	{
		//loc_23415fe0
		sub_23415488(&Data_235af5d0[0]);

		OSSemPost(Data_234920d4);

		return 0;
	}
}


/* 23415ff8 /  / 2341da0c - complete */
int sub_23415ff8(int r4)
{
#if 0
	console_send_string("sub_23415ff8 (todo.c): TODO\r\n");
#endif

	sub_23416a38();

	Data_235af5d0[r4].Data_0x4c = 0;

	OSSemPost(Data_234920d4);

	return 0;
}


/* 234168d0 - todo */
int/*MUSB_HfiDevice*/ sub_234168d0(int a)
{
#if 0
	console_send_string("sub_234168d0 (todo.c): TODO\r\n");
#endif

	Struct_235af5d0* r4_ = &Data_235af5d0[a];

	sub_23416a38();

	int/*MUSB_HfiDevice*/ r4 = r4_->Data_0x4c;

	OSSemPost(Data_234920d4);

	return r4;
}


/* 23416a38 /  / 2341e44c - complete */
int sub_23416a38(void)
{
#if 0
	console_send_string("sub_23416a38 (todo.c): TODO\r\n");
#endif

	uint8_t err;

	OSSemPend(Data_234920d4, 0, &err);

	return err;
}


/* 23416a68 - todo */
uint16_t sub_23416a68(int a)
{
#if 0
	console_send_string("sub_23416a68 (todo.c): TODO\r\n");
#endif

	uint16_t r0;

	uint8_t* r2 = (uint8_t*)Data_234920d8;

	//r0 = (r2[a+1] << 8) + r2[a];
	r0 = *r2++;
	r0 += (*r2 << 8);

	return r0;
}


