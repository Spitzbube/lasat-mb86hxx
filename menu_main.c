
#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "amplifier.h"
#include "menu.h"

#ifndef VDR110

#pragma thumb

extern void sub_23424398();
extern void sub_2348d742();
extern void sub_23491634();
extern void sub_2349972e();
extern Menu_Item* sub_2344d9d0(struct Menu*);
extern int sub_2344dcb2(int* a);
extern void menu_settings_set_flavor(uint8_t);

static int Data_234c125c[]; //234c125c
static int Data_234c1264[]; //234c1264
static uint32_t menu_main_clut[]; //234c1388
static Menu menu_main; //234c2044
static Menu menu_main_ex; //234c2188

static int menu_main_on_enter(int);
static int menu_main_on_exit(void);
static int menu_main_items_on_event(void*);

//0x234c1230
uint8_t bData_234c1230 = 0; //234c1230 +0
int* Data_234c1234 = &Data_234c125c[0]; //234c1234 +4
int* Data_234c1238 = &Data_234c1264[0]; //234c1238 +8
Graphic_Color_Data menu_main_graphic_color_data = //234c123c
{
	&menu_main_clut[0],
};
Menu* menu_main_current_flavor = &menu_main; //234C1240 +0x10
int Data_234c1244 = 0; //234c1244 +0x14
int Data_234c1248 = 0; //234c1248 +0x18
int (*Data_234c124c)() = 0; //234C124C +0x1c
Menu* Data_234c1250 = 0; //234c1250 +0x20
Menu_Item* Data_234c1254 = 0; //234c1254 +0x24
void* Data_234c1258 = 0; //234c1258 +0x28
int Data_234c125c[] = //234c125c +0x2c
{
	0xf4,
	0x162,
};
int Data_234c1264[] = //234c1264 +0x34
{
	0x106,
	0x163,
};
Menu* menu_main_flavor[] = //234C126C +3c
{
	&menu_main, //234c2044 
	&menu_main_ex //234c2188
};

Graphic_Job_2_5_Item_Background Data_234c1274 = //234c1274
{
	14, 
	4, //???  
	0x0a, //...
#if 0
0x234c1274                        dw         0x000e                             ; DATA XREF=sub_2344d444+10, sub_2344d444+222, sub_23452a3e+28, dword_23452aa0, 0x234c1d0c
0x234c1276 0000                   movs       r0, r0
0x234c1278                        dd         0x00000004
0x234c127c                        db         0x0a                               ; DATA XREF=sub_2344d444+224
#endif
};

Graphic_Job_2_5_Item_Background menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right = //234c128c
{
	14, 
	5, //Shaded round corner  
	0x01|0x02|0x04|0x08/*0x0f*/, //...
#if 0
0x234c128c                        dw         0x000e                             ; DATA XREF=sub_2344d444+18, sub_2344d444+232, sub_2348c844+46, 0x234c184c, dword_234eb848, 0x234eef50, dword_234f4b30
0x234c128e 0000                   movs       r0, r0
0x234c1290                        dd         0x00000005
0x234c1294                        db         0x0f
#endif
};

Graphic_Job_2_5_Item_Background Data_234c1298 = //234c1298
{
	9, 
	4, //Solid round corner 
	0x02|0x01, //...
#if 0
0x234c1298 0900                   movs       r1, r1                             ; DATA XREF=sub_2344d444+238, 0x234c198c
0x234c129a 0000                   movs       r0, r0
0x234c129c                        dd         0x00000004                         ; DATA XREF=sub_2344d444+240
0x234c12a0                        db         0x03
#endif
};

Graphic_Job_2_5_Item_Background Data_234c12a4 = //234c12a4
{
	9, 
	4, 
	0x08|0x02|0x01/*0x0b*/, //...
#if 0
0x234c12a4 0900                   movs       r1, r1                             ; DATA XREF=sub_2344d444+244, 0x234e9aec, 0x234eaf94, 0x234ef4d0, 0x234efb10, 0x234f5b54
0x234c12a6 0000                   movs       r0, r0
0x234c12a8                        dd         0x00000004                         ; DATA XREF=sub_2344d444+246
0x234c12ac                        db         0x0b
#endif
};

Graphic_Job_2_5_Item_Background Data_234c12c8 = //234c12c8
{
	14, 5, 0x0a, //...
#if 0
0x234c12c8                        dw         0x000e                             ; DATA XREF=sub_2344d444+262, dword_2345985c+110, dword_2345985c+126, 0x234c346c, dword_234cec20, 0x234eefd0
0x234c12ca                        db  0x00 ; '.'
0x234c12cb                        db  0x00 ; '.'
0x234c12cc                        dd         0x00000005                         ; DATA XREF=sub_2344d444+264
0x234c12d0                        db         0x0a                               ; DATA XREF=sub_2344d444+266
#endif
};

Graphic_Job_2_5_Item_Background Data_234c12d4 = //234c12d4
{
	14, 0, 0x04|0x02, //...
#if 0
0x234c12d4 0E00                   movs       r6, r1                             ; DATA XREF=sub_2344d444+268, sub_234533bc+118, sub_234533bc+872, dword_234537d4, sub_234538b0+112, dword_23453c9c, sub_23459656+196, sub_2345afa4+190, dword_2345b32c, sub_2349511c+192, dword_23495360
0x234c12d6 0000                   movs       r0, r0
0x234c12d8                        dd         0x00000000                         ; DATA XREF=sub_2344d444+270
0x234c12dc                        db         0x06
#endif
};

Graphic_Job_2_5_Item_Background menu_main_graphic_item_background_dark_blue = //234c12e0
{
	9, 0, 0x04|0x02/*0x06*/, //...
#if 0
0x234c12e0                        dw         0x0009                             ; DATA XREF=sub_2344d444+274, sub_234523c8+152, sub_234523c8+216, sub_234523c8+224, sub_234523c8+358, sub_234523c8+464, sub_234523c8+656, sub_2345277e+16, dword_234527ac, sub_23452a3e+16, dword_23452a94
0x234c12e2                        dw         0x0000
0x234c12e4                        dd         0x00000000                         ; DATA XREF=sub_2344d444+276
0x234c12e8                        db         0x06                               ; DATA XREF=sub_2344d444+278
#endif
};

/* Menu Main, Background, Dark Blue, Two round edges below, left and right */
Graphic_Job_2_5_Item_Background menu_main_graphic_item_background_dark_blue_bottom_round_left_right = //234c12ec
{
	9, 4, 0x08|0x04, //...
#if 0
0x234c12ec                        dw         0x0009                             ; DATA XREF=sub_2344d444+280, sub_234523c8+376, sub_234523c8+474, sub_234523c8+536, sub_234523c8+604, sub_234523c8+664, sub_23452a3e+20, dword_23452a98, sub_2345afa4+264, dword_2345b338, sub_2348c8d4+252
0x234c12ee                        dw         0x0000
0x234c12f0                        dd         0x00000004                         ; DATA XREF=sub_2344d444+282, dword_234c1158+8
0x234c12f4                        db         0x0c
#endif
};

/* Menu Main, Background, Dark Blue, Two round edges top, left and right */
Graphic_Job_2_5_Item_Background menu_main_graphic_item_background_dark_blue_top_round_left_right = //234c12f8
{
	9, 4, 0x01|0x02, //...
#if 0
0x234c12f8 0900                   movs       r1, r1                             ; DATA XREF=sub_2344d444+286, sub_2345afa4+186, dword_2345b328, 0x234df4c0
0x234c12fa 0000                   movs       r0, r0
0x234c12fc                        dd         0x00000004                         ; DATA XREF=sub_2344d444+288
0x234c1300                        db         0x03
#endif
};

Graphic_Job_2_5_Item_Background Data_234c131c = //234c131c
{
	9, 4, 0x08, //...
#if 0
0x234c131c                        dw         0x0009                             ; DATA XREF=sub_2344d444+304, sub_234533bc+172, sub_234533bc+458, sub_234533bc+474, sub_234533bc+680, sub_234533bc+700, sub_234533bc+848, sub_234533bc+936, sub_234533bc+982, dword_234537d8, sub_234538b0+158
0x234c131e 0000                   movs       r0, r0
0x234c1320                        dd         0x00000004                         ; DATA XREF=sub_2344d444+306
0x234c1324                        db         0x08                               ; DATA XREF=sub_2344d444+308
#endif
};


Graphic_Job_2_5_Item_Background Data_234c1328 = //234c1328
{
	9, 4, 0x04, //...
#if 0
0x234c1328                        dw         0x0009                             ; DATA XREF=sub_2344d444+310, sub_23492670+30, dword_234926c4, sub_2349511c+48, dword_2349534c, sub_234987c2+48, dword_23498a60, 0x234c392c, 0x234e99ec, 0x234e9a2c, 0x234e9a6c
0x234c132a 0000                   movs       r0, r0
0x234c132c                        dd         0x00000004                         ; DATA XREF=sub_2344d444+312
0x234c1330                        db         0x04                               ; DATA XREF=sub_2344d444+314
#endif
};

Graphic_Job_2_5_Item_Background Data_234c1334 = //234c1334
{
	9, 4, 0x02, //...
#if 0
0x234c1334                        dw         0x0009                             ; DATA XREF=sub_2344d444+316, dword_234c1158+12, 0x234c34ac, dword_234ced60, 0x234e962c, 0x234eb094, 0x234ef010, 0x234f5c54
0x234c1336 0000                   movs       r0, r0
0x234c1338                        dd         0x00000004                         ; DATA XREF=sub_2344d444+318
0x234c133c                        db         0x02                               ; DATA XREF=sub_2344d444+320
#endif
};

Graphic_Job_2_5_Item_Background Data_234c1340 = //234c1340
{
	9, 4, 0x01, //...
#if 0
0x234c1340                        dw         0x0009                             ; DATA XREF=sub_2344d444+322, 0x234caf74, 0x234e98ac, 0x234eb194, 0x234ef290, 0x234f5d14
0x234c1342 0000                   movs       r0, r0
0x234c1344                        dd         0x00000004                         ; DATA XREF=sub_2344d444+324
0x234c1348                        db         0x01
#endif	
};

Graphic_Job_2_5_Item_Background Data_234c134c = //234c134c
{
	9, 4, 0x08|0x04|0x02|0x01, //...
#if 0
0x234c134c 0900                   movs       r1, r1                             ; DATA XREF=sub_2344d444+328, sub_23452a3e+24, dword_23452a9c, sub_2345afa4+260, dword_2345b334, 0x234c188c, 0x234c190c, 0x234df3c0, 0x234eef90, dword_234f7dd0
0x234c134e 0000                   movs       r0, r0
0x234c1350                        dd         0x00000004                         ; DATA XREF=sub_2344d444+330
0x234c1354                        db         0x0f
#endif	
};

