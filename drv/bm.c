
#include <stdint.h>
#include "ucos_ii.h"
#include "sys_services.h"
#include "bm.h"


void bm_set_global_offset(int a, int b);
void bm_set_read_enable(int a, int b);
void bm_set_endian_swap_rd(int a, int b);
void bm_set_buffer_low_level(int a, int b, int c);
void bm_set_buffer_high_level(int a, int b, int c);
void bmSetAudValue(int a, int b, int c);
void bmSetAudCfgEn(int a, int b);
void bmSetClearAudIrq(int a, int b);


//234ac874
int Data_234ac874 = 0; //234ac874 +0
int Data_234ac878 = 0; //234ac878 +4
int Data_234ac87c = 0; //234AC87C +8
int Data_234ac880 = 0; //234ac880 +0xc
int Data_234ac884 = 0; //234ac884 +0x10
int Data_234ac888 = 0; //234AC888 +0x14
int Data_234ac88c = 0; //234ac88c +0x18
int Data_234ac890 = 0; //234AC890 +0x1c
int Data_234ac894 = 0; //234AC894 +0x20
int Data_234ac898 = 0; //234AC898 +0x24
int Data_234ac89c = 0; //234AC89c +0x28
int Data_234ac8a0 = 0; //234ac8a0 +0x2c
int Data_234ac8a4 = 0; //234ac8a4 +0x30
int Data_234ac8a8 = 0; //234ac8a8 +0x34
int Data_234ac8ac = 0; //234AC8AC +0x38
int Data_234ac8b0 = 0; //234ac8b0 +0x3c
void* bm_sema = 0; //234ac8b4 +0x40
int bm_initialized = 0; //234ac8b8 +0x44
int bm_hwControlledBuffer = 0; //234AC8BC +0x48
uint32_t Data_234ac8c0 = 0; //234ac8c0 +0x4c
uint32_t bmGlobalOffset[2] = //234ac8c4
{
		0x20000000, 0x20000000
};


int Data_236e0b14[8]; //236e0b14
int Data_236e0b34[5/*size???*/]; //236e0b34 / 235b1d0c
int Data_236e0b48[8]; //236e0b48
int Data_236e0b68[5]; //  / 236e0b68

struct
{
	int Data_0; //0
	int Data_4; //4
	//8
} Data_236e0b7c[4]; //236e0b7c

struct
{
	int bmAudChannelAssignment; //0
	int bmAudSearchPattern; //4
	void (*bmAudHandler)(); //8
	void* Data_12; //12
	int bmAudData; //16
	//0x14 = 20
} bm_audStatus[2][5]; //236e0b9c -> 236E0C64


int bm_channelInUse[4][32]; //236e0c64 -> 236E0E64


int Data_236e0e64[8]; //236e0e64 -> 236E0E84

typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	BM_OpenParams openParams; //12 = 0x0c +0x34
	uint32_t channelId; //0x40
	int Data_0x44; //0x44
	int Data_0x48; //0x48
	//0x4c = 76
} BM_Handle;

BM_Handle bm_handleArray[0x80]; //236e0e84 -> 236E3484

BM_Handle* bm_allocate_handle(int);


/* 2342889c - complete */
void bm_set_buffer_size(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8300000 + (b * 4));

#if 0
	console_send_string("bm_set_buffer_size (todo.c): TODO\r\n");
#endif

	if (a == 0)
	{
		FREG(r3)[0] = c; //FREG_BM0_BUFSIZE
	}
	else if (a == 1)
	{
		FREG(r3)[256] = c; //FREG_BM1_BUFSIZE
	}
	else
	{
		r3 = (void*) (0xc8b00000 + (b * 4));

		if (a == 2)
		{
			FREG(r3)[0] = c;
		}
		else
		{
			FREG(r3)[256] = c;
		}
	}
}


/* 234288d4 - complete */
void bm_set_write_pointer(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8300000 + (b * 4));

#if 0
	console_send_string("bm_set_write_pointer (todo.c): TODO\r\n");
#endif

	if (a == 0)
	{
		FREG(r3)[32] = c; //FREG_BM0_WRPTR
	}
	else if (a == 1)
	{
		FREG(r3)[288] = c; //FREG_BM1_WRPTR
	}
	else
	{
		r3 = (void*) (0xc8b00000 + (b * 4));

		if (a == 2)
		{
			FREG(r3)[32] = c;
		}
		else
		{
			FREG(r3)[288] = c;
		}
	}
}


/* 2342890c - complete */
void bm_set_base_address(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8300000 + (b * 4));

#if 0
	console_send_string("bm_set_base_address (todo.c): TODO\r\n");
#endif

	if (a == 0)
	{
		FREG(r3)[64] = c; //FREG_BM0_BASEADDR
	}
	else if (a == 1)
	{
		FREG(r3)[320] = c; //FREG_BM1_BASEADDR
	}
	else
	{
		r3 = (void*) (0xc8b00000 + (b * 4));

		if (a == 2)
		{
			FREG(r3)[64] = c;
		}
		else
		{
			FREG(r3)[320] = c;
		}
	}
}


/* 23428944 - complete */
void bm_set_read_pointer(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8300000 + (b * 4));

#if 0
	console_send_string("bm_set_read_pointer (todo.c): TODO\r\n");
#endif

	c = c & ~0x3f;

	if (a == 0)
	{
		FREG(r3)[96] = c; //FREG_BM0_RDPTR
	}
	else if (a == 1)
	{
		FREG(r3)[352] = c; //FREG_BM1_RDPTR
	}
	else
	{
		r3 = (void*) (0xc8b00000 + (b * 4));

		if (a == 2)
		{
			FREG(r3)[96] = c;
		}
		else
		{
			FREG(r3)[352] = c;
		}
	}
}


