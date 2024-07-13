
#include "data.h"
#include "powermode.h"

extern void sub_23400510(int); //main

volatile uint8_t bData_234920c8 = 0; //234920c8


typedef struct
{
	void* pSema; //0
	int (*Data_4)(int); //4
	int (*Data_8)(int); //8
#if 0
	void (*Data_12)(int); //12
	void (*Data_16)(int); //16
#endif
	int state; //20
	Struct_20611068* pGpio; //24
	int Data_28; //28
	//32
} Powermode_Data;


Powermode_Data Data_2358be90; //2358be90


/* 23412fbc - todo */
int powermode_set_state(int state/*r5*/, UI_Thread_Params* r4, void* pFunc/*r7*/)
{
	uint8_t err; //sp
	void (*sb)();
	int ret = 0; //r8

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "powermode_set_state: state=%d, r4=%p, pFunc=%p\r\n", state, r4, pFunc);
		console_send_string(debug_string);
	}
#endif

	if (Data_2358be90.pSema == 0)
	{
		//->loc_23413280
		return -1;
	}

	OSSemPend(Data_2358be90.pSema, 0, &err);
	if (err != 0)
	{
		return 0; //ret
	}

	sb = 0;

	switch (state)
	{
	case 1:
		//loc_23413138 -> Switch On
#if 0
		if ((Data_2358be90.Data_8 != 0) &&
				(0 != (Data_2358be90.Data_8)(0)))
		{
			//loc_23413154
			ret = -1;
			//->loc_23413270
		}
		else
#endif
		{
			//loc_2341315c
			if (Data_2358be90.state != 6)
			{
#if 0
				clkpwr_full_power();
#endif

				rtos_task_wait(10);

				gpio_set(Data_2358be90.pGpio, 1);

				rtos_task_wait(1);

				sub_23400510(0);

#if 0
				if (Data_2358be90.Data_12 != 0)
				{
					(Data_2358be90.Data_12)(0);
				}

				sub_23439d06(0);
#endif
			}
			//loc_234131a8
			Data_2358be90.state = 1;

			av_switch_powermode(0);

#if 0
			if (Data_2358be90.Data_16 != 0)
			{
				(Data_2358be90.Data_16)(0);
			}
#endif

			if (r4 != 0)
			{
				r4->threadFunc = pFunc;
				r4->Data_20 = sb;

				ui_thread_create(r4);
			}

#if 0
			sub_23412f3c(1);
#endif
		}
		break;

	case 2:
		//loc_23413040 -> Switch Off
#if 0
		sub_23412f3c(2);
#endif

		Data_2358be90.state = 2;

		if (r4 != 0)
		{
			r4->threadFunc = pFunc;
			r4->Data_20 = sb;

			ui_thread_create(r4);
		}

#if 0
		sub_2340b22c(0xff);

		if (Data_2358be90.Data_16 != 0)
		{
			(Data_2358be90.Data_16)(1);
		}

		if (Data_2358be90.Data_28 == 0)
		{
			gpio_set(Data_2358be90.pGpio, 0);
		}

		if ((Data_2358be90.Data_4 != 0) &&
				((Data_2358be90.Data_4)(0) != 0))
		{
			sub_23400510(1);

			sub_23439d06(1);

			if (Data_2358be90.Data_12 != 0)
			{
				(Data_2358be90.Data_12)(1);
			}

			av_switch_powermode(1);
			//->loc_23413270
		}
		else
#endif
		{
			//loc_234130d8
#if 0
			sub_23412f3c(3);

			sub_23412ee8(Data_23491db4);
			sub_23412ee8(Data_23491db8);
#endif

			sub_23400510(1);

#if 0
			sub_23439d06(1);

			if (Data_2358be90.Data_12 != 0)
			{
				(Data_2358be90.Data_12)(1);
			}
#endif

			av_switch_powermode(1);

			gpio_set(Data_2358be90.pGpio, 0);

#if 0
			sub_23418db0();

			clkpwr_low_power();
#endif
			//->loc_23413270
		}
		break;

	case 3:
		//loc_234130d8
#if 0
		sub_23412f3c(3);

		sub_23412ee8(Data_23491db4);
		sub_23412ee8(Data_23491db8);

		sub_23400510(1);

		sub_23439d06(1);

		if (Data_2358be90.Data_12 != 0)
		{
			(Data_2358be90.Data_12)(1);
		}

		av_switch_powermode(1);

		gpio_set(Data_2358be90.pGpio, 0);

		sub_23418db0();

		clkpwr_low_power();
#endif
		//->loc_23413270
		break;

	case 6:
		//0x23413020
#if 0
		if ((Data_2358be90.Data_8 != 0) &&
				(0 != (Data_2358be90.Data_8)(0)))
		{
			//loc_23413154
			ret = -1;
			//->loc_23413270
		}
		else
		{
			//loc_234131e8
			if (Data_2358be90.state != 1)
			{
				//0x234131f4
				clkpwr_full_power();

				rtos_task_wait(10);

				gpio_set(Data_2358be90.pGpio, 1);

				rtos_task_wait(1);

				sub_23400510(0);

				if (Data_2358be90.Data_12 != 0)
				{
					(Data_2358be90.Data_12)(0);
				}

				sub_23439d06(0);
			}
			//loc_23413234
			Data_2358be90.state = 6;

			av_switch_powermode(1);

			if (Data_2358be90.Data_16 != 0)
			{
				(Data_2358be90.Data_16)(1);
			}

			sub_2341122c(1);

			if (r4 != 0)
			{
				r4->threadFunc = pFunc;
				r4->Data_20 = sb;

				ui_thread_create(r4);
			}
			//loc_23413270
		}
#endif
		break;

	default:
		//->loc_23413270
		break;
	}
	//loc_23413270
	err = OSSemPost(Data_2358be90.pSema);

	return ret;
}


/* 23413284 / 2341a154 - complete */
int powermode_init(Powermode_Init_Params* pParams)
{
	Struct_20401328 gpio;

#if 0
	console_send_string("powermode_init (todo.c): TODO\r\n");
#endif

	memset(&Data_2358be90, 0, sizeof(Data_2358be90));

	Data_2358be90.pSema = OSSemCreate(1);
	Data_2358be90.Data_4 = pParams->Data_8;
	Data_2358be90.Data_8 = pParams->Data_12;
#if 0
	Data_2358be90.Data_12 = pParams->Data_16;
	Data_2358be90.Data_16 = pParams->Data_20;
#endif
	Data_2358be90.pGpio = 0;

	if (pParams->gpioPin != 0xff)
	{
		//0x234132dc
		gpio.dwOutFunction = 1; //FAPI_GPIO_OUT_1
		gpio.dwInFunction = 0xff;
		gpio.bPin = pParams->gpioPin;

		gpio_open(&gpio, &Data_2358be90.pGpio);
	}
	//loc_23413300
	Data_2358be90.state = pParams->initialState;

	return 0;
}


