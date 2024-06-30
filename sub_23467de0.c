
#include "data.h"
#include "mu_dsi.h"
#include "mu_dci.h"

#pragma thumb


static MUSB_DmaController* sub_23467d5a(MUSB_pfDmaChannelStatusChanged pfDmaChannelStatusChanged,
	    void* pDmaPrivate,
	    MUSB_pfSystemToBusAddress pfSystemToBusAddress,
	    void* pSystemPrivate,
	    uint8_t* pCoreBaseIsr,
	    uint8_t* pCoreBaseBsr);
static void sub_23467dba(void);


MUSB_DmaControllerFactory Data_23494338 = //23494338
{
	    0x200,
	    sub_23467d5a,
	    sub_23467dba
};


typedef struct
{
	uint8_t bData_0; //0
	void* Data_4; //4
#if 0
	MUSB_DmaController Data_8; //8
	MUSB_pfDmaChannelStatusChanged Data_0x30; //0x30
	MUSB_pfSystemToBusAddress Data_0x34; //0x34
#endif
	void* Data_0x38; //0x38
	uint8_t* Data_0x3c; //0x3c
	uint8_t* Data_0x40; //0x40
	int fill_0x44[13]; //0x44
	int Data_0x78; //0x78
	int fill_0x7c; //0x7c
	//0x80
} Struct_238ce0fc;


Struct_238ce0fc Data_238ce0fc[2]; //238ce0fc -> 238CE1FC

#if 0

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


/* 23467cb0 - todo */
uint8_t sub_23467cb0(MUSB_DmaChannel* pChannel,
	    uint16_t wPacketSize, uint8_t bMode,
	    const uint8_t* pBuffer, uint32_t dwLength)
{
	console_send_string("sub_23467cb0 (todo.c): TODO\r\n");

}


/* 23467d0a - todo */
MUSB_DmaChannelStatus sub_23467d0a(MUSB_DmaChannel* pChannel)
{
	console_send_string("sub_23467d0a (todo.c): TODO\r\n");

}


/* 23467d10 - todo */
void sub_23467d10(MUSB_DmaChannel* pChannel)
{
	console_send_string("sub_23467d10 (todo.c): TODO\r\n");

}


/* 23467d12 - todo */
MUSB_DmaChannel* sub_23467d12(void* pPrivateData, uint8_t bLocalEnd,
	    uint8_t bTransmit, uint8_t bProtocol, uint16_t wMaxPacketSize)
{
	console_send_string("sub_23467d12 (todo.c): TODO\r\n");


}

#endif

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

#if 0
	Struct_238ce0fc* r0 = 0;

	for (uint32_t r4 = 0; r4 < 2; r4++)
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
#else
	return 0;
#endif
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
	Data_238ce0fc[0].Data_0x78 = 1;
	Data_238ce0fc[1].Data_0x78 = 1;

	MUSB_SetHsDmaControllerFactory(&Data_23494338);

	return 1;
}


