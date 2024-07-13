
#include "data.h"
#include "frontdisplay.h"

#pragma thumb

extern int menu_main_on_enter(int);
extern int menu_main_on_exit(int);
extern int menu_items_navigate(int*);
extern void menu_event_thread(UI_Thread_Params*);


Menu_Item menu_main_items[7] = //23492f98 +4
{
	//[0]
	{
		80, //"Allgemein"
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_general_settings_on_enter, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23492fc4
#if 0
		0x23492f98                        dw         0x0050
		0x23492f9a                        dw         0xffff
		0x23492f9c                        dd         0x00000000
		                              dword_23492fa0:
		0x23492fa0                        dd         0x00000000                         ; DATA XREF=sub_2343d104+22, aTvradio+80
		0x23492fa4                        dd         0x00000000
		0x23492fa8                        dd         0x00000000
		0x23492fac                        dd         0x00000000
		0x23492fb0                        dd         0x00000000
		0x23492fb4                        dd         0x23471fa3
		0x23492fb8                        dd         0x2343d6e3
		0x23492fbc                        dd         0x00000000
		0x23492fc0                        dd         0x00000000
#endif
	},
	//[1]
#if 0
	{
		11, //"Sendersuche"
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23470548, //void* Data_0x1c; //0x1c = 28
		menu_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 23492FF0
#if 0
		0x23492fc4                        dw         0x000b                             ; DATA XREF=sub_2343d104+18
		0x23492fc6                        dw         0xffff
		                              dword_23492fc8:
		0x23492fc8                        dd         0x00000000                         ; DATA XREF=aIn1Optical+20
		0x23492fcc                        dd         0x00000000
		0x23492fd0                        dd         0x00000000
		0x23492fd4                        dd         0x00000000
		0x23492fd8                        dd         0x00000000
		                              dword_23492fdc:
		0x23492fdc                        dd         0x00000000                         ; DATA XREF=dword_23492eac+8
		0x23492fe0                        dd         0x23470549
		0x23492fe4                        dd         0x2343d6e3
		0x23492fe8                        dd         0x00000000
		                              dword_23492fec:
		0x23492fec                        dd         0x00000000
#endif
	},
	//[2]
	{
		401, //"Equalizer"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		sub_23471600,
		menu_event_thread,
		0,
		0
		//0x2349301c
#if 0
			0x23492ff0                        dw         0x0191                             ; DATA XREF=dword_23492ec0+8
			0x23492ff2                        dw         0xffff
			0x23492ff4                        dd         0x00000000
			0x23492ff8                        dd         0x00000000
			0x23492ffc                        dd         0x00000000
			0x23493000                        dd         0x00000000
			0x23493004                        dd         0x00000000
			0x23493008                        dd         0x00000000
			0x2349300c                        dd         0x23471601                         ; DATA XREF=dword_23492c7c+80
			0x23493010                        dd         0x2343d6e3
			0x23493014                        dd         0x00000000                         ; DATA XREF=dword_23492c7c+88
			0x23493018                        dd         0x00000000

#endif
	},
	//[3]
	{
		TEXT_ID_NETZWERK, //"Netzwerk"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		menu_network_on_entry,
		menu_event_thread,
		0,
		0
		//0x23493048
#if 0
			0x2349301c                        dw         0x015d
			0x2349301e                        dw         0xffff
			0x23493020                        dd         0x00000000
			0x23493024                        dd         0x00000000
			0x23493028                        dd         0x00000000
			0x2349302c                        dd         0x00000000
			0x23493030                        dd         0x00000000
			0x23493034                        dd         0x00000000
			0x23493038                        dd         0x23470f23
			0x2349303c                        dd         0x2343d6e3
			0x23493040                        dd         0x00000000
			0x23493044                        dd         0x00000000
#endif
	},
	//[4]
	{
		87, //"Werkszustand"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		sub_2343d1ca,
		menu_event_thread,
		0,
		0
		//0x23493074
#if 0
		0x23493048                        dw         0x0057
		0x2349304a                        dw         0xffff
		0x2349304c                        dd         0x00000000
		0x23493050                        dd         0x00000000
		0x23493054                        dd         0x00000000                         ; DATA XREF=dword_23492c7c+32
		0x23493058                        dd         0x00000000
		0x2349305c                        dd         0x00000000
		0x23493060                        dd         0x00000000
		0x23493064                        dd         0x2343d1cb
		0x23493068                        dd         0x2343d6e3
		0x2349306c                        dd         0x00000000
		0x23493070                        dd         0x00000000
#endif
	},
	//[5]
	{
		63, //"information"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		sub_23471d2c,
		menu_event_thread,
		0,
		0
		//0x234930a0
#if 0
		0x23493074                        dw         0x003f
		0x23493076                        dw         0xffff
		0x23493078                        dd         0x00000000
		0x2349307c                        dd         0x00000000
		0x23493080                        dd         0x00000000
		0x23493084                        dd         0x00000000
		0x23493088                        dd         0x00000000
		0x2349308c                        dd         0x00000000
		0x23493090                        dd         0x23471d2d
		0x23493094                        dd         0x2343d6e3
		0x23493098                        dd         0x00000000
		0x2349309c                        dd         0x00000000
#endif
	},
	//[6]
	{
		458, //"Software-Update"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		sub_2347004a,
		menu_event_thread,
		0,
		0
		//0x234930cc
#if 0
		0x234930a0                        dw         0x01ca
		0x234930a2                        dw         0xffff                             ; DATA XREF=sub_2343d104+48
		0x234930a4                        dd         0x00000000                         ; DATA XREF=sub_2343d104+52
		0x234930a8                        dd         0x00000000                         ; DATA XREF=sub_2343d104+58
		0x234930ac                        dd         0x00000000
		0x234930b0                        dd         0x00000000
		0x234930b4                        dd         0x00000000
		0x234930b8                        dd         0x00000000
		0x234930bc                        dd         0x2347004b
		0x234930c0                        dd         0x2343d6e3
		0x234930c4                        dd         0x00000000
		0x234930c8                        dd         0x00000000
#endif
	}
#endif
};

