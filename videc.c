

#include "data.h"
#include "sys_services.h"
#include "ucos_ii.h"
#include "videc.h"
#include "videc_priv.h"


typedef struct
{
	uint8_t sp[32]; //0
	uint32_t addr; //0x20
	uint32_t size; //0x24
	//40 = 0x28
} Struct_23877674;


//234940bc
int Data_234940bc = 0; //234940bc +0
int Data_234940c0 = 0; //234940c0 +4
uint32_t Data_234940c4 = 0; //234940C4 +8
int Data_234940d0 = 0; //234940d0 +0x14
int Data_234940d4 = 0; //234940d4 +0x18
uint32_t Data_234940d8 = 0; //234940d8 +0x1c
int Data_234940dc = 0; //234940dc +0x20

uint32_t Data_234940e0[1] = {0}; //234940e0
Struct_23877674 Data_23877674; //23877674

uint32_t Data_2387769c[0x1800]; //2387769c
Struct_23877674 Data_2387d69c; //2387d69c = 0x2387769c + 0x6000

uint32_t Data_2387d6c4[0x100]; //2387d6c4
Struct_23877674 Data_2387dac4; //2387dac4 = 0x2387d6c4 + 0x400

uint32_t Data_2387daec[0x400]; //2387daec
Struct_23877674 Data_2387eaec; //2387eaec = 0x2387daec + 0x1000

uint32_t Data_2387eb14[0x8000]; //2387eb14
Struct_23877674 Data_2389eb14; //2389eb14 = 0x2387eb14 + 0x20000

uint32_t Data_2389eb3c[0x400]; //2389eb3c
Struct_23877674 Data_2389fb3c; //2389fb3c = 0x2389eb3c + 0x1000 -> 2389FB64


uint32_t Data_234940e4[22] = //234940e4
{
	0x00000000, 0x00000340, 0x00000680, 0x000009c0, 0x00000d00, 0x00001040, 0x00001380, 0x000016c0,
	0x00001a00, 0x00002000, 0x00002340, 0x00002680, 0x000029c0, 0x00002d00, 0x00003040, 0x00003380,
	0x000036c0, 0x00003a00, 0x00004000, 0x00004340, 0x00004680, 0x000049c0

};

uint32_t Data_2349413c[22] = //2349413c
{
	0x00000000, 0x000000a8, 0x00000150, 0x000001f8, 0x000002a0, 0x00000348, 0x000003f0, 0x00000498,
	0x00000540, 0x000005e8, 0x00000690, 0x00000738, 0x000007e0, 0x00000888, 0x00000930, 0x000009d8,
	0x00000a80, 0x00000b28, 0x00000bd0, 0x00000c78, 0x00000d20, 0x00000dc8
};

uint32_t Data_23494194[22] = //23494194
{
	0x00000000, 0x00000168, 0x000002d0, 0x00000438, 0x000005a0, 0x00000708, 0x00000870, 0x000009d8,
	0x00000b40, 0x00000ca8, 0x00000e10, 0x00000f78, 0x000010e0, 0x00001248, 0x000013b0, 0x00001518,
	0x00001680, 0x000017e8, 0x00001950, 0x00001ab8, 0x00001c20, 0x00001d88
};

struct
{
	volatile int Data_0; //0
	uint32_t Data_4; //4
	int Data_8; //8
	int Data_0xc[64]; //12 = 0xc
	int Data_0x10c[64]; //0x10c
	int Data_0x20c[64]; //20C
	int Data_0x30c[64]; //0x30c
	int Data_0x40c[64]; //0x40c
	uint8_t bData_0x50c[64]; //0x50C
	int Data_238a00b0; //0x54c = 238A00B0
	volatile int Data_0x550; //0x550 = 238A00B4
	int Data_0x554; //0x554 = 238A00B8
	volatile int Data_0x558[384]; //0x558 = 238A00BC
	volatile int Data_0xb58[384]; //0xb58 = 238A06BC
	uint8_t bData_238a0cbc[384]; //0x1158 238A0CBC
	int Data_238a0e3c; //0x12d8 = 238a0e3c
	volatile int Data_238a0e40; //0x12dc = 238a0e40
	volatile int Data_238a0e44; //0x2e0 = 238a0e44
	volatile int Data_238a0e48; //0x2e4 = 238A0E48
	int Data_238a0e4c; //0x2e8 = 238A0E4C
	int Data_238a0e50; //0x2ec = 238a0e50
	volatile uint32_t Data_238a0e54; //0x2f0 = 238A0E54
	int Data_238a0e58; //0x2f4 = 238a0e58
	int Data_238a0e5c; //0x2f8 = 238a0e5c
	int Data_238a0e60; //0x2fc = 238a0e60
	int Data_238a0e64; //0x300 = 238A0E64
	int Data_238a0e68; //0x304 = 238a0e68
	volatile int Data_238a0e6c; //0x308 = 238a0e6c
	int Data_238a0e70; //0x30c = 238a0e70
	int Data_238a0e74; //0x310 = 238A0E74
	int Data_238a0e78; //0x314 = 238A0E78
	int Data_238a0e7c; //0x318 = 238A0E7C
	uint32_t Data_238a0e80; //0x31c = 238A0E80
	int (*Data_238a0e84)(); //0x320 = 238A0E84
#if 0
	int Data_238a0e88; //0x324 = 238a0e88
	int fill_0x328[768]; //0x328 = 238a0e8c
	int Data_238a1a8c; //0xf28 = 238A1A8C
	int fill_238a1a90; //0xf2c = 238A1A90
	int Data_238a1a94; //0xf30 = 238A1A94
#else
	Struct_234774c4 Data_238a0e88; //238a0e88
#endif
	int fill_238a1a98[5]; //0xf34 = 238A1A98
	OS_EVENT* Data_0xf48; //0xf48 = 238A1AAC
	int (*Data_0xf4c)(); //0xf4c = 238A1AB0
	int fill_0xf50; //0xf50
	int (* volatile Data_238a1ab8)(); //0xf54 = 238A1AB8
	void (* volatile Data_238a1abc)(); //0xf58 = 238A1ABC
	void* (* volatile Data_238a1ac0)(); //0xf5c = 238A1AC0

} volatile Data_2389fb64; //2389fb64

struct
{
	int Data_0;
	uint32_t Data_4; //4
	int Data_8; //8
	uint32_t Data_0xc; //12 = 238a1ad0
	int Data_238a1ad4; //0x10 = 238a1ad4
	int Data_238a1ad8; //0x14 = 238a1ad8
	void* Data_238a1adc; //0x18 = 238A1ADC

} Data_238a1ac4; //238a1ac4


typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	int Data_0xc; //0xc
	int Data_0x10; //0x10
	int Data_0x14; //0x14
	int Data_0x18; //0x18
	int Data_0x1c; //0x1c
	int Data_0x20; //0x20
	int Data_0x24; //0x24
	int Data_0x28; //0x28
	int Data_0x2c; //0x2c
	int Data_0x30; //0x30
	int Data_0x34; //0x34
	int Data_0x38; //0x38
	int Data_0x3c; //0x3c
	int Data_0x40; //0x40
	int Data_0x44; //0x44
	int Data_0x48; //0x48
	int Data_0x4c; //0x4c
	int Data_0x50; //0x50
	int Data_0x54; //0x54
	int Data_0x58; //0x58
	int Data_0x5c; //0x5c
	//0x60 = 96
} Struct_210a8000;


void videc_delete_frame_bank(uint32_t frameBankNum);


/* 2345d780 / 23437ce8 - todo */
void sub_2345d780(int r0, int r1, int r2, int r3, uint32_t r4, uint32_t lr)
{
	uint32_t r5 = r4 & 0x3f;

#if 0
	uint32_t r4;
	for (r4 = r4_; r4 > 0x5f; )
	{
		r4 -= 0x60;
	}
#else
	while (r4 > 0x5f)
	{
		r4 -= 0x60;
	}
#endif

#if 1
	volatile Struct_210a8000* ip;
	ip = &((volatile Struct_210a8000*)(0x210a8000))[r5];
	ip->Data_0 = r5; //serial_num[31:0]
	ip->Data_4 = lr; //dec_mode[3:0]
	ip->Data_8 = 0; //lr
	ip->Data_0xc = 0; //lr
	ip->Data_0x10 = r0; //pic_addr[31:0]
	ip->Data_0x14 = r3; //pic_size[31:0]
	ip->Data_0x18 = 0; //lr
	ip->Data_0x1c = 0; //lr
	ip->Data_0x20 = r2; //PTS_valid_flag
	ip->Data_0x24 = 0; //lr
	ip->Data_0x28 = r1; //PTS[32:0]
	ip->Data_0x2c = 0; //lr
	ip->Data_0x30 = 0; //lr
	ip->Data_0x34 = 0; //lr
	ip->Data_0x38 = 0; //lr
	ip->Data_0x3c = 0; //lr
	ip->Data_0x40 = 0; //lr
	ip->Data_0x44 = 0; //lr
	ip->Data_0x48 = 0; //lr
	ip->Data_0x4c = 0; //lr
	ip->Data_0x50 = 0; //lr
	ip->Data_0x54 = 0; //lr
	ip->Data_0x58 = 0; //lr
	ip->Data_0x5c = 0; //lr
#else
	uint32_t ip = 0x210a8000 + r5 * 96;
	FREG(ip + 0)[0] = r5;
	FREG(ip + 4)[0] = lr;
	FREG(ip + 8)[0] = 0;
	FREG(ip + 0xc)[0] = 0;
	FREG(ip + 0x10)[0] = 0;
	FREG(ip + 0x14)[0] = r3;
	FREG(ip + 0x18)[0] = 0;
	FREG(ip + 0x1c)[0] = 0;
	FREG(ip + 0x20)[0] = r2;
	FREG(ip + 0x24)[0] = 0;
	FREG(ip + 0x28)[0] = r1;
	FREG(ip + 0x2c)[0] = 0;
	FREG(ip + 0x30)[0] = 0;
	FREG(ip + 0x34)[0] = 0;
	FREG(ip + 0x38)[0] = 0;
	FREG(ip + 0x3c)[0] = 0;
	FREG(ip + 0x40)[0] = 0;
	FREG(ip + 0x44)[0] = 0;
	FREG(ip + 0x48)[0] = 0;
	FREG(ip + 0x4c)[0] = 0;
	FREG(ip + 0x50)[0] = 0;
	FREG(ip + 0x54)[0] = 0;
	FREG(ip + 0x58)[0] = 0;
	FREG(ip + 0x5c)[0] = 0;
#endif

	FREG(0x60048000 + r4 * 4)[0] = r5; //VCPB_dec_req_idx_FIFO

	r4 = r4 + 1;
	if (r4 > 0x5f)
	{
		r4 = 0;
	}

	FREG(0x60048180)[0] = r4;
	FREG(0x600d0050)[0] = 0x20000000; //INT_REQ_TO_PCPU
}


