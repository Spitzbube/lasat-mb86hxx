
#include "data.h"
#include "frontdisplay.h"
#include "graphic.h"

#ifndef VDR110

static Menu menu_main; //234c2044

static void menu_main_on_enter(int);
static int menu_main_on_exit(void);
static int menu_main_items_on_event(void*);


//0x234c1230
uint8_t bData_234c1230 = 0; //234c1230 +0
Menu* Data_234c1240 = &menu_main; //234C1240 +0x10
int (*Data_234c124c)() = 0; //234C124C +0x1c
Menu* Data_234c1250 = 0; //234c1250 +0x20
Menu_Item* Data_234c1254 = 0; //234c1254 +0x24

uint8_t Data_234c1564[40] = "Head"; //234c1564 +0x28 = 234C158C
static Struct_235fdf74_Inner12_Inner0x20 Data_234c158c = //234c158c
{
	{0, 0, 0, 0},
	&Data_234c1564[0], //Data_0x10
#if 0
	0x234c158c 0000                   movs       r0, r0                             ; DATA XREF=0x234c1894
	0x234c158e 5100                   lsls       r1, r2, #0x1
	0x234c1590 2C00                   movs       r4, r5
	0x234c1592 3701                   lsls       r7, r6, #0x4
	0x234c1594 4F00                   lsls       r7, r1, #0x1
	0x234c1596 0106                   lsls       r1, r0, #0x18                      ; CODE XREF=dword_234c13ac+38
	0x234c1598 0200                   movs       r2, r0
	0x234c159a 0000                   movs       r0, r0
	0x234c159c                        dd         0x234c1564                         ; "Head"
#endif
};

static uint8_t Data_234c16b4[40] = "1"; //234c16b4
static uint8_t Data_234c16f4[40] = "2"; //234c16f4

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234c16dc = //234c16dc
{
	{0, 0, 0, 0},
	&Data_234c16b4[0], //Data_0x10
#if 0
	0x234c16dc 0000                   movs       r0, r0                             ; DATA XREF=0x234c1994
	0x234c16de 5100                   lsls       r1, r2, #0x1
	0x234c16e0 6400                   lsls       r4, r4, #0x1
	0x234c16e2 3701                   lsls       r7, r6, #0x4
	0x234c16e4 8000                   lsls       r0, r0, #0x2
	0x234c16e6 0104                   lsls       r1, r0, #0x10
	0x234c16e8 0901                   lsls       r1, r1, #0x4
	0x234c16ea 0000                   movs       r0, r0
	0x234c16ec                        dd         0x234c16b4
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234c171c = //234c171c
{
	{0, 0, 0, 0},
	&Data_234c16f4[0], //Data_0x10
#if 0
	0x234c171c 0000                   movs       r0, r0                             ; DATA XREF=0x234c19d4
	0x234c171e 5100                   lsls       r1, r2, #0x1
	0x234c1720 8400                   lsls       r4, r0, #0x2
	0x234c1722 3701                   lsls       r7, r6, #0x4
	0x234c1724 A000                   lsls       r0, r4, #0x2
	0x234c1726 0104                   lsls       r1, r0, #0x10
	0x234c1728 0901                   lsls       r1, r1, #0x4
	0x234c172a 0000                   movs       r0, r0
	0x234c172c                        dd         0x234c16f4
#endif
};

static Struct_2377ded0_Inner_0x1c Data_234c1834[14] = //234c1834
{
	{0}, //[0] = 234c1834
	{0}, //[1] = 234C1874
	{0}, //[2] = 234C18B4
	{0}, //[3] = 234C18F4
	{0}, //[4] = 234C1934 
	{0}, //[5] = 234C1974
	{0}, //[6] = 234C19B4
	{0}, //[7] = 234C19F4 
	{0}, //[8] = 234C1A34
	{0}, //[9] = 234C1A74 
	{0}, //[10] = 234C1AB4 
	{0}, //[11] = 234C1AF4
	{0}, //[12] = 234C1B34 
	{0}, //[13] = 234C1B74
};

static Struct_235fdf74_Inner12 Data_234c1874 = //234c1874
{
	{0, 0, 0, 0, 0, 0, 0, 0}, //TODO
	&Data_234c158c, //Data_0x20
#if 0
	0x234c1874 0100                   movs       r1, r0                             ; DATA XREF=0x234c2050
	0x234c1876 0000                   movs       r0, r0
	0x234c1878                        dd         0x234c1544
	0x234c187c 0000                   movs       r0, r0
	0x234c187e 0000                   movs       r0, r0
	0x234c1880 3D00                   movs       r5, r7
	0x234c1882 2900                   movs       r1, r5
	0x234c1884 FA00                   lsls       r2, r7, #0x3
	0x234c1886 2600                   movs       r6, r4
	0x234c1888 0000                   movs       r0, r0
	0x234c188a 0000                   movs       r0, r0
	0x234c188c                        dd         0x234c134c
	0x234c1890 0200                   movs       r2, r0
	0x234c1892 0000                   movs       r0, r0
	0x234c1894                        dd         0x234c158c
#endif
};

static Menu_Item_Inner4_Data_0 Data_234c1974 = //234c1974
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234c16dc, //Data_0x20
#if 0
	0x234c1974 0100                   movs       r1, r0                             ; DATA XREF=0x234c1f40
	0x234c1976 0000                   movs       r0, r0
	0x234c1978                        dd         0x234c1548
	0x234c197c 0000                   movs       r0, r0
	0x234c197e 0000                   movs       r0, r0
	0x234c1980 3D00                   movs       r5, r7
	0x234c1982 6000                   lsls       r0, r4, #0x1
	0x234c1984 FA00                   lsls       r2, r7, #0x3
	0x234c1986 2000                   movs       r0, r4
	0x234c1988 0000                   movs       r0, r0
	0x234c198a 0000                   movs       r0, r0
	0x234c198c                        dd         0x234c1298
	0x234c1990 0900                   movs       r1, r1
	0x234c1992 0000                   movs       r0, r0
	0x234c1994                        dd         0x234c16dc
#endif
};

