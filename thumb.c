
#include "data.h"
#include "frontdisplay.h"
#include "texttable.h"
#include "graphic.h"
#include "menu.h"
#include "amplifier.h"

#ifndef VDR110
//#include "menu_info_bar.h"
#include "osd_list.h"
#endif

#pragma thumb

extern int menu_channel_search_entry(UI_Thread_Params*);
extern int sub_23471600(UI_Thread_Params*);
extern int menu_network_on_entry(UI_Thread_Params*);
extern int sub_2343d1ca(UI_Thread_Params*);
extern int menu_information_entry(UI_Thread_Params*);
extern int menu_sw_update_entry(UI_Thread_Params*);

extern int menu_main_on_enter(int);
extern int menu_main_on_exit(UI_Thread_Params*);
extern int menu_items_navigate(int*);

OS_EVENT* Data_23492f94 = 0; //23492f94

Menu_Item menu_main_items[7] = //23492f98 +4
{
	//[0]
	{
		80, //"Allgemein"
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		menu_general_settings_entry, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23492fc4
	},
	//[1]
	{
		11, //"Sendersuche"
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0/*menu_channel_search_entry*/, //void* Data_0x1c; //0x1c = 28
		menu_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 23492FF0
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
	},
	//[5]
	{
		63, //"information"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		menu_information_entry,
		menu_event_thread,
		0,
		0
		//0x234930a0
	},
	//[6]
	{
		458, //"Software-Update"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		menu_sw_update_entry,
		menu_event_thread,
		0,
		0
		//0x234930cc
	}
};

Menu menuMain = //234930cc
{
		10, //"Hauptmenu"
		&menu_main_items[0], //Menu_Item* Data_4; //4
		&menu_main_items[0], //Menu_Item* Data_8; //8
		0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
		0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
		0, //int Data_0x14; //20 = 0x14
		6, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		0, //void (*Data_0x1c)(); //0x1c
		menu_items_navigate, //int (*onNavigate)(int*); //0x20
		menu_main_on_enter, //int (*onEnter)(int); //36 = 0x24
		menu_main_on_exit, //int (*onExit)(UI_Thread_Params*); //0x28
		0, //int Data_0x2c; //44 = 0x2c
		0, //int timeout; //48
		0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
		//0x38 = 56?
}; //23493104

void (*Data_23493104)(UI_Thread_Params*) = 0; //23493104

#ifndef VDR110
UI_Thread_Params Data_2379673c; //  / 2379673C
#endif
UI_Thread_Params Data_235fdf28; //235fdf28 235fdf98 / 23796754 -0x70
UI_Thread_Params Data_235fdf40; //235fdf40 235fdf58 / 2379676C - 0x18

#if 0
UI_Thread_Params Data_235fdf58; //0 235fdf58 235fdf98 -0x40
UI_Thread_Params* Data_235fdf70; //24 235fdf70 / 2378336C -0x40 + 0x18
Menu* menu_stack[13]; //28 235fdf74 -0x40 + 0x1c, size???
uint8_t menu_stack_level; //80 235fdfa8 235fdf98 + 0x10
uint8_t bData_235fdfa9; //81 235fdfa9
#else
struct Menu_Data Menu_Data; //235fdf58 / 23796784 -0x40
#endif


#ifndef VDR110
void sub_2344d850(Menu_Item*, uint16_t, uint8_t, uint8_t);

//0x234c21c4
void (*Data_234c21c8)() = sub_2344d850; //234c21c8 +4
void (*Data_234c21cc)() = 0; //234C21CC +8
void (*Data_234c21d4)() = 0; //234c21d4 +0x10
void (*Data_234c21d8)() = 0; //234C21D8 +0x14
#endif


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
int menu_main_on_exit(UI_Thread_Params* a)
{
#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "menu_main_on_exit: a=%p\r\n", a);
        console_send_string(debug_string);
    }
#endif

	sub_23410f28(1);

	return 0;
}


/* 2343d1d6 - todo */
int menu_main_start(void)
{
	UI_Thread_Params* r4;

#if 1
	console_send_string("menu_main_start (todo.c): TODO\r\n");
#endif

	r4 = sub_2343d572(); //Get the current UI thread params

	menu_stack_operate(&menuMain); //Add to the menu stack
	menu_initialize(&menuMain); //Initialize the menu
	sub_2343d51e(&menuMain, r4); //Backup UI thread params?

	return 0;
}


/* 2343d1f6 - todo */
void menu_main_adapt_items(int (*p)(Amplifier_Interface_Functions*, int, int, int))
{
	Amplifier_Interface_Functions sp;
	uint8_t r5 = 0;
	uint8_t r4;

	Data_23492f94 = OSSemCreate(1);

#if 1
	console_send_string("menu_main_adapt_items (todo.c): TODO\r\n");
#endif

	if (p != 0)
	{
		//Check Amplifier
		if (0 == (p)(&sp, 0, 0, 0))
		{
			sub_2346fa58(p);

#if 0	
			sub_23471658(p);

			sub_234709f2(sp.Data_235fc458);
#endif
			//->loc_2343d230
		}
		else
		{
			//loc_2343d22e
			r5 = 1;
		}
	}
	else
	{
		//loc_2343d22e
		r5 = 1;
	}
	//loc_2343d230
	//r6, =234930cc
	if (0 == network_get_device())
	{
		r5++; //Skip "Netzwerk" at [3]
	}
	//loc_2343d23e
	//r7 = 23492f94+4
	//->loc_2343d268
	while (r5--)
	{
		//loc_2343d244
		for (r4 = 2; r4 < menuMain.maxItem; r4++)
		{
			//loc_2343d248
			memcpy(&menu_main_items[r4], &menu_main_items[r4+1], sizeof(Menu_Item));
		}
		//0x2343d262
		menuMain.maxItem--;
	}
	//0x2343d272
	return;
}

#ifndef VDR110

/*  /  / 2344d850 - complete */
void sub_2344d850(Menu_Item* pMenuItem, uint16_t r1, uint8_t r2, uint8_t index)
{
#if 0
	console_send_string("sub_2344d850 (todo.c): TODO\r\n");
#endif

	Menu_Item_Inner4_Data_0* r4;

	do
	{
		r4 = pMenuItem->Data_4[index];
		if (r4 == 0)
		{
			break;
		}
		index++;

		r4->wData_0x1c = r1;
		r4->bData_0x3c = r2;

		r4 = pMenuItem->Data_4[index];
	}
	while (r4 != 0);
}

#endif //VDR110


/* 2343d3ac /  / 2344da42 - complete */
void menu_initialize(Menu* pMenu)
{
	Graphic_Queue_Item graphicQueueItem; //sp_0x40
	struct
	{
		int fill[13]; //0
		//???
	} sp_0xc;

	Menu_Item* pMenuItem;

#if 0
	console_send_string("menu_initialize (todo.c): TODO\r\n");
#endif

	if (pMenu->onEnter != 0)
	{
		(pMenu->onEnter)(0);
	}
	//loc_2343d3bc: Get the string of the menu header, if available
	//r6 = 0xffff;
	if ((pMenu->header != 0) && (pMenu->header->Data_0x20 != 0)
			&& (pMenu->stringId != 0xffff/*r6*/))
	{
		text_table_get_string(pMenu->stringId, pMenu->header->Data_0x20->pString, 36);
	}
	//loc_2343d3d8
	pMenuItem = pMenu->Data_8;
	if (/*pMenu->Data_8*/pMenuItem != 0)
	{
		if (pMenu->Data_0x34 != 0)
		{
			pMenuItem = (pMenu->Data_0x34)(pMenu);
			//->loc_2343d40a
		}
		else
		{
#ifndef VDR110
			//loc_2344da82
			Data_234c21c8 = sub_2344d850;

			uint8_t r6 = pMenu->maxItem;
			do
			{
				//loc_2344da8a
				sub_2344d850(pMenuItem, 9, 1, 0);

				// Get the string of the menu item caption (column 1), if available
				if ((pMenuItem->Data_4[0] != 0) &&
						(pMenuItem->Data_4[0]->Data_0x20 != 0) &&
						(pMenuItem->wData_0 != 0xffff))
				{
					//0x2344daa8
					text_table_get_string(pMenuItem->wData_0,
							pMenuItem->Data_4[0]->Data_0x20->pString, 36);
				}
				//loc_2344dab0: Get the string of the menu item value (column 2), if available
				if (pMenuItem->initValueString != 0)
				{
					(pMenuItem->initValueString)(pMenuItem);
				}
				//loc_2344daba
				pMenuItem++;
			}
			while (r6--);
			//0x2344dac6
#endif
			//loc_2343d3ec
			if (pMenu->Data_0x2c == 0)
			{
				pMenu->currentItem = 0;
			}
			//loc_2343d3f4
			pMenuItem = &pMenu->Data_8[pMenu->currentItem];

			pMenu->Data_4 = pMenuItem;

#ifdef VDR110
			if (pMenuItem->initValueString != 0)
			{
				(pMenuItem->initValueString)(pMenuItem);
			}
			//loc_2343d40a
#else
			sub_2344d850(pMenuItem, 10, 1, 0);
#endif
		}
		//loc_2343d40a: Initialize the help for this menu based on the current menu item
		if ((pMenu->help != 0) && (pMenu->help->Data_0x20 != 0))
		{
			if (pMenuItem->helpStringId != 0xffff/*r6*/)
			{
				//0x2343d41c
				text_table_get_string(pMenuItem->helpStringId, pMenu->help->Data_0x20->pString, 244);

				Graphic_Job_2_5_Item_Text* r5_ = pMenu->help->Data_0x20;

				sub_234089e8(&sp_0xc, r5_->pString, r5_->bData_0xd,
						r5_->x1, r5_->y1, r5_->x2, 4);
				//->loc_2343d448
			}
			else
			{
				//loc_2343d440: No help available
				memset(pMenu->help->Data_0x20->pString, 0, 243);
			}
		}
		//loc_2343d448
		if (pMenu->graphicHandler != 0)
		{
			(pMenu->graphicHandler)(&graphicQueueItem, pMenu->graphicData);
		}
	} //if (pMenu->Data_8 != 0)
	//loc_2343d454
	return;
}


/* 2343d458 /  / 2344db36 - todo */
void sub_2343d458(UI_Thread_Params* a)
{
	memcpy(&Menu_Data.Data_235fdf58, a, sizeof(UI_Thread_Params));
}


/* 2343d470 /  / 2344db54 - todo */
Menu* sub_2344db54(void)
{
	return Menu_Data.menu_stack[ Menu_Data.menu_stack_level ];
}


