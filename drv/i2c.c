
#include "ucos_ii.h"
#include "sys_services.h"
#include "gpio.h"
#include "i2c.h"


//234922a4
I2c_Bus* Data_234922a4; //234922a4 +0
OS_EVENT* i2cSema; //234922a8 +4
I2c_Bus Data_234922ac[5] = //234922ac -> 2349234C
{
		{
			(void*)0xffffffff, //clkGpio; //0
			(void*)0xffffffff, //dataGpio; //4
			0xff, //bData_8; //8
		},
		{
			(void*)0xffffffff, //clkGpio; //0
			(void*)0xffffffff, //dataGpio; //4
			0xff, //bData_8; //8
		},
		{
			(void*)0xffffffff, //clkGpio; //0
			(void*)0xffffffff, //dataGpio; //4
			0xff, //bData_8; //8
		},
		{
			(void*)0xffffffff, //clkGpio; //0
			(void*)0xffffffff, //dataGpio; //4
			0xff, //bData_8; //8
		},
		{
			(void*)0xffffffff, //clkGpio; //0
			(void*)0xffffffff, //dataGpio; //4
			0xff, //bData_8; //8
		},
};


#define FREG_I2C_STATUSREG0 (0xC4000000)
#define FREG_I2C_STATUSREG1 (0xC4000004)
#define FREG_I2C_IRQMASK0 (0xC4000008)
#define FREG_I2C_IRQMASK1 (0xC400000C)
#define FREG_I2C_CONTROLREG0 (0xC4000010)
#define FREG_I2C_CONTROLREG1 (0xC4000014)
#define FREG_I2C_CONTROLREG2 (0xC4000018)
#define FREG_I2C_CONTROLREG3 (0xC400001C)
#define FREG_I2C_TXDATAREG (0xC4000020)
#define FREG_I2C_GOREG (0xC4000024)
#define FREG_I2C_RXDATAREG (0xC4000028)

#define FREG_I2C_MOFFSET (0x0E000000/4)


void i2c_set_irqmask0(int a, int b);
void i2c_set_irqmask1(int a, int b);
void i2c_set_controlreg0(int a, int b);
void i2c_set_controlreg2(int a, int am_tx_num);
void i2c_set_controlreg3(int a, int am_rx_num);
void i2c_set_goreg(int a, int b);
int i2c_get_rxdatareg(int a);
void i2c_get_statusreg0(I2c_Bus*);
int i2c_is_busy(I2c_Bus*);
void sub_2341d154(void);
void sub_2341d194();
int i2c_read_reg(int, uint32_t, void*, int);


/* 2341b950 - todo */
void i2c_set_irqmask1_am_end(int a, int b)
{
	b = (b << 6) & (1 << 6); //AM_END

	if (a == 2)
	{
		*FREG(0xd300000c) = (*FREG(0xd300000c) & ~(1 << 6)) | b;
	}
	else
	{
		FREG(FREG_I2C_IRQMASK1)[a*FREG_I2C_MOFFSET] = //I2C_IRQMask1
				(FREG(FREG_I2C_IRQMASK1)[a*FREG_I2C_MOFFSET] & ~(1 << 6)) | b;
	}
}


/* 2341b994 - todo */
void i2c_set_irqmask1_am_err(int a, int b)
{
	b = (b << 5) & (1 << 5); //AM_ERR

	if (a == 2)
	{
		*FREG(0xd300000c) = (*FREG(0xd300000c) & ~(1 << 5)) | b;
	}
	else
	{
		FREG(FREG_I2C_IRQMASK1)[a*FREG_I2C_MOFFSET] = //I2C_IRQMask1
				(FREG(FREG_I2C_IRQMASK1)[a*FREG_I2C_MOFFSET] & ~(1 << 5)) | b;
	}
}


/* 2341b9d8 - todo */
void i2c_set_irqmask1_am_mrx_req(int a, int b)
{
	b = (b << 4) & (1 << 4); //AM_MRX_REQ

	if (a == 2)
	{
		*FREG(0xd300000c) = (*FREG(0xd300000c) & ~(1 << 4)) | b;
	}
	else
	{
		FREG(FREG_I2C_IRQMASK1)[a*FREG_I2C_MOFFSET] = //I2C_IRQMask1
				(FREG(FREG_I2C_IRQMASK1)[a*FREG_I2C_MOFFSET] & ~(1 << 4)) | b;
	}
}


/* 2341ba1c - todo */
void i2c_set_irqmask1_am_mtx_req(int a, int b)
{
	b = (b << 3) & (1 << 3); //AM_MTX_REQ

	if (a == 2)
	{
		*FREG(0xd300000c) = (*FREG(0xd300000c) & ~(1 << 3)) | b;
	}
	else
	{
		FREG(FREG_I2C_IRQMASK1)[a*FREG_I2C_MOFFSET] = //I2C_IRQMask1
				(FREG(FREG_I2C_IRQMASK1)[a*FREG_I2C_MOFFSET] & ~(1 << 3)) | b;
	}
}


/* 2341ba60 - todo */
void i2c_set_controlreg0_am_mode(int a, int b)
{
	b = (b << 8) & (3 << 8); //AM_MODE

	if (a == 2)
	{
		*FREG(0xd3000010) = (*FREG(0xd3000010) & ~(3 << 8)) | b;
	}
	else
	{
		FREG(FREG_I2C_CONTROLREG0)[a*FREG_I2C_MOFFSET] = //I2C_ControlReg0
				(FREG(FREG_I2C_CONTROLREG0)[a*FREG_I2C_MOFFSET] & ~(3 << 8)) | b;
	}
}


