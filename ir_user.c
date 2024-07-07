
#include <string.h>
#include "data.h"
#include "ir_user.h"


OS_EVENT* Data_23492068; //23492068 +0 / 234ac680
OS_EVENT* Data_2349206c; //2349206c +4
int (*inputhandler_uart_callback)(uint8_t*); //23492070 +8 / 234ac688

uint32_t uart_in_thread_stack[THREAD_STACK_SIZE_UART_IN]; //23549824 -> 2354A4A4
Struct_2340d784 Data_2354bda4; //2354bda4 / 235a8404


/* 2340d63c / 23414578 - todo */
void uart_in_thread(void* p)
{
	uint8_t writeBuf[20]; //size???
	uint8_t readBuf[20]; //size???
	int8_t r4 = 0;
	int r5 = 0;
	int8_t r6 = 0;
	int r7 = 0;
	int eol_ch = 0; //r8
	uint8_t ch = 0; //sp

	while (1)
	{
		//loc_2340d668
		if (0 == console_rx_empty())
		{
			//2340d674
			console_read_byte(&ch);

//    		console_send_number(ch, 2);

			eol_ch = ((eol_ch << 8) & 0xffff) | ch;

//            console_send_number(eol_ch, 4);

			writeBuf[r4] = ch;
			if (r4 < 19)
			{
				r4++;
			}
			else
			{
				r4 = 0;
			}

			if ((eol_ch == 0x0d0a) ||
#if 0
                0)
#else
                ((eol_ch & 0x0d) == 0x0d))
#endif
			{
				//2340d6ac
				r6 = r4 - r5;

				if (r6 >= 0)
				{
					//->loc_2340d6f0
					memcpy(readBuf, &writeBuf[r5], r6);
				}
				else
				{
					//2340d6c8
					r6 = r6 + 20;

					memcpy(readBuf, &writeBuf[r5], 20 - r5);
					memcpy(&readBuf[20 - r5], writeBuf, r4);
				}

				r5 = r4;
				r7 = 1;
				//->loc_2340d734
			}
			//loc_2340d734
		}
		else
		{
			//loc_2340d700
			if (r7 != 0)
			{
				//2340d708
				if (inputhandler_uart_callback != 0)
				{
					//2340d718
					readBuf[r6 - 2] = 0;

					if (0 != (inputhandler_uart_callback)(readBuf))
					{
						//->loc_2340d740
						break; //return;
					}
					//loc_2340d730
				}
				//loc_2340d730
				r7 = 0;
			}
			//loc_2340d734
		}
		//loc_2340d734
		rtos_task_wait(5);
	} //while (1)
	//loc_2340d740
}


/* 2340d748 / 23414684 - todo */
void inputhandler_register_uart_callback(int (*pFunc)(uint8_t*))
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

    OS_ENTER_CRITICAL();

	inputhandler_uart_callback = pFunc;

	OS_EXIT_CRITICAL();
}


/* 2340d784 / 234146c0 - todo */
void* ir_user_init(Struct_2340d784* r5)
{
	memcpy(&Data_2354bda4, r5, sizeof(Struct_2340d784));

	Data_23492068 = (void*) OSMboxCreate(0);
	Data_2349206c = (void*) OSMboxCreate(0);

	OSTaskCreateExt(uart_in_thread, 0, &uart_in_thread_stack[THREAD_STACK_SIZE_UART_IN-1]/*0x2354a4a0*/,
			r5->threadPrioUart, r5->threadPrioUart, uart_in_thread_stack, THREAD_STACK_SIZE_UART_IN, "STARTUP" , 0x03);

	return Data_2349206c;
}

