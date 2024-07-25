#include "data.h"
#include "ucos_ii.h"
#include "sub_2340a6a0.h"


extern OS_EVENT* channel_sema;
extern Struct_234fd8f0 Data_234fd8f0;


#if 0 //Moved to Struct_234fd8f0
struct
{
	uint16_t arChannel[8]; //235449a8
	int fill_0x10[496]; //0x10
	//0x7d0????
} favourites; //235449a8

uint32_t dwCrcFavourites; //2354611c
#endif

struct
{
	uint16_t wData_0; //0
	uint16_t wData_2; //2
	//4
} Data_2377d870[8]; //2377d870



/* 234515f0 - todo */
void sub_234515f0(int r4, int r7)
{
	uint8_t sp;
	uint32_t i;
	uint32_t j;

#if 0
	console_send_string("sub_234515f0 (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &sp);

	if (r4 == 0)
	{
		for (i = 0; i < 8; i++)
		{
			//loc_23451634
			if (/*Data_235449a8*/Data_234fd8f0.favourites.arChannel[i] != 0xffff)
			{
				//0x23451644
				Data_2377d870[i].wData_0 =
						Data_234fd8f0.Data_234fd8f0[ Data_234fd8f0.favourites.arChannel[i] ].Data_0.service_id;

				Data_2377d870[i].wData_2 =
						Data_234fd8f0.Data_23538270[ Data_234fd8f0.Data_234fd8f0[ /*Data_235449a8*/Data_234fd8f0.favourites.arChannel[i] ].Data_0.wData_4 ].transport_stream_id;
			}
			//loc_23451680
		}
		//->loc_23451738
	}
	else
	{
		//r4 = 0
		for (i = 0; i < 8; i++)
		{
			//loc_23451690
			if (/*Data_235449a8*/Data_234fd8f0.favourites.arChannel[i] != 0xffff)
			{
				//0x234516a0
				for (j = 0; j < 6000; j++)
				{
					int ip;
					int sl;
					//loc_234516ac
					int r3 = Data_234fd8f0.Data_234fd8f0[j].Data_0.service_id;
					if (r3 == 0xffff)
					{
						/*Data_235449a8*/Data_234fd8f0.favourites.arChannel[i] = 0xffff;
						//->loc_23451710
						break;
					}
					//0x234516c4
					ip = Data_234fd8f0.Data_234fd8f0[j].Data_0.wData_4;
					sl = Data_2377d870[i].wData_0;
					ip = Data_234fd8f0.Data_23538270[ ip ].transport_stream_id;

					if (sl == r3)
					{
						//0x234516e8
						if ((r7 != 0) || (Data_2377d870[i].wData_2 == ip))
						{
							//loc_234516fc
							/*Data_235449a8*/Data_234fd8f0.favourites.arChannel[i] = j;
							//->loc_23451710
							break;
						}
						//loc_23451704
					}
					//loc_23451704
				} //for (j = 0; j < 6000; j++)
				//loc_23451710
				if ((i & 3) == 0)
				{
					rtos_task_wait(1);
				}
				//loc_2345171c
			}
			//loc_2345171c
		}
		//0x23451728
		Data_234fd8f0.dwCrcFavourites = crc32((void*) &Data_234fd8f0.favourites, 
			sizeof(Data_234fd8f0.favourites));
	}
	//loc_23451738
	OSSemPost(channel_sema);
}

