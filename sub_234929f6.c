#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "menu.h"
#include "menu_info_bar.h"

#ifndef VDR110

#pragma thumb

void sub_2344f3c6(UI_Thread_Params*);

extern void sub_2348dbf8();
extern int sub_2348de88(int*);

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12d4; //234c12d4
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12ec; //234c12ec
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12f8; //234c12f8
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c134c; //234c134c
extern Menu* Data_234c5354; //234c5354

static Menu Data_234ee504; //234ee504
static uint8_t Data_239727bc[]; //239727bc
static uint8_t Data_239728dc[]; //239728dc
static uint8_t Data_23972904[]; //23972904
static uint8_t Data_2397292c[]; //2397292c
static uint8_t Data_23972954[]; //23972954
static uint8_t Data_2397297c[]; //2397297c
static uint8_t Data_239729a4[]; //239729a4
static uint8_t Data_239729cc[]; //239729cc
static uint8_t Data_239729f4[]; //239729f4
static uint8_t Data_23972a1c[]; //23972a1c
static uint8_t Data_23972a44[]; //23972a44

static int sub_2349281e(Struct_2348dc50*);
static int sub_23492914();
static int sub_23492a1c(UI_Thread_Params*);


//234ed9bc
static Menu* Data_234ed9bc = &Data_234ee504; //234ed9bc

