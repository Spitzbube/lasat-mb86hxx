
#include "data.h"
#include "frontdisplay.h"


//23492118
OS_EVENT* Data_23492118; //23492118

struct
{
#if 0
	int Data_0[138]; //0
	int Data_0x228[138]; //0x228
#else
	FrontDisplay_Job Data_0[4]; //0
#endif
	void* (*Prepare)(FrontDisplay_Job*); //0x450
	int Data_0x454; //0x454

} Data_235b0d40; //235b0d40


/* 23419fd4 - todo */
int frontdisplay_draw_scroll_text(uint8_t a)
{
	uint8_t buf[13];
	FrontDisplay_Job* pJob;
	uint8_t* pBuf = buf;
	uint8_t* r2;
	uint8_t i;

#if 0
	console_send_string("frontdisplay_draw_scroll_text (todo.c): TODO\r\n");
#endif

	pJob = &Data_235b0d40.Data_0[a];

	if (pJob->bData_0x10c != 0)
	{
		pJob->bScrollTimer++;
		if (pJob->bScrollTimer < 5)
		{
			//loc_2341a0d4
			return pJob->bData_0x10c;
		}
		else
		{
			pJob->bScrollTimer = 0;

			if (pJob->bData_0x10b >= pJob->bNumTextChars)
			{
				pJob->bData_0x10b = 0;
				pJob->bData_0x10c--;
			}

			if ((pJob->bData_0x110 != 0) && (a != 0))
			{
				buf[0] = ':';
				pBuf++;
			}

			r2 = &pJob->bData_8[pJob->bData_0x10b];
			//->loc_2341a088
			for (i = 0; i < (pJob->bNumDisplayChars - pJob->bDisplayOffset); i++)
			{
				//loc_2341a064
				uint8_t ch = *r2;
				if (ch == 0)
				{
					*pBuf = ' ';
					r2 = pJob->bData_8;
				}
				else
				{
					*pBuf = ch;
					r2++;
				}
				pBuf++;
			}
			//->loc_2341a0ac
			for (; i < 12; i++)
			{
				//loc_2341a0a0
				*pBuf++ = ' ';
			}
			//0x2341a0b4
			buf[12] = 0;

			vfd_display_text(buf, pJob->bDisplayOffset, pJob->bNumDisplayChars);

			pJob->bData_0x10b++;
		}
		//loc_2341a0d4
	}
	//loc_2341a0d4
	return pJob->bData_0x10c;
}


/* 2341a0e0 - todo */
int frontdisplay_draw_text(uint8_t a)
{
	uint8_t buf[13];
	uint8_t* pBuf = buf;
	uint8_t i;
	uint8_t* pString;
	FrontDisplay_Job* pJob;

#if 0
	console_send_string("frontdisplay_draw_text (todo.c): TODO\r\n");
#endif

	pJob = &Data_235b0d40.Data_0[a];

	if ((pJob->bData_0x110 != 0) && (a != 0))
	{
		buf[0] = ':';
		pBuf++;
	}

	pString = pJob->bData_8;
	pString += pJob->bData_0x10b;
	//->loc_2341a140
	for (i = 0; i < (pJob->bNumDisplayChars - pJob->bDisplayOffset); i++)
	{
		//loc_2341a124
		uint8_t ch = *pString;
		if (ch == 0)
		{
			//->loc_2341a154
			break;
		}
		//0x2341a130
		pString++;
		*pBuf++ = ch;
	}
	//loc_2341a154
	for (; i < 12; i++)
	{
		//loc_2341a158
		*pBuf++ = ' ';
	}
	//0x2341a16c
	buf[12] = 0;

	vfd_display_text(buf, pJob->bDisplayOffset, pJob->bNumDisplayChars);

	return 0;
}


