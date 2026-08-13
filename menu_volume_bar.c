
#ifndef VDR110

#include "data.h"
#include "frontdisplay.h"
#include "texttable.h"
#include "graphic.h"
#include "menu.h"

#pragma thumb

extern Menu_Item* sub_2344d9d0(struct Menu*);
extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern Graphic_Job_2_5_Item_Background Data_234c12d4; //234c12d4
extern Graphic_Job_2_5_Item_Background Data_234c1558; //234c1558
static Menu menu_volume_bar; //234e71ec
static Menu_Item menu_volume_bar_items[]; //234e71c0
static Menu menu_volume_bar_ex; //234e7228

extern void sub_2344e40a(void);
static int menu_volume_bar_on_enter(void); 
static int menu_volume_bar_on_exit(void); 
static int menu_volume_bar_on_event(int*);

Menu* menu_volume_bar_p = &menu_volume_bar; //234e6ee4
int Data_234e6eec = 0; //234e6eec
Menu* menu_volume_bar_flavor[] = //234e6ef0
{
    &menu_volume_bar,
    &menu_volume_bar_ex
};
static Graphic_Job_2_5_Item_Background Data_234e6ef8 = //234e6ef8
{
    10, 4, 0x0f
#if 0
0x234e6ef8                        dw         0x000a                             ; DATA XREF=sub_2348f510+2, 0x234e6f90
0x234e6efa 0000                   movs       r0, r0
0x234e6efc                        dd         0x00000004
0x234e6f00                        db         0x0f
#endif
};

static Graphic_Job_2_5_Item_Background Data_234e6f04 = //234e6f04
{
    9, 4, 0x0f
#if 0
0x234e6f04                        dw         0x0009                             ; DATA XREF=sub_2348f510+8, 0x234e6f50
0x234e6f06 0000                   movs       r0, r0
0x234e6f08                        dd         0x00000004
0x234e6f0c                        db         0x0f
#endif
};

static Graphic_Job_2_5_Item_Background Data_234e6f10 = //234e6f10
{
    5, 4, 0x0f
#if 0
0x234e6f10                        dw         0x0005                             ; DATA XREF=sub_2348f510+10, 0x234e6fd0
0x234e6f12 0000                   movs       r0, r0
0x234e6f14                        dd         0x00000004
0x234e6f18                        db         0x0f
#endif
};

