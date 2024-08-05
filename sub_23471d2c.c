
#include <string.h>
#include "data.h"
#include "frontdisplay.h"


#pragma thumb


static int sub_23471780(void);
static int sub_23471a1c(int);
static int sub_23471d1a(UI_Thread_Params*);

static Menu_Item Data_23496244[]; //23496244

static Menu menu_information = //2349620c
{
    63, //"information"
    &Data_23496244[0], //Menu_Item* Data_4; //4
    &Data_23496244[0], //Menu_Item* Data_8; //8
    0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
    0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
    0, //int Data_0x14; //20 = 0x14
    7, //uint8_t maxItem; //0x18 = 24
    0, //int8_t currentItem; //0x19
    0, //void (*Data_0x1c)(); //0x1c
    menu_items_navigate, //int (*onNavigate)(int*); //0x20
    sub_23471a1c, //int (*onEnter)(int); //36 = 0x24
    sub_23471d1a, //int (*onExit)(UI_Thread_Params*); //0x28
    0, //int Data_0x2c; //44 = 0x2c
    0, //int timeout; //48
    0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
    //0x38 = 56?
#if 0
0x2349620c                        dw         0x003f                             ; DATA XREF=sub_23471818, sub_234718c6+8, sub_234718c6+16, dword_23471b40, aLock+272, sub_23471d2c+4, sub_23471d2c+10, sub_23471d2c+16, dword_23471d84
0x2349620e 0000                   movs       r0, r0
0x23496210                        dd         0x23496244
0x23496214                        dd         0x23496244
0x23496218 0000                   movs       r0, r0
0x2349621a 0000                   movs       r0, r0
0x2349621c 0000                   movs       r0, r0
0x2349621e 0000                   movs       r0, r0
0x23496220 0000                   movs       r0, r0
0x23496222 0000                   movs       r0, r0                             ; CODE XREF=word_23496104+120
0x23496224                        db         0x07                               ; DATA XREF=aLock+276
0x23496225                        db  0x00 ; '.'                                ; DATA XREF=sub_23471818+10
0x23496226 0000                   movs       r0, r0
0x23496228 0000                   movs       r0, r0
0x2349622a 0000                   movs       r0, r0
0x2349622c                        dd         menu_items_navigate+1
0x23496230                        dd         sub_23471a1c+1
0x23496234                        dd         sub_23471d1a+1
0x23496238 0000                   movs       r0, r0
0x2349623a 0000                   movs       r0, r0
0x2349623c 0000                   movs       r0, r0
0x2349623e 0000                   movs       r0, r0
0x23496240 0000                   movs       r0, r0
0x23496242 0000                   movs       r0, r0
#endif
};

Menu_Item Data_23496244[8] = //23496244
{
	//[0]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[1]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[2]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[3]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[4]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[5]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[6]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[7]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
};


struct 
{
	Transponder Data_238e09c0; //238E09C0
	uint16_t wData_238e09d8; //238E09D8
	uint16_t wData_238e09da; //238E09DA
	Struct_23543df0 Data_238e09dc; //238E09DC
	int fill_238e09fc; //238E09FC
	int Data_238e0a00; //238E0A00
	void* Data_238e0a04; //238e0a04
	char strTransponder[52]; //238e0a08
	char Data_238e0a3c[12]; //238E0A3C
	char Data_238e0a48[12]; //238E0A48
	char Data_238e0a54[16]; //238E0A54
	char Data_238e0a64[12]; //238E0A64
	char Data_238e0a70[52]; //238E0A70
	char Data_238e0aa4[16/*size?*/]; //238E0AA4

} Data_238e09d8;