/* 2341baa4 - todo */
void i2c_set_controlreg0_reset(int a, int b)
{
	b = (b << 3) & (1 << 3); //RESET

	if (a == 2)
	{
		*FREG(0xd3000010) = (*FREG(0xd3000010) & ~(1 << 3)) | b;
	}
	else
	{
		FREG(FREG_I2C_CONTROLREG0)[a*FREG_I2C_MOFFSET] = //I2C_ControlReg0
				(FREG(FREG_I2C_CONTROLREG0)[a*FREG_I2C_MOFFSET] & ~(1 << 3)) | b;
	}
}


/* 2341bae8 - todo */
void i2c_set_controlreg1_ms_sla_add(int a, int b)
{
	b = (b << 8) & (0x7f << 8); //MS_SLA_ADD

	if (a == 2)
	{
		*FREG(0xd3000014) = (*FREG(0xd3000014) & ~(0x7f << 8)) | b;
	}
	else
	{
		FREG(FREG_I2C_CONTROLREG1)[a*FREG_I2C_MOFFSET] =
				(FREG(FREG_I2C_CONTROLREG1)[a*FREG_I2C_MOFFSET] & ~(0x7f << 8)) | b;
	}
}


/* 2341bb2c - todo */
void i2c_set_controlreg1_i2c_speed(int a, int b)
{
	b = (b << 0) & (1 << 0); //I2C_SPEED

	if (a == 2)
	{
		*FREG(0xd3000014) = (*FREG(0xd3000014) & ~(1 << 0)) | b;
	}
	else
	{
		FREG(FREG_I2C_CONTROLREG1)[a*FREG_I2C_MOFFSET] =
				(FREG(FREG_I2C_CONTROLREG1)[a*FREG_I2C_MOFFSET] & ~(1 << 0)) | b;
	}
}


/* 2341bb70 - todo */
void i2c_set_goreg_am_start(int a, int b)
{
	b = (b << 2) & (1 << 2); //AM_START

	if (a == 2)
	{
		*FREG(0xd3000024) = (*FREG(0xd3000024) & ~(1 << 2)) | b; //FREG_I2C2_GOREG
	}
	else
	{
		FREG(FREG_I2C_GOREG)[a*FREG_I2C_MOFFSET] =
				(FREG(FREG_I2C_GOREG)[a*FREG_I2C_MOFFSET] & ~(1 << 2)) | b;
	}
}


/* 2341bbb4 - todo */
void i2c_set_goreg_am_reset(int a, int b)
{
	b = (b << 1) & (1 << 1); //AM_RESET

	if (a == 2)
	{
		*FREG(0xd3000024) = (*FREG(0xd3000024) & ~(1 << 1)) | b; //FREG_I2C2_GOREG
	}
	else
	{
		FREG(FREG_I2C_GOREG)[a*FREG_I2C_MOFFSET] =
				(FREG(FREG_I2C_GOREG)[a*FREG_I2C_MOFFSET] & ~(1 << 1)) | b;
	}
}


/* 2341bbf8 - todo */
void i2c_handle_irq(int a)
{
	I2c_Bus* r4;
	uint8_t r5;
	uint32_t statusReg1;

	if (a != 2)
	{
		statusReg1 = FREG(FREG_I2C_STATUSREG1)[a*FREG_I2C_MOFFSET];
	}
	else
	{
		statusReg1 = *FREG(0xd3000004); //FREG_I2C2_STATUSREG1
	}

	r4 = 0;
	for (r5 = 0; r5 < 5; r5++)
	{
		//loc_2341bc24
		if (Data_234922ac[r5].bData_8 == a)
		{
			r4 = &Data_234922ac[r5];
			//->loc_2341bc48
			break;
		}
	}
	//loc_2341bc48
	if (r4 == 0)
	{
		return;
	}

	if (statusReg1 & (1 << 5)) //AM_ERR
	{
		//0x2341bc58
#if DEBUG_I2C_INTR
		console_send_string("i2c_handle_irq: AM_ERR\r\n");
#endif
		i2c_get_statusreg0(r4);
		i2c_set_irqmask1(r4->bData_8, 0);
		OSSemPost(r4->sema);
		return;
	}
	//loc_2341bc78
	if (statusReg1 & (1 << 3)) //AM_MTX_REQ
	{
#if DEBUG_I2C_INTR
		console_send_string("i2c_handle_irq: AM_MTX_REQ\r\n");
#endif
		if (a == 2)
		{
			*FREG(0xd3000020) = *(r4->pTxData); //FREG_I2C2_TXDATAREG
		}
		else
		{
			FREG(FREG_I2C_TXDATAREG)[a*FREG_I2C_MOFFSET] = *(r4->pTxData);
		}
		r4->pTxData++;
		r5 = 1;
	}
	//loc_2341bca4
	if (statusReg1 & (1 << 4)) //AM_MRX_REQ
	{
#if DEBUG_I2C_INTR
		console_send_string("i2c_handle_irq: AM_MRX_REQ\r\n");
#endif
		if ((r4->pRxData != 0) &&
				(r4->bData_11 < r4->bData_10))
		{
			r4->pRxData[r4->bData_11] = i2c_get_rxdatareg(r4->bData_8);
		}
		else
		{
			//loc_2341bcdc
			(void) i2c_get_rxdatareg(r4->bData_8);
		}
		//loc_2341bce0
		r4->bData_11++;
		r5 = 1;
	}
	//loc_2341bcf0
	if (statusReg1 & (1 << 6)) //AM_END
	{
#if DEBUG_I2C_INTR
		console_send_string("i2c_handle_irq: AM_END\r\n");
#endif
		r4->bData_9 = 0;
		r5 = 1;
		OSSemPost(r4->sema);
	}

	if ((r4->bData_9 == 0) && (r5 == 0))
	{
		i2c_set_irqmask1(r4->bData_8, 0);
	}
}


