
#include "data.h"
#include "ucos_ii.h"
#include "frontdisplay.h"
#include "sub_2340a6a0.h"
#include "channel_list_update.h"

#pragma thumb

extern OS_EVENT* Data_23492f94;
extern void sub_2343df02();
int sub_23470356();
static int menu_channel_search_on_enter();
static int menu_channel_search_lock();
static void menu_channel_search_unlock();
int sub_23470680(UI_Thread_Params*, uint16_t stringId, void*, void*);
void sub_2347092c();
void sub_2343d98e();
int sub_234709d4();
int sub_234709e0();


static Menu_Item menu_channel_search_items[];

struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	uint8_t bData_2; //2

} Data_23495ea0 = //23495ea0
{
		0x2d, 0, 0
};

Menu menu_channel_search = //23495ea4
{
		0xffff,
		&menu_channel_search_items[0], //Menu_Item* Data_4; //4
		&menu_channel_search_items[0], //Menu_Item* Data_8; //8
		0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
		0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
		0, //int Data_0x14; //20 = 0x14
		0, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		0, //void (*Data_0x1c)(); //0x1c
		0, //void (*Data_0x20)(); //0x20
		menu_channel_search_on_enter, //void (*onEnter)(); //36 = 0x24
		sub_23470356, //int (*onExit)(); //0x28
		0, //int Data_0x2c; //44 = 0x2c
		0, //int Data_0x30; //48
		0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
		//0x38 = 56?
}; //->23495EDC

Menu_Item menu_channel_search_items[] = //23495edc
{
	//[0]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //void* Data_0x1c; //0x1c = 28
		menu_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 2349641C
	}, //23495F08
};

extern Menu_Item Data_23495f50;

uint8_t bData_23495f08 = 0; //23495f08
void* Data_23495f0c = 0; //23495f0c
void (*Data_23495f10)() = 0; //23495f10
int Data_23495f14 = 0; //23495f14
Menu Data_23495f18 = //23495f18
{
		0x0085, //uint16_t stringId; //0
		&Data_23495f50, //Menu_Item* Data_4; //4
		&Data_23495f50, //Menu_Item* Data_8; //8
		0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
		0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
		0, //int Data_0x14; //20 = 0x14
		0, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		0, //void (*Data_0x1c)(); //0x1c
		menu_items_navigate, //void (*onNavigate)(); //0x20
		sub_234709d4, //void (*onEnter)(); //36 = 0x24
		sub_234709e0, //int (*onExit)(); //0x28
		0, //int Data_0x2c; //44 = 0x2c
		0, //int Data_0x30; //48
		0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
		//0x38 = 56?
#if 0
		0x23495f18                        dw                                      ; DATA XREF=sub_23470680+4, sub_23470680+14, sub_23470680+20, sub_23470680+26, sub_234706ca+62, sub_23470890+4, sub_2347092c+2, sub_23470978+6, sub_23470978+14, sub_23470978+74, sub_234709e0
		0x23495f1a                        dw         0x0000
		0x23495f1c                        dd         0x23495f50
		0x23495f20                        dd         0x23495f50
		0x23495f24                        dd         0x00000000
		0x23495f28                        dd         0x00000000
		0x23495f2c                        dd         0x00000000
		0x23495f30                        dd         0x00000000
		0x23495f34                        dd         0x00000000
		0x23495f38                        dd         0x2343d4c9
		0x23495f3c                        dd         0x234709d5
		0x23495f40                        dd         0x234709e1
		0x23495f44                        dd         0x00000000
		0x23495f48                        dd         0x00000000
		0x23495f4c                        dd         0x00000000
		0x23495f50
#endif
};

Menu_Item Data_23495f50 = //23495f50
{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_2347092c, //void* Data_0x1c; //0x1c = 28
		sub_2343d98e, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
#if 0
		0x23495f50                        dw         0xffff                             ; DATA XREF=0x23495f1c, 0x23495f20
		0x23495f52                        dw         0xffff
		0x23495f54                        dd         0x00000000
		0x23495f58                        dd         0x00000000
		0x23495f5c                        dd         0x00000000
		0x23495f60                        dd         0x00000000
		0x23495f64                        dd         0x00000000
		0x23495f68                        dd         0x00000000
		0x23495f6c                        dd         0x2347092d
		0x23495f70                        dd         0x2343d98f
		0x23495f74                        dd         0x00000000
		0x23495f78                        dd         0x00000000
		                              dword_23495f7c:
		0x23495f7c
#endif
};


struct
{
	int fill_0[1000]; //0
	//0xfa0 = 4000
} Data_238de5d0; //238de5d0 +0xfa0 -> 238DF570


struct
{
	int fill_0[1000]; //0
	//0xfa0 = 4000
} Data_238df570; //238df570 +0xfa0 -> 238E0510

struct
{
	int Data_0; //0
	OS_EVENT* sema; //4
	void* Data_8; //8
	int fill_12; //12 = 0xc
	uint16_t wData_0x10; //16 = 0x10
	void* Data_0x14; //20 = 0x14
	int fill_0x18; //24 = 0x18
	uint16_t wData_0x1c; //28 = 0x1c
	uint32_t dwCrcChannels; //32 = 0x20
	uint32_t Data_0x24; //36 = 0x24
	uint8_t textString[0x100]; //40 = 0x28

} Data_238e0510; //238e0510



