
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
extern uint8_t Data_239705e4[]; //239705e4
extern uint8_t Data_2397060c[]; //2397060c
extern uint8_t Data_23970634[]; //23970634
extern uint8_t Data_2397065c[]; //2397065c
extern uint8_t Data_23970684[]; //23970684
extern uint8_t Data_239706d4[]; //239706d4
extern uint8_t Data_239706fc[]; //239706fc
extern uint8_t Data_23970724[]; //23970724
extern uint8_t Data_2397074c[]; //2397074c
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

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e9364 = //234e9364
{
	{0, 0, 0, 0},
	&Data_2397056c[0], //Data_0x10
#if 0
	0x234e9364 0000                   movs       r0, r0                             ; DATA XREF=0x234e9634
	0x234e9366 5100                   lsls       r1, r2, #0x1
	0x234e9368 6400                   lsls       r4, r4, #0x1
	0x234e936a 2A01                   lsls       r2, r5, #0x4
	0x234e936c 8000                   lsls       r0, r0, #0x2
	0x234e936e 0104                   lsls       r1, r0, #0x10
	0x234e9370 0901                   lsls       r1, r1, #0x4
	0x234e9372 0000                   movs       r0, r0
	0x234e9374                        dd         0x2397056c
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e937c = //234e937c
{
	{0, 0, 0, 0},
	&Data_23970594[0], //Data_0x10
#if 0
	0x234e937c 0000                   movs       r0, r0                             ; DATA XREF=0x234e9674
	0x234e937e 5100                   lsls       r1, r2, #0x1
	0x234e9380 8400                   lsls       r4, r0, #0x2
	0x234e9382 2A01                   lsls       r2, r5, #0x4
	0x234e9384 A000                   lsls       r0, r4, #0x2
	0x234e9386 0104                   lsls       r1, r0, #0x10
	0x234e9388 0901                   lsls       r1, r1, #0x4
	0x234e938a 0000                   movs       r0, r0
	0x234e938c                        dd         0x23970594
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e9394 = //234e9394
{
	{0, 0, 0, 0},
	&Data_239705bc[0], //Data_0x10
#if 0
	0x234e9394 0000                   movs       r0, r0                             ; DATA XREF=0x234e96b4
	0x234e9396 5100                   lsls       r1, r2, #0x1
	0x234e9398 A400                   lsls       r4, r4, #0x2
	0x234e939a 2A01                   lsls       r2, r5, #0x4
	0x234e939c C000                   lsls       r0, r0, #0x3
	0x234e939e 0104                   lsls       r1, r0, #0x10
	0x234e93a0 0901                   lsls       r1, r1, #0x4
	0x234e93a2 0000                   movs       r0, r0
	0x234e93a4                        dd         0x239705bc
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e93ac = //234e93ac
{
	{0, 0, 0, 0},
	&Data_239705e4[0], //Data_0x10
#if 0
0x234e93ac 0000                   movs       r0, r0                             ; DATA XREF=0x234e96f4
0x234e93ae 5100                   lsls       r1, r2, #0x1
0x234e93b0 C400                   lsls       r4, r0, #0x3
0x234e93b2 2A01                   lsls       r2, r5, #0x4
0x234e93b4 E000                   lsls       r0, r4, #0x3
0x234e93b6 0104                   lsls       r1, r0, #0x10
0x234e93b8 0901                   lsls       r1, r1, #0x4
0x234e93ba 0000                   movs       r0, r0
0x234e93bc                        dd         0x239705e4
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

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e943c = //234e943c
{
	{0, 0, 0, 0},
	&Data_239706d4[0], //Data_0x10
#if 0
	0x234e943c 0000                   movs       r0, r0                             ; DATA XREF=0x234e98b4
	0x234e943e 5501                   lsls       r5, r2, #0x5
	0x234e9440 6400                   lsls       r4, r4, #0x1
	0x234e9442 2E02                   lsls       r6, r5, #0x8
	0x234e9444 8000                   lsls       r0, r0, #0x2
	0x234e9446 0104                   lsls       r1, r0, #0x10
	0x234e9448 0901                   lsls       r1, r1, #0x4
	0x234e944a 0000                   movs       r0, r0
	0x234e944c                        dd         0x239706d4
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e9454 = //234e9454
{
	{0, 0, 0, 0},
	&Data_239706fc[0], //Data_0x10
#if 0
	0x234e9454 0000                   movs       r0, r0                             ; DATA XREF=0x234e98f4
	0x234e9456 5501                   lsls       r5, r2, #0x5
	0x234e9458 8400                   lsls       r4, r0, #0x2
	0x234e945a 2E02                   lsls       r6, r5, #0x8
	0x234e945c A000                   lsls       r0, r4, #0x2
	0x234e945e 0104                   lsls       r1, r0, #0x10
	0x234e9460 0901                   lsls       r1, r1, #0x4
	0x234e9462 0000                   movs       r0, r0
	0x234e9464                        dd         0x239706fc
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e946c = //234e946c
{
	{0, 0, 0, 0},
	&Data_23970724[0], //Data_0x10
#if 0
	0x234e946c 0000                   movs       r0, r0                             ; DATA XREF=0x234e9934
	0x234e946e 5501                   lsls       r5, r2, #0x5
	0x234e9470 A400                   lsls       r4, r4, #0x2
	0x234e9472 2E02                   lsls       r6, r5, #0x8
	0x234e9474 C000                   lsls       r0, r0, #0x3
	0x234e9476 0104                   lsls       r1, r0, #0x10
	0x234e9478 0901                   lsls       r1, r1, #0x4
	0x234e947a 0000                   movs       r0, r0
	0x234e947c                        dd         0x23970724
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234e9484 = //234e9484
{
	{0, 0, 0, 0},
	&Data_2397074c[0], //Data_0x10
#if 0
0x234e9484 0000                   movs       r0, r0                             ; DATA XREF=0x234e9974
0x234e9486 5501                   lsls       r5, r2, #0x5
0x234e9488 C400                   lsls       r4, r0, #0x3
0x234e948a 2E02                   lsls       r6, r5, #0x8
0x234e948c E000                   lsls       r0, r4, #0x3
0x234e948e 0104                   lsls       r1, r0, #0x10
0x234e9490 0901                   lsls       r1, r1, #0x4
0x234e9492 0000                   movs       r0, r0
0x234e9494                        dd         0x2397074c
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

static Menu_Item_Inner4_Data_0 Data_234e9614 = //234e9614
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e9364, //Data_0x20
#if 0
	0x234e9614                        db         0x01                               ; DATA XREF=0x234ea1e0
	0x234e9615                        db  0x00 ; '.'
	0x234e9616 0000                   movs       r0, r0
	0x234e9618 0000                   movs       r0, r0
	0x234e961a 0000                   movs       r0, r0
	0x234e961c 0000                   movs       r0, r0
	0x234e961e 0000                   movs       r0, r0
	0x234e9620 3D00                   movs       r5, r7
	0x234e9622 6000                   lsls       r0, r4, #0x1
	0x234e9624 ED00                   lsls       r5, r5, #0x3
	0x234e9626 2000                   movs       r0, r4
	0x234e9628 0000                   movs       r0, r0
	0x234e962a 0000                   movs       r0, r0
	0x234e962c                        dd         0x234c1334
	0x234e9630 0900                   movs       r1, r1
	0x234e9632 0000                   movs       r0, r0
	0x234e9634                        dd         0x234e9364
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e9654 = // 234e9654
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e937c, //Data_0x20
#if 0
	0x234e9654                        db         0x01                               ; DATA XREF=0x234ea20c
	0x234e9655                        db  0x00 ; '.'
	0x234e9656 0000                   movs       r0, r0
	0x234e9658 0000                   movs       r0, r0
	0x234e965a 0000                   movs       r0, r0
	0x234e965c 0000                   movs       r0, r0
	0x234e965e 0000                   movs       r0, r0
	0x234e9660 3D00                   movs       r5, r7
	0x234e9662 8000                   lsls       r0, r0, #0x2
	0x234e9664 ED00                   lsls       r5, r5, #0x3
	0x234e9666 2000                   movs       r0, r4
	0x234e9668 0000                   movs       r0, r0
	0x234e966a 0000                   movs       r0, r0
	0x234e966c                        dd         0x234c12d4
	0x234e9670 0900                   movs       r1, r1
	0x234e9672 0000                   movs       r0, r0
	0x234e9674                        dd         0x234e937c
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e9694 = //234e9694
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e9394, //Data_0x20
#if 0
	0x234e9694                        db         0x01                               ; DATA XREF=menu_general_settings_p+12, 0x234ea238
	0x234e9695                        db  0x00 ; '.'
	0x234e9696 0000                   movs       r0, r0
	0x234e9698 0000                   movs       r0, r0
	0x234e969a 0000                   movs       r0, r0
	0x234e969c 0000                   movs       r0, r0
	0x234e969e 0000                   movs       r0, r0
	0x234e96a0 3D00                   movs       r5, r7
	0x234e96a2 A000                   lsls       r0, r4, #0x2
	0x234e96a4 ED00                   lsls       r5, r5, #0x3
	0x234e96a6 2000                   movs       r0, r4
	0x234e96a8 0000                   movs       r0, r0
	0x234e96aa 0000                   movs       r0, r0
	0x234e96ac                        dd         0x234c12d4
	0x234e96b0 0900                   movs       r1, r1
	0x234e96b2 0000                   movs       r0, r0
	0x234e96b4                        dd         0x234e9394
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e96d4 = //234e96d4
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e93ac, //Data_0x20
#if 0
0x234e96d4 0100                   movs       r1, r0                             ; DATA XREF=0x234ea264
0x234e96d6 0000                   movs       r0, r0
0x234e96d8 0000                   movs       r0, r0
0x234e96da 0000                   movs       r0, r0
0x234e96dc 0000                   movs       r0, r0
0x234e96de 0000                   movs       r0, r0
0x234e96e0 3D00                   movs       r5, r7
0x234e96e2 C000                   lsls       r0, r0, #0x3
0x234e96e4 ED00                   lsls       r5, r5, #0x3
0x234e96e6 2000                   movs       r0, r4
0x234e96e8 0000                   movs       r0, r0
0x234e96ea 0000                   movs       r0, r0
0x234e96ec                        dd         0x234c12d4
0x234e96f0 0900                   movs       r1, r1
0x234e96f2 0000                   movs       r0, r0
0x234e96f4                        dd         0x234e93ac
#endif
};

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

static Menu_Item_Inner4_Data_0 Data_234e9894 = //234e9894
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e943c, //Data_0x20
#if 0
	0x234e9894                        db         0x01                               ; DATA XREF=0x234ea1e4
	0x234e9895                        db  0x00 ; '.'
	0x234e9896 0000                   movs       r0, r0
	0x234e9898 0000                   movs       r0, r0
	0x234e989a 0000                   movs       r0, r0
	0x234e989c 0000                   movs       r0, r0
	0x234e989e 0000                   movs       r0, r0
	0x234e98a0 4101                   lsls       r1, r0, #0x5
	0x234e98a2 6000                   lsls       r0, r4, #0x1
	0x234e98a4 ED00                   lsls       r5, r5, #0x3
	0x234e98a6 2000                   movs       r0, r4
	0x234e98a8 0000                   movs       r0, r0
	0x234e98aa 0000                   movs       r0, r0
	0x234e98ac                        dd         0x234c1340
	0x234e98b0 0900                   movs       r1, r1
	0x234e98b2 0000                   movs       r0, r0
	0x234e98b4                        dd         0x234e943c
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e98d4 = //234e98d4
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e9454, //Data_0x20
#if 0
	0x234e98d4                        db         0x01                               ; DATA XREF=0x234ea210
	0x234e98d5                        db  0x00 ; '.'
	0x234e98d6 0000                   movs       r0, r0
	0x234e98d8 0000                   movs       r0, r0
	0x234e98da 0000                   movs       r0, r0
	0x234e98dc 0000                   movs       r0, r0
	0x234e98de 0000                   movs       r0, r0
	0x234e98e0 4101                   lsls       r1, r0, #0x5
	0x234e98e2 8000                   lsls       r0, r0, #0x2
	0x234e98e4 ED00                   lsls       r5, r5, #0x3
	0x234e98e6 2000                   movs       r0, r4
	0x234e98e8 0000                   movs       r0, r0
	0x234e98ea 0000                   movs       r0, r0
	0x234e98ec                        dd         0x234c12d4
	0x234e98f0 0900                   movs       r1, r1
	0x234e98f2 0000                   movs       r0, r0
	0x234e98f4                        dd         0x234e9454
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e9914 = //234e9914
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e946c, //Data_0x20
#if 0
	0x234e9914                        db         0x01                               ; DATA XREF=0x234ea23c
	0x234e9915                        db  0x00 ; '.'
	0x234e9916 0000                   movs       r0, r0
	0x234e9918 0000                   movs       r0, r0
	0x234e991a 0000                   movs       r0, r0
	0x234e991c 0000                   movs       r0, r0
	0x234e991e 0000                   movs       r0, r0
	0x234e9920 4101                   lsls       r1, r0, #0x5
	0x234e9922 A000                   lsls       r0, r4, #0x2
	0x234e9924 ED00                   lsls       r5, r5, #0x3
	0x234e9926 2000                   movs       r0, r4
	0x234e9928 0000                   movs       r0, r0
	0x234e992a 0000                   movs       r0, r0
	0x234e992c                        dd         0x234c12d4
	0x234e9930 0900                   movs       r1, r1
	0x234e9932 0000                   movs       r0, r0
	0x234e9934                        dd         0x234e946c
#endif
};

static Menu_Item_Inner4_Data_0 Data_234e9954 = //234e9954
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234e9484, //Data_0x20
#if 0
0x234e9954 0100                   movs       r1, r0                             ; DATA XREF=0x234ea268
0x234e9956 0000                   movs       r0, r0
0x234e9958 0000                   movs       r0, r0
0x234e995a 0000                   movs       r0, r0
0x234e995c 0000                   movs       r0, r0
0x234e995e 0000                   movs       r0, r0
0x234e9960 4101                   lsls       r1, r0, #0x5
0x234e9962 C000                   lsls       r0, r0, #0x3
0x234e9964 ED00                   lsls       r5, r5, #0x3
0x234e9966 2000                   movs       r0, r4
0x234e9968 0000                   movs       r0, r0
0x234e996a 0000                   movs       r0, r0
0x234e996c                        dd         0x234c12d4
0x234e9970 0900                   movs       r1, r1
0x234e9972 0000                   movs       r0, r0
0x234e9974                        dd         0x234e9484
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
static int menu_general_settings_on_enter(int);
static int on_menu_exit(UI_Thread_Params*);
#ifdef VDR110
static void get_channel_list_update_value_string();
static void get_deep_standby_value_string();
static void get_auto_standby_value_string();
static void* caption_string_display(FrontDisplay_Job*);
static void* item_string_display(FrontDisplay_Job*);
#else
static int menu_language_change(int*);
static int menu_initial_volume_change(int*);
static int sub_23490826(int*);
static void get_time_difference_value_string(Menu_Item*);
static void get_menu_language_string(Menu_Item*);
static void get_initial_volume_value_string(Menu_Item*);
static void get_timer_storage_value_string(Menu_Item*);
static void get_auto_standby_value_string(Menu_Item*);
static void get_deep_standby_value_string(Menu_Item*);
static void get_channel_list_sorting_value_string(Menu_Item*);
static void get_channel_list_update_value_string(Menu_Item*);
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
		7, //uint8_t maxItem; //0x18 = 24
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
	//[0]
	{
		75, //0x4b = "Zeitverschiebung"
		0, //uint16_t wData_2; //2
		{
			&Data_234e9614,
			&Data_234e9894,
			0, 0, 0
		}, //int fill_4[5]; //4
		get_time_difference_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //menu_time_difference_change, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EA1F8???
#if 0
		0x234ea1dc                        dw         0x004b                             ; DATA XREF=0x234ea4a0, 0x234ea4a4
		0x234ea1de                        dw         0x00f4
		0x234ea1e0                        dd         0x234e9614
		0x234ea1e4                        dd         0x234e9894
		0x234ea1e8 0000                   movs       r0, r0
		0x234ea1ea 0000                   movs       r0, r0
		0x234ea1ec 0000                   movs       r0, r0
		0x234ea1ee 0000                   movs       r0, r0
		0x234ea1f0 0000                   movs       r0, r0
		0x234ea1f2 0000                   movs       r0, r0
		0x234ea1f4                        dd         get_time_difference_value_string+1
		0x234ea1f8                        dd         sub_2349070c+1
		0x234ea1fc                        dd         menu_item_event_thread+1
		0x234ea200 0000                   movs       r0, r0
		0x234ea202 0000                   movs       r0, r0
		0x234ea204 0000                   movs       r0, r0
		0x234ea206 0000                   movs       r0, r0
#endif
	}, //234ea208
	//[1]
	{
		85, //0x55 = "Menusprache" = "Menu language"
		0, //uint16_t wData_2; //2
		{
			&Data_234e9654,
			&Data_234e98d4,
			0, 0, 0 //TODO
		}, //int fill_4[5]; //4
		get_menu_language_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_language_change, //menu_deep_standby_change, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EA234
#if 0
		0x234ea208                        dw         0x0055
		0x234ea20a                        dw         0x00f4
		0x234ea20c                        dd         0x234e9654
		0x234ea210                        dd         0x234e98d4
		0x234ea214 0000                   movs       r0, r0
		0x234ea216 0000                   movs       r0, r0
		0x234ea218 0000                   movs       r0, r0
		0x234ea21a 0000                   movs       r0, r0
		0x234ea21c 0000                   movs       r0, r0
		0x234ea21e 0000                   movs       r0, r0
		0x234ea220                        dd         get_menu_language_string+1
		0x234ea224                        dd         menu_language_change+1
		0x234ea228                        dd         menu_item_event_thread+1
		0x234ea22c 0000                   movs       r0, r0
		0x234ea22e 0000                   movs       r0, r0
		0x234ea230 0000                   movs       r0, r0
		0x234ea232 0000                   movs       r0, r0
#endif
	}, //234EA234
	//[2]
	{
		82, //0x52 = "Startlautstarke" = "Initial volume"
		0, //uint16_t wData_2; //2
		{
			&Data_234e9694,
			&Data_234e9914,
			0, 0, 0
		}, //int fill_4[5]; //4
		get_initial_volume_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_initial_volume_change, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EA260
#if 0
		0x234ea234                        dw         0x0052
		0x234ea236                        dw         0x00f4
		0x234ea238                        dd         0x234e9694
		0x234ea23c                        dd         0x234e9914
		0x234ea240 0000                   movs       r0, r0
		0x234ea242 0000                   movs       r0, r0
		0x234ea244 0000                   movs       r0, r0
		0x234ea246 0000                   movs       r0, r0
		0x234ea248 0000                   movs       r0, r0
		0x234ea24a 0000                   movs       r0, r0
		0x234ea24c                        dd         get_initial_volume_value_string+1
		0x234ea250                        dd         sub_23490756+1
		0x234ea254                        dd         menu_item_event_thread+1
		0x234ea258 0000                   movs       r0, r0
		0x234ea25a 0000                   movs       r0, r0
		0x234ea25c 0000                   movs       r0, r0
		0x234ea25e 0000                   movs       r0, r0
#endif
	}, //234EA260
	//[3]
	{
		399, //0x18f = "Timer-Speicherung"
		0, //uint16_t wData_2; //2
		{
			&Data_234e96d4,
			&Data_234e9954,
			0, 0, 0
		}, //int fill_4[5]; //4
		get_timer_storage_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23490826, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
#if 0
0x234ea260                        dw         0x018f
0x234ea262                        dw         0x00f4
0x234ea264                        dd         0x234e96d4
0x234ea268                        dd         0x234e9954
0x234ea26c 0000                   movs       r0, r0
0x234ea26e 0000                   movs       r0, r0
0x234ea270 0000                   movs       r0, r0
0x234ea272 0000                   movs       r0, r0
0x234ea274 0000                   movs       r0, r0
0x234ea276 0000                   movs       r0, r0
0x234ea278                        dd         get_timer_storage_value_string+1
0x234ea27c                        dd         sub_23490826+1
0x234ea280                        dd         menu_item_event_thread+1
0x234ea284 0000                   movs       r0, r0
0x234ea286 0000                   movs       r0, r0
0x234ea288 0000                   movs       r0, r0
0x234ea28a 0000                   movs       r0, r0
#endif
	},	//234EA28C?
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
		get_channel_list_sorting_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
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
0x234ea2fc                        dd         get_channel_list_sorting_value_string+1
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
		get_channel_list_update_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
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
0x234ea328                        dd         get_channel_list_update_value_string+1
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
uint8_t Data_2397056c[40]; //2397056c
uint8_t Data_23970594[40]; //23970594
uint8_t Data_239705bc[40]; //239705bc
uint8_t Data_239705e4[40]; //239705e4
uint8_t Data_2397060c[40]; //2397060c
uint8_t Data_23970634[40]; //23970634
uint8_t Data_2397065c[40]; //2397065c
uint8_t Data_23970684[40]; //23970684
uint8_t Data_239706d4[40]; //239706d4
uint8_t Data_239706fc[40]; //239706fc
uint8_t Data_23970724[40]; //23970724
uint8_t Data_2397074c[40]; //2397074c
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

#else //!VDR110


/*  /  / 234905f0 - todo */
void get_time_difference_value_string(Menu_Item* item)
{
#if 0
	console_send_string("get_time_difference_value_string (todo.c): TODO\r\n");
#endif

	uint8_t sp4[16]; //size???
	//uint8_t* sp;
	int r0;
	int r7;
	Menu_Item_Inner4_Data_0* r5 = item->Data_4[1];
	uint8_t* r6 = r5->Data_0x20->Data_0x10;
	uint8_t r4 = menu_general_settings_backup.timeDiff & 0x7f;

	if (r4 == 24)
	{
		//0x23490606
		r0 = 0;
		//->loc_23490616
	}
	else
	{
		//loc_2349060a
		//r2 = r4
		r0 = (menu_general_settings_backup.timeDiff & 0x7f) - 24;
	}
	//loc_23490616
	r7 = r0 * 30;

	if (r5->Data_0x20 != 0)
	{
		//0x2349061e
		text_table_get_string(0x4c/*Std.*/, sp4, 10);

		sp4[9] = 0;

	}
	//loc_2349062e
	if (r4 == 0x31)
	{
		//0x23490632
		//r1 = 0x234909ec
		//->loc_2349063c
		strcpy(r6, "AUTO");
		//->loc_23490674
	}
	//loc_23490636
	else if (r4 == 0x18)
	{
		//0x2349063a
		//r1 = 0x234909f4
		//loc_2349063c
		strcpy(r6, "GMT");
		//->loc_23490674
	}
	//loc_23490644
	else if (r4 < 0x18)
	{
		//0x23490648
		int r2 = (0 - r7) / 60;
		int r3 = (0 - r7) % 60;

		//sp = &sp4[0];
		//r1 = "-%d.%02d %s"
		//->loc_2349066e
		sprintf(r6, "-%d.%02d %s", r2, r3, &sp4[0]);
	}
	else
	{
		//loc_2349065c
		int r2 = r7 / 60;
		int r3 = r7 % 60;

		//sp = &sp4[0];
		//r1 = "+%d.%02d %s"
		//loc_2349066e
		sprintf(r6, "+%d.%02d %s", r2, r3, &sp4[0]);
	}
	//loc_23490674
	r5->Data_0x20->bData_0x17 = 1;
}


/*  /  / 2349067e - complete */
int menu_language_change(int* a)
{
#if 0
	console_send_string("menu_language_change (todo.c): TODO\r\n");
#endif

	uint8_t str[4];
	User_Settings settings;
	int a_ = *a;
	Menu_Item* pMenuItem = menu_general_settings_p->Data_8;

	if (a_ & (1 << 3))
	{
		if (text_table_get_num_languages() <= ++menu_general_settings_backup.menuLanguage)
		{
			menu_general_settings_backup.menuLanguage = 0;
		}
	}
	else
	{
		if (menu_general_settings_backup.menuLanguage == 0)
		{
			menu_general_settings_backup.menuLanguage = text_table_get_num_languages() - 1;
		}
		else
		{
			menu_general_settings_backup.menuLanguage--;
		}
	}

	sub_234082f4();

	text_table_get_string(0, &str[0], 4);

	sub_2344d8f8();

	get_time_difference_value_string(pMenuItem + 1);

	channel_handle_user_settings(1, &settings);

	if (menu_general_settings_backup.menuLanguage == settings.menuLanguage)
	{
		return 1;
	}

	return 0;
}


/*  /  / 234906ee - complete */
void get_menu_language_string(struct Menu_Item* a)
{
#if 0
	console_send_string("get_menu_language_string (todo.c): TODO\r\n");
#endif

	uint8_t* str =  a->Data_4[1]->Data_0x20->Data_0x10;

	if (a->Data_4[1]->Data_0x20 != 0)
	{
		text_table_get_string(2, str, 40);
		str[39] = 0;
	}
}


/*  /  / 23490756 - complete */
int menu_initial_volume_change(int* a)
{
#if 0
	console_send_string("menu_initial_volume_change (todo.c): TODO\r\n");
#endif

	int r0_ = *a;
	User_Settings settings;

	if (r0_ & (1 << 3))
	{
		menu_general_settings_backup.initialVolume = channel_change_volume(1, 1);
	}
	else if (r0_ & (1 << 2))
	{
		menu_general_settings_backup.initialVolume = channel_change_volume(1, -1);
	}

	uint8_t* r0 = (void*) channel_get_volume_table();
	menu_general_settings_backup.initialVolume = r0[menu_general_settings_backup.initialVolume];

	channel_handle_user_settings(1, &settings);

	if (menu_general_settings_backup.initialVolume == settings.initialVolume)
	{
		return 1;
	}

	return 0;
}


/*  /  / 2349079c - complete */
void get_initial_volume_value_string(Menu_Item* item)
{
#if 0
	console_send_string("get_initial_volume_value_string (todo.c): TODO\r\n");
#endif

	uint8_t* str = item->Data_4[1]->Data_0x20->Data_0x10;

	uint32_t r0 = sub_2340a650(menu_general_settings_backup.initialVolume);

	sprintf(str, "%d%%", (r0 * 204800) >> 16);
}


/* /  / 23490826 - todo */
int sub_23490826(int* a)
{
#if 1
	console_send_string("sub_23490826 (todo.c): TODO\r\n");
#endif

	return 0;
}


/* /  / 23490862 - todo */
void get_timer_storage_value_string(Menu_Item* pItem)
{
	uint8_t* str = pItem->Data_4[1]->Data_0x20->Data_0x10;

	pItem->Data_4[1]->Data_0x20->bData_0x17 = 1;

	if (menu_general_settings_backup.Data_0x10 & (1 << 11))
	{
		text_table_get_string(0x14, str, 38);
	}
	else
	{
		text_table_get_string(0x13, str, 38);
	}
}


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


/* /  / 23490984 - todo */
void get_channel_list_sorting_value_string(Menu_Item* pItem)
{
	Menu_Item_Inner4_Data_0* r0_ = pItem->Data_4[1];
	Menu_Item_Inner4_Data_0_Data_0x20* r0 = r0_->Data_0x20;
	uint8_t* str = r0->Data_0x10;

	r0->bData_0x17 = 1;

	if ((menu_general_settings_backup.Data_4 & (0x03 << 23)))
	{
		text_table_get_string(0xc0/*Automatisch*/, str, 38);
	}
	else
	{
		text_table_get_string(0xbf/*Manuell*/, str, 38);
	}
}


/* /  / 23490a2c - todo */
void get_channel_list_update_value_string(Menu_Item* pItem)
{
	Menu_Item_Inner4_Data_0* r0_ = pItem->Data_4[1];
	Menu_Item_Inner4_Data_0_Data_0x20* r0 = r0_->Data_0x20;
	uint8_t* str = r0->Data_0x10;

	r0->bData_0x17 = 1;

	if (menu_general_settings_backup.Data_0x10 & (1 << 7))
	{
		text_table_get_string(0xc0/*Automatisch*/, str, 38);
	}
	else
	{
		text_table_get_string(0xbf/*Manuell*/, str, 38);
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
#ifndef VDR110
	sub_23418a50(&menu_general_settings_backup, 1); //->av.c
#endif

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