static Graphic_Job_2_5_Item_Text Data_234ed9e4 = //234ed9e4
{
    0, 0x0051, 0x002d, 0x0148, 0x004f, 0x01, 0x06, 0x02, 0x00, &Data_239727bc[0], 0, 0, 0
#if 0
0x234ed9e4                        db         0x00                               ; DATA XREF=0x234edb64
0x234ed9e5                        db         0x00
0x234ed9e6                        dw         0x0051
0x234ed9e8                        dw         0x002d
0x234ed9ea                        dw         0x0148
0x234ed9ec                        dw         0x004f
0x234ed9ee                        db         0x01
0x234ed9ef                        db         0x06
0x234ed9f0                        db         0x02
0x234ed9f1                        db         0x00
0x234ed9f2 0000                   movs       r0, r0
0x234ed9f4                        dd         0x239727bc                         ; CODE XREF=word_234ed44e+1290
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eda14 = //234eda14
{
    0, 0x0047, 0x0064, 0x0148, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_239728dc[0], 0, 0, 0
#if 0
0x234eda14                        db         0x00                               ; DATA XREF=0x234edc64
0x234eda15                        db         0x00
0x234eda16                        dw         0x0047
0x234eda18                        dw         0x0064
0x234eda1a                        dw         0x0148
0x234eda1c                        dw         0x0080
0x234eda1e                        db         0x01
0x234eda1f                        db         0x04
0x234eda20                        db         0x09
0x234eda21                        db         0x01
0x234eda22 0000                   movs       r0, r0
0x234eda24                        dd         0x239728dc
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eda2c = //234eda2c
{
    0, 0x0047, 0x0084, 0x0148, 0x00a0, 0x01, 0x04, 0x09, 0x01, &Data_23972904[0], 0, 0, 0
#if 0
0x234eda2c                        db         0x00                               ; DATA XREF=0x234edca4
0x234eda2d                        db         0x00
0x234eda2e                        dw         0x0047
0x234eda30                        dw         0x0084
0x234eda32                        dw         0x0148
0x234eda34                        dw         0x00a0
0x234eda36                        db         0x01
0x234eda37                        db         0x04
0x234eda38                        db         0x09
0x234eda39                        db         0x01
0x234eda3a 0000                   movs       r0, r0
0x234eda3c                        dd         0x23972904
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eda44 = //234eda44
{
    0, 0x0047, 0x00a4, 0x0148, 0x00c0, 0x01, 0x04, 0x09, 0x01, &Data_2397292c[0], 0, 0, 0
#if 0
0x234eda44                        db         0x00                               ; DATA XREF=word_234ed44e+1298, 0x234edce4
0x234eda45                        db         0x00
0x234eda46                        dw         0x0047
0x234eda48                        dw         0x00a4
0x234eda4a                        dw         0x0148
0x234eda4c                        dw         0x00c0
0x234eda4e                        db         0x01
0x234eda4f                        db         0x04
0x234eda50                        db         0x09
0x234eda51                        db         0x01
0x234eda52 0000                   movs       r0, r0
0x234eda54                        dd         0x2397292c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eda5c = //234eda5c
{
    0, 0x0047, 0x00c4, 0x0148, 0x00e0, 0x01, 0x04, 0x09, 0x01, &Data_23972954[0], 0, 0, 0
#if 0
0x234eda5c                        db         0x00                               ; DATA XREF=0x234edd24
0x234eda5d                        db         0x00
0x234eda5e                        dw         0x0047
0x234eda60                        dw         0x00c4
0x234eda62                        dw         0x0148
0x234eda64                        dw         0x00e0
0x234eda66                        db         0x01
0x234eda67                        db         0x04
0x234eda68                        db         0x09
0x234eda69                        db         0x01
0x234eda6a 0000                   movs       r0, r0
0x234eda6c                        dd         0x23972954
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eda74 = //234eda74
{
    0, 0x0047, 0x00e4, 0x0148, 0x0100, 0x01, 0x04, 0x09, 0x01, &Data_2397297c[0], 0, 0, 0
#if 0
0x234eda74                        db         0x00                               ; DATA XREF=0x234edd64
0x234eda75                        db         0x00
0x234eda76                        dw         0x0047
0x234eda78                        dw         0x00e4                             ; CODE XREF=word_234ed44e+1350
0x234eda7a                        dw         0x0148
0x234eda7c                        dw         0x0100
0x234eda7e                        db         0x01
0x234eda7f                        db         0x04
0x234eda80                        db         0x09                               ; DATA XREF=word_234ed44e+1358
0x234eda81                        db         0x01
0x234eda82                        db  0x00 ; '.'
0x234eda83                        db  0x00 ; '.'
0x234eda84                        dd         0x2397297c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eda8c = //234eda8c
{
    0, 0x0047, 0x0104, 0x0148, 0x0120, 0x01, 0x04, 0x09, 0x01, &Data_239729a4[0], 0, 0, 0
#if 0
0x234eda8c                        db         0x00                               ; DATA XREF=0x234edda4
0x234eda8d                        db         0x00
0x234eda8e                        dw         0x0047
0x234eda90                        dw         0x0104
0x234eda92                        dw         0x0148
0x234eda94                        dw         0x0120
0x234eda96                        db         0x01
0x234eda97                        db         0x04
0x234eda98                        db         0x09
0x234eda99                        db         0x01
0x234eda9a 0000                   movs       r0, r0
0x234eda9c                        dd         0x239729a4
#endif
};

static Graphic_Job_2_5_Item_Text Data_234edaa4 = //234edaa4
{
    0, 0x0047, 0x0124, 0x0148, 0x0140, 0x01, 0x04, 0x09, 0x01, &Data_239729cc[0], 0, 0, 0
#if 0
0x234edaa4                        db         0x00                               ; CODE XREF=dword_234eda80+136, DATA XREF=0x234edde4
0x234edaa5                        db         0x00
0x234edaa6                        dw         0x0047
0x234edaa8                        dw         0x0124
0x234edaaa                        dw         0x0148
0x234edaac                        dw         0x0140
0x234edaae                        db         0x01
0x234edaaf                        db         0x04
0x234edab0                        db         0x09
0x234edab1                        db         0x01
0x234edab2 0000                   movs       r0, r0
0x234edab4                        dd         0x239729cc
#endif
};

static Graphic_Job_2_5_Item_Text Data_234edabc = //234edabc
{
    0, 0x0047, 0x0144, 0x0148, 0x0160, 0x01, 0x04, 0x09, 0x01, &Data_239729f4[0], 0, 0, 0
#if 0
0x234edabc                        db         0x00                               ; DATA XREF=0x234ede24
0x234edabd                        db         0x00
0x234edabe                        dw         0x0047
0x234edac0                        dw         0x0144
0x234edac2                        dw         0x0148
0x234edac4                        dw         0x0160
0x234edac6                        db         0x01
0x234edac7                        db         0x04
0x234edac8                        db         0x09
0x234edac9                        db         0x01
0x234edaca 0000                   movs       r0, r0
0x234edacc                        dd         0x239729f4
#endif
};

static Graphic_Job_2_5_Item_Text Data_234edad4 = //234edad4
{
    0, 0x0047, 0x0164, 0x0148, 0x0180, 0x01, 0x04, 0x09, 0x01, &Data_23972a1c[0], 0, 0, 0
#if 0
0x234edad4                        db         0x00                               ; DATA XREF=0x234ede64
0x234edad5                        db         0x00
0x234edad6                        dw         0x0047
0x234edad8                        dw         0x0164
0x234edada                        dw         0x0148
0x234edadc                        dw         0x0180
0x234edade                        db         0x01
0x234edadf                        db         0x04
0x234edae0                        db         0x09
0x234edae1                        db         0x01
0x234edae2 0000                   movs       r0, r0
0x234edae4                        dd         0x23972a1c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234edaec = //234edaec
{
    0, 0x0047, 0x0184, 0x0148, 0x01a0, 0x01, 0x04, 0x09, 0x01, &Data_23972a44[0], 0, 0, 0
#if 0
0x234edaec                        db         0x00                               ; DATA XREF=0x234edea4
0x234edaed                        db         0x00
0x234edaee                        dw         0x0047
0x234edaf0                        dw         0x0184
0x234edaf2                        dw         0x0148
0x234edaf4                        dw         0x01a0
0x234edaf6                        db         0x01
0x234edaf7                        db         0x04
0x234edaf8                        db         0x09
0x234edaf9                        db         0x01
0x234edafa 0000                   movs       r0, r0
0x234edafc                        dd         0x23972a44
#endif
};

static Graphic_Job_2_5_Item Data_234edb04[] = //234edb04
{
	{0}, //[0] = 234edb04 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0029, 0x010b, 0x0026, 0, &Data_234c134c/*Data_0x18*/, 2, 0, &Data_234ed9e4/*Data_0x20*/}, //[1] = 234EDB44: header
#if 0
0x234edb44                        db         0x01                               ; DATA XREF=0x234ee510
0x234edb45                        db  0x00 ; '.'
0x234edb46 0000                   movs       r0, r0
0x234edb48                        dd         0x234ed9d0
0x234edb4c 0000                   movs       r0, r0
0x234edb4e 0000                   movs       r0, r0
0x234edb50                        dw         0x003d
0x234edb52                        dw         0x0029
0x234edb54                        dw         0x010b
0x234edb56                        dw         0x0026
0x234edb58 0000                   movs       r0, r0
0x234edb5a 0000                   movs       r0, r0
0x234edb5c                        dd         0x234c134c
0x234edb60                        dw         0x0002
0x234edb62 0000                   movs       r0, r0
0x234edb64                        dd         0x234ed9e4
#endif
	{0}, //[2] = 234EDB84 
	{0}, //[3] = 234EDBC4 
	{0}, //[4] = 234EDC04 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0060, 0x010b, 0x0020, 0, &Data_234c12f8/*Data_0x18*/, 9, 0, &Data_234eda14/*Data_0x20*/}, //[5] = 234EDC44: ?
#if 0
0x234edc44                        db         0x01                               ; CODE XREF=dword_234eda80+520, DATA XREF=0x234ee350
0x234edc45                        db  0x00 ; '.'
0x234edc46 0000                   movs       r0, r0
0x234edc48                        dd         0x234ed9dc
0x234edc4c 0000                   movs       r0, r0
0x234edc4e 0000                   movs       r0, r0
0x234edc50                        dw         0x003d
0x234edc52                        dw         0x0060
0x234edc54                        dw         0x010b
0x234edc56                        dw         0x0020
0x234edc58 0000                   movs       r0, r0
0x234edc5a 0000                   movs       r0, r0
0x234edc5c                        dd         0x234c12f8
0x234edc60                        dw         0x0009
0x234edc62 0000                   movs       r0, r0
0x234edc64                        dd         0x234eda14
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0080, 0x010b, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eda2c/*Data_0x20*/}, //[6] = 234EDC84
#if 0
0x234edc84                        db         0x01                               ; CODE XREF=dword_234eda80+584, DATA XREF=0x234ee37c
0x234edc85                        db  0x00 ; '.'
0x234edc86 0000                   movs       r0, r0
0x234edc88                        dd         0x234ed9dc
0x234edc8c 0000                   movs       r0, r0
0x234edc8e 0000                   movs       r0, r0
0x234edc90                        dw         0x003d
0x234edc92                        dw         0x0080
0x234edc94                        dw         0x010b
0x234edc96                        dw         0x0020
0x234edc98 0000                   movs       r0, r0
0x234edc9a 0000                   movs       r0, r0
0x234edc9c                        dd         0x234c12d4
0x234edca0                        dw         0x0009
0x234edca2 0000                   movs       r0, r0
0x234edca4                        dd         0x234eda2c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x00a0, 0x010b, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eda44/*Data_0x20*/}, //[7] = 234EDCC4
#if 0
0x234edcc4                        db         0x01                               ; CODE XREF=dword_234eda80+648, DATA XREF=0x234ee3a8
0x234edcc5                        db  0x00 ; '.'
0x234edcc6 0000                   movs       r0, r0
0x234edcc8                        dd         0x234ed9dc
0x234edccc 0000                   movs       r0, r0
0x234edcce 0000                   movs       r0, r0
0x234edcd0                        dw         0x003d
0x234edcd2                        dw         0x00a0
0x234edcd4                        dw         0x010b
0x234edcd6                        dw         0x0020
0x234edcd8 0000                   movs       r0, r0
0x234edcda 0000                   movs       r0, r0
0x234edcdc                        dd         0x234c12d4
0x234edce0                        dw         0x0009
0x234edce2 0000                   movs       r0, r0
0x234edce4                        dd         0x234eda44
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x00c0, 0x010b, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eda5c/*Data_0x20*/}, //[8] = 234EDD04
#if 0
0x234edd04                        db         0x01                               ; CODE XREF=dword_234eda80+712, DATA XREF=0x234ee3d4
0x234edd05                        db  0x00 ; '.'
0x234edd06 0000                   movs       r0, r0
0x234edd08                        dd         0x234ed9dc
0x234edd0c 0000                   movs       r0, r0
0x234edd0e 0000                   movs       r0, r0
0x234edd10                        dw         0x003d
0x234edd12                        dw         0x00c0
0x234edd14                        dw         0x010b
0x234edd16                        dw         0x0020
0x234edd18 0000                   movs       r0, r0
0x234edd1a 0000                   movs       r0, r0
0x234edd1c                        dd         0x234c12d4
0x234edd20                        dw         0x0009
0x234edd22 0000                   movs       r0, r0
0x234edd24                        dd         0x234eda5c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x00e0, 0x010b, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eda74/*Data_0x20*/}, //[9] = 234EDD44
#if 0
0x234edd44                        db         0x01                               ; CODE XREF=dword_234eda80+776, DATA XREF=0x234ee400
0x234edd45                        db  0x00 ; '.'
0x234edd46 0000                   movs       r0, r0
0x234edd48                        dd         0x234ed9dc
0x234edd4c 0000                   movs       r0, r0
0x234edd4e 0000                   movs       r0, r0
0x234edd50                        dw         0x003d
0x234edd52                        dw         0x00e0
0x234edd54                        dw         0x010b
0x234edd56                        dw         0x0020
0x234edd58 0000                   movs       r0, r0
0x234edd5a 0000                   movs       r0, r0
0x234edd5c                        dd         0x234c12d4
0x234edd60                        dw         0x0009
0x234edd62 0000                   movs       r0, r0
0x234edd64                        dd         0x234eda74
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0100, 0x010b, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eda8c/*Data_0x20*/}, //[10] = 234EDD84
#if 0
0x234edd84                        db         0x01                               ; CODE XREF=dword_234eda80+840, DATA XREF=0x234ee42c
0x234edd85                        db  0x00 ; '.'
0x234edd86 0000                   movs       r0, r0
0x234edd88                        dd         0x234ed9dc
0x234edd8c 0000                   movs       r0, r0
0x234edd8e 0000                   movs       r0, r0
0x234edd90                        dw         0x003d
0x234edd92                        dw         0x0100
0x234edd94                        dw         0x010b
0x234edd96                        dw         0x0020
0x234edd98 0000                   movs       r0, r0
0x234edd9a 0000                   movs       r0, r0
0x234edd9c                        dd         0x234c12d4
0x234edda0                        dw         0x0009                             ; CODE XREF=dword_234eda80+932
0x234edda2 0000                   movs       r0, r0
0x234edda4                        dd         0x234eda8c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0120, 0x010b, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234edaa4/*Data_0x20*/}, //[11] = 234EDDC4
#if 0
0x234eddc4                        db         0x01                               ; CODE XREF=dword_234eda80+904, DATA XREF=0x234ee458
0x234eddc5                        db  0x00 ; '.'
0x234eddc6 0000                   movs       r0, r0
0x234eddc8                        dd         0x234ed9dc
0x234eddcc 0000                   movs       r0, r0
0x234eddce 0000                   movs       r0, r0
0x234eddd0                        dw         0x003d
0x234eddd2                        dw         0x0120
0x234eddd4                        dw         0x010b
0x234eddd6                        dw         0x0020
0x234eddd8 0000                   movs       r0, r0
0x234eddda 0000                   movs       r0, r0
0x234edddc                        dd         0x234c12d4
0x234edde0                        dw         0x0009
0x234edde2 0000                   movs       r0, r0
0x234edde4                        dd         0x234edaa4
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0140, 0x010b, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234edabc/*Data_0x20*/}, //[12] = 234EDE04
#if 0
0x234ede04                        db         0x01                               ; CODE XREF=dword_234eda80+968, DATA XREF=0x234ee484
0x234ede05                        db  0x00 ; '.'
0x234ede06 0000                   movs       r0, r0
0x234ede08                        dd         0x234ed9dc
0x234ede0c 0000                   movs       r0, r0
0x234ede0e 0000                   movs       r0, r0
0x234ede10                        dw         0x003d                             ; CODE XREF=dword_234eda80+996
0x234ede12                        dw         0x0140
0x234ede14                        dw         0x010b
0x234ede16                        dw         0x0020
0x234ede18 0000                   movs       r0, r0
0x234ede1a 0000                   movs       r0, r0
0x234ede1c                        dd         0x234c12d4
0x234ede20                        dw         0x0009
0x234ede22 0000                   movs       r0, r0
0x234ede24                        dd         0x234edabc
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0160, 0x010b, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234edad4/*Data_0x20*/}, //[13] = 234EDE44
#if 0
0x234ede44                        db         0x01                               ; CODE XREF=dword_234eda80+1032, DATA XREF=0x234ee4b0
0x234ede45                        db  0x00 ; '.'
0x234ede46 0000                   movs       r0, r0
0x234ede48                        dd         0x234ed9dc
0x234ede4c 0000                   movs       r0, r0
0x234ede4e 0000                   movs       r0, r0
0x234ede50                        dw         0x003d
0x234ede52                        dw         0x0160
0x234ede54                        dw         0x010b
0x234ede56                        dw         0x0020
0x234ede58 0000                   movs       r0, r0
0x234ede5a 0000                   movs       r0, r0
0x234ede5c                        dd         0x234c12d4
0x234ede60                        dw         0x0009
0x234ede62 0000                   movs       r0, r0
0x234ede64                        dd         0x234edad4
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0180, 0x010b, 0x0020, 0, &Data_234c12ec/*Data_0x18*/, 9, 0, &Data_234edaec/*Data_0x20*/}, //[14] = 234EDE84
#if 0
0x234ede84                        db         0x01                               ; DATA XREF=0x234ee4dc
0x234ede85                        db  0x00 ; '.'
0x234ede86 0000                   movs       r0, r0
0x234ede88                        dd         0x234ed9dc
0x234ede8c 0000                   movs       r0, r0                             ; CODE XREF=dword_234eda80+1096
0x234ede8e 0000                   movs       r0, r0
0x234ede90                        dw         0x003d
0x234ede92                        dw         0x0180
0x234ede94                        dw         0x010b
0x234ede96                        dw         0x0020
0x234ede98 0000                   movs       r0, r0
0x234ede9a 0000                   movs       r0, r0
0x234ede9c                        dd         0x234c12ec
0x234edea0                        dw         0x0009
0x234edea2 0000                   movs       r0, r0
0x234edea4                        dd         0x234edaec                         ; CODE XREF=dword_234eda80+1160
#endif
	{0}, //[15] = 234EDEC4 
    //234EDF04
};