/* 2347167c - todo */
void menu_information_get_transponder_string(Transponder* r5)
{
#if 0
	console_send_string("menu_information_get_transponder_string (todo.c): TODO\r\n");
#endif

	char sp4[20]; //size???
	int modulation;
	int r0 = fe_manager_get_transponder_type(r5);

	switch (r0)
	{
		case 1:
			//loc_234716d6
			memset(&Data_238e09d8.strTransponder[0], 0, 50);
			
			snprintf(Data_238e09d8.strTransponder, 49, "%dMHz", r5->Data_0.frequency / 10000);
			snprintf(sp4, 11, " %dkS/s", r5->Data_0.symbol_rate);
			strncat(Data_238e09d8.strTransponder, sp4, 48 - strlen(Data_238e09d8.strTransponder));
			
			modulation = r5->Data_0.Data_0.Bitfield_0.modulation;

			if (modulation == 1)
			{
				strncat(Data_238e09d8.strTransponder, " 16QAM", 48 - strlen(Data_238e09d8.strTransponder));
			}
			else if (modulation == 2)
			{
				strncat(Data_238e09d8.strTransponder, " 32QAM", 48 - strlen(Data_238e09d8.strTransponder));
			}
			else if (modulation == 3)
			{
				strncat(Data_238e09d8.strTransponder, " 64QAM", 48 - strlen(Data_238e09d8.strTransponder));
			}
			else if (modulation == 4)
			{
				strncat(Data_238e09d8.strTransponder, " 128QAM", 48 - strlen(Data_238e09d8.strTransponder));
			}
			else if (modulation == 5)
			{
				strncat(Data_238e09d8.strTransponder, " 256QAM", 48 - strlen(Data_238e09d8.strTransponder));
			}
			else
			{
				strncat(Data_238e09d8.strTransponder, " ???QAM", 48 - strlen(Data_238e09d8.strTransponder));
			}
			break;

		case 3:
			//0x2347168e
#if 0
			sprintf(Data_238e09d8.strTransponder, "Transponder Type 3");
#endif
			break;

		default:
			//loc_23471776
			sprintf(Data_238e09d8.strTransponder, "No Channel Info");
			break;
	}
	//loc_234716d2
}


/* 23471780 - complete */
static int sub_23471780(void)
{
#if 0
	console_send_string("sub_23471780 (todo.c): TODO\r\n");
#endif

	return 0;
}


/* 23471784 - todo */
void menu_information_get_service_strings(uint8_t* str, int strLen)
{
	Transponder transponder;
	Channel channel;
	Struct_2340bf0c sp_0x18;
	char buf[20];

#if 0
	console_send_string("menu_information_get_service_strings (todo.c): TODO\r\n");
#endif

	sub_2340bf0c(&sp_0x18);

	sub_2340bf94(sp_0x18.wCurrentChannel, &channel, &transponder);

	if (channel.service_id != 0)
	{
		sprintf(str, "SID: 0x%x", channel.service_id);
	}
	else
	{
		sprintf(str, "SID: -");
	}

	if (channel.wAudioPID != 0)
	{
		sprintf(buf, "  %s 0x%x", "APID:", channel.wAudioPID);
	}
	else
	{
		sprintf(buf, "  %s -", "APID:");
	}

	strncat(str, buf, strLen - strlen(str) - 2);

	if (channel.wAc3PID != 0)
	{
		sprintf(buf, "  %s 0x%x", "AC3PID:", channel.wAc3PID);
	}
	else
	{
		sprintf(buf, "  %s - ", "AC3PID:");
	}

	strncat(str, buf, strLen - strlen(str) - 2);
}


