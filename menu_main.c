
#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "menu.h"

#ifndef VDR110

#pragma thumb

static uint32_t menu_main_clut[]; //234c1388
static Menu menu_main; //234c2044

static int menu_main_on_enter(int);
static int menu_main_on_exit(void);
static int menu_main_items_on_event(void*);

//0x234c1230
uint8_t bData_234c1230 = 0; //234c1230 +0
Graphic_Color_Data menu_main_graphic_color_data = //234c123c
{
	&menu_main_clut[0],
};
Menu* Data_234c1240 = &menu_main; //234C1240 +0x10
int Data_234c1244; //234c1244 +0x14
int Data_234c1248; //234c1248 +0x18
int (*Data_234c124c)() = 0; //234C124C +0x1c
Menu* Data_234c1250 = 0; //234c1250 +0x20
Menu_Item* Data_234c1254 = 0; //234c1254 +0x24

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c128c = //234c128c
{
	14, 5, 0x0f, //...
#if 0
0x234c128c                        dw         0x000e                             ; DATA XREF=sub_2344d444+18, sub_2344d444+232, sub_2348c844+46, 0x234c184c, dword_234eb848, 0x234eef50, dword_234f4b30
0x234c128e 0000                   movs       r0, r0
0x234c1290                        dd         0x00000005
0x234c1294                        db         0x0f
#endif
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c1298 = //234c1298
{
	9, 4, 0x03, //...
#if 0
0x234c1298 0900                   movs       r1, r1                             ; DATA XREF=sub_2344d444+238, 0x234c198c
0x234c129a 0000                   movs       r0, r0
0x234c129c                        dd         0x00000004                         ; DATA XREF=sub_2344d444+240
0x234c12a0                        db         0x03
#endif
};

Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12a4 = //234c12a4
{
	9, 4, 0x0b, //...
#if 0
0x234c12a4 0900                   movs       r1, r1                             ; DATA XREF=sub_2344d444+244, 0x234e9aec, 0x234eaf94, 0x234ef4d0, 0x234efb10, 0x234f5b54
0x234c12a6 0000                   movs       r0, r0
0x234c12a8                        dd         0x00000004                         ; DATA XREF=sub_2344d444+246
0x234c12ac                        db         0x0b
#endif
};

Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12d4 = //234c12d4
{
	14, 0, 0x06, //...
#if 0
0x234c12d4 0E00                   movs       r6, r1                             ; DATA XREF=sub_2344d444+268, sub_234533bc+118, sub_234533bc+872, dword_234537d4, sub_234538b0+112, dword_23453c9c, sub_23459656+196, sub_2345afa4+190, dword_2345b32c, sub_2349511c+192, dword_23495360
0x234c12d6 0000                   movs       r0, r0
0x234c12d8                        dd         0x00000000                         ; DATA XREF=sub_2344d444+270
0x234c12dc                        db         0x06
#endif
};

Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12ec = //234c12ec
{
	9, 4, 0x0c, //...
#if 0
0x234c12ec                        dw         0x0009                             ; DATA XREF=sub_2344d444+280, sub_234523c8+376, sub_234523c8+474, sub_234523c8+536, sub_234523c8+604, sub_234523c8+664, sub_23452a3e+20, dword_23452a98, sub_2345afa4+264, dword_2345b338, sub_2348c8d4+252
0x234c12ee                        dw         0x0000
0x234c12f0                        dd         0x00000004                         ; DATA XREF=sub_2344d444+282, dword_234c1158+8
0x234c12f4                        db         0x0c
#endif
};

Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12f8 = //234c12f8
{
	9, 4, 0x03, //...
#if 0
0x234c12f8 0900                   movs       r1, r1                             ; DATA XREF=sub_2344d444+286, sub_2345afa4+186, dword_2345b328, 0x234df4c0
0x234c12fa 0000                   movs       r0, r0
0x234c12fc                        dd         0x00000004                         ; DATA XREF=sub_2344d444+288
0x234c1300                        db         0x03
#endif
};

Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c134c = //234c134c
{
	9, 4, 0x0f, //...
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
	{1, 0, 0/*&Data_234c1544*//*Data_4?*/, 0/*Data_8*/, 0x37, 0x23, 0x106, 0x32, 0, &Data_234c128c/*Data_0x18*/, 9, 0, 0, {0}, 0}, //[0] = 234c1834
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
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x29, 0xfa, 0x26, 0, &Data_234c134c/*Data_0x18*/, 2, 0, &menu_main_graphic_header_text_item/*Data_0x20*/}, //[1] = 234C1874 = header
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
	{1, 0, 0, 0/*Data_8*/, 0x37, 0x5a, 0x106, 0xac, 0, &Data_234c128c/*Data_0x18*/, 2, 0, 0/*Data_0x20*/}, //[4] = 234C1934
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
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xa0, 0xfa, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &menu_main_graphic_text_item_3/*Data_0x20*/}, //[7] = 234C19F4 
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
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xc0, 0xfa, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &menu_main_graphic_text_item_4}, //[8] = 234C1A34
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
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xe0, 0xfa, 0x20, 0, &Data_234c12ec/*Data_0x18*/, 9, 0, &menu_main_graphic_text_item_5}, //[9] = 234C1A74
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
	{0, 0, 0, 0/*Data_8*/, 0x3d, 0x100, 0xfa, 0x20, 0, &Data_234c12ec/*Data_0x18*/, 9, 0, &menu_main_graphic_text_item_6}, //[11] = 234C1AF4
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

