
#include <stdint.h>
#include "ucos_ii.h"
#include "eth.h"

#define FREG(reg) ((volatile uint32_t*)(reg))

typedef struct
{
	uint8_t bData[13]; //0

} Struct_234012b0_a;


//234c0da4
int ethInitialized = 0; //234c0da4 +0
uint32_t eth_max_devices = 1; //234c0da8 +4
int ethDrvRxBufPtr = 0; //234c0dac +8
int ethDrvTxBufPtr = 0; //234c0db0 +0xc
int ethRxBufSize = 0x6000; //234c0db4 +0x10
int ethTxBufSize = 0x6000; //234c0db8 +0x14
int ethDataBuffer = 0; //234c0dbc +0x18

/* driver ID " eth" */
#define ETH_HANDLE_ID             (0x00657468)
/* handle lock mode */
#define ETH_HLM_IDX               (0x00000000)
#define ETH_HLM_PTR               (0x00000001)
#define ETH_HLM_SUSPEND           (0x00000010)
#define ETH_HLM_CHK_USE           (0x00000100)
#define ETH_HLM_USE_TRUE          (0x00001000)
#define ETH_HLM_USE_FALSE         (0x00010000)


void ethInitSettings(uint32_t, eth_open_params*);
int eth_fm3_start(int r5, eth_stat_params*, eth_drv_data*, int r3);
void sub_2347da64();
int fapi_eth_fm3_rUpdate(uint32_t, int, int*);
int fapi_eth_fm3_wUpdate(uint32_t, int32_t written, /*FAPI_ETH_FrameEndEnumT*/int frame);
int fapi_eth_fm3_intr(int);
void fm3CheckPhyLink(int a);
void fm3RUInt(int a);
void fm3FreeRDescs(uint32_t a, fmac3hDescT* from, fmac3hDescT* to);

ethHandleT ethHandle[2/*size???*/] = //234c0dc0 ->
{
	{
		ETH_HANDLE_ID,
		0,
		0,
		{
	    	/*.speed:*/  0,
			/*.duplex:*/ 1/*FULL_DUPLEX*/,
			/*.loop:*/   0,
			/*.linkup:*/ 0,
			/*.error:*/  0
		},
		{
			/*.rSize:*/  0,
			/*.rPtr:*/   0,
			/*.wSize:*/  0,
			/*.wPtr:*/   0
		},
		{'0','0','0','0','0','0','0','0','0','0','0','0'},
		0,
		eth_fm3_start,
		sub_2347da64,
		fapi_eth_fm3_rUpdate,
		fapi_eth_fm3_wUpdate,
		fapi_eth_fm3_intr,
		0,
		fm3CheckPhyLink,
	},
};


extern int Data_234df19c; //234df19c
extern int Data_234df1a0; //234df1a0


typedef struct
{
	eth_drv_data* pData; //0 = 234dd90c
	uint8_t* rBufStart; //4
	uint32_t rBufSize; //8
	uint8_t* wBufStart; //12
	uint32_t wBufSize; //16
	uint32_t a_rBufSize; //0x14 = 20
	int32_t wSizeHidden; //0x18 = 24
	int32_t wSizeWrap; //0x1c = 28
	uint32_t txFrameSizeMax; //0x20
	uint32_t txFrameSizeMin; //0x24
	uint32_t buf_size_limit; //0x28
	int user_speed; //0x2c = 234dd938
	eth_stat_params* pStat; //0x30 = 234dd93c
	uint8_t* pAddr; //0x34 = 234dd940
	fmac3hDescT* rDesc; //0x38
	uint32_t rDescNum; //0x3c
	fmac3hDescT* descPtrRx; //0x40
	fmac3hDescT* descPtrRead; //0x44
	uint32_t     rSizeWrap; //0x48
	fmac3hDescTxT* descPtrTx; //0x4c
	fmac3hDescTxT* descPtrWrite; //0x50
	int stopFlagR; //0x54
	int stopFlagT; //0x58
    uint32_t wtCnt; //0x5c
    uint32_t ofCnt; //0x60
    uint32_t jtCnt; //0x64
    uint32_t ufCnt; //0x68
    uint32_t lcCnt; //0x6c
    uint32_t ruCnt; //0x70
	uint32_t inCnt; //0x74
	uint32_t daCnt; //0x78
	int phyPort; //0x7c
	int phyAddress; //0x80
	uint32_t supJumbo; //0x84
	uint32_t supVLAN; //0x88
	//0x8C
} fmac3hHandle;

fmac3hHandle Data_234dd90c[1] = //234dd90c -> 234DD998
{
	{
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000600, //a_rBufSize
			0x00000000,
			0x00000000,
			1518,
			14,
			2016,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000008,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			1,
			0x0000001f,
			0x00000000,
			0x00000000,
	}
};


/* MARxH */
#define FMAC3H_REG_MARH_val_EN      (0x80000000)

#define FMAC3H_REG_val(R,V) ((uint32_t)(FMAC3H_REG_##R##_val_##V))

/* Descriptors utilities */
/* DES0 */
/* DES0 common */
#define FMAC3H_DES0_sft_OWN         (31)  /*1*/
#define FMAC3H_DES0_bit_OWN         (1)
#define FMAC3H_DES0_sft_ES          (15)  /*1*/
#define FMAC3H_DES0_bit_ES          (1)
/* RDES0 */
#define FMAC3H_DES0_sft_FL          (16)  /*14*/
#define FMAC3H_DES0_sft_DE          (14)  /*1*/
#define FMAC3H_DES0_sft_LE          (12)  /*1*/
#define FMAC3H_DES0_sft_OE          (11)  /*1*/
#define FMAC3H_DES0_sft_VLAN        (10)  /*1*/
#define FMAC3H_DES0_sft_FS          (9)   /*1*/
#define FMAC3H_DES0_sft_LS          (8)   /*1*/
#define FMAC3H_DES0_sft_GF          (7)   /*1*/
#define FMAC3H_DES0_sft_FT          (5)   /*1*/
#define FMAC3H_DES0_sft_RWT         (4)   /*1*/
#define FMAC3H_DES0_sft_RE          (3)   /*1*/
#define FMAC3H_DES0_sft_DBE         (2)   /*1*/
#define FMAC3H_DES0_sft_CE          (1)   /*1*/
#define FMAC3H_DES0_bit_FL          (0x3FFF)
#define FMAC3H_DES0_bit_DE          (1)
#define FMAC3H_DES0_bit_LE          (1)
#define FMAC3H_DES0_bit_OE          (1)
#define FMAC3H_DES0_bit_VLAN        (1)
#define FMAC3H_DES0_bit_FS          (1)
#define FMAC3H_DES0_bit_LS          (1)
#define FMAC3H_DES0_bit_GF          (1)
#define FMAC3H_DES0_bit_FT          (1)
#define FMAC3H_DES0_bit_RWT         (1)
#define FMAC3H_DES0_bit_RE          (1)
#define FMAC3H_DES0_bit_DBE         (1)
#define FMAC3H_DES0_bit_CE          (1)
/*TDES0*/
#define FMAC3H_DES0_sft_JT          (14)  /*1*/
#define FMAC3H_DES0_sft_NC          (10)  /*1*/
#define FMAC3H_DES0_sft_LCO         (9)   /*1*/
#define FMAC3H_DES0_sft_EC          (8)   /*1*/
#define FMAC3H_DES0_sft_VF          (7)   /*1*/
#define FMAC3H_DES0_sft_CC          (3)   /*4*/
#define FMAC3H_DES0_sft_ED          (2)   /*1*/
#define FMAC3H_DES0_sft_UF          (1)   /*1*/
#define FMAC3H_DES0_sft_DB          (0)   /*1*/
#define FMAC3H_DES0_bit_JT          (1)
#define FMAC3H_DES0_bit_NC          (1)
#define FMAC3H_DES0_bit_LCO         (1)
#define FMAC3H_DES0_bit_EC          (1)
#define FMAC3H_DES0_bit_VF          (1)
#define FMAC3H_DES0_bit_CC          (0xF)
#define FMAC3H_DES0_bit_ED          (1)
#define FMAC3H_DES0_bit_UF          (1)
#define FMAC3H_DES0_bit_DB          (1)
/*DES0 R/T collision*/
#define FMAC3H_DES0_sft_R_LC        (6)   /*1*/
#define FMAC3H_DES0_sft_T_LC        (11)  /*1*/
#define FMAC3H_DES0_bit_R_LC        (1)
#define FMAC3H_DES0_bit_T_LC        (1)

#define FMAC3H_DESC_get(I,X,Y)   (((Y) & FMAC3H_DESC_msk(I,X)) >> FMAC3H_DES##I##_sft_##X)

#define fm3IsOwnDesc(descPtr)   \
    ( (((descPtr)->des0 & FMAC3H_DESC0_msk_OWN)!=0) ? 1/*FAPI_ETH_TRUE*/ : 0/*FAPI_ETH_FALSE*/ )

#define fm3IsFSWDesc(descPtr) ( (((descPtr)->des1 &  FMAC3H_DESC_msk(1,FS)) != 0) ? 1/*FAPI_ETH_TRUE*/ : 0/*FAPI_ETH_FALSE*/ )

#define fm3IsFSRDesc(descPtr) ( (((descPtr)->des0 &  FMAC3H_DESC_msk(0,FS)) != 0) ? 1/*FAPI_ETH_TRUE*/ : 0/*FAPI_ETH_FALSE*/ )

#define fm3IsLSRDesc(descPtr) ( (((descPtr)->des0 &  FMAC3H_DESC_msk(0,LS)) != 0) ? 1/*FAPI_ETH_TRUE*/ : 0/*FAPI_ETH_FALSE*/ )

#define fm3WDescDatSize(descPtr) FMAC3H_DESC_get(1,BS1, (descPtr)->des1)

#define fm3RDescDatSize(i, descPtr) ( (((descPtr)->des0 & FMAC3H_DESC_msk(0,DE)) != 0) ?      \
                            /*FM3HDL*/Data_234dd90c[i].a_rBufSize :                                 \
                            ((((descPtr)->des0 & FMAC3H_DESC_msk(0,LS)) != 0) ? \
                                    FMAC3H_DESC_get(0,FL, (descPtr)->des0) :               \
                                    /*FM3HDL*/Data_234dd90c[i].a_rBufSize) )

#define fm3PrevWDesc(descPtr) ( (fmac3hDescT*)(((fmac3hDescTxT*)(descPtr))->prevPtr) )

#define fm3PrevRDesc(i, descPtr) ( ((descPtr) == &(Data_234dd90c[i].rDesc[0])) ?              \
                   (fmac3hDescT*)&(Data_234dd90c[i].rDesc[/*DESC_TAIL*/Data_234dd90c[i].rDescNum-1]) :                           \
                   ((fmac3hDescT*)(descPtr)-1) )

#define fm3NextWDesc(descPtr) ( (fmac3hDescT*)((descPtr)->des3) )

#define fm3NextRDesc(i, descPtr) ( ((descPtr) == &(Data_234dd90c[i].rDesc[/*DESC_TAIL*/Data_234dd90c[i].rDescNum-1])) ?      \
                   (fmac3hDescT*)&(Data_234dd90c[i].rDesc[0]) : ((fmac3hDescT*)(descPtr)+1) )

#define fm3ResetRDesc(descPtr) ( (descPtr)->des0 = FMAC3H_DESC0_msk_OWN )

int ethLockHandle(ethHandleT* p, int mode);
void ethUnLockHandle(ethHandleT* p, int mode);


/* 23446ac4 - todo */
int ethChInitialized(int condition, int modify)
{
#if 0
	console_send_string("ethChInitialized (todo.c): TODO\r\n");
#endif

	int retval = 0;

	if ((ethInitialized == 0) && (condition == 1))
	{
		return 0xff;
	}
	if ((ethInitialized == 1) && (condition == 0))
	{
		return 0xff;
	}
	//loc_23436d24
	if (modify != 1)
	{
		return retval;
	}

	if (ethInitialized != 1)
	{
		ethInitialized = 1;
	}
	else
	{
		ethInitialized = 0;
	}

	return retval;
}


/* 23436d3c / 23446b10 - todo */
int ethLockHandle(ethHandleT* p, int mode)
{
#if 0
	console_send_string("ethLockHandle (todo.c): TODO\r\n");
#endif

	uint8_t sp;
	int res = -109;
	uint32_t index;

	if (mode & ETH_HLM_PTR)
	{
		index = ethGetIndex(p);
	}
	else
	{
		index = (uint32_t)p;
	}

	if ((index < eth_max_devices) &&
			(ethHandle[index].id == ETH_HANDLE_ID))
	{
		ethHandleT* r6 = &ethHandle[index];

		OSSemPend(r6->lock, 0, &sp);

		if (sp != 0)
		{
			//loc_23436dd8
			return res;
		}

		int r0_ = 0;
		if (mode & ETH_HLM_CHK_USE)
		{
			//0x23436da4
			if (r6->inUse == 1)
			{
				r0_ = mode & ETH_HLM_USE_FALSE;
				//->loc_23436dc0
			}
			else if (r6->inUse == 0)
			{
				r0_ = mode & ETH_HLM_USE_TRUE;
			}
		}

		if (r0_ == 0)
		{
			//loc_23436dc8
			res = 0;
		}
		else
		{
			//loc_23436dd0
			OSSemPost(r6->lock);
		}
	}
	//loc_23436dd8
	return res;
}


/* 23446bb4 - todo */
int eth_get_mac_address(int index, uint8_t* macAddress)
{
#if 0
	console_send_string("eth_get_mac_address (todo.c): TODO\r\n");
#endif

	int res;
	int i = 0;

	res = ethChInitialized(1, 0);
	if (res != 0)
	{
		return res;
	}

	if (macAddress == 0)
	{
		return -104;
	}

	res = ethLockHandle((void*)index, 0);
	if (res != 0)
	{
		return res;
	}

	for (i = 0; i < 12;)
	{
		uint8_t digit = ethHandle[index].addr[i];
		int index = i++;
		macAddress[index] = digit;
	}

	ethUnLockHandle((void*)index, 0);

	return res;
}


/* 23436e68 / 23446c3c - todo */
int eth_set_mac_address(int index, Struct_234012b0_a* macAddress)
{
#if 0
	console_send_string("eth_set_mac_address (todo.c): TODO\r\n");
#endif

	int res;
	ethHandleT* r0;
	int32_t i = 0;

	res = ethChInitialized(1, 0);
	if (res != 0)
	{
		return res;
	}

	if (macAddress == 0)
	{
		return 0xff;
	}

	res = ethLockHandle((void*)index, (ETH_HLM_CHK_USE | ETH_HLM_USE_FALSE)); //0x10100);
	if (res != 0)
	{
		return res;
	}

	r0 = &ethHandle[index];

	for (i = 0; i < 12; i++)
	{
		r0->addr[i] = macAddress->bData[i];
	}

	ethUnLockHandle((void*)index, ETH_HLM_IDX); //0);

	return res;
}


/* 23447400 - todo */
int ethDealBuffer(uint32_t index)
{
#if 0
	console_send_string("ethDealBuffer (todo.c): TODO\r\n");
#endif

	int res = 0xff;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "ethDealBuffer: index=%d, eth_max_devices=%d\r\n",
				index, eth_max_devices);
		console_send_string(debug_string);
	}
#endif

	if (index >= eth_max_devices)
	{
		return res;
	}

	ethHandle[index].data.rSize = ethRxBufSize / eth_max_devices;
	ethHandle[index].data.wSize = ethTxBufSize / eth_max_devices;

	ethHandle[index].data.rPtr = (void*) (ethDrvRxBufPtr + (ethHandle[index].data.rSize * index));
	ethHandle[index].data.wPtr = (void*) (ethDrvTxBufPtr + (ethHandle[index].data.wSize * index));

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "ethDealBuffer: rSize=%d, rPtr=0x%x\r\n",
				ethHandle[index].data.rSize, ethHandle[index].data.rPtr);
		console_send_string(debug_string);
		sprintf(debug_string, "ethDealBuffer: wSize=%d, wPtr=0x%x\r\n",
				ethHandle[index].data.wSize, ethHandle[index].data.wPtr);
		console_send_string(debug_string);
	}
#endif

	return 0;
}


/* 23446a58 - complete */
void ethInitSettings(uint32_t index, eth_open_params* settings)
{
#if 0
	console_send_string("ethInitSettings (todo.c): TODO\r\n");
#endif

	if (index >= eth_max_devices)
	{
		return;
	}

	if (settings != 0)
	{
		ethHandle[index].user_speed = settings->speed;
		ethHandle[index].stat.speed = settings->speed;
		ethHandle[index].stat.duplex = settings->duplex;
		ethHandle[index].stat.loop = settings->loop;
	}
	else
	{
		ethHandle[index].user_speed = 0;
		ethHandle[index].stat.speed = 0;
		ethHandle[index].stat.duplex = 1;
		ethHandle[index].stat.loop = 0;
	}

	ethHandle[index].stat.linkup = 0;
	ethHandle[index].stat.error = 0;
}