/* 23428980 - todo */
void bm_set_irq_mask(int a, int b)
{
	volatile uint32_t* r3 = (void*) (0xc8300000);

#if 0
	console_send_string("bm_set_irq_mask (todo.c): TODO\r\n");
#endif

	if (a == 0)
	{
		Data_234ac874 = b;
		FREG(r3)[128] = b; //FREG_BM0_IRQMASK
	}
	else if (a == 1)
	{
		Data_234ac888 = b;
		FREG(r3)[384] = b; //FREG_BM1_IRQMASK
	}
	else
	{
		r3 = (void*) (0xc8b00000);

		if (a == 2)
		{
			Data_234ac898 = b;
			FREG(r3)[128] = b;
		}
		else
		{
			Data_234ac8ac = b;
			FREG(r3)[384] = b;
		}
	}
}


/* 234289c4 - todo */
int bm_get_irq_mask(int a)
{
#if 0
	console_send_string("bm_get_irq_mask (todo.c): TODO\r\n");
#endif

	if (a == 0)
	{
		return Data_234ac874;
	}
	else if (a == 1)
	{
		return Data_234ac888;
	}
	else if (a == 2)
	{
		return Data_234ac898;
	}
	else
	{
		return Data_234ac8ac;
	}
}


/* 234289f0 - complete */
void bm_setReadEnable_ReadSelect(int a, int b)
{
#if 0
	console_send_string("bm_setReadEnable_ReadSelect (todo.c): TODO\r\n");
#endif

	b = (b << 8) & (1 << 8);

	if ((a == 0) || (a == 1))
	{
		Data_234ac878 = (Data_234ac878 & ~(1 << 8)) | b;
		FREG(0xc8300208)[0] = Data_234ac878; //FREG_BM01_READSELECT
	}
	else
	{
		Data_234ac89c = (Data_234ac89c & ~(1 << 8)) | b;
		FREG(0xc8b00208)[0] = Data_234ac89c; //FREG_BM23_READSELECT
	}
}


/* 23428a38 - todo */
void bm_setReadEnable_ReadEnable(int a, int b)
{
#if 0
	console_send_string("bm_setReadEnable_ReadEnable (todo.c): TODO\r\n");
#endif

	b = b & 0x7f;

	if ((a == 0) || (a == 1))
	{
		Data_234ac878 = (Data_234ac878 & ~0x7f) | b;
		FREG(0xc8300208)[0] = Data_234ac878; //FREG_BM01_READENABLE
	}
	else
	{
		Data_234ac89c = (Data_234ac89c & ~0x7f) | b;
		FREG(0xc8b00208)[0] = Data_234ac89c; //FREG_BM23_READENABLE
	}
}


/* 23428a7c - todo */
int bm_set_endian_swap_wr(int a, int b)
{
	volatile uint32_t* r3 = (void*) (0xc8300000);

#if 0
	console_send_string("bm_set_endian_swap_wr (todo.c): TODO\r\n");
#endif

	if (a == 0)
	{
		Data_234ac884 = b;
		FREG(r3)[134] = b; //FREG_BM0_ENDIANSWAPWR
	}
	else if (a == 1)
	{
		Data_234ac88c = b;
		FREG(r3)[390] = b; //FREG_BM1_ENDIANSWAPWR
	}
	else
	{
		r3 = (void*) (0xc8b00000);

		if (a == 2)
		{
			Data_234ac8a8 = b;
			FREG(r3)[134] = b;
		}
		else
		{
			Data_234ac8b0 = b;
			FREG(r3)[390] = b;
		}
	}
}


/* 23428ac0 - todo */
int bm_get_endian_swap_wr(int a)
{
#if 0
	console_send_string("bm_get_endian_swap_wr (todo.c): TODO\r\n");
#endif

	if (a == 0)
	{
		return Data_234ac884;
	}
	else if (a == 1)
	{
		return Data_234ac88c;
	}
	else if (a == 2)
	{
		return Data_234ac8a8;
	}
	else
	{
		return Data_234ac8b0;
	}
}


/* 23428b1c - complete */
void bm_handle_buffer_overflow(uint8_t a, int b)
{
#if 0
	console_send_string("bm_handle_buffer_overflow (todo.c): TODO\r\n");
#endif

	bm_set_read_pointer(a, b, 0);
	bm_set_write_pointer(a, b, 0);
}


/* 23428b44 - todo */
void sub_23428b44/*bm_isr_23*/()
{
#if 1
	console_send_string("sub_23428b44 (todo.c): TODO\r\n");
#endif
}


/* 23428d84 - todo */
int bm_isr_01()
{
#if 0
	console_send_string("bm_isr_01 (todo.c): TODO\r\n");
#endif

	uint32_t r6;
	uint32_t r4 = 0;
	uint8_t r7 = 0;

	uint32_t r5 = FREG(0xc8300264)[0]; //FREG_BM01_STATUSRDCLR
	uint32_t r1 = r5 & 0xf80000;
	uint32_t r0 = ~(r1 >> 19);

	Data_234ac894 = r0;
	FREG(0xc830021c)[0] = r0; //FREG_BM01_CLEARAUDIRQ

	if ((r5 & 0x10000) != 0)
	{
		r6 = FREG(0xc8300604)[0]; //FREG_BM1_IRQREG
		r7 = 1;
	}
	else
	{
		r6 = FREG(0xc8300204)[0]; //FREG_BM0_IRQREG
	}

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "bm_isr_01: r7=%d, r5=0x%08x, r6=0x%08x\r\n", r7, r5, r6);
		console_send_string(debug_string);
	}
#endif

//	int sl = 1;
	if (r5 & 0xf80000)
	{
		uint32_t sb = (r1 >> 19);

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "bm_isr_01: sb=0x%x\r\n", sb);
			console_send_string(debug_string);
		}