/* 2341bd24 - todo */
int i2c_irq0(void)
{
#if 0
	console_send_string("i2c_irq0 (i2c.c)\r\n");
#endif
	i2c_handle_irq(0);

	return 0;
}


/* 2341bd38 - todo */
int i2c_irq1(void)
{
#if 0
	console_send_string("i2c_irq1 (i2c.c)\r\n");
#endif
	i2c_handle_irq(1);

	return 0;
}


/* 2341bd4c - todo */
int i2c_irq2(void)
{
#if 0
	console_send_string("i2c_irq2 (i2c.c)\r\n");
#endif
	i2c_handle_irq(2);

	return 0;
}


/* 2341bd60 - todo */
void i2c_configure_irq(int a)
{
	if (a == 0)
	{
		intr_set_isr(i2c_irq0, 0, 15); //FAPI_INTR_I2C0
		sub_2341b3b8(15, 0);
		//r0=0xe000003c
		*FREG(0xe000023c) = 0x0f;
	}
	else if (a == 1)
	{
		intr_set_isr(i2c_irq1, 0, 16); //FAPI_INTR_I2C1
		sub_2341b3b8(16, 0);
		//r0=0xe0000040
		*FREG(0xe0000240) = 0x0f;
	}
	else //if (a == 2)
	{
		intr_set_isr(i2c_irq2, 0, 17); //FAPI_INTR_I2C2
		sub_2341b3b8(17, 0);
		//r0=0xe0000044
		*FREG(0xe0000244) = 0x0f;
	}
	//loc_2341bde0
}


/* 2341bde8 - todo */
void sub_2341bde8(I2c_Bus* r4)
{
#if 0
	console_send_string("sub_2341bde8 (todo.c): TODO\r\n");
#endif

	i2c_set_controlreg0_am_mode(r4->bData_8, 2/*master transmitter/receiver*/);

	if (r4->bData_8 == 2)
	{
		*FREG(0xd3000010) |= 0x80; //FREG_I2C2_SetControlreg0_UseAdd
	}
	else
	{
		FREG(FREG_I2C_CONTROLREG0)[r4->bData_8*FREG_I2C_MOFFSET] |= 0x80;
	}

	if (r4->bData_8 == 2)
	{
		*FREG(0xd3000010) |= 0x10; //FREG_I2C2_SetControlreg0_AmOn
	}
	else
	{
		FREG(FREG_I2C_CONTROLREG0)[r4->bData_8*FREG_I2C_MOFFSET] |= 0x10;
	}

	i2c_set_controlreg1_i2c_speed(r4->bData_8, 1);

	if (r4->bData_8 == 2)
	{
		*FREG(0xd3000010) |= 0x800; //FREG_I2C2_SetControlreg0_SpikeFlt
	}
	else
	{
		FREG(FREG_I2C_CONTROLREG0)[r4->bData_8*FREG_I2C_MOFFSET] |= 0x800;
	}

	if (r4->bData_8 == 2)
	{
		*FREG(0xd3000010) |= 0x400; //FREG_I2C2_SetControlreg0_OiDlyAl
	}
	else
	{
		FREG(FREG_I2C_CONTROLREG0)[r4->bData_8*FREG_I2C_MOFFSET] |= 0x400;
	}

	if (r4->bData_8 == 2)
	{
		*FREG(0xd3000014) = 0; //FREG_I2C2_CONTROLREG1
	}
	else
	{
		FREG(FREG_I2C_CONTROLREG1)[r4->bData_8*FREG_I2C_MOFFSET] = 0;
	}

	i2c_set_irqmask0(r4->bData_8, 0);
	i2c_set_irqmask1(r4->bData_8, 0);
	i2c_set_irqmask1_am_end(r4->bData_8, 1);
	i2c_set_irqmask1_am_err(r4->bData_8, 1);
	i2c_set_irqmask1_am_mrx_req(r4->bData_8, 1);
	i2c_set_irqmask1_am_mtx_req(r4->bData_8, 1);

	if (r4->sema == 0)
	{
		r4->sema = OSSemCreate(0);
	}
}


/* 2341bf30 - complete */
int i2c_wait_event()
{
	uint8_t res;

	OSSemPend(Data_234922a4->sema, 10, &res);

	if (res != 0)
	{
#if 1
		console_send_string("i2c_wait_event: (i2c.c): OSSemPend -> res != 0\r\n");
#endif
		return 0xff;
	}

	if ((0 != i2c_is_busy(Data_234922a4)) ||
			(Data_234922a4->dwErrorStatus != 0))
	{
#if 1
		extern char debug_string[];
		sprintf(debug_string, "i2c_wait_event: (i2c.c): busy or dwErrorStatus=0x%x\r\n",
				Data_234922a4->dwErrorStatus);
		console_send_string(debug_string);
#endif
		return 0xff;
	}

	return 0;
}


