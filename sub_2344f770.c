#include "data.h"
#include "ucos_ii.h"
#include "sub_2340a6a0.h"


extern OS_EVENT* channel_sema;
extern Channel_Database channel_database; //234fd8f0 + 489f4 = 235462E4
extern Struct_235462e4 Data_235462e4; //235462e4


/* 2344ee88 /  / 2340fec8 - complete */
void sub_2344ee88(uint16_t arwData[], uint8_t numData)
{
#if 0
	console_send_string("sub_2344ee88 (todo.c): TODO\r\n");
#endif

	uint8_t count = numData;
	while (count)
	{
		//loc_2344ee94
		uint8_t i = 0;
		do
		{
			//loc_2344ee98
			uint16_t* pw1 = &arwData[i];
			uint16_t* pw2 = &arwData[i+1];
			uint16_t w1 = pw1[0];
			uint16_t w2 = pw2[0];

			if (w1 < w2)
			{
				pw1[0] = w2;
				pw2[0] = w1;
			}
			i++;
		}
		while ((i+1) < numData);
		count--;
	}
}


/* 2344eedc - todo */
void sub_2344eedc(int a, uint16_t b, int c)
{
#if 0
	console_send_string("sub_2344eedc (todo.c): TODO\r\n");
#endif

	uint16_t* ip = &channel_database.Data_235441d8[a].arChannel[0];
	int r6 = 0;
	uint16_t r3 = 0;
	do
	{
		//loc_2344eefc
		if (ip[r3] == 0xffff/*r5*/)
		{
			break;
		}

		r3++;
	}
	while (r3 < 1000);

	if (r3 == 0)
	{
		return;
	}

	uint16_t r0;
	//->loc_2344ef58
	for (r0 = 0; r0 < r3; r0++)
	{
		//loc_2344ef28
		uint16_t* lr = &ip[r0];
		uint16_t r4 = lr[0];

		if (r4 == b)
		{
			r6 = 1;
			lr[0] = 0xffff; //r5
			//->loc_2344ef50
		}
		else
		{
			//0x2344ef40
			if ((c != 0) && (r4 > b))
			{
				lr[0] = r4 - 1;
			}
		}
		//loc_2344ef50
	} //for (r0 = 0; r0 < r3; r0++)
	//0x2344ef60
	if (r6 == 0)
	{
		return;
	}

	uint16_t* r4 = &ip[r3];
	//->loc_2344efa8
	while (r3--)
	{
		//loc_2344ef70
		uint16_t* r0 = &ip[r3];

		if (*r0 == 0xffff/*r5*/)
		{
			//loc_2344ef80
			while (r4 >= r0)
			{
				//0x2344ef88
#if 0
				uint16_t* lr = r0;
				uint16_t* r1 = r0+1;
				uint16_t r6 = r1[0];
				uint16_t r2 = lr[0];
				lr[0] = r6;
				r0++;
				r1[0] = r2;
#else
				uint16_t r6 = r0[1];
				uint16_t r2 = r0[0];
				r0[0] = r6;
				r0[1] = r2;
				r0++;
#endif
			}
			//loc_2344efa8
		}
		//loc_2344efa8
	} //while (r3--)
}


/* 2344f19c /  / 234101dc - todo */
void sub_2344f19c(void)
{
#if 0
	console_send_string("sub_2344f19c (todo.c): TODO\r\n");
#endif

	uint32_t* pCrc;

	if (channel_database.Data_235441d8[0].arChannel[0] != 0xffff)
	{
		pCrc = &channel_database.Data_23546118[0];
		*pCrc = crc32(&channel_database.Data_235441d8[0].arChannel[0], 2000);
	}
	//loc_2344f1c8
	if (channel_database.Data_235441d8[1].arChannel[0]/*235449A8*/ != 0xffff)
	{
		pCrc = &channel_database.Data_23546118[1];
		*pCrc = crc32(&channel_database.Data_235441d8[1].arChannel[0], 2000);
	}
	//loc_2344f1ec
	if (channel_database.Data_235441d8[2].arChannel[0]/*23545178*/ != 0xffff)
	{
		pCrc = &channel_database.Data_23546118[2];
		*pCrc = crc32(&channel_database.Data_235441d8[2].arChannel[0], 2000);
	}
	//loc_2344f210
	if (channel_database.Data_235441d8[3].arChannel[0]/*23545948*/ != 0xffff)
	{
		pCrc = &channel_database.Data_23546118[3];
		*pCrc = crc32(&channel_database.Data_235441d8[3].arChannel[0], 2000);
	}
}


/* 2344f238 /  / 23410278 - todo */
int sub_2344f238(uint16_t r5[], uint16_t r7)
{
#if 0
	console_send_string("sub_2344f238 (todo.c): TODO\r\n");
#endif

	//int sb = 0xffff
	while (r7--)
	{
		//loc_2344f250
		Channel* r4 = &channel_database.arChannels[(*r5)];
		uint16_t r6;
		for (r6 = 0; r6 < 6000; r4++, r6++)
		{
			//loc_2344f268
			if (r4[1].service_id == 0xffff)
			{
				//->loc_2344f2bc
				break;
			}
			//0x2344f274
			Channel* r8 = &r4[1];
			Channel sp = *r4;
			*r4 = *r8;
			*r8 = sp;
		}
		//loc_2344f2bc
		if (r4->wTransponderIndex == 0xffff)
		{
			//0x2344f2c8
			sub_23419940((r4->wVideoPID << 0) | (r4->wPcrPID << 16), 0);
		}
		//loc_2344f2dc
		memset(r4, 0xff, sizeof(Channel));
		sub_2344eedc(0, *r5, 1);
		sub_2344eedc(1, *r5, 1);
		sub_2344eedc(2, *r5, 1);
		sub_2344eedc(3, *r5, 1);

		r5++;
		//loc_2344f330
	} //while (r7--)
	//0x2344f340
	sub_2344f19c();

	return 0;
}


/* 2344f350 /  / 23410390 - complete */
uint32_t sub_2344f350(void)
{
	uint8_t err;
	uint32_t crc;

#if 0
	console_send_string("sub_2344f770 (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &err);

	crc = crc32(&channel_database.arChannels[0], 0x3a980);

	OSSemPost(channel_sema);

	return crc;
}


/* 2344f720 /  / 23410760 - complete */
int sub_23410760(uint16_t* r5, uint8_t r6)
{
	uint8_t err;

#if 0
	console_send_string("sub_23410760 (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &err);

	/*sub_2340fec8*/sub_2344ee88(r5, r6);
	/*sub_23410278*/sub_2344f238(r5, r6);

	OSSemPost(channel_sema);

	channel_load_lists();

	return Data_235462e4.numChannels;
}


/* 2344f770 /  / 234107b0 - complete */
Channel_Database* sub_2344f770(void)
{
	uint8_t err;
	struct Channel_Database* r4;

#if 0
	console_send_string("sub_2344f770 (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &err);

	r4 = &channel_database;

	OSSemPost(channel_sema);

	return r4;
}

