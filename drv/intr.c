
#include <stdint.h>
#include "ucos_ii.h"
#include "sys_services.h"


int intr_pipeArmStatusHandle = 0; //2349228c
int intr_pipeArmValueHandle = 0; //23492290 +4
int Data_23492294 = 0; //23492294 +8
int Data_23492298 = 0; //23492298 +12
void (*intr_pipeCallbackFunction)(int) = 0; //2349229c +16


typedef void (*ISR)(void);

ISR intr_arFuncs[32]; //235b1b24
int Data_235b1ba4[32]; //235b1ba4 +0x80


/* 2341b29c - complete */
void intr_set_isr(void (*a)(void), int b, int c)
{
	intr_arFuncs[c] = a;
	Data_235b1ba4[c] = b;
}


/* 2341b2b0 - todo */
int intr_isr31()
{
	int value; //r5

#if 0
	console_send_string("intr_isr31\r\n");
#endif

	if (1 == gpreg_read(intr_pipeArmStatusHandle))
	{
		*((volatile uint32_t*)0xcf000304) &= ~(1 << 31);

		if (0 == gpreg_write(intr_pipeArmStatusHandle, 2))
		{
			value = gpreg_read(intr_pipeArmValueHandle);

			if (0 == gpreg_write(intr_pipeArmValueHandle, 0))
			{
				if (intr_pipeCallbackFunction != 0)
				{
					(intr_pipeCallbackFunction)(value);
				}
			}
		}
	}
	//loc_2341b31c
	return 0;
}


/* 2341b324 - todo */
void intr_init()
{
	uint32_t index;
	uint32_t i;

	*((volatile uint32_t*)0xcf000300) = 0; //FREG_IRQ_CTRL_ARMIRQMASK
	*((volatile uint32_t*)0xcf000304) = 0; //FREG_IRQ_CTRL_ARMIRQXOR

	for (i = 0; i < 32; i++)
	{
		//loc_20401c8c
		((volatile uint32_t*)0xe0000200)[i] = 5; //FREG_VIC_VECTPRIORITYX
	}

	*((volatile uint32_t*)0xe0000010) = 0xffffffff; //FREG_VIC_INTENABLE
	*((volatile uint32_t*)0xe000000c) = 0; //FREG_VIC_INTSELECT

// enable the VIC (set the VE bit)
#if !defined(__GNUC__)
	index = 0;
	__asm { mrc p15,0,index,c1,c0,0 };
	index = index | (1UL<<24);
	__asm { mcr p15,0,index,c1,c0,0 };
#else
	index = 0;
	asm volatile( "mrc p15,0,%0,c1,c0,0" : "=r"(index) );
	index = index | (1UL<<24);
	asm volatile( "mcr p15,0,%0,c1,c0,0" : : "r"(index) );
#endif

// enable IRQ and FIQ for current CPU mode
#if !defined(__GNUC__)
    __asm { mrs index,cpsr }
    __asm { bic index,index,#0xC0 }
    __asm { msr cpsr_c,index }
#else
    asm volatile( "mrs %0,cpsr"     : "=r"(index) );
    asm volatile( "bic %0,%1,#0xC0" : "=r"(index) : "r"(index) );
    asm volatile( "msr cpsr_c,%0"   : : "r"(index) );
#endif
}


/* 2341b390 - todo */
uint32_t intr_get_vic_address()
{
	return *((volatile uint32_t*)0xe0000f00); //FREG_VIC_ADDRESS
}


/* 2341b39c - todo */
void intr_set_vic_address(uint32_t a)
{
	*((volatile uint32_t*)0xe0000f00) = a; //FREG_VIC_ADDRESS
}


/* 2341b3a8 - complete */
void intr_set_vectaddrx(int index, int func)
{
	((volatile uint32_t*)0xe0000100)[index] = func; //FREG_VIC_VECTADDRX
}


/* 2341b3b8 - todo */
char sub_2341b3b8(uint32_t a, int b)
{
	uint32_t mask;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	if (a >= 32)
	{
		return -1;
	}

	mask = 1 << a;

	OS_ENTER_CRITICAL();

	if (b != 0)
	{
		*((volatile uint32_t*)0xcf000304) |= mask; //FREG_IRQ_CTRL_ARMIRQXOR
	}
	*((volatile uint32_t*)0xcf000300) |= mask; //FREG_IRQ_CTRL_ARMIRQMASK

	OS_EXIT_CRITICAL();

	return 0;
}


/* 2341b43c - todo */
void intr_init_irq31()
{
#if 0
	console_send_string("intr_init_irq31 (todo.c): TODO\r\n");
#endif

	gpreg_open(2, &intr_pipeArmStatusHandle);
	gpreg_open(3, &intr_pipeArmValueHandle);
	gpreg_open(4, &Data_23492294);
	gpreg_open(5, &Data_23492298);

	intr_arFuncs[31] = intr_isr31;
	Data_235b1ba4[31] = 0;

	sub_2341b3b8(31, 0);

	((volatile uint32_t*)0xe0000200)[31] = 0x0f; //VICVECTPRIORITYX
}


/* 2341b4a4 - complete */
void intr_register_irq31_callback(void (*func)())
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("intr_register_irq31_callback (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	intr_pipeCallbackFunction = func;

	OS_EXIT_CRITICAL();
}


/* 2341b4c0 - todo */
int intr_write_pipe(int r4, int r1)
{
	uint32_t i;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("intr_write_pipe (todo.c): TODO\r\n");
#endif

	if (r1 == 2)
	{
		if (0 != gpreg_write(Data_23492294, 1))
		{
			//->loc_2341b568
			return 1;
		}

		if (0 != gpreg_write(Data_23492298, r4))
		{
			//->loc_2341b568
			return 1;
		}

		OS_ENTER_CRITICAL();

		*((volatile uint32_t*)0xcf000204) |= (1 << 31);

		OS_EXIT_CRITICAL();

		i = 0xfffff;
		while (i--)
		{
			//loc_2341b518
			if (2 == gpreg_read(Data_23492294))
			{
				OS_ENTER_CRITICAL();

				*((volatile uint32_t*)0xcf000204) &= ~(1 << 31);

				OS_EXIT_CRITICAL();

				return 0;
			}
			//loc_2341b544
		}
		//0x2341b54c
		OS_ENTER_CRITICAL();

		*((volatile uint32_t*)0xcf000204) &= ~(1 << 31);

		OS_EXIT_CRITICAL();

		return 11;
	}
	else
	{
		//->loc_2341b568
		return 1;
	}
}


/* 2341b570 - todo */
void sub_2341b570(int r4)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_2341b570 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	int r1 = FREG(0xcf000304)[0];

	if (r4 != 0)
	{
		r1 |= 0x800000;
	}
	else
	{
		r1 &= ~0x800000;
	}

	FREG(0xcf000304)[0] = r1;

	OS_EXIT_CRITICAL();
}


