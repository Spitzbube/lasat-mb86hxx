
#include "data.h"
#include "timer.h"
#include "ucos_ii.h"
#include <mu_arch.h>
#include <mu_cdi.h>
#include <class/mu_msd.h>

#pragma thumb

extern int Data_234927c4; //234927c4
extern int Data_234927c8; //234927c8
extern int Data_234927cc; //234927cc


static uint8_t MUSB_BoardMessageString(char*, uint16_t, const char*);
static uint8_t MUSB_BoardMessageNumber(char*, uint16_t, uint32_t, uint8_t, uint8_t);
static uint32_t MUSB_BoardGetTime(void);

//23492c38
uint8_t usb_bGpioState = 0; //23492c38 +0
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

#if 0
extern uint32_t Data_23494334; //23494334

MUSB_DeviceDriver Data_23494318 = //23494318
{
	NULL,
	1,
	&Data_23494334,
	sub_234679e0,
	sub_23467ae0,
	NULL,
	NULL
};

uint32_t Data_23494334 = 10; //23494334
#else
extern MUSB_DeviceDriver MGC_MsdDeviceDriver; //23494318
#endif

#ifdef USB_HUB
extern MUSB_DeviceDriver MGC_HubClassDriver;
#endif

#ifdef USB_ASIX
extern MUSB_DeviceDriver MGC_AsixDriver;
#endif

typedef struct
{
	uint8_t buffer[640]; //0
	int itemCount; //0x280 = 235fa884
	int itemLength; //0x284 = 235fa888
	uint32_t head; //235fa88c
	uint32_t tail; //235fa890
	//656 = 0x290
} usbQueueT;

typedef struct
{
	void* Data_0; //0
	int Data_4; //4
	MUSB_pfTimerExpired expireFunc; //expireFunc
	//12
} Struct_235fa56c;

typedef struct
{
	void (*Data_0)(); //0
	Struct_235fa56c Timer[2]; //235FA56C
	void* lock[17]; //235FA584
	MUSB_Controller* controllerPtr; //235FA5C8
	MUSB_Port* portPtr; //235FA5CC
	MUSB_SystemServices Services; //235fa5d0 -> 235FA604
	usbQueueT Queue; //235fa604 -> 235FA894
	MUSB_OtgClient MGC_MsdOtgClient; //235fa894
#if 0
	int fill_235fa8a4[11]; //0x33c = 235fa8a4
#endif
	MUSB_HostClient MGC_MsdHostClient; //235fa8d0
	MUSB_BusHandle MGC_hCdiBus; //235FA8E0
	uint8_t MGC_aMsdPeripheralList[100]; //235FA8E4 +0xc
	MUSB_DeviceDriver MGC_aDeviceDriver[8]; //235fa948 +8*0x1c
	uint8_t fill_235faa28; //0x4c0 = 235faa28
	uint8_t bData_235faa29; //0x4c1 = 235faa29
	//0x4c4
} MGC_System;

MGC_System MGC_usbSystem; //235fa568 -> 235FAA2C



/* 234397c8 - complete */
void MUSB_BoardPrintDiag()
{
#if 0
	console_send_string("MUSB_BoardPrintDiag (todo.c): TODO\r\n");
#endif

}


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
#if 0
	console_send_string("usb_isr (todo.c): TODO\r\n");
#endif

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


/* 234398c8 - todo */
void* usbServiceSystemToBusAddress(void* privateDataPtr, const void* sysAddress)
{
#if 1
	console_send_string("usbServiceSystemToBusAddress (todo.c): TODO\r\n");
#endif

	return (void*) sysAddress;
}


/* 234398cc - todo */
int usbServiceQueueBackgroundItem(void* privateDataPtr, void* itemPtr)
{
#if 0
	console_send_string("usbServiceQueueBackgroundItem (todo.c): TODO\r\n");
#endif

#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	uint8_t* queued_item_ptr;
	/*usbQueueT*/uint8_t* r6 = MGC_usbSystem.Queue.buffer;

	OS_ENTER_CRITICAL();

	if (MGC_usbSystem.Queue.itemCount != 0)
	{
		//0x234398e2
		if (((MGC_usbSystem.Queue.head + 1) % MGC_usbSystem.Queue.itemCount) !=
				MGC_usbSystem.Queue.tail)
		{
			//0x234398f0
			queued_item_ptr = r6 + MGC_usbSystem.Queue.head * MGC_usbSystem.Queue.itemLength;

			memcpy(queued_item_ptr, itemPtr, MGC_usbSystem.Queue.itemLength);

			MGC_usbSystem.Queue.head = (MGC_usbSystem.Queue.head + 1) %
					MGC_usbSystem.Queue.itemCount;

			OS_EXIT_CRITICAL();

			return 1;
		}
		//loc_23439912
	}
	//loc_23439912
	OS_EXIT_CRITICAL();

	return 0;
}


