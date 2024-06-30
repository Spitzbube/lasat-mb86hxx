
#include "data.h"
#include "ucos_ii.h"
#include <mu_cdi.h>


static uint8_t MUSB_BoardMessageString(char*, uint16_t, const char*);
static uint8_t MUSB_BoardMessageNumber(char*, uint16_t, uint32_t, uint8_t, uint8_t);
static uint32_t MUSB_BoardGetTime(void);

//23492c38
uint32_t Data_23492c3c[] = //0x23492c3c +4
{
	0xc7000800
};
OS_EVENT* usb_sema = 0; //23492c40 +8
OS_EVENT* Data_23492c44 = 0; //23492c44 +0xc
MUSB_SystemUtils MGC_usbUtils = //23492c48
{
	MUSB_SYSTEM_UTILS_VERSION,
	MUSB_BoardMessageString,
	MUSB_BoardMessageNumber,
	MUSB_BoardGetTime
};


typedef struct
{
	void (*Data_0)(); //0
#if 0	
	Struct_235fa56c Timer[2]; //235FA56C
	void* lock[17]; //235FA584
#endif
	MUSB_Controller* controllerPtr; //235FA5C8
#if 0
	MUSB_Port* portPtr; //235FA5CC
	MUSB_SystemServices Services; //235fa5d0 -> 235FA604
	usbQueueT Queue; //235fa604 -> 235FA894
	MUSB_OtgClient MGC_MsdOtgClient; //235fa894
	int fill_235fa8a4[11]; //0x33c = 235fa8a4
	MUSB_HostClient MGC_MsdHostClient; //235fa8d0
	MUSB_BusHandle MGC_hCdiBus; //235FA8E0
	uint8_t MGC_aMsdPeripheralList[100]; //235FA8E4 +0xc
	MUSB_DeviceDriver MGC_aDeviceDriver[8]; //235fa948 +8*0x1c
#endif
	uint8_t fill_235faa28; //0x4c0 = 235faa28
	uint8_t bData_235faa29; //0x4c1 = 235faa29
	//0x4c4
} MGC_System;

MGC_System MGC_usbSystem; //235fa568 -> 235FAA2C



/* 234397ca - todo */
static uint8_t MUSB_BoardMessageString(char* pMsg, uint16_t wBufSize, const char* pString)
{
	console_send_string("MUSB_BoardMessageString (todo.c): TODO\r\n");

	strncat(pMsg, pString, wBufSize);

	return 1;
}


/* 234397da - todo */
static uint8_t MUSB_BoardMessageNumber(char* pMsg,
		uint16_t wBufSize, uint32_t dwNumber, uint8_t bBase, uint8_t bJustification)
{
	console_send_string("MUSB_BoardMessageNumber (todo.c): TODO\r\n");

	return 1;
}


/* 23439804 - complete */
static uint32_t MUSB_BoardGetTime(void)
{
#if 0
	console_send_string("MUSB_BoardGetTime (todo.c): TODO\r\n");
#endif

	return 0;
}


/* 23439808 - complete */
int usb_isr()
{
#if 1
	console_send_string("usb_isr (todo.c): TODO\r\n");
#endif

#if 0
	uint32_t r0 = FREG(0xC70000F4)[0] & 1;
	if (r0 != 0)
	{
		int res = (MGC_usbSystem.controllerPtr->pfIsr)(MGC_usbSystem.controllerPtr->pIsrParam);

		Data_234927c8 = (Data_234927c8 & ~0x7f);
		Data_234927c8 |= 1;
		FREG(0xC70000F8)[0] = Data_234927c8;

		return (res > 0)? res: 0;
	}
	//loc_2343983a
	FREG(0xC70000F8)[0] = Data_234927c8 = FREG(0xC70000F4)[0];
#endif

	return 0;
}


/* 23439844 - complete */
void usb_RunBackground()
{
#if 0
	console_send_string("usb_RunBackground (called from idle_thread): TODO\r\n");
#endif

	if (0 != OSSemAccept(Data_23492c44))
	{
#if 0
		if (MGC_usbSystem.controllerPtr != 0)
		{
			if (MGC_usbSystem.Queue.tail != MGC_usbSystem.Queue.head)
			{
				(MGC_usbSystem.controllerPtr->pfBsr)(MGC_usbSystem.controllerPtr->pBsrParam);
			}
			//loc_2343986a
		}
		//loc_2343986a
		if (MGC_usbSystem.Data_0 != 0)
		{
			(MGC_usbSystem.Data_0)();

			MGC_usbSystem.Data_0 = 0;
		}
#endif
		//loc_23439876
		OSSemPost(Data_23492c44);
	}
}


