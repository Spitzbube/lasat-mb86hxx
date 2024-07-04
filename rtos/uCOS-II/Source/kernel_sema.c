
#include <ucos_ii.h>

#if 1

/* 2346425c - todo */
OS_EVENT* OSSemDel(OS_EVENT* pevent, int opt, int* res)
{
#if OS_CRITICAL_METHOD == 3u                               /* Allocate storage for CPU status register */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	int r6;

	if (OSIntNesting != 0)
	{
		*res = 0x8c; //OS_ERR_DEL_ISR
		//->loc_234642fc
		return pevent;
	}

	if (pevent == 0)
	{
		*res = 4;
		//->loc_234642fc
		return pevent;
	}

	if (pevent->OSEventType != 3)
	{
		*res = 1;
		//->loc_234642fc
		return pevent;
	}

	OS_ENTER_CRITICAL();

	if (pevent->OSEventGrp != 0)
	{
		r6 = 1;
	}
	else
	{
		r6 = 0;
	}

	switch (opt)
	{
	case 0:
		//loc_234642cc
		if (r6 == 0)
		{
			pevent->OSEventType = 0;
			pevent->OSEventPtr = OSEventFreeList;
			OSEventFreeList = pevent;

			OS_EXIT_CRITICAL();
			//->loc_23464344
			*res = 0;
			return 0;
		}
		else
		{
			//loc_234642f0
			OS_EXIT_CRITICAL();

			*res = 8;
			return pevent;
		}
		break;

	case 1:
		//loc_23464318
		while (pevent->OSEventGrp != 0)
		{
			//->loc_23464308
			OS_EventTaskRdy(pevent, 0, 1);
		}
		//0x23464324
		pevent->OSEventType = 0;
		pevent->OSEventPtr = OSEventFreeList;
		OSEventFreeList = pevent;

		OS_EXIT_CRITICAL();

		if (r6 == 1)
		{
			OS_Sched();
		}
		//->loc_23464344
		*res = 0;
		return 0;
		break;

	default:
		//loc_23464350
		OS_EXIT_CRITICAL();
		*res = 7; //OS_ERR_INVALID_OPT
		//->loc_234642fc
		return pevent;
		break;
	}
}


#if 0
/* 23477570 - todo */
void sub_23477570_()
{

}
#endif


int OSSemQuery(OS_EVENT* pevent, OS_SEM_DATA* pData)
{
	int i;
#if OS_CRITICAL_METHOD == 3u                               /* Allocate storage for CPU status register */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	if (pevent == 0)
	{
		return 4;
	}

	if (pevent->OSEventType != 3)
	{
		return 1;
	}

	OS_ENTER_CRITICAL();

	pData->bData_10 = pevent->OSEventGrp;

	for (i = 0; i < 8; i++)
	{
		pData->arData_2[i] = pevent->OSEventTbl[i];
	}

	pData->wData_0 = pevent->OSEventCnt;

	OS_EXIT_CRITICAL();

	return 0;
}

#endif
