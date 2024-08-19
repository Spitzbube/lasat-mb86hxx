#ifndef _USB_MSD_H_
#define _USB_MSD_H_

#include "mu_hfi.h"

#define CFG_ENABLE_SYC_OP                1

typedef struct
{
	MUSB_HfiVolumeHandle hVolume; //0
	const MUSB_HfiDeviceInfo* Data_4; //4
	MUSB_HfiDevice* pHfiDevice; //8
	void* requestSema; //12
	void* responseSema; //16
	uint16_t wData_0x14; //20
	//0x18 = 24
} USB_MSD_Device;


typedef struct
{
	int (*read)(void* h, uint32_t dwStartBlockLo, void* pBuffer, uint16_t wBlockCount); //0
	int (*write)(void* h, uint32_t dwStartBlockLo, void* pBuffer, uint16_t wBlockCount); //4
	void (*Data_8)(); //8
	void (*Data_12)(); //12
	void (*Data_16)(); //16
	void (*Data_20)(); //20
	USB_MSD_Device* pDevice; //24
} USB_MSD_Interface;


/*******************************************************************************
* Function Declarations
*******************************************************************************/
extern int usb_sw_init(void);
extern int usb_sw_uninit(void);


extern USB_MSD_Device* musb_msd_get_device(int index);
extern int MUSB_HfiRead(void*, uint32_t dwStartBlockLo, void* pBuffer, uint16_t wBlockCount);
extern int MUSB_HfiWrite(void*, uint32_t dwStartBlockLo, void* pBuffer, uint16_t wBlockCount);
extern uint32_t MUSB_HfiGetMediumBlockCount(void*);
extern uint32_t MUSB_HfiGetMediumBlockSize(void*);


#ifdef CFG_ENABLE_SYC_OP
extern uint32_t MUSB_HfiRead_sync( uint32_t first_block, uint32_t block_num, uint8_t *dest);
extern uint32_t MUSB_HfiWrite_sync( uint32_t first_block, uint32_t block_num, uint8_t *dest);
#endif // CFG_ENABLE_SYC_OP

#endif // _USB_MSD_H_

// EOF
