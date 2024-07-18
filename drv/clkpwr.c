
#include <stdint.h>
#include "ucos_ii.h"
#include "gpio.h"
#include "i2c.h"
#include "mcu.h"


extern void* main_hI2c0;


/* 23434e00 / 23442e34 - complete */
int clkpwr_mcu_read(Struct_23434e00* r4)
{
	int res;
	uint8_t sp[10];

#if 0
	console_send_string("clkpwr_mcu_read (todo.c): TODO\r\n");
#endif

	res = i2c_master_receive(main_hI2c0, 0x6c, &sp, 10);

	if (res == 0)
	{
#if 0
		for (int i = 0; i < 10; i++)
		{
			extern char debug_string[];
			sprintf(debug_string, "clkpwr_mcu_read: sp[%d]=0x%02x\r\n", i, sp[i]);
			console_send_string(debug_string);
		}
#endif

		r4->bData_8 = sp[0];
		r4->bData_9 = sp[1];
		r4->bData_6 = sp[2];
		r4->bData_7 = sp[3];
		r4->Data_0 = sp[4];
		r4->bData_4 = sp[8];
		r4->bData_5 = sp[9];
	}
#if 0
	else
	{
		console_send_string("clkpwr_mcu_read: i2c read error\r\n");
	}
#endif

	return res;
}


/* 23434e64 / 23442e98 - todo */
void clkpwr_mcu_write(Struct_23434e00* r0, uint8_t r1, uint8_t r2, uint8_t* r3)
{
#if 0
	console_send_string("clkpwr_mcu_write (todo.c): TODO\r\n");
#endif

	uint8_t lr, ip;

	r0->bData_0xa = r2;
	ip = r2;
	r0->bData_0xb = r1;

	lr = 0;

	while (1)
	{
		//loc_23434e78
		if (ip-- != 0)
		{
			r0->Data_12[lr++] = *r3++;
		}
		else
		{
			break;
		}
	}

#if 0 //TODO!!! This will cancel Debugging!
	i2c_master_send(main_hI2c0, 0x6c, &r0->bData_0xa, r2 + 2);
#else
	console_send_string("clkpwr_mcu_write: i2c_master_send disabled!\r\n");
#endif
}


