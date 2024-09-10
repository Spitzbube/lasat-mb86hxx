
#include <stdint.h>

#include "sys_services.h"
#include "timer.h"
#include "gpio.h"
#include "uart.h"
#include "console.h"
#include "threads.h"
#include "ucos_ii.h"
#include "memblk.h"
#include "flash.h"
#include "lastmode.h"
#include "sub_2340a6a0.h"
#include "frontend.h"
#include "bm.h"
#include "tsd.h"
#include "psi.h"

#define NULL ((void*)0)

extern void* main_hUart1; //23491d94 +8
extern void* main_hI2c0; //23491d98 +12 = 0xc
extern Struct_234a73e8* main_hPSIDecoder1; //23491d9c / 234ac4d0 +16 = 0x10
extern Struct_234a73e8* main_hPSIDecoder2; //23491da0 +20 = 0x14
extern int Data_23491da4; //23491da4 +0x18
extern int Data_23491da8; //23491da8
extern void* main_hHdmi; //23491dac
extern Struct_235f2e2c* main_hFlash; //23491db0 +0x24
extern Frontend* main_hFrontend1; //23491db4 +40 = 0x28 //Data_234ac4e8
extern Frontend* Data_23491db8; //23491db8 +44 = 0x2c //Data_234ac4ec
extern MemBlk_Handle* main_hMemBlk1; //23491DBC +0x30
extern MemBlk_Handle* main_hMemBlk2; //23491dc0 +0x34
extern Struct_20611068* main_hUsbGpio; //23491dc4 +0x38 
extern Lastmode_Instance* main_hLastmode; //23491dc8 +0x3c
extern void* main_hPCR_TSD_Handle; //23491dcc +0x40
extern void* main_hPESParserAudio; //23491dd0 +0x44
extern void* main_hAuOut; //23491dd4  +0x48
extern void* main_hAudec2; //23491dd8 +0x4c
extern void* main_hAudec1; //23491ddc +0x50
extern void* main_hAudec0; //23491de0 +0x54
extern void* main_hAudec4; //23491de4 +0x58
extern void* main_hAudec5; //23491de8 +0x5c
extern void* main_hAudecRadioText; //23491dec +0x60
extern void* main_hCurrentPCR_TSD_Handle; //23491e08
extern void* main_hPESParserVideo; //23491e0c +0x80 / 234ac510

typedef struct
{
	uint32_t crc; //0
	uint16_t currentChannel; //4
	uint16_t prevChannel; //6
	uint16_t currentTvChannel; //8
	uint16_t currentRadioChannel; //10
	uint8_t bData_12; //12
	uint8_t currentChList; //13
	/*
		Bit 0...3: Powermode
	 */
#if 1
	uint8_t bData_14; //14
#else
	uint32_t bData_14_0: 4; //14 Bit0...3
#endif
	uint8_t bVolume; //15
	//16
} LastMode;


typedef struct
{
	int fill_0; //0
	char* threadName; //4
	void* pSema; //8
	void* pMBox; //12
	void (*threadFunc)(); //16
	void (*Data_20)(); //20
	//24
} UI_Thread_Params;


extern void mainfunction_thread(UI_Thread_Params*);
extern void standby_thread(UI_Thread_Params*);
extern void menu_event_thread(UI_Thread_Params*);
extern void menu_item_event_thread(UI_Thread_Params*);


typedef struct
{
	int fill_0[4]; //0
	void* Data_0x10; //16 = 0x10
	uint16_t fill_0x14; //20 = 0x14
	uint8_t fill_0x16; //22 = 0x16
	uint8_t bData_0x17; //23 = 0x17
	//???
} Menu_Item_Inner4_Data_0_Data_0x20;

typedef struct
{
	uint8_t bData_0; //0
	int fill_4[6]; //4
	uint16_t wData_0x1c; //28 = 0x1c
	Menu_Item_Inner4_Data_0_Data_0x20* Data_0x20; //32 = 0x20
	int fill_0x24[6]; //36 = 0x24
	uint8_t bData_0x3c;
	//???
} Menu_Item_Inner4_Data_0;

typedef struct Menu_Item
{
	uint16_t wData_0; //0
	uint16_t helpStringId; //2
	Menu_Item_Inner4_Data_0* Data_4[5]; //4
	void (*initValueString)(struct Menu_Item*); //0x18 = 24
	void* onEvent; //0x1c = 28
	void* inputThreadFunc; //0x20 = 32
	void* Data_0x24; //0x24 = 36
	void* Data_0x28; //0x28 = 40
	//0x2c = 44
} Menu_Item;


typedef struct
{
	int fill_0[4]; //0
	void* Data_0x10; //0x10

} Struct_235fdf74_Inner12_Inner0x20;


typedef struct
{
	int fill_0[8]; //0
	Struct_235fdf74_Inner12_Inner0x20* Data_0x20; //0x20 = 32

} Struct_235fdf74_Inner12;

typedef struct
{
	uint16_t fill_0; //0
	uint16_t wData_2; //2
	uint16_t wData_4; //4
	uint16_t wData_6; //6
	int fill_8; //8
	uint8_t fill_0xc; //0xc
	uint8_t bData_0xd; //0xd
	void* str; //0x10
	uint16_t fill_0x14; //0x14
	uint8_t fill_0x16; //0x16
	uint8_t bData_0x17; //0x17

} Struct_235fdf74_Inner16_Inner0x20;