/* 2343d482 /  / 2344db72 - todo */
Menu* menu_stack_operate(Menu* r4)
{
	Menu* r0_;
	Menu** r0 = &Menu_Data.menu_stack[Menu_Data.menu_stack_level];

	if (r4 != 0)
	{
		r0_ = *r0;

		Menu_Data.menu_stack_level++;
		if (Menu_Data.menu_stack_level < 13)
		{
			Menu_Data.menu_stack[Menu_Data.menu_stack_level] = r4;
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

		if (Menu_Data.menu_stack_level != 0)
		{
			Menu_Data.menu_stack_level--;
		}
		//loc_2343d4be
		return Menu_Data.menu_stack[Menu_Data.menu_stack_level];
	}
}


/* 2343d4c8 /  / 2344dbb8 - todo */
int menu_items_navigate(int* a)
{
#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "menu_items_navigate: *a=%d\r\n", *a);
        console_send_string(debug_string);
    }
#endif

#ifdef VDR110
	Menu* pMenu;
	int handled = 0;

	pMenu = Menu_Data.menu_stack[Menu_Data.menu_stack_level];

	if (*a == 2) //Down
	{
		pMenu->currentItem--;
		if (pMenu->currentItem < 0)
		{
			pMenu->currentItem = pMenu->maxItem;
		}
		//loc_2343d504
		handled = 1;
	}
	//loc_2343d4ee
	else if (*a == 1) //Up
	{
		pMenu->currentItem++;
		if (pMenu->currentItem > pMenu->maxItem)
		{
			pMenu->currentItem = 0;
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
			sprintf(debug_string, "menu_items_navigate: currentItem=%d\r\n", pMenu->currentItem);
			console_send_string(debug_string);
		}
#endif

		pMenu->Data_4 = &pMenu->Data_8[pMenu->currentItem];

		if (pMenu->Data_4->initValueString != 0)
		{
			(pMenu->Data_4->initValueString)(pMenu->Data_4);
		}
	}
	//loc_2343d51a
#else //VDR110
	Menu* pMenu;
	int r5 = *a;
	struct
	{
		int fill_0[13]; //0
		//0x34 = 52
	} sp_0x10;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "menu_items_navigate: r5=%d\r\n", r5);
		console_send_string(debug_string);
	}
#endif

	pMenu = Menu_Data.menu_stack[Menu_Data.menu_stack_level];

	sub_2344d850(pMenu->Data_4, 9, 1, 0);

	if (r5 == 1)
	{
		//0x2344dbdc
		while (1)
		{
			//loc_2344dbde
			pMenu->currentItem--;
			if (pMenu->currentItem < 0)
			{
				//0x2344dbea
				pMenu->currentItem = pMenu->maxItem;
			}
			//loc_2344dbee
			if (pMenu->Data_8[pMenu->currentItem].Data_4[0]->bData_0 == 1)
			{
				//->0x2344dc00 -> loc_2344dc28
				break;
			}
		}
		//0x2344dc00 -> loc_2344dc28
	}
	else
	{
		//loc_2344dc02
		while (1)
		{
			//loc_2344dc08
			pMenu->currentItem++;
			if (pMenu->currentItem > pMenu->maxItem)
			{
				//0x2344dc14
				pMenu->currentItem = 0;
			}
			//loc_2344dc16
			if (pMenu->Data_8[pMenu->currentItem].Data_4[0]->bData_0 == 1)
			{
				//->loc_2344dc28
				break;
			}
		}
	}
	//loc_2344dc28
	Menu_Item* pMenuItem = &pMenu->Data_8[pMenu->currentItem];

	pMenu->Data_4 = pMenuItem;

	sub_2344d850(pMenuItem, 10, 1, 0);

	if (pMenu->help != 0)
	{
		//0x2344dc48
		if (pMenuItem->helpStringId != 0xffff)
		{
			//0x2344dc50
			text_table_get_string(pMenuItem->helpStringId, pMenu->help->Data_0x20->pString, 244);

			Graphic_Job_2_5_Item_Text* r5__ = pMenu->help->Data_0x20;

			sub_234089e8(&sp_0x10,
					r5__->pString,
					r5__->bData_0xd,
					r5__->x1,
					r5__->y1,
					r5__->x2,
					4);
			//->loc_2344dca4
		}
		else
		{
			//loc_2344dc9a
			memset(pMenu->help->Data_0x20->pString, 0, 248);
		}
		//loc_2344dca4
		pMenu->help->Data_0x20->bData_0x17 = 1;
	}
	//loc_2344dcac
#endif

	return 0;
}


/* 2343d51e /  / 2344de56 - todo */
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

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2343d51e: pMenuItem->inputThreadFunc=%p, r0->threadFunc=%p\r\n", 
				pMenuItem->inputThreadFunc, r0->threadFunc);
			console_send_string(debug_string);
		}
#endif

		if (pMenuItem->inputThreadFunc == r0->threadFunc)
		{
			//loc_2343d532
			return 0;
		}
		//loc_2343d538
		else if (pMenuItem->inputThreadFunc == 0)
		{
			//loc_2343d53c
			r0 = &Menu_Data.Data_235fdf58;
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
		r0 = &Menu_Data.Data_235fdf58;
		//->loc_2343d550
	}
	//loc_2343d550
	ui_thread_create(r0);
	//->loc_2343d532
	return 0;
}


/* 2343d556 / 2344c756 / 2344dd86 - todo */
void sub_2343d556(void* pMsg)
{
#if 0
	console_send_string("sub_2343d556 (todo.c): TODO\r\n");
#endif

	OSMboxAccept(Menu_Data.Data_235fdf70->pMBox);

	OSMboxPost(Menu_Data.Data_235fdf70->pMBox, pMsg);
}


/* Get UI Thread Params */
/* 2343d572 /  / 2344dda2 - todo */
UI_Thread_Params* sub_2343d572(void)
{
#if 0
	console_send_string("sub_2343d572 (todo.c): TODO\r\n");
#endif

	return Menu_Data.Data_235fdf70;
}


/* 2343d57a /  / 2344de8e - todo */
struct Menu_Data* sub_2344de8e(void)
{
#if 0
	console_send_string("sub_2344de8e (todo.c): TODO\r\n");
#endif

	return &Menu_Data;
}


/* /  / 2344de94 */
int sub_2344de94(void)
{
	return Menu_Data.menu_stack_level;
}


/* 2343d580 - todo */
int sub_2343d580()
{
#if 1
	console_send_string("sub_2343d580 (todo.c): TODO\r\n");
#endif

}


#ifndef VDR110

/*  /  / 2344e40a - todo */
void sub_2344e40a(UI_Thread_Params* a)
{
#if 1
	console_send_string("sub_2344e40a (inputThreadFunc): TODO\r\n");
#endif

//	Menu** sp_0x20; //sp_0x20
	uint8_t sp_0x1c; //sp_0x1c
	Graphic_Queue_Item sp_0xc; //sp_0xc
	Menu* r4;
	int (*r6)(Graphic_Queue_Item *, void *) = 0;
	void (*r5)() = 0;
	uint8_t (*r7)() = 0;
	int sp8; //sp8
	Menu_Item* sp4; //sp4
	uint8_t (*sp)() = 0;

	Data_2379673c = *a;

	Menu_Data.Data_235fdf70/*2379679C*/ = &Data_2379673c; //r4

	sp_0x1c = OSSemPost(Data_2379673c.pSema);

	OSMboxAccept(Data_2379673c.pMBox);

//	sp_0x20 = &Menu_Data.menu_stack[9]/*237967C4*/;

	while (1)
	{
		//loc_2344e43e
		r4 = Menu_Data.menu_stack[ Menu_Data.menu_stack_level ];
		sp4 = r4->Data_4;

		uint8_t* r0_ = OSMboxPend(Data_2379673c.pMBox, (uint16_t)r4->timeout, &sp_0x1c);

		uint8_t keyCode = *r0_;

		if (sp_0x1c != 10)
		{
			//0x2344e468
#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_2344e40a (thumb.c): keyCode=0x%x\r\n", keyCode);
				console_send_string(debug_string);
			}
#endif
			switch (keyCode)
			{
				case 0x34:
					//loc_2344e4e2
					break;

				case 0x11:
					//loc_2344e598 -> loc_2344e5ce
					//r0 = 8;
					//->loc_2344e5d4
					sp8 = 8;
					r5 = sp4->onEvent;
					r6 = r4->graphicHandler;
					//->loc_2344e622
					break;

				case 0x10:
					//loc_2344e55a -> loc_2344e5d2
					//r0 = 4;
					//loc_2344e5d4
					sp8 = 4;
					r5 = sp4->onEvent;
					r6 = r4->graphicHandler;
					//->loc_2344e622
					break;

				case 0x20:
					//loc_2344e59a
					break;

				case 0x21:
					//0x2344e4a2
					break;

				case 0x2c:
					//loc_2344e57e
					break;

				case 0x22:
					//loc_2344e57e
					break;

				default:
					//loc_2344e59c -> loc_2344e622???
					break;
			} //switch (keyCode)
			//loc_2344e622
			if (r7 != 0)
			{
				//0x2344e626
				sp_0x1c = (r7)();
			}
			//loc_2344e62a
			if (r5 != 0)
			{
				//0x2344e62e
				(r5)(&sp8);

				r5 = 0;
			}
			//loc_2344e634
			if (r6 != 0)
			{
				//0x2344e638
				(r6)(&sp_0xc, r4->graphicData);

				r6 = 0;
			}
			//loc_2344e640
			if (sp != 0)
			{
				//0x2344e646
				sp_0x1c = (sp)();
			}
			//->loc_2344e65e
		} //if (sp_0x1c != 10)
		else
		{
			//loc_2344e540 -> loc_2344e64c
			if (sp4 != 0)
			{
				//0x2344e652
				r5 = sp4->onEvent;
				if (r5 != 0)
				{
					(r5)(0);

					r5 = 0;
				}
			}
			//loc_2344e65e
		}
		//loc_2344e65e
		if (62 == OSTaskDelReq(0xff))
		{
			OSTaskDel(0xff);
		}
		//->loc_2344e43e
	} //while (1)
}

#endif //!VDR110


/* 2343d610 /  / 2344e6a2 - todo */
void mainfunction_thread(UI_Thread_Params* a)
{
#ifndef VDR110
	int sp_0x70 = 1; //  sp_0x70
#endif
    int timeout;
	uint8_t ir_key; //  / sp_0x6c
	uint8_t err; //sp_0xc / 0x68
	Menu_Event menuEvent; //sp / sp_0x5c
	Menu* pMenu; //r4
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2

	}* pMsg;

	Menu_Item* pMenuItem; //r0 / r6

#ifdef VDR110
	void (*r4_)(int);
	void (*r5)(int);
#else
	Graphic_Queue_Item sp_0x4c; //sp_0x4c +0x10 = sp_0x5c
	Struct_2348dc50* sp_0x48; //sp_0x48
	void (*r7)() = 0; //  / r7
	int sp_0x10 = 0; //  / sp_0x10
	int (*sp_0xc)(Graphic_Queue_Item *, void *) = 0; //  / sp_0xc
	void (*sp8)(); //  / sp8
	void (*sp4)(); //  / sp4
#endif

#if 0
	console_send_string("mainfunction_thread (thumb.c): entry\r\n");
#endif

#ifdef VDR110
	memcpy(&Data_235fdf28, a, sizeof(UI_Thread_Params));

	Menu_Data.Data_235fdf70 = &Data_235fdf28/*r4*/;

	OSSemPost(Data_235fdf28.pSema);
	OSMboxAccept(Data_235fdf28.pMBox);
#else
	memcpy(&Data_235fdf40, a, sizeof(UI_Thread_Params));

	Menu_Data.Data_235fdf70 = &Data_235fdf40/*r4*/;

	OSSemPost(Data_235fdf40.pSema);
	OSMboxAccept(Data_235fdf40.pMBox);
#endif

	//r5 = 23796794;

#ifdef VDR110
	if (Menu_Data.menu_stack_level == 0)
	{
		menu_root_start();
	}
