/******************************************************************
*                                                                *
*        Copyright Mentor Graphics Corporation 2006              *
*                                                                *
*                All Rights Reserved.                            *
*                                                                *
*    THIS WORK CONTAINS TRADE SECRET AND PROPRIETARY INFORMATION *
*  WHICH IS THE PROPERTY OF MENTOR GRAPHICS CORPORATION OR ITS   *
*  LICENSORS AND IS SUBJECT TO LICENSE TERMS.                    *
*                                                                *
******************************************************************/
//#include "include.h"

#pragma thumb

#define MUSB_PRT

#include "mu_cdi.h"
#include "mu_mem.h"
//#include "mu_impl.h"
#include "mu_stdio.h"
#include "mu_strng.h"
#include "mu_hfi.h"
#include "mu_spi.h"
#include "class/mu_msd.h"
//#include "mu_mapi.h"
//#include "mu_none.h"
#include "usb_msd.h"
//#include "rtos_pub.h"
#include "ucos_ii.h"

typedef void (*FUNCPTR)();

void sub_2343a17a (const uint16_t* r0);
uint8_t sub_2343a168(USB_MSD_Device* pDev);

#if 1 //CFG_SUPPORT_MSD
extern MUSB_FunctionClient MGC_xxxFunctionClient;
static void MGC_MsdNewOtgState(void *hClient, MUSB_BusHandle hBus,
                               MUSB_OtgState State);
static void MGC_MsdOtgError(void *hClient, MUSB_BusHandle hBus,
                            uint32_t dwStatus);

/**************************** GLOBALS *****************************/
static MUSB_Port *MGC_pCdiPort = NULL;
static MUSB_BusHandle MGC_hCdiBus = NULL;
static uint8_t MGC_bDesireHostRole = TRUE;
static uint8_t MGC_aMsdPeripheralList[256];
static MUSB_DeviceDriver MGC_aDeviceDriver[2];

#if 0

static MUSB_HostClient MGC_MsdHostClient =
{
    MGC_aMsdPeripheralList,		/* peripheral list */
    0,			    /* filled in main */
    MGC_aDeviceDriver,
    0					/* filled in main */
};

static MUSB_OtgClient MGC_MsdOtgClient =
{
    NULL,	/* no instance data; we are singleton */
    &MGC_bDesireHostRole,
    MGC_MsdNewOtgState,
    MGC_MsdOtgError
};

#endif

#if 0
static MUSB_HfiDevice *MGC_pHfiDevice = NULL;
static const MUSB_HfiMediumInfo *MGC_pHfiMediumInfo = NULL;
static uint8_t MediaIsOk = FALSE;
FUNCPTR trx_callback_ptr = NULL;
#endif


USB_MSD_Device Data_235faa2c[4]; //235faa2c /  / 237943e4

//234c1174
void (*Data_234c1174)() = 0; //234c1174 +0



#if 0

#ifdef CFG_ENABLE_SYC_OP
beken_semaphore_t msd_rd_sema = NULL;
beken_semaphore_t msd_wr_sema = NULL;
#endif

/*************************** FUNCTIONS ****************************/
/* OTG client */
static void MGC_MsdNewOtgState(void *hClient, MUSB_BusHandle hBus,
                               MUSB_OtgState State)
{
    char aAnswer[4];

    switch(State)
    {
    case MUSB_AB_IDLE:
        MUSB_PrintLine("S - Start Session");
        MUSB_GetLine(aAnswer, 4);
        if(('s' == aAnswer[0]) || ('S' == aAnswer[0]))
        {
            MUSB_RequestBus(MGC_hCdiBus);
        }
        break;

    case MUSB_A_SUSPEND:
        MUSB_PrintLine("R - Resume bus");
        MUSB_GetLine(aAnswer, 4);
        if(('r' == aAnswer[0]) || ('R' == aAnswer[0]))
        {
            MUSB_ResumeBus(MGC_hCdiBus);
        }
        break;

    default:
        break;
    }
}

