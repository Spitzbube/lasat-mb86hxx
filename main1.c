
#include "data.h"
#include "ir_user.h"

extern int main_process_uart_command(uint8_t*);


Uart_Module* main_hUart0 = 0; //23491d90 +4 
MemBlk_Handle* main_hMemBlk2 = 0; //23491dc0 +0x34
Struct_20611068* main_hUsbGpio = 0; //23491dc4 +0x38 

struct
{
	int fill_0[0x8000]; //0
	//size????
} Data_2349d250; //2349d250 


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


/* 23400978 / 23402150 - todo */
void main_inputhandler_init()
{
	void* pMBox; //r4;
	Struct_2340d784 sp_0x5c;

	memset(&sp_0x5c, 0, sizeof(Struct_2340d784));

	sp_0x5c.threadPrioIR = THREAD_PRIO_IR_USER_IN;
	sp_0x5c.threadPrioUart = THREAD_PRIO_UART_IN;
	sp_0x5c.threadPrioUI_1 = THREAD_PRIO_UI_1;
	sp_0x5c.threadPrioUI_2 = THREAD_PRIO_UI_2;
#if 0
	sp_0x5c.bData_20 = 1;
	sp_0x5c.bData_21 = (sub_23418e98() == 4)? 1: 0;
#endif
	//0x234009dc
	pMBox = ir_user_init(&sp_0x5c);
	if (pMBox != 0)
	{
	}
	//loc_23400a28
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