Menu menuMain = //234930cc
{
		10, //"Hauptmenu"
		&menu_main_items[0], //Menu_Item* Data_4; //4
		&menu_main_items[0], //Menu_Item* Data_8; //8
		0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
		0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
		0, //int Data_0x14; //20 = 0x14
		0, //6, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		0, //void (*Data_0x1c)(); //0x1c
		menu_items_navigate, //int (*onNavigate)(int*); //0x20
		menu_main_on_enter, //int (*onEnter)(int); //36 = 0x24
		menu_main_on_exit, //int (*onExit)(int); //0x28
		0, //int Data_0x2c; //44 = 0x2c
		0, //int timeout; //48
		0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
		//0x38 = 56?
#if 0
		0x234930cc                        dw         0x000a
		0x234930ce                        dw         0x0000
		0x234930d0                        dd         0x23492f98
		0x234930d4                        dd         0x23492f98                         ; DATA XREF=sub_2343d104+10
		0x234930d8                        dd         0x00000000
		0x234930dc                        dd         0x00000000
		0x234930e0                        dd         0x00000000
		0x234930e4                        db  0x06 ; '.'
		                              byte_234930e5:
		0x234930e5                        db         0x00                               ; DATA XREF=sub_2343d104+8
		0x234930e6 0000                   movs       r0, r0
		0x234930e8                        dd         0x00000000
		0x234930ec                        dd         0x2343d4c9
		0x234930f0                        dd         0x2343d1ad
		0x234930f4                        dd         0x2343d1bf
		0x234930f8                        dd         0x00000000
		0x234930fc                        dd         0x00000000
		0x23493100                        dd         0x00000000
#endif
}; //23493104

void (*Data_23493104)(UI_Thread_Params*) = 0; //23493104

UI_Thread_Params Data_235fdf28; //235fdf28 235fdf98 -0x70
UI_Thread_Params Data_235fdf40; //235fdf40 235fdf58 - 0x18
UI_Thread_Params Data_235fdf58; //235fdf58 235fdf98 -0x40
UI_Thread_Params* Data_235fdf70; //235fdf70 / 2378336C -0x40 + 0x18
Menu* menu_stack[13]; //235fdf74 -0x40 + 0x1c, size???
uint8_t menu_stack_level; //235fdfa8 235fdf98 + 0x10