/* 23446cc0 - complete */
void* eth_open(eth_open_params* pOpenParams)
{
	void* pHandle = 0;

#if 0
	console_send_string("eth_open (todo.c): TODO\r\n");
#endif

	if (0 == ethChInitialized(1, 0))
	{
		if (pOpenParams != 0)
		{
			int index = pOpenParams->Data_4;
			if (0 == ethLockHandle((void*)index, 0x10100))
			{
				//0x23446d00
				ethInitSettings(index, pOpenParams);

				if (0 != ethDealBuffer(index))
				{
					//0x23446d1c
					ethInitSettings(index, 0);
					//->loc_23446da8
				}
				else
				{
					//loc_23446d2c
					if (pOpenParams->recvCallback != 0)
					{
						ethHandle[index].recvCallback = pOpenParams->recvCallback;
					}

					ethHandle[index].inUse = 1;

					if (0 == (ethHandle[index].start)(index,
							&ethHandle[index].stat,
							&ethHandle[index].data,
							&ethHandle[index].addr))
					{
						pHandle = &ethHandle[index];
						//->loc_23446d9c
					}
					else
					{
						//0x23446d7c
						ethInitSettings(index, 0);
						sub_23446a20(index);

						ethHandle[index].recvCallback = 0;
						ethHandle[index].inUse = 0;
					}
					//loc_23446d9c
					ethUnLockHandle((void*)index, 0);
				}
			}
		}
	}
	//loc_23446da8
	return pHandle;
}


/* 23436fdc / 23446db0 - complete */
int eth_isr()
{
	uint32_t i;

#if 0
	console_send_string("eth_isr (todo.c): TODO\r\n");
#endif

	for (i = 0; i < eth_max_devices; i++)
	{
		if (ethHandle[i].inUse == 1)
		{
			if (1 == (ethHandle[i].intr)(i))
			{
				if (ethHandle[i].recvCallback != 0)
				{
					(ethHandle[i].recvCallback)(&ethHandle[i]);
				}
			}
		}
	}

	return 0;
}


/* 23446e18 - complete */
int eth_init()
{
#if 0
	console_send_string("eth_init (todo.c): TODO\r\n");
#endif

	int r4 = ethChInitialized(0, 1);
	if (r4 == 0)
	{
		r4 = ethRegisterDevices();
		if (r4 == 0)
		{
			r4 = ethAllocBuffers();
			if (r4 != 0)
			{
				sub_23447310();
				//loc_23437078
				if (0 != ethChInitialized(1, 1))
				{
					r4 = -112;
				}
				//->loc_234370b8
			}
			else
			{
				//loc_23437090
				intr_set_isr(eth_isr, 0, 22); //FAPI_INTR_ETH
				sub_2341b3b8(22, 0);

				FREG(0xe0000258)[0] = 0x0f;
				//loc_234370b8
			}
		}
		else
		{
			//loc_23437078
			if (0 != ethChInitialized(1, 1))
			{
				r4 = -112;
			}
			//->loc_234370b8
		}
	}
	//loc_234370b8
	return r4;
}


/* 2344700c - todo */
int eth_read(void* h, uint8_t* bufPtr, int32_t size, int* frame)
{
#if 0
	console_send_string("eth_read (todo.c): TODO\r\n");
#endif

	int read = 0;
	ethHandleT* r8 = h;
	int sl = 0;
	int sp;
	int r6;
//	ethHandleT* r8 = h;

	if (0 != ethChInitialized(1, 0))
	{
		return -1;
	}

	if ((size <= 0) || (bufPtr == 0) || (frame == 0))
	{
		return -1;
	}

	*frame = 0;

	r6 = ethLockHandle(r8, 0x1101);
	if (r6 != 0)
	{
		return r6;
	}

	sp = ethGetIndex(r8);

#if 0
    {
		extern char debug_string[];
    	uint32_t i;

#if 0
		sprintf(debug_string, "eth_read: rDesc=0x%08x [%d]\r\n",
				Data_234dd90c[sp].rDesc, Data_234dd90c[sp].rDescNum);
		console_send_string(debug_string);
#endif

		sprintf(debug_string, "eth_read: descPtrRx=0x%08x [%d]\r\n",
				Data_234dd90c[sp].descPtrRx,
				((int)(Data_234dd90c[sp].descPtrRx) - (int)(Data_234dd90c[sp].rDesc)) / sizeof(fmac3hDescT));
		console_send_string(debug_string);

		sprintf(debug_string, "eth_read: descPtrRead=0x%08x [%d]\r\n",
				Data_234dd90c[sp].descPtrRead,
				((int)(Data_234dd90c[sp].descPtrRead) - (int)(Data_234dd90c[sp].rDesc)) / sizeof(fmac3hDescT));
		console_send_string(debug_string);

    	for (i = 0; i < Data_234dd90c[sp].rDescNum; i++)
    	{
			sprintf(debug_string, "eth_read: [%d], des0=0x%08x\r\n",
					i, Data_234dd90c[sp].rDesc[i].des0);
			console_send_string(debug_string);
    	}
    }
#endif

	//->loc_2344711c
	while ((read < size) && ((*frame) == 0))
	{
		//loc_23447088
		if (r8->stat.error != 0)
		{
			r6 = -102;
			//->loc_23447130
			break;
		}
		//0x23447098
		void* r_ptr = r8->data.rPtr;
		int r_siz = r8->data.rSize;
		if ((r_ptr == 0) || (bufPtr == 0))
 		{
			//loc_234470ac
			r6 = -101;
			//->loc_23447130
			break;
		}
		//loc_234470b4
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "eth_read: r_siz=%d, size=%d, read=%d\r\n",
					r_siz, size, read);
			console_send_string(debug_string);
		}
#endif
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "eth_read: r_siz=%d\r\n", r_siz);
			console_send_string(debug_string);
		}
#endif
		if ((size - read) < r_siz)
		{
			r_siz = size - read;
		}

		if (r_siz == 0)
		{
			//0x234470c8
			if (sl == 1)
			{
				//->loc_23447130
				break;
			}
			//->loc_234470ec
		}
		//loc_234470d4
		else if (r_siz > 0)
		{
			//0x234470d8
			if (bufPtr != (void*) memcpy(bufPtr, r_ptr, r_siz))
			{
				//->loc_234470ac
				r6 = -101;
				//->loc_23447130
				break;
			}
		}
		//loc_234470ec
#if 0
		if (r_siz) hex_dump("eth_read", bufPtr, r_siz);
#endif
		bufPtr += r_siz;
		read += r_siz;

		r6 = (r8->rUpdate)(sp, r_siz, frame);

		if (r_siz == 0)
		{
			sl = 1;
		}

		if (r6 != 0)
		{
			//->loc_23447130
			break;
		}
	} //while ((read < size) && ((*frame) == 0))
	//loc_23447130
	ethUnLockHandle(r8, 1);

	if (r6 != 0)
	{
		read = r6;
	}

	return read;
}


/* 2344714c - complete */
int eth_get_stat(ethHandleT* r5, eth_stat_params* statParamsPtr)
{
#if 0
	console_send_string("eth_get_stat (todo.c): TODO\r\n");
#endif

	int r0 = ethChInitialized(1, 0);
	if (r0 != 0)
	{
		return r0;
	}

	if (statParamsPtr == 0)
	{
		return -104;
	}

	int r4 = ethLockHandle(r5, 0x1101);
	if (r4 == 0)
	{
		//memcpy(statParamsPtr, &r5->stat, sizeof(eth_stat_params));
		*statParamsPtr = r5->stat;

		ethUnLockHandle(r5, 1);
	}

	return r4;
}


/* 234471b0 - complete */
int eth_check_link(ethHandleT* r5)
{
#if 0
	console_send_string("eth_check_link (todo.c): TODO\r\n");
#endif

	int r4 = ethChInitialized(1, 0);
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "eth_check_link: r4=%d\r\n", r4);
		console_send_string(debug_string);
	}
#endif
	if (r4 == 0)
	{
		r4 = ethLockHandle(r5, 0x1111);
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "eth_check_link: r4=%d\r\n", r4);
			console_send_string(debug_string);
		}
#endif
		if (r4 == 0)
		{
			int r0 = ethGetIndex(r5);

			(r5->checklink)(r0);

			ethUnLockHandle(r5, 1);
		}
	}

	return r4;
}


/* 23437430 - todo */
void eth_set_buffer(int a)
{
#if 0
	console_send_string("eth_set_buffer (todo.c): TODO\r\n");
#endif

	ethDataBuffer = a;
}


/* 2343743c - todo */
int ethGetIndex(ethHandleT* p)
{
#if 0
	console_send_string("ethGetIndex (todo.c): TODO\r\n");
#endif

	uint32_t i;

	for (i = 0; i < eth_max_devices; i++)
	{
		if (p == &ethHandle[i])
		{
			//return i;
			break;
		}
	}

	return i;
}

#if 1

uint32_t fm3WFrameSize(uint32_t a)
{
#if 0
	console_send_string("fm3WFrameSize (todo.c): TODO\r\n");
#endif

    fmac3hDescTxT* tmp_desc_ptr = /*FM3HDL*/Data_234dd90c[a].descPtrWrite;
    uint32_t       data_size_in_frame = 0;

    while ( tmp_desc_ptr != 0/*NULL*/ )
    {
        data_size_in_frame +=
            fm3WDescDatSize(&(tmp_desc_ptr->desc));
        if ( fm3IsFSWDesc( &(tmp_desc_ptr->desc ) )
            == 1/*FAPI_ETH_TRUE*/ )
        {/* first desc of the frame */
            break;
        }
        /* refer prev desc */
        tmp_desc_ptr =
            (fmac3hDescTxT*)fm3PrevWDesc( tmp_desc_ptr );
    }
    return data_size_in_frame;
}


/* 23446e94 - todo */
int eth_write(/*FAPI_SYS_HandleT*/void* handle/*r8*/, const /*char_t*/uint8_t *bufPtr/*r7*/,
        int32_t size/*r6*/, /*FAPI_ETH_FrameEndEnumT*/int frame/*sl*/)
{
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "eth_write: size=%d, frame=%d\r\n",
				size, frame);
		console_send_string(debug_string);
	}

	hex_dump("eth_write", bufPtr, size);
#endif

	ethHandleT* r8 = handle;
    register int32_t remainder = size;  /* remaining bytes to write */
    register int32_t w_siz = 0;         /* current writable space/data size */
    register int32_t written = 0;       /* written size / return value */
    register int32_t errval;            /* error value */
    uint8_t/*char_t*/ *w_ptr = 0/*NULL*/;               /* current destination address */
    uint8_t/*char_t*/ dummybuf = 0;
    /*FAPI_ETH_FrameEndEnumT*/int tmp_frame = 0/*FAPI_ETH_FRAME_NOTEND*/;
#if ETH_LOCK_READ_WRITE
#if ETH_LOCK_USE_SYS_SEM
#else
    static uint32_t lock = 1;
#endif
#endif
    int fp;

    /*
     * 1) check arguments
     * 2) lock a handle
     * 3) copy data to 'wPtr' with 'wSize'
     * 4) update 'wPtr' and 'wSize' by calling wUpdate()
     * -) repeat 2) and 3) until exhausting a user buffer
     * 5) unlock a handle and return
     */

#if 0
    /* Check initialized flag */
    if (!ethInitialized) {
        return FAPI_ETH_ERR_NOT_INITIALIZED;
    }
#endif

    if (0 != ethChInitialized(1, 0))
    {
    	return -1;
    }

    /* 1. Check arguments */
    /* Check user buffer */
    if ((size != 0) && (bufPtr == 0/*NULL*/)) {
        return -1; //FAPI_ETH_ERR_NULL_PTR;
    }
    else if ((size == 0) && (bufPtr == 0/*NULL*/)) {
        bufPtr = &dummybuf;
    }

    /* Check size and frame flag */
    if ((size < 0) ||
        /*(frame == FAPI_ETH_FRAME_TERM)*/((frame != 1) && (frame != 0)) ||
        ((size == 0) && (frame != 1/*FAPI_ETH_FRAME_END*/))) {
        return -1; //FAPI_ETH_ERR_BAD_PARAMETER;
    }
    //loc_23446f08
    /* 2. lock handle */
#if 0
#if ETH_LOCK_READ_WRITE
#if ETH_LOCK_USE_SYS_SEM
    errval = ethLockHandle((ETH_HLM_CHK_USE |
                            ETH_HLM_USE_TRUE));
#else
    errval = ethLock(&lock, 0);
#endif
    if (errval != FAPI_OK) {
        return errval;
    }
#endif
#else
    errval = ethLockHandle(r8, 0x1101);
    if (errval != 0)
    {
    	return errval;
    }

    fp = ethGetIndex(r8);
    //->loc_23446fe8
#endif

#if 0
    /* Check status */
    if (ethHandle.stat.error != FAPI_ETH_ERR_NONE) {
        return FAPI_ETH_ERR_TXSTOP;
    }
#endif

    /* data write loop */
    while ((remainder > 0) || (size == 0)) {

    	if (r8->stat.error != 0)
    	{
    		written = -103;
    		break;
    	}

        /* 3. copy data */
        /* Get and check current data info  */
        w_ptr = /*ethHandle.*/r8->data.wPtr;
        w_siz = (int32_t) /*ethHandle.*/r8->data.wSize;

        /* check args of memcpy */
        if ((w_ptr == 0/*NULL*/) || (bufPtr == 0/*NULL*/)) {
            written = -101; //FAPI_ETH_ERR_DATACCESS;
            break;
        }

        /* buffer full */
        if (w_siz == 0) {
            if (remainder > 0) {
                break;
            }
        }
        else {
            /* calculate write size */
            if (w_siz > remainder) {
                w_siz = remainder;
            }

            /* copy data */
            memcpy(w_ptr, bufPtr, (uint32_t) w_siz);
        }

        /* set frame flag */
        if (w_siz == remainder) {
            /* data write completed */
            tmp_frame = frame;
        }
        else {
            /* data write does not complete */
            tmp_frame = 0/*FAPI_ETH_FRAME_NOTEND*/;
        }

        if ((w_siz == 0) && (tmp_frame == 0/*FAPI_ETH_FRAME_NOTEND*/)) {
            /* No data/area or  No flush order */
            break;
        }

        /* 4. update write size and pointer, and flush them to be sent */
        errval = /*ethHandle.*/r8->wUpdate(fp, w_siz, tmp_frame);
        if (errval >= 0) {
            /* No error */
            /* update write size and pointer */
            bufPtr = &(bufPtr[errval]);
            written += errval;

            if((tmp_frame == 1/*FAPI_ETH_FRAME_END*/) || (errval != w_siz)) {
                break;
            }
        }
        else {
            written = errval;
            break;
        }
        remainder = size - written;
    }/* data write loop */
    //loc_23446ff8
    /* 5. unlock handle */
#if 0
#if ETH_LOCK_READ_WRITE
#if ETH_LOCK_USE_SYS_SEM
    ethUnLockHandle();
#else
    ethUnlock(&lock);
#endif
#endif
#else
    ethUnLockHandle(r8, 1);
#endif

    return written;
}

#endif

/* 23447250 - todo */
int ethRegisterDevices()
{
#if 0
	console_send_string("ethRegisterDevices (todo.c): TODO\r\n");
#endif

	uint8_t sp;
	uint32_t i = 0;
	uint32_t pass_num = 0;
	int res = 0;

	for (i = 0; (i < eth_max_devices) && (res == 0); i++)
	{
		//loc_234374a0
		if (ethHandle[i].id == ETH_HANDLE_ID)
		{
			ethHandle[i].lock = OSSemCreate(1);
			if (ethHandle[i].lock == 0)
			{
				res = 0xff;
			}
			else
			{
				pass_num++;
			}
		}
		//loc_234374cc
	}
	//loc_234374e8
	if (res != 0)
	{
		for (pass_num = 0; pass_num < i; pass_num++)
		{
			//loc_234374f8
			if (ethHandle[pass_num].lock != 0)
			{
				ethHandle[pass_num].lock =
						(void*) OSSemDel(ethHandle[pass_num].lock, 1, &sp);
			}
			//loc_2343751c
		}
		//->loc_23437534
	}
	else
	{
		//loc_2343752c
		if (pass_num == 0)
		{
			res = 0xff;
		}
	}
	//loc_23437534
	return res;
}


/* 234473a8 - complete */
int ethAllocBuffers()
{
#if 0
	console_send_string("ethAllocBuffers (todo.c): TODO\r\n");
#endif

	int retval = 0;

	if (ethDataBuffer != 0)
	{
		int offset_rx = ((ethDataBuffer + 0x1f) & ~0x1f) - ethDataBuffer;

		ethDrvRxBufPtr = ethDataBuffer + offset_rx;

		int offset_tx = (((ethDataBuffer + (offset_rx + ethRxBufSize))
				+ 0x1f) & ~0x1f)
				- (ethDataBuffer + (offset_rx + ethRxBufSize));

		ethDrvTxBufPtr = ethDataBuffer + ((offset_rx + offset_tx) + ethRxBufSize);
	}

#if 0
    {
		extern char debug_string[];
		sprintf(debug_string, "ethAllocBuffers: ethDataBuffer=0x%x, ethDrvRxBufPtr=0x%x, ethDrvTxBufPtr=0x%x\r\n",
				ethDataBuffer, ethDrvRxBufPtr, ethDrvTxBufPtr);
		console_send_string(debug_string);
    }
#endif

	return retval;
}


/* 234376a4 / 23447478 - complete */
void ethUnLockHandle(ethHandleT* p, int mode)
{
#if 0
	console_send_string("ethUnLockHandle (todo.c): TODO\r\n");
#endif

	uint32_t index;

	if (mode & ETH_HLM_PTR)
	{
		index = ethGetIndex(p);
	}
	else
	{
		index = (uint32_t)p;
	}

	if (index < eth_max_devices)
	{
		OSSemPost(ethHandle[index].lock);
	}
}