static Graphic_Job_2_5_Item Data_234e6f38[] = //234e6f38
{
    {1, 0, 0/*&Data_234e6f1c*//*fill_4*/, 0/*&Data_234e6f2c*//*Data_8*/, 0x009b, 0x01d6, 0x0186, 0x0020, 0, &Data_234e6f04/*Data_0x18*/, 3}, //[0] = 234e6f38
#if 0
0x234e6f38                        db         0x01                               ; DATA XREF=sub_2348f2c8+22, dword_234e7180, 0x234e71f8
0x234e6f39                        db  0x00 ; '.'
0x234e6f3a 0000                   movs       r0, r0
0x234e6f3c                        dd         0x234e6f1c
0x234e6f40                        dd         0x234e6f2c
0x234e6f44                        dw         0x009b
0x234e6f46                        dw         0x01d6
0x234e6f48                        dw         0x0186
0x234e6f4a                        dw         0x0020
0x234e6f4c 0000                   movs       r0, r0
0x234e6f4e 0000                   movs       r0, r0
0x234e6f50                        dd         0x234e6f04
0x234e6f54                        dw         0x0003
0x234e6f56 0000                   movs       r0, r0
0x234e6f58                        dd         0x00000000                         ; DATA XREF=sub_2348f2c8+42
0x234e6f5c 0000                   movs       r0, r0
0x234e6f5e 0000                   movs       r0, r0
0x234e6f60 0000                   movs       r0, r0
0x234e6f62 0000                   movs       r0, r0
0x234e6f64 0000                   movs       r0, r0
0x234e6f66 0000                   movs       r0, r0
0x234e6f68 0000                   movs       r0, r0                             ; DATA XREF=dword_234e6e78+12
0x234e6f6a 0000                   movs       r0, r0
0x234e6f6c 0000                   movs       r0, r0
0x234e6f6e 0000                   movs       r0, r0                             ; CODE XREF=dword_234e6d14+96
0x234e6f70 0000                   movs       r0, r0
0x234e6f72 0000                   movs       r0, r0
0x234e6f74 0000                   movs       r0, r0                             ; DATA XREF=sub_2348f2c8+50
0x234e6f76 0000                   movs       r0, r0
#endif
    {1, 0, 0/*&Data_234e6f20*//*fill_4*/, 0/*Data_8*/, 0x00d7, 0x01dc, 0x0140, 0x0014, 0, &Data_234e6ef8/*Data_0x18*/, 2}, //[1] = 234E6F78
#if 0
0x234e6f78                        db         0x01                               ; DATA XREF=sub_2348f2c8+30, 0x234e71fc
0x234e6f79                        db         0x00
0x234e6f7a 0000                   movs       r0, r0
0x234e6f7c                        dd         0x234e6f20
0x234e6f80                        dd         0x00000000
0x234e6f84                        dw         0x00d7
0x234e6f86                        dw         0x01dc
0x234e6f88                        dw         0x0140
0x234e6f8a                        dw         0x0014
0x234e6f8c 0000                   movs       r0, r0
0x234e6f8e 0000                   movs       r0, r0
0x234e6f90                        dd         0x234e6ef8
0x234e6f94                        dw         0x0002
0x234e6f96 0000                   movs       r0, r0
0x234e6f98 0000                   movs       r0, r0                             ; DATA XREF=sub_2348f2c8+46
0x234e6f9a 0000                   movs       r0, r0
0x234e6f9c 0000                   movs       r0, r0
0x234e6f9e 0000                   movs       r0, r0
0x234e6fa0 0000                   movs       r0, r0
0x234e6fa2 0000                   movs       r0, r0
0x234e6fa4                        dd         0x00000000                         ; DATA XREF=dword_234e6eb4+12
0x234e6fa8 0000                   movs       r0, r0
0x234e6faa 0000                   movs       r0, r0
0x234e6fac 0000                   movs       r0, r0
0x234e6fae 0000                   movs       r0, r0
0x234e6fb0 0000                   movs       r0, r0
0x234e6fb2 0000                   movs       r0, r0
0x234e6fb4 0000                   movs       r0, r0                             ; DATA XREF=sub_2348f2c8+52
0x234e6fb6 0000                   movs       r0, r0
#endif
    {1, 0, 0/*&Data_234e6f24*//*fill_4*/, 0/*Data_8*/, 0x00dc, 0x01e1, 0x000a, 0x000a, 0, &Data_234e6f10/*Data_0x18*/, 7}, //[2] = 234E6FB8
#if 0
0x234e6fb8                        db         0x01                               ; DATA XREF=sub_2348f2c8+32
0x234e6fb9                        db         0x00
0x234e6fba 0000                   movs       r0, r0
0x234e6fbc                        dd         0x234e6f24
0x234e6fc0                        dd         0x00000000
0x234e6fc4                        dw         0x00dc
0x234e6fc6                        dw         0x01e1
0x234e6fc8                        dw         0x000a                             ; DATA XREF=sub_2348f2c8+40
0x234e6fca                        dw         0x000a
0x234e6fcc 0000                   movs       r0, r0
0x234e6fce 0000                   movs       r0, r0
0x234e6fd0                        dd         0x234e6f10
0x234e6fd4                        dw         0x0007
0x234e6fd6 0000                   movs       r0, r0
0x234e6fd8 0000                   movs       r0, r0                             ; DATA XREF=sub_2348f2c8+48
0x234e6fda 0000                   movs       r0, r0
0x234e6fdc 0000                   movs       r0, r0
0x234e6fde 0000                   movs       r0, r0
0x234e6fe0 0000                   movs       r0, r0
0x234e6fe2 0000                   movs       r0, r0
0x234e6fe4 0000                   movs       r0, r0
0x234e6fe6 0000                   movs       r0, r0
0x234e6fe8 0000                   movs       r0, r0
0x234e6fea 0000                   movs       r0, r0
0x234e6fec 0000                   movs       r0, r0
0x234e6fee 0000                   movs       r0, r0
0x234e6ff0 0000                   movs       r0, r0
0x234e6ff2 0000                   movs       r0, r0
0x234e6ff4 0000                   movs       r0, r0                             ; DATA XREF=sub_2348f2c8+54
0x234e6ff6 0000                   movs       r0, r0
#endif
    {0, 0, 0/*&Data_234e6f28*//*fill_4*/, 0/*Data_8*/, 0, 0, 0, 0, 0, 0/*Data_0x18*/, 0}, //[3] = 234E6FF8
#if 0
0x234e6ff8                        db         0x00
0x234e6ff9                        db         0x00
0x234e6ffa 0000                   movs       r0, r0
0x234e6ffc                        dd         0x234e6f28
0x234e7000 0000                   movs       r0, r0
0x234e7002 0000                   movs       r0, r0
0x234e7004 0000                   movs       r0, r0
0x234e7006 0000                   movs       r0, r0
0x234e7008 0000                   movs       r0, r0
0x234e700a 0000                   movs       r0, r0
0x234e700c 0000                   movs       r0, r0
0x234e700e 0000                   movs       r0, r0
0x234e7010 0000                   movs       r0, r0
0x234e7012 0000                   movs       r0, r0
0x234e7014 0000                   movs       r0, r0
0x234e7016 0000                   movs       r0, r0
0x234e7018 0000                   movs       r0, r0
0x234e701a 0000                   movs       r0, r0
0x234e701c 0000                   movs       r0, r0
0x234e701e 0000                   movs       r0, r0
0x234e7020 0000                   movs       r0, r0
0x234e7022 0000                   movs       r0, r0
0x234e7024 0000                   movs       r0, r0
0x234e7026 0000                   movs       r0, r0
0x234e7028 0000                   movs       r0, r0
0x234e702a 0000                   movs       r0, r0
0x234e702c 0000                   movs       r0, r0
0x234e702e 0000                   movs       r0, r0
0x234e7030 0000                   movs       r0, r0
0x234e7032 0000                   movs       r0, r0
0x234e7034 0000                   movs       r0, r0
0x234e7036 0000                   movs       r0, r0
#endif
    {1, 0, 0/*fill_4*/, 0/*&Data_234c14cc*//*Data_8*/, 0x009b, 0x01d6, 0x0186, 0x0020, 0, &Data_234c1558/*Data_0x18*/, 0}, //[4] = 234E7038
#if 0
0x234e7038                        db         0x01
0x234e7039                        db         0x00
0x234e703a 0000                   movs       r0, r0
0x234e703c                        dd         0x00000000
0x234e7040                        dd         0x234c14cc
0x234e7044                        dw         0x009b
0x234e7046                        dw         0x01d6
0x234e7048                        dw         0x0186
0x234e704a                        dw         0x0020
0x234e704c 0000                   movs       r0, r0
0x234e704e 0000                   movs       r0, r0
0x234e7050                        dd         0x234c1558
0x234e7054 0000                   movs       r0, r0
0x234e7056 0000                   movs       r0, r0
0x234e7058 0000                   movs       r0, r0
0x234e705a 0000                   movs       r0, r0
0x234e705c 0000                   movs       r0, r0
0x234e705e 0000                   movs       r0, r0
0x234e7060 0000                   movs       r0, r0
0x234e7062 0000                   movs       r0, r0
0x234e7064 0000                   movs       r0, r0
0x234e7066 0000                   movs       r0, r0
0x234e7068 0000                   movs       r0, r0
0x234e706a 0000                   movs       r0, r0
0x234e706c 0000                   movs       r0, r0
0x234e706e 0000                   movs       r0, r0
0x234e7070 0000                   movs       r0, r0
0x234e7072 0000                   movs       r0, r0
0x234e7074 0000                   movs       r0, r0
0x234e7076 0000                   movs       r0, r0
#endif
}; //->


