#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "menu.h"

#ifndef VDR110

#pragma thumb

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c

extern struct Menu_Data* sub_2344de8e(void);
extern void sub_2344ef18(UI_Thread_Params*);

static Menu Data_234cd288; //234cd288

static void sub_23457762(Menu_Item*);
static int sub_234577be();
static void sub_234579ee();
static void sub_23457a02();
static int sub_23457a04(UI_Thread_Params*);
static int sub_23457a12(int);


//0x234cc2a4
static Menu* Data_234cc2b0 = &Data_234cd288; //234cc2b0 +0xc

static Graphic_Job_2_5_Item Data_234cc2e4[] = //234cc2e4
{
	{0}, //[0] = 234cc2e4 
	{0}, //[1] = 234CC324 
	{0}, //[2] = 234CC364 
	{0}, //[3] = 234CC3A4 
    //234CC3E4
};

static Menu_Item Data_234cc420[] = //234cc420
{
	//[0]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234cc2e4[1], //234cc324,
		}, //int fill_4[5]; //4
		sub_23457762, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_234577be, //void* onEvent; //0x1c = 28
		sub_2344ef18, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EE378
#if 0
0x234cc420                        dw         0xffff                             ; DATA XREF=sub_234577be+10, dword_23457864, sub_23457918+74, dword_23457abc, 0x234cd28c, 0x234cd290
0x234cc422                        dw         0xffff
0x234cc424                        dd         0x234cc324                         ; DATA XREF=sub_23457918+78
0x234cc428 0000                   movs       r0, r0
0x234cc42a 0000                   movs       r0, r0
0x234cc42c 0000                   movs       r0, r0
0x234cc42e 0000                   movs       r0, r0
0x234cc430 0000                   movs       r0, r0
0x234cc432 0000                   movs       r0, r0
0x234cc434 0000                   movs       r0, r0
0x234cc436 0000                   movs       r0, r0
0x234cc438                        dd         sub_23457762+1
0x234cc43c                        dd         sub_234577be+1
0x234cc440                        dd         sub_2344ef18+1
#endif
    },
};


static Graphic_Job_2_5 Data_234cd084 = //234cd084
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x003e, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234cc2e4[0], //Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	0x10, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	4, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
	sub_23457a02, //void (*unlock)(); //0x1c
	sub_234579ee, //void (*lock)(); //0x20
#if 0
0x234cd084                        db         0x00                               ; DATA XREF=sub_23457a3e+10, dword_234cd29c
0x234cd085                        db         0xfa
0x234cd086                        dw         0x003e
0x234cd088                        db         0x04
0x234cd089                        db  0x00 ; '.'
0x234cd08a 0000                   movs       r0, r0
0x234cd08c                        dd         0x234cc2e4
0x234cd090                        dd         menu_main_graphic_color_data
0x234cd094                        db         0x10
0x234cd095                        db  0x00 ; '.'
0x234cd096 0000                   movs       r0, r0
0x234cd098                        dd         0x00000000
0x234cd09c                        db         0x04
0x234cd09d                        db  0x01 ; '.'                                ; DATA XREF=sub_23457a3e+12
0x234cd09e 0000                   movs       r0, r0
0x234cd0a0                        dd         sub_23457a02+1
0x234cd0a4                        dd         sub_234579ee+1
#endif
};


