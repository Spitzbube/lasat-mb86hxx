

#include "data.h"
#include "sub_2340a6a0.h"
#include "frontend.h"
#include "fe_manager.h"


typedef struct
{
	int (*Data_0)(); //0
	int (*Data_4)(); //4
	int fill_8[9]; //8
	//0x2c = 44
} sub_2340e754_1;


//23492080
uint8_t bData_23492080 = 0; //23492080 +0
uint8_t fe_manager_threadPrio = 0; //23492081 +1
uint8_t Data_23492084[4] = {0}; //23492084 +4
void* fe_manager_pSema = 0; //23492088 +8
Struct_20611068* Data_2349208c/*hGpio*/ = 0; //2349208c +12

int fe_manager_threadStack[THREAD_STACK_SIZE_FE_MANAGER]; //2354cdd0 ->2354DD70
Struct_2354dd70 Data_2354dd70[2];


/* 2340dc48 - complete */
int frontend_reset_by_gpio(Struct_2354dd70* r4)
{
#if 0
	console_send_string("frontend_reset_by_gpio\r\n");
#endif

	if (r4->resetGpio == (void*)0xff)
	{
		return 0xff;
	}

	gpio_set(r4->resetGpio, 1);
	rtos_task_wait(1);
	gpio_set(r4->resetGpio, 0);
	rtos_task_wait(1);
	gpio_set(r4->resetGpio, 1);
	rtos_task_wait(1);

	return 0;
}


/* 2340dc9c - todo */
void sub_2340dc9c()
{
	console_send_string("sub_2340dc9c (filter_manager.c): TODO\r\n");

}


/* 2340dce8 - todo */
void sub_2340dce8()
{
	console_send_string("sub_2340dce8 (filter_manager.c): TODO\r\n");

}

typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	int Data_12; //12
	int Data_16; //16
	int Data_20; //20
} Struct_2340dd74;


/* 2340dd74 - todo */
int sub_2340dd74(Struct_2354dd70* r4)
{	
#if 0
	console_send_string("sub_2340dd74 (filter_manager.c): TODO\r\n");
#endif

	r4->bData_0x9f = 1;

	(r4->Data_0x30.Data_4)(r4->bData_0xd9, 
		 r4->Data_0xc8 & 0xff,
		 r4->Data_0xc4 & 0xff, 0, 
		 r4->hI2c,
		 r4->resetGpio,
		 r4->Data_0xa4,
		 r4->Data_0xa8,
		 r4->Data_0xb0,
		 r4->Data_0xac);

	(r4->Data_0x30.Data_0x10)(&r4->bData_0x9d);
	(r4->Data_0x30.Data_0x14)(&r4->bData_0x9e);
	(r4->Data_0x30.Data_0x18)(&r4->Data_0x94);

	if (r4->Data_0x5c != 0)
	{
		(r4->Data_0x5c)(&r4->Data_0x94);
	}

#if 0
sub_234483e8 (todo.c): TODO
sub_23402d0c (todo.c): TODO
sub_23403160 (todo.c): TODO
sub_2347192c (todo.c): TODO
#endif

	return 0;
}


