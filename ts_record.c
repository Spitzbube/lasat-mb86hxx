
#include "data.h"
#include "ucos_ii.h"
#include "timer.h"
#include "ts_record.h"


uint32_t ts_record_thread_stack[THREAD_STACK_SIZE_TS_RECORD]; //0x237bec10 -> 237BF890
struct
{
	int fill_0[16]; //0
	int Data_0x40; //0x40
	int fill_0x44[30]; //0x44
	void (*Data_0xbc)(void*); //0xbc
	void (*Data_0xc0)(void*); //0xc0
	int Data_0xc4; //0xc4
	void* arhTsd[10]; //0xc8 = 237bf958
	void* hBm; //0xf0 = 237BF980
	int Data_0xf4; //0xf4 = 237BF984
	int threadPrio; //0xf8
	void* hTimer; //0xfc = 237BF98C
	int fill_0x100[196]; //0x100
	int Data_0x410; //0x410 = 237BFCA0
	int Data_0x414; //0x414 = 237BFCA4
	int Data_0x418; //0x418 = 237BFCA8
	int Data_0x41c; //0x41c = 237BFCAC

} Data_237bf890; //237bf890


/* 23457c58 - complete */
static void sub_23457c58(void)
{
#if 1
	console_send_string("sub_23457c58 (todo.c): TODO\r\n");
#endif

	sub_234216fc(Data_237bf890.arhTsd[0]);
}


/* 23457c64 - complete */
static int sub_23457c64(void)
{
#if 1
	console_send_string("sub_23457c64 (todo.c): TODO\r\n");
#endif

	Data_237bf890.Data_0x40++;

	return 0;
}


/* 23458380 /  / 23421a90 - todo */
static void ts_record_task()
{
#if 1
	console_send_string("ts_record_task (todo.c): TODO\r\n");
#endif

	//TODO

	while (1)
	{
		//loc_234583a0
		if ((Data_237bf890.Data_0xf4 & 0xffff) == 0)
		{
			//0x234583b0
			if (Data_237bf890.Data_0xbc != NULL)
			{
				(Data_237bf890.Data_0xbc)(&Data_237bf890.Data_0xf4);

				Data_237bf890.Data_0xbc = NULL;
			}
			//loc_234583c8
			rtos_task_wait(0xffff);
			//->loc_234583a0
		}
		else
		{
			//->loc_234583d4
			if (Data_237bf890.Data_0xc0 != NULL)
			{
				(Data_237bf890.Data_0xc0)(&Data_237bf890.Data_0xf4);

				Data_237bf890.Data_0xc0 = NULL;
			}
			//loc_234583ec
			if (Data_237bf890.Data_0xbc != NULL)
			{
				(Data_237bf890.Data_0xbc)(&Data_237bf890.Data_0xf4);

				Data_237bf890.Data_0xbc = NULL;
			}
			else
			{
				//loc_23458408
				rtos_task_wait(4);
			}
			//loc_23458410

			//TODO
		}
	}

}


/* 23458640 /  / 23421d50 - todo */
int ts_record_init(TS_Record_Params* r5)
{
	TSD_PesParserParams tsdParams;
	Timer_Params timerParams; //sp_0x14

#if 0
	console_send_string("ts_record_init (todo.c): TODO\r\n");
#endif

	tsdParams.bData_0 = 2;
	tsdParams.bData_1 = 1; //r1
	tsdParams.Data_4.Data_4 = 2;
	tsdParams.pid = 0; //r4
	tsdParams.Data_4.pidChannel = 8;
	tsdParams.Data_4.Data_0 = 0x10000;
	tsdParams.Data_0x38 = 0; //r4
	tsdParams.Data_4.bufferAddress = r5->bufferAddress;
	tsdParams.Data_4.bufferSize = r5->bufferSize;
	tsdParams.Data_4.Data_0x14 = 1; //r1
	tsdParams.Data_4.Data_0x18 = 0; //r4
	tsdParams.Data_4.Data_0x2c = 0; //r6 
	tsdParams.Data_4.Data_0x1c = 0; //r4
	tsdParams.Data_4.handleOverflow = sub_23457c58;

	timerParams.Data_0 = 100;

	tsdParams.Data_4.Data_0x30 = 0; //r6 
	tsdParams.Data_4.Data_0x24 = 0; //r6 

	timerParams.Data_8 = sub_23457c64;

	tsdParams.Data_4.Data_0x28 = 0; //r6 

	timerParams.Data_4 = &Data_237bf890; //r7

	Data_237bf890.hTimer = timer_user_open(&timerParams);

	Data_237bf890.Data_0x410 = 0; //r6; //r4 = 0;
	Data_237bf890.Data_0x414 = r5->Data_8;
	Data_237bf890.Data_0x418 = 3;
	Data_237bf890.Data_0xc4 = 0; //r6
	Data_237bf890.Data_0x41c = r5->Data_0xc;

	for (uint8_t i = 0; i < 10; i++)
	{
		//loc_234586f4
		sub_234210ec(&Data_237bf890.arhTsd[i], &tsdParams, (i == 0));

		tsdParams.Data_4.pidChannel++;
	}

	Data_237bf890.hBm = tsd_get_bm_handle(Data_237bf890.arhTsd[0]);

	Data_237bf890.threadPrio = r5->threadPrio;

	OSTaskCreateExt(ts_record_task, 0, 
		&ts_record_thread_stack[THREAD_STACK_SIZE_TS_RECORD-1]/*0x237bf88c*/,
		r5->threadPrio, r5->threadPrio,
		&ts_record_thread_stack[0], THREAD_STACK_SIZE_TS_RECORD,
		"TS_Record Buffer_Task", 3);

	return 0;
}


/* 23458874 - complete */
int sub_23458874(void)
{
#if 0
	console_send_string("sub_23458874 (todo.c): TODO\r\n");
#endif

	int r4;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	OS_ENTER_CRITICAL();

	r4 = Data_237bf890.Data_0xf4;

	OS_EXIT_CRITICAL();

	return r4;
}


/* 2345897c - todo */
void ts_record_get_tsd_handles(TS_Record_Handles* a)
{
#if 0
	console_send_string("ts_record_get_tsd_handles (todo.c): TODO\r\n");
#endif

	a->arhTsd = &Data_237bf890.arhTsd[0];
	a->phBm = &Data_237bf890.hBm;
}


