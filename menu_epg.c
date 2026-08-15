
#ifndef VDR110

#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "texttable.h"
#include "graphic.h"
#include "menu.h"
#include "osd_list.h"
#include "clocktime.h"
#include "tdt.h"
#include "eit.h"

#pragma thumb

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern void* Data_234c1258; //234c1258
extern Graphic_Job_2_5_Item_Background Data_234c12d4; //234c12d4
extern Graphic_Job_2_5_Item_Background Data_234c1340; //234c1340
extern Graphic_Job_2_5_Item_Background Data_234c134c; //234c134c
extern void* sub_2344d0d0(FrontDisplay_Job*);
extern void sub_2344f102(UI_Thread_Params*);
extern void sub_234500bc(UI_Thread_Params*);
extern void sub_2348dbf8(void);
extern  int sub_2348de88(int*a);
static Menu Data_234cc1b4;
static Menu Data_234cc22c;
static int sub_234562ec(void);
static void sub_23456302(void);
static void sub_23456bd0(void);
static int sub_234567d8(Struct_2348dc50*);
static int sub_23456aa2(void);
static int sub_23456bc0(void);

static uint8_t Data_23799ce8[]; //23799ce8
static uint8_t Data_23799d10[]; //23799d10
static uint8_t menu_epg_weekday_string[]; //2379A6F0
static uint8_t Data_2379c098[]; //2379c098
static uint8_t Data_2379c138[]; //2379c138
static uint8_t Data_2379c160[]; //2379c160
static uint8_t Data_2379c188[]; //2379c188
static uint8_t Data_2379c1b0[]; //2379c1b0
static uint8_t Data_2379c1d8[]; //2379c1d8
static uint8_t Data_2379c200[]; //2379c200
static uint8_t Data_2379c228[]; //2379c228
static uint8_t Data_2379c250[]; //2379c250
static uint8_t Data_2379c278[]; //2379c278
static uint8_t Data_2379c2a0[]; //2379c2a0
static uint8_t Data_2379c2d4[]; //2379c2d4

//0x234ca54c
volatile uint8_t bData_234ca54c = 0; //234ca54c +0
uint16_t wData_234ca54e = 0x0104; //234CA54E +2
uint16_t wData_234ca550 = 0x0102; //234CA550 +4
static Menu* Data_234ca55c = &Data_234cc1b4; //234ca55c +0x10
static Menu* Data_234ca560 = &Data_234cc22c; //234ca560 +0x14
static Menu* Data_234ca564 = 0; //234CA564 +0x18
static uint8_t menu_epg_date_string[]; //234ca7c0
static uint8_t menu_epg_clock_time_string[]; //234ca7f4

static uint8_t Data_234ca568[8] = ""; //234ca568

static Graphic_Job_2_5_Item_Text Data_234ca580 = //234ca580
{
	0, 0x0047, 0x002e, 0x00df, 0x004f, 0x01, 0x06, 0x02, 0x01, &Data_23799ce8[0], 0, 0, 0
#if 0
0x234ca580                        db         0x00                               ; DATA XREF=sub_23456f24+48, 0x234ca8fc
0x234ca581                        db  0x00 ; '.'
0x234ca582                        dw         0x0047
0x234ca584                        dw         0x002e
0x234ca586                        dw         0x00df
0x234ca588                        dw         0x004f
0x234ca58a                        db         0x01
0x234ca58b                        db         0x06                               ; DATA XREF=sub_23456f24+50
0x234ca58c                        db         0x02
0x234ca58d                        db         0x01
0x234ca58e 0000                   movs       r0, r0
0x234ca590                        dd         0x23799ce8
0x234ca594 0000                   movs       r0, r0
0x234ca596 0000                   movs       r0, r0
0x234ca598 0000                   movs       r0, r0
#endif
};

static Graphic_Job_2_5_Item_Text menu_epg_date_text_field = //234ca598
{
    0, 0x0100, 0x002e, 0x01f8, 0x004f, 0x01, 0x04, 0x09, 0x01, &menu_epg_date_string[0], 0, 0, 0
#if 0
0x234ca598                        db         0x00                               ; DATA XREF=sub_23456f24+24, 0x234caefc
0x234ca599                        db         0x00
0x234ca59a                        dw         0x0100
0x234ca59c                        dw         0x002e
0x234ca59e                        dw         0x01f8
0x234ca5a0                        dw         0x004f
0x234ca5a2                        db         0x01
0x234ca5a3                        db         0x04
0x234ca5a4                        db         0x09
0x234ca5a5                        db         0x01
0x234ca5a6 0000                   movs       r0, r0
0x234ca5a8                        dd         0x234ca7c0
#endif
};