/* 234646a8 - todo */
void OS_CPU_ExceptHndlr(uint32_t irqNr)
{
	uint32_t r5 = intr_get_vic_address();

#if 0
	((volatile uint32_t*)0xc2000000)[0] = 'i';

	switch (irqNr & 0x0f)
	{
	case 0:
		((volatile uint32_t*)0xc2000000)[0] = '0';
		break;
	case 1:
		((volatile uint32_t*)0xc2000000)[0] = '1';
		break;
	case 2:
		((volatile uint32_t*)0xc2000000)[0] = '2';
		break;
	case 3:
		((volatile uint32_t*)0xc2000000)[0] = '3';
		break;
	case 4:
		((volatile uint32_t*)0xc2000000)[0] = '4';
		break;
	case 5:
		((volatile uint32_t*)0xc2000000)[0] = '5';
		break;
	case 6:
		((volatile uint32_t*)0xc2000000)[0] = '6';
		break;
	case 7:
		((volatile uint32_t*)0xc2000000)[0] = '7';
		break;
	}
#endif

	if (((irqNr & 0x0f) == 6) && (((irqNr >> 8) & 0xff) != 0))
	{
#if 0
		switch ((irqNr >> 8) & 0xff)
		{
		case 1:
			((volatile uint32_t*)0xc2000000)[0] = 'a';
			break;
		case 2:
			((volatile uint32_t*)0xc2000000)[0] = 'b';
			break;
		case 3:
			((volatile uint32_t*)0xc2000000)[0] = 'c';
			break;
		case 4:
			((volatile uint32_t*)0xc2000000)[0] = 'd';
			break;
		case 5:
			((volatile uint32_t*)0xc2000000)[0] = 'e';
			break;
		case 6:
			((volatile uint32_t*)0xc2000000)[0] = 'f';
			break;
		case 7:
			((volatile uint32_t*)0xc2000000)[0] = 'g';
			break;
		case 8:
			((volatile uint32_t*)0xc2000000)[0] = 'h';
			break;
		case 9:
			((volatile uint32_t*)0xc2000000)[0] = 'i';
			break;
		case 10:
			((volatile uint32_t*)0xc2000000)[0] = 'j';
			break;
		case 11:
			((volatile uint32_t*)0xc2000000)[0] = 'k';
			break;
		case 12:
			((volatile uint32_t*)0xc2000000)[0] = 'l';
			break;
		case 13:
			((volatile uint32_t*)0xc2000000)[0] = 'm';
			break;
		case 14:
			((volatile uint32_t*)0xc2000000)[0] = 'n';
			break;
		case 15:
			((volatile uint32_t*)0xc2000000)[0] = 'o';
			break;
		case 16:
			((volatile uint32_t*)0xc2000000)[0] = 'p';
			break;
		case 17:
			((volatile uint32_t*)0xc2000000)[0] = 'q';
			break;
		case 18:
			((volatile uint32_t*)0xc2000000)[0] = 'r';
			break;
		case 19:
			((volatile uint32_t*)0xc2000000)[0] = 's';
			break;
		case 20:
			((volatile uint32_t*)0xc2000000)[0] = 't';
			break;
		case 21:
			((volatile uint32_t*)0xc2000000)[0] = 'u';
			break;
		case 22:
			((volatile uint32_t*)0xc2000000)[0] = 'v';
			break;
		case 23:
			((volatile uint32_t*)0xc2000000)[0] = 'w';
			break;
		case 24:
			((volatile uint32_t*)0xc2000000)[0] = 'x';
			break;
		case 25:
			((volatile uint32_t*)0xc2000000)[0] = 'y';
			break;
		case 26:
			((volatile uint32_t*)0xc2000000)[0] = 'z';
			break;
		}
#endif

		{
		void (*pFunc)(void) = intr_arFuncs[(irqNr >> 8) & 0xff];

		OS_CPU_SR_INT_En();

		if (pFunc) pFunc();
		}

		OS_CPU_SR_INT_Dis();
	}
	//loc_234646ec
	intr_set_vic_address(r5);
}