/* 2345d830 / 23437d98 - todo */
int sub_2345d830(int a)
{
#if 0
	console_send_string("sub_2345d830 (todo.c): TODO\r\n");
#endif

	if (Data_2389fb64.Data_238a0e4c != 0)
	{
		int r0 = Data_2389fb64.Data_238a0e40 - Data_2389fb64.Data_238a0e48;
		if (r0 < 0)
		{
			r0 += 384;
		}

		if ((Data_2389fb64.Data_238a0e44 + 2) >= r0)
		{
			//->loc_2345d9c0
			return 1;
		}

		r0 = r0  - Data_2389fb64.Data_238a0e44;
		int r5 = r0 - 2;
		r0 = sub_23460320(r0);
		if (r0 == 0)
		{
			//->loc_2345d9c0
			return 3;
		}
		//0x2345d884
		if (r5 >= r0)
		{
			r5 = r0;
		}
		//->loc_2345d9b4
		while (r5--)
		{
			//loc_2345d89c
			int r2 = Data_2389fb64.Data_238a0e48;
			Data_2389fb64.Data_238a0e48++;
			if (Data_2389fb64.Data_238a0e48 == 384)
			{
				Data_2389fb64.Data_238a0e48 = 0;
			}

			int r1 = Data_2389fb64.Data_0x558[Data_2389fb64.Data_238a0e48];
			int r3 = Data_2389fb64.Data_0x558[r2];
			int ip = r1 - r3;
			if (ip < 0)
			{
				ip += Data_238a1ac4.Data_0xc;
			}

			sub_2345d780(Data_2389fb64.Data_0x558[r2],
					Data_2389fb64.Data_0xb58[r2],
					Data_2389fb64.bData_238a0cbc[r2],
					ip, r2, 0);

			r0 = sub_23460320();
			r0 = 0x3e - r0;

			r1 = Data_2389fb64.Data_238a0e48 - r0;
			if (r1 < 0)
			{
				r1 += 384;
			}

			if ((Data_2389fb64.Data_238a0e54 & 0xffff) == 0)
			{
				FREG(0xc8300180 + 4 * (Data_2389fb64.Data_238a0e54 >> 16))[0] = Data_2389fb64.Data_0x558[r1]; //BM0_RD_PTR
				//->loc_2345d9b4
			}
			else if ((Data_2389fb64.Data_238a0e54 & 0xffff) == 1)
			{
				FREG(0xc8300580 + 4 * (Data_2389fb64.Data_238a0e54 >> 16))[0] = Data_2389fb64.Data_0x558[r1]; //BM1_RD_PTR
			}
			else if ((Data_2389fb64.Data_238a0e54 & 0xffff) == 2)
			{
				FREG(0xc8b00180 + 4 * (Data_2389fb64.Data_238a0e54 >> 16))[0] = Data_2389fb64.Data_0x558[r1]; //BM2_RD_PTR
			}
			else if ((Data_2389fb64.Data_238a0e54 & 0xffff) == 3)
			{
				FREG(0xc8b00580 + 4 * (Data_2389fb64.Data_238a0e54 >> 16))[0] = Data_2389fb64.Data_0x558[r1]; //BM3_RD_PTR
			}
			//loc_2345d9b4
		} //while (r5--)
		//loc_2345d9bc
	} //if (Data_2389fb64.Data_238a0e4c != 0)
	//loc_2345d9bc
	return 0;
}


/* 2345da3c - todo */
int sub_2345da3c()
{
#if 0
	console_send_string("sub_2345da3c (todo.c): TODO\r\n");
#endif

	if (Data_2389fb64.Data_4 == 0xff)
	{
		if ((900 > (Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550] >> 16)) &&
				(1280 < (Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550] >> 16)))
		{
			if ((uint16_t)(Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550]) >= 1080)
			{
				sub_2345d9c4();
				sub_2345de14();

				return 0x100;
			}
			//loc_2345daac
			else if ((uint16_t)(Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550]) <= 576)
			{
				sub_2345d9c4();
				sub_2345e034();

				return 0x800;
			}
			//loc_2345dad4
		}
		//loc_2345dad4
	}
	//loc_2345dad4
	return 0;
}


/* 2345dadc / 2343802c - todo */
void vdec_load_firmware(uint32_t r0)
{
	uint32_t i;
	uint32_t* r2;
	uint32_t r3;

	if (r0 == 0)
	{
		for (i = 0; i < Data_23877674.size; i += 4)
		{
			FREG(0x60040708 + i)[0] = //FW_ADDRESS_VIDEO_MPEG_JUMP = 0x60040c80???
					Data_234940e0[i / 4/*& ~0x03*/];
		}

		for (i = 0; i < Data_2387d69c.size; i += 4)
		{
			FREG(0x60080000 + i)[0] = //FW_ADDRESS_VIDEO_MPEG_CODE
					Data_2387769c[i / 4/*& ~0x03*/];
		}

		for (i = 0; i < Data_2387dac4.size; i += 4)
		{
			FREG(0x60097c00 + i)[0] = //FW_ADDRESS_VIDEO_MPEG_CTRL
					Data_2387d6c4[i / 4/*& ~0x03*/];
		}
	}
	else
	{
		//loc_2345db68
		for (i = 0; i < Data_2387eaec.size; i += 4)
		{
			FREG(0x60040000 + i)[0] = //FW_ADDRESS_VIDEO_H264_JUMP
					Data_2387daec[i / 4/*& ~0x03*/];
		}

		for (i = 0; i < Data_2389eb14.size; i += 4)
		{
			FREG(0x60080000 + i)[0] = //FW_ADDRESS_VIDEO_H264_CODE
					Data_2387eb14[i / 4/*& ~0x03*/];
		}

		for (i = 0; i < Data_2389fb3c.size; i += 4)
		{
			FREG(0x60097c00 + i)[0] = //FW_ADDRESS_VIDEO_H264_CTRL
					Data_2389eb3c[i / 4/*& ~0x03*/];
		}
	}
}


/* 2345dbf0 - todo */
int sub_2345dbf0()
{
	FREG(0xde000858)[0] = 0x6e; //RAMIF_V_YB
	FREG(0xde00085c)[0] = 0xe6; //RAMIF_V_CT
	FREG(0xde000860)[0] = 0x122; //RAMIF_V_CB

	for (uint32_t r0 = 0; r0 < 22; r0++)
	{
		//loc_2345dc18
		FREG(0xde000800 + r0 * 4)[0] = //RAMIF_V_BANKn
				Data_23494194[r0];
	}

	FREG(0xde000864)[0] = 2; //RAMIF_V_SIZE = 1280
	FREG(0xde000010)[0] = 0x1f;
	FREG(0xde000700)[0] = 0; //r4
	FREG(0xde000008)[0] = 5;

	FREG(0xdb000000)[0] = 0; //r4
	FREG(0xdb000004)[0] = 0x200;
	FREG(0xdb000008)[0] = 0xb00;
	FREG(0xdb00000c)[0] = 0xc00;
	FREG(0xdb000014)[0] = Data_238a1ac4.Data_4 >> 11;
	FREG(0xdb000010)[0] = 0; //r4
	FREG(0xdb00003c)[0] = 4;
	FREG(0xdb000000)[0] = 0x80;
	FREG(0xdb000080)[0] = 0; //r4
	FREG(0xdb000064)[0] = 3;

	FREG(0x600d0000)[0] = FAPI_VIDEC_HW_RESET_ON; //FREG_VD_CMDRESET

	vdec_load_firmware(1);

	FREG(0x60048600)[0] = //FREG_VD_PBVCPBINFOTABLESADDR
			0x210a8000; //vcpbInfoTableStartAddress
	FREG(0x60048604)[0] = //FREG_VD_PBVDPBINFOTABLESADDR
			0x210aa400; //vdpbInfoTableStartAddress
	FREG(0x60048608)[0] = //FREG_VD_PBPCPUWORKADDR
			0x210ab600; //pcpuWorkAreaStartAddress
	FREG(0x6004860c)[0] = //FREG_VD_PBPCPUWORKSIZE
			0x100000; //pcpuWorkAreaSize
	FREG(0x60048610)[0] = //FREG_VD_PBDECSTARTPARAMSADDR
			0x211ab600; //decStartParamsStartAddress
	FREG(0x60048614)[0] = //FREG_VD_PBOUTCOMEOFDECODEADDR
			0x211ab700; //oodInfoTableStartAddress

	FREG(0x211ab600)[0] = Data_238a1ac4.Data_4/*streamAreaStartAddress*/ + 0x20000000;
	FREG(0x211ab604)[0] = Data_238a1ac4.Data_0xc/*decoderBufferSize*/;
	FREG(0x211ab608)[0] = 1;
	FREG(0x211ab610)[0] = 9;
	FREG(0x211ab614)[0] = 0x16;
	FREG(0x211ab618)[0] = 1920;
	FREG(0x211ab61c)[0] = 1088;
	FREG(0x211ab620)[0] = 0; //r4
	FREG(0x211ab624)[0] = 0; //r4
	FREG(0x211ab628)[0] = 0; //r4

	FREG(0x61100068)[0] = 0xffffffff; //FREG_PINT_INTENA

	FREG(0x600d0004)[0] = 0x1f0000; //FREG_VD_CLKEN
	FREG(0x600d0000)[0] = FAPI_VIDEC_HW_RESET_OFF; //r4 //FREG_VD_CMDRESET

	Data_2389fb64.Data_238a1ab8 = sub_2345da3c;

	uint32_t i = 99;
	do
	{
		//loc_2345dd60
		if (Data_2389fb64.Data_0 != 0)
		{
			FREG(0x600d0050)[0] = MAINCPU_CMD_DECODE_START; //FREG_VD_INTREQTOPCPU
			//->loc_2345dd84
			break;
		}

		rtos_task_wait(1);
	} while (i--);
	//loc_2345dd84
	return 0;
}


/* 2345dd8c - todo */
int sub_2345dd8c()
{
	if (Data_2389fb64.Data_4 == 0xff)
	{
		if ((uint16_t)(Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550]) < 1080)
		{
			if ((uint16_t)(Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550]) == 720)
			{
				sub_2345d9c4();
				sub_2345dbf0();

				return 0x400;
			}
			//loc_2345dde4
			if ((uint16_t)(Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550]) <= 576)
			{
				sub_2345d9c4();
				sub_2345e034();

				return 0x800;
			}
			//loc_2345de0c
		}
		//loc_2345de0c
	}
	//loc_2345de0c
	return 0;
}


