
#include "data.h"
#include "ir_user.h"
#include "ir.h"
#include "vfd.h"
#include "powermode.h"
#include "av.h"
#include "flash.h"
#include "sub_23438084.h"
#include "thumb2.h"


extern int main_process_uart_command(uint8_t*);


uint8_t bData_23491d8c = 0; //23491d8c +0
Uart_Module* main_hUart0 = 0; //23491d90 +4 
Struct_235f2e2c* main_hFlash = 0; //23491db0 +0x24
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

#if 0
				sub_2340bf0c(&sp_0x28);

				channel_start_number(&sp0, sp_0x28.wData_0x2a, sp_0x28.wData_0x2a);
#endif
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