#endif

		for (r4 = 0; r4 < 5; r4++)
		{
			//loc_23428dcc
			uint32_t r0 = sb & (1 << r4);

			if (((r0 >> r4) & 1) &&
					(bm_audStatus[0][r4].bmAudHandler != 0))
			{
				int aud_wrpointer = bm_get_aud_wrpointer(r7, r4);

				(bm_audStatus[0][r4].bmAudHandler)(bm_audStatus[0][r4].bmAudData, r4, aud_wrpointer);
			}
			//loc_23428e14
		}
		//loc_23428e20
	}
	//loc_23428e20
	//sb, =0x236e0e84 = bm_handleArray
	// r8, #0x13
	if (r6 != 0)
	{
		//0x23428e30
		for (r4 = 0; r4 < 32; r4++)
		{
			//loc_23428e34
			uint32_t r0 = r6 & (1 << r4);
			if ((r0 >> r4) & 1)
			{
				//0x23428e44
				for (int32_t r0 = 0x7f; r0 >= 0; r0--)
				{
					//loc_23428e48
					if ((bm_handleArray[r0].Data_4 != 0) &&
							(bm_handleArray[r0].Data_8 == r7) &&
							(bm_handleArray[r0].channelId == r4))
					{
						(bm_handleArray[r0].openParams.handleOverflow)(r7, r4);
						//->loc_23428e94
						break;
					}
					//loc_23428e8c
				}
			}
			//loc_23428e94
		}
		//loc_23428ea0
	}
	//loc_23428ea0
	if (r5 & 0x60000)
	{
		//0x23428ea8
		if ((r5 & 0xff) || (r5 & 0xff00))
		{
			//0x23428eb8
			r5 &= 0xff;

			for (r4 = 0; r4 < 8; r4++)
			{
				//loc_23428ec0
				uint32_t r0 = r5 & (1 << r4);
				if ((r0 >> r4) & 1)
				{
					//0x23428ed0
					r0 = sub_2342a024(0, r4);
					r0 = (r0 & 0x20) >> 5;

					for (int32_t r1 = 0x7f; r1 >= 0; r1--)
					{
						//loc_23428eec
						if ((bm_handleArray[r1].Data_4 != 0) &&
								(bm_handleArray[r1].Data_8 == r0) &&
								(bm_handleArray[r1].channelId == Data_236e0e64[r4]))
						{
							//0x23428f18
							(bm_handleArray[r1].openParams.Data_0x24)(r0, bm_handleArray[r1].channelId);
							//->loc_23428f38
							break;
						}
						//loc_23428f30
					}
				}
				//loc_23428f38
			}
			//0x23428f44 -> loc_23428fc4
		}
		else
		{
			for (r4 = 0; r4 < 8; r4++)
			{
				//loc_23428f48
				uint32_t r1 = r5 & (1 << (r4 + 8));
				if ((r1 >> (r4 + 8)) & 1)
				{
					sub_2342a024(0, r4);

					int r0 = bm_hwControlledBuffer;

					for (int32_t r1 = 0x7f; r1 >= 0; r1--)
					{
						//loc_23428f70
						if ((bm_handleArray[r1].Data_4 != 0) &&
								(bm_handleArray[r1].Data_8 == r0) &&
								(bm_handleArray[r1].channelId == r4))
						{
							//0x23428f98
							(bm_handleArray[r1].openParams.Data_0x2c)(r0, r4);
							//->loc_23428fb8
							break;
						}
						//loc_23428fb0
					}
					//loc_23428fb8
				}
				//loc_23428fb8
			}
			//loc_23428fc4
		}
	}
	//loc_23428fc4
	return 0;
}


