
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
