
#include "data.h"
#include "graphic.h"
#include "menu.h"

#pragma thumb

#ifndef VDR110

static int menu_installation_items_on_event(void*);
extern void sub_2349615c();

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern Graphic_Job_2_5_Item_Background Data_234c1298; //234c1298
extern Graphic_Job_2_5_Item_Background Data_234c134c; //234c134c

static Menu menu_installation;
static uint8_t Data_23796ad0[]; //23796ad0, size???
static uint8_t Data_23796bf0[]; //23796bf0
static uint8_t Data_23796c18[]; //23796c18
static uint8_t Data_23796c40[]; //23796c40
static uint8_t Data_23796c68[]; //23796c68
static uint8_t Data_23796c90[]; //23796c90
static uint8_t Data_23796ce0[]; //23796ce0


//0x234c21f8
int Data_234c2200 = 0; //234c2200 +8
static Menu* menu_installation_p = &menu_installation; //234c2204 +0xc
void (*Data_234c2214)() = sub_2349615c; //234c2214 +0x1c

static Graphic_Job_2_5_Item_Text Data_234c2220 = //234c2220
{
	0, 0x0051, 0x115, 0x137, 0x12f, 0x01, 0x04, 0x09, 0x01, &Data_23796ce0[0], 0, 0, 0
#if 0
0x234c2220                        db         0x00                               ; DATA XREF=menu_installation_items_on_event+224, 0x234c2698
0x234c2221                        db         0x00
0x234c2222                        dw         0x0051                             ; DATA XREF=menu_installation_items_on_event+228
0x234c2224                        dw         0x0115
0x234c2226                        dw         0x0137                             ; DATA XREF=menu_installation_items_on_event+226
0x234c2228                        dw         0x012f
0x234c222a                        db         0x01
0x234c222b                        db         0x04
0x234c222c                        db         0x09
0x234c222d                        db         0x01
0x234c222e 0000                   movs       r0, r0
0x234c2230                        dd         0x23796ce0
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c2260 = //234c2260
{
	0, 0x0051, 0x002c, 0x0136, 0x004f, 0x01, 0x06, 0x02, 0x00, &Data_23796ad0[0], 0, 0, 0
#if 0
0x234c2260                        db         0x00                               ; DATA XREF=0x234c2398
0x234c2261                        db         0x00
0x234c2262                        dw         0x0051
0x234c2264                        dw         0x002c
0x234c2266                        dw         0x0136
0x234c2268                        dw         0x004f
0x234c226a                        db         0x01
0x234c226b                        db         0x06
0x234c226c                        db         0x02
0x234c226d                        db         0x00
0x234c226e 0000                   movs       r0, r0
0x234c2270                        dd         0x23796ad0
0x234c2274                        dw         0x0000
0x234c2276                        db         0x00
0x234c2277                        db         0x00
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c2290 = //234c2290
{
	0, 0x0051, 0x0064, 0x0136, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_23796bf0[0], 0, 0, 0
#if 0
0x234c2290                        db         0x00                               ; DATA XREF=0x234c2498
0x234c2291                        db         0x00
0x234c2292                        dw         0x0051
0x234c2294                        dw         0x0064
0x234c2296                        dw         0x0136
0x234c2298                        dw         0x0080
0x234c229a                        db         0x01
0x234c229b                        db         0x04
0x234c229c                        db         0x09
0x234c229d                        db         0x01
0x234c229e 0000                   movs       r0, r0
0x234c22a0                        dd         0x23796bf0
0x234c22a4                        dw         0x0000
0x234c22a6                        db         0x00
0x234c22a7                        db         0x00
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c22a8 = //234c22a8
{
	0, 0x0051, 0x0084, 0x0136, 0x00a0, 0x01, 0x04, 0x09, 0x01, &Data_23796c18[0], 0, 0, 0
#if 0
0x234c22a8                        db         0x00                               ; DATA XREF=0x234c24d8
0x234c22a9                        db         0x00
0x234c22aa                        dw         0x0051
0x234c22ac                        dw         0x0084
0x234c22ae                        dw         0x0136
0x234c22b0                        dw         0x00a0
0x234c22b2                        db         0x01
0x234c22b3                        db         0x04
0x234c22b4                        db         0x09
0x234c22b5                        db         0x01
0x234c22b6 0000                   movs       r0, r0
0x234c22b8                        dd         0x23796c18
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c22c0 = //234c22c0
{
	0, 0x0051, 0x00a4, 0x0136, 0x00c0, 0x01, 0x04, 0x09, 0x01, &Data_23796c40[0], 0, 0, 0
#if 0
0x234c22c0                        db         0x00                               ; DATA XREF=0x234c2518
0x234c22c1                        db         0x00
0x234c22c2                        dw         0x0051
0x234c22c4                        dw         0x00a4
0x234c22c6                        dw         0x0136
0x234c22c8                        dw         0x00c0
0x234c22ca                        db         0x01
0x234c22cb                        db         0x04
0x234c22cc                        db         0x09
0x234c22cd                        db         0x01
0x234c22ce                        dw         0x0000
0x234c22d0                        dd         0x23796c40
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c22d8 = //234c22d8
{
	0, 0x0051, 0x00c4, 0x0136, 0x00e0, 0x01, 0x04, 0x09, 0x01, &Data_23796c68[0], 0, 0, 0
#if 0
0x234c22d8                        db         0x00                               ; DATA XREF=0x234c2558
0x234c22d9                        db         0x00
0x234c22da                        dw         0x0051
0x234c22dc                        dw         0x00c4
0x234c22de                        dw         0x0136
0x234c22e0                        dw         0x00e0
0x234c22e2                        db         0x01
0x234c22e3                        db         0x04
0x234c22e4                        db         0x09
0x234c22e5                        db         0x01
0x234c22e6 0000                   movs       r0, r0
0x234c22e8                        dd         0x23796c68
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c22f0 = //234c22f0
{
	0, 0x0051, 0x00e4, 0x0136, 0x0100, 0x01, 0x04, 0x09, 0x01, &Data_23796c90[0], 0, 0, 0
#if 0
0x234c22f0                        db         0x00                               ; DATA XREF=0x234c2598
0x234c22f1                        db         0x00
0x234c22f2                        dw         0x0051
0x234c22f4                        dw         0x00e4
0x234c22f6                        dw         0x0136
0x234c22f8                        dw         0x0100
0x234c22fa                        db         0x01
0x234c22fb                        db         0x04
0x234c22fc                        db         0x09
0x234c22fd                        db         0x01
0x234c22fe 0000                   movs       r0, r0
0x234c2300                        dd         0x23796c90
#endif
};


static Graphic_Job_2_5_Item Data_234c2338[] = //234c2338
{
	{0}, //[0] = 234c2338 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x29, 0xf9, 0x26, 0, &Data_234c134c/*Data_0x18*/, 2, 0, &Data_234c2260/*Data_0x20*/}, //[1] = 234C2378 
#if 0
0x234c2378                        db         0x01                               ; DATA XREF=0x234c2ef4
0x234c2379                        db         0x00
0x234c237a                        db         0x00
0x234c237b                        db         0x00
0x234c237c                        dd         0x234c2240
0x234c2380                        dd         0x00000000
0x234c2384                        dw         0x003d
0x234c2386                        dw         0x0029
0x234c2388                        dw         0x00f9
0x234c238a                        dw         0x0026
0x234c238c                        dw         0x0000
0x234c238e                        db         0x00
0x234c238f                        db         0x00
0x234c2390                        dd         0x234c134c
0x234c2394                        dw         0x0002
0x234c2396                        dw         0x0000
0x234c2398                        dd         0x234c2260
0x234c239c                        dd         0x00000000
0x234c23a0                        dd         0x00000000
0x234c23a4                        dd         0x00000000
0x234c23a8                        dd         0x00000000
0x234c23ac                        dd         0x00000000
0x234c23b0                        dd         0x00000000
0x234c23b4                        dd         0x00000000
#endif
	{0}, //[2] = 234C23B8
	{0}, //[3] =  234C23F8
	{0}, //[4] =  234C2438
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x60, 0xf9, 0x20, 0, &Data_234c1298/*Data_0x18*/, 9, 0, &Data_234c2290/*Data_0x20*/}, //[5] =  234C2478
#if 0
0x234c2478                        db         0x01                               ; DATA XREF=0x234c2c84
0x234c2479                        db         0x00
0x234c247a                        db         0x00
0x234c247b                        db         0x00
0x234c247c                        dd         0x234c2244
0x234c2480                        dd         0x00000000
0x234c2484                        dw         0x003d
0x234c2486                        dw         0x0060
0x234c2488                        dw         0x00f9
0x234c248a                        dw         0x0020
0x234c248c                        dw         0x0000
0x234c248e                        db         0x00
0x234c248f                        db         0x00
0x234c2490                        dd         0x234c1298
0x234c2494                        dw         0x0009
0x234c2496                        dw         0x0000
0x234c2498                        dd         0x234c2290
0x234c249c                        dd         0x00000000
0x234c24a0                        dd         0x00000000
0x234c24a4                        dd         0x00000000
0x234c24a8                        dd         0x00000000
0x234c24ac                        dd         0x00000000
0x234c24b0                        dd         0x00000000
0x234c24b4                        dd         0x00000000
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x80, 0xf9, 0x20, 0, &menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 9, 0, &Data_234c22a8/*Data_0x20*/}, //[6] =  234C24B8
#if 0
0x234c24b8                        db         0x01                               ; DATA XREF=0x234c2cb0
0x234c24b9                        db         0x00
0x234c24ba                        db         0x00
0x234c24bb                        db         0x00
0x234c24bc                        dd         0x234c2244
0x234c24c0                        dd         0x00000000
0x234c24c4                        dw         0x003d
0x234c24c6                        dw         0x0080
0x234c24c8                        dw         0x00f9
0x234c24ca                        dw         0x0020
0x234c24cc                        dw         0x0000
0x234c24ce                        db         0x00
0x234c24cf                        db         0x00
0x234c24d0                        dd         0x234c12e0
0x234c24d4                        dw         0x0009
0x234c24d6                        dw         0x0000
0x234c24d8                        dd         0x234c22a8
0x234c24dc                        dd         0x00000000
0x234c24e0                        dd         0x00000000
0x234c24e4                        dd         0x00000000
0x234c24e8                        dd         0x00000000
0x234c24ec                        dd         0x00000000
0x234c24f0                        dd         0x00000000
0x234c24f4                        dd         0x00000000
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xa0, 0xf9, 0x20, 0, &menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 9, 0, &Data_234c22c0/*Data_0x20*/}, //[7] =  234C24F8
#if 0
0x234c24f8                        db         0x01                               ; DATA XREF=0x234c2cdc
0x234c24f9                        db         0x00
0x234c24fa                        db         0x00
0x234c24fb                        db         0x00
0x234c24fc                        dd         0x234c2244
0x234c2500 0000                   movs       r0, r0
0x234c2502 0000                   movs       r0, r0
0x234c2504                        dw         0x003d
0x234c2506                        dw         0x00a0
0x234c2508                        dw         0x00f9
0x234c250a                        dw         0x0020
0x234c250c 0000                   movs       r0, r0
0x234c250e 0000                   movs       r0, r0
0x234c2510                        dd         0x234c12e0
0x234c2514                        dw         0x0009
0x234c2516                        dw         0x0000
0x234c2518                        dd         0x234c22c0
0x234c251c 0000                   movs       r0, r0
0x234c251e 0000                   movs       r0, r0
0x234c2520 0000                   movs       r0, r0
0x234c2522 0000                   movs       r0, r0
0x234c2524 0000                   movs       r0, r0
0x234c2526 0000                   movs       r0, r0
0x234c2528 0000                   movs       r0, r0
0x234c252a 0000                   movs       r0, r0
0x234c252c 0000                   movs       r0, r0
0x234c252e 0000                   movs       r0, r0
0x234c2530 0000                   movs       r0, r0
0x234c2532 0000                   movs       r0, r0
0x234c2534 0000                   movs       r0, r0
0x234c2536 0000                   movs       r0, r0
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xc0, 0xf9, 0x20, 0, &menu_main_graphic_item_background_dark_blue_bottom_round_left_right/*Data_0x18*/, 9, 0, &Data_234c22d8/*Data_0x20*/}, //[8] =  234C2538
#if 0
0x234c2538                        db         0x01                               ; DATA XREF=0x234c2d08
0x234c2539                        db         0x00
0x234c253a                        db         0x00
0x234c253b                        db         0x00
0x234c253c                        dd         0x234c2244
0x234c2540 0000                   movs       r0, r0
0x234c2542 0000                   movs       r0, r0
0x234c2544                        dw         0x003d
0x234c2546                        dw         0x00c0
0x234c2548                        dw         0x00f9
0x234c254a                        dw         0x0020
0x234c254c 0000                   movs       r0, r0
0x234c254e 0000                   movs       r0, r0
0x234c2550                        dd         0x234c12ec
0x234c2554                        dw         0x0009
0x234c2556                        dw         0x0000
0x234c2558                        dd         0x234c22d8
#endif
	{0, 0, 0, 0/*Data_8*/, 0x3d, 0xe0, 0xf9, 0x20, 0, &menu_main_graphic_item_background_dark_blue_bottom_round_left_right/*Data_0x18*/, 9, 0, &Data_234c22f0/*Data_0x20*/}, //[9] =  234C2578
#if 0
0x234c2578                        db         0x00                               ; DATA XREF=0x234c2d34
0x234c2579                        db         0x00
0x234c257a                        db         0x00
0x234c257b                        db         0x00
0x234c257c                        dd         0x234c2244
0x234c2580 0000                   movs       r0, r0
0x234c2582 0000                   movs       r0, r0
0x234c2584                        dw         0x003d
0x234c2586                        dw         0x00e0
0x234c2588                        dw         0x00f9
0x234c258a                        dw         0x0020
0x234c258c 0000                   movs       r0, r0
0x234c258e 0000                   movs       r0, r0
0x234c2590                        dd         0x234c12ec
0x234c2594                        dw         0x0009
0x234c2596                        dw         0x0000
0x234c2598                        dd         0x234c22f0
#endif
	{0}, //[10] =  234C25B8
	{0}, //[11] =  234C25F8
	{0}, //[12] =  234C2638
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x111, 0xfa, 0x1e, 0, &Data_234c134c/*Data_0x18*/, 9, 0, &Data_234c2220/*Data_0x20*/}, //[13] =  234C2678
#if 0
0x234c2678                        db         0x01                               ; DATA XREF=0x234c2d60
0x234c2679                        db         0x00
0x234c267a                        db         0x00
0x234c267b                        db         0x00
0x234c267c                        dd         0x234c2254
0x234c2680                        dw         0x0000
0x234c2682                        dw         0x0000
0x234c2684                        dw         0x003d
0x234c2686                        dw         0x0111
0x234c2688                        dw         0x00fa
0x234c268a                        dw         0x001e
0x234c268c                        dw         0x0000
0x234c268e                        dw         0x0000
0x234c2690                        dd         0x234c134c
0x234c2694                        dw         0x0009
0x234c2696                        dw         0x0000
0x234c2698                        dd         0x234c2220
#endif
	{0}, //[14] =  234C26B8
	{0}, //[15] =  234C26F8
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x111, 0xfa, 0x1e, 0, &Data_234c134c/*Data_0x18*/, 9, 0, &Data_234c2220/*Data_0x20*/}, //[16] =  234C2738
#if 0
0x234c2678                        db         0x01                               ; DATA XREF=0x234c2d60
0x234c2679                        db         0x00
0x234c267a                        db         0x00
0x234c267b                        db         0x00
0x234c267c                        dd         0x234c2254
0x234c2680                        dw         0x0000
0x234c2682                        dw         0x0000
0x234c2684                        dw         0x003d
0x234c2686                        dw         0x0111
0x234c2688                        dw         0x00fa
0x234c268a                        dw         0x001e
0x234c268c                        dw         0x0000
0x234c268e                        dw         0x0000
0x234c2690                        dd         0x234c134c
0x234c2694                        dw         0x0009
0x234c2696                        dw         0x0000
0x234c2698                        dd         0x234c2220
#endif
	{0}, //[17] =  234C2778
};

