
#include "data.h"
#include "graphic.h"
#include "menu.h"

#pragma thumb

#ifndef VDR110

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern Graphic_Job_2_5_Item_Background Data_234c12a4; //234c12a4
extern Graphic_Job_2_5_Item_Background Data_234c12d4; //234c12d4
extern Graphic_Job_2_5_Item_Background Data_234c131c; //234c131c
extern Graphic_Job_2_5_Item_Background Data_234c1328; //234c1328
extern Graphic_Job_2_5_Item_Background Data_234c1334; //234c1334
extern Graphic_Job_2_5_Item_Background Data_234c1340; //234c1340

extern void menu_item_event_thread();

static int video_signal_analog_change(uint32_t*);
static void get_video_signal_analog_value_string(Menu_Item*);
static int video_signal_digital_change(uint32_t*);
static void get_video_signal_digital_value_string(Menu_Item*);
static int menu_display_adjustment_change();
static void get_display_adjustment_value_string(Menu_Item*);
static void get_display_format_value_string(Menu_Item*);
static void get_video_system_value_string(Menu_Item*);
static void sub_23492c4a(Menu_Item*);
static void sub_23492c78(Menu_Item*);
static void sub_23492ca6(Menu_Item*);
static int sub_23492e6c(uint32_t*);
static int sub_23492ec0(uint32_t*);
static int sub_23492f14(uint32_t*);
static int video_system_change(uint32_t*);
static int display_format_change();
static int menu_picture_on_enter(void);
static int menu_picture_on_exit(UI_Thread_Params*);

static Menu menu_picture;
static uint8_t menu_picture_header_string[];
static uint8_t Data_23972c20[];
static uint8_t video_signal_analog_caption_string[];
static uint8_t video_signal_digital_caption_string[];
static uint8_t display_format_caption_string[];
static uint8_t display_adjustment_caption_string[];
static uint8_t Data_23972db8[];
static uint8_t Data_23972de0[];
static uint8_t Data_23972e08[];
static uint8_t Data_23972e30[];
static uint8_t Data_23972e58[];
static uint8_t video_signal_analog_value_string[];
static uint8_t video_signal_digital_value_string[];
static uint8_t display_format_value_string[];
static uint8_t display_adjustment_value_string[];
static uint8_t Data_23972f20[];
static uint8_t Data_23972f48[]; 
static uint8_t Data_23972f70[];
static uint8_t Data_23972f98[];

static Menu* menu_picture_p = &menu_picture; //234eed24

static Graphic_Job_2_5_Item_Text Data_234eed30 = //234eed30
{
	0, 0x0051, 0x002c, 0x0127, 0x004f, 0x01, 0x06, 0x02, 0x00, &menu_picture_header_string[0], 0, 0, 0
#if 0
0x234eed30                        db         0x00                               ; DATA XREF=0x234ef4d8, 0x234efb18
0x234eed31                        db  0x00 ; '.'
0x234eed32                        dw         0x0051
0x234eed34                        dw         0x002c
0x234eed36                        dw         0x0127
0x234eed38                        dw         0x004f
0x234eed3a                        db         0x01
0x234eed3b                        db         0x06
0x234eed3c                        db         0x02
0x234eed3d                        db         0x00
0x234eed3e 0000                   movs       r0, r0
0x234eed40                        dd         0x23972bf8
0x234eed44                        dw         0x0000
0x234eed46                        db         0x00
0x234eed47                        db         0x00
#endif
};

#if 0
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