#endif

	while (1)
	{
		//loc_2343d642 / 2344e6d6
		pMenu = Menu_Data.menu_stack[Menu_Data.menu_stack_level];
		if (pMenu != 0)
		{
			timeout = pMenu->timeout;
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

#ifdef VDR110
		pMsg = (void*) OSMboxPend(Data_235fdf28.pMBox, timeout, &err);
#else
		pMsg = (void*) OSMboxPend(Data_235fdf40.pMBox, timeout, &err);
#endif

#if 0
        {
            extern char debug_string[];
            sprintf(debug_string, "mainfunction_thread (thumb.c): after OSMboxPend, err=%d\r\n", err);
            console_send_string(debug_string);
        }
#endif

		ir_key = pMsg->bData_0;

#ifndef VDR110
		sp_0x48 = sub_2348dcd2();
#endif

		if (pMenu != 0)
		{
#ifdef VDR110
			pMenuItem = pMenu->Data_4;
			r4_ = pMenuItem->Data_0x24;
			r5 = pMenuItem->Data_0x28;
#else
			pMenuItem = pMenu->Data_4;
			sp8 = pMenu->graphicData->lock;
			sp4 = pMenu->graphicData->unlock;
#endif
			//->loc_2343d682 / 0x2344e72e
		}
		else
		{
#ifdef VDR110
			//loc_2343d67c
			pMenuItem = 0;
			r4_ = 0;
			r5 = 0;
#else
			//0x2344e728
			pMenuItem = 0;
			sp8 = 0;
			sp4 = 0;
#endif
		}
		//loc_2343d682 / 0x2344e72e
		if (err != 10)
		{
			//0x2343d68a / 0x2344e736
#if 1
			{
                extern char debug_string[];
				sprintf(debug_string, "mainfunction_thread: ir key=%d\r\n", ir_key);
				console_send_string(debug_string);
			}
#endif

#ifndef VDR110
			sp_0x70 = 1;
#if 0 //TODO!!!

			if (0 != sub_2345a4e6(1))
			{
				//0x2344e742
				switch (ir_key)
				{
				case 12:
					//0x2344e770
					onoff_set_state(6, &Menu_Data_Threads.Data_235fdf28, standby_thread);
					//->0x2344ee44
					break;

				case 16:
				case 17:
				case 32:
				case 33:
				case 48:
				case 49:
				case 53:
				case 87:
					//0x2344e76c
					//r1 = 0x13
					//->0x2344edb6
					sub_234546b8(&Menu_Data_Threads.Data_235fdf28, 0x13);
					//->0x2344ee44
					break;

				default:
					//0x2344e77c -> 0x2344ee44
					break;
				}
			}
			else
#endif //TODO
			{
				//0x2344e77e
				switch (ir_key)
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
					//2344E8F8???
					if (Menu_Data.menu_stack_level == 0)
					{
						//0x2344e8fe
						menu_info_bar_enter();

						pMenu = Menu_Data.menu_stack[Menu_Data.menu_stack_level];
						pMenuItem = pMenu->Data_4;

						sp_0x48 = sub_2348dcd2();
					}
					//0x2344e916
					//r0, #0x40
					//->0x2344ec7c
					sp_0x48->Data_0 = 0x40;
					menuEvent.Data_0 = 0x40; //r0
					menuEvent.Data_8 = sp_0x48; 
					menuEvent.keyCode = ir_key;
					//0x2344ec8c
					r7 = pMenuItem->onEvent;
					sp_0xc = pMenu->graphicHandler;
					//->2344ee44
					break;

#if 0 //TODO!!!
				case 10:
				case 11:
					//2344E7FC??? -> 0x2344ee44
					break;

				case 12:
					//2344E97A??? -> 2344eb94
					if (0 != sub_2345a4e6(0))
					{
						//0x2344eb9e
						//TODO!!!
					}
					//loc_2344ebd4
					//TODO!!!
					break;

				case 13:
					//2344E978???
					//TODO!!!
					break;
#endif //TODO

				case 16:
					//2344E878???
					//break;
				case 17:
					//0x2344e878 -> 0x2344ea6e
					//TODO
					//->0x2344eab4
					if (Menu_Data.menu_stack_level != 0)
					{
						//0x2344eab8
						if (pMenu->onExit != 0)
						{
							//0x2344eabe
							(pMenu->onExit)(&Data_235fdf40);
						}
						//0x2344eac4
						pMenu = MENU_STACK_POP();
					}
					//0x2344eacc
					menu_volume_bar_entry(&Data_235fdf40);
					//->0x2344ee44
					break;

#if 0 //TODO
				case 65: //VOL-
					//2344E788 -> 2344E878
					{
						int r0 = sub_23451f66();
						//TODO!!!
					}
					break;
#endif //TODO

				case 32: //0x20 = Up
					//2344E99C???
					{
						int r0 = sub_23451f66();
						//TODO!!!
						channel_next();
						//->0x2344e990
						if (Menu_Data.menu_stack_level == 0)
						{
							//0x2344e996
							menu_info_bar_enter();
						}
						//2344e99a -> 2344edee
						sub_2348d660(1);
						//->0x2344ee44
					}
					break;

				case 33: //Down
					//2344E98C??? -> 2344e9e4
					{
						int r0 = sub_23451f66();
						//TODO

						//0x2344ea1a
						channel_prev();
						//->0x2344e990
						if (Menu_Data.menu_stack_level == 0)
						{
							//0x2344e996
							menu_info_bar_enter();
						}
						//2344e99a -> 2344edee
						sub_2348d660(1);
						//->0x2344ee44
					}
					break;

				case 34: // <->
					//2344E98A??? -> 2344ea20
					channel_swap();
					//->0x2344e990
					if (Menu_Data.menu_stack_level == 0)
					{
						//0x2344e996
						menu_info_bar_enter();
					}
					//2344e99a -> 2344edee
					sub_2348d660(1);
					//->0x2344ee44
					break;

#if 0 //TODO!!!
				case 35:
					//2344E988??? -> 0x2344ed36
					//TODO!!!
					break;

				case 36:
					//2344E7FC??? -> 0x2344ee44
					break;

				case 42:
					//2344E986??? -> 0x2344ea4a
					//TODO!!!
					break;
#endif //TODO

				case 44: //Info / EPG
				case 47: // I / i (Displaytext aktualisieren)
					//2344E984??? -> 0x2344eb84
					if (Menu_Data.menu_stack_level == 0)
					{
						//0x2344eb8a
						sub_23456ed0(&Data_235fdf40);
						//->0x2344ee44
					}
					//0x2344eab2 -> 0x2344ee44
					break;

#if 0 //TODO
				case 45:
					//2344E91A???
					//TODO!!!
					break;
#endif //TODO

				case 48: //CH+
					//2344E982??? -> 0x2344e9de
					channel_next();
					//->0x2344e990
					if (Menu_Data.menu_stack_level == 0)
					{
						//0x2344e996
						menu_info_bar_enter();
					}
					//2344e99a -> 2344edee
					sub_2348d660(1);
					//->0x2344ee44
					break;

				case 49: //CH-
					//2344E980??? -> 0x2344ea1a
					channel_prev();
					//->0x2344e990
					if (Menu_Data.menu_stack_level == 0)
					{
						//0x2344e996
						menu_info_bar_enter();
					}
					//2344e99a -> 2344edee
					sub_2348d660(1);
					//->0x2344ee44
					break;

#if 0 //TODO
				case 50:
					//2344E97E??? -> 2344ead6
					//TODO!!!
					break;

				case 52: //BT (VT8500: Blue)
					//2344E97C??? -> 2344eb5a
					//TODO!!!
					break;

				case 53: //0x35
					//0x2344e876 -> 0x2344ed86
					sub_23451e6a(1);
					//->0x2344ed94
					//TODO!!!
					break;
#endif //TODO

				case 82: //Menu
					//0x2344e806
					sub_2344d414(&Data_235fdf40);
					//->0x2344ee44
					break;

#if 0 //TOOD
				case 83:
					//0x2344e8bc -> 0x2344edce
					//TODO!!!
					break;
#endif //TODO

				case 69: //0x45 //Radio
					//0x2344e7f0
					if (0 == channel_switch_lists())
					{
						channel_switch_lists();
						//2344ee44
					}
					//2344e8f0 -> 2344e990
					if (Menu_Data.menu_stack_level == 0)
					{
						//0x2344e996
						menu_info_bar_enter();
					}
					//2344e99a -> 2344edee
					sub_2348d660(1);
					//->0x2344ee44
					break;

				case 87: //OK
				case 0xf7:
					//0x2344e8c8
					if (Menu_Data.menu_stack_level == 0)
					{
						menu_info_bar_enter();
						sub_2348d660(1);

						pMenu = Menu_Data.menu_stack[Menu_Data.menu_stack_level];
						pMenuItem = pMenu->Data_4;

						sp_0x48 = sub_2348dcd2();						
					}
					//0x2344e8ec
					//r0, #0x20
					//->0x2344ec7c
					sp_0x48->Data_0 = 0x20; //r0;
					menuEvent.Data_0 = 0x20; //r0
					menuEvent.Data_8 = sp_0x48; 
					menuEvent.keyCode = ir_key;
					//0x2344ec8c
					r7 = pMenuItem->onEvent;
					sp_0xc = pMenu->graphicHandler;
					//->2344ee44
					break;
				} //switch
			}
#endif

#ifdef VDR110
			if (Menu_Data.menu_stack_level == 0)
			{
				menu_root_start();

				pMenuItem = Menu_Data.menu_stack[Menu_Data.menu_stack_level]->Data_4;
			}
			//loc_2343d6a0
			void* r0_;
			void (*r7_)(void*);

			r0_ = pMenuItem->onEvent;
			menuEvent.keyCode = ir_key;
			r7_ = r0_;
#endif

#ifndef VDR110
			//0x2344ee44
#if 0 //TODO!!!
			if (sp8 != 0)
			{
#if 1
				{
					extern char debug_string[];
					sprintf(debug_string, "mainfunction_thread: sp8=0x%x\r\n", sp8);
					console_send_string(debug_string);
				}
#endif
				err = (sp8)();
			}
#endif //TODO!!!
			//0x2344ee4e
			if (r7 != 0)
			{
#if 1
				{
					extern char debug_string[];
					sprintf(debug_string, "mainfunction_thread: r7=0x%x\r\n", r7);
					console_send_string(debug_string);
				}
#endif
				(r7)(&menuEvent);

				r7 = 0;
			}
			//0x2344ee58
#if 0 //TODO!!!
			if (sp_0x10 != 0)
			{
#if 1
				{
					extern char debug_string[];
					sprintf(debug_string, "mainfunction_thread: sp_0x10=0x%x\r\n", sp_0x10);
					console_send_string(debug_string);
				}
#endif
				(sp_0x10)(sp_0x48);

				sp_0x10 = 0;
			}
#endif //TODO!!!
			//0x2344ee68
			if (sp_0xc != 0)
			{
#if 1
				{
					extern char debug_string[];
					sprintf(debug_string, "mainfunction_thread: sp_0xc=0x%x\r\n", sp_0xc);
					console_send_string(debug_string);
				}
#endif
				(sp_0xc)(&sp_0x4c, pMenu->graphicData);
			}
			//0x2344ee7a
#if 0 //TODO!!!
			if (sp4 != 0)
			{
#if 1
				{
					extern char debug_string[];
					sprintf(debug_string, "mainfunction_thread: sp4=0x%x\r\n", sp4);
					console_send_string(debug_string);
				}
#endif
				(sp4)();

				err = 0;
			}
			//->0x2344ef02
#endif //TODO
#endif

#ifdef VDR110
			if (r4_ != 0)
			{
				(r4_)(0);
			}
			//loc_2343d6b0
			if (r7_ != 0)
			{
				(r7_)(&menuEvent);
			}
			//loc_2343d6b8
			if (r5 != 0)
			{
				(r5)(0);
			}
			//->loc_2343d6d0
#endif
		} //if (err != 10)
		else
		{
			//->loc_2343d6c2 / 0x2344e834 -> 0x2344eece
#if 0
			console_send_string("mainfunction_thread (thumb.c): timeout\r\n");
#endif

#ifdef VDR110
			if (pMenuItem != 0)
			{
				void (*r1)(int) = pMenuItem->onEvent;
				if (r1 != 0)
				{
					(r1)(0);
				}
			}
#else
			if (pMenuItem != 0)
			{
				// / 0x2344eed2
				r7 = pMenuItem->onEvent;
				if (r7 != 0)
				{
					(r7)(0);
				}
				//  / 0x2344eeea
			}
			else
			{
				//0x2344eee0
				if (Data_234c21d8 != 0)
				{
					(Data_234c21d8)();
				}
				//2344eeea
			}
			//0x2344eeea
			if (Data_234c21cc != 0)
			{
				//0x2344eef2
				(Data_234c21cc)(sp_0x70);

				sp_0x70 = 0;
			}
			//0x2344eefa
			if (Data_234c21d4 != 0)
			{
				(Data_234c21d4)();
			}
			//0x2344ef02
#endif
		}
		//loc_2343d6d0 / 0x2344ef02
		if (62 == OSTaskDelReq(0xff))
		{
			OSTaskDel(0xff);
		}
		//->loc_2343d642
	} //while (1)
}


