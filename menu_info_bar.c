
#ifndef VDR110

#include "data.h"
#include "frontdisplay.h"
#include "texttable.h"
#include "graphic.h"
#include "menu.h"
#include "eit.h"
#include "clocktime.h"
#include "menu_info_bar.h"

#pragma thumb

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern void* Data_234c1258; //234c1258
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c128c; //234c128c
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12ec; //234c12ec

static Graphic_Job_2_5_Item Data_234e0620[]; //234e0620
static Menu Data_234e1c78;
static Menu Data_234e1cf0;
static uint8_t Data_2396b944[]; //2396b944
static uint8_t Data_2396b950[]; //2396b950
static uint8_t Data_2396c964[]; //2396c964
static uint8_t Data_2396c978[]; //2396c978
static uint8_t Data_2396c98c[]; //2396c98c
static uint8_t Data_2396c9a0[]; //2396c9a0

static int sub_2348c9e0(void);
static int sub_2348c8b4(void);
static void sub_2348c8c8(void);
static int sub_2348cbc8(void);
static int sub_2348cecc(void);
static int sub_2348d3f6(Menu_Event*);
static void sub_2348db56(Menu_Item*, uint16_t, uint8_t, uint8_t);
/*static*/ int sub_2348db78(Menu_Item*, int);
/*static*/ void sub_2348dcd8(int);
/*static*/ int sub_2348de88(int*a);


//234dfe48
uint8_t bData_234dfe48 = 0; //234dfe48 +0
uint8_t Data_234dfe4c[] = " "; //234dfe4c +4
uint16_t wData_234dfe4e = 0; //234dfe4e +6
int (*Data_234dfe50)() = 0; //234DFE50 +8
Menu* Data_234dfe54 = //234dfe54 +0xc
    &Data_234e1c78;

Menu* Data_234dfe58 = //234dfe58 +0x10
    &Data_234e1cf0; 
uint8_t menu_info_bar_time_string[] = "--:--  "; //234DFE5C +0x14

uint8_t bData_234dfe64 = 0; //234DFE64

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dfe74 = //234dfe74
{
	14, //uint16_t wData_0; //0
	4, //int Data_4; //4
	0x0b, //uint8_t bData_8; //8
#if 0
0x234dfe74                        dw         0x000e                             ; DATA XREF=sub_2348d81e+4, 0x234e0638
0x234dfe76 0000                   movs       r0, r0
0x234dfe78                        dd         0x00000004
0x234dfe7c                        db         0x0b
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dfe80 = //234dfe80
{
	9, //uint16_t wData_0; //0
	4, //int Data_4; //4
	0x0a, //uint8_t bData_8; //8
#if 0
0x234dfe80                        dw         0x0009                             ; DATA XREF=sub_2348d81e+18, 0x234e06b8
0x234dfe82 0000                   movs       r0, r0
0x234dfe84                        dd         0x00000004
0x234dfe88                        db         0x0a
0x234dfe89                        db  0x00 ; '.'
0x234dfe8a                        db  0x00 ; '.'
0x234dfe8b                        db  0x00 ; '.'
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dfe8c = //234dfe8c
{
	9, //uint16_t wData_0; //0
	4, //int Data_4; //4
	0x01, //uint8_t bData_8; //8
#if 0
0x234dfe8c                        dw         0x0009                             ; DATA XREF=sub_2348d81e+20, 0x234e06f8
0x234dfe8e                        dw         0x0000
0x234dfe90                        dd         0x00000004
0x234dfe94                        db         0x01
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dfe98 = //234dfe98
{
	9, //uint16_t wData_0; //0
	4, //int Data_4; //4
	0x0d, //uint8_t bData_8; //8
#if 0
0x234dfe98                        dw         0x0009                             ; DATA XREF=sub_2348d81e+22, 0x234e0738
0x234dfe9a                        dw         0x0000
0x234dfe9c                        dd         0x00000004
0x234dfea0                        db         0x0d
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dfea4 = //234dfea4
{
	9, //uint16_t wData_0; //0
	4, //int Data_4; //4
	0x07, //uint8_t bData_8; //8
#if 0
0x234dfea4                        dw         0x0009                             ; DATA XREF=sub_2348d81e+24, 0x234e0778
0x234dfea6 0000                   movs       r0, r0
0x234dfea8                        dd         0x00000004
0x234dfeac                        db         0x07
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dfebc = //234dfebc
{
	14, //uint16_t wData_0; //0
	4, //int Data_4; //4
	0x04, //uint8_t bData_8; //8
#if 0
0x234dfebc                        dw         0x000e                             ; DATA XREF=sub_2348d81e+28, 0x234e0678
0x234dfebe 0000                   movs       r0, r0
0x234dfec0                        dd         0x00000004
0x234dfec4                        db         0x04
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dfed4 = //234dfed4
{
	4, //uint16_t wData_0; //0
	4, //int Data_4; //4
	0x0a, //uint8_t bData_8; //8
#if 0
0x234dfed4                        dw         0x0004                             ; DATA XREF=sub_2348d81e+60, 0x234e0ab8
0x234dfed6 0000                   movs       r0, r0
0x234dfed8                        dd         0x00000004                         ; DATA XREF=sub_2348d81e+62
0x234dfedc                        db         0x0a
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dfee0 = //234dfee0
{
	14, //uint16_t wData_0; //0
	0, //int Data_4; //4
	0x0d, //uint8_t bData_8; //8
#if 0
0x234dfee0                        dw         0x000e                             ; DATA XREF=sub_2348c8d4+184, sub_2348ca2a+298, dword_234e0838, dword_234e0bf8
0x234dfee2 0000                   movs       r0, r0
0x234dfee4                        dd         0x00000000
0x234dfee8                        db         0x0d
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dfeec = //234dfeec
{
	14, //uint16_t wData_0; //0
	4, //int Data_4; //4
	0x0f, //uint8_t bData_8; //8
#if 0
0x234dfeec                        dw         0x000e                             ; DATA XREF=sub_2348d81e+64, 0x234e07b8
0x234dfeee 0000                   movs       r0, r0
0x234dfef0                        dd         0x00000004                         ; DATA XREF=sub_2348d81e+66
0x234dfef4                        db         0x0f
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dfef8 = //234dfef8
{
	14, //uint16_t wData_0; //0
	4, //int Data_4; //4
	0x03, //uint8_t bData_8; //8
#if 0
0x234dfef8                        dw         0x000e                             ; DATA XREF=sub_2348d81e+68, 0x234e0af8
0x234dfefa 0000                   movs       r0, r0
0x234dfefc                        dd         0x00000004                         ; DATA XREF=sub_2348d81e+70
0x234dff00                        db         0x03
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dff04 = //234dff04
{
	9, //uint16_t wData_0; //0
	4, //int Data_4; //4
	0x07, //uint8_t bData_8; //8
#if 0
0x234dff04                        dw         0x0009                             ; DATA XREF=sub_2348d81e+72, 0x234e0b38
0x234dff06 0000                   movs       r0, r0
0x234dff08                        dd         0x00000004                         ; DATA XREF=sub_2348d81e+74
0x234dff0c                        db         0x07
#endif
};

static Graphic_Job_2_5_Item_Text Data_234dff34 = //234dff34: Channel Number
{
	0, 0x004f, 0x0148, 0x0090, 0x016d, 0x01, 0x04, 0x03, 0x00, &Data_2396b944[0], 0, 0, 0
#if 0
0x234dff34                        db         0x00                               ; DATA XREF=sub_2348cc10+26, sub_2348d7ee+22, dword_234e06c0
0x234dff35                        db  0x00 ; '.'
0x234dff36                        dw         0x004f
0x234dff38                        dw         0x0148
0x234dff3a                        dw         0x0090
0x234dff3c                        dw         0x016d
0x234dff3e                        db         0x01
0x234dff3f                        db         0x04
0x234dff40                        db         0x03
0x234dff41                        db         0x00
0x234dff42 0000                   movs       r0, r0
0x234dff44                        dd         0x2396b944
0x234dff48                        dw         0x0000
0x234dff4a                        db  0x00 ; '.'
0x234dff4b                        db         0x00
#endif
};

static Graphic_Job_2_5_Item_Text Data_234dff4c = //234dff4c: Channel Name
{
	0, 0x0099, 0x0148, 0x01d5, 0x016d, 0x01, 0x04, 0x08, 0x00, &Data_2396b950[0], 0, 0, 0
#if 0
0x234dff4c                        db         0x00                               ; DATA XREF=sub_2348cc10+36, sub_2348d7ee+40, dword_2348d908, dword_234e0700
0x234dff4d                        db         0x00
0x234dff4e                        dw         0x0099
0x234dff50                        dw         0x0148                             ; DATA XREF=sub_2348d7ee+44
0x234dff52                        dw         0x01d5                             ; CODE XREF=dword_234e0194+116
0x234dff54                        dw         0x016d
0x234dff56                        db         0x01
0x234dff57                        db         0x04
0x234dff58                        db         0x08
0x234dff59                        db         0x00
0x234dff5a 0000                   movs       r0, r0
0x234dff5c                        dd         0x2396b950
0x234dff60                        dw         0x0000
0x234dff62                        db  0x00 ; '.'
                              byte_234dff63:
0x234dff63                        db         0x00
#endif
};

static uint8_t Data_234dff64[0x200] = " "; //234dff64, size???

static Graphic_Job_2_5_Item_Text Data_234e0164 = //234e0164
{
	0, 0x0099, 0x0175, 0x028a, 0x01b8, 0x01, 0x05, 0x03, 0x01, &Data_234dff64[0], 0, 0, 0
#if 0
0x234e0164                        db         0x00                               ; DATA XREF=sub_2348d06a+118, 0x234e0740
0x234e0165                        db         0x00
0x234e0166                        dw         0x0099                             ; DATA XREF=sub_2348d06a+128
0x234e0168                        dw         0x0175                             ; DATA XREF=sub_2348d06a+122
0x234e016a                        dw         0x028a                             ; DATA XREF=sub_2348d06a+120
0x234e016c                        dw         0x01b8
0x234e016e                        db         0x01
0x234e016f                        db         0x05
0x234e0170                        db         0x03
0x234e0171                        db         0x01                               ; DATA XREF=sub_2348d06a+130
0x234e0172 0000                   movs       r0, r0
0x234e0174                        dd         0x234dff64
0x234e0178                        dw         0x0000
0x234e017a                        db  0x00 ; '.'
0x234e017b                        db         0x00
#endif
};

uint8_t Data_234e017c[20] = "\x07 ] \x07 \ "; //234e017c
static Menu_Item Data_234e0190[] = //234e0190
{
    //[0]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[8], /*234e0820*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e0190                        dw         0xffff                             ; DATA XREF=sub_2348ca2a+360, sub_2348cc10+158, dword_2348cce4, 0x234e1c7c, 0x234e1c80
0x234e0192                        dw         0xffff
0x234e0194                        dd         0x234e0820                         ; DATA XREF=sub_2348ca2a+370
0x234e0198                        dd         0x00000000
0x234e019c                        dd         0x00000000
0x234e01a0                        dd         0x00000000
0x234e01a4                        dd         0x00000000
0x234e01a8                        dd         0x00000000
0x234e01ac                        dd         sub_2348d3f6+1
0x234e01b0                        dd         mainfunction_thread+1
0x234e01b4                        dd         0x00000000
0x234e01b8                        dd         0x00000000    
#endif
    }, 
    //[1]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[9], /*234e0860*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e01bc                        dw         0xffff                             ; DATA XREF=sub_2348ca2a+366
0x234e01be                        dw         0xffff
0x234e01c0                        dd         0x234e0860
0x234e01c4                        dd         0x00000000
0x234e01c8                        dd         0x00000000
0x234e01cc                        dd         0x00000000
0x234e01d0                        dd         0x00000000
0x234e01d4                        dd         0x00000000
0x234e01d8                        dd         sub_2348d3f6+1
0x234e01dc                        dd         mainfunction_thread+1
0x234e01e0                        dd         0x00000000
0x234e01e4                        dd         0x00000000
#endif
    }, 
    //[2]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[10], /*234e08a0*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e01e8                        dw         0xffff
0x234e01ea                        dw         0xffff
0x234e01ec                        dd         0x234e08a0
0x234e01f0                        dd         0x00000000
0x234e01f4                        dd         0x00000000
0x234e01f8                        dd         0x00000000
0x234e01fc                        dd         0x00000000
0x234e0200                        dd         0x00000000
0x234e0204                        dd         sub_2348d3f6+1
0x234e0208                        dd         mainfunction_thread+1
0x234e020c                        dd         0x00000000
0x234e0210                        dd         0x00000000
#endif
    }, 
    //[3]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[11], /*234e08e0*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e0214                        dw         0xffff
0x234e0216                        dw         0xffff
0x234e0218                        dd         0x234e08e0
0x234e021c                        dd         0x00000000
0x234e0220                        dd         0x00000000
0x234e0224                        dd         0x00000000
0x234e0228                        dd         0x00000000
0x234e022c                        dd         0x00000000
0x234e0230                        dd         sub_2348d3f6+1
0x234e0234                        dd         mainfunction_thread+1
0x234e0238                        dd         0x00000000
0x234e023c                        dd         0x00000000
#endif
    }, 
    //[4]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[12], /*234e0920*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e0240                        dw         0xffff
0x234e0242                        dw         0xffff
0x234e0244                        dd         0x234e0920
0x234e0248                        dd         0x00000000
0x234e024c                        dd         0x00000000
0x234e0250                        dd         0x00000000
0x234e0254                        dd         0x00000000
0x234e0258                        dd         0x00000000
0x234e025c                        dd         sub_2348d3f6+1
0x234e0260                        dd         mainfunction_thread+1
0x234e0264                        dd         0x00000000
0x234e0268                        dd         0x00000000
#endif
    }, 
    //[5]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[13], /*234e0960*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e026c                        dw         0xffff
0x234e026e                        dw         0xffff
0x234e0270                        dd         0x234e0960
0x234e0274                        dd         0x00000000
0x234e0278                        dd         0x00000000
0x234e027c                        dd         0x00000000
0x234e0280                        dd         0x00000000
0x234e0284                        dd         0x00000000                         ; DATA XREF=sub_2348c8d4+256
0x234e0288                        dd         sub_2348d3f6+1
0x234e028c                        dd         mainfunction_thread+1
0x234e0290                        dd         0x00000000
0x234e0294                        dd         0x00000000
#endif
    }, 
};

static Menu_Item Data_234e0298[] = //234e0298
{
    //[0]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[23], /*234e0be0*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e0298                        dw         0xffff                             ; DATA XREF=sub_2348c8d4+94, sub_2348c8d4+108, sub_2348c8d4+120, sub_2348c8d4+248, dword_2348ccc0, 0x234e1cf4, 0x234e1cf8
0x234e029a                        dw         0xffff
0x234e029c                        dd         0x234e0be0                         ; DATA XREF=sub_2348c8d4+96, sub_2348c8d4+258
0x234e02a0                        dd         0x00000000
0x234e02a4                        dd         0x00000000
0x234e02a8                        dd         0x00000000
0x234e02ac                        dd         0x00000000
0x234e02b0 0000                   movs       r0, r0
0x234e02b2 0000                   movs       r0, r0                             ; CODE XREF=menu_settings_items+560
0x234e02b4                        dd         sub_2348d3f6+1
0x234e02b8                        dd         mainfunction_thread+1
0x234e02bc 0000                   movs       r0, r0
0x234e02be 0000                   movs       r0, r0
0x234e02c0 0000                   movs       r0, r0
0x234e02c2 0000                   movs       r0, r0
#endif
    }, 
    //[1]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[24], /*234e0c20*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e02c4                        dw         0xffff                             ; DATA XREF=sub_2348c8d4+254
0x234e02c6                        dw         0xffff
                              dword_234e02c8:
0x234e02c8                        dd         0x234e0c20                         ; DATA XREF=sub_2348c8d4+100
0x234e02cc                        dd         0x00000000
0x234e02d0                        dd         0x00000000
0x234e02d4                        dd         0x00000000
0x234e02d8                        dd         0x00000000
0x234e02dc                        dd         0x00000000
0x234e02e0                        dd         sub_2348d3f6+1
0x234e02e4                        dd         mainfunction_thread+1
0x234e02e8 0000                   movs       r0, r0
0x234e02ea 0000                   movs       r0, r0
0x234e02ec 0000                   movs       r0, r0
0x234e02ee 0000                   movs       r0, r0
#endif
    }, 
    //[2]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[25], /*234e0c60*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e02f0                        dw         0xffff
0x234e02f2                        dw         0xffff
                              dword_234e02f4:
0x234e02f4                        dd         0x234e0c60                         ; DATA XREF=sub_2348c8d4+104
0x234e02f8                        dd         0x00000000
0x234e02fc                        dd         0x00000000
0x234e0300                        dd         0x00000000
0x234e0304                        dd         0x00000000
0x234e0308                        dd         0x00000000
0x234e030c                        dd         sub_2348d3f6+1
0x234e0310                        dd         mainfunction_thread+1
0x234e0314                        db  0x00 ; '.'
0x234e0315                        db  0x00 ; '.'
0x234e0316                        db  0x00 ; '.'
0x234e0317                        db  0x00 ; '.'
0x234e0318                        db  0x00 ; '.'                                ; DATA XREF=sub_2348c8d4+110
0x234e0319                        db  0x00 ; '.'
0x234e031a 0000                   movs       r0, r0
#endif
    }, 
    //[3]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[26], /*234e0ca0*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e031c                        dw         0xffff
0x234e031e                        dw         0xffff
                              dword_234e0320:
0x234e0320                        dd         0x234e0ca0                         ; DATA XREF=sub_2348c8d4+112
0x234e0324                        dd         0x00000000
0x234e0328                        dd         0x00000000
0x234e032c                        dd         0x00000000
0x234e0330                        dd         0x00000000
0x234e0334                        dd         0x00000000
0x234e0338                        dd         sub_2348d3f6+1
0x234e033c                        dd         mainfunction_thread+1
0x234e0340 0000                   movs       r0, r0
0x234e0342 0000                   movs       r0, r0
0x234e0344 0000                   movs       r0, r0
0x234e0346 0000                   movs       r0, r0
#endif
    }, 
    //[4]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[27], /*234e0ce0*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e0348                        dw         0xffff
0x234e034a                        dw         0xffff
                              dword_234e034c:
0x234e034c                        dd         0x234e0ce0                         ; DATA XREF=sub_2348c8d4+116
0x234e0350                        dd         0x00000000
0x234e0354                        dd         0x00000000
0x234e0358                        dd         0x00000000                         ; DATA XREF=sub_2348c8d4+122
0x234e035c                        dd         0x00000000
0x234e0360                        dd         0x00000000
0x234e0364                        dd         sub_2348d3f6+1
0x234e0368                        dd         mainfunction_thread+1
0x234e036c 0000                   movs       r0, r0
0x234e036e 0000                   movs       r0, r0
0x234e0370 0000                   movs       r0, r0
0x234e0372 0000                   movs       r0, r0
#endif
    }, 
    //[5]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[28], /*234e0d20*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e0374                        dw         0xffff