static Graphic_Job_2_5 Data_234c2c38 = //234c2c38
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x0009, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234c2338[0], //Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	0x10, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	18, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
	0, //0x1c
	0, //0x20
#if 0
0x234c2c38                        db         0x00                               ; DATA XREF=sub_234523c8+12, sub_2345277e+18, sub_2345277e+20, sub_2345284c+10, dword_234c2efc
0x234c2c39                        db         0xfa
0x234c2c3a                        dw         0x0009
0x234c2c3c                        db         0x04
0x234c2c3d                        db  0x00 ; '.'
0x234c2c3e 0000                   movs       r0, r0
0x234c2c40                        dd         0x234c2338                         ; DATA XREF=sub_234523c8+14, sub_2345277e+22
0x234c2c44                        dd         menu_main_graphic_color_data
0x234c2c48                        db         0x10
0x234c2c49                        db  0x00 ; '.'
0x234c2c4a                        db  0x00 ; '.'
0x234c2c4b                        db  0x00 ; '.'
0x234c2c4c                        db  0x00 ; '.'
0x234c2c4d                        db  0x00 ; '.'
0x234c2c4e                        db  0x00 ; '.'
0x234c2c4f                        db  0x00 ; '.'
0x234c2c50                        db         0x12
0x234c2c51                        db         0x01
0x234c2c52 0000                   movs       r0, r0
0x234c2c54                        dd         0x00000000
0x234c2c58                        dd         0x00000000
#endif
};

