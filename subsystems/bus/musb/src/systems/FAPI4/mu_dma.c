
#include "mu_dsi.h"
#include "mu_dci.h"

#pragma thumb

extern void* main_hMemBlk2; //23491dc0 +0x34

static MUSB_DmaController* sub_23467d5a(MUSB_pfDmaChannelStatusChanged pfDmaChannelStatusChanged,
	    void* pDmaPrivate,
	    MUSB_pfSystemToBusAddress pfSystemToBusAddress,
	    void* pSystemPrivate,
	    uint8_t* pCoreBaseIsr,
	    uint8_t* pCoreBaseBsr);
static void sub_23467dba(void);

extern int dma_dwUsbMode; //234927cc

MUSB_DmaControllerFactory Data_23494338 = //23494338
{
	    0x200,
	    sub_23467d5a,
	    sub_23467dba
};


typedef struct Struct_238ce0fc
{
	uint8_t bData_0; //0
	void* Data_4; //4
	MUSB_DmaController Data_8; //8
	MUSB_pfDmaChannelStatusChanged Data_0x30; //0x30
	MUSB_pfSystemToBusAddress Data_0x34; //0x34
	void* Data_0x38; //0x38
	uint8_t* Data_0x3c; //0x3c
	uint8_t* Data_0x40; //0x40
	struct Struct_238ce0fc_Inner_0x44
	{
		void* Data_0; //0
		int Data_4; //4
		int Data_8; //8
		int Data_0xc; //0xc
		int Data_0x10; //0x10
		int Data_0x14; //20
		uint16_t wData_0x18; //0x18
		uint8_t bData_0x1a; //0x1a
		uint8_t bEndpoint; //0x1b
		uint8_t bWrite; //0x1c
		uint8_t bData_0x1d; //0x1d
		MUSB_DmaChannel Data_0x20; //0x20
		//52 = 0x34
#if 1
		int Data_0x34; //0x34
		struct Struct_238ce0fc* Data_0x38; //0x38
		//0x3c
#endif
	} Data_0x44; //0x44
#if 0
	int Data_0x78; //0x78
	struct Struct_238ce0fc* Data_0x7c; //0x7c
#endif
	//0x80
} Struct_238ce0fc;


Struct_238ce0fc Data_238ce0fc[2]; //238ce0fc -> 238CE1FC


/* 23467c40 - todo */
uint8_t sub_23467c40(void* pPrivateData)
{
#if 0
	console_send_string("sub_23467c40 (todo.c): TODO\r\n");
#endif

	return 1;
}


/* 23467c44 - todo */
uint8_t sub_23467c44(void* pPrivateData)
{
#if 0
	console_send_string("sub_23467c44 (todo.c): TODO\r\n");
#endif

	return 1;
}


/* 23467c48 - todo */
uint8_t* sub_23467c48(MUSB_DmaChannel* pChannel, uint32_t dwLength)
{
#if 0
	console_send_string("sub_23467c48 (todo.c): TODO\r\n");
#endif

	return memblk_alloc(main_hMemBlk2, dwLength);
}


/* 23467c54 - todo */
uint8_t sub_23467c54(MUSB_DmaChannel* pChannel, uint8_t* pBuffer)
{
#if 0
	console_send_string("sub_23467c54 (todo.c): TODO\r\n");
#endif

	memblk_free(main_hMemBlk2, pBuffer);

	return 1;
}


/* 23467c62 - complete */
static void sub_23467c62(int status, struct Struct_238ce0fc_Inner_0x44* r4)
{
#if 0
	console_send_string("sub_23467c62 (todo.c): TODO\r\n");
#endif

	Struct_238ce0fc* r5 = r4->Data_0x38;

	uint8_t r6 = MGC_FAPI_ReadReg8(r4->Data_0, 0x0e);

	MGC_FAPI_WriteReg8(r4->Data_0, 0x0e, r4->bEndpoint);

	if (r4->bWrite != 0)
	{
		while (1)
		{
			uint32_t r0 = MGC_FAPI_ReadReg16(r4->Data_0, 0x12);
			if ((r0 & 2) == 0)
			{
				break;
			}
		}
	}

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "sub_23467c62: r4->Data_8=%d\r\n", 
            r4->Data_8);
        console_send_string(debug_string);
    }
#endif

	r4->Data_0x20.dwActualLength += r4->Data_8;
	r4->Data_0x34 = 1;

	(r5->Data_0x30)(r5->Data_4, r4->bEndpoint, r4->bWrite);

	MGC_FAPI_WriteReg8(r4->Data_0, 0x0e, r6);
}


/* 23467cb0 - todo */
uint8_t sub_23467cb0(MUSB_DmaChannel* pChannel,
	    uint16_t wPacketSize, uint8_t bMode,
	    const uint8_t* pBuffer, uint32_t dwLength)
{
#if 0
	console_send_string("sub_23467cb0 (todo.c): TODO\r\n");
#endif

	struct Struct_238ce0fc_Inner_0x44* r0 = pChannel->pPrivateData;

	pChannel->bDesiredMode = (r0->bWrite != 0);
	r0->Data_8 = dwLength;

	uint32_t r2 = dma_dwUsbMode;
	uint32_t r7 = r0->bEndpoint;

	if (r0->bWrite != 0)
	{
		//Paced EP Write Channel
		r7 <<= 3;
		r7 &= (3 << 3);
		r2 = r2 & ~(3 << 3);
		((volatile uint32_t*)0xC7000014)[0] = dma_dwUsbMode = r2 | r7;
	}
	else
	{
		//Paced EP Read Channel
		r7 <<= 5;
		r7 &= (3 << 5);
		r2 = r2 & ~(3 << 5);
		((volatile uint32_t*)0xC7000014)[0] = dma_dwUsbMode = r2 | r7;
	}

	dma_start_usb_transfer(pChannel->pPrivateData, 
		sub_23467c62, 0, pBuffer, dwLength, 
		r0->wData_0x18, r0->bEndpoint, r0->bWrite);
	
	return 1;
}


