
#include <string.h>
#include "data.h"
#include "ir_user.h"


OS_EVENT* Data_23492068; //23492068 +0 / 234ac680
OS_EVENT* Data_2349206c; //2349206c +4
int (*inputhandler_uart_callback)(uint8_t*); //23492070 +8 / 234ac688
void (*Data_23492074)(void*, void*); //23492074 +c
typedef struct
{
	uint8_t bData_0;
	uint16_t wData_2;
	uint16_t wData_4;

} ir_data;

ir_data Data_23492078 = //23492078 +0x10 / 234ac68c
{
		0, 0, 0
};

uint32_t ir_thread_stack[THREAD_STACK_SIZE_IR_USER_IN]; //235491e4
uint32_t uart_in_thread_stack[THREAD_STACK_SIZE_UART_IN]; //23549824 -> 2354A4A4
uint32_t Data_2354a4a4/*stack1*/[0x320]; //2354a4a4 +0x320*4 = 2354B124 / 235a6b04
uint32_t Data_2354b124/*stack2*/[0x320]; //2354b124 +0x320*4 = 2354BDA4 / 235a7784
Struct_2340d784 Data_2354bda4; //2354bda4 / 235a8404


/* 2340d3ec - todo */
void sub_2340d3ec()
{

}


/* 2340d564 / 234143ec - todo */
void ir_user_in_thread()
{
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2

	} sp_0x18;
	uint8_t sp_0x14;
	uint8_t sp_0x10;
	uint8_t sp_0xc;
	uint8_t sp8; //sp8

	int r5 = 0xff;
	uint8_t r4 = 0;

	while (1)
	{
		//loc_2340d57c
		ir_data* pIRD;

#if 0
		console_send_string("ir_user_in_thread (before mBoxPend)\r\n");
#endif

		pIRD = (void*) OSMboxPend(Data_23492068, 0, &sp8);

		if (sp8 == 10) //OS_ERR_TIMEOUT
		{
			//->loc_2340d57c
			continue;
		}
		//2340d598
		if (pIRD->bData_0 == 0)
		{
			int r0_;
			if (0 != sub_23453d90(pIRD->wData_2, pIRD->wData_4, &sp_0x14, &sp_0xc, &sp_0x10))
			{
				//->loc_2340d57c
#if 1
				console_send_string("sub_23453d90 != 0\r\n");
#endif
				continue;
			}
			//2340d5c8
			if ((sp_0x10 == r5) && (r4 != 0))
			{
#if 1
				console_send_string("r4 != 0\r\n");
#endif
				r4--;
				//->loc_2340d614
			}
			else
			{
				//loc_2340d5e4
#if 0
				console_send_string("OSMboxPost\r\n");
#endif
				if (Data_2349206c != 0)
				{
					sp_0x18.bData_0 = sp_0xc;
					sp_0x18.bData_1 = sp_0x10;
					sp_0x18.bData_2 = sp_0x14;

#if 1
                    {
                        extern char debug_string[];
                        sprintf(debug_string, "ir_user_in_thread: OSMboxPost with sp_0xc=0x%x, sp_0x10=0x%x, sp_0x14=0x%x\r\n", 
                            sp_0xc, sp_0x10, sp_0x14);
                        console_send_string(debug_string);
                    }
#endif

					sp8 = OSMboxPost(Data_2349206c, &sp_0x18);

					sub_23410fe4();
				}
				//loc_2340d614
			}

			r0_ = r5;
			r5 = sp_0x10;
			if (r0_ != r5)
			{
				r4 = 4;
			}
			//->loc_2340d57c
		} //if (pIRD->bData_0 == 0)
		else
		{
			//loc_2340d628
			if (Data_23492074 != 0)
			{
				(Data_23492074)(pIRD, &sp_0x18);
			}
			//->loc_2340d57c
		}
	}
}


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


/* 2340d764 / 234146a0 - todo */
void ir_user_send_data(int a, int b, int c)
{
	Data_23492078.wData_2 = a;
	Data_23492078.wData_4 = b;
	Data_23492078.bData_0 = c;

	OSMboxPost(Data_23492068, &Data_23492078);
}


