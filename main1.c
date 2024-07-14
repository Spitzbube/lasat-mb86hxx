
#include "data.h"
#include "ir_user.h"
#include "ir.h"
#include "vfd.h"
#include "powermode.h"
#include "av.h"
#include "flash.h"
#include "i2c.h"
#include "sub_23438084.h"
#include "thumb2.h"
#include "sub_2340a6a0.h"
#include "frontend.h"
#include "fe_manager.h"


extern int main_process_uart_command(uint8_t*);


uint8_t bData_23491d8c = 0; //23491d8c +0
Uart_Module* main_hUart0 = 0; //23491d90 +4 
void* main_hI2c0 = 0; //23491d98 +12 = 0xc
Struct_235f2e2c* main_hFlash = 0; //23491db0 +0x24
Struct_2354dd70* Data_23491db4 = 0; //23491db4 +40 = 0x28 //Data_234ac4e8
Struct_2354dd70* Data_23491db8 = 0; //23491db8 +44 = 0x2c //Data_234ac4ec
MemBlk_Handle* main_hMemBlk2 = 0; //23491dc0 +0x34
Struct_20611068* main_hUsbGpio = 0; //23491dc4 +0x38 
Struct_23438084* Data_23491dc8 = 0; //23491dc8 +0x3c


struct
{
	int fill_0[8]; //0
	//size???
} Data_2349d230; //2349d230 //TODO

struct
{
	int fill_0[0x8000]; //0
	//size????
} Data_2349d250; //2349d250 


/* 23400510 - complete */
int sub_23400510(int a)
{
#if 0
	char str[32];
	sprintf("sub_23400510 (main.c): a=%d\r\n", a);
	console_send_string(str);
#endif
	return 0;
}


struct
{
	int pin; //0
	int delay; //4

}
Data_23491df4[2] = //23491df4
{
		{86, 1},
		{87, 1}
};


/* 23400580 / 234011e4 - complete */
void main_frontend_i2c_init()
{
	Struct_20611068* hGpio;
	Struct_2341cd7c i2cParams;
	Struct_20401328 gpioParams;
	uint32_t i = 2;

#if 0
	i2cParams.bData_0 = 0; // I2C0
	i2cParams.bData_1 = 0;
	i2cParams.clkPin = 25;
	i2cParams.dataPin = 24;

	i2c_open(&i2cParams, &main_hI2c0);
#endif

	gpioParams.dwInFunction = 0xff;
	gpioParams.dwOutFunction = 0;

	while (i--)
	{
		//loc_234005a4
		gpioParams.bPin = Data_23491df4[i].pin;

#if 0
		{
			char str[40];
			sprintf(str, "main_frontend_i2c_init: i=%d, pin=%d\r\n", i, gpioParams.bPin);
			console_send_string(str);
		}
#endif

		gpio_open(&gpioParams, &hGpio);

		gpio_set(hGpio, 1);
		rtos_task_wait((uint16_t)Data_23491df4[i].delay);

		gpio_set(hGpio, 0);
		rtos_task_wait((uint16_t)Data_23491df4[i].delay);

		gpio_set(hGpio, 1);

#if 0
//		rtos_task_wait((uint16_t)Data_23491df4[i].delay);
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

		gpio_close(hGpio);
	}
	//0x23400608
#if 1 //orig
	i2cParams.bData_0 = 0; // I2C0
	i2cParams.bData_1 = 0;
	i2cParams.clkPin = 25;
	i2cParams.dataPin = 24;

	i2c_open(&i2cParams, &main_hI2c0);
#endif

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
}


/* 23400634 - todo / 23401298 - todo */
void main_flash_init()
{
	int sp_0x24;
	Struct_23437fd4 sp_0x10;

	flash_init();

	sp_0x24 = 1;

	flash_open(&sp_0x24, &main_hFlash);

	if (main_hFlash != 0)
	{
		sp_0x10.pFlash = main_hFlash;
		sp_0x10.Data_16 = &Data_2349d230;
		sp_0x10.Data_0 = 16;
		sp_0x10.Data_4 = 0x40370000;
		sp_0x10.Data_8 = 16;

		Data_23491dc8 = sub_23437fd4(&sp_0x10);

#if 0
		Struct_23419cd0 sp4 = {0x40380000, 0, 0}; //23487b5c

		sp4.hFlash = main_hFlash;
		sp4.Data_8 = (void*) sub_234019e0(0x20000);

		sub_23419cd0(&sp4);
#endif
	}
	//loc_234006bc
}


