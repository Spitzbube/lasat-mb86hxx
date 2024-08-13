#ifndef _USB_MSD_H_
#define _USB_MSD_H_

#include "mu_hfi.h"

#define CFG_ENABLE_SYC_OP                1

typedef struct
{
	MUSB_HfiVolumeHandle Data_0; //0
	const MUSB_HfiDeviceInfo* Data_4; //4
	MUSB_HfiDevice* pHfiDevice; //8
	void* Data_0xc; //12
	void* Data_0x10; //16
	uint16_t wData_0x14; //20
	//0x18 = 24
} USB_MSD_Device;


/*******************************************************************************
* Function Declarations
*******************************************************************************/
extern int usb_sw_init(void);
extern int usb_sw_uninit(void);


extern USB_MSD_Device* musb_msd_get_device(int index);


#ifdef CFG_ENABLE_SYC_OP
extern uint32_t MUSB_HfiRead_sync( uint32_t first_block, uint32_t block_num, uint8_t *dest);
extern uint32_t MUSB_HfiWrite_sync( uint32_t first_block, uint32_t block_num, uint8_t *dest);
#endif // CFG_ENABLE_SYC_OP

#endif // _USB_MSD_H_

// EOF
