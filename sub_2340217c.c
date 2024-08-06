
#include <stdint.h>
#include "data.h"
#include "i2c.h"
#include "sub_2340a6a0.h"
#include "mt_fe_tn_tc3800.h"
#include "Struct_23443080.h"
#include "m88dc2800.h"
#include "sub_2340217c.h"


extern void sub_23442dcc();
extern void sub_23442e04();
extern void sub_23442e3c();

#pragma thumb

typedef struct
{
	I2c_Bus* Data_0; //0

} Struct_2340217c_Inner_0x1c;

typedef struct
{
	int fill_0[5]; //0
	uint8_t bData_20; //20 = 0x14
	uint8_t bData_21; //21 = 0x15
	int fill_0x18; //24 = 0x18
	void* Data_0x1c; //28

} Struct_2340217c;

typedef struct
{
	void* hI2c;
	int Data_4; //4
	int fill_8; //8
#if 0
	void (*Data_0xc); //0x0c = 12
	void (*Data_0x10); //0x10 = 16
	void (*Data_0x14); //0x14 = 20
	void (*Data_0x18); //0x18 = 24
	void (*Data_0x1c); //0x1c = 28
	uint8_t bData_0x20; //0x20 = 32
	uint8_t bData_0x21; //0x21 = 33
	int fill_0x24; //0x24
	void* Data_0x28; //0x28
#else
	Struct_23472f1c_Inner16 Data_0xc; //0xc = 12
#endif
	void (*Data_0x2c)(); //0x2c = 44
	void (*Data_0x30)(); //0x30 = 48
	void (*Data_0x34)(); //0x34
	void (*Data_0x38)(); //0x38
	void (*Data_0x3c)(); //0x3c
	uint8_t bData_0x40; //0x40
	uint8_t bData_0x41; //0x41
	int fill_0x44; //0x44
	void* Data_0x48; //0x48
#if 0
	int Data_0x4c; //0x4c
	int fill_0x50[8]; //0x50
#else
	Struct_23476318 Data_0x4c; //0x4c = 76
#endif
#if 0
	int Data_0x70; //0x70
	int fill_0x74[5]; //0x74
	int Data_0x88; //0x88
	int Data_0x8c; //0x8c
	int Data_0x90; //0x90
	int Data_0x94; //0x94
	int Data_0x98; //0x98
	int Data_0x9c; //0x9c
	int Data_0xa0; //0xa0
	int Data_0xa4[2]; //0xa4
	int Data_0xac; //0xac
	int Data_0xb0; //0xb0
#else
	/*Struct_23472ef0_4*/Struct_23472f1c Data_0x70; //0x70 +0x5c = 0xcc!
#endif
#if 0
	int Data_0xcc; //0xcc
	int fill_0xd0[11]; //0xd0
#else
	Struct_23442f9a_4 Data_0xcc; //0xcc = 204
#endif
#if 0
	int Data_0xfc; //0xfc
	int fill_0x100[3]; //0x100
#else
	/*Struct_23442940_4*/Struct_23442966 Data_0xfc; //0xfc
	int fill_0x108; //0x108
#endif
	uint8_t bData_268; //268 = 0x10C
	uint8_t arData_269[3]; //269 = 0x10d, size?
	//0x110 = 272
} Struct_234a5270;


uint8_t bData_23491e1c = 0; //23491e1c

Struct_234a5270 Data_234a5270[2] = //234a5270, size? -> 234A5490
{
		{0},
		{0}
};


/* 23402130 - complete */
int sub_23402130(int a, int b)
{
	int r0;
#if 0
	console_send_string("sub_23402130 (todo.c): TODO\r\n");
#endif

	r0 = b / 10;
	if (r0 == 0)
	{
		r0 = 1;
	}

	rtos_task_wait((uint16_t)r0);

	return 0;
}


/* 2340214a - todo */
void sub_2340214a()
{
#if 1
	console_send_string("sub_2340214a (todo.c): TODO\r\n");
#endif

}


/* 2340217c - todo */
int sub_2340217c(Struct_2340217c* r0, uint8_t r5, uint8_t r2[], uint32_t r4)
{
	int res;
	int r1;
	uint8_t r7;
	uint8_t sp[10]; //size?

	Struct_2340217c_Inner_0x1c* r6 = r0->Data_0x1c;

	if (r4 > 6)
	{
		//loc_234021b4
		return 2;
	}

	r1 = r0->bData_20;
	sp[0] = r0->bData_21;
	sp[1] = r5;

	for (r7 = 0; r7 < r4; r7++)
	{
		//loc_23402196
		sp[2 + r7] = r2[r7];
	}
	//0x234021a4
	res = i2c_master_send(r6->Data_0, r1, sp, r4 + 2);
	res &= 0xff;
	if (res != 0)
	{
		return 2;
	}

	return 0;
}


