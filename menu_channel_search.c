
#include <string.h>
#include "data.h"
#include "ucos_ii.h"
#include "frontdisplay.h"
#include "sub_2340a6a0.h"
#include "nit.h"
#include "channel_list_update.h"
#include "frontdisplay.h"

#pragma thumb

extern OS_EVENT* Data_23492f94;
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


uint16_t Data_238de5d0[2000]; //238de5d0 +0xfa0 -> 238DF570
uint16_t Data_238df570[2000]; //238df570 +0xfa0 -> 238E0510

struct
{
	int Data_0; //0
	OS_EVENT* sema; //4
	uint16_t* Data_8; //8
	int fill_12; //12 = 0xc
	uint16_t wData_0x10; //16 = 0x10
	uint16_t* Data_0x14; //20 = 0x14
	int fill_0x18; //24 = 0x18
	uint16_t wData_0x1c; //28 = 0x1c
	uint32_t dwCrcChannels; //32 = 0x20
	uint32_t Data_0x24; //36 = 0x24
	uint8_t textString[0x100]; //40 = 0x28

} Data_238e0510; //238e0510


/* 23470090 - todo */
void sub_23470090(void* a, uint16_t r7, uint16_t* c, uint16_t* d)
{
#if 0
	console_send_string("sub_23470090 (todo.c): TODO\r\n");
#endif

	Transponder transponder; //sp_0x2c
	Channel channel; //sp4

	uint16_t i;
	uint16_t* r4 = a;
	uint16_t r5 = 0;
	uint16_t r6 = 0;

	for (i = 0; i < 1999; i++)
	{
		//loc_234700a4
		if (Data_238e0510.Data_8[i] == 0xffff)
		{
			r6 = i;
			//->loc_234700ba
			break;
		}
	}
	//loc_234700ba
	for (i = 0; i < 1999; i++)
	{
		//loc_234700c0
		if (Data_238e0510.Data_0x14[i] == 0xffff)
		{
			r5 = i;
			//->loc_234700d6
			break;
		}
	}

	do
	{
		//loc_234700d6
		sub_2340c19c(r4[0], &channel, &transponder);

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_23470090: r7=%d, r6=%d, r5=%d, *r4=0x%x\r\n", 
				r7, r6, r5, r4[0]);
			console_send_string(debug_string);
		}
#endif

		if (channel.Data_0.wFlags_2 & (1 << 3))
		{
			//0x234700ea
			if (r6 < 2000)
			{
				//0x234700ee
				Data_238e0510.Data_8[r6++] = r4[0];
			}
			//loc_2347010e
		}
		else
		{
			//loc_234700fc
			if (r5 < 2000)
			{
				//0x23470100
				Data_238e0510.Data_0x14[r5++] = r4[0];
			}
			//loc_2347010e
		}
		//loc_2347010e
		r4++;
		r7--;
	}
	while (r7 != 0);
	//0x23470118
	*c = r6;
	*d = r5;
}


/* 23470124 - complete */
static void sub_23470124(int r4)
{
#if 0
	console_send_string("sub_23470124 (todo.c): TODO\r\n");
#endif

	sub_23418e54(0);

	powermode_set_state(1, 0, 0);

	sub_23470890(r4, 24);

	return 0;
}


/* 23470144 - todo */
static void sub_23470144(void* r5, int r6, int r4)
{
	Struct_2344dc3c sp4;
	int sp;
	Struct_234fd8f0* r5_;
	uint32_t r1, r0;
	int crcFail;

#if 0
	console_send_string("sub_23470144 (todo.c): TODO\r\n");
#endif

	if (0 != menu_channel_search_lock())
	{
		return;
	}

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23470144: r6=%d, r4=%d\r\n", 
			r6, r4);
		console_send_string(debug_string);
	}
#endif

	if (r4 == 1)
	{
		sub_23470090(r5, r6, &Data_238e0510.wData_0x10, &Data_238e0510.wData_0x1c);
		//->loc_234701d4
	}
	//loc_2347016a
	else if (r4 == 3)
	{
		//0x2347016e
		Data_238e0510.Data_0 = ((int*)r5)[0];

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_23470144: Data_238e0510.Data_0=%d\r\n", 
				Data_238e0510.Data_0);
			console_send_string(debug_string);
		}
