

#include "data.h"
#include "ucos_ii.h"
#include "ota.h"


extern void sub_23454df4();


void* ota_mbox; //234920cc

uint32_t ota_thread_stack[600]; //2358c124

Struct_2358ca84 Data_2358ca84; //2358ca84 -> 235957B8???


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

	Data_2358ca84.bData_0x8d32 = 0;

	ota_mbox = OSMboxCreate(0);

	while (1)
	{
		//loc_23414048
		Struct_23414198* r7 = OSMboxPend(ota_mbox, Data_2358ca84.bData_0x8d32, &err);

		ota_lock();

		if (err != OS_ERR_TIMEOUT)
		{
			//0x2341406c
#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "ota_thread: r7->bData_0xe=%d\r\n",
					r7->bData_0xe);
				console_send_string(debug_string);
			}
#endif

			if (Data_2358ca84.Data_0x1c != 0)
			{
				//0x23414078
				(Data_2358ca84.Data_0x1c)(r7);
			}
			//loc_234140a4
		} //if (err != OS_ERR_TIMEOUT)
		else
		{
			//loc_23414080: Timeout
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
		Data_2358ca84.bData_0x8d33 = prio;

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

		Data_2358ca84.Data_0x89c8 = a->bData_0;
	}
	else
	{
		Data_2358ca84.Data_0x1c = sub_23413f10;
	}

	sub_23439324(Data_2358ca84.bData_0x8d33);

	return 0;
}


/* 23414198 - todo */
int sub_23414198(uint8_t r7, int bCreateMbox, int r8, uint16_t sb, Struct_23414198* r4)
{
#if 0
	console_send_string("sub_23414198 (todo.c): TODO\r\n");
#endif

	uint8_t err; 
	int res = 0;

	if (ota_mbox == 0)
	{
		return 1;
	}

	if (bCreateMbox != 0)
	{
		r4->mbox = OSMboxCreate(0);
	}
	else
	{
		r4->mbox = 0;
	}

	r4->bData_0xe = r7;
	r4->Data_4 = r8;
	r4->wData_0xc = sb;

	err = OSMboxPost(ota_mbox, r4);

	if (err != 0)
	{
		res = 3;
	}

	if (r4->mbox != 0)
	{
		OSMboxPend(r4->mbox, 100, &err);

		if ((err == OS_ERR_TIMEOUT) && (res == 0))
		{
			res = 2;
		}

		r4->mbox = OSMboxDel(r4->mbox, 1, &err);
	}
	//loc_2341423c
	return res;
}


/* 23414244 - todo */
Struct_2358ca84* sub_23414244(void)
{
#if 0
	console_send_string("sub_23414244 (todo.c): TODO\r\n");
#endif

	return &Data_2358ca84;
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


