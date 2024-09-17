
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


#if 0
typedef struct
{
	int fill_0[4]; //0
	void* Data_0x10; //0x10

} Struct_235fdf74_Inner12_Inner0x20;
#endif

#if 0
typedef struct
{
	int fill_0[8]; //0
	Struct_235fdf74_Inner12_Inner0x20* Data_0x20; //0x20 = 32

} Struct_235fdf74_Inner12;
#endif //->Graphic_Job_2_5_Item

#if 0
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
#endif

#if 0
typedef struct
{
	int fill_0[4]; //0
	void* Data_0x10; //0x10

} Struct_235fdf74_Inner20_Inner8_Inner0x20;
#endif

#if 0
typedef struct
{
	Graphic_Job_2_5_Item Data_0[9]; //0
	struct
	{
		int fill_0[8]; //0
		Struct_235fdf74_Inner20_Inner8_Inner0x20* Data_0x20; //0x20 = 32
		//0x24???
	} Data_576; //0x240 = 576
	int fill_0x264[38]; //0x264
	uint8_t bData_0x2fc; //0x2fc
} Struct_235fdf74_Inner20_Inner8;
#endif

typedef struct
{
	int Data_0; //0
	uint8_t keyCode; //4
	void* Data_8; //8
	//12
} Menu_Event;


extern int menu_items_navigate(int*);
extern int menu_general_settings_entry(UI_Thread_Params*);


extern void sub_2342d878();
extern void sub_2342d9e0();
extern void sub_2342db04();
extern void sub_2342dc7c();
extern void sub_2342df40(); 

extern void sub_234256fc();