/* 2340de08 - todo */
int frontend_cable_thread_func(Struct_2354dd70* r4)
{
#if 0
	console_send_string("frontend_cable_thread_func: TODO\r\n");
#endif

	if (r4->bState != 5)
	{
		(r4->Data_0x30.Data_4)(r4->bData_0xd9, r4->Data_0xc8 & 0xff, r4->Data_0xc4 & 0xff, 0,
				r4->hI2c, r4->resetGpio,
				r4->Data_0xa4, r4->Data_0xa8,
				r4->Data_0xb0, r4->Data_0xac);

#if 0
		if (r4->bState != 0)
		{
			extern char debug_string[];
			sprintf(debug_string, "frontend_cable_thread_func: r4->bState=%d\r\n", r4->bState);
			console_send_string(debug_string);
		}
#endif

		if (r4->bState == 4)
		{
			r4->bState = 5; //r5

			memcpy(&r4->Data_0x64, &r4->Data_0x7c, 24);

			(r4->Data_0x30.Data_0x1c)(r4->Data_0x64.Data_0.frequency);

			if (r4->stateChangeCallback != 0)
			{
				(r4->stateChangeCallback)(0, &r4->Data_0x64);
			}

			Data_23492084[r4->bData_0xd9] = 1; //r6
		} //if (r4->bState == 4)
		//loc_2340deb4
		if (r4->bState == 1) //Start Tune
		{
			void* sb;

			memcpy(&r4->Data_0x64, &r4->Data_0x7c, 24);

			sb = &r4->Data_0x64;

			if (Data_23492084[r4->bData_0xd9] != 0)
			{
				(r4->Data_0x30.Data_0)();

				Data_23492084[r4->bData_0xd9] = 0; //r7
			}
			//loc_2340def8
			if (0 == (r4->Data_0x30.Data_8)(sb))
			{
				r4->bData_0x9c = 0; //r7
				r4->bState = 2;
				r4->wData_0xd4 = 5; //r5
				//->loc_2340df28
			}
			//loc_2340df1c
		} //if (r4->bState == 1)
		//loc_2340df1c
		if (r4->bState == 2) //Check Lock
		{
			//loc_2340df28
			uint8_t r8 = r4->bData_0x9c;

			if (0 != (r4->Data_0x30.Data_0x0c)(&r4->bData_0x9c))
			{
				r4->bData_0x9c = 0; //r7
				//->loc_2340dfb0
			}
			else
			{
				//0x2340df44
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "frontend_cable_thread_func: r8=%d, r4->bData_0x9c=%d\r\n", 
							r8, r4->bData_0x9c);
					console_send_string(debug_string);
				}
#endif

				if (r8 != r4->bData_0x9c)
				{
					if (r4->bData_0x9c == 0)
					{
						//0x2340df58
						if (r4->stateChangeCallback != 0)
						{
							(r4->stateChangeCallback)(0x0f, &r4->Data_0x64);
							//loc_2340df8c
						}
						//loc_2340df98
					}
					else
					{
						//loc_2340df70
						r4->wData_0xd4 = 5; //r5;

						if (r4->stateChangeCallback != 0)
						{
							(r4->stateChangeCallback)(0x00, &r4->Data_0x64);
							//loc_2340df8c
						}
						//loc_2340dfb0
					}
				} //if (r8 != r4->bData_0x9c)
				//loc_2340df8c
				if (r4->bData_0x9c == 0)
				{
					//loc_2340df98: Fall back to tune state after configured number of cycles
					r4->wData_0xd4--;

					if (r4->wData_0xd4 < 0)
					{
						r4->bState = 1; // r6;
					}
				}
				//loc_2340dfb0
			}
		} //if (r4->bState == 2)
		//loc_2340dfb0
	}
	//loc_2340dfb0
	return 0;
}


/* 2340dfbc - todo */
void sub_2340dfbc()
{
	console_send_string("sub_2340dfbc (filter_manager.c): TODO\r\n");

}


/* 2340e054 - todo */
void sub_2340e054()
{
	console_send_string("sub_2340e054 (filter_manager.c): TODO\r\n");

}


/* 2340e23c - todo */
void sub_2340e23c()
{
	console_send_string("sub_2340e23c (filter_manager.c): TODO\r\n");

}


/* 2340e274 - todo */
void sub_2340e274()
{
	console_send_string("sub_2340e274 (filter_manager.c): TODO\r\n");

}


/* 2340e604 - todo */
void frontend_thread()
{
	uint8_t sp;
	Struct_2354dd70* r4;
	int r5 = 0;

	while (1)
	{
		//loc_2340e61c
		OSSemPend(fe_manager_pSema, 0, &sp);

#if 0
    	console_send_string("frontend_thread (fe_manager.c): TODO\r\n");
#endif

		r4 = &Data_2354dd70[r5];

		if (r4->threadFunc != 0)
		{
			(r4->threadFunc)(r4);
		}

		if (r4->Data_0x5c != 0)
		{
			if (r4->Data_0x58 != 0)
			{
				(r4->Data_0x58)(r4);
			}
		}

		r5 = 1 & ~r5;

		OSSemPost(fe_manager_pSema);

		rtos_task_wait(5);
	} //while (1)
}


