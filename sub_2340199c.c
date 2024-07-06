
#include "data.h"


//23491e10
uint32_t Data_23491e10 = 0x00400000; //0
uint32_t Data_23491e14 = 0x01bffc00; //4


/* 2340199c - todo */
uint32_t sub_2340199c(uint32_t a)
{
	uint32_t r1 = Data_23491e10;

#if 0
	console_send_string("sub_2340199c (todo.c): TODO\r\n");
#endif

	if (a % 1024)
	{
		a = (a / 1024) * 1024 + 1024;
	}

	a += r1;

	if ((a & ~0xf0000000) <= 0x1bffc00)
	{
		Data_23491e10 = a;
		return r1;
	}
	else
	{
		while (1) {}
	}
}


/* 234019e0 - todo */
uint32_t sub_234019e0(uint32_t a)
{
	uint32_t r1 = Data_23491e14;

#if 0
	console_send_string("sub_2340199c (todo.c): TODO\r\n");
#endif

	if (a % 4)
	{
		a = (a / 4) * 4 + 4;
	}

	a += r1;

	if ((a & ~0xf0000000) <= 0x2000000)
	{
		Data_23491e14 = a;
		return r1 | 0x20000000;
	}
	else
	{
		while (1) {}
	}
}

