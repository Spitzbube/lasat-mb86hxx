
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
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c1298; //234c1298
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12ec; //234c12ec
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12f8; //234c12f8

/*extern*/ uint8_t Data_234e1e68[40] = "1"; //234e1e68, size???
/*extern*/ uint8_t Data_234e1e8c[40] = "2"; //234e1e8c, size???
/*extern*/ uint8_t Data_234e1eb0[40] = "3"; //234e1eb0, size???
/*extern*/ uint8_t Data_234e1ed4[40] = "4"; //234e1ed4, size???
/*extern*/ uint8_t Data_234e1ef8[40] = "5"; //234e1ef8, size???
/*extern*/ uint8_t Data_234e1f1c[40] = "6"; //234e1f1c, size???
/*extern*/ uint8_t Data_234e1fd0[40] = "EINS"; //234e1fd0, size???
/*extern*/ uint8_t Data_234e1ffc[40] = "ZWEI"; //234e1ffc, size???
/*extern*/ uint8_t Data_234e2028[40] = "DREI"; //234e2028, size???
/*extern*/ uint8_t Data_234e2054[40] = "VIER"; //234e2054, size???
/*extern*/ uint8_t Data_234e2080[40] = "FUENF"; //234e2080, size???
/*extern*/ uint8_t Data_234e20ac[40] = "SECHS"; //234e20ac, size???
/*extern*/ uint8_t Data_234e92d4[]; //234e92d4
/*extern*/ uint8_t Data_234e92dc[]; //234e92dc
/*extern*/ uint8_t Data_234e92e4[]; //234e92e4
/*extern*/ uint8_t Data_234e92ec[]; //234e92ec
/*extern*/ uint8_t Data_234e92f4[]; //234e92f4
/*extern*/ uint8_t Data_234e92fc[]; //234e92fc

static void graphic_unlock(void);
static int graphic_lock(void);
static int sub_2348ff32(int);
static int sub_2348ff9e(int);
static int sub_2348fc2c(UI_Thread_Params*);
static void update_transponder_value_strings(Transponder*);