static uint32_t menu_main_clut[] = //234c1388
{
0x6b6fb800, 0x6b6fb800, 0x1f103f00, 0xe0e0e000,
0x90909000, 0x10101000, 0xa8d02000, 0x6941e100,
0x2f104f00, 0x15900000, 0x8b222200, 0xc0a0f000,
0x7181c100, 0x4181a100, 0x50505000, 0x6b6fb800
};

extern void sub_23413af4(void*, uint8_t);
extern void sub_23413cfc(void*, uint8_t);

/*static*/ Struct_2377ded0_Inner_0x1c_Inner_8 Data_234c14f0 = //234c14f0
{
	0x34, 0x37, 0x5a, &sub_23413cfc,
#if 0
0x234c14f0                        dd         0x00000034
0x234c14f4                        dw         0x0037
0x234c14f6                        dw         0x005a
0x234c14f8                        dd         0x23413cfc
#endif
};
//int Data_234c14fc; //234c14fc
/*static*/ Struct_2377ded0_Inner_0x1c_Inner_8 Data_234c1508 = //234c1508
{
	0x36, 0, 0, &sub_23413af4,
#if 0
0x234c1508                        dd         0x00000036
0x234c150c                        dw         0x0000
0x234c150e                        dw         0x0000
0x234c1510                        dd         0x23413af4
#endif
};
/*static*/ Struct_2377ded0_Inner_0x1c_Inner_8 Data_234c1514 = //234c1514
{
	0x37, 0, 0, &sub_23413af4,
#if 0
0x234c1514                        dd         0x00000037
0x234c1518                        dw         0x0000
0x234c151a                        dw         0x0000
0x234c151c                        dd         0x23413af4
#endif
};

Graphic_Job_2_5_Item_Background Data_234c1558 = //234c1558
{
	14, 12, 0x00, //...
#if 0
0x234c1558                        dw         0x000e                             ; DATA XREF=0x234e7050, 0x234eb294, dword_23504814
0x234c155a                        db  0x00 ; '.'
0x234c155b                        db  0x00 ; '.'
0x234c155c                        dd         0x0000000c
0x234c1560                        db         0x00
#endif	
};

static uint8_t menu_main_header_text_buffer[40] = "Head"; //234c1564 +0x28 = 234C158C
static Graphic_Job_2_5_Item_Text menu_main_graphic_header_text_item = //234c158c
{
	0, 0x0051, 0x002c, 0x0137, 0x004f, 0x01, 0x06, 0x02, 0x00, &menu_main_header_text_buffer[0], 0, 0, 0
#if 0
0x234c158c                        db         0x00                               ; DATA XREF=0x234c1894
0x234c158d                        db  0x00 ; '.'
0x234c158e                        dw         0x0051
0x234c1590                        dw         0x002c
0x234c1592                        dw         0x0137
0x234c1594                        dw         0x004f
0x234c1596                        db         0x01                               ; CODE XREF=menu_main_clut+74
0x234c1597                        db         0x06
0x234c1598                        db         0x02
0x234c1599                        db         0x00
0x234c159a 0000                   movs       r0, r0
0x234c159c                        dd         0x234c1564                         ; "Head"
0x234c15a0                        dw         0x0000
0x234c15a2                        db         0x00
0x234c15a3                        db         0x00
#endif
};

static uint8_t menu_main_help_text_buffer[248] = "Help"; //234c15a4

static Graphic_Job_2_5_Item_Text menu_main_graphic_help_text_item = //234c169c
{
	0, 0x0047, 0x01c7, 0x0257, 0x01fd, 0x01, 0x05, 0x03, 0x01, &menu_main_help_text_buffer[0], 0, 0, 0
#if 0
0x234c169c                        db         0x00                               ; DATA XREF=0x234c1914
0x234c169d                        db  0x00 ; '.'
0x234c169e                        dw         0x0047
0x234c16a0                        dw         0x01c7
0x234c16a2                        dw         0x0257
0x234c16a4                        dw         0x01fd
0x234c16a6                        db         0x01
0x234c16a7                        db         0x05
0x234c16a8                        db         0x03                               ; CODE XREF=menu_main_clut+284
0x234c16a9                        db         0x01
0x234c16aa 0000                   movs       r0, r0
0x234c16ac                        dd         aHelp_234c15a4                     ; "Help", DATA XREF=menu_main_clut+214
0x234c16b0                        dw         0x0000
0x234c16b2                        db         0x00
0x234c16b3                        db         0x00
#endif
};


static uint8_t menu_main_graphic_item_1_text_buffer[40] = "1"; //234c16b4
static Graphic_Job_2_5_Item_Text menu_main_graphic_text_item_1 = //234c16dc
{
	0, 0x0051, 0x0064, 0x0137, 0x0080, 0x01, 0x04, 0x09, 0x01, &menu_main_graphic_item_1_text_buffer[0], 0, 0, 0
#if 0
0x234c16dc                        db         0x00                               ; DATA XREF=0x234c1994
0x234c16dd                        db  0x00 ; '.'
0x234c16de                        dw         0x0051
0x234c16e0                        dw         0x0064
0x234c16e2                        dw         0x0137
0x234c16e4                        dw         0x0080
0x234c16e6                        db         0x01
0x234c16e7                        db         0x04
0x234c16e8                        db         0x09
0x234c16e9                        db         0x01
0x234c16ea 0000                   movs       r0, r0
0x234c16ec                        dd         a1                                 ; "1"
0x234c16f0                        dw         0x0000
0x234c16f2                        db         0x00
0x234c16f3                        db         0x00
#endif
};

static uint8_t menu_main_graphic_item_2_text_buffer[40] = "2"; //234c16f4
static Graphic_Job_2_5_Item_Text menu_main_graphic_text_item_2 = //234c171c
{
	0, 0x0051, 0x0084, 0x0137, 0x00a0, 0x01, 0x04, 0x09, 0x01, &menu_main_graphic_item_2_text_buffer[0], 0, 0, 0
#if 0
0x234c171c                        db         0x00                               ; DATA XREF=0x234c19d4
0x234c171d                        db  0x00 ; '.'
0x234c171e                        dw         0x0051
0x234c1720                        dw         0x0084
0x234c1722                        dw         0x0137
0x234c1724                        dw         0x00a0
0x234c1726                        db         0x01
0x234c1727                        db         0x04
0x234c1728                        db         0x09
0x234c1729                        db         0x01
0x234c172a 0000                   movs       r0, r0
0x234c172c                        dd         0x234c16f4
0x234c1730                        dw         0x0000
0x234c1732                        db         0x00
0x234c1733                        db         0x00
#endif
};

static uint8_t menu_main_graphic_item_3_text_buffer[40] = "3"; //234c1734
static Graphic_Job_2_5_Item_Text menu_main_graphic_text_item_3 = //234c175c
{
	0, 0x0051, 0x00a4, 0x0137, 0x00c0, 0x01, 0x04, 0x09, 0x01, &menu_main_graphic_item_3_text_buffer[0], 0, 0, 0
#if 0
0x234c175c                        db         0x00                               ; DATA XREF=0x234c1a14
0x234c175d                        db  0x00 ; '.'
0x234c175e                        dw         0x0051
0x234c1760                        dw         0x00a4
0x234c1762                        dw         0x0137
0x234c1764                        dw         0x00c0
0x234c1766                        db         0x01
0x234c1767                        db         0x04
0x234c1768                        db         0x09
0x234c1769                        db         0x01
0x234c176a 0000                   movs       r0, r0
0x234c176c                        dd         0x234c1734
0x234c1770                        dw         0x0000
0x234c1772                        db         0x00
0x234c1773                        db  0x00 ; '.'
0x234c1774 3400                   movs       r4, r6
#endif
};

static uint8_t menu_main_graphic_item_4_text_buffer[40] = "4"; //0x234c1774
static Graphic_Job_2_5_Item_Text menu_main_graphic_text_item_4 = //234c179c
{
	0, 0x0051, 0x00c4, 0x0137, 0x00e0, 0x01, 0x04, 0x09, 0x01, &menu_main_graphic_item_4_text_buffer[0], 0, 0, 0
#if 0
0x234c179c                        db         0x00                               ; DATA XREF=0x234c1a54
0x234c179d                        db  0x00 ; '.'
0x234c179e                        dw         0x0051
0x234c17a0                        dw         0x00c4
0x234c17a2                        dw         0x0137
0x234c17a4                        dw         0x00e0
0x234c17a6                        db         0x01
0x234c17a7                        db         0x04
0x234c17a8                        db         0x09
0x234c17a9                        db         0x01
0x234c17aa 0000                   movs       r0, r0
0x234c17ac                        dd         0x234c1774
0x234c17b0 0000                   movs       r0, r0
0x234c17b2 0000                   movs       r0, r0
0x234c17b4 3500                   movs       r5, r6
#endif
};

static uint8_t menu_main_graphic_item_5_text_buffer[40] = "5"; //234c17b4
static Graphic_Job_2_5_Item_Text menu_main_graphic_text_item_5 = //234c17dc
{
	0, 0x0051, 0x00e4, 0x0137, 0x100, 0x01, 0x04, 0x09, 0x01, &menu_main_graphic_item_5_text_buffer[0], 0, 0, 0
#if 0
0x234c17dc 0000                   movs       r0, r0                             ; DATA XREF=0x234c1a94
0x234c17de                        dw         0x0051
0x234c17e0                        dw         0x00e4
0x234c17e2                        dw         0x0137
0x234c17e4                        dw         0x0100
0x234c17e6                        db         0x01
0x234c17e7                        db         0x04
0x234c17e8                        db         0x09
0x234c17e9                        db         0x01
0x234c17ea 0000                   movs       r0, r0
0x234c17ec                        dd         0x234c17b4
0x234c17f0 0000                   movs       r0, r0
0x234c17f2 0000                   movs       r0, r0
#endif
};

static  uint8_t menu_main_graphic_item_6_text_buffer[40] = "6"; //0x234c17f4
static Graphic_Job_2_5_Item_Text menu_main_graphic_text_item_6 = //234c181c
{
	0, 0x0051, 0x0104, 0x0137, 0x120, 0x01, 0x04, 0x09, 0x01, &menu_main_graphic_item_6_text_buffer[0], 0, 0, 0
#if 0
0x234c181c                        db         0x00                               ; DATA XREF=0x234c1b14
0x234c181d                        db  0x00 ; '.'
0x234c181e                        dw         0x0051
0x234c1820                        dw         0x0104
0x234c1822                        dw         0x0137
0x234c1824                        dw         0x0120
0x234c1826                        db         0x01
0x234c1827                        db         0x04
0x234c1828                        db         0x09
0x234c1829                        db         0x01
0x234c182a 0000                   movs       r0, r0
0x234c182c                        dd         0x234c17f4
0x234c1830 0000                   movs       r0, r0
0x234c1832 0000                   movs       r0, r0
#endif
};