/* 2345de14 - todo */
int sub_2345de14()
{
#if 0
	console_send_string("sub_2345de14 (todo.c): TODO\r\n");
#endif

	FREG(0xde000858)[0] = 0x110;
	FREG(0xde00085c)[0] = 0x230;
	FREG(0xde000860)[0] = 0x2b0;

	for (uint32_t r0 = 0; r0 < 22; r0++)
	{
		//loc_2345de3c
		FREG(0xde000800 + r0 * 4)[0] = //RAMIF_V_BANKn
				Data_234940e4[r0];
	}

	FREG(0xde000864)[0] = 0; //RAMIF_V_SIZE = 1920
	FREG(0xde000010)[0] = 0x1f;
	FREG(0xde000700)[0] = 0; //r4
	FREG(0xde000008)[0] = 5;

	FREG(0xdb000000)[0] = 0; //r4
	FREG(0xdb000004)[0] = 0x200;
	FREG(0xdb000008)[0] = 0xb00;
	FREG(0xdb00000c)[0] = 0xc00;
	FREG(0xdb000014)[0] = Data_238a1ac4.Data_4 >> 11; //BASE_STM
	FREG(0xdb000010)[0] = 0; //r4
	FREG(0xdb00003c)[0] = 4; //r7
	FREG(0xdb000000)[0] = 0x80;
	FREG(0xdb000080)[0] = 0; //r4
	FREG(0xdb000064)[0] = 3;

	FREG(0x600d0000)[0] = FAPI_VIDEC_HW_RESET_ON; //FREG_VD_CMDRESET

	vdec_load_firmware(1);

	FREG(0x60048600)[0] = //FREG_VD_PBVCPBINFOTABLESADDR
			0x210a8000; //vcpbInfoTableStartAddress
	FREG(0x60048604)[0] = //FREG_VD_PBVDPBINFOTABLESADDR
			0x210aa400; //vdpbInfoTableStartAddress
	FREG(0x60048608)[0] = //FREG_VD_PBPCPUWORKADDR
			0x210ab600; //pcpuWorkAreaStartAddress
	FREG(0x6004860c)[0] = //FREG_VD_PBPCPUWORKSIZE
			0x100000; //pcpuWorkAreaSize
	FREG(0x60048610)[0] = //FREG_VD_PBDECSTARTPARAMSADDR
			0x211ab600; //decStartParamsStartAddress
	FREG(0x60048614)[0] = //FREG_VD_PBOUTCOMEOFDECODEADDR
			0x211ab700; //oodInfoTableStartAddress

	FREG(0x211ab600)[0] = Data_238a1ac4.Data_4/*streamAreaStartAddress*/ + 0x20000000;
	FREG(0x211ab604)[0] = Data_238a1ac4.Data_0xc/*decoderBufferSize*/;
	FREG(0x211ab608)[0] = 1;
	FREG(0x211ab610)[0] = 4;
	FREG(0x211ab614)[0] = 0x10;
	FREG(0x211ab618)[0] = 1920;
	FREG(0x211ab61c)[0] = 1088;
	FREG(0x211ab620)[0] = 0; //r4
	FREG(0x211ab624)[0] = 0; //r4
	FREG(0x211ab628)[0] = 0; //r4

	FREG(0x61100068)[0] = 0xffffffff; //FREG_PINT_INTENA

	FREG(0x600d0004)[0] = 0x1f0000; //FREG_VD_CLKEN
	FREG(0x600d0000)[0] = FAPI_VIDEC_HW_RESET_OFF; //r4 //FREG_VD_CMDRESET

	Data_2389fb64.Data_238a1ab8 = sub_2345dd8c;

	uint32_t i = 99;
	do
	{
		//loc_2345df7c
		if (Data_2389fb64.Data_0 != 0)
		{
			FREG(0x600d0050)[0] = MAINCPU_CMD_DECODE_START; //FREG_VD_INTREQTOPCPU
			//->loc_2345dfa0
			break;
		}

		rtos_task_wait(1);
	} while (i--);
	//loc_2345dfa0
	return 0;
}


/* 2345dfa8 - todo */
int sub_2345dfa8()
{
#if 0
	console_send_string("sub_2345dfa8 (todo.c): TODO\r\n");
#endif

	uint32_t r1;

	if (Data_2389fb64.Data_4 == 0xff)
	{
		if ((uint16_t)(Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550]) > 576)
		{
			//0x2345dfd4
			r1 = (720 << 20);
			if ((Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550] << 20) == r1)
			{
				sub_2345d9c4();
				sub_2345dbf0();

				return 0x400;
			}
			//loc_2345e87c
			r1 = 1080;
			if ((Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550] & 0xFFF) >= r1)
			{
				sub_2345d9c4();
				sub_2345de14();

				return 0x100;
			}
			//loc_2345e02c
		}
		//loc_2345e02c
	}
	//loc_2345e02c
	return 0;
}


/* 2345e034 - todo */
int sub_2345e034()
{
#if 0
	console_send_string("sub_2345e034 (todo.c): TODO\r\n");
#endif

	FREG(0xde000858)[0] = 0x36;
	FREG(0xde00085c)[0] = 0x72;
	FREG(0xde000860)[0] = 0x8a;

	for (uint32_t r0 = 0; r0 < 22; r0++)
	{
		//loc_2345de3c
		FREG(0xde000800 + r0 * 4)[0] = //RAMIF_V_BANKn
				Data_2349413c[r0];
	}

	FREG(0xde000864)[0] = 3; //RAMIF_V_SIZE = ?
	FREG(0xde000010)[0] = 0x1f;
	FREG(0xde000700)[0] = 0; //r4
	FREG(0xde000008)[0] = 5;

	FREG(0xdb000000)[0] = 0; //r4
	FREG(0xdb000004)[0] = 0x200;
	FREG(0xdb000008)[0] = 0xb00;
	FREG(0xdb00000c)[0] = 0xc00;
	FREG(0xdb000014)[0] = Data_238a1ac4.Data_4 >> 11; //BASE_STM
	FREG(0xdb000010)[0] = 0; //r4
	FREG(0xdb00003c)[0] = 4; //r7
	FREG(0xdb000000)[0] = 0x80;
	FREG(0xdb000080)[0] = 0; //r4
	FREG(0xdb000064)[0] = 3;

	FREG(0x600d0000)[0] = FAPI_VIDEC_HW_RESET_ON; //FREG_VD_CMDRESET

	vdec_load_firmware(1);

	FREG(0x60048600)[0] = //FREG_VD_PBVCPBINFOTABLESADDR
			0x210a8000; //vcpbInfoTableStartAddress
	FREG(0x60048604)[0] = //FREG_VD_PBVDPBINFOTABLESADDR
			0x210aa400; //vdpbInfoTableStartAddress
	FREG(0x60048608)[0] = //FREG_VD_PBPCPUWORKADDR
			0x210ab600; //pcpuWorkAreaStartAddress
	FREG(0x6004860c)[0] = //FREG_VD_PBPCPUWORKSIZE
			0x100000; //pcpuWorkAreaSize
	FREG(0x60048610)[0] = //FREG_VD_PBDECSTARTPARAMSADDR
			0x211ab600; //decStartParamsStartAddress
	FREG(0x60048614)[0] = //FREG_VD_PBOUTCOMEOFDECODEADDR
			0x211ab700; //oodInfoTableStartAddress

	FREG(0x211ab600)[0] = Data_238a1ac4.Data_4/*streamAreaStartAddress*/ + 0x20000000;
	FREG(0x211ab604)[0] = Data_238a1ac4.Data_0xc/*decoderBufferSize*/;
	FREG(0x211ab608)[0] = 1;
	FREG(0x211ab610)[0] = 4;
	FREG(0x211ab614)[0] = 0x16;
	FREG(0x211ab618)[0] = 1920;
	FREG(0x211ab61c)[0] = 1088;
	FREG(0x211ab620)[0] = 0; //r4
	FREG(0x211ab624)[0] = 0; //r4
	FREG(0x211ab628)[0] = 0; //r4

	FREG(0x61100068)[0] = 0xffffffff; //FREG_PINT_INTENA

	FREG(0x600d0004)[0] = 0x1f0000; //FREG_VD_CLKEN
	FREG(0x600d0000)[0] = FAPI_VIDEC_HW_RESET_OFF; //r4 //FREG_VD_CMDRESET

	Data_2389fb64.Data_238a1ab8 = sub_2345dfa8;

	uint8_t i = 100;
	while (i--)
	{
		//loc_2345e1a4
		if (Data_2389fb64.Data_0 != 0)
		{
			FREG(0x600d0050)[0] = MAINCPU_CMD_DECODE_START; //FREG_VD_INTREQTOPCPU
			//->loc_2345e1d0
			break;
		}

		rtos_task_wait(1);
	}
	//loc_2345e1d0
	return 0;
}


/* 2345e1d8 - complete */
int sub_2345e1d8()
{
#if 0
	console_send_string("sub_2345e1d8 (todo.c): TODO\r\n");
#endif

	if (((Data_2389fb64.Data_238a0e88.Data_0xc04 == 0x10) &&
			(Data_2389fb64.Data_238a0e88.bData_0xc0c == 1)) ||
			((Data_2389fb64.Data_238a0e88.Data_0xc04 == 0x1c) &&
						(Data_2389fb64.Data_238a0e88.bData_0xc0c == 1)))
	{
		//loc_2345e208
		sub_2345dbf0();

		return 0x400;
	}
	//loc_2345e214
	else if ((Data_2389fb64.Data_238a0e88.Data_0xc04 == 0x38) ||
			(Data_2389fb64.Data_238a0e88.Data_0xc04 == 0x1a) ||
			(Data_2389fb64.Data_238a0e88.Data_0xc04 == 0x10))
	{
		sub_2345de14();

		return 0x100;
	}
	else
	{
		//loc_2345e23c
		sub_2345e034();

		return 0x800;
	}
}


/* 2345e248 - todo */
void videc_audcallback_h264(int r0, int audNum, uint32_t r5/*foundPtr*/)
{
#if 0
	console_send_string("videc_audcallback_h264 (todo.c): TODO\r\n");
#endif

	if (audNum != 0)
	{
		return;
	}

	Data_2389fb64.Data_238a0e7c = 0x100;

	if (Data_2389fb64.Data_0 != 2)
	{
		//0x2345e280
		int r1 = Data_234940bc;
		if (r1 != 0)
		{
			//0x2345e28c
			uint8_t* r0 = (void*)(0x20000000 + Data_238a1ac4.Data_4 + r1);
			if (((r0[0] << 16) | (r0[1] << 8) | (r0[2] << 0)) == 1)
			{
				//0x2345e2b8
				r1 = r5 - r1;
				r0 += 6;
				if (r1 > 0)
				{
					//->loc_2345e324
					while (r1--)
					{
						//loc_2345e2cc
						if (((r0[0] << 16) | (r0[1] << 8) | (r0[2] << 0)) == 1)
						{
							//0x2345e2ec
							int r2 = r0[3];
							r0 += 3;
							r2 &= 0x1f;
							if (r2 == 7)
							{
								//0x2345e2fc
								int r0_ = sub_234774c4(r0 + 1, &Data_2389fb64.Data_238a0e88);
								if (r0_ == 0)
								{
									Data_2389fb64.Data_238a0e84 = sub_2345e1d8;
								}
								//->loc_2345e32c
								break;
							}
							//loc_2345e318
							else if (r2 != 6)
							{
								//loc_2345e32c
								break;
							}
						}
						//loc_2345e320
						r0++;
						//loc_2345e324
					} //while (r1--)
					//loc_2345e32c
				}
				//loc_2345e32c
			}
			//loc_2345e32c
		}
		//loc_2345e32c
		int r0;
		if (r5 < 4)
		{
			r0 = Data_238a1ac4.Data_0xc + r5 - 4;
		}
		else
		{
			r0 = r5 - 4;
		}
		Data_2389fb64.Data_0x558[Data_2389fb64.Data_238a0e40] = r0;
		Data_2389fb64.Data_238a0e40++;
		if (Data_2389fb64.Data_238a0e40 == 384)
		{
			Data_2389fb64.Data_238a0e40 = 0; //r8
		}

		Data_234940bc = r0;

		return;
	} //if (Data_2389fb64.Data_0 != 2)
	else
	{
		//loc_2345e36c
		Data_234940bc = 0; //r8

		int r0;
		if (r5 < 4)
		{
			r0 = Data_238a1ac4.Data_0xc + r5 - 4;
		}
		else
		{
			r0 = r5 - 4;
		}

		if (Data_2389fb64.Data_238a0e4c == 0)
		{
			Data_2389fb64.Data_238a0e4c = 1; //sb
		}

		Data_2389fb64.Data_0x558[Data_2389fb64.Data_238a0e40] = r0;

		int r5 = Data_2389fb64.Data_238a0e40 - 1;
		if (r5 < 0)
		{
			r5 += 384;
		}

		uint32_t pts = tsd_get_pts(Data_238a1ac4.Data_238a1adc);

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "videc_audcallback_h264: Data_2389fb64.Data_238a0e40=%d, pts=%u\r\n",
					Data_2389fb64.Data_238a0e40, pts);
			console_send_string(debug_string);
		}
