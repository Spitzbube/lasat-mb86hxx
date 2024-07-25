
#include "data.h"
#include "menu.h"
#include "frontdisplay.h"
#include "sub_2340a6a0.h"
#include "eit.h"
#include "radiotext.h"

#pragma thumb

#ifndef ROOT_MENU_STANDBY
#define ROOT_MENU_STANDBY (12*60*60)/*3 hours?*/ //(2*60)
#endif

#ifndef ROOT_MENU_STANDBY_WARN
#define ROOT_MENU_STANDBY_WARN (8*60)/*2 minutes?*/ //(1*60)
#endif

int menu_root_on_event(void*);
int menu_root_on_enter(int);
int menu_root_on_exit(UI_Thread_Params*);
void menu_root_start_event_display();

//0x2349596c
uint8_t bData_2349596c = 0; //2349596c +0
uint8_t bData_2349596d = 0; //2349596e +1
uint8_t bData_2349596e = 0; //2349596e +2
uint8_t bData_2349596f = 0; //2349596F +3

//0x23495984
struct
{
	uint8_t bData_0; //0
	int timerVal; //4    23495974
	void* (*timerFunc)(); //8   23495978
	void (*Data_2349597c)(); //12  2349597c
	int fill_23495980; //16  23495980
	uint8_t strText[0x100]; //20  23495984
	uint8_t Data_23495a84[256]; //23495a84
	uint8_t bData_23495b84; //0x214 = 532, 23495b84
	int Data_23495b88; //0x218 = 536, 23495b88
	uint16_t wFavouriteIndex; //0x21C = 540, 23495b8c
	int Data_23495b90; //544, 23495b90
	uint16_t fill_548; //548, 23495b94
	uint8_t bData_23495b96; //0x226 = 550   23495b96
	uint8_t fill_23495b97; //23495b97
	uint8_t bEventDisplayMode; //0x228 = 552, 23495b98
	int (*standbyTimerFunc)(); //0x22C = 556, 23495b9c  0x23495b90 - 0x20 +0x2c
	uint8_t bKeyActivity; //0x230 = 560, 23495ba0 23495b90 + 0x10
	uint32_t standbyCount; //564, 23495ba4, 23495b90 +0x14
	uint8_t bData_23495ba8; //23495BA8 23495b90 +0x18
	//572?
} Data_23495970 = //23495970   0x23495984 - 0x14   + 0x23C -> 23495BAC
{
		1, //bData_0
};

//0x23495b90
//void (*standbyTimerFunc)(); //0x22C = 556, 23495b9c  0x23495b90 - 0x20 +0x2c
//uint8_t bKeyActivity; //23495ba0 23495b90 + 0x10
extern Menu_Item Data_23495be4; //23495be4
Menu Data_23495bac = //23495bac 0x23495b90 + 0x1c  -> 23495BE4
{
		0xffff, //wData_0
		&Data_23495be4, //Data_4
		&Data_23495be4, //Data_8
		0, //Data_0xc
		0, //Data_0x10
		0, //Data_0x14
		0, //maxItem
		0, //currentItem
		0, //Data_0x1c
		0, //onNavigate //0x20
		menu_root_on_enter, //onEnter //0x24
		menu_root_on_exit, //onExit //0x28
		0xff, //Data_0x2c
		25, //timeout //0x30
		0 //Data_0x34
#if 0
		0x23495bac                        dw         0xffff                             ; DATA XREF=sub_2346f708+66, sub_2346f708+74
		0x23495bae 0000                   movs       r0, r0
		0x23495bb0                        dd         0x23495be4
		0x23495bb4                        dd         0x23495be4
		0x23495bb8                        dd         0x00000000
		0x23495bbc                        dd         0x00000000
		0x23495bc0                        dd         0x00000000
		0x23495bc4                        db         0x00
		0x23495bc5                        db         0x00
		0x23495bc6 0000                   movs       r0, r0
		0x23495bc8                        dd         0x00000000
		0x23495bcc                        dd         0x00000000
		0x23495bd0                        dd         0x2346ecfd
		0x23495bd4                        dd         0x2346ed1d
		0x23495bd8                        dd         0x000000ff
		0x23495bdc                        dd         0x00000019
		0x23495be0                        dd         0x00000000
#endif
};
Menu_Item Data_23495be4 = //23495be4
{
		0xffff,
		0xffff,
		{0, 0, 0, 0, 0},
		0, //Data_0x18
		menu_root_on_event, //onEvent //0x1c
		mainfunction_thread, //inputThreadFunc //0x20
		0, //Data_0x24
		0 //Data_0x28
#if 0
		0x23495be4                        db  0xff ; '.'                                ; DATA XREF=0x23495bb0, 0x23495bb4
		0x23495be5                        db  0xff ; '.'
		0x23495be6                        db  0xff ; '.'
		0x23495be7                        db  0xff ; '.'
		0x23495be8 0000                   movs       r0, r0
		0x23495bea 0000                   movs       r0, r0
		0x23495bec 0000                   movs       r0, r0
		0x23495bee 0000                   movs       r0, r0
		0x23495bf0 0000                   movs       r0, r0
		0x23495bf2 0000                   movs       r0, r0
		0x23495bf4 0000                   movs       r0, r0
		0x23495bf6 0000                   movs       r0, r0
		0x23495bf8 0000                   movs       r0, r0
		0x23495bfa 0000                   movs       r0, r0
		0x23495bfc 0000                   movs       r0, r0
		0x23495bfe 0000                   movs       r0, r0
		0x23495c00                        dd         0x2346f37d
		0x23495c04                        dd         0x2343d611
		0x23495c08                        dd         0x00000000
		0x23495c0c                        dd         0x00000000
#endif
};


