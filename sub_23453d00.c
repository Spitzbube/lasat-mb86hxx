
#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "menu.h"

#ifndef VDR110

#pragma thumb

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12d4; //234c12d4
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c131c; //234c131c
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c1334; //234c1334
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c134c; //234c134c

extern void sub_2344f6ac();
static void sub_23453fea();

static Menu Data_234c4e7c; //234c4e7c
static uint8_t Data_23799454[]; //23799454
static uint8_t Data_2379947c[]; //2379947c
static uint8_t Data_237994a4[]; //237994a4
static uint8_t Data_237994cc[]; //237994cc
static uint8_t Data_237994f4[]; //237994f4
static uint8_t Data_2379960c[]; //2379960c

//0x234c2f60
static void (*Data_234c2f68)() = sub_23453fea; //234C2F68 +8
static Menu* Data_234c2f70 = &Data_234c4e7c; //234C2F70 +0x10

static uint8_t Data_234c315c[40] = "1"; //234c315c, size???

static Graphic_Job_2_5_Item_Text Data_234c3184 = //234c3184
{
	0, 0x0051, 0x0064, 0x00fd, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_234c315c[0], 0, 0, 0
#if 0
0x234c3184                        db         0x00                               ; DATA XREF=0x234c34b4
0x234c3185                        db         0x00
0x234c3186                        dw         0x0051
0x234c3188                        dw         0x0064
0x234c318a                        dw         0x00fd
0x234c318c                        dw         0x0080
0x234c318e                        db         0x01
0x234c318f                        db         0x04
0x234c3190                        db         0x09
0x234c3191                        db         0x01
0x234c3192 0000                   movs       r0, r0
0x234c3194                        dd         0x234c315c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c319c = //234c319c
{
	0, 0x0051, 0x0084, 0x00fd, 0x00a0, 0x01, 0x04, 0x09, 0x01, &Data_23799454[0], 0, 0, 0
#if 0
0x234c319c                        db         0x00                               ; DATA XREF=0x234c34f4
0x234c319d                        db         0x00
0x234c319e                        dw         0x0051
0x234c31a0                        dw         0x0084
0x234c31a2                        dw         0x00fd
0x234c31a4                        dw         0x00a0
0x234c31a6                        db         0x01
0x234c31a7                        db         0x04
0x234c31a8                        db         0x09
0x234c31a9                        db         0x01
0x234c31aa 0000                   movs       r0, r0
0x234c31ac                        dd         0x23799454
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c31b4 = //234c31b4
{
	0, 0x0051, 0x00a4, 0x00fd, 0x00c0, 0x01, 0x04, 0x09, 0x01, &Data_2379947c[0], 0, 0, 0
#if 0
0x234c31b4                        db         0x00                               ; DATA XREF=0x234c3534
0x234c31b5                        db         0x00
0x234c31b6                        dw         0x0051
0x234c31b8                        dw         0x00a4
0x234c31ba                        dw         0x00fd
0x234c31bc                        dw         0x00c0
0x234c31be                        db         0x01
0x234c31bf                        db         0x04
0x234c31c0                        db         0x09
0x234c31c1                        db         0x01
0x234c31c2 0000                   movs       r0, r0
0x234c31c4                        dd         0x2379947c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c31cc = //234c31cc
{
	0, 0x0051, 0x00c4, 0x00fd, 0x00e0, 0x01, 0x04, 0x09, 0x01, &Data_237994a4[0], 0, 0, 0
#if 0
0x234c31cc                        db         0x00                               ; DATA XREF=0x234c3574
0x234c31cd                        db         0x00
0x234c31ce                        dw         0x0051
0x234c31d0                        dw         0x00c4
0x234c31d2                        dw         0x00fd
0x234c31d4                        dw         0x00e0
0x234c31d6                        db         0x01
0x234c31d7                        db         0x04
0x234c31d8                        db         0x09
0x234c31d9                        db         0x01
0x234c31da 0000                   movs       r0, r0
0x234c31dc                        dd         0x237994a4
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c31e4 = //234c31e4
{
	0, 0x0051, 0x00e4, 0x00fd, 0x0100, 0x01, 0x04, 0x09, 0x01, &Data_237994cc[0], 0, 0, 0
#if 0
0x234c31e4                        db         0x00                               ; DATA XREF=0x234c35b4
0x234c31e5                        db         0x00
0x234c31e6                        dw         0x0051
0x234c31e8                        dw         0x00e4
0x234c31ea                        dw         0x00fd
0x234c31ec                        dw         0x0100
0x234c31ee                        db         0x01
0x234c31ef                        db         0x04
0x234c31f0                        db         0x09
0x234c31f1                        db         0x01
0x234c31f2 0000                   movs       r0, r0
0x234c31f4                        dd         0x237994cc
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c31fc = //234c31fc
{
	0, 0x0051, 0x0104, 0x00fd, 0x0120, 0x01, 0x04, 0x09, 0x01, &Data_237994f4[0], 0, 0, 0
#if 0
0x234c31fc                        db         0x00                               ; DATA XREF=0x234c35f4
0x234c31fd                        db         0x00
0x234c31fe                        dw         0x0051
0x234c3200                        dw         0x0104
0x234c3202                        dw         0x00fd
0x234c3204                        dw         0x0120
0x234c3206                        db         0x01
0x234c3207                        db         0x04
0x234c3208                        db         0x09
0x234c3209                        db         0x01
0x234c320a 0000                   movs       r0, r0
0x234c320c                        dd         0x237994f4
#endif
};


static Graphic_Job_2_5_Item_Text Data_234c32fc = //234c32fc
{
	0, 0x0051, 0x0134, 0x0125, 0x0150, 0x01, 0x04, 0x09, 0x01, &Data_2379960c[0], 0, 0, 0
#if 0
0x234c32fc                        db         0x00                               ; DATA XREF=0x234c39b4
0x234c32fd                        db         0x00
0x234c32fe                        dw         0x0051
0x234c3300                        dw         0x0134
0x234c3302                        dw         0x0125
0x234c3304                        dw         0x0150
0x234c3306                        db         0x01
0x234c3307                        db         0x04
0x234c3308                        db         0x09
0x234c3309                        db         0x01
0x234c330a 0000                   movs       r0, r0
0x234c330c                        dd         0x2379960c
#endif
};



static Graphic_Job_2_5_Item Data_234c3394[] = //234c3394
{
	{0}, //[0] = 234c3394 
	{0}, //[1] = 234C33D4 
	{0}, //[2] = 234C3414 
	{0}, //[3] = 234C3454 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x60, 0xc0, 0x20, 0, &Data_234c1334/*Data_0x18*/, 9, 0, &Data_234c3184/*Data_0x20*/}, //[4] = 234C3494 
#if 0
0x234c3494                        db         0x01                               ; DATA XREF=0x234c4c18
0x234c3495                        db         0x00
0x234c3496                        db         0x00
0x234c3497                        db         0x00
0x234c3498                        dd         0x00000000
0x234c349c 0000                   movs       r0, r0
0x234c349e 0000                   movs       r0, r0
0x234c34a0                        dw         0x003d
0x234c34a2                        dw         0x0060
0x234c34a4                        dw         0x00c0
0x234c34a6                        dw         0x0020
0x234c34a8 0000                   movs       r0, r0
0x234c34aa 0000                   movs       r0, r0
0x234c34ac                        dd         0x234c1334
0x234c34b0                        dw         0x0009
0x234c34b2                        dw         0x0000
0x234c34b4                        dd         0x234c3184
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x80, 0xc0, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234c319c/*Data_0x20*/}, //[5] = 234C34D4 
#if 0
0x234c34d4                        db         0x01                               ; DATA XREF=0x234c4c44
0x234c34d5                        db         0x00
0x234c34d6                        db         0x00
0x234c34d7                        db         0x00
0x234c34d8                        dd         0x00000000
0x234c34dc                        db  0x00 ; '.'
0x234c34dd                        db  0x00 ; '.'
0x234c34de                        db  0x00 ; '.'
0x234c34df                        db  0x00 ; '.'
0x234c34e0                        dw         0x003d
0x234c34e2                        dw         0x0080
0x234c34e4                        dw         0x00c0
0x234c34e6                        dw         0x0020
0x234c34e8 0000                   movs       r0, r0
0x234c34ea 0000                   movs       r0, r0
0x234c34ec                        dd         0x234c12d4
0x234c34f0                        dw         0x0009
0x234c34f2                        dw         0x0000
0x234c34f4                        dd         0x234c319c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xa0, 0xc0, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234c31b4/*Data_0x20*/}, //[6] = 234C3514 
#if 0
0x234c3514                        db         0x01                               ; DATA XREF=0x234c4c70
0x234c3515                        db         0x00
0x234c3516                        db         0x00
0x234c3517                        db         0x00
0x234c3518                        dd         0x00000000
0x234c351c                        dd         0x00000000
0x234c3520                        dw         0x003d
0x234c3522                        dw         0x00a0
0x234c3524                        dw         0x00c0
0x234c3526                        dw         0x0020
0x234c3528 0000                   movs       r0, r0
0x234c352a 0000                   movs       r0, r0
0x234c352c                        dd         0x234c12d4
0x234c3530                        dw         0x0009
0x234c3532                        dw         0x0000
0x234c3534                        dd         0x234c31b4
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xc0, 0xc0, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234c31cc/*Data_0x20*/}, //[7] = 234C3554 
#if 0
0x234c3554                        db         0x01                               ; DATA XREF=0x234c4c9c
0x234c3555                        db         0x00
0x234c3556                        db         0x00
0x234c3557                        db         0x00
0x234c3558                        dd         0x00000000
0x234c355c                        dd         0x00000000
0x234c3560                        dw         0x003d
0x234c3562                        dw         0x00c0
0x234c3564                        dw         0x00c0
0x234c3566                        dw         0x0020
0x234c3568 0000                   movs       r0, r0
0x234c356a 0000                   movs       r0, r0
0x234c356c                        dd         0x234c12d4
0x234c3570                        dw         0x0009
0x234c3572                        dw         0x0000
0x234c3574                        dd         0x234c31cc
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xe0, 0xc0, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234c31e4/*Data_0x20*/}, //[8] = 234C3594 
#if 0
0x234c3594                        db         0x01                               ; DATA XREF=0x234c4cc8
0x234c3595                        db         0x00
0x234c3596                        db         0x00
0x234c3597                        db         0x00
0x234c3598                        dd         0x00000000
0x234c359c                        dd         0x00000000
0x234c35a0                        dw         0x003d
0x234c35a2                        dw         0x00e0
0x234c35a4                        dw         0x00c0
0x234c35a6                        dw         0x0020
0x234c35a8 0000                   movs       r0, r0
0x234c35aa 0000                   movs       r0, r0
0x234c35ac                        dd         0x234c12d4
0x234c35b0                        dw         0x0009
0x234c35b2                        dw         0x0000
0x234c35b4                        dd         0x234c31e4
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x100, 0xc0, 0x20, 0, &Data_234c131c/*Data_0x18*/, 9, 0, &Data_234c31fc/*Data_0x20*/}, //[9] = 234C35D4 
#if 0
0x234c35d4                        db         0x01                               ; DATA XREF=0x234c4cf4
0x234c35d5                        db         0x00
0x234c35d6                        db         0x00
0x234c35d7                        db         0x00
0x234c35d8                        dd         0x00000000
0x234c35dc                        dd         0x00000000
0x234c35e0                        dw         0x003d
0x234c35e2                        dw         0x0100
0x234c35e4                        dw         0x00c0
0x234c35e6                        dw         0x0020
0x234c35e8 0000                   movs       r0, r0
0x234c35ea 0000                   movs       r0, r0
0x234c35ec                        dd         0x234c131c
0x234c35f0                        dw         0x0009
0x234c35f2                        dw         0x0000
0x234c35f4                        dd         0x234c31fc
#endif
	{0}, //[10] = 234C3614 
	{0}, //[11] = 234C3654 
	{0}, //[12] = 234C3694 
	{0}, //[13] = 234C36D4 
	{0}, //[14] = 234C3714 
	{0}, //[15] = 234C3754 
	{0}, //[16] = 234C3794 
	{0}, //[17] = 234C37D4 
	{0}, //[18] = 234C3814 
	{0}, //[19] = 234C3854 
	{0}, //[20] = 234C3894 
	{0}, //[21] = 234C38D4 
	{0}, //[22] = 234C3914 
	{0}, //[23] = 234C3954 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x130, 0xe8, 0x20, 0, &Data_234c134c/*Data_0x18*/, 9, 0, &Data_234c32fc/*Data_0x20*/}, //[24] = 234C3994 
#if 0
0x234c3994                        db         0x01                               ; DATA XREF=0x234c4d20
0x234c3995                        db         0x00
0x234c3996                        db         0x00
0x234c3997                        db         0x00
0x234c3998                        dd         0x00000000
0x234c399c                        dd         0x00000000
0x234c39a0                        dw         0x003d
0x234c39a2                        dw         0x0130
0x234c39a4                        dw         0x00e8
0x234c39a6                        dw         0x0020
0x234c39a8 0000                   movs       r0, r0
0x234c39aa 0000                   movs       r0, r0
0x234c39ac                        dd         0x234c134c
0x234c39b0                        dw         0x0009
0x234c39b2                        dw         0x0000
0x234c39b4                        dd         0x234c32fc
#endif
	{0}, //[25] = 234C39D4 
	{0}, //[26] = 234C3A14 
	{0}, //[27] = 234C3A54 
	{0}, //[28] = 234C3A94 
	{0}, //[29] = 234C3AD4 
	{0}, //[30] = 234C3B14 
	{0}, //[31] = 234C3B54 
	{0}, //[32] = 234C3B94 
	{0}, //[33] = 234C3BD4 
};

