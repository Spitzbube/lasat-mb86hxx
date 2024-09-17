

#include <stdint.h>
#include "data.h"
#include "ucos_ii.h"
#include "ts_play.h"


int ts_play_thread_stack[THREAD_STACK_SIZE_TS_PLAY]; //235afe88 -> 235B0B08
Struct_235b0b08 Data_235b0b08; //235b0b08 /  / 23661dc8


/* 234188e4 - todo */
void ts_play_task()
{
	Data_235b0b08.Data_0 = 0;
	Data_235b0b08.Data_0x20 = 0;
	Data_235b0b08.Data_0x28 = 0;
	Data_235b0b08.Data_0x2c = 0;

	//TODO

	while (1)
	{
		//loc_23418900
		uint16_t r0 = 10;

		//TODO

		//loc_23418988
		rtos_task_wait(r0);
		//->loc_23418900
	} //while (1)
}


/* 23418b54 /  / 23424098 - complete */
int ts_play_init(Struct_23418b54* r4)
{
	extern void sub_23422334();
	Struct_23459168 sp_0x18;

	Data_235b0b08.Data_4 = r4->threadPrio;
	Data_235b0b08.Data_0x44 = r4->Data_4;
	Data_235b0b08.Data_0x50 = 0xff;
	Data_235b0b08.bData_0x54 = 0;
	Data_235b0b08.Data_0x48 = 0;
	Data_235b0b08.Data_0x4c = 0;
	Data_235b0b08.Data_0x40 = r4->Data_0;
	Data_235b0b08.Data_0x14 = r4->Data_8;

	sp_0x18.Data_0 = &Data_235b0b08;
	sp_0x18.Data_4 = sub_23422334;

	sub_23459168(&sp_0x18);

	sub_2345d594(&sp_0x18);

	OSTaskCreateExt(ts_play_task, 0, 
            &ts_play_thread_stack[THREAD_STACK_SIZE_TS_PLAY-1]/*0x235b0b04*/,
			r4->threadPrio, r4->threadPrio,
			ts_play_thread_stack, THREAD_STACK_SIZE_TS_PLAY,
			"TS_PLAY_Task", 3);

	return 0;
}


/* 23418bf0 /  / 23424134 - complete */
int sub_23418bf0(void)
{
	int r4;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	OS_ENTER_CRITICAL();

	r4 = Data_235b0b08.Data_0;

	OS_EXIT_CRITICAL();

	return r4;
}