/* 234006c4 - complete */
void main_base_init()
{
	ARM1176_INTR_Initialise();
	intr_init();
	timer_init();
	timer_open(0);
}

/* 234006e4 - todo */
void main_console_init()
{
	unsigned char str[72];
	Uart_Init_Params uartParams;

	gpio_init();
	uart_setup();

	uartParams.bData_0 = 0;

	uartParams.rxPin.bPin = 32;
	uartParams.rxPin.dwOutFunction = 0xff;
	uartParams.rxPin.dwInFunction = 21; //0x15; //+ 0x0100 /*0x115*/ = FAPI_GPIO_IN_UART0_DATA

	uartParams.txPin.bPin = 33;
	uartParams.txPin.dwOutFunction = 23; //0x17; //+ 0x0080 /*0x97*/ = FAPI_GPIO_OUT_UART0_DATA
	uartParams.txPin.dwInFunction = 0xff;

	uart_init(&uartParams, &main_hUart0);
	console_init(main_hUart0);

	strcpy(str, "**  (C) LASAT GMBH v.");
	strcat(str, "Oct  8 2021");
	strcat(str, "             **\n\r");
#if 1
	console_send_string(str);
#endif
}


/* 2340088c / 23402068 - todo */
void main_powermode_init()
{
	extern void sub_2343b992();
	extern void sub_2343cc34();

	Powermode_Init_Params params;

	params.gpioPin = 6;
	params.initialState = 1;
	params.Data_8 = 0;
	params.Data_12 = 0;
#if 0
	params.Data_16 = sub_2343cc34;
	params.Data_20 = sub_2343b992;
#endif

	powermode_init(&params);
}


/* 23400978 / 23402150 - todo */
void main_inputhandler_init()
{
	void* pMBox; //r4;
	UI_Thread_Params sp_0x74;
	Struct_2340d784 sp_0x5c;
	Struct_2340bf0c sp_0x28;
	struct Struct_234fd8f0_Inner0 sp0;

	ir_init(ir_user_send_data, 0x3b);

	menu_main_adapt_items(sub_2343b946/*thumbb2.c*/);
	
	memset(&sp_0x5c, 0, sizeof(Struct_2340d784));

	sp_0x5c.threadPrioIR = THREAD_PRIO_IR_USER_IN;
	sp_0x5c.threadPrioUart = THREAD_PRIO_UART_IN;
	sp_0x5c.threadPrioUI_1 = THREAD_PRIO_UI_1;
	sp_0x5c.threadPrioUI_2 = THREAD_PRIO_UI_2;
	sp_0x5c.bData_20 = 1;
	sp_0x5c.bData_21 = 1; //(sub_23418e98() == 4)? 1: 0;
	//0x234009dc
	pMBox = ir_user_init(&sp_0x5c);
	if (pMBox != 0)
	{
		//0x234009ec
		sp_0x74.Data_20 = 0;
		sp_0x74.threadFunc = mainfunction_thread;
		sp_0x74.threadName = "MainInputHandler";
		sp_0x74.pMBox = pMBox;

		sub_2343d458(&sp_0x74);

#if 1
		if (bData_23491d8c != 0)
#else
		if (1)
#endif
		{
#if 0
			sub_2343e196(&sp_0x74);
#endif
			//loc_23400a28
		}
		else
		{
			//loc_23400a30
			int state = powermode_get_state();
			if (state == 1)
			{
				//0x23400a3c
				ui_thread_create(&sp_0x74);

				sub_2340bf0c(&sp_0x28);

				channel_start_number(&sp0, sp_0x28.wData_0x2a, sp_0x28.wData_0x2a);
				//->loc_23400a28
			}
			//loc_23400a60
			else if (state == 2)
			{
				//0x23400a68
				sp_0x74.Data_20 = 0;
				sp_0x74.pMBox = pMBox;
				sp_0x74.threadFunc = standby_thread;
				sp_0x74.threadName = "MainInputHandler";

				ui_thread_create(&sp_0x74);
			}
			//loc_23400a28
		} 
	}
	//loc_23400a28
}