static Graphic_Job_2_5_Item Data_234e7038[] = //234e7038
{
    {1, 0, 0, 0/*&Data_234c14cc*//*Data_8*/, 0x9b, 0x1d6, 0x186, 0x20, 0, &Data_234c1558/*Data_0x18*/}, //[0] = 234e7038
#if 0
0x234e7038                        db         0x01                               ; DATA XREF=0x234e71a4, 0x234e7234
0x234e7039                        db         0x00
0x234e703a 0000                   movs       r0, r0
0x234e703c                        dd         0x00000000
0x234e7040                        dd         0x234c14cc
0x234e7044                        dw         0x009b
0x234e7046                        dw         0x01d6
0x234e7048                        dw         0x0186
0x234e704a                        dw         0x0020
0x234e704c 0000                   movs       r0, r0
0x234e704e 0000                   movs       r0, r0
0x234e7050                        dd         0x234c1558
#endif
    {1, 0, 0, 0/*&Data_234c14cc*//*Data_8*/, 0xe1, 0x1dc, 0x131, 0x14, 0, &Data_234c12d4/*Data_0x18*/}, //[1] = 234e7078
#if 0
0x234e7078                        db         0x01                               ; DATA XREF=0x234e7238
0x234e7079                        db         0x00
0x234e707a 0000                   movs       r0, r0
0x234e707c 0000                   movs       r0, r0
0x234e707e 0000                   movs       r0, r0
0x234e7080                        dd         0x234c14cc
0x234e7084                        dw         0x00e1
0x234e7086                        dw         0x01dc
0x234e7088                        dw         0x0131
0x234e708a                        dw         0x0014
0x234e708c 0000                   movs       r0, r0
0x234e708e 0000                   movs       r0, r0
0x234e7090                        dd         0x234c12d4
#endif
    {1, 0, 0, 0/*&Data_234c1538*//*Data_8*/, 0xdc, 0x1dc, 0xa, 0x14, 0, &Data_234c12d4/*Data_0x18*/}, //[2] = 234e70B8
#if 0
0x234e70b8                        db         0x01
0x234e70b9                        db         0x00
0x234e70ba 0000                   movs       r0, r0
0x234e70bc 0000                   movs       r0, r0
0x234e70be 0000                   movs       r0, r0
0x234e70c0                        dd         0x234c1538
0x234e70c4                        dw         0x00dc
0x234e70c6                        dw         0x01dc
0x234e70c8                        dw         0x000a
0x234e70ca                        dw         0x0014
0x234e70cc 0000                   movs       r0, r0
0x234e70ce 0000                   movs       r0, r0
0x234e70d0                        dd         0x234c12d4
#endif
    {1, 0, 0, 0/*&Data_234e6f2c*//*Data_8*/, 0xa0, 0x1d9, 0x32, 0x19, 0, &Data_234c12d4/*Data_0x18*/}, //[3] = 234e70F8
#if 0
0x234e70f8                        db         0x01
0x234e70f9                        db         0x00
0x234e70fa 0000                   movs       r0, r0
0x234e70fc 0000                   movs       r0, r0
0x234e70fe 0000                   movs       r0, r0
0x234e7100                        dd         0x234e6f2c
0x234e7104                        dw         0x00a0
0x234e7106                        dw         0x01d9
0x234e7108                        dw         0x0032
0x234e710a                        dw         0x0019
0x234e710c 0000                   movs       r0, r0
0x234e710e 0000                   movs       r0, r0
0x234e7110                        dd         0x234c12d4
#endif
    {0, 0, 0/*&Data_234e6f28*//*Data_4*/, 0/*Data_8*/}, //[4] = 234e7138
#if 0
0x234e7138                        db         0x00
0x234e7139                        db         0x00
0x234e713a 0000                   movs       r0, r0
0x234e713c                        dd         0x234e6f28                         ; DATA XREF=dword_234e6e00+56
#endif
};