static Graphic_Job_2_5_Item menu_main_graphic_items[14] = //234c1834
{
	{1, 0, 0/*&Data_234c1544*//*Data_4?*/, 0/*Data_8*/, 0x37, 0x23, 0x106, 0x32, 0, 
	&menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
	9, 0, 0, {0}, 0}, //[0] = 234c1834: Header border box
#if 0
0x234c1834                        db         0x01                               ; DATA XREF=menu_main_on_enter+18, menu_main_on_enter+30, dword_234c1efc
0x234c1835                        db         0x00
0x234c1836 0000                   movs       r0, r0
0x234c1838                        dd         0x234c1544
0x234c183c                        dd         0x00000000
0x234c1840                        dw         0x0037
0x234c1842                        dw         0x0023
0x234c1844                        dw         0x0106
0x234c1846                        dw         0x0032
0x234c1848 0000                   movs       r0, r0
0x234c184a 0000                   movs       r0, r0
0x234c184c                        dd         0x234c128c
0x234c1850                        dw         0x0009
0x234c1852                        dw         0x0000
0x234c1854                        dd         0x00000000
0x234c1858 0000                   movs       r0, r0
0x234c185a 0000                   movs       r0, r0
0x234c185c 0000                   movs       r0, r0
0x234c185e 0000                   movs       r0, r0
0x234c1860 0000                   movs       r0, r0
0x234c1862 0000                   movs       r0, r0
0x234c1864 0000                   movs       r0, r0
0x234c1866 0000                   movs       r0, r0
0x234c1868 0000                   movs       r0, r0
0x234c186a 0000                   movs       r0, r0
0x234c186c 0000                   movs       r0, r0                             ; CODE XREF=dword_234c13ac+250, DATA XREF=dword_234c13ac+198
0x234c186e 0000                   movs       r0, r0
0x234c1870 0000                   movs       r0, r0
0x234c1872 0000                   movs       r0, r0
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x29, 0xfa, 0x26, 0, &Data_234c134c/*Data_0x18*/, 2, 0, &menu_main_graphic_header_text_item/*Data_0x20*/}, //[1] = 234C1874 = header text box
#if 0
0x234c1874                        db         0x01                               ; DATA XREF=0x234c2050
0x234c1875                        db         0x00
0x234c1876 0000                   movs       r0, r0
0x234c1878                        dd         0x234c1544
0x234c187c                        dd         0x00000000
0x234c1880                        dw         0x003d
0x234c1882                        dw         0x0029
0x234c1884                        dw         0x00fa
0x234c1886                        dw         0x0026
0x234c1888 0000                   movs       r0, r0
0x234c188a 0000                   movs       r0, r0
0x234c188c                        dd         0x234c134c
0x234c1890                        dw         0x0002
0x234c1892                        dw         0x0000
0x234c1894                        dd         0x234c158c
#endif
	{0}, //[2] = 234C18B4
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x1c3, 0x21a, 0x3a, 0, &Data_234c134c/*Data_0x18*/, 3, 0, &menu_main_graphic_help_text_item/*Data_0x20*/}, //[3] = 234C18F4 = help
#if 0
0x234c18f4                        db         0x01                               ; DATA XREF=0x234c2054
0x234c18f5                        db         0x00
0x234c18f6 0000                   movs       r0, r0
0x234c18f8                        dd         0x234c1550
0x234c18fc 0000                   movs       r0, r0
0x234c18fe 0000                   movs       r0, r0
0x234c1900                        dw         0x003d
0x234c1902                        dw         0x01c3
0x234c1904                        dw         0x021a
0x234c1906                        dw         0x003a
0x234c1908 0000                   movs       r0, r0
0x234c190a 0000                   movs       r0, r0
0x234c190c                        dd         0x234c134c
0x234c1910                        db         0x03
0x234c1911                        db  0x00 ; '.'
0x234c1912 0000                   movs       r0, r0
0x234c1914                        dd         0x234c169c
0x234c1918                        dd         0x00000000
0x234c191c                        dd         0x00000000
0x234c1920                        dd         0x00000000
0x234c1924                        dd         0x00000000
0x234c1928                        dd         0x00000000
0x234c192c                        dd         0x00000000
0x234c1930                        dd         0x00000000
#endif
	{0, 0, 0, 0/*Data_8*/, 0x37, 0x5a, 0x106, 0xac, 0, 
	&menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
	2, 0, 0/*Data_0x20*/}, //[4] = 234C1934: Items border box
#if 0
0x234c1934                        db         0x01
0x234c1935                        db         0x00
0x234c1936 0000                   movs       r0, r0
0x234c1938                        dd         0x234c1548
0x234c193c 0000                   movs       r0, r0
0x234c193e 0000                   movs       r0, r0
0x234c1940                        dw         0x0037
0x234c1942                        dw         0x005a
0x234c1944                        dw         0x0106
0x234c1946                        dw         0x00ac
0x234c1948 0000                   movs       r0, r0
0x234c194a 0000                   movs       r0, r0
0x234c194c                        dd         0x234c128c
0x234c1950                        db         0x02
0x234c1951                        db  0x00 ; '.'
0x234c1952 0000                   movs       r0, r0
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x60, 0xfa, 0x20, 0, &Data_234c1298/*Data_0x18*/, 9, 0, &menu_main_graphic_text_item_1/*Data_0x20*/}, //[5] = 234C1974: "Einstellungen" col 0
#if 0
0x234c1974                        db         0x01                               ; DATA XREF=0x234c1f40
0x234c1975                        db         0x00
0x234c1976 0000                   movs       r0, r0
0x234c1978                        dd         0x234c1548
0x234c197c                        dd         0x00000000
0x234c1980                        dw         0x003d
0x234c1982                        dw         0x0060
0x234c1984                        dw         0x00fa
0x234c1986                        dw         0x0020
0x234c1988 0000                   movs       r0, r0
0x234c198a 0000                   movs       r0, r0
0x234c198c                        dd         0x234c1298
0x234c1990                        dw         0x0009
0x234c1992                        dw         0x0000
0x234c1994                        dd         0x234c16dc
0x234c1998                        dd         0x00000000
0x234c199c                        dd         0x00000000
0x234c19a0                        dd         0x00000000
0x234c19a4                        dd         0x00000000
0x234c19a8                        dd         0x00000000
0x234c19ac                        dd         0x00000000
0x234c19b0                        dd         0x00000000
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x80, 0xfa, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &menu_main_graphic_text_item_2/*Data_0x20*/}, //[6] = 234C19B4: "Installation"
#if 0
0x234c19b4                        db         0x01                               ; DATA XREF=0x234c1f6c
0x234c19b5                        db         0x00
0x234c19b6 0000                   movs       r0, r0
0x234c19b8                        dd         0x234c1548
0x234c19bc                        dd         0x00000000
0x234c19c0                        dw         0x003d
0x234c19c2                        dw         0x0080
0x234c19c4                        dw         0x00fa
0x234c19c6                        dw         0x0020
0x234c19c8 0000                   movs       r0, r0
0x234c19ca 0000                   movs       r0, r0
0x234c19cc                        dd         0x234c12d4
0x234c19d0                        dw         0x0009
0x234c19d2                        dw         0x0000
0x234c19d4                        dd         0x234c171c
0x234c19d8                        dd         0x00000000
0x234c19dc                        dd         0x00000000
0x234c19e0                        dd         0x00000000
0x234c19e4                        dd         0x00000000
0x234c19e8                        dd         0x00000000
0x234c19ec                        dd         0x00000000
0x234c19f0                        dd         0x00000000
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xa0, 0xfa, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &menu_main_graphic_text_item_3/*Data_0x20*/}, //[7] = 234C19F4: 'Channel list'
#if 0
0x234c19f4                        db         0x01                               ; DATA XREF=0x234c1f98
0x234c19f5                        db  0x00 ; '.'
0x234c19f6 0000                   movs       r0, r0
0x234c19f8                        dd         0x234c1548
0x234c19fc 0000                   movs       r0, r0
0x234c19fe 0000                   movs       r0, r0
0x234c1a00                        dw         0x003d
0x234c1a02                        dw         0x00a0
0x234c1a04                        dw         0x00fa
0x234c1a06                        dw         0x0020
0x234c1a08 0000                   movs       r0, r0
0x234c1a0a 0000                   movs       r0, r0
0x234c1a0c                        dd         0x234c12d4
0x234c1a10                        dw         0x0009
0x234c1a12                        dw         0x0000
0x234c1a14                        dd         menu_main_graphic_text_item_2+64
0x234c1a18                        dd         0x00000000
0x234c1a1c                        dd         0x00000000
0x234c1a20                        dd         0x00000000
0x234c1a24                        dd         0x00000000
0x234c1a28                        dd         0x00000000
0x234c1a2c                        dd         0x00000000
0x234c1a30                        dd         0x00000000
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xc0, 0xfa, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &menu_main_graphic_text_item_4}, //[8] = 234C1A34: "Timer"
#if 0
0x234c1a34                        db         0x01                               ; DATA XREF=0x234c1fc4
0x234c1a35                        db  0x00 ; '.'
0x234c1a36 0000                   movs       r0, r0
0x234c1a38                        dd         0x234c1548
0x234c1a3c 0000                   movs       r0, r0
0x234c1a3e 0000                   movs       r0, r0
0x234c1a40                        dw         0x003d
0x234c1a42                        dw         0x00c0
0x234c1a44                        dw         0x00fa
0x234c1a46                        dw         0x0020
0x234c1a48 0000                   movs       r0, r0
0x234c1a4a 0000                   movs       r0, r0
0x234c1a4c                        dd         0x234c12d4
0x234c1a50                        dw         0x0009
0x234c1a52                        dw         0x0000
0x234c1a54                        dd         0x234c179c
0x234c1a58 0000                   movs       r0, r0
0x234c1a5a 0000                   movs       r0, r0
0x234c1a5c 0000                   movs       r0, r0
0x234c1a5e 0000                   movs       r0, r0
0x234c1a60 0000                   movs       r0, r0
0x234c1a62 0000                   movs       r0, r0
0x234c1a64 0000                   movs       r0, r0
0x234c1a66 0000                   movs       r0, r0
0x234c1a68 0000                   movs       r0, r0
0x234c1a6a 0000                   movs       r0, r0
0x234c1a6c 0000                   movs       r0, r0
0x234c1a6e 0000                   movs       r0, r0
0x234c1a70 0000                   movs       r0, r0
0x234c1a72 0000                   movs       r0, r0
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xe0, 0xfa, 0x20, 0, &menu_main_graphic_item_background_dark_blue_bottom_round_left_right/*Data_0x18*/, 9, 0, &menu_main_graphic_text_item_5}, //[9] = 234C1A74: "Information"
#if 0
0x234c1a74                        db         0x01                               ; DATA XREF=0x234c1ff0
0x234c1a75                        db  0x00 ; '.'
0x234c1a76 0000                   movs       r0, r0
0x234c1a78                        dd         0x234c1548
0x234c1a7c 0000                   movs       r0, r0
0x234c1a7e 0000                   movs       r0, r0
0x234c1a80                        dw         0x003d
0x234c1a82                        dw         0x00e0
0x234c1a84                        dw         0x00fa
0x234c1a86                        dw         0x0020
0x234c1a88 0000                   movs       r0, r0
0x234c1a8a 0000                   movs       r0, r0
0x234c1a8c                        dd         0x234c12ec
0x234c1a90 0900                   movs       r1, r1
0x234c1a92 0000                   movs       r0, r0
0x234c1a94                        dd         0x234c17dc
#endif 
	{0}, //[10] = 234C1AB4 
	{0, 0, 0, 0/*Data_8*/, 0x3d, 0x100, 0xfa, 0x20, 0, &menu_main_graphic_item_background_dark_blue_bottom_round_left_right/*Data_0x18*/, 9, 0, &menu_main_graphic_text_item_6}, //[11] = 234C1AF4