static Menu Data_234cd288 = //234cd288
{
    0x012d, //'PIN eingeben' / 'Enter PIN'
    &Data_234cc420[0], //Menu_Item* Data_4; //4
    &Data_234cc420[0], //Menu_Item* Data_8; //8
    &Data_234cc2e4[2], //234cc364, //Struct_235fdf74_Inner12* header; //12 = 0xc
    0, /*&Data_234c3414*/ //Struct_235fdf74_Inner16* help; //16 = 0x10
    &Data_234cd084, //int graphicData; //20 = 0x14
    0, //uint8_t maxItem; //0x18 = 24
    0, //int8_t currentItem; //0x19
    graphic_start_job_2_5, //void (*graphicHandler)(); //0x1c
    NULL, //void (*onNavigate)(); //0x20
    sub_23457a12, //int (*onEnter)(int); //36 = 0x24
    sub_23457a04, //int (*onExit)(UI_Thread_Params*); //0x28
#if 0
0x234cd288                        dw         0x012d                             ; DATA XREF=sub_234577be+20, sub_23457918+26, sub_23457a3e+8, dword_234cc2b0, 0x234cc2c4
0x234cd28a 0000                   movs       r0, r0
0x234cd28c                        dd         0x234cc420
0x234cd290                        dd         0x234cc420
0x234cd294                        dd         0x234cc364                         ; CODE XREF=byte_234cd195+187
0x234cd298 0000                   movs       r0, r0                             ; CODE XREF=byte_234cd195+191
0x234cd29a 0000                   movs       r0, r0
0x234cd29c                        dd         0x234cd084                         ; DATA XREF=sub_23457a3e+10
0x234cd2a0 0000                   movs       r0, r0
0x234cd2a2 0000                   movs       r0, r0
0x234cd2a4                        dd         graphic_start_job_2_5
0x234cd2a8 0000                   movs       r0, r0
0x234cd2aa 0000                   movs       r0, r0
0x234cd2ac                        dd         sub_23457a12+1
0x234cd2b0                        dd         sub_23457a04+11
0x234cd2b4 0000                   movs       r0, r0
0x234cd2b6 0000                   movs       r0, r0
0x234cd2b8                        dd         0x00000000                         ; DATA XREF=byte_234cd195+63
0x234cd2bc 0000                   movs       r0, r0
0x234cd2be 0000                   movs       r0, r0
0x234cd2c0 0000                   movs       r0, r0
0x234cd2c2 0000                   movs       r0, r0
#endif
//234CD2C4
};



/* /  / 23457762 - todo */
static void sub_23457762(Menu_Item* a)
{
#if 1
	console_send_string("sub_23457762 (todo.c): TODO\r\n");
#endif

}


/* /  / 234577be - todo */
int sub_234577be()
{
#if 1
	console_send_string("sub_234577be (todo.c): TODO\r\n");
#endif

    return 0;
}


/* /  / 23457918 - todo */
int sub_23457918()
{
#if 1
	console_send_string("sub_23457918 (todo.c): TODO\r\n");
#endif

    return 0;
}


/* /  / 234579ee - todo */
void sub_234579ee()
{
#if 1
	console_send_string("sub_234579ee (todo.c): TODO\r\n");
#endif

}


/* /  / 23457a02 - todo */
void sub_23457a02()
{
#if 1
	console_send_string("sub_23457a02 (todo.c): TODO\r\n");
#endif

}


/* /  / 23457a04 - todo */
int sub_23457a04(UI_Thread_Params* a)
{
#if 1
	console_send_string("sub_23457a04 (todo.c): TODO\r\n");
#endif

    return 0;
}


/* /  / 23457a12 - todo */
int sub_23457a12(int a)
{
#if 1
    console_send_string("sub_23457a12 (todo.c): TODO\r\n");
#endif

    return 0;
}
    

/* /  / 23457a3e - todo */
int menu_pin_entry(UI_Thread_Params* pThreadParams, int r7)
{
#if 0
	console_send_string("menu_pin_entry (todo.c): TODO\r\n");
#endif

    uint8_t* r4 = &Data_234cc2b0->graphicData->bData_0x19;

    if (sub_2344de8e()->menu_stack[0] != NULL)
    {
        *r4 = 0;
    }
    else
    {
        *r4 = 1;
    }

    if (r7 != 0)
    {
        Data_234cc2b0->Data_4->onEvent = sub_23457918;
    }
    else
    {
        Data_234cc2b0->Data_4->onEvent = sub_234577be;
    }

    menu_stack_operate(Data_234cc2b0);
    menu_initialize(Data_234cc2b0);
    /*sub_2344de56*/sub_2343d51e(Data_234cc2b0, pThreadParams);

    return 0;
}


#endif