static Graphic_Job_2_5 menu_volume_bar_graphic_data = //234e7178
{
	0, //uint8_t bData_0; //0
	0, //uint8_t bData_1; //1
	0x0016, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234e6f38[0], //Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* pColorData; //12
	16, //uint8_t numColors; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	4, //uint8_t bNumItems; //0x18 = 24
	1, //uint8_t bData_0x19; //0x19 = 25
	0, //void (*Data_0x1c)(); //0x1c
	0, //void (*Data_0x20)(); //0x20
	//???
#if 0
0x234e7178                        db         0x00                               ; DATA XREF=sub_2348f2c8+18, menu_volume_bar_entry+68, dword_234e7200
0x234e7179                        db         0x00
0x234e717a                        dw         0x0016
0x234e717c                        db         0x04
0x234e717d                        db  0x00 ; '.'
0x234e717e 0000                   movs       r0, r0
0x234e7180                        dd         0x234e6f38                         ; DATA XREF=sub_2348f2c8+22
0x234e7184                        dd         menu_main_graphic_color_data
0x234e7188                        db         0x10
0x234e7189                        db  0x00 ; '.'
0x234e718a 0000                   movs       r0, r0
0x234e718c                        dd         0x00000000
0x234e7190                        db  0x04 ; '.'
0x234e7191                        db         0x01                               ; DATA XREF=menu_volume_bar_entry+70
0x234e7192 0000                   movs       r0, r0
0x234e7194                        dd         0x00000000
0x234e7198                        dd         0x00000000
#endif
};