#if 1
extern int sub_23401e92(uint8_t, uint8_t);
extern int sub_23401ea4(Struct_2340e754*, int);
extern void sub_23401efc();
extern void sub_23401fe4();
extern void sub_23402060();
extern void sub_2340201a();
extern void sub_234020b8();
extern void sub_234020c2();
extern void sub_2340c318();
extern void sub_2340c970_();
extern void sub_2340ca9c();
extern void sub_23402df4();
extern void sub_23402e8e();
extern void sub_23402b6c();
extern void sub_23402c9a();
extern void sub_23402da0();
extern void sub_23402d0c();
extern void sub_23403160();
extern void sub_23402e68();
extern void sub_23402280();
extern void sub_2340229c();
extern void sub_23402364();
extern void sub_2340246c();
extern void sub_234024ac();
extern void sub_2340251c();
extern void sub_2340ef00();
extern void sub_2340eee0();
#else
extern void sub_23403d60();
extern void sub_23403700();
extern void DEM_86668_SearchTransponder();
extern void DEM_86668_GetLock();
extern void sub_23403d14();
extern void sub_23403ba6();
extern void sub_23403cb2();
extern void sub_234040dc();
#endif


/* 23400fa0 / 234019b4 - todo */
void main_frontend_init()
{
	typedef int (*func)();

	struct
	{
		int fill_0[4]; //0
		int Data_16; //16

	} sp_0x94;
	fe_manager_Params sp_0x90;
	Struct_2340e754 sp_0x7c;
#if 0
	func sp_0x50[11] = //23487b68
	{
			sub_23401e92,
			sub_23401ea4,
			sub_23401efc,
			sub_23401fe4,
			sub_23402060,
			sub_2340201a,
			sub_234020b8,
			sub_234020c2,
			sub_2340c318,
			sub_2340c970_,
			sub_2340ca9c
	};
#endif
	func sp_0x30[8] = //23487b94
	{
			sub_23402df4, //init
			sub_23402e8e, //set addresses
			sub_23402b6c, //tune
			sub_23402c9a, //get lock
			sub_23402da0,
			sub_23402d0c,
			sub_23403160,
			sub_23402e68
	};

	sp_0x90.threadPrio = THREAD_PRIO_FE_MANAGER;
#if 0
	sp_0x90.gpioPin = 0xff; //r5
#else
	sp_0x90.gpioPin = 0x4f;
#endif

	fe_manager_init(&sp_0x90);

#if 0 //Cable Frontends from V241
	Struct_235441b0 sp_0xe8;
	Struct_2340e754 sp_0xd0; //+0x14
	struct
	{
		func Data_0[8]; //0
		//0x20 = 32
	}
	sp_0x38[] = //234a3688
	{
		{
			sub_23403d60, //init
			sub_23403700, //set addresses
			DEM_86668_SearchTransponder, //tune
			DEM_86668_GetLock, //get lock
			sub_23403d14,
			sub_23403ba6,
			sub_23403cb2,
			sub_234040dc,
		},
#if 0
		{
			sub_234052c2,
			sub_23405312,
			sub_2340509c,
			sub_234051be,
			sub_23405668,
			sub_2340522e,
			sub_234055b4,
			sub_234052f2
		},
#endif
	};

	sp_0xd0.bData_8 = 0xc6;
	sp_0xd0.bData_12 = 0xff;
	sp_0xd0.bData_9 = 0x30;
	sp_0xd0.bData_13 = 0xff;
	sp_0xd0.bData_10 = 0xff;
	sp_0xd0.bData_17 = 0xff;
	sp_0xd0.bData_14 = 0xff;
	sp_0xd0.Data_4 = 3; //sb
	sp_0xd0.bData_11 = 86; //r7
	sp_0xd0.bData_15 = 0xff;
	sp_0xd0.bData_16 = 0xff;
	sp_0xd0.hI2c = main_hI2c0;
	//r4 = 0xff
	Data_23491db4 = (void*) fe_manager_detect(&sp_0xd0, &sp_0x38[0]);
	if (Data_23491db4 != 0)
	{
		//->loc_23401d20
		sub_2340c970(1, &sp_0xe8);

		if (sp_0xe8.Data_0x10 & 0x80)
		{
			sub_23413310(sub_2343dd2c, sub_2343deb4);
		}

		return;
	}
	//0x23401bbc

#else //Frontends from VDR110

#if 0 // Try FE type 1 with sp_0x50
	sp_0x7c.Data_4 = 1;
	sp_0x7c.bData_8 = 0xc0; //r6
	sp_0x7c.bData_9 = 0xd0;
	sp_0x7c.bData_12 = 0xff;
	sp_0x7c.bData_13 = 0xff;
	sp_0x7c.bData_10 = 0x16;
	sp_0x7c.bData_17 = 0xff;
	sp_0x7c.bData_14 = 0xff;
	sp_0x7c.bData_11 = 86; //r4;
	sp_0x7c.bData_15 = 0xff;
	sp_0x7c.bData_16 = 0xff;
	sp_0x7c.hI2c = main_hI2c0;

	Data_23491db4 = (void*) fe_manager_detect(&sp_0x7c, &sp_0x50);

	if (Data_23491db4 == 0)
	{
		//0x23401044
		sp_0x7c.bData_9 = 0xd4;

		Data_23491db4 = (void*) fe_manager_detect(&sp_0x7c, &sp_0x50);
	}
#endif
	{
		//loc_2340105c
#if 0 // Try FE type 6 with sp4
		func sp4[11] = // 23487bb4;
		{
				sub_23402280,
				sub_2340229c,
				sub_23402364,
				sub_2340246c,
				sub_234024ac,
				sub_2340251c,
				sub_2340ef00,
				sub_2340eee0,
				sub_2340c318,
				sub_2340c970,
				sub_2340ca9c
		};

		sp_0x7c.Data_4 = 6;
		sp_0x7c.bData_8 = 0xc0; //r6
		sp_0x7c.bData_9 = 0xc8;
		sp_0x7c.bData_12 = 0xff;
		sp_0x7c.bData_13 = 0xff;
		sp_0x7c.bData_10 = 0xff;
		sp_0x7c.bData_14 = 0xff;
		sp_0x7c.bData_11 = 87;
		sp_0x7c.bData_15 = 0xff;
		sp_0x7c.bData_16 = 0xff;
		sp_0x7c.hI2c = main_hI2c0;

		/*Data_23491d8c.Data_0x2c*/Data_23491db8 = (void*) fe_manager_detect(&sp_0x7c, &sp4);
#endif

		if (Data_23491db4 == 0)
		{
			//0x234010c4
#if 1 // Try FE type 3 with sp_0x30
			sp_0x7c.bData_8 = 0xc2;
			sp_0x7c.bData_12 = 0xff;
			sp_0x7c.bData_9 = 0x3a; //r8
			sp_0x7c.bData_13 = 0xff;
			sp_0x7c.bData_10 = 0xff;
			sp_0x7c.bData_17 = 0xff;
			sp_0x7c.bData_14 = 0xff;
			sp_0x7c.Data_4 = 3; //r6;
			sp_0x7c.bData_11 = 86; //r4;
			sp_0x7c.bData_15 = 0xff;
			sp_0x7c.bData_16 = 0xff;
			sp_0x7c.hI2c = main_hI2c0;

			Data_23491db4 = (void*) fe_manager_detect(&sp_0x7c, &sp_0x30);

			if (Data_23491db4 != 0)
			{
				//loc_2340111c
				sub_2340c970(1, &sp_0x94);

				if (sp_0x94.Data_16 & 0x80)
				{
					sub_23413310(sub_2343dd2c, sub_2343deb4);
				}
				//loc_2340113c
				return;
			} //if (Data_23491db4 != 0)
			else
#endif
			{
				//loc_23401144
				uint8_t r4;
				uint8_t sp_0x2c[] = {0xc0, 0xc6, 0, 0};

#if 1 // Try 2 x FE type 3 with sp_0x30
				sp_0x7c.bData_12 = 0xff;
				sp_0x7c.bData_9 = 0x3a; //r8
				sp_0x7c.bData_13 = 0xff;
				sp_0x7c.bData_10 = 0xff;
				sp_0x7c.bData_17 = 0xff;
				sp_0x7c.bData_14 = 0xff;
				sp_0x7c.Data_4 = 3; //r6;
				sp_0x7c.bData_11 = 86; //r4;
				sp_0x7c.bData_15 = 0xff;
				sp_0x7c.bData_16 = 0xff;
				sp_0x7c.hI2c = main_hI2c0;
				//r6 = &sp_0x2c
				for (r4 = 0; r4 < 2; r4++)
				{
					//loc_23401188
					sp_0x7c.bData_8 = sp_0x2c[r4];

					Data_23491db4 = (void*) fe_manager_detect(&sp_0x7c, &sp_0x30);

					if (Data_23491db4 != 0)
					{
#if 0
						sub_23413358();
						//->loc_2340111c
						sub_2340c970(1, &sp_0x94);

						if (sp_0x94.Data_16 & 0x80)
						{
							sub_23413310(sub_2343dd2c, sub_2343deb4);
						}
#endif
						//loc_2340113c
						return;
					}
					//loc_234011b0
				}
				//loc_234011c0
#endif
			}
		} //if (Data_23491db4 == 0)
		//loc_234011c0
		if ((Data_23491db4 == 0) && (/*Data_23491d8c.Data_0x2c*/Data_23491db8 == 0))
		{
			//0x234011cc
#if 0 // Try FE type 5
			sp_0x7c.Data_4 = 5;
			sp_0x7c.bData_14 = 0xff;
			sp_0x7c.bData_17 = 0xff;
			sp_0x7c.bData_15 = 0xff;

			Data_23491db4 = (void*) fe_manager_detect(&sp_0x7c, 0);
#endif
		}
	}
	//loc_2340113c
#endif
	return;
}