/* 23428fcc / 2341dac4 - todo */
int bm_init()
{
#if 0
	console_send_string("bm_init (todo.c): TODO\r\n");
#endif

	if (bm_initialized != 0)
	{
		return 0;
	}
	//loc_23428fe8
	if ((bm_get_global_offset(0) & 0x03) || (bm_get_global_offset(2) & 0x03))
	{
		//loc_23429008
		return 1;
	}
	//loc_23429010
	bm_sema = OSSemCreate(1);

	memset(bm_handleArray, 0, 0x80 * 76);

	for (int32_t r0 = 0x7f; r0 >= 0; r0--)
	{
		//loc_23429038
		bm_handleArray[r0].Data_0 = 0x626d;
	}

	memset(bm_channelInUse, 0, 32 * 4 * 4);

	memset(&bm_audStatus, 0, 200);

	for (int32_t r0 = 4; r0 >= 0; r0--)
	{
		//loc_2342906c
		bm_audStatus[0][r0].bmAudChannelAssignment = -1; //r8
		bm_audStatus[1][r0].bmAudChannelAssignment = -1; //r8
	}
	//0x23429084
	//r6 = 0xc8300000
	Data_234ac890 = 0;
	FREG(0xc83002f4)[0] = 0; //FREG_BM01_AUDCFGEN

	Data_234ac894 = 0;
	FREG(0xc830021c)[0] = 0; //FREG_BM01_CLEARAUDIRQ
	FREG(0xC8B002F4)[0] = 0; //FREG_BM23_AUDCFGEN
	FREG(0xC8B0021C)[0] = 0; //FREG_BM23_CLEARAUDIRQ

	memset(Data_236e0e64, 0, 8 * 4);

	Data_234ac874 = 0xffffffff;
	FREG(0xc8300200)[0] = 0xffffffff; //FREG_BM0_IRQMASK

	Data_234ac888 = 0xffffffff;
	FREG(0xc8300600)[0] = 0xffffffff; //FREG_BM1_IRQMASK

	Data_234ac898 = 0xffffffff;
	FREG(0xC8B00200)[0] = 0xffffffff; //FREG_BM2_IRQMASK

	Data_234ac8ac = 0xffffffff;
	FREG(0xC8B00600)[0] = 0xffffffff; //FREG_BM3_IRQMASK

	Data_234ac878 = 0;
	FREG(0xc8300208)[0] = 0; //FREG_BM01_READENABLE

	Data_234ac89c = 0;
	FREG(0xC8B00208)[0] = 0; //FREG_BM23_READENABLE

	for (int32_t r0 = 0x1f; r0 >= 0; r0--)
	{
		//loc_234290e8
		FREG(0xc8300180)[r0] = 0; //FREG_BM0_RDPTR
		FREG(0xc8300080)[r0] = 0; //FREG_BM0_WRPTR
		FREG(0xc8300000)[r0] = 0; //FREG_BM0_BUFSIZE
		FREG(0xc8300100)[r0] = 0; //FREG_BM0_BASEADDR

		FREG(0xc8300580)[r0] = 0; //FREG_BM1_RDPTR
		FREG(0xc8300480)[r0] = 0; //FREG_BM1_WRPTR
		FREG(0xc8300400)[r0] = 0; //FREG_BM1_BUFSIZE
		FREG(0xc8300500)[r0] = 0; //FREG_BM1_BASEADDR

		FREG(0xc8b00180)[r0] = 0; //FREG_BM2_RDPTR
		FREG(0xc8b00080)[r0] = 0; //FREG_BM2_WRPTR
		FREG(0xc8b00000)[r0] = 0; //FREG_BM2_BUFSIZE
		FREG(0xc8b00100)[r0] = 0; //FREG_BM2_BASEADDR

		FREG(0xc8b00580)[r0] = 0; //FREG_BM3_RDPTR
		FREG(0xc8b00480)[r0] = 0; //FREG_BM3_WRPTR
		FREG(0xc8b00400)[r0] = 0; //FREG_BM3_BUFSIZE
		FREG(0xc8b00500)[r0] = 0; //FREG_BM3_BASEADDR
	}
	//0x23429138
	FREG(0xc8300240)[0] = 0; //FREG_BM01_BUFHIGHLEV
	Data_236e0b14[0] = 0;
	FREG(0xc8300220)[0] = 0; //FREG_BM01_BUFLOWLEV

	FREG(0xc8300240)[1] = 0; //
	Data_236e0b14[1] = 0;
	FREG(0xc8300220)[1] = 0; //

	FREG(0xc8b00240)[2] = 0; //FREG_BM23_BUFHIGHLEV
	Data_236e0b48[2] = 0;
	FREG(0xc8b00220)[2] = 0; //

	FREG(0xc8b00240)[3] = 0; //
	Data_236e0b48[3] = 0;
	FREG(0xc8b00220)[3] = 0; //

	FREG(0xc8300204)[0]; //FREG_BM0_IRQREG
	FREG(0xc8300604)[0]; //FREG_BM1_IRQREG
	FREG(0xC8B00204)[0]; //FREG_BM2_IRQREG
	FREG(0xC8B00604)[0]; //FREG_BM3_IRQREG

	bm_set_global_offset(0, bmGlobalOffset[0]);
	bm_set_global_offset(2, bmGlobalOffset[1]);

	if ((bm_hwControlledBuffer != 0) && (bm_hwControlledBuffer != 1))
	{
		FREG(0xc880011c)[0] = 0x7f; //FREG_BM_HCBSELECT
		//->loc_234291d4
	}
	else
	{
		FREG(0xc880011c)[0] = 0; //FREG_BM_HCBSELECT
	}

	if ((bm_hwControlledBuffer != 0) && (bm_hwControlledBuffer != 2))
	{
		bm_setReadEnable_ReadSelect(bm_hwControlledBuffer, 1);
	}
	else
	{
		//loc_234291e0
		bm_setReadEnable_ReadSelect(bm_hwControlledBuffer, 0);
	}

	intr_set_isr(bm_isr_01, 0, 24); //FAPI_INTR_BM01
	sub_2341b3b8/*sub_234268c0*/(24, 0);

	FREG(0xe0000200)[24] = 0x0f; //r4

	intr_set_isr(sub_23428b44, 0, 25); //FAPI_INTR_BM23
	sub_2341b3b8/*sub_234268c0*/(25, 0);

	FREG(0xe0000200)[25] = 0x0f; //r4

	bm_initialized = 1; //r8

	//->loc_23428fe0
	return 0;
}


/* 2342923c - todo */
void* bm_open(BM_OpenParams* pOpenParams)
{
	int r6;
	uint8_t sp;
	int r7 = -1;
	int sl = 0;
	int fp = 0;
	uint32_t r5_ = 0;

#if 0
	console_send_string("bm_open (1): TODO\r\n");
#endif

	if ((bm_initialized == 0) || (pOpenParams == 0))
	{
		//loc_23429328
		return (void*)6;
	}
	//0x23429268
	r6 = pOpenParams->Data_4;

	if ((r6 != 0) && (r6 != 1) && (r6 != 2) && (r6 != 3) && (r6 != -1))
	{
		//loc_23429328
		return (void*)6;
	}
	//0x23429284
	if ((pOpenParams->bufferSize > 0x1000000) ||
			!((pOpenParams->pidChannel >= -1) && (pOpenParams->pidChannel <= 31)))
		//((pOpenParams->pidChannel + 1) >= 33))
	{
		//loc_23429328
		return (void*)6;
	}

	if (pOpenParams->Data_0x2c != 0)
	{
		if (pOpenParams->Data_0x24 != 0)
		{
			if ((pOpenParams->Data_0x30 + pOpenParams->Data_0x28) >= pOpenParams->bufferSize)
			{
				//loc_23429328
				return (void*)6;
			}
		}
		//loc_234292c8
		if (pOpenParams->pidChannel >= 8)
		{
			//loc_23429328
			return (void*)6;
		}
	}
	//loc_234292d0
	if ((pOpenParams->Data_0x14 != 0) && (pOpenParams->Data_0x14 != 1))
	{
		//->loc_234293c8
		return 0;
	}

	//0x234292e0
	if ((pOpenParams->Data_0x18 != 0) && (pOpenParams->Data_0x18 != 1))
	{
		//loc_23429328
		return (void*)6;
	}

	if ((pOpenParams->Data_0x1c != 0) && (pOpenParams->Data_0x1c != 1))
	{
		//loc_23429328
		return (void*)6;
	}
	//0x23429300
	//r8, =0x236e0c64
	if ((pOpenParams->pidChannel != -1) && (bm_channelInUse[r6][pOpenParams->pidChannel] == 1))
	{
		//loc_23429328
		return (void*)6;
	}
	//loc_2342931c
	if ((pOpenParams->bufferAddress & 0x03) != 0)
	{
		//loc_23429328
		return (void*)6;
	}
	//loc_23429330
	if (r6 == -1)
	{
		r6 = bm_hwControlledBuffer;
	}

	if (0 != bm_buffer_overlap(r6, pOpenParams->bufferAddress, pOpenParams->bufferSize))
	{
		//loc_234293c8
		return 0;
	}
	//0x23429348
	OSSemPend(bm_sema, 0, &sp);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "bm_open: pOpenParams->pidChannel=%d\r\n",
				pOpenParams->pidChannel);
		console_send_string(debug_string);
	}