/* 2343d6e2 /   / 2344e2a6 - todo */
void menu_event_thread(UI_Thread_Params* p)
{
//	Struct_235fdf98* sp_0x28;
	uint8_t err; //sp_0x24 / / sp_0x34
	int navigateVal; //sp_0x20 /  / sp_0x30
#ifndef VDR110
	Graphic_Queue_Item graphicQueueItem; //sp_0x20;
#endif
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
	int (*navigateFunc)(int*) = 0; //r7 /  / sp4
	void (*r6)();
	int (*eventHandler)() = 0; //r5

#if 0
	console_send_string("menu_event_thread (todo.c): TODO\r\n");
#endif

	sp8 = *p;

	Menu_Data.Data_235fdf70 = &sp8;

	err = OSSemPost(sp8.pSema);

#ifndef VDR110
	int (*pfGraphicHandler)(Graphic_Queue_Item *, void *) = 0; //r6
#endif

	OSMboxAccept(sp8.pMBox);

//	sp_0x28 = &Data_235fdf98;

	while (1)
	{
		//loc_2343d70e /  / loc_2344e2d6
		int timeout;
		if (Menu_Data.menu_stack[ /*sp_0x28->bData_0x10*/Menu_Data.menu_stack_level ] != 0)
		{
			//0x2343d71e
			timeout = Menu_Data.menu_stack[ /*sp_0x28->bData_0x10*/Menu_Data.menu_stack_level ]->timeout;
		}
		else
		{
			timeout = 0;
		}
		//loc_2343d720
		pMsg = (void*) OSMboxPend(sp8.pMBox, (uint16_t)timeout, &err);

		r0 = pMsg->bData_0;

		pMenu = Menu_Data.menu_stack[ /*sp_0x28->bData_0x10*/Menu_Data.menu_stack_level ];
		pMenuItem = pMenu->Data_4;
#ifndef VDR110
		Graphic_Job_2_5* r2_ = pMenu->graphicData;
		int (*sp)() = r2_->lock;
		int (*r7)() = r2_->unlock;
#else
		sp4 = pMenuItem->Data_0x24;
		r6 = pMenuItem->Data_0x28;
#endif

		if (err == 0)
		{
			//0x2343d746 /  / 0x2344e310
			switch (r0)
			{
			case 0x21: //Down
			case 0x83:
				//loc_2343d77c /  / loc_2344e398
				navigateVal = 2;
				//loc_2343d77e
				navigateFunc = pMenu->onNavigate;
#ifndef VDR110
				pfGraphicHandler = pMenu->graphicHandler;
				//loc_2344e3a2
				if (sp != 0)
				{
					/*sp_0x34*/err = (sp)();
				}
				//loc_2344e3ac
#else
				//->loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
#endif
				break;

			case 0x20: //Up
			case 0x82:
				//0x2343d75e -> loc_2343d7d0 /  / loc_2344e38e -> loc_2344e39a
				navigateVal = 1;
				//loc_2343d77e
				navigateFunc = pMenu->onNavigate;
#ifndef VDR110
				pfGraphicHandler = pMenu->graphicHandler;
				//loc_2344e3a2
				if (sp != 0)
				{
					/*sp_0x34*/err = (sp)();
				}
				//loc_2344e3ac
#else
				//->loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
#endif
				break;

			case 0x2d: //EXIT
			case 0xe0:
				//loc_2343d78e /  / loc_2344e338
#ifndef VDR110
				if (r2_->wData_2 != 0x2e)
				{
					//0x2344e340
					if ((pMenu->onExit != 0) && ((pMenu->onExit)(0) != 0))
					{
						//->loc_2344e3a2
						if (sp != 0)
						{
							/*sp_0x34*/err = (sp)();
						}
						//loc_2344e3ac
					}
					else
					{
						//loc_2344e356
						pMenu = MENU_STACK_POP();
						if (pMenu != 0)
						{
							//0x2344e360
							sp = pMenu->graphicData->lock;
							r7 = pMenu->graphicData->unlock;
							pfGraphicHandler = pMenu->graphicHandler;

							sub_2343d51e(pMenu, &sp8);
							//->loc_2344e3a2
							if (sp != 0)
							{
								/*sp_0x34*/err = (sp)();
							}
							//loc_2344e3ac
						}
						else
						{
							//loc_2344e374
							graphic_start_job_2_5(&graphicQueueItem, 0);

							sub_2343d51e(0, &sp8);
							//loc_2344e384
							r7 = 0;
							//->loc_2344e3ac
						}
					}
				} //if (r2_->wData_2 != 0x2e)
				else
				{
					//loc_2344e34e
					if (pMenu->onExit != 0)
					{
						//0x2344e352
						(pMenu->onExit)(0);
					}
					//loc_2344e356
					pMenu = MENU_STACK_POP();
					if (pMenu != 0)
					{
						//0x2344e360
						sp = pMenu->graphicData->lock;
						r7 = pMenu->graphicData->unlock;
						pfGraphicHandler = pMenu->graphicHandler;

						sub_2343d51e(pMenu, &sp8);
						//->loc_2344e3a2
						if (sp != 0)
						{
							/*sp_0x34*/err = (sp)();
						}
						//loc_2344e3ac
					}
					else
					{
						//loc_2344e374
						graphic_start_job_2_5(&graphicQueueItem, 0);

						sub_2343d51e(0, &sp8);
						//loc_2344e384
						r7 = 0;
						//->loc_2344e3ac
					}
				}
#else
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
					pMenu = MENU_STACK_POP();

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
#endif
				break;

			case 0x57: //OK
			case 0xea:
				//0x2343d768 -> loc_2343d7d4 /  / loc_2344e334
				eventHandler = pMenuItem->onEvent;
#ifndef VDR110
				//loc_2344e384
				r7 = 0;
				//->loc_2344e3ac
#else
				//loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
#endif
				break;

			case 0x11: //Left
			case 0x81:
				//loc_2343d820 /  / loc_2344e388
#ifndef VDR110
				if (r2_->wData_2 == 0x51)
				{
					//loc_2344e38e
					//r0 = 1;
					//->loc_2344e39a
					navigateVal = 1;
					navigateFunc = pMenu->onNavigate;
					pfGraphicHandler = pMenu->graphicHandler;
				}
				//loc_2344e3a2
				if (sp != 0)
				{
					/*sp_0x34*/err = (sp)();
				}
				//loc_2344e3ac
#else
				navigateVal = 4;
				//loc_2343d77e
				navigateFunc = pMenu->onNavigate;
				//->loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
#endif
				break;

			case 0x10: //Right
			case 0x80:
				//loc_2343d824 /  / loc_2344e392
#ifndef VDR110
				if (r2_->wData_2 == 0x51)
				{
					//loc_2344e398
					//r0 = 2;
					//loc_2344e39a
					navigateVal = 2;
					navigateFunc = pMenu->onNavigate;
					pfGraphicHandler = pMenu->graphicHandler;
				}
				//loc_2344e3a2
				if (sp != 0)
				{
					/*sp_0x34*/err = (sp)();
				}
				//loc_2344e3ac
#else
				navigateVal = 8;
				//loc_2343d77e
				navigateFunc = pMenu->onNavigate;
				//->loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
#endif
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
#ifndef VDR110
			//loc_2344e3ac
			if (eventHandler != 0)
			{
				(eventHandler)(&sp8);
				eventHandler = 0;
			}
			//loc_2344e3b6
#else
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
					pMenu = MENU_STACK_POP();

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
#endif
			if (navigateFunc != 0)
			{
				(navigateFunc)(&navigateVal);

				err = sub_2343d51e(pMenu, &sp8);

				navigateFunc = 0;
			} //if (navigateFunc != 0)
			//loc_2343d84a /  / loc_2344e3d0
#ifndef VDR110
			if (pfGraphicHandler != 0)
			{
				//0x2344e3d4
				(pfGraphicHandler)(&graphicQueueItem, pMenu->graphicData);

				pfGraphicHandler = 0;
			}
			//loc_2344e3dc
			if (r7 != 0)
			{
				//0x2344e3e0
				err = (r7)();
			}
			//->loc_2344e3f6
#else
			if (r6 != 0)
			{
				(r6)(0);
			}
			//->loc_2343d89c
#endif
		} //if (err == 0)
		else
		{
			//->loc_2343d828 -> loc_2343d854 /  / loc_2344e3e6
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
						pMenu = MENU_STACK_POP();

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

#ifndef VDR110



/* /  / 2344ef18 - todo */
void sub_2344ef18(UI_Thread_Params* a)
{
#if 1
	console_send_string("sub_2344ef18 (todo.c): TODO\r\n");
#endif

}


/* /  / 2344f102 - todo */
void sub_2344f102(UI_Thread_Params* a)
{
#if 1
	console_send_string("sub_2344f102 (todo.c): TODO\r\n");
#endif

	uint8_t sp_0x44; //sp_0x44
	uint8_t err; //sp_0x40
	int sp_0x3c; //sp_0x3c
	UI_Thread_Params sp_0x24; //sp_0x24
	Graphic_Queue_Item sp_0x14; //sp_0x14
	Struct_2348dc50* sp_0x10; //sp_0x10
	int (*sp_0xc)(int*); //sp_0xc
	uint8_t (*sp8)(); //sp8
	uint8_t (*sp4)(); //sp4

	//int r2 = 0;
	Menu* r4; //r4
	Menu_Item* r6; //r6
	void (*r7)() = 0;
	int (*pOnEvent)(Struct_2348dc50*) = NULL; //r5
	sp_0xc = 0;

	sp_0x24 = *a;
	Menu_Data.Data_235fdf70/*2379679C*/ = &sp_0x24;

	err = OSSemPost(sp_0x24.pSema);
	OSMboxAccept(sp_0x24.pMBox);

	//sp_0x48 = &Menu_Data.menu_stack[9]/*237967C4*/;

	while (1)
	{
		//loc_2344f132
		r4 = Menu_Data.menu_stack[ Menu_Data.menu_stack_level ];

		uint32_t timeout;
		if (r4 != 0)
		{
			timeout = r4->timeout;
		}
		else
		{
			timeout = 0;
		}
		//loc_2344f148
		uint8_t* r0__ = OSMboxPend(sp_0x24.pMBox, (uint16_t)timeout, &err);
		sp_0x44 = *r0__;
		r6 = r4->Data_4;

		sp_0x10 = sub_2348dcd2();

		sp_0x10->pThreadParams = &sp_0x24;

		//r0 = r4->graphicData;
		sp8 = r4->graphicData->lock;
		sp4 = r4->graphicData->unlock;

		if (err == 0)
		{
			//0x2344f174
#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_2344f102: keyCode=0x%02x (%d)\r\n", sp_0x44, sp_0x44);
				console_send_string(debug_string);
			}
#endif
			switch (sp_0x44)
			{
				case 0xe0:
				case 0xf6:
					//loc_2344f216
				case 0x2d: //45 = Exit
					//2344F216???
					if (r4->graphicData/*r0*/->wData_2 == 0x27)
					{
						//loc_2344f248 -> loc_2344f352
					}
					else
					{
						//loc_2344f21c
						if ((r4->onExit != 0) && (0 != (r4->onExit)(&sp_0x24)))
						{
							//loc_2344f192 -> loc_2344f248
						}
						else
						{
							//loc_2344f22a
							r4 = MENU_STACK_POP();
							if (r4 != 0)
							{
								//0x2344f234
								sp8 = r4->graphicData->lock;
								sp4 = r4->graphicData->unlock;
								r7 = r4->graphicHandler;

								sub_2343d51e(r4, &sp_0x24);
								//loc_2344f248 -> loc_2344f352
							}
							else
							{
								//loc_2344f252
								sp4 = 0;

								graphic_start_job_2_5(&sp_0x14, 0);
								sub_2343d51e(0, &sp_0x24);
								//->loc_2344f35c
								goto loc_2344f35c;
							}
						}
					}
					break;

					break;

				case 0x57: //87 = OK
				case 0xea:
					//loc_2344f2b0
					//r0, #0x20
					//->0x2344f1d2
					sp_0x3c = (1 << 5); //0x20;
					//->0x2344f29c
					pOnEvent = r6->onEvent;
					//->2344f352
					break;

				case 0xe4:
					//loc_2344f208
					break;

				case 0x2c:
					//loc_2344f24a
					break;

				case 0x36:
					//loc_2344f26a
					break;

				case 0x0c: //On-Off
					//loc_2344f26e -> loc_2344f2dc
					if (0 != sub_2345a4e6(0))
					{
						//0x2344f2e6
						if (r4 != 0)
						{
							while (1)
							{
								//loc_2344f2ea							
								if (r4->onExit != 0)
								{
									//0x2344f2f0
									(r4->onExit)(&sp_0x24);
								}
								//loc_2344f2f4
								r4 = MENU_STACK_POP();
								if (r4 == 0)
								{
									//->0x2344f2fe
									break;
								}
							}
							//0x2344f2fe
							graphic_start_job_2_5(&sp_0x14, 0);
						}
						//loc_2344f306
						sub_2348f4e0();
						powermode_set_state(6, &sp_0x24, standby_thread);
					}
					//loc_2344f312
					if (0 != sub_23451e8c(1))
					{
						//0x2344f31c
						if (r4 != 0)
						{
							while (1)
							{
								//loc_2344f320
								if (r4->onExit != 0)
								{
									//0x2344f326
									(r4->onExit)(&sp_0x24);
								}
								//loc_2344f32a
								r4 = MENU_STACK_POP();
								if (r4 == 0)
								{
									//->0x2344f334
									break;
								}
							} //while (1)
							//0x2344f334
							graphic_start_job_2_5(&sp_0x14, 0);
						}
						//loc_2344f33c
						sub_2348f4e0();
						powermode_set_state(2, &sp_0x24, standby_thread);
					}
					//loc_2344f34a
					pOnEvent = 0;
					r7 = 0;
					sp_0xc = 0;
					//->loc_2344f3b2
					goto loc_2344f3b2;
					break;

				case 0x10: //Right
					//loc_2344f270 -> loc_2344f296
					//r0 = 0x200
					//->loc_2344f27c
					sp_0x3c = 0x200;
					r7 = r4->graphicHandler;
					pOnEvent = r6->onEvent;
					sp_0xc = r4->onNavigate;
					//->loc_2344f352
					break;

				case 0x11: //Left
					//0x2344f194
					//r0 = 0x400
					//->loc_2344f27c
					sp_0x3c = 0x400;
					r7 = r4->graphicHandler;
					pOnEvent = r6->onEvent;
					sp_0xc = r4->onNavigate;
					//->loc_2344f352
					break;

				case 0x20: //Up
					//loc_2344f276
					//r0 = 1;
					//->loc_2344f27c
					sp_0x3c = 0x01;
					r7 = r4->graphicHandler;
					pOnEvent = r6->onEvent;
					sp_0xc = r4->onNavigate;
					//->loc_2344f352
					break;

				case 0x21: //Down
					//0x2344f27a
					sp_0x3c = 0x02;
					r7 = r4->graphicHandler;
					pOnEvent = r6->onEvent;
					sp_0xc = r4->onNavigate;
					//->loc_2344f352
					break;

				case 0x39:
					//loc_2344f2a0
					break;

				case 0x40:
					//0x2344f1d0
					break;

				case 0x41:
					//loc_2344f2ac
					break;

				case 0x37:
					//loc_2344f2b4
					break;

				default:
					//loc_2344f248 -> loc_2344f352
					break;
			}
			//loc_2344f352???
			if (sp8 != 0)
			{
				//0x2344f358
				err = (sp8)();				
			}
			//loc_2344f35c
loc_2344f35c:
			if (pOnEvent != NULL)
			{
				//0x2344f360
				sp_0x10->Data_0 = sp_0x3c;

				int r0 = (pOnEvent)(sp_0x10);
				if (r0 != 0)
				{
					//0x2344f36e
					sub_2343d51e(0, &sp_0x24);
				}
				//loc_2344f376
				pOnEvent = NULL;
			}
			//loc_2344f378
			if (sp_0xc != 0)
			{
				//0x2344f37e
				err = (sp_0xc)(&sp_0x3c);

				sp_0xc = 0;
			}
			//loc_2344f38a
			if (r7 != 0)
			{
				//0x2344f38e
				(r7)(&sp_0x14, r4->graphicData);

				r7 = 0;
			}
			//loc_2344f396
			if (sp4 != 0)
			{
				//0x2344f39c
				err = (sp4)();

				sp4 = 0;
			}
			//loc_2344f3b2
		} //if (err == 0)
		else
		{
			//loc_2344f268 -> loc_2344f3a2: Default event handler (timer?)
			if (r6 != 0)
			{
				pOnEvent = r6->onEvent;
				if (pOnEvent != NULL)
				{
					(pOnEvent)(NULL);
					pOnEvent = NULL;
				}
			}
			//loc_2344f3b2
		}
		//loc_2344f3b2
loc_2344f3b2:
		if (62 == OSTaskDelReq(0xff))
		{
			OSTaskDel(0xff);
		}
		//->loc_2344f132
	} //while (1)
}


/* /  / 2344f3c6 - todo */
void sub_2344f3c6(UI_Thread_Params* a)
{
#if 1
	console_send_string("sub_2344f3c6 (todo.c): TODO\r\n");
#endif

	uint8_t keyCode; //sp_0x3c
	uint8_t err; //sp_0x38
	UI_Thread_Params thread_params; //sp_0x20
	Graphic_Queue_Item sp_0x10;
	Struct_2348dc50* sp_0xc;
	Menu_Item* sp8;
	int (*graphic_lock)(); //sp4
	int (*graphic_unlock)(); //sp
	Menu* r4;

	void (*r6)() = NULL;
	int (*r5)(Graphic_Queue_Item *, void *) = NULL;
	void (*r7)() = NULL;

	thread_params = *a;
	Menu_Data.Data_235fdf70/*2379679C*/ = &thread_params;

	sub_2348dcd2();

	err = OSSemPost(thread_params.pSema);

	OSMboxAccept(thread_params.pMBox);

	//sp_0x40 = &237967C4

	while (1)
	{
		//loc_2344f3f8
		uint8_t* r0__ = OSMboxPend(thread_params.pMBox, 0, &err);
		keyCode = *r0__;

		r4 = Menu_Data.menu_stack[ Menu_Data.menu_stack_level ];
		sp8 = r4->Data_4;

		sp_0xc = sub_2348dcd2();
		sp_0xc->pThreadParams = &thread_params;

		graphic_lock = r4->graphicData->lock;
		graphic_unlock = r4->graphicData->unlock;

		switch (keyCode)
		{
			case 0x2d:
				//loc_2344f472
				if ((r4->onExit == NULL) ||
					(0 == (r4->onExit)(&thread_params)))
				{
					//loc_2344f480
					r4 = menu_stack_operate(NULL);
					if (r4 != NULL)
					{
						//0x2344f48a
						graphic_lock = r4->graphicData->lock;
						graphic_unlock = r4->graphicData->unlock;
						r5 = r4->graphicHandler;

						/*sub_2344de56*/sub_2343d51e(r4, &thread_params);
						//->loc_2344f4e8
					}
					else
					{
						//loc_2344f4a0
						graphic_start_job_2_5(&sp_0x10, NULL);

						/*sub_2344de56*/sub_2343d51e(NULL, &thread_params);

						graphic_unlock = NULL;
						//->loc_2344f4f2
						goto loc_2344f4f2;
					}
				}
				//loc_2344f4e8
				break;

			case 0x37: //55: Red
			case 0x38: //56: F1
				//loc_2344f462
				sp_0xc->Data_0 = 0x80;
				//->loc_2344f4d0
				r7 = sp8->onEvent;
				r6 = r4->onNavigate;
				r5 = r4->graphicHandler;
				//->loc_2344f4e8
				break;

			case 0x57: //87: OK
				//loc_2344f4da
				//r1 = 0x20
				//->loc_2344f4e2
				sp_0xc->Data_0 = 0x20;
				//->loc_2344f4d0
				r7 = sp8->onEvent;
				r6 = r4->onNavigate;
				r5 = r4->graphicHandler;
				//->loc_2344f4e8
				break;

				//TODO!!!

			default:
#if 1
				{
					extern char debug_string[];
					sprintf(debug_string, "sub_2344f3c6: keyCode=%d(0x%x)\r\n", keyCode, keyCode);
					console_send_string(debug_string);
				}
#endif
				break;
		} //switch (keyCode)
		//loc_2344f4e8
		if (graphic_lock != NULL)
		{
			//0x2344f4ee
			err = (graphic_lock)();
		}
loc_2344f4f2:
		//loc_2344f4f2
		if (r7 != NULL)
		{
			//0x2344f4f6
			(r7)(sp_0xc);

			r7 = NULL;
		}
		//loc_2344f4fc
		if (r6 != NULL)
		{
			//0x2344f500
			(r6)(sp_0xc);

			r6 = NULL;
		}
		//loc_2344f506
		if (r5 != NULL)
		{
			//0x2344f50a
			(r5)(&sp_0x10, r4->graphicData);

			r5 = NULL;
		}
		//loc_2344f512
		if (graphic_unlock != NULL)
		{
			err = (graphic_unlock)();
		}
		//loc_2344f51c
		if (62 == OSTaskDelReq(0xff))
		{
			//loc_23450218
			OSTaskDel(0xff);
		}
		//->loc_2344f3f8
	} //while (1)

}


/* /  / 234500bc - todo */
void sub_234500bc(UI_Thread_Params* a)
{
#if 1
	console_send_string("sub_234500bc (todo.c): TODO\r\n");
#endif

	uint8_t sp_0x34; //sp_0x34
	int sp_0x30; //sp_0x30
	Graphic_Queue_Item sp_0x20; //sp_0x20
	UI_Thread_Params sp8;
	void (*sp4)(void);
	uint8_t (*r7)(void);
	int (*r6)(int*) = 0;
	void (*r5)(Graphic_Queue_Item*, Graphic_Job_2_5*);
	Menu* r4;

	sp8 = *a;
	Menu_Data.Data_235fdf70/*2379679C*/ = &sp8;

	sp_0x34 = OSSemPost(sp8.pSema);

	r5 = 0;

	OSMboxAccept(sp8.pMBox);

	while (1)
	{
		//loc_234500e8
		Menu* r0 = Menu_Data.menu_stack[ Menu_Data.menu_stack_level ];

		uint32_t timeout;
		if (r0 != 0)
		{
			timeout = r0->timeout;
		}
		else
		{
			timeout = 0;
		}
		//loc_234500fa
		uint8_t* r0__ = OSMboxPend(sp8.pMBox, (uint16_t)timeout, &sp_0x34);
		uint8_t keyCode/*r0*/ = *r0__;

		r4 = Menu_Data.menu_stack[ Menu_Data.menu_stack_level ];

		Menu_Item* r1 = r4->Data_4;
		sp4 = r4->graphicData->lock;
		r7 = r4->graphicData->unlock;

		if (sp_0x34 != 10)
		{
			//0x23450122
#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_234500bc: keyCode=0x%02x (%d)\r\n", keyCode, keyCode);
				console_send_string(debug_string);
			}
#endif
			switch (keyCode)
			{
				case 0x2c:
				case 0x2d:
				case 0x2f:
					//loc_23450144
					if ((r4->onExit == 0) || (0 == (r4->onExit(&sp8))))
					{
						//loc_23450152
						r4 = MENU_STACK_POP();
						if (r4 != 0)
						{
							//0x2345015c
							sp4 = r4->graphicData->lock;
							r7 = r4->graphicData->unlock;
							r5 = r4->graphicHandler;

							sub_2343d51e(r4, &sp8);
							//->loc_23450192
						}
						else
						{
							//loc_23450170
							r7 = 0;

							graphic_start_job_2_5(&sp_0x20, 0);
							sub_2343d51e(0, &sp8);
							//->loc_2345019c
							goto loc_2345019c;
						}
					}
					//loc_23450192
					break;

				case 0x20:
					//loc_23450184
					break;

				case 0x21:
					//loc_2345018e
					break;

				case 0x32:
					//0x2345013e
					break;

				default:
					//loc_23450192
					break;
			} //switch (keyCode)
			//loc_23450192
			if (sp4 != 0)
			{
				(sp4)();

				sp4 = 0;
			}
loc_2345019c:
			//loc_2345019c
			if (r6 != 0)
			{
				(r6)(&sp_0x30);

				r6 = 0;
			}
			//loc_234501a6
			if (r5 != 0)
			{
				(r5)(&sp_0x20, r4->graphicData);

				r5 = 0;
			}
			//loc_234501b2
			if (r7 != 0)
			{
				sp_0x34 = (r7)();
			}
			//->loc_2345020c
		} //if (sp_0x34 != 10)
		else
		{
			//loc_234501bc
			r6 = r1->onEvent;
#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_234500bc: loc_234501bc: r6=%p\r\n", r6);
				console_send_string(debug_string);
			}
#endif
			if (r6 != 0)
			{
				//0x234501c2
				int res = (r6)(0);
#if 1
				{
					extern char debug_string[];
					sprintf(debug_string, "sub_234500bc: OnEvent->res=%d\r\n", res);
					console_send_string(debug_string);
				}
#endif
				if (res = 0xff)
				{
					//0x234501ca
					if ((r4->onExit == 0) || (0 == (r4->onExit)(&sp8)))
					{
						//loc_234501d8
						r4 = MENU_STACK_POP();
						if (r4 != 0)
						{
							//0x234501e2
							sub_2343d51e(r4, &sp8);

							if (r5 != 0)
							{
								//0x234501f0
								(r5)(&sp_0x20, r4->graphicData);

								r5 = 0;
							}
							//->loc_2345020a
						}
						else
						{
							//loc_234501fa
							graphic_start_job_2_5(&sp_0x20, 0);

							sub_2343d51e(0, &sp8);
						}
						//loc_2345020a
					}
					else
					{
						//->loc_23450220
						return;
					}
				}
				//loc_2345020a
				r6 = 0;
			}
			//loc_2345020c
		}
		//loc_2345020c
		if (62 == OSTaskDelReq(0xff))
		{
			//loc_23450218
			OSTaskDel(0xff);
		}
		//->loc_234500e8
	} //while (1)
	//loc_23450220
}


#endif //!VDR110

/* 2343d8b4 - todo */
void standby_thread(UI_Thread_Params* a)
{
	uint8_t err; //sp_0x5c
	Struct_2340bf0c sp_0x28;
	Channel sp;
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

	Menu_Data.Data_235fdf70 = &Data_235fdf40;

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
					sub_2340bf0c(&sp_0x28);

					channel_start_number(&sp, 
						sp_0x28.wCurrentChannel, sp_0x28.wCurrentChannel);
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


/* 2343d98e - todo */
void sub_2343d98e(UI_Thread_Params* r1)
{
	uint8_t sp_0x20;
	int sp_0x1c;
	UI_Thread_Params sp4;
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2

	}* pMsg;

	void (*r4)() = 0;

#if 0
	console_send_string("sub_2343d98e (todo.c): TODO\r\n");
#endif

	memcpy(&sp4, r1, sizeof(UI_Thread_Params));

	Menu_Data.Data_235fdf70 = &sp4;

	sp_0x20 = OSSemPost(sp4.pSema);

	Menu_Data.bData_235fdfa9 = 0; //TODO!!!

	OSMboxAccept(sp4.pMBox);

	while (1)
	{
		//loc_2343d9ba
		Menu* r7;
		Menu* r2;
		Menu_Item* r1;

		pMsg = (void*) OSMboxPend(sp4.pMBox, 0, &sp_0x20);

		r2 = Menu_Data.menu_stack[Menu_Data.menu_stack_level];
		r1 = r2->Data_4;

		switch (pMsg->bData_0)
		{
		case 0x57:
		case 0xea:
			//loc_2343d9f8
			//r0, #0x20
			//->loc_2343da30
			sp_0x1c = 0x20;

			r4 = r1->onEvent;
			//loc_2343da34
			break;

		case 0x2d: //EXIT
		case 0xe0:
			//loc_2343d9fc
			if (r2->onExit != 0)
			{
				(r2->onExit)(0);
			}
			//loc_2343da06
			r7 = MENU_STACK_POP();
			if (r7 != 0)
			{
				//0x2343da10
				if (r7->onEnter != 0)
				{
					(r7->onEnter)(-1);
				}
				//loc_2343da1c
				sub_2343d51e(r7, &sp4);
				//->loc_2343da34
			}
			else
			{
				//loc_2343da26
				sub_2343d51e(0, &sp4);
			}
			//->loc_2343da34
			break;

		case 0x10:
		case 0x11:
		case 0x2f:
		case 0x80:
		case 0x81:
			//loc_2343da2c
			sp_0x1c = 1 << 12;

			r4 = r1->onEvent;
			//loc_2343da34
			break;

		default:
			//loc_2343da34
			break;
		}
		//loc_2343da34
		if (r4 != 0)
		{
			(r4)(&sp_0x1c);

			r4 = 0;
		}
		//loc_2343da3e
		if (62 == OSTaskDelReq(0xff))
		{
			OSTaskDel(0xff);
		}
		//->loc_2343d9ba
	}
}


/*  /  / 2344f662 - todo */
void sub_2344f662(Graphic_Queue_Item* pQueueItem)
{
#if 0
	console_send_string("sub_2344f662 (todo.c): TODO\r\n");
#endif

	Menu* pMenu = Menu_Data.menu_stack[ Menu_Data.menu_stack_level ];

	if (Menu_Data.menu_stack_level != 0)
	{
		//0x2344f678
		if ((pMenu->onExit == 0) || (0 == (pMenu->onExit)(Menu_Data.Data_235fdf70)))
		{
			//loc_2344f686
			Menu* pMenu = MENU_STACK_POP();

			if (pMenu != 0)
			{
				//0x2344f692
				sub_2343d51e(pMenu, Menu_Data.Data_235fdf70);

				graphic_start_job_2_5(pQueueItem, pMenu->graphicData);
			}
			else
			{
				//loc_2344f69c
				sub_2343d51e(0, Menu_Data.Data_235fdf70);

				graphic_start_job_2_5(pQueueItem, 0);
			}
		}
		//loc_2344f6aa
	}
	//loc_2344f6aa
}

#ifndef VDR110

/* /  / 2344f6ac */
void sub_2344f6ac(UI_Thread_Params* p)
{
#if 1
	console_send_string("sub_2344f6ac (todo.c): TODO\r\n");
#endif

	uint8_t sp_0x44;
	int sp_0x40;
	int sp_0x34;
	Graphic_Queue_Item sp_0x24;
	UI_Thread_Params sp_0xc;
	void (*sp8)() = NULL;
	int (*sp4)();
	int (*sp)();
	void (*r6)();
	int (*r5)(void*) = NULL;

	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2

	}* pMsg;
	int r0;

	Menu_Item* r7;

	sp_0xc = *p;

	//r4, =0x23796784

	Menu_Data.Data_235fdf70 = &sp_0xc;

	sp_0x44 = OSSemPost(sp_0xc.pSema);

	r6 = NULL;
	sp_0x40 = 0;

	OSMboxAccept(sp_0xc.pMBox);

	//sp_0x48 = r4 + 0x40 = 237967C4

	while (1)
	{
		//loc_2344f6de
		int timeout;
		Menu* r4 = Menu_Data.menu_stack[ Menu_Data.menu_stack_level ];

		if (r4 != NULL)
		{
			timeout = r4->timeout;
		}
		else
		{
			timeout = 0;
		}
		//loc_2344f6fe
		pMsg = (void*) OSMboxPend(sp_0xc.pMBox, (uint16_t)timeout, &sp_0x44);

		r0 = pMsg->bData_0;

		r7 = r4->Data_4;
		sp4 = r4->graphicData->lock;
		sp = r4->graphicData->unlock;

		if (sp_0x44 != 0)
		{
			//0x2344f71e
			if (r7 != NULL)
			{
				if (sp4 != NULL)
				{
					(sp4)();
				}
				//loc_2344f728
				r5 = r7->onEvent;

				if (r5 != NULL)
				{
					(r5)(NULL);

					r5 = NULL;
				}
				//loc_2344f734
				if (sp != NULL)
				{
					(sp)();
				}
			}
			//loc_2344f73c -> loc_2344f8a2
		}
		else
		{
			//loc_2344f73e
			switch (r0)
			{
				case 9:
				case 8:
				case 7:
					//loc_2344f7d0
					break;

				case 0x20:
					//loc_2344f7fa
					sp_0x34 = 1;
					//->loc_2344f800
					r6 = r4->graphicHandler;
					if (sp_0x40 == 0)
					{
						sp8 = r4->onNavigate;
						//->loc_2344f812
					}
					else
					{
						//loc_2344f810
						r5 = r7->onEvent;
					}
					//loc_2344f812
					break;

				case 0x21:
					//loc_2344f7fe
					sp_0x34 = 2;
					//loc_2344f800
					r6 = r4->graphicHandler;
					if (sp_0x40 == 0)
					{
						sp8 = r4->onNavigate;
						//->loc_2344f812
					}
					else
					{
						//loc_2344f810
						r5 = r7->onEvent;
					}
					//loc_2344f812
					break;

				case 0x2d:
					//loc_2344f784
					if (sp_0x40 != 1)
					{
						//0x2344f78a
						if ((r4->onExit == NULL) ||
							(0 == (r4->onExit)(&sp_0xc)))
						{
							//loc_2344f798
							r4 = MENU_STACK_POP();
							if (r4 != NULL)
							{
								//0x2344f7a2
								sp4 = r4->graphicData->lock;
								sp = r4->graphicData->unlock;
								r7 = r4->Data_4;
								r6 = r4->graphicHandler;

								/*sub_2344de56*/sub_2343d51e(r4, &sp_0xc);
								//->loc_2344f812
							}
							else
							{
								//loc_2344f7ba
								sp = NULL;

								graphic_start_job_2_5(&sp_0x24, NULL);
								/*sub_2344de56*/sub_2343d51e(NULL, &sp_0xc);
								//->loc_2344f81c
								goto loc_2344f81c;
							}
						}
						//loc_2344f812
					}
					//loc_2344f812
					break;

				case 0x10:
					//loc_2344f840
					sp_0x34 = 8;
					r6 = r4->graphicHandler;
					//->loc_2344f810
					r5 = r7->onEvent;
					//loc_2344f812
					break;

				case 0x11:
					//0x2344f75c
					sp_0x34 = 4;
					r6 = r4->graphicHandler;
					//->loc_2344f810
					r5 = r7->onEvent;
					//loc_2344f812
					break;

				case 0x57:
					//0x2344f770
					sp_0x34 = 0x20;

					if (sp_0x40 == 0)
					{
						//0x2344f77a
						sp_0x40 = 1;

						//r1 = 9;
						//r2 = 1;
						//->loc_2344f7f0
						sub_2344d850(r7, 9, 1, 1);
						//->loc_2344f7de
					}
					//loc_2344f7e4
					else if (sp_0x40 == 1)
					{
						//0x2344f7e8
						sp_0x40 = 0;
						//r2 = 1;
						//r1 = 7;
						//loc_2344f7f0
						sub_2344d850(r7, 7, 1, 1);
						//->loc_2344f7de
					}
					//loc_2344f7de
					r5 = r7->onEvent;
					r6 = r4->graphicHandler;
					//->loc_2344f812
					break;

				default:
					//loc_2344f812
					break;
			}
			//loc_2344f812
			if (sp4 != NULL)
			{
				//0x2344f818
				sp_0x44 = (sp4)();
			}
loc_2344f81c:
			//loc_2344f81c
			if (r5 != NULL)
			{
				//0x2344f820
				if (sp_0x40 == 1)
				{
					//0x2344f826
					sp_0x34 |= (1 << 28);

					int r0 = (r5)(&sp_0x34);

					if (r0 == 8)
					{
						//0x2344f838
						r6 = NULL;
						sp8 = NULL;
						//->loc_2344f866
					}
					else
					{
						//loc_2344f844
						//r2 = 1;
						//r1 = 9;
						//->loc_2344f85c
						(Data_234c21c8)(r7, 9, 1, 1);
						//loc_2344f866
					}
				} //if (sp_0x40 == 1)
				else
				{
					//loc_2344f84a
					if (0 != (r5)(&sp_0x34))
					{
						//0x2344f852
						//r2 = 1;
						//r1 = 0xa
						//->loc_2344f85c
						(Data_234c21c8)(r7, 10, 1, 1);
						//loc_2344f866
					}
					else
					{
						//loc_2344f858
						//r2 = 1;
						//r1 = 8;
						//loc_2344f85c
						(Data_234c21c8)(r7, 8, 1, 1);
						//loc_2344f866
					}
				}
				//loc_2344f866
				if (r7->initValueString != NULL)
				{
					(r7->initValueString)(r7);
				}
				//loc_2344f870
				r5 = NULL;
			}
			//loc_2344f872
			if (sp8 != NULL)
			{
				//0x2344f878
				(sp8)(&sp_0x34);

				sp_0x44 = /*sub_2344de56*/sub_2343d51e(r4, &sp_0xc);

				sp8 = NULL;
			}
			//loc_2344f88c
			if (r6 != NULL)
			{
				//0x2344f890
				(r6)(&sp_0x24, r4->graphicData);

				r6 = NULL;
			}
			//loc_2344f898
			if (sp != NULL)
			{
				//0x2344f89e
				sp_0x44 = (sp)();
			}
			//loc_2344f8a2
		}
		//loc_2344f8a2
		if (62 == OSTaskDelReq(0xff))
		{
			//loc_2344f8ae
			OSTaskDel(0xff);
		}
		//->loc_2344f6de
	}
	//while (1)
}