static Menu_Item menu_installation_items[] = //234c2c80
{
	//[0]
	{
		0x72, //"Empfangskonfiguration" / "Antenna configuration"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c2338[5], //234c2478,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_installation_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C2CAC
#if 0
0x234c2c80                        dw         0x0072                             ; DATA XREF=sub_234523c8+38, sub_234523c8+184, sub_234523c8+254, sub_234523c8+306, sub_234523c8+400, sub_234523c8+564, sub_234523c8+568, 0x234c2eec, dword_234c2ef0
0x234c2c82                        dw         0x00f3
0x234c2c84                        dd         0x234c2478
0x234c2c88 0000                   movs       r0, r0
0x234c2c8a 0000                   movs       r0, r0
0x234c2c8c 0000                   movs       r0, r0
0x234c2c8e 0000                   movs       r0, r0
0x234c2c90 0000                   movs       r0, r0
0x234c2c92 0000                   movs       r0, r0
0x234c2c94 0000                   movs       r0, r0
0x234c2c96 0000                   movs       r0, r0
0x234c2c98 0000                   movs       r0, r0
0x234c2c9a 0000                   movs       r0, r0
0x234c2c9c                        dd         menu_installation_items_on_event+1                     ; DATA XREF=sub_234523c8+566
0x234c2ca0                        dd         menu_event_thread+1
0x234c2ca4 0000                   movs       r0, r0
0x234c2ca6 0000                   movs       r0, r0
0x234c2ca8 0000                   movs       r0, r0
0x234c2caa 0000                   movs       r0, r0
#endif
	},
	//[1]
	{
		0x0b, //"Sendersuche" / "Channel search"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c2338[6], //234c24b8,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_installation_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C2CD8
#if 0
0x234c2cac                        dw         0x000b                             ; DATA XREF=sub_234523c8+52
0x234c2cae                        dw         0x00f3
0x234c2cb0                        dd         0x234c24b8
0x234c2cb4 0000                   movs       r0, r0
0x234c2cb6 0000                   movs       r0, r0
0x234c2cb8 0000                   movs       r0, r0
0x234c2cba 0000                   movs       r0, r0
0x234c2cbc 0000                   movs       r0, r0
0x234c2cbe 0000                   movs       r0, r0
0x234c2cc0 0000                   movs       r0, r0
0x234c2cc2 0000                   movs       r0, r0
0x234c2cc4 0000                   movs       r0, r0
0x234c2cc6 0000                   movs       r0, r0
0x234c2cc8                        dd         menu_installation_items_on_event+1                     ; DATA XREF=sub_234523c8+570
0x234c2ccc                        dd         menu_event_thread+1
0x234c2cd0 0000                   movs       r0, r0
0x234c2cd2 0000                   movs       r0, r0
0x234c2cd4 0000                   movs       r0, r0
0x234c2cd6 0000                   movs       r0, r0
#endif
	},
	//[2]
	{
		0x57, //"Werkszustand" / "Factory reset"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c2338[7], //234c24f8,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_installation_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C2D04
#if 0
0x234c2cd8                        dw         0x0057                             ; DATA XREF=sub_234523c8+46
0x234c2cda                        dw         0x00f3
0x234c2cdc                        dd         0x234c24f8
0x234c2ce0 0000                   movs       r0, r0
0x234c2ce2 0000                   movs       r0, r0
0x234c2ce4 0000                   movs       r0, r0
0x234c2ce6 0000                   movs       r0, r0
0x234c2ce8 0000                   movs       r0, r0
0x234c2cea 0000                   movs       r0, r0
0x234c2cec 0000                   movs       r0, r0
0x234c2cee 0000                   movs       r0, r0
0x234c2cf0 0000                   movs       r0, r0
0x234c2cf2 0000                   movs       r0, r0
0x234c2cf4                        dd         menu_installation_items_on_event+1
0x234c2cf8                        dd         menu_event_thread+1
0x234c2cfc 0000                   movs       r0, r0
0x234c2cfe 0000                   movs       r0, r0
0x234c2d00 0000                   movs       r0, r0                             ; DATA XREF=sub_234523c8+186, sub_234523c8+256, sub_234523c8+308, sub_234523c8+402
0x234c2d02 0000                   movs       r0, r0
#endif
	},
	//[3]
	{
		0x58, //"Softwareupdate" / "Software download"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c2338[8], //234c2538,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_installation_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C2D30
#if 0
0x234c2d04                        dw         0x0058                             ; DATA XREF=menu_installation_entry+188, menu_installation_entry+258, menu_installation_entry+310, menu_installation_entry+404
0x234c2d06                        dw         0x00f3
0x234c2d08                        dd         0x234c2538
0x234c2d0c 0000                   movs       r0, r0
0x234c2d0e 0000                   movs       r0, r0
0x234c2d10 0000                   movs       r0, r0
0x234c2d12 0000                   movs       r0, r0
0x234c2d14 0000                   movs       r0, r0
0x234c2d16 0000                   movs       r0, r0
0x234c2d18 0000                   movs       r0, r0
0x234c2d1a 0000                   movs       r0, r0
0x234c2d1c 0000                   movs       r0, r0
0x234c2d1e 0000                   movs       r0, r0
0x234c2d20                        dd         menu_installation_items_on_event+1
0x234c2d24                        dd         menu_event_thread+1
0x234c2d28 0000                   movs       r0, r0
0x234c2d2a 0000                   movs       r0, r0
0x234c2d2c 0000                   movs       r0, r0
0x234c2d2e 0000                   movs       r0, r0
#endif
	},
	//[4]
	{
		0x0177, //"SCR (Sat Channel Router)" / "SCR (Sat Channel Router)"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c2338[9], //234c2578,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_installation_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C2D5C
#if 0
0x234c2d30                        dw         0x0177
0x234c2d32                        dw         0x00f3
0x234c2d34                        dd         0x234c2578
0x234c2d38 0000                   movs       r0, r0
0x234c2d3a 0000                   movs       r0, r0
0x234c2d3c 0000                   movs       r0, r0
0x234c2d3e 0000                   movs       r0, r0
0x234c2d40 0000                   movs       r0, r0
0x234c2d42 0000                   movs       r0, r0
0x234c2d44 0000                   movs       r0, r0
0x234c2d46 0000                   movs       r0, r0
0x234c2d48 0000                   movs       r0, r0
0x234c2d4a 0000                   movs       r0, r0
0x234c2d4c                        dd         menu_installation_items_on_event+1
0x234c2d50                        dd         menu_event_thread+1
#endif
	},
	//[5]
	{
		0xffff, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c2338[13], //234c2678,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_installation_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C2D88
#if 0
0x234c2d5c                        dw         0xffff
0x234c2d5e                        dw         0x00f3
0x234c2d60                        dd         0x234c2678
0x234c2d64 0000                   movs       r0, r0
0x234c2d66 0000                   movs       r0, r0
0x234c2d68 0000                   movs       r0, r0
0x234c2d6a 0000                   movs       r0, r0
0x234c2d6c 0000                   movs       r0, r0
0x234c2d6e 0000                   movs       r0, r0
0x234c2d70 0000                   movs       r0, r0
0x234c2d72 0000                   movs       r0, r0
0x234c2d74 0000                   movs       r0, r0
0x234c2d76 0000                   movs       r0, r0
0x234c2d78                        dd         menu_installation_items_on_event+1
0x234c2d7c                        dd         menu_event_thread+1
#endif
	},
	//[6]
	{
		0xffff, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234c2338[16], //234c2738,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_installation_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C2DB4
#if 0
0x234c2d88                        dw         0xffff
0x234c2d8a                        dw         0x00f3
0x234c2d8c                        dd         0x234c2738
0x234c2d90 0000                   movs       r0, r0
0x234c2d92 0000                   movs       r0, r0
0x234c2d94 0000                   movs       r0, r0
0x234c2d96 0000                   movs       r0, r0
0x234c2d98 0000                   movs       r0, r0
0x234c2d9a 0000                   movs       r0, r0
0x234c2d9c 0000                   movs       r0, r0
0x234c2d9e 0000                   movs       r0, r0
0x234c2da0 0000                   movs       r0, r0
0x234c2da2 0000                   movs       r0, r0
0x234c2da4                        dd         menu_installation_items_on_event+1
0x234c2da8                        dd         menu_event_thread+1
0x234c2dac 0000                   movs       r0, r0
0x234c2dae 0000                   movs       r0, r0
0x234c2db0 0000                   movs       r0, r0
0x234c2db2 0000                   movs       r0, r0
#endif
	}
};