/* 234011f4 - todo */
void sub_234011f4()
{
	Struct_234011f4 sp;
	int oldCrc;
	int calcCrc;
	int r0;

#if 0
	console_send_string("sub_234011f4()\r\n");
#endif

	if (0 != sub_2340add4(0x40300000))
	{
		sub_2340aee4(0x40200000);

		sub_23438194(Data_23491dc8);

		bData_23491d8c = 1;
		//->loc_23401234
	}
	//loc_23401228
	if (bData_23491d8c == 1)
	{
		//loc_23401234
		r0 = 0;
	}
	else
	{
		//loc_2340123c
		sub_23438084(Data_23491dc8, &sp, 0, sizeof(Struct_234011f4));

		oldCrc = sp.crc;
		sp.crc = 0;

		calcCrc = crc32((void*) &sp, sizeof(Struct_234011f4));
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_234011f4: oldCrc=0x%x, calcCrc=0x%x\r\n", oldCrc, calcCrc);
			console_send_string(debug_string);
		}
#endif
		if (oldCrc != calcCrc)
		{
			//->loc_23401234
			r0 = 0;
		}
		else
		{
			//loc_23401274
			r0 = sp.bData_15;
		}
	}
	//loc_23401274
	channel_init(r0);

	sub_2340a794();
}