/* 2341bf7c - todo */
int i2c_send(uint32_t addr, void* pTxData, int numTxBytes)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	if (0 != i2c_is_busy(Data_234922a4))
	{
		return 0xff;
	}

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "i2c_send Data_234922a4->bData_8=%d\r\n", Data_234922a4->bData_8);
		console_send_string(debug_string);
	}
#endif

	OS_ENTER_CRITICAL();

#if DEBUG_I2C_SEND
	console_send_string("i2c_send (i2c.c): ");
	{
		extern char debug_string[];
		sprintf(debug_string, "addr=0x%02x, pTxData[0]=0x%02x, numTxBytes=%d\r\n", addr, ((char*)pTxData)[0], numTxBytes);
		console_send_string(debug_string);
	}
#endif

	i2c_set_controlreg0(Data_234922a4->bData_8, 0xe90); //(AM_ON | USE_ADD | master transmitter/receiver | ...)
	i2c_set_controlreg1_i2c_speed(Data_234922a4->bData_8, Data_234922a4->bData_28);
	i2c_set_controlreg0_am_mode(Data_234922a4->bData_8, 0/*master transmitter*/);
	i2c_set_controlreg0_reset(Data_234922a4->bData_8, 1);
	i2c_set_controlreg0_reset(Data_234922a4->bData_8, 0);
	i2c_set_irqmask1_am_end(Data_234922a4->bData_8, 1);
	i2c_set_irqmask1_am_err(Data_234922a4->bData_8, 1);
	i2c_set_irqmask1_am_mrx_req(Data_234922a4->bData_8, 1);
	i2c_set_irqmask1_am_mtx_req(Data_234922a4->bData_8, 1);
	i2c_set_irqmask0(Data_234922a4->bData_8, 0);
	i2c_set_controlreg1_ms_sla_add(Data_234922a4->bData_8, addr >> 1);
	i2c_set_controlreg2(Data_234922a4->bData_8, numTxBytes + 1);
	i2c_set_controlreg3(Data_234922a4->bData_8, 0); //numRxBytes
	i2c_set_goreg_am_reset(Data_234922a4->bData_8, 1);
	i2c_set_goreg(Data_234922a4->bData_8, 0);
	i2c_set_goreg_am_start(Data_234922a4->bData_8, 1);

	Data_234922a4->dwErrorStatus = 0;
	Data_234922a4->bData_11 = 0;
	Data_234922a4->pRxData = 0;
	Data_234922a4->pTxData = pTxData;
	Data_234922a4->bData_9 = 0xff;

	OS_EXIT_CRITICAL();

	return 0xff & i2c_wait_event();
}


/* 2341c0e0 - todo */
int i2c_send_receive(uint32_t addr, uint8_t* pTxData, int numTxBytes, uint8_t* pRxData, int numRxBytes)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	if (0 != i2c_is_busy(Data_234922a4))
	{
		return 0xff;
	}

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "i2c_send_receive Data_234922a4->bData_8=%d\r\n", Data_234922a4->bData_8);
		console_send_string(debug_string);
	}
#endif

	OS_ENTER_CRITICAL();

	if (Data_234922a4->bData_8 != 2)
	{
		//0x2341c128
#if DEBUG_I2C_SEND_RECEIVE
		console_send_string("i2c_send_receive (bus 0/1): ");
		{
			extern char debug_string[];
			sprintf(debug_string, "addr=0x%02x, pTxData[0]=0x%02x, numTxBytes=%d, numRxBytes=%d\r\n",
					addr, ((char*)pTxData)[0], numTxBytes, numRxBytes);
			console_send_string(debug_string);
		}
#endif

		i2c_set_controlreg0(Data_234922a4->bData_8, 0xe90); //(AM_ON | USE_ADD | master transmitter/receiver | ...)
		i2c_set_controlreg1_i2c_speed(Data_234922a4->bData_8, Data_234922a4->bData_28);
		i2c_set_controlreg0_am_mode(Data_234922a4->bData_8, (numTxBytes != 0)?
						2: //master transmitter/receiver
						1); //master receiver
		i2c_set_controlreg0_reset(Data_234922a4->bData_8, 1);
		i2c_set_controlreg0_reset(Data_234922a4->bData_8, 0);
		i2c_set_irqmask1_am_end(Data_234922a4->bData_8, 1);
		i2c_set_irqmask1_am_err(Data_234922a4->bData_8, 1);
		i2c_set_irqmask1_am_mrx_req(Data_234922a4->bData_8, 1);
		i2c_set_irqmask1_am_mtx_req(Data_234922a4->bData_8, 1);
		i2c_set_irqmask0(Data_234922a4->bData_8, 0);
		i2c_set_controlreg1_ms_sla_add(Data_234922a4->bData_8, addr >> 1);
		i2c_set_controlreg2(Data_234922a4->bData_8, numTxBytes + 1);
		i2c_set_controlreg3(Data_234922a4->bData_8, numRxBytes);

		Data_234922a4->dwErrorStatus = 0;
		Data_234922a4->bData_10 = numRxBytes;
		Data_234922a4->bData_11 = 0;
		Data_234922a4->pRxData = pRxData;
		Data_234922a4->pTxData = pTxData;
		Data_234922a4->bData_9 = 0xff;

		i2c_set_goreg_am_reset(Data_234922a4->bData_8, 1);
		i2c_set_goreg(Data_234922a4->bData_8, 0);
		i2c_set_goreg_am_start(Data_234922a4->bData_8, 1);

		OS_EXIT_CRITICAL();

		return (0xff & i2c_wait_event());
	} //if (Data_234922a4->bData_8 != 2)
	else
	{
#if 0
		console_send_string("i2c_send_receive (bus 2)\r\n");
#endif
		//loc_2341c25c
		i2c_set_irqmask1_am_end(Data_234922a4->bData_8, 0);
		i2c_set_irqmask1_am_err(Data_234922a4->bData_8, 0);
		i2c_set_irqmask1_am_mrx_req(Data_234922a4->bData_8, 0);
		i2c_set_irqmask1_am_mtx_req(Data_234922a4->bData_8, 0);
		i2c_set_irqmask0(Data_234922a4->bData_8, 0);

		OS_EXIT_CRITICAL();

		*FREG(0xd3000024) = (1 << 1); //FREG_I2C2_GOREG (AM_RESET)
		*FREG(0xd3000010) = 0x290;
		*FREG(0xd3000014) = (addr << 7) + 1; //I2C2_ControlReg1
		*FREG(0xd3000018) = 0x03; //FREG_I2C2_CONTROLREG2 (TX_NUM)
		*FREG(0xd300001c) = (1 << 0); //FREG_I2C2_CONTROLREG3 (RX_NUM)
		*FREG(0xd3000024) = (1 << 2); //FREG_I2C2_GOREG (AM_START)

		while (1)
		{
			//loc_2341c2e0
			if (*FREG(0xd3000004) & (1 << 2)) //FREG_I2C2_STATUSREG1 (OCCUP)
			{
				break;
			}
		}
		while (1)
		{
			//loc_2341c2ec
			if (*FREG(0xd3000004) & (1 << 3)) //FREG_I2C2_STATUSREG1 (AM_MTX_REQ)
			{
				break;
			}
		}

		*FREG(0xd3000020) = *pTxData;

		while (1)
		{
			//loc_2341c300
			if (*FREG(0xd3000004) & (1 << 4)) // FREG_I2C2_STATUSREG1 (AM_MRX_REQ)
			{
				break;
			}
		}

		*pRxData = *FREG(0xd3000028);

		while (1)
		{
			//loc_2341c314
			if ((*FREG(0xd3000004) & (1 << 2)) == 0) //FREG_I2C2_STATUSREG1 (OCCUP)
			{
				break;
			}
		}

		return 0;
	}
}


