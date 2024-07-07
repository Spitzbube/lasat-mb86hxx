
#include "data.h"
#include "ucos_ii.h"


void main_base_init(void);
void main_console_init(void);
void main_usb_init(void);
void main_network_init(void);
void main_inputhandler_init(void);


/* 23400158 - todo */
int main_process_uart_command(uint8_t* r4)
{
#if 0
	console_send_string("main_process_uart_command (todo.c): TODO\r\n");
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "main_process_uart_command: r4='%s'\r\n", r4);
		console_send_string(debug_string);
	}
#endif

//	else
	{
		//->loc_2340032c
		console_send_string("\n unknown com");
		return 0;
	}
}


/* 23400424 - todo */
void startup_thread()
{
	main_network_init();
	main_usb_init();
	inputhandler_register_uart_callback(main_process_uart_command);
	main_inputhandler_init();

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