static Graphic_Job_2_5 Data_234ee304 = //234ee304
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x0033, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234edb04[0], //Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	0x10, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	16, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
#if 0
0x234ee304                        db         0x00                               ; DATA XREF=0x234ee518
0x234ee305                        db         0xfa
0x234ee306                        dw         0x0033
0x234ee308                        db         0x04
0x234ee309                        db  0x00 ; '.'
0x234ee30a 0000                   movs       r0, r0
0x234ee30c                        dd         0x234edb04
0x234ee310                        dd         menu_main_graphic_color_data
0x234ee314                        db         0x10
0x234ee315                        db  0x00 ; '.'
0x234ee316                        db         0x00
0x234ee317                        db  0x00 ; '.'
0x234ee318                        dd         0x00000000
0x234ee31c                        db         0x10
0x234ee31d                        db         0x01
#endif
};

static Menu_Item Data_234ee34c[] = //234ee34c
{
	//[0]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234edb04[5], //234edc44,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_2349281e, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EE378
#if 0
0x234ee34c                        dw         0xffff                             ; DATA XREF=0x234ee508, 0x234ee50c
0x234ee34e                        dw         0x0105
0x234ee350                        dd         0x234edc44
0x234ee354 0000                   movs       r0, r0
0x234ee356 0000                   movs       r0, r0
0x234ee358 0000                   movs       r0, r0
0x234ee35a 0000                   movs       r0, r0
0x234ee35c 0000                   movs       r0, r0
0x234ee35e 0000                   movs       r0, r0
0x234ee360 0000                   movs       r0, r0
0x234ee362 0000                   movs       r0, r0
0x234ee364 0000                   movs       r0, r0
0x234ee366 0000                   movs       r0, r0
0x234ee368                        dd         sub_2349281e+1
0x234ee36c                        dd         sub_2344f3c6+1
#endif
    },
	//[1]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234edb04[6], //234edc84,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_2349281e, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EE3A4