#endif

		Data_2389fb64.Data_0xb58[Data_2389fb64.Data_238a0e40] = pts;

		if (Data_2389fb64.Data_0xb58[Data_2389fb64.Data_238a0e40] != Data_2389fb64.Data_0xb58[r5])
		{
			Data_2389fb64.bData_238a0cbc[Data_2389fb64.Data_238a0e40] =  1; //sb
		}
		else
		{
			Data_2389fb64.bData_238a0cbc[Data_2389fb64.Data_238a0e40] =  0; //r8
		}

		Data_2389fb64.Data_238a0e40++;
		if (Data_2389fb64.Data_238a0e40 == 384)
		{
			Data_2389fb64.Data_238a0e40 = 0; //r8
		}

		sub_2345d830(1);
	}
}


/* 2345e60c - todo */
void sub_2345e60c()
{
	console_send_string("sub_2345e60c (todo.c): TODO\r\n");

}


/* 2345e828 - todo */
int sub_2345e828()
{
#if 0
	console_send_string("sub_2345e828 (todo.c): TODO\r\n");
#endif

	if (Data_2389fb64.Data_4 == 0xff)
	{
		if ((uint16_t)(Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550]) > 576)
		{
			//0x2345e854
			if ((uint16_t)(Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550]) == 720)
			{
				sub_2345d9c4();
				sub_2345e410();

				return 0x400;
			}
			//loc_2345e87c
			uint32_t r2 = 1080;
			if ((uint16_t)(Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550]) >= r2)
			{
				sub_2345d9c4();
				sub_2345e694();

				return 0x100;
			}
			//loc_2345e8a8
		}
		//loc_2345e8a8
	}
	//loc_2345e8a8
	return 0;
}


/* 2345e8b0 - todo */
int sub_2345e8b0()
{
#if 0
	console_send_string("sub_2345e8b0 (todo.c): TODO\r\n");
#endif

	FREG(0xde000858)[0] = 0x36; //RAMIF_V_YB
	FREG(0xde00085c)[0] = 0x72; //RAMIF_V_CT
	FREG(0xde000860)[0] = 0x8a; //RAMIF_V_CB

	for (uint8_t i = 0; i < 22; i++)
	{
		//loc_2345e8d8
		FREG(0xde000800 + i * 4)[0] = //RAMIF_V_BANKn
				Data_2349413c[i];
	}

	FREG(0xde000864)[0] = 3; //RAMIF_V_SIZE = ?
	FREG(0xde000010)[0] = 0x1f;
	FREG(0xde000700)[0] = 1; //r7
	FREG(0xde000008)[0] = 5;

	FREG(0xdb000000)[0] = 0; //r4
	FREG(0xdb000014)[0] = Data_238a1ac4.Data_4 >> 11;
	FREG(0xdb000010)[0] = 0; //r4
	FREG(0xdb00003c)[0] = 4;
	FREG(0xdb000000)[0] = 0x80;
	FREG(0xdb000080)[0] = 0; //r4
	FREG(0xdb000064)[0] = 3;

	FREG(0x600d0000)[0] = FAPI_VIDEC_HW_RESET_ON; //FREG_VD_CMDRESET

	vdec_load_firmware(0);

	FREG(0x60048600)[0] = //FREG_VD_PBVCPBINFOTABLESADDR
			0x210a8000; //vcpbInfoTableStartAddress
	FREG(0x60048604)[0] = //FREG_VD_PBVDPBINFOTABLESADDR
			0x210aa400; //vdpbInfoTableStartAddress
	FREG(0x60048608)[0] = //FREG_VD_PBPCPUWORKADDR
			0x210ab600; //pcpuWorkAreaStartAddress
	FREG(0x6004860c)[0] = //FREG_VD_PBPCPUWORKSIZE
			0x100000; //pcpuWorkAreaSize
	FREG(0x60048610)[0] = //FREG_VD_PBDECSTARTPARAMSADDR
			0x211ab600; //decStartParamsStartAddress
	FREG(0x60048614)[0] = //FREG_VD_PBOUTCOMEOFDECODEADDR
			0x211ab700; //oodInfoTableStartAddress

	FREG(0x211ab600)[0] = Data_238a1ac4.Data_4/*streamAreaStartAddress*/ + 0x20000000;
	FREG(0x211ab604)[0] = Data_238a1ac4.Data_0xc/*decoderBufferSize*/;
	FREG(0x211ab608)[0] = 1; //r7
	FREG(0x211ab610)[0] = 0; //r4
	FREG(0x211ab614)[0] = 0x16;
	FREG(0x211ab618)[0] = 1920;
	FREG(0x211ab61c)[0] = 1088;
	FREG(0x211ab620)[0] = 0; //r4
	FREG(0x211ab624)[0] = 0; //r4

	FREG(0x61100068)[0] = 0xffffffff; //FREG_PINT_INTENA

	FREG(0x600d0004)[0] = 0x1f0000; //FREG_VD_CLKEN
	FREG(0x600d0000)[0] = FAPI_VIDEC_HW_RESET_OFF; //r4 //FREG_VD_CMDRESET

	Data_2389fb64.Data_238a1ab8 = sub_2345e828;
	//->loc_2345ea08
	while (Data_2389fb64.Data_0 == 0)
	{
		//loc_2345ea00
		rtos_task_wait(1);
	}
	//0x2345ea14
	FREG(0x600d0050)[0] = MAINCPU_CMD_DECODE_START; //FREG_VD_INTREQTOPCPU

	return 0;
}


/* 2345ea24 - todo */
void sub_2345ea24()
{
	console_send_string("sub_2345ea24 (todo.c): TODO\r\n");

}


/* 2345eaac - todo */
void sub_2345eaac()
{
	Data_2389fb64.Data_0 = 0;

	if (Data_2389fb64.Data_238a1ab8 == sub_2345da3c)
	{
		sub_2345dbf0();
		//->loc_2345eb30
	}
	//loc_2345ead8
	else if (Data_2389fb64.Data_238a1ab8 == sub_2345dd8c)
	{
		sub_2345de14();
		//->loc_2345eb30
	}
	//loc_2345eaf0
	else if (Data_2389fb64.Data_238a1ab8 == sub_2345dfa8)
	{
		sub_2345e034();
		//->loc_2345eb30
	}
	//loc_2345eb08
	else if (Data_2389fb64.Data_238a1ab8 == sub_2345e828)
	{
		sub_2345e8b0();
		//->loc_2345eb30
	}
	//loc_2345eb20
	else if (Data_2389fb64.Data_238a1ab8 == sub_2345e60c)
	{
		sub_2345e694();
	}

	//loc_2345eb30

	if (Data_2389fb64.Data_238a1ab8 == sub_2345ea24)
	{
		sub_2345e410();
		//->loc_2345eb60
	}
	//loc_2345eb48
	else if (Data_2389fb64.Data_238a1ab8 == 0)
	{
		sub_2345e8b0();
	}
	//loc_2345eb60
	while (Data_2389fb64.Data_0 == 2)
	{
		//loc_2345eb58
		rtos_task_wait(1);
	}
}


/* 2345eb70 / 234390ac - todo */
void sub_2345eb70(int r6, int fp)
{
#if 0
	console_send_string("sub_2345eb70 (todo.c): TODO\r\n");
#endif

	uint32_t r5 = 200;

	if (Data_2389fb64.Data_0 == 0)
	{
		Data_2389fb64.Data_4 = 1; //r8

		sub_2345eaac();
	}

	Data_2389fb64.Data_238a0e84 = 0; //sb
	Data_2389fb64.Data_238a1abc = 0;
	Data_2389fb64.Data_238a1ac0 = 0;

	FREG(0x600d0050)[0] = MAINCPU_CMD_DECODE_END; //INT_REQ_TO_PCPU
	//->loc_2345ecac
	while (r5--)
	{
		//loc_2345ebbc
		if (Data_2389fb64.Data_0 == 3)
		{
			//0x2345ebc8
			Data_2389fb64.Data_8 = 1; //r8
			Data_2389fb64.Data_0x550 = 0; //sb

			FREG(0x600d0050)[0] = MAINCPU_CMD_DECODE_START; //INT_REQ_TO_PCPU

			while (1)
			{
				//loc_2345ebd8
				if (Data_2389fb64.Data_0 == 2)
				{
					break;
				}
			}
			//0x2345ebe4
			if (Data_2389fb64.Data_4 == 0)
			{
				Data_2389fb64.Data_4 = 3;
			}

			sub_2345d780(r6, 0, 1, fp, 0, 2);
			sub_2345d780(r6, 0, 1, fp, 1, 2);

			if ((Data_2389fb64.Data_238a0e54 & 0xffff) == 0)
			{
				//loc_2345ec44
				FREG(0xc8300180 + 4 * (Data_2389fb64.Data_238a0e54 >> 16))[0] = r6; //BM0_RD_PTR
			}
			//loc_2345ec58
			else if ((Data_2389fb64.Data_238a0e54 & 0xffff) == 1)
			{
				//loc_2345ec68
				FREG(0xc8300580 + 4 * (Data_2389fb64.Data_238a0e54 >> 16))[0] = r6; //BM1_RD_PTR
			}
			//loc_2345ec7c
			else if ((Data_2389fb64.Data_238a0e54 & 0xffff) == 2)
			{
				//->loc_2345ec44
				FREG(0xc8b00180 + 4 * (Data_2389fb64.Data_238a0e54 >> 16))[0] = r6; //BM2_RD_PTR
			}
			else if ((Data_2389fb64.Data_238a0e54 & 0xffff) == 3)
			{
				//->loc_2345ec68
				FREG(0xc8b00580 + 4 * (Data_2389fb64.Data_238a0e54 >> 16))[0] = r6; //BM3_RD_PTR
			}
			return;
		}
		//loc_2345eca4
		rtos_task_wait(1);
	} //while (r5--)
	//0x2345ecb4
	Data_2389fb64.Data_4 = 1; //r8

	sub_2345eaac();
}


/* 2345ef9c - complete */
int sub_2345ef9c()
{
#if 0
	console_send_string("sub_2345ef9c (todo.c): TODO\r\n");
#endif

	if (Data_2389fb64.Data_238a0e88.Data_0xc04 == 0x10)
	{
		sub_2345e410();

		return 0x400;
	}
	//loc_2345efbc
	else if (Data_2389fb64.Data_238a0e88.Data_0xc04 == 0)
	{
		sub_2345e694();

		return 0x100;
	}
	else
	{
		//loc_2345efd4
		sub_2345e8b0();

		return 0x800;
	}
}