#endif

	if (pOpenParams->pidChannel == -1)
	{
		//0x23429364
		if (r6 == bm_hwControlledBuffer)
		{
			r5_ = 8;
		}

		for (; r5_ < 32; r5_++)
		{
			//loc_23429374
			if (bm_channelInUse[r6][r5_] == 0)
			{
				r7 = r5_;
				//->loc_23429394
				break;
			}
		}
		//loc_23429394
		if (r7 == -1)
		{
			//loc_2342939c
			OSSemPost(bm_sema);
			//->loc_234293c8
			return 0;
		}
		//loc_234293a8
	} //if (pOpenParams->pidChannel == -1)
	//loc_234293a8
	OSSemPost(bm_sema);

	BM_Handle* r5 = bm_allocate_handle(r6);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "bm_open: r6=%d, r5=%p\r\n",
				r6, r5);
		console_send_string(debug_string);
	}
#endif

	if (0 == bm_check_handle(r5))
	{
		//loc_234293c8
		return 0;
	}
	//loc_234293d0
	OSSemPend(bm_sema, 0, &sp);

	r5->openParams = *pOpenParams;

	Data_236e0b7c[r6].Data_0 = 1;

#if 1
	int r0_ = pOpenParams->pidChannel;
	if (r0_ == -1)
	{
		r0_ = r7;
	}
	r5->channelId = r0_;

#else
	if (pOpenParams->pidChannel == -1)
	{
		r5->Data_0x40 = pOpenParams->pidChannel;
	}
	else
	{
		r5->Data_0x40 = r7;
	}
#endif

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "bm_open: r5->Data_0x40=%d\r\n",
				r5->Data_0x40);
		console_send_string(debug_string);
	}
#endif

	r5->Data_8 = r6;

	bm_channelInUse[r6][r5->channelId] = 1; //r7

	bm_set_read_pointer(r6, r5->channelId, 0);
	bm_set_write_pointer(r6, r5->channelId, 0);
	bm_set_buffer_size(r6, r5->channelId, pOpenParams->bufferSize);
	bm_set_base_address(r6, r5->channelId, pOpenParams->bufferAddress);

	int r0 = bm_get_irq_mask(r6);
	r0 = r0 & ~(1 << r5->channelId);
	bm_set_irq_mask(r6, r0);

	r0 = bm_get_endian_swap_wr(r6);
	r0 = (r0 & ~(1 << r5->channelId));
	r0 |= (pOpenParams->Data_0x14 << r5->channelId);
	bm_set_endian_swap_wr(r6, r0);

	if (r5->channelId < 8)
	{
		//0x234294a8
		r0 = bm_get_read_enable(r6);
		r0 = r0 | (1 << r5->channelId);
		bm_set_read_enable(r6, r0);

		if ((r6 == 0) || (r6 == 2))
		{
			bm_setReadEnable_ReadSelect(r6, 0);
		}
		else
		{
			bm_setReadEnable_ReadSelect(r6, 1);
		}

		r0 = bm_get_endian_swap_rd(r6);
		r0 = r0 & ~(1 << r5->channelId);
		r0 |= (pOpenParams->Data_0x18 << r5->channelId);
		r0 = r0 & ~(1 << (r5->channelId + 8));
		r0 |= (pOpenParams->Data_0x1c << (r5->channelId + 8));
		bm_set_endian_swap_rd(r6, r0);
	}
	//loc_2342950c
	if (pOpenParams->handleOverflow == 0)
	{
		r5->openParams.handleOverflow = bm_handle_buffer_overflow;
	}

	if ((pOpenParams->Data_0x2c != 0) &&
			(pOpenParams->Data_0x30 < pOpenParams->bufferSize) &&
			(r5->channelId < 8))
	{
		uint32_t r2 = (fp | 0x80000000);
		r5->Data_0x48 = (pOpenParams->Data_0x30 & ~0xff00001f);
		r5->Data_0x48 |= r2;
		bm_set_buffer_low_level(r6, r5->channelId, r5->Data_0x48);
	}
	else
	{
		r5->Data_0x48 = 0;
	}
	//loc_23429560
	if ((pOpenParams->Data_0x24 != 0) &&
			(pOpenParams->Data_0x28 < pOpenParams->bufferSize))
	{
		if (Data_234ac8c0 > 8)
		{
			//->loc_2342939c
			OSSemPost(bm_sema);
			//->loc_234293c8
			return 0;
		}
		//0x23429584
		Data_234ac8c0++;

		uint32_t r1 = (sl | 0x80000000);
		uint32_t r2 = (r5->channelId & 0x1f);
		r2 |= (pOpenParams->Data_0x28 & ~0xff0000ff);
		r2 |= r1;

		if ((r6 == 1) || (r6 == 3))
		{
			r2 |= (1 << 5);
		}

		for (uint32_t r1 = 0; r1 < 8; r1++)
		{
			//loc_234295bc
			if (Data_236e0e64[r1] == 0)
			{
				Data_236e0e64[r1] = r5->channelId;

				bm_set_buffer_high_level(r6, r1, r2);
				//->loc_234295e4
				break;
			}
			//loc_234295d8
		}
		//0x234295e4
	}
	//loc_234295e4
	sys_flush_data_cache(r5, 0x4c);

	OSSemPost(bm_sema);

	return r5;
}