/* 2346ec9c - complete */
static void* string_display(FrontDisplay_Job* r4)
{
#if 0
	console_send_string("string_display (todo.c): TODO\r\n");
#endif

	strncpy(r4->bData_8, &Data_23495970.strText[0], 0xff);

	r4->bNumTextChars = strlen(r4->bData_8);
	r4->bDisplayOffset = 0;
	r4->bNumDisplayChars = 12;
	r4->bData_0x10b = 0;
	r4->bData_0x10c = 0;
	r4->bData_0x110 = 0;
	r4->holdTime = 0;
	r4->Data_0 = frontdisplay_draw_text;
	r4->Data_4 = 0;
	r4->bData_0x10f = 0;

	return string_display;
}


/* 2346ecd4 - complete */
void* sub_2346ecd4(int* a)
{
#if 0
	console_send_string("sub_2346ecd4 (todo.c): TODO\r\n");
#endif

	(*a)--;

	if (*a != 0)
	{
		return sub_2346ecd4;
	}
	//loc_2346ece2
	if (0 == sub_2346faf6(&Data_23495970.strText[0]))
	{
		frontdisplay_start_text(string_display);
		//->loc_2346ecf8
	}
	else
	{
		//loc_2346ecf4
		sub_23411550(); //->av.c
	}
	//loc_2346ecf8
	return 0;
}


/* 2346ecfc - complete */
int menu_root_on_enter(int a)
{
#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "menu_root_on_enter: a=%d\r\n", a);
        console_send_string(debug_string);
    }
#endif

	if (a != 0)
	{
		Data_23495970.timerFunc = sub_2346ecd4;
		Data_23495970.timerVal = 1;
		Data_23495970.Data_2349597c = 0;
	}
	//loc_2346ed10
	memset(&Data_23495970.Data_23495b90, 0, 8);

	return 0;
}


/* 2346ed1c - complete */
int menu_root_on_exit(UI_Thread_Params* a)
{
#if 0
	console_send_string("menu_root_on_exit\r\n");
#endif

	return 0;
}


/* 2346ed20 - todo */
int sub_2346ed20()
{
#if 1
	console_send_string("sub_2346ed20 (todo.c): TODO\r\n");
#endif

	return 0;
}


/* 2346edaa - complete */
static void* event_string_display(FrontDisplay_Job* r5)
{
	strncpy(r5->bData_8, &Data_23495970.strText[0], 0xff);

	r5->bNumTextChars = strlen(r5->bData_8);
	r5->bDisplayOffset = 0;
	r5->bNumDisplayChars = 12;
	r5->bData_0x10b = 0;
	r5->holdTime = 0;
	r5->Data_4 = 0;
	r5->bData_0x10f = 0;
	r5->bData_0x110 = 0;
	r5->bData_0x10c = 0;
	r5->Data_0 = frontdisplay_draw_text;

	if (r5->bNumTextChars > 12)
	{
		r5->bData_0x10c = 1;
		r5->Data_0 = frontdisplay_draw_scroll_text;
	}
	//loc_2346edec
	return event_string_display;
}


/* 2346edf0 - complete */
static void* now_next_display(FrontDisplay_Job* r5)
{
#if 0
	console_send_string("now_next_display (todo.c): TODO\r\n");
#endif

	text_table_get_string(443 + Data_23495970.bEventDisplayMode, r5->bData_8, 0xfe);

	r5->bNumTextChars = strlen(r5->bData_8);
	r5->bDisplayOffset = 0;
	r5->bNumDisplayChars = 12;
	r5->bData_0x10b = 0;
	r5->bData_0x10c = 0;
	r5->bData_0x110 = 0;
	r5->holdTime = 15;
	r5->Data_0 = frontdisplay_draw_text;
	r5->Data_4 = 0;
	r5->bData_0x10f = 0;

	return event_string_display;
}


/* 2346ee32 - todo */
static void* rds_text_display(FrontDisplay_Job* p)
{
#if 0
	console_send_string("rds_text_display (todo.c): TODO\r\n");
#endif

	strncpy(p->bData_8, &Data_23495970.strText[0], 255);

	p->bNumTextChars = strlen(p->bData_8);
	p->bDisplayOffset = 0;
	p->bNumDisplayChars = 12;
	p->bData_0x10b = 0;
	p->holdTime = 0;
	p->Data_4 = 0;
	p->bData_0x10f = 0;
	p->bData_0x110 = 0;
	p->bData_0x10c = 1;
	p->Data_0 = frontdisplay_draw_scroll_text;

	return rds_text_display;
}


