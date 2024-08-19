
#include "mu_dsi.h"
#include "mu_dci.h"
#include "plat_arc.h"

#pragma thumb

extern void* main_hMemBlk2; //23491dc0 +0x34

static MUSB_DmaController* mu_dma_new_controller(MUSB_pfDmaChannelStatusChanged pfDmaChannelStatusChanged,
	    void* pDmaPrivate,
	    MUSB_pfSystemToBusAddress pfSystemToBusAddress,
	    void* pSystemPrivate,
	    uint8_t* pCoreBaseIsr,
	    uint8_t* pCoreBaseBsr);
static void mu_dma_delete_controller(MUSB_DmaController*);

extern int dma_dwUsbMode; //234927cc

MUSB_DmaControllerFactory mu_dma_controller_factory = //23494338
{
	    0x200,
	    mu_dma_new_controller,
	    mu_dma_delete_controller
};


typedef struct MU_DMA_Channel
{
	void* Data_0; //0
	int Data_4; //4
	int dwLength; //8
	int Data_0xc; //0xc
	int Data_0x10; //0x10
	int Data_0x14; //20
	uint16_t wData_0x18; //0x18
	uint8_t bData_0x1a; //0x1a
	uint8_t bEndpoint; //0x1b
	uint8_t bWrite; //0x1c
	uint8_t bData_0x1d; //0x1d
	MUSB_DmaChannel channel; //0x20
	int status; //0x34
	struct MU_DMA_Controller* pDmaController; //0x38
	//0x3c
} MU_DMA_Channel;

typedef struct MU_DMA_Controller
{
	uint8_t bData_0; //0
	void* Data_4; //4
	MUSB_DmaController controller; //8
	MUSB_pfDmaChannelStatusChanged pfChannelStatusChanged; //0x30
	MUSB_pfSystemToBusAddress Data_0x34; //0x34
	void* Data_0x38; //0x38
	uint8_t* Data_0x3c; //0x3c
	uint8_t* Data_0x40; //0x40
	MU_DMA_Channel channel; //0x44 +0x3c
	//0x80
} MU_DMA_Controller;


MU_DMA_Controller mu_dma_controller[2]; //238ce0fc -> 238CE1FC


/* 23467c40 - todo */
uint8_t mu_dma_start_controller(void* pPrivateData)
{
#if 0
	console_send_string("mu_dma_start_controller (todo.c): TODO\r\n");
#endif

	return 1;
}


/* 23467c44 - todo */
uint8_t mu_dma_stop_controller(void* pPrivateData)
{
#if 0
	console_send_string("mu_dma_stop_controller (todo.c): TODO\r\n");
#endif

	return 1;
}


/* 23467c48 - todo */
uint8_t* mu_dma_allocate_buffer(MUSB_DmaChannel* pChannel, uint32_t dwLength)
{
#if 0
	console_send_string("mu_dma_allocate_buffer (todo.c): TODO\r\n");
#endif

	return memblk_alloc(main_hMemBlk2, dwLength);
}


/* 23467c54 - todo */
uint8_t mu_dma_release_buffer(MUSB_DmaChannel* pChannel, uint8_t* pBuffer)
{
#if 0
	console_send_string("mu_dma_release_buffer (todo.c): TODO\r\n");
#endif

	memblk_free(main_hMemBlk2, pBuffer);

	return 1;
}


/* 23467c62 - complete */
static void mu_dma_transfer_complete(int status, struct MU_DMA_Channel* pDmaChannel)
{
#if 0
	console_send_string("mu_dma_transfer_complete (todo.c): TODO\r\n");
#endif

	MU_DMA_Controller* pDmaController = pDmaChannel->pDmaController;

	uint8_t r6 = MGC_FAPI_ReadReg8(pDmaChannel->Data_0, 0x0e);

	MGC_FAPI_WriteReg8(pDmaChannel->Data_0, 0x0e, pDmaChannel->bEndpoint);

	if (pDmaChannel->bWrite != 0)
	{
		while (1)
		{
			uint32_t r0 = MGC_FAPI_ReadReg16(pDmaChannel->Data_0, 0x12);
			if ((r0 & 2) == 0)
			{
				break;
			}
		}
	}

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "mu_dma_transfer_complete: pDmaChannel->dwLength=%d\r\n", 
            pDmaChannel->dwLength);
        console_send_string(debug_string);
    }