0x234e0376                        dw         0xffff
                              dword_234e0378:
0x234e0378                        dd         0x234e0d20                         ; DATA XREF=sub_2348c8d4+124
0x234e037c                        dd         0x00000000
0x234e0380                        dd         0x00000000
0x234e0384                        dd         0x00000000
0x234e0388                        dd         0x00000000
0x234e038c                        dd         0x00000000
0x234e0390                        dd         sub_2348d3f6+1
0x234e0394                        dd         mainfunction_thread+1
0x234e0398 0000                   movs       r0, r0
0x234e039a 0000                   movs       r0, r0
0x234e039c 0000                   movs       r0, r0
0x234e039e 0000                   movs       r0, r0
#endif
    }, 
};

static uint8_t Data_234e03b0[100] = " "; //234e03b0, size???

static Graphic_Job_2_5_Item_Text Data_234e0414 = //234e0414
{
	0, 0x0099, 0x01c0, 0x028a, 0x0203, 0x01, 0x05, 0x03, 0x01, &Data_234e03b0[0], 0, 0, 0
#if 0
0x234e0414                        db         0x00                               ; DATA XREF=0x234e0780
0x234e0415                        db         0x00
0x234e0416                        dw         0x0099
0x234e0418                        dw         0x01c0
0x234e041a                        dw         0x028a
0x234e041c                        dw         0x0203
0x234e041e                        db         0x01
0x234e041f                        db         0x05
0x234e0420                        db         0x03
0x234e0421                        db         0x01
0x234e0422                        dw         0x0000
0x234e0424                        dd         0x234e03b0
0x234e0428                        dw         0x0000
0x234e042a                        db         0x00
0x234e042b                        db         0x00
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e042c = //234e042c
{
	0, 0x00fe, 0x0042, 0x019e, 0x005e, 0x01, 0x04, 0x03, 0x01, &Data_2396c964[0], 0, 0, 0
#if 0
0x234e042c                        db         0x00                               ; DATA XREF=0x234e0840
0x234e042d                        db         0x00
0x234e042e                        dw         0x00fe
0x234e0430                        dw         0x0042
0x234e0432                        dw         0x019e
0x234e0434                        dw         0x005e
0x234e0436                        db         0x01
0x234e0437                        db         0x04
0x234e0438                        db         0x03
0x234e0439                        db         0x01
0x234e043a 0000                   movs       r0, r0
0x234e043c                        dd         0x2396c964
0x234e0440                        dw         0x0000
0x234e0442                        dw         0x0000
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e0444 = //234e0444
{
	0, 0x00fe, 0x0062, 0x019e, 0x007e, 0x01, 0x04, 0x03, 0x01, &Data_2396c978[0], 0, 0, 0
#if 0
0x234e0444                        db         0x00                               ; DATA XREF=0x234e0880
0x234e0445                        db  0x00 ; '.'
0x234e0446                        dw         0x00fe
0x234e0448                        dw         0x0062
0x234e044a                        dw         0x019e
0x234e044c                        dw         0x007e
0x234e044e                        db         0x01
0x234e044f                        db         0x04
0x234e0450                        db         0x03
0x234e0451                        db         0x01
0x234e0452 0000                   movs       r0, r0
0x234e0454                        dd         0x2396c978
0x234e0458                        dw         0x0000
0x234e045a                        dw         0x0000
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e045c = //234e045c
{
	0, 0x00fe, 0x0082, 0x019e, 0x009e, 0x01, 0x04, 0x03, 0x01, &Data_2396c98c[0], 0, 0, 0
#if 0
0x234e045c                        db         0x00                               ; DATA XREF=0x234e08c0
0x234e045d                        db  0x00 ; '.'
0x234e045e                        dw         0x00fe
0x234e0460                        dw         0x0082
0x234e0462                        dw         0x019e
0x234e0464                        dw         0x009e
0x234e0466                        db         0x01
0x234e0467                        db         0x04
0x234e0468                        db         0x03
0x234e0469                        db         0x01
0x234e046a 0000                   movs       r0, r0
0x234e046c                        dd         0x2396c98c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e0474 = //234e0474
{
	0, 0x00fe, 0x00a2, 0x019e, 0x00be, 0x01, 0x04, 0x03, 0x01, &Data_2396c9a0[0], 0, 0, 0
#if 0
0x234e0474                        db         0x00                               ; DATA XREF=0x234e0900
0x234e0475                        db  0x00 ; '.'
0x234e0476                        dw         0x00fe
0x234e0478                        dw         0x00a2
0x234e047a                        dw         0x019e
0x234e047c                        dw         0x00be
0x234e047e                        db         0x01
0x234e047f                        db         0x04
0x234e0480                        db         0x03
0x234e0481                        db         0x01
0x234e0482 0000                   movs       r0, r0
0x234e0484                        dd         0x2396c9a0
#endif
};

static uint8_t Data_234e054c[4] = "V"; //234e054c

static Graphic_Job_2_5_Item_Text Data_234e0550 = //234e0550
{
	0, 0x004a, 0x020c, 0x0091, 0x0285, 0x01, 0x05, 0x08, 0x01, &Data_234e054c[0], 0, 0, 0
#if 0
0x234e0550                        db         0x00                               ; DATA XREF=0x234e0ac0
0x234e0551                        db  0x00 ; '.'
0x234e0552                        dw         0x004a
0x234e0554                        dw         0x020c
0x234e0556                        dw         0x0091
0x234e0558                        dw         0x0285
0x234e055a                        db         0x01
0x234e055b                        db         0x05
0x234e055c                        db         0x08
0x234e055d                        db         0x01
0x234e055e 0000                   movs       r0, r0
0x234e0560                        dd         0x234e054c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e0568 = //234e0568
{
	0, 0x0239, 0x014a, 0x028a, 0x016d, 0x01, 0x05, 0x03, 0x01, &menu_info_bar_time_string[0], 0, 0, 0
#if 0
0x234e0568                        db         0x00                               ; DATA XREF=0x234e0b40
0x234e0569                        db         0x00
0x234e056a                        dw         0x0239
0x234e056c                        dw         0x014a
0x234e056e                        dw         0x028a
0x234e0570                        dw         0x016d
0x234e0572                        db         0x01
0x234e0573                        db         0x05
0x234e0574                        db         0x03
0x234e0575                        db         0x01
0x234e0576 0000                   movs       r0, r0
0x234e0578                        dd         0x234dfe5c
#endif
};

static Graphic_Job_2_5_Item Data_234e0620[40] = //234e0620
{
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x41, 0x0140, 0x186, 0x32, 0/*fill_0x14*/, &Data_234dfe74/*Data_0x18*/, 2/*wData_0x1c*/}, //[0] = 234e0620 = header
#if 0
0x234e0620                        db         0x01                               ; DATA XREF=sub_2348c8d4+30, sub_2348ca2a+12, sub_2348cc10+22, sub_2348cc10+32, sub_2348cc10+42, sub_2348cc10+48, sub_2348cc10+54, sub_2348cc10+66, sub_2348cc10+72, sub_2348cc10+78, sub_2348cc10+82
0x234e0621                        db         0x00
0x234e0622 0000                   movs       r0, r0
0x234e0624 0000                   movs       r0, r0
0x234e0626 0000                   movs       r0, r0
0x234e0628 0000                   movs       r0, r0
0x234e062a 0000                   movs       r0, r0
0x234e062c                        dw         0x0041
0x234e062e                        dw         0x0140
0x234e0630                        dw         0x0186
0x234e0632                        dw         0x0032
0x234e0634                        db         0x00
0x234e0635                        db         0x00
0x234e0636                        db         0x00
0x234e0637                        db         0x00
0x234e0638                        dd         0x234dfe74
0x234e063c                        db         0x02                               ; DATA XREF=sub_2348cc10+60, dword_2348ccec+62, dword_2348ccec+74, dword_2348ccec+266, dword_2348ccec+278
0x234e063d                        db  0x00 ; '.'
0x234e063e 0000                   movs       r0, r0
0x234e0640                        dd         0x00000000                         ; DATA XREF=dword_2348ccec+100
0x234e0644 0000                   movs       r0, r0
0x234e0646 0000                   movs       r0, r0
0x234e0648 0000                   movs       r0, r0
0x234e064a 0000                   movs       r0, r0
0x234e064c 0000                   movs       r0, r0
0x234e064e 0000                   movs       r0, r0
0x234e0650 0000                   movs       r0, r0
0x234e0652 0000                   movs       r0, r0
0x234e0654 0000                   movs       r0, r0
0x234e0656 0000                   movs       r0, r0
0x234e0658 0000                   movs       r0, r0
0x234e065a 0000                   movs       r0, r0
0x234e065c 0000                   movs       r0, r0
0x234e065e 0000                   movs       r0, r0
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x91, 0x16d, 0x1fe, 0x9b, 0/*fill_0x14*/, &Data_234dfebc/*Data_0x18*/, 2/*wData_0x1c*/}, //[1] = 234e0660 = help
#if 0
0x234e0660                        db         0x01                               ; DATA XREF=0x234e1c88
0x234e0661                        db         0x00
0x234e0662 0000                   movs       r0, r0
0x234e0664 0000                   movs       r0, r0
0x234e0666 0000                   movs       r0, r0
0x234e0668 0000                   movs       r0, r0
0x234e066a 0000                   movs       r0, r0
0x234e066c                        dw         0x0091
0x234e066e                        dw         0x016d
0x234e0670                        dw         0x01fe
0x234e0672                        dw         0x009b
0x234e0674                        db         0x00
0x234e0675                        db         0x00
0x234e0676                        db         0x00
0x234e0677                        db         0x00
0x234e0678                        dd         0x234dfebc
0x234e067c                        db         0x02
0x234e067d                        db  0x00 ; '.'
0x234e067e 0000                   movs       r0, r0
0x234e0680 0000                   movs       r0, r0
0x234e0682 0000                   movs       r0, r0
0x234e0684 0000                   movs       r0, r0
0x234e0686 0000                   movs       r0, r0
0x234e0688 0000                   movs       r0, r0
0x234e068a 0000                   movs       r0, r0
0x234e068c 0000                   movs       r0, r0
0x234e068e 0000                   movs       r0, r0
0x234e0690 0000                   movs       r0, r0
0x234e0692 0000                   movs       r0, r0
0x234e0694 0000                   movs       r0, r0
0x234e0696 0000                   movs       r0, r0
0x234e0698 0000                   movs       r0, r0
0x234e069a 0000                   movs       r0, r0
0x234e069c 0000                   movs       r0, r0
0x234e069e 0000                   movs       r0, r0
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x46, 0x145, 0x50, 0x28, 0/*fill_0x14*/, &Data_234dfe80/*Data_0x18*/, 3/*wData_0x1c*/, 0, &Data_234dff34}, //[2] = 234E06A0: Channel Number
#if 0
0x234e06a0                        db         0x01                               ; DATA XREF=sub_2348cc10+24
0x234e06a1                        db         0x00
0x234e06a2                        db  0x00 ; '.'
0x234e06a3                        db  0x00 ; '.'
0x234e06a4                        db  0x00 ; '.'
0x234e06a5                        db  0x00 ; '.'
0x234e06a6                        db  0x00 ; '.'
0x234e06a7                        db  0x00 ; '.'
0x234e06a8 0000                   movs       r0, r0
0x234e06aa 0000                   movs       r0, r0
0x234e06ac                        dw         0x0046
0x234e06ae                        dw         0x0145
0x234e06b0                        dw         0x0050
0x234e06b2                        dw         0x0028
0x234e06b4 0000                   movs       r0, r0
0x234e06b6 0000                   movs       r0, r0
0x234e06b8                        dd         0x234dfe80
0x234e06bc                        dw         0x0003
0x234e06be 0000                   movs       r0, r0
0x234e06c0                        dd         0x234dff34                         ; DATA XREF=sub_2348cc10+26
0x234e06c4 0000                   movs       r0, r0
0x234e06c6 0000                   movs       r0, r0
0x234e06c8 0000                   movs       r0, r0
0x234e06ca 0000                   movs       r0, r0
0x234e06cc 0000                   movs       r0, r0
0x234e06ce 0000                   movs       r0, r0
0x234e06d0 0000                   movs       r0, r0
0x234e06d2 0000                   movs       r0, r0
0x234e06d4 0000                   movs       r0, r0
0x234e06d6 0000                   movs       r0, r0
0x234e06d8 0000                   movs       r0, r0
0x234e06da 0000                   movs       r0, r0
0x234e06dc 0000                   movs       r0, r0
0x234e06de 0000                   movs       r0, r0
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x96, 0x145, 0x12c, 0x28, 0/*fill_0x14*/, &Data_234dfe8c/*Data_0x18*/, 8/*wData_0x1c*/, 0, &Data_234dff4c}, //[3] = 234E06E0: Channel Name
#if 0
0x234e06e0                        db         0x01                               ; DATA XREF=sub_2348cc10+34
0x234e06e1                        db         0x00
0x234e06e2 0000                   movs       r0, r0
0x234e06e4 0000                   movs       r0, r0
0x234e06e6 0000                   movs       r0, r0
0x234e06e8 0000                   movs       r0, r0
0x234e06ea 0000                   movs       r0, r0
0x234e06ec                        dw         0x0096
0x234e06ee                        dw         0x0145
0x234e06f0                        dw         0x012c
0x234e06f2                        dw         0x0028
0x234e06f4 0000                   movs       r0, r0
0x234e06f6 0000                   movs       r0, r0
0x234e06f8                        dd         0x234dfe8c
0x234e06fc                        dw         0x0008
0x234e06fe                        dw         0x0000
0x234e0700                        dd         0x234dff4c                         ; DATA XREF=sub_2348cc10+36
0x234e0704 0000                   movs       r0, r0
0x234e0706 0000                   movs       r0, r0
0x234e0708 0000                   movs       r0, r0
0x234e070a 0000                   movs       r0, r0
0x234e070c 0000                   movs       r0, r0
0x234e070e 0000                   movs       r0, r0
0x234e0710 0000                   movs       r0, r0
0x234e0712 0000                   movs       r0, r0
0x234e0714 0000                   movs       r0, r0
0x234e0716 0000                   movs       r0, r0
0x234e0718 0000                   movs       r0, r0
0x234e071a 0000                   movs       r0, r0
0x234e071c 0000                   movs       r0, r0
0x234e071e 0000                   movs       r0, r0
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x96, 0x172, 0x1f4, 0x46, 0/*fill_0x14*/, &Data_234dfe98/*Data_0x18*/, 3/*wData_0x1c*/, 0, &Data_234e0164}, //[4] = 234E0720: Present Event
#if 0
0x234e0720                        db         0x01
0x234e0721                        db         0x00
0x234e0722 0000                   movs       r0, r0
0x234e0724 0000                   movs       r0, r0
0x234e0726 0000                   movs       r0, r0
0x234e0728 0000                   movs       r0, r0
0x234e072a 0000                   movs       r0, r0
0x234e072c                        dw         0x0096
0x234e072e                        dw         0x0172
0x234e0730                        dw         0x01f4
0x234e0732                        dw         0x0046
0x234e0734 0000                   movs       r0, r0
0x234e0736 0000                   movs       r0, r0
0x234e0738                        dd         0x234dfe98
0x234e073c                        dw         0x0003
0x234e073e                        dw         0x0000
0x234e0740                        dd         0x234e0164
0x234e0744 0000                   movs       r0, r0
0x234e0746 0000                   movs       r0, r0
0x234e0748 0000                   movs       r0, r0
0x234e074a 0000                   movs       r0, r0
0x234e074c 0000                   movs       r0, r0
0x234e074e 0000                   movs       r0, r0
0x234e0750 0000                   movs       r0, r0
0x234e0752 0000                   movs       r0, r0
0x234e0754 0000                   movs       r0, r0
0x234e0756 0000                   movs       r0, r0
0x234e0758 0000                   movs       r0, r0
0x234e075a 0000                   movs       r0, r0
0x234e075c 0000                   movs       r0, r0
0x234e075e 0000                   movs       r0, r0
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x96, 0x1bd, 0x1f4, 0x46, 0/*fill_0x14*/, &Data_234dfea4/*Data_0x18*/, 3/*wData_0x1c*/, 0, &Data_234e0414}, //[5] = 234E0760: Following Event
#if 0
0x234e0760                        db         0x01
0x234e0761                        db         0x00
0x234e0762 0000                   movs       r0, r0
0x234e0764 0000                   movs       r0, r0
0x234e0766 0000                   movs       r0, r0
0x234e0768 0000                   movs       r0, r0
0x234e076a 0000                   movs       r0, r0
0x234e076c                        dw         0x0096
0x234e076e                        dw         0x01bd
0x234e0770                        dw         0x01f4
0x234e0772                        dw         0x0046
0x234e0774 0000                   movs       r0, r0
0x234e0776 0000                   movs       r0, r0
0x234e0778                        dd         0x234dfea4
0x234e077c                        dw         0x0003
0x234e077e                        dw         0x0000
0x234e0780                        dd         0x234e0414
0x234e0784 0000                   movs       r0, r0
0x234e0786 0000                   movs       r0, r0
0x234e0788 0000                   movs       r0, r0
0x234e078a 0000                   movs       r0, r0
0x234e078c 0000                   movs       r0, r0
0x234e078e 0000                   movs       r0, r0
0x234e0790 0000                   movs       r0, r0
0x234e0792 0000                   movs       r0, r0
0x234e0794 0000                   movs       r0, r0
0x234e0796 0000                   movs       r0, r0
0x234e0798 0000                   movs       r0, r0
0x234e079a 0000                   movs       r0, r0
0x234e079c 0000                   movs       r0, r0
0x234e079e 0000                   movs       r0, r0
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x00ea, 0x18, 0xc0, 0x171, 0/*fill_0x14*/, &Data_234dfeec/*Data_0x18*/, 0/*wData_0x1c*/}, //[6] = 234E07A0
#if 0
0x234e07a0                        db         0x00                               ; DATA XREF=sub_2348ca2a+30
0x234e07a1                        db         0x00
0x234e07a2 0000                   movs       r0, r0
0x234e07a4 0000                   movs       r0, r0
0x234e07a6 0000                   movs       r0, r0
0x234e07a8 0000                   movs       r0, r0
0x234e07aa 0000                   movs       r0, r0
0x234e07ac                        dw         0x00ea
0x234e07ae                        dw         0x0018
0x234e07b0                        dw         0x00c0
0x234e07b2                        dw         0x0171
0x234e07b4 0000                   movs       r0, r0
0x234e07b6 0000                   movs       r0, r0
0x234e07b8                        dd         0x234dfeec
0x234e07bc 0000                   movs       r0, r0
0x234e07be 0000                   movs       r0, r0
0x234e07c0 0000                   movs       r0, r0
0x234e07c2 0000                   movs       r0, r0
0x234e07c4 0000                   movs       r0, r0
0x234e07c6 0000                   movs       r0, r0
0x234e07c8 0000                   movs       r0, r0
0x234e07ca 0000                   movs       r0, r0
0x234e07cc 0000                   movs       r0, r0
0x234e07ce 0000                   movs       r0, r0
0x234e07d0 0000                   movs       r0, r0
0x234e07d2 0000                   movs       r0, r0
0x234e07d4 0000                   movs       r0, r0
0x234e07d6 0000                   movs       r0, r0
0x234e07d8 0000                   movs       r0, r0
0x234e07da 0000                   movs       r0, r0
0x234e07dc 0000                   movs       r0, r0
0x234e07de 0000                   movs       r0, r0
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x00f0, 0x1e, 0xb4, 0x0165, 0/*fill_0x14*/, &Data_234c128c/*Data_0x18*/, 2/*wData_0x1c*/}, //[7] = 234E07E0
#if 0
0x234e07e0                        db         0x01                               ; DATA XREF=sub_2348ca2a+26
0x234e07e1                        db         0x00
0x234e07e2 0000                   movs       r0, r0
0x234e07e4 0000                   movs       r0, r0
0x234e07e6 0000                   movs       r0, r0
0x234e07e8 0000                   movs       r0, r0
0x234e07ea 0000                   movs       r0, r0
0x234e07ec                        dw         0x00f0
0x234e07ee                        dw         0x001e
0x234e07f0                        dw         0x00b4
0x234e07f2                        dw         0x0165
0x234e07f4 0000                   movs       r0, r0
0x234e07f6 0000                   movs       r0, r0
0x234e07f8                        dd         0x234c128c
0x234e07fc                        dw         0x0002
0x234e07fe 0000                   movs       r0, r0
0x234e0800 0000                   movs       r0, r0
0x234e0802 0000                   movs       r0, r0
0x234e0804 0000                   movs       r0, r0
0x234e0806 0000                   movs       r0, r0
0x234e0808 0000                   movs       r0, r0
0x234e080a 0000                   movs       r0, r0
0x234e080c 0000                   movs       r0, r0
0x234e080e 0000                   movs       r0, r0
0x234e0810 0000                   movs       r0, r0
0x234e0812 0000                   movs       r0, r0
0x234e0814 0000                   movs       r0, r0
0x234e0816 0000                   movs       r0, r0
0x234e0818 0000                   movs       r0, r0
0x234e081a 0000                   movs       r0, r0
0x234e081c 0000                   movs       r0, r0
0x234e081e 0000                   movs       r0, r0
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0xf6, 0x3e, 0xa8, 0x20, 0/*fill_0x14*/, &Data_234dfee0/*Data_0x18*/, 3/*wData_0x1c*/, 0, &Data_234e042c}, //[8] = 234E0820: Data_234dfe54->Item[0]
#if 0
0x234e0820                        db         0x01                               ; DATA XREF=sub_2348ca2a+370, dword_234e0194
0x234e0821                        db         0x00
0x234e0822 0000                   movs       r0, r0
0x234e0824 0000                   movs       r0, r0
0x234e0826 0000                   movs       r0, r0
0x234e0828 0000                   movs       r0, r0
0x234e082a 0000                   movs       r0, r0
0x234e082c                        dw         0x00f6
0x234e082e                        dw         0x003e
0x234e0830                        dw         0x00a8
0x234e0832                        dw         0x0020
0x234e0834 0000                   movs       r0, r0
0x234e0836 0000                   movs       r0, r0
0x234e0838                        dd         0x234dfee0                         ; DATA XREF=sub_2348ca2a+372
0x234e083c                        dw         0x0003
0x234e083e 0000                   movs       r0, r0
0x234e0840                        dd         0x234e042c
0x234e0844 0000                   movs       r0, r0
0x234e0846 0000                   movs       r0, r0
0x234e0848 0000                   movs       r0, r0
0x234e084a 0000                   movs       r0, r0
0x234e084c 0000                   movs       r0, r0
0x234e084e 0000                   movs       r0, r0
0x234e0850 0000                   movs       r0, r0
0x234e0852 0000                   movs       r0, r0
0x234e0854 0000                   movs       r0, r0
0x234e0856 0000                   movs       r0, r0
0x234e0858 0000                   movs       r0, r0
0x234e085a 0000                   movs       r0, r0
0x234e085c 0000                   movs       r0, r0
0x234e085e 0000                   movs       r0, r0
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0xf6, 0x5e, 0xa8, 0x20, 0/*fill_0x14*/, &Data_234dfee0/*Data_0x18*/, 3/*wData_0x1c*/, 0, &Data_234e0444}, //[9] = 234E0860: Data_234dfe54->Item[1]
#if 0
0x234e0860                        db         0x01                               ; DATA XREF=0x234e01c0
0x234e0861                        db         0x00
0x234e0862 0000                   movs       r0, r0
0x234e0864 0000                   movs       r0, r0
0x234e0866 0000                   movs       r0, r0
0x234e0868 0000                   movs       r0, r0
0x234e086a 0000                   movs       r0, r0
0x234e086c                        dw         0x00f6
0x234e086e                        dw         0x005e
0x234e0870                        dw         0x00a8
0x234e0872                        dw         0x0020
0x234e0874 0000                   movs       r0, r0
0x234e0876 0000                   movs       r0, r0
0x234e0878                        dd         0x234dfee0
0x234e087c                        dw         0x0003
0x234e087e 0000                   movs       r0, r0
0x234e0880                        dd         0x234e0444
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x00f6, 0x007e, 0x00a8, 0x0020, 0/*fill_0x14*/, &Data_234dfee0/*Data_0x18*/, 3/*wData_0x1c*/, 0, &Data_234e045c}, //[10] = 234E08A0: Data_234dfe54->Item[2]
#if 0
0x234e08a0                        db         0x01                               ; DATA XREF=0x234e01ec
0x234e08a1                        db         0x00
0x234e08a2 0000                   movs       r0, r0
0x234e08a4 0000                   movs       r0, r0
0x234e08a6 0000                   movs       r0, r0
0x234e08a8 0000                   movs       r0, r0
0x234e08aa 0000                   movs       r0, r0
0x234e08ac                        dw         0x00f6
0x234e08ae                        dw         0x007e
0x234e08b0                        dw         0x00a8
0x234e08b2                        dw         0x0020
0x234e08b4 0000                   movs       r0, r0
0x234e08b6 0000                   movs       r0, r0
0x234e08b8                        dd         0x234dfee0
0x234e08bc                        dw         0x0003
0x234e08be 0000                   movs       r0, r0
0x234e08c0                        dd         0x234e045c
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x00f6, 0x009e, 0x00a8, 0x0020, 0/*fill_0x14*/, &Data_234dfee0/*Data_0x18*/, 3/*wData_0x1c*/, 0, &Data_234e0474}, //[11] = 234E08E0: Data_234dfe54->Item[3]
#if 0
0x234e08e0                        db         0x01                               ; DATA XREF=0x234e0218
0x234e08e1                        db  0x00 ; '.'
0x234e08e2 0000                   movs       r0, r0
0x234e08e4 0000                   movs       r0, r0
0x234e08e6 0000                   movs       r0, r0
0x234e08e8 0000                   movs       r0, r0
0x234e08ea 0000                   movs       r0, r0
0x234e08ec                        dw         0x00f6
0x234e08ee                        dw         0x009e
0x234e08f0                        dw         0x00a8
0x234e08f2                        dw         0x0020
0x234e08f4 0000                   movs       r0, r0
0x234e08f6 0000                   movs       r0, r0
0x234e08f8                        dd         0x234dfee0
0x234e08fc                        dw         0x0003
0x234e08fe 0000                   movs       r0, r0
0x234e0900                        dd         0x234e0474
#endif
    {0}, //[12] = 234E0920: Data_234dfe54->Item[4]
    {0}, //[13] = 234E0960: Data_234dfe54->Item[5]
    {0}, //[14] = 234E09A0
    {0}, //[15] = 234E09E0
    {0}, //[16] = 234E0A20
    {0}, //[17] = 234E0A60
    {0, 0, 0/*fill_4*/, 0/*Data_8*/, 0x0046, 0x0208, 0x004b, 0x0019, 0/*fill_0x14*/, &Data_234dfed4/*Data_0x18*/, 3/*wData_0x1c*/, 0, &Data_234e0550}, //[18] = 234E0AA0