#endif

		if (Data_238e0510.Data_0 == 1)
		{
			//->loc_234701d4
		}
		else
		{
			if (Data_238e0510.Data_0 == 2)
			{
				//0x2347017c
				r5_ = sub_2344f770();

				psi_get_network_info(&sp4, main_hPSIDecoder1);

				sp = sp4.Data_4->wData_0x1a;

				sub_2340c368(0, &sp);

				r0 = crc32(r5_->arChannels, sizeof(r5_->arChannels));
				r1 = Data_238e0510.dwCrcChannels;

				crcFail = (r0 - r1);
				if (crcFail)
				{
					//0x234701aa
					sub_234515f0(1, 1);
					sub_23418e54(1);
					sub_2343dca8(sub_23470124);
				}
				//loc_234701be
				powermode_set_state(3, 0, 0);
				//->loc_234701ce
				sub_2343deb4(1);
			}
			else if (Data_238e0510.Data_0 == 3)
			{
				//0x234701ce
				sub_2343deb4(1);
			}
		}
	}
	//loc_234701d4
	menu_channel_search_unlock();
}


/* 234701da - todo */
int sub_234701da(Transponder arTransponders[], int numTransponders, void* sema)
{
	Struct_2343df02 sp_0x40;
	Struct_235441b0 sp_0x24;
	Struct_2354613c sp4;

#if 0
	console_send_string("sub_234701da (todo.c): TODO\r\n");
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_234701da: numTransponders=%d\r\n", numTransponders);
		console_send_string(debug_string);
	}
#endif

	Struct_234fd8f0* r6 = sub_2344f770();

	Data_238e0510.sema = sema;

	menu_channel_search_lock();

	Data_238e0510.dwCrcChannels = crc32(&r6->arChannels[0], sizeof(r6->arChannels));
	Data_238e0510.Data_8 = &Data_238de5d0[0];
	Data_238e0510.wData_0x10 = 0; //r5
	Data_238e0510.Data_0x14 = &Data_238df570[0];
	Data_238e0510.wData_0x1c = 0; //r5

	memset(&Data_238e0510.Data_0x14[0], 0xff, 4000);
	memset(&Data_238e0510.Data_8[0], 0xff, 4000);
	memset(&sp_0x40, 0, sizeof(Struct_2343df02));

	sp_0x40.bData_0x11 = 1; //r6
	sp_0x40.Data_8 = 0; //r5
	sp_0x40.pfProgress = sub_23470144;
	sp_0x40.listLen = numTransponders;
	sp_0x40.pList = arTransponders;
	sp_0x40.bData_0x10 = 1; //r6

	sub_2340c970(1, &sp_0x24);

	sp_0x40.bData_0x12 = (sp_0x24.Data_4 >> 23) & 0x03;

	sub_2340ca5c(1, &sp4);

	uint32_t r4 = sp4.crc;
	sp4.crc = 0; //r5

	uint32_t r0 = crc32(&sp4, sizeof(sp4));

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_234701da: r4=0x%x, r0=0x%x\r\n", r4, r0);
		console_send_string(debug_string);
	}
#endif

	if (r0 == r4)
	{
		//0x23470264
		arTransponders[0] = sp4.transponder;

		sp_0x40.listLen = 1;
		sp_0x40.wData_0x16 = sp4.wData_0x18;
		sp_0x40.wData_0x14 = sp4.wData_0x1a;
	}
	else
	{
		//loc_23470280
		sp_0x40.wData_0x14 = 0xffff;
	}

	scan_start(&sp_0x40);

	menu_channel_search_unlock();

	return 0;
}


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

	Data_238e0510.Data_8 = &Data_238de5d0[0];
	Data_238e0510.sema = Data_23492f94;
	Data_238e0510.wData_0x10 = 0; //r4
	Data_238e0510.Data_0x14 = &Data_238df570[0];
	Data_238e0510.wData_0x1c = 0; //r4
	Data_238e0510.Data_0x24 = 0; //r4

	memset(&Data_238e0510.Data_0x14[0], 0xff, 0xfa0); //r7
	memset(&Data_238e0510.Data_8[0], 0xff, 0xfa0); //r7
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

