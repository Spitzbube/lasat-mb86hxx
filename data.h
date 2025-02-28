
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
extern void* main_hViencSd; //23491da4 +0x18
extern void* main_hViencHd; //23491da8
extern void* main_hHdmi; //23491dac
extern Struct_235f2e2c* main_hFlash; //23491db0 +0x24
extern Frontend* main_hFrontend1; //23491db4 +40 = 0x28 //Data_234ac4e8 / 234c01d4
extern Frontend* Data_23491db8; //23491db8 +44 = 0x2c //Data_234ac4ec / 234c01d8
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