/* 2343d104 - complete */
void* sub_2343d104(FrontDisplay_Job* r5)
{
#if 0
	console_send_string("sub_2343d104 (todo.c): TODO\r\n");
#endif

	text_table_get_string(menuMain.Data_8[menuMain.currentItem].wData_0, r5->bData_8, 0xfe);

	r5->bNumTextChars = strlen(r5->bData_8);
	r5->bDisplayOffset = 0;
	r5->bNumDisplayChars = 12;
	r5->bData_0x10b = 0;
	r5->holdTime = 0;
	r5->Data_4 = 0;
	r5->bData_0x10f = 0;
	r5->bData_0x10c = 0;
	r5->Data_0 = frontdisplay_draw_text;

	if (r5->bNumTextChars > 12)
	{
		r5->bData_0x10c = 1;
		r5->Data_0 = frontdisplay_draw_scroll_text;
	}
	//loc_2343d152
	return sub_2343d104;
}


/* 2343d156 - todo */
void* sub_2343d156(FrontDisplay_Job* r4)
{
	uint8_t* str; //r6
	uint8_t len;

#if 0
	console_send_string("sub_2343d156 (todo.c): TODO\r\n");
#endif

	r4->bData_8[0] = 0x22;

	text_table_get_string(menuMain.stringId, &r4->bData_8[1], 0xfc);

	str = &r4->bData_8[0];

	len = strlen(str);

	r4->bData_8[len++] = 0x22;
	r4->bData_8[len] = 0;

	r4->bNumTextChars = strlen(str);
	r4->bDisplayOffset = 0; //r5
	r4->bNumDisplayChars = 12;
	r4->bData_0x10b = 0; //r5
	r4->bData_0x10c = 0; //r5
	r4->bData_0x110 = 0; //r5
	r4->holdTime = 15;

	r4->Data_0 = frontdisplay_draw_text;
	r4->Data_4 = 0; //r5
	r4->bData_0x10f = 0; //r5

	return sub_2343d104;
}


/* 2343d1ac - todo */
int menu_main_on_enter(int a)
{
#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "menu_main_on_enter: a=%d\r\n", a);
        console_send_string(debug_string);
    }
#endif

	sub_23410f28(0);

	frontdisplay_start_text(sub_2343d156);

	return 0;
}


/* 2343d1be - complete */
int menu_main_on_exit(int a)
{
#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "menu_main_on_exit: a=%d\r\n", a);
        console_send_string(debug_string);
    }
#endif

	sub_23410f28(1);

	return 0;
}


/* 2343d1d6 - todo */
int menu_main_start()
{
	UI_Thread_Params* r4;

#if 1
	console_send_string("menu_main_start (todo.c): TODO\r\n");
#endif

	r4 = sub_2343d572(); //Get the current UI thread params

	sub_2343d482(&menuMain); //Add to the menu stack
	sub_2343d3ac(&menuMain); //Initialize the menu
	sub_2343d51e(&menuMain, r4); //Backup UI thread params?

	return 0;
}


/* Menu Initialize */
/* 2343d3ac - complete */
void sub_2343d3ac(Menu* pMenu)
{
	struct
	{
		int fill_0[4]; //0
		//???
	} sp_0x40;

	struct
	{
		int fill[13]; //0
		//???
	} sp_0xc;

	Menu_Item* pMenuItem;

#if 0
	console_send_string("sub_2343d3ac (todo.c): TODO\r\n");
#endif

	if (pMenu->onEnter != 0)
	{
		(pMenu->onEnter)(0);
	}
	//loc_2343d3bc
	//r6 = 0xffff;
	if ((pMenu->Data_0xc != 0) && (pMenu->Data_0xc->Data_0x20 != 0)
			&& (pMenu->stringId != 0xffff/*r6*/))
	{
		text_table_get_string(pMenu->stringId, pMenu->Data_0xc->Data_0x20->Data_0x10, 36);
	}
	//loc_2343d3d8
	if (pMenu->Data_8 != 0)
	{
		if (pMenu->Data_0x34 != 0)
		{
			pMenuItem = (pMenu->Data_0x34)(pMenu);
			//->loc_2343d40a
		}
		else
		{
			//loc_2343d3ec
			if (pMenu->Data_0x2c == 0)
			{
				pMenu->currentItem = 0;
			}
			//loc_2343d3f4
			pMenuItem = &pMenu->Data_8[pMenu->currentItem];

			pMenu->Data_4 = pMenuItem;

			if (pMenuItem->Data_0x18 != 0)
			{
				(pMenuItem->Data_0x18)(pMenuItem);
			}
			//loc_2343d40a
		}
		//loc_2343d40a
		if ((pMenu->Data_0x10 != 0) && (pMenu->Data_0x10->Data_0x20 != 0))
		{
			if (pMenuItem->wData_2 != 0xffff/*r6*/)
			{
				//0x2343d41c
				Struct_235fdf74_Inner16_Inner0x20* r5_;

				text_table_get_string(pMenuItem->wData_2, pMenu->Data_0x10->Data_0x20->Data_0x10, 244);

				r5_ = pMenu->Data_0x10->Data_0x20;

				sub_234089e8(&sp_0xc, r5_->Data_0x10, r5_->bData_0xd,
						r5_->wData_2, r5_->wData_4, r5_->wData_6, 4);
				//->loc_2343d448
			}
			else
			{
				//loc_2343d440
				memset(pMenu->Data_0x10->Data_0x20->Data_0x10, 0, 243);
			}
		}
		//loc_2343d448
		if (pMenu->Data_0x1c != 0)
		{
			(pMenu->Data_0x1c)(&sp_0x40, pMenu->Data_0x14);
		}
	} //if (pMenu->Data_8 != 0)
	//loc_2343d454
	return;
}


