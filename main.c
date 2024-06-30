
#include "data.h"
#include "ucos_ii.h"


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


/* 234017f0 / 234023e8 - todo */
void main_usb_init()
{
#if 0
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
#endif
	{
#if 0
		sub_2343a162(sub_23400120);
#endif
		usb_init();
#if 0
		MGC_usbInitController();
		usb_msd_init();
#endif
	}
	//loc_23401858
	return;
}