static Graphic_Job_2_5_Item_Text Data_234eed60 = //234eed60
{
	0, 0x0051, 0x0064, 0x012a, 0x0080, 0x01, 0x04, 0x09, 0x01, &video_signal_analog_caption_string[0], 0, 0
#if 0
0x234eed60                        db         0x00                               ; CODE XREF=dword_234ee604+264, DATA XREF=0x234ef018
0x234eed61                        db  0x00 ; '.'
0x234eed62                        dw         0x0051
0x234eed64                        dw         0x0064
0x234eed66                        dw         0x012a
0x234eed68                        dw         0x0080
0x234eed6a                        db         0x01
0x234eed6b                        db         0x04
0x234eed6c                        db         0x09
0x234eed6d                        db         0x01
0x234eed6e 0000                   movs       r0, r0
0x234eed70                        dd         0x23972d18
0x234eed74 0000                   movs       r0, r0
0x234eed76 0000                   movs       r0, r0
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eed78 = //234eed78
{
	0, 0x0051, 0x0084, 0x012a, 0x00a0, 0x01, 0x04, 0x09, 0x01, &video_signal_digital_caption_string[0], //Data_0x10
#if 0
0x234eed78                        db         0x00                               ; DATA XREF=0x234ef058
0x234eed79                        db  0x00 ; '.'
0x234eed7a                        dw         0x0051
0x234eed7c                        dw         0x0084
0x234eed7e                        dw         0x012a
0x234eed80                        dw         0x00a0
0x234eed82                        db         0x01
0x234eed83                        db         0x04
0x234eed84                        db         0x09
0x234eed85                        db         0x01
0x234eed86 0000                   movs       r0, r0
0x234eed88                        dd         0x23972d40
0x234eed8c 0000                   movs       r0, r0
0x234eed8e 0000                   movs       r0, r0
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eed90 = //234eed90
{
	0, 0x0051, 0x00a4, 0x012a, 0x00c0, 0x01, 0x04, 0x09, 0x01, &display_format_caption_string[0], //Data_0x10
#if 0
0x234eed90                        db         0x00                               ; DATA XREF=0x234ef098
0x234eed91                        db         0x00
0x234eed92                        dw         0x0051
0x234eed94                        dw         0x00a4
0x234eed96                        dw         0x012a
0x234eed98                        dw         0x00c0
0x234eed9a                        db         0x01
0x234eed9b                        db         0x04
0x234eed9c                        db         0x09
0x234eed9d                        db         0x01
0x234eed9e 0000                   movs       r0, r0
0x234eeda0                        dd         0x23972d68
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eeda8 = //234eeda8
{
	0, 0x0051, 0x00c4, 0x012a, 0x00e0, 0x01, 0x04, 0x09, 0x01, &display_adjustment_caption_string[0], //Data_0x10
#if 0
0x234eeda8                        db         0x00                               ; DATA XREF=0x234ef0d8
0x234eeda9                        db         0x00
0x234eedaa                        dw         0x0051
0x234eedac                        dw         0x00c4                             ; DATA XREF=dword_234ee734+1428
0x234eedae                        dw         0x012a
0x234eedb0                        dw         0x00e0
0x234eedb2                        db         0x01
0x234eedb3                        db         0x04
0x234eedb4                        db         0x09
0x234eedb5                        db         0x01
0x234eedb6 0000                   movs       r0, r0
0x234eedb8                        dd         0x23972d90
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eedc0 = //234eedc0
{
	0, 0x0051, 0x00e4, 0x012a, 0x0100, 0x01, 0x04, 0x09, 0x01, &Data_23972db8[0], //Data_0x10
#if 0
0x234eedc0                        db         0x00                               ; DATA XREF=0x234ef118
0x234eedc1                        db         0x00
0x234eedc2                        dw         0x0051
0x234eedc4                        dw         0x00e4
0x234eedc6                        dw         0x012a
0x234eedc8                        dw         0x0100
0x234eedca                        db         0x01
0x234eedcb                        db         0x04
0x234eedcc                        db         0x09
0x234eedcd                        db         0x01
0x234eedce 0000                   movs       r0, r0
0x234eedd0                        dd         0x23972db8
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eedf0 = //234eedf0
{
	0, 0x0051, 0x0124, 0x012a, 0x0140, 0x01, 0x04, 0x09, 0x01, &Data_23972e08[0], //Data_0x10
#if 0
0x234eedf0                        db         0x00                               ; DATA XREF=0x234ef198
0x234eedf1                        db         0x00
0x234eedf2                        dw         0x0051
0x234eedf4                        dw         0x0124
0x234eedf6                        dw         0x012a
0x234eedf8                        dw         0x0140
0x234eedfa                        db         0x01
0x234eedfb                        db         0x04
0x234eedfc                        db         0x09
0x234eedfd                        db         0x01
0x234eedfe 0000                   movs       r0, r0
0x234eee00                        dd         0x23972e08
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eee08 = //234eee08
{
	0, 0x0051, 0x0144, 0x012a, 0x0160, 0x01, 0x04, 0x09, 0x01, &Data_23972e30[0], 
#if 0
0x234eee08                        db         0x00                               ; DATA XREF=0x234ef1d8
0x234eee09                        db  0x00 ; '.'
0x234eee0a                        dw         0x0051
0x234eee0c                        dw         0x0144
0x234eee0e                        dw         0x012a
0x234eee10                        dw         0x0160
0x234eee12                        db         0x01
0x234eee13                        db         0x04
0x234eee14                        db         0x09
0x234eee15                        db         0x01
0x234eee16 0000                   movs       r0, r0
0x234eee18                        dd         0x23972e30
0x234eee1c                        dw         0x0000
0x234eee1e                        dw         0x0000
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eee20 = //234eee20
{
	0, 0x0051, 0x0164, 0x012a, 0x0180, 0x01, 0x04, 0x09, 0x01, &Data_23972e58[0], 
#if 0
0x234eee20                        db         0x00                               ; DATA XREF=0x234ef218
0x234eee21                        db         0x00
0x234eee22                        dw         0x0051
0x234eee24                        dw         0x0164
0x234eee26                        dw         0x012a
0x234eee28                        dw         0x0180
0x234eee2a                        db         0x01
0x234eee2b                        db         0x04
0x234eee2c                        db         0x09
0x234eee2d                        db         0x01
0x234eee2e 0000                   movs       r0, r0
0x234eee30                        dd         0x23972e58
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eee38 = //234eee38
{
	0, 0x0155, 0x0064, 0x022e, 0x0080, 1, 4, 9, 1, &video_signal_analog_value_string[0], 0, 0, 0
#if 0
0x234eee38                        db         0x00                               ; DATA XREF=0x234ef298
0x234eee39                        db  0x00 ; '.'
0x234eee3a                        dw         0x0155
0x234eee3c                        dw         0x0064
0x234eee3e                        dw         0x022e
0x234eee40                        dw         0x0080
0x234eee42                        db         0x01
0x234eee43                        db         0x04
0x234eee44                        db         0x09
0x234eee45                        db         0x01
0x234eee46 0000                   movs       r0, r0
0x234eee48                        dd         0x23972e80
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eee50 = //234eee50
{
	0, 0x0155, 0x0084, 0x022e, 0x00a0, 1, 4, 9, 1, &video_signal_digital_value_string[0], 0, 0, 0
#if 0
0x234eee50                        db         0x00                               ; DATA XREF=0x234ef2d8
0x234eee51                        db         0x00
0x234eee52                        dw         0x0155
0x234eee54                        dw         0x0084
0x234eee56                        dw         0x022e
0x234eee58                        dw         0x00a0
0x234eee5a                        db         0x01
0x234eee5b                        db         0x04
0x234eee5c                        db         0x09
0x234eee5d                        db         0x01
0x234eee5e 0000                   movs       r0, r0
0x234eee60                        dd         0x23972ea8
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eee68 = //234eee68
{
	0, 0x0155, 0x00a4, 0x022e, 0x00c0, 1, 4, 9, 1, &display_format_value_string[0], 0, 0, 0
#if 0
0x234eee68                        db         0x00                               ; DATA XREF=0x234ef318
0x234eee69                        db         0x00
0x234eee6a                        dw         0x0155
0x234eee6c                        dw         0x00a4
0x234eee6e                        dw         0x022e
0x234eee70                        dw         0x00c0
0x234eee72                        db         0x01
0x234eee73                        db         0x04
0x234eee74                        db         0x09
0x234eee75                        db         0x01
0x234eee76 0000                   movs       r0, r0
0x234eee78                        dd         0x23972ed0
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eee80 = //234eee80
{
	0, 0x0155, 0x00c4, 0x022e, 0x00e0, 1, 4, 9, 1, &display_adjustment_value_string[0], 0, 0, 0
#if 0
0x234eee80                        db         0x00                               ; DATA XREF=0x234ef358
0x234eee81                        db         0x00
0x234eee82                        dw         0x0155
0x234eee84                        dw         0x00c4
0x234eee86                        dw         0x022e
0x234eee88                        dw         0x00e0
0x234eee8a                        db         0x01
0x234eee8b                        db         0x04
0x234eee8c                        db         0x09
0x234eee8d                        db         0x01
0x234eee8e 0000                   movs       r0, r0
0x234eee90                        dd         0x23972ef8
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eee98 = //234eee98
{
	0, 0x0155, 0x00e4, 0x022e, 0x0100, 1, 4, 9, 1, &Data_23972f20[0], 0, 0, 0
#if 0
0x234eee98                        db         0x00                               ; DATA XREF=0x234ef398
0x234eee99                        db         0x00
0x234eee9a                        dw         0x0155
0x234eee9c                        dw         0x00e4
0x234eee9e                        dw         0x022e
0x234eeea0                        dw         0x0100
0x234eeea2                        db         0x01
0x234eeea3                        db         0x04
0x234eeea4                        db         0x09
0x234eeea5                        db         0x01
0x234eeea6 0000                   movs       r0, r0
0x234eeea8                        dd         0x23972f20
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eeeb0 = //234eeeb0
{
	0, 0x0155, 0x0124, 0x022e, 0x0140, 1, 4, 9, 1, &Data_23972f48[0], 0, 0, 0
#if 0
0x234eeeb0                        db         0x00                               ; DATA XREF=0x234ef418
0x234eeeb1                        db         0x00
0x234eeeb2                        dw         0x0155
0x234eeeb4                        dw         0x0124
0x234eeeb6                        dw         0x022e
0x234eeeb8                        dw         0x0140
0x234eeeba                        db         0x01
0x234eeebb                        db         0x04
0x234eeebc                        db         0x09
0x234eeebd                        db         0x01
0x234eeebe 0000                   movs       r0, r0
0x234eeec0                        dd         0x23972f48
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eeec8 = //234eeec8
{
	0, 0x0155, 0x0144, 0x022e, 0x0160, 0x01, 0x04, 0x09, 0x01, &Data_23972f70[0]
#if 0
0x234eeec8                        db         0x00                               ; DATA XREF=0x234ef458
0x234eeec9                        db  0x00 ; '.'
0x234eeeca                        dw         0x0155
0x234eeecc                        dw         0x0144
0x234eeece                        dw         0x022e
0x234eeed0                        dw         0x0160
0x234eeed2                        db         0x01
0x234eeed3                        db         0x04
0x234eeed4                        db         0x09
0x234eeed5                        db         0x01
0x234eeed6 0000                   movs       r0, r0
0x234eeed8                        dd         0x23972f70
0x234eeedc 0000                   movs       r0, r0
0x234eeede 0000                   movs       r0, r0
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eeee0 = //234eeee0
{
	0, 0x0155, 0x0164, 0x022e, 0x0180, 0x01, 0x04, 0x09, 0x01, &Data_23972f98[0]
#if 0
0x234eeee0                        db         0x00                               ; DATA XREF=0x234ef498
0x234eeee1                        db         0x00
0x234eeee2                        dw         0x0155
0x234eeee4                        dw         0x0164
0x234eeee6                        dw         0x022e
0x234eeee8                        dw         0x0180
0x234eeeea                        db         0x01
0x234eeeeb                        db         0x04
0x234eeeec                        db         0x09
0x234eeeed                        db         0x01
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

static Graphic_Job_2_5_Item Data_234eeef8[25] = //234eeef8
{
	{0}, //[0] = 234eeef8
	{0}, //[1] = 234EEF38
	{0}, //[2] = 234EEF78
	{0}, //[3] = 234EEFB8
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x60, 0xed, 0x20, 0, &Data_234c1334/*Data_0x18*/, 9, 0, &Data_234eed60, {0}, 0}, //[4] = 234EEFF8 = Item 0 (Videosignal - Analog) = Caption
#if 0
0x234eeff8                        db         0x01                               ; DATA XREF=0x234efbc4
0x234eeff9                        db         0x00
0x234eeffa 0000                   movs       r0, r0
0x234eeffc 0000                   movs       r0, r0
0x234eeffe 0000                   movs       r0, r0
0x234ef000                        dd         0x00000000
0x234ef004                        dw         0x003d
0x234ef006                        dw         0x0060
0x234ef008                        dw         0x00ed
0x234ef00a                        dw         0x0020
0x234ef00c 0000                   movs       r0, r0
0x234ef00e 0000                   movs       r0, r0
0x234ef010                        dd         0x234c1334
0x234ef014                        dw         0x0009
0x234ef016                        dw         0x0000
0x234ef018                        dd         0x234eed60
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x80, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eed78, {0}, 0}, //[5] = 234EF038
#if 0
0x234ef038                        db         0x01                               ; DATA XREF=0x234efbf0
0x234ef039                        db  0x00 ; '.'
0x234ef03a 0000                   movs       r0, r0
0x234ef03c 0000                   movs       r0, r0
0x234ef03e 0000                   movs       r0, r0
0x234ef040                        dd         0x00000000
0x234ef044                        dw         0x003d
0x234ef046                        dw         0x0080
0x234ef048                        dw         0x00ed
0x234ef04a                        dw         0x0020
0x234ef04c 0000                   movs       r0, r0
0x234ef04e 0000                   movs       r0, r0
0x234ef050                        dd         0x234c12d4
0x234ef054                        dw         0x0009
0x234ef056                        dw         0x0000
0x234ef058                        dd         0x234eed78
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xa0, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eed90, {0}, 0}, //[6] = 234EF078
#if 0
0x234ef078                        db         0x01                               ; DATA XREF=0x234efc1c
0x234ef079                        db  0x00 ; '.'
0x234ef07a 0000                   movs       r0, r0
0x234ef07c 0000                   movs       r0, r0
0x234ef07e 0000                   movs       r0, r0
0x234ef080 0000                   movs       r0, r0
0x234ef082 0000                   movs       r0, r0
0x234ef084                        dw         0x003d
0x234ef086                        dw         0x00a0
0x234ef088                        dw         0x00ed
0x234ef08a                        dw         0x0020
0x234ef08c 0000                   movs       r0, r0
0x234ef08e 0000                   movs       r0, r0
0x234ef090                        dd         0x234c12d4
0x234ef094                        dw         0x0009
0x234ef096 0000                   movs       r0, r0
0x234ef098                        dd         0x234eed90
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xc0, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eeda8, {0}, 0}, //[7] = 234EF0B8 = Item 3 (Bildanpassung) = Caption
#if 0
0x234ef0b8                        db         0x01                               ; DATA XREF=0x234efc48
0x234ef0b9                        db  0x00 ; '.'
0x234ef0ba 0000                   movs       r0, r0
0x234ef0bc 0000                   movs       r0, r0
0x234ef0be 0000                   movs       r0, r0
0x234ef0c0 0000                   movs       r0, r0
0x234ef0c2 0000                   movs       r0, r0
0x234ef0c4                        dw         0x003d
0x234ef0c6                        dw         0x00c0
0x234ef0c8                        dw         0x00ed
0x234ef0ca                        dw         0x0020
0x234ef0cc 0000                   movs       r0, r0
0x234ef0ce 0000                   movs       r0, r0
0x234ef0d0                        dd         0x234c12d4
0x234ef0d4 0900                   movs       r1, r1
0x234ef0d6 0000                   movs       r0, r0
0x234ef0d8                        dd         0x234eeda8
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xe0, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eedc0, {0}, 0}, //[8] = 234EF0F8: "Videosystem" Caption
#if 0
0x234ef0f8                        dw         0x0001                             ; DATA XREF=0x234efc74
0x234ef0fa 0000                   movs       r0, r0
0x234ef0fc 0000                   movs       r0, r0
0x234ef0fe 0000                   movs       r0, r0
0x234ef100 0000                   movs       r0, r0
0x234ef102 0000                   movs       r0, r0
0x234ef104                        dw         0x003d
0x234ef106                        dw         0x00e0
0x234ef108                        dw         0x00ed
0x234ef10a                        dw         0x0020
0x234ef10c 0000                   movs       r0, r0
0x234ef10e 0000                   movs       r0, r0
0x234ef110                        dd         0x234c12d4
0x234ef114                        dw         0x0009
0x234ef116 0000                   movs       r0, r0
0x234ef118                        dd         0x234eedc0
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x100, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eedd8, {0}, 0}, //[9] = 234EF138 = Item ? (Bildskalierung:)
#if 0
0x234ef138                        db         0x01
0x234ef139                        db         0x00
0x234ef13a 0000                   movs       r0, r0
0x234ef13c 0000                   movs       r0, r0
0x234ef13e 0000                   movs       r0, r0
0x234ef140                        dd         0x00000000
0x234ef144                        dw         0x003d
0x234ef146                        dw         0x0100
0x234ef148                        dw         0x00ed
0x234ef14a                        dw         0x0020
0x234ef14c 0000                   movs       r0, r0
0x234ef14e 0000                   movs       r0, r0
0x234ef150                        dd         0x234c12d4
0x234ef154                        dw         0x0009
0x234ef156                        dw         0x0000
0x234ef158                        dd         0x234eedd8
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x120, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eedf0, {0}, 0}, //[10] = 234EF178 = Item 5 ( >Eingang 720x576) = Caption
#if 0
0x234ef178                        db         0x01                               ; DATA XREF=0x234efca0
0x234ef179                        db         0x00
0x234ef17a 0000                   movs       r0, r0
0x234ef17c 0000                   movs       r0, r0
0x234ef17e 0000                   movs       r0, r0
0x234ef180 0000                   movs       r0, r0
0x234ef182 0000                   movs       r0, r0
0x234ef184                        dw         0x003d
0x234ef186                        dw         0x0120
0x234ef188                        dw         0x00ed
0x234ef18a                        dw         0x0020
0x234ef18c 0000                   movs       r0, r0
0x234ef18e 0000                   movs       r0, r0
0x234ef190                        dd         0x234c12d4
0x234ef194                        dw         0x0009
0x234ef196 0000                   movs       r0, r0
0x234ef198                        dd         0x234eedf0
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x140, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eee08, {0}, 0}, //[11] = 234EF1B8
#if 0
0x234ef1b8                        db         0x01                               ; DATA XREF=0x234efccc
0x234ef1b9                        db  0x00 ; '.'
0x234ef1ba 0000                   movs       r0, r0
0x234ef1bc 0000                   movs       r0, r0
0x234ef1be 0000                   movs       r0, r0
0x234ef1c0                        dd         0x00000000
0x234ef1c4                        dw         0x003d
0x234ef1c6                        dw         0x0140                             ; CODE XREF=dword_234ee734+1344
0x234ef1c8                        dw         0x00ed
0x234ef1ca                        dw         0x0020
0x234ef1cc 0000                   movs       r0, r0
0x234ef1ce 0000                   movs       r0, r0
0x234ef1d0                        dd         0x234c12d4
0x234ef1d4                        dw         0x0009
0x234ef1d6                        dw         0x0000
0x234ef1d8                        dd         0x234eee08
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x160, 0xed, 0x20, 0, &Data_234c131c/*Data_0x18*/, 9, 0, &Data_234eee20, {0}, 0}, //[12] = 234EF1F8 = Item 7 (' >Eingang 1920x1080') = Caption
#if 0
0x234ef1f8                        db         0x01                               ; DATA XREF=0x234efcf8
0x234ef1f9                        db  0x00 ; '.'
0x234ef1fa 0000                   movs       r0, r0
0x234ef1fc 0000                   movs       r0, r0
0x234ef1fe 0000                   movs       r0, r0
0x234ef200 0000                   movs       r0, r0
0x234ef202 0000                   movs       r0, r0
0x234ef204                        dw         0x003d
0x234ef206                        dw         0x0160
0x234ef208                        dw         0x00ed
0x234ef20a                        dw         0x0020
0x234ef20c 0000                   movs       r0, r0
0x234ef20e 0000                   movs       r0, r0
0x234ef210                        dd         0x234c131c
0x234ef214                        dw         0x0009
0x234ef216 0000                   movs       r0, r0
0x234ef218                        dd         0x234eee20
#endif
	{0}, //[13] = 234EF238
	{1, 0, 0, 0/*Data_8*/, 0x0141, 0x0060, 0xed, 0x20, 0, &Data_234c1340/*Data_0x18*/, 9, 0, &Data_234eee38, {0}, 0}, //[14] = 234EF278 = Item 0 (Videosignal - Analog) = Value
#if 0
0x234ef278                        db         0x01                               ; DATA XREF=0x234efbc8
0x234ef279                        db  0x00 ; '.'
0x234ef27a 0000                   movs       r0, r0
0x234ef27c 0000                   movs       r0, r0
0x234ef27e 0000                   movs       r0, r0
0x234ef280                        dd         0x00000000
0x234ef284                        dw         0x0141
0x234ef286                        dw         0x0060
0x234ef288                        dw         0x00ed
0x234ef28a                        dw         0x0020
0x234ef28c 0000                   movs       r0, r0
0x234ef28e 0000                   movs       r0, r0
0x234ef290                        dd         0x234c1340
0x234ef294                        dw         0x0009
0x234ef296                        dw         0x0000
0x234ef298                        dd         0x234eee38
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0141, 0x0080, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eee50, {0}, 0}, //[15] = 234EF2B8
#if 0
0x234ef2b8                        db         0x01                               ; DATA XREF=0x234efbf4
0x234ef2b9                        db  0x00 ; '.'
0x234ef2ba 0000                   movs       r0, r0
0x234ef2bc 0000                   movs       r0, r0
0x234ef2be 0000                   movs       r0, r0
0x234ef2c0 0000                   movs       r0, r0
0x234ef2c2 0000                   movs       r0, r0
0x234ef2c4                        dw         0x0141
0x234ef2c6                        dw         0x0080
0x234ef2c8                        dw         0x00ed
0x234ef2ca                        dw         0x0020
0x234ef2cc 0000                   movs       r0, r0
0x234ef2ce 0000                   movs       r0, r0
0x234ef2d0                        dd         0x234c12d4
0x234ef2d4                        dw         0x0009
0x234ef2d6 0000                   movs       r0, r0
0x234ef2d8                        dd         0x234eee50
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0141, 0x00a0, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eee68, {0}, 0}, //[16] = 234EF2F8
#if 0
0x234ef2f8                        db         0x01                               ; DATA XREF=0x234efc20
0x234ef2f9                        db  0x00 ; '.'
0x234ef2fa 0000                   movs       r0, r0
0x234ef2fc 0000                   movs       r0, r0
0x234ef2fe 0000                   movs       r0, r0
0x234ef300 0000                   movs       r0, r0
0x234ef302 0000                   movs       r0, r0
0x234ef304                        dw         0x0141
0x234ef306                        dw         0x00a0
0x234ef308                        dw         0x00ed
0x234ef30a                        dw         0x0020
0x234ef30c 0000                   movs       r0, r0
0x234ef30e 0000                   movs       r0, r0
0x234ef310                        dd         0x234c12d4
0x234ef314                        dw         0x0009
0x234ef316 0000                   movs       r0, r0
0x234ef318                        dd         0x234eee68
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0141, 0x00c0, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eee80, {0}, 0}, //[17] = 234EF338 = Item 3 (Bildanpassung) = Value
#if 0
0x234ef338                        db         0x01                               ; DATA XREF=0x234efc4c
0x234ef339                        db  0x00 ; '.'
0x234ef33a 0000                   movs       r0, r0
0x234ef33c 0000                   movs       r0, r0
0x234ef33e 0000                   movs       r0, r0
0x234ef340 0000                   movs       r0, r0
0x234ef342 0000                   movs       r0, r0
0x234ef344                        dw         0x0141
0x234ef346                        dw         0x00c0
0x234ef348                        dw         0x00ed
0x234ef34a                        dw         0x0020
0x234ef34c 0000                   movs       r0, r0
0x234ef34e 0000                   movs       r0, r0
0x234ef350                        dd         0x234c12d4
0x234ef354 0900                   movs       r1, r1
0x234ef356 0000                   movs       r0, r0
0x234ef358                        dd         0x234eee80
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0141, 0x00e0, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eee98, {0}, 0}, //[18] = 234EF378
#if 0
0x234ef378                        db         0x01                               ; DATA XREF=0x234efc78
0x234ef379                        db  0x00 ; '.'
0x234ef37a 0000                   movs       r0, r0
0x234ef37c 0000                   movs       r0, r0
0x234ef37e 0000                   movs       r0, r0
0x234ef380 0000                   movs       r0, r0
0x234ef382 0000                   movs       r0, r0
0x234ef384                        dw         0x0141
0x234ef386                        dw         0x00e0
0x234ef388                        dw         0x00ed
0x234ef38a                        dw         0x0020
0x234ef38c 0000                   movs       r0, r0
0x234ef38e 0000                   movs       r0, r0
0x234ef390                        dd         0x234c12d4
0x234ef394                        dw         0x0009
0x234ef396 0000                   movs       r0, r0
0x234ef398                        dd         0x234eee98
#endif
	{0}, //[19] = 234EF3B8
	{1, 0, 0, 0/*Data_8*/, 0x0141, 0x0120, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eeeb0, {0}, 0}, //[20] = 234ef3f8
#if 0
0x234ef3f8                        db         0x01                               ; DATA XREF=0x234efca4
0x234ef3f9                        db  0x00 ; '.'
0x234ef3fa 0000                   movs       r0, r0
0x234ef3fc 0000                   movs       r0, r0
0x234ef3fe 0000                   movs       r0, r0
0x234ef400 0000                   movs       r0, r0
0x234ef402 0000                   movs       r0, r0
0x234ef404                        dw         0x0141
0x234ef406                        dw         0x0120
0x234ef408                        dw         0x00ed
0x234ef40a                        dw         0x0020
0x234ef40c 0000                   movs       r0, r0
0x234ef40e 0000                   movs       r0, r0
0x234ef410                        dd         0x234c12d4
0x234ef414                        dw         0x0009
0x234ef416 0000                   movs       r0, r0
0x234ef418                        dd         0x234eeeb0
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0141, 0x0140, 0xed, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eeec8, {0}, 0}, //[21] = 234EF438
#if 0
0x234ef438                        db         0x01                               ; DATA XREF=0x234efcd0
0x234ef439                        db  0x00 ; '.'
0x234ef43a 0000                   movs       r0, r0
0x234ef43c 0000                   movs       r0, r0
0x234ef43e 0000                   movs       r0, r0
0x234ef440                        dd         0x00000000
0x234ef444                        dw         0x0141
0x234ef446                        dw         0x0140
0x234ef448                        dw         0x00ed
0x234ef44a                        dw         0x0020
0x234ef44c 0000                   movs       r0, r0
0x234ef44e 0000                   movs       r0, r0
0x234ef450                        dd         0x234c12d4
0x234ef454                        dw         0x0009
0x234ef456                        dw         0x0000
0x234ef458                        dd         0x234eeec8
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0141, 0x0160, 0xed, 0x20, 0, &Data_234c1328/*Data_0x18*/, 9, 0, &Data_234eeee0, {0}, 0}, //[22] = 234EF478 = Item 7 (' >Eingang 1920x1080') = Value
#if 0
0x234ef478                        db         0x01                               ; DATA XREF=0x234efcfc
0x234ef479                        db  0x00 ; '.'
0x234ef47a 0000                   movs       r0, r0
0x234ef47c 0000                   movs       r0, r0
0x234ef47e 0000                   movs       r0, r0
0x234ef480 0000                   movs       r0, r0
0x234ef482 0000                   movs       r0, r0
0x234ef484                        dw         0x0141
0x234ef486                        dw         0x0160
0x234ef488                        dw         0x00ed
0x234ef48a                        dw         0x0020
0x234ef48c 0000                   movs       r0, r0
0x234ef48e 0000                   movs       r0, r0
0x234ef490                        dd         0x234c1328
0x234ef494                        dw         0x0009
0x234ef496 0000                   movs       r0, r0
0x234ef498                        dd         0x234eeee0
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x29, 0xed, 0x26, 0, &Data_234c12a4/*Data_0x18*/, 2, 0, &Data_234eed30, {0}, 0}, //[23] = 234EF4B8 = Menu Head
#if 0
0x234ef4b8                        db         0x01                               ; DATA XREF=0x234efe8c
0x234ef4b9                        db         0x00
0x234ef4ba                        dw         0x0000
0x234ef4bc                        dd         0x00000000
0x234ef4c0                        dd         0x00000000
0x234ef4c4                        dw         0x003d
0x234ef4c6                        dw         0x0029
0x234ef4c8                        dw         0x00ed
0x234ef4ca                        dw         0x0026
0x234ef4cc 0000                   movs       r0, r0
0x234ef4ce 0000                   movs       r0, r0
0x234ef4d0                        dd         0x234c12a4
0x234ef4d4                        dw         0x0002
0x234ef4d6                        dw         0x0000
0x234ef4d8                        dd         0x234eed30
#endif
	{0}, //[24] = 234EF4F8
};

