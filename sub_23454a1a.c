#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "menu.h"

#ifndef VDR110

#pragma thumb

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c1298; //234c1298
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c134c; //234c134c

extern void sub_2344fa5a(UI_Thread_Params*);

static Menu Data_234c7944; //234c7944
static Menu Data_234c79bc; //234c79bc
static Menu Data_234c7bd8; //234c7bd8
static Menu Data_234c7ea8; //234c7ea8

static uint8_t Data_237997c4[]; //237997c4
static uint8_t Data_23799814[]; //23799814
static uint8_t Data_23799874[]; //23799874
static uint8_t Data_2379989c[]; //2379989c

static int sub_23454562(UI_Thread_Params*);
static int sub_2345458e(UI_Thread_Params*);
static int sub_234549ca(int);
static int sub_23454a1a(int);
static int sub_23454ea0(UI_Thread_Params*);
static int sub_23454f30(UI_Thread_Params*);


//0x234c52dc
static Menu* Data_234c52e0 = &Data_234c7bd8; //234c52e0 +4
static Menu* Data_234c52fc = &Data_234c7944; //234c52fc +0x20
static Menu* Data_234c5304 = &Data_234c79bc; //234c5304 +0x28
Menu* Data_234c5354 = &Data_234c7ea8; //234c5354

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c5468 = //234c5468
{
	9, 4, 0x08, //...
#if 0
0x234c5468                        dw         0x0009                             ; DATA XREF=sub_234552c6+8, 0x234c5608
0x234c546a                        dw         0x0000
0x234c546c                        dd         0x00000004
0x234c5470                        db         0x08
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c5474 = //234c5474
{
	9, 4, 0x04, //...
#if 0
0x234c5474                        dw         0x0009                             ; DATA XREF=sub_234552c6+10, dword_234c4fe4+380, 0x234c5648
0x234c5476 0000                   movs       r0, r0
0x234c5478                        dd         0x00000004
0x234c547c                        db         0x04
#endif
};

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

static Graphic_Job_2_5_Item_Text Data_234c54c0 = //234c54c0
{
    0, 0x00d8, 0x00d1, 0x0194, 0x00f3, 0x01, 0x06, 0x02, 0x00, &Data_237997c4[0], 0, 0, 0
#if 0
0x234c54c0                        db         0x00                               ; DATA XREF=0x234c5690
0x234c54c1                        db         0x00
0x234c54c2                        dw         0x00d8
0x234c54c4                        dw         0x00d1
0x234c54c6                        dw         0x0194
0x234c54c8                        dw         0x00f3
0x234c54ca                        db         0x01
0x234c54cb                        db         0x06
0x234c54cc                        db         0x02
0x234c54cd                        db         0x00
0x234c54ce 0000                   movs       r0, r0
0x234c54d0                        dd         0x237997c4
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c54d8 = //234c54d8
{
    0, 0x00e2, 0x0103, 0x0131, 0x0190, 0x01, 0x04, 0x09, 0x01, &Data_23799874[0], 0, 0, 0
#if 0
0x234c54d8                        db         0x00                               ; DATA XREF=0x234c5610
0x234c54d9                        db         0x00
0x234c54da                        dw         0x00e2
0x234c54dc                        dw         0x0103
0x234c54de                        dw         0x0131
0x234c54e0                        dw         0x0190
0x234c54e2                        db         0x01
0x234c54e3                        db         0x04
0x234c54e4                        db         0x09
0x234c54e5                        db         0x01
0x234c54e6 0000                   movs       r0, r0
0x234c54e8                        dd         0x23799874
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c54f0 = //234c54f0
{
    0, 0x0145, 0x0103, 0x0194, 0x0190, 0x01, 0x04, 0x09, 0x01, &Data_2379989c[0], 0, 0, 0
#if 0
0x234c54f0                        db         0x00                               ; DATA XREF=0x234c5650
0x234c54f1                        db         0x00
0x234c54f2                        dw         0x0145
0x234c54f4                        dw         0x0103
0x234c54f6                        dw         0x0194
0x234c54f8                        dw         0x0190
0x234c54fa                        db         0x01
0x234c54fb                        db         0x04
0x234c54fc                        db         0x09
0x234c54fd                        db         0x01
0x234c54fe 0000                   movs       r0, r0
0x234c5500                        dd         0x2379989c
#endif
};

static Graphic_Job_2_5_Item Data_234c55b0[] = //234c55b0
{
	{0}, //[0] = 234c55b0
	{1, 0, 0, 0/*Data_8*/, 0x00ce, 0x00fa, 0x0063, 0x0032, 0, &Data_234c5468/*Data_0x18*/, 9, 0, &Data_234c54d8/*Data_0x20*/}, //[1] = 234C55F0
#if 0
0x234c55f0                        db         0x01                               ; DATA XREF=0x234c6a5c
0x234c55f1                        db  0x00 ; '.'
0x234c55f2 0000                   movs       r0, r0
0x234c55f4                        dd         0x234c5484
0x234c55f8 0000                   movs       r0, r0
0x234c55fa 0000                   movs       r0, r0
0x234c55fc                        dw         0x00ce
0x234c55fe                        dw         0x00fa
0x234c5600                        dw         0x0063
0x234c5602                        dw         0x0032
0x234c5604 0000                   movs       r0, r0
0x234c5606 0000                   movs       r0, r0
0x234c5608                        dd         0x234c5468
0x234c560c                        dw         0x0009
0x234c560e 0000                   movs       r0, r0
0x234c5610                        dd         0x234c54d8
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0131, 0x00fa, 0x0063, 0x0032, 0, &Data_234c5474/*Data_0x18*/, 9, 0, &Data_234c54f0/*Data_0x20*/}, //[2] = 234C5630
#if 0
0x234c5630                        db         0x01                               ; DATA XREF=0x234c6a88
0x234c5631                        db  0x00 ; '.'
0x234c5632 0000                   movs       r0, r0
0x234c5634                        dd         0x234c5488
0x234c5638 0000                   movs       r0, r0
0x234c563a 0000                   movs       r0, r0
0x234c563c                        dw         0x0131                             ; DATA XREF=dword_234c5170+248
0x234c563e                        dw         0x00fa
0x234c5640                        dw         0x0063                             ; DATA XREF=dword_234c5170+252
0x234c5642                        dw         0x0032
0x234c5644                        db  0x00 ; '.'
0x234c5645                        db  0x00 ; '.'
0x234c5646                        db         0x00
0x234c5647                        db  0x00 ; '.'
0x234c5648                        dd         0x234c5474
0x234c564c                        dw         0x0009
0x234c564e 0000                   movs       r0, r0
0x234c5650                        dd         0x234c54f0
#endif
	{1, 0, 0, 0/*Data_8*/, 0x00ce, 0x00ce, 0x00c6, 0x002b, 0, &Data_234c1298/*Data_0x18*/, 2, 0, &Data_234c54c0/*Data_0x20*/}, //[3] = 234C5670: header
#if 0
0x234c5670                        db         0x01                               ; DATA XREF=0x234c79c8, 0x234c7a04, 0x234c7ba8, dword_234c7f2c
0x234c5671                        db  0x00 ; '.'
0x234c5672 0000                   movs       r0, r0
0x234c5674                        dd         0x234c5480
0x234c5678                        dd         0x00000000
0x234c567c                        dw         0x00ce
0x234c567e                        dw         0x00ce
0x234c5680                        dw         0x00c6
0x234c5682                        dw         0x002b
0x234c5684 0000                   movs       r0, r0
0x234c5686 0000                   movs       r0, r0
0x234c5688                        dd         0x234c1298
0x234c568c                        dw         0x0002
0x234c568e 0000                   movs       r0, r0
0x234c5690                        dd         0x234c54c0
#endif
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
	//[0]
	{
		0x006e, //'Ja'
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c55b0[1], //234c55f0,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_23454ea0, //void* onEvent; //0x1c = 28
		sub_2344fa5a, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C6A84
#if 0
0x234c6a58                        dw         0x006e                             ; DATA XREF=0x234c79c0, 0x234c79c4
0x234c6a5a                        dw         0xffff
0x234c6a5c                        dd         0x234c55f0
0x234c6a60 0000                   movs       r0, r0
0x234c6a62 0000                   movs       r0, r0
0x234c6a64 0000                   movs       r0, r0
0x234c6a66 0000                   movs       r0, r0
0x234c6a68 0000                   movs       r0, r0
0x234c6a6a 0000                   movs       r0, r0
0x234c6a6c 0000                   movs       r0, r0
0x234c6a6e 0000                   movs       r0, r0
0x234c6a70 0000                   movs       r0, r0
0x234c6a72 0000                   movs       r0, r0
0x234c6a74                        dd         sub_23454ea0+1
0x234c6a78                        dd         sub_2344fa5a+1
#endif
    },
	//[1]
	{
		0x006f, //'Nein'
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c55b0[2], //234c5630,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_2345458e, //void* onEvent; //0x1c = 28
		sub_2344fa5a, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C6AB0
#if 0
0x234c6a84                        dw         0x006f
0x234c6a86                        dw         0xffff
0x234c6a88                        dd         0x234c5630
0x234c6a8c 0000                   movs       r0, r0
0x234c6a8e 0000                   movs       r0, r0
0x234c6a90 0000                   movs       r0, r0
0x234c6a92 0000                   movs       r0, r0
0x234c6a94 0000                   movs       r0, r0
0x234c6a96 0000                   movs       r0, r0
0x234c6a98 0000                   movs       r0, r0
0x234c6a9a 0000                   movs       r0, r0
0x234c6a9c 0000                   movs       r0, r0
0x234c6a9e 0000                   movs       r0, r0
0x234c6aa0                        dd         sub_2345458e+1
0x234c6aa4                        dd         sub_2344fa5a+1                     ; DATA XREF=dword_234c680c+88
#endif
    }
};

static Menu_Item Data_234c6ab0[] = //234c6ab0
{
	//[0]
	{
		0x006e, //'Ja'
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c55b0[1], //234c55f0,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_23454f30, //void* onEvent; //0x1c = 28
		sub_2344fa5a, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C6ADC
#if 0
0x234c6ab0                        dw         0x006e                             ; DATA XREF=0x234c7948, 0x234c794c
0x234c6ab2                        dw         0xffff
0x234c6ab4                        dd         0x234c55f0
0x234c6ab8 0000                   movs       r0, r0
0x234c6aba 0000                   movs       r0, r0
0x234c6abc                        dd         0x00000000                         ; DATA XREF=dword_234c6914+88
0x234c6ac0 0000                   movs       r0, r0
0x234c6ac2 0000                   movs       r0, r0
0x234c6ac4 0000                   movs       r0, r0
0x234c6ac6 0000                   movs       r0, r0
0x234c6ac8 0000                   movs       r0, r0
0x234c6aca 0000                   movs       r0, r0
0x234c6acc                        dd         sub_23454f30+1
0x234c6ad0                        dd         sub_2344fa5a+1
#endif
    },
	//[1]
	{
		0x006f, //'Nein'
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c55b0[2], //234c5630,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_23454562, //void* onEvent; //0x1c = 28
		sub_2344fa5a, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C6ADC
#if 0
0x234c6adc                        dw         0x006f
0x234c6ade                        dw         0xffff
0x234c6ae0                        dd         0x234c5630
0x234c6ae4 0000                   movs       r0, r0
0x234c6ae6 0000                   movs       r0, r0
0x234c6ae8 0000                   movs       r0, r0
0x234c6aea 0000                   movs       r0, r0
0x234c6aec 0000                   movs       r0, r0
0x234c6aee 0000                   movs       r0, r0
0x234c6af0 0000                   movs       r0, r0
0x234c6af2 0000                   movs       r0, r0
0x234c6af4 0000                   movs       r0, r0
0x234c6af6 0000                   movs       r0, r0
0x234c6af8                        dd         sub_23454562+1
0x234c6afc                        dd         sub_2344fa5a+1
#endif
	}
};

static Menu Data_234c7944 = //234c7944
{
    0x0085, //'Speichern?' / 'Save?'
    &Data_234c6ab0[0], //Menu_Item* Data_4; //4
    &Data_234c6ab0[0], //Menu_Item* Data_8; //8
    &Data_234c55b0[3], //234c5670, //Struct_235fdf74_Inner12* header; //12 = 0xc
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
0x234c7944                        dw         0x0085                             ; DATA XREF=0x234c52fc
0x234c7946 0000                   movs       r0, r0
0x234c7948                        dd         0x234c6ab0
0x234c794c                        dd         0x234c6ab0
0x234c7950                        dd         0x234c5670
0x234c7954 0000                   movs       r0, r0
0x234c7956 0000                   movs       r0, r0
0x234c7958                        dd         0x234c5cd4
0x234c795c                        db         0x01
0x234c795d                        db  0x00 ; '.'
0x234c795e 0000                   movs       r0, r0
0x234c7960                        dd         graphic_start_job_2_5
0x234c7964                        dd         menu_items_navigate+1
#endif
//234C7980
};

static Menu Data_234c79bc = //234c79bc
{
    0x0085, //'Speichern?' / 'Save?'
    &Data_234c6a58[0], //Menu_Item* Data_4; //4
    &Data_234c6a58[0], //Menu_Item* Data_8; //8
    &Data_234c55b0[3], //234c5670, //Struct_235fdf74_Inner12* header; //12 = 0xc
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
0x234c79cc                        dd         0x00000000                         ; DATA XREF=dword_234c7870+120
0x234c79d0                        dd         0x234c5cd4                         ; DATA XREF=dword_234c7524+212
0x234c79d4                        db         0x01
0x234c79d5                        db  0x00 ; '.'
0x234c79d6 0000                   movs       r0, r0
0x234c79d8                        dd         graphic_start_job_2_5
0x234c79dc                        dd         menu_items_navigate+1
#endif
//234C79F8
};

static Menu Data_234c7bd8 = //234c7bd8
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
    sub_234549ca, //int (*onEnter)(int); //36 = 0x24
    0, //int (*onExit)(UI_Thread_Params*); //0x28
	0, //int Data_0x2c; //44 = 0x2c
	0, //int timeout; //48 = 0x30
	0, //Menu_Item* (*Data_0x34)(struct Menu*); //52 = 0x34
	0, //void* (*Data_0x38)(struct FrontDisplay_Job*); //56 = 0x38
#if 0
0x234c7bd8                        dw         0xffff                             ; DATA XREF=sub_23454a2a+6, sub_23454a2a+12, sub_23454a5c+12, sub_23454a5c+18, sub_23454a98+12, sub_23454a98+18, sub_23454ace+12, sub_23454ace+18, sub_23454b04+4, sub_23454b04+10, sub_23454b48+6
0x234c7bda                        dw         0x0000
0x234c7bdc                        dd         0x00000000
0x234c7be0                        dd         0x00000000
0x234c7be4                        dd         0x234c5730
0x234c7be8                        dd         0x00000000                         ; DATA XREF=dword_234c7af8+12
0x234c7bec                        dd         0x234c5cf8                         ; DATA XREF=sub_23454a2a+14, sub_23454a5c+20, sub_23454a98+20, sub_23454ace+20, sub_23454b04+12, sub_23454b48+14, sub_23454b8e+12, sub_23454bc0+12, sub_23454bf2+12, sub_23454c1c+12, sub_23454c52+12
0x234c7bf0 0000                   movs       r0, r0
0x234c7bf2 0000                   movs       r0, r0
0x234c7bf4                        dd         graphic_start_job_2_5
0x234c7bf8 0000                   movs       r0, r0
0x234c7bfa 0000                   movs       r0, r0
0x234c7bfc                        dd         sub_234549ca+1
#endif
//234C7EE4
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


static uint8_t Data_237997c4[80]; //237997c4, size???
static uint8_t Data_23799814[80]; //23799814, size???
static Graphic_Queue_Item Data_23799864; //23799864
static uint8_t Data_23799874[40]; //23799874
static uint8_t Data_2379989c[40]; //2379989c, size???


/* /  / 23454562 - todo  */
static int sub_23454562(UI_Thread_Params *a)
{
#if 0
	console_send_string("sub_23454562 (todo.c): TODO\r\n");
#endif

	Struct_2340bf0c sp;

	/*sub_2340e9e8*/sub_2340bf0c(&sp);
	/*sub_2340d8b0*/sub_2340add4(0x40300000);
	channel_load_lists();

	if (sp.bData_0x31 & (1 << 1))
	{
		/*sub_234109e8*/sub_2344f9a8(0);	
	}

	sub_23496cb2();

	return 0;
}


/* /  / 2345458e - todo */
static int sub_2345458e(UI_Thread_Params *a)
{
#if 1
	console_send_string("sub_2345458e (todo.c): TODO\r\n");
#endif

	return 0;
}


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

		case 5:
			//23454946
			r4 = Data_234c52fc;
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


/* /  / 234549ca - todo */
static int sub_234549ca(int a)
{
#if 0
	console_send_string("sub_234549ca (todo.c): TODO\r\n");
#endif

	text_table_get_string(0x4e/*'Einstellungen werden gespeichert, bitte warten...'*/, 
		&Data_23799814[0], 80);

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


/* /  / 23454ea0 - todo */
static int sub_23454ea0(UI_Thread_Params* a)
{
#if 1
	console_send_string("sub_23454ea0 (todo.c): TODO\r\n");
#endif

	menu_initialize(Data_234c52e0);

	graphic_start_job_2_5(&Data_23799864, Data_234c52e0->graphicData);

	sub_234552e8();

	sub_2348fb6e();

	sub_234543a0();

	return 0;
}


/* /  / 23454f30 - todo */
static int sub_23454f30(UI_Thread_Params* a)
{
#if 1
	console_send_string("sub_23454f30 (todo.c): TODO\r\n");
#endif

	Struct_2340bf0c sp4;

	/*sub_2340e9e8*/sub_2340bf0c(&sp4);

	menu_initialize(Data_234c52e0);
	graphic_start_job_2_5(&Data_23799864, Data_234c52e0->graphicData);

	channel_write_database();

	if (sp4.bData_0x31 & (1 << 1))
	{
		//0x23454f58
		/*sub_234109b8*/sub_2344f978(1);
		/*sub_234109e8*/sub_2344f9a8(0);
	}
	//loc_23454f64
	sub_23496cb2();

	return 0;
}


/* /  / 234552e8 - todo */
void sub_234552e8()
{
#if 1
	console_send_string("sub_234552e8 (todo.c): TODO\r\n");
#endif

	channel_write_database();
	channel_load_lists();
}


#endif