/* 2343d458 - todo */
void sub_2343d458(UI_Thread_Params* a)
{
	memcpy(&Data_235fdf58, a, sizeof(UI_Thread_Params));
}


//MenuStack Add or Remove
/* 2343d482 - todo */
Menu* sub_2343d482(Menu* r4)
{
	Menu* r0_;
	Menu** r0 = &menu_stack[menu_stack_level];

	if (r4 != 0)
	{
		r0_ = *r0;

		menu_stack_level++;
		if (menu_stack_level < 13)
		{
			menu_stack[menu_stack_level] = r4;
			return r0_;
		}
		else
		{
			//loc_2343d4ac
			return 0;
		}
	}
	else
	{
		//loc_2343d4b0
		*r0 = 0;

		if (menu_stack_level != 0)
		{
			menu_stack_level--;
		}
		//loc_2343d4be
		return menu_stack[menu_stack_level];
	}
}


/* 2343d4c8 - todo */
int menu_items_navigate(int* a)
{
	Menu* r1;
	int handled = 0;

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "menu_items_navigate: *a=%d\r\n", *a);
        console_send_string(debug_string);
    }
#endif

	r1 = menu_stack[menu_stack_level];

	if (*a == 2) //Down
	{
		r1->currentItem--;
		if (r1->currentItem < 0)
		{
			r1->currentItem = r1->maxItem;
		}
		//loc_2343d504
		handled = 1;
	}
	//loc_2343d4ee
	else if (*a == 1) //Up
	{
		r1->currentItem++;
		if (r1->currentItem > r1->maxItem)
		{
			r1->currentItem = 0;
		}
		//loc_2343d504
		handled = 1;
	}

	if (handled)
	{
		//loc_2343d504
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "menu_items_navigate: currentItem=%d\r\n", r1->currentItem);
			console_send_string(debug_string);
		}
#endif

		r1->Data_4 = &r1->Data_8[r1->currentItem];

		if (r1->Data_4->Data_0x18 != 0)
		{
			(r1->Data_4->Data_0x18)(r1->Data_4);
		}
	}
	//loc_2343d51a
	return 0;
}


/* 2343d51e - todo */
int sub_2343d51e(Menu* r2, UI_Thread_Params* r0)
{
	UI_Thread_Params sp4;

#if 0
	console_send_string("sub_2343d51e (todo.c): TODO\r\n");
#endif

	if (r2 != 0)
	{
		//0x2343d528
		Menu_Item* pMenuItem = r2->Data_4;

		if (pMenuItem->inputThreadFunc == r0->threadFunc)
		{
			//loc_2343d532
			return 0;
		}
		//loc_2343d538
		else if (pMenuItem->inputThreadFunc == 0)
		{
			//loc_2343d53c
			r0 = &Data_235fdf58;
			//->loc_2343d550
		}
		else
		{
			//loc_2343d542
			if (r0 == 0)
			{
				r0 = &sp4;
			}
			//loc_2343d548
			r0->Data_20 = r0->threadFunc;
			r0->threadFunc = pMenuItem->inputThreadFunc;
			//loc_2343d550
		}
	}
	else
	{
		//loc_2343d53c
		r0 = &Data_235fdf58;
		//->loc_2343d550
	}
	//loc_2343d550
	ui_thread_create(r0);
	//->loc_2343d532
	return 0;
}


