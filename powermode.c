
#include "data.h"
#include "powermode.h"

extern void sub_23400510(int); //main

static volatile uint8_t powermode_shutdown_frontend_finished = 0; //234920c8


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


/* 23412ea4 - todo */
int powermode_get_state()
{
	uint8_t sp;
	int r5;

#if 0
	console_send_string("powermode_get_state (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_2358be90.pSema, 0, &sp);

	r5 = Data_2358be90.state;

	sp = OSSemPost(Data_2358be90.pSema);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "powermode_get_state: r5=%d\r\n", r5);
		console_send_string(debug_string);
	}
#endif

	return r5;
}


/* 23412ed4 - todo */
static int powermode_shutdown_frontend_callback()
{
#if 1
	console_send_string("powermode_shutdown_frontend_callback (todo.c): TODO\r\n");
#endif

	powermode_shutdown_frontend_finished = 1;

	return 0;
}


/* 23412ee8 - todo */
void powermode_shutdown_frontend(Struct_2354dd70* a)
{
	if (a != 0)
	{
		uint32_t wait = 100;

		powermode_shutdown_frontend_finished = 0;

		if (0 != fe_manager_shutdown(a, 1, powermode_shutdown_frontend_callback))
		{
			return;
		}
		//->loc_23412f30
		while (wait-- > 0)
		{
			//loc_23412f1c
			if (powermode_shutdown_frontend_finished != 0)
			{
				break;
			}

			rtos_task_wait(3);
		}
	}
}


/* 23412f3c - complete */
void powermode_save_lastmode(int r7)
{
	Struct_234011f4 sp;
	uint32_t oldCrc;

	sub_23438084(Data_23491dc8, &sp, 0, sizeof(Struct_234011f4));

	oldCrc = sp.crc;
	sp.crc = 0;

	if (oldCrc == crc32((void*) &sp, sizeof(Struct_234011f4)))
	{
		sp.crc = 0;
#if 1
		sp.bData_14 = (sp.bData_14 & ~0x0f) | (r7 & 0x0f);
#else
		sp.bData_14_0 = r7;
#endif

		sp.crc = crc32((void*) &sp, sizeof(Struct_234011f4));

		sub_23438108(Data_23491dc8, &sp, 0, sizeof(Struct_234011f4));
	}
	//loc_23412fb8
}


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
				clkpwr_full_power();

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

			powermode_save_lastmode(1);
		}
		break;

	case 2:
		//loc_23413040 -> Switch Off
		powermode_save_lastmode(2);

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
			powermode_save_lastmode(3);

			powermode_shutdown_frontend(main_hFrontend1);
			powermode_shutdown_frontend(Data_23491db8);

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
#endif

			clkpwr_low_power();
			//->loc_23413270
		}
		break;

	case 3:
		//loc_234130d8
		powermode_save_lastmode(3);

		powermode_shutdown_frontend(main_hFrontend1);
		powermode_shutdown_frontend(Data_23491db8);

#if 0
		sub_23400510(1);

		sub_23439d06(1);

		if (Data_2358be90.Data_12 != 0)
		{
			(Data_2358be90.Data_12)(1);
		}

		av_switch_powermode(1);

		gpio_set(Data_2358be90.pGpio, 0);

		sub_23418db0();
#endif

		clkpwr_low_power();
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


/* 23413310 - todo */
int sub_23413310(void* r5, void* r6)
{
	uint8_t err;

#if 0
	console_send_string("sub_23413310 (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_2358be90.pSema, 0, &err);

	Data_2358be90.Data_4 = r5;
	Data_2358be90.Data_8 = r6;

	err = OSSemPost(Data_2358be90.pSema);

	return 0;
}


/* 23413358 - todo */
int sub_23413358(void* r5, void* r6)
{
	uint8_t err;

#if 0
	console_send_string("sub_23413358 (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_2358be90.pSema, 0, &err);

	Data_2358be90.Data_28 = 1;

	err = OSSemPost(Data_2358be90.pSema);

	return 0;
}