typedef struct
{
	int fill_0[8]; //0
	Struct_235fdf74_Inner16_Inner0x20* Data_0x20; //0x20 = 32

} Struct_235fdf74_Inner16;

typedef struct
{
	int fill_0[4]; //0
	void* Data_0x10; //0x10

} Struct_235fdf74_Inner20_Inner8_Inner0x20;

typedef struct
{
	int Data_0; //0
	uint16_t wData_4; //4
	uint16_t wData_6; //6
	void (*Data_8)(void*, uint8_t); //8
	//???
} Struct_2377ded0_Inner_0x1c_Inner_8;

typedef struct
{
	int fill_0; //0
	int Data_4; //4
	uint8_t bData_8; //8
	//???
} Struct_2377ded0_Inner_0x1c_Inner_0x18;

typedef struct
{
	uint8_t bData_0; //0
	uint16_t wData_2; //2
	uint16_t wData_4; //4
	uint16_t wData_6; //6
	uint16_t wData_8; //8
	uint8_t fill_0xa; //10
	uint8_t bData_0xb; //11
	uint8_t bData_0xc; //12
	uint8_t bData_0xd; //13
	uint8_t* Data_0x10; //16
	uint16_t wData_0x14; //20 = 0x14
	uint8_t bData_0x16; //22 = 0x16
	uint8_t bData_0x17; //23 = 0x17
	//0x18
} Struct_2377ded0_Inner_0x1c_Inner_0x20;

typedef struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	int fill_4; //4
	Struct_2377ded0_Inner_0x1c_Inner_8* Data_8; //8
	uint16_t wData_0xc; //0xc = 12
	uint16_t wData_0xe; //0xe = 14
	uint16_t wData_0x10; //0x10 = 16
	uint16_t wData_0x12; //0x12 = 18
	int fill_0x14; //0x14
	Struct_2377ded0_Inner_0x1c_Inner_0x18* Data_0x18; //0x18
	uint16_t wData_0x1c; //0x1c
	uint16_t wData_0x1e; //0x1e
	Struct_2377ded0_Inner_0x1c_Inner_0x20* Data_0x20; //0x20
	Struct_2377ded0_Inner_0x1c_Inner_0x20 Data_0x24; //0x24 +0x18
	uint8_t bData_0x3c; //0x3c
	//0x40
} Struct_2377ded0_Inner_0x1c;

typedef struct
{
	Struct_2377ded0_Inner_0x1c Data_0[9]; //0
	struct
	{
		int fill_0[8]; //0
		Struct_235fdf74_Inner20_Inner8_Inner0x20* Data_0x20; //0x20 = 32
		//0x24???
	} Data_576; //0x240 = 576
	int fill_0x264[38]; //0x264
	uint8_t bData_0x2fc; //0x2fc
} Struct_235fdf74_Inner20_Inner8;

typedef struct
{
	uint16_t fill_0; //0
	uint16_t wData_2; //2
	struct
	{
		int fill_0; //0
		Struct_235fdf74_Inner20_Inner8* Data_4; //4
		int fill_8[4]; //8
	} Data_4;
	void (*Data_0x1c)(); //28 = 0x1c
	void (*Data_0x20)(); //32 = 0x20
	//???
} Struct_235fdf74_Inner20;

typedef struct Menu
{
	uint16_t stringId; //0
	Menu_Item* Data_4; //4
	Menu_Item* Data_8; //8
	Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
	Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
	Struct_235fdf74_Inner20* Data_0x14; //20 = 0x14
	uint8_t maxItem; //0x18 = 24
	int8_t currentItem; //0x19
	void (*Data_0x1c)(); //0x1c
	int (*onNavigate)(int*); //0x20
	int (*onEnter)(int); //36 = 0x24
	int (*onExit)(UI_Thread_Params*); //0x28
	int Data_0x2c; //44 = 0x2c
	int timeout; //48 = 0x30
	Menu_Item* (*Data_0x34)(struct Menu*); //52
#ifdef VDR110
	//0x38 = 56?
#else
	void* (*Data_0x38)(struct FrontDisplay_Job*); //56
	//0x3c = 60?
#endif
}
Menu;

typedef struct
{
	int fill_0; //0
	uint8_t keyCode; //4
	int fill_8; //8
} Menu_Event;


extern int menu_items_navigate(int*);
extern int menu_general_settings_entry(UI_Thread_Params*);


struct Menu_Data
{
	UI_Thread_Params Data_235fdf58; //0 235fdf58 235fdf98 -0x40 23796784
	UI_Thread_Params* Data_235fdf70; //24 = 0x18 235fdf70 / 2378336C -0x40 + 0x18 2379679C
	Menu* menu_stack[13]; //28 = 0x1c 235fdf74 -0x40, size??? 237967A0
	uint8_t menu_stack_level; //80 = 0x50 235fdfa8 235fdf98 + 0x10 237967D4
	uint8_t bData_235fdfa9;

};


extern void sub_2342d6ec();
extern void sub_2342d878();
extern void sub_2342d9e0();
extern void sub_2342db04();
extern void sub_2342dc7c();
extern void sub_2342df40(); 

extern void sub_234256fc();