#if 0
0x234e0aa0                        db         0x00
0x234e0aa1                        db  0x00 ; '.'
0x234e0aa2 0000                   movs       r0, r0
0x234e0aa4 0000                   movs       r0, r0
0x234e0aa6 0000                   movs       r0, r0
0x234e0aa8 0000                   movs       r0, r0
0x234e0aaa 0000                   movs       r0, r0
0x234e0aac                        dw         0x0046
0x234e0aae                        dw         0x0208
0x234e0ab0                        dw         0x004b
0x234e0ab2                        dw         0x0019
0x234e0ab4 0000                   movs       r0, r0
0x234e0ab6 0000                   movs       r0, r0
0x234e0ab8                        dd         0x234dfed4
0x234e0abc                        dw         0x0003
0x234e0abe 0000                   movs       r0, r0
0x234e0ac0                        dd         0x234e0550
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x022b, 0x0140, 0x0064, 0x0030, 0/*fill_0x14*/, &Data_234dfef8/*Data_0x18*/, 2/*wData_0x1c*/}, //[19] = 234E0AE0: Border around the "time"?
#if 0
0x234e0ae0                        db         0x01
0x234e0ae1                        db  0x00 ; '.'
0x234e0ae2 0000                   movs       r0, r0
0x234e0ae4 0000                   movs       r0, r0
0x234e0ae6 0000                   movs       r0, r0
0x234e0ae8 0000                   movs       r0, r0
0x234e0aea 0000                   movs       r0, r0
0x234e0aec                        dw         0x022b
0x234e0aee                        dw         0x0140
0x234e0af0                        dw         0x0064
0x234e0af2                        dw         0x0030
0x234e0af4 0000                   movs       r0, r0
0x234e0af6 0000                   movs       r0, r0
0x234e0af8                        dd         0x234dfef8
0x234e0afc                        dw         0x0002
#endif
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x0230, 0x0145, 0x005a, 0x0028, 0/*fill_0x14*/, &Data_234dff04/*Data_0x18*/, 3/*wData_0x1c*/, 0, &Data_234e0568}, //[20] = 234E0B20: Time
#if 0
0x234e0b20                        db         0x01
0x234e0b21                        db  0x00 ; '.'
0x234e0b22 0000                   movs       r0, r0
0x234e0b24 0000                   movs       r0, r0
0x234e0b26 0000                   movs       r0, r0
0x234e0b28 0000                   movs       r0, r0
0x234e0b2a 0000                   movs       r0, r0
0x234e0b2c                        dw         0x0230
0x234e0b2e                        dw         0x0145
0x234e0b30                        dw         0x005a
0x234e0b32                        dw         0x0028
0x234e0b34 0000                   movs       r0, r0
0x234e0b36 0000                   movs       r0, r0
0x234e0b38                        dd         0x234dff04
0x234e0b3c                        dw         0x0003
0x234e0b3e 0000                   movs       r0, r0
0x234e0b40                        dd         0x234e0568
#endif
    {0, 0, 0/*fill_4*/, 0/*Data_8*/, 0x0037, 0x0018, 0x00c0, 0x0171, 0/*fill_0x14*/, &Data_234dfeec/*Data_0x18*/}, //[21] = 234E0B60