#if 0
0x234ee378                        dw         0xffff
0x234ee37a                        dw         0x0105
0x234ee37c                        dd         0x234edc84
0x234ee380 0000                   movs       r0, r0
0x234ee382 0000                   movs       r0, r0
0x234ee384 0000                   movs       r0, r0
0x234ee386 0000                   movs       r0, r0
0x234ee388 0000                   movs       r0, r0
0x234ee38a 0000                   movs       r0, r0
0x234ee38c 0000                   movs       r0, r0
0x234ee38e 0000                   movs       r0, r0
0x234ee390 0000                   movs       r0, r0
0x234ee392 0000                   movs       r0, r0
0x234ee394                        dd         sub_2349281e+1
0x234ee398                        dd         sub_2344f3c6+1
#endif
    },
	//[2]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234edb04[7], //234edcc4,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_2349281e, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EE3D0
#if 0
0x234ee3a4                        dw         0xffff
0x234ee3a6                        dw         0x0105
0x234ee3a8                        dd         0x234edcc4
0x234ee3ac 0000                   movs       r0, r0
0x234ee3ae 0000                   movs       r0, r0
0x234ee3b0 0000                   movs       r0, r0
0x234ee3b2 0000                   movs       r0, r0
0x234ee3b4 0000                   movs       r0, r0
0x234ee3b6 0000                   movs       r0, r0
0x234ee3b8 0000                   movs       r0, r0
0x234ee3ba 0000                   movs       r0, r0
0x234ee3bc 0000                   movs       r0, r0
0x234ee3be 0000                   movs       r0, r0
0x234ee3c0                        dd         sub_2349281e+1
0x234ee3c4                        dd         sub_2344f3c6+1
#endif
    },
	//[3]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234edb04[8], //234edd04,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_2349281e, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EE3FC