#endif //VDR110

/* 2343da50 /  / 2344f8b6 - todo */
void menu_item_event_thread(UI_Thread_Params* p)
{
#ifdef VDR110
	void (*pfOnMenuNavigate)() = 0; //r6
#endif
	Menu* pMenu; //r5 / r4
	Menu_Item* pMenuItem; //r1 / r7
	uint8_t (*pfMenuItemOnEvent)(int*) = 0; //r4 / r5
#ifndef VDR110
	void (*pfGraphicHandler)(); // / r6
#endif
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2

	}* pMsg;
	int r0;
	uint8_t err; //sp_0x20 / sp_0x3c
	int cursor; //sp_0x1c / sp_0x38
#ifndef VDR110
	Graphic_Queue_Item graphicQueueItem; //sp_0x28
#endif
	UI_Thread_Params threadParams; //sp4 / sp_0x10
#ifndef VDR110
	void (*pfOnMenuNavigate)() = 0; //sp_0xc
	uint8_t (*sp8)(); //sp8
	uint8_t (*sp4)(); //sp4
#endif

#if 0
	console_send_string("menu_item_event_thread (todo.c): TODO\r\n");
#endif

	threadParams = *p;

	Menu_Data.Data_235fdf70 = &threadParams;

	//r5, =0x235fdf58

	err = OSSemPost(threadParams.pSema);