#if 0
0x234e0b60                        db         0x00
0x234e0b61                        db  0x00 ; '.'
0x234e0b62 0000                   movs       r0, r0
0x234e0b64 0000                   movs       r0, r0
0x234e0b66 0000                   movs       r0, r0
0x234e0b68 0000                   movs       r0, r0
0x234e0b6a 0000                   movs       r0, r0
0x234e0b6c                        dw         0x0037
0x234e0b6e                        dw         0x0018
0x234e0b70                        dw         0x00c0
0x234e0b72                        dw         0x0171
0x234e0b74 0000                   movs       r0, r0
0x234e0b76 0000                   movs       r0, r0
0x234e0b78                        dd         0x234dfeec
#endif
    {0, 0, 0/*fill_4*/, 0/*Data_8*/, 0x0037, 0x001e, 0x00b4, 0x0165, 0/*fill_0x14*/, &Data_234c128c/*Data_0x18*/, 2/*wData_0x1c*/}, //[22] = 234E0BA0
#if 0
0x234e0ba0                        db         0x00
0x234e0ba1                        db  0x00 ; '.'
0x234e0ba2 0000                   movs       r0, r0
0x234e0ba4 0000                   movs       r0, r0
0x234e0ba6 0000                   movs       r0, r0
0x234e0ba8 0000                   movs       r0, r0
0x234e0baa 0000                   movs       r0, r0
0x234e0bac                        dw         0x0037
0x234e0bae                        dw         0x001e
0x234e0bb0                        dw         0x00b4
0x234e0bb2                        dw         0x0165
0x234e0bb4 0000                   movs       r0, r0
0x234e0bb6 0000                   movs       r0, r0
0x234e0bb8                        dd         0x234c128c
0x234e0bbc                        dw         0x0002
#endif
    {0}, //[23] = 234E0BE0: Data_234dfe58->Item[0]
    {0}, //[24] = 234E0C20: Data_234dfe58->Item[1]
    {0}, //[25] = 234E0C60: Data_234dfe58->Item[2]
    {0}, //[26] = 234E0CA0: Data_234dfe58->Item[3]
    {0}, //[27] = 234E0CE0: Data_234dfe58->Item[4]
    {0}, //[28] = 234E0D20: Data_234dfe58->Item[5]
    {0}, //[29] = 234E0D60
    {0}, //[30] = 234E0DA0
    {0}, //[31] = 234E0DE0
    {0}, //[32] = 234E0E20
    {0}, //[33] = 234E0E60
    {0}, //[34] = 234E0EA0
    {0}, //[35] = 234E0EE0
    {0}, //[36] = 234E0F20
    {0}, //[37] = 234E0F60
    {0}, //[38] = 234E0FA0
    {0}, //[39] = 234E0FE0
}; //->234E1020

static Graphic_Job_2_5 Data_234e1a20 = //234e1a20
{
    0,
    0,
    1, //wData_2
    4, //bData_4
    &Data_234e0620[0], //pItems
    &menu_main_graphic_color_data, //pColorData
    16, //numColors
    0,
    40, //bNumItems
    1, //bData_0x19
    sub_2348c8c8, //Data_0x1c
    sub_2348c8b4, //Data_0x20
#if 0
0x234e1a20                        db         0x00                               ; DATA XREF=sub_2348c8d4+28, sub_2348ca2a+10, sub_2348cc10+16, sub_2348cc10+30, sub_2348cc10+40, sub_2348cc10+50, sub_2348cc10+62, sub_2348cc10+74, sub_2348cc10+84, sub_2348cc10+94, sub_2348cc10+106
0x234e1a21                        db         0x00
0x234e1a22                        dw         0x0001                             ; DATA XREF=sub_2348d7c2+16, sub_2348d7c2+36
0x234e1a24                        db         0x04
0x234e1a25                        db  0x00 ; '.'
0x234e1a26 0000                   movs       r0, r0
0x234e1a28                        dd         0x234e0620                         ; DATA XREF=sub_2348c8d4+30, sub_2348ca2a+12, sub_2348cc10+22, sub_2348cc10+32, sub_2348cc10+42, sub_2348cc10+54, sub_2348cc10+66, sub_2348cc10+78, sub_2348cc10+86, sub_2348cc10+98, sub_2348cc10+110
0x234e1a2c                        dd         0x234c123c
0x234e1a30                        db         0x10
0x234e1a31                        db  0x00 ; '.'
0x234e1a32 0000                   movs       r0, r0
0x234e1a34 0000                   movs       r0, r0
0x234e1a36 0000                   movs       r0, r0
0x234e1a38                        db         0x28
0x234e1a39                        db         0x01
0x234e1a3a 0000                   movs       r0, r0
0x234e1a3c                        dd         sub_2348c8c8+1
0x234e1a40                        dd         sub_2348c8b4+1    
#endif
};

Menu Data_234e1c78 = //234e1c78 +0x3c = 234E1CB4
{
    0,
    &Data_234e0190[0],
    &Data_234e0190[0],
    &Data_234e0620[0], //header
    &Data_234e0620[1], //help
    &Data_234e1a20, //graphicData
    5, //maxItem
    0, //currentItem
    graphic_start_job_2_5,
    sub_2348de88, //onNavigate
    sub_2348cbc8, //onEnter
    sub_2348cecc, //onExit
    0xff,
    100,
#if 0
0x234e1c78                        dw         0x0000                             ; DATA XREF=sub_2348c8d4+24, sub_2348ca2a+8, sub_2348cbc8+8, sub_2348cc10+8, dword_2348ccec+52, dword_2348ccec+196, sub_2348d61a+6, sub_2348d61a+18, sub_2348d61a+56, sub_2348d660+84, sub_2348d78c+24
0x234e1c7a                        dw         0x0000
0x234e1c7c                        dd         0x234e0190
0x234e1c80                        dd         0x234e0190
0x234e1c84                        dd         0x234e0620
0x234e1c88                        dd         0x234e0660
0x234e1c8c                        dd         0x234e1a20                         ; DATA XREF=sub_2348c8d4+28, sub_2348ca2a+10, sub_2348cc10+16, sub_2348cc10+30, sub_2348cc10+40, sub_2348cc10+50, sub_2348cc10+62, sub_2348cc10+74, sub_2348cc10+84, sub_2348cc10+94, sub_2348cc10+106
0x234e1c90                        dw         0x0005
0x234e1c92                        dw         0x0000
0x234e1c94                        dd         graphic_start_job_2_5              ; DATA XREF=sub_2348d61a+8, sub_2348d61a+60
0x234e1c98                        dd         sub_2348de88+1
0x234e1c9c                        dd         sub_2348cbc8+1
0x234e1ca0                        dd         sub_2348cecc+1
0x234e1ca4 FF00                   lsls       r7, r7, #0x3
0x234e1ca6 0000                   movs       r0, r0
0x234e1ca8                        dd         0x00000064                         ; DATA XREF=sub_2348d660+86
0x234e1cac 0000                   movs       r0, r0
0x234e1cae 0000                   movs       r0, r0
0x234e1cb0 0000                   movs       r0, r0
0x234e1cb2 0000                   movs       r0, r0
#endif
};

