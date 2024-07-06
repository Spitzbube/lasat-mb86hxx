

#include <ucos_ii.h>


/* 234636d0 - todo */
void  *OSMboxAccept (OS_EVENT *pevent)
{
    void      *pmsg;
#if OS_CRITICAL_METHOD == 3u                          /* Allocate storage for CPU status register      */
    OS_CPU_SR  cpu_sr = 0u;
#endif

    if (pevent == 0)
    {
        return 0;
    }

    if (pevent->OSEventType != OS_EVENT_TYPE_MBOX)
    {
        return 0;
    }

	OS_ENTER_CRITICAL();

    pmsg               = pevent->OSEventPtr;
    pevent->OSEventPtr = 0;

	OS_EXIT_CRITICAL();

	return (pmsg);
}


/* 2346370c - todo */
OS_EVENT* OSMboxCreate(void* pmsg)
{
	OS_EVENT* pEvent;
#if OS_CRITICAL_METHOD == 3u                          /* Allocate storage for CPU status register      */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	if (OSIntNesting != 0)
	{
		return 0;
	}

	OS_ENTER_CRITICAL();

	pEvent = OSEventFreeList;
	if (pEvent != 0)
	{
		OSEventFreeList = pEvent->OSEventPtr;
	}

	OS_EXIT_CRITICAL();

	if (pEvent != 0)
	{
		pEvent->OSEventType = OS_EVENT_TYPE_MBOX;
		pEvent->OSEventCnt = 0;
		pEvent->OSEventPtr = pmsg;

		OS_EventWaitListInit(pEvent);
	}
	//loc_23463768
	return pEvent;
}


/* 23463874 - todo */
void* OSMboxPend(OS_EVENT* pevent, int timeout, uint8_t* perr)
{
	void* pmsg;
#if OS_CRITICAL_METHOD == 3u                          /* Allocate storage for CPU status register      */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	if (OSIntNesting != 0)
	{
		*perr = OS_ERR_PEND_ISR;
		return 0;
	}

	if (pevent == 0)
	{
		*perr = OS_ERR_PEVENT_NULL;
		return 0;
	}

	if (pevent->OSEventType != OS_EVENT_TYPE_MBOX)
	{
		*perr = OS_ERR_EVENT_TYPE;
		return 0;
	}

	OS_ENTER_CRITICAL();

	pmsg = pevent->OSEventPtr;
	if (pmsg != 0)
	{
		pevent->OSEventPtr = 0;
		//->loc_23463920
		OS_EXIT_CRITICAL();

		*perr = 0;
		return pmsg;
	}

	OSTCBCur->OSTCBStat     |= OS_STAT_MBOX;          /* Message not available, task will pend         */
//	    OSTCBCur->OSTCBStatPend  = OS_STAT_PEND_OK;
	OSTCBCur->OSTCBDly       = timeout;                /* Load timeout in TCB                           */

	OS_EventTaskWait(pevent);                          /* Suspend task until event or timeout occurs    */

	OS_EXIT_CRITICAL();

	OS_Sched();                                        /* Find next highest priority task ready to run  */

	OS_ENTER_CRITICAL();

	pmsg = OSTCBCur->OSTCBMsg;

	if (pmsg != 0)
	{
		OSTCBCur->OSTCBMsg = 0;
		OSTCBCur->OSTCBStat = 0;
		OSTCBCur->OSTCBEventPtr = 0;

		OS_EXIT_CRITICAL();

		*perr = 0;
		return pmsg;
	}
	else
	{
		//loc_23463934
		OS_EventTaskRemove(pevent);
		OS_EXIT_CRITICAL();

		*perr = OS_ERR_TIMEOUT;
		return 0;
	}

	return 0;
}


/* 23463954 - todo */
int OSMboxPost(OS_EVENT *pevent, void *pmsg)
{
#if OS_CRITICAL_METHOD == 3u                          /* Allocate storage for CPU status register      */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	if (pevent == 0)
	{
		return OS_ERR_PEVENT_NULL;
	}

	if (pmsg == 0)
	{
		return OS_ERR_POST_NULL_PTR;
	}

	if (pevent->OSEventType != OS_EVENT_TYPE_MBOX)
	{
		return OS_ERR_EVENT_TYPE;
	}

	OS_ENTER_CRITICAL();

	if (pevent->OSEventGrp != 0)
	{
		OS_EventTaskRdy(pevent, pmsg, 2);

		OS_EXIT_CRITICAL();

		OS_Sched();
		//->loc_234639e0
	}
	else
	{
		//loc_234639b8
		if (pevent->OSEventPtr != 0)
		{
			OS_EXIT_CRITICAL();

			return OS_ERR_MBOX_FULL;
		}
		//loc_234639d4
		pevent->OSEventPtr = pmsg;

		OS_EXIT_CRITICAL();
	}
	//loc_234639e0
	return 0;
}