/* 2347c940 - todo */
void fm3InitRDescs(int a)
{
#if 0
	console_send_string("fm3InitRDescs (todo.c): TODO\r\n");
#endif

    uint32_t ii;
    uint32_t one_desc_size = (int32_t)sizeof(fmac3hDescT);

#if 0
    {
		extern char debug_string[];
		sprintf(debug_string, "fm3InitRDescs: a=%d, rBufStart=0x%x, rPtr=0x%x\r\n",
				a, Data_234dd90c[a].rBufStart, Data_234dd90c[a].pData->rPtr);
		console_send_string(debug_string);
    }
#endif

    /* calculate number of descriptors */
    Data_234dd90c[a].rDescNum = Data_234dd90c[a].rBufSize /
                      ((Data_234dd90c[a].a_rBufSize) + one_desc_size);
    Data_234dd90c[a].rDesc
     = (fmac3hDescT*)((uint32_t)
       (&(Data_234dd90c[a].pData->rPtr[(Data_234dd90c[a].a_rBufSize * Data_234dd90c[a].rDescNum)])));
    Data_234dd90c[a].rBufSize  = Data_234dd90c[a].a_rBufSize * Data_234dd90c[a].rDescNum;

#if 0
    {
		extern char debug_string[];
		sprintf(debug_string, "fm3InitRDescs: rDescNum=%d, rDesc=0x%x, rBufSize=%d\r\n",
				Data_234dd90c[a].rDescNum, Data_234dd90c[a].rDesc, Data_234dd90c[a].rBufSize);
		console_send_string(debug_string);
    }
#endif

    /* init descriptors */
    for ( ii=0; ii < Data_234dd90c[a].rDescNum; ii++ )
    {
    	//loc_2347c988
        Data_234dd90c[a].rDesc[ii].des0 = FMAC3H_DESC0_msk_OWN;
        Data_234dd90c[a].rDesc[ii].des1 = (uint32_t)0;
        FMAC3H_DESC_set(1, BS1, Data_234dd90c[a].rDesc[ii].des1, Data_234dd90c[a].a_rBufSize);
        FMAC3H_DESC_set(1, BS2, Data_234dd90c[a].rDesc[ii].des1, 0);
        Data_234dd90c[a].rDesc[ii].des2 = (uint32_t)(Data_234dd90c[a].rBufStart) +
                                (uint32_t)(Data_234dd90c[a].a_rBufSize * ii);
        Data_234dd90c[a].rDesc[ii].des3 = 0;

#if 0
    {
		extern char debug_string[];
		sprintf(debug_string, "fm3InitRDescs: ii=%d, des1(size)=0x%x, des2(addr)=0x%x\r\n",
				ii, Data_234dd90c[a].rDesc[ii].des1, Data_234dd90c[a].rDesc[ii].des2);
		console_send_string(debug_string);
    }
#endif
    }
    /* set last flag of descriptor */
    FMAC3H_DESC_set(1, ER, Data_234dd90c[a].rDesc[ii - 1].des1, 1);
    /* Init desc information */
    Data_234dd90c[a].descPtrRx   = &(Data_234dd90c[a].rDesc[0]);
    Data_234dd90c[a].descPtrRead = &(Data_234dd90c[a].rDesc[0]);
}


/* 2347ca24 - todo */
void fm3Init1stWDesc(int a)
{
#if 0
	console_send_string("fm3Init1stWDesc (todo.c): TODO\r\n");
#endif

    uint32_t first_desc_addr = (uint32_t)(Data_234dd90c[a].pData->wPtr);

    /* allocate first descriptor  on the head of write buffer */
    Data_234dd90c[a].descPtrWrite = (fmac3hDescTxT*)(first_desc_addr);
    Data_234dd90c[a].pData->wPtr  = &(Data_234dd90c[a].pData->wPtr[sizeof(fmac3hDescTxT)]);
    Data_234dd90c[a].pData->wSize -= ((int32_t)(sizeof(fmac3hDescTxT)));
    Data_234dd90c[a].wSizeHidden  = (int32_t)(Data_234dd90c[a].pData->wSize - Data_234dd90c[a].buf_size_limit);
    Data_234dd90c[a].pData->wSize = Data_234dd90c[a].buf_size_limit;
    Data_234dd90c[a].descPtrTx    = Data_234dd90c[a].descPtrWrite;

    /* initialize first descriptor(pointer of Write/Transfer) */
    Data_234dd90c[a].descPtrWrite->desc.des0 = (uint32_t)0;
    Data_234dd90c[a].descPtrWrite->desc.des1 = (uint32_t)0;
    /* set interrupt flag */
    FMAC3H_DESC_set(1,IC,Data_234dd90c[a].descPtrWrite->desc.des1,1);
    /* set frame first flag */
    FMAC3H_DESC_set(1,FS,Data_234dd90c[a].descPtrWrite->desc.des1,1);
    /* set chained flag */
    FMAC3H_DESC_set(1,CH,Data_234dd90c[a].descPtrWrite->desc.des1,1);
    /* set buffer addr */
    Data_234dd90c[a].descPtrWrite->desc.des2 = (uint32_t)Data_234dd90c[a].pData->wPtr;
    /* chained settings */
    Data_234dd90c[a].descPtrWrite->desc.des3 = 0; //(uint32_t)NULL;
    Data_234dd90c[a].descPtrWrite->prevPtr   = 0; //NULL;
    /* Init extended area */
    Data_234dd90c[a].descPtrWrite->areaSiz   = (int32_t)sizeof(fmac3hDescTxT);

    /* set transfer frame size max */
    if ( Data_234dd90c[a].supJumbo == 0/*FAPI_ETH_FALSE*/ )
    {
        Data_234dd90c[a].txFrameSizeMax = 1518; //UNTAGED_NORMAL_FRAME;
    }
    else
    {
        Data_234dd90c[a].txFrameSizeMax = 9018; //UNTAGED_JUMBO_FRAME;
    }
    Data_234dd90c[a].txFrameSizeMin = 14; //MIN_SIZE_OF_FRAME;
    if ( Data_234dd90c[a].supVLAN == 1/*FAPI_ETH_TRUE*/ )
    {
        Data_234dd90c[a].txFrameSizeMax += 4; //TAGED_SIZE;
        Data_234dd90c[a].txFrameSizeMin += 4; //TAGED_SIZE;
    }
}


/* 2347cb54 - todo */
int/*fmac3hDescStatEnumT*/ fm3DescStat(uint32_t a, /*fmac3hRWEnumT*/int rw, fmac3hDescT*  descPtr)
{
#if 0
	console_send_string("fm3DescStat (todo.c): TODO\r\n");
#endif

    /*fmac3hDescStatEnumT*/int desc_stat = 0; //FMAC3H_FRAME_NOTEND;

    if ( rw == 2/*FMAC3H_W*/ )
    {/* write side */
        if ( (descPtr->des1 & 0x40000000/*FMAC3H_DESC_msk(1, LS)*/) != 0 )
        {/* Frame end is detected*/
            desc_stat = /*(fmac3hDescStatEnumT)*/((uint32_t)desc_stat |
                        (uint32_t)1/*FMAC3H_FRAME_END*/);
        }
        if ( (descPtr->des0 & 0x8000/*FMAC3H_DESC_msk(0, ES)*/) != 0 )
        {/* Error stat is detected */
            if( (descPtr->des0 & 0x4000/*FMAC3H_DESC_msk(0, JT)*/) != 0 )
            {/* jabber timeout *//* Transfer stop */
                desc_stat = /*(fmac3hDescStatEnumT)*/((uint32_t)desc_stat |
                        (uint32_t)0x12/*FMAC3H_FRAME_JT*/);
            }

            if ( (descPtr->des0 & 0x800/*FMAC3H_DESC_msk(0, T_LC)*/) != 0 )
            {/* loss of carrier error */
                desc_stat = /*(fmac3hDescStatEnumT)*/
                ((uint32_t)desc_stat | (uint32_t)0x20/*FMAC3H_FRAME_LC_T*/);
            }

            if ( (descPtr->des0 & 0x400/*FMAC3H_DESC_msk(0, NC)*/) != 0 )
            {/* no carrier error */
                desc_stat = /*(fmac3hDescStatEnumT)*/
                ((uint32_t)desc_stat | (uint32_t)0x40/*FMAC3H_FRAME_NC*/);
            }

            if ( (descPtr->des0 & 0x2/*FMAC3H_DESC_msk(0, UF)*/) != 0 )
            {/* under flow *//* suspend */
                desc_stat = /*(fmac3hDescStatEnumT)*/
                ((uint32_t)desc_stat | (uint32_t)0x402/*FMAC3H_FRAME_UNF*/);
            }
            else if ( (descPtr->des0 & 0x200/*FMAC3H_DESC_msk(0, LCO)*/) != 0 )
            {/* late collision *//* abort */
                desc_stat = /*(fmac3hDescStatEnumT)*/
                ((uint32_t)desc_stat | (uint32_t)0x82/*FMAC3H_FRAME_LCO*/);
            }

            if ( (descPtr->des0 & 0x100/*FMAC3H_DESC_msk(0, EC)*/) != 0 )
            {/* excessive collision *//* abort */
                desc_stat = /*(fmac3hDescStatEnumT)*/
                ((uint32_t)desc_stat | (uint32_t)0x102/*FMAC3H_FRAME_EC*/);
            }

            if ( (descPtr->des0 & 0x4/*FMAC3H_DESC_msk(0, ED)*/) != 0 )
            {/* excessive deferral *//* abort */
                desc_stat = /*(fmac3hDescStatEnumT)*/
                ((uint32_t)desc_stat | (uint32_t)0x202/*FMAC3H_FRAME_ED*/);
            }
        }/* Error stat is detected */
    }/* write side */
    else if ( rw == 1/*FMAC3H_R*/ )
    {/* read side */
        if ( (descPtr->des0 & /*FMAC3H_DESC_msk(0, LS)*/0x100) != 0 )
        {/* Frame end is detected*/
            uint32_t error_level = 0;

            desc_stat = 1; //FMAC3H_FRAME_END;
            if ( (descPtr->des0 & /*FMAC3H_DESC_msk(0, ES)*/0x8000) != 0 )
            {/*ES(CE/RE/R_LC/OE/DE) is detected*/
                desc_stat = 2; //FMAC3H_FRAME_TERM;
                if ( (descPtr->des0 & 0x4000/*FMAC3H_DESC_msk(0, DE)*/) != 0 )
                {/* no descriptor */
                    desc_stat = /*(fmac3hDescStatEnumT)*/
                    ((uint32_t)desc_stat | (uint32_t)0x10000/*FMAC3H_FRAME_DE*/);
                    error_level = 1;
                }

                if ( (descPtr->des0 & 0x800/*FMAC3H_DESC_msk(0, OE)*/) != 0 )
                {/* overflow */
                    desc_stat = /*(fmac3hDescStatEnumT)*/
                    ((uint32_t)desc_stat | (uint32_t)0x40002/*FMAC3H_FRAME_OVF*/);
                    error_level = 1;
                }

                if ( error_level == 0 )
                {
                    if ( (descPtr->des0 & 0x40/*FMAC3H_DESC_msk(0, R_LC)*/) != 0 )
                    {/* late collision */
                        desc_stat = /*(fmac3hDescStatEnumT)*/
                        ((uint32_t)desc_stat | (uint32_t)0x80002/*FMAC3H_FRAME_LC_R*/);
                    }

                    if ( (descPtr->des0 & 0x8/*FMAC3H_DESC_msk(0, RE)*/) != 0 )
                    {/* receive error */
                        desc_stat = /*(fmac3hDescStatEnumT)*/
                        ((uint32_t)desc_stat | (uint32_t)0x200002/*FMAC3H_FRAME_RE*/);
                    }

                    if ( (descPtr->des0 & 0x2/*FMAC3H_DESC_msk(0, CE)*/) != 0 )
                    {/* CRC error */
                        desc_stat = /*(fmac3hDescStatEnumT)*/
                        ((uint32_t)desc_stat | (uint32_t)0x800002/*FMAC3H_FRAME_CE*/);
                    }
                }
            }/*ES(CE/RE/LC/GF/OVF/DE) is detected*/
            if ( error_level == 0 )
            {
                if ( (descPtr->des0 & 0x10/*FMAC3H_DESC_msk(0, RWT)*/) != 0 )
                {/* watchdog timeout */
                    desc_stat = /*(fmac3hDescStatEnumT)*/
                    ((uint32_t)desc_stat | (uint32_t)0x100002/*FMAC3H_FRAME_RWT*/);
                }

                if ( ((descPtr->des0 & 0x1000/*FMAC3H_DESC_msk(0,LE)*/) != 0 ) &&
                        ((descPtr->des0 & 0x80/*FMAC3H_DESC_msk(0,GF)*/) == 0 ) )
                {/* length error */
                    desc_stat = /*(fmac3hDescStatEnumT)*/
                    ((uint32_t)desc_stat | (uint32_t)0x20002/*FMAC3H_FRAME_LE*/);
                }

                if ( (descPtr->des0 & 0x4/*FMAC3H_DESC_msk(0, DB)*/) != 0 )
                {/* dribble bit */
                    desc_stat = /*(fmac3hDescStatEnumT)*/
                    ((uint32_t)desc_stat | (uint32_t)0x400002/*FMAC3H_FRAME_DBE*/);
                }
            }
        }/* Frame end is detected*/
        else
        {/* error marked by software */
            if ( (descPtr->des0 & 0x585a/*FMAC3H_DESC_msk(0, R_EMARK)*/)
                    == 0x585a/*FMAC3H_DESC_msk(0, R_EMARK)*/ )
            {
                desc_stat = 2; //FMAC3H_FRAME_TERM;
            }
        }
    }/* read side */
    else
    {/*error case*/
        fm3SWError( a, "fm3DescStat()" /* __FUNCTION__ */ , "Wrong RW" );
    }

    return desc_stat;
}


/* 2347cc8c - todo */
void fm3FreeRDescs(uint32_t a, fmac3hDescT* from, fmac3hDescT* to)
{
#if 0
	console_send_string("fm3FreeRDescs (todo.c): TODO\r\n");
#endif

    if (from == to) {
        fm3ResetRDesc( from );
    }
    else if ((uint32_t) from < (uint32_t) to) {
        for (; (uint32_t) from <= (uint32_t) to; from = &(from[1]))
        {
            fm3ResetRDesc( from );
        }
    }

    /* from > to */
    else  {
        for (; (uint32_t) from <= (uint32_t) (&(/*FM3HDL*/Data_234dd90c[a].rDesc[/*DESC_TAIL*//*FM3HDL*/Data_234dd90c[a].rDescNum-1]));
                                                            from = &(from[1])) {
            fm3ResetRDesc( from );
        }
        for (from = &(/*FM3HDL*/Data_234dd90c[a].rDesc[0]); (uint32_t) from <= (uint32_t) to;
                                                            from = &(from[1])) {
            fm3ResetRDesc( from );
        }
    }
}

#if 1

/* 0x2347ccf4 - complete */
void fm3LCErr(uint32_t a, /*fmac3hRWEnumT*/int rw)
{
#if 0
	console_send_string("fm3LCErr (todo.c): TODO\r\n");
#endif

    ++/*FM3HDL*/Data_234dd90c[a].lcCnt;
#if ENA_ERR_MAXCNT
    if ( FM3HDL.lcCnt > FMAC3H_LC_MAX )
    {
        FM3HDL.pStat->error
            = (FAPI_ETH_ErrorEnumT)((uint32_t)(FM3HDL.pStat->error) |
                    (uint32_t)FAPI_ETH_ERR_LATE_COL);
        FM3HDL.stopFlagT
            = (fmac3hStatEnumT)((uint32_t)FM3HDL.stopFlagT |
                    (uint32_t)FMAC3H_FATAL_ERROR);
        FM3HDL.stopFlagR
            = (fmac3hStatEnumT)((uint32_t)FM3HDL.stopFlagR |
                    (uint32_t)FMAC3H_FATAL_ERROR);
    }
    else
#endif /* ENA_ERR_MAXCNT */
    {
        if ( rw == 2/*FMAC3H_W*/ )
        {
            /*FM3HDL*/Data_234dd90c[a].stopFlagT
                = /*(fmac3hStatEnumT)*/((uint32_t)/*FM3HDL*/Data_234dd90c[a].stopFlagT |
                        (uint32_t)0x00100000UL/*FMAC3H_TX_RUN*/);
        }
        else
        {
            /*FM3HDL*/Data_234dd90c[a].stopFlagR
                = /*(fmac3hStatEnumT)*/((uint32_t)/*FM3HDL*/Data_234dd90c[a].stopFlagR |
                        (uint32_t)0x00000100UL/*FMAC3H_RX_RUN*/);
        }
    }
}


static void fm3UNFInt(uint32_t a)
{
#if 0
	console_send_string("fm3UNFInt (todo.c): TODO\r\n");
#endif

    ++/*FM3HDL*/Data_234dd90c[a].ufCnt;
#if ENA_ERR_MAXCNT
    if ( FM3HDL.ufCnt > FMAC3H_UNF_MAX )
    {
        FM3HDL.pStat->error
        = (FAPI_ETH_ErrorEnumT)((uint32_t)(FM3HDL.pStat->error) |
                (uint32_t)FAPI_ETH_ERR_TX_BAND);
        FM3HDL.stopFlagT
        = (fmac3hStatEnumT)((uint32_t)FM3HDL.stopFlagT |
                (uint32_t)FMAC3H_FATAL_ERROR);
    }
    else
#endif /* ENA_ERR_MAXCNT */
    {
#if 0
        FAPI_SYS_PRINT_DEBUG( FAPI_ETH_ERR, "[ETH] FMAC3H Underflow Error\n" );
#endif
        /*FM3HDL*/Data_234dd90c[a].stopFlagT
        = /*(fmac3hStatEnumT)*/((uint32_t)/*FM3HDL*/Data_234dd90c[a].stopFlagT |
                (uint32_t)0x400000/*FMAC3H_TX_SUSP_HWERR*/);
    }
}