Menu Data_234e1cf0 = //234e1cf0 +0x3c = 234E1D2C
{
    0,
    &Data_234e0298[0],
    &Data_234e0298[0],
    &Data_234e0620[0], //header
    &Data_234e0620[1], //help
    &Data_234e1a20, //graphicData
    5, //maxItem
    0, //currentItem
    graphic_start_job_2_5,
    sub_2348de88, //onNavigate
    sub_2348c9e0, //onEnter
    sub_2348cecc, //onExit
    0xff,
    100,
#if 0
0x234e1cf0                        dw         0x0000                             ; DATA XREF=sub_2348c9e0+8, sub_2348d61a+10, sub_2348d61a+26, sub_2348d61a+62, sub_2348d660+88, dword_234dfe58
0x234e1cf2                        dw         0x0000
0x234e1cf4                        dd         0x234e0298
0x234e1cf8                        dd         0x234e0298
0x234e1cfc                        dd         0x234e0620
0x234e1d00                        dd         0x234e0660
0x234e1d04                        dd         0x234e1a20
0x234e1d08                        dw         0x0005
0x234e1d0a                        dw         0x0000
0x234e1d0c                        dd         graphic_start_job_2_5              ; DATA XREF=sub_2348d61a+12, sub_2348d61a+64
0x234e1d10                        dd         sub_2348de88+1
0x234e1d14                        dd         sub_2348c9e0+1
0x234e1d18                        dd         sub_2348cecc+1
0x234e1d1c                        dd         0x000000ff
0x234e1d20                        dd         0x00000064                         ; DATA XREF=sub_2348d660+90
0x234e1d24 0000                   movs       r0, r0
0x234e1d26 0000                   movs       r0, r0
0x234e1d28 0000                   movs       r0, r0
0x234e1d2a 0000                   movs       r0, r0
#endif
};

Struct_2348dc50* sub_2348dc50(Struct_2348dc50*);


//234e1d68
uint8_t bData_234e1d68 = 0; //234e1d68 +0
uint8_t bData_234e1d69 = 0; //234e1d69 +1
void (*Data_234e1d6c)(Menu_Item*, uint16_t, uint8_t, uint8_t) = sub_2348db56; //234e1d6c +4 
Struct_2348dc50* Data_234e1d70 = 0; //234e1d70 +8


struct 
{
    Struct_2348dc50* Data_0; //0
    Struct_2348dc50* Data_4; //4
    int fill_8[50]; //8
    Channel Data_2396b6f8; //2396B6F8 +0x28 = 2396B720
    User_Settings Data_2396b720; //2396b720 0xf8 +0x1c = 2396B73C
    uint16_t wChannelNumber; //2396b73c
    uint16_t wData_2396b73e; //2396b73e
    uint16_t fill_2396b740; //2396b740
    uint16_t wServiceId; //2396b742
    uint8_t bDirectChannelDigits; //2396B744
    int fill_2396b748; //2396b748
    void (*Data_2396b74c)(void); //2396b74c
    void (*Data_2396b750)(void); //2396b750
    void (*Data_2396b754)(); //2396b754
    uint16_t wData_2396b758; //2396b758
    uint16_t wHoldCounter; //2396b75a
    uint16_t wData_2396b75c; //2396b75c +0x134
    
} Data_2396b628; //2396b628

uint8_t Data_2396b944[12]; //2396b944. size???
uint8_t Data_2396b950[100]; //2396b950, size???
uint8_t Data_2396c964[20]; //2396c964, size???
uint8_t Data_2396c978[20]; //2396c978, size???
uint8_t Data_2396c98c[20]; //2396c98c, size???
uint8_t Data_2396c9a0[100]; //2396c9a0, size???

Struct_2348dc50 Data_2396ca04[10]; //2396ca04???, size???


/* /  / 2348c8b4 - complete */
int sub_2348c8b4(void)
{
#if 0
	console_send_string("sub_2348c8b4 (todo.c): TODO\r\n");
#endif

    uint8_t err = 0;

    OSSemPend(Data_234c1258, 0, &err);

    return 0;
}


/* /  / 2348c8c8 - complete */
void sub_2348c8c8(void)
{
#if 0
	console_send_string("sub_2348c8c8 (todo.c): TODO\r\n");
#endif

    OSSemPost(Data_234c1258);
}


/* 2348c8d4 - todo */
static int sub_2348c8d4(Struct_2348dc50* a)
{
#if 0
	console_send_string("sub_2348c8d4 (todo.c): TODO\r\n");
#endif

    uint8_t r6 = 0;
    Struct_2348dc50 sp = *a;

    Graphic_Job_2_5_Item* ip = &Data_234dfe54->graphicData->pItems[22];
    Graphic_Job_2_5_Item* lr = &Data_234dfe54->graphicData->pItems[21];
    Graphic_Job_2_5_Item* r0 = &Data_234dfe54->graphicData->pItems[30];

    int r7 = 1;
    Menu_Item* r4 = sp.Data_4->Data_8;

    struct Struct_2348dc50_Data_0x10
    {
        int fill_0; //0
        uint8_t Data_4[20]; //4
        //0x18 = 24
    }* r5 = &((struct Struct_2348dc50_Data_0x10*)(sp.Data_0x10))[sp.wData_0x1e - sp.wData_0x22];

    if (sp.wData_0x20 == 0)
    {
        //0x2348c926
        ip->bData_0 = 0;
        r0->bData_0 = 0;

        lr->bData_0x3c = 1; //r7

        Data_234e0298[0].Data_4[0]/*234e029c*/->bData_0 = 0;
        Data_234e0298[1].Data_4[0]/*234e02c8*/->bData_0 = 0;
        Data_234e0298[2].Data_4[0]/*234e02f4*/->bData_0 = 0;
        Data_234e0298[3].Data_4[0]/*234e0320*/->bData_0 = 0;
        Data_234e0298[4].Data_4[0]/*234e034c*/->bData_0 = 0;
        Data_234e0298[5].Data_4[0]/*234e0378*/->bData_0 = 0;
        //->loc_2348c9da
    }
    else
    {
        //loc_2348c956
        sprintf(r0->Data_0x20->pString, "[%d/%d]", 
            sp.wData_0x1e + 1, sp.wData_0x20);

        //->loc_2348c9c2
        for (uint8_t r0 = 0; r0 < sp.wData_0x26; r0++)
        {
            //loc_2348c968
            r4->Data_4[0]->Data_0x20->bData_0x17 = 1; //r7
            r4->Data_4[0]->bData_0x3c = 1; //r7

            uint16_t r1 = sp.wData_0x1e - sp.wData_0x22 + r0;
            if (sp.wData_0x20 > r1)
            {
                //0x2348c988
                ((Graphic_Job_2_5_Item*)(r4->Data_4[0]))->Data_0x18 = &Data_234dfee0;

                if (r4->Data_4[0]->Data_0x20 != 0)
                {
                    //0x2348c998
                    r4->Data_4[0]->Data_0x20->Data_0x10 = &r5->Data_4[0];
                }
                //loc_2348c99c
                r4->Data_4[0]->bData_0 = 1; //r7
                r6++;
                //->loc_2348c9ba
            }
            else
            {
                //loc_2348c9a6
                if (r4->Data_4[0]->Data_0x20 != 0)
                {
                    //0x2348c998
                    r4->Data_4[0]->Data_0x20->Data_0x10 = &Data_234dfe4c[0];
                }
                //loc_2348c9b4
                r4->Data_4[0]->bData_0 = 0;
            }
            //loc_2348c9ba
            r5++;
            r4++;
        }
        //0x2348c9ca
        //234E0258 / 234E0270 = 234c12ec
        ((Graphic_Job_2_5_Item*)(Data_234e0298[r6 - 1].Data_4[0]))->Data_0x18 = &Data_234c12ec; //TODO!!!
    }
    //loc_2348c9da
    return 0;
}


/* 2348c9e0 - todo */
int sub_2348c9e0(void)
{
    Struct_2348dc50 sp;

    sp.Data_4 = Data_234dfe58;
    sp.Data_0x10 = 0;
    sp.wData_0x1c = 4;
    sp.Data_0x14 = sub_2348c8d4;
    sp.Data_0x18 = sub_2348db78;
    sp.Data_0x54 = 0;
    sp.wData_0x24 = 0;
    sp.wData_0x26 = 6;
    sp.wData_0x20 = 0;
    sp.wData_0x1e = 0;
    sp.wData_0x22 = 0;
    sp.bData_0x5e = 9;
    sp.bData_0x59 = 2;
    sp.bData_0x5a = 10;
    sp.bData_0x5b = 9;

    Data_2396b628.Data_4 = sub_2348dc50(&sp);

    return 0;
}


/* 2348ca2a - todo */
static int sub_2348ca2a(Struct_2348dc50* a)
{
#if 0
	console_send_string("sub_2348ca2a (todo.c): TODO\r\n");
#endif

    uint8_t r6 = 0;

    uint8_t* sp_0x78;
    char** sp_0x74;
    uint16_t sp_0x70;
    Graphic_Job_2_5_Item* sp_0x6c = &Data_234dfe54->graphicData->pItems[29];
    Graphic_Job_2_5_Item* sp_0x68 = &Data_234dfe54->graphicData->pItems[7];
    Graphic_Job_2_5_Item* sp_0x64 = &Data_234dfe54->graphicData->pItems[6];

    Struct_2348dc50 sp = *a;

    int r7 = 1;

    if (sp.wData_0x20 == 0)
    {
        //0x2348ca62
        sp_0x68->bData_0 = 0;
        sp_0x6c->bData_0 = 0;

        sp_0x64->bData_0x3c = 1; //r7

        Data_234dfe54->Data_8[0].Data_4[0]->bData_0 = 0;
        Data_234dfe54->Data_8[1].Data_4[0]->bData_0 = 0;
        Data_234dfe54->Data_8[2].Data_4[0]->bData_0 = 0;
        Data_234dfe54->Data_8[3].Data_4[0]->bData_0 = 0;
        Data_234dfe54->Data_8[4].Data_4[0]->bData_0 = 0;
        Data_234dfe54->Data_8[5].Data_4[0]->bData_0 = 0;
        //->loc_2348cbc2
    }
    else
    {
        //loc_2348caa8
        sp.Data_4->currentItem = sp.wData_0x22;
        sp.Data_4->Data_4 = &sp.Data_4->Data_8[sp.wData_0x22];

        Menu_Item* r4 = sp.Data_4->Data_8;

        sp_0x74 = sp.Data_0x10[sp.wData_0x1e - sp.wData_0x22];

        sprintf(sp_0x6c->Data_0x20->pString, "[%d/%d]", 
            sp.wData_0x1e + 1, sp.wData_0x20);

        //->loc_2348cb88
        for (uint8_t r5 = 0; r5 < sp.wData_0x26; r5++)
        {
            //loc_2348caec
            r4->Data_4[0]->Data_0x20->bData_0x17 = 1; //r7

            sp_0x78 = r4->Data_4[0]->Data_0x20->Data_0x10;

            r4->Data_4[0]->bData_0x3c = 1; //r7

            sp_0x70 = sp.wData_0x1e - sp.wData_0x22 + r5;

            if ((sp.wData_0x22 != r5) || 
                (sub_2348dcd2() != Data_2396b628.Data_0))
            {
                //loc_2348cb1c
                sub_2348dba4(r4, sp_0x70, 1);
            }
            else
            {
                //loc_2348cb20
                sub_2348dba4(r4, sp_0x70, 2);
            }

            if (sp.wData_0x20 > sp_0x70)
            {
                //0x2348cb36
                char* r1 = sp_0x74[0];
                if (r1 != 0)
                {
                    strncpy(sp_0x78, r1, 18);
                    //->loc_2348cb50
                }
                else
                {
                    //loc_2348cb48
                    sprintf(sp_0x78, "???");
                }
                //loc_2348cb50
                r6++;

                ((Graphic_Job_2_5_Item*)(r4->Data_4[0]))->Data_0x18 = &Data_234dfee0;

                r4->Data_4[0]->bData_0 = 1; //r7
                //->loc_2348cb7c
            }
            else
            {
                //loc_2348cb62
                sprintf(sp_0x78, " ");

                r4->Data_4[0]->bData_0 = 0;
                r4->Data_4[0]->bData_0x3c = 1; //r7             

                sp_0x64->bData_0x3c = 1; //r7   
            }
            //loc_2348cb7c
            sp_0x74++;
            r4++;
        } //for (uint8_t r5 = 0; r5 < sp.wData_0x26; r5++) 
        //0x2348cb90

    	console_send_string("0x2348cb90 (todo.c): TODO!!!\r\n");

        //TODO!!!
    }
    //loc_2348cbc2
    return 0;
}


/* 2348cbc8 - todo */
int sub_2348cbc8(void) //onEnter
{
#if 0
	console_send_string("sub_2348cbc8 (todo.c): TODO\r\n");
#endif

    Struct_2348dc50 sp;

    sp.Data_4 = Data_234dfe54;
    sp.Data_0x10 = 0;
    sp.wData_0x1c = 4;
    sp.Data_0x14 = sub_2348ca2a;
    sp.Data_0x18 = sub_2348db78;
    sp.Data_0x54 = 0;
    sp.wData_0x24 = 0;
    sp.wData_0x26 = 6;
    sp.wData_0x20 = 0;
    sp.wData_0x1e = 0;
    sp.wData_0x22 = 0;
    sp.bData_0x5e = 9;
    sp.bData_0x59 = 2;
    sp.bData_0x5a = 10;
    sp.bData_0x5b = 9;

    Data_2396b628.Data_0 = sub_2348dc50(&sp);

    return 0;
}