/* 2343991c - complete */
uint8_t usbServiceDequeueBackgroundItem(void* a, void* itemPtr)
{
#if 0
	console_send_string("usbServiceDequeueBackgroundItem (todo.c): TODO\r\n");
#endif

#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	uint8_t* queued_item_ptr;
	/*usbQueueT*/uint8_t* r6 = MGC_usbSystem.Queue.buffer;

	OS_ENTER_CRITICAL();

	if ((MGC_usbSystem.Queue.tail != MGC_usbSystem.Queue.head) &&
			(MGC_usbSystem.Queue.itemCount != 0))
	{
		queued_item_ptr = r6 + MGC_usbSystem.Queue.tail * MGC_usbSystem.Queue.itemLength;
		memcpy(itemPtr, queued_item_ptr, MGC_usbSystem.Queue.itemLength);

		MGC_usbSystem.Queue.tail =
				(MGC_usbSystem.Queue.tail + 1) % MGC_usbSystem.Queue.itemCount;

		OS_EXIT_CRITICAL();

		return 1;
	}
	//loc_2343995c
	OS_EXIT_CRITICAL();

	return 0;
}


/* 23439966 - complete */
void usbServiceFlushBackgroundQueue()
{
#if 0
	console_send_string("usbServiceFlushBackgroundQueue (todo.c): TODO\r\n");
#endif

#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	OS_ENTER_CRITICAL();

	MGC_usbSystem.Queue.tail = 0;
	MGC_usbSystem.Queue.head = 0;

	OS_EXIT_CRITICAL();
}


/* 2343997a - complete */
int sub_2343997a(void* a)
{
#if 0
	console_send_string("sub_2343997a (todo.c): TODO\r\n");
#endif

	uint32_t index = (uint32_t) a;
	Struct_235fa56c* r4 = &MGC_usbSystem.Timer[index];

	if ((index < 2) && (r4->Data_0 != 0))
	{
		if (r4->Data_4 == 0)
		{
			timer_user_control(r4->Data_0, 0);
			r4->Data_0 = sub_2341b85c(r4->Data_0);
		}

		if (r4->expireFunc != 0)
		{
			(r4->expireFunc)(MGC_usbSystem.controllerPtr->pPrivateData, index);
		}
	}

	return 0;
}


/* 234399b6 - complete */
uint8_t usbServiceArmTimer(void* privateDataPtr,
                                   uint16_t   index,
                                   uint32_t   time,
                                   uint8_t    periodicFlag,
                                   MUSB_pfTimerExpired expiredCallback)
{
#if 0
	console_send_string("usbServiceArmTimer (todo.c): TODO\r\n");
#endif

	Timer_Params sp;

	if (MGC_usbSystem.Timer[index].Data_0 != 0)
	{
		timer_user_control(MGC_usbSystem.Timer[index].Data_0, 0);
		MGC_usbSystem.Timer[index].Data_0 = sub_2341b85c(MGC_usbSystem.Timer[index].Data_0);
		if (MGC_usbSystem.Timer[index].Data_0 != 0)
		{
			return 1;
		}
	}

	sp.Data_0 = time / 10;
	sp.Data_4 = (void*) index;
	sp.Data_8 = sub_2343997a;

	MGC_usbSystem.Timer[index].expireFunc = expiredCallback;
	MGC_usbSystem.Timer[index].Data_4 = periodicFlag;
	MGC_usbSystem.Timer[index].Data_0 = timer_user_open(&sp);

	if (MGC_usbSystem.Timer[index].Data_0 != 0)
	{
		timer_user_control(MGC_usbSystem.Timer[index].Data_0, 1);
	}

	return 1;
}