/* 2346ee6c - todo */
static void* store_favourite_timer_func(uint32_t* pCount)
{
	Struct_2340bf0c sp4; //sp4

#if 0
	console_send_string("store_favourite_timer_func (todo.c): TODO\r\n");
#endif

	(*pCount)--;
	if (*pCount != 0)
	{
		return store_favourite_timer_func;
	}
	else
	{
		//loc_2346ee7e
		Data_23495970.Data_2349597c = 0;

		sub_2340bf0c(&sp4);

		Struct_234fd8f0* r5 = sub_2344f770();

		snprintf(&Data_23495970.strText[0], 256, "Ch %d->S%d",
			sp4.wCurrentChannel + 1,
			Data_23495970.wFavouriteIndex);

		frontdisplay_start_text(string_display);

		uint16_t* pFav = &r5->favourites.arChannel[0];
		pFav[Data_23495970.wFavouriteIndex - 1] = sp4.wCurrentChannel;

		uint32_t* pCrc = &r5->dwCrcFavourites;
		*pCrc = crc32(&r5->favourites.arChannel[0], 
			sizeof(r5->favourites));

		sub_2340c204(1);
		sub_2340c8a8();
		sub_2340c204(0);

		Data_23495970.timerVal = 5;

		return sub_2346ecd4;
	}
}


/* 2346eeee - complete */
static void* sub_2346eeee(int* a)
{
#if 0
	console_send_string("sub_2346eeee (todo.c): TODO\r\n");
#endif

	(*a)--;

	if (*a != 0)
	{
		return sub_2346eeee;
	}
	//loc_2346eefa
	return 0;
}


/* 2346eefe - complete */
void sub_2346eefe()
{
#if 0
	console_send_string("sub_2346eefe (todo.c): TODO\r\n");
#endif

	Data_23495970.timerVal = 0;
	Data_23495970.timerFunc = 0;
	Data_23495970.Data_2349597c = 0;

}


/* 2346ef6c - todo */
static void* standby_warn_timer_func(uint32_t* pCount)
{
#if 0
	console_send_string("standby_warn_timer_func (todo.c): TODO\r\n");
#endif

//	int r6 = 1;

	(*pCount)--;

	struct
	{
		int fill_0[4]; //0
		uint8_t bData_0x10; //0x10

	}* r5 = (void*) &Data_23495970.Data_23495b90; //0x220 = 544

	if (*pCount != 0)
	{
		if (r5->bData_0x10/*bKeyActivity*/ != 0)
		{
			//0x2346ef8c: Abort auto-standby warning
			sub_2346f77e();

			Data_23495970.timerVal = 1; //r6
			return Data_23495970.timerFunc;
		}
		//loc_2346ef9a
		text_table_get_string(450, //"Aus in %ds"
			&Data_23495970.Data_23495a84[0], 255);

		snprintf(&Data_23495970.strText[0], 255, 
			&Data_23495970.Data_23495a84[0], 
			(*pCount) / 4);

		frontdisplay_start_text(string_display);

		return standby_warn_timer_func;
	}
	//loc_2346efc0
	UI_Thread_Params* r1 = sub_2343d572();

	powermode_set_state(2/*Off*/, r1, standby_thread);

	r5->bData_0x10/*bKeyActivity*/ = 1; //r6

	return 0;
}


/* 2346efd4 - todo */
static void* event_display_timer_func(uint32_t* pCount)
{
	int r4;

	Struct_2340bf0c sp_0x48;
	Struct_235fdfac sp_0x30;
	struct Struct_234fd8f0_Inner0 sp8;

#if 0
	console_send_string("event_display_timer_func (todo.c): TODO\r\n");
#endif

	(*pCount)--;

	if (*pCount != 0)
	{
		//0x2346efe2
#if 0
		//r5, =0x23495984
		if (0 != sub_23418bf0()) //->ts_play
		{
			//0x2346efec
			sub_2345d5c4(&Data_23495970.strText[0], 0xff);
			//->loc_2346f082
		}
		else
#endif
		{
			//loc_2346eff6
			sub_2340bf0c(&sp_0x48);

			uint8_t sp4[] = " ";

			sub_2340bf94(sp_0x48.wCurrentChannel, &sp8, &sp_0x30);

			Struct_2377b8d0* pEITSectionData =
					eit_get_section_data(sp8.Data_0.service_id, sp_0x30.transport_stream_id);
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "event_display_timer_func: sp8.Data_0.service_id=%d, sp_0x30.transport_stream_id=%d, pEITSectionData=%p\r\n",
						sp8.Data_0.service_id, sp_0x30.transport_stream_id, pEITSectionData);
				console_send_string(debug_string);
			}
#endif
			if (pEITSectionData != 0)
			{
				//0x2346f01e
				struct Struct_2377b8d0_Inner8* r0 =
						sub_2344ec90(pEITSectionData, 4 - 3 * Data_23495970.bEventDisplayMode);
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "event_display_timer_func: Data_23495970.bEventDisplayMode=%d, r0=%p\r\n",
							Data_23495970.bEventDisplayMode, r0);
					console_send_string(debug_string);
				}
