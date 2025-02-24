#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "menu.h"

#ifndef VDR110

#pragma thumb

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c134c; //234c134c

static Menu Data_234c79bc; //234c79bc
static Menu Data_234c7ea8; //234c7ea8

static int sub_23454a1a(int);

//0x234c52dc
static Menu* Data_234c5304 = &Data_234c79bc; //234c5304 +0x28
Menu* Data_234c5354 = &Data_234c7ea8; //234c5354
static uint8_t Data_23799814[]; //23799814

static Graphic_Job_2_5_Item_Text Data_234c54a8 = //234c54a8
{
    0, 0x006e, 0x00cb, 0x021c, 0x0131, 0x01, 0x06, 0x02, 0x00, &Data_23799814[0], 0, 0, 0
#if 0
0x234c54a8                        db         0x00                               ; DATA XREF=0x234c5750
0x234c54a9                        db         0x00
0x234c54aa                        dw         0x006e
0x234c54ac                        dw         0x00cb
0x234c54ae                        dw         0x021c
0x234c54b0                        dw         0x0131
0x234c54b2                        db         0x01
0x234c54b3                        db         0x06
0x234c54b4                        db         0x02
0x234c54b5                        db         0x00
0x234c54b6 0000                   movs       r0, r0
0x234c54b8                        dd         0x23799814
#endif
};

static Graphic_Job_2_5_Item Data_234c55b0[] = //234c55b0
{
	{0}, //[0] = 234c55b0
	{0}, //[1] = 234C55F0
	{0}, //[2] = 234C5630
	{0}, //[3] = 234C5670
	{0}, //[4] = 234C56B0
	//234C56F0
};

static Graphic_Job_2_5_Item Data_234c56f0[] = //234c56f0
{
	{0}, //[0] = 234c56f0
	{1, 0, 0, 0/*Data_8*/, 0x0064, 0x00c8, 0x01b8, 0x0069, 0, &Data_234c134c/*Data_0x18*/, 2, 0, &Data_234c54a8/*Data_0x20*/}, //[1] = 234C5730: Header
#if 0
0x234c5730                        db         0x01                               ; DATA XREF=0x234c7be4, 0x234c7e78, 0x234c7eb4
0x234c5731                        db  0x00 ; '.'
0x234c5732 0000                   movs       r0, r0
0x234c5734                        dd         0x234c5480
0x234c5738 0000                   movs       r0, r0
0x234c573a 0000                   movs       r0, r0
0x234c573c                        dw         0x0064
0x234c573e                        dw         0x00c8
0x234c5740                        dw         0x01b8
0x234c5742                        dw         0x0069
0x234c5744 0000                   movs       r0, r0
0x234c5746 0000                   movs       r0, r0
0x234c5748                        dd         0x234c134c
0x234c574c                        dw         0x0002
0x234c574e 0000                   movs       r0, r0
0x234c5750                        dd         0x234c54a8
#endif
	{0}, //[2] = 234C5770 
    //234C57B0
};

static Graphic_Job_2_5 Data_234c5cd4 = //234c5cd4
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x0008, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234c55b0[0], //Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	0x10, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	5, //uint8_t bData_0x18; //0x18 = 24
	0x00, //uint8_t bData_0x19; //0x19 = 25
#if 0
0x234c5cd4                        db         0x00                               ; DATA XREF=dword_234c79d0, 0x234c7a0c, 0x234c7bb0
0x234c5cd5                        db         0xfa
0x234c5cd6                        dw         0x0008
0x234c5cd8                        db         0x04
0x234c5cd9                        db  0x00 ; '.'
0x234c5cda 0000                   movs       r0, r0
0x234c5cdc                        dd         0x234c55b0
0x234c5ce0                        dd         menu_main_graphic_color_data
0x234c5ce4                        db         0x10
0x234c5ce5                        db  0x00 ; '.'
0x234c5ce6                        dw         0x0000
0x234c5ce8                        dd         0x00000000
0x234c5cec                        db         0x05
0x234c5ced                        db  0x00 ; '.'
0x234c5cee 0000                   movs       r0, r0
0x234c5cf0 0000                   movs       r0, r0
0x234c5cf2 0000                   movs       r0, r0
0x234c5cf4 0000                   movs       r0, r0
0x234c5cf6 0000                   movs       r0, r0
#endif
};

static Graphic_Job_2_5 Data_234c5cf8 = //234c5cf8
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x0008, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234c56f0[0], //Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	0x10, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	3, //uint8_t bData_0x18; //0x18 = 24
	0x00, //uint8_t bData_0x19; //0x19 = 25
#if 0
0x234c5cf8                        db         0x00                               ; DATA XREF=sub_23454a2a+14, sub_23454a5c+20, sub_23454a98+20, sub_23454ace+20, sub_23454b04+12, sub_23454b48+14, sub_23454b8e+12, sub_23454bc0+12, sub_23454bf2+12, sub_23454c1c+12, sub_23454c52+12
0x234c5cf9                        db         0xfa
0x234c5cfa                        dw         0x0008
0x234c5cfc                        db         0x04
0x234c5cfd                        db  0x00 ; '.'
0x234c5cfe 0000                   movs       r0, r0
0x234c5d00                        dd         0x234c56f0
0x234c5d04                        dd         menu_main_graphic_color_data
0x234c5d08                        db         0x10
0x234c5d09                        db  0x00 ; '.'
0x234c5d0a 0000                   movs       r0, r0
0x234c5d0c                        dd         0x00000000
0x234c5d10                        db         0x03
0x234c5d11                        db         0x00
#endif
};


static Menu_Item Data_234c6a58[] = //234c6a58
{

};

