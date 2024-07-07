
#include <stdint.h>
#include "gpio.h"


//23492694
uint8_t bData_23492694; //23492694 +0
uint16_t wData_23492696; //23492696 +2
uint16_t wData_23492698; //23492698 +4
uint16_t wData_2349269a; //2349269a +6
uint32_t Data_2349269c; //2349269c +8
void (*Data_234926a0)(uint16_t, uint16_t, int); //234926a0 +c

uint16_t arData_235f3234[256]; //235f3234, size?


/* 2342e320 - todo */
void ir_isr()
{
#if 0
	console_send_string("ir_isr\r\n");
#endif

	while (1)
	{
		//loc_2342e330
		uint32_t r4 = *((volatile uint32_t*) 0xc1000008); //FREG_IR_RRECEIVE
		if ((r4 & 0xff) > 10)
		{
			arData_235f3234[wData_23492696++] = r4;
			wData_23492696 &= 0xff;
		}
		//loc_2342e35c
		if ((~r4 & 0xff) != 0)
		{
			*((volatile uint32_t*) 0xc1000000) = 0x77; //FREG_IR_RCONFIG
			//->loc_2342e3a4
		}
		else
		{
			int r1;

			*((volatile uint32_t*) 0xc1000000) = 0x7f; //FREG_IR_RCONFIG
			*((volatile uint32_t*) 0xc1000000) = 0x77; //FREG_IR_RCONFIG

			r1 = wData_23492696 - wData_23492698;
			if (r1 < 0)
			{
				r1 += 256;
			}

			if (Data_234926a0 != 0)
			{
				(Data_234926a0)(wData_23492698, r1, 0);
			}

			wData_23492698 = wData_23492696;
		}

		if ((r4 >> 9) == 0) break;
	}

}


/* 2342e3b0 - todo */
void sub_2342e3b0(int a)
{
#if 0
	console_send_string("sub_2342e3b0 (todo.c): TODO\r\n");
#endif

	bData_23492694 = a;

}


/* 2342e3bc - todo */
void sub_2342e3bc()
{
	uint32_t key;

#if 0
	console_send_string("sub_2342e3bc (todo.c): TODO\r\n");
#endif

	if (bData_23492694 != 0)
	{
		bData_23492694--;
		return;
	}

	key = *((volatile uint32_t*)0xc100003c); //FPC_Key

	if (Data_2349269c != key)
	{
		if (Data_234926a0 != 0)
		{
			(Data_234926a0)(0, (uint16_t)key, 1);
		}
	}

	Data_2349269c = key;
}


/* 2342e408 - todo */
int ir_init(void *func, int b)
{
	Struct_20611068* sp0xc;
	Struct_20401328 sp;

	sp.dwOutFunction = 0xff;
	sp.dwInFunction = 13; //FAPI_GPIO_IN_IR_DATA
	sp.bPin = b;

	gpio_open(&sp, &sp0xc);

	Data_234926a0 = func;

	intr_set_isr(ir_isr, 0, 14);
	sub_2341b3b8(14, 0);

	((volatile uint32_t*) 0xe0000200)[14] = 0x0f; //FREG_VIC_VECTPRIORITYX
	*((volatile uint32_t*) 0xc1000004) = 0xc4e; //FREG_IR_RPRESCALER
	*((volatile uint32_t*) 0xc1000000) = 0x7f; //FREG_IR_RCONFIG
	*((volatile uint32_t*) 0xc1000000) = 0x77; //FREG_IR_RCONFIG

	return 0;
}


/* 2342e488 - todo */
int sub_2342e488(int a, int b)
{
	int r0;

	if (b != 0)
	{
		wData_2349269a = a;
		return 0;
	}

	r0 = arData_235f3234[wData_2349269a++];
	wData_2349269a &= 0xff;

	return r0;
}

