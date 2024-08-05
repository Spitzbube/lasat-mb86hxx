
#include "data.h"
#include "ir_user.h"
#include "ir.h"
#include "vfd.h"
#include "powermode.h"
#include "av.h"
#include "flash.h"
#include "i2c.h"
#include "lastmode.h"
#include "thumb2.h"
#include "sub_2340a6a0.h"
#include "frontend.h"
#include "fe_manager.h"
#include "audec.h"
#include "auout.h"
#include "thumb2.h"
#include "hdmi.h"
#include "clkpwr.h"
#include "videc.h"
#include "graphic.h"
#include "sub_23419cd0.h"
#include "radiotext.h"
#include "channel_list_update.h"
#include "scan.h"


extern int main_process_uart_command(uint8_t*);


uint8_t main_bNeedSetup = 0; //23491d8c +0
Uart_Module* main_hUart0 = 0; //23491d90 +4
void* Data_23491d94 = 0; //23491d94 +8
void* main_hI2c0 = 0; //23491d98 +12 = 0xc
Struct_234a73e8* main_hPSIDecoder1 = 0; //23491d9c / 234ac4d0 +16 = 0x10
Struct_234a73e8* main_hPSIDecoder2 = 0; //23491da0 +20 = 0x14
int Data_23491da4 = 0; //23491da4 +0x18
int Data_23491da8 = 0; //23491da8
void* main_hHdmi = 0; //23491dac
Struct_235f2e2c* main_hFlash = 0; //23491db0 +0x24
Struct_2354dd70* main_hFrontend1 = 0; //23491db4 +40 = 0x28 //Data_234ac4e8
Struct_2354dd70* Data_23491db8 = 0; //23491db8 +44 = 0x2c //Data_234ac4ec
MemBlk_Handle* main_hMemBlk1 = 0; //23491DBC +0x30
MemBlk_Handle* main_hMemBlk2 = 0; //23491dc0 +0x34
Struct_20611068* main_hUsbGpio = 0; //23491dc4 +0x38 
Lastmode_Instance* main_hLastmode = 0; //23491dc8 +0x3c
void* main_hPCR_TSD_Handle = 0; //23491dcc +0x40
void* main_hPESParserAudio = 0; //23491dd0 +0x44
void* main_hAuOut = 0; //23491dd4  +0x48
void* main_hAudec2 = 0; //23491dd8 +0x4c
void* main_hAudec1 = 0; //23491ddc +0x50
void* main_hAudec0 = 0; //23491de0 +0x54
void* main_hAudec4 = 0; //23491de4 +0x58
void* main_hAudec5 = 0; //23491de8 +0x5c
void* main_hAudecRadioText = 0; //23491dec +0x60
void* main_hCurrentPCR_TSD_Handle = 0; //23491e08
void* main_hPESParserVideo = 0; //23491e0c +0x80 / 234ac510


struct
{
	int fill_0[8]; //0
	//size???
} Data_2349d230; //2349d230 //TODO

struct
{
	int fill_0[0x8000]; //0
	//size????
} Data_2349d250; //2349d250 


/* 23400510 - complete */
int sub_23400510(int a)
{
#if 0
	char str[32];
	sprintf("sub_23400510 (main.c): a=%d\r\n", a);
	console_send_string(str);
#endif
	return 0;
}


/* 23400518 - complete */
void sub_23400518()
{
#if 0
	console_send_string("sub_23400518 (todo.c): TODO\r\n");
#endif

	/* empty */
}


/* 2340051c - complete */
int sub_2340051c()
{
#if 0
	console_send_string("sub_2340051c (todo.c): TODO\r\n");
#endif

	return 0;
}


/* 2340052c - complete */
void sub_2340052c()
{
#if 0
	console_send_string("loc_2340052c (todo.c): TODO\r\n");
#endif

	/* empty */
}


/* 23400560 - todo */
void main_on_new_psi_decoder1(Struct_234a73e8* h)
{
	main_hPSIDecoder1 = h;
}


/* 23400570 - todo */
void main_on_new_psi_decoder2(Struct_234a73e8* h)
{
	main_hPSIDecoder2 = h;
}


struct
{
	int pin; //0
	int delay; //4

}
Data_23491df4[2] = //23491df4
{
		{86, 1},
		{87, 1}
};


/* 23400580 / 234011e4 - complete */
void main_frontend_i2c_init()
{
	Struct_20611068* hGpio;
	Struct_2341cd7c i2cParams;
	Struct_20401328 gpioParams;
	uint32_t i = 2;

	gpioParams.dwInFunction = 0xff;
	gpioParams.dwOutFunction = 0;

	while (i--)
	{
		//loc_234005a4
		gpioParams.bPin = Data_23491df4[i].pin;

		gpio_open(&gpioParams, &hGpio);

		gpio_set(hGpio, 1);
		rtos_task_wait((uint16_t)Data_23491df4[i].delay);

		gpio_set(hGpio, 0);
		rtos_task_wait((uint16_t)Data_23491df4[i].delay);

		gpio_set(hGpio, 1);

		gpio_close(hGpio);
	}
	//0x23400608
	i2cParams.bData_0 = 0; // I2C0
	i2cParams.bData_1 = 0;
	i2cParams.clkPin = 25;
	i2cParams.dataPin = 24;

	i2c_open(&i2cParams, &main_hI2c0);
}