static void MGC_MsdOtgError(void *hClient, MUSB_BusHandle hBus,
                            uint32_t dwStatus)
{
    switch(dwStatus)
    {
    case MUSB_STATUS_UNSUPPORTED_DEVICE:
        MUSB_PRT("Device not supported\r\n");
        break;

    case MUSB_STATUS_UNSUPPORTED_HUB:
        MUSB_PRT("Hubs not supported\r\n");
        break;

    case MUSB_STATUS_OTG_VBUS_INVALID:
        MUSB_PRT("Vbus error\r\n");
        break;

    case MUSB_STATUS_OTG_NO_RESPONSE:
        MUSB_PRT("Device not responding\r\n");
        break;

    case MUSB_STATUS_OTG_SRP_FAILED:
        MUSB_PRT("Device not responding (SRP failed)\r\n");
        break;

    default:
        break;
    }
}

#endif


/* 23439e84 /  / 2344ad1c - complete */
static void transfer_complete(MUSB_HfiVolumeHandle hVolume, uint16_t wActualBlocks)
{
    uint8_t i = 0;
	USB_MSD_Device* pDev = 0;

	for (i = 0; i < 4; i++)
	{
		if (Data_235faa2c[i].hVolume == hVolume)
		{
			pDev = &Data_235faa2c[i];
			break;
		}
	}

	if (pDev != 0)
	{
		pDev->wData_0x14 = wActualBlocks;

		OSSemPost(pDev->responseSema);
	}
}


/* 23439eb4 /  / 2344ad4c - complete */
MUSB_HfiStatus MUSB_HfiAddDevice(MUSB_HfiVolumeHandle *phVolume/*r6*/,
                                 const MUSB_HfiDeviceInfo *pInfo/*r5*/,
                                 MUSB_HfiDevice *pDevice/*r7*/)
{
	uint32_t i;

#if 0
    MGC_pHfiDevice = pDevice;
    MediaIsOk = TRUE;
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "MUSB_HfiAddDevice\r\n");
		console_send_string(debug_string);
	}
#endif

	sub_2343a17a(pInfo->awDiskVendor);
	sub_2343a17a(pInfo->awSerialNumber);
	sub_2343a17a(pInfo->awDiskProduct);

	for (i = 0; i < 4; i++)
	{
		//loc_23439ed8
		if (Data_235faa2c[i].hVolume == 0)
		{
			Data_235faa2c[i].hVolume = *phVolume;
			Data_235faa2c[i].pHfiDevice = pDevice;
			Data_235faa2c[i].Data_4 = pInfo;
			Data_235faa2c[i].requestSema = OSSemCreate(1);
			Data_235faa2c[i].responseSema = OSSemCreate(0);
			//->loc_23439f08
			break;
		}
		//loc_23439f02
	}
	//loc_23439f08
	if (Data_234c1174 != 0)
	{
		(Data_234c1174)(1, i);
	}

    return MUSB_HFI_SUCCESS;

}


/* 23439f66 - complete */
void MUSB_HfiMediumInserted(MUSB_HfiVolumeHandle 	 hVolume,
                            const MUSB_HfiMediumInfo *pMediumInfo)
{
#if 0
    MGC_pHfiMediumInfo = pMediumInfo;
#endif

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "MUSB_HfiMediumInserted\r\n");
		console_send_string(debug_string);
	}
#endif
}

/* 23439f68 - complete */
void MUSB_HfiMediumRemoved(MUSB_HfiVolumeHandle hVolume)
{
#if 0
    MGC_pHfiMediumInfo = NULL;
#endif

}


/* 23439f1a - complete */
void MUSB_HfiDeviceRemoved(MUSB_HfiVolumeHandle hVolume)
{
	uint8_t err;

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "MUSB_HfiDeviceRemoved\r\n");
		console_send_string(debug_string);
	}
#endif

	for (uint32_t i = 0; i < 4; i++)
	{
		//loc_23439f20
		if (Data_235faa2c[i].hVolume == hVolume)
		{
			Data_235faa2c[i].hVolume = 0;
			Data_235faa2c[i].pHfiDevice = 0;
			Data_235faa2c[i].requestSema = (void*) OSSemDel(Data_235faa2c[i].requestSema, 1, &err);
			Data_235faa2c[i].responseSema = (void*) OSSemDel(Data_235faa2c[i].responseSema, 1, &err);

			if (Data_234c1174 != 0)
			{
				(Data_234c1174)(1, i);
			}

			break;
		}
		//loc_23439f5e
	}
}