/* 2341e0f8 / 23429600 - todo */
void sub_2341e0f8(void* h, int bufSize)
{
	uint8_t err;
	BM_Handle* r4 = h;
	int ip;

#if 0
	console_send_string("sub_2341e0f8 (todo.c): TODO\r\n");
#endif

	OSSemPend(bm_sema, 0, &err);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2341e0f8: r4->openParams.bufferSize=0x%x, bufSize=0x%x\r\n",
				r4->openParams.bufferSize, bufSize);
		console_send_string(debug_string);
	}
#endif

	if (r4->openParams.bufferSize != bufSize)
	{
		r4->openParams.bufferSize = bufSize;

		if ((r4->Data_8 == 0) || (r4->Data_8 == 1))
		{
			ip = 0;
		}
		else
		{
			ip = 1;
		}

		bm_set_read_pointer(ip, r4->channelId, 0);
		bm_set_write_pointer(ip, r4->channelId, 0);
		bm_set_buffer_size(ip, r4->channelId, r4->openParams.bufferSize);
	}
	//loc_2341e16c
	OSSemPost(bm_sema);
}


/* 23429994 - todo */
uint32_t sub_23429994(uint16_t a)
{
	if ((a == 0) || (a == 1) || (a == 2) || (a == 3))
	{
		return bm_get_global_offset(a);
	}

	return 0;
}


/* 2341e4a8 / 234299b0 - complete */
int sub_2341e4a8(void* h, uint32_t offset, int r6)
{
	uint8_t sp;
	BM_Handle* r4 = h;

#if 0
	console_send_string("sub_2341e4a8 (todo.c): TODO\r\n");
#endif

	if (0 == bm_check_handle(r4))
	{
		return 0xff;
	}

	if ((r6 == 0) && (offset > r4->openParams.bufferSize))
	{
		return 0xff;
	}
	//loc_234299e8
	OSSemPend(bm_sema, 0, &sp);

	r4->Data_0x44 = offset;

	bm_set_read_pointer(r4->Data_8, r4->channelId, offset);

	sys_flush_data_cache(r4, sizeof(BM_Handle));

	OSSemPost(bm_sema);

	return 0;
}


/* 2341e524 / 23429a2c - complete */
int sub_2341e524(void* h, uint32_t offset, int r6)
{
	uint8_t sp;
	BM_Handle* r4 = h;

#if 0
	console_send_string("sub_2341e524 (todo.c): TODO\r\n");
#endif

	if (0 == bm_check_handle(r4))
	{
		return 0xff;
	}

	if ((r6 == 0) && (offset > r4->openParams.bufferSize))
	{
		return 0xff;
	}

	OSSemPend(bm_sema, 0, &sp);

	bm_set_write_pointer(r4->Data_8, r4->channelId, offset);

	OSSemPost(bm_sema);

	return 0;
}


/* 2341e600 / 23429b08 - complete */
int sub_2341e600(void* h, int r7)
{
	uint8_t sp;
	BM_Handle* r4 = h;

#if 0
	console_send_string("sub_2341e600 (todo.c): TODO\r\n");
#endif

	if (0 == bm_check_handle(r4))
	{
		return 0x07;
	}

	if ((r4->Data_8 != bm_hwControlledBuffer) ||
			(r4->channelId > 6))
	{
		//loc_23429b44
		return 3;
	}
	//loc_23429b4c
	OSSemPend(bm_sema, 0, &sp);

	int enableMask;
	if (r7 != 0)
	{
		enableMask = bm_get_read_enable_readenable(r4->Data_8) | (1 << r4->channelId);
		//->loc_23429b88
	}
	else
	{
		//loc_23429b7c
		enableMask = bm_get_read_enable_readenable(r4->Data_8) & ~(1 << r4->channelId);
	}
	//loc_23429b88
	bm_setReadEnable_ReadEnable(r4->Data_8, enableMask);

	OSSemPost(bm_sema);

	return 0;
}


/* 2341e698 / 23429ba0 - complete */
int bm_SetAudCallback(void* h, uint32_t audIndex, int searchPattern, void (*callbackFunction)(), int optData)
{
	BM_Handle* bm_handle_ptr = h;
	int block_index = 0;

#if 0
	console_send_string("bm_SetAudCallback (todo.c): TODO\r\n");
#endif

	if ((0 != bm_check_handle(bm_handle_ptr)) && (audIndex >= 5))
	{
		return 0x07;
	}

	if ((bm_handle_ptr->Data_8 != 0) && (bm_handle_ptr->Data_8 != 1))
	{
		block_index = 1;
	}

	bm_audStatus[block_index][audIndex].bmAudChannelAssignment = bm_handle_ptr->channelId;
	bm_audStatus[block_index][audIndex].bmAudSearchPattern = searchPattern;
	bm_audStatus[block_index][audIndex].bmAudHandler = callbackFunction;
	bm_audStatus[block_index][audIndex].bmAudData = optData;

	return 0;
}


/* 2341e70c / 23429c14 - todo */
int bm_StartAudFiltering(void* a)
{
	uint32_t index = 0;
	BM_Handle* bm_handle_ptr = a;
	int aud_index = -1;
	int block_index = 0;

#if 0
	console_send_string("bm_StartAudFiltering (todo.c): TODO\r\n");
#endif

	if (0 == bm_check_handle(bm_handle_ptr))
	{
		return 7;
	}

	if ((bm_handle_ptr->Data_8 != 0) && (bm_handle_ptr->Data_8 != 1))
	{
		block_index = 1;
	}

	bmSetAudCfgEn(bm_handle_ptr->Data_8, 0);

	bmSetClearAudIrq(bm_handle_ptr->Data_8, 0);

	for (index = 0; index < 5; index++)
	{
		//loc_23429c6c
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "bm_StartAudFiltering: bm_audStatus[%d][%d].bmAudChannelAssignment=0x%x, bm_handle_ptr->channelId=0x%x\r\n",
					block_index, index, bm_audStatus[block_index][index].bmAudChannelAssignment, bm_handle_ptr->channelId);
			console_send_string(debug_string);
		}