static void fm3ClearErrorCount(uint32_t a, /*fmac3hRWEnumT*/int rw)
{
#if 0
	console_send_string("fm3ClearErrorCount (todo.c): TODO\r\n");
#endif

    /* Clear error counts */
    if ( rw == 2/*FMAC3H_W*/ )
    {
        /*FM3HDL*/Data_234dd90c[a].jtCnt = 0;
        /*FM3HDL*/Data_234dd90c[a].ufCnt = 0;
    }
    else
    {
        /*FM3HDL*/Data_234dd90c[a].wtCnt = 0;
        /*FM3HDL*/Data_234dd90c[a].ofCnt = 0;
    }
    /*FM3HDL*/Data_234dd90c[a].lcCnt = 0;
}


/* 2347e398 - complete */
void fm3TJTInt(uint32_t a)
{
#if 0
	console_send_string("fm3TJTInt (todo.c): TODO\r\n");
#endif

    if( /*FM3HDL*/Data_234dd90c[a].supJumbo == 1/*FAPI_ETH_TRUE*/ )
    {
        /* If support jumbo-frame, TJT should be disabled. */
        /*FM3HDL*/Data_234dd90c[a].pStat->error
        = /*(FAPI_ETH_ErrorEnumT)*/((uint32_t)(/*FM3HDL*/Data_234dd90c[a].pStat->error) |
                (uint32_t)0x100/*FAPI_ETH_ERR_TX_CONFIG*/);
        /*FM3HDL*/Data_234dd90c[a].stopFlagT
        = /*(fmac3hStatEnumT)*/((uint32_t)/*FM3HDL*/Data_234dd90c[a].stopFlagT |
                (uint32_t)0x1/*FMAC3H_FATAL_ERROR*/);
    }
    else
    {/* !supJumbo */
        ++/*FM3HDL*/Data_234dd90c[a].jtCnt;
#if ENA_ERR_MAXCNT
        if ( FM3HDL.jtCnt > FMAC3H_TJT_MAX )
        {
            FM3HDL.pStat->error
            = (FAPI_ETH_ErrorEnumT)((uint32_t)(FM3HDL.pStat->error) |
                    (uint32_t)FAPI_ETH_ERR_TJT_MAX);
            FM3HDL.stopFlagT
            = (fmac3hStatEnumT)((uint32_t)FM3HDL.stopFlagT |
                    (uint32_t)FMAC3H_FATAL_ERROR);
        }
        else
#endif /* ENA_ERR_MAXCNT */
        {
#if 0
            FAPI_SYS_PRINT_DEBUG( FAPI_ETH_ERR,
                    "[ETH] FMAC3H Jobber Timeout Error, %d\n",
                    FM3HDL.jtCnt);
#endif
            /*FM3HDL*/Data_234dd90c[a].stopFlagT
            = /*(fmac3hStatEnumT)*/((uint32_t)/*FM3HDL*/Data_234dd90c[a].stopFlagT |
                    (uint32_t)0x1000000/*FMAC3H_TX_STOP_HWERR*/);
        }
    }/* !supJumbo */
}


/* 2347cd30 - todo */
void fm3HandleIntTx(uint32_t a/*sb*/)
{
#if 0
	console_send_string("fm3HandleIntTx (todo.c): TODO\r\n");
#endif

#if 1
    uint32_t            aborted = 0; //FAPI_ETH_FALSE;
    /*fmac3hDescStatEnumT*/int desc_stat;


    /*   Before        Descriptors         After interrupt
     *                +---------------+
     *                |1              |
     *                |---------------|
     *                |1              |
     * descPtrTx   -->|---------------|
     *                |1=>0           |    Own bit is 1 => 0, and
     *                |---------------|<---new descPtrTx should be here.
     *                |0              |
     *                |---------------|
     *                |0              |
     * descPtrWrite-->|---------------|
     *                |1              |
     *                +---------------+
     */

    while ( (/*FM3HDL*/Data_234dd90c[a].descPtrTx != /*FM3HDL*/Data_234dd90c[a].descPtrWrite) &&
            ((aborted == 1/*FAPI_ETH_TRUE*/) ||
             (fm3IsOwnDesc( &(/*FM3HDL*/Data_234dd90c[a].descPtrTx->desc) ) == 0/*FAPI_ETH_FALSE*/)) )
    {/* completed descriptor search loop */
        desc_stat = fm3DescStat(a, 2/*FMAC3H_W*/, &(/*FM3HDL*/Data_234dd90c[a].descPtrTx->desc));
        if ( ((uint32_t)desc_stat & (uint32_t)0x12/*FMAC3H_FRAME_JT*/) == (uint32_t)0x12/*FMAC3H_FRAME_JT*/ )
        {/* stopped */
            fm3TJTInt( a );
            aborted = 1; //FAPI_ETH_TRUE;
        }
        if ( ((uint32_t)desc_stat & (uint32_t)0x402/*FMAC3H_FRAME_UNF*/) == (uint32_t)0x402/*FMAC3H_FRAME_UNF*/ )
        {/* suspended */
            fm3UNFInt( a );
            aborted = 1; //FAPI_ETH_TRUE;
        }
        else if ( ((uint32_t)desc_stat & (uint32_t)0x82/*FMAC3H_FRAME_LCO*/) == (uint32_t)0x82/*FMAC3H_FRAME_LCO*/ )
        {
            fm3LCErr( a, 2/*FMAC3H_W*/ );
            aborted = 1; //FAPI_ETH_TRUE;
        }else{/*None*/}

        if ( ((uint32_t)desc_stat & (uint32_t)0x102/*FMAC3H_FRAME_EC*/) == (uint32_t)0x102/*FMAC3H_FRAME_EC*/ )
        {
            aborted = 1; //FAPI_ETH_TRUE;
        }
        if ( ((uint32_t)desc_stat & (uint32_t)0x202/*FMAC3H_FRAME_ED*/) == (uint32_t)0x202/*FMAC3H_FRAME_ED*/ )
        {
            aborted = 1; //FAPI_ETH_TRUE;
        }

        if ( desc_stat == 1/*FMAC3H_FRAME_END*/ )
        {
            if( aborted != 1/*FAPI_ETH_TRUE*/ )
            {/* Normal ended frame */
                /* clear error counts */
                fm3ClearErrorCount( a, 2/*FMAC3H_W*/ );
            }
            else
            {
                aborted = 0; //FAPI_ETH_FALSE;
            }
        }

        /* feed writable size */
        if ( (uint32_t)(/*FM3HDL*/Data_234dd90c[a].descPtrTx) < (uint32_t)(/*FM3HDL*/Data_234dd90c[a].descPtrWrite) )
        {
            /*FM3HDL*/Data_234dd90c[a].wSizeWrap += (int32_t)/*FM3HDL*/Data_234dd90c[a].descPtrTx->areaSiz;
        }
        else if ( (uint32_t)(/*FM3HDL*/Data_234dd90c[a].descPtrTx) > (uint32_t)(/*FM3HDL*/Data_234dd90c[a].descPtrWrite) )
        {
            if ( (/*FM3HDL*/Data_234dd90c[a].wSizeHidden < 0) &&
                 ((/*FM3HDL*/Data_234dd90c[a].wSizeHidden + (int32_t)/*FM3HDL*/Data_234dd90c[a].descPtrTx->areaSiz) >= 0) )
            {
                /*FM3HDL*/Data_234dd90c[a].pData->wSize -= (uint32_t) /*FM3HDL*/Data_234dd90c[a].wSizeHidden;
                /*FM3HDL*/Data_234dd90c[a].wSizeHidden  += (int32_t) /*FM3HDL*/Data_234dd90c[a].descPtrTx->areaSiz;
            }
            else if ( (/*FM3HDL*/Data_234dd90c[a].wSizeHidden < 0) &&
                      ((/*FM3HDL*/Data_234dd90c[a].wSizeHidden + (int32_t)/*FM3HDL*/Data_234dd90c[a].descPtrTx->areaSiz) < 0) )
            {
                /*FM3HDL*/Data_234dd90c[a].pData->wSize += /*FM3HDL*/Data_234dd90c[a].descPtrTx->areaSiz;
                /*FM3HDL*/Data_234dd90c[a].wSizeHidden  += (int32_t)/*FM3HDL*/Data_234dd90c[a].descPtrTx->areaSiz;
            }
            else
            {
                /*FM3HDL*/Data_234dd90c[a].wSizeHidden += (int32_t)/*FM3HDL*/Data_234dd90c[a].descPtrTx->areaSiz;
            }
        }
        else{/* Never */}
        /* refer next desc */
        /*FM3HDL*/Data_234dd90c[a].descPtrTx
            = (fmac3hDescTxT*)fm3NextWDesc(&((/*FM3HDL*/Data_234dd90c[a].descPtrTx)->desc));
    }/* completed descriptor search loop */
#endif
}

#endif

/* 2347cf1c - complete */
int fm3StartDevice(int a, int rw)
{
#if 1
	console_send_string("fm3StartDevice (todo.c): TODO\r\n");
#endif

    int32_t retval   = 0; //FAPI_OK;
    uint32_t omr     = FREG(0xe4001018)[0]; //FREG_ETH_GetOmr();
    uint32_t old_omr = omr;

    if ( ((uint32_t)rw & (uint32_t)1/*FMAC3H_R*/) != 0 )
    {
    	//0x2347cf50
        if( /*FMAC3H_FLAG_IS(FM3HDL.stopFlagR, FMAC3H_RX_STOP)*/ (Data_234dd90c[a].stopFlagR & 0x00000800UL)
        ||  /*FMAC3H_FLAG_IS(FM3HDL.stopFlagR, FMAC3H_RX_STOP_HWERR)*/ (Data_234dd90c[a].stopFlagR & 0x00001000UL))
        {
            /*FM3HDL*/Data_234dd90c[a].stopFlagR = 0x00000100UL; //FMAC3H_RX_RUN;
            /* start command(set OMR.SR) */
            omr |= 2; //FMAC3H_REG_val(OMR, RX_START);
        }
        else if(
                 /*FMAC3H_FLAG_IS(FM3HDL.stopFlagR, FMAC3H_RX_SUSP_NOBUF)*/ (Data_234dd90c[a].stopFlagR & 0x00000200UL) ||
                 /*FMAC3H_FLAG_IS(FM3HDL.stopFlagR, FMAC3H_RX_SUSP_HWERR)*/ (Data_234dd90c[a].stopFlagR & 0x00000400UL) )

        {
        	/*FM3HDL*/Data_234dd90c[a].stopFlagR = 0x00000100UL; //FMAC3H_RX_RUN;
            /* poll command */
#if 0
            FREG_ETH_SetRpdr( (uint32_t)1 );
#else
            { Data_234df1a0 = 1; FREG(0xe4001008)[0] = 1; }
#endif
        }
        else /* FMAC3H_RX_RUN || FMAC3H_FATAL_ERROR */
        {
            /* None */
        }
    }
    //loc_2347cf7c
    if ( ((uint32_t)rw & (uint32_t)2/*FMAC3H_W*/) != 0 )
    {
        if( /*FMAC3H_FLAG_IS(FM3HDL.stopFlagT, FMAC3H_TX_STOP)*/ (Data_234dd90c[a].stopFlagT & 0x00800000UL)
        ||  /*FMAC3H_FLAG_IS(FM3HDL.stopFlagT, FMAC3H_TX_STOP_HWERR)*/ (Data_234dd90c[a].stopFlagT & 0x01000000UL))
        {
            /*FM3HDL*/Data_234dd90c[a].stopFlagT = 0x00100000UL; //FMAC3H_TX_RUN;
            /* set TDLAR(descriptor base) current desc */
#if 0
            FREG_ETH_SetTdlar( (uint32_t)(&(FM3HDL.descPtrTx->desc)) );
#else
            FREG(0xe4001010)[0] = (uint32_t)(&(/*FM3HDL*/Data_234dd90c[a].descPtrTx->desc));
#endif
            /* start command (set OMR.ST) */
            omr |= 0x2000; //FMAC3H_REG_val(OMR, TX_START);
        }
        else if( /*FMAC3H_FLAG_IS(FM3HDL.stopFlagT, FMAC3H_TX_SUSP_NODAT)*/ (Data_234dd90c[a].stopFlagT & 0x00200000UL)
             ||  /*FMAC3H_FLAG_IS(FM3HDL.stopFlagT, FMAC3H_TX_SUSP_HWERR)*/(Data_234dd90c[a].stopFlagT & 0x00400000UL) )
        {
            /*FM3HDL*/Data_234dd90c[a].stopFlagT = 0x00100000UL; //FMAC3H_TX_RUN;
            /* poll command */
#if 0
            FREG_ETH_SetTpdr( (uint32_t)1 );
#else
            { Data_234df19c = 1; FREG(0xe4001004)[0] = 1; }
#endif
        }
        else /* FMAC3H_TX_RUN || FMAC3H_FATAL_ERROR */
        {
            /* None */
        }
    }
    //loc_2347cfb8
    if ( omr != old_omr )
    {
        /* It is  NOT assumed that this function is
           executed in such a situation that
           Transmit process runs and Receive process stops.
           Please fix me when such a case is needed.       */
#if 0
        FREG_ETH_SetOmr( omr | FREG_ETH_GetOmr() );
#else
        FREG(0xe4001018)[0] |= omr;
#endif
    }

    return retval;
}


/* 2347cfcc - todo */
int fm3FixStat(int a)
{
#if 0
	console_send_string("fm3FixStat (todo.c): TODO\r\n");
#endif

    int32_t int_result = 0; //FAPI_OK;

    /* transfer side */
    if ( ((uint32_t)/*FM3HDL*/Data_234dd90c[a].stopFlagT & (uint32_t)1/*FMAC3H_FATAL_ERROR*/) != 0 )
    {/* fatal error, stop device */
        fm3StopDevice( a, 3/*FMAC3H_RW*/ );
        /*FM3HDL*/Data_234dd90c[a].stopFlagT = 1; //FMAC3H_FATAL_ERROR;
        int_result = -105; //FAPI_ETH_ERR_FATALSTOP;
    }
    else if(
      (((uint32_t)/*FM3HDL*/Data_234dd90c[a].stopFlagT & (uint32_t)0x01000000UL/*FMAC3H_TX_STOP_HWERR*/) != 0) ||
      (((uint32_t)/*FM3HDL*/Data_234dd90c[a].stopFlagT & (uint32_t)0x00400000UL/*FMAC3H_TX_SUSP_HWERR*/) != 0) )
    {/* restart transfer */
        int_result = fm3StartDevice( a, 2/*FMAC3H_W*/ );
#if 0
        if ( int_result != 0/*FAPI_OK*/ )
        {/* Not Implemented */
            int_result = 0; //FAPI_OK;
        }
#endif
    }
    else if ( ((uint32_t)/*FM3HDL*/Data_234dd90c[a].stopFlagT & (uint32_t)0x200000/*FMAC3H_TX_SUSP_NODAT*/) != 0 )
    {
        /*FM3HDL*/Data_234dd90c[a].stopFlagT =
            /*(fmac3hStatEnumT)*/((uint32_t)(/*FM3HDL*/Data_234dd90c[a].stopFlagT) &
                    ~((uint32_t)0x100000/*FMAC3H_TX_RUN*/));
    }

    /* receive side */
    if ( ((uint32_t)/*FM3HDL*/Data_234dd90c[a].stopFlagR & (uint32_t)1/*FMAC3H_FATAL_ERROR*/) != 0 )
    {
        fm3StopDevice( a, 3/*FMAC3H_RW*/ );
        /*FM3HDL*/Data_234dd90c[a].stopFlagR = 1; //FMAC3H_FATAL_ERROR;
        int_result = -105; //FAPI_ETH_ERR_FATALSTOP;
    }
    else if ( ((uint32_t)/*FM3HDL*/Data_234dd90c[a].stopFlagR & (uint32_t)0x200/*FMAC3H_RX_SUSP_NOBUF*/) != 0 )
    {
        /*FM3HDL*/Data_234dd90c[a].stopFlagR =
         /*(fmac3hStatEnumT)*/((uint32_t)(/*FM3HDL*/Data_234dd90c[a].stopFlagR) &
                           ~((uint32_t)0x100/*FMAC3H_RX_RUN*/));

    }

    return int_result;
}


/* 2347d0b8 - complete */
int fm3CheckMiiDevLink(int a)
{
#if 0
	console_send_string("fm3CheckMiiDevLink (todo.c): TODO\r\n");
#endif

    uint32_t           reg_val = (uint32_t)0;
    /*FAPI_ETH_LinkEnumT*/int link    = 2; //FAPI_ETH_LINKUNKNOWN;

    if ( (fm3ReadPhy( /*FM3HDL*/Data_234dd90c[a].phyAddress, 1/*MII_addr(1)*/, &reg_val )) == 0/*FAPI_OK*/ )
    {
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "fm3CheckMiiDevLink: reg_val=0x%x\r\n", reg_val);
			console_send_string(debug_string);
		}
#endif

        if ( (reg_val & 0x04/*MII_msk(1, LINK_STAT)*/) == 0x04/*MII_msk(1, LINK_STAT)*/ )
        {
            link = 1; //FAPI_ETH_LINKUP;
        }
        else
        {
            link = 0; //FAPI_ETH_LINKDOWN;
        }
    }
    return link;
}


