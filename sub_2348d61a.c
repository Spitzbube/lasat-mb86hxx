
#ifndef VDR110

#include "data.h"
#include "frontdisplay.h"
#include "texttable.h"
#include "graphic.h"
#include "menu.h"
#include "sub_2348d61a.h"

#pragma thumb

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c128c; //234c128c

static Graphic_Job_2_5_Item Data_234e0620[]; //234e0620
static Menu Data_234e1c78;
static Menu Data_234e1cf0;
static uint8_t Data_2396b944[]; //2396b944
static uint8_t Data_2396b950[]; //2396b950

static int sub_2348cbc8(void);
static int sub_2348d3f6(Menu_Event*);
static void sub_2348db56(Menu_Item*, uint16_t, uint8_t, uint8_t);
static void sub_2348db78(void);
/*static*/ void sub_2348dcd8(int);


//234dfe48
Menu* Data_234dfe54 = //234dfe54 +0xc
    &Data_234e1c78;

Menu* Data_234dfe58 = //234dfe58 +0x10
    &Data_234e1cf0; 

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

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dfeec = //234dfeec
{
	14, //uint16_t wData_0; //0
	4, //int Data_4; //4
	0x0f, //uint8_t bData_8; //8
#if 0
0x234dfeec                        dw         0x000e                             ; DATA XREF=sub_2348d81e+64, 0x234e07b8
0x234dfeee 0000                   movs       r0, r0
                              dword_234dfef0:
0x234dfef0                        dd         0x00000004                         ; DATA XREF=sub_2348d81e+66
0x234dfef4                        db         0x0f
#endif
};

static Graphic_Job_2_5_Item_Text Data_234dff34 = //234dff34
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

static Graphic_Job_2_5_Item_Text Data_234dff4c = //234dff4c
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
};

static Menu_Item Data_234e0298[] = //234e0298
{
    //[0]
    {
        0xffff,
        0xffff,
        {0/*&Data_234e0be0*/},
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
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x46, 0x145, 0x50, 0x28, 0/*fill_0x14*/, &Data_234dfe80/*Data_0x18*/, 3/*wData_0x1c*/, 0, &Data_234dff34}, //[2] = 234E06A0
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
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x96, 0x145, 0x12c, 0x28, 0/*fill_0x14*/, &Data_234dfe8c/*Data_0x18*/, 8/*wData_0x1c*/, 0, &Data_234dff4c}, //[3] = 234E06E0
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
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x96, 0x172, 0x1f4, 0x46, 0/*fill_0x14*/, &Data_234dfe98/*Data_0x18*/, 3/*wData_0x1c*/, 0, &Data_234e0164}, //[4] = 234E0720
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
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x96, 0x1bd, 0x1f4, 0x46, 0/*fill_0x14*/, &Data_234dfea4/*Data_0x18*/, 3/*wData_0x1c*/, 0, &Data_234e0414}, //[5] = 234E0760
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
    {0}, //[8] = 234E0820
    {0}, //[9] = 234E0860
    {0}, //[10] = 234E08A0
    {0}, //[11] = 234E08E0
    {0}, //[12] = 234E0920
    {0}, //[13] = 234E0960
    {0}, //[14] = 234E09A0
    {0}, //[15] = 234e0660
    {0}, //[16] = 234e0660
    {0}, //[17] = 234e0660
    {0}, //[18] = 234e0660
    {0}, //[19] = 234e0660
    {0}, //[20] = 234e0660
    {0}, //[21] = 234e0660
    {0}, //[22] = 234e0660
    {0}, //[23] = 234e0660
    {0}, //[24] = 234e0660
    {0}, //[25] = 234e0660
    {0}, //[26] = 234e0660
    {0}, //[27] = 234e0660
    {0}, //[28] = 234e0660
    {0}, //[29] = 234e0660
    {0}, //[30] = 234e0660
    {0}, //[31] = 234e0660
    {0}, //[32] = 234e0660
    {0}, //[33] = 234e0660
    {0}, //[34] = 234e0660
    {0}, //[35] = 234e0660
    {0}, //[36] = 234e0660
    {0}, //[37] = 234e0660
    {0}, //[38] = 234e0660
    {0}, //[39] = 234e0660
};

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
    0, //sub_2348c8c8, //Data_0x1c
    0, //sub_2348c8b4, //Data_0x20
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
    0, //&Data_234e0660, //help
    &Data_234e1a20, //graphicData
    0, //5, //maxItem
    0, //currentItem
    graphic_start_job_2_5,
    0, //sub_2348de88, //onNavigate
    sub_2348cbc8, //onEnter
    0, //sub_2348cecc, //onExit
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
    0, //&Data_234e0660, //help
    &Data_234e1a20, //graphicData
    0, //5, //maxItem
    0, //currentItem
    graphic_start_job_2_5,
    0, //sub_2348de88, //onNavigate
    0, //sub_2348c9e0, //onEnter
    0, //sub_2348cecc, //onExit
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
    int fill_4[51]; //4
    Channel Data_2396b6f8; //2396B6F8 +0x28 = 2396B720
    User_Settings Data_2396b720; //2396b720 0xf8 +0x1c = 2396B73C
    uint16_t wData_2396b73c; //2396b73c
    uint16_t wData_2396b73e; //2396b73e
    uint16_t fill_2396b740; //2396b740
    uint16_t wData_2396b742; //2396b742
    uint8_t bData_2396b744; //2396B744
    int fill_2396b748; //2396b748
    void (*Data_2396b74c)(void); //2396b74c
    void (*Data_2396b750)(void); //2396b750
    void (*Data_2396b754)(); //2396b754
    uint16_t wData_2396b758; //2396b758
    uint16_t wData_2396b75a; //2396b75a
    uint16_t wData_2396b75c; //2396b75c +0x134
    
} Data_2396b628; //2396b628

