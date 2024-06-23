
#include "data.h"

Uart_Module* Data_20408480; //20408480 +0
unsigned int uartClockFrequency; //20408484 + 4
//OS_EVENT* uartSema; //20408488 + 8
Struct_20611068* Data_2040848c; //2040848c
Struct_20611068* Data_20408490; //20408490
Uart_Module Data_20408494[2] = //20408494
{
		{0, (void*)0xc2000000},
		{0, (void*)0xce000000},
};
Uart_Module Data_204084a4[2] = //204084a4
{
		{0, (void*)0xcd000000},
		{0, (void*)0xce000000},
};


/* 2341ad64 - todo */
int sub_2341ad64(Uart_Module* r0)
{
	Uart_Regs* regs;
	uint8_t sp;
	int r4;

	regs = r0->Data_4;

	if (r0 == 0)
	{
		return 0;
	}

//	OSSemPend(uartSema, 0, &sp);

	r4 = regs->FREG_UART_FR;

//	OSSemPost(uartSema);

	if (r4 & ((1 << 4)/*Rxfe*/ | (1 << 3)/*Busy*/))
	{
		return 1;
	}

	return 0;
}


/* 2341ada0 - todo */
int uart_write_byte(Uart_Module* r0, unsigned char ch)
{
	Uart_Regs* regs;
	uint8_t sp;

	if (r0 == 0)
	{
		return 1;
	}

	regs = r0->Data_4;

//	OSSemPend(uartSema, 0, &sp);

	while ((regs->FREG_UART_FR & 0x28) != 0)
	{
		/* Txff + Busy */
	}

//	OSSemPost(uartSema);

	regs->FREG_UART_DR = ch;

	return 0;
}


/* 2341adec - todo */
char uart_init(Uart_Init_Params* pParams, Uart_Module** ppModule)
{
	int i;
	uint8_t sp = 0;

	if (pParams->bData_0 > 2)
	{
		return 3;
	}

//	OSSemPend(uartSema, 0, &sp);

	if (Data_20408480[pParams->bData_0].bData_0 != 0)
	{
		sp = 4;
	}
	else
	{
		Uart_Regs* pRegs = Data_20408480[pParams->bData_0].Data_4;

		unsigned int r8 = uartClockFrequency / (115200 * 16);
		unsigned int r0 = ((uartClockFrequency * 4) / 115200);
		r0 = r0 - (r8 * 64);
		r0 = (5 + r0 * 10) / 10;

		pRegs->FREG_UART_IBRD = r8;
		pRegs->FREG_UART_FBRD = r0;
		pRegs->FREG_UART_LCRH = 0x70;
		pRegs->FREG_UART_CR = 0x301;

		if (pParams->txPin.bPin != 0xff)
		{
			gpio_open(&pParams->txPin, &Data_2040848c);
		}

		if (pParams->rxPin.bPin != 0xff)
		{
			gpio_open(&pParams->rxPin, &Data_20408490);
		}

		Data_20408480[pParams->bData_0].bData_0 = 1;

		*ppModule = &Data_20408480[pParams->bData_0];

		for (i = 0; i < 0xffff; i++)
		{
			/* wait */
		}

		for (i = 0; i < 0x10; i++)
		{
			/* wait */
			pRegs->FREG_UART_DR;
		}
	}

	//loc_200015c0
//	OSSemPost(uartSema);

	return sp;
}


/* 2341acb4 - todo */
int uart_setup(void)
{
	unsigned char i;

	if (0 != sys_get_device_id())
	{
		Data_20408480 = Data_20408494;
		uartClockFrequency = 81000000;
	}
	else
	{
		Data_20408480 = Data_204084a4;
		uartClockFrequency = 99000000;
	}

	for (i = 0; i < 2; i++)
	{
		//loc_20401630
		Data_20408480[i].bData_0 = 0;
		Data_20408480[i].Data_4->FREG_UART_CR = 0;
	}

//	uartSema = OSSemCreate(1);

	return 0;
}


/* 2341ad20 - todo */
unsigned char uart_read_byte(Uart_Module* r0)
{
	int r4;
	uint8_t sp;
	Uart_Regs* pRegs = r0->Data_4;

	if (r0 == 0)
	{
		return 0;
	}

//	OSSemPend(uartSema, 0, &sp);

	while (pRegs->FREG_UART_FR & 0x18)
	{
		//loc_20401690
		/* wait */
	}

	r4 = pRegs->FREG_UART_DR;

//	OSSemPost(uartSema);

	return r4;
}


/* 20001690 - todo */
void uart_send_number()
{

}