/* 23439f6a /  / 2344ae02 - complete */
int MUSB_HfiRead(void* h, uint32_t dwStartBlockLo, void* pBuffer, uint16_t wBlockCount)
{
    uint8_t err;
    USB_MSD_Device* pDev = h;

#if 0
	console_send_string("MUSB_HfiRead (todo.c): TODO\r\n");
#endif

    if (wBlockCount == 0)
    {
        return 0;
    }

    err = sub_2343a168(pDev);

    pDev->wData_0x14 = 0;

    int res = pDev->pHfiDevice->pfReadDevice(pDev->pHfiDevice->pPrivateData,
        dwStartBlockLo, 0/*dwStartBlockHi*/, 
        wBlockCount, pBuffer, 
        transfer_complete, 1/*bAllowDma*/);

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "MUSB_HfiRead: %d\r\n", res);
        console_send_string(debug_string);
    }
#endif

    if (res == 0)
    {
        OSSemPend(pDev->responseSema, 1000, &err);

        OSSemPost(pDev->requestSema);

        return 0;
    }
    else
    {
#if 1
        {
            extern char debug_string[];
            sprintf(debug_string, "MUSB_HfiRead: res=%d\r\n", res);
            console_send_string(debug_string);
        }
#endif

        OSSemPost(pDev->requestSema);

        return 0xff;
    }
}


/* 23439fc4 /  / 2344ae5c - complete */
int MUSB_HfiWrite(void* h, uint32_t dwStartBlockLo, void* pBuffer, uint16_t wBlockCount)
{
    int res;
    uint8_t err;
    USB_MSD_Device* pDev = h;

#if 0
	console_send_string("MUSB_HfiWrite (todo.c): TODO\r\n");
#endif

    if (wBlockCount == 0)
    {
        return 0;
    }

    err = sub_2343a168(pDev);
    if (err != 0)
    {
        return 0xff;
    }

    pDev->wData_0x14 = 0;

    res = pDev->pHfiDevice->pfWriteDevice(pDev->pHfiDevice->pPrivateData,
        dwStartBlockLo, 0, 
        wBlockCount, pBuffer, 
        0, transfer_complete, 1);

    if (res == 0)
    {
        OSSemPend(pDev->responseSema, 1000, &err);

        if (err == OS_ERR_TIMEOUT)
        {
            OSSemPost(pDev->requestSema);

            return 0xff;
        }        
    }
    else
    {
        OSSemPost(pDev->requestSema);

        return 0xff;
    }

    OSSemPost(pDev->requestSema);

    return 0;
}


/* 2343a02e - todo */
void sub_2343a02e()
{
#if 1
	console_send_string("sub_2343a02e (todo.c): TODO\r\n");
#endif


}


/* 2343a11c - complete */
uint32_t MUSB_HfiGetMediumBlockCount(void* h)
{
    USB_MSD_Device* pDev = h;
    uint32_t size;

#if 0
	console_send_string("MUSB_HfiGetMediumBlockCount (todo.c): TODO\r\n");
#endif

    if (pDev != 0)
    {
        (void) sub_2343a168(pDev);

        size = pDev->Data_4->InitialMedium.dwBlockCountLo;

        OSSemPost(pDev->requestSema);

        return size;
    }

    return 0;
}


/* 2343a136 - complete */
uint32_t MUSB_HfiGetMediumBlockSize(void* h)
{
    USB_MSD_Device* pDev = h;
    uint32_t size;

#if 0
	console_send_string("MUSB_HfiGetMediumBlockSize (todo.c): TODO\r\n");
#endif

    if (pDev != 0)
    {
        (void) sub_2343a168(pDev);

        size = pDev->Data_4->InitialMedium.dwBlockSize;

        OSSemPost(pDev->requestSema);

        return size;
    }

    return 0;
}


#if 0

uint8_t MGC_MsdGetMediumstatus(void)
{
    return MediaIsOk;
}

#endif

void MGC_StartupAppEvent(void)
{
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "MGC_StartupAppEvent\r\n");
		console_send_string(debug_string);
	}
