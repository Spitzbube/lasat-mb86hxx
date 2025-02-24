#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "menu.h"

#ifndef VDR110

#pragma thumb

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12d4; //234c12d4
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12ec; //234c12ec
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12f8; //234c12f8
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c134c; //234c134c


static Menu Data_234eadf8; //234eadf8
static uint8_t Data_2397083c[]; //2397083c
static uint8_t Data_2397095c[]; //2397095c
static uint8_t Data_23970984[]; //23970984
static uint8_t Data_239709ac[]; //239709ac
static uint8_t Data_239709d4[]; //239709d4
static uint8_t Data_239709fc[]; //239709fc

extern int sub_2348e352(int);
extern int sub_234929f6(int);

//234ea514
static Menu* Data_234ea514 = &Data_234eadf8; //234ea514

static Graphic_Job_2_5_Item_Text Data_234ea538 = //234ea538
{
    0, 0x0051, 0x002c, 0x014d, 0x004f, 0x01, 0x06, 0x02, 0x00, &Data_2397083c[0], 0, 0, 0
#if 0
0x234ea538                        db         0x00                               ; DATA XREF=0x234ea658
0x234ea539                        db         0x00
0x234ea53a                        dw         0x0051
0x234ea53c                        dw         0x002c
0x234ea53e                        dw         0x014d
0x234ea540                        dw         0x004f
0x234ea542                        db         0x01
0x234ea543                        db         0x06
0x234ea544                        db         0x02
0x234ea545                        db         0x00
0x234ea546 0000                   movs       r0, r0
0x234ea548                        dd         0x2397083c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ea568 = //234ea568
{
    0, 0x0051, 0x0064, 0x014d, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_2397095c[0], 0, 0, 0
#if 0
0x234ea568                        db         0x00                               ; DATA XREF=0x234ea758
0x234ea569                        db         0x00
0x234ea56a                        dw         0x0051
0x234ea56c                        dw         0x0064
0x234ea56e                        dw         0x014d
0x234ea570                        dw         0x0080
0x234ea572                        db         0x01
0x234ea573                        db         0x04
0x234ea574                        db         0x09
0x234ea575                        db         0x01
0x234ea576 0000                   movs       r0, r0
0x234ea578                        dd         0x2397095c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ea580 = //234ea580
{
    0, 0x0051, 0x0084, 0x014d, 0x00a0, 0x01, 0x04, 0x09, 0x01, &Data_23970984[0], 0, 0, 0
#if 0
0x234ea580                        db         0x00                               ; DATA XREF=0x234ea798
0x234ea581                        db         0x00
0x234ea582                        dw         0x0051
0x234ea584                        dw         0x0084
0x234ea586                        dw         0x014d
0x234ea588                        dw         0x00a0
0x234ea58a                        db         0x01
0x234ea58b                        db         0x04
0x234ea58c                        db         0x09
0x234ea58d                        db         0x01
0x234ea58e 0000                   movs       r0, r0
0x234ea590                        dd         0x23970984
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ea598 = //234ea598
{
    0, 0x0051, 0x00a4, 0x014d, 0x00c0, 0x01, 0x04, 0x09, 0x01, &Data_239709ac[0], 0, 0, 0
#if 0
0x234ea598                        db         0x00                               ; DATA XREF=0x234ea7d8
0x234ea599                        db         0x00
0x234ea59a                        dw         0x0051
0x234ea59c                        dw         0x00a4
0x234ea59e                        dw         0x014d
0x234ea5a0                        dw         0x00c0                             ; DATA XREF=menu_general_settings_items+624
0x234ea5a2                        db         0x01
0x234ea5a3                        db         0x04
0x234ea5a4                        db         0x09
0x234ea5a5                        db         0x01
0x234ea5a6 0000                   movs       r0, r0
0x234ea5a8                        dd         0x239709ac
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ea5b0 = //234ea5b0
{
    0, 0x0051, 0x00c4, 0x014d, 0x00e0, 0x01, 0x04, 0x09, 0x01, &Data_239709d4[0], 0, 0, 0
#if 0
0x234ea5b0                        db         0x00                               ; DATA XREF=0x234ea818
0x234ea5b1                        db         0x00
0x234ea5b2                        dw         0x0051
0x234ea5b4                        dw         0x00c4
0x234ea5b6                        dw         0x014d
0x234ea5b8                        dw         0x00e0
0x234ea5ba                        db         0x01
0x234ea5bb                        db         0x04
0x234ea5bc                        db         0x09
0x234ea5bd                        db         0x01
0x234ea5be 0000                   movs       r0, r0
0x234ea5c0                        dd         0x239709d4
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ea5c8 = //234ea5c8
{
    0, 0x0051, 0x00e4, 0x014d, 0x0100, 0x01, 0x04, 0x09, 0x01, &Data_239709fc[0], 0, 0, 0
#if 0
0x234ea5c8                        db         0x00                               ; DATA XREF=0x234ea858
0x234ea5c9                        db         0x00
0x234ea5ca                        dw         0x0051
0x234ea5cc                        dw         0x00e4
0x234ea5ce                        dw         0x014d
0x234ea5d0                        dw         0x0100
0x234ea5d2                        db         0x01
0x234ea5d3                        db         0x04
0x234ea5d4                        db         0x09
0x234ea5d5                        db         0x01
0x234ea5d6 0000                   movs       r0, r0
0x234ea5d8                        dd         0x239709fc                         ; DATA XREF=menu_general_settings+88
#endif
};

static Graphic_Job_2_5_Item Data_234ea5f8[] = //234ea5f8
{
	{0}, //[0] = 234ea5f8 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0029, 0x0110, 0x0026, 0, &Data_234c134c/*Data_0x18*/, 2, 0, &Data_234ea538/*Data_0x20*/}, //[1] = 234EA638: header
#if 0
0x234ea638                        db         0x01                               ; DATA XREF=0x234eae04
0x234ea639                        db  0x00 ; '.'
0x234ea63a 0000                   movs       r0, r0
0x234ea63c                        dd         0x234ea524
0x234ea640 0000                   movs       r0, r0
0x234ea642 0000                   movs       r0, r0
0x234ea644                        dw         0x003d
0x234ea646                        dw         0x0029
0x234ea648                        dw         0x0110
0x234ea64a                        dw         0x0026
0x234ea64c 0000                   movs       r0, r0
0x234ea64e 0000                   movs       r0, r0
0x234ea650                        dd         0x234c134c
0x234ea654                        dw         0x0002
0x234ea656 0000                   movs       r0, r0
0x234ea658                        dd         0x234ea538
#endif
	{0}, //[2] = 234EA678 
	{0}, //[3] = 234EA6B8 
	{0}, //[4] = 234EA6F8 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0060, 0x0110, 0x0020, 0, &Data_234c12f8/*Data_0x18*/, 9, 0, &Data_234ea568/*Data_0x20*/}, //[5] = 234EA738: 'Edit main list'
#if 0
0x234ea738                        db         0x01                               ; DATA XREF=0x234eac44
0x234ea739                        db  0x00 ; '.'
0x234ea73a 0000                   movs       r0, r0
0x234ea73c                        dd         0x234ea530
0x234ea740 0000                   movs       r0, r0
0x234ea742 0000                   movs       r0, r0
0x234ea744                        dw         0x003d
0x234ea746                        dw         0x0060
0x234ea748                        dw         0x0110
0x234ea74a                        dw         0x0020
0x234ea74c 0000                   movs       r0, r0
0x234ea74e 0000                   movs       r0, r0
0x234ea750                        dd         0x234c12f8
0x234ea754                        dw         0x0009
0x234ea756 0000                   movs       r0, r0
0x234ea758                        dd         0x234ea568
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0080, 0x0110, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234ea580/*Data_0x20*/}, //[6] = 234EA778: 'Edit favourites list'
#if 0
0x234ea778                        db         0x01                               ; DATA XREF=0x234eac70
0x234ea779                        db  0x00 ; '.'
0x234ea77a 0000                   movs       r0, r0
0x234ea77c                        dd         0x234ea530
0x234ea780 0000                   movs       r0, r0
0x234ea782 0000                   movs       r0, r0
0x234ea784                        dw         0x003d
0x234ea786                        dw         0x0080
0x234ea788                        dw         0x0110
0x234ea78a                        dw         0x0020
0x234ea78c 0000                   movs       r0, r0
0x234ea78e 0000                   movs       r0, r0
0x234ea790                        dd         0x234c12d4
0x234ea794                        dw         0x0009
0x234ea796 0000                   movs       r0, r0
0x234ea798                        dd         0x234ea580
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x00a0, 0x0110, 0x0020, 0, &Data_234c12ec/*Data_0x18*/, 9, 0, &Data_234ea598/*Data_0x20*/}, //[7] = 234EA7B8: 'Delete all channels'
#if 0
0x234ea7b8                        db         0x01                               ; DATA XREF=sub_23490bd0+44, sub_23490bd0+48, dword_234eac9c
0x234ea7b9                        db  0x00 ; '.'
0x234ea7ba 0000                   movs       r0, r0
0x234ea7bc                        dd         0x234ea530
0x234ea7c0 0000                   movs       r0, r0                             ; DATA XREF=dword_234ea5d8+292
0x234ea7c2 0000                   movs       r0, r0
0x234ea7c4                        dw         0x003d
0x234ea7c6                        dw         0x00a0
0x234ea7c8                        dw         0x0110
0x234ea7ca                        dw         0x0020
0x234ea7cc 0000                   movs       r0, r0
0x234ea7ce 0000                   movs       r0, r0
0x234ea7d0                        dd         0x234c12ec
0x234ea7d4                        dw         0x0009
0x234ea7d6 0000                   movs       r0, r0
0x234ea7d8                        dd         0x234ea598
#endif
	{0, 0, 0, 0/*Data_8*/, 0x3d, 0x00c0, 0x0110, 0x0020, 0, &Data_234c12ec/*Data_0x18*/, 9, 0, &Data_234ea5b0/*Data_0x20*/}, //[8] = 234EA7F8: 'Internet Radio'
#if 0
0x234ea7f8                        db         0x00                               ; DATA XREF=0x234eacc8
0x234ea7f9                        db  0x00 ; '.'
0x234ea7fa 0000                   movs       r0, r0
0x234ea7fc                        dd         0x234ea530
0x234ea800 0000                   movs       r0, r0
0x234ea802 0000                   movs       r0, r0
0x234ea804                        dw         0x003d
0x234ea806                        dw         0x00c0
0x234ea808                        dw         0x0110
0x234ea80a                        dw         0x0020
0x234ea80c 0000                   movs       r0, r0
0x234ea80e 0000                   movs       r0, r0
0x234ea810                        dd         0x234c12ec
0x234ea814                        dw         0x0009
0x234ea816 0000                   movs       r0, r0
0x234ea818                        dd         0x234ea5b0
#endif
	{0, 0, 0, 0/*Data_8*/, 0x3d, 0x00e0, 0x0110, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234ea5c8/*Data_0x20*/}, //[9] = 234EA838
#if 0
0x234ea838                        db         0x00                               ; DATA XREF=0x234eacf4
0x234ea839                        db  0x00 ; '.'
0x234ea83a 0000                   movs       r0, r0
0x234ea83c                        dd         0x234ea530
0x234ea840 0000                   movs       r0, r0
0x234ea842 0000                   movs       r0, r0
0x234ea844                        dw         0x003d
0x234ea846                        dw         0x00e0
0x234ea848                        dw         0x0110
0x234ea84a                        dw         0x0020
0x234ea84c 0000                   movs       r0, r0
0x234ea84e 0000                   movs       r0, r0
0x234ea850                        dd         0x234c12d4
0x234ea854                        dw         0x0009
0x234ea856 0000                   movs       r0, r0
0x234ea858                        dd         0x234ea5c8
#endif
	{0}, //[10] = 234EA878 
	{0}, //[11] = 234EA8B8 
    //234EA8F8
}; 

static Graphic_Job_2_5 Data_234eabf8 = //234eabf8
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x000b, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234ea5f8[0], //Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	0x10, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	12, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
#if 0
0x234eabf8                        db         0x00                               ; DATA XREF=sub_23490bd0+12, dword_234eae0c
0x234eabf9                        db         0xfa
0x234eabfa                        dw         0x000b
0x234eabfc                        db         0x04                               ; DATA XREF=dword_234ea5d8+1152
0x234eabfd                        db  0x00 ; '.'
0x234eabfe 0000                   movs       r0, r0
0x234eac00                        dd         0x234ea5f8                         ; DATA XREF=dword_234ea5d8+1380
0x234eac04                        dd         menu_main_graphic_color_data
0x234eac08                        db         0x10
0x234eac09                        db  0x00 ; '.'
0x234eac0a 0000                   movs       r0, r0
0x234eac0c                        dd         0x00000000
0x234eac10                        db         0x0c
0x234eac11                        db         0x01
#endif
};

static Menu_Item Data_234eac40[] = //234eac40
{
	//[0]
	{
		0x007f, //'Gesamtliste bearbeiten' / 'Edit main list'
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234ea5f8[5], //234ea738,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_2348e352, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EAC6C
#if 0
0x234eac40                        dw         0x007f                             ; DATA XREF=sub_23490bd0+10, sub_23490bd0+16, dword_234ea5d8+1444, 0x234eadfc, dword_234eae00
0x234eac42                        dw         0x00f3
0x234eac44                        dd         0x234ea738
0x234eac48 0000                   movs       r0, r0
0x234eac4a 0000                   movs       r0, r0
0x234eac4c 0000                   movs       r0, r0
0x234eac4e 0000                   movs       r0, r0
0x234eac50 0000                   movs       r0, r0
0x234eac52 0000                   movs       r0, r0
0x234eac54 0000                   movs       r0, r0
0x234eac56 0000                   movs       r0, r0
0x234eac58 0000                   movs       r0, r0
0x234eac5a 0000                   movs       r0, r0
0x234eac5c                        dd         sub_2348e352+1                     ; DATA XREF=sub_23490bd0+20
0x234eac60                        dd         menu_event_thread+1
#endif
    },
	//[1]
	{
		0x0059, //'Favoritenliste bearbeiten' / 'Edit favourites list'
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234ea5f8[6], //234ea778,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23496d2a, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EAC98
#if 0
0x234eac6c                        dw         0x0059                             ; DATA XREF=sub_23490bd0+22, sub_23490bd0+26
0x234eac6e                        dw         0x00f3
0x234eac70                        dd         0x234ea778
0x234eac74 0000                   movs       r0, r0
0x234eac76 0000                   movs       r0, r0
0x234eac78 0000                   movs       r0, r0
0x234eac7a 0000                   movs       r0, r0
0x234eac7c 0000                   movs       r0, r0
0x234eac7e 0000                   movs       r0, r0
0x234eac80 0000                   movs       r0, r0
0x234eac82 0000                   movs       r0, r0
0x234eac84 0000                   movs       r0, r0
0x234eac86 0000                   movs       r0, r0
0x234eac88                        dd         sub_23496d2a+1                     ; DATA XREF=sub_23490bd0+30
0x234eac8c                        dd         menu_event_thread+1
#endif
    },
	//[2]
	{
		0x010b, //'Alle Programme l▒schen' / 'Delete all channels'
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234ea5f8[7], //234ea7b8,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_234929f6, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EACC4
#if 0
0x234eac98                        dw         0x010b                             ; DATA XREF=sub_23490bd0+32, sub_23490bd0+38
0x234eac9a                        dw         0x00f3
0x234eac9c                        dd         0x234ea7b8                         ; DATA XREF=sub_23490bd0+44, dword_234ea5d8+1216
0x234eaca0 0000                   movs       r0, r0
0x234eaca2 0000                   movs       r0, r0
0x234eaca4 0000                   movs       r0, r0
0x234eaca6 0000                   movs       r0, r0
0x234eaca8 0000                   movs       r0, r0
0x234eacaa 0000                   movs       r0, r0
0x234eacac 0000                   movs       r0, r0
0x234eacae 0000                   movs       r0, r0
0x234eacb0 0000                   movs       r0, r0
0x234eacb2 0000                   movs       r0, r0
0x234eacb4                        dd         sub_234929f6+1                     ; DATA XREF=sub_23490bd0+42
0x234eacb8                        dd         menu_event_thread+1
#endif
    },
	//[3]
	{
		0x01b2, //'Internet Radio' / 'Internet Radio'
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234ea5f8[8], //234ea7f8,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_2349b64e, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EACF0
#if 0
0x234eacc4                        dw         0x01b2                             ; DATA XREF=sub_23490bd0+46, sub_23490bd0+54
0x234eacc6                        dw         0x00f3
0x234eacc8                        dd         0x234ea7f8
0x234eaccc 0000                   movs       r0, r0
0x234eacce 0000                   movs       r0, r0
0x234eacd0 0000                   movs       r0, r0
0x234eacd2 0000                   movs       r0, r0
0x234eacd4 0000                   movs       r0, r0
0x234eacd6 0000                   movs       r0, r0
0x234eacd8 0000                   movs       r0, r0
0x234eacda 0000                   movs       r0, r0
0x234eacdc 0000                   movs       r0, r0
0x234eacde 0000                   movs       r0, r0
0x234eace0                        dd         sub_2349b64e+1                     ; DATA XREF=sub_23490bd0+58
0x234eace4                        dd         menu_event_thread+1
#endif
    },
	//[4]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234ea5f8[9], //234ea838,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		NULL, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EAD1C
#if 0
0x234eacf0                        dw         0xffff
0x234eacf2                        dw         0x00f3
0x234eacf4                        dd         0x234ea838
0x234eacf8 0000                   movs       r0, r0
0x234eacfa 0000                   movs       r0, r0
0x234eacfc 0000                   movs       r0, r0
0x234eacfe 0000                   movs       r0, r0
0x234ead00 0000                   movs       r0, r0
0x234ead02 0000                   movs       r0, r0
0x234ead04 0000                   movs       r0, r0
0x234ead06 0000                   movs       r0, r0
0x234ead08 0000                   movs       r0, r0
0x234ead0a 0000                   movs       r0, r0
0x234ead0c 0000                   movs       r0, r0
0x234ead0e 0000                   movs       r0, r0
0x234ead10                        dd         menu_event_thread
#endif
    }
};

static Menu Data_234eadf8 = //234eadf8
{
    0x0044, //'Senderliste' / 'Channel list'
    &Data_234eac40[0], //Menu_Item* Data_4; //4
    &Data_234eac40[0], //Menu_Item* Data_8; //8
    &Data_234ea5f8[1], //234ea638, //Struct_235fdf74_Inner12* header; //12 = 0xc
    0, /*&Data_234c3414*/ //Struct_235fdf74_Inner16* help; //16 = 0x10
    &Data_234eabf8, //int graphicData; //20 = 0x14
    4, //uint8_t maxItem; //0x18 = 24
    0, //int8_t currentItem; //0x19
    graphic_start_job_2_5, //void (*graphicHandler)(); //0x1c
    menu_items_navigate, //menu_items_navigate, //void (*onNavigate)(); //0x20
    NULL, //int (*onEnter)(int); //36 = 0x24
    NULL, //int (*onExit)(UI_Thread_Params*); //0x28
#if 0
0x234eadf8                        dw         0x0044                             ; DATA XREF=sub_23490bd0+8, dword_234ea514, 0x234ea518
0x234eadfa 0000                   movs       r0, r0
0x234eadfc                        dd         0x234eac40
0x234eae00                        dd         0x234eac40                         ; DATA XREF=sub_23490bd0+10
0x234eae04                        dd         0x234ea638
0x234eae08                        dd         0x234ea6b8
0x234eae0c                        dd         0x234eabf8                         ; DATA XREF=sub_23490bd0+12
0x234eae10                        db         0x04
0x234eae11                        db  0x00 ; '.'
0x234eae12 0000                   movs       r0, r0
0x234eae14                        dd         graphic_start_job_2_5
0x234eae18                        dd         menu_items_navigate+1
#endif
//234EAE34
};



static uint8_t Data_2397083c[40]; //2397083c, size???
static uint8_t Data_2397095c[40]; //2397095c, size???
static uint8_t Data_23970984[40]; //23970984, size???
static uint8_t Data_239709ac[40]; //239709ac, size???
static uint8_t Data_239709d4[40]; //239709d4, size???
static uint8_t Data_239709fc[40]; //239709fc, size???


/* /  / 23490bd0 - todo */
int sub_23490bd0(UI_Thread_Params* sp)
{
#if 1
	console_send_string("sub_23490bd0 (todo.c): TODO\r\n");
#endif

    //loc_23490c20


    //loc_23490c70
    menu_stack_operate(Data_234ea514);
    menu_initialize(Data_234ea514);
    /*sub_2344de56*/sub_2343d51e(Data_234ea514, sp);
    return 0;
}




#endif