/* Get UI Thread Params */
/* 2343d572 - todo */
UI_Thread_Params* sub_2343d572(void)
{
#if 0
	console_send_string("sub_2343d572 (todo.c): TODO\r\n");
#endif

	return Data_235fdf70;
}


/* 2343d610 - todo */
void mainfunction_thread(UI_Thread_Params* a)
{
    int timeout;
	uint8_t err; //sp_0xc;
	Menu_Event sp;
	int r7;
	Menu* r4;
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2

	}* pMsg;

	Menu_Item* r0;

	void (*r4_)(int);
	void (*r5)(int);

#if 0
	console_send_string("mainfunction_thread (thumb.c): entry\r\n");
#endif

	memcpy(&Data_235fdf28, a, sizeof(UI_Thread_Params));

	Data_235fdf70 = &Data_235fdf28/*r4*/;

	OSSemPost(Data_235fdf28.pSema);
	OSMboxAccept(Data_235fdf28.pMBox);

	if (menu_stack_level == 0)
	{
		sub_2346f708();
	}

	while (1)
	{
		//loc_2343d642
		r4 = menu_stack[menu_stack_level];
		if (r4 != 0)
		{
			timeout = r4->timeout;
		}
		else
		{
			//loc_2343d656
			timeout = 0;
		}
		//loc_2343d658
#if 0
		console_send_string("mainfunction_thread (thumb.c): before OSMboxPend\r\n");
#endif
		pMsg = (void*) OSMboxPend(Data_235fdf28.pMBox, timeout, &err);
#if 0
        {
            extern char debug_string[];
            sprintf(debug_string, "mainfunction_thread (thumb.c): after OSMboxPend, sp_0xc=%d\r\n", sp_0xc);
            console_send_string(debug_string);
        }
#endif

		r7 = pMsg->bData_0;

		if (r4 != 0)
		{
			r0 = r4->Data_4;
			r4_ = r0->Data_0x24;
			r5 = r0->Data_0x28;
			//->loc_2343d682
		}
		else
		{
			//loc_2343d67c
			r0 = 0;
			r4_ = 0;
			r5 = 0;
		}
		//loc_2343d682
		if (err != 10)
		{
			//0x2343d68a
			void* r0_;
			void (*r7_)(void*);
#if 1
			{
                extern char debug_string[];
				sprintf(debug_string, "mainfunction_thread: ir key=%d\r\n", r7);
				console_send_string(debug_string);
			}
#endif
			if (menu_stack_level == 0)
			{
				sub_2346f708();

				r0 = menu_stack[menu_stack_level]->Data_4;
			}
			//loc_2343d6a0
			r0_ = r0->onEvent;
			sp.keyCode = r7;
			r7_ = r0_;

			if (r4_ != 0)
			{
				(r4_)(0);
			}
			//loc_2343d6b0
			if (r7_ != 0)
			{
				(r7_)(&sp);
			}
			//loc_2343d6b8
			if (r5 != 0)
			{
				(r5)(0);
			}
			//->loc_2343d6d0
		} //if (err != 10)
		else
		{
			//->loc_2343d6c2
#if 0
			console_send_string("mainfunction_thread (thumb.c): timeout\r\n");
#endif
			if (r0 != 0)
			{
				void (*r1)(int) = r0->onEvent;
				if (r1 != 0)
				{
					(r1)(0);
				}
			}
		}
		//loc_2343d6d0
		if (62 == OSTaskDelReq(0xff))
		{
			OSTaskDel(0xff);
		}
		//->loc_2343d642
	} //while (1)
}


/* 2343d6e2 - todo */
void menu_event_thread(UI_Thread_Params* p)
{
//	Struct_235fdf98* sp_0x28;
	uint8_t err; //sp_0x24
	int navigateVal; //sp_0x20
	UI_Thread_Params sp8; //->sp0x20
	void (*sp4)();
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2

	}* pMsg;
	int r0;
	Menu* pMenu; //r4
	Menu_Item* pMenuItem; //r1
	int (*navigateFunc)(int*) = 0; //r7
	void (*r6)();
	int (*eventHandler)() = 0; //r5