#if 0
0x234ee3d0                        dw         0xffff
0x234ee3d2                        dw         0x0105
0x234ee3d4                        dd         0x234edd04
0x234ee3d8 0000                   movs       r0, r0
0x234ee3da 0000                   movs       r0, r0
0x234ee3dc 0000                   movs       r0, r0
0x234ee3de 0000                   movs       r0, r0
0x234ee3e0 0000                   movs       r0, r0
0x234ee3e2 0000                   movs       r0, r0
0x234ee3e4 0000                   movs       r0, r0                             ; CODE XREF=dword_234eda80+2520
0x234ee3e6 0000                   movs       r0, r0
0x234ee3e8 0000                   movs       r0, r0
0x234ee3ea 0000                   movs       r0, r0
0x234ee3ec                        dd         sub_2349281e+1
0x234ee3f0                        dd         sub_2344f3c6+1
#endif
    },
	//[4]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234edb04[9], //234edd44,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_2349281e, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EE428
#if 0
0x234ee3fc                        dw         0xffff
0x234ee3fe                        dw         0x0105
0x234ee400                        dd         0x234edd44
0x234ee404                        db  0x00 ; '.'
0x234ee405                        db  0x00 ; '.'
0x234ee406 0000                   movs       r0, r0
0x234ee408 0000                   movs       r0, r0
0x234ee40a 0000                   movs       r0, r0
0x234ee40c 0000                   movs       r0, r0
0x234ee40e 0000                   movs       r0, r0
0x234ee410 0000                   movs       r0, r0
0x234ee412 0000                   movs       r0, r0
0x234ee414 0000                   movs       r0, r0
0x234ee416 0000                   movs       r0, r0
0x234ee418                        dd         sub_2349281e+1
0x234ee41c                        dd         sub_2344f3c6+1
#endif
    },
	//[5]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234edb04[10], //234edd84,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_2349281e, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EE454
#if 0
0x234ee428                        dw         0xffff
0x234ee42a                        dw         0x0105
0x234ee42c                        dd         0x234edd84
0x234ee430 0000                   movs       r0, r0
0x234ee432 0000                   movs       r0, r0
0x234ee434 0000                   movs       r0, r0
0x234ee436 0000                   movs       r0, r0
0x234ee438 0000                   movs       r0, r0
0x234ee43a 0000                   movs       r0, r0
0x234ee43c 0000                   movs       r0, r0
0x234ee43e 0000                   movs       r0, r0
0x234ee440 0000                   movs       r0, r0
0x234ee442 0000                   movs       r0, r0
0x234ee444                        dd         sub_2349281e+1
0x234ee448                        dd         sub_2344f3c6+1
#endif
    },
	//[6]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234edb04[11], //234eddc4,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_2349281e, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EE480
#if 0
0x234ee454                        dw         0xffff
0x234ee456                        dw         0x0105
0x234ee458                        dd         0x234eddc4
0x234ee45c 0000                   movs       r0, r0
0x234ee45e 0000                   movs       r0, r0
0x234ee460 0000                   movs       r0, r0
0x234ee462 0000                   movs       r0, r0
0x234ee464 0000                   movs       r0, r0
0x234ee466 0000                   movs       r0, r0
0x234ee468 0000                   movs       r0, r0
0x234ee46a 0000                   movs       r0, r0
0x234ee46c 0000                   movs       r0, r0
0x234ee46e 0000                   movs       r0, r0
0x234ee470                        dd         sub_2349281e+1
0x234ee474                        dd         sub_2344f3c6+1
#endif
    },
	//[7]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234edb04[12], //234ede04,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_2349281e, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EE4AC
#if 0
0x234ee480                        dw         0xffff
0x234ee482                        dw         0x0105
0x234ee484                        dd         0x234ede04
0x234ee488 0000                   movs       r0, r0
0x234ee48a 0000                   movs       r0, r0
0x234ee48c 0000                   movs       r0, r0
0x234ee48e 0000                   movs       r0, r0
0x234ee490 0000                   movs       r0, r0
0x234ee492 0000                   movs       r0, r0
0x234ee494 0000                   movs       r0, r0
0x234ee496 0000                   movs       r0, r0
0x234ee498 0000                   movs       r0, r0
0x234ee49a 0000                   movs       r0, r0
0x234ee49c                        dd         sub_2349281e+1
0x234ee4a0                        dd         sub_2344f3c6+1
#endif
    },
	//[8]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234edb04[13], //234ede44,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_2349281e, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EE4D8
