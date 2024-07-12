
#include "data.h"
#include "onoff.h"


volatile uint8_t bData_234920c8 = 0; //234920c8


struct
{
	void* pSema; //0
	int (*Data_4)(int); //4
	int (*Data_8)(int); //8
	void (*Data_12)(int); //12
	void (*Data_16)(int); //16
	int state; //20
	Struct_20611068* pGpio; //24
	int Data_28; //28
	//32
} Data_2358be90;




/* 23413284 / 2341a154 - complete */
int onoff_init(Struct_23413284* r4)
{
	Struct_20401328 gpio;

#if 0
	console_send_string("onoff_init (todo.c): TODO\r\n");
#endif

	memset(&Data_2358be90, 0, sizeof(Data_2358be90));

	Data_2358be90.pSema = OSSemCreate(1);
	Data_2358be90.Data_4 = r4->Data_8;
	Data_2358be90.Data_8 = r4->Data_12;
#if 0
	Data_2358be90.Data_12 = r4->Data_16;
	Data_2358be90.Data_16 = r4->Data_20;
#endif
	Data_2358be90.pGpio = 0;

	if (r4->gpioPin != 0xff)
	{
		//0x234132dc
		gpio.dwOutFunction = 1; //FAPI_GPIO_OUT_1
		gpio.dwInFunction = 0xff;
		gpio.bPin = r4->gpioPin;

		gpio_open(&gpio, &Data_2358be90.pGpio);
	}
	//loc_23413300
	Data_2358be90.state = r4->initialState;

	return 0;
}