static Graphic_Job_2_5 Data_234efb78 = //234efb78
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x0007, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234eeef8[0], //pItems; //8
	&menu_main_graphic_color_data, //Struct_23414b38_b_Inner_0xc* pColorData; //12
	16, //uint8_t numColors; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	25, //uint8_t bNumItems; //0x18 = 24
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

static Menu_Item menu_picture_items[] = //234efbc0
{
	//[0]
	{
		83, //0x53 = "Videosignal - Analog"
		0xf4, //uint16_t wData_2; //2
		{
			&Data_234eeef8[4], //234eeff8,
			&Data_234eeef8[14], //234ef278,
		}, //int fill_4[5]; //4
		get_video_signal_analog_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		video_signal_analog_change, //void* onEvent; //0x1c = 28
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
0x234efbdc                        dd         video_signal_analog_change+1
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
			&Data_234eeef8[5], //234ef038,
			&Data_234eeef8[15], //234ef2b8,
		}, //int fill_4[5]; //4
		get_video_signal_digital_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		video_signal_digital_change, //void* onEvent; //0x1c = 28
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
			&Data_234eeef8[6], //234ef078,
			&Data_234eeef8[16], //234ef2f8,
		}, //int fill_4[5]; //4
		get_display_format_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		display_format_change, //void* onEvent; //0x1c = 28
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
		0x234efc34                        dd         display_format_change+1
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
			&Data_234eeef8[7], //234ef0b8,
			&Data_234eeef8[17], //234ef338,
			0, 0, 0
		}, //int fill_4[5]; //4
		get_display_adjustment_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_display_adjustment_change, //void* onEvent; //0x1c = 28
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
		374, //0x176 = "Videosystem" / 
		0xf4, //uint16_t wData_2; //2
		{
			&Data_234eeef8[8], //234ef0f8,
			&Data_234eeef8[18], //234ef378,
			0, 0, 0
		}, //int fill_4[5]; //4
		get_video_system_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		video_system_change, //void* onEvent; //0x1c = 28
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
0x234efc8c                        dd         video_system_change+1
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
			&Data_234eeef8[10], //234ef178,
			&Data_234eeef8[20], //234ef3f8,
			0, 0, 0
		}, //int fill_4[5]; //4
		sub_23492c4a, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23492e6c, //void* onEvent; //0x1c = 28
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
		328, //0x148 = " >Eingang 1280x720"
		0xf4, //uint16_t wData_2; //2
		{
			&Data_234eeef8[11], //234ef1b8,
			&Data_234eeef8[21], //234ef438,
			0, 0, 0
		}, //int fill_4[5]; //4
		sub_23492c78, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23492ec0, //void* onEvent; //0x1c = 28
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
		329, //0x149 = ' >Eingang 1920x1080'
		0xf4, //uint16_t wData_2; //2
		{
			&Data_234eeef8[12], //234ef1f8,
			&Data_234eeef8[22], //234ef478,
			0, 0, 0
		}, //int fill_4[5]; //4
		sub_23492ca6, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23492f14, //void* onEvent; //0x1c = 28
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
	&Data_234eeef8[23], //234ef4b8, //Struct_235fdf74_Inner12* header; //12 = 0xc
	0, //&Data_234eef78, //Struct_235fdf74_Inner16* help; //16 = 0x10
	&Data_234efb78, //Struct_235fdf74_Inner20* graphicData; //20 = 0x14
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
uint8_t menu_picture_header_string[40]; //23972bf8
uint8_t Data_23972c20[248]; //23972c20
uint8_t video_signal_analog_caption_string[40]; //23972d18
uint8_t video_signal_digital_caption_string[40]; //23972d40
uint8_t display_format_caption_string[40]; //23972d68
uint8_t display_adjustment_caption_string[40]; //23972d90
uint8_t Data_23972db8[40]; //23972db8
uint8_t Data_23972de0[40]; //23972de0
uint8_t Data_23972e08[40]; //23972e08
uint8_t Data_23972e30[40]; //23972e30
uint8_t Data_23972e58[40]; //23972e58
uint8_t video_signal_analog_value_string[40]; //23972e80
uint8_t video_signal_digital_value_string[40]; //23972ea8
uint8_t display_format_value_string[40]; //23972ed0
uint8_t display_adjustment_value_string[40]; //23972ef8
uint8_t Data_23972f20[40]; //23972f20
uint8_t Data_23972f48[40]; //23972f48
uint8_t Data_23972f70[40]; //23972f70
uint8_t Data_23972f98[40]; //23972f98


