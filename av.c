
#include "data.h"
#include "vfd.h"
#include "frontdisplay.h"
#include "av.h"


OS_EVENT* Data_23492098 = 0; //23492098

int av_thread_stack[THREAD_STACK_SIZE_AV]; //2358b764 ->2358BDA4


struct Struct_2358bda4
{
	int fill_0; //0
#if 0
	Struct_20611068* Data_4; //4
	Struct_20611068* Data_8; //8
	int Data_12; //12
	int Data_16; //16
	int Data_20; //20
	int Data_24; //24
	int Data_28; //28
	int Data_32; //32
	int fill_36; //36 = 0x24
	int Data_0x28; //40 = 0x28
#if 1
	Struct_2358bdd0 Data_2358bdd0; //2358bdd0
#else
	int Data_0x2c; //44 = 0x2c //2358bdd0
	int Data_0x30; //48 = 0x30
#endif
#endif
	Struct_23410ea4 Data_0x34; //52 = 0x34 //2358bdd8
#if 0
	Struct_235441b0 Data_0x40; //64 = 0x40
	Struct_235441b0* Data_0x5c; //92 = 0x5C
	int Data_0x60; //96 = 0x60
	int Data_0x64; //100 = 0x64
	int Data_0x68; //104 = 0x68
	int Data_0x6c; //108 = 0x6c
	int Data_0x70; //112 = 0x70
	int Data_0x74; //116 = 0x74
	void (*Data_0x78)(void*, void*); //120 = 0x78
	void (*Data_0x7c)(); //124 = 0x7c
#endif
	void (*frontDisplayTask)(); //128 = 0x80
#if 0
	void (*Data_0x84)(); //132 = 0x84
#endif

} Data_2358bda4; //2358bda4

//2358bdd0



/* 23410cfc - todo */
void av_thread()
{
	int r0;
	uint8_t sp_0x14;
#if 0
	int sp_0x10 = 0;
	int sp_0xc = 0;
	Struct_20401328 sp;

	if (Data_2358bda4.Data_0x34.Data_4 != 0xff)
	{
		sp.dwOutFunction = 0;
		sp.dwInFunction = 0xff;
		sp.bPin = Data_2358bda4.Data_0x34.Data_4;

		gpio_open(&sp, &Data_2358bda4.Data_4);
	}

	if (Data_2358bda4.Data_0x34.Data_8 != 0xff)
	{
		sp.dwOutFunction = 1;
		sp.dwInFunction = 0xff;
		sp.bPin = Data_2358bda4.Data_0x34.Data_8;

		gpio_open(&sp, &Data_2358bda4.Data_8);
	}
	//loc_23410d5c
	sub_2340c970(1, &Data_2358bda4.Data_0x40);

	Data_2358bda4.Data_12 = 0;
	Data_2358bda4.Data_16 = 0;
	Data_2358bda4.Data_20 = 0;
	Data_2358bda4.Data_24 = 0;
	Data_2358bda4.Data_28 = 0;
	Data_2358bda4.Data_32 = 0;
	Data_2358bda4.Data_0x6c = Data_2358bda4.Data_0x40.bData_0x15;
	Data_2358bda4.Data_0x70 = Data_2358bda4.Data_0x40.bData_0x17;
	Data_2358bda4.Data_0x64 = -1;
	Data_2358bda4.Data_0x60 = 3; /* HDMI: 20 1920x1080i @ 50Hz */
	Data_2358bda4.Data_0x68 = (Data_2358bda4.Data_0x40.Data_4 & 3) / 2;
	Data_2358bda4.Data_0x78 = 0;
	Data_2358bda4.Data_0x84 = 0;

	sp_0x10 = 0;
	sp_0xc = 0;

	r0 = ((sub_23428178(Data_23491da8) - 4) != 0)? 1: 0;
	if (Data_2358bda4.Data_0x68 != r0)
	{
		sub_2341159c();
	}
#endif
	//r5 = dword_23492098
	while (1)
	{
		//loc_23410de4 / loc_23417d84
#if 0
		console_send_string("av_thread (todo.c): TODO\r\n");
#endif

#if 0
		sub_2340c970(1, &Data_2358bda4.Data_0x40);

		if (Data_2358bda4.Data_0x84 != 0)
		{
			(Data_2358bda4.Data_0x84)();
		}

		if (Data_2349209c != 0)
		{
			(Data_2349209c)();
		}
#endif

		OSSemPend(Data_23492098, 0, &sp_0x14);

#if 0
		if (Data_2358bda4.Data_0x78 != 0)
		{
			(Data_2358bda4.Data_0x78)(&sp_0x10, &sp_0xc);
		}

		if (Data_2358bda4.Data_0x7c != 0)
		{
			if (Data_2358bda4.Data_0x74 != 0)
			{
				Data_2358bda4.Data_0x74--;
			}
			else
			{
				(Data_2358bda4.Data_0x7c)();

				Data_2358bda4.Data_0x7c = 0;
			}
			//loc_23410e54
		}
		//loc_23410e54
#endif
		if (Data_2358bda4.frontDisplayTask != 0)
		{
			(Data_2358bda4.frontDisplayTask)();
		}

#if 0
		sub_2342e3bc();
#endif

		OSSemPost(Data_23492098);

		rtos_task_wait(5);
		//->loc_23410de4
	}
}