#endif
				if (r0 != 0)
				{
					//0x2346f034
					struct Struct_2377b8d0_Inner8_Inner8* r0_ = r0->Data_8;
					if (r0_ != 0)
					{
						//0x2346f03a
						struct Struct_2377b8d0_Inner8_Inner8_Inner0* r0 = r0_->Data_0;

						uint8_t* eventName = r0->strName;

						if (eventName != 0)
						{
							//0x2346f042
							if ((eventName[0] != 0) && (eventName[0] < 0x21))
							{
								//0x2346f04c
								eventName++;
							}
							//loc_2346f052
						}
						else
						{
							//loc_2346f050
							eventName = sp4;
						}
						//loc_2346f052
						uint8_t* eventText = r0->strText;
						//int r1 = 0x100;

						if (eventText != 0)
						{
							//0x2346f05c
							if ((eventText[0] != 0) && (eventText[0] < 0x21))
							{
								//0x2346f066
								eventText++;
							}
							//loc_2346f068
							snprintf(&Data_23495970.strText[0], /*r1*/0x100, "%s - %s ", eventName, eventText);
							//->loc_2346f082
						}
						else
						{
							//loc_2346f074
							snprintf(&Data_23495970.strText[0], /*r1*/0x100, "%s ", eventName);
							//->loc_2346f082
						}
#if 0
						{
							extern char debug_string[];
							sprintf(debug_string, "event_display_timer_func: eventName='%s', eventText='%s'\r\n",
									eventName, eventText? eventText: "");
							console_send_string(debug_string);
						}
#endif
					} //if (r0_ != 0)
					else
					{
						//loc_2346f078
						text_table_get_string(40, &Data_23495970.strText[0], 0xff);
					}
				} //if (r0 != 0)
				else
				{
					//loc_2346f078
					text_table_get_string(40, &Data_23495970.strText[0], 0xff);
				}
			} //if (pEITSectionData != 0)
			else
			{
				//loc_2346f078
				text_table_get_string(40, &Data_23495970.strText[0], 0xff);
			}
		}
		//loc_2346f082
		uint32_t r0 = strlen(&Data_23495970.strText[0]);

		r4 = *pCount;

		if (r0 < 13)
		{
			//0x2346f08e
			r4 = 20;
			//->loc_2346f100
		}
		else
		{
			//loc_2346f0f8
			if (r0 > 40)
			{
				//0x2346f0fc
				r4 = r0 + 10;
			}
			//loc_2346f100
		}
		//loc_2346f100
		frontdisplay_start_text(now_next_display);
	} //if (*pCount != 0)
	else
	{
		//->loc_2346f092 -> loc_2346f108
		r4 = 1;
		//loc_2346f10a
	}
	//loc_2346f10a
	sub_2346f77e();

	Data_23495970.timerVal = r4;

	return Data_23495970.timerFunc;
}


/* 2346f118 - todo */
static void* rds_text_timer_func(uint32_t* pCount/*r4*/)
{
	int r4;

#if 0
	console_send_string("rds_text_timer_func (todo.c): TODO\r\n");
#endif

	if (--(*pCount) != 0)
	{
		//0x2346f130
		radiotext_get_string(RDS_RADIOTEXT, &Data_23495970.strText[0], 255);

		if (Data_23495970.strText[0] == 0)
		{
			//0x2346f140
			text_table_get_string(0x1BD, &Data_23495970.strText[0], 255);
		}
		//loc_2346f14c
		uint32_t r7 = strlen(&Data_23495970.strText[0]);

		if (0 == strcmp(&Data_23495970.strText[0], &Data_23495970.Data_23495a84[0]))
		{
			//0x2346f162
			uint8_t sp[] = {0x00, 0x20, 0x00, 0x00};
			if (r7 < 255)
			{
				//0x2346f16c
				Data_23495970.strText[r7] = sp[bData_2349596c];
				Data_23495970.strText[r7 + 1] = 0;
			}
			//loc_2346f17a
			r4 = *pCount;
			//->loc_2346f18a
		}
		else
		{
			//loc_2346f17e
			strcpy(&Data_23495970.Data_23495a84[0], &Data_23495970.strText[0]);

			r4 = r7;
			r4 += 25;
		}
		//loc_2346f18a
		bData_2349596c = 0;

		frontdisplay_start_text(rds_text_display);
		//->loc_2346f1a2
	} //if (--(*pCount) != 0)
	else
	{
		//loc_2346f196
		r4 = strlen(&Data_23495970.strText[0]);
		r4 += 25;

		bData_2349596c = 1;
	}
	//loc_2346f1a2
	Data_23495970.timerVal = r4;
	
	return Data_23495970.timerFunc;
}