static Graphic_Job_2_5 Data_234c4b84 = //234c4b84
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x000d, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234c3394[0], //Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	0x10, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	34, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
	0, //0x1c
	0, //0x20
#if 0
0x234c4b84                        db         0x00                               ; DATA XREF=sub_23452b1c+10, sub_23452b1c+342, sub_234533bc+12, sub_234538b0+12, dword_234c4e90
0x234c4b85                        db         0xfa
0x234c4b86                        dw         0x000d
0x234c4b88                        db         0x04
0x234c4b89                        db         0x00
0x234c4b8a                        db         0x00
0x234c4b8b                        db         0x00
0x234c4b8c                        dd         0x234c3394                         ; DATA XREF=sub_234533bc+24
0x234c4b90                        dd         menu_main_graphic_color_data
0x234c4b94                        db         0x10
0x234c4b95                        db  0x00 ; '.'
0x234c4b96 0000                   movs       r0, r0
0x234c4b98 0000                   movs       r0, r0
0x234c4b9a 0000                   movs       r0, r0
0x234c4b9c                        db         0x22
0x234c4b9d                        db         0x01
0x234c4b9e 0000                   movs       r0, r0
0x234c4ba0                        dd         sub_23452ab8+1
0x234c4ba4                        dd         sub_23452aa4+1
#endif
};

