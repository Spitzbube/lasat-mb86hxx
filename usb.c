
#include "ucos_ii.h"


OS_EVENT* usb_sema = 0; //23492c40 +8
OS_EVENT* Data_23492c44 = 0; //23492c44 +0xc


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

#if 0
		memset(&MGC_usbSystem, 0, sizeof(MGC_usbSystem));

		if (0 != sub_23467de0(Data_23492c3c[0]))
		{
			intr_set_isr(usb_isr, 0, 21); //FAPI_INTR_USB

			sub_2341b3b8(21, 0);

			FREG(0xe0000254)[0] = 0x0f;
		}
#endif
		//loc_234398c4
	}
	//loc_234398c4
	return 0;
}