#if 0
0x234c1af4                        db         0x00                               ; DATA XREF=0x234c201c
0x234c1af5                        db  0x00 ; '.'
0x234c1af6 0000                   movs       r0, r0
0x234c1af8                        dd         0x234c1548
0x234c1afc 0000                   movs       r0, r0
0x234c1afe 0000                   movs       r0, r0
0x234c1b00                        dw         0x003d
0x234c1b02                        dw         0x0100
0x234c1b04                        dw         0x00fa
0x234c1b06                        dw         0x0020
0x234c1b08                        db  0x00 ; '.'
0x234c1b09                        db  0x00 ; '.'
0x234c1b0a 0000                   movs       r0, r0
0x234c1b0c                        dd         0x234c12ec
0x234c1b10                        dw         0x0009
0x234c1b12                        dw         0x0000
0x234c1b14                        dd         0x234c181c
#endif
	{0}, //[12] = 234C1B34 
	{0}, //[13] = 234C1B74
};

static Graphic_Job_2_5_Item menu_main_graphic_items_ex[13] = //234C1BB4
{
	{1, 0, 0/*&Data_234c1544*//*Data_4?*/, 0/*Data_8*/, 0x37, 0x23, 0x106, 0x32, 0, &Data_234c1558/*Data_0x18*/, 0, 0, 0, {0}, 0}, //[0] = 234C1BB4: ???
#if 0
0x234c1bb4                        db         0x01                               ; DATA XREF=0x234c1f20
0x234c1bb5                        db         0x00
0x234c1bb6                        dw         0x0000
0x234c1bb8                        dd         0x234c1544
0x234c1bbc                        dd         0x234c14b4
0x234c1bc0                        dw         0x0037
0x234c1bc2                        dw         0x0023
0x234c1bc4                        dw         0x0106
0x234c1bc6                        dw         0x0032
0x234c1bc8 0000                   movs       r0, r0
0x234c1bca 0000                   movs       r0, r0
0x234c1bcc                        dd         0x234c1558
#endif
	{1, 0, 0/*&Data_234c1544*//*Data_4?*/, 0/*Data_8*/, 0x3d, 0x29, 0xfa, 0x26, 0, &Data_234c12d4/*Data_0x18*/, 0, 0, &menu_main_graphic_header_text_item, {0}, 0}, //[1] = 234C1BF4: ???
#if 0
0x234c1bf4                        db         0x01                               ; DATA XREF=0x234c2194
0x234c1bf5                        db         0x00
0x234c1bf6 0000                   movs       r0, r0
0x234c1bf8                        dd         0x234c1544
0x234c1bfc 0000                   movs       r0, r0
0x234c1bfe 0000                   movs       r0, r0
0x234c1c00                        dw         0x003d
0x234c1c02                        dw         0x0029
0x234c1c04                        dw         0x00fa
0x234c1c06                        dw         0x0026
0x234c1c08 0000                   movs       r0, r0
0x234c1c0a 0000                   movs       r0, r0
0x234c1c0c                        dd         0x234c12d4
0x234c1c10 0000                   movs       r0, r0
0x234c1c12 0000                   movs       r0, r0
0x234c1c14                        dd         0x234c158c
#endif
	{0}, //[2] = 234C1C34 
	{1, 0, 0/*&Data_234c1550*//*Data_4?*/, 0/*Data_8*/, 0x3d, 0x1c3, 0x21a, 0x3a, 0, &Data_234c134c/*Data_0x18*/, 0, 0, &menu_main_graphic_help_text_item, {0}, 0}, //[3] = 234C1C74: ???
#if 0
0x234c1c74                        db         0x01                               ; DATA XREF=0x234c2198
0x234c1c75                        db         0x00
0x234c1c76 0000                   movs       r0, r0
0x234c1c78                        dd         0x234c1550
0x234c1c7c 0000                   movs       r0, r0
0x234c1c7e 0000                   movs       r0, r0
0x234c1c80                        dw         0x003d
0x234c1c82                        dw         0x01c3
0x234c1c84                        dw         0x021a
0x234c1c86                        dw         0x003a
0x234c1c88 0000                   movs       r0, r0
0x234c1c8a 0000                   movs       r0, r0
0x234c1c8c                        dd         0x234c134c
0x234c1c90 0000                   movs       r0, r0
0x234c1c92 0000                   movs       r0, r0
0x234c1c94                        dd         0x234c169c
#endif
	{0}, //[4] = 234C1CB4 
	{1, 0, 0/*&Data_234c1548*//*Data_4?*/, 0/*Data_8*/, 
	0x3d, 0x60, 0xfa, 0x20, 0, 
	&Data_234c1274/*Data_0x18*/, 0, 0, 
	&menu_main_graphic_text_item_1, {0}, 0}, //[5] = 234C1CF4: Item 1
#if 0
0x234c1cf4                        db         0x01                               ; DATA XREF=0x234c2084
0x234c1cf5                        db         0x00
0x234c1cf6 0000                   movs       r0, r0
0x234c1cf8                        dd         0x234c1548
0x234c1cfc 0000                   movs       r0, r0
0x234c1cfe 0000                   movs       r0, r0
0x234c1d00                        dw         0x003d
0x234c1d02                        dw         0x0060
0x234c1d04                        dw         0x00fa
0x234c1d06                        dw         0x0020
0x234c1d08 0000                   movs       r0, r0
0x234c1d0a 0000                   movs       r0, r0
0x234c1d0c                        dd         0x234c1274
0x234c1d10 0000                   movs       r0, r0
0x234c1d12 0000                   movs       r0, r0
0x234c1d14                        dd         0x234c16dc
#endif
	{1, 0, 0/*&Data_234c1548*//*Data_4?*/, 0/*Data_8*/, 0x3d, 0x80, 0xfa, 0x20, 0, &Data_234c1274/*Data_0x18*/, 0, 0, &menu_main_graphic_text_item_2, {0}, 0}, //[6] = 234C1D34: ???
#if 0
0x234c1d34                        db         0x01                               ; DATA XREF=0x234c20b0
0x234c1d35                        db         0x00
0x234c1d36 0000                   movs       r0, r0
0x234c1d38                        dd         0x234c1548
0x234c1d3c 0000                   movs       r0, r0
0x234c1d3e 0000                   movs       r0, r0
0x234c1d40                        dw         0x003d
0x234c1d42                        dw         0x0080
0x234c1d44                        dw         0x00fa
0x234c1d46                        dw         0x0020
0x234c1d48 0000                   movs       r0, r0
0x234c1d4a 0000                   movs       r0, r0
0x234c1d4c                        dd         0x234c1274
0x234c1d50 0000                   movs       r0, r0
0x234c1d52 0000                   movs       r0, r0
0x234c1d54                        dd         0x234c171c
#endif
	{1, 0, 0/*&Data_234c1548*//*Data_4?*/, 0/*Data_8*/, 0x3d, 0xa0, 0xfa, 0x20, 0, &Data_234c1274/*Data_0x18*/, 0, 0, &menu_main_graphic_text_item_3, {0}, 0}, //[7] = 234C1D74: ???
#if 0
0x234c1d74                        db         0x01                               ; DATA XREF=0x234c20dc
0x234c1d75                        db         0x00
0x234c1d76 0000                   movs       r0, r0
0x234c1d78                        dd         0x234c1548
0x234c1d7c 0000                   movs       r0, r0
0x234c1d7e 0000                   movs       r0, r0
0x234c1d80                        dw         0x003d
0x234c1d82                        dw         0x00a0
0x234c1d84                        dw         0x00fa
0x234c1d86                        dw         0x0020
0x234c1d88 0000                   movs       r0, r0
0x234c1d8a 0000                   movs       r0, r0
0x234c1d8c                        dd         0x234c1274
0x234c1d90 0000                   movs       r0, r0
0x234c1d92 0000                   movs       r0, r0
0x234c1d94                        dd         0x234c175c
#endif
	{1, 0, 0/*&Data_234c1548*//*Data_4?*/, 0/*Data_8*/, 0x3d, 0xc0, 0xfa, 0x20, 0, &Data_234c1274/*Data_0x18*/, 0, 0, &menu_main_graphic_text_item_4, {0}, 0}, //[8] = 234C1DB4: ???
#if 0
0x234c1db4                        db         0x01                               ; DATA XREF=0x234c2108
0x234c1db5                        db         0x00
0x234c1db6 0000                   movs       r0, r0
0x234c1db8                        dd         0x234c1548
0x234c1dbc 0000                   movs       r0, r0
0x234c1dbe 0000                   movs       r0, r0
0x234c1dc0                        dw         0x003d
0x234c1dc2                        dw         0x00c0
0x234c1dc4                        dw         0x00fa
0x234c1dc6                        dw         0x0020
0x234c1dc8 0000                   movs       r0, r0
0x234c1dca 0000                   movs       r0, r0
0x234c1dcc                        dd         0x234c1274
0x234c1dd0 0000                   movs       r0, r0
0x234c1dd2 0000                   movs       r0, r0
0x234c1dd4                        dd         0x234c179c
#endif
	{1, 0, 0/*&Data_234c1548*//*Data_4?*/, 0/*Data_8*/, 0x3d, 0xe0, 0xfa, 0x20, 0, &Data_234c1274/*Data_0x18*/, 0, 0, &menu_main_graphic_text_item_5, {0}, 0}, //[9] = 234C1DF4: ???
#if 0
0x234c1df4                        db         0x01                               ; DATA XREF=0x234c2134
0x234c1df5                        db         0x00
0x234c1df6 0000                   movs       r0, r0
0x234c1df8                        dd         0x234c1548
0x234c1dfc 0000                   movs       r0, r0
0x234c1dfe 0000                   movs       r0, r0
0x234c1e00                        dw         0x003d
0x234c1e02                        dw         0x00e0
0x234c1e04                        dw         0x00fa
0x234c1e06                        dw         0x0020
0x234c1e08 0000                   movs       r0, r0
0x234c1e0a 0000                   movs       r0, r0
0x234c1e0c                        dd         0x234c1274
0x234c1e10 0000                   movs       r0, r0
0x234c1e12 0000                   movs       r0, r0
0x234c1e14                        dd         0x234c17dc
#endif
	{0}, //[10] = 234C1E34 
	{0, 0, 0/*&Data_234c1548*//*Data_4?*/, 0/*Data_8*/, 0x3d, 0x100, 0xfa, 0x20, 0, &Data_234c1274/*Data_0x18*/, 0, 0, &menu_main_graphic_text_item_6, {0}, 0}, //[11] = 234C1E74: ???
#if 0
0x234c1e74                        db         0x00                               ; DATA XREF=0x234c2160
0x234c1e75                        db         0x00
0x234c1e76 0000                   movs       r0, r0
0x234c1e78                        dd         0x234c1548
0x234c1e7c 0000                   movs       r0, r0
0x234c1e7e 0000                   movs       r0, r0
0x234c1e80                        dw         0x003d
0x234c1e82                        dw         0x0100
0x234c1e84                        dw         0x00fa
0x234c1e86                        dw         0x0020
0x234c1e88 0000                   movs       r0, r0
0x234c1e8a 0000                   movs       r0, r0
0x234c1e8c                        dd         0x234c1274
0x234c1e90 0000                   movs       r0, r0
0x234c1e92 0000                   movs       r0, r0
0x234c1e94                        dd         0x234c181c
#endif
	{0}, //[12] = 234C1EB4 
};