/* 2340e674 - todo */
int fe_manager_init(fe_manager_Params* pParams)
{
	uint8_t i;
	Struct_20401328 gpioParams;

#if 0
	console_send_string("fe_manager_init (filter_manager.c): TODO\r\n");
#endif

	if (fe_manager_pSema != 0)
	{
		return 4;
	}

	for (i = 0; i < 2; i++)
	{
		//loc_2340e6a4
		Data_2354dd70[i].bState = 0xff;
		Data_2354dd70[i].threadFunc = 0;
	}
	//0x2340e6c4
	fe_manager_pSema = OSSemCreate(1);

	fe_manager_threadPrio = pParams->threadPrio;

	if (pParams->gpioPin != 0xff)
	{
		struct
		{
			int fill_0; //0
			uint32_t Data_4; //4
			int fill_8[2]; //8
			int Data_16; //16
			int fill_20[2]; //20
			//28 = 0x1c
		} sp;

		channel_handle_user_settings(1, &sp);

		gpioParams.dwInFunction = 0xff;
		gpioParams.dwOutFunction = (sp.Data_4 << 13) >> 31; //TODO
		gpioParams.bPin = pParams->gpioPin;

		gpio_open(&gpioParams, &Data_2349208c);
	}
	//loc_2340e718
	OSTaskCreateExt(frontend_thread, 0, &fe_manager_threadStack[THREAD_STACK_SIZE_FE_MANAGER-1],
			pParams->threadPrio & 0xff, pParams->threadPrio,
			fe_manager_threadStack, THREAD_STACK_SIZE_FE_MANAGER, "FILTER_MANAGER", 3);

	return 0;
}


/* 2340e754 - todo */
Struct_2354dd70* fe_manager_detect(Struct_2340e754* r5, sub_2340e754_1* r8)
{
	uint8_t sp_0x28;
	Struct_20401328 sp_0x1c;
	uint8_t i;
	Struct_2354dd70* r4 = 0;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "fe_manager_detect: r5->Data_4=%d\r\n", r5->Data_4);
		console_send_string(debug_string);
	}