/* 23410ea4 - todo */
int av_init(Struct_23410ea4* r4)
{
	if (Data_23492098 != 0)
	{
		return 0xff;
	}

	memcpy(&Data_2358bda4.Data_0x34, r4, sizeof(Struct_23410ea4));

#if 0
	Data_2358bda4.Data_0x5c = &Data_2358bda4.Data_0x40;
#endif

	Data_23492098 = OSSemCreate(1);

	OSTaskCreateExt(av_thread, 0, &av_thread_stack[THREAD_STACK_SIZE_AV-1],
			r4->threadPrio & 0xff, r4->threadPrio & 0xffff,
			av_thread_stack, THREAD_STACK_SIZE_AV, "AV ", 3);

	return 0;
}


/* 234110a0 - todo */
void av_switch_powermode(int r7)
{
	uint8_t sp_0xc;
	Struct_23437974 sp;

#if 1
	console_send_string("av_switch_powermode (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_23492098, 0, &sp_0xc);

	if (r7 != 0)
	{
		//0x234110cc
#if 0
		if (Data_2358bda4.Data_0x7c != 0)
		{
			(Data_2358bda4.Data_0x7c)();

			Data_2358bda4.Data_0x7c = 0;
		}
		//loc_234110e0
		Data_2358bda4.Data_0x78 = 0;
#endif
		Data_2358bda4.frontDisplayTask = 0;
#if 0
		Data_2358bda4.Data_0x64 = 0;
		Data_2358bda4.Data_0x84 = 0;

		sub_2340a320(1);

		sub_2343655c(2);

		sub_23437d58();

		gpio_set(Data_2358bda4.Data_4, 1);
		gpio_set(Data_2358bda4.Data_8, 0);
#endif
	}
	else
	{
		//loc_23411128
#if 0
		Data_2358bda4.Data_0x78 = sub_23410be8;
#endif
		Data_2358bda4.frontDisplayTask = frontdisplay_task;
#if 0
		Data_2358bda4.Data_0x84 = sub_23410ce4;
		Data_2358bda4.Data_0x28 = 0;
		memset(&Data_2358bda4.Data_2358bdd0, 0, 8);
#if 0
		Data_2358bda4.Data_0x2c = 0; //2358bdd0
		Data_2358bda4.Data_0x30 = 0;
#endif
#endif

		vfd_init(&sp);

#if 0
		av_display_program_name(Data_2358bda4.Data_12 - 1);
		//->loc_23411114
		gpio_set(Data_2358bda4.Data_4, 0);
#endif
	}

	OSSemPost(Data_23492098);
}


/* 234111a8 - complete */
int sub_234111a8()
{
#if 1
	console_send_string("sub_234111a8 (todo.c): TODO\r\n");
#endif

#if 0
	if (Data_2358bda4.Data_0x5c != 0)
	{
		return Data_2358bda4.Data_0x5c->bData_0x0d;
	}
#endif

	return 0;
}