/* 2340146c / 2340195c - complete */
void main_graphic_init()
{
#if 0 //Only v241!!!
	Struct_234539f0 sp4;

	sp4.Data_0 = 0x22000000;
	sp4.Data_4 = 0x22048000;
	sp4.Data_8 = 0x22090000;
	sp4.Data_12 = 0x22240000;
	sp4.threadPrio = THREAD_PRIO_GRAPHIC;
	sp4.Data_16 = sub_234256fc;

	graphic_init(&sp4);
#endif

	text_table_init(main_hFlash, 0x401b0000);
}


/* 23401488 - todo */
void main_network_init()
{
#if 1
	console_send_string("main_network_init (todo.c): TODO\r\n");
#endif

#if 0
	sub_23419454(sub_234012b0);

	eth_set_buffer( sub_234019e0(0x10000) );
#endif

	uint32_t r4 = sub_234019e0(0x150000);

#if 0
	Data_23491df0 = sub_234019e0(0x10000);
#endif

	if (0 == network_init(r4))
	{
#if 0
		ftpd_init();

		tcp_console_init(main_process_uart_command);
#endif
	}
#if 1 //TODO!!! Until network_init is fixed
	else
	{
		tcp_console_init(main_process_uart_command);
	}
#endif
}


/* 234015ec / 23402000 - complete */
void main_frontpanel_init()
{
	Struct_23410ea4 avParams;
	Struct_23437974 vfdParams;
	uint8_t sp4[] = {0x03, 0x04, 0x02,  0x07,  0x08, 0x05, 0x00, 0x00}; //234017DC

	fpc_init(sp4);

	avParams.threadPrio = THREAD_PRIO_AV;
	avParams.Data_4 = 14;
	avParams.Data_8 = 13;

	av_init(&avParams);

	vfdParams.Data_0 = 80;
	vfdParams.Data_4 = 3;
	vfdParams.Data_8 = 4;

	vfd_init(&vfdParams);

	frontdisplay_init();
}


/* 234017f0 / 234023e8 - todo */
void main_usb_init()
{
	Struct_20401328 sp_0x10;
	MemBlk_Params sp;

	sp_0x10.dwOutFunction = 0;
	sp_0x10.dwInFunction = 0xff;
	sp_0x10.bPin = 0x53;

	gpio_open(&sp_0x10, &main_hUsbGpio);

	sp.addr = (int) &Data_2349d250;
	sp.size = 0x8000;

	main_hMemBlk2 = memblk_open(&sp);
	if (main_hMemBlk2 != 0)
	{
#if 0
		sub_2343a162(sub_23400120);
#endif
		usb_init();
		MGC_usbInitController();
		usb_msd_init();
	}
	//loc_23401858
	return;
}