/* 2346f1a8 - todo */
static void* rds_ps_name_timer_func(uint32_t* pCount/*r4*/)
{
	uint32_t r4;

#if 0
	console_send_string("rds_ps_name_timer_func (todo.c): TODO\r\n");
#endif

	radiotext_get_string(RDS_PS_NAME, &Data_23495970.strText[0], 255);

	if (Data_23495970.strText[0] == 0)
	{
		//0x2346f1c2
		text_table_get_string(0x1BE, &Data_23495970.strText[0], 255);

		(*pCount)--;
		if ((*pCount) != 0)
		{
			//0x2346f1da
			uint32_t r7 = strlen(&Data_23495970.strText[0]);

			if (0 == strcmp(&Data_23495970.strText[0], &Data_23495970.Data_23495a84[0]))
			{
				//0x2346f1ee
				uint8_t sp[] = {0x00, 0x20, 0x00, 0x00};
				if (r7 < 255)
				{
					//0x2346f1f8
					Data_23495970.strText[r7] = sp[bData_2349596d];
					Data_23495970.strText[r7 + 1] = 0;
				}
				//loc_2346f206
				r4 = *pCount;
				//->loc_2346f216
			}
			else
			{
				//loc_2346f20a
				strcpy(&Data_23495970.Data_23495a84[0], &Data_23495970.strText[0]);

				r4 = r7;
				r4 += 25;
			}
			//loc_2346f216
			bData_2349596d = 0;

			frontdisplay_start_text(rds_text_display);
			//->loc_2346f22e
		}
		else
		{
			//loc_2346f222
			r4 = strlen(&Data_23495970.strText[0]);
			r4 += 25;

			bData_2349596d = 1;
		}
		//loc_2346f22e
		Data_23495970.timerVal = r4;
		//->loc_2346f238
	}
	else
	{
		//loc_2346f232
		frontdisplay_start_text(string_display);
	}
	//loc_2346f238
	return Data_23495970.timerFunc;
}


/* 2346f26c - todo */
static void check_favourite_channel(void)
{
	Struct_2340bf0c sp_0x2c; //sp_0x2c
	struct Struct_234fd8f0_Inner0 sp4; //sp4

#if 0
	console_send_string("check_favourite_channel (todo.c): TODO\r\n");
#endif

	Struct_234fd8f0* r0 = sub_2344f770();
	uint16_t* pFav = &r0->favourites.arChannel[0];
	int channel = pFav[Data_23495970.wFavouriteIndex - 1];
	Data_23495970.Data_23495b88 = 0;

	if (channel == 0xffff)
	{
		//0x2346f290
		text_table_get_string(0x1C0, &Data_23495970.strText[0], 255);

		frontdisplay_start_text(string_display);
		//->loc_2346f2b4
		sub_2346f77e();
	}
	else
	{
		//loc_2346f2a6
		sub_2340bf0c(&sp_0x2c);

		if (channel == sp_0x2c.wCurrentChannel)
		{
			//loc_2346f2b4: Already active channel
			sub_2346f77e();
		}
		else
		{
			//loc_2346f2ba
			channel_start_number(&sp4, channel, 0);
			sub_2346f76c();
		}
	}
}


/* 2346f2ca - todo */
static void* check_favourite_timer_func(uint32_t* pCount)
{
#if 0
	console_send_string("check_favourite_timer_func (todo.c): TODO\r\n");
#endif

	(*pCount)--;
	if ((*pCount) != 0)
	{
		return check_favourite_timer_func;
	}

	check_favourite_channel();

	return Data_23495970.timerFunc;
}


/* 2346f2e2 - todo */
void sub_2346f2e2()
{
#if 1
	console_send_string("sub_2346f2e2 (todo.c): TODO\r\n");
#endif

}


/* 2346f342 - todo */
static int standby_timer_func()
{
#if 0
	console_send_string("standby_timer_func (todo.c): TODO\r\n");
#endif

	int r0 = 0;

	int r4 = Data_23495970.bKeyActivity;
	if (r4 != 0)
	{
		Data_23495970.bKeyActivity = 0; //r3
		Data_23495970.standbyCount = ROOT_MENU_STANDBY;
		//loc_2346f35a
		return r0;
	}
	//loc_2346f35c
	if (Data_23495970.standbyCount != 0)
	{
		Data_23495970.standbyCount--;
		if (Data_23495970.standbyCount >= ROOT_MENU_STANDBY_WARN)
		{
			//->loc_2346f35a
			return r0;
		}
	}
	//loc_2346f36e
	Data_23495970.timerVal = ROOT_MENU_STANDBY_WARN;
	Data_23495970.Data_2349597c = 0;
	Data_23495970.timerFunc = standby_warn_timer_func;

	return 0xff;
}


/* 2346f37c - todo */
int menu_root_on_event(void* r0)
{
	Struct_2340bf0c sp4; //sp4

#if 0
	console_send_string("menu_root_on_event (todo.c): TODO\r\n");
#endif

	//r6 = 23495970
	//r4 = 23495B70

	//r3 = Data_23495970.timerVal;
	//r2 = Data_23495970.timerFunc;

	if (r0 == 0)
	{
		//0x2346f390: handle timeout
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "menu_root_on_event: Data_23495970.timerVal=%d, Data_23495970.timerFunc=%p\r\n",
					Data_23495970.timerVal, Data_23495970.timerFunc);
			console_send_string(debug_string);
		}