/* 23471818 - complete */
void* sub_23471818(FrontDisplay_Job a[])
{
#if 0
	console_send_string("sub_23471818 (todo.c): TODO\r\n");
#endif

	if (menu_information.currentItem == 0)
	{
		strncpy(&a[0].bData_8[0], &Data_238e09d8.strTransponder[0], 255);
	}
	else if (menu_information.currentItem == 1)
	{
		strncpy(&a[0].bData_8[0], &Data_238e09d8.Data_238e0a54[0], 255);
	}
	else if (menu_information.currentItem == 2)
	{
		strncpy(&a[0].bData_8[0], &Data_238e09d8.Data_238e0a48[0], 255);
	}
	else if (menu_information.currentItem == 3)
	{
		strncpy(&a[0].bData_8[0], &Data_238e09d8.Data_238e0a3c[0], 255);
	}
	else if (menu_information.currentItem == 4)
	{
		strncpy(&a[0].bData_8[0], &Data_238e09d8.Data_238e0a64[0], 255);
	}
	else if (menu_information.currentItem == 5)
	{
		menu_information_get_service_strings(&a[0].bData_8[0], 255);
	}
	else if (menu_information.currentItem == 6)
	{
		strncpy(&a[0].bData_8[0], &Data_238e09d8.Data_238e0a70[0], 255);
	}
	else
	{
		snprintf(&a[0].bData_8[0], 251, "MAC:%s", &Data_238e09d8.Data_238e0aa4[3]);
	}

	a[0].bData_8[255] = 0;

	uint8_t len = strlen(&a[0].bData_8[0]);

	a[0].bNumTextChars = len;
	a[0].bDisplayOffset = 0;
	a[0].bNumDisplayChars = 12;
	a[0].bData_0x10b = 0;
	a[0].bData_0x110 = 0;
	a[0].holdTime = 0;
	a[0].bData_0x10f = 0;
	a[0].Data_4 = 0;

	if (len > 12)
	{
		a[0].bData_0x10c = 1;
		a[0].Data_0 = frontdisplay_draw_scroll_text;
	}
	else
	{
		a[0].bData_0x10c = 0;
		a[0].Data_0 = frontdisplay_draw_text;
	}

	return sub_23471818;
}


/* 234718c6 - complete */
void* sub_234718c6(FrontDisplay_Job a[])
{
#if 0
	console_send_string("sub_234718c6 (todo.c): TODO\r\n");
#endif

	a[0].bData_8[0] = 0x22;

	text_table_get_string(menu_information.stringId, &a[0].bData_8[1], 252);

	uint8_t len = strlen(&a[0].bData_8[0]);

	a[0].bData_8[len] = 0x22;
	len++;
	a[0].bData_8[len] = 0;

	len = strlen(&a[0].bData_8[0]);

	a[0].bNumTextChars = len;
	a[0].bDisplayOffset = 0; 
	a[0].bNumDisplayChars = 12;
	a[0].bData_0x10b = 0; 
	a[0].bData_0x10c = 0; 
	a[0].bData_0x110 = 0; 
	a[0].holdTime = 20;
	a[0].Data_4 = 0;
	a[0].Data_0 = frontdisplay_draw_text;
	a[0].bData_0x10f = 0; 

	if (len > 12)
	{
		a[0].bData_8[10] = 0x2e;
		a[0].bData_8[11] = 0x22;
		a[0].bData_8[12] = 0;
	}
	//loc_23471928
	return sub_23471818;
}


/* 2347192c - todo */
static void sub_2347192c(void)
{
	console_send_string("sub_2347192c (todo.c): TODO\r\n");

}