/* 23439a0c - complete */
uint8_t usbServiceCancelTimer(void* privateDataPtr, uint16_t index)
{
#if 0
	console_send_string("usbServiceCancelTimer (todo.c): TODO\r\n");
#endif

	Struct_235fa56c* r4 = &MGC_usbSystem.Timer[index];

	if (index < 2)
	{
		if (r4->Data_0 != 0)
		{
			timer_user_control(r4->Data_0, 0);

			r4->Data_0 = sub_2341b85c(r4->Data_0);
		}
	}

	return 1;
}


/* 23439a34 - complete */
uint8_t usbServiceLock(void* a, uint16_t index)
{
#if 0
	console_send_string("usbServiceLock (todo.c): TODO\r\n");
#endif

	uint8_t err;

	OSSemPend(MGC_usbSystem.lock[index], 0, &err);

	return 1;
}


/* 23439a4a - complete */
uint8_t usbServiceUnlock(void* a, uint16_t index)
{
#if 0
	console_send_string("usbServiceUnlock (todo.c): TODO\r\n");
#endif

	uint8_t err;

	OSSemPost(MGC_usbSystem.lock[index]);

	return 1;
}


/* 23439a5c / 23449798 - todo */
void sub_23439a5c()
{
#if 1
	console_send_string("sub_23439a5c (todo.c): TODO\r\n");
#endif

#if 1
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	uint8_t i; // = 0;

	if ((MGC_usbSystem.MGC_hCdiBus != 0) &&
			(0 != MUSB_DeactivateClient(MGC_usbSystem.MGC_hCdiBus)))
	{
		uint8_t val = MGC_Read8((void*) Data_23492c3c[0], 1);
		val &= ~0x40;
		MGC_Write8((void*) Data_23492c3c[0], 1, val);

		MGC_usbSystem.MGC_hCdiBus = 0;

		memset(&MGC_usbSystem.MGC_MsdOtgClient, 0, sizeof(MUSB_OtgClient));
		memset(&MGC_usbSystem.MGC_MsdHostClient, 0, sizeof(MUSB_HostClient));
	}
	//loc_23439aa2
	if (MGC_usbSystem.controllerPtr != NULL)
	{
		MUSB_StopController(MGC_usbSystem.controllerPtr);
		MUSB_DestroyController(MGC_usbSystem.controllerPtr);

		OS_ENTER_CRITICAL();

		Data_234927c4 = 0x7f;
		FREG(0xC70000F0)[0] = Data_234927c4; //DMA_USB_INT_MASK

		Data_234927cc &= ~0x80;
		FREG(0xC7000014)[0] = Data_234927cc; //DMA_USB_MODE

		MGC_usbSystem.controllerPtr = NULL;

		OS_EXIT_CRITICAL();
	}
	//loc_23439ad8
	memset(&MGC_usbSystem.Queue, 0, sizeof(MGC_usbSystem.Queue)/*164*4*/);

	if (MGC_usbSystem.Timer[0].Data_0 != 0)
	{
		timer_user_control(MGC_usbSystem.Timer[0].Data_0, 0);
		MGC_usbSystem.Timer[0].Data_0 = sub_2341b85c(MGC_usbSystem.Timer[0].Data_0);
	}

	for (i = 0; i < 17; i++)
	{
		//loc_23439afa
		if (MGC_usbSystem.lock[i] != 0)
		{
			uint8_t sp;
			MGC_usbSystem.lock[i] = (void*) OSSemDel(MGC_usbSystem.lock[i], 1, &sp);
		}
	}
#endif
}


/* 23439b18 - todo */
void sub_23439b18(void* hClient, MUSB_BusHandle hBus, uint32_t status)
{
#if 0
	console_send_string("sub_23439b18 (todo.c): TODO\r\n");
#endif

	if (hBus != NULL)
	{
		int r0 = status << 24;
	}
}


/* 23439b20 - complete */
void sub_23439b20(void* h, MUSB_BusHandle hBus, MUSB_OtgState state)
{
#if 0
	console_send_string("sub_23439b20 (todo.c): TODO\r\n");
#endif

	if (hBus != NULL)
	{
		if (state == MUSB_AB_IDLE)
		{
			MUSB_RequestBus(hBus);
		}
	}
}