#endif
		if (Data_23495970.timerVal != 0)
		{
			if (Data_23495970.timerFunc != 0)
			{
				void* r0 = (Data_23495970.timerFunc)(&Data_23495970.timerVal);
				//->loc_2346f47a
				Data_23495970.timerFunc = r0;
			}
			//loc_2346f3b6 -> loc_2346f6f0
		}
		else
		{
			//loc_2346f39e
			if ((Data_23495970.standbyTimerFunc == 0) ||
					(0 == (Data_23495970.standbyTimerFunc)()))
			{
#if 0
				//loc_2346f3aa
				if (0 != sub_2346f7e0())
				{
					//->loc_2346f3a8 -> loc_2346f3b6
				}
				else
				{
					//0x2346f3b2
					sub_2346f844();
					//loc_2346f3b6 -> loc_2346f6f0
				}
#endif
			}
			//loc_2346f3b6 -> loc_2346f6f0
		}
	} //if (r0 == 0)
	else
	{
		//loc_2346f3b8
		//r5, =0x23495b90

		Menu_Event* r7 = r0;

		Data_23495970.bKeyActivity = 1;

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "menu_root_on_event: r7->keyCode=%d\r\n",
					r7->keyCode);
			console_send_string(debug_string);
		}
#endif

		if (!((r7->keyCode >= 90/*0x5a*/ && r7->keyCode < 98))) //S1...S8
		{
			//0x2346f3c8
			Data_23495970.Data_23495b88 = 0;
		}
		//loc_2346f3cc
		if ((r7->keyCode > 9) && (r7->keyCode != 87/*0x57*/))
		{
			Data_23495970.bData_23495b96 = 0;
		}
		//loc_2346f3da
		if ((r7->keyCode >= 225/*0xe1*/) && (r7->keyCode < 228/*0xe4*/))
		{
			Data_23495970.wFavouriteIndex = r7->keyCode-224/*0xe0*/ + Data_23495970.bData_23495b84;
			Data_23495970.bData_23495b84 = 0;
			Data_23495970.timerVal = 10;
			Data_23495970.timerFunc = store_favourite_timer_func;
			Data_23495970.Data_2349597c = check_favourite_channel;
			//->loc_2346f408
			//loc_2346f40a -> loc_2346f6f0
		}
		//loc_2346f3fc
#if 0
		else if (r7->keyCode == 224/*0xe0*/)
		{
			Data_23495970.timerVal = 0;
			Data_23495970.timerFunc = 0;
			Data_23495970.Data_2349597c = sub_2346f314;
			//loc_2346f40a -> loc_2346f6f0
		}
		//loc_2346f40c
		else if (r7->keyCode == 130/*0x82*/)
		{
			sub_2346f7a8(-1);
			//->loc_2346f6f0
		}
		//loc_2346f416
		else if (r7->keyCode == 131/*0x83*/)
		{
			sub_2346f7a8(1);
			//->loc_2346f6f0
		}
		//loc_2346f422
		else if (r7->keyCode == 128/*0x80*/)
		{
			sub_2346f790(1);
			//->loc_2346f6f0
		}
		//loc_2346f42a
		else if (r7->keyCode == 129/*0x81*/)
		{
			sub_2346f790(-1);
			//->loc_2346f6f0
		}
		//loc_2346f438
#endif		
		else if ((r7->keyCode >= 90/*0x5a*/) && (r7->keyCode < 97)) //S1...S8
		{
			sub_2340bf0c(&sp4);

			if (sp4.wNumChannels != 0)
			{
				//0x2346f44e
				Data_23495970.wFavouriteIndex = r7->keyCode - 89;

				if (Data_23495970.Data_23495b88 == 0)
				{
					Data_23495970.timerVal = 3;
					Data_23495970.timerFunc = check_favourite_timer_func;
					Data_23495970.Data_2349597c = 0;

					Data_23495970.Data_23495b88 = 10;
				}
				//loc_2346f46a
				Data_23495970.Data_23495b88--;

				if (Data_23495970.Data_23495b88 == 1)
				{
					//0x2346f472
					Data_23495970.timerFunc = store_favourite_timer_func(&Data_23495970.Data_23495b88);
					//->loc_2346f6f0
				}
				//->loc_2346f3b6 -> loc_2346f6f0
			}
			//->loc_2346f3b6 -> loc_2346f6f0
		}
		//loc_2346f47e
