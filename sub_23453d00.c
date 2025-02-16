
#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "menu.h"

#ifndef VDR110

#pragma thumb

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern void* Data_234c1258; //234c1258
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12a4; //234c12a4
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12d4; //234c12d4
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c131c; //234c131c
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c1328; //234c1328
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c1334; //234c1334
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c1340; //234c1340
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c134c; //234c134c

extern void sub_2344f6ac();
static int menu_channel_search_on_enter(int);
static int menu_channel_search_on_exit(UI_Thread_Params*);
static void menu_channel_search_get_antenna_value_string(Menu_Item*);
static int sub_23453d78(void*);
static void menu_channel_search_get_search_mode_string(Menu_Item*);
static void menu_channel_search_get_encryption_mode_string(Menu_Item*);
static void sub_23453fea();

static Menu Data_234c4e7c; //234c4e7c
static uint8_t Data_2379942c[]; //2379942c
static uint8_t Data_23799454[]; //23799454
static uint8_t Data_2379947c[]; //2379947c
static uint8_t Data_237994a4[]; //237994a4
static uint8_t Data_237994cc[]; //237994cc
static uint8_t Data_237994f4[]; //237994f4
static uint8_t Data_2379951c[]; //2379951c
static uint8_t Data_23799544[]; //23799544
static uint8_t Data_2379956c[]; //2379956c
static uint8_t Data_2379960c[]; //2379960c
static uint8_t menu_channel_search_ber_string[]; //234c32d4