#endif

#if 0
    if(trx_callback_ptr)
    {
        (*trx_callback_ptr)();
    }
#endif
}

#if 0

void MGC_RegisterCBTransferComplete(FUNCPTR func)
{
    trx_callback_ptr = func;
}

uint32_t MGC_MsdTransferComplete(MUSB_HfiVolumeHandle hVolume,
                                 uint16_t wActualBlocks)

{
    if(trx_callback_ptr)
    {
        (*trx_callback_ptr)();
    }
    MUSB_PRT("MGC_MsdTransferComplete:0x%x\r\n", trx_callback_ptr);

    return 2;
}

uint32_t get_HfiMedium_size(void)
{
    if(MGC_pHfiMediumInfo)
        return MGC_pHfiMediumInfo->dwBlockCountLo;
    else
        return 0;
}
uint32_t get_HfiMedium_blksize(void)
{
    if(MGC_pHfiMediumInfo)
        return MGC_pHfiMediumInfo->dwBlockSize;
    else
        return 0;
}

uint32_t MUSB_HfiRead( uint32_t first_block, uint32_t block_num, uint8_t *dest)
{
    uint32_t RetValue = 1;

    if(MGC_pHfiDevice && MGC_pHfiDevice->pfReadDevice)
    {
        RetValue = MGC_pHfiDevice->pfReadDevice(MGC_pHfiDevice->pPrivateData,
                                                first_block, 0, block_num, dest,
                                                MGC_MsdTransferComplete, TRUE);
    }

    return RetValue;
}

uint32_t MUSB_HfiWrite( uint32_t first_block, uint32_t block_num, uint8_t *dest)
{
    uint32_t RetValue = 1;

    if(MGC_pHfiDevice)
    {
        MUSB_PRT("pfWriteDevice0\r\n");
        RetValue = MGC_pHfiDevice->pfWriteDevice(MGC_pHfiDevice->pPrivateData,
                   first_block, 0, block_num, dest,
                   0, MGC_MsdTransferComplete, FALSE);
        MUSB_PRT("pfWriteDevice1\r\n");
    }

    return RetValue;
}

#ifdef CFG_ENABLE_SYC_OP
uint32_t MGC_MsdReadSyncInit(void)
{
    OSStatus ret = kNoErr;

    if(NULL == msd_rd_sema)
    {
        ret = rtos_init_semaphore(&msd_rd_sema, 1);
        if (kNoErr != ret)
        {
            MUSB_PRT("MGC_MsdReadSyncInit failed\r\n");
        }
    }

    return ret;
}

uint32_t MGC_MsdWriteSyncInit(void)
{
    OSStatus ret = kNoErr;

    if(NULL == msd_wr_sema)
    {
        ret = rtos_init_semaphore(&msd_wr_sema, 1);
        if (kNoErr != ret)
        {
            MUSB_PRT("MGC_MsdReadSyncInit failed\r\n");
        }
    }

    return ret;
}

OSStatus MGC_MsdReadSyncWaiting(uint32_t timeout)
{
    return rtos_get_semaphore(&msd_rd_sema, timeout);
}

OSStatus MGC_MsdWriteSyncWaiting(uint32_t timeout)
{
    return rtos_get_semaphore(&msd_wr_sema, timeout);
}


uint32_t MGC_MsdReadComplete(MUSB_HfiVolumeHandle hVolume,
                             uint16_t wActualBlocks)

{
    MUSB_PRT("MGC_MsdReadComplete\r\n");
    rtos_set_semaphore(&msd_rd_sema);

    return 0;
}

uint32_t MGC_MsdWriteComplete(MUSB_HfiVolumeHandle hVolume,
                              uint16_t wActualBlocks)

{
    MUSB_PRT("MGC_MsdWriteComplete\r\n");
    rtos_set_semaphore(&msd_wr_sema);

    return 0;
}

uint32_t MUSB_HfiRead_sync( uint32_t first_block, uint32_t block_num, uint8_t *dest)
{
    uint32_t RetValue = 1;

    if(MGC_pHfiDevice && MGC_pHfiDevice->pfReadDevice)
    {
        RetValue = MGC_pHfiDevice->pfReadDevice(MGC_pHfiDevice->pPrivateData,
                                                first_block, 0, block_num, dest,
                                                MGC_MsdReadComplete, TRUE);
        MGC_MsdReadSyncWaiting(BEKEN_WAIT_FOREVER);
    }

    return RetValue;
}