/* 2345efe0 - todo */
void videc_audcallback_mpeg(int r0, int audNum, uint32_t r2/*foundPtr*/)
{
#if 0
	console_send_string("videc_audcallback_mpeg (todo.c): TODO\r\n");
#endif

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "videc_audcallback_mpeg: Data_2389fb64.Data_0=%d, audNum=%d, r2=%d\r\n",
				Data_2389fb64.Data_0, audNum, r2);
		console_send_string(debug_string);
	}
#endif

	if (r2 < 4)
	{
		r2 += Data_238a1ac4.Data_0xc;
	}

	r2 = r2 - 4;

	if (Data_2389fb64.Data_0/*lr*/ != 2)
	{
		//0x2345f018
		if (audNum != 0)
		{
			return;
		}

		uint32_t r1 = r2 + 4;

		if (Data_238a1ac4.Data_0xc < r1)
		{
			r1 -= Data_238a1ac4.Data_0xc;
		}

		uint8_t* r0 = (void*)(0x20000000 + /*r3*/Data_238a1ac4.Data_4 + r1);

		int r0_ = ((r0[0] << 16) | (r0[1] << 8) | (r0[2] << 0));

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "videc_audcallback_mpeg: r0_=0x%x\r\n",
					r0_);
			console_send_string(debug_string);
		}
#endif

		if ((1080 << 20) == (r0_ << 20))
		{
			Data_2389fb64.Data_238a0e88.Data_0xc04 = 0; //r6
			//->loc_2345f070
		}
		else if ((720 << 20) == (r0_ << 20))
		{
			Data_2389fb64.Data_238a0e88.Data_0xc04 = 0x10;
		}
		else /* (576 << 20)? */
		{
			Data_2389fb64.Data_238a0e88.Data_0xc04 = 0x11;
		}
		//loc_2345f070
		Data_2389fb64.Data_238a0e84 = sub_2345ef9c;

		return;
	} //if (Data_2389fb64.Data_0/*lr*/ != 2)
	else
	{
		//loc_2345f07c
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "videc_audcallback_mpeg: Data_2389fb64.Data_238a0e4c=%d\r\n",
					Data_2389fb64.Data_238a0e4c);
			console_send_string(debug_string);
		}
#endif
		if (Data_2389fb64.Data_238a0e4c == 0)
		{
			//0x2345f090
			if (audNum != 0)
			{
				return;
			}

			Data_2389fb64.Data_238a0e4c = 1; //r7

			uint32_t r1 = r2 + 7;

			if (Data_238a1ac4.Data_0xc < r1)
			{
				r1 -= Data_238a1ac4.Data_0xc;
			}

			uint8_t* r0 = (void*)(0x20000000 + /*r3*/Data_238a1ac4.Data_4 + r1);

			Data_234940c0 = r2;
			//->loc_2345f110
			Data_2389fb64.Data_238a0e64 = ((r0[0] >> 4) & 0x03);
			Data_2389fb64.Data_238a0e68 = r0[0] & 0x0f;

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "videc_audcallback_mpeg: Data_2389fb64.Data_238a0e64=0x%x, Data_2389fb64.Data_238a0e68=0x%x\r\n",
					Data_2389fb64.Data_238a0e64, Data_2389fb64.Data_238a0e68);
			console_send_string(debug_string);
		}
#endif

			return;
		}
		//loc_2345f0b8
		else if (audNum == 0)
		{
			//0x2345f0c0
			uint32_t r1 = r2 + 7;

			if (Data_238a1ac4.Data_0xc < r1)
			{
				r1 -= Data_238a1ac4.Data_0xc;
			}

			uint8_t* r0 = (void*)(0x20000000 + /*r3*/Data_238a1ac4.Data_4 + r1);

			int r1_ = ((r0[0] >> 4) & 0x03);

			if (Data_2389fb64.Data_238a0e64/*r3*/ == r1_)
			{
				Data_2389fb64.Data_238a0e6c = 5;

				return;
			}
			//0x2345f0f4
			if (Data_2389fb64.Data_238a0e6c != 0)
			{
				Data_2389fb64.Data_238a0e6c--;

				return;
			}
			//0x2345f10c
			Data_2389fb64.Data_238a0e6c = 5;
			//loc_2345f110
			Data_2389fb64.Data_238a0e64 = ((r0[0] >> 4) & 0x03);
			Data_2389fb64.Data_238a0e68 = r0[0] & 0x0f;

			return;
		}
		else
		{
			//loc_2345f130
			if (Data_234940c0 != 0)
			{
				r2 = Data_234940c0;
				Data_234940c0 = 0; //r6
			}

			Data_2389fb64.Data_0x558[Data_2389fb64.Data_238a0e40] = r2;

			int r5 = Data_2389fb64.Data_238a0e40 - 1;
			if (r5 < 0)
			{
				r5 += 384;
			}

			uint32_t pts = tsd_get_pts(Data_238a1ac4.Data_238a1adc);

#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "videc_audcallback_mpeg: Data_2389fb64.Data_238a0e40=%d, pts=%u\r\n",
						Data_2389fb64.Data_238a0e40, pts);
				console_send_string(debug_string);
			}
#endif

			Data_2389fb64.Data_0xb58[Data_2389fb64.Data_238a0e40] = pts;

			if (Data_2389fb64.Data_0xb58[Data_2389fb64.Data_238a0e40] != Data_2389fb64.Data_0xb58[r5])
			{
				Data_2389fb64.bData_238a0cbc[Data_2389fb64.Data_238a0e40] = 1; //r7
			}
			else
			{
				Data_2389fb64.bData_238a0cbc[Data_2389fb64.Data_238a0e40] = 0; //r6
			}

			Data_2389fb64.Data_238a0e40++;
			if (Data_2389fb64.Data_238a0e40 == 384)
			{
				Data_2389fb64.Data_238a0e40 = 0; //r6
			}

			sub_2345d830(1);
		}
	}
}


/* 2345f1d0 / 2343970c - todo */
int videc_isr_decode()
{
#if 0
	console_send_string("videc_isr_decode (todo.c): TODO\r\n");
#endif

	uint32_t r7 = FREG(0x61100078)[0];

	FREG(0x61100078)[0] = r7;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "videc_isr_decode: r7=0x%x\r\n",
				r7);
		console_send_string(debug_string);
	}
#endif

	if (r7 & 0x800) //PCPU_MESSAGE_BOOT_DONE
	{
		//r0 = 1;
		//->loc_2345f21c
		Data_2389fb64.Data_0 = 1;
		//->loc_2345f514
		return 0;
	}

	if (r7 & 0x100) //PCPU_MESSAGE_DEC_START
	{
		Data_2389fb64.Data_0 = 2;

		Data_2389fb64.Data_238a0e4c = 0; //sb

		Data_234940c4 = 0; //sb
	}

	if (r7 & 0x400) //PCPU_MESSAGE_DECODE_END
	{
		//0x2345f218
		Data_2389fb64.Data_0 = 3;
		//->loc_2345f514
		return 0;
	}
	//loc_2345f224
	if (r7 & 0x4000)
	{
		FREG(0x600d0050)[0] = 0x4000;
	}

	if (r7 & 0x2000) //PCPU_MESSAGE_VCPB_FREE_FIFO_UPDATE
	{
		//0x2345f23c
		int vc_f_wpos = FREG(0x60048380)[0]; //VCPB_FREE_IDX_FIFO_WRITE_POS_ADDR_0
		int vc_f_rpos = FREG(0x60048384)[0]; //VCPB_FREE_IDX_FIFO_READ_POS_ADDR_0
		int sl = vc_f_wpos - vc_f_rpos;
		if (sl < 0)
		{
			sl += 96;
		}

		Data_234940c4 += sl;

		if (Data_234940c4 >= 0x4a)
		{
			Data_2389fb64.Data_238a0e3c |= 1;

			Data_234940c4 = 0; //sb
		}
		//fp, #0x0
		//->loc_2345f33c
		for (uint32_t fp = 0; fp < sl; fp++)
		{
			//loc_2345f27c
			volatile struct
			{
				int fill_0[103]; //0
				int Data_0x19c; //0x19c
				int fill_0x1a0[41]; //0x1a0
				int Data_0x244; //0x244
				int fill_0x248[3]; //0x248
				int Data_0x254; //0x254
				uint32_t Data_0x258; //0x258
				uint32_t Data_0x25c; //0x25c
				int fill_0x260[104]; //0x260
				int Data_0x400; //0x400
				int Data_0x404; //0x404
				int fill_0x408[62]; //0x408
				//0x500
			}* r5 = (void*) 0x211ab700; //oodInfoTableStartAddress

			r5 = &r5[Data_2389fb64.Data_238a0e60];

			if (r5->Data_0x244 == 0)
			{
				Data_2389fb64.Data_238a00b0 = 0; //sb
				//->loc_2345f31c
			}
			else
			{
				//0x2345f29c
				Data_2389fb64.Data_238a00b0 = r5->Data_0x19c;
				Data_2389fb64.Data_238a0e64 = r5->Data_0x244;
				Data_2389fb64.Data_238a0e64 = (Data_2389fb64.Data_238a0e64 == 1)? 3: Data_2389fb64.Data_238a0e64;
				Data_2389fb64.Data_238a0e68 = 3;
				Data_2389fb64.Data_238a0e80 = r5->Data_0x25c / (r5->Data_0x258 * 2);

				uint32_t r0 = (r5->Data_0x400 & (1 << 5));
				if ((r0 >> 5) == 1)
				{
					Data_2389fb64.Data_238a0e74 = 1;
					Data_2389fb64.Data_238a0e70 = (r5->Data_0x404 & 0xff);
				}
				else
				{
					Data_2389fb64.Data_238a0e74 = 0; //sb
				}

				if (r5->Data_0x254 != 1)
				{
					//0x2345f30c
					if (r5->Data_0x254 == 2)
					{
						Data_2389fb64.Data_238a0e68 = 4;
					}
				}
				//loc_2345f31c
			}
			//loc_2345f31c
			Data_2389fb64.Data_238a0e60 = (Data_2389fb64.Data_238a0e60 + 1) & 0x3f;

			vc_f_rpos++;
			if (vc_f_rpos == 0x60)
			{
				vc_f_rpos = 0;
			}
			//loc_2345f33c
		} //for (uint32_t fp = 0; fp < sl; fp++)
		//0x2345f344
		FREG(0x60048384)[0] = vc_f_rpos; //VCPB_FREE_IDX_FIFO_READ_POS_ADDR_0
	}
	//loc_2345f34c
	if (r7 & 0x1000) //PCPU_MESSAGE_VDPB_INFO_UPDATE
	{
		//0x2345f354
		//sl, =0x60048000
		int r0 = FREG(0x600484c0)[0];
		int r5 = FREG(0x600484c4)[0];
		int r7 = r0 - r5;
		if (r7 < 0)
		{
			r7 += 48;
		}

		Data_234940c4 = 0; //sb

		Data_2389fb64.Data_238a0e3c &= ~1;

		uint32_t fp = 0x210aa000; //0x210aa400 = vdpbInfoTableStartAddress

		//r6, #0x0
		//->loc_2345f508
		for (uint32_t r6 = 0; r6 < r7; r6++)
		{
			//loc_2345f388
			uint32_t r1 = 0x60048000 + r5 * 4;
			uint32_t r0 = fp + FREG(r1 + 0x400)[0] * 0x60;

			if (FREG(r0 + 0x428)[0] == 0x10101010)
			{
				//0x2345f3a8
				videc_delete_frame_bank( FREG(r1 + 0x400)[0] & 0xff );
				//->loc_2345f4f8
			}
			else
			{
				//loc_2345f3b8
				Data_2389fb64.Data_0x10c[Data_2389fb64.Data_8] = FREG(r1 + 0x400)[0];
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "videc_isr_decode: Data_2389fb64.Data_0x10c[%d] = %d\r\n",
							Data_2389fb64.Data_8, Data_2389fb64.Data_0x10c[Data_2389fb64.Data_8]);
					console_send_string(debug_string);
				}
#endif
				FREG(r0 + 0x400)[0];
				Data_2389fb64.Data_0x20c[Data_2389fb64.Data_8] = FREG(r0 + 0x40c)[0];
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "videc_isr_decode: Data_2389fb64.Data_0x20c[%d] = %d\r\n",
							Data_2389fb64.Data_8, Data_2389fb64.Data_0x20c[Data_2389fb64.Data_8]);
					console_send_string(debug_string);
				}