static Menu Data_234e72f0; //234e72f0
static Menu Data_234e732c; //234e732c
static Graphic_Job_2_5_Item Data_234e786c[]; //234e786c
static Graphic_Job_2_5 Data_234e8e6c; //234e8e6c
static Menu_Item Data_234e8eb4[]; //234e8eb4
static Menu_Item Data_234e8fbc[]; //234e8fbc
static uint8_t Data_2396e104[]; //2396e104
static uint8_t Data_2396e224[]; //2396e224
static uint8_t Data_239701b0[]; //239701b0
static uint8_t Data_239701d8[]; //239701d8
static uint8_t Data_239701ec[]; //239701ec
static uint8_t Data_23970200[]; //23970200
static uint8_t Data_23970214[]; //23970214
static uint8_t Data_23970228[]; //23970228
static uint8_t Data_2397023c[]; //2397023c
static uint8_t Data_239702a0[]; //239702a0
static uint8_t Data_239702c8[]; //239702c8
static uint8_t Data_239702f0[]; //239702f0
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

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234e72d8 = //234e72d8
{
	7, 4, 0x0f, //...
#if 0
0x234e72d8                        dw         0x0007                             ; DATA XREF=sub_234904ce+78, 0x234e82c4
0x234e72da 0000                   movs       r0, r0
0x234e72dc                        dd         0x00000004                         ; DATA XREF=sub_234904ce+84
0x234e72e0                        db         0x0f
#endif	
};

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234e72e4 = //234e72e4
{
	3, 4, 0x0f, //...
#if 0
0x234e72e4                        dw         0x0003                             ; DATA XREF=sub_234904ce+86, 0x234e8304
0x234e72e6 0000                   movs       r0, r0
0x234e72e8                        dd         0x00000004                         ; DATA XREF=sub_234904ce+88
0x234e72ec                        db         0x0f
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
		5, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		graphic_start_job_2_5, //void (*graphicHandler)(); //0x1c
		0, //menu_items_navigate, //void (*onNavigate)(); //0x20
		sub_2348ff9e, //int (*onEnter)(int); //36 = 0x24
		sub_2348fc2c, //int (*onExit)(UI_Thread_Params*); //0x28
#if 0
0x234e72f0                        dw         0x007a                             ; DATA XREF=sub_2348f56e+12, sub_2348f56e+116, sub_2348f688+14, scan_progress+14, aDd_2348fa10+332, sub_2348fc86+20, sub_2348fc86+60, sub_2348fc86+78, sub_2348fda0+10, sub_2348fda0+46, sub_2348fda0+52
0x234e72f2 0000                   movs       r0, r0
0x234e72f4                        dd         0x234e8eb4
0x234e72f8                        dd         0x234e8eb4
0x234e72fc                        dd         0x234e78ac
0x234e7300                        dd         0x234e792c
0x234e7304                        dd         0x234e8e6c                         ; DATA XREF=sub_2348f56e+14, sub_2348f56e+118, sub_2348f688+18, scan_progress+16, aDd_2348fa10+334, sub_2348fc86+66, sub_2349052a+10
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
		5, //uint8_t maxItem; //0x18 = 24
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

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234e73e0 = //234e73e0
{
	9, 0, 0x06, //...
#if 0
0x234e73e0                        dw         0x0009                             ; DATA XREF=0x234e81c4
0x234e73e2 0000                   movs       r0, r0
0x234e73e4                        dd         0x00000000
0x234e73e8                        db         0x06
#endif	
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

static Graphic_Job_2_5_Item_Text Data_234e7404 = //234e7404
{
    0, 0x0047, 0x0064, 0x0088, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_234e1e68[0], 0, 0, 0
#if 0
0x234e7404                        db         0x00                               ; DATA XREF=0x234e7a8c
0x234e7405                        db         0x00
0x234e7406                        dw         0x0047
0x234e7408                        dw         0x0064
0x234e740a                        dw         0x0088
0x234e740c                        dw         0x0080
0x234e740e                        db         0x01
0x234e740f                        db         0x04
0x234e7410                        db         0x09
0x234e7411                        db         0x01
0x234e7412 0000                   movs       r0, r0
0x234e7414                        dd         0x234e1e68
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e741c = //234e741c
{
    0, 0x0047, 0x0084, 0x0088, 0x00a0, 0x01, 0x04, 0x09, 0x01, &Data_234e1e8c[0], 0, 0, 0
#if 0
0x234e741c                        db         0x00                               ; DATA XREF=0x234e7acc
0x234e741d                        db         0x00
0x234e741e                        dw         0x0047
0x234e7420                        dw         0x0084
0x234e7422                        dw         0x0088
0x234e7424                        dw         0x00a0
0x234e7426                        db         0x01
0x234e7427                        db         0x04
0x234e7428                        db         0x09
0x234e7429                        db         0x01
0x234e742a 0000                   movs       r0, r0
0x234e742c                        dd         0x234e1e8c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e7434 = //234e7434
{
    0, 0x0047, 0x00a4, 0x0088, 0x00c0, 0x01, 0x04, 0x09, 0x01, &Data_234e1eb0[0], 0, 0, 0
#if 0
0x234e7434                        db         0x00                               ; DATA XREF=0x234e7b0c
0x234e7435                        db         0x00
0x234e7436                        dw         0x0047
0x234e7438                        dw         0x00a4
0x234e743a                        dw         0x0088
0x234e743c                        dw         0x00c0
0x234e743e                        db         0x01
0x234e743f                        db         0x04
0x234e7440                        db         0x09
0x234e7441                        db         0x01
0x234e7442 0000                   movs       r0, r0
0x234e7444                        dd         0x234e1eb0
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e744c = //234e744c
{
    0, 0x0047, 0x00c4, 0x0088, 0x00e0, 0x01, 0x04, 0x09, 0x01, &Data_234e1ed4[0], 0, 0, 0
#if 0
0x234e744c                        db         0x00                               ; DATA XREF=0x234e7b4c
0x234e744d                        db         0x00
0x234e744e                        dw         0x0047
0x234e7450                        dw         0x00c4
0x234e7452                        dw         0x0088
0x234e7454                        dw         0x00e0
0x234e7456                        db         0x01
0x234e7457                        db         0x04
0x234e7458                        db         0x09
0x234e7459                        db         0x01
0x234e745a 0000                   movs       r0, r0
0x234e745c                        dd         0x234e1ed4
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e7464 = //234e7464
{
    0, 0x0047, 0x00e4, 0x0088, 0x0100, 0x01, 0x04, 0x09, 0x01, &Data_234e1ef8[0], 0, 0, 0
#if 0
0x234e7464                        db         0x00                               ; DATA XREF=0x234e7b8c
0x234e7465                        db         0x00
0x234e7466                        dw         0x0047
0x234e7468                        dw         0x00e4
0x234e746a                        dw         0x0088
0x234e746c                        dw         0x0100
0x234e746e                        db         0x01
0x234e746f                        db         0x04
0x234e7470                        db         0x09
0x234e7471                        db         0x01
0x234e7472 0000                   movs       r0, r0
0x234e7474                        dd         0x234e1ef8
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e747c = //234e747c
{
    0, 0x0047, 0x0104, 0x0088, 0x0120, 0x01, 0x04, 0x09, 0x01, &Data_234e1f1c[0], 0, 0, 0
#if 0
0x234e747c                        db         0x00                               ; DATA XREF=0x234e7bcc
0x234e747d                        db         0x00
0x234e747e                        dw         0x0047
0x234e7480                        dw         0x0104
0x234e7482                        dw         0x0088
0x234e7484                        dw         0x0120
0x234e7486                        db         0x01
0x234e7487                        db         0x04
0x234e7488                        db         0x09
0x234e7489                        db         0x01
0x234e748a 0000                   movs       r0, r0
0x234e748c                        dd         0x234e1f1c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e74f4 = //234e74f4
{
    0, 0x0097, 0x0064, 0x015c, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_234e1fd0[0], 0, 0, 0
#if 0
0x234e74f4                        db         0x00                               ; DATA XREF=0x234e7c0c
0x234e74f5                        db         0x00
0x234e74f6                        dw         0x0097
0x234e74f8                        dw         0x0064
0x234e74fa                        dw         0x015c
0x234e74fc                        dw         0x0080
0x234e74fe                        db         0x01
0x234e74ff                        db         0x04
0x234e7500                        db         0x09
0x234e7501                        db         0x01
0x234e7502 0000                   movs       r0, r0
0x234e7504                        dd         0x234e1fd0                         ; "EINS"
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e750c = //234e750c
{
    0, 0x0097, 0x0084, 0x015c, 0x00a0, 0x01, 0x04, 0x09, 0x01, &Data_234e1ffc[0], 0, 0, 0
#if 0
0x234e750c                        db         0x00                               ; DATA XREF=0x234e7c4c
0x234e750d                        db         0x00
0x234e750e                        dw         0x0097
0x234e7510                        dw         0x0084
0x234e7512                        dw         0x015c
0x234e7514                        dw         0x00a0
0x234e7516                        db         0x01
0x234e7517                        db         0x04
0x234e7518                        db         0x09
0x234e7519                        db         0x01
0x234e751a 0000                   movs       r0, r0
0x234e751c                        dd         0x234e1ffc                         ; "ZWEI"
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e7524 = //234e7524
{
    0, 0x0097, 0x00a4, 0x015c, 0x00c0, 0x01, 0x04, 0x09, 0x01, &Data_234e2028[0], 0, 0, 0
#if 0
0x234e7524                        db         0x00                               ; DATA XREF=0x234e7c8c
0x234e7525                        db         0x00
0x234e7526                        dw         0x0097
0x234e7528                        dw         0x00a4
0x234e752a                        dw         0x015c
0x234e752c                        dw         0x00c0
0x234e752e                        db         0x01
0x234e752f                        db         0x04
0x234e7530                        db         0x09
0x234e7531                        db         0x01
0x234e7532 0000                   movs       r0, r0
0x234e7534                        dd         0x234e2028                         ; "DREI"
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e753c = //234e753c
{
    0, 0x0097, 0x00c4, 0x015c, 0x00e0, 0x01, 0x04, 0x09, 0x01, &Data_234e2054[0], 0, 0, 0
#if 0
0x234e753c                        db         0x00                               ; DATA XREF=0x234e7ccc
0x234e753d                        db         0x00
0x234e753e                        dw         0x0097
0x234e7540                        dw         0x00c4
0x234e7542                        dw         0x015c
0x234e7544                        dw         0x00e0
0x234e7546                        db         0x01
0x234e7547                        db         0x04
0x234e7548                        db         0x09
0x234e7549                        db         0x01
0x234e754a 0000                   movs       r0, r0
0x234e754c                        dd         0x234e2054                         ; "VIER"
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e7554 = //234e7554
{
    0, 0x0097, 0x00e4, 0x015c, 0x0100, 0x01, 0x04, 0x09, 0x01, &Data_234e2080[0], 0, 0, 0
#if 0
0x234e7554                        db         0x00                               ; DATA XREF=0x234e7d0c
0x234e7555                        db         0x00
0x234e7556                        dw         0x0097
0x234e7558                        dw         0x00e4
0x234e755a                        dw         0x015c
0x234e755c                        dw         0x0100
0x234e755e                        db         0x01
0x234e755f                        db         0x04
0x234e7560                        db         0x09
0x234e7561                        db         0x01
0x234e7562 0000                   movs       r0, r0
0x234e7564                        dd         0x234e2080                         ; "FUENF"
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e756c = //234e756c
{
    0, 0x0097, 0x0104, 0x015c, 0x0120, 0x01, 0x04, 0x09, 0x01, &Data_234e20ac[0], 0, 0, 0
#if 0
0x234e756c                        db         0x00                               ; DATA XREF=0x234e7d4c
0x234e756d                        db         0x00
0x234e756e                        dw         0x0097
0x234e7570                        dw         0x0104
0x234e7572                        dw         0x015c
0x234e7574                        dw         0x0120
0x234e7576                        db         0x01
0x234e7577                        db         0x04
0x234e7578                        db         0x09
0x234e7579                        db         0x01
0x234e757a 0000                   movs       r0, r0
0x234e757c                        dd         0x234e20ac                         ; "SECHS"
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

static Graphic_Job_2_5_Item_Text Data_234e75fc = //234e75fc
{
    0, 0x017d, 0x0064, 0x01be, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_234e92d4[0], 0, 0, 0
#if 0
0x234e75fc                        db         0x00                               ; DATA XREF=0x234e7e0c
0x234e75fd                        db         0x00
0x234e75fe                        dw         0x017d
0x234e7600                        dw         0x0064
0x234e7602                        dw         0x01be
0x234e7604                        dw         0x0080
0x234e7606                        db         0x01
0x234e7607                        db         0x04
0x234e7608                        db         0x09
0x234e7609                        db         0x01
0x234e760a 0000                   movs       r0, r0
0x234e760c                        dd         0x234e92d4
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e7614 = //234e7614
{
    0, 0x017d, 0x0084, 0x01be, 0x00a0, 0x01, 0x04, 0x09, 0x01, &Data_234e92dc[0], 0, 0, 0
#if 0
0x234e7614                        db         0x00                               ; DATA XREF=0x234e7e4c
0x234e7615                        db         0x00
0x234e7616                        dw         0x017d
0x234e7618                        dw         0x0084
0x234e761a                        dw         0x01be
0x234e761c                        dw         0x00a0
0x234e761e                        db         0x01
0x234e761f                        db         0x04
0x234e7620                        db         0x09
0x234e7621                        db         0x01
0x234e7622 0000                   movs       r0, r0
0x234e7624                        dd         0x234e92dc
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e762c = //234e762c
{
    0, 0x017d, 0x00a4, 0x01be, 0x00c0, 0x01, 0x04, 0x09, 0x01, &Data_234e92e4[0], 0, 0, 0
#if 0
0x234e762c                        db         0x00                               ; DATA XREF=0x234e7e8c
0x234e762d                        db         0x00
0x234e762e                        dw         0x017d
0x234e7630                        dw         0x00a4
0x234e7632                        dw         0x01be
0x234e7634                        dw         0x00c0
0x234e7636                        db         0x01
0x234e7637                        db         0x04
0x234e7638                        db         0x09
0x234e7639                        db         0x01
0x234e763a 0000                   movs       r0, r0
0x234e763c                        dd         0x234e92e4
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e7644 = //234e7644
{
    0, 0x017d, 0x00c4, 0x01be, 0x00e0, 0x01, 0x04, 0x09, 0x01, &Data_234e92ec[0], 0, 0, 0
#if 0
0x234e7644                        db         0x00                               ; DATA XREF=0x234e7ecc
0x234e7645                        db         0x00
0x234e7646                        dw         0x017d
0x234e7648                        dw         0x00c4
0x234e764a                        dw         0x01be
0x234e764c                        dw         0x00e0
0x234e764e                        db         0x01
0x234e764f                        db         0x04
0x234e7650                        db         0x09
0x234e7651                        db         0x01
0x234e7652 0000                   movs       r0, r0
0x234e7654                        dd         0x234e92ec
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e765c = //234e765c
{
    0, 0x017d, 0x00e4, 0x01be, 0x0100, 0x01, 0x04, 0x09, 0x01, &Data_234e92f4[0], 0, 0, 0
#if 0
0x234e765c                        db         0x00                               ; DATA XREF=0x234e7f0c
0x234e765d                        db         0x00
0x234e765e                        dw         0x017d
0x234e7660                        dw         0x00e4
0x234e7662                        dw         0x01be
0x234e7664                        dw         0x0100
0x234e7666                        db         0x01
0x234e7667                        db         0x04
0x234e7668                        db         0x09
0x234e7669                        db         0x01
0x234e766a 0000                   movs       r0, r0
0x234e766c                        dd         0x234e92f4
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e7674 = //234e7674
{
    0, 0x017d, 0x0104, 0x01be, 0x0120, 0x01, 0x04, 0x09, 0x01, &Data_234e92fc[0], 0, 0, 0
#if 0
0x234e7674                        db         0x00                               ; DATA XREF=0x234e7f4c
0x234e7675                        db         0x00
0x234e7676                        dw         0x017d
0x234e7678                        dw         0x0104
0x234e767a                        dw         0x01be
0x234e767c                        dw         0x0120
0x234e767e                        db         0x01
0x234e767f                        db         0x04
0x234e7680                        db         0x09
0x234e7681                        db         0x01
0x234e7682 0000                   movs       r0, r0
0x234e7684                        dd         0x234e92fc
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e76ec = //234e76ec
{
    0, 0x01cd, 0x0064, 0x0292, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_239701d8[0], 0, 0, 0
#if 0
0x234e76ec                        db         0x00                               ; DATA XREF=0x234e7f8c
0x234e76ed                        db         0x00
0x234e76ee                        dw         0x01cd
0x234e76f0                        dw         0x0064
0x234e76f2                        dw         0x0292
0x234e76f4                        dw         0x0080
0x234e76f6                        db         0x01
0x234e76f7                        db         0x04
0x234e76f8                        db         0x09
0x234e76f9                        db         0x01
0x234e76fa 0000                   movs       r0, r0
0x234e76fc                        dd         0x239701d8
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e7704 = //234e7704
{
    0, 0x01cd, 0x0084, 0x0292, 0x00a0, 0x01, 0x04, 0x09, 0x01, &Data_239701ec[0], 0, 0, 0
#if 0
0x234e7704                        db         0x00                               ; DATA XREF=0x234e7fcc
0x234e7705                        db         0x00
0x234e7706                        dw         0x01cd
0x234e7708                        dw         0x0084
0x234e770a                        dw         0x0292
0x234e770c                        dw         0x00a0
0x234e770e                        db         0x01
0x234e770f                        db         0x04
0x234e7710                        db         0x09
0x234e7711                        db         0x01
0x234e7712 0000                   movs       r0, r0
0x234e7714                        dd         0x239701ec
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e771c = //234e771c
{
    0, 0x01cd, 0x00a4, 0x0292, 0x00c0, 0x01, 0x04, 0x09, 0x01, &Data_23970200[0], 0, 0, 0
#if 0
0x234e771c                        db         0x00                               ; DATA XREF=0x234e800c
0x234e771d                        db  0x00 ; '.'
0x234e771e                        dw         0x01cd
0x234e7720                        dw         0x00a4
0x234e7722                        dw         0x0292
0x234e7724                        dw         0x00c0
0x234e7726                        db         0x01
0x234e7727                        db         0x04
0x234e7728                        db         0x09
0x234e7729                        db         0x01
0x234e772a 0000                   movs       r0, r0
0x234e772c                        dd         0x23970200
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e7734 = //234e7734
{
    0, 0x01cd, 0x00c4, 0x0292, 0x00e0, 0x01, 0x04, 0x09, 0x01, &Data_23970214[0], 0, 0, 0
#if 0
0x234e7734                        db         0x00                               ; DATA XREF=0x234e804c
0x234e7735                        db         0x00
0x234e7736                        dw         0x01cd
0x234e7738                        dw         0x00c4
0x234e773a                        dw         0x0292
0x234e773c                        dw         0x00e0
0x234e773e                        db         0x01
0x234e773f                        db         0x04
0x234e7740                        db         0x09
0x234e7741                        db         0x01
0x234e7742 0000                   movs       r0, r0
0x234e7744                        dd         0x23970214
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e774c = //234e774c
{
    0, 0x01cd, 0x00e4, 0x0292, 0x0100, 0x01, 0x04, 0x09, 0x01, &Data_23970228[0], 0, 0, 0
#if 0
0x234e774c                        db         0x00                               ; DATA XREF=0x234e808c
0x234e774d                        db         0x00
0x234e774e                        dw         0x01cd
0x234e7750                        dw         0x00e4
0x234e7752                        dw         0x0292
0x234e7754                        dw         0x0100
0x234e7756                        db         0x01
0x234e7757                        db         0x04
0x234e7758                        db         0x09
0x234e7759                        db         0x01
0x234e775a 0000                   movs       r0, r0
0x234e775c                        dd         0x23970228
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e7764 = //234e7764
{
    0, 0x01cd, 0x0104, 0x0292, 0x0120, 0x01, 0x04, 0x09, 0x01, &Data_2397023c[0], 0, 0, 0
#if 0
0x234e7764                        db         0x00                               ; DATA XREF=0x234e80cc
0x234e7765                        db         0x00
0x234e7766                        dw         0x01cd
0x234e7768                        dw         0x0104
0x234e776a                        dw         0x0292
0x234e776c                        dw         0x0120
0x234e776e                        db         0x01
0x234e776f                        db         0x04
0x234e7770                        db         0x09
0x234e7771                        db         0x01
0x234e7772 0000                   movs       r0, r0
0x234e7774                        dd         0x2397023c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e77dc = //234e77dc
{
    0, 0x0047, 0x0135, 0x015d, 0x0151, 0x01, 0x04, 0x09, 0x01, &Data_239702a0[0], 0, 0, 0
#if 0
0x234e77dc                        db         0x00                               ; DATA XREF=0x234e818c
0x234e77dd                        db         0x00
0x234e77de                        dw         0x0047
0x234e77e0                        dw         0x0135
0x234e77e2                        dw         0x015d
0x234e77e4                        dw         0x0151
0x234e77e6                        db         0x01
0x234e77e7                        db         0x04
0x234e77e8                        db         0x09
0x234e77e9                        db         0x01
0x234e77ea 0000                   movs       r0, r0
0x234e77ec                        dd         0x239702a0
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e77f4 = //234e77f4
{
    0, 0x0047, 0x0155, 0x015d, 0x0171, 0x01, 0x04, 0x09, 0x01, &Data_239702c8[0], 0, 0, 0
#if 0
0x234e77f4                        db         0x00                               ; DATA XREF=0x234e81cc
0x234e77f5                        db         0x00
0x234e77f6                        dw         0x0047
0x234e77f8                        dw         0x0155
0x234e77fa                        dw         0x015d
0x234e77fc                        dw         0x0171
0x234e77fe                        db         0x01
0x234e77ff                        db         0x04
0x234e7800                        db         0x09
0x234e7801                        db         0x01
0x234e7802 0000                   movs       r0, r0
0x234e7804                        dd         0x239702c8
#endif
};

static Graphic_Job_2_5_Item_Text Data_234e780c = //234e780c
{
    0, 0x0047, 0x0175, 0x015d, 0x0191, 0x01, 0x04, 0x09, 0x01, &Data_239702f0[0], 0, 0, 0
#if 0
0x234e780c                        db         0x00                               ; DATA XREF=0x234e820c
0x234e780d                        db         0x00
0x234e780e                        dw         0x0047
0x234e7810                        dw         0x0175
0x234e7812                        dw         0x015d
0x234e7814                        dw         0x0191
0x234e7816                        db         0x01
0x234e7817                        db         0x04
0x234e7818                        db         0x09
0x234e7819                        db         0x01
0x234e781a 0000                   movs       r0, r0
0x234e781c                        dd         0x239702f0
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
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0060, 0x004b, 0x0020, 0, &Data_234c12f8/*Data_0x18*/, 9, 0, &Data_234e7404/*Data_0x20*/}, //[8] = 234E7A6C
#if 0
0x234e7a6c                        db         0x01                               ; DATA XREF=0x234e8eb8
0x234e7a6d                        db  0x00 ; '.'
0x234e7a6e 0000                   movs       r0, r0
0x234e7a70                        dd         0x00000000
0x234e7a74                        dd         0x00000000
0x234e7a78                        dw         0x003d
0x234e7a7a                        dw         0x0060
0x234e7a7c                        dw         0x004b
0x234e7a7e                        dw         0x0020
0x234e7a80 0000                   movs       r0, r0
0x234e7a82 0000                   movs       r0, r0
0x234e7a84                        dd         0x234c12f8
0x234e7a88                        dw         0x0009
0x234e7a8a 0000                   movs       r0, r0
0x234e7a8c                        dd         0x234e7404
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0080, 0x004b, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e741c/*Data_0x20*/}, //[9] = 234E7AAC
#if 0
0x234e7aac                        db         0x01                               ; DATA XREF=0x234e8ee4
0x234e7aad                        db  0x00 ; '.'
0x234e7aae 0000                   movs       r0, r0
0x234e7ab0                        dd         0x00000000
0x234e7ab4                        dd         0x00000000
0x234e7ab8                        dw         0x003d
0x234e7aba                        dw         0x0080
0x234e7abc                        dw         0x004b
0x234e7abe                        dw         0x0020
0x234e7ac0 0000                   movs       r0, r0
0x234e7ac2 0000                   movs       r0, r0
0x234e7ac4                        dd         0x234e73e0
0x234e7ac8                        dw         0x0009
0x234e7aca 0000                   movs       r0, r0
0x234e7acc                        dd         0x234e741c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x00a0, 0x004b, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e7434/*Data_0x20*/}, //[10] = 234E7AEC
#if 0
0x234e7aec                        db         0x01
0x234e7aed                        db  0x00 ; '.'
0x234e7aee 0000                   movs       r0, r0
0x234e7af0                        dd         0x00000000
0x234e7af4                        dd         0x00000000
0x234e7af8                        dw         0x003d
0x234e7afa                        dw         0x00a0
0x234e7afc                        dw         0x004b
0x234e7afe                        dw         0x0020
0x234e7b00 0000                   movs       r0, r0
0x234e7b02 0000                   movs       r0, r0
0x234e7b04                        dd         0x234e73e0
0x234e7b08                        dw         0x0009
0x234e7b0a 0000                   movs       r0, r0
0x234e7b0c                        dd         0x234e7434
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x00c0, 0x004b, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e744c/*Data_0x20*/}, //[11] = 234E7B2C
#if 0
0x234e7b2c                        db         0x01
0x234e7b2d                        db  0x00 ; '.'
0x234e7b2e 0000                   movs       r0, r0
0x234e7b30                        dd         0x00000000
0x234e7b34                        dd         0x00000000
0x234e7b38                        dw         0x003d
0x234e7b3a                        dw         0x00c0
0x234e7b3c                        dw         0x004b
0x234e7b3e                        dw         0x0020
0x234e7b40 0000                   movs       r0, r0
0x234e7b42 0000                   movs       r0, r0
0x234e7b44                        dd         0x234e73e0
0x234e7b48                        dw         0x0009
0x234e7b4a 0000                   movs       r0, r0
0x234e7b4c                        dd         0x234e744c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x00e0, 0x004b, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e7464/*Data_0x20*/}, //[12] = 234E7B6C
#if 0
0x234e7b6c                        db         0x01
0x234e7b6d                        db  0x00 ; '.'
0x234e7b6e 0000                   movs       r0, r0
0x234e7b70                        dd         0x00000000
0x234e7b74                        dd         0x00000000
0x234e7b78                        dw         0x003d
0x234e7b7a                        dw         0x00e0
0x234e7b7c                        dw         0x004b
0x234e7b7e                        dw         0x0020
0x234e7b80 0000                   movs       r0, r0
0x234e7b82 0000                   movs       r0, r0
0x234e7b84                        dd         0x234e73e0
0x234e7b88                        dw         0x0009
0x234e7b8a 0000                   movs       r0, r0
0x234e7b8c                        dd         0x234e7464
#endif
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x0100, 0x004b, 0x0020, 0, &Data_234c12ec/*Data_0x18*/, 9, 0, &Data_234e747c/*Data_0x20*/}, //[13] = 234E7BAC
#if 0
0x234e7bac                        db         0x01
0x234e7bad                        db  0x00 ; '.'
0x234e7bae 0000                   movs       r0, r0
0x234e7bb0                        dd         0x00000000
0x234e7bb4                        dd         0x00000000
0x234e7bb8                        dw         0x003d
0x234e7bba                        dw         0x0100
0x234e7bbc                        dw         0x004b
0x234e7bbe                        dw         0x0020
0x234e7bc0 0000                   movs       r0, r0
0x234e7bc2 0000                   movs       r0, r0
0x234e7bc4                        dd         0x234c12ec
0x234e7bc8                        dw         0x0009
0x234e7bca 0000                   movs       r0, r0
0x234e7bcc                        dd         0x234e747c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x008d, 0x0060, 0x00cf, 0x0020, 0, &Data_234c12f8/*Data_0x18*/, 9, 0, &Data_234e74f4/*Data_0x20*/}, //[14] = 234E7BEC
#if 0
0x234e7bec                        db         0x01                               ; DATA XREF=0x234e8ebc
0x234e7bed                        db  0x00 ; '.'
0x234e7bee 0000                   movs       r0, r0
0x234e7bf0                        dd         0x00000000
0x234e7bf4                        dd         0x00000000
0x234e7bf8                        dw         0x008d
0x234e7bfa                        dw         0x0060
0x234e7bfc                        dw         0x00cf
0x234e7bfe                        dw         0x0020
0x234e7c00 0000                   movs       r0, r0
0x234e7c02 0000                   movs       r0, r0
0x234e7c04                        dd         0x234c12f8
0x234e7c08                        dw         0x0009
0x234e7c0a 0000                   movs       r0, r0
0x234e7c0c                        dd         0x234e74f4
#endif
	{1, 0, 0, 0/*Data_8*/, 0x008d, 0x0080, 0x00cf, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e750c/*Data_0x20*/}, //[15] = 234E7C2C
#if 0
0x234e7c2c                        db         0x01                               ; DATA XREF=0x234e8ee8
0x234e7c2d                        db  0x00 ; '.'
0x234e7c2e 0000                   movs       r0, r0
0x234e7c30                        dd         0x00000000
0x234e7c34                        dd         0x00000000
0x234e7c38                        dw         0x008d
0x234e7c3a                        dw         0x0080
0x234e7c3c                        dw         0x00cf
0x234e7c3e                        dw         0x0020
0x234e7c40 0000                   movs       r0, r0
0x234e7c42 0000                   movs       r0, r0
0x234e7c44                        dd         0x234e73e0
0x234e7c48                        dw         0x0009
0x234e7c4a 0000                   movs       r0, r0
0x234e7c4c                        dd         0x234e750c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x008d, 0x00a0, 0x00cf, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e7524/*Data_0x20*/}, //[16] = 234E7C6C
#if 0
0x234e7c6c                        db         0x01
0x234e7c6d                        db  0x00 ; '.'
0x234e7c6e 0000                   movs       r0, r0
0x234e7c70                        dd         0x00000000
0x234e7c74                        dd         0x00000000
0x234e7c78                        dw         0x008d
0x234e7c7a                        dw         0x00a0
0x234e7c7c                        dw         0x00cf
0x234e7c7e                        dw         0x0020
0x234e7c80 0000                   movs       r0, r0
0x234e7c82 0000                   movs       r0, r0
0x234e7c84                        dd         0x234e73e0
0x234e7c88                        dw         0x0009
0x234e7c8a 0000                   movs       r0, r0
0x234e7c8c                        dd         0x234e7524
#endif
	{1, 0, 0, 0/*Data_8*/, 0x008d, 0x00c0, 0x00cf, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e753c/*Data_0x20*/}, //[17] = 234E7CAC
#if 0
0x234e7cac                        db         0x01
0x234e7cad                        db  0x00 ; '.'
0x234e7cae 0000                   movs       r0, r0
0x234e7cb0                        dd         0x00000000
0x234e7cb4                        dd         0x00000000
0x234e7cb8                        dw         0x008d
0x234e7cba                        dw         0x00c0
0x234e7cbc                        dw         0x00cf
0x234e7cbe                        dw         0x0020
0x234e7cc0                        db         0x00
0x234e7cc1                        db  0x00 ; '.'
0x234e7cc2 0000                   movs       r0, r0
0x234e7cc4                        dd         0x234e73e0
0x234e7cc8                        dw         0x0009
0x234e7cca 0000                   movs       r0, r0
0x234e7ccc                        dd         0x234e753c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x008d, 0x00e0, 0x00cf, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e7554/*Data_0x20*/}, //[18] = 234E7CEC
#if 0
0x234e7cec                        db         0x01
0x234e7ced                        db  0x00 ; '.'
0x234e7cee 0000                   movs       r0, r0
0x234e7cf0                        dd         0x00000000
0x234e7cf4                        dd         0x00000000
0x234e7cf8                        dw         0x008d
0x234e7cfa                        dw         0x00e0
0x234e7cfc                        dw         0x00cf
0x234e7cfe                        dw         0x0020
0x234e7d00 0000                   movs       r0, r0
0x234e7d02 0000                   movs       r0, r0
0x234e7d04                        dd         0x234e73e0
0x234e7d08                        dw         0x0009
0x234e7d0a 0000                   movs       r0, r0
0x234e7d0c                        dd         0x234e7554
#endif
	{1, 0, 0, 0/*Data_8*/, 0x008d, 0x0100, 0x00cf, 0x0020, 0, &Data_234c12ec/*Data_0x18*/, 9, 0, &Data_234e756c/*Data_0x20*/}, //[19] = 234E7D2C
#if 0
0x234e7d2c                        db         0x01
0x234e7d2d                        db  0x00 ; '.'
0x234e7d2e 0000                   movs       r0, r0
0x234e7d30                        dd         0x00000000
0x234e7d34                        dd         0x00000000
0x234e7d38                        dw         0x008d
0x234e7d3a                        dw         0x0100
0x234e7d3c                        dw         0x00cf
0x234e7d3e                        dw         0x0020
0x234e7d40 0000                   movs       r0, r0
0x234e7d42 0000                   movs       r0, r0
0x234e7d44                        dd         0x234c12ec
0x234e7d48                        dw         0x0009
0x234e7d4a 0000                   movs       r0, r0
0x234e7d4c                        dd         0x234e756c
#endif
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
	{1, 0, 0, 0/*Data_8*/, 0x0173, 0x0060, 0x004b, 0x0020, 0, &Data_234c12f8/*Data_0x18*/, 9, 0, &Data_234e75fc/*Data_0x20*/}, //[22] = 234E7DEC
#if 0
0x234e7dec                        db         0x01                               ; DATA XREF=0x234e8fc0
0x234e7ded                        db  0x00 ; '.'
0x234e7dee 0000                   movs       r0, r0
0x234e7df0                        dd         0x00000000
0x234e7df4                        dd         0x00000000
0x234e7df8                        dw         0x0173
0x234e7dfa                        dw         0x0060
0x234e7dfc                        dw         0x004b
0x234e7dfe                        dw         0x0020
0x234e7e00 0000                   movs       r0, r0
0x234e7e02 0000                   movs       r0, r0
0x234e7e04                        dd         0x234c12f8
0x234e7e08                        dw         0x0009
0x234e7e0a 0000                   movs       r0, r0
0x234e7e0c                        dd         0x234e75fc
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0173, 0x0080, 0x004b, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e7614/*Data_0x20*/}, //[23] = 234E7E2C
#if 0
0x234e7e2c                        db         0x01                               ; DATA XREF=0x234e8fec
0x234e7e2d                        db  0x00 ; '.'
0x234e7e2e 0000                   movs       r0, r0
0x234e7e30                        dd         0x00000000
0x234e7e34                        dd         0x00000000
0x234e7e38                        dw         0x0173
0x234e7e3a                        dw         0x0080
0x234e7e3c                        dw         0x004b
0x234e7e3e                        dw         0x0020
0x234e7e40 0000                   movs       r0, r0
0x234e7e42 0000                   movs       r0, r0
0x234e7e44                        dd         0x234e73e0
0x234e7e48                        dw         0x0009
0x234e7e4a 0000                   movs       r0, r0
0x234e7e4c                        dd         0x234e7614
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0173, 0x00a0, 0x004b, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e762c/*Data_0x20*/}, //[24] = 234E7E6C
#if 0
0x234e7e6c                        db         0x01                               ; DATA XREF=0x234e9018
0x234e7e6d                        db  0x00 ; '.'
0x234e7e6e 0000                   movs       r0, r0
0x234e7e70                        dd         0x00000000
0x234e7e74                        dd         0x00000000
0x234e7e78                        dw         0x0173
0x234e7e7a                        dw         0x00a0
0x234e7e7c                        dw         0x004b
0x234e7e7e                        dw         0x0020
0x234e7e80 0000                   movs       r0, r0
0x234e7e82 0000                   movs       r0, r0
0x234e7e84                        dd         0x234e73e0
0x234e7e88                        dw         0x0009
0x234e7e8a 0000                   movs       r0, r0
0x234e7e8c                        dd         0x234e762c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0173, 0x00c0, 0x004b, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e7644/*Data_0x20*/}, //[25] = 234E7EAC
#if 0
0x234e7eac                        db         0x01                               ; DATA XREF=0x234e9044
0x234e7ead                        db  0x00 ; '.'
0x234e7eae 0000                   movs       r0, r0
0x234e7eb0                        dd         0x00000000
0x234e7eb4                        dd         0x00000000
0x234e7eb8                        dw         0x0173
0x234e7eba                        dw         0x00c0
0x234e7ebc                        dw         0x004b
0x234e7ebe                        dw         0x0020
0x234e7ec0 0000                   movs       r0, r0
0x234e7ec2 0000                   movs       r0, r0
0x234e7ec4                        dd         0x234e73e0
0x234e7ec8                        dw         0x0009
0x234e7eca 0000                   movs       r0, r0
0x234e7ecc                        dd         0x234e7644
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0173, 0x00e0, 0x004b, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e765c/*Data_0x20*/}, //[26] = 234E7EEC
#if 0
0x234e7eec                        db         0x01                               ; DATA XREF=0x234e9070
0x234e7eed                        db  0x00 ; '.'
0x234e7eee 0000                   movs       r0, r0
0x234e7ef0                        dd         0x00000000
0x234e7ef4                        dd         0x00000000
0x234e7ef8                        dw         0x0173
0x234e7efa                        dw         0x00e0
0x234e7efc                        dw         0x004b
0x234e7efe                        dw         0x0020
0x234e7f00 0000                   movs       r0, r0
0x234e7f02 0000                   movs       r0, r0
0x234e7f04                        dd         0x234e73e0
0x234e7f08                        dw         0x0009
0x234e7f0a 0000                   movs       r0, r0
0x234e7f0c                        dd         0x234e765c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0173, 0x0100, 0x004b, 0x0020, 0, &Data_234c12ec/*Data_0x18*/, 9, 0, &Data_234e7674/*Data_0x20*/}, //[27] = 234E7F2C
#if 0
0x234e7f2c                        db         0x01                               ; DATA XREF=0x234e909c
0x234e7f2d                        db  0x00 ; '.'
0x234e7f2e 0000                   movs       r0, r0
0x234e7f30                        dd         0x00000000
0x234e7f34                        dd         0x00000000
0x234e7f38                        dw         0x0173
0x234e7f3a                        dw         0x0100
0x234e7f3c                        dw         0x004b
0x234e7f3e                        dw         0x0020
0x234e7f40 0000                   movs       r0, r0
0x234e7f42 0000                   movs       r0, r0
0x234e7f44                        dd         0x234c12ec
0x234e7f48                        dw         0x0009
0x234e7f4a 0000                   movs       r0, r0
0x234e7f4c                        dd         0x234e7674
#endif
	{1, 0, 0, 0/*Data_8*/, 0x01c3, 0x0060, 0x00cf, 0x0020, 0, &Data_234c12f8/*Data_0x18*/, 9, 0, &Data_234e76ec/*Data_0x20*/}, //[28] = 234E7F6C
#if 0
0x234e7f6c                        db         0x01                               ; DATA XREF=0x234e8fc4
0x234e7f6d                        db  0x00 ; '.'
0x234e7f6e 0000                   movs       r0, r0
0x234e7f70                        dd         0x00000000
0x234e7f74                        dd         0x00000000
0x234e7f78                        dw         0x01c3
0x234e7f7a                        dw         0x0060
0x234e7f7c                        dw         0x00cf
0x234e7f7e                        dw         0x0020
0x234e7f80 0000                   movs       r0, r0
0x234e7f82 0000                   movs       r0, r0
0x234e7f84                        dd         0x234c12f8
0x234e7f88                        dw         0x0009
0x234e7f8a 0000                   movs       r0, r0
0x234e7f8c                        dd         0x234e76ec
#endif
	{1, 0, 0, 0/*Data_8*/, 0x01c3, 0x0080, 0x00cf, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e7704/*Data_0x20*/}, //[29] = 234E7FAC
#if 0
0x234e7fac                        db         0x01                               ; DATA XREF=0x234e8ff0
0x234e7fad                        db  0x00 ; '.'
0x234e7fae                        db  0x00 ; '.'
0x234e7faf                        db  0x00 ; '.'
0x234e7fb0                        dd         0x00000000
0x234e7fb4                        dd         0x00000000
0x234e7fb8                        dw         0x01c3
0x234e7fba                        dw         0x0080
0x234e7fbc                        dw         0x00cf
0x234e7fbe                        dw         0x0020
0x234e7fc0 0000                   movs       r0, r0
0x234e7fc2 0000                   movs       r0, r0
0x234e7fc4                        dd         0x234e73e0
0x234e7fc8                        dw         0x0009
0x234e7fca                        db         0x00
0x234e7fcb                        db  0x00 ; '.'
0x234e7fcc                        dd         0x234e7704
#endif
	{1, 0, 0, 0/*Data_8*/, 0x01c3, 0x00a0, 0x00cf, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e771c/*Data_0x20*/}, //[30] = 234E7FEC
#if 0
0x234e7fec                        db         0x01                               ; DATA XREF=0x234e901c
0x234e7fed                        db  0x00 ; '.'
0x234e7fee                        db  0x00 ; '.'
0x234e7fef                        db  0x00 ; '.'
0x234e7ff0                        dd         0x00000000
0x234e7ff4                        dd         0x00000000
0x234e7ff8                        dw         0x01c3
0x234e7ffa                        dw         0x00a0
0x234e7ffc                        dw         0x00cf
0x234e7ffe                        dw         0x0020
0x234e8000 0000                   movs       r0, r0
0x234e8002 0000                   movs       r0, r0
0x234e8004                        dd         0x234e73e0
0x234e8008                        dw         0x0009
0x234e800a                        db         0x00
0x234e800b                        db  0x00 ; '.'
0x234e800c                        dd         0x234e771c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x01c3, 0x00c0, 0x00cf, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e7734/*Data_0x20*/}, //[31] = 234E802C
#if 0
0x234e802c                        db         0x01                               ; DATA XREF=0x234e9048
0x234e802d                        db  0x00 ; '.'
0x234e802e 0000                   movs       r0, r0
0x234e8030                        dd         0x00000000
0x234e8034                        dd         0x00000000
0x234e8038                        dw         0x01c3
0x234e803a                        dw         0x00c0
0x234e803c                        dw         0x00cf
0x234e803e                        dw         0x0020
0x234e8040 0000                   movs       r0, r0
0x234e8042 0000                   movs       r0, r0
0x234e8044                        dd         0x234e73e0
0x234e8048                        dw         0x0009
0x234e804a 0000                   movs       r0, r0
0x234e804c                        dd         0x234e7734
#endif
	{1, 0, 0, 0/*Data_8*/, 0x01c3, 0x00e0, 0x00cf, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e774c/*Data_0x20*/}, //[32] = 234E806C
#if 0
0x234e806c                        db         0x01                               ; DATA XREF=0x234e9074
0x234e806d                        db  0x00 ; '.'
0x234e806e 0000                   movs       r0, r0
0x234e8070                        dd         0x00000000
0x234e8074                        dd         0x00000000
0x234e8078                        dw         0x01c3
0x234e807a                        dw         0x00e0
0x234e807c                        dw         0x00cf
0x234e807e                        dw         0x0020
0x234e8080 0000                   movs       r0, r0
0x234e8082 0000                   movs       r0, r0
0x234e8084                        dd         0x234e73e0
0x234e8088                        dw         0x0009
0x234e808a 0000                   movs       r0, r0
0x234e808c                        dd         0x234e774c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x01c3, 0x0100, 0x00cf, 0x0020, 0, &Data_234c12ec/*Data_0x18*/, 9, 0, &Data_234e7764/*Data_0x20*/}, //[33] = 234E80AC
#if 0
0x234e80ac                        db         0x01                               ; DATA XREF=0x234e90a0
0x234e80ad                        db  0x00 ; '.'
0x234e80ae 0000                   movs       r0, r0
0x234e80b0                        dd         0x00000000
0x234e80b4                        dd         0x00000000
0x234e80b8                        dw         0x01c3
0x234e80ba                        dw         0x0100
0x234e80bc                        dw         0x00cf
0x234e80be                        dw         0x0020
0x234e80c0 0000                   movs       r0, r0
0x234e80c2 0000                   movs       r0, r0
0x234e80c4                        dd         0x234c12ec
0x234e80c8                        dw         0x0009
0x234e80ca 0000                   movs       r0, r0
0x234e80cc                        dd         0x234e7764
#endif
	{0}, //[34] = 234E80EC 
	{0}, //[35] = 234E812C 
	{1, 0, 0, 0/*Data_8*/, 0x003d, 0x0131, 0x0120, 0x0020, 0, &Data_234c1298/*Data_0x18*/, 9, 0, &Data_234e77dc/*Data_0x20*/}, //[36] = 234E816C
#if 0
0x234e816c                        db         0x01
0x234e816d                        db  0x00 ; '.'
0x234e816e 0000                   movs       r0, r0
0x234e8170                        dd         0x00000000
0x234e8174                        dd         0x00000000
0x234e8178                        dw         0x003d
0x234e817a                        dw         0x0131
0x234e817c                        dw         0x0120
0x234e817e                        dw         0x0020
0x234e8180 0000                   movs       r0, r0
0x234e8182 0000                   movs       r0, r0
0x234e8184                        dd         0x234c1298
0x234e8188                        dw         0x0009
0x234e818a 0000                   movs       r0, r0
0x234e818c                        dd         0x234e77dc
#endif
	{1, 0, 0, 0/*Data_8*/, 0x003d, 0x0151, 0x0120, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e77f4/*Data_0x20*/}, //[37] = 234E81AC
#if 0
0x234e81ac                        db         0x01
0x234e81ad                        db         0x00
0x234e81ae 0000                   movs       r0, r0
0x234e81b0                        dd         0x00000000
0x234e81b4                        dd         0x00000000
0x234e81b8                        dw         0x003d
0x234e81ba                        dw         0x0151
0x234e81bc                        dw         0x0120
0x234e81be                        dw         0x0020
0x234e81c0 0000                   movs       r0, r0
0x234e81c2 0000                   movs       r0, r0
0x234e81c4                        dd         0x234e73e0
0x234e81c8                        dw         0x0009
0x234e81ca 0000                   movs       r0, r0
0x234e81cc                        dd         0x234e77f4
#endif
	{1, 0, 0, 0/*Data_8*/, 0x003d, 0x0171, 0x0120, 0x0020, 0, &Data_234e73e0/*Data_0x18*/, 9, 0, &Data_234e780c/*Data_0x20*/}, //[38] = 234E81EC
#if 0
0x234e81ec                        db         0x01
0x234e81ed                        db  0x00 ; '.'
0x234e81ee 0000                   movs       r0, r0
0x234e81f0                        dd         0x00000000
0x234e81f4                        dd         0x00000000
0x234e81f8                        dw         0x003d
0x234e81fa                        dw         0x0171
0x234e81fc                        dw         0x0120
0x234e81fe                        dw         0x0020
0x234e8200 0000                   movs       r0, r0
0x234e8202 0000                   movs       r0, r0
0x234e8204                        dd         0x234e73e0
0x234e8208                        dw         0x0009
0x234e820a 0000                   movs       r0, r0
0x234e820c                        dd         0x234e780c
#endif
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
	{1, 0, 0, 0/*Data_8*/, 0x016d, 0x015f, 0x012c, 0x0014, 0, &Data_234e72d8/*Data_0x18*/, 2, 0, NULL/*Data_0x20*/}, //[41] = 234E82AC
#if 0
0x234e82ac                        db         0x01
0x234e82ad                        db  0x00 ; '.'
0x234e82ae 0000                   movs       r0, r0
0x234e82b0                        dd         0x00000000
0x234e82b4                        dd         0x00000000
0x234e82b8                        dw         0x016d
0x234e82ba                        dw         0x015f
0x234e82bc                        dw         0x012c
0x234e82be                        dw         0x0014
0x234e82c0                        dw         0x0000
0x234e82c2 0000                   movs       r0, r0
0x234e82c4                        dd         0x234e72d8
0x234e82c8                        dw         0x0002
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0173, 0x0165, 0x0014, 0x0008, 0, &Data_234e72e4/*Data_0x18*/, 7, 0, NULL/*Data_0x20*/}, //[42] = 234E82EC
#if 0
0x234e82ec                        db         0x01
0x234e82ed                        db  0x00 ; '.'
0x234e82ee 0000                   movs       r0, r0
0x234e82f0                        dd         0x00000000
0x234e82f4                        dd         0x00000000
0x234e82f8                        dw         0x0173
0x234e82fa                        dw         0x0165
0x234e82fc                        dw         0x0014
0x234e82fe                        dw         0x0008
0x234e8300 0000                   movs       r0, r0
0x234e8302 0000                   movs       r0, r0
0x234e8304                        dd         0x234e72e4
0x234e8308                        dw         0x0007
#endif
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
	graphic_unlock, //0x1c
	graphic_lock, //0x20
#if 0
0x234e8e6c                        db  0x00 ; '.'                                ; DATA XREF=sub_2348f56e+14, sub_2348f56e+118, sub_2348f688+18, scan_progress+16, aDd_2348fa10+334, sub_2348fc86+66, sub_2349052a+10, dword_234e7304, 0x234e7340
0x234e8e6d                        db  0xfa ; '.'
0x234e8e6e                        dw         0x000f
0x234e8e70                        db         0x04
0x234e8e71                        db  0x00 ; '.'
0x234e8e72 0000                   movs       r0, r0
0x234e8e74                        dd         0x234e786c                         ; DATA XREF=sub_2348f56e+16, sub_2348f688+20, scan_progress+18, sub_2348fc86+68, sub_2349052a+16
0x234e8e78                        dd         menu_main_graphic_color_data
0x234e8e7c                        db         0x10
0x234e8e7d                        db  0x00 ; '.'
0x234e8e7e 0000                   movs       r0, r0
0x234e8e80                        dd         0x00000000
0x234e8e84                        db         0x2c
0x234e8e85                        db         0x01
0x234e8e86 0000                   movs       r0, r0
0x234e8e88                        dd         graphic_unlock+1
0x234e8e8c                        dd         graphic_lock+1
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
			&Data_234e786c[14], //234e7bec,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234E8EE0
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
	//[1]
	{
		0x0000, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234e786c[9], //234e7aac,
			&Data_234e786c[15], //234e7c2c,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234E8F0C
#if 0
0x234e8ee0                        dw         0x0000
0x234e8ee2                        dw         0x00fc
0x234e8ee4                        dd         0x234e7aac
0x234e8ee8                        dd         0x234e7c2c
0x234e8eec 0000                   movs       r0, r0
0x234e8eee 0000                   movs       r0, r0
0x234e8ef0 0000                   movs       r0, r0
0x234e8ef2 0000                   movs       r0, r0
0x234e8ef4 0000                   movs       r0, r0
0x234e8ef6 0000                   movs       r0, r0
0x234e8ef8 0000                   movs       r0, r0
0x234e8efa 0000                   movs       r0, r0
0x234e8efc                        dd         sub_234902a6+1
0x234e8f00                        dd         sub_2344f3c6+1
#endif
    },
	//[2]
	{
		0x0000, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234e786c[10], //234e7aec,
			&Data_234e786c[16], //234e7c6c,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234E8F38
#if 0
0x234e8f0c                        dw         0x0000
0x234e8f0e                        dw         0x00fc
0x234e8f10                        dd         0x234e7aec
0x234e8f14                        dd         0x234e7c6c
0x234e8f18 0000                   movs       r0, r0
0x234e8f1a 0000                   movs       r0, r0
0x234e8f1c 0000                   movs       r0, r0
0x234e8f1e 0000                   movs       r0, r0
0x234e8f20 0000                   movs       r0, r0
0x234e8f22 0000                   movs       r0, r0
0x234e8f24 0000                   movs       r0, r0
0x234e8f26 0000                   movs       r0, r0
0x234e8f28                        dd         sub_234902a6+1
0x234e8f2c                        dd         sub_2344f3c6+1
#endif
    },
	//[3]
	{
		0x0000, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234e786c[11], //234e7b2c,
			&Data_234e786c[17], //234e7cac,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234E8F64
#if 0
0x234e8f38                        dw         0x0000
0x234e8f3a                        dw         0x00fc
0x234e8f3c                        dd         0x234e7b2c
0x234e8f40                        dd         0x234e7cac
0x234e8f44 0000                   movs       r0, r0
0x234e8f46 0000                   movs       r0, r0
0x234e8f48 0000                   movs       r0, r0
0x234e8f4a 0000                   movs       r0, r0
0x234e8f4c 0000                   movs       r0, r0
0x234e8f4e 0000                   movs       r0, r0
0x234e8f50 0000                   movs       r0, r0
0x234e8f52 0000                   movs       r0, r0
0x234e8f54                        dd         sub_234902a6+1
0x234e8f58                        dd         sub_2344f3c6+1
#endif
	},
	//[4]
	{
		0x0000, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234e786c[12], //234e7b6c,
			&Data_234e786c[18], //234e7cec,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234E8F90
#if 0
0x234e8f64                        dw         0x0000
0x234e8f66                        dw         0x00fc
0x234e8f68                        dd         0x234e7b6c
0x234e8f6c                        dd         0x234e7cec
0x234e8f70 0000                   movs       r0, r0
0x234e8f72 0000                   movs       r0, r0
0x234e8f74 0000                   movs       r0, r0
0x234e8f76 0000                   movs       r0, r0
0x234e8f78 0000                   movs       r0, r0
0x234e8f7a 0000                   movs       r0, r0
0x234e8f7c 0000                   movs       r0, r0
0x234e8f7e 0000                   movs       r0, r0
0x234e8f80                        dd         sub_234902a6+1
0x234e8f84                        dd         sub_2344f3c6+1
#endif
    },
	//[5]
	{
		0x0000, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234e786c[13], //234e7bac,
			&Data_234e786c[19], //234e7d2c,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234E8FBC
#if 0
0x234e8f90                        dw         0x0000
0x234e8f92                        dw         0x00fc
0x234e8f94                        dd         0x234e7bac
0x234e8f98                        dd         0x234e7d2c
0x234e8f9c 0000                   movs       r0, r0
0x234e8f9e 0000                   movs       r0, r0
0x234e8fa0 0000                   movs       r0, r0
0x234e8fa2 0000                   movs       r0, r0
0x234e8fa4 0000                   movs       r0, r0
0x234e8fa6 0000                   movs       r0, r0
0x234e8fa8 0000                   movs       r0, r0
0x234e8faa 0000                   movs       r0, r0
0x234e8fac                        dd         sub_234902a6+1
0x234e8fb0                        dd         sub_2344f3c6+1
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
			&Data_234e786c[28], //234e7f6c,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234E8FE8
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
	//[1]
	{
		0x0000, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234e786c[23], //234e7e2c,
			&Data_234e786c[29], //234e7fac,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234E9014
#if 0
0x234e8fe8                        dw         0x0000
0x234e8fea                        dw         0x00fc
0x234e8fec                        dd         0x234e7e2c
0x234e8ff0                        dd         0x234e7fac
0x234e8ff4 0000                   movs       r0, r0
0x234e8ff6 0000                   movs       r0, r0
0x234e8ff8 0000                   movs       r0, r0
0x234e8ffa 0000                   movs       r0, r0
0x234e8ffc 0000                   movs       r0, r0
0x234e8ffe 0000                   movs       r0, r0
0x234e9000 0000                   movs       r0, r0
0x234e9002 0000                   movs       r0, r0
0x234e9004                        dd         sub_234902a6+1
0x234e9008                        dd         sub_2344f3c6+1
#endif
    },
	//[2]
	{
		0x0000, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234e786c[24], //234e7e6c,
			&Data_234e786c[30], //234e7fec,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234E9040
#if 0
0x234e9014                        dw         0x0000
0x234e9016                        dw         0x00fc
0x234e9018                        dd         0x234e7e6c
0x234e901c                        dd         0x234e7fec
0x234e9020 0000                   movs       r0, r0
0x234e9022 0000                   movs       r0, r0
0x234e9024 0000                   movs       r0, r0
0x234e9026 0000                   movs       r0, r0
0x234e9028 0000                   movs       r0, r0
0x234e902a 0000                   movs       r0, r0
0x234e902c 0000                   movs       r0, r0
0x234e902e 0000                   movs       r0, r0
0x234e9030                        dd         sub_234902a6+1
0x234e9034                        dd         sub_2344f3c6+1
#endif
    },
	//[3]
	{
		0x0000, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234e786c[25], //234e7eac,
			&Data_234e786c[31], //234e802c,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234E906C
#if 0
0x234e9040                        dw         0x0000
0x234e9042                        dw         0x00fc
0x234e9044                        dd         0x234e7eac
0x234e9048                        dd         0x234e802c
0x234e904c 0000                   movs       r0, r0
0x234e904e 0000                   movs       r0, r0
0x234e9050 0000                   movs       r0, r0
0x234e9052 0000                   movs       r0, r0
0x234e9054 0000                   movs       r0, r0
0x234e9056 0000                   movs       r0, r0
0x234e9058 0000                   movs       r0, r0
0x234e905a 0000                   movs       r0, r0
0x234e905c                        dd         sub_234902a6+1
0x234e9060                        dd         sub_2344f3c6+1
#endif
    },
	//[4]
	{
		0x0000, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234e786c[26], //234e7eec,
			&Data_234e786c[32], //234e806c,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234E9098
#if 0
0x234e906c                        dw         0x0000
0x234e906e                        dw         0x00fc
0x234e9070                        dd         0x234e7eec
0x234e9074                        dd         0x234e806c
0x234e9078 0000                   movs       r0, r0
0x234e907a 0000                   movs       r0, r0
0x234e907c 0000                   movs       r0, r0
0x234e907e 0000                   movs       r0, r0
0x234e9080 0000                   movs       r0, r0
0x234e9082 0000                   movs       r0, r0
0x234e9084 0000                   movs       r0, r0
0x234e9086 0000                   movs       r0, r0
0x234e9088                        dd         sub_234902a6+1
0x234e908c                        dd         sub_2344f3c6+1
#endif
    },
	//[5]
	{
		0x0000, //
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234e786c[27], //234e7f2c,
			&Data_234e786c[33], //234e80ac,
		}, //int fill_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		0, //sub_23453d78, //void* onEvent; //0x1c = 28
		sub_2344f3c6, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234E90C4
#if 0
0x234e9098                        dw         0x0000
0x234e909a                        dw         0x00fc
0x234e909c                        dd         0x234e7f2c
0x234e90a0                        dd         0x234e80ac
0x234e90a4 0000                   movs       r0, r0
0x234e90a6 0000                   movs       r0, r0
0x234e90a8 0000                   movs       r0, r0
0x234e90aa 0000                   movs       r0, r0
0x234e90ac 0000                   movs       r0, r0
0x234e90ae 0000                   movs       r0, r0
0x234e90b0 0000                   movs       r0, r0
0x234e90b2 0000                   movs       r0, r0
0x234e90b4                        dd         sub_234902a6+1
0x234e90b8                        dd         sub_2344f3c6+1
#endif
    }
};

/*extern*/ uint8_t Data_234e92d4[8]; //234e92d4
/*extern*/ uint8_t Data_234e92dc[8]; //234e92dc
/*extern*/ uint8_t Data_234e92e4[8]; //234e92e4
/*extern*/ uint8_t Data_234e92ec[8]; //234e92ec
/*extern*/ uint8_t Data_234e92f4[8]; //234e92f4
/*extern*/ uint8_t Data_234e92fc[8]; //234e92fc


static uint8_t Data_2396e104[40]; //2396e104, size???
static uint8_t Data_2396e224[40]; //2396e224 +0x28 = 2396E24C

uint16_t Data_2396e24c[2000]; //2396e24c +4000 = 2396F1EC
uint16_t Data_2396f1ec[2000]; //2396F1EC +4000 = 2397018C

struct
{
    int Data_2397018c; //0x2397018c
    void* sema; //23970190 +4
    uint16_t* Data_23970194; //23970194 +8
    Struct_2348dc50* Data_23970198; //23970198
    uint16_t wData_2397019c; //2397019c
	uint16_t* Data_239701a0; //239701a0 +0x14
	Struct_2348dc50* Data_239701a4; //239701a4 +0x18
	uint16_t wData_239701a8; //239701a8 +0x1c
    uint32_t Data_239701ac; //239701ac

} Data_23970198; //???

static uint8_t Data_239701b0[40]; //239701b0
static uint8_t Data_239701d8[20]; //239701d8
static uint8_t Data_239701ec[20]; //239701ec
static uint8_t Data_23970200[20]; //23970200
static uint8_t Data_23970214[20]; //23970214
static uint8_t Data_23970228[20]; //23970228
static uint8_t Data_2397023c[20]; //2397023c
static uint8_t Data_239702a0[40]; //239702a0
static uint8_t Data_239702c8[40]; //239702c8
static uint8_t Data_239702f0[40]; //239702f0
static uint8_t Data_23970318[40]; //23970318. size???




/* /  / 2348f54e - complete */
static void graphic_unlock(void)
{
#if 0
	console_send_string("graphic_unlock (todo.c): TODO\r\n");
#endif

	OSSemPost(Data_23970198.sema);
}


/* /  / 2348f55a - complete */
static int graphic_lock(void)
{
#if 0
	console_send_string("graphic_lock (todo.c): TODO\r\n");
#endif

	uint8_t err;

	OSSemPend(Data_23970198.sema, 0, &err);

	return err;
}


/* /  / 2348f56e - todo */
void sub_2348f56e(uint16_t sp_0x14, uint16_t sp_0x18)
{
#if 0
	console_send_string("sub_2348f56e (todo.c): TODO\r\n");
#endif

	Graphic_Queue_Item sp4;
	uint32_t r7 = 10;
	Graphic_Job_2_5_Item* r5 = &Data_234e7268->graphicData->pItems[41];
	Graphic_Job_2_5_Item* r4 = &Data_234e7268->graphicData->pItems[42];

	graphic_lock();

	if (sp_0x18 == 0)
	{
		//->loc_2348f5d4
		r4->width = 20;
		//loc_2348f5d6
	}
	else
	{
		//loc_2348f596
		uint32_t r6;
		if (r4->Data_8 != NULL)
		{
			//0x2348f59c
			r6 = r5->width;
			r7 = 0;
			//->loc_2348f5a6
		}
		else
		{
			//loc_2348f5a2
			r6 = r5->width - 10;
		}
		//loc_2348f5a6
		r4->width = r6 - ((((sp_0x14 * 100) / sp_0x18) * r6) / 100);
		if (r4->width < 20)
		{
			r4->width = 20;
		}
		//loc_2348f5c8
		if (r4->width > (300 - r7))
		{
			//loc_2348f5d4
			r4->width = (300 - r7);
		}
		//loc_2348f5d6
	}
	//loc_2348f5d6
	r4->bData_0x3c = 1;
	r5->bData_0x3c = 1;

	graphic_start_job_2_5(&sp4, Data_234e7268->graphicData);

	graphic_unlock();
}


/* 23470090? /  / 2348f5f4 - todo */
void sub_2348f5f4(void* a, uint16_t r7, uint16_t* c, uint16_t* d)
{
#if 0
	console_send_string("sub_2348f5f4 (todo.c): TODO\r\n");
#endif

	Transponder transponder; //sp_0x2c
	Channel channel; //sp4

	uint16_t i;
	uint16_t* r4 = a;
	uint16_t r5 = 0;
	uint16_t r6 = 0;

	for (i = 0; i < 1999; i++)
	{
		if (Data_23970198.Data_23970194[i] == 0xffff)
		{
			r6 = i;
			break;
		}
	}

	for (i = 0; i < 1999; i++)
	{
		if (Data_23970198.Data_239701a0[i] == 0xffff) //239701a0
		{
			r5 = i;
			break;
		}
	}

	do
	{
		sub_2340c19c(r4[0], &channel, &transponder);

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_23470090: r7=%d, r6=%d, r5=%d, *r4=0x%x\r\n", 
				r7, r6, r5, r4[0]);
			console_send_string(debug_string);
		}
#endif

		if (channel.wFlags_2 & (1 << 3))
		{
			if (r6 < 2000)
			{
				Data_23970198.Data_23970194[r6++] = r4[0];
			}
		}
		else
		{
			if (r5 < 2000)
			{
				Data_23970198.Data_239701a0[r5++] = r4[0];
			}
		}

		r4++;
		r7--;
	}
	while (r7 != 0);

	*c = r6;
	*d = r5;
}


/* /  / 2348f688 - todo */
static void update_transponder_value_strings(Transponder* r4)
{
#if 0
	console_send_string("update_transponder_value_strings (todo.c): TODO\r\n");
#endif

	uint8_t* sp_0x28 = Data_234e7268->graphicData->pItems[36].Data_0x20->pString;
	Data_234e7268->graphicData->pItems[36].Data_0x20->bData_0x17 = 1;
	uint8_t* sp_0x24 = Data_234e7268->graphicData->pItems[37].Data_0x20->pString;
	Data_234e7268->graphicData->pItems[37].Data_0x20->bData_0x17 = 1;
	uint8_t* r7 = Data_234e7268->graphicData->pItems[38].Data_0x20->pString;
	Data_234e7268->graphicData->pItems[38].Data_0x20->bData_0x17 = 1;

	int r0 = fe_manager_get_transponder_type(r4);
	//r5 = 1000;
	if (r0 == 0)
	{
		//0x2348f6d2
#if 1
		console_send_string("update_transponder_value_strings (0x2348f6d2): TODO!!!\r\n");
#endif
	}
	//loc_2348f75a
	//r6, =0x2710
	else if (r0 == 2)
	{
		//0x2348f760
#if 1
		console_send_string("update_transponder_value_strings (0x2348f760): TODO!!!\r\n");
#endif
	}
	//loc_2348f812
	else if (r0 == 1)
	{
		//0x2348f816
		uint8_t sp_0x10[20]; //size???

		snprintf(&sp_0x10[0], 18, ": %c%d (%d.%dMHz)", 
			r4->Data_0.wData_0x0e >> 8,
			r4->Data_0.wData_0x0e & 0xff,
			r4->Data_0.frequency / 10000/*r6*/,
			(r4->Data_0.frequency % 10000) / 1000/*r5*/);
		text_table_get_string(0x16/*'Kanal'*/, &sp_0x28[0], 40);
		strncat(&sp_0x28[0], &sp_0x10[0], 19);

		snprintf(&sp_0x10[0], 18, ": %dkS", r4->Data_0.symbol_rate);
		text_table_get_string(0x1b/*'Symbolrate'*/, &sp_0x24[0], 20);
		strncat(&sp_0x24[0], &sp_0x10[0], 19);

		switch (r4->Data_0.Data_0.Bitfield_0.modulation)
		{
			case 0:
				strcpy(&sp_0x10[0], ": 16QAM");
				break;
			case 1:
				strcpy(&sp_0x10[0], ": 32QAM");
				break;
			case 2:
				strcpy(&sp_0x10[0], ": 64QAM");
				break;
			case 3:
				strcpy(&sp_0x10[0], ": 128QAM");
				break;
			case 4:
				strcpy(&sp_0x10[0], ": 256QAM");
				break;
			case 5:
			default:
				strcpy(&sp_0x10[0], ": ---");
				break;
		}
		text_table_get_string(0xf2/*'Modulation'*/, &r7[0], 20);
		strncat(&r7[0], &sp_0x10[0], 19);
		//loc_2348f80e
	}
	else
	{
		//loc_2348f8b2
		sprintf(&sp_0x28[0], "---");
		sprintf(&sp_0x24[0], "---");
		sprintf(&r7[0], "---");
		//->loc_2348f80e
	}
}


/* /  / 2348f8cc - todo */
static void scan_progress(void* p, int sp_0x9c, int progress_type)
{
#if 0
	console_send_string("scan_progress (todo.c): TODO\r\n");
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "scan_progress: progress_type=%d\r\n", progress_type);
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

	graphic_lock();

	//r1 = 1;
	if (progress_type == SCAN_PROGRESS_CALLBACK_TRANSPONDER)
	{
		//0x2348f8fe
		Scan_Progress_Transponder* r4 = p;
		
		r5->Data_0x20->bData_0x17 = 1; //r1

		update_transponder_value_strings(r4->pTransponder);

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
	else if (progress_type == SCAN_PROGRESS_CALLBACK_CHANNELS)
	{
		//0x2348fa1e
		Struct_2348dc50* r4;
		
		sub_2348f5f4(p, sp_0x9c, &Data_23970198.wData_2397019c, &Data_23970198.wData_239701a8);

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
		if (Data_23970198.Data_23970198->bData_0x5f == sp_0x34.bData_0x5f)
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
			r4->wData_0x20 = Data_23970198.wData_239701a8;
			r4->wData_0x1e = r4->wData_0x20 - 1;
			r4->wData_0x22 = r4->wData_0x1e % r4->wData_0x26;
			//->loc_2348fac0
		}
		else
		{
			//loc_2348fabc
			r4->wData_0x1e = 0; //r5
			r4->wData_0x22 = 0; //r5
		}
		//loc_2348fac0
		r4->wData_0x20 = Data_23970198.wData_239701a8;

		sub_2348dcd8(Data_23970198.Data_239701a4->bData_0x5f);

		if (r4->Data_0x14 != NULL)
		{
			(r4->Data_0x14)(r4);
		}
		//loc_2348fad8
		if (Data_23970198.Data_239701a4->bData_0x5f == sp_0x34.bData_0x5f)
		{
			//0x2348fae6
			r4->pMenu->Data_4 = &r4->pMenu->Data_8[r4->wData_0x22];
			//r0 = r4->pMenu->Data_4

			if (r4->Data_0x18 != NULL)
			{
				//0x2348fafe
				(r4->Data_0x18)(r4->pMenu->Data_4, 2);
			}
			//loc_2348fb02
		}
		//loc_2348fb02
		sub_2348dcd8(sp_0x34.bData_0x5f);
		//->loc_2348fb5a
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

	graphic_unlock();
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
    update_transponder_value_strings(&sp4);

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

    scan_params.pfProgress = scan_progress;
    scan_params.pfData_8 = sub_2348f56e;

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
static int sub_2348fe7a(Struct_2348dc50* p)
{
#if 0
	console_send_string("sub_2348fe7a (todo.c): TODO\r\n");
#endif

	uint8_t* sp_0xa8;
	uint8_t* sp_0xa4;
	Transponder transponder; //sp_0x8c
	Channel channel; //sp_0x64
	Struct_2348dc50 sp = *p;
	Menu_Item* pMenuItem = sp.pMenu->Data_8;
	uint16_t* ch = &((uint16_t*)(sp.Data_0x10))[sp.wData_0x1e - sp.wData_0x22];
	uint16_t r5;
	int i;
	//->loc_2348ff24
	for (i = 0; i < sp.wData_0x26; i++)
	{
		//loc_2348fea2
		sp_0xa8 = ((Graphic_Job_2_5_Item*)(pMenuItem->Data_4[0]))->Data_0x20->pString;
		sp_0xa4 = ((Graphic_Job_2_5_Item*)(pMenuItem->Data_4[1]))->Data_0x20->pString;

		((Graphic_Job_2_5_Item*)(pMenuItem->Data_4[0]))->Data_0x20->bData_0x17 = 1;
		((Graphic_Job_2_5_Item*)(pMenuItem->Data_4[1]))->Data_0x20->bData_0x17 = 1;

		uint16_t r7 = sp.wData_0x1e - sp.wData_0x22 + i;

		sub_2348dba4(pMenuItem, r7, 1);

		if (sp.wData_0x20 > r7)
		{
			//0x2348fedc
			/*sub_2340ec78*/sub_2340c19c(*ch, &channel, &transponder);

			if (sp_0xa8 != NULL)
			{
				sprintf(sp_0xa8, "%d", r7 + 1);
			}
			//loc_2348fef4
			if (sp_0xa4 != NULL)
			{
				memset(sp_0xa4, 0, 18);
				strncat(sp_0xa4, &channel.service_name[0], 15);
			}
			//loc_2348ff1c
		}
		else
		{
			//loc_2348ff0c
			sprintf(sp_0xa8, " ");
			sprintf(sp_0xa4, " ");
		}
		//loc_2348ff1c
		pMenuItem++;
		ch++;
	} //for (i = 0; i < sp.wData_0x26; i++)
	//0x2348ff2c
    return 0;
}


/* /  / 2348ff32 - todo */
int sub_2348ff32(int a)
{
#if 0
	console_send_string("sub_2348ff32 (todo.c): TODO\r\n");
#endif

	Struct_2348dc50 sp;

	Data_23970198.Data_239701a0 = &Data_2396f1ec[0]; //r4

	memset(&Data_2396f1ec[0], 0xff, 4000);

    memset(&sp, 0, sizeof(Struct_2348dc50));

    sp.Data_0x10 = &Data_2396f1ec[0]; //r4
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

    Data_23970198.Data_23970194 = &Data_2396e24c[0]; //r4

    memset(&Data_2396e24c[0], 0xff, 4000);

    memset(&sp4, 0, sizeof(Struct_2348dc50));

    Data_23970198.sema = Data_234c1258;

    sp4.Data_0x10 = &Data_2396e24c[0]; //r4
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
