
#include "data.h"
#include "menu.h"
#include "frontdisplay.h"
#include "sub_2340a6a0.h"
#include "channel_list_update.h"

#pragma thumb


#ifndef VDR110

extern void sub_23414b38(); //->graphic.c

extern uint8_t Data_2397044c[]; //2397044c
extern uint8_t Data_2397056c[]; //2397056c
extern uint8_t Data_23970594[]; //23970594
extern uint8_t Data_239705bc[]; //239705bc
extern uint8_t Data_2397060c[]; //2397060c
extern uint8_t Data_23970634[]; //23970634
extern uint8_t Data_2397065c[]; //2397065c
extern uint8_t Data_23970684[]; //23970684
extern uint8_t Data_239706d4[]; //239706d4
extern uint8_t Data_239706fc[]; //239706fc
extern uint8_t Data_23970724[]; //23970724
extern uint8_t Data_23970774[]; //23970774
extern uint8_t Data_2397079c[]; //2397079c
extern uint8_t Data_239707c4[]; //239707c4
extern uint8_t Data_239707ec[]; //239707ec

static Menu menu_general_settings;
static Menu* menu_general_settings_p = &menu_general_settings; //234e9324

Struct_235fdf74_Inner12_Inner0x20 Data_234e9334 = //234e9334
{
	{0, 0, 0, 0},
	&Data_2397044c[0], //Data_0x10
#if 0
	0x234e9334 0000                   movs       r0, r0                             ; DATA XREF=0x234e9af4
	0x234e9336 5100                   lsls       r1, r2, #0x1
	0x234e9338 2C00                   movs       r4, r5
	0x234e933a 2701                   lsls       r7, r4, #0x4
	0x234e933c 4F00                   lsls       r7, r1, #0x1
	0x234e933e 0106                   lsls       r1, r0, #0x18
	0x234e9340 0200                   movs       r2, r0
	0x234e9342 0000                   movs       r0, r0
	0x234e9344                        dd         0x2397044c
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e93c4 = //234e93c4
{
	{0, 0, 0, 0}, //TODO
	&Data_2397060c[0], //Data_0x10
#if 0
0x234e93c4 0000                   movs       r0, r0                             ; DATA XREF=0x234e9734
0x234e93c6 5100                   lsls       r1, r2, #0x1
0x234e93c8 E400                   lsls       r4, r4, #0x3
0x234e93ca 2A01                   lsls       r2, r5, #0x4
0x234e93cc 0001                   lsls       r0, r0, #0x4
0x234e93ce 0104                   lsls       r1, r0, #0x10
0x234e93d0 0901                   lsls       r1, r1, #0x4
0x234e93d2 0000                   movs       r0, r0
0x234e93d4                        dd         0x2397060c
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e93dc = //234e93dc
{
	{0, 0, 0, 0}, //TODO
	&Data_23970634[0], //Data_0x10
#if 0
0x234e93dc 0000                   movs       r0, r0                             ; DATA XREF=0x234e9774
0x234e93de 5100                   lsls       r1, r2, #0x1
0x234e93e0 0401                   lsls       r4, r0, #0x4
0x234e93e2 2A01                   lsls       r2, r5, #0x4
0x234e93e4 2001                   lsls       r0, r4, #0x4
0x234e93e6 0104                   lsls       r1, r0, #0x10
0x234e93e8 0901                   lsls       r1, r1, #0x4
0x234e93ea 0000                   movs       r0, r0
0x234e93ec                        dd         0x23970634
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e93f4 = //234e93f4
{
	{0, 0, 0, 0}, //TODO
	&Data_2397065c[0], //Data_0x10
#if 0
0x234e93f4 0000                   movs       r0, r0                             ; DATA XREF=0x234e97b4
0x234e93f6 5100                   lsls       r1, r2, #0x1
0x234e93f8 2401                   lsls       r4, r4, #0x4
0x234e93fa 2A01                   lsls       r2, r5, #0x4
0x234e93fc 4001                   lsls       r0, r0, #0x5
0x234e93fe 0104                   lsls       r1, r0, #0x10
0x234e9400 0901                   lsls       r1, r1, #0x4
0x234e9402 0000                   movs       r0, r0
0x234e9404                        dd         0x2397065c
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e940c = //234e940c
{
	{0, 0, 0, 0}, //TODO
	&Data_23970684[0], //Data_0x10
#if 0
0x234e940c 0000                   movs       r0, r0                             ; DATA XREF=0x234e97f4
0x234e940e 5100                   lsls       r1, r2, #0x1
0x234e9410 4401                   lsls       r4, r0, #0x5
0x234e9412 2A01                   lsls       r2, r5, #0x4
0x234e9414 6001                   lsls       r0, r4, #0x5
0x234e9416 0104                   lsls       r1, r0, #0x10
0x234e9418 0901                   lsls       r1, r1, #0x4
0x234e941a 0000                   movs       r0, r0
0x234e941c                        dd         0x23970684
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e949c = //234e949c
{
	{0, 0, 0, 0}, //TODO
	&Data_23970774[0], //Data_0x10
#if 0
0x234e949c 0000                   movs       r0, r0                             ; DATA XREF=0x234e99b4
0x234e949e 5501                   lsls       r5, r2, #0x5
0x234e94a0 E400                   lsls       r4, r4, #0x3
0x234e94a2 2E02                   lsls       r6, r5, #0x8
0x234e94a4 0001                   lsls       r0, r0, #0x4
0x234e94a6 0104                   lsls       r1, r0, #0x10
0x234e94a8 0901                   lsls       r1, r1, #0x4
0x234e94aa 0000                   movs       r0, r0
0x234e94ac                        dd         0x23970774
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e94b4 = //234e94b4
{
	{0, 0, 0, 0}, //TODO
	&Data_2397079c[0], //Data_0x10
#if 0
0x234e94b4 0000                   movs       r0, r0                             ; DATA XREF=0x234e99f4
0x234e94b6 5501                   lsls       r5, r2, #0x5
0x234e94b8 0401                   lsls       r4, r0, #0x4
0x234e94ba 2E02                   lsls       r6, r5, #0x8
0x234e94bc 2001                   lsls       r0, r4, #0x4
0x234e94be 0104                   lsls       r1, r0, #0x10
0x234e94c0 0901                   lsls       r1, r1, #0x4
0x234e94c2 0000                   movs       r0, r0
0x234e94c4                        dd         0x2397079c
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e94cc = //234e94cc
{
	{0, 0, 0, 0}, //TODO
	&Data_239707c4[0], //Data_0x10
#if 0
0x234e94cc 0000                   movs       r0, r0                             ; DATA XREF=0x234e9a34
0x234e94ce 5501                   lsls       r5, r2, #0x5
0x234e94d0 2401                   lsls       r4, r4, #0x4
0x234e94d2 2E02                   lsls       r6, r5, #0x8
0x234e94d4 4001                   lsls       r0, r0, #0x5
0x234e94d6 0104                   lsls       r1, r0, #0x10
0x234e94d8 0901                   lsls       r1, r1, #0x4
0x234e94da 0000                   movs       r0, r0
0x234e94dc                        dd         0x239707c4
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e94e4 = //234e94e4
{
	{0, 0, 0, 0}, //TODO
	&Data_239707ec[0], //Data_0x10
#if 0
0x234e94e4 0000                   movs       r0, r0                             ; DATA XREF=0x234e9a74
0x234e94e6 5501                   lsls       r5, r2, #0x5
0x234e94e8 4401                   lsls       r4, r0, #0x5
0x234e94ea 2E02                   lsls       r6, r5, #0x8
0x234e94ec 6001                   lsls       r0, r4, #0x5
0x234e94ee 0104                   lsls       r1, r0, #0x10
0x234e94f0 0901                   lsls       r1, r1, #0x4
0x234e94f2 0000                   movs       r0, r0
0x234e94f4                        dd         0x239707ec
#endif
};

#if 0
Struct_235fdf74_Inner16 Data_234e9594 = //234e9594
{
	uint16_t fill_0; //0
	uint16_t wData_2; //2
	uint16_t wData_4; //4
	uint16_t wData_6; //6
	int fill_8; //8
	uint8_t fill_0xc; //0xc
	uint8_t bData_0xd; //0xd
	void* Data_0x10; //0x10
	uint16_t fill_0x14; //0x14
	uint8_t fill_0x16; //0x16
	uint8_t bData_0x17; //0x17
#if 0
#endif
};
#endif

static Menu_Item_Inner4_Data_0 Data_234e9714 = //234e9714
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e93c4, //Data_0x20
#if 0
0x234e9714 0100                   movs       r1, r0                             ; DATA XREF=0x234ea290
0x234e9716 0000                   movs       r0, r0
0x234e9718 0000                   movs       r0, r0
0x234e971a 0000                   movs       r0, r0
0x234e971c 0000                   movs       r0, r0
0x234e971e 0000                   movs       r0, r0
0x234e9720 3D00                   movs       r5, r7
0x234e9722 E000                   lsls       r0, r4, #0x3
0x234e9724 ED00                   lsls       r5, r5, #0x3
0x234e9726 2000                   movs       r0, r4
0x234e9728 0000                   movs       r0, r0
0x234e972a 0000                   movs       r0, r0
0x234e972c                        dd         0x234c12d4
0x234e9730 0900                   movs       r1, r1
0x234e9732 0000                   movs       r0, r0
0x234e9734                        dd         0x234e93c4
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e9754 = //234e9754
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e93dc, //Data_0x20
#if 0
0x234e9754 0100                   movs       r1, r0                             ; DATA XREF=0x234ea2bc
0x234e9756 0000                   movs       r0, r0
0x234e9758 0000                   movs       r0, r0
0x234e975a 0000                   movs       r0, r0
0x234e975c 0000                   movs       r0, r0
0x234e975e 0000                   movs       r0, r0
0x234e9760 3D00                   movs       r5, r7
0x234e9762 0001                   lsls       r0, r0, #0x4
0x234e9764 ED00                   lsls       r5, r5, #0x3
0x234e9766 2000                   movs       r0, r4
0x234e9768 0000                   movs       r0, r0
0x234e976a 0000                   movs       r0, r0
0x234e976c                        dd         0x234c131c
0x234e9770 0900                   movs       r1, r1
0x234e9772 0000                   movs       r0, r0
0x234e9774                        dd         0x234e93dc
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e9794 = //234e9794
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e93f4, //Data_0x20
#if 0
0x234e9794 0000                   movs       r0, r0                             ; DATA XREF=0x234ea2e8
0x234e9796 0000                   movs       r0, r0
0x234e9798 0000                   movs       r0, r0
0x234e979a 0000                   movs       r0, r0
0x234e979c 0000                   movs       r0, r0
0x234e979e 0000                   movs       r0, r0
0x234e97a0 3D00                   movs       r5, r7
0x234e97a2 2001                   lsls       r0, r4, #0x4
0x234e97a4 ED00                   lsls       r5, r5, #0x3
0x234e97a6 2000                   movs       r0, r4
0x234e97a8 0000                   movs       r0, r0
0x234e97aa 0000                   movs       r0, r0
0x234e97ac                        dd         0x234c131c
0x234e97b0 0900                   movs       r1, r1
0x234e97b2 0000                   movs       r0, r0
0x234e97b4                        dd         0x234e93f4
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e97d4 = //234e97d4
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e940c, //Data_0x20
#if 0
0x234e97d4 0000                   movs       r0, r0                             ; DATA XREF=0x234ea314
0x234e97d6 0000                   movs       r0, r0
0x234e97d8 0000                   movs       r0, r0
0x234e97da 0000                   movs       r0, r0
0x234e97dc 0000                   movs       r0, r0
0x234e97de 0000                   movs       r0, r0
0x234e97e0 3D00                   movs       r5, r7
0x234e97e2 4001                   lsls       r0, r0, #0x5
0x234e97e4 ED00                   lsls       r5, r5, #0x3
0x234e97e6 2000                   movs       r0, r4
0x234e97e8 0000                   movs       r0, r0
0x234e97ea 0000                   movs       r0, r0
0x234e97ec                        dd         0x234c131c
0x234e97f0 0900                   movs       r1, r1
0x234e97f2 0000                   movs       r0, r0
0x234e97f4                        dd         0x234e940c
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e9994 = //234e9994
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e949c, //Data_0x20
#if 0
0x234e9994 0100                   movs       r1, r0                             ; DATA XREF=0x234ea294
0x234e9996 0000                   movs       r0, r0
0x234e9998 0000                   movs       r0, r0
0x234e999a 0000                   movs       r0, r0
0x234e999c 0000                   movs       r0, r0
0x234e999e 0000                   movs       r0, r0
0x234e99a0 4101                   lsls       r1, r0, #0x5
0x234e99a2 E000                   lsls       r0, r4, #0x3
0x234e99a4 ED00                   lsls       r5, r5, #0x3
0x234e99a6 2000                   movs       r0, r4
0x234e99a8 0000                   movs       r0, r0
0x234e99aa 0000                   movs       r0, r0
0x234e99ac                        dd         0x234c12d4
0x234e99b0 0900                   movs       r1, r1
0x234e99b2 0000                   movs       r0, r0
0x234e99b4                        dd         0x234e949c
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e99d4 = //234e99d4
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e94b4, //Data_0x20
#if 0
0x234e99d4 0100                   movs       r1, r0                             ; DATA XREF=0x234ea2c0
0x234e99d6 0000                   movs       r0, r0
0x234e99d8 0000                   movs       r0, r0
0x234e99da 0000                   movs       r0, r0
0x234e99dc 0000                   movs       r0, r0
0x234e99de 0000                   movs       r0, r0
0x234e99e0 4101                   lsls       r1, r0, #0x5
0x234e99e2 0001                   lsls       r0, r0, #0x4
0x234e99e4 ED00                   lsls       r5, r5, #0x3
0x234e99e6 2000                   movs       r0, r4
0x234e99e8 0000                   movs       r0, r0
0x234e99ea 0000                   movs       r0, r0
0x234e99ec                        dd         0x234c1328
0x234e99f0 0900                   movs       r1, r1
0x234e99f2 0000                   movs       r0, r0
0x234e99f4                        dd         0x234e94b4
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e9a14 = //234e9a14
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e94cc, //Data_0x20
#if 0
0x234e9a14 0000                   movs       r0, r0                             ; DATA XREF=0x234ea2ec
0x234e9a16 0000                   movs       r0, r0
0x234e9a18 0000                   movs       r0, r0
0x234e9a1a 0000                   movs       r0, r0
0x234e9a1c 0000                   movs       r0, r0
0x234e9a1e 0000                   movs       r0, r0
0x234e9a20 4101                   lsls       r1, r0, #0x5
0x234e9a22 2001                   lsls       r0, r4, #0x4
0x234e9a24 ED00                   lsls       r5, r5, #0x3
0x234e9a26 2000                   movs       r0, r4
0x234e9a28 0000                   movs       r0, r0
0x234e9a2a 0000                   movs       r0, r0
0x234e9a2c                        dd         0x234c1328
0x234e9a30 0900                   movs       r1, r1
0x234e9a32 0000                   movs       r0, r0
0x234e9a34                        dd         0x234e94cc
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e9a54 = //234e9a54
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e94e4, //Data_0x20
#if 0
0x234e9a54 0000                   movs       r0, r0                             ; DATA XREF=0x234ea318
0x234e9a56 0000                   movs       r0, r0
0x234e9a58 0000                   movs       r0, r0
0x234e9a5a 0000                   movs       r0, r0
0x234e9a5c 0000                   movs       r0, r0
0x234e9a5e 0000                   movs       r0, r0
0x234e9a60 4101                   lsls       r1, r0, #0x5
0x234e9a62 4001                   lsls       r0, r0, #0x5
0x234e9a64 ED00                   lsls       r5, r5, #0x3
0x234e9a66 2000                   movs       r0, r4
0x234e9a68 0000                   movs       r0, r0
0x234e9a6a 0000                   movs       r0, r0
0x234e9a6c                        dd         0x234c1328
0x234e9a70 0900                   movs       r1, r1
0x234e9a72 0000                   movs       r0, r0
0x234e9a74                        dd         0x234e94e4
#endif
};

static Struct_235fdf74_Inner12 Data_234e9ad4 = //234e9ad4
{
	{0, 0, 0, 0, 0, 0, 0, 0}, //TODO
	&Data_234e9334, //Data_0x20
#if 0
	0x234e9ad4                        db         0x01                               ; DATA XREF=0x234ea4a8
	0x234e9ad5                        db  0x00 ; '.'
	0x234e9ad6 0000                   movs       r0, r0
	0x234e9ad8 0000                   movs       r0, r0
	0x234e9ada 0000                   movs       r0, r0
	0x234e9adc 0000                   movs       r0, r0
	0x234e9ade 0000                   movs       r0, r0
	0x234e9ae0 3D00                   movs       r5, r7
	0x234e9ae2 2900                   movs       r1, r5
	0x234e9ae4 ED00                   lsls       r5, r5, #0x3
	0x234e9ae6 2600                   movs       r6, r4
	0x234e9ae8 0000                   movs       r0, r0
	0x234e9aea 0000                   movs       r0, r0
	0x234e9aec                        dd         0x234c12a4
	0x234e9af0 0200                   movs       r2, r0
	0x234e9af2 0000                   movs       r0, r0
	0x234e9af4                        dd         0x234e9334
#endif
};

static Struct_235fdf74_Inner20 Data_234ea194 = //234ea194
{
		0, //uint16_t fill_0; //0
		0, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0, 0}, //int fill_4[6]; //4
		0, //void (*Data_0x1c)(); //28 = 0x1c
		0, //void (*Data_0x20)(); //32 = 0x20
#if 0
		0x234ea194                        db  0x00 ; '.'                                ; DATA XREF=0x234ea4b0
		0x234ea195                        db  0xfa ; '.'
		0x234ea196 0700                   movs       r7, r0
		0x234ea198 0400                   movs       r4, r0
		0x234ea19a 0000                   movs       r0, r0
		0x234ea19c                        dd         0x234e9514
		0x234ea1a0                        dd         0x234c123c
		0x234ea1a4 1000                   movs       r0, r2
		0x234ea1a6 0000                   movs       r0, r0
		0x234ea1a8 0000                   movs       r0, r0
		0x234ea1aa 0000                   movs       r0, r0
		0x234ea1ac 1901                   lsls       r1, r3, #0x4
		0x234ea1ae 0000                   movs       r0, r0
		0x234ea1b0                        dd         0x00000000
		0x234ea1b4                        dd         0x00000000
#endif
};

#endif //!VDR110

static int on_channel_list_update_change();
static int on_deep_standby_change();
static int on_auto_standby_change();
static void get_channel_list_update_value_string();
static int menu_general_settings_on_enter(int);
static int on_menu_exit(UI_Thread_Params*);
#ifdef VDR110
static void get_deep_standby_value_string();
static void get_auto_standby_value_string();
static void* caption_string_display(FrontDisplay_Job*);
static void* item_string_display(FrontDisplay_Job*);
#else
static void get_auto_standby_value_string(Menu_Item*);
static void get_deep_standby_value_string(Menu_Item*);
#endif

static Menu_Item menu_general_settings_items[]; //234963f0

uint8_t bData_234963a4 = 0; //234963a4
Menu_Item* Data_234963a8 = 0; //234963a4

static Menu menu_general_settings = //234963ac /  / 234ea49c
{
		80, //"Allgemein"?
		&menu_general_settings_items[0], //Menu_Item* Data_4; //4
		&menu_general_settings_items[0], //Menu_Item* Data_8; //8
#ifdef VDR110
		0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
		0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
		0, //int Data_0x14; //20 = 0x14
		2, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		0, //void (*Data_0x1c)(); //0x1c
#else
		&Data_234e9ad4, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
		0, //&Data_234e9594, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
		&Data_234ea194, //int Data_0x14; //20 = 0x14
		3, //7, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		sub_23414b38, //void (*Data_0x1c)(); //0x1c
#endif
		menu_items_navigate, //void (*onNavigate)(); //0x20
		menu_general_settings_on_enter, //void (*onEnter)(); //36 = 0x24
		on_menu_exit, //int (*onExit)(); //0x28
		0, //int Data_0x2c; //44 = 0x2c
		0, //int Data_0x30; //48
		0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
#ifdef VDR110
		//0x38 = 56?
#else
		0, //void* (*Data_0x38)(struct FrontDisplay_Job*); //56
		//0x3c = 60?
#endif
}; //->234963E4

#ifdef VDR110

typedef void (*item_value_string_callback)(uint8_t* str, int len);

static item_value_string_callback item_value_string_callbacks[3] = //234963e4
{
		get_auto_standby_value_string,
		get_deep_standby_value_string,
		get_channel_list_update_value_string
};

#endif

Menu_Item menu_general_settings_items[] = //234963f0 / 234ea1dc
{
#ifdef VDR110
	//[0]
	{
		382, //"Auto-Standby"
		0, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		on_auto_standby_change, //void* onEvent; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 2349641C
	}, //2349641C
	//[1]
	{
		341, //"Deep-Standby"
		0, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		on_deep_standby_change, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 23496448
	}, //23496448
	//[2]
	{
		394, //"Senderaktualisierung" // Channel list update
		0, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		on_channel_list_update_change, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 23496474
	} //23496474
#else //!VDR110: TODO!!!
	//234EA28C?
	//[4]
	{
		382, //0x017e = "Auto-Standby"
		0, //uint16_t wData_2; //2
		{&Data_234e9714, &Data_234e9994, 0, 0, 0}, //Menu_Item_Inner4_Data_0* Data_4[5]; //4
		get_auto_standby_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		on_auto_standby_change, //void* onEvent; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
#if 0
0x234ea28c                        dw         0x017e
0x234ea28e                        dw         0x00f4
0x234ea290                        dd         0x234e9714
0x234ea294                        dd         0x234e9994
0x234ea298 0000                   movs       r0, r0
0x234ea29a 0000                   movs       r0, r0
0x234ea29c 0000                   movs       r0, r0
0x234ea29e 0000                   movs       r0, r0
0x234ea2a0 0000                   movs       r0, r0
0x234ea2a2 0000                   movs       r0, r0
0x234ea2a4                        dd         get_auto_standby_value_string+1
0x234ea2a8                        dd         sub_234908f4+1
0x234ea2ac                        dd         menu_item_event_thread+1
0x234ea2b0 0000                   movs       r0, r0
0x234ea2b2 0000                   movs       r0, r0
0x234ea2b4 0000                   movs       r0, r0
0x234ea2b6 0000                   movs       r0, r0
#endif
	}, //234ea2b8
	//[5]
	{
		341, //0x155 = "Deep-Standby"
		0, //uint16_t wData_2; //2
		{&Data_234e9754, &Data_234e99d4, 0, 0, 0}, //int fill_4[5]; //4
		get_deep_standby_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		on_deep_standby_change, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
#if 0
0x234ea2b8                        dw         0x0155
0x234ea2ba                        dw         0x0106
0x234ea2bc                        dd         0x234e9754
0x234ea2c0                        dd         0x234e99d4
0x234ea2c4 0000                   movs       r0, r0
0x234ea2c6 0000                   movs       r0, r0
0x234ea2c8 0000                   movs       r0, r0
0x234ea2ca 0000                   movs       r0, r0
0x234ea2cc 0000                   movs       r0, r0
0x234ea2ce 0000                   movs       r0, r0
0x234ea2d0                        dd         get_deep_standby_value_string+1
0x234ea2d4                        dd         sub_23490886+1
0x234ea2d8                        dd         menu_item_event_thread+1
0x234ea2dc 0000                   movs       r0, r0
0x234ea2de 0000                   movs       r0, r0
0x234ea2e0 0000                   movs       r0, r0
0x234ea2e2 0000                   movs       r0, r0
#endif
	}, //234ea2e4
	//[6]
	{
		389, //0x185 = "Sendersortierung"
		0, //uint16_t wData_2; //2
		{&Data_234e9794, &Data_234e9a14, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
#if 0
0x234ea2e4                        dw         0x0185
0x234ea2e6                        dw         0x00f4
0x234ea2e8                        dd         0x234e9794
0x234ea2ec                        dd         0x234e9a14
0x234ea2f0 0000                   movs       r0, r0
0x234ea2f2 0000                   movs       r0, r0
0x234ea2f4 0000                   movs       r0, r0
0x234ea2f6 0000                   movs       r0, r0
0x234ea2f8 0000                   movs       r0, r0
0x234ea2fa 0000                   movs       r0, r0
0x234ea2fc                        dd         sub_23490984+1
0x234ea300                        dd         sub_23490956+1
0x234ea304                        dd         menu_item_event_thread+1
0x234ea308 0000                   movs       r0, r0
0x234ea30a 0000                   movs       r0, r0
0x234ea30c 0000                   movs       r0, r0
0x234ea30e 0000                   movs       r0, r0
#endif
	}, //234ea310
	//[7]
	{
		394, //0x18a = "Senderaktualisierung"
		0, //uint16_t wData_2; //2
		{&Data_234e97d4, &Data_234e9a54, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
#if 0
0x234ea310                        dw         0x018a
0x234ea312                        dw         0x00f4
0x234ea314                        dd         0x234e97d4
0x234ea318                        dd         0x234e9a54
0x234ea31c 0000                   movs       r0, r0
0x234ea31e 0000                   movs       r0, r0
0x234ea320 0000                   movs       r0, r0
0x234ea322 0000                   movs       r0, r0
0x234ea324 0000                   movs       r0, r0
0x234ea326 0000                   movs       r0, r0
0x234ea328                        dd         sub_23490a2c+1
0x234ea32c                        dd         sub_234909aa+1
0x234ea330                        dd         menu_item_event_thread+1
0x234ea334 0000                   movs       r0, r0
0x234ea336 0000                   movs       r0, r0
0x234ea338 0000                   movs       r0, r0
0x234ea33a 0000                   movs       r0, r0
#endif
	} //234ea33c
#endif //!VDR110
};

static User_Settings menu_general_settings_backup; //238e0ab8

#ifndef VDR110
uint8_t Data_2397044c[40]; //2397044c, size???
uint8_t Data_2397060c[40]; //2397060c
uint8_t Data_23970634[40]; //23970634
uint8_t Data_2397065c[40]; //2397065c
uint8_t Data_23970684[40]; //23970684
uint8_t Data_23970774[40]; //23970774
uint8_t Data_2397079c[40]; //2397079c
uint8_t Data_239707c4[40]; //239707c4
uint8_t Data_239707ec[40]; //239707ec
#endif //!VDR110


/* 23471d8c - todo */
int on_channel_list_update_change()
{
#if 0
	console_send_string("on_channel_list_update_change (todo.c): TODO\r\n");
#endif

	menu_general_settings_backup.Data_0x10 ^= (1 << 7);

	if ((menu_general_settings_backup.Data_0x10 >> 7) & 1)
	{
		powermode_set_onoff_callbacks(channel_list_update_start, sub_2343deb4);
	}
	else
	{
		//loc_23471da2
		powermode_set_onoff_callbacks(0, 0);
	}

	return 0;
}


/* 23471dae - complete */
void get_channel_list_update_value_string(uint8_t* str, int len)
{
#if 0
	console_send_string("get_channel_list_update_value_string (todo.c): TODO\r\n");
#endif

	if (menu_general_settings_backup.Data_0x10 & (1 << 7))
	{
		text_table_get_string(20, str, len - 1);
	}
	else
	{
		//loc_23471dc0
		text_table_get_string(19, str, len - 1);
	}
}


/* 23471dcc /  / 23490886 - complete */
int on_deep_standby_change()
{
#ifdef VDR110
	menu_general_settings_backup.Data_0x10 ^= (1 << 6);

	return 0;
#else
	console_send_string("on_deep_standby_change (todo.c): TODO\r\n");
#endif
}


/* 23471df8 /  / 234908f4 - todo */
int on_auto_standby_change()
{
#ifdef VDR110
	menu_general_settings_backup.Data_0x10 ^= (1 << 15);

	menu_root_set_standby_timer_func((menu_general_settings_backup.Data_0x10 >> 15) & 1);

	return 0;
#else
	console_send_string("on_auto_standby_change (todo.c): TODO\r\n");
#endif
}

#ifdef VDR110


/* 23471dda - complete */
void get_deep_standby_value_string(uint8_t* str, int len)
{
#if 0
	console_send_string("get_deep_standby_value_string (todo.c): TODO\r\n");
#endif

	if (menu_general_settings_backup.Data_0x10 & (1 << 6))
	{
		text_table_get_string(19, str, len - 1);
	}
	else
	{
		//loc_23471dec
		text_table_get_string(20, str, len - 1);
	}
}


/* 23471e12 - complete */
void get_auto_standby_value_string(uint8_t* str, int len)
{
#if 0
	console_send_string("get_auto_standby_value_string (todo.c): TODO\r\n");
#endif

	if (menu_general_settings_backup.Data_0x10 & (1 << 15))
	{
		text_table_get_string(20, str, len - 1);
	}
	else
	{
		//loc_23471e24
		text_table_get_string(19, str, len - 1);
	}
}

/* 23471e30 - todo */
void* item_string_display(FrontDisplay_Job* r7)
{
	FrontDisplay_Job* r4;
	Menu_Item* r5;
	uint8_t* sp;

#if 0
	console_send_string("item_string_display (todo.c): TODO\r\n");
#endif

	r5 = menu_general_settings.Data_4;
	sp = r7->bData_8;

	text_table_get_string(r5->wData_0, sp, 0xfe);

	r7->bData_8[0xff] = 0;
	r7->bNumTextChars = strlen(sp);
	r7->bDisplayOffset = 0;
	r7->bNumDisplayChars = 12;
	r7->bData_0x10b = 0;
	r7->bData_0x110 = 0;
	r7->holdTime = 15;
	r7->Data_4 = 0;
	r7->bData_0x10f = 0;
	r7->bData_0x10c = 0;
	r7->Data_0 = frontdisplay_draw_text;

	if (r7->bNumTextChars > 12)
	{
		r7->bData_0x10c = 1;
		r7->Data_0 = frontdisplay_draw_scroll_text;
	}
	//loc_23471e7c
	r4 = &r7[1];

	if ((uint8_t)menu_general_settings.currentItem < 3)
	{
		if (item_value_string_callbacks[menu_general_settings.currentItem] != 0)
		{
			(item_value_string_callbacks[menu_general_settings.currentItem])(r4->bData_8, 0xff);
		}
	}
	//loc_23471e9e
	r4->bNumTextChars = strlen(r4->bData_8);
	r4->bNumDisplayChars = 12;
	r4->bDisplayOffset = 6;
	r4->bData_0x10b = 0;
	r4->bData_0x10c = 0;
	r4->bData_0x110 = 1;
	r4->holdTime = 0;
	r4->bData_0x10f = 0;
	r4->Data_4 = 0;
	r4->Data_0 = frontdisplay_draw_text;

	if (r4->bNumTextChars < 6)
	{
		r4->bDisplayOffset = r4->bNumDisplayChars - r4->bNumTextChars - 1;
		//->loc_23471ede
	}
	else
	{
		//loc_23471ed8
		r4->bData_0x10c = 1;
		r4->Data_0 = frontdisplay_draw_scroll_text;
	}
	//loc_23471ede
	if (Data_234963a8 != r5)
	{
		r4->bData_0x10f = 1;
		//->loc_23471f04
	}
	else
	{
		//loc_23471eec
		if (r4->bNumTextChars < bData_234963a4)
		{
			r7->bData_0x10f = 1;
			r7->bNumDisplayChars = r4->bDisplayOffset;
			r7->holdTime = 0;
			r7->bData_0x10c = 0;
			r7->Data_0 = frontdisplay_draw_text;
		}
		//loc_23471f04
	}
	//loc_23471f04
	bData_234963a4 = r4->bNumTextChars;
	Data_234963a8 = r5;

	return item_string_display;
}


/* 23471f0e - todo */
void* caption_string_display(FrontDisplay_Job* r4)
{
	uint8_t* str; //r6
	uint8_t len;

#if 0
	console_send_string("caption_string_display (todo.c): TODO\r\n");
#endif

	r4->bData_8[0] = '"';

	text_table_get_string(menu_general_settings.stringId, &r4->bData_8[1], 252);

	str = &r4->bData_8[0];

	len = strlen(str);

	r4->bData_8[len++] = '""';
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

	return item_string_display;
}

#else


/* 234908ba - complete */
static void get_deep_standby_value_string(Menu_Item* pItem)
{
#if 0
	console_send_string("get_deep_standby_value_string (todo.c): TODO\r\n");
#endif

	Menu_Item_Inner4_Data_0* r0_ = pItem->Data_4[1];
	Menu_Item_Inner4_Data_0_Data_0x20* r0 = r0_->Data_0x20;
	uint8_t* str = r0->Data_0x10;
	r0->bData_0x17 = 1;

	if (0 == sub_23418e98())
	{
		text_table_get_string(0x189/*Nicht verf▒gbar*/, str, 38);
	}
	else
	{
		if (menu_general_settings_backup.Data_0x10 & (1 << 6))
		{
			text_table_get_string(0x13, str, 38);
		}
		else
		{
			text_table_get_string(0x14, str, 38);
		}
	}
}


/* 23490932 - todo */
static void get_auto_standby_value_string(Menu_Item* pItem)
{
#if 0
	console_send_string("get_auto_standby_value_string (todo.c): TODO\r\n");
#endif

	User_Settings* sett = &menu_general_settings_backup;
	Menu_Item_Inner4_Data_0* r0_ = pItem->Data_4[1];
	Menu_Item_Inner4_Data_0_Data_0x20* r0 = r0_->Data_0x20;
	uint8_t* str = r0->Data_0x10;
	r0->bData_0x17 = 1;

	if (sett->Data_0x10 & (1 << 15))
	{
		text_table_get_string(0x14, str, 38);
	}
	else
	{
		text_table_get_string(0x13, str, 38);
	}
}


#endif //VDR110

/* 23471f64 /  / 23490a50 - todo */
int menu_general_settings_on_enter(int a)
{
#if 1
	console_send_string("menu_general_settings_on_enter (todo.c): TODO\r\n");
#endif

	// Get the settings
	channel_handle_user_settings(1, &menu_general_settings_backup);

#ifdef VDR110
	frontdisplay_start_text(caption_string_display);
#endif

	return 0;
}


/* 23471f78 - complete */
int on_menu_exit(UI_Thread_Params* r4)
{
#if 0
	console_send_string("on_menu_exit (todo.c): TODO\r\n");
#endif

	User_Settings oldSettings;

	// Get the old settings
	channel_handle_user_settings(1, &oldSettings);

	// Compare with the work copy
	if (0 != memcmp(&oldSettings, &menu_general_settings_backup, sizeof(User_Settings)))
	{
		// To save dialog?
		sub_23470890(r4, 1);

		return 1;
	}
	//loc_23471f9e
	return 0;
}


/* 23471fa2 /  / 23490aa4 - complete */
int menu_general_settings_entry(UI_Thread_Params* p)
{
#if 0
	console_send_string("menu_general_settings_entry (todo.c): TODO\r\n");
#endif

#ifdef VDR110
	sub_2343d482(&menu_general_settings);
	sub_2343d3ac(&menu_general_settings);
	sub_2343d51e(&menu_general_settings, p);
#else
	sub_2343d482(menu_general_settings_p);
	sub_2343d3ac(menu_general_settings_p);
	sub_2343d51e(menu_general_settings_p, p);
#endif

	return 0;
}


/* 23471fbe - todo */
User_Settings* sub_23471fbe(void)
{
	return &menu_general_settings_backup;
}