/* 2348cc10 - todo */
void sub_2348cc10(void)
{
#if 0
	console_send_string("sub_2348cc10 (todo.c): TODO\r\n");
#endif

    Data_234dfe54->graphicData->pItems[2].Data_0x20->bData_0x17 = 1; //r4
    Data_234dfe54->graphicData->pItems[3].Data_0x20->bData_0x17 = 1; //r4

    Data_234dfe54->graphicData->pItems[32].bData_0 = 1; //r4
    Data_234dfe54->graphicData->pItems[32].bData_0x3c = 1; //r4

    Data_234dfe54->graphicData->pItems[33].bData_0 = 0; //r5
    Data_234dfe54->graphicData->pItems[34].bData_0 = 0; //r5
    Data_234dfe54->graphicData->pItems[35].bData_0 = 0; //r5
    Data_234dfe54->graphicData->pItems[36].bData_0 = 0; //r5
    Data_234dfe54->graphicData->pItems[37].bData_0 = 0; //r5
    Data_234dfe54->graphicData->pItems[38].bData_0 = 0; //r5
    Data_234dfe54->graphicData->pItems[39].bData_0 = 0; //r5

    memset(&Data_2396b944[0], 0, 10);
    memset(&Data_2396b950[0], 0, 20);
    //r1, #0x13
    //r0 = 0x234e017c
    //->loc_2348ccf0
    memset(&Data_234e017c[0], 0, 19);

    Data_2396b628.Data_2396b754 = 0; //r5

    if ((0 != sub_23418bf0/*sub_23424134*/()) || //->ts_play.c
        (0 != sub_23421f84())) //recording?
    {
        //loc_2348cd0a
    	console_send_string("sub_2348cc10, loc_2348cd0a: TODO!!!\r\n");
    }
    //loc_2348ce08 -> loc_2348ce84
    sprintf(&Data_2396b944[0], "%d", Data_2396b628.wChannelNumber);

    if (Data_2396b628.Data_2396b6f8.wFlags_2 & (1 << 0))
    {
        //0x2348ce9c
        Data_2396b950[0] = 0x07;
        Data_2396b950[1] = ' ';
        Data_2396b950[2] = '1';
        Data_2396b950[3] = 0;

        if ((((int*)&Data_2396b628.Data_2396b6f8.service_name[0])[0] + 1) == 0)
        {
            //->loc_2348ce42
            return;
        }
        else
        {
            //0x2348ceb6
            strncat(&Data_2396b950[3], &Data_2396b628.Data_2396b6f8.service_name[0], 16);
        }
    }
    else
    {
        //loc_2348cec2
        strncat(&Data_2396b950[0], &Data_2396b628.Data_2396b6f8.service_name[0], 19);
    }
}


/* /  / 2348cecc - todo */
int sub_2348cecc(void)
{
#if 1
	console_send_string("sub_2348cecc (todo.c): TODO\r\n");
#endif

    return 0;
}


/*  /  / 2348cf20 - todo */
int menu_info_bar_populate_event_field(EIT_Event* r4, Graphic_Job_2_5_Item* sp_0x58)
{
#if 0
	console_send_string("menu_info_bar_populate_event_field (todo.c): TODO\r\n");
#endif

    char strStartEndTime[24]; //sp_0x40
    int sp_0xc;
    char* r6;

    if ((sp_0x58 == 0) ||
        (sp_0x58->Data_0x20 == 0) ||
        ((r6 = sp_0x58->Data_0x20->pString) == 0) ||
        (r4 == 0))
    {
        //loc_2348cf3c
        return 4;
    }
    //loc_2348cf42
    sp_0x58->Data_0x20->bData_0x17 = 1;

    memset(r6, 0, 100);

    if (r4->Data_8 != 0)
    {
        //0x2348cf54
#if 0
        {
            extern char debug_string[];
            sprintf(debug_string, "menu_info_bar_populate_event_field: %02x:%02x (%02x:%02x)\r\n",
                    r4->start_time[0], r4->start_time[1], 
                    r4->duration[0], r4->duration[1]);
            console_send_string(debug_string);
        }
#endif

        clocktime_get_event_time_string(r4->start_time[0], r4->start_time[1], 
            r4->duration[0], r4->duration[1],
            &strStartEndTime[0], 20);

        struct Struct_2377b8d0_Inner8_Inner8_Inner0* r5 = r4->Data_8->Data_0;
        if (r5 != 0)
        {
            //0x2348cf72
            //r7 = 2396B728;
            struct Struct_2377b8d0_Inner8_Inner8_Inner0* r4 = r5;
            //->loc_2348cf8c
            while (r4->next != 0)
            {
                //loc_2348cf7a
                int r0 = sub_2340beb0(r4->ISO_639_language_code, Data_2396b628.Data_2396b720.menuLanguage);
                if (r0 != 0)
                {
                    //0x2348cf86
                    r5 = r4;
                    //->loc_2348cf92
                    break;
                }
                //loc_2348cf8a
                r4 = r4->next;
            }
            //loc_2348cf92
            uint16_t r7 = strlen(&strStartEndTime[0]) + 3;

            char* r4_ = r5->strName;
            if (r4_ != 0)
            {
                //0x2348cfa2
                char ch = *r4_;
                if (ch == 3)
                {
                    //0x2348cfa8
                    *r6 = ch;
                    r6++;
                    r7++;
                }
                //loc_2348cfb0
                char* r0 = r5->strName;
                ch = r0[0];
                if (ch == 0x10)
                {
                    //0x2348cfb8
                    r4_ = r0 + 3;
                }
                //loc_2348cfba
                sprintf(r6, "%s ", &strStartEndTime[0]);
                strncat(r6, r4_, 100 - r7);

                sub_234089e8/*sub_2340b4c4*/(&sp_0xc, r6, 
                    sp_0x58->Data_0x20->bData_0xd,
                    sp_0x58->Data_0x20->x1,
                    sp_0x58->Data_0x20->y1,
                    sp_0x58->Data_0x20->x2,
                    2);
                //->loc_2348cff6
            }
            else
            {
                //loc_2348cfec
                text_table_get_string(0x28/*keine Senderinformation*/, r6, 50);
            }
        }
        //loc_2348cff6
    }
    //loc_2348cff6
    return 0;
}


/*  /  / 2348cffa - complete */
int menu_info_bar_clear_event_field(int r4, Graphic_Job_2_5_Item* r1)
{
#if 0
	console_send_string("menu_info_bar_clear_event_field (todo.c): TODO\r\n");
#endif

    uint8_t oldString[20];

    if (r1->Data_0x20 == 0)
    {
        return 4;
    }

    uint8_t* pString = r1->Data_0x20->pString;
    if (pString == 0)
    {
        return 4;
    }

    r1->Data_0x20->bData_0x17 = 1;

    if (r4 == 3)
    {
        strncpy(&oldString[0], pString, 20);
        sprintf(pString, "\x07 1");
        strncat(pString, &oldString[0], 15);
    }
    else
    {
        memset(pString, 0, 100);

        if (r4 == 0)
        {
            text_table_get_string(1/*'Fehlerhaftes Signal!'*/, pString, 50);
        }
        else if (r4 == 1)
        {
            text_table_get_string(0x8a/*'Kurzschluss/▒berlast am Antenneneingang!'*/, pString, 50);
        }
        else if (r4 == 2)
        {
            text_table_get_string(0x28/*'keine Senderinformation'*/, pString, 50);
        } 
    }

    return 0;
}


/* 2348d06a - todo */
int sub_2348d06a(struct Struct_2377b8d0_Inner8** r4, struct Struct_2377b8d0_Inner8** r7)
{
#if 0
	console_send_string("sub_2348d06a (todo.c): TODO\r\n");
#endif

    uint8_t sp_0x104;
    int sp_0x100;
    uint8_t sp_0xfc;
    int sp_0xf8;
    Transponder transponder; //sp_0xe0 +0x18 = 0xf8
    Channel channel; //sp_0xb8

    sp_0x104 = 0;
    sp_0x100 = 0;
    sp_0xfc = 0;
    sp_0xf8 = 0;

    int r0_ = sub_23418bf0/*sub_23424134*/();
    //sp_0x110 / r1 = 2396B728;
    //r5 = 0x234dfe48;

    if (r0_ != 0)
    {
        //0x2348d08c
    	console_send_string("sub_2348d06a, 0x2348d08c: TODO!!!\r\n");
    }
    else
    {        
        //loc_2348d18a -> loc_2348d236
        uint8_t r6;

        sub_2340bf94/*sub_2340ea70*/(Data_2396b628.wChannelNumber/*2396B728->Data_0x14;*/ - 1, 
            &channel, &transponder);

        int r0 = fe_manager_get_transponder_type(&transponder);
        if (r0 == 0)
        {
            //0x2348d24e

        	console_send_string("sub_2348d06a, 0x2348d24e: TODO!!!\r\n");
        }
        //loc_2348d274
        else if (r0 == 1)
        {
            //0x2348d278
            if (6 == sub_2340ee34/*sub_23416808*/(Data_23491db8))
            {
                //0x2348d284
                r6 = sub_2340ecc0/*sub_23416694*/(Data_23491db8, &sp_0x104, &sp_0xfc);
            }
            else
            {
                //loc_2348d288                
                r6 = sub_2340ecc0/*sub_23416694*/(main_hFrontend1, &sp_0x104, &sp_0xfc);
            }
            //->loc_2348d2c8
        }
        else
        {
            //loc_2348d298

        	console_send_string("sub_2348d06a, loc_2348d298: TODO!!!\r\n");
        }

        if (sp_0x104 == 0)
        {
            //0x2348d2d0
            if (sp_0xfc == 0)
            {
                //0x2348d2d8
                if (r6 == 0)
                {
                    //0x2348d2dc
                    if (Data_2396b628.wData_2396b75c == 0)
                    {
                        menu_info_bar_clear_event_field(0/*'Fehlerhaftes Signal!'*/, 
                            &Data_234dfe54->graphicData->pItems[4]);
                        //->loc_2348d324
                    }
                    else
                    {
                        //loc_2348d2f6
                        Data_2396b628.wData_2396b75c--;
                        //->loc_2348d324
                    }
                    //loc_2348d324
                    return 0xff;
                } //if (r6 == 0)
                //loc_2348d30a
            } //if (sp_0xfc == 0)
            else
            {
                //loc_2348d2fc
                menu_info_bar_clear_event_field(1/*'Kurzschluss/▒berlast am Antenneneingang!'*/, 
                    &Data_234dfe54->graphicData->pItems[4]);
                //->loc_2348d324
                return 0xff;
            }
        } //if (sp_0x104 == 0)
        //loc_2348d30a
        if (Data_234dfe50 != 0)
        {
            //0x2348d310
            int r0 = (Data_234dfe50)(&Data_234dfe54->graphicData->pItems[4], 0x200);
            if (r0 != 0)
            {
                //loc_2348d324
                return 0xff;
            }
            //loc_2348d328
        }
        //loc_2348d328
        EIT_EventList* r6_;
        r6_ = eit_get_section_data(Data_2396b628.wServiceId,
            transponder.transport_stream_id);

        if (r6_ == 0)
        {
            //->loc_2348d20a
            menu_info_bar_clear_event_field(2, &Data_234dfe54->graphicData->pItems[4]);
            menu_info_bar_clear_event_field(2, &Data_234dfe54->graphicData->pItems[5]);

            *r4 = 0;
            *r7 = 0;

            return 0;
        }
        //loc_2348d33a
        EIT_Event* pEvent;
        
        pEvent = eit_get_present_following_event(r6_, 4);

        *r4 = pEvent;

        if (pEvent != 0)
        {
            //loc_2348d34a -> loc_2348d1cc
            menu_info_bar_populate_event_field(pEvent, &Data_234dfe54->graphicData->pItems[4]);
            //->loc_2348d1ec
        }
        else
        {
            //->loc_2348d1dc
            menu_info_bar_clear_event_field(2, &Data_234dfe54->graphicData->pItems[4]);
        }
        //loc_2348d1ec
        pEvent = eit_get_present_following_event(r6_, 1);

        *r7 = pEvent;

        if (pEvent != 0)
        {
            //0x2348d1fa
            menu_info_bar_populate_event_field(pEvent, &Data_234dfe54->graphicData->pItems[5]);
            //->loc_2348d230
        }
        else
        {
            //loc_2348d106
            menu_info_bar_clear_event_field(2, &Data_234dfe54->graphicData->pItems[5]);
        }
        //->loc_2348d230
        return 0;
    }
}


/* 2348d34c - todo */
void sub_2348d34c(void)
{
#if 0
	console_send_string("sub_2348d34c (todo.c): TODO\r\n");
#endif

    Channel sp;

    if (Data_2396b628.wChannelNumber != 0)
    {
        uint32_t r0 = Data_2396b628.wChannelNumber - 1;
        Data_2396b628.bDirectChannelDigits = 0;

        channel_start_number(&sp, (uint16_t) r0, (uint16_t) r0);

        sub_23411550();

        uint16_t r1 = 0xffff;

        if (sp.service_id != (r1 - 1))
        {
            Data_2396b628.Data_2396b6f8 = sp;

            Data_2396b628.wServiceId = Data_2396b628.Data_2396b6f8.service_id;
            Data_2396b628.wData_2396b73e = Data_2396b628.wChannelNumber;
        }
        else
        {
            //loc_2348d394
            Data_2396b628.wChannelNumber = Data_2396b628.wData_2396b73e;
        }
    }
    else
    {
        //loc_2348d394
        Data_2396b628.wChannelNumber = Data_2396b628.wData_2396b73e;
    }
    //loc_2348d398
    Data_2396b628.Data_2396b74c = sub_2348cc10;
}


