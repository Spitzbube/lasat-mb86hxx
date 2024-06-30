
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