/* 23400634 - todo / 23401298 - todo */
void main_flash_init()
{
	int sp_0x24;
	Lastmode_Params lastmode_params;

	flash_init();

	sp_0x24 = 1;

	flash_open(&sp_0x24, &main_hFlash);

	if (main_hFlash != 0)
	{
		lastmode_params.pFlash = main_hFlash;
		lastmode_params.pBuffer = &Data_2349d230;
		lastmode_params.Data_0 = 16;
		lastmode_params.Data_4 = 0x40370000;
		lastmode_params.Data_8 = 16;

		main_hLastmode = lastmode_init(&lastmode_params);

		Struct_23419cd0 sp4 = {0x40380000, 0, 0}; //23487b5c

		sp4.hFlash = main_hFlash;
		sp4.Data_8 = (void*) sub_234019e0(0x20000);

		sub_23419cd0(&sp4);
	}
	//loc_234006bc
}


/* 234006c4 - complete */
void main_base_init()
{
	ARM1176_INTR_Initialise();
	intr_init();
	gpreg_init();
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


/* 23400768 / 234014c4 - complete */
void main_audio_init()
{
	Struct_234298cc sp;

	sp.pFlash = main_hFlash;
	sp.Data_4 = 0x40200000;

	audec_init(&sp);

#if V241
	aout_init(0x22fffc00);
#else
	aout_init( sub_234019e0(0x150) );
#endif
}


/* 23400798 - todo */
int sub_23400798()
{
#if 0
	console_send_string("sub_23400798 (todo.c): TODO\r\n");
#endif

	Struct_23429ae8 sp8;
	int sp4;

	sp8.Data_0 = 1;
	sp8.Data_4 = 16;
	sp8.bmHandle = tsd_get_bm_handle(main_hPESParserAudio);
	sp8.audioOutHandle = main_hAuOut;

	if (0 == audec_open_decoder(&sp8, &main_hAudec1))
	{
		audec_get_status(main_hAudec1);
	}

	sp8.Data_0 = 2;

	if (0 == audec_open_decoder(&sp8, &main_hAudec2))
	{
		audec_get_status(main_hAudec2);
	}

	sp8.Data_0 = 0;

	if (0 == audec_open_decoder(&sp8, &main_hAudec0))
	{
		audec_get_status(main_hAudec0);
	}

	sp8.Data_0 = 4;

	if (0 == audec_open_decoder(&sp8, &main_hAudec4))
	{
		audec_get_status(main_hAudec4);
	}

	sp8.Data_0 = 5;

	if (0 == audec_open_decoder(&sp8, &main_hAudec5))
	{
		audec_get_status(main_hAudec5);
	}

	sp4 = sub_234019e0(sizeof(AUDEC_RadioText));

	main_hAudecRadioText = audec_set_params(&sp4);
	if (main_hAudecRadioText != 0)
	{
		radiotext_init();
	}

	return 0;
}


/* 2340088c / 23402068 - todo */
void main_powermode_init()
{
	extern void sub_2343b992();
	extern void sub_2343cc34();

	Powermode_Init_Params params;

	params.gpioPin = 6;
	params.initialState = 1;
	params.pfOnSwitchOff = 0;
	params.pfOnSwitchOn = 0;
	params.Data_16 = sub_2343cc34;
	params.Data_20 = sub_2343b992;

	powermode_init(&params);
}


/* 234008d0 / 23401fd4 - todo */
void main_scan_init(void)
{
	Scan_Params sp;

	sp.threadPrio = THREAD_PRIO_SCAN;
#ifndef V241
	sp.bData_2 = 1;
#endif

	scan_init(&sp);
}


/* 23400964 / 23401fec - todo */
int main_clkpwr_init()
{
	clkpwr_reset();
	clkpwr_low_power();

	return clkpwr_full_power();
}


/* 23400978 / 23402150 - todo */
void main_inputhandler_init()
{
	void* pMBox; //r4;
	UI_Thread_Params sp_0x74;
	Struct_2340d784 sp_0x5c;
	Struct_2340bf0c sp_0x28;
	Channel channel;

	ir_init(ir_user_send_data, 0x3b);

	menu_main_adapt_items(sub_2343b946/*thumbb2.c*/);
	
	memset(&sp_0x5c, 0, sizeof(Struct_2340d784));

	sp_0x5c.threadPrioIR = THREAD_PRIO_IR_USER_IN;
	sp_0x5c.threadPrioUart = THREAD_PRIO_UART_IN;
	sp_0x5c.threadPrioUI_1 = THREAD_PRIO_UI_1;
	sp_0x5c.threadPrioUI_2 = THREAD_PRIO_UI_2;
	sp_0x5c.bData_20 = 1;
	sp_0x5c.bData_21 = 1; //(sub_23418e98() == 4)? 1: 0;
	//0x234009dc
	pMBox = ir_user_init(&sp_0x5c);
	if (pMBox != 0)
	{
		//0x234009ec
		sp_0x74.Data_20 = 0;
		sp_0x74.threadFunc = mainfunction_thread;
		sp_0x74.threadName = "MainInputHandler";
		sp_0x74.pMBox = pMBox;

		sub_2343d458(&sp_0x74);

#if 1
		if (main_bNeedSetup != 0)
#else
		if (1)
#endif
		{
			menu_guided_install_entry(&sp_0x74);
			//loc_23400a28
		}
		else
		{
			//loc_23400a30
			int state = powermode_get_state();
			if (state == 1)
			{
				//0x23400a3c
				ui_thread_create(&sp_0x74);

				sub_2340bf0c(&sp_0x28);

				channel_start_number(&channel, 
					sp_0x28.wCurrentChannel, sp_0x28.wCurrentChannel);
				//->loc_23400a28
			}
			//loc_23400a60
			else if (state == 2)
			{
				//0x23400a68
				sp_0x74.Data_20 = 0;
				sp_0x74.pMBox = pMBox;
				sp_0x74.threadFunc = standby_thread;
				sp_0x74.threadName = "MainInputHandler";

				ui_thread_create(&sp_0x74);
			}
			//loc_23400a28
		} 
	}
	//loc_23400a28
}


/* 23400a8c / 2340154c - todo */
void main_tsd_bm_init()
{
	TSD_InitParams sp_0x1c;

	Struct_2342c4f8_Inner8 sp_0x14;

	Struct_2342c4f8 sp4;

	bm_init();

	memset(&sp_0x1c, 0, sizeof(sp_0x1c));

	memset(&sp4, 0, sizeof(sp4));

	sp_0x1c.wData_0 = 0x24;
	sp_0x1c.wData_2 = 0x23;
	sp_0x1c.wData_4 = 0x26;
	sp_0x1c.wData_6 = 0x1a;
	sp_0x1c.wData_8 = 0x1c;
	sp_0x1c.wData_10 = 0x1b;
	sp_0x1c.wData_12 = 0x1d;
	sp_0x1c.wData_14 = 0x1f;
	sp_0x1c.wData_16 = 0x1e;
	sp_0x1c.wData_18 = 0x22;
	sp_0x1c.wData_20 = 0x25;
	sp_0x1c.wData_24 = 0x38;
	sp_0x1c.wData_26 = 0x3d;
	sp_0x1c.wData_28 = 0x3c;
	sp_0x1c.wData_30 = 0x33;
	sp_0x1c.wData_32 = 0x34;
	sp_0x1c.wData_34 = 0x30;
	sp_0x1c.wData_36 = 0x31;
	sp_0x1c.wData_38 = 0x32;
	sp_0x1c.wData_40 = 0x35;
	sp_0x1c.wData_42 = 0x36;
	sp_0x1c.wData_44 = 0x37;
	sp_0x1c.wData_48 = 0x4C;
	sp_0x1c.wData_50 = 0x47;
	sp_0x1c.wData_52 = 0x46;
	sp_0x1c.wData_54 = 0x4b;
	sp_0x1c.wData_56 = 0x4a;
	sp_0x1c.wData_58 = 0x4e;
	sp_0x1c.wData_60 = 0x44;
	sp_0x1c.wData_62 = 0x4d;
	sp_0x1c.wData_64 = 0x49;
	sp_0x1c.wData_66 = 0x45;
	sp_0x1c.wData_68 = 0x48;

	tsd_init(&sp_0x1c);

	sp_0x14.Data_4;
	sp_0x14.Data_4 = 0x30;
	sp_0x14.Data_0 = 0; //r4

	sp4.Data_0 = 0; //r4
	sp4.Data_4 = 1; //r5
	sp4.Data_8 = &sp_0x14;
	sp4.Data_12 = 0; //r4

	sub_2342c4f8(&sp4);

	sp4.Data_0 = 2;
	sp4.Data_4 = 0; //r4

	sp_0x14.Data_0 = 1; //r5

	sub_2342c4f8(&sp4);

	sp4.Data_0 = 3;
	sp4.Data_4 = 0; //r4

	sp_0x14.Data_0 = 1; //r5

	sub_2342c4f8(&sp4);

	sub_23435fc4(); //-> dpll.c / sync.c
}


/* 23400c54 / 234016f0 - todo */
void main_psi_init()
{
#if 0
	struct
	{
		int fill_0[36]; //0
		//0x90
	} sp_0x14;

	console_send_string("main_psi_init (todo.c): TODO\r\n");

	memset(&sp_0x14, 0, 0x90);

	sub_234063cc(0);

	sub_2340199c(0x1000);

	//TODO
#endif

	PSI_Params sp_0x14;
	MemBlk_Params sp4;

#if 0
	console_send_string("main_psi_init (todo.c): TODO\r\n");
#endif

	memset(&sp_0x14, 0, sizeof(sp_0x14));

	psi_init(0);

	sp_0x14.onNewPSIDecoder = main_on_new_psi_decoder1;
	sp_0x14.threadPrio = THREAD_PRIO_PSI_1;
	sp_0x14.bufferParams.wData_0 = 0; //r6

	sp_0x14.bufferParams.PAT_bufferAddress = sub_2340199c(0x1000);
	sp_0x14.bufferParams.PAT_bufferSize = 0x1000; //r4
	sp_0x14.bufferParams.PMT_bufferAddress = sub_2340199c(0x1000);
	sp_0x14.bufferParams.PMT_bufferSize = 0x1000; //r4
	sp_0x14.bufferParams.SDT_BAT_bufferAddress = sub_2340199c(0x1000);
	sp_0x14.bufferParams.SDT_BAT_bufferSize = 0x1000; //r4
	sp_0x14.bufferParams.NIT_bufferAddress = sub_2340199c(0x1000);
	sp_0x14.bufferParams.NIT_bufferSize = 0x1000; //r4
	sp_0x14.bufferParams.EIT_bufferAddress = sub_2340199c(0x4000);
	sp_0x14.bufferParams.EIT_bufferSize = 0x4000; //r5
	sp_0x14.bufferParams.TDT_bufferAddress = sub_2340199c(0x1000);
	sp_0x14.bufferParams.TDT_bufferSize = 0x1000; //r4
	sp_0x14.bufferParams.Data_0x24 = sub_2340199c(0x2000);
	sp_0x14.bufferParams.Data_0x28 = 0x2000;
	sp_0x14.bufferParams.Data_0x1c = sub_2340199c(0x1000);
	sp_0x14.bufferParams.Data_0x20 = 0x1000; //r4
	sp_0x14.bufferParams.Data_0x54 = sub_2340199c(0x4000);
	sp_0x14.bufferParams.Data_0x58 = 0x4000; //r5
	sp_0x14.bufferParams.Data_0x5c = sub_2340199c(0x1000);
	sp_0x14.bufferParams.Data_0x60 = 0x1000; //r4
	sp_0x14.bufferParams.Data_0x64 = sub_2340199c(0x1000);
	sp_0x14.bufferParams.Data_0x68 = 0x1000; //r4
	sp_0x14.bufferParams.Data_0x6c = sub_2340199c(0x1000);
	sp_0x14.bufferParams.Data_0x70 = 0x1000; //r4

	extern void sub_2343cb0e();
	extern void sub_2343cc7c();
	extern void sub_2343ccee();

	sp_0x14.Data_0x7c = sub_2343cb0e;
	sp_0x14.Data_0x88 = sub_2343cc7c; //r7
	sp_0x14.Data_0x8c = sub_2343ccee;

	psi_open(&sp_0x14);

	while (main_hPSIDecoder1 == 0)
	{
		//sub_23400d7c
		rtos_task_wait(1);
	}
	//0x23400d90
	memset(&sp_0x14, 0, sizeof(sp_0x14));

	sp_0x14.onNewPSIDecoder = main_on_new_psi_decoder2;
	sp_0x14.threadPrio = THREAD_PRIO_PSI_2;
	sp_0x14.bufferParams.wData_0 = 3;

	sp_0x14.bufferParams.PAT_bufferAddress = sub_2340199c(0x1000);
	sp_0x14.bufferParams.PAT_bufferSize = 0x1000; //r4
	sp_0x14.bufferParams.PMT_bufferAddress = sub_2340199c(0x1000);
	sp_0x14.bufferParams.PMT_bufferSize = 0x1000; //r4
	sp_0x14.bufferParams.Data_0x5c = sub_2340199c(0x1000);
	sp_0x14.bufferParams.Data_0x60 = 0x1000; //r4
	sp_0x14.bufferParams.Data_0x64 = sub_2340199c(0x1000);
	sp_0x14.bufferParams.Data_0x68 = 0x1000; //r4
	sp_0x14.Data_0x80 = 0; //r6
	sp_0x14.Data_0x84 = 0; //r6
	sp_0x14.Data_0x7c = 0; //r6
	sp_0x14.Data_0x88 = sub_2343cc7c; //r7
	sp_0x14.Data_0x8c = 0; //r6

	psi_open(&sp_0x14);

	while (main_hPSIDecoder2 == 0)
	{
		//loc_23400e14
		rtos_task_wait(1);
	}
	//0x23400e28
	sp4.addr = sub_234019e0(0x1db800);
	sp4.size = 0x1db800;

	main_hMemBlk1 = memblk_open(&sp4);
}


/* 23400e4c / 234028b4 - complete */
int main_pes_init(void)
{
	TSD_PesParserParams sp_0x58;
	AUOUT_OpenParams aoutParams;

#if 0
	console_send_string("main_pes_init (todo.c): TODO\r\n");
#endif

#if 0 //V241
	sp_0x58.Data_4.pidChannel = 9;
	sp_0x58.Data_0x38 = 0; //r4
	sp_0x58.bData_0 = 0; //r4
	sp_0x58.Data_4.bufferAddress = sub_2340199c(0x3ffc00);
	sp_0x58.bData_1 = 0; //r4
	sp_0x58.pid = 0; //r4
	sp_0x58.Data_4.Data_4 = 0; //r4
	sp_0x58.Data_4.bufferSize = 0x3ffc00; //r7
	sp_0x58.Data_4.Data_0x14 = 1; //r5
	sp_0x58.Data_4.Data_0x18 = 0; //r4
	sp_0x58.Data_4.Data_0x1c = 0; //r4
	sp_0x58.Data_4.handleOverflow = 0; //r4
	sp_0x58.Data_4.Data_0x24 = 0; //r4
	sp_0x58.Data_4.Data_0x28 = 0; //r4
	sp_0x58.Data_4.Data_0x2c = 0; //r4
	sp_0x58.Data_4.Data_0x30 = 0; //r4

	tsd_open_pes_parser(&main_hPESParserVideo, &sp_0x58);
#endif

#if 1
	sp_0x58.bData_0 = 0; //r4
	sp_0x58.bData_1 = 0xff; //r6
	sp_0x58.Data_4.pidChannel = 8;
	sp_0x58.pid = 0; //r4
	sp_0x58.Data_0x38 = 0; //r4
	sp_0x58.Data_4.Data_4 = 0; //r4

	sp_0x58.Data_4.bufferAddress = sub_2340199c(0x10000);
	sp_0x58.Data_4.bufferSize = 0x10000; //r7
	sp_0x58.Data_4.Data_0x14 = 1; //r8

	sp_0x58.Data_4.Data_0x18 = 0; //r4
	sp_0x58.Data_4.Data_0x1c = 0; //r4
	sp_0x58.Data_4.handleOverflow = 0; //r4
	sp_0x58.Data_4.Data_0x24 = 0; //r4
	sp_0x58.Data_4.Data_0x28 = 0; //r4
	sp_0x58.Data_4.Data_0x2c = 0; //r4
	sp_0x58.Data_4.Data_0x30 = 0; //r4

	tsd_open_pes_parser(&main_hPESParserAudio, &sp_0x58);
#endif

	if (main_hPESParserAudio != 0)
	{
		aoutParams.enableSPDIF = 1; //r8
		aoutParams.spdifBufferAddress = sub_2340199c(0x20000);
		aoutParams.spdifBufferSize = 0x20000; //r5
		aoutParams.i2s0BufferAddress = sub_2340199c(0x20000);
		aoutParams.i2s0BufferSize = 0x20000; //r5

		aoutParams.speakerArr[1] = AUOUT_SPEAKER_RIGHT; //2;
		aoutParams.speakerArr[2] = AUOUT_SPEAKER_UNDEF; //-1;
		aoutParams.speakerArr[0] = AUOUT_SPEAKER_LEFT; //0; //r4

		aoutParams.Data_0x4c = sub_23409770;
		aoutParams.Data_0x50 = sub_23409788;

		auout_open(&aoutParams, &main_hAuOut);

		sub_23400798();

		if (main_hPCR_TSD_Handle == 0)
		{
			sp_0x58.Data_4.Data_0x1c = 0; //r4
			sp_0x58.Data_4.Data_4 = 0; //r4
			sp_0x58.Data_4.Data_0 = 0x10000; //r7;
			sp_0x58.Data_4.pidChannel = 18;
			sp_0x58.Data_4.Data_0x14 = 1; //r8;
			sp_0x58.Data_4.Data_0x18 = 0; //r4
			sp_0x58.Data_4.handleOverflow = 0; //r4
			sp_0x58.Data_4.Data_0x24 = 0; //r4
			sp_0x58.Data_4.Data_0x28 = 0; //r4
			sp_0x58.Data_4.Data_0x2c = 0; //r4
			sp_0x58.Data_4.Data_0x30 = 0; //r4

			sp_0x58.Data_4.bufferAddress = sub_2340199c(0x4000);
			sp_0x58.Data_4.bufferSize = 0x4000;

			sp_0x58.bData_0 = 0; //r4
			sp_0x58.bData_1 = 0xff; //r6;
			sp_0x58.pid = 0; //r4
			sp_0x58.Data_0x38 = 0; //r4

			tsd_open_pes_parser(&main_hPCR_TSD_Handle, &sp_0x58);
		}
	}
	//23400F90
	return 0;
}


#if 1
extern int sub_23401e92(uint8_t, uint8_t);
extern int sub_23401ea4(Struct_2340e754*, int);
extern void sub_23401efc();
extern void sub_23401fe4();
extern void sub_23402060();
extern void sub_2340201a();
extern void sub_234020b8();
extern void sub_234020c2();
extern void sub_2340c318();
extern void sub_2340c970_();
extern void sub_2340ca9c();
extern void sub_23402df4();
extern void sub_23402e8e();
extern void sub_23402b6c();
extern void sub_23402c9a();
extern void sub_23402da0();
extern void sub_23402d0c();
extern void sub_23403160();
extern void sub_23402e68();
extern void sub_23402280();
extern void sub_2340229c();
extern void sub_23402364();
extern void sub_2340246c();
extern void sub_234024ac();
extern void sub_2340251c();
extern void sub_2340ef00();
extern void sub_2340eee0();
#else
extern void sub_23403d60();
extern void sub_23403700();
extern void DEM_86668_SearchTransponder();
extern void DEM_86668_GetLock();
extern void sub_23403d14();
extern void sub_23403ba6();
extern void sub_23403cb2();
extern void sub_234040dc();
#endif


/* 23400fa0 / 234019b4 - todo */
void main_frontend_init()
{
	typedef int (*func)();

	User_Settings sp_0x94;
	fe_manager_Params sp_0x90;
	Struct_2340e754 sp_0x7c;
#if 0
	func sp_0x50[11] = //23487b68
	{
			sub_23401e92,
			sub_23401ea4,
			sub_23401efc,
			sub_23401fe4,
			sub_23402060,
			sub_2340201a,
			sub_234020b8,
			sub_234020c2,
			sub_2340c318,
			sub_2340c970_,
			sub_2340ca9c
	};
#endif
	func sp_0x30[8] = //23487b94
	{
			sub_23402df4, //init
			sub_23402e8e, //set addresses
			sub_23402b6c, //tune
			sub_23402c9a, //get lock
			sub_23402da0,
			sub_23402d0c,
			sub_23403160,
			sub_23402e68
	};

	sp_0x90.threadPrio = THREAD_PRIO_FE_MANAGER;
#if 0
	sp_0x90.gpioPin = 0xff; //r5
#else
	sp_0x90.gpioPin = 0x4f;
#endif

	fe_manager_init(&sp_0x90);

#if 0 //Cable Frontends from V241
	User_Settings sp_0xe8;
	Struct_2340e754 sp_0xd0; //+0x14
	struct
	{
		func Data_0[8]; //0
		//0x20 = 32
	}
	sp_0x38[] = //234a3688
	{
		{
			sub_23403d60, //init
			sub_23403700, //set addresses
			DEM_86668_SearchTransponder, //tune
			DEM_86668_GetLock, //get lock
			sub_23403d14,
			sub_23403ba6,
			sub_23403cb2,
			sub_234040dc,
		},
#if 0
		{
			sub_234052c2,
			sub_23405312,
			sub_2340509c,
			sub_234051be,
			sub_23405668,
			sub_2340522e,
			sub_234055b4,
			sub_234052f2
		},
#endif
	};

	sp_0xd0.bData_8 = 0xc6;
	sp_0xd0.bData_12 = 0xff;
	sp_0xd0.bData_9 = 0x30;
	sp_0xd0.bData_13 = 0xff;
	sp_0xd0.bData_10 = 0xff;
	sp_0xd0.bData_17 = 0xff;
	sp_0xd0.bData_14 = 0xff;
	sp_0xd0.Data_4 = 3; //sb
	sp_0xd0.bData_11 = 86; //r7
	sp_0xd0.bData_15 = 0xff;
	sp_0xd0.bData_16 = 0xff;
	sp_0xd0.hI2c = main_hI2c0;
	//r4 = 0xff
	main_hFrontend1 = (void*) fe_manager_detect(&sp_0xd0, &sp_0x38[0]);
	if (main_hFrontend1 != 0)
	{
		//->loc_23401d20
		channel_handle_user_settings(1, &sp_0xe8);

		if (sp_0xe8.Data_0x10 & 0x80)
		{
			powermode_set_onoff_callbacks(channel_list_update_start, sub_2343deb4);
		}

		return;
	}
	//0x23401bbc

#else //Frontends from VDR110

#if 0 // Try FE type 1 with sp_0x50
	sp_0x7c.Data_4 = 1;
	sp_0x7c.bData_8 = 0xc0; //r6
	sp_0x7c.bData_9 = 0xd0;
	sp_0x7c.bData_12 = 0xff;
	sp_0x7c.bData_13 = 0xff;
	sp_0x7c.bData_10 = 0x16;
	sp_0x7c.bData_17 = 0xff;
	sp_0x7c.bData_14 = 0xff;
	sp_0x7c.bData_11 = 86; //r4;
	sp_0x7c.bData_15 = 0xff;
	sp_0x7c.bData_16 = 0xff;
	sp_0x7c.hI2c = main_hI2c0;

	main_hFrontend1 = (void*) fe_manager_detect(&sp_0x7c, &sp_0x50);

	if (main_hFrontend1 == 0)
	{
		//0x23401044
		sp_0x7c.bData_9 = 0xd4;

		main_hFrontend1 = (void*) fe_manager_detect(&sp_0x7c, &sp_0x50);
	}
#endif
	{
		//loc_2340105c
#if 0 // Try FE type 6 with sp4
		func sp4[11] = // 23487bb4;
		{
				sub_23402280,
				sub_2340229c,
				sub_23402364,
				sub_2340246c,
				sub_234024ac,
				sub_2340251c,
				sub_2340ef00,
				sub_2340eee0,
				sub_2340c318,
				sub_2340c970,
				sub_2340ca9c
		};

		sp_0x7c.Data_4 = 6;
		sp_0x7c.bData_8 = 0xc0; //r6
		sp_0x7c.bData_9 = 0xc8;
		sp_0x7c.bData_12 = 0xff;
		sp_0x7c.bData_13 = 0xff;
		sp_0x7c.bData_10 = 0xff;
		sp_0x7c.bData_14 = 0xff;
		sp_0x7c.bData_11 = 87;
		sp_0x7c.bData_15 = 0xff;
		sp_0x7c.bData_16 = 0xff;
		sp_0x7c.hI2c = main_hI2c0;

		/*Data_23491d8c.Data_0x2c*/Data_23491db8 = (void*) fe_manager_detect(&sp_0x7c, &sp4);
#endif

		if (main_hFrontend1 == 0)
		{
			//0x234010c4
#if 1 // Try FE type 3 with sp_0x30
			sp_0x7c.bData_8 = 0xc2;
			sp_0x7c.bData_12 = 0xff;
			sp_0x7c.bData_9 = 0x3a; //r8
			sp_0x7c.bData_13 = 0xff;
			sp_0x7c.bData_10 = 0xff;
			sp_0x7c.bData_17 = 0xff;
			sp_0x7c.bData_14 = 0xff;
			sp_0x7c.Data_4 = 3; //r6;
			sp_0x7c.bData_11 = 86; //r4;
			sp_0x7c.bData_15 = 0xff;
			sp_0x7c.bData_16 = 0xff;
			sp_0x7c.hI2c = main_hI2c0;

			main_hFrontend1 = (void*) fe_manager_detect(&sp_0x7c, &sp_0x30);

			if (main_hFrontend1 != 0)
			{
				//loc_2340111c
				channel_handle_user_settings(1, &sp_0x94); //Get the settings

				if (sp_0x94.Data_0x10 & (1 << 7)) //Channel list update enabled?
				{
					powermode_set_onoff_callbacks(channel_list_update_start, sub_2343deb4);
				}
				//loc_2340113c
				return;
			} //if (main_hFrontend1 != 0)
			else
#endif
			{
				//loc_23401144
				uint8_t r4;
				uint8_t sp_0x2c[] = {0xc0, 0xc6, 0, 0};

#if 1 // Try 2 x FE type 3 with sp_0x30
				sp_0x7c.bData_12 = 0xff;
				sp_0x7c.bData_9 = 0x3a; //r8
				sp_0x7c.bData_13 = 0xff;
				sp_0x7c.bData_10 = 0xff;
				sp_0x7c.bData_17 = 0xff;
				sp_0x7c.bData_14 = 0xff;
				sp_0x7c.Data_4 = 3; //r6;
				sp_0x7c.bData_11 = 86; //r4;
				sp_0x7c.bData_15 = 0xff;
				sp_0x7c.bData_16 = 0xff;
				sp_0x7c.hI2c = main_hI2c0;
				//r6 = &sp_0x2c
				for (r4 = 0; r4 < 2; r4++)
				{
					//loc_23401188
					sp_0x7c.bData_8 = sp_0x2c[r4];

					main_hFrontend1 = (void*) fe_manager_detect(&sp_0x7c, &sp_0x30);

					if (main_hFrontend1 != 0)
					{
						sub_23413358();
						//->loc_2340111c
						channel_handle_user_settings(1, &sp_0x94); //Get the settings

						if (sp_0x94.Data_0x10 & (1<< 7)) //Channel list update enabled?
						{
							powermode_set_onoff_callbacks(channel_list_update_start, sub_2343deb4);
						}
						//loc_2340113c
						return;
					}
					//loc_234011b0
				}
				//loc_234011c0
#endif
			}
		} //if (main_hFrontend1 == 0)
		//loc_234011c0
		if ((main_hFrontend1 == 0) && (/*Data_23491d8c.Data_0x2c*/Data_23491db8 == 0))
		{
			//0x234011cc
#if 0 // Try FE type 5
			sp_0x7c.Data_4 = 5;
			sp_0x7c.bData_14 = 0xff;
			sp_0x7c.bData_17 = 0xff;
			sp_0x7c.bData_15 = 0xff;

			main_hFrontend1 = (void*) fe_manager_detect(&sp_0x7c, 0);
#endif
		}
	}
	//loc_2340113c
#endif
	return;
}


/* 234011f4 - todo */
void main_channel_init()
{
	LastMode lastmode;
	int oldCrc;
	int calcCrc;
	int bVolume;

#if 0
	console_send_string("main_channel_init()\r\n");
#endif

	if (0 != sub_2340add4(0x40300000))
	{
		sub_2340aee4(0x40200000);

		sub_23438194(main_hLastmode);

		main_bNeedSetup = 1;
		//->loc_23401234
	}
	//loc_23401228
	if (main_bNeedSetup == 1)
	{
		//loc_23401234
		bVolume = 0;
	}
	else
	{
		//loc_2340123c
		lastmode_read(main_hLastmode, &lastmode, 0, sizeof(LastMode));

		oldCrc = lastmode.crc;
		lastmode.crc = 0;

		calcCrc = crc32((void*) &lastmode, sizeof(LastMode));
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "main_channel_init: oldCrc=0x%x, calcCrc=0x%x\r\n", oldCrc, calcCrc);
			console_send_string(debug_string);
		}
#endif
		if (oldCrc != calcCrc)
		{
			//->loc_23401234
			bVolume = 0;
		}
		else
		{
			//loc_23401274
			bVolume = lastmode.bVolume;
		}
	}
	//loc_23401274
	channel_init(bVolume);

	channel_load_lists();
}