/* 2347d104 - complete */
int fm3UpdateStatusMiiDevice(uint32_t a)
{
#if 0
	console_send_string("fm3UpdateStatusMiiDevice (todo.c): TODO\r\n");
#endif

    uint32_t phy_register_value;
    int32_t  retval;

    /* update status information */
    retval = fm3ReadPhy( /*FM3HDL*/Data_234dd90c[a].phyAddress, 0x1f/*MII_addr(31)*/, &phy_register_value );
    if ( retval == 0/*FAPI_OK*/ )
    {
        /* speed & duplex */
        switch( (phy_register_value & 0x1c/*MII_msk(31, SPEED)*/) )
        {
            case 0x18: //MII_val(31, 100M_FULL) :
                /*FM3HDL*/Data_234dd90c[a].pStat->speed =  100; //FAPI_ETH_SPEED_100M;
                /*FM3HDL*/Data_234dd90c[a].pStat->duplex = 1; //FAPI_ETH_FULL_DUPLEX;
                break;
            case 8: //MII_val(31, 100M_HALF) :
                /*FM3HDL*/Data_234dd90c[a].pStat->speed =  100; //FAPI_ETH_SPEED_100M;
                /*FM3HDL*/Data_234dd90c[a].pStat->duplex = 0; //FAPI_ETH_HALF_DUPLEX;
                break;
            case 0x14: //MII_val(31, 10M_FULL) :
                /*FM3HDL*/Data_234dd90c[a].pStat->speed =  10; //FAPI_ETH_SPEED_10M;
                /*FM3HDL*/Data_234dd90c[a].pStat->duplex = 1; //FAPI_ETH_FULL_DUPLEX;
                break;
            case 4: //MII_val(31, 10M_HALF) :
                /*FM3HDL*/Data_234dd90c[a].pStat->speed =  10; //FAPI_ETH_SPEED_10M;
                /*FM3HDL*/Data_234dd90c[a].pStat->duplex = 0; //FAPI_ETH_HALF_DUPLEX;
                break;
            default:
                retval = -112; //FAPI_ETH_ERR_UNKNOWN;
                break;
        }
    }

    return retval;
}


/* 2347d18c - todo */
int fm3StartMiiDevice(uint32_t r7)
{
#if 1
	console_send_string("fm3StartMiiDevice (todo.c): TODO\r\n");
#endif

#if 1
    int32_t  retval;
    uint32_t phy_register_value/*sp4*/ = (uint32_t)0;
    uint32_t sp = 0;
    uint32_t linkup_timeout/*r5*/ = 3000; // 10; //FMAC3H_PHY_LINK_TIMEOUT;
    uint32_t ii;

    /* reset PHY */
    retval = fm3WritePhy( /*FM3HDL*/Data_234dd90c[r7].phyAddress, 0/*MII_addr(0)*/, 0x8000/*MII_val(0, RESET)*/ );
    if ( retval != 0/*FAPI_OK*/ )
    {
        return retval;
    }

    /* wait reset */
    for ( ii = 0; ii < 1000/*FMAC3H_PHY_SRST_TIMEOUT*/; ii++ )
    {
    	//loc_2347d1d0
        /*FAPI_SYS_SLEEP*/rtos_task_wait( 1 ); /* sleep 1msec */
        retval = fm3ReadPhy( /*FM3HDL*/Data_234dd90c[r7].phyAddress, 0/*MII_addr(0)*/, &phy_register_value );
        if ( retval != 0/*FAPI_OK*/ )
        {
            return retval;
        }
        /* check reset is done */
        if ( (phy_register_value & 0x8000/*MII_val(0, RESET)*/) == 0 )
        {
            break;
        }
    }
    //0x2347d208
    if ( ii == 1000/*FMAC3H_PHY_SRST_TIMEOUT*/ )
    {
#if 0
        FAPI_SYS_PRINT_DEBUG( FAPI_ETH_ERR, PHY_RESET_MSG, __FUNCTION__ );
#endif
        //->loc_2347d22c
        return 0xff; //FAPI_ETH_ERR_TIMEOUT;
    }
    fm3ReadPhy( /*FM3HDL*/Data_234dd90c[r7].phyAddress, 2, &sp );
    if (sp != 7)
    {
    	return 0xff;
    }
    //loc_2347d234
    /* unset fields to be set */
    phy_register_value &= ~0x7100/*(MII_msk(0, LOOPBACK)  | MII_msk(0, SPEEDSELECT) |
                            MII_msk(0, AN_ENABLE) | MII_msk(0, DUPLEX_MODE))*/;

    /* loopback setting */
    if ( /*FM3HDL*/Data_234dd90c[r7].pStat->loop == 2/*FAPI_ETH_LOOP_ON_PHY*/ )
    {
        phy_register_value |= 0x4000; //MII_val(0, LOOPBACK);
    }

    if ( /*FM3HDL*/Data_234dd90c[r7].pStat->speed == 0/*FAPI_ETH_SPEED_AUTO*/ )
    {/* auto nego */
        phy_register_value |= 0x1000; //MII_val(0, AUTO_NEGO);
        //->loc_2347d290
    }
    else
    {/* ! auto nego */
        /* speed */
        if ( /*FM3HDL*/Data_234dd90c[r7].pStat->speed == 100/*FAPI_ETH_SPEED_100M*/ )
        {/* 100M */
            phy_register_value |= 0x2000; //MII_val(0, 100M);
        }
        else
        {/* 10M */
            phy_register_value |= 0; //MII_val(0, 10M);
        }
        /* duplex */
        if ( /*FM3HDL*/Data_234dd90c[r7].pStat->duplex == 1/*FAPI_ETH_FULL_DUPLEX*/ )
        {/* Full Duplex */
            phy_register_value |= 0x100; //MII_val(0, DUPLEX_FULL);
        }
        else
        {/* half */
            phy_register_value |= 0; //MII_val(0, DUPLEX_HALF);
        }
    }/* ! auto nego */
    //loc_2347d290
    /* write settings */
    retval = fm3WritePhy( /*FM3HDL*/Data_234dd90c[r7].phyAddress, 0/*MII_addr(0)*/, phy_register_value );
    if ( retval != 0/*FAPI_OK*/ )
    {
        return retval;
    }

    if ( /*FM3HDL*/Data_234dd90c[r7].pStat->loop == 2/*FAPI_ETH_LOOP_ON_PHY*/ )
    {
        return 0; //FAPI_OK;
    }

    /* wait for linkup */
    while ( linkup_timeout > (uint32_t)0 )
    {
    	//loc_2347d2c4
        --linkup_timeout;
        if ( fm3CheckMiiDevLink( r7 ) == 1/*FAPI_ETH_LINKUP*/ )
            break;
        rtos_task_wait/*FAPI_SYS_SLEEP*/( 1 ); /*sleep 1msec*/
    }
    if ( linkup_timeout > 0 )
    {/* update status information */
        /*FM3HDL*/Data_234dd90c[r7].pStat->linkup = 1; //FAPI_ETH_LINKUP;
        retval = fm3UpdateStatusMiiDevice( r7 );
    }/* update status information */
    else
    {/* PHY is not busy. but timeout */
#if 0
        FAPI_SYS_PRINT_DEBUG( FAPI_ETH_WARN, PHY_TIMEOUT_MSG, __FUNCTION__ );
#endif
        retval = -113; //FAPI_ETH_ERR_LINKDOWN;
    }

    return retval;
#endif
}


/* 2347d314 - todo */
void fm3CheckPhyLink(int r5)
{
#if 0
	console_send_string("fm3CheckPhyLink (todo.c): TODO\r\n");
#endif

#if 1
    /*FAPI_ETH_LinkEnumT*/int old_link;
    uint32_t           mcr;
    int32_t            retval;

    if ( /*FM3HDL*/Data_234dd90c[r5].pStat->loop == 1/*FAPI_ETH_LOOP_ON_MAC*/ )
    {
        /*FM3HDL*/Data_234dd90c[r5].pStat->linkup = 0/*FAPI_ETH_LINKDOWN*/;
    }
    else if ( /*FM3HDL*/Data_234dd90c[r5].phyPort == 1/*FMAC3H_PORT_MII*/ )
    {
        old_link = /*FM3HDL*/Data_234dd90c[r5].pStat->linkup;
        /*FM3HDL*/Data_234dd90c[r5].pStat->linkup = fm3CheckMiiDevLink( r5 );
        if ( (old_link != 1/*FAPI_ETH_LINKUP*/) && (/*FM3HDL*/Data_234dd90c[r5].pStat->linkup == 1/*FAPI_ETH_LINKUP*/) )
        {
            /*retval =*/ fm3UpdateStatusMiiDevice( r5 );
#if 0
            if ( retval != FAPI_OK)
            { /* nothing */; }
#endif
        }
        if ( /*FM3HDL*/Data_234dd90c[r5].user_speed == 0/*FAPI_ETH_SPEED_AUTO*/ ) {
            mcr = FREG(0xe4000000)[0]; //FREG_ETH_GetMcr();
            if ( /*FM3HDL*/Data_234dd90c[r5].pStat->duplex == 1/*FAPI_ETH_FULL_DUPLEX*/ )
            {
                mcr |= 0x800/*FMAC3H_REG_val(MCR, FULL_DPLX)*/;
            }
            else/* (FM3HDL.pStat->duplex == FAPI_ETH_HALF_DUPLEX) */
            {
                mcr &= ~0x800/*(FMAC3H_REG_val(MCR, FULL_DPLX))*/;
            }
            FREG(0xe4000000)[0] = mcr; //FREG_ETH_SetMcr( mcr );
        }
    }
#if 0
    else if ( /*FM3HDL*/Data_234dd90c[r5].phyPort == FMAC3H_PORT_GMII )
    {
        /*FM3HDL*/Data_234dd90c[r5].pStat->linkup = FAPI_ETH_LINKUNKNOWN;
    }
#endif
    else
    {
        /*FM3HDL*/Data_234dd90c[r5].pStat->linkup = 2; //FAPI_ETH_LINKUNKNOWN;
    }
#endif
}


/* 2347d3b4 - todo */
static int fm3ConvertMacAddress(int a, int high)
{
#if 0
	console_send_string("fm3ConvertMacAddress (todo.c): TODO\r\n");
#endif

    uint32_t mar  = (uint32_t) 0;

    int ip = 0;
    int r2;
    if (high == 1)
    {
    	ip = 8;
    	r2 = 12;
    	mar = FMAC3H_REG_val(MARH, EN) & 0xFFFF0000; // 0x80000000;
    }
    else
    {
    	r2 = 8;
    }

    fmac3hHandle* h = &Data_234dd90c[a];

    for (uint32_t r1 = 0; r1 < (r2 - ip); r1++)
    {
    	int r2;
    	uint8_t r3 = h->pAddr[ip + r1];
    	if (r3 < 0x3a)
    	{
    		r2 = 0x30;
    	}
    	else if (r3 < 0x47)
    	{
    		r2 = 0x37;
    	}
    	else
    	{
    		r2 = 0x57;
    	}

    	r3 = (r3 - r2) & 0x0f;
    	if ((r1 & 1) == 0)
    	{
    		r2 = r1 + 1;
    	}
    	else
    	{
    		r2 = r1 - 1;
    	}

    	mar |= (r3 << (r2 << 2));
    }

#if 0
    {
		extern char debug_string[];
		sprintf(debug_string, "fm3ConvertMacAddress: mar=0x%x\r\n", mar);
		console_send_string(debug_string);
    }
#endif

    return mar;
}


static int32_t fm3StartPhy(int r8)
{
    int32_t retval = 0xff; //FAPI_ETH_ERR_NODEV;

    if ( Data_234dd90c[r8].pStat->loop == 1/*FAPI_ETH_LOOP_ON_MAC*/ )
    {
        retval = 0; //FAPI_OK;
    }
    else if ( Data_234dd90c[r8].phyPort == 1/*FMAC3H_PORT_MII*/ )
    {
        retval = fm3StartMiiDevice( r8 );
    }
#if 0
    else if ( Data_234dd90c[r8].phyPort == FMAC3H_PORT_GMII )
    {
        retval = FAPI_ETH_ERR_FEATURE_NOT_SUPPORTED;
    }
    else
    {}
#endif

    return retval;
}


/* 2347d444 - todo */
static int fm3InitDevice(uint32_t r8)
{
#if 0
	console_send_string("fm3InitDevice (todo.c): TODO\r\n");
#endif

    int32_t  retval;
    uint32_t bmr;
#if 1//FIX_TX_OWN
    uint32_t omr = 0;
#endif /* FIX_TX_OWN */
    uint32_t ii;

    /* reset fmac3h */
    //FREG_ETH_SetBmr( FMAC3H_REG_val(BMR, SW_RST) );
    FREG(0xe4001000)[0] = 1;
    for ( ii = 0; ii < 1000/*FMAC3H_PHY_SRST_TIMEOUT*/; ii++ )
    {
        /*FAPI_SYS_SLEEP*/rtos_task_wait( 1 ); /* sleep 1msec */
        /* check reset is done */
        if ( (/*FREG_ETH_GetBmr()*/FREG(0xe4001000)[0] & 1/*FMAC3H_REG_val(BMR, SW_RST)*/)
                != 1/*FMAC3H_REG_val(BMR, SW_RST)*/ )
        {
            break;
        }
    }
    if ( ii == 1000/*FMAC3H_SRST_TIMEOUT*/ )
    {
        //FAPI_SYS_PRINT_DEBUG( FAPI_ETH_ERR, FMAC3H_RESET_MSG, __FUNCTION__ );
        return 0xff; //FAPI_ETH_ERR_TIMEOUT;
    }

#if 0
#if FIX_TX_OWN
    bmr = FMAC3H_REG_val(BMR, DMA_1B);
#else
    /* set BMR (Bus Access settings) */
    bmr = FMAC3H_REG_val(BMR, DMA_32B);
#endif /* FIX_TX_OWN */
    FREG_ETH_SetBmr(bmr);
#else
    FREG(0xe4001000)[0] = 0x100;
#endif

    /* set IER (Interrupt settings) */
    /* ERE(ERI), ETE(ETI) is not set */
#if 0
    FREG_ETH_SetIer(FMAC3H_REG_msk(IER, NI) |
                    FMAC3H_REG_msk(IER, AI) |
                    FMAC3H_REG_msk(IER, FBE)|
                    FMAC3H_REG_msk(IER, RW) |
                    FMAC3H_REG_msk(IER, RS) |
                    FMAC3H_REG_msk(IER, RU) |
                    FMAC3H_REG_msk(IER, RI) |
                    FMAC3H_REG_msk(IER, UN) |
                    FMAC3H_REG_msk(IER, OVF)|
                    FMAC3H_REG_msk(IER, TJ) |
                    FMAC3H_REG_msk(IER, TU) |
                    FMAC3H_REG_msk(IER, TS) |
                    FMAC3H_REG_msk(IER, TI) );
#else
    FREG(0xe400101c)[0] = 0x1a3ff;
#endif

#if FIX_INIT
    /* Start phy */
    /* Duplex mode may be changed due to auto-negotiation. */
    /* So don't move this function after SetMcr() */
    retval = fm3StartPhy(  );

    /* set MCR (Configuration resister)*/
    FREG_ETH_SetMcr( fm3SetupMCR(  ) );
#else
#if 0
    retval = 0xff;
    if (Data_234dd90c[r8].pStat->loop == 1)
    {
    	retval = 0;
    }
    else
    {
    	//0x2347d4c4
    	if (Data_234dd90c[r8].phyPort == 1)
    	{
    		retval = fm3StartMiiDevice(r8);
    	}
    }
#else
    retval = fm3StartPhy(r8);
#endif
    //loc_2347d4d4
    FREG(0xe4000000/*FREG_ETH_MCR*/)[0] = fm3SetupMCR(r8);
#endif /* FIX_INIT */

    /* set RDLAR (Receive Descriptor base address) */
#if 0
    FREG_ETH_SetRdlar( (uint32_t)(FM3HDL.descPtrRx) );
#else
    FREG(0xe400100c/*FREG_ETH_RDLAR*/)[0] = (uint32_t)(Data_234dd90c[r8].descPtrRx);
#endif
    /* set TDLAR(descriptor base) current desc */
#if 0
    FREG_ETH_SetTdlar( (uint32_t)(&(FM3HDL.descPtrTx->desc)) );
#else
    FREG(0xe4001010/*FREG_ETH_TDLAR*/)[0] = (uint32_t)&(Data_234dd90c[r8].descPtrTx->desc);
#endif
    /* set MFFR (Address Filtering)*/
#if 0
    FREG_ETH_SetMffr( FMAC3H_REG_val(MFFR,RECV_ALL_PR) );
#else
    FREG(0xe4000004/*FREG_ETH_MFFR*/)[0] = 1; //r7
#endif
    /* set MHTRH (Address Filtering)*/
#if 0
    FREG_ETH_SetMhtrh( (uint32_t)0xFFFFFFFF );
#else
    FREG(0xe4000008/*FREG_ETH_MHTRH*/)[0] = 0xFFFFFFFF;
#endif
    /* set MHTRL (Address Filtering)*/
#if 0
    FREG_ETH_SetMhtrl( (uint32_t)0xFFFFFFFF );
#else
    FREG(0xe400000c/*FREG_ETH_MHTRL*/)[0] = 0xFFFFFFFF;
#endif
    /* set MAR0H (MAC Address)*/
#if 0
    FREG_ETH_SetMar0h( fm3ConvertMacAddress( FAPI_ETH_TRUE ) );
#else
    FREG(0xe4000040/*FREG_ETH_MAR0H*/)[0] = fm3ConvertMacAddress(r8, 1);
#endif
    /* set MAR0L (MAC Address)*/
#if 0
    FREG_ETH_SetMar0l( fm3ConvertMacAddress( FAPI_ETH_FALSE ) );
#else
    FREG(0xe4000044/*FREG_ETH_MAR0L*/)[0] = fm3ConvertMacAddress(r8, 0);
#endif
    /* Setup Flow Control Register */
#if 0
    FREG_ETH_SetFcr( (FMAC3H_REG_msk(FCR, RFE) | FMAC3H_REG_msk(FCR, TFE)) );
#else
    FREG(0xe4000018/*FREG_ETH_FCR*/)[0] = 0x06;
#endif

#if 1 //FIX_TX_OWN
    omr |= 0x200000; //FMAC3H_REG_val(OMR, STORE);
#if 0
    FREG_ETH_SetOmr( omr | FREG_ETH_GetOmr() );
#else
    FREG(0xe4001018/*FREG_ETH_OMR*/)[0] = omr | FREG(0xe4001018/*FREG_ETH_OMR*/)[0];
#endif
#endif /* FIX_TX_OWN */

#if 1 //FIX_INIT
#else
    /* Start phy */
    /* Duplex mode may be changed due to auto-negotiation. */
    /* So don't move this function after SetMcr() */
    retval = fm3StartPhy(  );

    /* set MCR (Configuration resister)*/
    FREG_ETH_SetMcr( fm3SetupMCR(  ) );
#endif /* FIX_INIT */

    return retval;
}