/* 2340d784 / 234146c0 - todo */
void* ir_user_init(Struct_2340d784* r5)
{
	memcpy(&Data_2354bda4, r5, sizeof(Struct_2340d784));

	Data_23492068 = (void*) OSMboxCreate(0);
	Data_2349206c = (void*) OSMboxCreate(0);

#if 1 //VDR110
	if (Data_2354bda4.bData_20 != 0)
	{
		Data_23492074 = sub_2340d3ec;
	}

	if (Data_2354bda4.bData_21 != 0)
	{
		sub_23453d80();
	}
#endif

	OSTaskCreateExt(ir_user_in_thread, 0, &ir_thread_stack[THREAD_STACK_SIZE_IR_USER_IN-1]/*0x23549820*/,
			r5->threadPrioIR, r5->threadPrioIR, ir_thread_stack, THREAD_STACK_SIZE_IR_USER_IN, "IR_USER_IN" , 0x03);

	OSTaskCreateExt(uart_in_thread, 0, &uart_in_thread_stack[THREAD_STACK_SIZE_UART_IN-1]/*0x2354a4a0*/,
			r5->threadPrioUart, r5->threadPrioUart, uart_in_thread_stack, THREAD_STACK_SIZE_UART_IN, "STARTUP" , 0x03);

	return Data_2349206c;
}


/* 2340d840 / 2341475c - todo */
int ui_thread_create(UI_Thread_Params* pThreadParams/*r5*/)
{
	void* pStackTop;
	uint32_t retry = 16;
	int* pStack = 0;

	uint8_t res; //sp_0x2c;
	UI_Thread_Params sp_0x14;

	memcpy(&sp_0x14, pThreadParams, 24);

	sp_0x14.pSema = OSSemCreate(0);

	if (pThreadParams->threadFunc == 0)
	{
		//->loc_2340d92c
		return 1;
	}
	//0x2340d880
	if (Data_2354bda4.threadPrioUI == 0)
	{
		Data_2354bda4.threadPrioUI = Data_2354bda4.threadPrioUI_1;
		//->loc_2340d8a0
	}
	else
	{
		//0x2340d898
		res = OSTaskDelReq();
	}
	//loc_2340d8a0
	if (Data_2354bda4.threadPrioUI == Data_2354bda4.threadPrioUI_1)
	{
		Data_2354bda4.threadPrioUI = Data_2354bda4.threadPrioUI_2;
		pStack = Data_2354b124;
		//->loc_2340d8cc
	}
	//0x2340d8bc
	else if (Data_2354bda4.threadPrioUI == Data_2354bda4.threadPrioUI_2)
	{
		Data_2354bda4.threadPrioUI = Data_2354bda4.threadPrioUI_1;
		pStack = Data_2354a4a4;
	}
	//loc_2340d8cc -> loc_2340d920
	pStackTop = pStack + (0x320-1);
	while (retry--)
	{
		//loc_2340d8d8
#if 1
		console_send_string("ui_thread_create (ir_user.c): create thread\r\n");
#endif

		res = OSTaskCreateExt(pThreadParams->threadFunc, &sp_0x14, pStackTop,
				Data_2354bda4.threadPrioUI, Data_2354bda4.threadPrioUI,
				pStack, 0x320, pThreadParams->threadName, 3);

		if ((uint8_t)res == 40) //OS_ERR_PRIO_EXIST
		{
			//0x2340d918
			rtos_task_wait(10);
			//loc_2340d920
		}
		else
		{
			//loc_2340d934
			OSSemPend(sp_0x14.pSema, 0, &res);
#if 1
    		console_send_string("ui_thread_create (ir_user.c): thread is running successfully\r\n");
#endif
			OSSemDel(sp_0x14.pSema, 1, &res);

			return res;
		}
	} //while (retry--)
	//0x2340d928
	return 11;
}


/* sub_2340d95c / 23414878 - todo */
void ui_thread_delete()
{
	OSTaskDel(Data_2354bda4.threadPrioUI);
}