static Menu_Item_Inner4_Data_0 Data_234c19b4 = //234c19b4
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234c171c, //Data_0x20
#if 0
	0x234c19b4 0100                   movs       r1, r0                             ; DATA XREF=0x234c1f6c
	0x234c19b6 0000                   movs       r0, r0
	0x234c19b8                        dd         0x234c1548
	0x234c19bc 0000                   movs       r0, r0
	0x234c19be 0000                   movs       r0, r0
	0x234c19c0 3D00                   movs       r5, r7
	0x234c19c2 8000                   lsls       r0, r0, #0x2
	0x234c19c4 FA00                   lsls       r2, r7, #0x3
	0x234c19c6 2000                   movs       r0, r4
	0x234c19c8 0000                   movs       r0, r0
	0x234c19ca 0000                   movs       r0, r0
	0x234c19cc                        dd         0x234c12d4
	0x234c19d0 0900                   movs       r1, r1
	0x234c19d2 0000                   movs       r0, r0
	0x234c19d4                        dd         0x234c171c
#endif
};

#if 1
static Struct_23414b38_b Data_234c1ef4 = //234c1ef4
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x0004, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234c1834[0], //int Data_8; //8
	0, //Struct_23414b38_b_Inner_0xc* Data_0xc; //12
	0x0f, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	14, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
	0, //0x1c
	0, //0x20
