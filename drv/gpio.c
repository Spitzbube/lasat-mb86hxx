
#include <string.h>
#include <stdint.h>
#include "sys_services.h"
#include "gpio.h"
#include "ucos_ii.h"


#define FAPI_GPIO_PIN_COUNT           96


int Data_20408478; //20408478 -4
int Data_2040847c; //2040847c

Struct_20611068 Data_20611068[FAPI_GPIO_PIN_COUNT];


typedef union
{
	struct
	{
#if 1
		unsigned int DataOutSel: 8; //0
		unsigned int DataEnSel: 8; //1
		unsigned int DataEnExchange: 1; //2
		unsigned int DataOutInv: 1; //2
		unsigned int DataEnableInv: 1; //2
#else
		unsigned int DataOutSel: 7; //0
		unsigned int fill_8: 1;
		unsigned int DataEnSel: 4; //1
		unsigned int fill_12: 4;
		unsigned int DataEnExchange: 1; //2
		unsigned int DataOutInv: 1; //2
		unsigned int DataEnableInv: 1; //2
#endif
	} bits; //0
	unsigned int dwData; //0
} DataOut;



/* 2341a938 / 23426c1c - todo */
int gpio_init(void)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	unsigned char pin;
	OS_ENTER_CRITICAL();

	Data_2040847c = (1 << 9);

//	gpioRegs = (void*) 0xc3000000;

	if (0 != sys_get_device_id())
	{
		*((volatile unsigned int*)0xc30004c0/*GPIO_IRQ_cfg*/) = Data_2040847c;
		Data_20408478 = 0xc3000404/*GPIO_input_31_0*/;
	}
	else
	{
		*((volatile unsigned int*)0xc3000520) = Data_2040847c;
		*((volatile unsigned int*)0xc30005c4) = 0; //r5;
		Data_20408478 = 0xc3000504;
	}

	memset(Data_20611068, 0xff, FAPI_GPIO_PIN_COUNT*sizeof(Struct_20611068));

	for (pin = 0; pin < FAPI_GPIO_PIN_COUNT; pin++)
	{
		//loc_204012e8
		DataOut dataOut; //sp

		dataOut.dwData = 0; //r5;
		dataOut.bits.DataEnSel = 1;

#if 0 //DEADLOCK? Probably also the Debug pins are affected!
		if (Data_20408478 == 0xc3000404)
		{
			if (pin != 2 /*Debug_Out*/)
			{
				*((volatile unsigned int*)0xc3000000 + pin) = dataOut.dwData; //Out
			}
			if (pin != 0 /*Debug_In*/)
			{
				*((volatile unsigned int*)0xc3000208) = pin + 2; //In
			}
		}
#endif
	}

	OS_EXIT_CRITICAL();

	return 0;
}

/* 2341a9dc - todo */
int gpio_open(Struct_20401328* pParams, Struct_20611068** r5)
{
	DataOut dataOut; //sp
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

//	int r6 = 0;
	int bidi = 0;

	if (pParams->bPin == 0xff)
	{
		*r5 = 0; //r6;
		//->loc_20401474
	}
	else
	{
		OS_ENTER_CRITICAL();

		if (pParams->bPin < FAPI_GPIO_PIN_COUNT)
		{
			//20401358
			Struct_20611068* r1 = &Data_20611068[pParams->bPin];

			if (r1->bData_0 != 0xff)
			{
				OS_EXIT_CRITICAL();

				return 4;
			}
			else
			{
				//loc_2040137c
				volatile uint32_t* gpioRegs = (void*) 0xc3000000;

				dataOut.dwData = 0; //r6;

				if (pParams->dwInFunction != 0xff)
				{
					if (pParams->dwOutFunction == 0xff)
					{
						//2040139c
						dataOut.bits.DataEnSel = 1;
						//FREG_GPIO_SetDataOut_DataEnSel(pin, 1)
						gpioRegs[pParams->bPin] = dataOut.dwData;

						//FREG_GPIO_SetDataIn(pParams->dwInFunction, pParams->bPin)
						gpioRegs[0x80 + pParams->dwInFunction] = pParams->bPin + 2;
						//loc_204013c0
					}
					else
					{
						//loc_204013dc
						bidi = 1;
					}
				} //if (pParams->dwInFunction != 0xff)
				//loc_204013c0
				if (!bidi && (pParams->dwOutFunction != 0xff))
				{
					//204013cc
					if (pParams->dwInFunction == 0xff)
					{
						dataOut.bits.DataOutSel = pParams->dwOutFunction;
						//->loc_20401458
						gpioRegs[pParams->bPin] = dataOut.dwData;
						//loc_20401464
					}
					else
					{
						//loc_204013dc
						bidi = 1;
					}
				} //if (!bidi && (pParams->dwOutFunction != 0xff))

				if (bidi/*(pParams->dwInFunction != 0xff) && (pParams->dwOutFunction != 0xff)*/)
				{
					//loc_2341aa90
					dataOut.bits.DataEnSel = 0; //r6
					dataOut.bits.DataEnExchange = 1;
					dataOut.bits.DataOutSel = pParams->dwOutFunction;

					if (pParams->dwOutFunction == 0x1d) //FAPI_GPIO_OUT_ICC0_DATA
					{
						dataOut.bits.DataEnExchange = 0;
						//FREG_GPIO_SetDataOut_DataEnSel( pin, 10 );
						dataOut.bits.DataEnSel = 10;
						//->loc_20401440
					}
					//2040140c
					else if ((pParams->dwOutFunction >= 0x8e) && (pParams->dwOutFunction <= 0x9d))
					{
						dataOut.bits.DataEnExchange = 0;
						dataOut.bits.DataEnSel = 33; //0x21;
						//->loc_20401440
					}
					//20401428
					else if (pParams->dwOutFunction == 0xa9)
					{
						dataOut.bits.DataEnExchange = 0;
						dataOut.bits.DataEnSel = 34; //0x22;
						//->loc_20401440
					}
					//loc_20401444
					gpioRegs[0x80 + pParams->dwInFunction] = pParams->bPin + 2;
					//loc_20401458
					gpioRegs[pParams->bPin] = dataOut.dwData;
					//loc_20401464
				} //if (bidi)
				//loc_20401464
				r1->bData_0 = pParams->bPin;
				*r5 = r1;
			}
		} //if (pParams->bPin < FAPI_GPIO_PIN_COUNT)
		else
		{
			//loc_2040147c
			OS_EXIT_CRITICAL();

			return 2;
		}

		OS_EXIT_CRITICAL();
	}
	//loc_20401474
	return 0;
}