#endif

	pDmaChannel->channel.dwActualLength += pDmaChannel->dwLength;
	pDmaChannel->status = 1;

	(pDmaController->pfChannelStatusChanged)(pDmaController->Data_4, 
		pDmaChannel->bEndpoint, pDmaChannel->bWrite);

	MGC_FAPI_WriteReg8(pDmaChannel->Data_0, 0x0e, r6);
}


/* 23467cb0 - todo */
uint8_t mu_dma_program_channel(MUSB_DmaChannel* pChannel,
	    uint16_t wPacketSize, uint8_t bMode,
	    const uint8_t* pBuffer, uint32_t dwLength)
{
#if 0
	console_send_string("mu_dma_program_channel (todo.c): TODO\r\n");
#endif

	struct MU_DMA_Channel* pDmaChannel = pChannel->pPrivateData;

	pChannel->bDesiredMode = (pDmaChannel->bWrite != 0);
	pDmaChannel->dwLength = dwLength;

	uint32_t mode = dma_dwUsbMode;
	uint32_t ep = pDmaChannel->bEndpoint;

	if (pDmaChannel->bWrite != 0)
	{
		//Paced EP Write Channel
		ep <<= 3;
		ep &= (3 << 3);
		mode = mode & ~(3 << 3);
		((volatile uint32_t*)0xC7000014)[0] = dma_dwUsbMode = mode | ep;
	}
	else
	{
		//Paced EP Read Channel
		ep <<= 5;
		ep &= (3 << 5);
		mode = mode & ~(3 << 5);
		((volatile uint32_t*)0xC7000014)[0] = dma_dwUsbMode = mode | ep;
	}

	dma_start_usb_transfer(pChannel->pPrivateData, 
		mu_dma_transfer_complete, 0, pBuffer, dwLength, 
		pDmaChannel->wData_0x18, pDmaChannel->bEndpoint, pDmaChannel->bWrite);
	
	return 1;
}


/* 23467d0a - complete */
MUSB_DmaChannelStatus mu_dma_get_channel_status(MUSB_DmaChannel* pChannel)
{
#if 0
	console_send_string("mu_dma_get_channel_status (todo.c): TODO\r\n");
#endif

	struct MU_DMA_Channel* p = pChannel->pPrivateData;

#if 0
    {
        extern char debug_string[];
        sprintf(debug_string, "mu_dma_get_channel_status: p->status=%d\r\n", 
            p->status);
        console_send_string(debug_string);
    }
#endif

	return p->status;
}


/* 23467d10 - complete */
void mu_dma_release_channel(MUSB_DmaChannel* pChannel)
{
#if 0
	console_send_string("mu_dma_release_channel (todo.c): TODO\r\n");
#endif
}


/* 23467d12 - complete */
MUSB_DmaChannel* mu_dma_allocate_channel(void* pPrivateData, uint8_t bLocalEnd,
	    uint8_t bTransmit, uint8_t bProtocol, uint16_t wMaxPacketSize)
{
#if 0
	console_send_string("mu_dma_allocate_channel (todo.c): TODO\r\n");
#endif

	MU_DMA_Controller* pDmaController = pPrivateData;
	struct MU_DMA_Channel* pDmaChannel = &pDmaController->channel;

	if (pDmaController->channel.status != 1)
	{
		return 0;
	}

	pDmaChannel->status = 2; //r4
	pDmaChannel->pDmaController = pDmaController; //r0
	pDmaChannel->Data_0 = pDmaController->Data_0x40;
	pDmaChannel->bData_0x1a = 0; ///r4
	pDmaChannel->Data_4 = 0;
	pDmaChannel->dwLength = 0;
	pDmaChannel->bEndpoint = bLocalEnd;
	pDmaChannel->bWrite = bTransmit;
	pDmaChannel->wData_0x18 = wMaxPacketSize;
	pDmaChannel->bData_0x1d = 0;
	pDmaChannel->Data_0xc = 0;
	pDmaChannel->Data_0x10 = 0;
	pDmaChannel->Data_0x14 = 0;
	pDmaChannel->channel.pPrivateData = pDmaChannel;
	pDmaChannel->channel.dwMaxLength = (1 << 20);
	pDmaChannel->channel.dwActualLength = 0;
	pDmaChannel->channel.bStatus = MUSB_DMA_STATUS_FREE;
	pDmaChannel->channel.bDesiredMode = 0;

	return &pDmaChannel->channel;
}