/* 2341a190 - complete */
void frontdisplay_task()
{
	uint8_t i;
	FrontDisplay_Job* pJob = &Data_235b0d40.Data_0[0];

#if 0
	console_send_string("frontdisplay_task (todo.c): TODO\r\n");
#endif

	if (0 != sub_2341a404())
	{
		return;
	}

	if (Data_235b0d40.Data_0x454 != 0)
	{
		Data_235b0d40.Data_0x454--;
		//->loc_2341a268 -> loc_2341a284
		OSSemPost(Data_23492118);
		return;
	}
	//0x2341a1bc
	if (Data_235b0d40.Prepare != 0)
	{
		memset(&Data_235b0d40.Data_0[2], 0, 2 * sizeof(FrontDisplay_Job));

		Data_235b0d40.Prepare =
				(Data_235b0d40.Prepare)(&Data_235b0d40.Data_0[2]);

		for (i = 0; i < 2; i++)
		{
			//loc_2341a1e8
			if ((0 != strcmp(Data_235b0d40.Data_0[i + 2].bData_8,
					Data_235b0d40.Data_0[i + 0].bData_8)) ||
					(Data_235b0d40.Data_0[i + 2].bData_0x10f != 0))
			{
				Data_235b0d40.Data_0[i + 0] = Data_235b0d40.Data_0[i + 2];
			}
		} //for (i = 0; i < 2; i++)
	}
	//loc_2341a228
	for (i = 0; i < 2; i++)
	{
		//loc_2341a230
		if (pJob->Data_0 != 0)
		{
			if (0 == (pJob->Data_0)(i))
			{
				pJob->Data_0 = 0;
			}

			if (pJob->holdTime != 0)
			{
				if (pJob->Data_0 == 0)
				{
					//0x2341a264
					Data_235b0d40.Data_0x454 = pJob->holdTime;
				}
				//->loc_2341a284
				break;
			}
			//loc_2341a270
		}
		//loc_2341a270
		pJob++;
	} //for (i = 0; i < 2; i++)
	//loc_2341a284
	OSSemPost(Data_23492118);
}


/* 2341a290 - complete */
int sub_2341a290(uint8_t* sb, uint32_t r5)
{
#if 0
	console_send_string("sub_2341a290 (todo.c): TODO\r\n");
#endif

	if (0 == sub_2341a404())
	{
//		int r6 = 0;
//		uint8_t r4 = 0;
		Data_235b0d40.Prepare = 0; //r6

		for (uint8_t i = 0; i < 2; i++)
		{
			//loc_2341a2bc
			Data_235b0d40.Data_0[i].Data_0 = 0; //r6
			Data_235b0d40.Data_0[i].bData_0x10c = 0; //r6
			Data_235b0d40.Data_0[i].bData_8[0] = 0; //r6

			if (Data_235b0d40.Data_0[i].Data_4 != 0)
			{
				(Data_235b0d40.Data_0[i].Data_4)();
			}
		}
		//0x2341a2ec
		if (sb != 0)
		{
			if ((strlen(sb) + r5) < 13)
			{
				if (r5 == 0)
				{
					sub_23437b24(sb);
					//->loc_2341a380
				}
				else
				{
					//loc_2341a31c
					vfd_display_text(sb, r5, 12);
					//->loc_2341a380
				}
			}
			else
			{
				//loc_2341a330
				vfd_display_text(sb, r5, 12);

				strncpy(Data_235b0d40.Data_0[0].bData_8, sb, 0xff);
				Data_235b0d40.Data_0[0].bNumTextChars = strlen(Data_235b0d40.Data_0[0].bData_8);
				Data_235b0d40.Data_0[0].bDisplayOffset = r5;
				Data_235b0d40.Data_0[0].bNumDisplayChars = 12;
				Data_235b0d40.Data_0[0].bData_0x10b = 0; //r6
				Data_235b0d40.Data_0[0].bData_0x10c = 1;
				Data_235b0d40.Data_0[0].bData_0x110 = 0; //r6
				Data_235b0d40.Data_0[0].Data_0 = frontdisplay_draw_scroll_text;
			}
		}
		//loc_2341a380
		OSSemPost(Data_23492118);
	}
	//loc_2341a38c
	return 0;
}


/* 2341a394 - complete */
int frontdisplay_start_text(void* (*f)(FrontDisplay_Job*))
{
#if 0
	console_send_string("frontdisplay_start_text (todo.c): TODO\r\n");
#endif

	if (0 == sub_2341a404())
	{
		Data_235b0d40.Prepare = f;

		OSSemPost(Data_23492118);
	}
}


/* 2341a3c0 - complete */
int frontdisplay_init()
{
#if 0
	console_send_string("frontdisplay_init (todo.c): TODO\r\n");
#endif

	Data_23492118 = OSSemCreate(1);

	Data_235b0d40.Prepare = 0;
	Data_235b0d40.Data_0x454 = 0;

	memset(&Data_235b0d40.Data_0[0], 0, 2 * sizeof(FrontDisplay_Job));
	memset(&Data_235b0d40.Data_0[2], 0, 2 * sizeof(FrontDisplay_Job));

	return 0;
}


/* 2341a404 - complete */
int sub_2341a404()
{
	uint8_t sp;

#if 0
	console_send_string("sub_2341a404 (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_23492118, 0, &sp);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2341a404: sp=%d\r\n", sp);
		console_send_string(debug_string);
	}
#endif

	return sp;
}


