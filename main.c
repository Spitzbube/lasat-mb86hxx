
#include "data.h"
#include "ucos_ii.h"


void main_base_init(void);
void main_console_init(void);
void main_usb_init(void);


/* 23400424 - todo */
void startup_thread()
{
	main_usb_init();

	while (1)
	{
#if 0
		console_send_string("startup_thread\r\n");
#endif
		//loc_234004ac
		rtos_task_wait(10);
	}
}

/* 234004b8 - todo */
int main()
{
	static uint32_t startup_thread_stack[THREAD_STACK_SIZE_STARTUP]; //2349c5a0 +0x320*4 = 2349D220

	main_base_init();
	main_console_init();

	OSInit();

	OSTaskCreateExt(startup_thread,
			0,
			&startup_thread_stack[THREAD_STACK_SIZE_STARTUP-1]/*2349d21c*/,
			THREAD_PRIO_STARTUP/*(6 << 3) | 7*/,
			THREAD_PRIO_STARTUP/*(6 << 3) | 7*/,
			startup_thread_stack,
			THREAD_STACK_SIZE_STARTUP,
			"STARTUP",
			0x03);

	OSStart(); 

    return 0;
}