static Graphic_Job_2_5_Item_Text menu_epg_clock_time_text_field = //234ca5b0
{
	0, 0x0217, 0x002e, 0x0257, 0x004f, 0x01, 0x04, 0x09, 0x01, &menu_epg_clock_time_string[0], 0, 0, 0
#if 0
0x234ca5b0                        db         0x00                               ; DATA XREF=sub_23456f24+18, 0x234caf7c
0x234ca5b1                        db         0x00
0x234ca5b2                        dw         0x0217
0x234ca5b4                        dw         0x002e
0x234ca5b6                        dw         0x0257
0x234ca5b8                        dw         0x004f
0x234ca5ba                        db         0x01
0x234ca5bb                        db         0x04
0x234ca5bc                        db         0x09
0x234ca5bd                        db         0x01
0x234ca5be 0000                   movs       r0, r0
0x234ca5c0                        dd         0x234ca7f4                         ; "--:--  "
0x234ca5c4 0000                   movs       r0, r0
0x234ca5c6 0000                   movs       r0, r0
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca5c8 = //234ca5c8
{
	0, 0x0217, 0x002e, 0x0257, 0x004f, 0x01, 0x04, 0x09, 0x01, &Data_234ca568[0], 0, 0, 0
#if 0
0x234ca5c8                        db         0x00                               ; DATA XREF=sub_23456c9c+28, sub_23456f24+72, 0x234cbafc
0x234ca5c9                        db         0x00
0x234ca5ca                        dw         0x0217
0x234ca5cc                        dw         0x002e
0x234ca5ce                        dw         0x0257
0x234ca5d0                        dw         0x004f
0x234ca5d2                        db         0x01
0x234ca5d3                        db         0x04                               ; DATA XREF=sub_23456f24+74
                              dword_234ca5d4:
0x234ca5d4                        db         0x09                               ; DATA XREF=dword_234ca4e8+8
0x234ca5d5                        db         0x01
0x234ca5d6                        db  0x00 ; '.'
0x234ca5d7                        db  0x00 ; '.'
0x234ca5d8                        dd         0x234ca568
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca5e0 = //234ca5e0
{
	0, 0x0047, 0x0064, 0x00dd, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_2379c098[0], 0, 0, 0
#if 0
0x234ca5e0                        db         0x00       
0x234ca5e1                        db         0x00
0x234ca5e2                        dw         0x0047
0x234ca5e4                        dw         0x0064
0x234ca5e6                        dw         0x00dd
0x234ca5e8                        dw         0x0080
0x234ca5ea                        db         0x01
0x234ca5eb                        db         0x04
0x234ca5ec                        db         0x09
0x234ca5ed                        db         0x01
0x234ca5ee 0000                   movs       r0, r0
0x234ca5f0                        dd         0x2379c098
0x234ca5f4 0000                   movs       r0, r0
0x234ca5f6 0000                   movs       r0, r0
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca6d0 = //234ca6d0
{
	0, 0x00ed, 0x0064, 0x0256, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_2379c138[0], 0, 0, 0
#if 0
0x234ca6d0                        db         0x00                               ; DATA XREF=0x234cac7c
0x234ca6d1                        db         0x00
0x234ca6d2                        dw         0x00ed
0x234ca6d4                        dw         0x0064
0x234ca6d6                        dw         0x0256
0x234ca6d8                        dw         0x0080
0x234ca6da                        db         0x01
0x234ca6db                        db         0x04
0x234ca6dc                        db         0x09
0x234ca6dd                        db         0x01
0x234ca6de 0000                   movs       r0, r0
0x234ca6e0                        dd         0x2379c138
0x234ca6e4 0000                   movs       r0, r0
0x234ca6e6 0000                   movs       r0, r0
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca6e8 = //Data_234ca6e8
{
	0, 0x00ed, 0x0084, 0x0256, 0x00a0, 0x01, 0x04, 0x09, 0x01, &Data_2379c160[0], 0, 0, 0
#if 0
0x234ca6e8                        db         0x00                               ; DATA XREF=0x234cacbc
0x234ca6e9                        db         0x00
0x234ca6ea                        dw         0x00ed
0x234ca6ec                        dw         0x0084
0x234ca6ee                        dw         0x0256
0x234ca6f0                        dw         0x00a0
0x234ca6f2                        db         0x01
0x234ca6f3                        db         0x04
0x234ca6f4                        db         0x09
0x234ca6f5                        db         0x01
0x234ca6f6 0000                   movs       r0, r0
0x234ca6f8                        dd         0x2379c160
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca700 = //234ca700
{
	0, 0x00ed, 0x00a4, 0x0256, 0x00c0, 0x01, 0x04, 0x09, 0x01, &Data_2379c188[0], 0, 0, 0
#if 0
0x234ca700                        db         0x00                               ; DATA XREF=0x234cacfc
0x234ca701                        db         0x00
0x234ca702                        dw         0x00ed
0x234ca704                        dw         0x00a4
0x234ca706                        dw         0x0256
0x234ca708                        dw         0x00c0
0x234ca70a                        db         0x01
0x234ca70b                        db         0x04
0x234ca70c                        db         0x09
0x234ca70d                        db         0x01
0x234ca70e 0000                   movs       r0, r0
0x234ca710                        dd         0x2379c188
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca718 = //234ca718
{
	0, 0x00ed, 0x00c4, 0x0256, 0x00e0, 0x01, 0x04, 0x09, 0x01, &Data_2379c1b0[0], 0, 0, 0
#if 0
0x234ca718                        db         0x00                               ; DATA XREF=0x234cad3c
0x234ca719                        db         0x00
0x234ca71a                        dw         0x00ed
0x234ca71c                        dw         0x00c4
0x234ca71e                        dw         0x0256
0x234ca720                        dw         0x00e0
0x234ca722                        db         0x01
0x234ca723                        db         0x04
0x234ca724                        db         0x09
0x234ca725                        db         0x01
0x234ca726 0000                   movs       r0, r0
0x234ca728                        dd         0x2379c1b0
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca730 = //234ca730
{
	0, 0x00ed, 0x00e4, 0x0256, 0x0100, 0x01, 0x04, 0x09, 0x01, &Data_2379c1d8[0], 0, 0, 0
#if 0
0x234ca730                        db         0x00                               ; DATA XREF=0x234cad7c
0x234ca731                        db         0x00
0x234ca732                        dw         0x00ed
0x234ca734                        dw         0x00e4
0x234ca736                        dw         0x0256
0x234ca738                        dw         0x0100                             ; DATA XREF=dword_234ca4e8+60
0x234ca73a                        db         0x01
0x234ca73b                        db         0x04
0x234ca73c                        db         0x09
0x234ca73d                        db         0x01
0x234ca73e 0000                   movs       r0, r0
0x234ca740                        dd         0x2379c1d8
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca748 = //234ca748
{
	0, 0x00ed, 0x0104, 0x0256, 0x0120, 0x01, 0x04, 0x09, 0x01, &Data_2379c200[0], 0, 0, 0
#if 0
0x234ca748                        db         0x00                               ; DATA XREF=0x234cadbc
0x234ca749                        db         0x00
0x234ca74a                        dw         0x00ed
0x234ca74c                        dw         0x0104
0x234ca74e                        dw         0x0256
0x234ca750                        dw         0x0120
0x234ca752                        db         0x01
0x234ca753                        db         0x04
0x234ca754                        db         0x09
0x234ca755                        db         0x01
0x234ca756 0000                   movs       r0, r0
0x234ca758                        dd         0x2379c200
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca760 = //234ca760
{
	0, 0x00ed, 0x0124, 0x0256, 0x0140, 0x01, 0x04, 0x09, 0x01, &Data_2379c228[0], 0, 0, 0
#if 0
0x234ca760                        db         0x00                               ; DATA XREF=0x234cadfc
0x234ca761                        db         0x00
0x234ca762                        dw         0x00ed
0x234ca764                        dw         0x0124
0x234ca766                        dw         0x0256
0x234ca768                        dw         0x0140
0x234ca76a                        db         0x01
0x234ca76b                        db         0x04
0x234ca76c                        db         0x09
0x234ca76d                        db         0x01
0x234ca76e 0000                   movs       r0, r0
0x234ca770                        dd         0x2379c228
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca778 = //234ca778
{
	0, 0x00ed, 0x0144, 0x0256, 0x0160, 0x01, 0x04, 0x09, 0x01, &Data_2379c250[0], 0, 0, 0
#if 0
0x234ca778                        db         0x00                               ; DATA XREF=0x234cae3c
0x234ca779                        db         0x00
0x234ca77a                        dw         0x00ed
0x234ca77c                        dw         0x0144                             ; DATA XREF=dword_234ca468+112
0x234ca77e                        dw         0x0256
0x234ca780                        dw         0x0160                             ; DATA XREF=dword_234ca468+116
0x234ca782                        db         0x01
0x234ca783                        db         0x04
0x234ca784                        db         0x09
0x234ca785                        db         0x01
0x234ca786 0000                   movs       r0, r0
0x234ca788                        dd         0x2379c250
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca790 = //234ca790
{
	0, 0x00ed, 0x0164, 0x0256, 0x0180, 0x01, 0x04, 0x09, 0x01, &Data_2379c278[0], 0, 0, 0
#if 0
0x234ca790                        db         0x00                               ; DATA XREF=0x234cae7c
0x234ca791                        db         0x00
0x234ca792                        dw         0x00ed
0x234ca794                        dw         0x0164
0x234ca796                        dw         0x0256
0x234ca798                        dw         0x0180
0x234ca79a                        db         0x01
0x234ca79b                        db         0x04
0x234ca79c                        db         0x09
0x234ca79d                        db         0x01
0x234ca79e 0000                   movs       r0, r0
0x234ca7a0                        dd         0x2379c278
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca7a8 = //234ca7a8
{
	0, 0x00ed, 0x0184, 0x0256, 0x01a0, 0x01, 0x04, 0x09, 0x01, &Data_2379c2a0[0], 0, 0, 0
#if 0
0x234ca7a8                        db         0x00                               ; DATA XREF=0x234caebc
0x234ca7a9                        db         0x00
0x234ca7aa                        dw         0x00ed
0x234ca7ac                        dw         0x0184
0x234ca7ae                        dw         0x0256
0x234ca7b0                        dw         0x01a0
0x234ca7b2                        db         0x01
0x234ca7b3                        db         0x04
0x234ca7b4                        db         0x09
0x234ca7b5                        db         0x01
0x234ca7b6 0000                   movs       r0, r0
0x234ca7b8                        dd         0x2379c2a0
#endif
};

uint8_t menu_epg_date_string[52] = "--.--.----"; //234ca7c0
uint8_t menu_epg_clock_time_string[] = "--:--  "; //234ca7f4

static Graphic_Job_2_5_Item_Text Data_234ca814 = //234ca814
{
	0, 0x0047, 0x0064, 0x0257, 0x01a0, 0x01, 0x04, 0x09, 0x01, &Data_23799d10[0], 0, 0, 0
#if 0
0x234ca814                        db         0x00                               ; DATA XREF=0x234cb9bc
0x234ca815                        db         0x00
0x234ca816                        dw         0x0047
0x234ca818                        dw         0x0064
0x234ca81a                        dw         0x0257
0x234ca81c                        dw         0x01a0
0x234ca81e                        db         0x01
0x234ca81f                        db         0x04
0x234ca820                        db         0x09
0x234ca821                        db         0x01
0x234ca822 0000                   movs       r0, r0
0x234ca824                        dd         0x23799d10
#endif
};

static Graphic_Job_2_5_Item_Text Data_234ca82c = //234ca82c
{
	0, 0x0047, 0x01c7, 0x0257, 0x01fd, 0x01, 0x05, 0x03, 0x01, &Data_2379c2d4[0], 0, 0, 0
#if 0
0x234ca82c                        db         0x00                               ; DATA XREF=0x234cb03c
0x234ca82d                        db         0x00
0x234ca82e                        dw         0x0047
0x234ca830                        dw         0x01c7
0x234ca832                        dw         0x0257
0x234ca834                        dw         0x01fd
0x234ca836                        db         0x01
0x234ca837                        db         0x05
0x234ca838                        db         0x03
0x234ca839                        db         0x01
0x234ca83a 0000                   movs       r0, r0
0x234ca83c                        dd         0x2379c2d4
0x234ca840 0000                   movs       r0, r0
0x234ca842 0000                   movs       r0, r0
#endif
};

static Graphic_Job_2_5_Item Data_234ca85c[34] = //234ca85c
{
    {0}, //[0] = 234ca85c
    {0}, //[1] = 234CA89C
    {1, 0, 0, 0/*Data_8*/, 0x003d, 0x0029, 0x00a2, 0x0026, 0, &Data_234c134c/*Data_0x18*/, 2, 0, &Data_234ca580/*Data_0x20*/}, //[2] = 234CA8DC: header / service name
#if 0
0x234ca8dc                        db         0x01                               ; DATA XREF=0x234cc1c0
0x234ca8dd                        db  0x00 ; '.'
0x234ca8de 0000                   movs       r0, r0
0x234ca8e0 0000                   movs       r0, r0
0x234ca8e2 0000                   movs       r0, r0
0x234ca8e4 0000                   movs       r0, r0
0x234ca8e6 0000                   movs       r0, r0
0x234ca8e8                        dw         0x003d
0x234ca8ea                        dw         0x0029
0x234ca8ec                        dw         0x00a2
0x234ca8ee                        dw         0x0026
0x234ca8f0 0000                   movs       r0, r0
0x234ca8f2 0000                   movs       r0, r0
0x234ca8f4                        dd         0x234c134c
0x234ca8f8                        dw         0x0002
0x234ca8fa                        dw         0x0000
0x234ca8fc                        dd         0x234ca580
#endif
    {0}, //[3] = 234CA91C
    {0}, //[4] = 234CA95C
    {0}, //[5] = 234CA99C
    {1, 0, 0, 0/*Data_8*/, 0x003d, 0x0060, 0x00a0, 0x0020, 0, &menu_main_graphic_item_background_dark_blue_top_round_left_right/*Data_0x18*/, 9, 0, &Data_234ca5e0/*Data_0x20*/}, //[6] = 234CA9DC
#if 0
0x234ca9dc                        db         0x01                               ; DATA XREF=0x234cbdf0
0x234ca9dd                        db  0x00 ; '.'
0x234ca9de 0000                   movs       r0, r0
0x234ca9e0 0000                   movs       r0, r0
0x234ca9e2 0000                   movs       r0, r0
0x234ca9e4 0000                   movs       r0, r0
0x234ca9e6 0000                   movs       r0, r0
0x234ca9e8                        dw         0x003d
0x234ca9ea                        dw         0x0060
0x234ca9ec                        dw         0x00a0
0x234ca9ee                        dw         0x0020
0x234ca9f0 0000                   movs       r0, r0
0x234ca9f2 0000                   movs       r0, r0
0x234ca9f4                        dd         0x234c12f8
0x234ca9f8                        dw         0x0009
0x234ca9fa                        dw         0x0000
0x234ca9fc                        dd         0x234ca5e0
#endif
    {0}, //[7] = 234CAA1C
    {0}, //[8] = 234CAA5C
    {0}, //[9] = 234CAA9C
    {0}, //[10] = 234CAADC
    {0}, //[11] = 234CAB1C
    {0}, //[12] = 234CAB5C
    {0}, //[13] = 234CAB9C
    {0}, //[14] = 234CABDC
    {0}, //[15] = 234CAC1C
    {1, 0, 0, 0/*Data_8*/, 0x00e3, 0x0060, 0x0173, 0x0020, 0, &menu_main_graphic_item_background_dark_blue_top_round_left_right/*Data_0x18*/, 9, 0, &Data_234ca6d0/*Data_0x20*/}, //[16] = 234CAC5C
#if 0
0x234cac5c                        dw         0x0001                             ; DATA XREF=0x234cbdf4
0x234cac5e 0000                   movs       r0, r0
0x234cac60 0000                   movs       r0, r0
0x234cac62 0000                   movs       r0, r0
0x234cac64 0000                   movs       r0, r0
0x234cac66 0000                   movs       r0, r0
0x234cac68                        dw         0x00e3
0x234cac6a                        dw         0x0060
0x234cac6c                        dw         0x0173
0x234cac6e                        dw         0x0020
0x234cac70 0000                   movs       r0, r0
0x234cac72 0000                   movs       r0, r0
0x234cac74                        dd         0x234c12f8
0x234cac78                        dw         0x0009
0x234cac7a                        dw         0x0000
0x234cac7c                        dd         0x234ca6d0
#endif
    {1, 0, 0, 0/*Data_8*/, 0x00e3, 0x0080, 0x0173, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234ca6e8/*Data_0x20*/}, //[17] = 234CAC9C
#if 0
0x234cac9c                        db         0x01                               ; DATA XREF=0x234cbe20
0x234cac9d                        db  0x00 ; '.'
0x234cac9e 0000                   movs       r0, r0
0x234caca0 0000                   movs       r0, r0                             ; DATA XREF=menu_epg_clock_time_string+840
0x234caca2 0000                   movs       r0, r0
0x234caca4 0000                   movs       r0, r0
0x234caca6 0000                   movs       r0, r0
0x234caca8                        dw         0x00e3
0x234cacaa                        dw         0x0080
0x234cacac                        dw         0x0173
0x234cacae                        dw         0x0020
0x234cacb0 0000                   movs       r0, r0
0x234cacb2 0000                   movs       r0, r0
0x234cacb4                        dd         0x234c12d4
0x234cacb8                        dw         0x0009
0x234cacba                        dw         0x0000
0x234cacbc                        dd         0x234ca6e8
#endif
    {1, 0, 0, 0/*Data_8*/, 0x00e3, 0x00a0, 0x0173, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234ca700/*Data_0x20*/}, //[18] = 234CACDC
#if 0
0x234cacdc                        db         0x01                               ; DATA XREF=0x234cbe4c
0x234cacdd                        db  0x00 ; '.'
0x234cacde 0000                   movs       r0, r0
0x234cace0 0000                   movs       r0, r0
0x234cace2 0000                   movs       r0, r0
0x234cace4 0000                   movs       r0, r0
0x234cace6 0000                   movs       r0, r0
0x234cace8                        dw         0x00e3
0x234cacea                        dw         0x00a0
0x234cacec                        dw         0x0173
0x234cacee                        dw         0x0020
0x234cacf0 0000                   movs       r0, r0
0x234cacf2 0000                   movs       r0, r0
0x234cacf4                        dd         0x234c12d4
0x234cacf8                        dw         0x0009
0x234cacfa                        dw         0x0000
0x234cacfc                        dd         0x234ca700
#endif
    {1, 0, 0, 0/*Data_8*/, 0x00e3, 0x00c0, 0x0173, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234ca718/*Data_0x20*/}, //[19] = 234CAD1C
#if 0
0x234cad1c                        db         0x01                               ; DATA XREF=0x234cbe78
0x234cad1d                        db  0x00 ; '.'
0x234cad1e 0000                   movs       r0, r0
0x234cad20 0000                   movs       r0, r0
0x234cad22 0000                   movs       r0, r0
0x234cad24 0000                   movs       r0, r0
0x234cad26 0000                   movs       r0, r0
0x234cad28                        dw         0x00e3
0x234cad2a                        dw         0x00c0
0x234cad2c                        dw         0x0173
0x234cad2e                        dw         0x0020
0x234cad30 0000                   movs       r0, r0
0x234cad32 0000                   movs       r0, r0
0x234cad34                        dd         0x234c12d4
0x234cad38                        dw         0x0009
0x234cad3a                        dw         0x0000
0x234cad3c                        dd         0x234ca718
#endif
    {1, 0, 0, 0/*Data_8*/, 0x00e3, 0x00e0, 0x0173, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234ca730/*Data_0x20*/}, //[20] = 234CAD5C
#if 0
0x234cad5c                        db         0x01                               ; DATA XREF=0x234cbea4
0x234cad5d                        db  0x00 ; '.'
0x234cad5e 0000                   movs       r0, r0
0x234cad60 0000                   movs       r0, r0
0x234cad62 0000                   movs       r0, r0
0x234cad64 0000                   movs       r0, r0
0x234cad66 0000                   movs       r0, r0
0x234cad68                        dw         0x00e3
0x234cad6a                        dw         0x00e0
0x234cad6c                        dw         0x0173
0x234cad6e                        dw         0x0020
0x234cad70 0000                   movs       r0, r0
0x234cad72 0000                   movs       r0, r0
0x234cad74                        dd         0x234c12d4
0x234cad78                        dw         0x0009
0x234cad7a 0000                   movs       r0, r0
0x234cad7c                        dd         0x234ca730
#endif
    {1, 0, 0, 0/*Data_8*/, 0x00e3, 0x0100, 0x0173, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234ca748/*Data_0x20*/}, //[21] = 234CAD9C
#if 0
0x234cad9c                        db         0x01                               ; DATA XREF=0x234cbed0
0x234cad9d                        db  0x00 ; '.'
0x234cad9e 0000                   movs       r0, r0
0x234cada0 0000                   movs       r0, r0
0x234cada2 0000                   movs       r0, r0
0x234cada4 0000                   movs       r0, r0
0x234cada6 0000                   movs       r0, r0
0x234cada8                        dw         0x00e3
0x234cadaa                        dw         0x0100
0x234cadac                        dw         0x0173
0x234cadae                        dw         0x0020
0x234cadb0 0000                   movs       r0, r0
0x234cadb2 0000                   movs       r0, r0
0x234cadb4                        dd         0x234c12d4
0x234cadb8                        dw         0x0009
0x234cadba                        dw         0x0000
0x234cadbc                        dd         0x234ca748
#endif
    {1, 0, 0, 0/*Data_8*/, 0x00e3, 0x0120, 0x0173, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234ca760/*Data_0x20*/}, //[22] = 234CADDC
#if 0
0x234caddc                        db         0x01                               ; DATA XREF=0x234cbefc
0x234caddd                        db  0x00 ; '.'
0x234cadde 0000                   movs       r0, r0
0x234cade0 0000                   movs       r0, r0                             ; DATA XREF=menu_epg_clock_time_string+968
0x234cade2 0000                   movs       r0, r0
0x234cade4 0000                   movs       r0, r0
0x234cade6 0000                   movs       r0, r0
0x234cade8                        dw         0x00e3
0x234cadea                        dw         0x0120
0x234cadec                        dw         0x0173
0x234cadee                        dw         0x0020
0x234cadf0 0000                   movs       r0, r0
0x234cadf2 0000                   movs       r0, r0
0x234cadf4                        dd         0x234c12d4
0x234cadf8 0900                   movs       r1, r1
0x234cadfa 0000                   movs       r0, r0
0x234cadfc                        dd         0x234ca760
#endif
    {1, 0, 0, 0/*Data_8*/, 0x00e3, 0x0140, 0x0173, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234ca778/*Data_0x20*/}, //[23] = 234CAE1C
#if 0
0x234cae1c                        db         0x01                               ; DATA XREF=0x234cbf28
0x234cae1d                        db  0x00 ; '.'
0x234cae1e 0000                   movs       r0, r0
0x234cae20 0000                   movs       r0, r0                             ; DATA XREF=menu_epg_clock_time_string+584
0x234cae22 0000                   movs       r0, r0
0x234cae24 0000                   movs       r0, r0
0x234cae26 0000                   movs       r0, r0
0x234cae28                        dw         0x00e3
0x234cae2a                        dw         0x0140
0x234cae2c                        dw         0x0173
0x234cae2e                        dw         0x0020
0x234cae30 0000                   movs       r0, r0
0x234cae32 0000                   movs       r0, r0
0x234cae34                        dd         0x234c12d4
0x234cae38                        dw         0x0009
0x234cae3a                        dw         0x0000
0x234cae3c                        dd         0x234ca778
#endif
    {1, 0, 0, 0/*Data_8*/, 0x00e3, 0x0160, 0x0173, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234ca790/*Data_0x20*/}, //[24] = 234CAE5C
#if 0
0x234cae5c                        db         0x01                               ; DATA XREF=0x234cbf54
0x234cae5d                        db  0x00 ; '.'
0x234cae5e 0000                   movs       r0, r0
0x234cae60 0000                   movs       r0, r0
0x234cae62 0000                   movs       r0, r0
0x234cae64 0000                   movs       r0, r0
0x234cae66 0000                   movs       r0, r0
0x234cae68                        dw         0x00e3
0x234cae6a                        dw         0x0160
0x234cae6c                        dw         0x0173
0x234cae6e                        dw         0x0020
0x234cae70 0000                   movs       r0, r0
0x234cae72 0000                   movs       r0, r0
0x234cae74                        dd         0x234c12d4
0x234cae78                        dw         0x0009
0x234cae7a                        dw         0x0000
0x234cae7c                        dd         0x234ca790
#endif
    {1, 0, 0, 0/*Data_8*/, 0x00e3, 0x0180, 0x0173, 0x0020, 0, &menu_main_graphic_item_background_dark_blue_bottom_round_left_right/*Data_0x18*/, 9, 0, &Data_234ca7a8/*Data_0x20*/}, //[25] = 234CAE9C
#if 0
0x234cae9c                        db         0x01                               ; DATA XREF=0x234cbf80
0x234cae9d                        db  0x00 ; '.'
0x234cae9e 0000                   movs       r0, r0
0x234caea0 0000                   movs       r0, r0
0x234caea2 0000                   movs       r0, r0
0x234caea4 0000                   movs       r0, r0
0x234caea6 0000                   movs       r0, r0
0x234caea8                        dw         0x00e3
0x234caeaa                        dw         0x0180
0x234caeac                        dw         0x0173
0x234caeae                        dw         0x0020
0x234caeb0 0000                   movs       r0, r0
0x234caeb2 0000                   movs       r0, r0
0x234caeb4                        dd         0x234c12ec
0x234caeb8                        dw         0x0009
0x234caeba 0000                   movs       r0, r0
0x234caebc                        dd         0x234ca7a8
#endif
    {1, 0, 0, 0/*Data_8*/, 0x00f6, 0x0029, 0x0102, 0x0026, 0, &Data_234c134c/*Data_0x18*/, 9, 0, &menu_epg_date_text_field/*Data_0x20*/}, //[26] = 234CAEDC: Date field
#if 0
0x234caedc                        db         0x01
0x234caedd                        db  0x00 ; '.'
0x234caede 0000                   movs       r0, r0
0x234caee0 0000                   movs       r0, r0
0x234caee2 0000                   movs       r0, r0
0x234caee4 0000                   movs       r0, r0
0x234caee6 0000                   movs       r0, r0
0x234caee8                        dw         0x00f6
0x234caeea                        dw         0x0029
0x234caeec                        dw         0x0102
0x234caeee                        dw         0x0026
0x234caef0 0000                   movs       r0, r0
0x234caef2 0000                   movs       r0, r0
0x234caef4                        dd         0x234c134c
0x234caef8                        dw         0x0009
0x234caefa                        dw         0x0000
0x234caefc                        dd         0x234ca598
#endif
    {0}, //[27] = 234CAF1C
    {1, 0, 0, 0/*Data_8*/, 0x020e, 0x0029, 0x0049, 0x0026, 0, &Data_234c1340/*Data_0x18*/, 3, 0, &menu_epg_clock_time_text_field/*Data_0x20*/}, //[28] = 234CAF5C: Clock Time
#if 0
0x234caf5c                        db         0x01
0x234caf5d                        db  0x00 ; '.'
0x234caf5e 0000                   movs       r0, r0
0x234caf60 0000                   movs       r0, r0
0x234caf62 0000                   movs       r0, r0
0x234caf64 0000                   movs       r0, r0
0x234caf66 0000                   movs       r0, r0
0x234caf68                        dw         0x020e
0x234caf6a                        dw         0x0029
0x234caf6c                        dw         0x0049
0x234caf6e                        dw         0x0026
0x234caf70 0000                   movs       r0, r0
0x234caf72 0000                   movs       r0, r0
0x234caf74                        dd         0x234c1340
0x234caf78                        dw         0x0009
0x234caf7a                        dw         0x0000
0x234caf7c                        dd         0x234ca5b0
#endif
    {0}, //[29] = 234CAF9C
    {0}, //[30] = 234CAFDC
    {1, 0, 0, 0/*Data_8*/, 0x003d, 0x01c3, 0x021a, 0x003a, 0, &Data_234c134c/*Data_0x18*/, 3, 0, &Data_234ca82c/*Data_0x20*/}, //[31] = 234CB01C: help
#if 0
0x234cb01c                        db         0x01                               ; DATA XREF=0x234cc1c4
0x234cb01d                        db  0x00 ; '.'
0x234cb01e 0000                   movs       r0, r0
0x234cb020 0000                   movs       r0, r0                             ; DATA XREF=asc_234ca7f4+1608
0x234cb022 0000                   movs       r0, r0
0x234cb024 0000                   movs       r0, r0
0x234cb026 0000                   movs       r0, r0
0x234cb028                        dw         0x003d
0x234cb02a                        dw         0x01c3
0x234cb02c                        dw         0x021a
0x234cb02e                        dw         0x003a
0x234cb030 0000                   movs       r0, r0
0x234cb032 0000                   movs       r0, r0
0x234cb034                        dd         0x234c134c
0x234cb038                        dw         0x0003
0x234cb03a                        dw         0x0000
0x234cb03c                        dd         0x234ca82c
#endif
    {0}, //[32] = 234CB05C
    {0}, //[33] = 234CB09C
}; //->234CB0DC

static Graphic_Job_2_5_Item Data_234cb95c[8] = //234cb95c
{
    {1, 0, 0, 0/*Data_8*/, 0x0037, 0x005a, 0x0226, 0x014c, 0, 
    &menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
    2, 0, 0/*Data_0x20*/}, //[0] = 234cb95c: header
#if 0
0x234cb95c                        db         0x01                               ; DATA XREF=sub_2345636a+14, sub_23456c9c+20, 0x234cbdac, 0x234cc238
0x234cb95d                        db  0x00 ; '.'
0x234cb95e 0000                   movs       r0, r0
0x234cb960 0000                   movs       r0, r0
0x234cb962 0000                   movs       r0, r0
0x234cb964 0000                   movs       r0, r0
0x234cb966 0000                   movs       r0, r0
0x234cb968                        dw         0x0037
0x234cb96a                        dw         0x005a
0x234cb96c                        dw         0x0226
0x234cb96e                        dw         0x014c                             ; DATA XREF=sub_23456c9c+40
0x234cb970 0000                   movs       r0, r0
0x234cb972 0000                   movs       r0, r0
0x234cb974                        dd         0x234c128c
0x234cb978                        dw         0x0002
#endif
    {1, 0, 0, 0/*Data_8*/, 0x003d, 0x0060, 0x021a, 0x0140, 0, &Data_234c134c/*Data_0x18*/, 3, 0, &Data_234ca814/*Data_0x20*/}, //[1] = 234CB99C
#if 0
0x234cb99c                        db         0x01                               ; DATA XREF=sub_2345636a+22, sub_23456c9c+38
0x234cb99d                        db  0x00 ; '.'
0x234cb99e 0000                   movs       r0, r0
0x234cb9a0 0000                   movs       r0, r0
0x234cb9a2 0000                   movs       r0, r0
0x234cb9a4 0000                   movs       r0, r0
0x234cb9a6 0000                   movs       r0, r0
0x234cb9a8                        dw         0x003d
0x234cb9aa                        dw         0x0060
0x234cb9ac                        dw         0x021a
0x234cb9ae                        dw         0x0140                             ; DATA XREF=sub_23456c9c+42
0x234cb9b0 0000                   movs       r0, r0
0x234cb9b2 0000                   movs       r0, r0
0x234cb9b4                        dd         0x234c134c
0x234cb9b8                        dw         0x0003
0x234cb9ba                        dw         0x0000
0x234cb9bc                        dd         0x234ca814
#endif
    {0, 0, 0, 0/*Data_8*/, 0x00f0, 0x0023, 0x010e, 0x0032, 0, 
    &menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
    2, 0, 0/*Data_0x20*/}, //[2] = 234CB9DC: Menu Item 0
#if 0
0x234cb9dc                        db         0x00                               ; DATA XREF=0x234cc160
0x234cb9dd                        db  0x00 ; '.'
0x234cb9de 0000                   movs       r0, r0
0x234cb9e0 0000                   movs       r0, r0                             ; DATA XREF=menu_epg_clock_time_string+3912, menu_epg_clock_time_string+3976
0x234cb9e2 0000                   movs       r0, r0
0x234cb9e4 0000                   movs       r0, r0
0x234cb9e6 0000                   movs       r0, r0
0x234cb9e8                        dw         0x00f0
0x234cb9ea                        dw         0x0023
0x234cb9ec                        dw         0x010e
0x234cb9ee                        dw         0x0032
0x234cb9f0 0000                   movs       r0, r0
0x234cb9f2 0000                   movs       r0, r0
0x234cb9f4                        dd         0x234c128c
0x234cb9f8                        dw         0x0002
#endif
    {0}, //[3] = 234CBA1C
    {0}, //[4] = 234CBA5C: help
    {0}, //[5] = 234CBA9C
    {1, 0, 0, 0/*Data_8*/, 0x020e, 0x0029, 0x0049, 0x0026, 0, &Data_234c134c/*Data_0x18*/, 9, 0, &Data_234ca5c8/*Data_0x20*/}, //[6] = 234CBADC
#if 0
0x234cbadc                        db         0x01                               ; DATA XREF=sub_2345636a+20
0x234cbadd                        db  0x00 ; '.'
0x234cbade 0000                   movs       r0, r0
0x234cbae0 0000                   movs       r0, r0
0x234cbae2 0000                   movs       r0, r0
0x234cbae4 0000                   movs       r0, r0
0x234cbae6 0000                   movs       r0, r0
0x234cbae8                        dw         0x020e
0x234cbaea                        dw         0x0029
0x234cbaec                        dw         0x0049
0x234cbaee                        dw         0x0026
0x234cbaf0 0000                   movs       r0, r0
0x234cbaf2 0000                   movs       r0, r0
0x234cbaf4                        dd         0x234c134c
0x234cbaf8                        dw         0x0009
0x234cbafa                        dw         0x0000
0x234cbafc                        dd         0x234ca5c8
#endif
    {0}, //[7] = 234CBB1C
};

static Graphic_Job_2_5 Data_234cbd5c = //234cbd5c
{
    0,
    0,
    0x10, //wData_2
    4, //bData_4
    &Data_234ca85c[0], //pItems
    &menu_main_graphic_color_data, //pColorData
    16, //numColors
    0,
    34, //bNumItems
    1, //bData_0x19
    sub_23456302, //Data_0x1c
    sub_234562ec, //Data_0x20
#if 0
0x234cbd5c                        db         0x00                               ; DATA XREF=sub_2345630e+10, sub_2345661e+14, dword_234cc1c8
0x234cbd5d                        db         0xfa
0x234cbd5e                        dw         0x0010
0x234cbd60                        db         0x04
0x234cbd61                        db  0x00 ; '.'
0x234cbd62 0000                   movs       r0, r0
0x234cbd64                        dd         0x234ca85c                         ; DATA XREF=sub_2345630e+12, sub_2345661e+16
0x234cbd68                        dd         0x234c123c
0x234cbd6c                        db         0x10
0x234cbd6d                        db  0x00 ; '.'
0x234cbd6e 0000                   movs       r0, r0
0x234cbd70 0000                   movs       r0, r0
0x234cbd72 0000                   movs       r0, r0
0x234cbd74                        db         0x22
0x234cbd75                        db         0x01
0x234cbd76 0000                   movs       r0, r0
0x234cbd78                        dd         sub_23456302+1
0x234cbd7c                        dd         sub_234562ec+1
#endif
};

static Graphic_Job_2_5 Data_234cbda4 = //234cbda4
{
    0,
    0,
    0x15, //wData_2
    4, //bData_4
    &Data_234cb95c[0], //pItems
    &menu_main_graphic_color_data, //pColorData
    16, //numColors
    0,
    8, //bNumItems
    0, //bData_0x19
    0, //Data_0x1c
    0, //Data_0x20
#if 0
0x234cbda4                        db         0x00                               ; DATA XREF=sub_2345636a+12, sub_23456c9c+18, dword_234cc240
0x234cbda5                        db         0xfa
0x234cbda6                        dw         0x0015
0x234cbda8                        db         0x04
0x234cbda9                        dw         0x0000
0x234cbdab                        db         0x00
0x234cbdac                        dd         0x234cb95c                         ; DATA XREF=sub_2345636a+14, sub_23456c9c+20
0x234cbdb0                        dd         menu_main_graphic_color_data
0x234cbdb4                        db         0x10
0x234cbdb5                        db  0x00 ; '.'
0x234cbdb6 0000                   movs       r0, r0
0x234cbdb8 0000                   movs       r0, r0
0x234cbdba 0000                   movs       r0, r0
0x234cbdbc                        db         0x08
#endif
};

static Menu_Item Data_234cbdec[] = //234cbdec
{
    //[0]
    {
        0x0000,
        0x0101,
        {&Data_234ca85c[6]/*234ca9dc*/, &Data_234ca85c[16]/*234cac5c*/},
        0,
        sub_234567d8, //onEvent
        sub_2344f102, //inputThreadFunc
        0,
        0,
#if 0
0x234cbdec                        dw         0x0000  
0x234cbdee                        dw         0x0101
0x234cbdf0                        dd         0x234ca9dc
0x234cbdf4                        dd         0x234cac5c
0x234cbdf8 0000                   movs       r0, r0
0x234cbdfa 0000                   movs       r0, r0
0x234cbdfc 0000                   movs       r0, r0
0x234cbdfe 0000                   movs       r0, r0
0x234cbe00 0000                   movs       r0, r0
0x234cbe02 0000                   movs       r0, r0
0x234cbe04 0000                   movs       r0, r0
0x234cbe06 0000                   movs       r0, r0
0x234cbe08                        dd         sub_234567d8+1
0x234cbe0c                        dd         sub_2344f102+1
0x234cbe10 0000                   movs       r0, r0
0x234cbe12 0000                   movs       r0, r0
0x234cbe14 0000                   movs       r0, r0
0x234cbe16 0000                   movs       r0, r0
#endif
    },
    //[1]
    {
        0x0000,
        0x0101,
        {&Data_234ca85c[7]/*234caa1c*/, &Data_234ca85c[17]/*234cac9c*/},
        0,
        sub_234567d8, //onEvent
        sub_2344f102, //inputThreadFunc
        0,
        0,
#if 0
0x234cbe18                        dw         0x0000
0x234cbe1a                        dw         0x0101
0x234cbe1c                        dd         0x234caa1c
0x234cbe20                        dd         0x234cac9c                         ; DATA XREF=asc_234ca7f4+4872
0x234cbe24 0000                   movs       r0, r0
0x234cbe26 0000                   movs       r0, r0
0x234cbe28 0000                   movs       r0, r0
0x234cbe2a 0000                   movs       r0, r0                             ; CODE XREF=dword_234cbdac+36
0x234cbe2c 0000                   movs       r0, r0
0x234cbe2e 0000                   movs       r0, r0
0x234cbe30 0000                   movs       r0, r0
0x234cbe32 0000                   movs       r0, r0
0x234cbe34                        dd         sub_234567d8+1
0x234cbe38                        dd         sub_2344f102+1
0x234cbe3c 0000                   movs       r0, r0
0x234cbe3e 0000                   movs       r0, r0
0x234cbe40 0000                   movs       r0, r0
0x234cbe42 0000                   movs       r0, r0
#endif
    },
    //[2]
    {
        0x0000,
        0x0101,
        {&Data_234ca85c[8]/*234caa5c*/, &Data_234ca85c[18]/*234cacdc*/},
        0,
        sub_234567d8, //onEvent
        sub_2344f102, //inputThreadFunc
        0,
        0,
#if 0
0x234cbe44                        dw         0x0000
0x234cbe46                        dw         0x0101
0x234cbe48                        dd         0x234caa5c
0x234cbe4c                        dd         0x234cacdc
0x234cbe50 0000                   movs       r0, r0
0x234cbe52 0000                   movs       r0, r0
0x234cbe54 0000                   movs       r0, r0
0x234cbe56 0000                   movs       r0, r0
0x234cbe58 0000                   movs       r0, r0
0x234cbe5a 0000                   movs       r0, r0
0x234cbe5c 0000                   movs       r0, r0
0x234cbe5e 0000                   movs       r0, r0
0x234cbe60                        dd         sub_234567d8+1
0x234cbe64                        dd         sub_2344f102+1
0x234cbe68 0000                   movs       r0, r0
0x234cbe6a 0000                   movs       r0, r0
0x234cbe6c 0000                   movs       r0, r0
0x234cbe6e 0000                   movs       r0, r0
#endif
    },
    //[3]
    {
        0x0000,
        0x0101,
        {&Data_234ca85c[9]/*234caa9c*/, &Data_234ca85c[19]/*234cad1c*/},
        0,
        sub_234567d8, //onEvent
        sub_2344f102, //inputThreadFunc
        0,
        0,
#if 0
0x234cbe70                        dw         0x0000
0x234cbe72                        dw         0x0101
0x234cbe74                        dd         0x234caa9c
0x234cbe78                        dd         0x234cad1c
0x234cbe7c 0000                   movs       r0, r0
0x234cbe7e 0000                   movs       r0, r0
0x234cbe80 0000                   movs       r0, r0
0x234cbe82 0000                   movs       r0, r0
0x234cbe84 0000                   movs       r0, r0
0x234cbe86 0000                   movs       r0, r0
0x234cbe88 0000                   movs       r0, r0
0x234cbe8a 0000                   movs       r0, r0
0x234cbe8c                        dd         sub_234567d8+1
0x234cbe90                        dd         sub_2344f102+1
0x234cbe94 0000                   movs       r0, r0
0x234cbe96 0000                   movs       r0, r0
0x234cbe98 0000                   movs       r0, r0
0x234cbe9a 0000                   movs       r0, r0
#endif
    },
    //[4]
    {
        0x0000,
        0x0101,
        {&Data_234ca85c[10]/*234caadc*/, &Data_234ca85c[20]/*234cad5c*/},
        0,
        sub_234567d8, //onEvent
        sub_2344f102, //inputThreadFunc
        0,
        0,
#if 0
0x234cbe9c                        dw         0x0000
0x234cbe9e                        dw         0x0101
0x234cbea0                        dd         0x234caadc
0x234cbea4                        dd         0x234cad5c
0x234cbea8 0000                   movs       r0, r0
0x234cbeaa 0000                   movs       r0, r0
0x234cbeac 0000                   movs       r0, r0
0x234cbeae 0000                   movs       r0, r0
0x234cbeb0 0000                   movs       r0, r0
0x234cbeb2 0000                   movs       r0, r0
0x234cbeb4 0000                   movs       r0, r0
0x234cbeb6 0000                   movs       r0, r0
0x234cbeb8                        dd         sub_234567d8+1
0x234cbebc                        dd         sub_2344f102+1
0x234cbec0 0000                   movs       r0, r0
0x234cbec2 0000                   movs       r0, r0
0x234cbec4 0000                   movs       r0, r0
0x234cbec6 0000                   movs       r0, r0
#endif
    },
    //[5]
    {
        0x0000,
        0x0101,
        {&Data_234ca85c[11]/*234cab1c*/, &Data_234ca85c[21]/*234cad9c*/},
        0,
        sub_234567d8, //onEvent
        sub_2344f102, //inputThreadFunc
        0,
        0,
#if 0
0x234cbec8                        dw         0x0000
0x234cbeca                        dw         0x0101
0x234cbecc                        dd         0x234cab1c
0x234cbed0                        dd         0x234cad9c
0x234cbed4 0000                   movs       r0, r0
0x234cbed6 0000                   movs       r0, r0
0x234cbed8 0000                   movs       r0, r0
0x234cbeda 0000                   movs       r0, r0
0x234cbedc 0000                   movs       r0, r0
0x234cbede 0000                   movs       r0, r0
0x234cbee0 0000                   movs       r0, r0
0x234cbee2 0000                   movs       r0, r0
0x234cbee4                        dd         sub_234567d8+1
0x234cbee8                        dd         sub_2344f102+1
0x234cbeec 0000                   movs       r0, r0
0x234cbeee 0000                   movs       r0, r0
0x234cbef0 0000                   movs       r0, r0
0x234cbef2 0000                   movs       r0, r0
#endif
    },
    //[6]
    {
        0x0000,
        0x0101,
        {&Data_234ca85c[12]/*234cab5c*/, &Data_234ca85c[22]/*234caddc*/},
        0,
        sub_234567d8, //onEvent
        sub_2344f102, //inputThreadFunc
        0,
        0,
#if 0
0x234cbef4                        dw         0x0000
0x234cbef6                        dw         0x0101
0x234cbef8                        dd         0x234cab5c
0x234cbefc                        dd         0x234caddc
0x234cbf00 0000                   movs       r0, r0
0x234cbf02 0000                   movs       r0, r0
0x234cbf04 0000                   movs       r0, r0
0x234cbf06 0000                   movs       r0, r0
0x234cbf08 0000                   movs       r0, r0
0x234cbf0a 0000                   movs       r0, r0
0x234cbf0c 0000                   movs       r0, r0
0x234cbf0e 0000                   movs       r0, r0
0x234cbf10                        dd         sub_234567d8+1
0x234cbf14                        dd         sub_2344f102+1
0x234cbf18 0000                   movs       r0, r0
0x234cbf1a 0000                   movs       r0, r0
0x234cbf1c 0000                   movs       r0, r0
0x234cbf1e 0000                   movs       r0, r0
#endif
    },
    //[7]
    {
        0x0000,
        0x0101,
        {&Data_234ca85c[13]/*234cab9c*/, &Data_234ca85c[23]/*234cae1c*/},
        0,
        sub_234567d8, //onEvent
        sub_2344f102, //inputThreadFunc
        0,
        0,
#if 0
0x234cbf20                        dw         0x0000
0x234cbf22                        dw         0x0101
0x234cbf24                        dd         0x234cab9c
0x234cbf28                        dd         0x234cae1c
0x234cbf2c 0000                   movs       r0, r0
0x234cbf2e 0000                   movs       r0, r0
0x234cbf30 0000                   movs       r0, r0
0x234cbf32 0000                   movs       r0, r0
0x234cbf34 0000                   movs       r0, r0
0x234cbf36 0000                   movs       r0, r0
0x234cbf38 0000                   movs       r0, r0
0x234cbf3a 0000                   movs       r0, r0
0x234cbf3c                        dd         sub_234567d8+1
0x234cbf40                        dd         sub_2344f102+1
0x234cbf44 0000                   movs       r0, r0
0x234cbf46 0000                   movs       r0, r0
0x234cbf48 0000                   movs       r0, r0
0x234cbf4a 0000                   movs       r0, r0
#endif
    },
    //[8]
    {
        0x0000,
        0x0101,
        {&Data_234ca85c[14]/*234cabdc*/, &Data_234ca85c[24]/*234cae5c*/},
        0,
        sub_234567d8, //onEvent
        sub_2344f102, //inputThreadFunc
        0,
        0,
#if 0
0x234cbf4c                        dw         0x0000
0x234cbf4e                        dw         0x0101
0x234cbf50                        dd         0x234cabdc
0x234cbf54                        dd         0x234cae5c
0x234cbf58 0000                   movs       r0, r0
0x234cbf5a 0000                   movs       r0, r0
0x234cbf5c 0000                   movs       r0, r0
0x234cbf5e 0000                   movs       r0, r0
0x234cbf60 0000                   movs       r0, r0
0x234cbf62 0000                   movs       r0, r0
0x234cbf64 0000                   movs       r0, r0
0x234cbf66 0000                   movs       r0, r0
0x234cbf68                        dd         sub_234567d8+1
0x234cbf6c                        dd         sub_2344f102+1
0x234cbf70 0000                   movs       r0, r0
0x234cbf72 0000                   movs       r0, r0
0x234cbf74 0000                   movs       r0, r0
0x234cbf76 0000                   movs       r0, r0
#endif
    },
    //[9]
    {
        0x0000,
        0x0101,
        {&Data_234ca85c[15]/*234cac1c*/, &Data_234ca85c[25]/*234cae9c*/},
        0,
        sub_234567d8, //onEvent
        sub_2344f102, //inputThreadFunc
        0,
        0,
#if 0
0x234cbf78                        dw         0x0000
0x234cbf7a                        dw         0x0101
0x234cbf7c                        dd         0x234cac1c
0x234cbf80                        dd         0x234cae9c
0x234cbf84 0000                   movs       r0, r0
0x234cbf86 0000                   movs       r0, r0
0x234cbf88 0000                   movs       r0, r0
0x234cbf8a 0000                   movs       r0, r0
0x234cbf8c 0000                   movs       r0, r0
0x234cbf8e 0000                   movs       r0, r0
0x234cbf90 0000                   movs       r0, r0
0x234cbf92 0000                   movs       r0, r0
0x234cbf94                        dd         sub_234567d8+1
0x234cbf98                        dd         sub_2344f102+1
0x234cbf9c 0000                   movs       r0, r0
0x234cbf9e 0000                   movs       r0, r0
0x234cbfa0 0000                   movs       r0, r0
0x234cbfa2 0000                   movs       r0, r0
#endif
    },
};

static Menu_Item Data_234cc15c[] = //234cc15c
{
    [0]
    {
        0xffff,
        0x0104,
        {&Data_234cb95c[2]/*234cb9dc*/},
        0,
        sub_23456bd0, //onEvent
        sub_234500bc, //inputThreadFunc
        0,
        0,
#if 0
0x234cc15c                        dw         0xffff                             ; DATA XREF=0x234cc230, 0x234cc234
0x234cc15e                        dw         0x0104
0x234cc160                        dd         0x234cb9dc
0x234cc164 0000                   movs       r0, r0
0x234cc166 0000                   movs       r0, r0
0x234cc168 0000                   movs       r0, r0
0x234cc16a 0000                   movs       r0, r0
0x234cc16c 0000                   movs       r0, r0
0x234cc16e 0000                   movs       r0, r0
0x234cc170 0000                   movs       r0, r0
0x234cc172 0000                   movs       r0, r0
0x234cc174 0000                   movs       r0, r0
0x234cc176 0000                   movs       r0, r0
0x234cc178                        dd         sub_23456bd0+1
0x234cc17c                        dd         sub_234500bc+1
0x234cc180 0000                   movs       r0, r0
0x234cc182 0000                   movs       r0, r0
0x234cc184 0000                   movs       r0, r0
0x234cc186 0000                   movs       r0, r0
#endif
    },
};

static Menu Data_234cc1b4 = //234cc1b4
{
    0xffff,
    &Data_234cbdec[0],
    &Data_234cbdec[0],
    &Data_234ca85c[2], //header
    0, //&Data_234ca85c[31], //help
    &Data_234cbd5c, //graphicData
    9, //maxItem
    0, //currentItem
    graphic_start_job_2_5,
    sub_2348de88, //onNavigate
    sub_23456aa2, //onEnter
    sub_23456bc0, //onExit
    0,
    100,
#if 0
0x234cc1b4                        dw         0xffff                             ; DATA XREF=sub_2345630e+8, sub_2345661e+12, sub_23456932+20, sub_23456aa2+114, sub_23456ed0+22, sub_23456ed0+28, sub_23456ed0+36, sub_23456f72+8, dword_234ca55c
0x234cc1b6 0000                   movs       r0, r0
0x234cc1b8                        dd         0x234cbdec
0x234cc1bc                        dd         0x234cbdec                         ; DATA XREF=sub_23456932+22
0x234cc1c0                        dd         0x234ca8dc
0x234cc1c4                        dd         0x234cb01c
0x234cc1c8                        dd         0x234cbd5c                         ; DATA XREF=sub_2345630e+10, sub_2345661e+14
0x234cc1cc                        db         0x09
0x234cc1cd                        db         0x00
0x234cc1ce 0000                   movs       r0, r0
0x234cc1d0                        dd         graphic_start_job_2_5
0x234cc1d4                        dd         sub_2348de88+1
0x234cc1d8                        dd         sub_23456aa2+1                     ; CODE XREF=dword_234cc2b4+16
0x234cc1dc                        dd         sub_23456bc0+1
0x234cc1e0 0000                   movs       r0, r0
0x234cc1e2 0000                   movs       r0, r0
0x234cc1e4                        dd         0x00000064
0x234cc1e8 0000                   movs       r0, r0
0x234cc1ea 0000                   movs       r0, r0
0x234cc1ec 0000                   movs       r0, r0
0x234cc1ee 0000                   movs       r0, r0
#endif
};

static Menu Data_234cc22c = //234cc22c
{
    0xffff,
    &Data_234cc15c[0],
    &Data_234cc15c[0],
    &Data_234cb95c[0], //header
    0, //234cba5c &Data_, //help
    &Data_234cbda4, //graphicData
    0, //maxItem
    0, //currentItem
    graphic_start_job_2_5,
#if 0
0x234cc22c                        dw         0xffff                             ; DATA XREF=sub_2345636a+10, sub_23456bd0+8, sub_23456c9c+16, dword_234ca560, 0x234ca578
0x234cc22e                        dw         0x0000
0x234cc230                        dd         0x234cc15c
0x234cc234                        dd         0x234cc15c
0x234cc238                        dd         0x234cb95c
0x234cc23c                        dd         0x234cba5c
                              dword_234cc240:
0x234cc240                        dd         0x234cbda4                         ; DATA XREF=sub_2345636a+12, sub_23456c9c+18
0x234cc244 0000                   movs       r0, r0
0x234cc246 0000                   movs       r0, r0
0x234cc248                        dd         graphic_start_job_2_5
0x234cc24c 0000                   movs       r0, r0
0x234cc24e 0000                   movs       r0, r0
0x234cc250 0000                   movs       r0, r0
0x234cc252 0000                   movs       r0, r0
0x234cc254 0000                   movs       r0, r0
0x234cc256 0000                   movs       r0, r0
0x234cc258 0000                   movs       r0, r0
0x234cc25a 0000                   movs       r0, r0
0x234cc25c 0000                   movs       r0, r0
0x234cc25e 0000                   movs       r0, r0
0x234cc260 0000                   movs       r0, r0
0x234cc262 0000                   movs       r0, r0
0x234cc264 0000                   movs       r0, r0
0x234cc266 0000                   movs       r0, r0
#endif
};


uint8_t Data_23799ce8[40]; //23799ce8, size???
uint8_t Data_23799d10[2500]; //23799d10, size???
User_Settings Data_2379a6d4; //2379a6d4 +0x1c = 2379A6F0
uint8_t menu_epg_weekday_string[20]; //2379A6F0 +0x14 = 2379a704
EIT_Event* Data_2379a704[1600]; //2379a704 -> 2379C004
struct 
{
    EIT_Event* Data_2379c004; //2379c004
    EIT_EventList* Data_2379c008; //2379c008 +4
    Struct_2348dc50* Data_2379c00c; //2379c00c +8
    uint16_t fill_2379c010; //2379c010 +0x0c
    uint16_t wData_2379c012; //2379c012 +0x0e
    uint16_t wData_2379c014; //2379c014 +0x10
    uint16_t fill_2379c016; //2379c016 +0x12
    uint8_t bData_2379c018; //2379c018 +0x14
    uint8_t bData_2379c019; //2379C019 +0x15
    //???
    struct
    {
        int fill_2379c01c; //2379c01c
        int Data_2379c020; //2379c020
        //8
    } Data_2379c01c[6]; //2379c01c
    //???
} Data_2379c004; //2379c004
//???
Channel Data_2379c04c; //2379c04c +0x28 = 2379C074
Transponder Data_2379c074; //2379c074 +0x18 = 2379C08C
Clock_Time Data_2379c08c; //2379c08c
uint8_t Data_2379c098[100]; //2379c098, size???
uint8_t Data_2379c138[40]; //2379c138, size???
uint8_t Data_2379c160[40]; //2379c160, size???
uint8_t Data_2379c188[40]; //2379c188, size???
uint8_t Data_2379c1b0[40]; //2379c1b0, size???
uint8_t Data_2379c1d8[40]; //2379c1d8, size???
uint8_t Data_2379c200[40]; //2379c200, size???
uint8_t Data_2379c228[40]; //2379c228, size???
uint8_t Data_2379c250[40]; //2379c250, size???
uint8_t Data_2379c278[40]; //2379c278, size???
uint8_t Data_2379c2a0[40]; //2379c2a0, size???
uint8_t Data_2379c2d4[100]; //2379c2d4, size???


/* /  / 234562ec - complete */
int sub_234562ec(void)
{
#if 0
	console_send_string("sub_234562ec (todo.c): TODO\r\n");
#endif

    uint8_t err = 0;

    OSSemPend(Data_234c1258, 0, &err);

    return 0;
}


/* /  / 23456302 - complete */
void sub_23456302(void)
{
#if 0
	console_send_string("sub_23456302 (todo.c): TODO\r\n");
#endif

    OSSemPost(Data_234c1258);
}


/*  /  / 2345630e - todo */
void menu_epg_update_clock_time_text_field(void)
{
#if 0
	console_send_string("menu_epg_update_clock_time_text_field (todo.c): TODO\r\n");
#endif

    Graphic_Job_2_5_Item* r4 = &Data_234ca55c->graphicData->pItems[28];
    char* pString = r4->pText->pString;

    clocktime_get(&Data_2379c08c);

    if (Data_2379c08c.bData_4 != 0)
    {
        //0x23456330
        sub_23411da0/*sub_234197b4*/(&Data_2379c08c, Data_2379a6d4.timeDiff);

        sprintf(pString, "%02d:%02d", 
            Data_2379c08c.hours, Data_2379c08c.minutes);
        
        if (bData_234ca54c != 0)
        {
            pString[2] = ' ';
        }
        //loc_23456350
        bData_234ca54c ^= 1; 
    }
    else
    {
        //loc_2345635a
        sprintf(pString, "--:--");
    }
    //loc_23456362
    r4->pText->bUpdate = 1;
}


/* /  / 2345636a - todo */
void sub_2345636a(EIT_Event* r6)
{
#if 0
	console_send_string("sub_2345636a (todo.c): TODO\r\n");
#endif

    char* sp_0x18;
    Graphic_Job_2_5_Item* sp_0x14;
    Graphic_Job_2_5_Item* sp_0x10;
    uint16_t r4 = 0;

    sp_0x10 = &Data_234ca560->graphicData->pItems[6];
    sp_0x14 = &Data_234ca560->graphicData->pItems[1];

    if (r6 != 0)
    {
        //0x2345638a
        sp_0x18 = sp_0x10->pText->pString;

        if (r6->Data_8 != 0)
        {
            //0x2345639a
            struct Struct_2377b8d0_Inner8_Inner8_Inner0* r5 = r6->Data_8->Data_0;
            if ((r5 == 0) && (r6->Data_8->Data_4 == 0))
            {
                //0x234563a6
                text_table_get_string(0x28, &Data_23799d10[0], 2480);
                //->loc_2345643e
            }
            else
            {
                //loc_234563b0
                struct Struct_2377b8d0_Inner8_Inner8_Inner0* r7 = r5;
                //->loc_234563c8
                while (r5 != 0)
                {
                    //loc_234563b4
                    int r0 = sub_2340beb0(r5->ISO_639_language_code, Data_2379a6d4.menuLanguage);
                    if (r0 != 0)
                    {
                        //0x234563c2
                        r7 = r5;
                        //->loc_234563cc
                        break;
                    }
                    //loc_234563c6
                    r5 = r5->next;
                }
                //loc_234563cc
                if (r7 != 0)
                {
                    //0x234563d0
                    char* r2 = r7->strName;
                    if (r2[0] == 0x10)
                    {
                        r2 += 3;
                    }
                    //loc_234563da
                    char* r3 = r7->strText;
                    if (r3[0] == 0x10)
                    {
                        r3 += 3;
                    }
                    //loc_234563e4
                    if (r3 != 0)
                    {
                        sprintf(&Data_23799d10[0], "%s\n%s\n", r2, r3);
                        //->loc_234563fa
                    }
                    else
                    {
                        //loc_234563f2
                        sprintf(&Data_23799d10[0], "%s\n\n", r2);
                    }
                    //loc_234563fa
                    r4 = strlen(&Data_23799d10[0]);
                }
                //loc_23456402
                struct Struct_2377b8d0_Inner8_Inner8_Inner4* r5 = r6->Data_8->Data_4;
                if (r5 != 0)
                {
                    //0x2345640a
                    struct Struct_2377b8d0_Inner8_Inner8_Inner4* r6 = r5;
                    while (r6 != 0)
                    {
                        //loc_2345640c
                        int r0 = sub_2340beb0(r6->Data_0, Data_2379a6d4.menuLanguage);
                        if (r0 != 0)
                        {
                            r5 = r6;
                            //->loc_23456424
                            break;
                        }
                        //loc_2345641e
                        r6 = r6->next;
                    }
                    //loc_23456424
                    char* r1 = r5->Data_4;
                    if (r1 != 0)
                    {
                        //0x2345642a
                        char* r0 = r7->strName;
                        if (r0[0] == 0x10)
                        {
                            r1 += 3;
                        }
                        //loc_23456434
                        strncat(&Data_23799d10[0], r1, 2499 - r4);
                    }
                    //loc_2345643e
                }
                //loc_2345643e
            }
            //loc_2345643e
            char* r1 = &Data_23799d10[0];
            //->loc_23456458
            while (r4 < 2500)
            {
                //loc_23456448
                char ch = r1[r4];
                if (ch == 0)
                {
                    //->loc_2345645c
                    break;
                }
                if (ch == 0x0a)
                {
                    r1[r4] = ' ';
                }
                //loc_23456454
                r4++;
            }
            //loc_2345645c
            sub_234089e8/*sub_2340b4c4*/(&Data_2379c004.bData_2379c018, &Data_23799d10[0], 
                sp_0x14->pText->bData_0xd,
                sp_0x14->pText->x1,
                sp_0x14->pText->y1,
                sp_0x14->pText->x2,
                0x0c);

            //r1 = 2379A704 + Data_2379c004.bData_2379c019 * 8;
            //->loc_2345648c
            char* r0 = Data_2379c004.Data_2379c01c[Data_2379c004.bData_2379c019].Data_2379c020;
            if (r0 != 0)
            {
                //0x23456498
                sp_0x14->pText->pString = r0;
            }
            //loc_2345649e
            sprintf(sp_0x18, "%d/%d", 
                Data_2379c004.bData_2379c019 + 1,
                Data_2379c004.bData_2379c018 + 1);

            uint16_t helpStringId;
            if ((Data_2379c004.bData_2379c018 + 1) > 1)
            {
                //0x234564b8
                helpStringId = wData_234ca550;
            }
            else
            {
                //loc_234564bc
                helpStringId = wData_234ca54e;
            }
            //loc_234564be
            Data_234ca560->Data_8->helpStringId = helpStringId;

            sp_0x14->pText->bUpdate = 1;
            sp_0x10->pText->bUpdate = 1;
            //loc_234564d2
        }
        else
        {
            //loc_2345648a -> loc_234564d6
            text_table_get_string(0x28, &Data_23799d10[0], 2480);
        }
    }
    //loc_23456488 -> loc_234564d2
}


/* /  / 234564e0 - todo */
int sub_234564e0(uint16_t* a)
{
#if 0
	console_send_string("sub_234564e0 (todo.c): TODO\r\n");
#endif

    uint16_t index;

    if (a != 0)
    {
        *a = 0;

        EIT_Event** r4 = &Data_2379a704[0];
        EIT_Event* r1 = Data_2379c004.Data_2379c004;

        if (r1 != 0)
        {
            //->loc_2345652c
            for (index = 0; index < Data_2379c004.wData_2379c012; index++)
            {
                //loc_234564fe
                if (((*r4)->wData_0x16 == r1->wData_0x16) && 
                    ((*r4)->start_time[0] == r1->start_time[0]) &&
                    ((*r4)->start_time[1] == r1->start_time[1]) &&
                    ((*r4)->start_time[2] == r1->start_time[2]))
                {
                    *a = index;

                    return 1;
                }
                //loc_23456526
                r4++;
            }
            //loc_23456530
        }
        //loc_23456530
    }
    //loc_23456530
    return 0;
}


/* /  / 23456534 - todo */
void sub_23456534(void)
{
#if 0
	console_send_string("sub_23456534 (todo.c): TODO\r\n");
#endif

    uint32_t r4;
    uint32_t r3;
    uint32_t r2;
    EIT_Event* sp8;
    uint32_t sp4;
    uint32_t sp;
    uint32_t a, b, c;
    uint32_t lr;
    uint32_t ip;
    
    if (Data_2379c004.wData_2379c012 != 0)
    {
        ip = Data_2379c004.wData_2379c012;
        while (1)
        {
            //loc_23456542
            r2 = 0;
            lr = 0;
            r4 = 0;
            EIT_Event** r0 = &Data_2379a704[0];
            EIT_Event** r1 = r0 + 1;
            r2 = ip;
            r2--;
            sp4 = r2;
            //->loc_234565a2
            while (r4 < r2)
            {
                //loc_23456556
                EIT_Event* pEvent = *r0;

                a = pEvent->section_number;
                b = pEvent->table_id;
                c = pEvent->bData_0x1b;
                sp8 = pEvent;

                sp = (a * 100) + ((b & 0x0f) * 100000) + c;

                pEvent = *r1;

                a = pEvent->section_number;
                b = pEvent->table_id;
                c = pEvent->bData_0x1b;

                r3 = (a * 100) + ((b & 0x0f) * 100000) + c;

                if (sp > r3)
                {
                    //0x23456590
                    lr = 1;
                    *r0 = pEvent;
                    *r1 = sp8;
                }
                //loc_2345659a
                r2 = sp4;
                r0++;
                r1++;
                r4++;
            }
            //0x234565a6
            ip--;
            if ((lr == 0) || (ip == 0))
            {
                //->loc_234565b8
                break;
            }
            //->loc_23456542
        } //while (1)
    }
    //loc_234565b8
}


/* /  / 234565ba - todo */
int sub_234565ba(void)
{
#if 0
	console_send_string("sub_234565ba (todo.c): TODO\r\n");
#endif

    EIT_Event* pEvent;
    EIT_Event** pList;

    Data_2379c004.wData_2379c012 = 0;
    Data_2379c004.wData_2379c014 = 0;

    Data_2379c004.Data_2379c008 = 
        eit_get_section_data(Data_2379c04c.service_id, Data_2379c074.transport_stream_id);

    if (Data_2379c004.Data_2379c008 != 0)
    {
        //0x234565da
        pList = &Data_2379a704[0];
        pEvent = Data_2379c004.Data_2379c008->pEventFirst;
    }
    else
    {
        //loc_234565e2
        Data_2379c004.wData_2379c012 = 0;

        return 2;
    }
    //->loc_23456618
    while (pEvent != 0)
    {
        //->loc_234565e8
        if (pEvent->table_id == 0x4e)
        {
            if (Data_2379c004.wData_2379c012 >= 1599)
            {
                return 1;
            }
            //loc_234565fa
            *pList++ = pEvent;

            Data_2379c004.wData_2379c012++;
        }
        //loc_23456602
        if ((pEvent->running_status == 4) &&
            (Data_2379c004.wData_2379c014 == 0))
        {
            Data_2379c004.wData_2379c014 = pEvent->event_id;
            Data_2379c004.Data_2379c004 = pEvent;
        }
        //loc_23456616
        pEvent = pEvent->next;
    }

    return 0;
}


/* /  / 2345661e - todo */
void menu_epg_update_date_text_field(EIT_Event* pEvent)
{
#if 0
	console_send_string("menu_epg_update_date_text_field (todo.c): TODO\r\n");
#endif

    Struct_23419f50 sp8;

    Graphic_Job_2_5_Item* pItem = &Data_234ca55c->graphicData->pItems[26];

    if (pEvent != 0)
    {
        char* pString = pItem->pText->pString;

        if (pEvent->wData_0x16 != 0)
        {
            sp8.time_of_change_mjd = pEvent->wData_0x16;
            sp8.time_of_change_utc_hours = sub_23456fd8(pEvent->start_time[0]);
            sp8.time_of_change_utc_minutes = sub_23456fd8(pEvent->start_time[1]);

            sub_23412444(&sp8);

            sub_23412148(&sp8, Data_2379a6d4.timeDiff);

            memset(&menu_epg_weekday_string[0], 0, 20);

            text_table_get_string(sp8.weekDay + 2, &menu_epg_weekday_string[0], 19);

            snprintf(pString, 50, "%s %s", &menu_epg_weekday_string[0], &sp8.Data_0[0]);
        } //if (pEvent->wData_0x16 != 0)
        else
        {
            strncpy(pString, "      - - . - - . - - - -", 50);
        }

        pItem->pText->bUpdate = 1;
    }
}


/* /  / 234566a8 - todo */
void sub_234566a8(void)
{
#if 0
	console_send_string("sub_234566a8 (todo.c): TODO\r\n");
#endif

    uint8_t sp_0x1c;
    uint16_t sp_0x18;
    Graphic_Queue_Item sp8;
    PSI_Program* sp4;
    uint16_t sp;

    sp_0x18 = 0;

    Struct_2348dc50* r4 = Data_2379c004.Data_2379c00c;

    if (Data_2379c04c.wTransponderIndex == 0xffff)
    {
        if (0 == psi_get_all_current_programs(main_hPSIDecoder1, &sp, &sp4))
        {
            Data_2379c074.transport_stream_id/*2379C084*/ = sp4->transport_stream_id;
            Data_2379c04c.service_id = sp4->pat_program_number;
        }
    }
    //loc_234566e6
    int r0 = sub_2345703c(&sp_0x1c);
    int r1 = 0;
    if (r0 == 0)
    {
        //->loc_2345676c
        r0 = sub_23456fe8(&sp_0x1c);
        r1 = 1;
    }
    //loc_23456774
    if ((Data_2379c004.wData_2379c012 != r0) || (sp_0x1c != 0))
    {
        //loc_23456784
        if (r1 == 0)
        {
            //0x23456788
            sub_23457200();
            //->loc_23456792
        }
        else
        {
            //loc_2345678e
            sub_234565ba();
        }
        //loc_23456792
        sub_23456534();

        if (0 != sub_234564e0(&sp_0x18))
        {
            //0x234567a0
            r4->arwData_0x28[0] = sp_0x18 + 1;
            r4->Data_0x54 = &r4->arwData_0x28[0];
        }
        //loc_234567ae
        r4->wData_0x20 = Data_2379c004.wData_2379c012;

        if (r4->Data_0x14 != 0)
        {
            //0x234567b8
            (r4->Data_0x14)(r4);
        }
        //loc_234567bc
        sub_2348dcd8(r4->bData_0x5f);
        //loc_234567c4
        graphic_start_job_2_5(&sp8, Data_234ca55c->graphicData);
        return;
    }
    //->loc_234567d2
    menu_epg_update_clock_time_text_field();
    //->loc_234567c4
    graphic_start_job_2_5(&sp8, Data_234ca55c->graphicData);
}


/* /  / 234567d8 - todo */
int sub_234567d8(Struct_2348dc50* r5)
{
#if 0
	console_send_string("sub_234567d8 (todo.c): TODO\r\n");
#endif

    Struct_2348dc50 sp4;

    if (r5 != 0)
    {
        //0x234567e0
        sp4 = *r5;

#if 1
        {
            extern char debug_string[];
            sprintf(debug_string, "sub_234567d8: sp4.Data_0 = 0x%x, sp4.wData_0x20=%d\r\n",
                    sp4.Data_0, sp4.wData_0x20);
            console_send_string(debug_string);
        }
#endif

        if (sp4.Data_0 & (1 << 6))
        {
            sub_2348dc9e();

            if (sp4.Data_0 & (1 << 1))
            {  
                channel_prev();
                //->loc_2345680c
            }
            //loc_23456802
            else if (sp4.Data_0 & (1 << 0))
            {
                channel_next();
            }
            //loc_2345680c
            osd_list_draw(Data_234ca55c, 1);
            //->loc_2345691e
        } //if (sp4.Data_0 & (1 << 6))
        else
        {
            //loc_23456816
            if (sp4.wData_0x20 != 0)
            {
                //0x23456820
                if (sp4.Data_0 & (1 << 1)) //0x02 (Down Key)
                {
                    //0x23456826
                    //sp4.Data_0x10[sp4.wData_0x1e + 1];
                    //->loc_23456848
                    menu_epg_update_date_text_field(sp4.Data_0x10[sp4.wData_0x1e + 1]);
                    //->loc_23456854 -> loc_2345691e
                }
                //loc_23456832
                else if (sp4.Data_0 & (1 << 0)) //0x01 (Up Key)
                {
                    //0x23456838
                    if (sp4.wData_0x1e == 0)
                    {
                        //0x23456842
                        menu_epg_update_date_text_field(sp4.Data_0x10[sp4.wData_0x20 - 1]);
                        //->loc_23456854 -> loc_2345691e
                    }
                    else
                    {
                        //loc_2345684c
                        menu_epg_update_date_text_field(sp4.Data_0x10[sp4.wData_0x1e - 1]);
                        //->loc_23456854 -> loc_2345691e
                    }
                }
                //loc_2345685c
                else if (sp4.Data_0 & (1 << 9)) //0x200 (Right key)
                {
                    //0x23456862
                    //sp4.bData_0x58;
                    //->loc_23456878
                    sub_2348dff2(r5, (int8_t) sp4.bData_0x58);
                    //0x2345687e
                    sp4 = *r5;

                    menu_epg_update_date_text_field(sp4.Data_0x10[sp4.wData_0x1e]);

                    rtos_task_wait(10);
                    //->loc_2345691e
                }
                //loc_2345686a
                else if (sp4.Data_0 & (1 << 10)) //0x400 (Left key)
                {
                    //0x23456870
                    //sp4.bData_0x58;
                    //->loc_23456878
                    sub_2348dff2(r5, (int8_t)  -sp4.bData_0x58);
                    //0x2345687e
                    sp4 = *r5;

                    menu_epg_update_date_text_field(sp4.Data_0x10[sp4.wData_0x1e]);

                    rtos_task_wait(10);
                    //->loc_2345691e
                }
                //loc_234568a2
                else if (sp4.Data_0 & (1 << 5)) //0x20 (OK Key)
                {
                    //0x234568a8
                    sub_2345636a(sp4.Data_0x10[sp4.wData_0x1e]);

                    void* r5 = sub_2343d572();

                    Data_234ca560->graphicData->pItems[0].height = 0x14C;
                    Data_234ca560->graphicData->pItems[1].height = 0x140;

                    Data_234ca560->graphicData->bData_0x19 = 0;
                    Data_234ca560->timeout = 0;
                    //->loc_234568e0
                    MENU_STACK_PUSH(Data_234ca560);
                    menu_initialize(Data_234ca560);
                    sub_2343d51e(Data_234ca560, r5);
                    //->loc_2345691e
                }
                //loc_234568f4
                else if (sp4.Data_0 & (1 << 7))
                {
                    //0x234568fa
                    if (((Data_2379a6d4.Data_0x10 << 26) >> 30) != 2)
                    {
                        //0x23456906
                        EIT_Event** r4 = &sp4.Data_0x10[sp4.wData_0x1e];
                        void* r0 = sub_2343d572();

                        sub_23459b66(r0, *r4, &Data_2379a6d4);
                    }
                    //loc_2345691e
                }
                //loc_2345691e
            } //if (sp4.wData_0x20 != 0)
            //loc_2345691e
        }
        //->loc_2345691e
        return 0;
    }
    else
    {
        //loc_234568de -> loc_23456924
        sub_234562ec();
        sub_234566a8();
        sub_23456302();
        //->loc_2345691e
    }
    //loc_2345691e
    return 0;
}


/* /  / 23456932 - todo */
int sub_23456932(Struct_2348dc50* a)
{
#if 0
	console_send_string("sub_23456932 (todo.c): TODO\r\n");
#endif

    uint16_t r7;
    Menu_Item* sp_0x70;
    EIT_Event** sp_0x6c;
    Struct_2348dc50 sp8 = *a;

    sp_0x70 = Data_234ca55c->Data_8;
    
    sp_0x6c = &sp8.Data_0x10[sp8.wData_0x1e - sp8.wCurrentItem];
    //->loc_23456a82
    for (r7 = 0; r7 < sp8.wData_0x26; r7++)
    {
        //loc_23456960
        char* r4 = sp_0x70->Data_4[0]->pText->pString;
        char* r5 = sp_0x70->Data_4[1]->pText->pString;

        sp_0x70->Data_4[0]->pText->bUpdate = 1;
        sp_0x70->Data_4[1]->pText->bUpdate = 1;

        uint16_t r6 = (sp8.wData_0x1e - sp8.wCurrentItem) + r7;

        if (sp8.wCurrentItem != r7)
        {
            //0x2345698e
            if (sp8.Data_0x54 != 0)
            {
                //0x23456994
                //r2 = 1;
                //->loc_234569ac
                sub_2348dba4(sp_0x70, r6, 1);
                //->loc_234569be
            }
            else
            {
                //loc_23456998
                //r1 = 1;
                //->loc_234569b8
                sub_2348db78(sp_0x70, 1);
                //loc_234569be
            }
        }
        else
        {
            //loc_2345699c
            if ((sp8.Data_0x54 != 0) &&
                //0x234569a2
                (((uint16_t*)(sp8.Data_0x54))[0] == (sp8.wData_0x1e + 1)))
            {
                //0x234569aa
                sub_2348dba4(sp_0x70, r6, 2);
                //->loc_234569be
            }
            else
            {
                //loc_234569b6
                sub_2348db78(sp_0x70, 2);
            }
        }
        //loc_234569be
        if (sp8.wData_0x20 > r6)
        {
            //0x234569c8
            if (r4 != 0)
            {
                //0x234569cc
                clocktime_get_event_time_string(
                    (*sp_0x6c)->start_time[0],
                    (*sp_0x6c)->start_time[1],
                    (*sp_0x6c)->duration[0],
                    (*sp_0x6c)->duration[1],
                    r4, 15);
            }
            //loc_234569e4
            if (r5 != 0)
            {
                memset(r5, 0, 40);

                struct Struct_2377b8d0_Inner8_Inner8* r0 = (*sp_0x6c)->Data_8;
                if (r0 != 0)
                {
                    //0x234569fa
                    struct Struct_2377b8d0_Inner8_Inner8_Inner0* r6 = r0->Data_0;
                    struct Struct_2377b8d0_Inner8_Inner8_Inner0* r4 = r6;
                    //->loc_23456a14
                    while (r4 != 0)
                    {
                        //loc_23456a00
                        if (0 != sub_2340beb0(r4->ISO_639_language_code, Data_2379a6d4.menuLanguage))
                        {
                            //0x23456a0e
                            r6 = r4;
                            //->loc_23456a18
                            break;
                        }
                        //loc_23456a12
                        r4 = r4->next;
                    } //while (r4 != 0)
                    //loc_23456a18
                    if ((r6 != 0) && (r6->strName != 0))
                    {
                        //0x23456a22
#if 0
                        {
                            extern char debug_string[];
                            sprintf(debug_string, "sub_23456932: r6->strName='%s'\r\n", 
                                r6->strName);
                            console_send_string(debug_string);
                        }
#endif
                        int r4 = 0;
                        if (Data_2379c08c.bData_4 != 0)
                        {
                            //0x23456a2c
                            if (0 == sub_2345a746(*sp_0x6c, &Data_2379c04c))
                            {
                                //0x23456a3c
                                r5[0] = 7;
                                r5[1] = ' ';
                                r5[2] = 0x59;
                                r5[3] = ' ';
                                r5[4] = 0;
                                r4 = 4;
                            }
                            //loc_23456a50
                        }
                        //loc_23456a50
                        char* r1 = r6->strName;

                        if (r1[0] == 0x10)
                        {
                            //0x23456a58
                            strncat(r5, &r1[3], 38 - r4);
                        }
                        else
                        {
                            //loc_23456a60
                            strncat(r5, &r1[0], 38 - r4);
                        }
#if 0
                        {
                            extern char debug_string[];
                            sprintf(debug_string, "sub_23456932: r5='%s'\r\n", r5);
                            console_send_string(debug_string);
                        }
#endif
                        //->loc_23456a72
                    } //if ((r6 != 0) && (r6->strName != 0))
                    //loc_23456a72
                } //if (r0 != 0)
                //loc_23456a72
            } //if (r5 != 0)
            //loc_23456a72
        } //if (sp8.wData_0x20 > r6)
        else
        {
            //loc_23456a6c
            *r4 = 0;
            *r5 = 0;
        }
        //loc_23456a72
        sp_0x6c++;
        sp_0x70++;
    }
    //loc_23456a8c
    menu_epg_update_date_text_field(sp8.Data_0x10[sp8.wData_0x1e]);

    return 0;
}


/* /  / 23456aa2 - todo */
int sub_23456aa2(void)
{
#if 0
	console_send_string("sub_23456aa2 (todo.c): TODO\r\n");
#endif

    uint16_t sp_0xd4; //sp_0xd4
    Struct_2348dc50 sp_0x70; //sp_0x70
    Struct_2340bf0c sp_0x3c;
    Struct_2340bf0c sp8;
    PSI_Program* sp4;
    uint16_t sp;

    Struct_2348dc50* r4 = 0;
    sp_0xd4 = 0;

    sub_2344ed14(0);

    sub_2340bf0c(&sp_0x3c);

    sub_2340bf94(sp_0x3c.wCurrentChannel, &Data_2379c04c, &Data_2379c074);

    if (Data_2379c04c.wTransponderIndex == 0xffff)
    {
        //0x23456ad2
        if (0 == psi_get_all_current_programs(main_hPSIDecoder1, &sp, &sp4))
        {
            Data_2379c074.transport_stream_id/*2379C084*/ = sp4->transport_stream_id;
        }
    }
    //loc_23456af2
    sub_23457200();
    sub_23456534();

    if (Data_2379c004.wData_2379c012 == 0)
    {
        sub_234565ba();
        sub_23456534();
    }
    //loc_23456b0c
    sp_0x70.pMenu = Data_234ca55c;
    sp_0x70.Data_0x10 = &Data_2379a704[0];
    sp_0x70.wData_0x1c = 4;
    sp_0x70.Data_0x54 = 0; //r4
    sp_0x70.Data_0x14 = sub_23456932;
    sp_0x70.Data_0x18 = sub_2348dbf8;
    sp_0x70.wData_0x1e = 0; //r4
    sp_0x70.wCurrentItem = 0; //r4
    sp_0x70.wData_0x20 = Data_2379c004.wData_2379c012;
    sp_0x70.wData_0x24 = 0; //r4
    sp_0x70.wData_0x26 = 10;
    sp_0x70.bData_0x58 = 10;
    sp_0x70.bData_0x5c = 7;
    sp_0x70.bData_0x5d = 8;
    sp_0x70.bData_0x5e = 9;
    sp_0x70.bData_0x59 = 2;
    sp_0x70.bData_0x5a = 10;
    sp_0x70.bData_0x5b = 9;

    r4 = osd_list_create(&sp_0x70);
    Data_2379c004.Data_2379c00c = r4;

    if (0 != sub_234564e0(&sp_0xd4))
    {
        //0x23456b62
        r4->arwData_0x28[0] = sp_0xd4 + 1;
        r4->Data_0x54 = &r4->arwData_0x28[0];
        r4->wData_0x1e = sp_0xd4;
        //->loc_23456b90
        r4->wCurrentItem = r4->wData_0x1e % r4->wData_0x26;
    }
    //loc_23456b98
    sub_2340bf0c(&sp8);

    strncpy(&Data_23799ce8[0], &sp8.Data_0.service_name[0], 38);

    Data_234ca55c->graphicData->pItems[2].pText->bUpdate = 1;

    menu_epg_update_clock_time_text_field();

    return 0;
}


/* /  / 23456bc0 - todo */
int sub_23456bc0(void)
{
#if 0
	console_send_string("sub_23456bc0 (todo.c): TODO\r\n");
#endif

    sub_2348dc9e();
    sub_2344ed14(1);

    return 0;
}


/* /  / 23456bd0 */
void sub_23456bd0(void)
{
#if 1
	console_send_string("sub_23456bd0 (todo.c): TODO\r\n");
#endif

}


/* /  / 23456db4 - todo */
static void* sub_23456db4(FrontDisplay_Job* r5)
{
#if 0
	console_send_string("sub_23456db4 (todo.c): TODO\r\n");
#endif

    Struct_2348dc50* r0__ = sub_2348dcd2();
    Menu* r0 = r0__->pMenu;
    int r6 = 0;

    if (r0 == 0)
    {
        Data_234ca564 = 0; //r6
        //->loc_23456de4
        return sub_2344d0d0;
    }
    //loc_23456dca
    if (r0->graphicData->wData_2 == 21)
    {
        //->loc_23456ecc
        return sub_23456db4;
    }
    //0x23456dd2
    if (Data_234ca564 != r0)
    {
        if (Data_234ca564 != 0)
        {
            //loc_23456de4
            return sub_2344d0d0;
        }
        //loc_23456de8
        Data_234ca564 = r0;

        if ((r0->header != 0) && (r0->header->pText != 0))
        {
            //0x23456df6
            r5->bData_8[0] = 0x22;

            text_table_get_string(0x15/*'Vorschau'*/, &r5->bData_8[1], 9);

            uint8_t len = strlen(&r5->bData_8[0]);

            r5->bData_8[len] = 0x22;
            len++;
            r5->bData_8[len] = 0; //r6

            r5->bNumTextChars = strlen(&r5->bData_8[0]);
            r5->bDisplayOffset = 0;
            r5->bNumDisplayChars = 12;
            r5->bData_0x10b = 0;
            r5->bData_0x10c = 0;
            r5->bData_0x110 = 0;
            r5->holdTime = 20;
            r5->Data_0 = frontdisplay_draw_text;
            r5->Data_4 = 0;
            r5->bData_0x10f = 0;
            //->loc_23456ecc
            return sub_23456db4;
        }
        //loc_23456e3a
    }
    //loc_23456e3a
    r5->bData_8[0] = 0; //r6

    if ((r0->Data_4 != 0) && 
        (r0->Data_4->Data_4[1] != 0) && (r0->Data_4->Data_4[1]->pText != 0))
    {
        int r0_ = 0;
        //0x23456e50
        char* r1 = r0->Data_4->Data_4[1]->pText->pString;
        if (r1[0] == 7)
        {
            char r2 = r1[2];
            r1 += 3;
            if (r2 == 0x59)
            {
                r5->bData_8[0] = 0x1b;
                r0_ = 1;                
            }
        }
        //loc_23456e66
        if ((*r1 != 0) &&
            ((*r1 >= 0x21) || (*++r1 != 0)) &&
            ((*r1 >= 0x20) || (*++r1 != 0)))
        {
            //loc_23456e86
            strncpy(&r5->bData_8[r0_], r1, 0xfd);
            //->loc_23456e9e
        }
        else
        {
            //loc_23456e92
            text_table_get_string(0x28/*'keine Senderinformation'*/, &r5->bData_8[r0_], 0xfd);
        }
        //loc_23456e9e
        r5->bData_8[0xff] = 0;

        r5->bNumTextChars = strlen(&r5->bData_8[0]);
        r5->bDisplayOffset = 0;
        r5->bNumDisplayChars = 12;
        r5->bData_0x10b = 0;
        r5->bData_0x10c = 0;
        r5->bData_0x110 = 0;
        r5->holdTime = 0;
        r5->bData_0x10f = 0;
        r5->Data_4 = 0;
        r5->Data_0 = frontdisplay_draw_text;

        if (r5->bNumTextChars > 12)
        {
            r5->bData_0x10c = 1;
            r5->Data_0 = frontdisplay_draw_scroll_text;
        }
    }
    //loc_23456ecc
    return sub_23456db4;
}


/* /  / 23456ed0 - todo */
int sub_23456ed0(UI_Thread_Params* r5)
{
#if 0
	console_send_string("sub_23456ed0 (todo.c): TODO\r\n");
#endif

    channel_handle_user_settings(1, &Data_2379a6d4);

    sub_2343d458(r5);

    MENU_STACK_PUSH(Data_234ca55c);
    osd_list_draw(Data_234ca55c, 1);
    sub_2343d51e(Data_234ca55c, r5);

    frontdisplay_start_text(sub_23456db4);

    return 0;
}


/* /  / 23456fd8 - todo */
uint8_t sub_23456fd8(uint8_t bData)
{
#if 0
	console_send_string("sub_23456fd8 (todo.c): TODO\r\n");
#endif

    return ((bData >> 4) * 10) + (bData & 0x0f);
}


/* /  / 23456fe8 - todo */
int16_t sub_23456fe8(uint8_t* r5)
{
#if 0
	console_send_string("sub_23456fe8 (todo.c): TODO\r\n");
#endif

    uint16_t r4 = 0;

    *r5 = 0; //r4

    EIT_EventList* pEventList = 
        eit_get_section_data(Data_2379c04c.service_id, Data_2379c074.transport_stream_id);
    
    if (pEventList == 0)
    {
        return 0;
    }

    EIT_Event* pEvent = pEventList->pEventFirst;
    //r1 = 0x2379c004;
    //int r3 = 1;
    //->loc_2345702e
    while (pEvent != 0)
    {
        //loc_2345700a
        if (pEvent->table_id == 0x4e)
        {
            //0x23457010
            r4++;

            if ((pEvent->running_status == 4) && 
                (Data_2379c004.Data_2379c004 != 0) &&
                (pEvent->event_id != Data_2379c004.wData_2379c014))
            {
                *r5 = 1; //r3
            }
        }
        //loc_2345702c
        pEvent = pEvent->next;
        //loc_2345702e
    } //while (pEvent != 0)

    return r4;
}


/* /  / 2345703c - todo */
int16_t sub_2345703c(uint8_t* r7)
{
#if 0
	console_send_string("sub_2345703c (todo.c): TODO\r\n");
#endif

    Clock_Time sp_0x20;
    uint16_t sp_0x1c;
    uint16_t sp_0x18;
    EIT_Event* pEvent;
    uint16_t r5 = 0;

    *r7 = 0;

    EIT_EventList* pEventList = 
        eit_get_section_data(Data_2379c04c.service_id, Data_2379c074.transport_stream_id);
    
    if (pEventList == 0)
    {
        return 0;
    }

    clocktime_get(&sp_0x20);

    pEvent = pEventList->pEventFirst;

    uint32_t r6;
    if (sp_0x20.bData_4 == 0)
    {
        r6 = 0;
    }
    else
    {
        r6 = (sp_0x20.mjd << 16) | (sp_0x20.hours << 8) | (sp_0x20.minutes);
    }
    //->loc_234571e8
    while (pEvent != 0)
    {
        //loc_234570a4
        if (pEvent->table_id != 0x4e)
        {
            //0x234570b0
            sub_234128f4(pEvent->start_time[0], pEvent->start_time[1],
                pEvent->duration[0], pEvent->duration[1],
                0, 0, &sp_0x1c, &sp_0x18, 0);

            uint32_t r0 = pEvent->wData_0x16;

            uint8_t h = ((pEvent->start_time[0] & 0xf0) >> 4) * 10.0;
            h = h + (double)(pEvent->start_time[0] & 0x0f);

            uint8_t m = ((pEvent->start_time[1] & 0xf0) >> 4) * 10.0;
            m = m + (double)(pEvent->start_time[1] & 0x0f);

            uint32_t r3 = (h << 8) | m;
            uint32_t ip = (sp_0x1c << 8) | sp_0x18;

            if (r3 > ip)
            {
                r0++;
            }

            r0 = (r0 << 16) | (sp_0x1c << 8) | sp_0x18;

            if (r0 > r6)
            {
                r5++;
            }
            //->loc_234571e4
        }
        else
        {
            //loc_234571b4
            if ((pEvent->running_status == 4) &&
                (Data_2379c004.Data_2379c004 != 0) &&
                (pEvent->event_id != Data_2379c004.wData_2379c014))
            {
                *r7 = 1;
            }
        }
        //loc_234571e4
        pEvent = pEvent->next;
        //loc_234571e8
    } //while (pEvent != 0)

    return r5;
}


/* /  / 23457200 */
int sub_23457200(void)
{
#if 0
	console_send_string("sub_23457200 (todo.c): TODO\r\n");
#endif

    Clock_Time sp_0x1c; //sp_0x1c
    uint16_t sp_0x18; //sp_0x18
    uint16_t sp_0x14; //sp_0x14
    EIT_Event* r4 = 0;
    EIT_Event** r6;

    Data_2379c004.wData_2379c012 = 0; //r4
    Data_2379c004.wData_2379c014 = 0; //r4

    Data_2379c004.Data_2379c008 = 
        eit_get_section_data(Data_2379c04c.service_id, Data_2379c074.transport_stream_id);

    clocktime_get(&sp_0x1c);

    uint32_t r8;
    if (sp_0x1c.bData_4 == 0)
    {
        r8 = 0;
    }
    else
    {
        r8 = (sp_0x1c.mjd << 16) | (sp_0x1c.hours << 8) | (sp_0x1c.minutes);
    }

    if (Data_2379c004.Data_2379c008 != 0)
    {
        r6 = &Data_2379a704[0];
        r4 = Data_2379c004.Data_2379c008->pEventFirst;
        //->loc_234573d8 
    }
    else
    {
        //0x23457278
        Data_2379c004.wData_2379c012 = 0; //r4

        return 2;
    }
    //loc_234573d8
    while (r4 != 0)
    {
        //->loc_2345728c
        if (r4->table_id != 0x4e)
        {
            //0x23457298
            if (Data_2379c004.wData_2379c012 >= 1599)
            {
                return 1;
            }
            //0x234572ac
            sub_234128f4(r4->start_time[0], r4->start_time[1], 
                r4->duration[0], r4->duration[1], 0, 0, &sp_0x18, &sp_0x14, 0);

            uint8_t r2 = ((r4->start_time[0] & 0xf0) >> 4) * 10.0;
            r2 += (double)(r4->start_time[0] & 0x0f);

            uint8_t r1 = ((r4->start_time[1] & 0xf0) >> 4) * 10.0;
            r1 += (double)(r4->start_time[1] & 0x0f);

            uint32_t r0 = r4->wData_0x16;

            if (((r2 << 8) | r1) > ((sp_0x18 << 8) | sp_0x14))
            {
                r0++;
            }

#if 0
            {
                extern char debug_string[];
                sprintf(debug_string, "sub_23457200: %08x, %08x\r\n",
                        ((r0 << 16) | (r2 << 8) | r1), r8);
                console_send_string(debug_string);
            }
#endif

            if (((r0 << 16) | (r2 << 8) | r1) > r8)
            {
                *r6++ = r4;
                Data_2379c004.wData_2379c012++;
            }
            //->loc_234573d4
        } //if (r4->table_id != 0x4e)
        else
        {
            //loc_234573b8
            if (r4->running_status == 4)
            {
                if (Data_2379c004.wData_2379c014 == 0)
                {
                    Data_2379c004.wData_2379c014 = r4->event_id;
                    Data_2379c004.Data_2379c004 = r4;
                }
            }
        }
        //loc_234573d4
        r4 = r4->next;
    } //while (r4 != 0)
    //0x234573e0
#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "sub_23457200: Data_2379c004.wData_2379c012=%d\r\n",
                Data_2379c004.wData_2379c012);
        console_send_string(debug_string);
    }
#endif
    return 0;
}





#endif //!VDR110
