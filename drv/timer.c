#include <stdint.h>
#include "sys_services.h"
#include "timer.h"

Struct_235b1c24 Data_235b1c24[10]; //235b1c24


void sub_2341b8bc(int a, int b);
void sub_2341b8e0(int a, int b);
void sub_2341b904(int a, int b);
void sub_2341b924(int a, int b);


/* 2341b5b8 - todo */
void timer_init(void)
{
	unsigned char r4;
	unsigned char r1;
//	int r5 = FAMOS_EnterCriticalSection();

	for (r4 = 0; r4 < 3; r4++)
	{
		//loc_20401f14
		sub_2341b904(r4, 0);
		sub_2341b924(r4, 1);
		sub_2341b8e0(r4, 0);
		sub_2341b8bc(r4, 0);
	}

	for (r1 = 0; r1 < 10; r1++)
	{
		//loc_20401f60
		Data_235b1c24[r1].Data_0 = 0;
		Data_235b1c24[r1].Data_4 = 0;
		Data_235b1c24[r1].Data_8 = 0;
		Data_235b1c24[r1].Data_12 = 0;
		Data_235b1c24[r1].Func_16 = 0;
	}

//	FAMOS_LeaveCriticalSection(r5);
}


/* 2341b64c - complete */
int timer_isr(void)
{
	uint8_t i;

	sub_2341b924(0, 1);

	for (i = 0; i < 10; i++)
	{
		//loc_2341b664
		if (Data_235b1c24[i].Data_0 == 2)
		{
			if (Data_235b1c24[i].Data_4 != 0)
			{
				Data_235b1c24[i].Data_4--;
			}
			else
			{
				Data_235b1c24[i].Data_4 = Data_235b1c24[i].Data_8;

				if (Data_235b1c24[i].Func_16 != 0)
				{
					(Data_235b1c24[i].Func_16)(Data_235b1c24[i].Data_12);
				}
			}
		}
		//loc_2341b6a4
	}

	OSTimeTick();

	return 0;
}


/* 2341b6c0 - todo */
int timer_open(uint32_t r6)
{
	int r4;
	int r8;
	unsigned char r7 = (r6 + 5);

	if (r6 > 3)
	{
		return 1;
	}

//	r8 = FAMOS_EnterCriticalSection();

	if (0 != sys_get_device_id())
	{
		r4 = 80;
	}
	else
	{
		r4 = 98;
	}

	*((volatile uint32_t*)0xcf000004 + r6 * 16) = r4; //FREG_IRQ_CTRL_TIMERXCNTPRE

	sub_2341b8e0(r6, 1);
	sub_2341b8bc(r6, 1);

	*((volatile uint32_t*)0xcf00000c + r6 * 16) = 9999; //FREG_IRQ_CTRL_TIMERXCNTHIGH
	*((volatile uint32_t*)0xcf000008 + r6 * 16) = 0; //FREG_IRQ_CTRL_TIMERXCNTLOW

	intr_set_isr(timer_isr, 0, r7);
	sub_2341b3b8(r7, 0);

	*((volatile uint32_t*)0xe0000200 + r7) = 0x0f; //FREG_VIC_VECTPRIORITYX

	sub_2341b904(r6, 1);

	r6 = 1;

	*((volatile uint32_t*)0xcf000004 + r6 * 16) = r4; //FREG_IRQ_CTRL_TIMERXCNTPRE

	sub_2341b8e0(1, 0);
	sub_2341b8bc(1, 1);

	*((volatile uint32_t*)0xcf00000c + r6 * 16) = 0xFFFFFFFF; //FREG_IRQ_CTRL_TIMERXCNTHIGH
	*((volatile uint32_t*)0xcf000008 + r6 * 16) = 0xFFFFFFFF; //FREG_IRQ_CTRL_TIMERXCNTLOW

	sub_2341b904(1, 1);

//	FAMOS_LeaveCriticalSection(r8);

	return 0;
}

#if 0
/* 2341b7a8 - todo */
Struct_235b1c24* timer_user_open(Timer_Params* r5)
{
	uint32_t r0;
	uint8_t i;
	Struct_235b1c24* r4 = 0;

#if 0
	console_send_string("timer_user_open (todo.c): TODO\r\n");
#endif

	r0 = FAMOS_EnterCriticalSection();

	for (i = 0; i < 10; i++)
	{
		//loc_2341b7c0
		if (Data_235b1c24[i].Data_0 == 0)
		{
			r4 = &Data_235b1c24[i];
			//->loc_2341b7e8
			break;
		}
	}
	//loc_2341b7e8
	if (r4 != 0)
	{
		r4->Data_8 = r4->Data_4 = r5->Data_0;
		r4->Func_16 = r5->Data_8;
		r4->Data_12 = r5->Data_4;
		r4->Data_0 = 1;
	}
	//loc_2341b814
	FAMOS_LeaveCriticalSection(r0);

	return r4;
}


/* 2341b820 - complete */
int timer_user_control(void* h, int r5)
{
	Struct_235b1c24* r4 = h;
	uint32_t r0;

#if 0
	console_send_string("timer_user_control (todo.c): TODO\r\n");
#endif

	r0 = FAMOS_EnterCriticalSection();

	r4->Data_0 = r5? 2: 1;

	r4->Data_4 = r4->Data_8;

	FAMOS_LeaveCriticalSection(r0);

	return 0;
}


/* 2341b85c / - complete */
void* sub_2341b85c(void* h)
{
	Struct_235b1c24* r4 = h;
	uint32_t r0;

#if 0
	console_send_string("timer_user_control (todo.c): TODO\r\n");
#endif

	if (r4 == 0)
	{
		return (void*) -1;
	}

	r0 = FAMOS_EnterCriticalSection();

	r4->Data_0 = 0;

	FAMOS_LeaveCriticalSection(r0);

	return 0;
}


/* 2341b884 / 23426d8c - todo */
uint64_t timer_get_timestamp(uint32_t resolution)
{
	uint64_t counter_current = FREG(0xcf00000c)[1 * 16];
	counter_current = (counter_current << 32) | FREG(0xcf000008)[1 * 16];

	uint64_t counter_start   = 0xFFFFFFFFFFFFFFFFULL;

	counter_current = counter_start - counter_current;

	return counter_current / resolution;
}
#endif


/* 2341b8bc - todo */
void sub_2341b8bc(int a, int b)
{
	int r1 = (b << 2) & (1 << 2);
	volatile uint32_t* r0 = (volatile uint32_t*)0xcf000000 + a * 16;

	*r0 = (*r0 & ~(1 << 2)) | r1; //TimerxEnable_Endless
}


/* 2341b8e0 - todo */
void sub_2341b8e0(int a, int b)
{
	int r1 = (b << 1) & (1 << 1);
	volatile uint32_t* r0 = (volatile uint32_t*)0xcf000000 + a * 16;

	*r0 = (*r0 & ~(1 << 1)) | r1; //TimerxEnable_IrqEnable
}


/* 2341b904 - todo */
void sub_2341b904(int a, int b)
{
	int r1 = (b << 0) & (1 << 0);
	volatile uint32_t* r0 = (volatile uint32_t*)0xcf000000 + a * 16;

	*r0 = (*r0 & ~(1 << 0)) | r1; //SetTimerxEnable_Enable
}


/* 2341b924 - todo */
void sub_2341b924(int a, int b)
{
	int r1 = (b << 0) & (1 << 0);
	volatile uint32_t* r0 = (volatile uint32_t*)0xcf000000 + a * 16;

	r0[6] = (r0[6] & ~(1 << 0)) | r1; //TimerxIrqReset_IrqReset
}

