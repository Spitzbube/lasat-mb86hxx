
#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "menu.h"
#include "frontend.h"
#include "fe_manager.h"
#include "osd_list.h"

#pragma thumb


#ifndef VDR110

extern void sub_2344ffae(UI_Thread_Params*);

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern void* Data_234c1258; //234c1258 +0x28
extern Graphic_Job_2_5_Item_Background Data_234c134c; //234c134c
extern uint8_t menu_channel_search_fec_string[]; //234c2fdc
extern uint8_t menu_channel_search_ber_string[]; //234c32d4
extern uint8_t menu_channel_search_cnr_string[]; //234c3314
extern uint8_t menu_channel_search_signal_level_string[]; //234c3354
extern uint8_t menu_information_item0_string[]; //239702a0
extern uint8_t menu_information_item1_string[]; //239702c8
extern uint8_t menu_information_item2_string[]; //239702f0

#define menu_information_graphic_item_text_item1_x1 0x47 //71
#define menu_information_graphic_item_text_item1_x2 0x135 //309

typedef struct
{
	int Data_0; //0
	int Data_4; //4
	uint8_t bData_8; //8
	uint8_t bData_9; //9
	uint8_t bData_0x0a; //10
	uint8_t bData_0x0b; //11
	//???
} Struct_23455910;

static void menu_information_get_transponder_string(Transponder*);
static void menu_information_get_channel_pid_strings(Channel*);
static void  sub_234556b4(int);
static int sub_23455910(Struct_23455910*);
static void* sub_23455ca8(int*);
static int menu_information_on_enter();
static void menu_information_on_exit();
static void* sub_2345611c(void*);

//234c3314
static struct
{
	int fill_0[7]; //0
	uint16_t fill_28; //28
	//30
} Data_23799a40; //23799a40 -0xb0
// /  / 23799af0
static int Data_23799af0; //23799af0 +0
static void* Data_23799af4; //23799AF4 +4
static void* Data_23799af8; //23799AF8 +8
#if 0
static Transponder Data_23799b08; //23799B08 +0x18
static uint16_t wData_23799b20; //23799B20 +0x30
static uint16_t wData_23799b22; //23799B22 +0x32
static Struct_23543df0 Data_23799b24; //23799B24 +0x34
static int Data_23799b48; //23799B48 +0x58
static int Data_23799b4c; //23799b4c +0x5c
#else
static struct
{
	Transponder transponder; //23799B08 +0x18
	uint16_t wData_23799b20; //23799B20 +0x30
	uint16_t wData_23799b22; //23799B22 +0x32
	Struct_23543df0 Data_23799b24; //23799B24 +0x34
	int Data_23799b48; //23799B48 +0x58
	int Data_23799b4c; //23799b4c +0x5c

} Data_23799b08; //23799B08 +0x18
#endif
static uint8_t Data_23799b50[100/*size???*/] = ""; //23799b50
static uint8_t Data_23799b78[100/*size???*/] = ""; //23799b78
static uint8_t Data_237999dc[100/*size???*/] = ""; //237999dc

static Menu menu_information; //234ca4d4
static Menu menu_information_ex; //234ca510

// / / 234c8664
static void (*Data_234c8664)() = NULL; //234c8664 +0
static Menu* menu_information_p = &menu_information; // /  / 234c8668 +4
static Menu* menu_information_flavor[] = //234c8670 +0x0c
{
	&menu_information,
	&menu_information_ex
};

static Graphic_Job_2_5_Item_Text menu_information_graphic_item_text_header = // /  / 234c869c
{
	0, //uint8_t bData_0; //0
	0x51, //uint16_t x1; //wData_2 = 2
	0x2c, //uint16_t y1; //wData_4 = 4
	menu_information_graphic_item_text_item1_x2, //uint16_t x2; //wData_6 = 6
	0x4f, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	6, //uint8_t bData_0xb; //11
	2, //uint8_t bData_0xc; //12
	0, //uint8_t bData_0xd; //13
	&Data_23799b50[0], //uint8_t* pString; //16 = 0x10
	0, //uint16_t wData_0x14; //20 = 0x14
	0, //uint8_t bData_0x16; //22 = 0x16
	0, //uint8_t bData_0x17; //23 = 0x17
#if 0
0x234c869c                        db         0x00                               ; DATA XREF=0x234c96c0
0x234c869d                        db  0x00 ; '.'
0x234c869e                        dw         0x0051
0x234c86a0                        dw         0x002c
0x234c86a2                        dw         0x0135
0x234c86a4                        dw         0x004f
0x234c86a6                        db         0x01
0x234c86a7                        db         0x06
0x234c86a8                        db         0x02
0x234c86a9                        db         0x00
0x234c86aa                        db         0x00
0x234c86ab                        db         0x00
0x234c86ac                        dd         0x23799b50
0x234c86b0                        dw         0x0000                             ; DATA XREF=dword_234c85c0+12
0x234c86b2                        db         0x00
0x234c86b3                        db         0x00
#endif
};

