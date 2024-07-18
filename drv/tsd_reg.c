
#include <stdint.h>
#include "sys_services.h"


/* 2342292c / 2342dd1c - todo */
uint32_t sub_2342292c(int a)
{
	return FREG(0xc8000144 + a * 12)[0] & 1; //TSD01_PTS_1:PTS_MSB
}


/* 23422944 / 2342dd34 - todo */
uint32_t sub_23422944(int a)
{
	return FREG(0xc8800144 + a * 12)[0] & 1; //TSD23_PTS_1:PTS_MSB
}