#if 0
static Struct_235fdf74_Inner12 Data_234c1874 = //234c1874
{
	{0, 0, 0, 0, 0, 0, 0, 0}, //TODO
	&Data_234c158c, //Data_0x20
#if 0
	0x234c1874 0100                   movs       r1, r0                             ; DATA XREF=0x234c2050
	0x234c1876 0000                   movs       r0, r0
	0x234c1878                        dd         0x234c1544
	0x234c187c 0000                   movs       r0, r0
	0x234c187e 0000                   movs       r0, r0
	0x234c1880 3D00                   movs       r5, r7
	0x234c1882 2900                   movs       r1, r5
	0x234c1884 FA00                   lsls       r2, r7, #0x3
	0x234c1886 2600                   movs       r6, r4
	0x234c1888 0000                   movs       r0, r0
	0x234c188a 0000                   movs       r0, r0
	0x234c188c                        dd         0x234c134c
	0x234c1890 0200                   movs       r2, r0
	0x234c1892 0000                   movs       r0, r0
	0x234c1894                        dd         0x234c158c
#endif
};
#endif

#if 0
static Menu_Item_Inner4_Data_0 Data_234c1974 = //234c1974
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234c16dc, //Data_0x20
#if 0
	0x234c1974 0100                   movs       r1, r0                             ; DATA XREF=0x234c1f40
	0x234c1976 0000                   movs       r0, r0
	0x234c1978                        dd         0x234c1548
	0x234c197c 0000                   movs       r0, r0
	0x234c197e 0000                   movs       r0, r0
	0x234c1980 3D00                   movs       r5, r7
	0x234c1982 6000                   lsls       r0, r4, #0x1
	0x234c1984 FA00                   lsls       r2, r7, #0x3
	0x234c1986 2000                   movs       r0, r4
	0x234c1988 0000                   movs       r0, r0
	0x234c198a 0000                   movs       r0, r0
	0x234c198c                        dd         0x234c1298
	0x234c1990 0900                   movs       r1, r1
	0x234c1992 0000                   movs       r0, r0
	0x234c1994                        dd         0x234c16dc
#endif
};
#endif

#if 0
static Menu_Item_Inner4_Data_0 Data_234c19b4 = //234c19b4
{
	1,
	{0, 0, 0, 0, 0, 0}, //TODO
	0,
	&Data_234c171c, //Data_0x20
#if 0
	0x234c19b4 0100                   movs       r1, r0                             ; DATA XREF=0x234c1f6c
	0x234c19b6 0000                   movs       r0, r0
	0x234c19b8                        dd         0x234c1548
	0x234c19bc 0000                   movs       r0, r0
	0x234c19be 0000                   movs       r0, r0
	0x234c19c0 3D00                   movs       r5, r7
	0x234c19c2 8000                   lsls       r0, r0, #0x2
	0x234c19c4 FA00                   lsls       r2, r7, #0x3
	0x234c19c6 2000                   movs       r0, r4
	0x234c19c8 0000                   movs       r0, r0
	0x234c19ca 0000                   movs       r0, r0
	0x234c19cc                        dd         0x234c12d4
	0x234c19d0 0900                   movs       r1, r1
	0x234c19d2 0000                   movs       r0, r0
	0x234c19d4                        dd         0x234c171c
#endif
};
#endif

#if 1
static Graphic_Job_2_5 menu_main_graphic_data = //234c1ef4
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x0004, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&menu_main_graphic_items[0], //int Data_8; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	15, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	14, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
	0, //0x1c
	0, //0x20
#if 0
#endif
};
#else
static Struct_235fdf74_Inner20 menu_main_graphic_data = //234c1ef4
{
	0, //uint16_t fill_0; //0
	0, //uint16_t wData_2; //2
	{0, 0, 0, 0, 0, 0}, //int fill_4[6]; //4
	0, //void (*Data_0x1c)(); //28 = 0x1c
	0, //void (*Data_0x20)(); //32 = 0x20
#if 0
	0x234c1ef4                        db  0x00 ; '.'                                ; DATA XREF=sub_2344d060+6, dword_234c2058
	0x234c1ef5                        db  0xfa ; '.'
	0x234c1ef6 0400                   movs       r4, r0
	0x234c1ef8 0400                   movs       r4, r0
	0x234c1efa 0000                   movs       r0, r0
	0x234c1efc                        dd         0x234c1834                         ; DATA XREF=sub_2344d060+18
	0x234c1f00                        dd         0x234c123c
	0x234c1f04 0F00                   movs       r7, r1
	0x234c1f06 0000                   movs       r0, r0
	0x234c1f08 0000                   movs       r0, r0
	0x234c1f0a 0000                   movs       r0, r0
	0x234c1f0c 0E01                   lsls       r6, r1, #0x4
	0x234c1f0e 0000                   movs       r0, r0
	0x234c1f10                        dd         0x00000000
	0x234c1f14                        dd         0x00000000
#endif
};
#endif

