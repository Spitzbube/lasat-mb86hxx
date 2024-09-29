
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