/* 2347d5fc - todo */
int fm3NextRData(uint32_t a, uint32_t* descNumPtr/*r8*/)
{
#if 0
	console_send_string("fm3NextRData (todo.c): TODO\r\n");
#endif

    fmac3hDescT*        tmp_desc_ptr;
    fmac3hDescT*        first_desc_ptr;
    fmac3hDescT*        last_desc_ptr;
    uint32_t            new_size;
    uint32_t            new_size_wrapped;
    uint32_t            descNum;
#if 1//FIX_FRAME_DESC_NUM
    uint32_t            curFrameDescNum;
#endif /* FIX_FRAME_DESC_NUM */
    uint32_t            loop_flag;
    /*fmac3hDescStatEnumT*/int desc_stat = 0; //FMAC3H_FRAME_NOTEND;

    /* Parameter check omitted, as the only caller already checks valid */
	if (descNumPtr == 0)
	{
		return -104;
	}


    /* In case of reaching to the end of ring buffer */
    if ( /*FM3HDL.*/Data_234dd90c[a].rSizeWrap != 0 )
    {
        /*FM3HDL*/Data_234dd90c[a].descPtrRead = &(/*FM3HDL*/Data_234dd90c[a].rDesc[/*DESC_HEAD*/0]);
        new_size = /*FM3HDL*/Data_234dd90c[a].rSizeWrap;
        /*FM3HDL*/Data_234dd90c[a].rSizeWrap = 0;
        *descNumPtr = (((uint32_t)(&/*FM3HDL*/Data_234dd90c[a].rDesc[/*DESC_TAIL*//*FM3HDL*/Data_234dd90c[a].rDescNum-1]) -
                (uint32_t)/*FM3HDL*/Data_234dd90c[a].descPtrRead) / /*FM3HDL*/Data_234dd90c[a].a_rBufSize) + 1;

        return (int32_t)new_size;
    }
    //loc_2347d660
    /* In other cases */
    *descNumPtr = 0;
    first_desc_ptr = 0; //NULL;
    last_desc_ptr = 0; //NULL;
    descNum = 0;
    new_size = 0;
    new_size_wrapped = 0;
    tmp_desc_ptr = /*FM3HDL*/Data_234dd90c[a].descPtrRead;
    /*lint -e{716} */
    while (1)
    {
        /*
         * rDesc_first:
         */
        /* 1. Looking for the first descriptor of frame */
        loop_flag = 0;
        while (1)
        {
            if ( fm3IsOwnDesc( tmp_desc_ptr ) )
            {
                loop_flag = 1; /* goto rDesc_not_found */
                break;
            }

            if ( !fm3IsFSRDesc( tmp_desc_ptr ) )
            {
                /*FM3HDL*/Data_234dd90c[a].daCnt++;
                /* Skip error descriptor */
                desc_stat = fm3DescStat( a, 1/*FMAC3H_R*/, tmp_desc_ptr );
                if ( ((uint32_t)desc_stat & (uint32_t)2/*FMAC3H_FRAME_TERM*/) != 0 ) {
                    fm3HandleRxErr( a, tmp_desc_ptr );
                }
                /* Try to check a next descriptor */
                tmp_desc_ptr = fm3NextRDesc( a, tmp_desc_ptr );
                (*descNumPtr)++;
                if ( ++descNum == /*FM3HDL*/Data_234dd90c[a].rDescNum )
                {
                    loop_flag = 1; /* goto rDesc_not_found */
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if ( loop_flag == 1 )      /* goto rDesc_not_found */
            break;
        first_desc_ptr = tmp_desc_ptr;

        /* 2. Looking for the last descriptor of frame */
#if 1 //FIX_FRAME_DESC_NUM
        curFrameDescNum = 0;
#endif /* FIX_FRAME_DESC_NUM */
        loop_flag = 0;
        while (1)
        {
            if ( fm3IsOwnDesc( tmp_desc_ptr ) )
            {
                loop_flag = 1; /* goto rDesc_not_found */
                break;
            }
            /*FM3HDL*/Data_234dd90c[a].daCnt++;
            /* Skip error descriptor */
            desc_stat = fm3DescStat( a, 1/*FMAC3H_R*/, tmp_desc_ptr );
            if ( ((uint32_t)desc_stat & (uint32_t)2/*FMAC3H_FRAME_TERM*/) != 0 )
            {
                fm3HandleRxErr( a, tmp_desc_ptr );

                tmp_desc_ptr = fm3NextRDesc( a, tmp_desc_ptr );
                (*descNumPtr)++;
                if ( ++descNum == /*FM3HDL*/Data_234dd90c[a].rDescNum )
                {
                    loop_flag = 1; /* goto rDesc_not_found */
                    break;
                }
                else
                {
                    /* Look for a new first descriptor again */
                    first_desc_ptr = 0; //NULL;
                    new_size = 0;
                    new_size_wrapped = 0;
                    loop_flag = 2; /* goto rDesc_first */
                    break;
                }
            }

            /* Here we have a valid descriptor. */
            /* Calculate a new readable size    */
            if ( (tmp_desc_ptr == &(/*FM3HDL*/Data_234dd90c[a].rDesc[/*DESC_HEAD*/0])) &&
                    (tmp_desc_ptr != first_desc_ptr) )    /* (a)first one after wrapped */
                new_size_wrapped = fm3RDescDatSize( a, tmp_desc_ptr );
            else if ( new_size_wrapped == 0 )          /* (b)normal case */
                new_size += fm3RDescDatSize( a, tmp_desc_ptr );
            else                                       /* (c)second and later after wrapped */
                new_size_wrapped += fm3RDescDatSize( a, tmp_desc_ptr );

            /* 3. Try to check a next descriptor until reaching the last one */
            if ( !fm3IsLSRDesc( tmp_desc_ptr ) )
            {
                tmp_desc_ptr = fm3NextRDesc( a, tmp_desc_ptr );
#if 1 //FIX_FRAME_DESC_NUM
                curFrameDescNum++;
#else
                ++(*descNumPtr);
#endif /* FIX_FRAME_DESC_NUM */
                if ( ++descNum == /*FM3HDL*/Data_234dd90c[a].rDescNum )
                {
                    /* Frame was partially received */
                    first_desc_ptr = 0; //NULL;
                    new_size = 0;
                    new_size_wrapped = 0;
#if 1 //FIX_FRAME_DESC_NUM
                    (*descNumPtr) += curFrameDescNum;
#endif /* FIX_FRAME_DESC_NUM */
                    loop_flag = 1; /* goto rDesc_not_found */
                    break;
                }
            }
            else
            {   /* Next data found, and repeat 2. */
                last_desc_ptr = tmp_desc_ptr;
                break;
            }
        }
        if ( loop_flag == 1 )      /* goto rDesc_not_found */
        {
            break;
        }
        else if ( loop_flag == 2 ) /* goto rDesc_first */
        {
            continue;
        }

        if ( last_desc_ptr )       /* Next data found */
        {
            break;
        }
    }
/*
 * rDesc_not_found:
 * rDesc_found:
 */
    if ( first_desc_ptr == 0/*NULL*/ )                /* Valid descriptor not found */
    {
        /*FM3HDL*/Data_234dd90c[a].descPtrRead = tmp_desc_ptr;
        new_size = 0; /* just for safety */
        /*FM3HDL*/Data_234dd90c[a].rSizeWrap = 0;
    }
    else
    {
        /*FM3HDL*/Data_234dd90c[a].descPtrRead = first_desc_ptr;
        if ( new_size_wrapped != 0 )             /* Found, but frame is wrapped */
        {
            /*FM3HDL*/Data_234dd90c[a].rSizeWrap = new_size_wrapped;
        }
        else                                     /* Normal case */
        {
            /*FM3HDL*/Data_234dd90c[a].rSizeWrap = 0;
        }
    }

    return (int32_t)new_size;
}


static void fm3FixSettings(eth_stat_params* pStat)
{
    if ( pStat->loop == 1/*FAPI_ETH_LOOP_ON_MAC*/ )
    {
        /* None */
    }
    if ( (pStat->loop != 0/*FAPI_ETH_LOOP_OFF*/) &&
         (pStat->speed == 0/*FAPI_ETH_SPEED_AUTO*/) )
    {
        /* auto negotiation is not performed in
           loopback mode. set default value */
        pStat->speed = 100; //FAPI_ETH_SPEED_100M;
        pStat->duplex = 1; //FAPI_ETH_FULL_DUPLEX;
    }
}


 /* 2347d910 - todo */
int eth_fm3_start(int r5, eth_stat_params* settings, eth_drv_data* datArea, int macAddr)
{
	int res;

#if 1
	console_send_string("eth_fm3_start (todo.c): TODO\r\n");
#endif

	if (r5 != 0)
	{
		return 0xff;
	}

	if ((settings == 0) || (datArea == 0) || (macAddr == 0) ||
			(datArea->rSize == 0) ||
			(datArea->rPtr == 0) ||
			(datArea->wSize == 0) ||
			(datArea->wPtr == 0))
	{
#if 0
		console_send_string("eth_fm3_start: err1\r\n");
#endif
		return -110;
	}

	if ((settings->speed != 0) &&
			(settings->speed != 10) &&
			(settings->speed != 100))
	{
#if 0
		console_send_string("eth_fm3_start: err2\r\n");
#endif
		return 0xff;
	}

	if ((settings->duplex != 0) && (settings->duplex != 1))
	{
#if 0
		console_send_string("eth_fm3_start: err3\r\n");
#endif
		return 0xff;
	}

	if ((settings->loop != 0) &&
			(settings->loop != 1) &&
			(settings->loop != 2))
	{
#if 0
		console_send_string("eth_fm3_start: err4\r\n");
#endif
		return 0xff;
	}
	//loc_2347d990
	int r6 = 0;

	Data_234dd90c[r6].pStat = settings;
	Data_234dd90c[r6].user_speed = settings->speed;

#if 0
	if (settings->loop != 0)
	{
		//0x2347d9b4
		if (settings->speed == 0)
		{
			settings->speed = 100;
			settings->duplex = 1;
		}
	}
#else
	fm3FixSettings(Data_234dd90c[r6].pStat);
#endif

	//loc_2347d9cc
	Data_234dd90c[r6].pAddr = (void*) macAddr;

	Data_234dd90c[r6].pData = datArea;
	Data_234dd90c[r6].rBufSize = Data_234dd90c[r6].pData->rSize; //datArea->rSize;
	Data_234dd90c[r6].rBufStart = Data_234dd90c[r6].pData->rPtr; //datArea->rPtr;
	Data_234dd90c[r6].wBufSize = Data_234dd90c[r6].pData->wSize; //datArea->wSize;
	Data_234dd90c[r6].wBufStart = Data_234dd90c[r6].pData->wPtr; //datArea->wPtr;

	Data_234dd90c[r6].pData->rSize/*datArea->rSize*/ = 0; //r6;
	Data_234dd90c[r6].wSizeWrap = 0;
	Data_234dd90c[r6].wSizeHidden = 0;

	fm3InitRDescs(r6);
	fm3Init1stWDesc(r6);

	Data_234dd90c[r6].stopFlagR = 0x800; //FMAC3H_RX_STOP
	Data_234dd90c[r6].stopFlagT = 0x800000; //FMAC3H_TX_STOP

	res = fm3InitDevice(r6);
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "fm3InitDevice returned res=%d\r\n", res);
		console_send_string(debug_string);
	}
#endif
	if ((res == 0) || (res == -113))
	{
		//0x2347da38
		res = fm3StartDevice(r5, 1);
		if (res != 0)
		{
			if (0 != sub_2347d548(r5))
			{
				res = -112;
			}
		}
		//loc_2347da5c
	}
	//loc_2347da5c
	return res;
}


/* 2347da64 - todo */
void sub_2347da64()
{
	console_send_string("sub_2347da64 (todo.c): TODO\r\n");

}


/* 2347da8c - todo */
int fapi_eth_fm3_rUpdate(uint32_t sl, int read/*r6*/, int* frame/*r8*/)
{
#if 0
	console_send_string("fapi_eth_fm3_rUpdate (todo.c): TODO\r\n");
#endif

    fmac3hDescT* old_desc_ptr/*sp_0xc*/ = /*FM3HDL*/Data_234dd90c[sl].descPtrRead;
    int/*fmac3hDescStatEnumT*/ desc_stat = 0; //FMAC3H_FRAME_NOTEND;
    int32_t      new_size = 0;
    uint32_t     free_desc_num = 0;
    uint32_t     free_desc_num_old;
    uint32_t     read_base = 0;
    uint32_t     ii;
    uint32_t     irq_flags = 0;
    int32_t      retval = 0; //FAPI_OK;
	int sp;

    if (sl > 0)
    {
    	return -100;
    }

    if ( (read < 0) || ((uint32_t)read > /*FM3HDL*/Data_234dd90c[sl].pData->rSize) ) {
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "eth_read: read=%d, rSize=%d\r\n",
					read, Data_234dd90c[sl].pData->rSize);
			console_send_string(debug_string);
		}
#endif
    }

#if 1
    if (read == 0)
    {
    	frame = &sp;
    }
#endif

    if (frame == 0)
    {
    	return -104;
    }

    *frame = 0;

    /*
     * Receive buffers are configured as an array (Ring).
     * Descriptors and Data buffers are separately allocated.
     *
     *               Descriptors           Buffer           After rUpdate()
     *              +-----------+         |        |
     *              |           |         |        |
     *              +-----------+   +---->+--------+
     *              |           |   |     |        |
     * descPtrRead->+-----------+   |     |        |
     *              |0   FS   ------+     |        | <-rPtr  -----
     *              +-----------+         |        |    |      |
     *              |0   LS   ----------->+--------+    |     read
     *              +-----------+         |        |    |      |
     *              |           |         |        |   rSize ------<- new rPtr
     *              +-----------+         |        |    |      |
     *              |           |         |        |    v     new rSize
     *              +-----------+         +--------+   ---   ------
     *              |           |         |        |
     *              +-----------+             ...
     */

    /* 1-1. Calculate a tentative new rSize(new_size) and
     *      a number of descriptors to be freed
     */
    //loc_2347daf8
    if ( read > 0 )
    {
        new_size  = (int32_t)/*FM3HDL*/Data_234dd90c[sl].pData->rSize - read;
        read_base = (uint32_t)/*FM3HDL*/Data_234dd90c[sl].pData->rPtr - /*FM3HDL*/Data_234dd90c[sl].descPtrRead->des2;
        /* calculate number of descs to be freed */
        free_desc_num = (read_base + (uint32_t)read) / /*FM3HDL*/Data_234dd90c[sl].a_rBufSize;
        /* update descPtrRead */
        for ( ii = 0; ii < free_desc_num; ii++ )
        {
            /*FM3HDL*/Data_234dd90c[sl].descPtrRead = fm3NextRDesc(sl, /*FM3HDL*/Data_234dd90c[sl].descPtrRead);
        }
        if ( ((read_base + (uint32_t)read) % /*FM3HDL*/Data_234dd90c[sl].a_rBufSize) == 0 )
        {/* rPtr is on end of buffer of desc */
            desc_stat = fm3DescStat( sl, 1/*FMAC3H_R*/,
            (fmac3hDescT*)fm3PrevRDesc( sl, /*FM3HDL*/Data_234dd90c[sl].descPtrRead ) );
        }
        else
        {/* rPtr is on middle of buffer of desc */
            desc_stat = fm3DescStat( sl, 1/*FMAC3H_R*/, /*FM3HDL*/Data_234dd90c[sl].descPtrRead );
            if ( desc_stat == 2/*FMAC3H_FRAME_TERM*/ )
            {
                new_size = 0;
            }
            else if ( desc_stat == 1/*FMAC3H_FRAME_END*/ )
            {
                if ( new_size != 0 )
                {
                    desc_stat = 0/*FMAC3H_FRAME_NOTEND*/;
                }
            }else{/*FMAC3H_FRAME_NOTEND*/}

            if ( new_size == 0 )
            {/* current frame ended. step next desc. */
                free_desc_num++;
                /*FM3HDL*/Data_234dd90c[sl].descPtrRead
                 = fm3NextRDesc( sl, /*FM3HDL*/Data_234dd90c[sl].descPtrRead );
            }
        }/* rPtr is on middle of buffer of desc */
    }

