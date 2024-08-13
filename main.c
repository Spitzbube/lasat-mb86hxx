
#include "data.h"
#include "ucos_ii.h"
#include "startup.h"
#include "usb_msd.h"
#include "sub_2345609c.h"


void* (*main_pfHandleUsbStorage)(void); //23491d88 +0 /  / 234c0188 +0x10


extern void sub_23439f6a();
extern void sub_23439fc4();
extern void sub_2343a02e();
extern void sub_2343a11c();
extern void sub_2343a136();
extern void sub_23412da8();


/* 234000a0 /  / 234000e0 - todo */
void* main_handle_usb_storage(void)
{
	Struct_23415f44 sp;

#if 1
	console_send_string("main_handle_usb_storage (todo.c): TODO\r\n");
#endif

	usb_lock();

	USB_MSD_Device* r0 = musb_msd_get_device(0);
	if (r0 != 0)
	{
		sp.Data_0x18 = r0;
		sp.Data_0 = sub_23439f6a;
		sp.Data_4 = sub_23439fc4;
		sp.Data_8 = sub_2343a02e;
		sp.Data_12 = sub_2343a11c;
		sp.Data_16 = sub_2343a136;
		sp.Data_20 = sub_23412da8;

#if 0

#ifndef DVBC_RADIO
		sub_2345609c/*sub_2341f814*/(sp);
#endif

		sub_23415f44(&sp);

		if (0 != sub_23415fb4(0))
		{
			//loc_23400108
			sub_23415ff8/*2341da0c*/(0);
		}
		//loc_23400110
#endif
	}
	else
	{
		//loc_23400108
		sub_23415ff8/*2341da0c*/(0);
	}

	usb_unlock();

	return 0;
}


/* 23400120 /  / 234001dc - todo */
void main_on_usb_storage(void)
{
#if 1
	console_send_string("main_on_usb_storage (main.c)\r\n");
#endif

	main_pfHandleUsbStorage = main_handle_usb_storage;
}


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
	main_clkpwr_init();
	main_powermode_init();
	main_frontend_i2c_init();
	main_tsd_bm_init();
	main_psi_init();
	main_dma_init();
	main_flash_init();
#if 1 //Only v241!!!
	main_vdec_init();
#endif
	main_video_hdmi_init();
	main_audio_init();
	main_channel_init();
	main_pes_init();
#if 0 //v290
	sub_23402948();
#endif
	main_frontend_init();
	main_scan_init();
	main_frontpanel_init();
	main_graphic_init();
	main_network_init();
	sub_23401504();
	sub_234014dc();
	inputhandler_register_uart_callback(main_process_uart_command);
	main_usb_init();
	main_ts_play_init();
	sub_234018c8();
	main_set_power_mode();
	main_inputhandler_init();

	while (1)
	{
		//loc_23400498
		if (main_pfHandleUsbStorage != 0)
		{
			void* p = (main_pfHandleUsbStorage)();
			main_pfHandleUsbStorage = p;
		}
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

