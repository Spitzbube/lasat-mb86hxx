
#include <stdint.h>

extern void* OS_CPU_ExceptStk; //23487950
int Data_234942a8 = 0; //234942a8 +0
void* OS_CPU_ExceptStkBase; //234942ac +4
int Data_234942b0; //234942b0 +8


/* 23464598 - todo */
void OSInitHookBegin()
{
	uint32_t size;
	uint32_t* pstk;

	pstk = OS_CPU_ExceptStk;
	size = 0x1ff;
	while (size--)
	{
		*pstk++ = 0;
	}

	OS_CPU_ExceptStkBase = OS_CPU_ExceptStk;
	*(((uint32_t*)OS_CPU_ExceptStk) - 0x200) = 0x12345678;
}


/* 234645cc - complete */
void OSInitHookEnd()
{
#if 0
	((volatile uint32_t*)0xc2000000)[0] = '1';
#endif
}


/* 234645d0 - complete */
void OSTaskCreateHook()
{
#if 0
	((volatile uint32_t*)0xc2000000)[0] = '2';
#endif
}


/* 234645d8 / 23477714? - todo */
void OSTaskIdleHook()
{
	if (Data_234942a8 != 0)
	{
		Data_234942a8--;
	}
	else
	{
		usb_RunBackground();

		Data_234942a8 = 100;
	}

	*((volatile uint32_t*)0xca00003c) = 0x1000; //FREG_CLKPWR_WATCHDOG
}


/* 23464610 - complete */
void OSTCBInitHook()
{
#if 0
	((volatile uint32_t*)0xc2000000)[0] = '3';
#endif
}


/* 23464614 - todo */
uint32_t OSTaskStkInit(void (*func)(int), int b, uint32_t* stack, int d)
{
	*stack-- = (unsigned int)func & ~1;
	*stack-- = 0x14141414;
	*stack-- = 0x12121212;
	*stack-- = 0x11111111;
	*stack-- = 0x10101010;
	*stack-- = 0x09090909;
	*stack-- = 0x08080808;
	*stack-- = 0x07070707;
	*stack-- = 0x06060606;
	*stack-- = 0x05050505;
	*stack-- = 0x04040404;
	*stack-- = 0x03030303;
	*stack-- = 0x02020202;
	*stack-- = 0x01010101;
	*stack-- = b;
	*stack = ((uint32_t)func & 1)? 0x33: 0x13;

	return (uint32_t)stack;
}


/* 234646a0 - complete */
void OSTaskSwHook()
{
#if 0
	((volatile uint32_t*)0xc2000000)[0] = '4';
#endif
}


/* 234646a4 - complete */
void OSTimeTickHook()
{
#if 0
	((volatile uint32_t*)0xc2000000)[0] = '5';
#endif
}