#if PROF_PRINT_fapi_eth_fm3_rUpdate
    PROF_TS_SET(2);
#endif

    /* 1-2. Update rPtr and rSize */
    if ( new_size == 0 )
    {
        /* search next readable data */
        free_desc_num_old = free_desc_num;
        new_size = fm3NextRData( sl, &free_desc_num );
        free_desc_num += free_desc_num_old;
        if ( (new_size > 0) || (free_desc_num > 0) )
        {
            /* rPtr should be on the head of next frame data */
            /*FM3HDL*/Data_234dd90c[sl].pData->rPtr
             = (/*char_t*/uint8_t*)(/*FM3HDL*/Data_234dd90c[sl].descPtrRead->des2);
        } else
        {
            /* fm3NextRData() may return a negative. */
            new_size = 0;
        }
        if ( (desc_stat == 0/*FMAC3H_FRAME_NOTEND*/) && (read > 0) &&
             (free_desc_num_old != free_desc_num) )
        {
            desc_stat = 2/*FMAC3H_FRAME_TERM*/;
        }
    }
    else
    {
        /*FM3HDL*/Data_234dd90c[sl].pData->rPtr += read;
    }
    /*FM3HDL*/Data_234dd90c[sl].pData->rSize = (uint32_t)new_size;

#if PROF_PRINT_fapi_eth_fm3_rUpdate
    PROF_TS_SET(3);
#endif

    /* 2. Free descriptors from old descPtrRead
     *    If necessary, disable interrupts.
     */
    if ( free_desc_num == 0 )
    {
        /* None */
    }
    else if ( (free_desc_num > 0) &&
            (free_desc_num < /*FM3HDL*/Data_234dd90c[sl].rDescNum) )
    {
        fm3FreeRDescs( sl, old_desc_ptr,
                       fm3PrevRDesc( sl, /*FM3HDL*/Data_234dd90c[sl].descPtrRead) );
    }
    else if( free_desc_num == /*FM3HDL*/Data_234dd90c[sl].rDescNum )
    {
        fm3FreeRDescs( sl, &(/*FM3HDL*/Data_234dd90c[sl].rDesc[0]),
                      &(/*FM3HDL*/Data_234dd90c[sl].rDesc[/*DESC_TAIL*/Data_234dd90c[sl].rDescNum-1]) );
    }
    else/* free_desc_num > FM3HDL.rDescNum */
    {
        /* error case */
        fm3SWError( sl, "fm3NextRData()" /* __FUNCTION__ */ , "# of free descs is big" );
    }

#if PROF_PRINT_fapi_eth_fm3_rUpdate
    PROF_TS_SET(4);
#endif

    /* 3. Restart receive process of FMAC3H
     * If necessary, disable interrupts.
     */
    if ( (free_desc_num > 0) &&
            (((uint32_t)/*FM3HDL*/Data_234dd90c[sl].stopFlagR & (uint32_t)0x00000200UL/*FMAC3H_RX_SUSP_NOBUF*/)
          != 0) )
    {
        /* irq mask */
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
        OS_CPU_SR  cpu_sr = 0u;
#endif
        OS_ENTER_CRITICAL();

        retval = fm3StartDevice( sl, 1/*FMAC3H_R*/ );

        /* irq un-mask */
        OS_EXIT_CRITICAL();
    }

#if PROF_PRINT_fapi_eth_fm3_rUpdate
    PROF_TS_SET(5);
#endif

    /* 4. Translate frame status */
    if ( desc_stat == 1/*FMAC3H_FRAME_END*/ ) {
        *frame = 1; //FAPI_ETH_FRAME_END;
    }
    else if ( desc_stat == 2/*FMAC3H_FRAME_TERM*/ ) {
        *frame = 2; //FAPI_ETH_FRAME_TERM;
    }

    return retval;
}

#if 1

#define MIN_SIZE_OF_WRITE         (32)

/* 2347ddac - todo */
int fapi_eth_fm3_wUpdate(uint32_t sb, int32_t written, /*FAPI_ETH_FrameEndEnumT*/int frame)
{
#if 0
	console_send_string("fapi_eth_fm3_wUpdate (todo.c): TODO\r\n");
#endif

    /*char_t*/uint8_t*        new_w_ptr;
    int32_t        new_w_siz;
    uint32_t       irq_masked = 0;//FAPI_ETH_FALSE;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
    uint32_t       valid_written;
    uint32_t       data_size_in_desc;
    uint32_t       data_size_in_frame;
    uint32_t       wrapped = 0; //FAPI_ETH_FALSE;
    fmac3hDescTxT* new_desc_ptr = 0; //NULL;
    /*FAPI_ETH_FrameEndEnumT*/int flush_order = frame;

    if (sb > 0)
    {
    	return -100;
    }

    if ( (written < 0) || ((uint32_t)written > /*FM3HDL*/Data_234dd90c[sb].pData->wSize) )
    {
        return 0xff; //FAPI_ETH_ERR_BAD_PARAMETER;
    }
    valid_written      = (uint32_t)written;
    data_size_in_desc  = (uint32_t)written;
    data_size_in_frame = (uint32_t)written;

    if ( (frame != 1/*FAPI_ETH_FRAME_END*/) && (frame != 0/*FAPI_ETH_FRAME_NOTEND*/) )
    {
        return 0xff; //FAPI_ETH_ERR_BAD_PARAMETER;
    }

    /*
     * 1.Intentionally flushed by upper layer
     */
    if ( (written == 0) && (flush_order == 1/*FAPI_ETH_FRAME_END*/) )
    {
        fm3DiscardWFrame( sb );
        return 0;
    }

    /*
     * 2. Calculate size of current frame, and
     *    get data size of the current descriptor
     */
    /*
     * Transmit buffers are configured as a linked list (Chain).
     * Descriptors and data buffers are allocated in consequence
     * in the same space. So one empty descriptor will be created
     * once the current frame is to be sent.
     *
     *                          TX Buffer
     *                              ...
     *                        |              |
     *------                  +--------------+ <--First Descriptor
     *   |                    |              |
     *   |                    |          *-------+
     *   |                    |              |   |
     *   |                    +--------------+ <-+
     *   |                    |              |
     *   |                    | (data buffer)|
     * data_size_in_frame           ...
     *   |                    |              |
     *   |                    |              |
     *   |                    +--------------+ <--Current Descriptor
     *   |                    |              |     (FM3HDL.descPtrWrite)
     *   |                    |          *-------+
     *   |                    |              |   |
     *   |    ------          +--------------+ <-+
     *   |      |             |              |
     *   |  data_size_in_desc | (data buffer)| <--FM3HDL.wPtr
     *   |      |             |              |        |
     *   |      |             |              |      written
     *   V      V             |              |        V
     * -----  ------          |              | -----------
     *                              ...
     */

    data_size_in_frame += fm3WFrameSize( sb );
    /* check frame size */
    if ( data_size_in_frame > /*FM3HDL*/Data_234dd90c[sb].txFrameSizeMax )
    {
    	//0x2347de64
        fm3DiscardWFrame( sb );
        return -106; //FAPI_ETH_ERR_TOO_BIG_FRAME;
    }
    else if ( (data_size_in_frame < /*FM3HDL*/Data_234dd90c[sb].txFrameSizeMin) &&
            (flush_order == 1/*FAPI_ETH_FRAME_END*/) )
    {
        fm3DiscardWFrame( sb );
        return -107; //FAPI_ETH_ERR_TOO_SHORT_FRAME;
    }
    //loc_2347de98
    data_size_in_desc +=
        (int32_t)FMAC3H_DESC_get(1, BS1, /*FM3HDL*/Data_234dd90c[sb].descPtrWrite->desc.des1);
    /* check the data exceeded the max size of a descriptor payload */
    if ( data_size_in_desc > /*FM3HDL*/Data_234dd90c[sb].buf_size_limit )
    {
        return -1; //FAPI_ETH_ERR_BAD_PARAMETER;
    }
    //loc_2347dec0
    /*
     *    Disable interrupt if necessary because
     *    wSize may be changed by interrupt handler.
     */
    if ( ((uint32_t)/*FM3HDL*/Data_234dd90c[sb].stopFlagT & (uint32_t)0x100000/*FMAC3H_TX_RUN*/) != 0 )
    {
        /* mask irq */
        OS_ENTER_CRITICAL();
        irq_masked = 1; //FAPI_ETH_TRUE;
    }
    //loc_2347ded8
    new_w_ptr = /*FM3HDL*/Data_234dd90c[sb].pData->wPtr;
    new_w_siz = (int32_t)/*FM3HDL*/Data_234dd90c[sb].pData->wSize;

    /* get new buffer information */
    new_w_ptr += valid_written;
    new_w_siz -= (int32_t)valid_written;

    /* update descriptor data size */
    FMAC3H_DESC_set(1, BS1, /*FM3HDL*/Data_234dd90c[sb].descPtrWrite->desc.des1,
                    (uint32_t)data_size_in_desc);
    /*FM3HDL*/Data_234dd90c[sb].descPtrWrite->areaSiz += valid_written;

    /*
     * 3. Check and create a new descriptor if necessary
     */
    if ( (flush_order == 1/*FAPI_ETH_FRAME_END*/)         ||  /* flush order ? */
            (new_w_ptr == /*WBUFEND*/(/*FM3HDL*/Data_234dd90c[sb].wBufStart + /*FM3HDL*/Data_234dd90c[sb].wBufSize))                      ||  /* reaches buffer tail? */
            (data_size_in_desc == /*FM3HDL*/Data_234dd90c[sb].buf_size_limit) )   /* reaches one descriptor size max? */
    {
        uint32_t truncated
        = (((uint32_t)new_w_ptr + (uint32_t)0x1F) & ~((uint32_t)0x1F))
        - (uint32_t)new_w_ptr;
        uint32_t alloc_size = truncated + sizeof(fmac3hDescTxT);

        /* allocation process */
        if ( data_size_in_desc == 0 )
        {
            new_desc_ptr = /*FM3HDL*/Data_234dd90c[sb].descPtrWrite;
        }
        else if ( (new_w_siz > (int32_t)alloc_size)           ||
                ((/*FM3HDL*/Data_234dd90c[sb].wSizeHidden >= 0) &&
                ((new_w_siz + /*FM3HDL*/Data_234dd90c[sb].wSizeHidden) > (int32_t)alloc_size)) )
        {
            new_desc_ptr = (fmac3hDescTxT*)
                           ((uint32_t)(new_w_ptr + truncated));
            new_w_ptr += alloc_size;
            new_w_siz -= (int32_t)alloc_size;/*may be minus value*/
        }
        else if( /*FM3HDL*/Data_234dd90c[sb].wSizeWrap > (int32_t)sizeof(fmac3hDescTxT) )
        {
            wrapped = 1; //FAPI_ETH_TRUE;
            truncated = (uint32_t)/*WBUFEND*/(/*FM3HDL*/Data_234dd90c[sb].wBufStart + /*FM3HDL*/Data_234dd90c[sb].wBufSize) - (uint32_t)new_w_ptr;
            new_desc_ptr = (fmac3hDescTxT*)(uint32_t)((/*FM3HDL*/Data_234dd90c[sb].wBufStart));
            new_w_ptr = &(/*FM3HDL*/Data_234dd90c[sb].wBufStart[sizeof(fmac3hDescTxT)]);
            /* new_w_siz is calculated under irq mask */
        }
        else { /* None */ }

        if ( (new_desc_ptr != 0/*NULL*/) && (new_desc_ptr != /*FM3HDL*/Data_234dd90c[sb].descPtrWrite) )
        {/* allocation succeeded 1 */
            if ( flush_order == 1/*FAPI_ETH_FRAME_END*/ )
            {/* set last desc bit */
                FMAC3H_DESC_set(1, LS, /*FM3HDL*/Data_234dd90c[sb].descPtrWrite->desc.des1, 1);
            }
            /* set next desc addr */
            /*FM3HDL*/Data_234dd90c[sb].descPtrWrite->desc.des3 = (uint32_t)new_desc_ptr;
            /*FM3HDL*/Data_234dd90c[sb].descPtrWrite->areaSiz += truncated;
            /* update old desc */
            if ( fm3IsFSWDesc( &(/*FM3HDL*/Data_234dd90c[sb].descPtrWrite->desc) )
                != 1/*FAPI_ETH_TRUE*/ )
            {
                /* set own bit if it is NOT 1st desc */
            	/*FM3HDL*/Data_234dd90c[sb].descPtrWrite->desc.des0 |= FMAC3H_DESC0_msk_OWN;
            }

            /* initialize new desc */
            new_desc_ptr->desc.des0 = (uint32_t)0;
            new_desc_ptr->desc.des1 = (uint32_t)0;
            if ( flush_order == 1/*FAPI_ETH_FRAME_END*/ )
            {/* set 1st desc bit */
                FMAC3H_DESC_set(1, FS, new_desc_ptr->desc.des1, 1);
            }
            FMAC3H_DESC_set( 1, IC, new_desc_ptr->desc.des1, 1);
            FMAC3H_DESC_set( 1, CH, new_desc_ptr->desc.des1, 1);
            new_desc_ptr->desc.des2 = (uint32_t)new_w_ptr;
            new_desc_ptr->desc.des3 = (uint32_t)0/*NULL*/;
            new_desc_ptr->prevPtr = /*FM3HDL*/Data_234dd90c[sb].descPtrWrite;
            new_desc_ptr->areaSiz = sizeof(fmac3hDescTxT);
        }/* allocation succeeded */
        else if ( new_desc_ptr == /*FM3HDL*/Data_234dd90c[sb].descPtrWrite )
        {
            fmac3hDescTxT* prev_desc
            = (fmac3hDescTxT*)fm3PrevWDesc( /*FM3HDL*/Data_234dd90c[sb].descPtrWrite );
            FMAC3H_DESC_set(1, FS, /*FM3HDL*/Data_234dd90c[sb].descPtrWrite->desc.des1, 1);
            /* just for safety */
            if (flush_order != 1/*FAPI_ETH_FRAME_END*/) {
                flush_order = 1; //FAPI_ETH_FRAME_END;
            }
            FMAC3H_DESC_set(1, LS, prev_desc->desc.des1, 1);
        }
        else
        {/* allocation failed */
            if ( valid_written < MIN_SIZE_OF_WRITE )
            {
                if ( irq_masked == 1/*FAPI_ETH_TRUE*/ )
                {
                    /* un-mask irq */
                    OS_EXIT_CRITICAL();
                }
                return -108; //FAPI_ETH_ERR_AGAIN;
            }
            valid_written -= MIN_SIZE_OF_WRITE;
            new_w_ptr -= MIN_SIZE_OF_WRITE;
            new_w_siz += MIN_SIZE_OF_WRITE;
            FMAC3H_DESC_set(1, BS1, /*FM3HDL*/Data_234dd90c[sb].descPtrWrite->desc.des1,
                (uint32_t)(data_size_in_desc - MIN_SIZE_OF_WRITE));
            /*FM3HDL*/Data_234dd90c[sb].descPtrWrite->areaSiz -= MIN_SIZE_OF_WRITE;
            if ( flush_order == 1/*FAPI_ETH_FRAME_END*/ )
            {
                flush_order = 0; //FAPI_ETH_FRAME_NOTEND;
            }
        }/* allocation failed */
    }

    /*
     * 4. Update writable data pointer and size.
     */
    /*
     *                  TX Buffer           After wUpdate()
     *                       ...
     *  |             |                |
     *  |             +----------------+ <--FM3HDL.descPtrWrite
     *  |             |0               |
     * buf_size_limit |             *------+
     *  |             |                |   |
     *  |             +----------------+ <-+
     *  |             |   data         |
     *  |             |     filled     |
     *  |             |   ----------   | <--FM3HDL.wPtr
     *  |             |                |        |
     *  |             |   free for     |      FM3HDL.wSize
     *  |             |     current    |        |
     *  V             |     frame      |        V
     * ----------     |   ----------   | ----------------
     * free           |                |        |
     *   for buffering|                |      FM3HDL.wSizeHidden
     *   more frames  |      ...       |        |
     *                |                |        V
     * -------------  +----------------+ <--FM3HDL.descPtrTx
     *   not-yet-sent |1               |
     *   data exists  |      ...       |
     *
     */
    //loc_2347e0c8
    if ( ( valid_written > 0 ) || (flush_order == 1/*FAPI_ETH_FRAME_END*/) )
    {
        /* update write pointer */
    	/*FM3HDL*/Data_234dd90c[sb].pData->wPtr = new_w_ptr;
        /* update write size */
        if ( new_desc_ptr == 0/*NULL*/ )
        {
        	/*FM3HDL*/Data_234dd90c[sb].pData->wSize = (uint32_t)new_w_siz;
            if (new_w_siz < 0)
            {
            	/*FM3HDL*/Data_234dd90c[sb].pData->wSize = 0;
#if 0
                FAPI_SYS_PRINT_DEBUG( FAPI_ETH_ERR,
                        "[ETH] new_w_siz is negative.(%d)\n", new_w_siz );
#endif
            }
        }
        else{
            if ( wrapped == 1/*FAPI_ETH_TRUE*/ )
            {
                /*FM3HDL*/Data_234dd90c[sb].wSizeHidden  = /*FM3HDL*/Data_234dd90c[sb].wSizeWrap;
                /*FM3HDL*/Data_234dd90c[sb].wSizeHidden  -= ((int32_t)sizeof(fmac3hDescTxT));
                /*FM3HDL*/Data_234dd90c[sb].wSizeWrap    = 0; /* moved to wSizeHidden */
                /*FM3HDL*/Data_234dd90c[sb].pData->wSize = 0; /* moved to newDescPtr->areaSiz */
                new_w_siz = 0;
            }
            if ( /*FM3HDL*/Data_234dd90c[sb].wSizeHidden < 0 )
            {
                /*FM3HDL*/Data_234dd90c[sb].wSizeHidden = 0;
            }
            /*FM3HDL*/Data_234dd90c[sb].wSizeHidden += new_w_siz;
            if ( /*FM3HDL*/Data_234dd90c[sb].wSizeHidden > (int32_t)/*FM3HDL*/Data_234dd90c[sb].buf_size_limit )
            {
                /*FM3HDL*/Data_234dd90c[sb].pData->wSize = /*FM3HDL*/Data_234dd90c[sb].buf_size_limit;
            }
            else
            {
                /*FM3HDL*/Data_234dd90c[sb].pData->wSize = (uint32_t)/*FM3HDL*/Data_234dd90c[sb].wSizeHidden;
            }
            /*FM3HDL*/Data_234dd90c[sb].wSizeHidden -= (int32_t)/*FM3HDL*/Data_234dd90c[sb].buf_size_limit;
            if ( ((uint32_t)/*FM3HDL*/Data_234dd90c[sb].pData->wPtr + /*FM3HDL*/Data_234dd90c[sb].pData->wSize)
                    >= (uint32_t)/*WBUFEND*/(/*FM3HDL*/Data_234dd90c[sb].wBufStart + /*FM3HDL*/Data_234dd90c[sb].wBufSize) )
            {
                /*FM3HDL*/Data_234dd90c[sb].wSizeHidden = 0;
            }
        }

        /*
         * 5. Actually send data to the network.
         */
        if ( flush_order == 1/*FAPI_ETH_FRAME_END*/ )
        {
            fmac3hDescTxT* tmp_desc_ptr = /*FM3HDL*/Data_234dd90c[sb].descPtrWrite;
            if ( new_desc_ptr  == /*FM3HDL*/Data_234dd90c[sb].descPtrWrite )
            {
                tmp_desc_ptr
                = (fmac3hDescTxT*)fm3PrevWDesc(/*FM3HDL*/Data_234dd90c[sb].descPtrWrite );
            }
            while ( fm3IsFSWDesc( &(tmp_desc_ptr->desc) )
                    != 1/*FAPI_ETH_TRUE*/ )
            {/* search 1st desc */
                /* do nothing */
                tmp_desc_ptr =
                    (fmac3hDescTxT*)fm3PrevWDesc( tmp_desc_ptr );
            }
            /* set own of 1st desc */
            tmp_desc_ptr->desc.des0 |= FMAC3H_DESC0_msk_OWN;
        }

        if ( (new_desc_ptr != 0/*NULL*/) && (new_desc_ptr != /*FM3HDL*/Data_234dd90c[sb].descPtrWrite) )
        {
            /* update write desc pointer */
        	/*FM3HDL*/Data_234dd90c[sb].descPtrWrite = (fmac3hDescTxT*)
                fm3NextWDesc( &((/*FM3HDL*/Data_234dd90c[sb].descPtrWrite)->desc) );
        }

        if ( irq_masked == 1/*FAPI_ETH_TRUE*/ )
        {
            /* un-mask irq */
        	OS_EXIT_CRITICAL();
        }

        if ( (((uint32_t)/*FM3HDL*/Data_234dd90c[sb].stopFlagT & (uint32_t)0x100000/*FMAC3H_TX_RUN*/) == 0) &&
                (flush_order == 1/*FAPI_ETH_FRAME_END*/) )
        {
            int32_t retval;
            /* irq mask */
            OS_ENTER_CRITICAL();
            retval = fm3StartDevice( sb, 2/*FMAC3H_W*/ );
            /* irq un-mask */
            OS_EXIT_CRITICAL();
            if ( retval != 0/*FAPI_OK*/ )
            {
                /* Not Implemented */
                /* fm3StartDevice() always returns FAPI_OK */
            }
        }
    }
    else
    {
        if ( irq_masked == 1/*FAPI_ETH_TRUE*/ )
        {
            /* un-mask irq */
            OS_EXIT_CRITICAL();
        }
    }

    /* 6. return valid written data size */
    return (int32_t)valid_written;
}

