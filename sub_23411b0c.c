
#include "data.h"
#include "ucos_ii.h"
#include "timer.h"


typedef struct
{
	uint8_t fill_0; //0
	uint8_t bData_1; //1
	uint8_t bData_2; //2
	uint8_t bData_3; //3
	uint8_t bData_4; //4
	int Data_8; //8
	//12
} Struct_2358be5c_Inner0;


typedef struct
{
	Struct_2358be5c_Inner0 Data_0; //0
	Struct_235b1c24* Data_12; //12
	int fill_16[9]; //16
	//0x34 = 52
} Struct_2358be5c;

Struct_2358be5c Data_2358be5c; //2358be5c


uint8_t sub_23412e4c(uint8_t);


/* 23411944 - todo */
void sub_23411944()
{
	console_send_string("sub_23411944 (todo.c): TODO\r\n");

}


/* 23411a14 - complete */
void sub_23411a14()
{
	Timer_Params sp;

#if 0
	console_send_string("sub_23411a14 (todo.c): TODO\r\n");
#endif

	memset(&Data_2358be5c, 0, sizeof(Struct_2358be5c));

	sp.Data_0 = 100;
	sp.Data_8 = sub_23411944;
	sp.Data_4 = 0;

	Data_2358be5c.Data_12 = timer_user_open(&sp);

	if (Data_2358be5c.Data_12 != 0)
	{
		timer_user_control(Data_2358be5c.Data_12, 1);
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


/* 23411d74 - complete */
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