#endif
				Data_2389fb64.Data_0x30c[Data_2389fb64.Data_8] = FREG(r0 + 0x404)[0] << 16;
				Data_2389fb64.Data_0x30c[Data_2389fb64.Data_8] += FREG(r0 + 0x408)[0];
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "videc_isr_decode: Data_2389fb64.Data_0x30c[%d] = 0x%x\r\n",
							Data_2389fb64.Data_8, Data_2389fb64.Data_0x30c[Data_2389fb64.Data_8]);
					console_send_string(debug_string);
				}
#endif
				Data_2389fb64.Data_0xc[Data_2389fb64.Data_8] = FREG(r0 + 0x418)[0] << 16;
				Data_2389fb64.Data_0xc[Data_2389fb64.Data_8] += FREG(r0 + 0x41c)[0];
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "videc_isr_decode: Data_2389fb64.Data_0xc[%d] = %d\r\n",
							Data_2389fb64.Data_8, Data_2389fb64.Data_0xc[Data_2389fb64.Data_8]);
					console_send_string(debug_string);
				}
#endif
				Data_2389fb64.bData_0x50c[Data_2389fb64.Data_8] = FREG(r0 + 0x420)[0];
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "videc_isr_decode: Data_2389fb64.bData_0x50c[%d] = %d\r\n",
							Data_2389fb64.Data_8, Data_2389fb64.bData_0x50c[Data_2389fb64.Data_8]);
					console_send_string(debug_string);
				}
#endif
				if (Data_2389fb64.bData_0x50c[Data_2389fb64.Data_8] != 0)
				{
					Data_2389fb64.Data_0x40c[Data_2389fb64.Data_8] = FREG(r0 + 0x428)[0];
					//->loc_2345f4cc
				}
				else
				{
					//0x2345f468
					int r0 = (Data_2389fb64.Data_8 - 1) & 0x3f;
					Data_2389fb64.Data_0x40c[Data_2389fb64.Data_8] = Data_2389fb64.Data_0x40c[r0];

					if ((uint16_t)(Data_2389fb64.Data_0x30c[Data_2389fb64.Data_8]) == 720)
					{
						Data_2389fb64.Data_0x40c[Data_2389fb64.Data_8] += 270000;
					}
					else
					{
						Data_2389fb64.Data_0x40c[Data_2389fb64.Data_8] += 540000;
					}

					Data_2389fb64.bData_0x50c[Data_2389fb64.Data_8] = 1;
				}
				//loc_2345f4cc
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "videc_isr_decode: Data_2389fb64.Data_0x40c[%d] = 0x%x\r\n",
							Data_2389fb64.Data_8, Data_2389fb64.Data_0x40c[Data_2389fb64.Data_8]);
					console_send_string(debug_string);
				}
#endif
				//loc_2345f4cc
				if ((Data_2389fb64.Data_8 == 2) && (Data_2389fb64.Data_4 == 0))
				{
					Data_2389fb64.Data_4 = 1;
					Data_2389fb64.Data_0x550 = 0; //sb
				}

				Data_2389fb64.Data_8 = (Data_2389fb64.Data_8 + 1) & 0x3f;
			}
			//loc_2345f4f8
			r5++;
			if (r5 == 48)
			{
				r5 = 0;
			}
		} //for (uint32_t r6 = 0; r6 < r7; r6++)
		//0x2345f510
		FREG(0x600484c4)[0] = r5;
	}
	//loc_2345f514
	return 0;
}


/* 2345f694 / 23439b8c - todo */
int sub_2345f694()
{
#if 0
	console_send_string("sub_2345f694 (todo.c): TODO\r\n");
#endif

	int r0 = 0;
//	int sb = 0;

	if (Data_2389fb64.bData_0x50c[Data_2389fb64.Data_0x550] != 0)
	{
		//0x2345f6bc
		int r6 = Data_2389fb64.Data_0x40c[Data_2389fb64.Data_0x550];
		int r2 = Data_2389fb64.Data_238a0e58;
		int r1 = Data_2389fb64.Data_238a0e5c;
		int r8 = r6 - r2;
		r1 = r1 - r8;

		if ((Data_2389fb64.Data_238a0e58 == 0) ||
				(Data_2389fb64.Data_238a0e5c == 0))
		{
			Data_2389fb64.Data_238a0e58 = r6;
			Data_2389fb64.Data_238a0e5c = r8;

			Data_234940d0 = 0; //sb
			//->loc_2345f85c
			return 0;
		}
		//0x2345f6fc
		if ((uint32_t)(r1 + 0x4ff) <= 0x9fe)
		{
			//0x2345f710
			uint8_t sp;

			r0 = sub_23435f74(&sp);
			if (sp == 0)
			{
				//loc_2345f85c
				return 0;
			}
			//0x2345f724
			//uint32_t r1 = 540000;
			r0 = r6 - r0 + 2160000;
			int r7 = Data_2389fb64.Data_8 - Data_2389fb64.Data_0x550;
			if (r0 > 0)
			{
				//0x2345f748
				if (r7 < 0)
				{
					r7 += 0x40;
				}

				r0 = r0 / (540000 >> Data_2389fb64.Data_238a00b0);

				if ((0x80 - r7) < r0)
				{
					//0x2345f768
					Data_2389fb64.Data_238a0e3c |= 0x02;
					//loc_2345f7a4 -> loc_2345f804
					return 0xff;
				}
				//loc_2345f7ac
			} //if (r0 > 0)
			else
			{
				//loc_2345f774
				if (r7 < 0)
				{
					r7 += 0x40;
				}

				r0 = r0 / (540000 >> Data_2389fb64.Data_238a00b0);
				if (abs(r0) > r7)
				{
					Data_2389fb64.Data_238a0e3c |= 0x04;
					//loc_2345f7a4 -> loc_2345f804
					return 0xff;
				}
				//loc_2345f7ac
			}
		} //if ((uint32_t)(r1 + 0x4ff) < 0x9fe)
		//loc_2345f7ac
		Data_2389fb64.Data_238a0e58 = r6;
		Data_2389fb64.Data_238a0e5c = r8;

		if (r0 != 0)
		{
			//0x2345f7bc
			Data_2389fb64.Data_238a0e50 = (r0 > 0)? 1: -1;
		}
		//loc_2345f7c8
	}
	//loc_2345f7c8
	if (Data_2389fb64.Data_238a0e50 != 0)
	{
		//0x2345f7d4
		if (Data_2389fb64.Data_238a0e50 > 0)
		{
			//0x2345f7e4
			Data_2389fb64.Data_0x550 = (Data_2389fb64.Data_0x550 - 1) & 0x3f;

			Data_2389fb64.Data_238a0e50 = 0; //sb

			Data_2389fb64.Data_238a0e58 = Data_2389fb64.Data_0x40c[Data_2389fb64.Data_0x550];
			//loc_2345f804
			return 0xff;
		}
		else
		{
			//loc_2345f80c
			FREG(0xcb000004)[0] = //VO_FRAMOFFSET
					Data_2389fb64.Data_0x10c[Data_2389fb64.Data_0x550];

			videc_delete_frame_bank(Data_2389fb64.Data_0x10c[Data_2389fb64.Data_0x554] & 0xff);

			Data_2389fb64.Data_0x554 = Data_2389fb64.Data_0x550;

			Data_2389fb64.Data_0x550 = (Data_2389fb64.Data_0x550 + 1) & 0x3f;

			Data_2389fb64.Data_238a0e50 = 0; //sb

			Data_2389fb64.Data_238a0e58 = Data_2389fb64.Data_0x40c[Data_2389fb64.Data_0x550];
		}
	}
	//loc_2345f85c
	return 0;
}


/* 2345f864 - complete */
int sub_2345f864()
{
	FREG(0xcb000044)[0] |= (1 << 14); //VO_VOMODE:VOFIELD

	return 0;
}


/* 2345f87c - complete */
void sub_2345f87c()
{
#if 0
	console_send_string("sub_2345f87c (todo.c): TODO\r\n");
#endif

	if (Data_2389fb64.Data_238a00b0 == 0)
	{
		if (Data_2389fb64.Data_0x20c[Data_2389fb64.Data_0x550] != 5)
		{
			sub_23434728(0);
		}
		else
		{
			sub_23434728(1);

			Data_2389fb64.Data_238a1ac0 = sub_2345f864;
		}
	}
}


/* 2345f8f8 - todo */
void sub_2345f8f8()
{
#if 0
	console_send_string("sub_2345f8f8 (todo.c): TODO\r\n");
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2345f8f8: Data_2389fb64.Data_0x30c[%d]=0x%x, Data_2389fb64.Data_238a00b0=0x%x\r\n",
				Data_2389fb64.Data_0x550, Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550],
				Data_2389fb64.Data_238a00b0);
		console_send_string(debug_string);
	}
#endif

	uint8_t r2 = Data_2389fb64.Data_238a00b0 & 0xff;
	uint16_t r1 = Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550];
	uint16_t r0 = Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550] >> 16;

	sub_234346fc(r0, r1, r2);
}


/* 2345f928 - todo */
int sub_2345f928()
{
	int r4 = 0;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_2345f928 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	if (Data_2389fb64.Data_4 != 0xff)
	{
		Data_234940d4 = 0;
		Data_234940dc = 0;
		Data_234940d8 = 0;
		//->loc_2345f9a4
	}
	else
	{
		if (Data_2389fb64.Data_8 == Data_234940d4)
		{
			if (Data_2389fb64.Data_238a0e40 != Data_234940dc)
			{
				Data_234940d8++;
				if (Data_234940d8 > 0x40)
				{
					r4 = 1;
					//loc_2345f990
					Data_234940d8 = 0;
				}
				//->loc_2345f994
			}
		}
		else
		{
			//loc_2345f990
			Data_234940d8 = 0;
		}
		//loc_2345f994
		Data_234940d4 = Data_2389fb64.Data_8;
		Data_234940dc = Data_2389fb64.Data_238a0e40;
	}
	//loc_2345f9a4
	if (Data_2389fb64.Data_238a0e3c != 0)
	{
		Data_2389fb64.Data_238a0e3c = 0;

		r4 = 1;
	}

	OS_EXIT_CRITICAL();

	return r4;
}