/* 2340146c / 2340195c - complete */
void main_graphic_init()
{
#if 1 //Only v241!!!
	Struct_234539f0 sp4;

	sp4.Data_0 = 0x22000000;
	sp4.Data_4 = 0x22048000;
	sp4.Data_8 = 0x22090000;
	sp4.Data_12 = 0x22240000;
	sp4.threadPrio = THREAD_PRIO_GRAPHIC;
	sp4.Data_16 = sub_234256fc;

	graphic_init(&sp4);
#endif

	text_table_init(main_hFlash, 0x401b0000);
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


/*  / 234014a0 - todo */
void main_vdec_init(void)
{
	Struct_2345fd98 sp;

	sp.hFlash = main_hFlash;
	sp.Data_4 = 0x40200000;

	vdec_init(&sp);
}


/* 234014dc - complete */
void sub_234014dc()
{
#if 0
	console_send_string("sub_234014dc (todo.c): TODO\r\n");
#endif

	Struct_2343b8e6 sp;

	sp.Data_0 = 0x13;
	sp.Data_4 = 0xff;
	sp.Data_8 = 0x12;

	sub_2343b8e6(&sp);
}


/* 23401504 - todo */
void sub_23401504()
{
#if 0
	console_send_string("sub_23401504 (todo.c): TODO\r\n");
#endif

	Struct_20611068* sp_0x2c;
	Struct_20401328 sp_0x20;
	Uart_Init_Params sp4;

	sp_0x20.dwOutFunction = 0xff; //r6
	sp_0x20.dwInFunction = 0x40; //r7
	sp_0x20.bPin = 0x14; //r5

	int r4 = gpio_open(&sp_0x20, &sp_0x2c);
	if (r4 == 0)
	{
		if (0 != sub_2341abfc(sp_0x2c))
		{
			gpio_close(sp_0x2c);
			//loc_2340154c
		}
		else
		{
			//loc_2340157c
			gpio_close(sp_0x2c);
			//loc_23401584
			return;
		}
	}
	//loc_2340154c
	sp_0x20.dwOutFunction = 0xff; //r6
	sp_0x20.dwInFunction = 0x40; //r7
	sp_0x20.bPin = 0x15; //r8

	r4 |= gpio_open(&sp_0x20, &sp_0x2c);
	if (r4 == 0)
	{
		if (0 != sub_2341abfc(sp_0x2c))
		{
			//loc_2340158c
			gpio_close(sp_0x2c);

			sp4.bData_0 = 1;
			sp4.rxPin.bPin = 0x14; //r5
			sp4.rxPin.dwOutFunction = 0xff; //r6
			sp4.rxPin.dwInFunction = 0x40; //r7
			sp4.txPin.dwOutFunction = 0x2c;
			sp4.txPin.bPin = 0x15; //r8
			sp4.txPin.dwInFunction = 0xff; //r6

			uart_init(&sp4, &Data_23491d94);
			//->loc_23401584
		}
		else
		{
			//loc_2340157c
			gpio_close(sp_0x2c);
			//loc_23401584
		}
	}
	//loc_23401584
	return;
}


/* 234015ec / 23402000 - complete */
void main_frontpanel_init()
{
	Struct_23410ea4 avParams;
	Struct_23437974 vfdParams;
	uint8_t sp4[] = {0x03, 0x04, 0x02,  0x07,  0x08, 0x05, 0x00, 0x00}; //234017DC

	fpc_init(sp4);

	avParams.threadPrio = THREAD_PRIO_AV;
	avParams.Data_4 = 14;
	avParams.Data_8 = 13;

	av_init(&avParams);

	vfdParams.Data_0 = 80;
	vfdParams.Data_4 = 3;
	vfdParams.Data_8 = 4;

	vfd_init(&vfdParams);

	frontdisplay_init();
}


/* 23401654 / 234013ac - todo */
void main_video_hdmi_init()
{
	sub_23427ef4();

	Struct_234248a0 sp_0x28;
	Struct_23427f24 sp_0x18;
	HDMI_VideoParams sp4;

	sp_0x18.Data_12 = 5;
	sp_0x18.Data_0 = 2;
	sp_0x18.Data_4 = 1;
	sp_0x18.Data_8 = 4; //r8

	int r0 = sub_23427f24(&sp_0x18, &Data_23491da4);
	if (r0 == 0)
	{
		sub_23427fe8(Data_23491da4);
	}

	sp_0x18.Data_8 = 0;
	sp_0x18.Data_0 = 3; //r7
	sp_0x18.Data_4 = 4; // r8
	sp_0x18.Data_12 = 4; //r8

	r0 = sub_23427f24(&sp_0x18, &Data_23491da8);
	if (r0 == 0)
	{
		sub_23427fe8(Data_23491da8);
	}

	sub_23434718(0);

	sub_234345a4(4);

	r0 = sub_2342d668(0, 0, 0, 0xff);

	sub_234344d0((r0 >> 16) & 0xff, (r0 >> 24) & 0xff, (r0 >> 8) & 0xff);

	hdmi_init();

	sp_0x28.Data_0 = 3; //r7;

	hdmi_open(&sp_0x28, &main_hHdmi);

	sp4.activeFormat = 8;
	sp4.inputType = 2; //r5;
	sp4.videoCode = 20;
	sp4.scanInfo = 1; //r6;
	sp4.outputType = 2; //r5

	hdmi_SetVideoParameters(main_hHdmi, &sp4);
}


/* 23401748 - todo */
void main_set_power_mode()
{
	uint8_t sp_0x10;
	LastMode sp;

#if 0
	console_send_string("main_set_power_mode (main.c)\r\n");
#endif

	rtos_task_wait(10);

	if (0 == sub_23418e1c(&sp_0x10))
	{
		uint32_t r0 = sub_23418e98();

		if ((r0 >= 3) && ((sp_0x10 & 0x40) == 0))
		{
			lastmode_read(main_hLastmode, &sp, 0, sizeof(sp));

			if (((sp.bData_14 & 0x0f) == 0x01) ||
					((~sp.bData_14 & 0x0f) == 0))
			{
				//loc_234017b8
				powermode_set_state(1, 0, 0);
			}
			else
			{
				powermode_set_state(2, 0, 0);
			}
		}
		else
		{
			//loc_234017b8
			powermode_set_state(1, 0, 0);
		}
	}
	//loc_234017c8
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


/* 234018c8 - todo */
void sub_234018c8(void)
{
#if 0
	console_send_string("sub_234018c8 (main.c)\r\n");
#endif

	ota_init(THREAD_PRIO_OTA);
}


#if 1 //Only v290

/*  / 23402948 - todo */
void sub_23402948(void)
{

#if 0
	/*sub_2345bc50*/sub_23425e88(/*Struct_2345bc50* pParams*/);
#endif
}

#endif