uint8_t Data_2396b944[12]; //2396b944. size???
uint8_t Data_2396b950[100]; //2396b950, size???

Struct_2348dc50 Data_2396ca04[10]; //2396ca04???, size???


/* 2348ca2a - todo */
static void sub_2348ca2a(Struct_2348dc50* a)
{
#if 1
	console_send_string("sub_2348ca2a (todo.c): TODO\r\n");
#endif

#if 0
    uint8_t r6 = 0;

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

//        sp_0x74 = sp.Data_0x10[sp.wData_0x1e - sp.wData_0x22];
    }
#endif
}


/* 2348cbc8 - todo */
int sub_2348cbc8(void) //onEnter
{
#if 1
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
#if 1
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
    sprintf(&Data_2396b944[0], "%d", Data_2396b628.wData_2396b73c);

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


/* 2348d06a - todo */
int sub_2348d06a(void* a, void* b)
{
#if 1
	console_send_string("sub_2348d06a (todo.c): TODO\r\n");
#endif

}


/* 2348d34c - todo */
void sub_2348d34c(void)
{
#if 1
	console_send_string("sub_2348d34c (todo.c): TODO\r\n");
#endif

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

            Data_2396b628.bData_2396b744 = 0; //r6

            if (keyCode > sp.wNumChannels)
            {
                sprintf(&Data_2396b944[0], "%d", 
                    Data_2396b628.wData_2396b73c);
                //->loc_2348d614
                return 0;
            }
            else
            {
                //loc_2348d44a
                Data_2396b628.wData_2396b73c = keyCode;

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
        else if (sp_0x38.Data_0 == 0x40)
        {
            //0x2348d474

            //TODO!!!
        }
        //loc_2348d53a
        else if (sp_0x38.Data_0 == 0x20)
        {
            //0x2348d53e
            if (Data_2396b628.bData_2396b744 == 0)
            {
                //->loc_2348d614
                return 0;
            }
            //0x2348d544
            Data_2396b628.wData_2396b758 = 0; //r6
            Data_2396b628.wData_2396b75a = Data_2396b628.Data_2396b720.Data_0x10 & 0x0f;
            //loc_2348d54e
            Data_2396b628.bData_2396b744 = 0; //r6
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
        Graphic_Queue_Item sp_0x8c;
        int sp_0x88 = 0;
        int sp_0x84 = 0;
        int sp_0x78;

        sub_2348d3a2();

        int r5 = sub_2348d06a(&sp_0x88, &sp_0x84);

        sub_2348d87e(&sp_0x78, sp_0x88);

        graphic_start_job_2_5(&sp_0x8c, Data_234dfe54->graphicData);

        if (r5 == 0)
        {
            //0x2348d5fe
            if (Data_2396b628.wData_2396b75a != 0xffff)
            {
                Data_2396b628.wData_2396b75a--;

                if (Data_2396b628.wData_2396b75a == 0)
                {
                    sub_2344f662(&sp_0x8c);
                }
            }
        }
        //loc_2348d614
    }
    //loc_2348d614
    return 0;
}


/* 2348d61a - todo */
int sub_2348d61a(void)
{
#if 1
	console_send_string("sub_2348d61a (todo.c): TODO\r\n");
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
        Data_2396b628.wData_2396b73c = sp4.wCurrentChannel + 1;
        Data_2396b628.wData_2396b73e = Data_2396b628.wData_2396b73c;
        Data_2396b628.wData_2396b742 = Data_2396b628.Data_2396b6f8.service_id;

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
        Data_2396b628.wData_2396b75a = r0;
        Data_2396b628.Data_2396b74c = sub_2348cc10;
        Data_2396b628.wData_2396b75c = 1;

        Data_234dfe54->timeout = 1;
        Data_234dfe58->timeout = 1;
    }
    //loc_2348d6bc
}


/* 2348d87e - todo */
void sub_2348d87e(void* a, int b)
{
#if 1
	console_send_string("sub_2348d87e (todo.c): TODO\r\n");
#endif

}


/* 2348db56 - complete */
void sub_2348db56(Menu_Item* a, uint16_t b, uint8_t c, uint8_t d)
{
#if 1
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
void sub_2348db78(void)
{
#if 1
	console_send_string("sub_2348db78 (todo.c): TODO\r\n");
#endif

}


/* 2348dc50 - todo */
Struct_2348dc50* sub_2348dc50(Struct_2348dc50* a)
{
#if 1
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
#if 1
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


#if 0
mainfunction_thread: ir key=87
sub_2348d61a (todo.c): TODO
sub_2348ca2a (todo.c): TODO
sub_2348d660 (todo.c): TODO
mainfunction_thread: r7=0x2341fc51
sub_2348d3f6 (todo.c): TODO
mainfunction_thread: sp_0xc=0x2341a858
graphic_thread: r7->command=2
loc_23453500: r5->wData_2=0x1, bData_0=0, bData_0x19=1, bData_4=4
loc_23453500: r5->bNumItems=40, r5->pItems=23451274, bData_1=255
dma_start_memcpy: writeAddr=22048000, readAddr=22000000, length=221184
sub_2348d3f6 (todo.c): TODO
#endif


#endif //!VDR110