/* 23470298 - todo */
void menu_channel_search_progress(void* r5, int r1, int r2)
{
#if 0
	console_send_string("menu_channel_search_progress (todo.c): TODO\r\n");
#endif

	//r4, =0x238e0510

	if (r2 == 2)
	{
		//0x234702a2
		uint16_t percentage;
		uint16_t r6 = 0;
		uint16_t r7 = 0;

		menu_channel_search_lock();

		if (((uint16_t*)r5)[0] != 0)
		{
			r7 = ((uint16_t*)r5)[0];
			r6 = ((uint16_t*)r5)[1] + 1;
		}
		{
			//loc_234702b8
			uint8_t str[] = "  ";

			percentage = (r6 * 100) / r7;

			if (percentage < Data_238e0510.Data_0x24)
			{
				percentage = Data_238e0510.Data_0x24;
				//->loc_234702d6
			}
			else
			{
				//loc_234702d4
				Data_238e0510.Data_0x24 = percentage;
			}
			//loc_234702d6
			if (percentage > 99)
			{
				str[0] = 0;
				//->loc_234702ea
			}
			//loc_234702e2
			else if (percentage > 9)
			{
				str[1] = 0;
			}
			//loc_234702ea
			snprintf(Data_238e0510.textString, 0xff, "Suche...%s%d%%", str, percentage);
			menu_channel_search_unlock();
		}
	}
	//loc_23470300
	else if (r2 == 1)
	{
		//0x23470304
		sub_23470090(r5, r1, &Data_238e0510.wData_0x10, &Data_238e0510.wData_0x1c);
	}
	//loc_23470314
	else if (r2 == 3)
	{
		//0x23470318
		Data_238e0510.Data_0 = ((int*)r5)[0];

		switch (Data_238e0510.Data_0)
		{
		case 1:
			break;

		case 2:
			sub_2343d556(&Data_23495ea0);
			break;
		}
	}
	//loc_23470312
	return;
}


/* 23470356 - todo */
int sub_23470356()
{
#if 0
	console_send_string("sub_23470356 (todo.c): TODO\r\n");
#endif

	Struct_234fd8f0* r4 = sub_2344f770();

	sub_234101e8();

	sub_23470572();

	uint32_t crc = crc32(r4->arChannels, sizeof(r4->arChannels));

	int crcFail = (crc - Data_238e0510.dwCrcChannels);
	if (crcFail)
	{
		sub_23470890(sub_2343d572(), 5);

		return 1;
	}
	else
	{
		sub_2343dcce();

		return 0;
	}
}


/* 2347038c - todo */
int sub_2347038c()
{
#if 0
	console_send_string("sub_2347038c (todo.c): TODO\r\n");
#endif

	sub_2343d482(0);

	sub_2340add4(0x40300000);

	sub_2343dcce();

	return 0;
}


/* 234703a2 - complete */
int sub_234703a2()
{
	UI_Thread_Params* r4;

#if 0
	console_send_string("sub_234703a2 (todo.c): TODO\r\n");
#endif

	sub_2344f770();

	r4 = sub_2343d572();

	sub_234101e8();

	if (Data_238e0510.Data_0 == 2)
	{
		//0x234703ba
		uint32_t r0 = crc32( (void*) sub_2344f770(), 0x3a980);

		r0 -= Data_238e0510.dwCrcChannels;

		if (r0 != 0)
		{
			sub_234515f0(1, 1);

			sub_23470890(r4, 5);
			//->loc_234703ea
		}
		else
		{
			//loc_234703dc
			sub_23470680(r4, 0x1B9, sub_2347038c, sub_2347038c);
		}
		//loc_234703ea
		return 1;
	}
	//loc_234703ee
	sub_2340add4(0x40300000);

	sub_2343dcce();

	return 0;
}


/* 234703fc - todo */
void* sub_234703fc(FrontDisplay_Job* pJob)
{
	menu_channel_search_lock();

	strncpy(pJob->bData_8, Data_238e0510.textString, 0xff);

	pJob->bNumTextChars = strlen(pJob->bData_8);
	pJob->bDisplayOffset = 0;
	pJob->bNumDisplayChars = 12;
	pJob->bData_0x10b = 0;
	pJob->bData_0x110 = 0;
	pJob->holdTime = 0;
	pJob->Data_4 = 0;
	pJob->bData_0x10f = 0;
	pJob->bData_0x10c = 0;
	pJob->Data_0 = frontdisplay_draw_text;

	if (pJob->bNumTextChars > 12)
	{
		pJob->bData_0x10c = 1;
		pJob->Data_0 = frontdisplay_draw_scroll_text;
	}
	//loc_23470446
	menu_channel_search_unlock();

	return sub_234703fc;
}