/* 2341c328 - complete */
void sub_2341c328(void)
{
#if 1
	console_send_string("sub_2341c328 (i2c.c): TODO\r\n");
#else
	volatile uint32_t i;

	gpio_set(Data_234922a4->dataGpio, 0);

	for (i = 0; i < 68; i++)
	{
		//loc_2341c344
#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
		__asm { nop }
#endif
	}

	gpio_set(Data_234922a4->clkGpio, 0);

	for (i = 0; i < 68; i++)
	{
		//loc_2341c344
#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
		__asm { nop }
#endif
	}
#endif
}


/* 2341c37c - todo */
int sub_2341c37c()
{
	console_send_string("sub_2341c37c (i2c.c): TODO\r\n");

}


/* 2341c5a8 - todo */
int sub_2341c5a8(uint8_t r8)
{
#if 1
	console_send_string("sub_2341c5a8 (i2c.c): TODO\r\n");
#else
	volatile uint32_t i;
	uint32_t r4;
	int r6 = 0;
	uint32_t r5 = 0x80;

	while (1)
	{
		//loc_2341c5bc
		if (r8 & r5)
		{
			gpio_set(Data_234922a4->dataGpio, 1);
			sub_2341aba0(Data_234922a4->dataGpio, 0);

			if (0 == sub_2341abfc(Data_234922a4->dataGpio))
			{
				r6 = -8;
			}

			sub_2341aba0(Data_234922a4->dataGpio, 1);
			//->loc_2341c614
		}
		else
		{
			//loc_2341c60c
			gpio_set(Data_234922a4->dataGpio, 0);
		}
		//loc_2341c614
		gpio_set(Data_234922a4->clkGpio, 1);
		sub_2341aba0(Data_234922a4->clkGpio, 0);

		r4 = 0x4000;
		//->loc_2341c640
		while (1)
		{
			if (0 != sub_2341abfc(Data_234922a4->clkGpio))
			{
				//->loc_2341c660
				break;
			}

			if (r4 == 0)
			{
				//->loc_2341c668
				break;
			}
			//->loc_2341c63c
			r4--;
		}
		//loc_2341c660
		if (r4 == 0)
		{
			//loc_2341c668
			r6 = -8;
		}
		//loc_2341c66c
		sub_2341aba0(Data_234922a4->clkGpio, 1);

		for (i = 0; i < 4; i++)
		{
			//loc_2341c680
#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
			__asm { nop }
#endif
		}

		gpio_set(Data_234922a4->clkGpio, 0);

		for (i = 0; i < 68; i++)
		{
			//loc_2341c6a4
#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
			__asm { nop }
#endif
		}

		r5 >>= 1;
		if (r5 == 0)
		{
			//->loc_2341c6c8
			break;
		}

		if (r6 != 0)
		{
			//loc_2341c6d0
			break;
		}
		//->loc_2341c5bc
	} //while (1)
	//loc_2341c6c8
	if (r6 != 0)
	{
		//loc_2341c6d0
		gpio_set(Data_234922a4->dataGpio, 0);

		return -2;
	}

	return 0;
#endif
}


