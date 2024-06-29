#include "ucos_ii.h"
#include "kernel.h"


/* 23439064 - todo */
INT8U OSTaskCreateExt(void (*func)(void *), void* b,
    OS_STK* stack, INT8U prio/*r3/r4*/,
    INT16U e,
    OS_STK* f,
    INT32U g/*r6*/,
    void* h,
    INT16U i/*r7*/)
{
	char res;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	int stack_frame;

	if (prio > 63)
	{
		//->loc_23448a54: OS_PRIO_INVALID
		res = 42;
	}
	else
	{
		OS_ENTER_CRITICAL();

		if (OSTCBPrioTbl[prio] == 0)
		{
			OSTCBPrioTbl[prio] = (RTOS_tTCB*) 1;
			OS_EXIT_CRITICAL();

			if ((i & 1) || (i & 2))
			{
				memset(f, 0, g * 4);
			}

			stack_frame = OSTaskStkInit(func, b, stack, i);
			res = rtos_create_tcb(prio, stack_frame, f, e, g, h, i);

			if (res == 0)
			{
				OS_ENTER_CRITICAL();
				OSTaskCtr++;
				OS_EXIT_CRITICAL();

				if (OSRunning == 1)
				{
					OS_Sched();
				}
				//->loc_23439138
			}
			else
			{
				//loc_23439128: TCB creation failed
				OS_ENTER_CRITICAL();
				OSTCBPrioTbl[prio] = 0;
				OS_EXIT_CRITICAL();
			}
		}
		else
		{
			//loc_23439140: OS_PRIO_EXIST
			OS_EXIT_CRITICAL();

			res = 40;
		}
	}
	//loc_2343913c
	return res;
}


#if 0
/* 2343914c - todo */
int OSTaskDel(uint8_t prio)
{
	uint32_t cpu_status;
	RTOS_tTCB* ptcb;

	if (OSIntNesting != 0)
	{
		return 63;
	}

	if (prio == 0x3f) //OS_TASK_IDLE_PRIO
	{
		return 61;
	}

	if (prio >= 0x3f)
	{
		if (prio != 0xff) //OS_PRIO_SELF
		{
			return 42; //OS_ERR_PRIO_INVALID
		}
	}
	//loc_23439184
	OS_ENTER_CRITICAL();

	if (prio == 0xff)
	{
		prio = OSTCBCur->prio;
	}

	ptcb = OSTCBPrioTbl[prio];
	if (ptcb == 0)
	{
		//loc_234392b4
		OS_EXIT_CRITICAL();

		return 60;
	}

//	OSRdyTbl[ptcb->OSTCBY] &= ~ptcb->OSTCBBitX;
	if ((OSRdyTbl[ptcb->OSTCBY] &= ~ptcb->OSTCBBitX) == 0)
	{
		OSRdyGrp &= ~ptcb->OSTCBBitY;
	}

	if (ptcb->OSTCBEventPtr != 0)
	{
		OS_EVENT *pevent = ptcb->OSTCBEventPtr;
		uint8_t y =  ptcb->OSTCBY;

//		pevent->OSEventTbl[y]  &= ~ptcb->OSTCBBitX;
		if ((pevent->OSEventTbl[y]  &= ~ptcb->OSTCBBitX) == 0)
		{
			pevent->OSEventGrp &= ~ptcb->OSTCBBitY;
		}
	}
	//loc_23439208
	ptcb->OSTCBDly = 0;
	ptcb->OSTCBStat = 0;

    if (OSLockNesting < 255u)
    {
    	OSLockNesting++;
    }

	OS_EXIT_CRITICAL();

	OS_Dummy();

	OS_ENTER_CRITICAL();

    if (OSLockNesting > 0)
    {
    	OSLockNesting--;
    }

    OSTaskDelHook(ptcb);

    OSTaskCtr--;

    OSTCBPrioTbl[prio] = 0;

    if (ptcb->OSTCBPrev == 0)
    {
    	ptcb->next->OSTCBPrev = 0;
    	OSTCBList = ptcb->next;
    }
    else
    {
    	ptcb->OSTCBPrev->next = ptcb->next;
    	ptcb->next->OSTCBPrev = ptcb->OSTCBPrev;
    }

    ptcb->next = rtos_pTCBFree;
    rtos_pTCBFree = ptcb;

	OS_EXIT_CRITICAL();

	OS_Sched();

	return 0;
}


/* 234392c0 - todo */
uint8_t OSTaskDelReq(uint8_t prio)
{
	uint32_t cpu_status;
	RTOS_tTCB* ptcb;
	uint8_t stat;

	if (prio == 0x3f) //OS_TASK_IDLE_PRIO
	{
		return 61;
	}

	if (prio >= 0x3f)
	{
		if (prio != 0xff) //OS_PRIO_SELF
		{
			return 42; //OS_ERR_PRIO_INVALID
		}

		OS_ENTER_CRITICAL();

		stat = OSTCBCur->l;
		//->loc_23439318
		OS_EXIT_CRITICAL();

		return stat;
	}
	//loc_234392f8
	OS_ENTER_CRITICAL();

	ptcb = OSTCBPrioTbl[prio];
	if (ptcb != 0)
	{
		ptcb->l = 62;
		stat = 0;
	}
	else
	{
		stat = 11;
	}
	//loc_23439318
	OS_EXIT_CRITICAL();

	return stat;
}
#endif

/* 234395d0 - todo */
void rtos_task_wait(uint16_t a)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	if (a != 0)
	{
		OS_ENTER_CRITICAL();

		if ((OSRdyTbl[OSTCBCur->OSTCBY] &= ~OSTCBCur->OSTCBBitX) == 0)
		{
			OSRdyGrp &= ~OSTCBCur->OSTCBBitY;
		}

		OSTCBCur->OSTCBDly = a;

		OS_EXIT_CRITICAL();

		OS_Sched();
	}
}

#if 0
/* 234396d8 - todo */
int OSTimeDlyResume(uint8_t prio)
{
	uint32_t r0;
	RTOS_tTCB* ptcb;

#if 0
	console_send_string("OSTimeDlyResume (todo.c): TODO\r\n");
#endif

	if (prio >= 0x3f)
	{
		return 42; //OS_PRIO_INVALID
	}

	r0 = FAMOS_EnterCriticalSection();

	ptcb = OSTCBPrioTbl[prio];

	if (ptcb == 0)
	{
		//loc_23439770
		FAMOS_LeaveCriticalSection(r0);
		return 11; //OS_TASK_NOT_EXIST
	}
	//0x23439700
	if (ptcb->OSTCBDly == 0)
	{
		//loc_23439764
		FAMOS_LeaveCriticalSection(r0);
		return 80; //OS_TIME_NOT_DLY
	}
	//0x2343970c
	ptcb->OSTCBDly = 0;

	if ((ptcb->OSTCBStat & 0x08/*OS_STAT_SUSPEND*/) == 0)
	{
		OSRdyGrp |= ptcb->OSTCBBitY;
		OSRdyTbl[ptcb->OSTCBY] |= ptcb->OSTCBBitX;

		FAMOS_LeaveCriticalSection(r0);

		OS_Sched();
	}
	else
	{
		//loc_23439758
		FAMOS_LeaveCriticalSection(r0);
	}
	//loc_2343975c
	return 0;
}
#endif