#ifndef VDR110
	pfGraphicHandler = 0;
#endif

	OSMboxAccept(threadParams.pMBox);

	//r7 = r5 + 0x40 = 235FDF98

	while (1)
	{
		//loc_2343da7a
		int timeout;
		if (Menu_Data.menu_stack[ Menu_Data.menu_stack_level ] != 0)
		{
			//0x2343da88
			timeout = Menu_Data.menu_stack[ Menu_Data.menu_stack_level ]->timeout;
		}
		else
		{
			timeout = 0;
		}
		//loc_2343da8a
		pMsg = (void*) OSMboxPend(threadParams.pMBox, (uint16_t)timeout, &err);

		r0 = pMsg->bData_0;
		//loc_2343daa4
		pMenu = Menu_Data.menu_stack[ Menu_Data.menu_stack_level ];
		pMenuItem = pMenu->Data_4;
#ifndef VDR110
		sp8 = pMenu->graphicData->lock;
		sp4 = pMenu->graphicData->unlock;
#endif

		if (err != 10)
		{
			//0x2343dab6 / 0x2344f922
			switch (r0)
			{
			case 0x20: //Up
				//loc_2343db10
				cursor = 1;
				//->loc_2343db16
#ifndef VDR110
				pfGraphicHandler = pMenu->graphicHandler;
#endif
				pfOnMenuNavigate = pMenu->onNavigate;
				//->loc_2343db20
				break;

			case 0x21: //Down
				//loc_2343db14
				cursor = 2;
				//->loc_2343db16
#ifndef VDR110
				pfGraphicHandler = pMenu->graphicHandler;
#endif
				pfOnMenuNavigate = pMenu->onNavigate;
				//->loc_2343db20
				break;

			case 0x11: //Left
				//0x2343dac4
				cursor = 4;
#ifndef VDR110
				pfGraphicHandler = pMenu->graphicHandler;
#endif
				pfMenuItemOnEvent = pMenuItem->onEvent;
				//->loc_2343db20
				break;

			case 0x10: //Right
				//loc_2343db1c
				cursor = 8;
#ifndef VDR110
				pfGraphicHandler = pMenu->graphicHandler;
#endif
				pfMenuItemOnEvent = pMenuItem->onEvent;
				//->loc_2343db20
				break;

			case 0x2d: //EXIT
#ifdef VDR110
				//0x2343dad4
				if (pMenu != 0)
				{
					if ((pMenu->onExit == 0) ||
							(0 == (pMenu->onExit)(&threadParams)))
					{
						//loc_2343dae6
						pMenu = MENU_STACK_POP();

						if (pMenu != 0)
						{
							sub_2343d51e(pMenu, &threadParams);

							if (pMenu->onEnter != 0)
							{
								(pMenu->onEnter)(-1);
							}
							//loc_2343db20
						}
						else
						{
							//loc_2343db06
							sub_2343d51e(0, &threadParams);
							//->loc_2343db20
						}
					}
					//loc_2343db20
				}
				else
				{
					//loc_2343db06
					sub_2343d51e(0, &threadParams);
					//->loc_2343db20
				}
#else //!VDR110
			case 0xe0:
				//loc_2344f95e
				if ((pMenu->onExit == 0) ||
						(0 == (pMenu->onExit)(&threadParams)))
				{
					//loc_2344f96c
					pMenu = MENU_STACK_POP();

					if (pMenu != 0)
					{
						//0x2344f976
						sp8 = pMenu->graphicData->lock;
						sp4 = pMenu->graphicData->unlock;

						pMenuItem = pMenu->Data_4;
						pfGraphicHandler = pMenu->graphicHandler;

						sub_2343d51e(pMenu, &threadParams);
						//->loc_2344f9c0
					}
					else
					{
						//loc_2344f98e
						sp4 = 0;

						graphic_start_job_2_5(&graphicQueueItem, 0);

						sub_2343d51e(0, &threadParams);
						//->loc_2344f9ca
					}
				}
				//loc_2344f9c0
#endif //!VDR110
				break;
			} //switch (r0)
#ifdef VDR110
			//loc_2343db20
			if (pfMenuItemOnEvent != 0)
			{
				(pfMenuItemOnEvent)(&cursor);

				pfMenuItemOnEvent = 0;
			}
			//loc_2343db2a
#else //!VDR110
			//loc_2344f9c0
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "menu_item_event_thread: sp8=0x%x\r\n", sp8);
				console_send_string(debug_string);
			}