/* 2341c814 - todo */
int sub_2341c814(int sl, void* r8, int sb)
{
#if 1
	console_send_string("sub_2341c814 (i2c.c): TODO\r\n");
#else
	uint16_t r7 = 4;

	while (1)
	{
		uint8_t* r4;
		int r5;
		int r6;

		//loc_2341c828
		r7--;

		r4 = r8;
		r5 = sb;

		sub_2341d154();
		sub_2341c328();

		r6 = sub_2341c5a8(sl);
		r6 |= sub_2341c37c();

		//->loc_2341c874
		while ((r5 > 0) && (r6 == 0))
		{
			//loc_2341c858
			r6 = sub_2341c5a8(*r4);
			r6 |= sub_2341c37c();

			r4++;
			r5--;
		}
		//loc_2341c884
		sub_2341d194();

		if (r7 != 0)
		{
			if (r6 == 0)
			{
				//->loc_2341c8a8
				break;
			}
			else
			{
				//->loc_2341c828
				continue;
			}
		}
		else
		{
			//loc_2341c89c
			if (r6 == 0)
			{
				//->loc_2341c8a8
				break;
			}
			else
			{
				return -1;
			}
		}
	}
	//loc_2341c8a8
	return 0;
#endif
}


/* 2341c958 - todo */
int sub_2341c958(int a, void* b, int c)
{
	console_send_string("sub_2341c958 (i2c.c): TODO\r\n");

}


/* 2341cb64 - complete */
int i2c_master_read_reg(I2c_Bus* hI2c, int addr, int wTxData, void* pRxData, int numRxBytes)
{
	uint8_t res;

#if DEBUG_I2C_MASTER_READ_REG
	console_send_string("i2c_master_read_reg (i2c.c)\r\n");
	{
		extern char debug_string[];
		sprintf(debug_string, "hI2c=%p, addr=0x%02x, wTxData=0x%04x, numRxBytes=%d\r\n", hI2c, addr, wTxData, numRxBytes);
		console_send_string(debug_string);
	}
#endif

	OSSemPend(i2cSema, 0, &res);

	Data_234922a4 = hI2c;

	if (hI2c == 0)
	{
		res = 7;
	}
	else
	{
		res = i2c_read_reg(addr, wTxData, pRxData, numRxBytes);
	}

	OSSemPost(i2cSema);

	return res;
}


/* 2341cc2c - todo */
int i2c_master_receive(I2c_Bus* hI2c, int addr, void* pRxData, int numRxData)
{
	uint8_t sp;

#if DEBUG_I2C_MASTER_RECEIVE
	console_send_string("i2c_master_receive (i2c.c): ");
	{
		extern char debug_string[];
		sprintf(debug_string, "hI2c=%p, addr=0x%02x, pRxData=%p, numRxData=%d\r\n", hI2c, addr, pRxData, numRxData);
		console_send_string(debug_string);
	}
#endif

	OSSemPend(i2cSema, 0, &sp);

	Data_234922a4 = hI2c;

	if (hI2c == 0)
	{
		sp = 7;
		//->loc_2341cc9c
	}
	else
	{
		if (hI2c->bData_8 == 0xff)
		{
			//Bit-banging
#if 0
			sp = sub_2341c958(addr, pRxData, numRxData);
#else
			console_send_string("i2c_master_receive (bit-banging): TODO\r\n");
#endif
		}
		else
		{
			//loc_2341cc84
			sp = i2c_send_receive(addr, 0, 0, pRxData, numRxData);
		}
	}
	//loc_2341cc9c
	OSSemPost(i2cSema);

	return sp;
}


/* 2341ccb0 - todo */
int i2c_master_send(I2c_Bus* hI2c, int addr, void* pTxData, int numTxBytes)
{
	uint8_t sp;

#if DEBUG_I2C_MASTER_SEND
	console_send_string("i2c_master_send (i2c.c): ");
	{
		extern char debug_string[];
		sprintf(debug_string, "hI2c=%p, addr=0x%02x, pTxData=%p, numTxBytes=%d\r\n", hI2c, addr, pTxData, numTxBytes);
		console_send_string(debug_string);
	}
#endif

	OSSemPend(i2cSema, 0, &sp);

	Data_234922a4 = hI2c;

	if (hI2c == 0)
	{
		sp = 7;
	}
	else
	{
		if (hI2c->bData_8 == 0xff)
		{
			// Bit-banging
#if 0
			sub_2341c814(addr, pTxData, numTxBytes);
#else
			console_send_string("i2c_master_send (bit-banging): TODO\r\n");
#endif
		}
		else
		{
			//loc_2341cd08
			i2c_send(addr, pTxData, numTxBytes);
		}
	}
	//loc_2341cd0c
	OSSemPost(i2cSema);

	return sp;
}