#if 0
	console_send_string("menu_event_thread (todo.c): TODO\r\n");
#endif

	sp8 = *p;

	Data_235fdf70 = &sp8;

	err = OSSemPost(sp8.pSema);
	OSMboxAccept(sp8.pMBox);

//	sp_0x28 = &Data_235fdf98;

	while (1)
	{
		//loc_2343d70e
		int timeout;
		if (menu_stack[ /*sp_0x28->bData_0x10*/menu_stack_level ] != 0)
		{
			//0x2343d71e
			timeout = menu_stack[ /*sp_0x28->bData_0x10*/menu_stack_level ]->timeout;
		}
		else
		{
			timeout = 0;
		}
		//loc_2343d720
		pMsg = (void*) OSMboxPend(sp8.pMBox, (uint16_t)timeout, &err);

		r0 = pMsg->bData_0;

		pMenu = menu_stack[ /*sp_0x28->bData_0x10*/menu_stack_level ];
		pMenuItem = pMenu->Data_4;
		sp4 = pMenuItem->Data_0x24;
		r6 = pMenuItem->Data_0x28;

		if (err == 0)
		{
			//0x2343d746
			switch (r0)
			{
			case 0x21: //Down
			case 0x83:
				//loc_2343d77c
				navigateVal = 2;
				//loc_2343d77e
				navigateFunc = pMenu->onNavigate;
				//->loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
				break;

			case 0x20: //Up
			case 0x82:
				//0x2343d75e -> loc_2343d7d0
				navigateVal = 1;
				//loc_2343d77e
				navigateFunc = pMenu->onNavigate;
				//->loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
				break;

			case 0x2d: //EXIT
			case 0xe0:
				//loc_2343d78e
				if ((pMenu->onExit != 0) && ((pMenu->onExit)(0) != 0))
				{
					//->loc_2343d7d6
					if (sp4 != 0)
					{
						(sp4)(0);
					}
					//loc_2343d7e2
				}
				else
				{
					//loc_2343d79c
					pMenu = sub_2343d482(0);

					if (pMenu != 0)
					{
						sp4 = pMenu->Data_4->Data_0x24;
						r6 = pMenu->Data_4->Data_0x28;

						if (pMenu->onEnter != 0)
						{
							(pMenu->onEnter)(-1);
						}
						//loc_2343d7ba
						sub_2343d51e(pMenu, &sp8);
						//->loc_2343d7d6
						if (sp4 != 0)
						{
							(sp4)(0);
						}
						//loc_2343d7e2
					}
					else
					{
						//loc_2343d7c4
						sub_2343d51e(0, &sp8);
						//loc_2343d7cc
						r6 = 0;
						//->loc_2343d7e2
					}
				}
				break;

			case 0x57: //OK
			case 0xea:
				//0x2343d768 -> loc_2343d7d4
				eventHandler = pMenuItem->onEvent;
				//loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
				break;

			case 0x11: //Left
			case 0x81:
				//loc_2343d820
				navigateVal = 4;
				//loc_2343d77e
				navigateFunc = pMenu->onNavigate;
				//->loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
				break;

			case 0x10: //Right
			case 0x80:
				//loc_2343d824
				navigateVal = 8;
				//loc_2343d77e
				navigateFunc = pMenu->onNavigate;
				//->loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
				break;

			case 0xff:
				//loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
				break;

			default:
				//loc_2343d7cc
				r6 = 0;
				//->loc_2343d7e2
				break;
			} //switch (r0)
			//loc_2343d7e2
			if (eventHandler != 0)
			{
				//0x2343d7e6
				if (0 != (eventHandler)(&sp8))
				{
					//0x2343d7ee
					if ((pMenu->onExit != 0) && ((pMenu->onExit)(0) != 0))
					{
						//->loc_2343d8b0
						return;
					}
					//loc_2343d7fc
					pMenu = sub_2343d482(0);

					if (pMenu != 0)
					{
						r6 = pMenu->Data_4->Data_0x28;

						if (pMenu->onEnter != 0)
						{
							(pMenu->onEnter)(-1);
						}
						//loc_2343d816
						sub_2343d51e(pMenu, &sp8);
						//->loc_2343d834
					}
					else
					{
						//loc_2343d82a
						sub_2343d51e(0, &sp8);

						r6 = 0;
					}
				} //if (0 != (eventHandler)(&sp8))
				//loc_2343d834
				eventHandler = 0;
			} //if (eventHandler != 0)
			//loc_2343d836
			if (navigateFunc != 0)
			{
				(navigateFunc)(&navigateVal);

				err = sub_2343d51e(pMenu, &sp8);

				navigateFunc = 0;
			} //if (navigateFunc != 0)
			//loc_2343d84a
			if (r6 != 0)
			{
				(r6)(0);
			}
			//->loc_2343d89c
		} //if (err == 0)
		else
		{
			//->loc_2343d828 -> loc_2343d854
			if (pMenuItem != 0)
			{
				eventHandler = pMenuItem->onEvent;
				if (eventHandler != 0)
				{
					if (0 != (eventHandler)(0))
					{
						if ((pMenu->onExit != 0) && ((pMenu->onExit)(0) != 0))
						{
							//->loc_2343d8b0
							return;
						}
						//loc_2343d874
						pMenu = sub_2343d482(0);

						if (pMenu != 0)
						{
							if (pMenu->onEnter != 0)
							{
								(pMenu->onEnter)(-1);
							}
							//loc_2343d88a
							sub_2343d51e(pMenu, &sp8);
							//->loc_2343d89a
						}
						else
						{
							//loc_2343d894
							sub_2343d51e(0, &sp8);
						}
					}
					//loc_2343d89a
					eventHandler = 0;
				} //if (eventHandler != 0)
				//loc_2343d89c
			} //if (pMenuItem != 0)
			//loc_2343d89c
		}
		//loc_2343d89c
		if (62 == OSTaskDelReq(0xff))
		{
			//loc_2343d8a8
			OSTaskDel(0xff);
		}
		//->loc_2343d70e
	} //while (1)
	//loc_2343d8b0
	return;
}