static Menu menu_installation = //234c2ee8
{
		0x0079, //"Installation"
		&menu_installation_items[0], //Menu_Item* Data_4; //4
		&menu_installation_items[0], //Menu_Item* Data_8; //8
		&Data_234c2338[1], //234c2378, //Struct_235fdf74_Inner12* header; //12 = 0xc
		/*&Data_234df428*/0, //Struct_235fdf74_Inner16* help; //16 = 0x10
		&Data_234c2c38, //int graphicData; //20 = 0x14
		6, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		graphic_start_job_2_5, //void (*Data_0x1c)(); //0x1c
		menu_items_navigate, //void (*onNavigate)(); //0x20
		//TODO!!!
#if 0
0x234c2ee8                        dw         0x0079                             ; DATA XREF=sub_234523a0+8, sub_234523c8+8, sub_234523c8+182, sub_234523c8+252, sub_234523c8+398, sub_234523c8+560, sub_2345277e+12, sub_2345284e+290, sub_2345284e+466, dword_234c2204
0x234c2eea 0000                   movs       r0, r0
0x234c2eec                        dd         dword_234c2c40+64
0x234c2ef0                        dd         dword_234c2c40+64                  ; DATA XREF=sub_234523c8+38, sub_234523c8+184, sub_234523c8+254, sub_234523c8+306, sub_234523c8+400, sub_234523c8+564, sub_234523c8+568
0x234c2ef4                        dd         dword_234c2288+240
0x234c2ef8                        dd         dword_234c2288+368
0x234c2efc                        dd         dword_234c2288+2480                ; DATA XREF=sub_234523c8+12, sub_2345277e+18, sub_2345277e+20
0x234c2f00                        db  0x06 ; '.'
0x234c2f01                        db         0x00                               ; DATA XREF=sub_234523a0+10, sub_2345284e+292, sub_2345284e+468
0x234c2f02 0000                   movs       r0, r0
0x234c2f04                        dd         graphic_start_job_2_5
0x234c2f08                        dd         menu_items_navigate+1
0x234c2f0c                        dd         sub_23452752+1
0x234c2f10                        dd         sub_23452774+1
0x234c2f14 0000                   movs       r0, r0
0x234c2f16 0000                   movs       r0, r0
0x234c2f18 0A00                   movs       r2, r1
0x234c2f1a 0000                   movs       r0, r0
0x234c2f1c 0000                   movs       r0, r0
0x234c2f1e 0000                   movs       r0, r0
0x234c2f20 0000                   movs       r0, r0
0x234c2f22 0000                   movs       r0, r0
#endif
};