/* 2341cd7c - todo (<-sub_23400580 / <-sub_23424798) */
int i2c_open(Struct_2341cd7c* pParams, void** pHandle)
{
	uint8_t i;
	int r0 = 0;
	uint8_t err = 0;
	Struct_20401328 gpio;

#if 0
	console_send_string("i2c_open (todo.c): TODO\r\n");
#endif

	if (i2cSema == 0)
	{
		i2cSema = OSSemCreate(1);
	}
	//loc_2341cdac
	OSSemPend(i2cSema, 0, &err);

	if (err != 0)
	{
		return 12;
	}

	*pHandle = 0;

	for (i = 0; i < 5; i++)
	{
		//loc_2341cdd0
		if ((int)(Data_234922ac[i].clkGpio) == -1)
		{
			*pHandle = Data_234922a4 = &Data_234922ac[i];
			r0 = 1;
			//->loc_2341cdfc
			break;
		}
	}
	//loc_2341cdfc
	if (r0 == 0)
	{
		//loc_2341cfb4
		OSSemPost(i2cSema);
		return 12;
	}
	//0x2341ce04
	r0 = 0;
	do
	{
		if (pParams->bData_0 == 0xff)
		{
			gpio.dwOutFunction = 0; //r7
			gpio.dwInFunction = 0xff; //r8
			gpio.bPin = pParams->clkPin;

			if (0 != gpio_open(&gpio, &Data_234922a4->clkGpio))
			{
				r0 = 1;
				break;
				//->loc_2341cfa0
			}

			gpio.bPin = pParams->dataPin;

			if (0 != gpio_open(&gpio, &Data_234922a4->dataGpio))
			{
				r0 = 1;
				break;
				//->loc_2341cfa0
			}

			Data_234922a4->bData_8 = 0xff;

			gpio_set(Data_234922a4->dataGpio, 1);
			gpio_set(Data_234922a4->clkGpio, 1);
			//->loc_2341cf78
		} //if (pParams->bData_0 == 0xff)
		else
		{
			{
				extern char debug_string[];
				sprintf(debug_string, "i2c_open pParams->bData_0=%d\r\n", pParams->bData_0);
				console_send_string(debug_string);
			}
			//loc_2341ce7c
			Data_234922a4->bData_28 = pParams->bData_1;

			if (pParams->bData_0 == 0)
			{
				//0x2341ce94
				gpio.dwOutFunction = 25; //FAPI_GPIO_OUT_I2C0_CLK
				gpio.dwInFunction = 15; //FAPI_GPIO_IN_I2C0_CLK
				gpio.bPin = pParams->clkPin;

				if (0 != gpio_open(&gpio, &Data_234922a4->clkGpio))
				{
					r0 = 1;
					break;
					//->loc_2341cfa0
				}
				//0x2341cec0
				gpio.dwOutFunction = 24; //FAPI_GPIO_OUT_I2C0_DATA
				gpio.dwInFunction = 14; //FAPI_GPIO_IN_I2C0_DATA
				gpio.bPin = pParams->dataPin;

				if (0 != gpio_open(&gpio, &Data_234922a4->dataGpio))
				{
					r0 = 1;
					break;
					//->loc_2341cfa0
				}

				Data_234922a4->bData_8 = 0;

				sub_2341bde8(Data_234922a4);
				i2c_configure_irq(0);
			}
			//loc_2341cf04
			else if (pParams->bData_0 == 1)
			{
				//0x2341cf0c
				gpio.dwOutFunction = 66; //FAPI_GPIO_OUT_I2C1_CLK
				gpio.dwInFunction = 66; //FAPI_GPIO_IN_I2C1_CLK
				gpio.bPin = pParams->clkPin;

				if (0 != gpio_open(&gpio, &Data_234922a4->clkGpio))
				{
					r0 = 1;
					break;
					//->loc_2341cfa0
				}
				//0x2341cf34
				gpio.dwOutFunction = 65; //FAPI_GPIO_OUT_I2C1_DATA
				gpio.dwInFunction = 65; //FAPI_GPIO_IN_I2C1_DATA
				gpio.bPin = pParams->dataPin;

				if (0 != gpio_open(&gpio, &Data_234922a4->dataGpio))
				{
					r0 = 1;
					break;
					//->loc_2341cfa0
				}

				Data_234922a4->bData_8 = 1;

				sub_2341bde8(Data_234922a4);
				i2c_configure_irq(1);
			}
			else
			{
				//loc_2341cf8c
				Data_234922a4->bData_8 = 2;

				sub_2341bde8(Data_234922a4);
				i2c_configure_irq(2);
			}
		}
	}
	while (0);

	if (r0 != 0)
	{
		//->loc_2341cfa0
		*pHandle = 0;

		memset(Data_234922a4, 0xff, sizeof(I2c_Bus));
		OSSemPost(i2cSema);
		return 12;
	}
	else
	{
		//loc_2341cf78
		OSSemPost(i2cSema);

		return 0;
	}
}


/* 2341cfc4 - todo */
void i2c_set_irqmask0(int a, int b)
{
	if (a == 2)
	{
		*FREG(0xd3000008) = b; //FREG_I2C2_IRQMASK0
	}
	else
	{
		FREG(FREG_I2C_IRQMASK0)[a*FREG_I2C_MOFFSET] = b;
	}
}


/* 2341cfe0 - todo */
void i2c_set_irqmask1(int a, int b)
{
	if (a == 2)
	{
		*FREG(0xd300000c) = b; //FREG_I2C2_IRQMASK1
	}
	else
	{
		FREG(FREG_I2C_IRQMASK1)[a*FREG_I2C_MOFFSET] = b;
	}
}


/* 2341cffc - todo */
void i2c_set_controlreg0(int a, int b)
{
	if (a == 2)
	{
		*FREG(0xd3000010) = b; //FREG_I2C2_CONTROLREG0
	}
	else
	{
		FREG(FREG_I2C_CONTROLREG0)[a*FREG_I2C_MOFFSET] = b;
	}
}


