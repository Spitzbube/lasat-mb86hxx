
#include "data.h"

Uart_Module* main_hUart0 = 0; //23491d90 +4 


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