static Graphic_Job_2_5 menu_volume_bar_graphic_data_ex = //234e719c
{
	0, //uint8_t bData_0; //0
	0, //uint8_t bData_1; //1
	0x0016, //uint16_t wData_2; //2
	(0x08|0x04)/*0x0c*/, //uint8_t bData_4; //4
	&Data_234e7038[0], //Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* pColorData; //12
	16, //uint8_t numColors; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	5, //uint8_t bNumItems; //0x18 = 24
	1, //uint8_t bData_0x19; //0x19 = 25
	0, //void (*Data_0x1c)(); //0x1c
	0, //void (*Data_0x20)(); //0x20
	//???

#if 0
0x234e719c                        db         0x00                               ; DATA XREF=0x234e723c
0x234e719d                        db         0x00
0x234e719e                        dw         0x0016
0x234e71a0                        db         0x0c
0x234e71a1                        db  0x00 ; '.'
0x234e71a2 0000                   movs       r0, r0
0x234e71a4                        dd         0x234e7038
0x234e71a8                        dd         menu_main_graphic_color_data
0x234e71ac                        db         0x10
0x234e71ad                        db  0x00 ; '.'
0x234e71ae 0000                   movs       r0, r0
0x234e71b0 0000                   movs       r0, r0
0x234e71b2 0000                   movs       r0, r0
0x234e71b4                        db         0x05                               ; DATA XREF=dword_234e6e78+56
0x234e71b5                        db         0x01
0x234e71b6                        db  0x00 ; '.'
0x234e71b7                        db  0x00 ; '.'
0x234e71b8                        dd         0x00000000
0x234e71bc                        dd         0x00000000
#endif
};