#if 0
#endif
};
#else
static Struct_235fdf74_Inner20 Data_234c1ef4 = //234c1ef4
{
	0, //uint16_t fill_0; //0
	0, //uint16_t wData_2; //2
	{0, 0, 0, 0, 0, 0}, //int fill_4[6]; //4
	0, //void (*Data_0x1c)(); //28 = 0x1c
	0, //void (*Data_0x20)(); //32 = 0x20
#if 0
	0x234c1ef4                        db  0x00 ; '.'                                ; DATA XREF=sub_2344d060+6, dword_234c2058
	0x234c1ef5                        db  0xfa ; '.'
	0x234c1ef6 0400                   movs       r4, r0
	0x234c1ef8 0400                   movs       r4, r0
	0x234c1efa 0000                   movs       r0, r0
	0x234c1efc                        dd         0x234c1834                         ; DATA XREF=sub_2344d060+18
	0x234c1f00                        dd         0x234c123c
	0x234c1f04 0F00                   movs       r7, r1
	0x234c1f06 0000                   movs       r0, r0
	0x234c1f08 0000                   movs       r0, r0
	0x234c1f0a 0000                   movs       r0, r0
	0x234c1f0c 0E01                   lsls       r6, r1, #0x4
	0x234c1f0e 0000                   movs       r0, r0
	0x234c1f10                        dd         0x00000000
	0x234c1f14                        dd         0x00000000
#endif
};
#endif

static Menu_Item menu_main_items[] = //234c1f3c
{
	//[0]
	{
		0x4a, //"Einstellungen"
		0xffff, //uint16_t wData_2; //2
		{
				&Data_234c1974, //Data_4.Data_0
				0,
				0,
				0,
				0
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23492fc4
	},
#if 0
	0x234c1f3c                        dw         0x004a                             ; DATA XREF=0x234c2048, 0x234c204c
	0x234c1f3e                        dw         0x00f3
	0x234c1f40                        dd         0x234c1974
	0x234c1f44                        dd         0x00000000
	0x234c1f48                        dd         0x00000000
	0x234c1f4c                        dd         0x00000000
	0x234c1f50                        dd         0x00000000
	0x234c1f54                        dd         0x00000000
	0x234c1f58                        dd         menu_main_items_on_event+1
	0x234c1f5c                        dd         sub_2344e2a6+1
	0x234c1f60                        dd         0x00000000
	0x234c1f64                        dd         0x00000000
#endif
	//[1]
	{
		0x79, //"Installation"
		0xffff, //uint16_t wData_2; //2
		{
				&Data_234c19b4, //Data_4.Data_0
				0,
				0,
				0,
				0
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23492fc4
	},
#if 0
	0x234c1f68                        dw         0x0079
	0x234c1f6a                        dw         0x00f3
	0x234c1f6c                        dd         0x234c19b4
	0x234c1f70                        dd         0x00000000
	0x234c1f74                        dd         0x00000000
	0x234c1f78                        dd         0x00000000
	0x234c1f7c                        dd         0x00000000
	0x234c1f80                        dd         0x00000000
	0x234c1f84                        dd         menu_main_items_on_event+1
	0x234c1f88                        dd         sub_2344e2a6+1
	0x234c1f8c                        dd         0x00000000
	0x234c1f90                        dd         0x00000000
#endif
	//TODO!!!: Increase also menu_main.maxItem!
};

static Menu menu_main = //234c2044
{
    10, //"Hauptmenu"
    &menu_main_items[0], //Menu_Item* Data_4; //4
    &menu_main_items[0], //Menu_Item* Data_8; //8
    &Data_234c1874, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
    0, //&Data_234c1874, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
    &Data_234c1ef4, //int Data_0x14; //20 = 0x14
    1, //5, //uint8_t maxItem; //0x18 = 24
    0, //int8_t currentItem; //0x19
    0, //sub_23414b38, //void (*Data_0x1c)(); //0x1c
	menu_items_navigate, //void (*onNavigate)(); //0x20
    menu_main_on_enter, //void (*onEnter)(); //36 = 0x24
    menu_main_on_exit, //int (*onExit)(); //0x28
    0, //int Data_0x2c; //44 = 0x2c
    0, //int Data_0x30; //48
    0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
    0, //void* (*Data_0x38)(struct FrontDisplay_Job*); //56
    //0x3c = 60
#if 0
    0x234c2044                        dw         0x000a                             ; DATA XREF=sub_2344d060+4, sub_2344d3f0+6, sub_2344d3f0+12, sub_2344d3f0+18
    0x234c2046                        dw         0x0000
    0x234c2048                        dd         0x234c1f3c
    0x234c204c                        dd         0x234c1f3c
    0x234c2050                        dd         0x234c1874
    0x234c2054                        dd         0x234c18f4
                                    dword_234c2058:
    0x234c2058                        dd         0x234c1ef4                         ; DATA XREF=sub_2344d060+6
    0x234c205c 0500                   movs       r5, r0
    0x234c205e 0000                   movs       r0, r0
    0x234c2060                        dd         sub_23414b38
    0x234c2064                        dd         sub_2344dbb8+1
    0x234c2068                        dd         menu_main_on_enter+1
    0x234c206c                        dd         menu_main_on_exit+1
    0x234c2070 0000                   movs       r0, r0
    0x234c2072 0000                   movs       r0, r0
    0x234c2074                        dw         0x000a
    0x234c2076                        dw         0x0000
    0x234c2078                        dd         0x00000000
    0x234c207c                        dd         0x00000000
#endif
};



/*  /  / 2344cf8c - todo */
int menu_main_items_on_event(void* r0)
{
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "menu_main_items_on_event: r0=%p\r\n", r0);
		console_send_string(debug_string);
	}
#endif

	if (r0 != 0)
	{
		//0x2344cf96
		if (Data_234c1240->currentItem == 0)
		{
			//0x2344cfa0: Einstellungen
			menu_settings_entry(r0);
			//->loc_2344d05a
		}
		//loc_2344cfa6
		else if (Data_234c1240->currentItem == 1)
		{
			//0x2344cfaa: Installation
#if 0
			sub_234523c8();
#endif
			//->loc_2344d05a
		}
		//loc_2344cfb0
		else if (Data_234c1240->currentItem == 2)
		{
			//0x2344cfb4: Senderliste
#if 0
			sub_23490bd0();
#endif
			//->loc_2344d05a
		}
		//loc_2344cfba
		else if (Data_234c1240->currentItem == 3)
		{
			//0x2344cfbe: Timer
#if 0
			sub_23492b34();
#endif
			//->loc_2344d05a
		}
		//loc_2344cfc4
		else if (Data_234c1240->currentItem == 4)
		{
			//0x2344cfc8: Information
#if 0
			sub_23456220();
#endif
			//->loc_2344d05a
		}
		//loc_2344cfce
		else if (Data_234c1240->currentItem == 5)
		{
			//0x2344cfc8: Aufnahmespeicher
#if 0
			sub_23497aa0();
#endif
			//->loc_2344d05a
		}
		//loc_2344d05a
	}
	else
	{
		//loc_2344cfd8
		console_send_string("menu_main_items_on_event: loc_2344cfd8: TODO\r\n");

		//TODO!!!
	}
	//loc_2344d05a
	return 0;
}