/* 23439b30 / 2344986c - todo */
int usb_msd_init()
{
#if 1
	console_send_string("usb_msd_init (todo.c): TODO\r\n");
#endif

	MGC_usbSystem.MGC_MsdOtgClient.pPrivateData = &MGC_usbSystem;
	MGC_usbSystem.MGC_MsdOtgClient.pbDesireHostRole = &MGC_usbSystem.bData_235faa29;
	MGC_usbSystem.MGC_MsdOtgClient.pfOtgState = sub_23439b20;
	MGC_usbSystem.MGC_MsdOtgClient.pfOtgError = sub_23439b18;

	MGC_usbSystem.MGC_aDeviceDriver[0] = MGC_MsdDeviceDriver; //Data_23494318;
#ifdef USB_HUB
	MGC_usbSystem.MGC_aDeviceDriver[1] = MGC_HubClassDriver;
#endif

#ifdef USB_ASIX
	MGC_usbSystem.MGC_aDeviceDriver[2] = MGC_AsixDriver;
#endif

	MGC_usbSystem.MGC_aMsdPeripheralList[0] = MUSB_TARGET_CLASS; //6; //r2
	MGC_usbSystem.MGC_aMsdPeripheralList[1] = MUSB_CLASS_PER_INTERFACE; //0; //r3
	MGC_usbSystem.MGC_aMsdPeripheralList[2] = MUSB_TARGET_INTERFACE; //5; //r0
	MGC_usbSystem.MGC_aMsdPeripheralList[3] = 0; //r3
	MGC_usbSystem.MGC_aMsdPeripheralList[4] = MUSB_TARGET_CLASS; //6; //r2
	MGC_usbSystem.MGC_aMsdPeripheralList[5] = MUSB_CLASS_MASS_STORAGE; //8; //r6
	MGC_usbSystem.MGC_aMsdPeripheralList[6] = MUSB_TARGET_SUBCLASS; //7; //r5
	MGC_usbSystem.MGC_aMsdPeripheralList[7] = MGC_MSD_SCSI_SUBCLASS; //6; //r2
	MGC_usbSystem.MGC_aMsdPeripheralList[8] = MUSB_TARGET_PROTOCOL; //8; //r6
	MGC_usbSystem.MGC_aMsdPeripheralList[9] = MGC_MSD_BOT_PROTOCOL; //0x50;
	MGC_usbSystem.MGC_aMsdPeripheralList[10] = MUSB_TARGET_ACCEPT; //9;
	MGC_usbSystem.MGC_aMsdPeripheralList[11] = 0; /* placeholder for driver index */ //r3
#ifdef USB_HUB
	MGC_usbSystem.MGC_aMsdPeripheralList[12] = MUSB_TARGET_CLASS; //6;
	MGC_usbSystem.MGC_aMsdPeripheralList[13] = MUSB_CLASS_HUB; //9;
	MGC_usbSystem.MGC_aMsdPeripheralList[14] = MUSB_TARGET_ACCEPT; //9;
	MGC_usbSystem.MGC_aMsdPeripheralList[15] = 1; /* placeholder for driver index */
#endif

#ifdef USB_ASIX
#if 0
	MGC_usbSystem.MGC_aMsdPeripheralList[16] = MUSB_TARGET_CLASS;
	MGC_usbSystem.MGC_aMsdPeripheralList[17] = MUSB_CLASS_PER_INTERFACE;
	MGC_usbSystem.MGC_aMsdPeripheralList[18] = MUSB_TARGET_INTERFACE;
	MGC_usbSystem.MGC_aMsdPeripheralList[19] = 0;
	MGC_usbSystem.MGC_aMsdPeripheralList[20] = MUSB_TARGET_CLASS;
	MGC_usbSystem.MGC_aMsdPeripheralList[21] = 0xff;
	MGC_usbSystem.MGC_aMsdPeripheralList[22] = MUSB_TARGET_SUBCLASS;
	MGC_usbSystem.MGC_aMsdPeripheralList[23] = 0xff;
	MGC_usbSystem.MGC_aMsdPeripheralList[24] = MUSB_TARGET_ACCEPT; //9;
	MGC_usbSystem.MGC_aMsdPeripheralList[25] = 2; /* placeholder for driver index */
#else
	MGC_usbSystem.MGC_aMsdPeripheralList[16] = MUSB_TARGET_VID;
	MGC_usbSystem.MGC_aMsdPeripheralList[17] = (0x0b95) & 0xff;
	MGC_usbSystem.MGC_aMsdPeripheralList[18] = (0x0b95) >> 8;
	MGC_usbSystem.MGC_aMsdPeripheralList[19] = MUSB_TARGET_PID;
	MGC_usbSystem.MGC_aMsdPeripheralList[20] = (0x772a) & 0xff;
	MGC_usbSystem.MGC_aMsdPeripheralList[21] = (0x772a) >> 8;
	MGC_usbSystem.MGC_aMsdPeripheralList[22] = MUSB_TARGET_ACCEPT; //9;
	MGC_usbSystem.MGC_aMsdPeripheralList[23] = 2; /* placeholder for driver index */
#endif
#endif

	MGC_usbSystem.MGC_MsdHostClient.aDeviceDriverList = &MGC_usbSystem.MGC_aDeviceDriver[0]; //r7
	MGC_usbSystem.MGC_MsdHostClient.pPeripheralList = &MGC_usbSystem.MGC_aMsdPeripheralList[0];
#ifdef USB_HUB
#ifdef USB_ASIX
	MGC_usbSystem.MGC_MsdHostClient.wPeripheralListLength = 24;
	MGC_usbSystem.MGC_MsdHostClient.bDeviceDriverListLength = 3;
#else
	MGC_usbSystem.MGC_MsdHostClient.wPeripheralListLength = 16;
	MGC_usbSystem.MGC_MsdHostClient.bDeviceDriverListLength = 2;
#endif
#else
	MGC_usbSystem.MGC_MsdHostClient.wPeripheralListLength = 12;
	MGC_usbSystem.MGC_MsdHostClient.bDeviceDriverListLength = 1;
#endif

	if (0 != MGC_HdrcUlpiVbusControl(MGC_usbSystem.portPtr->pPrivateData, 1, 0))
	{
		//0x23439ba0
		MGC_usbSystem.MGC_hCdiBus = MUSB_RegisterOtgClient(MGC_usbSystem.portPtr,
				/*(MUSB_FunctionClient*)*/NULL,
				/*(MUSB_HostClient*)*/ &MGC_usbSystem.MGC_MsdHostClient,
				/*(MUSB_OtgClient*)*/ &MGC_usbSystem.MGC_MsdOtgClient);
	}
	//loc_23439bb2
	return 0;
}