/* 2345f9c0 / 23439eb0 - todo */
int videc_isr_display()
{
#if 0
	console_send_string("videc_isr_display (todo.c): TODO\r\n");
#endif

	int r0 = 0;

	uint32_t r2 = FREG(0xcb0100a0)[0]; //VO_DISPPICPOS

	FREG(0xcb01007c)[0] = 0; //r7 //VO_DISPIRQCTRL

	if ((r2 & (1 << 11)) == 0) //CURRENTFIELD
	{
		r0 = 1;
	}

	uint8_t r6 = (1 - r0) & 0xff;

	if (Data_2389fb64.Data_238a0e80 >= 0x21)
	{
		r6 = 1;
	}

	//r8, #0xcb000000

	if (Data_2389fb64.Data_0 == 4)
	{
		if (Data_2389fb64.Data_238a0e78 == 0)
		{
			FREG(0xcb000040)[0] = 0; //r7 //VO_VOLAYERENABLE
		}

		Data_2389fb64.Data_0 = 0; //r7
		Data_2389fb64.Data_0x554 = 0; //r7

		sub_2345f928();
	}
	//loc_2345fa24
	if ((Data_2389fb64.Data_0 == 2) &&
			//0x2345fa30
			(Data_2389fb64.Data_4 != 0))
	{
		//0x2345fa3c
		int r0 = Data_2389fb64.Data_8 - Data_2389fb64.Data_0x550;
		if (r0 < 0)
		{
			r0 += 0x40;
		}

		if (r0 != 0)
		{
			//0x2345fa54
			if (r6 != 0)
			{
				//0x2345fa5c
				if (r0 <= 1)
				{
					Data_2389fb64.Data_238a0e58 = 0; //r7
					Data_2389fb64.Data_238a0e5c = 0; //r7
					//->loc_2345fb50
				}
				else
				{
					//0x2345fa6c
					Data_2389fb64.Data_0x550++;
					Data_2389fb64.Data_0x550 &=0x3f;

					if (Data_2389fb64.Data_4 >= 2)
					{
						//0x2345fa90
						if (0 == (Data_2389fb64.Data_0xf4c)())
						{
							//0x2345faa0
							if (Data_2389fb64.Data_238a1abc != 0)
							{
								(Data_2389fb64.Data_238a1abc)();
							}

#if 0
							{
								extern char debug_string[];
								sprintf(debug_string, "videc_isr_display: Data_2389fb64.Data_0x10c[%d] = 0x%x\r\n",
										Data_2389fb64.Data_0x550,
										Data_2389fb64.Data_0x10c[Data_2389fb64.Data_0x550]);
								console_send_string(debug_string);
							}
#endif

							FREG(0xcb000004)[0] = //VO_FRAMOFFSET
									Data_2389fb64.Data_0x10c[Data_2389fb64.Data_0x550];

							videc_delete_frame_bank(Data_2389fb64.Data_0x10c[Data_2389fb64.Data_0x554] & 0xff);

							Data_2389fb64.Data_0x554 = Data_2389fb64.Data_0x550;

							if (Data_2389fb64.Data_4 != 0xff)
							{
								//0x2345fae8
#if 1
								{
									extern char debug_string[];
									sprintf(debug_string, "videc_isr_display: Data_2389fb64.Data_4 = 0x%x\r\n",
											Data_2389fb64.Data_4);
									console_send_string(debug_string);
								}
#endif

								sub_2345f8f8();

								FREG(0xcb000040)[0] = 1; //VO_VOLAYERENABLE

								Data_2389fb64.Data_4 = 0xff;
							}
							//loc_2345fb50
						}
						//loc_2345fb50
					} //if (Data_2389fb64.Data_4 > 2)
					else
					{
						//loc_2345fb00
						videc_delete_frame_bank(Data_2389fb64.Data_0x10c[Data_2389fb64.Data_0x554] & 0xff);

						Data_2389fb64.Data_238a0e58 = Data_2389fb64.Data_0x40c[Data_2389fb64.Data_0x550];

						Data_2389fb64.Data_0x554 = Data_2389fb64.Data_0x550;

						Data_2389fb64.Data_4++;
						//loc_2345fb50
					}
				}
			} //if (r6 != 0)
			else
			{
				//loc_2345fb38
				if (Data_2389fb64.Data_238a1ac0 != 0)
				{
					Data_2389fb64.Data_238a1ac0 = (Data_2389fb64.Data_238a1ac0)();
				}
			}
		}
		//loc_2345fb50
	}
	//loc_2345fb50
	return 0;
}


/* 2345fb58 / 2343a048 - todo */
int vdec_flash_read(void* sb/*hFlash*/, int r4)
{
#if 0
	console_send_string("vdec_flash_read (todo.c): TODO\r\n");
#endif

	uint32_t sp_0x28;
	struct
	{
		uint8_t sp[32]; //0
		uint32_t addr; //0x20
		uint32_t size; //0x24
		//40 = 0x28
	} sp;

	flash_read(sb, r4, 4, &sp_0x28);
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "vdec_flash_read(1): sp_0x28=0x%x\r\n", sp_0x28);
		console_send_string(debug_string);
	}
#endif
	if (sp_0x28 != 0x1234567)
	{
		//loc_2345fd8c
		return 0;
	}

	r4 += 4;

	flash_read(sb, r4, 4, &sp_0x28);
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "vdec_flash_read(2): sp_0x28=0x%x\r\n", sp_0x28);
		console_send_string(debug_string);
	}
#endif
	if (sp_0x28 != 0xfedcba98)
	{
		//loc_2345fd8c
		return 0;
	}

	int r7 = r4 + 4;

	flash_read(sb, r7, 4, &sp_0x28);
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "vdec_flash_read(3): sp_0x28=0x%x\r\n", sp_0x28);
		console_send_string(debug_string);
	}
#endif
	flash_read(sb, sp_0x28, 4, &sp_0x28);
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "vdec_flash_read(4): sp_0x28=0x%x\r\n", sp_0x28);
		console_send_string(debug_string);
	}
#endif

//	uint32_t r8 = 0x400;
	uint32_t r6 = sp_0x28 >> 16;
	//->loc_2345fd84
	while (r6--)
	{
		//loc_2345fbe8
		r7 += 4;

		flash_read(sb, r7, 4, &sp_0x28);
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "vdec_flash_read(5): sp_0x28=0x%x\r\n", sp_0x28);
			console_send_string(debug_string);
		}
#endif
		flash_read(sb, sp_0x28, 40, &sp);
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "vdec_flash_read(6): sp.sp='%s', sp.addr=0x%x, sp.size/4=0x%x\r\n",
					sp.sp, sp.addr, sp.size / 4);
			console_send_string(debug_string);
		}
#endif
		uint32_t* r4_;
#if 0
		uint32_t r0 = 0;
		uint32_t r1;
#endif
		if (0 == strcmp(&sp.sp[0], "fta_mpeg0.bin"))
		{
			//0x2345fc28
			r4_ = Data_234940e0;
			memcpy(&Data_23877674, &sp, 40);
#if 0
			r0 = sp.size;
			r1 = 1;
			//->loc_2345fd04
#else
			if ((sp.size / 4) > 1)
			{
				//loc_2345fd84
				continue;
			}
			//loc_2345fd44
#endif
		}
		//loc_2345fc48
		else if (0 == strcmp(&sp.sp[0], "fta_mpeg1.bin"))
		{
			//0x2345fc5c
			r4_ = Data_2387769c;
			memcpy(&Data_2387d69c, &sp, 40);
#if 0
			r0 = sp.size;
			r1 = 0x1800;
			//->loc_2345fd04
#else
			if ((sp.size / 4) > (sizeof(Data_2387769c) / 4)) //0x1800)
			{
				//loc_2345fd84
				continue;
			}
			//loc_2345fd44
#endif
		}
		//loc_2345fc7c
		else if (0 == strcmp(&sp.sp[0], "fta_mpeg2.bin"))
		{
			//0x2345fc90
			r4_ = Data_2387d6c4;
			memcpy(&Data_2387dac4, &sp, 40);
#if 0
			r0 = sp.size;
			r1 = 0x100;
			//->loc_2345fd04
#else
			if ((sp.size / 4) > (sizeof(Data_2387d6c4) / 4)) //0x100)
			{
				//loc_2345fd84
				continue;
			}
			//loc_2345fd44
#endif
		}
		//loc_2345fcb0
		else if (0 == strcmp(&sp.sp[0], "dec_h2640.bin"))
		{
			r4_ = Data_2387daec;
			memcpy(&Data_2387eaec, &sp, 40);
			//->loc_2345fd34
#if 0
			r0 = sp.size;
			r1 = 0x400;
			//0x2345fd3c
#else
			if ((sp.size / 4) > (sizeof(Data_2387daec) / 4)) //0x400)
			{
				//loc_2345fd84
				continue;
			}
			//loc_2345fd44
#endif
		}
		//0x2345fcd4
		else if (0 == strcmp(&sp.sp[0], "dec_h2641.bin"))
		{
			//0x2345fce8
			r4_ = Data_2387eb14;
			memcpy(&Data_2389eb14, &sp, 40);
#if 0
			r0 = sp.size;
			r1 = 0x8000;
			//loc_2345fd04
#else
			if ((sp.size / 4) > (sizeof(Data_2387eb14) / 4)) //0x8000)
			{
				//loc_2345fd84
				continue;
			}
			//loc_2345fd44
#endif
		}
		//loc_2345fd10
		else if (0 == strcmp(&sp.sp[0], "dec_h2642.bin"))
		{
			//0x2345fd24
			r4_ = Data_2389eb3c;
			memcpy(&Data_2389fb3c, &sp, 40);
#if 0
			r0 = sp.size;
			r1 = 0x400;
			//0x2345fd3c
#else
			if ((sp.size / 4) > (sizeof(Data_2389eb3c) / 4)) //0x400)
			{
				//loc_2345fd84
				continue;
			}
			//loc_2345fd44
#endif
		}
		else
		{
			//loc_2345fd84
			continue;
		}
#if 0
		//0x2345fd3c
		if ((/*sp.size*/r0 / 4) > r1)
		{
			//loc_2345fd84
			continue;
		}
#endif
		//loc_2345fd44
		for (uint32_t i = 0; i < (sp.size / 4); i++)
		{
			//loc_2345fd4c
			flash_read(sb, sp.addr, 4, &sp_0x28);

			sp.addr += 4;

			r4_[i] = sp_0x28;
		}
		//loc_2345fd84
	} //while (r6--)
	//loc_2345fd8c
	return 0;
}