static Menu_Item Data_234c4c14[] = //234c4c14
{
	//[0]
	{
		0xbd, //"Antenne" / "Satellite"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c3394[4], //234c3494,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //void* onEvent; //0x1c = 28
		menu_item_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C4C40
#if 0
0x234c4c14                        dw         0x00bd                             ; DATA XREF=sub_234533bc+16, sub_234533bc+748, sub_234538b0+34, 0x234c4e80, dword_234c4e84
0x234c4c16                        dw         0x00f4
0x234c4c18                        dd         0x234c3494
0x234c4c1c                        dd         0x234c3654
0x234c4c20 0000                   movs       r0, r0
0x234c4c22 0000                   movs       r0, r0
0x234c4c24 0000                   movs       r0, r0
0x234c4c26 0000                   movs       r0, r0
0x234c4c28 0000                   movs       r0, r0
0x234c4c2a 0000                   movs       r0, r0
0x234c4c2c                        dd         sub_23453d36+1
0x234c4c30                        dd         sub_23453d78+1
0x234c4c34                        dd         menu_item_event_thread+1
0x234c4c38 0000                   movs       r0, r0
0x234c4c3a 0000                   movs       r0, r0
0x234c4c3c 0000                   movs       r0, r0
0x234c4c3e 0000                   movs       r0, r0
#endif
	},
	//[1]
	{
		0x1d, //"Suchmodus" / "Search mode"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c3394[5], //234c34d4,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //void* onEvent; //0x1c = 28
		menu_item_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C4C6C
#if 0
0x234c4c40                        dw         0x001d
0x234c4c42                        dw         0x00f4
0x234c4c44                        dd         0x234c34d4
0x234c4c48                        dd         0x234c3694
0x234c4c4c 0000                   movs       r0, r0
0x234c4c4e 0000                   movs       r0, r0
0x234c4c50 0000                   movs       r0, r0
0x234c4c52 0000                   movs       r0, r0
0x234c4c54 0000                   movs       r0, r0
0x234c4c56 0000                   movs       r0, r0
0x234c4c58                        dd         sub_23453f1a+1
0x234c4c5c                        dd         sub_23453f4e+1
0x234c4c60                        dd         menu_item_event_thread+1
#endif
	},
	//[2]
	{
		0x1e, //"Verschl▒sselt" / "Encrypted"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c3394[6], //234c3514,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //void* onEvent; //0x1c = 28
		menu_item_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C4C98
#if 0
0x234c4c6c                        dw         0x001e                             ; DATA XREF=sub_234533bc+20, sub_234538b0+38
0x234c4c6e                        dw         0x00f4
0x234c4c70                        dd         0x234c3514
0x234c4c74                        dd         0x234c36d4
0x234c4c78 0000                   movs       r0, r0
0x234c4c7a 0000                   movs       r0, r0
0x234c4c7c 0000                   movs       r0, r0
0x234c4c7e 0000                   movs       r0, r0
0x234c4c80 0000                   movs       r0, r0
0x234c4c82 0000                   movs       r0, r0
0x234c4c84                        dd         sub_23453fa8+1
0x234c4c88                        dd         sub_23453fa8+41
0x234c4c8c                        dd         menu_item_event_thread+1
#endif
	},
	//[3]
	{
		0x19, //"Frequenz" / "Frequency"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c3394[7], //234c3554,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //void* onEvent; //0x1c = 28
		sub_2344f6ac, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C4CC4
#if 0
0x234c4c98                        dw         0x0019                             ; DATA XREF=sub_234533bc+38, sub_234533bc+758, sub_234533bc+764, sub_234538b0+48
0x234c4c9a                        dw         0x00f5                             ; DATA XREF=sub_234533bc+782
0x234c4c9c                        dd         0x234c3554
0x234c4ca0                        dd         0x234c3714
0x234c4ca4 0000                   movs       r0, r0
0x234c4ca6 0000                   movs       r0, r0
0x234c4ca8 0000                   movs       r0, r0
0x234c4caa 0000                   movs       r0, r0
0x234c4cac 0000                   movs       r0, r0
0x234c4cae 0000                   movs       r0, r0
0x234c4cb0                        dd         sub_23453164+1                     ; DATA XREF=sub_234533bc+798
0x234c4cb4                        dd         sub_2345327c+1                     ; DATA XREF=sub_234533bc+796
0x234c4cb8                        dd         sub_2344f6ac+1                     ; DATA XREF=sub_234533bc+792
#endif
	},
	//[4]
	{
		0x1a, //"Polarisation" / "Polarisation"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c3394[8], //234c3594,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //void* onEvent; //0x1c = 28
		menu_item_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C4CF0
#if 0
0x234c4cc4                        dw         0x001a                             ; DATA XREF=sub_234533bc+46, sub_234533bc+762, sub_234533bc+768, sub_234538b0+52
0x234c4cc6                        dw         0x00f4                             ; DATA XREF=sub_234533bc+788
0x234c4cc8                        dd         0x234c3594
0x234c4ccc                        dd         0x234c3754
0x234c4cd0 0000                   movs       r0, r0
0x234c4cd2 0000                   movs       r0, r0
0x234c4cd4 0000                   movs       r0, r0
0x234c4cd6 0000                   movs       r0, r0
0x234c4cd8 0000                   movs       r0, r0
0x234c4cda 0000                   movs       r0, r0
0x234c4cdc                        dd         sub_23453136+1                     ; DATA XREF=sub_234533bc+806
0x234c4ce0                        dd         sub_2345323c+1                     ; DATA XREF=sub_234533bc+800
0x234c4ce4                        dd         menu_item_event_thread+1           ; DATA XREF=sub_234533bc+804
#endif
	},
	//[5]
	{
		0x1b, //"Symbolrate" / "Symbol rate"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c3394[9], //234c35d4,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //void* onEvent; //0x1c = 28
		sub_2344f6ac, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C4D1C
#if 0
0x234c4cf0                        dw         0x001b                             ; DATA XREF=sub_234533bc+48, sub_234533bc+756, sub_234538b0+54
0x234c4cf2                        dw         0x00f5
0x234c4cf4                        dd         0x234c35d4
0x234c4cf8                        dd         0x234c3794
0x234c4cfc 0000                   movs       r0, r0
0x234c4cfe 0000                   movs       r0, r0
0x234c4d00 0000                   movs       r0, r0
0x234c4d02 0000                   movs       r0, r0
0x234c4d04 0000                   movs       r0, r0
0x234c4d06 0000                   movs       r0, r0
0x234c4d08                        dd         sub_234530e8+1
0x234c4d0c                        dd         sub_234531bc+1
0x234c4d10                        dd         sub_2344f6ac+1
#endif
	},
	//[6]
	{
		0x1c, //"Starte Sendersuche" / "Start scan"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c3394[24], //234c3994,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C4D48
#if 0
0x234c4d1c                        dw         0x001c
0x234c4d1e                        dw         0x00f3
0x234c4d20                        dd         0x234c3994
0x234c4d24 0000                   movs       r0, r0
0x234c4d26 0000                   movs       r0, r0
0x234c4d28 0000                   movs       r0, r0
0x234c4d2a 0000                   movs       r0, r0
0x234c4d2c 0000                   movs       r0, r0
0x234c4d2e 0000                   movs       r0, r0
0x234c4d30 0000                   movs       r0, r0
0x234c4d32 0000                   movs       r0, r0
0x234c4d34 0000                   movs       r0, r0
0x234c4d36 0000                   movs       r0, r0
0x234c4d38                        dd         sub_23452c86+1
0x234c4d3c                        dd         menu_event_thread+1
#endif
	},
};


