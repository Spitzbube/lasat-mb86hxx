
#include "data.h"
#include "ucos_ii.h"
#include "timer.h"


//234c0520
int Data_234c0520 = 0; //234c0520


typedef struct
{
	Struct_2358be5c_Inner0 Data_0; //0
	Struct_235b1c24* hTimer; //12
	int fill_16[9]; //16
	//0x34 = 52
} Struct_2358be5c;

Struct_2358be5c Data_2358be5c; //2358be5c /  / 235fb434


uint8_t sub_23412e4c(uint8_t);


/* 23411944 /  / 23419344 - todo */
int clocktime_timer_callback(void)
{
	console_send_string("clocktime_timer_callback (todo.c): TODO\r\n");

	int r5 = ((volatile int*)0xcf000048)[0];

	if (Data_2358be5c.Data_0.bData_4 == 0)
	{
		Data_234c0520 = r5;
		//->loc_2341940c
	}
	else
	{
		//0x23419368
		int64_t r8 = Data_234c0520 - r5;
		uint8_t r3 = 0;

		uint8_t r0 = r8 / 1000000;
		//->loc_234193f4
		while (r0--)
		{
			//loc_2341939c
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

	Data_2358be5c.Data_0.bData_1 = sub_23412e4c(r5[2]);
	Data_2358be5c.Data_0.bData_2 = sub_23412e4c(r5[1]);
	Data_2358be5c.Data_0.bData_3 = sub_23412e4c(r5[0]);
	Data_2358be5c.Data_0.bData_4 = 1;
	Data_2358be5c.Data_0.Data_8 = r6;
}


/* 23411d74 /  / 23419788 - complete */
int sub_23411d74(Struct_2358be5c_Inner0* a)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_23411d74 (todo.c): TODO\r\n");
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
		uint8_t* r1 = &Data_2358be5c.Data_0.bData_1;
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