static Graphic_Job_2_5 menu_main_graphic_data = //234c1ef4
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x0004, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&menu_main_graphic_items[0], //int Data_8; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	0x0f, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	14, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
	0, //0x1c
	0, //0x20
};

static Graphic_Job_2_5 menu_main_graphic_data_ex = //234c1f18
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x0004, //uint16_t wData_2; //2
	0x0c, //uint8_t bData_4; //4
	&menu_main_graphic_items_ex[0], //int Data_8; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	0x0f, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	13, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
	0, //0x1c
	0, //0x20
#if 0
0x234c1f18                        db  0x00 ; '.'                                ; DATA XREF=0x234c219c
0x234c1f19                        db  0xfa ; '.'
0x234c1f1a                        dw         0x0004
0x234c1f1c                        db         0x0c
0x234c1f1d                        db  0x00 ; '.'
0x234c1f1e 0000                   movs       r0, r0
0x234c1f20                        dd         0x234c1bb4
0x234c1f24                        dd         menu_main_graphic_color_data
0x234c1f28 0F00                   movs       r7, r1
0x234c1f2a 0000                   movs       r0, r0
0x234c1f2c 0000                   movs       r0, r0
0x234c1f2e 0000                   movs       r0, r0
0x234c1f30                        db         0x0d
0x234c1f31                        db         0x01
0x234c1f32 0000                   movs       r0, r0
0x234c1f34 0000                   movs       r0, r0
0x234c1f36 0000                   movs       r0, r0
0x234c1f38 0000                   movs       r0, r0
0x234c1f3a 0000                   movs       r0, r0
#endif
};

