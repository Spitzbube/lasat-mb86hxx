
#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "menu.h"
#include "menu_info_bar.h"
#include "channel_list_update.h"
#include "scan.h"

#ifndef VDR110

#pragma thumb


extern void sub_2348dbf8(void);
extern int sub_2348dd36(Menu*, int);
extern void sub_2344f3c6(UI_Thread_Params*);

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern void* Data_234c1258; //234c1258

static void sub_2348f54e(void);
static int sub_2348f55a(void);
static int sub_2348ff32(int);
static int sub_2348ff9e(int);
static int sub_2348fc2c(UI_Thread_Params*);

static Menu Data_234e72f0; //234e72f0
static Menu Data_234e732c; //234e732c
static Graphic_Job_2_5_Item Data_234e786c[]; //234e786c
static Graphic_Job_2_5 Data_234e8e6c; //234e8e6c
static Menu_Item Data_234e8eb4[]; //234e8eb4
static Menu_Item Data_234e8fbc[]; //234e8fbc
static uint8_t Data_2396e104[]; //2396e104
static uint8_t Data_2396e224[]; //2396e224
static uint8_t Data_239701b0[]; //239701b0
static uint8_t Data_23970318[]; //23970318

//0x234e7264
static Menu* Data_234e7268 = &Data_234e72f0; //234e7268 +4
static Menu* Data_234e726c = &Data_234e732c; //234e726c +8

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234e729c = //234e729c
{
	9, 4, 0x0f, //...
#if 0
0x234e729c                        dw         0x0009                             ; DATA XREF=sub_234904ce+20, 0x234e8284
0x234e729e 0000                   movs       r0, r0
0x234e72a0                        dd         0x00000004
0x234e72a4                        db         0x0f
#endif	
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234e72a8 = //234e72a8
{
	9, 4, 0x0c, //...
#if 0
0x234e72a8                        dw         0x0009                             ; DATA XREF=sub_234904ce+22, 0x234e8244
0x234e72aa 0000                   movs       r0, r0
0x234e72ac                        dd         0x00000004
0x234e72b0                        db         0x0c
#endif	
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234e72c0 = //234e72c0
{
	9, 4, 0x0f, //...
#if 0
0x234e72c0                        dw         0x0009                             ; DATA XREF=sub_234904ce+26, 0x234e78c4
0x234e72c2 0000                   movs       r0, r0
0x234e72c4                        dd         0x00000004
0x234e72c8                        db         0x0f
#endif	
};

static Menu Data_234e72f0 = //234e72f0
{
		0x007a, //"Neue TV-Kan▒le:" / "New video:"
		&Data_234e8eb4[0], //Menu_Item* Data_4; //4
		&Data_234e8eb4[0], //Menu_Item* Data_8; //8
		&Data_234e786c[1], //234e78ac, //Struct_235fdf74_Inner12* header; //12 = 0xc
		0, /*&Data_234c3414*/ //Struct_235fdf74_Inner16* help; //16 = 0x10
		&Data_234e8e6c, //int graphicData; //20 = 0x14
		0, //5, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		graphic_start_job_2_5, //void (*graphicHandler)(); //0x1c
		0, //menu_items_navigate, //void (*onNavigate)(); //0x20
		sub_2348ff9e, //int (*onEnter)(int); //36 = 0x24
		sub_2348fc2c, //int (*onExit)(UI_Thread_Params*); //0x28
#if 0
0x234e72f0                        dw         0x007a                             ; DATA XREF=sub_2348f56e+12, sub_2348f56e+116, sub_2348f688+14, sub_2348f8cc+14, aDd_2348fa10+332, sub_2348fc86+20, sub_2348fc86+60, sub_2348fc86+78, sub_2348fda0+10, sub_2348fda0+46, sub_2348fda0+52
0x234e72f2 0000                   movs       r0, r0
0x234e72f4                        dd         0x234e8eb4
0x234e72f8                        dd         0x234e8eb4
0x234e72fc                        dd         0x234e78ac
0x234e7300                        dd         0x234e792c
0x234e7304                        dd         0x234e8e6c                         ; DATA XREF=sub_2348f56e+14, sub_2348f56e+118, sub_2348f688+18, sub_2348f8cc+16, aDd_2348fa10+334, sub_2348fc86+66, sub_2349052a+10
0x234e7308                        db         0x05
0x234e7309                        db  0x00 ; '.'
0x234e730a                        db  0x00 ; '.'
0x234e730b                        db  0x00 ; '.'
0x234e730c                        dd         graphic_start_job_2_5
0x234e7310                        dd         sub_2348de88+1
0x234e7314                        dd         sub_2348ff9e+1
0x234e7318                        dd         sub_2348fc2c+1                     ; DATA XREF=sub_2348fc86+22, sub_2348fda0+14
0x234e731c 0000                   movs       r0, r0
0x234e731e 0000                   movs       r0, r0
0x234e7320 0000                   movs       r0, r0
0x234e7322 0000                   movs       r0, r0
0x234e7324 0000                   movs       r0, r0
0x234e7326 0000                   movs       r0, r0
0x234e7328                        dd         sub_2349052a+1                     ; DATA XREF=dword_234e721c+40
#endif
    //234E732C
};

static Menu Data_234e732c = //234e732c
{
		0x007c, //"Neue Radio-Kan▒le:" / "New radio:"
		&Data_234e8fbc[0], //Menu_Item* Data_4; //4
		&Data_234e8fbc[0], //Menu_Item* Data_8; //8
		&Data_234e786c[21], //234e7dac, //Struct_235fdf74_Inner12* header; //12 = 0xc
		0, /*&Data_234c3414*/ //Struct_235fdf74_Inner16* help; //16 = 0x10
		&Data_234e8e6c, //int graphicData; //20 = 0x14
		0, //5, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		graphic_start_job_2_5, //void (*graphicHandler)(); //0x1c
		0, //menu_items_navigate, //void (*onNavigate)(); //0x20
		sub_2348ff32, //int (*onEnter)(int); //36 = 0x24
		sub_2348fc2c, //int (*onExit)(UI_Thread_Params*); //0x28
#if 0
0x234e732c                        dw         0x007c                             ; DATA XREF=sub_2348fc86+24, sub_2348fda0+16, sub_2348ff32+36, dword_234e726c
0x234e732e                        db         0x00
0x234e732f                        db  0x00 ; '.'
0x234e7330                        dd         0x234e8fbc
0x234e7334                        dd         0x234e8fbc
0x234e7338                        dd         0x234e7dac
0x234e733c                        dd         0x234e792c
0x234e7340                        dd         0x234e8e6c
0x234e7344                        db         0x05
0x234e7345                        db  0x00 ; '.'
0x234e7346 0000                   movs       r0, r0
0x234e7348                        dd         graphic_start_job_2_5
0x234e734c                        dd         sub_2348de88+1
0x234e7350                        dd         sub_2348ff32+1
0x234e7354                        dd         sub_2348fc2c+1                     ; DATA XREF=sub_2348fc86+26, sub_2348fda0+20
0x234e7358 0000                   movs       r0, r0
0x234e735a 0000                   movs       r0, r0
0x234e735c 0000                   movs       r0, r0
0x234e735e 0000                   movs       r0, r0
0x234e7360 0000                   movs       r0, r0
0x234e7362 0000                   movs       r0, r0
0x234e7364                        dd         sub_2349052a+1
#endif
    //234E7368
};

static Menu Data_234e7368 = //234e7368
{
	0x007a, //"Neue TV-Kan▒le:" / "New video:"
	0, //&Data_234e8fbc[0], //Menu_Item* Data_4; //4
	0, //&Data_234e8fbc[0], //Menu_Item* Data_8; //8
	0, //&Data_234c3394[32], //234e7dac, //Struct_235fdf74_Inner12* header; //12 = 0xc
	0, /*&Data_234c3414*/ //Struct_235fdf74_Inner16* help; //16 = 0x10
	0, //&Data_234e8e6c, //int graphicData; //20 = 0x14
	0, //5, //uint8_t maxItem; //0x18 = 24
	0, //int8_t currentItem; //0x19
	graphic_start_job_2_5, //void (*graphicHandler)(); //0x1c
	0, //menu_items_navigate, //void (*onNavigate)(); //0x20
	sub_2348ff9e, //int (*onEnter)(int); //36 = 0x24
	sub_2348fc2c, //int (*onExit)(UI_Thread_Params*); //0x28
#if 0
0x234e7368                        dw         0x007a                             ; DATA XREF=sub_2348fc86+28, sub_2348fda0+22, 0x234e7278
0x234e736a 0000                   movs       r0, r0
0x234e736c                        dd         0x234e90c4
0x234e7370                        dd         0x234e90c4
0x234e7374                        dd         0x234e83ac
0x234e7378                        dd         0x234e842c
0x234e737c                        dd         0x234e8e90
0x234e7380                        db         0x05
0x234e7381                        db  0x00 ; '.'
0x234e7382 0000                   movs       r0, r0
0x234e7384                        dd         graphic_start_job_2_5
0x234e7388                        dd         sub_2348de88+1
0x234e738c                        dd         sub_2348ff9e+1
0x234e7390                        dd         sub_2348fc2c+1                     ; DATA XREF=sub_2348fc86+30, sub_2348fda0+24
0x234e7394 0000                   movs       r0, r0
0x234e7396 0000                   movs       r0, r0
0x234e7398 0000                   movs       r0, r0
0x234e739a 0000                   movs       r0, r0
0x234e739c 0000                   movs       r0, r0
0x234e739e 0000                   movs       r0, r0
0x234e73a0                        dd         sub_2349052a+1
#endif
	//234E73A4
};

static Menu Data_234e73a4 = //234e73a4
{
		0x007c, //"Neue Radio-Kan▒le:" / "New radio:"
		0, //&Data_234e8fbc[0], //Menu_Item* Data_4; //4
		0, //&Data_234e8fbc[0], //Menu_Item* Data_8; //8
		0, //&Data_234c3394[32], //234e7dac, //Struct_235fdf74_Inner12* header; //12 = 0xc
		0, /*&Data_234c3414*/ //Struct_235fdf74_Inner16* help; //16 = 0x10
		0, //&Data_234e8e6c, //int graphicData; //20 = 0x14
		0, //5, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		graphic_start_job_2_5, //void (*graphicHandler)(); //0x1c
		0, //menu_items_navigate, //void (*onNavigate)(); //0x20
		sub_2348ff32, //int (*onEnter)(int); //36 = 0x24
		sub_2348fc2c, //int (*onExit)(UI_Thread_Params*); //0x28
#if 0
0x234e73a4                        dw         0x007c                             ; DATA XREF=sub_2348fc86+32, sub_2348fda0+26
0x234e73a6 0000                   movs       r0, r0
0x234e73a8                        dd         0x234e91cc
0x234e73ac                        dd         0x234e91cc
0x234e73b0                        dd         0x234e88ac
0x234e73b4                        dd         0x234e842c
0x234e73b8                        dd         0x234e8e90
0x234e73bc                        db         0x05
0x234e73bd                        db  0x00 ; '.'
0x234e73be 0000                   movs       r0, r0
0x234e73c0                        dd         graphic_start_job_2_5
0x234e73c4                        dd         sub_2348de88+1
0x234e73c8                        dd         sub_2348ff32+1
0x234e73cc                        dd         sub_2348fc2c+1                     ; DATA XREF=sub_2348fc86+34, sub_2348fda0+28
0x234e73d0 0000                   movs       r0, r0
0x234e73d2 0000                   movs       r0, r0
0x234e73d4 0000                   movs       r0, r0
0x234e73d6 0000                   movs       r0, r0
0x234e73d8 0000                   movs       r0, r0
0x234e73da 0000                   movs       r0, r0
0x234e73dc                        dd         sub_2349052a+1
#endif
    //234E73E0
};

static Graphic_Job_2_5_Item_Text Data_234e73ec = //234e73ec
{
    0, 0x0047, 0x002c, 0x015c, 0x004f, 0x01, 0x06, 0x02, 0x00, &Data_2396e104[0], 0, 0, 0
#if 0
0x234e73ec                        db         0x00                               ; DATA XREF=0x234e78cc
0x234e73ed                        db         0x00
0x234e73ee                        dw         0x0047
0x234e73f0                        dw         0x002c
0x234e73f2                        dw         0x015c
0x234e73f4                        dw         0x004f
0x234e73f6                        db         0x01
0x234e73f7                        db         0x06
0x234e73f8                        db         0x02
0x234e73f9                        db         0x00
0x234e73fa 0000                   movs       r0, r0
0x234e73fc                        dd         0x2396e104
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e75e4 = //Data_234e75e4
{
    0, 0x017d, 0x002c, 0x0292, 0x004f, 0x01, 0x06, 0x02, 0x00, &Data_239701b0[0], 0, 0, 0
#if 0
0x234e75e4                        db         0x00                               ; DATA XREF=0x234e7dcc
0x234e75e5                        db  0x00 ; '.'
0x234e75e6                        dw         0x017d
0x234e75e8                        dw         0x002c
0x234e75ea                        dw         0x0292
0x234e75ec                        dw         0x004f
0x234e75ee                        db         0x01
0x234e75ef                        db         0x06
0x234e75f0                        db         0x02
0x234e75f1                        db         0x00
0x234e75f2 0000                   movs       r0, r0
0x234e75f4                        dd         0x239701b0
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e7824 = //234e7824
{
    0, 0x0047, 0x0195, 0x015d, 0x01b1, 0x01, 0x04, 0x09, 0x01, &Data_2396e224[0], 0, 0, 0
#if 0
0x234e7824                        db         0x00                               ; DATA XREF=0x234e824c
0x234e7825                        db         0x00
0x234e7826                        dw         0x0047
0x234e7828                        dw         0x0195
0x234e782a                        dw         0x015d
0x234e782c                        dw         0x01b1
0x234e782e                        db         0x01
0x234e782f                        db         0x04
0x234e7830                        db         0x09
0x234e7831                        db         0x01
0x234e7832 0000                   movs       r0, r0
0x234e7834                        dd         0x2396e224
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e783c = //234e783c
{
    0, 0x017d, 0x0135, 0x0292, 0x0151, 0x01, 0x04, 0x09, 0x01, &Data_23970318[0], 0, 0, 0
#if 0
0x234e783c                        db         0x00                               ; DATA XREF=0x234e828c
0x234e783d                        db         0x00
0x234e783e                        dw         0x017d
0x234e7840                        dw         0x0135
0x234e7842                        dw         0x0292
0x234e7844                        dw         0x0151
0x234e7846                        db         0x01
0x234e7847                        db         0x04
0x234e7848                        db         0x09
0x234e7849                        db         0x01
0x234e784a 0000                   movs       r0, r0
0x234e784c                        dd         0x23970318
#endif
};

static Graphic_Job_2_5_Item Data_234e786c[] = //234e786c
{
	{0}, //[0] = 234e786c 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0029, 0x011f, 0x0026, 0, &Data_234e72c0/*Data_0x18*/, 2, 0, &Data_234e73ec/*Data_0x20*/}, //[1] = 234E78AC: Header TV Channels
#if 0
0x234e78ac                        db         0x01                               ; DATA XREF=0x234e72fc
0x234e78ad                        db         0x00
0x234e78ae                        db         0x00
0x234e78af                        db         0x00
0x234e78b0                        dd         0x00000000
0x234e78b4                        dd         0x00000000
0x234e78b8                        dw         0x003d
0x234e78ba                        dw         0x0029
0x234e78bc                        dw         0x011f
0x234e78be                        dw         0x0026
0x234e78c0 0000                   movs       r0, r0
0x234e78c2 0000                   movs       r0, r0
0x234e78c4                        dd         0x234e72c0
0x234e78c8                        dw         0x0002
0x234e78ca                        db  0x00 ; '.'
0x234e78cb                        db  0x00 ; '.'
0x234e78cc                        dd         0x234e73ec
#endif
	{0}, //[2] = 234E78EC 
	{0}, //[3] = 234E792C 
	{0}, //[4] = 234E796C 
	{0}, //[5] = 234E79AC 
	{0}, //[6] = 234E79EC 
	{0}, //[7] = 234E7A2C 
	{0}, //[8] = 234E7A6C 
	{0}, //[9] = 234E7AAC 
	{0}, //[10] = 234E7AEC 
	{0}, //[11] = 234E7B2C 
	{0}, //[12] = 234E7B6C 
	{0}, //[13] = 234E7BAC 
	{0}, //[14] = 234E7BEC 
	{0}, //[15] = 234E7C2C 
	{0}, //[16] = 234E7C6C 
	{0}, //[17] = 234E7CAC 
	{0}, //[18] = 234E7CEC 
	{0}, //[19] = 234E7D2C 
	{0}, //[20] = 234E7D6C 
	{1, 0, 0, 0/*Data_8*/, 0x0173, 0x0029, 0x011f, 0x0026, 0, &Data_234e72c0/*Data_0x18*/, 2, 0, &Data_234e75e4/*Data_0x20*/}, //[21] = 234E7DAC: Header Radio Channels
#if 0
0x234e7dac                        db         0x01                               ; DATA XREF=0x234e7338
0x234e7dad                        db  0x00 ; '.'
0x234e7dae 0000                   movs       r0, r0
0x234e7db0                        dd         0x00000000
0x234e7db4                        dd         0x00000000
0x234e7db8                        dw         0x0173
0x234e7dba                        dw         0x0029
0x234e7dbc                        dw         0x011f
0x234e7dbe                        dw         0x0026
0x234e7dc0 0000                   movs       r0, r0
0x234e7dc2 0000                   movs       r0, r0
0x234e7dc4                        dd         0x234e72c0
0x234e7dc8                        dw         0x0002
0x234e7dca 0000                   movs       r0, r0
0x234e7dcc                        dd         0x234e75e4
#endif
	{0}, //[22] = 234E7DEC 
	{0}, //[23] = 234E7E2C 
	{0}, //[24] = 234E7E6C 
	{0}, //[25] = 234E7EAC 
	{0}, //[26] = 234E7EEC 
	{0}, //[27] = 234E7F2C 
	{0}, //[28] = 234E7F6C 
	{0}, //[29] = 234E7FAC 
	{0}, //[30] = 234E7FEC 
	{0}, //[31] = 234E802C 
	{0}, //[32] = 234E806C 
	{0}, //[33] = 234E80AC 
	{0}, //[34] = 234E80EC 
	{0}, //[35] = 234E812C 
	{0}, //[36] = 234E816C 
	{0}, //[37] = 234E81AC 
	{0}, //[38] = 234E81EC 
	{1, 0, 0, 0/*Data_8*/, 0x003d, 0x0191, 0x0120, 0x0020, 0, &Data_234e72a8/*Data_0x18*/, 9, 0, &Data_234e7824/*Data_0x20*/}, //[39] = 234E822C
#if 0
0x234e822c                        db         0x01
0x234e822d                        db  0x00 ; '.'
0x234e822e 0000                   movs       r0, r0
0x234e8230                        dd         0x00000000
0x234e8234                        dd         0x00000000
0x234e8238                        dw         0x003d
0x234e823a                        dw         0x0191
0x234e823c                        dw         0x0120
0x234e823e                        dw         0x0020
0x234e8240 0000                   movs       r0, r0
0x234e8242 0000                   movs       r0, r0
0x234e8244                        dd         0x234e72a8
0x234e8248                        dw         0x0009
0x234e824a 0000                   movs       r0, r0
0x234e824c                        dd         0x234e7824
#endif 
	{1, 0, 0, 0/*Data_8*/, 0x0173, 0x0131, 0x011f, 0x0020, 0, &Data_234e729c/*Data_0x18*/, 9, 0, &Data_234e783c/*Data_0x20*/}, //[40] = 234E826C
#if 0
0x234e826c                        db         0x01
0x234e826d                        db  0x00 ; '.'
0x234e826e 0000                   movs       r0, r0
0x234e8270                        dd         0x00000000
0x234e8274                        dd         0x00000000
0x234e8278                        dw         0x0173
0x234e827a                        dw         0x0131
0x234e827c                        dw         0x011f
0x234e827e                        dw         0x0020
0x234e8280 0000                   movs       r0, r0
0x234e8282 0000                   movs       r0, r0
0x234e8284                        dd         0x234e729c
0x234e8288                        dw         0x0009
0x234e828a 0000                   movs       r0, r0
0x234e828c                        dd         0x234e783c
#endif
	{0}, //[41] = 234E82AC 
	{0}, //[42] = 234E82EC 
	{0}, //[43] = 234E832C 
}; //->234E836C


static Graphic_Job_2_5 Data_234e8e6c = //234e8e6c
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x000f, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234e786c[0], //Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	0x10, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	44, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
	sub_2348f54e, //0x1c
	sub_2348f55a, //0x20
#if 0
0x234e8e6c                        db  0x00 ; '.'                                ; DATA XREF=sub_2348f56e+14, sub_2348f56e+118, sub_2348f688+18, sub_2348f8cc+16, aDd_2348fa10+334, sub_2348fc86+66, sub_2349052a+10, dword_234e7304, 0x234e7340
0x234e8e6d                        db  0xfa ; '.'
0x234e8e6e                        dw         0x000f
0x234e8e70                        db         0x04
0x234e8e71                        db  0x00 ; '.'
0x234e8e72 0000                   movs       r0, r0
0x234e8e74                        dd         0x234e786c                         ; DATA XREF=sub_2348f56e+16, sub_2348f688+20, sub_2348f8cc+18, sub_2348fc86+68, sub_2349052a+16
0x234e8e78                        dd         menu_main_graphic_color_data
0x234e8e7c                        db         0x10
0x234e8e7d                        db  0x00 ; '.'
0x234e8e7e 0000                   movs       r0, r0
0x234e8e80                        dd         0x00000000
0x234e8e84                        db         0x2c
0x234e8e85                        db         0x01
0x234e8e86 0000                   movs       r0, r0
0x234e8e88                        dd         sub_2348f54e+1
0x234e8e8c                        dd         sub_2348f55a+1
#endif
};

static Menu_Item Data_234e8eb4[] = //234e8eb4
{
	//[0]
	{
		0x0000, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234e786c[8], //234e7a6c,
			0, //&Data_234c3394[11], //234e7bec,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C4C40
#if 0
0x234e8eb4                        dw         0x0000                             ; DATA XREF=0x234e72f4, 0x234e72f8
0x234e8eb6                        dw         0x00fc
0x234e8eb8                        dd         0x234e7a6c
0x234e8ebc                        dd         0x234e7bec
0x234e8ec0 0000                   movs       r0, r0
0x234e8ec2 0000                   movs       r0, r0
0x234e8ec4 0000                   movs       r0, r0
0x234e8ec6 0000                   movs       r0, r0
0x234e8ec8 0000                   movs       r0, r0
0x234e8eca 0000                   movs       r0, r0
0x234e8ecc 0000                   movs       r0, r0
0x234e8ece 0000                   movs       r0, r0
0x234e8ed0                        dd         sub_234902a6+1
0x234e8ed4                        dd         sub_2344f3c6+1
#endif
    },
};


static Menu_Item Data_234e8fbc[] = //234e8fbc
{
	//[0]
	{
		0x0000, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234e786c[22], //234e7dec,
			0, //&Data_234e786c[11], //234e7f6c,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234C4C40
#if 0
0x234e8fbc                        dw         0x0000                             ; DATA XREF=0x234e7330, 0x234e7334
0x234e8fbe                        dw         0x00fc
0x234e8fc0                        dd         0x234e7dec
0x234e8fc4                        dd         0x234e7f6c
0x234e8fc8 0000                   movs       r0, r0
0x234e8fca 0000                   movs       r0, r0
0x234e8fcc 0000                   movs       r0, r0
0x234e8fce 0000                   movs       r0, r0
0x234e8fd0 0000                   movs       r0, r0
0x234e8fd2 0000                   movs       r0, r0
0x234e8fd4 0000                   movs       r0, r0
0x234e8fd6 0000                   movs       r0, r0
0x234e8fd8                        dd         sub_234902a6+1
0x234e8fdc                        dd         sub_2344f3c6+1
#endif
    },
};


static uint8_t Data_2396e104[40]; //2396e104, size???
static uint8_t Data_2396e224[40]; //2396e224 +0x28 = 2396E24C

struct
{
    struct
    {
        uint8_t fill_0[4000];
        //4000
    } Data_2396e24c; //2396e24c +4000 = 2396F1EC
    struct
    {
        uint8_t fill_0[4000];
        //4000
    } Data_2396f1ec; //2396F1EC +4000 = 2397018C
    int Data_2397018c; //0x2397018c
    void* sema; //23970190 +4
    void* Data_23970194; //23970194 +8
    Struct_2348dc50* Data_23970198; //23970198
    uint16_t wData_2397019c; //2397019c
	void* Data_239701a0; //239701a0 +0x14
	Struct_2348dc50* Data_239701a4; //239701a4 +0x18
	uint16_t wData_239701a8; //239701a8 +0x1c
    uint32_t Data_239701ac; //239701ac

} Data_23970198; //???

static uint8_t Data_239701b0[40]; //239701b0, size???
static uint8_t Data_23970318[40]; //23970318. size???




/* /  / 2348f54e - todo */
void sub_2348f54e(void)
{
#if 0
	console_send_string("sub_2348f54e (todo.c): TODO\r\n");
#endif

	OSSemPost(Data_23970198.sema);
}


/* /  / 2348f55a - complete */
int sub_2348f55a(void)
{
#if 0
	console_send_string("sub_2348f55a (todo.c): TODO\r\n");
#endif

	uint8_t err;

	OSSemPend(Data_23970198.sema, 0, &err);

	return err;
}


/* /  / 2348f56e - todo */
void sub_2348f56e()
{
#if 1
	console_send_string("sub_2348f56e (todo.c): TODO\r\n");
#endif

}


/*  /  / 2348f5f4 - todo */
void sub_2348f5f4()
{
#if 1
	console_send_string("sub_2348f5f4 (todo.c): TODO\r\n");
#endif

}


/* /  / 2348f688 - todo */
void sub_2348f688(Transponder* a)
{
#if 1
	console_send_string("sub_2348f688 (todo.c): TODO\r\n");
#endif

}


/* /  / 2348f8cc - todo */
void sub_2348f8cc(void* p, int sp_0x9c, int progress_type)
{
#if 0
	console_send_string("sub_2348f8cc (todo.c): TODO\r\n");
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2348f8cc (progress): progress_type=%d\r\n", progress_type);
		console_send_string(debug_string);
	}
#endif

	Struct_2348dc50 sp_0x34; //sp_0x34 +0x64 = 0x98
	Graphic_Queue_Item sp_0x24;
	uint8_t sp_0xc[30]; //size???
	Graphic_Job_2_5_Item* r5 = &Data_234e7268->graphicData->pItems[39];
	Graphic_Job_2_5_Item* r6 = &Data_234e7268->graphicData->pItems[40];
	uint8_t* sp8 = r5->Data_0x20->pString;
	uint8_t* sp4 = r6->Data_0x20->pString;

	sub_2348f55a();

	//r1 = 1;
	if (progress_type == SCAN_PROGRESS_CALLBACK_TRANSPONDER)
	{
		//0x2348f8fe
		Scan_Progress_Transponder* r4 = p;
		
		r5->Data_0x20->bData_0x17 = 1; //r1

		sub_2348f688(r4->pTransponder);

		text_table_get_string(0xbe/*"Transponder"*/, sp8, 40);

		if (r4->total != 0)
		{
			//0x2348f918
			sprintf(&sp_0xc[0], ": %d/%d", r4->current + 1, r4->total);
		}
		else
		{
			//loc_2348f922
			sprintf(&sp_0xc[0], ": %d/%d", 0, 0);
		}

		strcat(sp8, &sp_0xc[0]);
		//->loc_2348fb5a
	}
	//loc_2348f938 -> loc_2348fa18
	//r5 = 0;
	else if (progress_type == 1)
	{
		//0x2348fa1e
		Struct_2348dc50* r4;
		
		sub_2348f5f4(p, sp_0x9c, &Data_23970198.wData_2397019c);

		memcpy(&sp_0x34, sub_2348dcd2(), sizeof(Struct_2348dc50));

		r4 = Data_23970198.Data_23970198;
		if (Data_23970198.wData_2397019c != 0)
		{
			//0x2348fa46
			r4->wData_0x20 = Data_23970198.wData_2397019c;
			r4->wData_0x1e = r4->wData_0x20 - 1;
			r4->wData_0x22 = r4->wData_0x1e % r4->wData_0x26;
			//->loc_2348fa5e
		}
		else
		{
			//loc_2348fa5a
			r4->wData_0x1e = 0; //r5
			r4->wData_0x22 = 0; //r5
		}
		//loc_2348fa5e
		r4->wData_0x20 = Data_23970198.wData_2397019c;

		sub_2348dcd8(Data_23970198.Data_23970198->bData_0x5f);

		if (r4->Data_0x14 != NULL)
		{
			(r4->Data_0x14)(r4);
		}
		//loc_2348fa76
		if (Data_23970198.Data_23970198->bData_0x5f != sp_0x34.bData_0x5f)
		{
			//0x2348fa84
			r4->pMenu->Data_4 = &r4->pMenu->Data_8[r4->wData_0x22];
			//r0 = r4->pMenu->Data_4

			if (r4->Data_0x18 != NULL)
			{
				//0x2348fa9c
				(r4->Data_0x18)(r4->pMenu->Data_4, 2);
			}
		}
		//loc_2348faa0
		r4 = Data_23970198.Data_239701a4;
		if (Data_23970198.wData_239701a8 != 0)
		{
			//0x2348faa8
		}
		//loc_2348fabc

		//TODO!!!
	}
	//loc_2348fb0e
	else if (progress_type == SCAN_PROGRESS_CALLBACK_STATE)
	{
		//0x2348fb12
		Scan_Progress_State* r4 = p;

		int r0 = 0x7b; //'Stopp'

		r6->Data_0x20->bData_0x17 = 1; //r1

		int status = r4->state;

		Data_23970198.Data_2397018c = status;

		if (status == 1)
		{
			//0x2348fb24
			r0 = 0x7d; //'Suche l▒uft'
		}
		//loc_2348fb28
		else if (status == 2)
		{
			//0x2348fb2c
			r0 = 0x7e; //'Suche beendet'
		}
		//loc_2348fb2e
		text_table_get_string(r0, &sp_0xc[0], 20);

		sp_0xc[20] = 0;

		text_table_get_string(0x49/*'Status: '*/, sp4, 29);

		sp4[29] = 0;

		strncat(sp4, &sp_0xc[0], 29 - strlen(sp4));
	}
	//loc_2348fb5a
	graphic_start_job_2_5(&sp_0x24, Data_234e7268->graphicData);

	sub_2348f54e();
}


/* /  / 2348fc2c - todo */
int sub_2348fc2c(UI_Thread_Params* a)
{
#if 1
	console_send_string("sub_2348fc2c (todo.c): TODO\r\n");
#endif

	return 0;
}


/* /  / 2348fc86 - todo */
int sub_2348fc86(UI_Thread_Params* r6)
{
#if 1
	console_send_string("sub_2348fc86 (todo.c): TODO\r\n");
#endif

    User_Settings sp_0x34;
    Struct_2343df02 scan_params;
    Transponder sp4;

    channel_handle_user_settings(1, &sp_0x34);

	Data_234e72f0.onExit = sub_2348fc2c;
	Data_234e732c.onExit = sub_2348fc2c;
	Data_234e7368.onExit = sub_2348fc2c;
	Data_234e73a4.onExit = sub_2348fc2c;

    memset(&sp4, 0xff, sizeof(Transponder));
    sub_2348f688(&sp4);

    Data_2396e224[0] = 0; //r5

    Data_234e7268->graphicData->pItems[42].width = 0x20;

    menu_stack_operate(Data_234e7268);

    if (0 != sub_2348dd36(Data_234e7268, 1))
    {
        //0x2348fce0
        //loc_2348fcf2
        (Data_234e7268->onExit)(r6);

        return 8;
    }
    //loc_2348fce4
    else if (0 != sub_2348dd36(Data_234e726c, 0))
    {
        //0x2348fcf0
        //loc_2348fcf2
        (Data_234e726c->onExit)(r6);

        return 8;
    }
    //loc_2348fcfe
    sub_2348dcd8(Data_23970198.Data_23970198->bData_0x5f);

    /*sub_2344de56*/sub_2343d51e(Data_234e7268, r6);

    memset(&scan_params, 0, sizeof(Struct_2343df02));

    sub_23454294(&scan_params);

    scan_params.pfProgress = sub_2348f8cc;
    scan_params.Data_8 = sub_2348f56e;

    scan_params.bData_0x12 = sp_0x34.Data_4.bitData.bit23;

    if (scan_params.bData_0x12 != 0)
    {
        //0x2348fd3a
        if (0 == fe_manager_get_transponder_type(scan_params.pList))
        {
            scan_params.bData_0x12 = 0; //r5
        }
        //loc_2348fd48
    }
    //loc_2348fd48
    /*sub_2340dd08*/sub_2340b22c(0xff);

    scan_start(&scan_params);

    return 0;
}


/* /  / 2348fe7a - todo */
void sub_2348fe7a()
{
#if 1
	console_send_string("sub_2348fe7a (todo.c): TODO\r\n");
#endif


    return 0;
}


/* /  / 2348ff32 - todo */
int sub_2348ff32(int a)
{
#if 0
	console_send_string("sub_2348ff32 (todo.c): TODO\r\n");
#endif

	Struct_2348dc50 sp;

	Data_23970198.Data_239701a0 = &Data_23970198.Data_2396f1ec; //r4

	memset(&Data_23970198.Data_2396f1ec, 0xff, 4000);

    memset(&sp, 0, sizeof(Struct_2348dc50));

    sp.Data_0x10 = &Data_23970198.Data_2396f1ec; //r4
    sp.pMenu = Data_234e726c;
    sp.wData_0x1c = 2;
    sp.Data_0x14 = sub_2348fe7a;
    sp.Data_0x54 = 0; //r4
    sp.Data_0x18 = sub_2348dbf8;
    sp.wData_0x1e = 0; //r4
    sp.wData_0x22 = 0; //r4
    sp.wData_0x20 = 0; //r4
    sp.wData_0x24 = 0; //r4
    sp.wData_0x26 = 6;
    sp.bData_0x58 = 6;
    sp.bData_0x5c = 7;
    sp.bData_0x5d = 8;
    sp.bData_0x5e = 9;
    sp.bData_0x59 = 2;
    sp.bData_0x5a = 10;
    sp.bData_0x5b = 9;

	Data_23970198.Data_239701a4 = sub_2348dc50(&sp);

	Data_23970198.wData_239701a8 = 0; //r4

    return 0;
}


/* /  / 2348ff9e - todo */
int sub_2348ff9e(int a)
{
#if 0
	console_send_string("sub_2348ff9e (todo.c): TODO\r\n");
#endif

    Struct_2348dc50 sp4;

    Channel_Database* r6 = /*sub_234107b0*/sub_2344f770();

    Data_23970198.Data_23970194 = &Data_23970198.Data_2396e24c; //r4

    memset(&Data_23970198.Data_2396e24c, 0xff, 4000);

    memset(&sp4, 0, sizeof(Struct_2348dc50));

    Data_23970198.sema = Data_234c1258;

    sp4.Data_0x10 = &Data_23970198.Data_2396e24c; //r4
    sp4.pMenu = Data_234e7268;
    sp4.wData_0x1c = 2;
    sp4.Data_0x54 = 0; //r4
    sp4.Data_0x14 = sub_2348fe7a;
    sp4.Data_0x18 = sub_2348dbf8;
    sp4.wData_0x1e = 0; //r4
    sp4.wData_0x22 = 0; //r4
    sp4.wData_0x20 = 0; //r4
    sp4.wData_0x24 = 0; //r4
    sp4.wData_0x26 = 6;
    sp4.bData_0x58 = 6;
    sp4.bData_0x5c = 7;
    sp4.bData_0x5d = 8;
    sp4.bData_0x5e = 9;
    sp4.bData_0x59 = 2;
    sp4.bData_0x5a = 10;
    sp4.bData_0x5b = 9;

    Data_23970198.Data_23970198 = sub_2348dc50(&sp4);

    Data_23970198.wData_2397019c = 0; //r4
    Data_23970198.Data_239701ac = crc32(r6, 240000);

    return 0;
}


#endif
