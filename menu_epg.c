
#ifndef VDR110

#include "data.h"
#include "frontdisplay.h"
#include "texttable.h"
#include "graphic.h"
#include "menu.h"
#include "menu_info_bar.h"
#include "clocktime.h"
#include "eit.h"

#pragma thumb

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern void* Data_234c1258; //234c1258
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12f8; //234c12f8
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c134c; //234c134c
extern void* sub_2344d0d0(FrontDisplay_Job*);
extern void sub_2344f102(UI_Thread_Params*);
extern void sub_2348dbf8(void);
extern  int sub_2348de88(int*a);
static Menu Data_234cc1b4;
static int sub_234562ec(void);
static void sub_23456302(void);
static int sub_234567d8(Struct_2348dc50*);
static int sub_23456aa2(void);
static int sub_23456bc0(void);

static uint8_t Data_23799ce8[]; //23799ce8
static uint8_t Data_2379c098[]; //2379c098
static uint8_t Data_2379c2d4[]; //2379c2d4

//0x234ca54c
static Menu* Data_234ca55c = &Data_234cc1b4; //234ca55c +0x10
static Menu* Data_234ca564 = 0; //234CA564 +0x18

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
    {1, 0, 0, 0/*Data_8*/, 0x003d, 0x0029, 0x00a2, 0x0026, 0, &Data_234c134c/*Data_0x18*/, 2, 0, &Data_234ca580/*Data_0x20*/}, //[2] = 234CA8DC: header
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
    {1, 0, 0, 0/*Data_8*/, 0x003d, 0x0060, 0x00a0, 0x0020, 0, &Data_234c12f8/*Data_0x18*/, 2, 0, &Data_234ca5e0/*Data_0x20*/}, //[6] = 234CA9DC
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
    {0}, //[16] = 234CAC5C
    {0}, //[17] = 234CAC9C
    {0}, //[18] = 234CACDC
    {0}, //[19] = 234CAD1C
    {0}, //[20] = 234CAD5C
    {0}, //[21] = 234CAD9C
    {0}, //[22] = 234CADDC
    {0}, //[23] = 234CAE1C
    {0}, //[24] = 234CAE5C
    {0}, //[25] = 234CAE9C
    {0}, //[26] = 234CAEDC
    {0}, //[27] = 234CAF1C
    {0}, //[28] = 234CAF5C
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


uint8_t Data_23799ce8[100]; //23799ce8, size???
User_Settings Data_2379a6d4; //2379a6d4
EIT_Event* Data_2379a704[1600]; //2379a704 -> 2379C004
struct 
{
    EIT_Event* Data_2379c004; //2379c004
    EIT_EventList* Data_2379c008; //2379c008
    Struct_2348dc50* Data_2379c00c; //2379c00c
    uint16_t fill_2379c010; //2379c010
    uint16_t wData_2379c012; //2379c012
    uint16_t wData_2379c014; //2379c014

} Data_2379c004; //2379c004
Channel Data_2379c04c; //2379c04c
Transponder Data_2379c074; //2379c074
uint8_t Data_2379c098[100]; //2379c098, size???
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

    	console_send_string("sub_234567d8 (0x234567e0): TODO\r\n");
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
void sub_23456932(void)
{
#if 1
	console_send_string("sub_23456932 (todo.c): TODO\r\n");
#endif

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

    sub_234764fc(0);

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
    sp_0x70.Data_4 = Data_234ca55c;
    sp_0x70.Data_0x10 = &Data_2379a704[0];
    sp_0x70.wData_0x1c = 4;
    sp_0x70.Data_0x54 = 0; //r4
    sp_0x70.Data_0x14 = sub_23456932;
    sp_0x70.Data_0x18 = sub_2348dbf8;
    sp_0x70.wData_0x1e = 0; //r4
    sp_0x70.wData_0x22 = 0; //r4
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

    r4 = sub_2348dc50(&sp_0x70);
    Data_2379c004.Data_2379c00c = r4;

    if (0 != sub_234564e0(&sp_0xd4))
    {
        //0x23456b62
        r4->arwData_0x28[0] = sp_0xd4 + 1;
        r4->Data_0x54 = &r4->arwData_0x28[0];
        r4->wData_0x1e = sp_0xd4;
        //->loc_23456b90
        r4->wData_0x22 = r4->wData_0x1e % r4->wData_0x26;
    }
    //loc_23456b98
    sub_2340bf0c(&sp8);

    strncpy(&Data_23799ce8[0], &sp8.Data_0.service_name[0], 38);

    Data_234ca55c->graphicData->pItems[2].Data_0x20->bData_0x17 = 1;

    sub_2345630e();

    return 0;
}


/* /  / 23456bc0 - todo */
int sub_23456bc0(void)
{
#if 0
	console_send_string("sub_23456bc0 (todo.c): TODO\r\n");
#endif

    sub_2348dc9e();
    sub_234764fc(1);

    return 0;
}


/* /  / 23456db4 - todo */
static void* sub_23456db4(FrontDisplay_Job* r5)
{
#if 0
	console_send_string("sub_23456db4 (todo.c): TODO\r\n");
#endif

    Struct_2348dc50* r0__ = sub_2348dcd2();
    Menu* r0 = r0__->Data_4;
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

        if ((r0->header != 0) && (r0->header->Data_0x20 != 0))
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
        (r0->Data_4->Data_4[1] != 0) && (r0->Data_4->Data_4[1]->Data_0x20 != 0))
    {
        int r0_ = 0;
        //0x23456e50
        char* r1 = r0->Data_4->Data_4[1]->Data_0x20->Data_0x10;
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
    sub_2348dd36(Data_234ca55c, 1);
    sub_2343d51e(Data_234ca55c, r5);

    frontdisplay_start_text(sub_23456db4);

    return 0;
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
            sub_234128f4/*sub_2341a308*/(r4->start_time[0], r4->start_time[1], 
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
    return 0;
}





#endif //!VDR110