/* 23439bb6 / 234498f2 - todo */
int MGC_usbInitController()
{
	int sp;
	MUSB_Controller* ctrl_ptr; //r4
	uint8_t r5;

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

		if (ctrl_ptr->wLockCount > 17)
		{
			//->loc_23439ce8
			return 0;
		}
		//->loc_23439c64
		for (r5 = 0; r5 < ctrl_ptr->wLockCount; r5++)
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
}


/* 23439d06 / 23449a3a - todo */
int sub_23439d06(int r5)
{
#if 1
	console_send_string("sub_23439d06 (todo.c): TODO\r\n");
#endif

	int sp4;
	uint8_t err;

	OSSemPend(usb_sema, 0, &err);

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23439d06: r5=%d\r\n", r5);
		console_send_string(debug_string);
	}
#endif

	if (r5 != 0)
	{
		if (0 != MGC_HdrcReadUlpiReg(MGC_usbSystem.portPtr->pPrivateData, 0, &sp4))
		{
			MGC_HdrcWriteUlpiReg(MGC_usbSystem.portPtr->pPrivateData, 0x0a, 0);
			MGC_HdrcWriteUlpiReg(MGC_usbSystem.portPtr->pPrivateData, 0x0b, 0);
			MGC_HdrcWriteUlpiReg(MGC_usbSystem.portPtr->pPrivateData, 0x0c, 0);

			OSSemPend(Data_23492c44, 0, &err);

			sub_23439a5c();

			OSSemPost(Data_23492c44);

			rtos_task_wait(3);
		}
		//->loc_23439d88
	}
	else
	{
		//loc_23439d6e
		if (main_hUsbGpio != 0)
		{
			gpio_set(main_hUsbGpio, usb_bGpioState);
		}

		if (0 != MGC_usbInitController())
		{
			usb_msd_init();
		}
	}
	//loc_23439d88
	OSSemPost(usb_sema);

	return 0;
}


/* 23439e04 / 23449b38 - complete */
void usb_set_gpio(int state)
{
#if 0
	console_send_string("usb_set_gpio (todo.c): TODO\r\n");
#endif

	uint8_t err;

	OSSemPend(usb_sema, 0, &err);

	usb_bGpioState = state;

	OSSemPost(usb_sema);
}