/* 2348d3a2 - todo */
void sub_2348d3a2(void)
{
#if 0
	console_send_string("sub_2348d3a2 (todo.c): TODO\r\n");
#endif

    if (Data_2396b628.Data_2396b750 != 0)
    {
        if (Data_2396b628.wData_2396b758 == 0)
        {
            (Data_2396b628.Data_2396b750)();

            Data_2396b628.Data_2396b750 = 0;
        }
        else
        {
            //loc_2348d3ba
            Data_2396b628.wData_2396b758--;
        }
    }
    //loc_2348d3be
    if (Data_2396b628.Data_2396b74c != 0)
    {
        (Data_2396b628.Data_2396b74c)();

        Data_2396b628.Data_2396b74c = 0;

        Data_234dfe54->timeout = 100;
        Data_234dfe58->timeout = 100;
    }
    //loc_2348d3d4
    if (Data_2396b628.Data_2396b754 != 0)
    {
        (Data_2396b628.Data_2396b754)(&Data_234dfe54->graphicData->pItems[36], 
            &Data_234dfe54->graphicData->pItems[37], 
            &Data_234dfe54->graphicData->pItems[38]);
    }
}


/* 2348d3f6 - todo */
int sub_2348d3f6(Menu_Event* r5)
{
#if 0
	console_send_string("sub_2348d3f6 (todo.c): TODO\r\n");
#endif

    Struct_2348dc50 sp_0x38;
    Graphic_Job_2_5_Item* sp_0x34;
    Struct_2340bf0c sp; 

    int r6 = 0;
    //r4, =0x234dfe48
    //r7, =0x2396b748

    if (r5 != 0)
    {
        //0x2348d406
        memcpy(&sp_0x38, r5->Data_8, sizeof(Struct_2348dc50));

        uint8_t keyCode/*r5*/ = r5->keyCode;
        Graphic_Job_2_5_Item* r0 = Data_234dfe54->graphicData->pItems;
        sp_0x34 = &r0[2];

#if 1
        {
            extern char debug_string[];
            sprintf(debug_string, "sub_2348d3f6: sp_0x38.Data_0=0x%x\r\n", 
                sp_0x38.Data_0);
            console_send_string(debug_string);
        }
#endif

        if (sp_0x38.Data_0 == 0x3C0000)
        {
            //0x2348d42e
            sub_2340bf0c(&sp);

            Data_2396b628.bDirectChannelDigits = 0; //r6

            if (keyCode > sp.wNumChannels)
            {
                sprintf(&Data_2396b944[0], "%d", 
                    Data_2396b628.wChannelNumber);
                //->loc_2348d614
                return 0;
            }
            else
            {
                //loc_2348d44a
                Data_2396b628.wChannelNumber = keyCode;

                sp_0x34->Data_0x20->bData_0x17 = 1;

                Data_2396b628.Data_2396b74c = 0; //r6
                Data_2396b628.Data_2396b750 = sub_2348d34c;

                //TODO!!!

                //->loc_2348d4ce
                sub_2348d3a2();
                //->loc_2348d614
                return 0;
            }
        }
        //loc_2348d470
        else if (sp_0x38.Data_0 == 0x40) //Direct Channel Number input by digits
        {
            //0x2348d474
            Data_2396b944[0] = 0; //r6;

            sp_0x34->Data_0x20->bData_0x17 = 1;
            Data_2396b628.Data_2396b74c = 0; //r6
            Data_2396b628.Data_2396b750 = sub_2348d34c;

            if (Data_2396b628.bDirectChannelDigits == 3)
            {
                Data_2396b628.wData_2396b758 = 0; //r6
                Data_2396b628.wHoldCounter = Data_2396b628.Data_2396b720.Data_0x10 & 0x0f;
                //->loc_2348d4aa
            }
            else
            {
                //loc_2348d498
                Data_2396b628.wData_2396b758 = 2;
                Data_2396b628.wHoldCounter = 2 + (Data_2396b628.Data_2396b720.Data_0x10 & 0x0f);
            }
            //loc_2348d4aa
            if (Data_2396b628.bDirectChannelDigits != 0)
            {
                //loc_2348d4aa
                uint16_t r1 = Data_2396b628.wChannelNumber;

                Data_2396b628.wChannelNumber = keyCode + (r1 * 10);

                if (Data_2396b628.wChannelNumber > wData_234dfe4e)
                {
                    //0x2348d4be
                    Data_2396b628.wChannelNumber = r1;

                    sprintf(&Data_2396b944[0], "%d", Data_2396b628.wChannelNumber);

                    Data_2396b628.wData_2396b758 = 0; //r6
                    //->loc_2348d54e
                    Data_2396b628.bDirectChannelDigits = 0; //r6
                    //->loc_2348d4ce
                    sub_2348d3a2();
                    //->loc_2348d614
                    return 0;
                }
                else
                {
                    //loc_2348d4d4
                    if (Data_2396b628.bDirectChannelDigits < 4)
                    {
                        //0x2348d4d8
                        Data_2396b944[0] = Data_2396b944[1];
                        Data_2396b944[1] = Data_2396b944[2];
                        Data_2396b944[2] = Data_2396b944[3];
                        //->loc_2348d524
                        keyCode += '0';
                        Data_2396b944[3] = keyCode;
                        Data_2396b944[4] = 0;

                        sub_2341151c(&Data_2396b944[0]);
                        //loc_2348d532
                    }
                    else
                    {
                        //loc_2348d4e8
                        Data_2396b628.wData_2396b758 = 0; //r6
                        Data_2396b628.bDirectChannelDigits = 0; //r6

                        sub_2348d3a2();
                        //->loc_2348d532
                    }
                }

            } //if (Data_2396b628.bDirectChannelDigits != 0)
            else
            {
                //loc_2348d4f2
                sub_2340bf0c(&sp);

                wData_234dfe4e = sp.wNumChannels;
                Data_2396b628.wChannelNumber = keyCode;

                if (Data_2396b628.wChannelNumber > wData_234dfe4e)
                {
                    //0x2348d50a
                    sprintf(&Data_2396b944[0], "%d", Data_2396b628.wChannelNumber);

                    Data_2396b628.bDirectChannelDigits = 0; //r6

                    sub_2341151c(&Data_2396b944[0]);
                    //->loc_2348d614
                    return 0;
                }
                else
                {
                    //loc_2348d51c
                    Data_2396b944[0] = '-';
                    Data_2396b944[1] = '-';
                    //loc_2348d524
                    Data_2396b944[2] = '-';
                    keyCode += '0';
                    Data_2396b944[3] = keyCode;
                    Data_2396b944[4] = 0;

                    sub_2341151c(&Data_2396b944[0]);
                    //loc_2348d532
                }
            }
            //loc_2348d532
            Data_2396b628.bDirectChannelDigits++;
            //->loc_2348d614
            return 0;
        } //else if (sp_0x38.Data_0 == 0x40)
        //loc_2348d53a
        else if (sp_0x38.Data_0 == 0x20)
        {
            //0x2348d53e
            if (Data_2396b628.bDirectChannelDigits == 0)
            {
                //->loc_2348d614
                return 0;
            }
            //0x2348d544
            Data_2396b628.wData_2396b758 = 0; //r6
            Data_2396b628.wHoldCounter = Data_2396b628.Data_2396b720.Data_0x10 & 0x0f;
            //loc_2348d54e
            Data_2396b628.bDirectChannelDigits = 0; //r6
            //->loc_2348d4ce
            sub_2348d3a2();
            //->loc_2348d614
            return 0;
        }
        //loc_2348d552
        else if (sp_0x38.Data_0 == 0x8000)
        {
            //->loc_2348d614
            return 0;
        }
        //0x2348d55a
        else if (sp_0x38.Data_0 == 0x40000000)
        {
            //0x2348d560

            //TODO!!!
        }
        //loc_2348d594
        else if (sp_0x38.Data_0 == 0x80000000)
        {
            //0x2348d59e

            //TODO!!!
        }
        //loc_2348d5c8
        else if (sp_0x38.Data_0 == 0x20000000)
        {
            //0x2348d5d0
            sub_234521ea();
        }
        //loc_2348d614
    } //if (r5 != 0)
    else
    {
        //loc_2348d4e6 -> loc_2348d5d6
        Graphic_Queue_Item graphicQueueItem; //sp_0x8c
        EIT_Event* sp_0x88 = 0;
        EIT_Event* sp_0x84 = 0;
        Clock_Time clockTime; //sp_0x78;

        sub_2348d3a2();

        int r5 = sub_2348d06a(&sp_0x88, &sp_0x84);

        sub_2348d87e(&clockTime, sp_0x88);

        graphic_start_job_2_5(&graphicQueueItem, Data_234dfe54->graphicData);

        if (r5 == 0)
        {
            //0x2348d5fe
            if (Data_2396b628.wHoldCounter != 0xffff)
            {
                Data_2396b628.wHoldCounter--;

                if (Data_2396b628.wHoldCounter == 0)
                {
                    sub_2344f662(&graphicQueueItem);
                }
            }
        }
        //loc_2348d614
    }
    //loc_2348d614
    return 0;
}


/* 2348d61a - todo */
int menu_info_bar_enter(void)
{
#if 0
	console_send_string("menu_info_bar_enter (todo.c): TODO\r\n");
#endif

    Data_234dfe54->graphicHandler = 0;
    Data_234dfe58->graphicHandler = 0;

    MENU_STACK_PUSH(Data_234dfe54);

    sub_2348dd36(Data_234dfe54, 1);
    sub_2348dd36(Data_234dfe58, 0);

    sub_2348dcd8(Data_2396b628.Data_0->bData_0x5f);

    channel_handle_user_settings(1, &Data_2396b628.Data_2396b720);

    Data_234dfe54->graphicHandler = graphic_start_job_2_5;
    Data_234dfe58->graphicHandler = graphic_start_job_2_5;

    return 0;
}


/* 2348d660 - todo */
void sub_2348d660(int r4)
{
#if 0
	console_send_string("sub_2348d660 (todo.c): TODO\r\n");
#endif

    Struct_2340bf0c sp4;

    if (Data_2396b628.Data_0 != 0)
    {
        sub_2340bf0c(&sp4);

        Data_2396b628.Data_2396b6f8 = sp4.Data_0; //Channel
        Data_2396b628.wChannelNumber = sp4.wCurrentChannel + 1;
        Data_2396b628.wData_2396b73e = Data_2396b628.wChannelNumber;
        Data_2396b628.wServiceId = Data_2396b628.Data_2396b6f8.service_id;

        int r0;
        if (r4 != 0)
        {
            r0 = Data_2396b628.Data_2396b720.Data_0x10 & 0x0f;
        }
        else
        {
            //loc_2348d6a4
            r0 = -1;
        }
        //loc_2348d6a8
        Data_2396b628.wHoldCounter = r0;
        Data_2396b628.Data_2396b74c = sub_2348cc10;
        Data_2396b628.wData_2396b75c = 1;

        Data_234dfe54->timeout = 1;
        Data_234dfe58->timeout = 1;
    }
    //loc_2348d6bc
}


/* /  / 2348d6c0 - todo */
void sub_2348d6c0(void)
{
#if 1
	console_send_string("sub_2348d6c0 (todo.c): TODO\r\n");
#endif

}


/* /  / 2348d742 - todo */
void sub_2348d742(void)
{
#if 1
	console_send_string("sub_2348d742 (todo.c): TODO\r\n");
#endif

}


/* 2348d87e - todo */
void sub_2348d87e(Clock_Time* r4, EIT_Event* b)
{
#if 0
	console_send_string("sub_2348d87e (todo.c): TODO\r\n");
#endif

//    int r6 = 1;

    Data_234dfe54->graphicData->pItems[20].Data_0x20->bData_0x17 = 1;
    menu_info_bar_time_string[0] = 0;

    clocktime_get(r4);

    sub_2348d920(b, r4);

    if (r4->bData_4 != 0)
    {
        //0x2348d8b4
        sub_23411da0/*sub_234197b4*/(r4, Data_2396b628.Data_2396b720.timeDiff);

        sprintf(&menu_info_bar_time_string[0], "%02d:%02d", r4->hours, r4->minutes);
    }
    else
    {
        //loc_2348d8cc
        sprintf(&menu_info_bar_time_string[0], "--:--");
    }
    //loc_2348d8d6
    if ((bData_234dfe48 ^= 1) != 0)
    {
        menu_info_bar_time_string[2] = ' ';
    }
}


/* /  / 2348d920 - todo */
int sub_2348d920(EIT_Event* r0, Clock_Time* pClockTime)
{
#if 0
	console_send_string("sub_2348d920 (todo.c): TODO\r\n");
#endif

    Graphic_Job_2_5_Item* r3 = Data_234dfe54->graphicData->pItems;
    uint32_t r2 = 0;

    Graphic_Job_2_5_Item* r4 = &r3[15];
    Graphic_Job_2_5_Item* r5 = &r3[16];
    Graphic_Job_2_5_Item* r6 = &r3[14];

    if ((pClockTime == 0) || (pClockTime->bData_4 == 0))
    {
        return 4;
    }

    if (r0 == 0)
    {
        r5->y = r4->y;
        //->loc_2348dad0
    }
    else
    {
        //0x2348d96c
        uint32_t minutes = pClockTime->hours * (uint8_t)60;
        minutes = minutes + pClockTime->minutes;

        uint32_t start = ((r0->start_time[0] & 0xf0) >> 4) * 10.0;
        start += (double)(r0->start_time[0] & 0x0f);
        start = start * 60;
        start += ((r0->start_time[1] & 0xf0) >> 4) * 10.0; 
        start += (double)(r0->start_time[1] & 0x0f);

        uint32_t duration = ((r0->duration[0] & 0xf0) >> 4) * 10.0;
        duration += (double)(r0->duration[0] & 0x0f);
        duration = duration * 60;
        duration += ((r0->duration[1] & 0xf0) >> 4) * 10.0;
        duration += (double)(r0->duration[1] & 0x0f);

        if ((start <= minutes) && ((start + duration) >= minutes))
        {
            //0x2348dabc
            r2 = ((minutes - start) * 118) / duration;
        }
    }
    //loc_2348dad0
    r6->bData_0x3c = 1;
    r4->bData_0x3c = 1;
    r5->bData_0x3c = 1;

    if (r4->height < r2)
    {
        r2 = 0;
    }

    r5->y = r4->y + r2;

    return 0;
}


