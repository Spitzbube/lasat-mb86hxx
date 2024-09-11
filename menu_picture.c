
#include "data.h"
#include "graphic.h"
#include "menu.h"

#pragma thumb

#ifndef VDR110

extern void menu_item_event_thread();

static void sub_23492b64();
static void get_video_signal_analog_value_string(Menu_Item*);
#if 0
static int menu_video_signal_digital_change();
#endif
static void get_video_signal_digital_value_string(Menu_Item*);
#if 0
static int menu_display_adjustment_change();
#endif
static void get_display_adjustment_value_string(Menu_Item*);
static void get_display_format_value_string(Menu_Item*);
static void get_video_system_value_string(Menu_Item*);
static void sub_23492c4a(Menu_Item*);
static void sub_23492c78(Menu_Item*);
static void sub_23492ca6(Menu_Item*);
#if 0
static int sub_23492e1e();
#endif
static int menu_picture_on_enter(void);
static void menu_picture_on_exit();

static Menu menu_picture;
static uint8_t Data_23972bf8[];
static uint8_t Data_23972c20[];
static uint8_t Data_23972d18[];
static uint8_t Data_23972d40[];
static uint8_t Data_23972d68[];
static uint8_t Data_23972d90[];
static uint8_t Data_23972db8[];
static uint8_t Data_23972de0[];
static uint8_t Data_23972e08[];
static uint8_t Data_23972e30[];
static uint8_t Data_23972e58[];
static uint8_t Data_23972e80[];
static uint8_t Data_23972ea8[];
static uint8_t Data_23972ed0[];
static uint8_t Data_23972ef8[];
static uint8_t Data_23972f20[];
static uint8_t Data_23972f48[]; 
static uint8_t Data_23972f70[];
static uint8_t Data_23972f98[];

static Menu* menu_picture_p = &menu_picture; //234eed24

#if 0
static Struct_235fdf74_Inner12_Inner0x20 Data_234eed30 = //234eed30
{
	{0, 0, 0, 0},
	&Data_23972bf8[0], //Data_0x10
#if 0
	0x234eed30 0000                   movs       r0, r0                             ; DATA XREF=0x234ef4d8
	0x234eed32 5100                   lsls       r1, r2, #0x1
	0x234eed34 2C00                   movs       r4, r5
	0x234eed36 2701                   lsls       r7, r4, #0x4
	0x234eed38 4F00                   lsls       r7, r1, #0x1
	0x234eed3a 0106                   lsls       r1, r0, #0x18
	0x234eed3c 0200                   movs       r2, r0
	0x234eed3e 0000                   movs       r0, r0
	0x234eed40                        dd         0x23972bf8
#endif
};