static Menu Data_234c4e7c = //234c4e7c
{
		0x000d, //"Sendersuche" / "Channel search"
		&Data_234c4c14[0], //Menu_Item* Data_4; //4
		&Data_234c4c14[0], //Menu_Item* Data_8; //8
		&Data_234c3394[32], //234c3b94, //Struct_235fdf74_Inner12* header; //12 = 0xc
		/*&Data_234c3414*/0, //Struct_235fdf74_Inner16* help; //16 = 0x10
		&Data_234c4b84, //int graphicData; //20 = 0x14
		6, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		graphic_start_job_2_5, //void (*Data_0x1c)(); //0x1c
		menu_items_navigate, //void (*onNavigate)(); //0x20
		//TODO!!!
#if 0
0x234c4e7c                        dw         0x000d                             ; DATA XREF=sub_23452b1c+8, sub_23452b1c+16, sub_23452b1c+340, sub_234533bc+10, sub_234533bc+744, sub_234538b0+10, sub_234538b0+26, dword_234c2f70
0x234c4e7e                        dw         0x0000
0x234c4e80                        dd         0x234c4c14
0x234c4e84                        dd         0x234c4c14                         ; DATA XREF=sub_234533bc+16, sub_234533bc+748, sub_234538b0+34
0x234c4e88                        dd         0x234c3b94
0x234c4e8c                        dd         0x234c3414
0x234c4e90                        dd         0x234c4b84                         ; DATA XREF=sub_23452b1c+10, sub_23452b1c+342, sub_234533bc+12, sub_234538b0+12
0x234c4e94                        db         0x06
0x234c4e95                        db         0x00
0x234c4e96 0000                   movs       r0, r0
0x234c4e98                        dd         graphic_start_job_2_5
0x234c4e9c                        dd         menu_items_navigate+1
0x234c4ea0                        dd         sub_23453a48+1
0x234c4ea4                        dd         sub_23453c52+1
0x234c4ea8 0000                   movs       r0, r0
0x234c4eaa 0000                   movs       r0, r0
0x234c4eac 0000                   movs       r0, r0
0x234c4eae 0000                   movs       r0, r0
0x234c4eb0 0000                   movs       r0, r0
0x234c4eb2 0000                   movs       r0, r0
0x234c4eb4 0000                   movs       r0, r0
0x234c4eb6 0000                   movs       r0, r0
#endif
    //234C4EB8
};