/* 2341d018 - todo */
void i2c_set_controlreg2(int a, int am_tx_num)
{
	if (a == 2)
	{
		*FREG(0xd3000018) = am_tx_num; //FREG_I2C2_CONTROLREG2
	}
	else
	{
		FREG(FREG_I2C_CONTROLREG2)[a*FREG_I2C_MOFFSET] = am_tx_num;
	}
}


/* 2341d034 - todo */
void i2c_set_controlreg3(int a, int am_rx_num)
{
	if (a == 2)
	{
		*FREG(0xd300001c) = am_rx_num; //FREG_I2C2_CONTROLREG3
	}
	else
	{
		FREG(FREG_I2C_CONTROLREG3)[a*FREG_I2C_MOFFSET] = am_rx_num;
	}
}


/* 2341d050 - todo */
void i2c_set_goreg(int a, int b)
{
	if (a == 2)
	{
		*FREG(0xd3000024) = b; //FREG_I2C2_GOREG
	}
	else
	{
		FREG(FREG_I2C_GOREG)[a*FREG_I2C_MOFFSET] = b;
	}
}


/* 2341d06c - todo */
int i2c_get_rxdatareg(int a)
{
	int b;
	if (a == 2)
	{
		b = *FREG(0xd3000028); //FREG_I2C2_RXDATAREG
	}
	else
	{
		b = FREG(FREG_I2C_RXDATAREG)[a*FREG_I2C_MOFFSET];
	}

	return b;
}


/* 2341d088 - todo */
void i2c_get_statusreg0(I2c_Bus* a)
{
	int r1;

#if 0
	console_send_string("i2c_get_statusreg0 (todo.c): TODO\r\n");
#endif

	if (a->bData_8 == 2)
	{
		r1 = *FREG(0xd3000000); //FREG_I2C2_STATUSREG0
	}
	else
	{
		r1 = FREG(FREG_I2C_STATUSREG0)[a->bData_8*FREG_I2C_MOFFSET];
	}

	if (r1 & (1 << 0)) //BE_STOP
	{
		a->dwErrorStatus = 1;
	}
	else if (((r1 & (1 << 1)) >> 1) != 0) //BE_START
	{
		a->dwErrorStatus = 2;
	}
	//loc_2341d0c8
	else if (((r1 & (1 << 2)) >> 2) != 0) //AL_ADRSTA
	{
		a->dwErrorStatus = 3;
	}
	else if (((r1 & (1 << 3)) >> 3) != 0) //AL_DATA
	{
		a->dwErrorStatus = 4;
	}
	else if (((r1 & (1 << 4)) >> 4) != 0) //AL_STOP
	{
		a->dwErrorStatus = 5;
	}
	else if (((r1 & (1 << 10)) >> 10) != 0) //SL_NACK
	{
		a->dwErrorStatus = 6;
	}
	else if (((r1 & (1 << 11)) >> 11) != 0) //RC_NACK
	{
		a->dwErrorStatus = 7;
	}
	else if (((r1 & (1 << 12)) >> 12) != 0) //MS_STOP_REC
	{
		a->dwErrorStatus = 8;
	}
}


/* 2341d12c - complete */
int i2c_is_busy(I2c_Bus* a)
{
	int b;
	if (a->bData_8 < 2)
	{
		b = FREG(FREG_I2C_STATUSREG1)[a->bData_8*FREG_I2C_MOFFSET];
	}
	else
	{
		b = *FREG(0xd3000004); //FREG_I2C2_STATUSREG1
	}

	if (b & (1 << 2)) //OCCUP
	{
		return 0xff;
	}

	return 0;
}


/* 2341d154 - complete */
void sub_2341d154(void)
{
	volatile uint32_t i;

	gpio_set(Data_234922a4->dataGpio, 1);
	gpio_set(Data_234922a4->clkGpio, 1);

	for (i = 0; i < 72; i++)
	{
		//loc_2341d180
#if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
		__asm { nop }
#endif
	}
}


/* 2341d194 - todo */
void sub_2341d194()
{
	console_send_string("sub_2341d194 (todo.c): TODO\r\n");

}


/* 2341d2d0 - todo */
int i2c_read_reg(int addr, uint32_t wTxData, void* pRxData, int numRxBytes)
{
	int res;
	uint8_t arTxBytes[2];
	int numTxBytes = 1;

#if 0
	console_send_string("i2c_read_reg (i2c.c)\r\n");
	{
		char str[40];
		sprintf(str, "Data_234922a4->bData_8=%d\r\n", Data_234922a4->bData_8);
		console_send_string(str);
	}
#endif

	if ((wTxData & 0xff00) != 0)
	{
		arTxBytes[0] = wTxData >> 8;
		arTxBytes[1] = wTxData & 0xff;
		numTxBytes = 2;
	}
	else
	{
		arTxBytes[0] = wTxData & 0xff;
		arTxBytes[1] = 0;
	}

	if (Data_234922a4->bData_8 == 0xff)
	{
#if 0
		res = sub_2341c814(addr, arTxBytes, 2);
		return res | sub_2341c958(addr, pRxData, numRxBytes);
#else
		console_send_string("i2c_read_reg (bit-banging): TODO\r\n");
#endif
		//->loc_2341d370
	}
	//loc_2341d340
	else if (Data_234922a4->bData_8 != 2)
	{
		res = i2c_send(addr, arTxBytes, numTxBytes);
		return res | i2c_send_receive(addr, 0, 0, pRxData, numRxBytes);
	}
	else
	{
		//loc_2341d378
		return i2c_send_receive(addr, arTxBytes, 1, pRxData, numRxBytes);
	}
}