#if 0
0x234ee4ac                        dw         0xffff
0x234ee4ae                        dw         0x0105
0x234ee4b0                        dd         0x234ede44
0x234ee4b4 0000                   movs       r0, r0
0x234ee4b6 0000                   movs       r0, r0
0x234ee4b8 0000                   movs       r0, r0
0x234ee4ba 0000                   movs       r0, r0
0x234ee4bc 0000                   movs       r0, r0
0x234ee4be 0000                   movs       r0, r0
0x234ee4c0 0000                   movs       r0, r0
0x234ee4c2 0000                   movs       r0, r0
0x234ee4c4 0000                   movs       r0, r0
0x234ee4c6 0000                   movs       r0, r0
0x234ee4c8                        dd         sub_2349281e+1
0x234ee4cc                        dd         sub_2344f3c6+1
#endif
    },
	//[9]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234edb04[14], //234ede84,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_2349281e, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234EE504
#if 0
0x234ee4d8                        dw         0xffff
0x234ee4da                        dw         0x0105
0x234ee4dc                        dd         0x234ede84
0x234ee4e0 0000                   movs       r0, r0
0x234ee4e2 0000                   movs       r0, r0
0x234ee4e4 0000                   movs       r0, r0
0x234ee4e6 0000                   movs       r0, r0
0x234ee4e8 0000                   movs       r0, r0
0x234ee4ea 0000                   movs       r0, r0
0x234ee4ec 0000                   movs       r0, r0
0x234ee4ee 0000                   movs       r0, r0
0x234ee4f0 0000                   movs       r0, r0
0x234ee4f2 0000                   movs       r0, r0
0x234ee4f4                        dd         sub_2349281e+1
0x234ee4f8                        dd         sub_2344f3c6+1
#endif
    }
};

static Menu Data_234ee504 = //234ee504
{
    0x010b, //'Alle Programme l▒schen' / 'Delete all channels'
    &Data_234ee34c[0], //Menu_Item* Data_4; //4
    &Data_234ee34c[0], //Menu_Item* Data_8; //8
    &Data_234edb04[1], //234edb44, //Struct_235fdf74_Inner12* header; //12 = 0xc
    0, /*&Data_234c3414*/ //Struct_235fdf74_Inner16* help; //16 = 0x10
    &Data_234ee304, //int graphicData; //20 = 0x14
    9, //uint8_t maxItem; //0x18 = 24
    0, //int8_t currentItem; //0x19
    graphic_start_job_2_5, //void (*graphicHandler)(); //0x1c
    sub_2348de88, //void (*onNavigate)(); //0x20
    sub_23492914, //int (*onEnter)(int); //36 = 0x24
    sub_23492a1c, //int (*onExit)(UI_Thread_Params*); //0x28
#if 0
0x234ee504                        dw         0x010b
0x234ee506                        dw         0x0000
0x234ee508                        dd         0x234ee34c
0x234ee50c                        dd         0x234ee34c
0x234ee510                        dd         0x234edb44
0x234ee514                        dd         0x234edbc4
0x234ee518                        dd         0x234ee304
0x234ee51c                        db         0x09
0x234ee51d                        db  0x00 ; '.'
0x234ee51e 0000                   movs       r0, r0
0x234ee520                        dd         graphic_start_job_2_5
0x234ee524                        dd         sub_2348de88+1
0x234ee528                        dd         sub_23492914+1
0x234ee52c                        dd         sub_23492a1c+1
#endif
//234EE540
};


//0x23972748
struct 
{
	Struct_23543df0* Data_23972748; //23972748 +0
	Transponder* Data_2397274c; //2397274c +4
	Channel* Data_23972750; //23972750 +8
	uint16_t arData_23972754[30]; //23972754 +0xc, size???
	uint16_t arData_23972790[20]; //23972790
	uint16_t wData_239727b8; //239727b8 +0x10
	uint8_t bData_239727ba; //239727ba +0x12

} Data_2397275a; //2397275a???


static uint8_t Data_239727bc[40]; //239727bc, size???
static uint8_t Data_239728dc[40]; //239728dc, size???
static uint8_t Data_23972904[40]; //23972904, size???
static uint8_t Data_2397292c[40]; //2397292c, size???
static uint8_t Data_23972954[40]; //23972954, size???
static uint8_t Data_2397297c[40]; //2397297c, size???
static uint8_t Data_239729a4[40]; //239729a4, size???
static uint8_t Data_239729cc[40]; //239729cc, size???
static uint8_t Data_239729f4[40]; //239729f4, size???
static uint8_t Data_23972a1c[40]; //23972a1c, size???
static uint8_t Data_23972a44[40]; //23972a44, size???



/* /  / 234926c8 - todo */
int sub_234926c8(Struct_2348dc50* a)
{
#if 0
	console_send_string("sub_234926c8 (todo.c): TODO\r\n");
#endif

	Struct_2348dc50 sp_0x24;
	Struct_23543df0 sp4;

	sp_0x24 = *a;
	Menu_Item* r4 = sp_0x24.pMenu->Data_8;
	uint8_t r5;

	for (r5 = 0; r5 < sp_0x24.wData_0x26; r4++, r5++)
	{
		//loc_234926de
		uint16_t r6 = sp_0x24.wData_0x1e - sp_0x24.wData_0x22 + r5;

		if (sp_0x24.Data_0x54 != 0)
		{
			//0x234926f0
			sub_2348dba4(r4, r6, 1);
		}
		//loc_234926fa
		if (r6 < sp_0x24.wData_0x20)
		{
			//0x23492704
			int r1 = Data_2397275a.arData_23972754[r6];

			if (r1 == 0xfffe)
			{
				//0x23492712
				strcpy(((Graphic_Job_2_5_Item*)(r4->Data_4[0]))->Data_0x20->pString, "Internet Radio");
				//->loc_2349275c
			}
			//loc_23492720
			else if (r1 == 0xffff)
			{
				//0x23492728
				text_table_get_string(0x158/*'Kabel'*/, 
					((Graphic_Job_2_5_Item*)(r4->Data_4[0]))->Data_0x20->pString, 20);
				//->loc_2349275c
			}
			else 
			{
				//loc_2349273a
				/*sub_2340ed78*/sub_2340c29c(&sp4, r1);

				strncpy(((Graphic_Job_2_5_Item*)(r4->Data_4[0]))->Data_0x20->pString,
					&sp4.Data_8[0], 20);
				//->loc_2349275c
			}
		}
		else
		{
			//loc_23492750
			memset(((Graphic_Job_2_5_Item*)(r4->Data_4[0]))->Data_0x20->pString, 
				0, 40);
		}
		//loc_2349275c
		((Graphic_Job_2_5_Item*)(r4->Data_4[0]))->Data_0x20->bData_0x17 = 1;
		r4->Data_4[0]->bData_0x3c = 1;
		//loc_23492772
	} //for (r5 = 0; r5 < sp_0x24.wData_0x26; r5++)
	//0x2349277a
	return 0;
}