uint32_t MUSB_HfiWrite_sync( uint32_t first_block, uint32_t block_num, uint8_t *dest)
{
    uint32_t RetValue = 1;

    if(MGC_pHfiDevice)
    {
        RetValue = MGC_pHfiDevice->pfWriteDevice(MGC_pHfiDevice->pPrivateData,
                   first_block, 0, block_num, dest,
                   0, MGC_MsdWriteComplete, FALSE);
        MGC_MsdWriteSyncWaiting(BEKEN_WAIT_FOREVER);
    }

    return RetValue;
}
#endif // CFG_ENABLE_SYC_OP

int usb_sw_init(void)
{
    uint8_t *pList;
    uint16_t ret;
    uint8_t bDriver = 0;
    uint16_t wCount = 0;
    uint16_t wSize = 0;
    uint16_t wRemain;
    MUSB_DeviceDriver *pDriver;

#ifdef CFG_ENABLE_SYC_OP
    ret = MGC_MsdReadSyncInit();
    ASSERT(0 == ret);

    ret = MGC_MsdWriteSyncInit();
    ASSERT(0 == ret);
#endif

    wRemain = (uint16_t)sizeof(MGC_aMsdPeripheralList);
    pList = MGC_aMsdPeripheralList;

    wSize = MUSB_FillMsdPeripheralList(bDriver, pList, wRemain);
    if(wSize < wRemain)
    {
        pDriver = MUSB_GetStorageClassDriver();
        if(pDriver)
        {
            MUSB_MemCopy(&(MGC_MsdHostClient.aDeviceDriverList[bDriver]),
                         pDriver,
                         sizeof(MUSB_DeviceDriver));

            pList += wSize;
            wCount += wSize;
            wRemain -= wSize;

            bDriver++;
        }
    }

    MGC_MsdHostClient.wPeripheralListLength = wCount;
    MGC_MsdHostClient.bDeviceDriverListLength = bDriver;

    if(!MUSB_InitSystem(5))
    {
        MUSB_PRT("[MGC] InitSystem failed\r\n");
        return -1;
    }

    /* find first CDI port */
    MGC_pCdiPort = MUSB_GetPort(0);

    /* start session */
    MGC_hCdiBus = MUSB_RegisterOtgClient(MGC_pCdiPort,
                                         &MGC_xxxFunctionClient,
                                         &MGC_MsdHostClient,
                                         &MGC_MsdOtgClient);

    MUSB_NoneRunBackground();

    return 0;
}

int usb_sw_uninit(void)
{
    return 0;
}

#endif


/* 2343a150 /  / 2344afe8 - todo */
USB_MSD_Device* musb_msd_get_device(int a)
{
#if 0
	console_send_string("musb_msd_get_device (todo.c): TODO\r\n");
#endif

	if (Data_235faa2c[a].pHfiDevice == 0)
	{
		return 0;
	}

	return &Data_235faa2c[a];
}


/* 2343a162 /  / 2344affa - complete */
void sub_2343a162(void (*a)())
{
#if 0
	console_send_string("sub_2344affa (todo.c): TODO\r\n");
#endif

	Data_234c1174 = a;
}


/* 2343a168 /  / 2344b000 - complete */
uint8_t sub_2343a168(USB_MSD_Device* pDev)
{
    uint8_t err;

#if 0
	console_send_string("sub_2343a168 (todo.c): TODO\r\n");
#endif

    OSSemPend(pDev->requestSema, 0, &err);

    return err;
}


/* 2343a17a - complete */
void sub_2343a17a (const uint16_t* r0)
{
#if 0
	console_send_string("sub_2343a17a (todo.c): TODO\r\n");
#endif

	uint8_t sp[4] = {0};
    
	while (*r0 != 0)
	{
		sp[0] = *r0++;
#if 0
		console_send_string(&sp);
#endif
	}
}


#endif // CFG_SUPPORT_MSD

// eof