static uint8_t Data_23799454[40]; //23799454
static uint8_t Data_2379947c[40]; //2379947c
static uint8_t Data_237994a4[40]; //237994a4
static uint8_t Data_237994cc[40]; //237994cc
static uint8_t Data_237994f4[40]; //237994f4, size???
static uint8_t Data_2379960c[40]; //2379960c, size???


/* /  / 23453cbc - todo */
static void sub_23453cbc()
{
#if 1
	console_send_string("sub_23453cbc (todo.c): TODO\r\n");
#endif

}


/* /  / 23453d00 - todo */
int sub_23453d00(UI_Thread_Params* r5)
{
#if 1
	console_send_string("sub_23453d00 (todo.c): TODO\r\n");
#endif

    if (sub_23421f84() != 0)
    {
        return 1;
    }
    //loc_23453d10
    if (/*sub_2340fbac*/sub_2340d0d0() == 1)
    {
        Data_234c2f68 = sub_23453cbc;
    }
    //loc_23453d1e
    menu_stack_operate(Data_234c2f70);
    menu_initialize(Data_234c2f70);
    sub_2343d51e(Data_234c2f70, r5);

    return 0;
}


/* /  / 23453fea */
static void sub_23453fea()
{
#if 1
	console_send_string("sub_23453fea (todo.c): TODO\r\n");
#endif

}


#endif
