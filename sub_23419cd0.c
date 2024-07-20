
#include "data.h"
#include "flash.h"
#include "sub_23419cd0.h"


//23492114
OS_EVENT* Data_23492114 = 0; //23492114 +0


struct Struct_235b0cf8_Inner4
{
	uint32_t Data_0; //0
	uint32_t Data_4; //4
	//8
};

struct Struct_235b0cf8
{
	struct Struct_235b0cf8_Inner0
	{
		struct Struct_235b0cf8_Inner4 Data_0[500]; //0
		int fill_0xfa0[0x3C17]; //0xFA0
		int Data_0xfffc; //0xFFFC
		//0x10000
	}* Data_0; //0
	struct Struct_235b0cf8_Inner4* Data_4; //4
	uint32_t Data_8; //8
	int Data_0xc; //12

} Data_235b0cf8; //235b0cf8

Struct_23419cd0 Data_235b0d08; //235b0d08


/* 23419cd0 - complete */
int sub_23419cd0(Struct_23419cd0* r4)
{
#if 0
	console_send_string("sub_23419cd0 (todo.c): TODO\r\n");
#endif

	Data_235b0cf8.Data_0 = r4->Data_8;
	Data_235b0cf8.Data_4 = &Data_235b0cf8.Data_0->Data_0[0];

	flash_read(r4->hFlash, r4->Data_0, 0x10000, Data_235b0cf8.Data_0);

	int crcRead = Data_235b0cf8.Data_0->Data_0xfffc; //((int*)(Data_235b0cf8.Data_0 + 0xfffc))[0];

	Data_235b0cf8.Data_8 = 500 * sizeof(struct Struct_235b0cf8_Inner4); //0xfa0;

	int crcCalc = crc32((void*) (Data_235b0cf8.Data_0), 0xfffc);

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23419cd0: crcRead=0x%x, crcCalc=0x%x\r\n", crcRead, crcCalc);
		console_send_string(debug_string);
	}
#endif

	if (crcCalc != crcRead)
	{
		memset(Data_235b0cf8.Data_0, 0, 0x10000);
		//->loc_23419d60
	}
	else
	{
		//loc_23419d2c
		for (uint32_t r0 = 0; r0 < 500; r0++)
		{
			//loc_23419d34
			uint32_t r1 = Data_235b0cf8.Data_4[r0].Data_4;
			if (r1 != 0)
			{
				r1 = r1 + Data_235b0cf8.Data_4[r0].Data_0;

				if (Data_235b0cf8.Data_8 < r1)
				{
					Data_235b0cf8.Data_8 = r1;
				}
			}
		}
		//loc_23419d60
	}
	//loc_23419d60
	Data_235b0d08 = *r4;

	Data_235b0cf8.Data_0xc = 0;

	Data_23492114 = OSSemCreate(1);

	return 0;
}


