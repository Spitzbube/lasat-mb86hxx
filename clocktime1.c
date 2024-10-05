
#include <stdint.h>


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


/* 23412e68 /  / 2341a87c - todo */
void clocktime_weekday_next(uint16_t* pWeekday, int b)
{
#if 0
	console_send_string("clocktime_weekday_next (todo.c): TODO\r\n");
#endif

	int8_t day = *pWeekday + b;

	if (day < 1)
	{
		day = 7;
	}
	else if (day > 7)
	{
		day = 1;
	}

	*pWeekday = day;
}