/* 2347044e - todo */
int menu_channel_search_on_enter()
{
#if 0
	console_send_string("menu_channel_search_on_enter (todo.c): TODO\r\n");
#endif

	frontdisplay_start_text(sub_234703fc);

	return 0;
}


/* 2347045a - todo */
int sub_2347045a(UI_Thread_Params* r0_, void (*r5)(void*))
{
	Struct_2343df02 sp4;

#if 1
	console_send_string("sub_2347045a (todo.c): TODO\r\n");
#endif

	Data_238e0510.dwCrcChannels = crc32( (void*) sub_2344f770(), 
		sizeof(Channel) * CHANNELS_MAX_NUM);

	Data_238e0510.Data_8 = &Data_238de5d0;
	Data_238e0510.sema = Data_23492f94;
	Data_238e0510.wData_0x10 = 0; //r4
	Data_238e0510.Data_0x14 = &Data_238df570;
	Data_238e0510.wData_0x1c = 0; //r4
	Data_238e0510.Data_0x24 = 0; //r4

	memset(&Data_238df570, 0xff, 0xfa0); //r7
	memset(Data_238e0510.Data_8, 0xff, 0xfa0); //r7
	//->loc_234704f4
	memset(&sp4, 0, sizeof(Struct_2343df02));

	sp4.Data_8 = 0; //r4
	sp4.pfProgress = menu_channel_search_progress;

	if (r5 != 0)
	{
		(r5)(&sp4); //-> sub_2343df02
	}
	//loc_2347050a
	sub_2340b22c(0xff);

	sub_23406834(main_hPSIDecoder1);

	scan_start(&sp4);

	sub_2343d482(&menu_channel_search);

	sub_2343d3ac(&menu_channel_search);

	sub_2343d51e(&menu_channel_search, r0_);

	return 0;
}


/* 23470538 - complete */
void sub_23470538()
{
#if 0
	console_send_string("sub_23470538 (todo.c): TODO\r\n");
#endif

	sub_234515f0(0, 1);

	channel_clear_channel_list();
}


/* 23470548 - complete */
int menu_channel_search_entry(UI_Thread_Params* r4)
{
#if 1
	console_send_string("menu_channel_search_entry (todo.c): TODO\r\n");
#endif

	sub_23470538();

	menu_channel_search.onExit = sub_234703a2;

	sub_2347045a(r4, sub_2343df02);

	return 0;
}


/* 234705d2 - complete */
int menu_channel_search_lock()
{
	uint8_t err;

#if 0
	console_send_string("menu_channel_search_lock (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_238e0510.sema, 0, &err);

	return err;
}


/* 234705e6 - complete */
void menu_channel_search_unlock()
{
#if 0
	console_send_string("menu_channel_search_unlock (todo.c): TODO\r\n");
#endif

	OSSemPost(Data_238e0510.sema);
}


/* 23470680 - todo */
int sub_23470680(UI_Thread_Params* r4, uint16_t stringId, void* r2, void* r3)
{
#if 0
	console_send_string("sub_23470680 (todo.c): TODO\r\n");
#endif

	Data_23495f10 = r3;
	Data_23495f0c = r2;
	Data_23495f18.stringId = stringId;

	sub_2343d482(&Data_23495f18);

	sub_2343d3ac(&Data_23495f18);

	sub_2343d51e(&Data_23495f18, r4);

	return 0;
}


/* 2347092c - todo */
void sub_2347092c()
{
	console_send_string("sub_2347092c (todo.c): TODO\r\n");

}


/* 23470978 - todo */
void* sub_23470978(FrontDisplay_Job* pJob)
{
#if 0
	console_send_string("sub_23470978 (todo.c): TODO\r\n");
#endif

	text_table_get_string(Data_23495f18.stringId, pJob->bData_8, 0xfe);

	pJob->bData_8[0xff] = 0;
	pJob->bNumTextChars = strlen(pJob->bData_8);
	pJob->bDisplayOffset = 0;
	pJob->bNumDisplayChars = 12;
	pJob->bData_0x10b = 0;
	pJob->bData_0x110 = 0;
	pJob->holdTime = 10;
	pJob->Data_4 = 0;
	pJob->bData_0x10f = 0;
	pJob->bData_0x10c = 0;
	pJob->Data_0 = frontdisplay_draw_text;

	if (pJob->bNumTextChars > 12)
	{
		pJob->bData_0x10c = 1;
		pJob->Data_0 = frontdisplay_draw_scroll_text;
	}
	//loc_234709c2
	if (bData_23495f08 != 0)
	{
		pJob->bData_0x10f = 1;

		bData_23495f08 = 0;
	}
	//loc_234709d0
	return sub_23470978;
}


/* 234709d4 - todo */
int sub_234709d4()
{
#if 0
	console_send_string("sub_234709d4 (todo.c): TODO\r\n");
#endif

	frontdisplay_start_text(sub_23470978);

	return 0;
}


/* 234709e0 - todo */
int sub_234709e0()
{
#if 0
	console_send_string("sub_234709e0 (todo.c): TODO\r\n");
#endif

	if (Data_23495f10 != 0)
	{
		(Data_23495f10)();
	}
	//loc_234709ee
	return 0;
}