#endif

	OSSemPend(fe_manager_pSema, 0/*r4*/, &sp_0x28);

	//sb = 0x2354dd70;

	for (i = 0; i < 2; i++)
	{
		//loc_2340e788
		if (Data_2354dd70[i].bState == 0xff)
		{
			r4 = &Data_2354dd70[i];
			//->loc_2340e7b4
			break;
		}
	}
	//loc_2340e7b4
	do
	{
		if (r4 == 0)
		{
#if 0
			console_send_string("fe_manager_detect (filter_manager.c): error 1\r\n");
#endif
			//->loc_2340e8d8
			break;
		}

		//0x2340e7bc
		r4->resetGpio = (void*) 0xff;
		r4->Data_0xa4 = (void*) 0xff;
		r4->Data_0xa8 = (void*) 0xff;
		r4->Data_0xbc = (void*) 0xff;
		r4->Data_0xac = (void*) 0xff;
		r4->Data_0xb0 = (void*) 0xff;
		r4->Data_0xb4 = 0xff;
		r4->Data_0xb8 = (void*) 0xff;
		r4->bData_0xcc = 0; //sl
		r4->bData_2 = 0xff;
		r4->wData_0 = 0xffff; //-1;

		if (r5->bData_11 != 0xff)
		{
			//0x2340e800
			sp_0x1c.dwInFunction = 0xff;
			sp_0x1c.dwOutFunction = 0; //sl
			sp_0x1c.bPin = r5->bData_11;

#if 0
			{
				char str[40];
				sprintf(str, "fe_manager_detect: r5->bData_11=%d\r\n", r5->bData_11);
				console_send_string(str);
			}
#endif

			if (0 != gpio_open(&sp_0x1c, &r4->resetGpio))
			{
#if 0
				console_send_string("fe_manager_detect (filter_manager.c): error 2\r\n");
#endif
				//->loc_2340e8d8
				break;
			}
		}
		//loc_2340e824
		if (r5->bData_16 != 0xff)
		{
			sp_0x1c.bPin = r5->bData_16;
			sp_0x1c.dwOutFunction = 0xff;
			sp_0x1c.dwInFunction = 0; //sl

			if (0 != gpio_open(&sp_0x1c, &r4->Data_0xb8))
			{
#if 0
				console_send_string("fe_manager_detect (filter_manager.c): error 3\r\n");
#endif
				//->loc_2340e8d8
				break;
			}
		}
		//loc_2340e850
		if (r5->bData_14 != 0xff)
		{
			sp_0x1c.bPin = r5->bData_14;
			sp_0x1c.dwInFunction = 0xff;
			sp_0x1c.dwOutFunction = 1; //fp

			if (0 != gpio_open(&sp_0x1c, &r4->Data_0xac))
			{
#if 0
				console_send_string("fe_manager_detect (filter_manager.c): error 4\r\n");
#endif
				//->loc_2340e8d8
				break;
			}
		}
		//loc_2340e880
		if (r5->bData_15 != 0xff)
		{
			sp_0x1c.bPin = r5->bData_15;
			sp_0x1c.dwOutFunction = 0xff;
			sp_0x1c.dwInFunction = 0; //sl

			if (0 != gpio_open(&sp_0x1c, &r4->Data_0xb0))
			{
#if 0
				console_send_string("fe_manager_detect (filter_manager.c): error 5\r\n");
#endif
				//->loc_2340e8d8
				break;
			}
		}
		//loc_2340e8ac
		if (r5->bData_17 != 0xff)
		{
			sp_0x1c.bPin = r5->bData_17;
			sp_0x1c.dwInFunction = 0xff;
			sp_0x1c.dwOutFunction = 1; //fp

			if (0 != gpio_open(&sp_0x1c, &r4->Data_0xbc))
			{
#if 0
				console_send_string("fe_manager_detect (filter_manager.c): error 6\r\n");
#endif
				//->loc_2340e8d8
				break;
			}
		}
		//loc_2340e8ec
		sp_0x28 = 0; //sl

		if (r5->Data_4 != 0)
		{
#if 0
			if ((r5->Data_4 == 1) || (r5->Data_4 == 6))
			{
				if (r4->resetGpio != 0)
				{
					frontend_reset_by_gpio(r4);
				}

				(void) (r8->Data_0)(r5->bData_8, r5->bData_9);
				sp_0x28 = (r8->Data_4)(r5, bData_23492080);

#if 0
				{
					char str[40];
					sprintf(str, "fe_manager_detect: (1/6): sp_0x28=%d\r\n", sp_0x28);
					console_send_string(str);
				}
#endif

				memcpy(&r4->Data_4, r8, 11*4);

				if (sp_0x28 == 0)
				{
					r4->threadFunc = sub_2340e274;
					r4->Data_0x58 = sub_2340e23c;
					//->loc_2340e9b0
				}
				else
				{
					//->loc_2340ea48
				}
			} //if ((r5->Data_4 == 1) || (r5->Data_4 == 6))
			//loc_2340e968
			else if (r5->Data_4 == 2)
			{
				if (r4->resetGpio != 0)
				{
					frontend_reset_by_gpio(r4);
				}

				sub_2343e388(r5->bData_9, r5->bData_8, r5->hI2c, r4->resetGpio);

				sp_0x28 = 0xff & sub_2343ebb2();
#if 0
				{
					char str[40];
					sprintf(str, "fe_manager_detect: (2): sp_0x28=%d\r\n", sp_0x28);
					console_send_string(str);
				}
#endif
				if (sp_0x28 == 0)
				{
					r4->threadFunc = sub_2340e054;
					r4->Data_0x58 = sub_2340dfbc;
					//->loc_2340eb04
				}
				else
				{
					//->loc_2340ea48
				}
			} //else if (r5->Data_4 == 2)
			//loc_2340e9b8
			else 
#endif
                if (r5->Data_4 == 3)
			{
#if 0
				{
					uint8_t rxData[1];
					uint8_t* pRxData = &rxData[0];
					int numRxBytes = sizeof(rxData);
					uint16_t wTxData = 0;

					for (uint8_t addr = 0x30; addr < 0x31; addr++)
					{
						int res = i2c_master_read_reg(main_hI2c0, addr, wTxData, pRxData, numRxBytes);

						extern char debug_string[];
						sprintf(debug_string, "main_frontend_i2c_init: addr=0x%x, res=%d\r\n", addr, res);
						console_send_string(debug_string);
					}
				}
#endif

				if (r4->resetGpio != 0)
				{
					frontend_reset_by_gpio(r4);
				}

#if 0
				{
					uint8_t rxData[1];
					uint8_t* pRxData = &rxData[0];
					int numRxBytes = sizeof(rxData);
					uint16_t wTxData = 0;

					for (uint8_t addr = 0x30; addr < 0x31; addr++)
					{
						int res = i2c_master_read_reg(main_hI2c0, addr, wTxData, pRxData, numRxBytes);

						extern char debug_string[];
						sprintf(debug_string, "main_frontend_i2c_init: addr=0x%x, res=%d\r\n", addr, res);
						console_send_string(debug_string);
					}
				}
#endif

				//Set Addresses
				(r8->Data_4)(bData_23492080, r5->bData_9, r5->bData_8, 0,
						r5->hI2c, r4->resetGpio,
						r4->Data_0xa4, r4->Data_0xa8, r4->Data_0xb0, r4->Data_0xac);

				//Init
				sp_0x28 = 0xff & (r8->Data_0)();
#if 1
				{
					char str[40];
					sprintf(str, "fe_manager_detect: (3): sp_0x28=%d\r\n", sp_0x28);
					console_send_string(str);
				}
#endif

				if (sp_0x28 == 0)
				{
					//0x2340ea1c
					memcpy(&r4->Data_0x30, r8, 8*4);

					r4->threadFunc = frontend_cable_thread_func;
					r4->Data_0x58 = sub_2340dd74;

#if 0
					if (sp_0x28 != 0)
					{
						//loc_2340ea48
					}
					else
					{
						//->loc_2340eb04
					}
#endif
				}
				else
				{
					//->loc_2340ea48
				}
			} //else if (r5->Data_4 == 3)
			//loc_2340eae8
			else if (r5->Data_4 == 4)
			{
				//loc_2340eb04: empty
			}
			else if (r5->Data_4 == 5)
			{
				r4->threadFunc = sub_2340dce8;
				r4->Data_0x58 = sub_2340dc9c;
			}
		} //if (r5->Data_4 != 0)

		if (sp_0x28 != 0)
		{
			//loc_2340ea48
			if (r4->resetGpio != (void*)0xff)
			{
				gpio_close(r4->resetGpio);
			}

			if (r4->Data_0xa4 != (void*)0xff)
			{
				gpio_close(r4->Data_0xa4);
			}

			if (r4->Data_0xa8 != (void*)0xff)
			{
				gpio_close(r4->Data_0xa8);
			}

			if (r4->Data_0xbc != (void*)0xff)
			{
				gpio_close(r4->Data_0xbc);
			}

			if (r4->Data_0xac != (void*)0xff)
			{
				gpio_close(r4->Data_0xac);
			}

			if (r4->Data_0xb0 != (void*)0xff)
			{
				gpio_close(r4->Data_0xb0);
			}

			if (r4->Data_0xb8 != (void*)0xff)
			{
				gpio_close(r4->Data_0xb8);
			}

			r4->threadFunc = 0;
			//->loc_2340e8d8
			break;
		}
		else
		{
			//loc_2340eb04
			r4->hI2c = r5->hI2c;
			r4->Data_0xc4 = r5->bData_8;
			r4->Data_0xc8 = r5->bData_9;
			r4->Data_0xd0 = r5->Data_4;
			r4->bState = 0; //sl;
			r4->bData_0xda = 0xff;
			r4->Data_0x98 = r4->bData_0xd9 = bData_23492080++;

			if (bData_23492080 == 2)
			{
				struct
				{
					int fill_0; //0
					uint32_t Data_4; //4
					int fill_8[2]; //8
					int Data_16; //16
					int fill_20[2]; //20
					//28 = 0x1c
				} sp;

				channel_handle_user_settings(1, &sp);

				if (sp.Data_4 & 0x40000)
				{
					Data_2354dd70[1].bData_0xda = 0; //ls
				}
			}
			//loc_2340eb64
			OSSemPost(fe_manager_pSema);
#if 1
			console_send_string("fe_manager_detect (fe_manager.c): return r4\r\n");
#endif
			return r4;
		}
	}
	while (0);
	//loc_2340e8d8
	OSSemPost(fe_manager_pSema);