/* /  / 23492b64 - todo */
int video_signal_analog_change(uint32_t* a)
{
#if 0
	console_send_string("video_signal_analog_change (menu_picture.c): TODO\r\n");
#endif

	User_Settings sp4;
	uint32_t cursor = *a;
	uint16_t val = menu_picture_user_settings.bVideoSignalAnalog;
	 
	channel_handle_user_settings(1, &sp4);

	if (cursor & 0x08)
	{
		val++;
		if (val == 3)
		{
			val = 0;
		}
	}
	else
	{
		if (val == 0)
		{
			val = 3;
		}
		val--;
	}

	menu_picture_user_settings.bVideoSignalAnalog = val;

	if (menu_picture_user_settings.bVideoSignalAnalog == sp4.bVideoSignalAnalog)
	{
		return 1;
	}

	return 0;
}


/*  /  / 23492ba6 - todo */
void get_video_signal_analog_value_string(Menu_Item* item)
{
#if 0
	console_send_string("get_video_signal_analog_value_string (menu_picture.c): TODO\r\n");
#endif

	uint8_t* str = item->Data_4[1]->Data_0x20->pString;
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


/*  /  / 23492bd2 - todo */
int video_signal_digital_change(uint32_t* a)
{
#if 0
	console_send_string("video_signal_digital_change (menu_picture.c): TODO\r\n");
#endif

	User_Settings settings;

	menu_picture_user_settings.Data_4.bitData.digital_video_signal ^= 1;

	channel_handle_user_settings(1, &settings);

	if (menu_picture_user_settings.Data_4.bitData.digital_video_signal ==
			settings.Data_4.bitData.digital_video_signal)
	{
		return 1;
	}

	return 0;
}


/*  /  / 23492c02 - complete */
void get_video_signal_digital_value_string(Menu_Item* item)
{
#if 0
	console_send_string("get_video_signal_digital_value_string (menu_picture.c): TODO\r\n");
#endif

	uint8_t* buf = item->Data_4[1]->Data_0x20->pString;

	if (menu_picture_user_settings.Data_4.bitData.digital_video_signal == 0)
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
	uint8_t* str = item->Data_4[1]->Data_0x20->pString;

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
	Graphic_Job_2_5_Item_Text* r1 = item->Data_4[1]->Data_0x20;
	uint8_t* str = r1->pString;

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
	Graphic_Job_2_5_Item_Text* r1 = item->Data_4[1]->Data_0x20;
	uint8_t* str = r1->pString;

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
	Graphic_Job_2_5_Item_Text* r1 = item->Data_4[1]->Data_0x20;
	uint8_t* str = r1->pString;

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


/*  /  / 23492cd4 - complete */
int menu_display_adjustment_change()
{
#if 0
	console_send_string("menu_display_adjustment_change (todo.c): TODO\r\n");
#endif

	User_Settings settings; //sp

	channel_handle_user_settings(1, &settings);

	menu_picture_user_settings.bDisplayAdjustment ^= 1;

	if (menu_picture_user_settings.bDisplayAdjustment == settings.bDisplayAdjustment)
	{
		return 1;
	}

	return 0;
}


/* /   / 23492cfe - todo */
int sub_23492cfe()
{
#if 0
	console_send_string("sub_23492cfe (todo.c): TODO\r\n");
#endif

	User_Settings settings; //sp

	channel_handle_user_settings(1, &settings);

	menu_picture_user_settings.bDisplayAdjustment ^= 1;

	if (menu_picture_user_settings.bDisplayAdjustment == settings.bDisplayAdjustment)
	{
		return 1;
	}

	return 0;
}


/*  /  / 23492d26 - complete */
void get_display_adjustment_value_string(Menu_Item* item)
{
#if 0
	console_send_string("get_display_adjustment_value_string (todo.c): TODO\r\n");
#endif

	if (item->Data_4[1]->Data_0x20 != 0)
	{
		uint8_t* str = item->Data_4[1]->Data_0x20->pString;
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


/*  /  / 23492d58 - complete */
void sub_23492d58(Menu_Item* item)
{
#if 0
	console_send_string("sub_23492d58 (todo.c): TODO\r\n");
#endif

	if (item->Data_4[1]->Data_0x20 != NULL)
	{
		uint8_t* str = item->Data_4[1]->Data_0x20->pString;
		if (str != NULL)
		{
			if (menu_picture_user_settings.bDisplayAdjustment == 0)
			{
				text_table_get_string(0x73/*'Letterbox'*/, str, 35);
			}
			else
			{
				text_table_get_string(0x78/*'Pillarbox'*/, str, 35);
			}

			str[39] = 0;
		}
	}
}


/*  /  / 23492d8a - todo */
int sub_23492d8a(User_Settings* a)
{
#if 0
	console_send_string("sub_23492d8a (todo.c): TODO\r\n");
#endif

	Menu_Item* item = &menu_picture_p->Data_8[3];

	if (a->displayFormat == 0)
	{
		item->initValueString = get_display_adjustment_value_string;
		item->onEvent = menu_display_adjustment_change;
	}
	else
	{
		item->initValueString = sub_23492d58;
		item->onEvent = sub_23492cfe;
	}

	return 0;
}


/*  /  / 23492dac - complete */
void get_display_format_value_string(Menu_Item* item)
{
#if 0
	console_send_string("get_display_format_value_string (menu_picture.c): TODO\r\n");
#endif

	uint8_t* str = item->Data_4[1]->Data_0x20->pString;

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


/* /  / 23492dcc - todo */
int video_system_change(uint32_t* a)
{
#if 0
	console_send_string("video_system_change (menu_picture.c): TODO\r\n");
#endif

	User_Settings settings; //sp4
	int r0 = *a;
	int32_t val = menu_picture_user_settings.Data_4.bitData.video_system;

	if (r0 & (1 << 3))
	{
		val++;
		if (val > 2)
		{
			val = 0;
		}
	}
	else
	{
		val--;
		if (val < 0)
		{
			val = 2;
		}
	}

	menu_picture_user_settings.Data_4.bitData.video_system = (uint32_t) val;

	channel_handle_user_settings(1, &settings);

	if (menu_picture_user_settings.Data_4.bitData.video_system == settings.Data_4.bitData.video_system)
	{
		return 1;
	}

	return 0;
}


/*  /  / 23492e1e - complete */
int display_format_change()
{
#if 0
	console_send_string("display_format_change (menu_picture.c): TODO\r\n");
#endif

	User_Settings settings; //sp4

	Menu_Item* r5 = &menu_picture_p->Data_8[3];

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

	channel_handle_user_settings(1, &settings);

	if (menu_picture_user_settings.displayFormat == settings.displayFormat)
	{
		return 1;
	}

	return 0;
}


/* /  / 23492e6c - todo */
int sub_23492e6c(uint32_t* a)
{
#if 0
	console_send_string("sub_23492e6c (menu_picture.c): TODO\r\n");
#endif

	int res;
	User_Settings sp;
	int r2 = *a;
	int16_t r0 = (menu_picture_user_settings.wPictureScaling & 0x0f);

	if (r2 & (1 << 3))
	{
		r0++;
		if (r0 > 2)
		{
			r0 = 0;
		}
	}
	else
	{
		r0--;
		if (r0 < 0)
		{
			r0 = 2;
		}
	}

	menu_picture_user_settings.wPictureScaling &= ~0x0f; 
	menu_picture_user_settings.wPictureScaling |= (r0 << 0);

	channel_handle_user_settings(1, &sp);

	if ((menu_picture_user_settings.wPictureScaling & 0x0f) == (sp.wPictureScaling & 0x0f))
	{
		res = 1;
	}
	else
	{
		res = 0;
	}

	return res;
}


/* /  / 23492ec0 - todo */
int sub_23492ec0(uint32_t* a)
{
#if 0
	console_send_string("sub_23492ec0 (menu_picture.c): TODO\r\n");
#endif

	int res;
	User_Settings sp;
	int r2 = *a;
	int16_t r0 = ((menu_picture_user_settings.wPictureScaling & 0xf0) >> 4);

	if (r2 & (1 << 3))
	{
		r0++;
		if (r0 > 2)
		{
			r0 = 0;
		}
	}
	else
	{
		r0--;
		if (r0 < 0)
		{
			r0 = 2;
		}
	}

	menu_picture_user_settings.wPictureScaling &= ~0xf0; 
	menu_picture_user_settings.wPictureScaling |= (r0 << 4);

	channel_handle_user_settings(1, &sp);

	if ((menu_picture_user_settings.wPictureScaling & 0xf0) == (sp.wPictureScaling & 0xf0))
	{
		res = 1;
	}
	else
	{
		res = 0;
	}

	return res;
}


/* /  / 23492f14 - todo */
int sub_23492f14(uint32_t* a)
{
#if 0
	console_send_string("sub_23492f14 (menu_picture.c): TODO\r\n");
#endif

	int res;
	User_Settings sp;
	int r2 = *a;
	int16_t r0 = ((menu_picture_user_settings.wPictureScaling & 0xf00) >> 8);

	if (r2 & (1 << 3))
	{
		r0++;
		if (r0 > 2)
		{
			r0 = 0;
		}
	}
	else
	{
		r0--;
		if (r0 < 0)
		{
			r0 = 2;
		}
	}

	menu_picture_user_settings.wPictureScaling &= 0xf0ff; 
	menu_picture_user_settings.wPictureScaling |= (r0 << 8);

	channel_handle_user_settings(1, &sp);

	if ((menu_picture_user_settings.wPictureScaling & 0xf00) == (sp.wPictureScaling & 0xf00))
	{
		res = 1;
	}
	else
	{
		res = 0;
	}

	return res;
}


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

	av_update_user_settings(&menu_picture_user_settings, 1);

	return 0;
}


/*  /  / 23493008 - todo */
int menu_picture_on_exit(UI_Thread_Params* r4)
{
#if 0
	console_send_string("menu_picture_on_exit (menu_picture.c): TODO\r\n");
#endif

	User_Settings sp4;

	channel_handle_user_settings(1, &sp4);

	if (0 != memcmp(&sp4, &menu_picture_user_settings, sizeof(User_Settings)))
	{
		if ((r4->Data_20 == 0) && (r4->threadFunc == 0))
		{
			sub_23454624(0x12);
			return 0;
		}
		else
		{
			//loc_2349303a
			sub_234548c2(r4, 0x12);
			return 1;
		}
	}
	else
	{
		//loc_23493046
		av_update_user_settings(0, 0);
		return 0;
	}
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


/* /  / 2349306e - todo */
User_Settings* menu_picture_get_settings(void)
{
#if 0
	console_send_string("menu_picture_get_settings (todo.c): TODO\r\n");
#endif

	return &menu_picture_user_settings;
}



#endif //!VDR110