/* 2343987e - todo */
int usb_init()
{
#if 0
	console_send_string("usb_init (todo.c): TODO\r\n");
#endif

	if (usb_sema == 0)
	{
		usb_sema = OSSemCreate(1);
		Data_23492c44 = OSSemCreate(1);

		memset(&MGC_usbSystem, 0, sizeof(MGC_usbSystem));

		if (0 != sub_23467de0(Data_23492c3c[0]))
		{
			intr_set_isr(usb_isr, 0, 21); //FAPI_INTR_USB

			sub_2341b3b8(21, 0);

			FREG(0xe0000254)[0] = 0x0f;
		}
		//loc_234398c4
	}
	//loc_234398c4
	return 0;
}


/* 23439bb6 / 234498f2 - todo */
int MGC_usbInitController()
{
	int sp;
	MUSB_Controller* ctrl_ptr; //r4

#if 1
	console_send_string("MGC_usbInitController (todo.c): TODO\r\n");
#endif

	if (MGC_usbSystem.controllerPtr != 0)
	{
		return -1;
	}
	//loc_23439bc6
	ctrl_ptr = MUSB_NewController(&MGC_usbUtils, MUSB_CONTROLLER_MHDRC,
			(void*) Data_23492c3c[0], (void*) Data_23492c3c[0]);
#if 0
	if (ctrl_ptr == 0)
	{
		//loc_23439c3e -> loc_23439ce8
		return 0;
	}
	else
	{
		//0x23439bda
		MGC_usbSystem.controllerPtr = ctrl_ptr;

		MGC_usbSystem.portPtr = MUSB_GetPort(0);

		if (0 == MGC_HdrcReadUlpiReg(MGC_usbSystem.portPtr->pPrivateData, 0, &sp))
		{
			//0x23439c38
			MUSB_DestroyController(MGC_usbSystem.controllerPtr);
			//loc_23439c3e -> loc_23439ce8
			return 0;
		}
		//loc_23439c40
		if (MGC_usbSystem.portPtr == 0)
		{
			//->loc_23439ce8
			return 0;
		}

		if (ctrl_ptr->wLockCount > 0x11)
		{
			//->loc_23439ce8
			return 0;
		}
		//->loc_23439c64
		for (uint8_t r5 = 0; r5 < ctrl_ptr->wLockCount; r5++)
		{
			//loc_23439c50
			MGC_usbSystem.lock[r5] = OSSemCreate(1);
			if (MGC_usbSystem.lock[r5] == 0)
			{
				//->loc_23439ce8
				return 0;
			}
		}
		//0x23439c6a
		memset(&MGC_usbSystem.Queue, 0, sizeof(MGC_usbSystem.Queue)/*164*4*/);

		//int r1 = ctrl_ptr->wData_8;
		//int r0 = ctrl_ptr->wData_0xa;

		if ((ctrl_ptr->wQueueLength * ctrl_ptr->wQueueItemSize) <= (uint32_t)640/*0x280*/)
		{
			//0x23439c82
			MGC_usbSystem.Queue.itemCount = ctrl_ptr->wQueueLength; //r1;
			MGC_usbSystem.Queue.itemLength = ctrl_ptr->wQueueItemSize; //r0;

			MGC_usbSystem.Services.wVersion = MUSB_SYSTEM_SERVICES_VERSION; //2;
			MGC_usbSystem.Services.pPrivateData = &MGC_usbSystem/*handlePtr???*/;
			MGC_usbSystem.Services.pfSystemToBusAddress = usbServiceSystemToBusAddress;
			MGC_usbSystem.Services.pfQueueBackgroundItem = usbServiceQueueBackgroundItem;
			MGC_usbSystem.Services.pfDequeueBackgroundItem = usbServiceDequeueBackgroundItem;
			MGC_usbSystem.Services.pfFlushBackgroundQueue = usbServiceFlushBackgroundQueue;
			MGC_usbSystem.Services.pfArmTimer = usbServiceArmTimer;
			MGC_usbSystem.Services.pfCancelTimer = usbServiceCancelTimer;
			MGC_usbSystem.Services.pfLock = usbServiceLock;
			MGC_usbSystem.Services.pfUnlock = usbServiceUnlock;
			MGC_usbSystem.Services.pfPrintDiag = MUSB_BoardPrintDiag;
			MGC_usbSystem.Services.pfNewPowerLoad = 0;
			MGC_usbSystem.Services.pfRemovePowerLoad = 0;

			Data_234927c4 = 0x7e;
			FREG(0xC70000F0)[0] = 0x7e; //DMA_USB_INT_MASK

			Data_234927cc = 0;
			FREG(0xC7000014)[0] = 0; //DMA_USB_MODE

			if (0 == MUSB_StartController(ctrl_ptr, /*service_ptr*/&MGC_usbSystem.Services))
			{
				//0x23439ce4
				return 1;
			}
			//loc_23439ce8
		}
		//loc_23439ce8
		return 0;
	}
#endif
}