/* /  / 23492780 - todo */
uint8_t sub_23492780(void)
{
#if 0
	console_send_string("sub_23492780 (todo.c): TODO\r\n");
#endif

	Channel_Database* pDb;
	int r4 = 0;
	int sp = 0xff;

	pDb = /*sub_234107b0*/sub_2344f770();
	Data_2397275a.Data_23972748 = &pDb->Data_23543df0[0];
	Data_2397275a.Data_2397274c = &pDb->arTransponders[0];
	Data_2397275a.Data_23972750 = &pDb->arChannels[0];

	uint16_t r0 = 0;
	uint16_t r1; //r1 = 0;
	for (r1 = 0; r1 < 6000; r1++)
	{
		//loc_234927a0
		Channel* ip = &Data_2397275a.Data_23972750[r1];

		uint16_t r2 = ip->wTransponderIndex;
		Transponder* r3 = &Data_2397275a.Data_2397274c[r2];
		uint16_t r5 = ip->wFlags_2;

		if (r5 == 0xffff)
		{
			//->loc_23492814
			break;
		}
		//0x234927c4
		int r6 = 0xfffe;
		if ((ip->service_id != 0xfffe) && ((r5 & (1 << 7)) != 0))
		{
			//0x234927d4
			if (r2 != 0xffff)
			{
				//0x234927da
				r6 = r3->Data_0.wData_0x0a;
			}
			//loc_234927dc
			if (r6 != sp)
			{
				//->0x234927e2
				uint8_t r2; //r2 = 0;
				//->loc_234927f4
				for (r2 = 0; r2 < r0; r2++)
				{
					//loc_234927e6
					if (Data_2397275a.arData_23972754[r2] == r6)
					{
						r4 = 1;
						//->loc_23492808
						//goto loc_23492808;
						break;
					}
				} //for (r2 = 0; r2 < r0; r2++)
				//0x234927f8
				if (r4 == 0)
				{
					//0x234927fc
					Data_2397275a.arData_23972754[r0] = r6;
					r0++;
					sp = r6;
				}
				//loc_23492808
loc_23492808:
				r4 = 0;
			}
			//loc_2349280a
		}
		//loc_2349280a
	} //for (uint16_t r1 = 0; r1 < 6000; r1++)
	//loc_23492814
	Data_2397275a.wData_239727b8 = r1;

	return r0;
}


/*  /  / 2349281e - todo */
static int sub_2349281e(Struct_2348dc50* r4)
{
#if 0
	console_send_string("sub_2349281e (todo.c): TODO\r\n");
#endif

	Struct_2348dc50 sp_0x10;
	Graphic_Queue_Item sp;

	sp_0x10 = *r4;

	uint16_t* r2 = NULL;
	uint8_t r3 = 0;
	int r6 = 0;
	uint16_t r7 = r4->wData_0x1e + 1;

	if (sp_0x10.Data_0/*r0*/ == 0x20)
	{
		//0x23492840
		uint8_t r1;
		uint16_t* r0 = &r4->arwData_0x28[0];
		for (r1 = 0; r1 < 20; r1++, r0++)
		{
			//loc_23492846
			uint16_t r5 = r0[0];
			if (r5 != 0)
			{
				//0x2349284c
				r3++;
				//->loc_23492858
			}
			else
			{
				//loc_23492852
				if (r2 == NULL)
				{
					//0x23492856
					r2 = r0;
				}
				//loc_23492858
			}
			//loc_23492858
			if (r5 == r7)
			{
				//0x2349285c
				r0[0] = 0; //r6;

				r4->wData_0x24--;

				return 1;
			}
			//loc_2349286a
		} //for (r1 = 0; r1 < 20; r1++, r0++)
		//0x23492874
		if (r3 < 20)
		{
			//0x23492878
			r4->wData_0x24++;
			r4->Data_0x54 = r2;
			*r2 = r7;
		}
		//->loc_23492910
	} //if (sp_0x10.Data_0/*r0*/ == 0x20)
	//loc_23492884
	else if (sp_0x10.Data_0/*r0*/ == 0x80)
	{
		//0x23492888
		if (r4->wData_0x24 != 0)
		{
			//0x2349288e
			menu_initialize(Data_234c5354);

			graphic_start_job_2_5(&sp, Data_234c5354->graphicData);

			uint8_t r5;
			for (r5 = 0; r5 < 20; r5++)
			{
				//loc_234928a4
				int r0 = r4->arwData_0x28[r5];
				if (r0 != 0)
				{
					//0x234928ae
					r0 = Data_2397275a.arData_23972754[r0 - 1];

					sub_23492a64(r0);
				}
				//loc_234928b8
			} //for (r5 = 0; r5 < 20; r5++)
			//0x234928c0
			graphic_start_job_2_5(&sp, NULL);

			Data_2397275a.bData_239727ba = sub_23492780();

			r4->wData_0x20 = Data_2397275a.bData_239727ba;
			if (r4->wData_0x20 != 0)
			{
				//0x234928da
				if (r4->wData_0x1e >= r4->wData_0x20)
				{
					//0x234928e2
					r4->wData_0x1e = r4->wData_0x20 - 1;
				}
				//loc_234928ea
			}
			else
			{
				//loc_234928e8
				r4->wData_0x1e = 0; //r6;
			}
			//loc_234928ea
			r4->wData_0x22 = r4->wData_0x1e % r4->wData_0x26;
			r4->wData_0x24 = 0;

			uint8_t r0;
			for (r0 = 0; r0 < 20; r0++)
			{
				//loc_234928fa
				r4->arwData_0x28[r0] = 0; //r6
			}
			//0x23492908
			sub_234926c8(r4);

			r4->Data_0x54 = 0; //r6
			//loc_23492910
		} //if (r4->wData_0x24 != 0)
		//loc_23492910
	}
	//loc_23492910
	return 0;
}