/* 23467d0a - complete */
MUSB_DmaChannelStatus sub_23467d0a(MUSB_DmaChannel* pChannel)
{
#if 0
	console_send_string("sub_23467d0a (todo.c): TODO\r\n");
#endif

	struct Struct_238ce0fc_Inner_0x44* p = pChannel->pPrivateData;

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "sub_23467d0a: p->Data_0x34=%d\r\n", 
            p->Data_0x34);
        console_send_string(debug_string);
    }
#endif

	return p->Data_0x34;
}


/* 23467d10 - complete */
void sub_23467d10(MUSB_DmaChannel* pChannel)
{
#if 0
	console_send_string("sub_23467d10 (todo.c): TODO\r\n");
#endif
}


/* 23467d12 - todo */
MUSB_DmaChannel* sub_23467d12(void* pPrivateData, uint8_t bLocalEnd,
	    uint8_t bTransmit, uint8_t bProtocol, uint16_t wMaxPacketSize)
{
#if 0
	console_send_string("sub_23467d12 (todo.c): TODO\r\n");
#endif

	Struct_238ce0fc* r3_ = pPrivateData;
	struct Struct_238ce0fc_Inner_0x44* r3 = &r3_->Data_0x44;

	if (r3_->/*Data_0x78*/Data_0x44.Data_0x34 != 1)
	{
		return 0;
	}

	r3_->/*Data_0x78*/Data_0x44.Data_0x34 = 2; //r4
	r3_->/*Data_0x7c*/Data_0x44.Data_0x38 = r3_; //r0
	r3->Data_0 = r3_->Data_0x40;
	r3->bData_0x1a = 0; ///r4
	r3->Data_4 = 0;
	r3->Data_8 = 0;
	r3->bEndpoint = bLocalEnd;
	r3->bWrite = bTransmit;
	r3->wData_0x18 = wMaxPacketSize;
	r3->bData_0x1d = 0;
	r3->Data_0xc = 0;
	r3->Data_0x10 = 0;
	r3->Data_0x14 = 0;
	r3->Data_0x20.pPrivateData = r3;
	r3->Data_0x20.dwMaxLength = (1 << 20);
	r3->Data_0x20.dwActualLength = 0;
	r3->Data_0x20.bStatus = MUSB_DMA_STATUS_FREE;
	r3->Data_0x20.bDesiredMode = 0;

	return &r3->Data_0x20;
}


/* 23467d5a - complete */
MUSB_DmaController* sub_23467d5a(MUSB_pfDmaChannelStatusChanged pfDmaChannelStatusChanged/*r6*/,
	    void* pDmaPrivate/*r1*/,
	    MUSB_pfSystemToBusAddress pfSystemToBusAddress/*r2*/,
	    void* pSystemPrivate/*r3*/,
	    uint8_t* pCoreBaseIsr/*arg_0*/,
	    uint8_t* pCoreBaseBsr/*arg_4*/)
{
#if 1
	console_send_string("sub_23467d5a (todo.c): TODO\r\n");
#endif

	uint32_t r4;
	Struct_238ce0fc* r0 = 0;

	for (r4 = 0; r4 < 2; r4++)
	{
		//loc_23467d64
		if (Data_238ce0fc[r4].Data_4 == 0)
		{
			r0 = &Data_238ce0fc[r4];
			r0->bData_0 = r4;
			//->loc_23467d7c
			break;
		}
		//loc_23467d76
	}
	//loc_23467d7c
	if (r0 == 0)
	{
		//loc_23467db8
		return 0;
	}
	//0x23467d80
	r0->Data_0x30 = pfDmaChannelStatusChanged;
	r0->Data_0x38 = pSystemPrivate;
	r0->Data_0x34 = pfSystemToBusAddress;
	r0->Data_4 = pDmaPrivate;
	r0->Data_0x3c = pCoreBaseIsr;
	r0->Data_0x40 = pCoreBaseBsr;
	r0->Data_8.pPrivateData = r0;
	r0->Data_8.pfDmaStartController = sub_23467c40;
	r0->Data_8.pfDmaStopController = sub_23467c44;
	r0->Data_8.pfDmaAllocateChannel = sub_23467d12;
	r0->Data_8.pfDmaReleaseChannel = sub_23467d10;
	r0->Data_8.pfDmaAllocateBuffer = sub_23467c48;
	r0->Data_8.pfDmaReleaseBuffer = sub_23467c54;
	r0->Data_8.pfDmaProgramChannel = sub_23467cb0;
	r0->Data_8.pfDmaGetChannelStatus = sub_23467d0a;
	r0->Data_8.pfDmaControllerIsr = 0;

	return &r0->Data_8;
}


/* 23467dba - todo */
void sub_23467dba(void)
{
	console_send_string("sub_23467dba (todo.c): TODO\r\n");

}


/* 23467de0 - complete */
int sub_23467de0()
{
#if 1
	console_send_string("sub_23467de0 (todo.c): TODO\r\n");
#endif

	MGC_FAPI_MemSet(&Data_238ce0fc, 0, sizeof(Data_238ce0fc));
	Data_238ce0fc[0]./*Data_0x78*/Data_0x44.Data_0x34 = 1;
	Data_238ce0fc[1]./*Data_0x78*/Data_0x44.Data_0x34 = 1;

	MUSB_SetHsDmaControllerFactory(&Data_23494338);

	return 1;
}