/* 2345fd98 / 2343a288 - todo */
void vdec_init(Struct_2345fd98* r4)
{
	Data_2389fb64.Data_0xf48 = OSSemCreate(1);
	Data_2389fb64.Data_0xf4c = sub_2345f694;

	vdec_flash_read(r4->hFlash, r4->Data_4);

	intr_set_isr(videc_isr_decode, 0, 18); //FAPI_INTR_AMCPU_AXP
	sub_2341b3b8(18, 0);

	FREG(0xe0000248)[0] = 0x0f;

	intr_set_isr(videc_isr_display, 0, 28); //FAPI_INTR_DISP0
	sub_2341b3b8(28, 0);

	FREG(0xe0000270)[0] = 0x0f;
}


/* 2345fea8 / 2343a39c - complete */
void sub_2345fea8(Struct_235f048c* r6, int r5)
{
	uint8_t err;

#if 0
	console_send_string("sub_2345fea8 (todo.c): TODO\r\n");
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2345fea8: r5=0x%x\r\n",
				r5);
		console_send_string(debug_string);
	}
#endif

	OSSemPend(Data_2389fb64.Data_0xf48, 0, &err);

	Data_238a1ac4.Data_238a1adc = r6;
	Data_238a1ac4.Data_238a1ad8 = r6->Data_4; //r7
#if 0
	Data_238a1ac4.Data_0 = r6->Data_8;
	Data_238a1ac4.Data_4 = r6->Data_12;
	Data_238a1ac4.Data_8 = r6->Data_0x10;
	Data_238a1ac4.Data_0xc = r6->Data_0x14;
#else
	memcpy(&Data_238a1ac4.Data_0, &r6->Data_8, 16);
#endif
	Data_238a1ac4.Data_0 = 0;
	Data_238a1ac4.Data_238a1ad4 = 0;

	Data_2389fb64.Data_238a0e58 = 0;
	Data_2389fb64.Data_238a0e5c = 0;
	Data_2389fb64.Data_238a0e3c = 0;
	Data_2389fb64.Data_238a0e78 = 0;
	Data_2389fb64.Data_0 = 0;
	Data_2389fb64.Data_4 = 0;
	Data_2389fb64.Data_238a0e48 = 0;
	Data_2389fb64.Data_238a0e4c = 0;
	Data_2389fb64.Data_8 = 0;
	Data_2389fb64.Data_0x550 = 0;
	Data_2389fb64.Data_238a0e60 = 0;
	Data_2389fb64.Data_238a0e50 = 0;
	Data_2389fb64.Data_238a0e40 = 0;
	Data_2389fb64.Data_238a0e44 = 0;
	Data_2389fb64.Data_0x554 = 0;
	Data_2389fb64.Data_238a0e54 = Data_238a1ac4.Data_238a1ad8; // r7;
	Data_2389fb64.Data_238a0e6c = 5;
	Data_2389fb64.Data_238a0e84 = 0;
	Data_2389fb64.Data_238a0e7c = 0;
	Data_2389fb64.Data_238a1abc = 0;
	Data_2389fb64.Data_238a1ac0 = 0;
	Data_2389fb64.Data_238a0e80 = 0x19;
	Data_2389fb64.Data_238a0e74 = 0;
	Data_2389fb64.Data_238a0e70 = 0;

	if (r5 != 0)
	{
		if (r5 == 0x100)
		{
			sub_2345e694();
		}
		else if (r5 == 0x400)
		{
			sub_2345e410();
		}
		else if (r5 == 0x800)
		{
			sub_2345e8b0();
		}
	}
	//loc_2345ff8c
	OSSemPost(Data_2389fb64.Data_0xf48);
}


/* 2345ff98 - complete */
int sub_2345ff98()
{
	uint8_t err;
	int r5 = 0;

#if 0
	console_send_string("sub_2345ff98 (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_2389fb64.Data_0xf48, 0, &err);

	if (Data_2389fb64.Data_0 == 0)
	{
		if (Data_2389fb64.Data_238a0e84 != 0)
		{
			r5 = (Data_2389fb64.Data_238a0e84)();
		}
	}
	else
	{
		//loc_2345ffd8
		if (Data_2389fb64.Data_238a1ab8 != 0)
		{
			r5 = (Data_2389fb64.Data_238a1ab8)();
		}
	}
	//loc_2345fff0
	OSSemPost(Data_2389fb64.Data_0xf48);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2345ff98: r5 = 0x%x\r\n",
				r5);
		console_send_string(debug_string);
	}
#endif

	return r5;
}


/* 23460000 - complete */
void sub_23460000(Struct_235f048c* r6, int r5)
{
	uint8_t err;

#if 0
	console_send_string("sub_23460000 (todo.c): TODO\r\n");
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23460000: r5=0x%x\r\n",
				r5);
		console_send_string(debug_string);
	}
#endif

	OSSemPend(Data_2389fb64.Data_0xf48, 0, &err);

	Data_238a1ac4.Data_238a1adc = r6;
	Data_238a1ac4.Data_238a1ad8 = r6->Data_4; //r7
#if 0
	Data_238a1ac4.Data_0 = r6->Data_8;
	Data_238a1ac4.Data_4 = r6->Data_12;
	Data_238a1ac4.Data_8 = r6->Data_0x10;
	Data_238a1ac4.Data_0xc = r6->Data_0x14;
#else
	memcpy(&Data_238a1ac4.Data_0, &r6->Data_8, 16);
#endif
	Data_238a1ac4.Data_0 = 0;
	Data_238a1ac4.Data_238a1ad4 = 0;

	Data_2389fb64.Data_238a0e58 = 0;
	Data_2389fb64.Data_238a0e5c = 0;
	Data_2389fb64.Data_238a0e3c = 0;
	Data_2389fb64.Data_0 = 0;
	Data_2389fb64.Data_4 = 0;
	Data_2389fb64.Data_238a0e48 = 0;
	Data_2389fb64.Data_238a0e4c = 0;
	Data_2389fb64.Data_8 = 0;
	Data_2389fb64.Data_238a0e60 = 0;
	Data_2389fb64.Data_238a0e50 = 0;
	Data_2389fb64.Data_238a0e40 = 0;
	Data_2389fb64.Data_0x554 = 0;
	Data_2389fb64.Data_238a0e64 = 3;
	Data_2389fb64.Data_238a0e44 = 0;
	Data_2389fb64.Data_238a0e54 = Data_238a1ac4.Data_238a1ad8; // r7;
	Data_2389fb64.Data_238a0e84 = 0;
	Data_2389fb64.Data_238a0e7c = 0x100;
	Data_2389fb64.Data_238a1abc = sub_2345f87c;
	Data_2389fb64.Data_238a1ac0 = 0;
	Data_2389fb64.Data_238a0e74 = 0;
	Data_2389fb64.Data_238a0e70 = 0;

	if (r5 != 0)
	{
		if (r5 == 0x100)
		{
			sub_2345de14();
		}
		else if (r5 == 0x400)
		{
			sub_2345dbf0();
		}
		else if (r5 == 0x800)
		{
			sub_2345e034();
		}
	}

	OSSemPost(Data_2389fb64.Data_0xf48);
}


/* 234600e8 - todo */
void videc_stop_decoder()
{
	uint8_t err;
	uint32_t count = 100;

#if 0
	console_send_string("videc_stop_decoder (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_2389fb64.Data_0xf48, 0, &err);

	Data_2389fb64.Data_238a0e84 = 0;

	if (Data_2389fb64.Data_0 != 0)
	{
		FREG(0x600d0050)[0] = MAINCPU_CMD_DECODE_END;
		//->loc_23460160
		//fapi_videc_wait_for_stop()
		while (count--)
		{
			//loc_2346012c
			if (Data_2389fb64.Data_0 == 3)
			{
				Data_2389fb64.Data_0 = 4;

				while (1)
				{
					//loc_23460140
					if (Data_2389fb64.Data_0 == 0)
					{
						break;
					}
				}

				FREG(0x600d0000)[0] = FAPI_VIDEC_HW_RESET_ON;
				//->loc_23460168
				break;
			}
			//loc_23460158
			rtos_task_wait(1);
		}
	}
	//loc_23460168
	OSSemPost(Data_2389fb64.Data_0xf48);
}


/* 23460174 / 2343a668 - todo */
void sub_23460174(int a)
{
#if 0
	console_send_string("sub_23460174 (todo.c): TODO\r\n");
#endif

	Data_2389fb64.Data_238a0e50 = a;
}


/* 23460180 - todo */
void sub_23460180(Struct_23460180* a, uint8_t* b)
{
#if 0
	console_send_string("sub_23460180 (todo.c): TODO\r\n");
#endif

	int ip;
	int r1;
	int r2;
	int r3 = 0;

	if (Data_2389fb64.Data_4 == 0)
	{
		*b = 0;
		r1 = r3;
		r2 = r3;
	}
	else
	{
		*b = 1;
		r1 = Data_2389fb64.Data_238a0e64;
		r2 = Data_2389fb64.Data_238a0e68;
		ip = r3;
	}

	a->Data_0 = r1;
	a->Data_4 = r2;
	a->Data_8.Data_0 = ip;
	a->Data_8.Data_4 = ip;
}


/* 234601cc - complete */
void sub_234601cc(Struct_234601cc* a, uint8_t* b)
{
#if 0
	console_send_string("sub_234601cc (todo.c): TODO\r\n");
#endif

	Struct_234601cc sp;

	*b = 0;

	if ((Data_2389fb64.Data_4 != 0xff) ||
			(Data_2389fb64.Data_4 < 2))
	{
		*a = sp;
	}
	else
	{
		//0x234601f8
		*b = 1;

		sp.Data_0 = (uint16_t) (Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550]);
		sp.Data_4 = Data_2389fb64.Data_0x30c[Data_2389fb64.Data_0x550] >> 16;
		sp.bData_8 = Data_2389fb64.Data_238a00b0;

		*a = sp;
	}
}


/* 23460294 / 2343a79c - complete */
void sub_23460294()
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_23460294 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	sub_2345d830(0);

	OS_EXIT_CRITICAL();
}


/* 23460320 - complete */
int sub_23460320(int a)
{
#if 0
	console_send_string("sub_23460320 (todo.c): TODO\r\n");
#endif

	int r0 = FREG(0x60048180)[0] - FREG(0x60048380)[0];

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23460320: r0=%d\r\n", r0);
		console_send_string(debug_string);
	}
#endif

	if (r0 < 0)
	{
		r0 += 96;
	}

	r0 = r0 + 2;

	if (r0 >= 64)
	{
		r0 = 64;
	}

	return 64 - r0;
}


/* 23460348 / 2343a854 - complete */
void videc_delete_frame_bank(uint32_t frameBankNum)
{
#if 0
	console_send_string("videc_delete_frame_bank (todo.c): TODO\r\n");
#endif

	int vd_f_wpos = FREG(VDPB_FREE_IDX_FIFO_WRITE_POS_ADDR_0)[0];
	FREG(VDPB_FREE_IDX_FIFO_START_ADDR_0 + (vd_f_wpos << 2))[0] = frameBankNum;

	FREG(VDPB_FREE_IDX_FIFO_WRITE_POS_ADDR_0)[0] = (vd_f_wpos == 0x2f)? 0: vd_f_wpos + 1;

	FREG(0x600d0050)[0] = MAINCPU_MESSAGE_VDPB_FREE_UPDATE;
}