#endif
			if (sp8 != 0)
			{
				err = (sp8)();
			}
			//loc_2344f9ca
			if (pfMenuItemOnEvent != 0)
			{
				//0x2344f9ce
				err = (pfMenuItemOnEvent)(&cursor);

				if (err == 0xff)
				{
					//0x2344f9dc
					pfGraphicHandler = 0;
					//->loc_2344fa02
				}
				//loc_2344f9e0
				else if (err != 0)
				{
					//0x2344f9e4
					//r2 = 1;
					//r1 = 10;
					//->loc_2344f9ee
					(Data_234c21c8)(pMenuItem, 10, 1, 1);

					if (pMenuItem->initValueString != 0)
					{
						(pMenuItem->initValueString)(pMenuItem);
					}
					//loc_2344fa02
				}
				else
				{
					//loc_2344f9ea
					//r2 = 1;
					//r1 = 8;
					//loc_2344f9ee
					(Data_234c21c8)(pMenuItem, 8, 1, 1);

					if (pMenuItem->initValueString != 0)
					{
						(pMenuItem->initValueString)(pMenuItem);
					}
					//loc_2344fa02
				}
				//loc_2344fa02
				pfMenuItemOnEvent = 0;
			} //if (pfMenuItemOnEvent != 0)
			//loc_2344fa04
