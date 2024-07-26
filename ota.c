

#include "data.h"
#include "ucos_ii.h"
#include "ota.h"


extern void sub_23454df4();


void* ota_mbox; //234920cc

uint32_t ota_thread_stack[600]; //2358c124

struct
{
	int sema; //0
	int Data_4; //4
	int fill_8; //8
	void (*Data_0xc)(); //12
	int fill_0x10; //0x10 16
	int (*Data_0x14)(); //20 0x14
	int fill_0x18; //24 0x18
	void (*Data_0x1c)(); //28 0x1c
	
} Data_2358ca84; //2358ca84

struct
{
	int fill_0[626]; //0
	int Data_0x9c8; //0x9c8
	int fill_0x9cc[217]; //0x9cc
	uint16_t fill_0xd30; //0xd30
	uint8_t bData_0xd32; //0xd32
	uint8_t bData_0xd33; //0xd33
	//???
} Data_23594a84; //23594a84


/* 23413cd0 - todo */
static void sub_23413cd0()
{
#if 1
	console_send_string("sub_23413cd0 (todo.c): TODO\r\n");
#endif

}


/* 23413f10 - todo */
static void sub_23413f10()
{
#if 1
	console_send_string("sub_23413f10 (todo.c): TODO\r\n");
#endif

}


/* 23414028 - todo */
static void ota_thread()
{
	uint8_t err; 

#if 0
	console_send_string("ota_thread (todo.c): TODO\r\n");
#endif

	Data_23594a84.bData_0xd32 = 0;

	ota_mbox = OSMboxCreate(0);

	while (1)
	{
		//loc_23414048
		void* r7 = OSMboxPend(ota_mbox, Data_23594a84.bData_0xd32, &err);

		ota_lock();

		if (err != OS_ERR_TIMEOUT)
		{
			//0x2341406c
			if (Data_2358ca84.Data_0x1c != 0)
			{
				//0x23414078
				(Data_2358ca84.Data_0x1c)(r7);
			}
			//loc_234140a4
		}
		else
		{
			//loc_23414080
			if (Data_2358ca84.Data_0x14 != 0)
			{
				//0x23414078
				int r0 = (Data_2358ca84.Data_0x14)();
				
				if (r0 != 0)
				{
					if (Data_2358ca84.Data_0xc != 0)
					{
						(Data_2358ca84.Data_0xc)(r0);
					}
				}
			}
		}
		//loc_234140a4
		ota_unlock();
	}
}


/* 234140ac - todo */
int ota_init(uint32_t prio)
{
	uint8_t err;

#if 0
	console_send_string("ota_init (todo.c): TODO\r\n");
#endif

	Data_2358ca84.sema = OSSemCreate(1);

	err = OSTaskCreateExt(ota_thread, 0, 
		&ota_thread_stack[600 - 1],
		prio & 0xff, prio & 0xffff, 
		ota_thread_stack, 600, "OTA-MainTask", 3);

	if (err != 0)
	{
		Data_2358ca84.sema = OSSemDel(Data_2358ca84.sema, 1, &err);
	}
	else
	{
		Data_23594a84.bData_0xd33 = prio;

		sub_23439478(prio & 0xff);
	}
	
	return err;
}


/* 2341413c - todo */
int sub_2341413c(Struct_2341413c* a)
{
#if 0
	console_send_string("sub_2341413c (todo.c): TODO\r\n");
#endif

	if (Data_2358ca84.sema == 0)
	{
		return 0xff;
	}

	Data_2358ca84.Data_4 = a->Data_8;
	Data_2358ca84.Data_0x14 = sub_23413cd0;

	if (a->bData_0 != 0)
	{
		Data_2358ca84.Data_0x1c = sub_23454df4;

		Data_23594a84.Data_0x9c8 = a->bData_0;
	}
	else
	{
		Data_2358ca84.Data_0x1c = sub_23413f10;
	}

	sub_23439324(Data_23594a84.bData_0xd33);

	return 0;
}


/* 2341424c - complete */
int ota_lock(void)
{
	uint8_t err;

#if 0
	console_send_string("ota_lock (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_2358ca84.sema, 0, &err);

	return err;
}


/* 234142d8 - complete */
void ota_unlock(void)
{
#if 0
	console_send_string("ota_unlock (todo.c): TODO\r\n");
#endif

	OSSemPost(Data_2358ca84.sema);
}


