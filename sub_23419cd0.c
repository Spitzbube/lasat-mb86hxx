
#include "data.h"
#include "flash.h"
#include "sub_23419cd0.h"


//23492114
OS_EVENT* Data_23492114 = 0; //23492114 +0


struct Struct_235b0cf8_Inner4
{
	uint32_t offset; //0
	uint32_t length; //4
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
	int dirty; //12
	Struct_23419cd0 Data_235b0d08; //235b0d08

} Data_235b0cf8; //235b0cf8



/* 23419908 /  /  - todo */
void sub_23419908(int a)
{
#if 0
	console_send_string("sub_23419908 (todo.c): TODO\r\n");
#endif

	if ((a != 0) &&
		(Data_235b0cf8.dirty != 0))
	{
		flash_write(Data_235b0cf8.Data_235b0d08.hFlash, Data_235b0cf8.Data_235b0d08.Data_0, 0x10000, Data_235b0cf8.Data_0);

		Data_235b0cf8.dirty = 0;
	}
}


/* 23419940 /  /  - todo */
int sub_23419940(uint32_t r4, int sb)
{
#if 0
	console_send_string("sub_23419940 (todo.c): TODO\r\n");
#endif

	uint8_t err; //sp

	OSSemPend(Data_23492114, 0, &err);

	if (err == 0)
	{
		//0x2341996c
		if (r4 < 500)
		{
			//0x23419974
			if (Data_235b0cf8.Data_4[r4].length == 0)
			{
				//0x2341998c
				OSSemPost(Data_23492114);

				return -1;
			}
			//loc_2341999c
			Data_235b0cf8.Data_4[r4].length = 0;

			struct Struct_235b0cf8_Inner4* r7 = ((uint8_t*)Data_235b0cf8.Data_235b0d08.Data_8) + 0x10000;

			memcpy(r7, Data_235b0cf8.Data_4, 0x10000);

			Data_235b0cf8.Data_8 = 4000;

			for (r4 = 0; r4 < 500; r4++)
			{
				//loc_234199c8
				struct Struct_235b0cf8_Inner4* r6 = &r7[r4];
				if (r6->length != 0)
				{
					//0x234199d8
					memcpy(((uint8_t*)Data_235b0cf8.Data_235b0d08.Data_8) + Data_235b0cf8.Data_8,
						((uint8_t*)Data_235b0cf8.Data_235b0d08.Data_8) + r7[r4].offset + 0x10000,
						r6->length);

					Data_235b0cf8.Data_4[r4] = *r6;
					Data_235b0cf8.Data_4[r4].offset = Data_235b0cf8.Data_8;
					Data_235b0cf8.Data_8 += r6->length;
					Data_235b0cf8.dirty = 1;
				}
				//loc_23419a28
				//for (r4 = 0; r4 < 500; r4++)
			}
			//0x23419a34
			Data_235b0cf8.Data_0->Data_0xfffc = crc32(Data_235b0cf8.Data_0, 0xfffc);
		}
		//loc_23419a4c
		sub_23419908(sb);

		OSSemPost(Data_23492114);
	}
	//loc_23419a5c
	return 0;
}


/* 23419a64 - complete */
int sub_23419a64(int idx, uint8_t* str, uint32_t maxLen)
{
#if 0
	console_send_string("sub_23419a64 (todo.c): TODO\r\n");
#endif

	uint8_t err; //sp

	OSSemPend(Data_23492114, 0, &err);

	if (err == 0)
	{
		void* p = Data_235b0cf8.Data_235b0d08.Data_8 + Data_235b0cf8.Data_4[idx].offset;
		uint32_t len;

		if ((Data_235b0cf8.Data_4[idx].length + 1) > (maxLen - 1))
		{
			len = maxLen - 1;
		}
		else
		{
			len = Data_235b0cf8.Data_4[idx].length;
		}

		memcpy(str, p, len);

		str[len] = 0;

		OSSemPost(Data_23492114);
	}

	return 0;
}


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
			uint32_t r1 = Data_235b0cf8.Data_4[r0].length;
			if (r1 != 0)
			{
				r1 = Data_235b0cf8.Data_4[r0].offset + r1;

				if (Data_235b0cf8.Data_8 < r1)
				{
					Data_235b0cf8.Data_8 = r1;
				}
			}
		}
		//loc_23419d60
	}
	//loc_23419d60
	Data_235b0cf8.Data_235b0d08 = *r4;

	Data_235b0cf8.dirty = 0;

	Data_23492114 = OSSemCreate(1);

	return 0;
}