static Menu Data_234c7ea8 = //234c7ea8
{
    0xffff, 
    NULL, //Menu_Item* Data_4; //4
    NULL, //Menu_Item* Data_8; //8
    &Data_234c56f0[1], //234c5730, //Struct_235fdf74_Inner12* header; //12 = 0xc
    NULL, //Struct_235fdf74_Inner16* help; //16 = 0x10
    &Data_234c5cf8, //int graphicData; //20 = 0x14
    0, //uint8_t maxItem; //0x18 = 24
    0, //int8_t currentItem; //0x19
    graphic_start_job_2_5, //void (*graphicHandler)(); //0x1c
    NULL, //void (*onNavigate)(); //0x20
    sub_23454a1a, //int (*onEnter)(int); //36 = 0x24
    0, //int (*onExit)(UI_Thread_Params*); //0x28
	0, //int Data_0x2c; //44 = 0x2c
	0, //int timeout; //48 = 0x30
	0, //Menu_Item* (*Data_0x34)(struct Menu*); //52 = 0x34
	0, //void* (*Data_0x38)(struct FrontDisplay_Job*); //56 = 0x38
#if 0
0x234c7ea8                        dw         0xffff                             ; DATA XREF=sub_2348fba6+48, sub_2348fba6+54, sub_2349281e+114, sub_2349281e+120, dword_234c5354
0x234c7eaa 0000                   movs       r0, r0
0x234c7eac                        dd         0x00000000
0x234c7eb0                        dd         0x00000000
0x234c7eb4                        dd         0x234c5730
0x234c7eb8                        dd         0x00000000                         ; DATA XREF=dword_234c7dc8+12
0x234c7ebc                        dd         0x234c5cf8                         ; DATA XREF=sub_2348fba6+56, sub_2349281e+122
0x234c7ec0 0000                   movs       r0, r0
0x234c7ec2 0000                   movs       r0, r0
0x234c7ec4                        dd         graphic_start_job_2_5
0x234c7ec8 0000                   movs       r0, r0
0x234c7eca 0000                   movs       r0, r0
0x234c7ecc                        dd         sub_23454a1a+1
#endif
//234C7EE4
};


static Menu Data_234c79bc = //234c79bc
{
    0xffff, 
    &Data_234c6a58[0], //Menu_Item* Data_4; //4
    &Data_234c6a58[0], //Menu_Item* Data_8; //8
    0, //&Data_234c56f0[1], //234c5670, //Struct_235fdf74_Inner12* header; //12 = 0xc
    NULL, //Struct_235fdf74_Inner16* help; //16 = 0x10
    &Data_234c5cd4, //int graphicData; //20 = 0x14
    1, //uint8_t maxItem; //0x18 = 24
    0, //int8_t currentItem; //0x19
    graphic_start_job_2_5, //void (*graphicHandler)(); //0x1c
    menu_items_navigate, //void (*onNavigate)(); //0x20
    NULL, //int (*onEnter)(int); //36 = 0x24
    0, //int (*onExit)(UI_Thread_Params*); //0x28
	0, //int Data_0x2c; //44 = 0x2c
	0, //int timeout; //48 = 0x30
	0, //Menu_Item* (*Data_0x34)(struct Menu*); //52 = 0x34
	0, //void* (*Data_0x38)(struct FrontDisplay_Job*); //56 = 0x38
#if 0
0x234c79bc                        dw         0x0085                             ; DATA XREF=0x234c5304
0x234c79be 0000                   movs       r0, r0
0x234c79c0                        dd         0x234c6a58
0x234c79c4                        dd         0x234c6a58
0x234c79c8                        dd         0x234c5670
                              dword_234c79cc:
0x234c79cc                        dd         0x00000000                         ; DATA XREF=dword_234c7870+120
                              dword_234c79d0:
0x234c79d0                        dd         0x234c5cd4                         ; DATA XREF=dword_234c7524+212
0x234c79d4                        db         0x01
0x234c79d5                        db  0x00 ; '.'
0x234c79d6 0000                   movs       r0, r0
0x234c79d8                        dd         graphic_start_job_2_5
0x234c79dc                        dd         menu_items_navigate+1
#endif
//234C79F8
};



static uint8_t Data_23799814[80]; //23799814, size???



/*  /   / 23454624 - todo */
void sub_23454624(int a)
{
#if 1
	console_send_string("sub_23454624 (todo.c): TODO\r\n");
#endif

}


/*  /   / 234548c2 - todo */
int sub_234548c2(UI_Thread_Params* r7, int r3)
{
#if 0
	console_send_string("sub_234548c2 (todo.c): TODO\r\n");
#endif
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_234548c2: r3=%d\r\n", r3);
		console_send_string(debug_string);
	}
#endif

	void* r4;
	int r5 = 1;

	switch (r3)
	{
		case 4:
			//23454942
			r4 = Data_234c5304;
			//->0x234549a2
			break;

		default:
			//234549A6
			break;
	}
	//0x234549a2
	if (r4 == NULL)
	{
		//234549A6
		return 9;
	}
	//0x234549aa
	menu_stack_operate(r4);
	menu_initialize(r4);
	/*sub_2344de56*/sub_2343d51e(r4, r7);

#if 0 //TODO!!!
	frontdisplay_start_text(sub_234546fe);
#endif

	return 0;
}


/* /  / 23454a1a - todo */
static int sub_23454a1a(int a)
{
#if 0
	console_send_string("sub_23454a1a (todo.c): TODO\r\n");
#endif

    text_table_get_string(0xd1/*'Please wait...'*/, &Data_23799814[0], 80);

    return 0;
}

#endif