/* 2343d8b4 - todo */
void standby_thread(UI_Thread_Params* a)
{
	uint8_t err; //sp_0x5c
#if 0
	Struct_2340bf0c sp_0x28;
	struct Struct_234fd8f0_Inner0 sp;
#endif
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2

	}* pMsg;
	uint8_t r6;

#if 0
	console_send_string("standby_thread (todo.c): TODO\r\n");
#endif

	memcpy(&Data_235fdf40, a, sizeof(UI_Thread_Params));

	Data_235fdf70 = &Data_235fdf40;

	err = OSSemPost(Data_235fdf40.pSema);

	OSMboxAccept(Data_235fdf40.pMBox);

	//r5 = 23493104

	while (1)
	{
		//loc_2343d8dc
#if 0
		console_send_string("standby_thread (thumb.c): before OSMboxPend\r\n");
#endif
		pMsg = (void*) OSMboxPend(Data_235fdf40.pMBox, 0, &err);
#if 0
		console_send_string("standby_thread (thumb.c): after OSMboxPend\r\n");
#endif

		r6 = pMsg->bData_0;

		if (err != 0)
		{
			sub_23439624(0, 0, 20, 0);
		}
		//loc_2343d8fc
		//r3 = r6
		switch (r6)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 12: //OnOff
		case 32/*0x20*/:
		case 33/*0x21*/:
		case 0x30:
		case 0x31:
		case 0x57:
		case 0x82:
		case 0x83:
		case 0xe1:
		case 0xe2:
		case 0xe3:
		case 0xe4:
			//loc_2343d948
			if (Data_23493104 != 0)
			{
				(Data_23493104)(&Data_235fdf40);

				Data_23493104 = 0;
				//->loc_2343d97c
			}
			else
			{
				//loc_2343d95a
				if (0 == powermode_set_state(1/*On*/, &Data_235fdf40, mainfunction_thread))
				{
#if 0
					sub_2340bf0c(&sp_0x28);

					channel_start_number(&sp, sp_0x28.wData_0x2a, sp_0x28.wData_0x2a);
#endif
				}
				//loc_2343d97c
			}
			break;

		default:
			//loc_2343d97c
			break;
		}
		//loc_2343d97c
		if (62 == OSTaskDelReq(0xff))
		{
			OSTaskDel(0xff);
		}
		//->loc_2343d8dc
	} //while (1)
}