static Menu_Item menu_main_items[] = //234c1f3c
{
	//[0]
	{
		0x4a, //"Einstellungen"
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
		0x44, //"Senderliste"
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
                                    dword_234c2058:
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



/*  /  / 2344cf8c - todo */
int menu_main_items_on_event(void* r0)
{
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "menu_main_items_on_event: r0=%p\r\n", r0);
		console_send_string(debug_string);
	}
#endif

	if (r0 != 0)
	{
		//0x2344cf96
		if (Data_234c1240->currentItem == 0)
		{
			//0x2344cfa0: Einstellungen
			menu_settings_entry(r0);
			//->loc_2344d05a
		}
		//loc_2344cfa6
		else if (Data_234c1240->currentItem == 1)
		{
			//0x2344cfaa: Installation
#if 0
			sub_234523c8();
#endif
			//->loc_2344d05a
		}
		//loc_2344cfb0
		else if (Data_234c1240->currentItem == 2)
		{
			//0x2344cfb4: Senderliste
#if 0
			sub_23490bd0();
#endif
			//->loc_2344d05a
		}
		//loc_2344cfba
		else if (Data_234c1240->currentItem == 3)
		{
			//0x2344cfbe: Timer
#if 0
			sub_23492b34();
#endif
			//->loc_2344d05a
		}
		//loc_2344cfc4
		else if (Data_234c1240->currentItem == 4)
		{
			//0x2344cfc8: Information
#if 0
			sub_23456220();
#endif
			//->loc_2344d05a
		}
		//loc_2344cfce
		else if (Data_234c1240->currentItem == 5)
		{
			//0x2344cfc8: Aufnahmespeicher
#if 0
			sub_23497aa0();
#endif
			//->loc_2344d05a
		}
		//loc_2344d05a
	}
	else
	{
		//loc_2344cfd8
		console_send_string("menu_main_items_on_event: loc_2344cfd8: TODO\r\n");

		//TODO!!!
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

	Graphic_Job_2_5* r4 = Data_234c1240->graphicData;

	Data_234c1248 = Data_234c1244 = musb_msd_get_device(0);

	r4->pItems[10].bData_0 = 0;

	if (Data_234c1244 != 0)
	{
		r4->wData_2 = 5;

		r4->pItems[4].height = 0xcc;
		r4->pItems[11].bData_0 = 1;
		r4->pItems[9].Data_0x18 = r4->pItems[7].Data_0x18;
	}
	else
	{
		//loc_2344d0aa
		r4->wData_2 = 4;

		r4->pItems[4].height = 0xac;
		r4->pItems[11].bData_0 = 0;
		r4->pItems[9].Data_0x18 = r4->pItems[11].Data_0x18;
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
					(r6->header->Data_0x20 != 0))
			{
				//0x2344d26e: Handle Menu Header
#if 0
    			console_send_string("sub_2344d0d0: 0x2344d26e: TODO!!!\r\n");
#endif
				r4->bData_8[0] = '"'; //r7

				strncpy(&r4->bData_8[1], r6->header->Data_0x20->pString, 10);

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
			} //if ((Data_234c1250 != r6) && (r6->Data_0xc != 0) && (r6->Data_0xc->Data_0x20 != 0))
			else
			{
				//loc_2344d2c4: Handle (current) Menu Item
				Menu_Item* pMenuItem = r6->Data_4;

				if (pMenuItem == 0)
				{
					//->loc_2344d2d0
					return 0;
				}

				Menu_Item_Inner4_Data_0* r0_ = pMenuItem->Data_4[0];
				if (r0_ == 0)
				{
					//->loc_2344d2d0: No Columns
					return 0;
				}
				//loc_2344d2d4: Column 1
				Menu_Item_Inner4_Data_0_Data_0x20* r0 = r0_->Data_0x20;

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
					strncpy(sp_0x38, r0->Data_0x10, 0xff);

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
					if (r0_->Data_0x20 != 0)
					{
						//0x2344d334
						sp_0x34 = r4->bData_8;

						strncpy(sp_0x34, r0_->Data_0x20->Data_0x10, 0xff);

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
					} //if (r0_->Data_0x20 != 0)
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

	menu_stack_operate(Data_234c1240);

	menu_initialize(Data_234c1240);

	sub_2343d51e(Data_234c1240, r5);

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
		sub_23457a3e(r4, 1);
	}
	else
	{
		menu_main_entry(r4);
	}

	return 0;
}

#endif //VDR110
