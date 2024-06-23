
#include <stdint.h>

typedef void (*ISR)(void);

ISR intr_arFuncs[32]; //235b1b24
int Data_235b1ba4[32]; //235b1ba4 +0x80


/* 2341b29c - complete */
void intr_set_isr(void (*a)(void), int b, int c)
{
	intr_arFuncs[c] = a;
	Data_235b1ba4[c] = b;
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
	int r0;
	uint32_t mask;

	if (a >= 32)
	{
		return -1;
	}

	mask = 1 << a;

//	r0 = FAMOS_EnterCriticalSection();

	if (b != 0)
	{
		*((volatile uint32_t*)0xcf000304) |= mask; //FREG_IRQ_CTRL_ARMIRQXOR
	}
	*((volatile uint32_t*)0xcf000300) |= mask; //FREG_IRQ_CTRL_ARMIRQMASK

//	FAMOS_LeaveCriticalSection(r0);

	return 0;
}


/* 234646a8 - todo */
void OS_CPU_ExceptHndlr(uint32_t irqNr)
{
	uint32_t r5 = intr_get_vic_address();

#if 1
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
#if 1
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