#if 1
	console_send_string("fe_manager_detect (filter_manager.c): return NULL\r\n");
#endif
	return 0;
}


/* 2340eb74 / 23415a90 - todo */
int fe_manager_tune(Struct_2354dd70* r4, Transponder sp_0x24, void (*callbackFunc/*r6*/)(), uint16_t r7)
{
//	int sp_0x24;
	uint8_t err; //sp

//	void* r6 = sp_0x24.Data_0;
//	int r7 = sp_0x24.Data_4;

#if 0
	console_send_string("fe_manager_tune (todo.c): TODO\r\n");
#endif

	if (r4 == 0)
	{
		return 7;
	}

	OSSemPend(fe_manager_pSema, 0, &err);

	if ((r4->bState == 4) || (r4->bState == 5))
	{
		frontend_reset_by_gpio(r4);
	}

	if (r4->Data_0x60 != 0)
	{
		if (0 != (r4->Data_0x60)(&sp_0x24))
		{
			OSSemPost(fe_manager_pSema);

			return 0;
		}
	}
	//loc_2340ebe4
	r4->bState = 1; //sb

	if (0 == memcmp(&r4->Data_0x7c, &sp_0x24, sizeof(Transponder)))
	{
		r4->bData_0x9c = 0; //r8
		r4->wData_0xd4 = 5;
		//->loc_2340ec28
	}
	else
	{
		//0x2340ec14
		r4->bState = 1; //sb

		memcpy(&r4->Data_0x7c, &sp_0x24, sizeof(Transponder));
	}
	//loc_2340ec28
	Data_2354dd70[0].stateChangeCallback = 0; //r8
	Data_2354dd70[1].stateChangeCallback = 0; //r8

	r4->stateChangeCallback = callbackFunc;
	r4->wData_0xd4 = r7;

	sub_23421a30(0, r4->Data_0x7c.bData_0x16);

	OSTimeDlyResume(fe_manager_threadPrio);
	//->loc_2340ebd0
	OSSemPost(fe_manager_pSema);

	return 0;
}