#if 0
		else if (r7->keyCode == 78/*0x4e*/) //Mode
		{
			sub_234810f6();
			//->loc_2346f6f0
		}
		//loc_2346f488
		else if (r7->keyCode == 70/*0x46*/) //USB
		{
			sub_2346ff0e();
			//->loc_2346f6f0
		}
		//loc_2346f492
		else if (r7->keyCode == 69/*0x45*/) //Radio
		{
			//r0 = 0;
			//->loc_2346f4b0: TODO
			if (0 == sub_2348112c(0))
			{
				//->loc_2346f49a
				sub_2346f77e();
				//->loc_2346f5dc
				Data_23495970.timerVal = 1;
				//->loc_2346f6f0
			}
			//->loc_2346f6f0
		}
		//loc_2346f4a0
		else if (r7->keyCode == 54/*0x36*/)
		{
			//loc_2346f4a4
			sub_2346fac4(0);
			//->loc_2346f6f0
		}
		//loc_2346f4ac
		else if (r7->keyCode == 52/*0x34*/)
		{
			//loc_2346f4b0
			if (0 == sub_2348112c(52))
			{
				//->loc_2346f49a
				sub_2346f77e();
				//->loc_2346f5dc
				Data_23495970.timerVal = 1;
				//->loc_2346f6f0
			}
			//->loc_2346f6f0
		}
		//loc_2346f4ba
		if (r7->keyCode == 55/*0x37*/)
		{
			//0x2346f4be

			//TODO
		}
		//loc_2346f550
		else if (r7->keyCode == 234/*0xea*/)
		{
			//->loc_2346f4a4
			sub_2346fac4(0);
			//->loc_2346f6f0
		}
		//0x2346f554
#endif		
		else if (r7->keyCode == 82/*0x52*/) //Menu
		{
			menu_main_start();
			//->loc_2346f6f0
		}
		//loc_2346f55e
		else if (r7->keyCode == 12/*0x0c*/) //On-Off
		{
			powermode_set_state(2/*Off*/, sub_2343d572(), standby_thread);
			//->loc_2346f6f0
		}
		//loc_2346f572
		else if ((r7->keyCode == 32/*0x20*/) //Up
				|| (r7->keyCode == 48/*0x30*/))
		{
			//loc_2346f57a
			channel_next();
			//->loc_2346f58c
			sub_2346f76c();
			//->loc_2346f6f0
		}
		//loc_2346f580
		else if ((r7->keyCode == 33/*0x21*/) //Down
				|| (r7->keyCode == 49/*0x31*/))
		{
			//loc_2346f588
			channel_prev();
			//loc_2346f58c
			sub_2346f76c();
			//->loc_2346f6f0
		}
		//loc_2346f592
		else if (r7->keyCode == 34/*0x22*/) // <->
		{
			//0x2346f596
			channel_swap();
			//->loc_2346f58c
			sub_2346f76c();
			//->loc_2346f6f0
		}
		//loc_2346f59c
		else if ((r7->keyCode == 17/*0x11*/) //Left
				|| (r7->keyCode == 65/*0x41*/)) //Vol-
		{
			//loc_2346f5a4
			//->loc_2346f5b4
			sub_2340c01c(1, -1);

			frontdisplay_start_text(sub_2346ed20);

			sub_2346f2e2();
			//->loc_2346f6f0
		}
		//loc_2346f5aa
		else if ((r7->keyCode == 16/*0x10*/) //Right
				|| (r7->keyCode == 64/*0x40*/)) //Vol+
		{
			//loc_2346f5b2
			//movs       r1, #0x1
			//loc_2346f5b4
			sub_2340c01c(1, 1);

			frontdisplay_start_text(sub_2346ed20);

			sub_2346f2e2();
			//->loc_2346f6f0
		}
		//loc_2346f5c6
#if 0
		else if (r7->keyCode == 87/*0x57*/) //OK
		{
			if (Data_23495970.bData_23495b96 == 0)
			{
				//->loc_2346f49a
				sub_2346f77e();
				//->loc_2346f5dc
			}
			else
			{
				//loc_2346f5d2
				frontdisplay_start_text(string_display);

				sub_2346f7c0();
				//loc_2346f5dc
			}
			Data_23495970.timerVal = 1;
			//->loc_2346f6f0
		}
		//loc_2346f5e2
		else if (r7->keyCode < 9)
		{
			//TODO
		}
		//loc_2346f654
		else if (r7->keyCode == 42/*0x2a*/)
		{
			//TODO

		}
#endif
		//loc_2346f65e
		//r1, =0x2346f1a9
		//r4, =0x2346f119
		else if (r7->keyCode == 44/*0x2c*/) //Info / EPG
		{
			//0x2346f666
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "menu_root_on_event: Info Key\r\n");
				console_send_string(debug_string);
			}
#endif
			if ((Data_23495970.timerVal/*r3*/ == 0) ||
					(Data_23495970.timerFunc/*r2*/ == sub_2346eeee) ||
					(Data_23495970.timerFunc/*r2*/ == rds_text_timer_func/*r4*/) ||
					(Data_23495970.timerFunc/*r2*/ == rds_ps_name_timer_func/*r1*/))
			{
				//loc_2346f678
				//r0, #0x0
				//->loc_2346f684
				Data_23495970.bEventDisplayMode/*[r5, #0x8]*/ = 0;

				menu_root_start_event_display();
				//->loc_2346f6f0
			}
			else
			{
				//loc_2346f67c
				if (Data_23495970.bEventDisplayMode/*[r5, #0x8]*/ != 0)
				{
					//->loc_2346f5d0 -> loc_2346f49a
					sub_2346f77e();
					//->loc_2346f5dc
					Data_23495970.timerVal = 1;
					//->loc_2346f6f0
				}
				else
				{
					//0x2346f682
					Data_23495970.bEventDisplayMode/*[r5, #0x8]*/ = 1;

					menu_root_start_event_display();
					//->loc_2346f6f0
				}
			}
		} //else if (r7->keyCode == 44/*0x2c*/) //Info / EPG
		//loc_2346f68c