uint8_t Data_23796ad0[40]; //23796ad0, size???
uint8_t Data_23796bf0[40]; //23796bf0
uint8_t Data_23796c18[40]; //23796c18
uint8_t Data_23796c40[40]; //23796c40
uint8_t Data_23796c68[40]; //23796c68
uint8_t Data_23796c90[40]; //23796c90, size???
uint8_t Data_23796ce0[40]; //23796ce0, size???


/*  /  / 234523c8 - todo */
int menu_installation_entry(UI_Thread_Params* sp_0x20)
{
#if 0
	console_send_string("menu_settings_entry (todo.c): TODO\r\n");
#endif

    //loc_234526f6
    if (Data_234c2200 != 0)
    {
        //0x234526fe

        //TODO!!!
    	console_send_string("0x234526fe (menu_installation_entry.c): TODO\r\n");
    }
    //loc_23452734
	menu_stack_operate(menu_installation_p);

	menu_initialize(menu_installation_p);

	sub_2343d51e(menu_installation_p, sp_0x20);

	return 0;
}


/* /  / 2345274c - todo */
void sub_2345274c(void* a)
{
#if 0
	console_send_string("sub_2345274c (todo.c): TODO\r\n");
#endif

	Data_234c2200 = a;
}


/* /  / 2345284c - todo */
int menu_installation_items_on_event(void* r0)
{
#if 0
	console_send_string("menu_installation_items_on_event (todo.c): TODO\r\n");
#endif

//    Menu* r2 = menu_installation_p;
    Graphic_Job_2_5* sp_0x20 = /*r2*/menu_installation_p->graphicData;

    if (r0 != NULL)
    {
        //0x2345285c
        //Menu_Item* r4 = /*r2*/menu_installation_p->Data_8;
		//void (*r3)() = Data_234c2214;

        if (/*r4*//*r2*/menu_installation_p->Data_8->wData_0 == 0x0b) //"Sendersuche"?
        {
            //0x2345286c
#if 0
			switch (/*r2*/menu_installation_p->currentItem)
			{
				case 0:
					//loc_23452890
					sub_23453d00(r0);
					//->loc_23452a38
					break;

				case 1:
					//loc_2345289a
					sub_23452a64();
					//->loc_23452a38
					break;
					
				case 2:
					//loc_234528a4
					(r3)();
					//->loc_23452a38
					break;

				case 5:
					//0x2345287c
					sub_2345b8a0();
					//loc_23452880
					//->loc_23452a38
					break;

				case 6:
					//0x234528c2
					sub_2345b85a();
					//->loc_23452a38
					break;
			}
#else
			if (/*r2*/menu_installation_p->currentItem == 0)
			{
				sub_23453d00(r0);
			}
			else if (/*r2*/menu_installation_p->currentItem == 1)
			{
				sub_23452a64();
			}
			else if (/*r2*/menu_installation_p->currentItem == 2)
			{
				(/*r3*/Data_234c2214)();
			}
			else if (/*r2*/menu_installation_p->currentItem == 5)
			{
				sub_2345b8a0();
			}
			else if (/*r2*/menu_installation_p->currentItem == 6)
			{
				sub_2345b85a();
			}
#endif
        }
		else
		{
	        //loc_23452882
#if 0
			switch (/*r2*/menu_installation_p->currentItem)
			{
				case 0:
					//0x23452886
					sub_234921b2();
					//->loc_23452a38
					break;

				case 1:
					//loc_23452890
					sub_23453d00(r0);
					//->loc_23452a38
					break;

				case 2:
					//loc_2345289a
					sub_23452a64();
					//->loc_23452a38
					break;

				case 3:
					//loc_234528a4
					(r3)();
					//->loc_23452a38
					break;

				case 4:
					//0x234528ac
					if (r4[4].wData_0 == 0x177) //'SCR (Sat Channel Router)'
					{
						//0x234528b8
						sub_234994a2();
						//->loc_23452a38
					}
					//loc_23452880
					break;

				case 5:
					//0x2345287c
					sub_2345b8a0();
					//loc_23452880
					//->loc_23452a38
					break;

				case 6:
					//0x234528c2
					sub_2345b85a();
					//->loc_23452a38
					break;
			}
#else
			if (/*r2*/menu_installation_p->currentItem == 0)
			{
				sub_234921b2();
			}
			else if (/*r2*/menu_installation_p->currentItem == 1)
			{
				sub_23453d00(r0);
			}
			else if (/*r2*/menu_installation_p->currentItem == 2)
			{
				sub_23452a64();
			}
			else if (/*r2*/menu_installation_p->currentItem == 3)
			{
				(/*r3*/Data_234c2214)();
			}
			else if (/*r2*/menu_installation_p->currentItem == 4)
			{
				if (/*r4*//*r2*/menu_installation_p->Data_8[4].wData_0 == 0x177) //'SCR (Sat Channel Router)'
				{
					//0x234528b8
					sub_234994a2();
				}
			}
			else if (/*r2*/menu_installation_p->currentItem == 5)
			{
				sub_2345b8a0();
			}
			else if (/*r2*/menu_installation_p->currentItem == 6)
			{
				sub_2345b85a();
			}
#endif
		}
    } //if (r0 != NULL)
	else
	{
	    //loc_234528c8
		console_send_string("menu_installation_items_on_event: loc_234528c8: TODO!!!\r\n");
	}
	//loc_23452a38
	return 0;
}




#endif //VDR110