/* 2340ec54 - complete */
int sub_2340ec54(Struct_2354dd70* r4, void (*func)())
{
	uint8_t err;

#if 0
	console_send_string("sub_2340ec54 (todo.c): TODO\r\n");
#endif

	if (r4 != 0)
	{
		OSSemPend(fe_manager_pSema, 0, &err);

		r4->stateChangeCallback = func;

		OSSemPost(fe_manager_pSema);
	}

	return 0;
}


/* 2340ec8c / 23415ba8 - complete */
int sub_2340ec8c(void* h, void (*r6)())
{
#if 0
	console_send_string("sub_2340ec8c (todo.c): TODO\r\n");
#endif

	Struct_2354dd70* r4 = h;
	uint8_t err;

	OSSemPend(fe_manager_pSema, 0, &err);

	r4->Data_0x5c = r6;

	OSSemPost(fe_manager_pSema);

	return 0;
}


/* 2340ecc0 - complete */
int sub_2340ecc0(Struct_2354dd70* r4, uint8_t* b, uint8_t* r5)
{
	int r0;

	if (r4 == 0)
	{
#if 0
		console_send_string("sub_2340ecc0: r4==0\r\n");
#endif
		*b = 0xff;

		return 0;
	}

#if 0
	{
		char str[48];
		sprintf(str, "sub_2340ecc0: r4->Data_0xd0=%d\r\n", r4->Data_0xd0);
		console_send_string(str);
	}
#endif

	if ((r4->Data_0xd0 == 1) || (r4->Data_0xd0 == 6))
	{
#if 0
		console_send_string("sub_2340ecc0: r4->Data_0x1c=TODO\r\n");
#endif
		r0 = 1 & (r4->Data_4.Data_0x18)(r4->bData_0xd9);
		//->loc_2340ed0c
	}
	//loc_2340ed00
	else if (r4->Data_0xd0 == 2)
	{
		r0 = r4->bData_0xcc;
	}
	else
	{
		r0 = 0;
	}
	//loc_2340ed0c
	*r5 = r0;

	return r4->bData_0x9c;
}