static Graphic_Job_2_5_Item_Text menu_information_graphic_item_text_item0 = //234c86b4
{
	0, //uint8_t bData_0; //0
	menu_information_graphic_item_text_item1_x1, //uint16_t x1; //wData_2 = 2
	0x64, //uint16_t y1; //wData_4 = 4
	menu_information_graphic_item_text_item1_x2, //uint16_t x2; //wData_6 = 6
	0x80, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	9, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&menu_information_item0_string[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c86b4                        db         0x00                               ; DATA XREF=sub_234552f8+34, dword_234c8b00
0x234c86b5                        db         0x00
0x234c86b6                        dw         0x0047
0x234c86b8                        dw         0x0064
0x234c86ba                        dw         0x0135
0x234c86bc                        dw         0x0080
0x234c86be                        db         0x01
0x234c86bf                        db         0x04
0x234c86c0                        db         0x09
0x234c86c1                        db         0x01
0x234c86c2                        dw         0x0000
0x234c86c4                        dd         0x239702a0                         ; DATA XREF=sub_234552f8+40
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c86cc = //234c86cc
{
	0, //uint8_t bData_0; //0
	menu_information_graphic_item_text_item1_x1, //uint16_t x1; //wData_2 = 2
	0x1c7, //uint16_t y1; //wData_4 = 4
	0x257, //uint16_t x2; //wData_6 = 6
	0x1fd, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	5, //uint8_t bData_0xb; //11
	3, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&Data_23799b78[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c86cc                        db         0x00                               ; DATA XREF=0x234c8a40
0x234c86cd                        db         0x00
0x234c86ce                        dw         0x0047
0x234c86d0                        dw         0x01c7
0x234c86d2                        dw         0x0257
0x234c86d4                        dw         0x01fd
0x234c86d6                        db         0x01
0x234c86d7                        db         0x05
0x234c86d8                        db         0x03
0x234c86d9                        db         0x01
0x234c86da 0000                   movs       r0, r0
0x234c86dc                        dd         0x23799b78
#endif
};

static Graphic_Job_2_5_Item_Text menu_information_graphic_item_text_item1 = // /  / 234c86e4
{
	0, //uint8_t bData_0; //0
	menu_information_graphic_item_text_item1_x1, //uint16_t x1; //wData_2 = 2
	0x84, //uint16_t y1; //wData_4 = 4
	menu_information_graphic_item_text_item1_x2, //uint16_t x2; //wData_6 = 6
	0xa0, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	9, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&menu_information_item1_string[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c86e4                        db         0x00                               ; DATA XREF=sub_234552f8+36, dword_234c8b40
0x234c86e5                        db  0x00 ; '.'
0x234c86e6                        dw         0x0047
0x234c86e8                        dw         0x0084
0x234c86ea                        dw         0x0135
0x234c86ec                        dw         0x00a0                             ; DATA XREF=dword_234c85fc+12
0x234c86ee                        db         0x01
0x234c86ef                        db         0x04
0x234c86f0                        db         0x09
0x234c86f1                        db         0x01
0x234c86f2                        db  0x00 ; '.'
0x234c86f3                        db  0x00 ; '.'
0x234c86f4                        dd         0x239702c8                         ; DATA XREF=sub_234552f8+42
#endif
};

static Graphic_Job_2_5_Item_Text menu_information_graphic_item_text_item2 = // /  / 234c86fc
{
	0, //uint8_t bData_0; //0
	menu_information_graphic_item_text_item1_x1, //uint16_t x1; //wData_2 = 2
	0xa4, //uint16_t y1; //wData_4 = 4
	menu_information_graphic_item_text_item1_x2, //uint16_t x2; //wData_6 = 6
	0xc0, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	9, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&menu_information_item2_string[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c86fc                        db         0x00                               ; DATA XREF=sub_234552f8+32, dword_234c8b80
0x234c86fd                        db         0x00
0x234c86fe                        dw         0x0047
0x234c8700                        dw         0x00a4
0x234c8702                        dw         0x0135
0x234c8704                        dw         0x00c0
0x234c8706                        db         0x01
0x234c8707                        db         0x04
0x234c8708                        db         0x09
0x234c8709                        db         0x01
0x234c870a 0000                   movs       r0, r0
0x234c870c                        dd         0x239702f0                         ; DATA XREF=sub_234552f8+38
#endif
};

static Graphic_Job_2_5_Item_Text menu_information_graphic_item_text_item3 = //234c8714
{
	0, //uint8_t bData_0; //0
	menu_information_graphic_item_text_item1_x1, //uint16_t x1; //wData_2 = 2
	0xd5, //uint16_t y1; //wData_4 = 4
	0x1c1, //uint16_t x2; //wData_6 = 6
	0xf1, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	9, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&menu_channel_search_signal_level_string[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c8714                        db         0x00                               ; DATA XREF=0x234c8d00
0x234c8715                        db         0x00
0x234c8716                        dw         0x0047
0x234c8718                        dw         0x00d5
0x234c871a                        dw         0x01c1
0x234c871c                        dw         0x00f1
0x234c871e                        db         0x01
0x234c871f                        db         0x04
0x234c8720                        db         0x09
0x234c8721                        db         0x01
0x234c8722 0000                   movs       r0, r0
0x234c8724                        dd         0x234c3354                         ; "Level:0 "
#endif
};

static Graphic_Job_2_5_Item_Text menu_information_graphic_item_text_item5 = //234c8744
{
	0, //uint8_t bData_0; //0
	menu_information_graphic_item_text_item1_x1, //uint16_t x1; //wData_2 = 2
	0x115, //uint16_t y1; //wData_4 = 4
	0x1c1, //uint16_t x2; //wData_6 = 6
	0x131, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	9, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&menu_channel_search_ber_string[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c8744                        db         0x00                               ; DATA XREF=0x234c8d40
0x234c8745                        db  0x00 ; '.'
0x234c8746                        dw         0x0047
0x234c8748                        dw         0x0115
0x234c874a                        dw         0x01c1
0x234c874c                        dw         0x0131
0x234c874e                        db         0x01
0x234c874f                        db         0x04
0x234c8750                        db         0x09
0x234c8751                        db         0x01
0x234c8752 0000                   movs       r0, r0
0x234c8754                        dd         0x234c32d4                         ; "BER: 0"
0x234c8758                        dd         0x00000000
#endif
};

static Graphic_Job_2_5_Item_Text menu_information_graphic_item_text_item4 = // /  / 234c872c
{
	0, //uint8_t bData_0; //0
	menu_information_graphic_item_text_item1_x1, //uint16_t x1; //wData_2 = 2
	0xf5, //uint16_t y1; //wData_4 = 4
	0x1c1, //uint16_t x2; //wData_6 = 6
	0x111, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	9, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&menu_channel_search_cnr_string[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c872c                        db         0x00                               ; DATA XREF=0x234c8cc0
0x234c872d                        db         0x00
0x234c872e                        dw         0x0047
0x234c8730                        dw         0x00f5
0x234c8732                        dw         0x01c1
0x234c8734                        dw         0x0111
0x234c8736                        db         0x01
0x234c8737                        db         0x04
0x234c8738                        db         0x09
0x234c8739                        db         0x01
0x234c873a 0000                   movs       r0, r0
0x234c873c                        dd         0x234c3314                         ; "C/N:0 "
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c875c = //234c875c
{
	0, //uint8_t bData_0; //0
	0xf0, //uint16_t x1; //wData_2 = 2
	0x115, //uint16_t y1; //wData_4 = 4
	0x12c, //uint16_t x2; //wData_6 = 6
	0x131, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	9, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&Data_237999dc[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c875c                        db         0x00
0x234c875d                        db  0x00 ; '.'
0x234c875e                        dw         0x00f0
0x234c8760                        dw         0x0115
0x234c8762                        dw         0x012c
0x234c8764                        dw         0x0131
0x234c8766                        db         0x01
0x234c8767                        db         0x04
0x234c8768                        db         0x09
0x234c8769                        db         0x01
0x234c876a                        dw         0x0000
0x234c876c                        dd         0x237999dc
0x234c8770                        dd         0x00000000
#endif
};

static Graphic_Job_2_5_Item_Text Data_234c8774 = //234c8774
{
	0, //uint8_t bData_0; //0
	0x154, //uint16_t x1; //wData_2 = 2
	0x115, //uint16_t y1; //wData_4 = 4
	0x190, //uint16_t x2; //wData_6 = 6
	0x131, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	9, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&menu_channel_search_fec_string[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c8774                        db         0x00
0x234c8775                        db         0x00
0x234c8776                        dw         0x0154
0x234c8778                        dw         0x0115
0x234c877a                        dw         0x0190
0x234c877c                        dw         0x0131
0x234c877e                        db         0x01
0x234c877f                        db         0x04
0x234c8780                        db         0x09
0x234c8781                        db         0x01
0x234c8782 0000                   movs       r0, r0
0x234c8784                        dd         0x234c2fdc                         ; "FEC"
#endif
};

static uint8_t menu_information_video_pid_string[20] = "VPid:"; //234c884c 
static Graphic_Job_2_5_Item_Text menu_information_graphic_item_text_video_pid = //234c8860
{
	0, //uint8_t bData_0; //0
	0x47, //uint16_t x1; //wData_2 = 2
	0xd5, //uint16_t y1; //wData_4 = 4
	0x135, //uint16_t x2; //wData_6 = 6
	0xf1, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	5, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&menu_information_video_pid_string[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c8860                        db         0x00                               ; DATA XREF=0x234c93c0
0x234c8861                        db         0x00
0x234c8862                        dw         0x0047
0x234c8864                        dw         0x00d5
0x234c8866                        dw         0x0135
0x234c8868                        dw         0x00f1
0x234c886a                        db         0x01
0x234c886b                        db         0x04
0x234c886c                        db         0x05
0x234c886d                        db         0x01
0x234c886e 0000                   movs       r0, r0
0x234c8870                        dd         0x234c884c                         ; "VPid:"
#endif
};

static uint8_t menu_information_audio_pid_string[20] = "APid:"; //234c8878
static Graphic_Job_2_5_Item_Text menu_information_graphic_item_text_audio_pid = //234c888c
{
	0, //uint8_t bData_0; //0
	0x47, //uint16_t x1; //wData_2 = 2
	0xf5, //uint16_t y1; //wData_4 = 4
	0x135, //uint16_t x2; //wData_6 = 6
	0x111, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	5, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&menu_information_audio_pid_string[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c888c                        db         0x00                               ; DATA XREF=0x234c9400
0x234c888d                        db  0x00 ; '.'
0x234c888e                        dw         0x0047
0x234c8890                        dw         0x00f5                             ; DATA XREF=dword_234c850c+20
0x234c8892                        dw         0x0135
0x234c8894                        dw         0x0111
0x234c8896                        db         0x01
0x234c8897                        db         0x04
0x234c8898                        db         0x05
0x234c8899                        db         0x01
0x234c889a                        db         0x00
0x234c889b                        db  0x00 ; '.'
0x234c889c                        dd         0x234c8878                         ; "APid:"
#endif
};

static uint8_t menu_information_txt_pid_string[20] = "TxtPid:"; //234c88a4
static Graphic_Job_2_5_Item_Text menu_information_graphic_item_text_txt_pid = //234c88b8
{
	0, //uint8_t bData_0; //0
	0x47, //uint16_t x1; //wData_2 = 2
	0x115, //uint16_t y1; //wData_4 = 4
	0x135, //uint16_t x2; //wData_6 = 6
	0x131, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	5, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&menu_information_txt_pid_string[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c88b8                        db         0x00                               ; DATA XREF=0x234c9440
0x234c88b9                        db         0x00
0x234c88ba                        dw         0x0047
0x234c88bc                        dw         0x0115
0x234c88be                        dw         0x0135
0x234c88c0                        dw         0x0131
0x234c88c2                        db         0x01
0x234c88c3                        db         0x04
0x234c88c4                        db         0x05
0x234c88c5                        db         0x01
0x234c88c6 0000                   movs       r0, r0
0x234c88c8                        dd         0x234c88a4                         ; "TxtPid:"
#endif
};

static uint8_t menu_information_ac3_pid_string[20] = "Ac3Pid:"; //234c88d0
static Graphic_Job_2_5_Item_Text menu_information_graphic_item_text_ac3_pid = //234c88e4
{
	0, //uint8_t bData_0; //0
	0x47, //uint16_t x1; //wData_2 = 2
	0x135, //uint16_t y1; //wData_4 = 4
	0x135, //uint16_t x2; //wData_6 = 6
	0x151, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	5, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&menu_information_ac3_pid_string[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c88e4                        db         0x00                               ; DATA XREF=0x234c9480
0x234c88e5                        db         0x00
0x234c88e6                        dw         0x0047
0x234c88e8                        dw         0x0135
0x234c88ea                        dw         0x0135
0x234c88ec                        dw         0x0151
0x234c88ee                        db         0x01
0x234c88ef                        db         0x04
0x234c88f0                        db         0x05
0x234c88f1                        db         0x01
0x234c88f2 0000                   movs       r0, r0
0x234c88f4                        dd         0x234c88d0                         ; "Ac3Pid:"
#endif
};

static uint8_t Data_234c88fc[20] = "Type:"; //234c88fc
static Graphic_Job_2_5_Item_Text Data_234c8910 = //234c8910
{
	0, //uint8_t bData_0; //0
	0x47, //uint16_t x1; //wData_2 = 2
	0x155, //uint16_t y1; //wData_4 = 4
	0x135, //uint16_t x2; //wData_6 = 6
	0x171, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	5, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&Data_234c88fc[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c8910                        db         0x00                               ; DATA XREF=0x234c94c0
0x234c8911                        db         0x00
0x234c8912                        dw         0x0047
0x234c8914                        dw         0x0155
0x234c8916                        dw         0x0135
0x234c8918                        dw         0x0171
0x234c891a                        db         0x01
0x234c891b                        db         0x04
0x234c891c                        db         0x05
0x234c891d                        db         0x01
0x234c891e 0000                   movs       r0, r0
0x234c8920                        dd         0x234c88fc                         ; "Type:"
#endif
};

static uint8_t Data_234c8928[20] = "VSize:"; //234c8928
static Graphic_Job_2_5_Item_Text Data_234c893c = //234c893c
{
	0, //uint8_t bData_0; //0
	0x47, //uint16_t x1; //wData_2 = 2
	0x175, //uint16_t y1; //wData_4 = 4
	0x135, //uint16_t x2; //wData_6 = 6
	0x191, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	5, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&Data_234c8928[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c893c                        db         0x00                               ; DATA XREF=0x234c9500
0x234c893d                        db         0x00
0x234c893e                        dw         0x0047
0x234c8940                        dw         0x0175
0x234c8942                        dw         0x0135
0x234c8944                        dw         0x0191
0x234c8946                        db         0x01
0x234c8947                        db         0x04
0x234c8948                        db         0x05
0x234c8949                        db         0x01
0x234c894a 0000                   movs       r0, r0
0x234c894c                        dd         0x234c8928                         ; "VSize:"
#endif
};

static uint8_t Data_234c8954[20] = "HSize:"; //234c8954
static Graphic_Job_2_5_Item_Text Data_234c8968 = //234c8968
{
	0, //uint8_t bData_0; //0
	0x47, //uint16_t x1; //wData_2 = 2
	0x195, //uint16_t y1; //wData_4 = 4
	0x135, //uint16_t x2; //wData_6 = 6
	0x1b1, //uint16_t y2; //wData_8 = 8
	1, //uint8_t fill_0xa; //10
	4, //uint8_t bData_0xb; //11
	5, //uint8_t bData_0xc; //12
	1, //uint8_t bData_0xd; //13
	&Data_234c8954[0], //uint8_t* pString; //16 = 0x10
#if 0
0x234c8968                        db         0x00                               ; DATA XREF=0x234c9540
0x234c8969                        db         0x00
0x234c896a                        dw         0x0047
0x234c896c                        dw         0x0195
0x234c896e                        dw         0x0135
0x234c8970                        dw         0x01b1
0x234c8972                        db         0x01
0x234c8973                        db         0x04
0x234c8974                        db         0x05
0x234c8975                        db         0x01
0x234c8976 0000                   movs       r0, r0
0x234c8978                        dd         0x234c8954                         ; "HSize:"
#endif
};

static Graphic_Job_2_5_Item Data_234c89e0[] = //234c89e0
{
	{0}, //[0] = 234c89e0 
	{1, 0, 0, 0, 0x3d, 0x1c3, 0x21a, 0x3a, 0, 
	&Data_234c134c/*Data_0x18*/, 
	3, 0, &Data_234c86cc/*Data_0x20*/}, //[1] = 234C8A20: ???
#if 0
0x234c8a20                        db         0x01                               ; DATA XREF=0x234ca4e4
0x234c8a21                        db         0x00
0x234c8a22                        db  0x00 ; '.'
0x234c8a23                        db  0x00 ; '.'
0x234c8a24                        dd         0x00000000
0x234c8a28                        dd         0x00000000
0x234c8a2c                        dw         0x003d
0x234c8a2e                        dw         0x01c3
0x234c8a30                        dw         0x021a
0x234c8a32                        dw         0x003a
0x234c8a34                        dd         0x00000000
0x234c8a38                        dd         0x234c134c
0x234c8a3c                        db         0x03
0x234c8a3d                        db         0x00
0x234c8a3e 0000                   movs       r0, r0
0x234c8a40                        dd         0x234c86cc
#endif
	{1, 0, 0, 0, 0x37, 0x5a, 0x104, 0x6c, 0, 
	&menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
	2}, //[2] = 234C8A60: Item 1 Top Border ???
#if 0
0x234c8a60                        db         0x01
0x234c8a61                        db  0x00 ; '.'
0x234c8a62 0000                   movs       r0, r0
0x234c8a64                        dd         0x00000000
0x234c8a68                        dd         0x00000000
0x234c8a6c                        dw         0x0037
0x234c8a6e                        dw         0x005a
0x234c8a70                        dw         0x0104
0x234c8a72                        dw         0x006c
0x234c8a74                        dd         0x00000000
0x234c8a78                        dd         0x234c128c
0x234c8a7c                        db         0x02
#endif
	{1, 0, 0, 0, 0x37, 0x23, 0x104, 0x32, 0, 
	&menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
	2}, //[3] = 234C8AA0: Header Item Top Border???
#if 0
0x234c8aa0                        db         0x01
0x234c8aa1                        db         0x00
0x234c8aa2 0000                   movs       r0, r0
0x234c8aa4                        dd         0x00000000
0x234c8aa8                        dd         0x00000000
0x234c8aac                        dw         0x0037
0x234c8aae                        dw         0x0023
0x234c8ab0                        dw         0x0104
0x234c8ab2                        dw         0x0032
0x234c8ab4                        dd         0x00000000
0x234c8ab8                        dd         0x234c128c
0x234c8abc                        db         0x02
#endif
	{1, 0, 0, 0, 0x3d, 0x60, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_top_round_left_right/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_item0/*Data_0x20*/}, //[4] = 234C8AE0: Text Item 0 (Frequency?)
#if 0
0x234c8ae0                        db         0x01                               ; DATA XREF=sub_234552f8+22
0x234c8ae1                        db         0x00
0x234c8ae2 0000                   movs       r0, r0
0x234c8ae4                        dd         0x00000000
0x234c8ae8                        dd         0x00000000
0x234c8aec                        dw         0x003d
0x234c8aee                        dw         0x0060
0x234c8af0                        dw         0x00f8
0x234c8af2                        dw         0x0020
0x234c8af4                        dd         0x00000000
0x234c8af8                        dd         0x234c12f8
0x234c8afc                        db         0x09
0x234c8afd                        db  0x00 ; '.'
0x234c8afe 0000                   movs       r0, r0
0x234c8b00                        dd         0x234c86b4                   ; DATA XREF=sub_234552f8+34
#endif
	{1, 0, 0, 0, 0x3d, 0x80, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_item1/*Data_0x20*/}, //[5] = 234C8B20: Text Item 1 (Symbolrate?)
#if 0
0x234c8b20                        db         0x01                               ; DATA XREF=sub_234552f8+30
0x234c8b21                        db         0x00
0x234c8b22 0000                   movs       r0, r0
0x234c8b24                        dd         0x00000000
0x234c8b28                        dd         0x00000000
0x234c8b2c                        dw         0x003d
0x234c8b2e                        dw         0x0080
0x234c8b30                        dw         0x00f8
0x234c8b32                        dw         0x0020
0x234c8b34                        dd         0x00000000
0x234c8b38                        dd         0x234c12e0
0x234c8b3c                        db         0x09
0x234c8b3d                        db  0x00 ; '.'
0x234c8b3e 0000                   movs       r0, r0
0x234c8b40                        dd         0x234c86e4                         ; DATA XREF=sub_234552f8+36
#endif
	{1, 0, 0, 0, 0x3d, 0xa0, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_bottom_round_left_right/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_item2/*Data_0x20*/}, //[6] = 234C8B60: Text Item 2 (Polarisation?)
#if 0
0x234c8b60                        db         0x01                               ; DATA XREF=sub_234552f8+26
0x234c8b61                        db  0x00 ; '.'
0x234c8b62 0000                   movs       r0, r0
0x234c8b64                        dd         0x00000000
0x234c8b68                        dd         0x00000000
0x234c8b6c                        dw         0x003d
0x234c8b6e                        dw         0x00a0
0x234c8b70                        dw         0x00f8
0x234c8b72                        dw         0x0020
0x234c8b74                        dd         0x00000000
0x234c8b78                        dd         0x234c12ec
0x234c8b7c                        db         0x09
0x234c8b7d                        db  0x00 ; '.'
0x234c8b7e 0000                   movs       r0, r0
0x234c8b80                        dd         0x234c86fc                         ; DATA XREF=sub_234552f8+32
#endif
	{1, 0, 0, 0, 0x37, 0xcb, 0x190, 0xe2, 0, 
	&Data_234c134c/*Data_0x18*/}, //[7] = 234C8BA0: ???
#if 0
0x234c8ba0                        db         0x01
0x234c8ba1                        db         0x00
0x234c8ba2 0000                   movs       r0, r0
0x234c8ba4                        dd         0x00000000
0x234c8ba8                        dd         0x00000000
0x234c8bac                        dw         0x0037
0x234c8bae                        dw         0x00cb
0x234c8bb0                        dw         0x0190
0x234c8bb2                        dw         0x00e2
0x234c8bb4 0000                   movs       r0, r0
0x234c8bb6 0000                   movs       r0, r0
0x234c8bb8                        dd         0x234c134c
#endif
	{0}, //[8] = 234C8BE0 
	{0}, //[9] = 234C8C20 
	{1, 0, 0, 0, 0x37, 0xcb, 0x190, 0x6c, 0, 
	&menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
	2}, //[10] = 234C8C60: ???
#if 0
0x234c8c60                        db         0x01
0x234c8c61                        db         0x00
0x234c8c62 0000                   movs       r0, r0
0x234c8c64                        dd         0x00000000
0x234c8c68                        dd         0x00000000
0x234c8c6c                        dw         0x0037
0x234c8c6e                        dw         0x00cb
0x234c8c70                        dw         0x0190
0x234c8c72                        dw         0x006c
0x234c8c74                        dd         0x00000000
0x234c8c78                        dd         0x234c128c
0x234c8c7c                        db         0x02
0x234c8c7d                        db  0x00 ; '.'
0x234c8c7e 0000                   movs       r0, r0
0x234c8c80                        dd         0x00000000
0x234c8c84                        dd         0x00000000
0x234c8c88                        dd         0x00000000
0x234c8c8c                        dd         0x00000000
0x234c8c90                        dd         0x00000000
0x234c8c94                        dd         0x00000000
0x234c8c98                        dd         0x00000000
0x234c8c9c                        dd         0x00000000
#endif
	{1, 0, 0, 0, 0x3d, 0xf1, 0x184, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_item4/*Data_0x20*/}, //[11] = 234C8CA0: Text Item 4 (C/N?)
#if 0
0x234c8ca0                        db         0x01
0x234c8ca1                        db         0x00
0x234c8ca2 0000                   movs       r0, r0
0x234c8ca4                        dd         0x00000000
0x234c8ca8                        dd         0x00000000
0x234c8cac                        dw         0x003d
0x234c8cae                        dw         0x00f1
0x234c8cb0                        dw         0x0184
0x234c8cb2                        dw         0x0020
0x234c8cb4                        dd         0x00000000
0x234c8cb8                        dd         0x234c12e0
0x234c8cbc                        db         0x09
0x234c8cbd                        db  0x00 ; '.'
0x234c8cbe 0000                   movs       r0, r0
0x234c8cc0                        dd         0x234c872c
#endif 
	{1, 0, 0, 0, 0x3d, 0xd1, 0x184, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_top_round_left_right/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_item3/*Data_0x20*/}, //[12] = 234C8CE0: Text Item 3 (Level: ?)
#if 0
0x234c8ce0                        db         0x01
0x234c8ce1                        db         0x00
0x234c8ce2 0000                   movs       r0, r0
0x234c8ce4                        dd         0x00000000
0x234c8ce8                        dd         0x00000000
0x234c8cec                        dw         0x003d
0x234c8cee                        dw         0x00d1
0x234c8cf0                        dw         0x0184
0x234c8cf2                        dw         0x0020
0x234c8cf4                        dd         0x00000000
0x234c8cf8                        dd         0x234c12f8
0x234c8cfc                        db         0x09
0x234c8cfd                        db  0x00 ; '.'
0x234c8cfe 0000                   movs       r0, r0
0x234c8d00                        dd         0x234c8714
0x234c8d04                        dd         0x00000000
0x234c8d08                        dd         0x00000000
0x234c8d0c                        dd         0x00000000
0x234c8d10                        dd         0x00000000
0x234c8d14                        dd         0x00000000
0x234c8d18                        dd         0x00000000
0x234c8d1c                        dd         0x00000000
#endif
	{1, 0, 0, 0, 0x3d, 0x111, 0x184, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_bottom_round_left_right/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_item5/*Data_0x20*/}, //[13] = 234C8D20: Text Item 5 (BER: ?)
#if 0
0x234c8d20                        db         0x01
0x234c8d21                        db         0x00
0x234c8d22                        db  0x00 ; '.'
0x234c8d23                        db  0x00 ; '.'
0x234c8d24                        dd         0x00000000
0x234c8d28                        dd         0x00000000
0x234c8d2c                        dw         0x003d
0x234c8d2e                        dw         0x0111
0x234c8d30                        dw         0x0184
0x234c8d32                        dw         0x0020
0x234c8d34 0000                   movs       r0, r0
0x234c8d36 0000                   movs       r0, r0
0x234c8d38                        dd         0x234c12ec
0x234c8d3c                        db         0x09
0x234c8d3d                        db  0x00 ; '.'
0x234c8d3e 0000                   movs       r0, r0
0x234c8d40                        dd         0x234c8744
#endif
	{0}, //[14] = 234C8D60:
#if 0
#endif 
	{0}, //[15] = 234C8DA0 
	{0}, //[16] = 234C8DE0 
	{0}, //[17] = 234C8E20 
	{1, 0, 0, 0, 0xd3, 0x115, 0x18, 0x18, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	11}, //[18] = 234C8E60: ???
#if 0
0x234c8e60                        db         0x01
0x234c8e61                        db         0x00
0x234c8e62                        dw         0x0000
0x234c8e64                        dd         0x00000000
0x234c8e68                        dd         0x00000000
0x234c8e6c                        dw         0x00d3
0x234c8e6e                        dw         0x0115
0x234c8e70                        dw         0x0018
0x234c8e72                        dw         0x0018
0x234c8e74 0000                   movs       r0, r0
0x234c8e76 0000                   movs       r0, r0
0x234c8e78                        dd         0x234c12e0
0x234c8e7c                        db         0x0b
0x234c8e7d                        db  0x00 ; '.'
0x234c8e7e 0000                   movs       r0, r0
#endif
	{1, 0, 0, 0, 0xf0, 0x111, 0x41, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &Data_234c875c/*Data_0x20*/}, //[19] = 234C8EA0:
#if 0
0x234c8ea0                        db         0x01
0x234c8ea1                        db         0x00
0x234c8ea2                        dw         0x0000
0x234c8ea4                        dd         0x00000000
0x234c8ea8                        dd         0x00000000
0x234c8eac                        dw         0x00f0
0x234c8eae                        dw         0x0111
0x234c8eb0                        dw         0x0041
0x234c8eb2                        dw         0x0020
0x234c8eb4                        dd         0x00000000
0x234c8eb8                        dd         0x234c12e0
0x234c8ebc                        db         0x09
0x234c8ebd                        db  0x00 ; '.'
0x234c8ebe 0000                   movs       r0, r0
0x234c8ec0                        dd         0x234c875c
#endif
	{0, 0, 0, 0, 0x137, 0x115, 0x18, 0x18, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	11}, //[20] = 234C8EE0: ???
#if 0
0x234c8ee0                        db         0x01
0x234c8ee1                        db  0x00 ; '.'
0x234c8ee2 0000                   movs       r0, r0
0x234c8ee4                        dd         0x00000000
0x234c8ee8                        dd         0x00000000
0x234c8eec                        dw         0x0137
0x234c8eee                        dw         0x0115
0x234c8ef0                        dw         0x0018
0x234c8ef2                        dw         0x0018
0x234c8ef4                        dd         0x00000000
0x234c8ef8                        dd         0x234c12e0
0x234c8efc                        db         0x0b
0x234c8efd                        db  0x00 ; '.'
0x234c8efe 0000                   movs       r0, r0
0x234c8f00                        dd         0x00000000
0x234c8f04                        dd         0x00000000
0x234c8f08                        dd         0x00000000
0x234c8f0c                        dd         0x00000000
0x234c8f10                        dd         0x00000000
0x234c8f14                        dd         0x00000000
0x234c8f18                        dd         0x00000000
0x234c8f1c                        dd         0x00000000
#endif
	{0}, //[21] = 234C8F20
	{0}, //[22] = 234C8F60 
	{0}, //[23] = 234C8FA0 
	{0}, //[24] = 234C8FE0 
	{0}, //[25] = 234C9020 
	{0}, //[26] = 234C9060 
	{0}, //[27] = 234C90A0 
	{0}, //[28] = 234C90E0 
	{0}, //[29] = 234C9120 
	{0}, //[30] = 234C9160 
	{0}, //[31] = 234C91A0 
	{0}, //[32] = 234C91E0 
	{0}, //[33] = 234C9220 
	{0}, //[34] = 234C9260 
	{0}, //[35] = 234C92A0 
	{0}, //[36] = 234C92E0 
	{0}, //[37] = 234C9320 
	{0, 0, 0, 0, 0x37, 0xcb, 0x104, 0xec, 0, 
	&menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
	2}, //[38] = 234C9360: Streams Pid Top Border
#if 0
0x234c9360                        db         0x00
0x234c9361                        db         0x00
0x234c9362                        dw         0x0000
0x234c9364                        dd         0x00000000
0x234c9368                        dd         0x00000000
0x234c936c                        dw         0x0037
0x234c936e                        dw         0x00cb
0x234c9370                        dw         0x0104
0x234c9372                        dw         0x00ec
0x234c9374                        dd         0x00000000
0x234c9378                        dd         0x234c128c
0x234c937c                        db         0x02
0x234c937d                        db  0x00 ; '.'
0x234c937e 0000                   movs       r0, r0
0x234c9380 0000                   movs       r0, r0
0x234c9382 0000                   movs       r0, r0
0x234c9384                        dd         0x00000000
0x234c9388                        dd         0x00000000
0x234c938c                        dd         0x00000000
0x234c9390                        dd         0x00000000
0x234c9394                        dd         0x00000000
0x234c9398                        dd         0x00000000
0x234c939c                        dd         0x00000000
#endif 
	{0, 0, 0, 0, 0x3d, 0xd1, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_top_round_left_right/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_video_pid/*Data_0x20*/}, //[39] = 234C93A0: "Video Pid"
#if 0
0x234c93a0                        db         0x00
0x234c93a1                        db  0x00 ; '.'
0x234c93a2 0000                   movs       r0, r0
0x234c93a4                        dd         0x00000000
0x234c93a8                        dd         0x00000000
0x234c93ac                        dw         0x003d
0x234c93ae                        dw         0x00d1
0x234c93b0                        dw         0x00f8
0x234c93b2                        dw         0x0020
0x234c93b4                        dd         0x00000000
0x234c93b8                        dd         0x234c12f8
0x234c93bc 0900                   movs       r1, r1
0x234c93be 0000                   movs       r0, r0
0x234c93c0                        dd         0x234c8860
#endif 
	{0, 0, 0, 0, 0x3d, 0xf1, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_audio_pid/*Data_0x20*/}, //[40] = 234C93E0: "Audio Pid"
#if 0
0x234c93e0                        db         0x00
0x234c93e1                        db  0x00 ; '.'
0x234c93e2                        dw         0x0000
0x234c93e4                        dd         0x00000000
0x234c93e8                        dd         0x00000000
0x234c93ec                        dw         0x003d
0x234c93ee                        dw         0x00f1
0x234c93f0                        dw         0x00f8
0x234c93f2                        dw         0x0020
0x234c93f4                        dd         0x00000000
0x234c93f8                        dd         0x234c12e0
0x234c93fc                        db         0x09
0x234c93fd                        db  0x00 ; '.'
0x234c93fe 0000                   movs       r0, r0
0x234c9400                        dd         0x234c888c
#endif
	{0, 0, 0, 0, 0x3d, 0x111, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_txt_pid/*Data_0x20*/}, //[41] = 234C9420: "Txt Pid"
#if 0
0x234c9420                        db         0x00
0x234c9421                        db  0x00 ; '.'
0x234c9422 0000                   movs       r0, r0
0x234c9424                        dd         0x00000000
0x234c9428                        dd         0x00000000
0x234c942c                        dw         0x003d
0x234c942e                        dw         0x0111
0x234c9430                        dw         0x00f8
0x234c9432                        dw         0x0020
0x234c9434                        dd         0x00000000
0x234c9438                        dd         0x234c12e0
0x234c943c                        db         0x09
0x234c943d                        db  0x00 ; '.'
0x234c943e 0000                   movs       r0, r0
0x234c9440                        dd         0x234c88b8
#endif 
	{0, 0, 0, 0, 0x3d, 0x131, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_ac3_pid/*Data_0x20*/}, //[42] = 234C9460: "AC3 Pid"
#if 0
0x234c9460                        db         0x00
0x234c9461                        db  0x00 ; '.'
0x234c9462 0000                   movs       r0, r0
0x234c9464                        dd         0x00000000
0x234c9468                        dd         0x00000000
0x234c946c                        dw         0x003d
0x234c946e                        dw         0x0131
0x234c9470                        dw         0x00f8
0x234c9472                        dw         0x0020
0x234c9474                        dd         0x00000000
0x234c9478                        dd         0x234c12e0
0x234c947c                        db         0x09
0x234c947d                        db  0x00 ; '.'
0x234c947e 0000                   movs       r0, r0
0x234c9480                        dd         0x234c88e4
#endif
	{0, 0, 0, 0, 0x3d, 0x151, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &Data_234c8910/*Data_0x20*/}, //[43] = 234C94A0: ???
#if 0
0x234c94a0                        db         0x00
0x234c94a1                        db  0x00 ; '.'
0x234c94a2 0000                   movs       r0, r0
0x234c94a4                        dd         0x00000000
0x234c94a8                        dd         0x00000000
0x234c94ac                        dw         0x003d
0x234c94ae                        dw         0x0151
0x234c94b0                        dw         0x00f8
0x234c94b2                        dw         0x0020
0x234c94b4                        dd         0x00000000
0x234c94b8                        dd         0x234c12e0
0x234c94bc                        db         0x09
0x234c94bd                        db  0x00 ; '.'
0x234c94be 0000                   movs       r0, r0
0x234c94c0                        dd         0x234c8910
#endif
	{0, 0, 0, 0, 0x3d, 0x171, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &Data_234c893c/*Data_0x20*/}, //[44] = 234C94E0: ???
#if 0
0x234c94e0                        db         0x00
0x234c94e1                        db  0x00 ; '.'
0x234c94e2 0000                   movs       r0, r0
0x234c94e4                        dd         0x00000000
0x234c94e8                        dd         0x00000000
0x234c94ec                        dw         0x003d
0x234c94ee                        dw         0x0171
0x234c94f0                        dw         0x00f8
0x234c94f2                        dw         0x0020
0x234c94f4                        dd         0x00000000
0x234c94f8                        dd         0x234c12e0
0x234c94fc                        db         0x09
0x234c94fd                        db  0x00 ; '.'
0x234c94fe 0000                   movs       r0, r0
0x234c9500                        dd         0x234c893c
#endif
	{0, 0, 0, 0, 0x3d, 0x191, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_bottom_round_left_right/*Data_0x18*/, 
	9, 0, &Data_234c8968/*Data_0x20*/}, //[45] = 234C9520
#if 0
0x234c9520                        db         0x00
0x234c9521                        db         0x00
0x234c9522 0000                   movs       r0, r0
0x234c9524                        dd         0x00000000
0x234c9528                        dd         0x00000000
0x234c952c                        dw         0x003d
0x234c952e                        dw         0x0191
0x234c9530                        dw         0x00f8
0x234c9532                        dw         0x0020
0x234c9534                        dd         0x00000000
0x234c9538                        dd         0x234c12ec
0x234c953c                        db         0x09
0x234c953d                        db  0x00 ; '.'
0x234c953e 0000                   movs       r0, r0
0x234c9540                        dd         0x234c8968
#endif 
	{0, 0, 0, 0, 0x37, 0xcb, 0x104, 0x8c, 0, 
	&menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
	2}, //[46] = 234C9560: Streams Pid Bottom Border
#if 0
0x234c9560                        db         0x00
0x234c9561                        db  0x00 ; '.'
0x234c9562 0000                   movs       r0, r0
0x234c9564                        dd         0x00000000
0x234c9568                        dd         0x00000000
0x234c956c                        dw         0x0037
0x234c956e                        dw         0x00cb
0x234c9570                        dw         0x0104
0x234c9572                        dw         0x008c
0x234c9574 0000                   movs       r0, r0
0x234c9576 0000                   movs       r0, r0
0x234c9578                        dd         0x234c128c
0x234c957c                        db         0x02
0x234c957d                        db  0x00 ; '.'
#endif
	{0}, //[47] = 234C95A0 
	{0}, //[48] = 234C95E0 
	{0}, //[49] = 234C9620 
	{0}, //[50] = 234C9660 
	{1, 0, 0, 0, 0x3d, 0x29, 0xf8, 0x26, 0, &Data_234c134c/*Data_0x18*/, 2, 0, &menu_information_graphic_item_text_header/*Data_0x20*/}, //[51] = 234C96A0: header
#if 0
0x234c96a0                        db         0x01                               ; DATA XREF=0x234ca4e0
0x234c96a1                        db         0x00
0x234c96a2                        dw         0x0000
0x234c96a4                        dd         0x00000000
0x234c96a8                        dd         0x00000000
0x234c96ac                        dw         0x003d
0x234c96ae                        dw         0x0029
0x234c96b0                        dw         0x00f8
0x234c96b2                        dw         0x0026
0x234c96b4                        dd         0x00000000
0x234c96b8                        dd         0x234c134c
0x234c96bc                        dw         0x0002
0x234c96be                        dw         0x0000
0x234c96c0                        dd         0x234c869c
0x234c96c4                        dd         0x00000000
0x234c96c8                        dd         0x00000000
0x234c96cc                        dd         0x00000000
0x234c96d0                        dd         0x00000000
0x234c96d4                        dd         0x00000000
0x234c96d8                        dd         0x00000000
0x234c96dc                        dd         0x00000000
#endif 
	{0}, //[52] = 234C96E0 
	//->234C9720
};

static Graphic_Job_2_5_Item menu_information_graphic_items_ex[] = //234C9720
{
	{0}, //[0] = 234C9720 
	{0}, //[1] = 234c9760 
	{0}, //[2] = 234C96E0 
	{0}, //[3] = 234C96E0 
	{0}, //[4] = 234C96E0 
	{0}, //[5] = 234C96E0 
	{0}, //[6] = 234C96E0 
	{0}, //[7] = 234C96E0 
	{0}, //[8] = 234C96E0 
	{0}, //[9] = 234C96E0 
	{0}, //[10] = 234C96E0 
	{0}, //[11] = 234C96E0 
	{0}, //[12] = 234C96E0 
	{0}, //[13] = 234C96E0 
	{0}, //[14] = 234C96E0 
	{0}, //[15] = 234C96E0 
	{0}, //[16] = 234C96E0 
	{0}, //[17] = 234C96E0 
	{0}, //[18] = 234C96E0 
	{0}, //[19] = 234C96E0 
	{0}, //[20] = 234C96E0 
	{0}, //[21] = 234C96E0 
	{0}, //[22] = 234C96E0 
	{0}, //[23] = 234C96E0 
	{0}, //[24] = 234C96E0 
	{0}, //[25] = 234C96E0 
	{0}, //[26] = 234C96E0 
	{0}, //[27] = 234C96E0 
	{0}, //[28] = 234C96E0 
	{0}, //[29] = 234C96E0 
	{0}, //[30] = 234C96E0 
	{0}, //[31] = 234C96E0 
	{0}, //[32] = 234C96E0 
	{0}, //[33] = 234C96E0 
	{0}, //[34] = 234C96E0 
	{0}, //[35] = 234C96E0 
	{0}, //[36] = 234C96E0 
	{0}, //[37] = 234C96E0 
	{0}, //[38] = 234C96E0 
	{0}, //[39] = 234C96E0 
	{0}, //[40] = 234C96E0 
	{0}, //[41] = 234C96E0 
	{0}, //[42] = 234C96E0 
	{0}, //[43] = 234C96E0 
	{0}, //[44] = 234C96E0 
	{0}, //[45] = 234C96E0 
	{0}, //[46] = 234C96E0 
	{0}, //[47] = 234C96E0 
	{0}, //[48] = 234C96E0 
	{0}, //[49] = 234C96E0 
	{0}, //[50] = 234C96E0 
	{0}, //[51] = 234C96E0 
	{0}, //[52] = 234C96E0 
	//->234CA460
};

static Graphic_Job_2_5 menu_information_graphic_data = //234ca460
{
	0x00, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x11, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234c89e0[0], //234c89e0 Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* pColorData; //12
	16, //uint8_t numColors; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	53, //0x35, //uint8_t bNumItems; //0x18 = 24
	1, //uint8_t bData_0x19; //0x19 = 25
	0, //sub_23456110, //void (*unlock)(); //0x1c
	0, //sub_23456086, //void (*lock)(); //0x20
#if 0
0x234ca460                        db  0x00 ; '.'                                ; DATA XREF=sub_234552f8+10, sub_23455544+20, sub_234556b4+16, sub_23455910+10, sub_2345611c+8, dword_234ca4e8
0x234ca461                        db  0xfa ; '.'
0x234ca462                        dw         0x0011
0x234ca464                        db         0x04
0x234ca465                        db  0x00 ; '.'
0x234ca466 0000                   movs       r0, r0
0x234ca468                        dd         0x234c89e0                         ; DATA XREF=sub_234552f8+18, sub_23455544+24, sub_234556b4+22, sub_234556b4+32, sub_234556b4+40, sub_234556b4+46
0x234ca46c                        dd         0x234c123c
0x234ca470                        db         0x10
0x234ca471                        db  0x00 ; '.'
0x234ca472 0000                   movs       r0, r0
0x234ca474                        dd         0x00000000
0x234ca478                        db         0x35
0x234ca479                        db         0x01
0x234ca47a 0000                   movs       r0, r0
0x234ca47c                        dd         0x23456111
0x234ca480                        dd         0x23456087
#endif
};

static Graphic_Job_2_5 menu_information_graphic_data_ex = //234ca484
{
	0x00, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x11, //uint16_t wData_2; //2
	0x0c, //uint8_t bData_4; //4
	&menu_information_graphic_items_ex[0], //234c9720 Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* pColorData; //12
	16, //uint8_t numColors; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	53, //0x35, //uint8_t bNumItems; //0x18 = 24
	1, //uint8_t bData_0x19; //0x19 = 25
	0, //sub_23456110, //void (*unlock)(); //0x1c
	0, //sub_23456086, //void (*lock)(); //0x20
#if 0
0x234ca484                        db         0x00                               ; DATA XREF=0x234ca524
0x234ca485                        db         0xfa
0x234ca486                        dw         0x0011
0x234ca488                        db         0x0c
0x234ca489                        db  0x00 ; '.'
0x234ca48a                        dw         0x0000
0x234ca48c                        dd         0x234c9720
0x234ca490                        dd         menu_main_graphic_color_data
0x234ca494                        db         0x10
0x234ca495                        db  0x00 ; '.'
0x234ca496 0000                   movs       r0, r0
0x234ca498                        dd         0x00000000
0x234ca49c                        db         0x35
0x234ca49d                        db         0x01
0x234ca49e 0000                   movs       r0, r0
0x234ca4a0                        dd         0x23456111
0x234ca4a4                        dd         0x23456087
#endif
};

static Menu_Item menu_information_items[] = //234ca4a8
{
	{
		0xffff, //uint16_t wData_0; //0
		0x00f8, //uint16_t helpStringId; //2
		{0}, //Graphic_Job_2_5_Item* Data_4[5]; //4
		0, //void (*initValueString)(struct Menu_Item*); //0x18 = 24
		sub_23455ca8, //void* onEvent; //0x1c = 28
		sub_2344ffae, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
	}
#if 0
0x234ca4a8                        dw         0xffff                             ; DATA XREF=0x234ca4d8, 0x234ca4dc
0x234ca4aa                        dw         0x00f8
0x234ca4ac                        dd         0x00000000
0x234ca4b0                        dd         0x00000000
0x234ca4b4                        dd         0x00000000
0x234ca4b8                        dd         0x00000000
0x234ca4bc                        dd         0x00000000
0x234ca4c0                        dd         0x00000000
0x234ca4c4                        dd         0x23455ca9
0x234ca4c8                        dd         0x2344ffaf
0x234ca4cc                        dd         0x00000000
0x234ca4d0                        dd         0x00000000
#endif
};

//TODO: items!!!
static Menu menu_information = //234ca4d4
{
    63, //"information"
    &menu_information_items[0], //234ca4a8, Menu_Item* Data_4; //4
    &menu_information_items[0], //234ca4a8, Menu_Item* Data_8; //8
    &Data_234c89e0[51], //234c96a0 Graphic_Job_2_5_Item* header; //12 = 0xc
    &Data_234c89e0[1], //234c8a20 Graphic_Job_2_5_Item* help; //16 = 0x10
    &menu_information_graphic_data, //234ca460 Graphic_Job_2_5* graphicData; //20 = 0x14
    0, //uint8_t maxItem; //0x18 = 24
    0, //int8_t currentItem; //0x19
    graphic_start_job_2_5, //void (*Data_0x1c)(); //0x1c
    sub_2348de88, //int (*onNavigate)(int*); //0x20
    menu_information_on_enter, //int (*onEnter)(int); //36 = 0x24
    menu_information_on_exit, //int (*onExit)(UI_Thread_Params*); //0x28
    0, //int Data_0x2c; //44 = 0x2c
    0, //int timeout; //48
    0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
	sub_2345611c, //void* (*Data_0x38)(struct FrontDisplay_Job*); //56

#if 0
0x234ca4d4                        dw         0x003f                             ; DATA XREF=sub_234552f8+8, sub_23455544+14, sub_234556b4+8, sub_23455910+8, sub_2345611c+6, menu_information_entry+6, menu_information_entry+12, menu_information_entry+18, dword_234c8668
0x234ca4d6                        dw         0x0000
0x234ca4d8                        dd         0x234ca4a8
0x234ca4dc                        dd         0x234ca4a8
0x234ca4e0                        dd         0x234c96a0
0x234ca4e4                        dd         0x234c8a20
0x234ca4e8                        dd         0x234ca460                         ; DATA XREF=sub_234552f8+10, sub_23455544+20, sub_234556b4+16, sub_23455910+10, sub_2345611c+8
0x234ca4ec 0000                   movs       r0, r0
0x234ca4ee 0000                   movs       r0, r0
0x234ca4f0                        dd         graphic_start_job_2_5
0x234ca4f4                        dd         0x2348de89
0x234ca4f8                        dd         0x23455d45
0x234ca4fc                        dd         0x23456065
0x234ca500 0000                   movs       r0, r0
0x234ca502 0000                   movs       r0, r0
0x234ca504 0000                   movs       r0, r0
0x234ca506 0000                   movs       r0, r0
0x234ca508 0000                   movs       r0, r0
0x234ca50a 0000                   movs       r0, r0
0x234ca50c                        dd         sub_2345611c+1
#endif
};

//TODO: items!!!
static Menu menu_information_ex = //234ca510
{
    63, //"information"
    &menu_information_items[0], //234ca4a8, Menu_Item* Data_4; //4
    &menu_information_items[0], //234ca4a8, Menu_Item* Data_8; //8
    &Data_234c89e0[51], //234ca3e0 Graphic_Job_2_5_Item* header; //12 = 0xc
    &Data_234c89e0[1], //234c9760 Graphic_Job_2_5_Item* help; //16 = 0x10
    &menu_information_graphic_data, //234ca484 Graphic_Job_2_5* graphicData; //20 = 0x14
    0, //uint8_t maxItem; //0x18 = 24
    0, //int8_t currentItem; //0x19
    graphic_start_job_2_5, //void (*Data_0x1c)(); //0x1c
    sub_2348de88, //int (*onNavigate)(int*); //0x20
    menu_information_on_enter, //int (*onEnter)(int); //36 = 0x24
    menu_information_on_exit, //int (*onExit)(UI_Thread_Params*); //0x28
    0, //int Data_0x2c; //44 = 0x2c
    0, //int timeout; //48
    0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
	sub_2345611c, //void* (*Data_0x38)(struct FrontDisplay_Job*); //56

#if 0
0x234ca510                        dw         0x003f                             ; DATA XREF=dword_234c8674
0x234ca512                        dw         0x0000
0x234ca514                        dd         menu_information_items
0x234ca518                        dd         menu_information_items
0x234ca51c                        dd         0x234ca3e0
0x234ca520                        dd         0x234c9760
0x234ca524                        dd         0x234ca484
0x234ca528                        dw         0x0000
0x234ca52a                        dw         0x0000
0x234ca52c                        dd         graphic_start_job_2_5
0x234ca530                        dd         sub_2348de88+1
0x234ca534                        dd         menu_information_on_enter+1
0x234ca538                        dd         menu_information_on_exit+1
0x234ca53c                        dd         0x00000000
0x234ca540                        dd         0x00000000
0x234ca544                        dd         0x2344d9d1
0x234ca548                        dd         0x2345611d
#endif
};

#endif //!VDR110


#ifdef VDR110

static int sub_23471780(void);
static int menu_information_on_enter(int);
static int menu_information_on_exit(UI_Thread_Params*);

static Menu_Item menu_information_items[]; //23496244

static Menu menu_information = //2349620c
{
    63, //"information"
    &menu_information_items[0], //Menu_Item* Data_4; //4
    &menu_information_items[0], //Menu_Item* Data_8; //8
    0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
    0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
    0, //int Data_0x14; //20 = 0x14
    7, //uint8_t maxItem; //0x18 = 24
    0, //int8_t currentItem; //0x19
    0, //void (*Data_0x1c)(); //0x1c
    menu_items_navigate, //int (*onNavigate)(int*); //0x20
    menu_information_on_enter, //int (*onEnter)(int); //36 = 0x24
    menu_information_on_exit, //int (*onExit)(UI_Thread_Params*); //0x28
    0, //int Data_0x2c; //44 = 0x2c
    0, //int timeout; //48
    0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
    //0x38 = 56?
};

Menu_Item menu_information_items[8] = //23496244
{
	//[0]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[1]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[2]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[3]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[4]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[5]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[6]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
	//[7]
	{
		0xffff,
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471780, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23496270
	},
};


struct 
{
	Transponder Data_238e09c0; //238E09C0
	uint16_t wData_238e09d8; //238E09D8
	uint16_t wData_238e09da; //238E09DA
	Struct_23543df0 Data_238e09dc; //238E09DC
	int fill_238e09fc; //238E09FC
	int Data_238e0a00; //238E0A00
	void* Data_238e0a04; //238e0a04
	char strTransponder[52]; //238e0a08
	char Data_238e0a3c[12]; //238E0A3C
	char Data_238e0a48[12]; //238E0A48
	char Data_238e0a54[16]; //238E0A54
	char Data_238e0a64[12]; //238E0A64
	char Data_238e0a70[52]; //238E0A70
	char Data_238e0aa4[16/*size?*/]; //238E0AA4

} Data_238e09d8;




/* 2347167c - todo */
void menu_information_get_transponder_string(Transponder* r5)
{
#if 0
	console_send_string("menu_information_get_transponder_string (todo.c): TODO\r\n");
#endif

	char sp4[20]; //size???
	int modulation;
	int r0 = fe_manager_get_transponder_type(r5);

	switch (r0)
	{
		case 1:
			//loc_234716d6
			memset(&Data_238e09d8.strTransponder[0], 0, 50);
			
			snprintf(Data_238e09d8.strTransponder, 49, "%dMHz", r5->Data_0.frequency / 10000);
			snprintf(sp4, 11, " %dkS/s", r5->Data_0.symbol_rate);
			strncat(Data_238e09d8.strTransponder, sp4, 48 - strlen(Data_238e09d8.strTransponder));
			
			modulation = r5->Data_0.Data_0.Bitfield_0.modulation;

			if (modulation == 1)
			{
				strncat(Data_238e09d8.strTransponder, " 16QAM", 48 - strlen(Data_238e09d8.strTransponder));
			}
			else if (modulation == 2)
			{
				strncat(Data_238e09d8.strTransponder, " 32QAM", 48 - strlen(Data_238e09d8.strTransponder));
			}
			else if (modulation == 3)
			{
				strncat(Data_238e09d8.strTransponder, " 64QAM", 48 - strlen(Data_238e09d8.strTransponder));
			}
			else if (modulation == 4)
			{
				strncat(Data_238e09d8.strTransponder, " 128QAM", 48 - strlen(Data_238e09d8.strTransponder));
			}
			else if (modulation == 5)
			{
				strncat(Data_238e09d8.strTransponder, " 256QAM", 48 - strlen(Data_238e09d8.strTransponder));
			}
			else
			{
				strncat(Data_238e09d8.strTransponder, " ???QAM", 48 - strlen(Data_238e09d8.strTransponder));
			}
			break;

		case 3:
			//0x2347168e
#if 0
			sprintf(Data_238e09d8.strTransponder, "Transponder Type 3");
#endif
			break;

		default:
			//loc_23471776
			sprintf(Data_238e09d8.strTransponder, "No Channel Info");
			break;
	}
	//loc_234716d2
}


/* 23471780 - complete */
static int sub_23471780(void)
{
#if 0
	console_send_string("sub_23471780 (todo.c): TODO\r\n");
#endif

	return 0;
}


/* 23471784 - todo */
void menu_information_get_service_strings(uint8_t* str, int strLen)
{
	Transponder transponder;
	Channel channel;
	Struct_2340bf0c sp_0x18;
	char buf[20];

#if 0
	console_send_string("menu_information_get_service_strings (todo.c): TODO\r\n");
#endif

	sub_2340bf0c(&sp_0x18);

	sub_2340bf94(sp_0x18.wCurrentChannel, &channel, &transponder);

	if (channel.service_id != 0)
	{
		sprintf(str, "SID: 0x%x", channel.service_id);
	}
	else
	{
		sprintf(str, "SID: -");
	}

	if (channel.wAudioPID != 0)
	{
		sprintf(buf, "  %s 0x%x", "APID:", channel.wAudioPID);
	}
	else
	{
		sprintf(buf, "  %s -", "APID:");
	}

	strncat(str, buf, strLen - strlen(str) - 2);

	if (channel.wAc3PID != 0)
	{
		sprintf(buf, "  %s 0x%x", "AC3PID:", channel.wAc3PID);
	}
	else
	{
		sprintf(buf, "  %s - ", "AC3PID:");
	}

	strncat(str, buf, strLen - strlen(str) - 2);
}


/* 23471818 - complete */
void* sub_23471818(FrontDisplay_Job a[])
{
#if 0
	console_send_string("sub_23471818 (todo.c): TODO\r\n");
#endif

	if (menu_information.currentItem == 0)
	{
		// Transponder info
		strncpy(&a[0].bData_8[0], &Data_238e09d8.strTransponder[0], 255);
	}
	else if (menu_information.currentItem == 1)
	{
		// Signal Strength
		strncpy(&a[0].bData_8[0], &Data_238e09d8.Data_238e0a54[0], 255);
	}
	else if (menu_information.currentItem == 2)
	{
		// Signal to Noise Ratio C/N
		strncpy(&a[0].bData_8[0], &Data_238e09d8.Data_238e0a48[0], 255);
	}
	else if (menu_information.currentItem == 3)
	{
		// Bit Error Rate
		strncpy(&a[0].bData_8[0], &Data_238e09d8.Data_238e0a3c[0], 255);
	}
	else if (menu_information.currentItem == 4)
	{
		// FE Lock
		strncpy(&a[0].bData_8[0], &Data_238e09d8.Data_238e0a64[0], 255);
	}
	else if (menu_information.currentItem == 5)
	{
		// Service info (PIDs)
		menu_information_get_service_strings(&a[0].bData_8[0], 255);
	}
	else if (menu_information.currentItem == 6)
	{
		// Software Versions
		strncpy(&a[0].bData_8[0], &Data_238e09d8.Data_238e0a70[0], 255);
	}
	else
	{
		snprintf(&a[0].bData_8[0], 251, "MAC:%s", &Data_238e09d8.Data_238e0aa4[3]);
	}

	a[0].bData_8[255] = 0;

	uint8_t len = strlen(&a[0].bData_8[0]);

	a[0].bNumTextChars = len;
	a[0].bDisplayOffset = 0;
	a[0].bNumDisplayChars = 12;
	a[0].bData_0x10b = 0;
	a[0].bData_0x110 = 0;
	a[0].holdTime = 0;
	a[0].bData_0x10f = 0;
	a[0].Data_4 = 0;

	if (len > 12)
	{
		a[0].bData_0x10c = 1;
		a[0].Data_0 = frontdisplay_draw_scroll_text;
	}
	else
	{
		a[0].bData_0x10c = 0;
		a[0].Data_0 = frontdisplay_draw_text;
	}

	return sub_23471818;
}


/* 234718c6 - complete */
void* sub_234718c6(FrontDisplay_Job a[])
{
#if 0
	console_send_string("sub_234718c6 (todo.c): TODO\r\n");
#endif

	a[0].bData_8[0] = 0x22;

	text_table_get_string(menu_information.stringId, &a[0].bData_8[1], 252);

	uint8_t len = strlen(&a[0].bData_8[0]);

	a[0].bData_8[len] = 0x22;
	len++;
	a[0].bData_8[len] = 0;

	len = strlen(&a[0].bData_8[0]);

	a[0].bNumTextChars = len;
	a[0].bDisplayOffset = 0; 
	a[0].bNumDisplayChars = 12;
	a[0].bData_0x10b = 0; 
	a[0].bData_0x10c = 0; 
	a[0].bData_0x110 = 0; 
	a[0].holdTime = 20;
	a[0].Data_4 = 0;
	a[0].Data_0 = frontdisplay_draw_text;
	a[0].bData_0x10f = 0; 

	if (len > 12)
	{
		a[0].bData_8[10] = 0x2e;
		a[0].bData_8[11] = 0x22;
		a[0].bData_8[12] = 0;
	}
	//loc_23471928
	return sub_23471818;
}


/* 2347192c - todo */
static int menu_information_get_frontend_strings(Frontend_Measurement* r4)
{
#if 0
	console_send_string("menu_information_get_frontend_strings (todo.c): TODO\r\n");
#endif

	if (r4->bLock == 1)
	{
		//0x23471936
		strcpy(&Data_238e09d8.Data_238e0a64[0], "FE Locked");

		if (r4->dwBER <= 9000)
		{
			//0x23471948
			if (r4->dwBER == 0)
			{
				sprintf(&Data_238e09d8.Data_238e0a3c[0], "BER:0");
				//->loc_23471980
			}
			//loc_23471958
			else if (r4->dwBER >= 1000)
			{
				//0x23471960
				sprintf(&Data_238e09d8.Data_238e0a3c[0], "BER:%dxE-4", r4->dwBER / 1000);
				//->loc_23471978
			}
			//loc_2347196a
			else if (r4->dwBER >= 100)
			{
				//0x2347196e
				sprintf(&Data_238e09d8.Data_238e0a3c[0], "BER:%dxE-5", r4->dwBER / 100);
			}
			//loc_234719a4
			else if (r4->dwBER >= 10)
			{
				sprintf(&Data_238e09d8.Data_238e0a3c[0], "BER:%dxE-6", r4->dwBER / 10);
				//->loc_23471978
			}
			else
			{
				//loc_234719b4
				sprintf(&Data_238e09d8.Data_238e0a3c[0], "BER:%dxE-7", r4->dwBER);
			}
			//loc_23471980
		}
		else
		{
			//loc_234719ba
			sprintf(&Data_238e09d8.Data_238e0a3c[0], "BER:>1xE-3");
		}
	}
	else
	{
		//loc_234719be
		strcpy(&Data_238e09d8.Data_238e0a64[0], "FE Unlocked");
		//->loc_234719ba
		sprintf(&Data_238e09d8.Data_238e0a3c[0], "BER:>1xE-3");
	}
	//loc_23471980
	text_table_get_string(0x1C4, &Data_238e09d8.Data_238e0a54[0], 8);

	uint32_t r5 = 14;
	if (r4->bStrength == 0)
	{
		//0x23471996
		strncat(&Data_238e09d8.Data_238e0a54[0], "<40dB\xB5V",
			r5 - strlen(&Data_238e09d8.Data_238e0a54[0]));
		//->loc_234719fe
	}
	//loc_234719ca
	else if (r4->bStrength >= 100)
	{
		//0x234719ce
		strncat(&Data_238e09d8.Data_238e0a54[0], ">80dB\xB5V",
			r5 - strlen(&Data_238e09d8.Data_238e0a54[0]));
		//->loc_234719fe
	}
	else
	{
		//loc_234719dc
		char sp[8]; //size?

		sprintf(sp, "%2ddB\xB5V", ((r4->bStrength * 40) / 100) + 40);

		strncat(&Data_238e09d8.Data_238e0a54[0], sp, 
			r5 - strlen(&Data_238e09d8.Data_238e0a54[0]));
	}

	if (r4->bSNR > 40)
	{
		sprintf(&Data_238e09d8.Data_238e0a48[0], "C/N:%ddB", 40);
	}
	else
	{
		//loc_23471a0e
		sprintf(&Data_238e09d8.Data_238e0a48[0], "C/N:%ddB", r4->bSNR);
	}

	return 0;
}


/* 23471a1c - todo */
static int menu_information_on_enter(int a)
{
#if 0
	console_send_string("menu_information_on_enter (todo.c): TODO\r\n");
#endif

	Transponder sp_0x7c;
	Channel sp_0x54;
	int sp_0x50;
    Struct_2340bf0c sp_0x1c;

    sub_2340bf0c(&sp_0x1c);

    char sp_0xc[16] = "not defined";
	struct
	{
		uint32_t Data_0; //0
		uint32_t Data_4; //4
	} sp4;
	uint32_t sp;
    
	Data_238e09d8.wData_238e09d8 = Data_238e09d8.wData_238e09da = sp_0x1c.wCurrentChannel;

	sub_2340bf94(Data_238e09d8.wData_238e09da, &sp_0x54, &sp_0x7c);

	Data_238e09d8.Data_238e0a00 = fe_manager_get_transponder_type(&sp_0x7c);
	Data_238e09d8.Data_238e0a04 = main_hFrontend1;

	if (sp_0x54.wTransponderIndex == 0xffff)
	{
		//0x23471a5e
		fe_manager_register_measurement_callback(main_hFrontend1, 0);

		strcpy(&Data_238e09d8.Data_238e0a3c[0], "BER: -");
		strcpy(&Data_238e09d8.Data_238e0a48[0], "C/N: -");
		text_table_get_string(0x1c4, &Data_238e09d8.Data_238e0a54[0], 13);
		strcat(&Data_238e09d8.Data_238e0a54[0], "-");
		strcpy(&Data_238e09d8.Data_238e0a64[0], "Lock: -");
		//->loc_23471c0e
	}
	else
	{
		//loc_23471a96 -> loc_23471c08
		fe_manager_register_measurement_callback(main_hFrontend1, 
			menu_information_get_frontend_strings);
	}
	//loc_23471c0e
	sub_2340c29c(&Data_238e09d8.Data_238e09dc, sp_0x7c.Data_0.wData_0x0a);
	
	Data_238e09d8.Data_238e09c0 = sp_0x7c;

	memset(&Data_238e09d8.Data_238e0a70[0], 0, 50);

	text_table_get_string(0x43, &Data_238e09d8.Data_238e0a70[0], 49);
	strncat(&Data_238e09d8.Data_238e0a70[0], ": V.", 4);

	sub_234070cc("BEMON/SmartHD/0148/211008/0000", &sp_0xc[0]);

	if (0 != sub_23429bf8())
	{
		//0x23471c56
		sp_0xc[4] = 'A';
		sp_0xc[5] = 0;
	}
	//loc_23471c60
	strncat(&Data_238e09d8.Data_238e0a70[0], &sp_0xc[0], 5);

	memset(&sp_0xc[0], 0, sizeof(sp_0xc));

	strncat(&sp_0xc[0], " Font: V.", 9);

	sub_234070cc(sub_2340929c(&sp_0x50), &sp_0xc[9]);

	strncat(&Data_238e09d8.Data_238e0a70[0], &sp_0xc[0], 
		48 - strlen(&Data_238e09d8.Data_238e0a70[0]));

	sub_2340c368(1, &sp);

	memset(&sp_0xc[0], 0, sizeof(sp_0xc));

	if (sp == -1)
	{
		//0x23471cbe
		strcpy(&sp_0xc[0], " List: -1");
	}
	else
	{
		//loc_23471cc8
		snprintf(&sp_0xc[0], 11, " List: %2x", (uint8_t)sp);
	}
	//loc_23471cd4
	strncat(&Data_238e09d8.Data_238e0a70[0], &sp_0xc[0], 
		48 - strlen(&Data_238e09d8.Data_238e0a70[0]));

	menu_information_get_transponder_string(&sp_0x7c);

	if (0 != network_get_device())
	{
		//0x23471cf6
		extern void (*network_pfGetMac)();

		if (network_pfGetMac != 0)
		{
			(network_pfGetMac)(&Data_238e09d8.Data_238e0aa4[0], &sp4);
		}
		//->loc_23471d0e
	}
	else
	{
		//loc_23471d08
		menu_information.maxItem = 6;
	}
	//loc_23471d0e
	frontdisplay_start_text(sub_234718c6);

	return 0;
}


/* 23471d1a - todo */
static int menu_information_on_exit(UI_Thread_Params* a)
{
#if 0
	console_send_string("menu_information_on_exit (todo.c): TODO\r\n");
#endif

	fe_manager_register_measurement_callback(Data_238e09d8.Data_238e0a04, 0);

	return 0;
}

#endif //VDR110

#ifndef VDR110


/* /  / 234552f8 - todo */
void menu_information_get_transponder_string(Transponder* r6)
{
#if 0
	console_send_string("menu_information_get_transponder_string (todo.c): TODO\r\n");
#endif

	Graphic_Job_2_5_Item* r2 = &menu_information_p->graphicData->pItems[4/*0x100*/];
	Graphic_Job_2_5_Item* r1 = &menu_information_p->graphicData->pItems[5/*0x140*/]; //r2 + 1;
	Graphic_Job_2_5_Item* r0 = &menu_information_p->graphicData->pItems[6/*0x180*/];

	uint8_t* r7 = r2->Data_0x20->pString; //4
	uint8_t* r4 = r1->Data_0x20->pString; //5
	uint8_t* r5 = r0->Data_0x20->pString; //6

	uint8_t len;
	int modulation;
	int r0_ = fe_manager_get_transponder_type(r6);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "menu_information_get_transponder_string: r0_=%d, r5=%p, r7=%p, r4=%p\r\n", 
			r0_,
			r5, r7, r4);
		console_send_string(debug_string);
	}
#endif

	switch (r0_)
	{
		case 0:
			//loc_23455356
			break;

		case 1:
			//loc_23455430 -> loc_23455496
			text_table_get_string(0x1b/*'Symbolrate'*/, r4, 30);
			r4[31] = 0;
			len = strlen(r4);
			snprintf(r4 + len, 40, ": %dkS/s", r6->Data_0.symbol_rate);

			text_table_get_string(0xf2/*'Modulation'*/, r5, 30);
			r5[31] = 0;
			len = strlen(r5);
			//char* r0 = r5 + len;
			modulation = r6->Data_0.Data_0.Bitfield_0.modulation;
			if (modulation == 1)
			{
				//0x234554d8
				strcat(r5 + len, ": 16QAM");
			}
			//loc_234554dc
			else if (modulation == 2)
			{
				//0x234554e0
				strcat(r5 + len, ": 32QAM");
			}
			//loc_234554e4
			else if (modulation == 3)
			{
				//0x234554e8
				strcat(r5 + len, ": 64QAM");
			}
			//loc_234554ec
			else if (modulation == 4)
			{
				//0x234554f0
				strcat(r5 + len, ": 128QAM");
			}
			//loc_234554f4
			else if (modulation == 5)
			{
				//0x234554f8
				strcat(r5 + len, ": 256QAM");
			}
			else
			{
				//loc_234554fc
				strcat(r5 + len, ": ---");
			}
			//loc_234554fe
			text_table_get_string(0x16/*'Kanal'*/, r7, 20);
			len = strlen(r7);
			r4 = r7 + len;
#if 0
			{
			uint32_t sp8;
			uint32_t sp;
			uint32_t r3;

			r5 = r6->Data_0.frequency / 10000UL;
			sp8 = (r6->Data_0.frequency % 10000UL) / 1000UL;
			r3 =  r6->Data_0.wData_0x0e;
			sp = (uint8_t) r3;
			r3 = r3 >> 8;
			//loc_2345553e
			snprintf(r4, 40, ": %c%d (%d.%dMHz)", r3, sp, sp8);
			}
#else		
			snprintf(r4, 40, ": %c%d (%d.%dMHz)", 
				r6->Data_0.wData_0x0e >> 8,
				r6->Data_0.wData_0x0e & 0xff,
				r6->Data_0.frequency / 10000UL,
				(r6->Data_0.frequency % 10000UL) / 1000UL);
#endif
			//->loc_23455352
			break;

		case 2:
			//loc_234553de
			break;

		case 3:
			//loc_23455352
			break;

		default:
			//0x2345533a
			break;
	}
	//loc_23455352
}


/* /  / 23455544 - todo */
static void menu_information_get_channel_pid_strings(Channel* r4)
{
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "menu_information_get_channel_pid_strings: Data_23799b08.Data_23799b48=%d\r\n", 
			Data_23799b08.Data_23799b48);
		console_send_string(debug_string);
	}
#endif

	Graphic_Job_2_5_Item* /*pItems*/r0 = menu_information_p->graphicData->pItems;

	Graphic_Job_2_5_Item* lr = &r0[41/*0xA40*/]; //Txt Pid?
	Graphic_Job_2_5_Item* ip = &r0[42/*0xA80*/];

	//r1 = 0x9C0
	//0x2345557a
	//r3 = r0 + r1;
	//0x2345558a / 0x23455598
	uint8_t* strVidPid/*r0*/ = r0[39/*0x9C0*/]./*r3->*/Data_0x20->pString;

	//234555ac
	uint8_t* strTxtPid/*sp_0x34*/ = lr->Data_0x20->pString; //Txt Pid String?
	uint8_t* sp_0x30 = ip->Data_0x20->pString;

	//234555d4
	lr->Data_0x20->bData_0x17 = 1; //r1;
	//234555d8
	ip->Data_0x20->bData_0x17 = 1; //r1;


	if (Data_23799b08.Data_23799b48 == 3)
	{
		//0x234555ec


		//234555fe
		sprintf(strTxtPid/*sp_0x34*/, "%s -", "TxtPid:");
		//->loc_23455666
		sprintf(sp_0x30, "%s -", "Ac3Pid:");
	} //if (Data_23799b08.Data_23799b48 == 3)
	else
	{
		//loc_2345560a
		if (r4->wVideoPID/*wData_0x0a*/ != 0)
		{
			//0x23455612
			sprintf(strVidPid, "%s 0x%x", "VPid:", r4->wVideoPID/*wData_0x0a*/);
			//->loc_23455620
		}
		else
		{
			//loc_2345561a
			sprintf(strVidPid, "%s -", "VPid:");
		}
		//loc_23455620
		if (r4->wAudioPID/*wData_0x10*/ != 0)
		{
			//0x23455628

			//->loc_2345563a
		}
		else
		{
			//loc_23455632
		}
		//loc_2345563a
		if (r4->wTtxPID/*wData_0x0e*/ != 0)
		{
			//0x23455642
			sprintf(strTxtPid/*sp_0x34*/, "%s 0x%x", "TxtPid:", r4->wTtxPID);
			//->loc_23455654
		}
		else
		{
			//loc_2345564c
			sprintf(strTxtPid/*sp_0x34*/, "%s -", "TxtPid:");
		}
		//loc_23455654
		if (r4->wAc3PID/*wData_0x0c*/ != 0)
		{
			//0x2345565a

			//->loc_23455670
		}
		else
		{
			//loc_23455666
			sprintf(sp_0x30, "%s -", "Ac3Pid:");
		}
	}
	//loc_23455670
	//TODO!!!
	//sub_2343b664(&sp4, &sp_0x10);

	//loc_234556b0
	return;
}


/* /  / 234556b4 - todo */
void sub_234556b4(int a)
{
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_234556b4: a=%d, Data_23799b08.Data_23799b48=%d, sub_2340d0d0()=%d\r\n", 
			a, 
			Data_23799b08.Data_23799b48,
			/*sub_2340fbac*/sub_2340d0d0());
		console_send_string(debug_string);
	}
#endif

	Transponder sp_0x5c; //
	Channel sp_0x34; //
	Struct_2340bf0c sp; //+0x32 = sp_0x32
	Graphic_Job_2_5_Item* r1;
	uint8_t r2;
	//int r5 = 1;
	//r6 = 0x280;
	Graphic_Job_2_5* r4 = menu_information_p->graphicData;
	Graphic_Job_2_5_Item* r4_;
	uint8_t r6;
	//r2 = 0x220;
	//r3 = 0x260;

	r4->pItems[7/*0x1e0+0x1c*/].bData_0x3c = 1; //r5
	r4->pItems[8/*0x200+0x1c*/].bData_0x3c = 1; //r5
	r4->pItems[9/*0x260+0x1c*/].bData_0x3c = 1; //r5
	//r1 = r4->pItems + r6/*0x280*/;
	r1 = &r4->pItems[10/*0x280*/];
	r2 = 24; //0x18;
	//int r7 = 0;
	do
	{
		//loc_234556e8
		r1->bData_0 = 0; //r7
		r1->bData_0x3c = 1; //r5
		r1++;
		r2--;
		//r2 = (r2 << 0x18) >> 0x18;
	}
	while (r2 != 0);
	//0x234556f8
	r2 = 13; //0x0d;
	//->loc_23455844
	r1 = &r4->pItems[38/*0x980*/]; //Streams Pid Top Border

	do
	{
		//loc_2345584c
		r1->bData_0 = 0; //r7
		r1->bData_0x3c = 1; //r5
		r1++;
		r2--;
		//r2 = (r2 << 0x18) >> 0x18;
	}
	while (r2 != 0);
	//0x2345585c
	if (a == 0)
	{
		//0x23455860: Display Level, C/N and BER
		if (Data_23799b08.Data_23799b48 == 2)
		{
			//loc_23455868
			r4_ = &r4->pItems[10/*0x280*/];
			r6 = 10;

			strcpy(&Data_237999dc[0], "Lock");
			menu_channel_search_fec_string[0] = 0; //r7;
			//->loc_234558fc
		}
		//loc_2345587c
		else if (Data_23799b08.Data_23799b48 == 1)
		{
			//0x23455880
			if (0 != /*sub_2340fbac*/sub_2340d0d0())
			{
				//0x23455888

				//TODO!!!
			}
			//->loc_23455868
			r4_ = &r4->pItems[10/*0x280*/];
			r6 = 10;

			strcpy(&Data_237999dc[0], "Lock");
			menu_channel_search_fec_string[0] = 0; //r7;
			//->loc_234558fc
		}
		else
		{
			//loc_234558a4
			r4_ = &r4->pItems[10/*0x280*/];
			r6 = 12;
			if (0 != /*sub_2340fbac*/sub_2340d0d0())
			{
				r6 = 24;
			}
			//loc_234558b4
			strcpy(&Data_237999dc[0], "QPSK");
			strcpy(menu_channel_search_fec_string, "FEC");
			//->loc_23455908
		}
	}
	//loc_234558c6
	else if (a == 1)
	{
		//0x234558ca: Display PIDs???
		/*sub_2340e9e8*/sub_2340bf0c(&sp);

		r4_ = &r4->pItems[38/*0x980*/]; //Items: Streams Pid Top Border
		r6 = 8; //numItems: Border + VPid + APid + TxtPid + Ac3Pid + Type + VSize + HSize

		sub_2340bf94/*sub_2340ea70*/(sp.wCurrentChannel, &sp_0x34, &sp_0x5c);
		menu_information_get_channel_pid_strings(&sp_0x34);
		//->loc_234558fc
	} //else if (a == 1)
	//loc_234558ee
	else if (a == 2)
	{
		//0x234558f2: Display Rest???

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_234556b4(0x234558f2): a=%d\r\n", 
				a);
			console_send_string(debug_string);
		}
#endif

		//TODO!!!
	} //else if (a == 2)
	else
	{
		//->loc_2345590c
		return; //break;
	}
	//loc_23455908
	while (r6 != 0)
	{
		//->loc_234558fc
		r4_->bData_0 = 1; //r5
		r4_->bData_0x3c = 1; //r5
		r4_++;
		r6--;
		//->loc_23455908
	}
	//loc_2345590c
	return;
}


/* /  / 23455910 - todo */
int sub_23455910(Struct_23455910* r4)
{
#if 0
	console_send_string("sub_23455910 (todo.c): TODO\r\n");
#endif

	Graphic_Job_2_5* sp_0xc0 = menu_information_p->graphicData;
	uint8_t* sp_0xBC;
	uint8_t* sp_0xB8;
	uint8_t* sp_0xB4;
	uint8_t* sp_0xB0;
	uint8_t* sp_0xAC;
	Graphic_Job_2_5_Item* sp_0x80;
	Graphic_Job_2_5_Item* sp_0x7c;
	Graphic_Job_2_5_Item* sp_0x78;
	Transponder sp_0x60; //sp_0x60
	Channel sp_0x38; //sp_0x38
	Struct_2340bf0c sp4; //+0x32 = sp_0x36
	Graphic_Job_2_5_Item* r6;
	Graphic_Job_2_5_Item* r5;
	struct Menu_Data* r5_ = sub_2344de8e();

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23455910: wData_2=0x%x, r4->Data_4=0x%x, r4->bData_8=0x%x\r\n", 
			r5_->menu_stack[ sub_2344de94() ]->graphicData->wData_2,
			r4->Data_4,
			r4->bData_8);
		console_send_string(debug_string);
	}
#endif

	if (r5_->menu_stack[ sub_2344de94() ]->graphicData->wData_2 == 0x11)
	{
		//0x23455936
		sp_0x80 = &sp_0xc0->pItems[35/*0x8C0*/];
		sp_0x7c = &sp_0xc0->pItems[36/*0x900*/];
		sp_0x78 = &sp_0xc0->pItems[37/*0x940*/];
		//r2 = 0x480
		if (r4->Data_4 != 0)
		{
			//0x2345595c
#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "0x2345595c: r4->Data_4=0x%x\r\n", 
					r4->Data_4);
				console_send_string(debug_string);
			}
#endif

			//TODO!!!

			//->loc_234559ee
		} //if (r4->Data_4 != 0)
		else
		{
			//loc_234559aa
			r6 = &sp_0xc0->pItems[20/*0x500*/];
//			sp_0x9C = r0 + 0x100;
//			sp_0x98 = r0 + 0x140;
//			sp_0x94 = r0 + 0x180;
//			sp_0x90 = r0 + 0x380;
			r5 = &sp_0xc0->pItems[18/*0x480*/];
//			r3 = r0 + 0x340;
//			sp_0x8c = r0 + 0x3c0;
//			sp_0x88 = r0 + 0x400;
//			sp_0x84 = r0 + 0x440;
			//loc_234559ee
		}
		//loc_234559ee
		sp_0xBC = sp_0xc0->pItems[13/*0x340*/]/*r3*/.Data_0x20->pString;
		sp_0xB8 = sp_0xc0->pItems[11/*0x2c0*/]/*r1*/.Data_0x20->pString;
		sp_0xB4 = sp_0xc0->pItems[12/*0x300*/]/*r2*/.Data_0x20->pString;
		
		sp_0xc0->pItems[13/*0x340*/]/*r3*/.Data_0x20->bData_0x17 = 1; //r7
		sp_0xc0->pItems[11/*0x2c0*/]/*r1*/.Data_0x20->bData_0x17 = 1; //r7
		sp_0xc0->pItems[12/*0x300*/]/*r2*/.Data_0x20->bData_0x17 = 1; //r7
		//0x23455a10
		sp_0xB0 = sp_0xc0->pItems[35/*0x8C0*/]/*sp_0x80*/.Data_0x20->pString;
		sp_0xAC = sp_0xc0->pItems[36/*0x900*/]/*sp_0x7c*/.Data_0x20->pString;
		//0x23455a20
		if (0 == OSSemAccept(Data_23799af4))
		{
			//->loc_23455a34 -> loc_23455c3a
			return 0;
		}
		//0x23455a2c
		if (Data_23799b08.wData_23799b22 != Data_23799b08.wData_23799b20)
		{
			//0x23455a40
#if 0
			console_send_string("0x23455a40 (menu_information.c): TODO\r\n");
#endif
			//TODO!!!

		}
		Transponder* sp_0xC8 = /*r2 =*/ &Data_23799b08.transponder;
		//loc_23455b3c -> loc_23455b42
		if (r4->bData_8 == 1)
		{
			//0x23455b48
			if (r4->Data_0 < 9000/*0x2328*/)
			{
				//0x23455b50
				sprintf(sp_0xBC, "BER: %d", r4->Data_0);
				//->loc_23455b62
			}
			else
			{
				//loc_23455b5a
				sprintf(sp_0xBC, "BER: >9000");
			}
			//loc_23455b62
			if (r5->wColor != 11)
			{
				//->loc_23455b7c
				r5->wColor = 11;
				//r5 += 0x20
				r5->bData_0x3c = 1; //r7
			}
			//->loc_23455b82
		} //if (r4->bData_8 == 1)
		else
		{
			//loc_23455b6c
			sprintf(sp_0xBC, "BER: >9000");
			//0x23455b74
			if (r5->wColor != 10)
			{
				r5->wColor = 10;
				//r5 += 0x20
				r5->bData_0x3c = 1; //r7
			}
		}
		//loc_23455b82
		//r0 = r6->wColor;
		if (r4->bData_0x0b == 0)
		{
			//0x23455b8a
			if (r6->wColor != 10)
			{
				r6->wColor = 10;
				//r6 += 0x20
				r6->bData_0x3c = 1; //r7
			}
		}
		//loc_23455b92
		else
		{
			if (r6->wColor != 11)
			{
				r6->wColor = 11;
				//r6 += 0x20
				r6->bData_0x3c = 1; //r7
			}
		}
		//loc_23455b9e
		/*sp_0x9C*/sp_0xc0->pItems[4/*0x100*/].Data_0x20->bData_0x17 = 1; //r7
		/*sp_0x98*/sp_0xc0->pItems[5/*0x140*/].Data_0x20->bData_0x17 = 1; //r7
		/*sp_0x94*/sp_0xc0->pItems[6/*0x180*/].Data_0x20->bData_0x17 = 1; //r7
		//0x23455bb0
		menu_information_get_transponder_string(sp_0xC8);

		sub_2340bf0c/*2340e9e8*/(&sp4);
		sub_2340bf94/*sub_2340ea70*/(sp4.wCurrentChannel, &sp_0x38, &sp_0x60);

		menu_information_get_channel_pid_strings(&sp_0x38);

		uint8_t r5 = r4->bData_9;
		if (r5 > 100)
		{
			r5 = 100;
		}
		//loc_23455bd6
		sprintf(sp_0xB4, "Level: %d%%", r5);
		sub_23452ac4(r5, /*sp_0x8C*/sp_0xc0->pItems[15/*0x3C0*/], 0xde, 100);
		/*sp_0x90*/sp_0xc0->pItems[14/*0x380*/].bData_0x3c = 1; //r7

		uint8_t r6 = r4->bData_0x0a;
		if (r6 > 40)
		{
			r6 = 40;
		}
		//loc_23455bfa
		sprintf(sp_0xB8, "C/N: %ddB", r6);
		sub_23452ac4(r6, /*sp_0x84*/sp_0xc0->pItems[17/*0x440*/], 0xde, 40);
		/*sp_0x88*/sp_0xc0->pItems[16/*0x400*/].bData_0x3c = 1; //r7
		//0x23455c16
		graphic_start_job_2_5(&Data_23799af8, sp_0xc0);
		OSSemPost(Data_23799af4);

		if (Data_234c8664 != 0)
		{
			(Data_234c8664)(r4->Data_0, r5, r6, r4->Data_0);
		}
		//loc_23455c3a
	} //if (r5_->menu_stack[ sub_2344de94() ]->graphicData->wData_2 == 0x11)
	//loc_23455a34 -> loc_23455c3a
	return 0;
}


/* /  / 23455ca8 - todo */
void* sub_23455ca8(int* a)
{
	int r0 = *a;
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23455ca8: r0=0x%x\r\n", r0);
		console_send_string(debug_string);
	}
#endif

	Struct_2340bf0c sp_0x40; //sp_0x40
	Transponder sp_0x28; //pTransponder
	Channel sp; //pChannel

	if (r0 == 0x8000)
	{
		//0x23455cb8
		Data_23799af0++;
		if (Data_23799af0 > 2)
		{
			//0x23455cc2
			if (Data_23799b08.Data_23799b48 == 3)
			{
				Data_23799af0 = 1;
			}
			else
			{
				Data_23799af0 = 0;
			}
		}
		//loc_23455cd0
		sub_234556b4(Data_23799af0);
		//->loc_23455d3e
		return NULL;
	}
	//loc_23455cd6
	else if (r0 == 0x0001)
	{
		//0x23455cda
		channel_next();
		//->loc_23455cf4
	}
	//loc_23455ce0
	else if (r0 == 0x0002)
	{
		//0x23455ce4
		channel_prev();
		//->loc_23455cf4
	}
	//loc_23455cea
	else if (r0 == 0x0100)
	{
		//0x23455cf0
		channel_swap();
		//loc_23455cf4
	}
	//loc_23455cf4
	sub_2340bf0c/*2340e9e8*/(&sp_0x40);
	Data_23799b08.wData_23799b22 = sp_0x40.wCurrentChannel;
	//loc_23455d00
	if (0 == sub_2340d0d0/*sub_2340fbac*/())
	{
		//0x23455d08
		int r5 = Data_23799b08.Data_23799b48;
		sub_2340bf94/*sub_2340ea70*/(Data_23799b08.wData_23799b22, &sp, &sp_0x28);
		Data_23799b08.Data_23799b48 = fe_manager_get_transponder_type(&sp_0x28);
		if (Data_23799b08.Data_23799b48 != r5)
		{
			//0x23455d20
			fe_manager_register_measurement_callback(Data_23799b08.Data_23799b4c, 0);
			void* r0;
			if (Data_23799b08.Data_23799b48 == 0)
			{
				r0 = main_hFrontend1;
			}
			else
			{
				r0 = Data_23491db8;
			}
			Data_23799b08.Data_23799b4c = r0;

			fe_manager_register_measurement_callback(Data_23799b08.Data_23799b4c, sub_23455910);
		} 
		//loc_23455d3e
	}
	//loc_23455d3e
	return NULL;
}


/*  /   / 23455d44 - todo */
int menu_information_on_enter()
{
#if 1
	console_send_string("menu_information_on_enter (todo.c): TODO\r\n");
#endif

	Transponder sp_0xa4; //pTransponder
	Channel sp_0x7c; //pChannel
	Struct_2340bf0c sp_0x1c; //+0x32 = sp_0x4e
	//uint8_t sp_0xc[16];
	Graphic_Job_2_5* r5 = menu_information_p->graphicData;

	/*sub_2340e9e8*/sub_2340bf0c(&sp_0x1c);

	//int r7 = 0;
	uint8_t sp_0xc[16] = "not defined";
	Data_23799b08.wData_23799b20 = Data_23799b08.wData_23799b22 = sp_0x1c.wCurrentChannel/*sp_0x46*/;

	if (sp_0x1c.wNumChannels/*sp_0x44*/ == 0)
	{
		//0x23455d72
		int r0 = /*sub_23416808*/sub_2340ee34(main_hFrontend1);
		switch (r0)
		{
			case 1:
				//0x23455d7c
				Data_23799b08.Data_23799b48 = 0; //r7
				//->loc_23455d94
				break;
			//loc_23455d80
			case 3:
				//loc_23455d88
				Data_23799b08.Data_23799b48 = 1;
				//->loc_23455d92
				break;
			case 2:
			case 6:
				//->loc_23455d90
				Data_23799b08.Data_23799b48 = 2;
				break;
			//loc_23455da8
			default:
				//
				Data_23799b08.Data_23799b48 = 3;
				//->loc_23455d92
				break;
		} //switch (r0)
	} //if (sp_0x1c.wNumChannels == 0)
	else
	{
		//loc_23455dac
		sub_2340bf94/*sub_2340ea70*/(Data_23799b08.wData_23799b22, &sp_0x7c, &sp_0xa4);
		Data_23799b08.Data_23799b48 = fe_manager_get_transponder_type(&sp_0xa4);
		//->loc_23455d92
	}
	//loc_23455d94
	//r1 = &dword_234c01d8
	if (0 == sub_2340d0d0/*sub_2340fbac*/())
	{
		//0x23455d9e
		switch (Data_23799b08.Data_23799b48)
		{
			case 0:
				//loc_23455da40
				//r0 = main_hFrontend1
				//->loc_23455dca
				Data_23799b08.Data_23799b4c = main_hFrontend1;
				fe_manager_register_measurement_callback(main_hFrontend1, sub_23455910);
				break;
			//loc_23455dbc
			case 1:
				//0x23455dc0
				if (sp_0xa4.bData_0x16/*sp_0xba*/ == 1)
				{
					//loc_23455dc8
					Data_23799b08.Data_23799b4c = Data_23491db8/*234c01d8*/;
					fe_manager_register_measurement_callback(Data_23799b08.Data_23799b4c, sub_23455910);
				}
				else
				{
					//loc_23455da4
					//r0 = main_hFrontend1
					//->loc_23455dca
					Data_23799b08.Data_23799b4c = main_hFrontend1;
					fe_manager_register_measurement_callback(main_hFrontend1, sub_23455910);
				}
				break;
			//loc_23455e66
			case 2:
				//->loc_23455dc8
				Data_23799b08.Data_23799b4c = Data_23491db8/*234c01d8*/;
				//loc_23455dca
				fe_manager_register_measurement_callback(Data_23799b08.Data_23799b4c, sub_23455910);
				break;

			default:
				//loc_23455da4
				//r0 = main_hFrontend1
				//->loc_23455dca
				Data_23799b08.Data_23799b4c = main_hFrontend1;
				fe_manager_register_measurement_callback(main_hFrontend1, sub_23455910);
				break;
		} //switch (Data_23799b08.Data_23799b48)
		//loc_23455dbc
	} //if (0 == sub_2340d0d0/*sub_2340fbac*/())
	else
	{
		//loc_23455e6c
		Data_23799b08.Data_23799b4c = Data_23491db8/*234c01d8*/;
		fe_manager_register_measurement_callback(Data_23799b08.Data_23799b4c, sub_23455910);
		//r1 = sub_23455910
		//r0 = main_hFrontend1
		//->loc_23455dce
		fe_manager_register_measurement_callback(main_hFrontend1, sub_23455910);
	}
	//0x23455dce 
	//0x23455dd2
	//r1 = r5->pItems;
	r5->pItems[37/*0x940*/].bData_0 = 1;
	r5->pItems[36/*0x900*/].background = &menu_main_graphic_item_background_dark_blue;
	r5->pItems[34/*0x880*/].height = 0x6c;

	sub_2340c29c/*sub_2340ed78*/(&Data_23799b08.Data_23799b24, sp_0xa4.Data_0.wData_0x0a/*sp_0xae*/);

	Data_23799b08.transponder = sp_0xa4; //memcpy(&Data_23799b08.transponder, &sp_0xa4, sizeof(Transponder));
	memset(&Data_23799a40, 0, 0x1e);
	//0x23455e18


	//0x23455f30


	//loc_23455f48


	//0x23455fb2
	if (Data_23799b08.Data_23799b48 == 3)
	{
		//0x23455fb8
		Data_23799af0 = 2;

//		sub_2340c9b0/*sub_2340f48c*/(1, &sp_0x64);

		//TODO!!!

		//->loc_2345603c
	}
	else
	{
		//loc_2345601c
		text_table_get_string(0x19/*'Frequenz'*/, &menu_information_item0_string[0], 35);
		text_table_get_string(0x1b/*'Symbolrate'*/, &menu_information_item1_string[0], 35);
		text_table_get_string(0x1a/*'Polarisation'*/, &menu_information_item2_string[0], 30);
	}
	//loc_2345603c
	sub_234556b4(Data_23799af0);
	menu_information_get_transponder_string(&sp_0xa4);

	sp_0x7c.wVideoPID/*0x86*/ = 0; //r7
	sp_0x7c.wAudioPID/*0x8c*/ = 0; //r7
	sp_0x7c.wAudioPID/*0x8a*/ = 0; //r7
	sp_0x7c.wAc3PID/*0x88*/ = 0; //r7
	menu_information_get_channel_pid_strings(&sp_0x7c);

	Data_23799af4 = Data_234c1258;

	return 0;
}


/* /  / 23456064 - todo */
void menu_information_on_exit()
{
#if 1
	console_send_string("menu_information_on_exit (todo.c): TODO\r\n");
#endif

	fe_manager_register_measurement_callback(Data_23799b08.Data_23799b4c, NULL);

	//TODO!!!
}


/* /  / 2345611c - todo */
void* sub_2345611c(void* a)
{
#if 0
	console_send_string("sub_2345611c (menu_installation.c): TODO\r\n");
#endif

	//TODO!!!

	//loc_234561d4
	return sub_2345611c;
}


#endif !VDR110


/* 23471d2c /  / 23456220 - todo */
int menu_information_entry(UI_Thread_Params* p)
{
#if 0
	console_send_string("menu_information_entry (todo.c): TODO\r\n");
#endif

#ifdef VDR110
	menu_stack_operate(&menu_information);

	menu_initialize(&menu_information);

	sub_2343d51e(&menu_information, p);
#else
	menu_stack_operate(menu_information_p);
	menu_initialize(menu_information_p);
	sub_2343d51e(menu_information_p, p);
	frontdisplay_start_text(sub_2345611c);
#endif //!VDR110

	return 0;
}

#ifndef VDR110

/* /  / 2345625c - todo */
void menu_information_set_flavor(uint8_t a)
{
#if 0
	console_send_string("menu_information_set_flavor (todo.c): TODO\r\n");
#endif

	menu_information_p  = menu_information_flavor[a];
	Menu_Item* r1 = menu_information_flavor[a]->Data_8;
	if (a == 0)
	{
		r1->helpStringId = 0xf8;
	}
	else
	{
		r1->helpStringId = 0x16B;
	}
}

#endif //!VDR110