#endif //!VDR110
			if (pfOnMenuNavigate != 0)
			{
				// / 0x2344fa0a
				(pfOnMenuNavigate)(&cursor);

				err = sub_2343d51e(pMenu, &threadParams);

				pfOnMenuNavigate = 0;
			}
#ifdef VDR110
			//loc_2343db4c
#else
			//loc_2344fa1e -> loc_2344fa22
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "menu_item_event_thread: pfGraphicHandler=%p\r\n", pfGraphicHandler);
				console_send_string(debug_string);
			}
#endif
			if (pfGraphicHandler != 0)
			{
				(pfGraphicHandler)(&graphicQueueItem, pMenu->graphicData);

				pfGraphicHandler = 0;
			}
			//loc_2344fa2e
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "menu_item_event_thread: sp4=0x%x\r\n", sp4);
				console_send_string(debug_string);
			}
#endif
			if (sp4 != 0)
			{
				//0x2344fa34
				err = (sp4)();
			}
			//loc_2344fa46
#endif //!VDR110
		} //if (err != 10)
		else
		{
			//loc_2343db40
			pfMenuItemOnEvent = pMenuItem->onEvent;
			if (pfMenuItemOnEvent != 0)
			{
				(pfMenuItemOnEvent)(0);

				pfMenuItemOnEvent = 0;
			}
		}
		//loc_2343db4c / loc_2344fa46
		if (62 == OSTaskDelReq(0xff))
		{
			//0x2343db56
			OSTaskDel(0xff);
		}
		//->loc_2343da7a
	} //while (1)
}


/* 2343dcce - complete */
void sub_2343dcce(void)
{
	Struct_2340bf0c sp_0x28;
	Channel sp;

#if 0
	console_send_string("sub_2343dcce (todo.c): TODO\r\n");
#endif

	sub_2340bf0c(&sp_0x28);

	if (sp_0x28.wNumChannels != 0)
	{
		channel_start_number(&sp, 
			sp_0x28.wCurrentChannel, sp_0x28.wCurrentChannel);
	}
}

#ifndef VDR110


/* /  / 2344fa5a - todo */
void sub_2344fa5a(UI_Thread_Params* p)
{
#if 0
	console_send_string("sub_23450f66 (todo.c): TODO\r\n");
#endif

	uint8_t err; //sp_0x34
	int cursor; //sp_0x30
	Graphic_Queue_Item sp_0x20;

	Menu* pMenu; //r4
	Menu_Item* pMenuItem; //r1

	UI_Thread_Params thread_params; //sp8
	void (*navigate)() = NULL; //r7
	int (*graphic_lock)() = NULL; //r5
	void (*event_handler)() = NULL; //sp4
	int (*graphic_unlock)() = NULL; //sp

	thread_params = *p;

	Menu_Data.Data_235fdf70 = &thread_params;

	err = OSSemPost(thread_params.pSema);

	//sp_0x38 = 237967C4;
	void (*graphic_handler)(Graphic_Queue_Item*, Graphic_Job_2_5*) = NULL; //r6
	Menu_Data.bData_235fdfa9/*237967D5*/ = 0; //r6

	OSMboxAccept(thread_params.pMBox);

	while (1)
	{
		//loc_2344fa8e
		struct
		{
			uint8_t bData_0; //0
			uint8_t bData_1; //1
			uint8_t bData_2; //2
	
		}* pMsg;
		int r0;
	
		pMsg = (void*) OSMboxPend(thread_params.pMBox, 0, &err);
		r0 = pMsg->bData_0;

		pMenu = Menu_Data.menu_stack[ Menu_Data.menu_stack_level ];
		pMenuItem = pMenu->Data_4;

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2344fa5a: r0=0x%x(%d)\r\n", r0, r0);
			console_send_string(debug_string);
		}
#endif

		switch (r0)
		{
			case 0x2d:
			case 0xe0:
				//0x2344faba -> loc_2344face
				cursor = 0x10;
				event_handler = pMenuItem->onEvent;
				//->loc_2344fade
				break;

			case 0x57: //87
			case 0xea: 
				//loc_2344fac4
				cursor = 0x20;
				event_handler = pMenuItem->onEvent;
				//->loc_2344fade
				break;
	
			case 0x10:
				//loc_2344fad2
				cursor = 0x01;
				navigate = pMenu->onNavigate;
				graphic_handler = pMenu->graphicHandler;
				//loc_2344fade
				break;

			case 0x11:
				//loc_2344fad6
				cursor = 0x02;
				navigate = pMenu->onNavigate;
				graphic_handler = pMenu->graphicHandler;
				//loc_2344fade
				break;

			default:
				//loc_2344fade
				break;
		} //switch (r0)
		//loc_2344fade
		if (graphic_lock != NULL)
		{
			err = (graphic_lock)();
		}
		//loc_2344fae6
		if (event_handler != NULL)
		{
			//0x2344faec
			if (cursor == 0x20)
			{
				//0x2344faf2
				(event_handler)(&thread_params);

				pMenu = menu_stack_operate(NULL);
			}
			//loc_2344fb00
			if ((pMenu != NULL) && 
				(NULL != (pMenu = menu_stack_operate(NULL))))
			{
				//0x2344fb0e
				err = /*sub_2344de56*/sub_2343d51e(pMenu, &thread_params);

				graphic_handler = pMenu->graphicHandler;
				graphic_lock = pMenu->graphicData->lock;
				graphic_unlock = pMenu->graphicData->unlock;

				if (graphic_lock != NULL)
				{
					err = (graphic_lock)();
				}
				//loc_2344fb2a				
			}
			else
			{
				//loc_2344fb6a
				graphic_start_job_2_5(&sp_0x20, NULL);
				/*sub_2344de56*/sub_2343d51e(NULL, &thread_params);
				graphic_lock = NULL;
				graphic_unlock = NULL;
				//->loc_2344fb2a
			}
			//loc_2344fb2a				
			event_handler = NULL;
		}
		//loc_2344fb2e
		if (navigate != NULL)
		{
			//0x2344fb32
			(navigate)(&cursor);

			err = /*sub_2344de56*/sub_2343d51e(pMenu, &thread_params);

			navigate = NULL;
		}
		//loc_2344fb42
		if (graphic_handler != NULL)
		{
			//0x2344fb46
			(graphic_handler)(&sp_0x20, pMenu->graphicData);

			graphic_handler = NULL;
		}
		//loc_2344fb4e
		if (graphic_unlock != NULL)
		{
			err = (graphic_unlock)();
		}
		//loc_2344fb58
		if (62 == OSTaskDelReq(0xff))
		{
			//0x2344fb62
			OSTaskDel(0xff);
		}
		//->loc_2344fa8e
	} //while (1)
}


/* /  / 23450f66 - todo */
void sub_23450f66(UI_Thread_Params* p)
{
#if 1
	console_send_string("sub_23450f66 (todo.c): TODO\r\n");
#endif

	Menu* r4; //pMenu;
	Menu_Item* r7;
	Graphic_Queue_Item sp_0x28;
	uint8_t sp_0x3c;
	int sp_0x38;
	UI_Thread_Params sp_0x10;
	int (*r6)(void*) = NULL;
	void (*sp_0xc)(void*) = 0;
	int (*sp8)();
	int (*sp4)();

	sp_0x10 = *p;

	Menu_Data.Data_235fdf70 = &sp_0x10;

	sp_0x3c = OSSemPost(sp_0x10.pSema);

	void (*r5)(Graphic_Queue_Item*, Graphic_Job_2_5*) = NULL;

	OSMboxAccept(sp_0x10.pMBox);

	//sp_0x40 = 237967C4;

	while (1)
	{
		//loc_23450f96
		struct
		{
			uint8_t bData_0; //0
			uint8_t bData_1; //1
			uint8_t bData_2; //2
	
		}* pMsg;
		int r0;
	
		pMsg = (void*) OSMboxPend(sp_0x10.pMBox, 0, &sp_0x3c);
		r0 = pMsg->bData_0;

		r4 = Menu_Data.menu_stack[ Menu_Data.menu_stack_level ];
		r7 = r4->Data_4;
		sp8 = r4->graphicData->lock;
		sp4 = r4->graphicData->unlock;

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_23450f66: r0=0x%x(%d)\r\n", r0, r0);
			console_send_string(debug_string);
		}
#endif

		switch (r0)
		{
			case 0x21:
				//loc_23451028
				break;

			case 0x2d:
				//loc_23450fe2
				break;

			case 0x57:
			case 0xea:
				//loc_23450fdc
				break;

			//TODO!!!
		}
		//loc_23451040
		if (sp8 != NULL)
		{
			sp_0x3c = (sp8)();
		}
		//loc_2345104a
		if (r6 != NULL)
		{
			sp_0x3c = (r6)(&sp_0x38);

			if (sp_0x3c == 0)
			{
				//0x2345105c
				//r2 = 1;
				//r1 = 8;
				//->loc_2345106a
				(Data_234c21c8)(r7, 8, 1, 1);
			}
			//loc_23451062
			else if (sp_0x3c == 1)
			{
				//0x23451066
				//r2 = 1;
				//r1 = 0x0a;
				//loc_2345106a
				(Data_234c21c8)(r7, 10, 1, 1);
			}
			//loc_23451074
			if (r7->initValueString != NULL)
			{
				(r7->initValueString)(r7);
			}
			//loc_2345107e
			r6 = NULL;
		}
		//loc_23451080
		if (sp_0xc != NULL)
		{
			//0x23451086
			(sp_0xc)(&sp_0x38);

			sp_0x3c = /*sub_2344de56*/sub_2343d51e(r4, &sp_0x10);

			sp_0xc = NULL;
		}
		//loc_2345109a
		if (r5 != NULL)
		{
			//0x2345109e
			(r5)(&sp_0x28, r4->graphicData);

			r5 = NULL;
		}
		//loc_234510a6
		if (sp4 != NULL)
		{
			//0x234510ac
			sp_0x3c = (sp4)();
		}
		//loc_234510b0
		if (62 == OSTaskDelReq(0xff))
		{
			//loc_234510bc
			OSTaskDel(0xff);
		}
		//->loc_23450f96
	} //while (1)
}

#endif