static Struct_235fdf74_Inner16_Inner0x20 Data_234eed48 = //234eed48
{
	0, //uint16_t fill_0; //0
	0, //uint16_t wData_2; //2
	0, //uint16_t wData_4; //4
	0, //uint16_t wData_6; //6
	0, //int fill_8; //8
	0, //uint8_t fill_0xc; //0xc
	0, //uint8_t bData_0xd; //0xd
	&Data_23972c20, //void* Data_0x10; //0x10
	0, //uint16_t fill_0x14; //0x14
	0, //uint8_t fill_0x16; //0x16
	0, //uint8_t bData_0x17; //0x17

#if 0
0x234eed48 0000                   movs       r0, r0                             ; DATA XREF=0x234eef98
0x234eed4a 4700                   lsls       r7, r0, #0x1
0x234eed4c C701                   lsls       r7, r0, #0x7
0x234eed4e 5702                   lsls       r7, r2, #0x9
0x234eed50 FD01                   lsls       r5, r7, #0x7
0x234eed52 0105                   lsls       r1, r0, #0x14
0x234eed54 0301                   lsls       r3, r0, #0x4
0x234eed56 0000                   movs       r0, r0
0x234eed58                        dd         0x23972c20
#endif
};
#endif

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eed60 = //234eed60
{
	{0, 0, 0, 0},
	&Data_23972d18[0], //Data_0x10
#if 0
	0x234eed60 0000                   movs       r0, r0                             ; CODE XREF=dword_234ee604+264, DATA XREF=0x234ef018
	0x234eed62 5100                   lsls       r1, r2, #0x1
	0x234eed64 6400                   lsls       r4, r4, #0x1
	0x234eed66 2A01                   lsls       r2, r5, #0x4
	0x234eed68 8000                   lsls       r0, r0, #0x2
	0x234eed6a 0104                   lsls       r1, r0, #0x10
	0x234eed6c 0901                   lsls       r1, r1, #0x4
	0x234eed6e 0000                   movs       r0, r0
	0x234eed70                        dd         0x23972d18
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eed78 = //234eed78
{
	{0, 0, 0, 0},
	&Data_23972d40[0], //Data_0x10
#if 0
	0x234eed78 0000                   movs       r0, r0                             ; DATA XREF=0x234ef058
	0x234eed7a 5100                   lsls       r1, r2, #0x1
	0x234eed7c 8400                   lsls       r4, r0, #0x2
	0x234eed7e 2A01                   lsls       r2, r5, #0x4
	0x234eed80 A000                   lsls       r0, r4, #0x2
	0x234eed82 0104                   lsls       r1, r0, #0x10
	0x234eed84 0901                   lsls       r1, r1, #0x4
	0x234eed86 0000                   movs       r0, r0
	0x234eed88                        dd         0x23972d40
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eed90 = //234eed90
{
	{0, 0, 0, 0},
	&Data_23972d68[0], //Data_0x10
#if 0
	0x234eed90 0000                   movs       r0, r0                             ; DATA XREF=0x234ef098
	0x234eed92 5100                   lsls       r1, r2, #0x1
	0x234eed94 A400                   lsls       r4, r4, #0x2
	0x234eed96 2A01                   lsls       r2, r5, #0x4
	0x234eed98 C000                   lsls       r0, r0, #0x3
	0x234eed9a 0104                   lsls       r1, r0, #0x10
	0x234eed9c 0901                   lsls       r1, r1, #0x4
	0x234eed9e 0000                   movs       r0, r0
	0x234eeda0                        dd         0x23972d68
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eeda8 = //234eeda8
{
	{0, 0, 0, 0},
	&Data_23972d90[0], //Data_0x10
#if 0
	0x234eeda8 0000                   movs       r0, r0                             ; DATA XREF=0x234ef0d8
	0x234eedaa 5100                   lsls       r1, r2, #0x1
	0x234eedac C400                   lsls       r4, r0, #0x3                       ; DATA XREF=dword_234ee734+1428
	0x234eedae 2A01                   lsls       r2, r5, #0x4
	0x234eedb0 E000                   lsls       r0, r4, #0x3
	0x234eedb2 0104                   lsls       r1, r0, #0x10
	0x234eedb4 0901                   lsls       r1, r1, #0x4
	0x234eedb6 0000                   movs       r0, r0
	0x234eedb8                        dd         0x23972d90
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eedc0 = //234eedc0
{
	{0, 0, 0, 0},
	&Data_23972db8[0], //Data_0x10
#if 0
0x234eedc0 0000                   movs       r0, r0                             ; DATA XREF=0x234ef118
0x234eedc2 5100                   lsls       r1, r2, #0x1
0x234eedc4 E400                   lsls       r4, r4, #0x3
0x234eedc6 2A01                   lsls       r2, r5, #0x4
0x234eedc8 0001                   lsls       r0, r0, #0x4
0x234eedca 0104                   lsls       r1, r0, #0x10
0x234eedcc 0901                   lsls       r1, r1, #0x4
0x234eedce 0000                   movs       r0, r0
0x234eedd0                        dd         0x23972db8
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eedf0 = //234eedf0
{
	{0, 0, 0, 0},
	&Data_23972e08[0], //Data_0x10
#if 0
0x234eedf0 0000                   movs       r0, r0                             ; DATA XREF=0x234ef198
0x234eedf2 5100                   lsls       r1, r2, #0x1
0x234eedf4 2401                   lsls       r4, r4, #0x4
0x234eedf6 2A01                   lsls       r2, r5, #0x4
0x234eedf8 4001                   lsls       r0, r0, #0x5
0x234eedfa 0104                   lsls       r1, r0, #0x10
0x234eedfc 0901                   lsls       r1, r1, #0x4
0x234eedfe 0000                   movs       r0, r0
0x234eee00                        dd         0x23972e08
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eee08 = //234eee08
{
	{0, 0, 0, 0},
	&Data_23972e30[0], //Data_0x10
#if 0
0x234eee08 0000                   movs       r0, r0                             ; DATA XREF=0x234ef1d8
0x234eee0a 5100                   lsls       r1, r2, #0x1
0x234eee0c 4401                   lsls       r4, r0, #0x5
0x234eee0e 2A01                   lsls       r2, r5, #0x4
0x234eee10 6001                   lsls       r0, r4, #0x5
0x234eee12 0104                   lsls       r1, r0, #0x10
0x234eee14 0901                   lsls       r1, r1, #0x4
0x234eee16 0000                   movs       r0, r0
0x234eee18                        dd         0x23972e30
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eee20 = //234eee20
{
	{0, 0, 0, 0},
	&Data_23972e58[0], //Data_0x10
#if 0
0x234eee20 0000                   movs       r0, r0                             ; DATA XREF=0x234ef218
0x234eee22 5100                   lsls       r1, r2, #0x1
0x234eee24 6401                   lsls       r4, r4, #0x5
0x234eee26 2A01                   lsls       r2, r5, #0x4
0x234eee28 8001                   lsls       r0, r0, #0x6
0x234eee2a 0104                   lsls       r1, r0, #0x10
0x234eee2c 0901                   lsls       r1, r1, #0x4
0x234eee2e 0000                   movs       r0, r0
0x234eee30                        dd         0x23972e58
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eee38 = //234eee38
{
	{0, 0, 0, 0},
	&Data_23972e80[0], //Data_0x10
#if 0
	0x234eee38 0000                   movs       r0, r0                             ; DATA XREF=0x234ef298
	0x234eee3a 5501                   lsls       r5, r2, #0x5
	0x234eee3c 6400                   lsls       r4, r4, #0x1
	0x234eee3e 2E02                   lsls       r6, r5, #0x8
	0x234eee40 8000                   lsls       r0, r0, #0x2
	0x234eee42 0104                   lsls       r1, r0, #0x10
	0x234eee44 0901                   lsls       r1, r1, #0x4
	0x234eee46 0000                   movs       r0, r0
	0x234eee48                        dd         0x23972e80
#endif
};

Menu_Item_Inner4_Data_0_Data_0x20 Data_234eee50 = //234eee50
{
	{0, 0, 0, 0},
	&Data_23972ea8[0], //Data_0x10
#if 0
	0x234eee50 0000                   movs       r0, r0                             ; DATA XREF=0x234ef2d8
	0x234eee52 5501                   lsls       r5, r2, #0x5
	0x234eee54 8400                   lsls       r4, r0, #0x2
	0x234eee56 2E02                   lsls       r6, r5, #0x8
	0x234eee58 A000                   lsls       r0, r4, #0x2
	0x234eee5a 0104                   lsls       r1, r0, #0x10
	0x234eee5c 0901                   lsls       r1, r1, #0x4
	0x234eee5e 0000                   movs       r0, r0
	0x234eee60                        dd         0x23972ea8
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eee68 = //234eee68
{
	{0, 0, 0, 0},
	&Data_23972ed0[0], //Data_0x10
#if 0
	0x234eee68 0000                   movs       r0, r0                             ; DATA XREF=0x234ef318
	0x234eee6a 5501                   lsls       r5, r2, #0x5
	0x234eee6c A400                   lsls       r4, r4, #0x2
	0x234eee6e 2E02                   lsls       r6, r5, #0x8
	0x234eee70 C000                   lsls       r0, r0, #0x3
	0x234eee72 0104                   lsls       r1, r0, #0x10
	0x234eee74 0901                   lsls       r1, r1, #0x4
	0x234eee76 0000                   movs       r0, r0
	0x234eee78                        dd         0x23972ed0
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eee80 = //234eee80
{
	{0, 0, 0, 0},
	&Data_23972ef8[0], //Data_0x10
#if 0
	0x234eee80 0000                   movs       r0, r0                             ; DATA XREF=0x234ef358
	0x234eee82 5501                   lsls       r5, r2, #0x5
	0x234eee84 C400                   lsls       r4, r0, #0x3
	0x234eee86 2E02                   lsls       r6, r5, #0x8
	0x234eee88 E000                   lsls       r0, r4, #0x3
	0x234eee8a 0104                   lsls       r1, r0, #0x10
	0x234eee8c 0901                   lsls       r1, r1, #0x4
	0x234eee8e 0000                   movs       r0, r0
	0x234eee90                        dd         0x23972ef8
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eee98 = //234eee98
{
	{0, 0, 0, 0},
	&Data_23972f20[0], //Data_0x10
#if 0
0x234eee98 0000                   movs       r0, r0                             ; DATA XREF=0x234ef398
0x234eee9a 5501                   lsls       r5, r2, #0x5
0x234eee9c E400                   lsls       r4, r4, #0x3
0x234eee9e 2E02                   lsls       r6, r5, #0x8
0x234eeea0 0001                   lsls       r0, r0, #0x4
0x234eeea2 0104                   lsls       r1, r0, #0x10
0x234eeea4 0901                   lsls       r1, r1, #0x4
0x234eeea6 0000                   movs       r0, r0
0x234eeea8                        dd         0x23972f20
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eeeb0 = //234eeeb0
{
	{0, 0, 0, 0},
	&Data_23972f48[0], //Data_0x10
#if 0
0x234eeeb0 0000                   movs       r0, r0                             ; DATA XREF=0x234ef418
0x234eeeb2 5501                   lsls       r5, r2, #0x5
0x234eeeb4 2401                   lsls       r4, r4, #0x4
0x234eeeb6 2E02                   lsls       r6, r5, #0x8
0x234eeeb8 4001                   lsls       r0, r0, #0x5
0x234eeeba 0104                   lsls       r1, r0, #0x10
0x234eeebc 0901                   lsls       r1, r1, #0x4
0x234eeebe 0000                   movs       r0, r0
0x234eeec0                        dd         0x23972f48
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eeec8 = //234eeec8
{
	{0, 0, 0, 0},
	&Data_23972f70[0], //Data_0x10
#if 0
0x234eeec8 0000                   movs       r0, r0                             ; DATA XREF=0x234ef458
0x234eeeca 5501                   lsls       r5, r2, #0x5
0x234eeecc 4401                   lsls       r4, r0, #0x5
0x234eeece 2E02                   lsls       r6, r5, #0x8
0x234eeed0 6001                   lsls       r0, r4, #0x5
0x234eeed2 0104                   lsls       r1, r0, #0x10
0x234eeed4 0901                   lsls       r1, r1, #0x4
0x234eeed6 0000                   movs       r0, r0
0x234eeed8                        dd         0x23972f70
#endif
};

static Menu_Item_Inner4_Data_0_Data_0x20 Data_234eeee0 = //234eeee0
{
	{0, 0, 0, 0},
	&Data_23972f98[0], //Data_0x10
#if 0
0x234eeee0 0000                   movs       r0, r0                             ; DATA XREF=0x234ef498
0x234eeee2 5501                   lsls       r5, r2, #0x5
0x234eeee4 6401                   lsls       r4, r4, #0x5
0x234eeee6 2E02                   lsls       r6, r5, #0x8
0x234eeee8 8001                   lsls       r0, r0, #0x6
0x234eeeea 0104                   lsls       r1, r0, #0x10
0x234eeeec 0901                   lsls       r1, r1, #0x4
0x234eeeee 0000                   movs       r0, r0
0x234eeef0                        dd         0x23972f98
#endif
};

#if 0
static Struct_235fdf74_Inner16 Data_234eef78 = //234eef78
{
	{0},
	&Data_234eed48, //Struct_235fdf74_Inner16_Inner0x20* Data_0x20; //0x20 = 32
#if 0
0x234eef78 0100                   movs       r1, r0                             ; DATA XREF=0x234efe90
0x234eef7a 0000                   movs       r0, r0
0x234eef7c 0000                   movs       r0, r0
0x234eef7e 0000                   movs       r0, r0
0x234eef80 0000                   movs       r0, r0
0x234eef82 0000                   movs       r0, r0
0x234eef84 3D00                   movs       r5, r7
0x234eef86 C301                   lsls       r3, r0, #0x7
0x234eef88 1A02                   lsls       r2, r3, #0x8
0x234eef8a 3A00                   movs       r2, r7
0x234eef8c 0000                   movs       r0, r0
0x234eef8e 0000                   movs       r0, r0
0x234eef90                        dd         0x234c134c
0x234eef94 0300                   movs       r3, r0
0x234eef96 0000                   movs       r0, r0
0x234eef98                        dd         0x234eed48
#endif
};
#endif

static Menu_Item_Inner4_Data_0 Data_234eeff8 = //234eeff8
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eed60, //Data_0x20
#if 0
	0x234eeff8                        db         0x01                               ; DATA XREF=0x234efbc4
	0x234eeff9                        db  0x00 ; '.'
	0x234eeffa 0000                   movs       r0, r0
	0x234eeffc 0000                   movs       r0, r0
	0x234eeffe 0000                   movs       r0, r0
	0x234ef000 0000                   movs       r0, r0
	0x234ef002 0000                   movs       r0, r0
	0x234ef004 3D00                   movs       r5, r7
	0x234ef006 6000                   lsls       r0, r4, #0x1
	0x234ef008 ED00                   lsls       r5, r5, #0x3
	0x234ef00a 2000                   movs       r0, r4
	0x234ef00c 0000                   movs       r0, r0
	0x234ef00e 0000                   movs       r0, r0
	0x234ef010                        dd         0x234c1334
	0x234ef014 0900                   movs       r1, r1
	0x234ef016 0000                   movs       r0, r0
	0x234ef018                        dd         0x234eed60
#endif
};

Graphic_Job_2_5_Item_Text Data_234eedd8 = //234eedd8
{
	0, 0x0051, 0x0104, 0x012a, 0x0120, 1, 4, 9, 1, &Data_23972de0[0], 0, 0, 0
#if 0
0x234eedd8                        db         0x00                               ; DATA XREF=0x234ef158
0x234eedd9                        db  0x00 ; '.'
0x234eedda                        dw         0x0051
0x234eeddc                        dw         0x0104
0x234eedde                        dw         0x012a
0x234eede0                        dw         0x0120
0x234eede2                        db         0x01
0x234eede3                        db         0x04
0x234eede4                        db         0x09
0x234eede5                        db         0x01
0x234eede6 0000                   movs       r0, r0
0x234eede8                        dd         0x23972de0                         ; DATA XREF=dword_234ee734+1488
0x234eedec                        dw         0x0000
0x234eedee                        db         0x00
0x234eedef                        db         0x00
#endif
};

static Graphic_Job_2_5_Item Data_234eeef8__[25] = //234eeef8
{
	{0}, //[0] = 234eeef8
	{0}, //[1] = 234EEF38
	{0}, //[2] = 234EEF78
	{0}, //[3] = 234EEFB8
	{0}, //[4] = 234EEFF8 = Item 0 (Videosignal - Analog) = Caption
	{0}, //[5] = 234EF038
	{0}, //[6] = 234EF078
	{0}, //[7] = 234EF0B8 = Item 3 (Bildanpassung) = Caption
	{0}, //[8] = 234EF0F8
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x100, 0xed, 0x20, 0, 0/*Data_0x18*/, 9, 0, &Data_234eedd8, {0}, 0}, //[9] = 234EF138 = Item ? (Bildskalierung:)
	{0}, //[10] = 234EF178 = Item 5 ( >Eingang 720x576) = Caption
	{0}, //[11] = 234EF1B8
	{0}, //[12] = 234EF1F8 = Item 7 ( >Eingang 720x576) = Caption
	{0}, //[13] = 234EF238
	{0}, //[14] = 234EF278 = Item 0 (Videosignal - Analog) = Value
	{0}, //[15] = 234EF2B8
	{0}, //[16] = 234EF2F8
	{0}, //[17] = 234EF338 = Item 3 (Bildanpassung) = Value
	{0}, //[18] = 234EF378
	{0}, //[19] = 234EF3B8
	{0}, //[20] = 234EF3F8
	{0}, //[21] = 234EF438
	{0}, //[22] = 234EF478 = Item 7 ( >Eingang 720x576) = Value
	{0}, //[23] = 234EF4B8
	{0}, //[24] = 234EF4F8
};

#if 0
static Struct_235fdf74_Inner20_Inner8 Data_234eeef8 = //234eeef8
{
	//Struct_2377ded0_Inner_0x1c[9]
	{
		{
			1, //uint8_t bData_0; //0
			0, //uint8_t bData_1; //1
			0, //int fill_4; //4
			0, //Struct_2377ded0_Inner_0x1c_Inner_8* Data_8; //8
			{0}, //int fill_0xc[4]; //0xc
			2, //uint16_t wData_0x1c; //0x1c
			0, //Graphic_Job_2_5_Item_Text* Data_0x20; //0x20
			0, //int Data_0x24; //0x24
			{0}, //int fill_0x28[3]; //0x28
			0, //int Data_0x34; //0x34
			0, //int fill_0x38; //0x38
			0, //uint8_t bData_0x3c; //0x3c
			//0x40
#if 0
0x234eeef8                        db         0x01                               ; DATA XREF=sub_23492fc8+14, 0x234efb80
0x234eeef9                        db         0x00
0x234eeefa                        db  0x00 ; '.'
0x234eeefb                        db  0x00 ; '.'
0x234eeefc                        dd         0x00000000
0x234eef00 0000                   movs       r0, r0
0x234eef02 0000                   movs       r0, r0
0x234eef04 3700                   movs       r7, r6
0x234eef06 2300                   movs       r3, r4
0x234eef08 FA00                   lsls       r2, r7, #0x3
0x234eef0a 3200                   movs       r2, r6
0x234eef0c 0000                   movs       r0, r0
0x234eef0e 0000                   movs       r0, r0
0x234eef10                        dd         0x234c12b0
0x234eef14                        dw         0x0002
0x234eef16 0000                   movs       r0, r0
0x234eef18                        dd         0x00000000                         ; DATA XREF=sub_23492fc8+18
0x234eef1c                        dd         0x00000000
0x234eef20 0000                   movs       r0, r0
0x234eef22 0000                   movs       r0, r0
0x234eef24 0000                   movs       r0, r0
0x234eef26 0000                   movs       r0, r0
0x234eef28 0000                   movs       r0, r0
0x234eef2a 0000                   movs       r0, r0
0x234eef2c                        dd         0x00000000
0x234eef30 0000                   movs       r0, r0
0x234eef32 0000                   movs       r0, r0
0x234eef34                        dd         0x00000000
#endif
		},
	},
	//234EF138
	{
		{0, 0, 0, 0, 0, 0, 0, 0},
		&Data_234eedd8,
#if 0
		0x234ef138                        db         0x01
		0x234ef139                        db  0x00 ; '.'
		0x234ef13a 0000                   movs       r0, r0
		0x234ef13c 0000                   movs       r0, r0
		0x234ef13e 0000                   movs       r0, r0
		0x234ef140 0000                   movs       r0, r0
		0x234ef142 0000                   movs       r0, r0
		0x234ef144 3D00                   movs       r5, r7
		0x234ef146 0001                   lsls       r0, r0, #0x4
		0x234ef148 ED00                   lsls       r5, r5, #0x3
		0x234ef14a 2000                   movs       r0, r4
		0x234ef14c 0000                   movs       r0, r0
		0x234ef14e 0000                   movs       r0, r0
		0x234ef150                        dd         0x234c12d4
		0x234ef154 0900                   movs       r1, r1
		0x234ef156 0000                   movs       r0, r0
		0x234ef158                        dd         0x234eedd8
#endif
	}
};
#endif

static Menu_Item_Inner4_Data_0 Data_234ef038 = //234ef038
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eed78, //Data_0x20
#if 0
	0x234ef038                        db         0x01                               ; DATA XREF=0x234efbf0
	0x234ef039                        db  0x00 ; '.'
	0x234ef03a 0000                   movs       r0, r0
	0x234ef03c 0000                   movs       r0, r0
	0x234ef03e 0000                   movs       r0, r0
	0x234ef040 0000                   movs       r0, r0
	0x234ef042 0000                   movs       r0, r0
	0x234ef044 3D00                   movs       r5, r7
	0x234ef046 8000                   lsls       r0, r0, #0x2
	0x234ef048 ED00                   lsls       r5, r5, #0x3
	0x234ef04a 2000                   movs       r0, r4
	0x234ef04c 0000                   movs       r0, r0
	0x234ef04e 0000                   movs       r0, r0
	0x234ef050                        dd         0x234c12d4
	0x234ef054 0900                   movs       r1, r1
	0x234ef056 0000                   movs       r0, r0
	0x234ef058                        dd         0x234eed78
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef078 = //234ef078
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eed90, //Data_0x20
#if 0
	0x234ef078                        db         0x01                               ; DATA XREF=0x234efc1c
	0x234ef079                        db  0x00 ; '.'
	0x234ef07a 0000                   movs       r0, r0
	0x234ef07c 0000                   movs       r0, r0
	0x234ef07e 0000                   movs       r0, r0
	0x234ef080 0000                   movs       r0, r0
	0x234ef082 0000                   movs       r0, r0
	0x234ef084 3D00                   movs       r5, r7
	0x234ef086 A000                   lsls       r0, r4, #0x2
	0x234ef088 ED00                   lsls       r5, r5, #0x3
	0x234ef08a 2000                   movs       r0, r4
	0x234ef08c 0000                   movs       r0, r0
	0x234ef08e 0000                   movs       r0, r0
	0x234ef090                        dd         0x234c12d4
	0x234ef094 0900                   movs       r1, r1
	0x234ef096 0000                   movs       r0, r0
	0x234ef098                        dd         0x234eed90
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef0b8 = //234ef0b8 = Item 3 (Bildanpassung)
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eeda8, //Data_0x20
#if 0
	0x234ef0b8                        db         0x01                               ; DATA XREF=0x234efc48
	0x234ef0b9                        db  0x00 ; '.'
	0x234ef0ba 0000                   movs       r0, r0
	0x234ef0bc 0000                   movs       r0, r0
	0x234ef0be 0000                   movs       r0, r0
	0x234ef0c0 0000                   movs       r0, r0
	0x234ef0c2 0000                   movs       r0, r0
	0x234ef0c4 3D00                   movs       r5, r7
	0x234ef0c6 C000                   lsls       r0, r0, #0x3
	0x234ef0c8 ED00                   lsls       r5, r5, #0x3
	0x234ef0ca 2000                   movs       r0, r4
	0x234ef0cc 0000                   movs       r0, r0
	0x234ef0ce 0000                   movs       r0, r0
	0x234ef0d0                        dd         0x234c12d4
	0x234ef0d4 0900                   movs       r1, r1
	0x234ef0d6 0000                   movs       r0, r0
	0x234ef0d8                        dd         0x234eeda8
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef0f8 = //234ef0f8
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eedc0, //Data_0x20
#if 0
0x234ef0f8 0100                   movs       r1, r0                             ; DATA XREF=0x234efc74
0x234ef0fa 0000                   movs       r0, r0
0x234ef0fc 0000                   movs       r0, r0
0x234ef0fe 0000                   movs       r0, r0
0x234ef100 0000                   movs       r0, r0
0x234ef102 0000                   movs       r0, r0
0x234ef104 3D00                   movs       r5, r7
0x234ef106 E000                   lsls       r0, r4, #0x3
0x234ef108 ED00                   lsls       r5, r5, #0x3
0x234ef10a 2000                   movs       r0, r4
0x234ef10c 0000                   movs       r0, r0
0x234ef10e 0000                   movs       r0, r0
0x234ef110                        dd         0x234c12d4
0x234ef114 0900                   movs       r1, r1
0x234ef116 0000                   movs       r0, r0
0x234ef118                        dd         0x234eedc0
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef178 = //234ef178
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eedf0, //Data_0x20
#if 0
0x234ef178 0100                   movs       r1, r0                             ; DATA XREF=0x234efca0
0x234ef17a 0000                   movs       r0, r0
0x234ef17c 0000                   movs       r0, r0
0x234ef17e 0000                   movs       r0, r0
0x234ef180 0000                   movs       r0, r0
0x234ef182 0000                   movs       r0, r0
0x234ef184 3D00                   movs       r5, r7
0x234ef186 2001                   lsls       r0, r4, #0x4
0x234ef188 ED00                   lsls       r5, r5, #0x3
0x234ef18a 2000                   movs       r0, r4
0x234ef18c 0000                   movs       r0, r0
0x234ef18e 0000                   movs       r0, r0
0x234ef190                        dd         0x234c12d4
0x234ef194 0900                   movs       r1, r1
0x234ef196 0000                   movs       r0, r0
0x234ef198                        dd         0x234eedf0
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef1b8 = //234ef1b8
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eee08, //Data_0x20
#if 0
0x234ef1b8 0100                   movs       r1, r0                             ; DATA XREF=0x234efccc
0x234ef1ba 0000                   movs       r0, r0
0x234ef1bc 0000                   movs       r0, r0
0x234ef1be 0000                   movs       r0, r0
0x234ef1c0 0000                   movs       r0, r0
0x234ef1c2 0000                   movs       r0, r0
0x234ef1c4 3D00                   movs       r5, r7
0x234ef1c6 4001                   lsls       r0, r0, #0x5                       ; CODE XREF=dword_234ee734+1344
0x234ef1c8 ED00                   lsls       r5, r5, #0x3
0x234ef1ca 2000                   movs       r0, r4
0x234ef1cc 0000                   movs       r0, r0
0x234ef1ce 0000                   movs       r0, r0
0x234ef1d0                        dd         0x234c12d4
0x234ef1d4 0900                   movs       r1, r1
0x234ef1d6 0000                   movs       r0, r0
0x234ef1d8                        dd         0x234eee08
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef1f8 = //234ef1f8
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eee20, //Data_0x20
#if 0
0x234ef1f8 0100                   movs       r1, r0                             ; DATA XREF=0x234efcf8
0x234ef1fa 0000                   movs       r0, r0
0x234ef1fc 0000                   movs       r0, r0
0x234ef1fe 0000                   movs       r0, r0
0x234ef200 0000                   movs       r0, r0
0x234ef202 0000                   movs       r0, r0
0x234ef204 3D00                   movs       r5, r7
0x234ef206 6001                   lsls       r0, r4, #0x5
0x234ef208 ED00                   lsls       r5, r5, #0x3
0x234ef20a 2000                   movs       r0, r4
0x234ef20c 0000                   movs       r0, r0
0x234ef20e 0000                   movs       r0, r0
0x234ef210                        dd         0x234c131c
0x234ef214 0900                   movs       r1, r1
0x234ef216 0000                   movs       r0, r0
0x234ef218                        dd         0x234eee20
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef278 = //234ef278
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eee38, //Data_0x20
#if 0
	0x234ef278                        db         0x01                               ; DATA XREF=0x234efbc8
	0x234ef279                        db  0x00 ; '.'
	0x234ef27a 0000                   movs       r0, r0
	0x234ef27c 0000                   movs       r0, r0
	0x234ef27e 0000                   movs       r0, r0
	0x234ef280 0000                   movs       r0, r0
	0x234ef282 0000                   movs       r0, r0
	0x234ef284 4101                   lsls       r1, r0, #0x5
	0x234ef286 6000                   lsls       r0, r4, #0x1
	0x234ef288 ED00                   lsls       r5, r5, #0x3
	0x234ef28a 2000                   movs       r0, r4
	0x234ef28c 0000                   movs       r0, r0
	0x234ef28e 0000                   movs       r0, r0
	0x234ef290                        dd         0x234c1340
	0x234ef294 0900                   movs       r1, r1
	0x234ef296 0000                   movs       r0, r0
	0x234ef298                        dd         0x234eee38
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef2b8 = //234ef2b8
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eee50, //Data_0x20
#if 0
	0x234ef2b8                        db         0x01                               ; DATA XREF=0x234efbf4
	0x234ef2b9                        db  0x00 ; '.'
	0x234ef2ba 0000                   movs       r0, r0
	0x234ef2bc 0000                   movs       r0, r0
	0x234ef2be 0000                   movs       r0, r0
	0x234ef2c0 0000                   movs       r0, r0
	0x234ef2c2 0000                   movs       r0, r0
	0x234ef2c4 4101                   lsls       r1, r0, #0x5
	0x234ef2c6 8000                   lsls       r0, r0, #0x2
	0x234ef2c8 ED00                   lsls       r5, r5, #0x3
	0x234ef2ca 2000                   movs       r0, r4
	0x234ef2cc 0000                   movs       r0, r0
	0x234ef2ce 0000                   movs       r0, r0
	0x234ef2d0                        dd         0x234c12d4
	0x234ef2d4 0900                   movs       r1, r1
	0x234ef2d6 0000                   movs       r0, r0
	0x234ef2d8                        dd         0x234eee50
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef2f8 = //234ef2f8
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eee68, //Data_0x20
#if 0
	0x234ef2f8                        db         0x01                               ; DATA XREF=0x234efc20
	0x234ef2f9                        db  0x00 ; '.'
	0x234ef2fa 0000                   movs       r0, r0
	0x234ef2fc 0000                   movs       r0, r0
	0x234ef2fe 0000                   movs       r0, r0
	0x234ef300 0000                   movs       r0, r0
	0x234ef302 0000                   movs       r0, r0
	0x234ef304 4101                   lsls       r1, r0, #0x5
	0x234ef306 A000                   lsls       r0, r4, #0x2
	0x234ef308 ED00                   lsls       r5, r5, #0x3
	0x234ef30a 2000                   movs       r0, r4
	0x234ef30c 0000                   movs       r0, r0
	0x234ef30e 0000                   movs       r0, r0
	0x234ef310                        dd         0x234c12d4
	0x234ef314 0900                   movs       r1, r1
	0x234ef316 0000                   movs       r0, r0
	0x234ef318                        dd         0x234eee68
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef338 = //234ef338
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eee80, //Data_0x20
#if 0
	0x234ef338                        db         0x01                               ; DATA XREF=0x234efc4c
	0x234ef339                        db  0x00 ; '.'
	0x234ef33a 0000                   movs       r0, r0
	0x234ef33c 0000                   movs       r0, r0
	0x234ef33e 0000                   movs       r0, r0
	0x234ef340 0000                   movs       r0, r0
	0x234ef342 0000                   movs       r0, r0
	0x234ef344 4101                   lsls       r1, r0, #0x5
	0x234ef346 C000                   lsls       r0, r0, #0x3
	0x234ef348 ED00                   lsls       r5, r5, #0x3
	0x234ef34a 2000                   movs       r0, r4
	0x234ef34c 0000                   movs       r0, r0
	0x234ef34e 0000                   movs       r0, r0
	0x234ef350                        dd         0x234c12d4
	0x234ef354 0900                   movs       r1, r1
	0x234ef356 0000                   movs       r0, r0
	0x234ef358                        dd         0x234eee80
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef378 = //234ef378
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eee98, //Data_0x20
#if 0
0x234ef378 0100                   movs       r1, r0                             ; DATA XREF=0x234efc78
0x234ef37a 0000                   movs       r0, r0
0x234ef37c 0000                   movs       r0, r0
0x234ef37e 0000                   movs       r0, r0
0x234ef380 0000                   movs       r0, r0
0x234ef382 0000                   movs       r0, r0
0x234ef384 4101                   lsls       r1, r0, #0x5
0x234ef386 E000                   lsls       r0, r4, #0x3
0x234ef388 ED00                   lsls       r5, r5, #0x3
0x234ef38a 2000                   movs       r0, r4
0x234ef38c 0000                   movs       r0, r0
0x234ef38e 0000                   movs       r0, r0
0x234ef390                        dd         0x234c12d4
0x234ef394 0900                   movs       r1, r1
0x234ef396 0000                   movs       r0, r0
0x234ef398                        dd         0x234eee98
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef3f8 = //234ef3f8
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eeeb0, //Data_0x20
#if 0
0x234ef3f8 0100                   movs       r1, r0                             ; DATA XREF=0x234efca4
0x234ef3fa 0000                   movs       r0, r0
0x234ef3fc 0000                   movs       r0, r0
0x234ef3fe 0000                   movs       r0, r0
0x234ef400 0000                   movs       r0, r0
0x234ef402 0000                   movs       r0, r0
0x234ef404 4101                   lsls       r1, r0, #0x5
0x234ef406 2001                   lsls       r0, r4, #0x4
0x234ef408 ED00                   lsls       r5, r5, #0x3
0x234ef40a 2000                   movs       r0, r4
0x234ef40c 0000                   movs       r0, r0
0x234ef40e 0000                   movs       r0, r0
0x234ef410                        dd         0x234c12d4
0x234ef414 0900                   movs       r1, r1
0x234ef416 0000                   movs       r0, r0
0x234ef418                        dd         0x234eeeb0
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef438 = //234ef438
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eeec8, //Data_0x20
#if 0
0x234ef438 0100                   movs       r1, r0                             ; DATA XREF=0x234efcd0
0x234ef43a 0000                   movs       r0, r0
0x234ef43c 0000                   movs       r0, r0
0x234ef43e 0000                   movs       r0, r0
0x234ef440 0000                   movs       r0, r0
0x234ef442 0000                   movs       r0, r0
0x234ef444 4101                   lsls       r1, r0, #0x5
0x234ef446 4001                   lsls       r0, r0, #0x5
0x234ef448 ED00                   lsls       r5, r5, #0x3
0x234ef44a 2000                   movs       r0, r4
0x234ef44c 0000                   movs       r0, r0
0x234ef44e 0000                   movs       r0, r0
0x234ef450                        dd         0x234c12d4
0x234ef454 0900                   movs       r1, r1
0x234ef456 0000                   movs       r0, r0
0x234ef458                        dd         0x234eeec8
#endif
};

static Menu_Item_Inner4_Data_0 Data_234ef478 = //234ef478
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234eeee0, //Data_0x20
#if 0
0x234ef478 0100                   movs       r1, r0                             ; DATA XREF=0x234efcfc
0x234ef47a 0000                   movs       r0, r0
0x234ef47c 0000                   movs       r0, r0
0x234ef47e 0000                   movs       r0, r0
0x234ef480 0000                   movs       r0, r0
0x234ef482 0000                   movs       r0, r0
0x234ef484 4101                   lsls       r1, r0, #0x5
0x234ef486 6001                   lsls       r0, r4, #0x5
0x234ef488 ED00                   lsls       r5, r5, #0x3
0x234ef48a 2000                   movs       r0, r4
0x234ef48c 0000                   movs       r0, r0
0x234ef48e 0000                   movs       r0, r0
0x234ef490                        dd         0x234c1328
0x234ef494 0900                   movs       r1, r1
0x234ef496 0000                   movs       r0, r0
0x234ef498                        dd         0x234eeee0
#endif
};

#if 0
static Struct_235fdf74_Inner12 Data_234ef4b8 = //234ef4b8
{
	{0, 0, 0, 0, 0, 0, 0, 0}, //TODO
	&Data_234eed30, //Data_0x20
#if 0
	0x234ef4b8                        db         0x01                               ; DATA XREF=0x234efe8c
	0x234ef4b9                        db  0x00 ; '.'
	0x234ef4ba 0000                   movs       r0, r0
	0x234ef4bc 0000                   movs       r0, r0
	0x234ef4be 0000                   movs       r0, r0
	0x234ef4c0 0000                   movs       r0, r0
	0x234ef4c2 0000                   movs       r0, r0
	0x234ef4c4 3D00                   movs       r5, r7
	0x234ef4c6 2900                   movs       r1, r5
	0x234ef4c8 ED00                   lsls       r5, r5, #0x3
	0x234ef4ca 2600                   movs       r6, r4
	0x234ef4cc 0000                   movs       r0, r0
	0x234ef4ce 0000                   movs       r0, r0
	0x234ef4d0                        dd         0x234c12a4
	0x234ef4d4 0200                   movs       r2, r0
	0x234ef4d6 0000                   movs       r0, r0
	0x234ef4d8                        dd         0x234eed30
#endif
};
#endif

#if 1
static Graphic_Job_2_5 Data_234efb78 = //234efb78
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x0007, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234eeef8__[0], //int Data_8; //8
	0, //Struct_23414b38_b_Inner_0xc* Data_0xc; //12
	0x10, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	25, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
	0, //0x1c
	0, //0x20
#if 0
0x234efb78                        db         0x00                               ; DATA XREF=sub_23492fc8+12, 0x234efe94
0x234efb79                        db         0xfa
0x234efb7a                        dw         0x0007
0x234efb7c                        db         0x04
0x234efb7d                        db  0x00 ; '.'
0x234efb7e 0000                   movs       r0, r0
0x234efb80                        dd         0x234eeef8                         ; DATA XREF=sub_23492fc8+14
0x234efb84                        dd         0x234c123c
0x234efb88                        db         0x10
0x234efb89                        db  0x00 ; '.'
0x234efb8a 0000                   movs       r0, r0
0x234efb8c                        dd         0x00000000
0x234efb90                        db         0x19
0x234efb91                        db         0x01
0x234efb92 0000                   movs       r0, r0
0x234efb94                        dd         0x00000000
0x234efb98                        dd         0x00000000
#endif
};
#else
static Struct_235fdf74_Inner20 Data_234efb78 = //234efb78
{
	0, //uint16_t fill_0; //0
	0, //uint16_t wData_2; //2
	{0, &Data_234eeef8, 0, 0, 0, 0}, //int fill_4[6]; //4
	0, //void (*Data_0x1c)(); //28 = 0x1c
	0, //void (*Data_0x20)(); //32 = 0x20
#if 0
	0x234efb78                        db  0x00 ; '.'                                ; DATA XREF=menu_picture_on_enter+12, 0x234efe94
	0x234efb79                        db  0xfa ; '.'
	0x234efb7a 0700                   movs       r7, r0
	0x234efb7c 0400                   movs       r4, r0
	0x234efb7e 0000                   movs       r0, r0
	0x234efb80                        dd         0x234eeef8                         ; DATA XREF=menu_picture_on_enter+14
	0x234efb84                        dd         0x234c123c
	0x234efb88 1000                   movs       r0, r2
	0x234efb8a 0000                   movs       r0, r0
	0x234efb8c 0000                   movs       r0, r0
	0x234efb8e 0000                   movs       r0, r0
	0x234efb90 1901                   lsls       r1, r3, #0x4
	0x234efb92 0000                   movs       r0, r0
	0x234efb94                        dd         0x00000000
	0x234efb98                        dd         0x00000000
#endif
};
#endif

static Menu_Item menu_picture_items[] = //234efbc0
{
	//[0]
	{
		83, //0x53 = "Videosignal - Analog"
		0xf4, //uint16_t wData_2; //2
		{
			&Data_234eeff8,
			&Data_234ef278,
			0, 0, 0
		}, //int fill_4[5]; //4
		get_video_signal_analog_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23492b64, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//234EFBEC
#if 0
0x234efbc0                        dw         0x0053                             ; DATA XREF=sub_23492d8a+6, 0x234efe84, dword_234efe88
0x234efbc2                        dw         0x00f4
0x234efbc4                        dd         0x234eeff8
0x234efbc8                        dd         0x234ef278
0x234efbcc 0000                   movs       r0, r0
0x234efbce 0000                   movs       r0, r0
0x234efbd0 0000                   movs       r0, r0
0x234efbd2 0000                   movs       r0, r0
0x234efbd4 0000                   movs       r0, r0
0x234efbd6 0000                   movs       r0, r0
0x234efbd8                        dd         get_video_signal_analog_value_string+1
0x234efbdc                        dd         sub_23492b64+1
0x234efbe0                        dd         menu_item_event_thread+1
0x234efbe4 0000                   movs       r0, r0
0x234efbe6 0000                   movs       r0, r0
0x234efbe8 0000                   movs       r0, r0
0x234efbea 0000                   movs       r0, r0
#endif
	},
	//[1]
	{
		390, //0x0186 = "Videosignal - Digital"
		0xf4, //uint16_t wData_2; //2
		{
			&Data_234ef038,
			&Data_234ef2b8,
			0, 0, 0
		}, //int fill_4[5]; //4
		get_video_signal_digital_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //menu_video_signal_digital_change, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//234EFC18
#if 0
		0x234efbec                        dw         0x0186
		0x234efbee                        dw         0x00f4
		0x234efbf0                        dd         0x234ef038
		0x234efbf4                        dd         0x234ef2b8
		0x234efbf8 0000                   movs       r0, r0
		0x234efbfa 0000                   movs       r0, r0
		0x234efbfc 0000                   movs       r0, r0
		0x234efbfe 0000                   movs       r0, r0
		0x234efc00 0000                   movs       r0, r0
		0x234efc02 0000                   movs       r0, r0
		0x234efc04                        dd         get_video_signal_digital_value_string+1
		0x234efc08                        dd         sub_23492bd2+1
		0x234efc0c                        dd         menu_item_event_thread+1
		0x234efc10 0000                   movs       r0, r0
		0x234efc12 0000                   movs       r0, r0
		0x234efc14 0000                   movs       r0, r0
		0x234efc16 0000                   movs       r0, r0
#endif
	},
	//[2]
	{
		84, //0x54 = "Bildformat" / "Display format"
		0xf4, //uint16_t wData_2; //2
		{
			&Data_234ef078,
			&Data_234ef2f8,
			0, 0, 0
		}, //int fill_4[5]; //4
		get_display_format_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //sub_23492e1e, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//234EFC44
#if 0
		0x234efc18                        dw         0x0054
		0x234efc1a                        dw         0x00f4
		0x234efc1c                        dd         0x234ef078
		0x234efc20                        dd         0x234ef2f8
		0x234efc24 0000                   movs       r0, r0
		0x234efc26 0000                   movs       r0, r0
		0x234efc28 0000                   movs       r0, r0
		0x234efc2a 0000                   movs       r0, r0
		0x234efc2c 0000                   movs       r0, r0
		0x234efc2e 0000                   movs       r0, r0
		0x234efc30                        dd         get_display_format_value_string+1
		0x234efc34                        dd         sub_23492e1e+1
		0x234efc38                        dd         menu_item_event_thread+1
		0x234efc3c 0000                   movs       r0, r0
		0x234efc3e 0000                   movs       r0, r0
		0x234efc40 0000                   movs       r0, r0
		0x234efc42 0000                   movs       r0, r0
#endif
	},
	//[3]
	{
		112, //0x70 = "Bildanpassung" / "Display adjustment"
		0xf4, //uint16_t wData_2; //2
		{
			&Data_234ef0b8,
			&Data_234ef338,
			0, 0, 0
		}, //int fill_4[5]; //4
		get_display_adjustment_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //menu_display_adjustment_change, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//234EFC70
#if 0
		0x234efc44                        dw         0x0070                             ; DATA XREF=sub_23492d8a+8, sub_23492e1e+16
		0x234efc46                        dw         0x00f4
		0x234efc48                        dd         0x234ef0b8
		0x234efc4c                        dd         0x234ef338
		0x234efc50 0000                   movs       r0, r0
		0x234efc52 0000                   movs       r0, r0
		0x234efc54 0000                   movs       r0, r0
		0x234efc56 0000                   movs       r0, r0
		0x234efc58 0000                   movs       r0, r0
		0x234efc5a 0000                   movs       r0, r0
		0x234efc5c                        dd         get_display_adjustment_value_string+1
		0x234efc60                        dd         sub_23492cd4+1
		0x234efc64                        dd         menu_item_event_thread+1
		0x234efc68 0000                   movs       r0, r0
		0x234efc6a 0000                   movs       r0, r0
		0x234efc6c 0000                   movs       r0, r0
		0x234efc6e 0000                   movs       r0, r0
#endif
	},
	//[4]
	{
		374, //0x176 = "Videosystem"
		0xf4, //uint16_t wData_2; //2
		{
			&Data_234ef0f8,
			&Data_234ef378,
			0, 0, 0
		}, //int fill_4[5]; //4
		get_video_system_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //sub_23492dcc, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x234efc9c
#if 0
0x234efc70                        dw         0x0176
0x234efc72                        dw         0x00f4
0x234efc74                        dd         0x234ef0f8
0x234efc78                        dd         0x234ef378
0x234efc7c 0000                   movs       r0, r0
0x234efc7e 0000                   movs       r0, r0
0x234efc80 0000                   movs       r0, r0
0x234efc82 0000                   movs       r0, r0
0x234efc84 0000                   movs       r0, r0
0x234efc86 0000                   movs       r0, r0
0x234efc88                        dd         get_video_system_value_string+1
0x234efc8c                        dd         sub_23492dcc+1
0x234efc90                        dd         menu_item_event_thread+1
0x234efc94 0000                   movs       r0, r0
0x234efc96 0000                   movs       r0, r0
0x234efc98 0000                   movs       r0, r0
0x234efc9a 0000                   movs       r0, r0
#endif
	},
	//[5]
	{
		327, //0x147 = " >Eingang 720x576"
		0xf4, //uint16_t wData_2; //2
		{
			&Data_234ef178,
			&Data_234ef3f8,
			0, 0, 0
		}, //int fill_4[5]; //4
		sub_23492c4a, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //sub_23492e6c, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x234efcc8
#if 0
0x234efc9c                        dw         0x0147
0x234efc9e                        dw         0x00f4
0x234efca0                        dd         0x234ef178
0x234efca4                        dd         0x234ef3f8
0x234efca8 0000                   movs       r0, r0
0x234efcaa 0000                   movs       r0, r0
0x234efcac 0000                   movs       r0, r0
0x234efcae 0000                   movs       r0, r0
0x234efcb0 0000                   movs       r0, r0
0x234efcb2 0000                   movs       r0, r0
0x234efcb4                        dd         sub_23492c4a+1
0x234efcb8                        dd         sub_23492e6c+1
0x234efcbc                        dd         menu_item_event_thread+1
0x234efcc0 0000                   movs       r0, r0
0x234efcc2 0000                   movs       r0, r0
0x234efcc4 0000                   movs       r0, r0
0x234efcc6 0000                   movs       r0, r0
#endif
	},
	//[6]
	{
		328, //0x148 = " >Eingang 720x576"
		0xf4, //uint16_t wData_2; //2
		{
			&Data_234ef1b8,
			&Data_234ef438,
			0, 0, 0
		}, //int fill_4[5]; //4
		sub_23492c78, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //sub_23492ec0, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x234efcf4
#if 0
0x234efcc8                        dw         0x0148
0x234efcca                        dw         0x00f4
0x234efccc                        dd         0x234ef1b8
0x234efcd0                        dd         0x234ef438
0x234efcd4 0000                   movs       r0, r0
0x234efcd6 0000                   movs       r0, r0
0x234efcd8 0000                   movs       r0, r0
0x234efcda 0000                   movs       r0, r0
0x234efcdc 0000                   movs       r0, r0
0x234efcde 0000                   movs       r0, r0
0x234efce0                        dd         sub_23492c78+1
0x234efce4                        dd         sub_23492ec0+1
0x234efce8                        dd         menu_item_event_thread+1
0x234efcec                        dd         0x00000000
0x234efcf0 0000                   movs       r0, r0
0x234efcf2 0000                   movs       r0, r0
#endif
	},
	//[7]
	{
		329, //0x149 = " >Eingang 720x576"
		0xf4, //uint16_t wData_2; //2
		{
			&Data_234ef1f8,
			&Data_234ef478,
			0, 0, 0
		}, //int fill_4[5]; //4
		sub_23492ca6, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //sub_23492f14, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x234efcf4
#if 0
0x234efcf4                        dw         0x0149
0x234efcf6                        dw         0x00f4
0x234efcf8                        dd         0x234ef1f8
0x234efcfc                        dd         0x234ef478
0x234efd00 0000                   movs       r0, r0
0x234efd02 0000                   movs       r0, r0
0x234efd04 0000                   movs       r0, r0
0x234efd06 0000                   movs       r0, r0
0x234efd08 0000                   movs       r0, r0
0x234efd0a 0000                   movs       r0, r0
0x234efd0c                        dd         sub_23492ca6+1
0x234efd10                        dd         sub_23492f14+1
0x234efd14                        dd         menu_item_event_thread+1
0x234efd18 0000                   movs       r0, r0
0x234efd1a 0000                   movs       r0, r0
0x234efd1c 0000                   movs       r0, r0
0x234efd1e 0000                   movs       r0, r0
#endif
	},
}; //->234efd20


static Menu menu_picture = //234efe80
{
	16, //"Bild"
	&menu_picture_items[0], //Menu_Item* Data_4; //4
	&menu_picture_items[0], //Menu_Item* Data_8; //8
	0, //&Data_234ef4b8, //Struct_235fdf74_Inner12* header; //12 = 0xc
	0, //&Data_234eef78, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
	&Data_234efb78, //Struct_235fdf74_Inner20* Data_0x14; //20 = 0x14
	7, //uint8_t maxItem; //0x18 = 24
	0, //int8_t currentItem; //0x19
	graphic_start_job_2_5, //void (*Data_0x1c)(); //0x1c
	menu_items_navigate, //void (*onNavigate)(); //0x20
	menu_picture_on_enter, //void (*onEnter)(); //36 = 0x24
	menu_picture_on_exit, //int (*onExit)(); //0x28
	0, //int Data_0x2c; //44 = 0x2c
	0, //int Data_0x30; //48
	0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
	0, //void* (*Data_0x38)(struct FrontDisplay_Job*); //56
	//0x3c = 60?
#if 0
0x234efe80 1000                   movs       r0, r2                             ; DATA XREF=sub_23492d8a+2, menu_picture_on_enter+8, menu_picture_entry+6, menu_picture_entry+12, menu_picture_entry+18, menu_picture_p
0x234efe82 0000                   movs       r0, r0
0x234efe84                        dd         0x234efbc0
0x234efe88                        dd         0x234efbc0                         ; DATA XREF=sub_23492d8a+6
0x234efe8c                        dd         0x234ef4b8
0x234efe90                        dd         0x234eef78
0x234efe94                        dd         0x234efb78                         ; DATA XREF=menu_picture_on_enter+12
0x234efe98 0700                   movs       r7, r0
0x234efe9a 0000                   movs       r0, r0
0x234efe9c                        dd         graphic_start_job_2_5
0x234efea0                        dd         menu_items_navigate+1
0x234efea4                        dd         menu_picture_on_enter+1
0x234efea8                        dd         menu_picture_on_exit+1
0x234efeac 0000                   movs       r0, r0
0x234efeae 0000                   movs       r0, r0
0x234efeb0 0000                   movs       r0, r0
0x234efeb2 0000                   movs       r0, r0
0x234efeb4 0000                   movs       r0, r0
0x234efeb6 0000                   movs       r0, r0
0x234efeb8 0000                   movs       r0, r0
0x234efeba 0000                   movs       r0, r0
#endif
};


static User_Settings menu_picture_user_settings; //23972bdc
uint8_t Data_23972bf8[40]; //23972bf8
uint8_t Data_23972c20[248]; //23972c20
uint8_t Data_23972d18[40]; //23972d18
uint8_t Data_23972d40[40]; //23972d40
uint8_t Data_23972d68[40]; //23972d68
uint8_t Data_23972d90[40]; //23972d90
uint8_t Data_23972db8[40]; //23972db8
uint8_t Data_23972de0[40]; //23972de0
uint8_t Data_23972e08[40]; //23972e08
uint8_t Data_23972e30[40]; //23972e30
uint8_t Data_23972e58[40]; //23972e58
uint8_t Data_23972e80[40]; //23972e80
uint8_t Data_23972ea8[40]; //23972ea8
uint8_t Data_23972ed0[40]; //23972ed0
uint8_t Data_23972ef8[40]; //23972ef8
uint8_t Data_23972f20[40]; //23972f20
uint8_t Data_23972f48[40]; //23972f48
uint8_t Data_23972f70[40]; //23972f70
uint8_t Data_23972f98[40]; //23972f98


/*/  / 23492b64 - todo */
void sub_23492b64()
{
#if 1
	console_send_string("sub_23492b64 (menu_picture.c): TODO\r\n");
#endif

}


/*  /  / 23492ba6 - todo */
void get_video_signal_analog_value_string(Menu_Item* item)
{
#if 0
	console_send_string("get_video_signal_analog_value_string (menu_picture.c): TODO\r\n");
#endif

	uint8_t* str = item->Data_4[1]->Data_0x20->Data_0x10;
	int signal = menu_picture_user_settings.bVideoSignalAnalog;

	if (signal == 0)
	{
		sprintf(str, "FBAS");
	}
	else if (signal == 1)
	{
		sprintf(str, "RGB");
	}
	else if (signal == 2)
	{
		sprintf(str, "YUV");
	}
	else
	{
		sprintf(str, "undef");
	}
}

#if 0

/*  /  / 23492bd2 - todo */
int menu_video_signal_digital_change()
{
#if 0
	console_send_string("menu_video_signal_digital_change (menu_picture.c): TODO\r\n");
#endif

	Struct_235441b0 settings;

	menu_picture_user_settings.Data_4_.bitData.digital_video_signal ^= 1;

	sub_2340c970/*sub_2340f44c*/(1, &settings);

	if (menu_picture_user_settings.Data_4_.bitData.digital_video_signal ==
			settings.Data_4_.bitData.digital_video_signal)
	{
		return 1;
	}

	return 0;
}

#endif

/*  /  / 23492c02 - complete */
void get_video_signal_digital_value_string(Menu_Item* item)
{
#if 0
	console_send_string("get_video_signal_digital_value_string (menu_picture.c): TODO\r\n");
#endif

	uint8_t* buf = item->Data_4[1]->Data_0x20->Data_0x10;

#if 0
	if (menu_picture_user_settings.Data_4_.bitData.digital_video_signal == 0)
#else
	if ((menu_picture_user_settings.Data_4.dwData & (1 << 1)) == 0)
#endif
	{
		sprintf(buf, "YCbCr");
	}
	else
	{
		sprintf(buf, "RGB");
	}
}


/*  /  / 23492c1e - todo */
void get_video_system_value_string(Menu_Item* item)
{
	Menu_Item_Inner4_Data_0_Data_0x20* r1 = item->Data_4[1]->Data_0x20;
	uint8_t* str = r1->Data_0x10;

	if (menu_picture_user_settings.Data_4.bitData.video_system == 0)
	{
		sprintf(str, "PAL");
	} 
	else if (menu_picture_user_settings.Data_4.bitData.video_system == 1)
	{
		sprintf(str, "NTSC");
	}
	else if (menu_picture_user_settings.Data_4.bitData.video_system == 2)
	{
		sprintf(str, "AUTO");
	}
}


/* /  / 23492c4a - todo */
void sub_23492c4a(Menu_Item* item)
{
	uint32_t r0 = menu_picture_user_settings.wPictureScaling & 0x0f;
	Menu_Item_Inner4_Data_0_Data_0x20* r1 = item->Data_4[1]->Data_0x20;
	uint8_t* str = r1->Data_0x10;

	if (r0 > 2)
	{
		r0 = 0;
	}

	if (r1 != 0)
	{
		text_table_get_string(r0 + 0x14A/*Ausgang 720x576*/, str, 40);

		str[39] = 0;
	}
}


/* /  / 23492c78 - todo */
void sub_23492c78(Menu_Item* item)
{
	uint32_t r0 = (menu_picture_user_settings.wPictureScaling & 0xf0) >> 4;
	Menu_Item_Inner4_Data_0_Data_0x20* r1 = item->Data_4[1]->Data_0x20;
	uint8_t* str = r1->Data_0x10;

	if (r0 > 2)
	{
		r0 = 0;
	}

	if (r1 != 0)
	{
		text_table_get_string(r0 + 0x14A/*Ausgang 720x576*/, str, 40);

		str[39] = 0;
	}
}

/* /  / 23492ca6 - todo */
void sub_23492ca6(Menu_Item* item)
{
	uint32_t r0 = (menu_picture_user_settings.wPictureScaling & 0xf00) >> 8;
	Menu_Item_Inner4_Data_0_Data_0x20* r1 = item->Data_4[1]->Data_0x20;
	uint8_t* str = r1->Data_0x10;

	if (r0 > 2)
	{
		r0 = 0;
	}

	if (r1 != 0)
	{
		text_table_get_string(r0 + 0x14A/*Ausgang 720x576*/, str, 40);

		str[39] = 0;
	}
}


#if 0

/*  /  / 23492cd4 - complete */
int menu_display_adjustment_change()
{
#if 0
	console_send_string("menu_display_adjustment_change (todo.c): TODO\r\n");
#endif

	Struct_235441b0 settings; //sp

	sub_2340c970/*sub_2340f44c*/(1, &settings);

	menu_picture_user_settings.bData_0x15 ^= 1;

	if (menu_picture_user_settings.bData_0x15 == settings.bData_0x15)
	{
		return 1;
	}

	return 0;
}

#endif

/*  /  / 23492d26 - complete */
void get_display_adjustment_value_string(Menu_Item* item)
{
#if 0
	console_send_string("get_display_adjustment_value_string (todo.c): TODO\r\n");
#endif

	if (item->Data_4[1]->Data_0x20 != 0)
	{
		uint8_t* str = item->Data_4[1]->Data_0x20->Data_0x10;
		if (str != 0)
		{
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "get_display_adjustment_value_string: menu_picture_user_settings.bData_0x15=%d\r\n",
						menu_picture_user_settings.bDisplayAdjustment);
				console_send_string(debug_string);
			}
#endif

			if (menu_picture_user_settings.bDisplayAdjustment == 0)
			{
				// Letterbox
				text_table_get_string(0x73/*Letterbox*/, str, 35);
			}
			else
			{
				//Vollbild / Full format
				text_table_get_string(0x71/*Vollbild*/, str, 35);
			}

			str[39] = 0;
		}
	}
}


/*  /  / 23492dac - complete */
void get_display_format_value_string(Menu_Item* item)
{
#if 0
	console_send_string("get_display_format_value_string (menu_picture.c): TODO\r\n");
#endif

	uint8_t* str = item->Data_4[1]->Data_0x20->Data_0x10;

	switch (menu_picture_user_settings.displayFormat)
	{
		case 0:
			sprintf(str, "4:3");
			break;

		case 1:
			sprintf(str, "16:9");
			break;

		default:
			break;
	}
}

#if 0

/*  /  / 23492e1e - complete */
int sub_23492e1e()
{
#if 0
	console_send_string("sub_23492e1e (menu_picture.c): TODO\r\n");
#endif

	Struct_235441b0 settings; //sp4

	Menu_Item* r5 = menu_picture_p->Data_8 + 3;

	menu_picture_user_settings.displayFormat ^= 1;

	sub_23492d8a(&menu_picture_user_settings);

	if (menu_picture_user_settings.displayFormat == 0)
	{
		get_display_adjustment_value_string(r5);
	}
	else
	{
		sub_23492d58(r5);
	}

	r5->Data_4[1]->Data_0x20->bData_0x17 = 1;

	sub_2340c970/*sub_2340f44c*/(1, &settings);

	if (menu_picture_user_settings.displayFormat == settings.displayFormat)
	{
		return 1;
	}

	return 0;
}

#endif

/*  /  / 23492fc8 - todo */
int menu_picture_on_enter(void)
{
#if 0
	console_send_string("menu_picture_on_enter (menu_picture.c): TODO\r\n");
#endif

	Graphic_Job_2_5* r0 = menu_picture_p->graphicData;
	uint8_t* str = r0->pItems[9].Data_0x20->pString;

	text_table_get_string(0x14e/*Bildskalierung:*/, str, 38);

	str[39] = 0;

	channel_handle_user_settings(1, &menu_picture_user_settings);

	sub_23492d8a(&menu_picture_user_settings);

	sub_23418a50(&menu_picture_user_settings, 1); //->av.c

	return 0;
}


/*  /  / 23493008 - todo */
void menu_picture_on_exit(void)
{
#if 1
	console_send_string("menu_picture_on_exit (menu_picture.c): TODO\r\n");
#endif

}


/*  /  / 23493050 - todo */
int menu_picture_entry(UI_Thread_Params* p)
{
#if 0
	console_send_string("menu_picture_entry (menu_picture.c): TODO\r\n");
#endif

	menu_stack_operate(menu_picture_p);

	menu_initialize(menu_picture_p);

	sub_2343d51e(menu_picture_p, p);

	return 0;
}

#endif //!VDR110