//0x234c2f60
static uint16_t wData_234c2f60 = 0x0106; //234C2F60 +0
static void (*Data_234c2f68)() = sub_23453fea; //234C2F68 +8
static Menu* Data_234c2f70 = &Data_234c4e7c; //234C2F70 +0x10

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c2f9c = //234c2f9c
{
	9, 4, 0x0c, //...
#if 0
0x234c2f9c                        dw         0x0009                             ; DATA XREF=sub_234544aa+14, 0x234c3a2c
0x234c2f9e                        dw         0x0000
0x234c2fa0                        dd         0x00000004
0x234c2fa4                        db         0x0c
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c2fa8 = //234c2fa8
{
	9, 4, 0x03, //...
#if 0
0x234c2fa8                        dw         0x0009                             ; DATA XREF=sub_234544aa+16, 0x234c3a6c
0x234c2faa 0000                   movs       r0, r0
0x234c2fac                        dd         0x00000004
0x234c2fb0                        db         0x03
#endif
};

static uint8_t menu_channel_search_qpsk_string[40] = "QPSK"; //234c2fb4
static uint8_t menu_channel_search_fec_string[40] = "FEC"; //234c2fdc

static Graphic_Job_2_5_Item_Text Data_234c3004 = //234c3004
{
	0, 0x01da, 0x00a4, 0x0257, 0x00c0, 0x01, 0x04, 0x09, 0x01, &menu_channel_search_ber_string[0], 0, 0, 0
#if 0
0x234c3004                        db         0x00                               ; DATA XREF=sub_234533bc+318, sub_234533bc+582, dword_23453838+88, dword_23453838+94, dword_23453838+104, sub_234538b0+6, menu_channel_search_on_enter+72, dword_23453c84, 0x234c3934
0x234c3005                        db         0x00
0x234c3006                        dw         0x01da
0x234c3008                        dw         0x00a4                             ; DATA XREF=sub_234533bc+320, sub_234533bc+584, dword_23453838+92
0x234c300a                        dw         0x0257
0x234c300c                        dw         0x00c0
0x234c300e                        db         0x01
0x234c300f                        db         0x04
0x234c3010                        db         0x09
0x234c3011                        db         0x01
0x234c3012 0000                   movs       r0, r0
0x234c3014                        dd         0x234c32d4                         ; "BER: 0"
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c3028 = //234c3028
{
	0x000e, 0, 0x05, //...
#if 0
0x234c3028                        dw         0x000e                             ; DATA XREF=0x234c38ec
0x234c302a                        dw         0x0000
0x234c302c                        dd         0x00000000
0x234c3030                        db         0x05
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c3034 = //234c3034
{
	0, 0x51, 0x2c, 0xfd, 0x4f, 0x01, 0x06, 0x02, 0x00, &Data_2379942c[0], 0, 0, 0
#if 0
0x234c3034                        db         0x00                               ; DATA XREF=0x234c3bb4
0x234c3035                        db         0x00
0x234c3036                        dw         0x0051
0x234c3038                        dw         0x002c
0x234c303a                        dw         0x00fd
0x234c303c                        dw         0x004f
0x234c303e                        db         0x01
0x234c303f                        db         0x06
0x234c3040                        db         0x02
0x234c3041                        db         0x00
0x234c3042 0000                   movs       r0, r0
0x234c3044                        dd         0x2379942c
#endif
};

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

static Graphic_Job_2_5_Item_Text Data_234c3214 = //234c3214
{
	0, 0x0128, 0x0064, 0x01c0, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_2379951c[0], 0, 0, 0
#if 0
0x234c3214                        db         0x00                               ; DATA XREF=0x234c3674
0x234c3215                        db         0x00
0x234c3216                        dw         0x0128
0x234c3218                        dw         0x0064
0x234c321a                        dw         0x01c0
0x234c321c                        dw         0x0080
0x234c321e                        db         0x01
0x234c321f                        db         0x04
0x234c3220                        db         0x09
0x234c3221                        db         0x01
0x234c3222 0000                   movs       r0, r0
0x234c3224                        dd         0x2379951c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c322c = //234c322c
{
	0, 0x0128, 0x0084, 0x01c0, 0x00a0, 0x01, 0x04, 0x09, 0x01, &Data_23799544[0], 0, 0, 0
#if 0
0x234c322c                        db         0x00                               ; DATA XREF=0x234c36b4
0x234c322d                        db         0x00
0x234c322e                        dw         0x0128
0x234c3230                        dw         0x0084
0x234c3232                        dw         0x01c0
0x234c3234                        dw         0x00a0
0x234c3236                        db         0x01
0x234c3237                        db         0x04
0x234c3238                        db         0x09
0x234c3239                        db         0x01
0x234c323a 0000                   movs       r0, r0
0x234c323c                        dd         0x23799544
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c3244 = //234c3244
{
	0, 0x0128, 0x00a4, 0x01c0, 0x00c0, 0x01, 0x04, 0x09, 0x01, &Data_2379956c[0], 0, 0, 0
#if 0
0x234c3244                        db         0x00                               ; DATA XREF=0x234c36f4
0x234c3245                        db         0x00
0x234c3246                        dw         0x0128
0x234c3248                        dw         0x00a4
0x234c324a                        dw         0x01c0
0x234c324c                        dw         0x00c0
0x234c324e                        db         0x01
0x234c324f                        db         0x04
0x234c3250                        db         0x09
0x234c3251                        db         0x01
0x234c3252 0000                   movs       r0, r0
0x234c3254                        dd         0x2379956c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c32a4 = //234c32a4
{
	0, 0x01f8, 0x0064, 0x02d7, 0x0080, 0x01, 0x04, 0x09, 0x01, &menu_channel_search_qpsk_string[0], 0, 0, 0
#if 0
0x234c32a4                        db         0x00                               ; DATA XREF=0x234c3834
0x234c32a5                        db         0x00
0x234c32a6                        dw         0x01f8
0x234c32a8                        dw         0x0064
0x234c32aa                        dw         0x02d7
0x234c32ac                        dw         0x0080
0x234c32ae                        db         0x01
0x234c32af                        db         0x04
0x234c32b0                        db         0x09
0x234c32b1                        db         0x01
0x234c32b2 0000                   movs       r0, r0
0x234c32b4                        dd         0x234c2fb4                         ; "QPSK"
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c32bc = //234c32bc
{
	0, 0x01f8, 0x0084, 0x02d7, 0x00a0, 0x01, 0x04, 0x09, 0x01, &menu_channel_search_fec_string[0], 0, 0, 0
#if 0
0x234c32bc                        db         0x00                               ; DATA XREF=0x234c38b4
0x234c32bd                        db         0x00
0x234c32be                        dw         0x01f8
0x234c32c0                        dw         0x0084
0x234c32c2                        dw         0x02d7
0x234c32c4                        dw         0x00a0
0x234c32c6                        db         0x01
0x234c32c7                        db         0x04
0x234c32c8                        db         0x09
0x234c32c9                        db         0x01
0x234c32ca 0000                   movs       r0, r0
0x234c32cc                        dd         0x234c2fdc
#endif
};

static uint8_t menu_channel_search_ber_string[40] = "BER: 0"; //234c32d4


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

static uint8_t menu_channel_search_cnr_string[40] = "C/N:0 "; //234c3314

static Graphic_Job_2_5_Item_Text Data_234c333c = //234c333c
{
	0, 0x01da, 0x017a, 0x0257, 0x0196, 0x01, 0x04, 0x09, 0x01, &menu_channel_search_cnr_string[0], 0, 0, 0
#if 0
0x234c333c                        db         0x00                               ; DATA XREF=0x234c3a34
0x234c333d                        db         0x00
0x234c333e                        dw         0x01da
0x234c3340                        dw         0x017a
0x234c3342                        dw         0x0257
0x234c3344                        dw         0x0196
0x234c3346                        db         0x01
0x234c3347                        db         0x04
0x234c3348                        db         0x09
0x234c3349                        db         0x01
0x234c334a 0000                   movs       r0, r0
0x234c334c                        dd         0x234c3314                         ; "C/N:0 "
#endif
};

static uint8_t menu_channel_search_signal_level_string[] = "Level:0 "; //234c3354

static Graphic_Job_2_5_Item_Text Data_234c337c = //234c337c
{
	0, 0x01da, 0x015a, 0x0257, 0x0176, 0x01, 0x04, 0x09, 0x01, &menu_channel_search_signal_level_string[0], 0, 0, 0
#if 0
0x234c337c                        db         0x00                               ; DATA XREF=0x234c3a74
0x234c337d                        db         0x00
0x234c337e                        dw         0x01da                             ; CODE XREF=word_234c2d04+296
0x234c3380                        dw         0x015a
0x234c3382                        dw         0x0257
0x234c3384                        dw         0x0176
0x234c3386                        db         0x01
0x234c3387                        db         0x04
0x234c3388                        db         0x09
0x234c3389                        db         0x01
0x234c338a 0000                   movs       r0, r0
0x234c338c                        dd         0x234c3354                         ; "Level:0 "
#endif
};

static Graphic_Job_2_5_Item Data_234c3394[] = //234c3394
{
	{0}, //[0] = 234c3394 
	{0}, //[1] = 234C33D4 
	{0}, //[2] = 234C3414 
	{0}, //[3] = 234C3454 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x60, 0xc0, 0x20, 0, &Data_234c1334/*Data_0x18*/, 9, 0, &Data_234c3184/*Data_0x20*/}, //[4] = 234C3494: Antenne Label
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
	{1, 0, 0, 0/*Data_8*/, 0x114, 0x60, 0xac, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234c3214/*Data_0x20*/}, //[11] = 234C3654: Antenna Value String
#if 0
0x234c3654                        db         0x01                               ; DATA XREF=0x234c4c1c
0x234c3655                        db  0x00 ; '.'
0x234c3656 0000                   movs       r0, r0
0x234c3658 0000                   movs       r0, r0
0x234c365a 0000                   movs       r0, r0
0x234c365c 0000                   movs       r0, r0
0x234c365e 0000                   movs       r0, r0
0x234c3660                        dw         0x0114
0x234c3662                        dw         0x0060
0x234c3664                        dw         0x00ac
0x234c3666                        dw         0x0020
0x234c3668 0000                   movs       r0, r0
0x234c366a 0000                   movs       r0, r0
0x234c366c                        dd         0x234c12d4
0x234c3670                        dw         0x0009
0x234c3672                        dw         0x0000
0x234c3674                        dd         0x234c3214
#endif
	{1, 0, 0, 0/*Data_8*/, 0x114, 0x80, 0xac, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234c322c/*Data_0x20*/}, //[12] = 234C3694 
#if 0
0x234c3694                        db         0x01                               ; DATA XREF=0x234c4c48
0x234c3695                        db         0x00
0x234c3696                        db         0x00
0x234c3697                        db         0x00
0x234c3698                        dd         0x00000000
0x234c369c                        dd         0x00000000
0x234c36a0                        dw         0x0114
0x234c36a2                        dw         0x0080
0x234c36a4                        dw         0x00ac
0x234c36a6                        dw         0x0020
0x234c36a8 0000                   movs       r0, r0
0x234c36aa 0000                   movs       r0, r0
0x234c36ac                        dd         0x234c12d4
0x234c36b0                        dw         0x0009
0x234c36b2                        dw         0x0000
0x234c36b4                        dd         0x234c322c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x114, 0xa0, 0xac, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234c3244/*Data_0x20*/}, //[13] = 234C36D4
#if 0
0x234c36d4                        db         0x01                               ; DATA XREF=0x234c4c74
0x234c36d5                        db         0x00
0x234c36d6                        db         0x00
0x234c36d7                        db         0x00
0x234c36d8                        dd         0x00000000
0x234c36dc                        dd         0x00000000
0x234c36e0                        dw         0x0114
0x234c36e2                        dw         0x00a0
0x234c36e4                        dw         0x00ac
0x234c36e6                        dw         0x0020
0x234c36e8 0000                   movs       r0, r0
0x234c36ea 0000                   movs       r0, r0
0x234c36ec                        dd         0x234c12d4
0x234c36f0                        dw         0x0009
0x234c36f2                        dw         0x0000
0x234c36f4                        dd         0x234c3244
#endif
	{0}, //[14] = 234C3714 
	{0}, //[15] = 234C3754 
	{0}, //[16] = 234C3794 
	{0}, //[17] = 234C37D4 
	{1, 0, 0, 0/*Data_8*/, 0x01d7, 0x0060, 0x0080, 0x0020, 0, &Data_234c1340/*Data_0x18*/, 0x09/*blue*/, 0, &Data_234c32a4/*Data_0x20*/}, //[18] = 234C3814
#if 0
0x234c3814                        db         0x01
0x234c3815                        db         0x00
0x234c3816                        db         0x00
0x234c3817                        db         0x00
0x234c3818                        dd         0x00000000
0x234c381c                        dd         0x00000000
0x234c3820                        dw         0x01d7
0x234c3822                        dw         0x0060
0x234c3824                        dw         0x0080
0x234c3826                        dw         0x0020
0x234c3828 0000                   movs       r0, r0
0x234c382a 0000                   movs       r0, r0
0x234c382c                        dd         0x234c1340
0x234c3830                        dw         0x0009
0x234c3832                        dw         0x0000
0x234c3834                        dd         0x234c32a4
#endif 
	{1, 0, 0, 0/*Data_8*/, 0x01db, 0x0064, 0x0018, 0x0018, 0, &Data_234c3028/*Data_0x18*/, 0x0b/*0x0a = red*/, 0, NULL/*Data_0x20*/}, //[19] = 234C3854
#if 0
0x234c3854                        db         0x01
0x234c3855                        db         0x00
0x234c3856                        db         0x00
0x234c3857                        db         0x00
0x234c3858                        dd         0x00000000
0x234c385c                        dd         0x00000000
0x234c3860                        dw         0x01db
0x234c3862                        dw         0x0064
0x234c3864                        dw         0x0018
0x234c3866                        dw         0x0018
0x234c3868 0000                   movs       r0, r0
0x234c386a 0000                   movs       r0, r0
0x234c386c                        dd         0x234c3028
0x234c3870                        dw         0x000b
#endif 
	{1, 0, 0, 0/*Data_8*/, 0x01d7, 0x0080, 0x0080, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 0x09/*blue*/, 0, &Data_234c32bc/*Data_0x20*/}, //[20] = 234C3894: FEC String
#if 0
0x234c3894                        db         0x01
0x234c3895                        db         0x00
0x234c3896                        db         0x00
0x234c3897                        db         0x00
0x234c3898                        dd         0x00000000
0x234c389c                        dd         0x00000000
0x234c38a0                        dw         0x01d7
0x234c38a2                        dw         0x0080
0x234c38a4                        dw         0x0080
0x234c38a6                        dw         0x0020
0x234c38a8 0000                   movs       r0, r0
0x234c38aa 0000                   movs       r0, r0
0x234c38ac                        dd         0x234c12d4
0x234c38b0                        dw         0x0009
0x234c38b2                        dw         0x0000
0x234c38b4                        dd         0x234c32bc
#endif
	{1, 0, 0, 0/*Data_8*/, 0x01db, 0x0084, 0x0018, 0x0018, 0, &Data_234c3028/*Data_0x18*/, 0x0b/*green*/, 0, NULL/*Data_0x20*/}, //[21] = 234C38D4
#if 0
0x234c38d4                        db         0x01
0x234c38d5                        db         0x00
0x234c38d6                        db         0x00
0x234c38d7                        db         0x00
0x234c38d8                        dd         0x00000000
0x234c38dc                        dd         0x00000000
0x234c38e0                        dw         0x01db
0x234c38e2                        dw         0x0084
0x234c38e4                        dw         0x0018
0x234c38e6                        dw         0x0018
0x234c38e8 0000                   movs       r0, r0
0x234c38ea 0000                   movs       r0, r0
0x234c38ec                        dd         0x234c3028
0x234c38f0                        dw         0x000b
#endif
	{1, 0, 0, 0/*Data_8*/, 0x01d7, 0x00a0, 0x0080, 0x20, 0, &Data_234c1328/*Data_0x18*/, 9, 0, &Data_234c3004/*Data_0x20*/}, //[22] = 234C3914: BER String
#if 0
0x234c3914                        db         0x01
0x234c3915                        db         0x00
0x234c3916                        db         0x00
0x234c3917                        db         0x00
0x234c3918                        dd         0x00000000
0x234c391c                        dd         0x00000000
0x234c3920                        dw         0x01d7
0x234c3922                        dw         0x00a0
0x234c3924                        dw         0x0080
0x234c3926                        dw         0x0020
0x234c3928 0000                   movs       r0, r0
0x234c392a 0000                   movs       r0, r0
0x234c392c                        dd         0x234c1328
0x234c3930                        dw         0x0009
0x234c3932                        dw         0x0000
0x234c3934                        dd         0x234c3004
#endif
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
	{1, 0, 0, 0/*Data_8*/, 0x01d7, 0x0176, 0x0080, 0x20, 0, &Data_234c2f9c/*Data_0x18*/, 9, 0, &Data_234c333c/*Data_0x20*/}, //[26] = 234C3A14: C/N String
#if 0
0x234c3a14                        db         0x01
0x234c3a15                        db         0x00
0x234c3a16                        db         0x00
0x234c3a17                        db         0x00
0x234c3a18                        dd         0x00000000
0x234c3a1c                        dd         0x00000000
0x234c3a20                        dw         0x01d7
0x234c3a22                        dw         0x0176
0x234c3a24                        dw         0x0080
0x234c3a26                        dw         0x0020
0x234c3a28 0000                   movs       r0, r0
0x234c3a2a 0000                   movs       r0, r0
0x234c3a2c                        dd         0x234c2f9c
0x234c3a30                        dw         0x0009
0x234c3a32                        dw         0x0000
0x234c3a34                        dd         0x234c333c
#endif 
	{1, 0, 0, 0/*Data_8*/, 0x01d7, 0x0156, 0x0080, 0x20, 0, &Data_234c2fa8/*Data_0x18*/, 9, 0, &Data_234c337c/*Data_0x20*/}, //[27] = 234C3A54: Signal Level String
#if 0
0x234c3a54                        db         0x01
0x234c3a55                        db         0x00
0x234c3a56                        db         0x00
0x234c3a57                        db         0x00
0x234c3a58                        dd         0x00000000
0x234c3a5c                        dd         0x00000000
0x234c3a60                        dw         0x01d7
0x234c3a62                        dw         0x0156
0x234c3a64                        dw         0x0080
0x234c3a66                        dw         0x0020
0x234c3a68 0000                   movs       r0, r0
0x234c3a6a 0000                   movs       r0, r0
0x234c3a6c                        dd         0x234c2fa8
0x234c3a70                        dw         0x0009
0x234c3a72                        dw         0x0000
0x234c3a74                        dd         0x234c337c
#endif
	{0}, //[28] = 234C3A94 
	{0}, //[29] = 234C3AD4 
	{0}, //[30] = 234C3B14 
	{0}, //[31] = 234C3B54 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x29, 0xc0, 0x26, 0, &Data_234c12a4/*Data_0x18*/, 2, 0, &Data_234c3034/*Data_0x20*/}, //[32] = 234C3B94: header
#if 0
0x234c3b94                        dw         0x0001                             ; DATA XREF=0x234c4e88
0x234c3b96 0000                   movs       r0, r0
0x234c3b98 0000                   movs       r0, r0
0x234c3b9a 0000                   movs       r0, r0
0x234c3b9c 0000                   movs       r0, r0
0x234c3b9e 0000                   movs       r0, r0
0x234c3ba0                        dw         0x003d
0x234c3ba2                        dw         0x0029
0x234c3ba4                        dw         0x00c0
0x234c3ba6                        dw         0x0026
0x234c3ba8 0000                   movs       r0, r0
0x234c3baa 0000                   movs       r0, r0
0x234c3bac                        dd         0x234c12a4
0x234c3bb0 0200                   movs       r2, r0
0x234c3bb2 0000                   movs       r0, r0
0x234c3bb4                        dd         0x234c3034
#endif
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
			&Data_234c3394[11], //234c3654,
		}, //int fill_4[5]; //4
		menu_channel_search_get_antenna_value_string, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
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
0x234c4c2c                        dd         menu_channel_search_get_antenna_value_string+1
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
			&Data_234c3394[12], //234c3694,
		}, //int fill_4[5]; //4
		menu_channel_search_get_search_mode_string, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
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
0x234c4c58                        dd         menu_channel_search_get_search_mode_string+1
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
			&Data_234c3394[13], //234c36d4
		}, //int fill_4[5]; //4
		menu_channel_search_get_encryption_mode_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
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
0x234c4c84                        dd         menu_channel_search_get_encryption_mode_string+1
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
		0, /*&Data_234c3414*/ //Struct_235fdf74_Inner16* help; //16 = 0x10
		&Data_234c4b84, //int graphicData; //20 = 0x14
		6, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		graphic_start_job_2_5, //void (*graphicHandler)(); //0x1c
		menu_items_navigate, //void (*onNavigate)(); //0x20
		menu_channel_search_on_enter, //int (*onEnter)(int); //36 = 0x24
		menu_channel_search_on_exit, //int (*onExit)(UI_Thread_Params*); //0x28
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
0x234c4ea0                        dd         menu_channel_search_on_enter+1
0x234c4ea4                        dd         menu_channel_search_on_exit+1
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


struct Struct_23796d30
{
	Struct_23543df0 Data_23796d30; //23796D30 +0x20
	int Data_23796d50; //23796d50
	Transponder Data_23796d54; //23796d54
	Transponder Data_23796d6c[200]; //23796d6c
	uint16_t wData_2379802c; //2379802c
	uint16_t wData_2379802e; //2379802e
	struct 
	{
		int Data_0; //0
		int Data_4; //4
		int Data_8; //8
	} Data_23798030; //23798030
	void* Data_23798078; //23798078
	Graphic_Queue_Item Data_23798088; //23798088
	void* Data_23798098; //23798098
	uint8_t bData_2379809c; //2379809c
	uint8_t bData_2379809d; //2379809d
	//0x1370
} Data_23796d30; //23796d30  -> 237980A0
struct Struct_23796d30 Data_237980a0; //237980A0 -> 23799410
static User_Settings Data_23799410; //23799410

static uint8_t Data_2379942c[40]; //2379942c
static uint8_t Data_23799454[40]; //23799454
static uint8_t Data_2379947c[40]; //2379947c
static uint8_t Data_237994a4[40]; //237994a4
static uint8_t Data_237994cc[40]; //237994cc
static uint8_t Data_237994f4[40]; //237994f4
static uint8_t Data_2379951c[40]; //2379951c
static uint8_t Data_23799544[40]; //23799544
static uint8_t Data_2379956c[40]; //2379956c, size???
static uint8_t Data_2379960c[40]; //2379960c, size???



/* /  / 23452ac4 */
void sub_23452ac4(uint32_t a, Graphic_Job_2_5_Item* b, int c, int d)
{
#if 1
	console_send_string("sub_23452ac4 (todo.c): TODO\r\n");
#endif

}


/* /  / 23452b1c - todo */
static int sub_23452b1c(Frontend_Measurement* r6)
{
#if 1
	console_send_string("sub_23452b1c (todo.c): TODO\r\n");
#endif

	struct Menu_Data* sp;

	//r5 = 234c2f60
	Graphic_Job_2_5* r4 = Data_234c2f70->graphicData;

	if (sub_2344db54() != Data_234c2f70)
	{
		//->loc_23452baa
		return 0;
	}
	//0x23452b32
	//Graphic_Job_2_5_Item* r0 = r4->pItems;
	//sp_0x10 = &r4->pItems[28];
	//r4 = &r4->pItems[19];
	//sp_0xc =  &r4->pItems[29];
	//r5 = &r4->pItems[21];
	//r3 = &r4->pItems[22]: BER String
	//sp8 = &r4->pItems[30];
	//r1 = &r4->pItems[26]: C/N String
	//r2 = &r4->pItems[27]; Signal Level String
	//sp4 = &&r4->pItems[31];

	//sp_0x1c = r4->pItems[22].Data_0x20->pString;
	//sp_0x18 = r4->pItems[26].Data_0x20->pString;
	//sp_0x14 = r4->pItems[27].Data_0x20->pString;

	r4->pItems[22].Data_0x20->bData_0x17 = 1; //r7
	r4->pItems[26].Data_0x20->bData_0x17 = 1; //r7
	r4->pItems[27].Data_0x20->bData_0x17 = 1; //r7

	sp = sub_2344de8e();
	if (sp->menu_stack[sub_2344de94()]->graphicData->wData_2 == 0x4e)
	{
		//loc_23452baa
		return 0;
	}
	//loc_23452bb0
	//sp_0x20 = 23798070;

	if (0 == sub_2347f098(Data_23796d30.Data_23798078))
	{
		return 0xff;
	}
	//loc_23452bc2
	//r0, #0xb
	//r1, #0xa
	//r2 = r4->pItems[19].wColor;
	if (r6->bLock == 1)
	{
		//0x23452bce
		if (r4->pItems[19].wColor != 0x0b)
		{
			//0x23452bd2
			r4->pItems[19].wColor = 0x0b;
			//->loc_23452bdc
			r4->pItems[19].bData_0x3c = 1; //r7
		}
		//loc_23452be0
	}
	else
	{
		//loc_23452bd6
		if (r4->pItems[19].wColor != 0x0a)
		{
			//0x23452bda
			r4->pItems[19].wColor = 0x0a;
			//->loc_23452bdc
			r4->pItems[19].bData_0x3c = 1; //r7
		}
		//loc_23452be0
	}
	//loc_23452be0
	if (r6->bData_0xb == 0)
	{
		//0x23452be6
		if (r4->pItems[21].wColor != 0x0a)
		{
			//0x23452bec
			r4->pItems[21].wColor = 0x0a; //r1
			//->loc_23452bf8
			r4->pItems[21].bData_0x3c = 1; //r7
		}
		//loc_23452bfc
	}
	else
	{
		//loc_23452bf0
		if (r4->pItems[21].wColor != 0x0b)
		{
			//0x23452bf6
			r4->pItems[21].wColor = 0x0b; //r0
			//loc_23452bf8
			r4->pItems[21].bData_0x3c = 1; //r7
		}
		//loc_23452bfc
	}
	//loc_23452bfc
	if (r6->dwBER < 9000)
	{
		//0x23452c04
		sprintf(/*sp_0x1c*/&r4->pItems[22].Data_0x20->pString[0], "BER: %d ", r6->dwBER);
		//->loc_23452c16
	}
	else
	{
		//loc_23452c0e
		sprintf(/*sp_0x1c*/&r4->pItems[22].Data_0x20->pString[0], "BER: >9000");
	}
	//loc_23452c16
	uint32_t cnr = r6->bSNR;
	if (cnr > 40)
	{
		cnr = 40;
	}
	//loc_23452c1e
	sub_23452ac4(cnr, /*sp_0xc*/&r4->pItems[29], 0x87, 0x28);

	/*sp_0xc*/r4->pItems[29].bData_0x3c = 1; //r7
	/*sp_0x10*/r4->pItems[28].bData_0x3c = 1; //r7

	uint32_t signal_strength = r6->bStrength;
	if (signal_strength > 100)
	{
		signal_strength = 100;
	}
	//loc_23452c40
	sub_23452ac4(signal_strength, /*sp4*/&r4->pItems[31], 0x87, 0x64);

	/*sp4*/r4->pItems[31].bData_0x3c = 1; //r7
	/*sp8*/r4->pItems[30].bData_0x3c = 1; //r7

	sprintf(/*sp_0x18*/&r4->pItems[26].Data_0x20->pString[0], "C/N: %ddB", cnr);

	sprintf(/*sp_0x14*/&r4->pItems[27].Data_0x20->pString[0], "Level: %d%%", signal_strength);

	graphic_start_job_2_5(&Data_23796d30.Data_23798088, Data_234c2f70->graphicData);

	OSSemPost(Data_23796d30.Data_23798078);
	//->loc_23452baa
	return 0;
}


/* /  / 234533bc - todo */
int sub_234533bc(void)
{
#if 1
	console_send_string("sub_234533bc (todo.c): TODO\r\n");
#endif

	return 0;
}


/* /  / 234538b0 - todo */
void sub_234538b0(int a)
{
#if 1
	console_send_string("sub_234538b0 (todo.c): TODO\r\n");
#endif

}


/* /  / 23453a48 - todo */
static int menu_channel_search_on_enter(int a)
{
#if 0
	console_send_string("menu_channel_search_on_enter (todo.c): TODO\r\n");
#endif

	Struct_2340bf0c sp_0x28;
	Channel sp;
	int r5;
	int r4;

	/*sub_2340e9e8*/sub_2340bf0c(&sp_0x28);

	r5 = /*sub_23416808*/sub_2340ee34(main_hFrontend1);
	r4 = /*sub_23416808*/sub_2340ee34(Data_23491db8);

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "menu_channel_search_on_enter: r5=%d, r4=%d\r\n", r5, r4);
		console_send_string(debug_string);
	}
#endif

	/*sub_2340dd08*/sub_2340b22c(0xff);

	channel_handle_user_settings(1, &Data_23799410);

	Data_23796d30.bData_2379809c = 0;
	Data_23796d30.bData_2379809d = 0x1d;

	if (r5 == 1)
	{
		//0x23453a82
		if ((r4 != 2) && (r4 != 6))
		{
			//0x23453a8a
			Data_23796d30.bData_2379809c = 1;
		}
		//loc_23453ab6
	}
	else
	{
		//loc_23453a90
		//r0 = 234C2F60
		if ((r4 == 2) || (r5 == 3))
		{
			//loc_23453a9c
			Data_23796d30.bData_2379809d = 0;
			Data_234c2f70->Data_8->helpStringId = wData_234c2f60;
			//->loc_23453ab6
		}
		else
		{
			//loc_23453aaa
			if ((r5 == 5) && (r4 == 6))
			{
				//0x23453ab2
				Data_23796d30.bData_2379809d = 0;
			}
		}
	}
	//loc_23453ab6
	//r6 = 23796D30
	//r4 = 23798010
	//sp_0x60 = 23798030
	//r7 = 23796D54
	//sp_0x5c = 23796D6C
	if (sp_0x28.wNumChannels != 0)
	{
		//0x23453ada
		/*sub_2340ea70*/sub_2340bf94(sp_0x28.wCurrentChannel, 
			&sp, /*r7*/&Data_23796d30.Data_23796d54);

		if (sp.wTransponderIndex == 0xffff)
		{
			//0x23453aee
			int r0 = 0xffff;
			if (r5 == 1)
			{
				r0 = 1;
				//->loc_23453afc
			}
			else if (r5 != 3)
			{
				r0 = 0;
			}
			Data_23796d30.Data_23796d50 = r0;

			Data_23796d30.wData_2379802e = 
				channel_get_transponder_list(Data_23796d30.Data_23796d50, 
					/*sp_0x5c*/&Data_23796d30.Data_23796d6c[0], 200);

//			memcpy(&Data_23796d30.Data_23796d54, &Data_23796d30.Data_23796d6c[0], sizeof(Transponder))
			Data_23796d30.Data_23796d54 = Data_23796d30.Data_23796d6c[0];
			//0x23453b14
			Data_23796d30.Data_23796d50 = Data_23796d30.Data_23796d54.Data_0.wData_0x0a;
			Data_23796d30.Data_23798030.Data_8 = Data_23796d30.Data_23796d54.Data_0.symbol_rate & 0x01;
			//->loc_23453b68
		} //if (sp.wTransponderIndex == 0xffff)
		else
		{
			//loc_23453b24
			Data_23796d30.Data_23796d50 = Data_23796d30.Data_23796d54.Data_0.wData_0x0a;
			Data_23796d30.Data_23798030.Data_8 = Data_23796d30.Data_23796d54.Data_0.symbol_rate & 0x01;

			Data_23796d30.wData_2379802e = 
				channel_get_transponder_list(Data_23796d30.Data_23796d50, 
					/*sp_0x5c*/&Data_23796d30.Data_23796d6c[0], 200);
			//->loc_23453b68
		}
	} //if (sp_0x28.wNumChannels != 0)
	else
	{
		//loc_23453b3e
		int r0;
		if (r5 == 1)
		{
			r0 = 1;
			//->loc_23453b50
		}
		else if (r5 == 3)
		{
			r0 = 0xffff;
			//->loc_23453b50
		}
		else 
		{
			//loc_23453b4e
			r0 = 0;
		}
		//loc_23453b50
		Data_23796d30.Data_23796d50 = r0;

		Data_23796d30.wData_2379802e = 
			channel_get_transponder_list(Data_23796d30.Data_23796d50, 
				/*sp_0x5c*/&Data_23796d30.Data_23796d6c[0], 200);

//		memcpy(&Data_23796d30.Data_23796d54, &Data_23796d30.Data_23796d6c[0], sizeof(Transponder))
		Data_23796d30.Data_23796d54 = Data_23796d30.Data_23796d6c[0];
	}
	//loc_23453b68
	Data_23796d30.wData_2379802c = 0; //r5

	/*sub_2340ed78*/sub_2340c29c(&Data_23796d30.Data_23796d30, Data_23796d30.Data_23796d50);

	Data_23796d30.Data_23798030.Data_0 = 0; //r5
	//r6 = 23798070
	Data_23796d30.Data_23798030.Data_4 = 1;
	Data_23796d30.Data_23798078 = Data_234c1258;

	sub_234538b0(0);

	Data_237980a0 = Data_23796d30;

	int r0 = sub_234533bc();
	if (r0 == 0)
	{
		//0x23453baa
		Data_23796d30.Data_23798098 = main_hFrontend1;
		//->loc_23453c08
	}
	//loc_23453bb2
	else if (r0 == 1)
	{
		//0x23453bb6
		if (Data_23796d30.Data_23796d54.bData_0x16/*23796d6a*/ == 1)
		{
			//0x23453bc0
			//r0 = Data_23491db8;
			Data_23796d30.Data_23798098 = Data_23491db8;
			//->loc_23453bc6		
		}
		else
		{
			//loc_23453bc4
			Data_23796d30.Data_23798098 = main_hFrontend1;
		}
		int r5; // = 0;
		//->loc_23453be8
		for (r5 = 0; r5 < Data_23796d30.wData_2379802e; r5++)
		{
			//loc_23453bce
			if (0 == memcmp(&Data_23796d30.Data_23796d6c[r5].Data_0, 
						&Data_23796d30.Data_23796d54.Data_0, 0x10))
			{
				//->loc_23453c32
				Data_23796d30.Data_23796d54 = Data_23796d30.Data_23796d6c[r5];

				Data_23796d30.wData_2379802c = r5;
				//->loc_23453bee
				break;
			}
		} //for (r5 = 0; r5 < Data_23796d30.wData_2379802e; r5++)
		//loc_23453bee
		Data_23796d30.Data_23796d54 = Data_23796d30.Data_23796d6c[ Data_23796d30.wData_2379802c ];
		//loc_23453c08
	}
	else
	{
		//loc_23453c14
		Data_23796d30.Data_23798098 = Data_23491db8;

		int r5; // = 0;
		//->loc_23453c4c
		for (r5 = 0; r5 < Data_23796d30.wData_2379802e; r5++)
		{
			//loc_23453c20: TODO!!!
			if (Data_23796d30.Data_23796d6c[r5].Data_0.wData_0x0c == Data_23796d30.Data_23796d54.Data_0.wData_0x0c)
			{
				//->loc_23453c32
				Data_23796d30.Data_23796d54 = Data_23796d30.Data_23796d6c[r5];

				Data_23796d30.wData_2379802c = r5;
				//->loc_23453bee
				break;
			}
		} //for (r5 = 0; r5 < Data_23796d30.wData_2379802e; r5++)
		//loc_23453bee
		Data_23796d30.Data_23796d54 = Data_23796d30.Data_23796d6c[ Data_23796d30.wData_2379802c ];
		//loc_23453c08
	}
	//loc_23453c08
	fe_manager_register_measurement_callback(Data_23796d30.Data_23798098, sub_23452b1c);
	//->0x23453a2c
	return 0;
}


/* /  / 23453c52 - complete */
static int menu_channel_search_on_exit(UI_Thread_Params* a)
{
	Struct_2340bf0c sp_0x28;
	Channel channel;

#if 0
	console_send_string("menu_channel_search_on_exit (todo.c): TODO\r\n");
#endif

	fe_manager_register_measurement_callback(main_hFrontend1, NULL);
	fe_manager_register_measurement_callback(Data_23491db8, NULL);

	/*sub_2340e9e8*/sub_2340bf0c(&sp_0x28);

	channel_start_number(&channel, sp_0x28.wCurrentChannel, sp_0x28.wCurrentChannel);

	return 0;
}



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


/* /  / 23453d36 - todo */
static void menu_channel_search_get_antenna_value_string(Menu_Item* item)
{
	uint8_t* pStr = item->Data_4[1]->Data_0x20->Data_0x10;

#if 0
	console_send_string("menu_channel_search_get_antenna_value_string (todo.c): TODO\r\n");
#endif

	if (Data_23796d30.Data_23796d50 == 0)
	{
		//0x23453d48
		text_table_get_string(0x157/*Terrestrisch*/, pStr, 19);
	}
	//loc_23453d52
	else if (Data_23796d30.Data_23796d50 == 0xffff)
	{
		//0x23453d58
		text_table_get_string(0x158/*Kabel*/, pStr, 19);
	}
	else
	{
		//loc_23453d66
		memcpy(pStr, &Data_23796d30.Data_23796d30.Data_8[0], 20);
	}
	//loc_23453d72
	pStr[19] = 0;
}


/* /  / 23453d78 - todo */
static int sub_23453d78(void* a)
{
#if 1
	console_send_string("sub_23453d78 (todo.c): TODO\r\n");
#endif

	return 0;
}


/* /  / 23453f1a - todo */
static void menu_channel_search_get_search_mode_string(Menu_Item* item)
{
#if 0
	console_send_string("menu_channel_search_get_search_mode_string (todo.c): TODO\r\n");
#endif

	uint8_t* pString = item->Data_4[1]->Data_0x20->Data_0x10;

	switch (Data_23796d30.Data_23798030.Data_0)
	{
		case 0:
			//loc_23453f34
			text_table_get_string(0xc0/*Automatisch*/, pString, 12);
			break;

		case 1:
			//loc_23453f38
			text_table_get_string(0xbf/*Manuell*/, pString, 12);
			break;

		case 2:
			//loc_23453f3c
			text_table_get_string(0x15d/*Netzwerk*/, pString, 12);
			break;

		default:
			//loc_23453f34
			text_table_get_string(0xc0/*Automatisch*/, pString, 12);
			break;
	}

	pString[12] = 0;
}


/* /  / 23453fa8 - todo */
void menu_channel_search_get_encryption_mode_string(Menu_Item* item)
{
#if 0
	console_send_string("menu_channel_search_get_encryption_mode_string (todo.c): TODO\r\n");
#endif

	uint8_t* pString = item->Data_4[1]->Data_0x20->Data_0x10;
	int nStr;

	switch (Data_23796d30.Data_23798030.Data_4)
	{
		case 0:
			//loc_23453fbc
			nStr = 0x6e/*Ja*/;
			break;

		case 1:
			//loc_23453fc0
			nStr = 0x6f/*Nein*/;
			break;

		default:
			//loc_23453fbc
			nStr = 0x6e/*Ja*/;
			break;
	}

	text_table_get_string(nStr, pString, 8);
	pString[7] = 0;
}


/* /  / 23453fea */
static void sub_23453fea()
{
#if 1
	console_send_string("sub_23453fea (todo.c): TODO\r\n");
#endif

}


#endif