/* 2348db56 - complete */
void sub_2348db56(Menu_Item* a, uint16_t b, uint8_t c, uint8_t d)
{
#if 0
	console_send_string("sub_2348db56 (todo.c): TODO\r\n");
#endif

    Menu_Item_Inner4_Data_0* r4;

    do
    {
        r4 = a->Data_4[d];
        if (r4 == 0)
        {
            break;
        }

        d++;
        r4->wData_0x1c = b;
        r4->bData_0x3c = c;

        r4 = a->Data_4[d];
    }
    while (r4 != 0);
}


/* 2348db78 - todo */
int sub_2348db78(Menu_Item* a, int b)
{
#if 0
	console_send_string("sub_2348db78 (todo.c): TODO\r\n");
#endif

    int r5 = 0;

    if (b == 1)
    {
        (Data_234e1d6c)(a, Data_234e1d70->bData_0x5b, 1, 0);
    }
    else if (b == 2)
    {
        (Data_234e1d6c)(a, Data_234e1d70->bData_0x5a, 1, 0);

        r5 = 1;
    }

    return r5;
}


/* /  / 2348dbf8 - todo */
int sub_2348dbf8(Menu_Item* pItem, int r1)
{
#if 0
	console_send_string("sub_2348dbf8 (todo.c): TODO\r\n");
#endif

    uint16_t* r2 = &Data_234e1d70->arwData_0x28[0];
    uint8_t i = 0;

    do
    {
        //loc_2348dc10
        if (*r2 == (Data_234e1d70->wData_0x1e + 1))
        {
            //0x2348dc16
            if (r1 == 1)
            {
                //0x2348dc1a
                //r1 = Data_234e1d70->bData_0x5d;
                //->loc_2348dc24
                (Data_234e1d6c)(pItem, Data_234e1d70->bData_0x5d, 1, 0);
            }
            //loc_2348dc1e
            else if (r1 == 2)
            {
                //0x2348dc22
                //r1 = Data_234e1d70->bData_0x5c;
                //loc_2348dc24
                (Data_234e1d6c)(pItem, Data_234e1d70->bData_0x5c, 1, 0);
            }
            //loc_2348dc2a
            return 1;
        }
        //loc_2348dc2e
        i++;
        r2++;
    }
    while (i < 20);
    //0x2348dc38
    if (r1 == 1)
    {
        //0x2348dc3c
        //r1 = Data_234e1d70->bData_0x5b;
        //->loc_2348dc46
        (Data_234e1d6c)(pItem, Data_234e1d70->bData_0x5b, 1, 0);
    }
    //loc_2348dc40
    else if (r1 == 2)
    {
        //0x2348dc44
        //r1 = Data_234e1d70->bData_0x5a;
        //loc_2348dc46
        (Data_234e1d6c)(pItem, Data_234e1d70->bData_0x5a, 1, 0);
    }
    //loc_2348dc4c
    return 0;
}


/* 2348dc50 - todo */
Struct_2348dc50* sub_2348dc50(Struct_2348dc50* a)
{
#if 0
	console_send_string("sub_2348dc50 (todo.c): TODO\r\n");
#endif

    Struct_2348dc50* r3 = &Data_2396ca04[0];

    uint8_t i;
    for (i = 1; i < 7; i++)
    {
        if (r3->Data_4 == 0)
        {
            break;
        }

        r3++;
    }

    if (i < 8)
    {
        Data_234e1d70 = r3;

        *Data_234e1d70 = *a;

        Data_234e1d70->bData_0x5f = i;

        bData_234e1d68++;

        for (uint8_t k = 0; k < 21; k++)
        {
            Data_234e1d70->arwData_0x28[k] = 0;
        }
    }
    //loc_2348dc98
    return Data_234e1d70;
}


/* 2348dc9e - todo */
int sub_2348dc9e(void)
{
#if 0
	console_send_string("sub_2348dc9e (todo.c): TODO\r\n");
#endif

    if (Data_234e1d70->bData_0x5f > 7)
    {
        return 4;
    }

    if (bData_234e1d68 == 0)
    {
        return 1;
    }

    bData_234e1d68--;

    memset(&Data_2396ca04[Data_234e1d70->bData_0x5f - 1], 0, sizeof(Struct_2348dc50));

    return 0;
}



/* 2348dcd2 - todo */
Struct_2348dc50* sub_2348dcd2(void)
{
#if 0
	console_send_string("sub_2348dcd2 (todo.c): TODO\r\n");
#endif

    return Data_234e1d70;
}


/* 2348dcd8 - todo*/
void sub_2348dcd8(int a)
{
#if 0 
	console_send_string("sub_2348dcd8 (todo.c): TODO\r\n");
#endif

    Data_234e1d70 = &Data_2396ca04[a - 1];
    bData_234e1d69 = a - 1;
}


/* 2348dd36 - todo */
int sub_2348dd36(Menu* r4, int b)
{
#if 0
	console_send_string("sub_2348dd36 (todo.c): TODO\r\n");
#endif

    Graphic_Queue_Item sp_0x44;
    struct 
    {
        int fill_0[13]; //0
    } sp_0x10;
    Menu_Item* r6;

    if (r4->onEnter != 0)
    {
        int r0 = (r4->onEnter)(r4);
        if (r0 != 0)
        {
            return r0;
        }
    }
    //loc_2348dd4a
    if ((r4->header != 0) &&
        (r4->header->Data_0x20 != 0) &&
        (r4->stringId != 0xffff))
    {
        text_table_get_string(r4->stringId, r4->header->Data_0x20->pString, 35);

        r4->header->Data_0x20->bData_0x17 = 1;
    }
    //loc_2348dd6e
    if ((Data_234e1d70->Data_4 != r4) ||
        ((r6 = r4->Data_8) == 0))
    {
        return 4;
    }
    //loc_2348dd84
    if (Data_234e1d70->Data_0x14 != 0)
    {
        (Data_234e1d70->Data_0x14)(Data_234e1d70);
    }
    //loc_2348dd8c
    uint8_t r5 = r4->maxItem;
    do
    {
        //loc_2348dd8e
        (Data_234e1d6c)(r6, Data_234e1d70->bData_0x5b, 1, 0);

        r6++;
    }
    while (r5--);
    //0x2348ddac
    r4->currentItem = Data_234e1d70->wData_0x22;

    r6 = &r4->Data_8[Data_234e1d70->wData_0x22];
    r4->Data_4 = r6;

    int r1;
    if (b != 0)
    {
        //0x2348ddc8
        if (Data_234e1d70->Data_0x54 != 0)
        {
            //0x2348ddce
            if ((Data_234e1d70->wData_0x1e + 1) ==
                ((uint16_t*)(Data_234e1d70->Data_0x54))[0])
            {
                //0x2348ddda
                r1 = Data_234e1d70->bData_0x5c;
                //loc_2348ddde
                (Data_234e1d6c)(r6, r1, 1, 0);
            }
            //loc_2348dde8
        } //if (Data_234e1d70->Data_0x54 != 0)
        else
        {
            //loc_2348de3c
            r1 = Data_234e1d70->bData_0x5a;
            //->loc_2348ddde
            (Data_234e1d6c)(r6, r1, 1, 0);
        }
    } //if (b != 0)
    else
    {
        //loc_2348de42
        r1 = Data_234e1d70->bData_0x5b;
        (Data_234e1d6c)(r6, r1, 1, 0);
    }
    //loc_2348dde8
    if ((r4->help != 0) && 
        (b == 1) && 
        (r4->help->Data_0x20 != 0) &&
        (r6->helpStringId != 0xffff))
    {
        text_table_get_string(r6->helpStringId, r4->help->Data_0x20->pString, 243);

        r4->header->Data_0x20->bData_0x17 = 1;

        sub_234089e8(&sp_0x10, 
            r4->help->Data_0x20->pString, 
            r4->help->Data_0x20->bData_0xd, 
            r4->help->Data_0x20->x1, 
            r4->help->Data_0x20->y1,
            r4->help->Data_0x20->x2, 
            2);
    }
    //loc_2348de2c
    if (r4->graphicHandler != 0)
    {
        (r4->graphicHandler)(&sp_0x44, r4->graphicData);
    }
    //loc_2348de38
    return 0;
}


/* /  / 2348de88 - todo */
int sub_2348de88(int* a)
{
    int r6 = 0;
    int r4 = *a;

    Menu* r5 = Data_234e1d70->Data_4;
    Menu_Item* r0 = r5->Data_4;

    if (Data_234e1d70->wData_0x20 == 0)
    {
        r5->Data_4 = r5->Data_8;

        return 4;
    }

    if (Data_234e1d70->Data_0x18 != 0)
    {
        (Data_234e1d70->Data_0x18)(r0, 1);
    }

    if (r4 == 1)
    {
        r6 = -1;
    }
    else if (r4 == 2)
    {
        r6 = 1;
    }

    if ((((Data_234e1d70->wData_0x22/*r2*/ == (Data_234e1d70->wData_0x26 - 1)/*r7*/) && (r6 > 0)) ||
        ((Data_234e1d70->wData_0x22 == 0) && (r6 < 0))) &&
        //loc_2348ded8
        (Data_234e1d70->wData_0x20 > Data_234e1d70->wData_0x26))
    {
        //0x2348dee0
        if (r6 > 0)
        {
            //0x2348dee4
            Data_234e1d70->wData_0x1e++;

            if (Data_234e1d70->wData_0x1e > (Data_234e1d70->wData_0x20 - 1))
            {
                Data_234e1d70->wData_0x1e = 0;
            }
            //loc_2348def6
            Data_234e1d70->wData_0x22 = 0;
            //->loc_2348df48
        }
        else
        {
            //loc_2348df18
            Data_234e1d70->wData_0x1e--;

            if (Data_234e1d70->wData_0x1e < 0)
            {
                //0x2348df24
                Data_234e1d70->wData_0x1e = Data_234e1d70->wData_0x20 - 1;

                uint8_t r0 = Data_234e1d70->wData_0x20 % Data_234e1d70->wData_0x26;
                if (r0 == 0)
                {
                    //loc_2348df32
                    Data_234e1d70->wData_0x22 = Data_234e1d70->wData_0x26 - 1; //r7
                    //->loc_2348df3c
                }
                else
                {
                    //loc_2348df36
                    r0--;
                    Data_234e1d70->wData_0x22 = r0;
                    //loc_2348df3c
                }
            }
            else
            {
                //loc_2348df32
                Data_234e1d70->wData_0x22 = Data_234e1d70->wData_0x26 - 1; //r7
            }
            //loc_2348df3c
            if (Data_234e1d70->wData_0x1e < Data_234e1d70->wData_0x22)
            {
                //->loc_2348def6
                Data_234e1d70->wData_0x22 = 0;
                //->loc_2348df48
            }
        }
        //loc_2348df48
        (Data_234e1d70->Data_0x14)(Data_234e1d70);
        //->loc_2348dfe0
        r5->Data_4 = &r5->Data_8[Data_234e1d70->wData_0x22];
    }
    else 
    {
        //loc_2348df50
        if ((r6 > 0) && (Data_234e1d70->wData_0x20 == (Data_234e1d70->wData_0x1e - 1)))
        {
            //0x2348df64
            Data_234e1d70->wData_0x1e = 0;
            Data_234e1d70->wData_0x22 = 0;

            (Data_234e1d70->Data_0x14)(Data_234e1d70);

            r5->Data_4 = &r5->Data_8[Data_234e1d70->wData_0x22];
            //0x2348df82 -> loc_2348dfa6
        }
        else
        {
            //loc_2348df8c
            Data_234e1d70->wData_0x1e += r6;

            if (Data_234e1d70->wData_0x1e > Data_234e1d70->wData_0x20)
            {
                //0x2348df9c
                Data_234e1d70->wData_0x1e = 0;
                Data_234e1d70->wData_0x22 = 0;
                //r0, [r5, #0x8]
                //->loc_2348dfc2
                r5->Data_4 = r5->Data_8;
                //->loc_2348dfa6

                //TODO
            }
            //loc_2348dfae
            else if (Data_234e1d70->wData_0x1e < 0)
            {
                //0x2348dfb2
                Data_234e1d70->wData_0x1e = Data_234e1d70->wData_0x20 - 1;
                Data_234e1d70->wData_0x22 = Data_234e1d70->wData_0x1e;

                r5->Data_4 = &r5->Data_8[Data_234e1d70->wData_0x22];
                //0x2348dfc4
                //->loc_2348dfa6
                //TODO
            }
            //loc_2348dfc8
            else if (r6 > 0)
            {
                //0x2348dfcc
                if (Data_234e1d70->wData_0x22/*r2*/ < (Data_234e1d70->wData_0x26 - 1)/*r7*/)
                {
                    //0x2348dfd0
                    Data_234e1d70->wData_0x22++;
                    //loc_2348dfe0
                }
                //loc_2348dfe0
                r5->Data_4 = &r5->Data_8[Data_234e1d70->wData_0x22];
            }
            //loc_2348dfd4
            else if (r6 < 0)
            {
                //0x2348dfd8
                if (Data_234e1d70->wData_0x22/*r2*/ > 0)
                {
                    //0x2348dfdc
                    Data_234e1d70->wData_0x22--;
                }
                //loc_2348dfe0
                r5->Data_4 = &r5->Data_8[Data_234e1d70->wData_0x22];
            }
            else
            {
                //loc_2348dfe0
                r5->Data_4 = &r5->Data_8[Data_234e1d70->wData_0x22];
            }
        }
    }
    //loc_2348df80 -> loc_2348dfa6
    if (Data_234e1d70->Data_0x18 != 0)
    {
        //loc_2348df86
        (Data_234e1d70->Data_0x18)(r5->Data_4, 2);
    }
    //loc_2348dfaa
    return 0;
}


#endif //!VDR110