/* 234021b8 - complete */
int sub_234021b8(Struct_23472f1c_Inner16* p, int addr, uint8_t* pData, int numBytes, int e)
{
	Struct_234a5270* r4;
	uint8_t res = 0;

#if 0
	console_send_string("sub_234021b8 (todo.c): TODO\r\n");
#endif

	r4 = p->Data_0x1c;

	if (r4->bData_268 != 0)
	{
		if (r4->bData_268 <= 2)
		{
			res = i2c_master_read_reg(r4->hI2c, addr, (r4->arData_269[1] << 8) | r4->arData_269[0], pData, numBytes);
		}
		//loc_234021e6
		r4->bData_268 = 0;
		//->loc_234021f8
	}
	else
	{
		//loc_234021ec
		res = i2c_master_receive(r4->hI2c, addr, pData, numBytes);
	}
	//loc_234021f8
	if (res != 0)
	{
		return 2;
	}

	return res;
}


/* 23402200 - complete */
int sub_23402200(Struct_23472f1c_Inner16* r0, int addr, uint8_t data[], int count, uint32_t flags)
{
	uint32_t i;
	Struct_234a5270* r4;

#if 0
	console_send_string("sub_23402200 (todo.c): TODO\r\n");
#endif

	r4 = r0->Data_0x1c;

	if ((flags & 2) == 0)
	{
		//0x2340220a
		r4->bData_268 = count;

		for (i = 0; i < count; i++)
		{
			//loc_23402214
			r4->arData_269[i] = data[i];
		}
		//->loc_23402236
	}
	else
	{
		//loc_23402226
		if (0xff & i2c_master_send(r4->hI2c, addr, data, count))
		{
			return 2;
		}
	}
	//loc_23402236
	return 0;
}


/* 23402280 - complete */
int sub_23402280()
{
#if 0
	console_send_string("sub_23402280 (todo.c): TODO\r\n");
#endif

	if (bData_23491e1c != 0)
	{
		memset(Data_234a5270, 0, sizeof(Data_234a5270));

		bData_23491e1c = 1;
	}

	return 0;
}


/* 2340229c - todo */
int sub_2340229c(Struct_2340e754* r5, uint8_t b)
{
	Struct_234a5270* r4;
	void* sp8;

#if 0
	console_send_string("sub_2340229c (todo.c): TODO\r\n");
#endif

	r4 = &Data_234a5270[b & 1];

	if (r4->hI2c == 0)
	{
		r4->hI2c = r5->hI2c;
		r4->bData_268 = 0; //r6
		r4->bData_0x40 = r5->bData_9;
		r4->bData_0x41 = 0x09;
		r4->Data_0x2c = sub_2340214a;
		r4->Data_0x34 = sub_23442dcc;
		r4->Data_0x30 = sub_2340217c;
		r4->Data_0x38 = sub_23442e04;
		r4->Data_0x48 = r4;
		r4->Data_0x3c = sub_23442e3c;

	//	sp8 = &r4->Data_0xcc;

		sub_23442f9a(r5->bData_8, 0x29, &r4->Data_0x2c, 0x80000000,
				&r4->Data_0x4c, &r4->Data_0xcc);

		r4->Data_0xc.bData_0x14 = 0; //r6
		r4->Data_0xc.bData_0x15 = 0; //r6
		r4->Data_0xc.i2c_master_receive = sub_234021b8;
		r4->Data_0xc.i2c_read_reg = sub_23442dcc;
		r4->Data_0xc.i2c_master_send = sub_23402200;
		r4->Data_0xc.i2c_write_reg = sub_23442e04;
		r4->Data_0xc.Data_0x1c = r4;
		r4->Data_0xc.i2c_write_reg_byte = sub_23442e3c;

		sub_23442940(0, r5->bData_9, &r4->Data_0xc, &r4->Data_0x70,
				/*sp8*/&r4->Data_0xcc, &r4->Data_0xfc/*r7*/);

		r4->Data_0x70.Data_0x18 = 0x167a61; //r1
		r4->Data_0x70.Data_0x24 = 0x167a61;
		r4->Data_0x70.Data_0x1c = 0x1a3972; //r3
		r4->Data_0x70.Data_0x20 = 0x1df882; //r5
		r4->Data_0x70.Data_0x30 = 0x1df882; //r5
		r4->Data_0x70.Data_0x2c = 0x1a3972; //r3
		r4->Data_0x70.Data_0x3c = 0x1e985a; //r2
		r4->Data_0x70.Data_0x28 = 0x167a61; //r1
		r4->Data_0x70.Data_0x40 = 2;
		r4->Data_4 = 0; //r6;

		if (0 == sub_23442966(&r4->Data_0xfc/*r7*/))
		{
			return 0;
		}
		else
		{
			r4->hI2c = 0;

			return 6;
		}
	}
	else
	{
		return 6;
	}
}