static Menu_Item menu_main_items[] = //234c1f3c
{
	//[0]
	{
		0x4a, //"Einstellungen" / 'Settings'
		0xf3, //uint16_t wData_2; //2
		{
			&menu_main_graphic_items[5], //234c1974, //Data_4.Data_0
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23492fc4
	},
#if 0
	0x234c1f3c                        dw         0x004a                             ; DATA XREF=0x234c2048, 0x234c204c
	0x234c1f3e                        dw         0x00f3
	0x234c1f40                        dd         0x234c1974
	0x234c1f44                        dd         0x00000000
	0x234c1f48                        dd         0x00000000
	0x234c1f4c                        dd         0x00000000
	0x234c1f50                        dd         0x00000000
	0x234c1f54                        dd         0x00000000
	0x234c1f58                        dd         menu_main_items_on_event+1
	0x234c1f5c                        dd         sub_2344e2a6+1
	0x234c1f60                        dd         0x00000000
	0x234c1f64                        dd         0x00000000
#endif
	//[1]
	{
		0x79, //"Installation"
		0xf3, //uint16_t wData_2; //2
		{
			&menu_main_graphic_items[6], //234c19b4, //Data_4.Data_0
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23492fc4
	},
#if 0
	0x234c1f68                        dw         0x0079
	0x234c1f6a                        dw         0x00f3
	0x234c1f6c                        dd         0x234c19b4
	0x234c1f70                        dd         0x00000000
	0x234c1f74                        dd         0x00000000
	0x234c1f78                        dd         0x00000000
	0x234c1f7c                        dd         0x00000000
	0x234c1f80                        dd         0x00000000
	0x234c1f84                        dd         menu_main_items_on_event+1
	0x234c1f88                        dd         sub_2344e2a6+1
	0x234c1f8c                        dd         0x00000000
	0x234c1f90                        dd         0x00000000
#endif
	//[2]
	{
		0x44, //"Senderliste" / 'Channel list'
		0xf3, //uint16_t wData_2; //2
		{
			&menu_main_graphic_items[7], //234c19f4
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
	},
#if 0
0x234c1f94                        dw         0x0044
0x234c1f96                        dw         0x00f3
0x234c1f98                        dd         0x234c19f4
0x234c1f9c                        dd         0x00000000
0x234c1fa0                        dd         0x00000000
0x234c1fa4                        dd         0x00000000
0x234c1fa8                        dd         0x00000000
0x234c1fac                        dd         0x00000000
0x234c1fb0                        dd         menu_main_items_on_event+1
0x234c1fb4                        dd         menu_event_thread+1
0x234c1fb8                        dd         0x00000000
0x234c1fbc                        dd         0x00000000
#endif
	//[3]
	{
		0xa6, //"Timer"
		0xf3, //uint16_t wData_2; //2
		{
			&menu_main_graphic_items[8], //234c1a34
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
	},
#if 0
0x234c1fc0                        dw         0x00a6
0x234c1fc2                        dw         0x00f3
0x234c1fc4                        dd         0x234c1a34
0x234c1fc8                        dd         0x00000000
0x234c1fcc                        dd         0x00000000
0x234c1fd0                        dd         0x00000000
0x234c1fd4                        dd         0x00000000
0x234c1fd8                        dd         0x00000000
0x234c1fdc                        dd         menu_main_items_on_event+1
0x234c1fe0                        dd         menu_event_thread+1
0x234c1fe4                        dd         0x00000000
0x234c1fe8                        dd         0x00000000
#endif
	//[4]
	{
		0x3f, //"Information"
		0xf3, //uint16_t wData_2; //2
		{
			&menu_main_graphic_items[9], //234c1a74
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
	},
#if 0
0x234c1fec                        dw         0x003f
0x234c1fee                        dw         0x00f3
0x234c1ff0                        dd         0x234c1a74
0x234c1ff4                        dd         0x00000000
0x234c1ff8                        dd         0x00000000
0x234c1ffc                        dd         0x00000000
0x234c2000                        dd         0x00000000
0x234c2004                        dd         0x00000000
0x234c2008                        dd         menu_main_items_on_event+1
0x234c200c                        dd         menu_event_thread+1
0x234c2010                        dd         0x00000000
0x234c2014                        dd         0x00000000
#endif
	//[5]
	{
		0x118, //"Aufnahmespeicher"
		0xf3, //uint16_t wData_2; //2
		{
			&menu_main_graphic_items[11], //234c1af4
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
	},
#if 0
0x234c2018                        dw         0x0118
0x234c201a                        dw         0x00f3
0x234c201c                        dd         0x234c1af4
0x234c2020                        dd         0x00000000
0x234c2024                        dd         0x00000000
0x234c2028                        dd         0x00000000
0x234c202c                        dd         0x00000000
0x234c2030                        dd         0x00000000
0x234c2034                        dd         menu_main_items_on_event+1
0x234c2038                        dd         menu_event_thread+1
0x234c203c                        dd         0x00000000
0x234c2040                        dd         0x00000000
#endif
};

static Menu menu_main = //234c2044
{
    10, //"Hauptmenu"
    &menu_main_items[0], //Menu_Item* Data_4; //4
    &menu_main_items[0], //Menu_Item* Data_8; //8
    &menu_main_graphic_items[1], /*234c1874*/ //Struct_235fdf74_Inner12* header; //12 = 0xc
    &menu_main_graphic_items[3], /*234C18F4*/ //Struct_235fdf74_Inner16* help; //16 = 0x10
    &menu_main_graphic_data, //Graphic_Job_2_5* graphicData; //20 = 0x14
    5, //uint8_t maxItem; //0x18 = 24
    0, //int8_t currentItem; //0x19
    graphic_start_job_2_5, //void (*Data_0x1c)(); //0x1c
	menu_items_navigate, //void (*onNavigate)(); //0x20
    menu_main_on_enter, //void (*onEnter)(); //36 = 0x24
    menu_main_on_exit, //int (*onExit)(); //0x28
    0, //int Data_0x2c; //44 = 0x2c
    0, //int Data_0x30; //48
    0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
    0, //void* (*Data_0x38)(struct FrontDisplay_Job*); //56
    //0x3c = 60
#if 0
    0x234c2044                        dw         0x000a                             ; DATA XREF=sub_2344d060+4, sub_2344d3f0+6, sub_2344d3f0+12, sub_2344d3f0+18
    0x234c2046                        dw         0x0000
    0x234c2048                        dd         0x234c1f3c
    0x234c204c                        dd         0x234c1f3c
    0x234c2050                        dd         0x234c1874
    0x234c2054                        dd         0x234c18f4
    0x234c2058                        dd         0x234c1ef4                         ; DATA XREF=sub_2344d060+6
    0x234c205c 0500                   movs       r5, r0
    0x234c205e 0000                   movs       r0, r0
    0x234c2060                        dd         graphic_start_job_2_5
    0x234c2064                        dd         sub_2344dbb8+1
    0x234c2068                        dd         menu_main_on_enter+1
    0x234c206c                        dd         menu_main_on_exit+1
    0x234c2070 0000                   movs       r0, r0
    0x234c2072 0000                   movs       r0, r0
    0x234c2074                        dw         0x000a
    0x234c2076                        dw         0x0000
    0x234c2078                        dd         0x00000000
    0x234c207c                        dd         0x00000000
#endif
};

static Menu_Item menu_main_items_ex[] = //234c2080
{
	//[0]
	{
		0x004a, //"Einstellungen"
		0x0161, //uint16_t wData_2; //2
		{
			&menu_main_graphic_items_ex[5], //234c1cf4
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
	},
#if 0
0x234c2080                        dw         0x004a                             ; DATA XREF=0x234c218c, 0x234c2190
0x234c2082                        dw         0x0161
0x234c2084                        dd         menu_main_graphic_items_ex+320
0x234c2088 0000                   movs       r0, r0
0x234c208a 0000                   movs       r0, r0
0x234c208c 0000                   movs       r0, r0
0x234c208e 0000                   movs       r0, r0
0x234c2090 0000                   movs       r0, r0
0x234c2092 0000                   movs       r0, r0
0x234c2094 0000                   movs       r0, r0
0x234c2096 0000                   movs       r0, r0
0x234c2098 0000                   movs       r0, r0
0x234c209a 0000                   movs       r0, r0
0x234c209c                        dd         menu_main_items_on_event+1
0x234c20a0                        dd         menu_event_thread+1
0x234c20a4 0000                   movs       r0, r0
0x234c20a6 0000                   movs       r0, r0
0x234c20a8 0000                   movs       r0, r0
0x234c20aa 0000                   movs       r0, r0
#endif
	//[1]
	{
		0x0079, //"Installation"
		0x0161, //uint16_t wData_2; //2
		{
			&menu_main_graphic_items_ex[6], //234C1D34
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
	},
#if 0
0x234c20ac                        dw         0x0079
0x234c20ae                        dw         0x0161
0x234c20b0                        dd         menu_main_graphic_items_ex+384
0x234c20b4 0000                   movs       r0, r0
0x234c20b6 0000                   movs       r0, r0
0x234c20b8 0000                   movs       r0, r0
0x234c20ba 0000                   movs       r0, r0
0x234c20bc 0000                   movs       r0, r0
0x234c20be 0000                   movs       r0, r0
0x234c20c0 0000                   movs       r0, r0
0x234c20c2 0000                   movs       r0, r0
0x234c20c4 0000                   movs       r0, r0
0x234c20c6 0000                   movs       r0, r0
0x234c20c8                        dd         menu_main_items_on_event+1
0x234c20cc                        dd         menu_event_thread+1
0x234c20d0 0000                   movs       r0, r0
0x234c20d2 0000                   movs       r0, r0
0x234c20d4 0000                   movs       r0, r0
0x234c20d6 0000                   movs       r0, r0
#endif
	//[2]
	{
		0x0044, //"Senderliste"
		0x0161, //uint16_t wData_2; //2
		{
			&menu_main_graphic_items_ex[7], //234C1D74
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
	},
#if 0
0x234c20d8                        dw         0x0044
0x234c20da                        dw         0x0161
0x234c20dc                        dd         menu_main_graphic_items_ex+448
0x234c20e0 0000                   movs       r0, r0
0x234c20e2 0000                   movs       r0, r0
0x234c20e4 0000                   movs       r0, r0
0x234c20e6 0000                   movs       r0, r0
0x234c20e8 0000                   movs       r0, r0
0x234c20ea 0000                   movs       r0, r0
0x234c20ec 0000                   movs       r0, r0
0x234c20ee 0000                   movs       r0, r0
0x234c20f0 0000                   movs       r0, r0
0x234c20f2 0000                   movs       r0, r0
0x234c20f4                        dd         menu_main_items_on_event+1
0x234c20f8                        dd         menu_event_thread+1
0x234c20fc 0000                   movs       r0, r0
0x234c20fe 0000                   movs       r0, r0
0x234c2100 0000                   movs       r0, r0
0x234c2102 0000                   movs       r0, r0
#endif
	//[3]
	{
		0x00a6, //"Timer"
		0x0161, //uint16_t wData_2; //2
		{
			&menu_main_graphic_items_ex[8], //234C1DB4
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
	},
#if 0
0x234c2104                        dw         0x00a6
0x234c2106                        dw         0x0161
0x234c2108                        dd         menu_main_graphic_items_ex+512
0x234c210c 0000                   movs       r0, r0
0x234c210e 0000                   movs       r0, r0
0x234c2110 0000                   movs       r0, r0
0x234c2112 0000                   movs       r0, r0
0x234c2114 0000                   movs       r0, r0
0x234c2116 0000                   movs       r0, r0
0x234c2118 0000                   movs       r0, r0
0x234c211a 0000                   movs       r0, r0
0x234c211c 0000                   movs       r0, r0
0x234c211e 0000                   movs       r0, r0
0x234c2120                        dd         menu_main_items_on_event+1
0x234c2124                        dd         menu_event_thread+1
0x234c2128 0000                   movs       r0, r0
0x234c212a 0000                   movs       r0, r0
0x234c212c 0000                   movs       r0, r0
0x234c212e 0000                   movs       r0, r0
#endif
	//[4]
	{
		0x003f, //"Information"
		0x0161, //uint16_t wData_2; //2
		{
			&menu_main_graphic_items_ex[9], //234C1DF4
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
	},
#if 0
0x234c2130                        dw         0x003f
0x234c2132                        dw         0x0161
0x234c2134                        dd         menu_main_graphic_items_ex+576
0x234c2138 0000                   movs       r0, r0
0x234c213a 0000                   movs       r0, r0
0x234c213c 0000                   movs       r0, r0
0x234c213e 0000                   movs       r0, r0
0x234c2140 0000                   movs       r0, r0
0x234c2142 0000                   movs       r0, r0
0x234c2144                        dd         0x00000000
0x234c2148 0000                   movs       r0, r0
0x234c214a 0000                   movs       r0, r0
0x234c214c                        dd         menu_main_items_on_event+1
0x234c2150                        dd         menu_event_thread+1
0x234c2154 0000                   movs       r0, r0
0x234c2156 0000                   movs       r0, r0
0x234c2158 0000                   movs       r0, r0
0x234c215a 0000                   movs       r0, r0
#endif
	//[5]
	{
		0x0118, //"Aufnahmespeicher"
		0x0161, //uint16_t wData_2; //2
		{
			&menu_main_graphic_items_ex[11], //234C1E74
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_main_items_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
	}
#if 0
0x234c215c                        dw         0x0118
0x234c215e                        dw         0x0161
0x234c2160                        dd         menu_main_graphic_items_ex+704
0x234c2164 0000                   movs       r0, r0
0x234c2166 0000                   movs       r0, r0
0x234c2168 0000                   movs       r0, r0
0x234c216a 0000                   movs       r0, r0
0x234c216c 0000                   movs       r0, r0
0x234c216e 0000                   movs       r0, r0
0x234c2170 0000                   movs       r0, r0
0x234c2172 0000                   movs       r0, r0
0x234c2174 0000                   movs       r0, r0
0x234c2176 0000                   movs       r0, r0
0x234c2178                        dd         menu_main_items_on_event+1
0x234c217c                        dd         menu_event_thread+1
0x234c2180 0000                   movs       r0, r0
0x234c2182 0000                   movs       r0, r0
0x234c2184 0000                   movs       r0, r0
0x234c2186 0000                   movs       r0, r0
#endif
};

/* TODO!!! item:....*/
static Menu menu_main_ex = //234c2188
{
    10, //"Hauptmenu"
    &menu_main_items_ex[0], //Menu_Item* Data_4; //4
    &menu_main_items_ex[0], //Menu_Item* Data_8; //8
    &menu_main_graphic_items_ex[1], /*234c1bf4*/ //Struct_235fdf74_Inner12* header; //12 = 0xc
    &menu_main_graphic_items_ex[3], /*234c1c74*/ //Struct_235fdf74_Inner16* help; //16 = 0x10
    &menu_main_graphic_data_ex, //Graphic_Job_2_5* graphicData; //20 = 0x14
    5, //uint8_t maxItem; //0x18 = 24
    0, //int8_t currentItem; //0x19
    graphic_start_job_2_5, //void (*Data_0x1c)(); //0x1c
	sub_2344dcb2, //void (*onNavigate)(); //0x20
    menu_main_on_enter, //void (*onEnter)(); //36 = 0x24
    menu_main_on_exit, //int (*onExit)(); //0x28
    0, //int Data_0x2c; //44 = 0x2c
    10, //int timeout; //48
    sub_2344d9d0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
    0, //void* (*Data_0x38)(struct FrontDisplay_Job*); //56
    //0x3c = 60
#if 0
0x234c2188                        dw         0x000a                             ; DATA XREF=0x234c1270
0x234c218a                        dw         0x0000
0x234c218c                        dd         0x234c2080
0x234c2190                        dd         0x234c2080
0x234c2194                        dd         0x234c1bf4
0x234c2198                        dd         0x234c1c74
0x234c219c                        dd         0x234c1f18
0x234c21a0 0500                   movs       r5, r0
0x234c21a2 0000                   movs       r0, r0
0x234c21a4                        dd         graphic_start_job_2_5
0x234c21a8                        dd         sub_2344dcb2+1
0x234c21ac                        dd         menu_main_on_enter+1
0x234c21b0                        dd         menu_main_on_exit+1
0x234c21b4                        dd         0x00000000
0x234c21b8                        dd         0x0000000a
0x234c21bc                        dd         sub_2344d9d0+1
0x234c21c0                        dd         0x00000000
#endif
};


/*  /  / 2344cf8c - todo */
int menu_main_items_on_event(void* r0)
{
	Graphic_Queue_Item sp8;
	struct
	{
		int Data_0;
	} sp4;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "menu_main_items_on_event: r0=%p\r\n", r0);
		console_send_string(debug_string);
	}
#endif

	if (r0 != 0)
	{
		//0x2344cf96
		if (menu_main_current_flavor->currentItem == 0)
		{
			//0x2344cfa0: Einstellungen
			menu_settings_entry(r0);
			//->loc_2344d05a
		}
		//loc_2344cfa6
		else if (menu_main_current_flavor->currentItem == 1)
		{
			//0x2344cfaa: Installation
			menu_installation_entry(r0);
			//->loc_2344d05a
		}
		//loc_2344cfb0
		else if (menu_main_current_flavor->currentItem == 2)
		{
			//0x2344cfb4: Senderliste
			menu_channel_list_entry(r0);
			//->loc_2344d05a
		}
		//loc_2344cfba
		else if (menu_main_current_flavor->currentItem == 3)
		{
			//0x2344cfbe: Timer
#if 0
			sub_23492b34();
#endif
			//->loc_2344d05a
		}
		//loc_2344cfc4
		else if (menu_main_current_flavor->currentItem == 4)
		{
			//0x2344cfc8: Information
			menu_information_entry(r0);
			//->loc_2344d05a
		}
		//loc_2344cfce
		else if (menu_main_current_flavor->currentItem == 5)
		{
			//0x2344cfc8: Aufnahmespeicher
#if 0
			sub_23497aa0();
#endif
			//->loc_2344d05a
		}
		//loc_2344d05a
	} //if (r0 != 0)
	else
	{
		//loc_2344cfd8
		Data_234c1244 = musb_msd_get_device(0);
		if (Data_234c1244 != Data_234c1248)
		{
			//0x2344cfe6
			Graphic_Job_2_5* r4 = menu_main_current_flavor->graphicData;
			//r3 = 0x2C0;
			//r6 = 0x240;

			if (Data_234c1244 != 0)
			{
				//0x2344cff6
				r4->wData_2 = 5;
				r4->pItems[4].height/*0x112*/ = 0xcc;
				r4->pItems[11].bEnable/*0x2c0*/ = 1; //r2
				r4->pItems[9].background/*0x258*/ = r4->pItems[7].background/*0x1c0*/;
			}
			else
			{
				//loc_2344d01a
				r4->wData_2 = 4;
				r4->pItems[4].height/*0x112*/ = 0xac;
				r4->pItems[11].bEnable/*0x2c0*/ = 0; //r2
				r4->pItems[9].background/*0x258*/ = r4->pItems[11].background/*0x2d8*/;

				if (menu_main_current_flavor->currentItem == 5)
				{
					//0x2344d042
					sp4.Data_0 = 2;
					(menu_main_current_flavor->onNavigate)(&sp4);
				}
				//loc_2344d04e
			}
			//loc_2344d04e
			graphic_start_job_2_5(&sp8, r4);
		}
		//loc_2344d056
		Data_234c1248 = Data_234c1244;
	}
	//loc_2344d05a
	return 0;
}


/*  /  / 2344d060 - todo */
int menu_main_on_enter(int a)
{
#if 0
	console_send_string("menu_main_on_enter (todo.c): TODO\r\n");
#endif

	Graphic_Job_2_5* r4 = menu_main_current_flavor->graphicData;

	Data_234c1248 = Data_234c1244 = musb_msd_get_device(0);

	r4->pItems[10].bEnable = 0;

	if (Data_234c1244 != 0)
	{
		r4->wData_2 = 5;

		r4->pItems[4].height = 0xcc;
		r4->pItems[11].bEnable = 1;
		r4->pItems[9].background = r4->pItems[7].background;
	}
	else
	{
		//loc_2344d0aa
		r4->wData_2 = 4;

		r4->pItems[4].height = 0xac;
		r4->pItems[11].bEnable = 0;
		r4->pItems[9].background = r4->pItems[11].background;
	}

	return 0;
}


/*  /  / 2344d0cc - complete */
int menu_main_on_exit(void)
{
#if 0
	console_send_string("menu_main_on_exit (todo.c): TODO\r\n");
#endif

	return 0;
}


/*  /  / 2344d0d0 - todo */
void* sub_2344d0d0(FrontDisplay_Job* r4)
{
#if 0
	console_send_string("sub_2344d0d0 (todo.c): TODO\r\n");
#endif

	struct Menu_Data* r0 = sub_2344de8e();

	//void* sp_0x40 = &r0->Data_0x40;
	FrontDisplay_Job* sp_0x3c;
	uint8_t* sp_0x38;
	uint8_t* sp_0x34;
	FrontDisplay_Job* sp_0x30;
	uint8_t sp_0x2c[4];

#if 0
	struct
	{
		int fill_0[5]; //0
		struct
		{
			uint16_t fill_0; //0
			uint16_t wData_2; //2

		}* Data_0x14; //20 = 0x14

	}
#endif
	Menu* r6 = r0->menu_stack[r0->menu_stack_level];

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2344d0d0: r0->menu_stack_level=%d, r6=%p\r\n",
				r0->menu_stack_level, r6);
		console_send_string(debug_string);
	}
#endif

	sp_0x2c[0] = 0;
	sp_0x30 = r4;

	uint8_t sp_0xc[32] = "default"; //234b49e4
	uint8_t* sp8 = &sp_0xc[0];
	uint8_t sp4;
	int sp;

	sp_0x3c = &r4[1];
	sp_0x38 = &r4->bData_8[0];

	int r7 = 0;
	//r5 = &r4->0x100;

	if ((r6 == 0) || (r6->graphicData->wData_2 == 1))
	{
		//loc_2344d11c
		sp = sub_23451f60();
		if (sp != 0)
		{
			//0x2344d126
	        console_send_string("sub_2344d0d0: 0x2344d126: TODO!!!\r\n");
#if 0 //TODO!!!
			if (0 != sub_23421f84()) //-> recording?
			{
				//0x2344d12e
				sp_0x2c[r7] = 0x1b;
				r7++;
			}
			//loc_2344d136
			sp_0x2c[r7] = 0x1a;
			r7++;
			sp4 = r7;

			strncpy(sp_0x38, sp_0x2c, 0xff);

			/*r5->8*/r4->bNumTextChars = strlen(sp_0x38);
			//r6 = 0;
			r4->bDisplayOffset = 0; //r6
			r4->bNumDisplayChars = 3;
			r4->bData_0x10b = 0; //r6
			r4->bData_0x10c = 0; //r6
			r4->holdTime = 0; //r6
			r4->Data_0 = frontdisplay_draw_text;
			r4->Data_4 = 0;
			r4->bData_0x10f = 0; //r6
			//0x2344d168
			//r5 = sp_0x3c

			if (0 != sub_234210bc())
			{
				//0x2344d172
				//r0 = sp + 8;
				//->loc_2344d188
				sp8 = (void*) (sp + 8);
			}
			else
			{
				//loc_2344d178
				if (0 != sub_2341e2e4())
				{
					//0x2344d182
					sp8 = (void*) sub_2341e3c4(sp);
				}
			}
			//loc_2344d18a
			strncpy(/*r4 = r5->8*/sp_0x3c->bData_8, sp8, 0xff);
			sp_0x3c->bNumTextChars = strlen(sp_0x3c->bData_8);
			sp_0x3c->bDisplayOffset = sp4;
			sp_0x3c->bNumDisplayChars = 12;
			sp_0x3c->bData_0x10b = 0; //r6
			sp_0x3c->bData_0x10c = 0; //r6
			sp_0x3c->bData_0x110 = 0; //r6
			sp_0x3c->holdTime = 0; //r6
			sp_0x3c->Data_0 = frontdisplay_draw_text;
			sp_0x3c->Data_4 = 0; //r6
			sp_0x3c->bData_0x10f = 0; //r6

			if ((sp_0x3c->bNumDisplayChars - sp_0x3c->bDisplayOffset) < sp_0x3c->bNumTextChars)
			{
				//0x2344d1c4
				sp_0x3c->bData_0x10c = 1;
				sp_0x3c->Data_0 = frontdisplay_draw_scroll_text;
			}
#endif //TODO
			//->loc_2344d21e
		} //if (sp != 0)
		else
		{
			//loc_2344d1ce
			if ((Data_234c124c != 0) &&
					(0 == (Data_234c124c)(&sp8)))
			{
				//0x2344d1de
				strncpy(sp_0x38, sp8, 0xff);

				/*r5->8*/r4->bNumTextChars = strlen(sp_0x38);
				r4->bDisplayOffset = r7; //0
				r4->bNumDisplayChars = 12;
				r4->bData_0x10b = 0;
				r4->bData_0x10c = 0;
				r4->bData_0x110 = 0;
				r4->holdTime = 0;
				r4->Data_0 = frontdisplay_draw_text;
				r4->Data_4 = 0;
				r4->bData_0x10f = 0;

				if (r4->bNumTextChars > 12)
				{
					//0x2344d20e
					r4->bData_0x10c = 1;
					r4->Data_0 = frontdisplay_draw_scroll_text;
				}
				//->loc_2344d21e
			}
			else
			{
				//loc_2344d21a
				sub_23418f80();
			}
			//loc_2344d21e
		}
		//loc_2344d21e
		Data_234c1250 = 0;
		//->loc_2344d2d0
		return 0;
	} //if ((r6 == 0) || (r6->Data_0x14->wData_2 == 1))
	else
	{
		//loc_2344d218 -> loc_2344d226
		if (/*sp_0x40->bData_0x10*/r0->menu_stack_level == 0)
		{
			//0x2344d22e

			//TODO!!!
			console_send_string("sub_2344d0d0: 0x2344d22e TODO!!!\r\n");

			//->loc_2344d2be
		} //if (/*sp_0x40->bData_0x10*/r0->bData_237967d4 == 0)
		else
		{
			//loc_2344d25a
			if ((Data_234c1250 != r6) &&
					//0x2344d262
					(r6->header != 0) &&
					//0x2344d268
					(r6->header->pText != 0))
			{
				//0x2344d26e: Handle Menu Header
#if 0
    			console_send_string("sub_2344d0d0: 0x2344d26e: TODO!!!\r\n");
#endif
				r4->bData_8[0] = '"'; //r7

				strncpy(&r4->bData_8[1], r6->header->pText->pString, 10);

				uint8_t r0 = (uint8_t) strlen(sp_0x38);
				r4->bData_8[r0] = '"'; //r7
				r0++;
				r4->bData_8[r0] = 0; //r7
				r4->bNumTextChars = strlen(sp_0x38);
				r4->bDisplayOffset = 0; //r7
				r4->bNumDisplayChars = 12;
				r4->bData_0x10b = 0; //r7
				r4->bData_0x10c = 0; //r7
				r4->bData_0x110 = 0; //r7
				r4->holdTime = 20;
				r4->Data_0 = frontdisplay_draw_text;
				r4->Data_4 = 0; //r7
				r4->bData_0x10f = 1;

				Data_234c1250 = r6;

				if (r6->Data_0x38 == 0)
				{
					//loc_2344d2be
					return sub_2344d0d0;
				}
				else
				{
					//loc_2344d2c0
					return r6->Data_0x38;
				}
			} //if ((Data_234c1250 != r6) && (r6->Data_0xc != 0) && (r6->Data_0xc->pText != 0))
			else
			{
				//loc_2344d2c4: Handle (current) Menu Item
				Menu_Item* pMenuItem = r6->pCurrentItem;

				if (pMenuItem == 0)
				{
					//->loc_2344d2d0
					return 0;
				}

				Graphic_Job_2_5_Item* r0_ = pMenuItem->Data_4[0];
				if (r0_ == NULL)
				{
					//->loc_2344d2d0: No Columns
					return 0;
				}
				//loc_2344d2d4: Column 1
				Graphic_Job_2_5_Item_Text* r0 = r0_->pText;

				if (r0 != 0)
				{
					//0x2344d2da
#if 0
					{
						extern char debug_string[];
						sprintf(debug_string, "sub_2344d0d0: r0->Data_0x10='%s'\r\n",
								r0->Data_0x10);
						console_send_string(debug_string);
					}
#endif
					strncpy(sp_0x38, r0->pString, 0xff);

					r4->bData_8[255] = 0;
					r4->bNumTextChars = strlen(sp_0x38);
					r4->bDisplayOffset = 0;
					r4->bNumDisplayChars = 12;
					r4->bData_0x10b = 0;
					r4->bData_0x10c = 0;
					r4->bData_0x110 = 0;
					r4->holdTime = 0;
					r4->Data_4 = 0;
					r4->Data_0 = frontdisplay_draw_text;
					r4->bData_0x10f = 0;

					if (Data_234c1250 != r6)
					{
						//0x2344d316
						r4->bData_0x10f = 1;
					}
					//loc_2344d31a
					if (r4->bNumTextChars > 12)
					{
						//0x2344d31e
						r4->bData_0x10c = 1;
						r4->Data_0 = frontdisplay_draw_scroll_text;
					}
					//loc_2344d326
					r4 = sp_0x3c;
				} //if (r0 != 0)
				//loc_2344d328
				r0_ = pMenuItem->Data_4[1];
				if (r0_ != 0)
				{
					//0x2344d32e: Column 2
					if (r0_->pText != 0)
					{
						//0x2344d334
						sp_0x34 = r4->bData_8;

						strncpy(sp_0x34, r0_->pText->pString, 0xff);

						r4->bData_8[0xff] = 0;

						r4->bNumTextChars = strlen(sp_0x34);

						r4->bDisplayOffset = 6;
						r4->bNumDisplayChars = 12;
						int ip = 6;
						if (r4->bNumTextChars < 6)
						{
							//0x2344d364
							r4->bDisplayOffset = (r4->bNumDisplayChars - r4->bNumTextChars) - 1;
						}
						//loc_2344d36a
						if (sp_0x30->bNumTextChars < r4->bDisplayOffset)
						{
							//0x2344d378
							r4->bDisplayOffset = sp_0x30->bNumTextChars;

							ip = r4->bNumDisplayChars - r4->bDisplayOffset;
						}
						//loc_2344d380
						r4->bData_0x10b = 0;
						r4->bData_0x10c = 0;
						r4->bData_0x110 = 1;
						r4->holdTime = 0;
						r4->bData_0x10f = 0;
						r4->Data_4 = 0;
						r4->Data_0 = frontdisplay_draw_text;
						sp_0x30->holdTime = 10;

						if (r4->bNumTextChars > ip)
						{
							//0x2344d3c0
							r4->Data_0 = frontdisplay_draw_scroll_text;
							r4->bData_0x10c = 1;
						}
						//loc_2344d3c6
						if (Data_234c1254 != pMenuItem)
						{
							//0x2344d3ce
							r4->bData_0x10f = 1;
							//->loc_2344d3e4
						}
						else
						{
							//loc_2344d3d2
							if (r4->bNumTextChars < bData_234c1230)
							{
								//0x2344d3d8
								sp_0x30->bData_0x10f = 1;
								sp_0x30->Data_0 = frontdisplay_draw_text;
								sp_0x30->holdTime = 0;
							}
							//loc_2344d3e4
						}
						//loc_2344d3e4
						bData_234c1230 = r4->bNumTextChars;
					} //if (r0_->pText != 0)
					//loc_2344d3e8
				} //if (r0_ != 0)
				//loc_2344d3e8
				Data_234c1254 = pMenuItem;
				Data_234c1250 = r6;
				//->loc_2344d2be
				return sub_2344d0d0;
			}
		}
	}
}


/*  /  / 2344d3f0 - todo */
int menu_main_entry(UI_Thread_Params* r5)
{
#if 0
	console_send_string("menu_main_entry (todo.c): TODO\r\n");
#endif

	menu_stack_operate(menu_main_current_flavor);

	menu_initialize(menu_main_current_flavor);

	sub_2343d51e(menu_main_current_flavor, r5);

	frontdisplay_start_text(sub_2344d0d0);

	return 0;
}


/*  /  / 2344d414 - complete */
int sub_2344d414(UI_Thread_Params* r4)
{
	User_Settings sp4;

#if 0
	console_send_string("sub_2344d414 (todo.c): TODO\r\n");
#endif

	sub_2343d458(r4);

	channel_handle_user_settings(1, &sp4);

	if (((sp4.Data_0x10 & 0x30) >> 4) != 0)
	{
		menu_pin_entry(r4, 1);
	}
	else
	{
		menu_main_entry(r4);
	}

	return 0;
}


/* /  /  2344d444 - todo */
void sub_2344d444(int r4)
{
	console_send_string("sub_2344d444 (todo.c): TODO\r\n");

}


/* / 2344bfe6 / 2344d610 - todo */
int sub_2344d610(int r6, int (r4)(Amplifier_Interface_Functions*, Amplifier_Settings*, uint8_t*, uint8_t*))
{
#if 0
	console_send_string("sub_2344d610 (todo.c): TODO\r\n");
#endif

	User_Settings sp_0x3c;
#if 0
	struct 
	{
		int fill_0[14]; //0
		int Data_0x38; //0x38 = 56
	} 
#else	
	Amplifier_Interface_Functions
#endif
	sp;

	Data_234c1258 = OSSemCreate(1);

	sub_2348d6c0();
	sub_2349235e();

	channel_handle_user_settings(1, &sp_0x3c);

	sub_2340f838(sub_2348d742);

	sub_2344d5dc(sp_0x3c.bData_0x19);

	sub_2344d444((sp_0x3c.Data_0x10 & (0x7 << 8)) >> 8);

	sub_23492670(sp_0x3c.bData_0x19);

	if ((sp_0x3c.Data_0x10 & (0x1 << 15)))
	{
		sub_2345112e(sub_2349972e);
	}
	else
	{
		sub_2345112e(0);
	}
	//0x2344d662
	if (r6 != 0)
	{
		sub_23490ac2(1);
		sub_2345a49e(0x35, (sp_0x3c.Data_0x10 & (0x1 << 11)) >> 11, 
			sub_23424398);
	}
	else
	{
		//loc_2344d676
		sub_23490ac2(0);
		sub_2345a49e(0x35, (sp_0x3c.Data_0x10 & (0x1 << 11)) >> 11, 
			0);
	}

	if (0 != network_get_device())
	{
		sub_2348c74a();
	}
	//loc_2344d696
	if (r4 != 0)
	{
		if (0 == (r4)(&sp, 0, 0, 0))
		{
			//0x2344d6a8
			Data_234c124c = sp.Data_235fc464;

			sub_2348c7aa();
			sub_2349a24e(r4);
			sub_2349a84c(r4);
			sub_2349aef4(r4);
		}
		//loc_2344d6c2
	}
	//loc_2344d6c2
	sub_2340fc20(sub_23491634);

	return 0;
}


/*  / 2344c0a4 / 2344d6ce - todo */
void sub_2344d6ce(uint8_t r5)
{
	uint8_t err; //sp

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2344d6ce: r5=%d\r\n", r5);
		console_send_string(debug_string);
	}
#endif

	if (r5 < 2)
	{
		//0x2344d6d6
		OSSemPend(Data_234c1258, 0, &err);
		if (err == 0)
		{
			menu_main_current_flavor = menu_main_flavor[r5];
			Data_234c1234 = Data_234c125c[r5];
			Data_234c1238 = Data_234c1264[r5];

			menu_settings_set_flavor(r5); //->menu_settings.c
			sub_23452a3e(r5);
			sub_23490c8a(r5);
			sub_23492b52(r5);
			menu_information_set_flavor(r5); //->menu_information.c
			menu_general_settings_set_flavor(r5); //->menu_general_settings.c
			sub_23493072(r5);
			sub_234911ba(r5);
			sub_23495a48(r5);
			sub_2349269c(r5);
			sub_23457a8a(r5);
			sub_234911fe(r5);
			sub_23498c7e(r5);
			sub_234543ba(r5);
			sub_234904ba(r5);
			sub_2348e07a(r5);
			sub_2348f1a6(r5);
			sub_23496a26(r5);
			sub_2345a87e(r5);
			sub_23497004(r5);
			sub_23456f24(r5);
			sub_23497728(r5);
			sub_2345c8ee(r5);
			sub_23497ac6(r5);
			sub_234923b0(r5);
			sub_23492a56(r5);
			sub_2345517e(r5);
			sub_234966b4(r5);
			//->loc_2344d7d4
			sub_2345b8d2(r5);
			sub_2345af0c(r5);
			sub_23493734(r5);
			sub_23494dea(r5);
			menu_volume_bar_set_flavor(r5); //->menu_volume_bar.c
			menu_info_bar_set_flavor(r5); //->menu_info_bar.c
			sub_2349827a(r5);
			sub_234995f4(r5);
			sub_23499782(r5);
			sub_23499946(r5);
			sub_2349af36(r5);
			sub_2349a854(r5);
			sub_2349aefa(r5);
			sub_2349a276(r5);
			sub_2349b6d6(r5);
			sub_2349b96c(r5);
			sub_23498eee(r5);
			sub_2349bcb6(r5);
			sub_23495636(r5);
			//0x2344d848
			OSSemPost(Data_234c1258);
		}
		//loc_2344d7ae -> loc_2344d84c
	}
	else
	{
		//loc_2344d7ae -> loc_2344d84c
	}
	//loc_2344d84c
}

#endif //VDR110