#endif

		if (bm_audStatus[block_index][index].bmAudChannelAssignment == bm_handle_ptr->channelId)
		{
			int irq_register = ~(1 << index);

			bm_audStatus[block_index][index].Data_12 = bm_handle_ptr;

			aud_index = index;

			if ((bm_handle_ptr->Data_8 == 1) || (bm_handle_ptr->Data_8 == 3))
			{
				bmSetAudCfgEn(bm_handle_ptr->Data_8,
						bm_audStatus[block_index][index].bmAudChannelAssignment | 0x120);
			}
			else
			{
				bmSetAudCfgEn(bm_handle_ptr->Data_8,
						bm_audStatus[block_index][index].bmAudChannelAssignment | 0x100);
			}

			bmSetClearAudIrq(bm_handle_ptr->Data_8, irq_register);

			bmSetAudValue(bm_handle_ptr->Data_8,
					aud_index, bm_audStatus[block_index][index].bmAudSearchPattern | 0x100);
		}
		//loc_23429ccc
	} //for (index = 0; index < 5; index++)

	if (aud_index == -1)
	{
		return 1;
	}

	return 0;
}


/* 2341e7e0 / 23429ce8 - todo */
int bm_StopAudFiltering(void* a, uint32_t audIndex)
{
	int r7 = 0xffff;
	BM_Handle* bm_handle_ptr = a;
	int block_index = 0;

#if 0
	console_send_string("bm_StopAudFiltering (todo.c): TODO\r\n");
#endif

	if ((audIndex >= 5) || (0 == bm_check_handle(bm_handle_ptr)))
	{
		return r7;
	}

	bmSetAudCfgEn(bm_handle_ptr->Data_8, 0);
	bmSetClearAudIrq(bm_handle_ptr->Data_8, 0);

	if ((bm_handle_ptr->Data_8 != 0) && (bm_handle_ptr->Data_8 != 1))
	{
		block_index = 1;
	}

	int irq_register = ~(1 << audIndex);

	bmSetAudCfgEn(bm_handle_ptr->Data_8,
			~bm_audStatus[block_index][audIndex].bmAudChannelAssignment);

	bmSetClearAudIrq(bm_handle_ptr->Data_8, irq_register);

	bmSetAudValue(bm_handle_ptr->Data_8, audIndex, 0);

	bm_audStatus[block_index][audIndex].bmAudChannelAssignment = -1;

	return 0;
}


/* 23429e88 - todo */
void bm_set_read_enable(int a, int b)
{
#if 0
	console_send_string("bm_set_read_enable (todo.c): TODO\r\n");
#endif

	if ((a == 0) || (a == 1))
	{
		Data_234ac878 = b;
		FREG(0xc8300208)[0] = b; //FREG_BM01_READENABLE
	}
	else
	{
		Data_234ac89c = b;
		FREG(0xc8b00208)[0] = b; //FREG_BM23_READENABLE
	}
}


/* 23429eac - todo */
int bm_get_read_enable(int a)
{
#if 0
	console_send_string("bm_get_read_enable (todo.c): TODO\r\n");
#endif

	if ((a == 0) || (a == 1))
	{
		return Data_234ac878;
	}
	else
	{
		return Data_234ac89c;
	}
}


/* 23429ec4 - todo */
int bm_get_read_enable_readenable(int a)
{
#if 0
	console_send_string("bm_get_read_enable_readenable (todo.c): TODO\r\n");
#endif

	if ((a == 0) || (a == 1))
	{
		return Data_234ac878 & 0x7f;
	}
	else
	{
		return Data_234ac89c & 0x7f;
	}
}


/* 23429ee0 - todo */
void bm_set_global_offset(int a, int b)
{
#if 0
	console_send_string("bm_set_global_offset (todo.c): TODO\r\n");
#endif

	if ((a == 0) || (a == 1))
	{
		Data_234ac87c = b;
		FREG(0xc8300210)[0] = b; //FREG_BM01_GLOBALOFFSET
	}
	else
	{
		Data_234ac8a0 = b;
		FREG(0xc8b00210)[0] = b; //FREG_BM23_GLOBALOFFSET
	}
}

/* 23429f04 - todo */
int bm_get_global_offset(int a)
{
#if 0
	console_send_string("bm_get_global_offset (todo.c): TODO\r\n");
#endif

	if ((a == 0) || (a == 1))
	{
		return Data_234ac87c;
	}
	else
	{
		return Data_234ac8a0;
	}
}


/* 23429f1c - complete */
void bm_set_endian_swap_rd(int a, int b)
{
#if 0
	console_send_string("bm_set_endian_swap_rd (todo.c): TODO\r\n");
#endif

	if ((a == 0) || (a == 1))
	{
		Data_234ac880 = b;
		FREG(0xc8300214)[0] = b; //FREG_BM01_ENDIANSWAPRD
	}
	else
	{
		Data_234ac8a4 = b;
		FREG(0xc8b00214)[0] = b; //FREG_BM23_ENDIANSWAPRD
	}
}


/* 23429f40 - complete */
int bm_get_endian_swap_rd(int a)
{
#if 0
	console_send_string("bm_get_endian_swap_rd (todo.c): TODO\r\n");
#endif

	if ((a == 0) || (a == 1))
	{
		return Data_234ac880;
	}
	else
	{
		return Data_234ac8a4;
	}
}


/* 2341ea50 / 23429f58 - complete */
void bmSetAudValue(int a, int b, int c)
{
#if 0
	console_send_string("bmSetAudValue (todo.c): TODO\r\n");
#endif

	if ((a == 0) || (a == 1))
	{
		Data_236e0b34[b] = c;
		FREG(0xc83002e0 + b * 4)[0] = c;
	}
	else
	{
		Data_236e0b68[b] = c;
		FREG(0xc8b002e0 + b * 4)[0] = c;
	}
}