#endif

static void fm3FBEInt(int r7, uint32_t sr)
{
#if 0
    if ( (sr & FMAC3H_REG_msk(SR, EB)) == FMAC3H_REG_val(SR, TX_BUSERR) )
    {/* Transmit */
        FM3HDL.pStat->error
        = (FAPI_ETH_ErrorEnumT)((uint32_t)(FM3HDL.pStat->error) |
                (uint32_t)FAPI_ETH_ERR_TX_BUS);
    }
    else
    {/* Receive */
        FM3HDL.pStat->error
        = (FAPI_ETH_ErrorEnumT)((uint32_t)(FM3HDL.pStat->error) |
                (uint32_t)FAPI_ETH_ERR_RX_BUS);
    }
    FM3HDL.stopFlagT = FMAC3H_FATAL_ERROR;
    FM3HDL.stopFlagR = FMAC3H_FATAL_ERROR;
#else
	if ((sr & 0x1800000) == 0x800000)
	{
		Data_234dd90c[r7].pStat->error |= 4;
	}
	else
	{
		Data_234dd90c[r7].pStat->error |= 2;
	}

	Data_234dd90c[r7].stopFlagT = 1;
	Data_234dd90c[r7].stopFlagR = 1;
#endif
}


/* 2347e230 - todo */
int fapi_eth_fm3_intr(int r7)
{
#if 0
	console_send_string("fapi_eth_fm3_intr (todo.c): TODO\r\n");
#endif

	int retval = 0;
	uint32_t sr;

	if (r7 != 0)
	{
		return retval;
	}
	//loc_2347e248
	sr = FREG(0xe4001014)[0];
	FREG(0xe4001014)[0] = sr;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "fapi_eth_fm3_intr: sr=0x%x\r\n", sr);
		console_send_string(debug_string);
	}
#endif

	if (sr & 0x2000)
	{
		//0x2347e260
#if 0
		if ((sr & 0x1800000) == 0x800000)
		{
			Data_234dd90c[r7].pStat->error |= 4;
		}
		else
		{
			Data_234dd90c[r7].pStat->error |= 2;
		}

		Data_234dd90c[r7].stopFlagT = 1;
		Data_234dd90c[r7].stopFlagR = 1;
#else
		fm3FBEInt(r7, sr);
#endif
	}
	//loc_2347e290
	if (sr & 0x43d0)
	{
		//0x2347e29c
		retval = fm3HandleIntRx(r7);
	}
	//loc_2347e2a8
	if (sr & 0x42f)
	{
		fm3HandleIntTx(r7);
	}

	if (sr & 0x80)
	{
		fm3RUInt(r7);
	}

	if (sr & 0x04)
	{
		//0x2347e2cc
		if (Data_234dd90c[r7].stopFlagT == 0x100000)
		{
			Data_234dd90c[r7].stopFlagT = 0x300000;
		}
	}
	//loc_2347e2e0
	fm3FixStat(r7);
	//loc_2347e240
	return retval;
}


static void fm3SendPause(void)
{
    uint32_t fcr;
    uint32_t timeout;

    for (timeout = 0; timeout < 0x100/*FMAC3H_FLOWCTL_TIMEOUT*/; timeout++) {
        fcr = FREG(0xe4000018)[0]; //FREG_ETH_GetFcr();
        if ((fcr & 1/*FMAC3H_REG_msk(FCR, FCB)*/) == 0x0) {
            break;
        }
    }
    if (timeout == 0x100/*FMAC3H_FLOWCTL_TIMEOUT*/) {
        return;
    }

#if 0
    fcr &= ~FMAC3H_REG_msk(FCR, PT);
    fcr |=  ((uint32_t)FMAC3H_FLOWCTL_PAUSE_TIME << FMAC3H_REG_FCR_sft_PT);
    fcr |= FMAC3H_REG_msk(FCR, FCB);
#else
    fcr &= 0xffff;
    fcr |= 0x1d00001;
#endif
    FREG(0xe4000018)[0] = fcr; //FREG_ETH_SetFcr(fcr);
}


/* 2347e2ec - complete */
void fm3RUInt(int a)
{
#if 0
	console_send_string("fm3RUInt (todo.c): TODO\r\n");
#endif

#if 1 //USE_FLOWCTL
    fm3SendPause();
#endif /* USE_FLOWCTL */

    /*FM3HDL*/Data_234dd90c[a].ruCnt++;

     /* Anyway, try recovery*/
    if ( /*FM3HDL*/Data_234dd90c[a].stopFlagR == 0x100/*FMAC3H_RX_RUN*/ )
    {
        /*FM3HDL*/Data_234dd90c[a].stopFlagR
        = /*(fmac3hStatEnumT)*/((uint32_t)/*FM3HDL*/Data_234dd90c[a].stopFlagR |
                (uint32_t)0x200/*FMAC3H_RX_SUSP_NOBUF*/);
    }
}


/* 2347e3e0 - complete */
int fm3HandleIntRx(int a)
{
#if 0
	console_send_string("fm3HandleIntRx (todo.c): TODO\r\n");
#endif

#if 0
    {
		extern char debug_string[];
		sprintf(debug_string, "fm3HandleIntRx: Data_234dd90c[a].descPtrRx=0x%x, des0=0x%x, des1=0x%x, des2=0x%x\r\n",
				Data_234dd90c[a].descPtrRx, Data_234dd90c[a].descPtrRx->des0, Data_234dd90c[a].descPtrRx->des1, Data_234dd90c[a].descPtrRx->des2);
		console_send_string(debug_string);
    }
#endif

	while ((Data_234dd90c[a].descPtrRx->des0 & 0x80000000) == 0)
	{
		//loc_2347e3f4
		Data_234dd90c[a].inCnt++;

		Data_234dd90c[a].descPtrRx = //fm3NextRDesc
				(Data_234dd90c[a].descPtrRx == &Data_234dd90c[a].rDesc[Data_234dd90c[a].rDescNum - 1])?
						&Data_234dd90c[a].rDesc[0]: (Data_234dd90c[a].descPtrRx + 1);

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "fm3HandleIntRx: Data_234dd90c[a].descPtrRx=0x%x, des0=0x%x, des1=0x%x, des2=0x%x\r\n",
					Data_234dd90c[a].descPtrRx, Data_234dd90c[a].descPtrRx->des0, Data_234dd90c[a].descPtrRx->des1, Data_234dd90c[a].descPtrRx->des2);
			console_send_string(debug_string);
		}
#endif

		if (Data_234dd90c[a].descPtrRx == Data_234dd90c[a].descPtrRead)
		{
			break;
		}
	}

	return 1;
}


/* 2347e440 - todo */
static int fm3CheckPhyBusy()
{
#if 0
	console_send_string("fm3CheckPhyBusy (todo.c): TODO\r\n");
#endif

    int32_t  retval       = -111; //FAPI_ETH_ERR_PHY_BUSY;
    uint32_t busy_timeout = (uint32_t)2000/*FMAC3H_PHY_RW_TIMEOUT*/;

    while ( busy_timeout > (uint32_t)0 )
    {
        --busy_timeout;
        if ( /*FREG_ETH_GetGar_Gb()*/(FREG(0xe4000010)[0] & 1) == (uint32_t)0 )
        {
            break;
        }
    }
    if ( busy_timeout > (uint32_t)0 )
    {
        retval = 0; //FAPI_OK;
    }
    return retval;
}


/* 2347d068 - todo */
static int fm3ReadPhy( uint8_t   phyAddr, uint8_t   phyRegisterAddr, uint32_t* phyRegisterValue )
{
#if 0
	console_send_string("fm3ReadPhy (todo.c): TODO\r\n");
#endif

    int32_t   retval;

    if ( phyRegisterValue == 0/*NULL*/ )
    {
        return -104; //FAPI_ETH_ERR_NULL_PTR;
    }

    retval = fm3CheckPhyBusy();
    if ( retval != 0/*FAPI_OK*/ )
    {
#if 0
        FAPI_SYS_PRINT_DEBUG( FAPI_ETH_WARN, PHY_BUSY_MSG, __FUNCTION__ );
#endif
        return retval;
    }

#if 0
    FREG_ETH_SetGar( (uint32_t)(
            ((uint32_t)phyAddr<<FMAC3H_REG_GAR_sft_PA) |
            ((uint32_t)phyRegisterAddr <<FMAC3H_REG_GAR_sft_GR) |
             FMAC3H_REG_val(GAR, READ) |
             FMAC3H_REG_val(GAR, BUSY)) );
#else
    FREG(0xe4000010)[0] = (phyAddr << 11) | (phyRegisterAddr << 6) | 0x01;
#endif

    retval = fm3CheckPhyBusy();
    if ( retval != 0/*FAPI_OK*/ )
    {
#if 0
        FAPI_SYS_PRINT_DEBUG( FAPI_ETH_WARN, PHY_BUSY_MSG, __FUNCTION__ );
#endif
        return retval;
    }

    *phyRegisterValue = FREG(0xe4000014)[0] & 0xffff; //FREG_ETH_GetGdr_Gd();

    return retval;
}


/* 2347e474 - complete */
static int fm3WritePhy( uint8_t  phyAddr, uint8_t  phyReg, uint32_t phyRegVal )
{
#if 0
	console_send_string("fm3WritePhy (todo.c): TODO\r\n");
#endif

	int32_t  retval = fm3CheckPhyBusy();

	if ( retval != 0/*FAPI_OK*/ )
	{
#if 0
		FAPI_SYS_PRINT_DEBUG( FAPI_ETH_WARN, PHY_BUSY_MSG, __FUNCTION__ );
#endif
		return retval;
	}

	FREG(0xe4000014)[0] = phyRegVal & 0xffff; //FREG_ETH_SetGdr_Gd( phyRegVal );

	retval = fm3CheckPhyBusy();
	if ( retval != 0/*FAPI_OK*/ )
	{
#if 0
		FAPI_SYS_PRINT_DEBUG( FAPI_ETH_WARN, PHY_BUSY_MSG, __FUNCTION__ );
#endif
		return retval;
	}

#if 0
	FREG_ETH_SetGar((uint32_t)(((uint32_t)phyAddr<<FMAC3H_REG_GAR_sft_PA)|
							   ((uint32_t)phyReg <<FMAC3H_REG_GAR_sft_GR)|
							   FMAC3H_REG_val(GAR, WRITE)|
							   FMAC3H_REG_val(GAR, BUSY)) );
#else
	FREG(0xe4000010)[0] = (phyAddr << 11) | (phyReg << 6) | 0x03;
#endif

	return retval;
}


/* 2347e544 - complete */
int fm3SetupMCR(int a)
{
#if 0
	console_send_string("fm3SetupMCR (todo.c): TODO\r\n");
#endif

    uint32_t mcr = (uint32_t)0;

    if ( Data_234dd90c[a].supJumbo == 1/*FAPI_ETH_TRUE*/ )
    {
#if 0
        /* disable watchdog and jabber timer */
        mcr |= FMAC3H_REG_val(MCR, DIS_WT);
        mcr |= FMAC3H_REG_val(MCR, DIS_JT);
        /* enable jumbo frame */
        mcr |= FMAC3H_REG_val(MCR, EN_JUMBO);
#else
        mcr |= 0xd00000;
#endif
    }
    /* port select */
    if ( Data_234dd90c[a].phyPort == 2/*FMAC3H_PORT_GMII*/ )
    {
        mcr &= ~0x8000/*(FMAC3H_REG_val(MCR, MII))*/;
    }
    else
    {
        mcr |= 0x8000/*FMAC3H_REG_val(MCR, MII)*/;
    }

    /* little endian */
    mcr &= ~0x4000/*(FMAC3H_REG_val(MCR, BIG_EDN))*/;

    /* local loopback mode setting */
    if ( Data_234dd90c[a].pStat->loop == 1/*FAPI_ETH_LOOP_ON_MAC*/ )
    {
        mcr |= 0x1000/*FMAC3H_REG_val(MCR, LOOPBACK)*/;
    }

    /* duplex mode setting */
    if ( Data_234dd90c[a].pStat->duplex == 0/*FAPI_ETH_HALF_DUPLEX*/ )
    {
        mcr &= ~0x800/*(FMAC3H_REG_val(MCR, FULL_DPLX))*/;
    }
    else/* (Data_234dd90c[a].pStat->duplex == FAPI_ETH_FULL_DUPLEX) */
    {
        mcr |= 0x800/*FMAC3H_REG_val(MCR, FULL_DPLX)*/;
    }

#if 0
    /* pad stripping */
    mcr |= FMAC3H_REG_val(MCR, STRIP_PAD);
    /* CRC stripping */
    mcr |= FMAC3H_REG_val(MCR, STRIP_CRC);
    /* enable deferral check */
    mcr |= FMAC3H_REG_val(MCR, CHK_DFRL);
    /* enable transmit */
    mcr |= FMAC3H_REG_val(MCR, EN_TX);
    /* enable receive */
    mcr |= FMAC3H_REG_val(MCR, EN_RX);
    mcr |= FMAC3H_REG_val(MCR, DIS_RECV_OWN);
#else
    mcr |= 0x219c;
#endif

    return mcr;
}