/* 23471a1c - todo */
static int sub_23471a1c(int a)
{
#if 0
	console_send_string("sub_23471a1c (todo.c): TODO\r\n");
#endif

	Transponder sp_0x7c;
	Channel sp_0x54;
	int sp_0x50;
    Struct_2340bf0c sp_0x1c;

    sub_2340bf0c(&sp_0x1c);

    char sp_0xc[16] = "not defined";
	struct
	{
		uint32_t Data_0; //0
		uint32_t Data_4; //4
	} sp4;
	uint32_t sp;
    
	Data_238e09d8.wData_238e09d8 = Data_238e09d8.wData_238e09da = sp_0x1c.wCurrentChannel;

	sub_2340bf94(Data_238e09d8.wData_238e09da, &sp_0x54, &sp_0x7c);

	Data_238e09d8.Data_238e0a00 = fe_manager_get_transponder_type(&sp_0x7c);
	Data_238e09d8.Data_238e0a04 = main_hFrontend1;

	if (sp_0x54.wTransponderIndex == 0xffff)
	{
		//0x23471a5e
		sub_2340ec8c(main_hFrontend1, 0);

		strcpy(&Data_238e09d8.Data_238e0a3c[0], "BER: -");
		strcpy(&Data_238e09d8.Data_238e0a48[0], "C/N: -");
		text_table_get_string(0x1c4, &Data_238e09d8.Data_238e0a54[0], 13);
		strcat(&Data_238e09d8.Data_238e0a54[0], "-");
		strcpy(&Data_238e09d8.Data_238e0a64[0], "Lock: -");
		//->loc_23471c0e
	}
	else
	{
		//loc_23471a96 -> loc_23471c08
		sub_2340ec8c(main_hFrontend1, sub_2347192c);
	}
	//loc_23471c0e
	sub_2340c29c(&Data_238e09d8.Data_238e09dc, sp_0x7c.Data_0.wData_0x0a);
	
	Data_238e09d8.Data_238e09c0 = sp_0x7c;

	memset(&Data_238e09d8.Data_238e0a70[0], 0, 50);

	text_table_get_string(0x43, &Data_238e09d8.Data_238e0a70[0], 49);
	strncat(&Data_238e09d8.Data_238e0a70[0], ": V.", 4);

	sub_234070cc("BEMON/SmartHD/0148/211008/0000", &sp_0xc[0]);

	if (0 != sub_23429bf8())
	{
		//0x23471c56
		sp_0xc[4] = 'A';
		sp_0xc[5] = 0;
	}
	//loc_23471c60
	strncat(&Data_238e09d8.Data_238e0a70[0], &sp_0xc[0], 5);

	memset(&sp_0xc[0], 0, sizeof(sp_0xc));

	strncat(&sp_0xc[0], " Font: V.", 9);

	sub_234070cc(sub_2340929c(&sp_0x50), &sp_0xc[9]);

	strncat(&Data_238e09d8.Data_238e0a70[0], &sp_0xc[0], 
		48 - strlen(&Data_238e09d8.Data_238e0a70[0]));

	sub_2340c368(1, &sp);

	memset(&sp_0xc[0], 0, sizeof(sp_0xc));

	if (sp == -1)
	{
		//0x23471cbe
		strcpy(&sp_0xc[0], " List: -1");
	}
	else
	{
		//loc_23471cc8
		snprintf(&sp_0xc[0], 11, " List: %2x", (uint8_t)sp);
	}
	//loc_23471cd4
	strncat(&Data_238e09d8.Data_238e0a70[0], &sp_0xc[0], 
		48 - strlen(&Data_238e09d8.Data_238e0a70[0]));

	menu_information_get_transponder_string(&sp_0x7c);

	if (0 != network_get_device())
	{
		//0x23471cf6
		extern void (*Data_234920ec)();

		if (Data_234920ec != 0)
		{
			(Data_234920ec)(&Data_238e09d8.Data_238e0aa4[0], &sp4);
		}
		//->loc_23471d0e
	}
	else
	{
		//loc_23471d08
		menu_information.maxItem = 6;
	}
	//loc_23471d0e
	frontdisplay_start_text(sub_234718c6);

	return 0;
}


/* 23471d1a - todo */
static int sub_23471d1a(UI_Thread_Params* a)
{
#if 0
	console_send_string("sub_23471d1a (todo.c): TODO\r\n");
#endif

	sub_2340ec8c(Data_238e09d8.Data_238e0a04, 0);

	return 0;
}


/* 23471d2c - todo */
int sub_23471d2c(UI_Thread_Params* r4)
{
#if 0
	console_send_string("sub_23471d2c (todo.c): TODO\r\n");
#endif

	sub_2343d482(&menu_information);

	sub_2343d3ac(&menu_information);

	sub_2343d51e(&menu_information, r4);

	return 0;
}

