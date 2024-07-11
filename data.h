
#include <stdint.h>

#include "sys_services.h"
#include "gpio.h"
#include "uart.h"
#include "console.h"
#include "threads.h"
#include "ucos_ii.h"
#include "memblk.h"

extern MemBlk_Handle* main_hMemBlk2; //23491dc0 +0x34
extern Struct_20611068* main_hUsbGpio; //23491dc4 +0x38 

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


extern void mainfunction_thread();


typedef struct Menu_Item
{
	uint16_t wData_0; //0
	uint16_t wData_2; //2
	int fill_4[5]; //4
	void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
	void* Data_0x1c; //0x1c = 28
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
	void (*Data_0x20)(); //0x20
	void (*Data_0x24)(); //36 = 0x24
	int (*Data_0x28)(); //0x28
	int Data_0x2c; //44 = 0x2c
	int Data_0x30; //48
	Menu_Item* (*Data_0x34)(struct Menu*); //52
	//0x38 = 56?
}
Menu;


int sub_23471fa2(UI_Thread_Params* r4);


