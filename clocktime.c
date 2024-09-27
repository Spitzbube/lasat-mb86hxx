
#include "data.h"
#include "ucos_ii.h"
#include "timer.h"
#include "clocktime.h"


//234c0520
uint32_t Data_234c0520 = 0; //234c0520


typedef struct
{
	Clock_Time Data_0; //0
	Struct_235b1c24* hTimer; //12
	int Data_0x10; //0x10
	int Data_0x14; //0x14
	int fill_0x18[7]; //0x18 = 24
	//0x34 = 52
} Struct_2358be5c;

Struct_2358be5c Data_2358be5c; //2358be5c /  / 235fb434


uint8_t sub_23412e4c(uint8_t);


/* 23411944 /  / 23419344 - todo */
int clocktime_timer_callback(void)
{
#if 0
	console_send_string("clocktime_timer_callback (todo.c): TODO\r\n");
#endif

	uint32_t r5 = ((volatile int*)0xcf000048)[0]; //TIMER1_CNT_LOW

	if (Data_2358be5c.Data_0.bData_4 == 0)
	{
		Data_234c0520 = r5;
		//->loc_2341940c
	}
	else
	{
		//0x23419368
		//int64_t r0_r1 = Data_234c0520;
		//int64_t r5_r6 = r5;
		uint32_t diff = (uint64_t)Data_234c0520 - (uint64_t)r5;
		int64_t mill = 1000000;

		uint8_t r0 = /*(r0_r1 - r5_r6)*/(int64_t)(/*Data_234c0520 - r5*/diff) / mill;
		//->loc_234193f4
		while (r0--)
		{
			//loc_2341939c
			Data_2358be5c.Data_0.seconds++;
			if (Data_2358be5c.Data_0.seconds >= 60)
			{
				Data_2358be5c.Data_0.seconds = 0;
				Data_2358be5c.Data_0.minutes++;
				if (Data_2358be5c.Data_0.minutes >= 60)
				{
					Data_2358be5c.Data_0.minutes = 0;
					Data_2358be5c.Data_0.hours++;
					if (Data_2358be5c.Data_0.hours >= 24)
					{
						Data_2358be5c.Data_0.hours = 0;
						Data_2358be5c.Data_0.Data_8++;
					}
				}
			}
		}
		//0x23419404
		Data_234c0520 = r5 + 1000000;
	}
	//loc_2341940c
	return 0;
}


/* 23411a14 /  / 23419414 - complete */
void clocktime_init(void)
{
	Timer_Params timer_params;

#if 0
	console_send_string("clocktime_init (todo.c): TODO\r\n");
#endif

	memset(&Data_2358be5c, 0, sizeof(Struct_2358be5c));

	timer_params.Data_0 = 100;
	timer_params.Data_8 = clocktime_timer_callback;
	timer_params.Data_4 = 0;

	Data_2358be5c.hTimer = timer_user_open(&timer_params);

	if (Data_2358be5c.hTimer != 0)
	{
		timer_user_control(Data_2358be5c.hTimer, 1);
	}
}


/* 23411b0c - complete */
void sub_23411b0c(int r6, uint8_t* r5)
{
#if 0
	console_send_string("sub_23411b0c (todo.c): TODO\r\n");
#endif

	Data_2358be5c.Data_0.seconds = sub_23412e4c(r5[2]);
	Data_2358be5c.Data_0.minutes = sub_23412e4c(r5[1]);
	Data_2358be5c.Data_0.hours = sub_23412e4c(r5[0]);
	Data_2358be5c.Data_0.bData_4 = 1;
	Data_2358be5c.Data_0.Data_8 = r6;
}


/* 23411d74 /  / 23419788 - complete */
int clocktime_get(Clock_Time* a)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("clocktime_get (todo.c): TODO\r\n");
#endif

	if (a == 0)
	{
		return 1;
	}

	OS_ENTER_CRITICAL();

	*a = Data_2358be5c.Data_0;

	OS_EXIT_CRITICAL();

	return 0;
}


/* 23411da0 /  / 234197b4 - todo */
void sub_23411da0()
{
#if 1
	console_send_string("sub_23411da0 (todo.c): TODO\r\n");
#endif

}


typedef struct
{
	int fill_0[3]; //0
	int Data_0xc; //12
	int fill_0x10[2]; //0x10
	uint16_t wData_0x18; //0x18
	uint16_t wData_0x1a; //0x1a
	uint16_t wData_0x1c; //0x1c
	//32 = 0x20
} Struct_23419f50;


/* 2341253c /  / 23419f50 - complete */
int sub_23419f50(Struct_23419f50* r4, uint16_t r5)
{
#if 0
	console_send_string("sub_23419f50 (todo.c): TODO\r\n");
#endif

#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	Clock_Time sp;

	if (r5 == 49)
	{
		r5 = 24;

		OS_ENTER_CRITICAL();

		r5 += Data_2358be5c.Data_0x10 * 2;

		OS_EXIT_CRITICAL();
	}
	//loc_2341256c
	memset(r4, 0, sizeof(Struct_23419f50));

	clocktime_get(&sp);

	if ((sp.bData_4 == 0) ||
		((r5 == 49) && (Data_2358be5c.Data_0x14 == 0)))
	{
		//loc_2341259c
		return 4;
	}
	//loc_234125a4
	r4->Data_0xc = sp.Data_8;

	sub_23412444(r4);

	r4->wData_0x18 = sp.hours;
	r4->wData_0x1a = sp.minutes;
	r4->wData_0x1c = sp.seconds;

	sub_23412148(r4, r5);

	return 0;
}


/* 23412da8 - todo */
int sub_23412da8(void)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	uint16_t r4 = (0x16 << 11) | (0x16 << 5); //0xB2C0;

#if 0
	console_send_string("sub_23412da8 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	if (Data_2358be5c.Data_0.bData_4 != 0)
	{
		uint8_t* r1 = &Data_2358be5c.Data_0.seconds;
		r4 = *(r1+0);
		r4 |= (*(r1+1) << 5);
		r4 |= (*(r1+2) << 11);
	}

	OS_EXIT_CRITICAL();

	return r4;
}


/* 23412e4c - todo */
uint8_t sub_23412e4c(uint8_t a)
{
#if 0
	console_send_string("sub_23412e4c (todo.c): TODO\r\n");
#endif

	uint8_t res = (a >> 4);
	res = res * 10 + (a & 0x0f);
	return res;
}