/* 23467d5a - complete */
MUSB_DmaController* mu_dma_new_controller(MUSB_pfDmaChannelStatusChanged pfDmaChannelStatusChanged/*r6*/,
	    void* pDmaPrivate/*r1*/,
	    MUSB_pfSystemToBusAddress pfSystemToBusAddress/*r2*/,
	    void* pSystemPrivate/*r3*/,
	    uint8_t* pCoreBaseIsr/*arg_0*/,
	    uint8_t* pCoreBaseBsr/*arg_4*/)
{
#if 0
	console_send_string("mu_dma_new_controller (todo.c): TODO\r\n");
#endif

	uint32_t i;
	MU_DMA_Controller* pDmaController = 0;

	for (i = 0; i < 2; i++)
	{
		//loc_23467d64
		if (mu_dma_controller[i].Data_4 == 0)
		{
			pDmaController = &mu_dma_controller[i];
			pDmaController->bData_0 = i;
			//->loc_23467d7c
			break;
		}
		//loc_23467d76
	}
	//loc_23467d7c
	if (pDmaController == 0)
	{
		//loc_23467db8
		return 0;
	}
	//0x23467d80
	pDmaController->pfChannelStatusChanged = pfDmaChannelStatusChanged;
	pDmaController->Data_0x38 = pSystemPrivate;
	pDmaController->Data_0x34 = pfSystemToBusAddress;
	pDmaController->Data_4 = pDmaPrivate;
	pDmaController->Data_0x3c = pCoreBaseIsr;
	pDmaController->Data_0x40 = pCoreBaseBsr;
	pDmaController->controller.pPrivateData = pDmaController;
	pDmaController->controller.pfDmaStartController = mu_dma_start_controller;
	pDmaController->controller.pfDmaStopController = mu_dma_stop_controller;
	pDmaController->controller.pfDmaAllocateChannel = mu_dma_allocate_channel;
	pDmaController->controller.pfDmaReleaseChannel = mu_dma_release_channel;
	pDmaController->controller.pfDmaAllocateBuffer = mu_dma_allocate_buffer;
	pDmaController->controller.pfDmaReleaseBuffer = mu_dma_release_buffer;
	pDmaController->controller.pfDmaProgramChannel = mu_dma_program_channel;
	pDmaController->controller.pfDmaGetChannelStatus = mu_dma_get_channel_status;
	pDmaController->controller.pfDmaControllerIsr = 0;

	return &pDmaController->controller;
}


/* 23467dba - complete */
void mu_dma_delete_controller(MUSB_DmaController* p)
{
#if 0
	console_send_string("mu_dma_delete_controller (todo.c): TODO\r\n");
#endif

	MU_DMA_Controller* pDmaController = &mu_dma_controller[0];
	uint8_t i = 2;

	while (i--)
	{
		if (p == &pDmaController->controller)
		{
			pDmaController->Data_4 = 0;
			pDmaController->channel.status = 1;

			break;
		}

		pDmaController++;
	}
}


/* 23467de0 - complete */
int mu_dma_init(void)
{
#if 0
	console_send_string("mu_dma_init (todo.c): TODO\r\n");
#endif

	MGC_FAPI_MemSet(&mu_dma_controller, 0, sizeof(mu_dma_controller));
	mu_dma_controller[0].channel.status = 1;
	mu_dma_controller[1].channel.status = 1;

	MUSB_SetHsDmaControllerFactory(&mu_dma_controller_factory);

	return 1;
}