/* /  / 23492914 - todo */
static int sub_23492914(int a)
{
#if 0
	console_send_string("sub_23492914 (todo.c): TODO\r\n");
#endif

	Struct_2348dc50 sp4;

	Data_2397275a.bData_239727ba = sub_23492780();

	memset(&sp4, 0, sizeof(Struct_2348dc50));

	sp4.Data_0x60 = /*sub_23410390*/sub_2344f350();
	sp4.pMenu = Data_234ed9bc;
	sp4.Data_0x10 = NULL;
	sp4.wData_0x1c = 0;
	sp4.Data_0x14 = sub_234926c8;
	sp4.Data_0x18 = sub_2348dbf8;
	sp4.Data_0x54 = 0;
	sp4.wData_0x1e = 0;
	sp4.wData_0x22 = 0;
	sp4.wData_0x20 = Data_2397275a.bData_239727ba;
	sp4.bData_0x58 = 10;
	sp4.wData_0x26 = 10;
	sp4.wData_0x24 = 0;
	sp4.bData_0x5c = 7;
	sp4.bData_0x5d = 8;
	sp4.bData_0x5e = 9;
	sp4.bData_0x59 = 2;
	sp4.bData_0x5a = 10;
	sp4.bData_0x5b = 9;

	sub_2348dc50(&sp4);

    return 0;
}


/* /  / 23492980 - todo */
void* sub_23492980(FrontDisplay_Job* r4)
{
#if 1
	console_send_string("sub_23492980 (todo.c): TODO\r\n");
#endif

    //TODO!!!

    return sub_23492980;
}


/* /  / 234929f6 - todo */
int sub_234929f6(int r5)
{
#if 1
	console_send_string("sub_234929f6 (todo.c): TODO\r\n");
#endif

    menu_stack_operate(Data_234ed9bc);
    sub_2348dd36(Data_234ed9bc, 1);
    /*sub_2344de56*/sub_2343d51e(Data_234ed9bc, r5);
#if 0 //TODO!!!
    frontdisplay_start_text(sub_23492980);
#endif

    return 0;
}


/* /  / 23492a1c - todo */
static int sub_23492a1c(UI_Thread_Params* r4)
{
#if 0
	console_send_string("sub_23492a64 (todo.c): TODO\r\n");
#endif

	Struct_2348dc50* r5 = sub_2348dcd2();

	if (/*sub_23410390*/sub_2344f350() != r5->Data_0x60)
	{
		//0x23492a30
		if (r4->Data_20 == 0)
		{
			//0x23492a36
			sub_23454624(4);
			//loc_23492a3c
			return 0;
		}
		else
		{
			//loc_23492a40
			if (0 == sub_234548c2(r4, 4))
			{
				return 1;
			}
			//loc_23492a50
			sub_2348dc9e();
			//->loc_23492a3c
		}
	}
	else
	{
		//loc_23492a50
		sub_2348dc9e();
		//->loc_23492a3c
	}
	//loc_23492a3c
	return 0;
}


/* /  / 23492a64 - todo */
int sub_23492a64(int r7)
{
#if 0
	console_send_string("sub_23492a64 (todo.c): TODO\r\n");
#endif

	uint16_t r4 = 0;
	int sp = 0;

	int r5 = Data_2397275a.wData_239727b8;
	//->loc_23492ae4
	while (--r5)
	{
		//loc_23492a74
		if (r7 == 0xfffe)
		{
			//0x23492a7a
			if (Data_2397275a.Data_23972750[r5].wTransponderIndex == 0xffff)
			{
				//0x23492a8c
				//r0 = 0x23972748 + r4*2;
				//->loc_23492ab0
				Data_2397275a.arData_23972790[r4] = r5;
				r4++;
			}
			//loc_23492ab8
		}
		else
		{
			//loc_23492a92
			int tp = Data_2397275a.Data_23972750[r5].wTransponderIndex;

			if (Data_2397275a.Data_2397274c[tp].Data_0.wData_0x0a == r7)
			{
				//r0 = 0x23972748 + r4*2;
				//loc_23492ab0
				Data_2397275a.arData_23972790[r4] = r5;
				r4++;
			}
			//loc_23492ab8
		}
		//loc_23492ab8
		if (r4 != 0)
		{
			if ((r4 == 20) || (r5 == 0))
			{
				//loc_23492ac4
				sub_23410760(&Data_2397275a.arData_23972790[0], (uint8_t)r4);

				rtos_task_wait(1);

				Data_2397275a.wData_239727b8 -= r4;

				if (r5 > 0)
				{
					//0x23492ae0
					r5 = Data_2397275a.wData_239727b8;
				}
				//loc_23492ae2
				r4 = 0;
			}
			//loc_23492ae4
		}
		//loc_23492ae4
	} //while (r5--)
	//0x23492ae8
	return sp;
}

#endif
