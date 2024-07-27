
#include "data.h"
#include "mcu.h"


//234920e4
uint8_t bData_234920e4 = 0; //234920e4 +0

Struct_23434e00 Data_235b0c4c; //235b0c4c


/* 23418db0 - complete */
int sub_23418db0()
{
	int r4;
	Struct_235441b0 sp4;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_23418db0 (todo.c): TODO\r\n");
#endif

	if (Data_235b0c4c.bData_8 == 0)
	{
		//loc_23418de0
		return 8;
	}

	sub_2340c970(1, &sp4); //Get settings

	if (sp4.Data_0x10 & (1 << 6)) //Deep standby
	{
		//loc_23418de0
		return 8;
	}
	//loc_23418dec
	OS_ENTER_CRITICAL();

	r4 = bData_234920e4;

	OS_EXIT_CRITICAL();

	if (r4 == 0)
	{
		clkpwr_mcu_write(&Data_235b0c4c, 0xaa, 0, 0);
	}

	return 0;
}


/* 23418e1c - complete */
int sub_23418e1c(uint8_t* r4)
{
#if 0
	console_send_string("sub_23418e1c (todo.c): TODO\r\n");
#endif

	memset(&Data_235b0c4c, 0, sizeof(Data_235b0c4c));

	if (0 == clkpwr_mcu_read(&Data_235b0c4c))
	{
		*r4 = Data_235b0c4c.bData_6;

		return 0;
	}

	return 8;
}


/* 23418e54 - todo */
void sub_23418e54()
{
	console_send_string("sub_23418e54 (todo.c): TODO\r\n");

}


/* 23418e98 / 23423734 - complete */
int sub_23418e98()
{
#if 0
	console_send_string("sub_23418e98 (todo.c): TODO\r\n");
#endif

	return Data_235b0c4c.bData_7;
}


