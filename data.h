
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
#include "sub_23438084.h"
#include "sub_2340a6a0.h"
#include "frontend.h"
#include "bm.h"
#include "tsd.h"
#include "psi.h"


extern void* Data_23491d94; //23491d94 +8
extern void* main_hI2c0; //23491d98 +12 = 0xc
extern Struct_234a73e8* main_hPSIDecoder1; //23491d9c / 234ac4d0 +16 = 0x10
extern Struct_234a73e8* main_hPSIDecoder2; //23491da0 +20 = 0x14
extern int Data_23491da4; //23491da4 +0x18
extern int Data_23491da8; //23491da8
extern void* Data_23491dac; //23491dac
extern Struct_235f2e2c* main_hFlash; //23491db0 +0x24
extern Struct_2354dd70* main_hFrontend1; //23491db4 +40 = 0x28 //Data_234ac4e8
extern Struct_2354dd70* Data_23491db8; //23491db8 +44 = 0x2c //Data_234ac4ec
extern MemBlk_Handle* main_hMemBlk1; //23491DBC +0x30
extern MemBlk_Handle* main_hMemBlk2; //23491dc0 +0x34
extern Struct_20611068* main_hUsbGpio; //23491dc4 +0x38 
extern Struct_23438084* Data_23491dc8; //23491dc8 +0x3c
extern void* main_hPCR_TSD_Handle; //23491dcc +0x40
extern void* main_hPESParserAudio; //23491dd0 +0x44
extern void* main_hAuOut; //23491dd4  +0x48
extern void* main_hAudec2; //23491dd8 +0x4c
extern void* main_hAudec1; //23491ddc +0x50
extern void* main_hAudec0; //23491de0 +0x54
extern void* main_hAudec4; //23491de4 +0x58
extern void* main_hAudec5; //23491de8 +0x5c
extern int Data_23491dec; //23491dec +0x60
extern void* main_hCurrentPCR_TSD_Handle; //23491e08
extern void* main_hPESParserVideo; //23491e0c +0x80 / 234ac510

typedef struct
{
	uint32_t crc; //0
	uint16_t currentChannel; //4
	uint16_t prevChannel; //6
	uint16_t wData_8; //8
	uint16_t wData_10; //10
	uint8_t bData_12; //12
	uint8_t bData_13; //13
#if 1
	uint8_t bData_14; //14
#else
	uint32_t bData_14_0: 4; //14 Bit0...3
#endif
	uint8_t bData_15; //15
	//16
} Struct_234011f4;


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


typedef struct Menu_Item
{
	uint16_t wData_0; //0
	uint16_t wData_2; //2
	int fill_4[5]; //4
	void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
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
	void* Data_0x10; //0x10

} Struct_235fdf74_Inner16_Inner0x20;

typedef struct
{
	int fill_0[8]; //0
	Struct_235fdf74_Inner16_Inner0x20* Data_0x20; //0x20 = 32

} Struct_235fdf74_Inner16;

typedef struct Menu
{
	uint16_t stringId; //0
	Menu_Item* Data_4; //4
	Menu_Item* Data_8; //8
	Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
	Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
	int Data_0x14; //20 = 0x14
	uint8_t maxItem; //0x18 = 24
	int8_t currentItem; //0x19
	void (*Data_0x1c)(); //0x1c
	int (*onNavigate)(int*); //0x20
	int (*onEnter)(int); //36 = 0x24
	int (*onExit)(UI_Thread_Params*); //0x28
	int Data_0x2c; //44 = 0x2c
	int timeout; //48 = 0x30
	Menu_Item* (*Data_0x34)(struct Menu*); //52
	//0x38 = 56?
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


extern int sub_2343dd2c(void);
extern int sub_2343deb4(int);

extern void sub_23472004();
extern void sub_234720a4();
 