static Menu_Item menu_volume_bar_items[] = //234e71c0
{
    //[0]
    {
	0xffff, //uint16_t wData_0; //0
	0xffff, //uint16_t helpStringId; //2
	{0}, //Graphic_Job_2_5_Item* Data_4[5]; //4
	0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
	menu_volume_bar_on_event, //void* onEvent; //0x1c = 28
	sub_2344e40a, //void* inputThreadFunc; //0x20 = 32
	0, //void* Data_0x24; //0x24 = 36
	0, //void* Data_0x28; //0x28 = 40
	//0x2c = 44
    }
#if 0
0x234e71c0                        dw         0xffff                             ; DATA XREF=0x234e71f0, 0x234e71f4
0x234e71c2                        dw         0xffff
0x234e71c4 0000                   movs       r0, r0
0x234e71c6 0000                   movs       r0, r0
0x234e71c8 0000                   movs       r0, r0
0x234e71ca 0000                   movs       r0, r0
0x234e71cc 0000                   movs       r0, r0
0x234e71ce 0000                   movs       r0, r0
0x234e71d0 0000                   movs       r0, r0
0x234e71d2 0000                   movs       r0, r0
0x234e71d4 0000                   movs       r0, r0
0x234e71d6 0000                   movs       r0, r0
0x234e71d8 0000                   movs       r0, r0
0x234e71da 0000                   movs       r0, r0
0x234e71dc                        dd         menu_volume_bar_on_event+1
0x234e71e0                        dd         sub_2344e40a+1
0x234e71e4 0000                   movs       r0, r0
0x234e71e6 0000                   movs       r0, r0
0x234e71e8 0000                   movs       r0, r0
0x234e71ea 0000                   movs       r0, r0
#endif
};

static Menu menu_volume_bar = //234e71ec
{
    0xffff,
    &menu_volume_bar_items[0],
    &menu_volume_bar_items[0],
    0, //234e6f38, //header
    0, //&Data_234e6f78, //help
    &menu_volume_bar_graphic_data, //graphicData
    0, //maxItem
    0, //currentItem
    graphic_start_job_2_5,
    0, //onNavigate
    menu_volume_bar_on_enter, //onEnter
    menu_volume_bar_on_exit, //onExit
    0xff,
    0, //timeout

#if 0
0x234e71ec                        dw         0xffff                             ; DATA XREF=sub_2348f2c8+10, menu_volume_bar_entry+42, menu_volume_bar_entry+64, menu_volume_bar_entry+76, menu_volume_bar_entry+82, dword_234e6ee4, dword_234e6ef0
0x234e71ee 0000                   movs       r0, r0
0x234e71f0                        dd         0x234e71c0
0x234e71f4                        dd         0x234e71c0
0x234e71f8                        dd         0x234e6f38
0x234e71fc                        dd         0x234e6f78
0x234e7200                        dd         0x234e7178                         ; DATA XREF=sub_2348f2c8+18, menu_volume_bar_entry+68
0x234e7204 0000                   movs       r0, r0
0x234e7206 0000                   movs       r0, r0
0x234e7208                        dd         graphic_start_job_2_5
0x234e720c 0000                   movs       r0, r0
0x234e720e 0000                   movs       r0, r0
0x234e7210                        dd         menu_volume_bar_on_enter+1
0x234e7214                        dd         menu_volume_bar_on_exit+1
0x234e7218                        dw         0x00ff
0x234e721a 0000                   movs       r0, r0
0x234e721c                        dd         0x00000000                         ; DATA XREF=menu_volume_bar_entry+44
0x234e7220 0000                   movs       r0, r0
0x234e7222 0000                   movs       r0, r0
0x234e7224 0000                   movs       r0, r0
0x234e7226 0000                   movs       r0, r0
#endif
};

/*TODO: items...*/
static Menu menu_volume_bar_ex = //234e7228
{
    0xffff,
    &menu_volume_bar_items[0],
    &menu_volume_bar_items[0],
    0, //234e7038, //header
    0, //&Data_234e7078, //help
    &menu_volume_bar_graphic_data_ex, //graphicData
    0, //maxItem
    0, //currentItem
    graphic_start_job_2_5,
    0, //onNavigate
    menu_volume_bar_on_enter, //onEnter
    menu_volume_bar_on_exit, //onExit
    0xff,
    0, //timeout
    sub_2344d9d0,
    0,
#if 0
0x234e7228                        dw         0xffff                             ; DATA XREF=0x234e6ef4
0x234e722a 0000                   movs       r0, r0
0x234e722c                        dd         menu_volume_bar_items
0x234e7230                        dd         menu_volume_bar_items
0x234e7234                        dd         0x234e7038
0x234e7238                        dd         0x234e7078
0x234e723c                        dd         0x234e719c
0x234e7240 0000                   movs       r0, r0
0x234e7242 0000                   movs       r0, r0
0x234e7244                        dd         graphic_start_job_2_5
0x234e7248 0000                   movs       r0, r0
0x234e724a 0000                   movs       r0, r0
0x234e724c                        dd         sub_2348f2c0+1
0x234e7250                        dd         sub_2348f2c4+1
0x234e7254                        dw         0x00ff
0x234e7256 0000                   movs       r0, r0
0x234e7258                        dd         0x00000000
0x234e725c                        dd         sub_2344d9d0+1
0x234e7260                        dd         0x00000000
#endif
};