/* 2341ea78 / 23429f80 - complete */
void bmSetAudCfgEn(int a, int b)
{
#if 0
	console_send_string("bmSetAudCfgEn (todo.c): TODO\r\n");
#endif

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "bmSetAudCfgEn: a=%d, b=0x%x\r\n",
				a, b);
		console_send_string(debug_string);
	}
#endif

	if ((a == 0) || (a == 1))
	{
		Data_234ac890 = b;
		FREG(0xc83002f4)[0] = b; //FREG_BM01_AUDCFGEN
	}
	else
	{
		FREG(0xc8b002f4)[0] = b; //FREG_BM23_AUDCFGEN
	}
}


/* 23429fa0 - complete */
int bm_get_aud_wrpointer(int a, int b)
{
#if 0
	console_send_string("bm_get_aud_wrpointer (todo.c): TODO\r\n");
#endif

	if ((a == 0) || (a == 1))
	{
		return FREG(0xc83002e0 + b * 4)[0] & ~0xff000000; //BM01_AUD_VALUE
	}
	else
	{
		return FREG(0xc8b002e0 + b * 4)[0] & ~0xff000000;
	}
}


/* 2341eab8 / 23429fc0 - complete */
void bmSetClearAudIrq(int a, int b)
{
#if 0
	console_send_string("bmSetClearAudIrq (todo.c): TODO\r\n");
#endif

	if ((a == 0) || (a == 1))
	{
		Data_234ac894 = b;
		FREG(0xc830021c)[0] = b; //FREG_BM01_CLEARAUDIRQ
	}
	else
	{
		FREG(0xc8b0021c)[0] = b; //FREG_BM23_CLEARAUDIRQ
	}
}


/* 23429fe0 - complete */
void bm_set_buffer_low_level(int a, int b, int c)
{
#if 0
	console_send_string("bm_set_buffer_low_level (todo.c): TODO\r\n");
#endif

	if ((a == 0) || (a == 1))
	{
		Data_236e0b14[b] = c;
		FREG(0xc8300220)[b] = c; //FREG_BM01_BUFLOWLEV
	}
	else
	{
		Data_236e0b48[b] = c;
		FREG(0xc8b00220)[b] = c; //FREG_BM23_BUFLOWLEV
	}
}


/* 2342a008 - complete */
void bm_set_buffer_high_level(int a, int b, int c)
{
#if 0
	console_send_string("bm_set_buffer_high_level (todo.c): TODO\r\n");
#endif

	if ((a == 0) || (a == 1))
	{
		FREG(0xc8300240)[b] = c; //FREG_BM01_BUFHIGHLEV
	}
	else
	{
		FREG(0xc8b00240)[b] = c; //FREG_BM23_BUFHIGHLEV
	}
}


/* 2342a044 - todo */
BM_Handle* bm_allocate_handle(int r5)
{
	uint8_t sp;
	BM_Handle* r6 = 0;

#if 0
	console_send_string("bm_allocate_handle (todo.c): TODO\r\n");
#endif

	OSSemPend(bm_sema, 0, &sp);

	int lr = Data_236e0b7c[r5].Data_4;
	if (lr == 32)
	{
		OSSemPost(bm_sema);

		return 0;
	}
	//loc_2342a088
	for (int32_t i = 0x7f; i >= 0; i--)
	{
		//loc_2342a094
		if (bm_handleArray[i].Data_4 == 0)
		{
			r6 = &bm_handleArray[i];
			r6->Data_4 = 1;
			r6->Data_8 = r5;
			bm_handleArray[i].Data_0 = 0x626d;

			Data_236e0b7c[r5].Data_4 = lr + 1;
			//->loc_2342a0d4
			break;
		}
		//loc_2342a0cc
	}
	//loc_2342a0d4
	sys_flush_data_cache(r6, 0x4c);

	OSSemPost(bm_sema);

	return r6;
}


/* 2342a0f0 - complete */
int bm_check_handle(BM_Handle* r4)
{
#if 0
	console_send_string("bm_check_handle (todo.c): TODO\r\n");
#endif

	sys_invalidate_data_cache(r4, 0x4c);

	if ((r4 != 0) && (r4->Data_4 != 0) && (r4->Data_0 == 0x626d))
	{
		return 1;
	}

	return 0;
}


/* 2342a12c - todo */
int bm_buffer_overlap(int r5, uint32_t address, uint32_t size)
{
	uint8_t sp;
	uint32_t start_address, end_address;
	uint32_t index_start_address;
	uint32_t index_end_address;
	uint32_t r8, r7;
	int32_t i;

#if 0
	console_send_string("bm_buffer_overlap (todo.c): TODO\r\n");
#endif

	OSSemPend(bm_sema, 0, &sp);

	if ((r5 == 0) || (r5 == 1))
	{
		start_address = bmGlobalOffset[0]; //Data_234ac8c4;
	}
	else
	{
		start_address = bmGlobalOffset[1]; //Data_234ac8c8;
	}

	start_address += address;
	end_address = start_address + size - 1;

	for (i = 0x7f; i >= 0; i--)
	{
		//loc_2342a17c
		BM_Handle* r1 = &bm_handleArray[i];

		if (r1->Data_4 == 1)
		{
			//0x2342a190
			if ((r1->Data_8 == 0) || (r1->Data_8 == 1))
			{
				index_start_address = bmGlobalOffset[0]; //Data_234ac8c4;
			}
			else
			{
				index_start_address = bmGlobalOffset[1]; //Data_234ac8c8;
			}

			r8 = r1->openParams.bufferAddress;
			r7 = r1->openParams.bufferSize;

			index_start_address += r8;
			index_end_address = index_start_address + r7 - 1;

			if (((index_start_address >= start_address) && (index_start_address <= end_address)) ||
					((index_end_address >= start_address) && (index_end_address <= end_address)))
			{
				//loc_2342a1d8
				OSSemPost(bm_sema);

				return 1;
			}
		}
		//loc_2342a1e8
	}
	//0x2342a1f0
	OSSemPost(bm_sema);

	return 0;
}


