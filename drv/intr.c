
#include <stdint.h>



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