/*  /  / 2344d060 - todo */
void menu_main_on_enter(int a)
{
#if 1
	console_send_string("menu_main_on_enter (todo.c): TODO\r\n");
#endif

}


/*  /  / 2344d0cc - complete */
int menu_main_on_exit(void)
{
#if 0
	console_send_string("menu_main_on_exit (todo.c): TODO\r\n");
#endif

	return 0;
}


/*  /  / 2344d0d0 - todo */
void* sub_2344d0d0(FrontDisplay_Job* r4)
{
#if 0
	console_send_string("sub_2344d0d0 (todo.c): TODO\r\n");
#endif

	struct Menu_Data* r0 = sub_2344de8e();

	//void* sp_0x40 = &r0->Data_0x40;
	FrontDisplay_Job* sp_0x3c;
	uint8_t* sp_0x38;
	uint8_t* sp_0x34;
	FrontDisplay_Job* sp_0x30;
	uint8_t sp_0x2c[4];

#if 0
	struct
	{
		int fill_0[5]; //0
		struct
		{
			uint16_t fill_0; //0
			uint16_t wData_2; //2

		}* Data_0x14; //20 = 0x14

	}
#endif
	Menu* r6 = r0->menu_stack[r0->menu_stack_level];

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2344d0d0: r0->menu_stack_level=%d, r6=%p\r\n",
				r0->menu_stack_level, r6);
		console_send_string(debug_string);
	}