#if 0
		else if (r7->keyCode == 13/*0x0d*/) //Mute
		{
			//TODO

		}
#endif
		//loc_2346f6c6
		else if (r7->keyCode == 47/*0x2f*/) // I / i (Displaytext aktualisieren)
		{
			//0x2346f6ca
			//r0, #0x19
			if (Data_23495970.timerFunc/*r2*/ == rds_text_timer_func/*r4*/)
			{
				//0x2346f6d0
				Data_23495970.timerFunc = rds_ps_name_timer_func/*r1*/;
				Data_23495970.timerVal = 25;
				//->loc_2346f6e0
				//r0, #0x0
				//->loc_2346f408
				Data_23495970.Data_2349597c = 0;
				//loc_2346f40a -> loc_2346f6f0
			}
			//loc_2346f6d6
			else if (Data_23495970.timerFunc == rds_ps_name_timer_func/*r1*/)
			{
				//->loc_2346f49a
				sub_2346f77e();
				//->loc_2346f5dc
				Data_23495970.timerVal = 1;
				//->loc_2346f6f0
			}
			else
			{
				//loc_2346f6dc
				Data_23495970.timerFunc = rds_text_timer_func/*r4*/;
				Data_23495970.timerVal = 25;
				//loc_2346f6e0
				//r0, #0x0
				//->loc_2346f408
				Data_23495970.Data_2349597c = 0;
				//loc_2346f40a -> loc_2346f6f0
			}
		} //else if (r7->keyCode == 47/*0x2f*/) // I / i (Displaytext aktualisieren)
		//loc_2346f6e4
		else if (r7->keyCode == 0xff)
		{
			if (Data_23495970.Data_2349597c != 0)
			{
				(Data_23495970.Data_2349597c)();
			}
		}
		//loc_2346f6f0
	}

	return 0;
}


/* 2346f6f6 - complete */
void sub_2346f6f6(int r4)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2346f6f6: r4=%d\r\n", r4);
		console_send_string(debug_string);
	}
#endif

	OS_ENTER_CRITICAL();

	Data_23495970.bData_23495ba8 = r4;

	OS_EXIT_CRITICAL();
}


/* 2346f708 - todo */
int menu_root_start()
{
	uint8_t r4;
	Struct_235441b0 settings; //sp4

#if 1
	console_send_string("menu_root_start (menu_root_start) (todo.c): TODO\r\n");
#endif

	r4 = Data_23495970.bData_0;

	sub_2340c970(1, &settings);

	memset(&Data_23495970, 0, sizeof(Data_23495970)); //4*143);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "menu_root_start: settings.Data_0x10=0x%x\r\n", 
			settings.Data_0x10);
		console_send_string(debug_string);
	}
#endif

	if (settings.Data_0x10 & (1 << 15)) //Auto-standby flag
	{
		//0x2346f72c
		Data_23495970.standbyTimerFunc = standby_timer_func;
		Data_23495970.bKeyActivity = 1;
	}
	//loc_2346f73a
	if (r4 != 0)
	{
		channel_set_psi_data_callback(sub_2346f6f6);
		sub_2346f76c();
	}
	//loc_2346f748
	sub_2343d482(&Data_23495bac); //Add to the menu stack
	sub_2343d3ac(&Data_23495bac); //Initialize the menu

	return 0;
}


/* 2346f75e - todo */
void sub_2346f75e()
{
	console_send_string("sub_2346f75e (todo.c): TODO\r\n");

}


/* 2346f76c - complete */
int sub_2346f76c()
{
#if 0
	console_send_string("sub_2346f76c (todo.c): TODO\r\n");
#endif

	Data_23495970.timerVal = 10;
	Data_23495970.timerFunc = sub_2346eeee;
	Data_23495970.Data_2349597c = 0;
}


/* 2346f77e - complete */
void sub_2346f77e()
{
#if 0
	console_send_string("sub_2346f77e (todo.c): TODO\r\n");
#endif

	Data_23495970.timerVal = 5;
	Data_23495970.timerFunc = sub_2346ecd4;
	Data_23495970.Data_2349597c = sub_2346eefe;
}


/* 2346f7ce - complete */
void menu_root_start_event_display()
{
#if 0
	console_send_string("menu_root_start_event_display (todo.c): TODO\r\n");
#endif

	Data_23495970.timerVal = 45;
	Data_23495970.timerFunc = event_display_timer_func;
	Data_23495970.Data_2349597c = 0;
}