/* /  / 2348f2c0 - complete */
static int menu_volume_bar_on_enter(void)
{
    return 0;
}


/* /  / 2348f2c4 - complete */
static int menu_volume_bar_on_exit(void)
{
    return 0;
}


/*  /  / 2348f2c8 - todo */
int sub_2348f2c8(uint32_t a)
{
#if 0
	console_send_string("sub_2348f2c8 (todo.c): TODO\r\n");
#endif

    a = (a * 100) / 32;

    Graphic_Job_2_5_Item* r4 = &menu_volume_bar_p->graphicData->pItems[0];
    Graphic_Job_2_5_Item* r6 = &menu_volume_bar_p->graphicData->pItems[1];
    Graphic_Job_2_5_Item* r5 = &menu_volume_bar_p->graphicData->pItems[2];

    r5->width = 10 + (a * 300) / 100;
    r4->bData_0x3c = 1;
    r6->bData_0x3c = 1;
    r5->bData_0x3c = 1;

    return 0;
}


/* /  / 2348f304 - complete */
static int menu_volume_bar_on_event(int* a)
{
    Graphic_Queue_Item sp;

    int r1 = *a;

#if 0
    {
        extern char debug_string[];
        sprintf(debug_string, "menu_volume_bar_on_event (menu_volume_bar.c): a=0x%x\r\n", a);
        console_send_string(debug_string);
    }
#endif

    if (a != 0)
    {
        int r0;

        if (r1 & (1 << 2))
        {
            r0 = channel_change_volume(1, 1);
        }
        else if (r1 & (1 << 3))
        {
            r0 = channel_change_volume(1, -1);
        }
        else
        {
            return 0;
        }

        sub_2348f2c8(r0);
    }
    else
    {
        sub_2344f662(&sp);
    }

    return 0;
}


/* /  / 2348f334 - todo */
void* sub_2348f334(FrontDisplay_Job* a)
{

#if 1 //TODO

    strcpy(a->bData_8, "TODO");
    a->bNumTextChars = 12;
    a->bDisplayOffset = 0; //r7
    a->bNumDisplayChars = 12;
    a->bData_0x10b = 0;
    a->bData_0x10c = 0;
    a->holdTime = 0;
    a->bData_0x10f = 0;
    a->Data_0 = frontdisplay_draw_text;
    a->Data_4 = 0;
    //->loc_2348f388
    return sub_2348f334;
#endif
}


/* /  / 2348f414 - todo */
int menu_volume_bar_entry(UI_Thread_Params* r5)
{
    frontdisplay_start_text(0);

    if (Data_234e6eec != 0)
    {
        sub_2348f254(0x2000);

        sub_2349984e(0, 1);
    }

    menu_volume_bar_p->timeout = 400;

    int r0 = channel_change_volume(0, 0);

    sub_2348f2c8(r0);

    sub_2343d458(r5);

    menu_volume_bar_p->graphicData->bData_0x19 = 1;

    MENU_STACK_PUSH(menu_volume_bar_p);

    menu_initialize(menu_volume_bar_p);

    sub_2343d51e(menu_volume_bar_p, r5);

    frontdisplay_start_text(sub_2348f334);

    return 0;
}


/* /  / 2348f502 - todo */
void menu_volume_bar_set_flavor(uint8_t a)
{
#if 0
	console_send_string("menu_volume_bar_set_flavor (todo.c): TODO\r\n");
#endif

    menu_volume_bar_p = menu_volume_bar_flavor[a];
}



#endif //!VDR110