#endif

	sp_0x2c[0] = 0;
	sp_0x30 = r4;

	uint8_t sp_0xc[32] = "default"; //234b49e4
	uint8_t* sp8 = &sp_0xc[0];
	uint8_t sp4;
	int sp;

	sp_0x3c = &r4[1];
	sp_0x38 = &r4->bData_8[0];

	int r7 = 0;
	//r5 = &r4->0x100;

	if ((r6 == 0) || (r6->Data_0x14->wData_2 == 1))
	{
		//loc_2344d11c
		sp = sub_23451f60();
		if (sp != 0)
		{
			//0x2344d126
	        console_send_string("sub_2344d0d0: 0x2344d126: TODO!!!\r\n");
#if 0 //TODO!!!
			if (0 != sub_23421f84()) //-> recording?
			{
				//0x2344d12e
				sp_0x2c[r7] = 0x1b;
				r7++;
			}
			//loc_2344d136
			sp_0x2c[r7] = 0x1a;
			r7++;
			sp4 = r7;

			strncpy(sp_0x38, sp_0x2c, 0xff);

			/*r5->8*/r4->bNumTextChars = strlen(sp_0x38);
			//r6 = 0;
			r4->bDisplayOffset = 0; //r6
			r4->bNumDisplayChars = 3;
			r4->bData_0x10b = 0; //r6
			r4->bData_0x10c = 0; //r6
			r4->holdTime = 0; //r6
			r4->Data_0 = frontdisplay_draw_text;
			r4->Data_4 = 0;
			r4->bData_0x10f = 0; //r6
			//0x2344d168
			//r5 = sp_0x3c

			if (0 != sub_234210bc())
			{
				//0x2344d172
				//r0 = sp + 8;
				//->loc_2344d188
				sp8 = (void*) (sp + 8);
			}
			else
			{
				//loc_2344d178
				if (0 != sub_2341e2e4())
				{
					//0x2344d182
					sp8 = (void*) sub_2341e3c4(sp);
				}
			}
			//loc_2344d18a
			strncpy(/*r4 = r5->8*/sp_0x3c->bData_8, sp8, 0xff);
			sp_0x3c->bNumTextChars = strlen(sp_0x3c->bData_8);
			sp_0x3c->bDisplayOffset = sp4;
			sp_0x3c->bNumDisplayChars = 12;
			sp_0x3c->bData_0x10b = 0; //r6
			sp_0x3c->bData_0x10c = 0; //r6
			sp_0x3c->bData_0x110 = 0; //r6
			sp_0x3c->holdTime = 0; //r6
			sp_0x3c->Data_0 = frontdisplay_draw_text;
			sp_0x3c->Data_4 = 0; //r6
			sp_0x3c->bData_0x10f = 0; //r6

			if ((sp_0x3c->bNumDisplayChars - sp_0x3c->bDisplayOffset) < sp_0x3c->bNumTextChars)
			{
				//0x2344d1c4
				sp_0x3c->bData_0x10c = 1;
				sp_0x3c->Data_0 = frontdisplay_draw_scroll_text;
			}
#endif //TODO
			//->loc_2344d21e
		} //if (sp != 0)
		else
		{
			//loc_2344d1ce
			if ((Data_234c124c != 0) &&
					(0 == (Data_234c124c)(&sp8)))
			{
				//0x2344d1de
				strncpy(sp_0x38, sp8, 0xff);

				/*r5->8*/r4->bNumTextChars = strlen(sp_0x38);
				r4->bDisplayOffset = r7; //0
				r4->bNumDisplayChars = 12;
				r4->bData_0x10b = 0;
				r4->bData_0x10c = 0;
				r4->bData_0x110 = 0;
				r4->holdTime = 0;
				r4->Data_0 = frontdisplay_draw_text;
				r4->Data_4 = 0;
				r4->bData_0x10f = 0;

				if (r4->bNumTextChars > 12)
				{
					//0x2344d20e
					r4->bData_0x10c = 1;
					r4->Data_0 = frontdisplay_draw_scroll_text;
				}
				//->loc_2344d21e
			}
			else
			{
				//loc_2344d21a
				sub_23418f80();
			}
			//loc_2344d21e
		}
		//loc_2344d21e
		Data_234c1250 = 0;
		//->loc_2344d2d0
		return 0;
	} //if ((r6 == 0) || (r6->Data_0x14->wData_2 == 1))
	else
	{
		//loc_2344d218 -> loc_2344d226
		if (/*sp_0x40->bData_0x10*/r0->menu_stack_level == 0)
		{
			//0x2344d22e

			//TODO!!!
			console_send_string("sub_2344d0d0: 0x2344d22e TODO!!!\r\n");

			//->loc_2344d2be
		} //if (/*sp_0x40->bData_0x10*/r0->bData_237967d4 == 0)
		else
		{
			//loc_2344d25a
			if ((Data_234c1250 != r6) &&
					//0x2344d262
					(r6->Data_0xc != 0) &&
					//0x2344d268
					(r6->Data_0xc->Data_0x20 != 0))
			{
				//0x2344d26e: Handle Menu Header
#if 0
    			console_send_string("sub_2344d0d0: 0x2344d26e: TODO!!!\r\n");
#endif
				r4->bData_8[0] = 0x22; //r7

				strncpy(&r4->bData_8[1], r6->Data_0xc->Data_0x20->Data_0x10, 10);

				uint8_t r0 = (uint8_t) strlen(sp_0x38);
				r4->bData_8[r0] = 0x22; //r7
				r0++;
				r4->bData_8[r0] = 0; //r7
				r4->bNumTextChars = strlen(sp_0x38);
				r4->bDisplayOffset = 0; //r7
				r4->bNumDisplayChars = 12;
				r4->bData_0x10b = 0; //r7
				r4->bData_0x10c = 0; //r7
				r4->bData_0x110 = 0; //r7
				r4->holdTime = 20;
				r4->Data_0 = frontdisplay_draw_text;
				r4->Data_4 = 0; //r7
				r4->bData_0x10f = 1;

				Data_234c1250 = r6;

				if (r6->Data_0x38 == 0)
				{
					//loc_2344d2be
					return sub_2344d0d0;
				}
				else
				{
					//loc_2344d2c0
					return r6->Data_0x38;
				}
			} //if ((Data_234c1250 != r6) && (r6->Data_0xc != 0) && (r6->Data_0xc->Data_0x20 != 0))
			else
			{
				//loc_2344d2c4: Handle (current) Menu Item
				Menu_Item* pMenuItem = r6->Data_4;

				if (pMenuItem == 0)
				{
					//->loc_2344d2d0
					return 0;
				}

				Menu_Item_Inner4_Data_0* r0_ = pMenuItem->Data_4[0];
				if (r0_ == 0)
				{
					//->loc_2344d2d0: No Columns
					return 0;
				}
				//loc_2344d2d4: Column 1
				Menu_Item_Inner4_Data_0_Data_0x20* r0 = r0_->Data_0x20;

				if (r0 != 0)
				{
					//0x2344d2da
#if 0
					{
						extern char debug_string[];
						sprintf(debug_string, "sub_2344d0d0: r0->Data_0x10='%s'\r\n",
								r0->Data_0x10);
						console_send_string(debug_string);
					}
#endif
					strncpy(sp_0x38, r0->Data_0x10, 0xff);

					r4->bData_8[255] = 0;
					r4->bNumTextChars = strlen(sp_0x38);
					r4->bDisplayOffset = 0;
					r4->bNumDisplayChars = 12;
					r4->bData_0x10b = 0;
					r4->bData_0x10c = 0;
					r4->bData_0x110 = 0;
					r4->holdTime = 0;
					r4->Data_4 = 0;
					r4->Data_0 = frontdisplay_draw_text;
					r4->bData_0x10f = 0;

					if (Data_234c1250 != r6)
					{
						//0x2344d316
						r4->bData_0x10f = 1;
					}
					//loc_2344d31a
					if (r4->bNumTextChars > 12)
					{
						//0x2344d31e
						r4->bData_0x10c = 1;
						r4->Data_0 = frontdisplay_draw_scroll_text;
					}
					//loc_2344d326
					r4 = sp_0x3c;
				} //if (r0 != 0)
				//loc_2344d328
				r0_ = pMenuItem->Data_4[1];
				if (r0_ != 0)
				{
					//0x2344d32e: Column 2
					if (r0_->Data_0x20 != 0)
					{
						//0x2344d334
						sp_0x34 = r4->bData_8;

						strncpy(sp_0x34, r0_->Data_0x20->Data_0x10, 0xff);

						r4->bData_8[0xff] = 0;

						r4->bNumTextChars = strlen(sp_0x34);

						r4->bDisplayOffset = 6;
						r4->bNumDisplayChars = 12;
						int ip = 6;
						if (r4->bNumTextChars < 6)
						{
							//0x2344d364
							r4->bDisplayOffset = (r4->bNumDisplayChars - r4->bNumTextChars) - 1;
						}
						//loc_2344d36a
						if (sp_0x30->bNumTextChars < r4->bDisplayOffset)
						{
							//0x2344d378
							r4->bDisplayOffset = sp_0x30->bNumTextChars;

							ip = r4->bNumDisplayChars - r4->bDisplayOffset;
						}
						//loc_2344d380
						r4->bData_0x10b = 0;
						r4->bData_0x10c = 0;
						r4->bData_0x110 = 1;
						r4->holdTime = 0;
						r4->bData_0x10f = 0;
						r4->Data_4 = 0;
						r4->Data_0 = frontdisplay_draw_text;
						sp_0x30->holdTime = 10;

						if (r4->bNumTextChars > ip)
						{
							//0x2344d3c0
							r4->Data_0 = frontdisplay_draw_scroll_text;
							r4->bData_0x10c = 1;
						}
						//loc_2344d3c6
						if (Data_234c1254 != pMenuItem)
						{
							//0x2344d3ce
							r4->bData_0x10f = 1;
							//->loc_2344d3e4
						}
						else
						{
							//loc_2344d3d2
							if (r4->bNumTextChars < bData_234c1230)
							{
								//0x2344d3d8
								sp_0x30->bData_0x10f = 1;
								sp_0x30->Data_0 = frontdisplay_draw_text;
								sp_0x30->holdTime = 0;
							}
							//loc_2344d3e4
						}
						//loc_2344d3e4
						bData_234c1230 = r4->bNumTextChars;
					} //if (r0_->Data_0x20 != 0)
					//loc_2344d3e8
				} //if (r0_ != 0)
				//loc_2344d3e8
				Data_234c1254 = pMenuItem;
				Data_234c1250 = r6;
				//->loc_2344d2be
				return sub_2344d0d0;
			}
		}
	}
}


/*  /  / 2344d3f0 - todo */
int menu_main_entry(UI_Thread_Params* r5)
{
#if 0
	console_send_string("menu_main_entry (todo.c): TODO\r\n");
#endif

	menu_stack_operate(Data_234c1240);

	menu_initialize(Data_234c1240);

	sub_2343d51e(Data_234c1240, r5);

	frontdisplay_start_text(sub_2344d0d0);

	return 0;
}


/*  /  / 2344d414 - complete */
int sub_2344d414(UI_Thread_Params* r4)
{
	User_Settings sp4;

#if 0
	console_send_string("sub_2344d414 (todo.c): TODO\r\n");
#endif

	sub_2344db36(r4);

	channel_handle_user_settings(1, &sp4);

	if (((sp4.Data_0x10 & 0x30) >> 4) != 0)
	{
		sub_23457a3e(r4, 1);
	}
	else
	{
		menu_main_entry(r4);
	}

	return 0;
}

#endif //VDR110