/* 2340ed18 - todo */
int fe_manager_get_transponder_type(Transponder* r0)
{
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "fe_manager_get_transponder_type: r0->Data_0.Data_0.Data_0=%d, r0->Data_0.Data_4=%d\r\n",
				r0->Data_0.Data_0.Data_0, r0->Data_0.Data_4);
		console_send_string(debug_string);
	}
#endif

	if (r0->bData_0x16 == 0xff)
	{
#if 0
		console_send_string("fe_manager_get_transponder_type: return 3\r\n");
#endif
		return 3;
	}

	if (((r0->Data_0.Data_0.Data_0 > 3399000) && (r0->Data_0.Data_0.Data_0 < 13000000)) &&
			((r0->Data_0.frequency > 1000) && (r0->Data_0.frequency < 70000)))
	{
#if 0
		console_send_string("fe_manager_get_transponder_type: return 0\r\n");
#endif
		return 0;
	}

	if (((r0->Data_0.frequency >= 1775000) && (r0->Data_0.frequency <= 8580000)) &&
			(r0->Data_0.wData_0x0a == 0))
	{
#if 0
		console_send_string("fe_manager_get_transponder_type: return 2\r\n");
#endif
		return 2;
	}

	if ((r0->Data_0.frequency >= 500000) && (r0->Data_0.frequency <= 8600000))
	{
#if 0
		console_send_string("fe_manager_get_transponder_type: return 1\r\n");
#endif
		return 1;
	}

#if 0
		console_send_string("fe_manager_get_transponder_type: return 4\r\n");
#endif

	return 4;
}


/* 2340ed98 - complete */
int fe_manager_shutdown(Struct_2354dd70* r4, int b, void (*func)())
{
	uint8_t err;

#if 1
	console_send_string("fe_manager_shutdown (filter_manager.c): complete\r\n");
#endif

	if (r4 != 0)
	{
		OSSemPend(fe_manager_pSema, 0, &err);

		if (err != 0)
		{
			return 0xff;
		}

		r4->bState = 4;
		r4->stateChangeCallback = func;

		memset(&r4->Data_0x64, 0, sizeof(Transponder));

		OSSemPost(fe_manager_pSema);

		return 0;
	}

	return 0xff;
}


/* 2340ee34 - complete */
int sub_2340ee34(Struct_2354dd70* p)
{
	if (p != 0)
	{
		return p->Data_0xd0;
	}

	return 5;
}

#if 0

/* 2340ee78 / 23415d94 - complete */
void sub_2340ee78(int r6, int r5)
{
#if 0
	console_send_string("sub_2340ee78 (todo.c): complete\r\n");
#endif

	uint8_t sp;

	OSSemPend(fe_manager_pSema, 0, &sp);

	if (Data_2349208c != 0)
	{
		//0x2340eea4
		gpio_set(Data_2349208c, r6);

		Data_2354dd70[1].bData_0xda = (r6 != 0)? 0: 0xff;

		if (r5 != 0)
		{
			Data_2354dd70[1].bData_0x9c = 0;
			Data_2354dd70[1].bState = 1;
		}
	}
	//loc_2340eed4
	OSSemPost(fe_manager_pSema);
}

#endif
