
#include <stdint.h>
#include "ucos_ii.h"
#include "sys_services.h"
#include "gpio.h"
#include "bm.h"
#include "tsd.h"
#include "auout.h"


#define AUOUT_HANDLE_ID                (uint32_t)0x414f5554 /* 'AOUT' */
#define AUOUT_SAMPLE_FREG_COUNT 9

typedef struct
{
	int i2sId; //0
	void* bmHandle; //4
	int leftCh; //8
	int rightCh; //12
	//16
} AUOUT_I2sBuffer;

typedef struct
{
	int id; //0
	int inUse; //4
	int fdClk; //8
	int useSPDIF; //12 = 0xc
	int audioClk; //16 = 0x10
	int speakerCount; //20 = 0x14
	uint32_t i2sBufferCount; //24 = 0x18
	int i2sSync; //28 = 0x1c
	void* spdifBufferHandle; //0x20
	int Data_0x24; //0x24
	int spdifSampleFreq; //0x28
	int Data_0x2c; //0x2c
	int Data_0x30; //0x30
	int Data_0x34; //0x34
	int speakerArr[AUOUT_SPEAKER_ALL]; //0x38
	AUOUT_I2sBuffer i2sBufferArr[AUOUT_I2S_ALL]; //0x58
	int Data_0x98; //0x98
	int Data_0x9c; //0x9c
	int Data_0xa0; //0xa0
	int Data_0xa4; //0xa4
	int Data_0xa8; //0xa8
	//0xac = 172
} Struct_2349251c;


typedef struct
{
	int format; //0
	int aoClk; //4
	int bitClk; //8
	int lrClkInv; //12
	int leftCh; //0x10 = 16
	int rightCh; //0x14 = 20
	Struct_20611068* hGpio[4]; //0x18 = 24
	//40 = 0x28
} Struct_23492520;


//234924e4
void* auoutHdmiHandle = 0; //234924e4 +0
int auoutSpdifEnabIndex = -1; //234924e8 +4
int auoutHdmiEnabIndex = -1; //234924ec +8
int Data_234924f0 = 0; //234924f0 +0xc
OS_EVENT* aout_sema = 0; //234924F4 +0x10
void* Data_234924f8 = 0; //234924f8 +0x14
void (*Data_234924fc)() = 0; //234924fc +0x18
void (*Data_23492500)() = 0; //23492500 +0x1c
void (*Data_23492504)() = 0; //23492504 +0x20
int Data_23492508 = 0; //23492508 +0x24
int Data_2349250c = 0; //2349250c +0x28
int auoutDacConnect = 0; //23492510 +0x2c
int aout_AmcSpdifMirror = 0; //23492514 +0x30
int Data_23492518 = 0; //23492518 +0x34
Struct_2349251c* Data_2349251c = 0; //2349251c +0x38
Struct_23492520 auoutI2s[4] = //23492520
{
		{
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000002,
		},
		{
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0xffffffff,
			0xffffffff,
		},
		{
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0xffffffff,
			0xffffffff,
		},
		{
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
			0xffffffff,
			0xffffffff,
		}
}; //->234925C0

uint32_t auoutClkpwrFd12Audio[2][AUOUT_SAMPLE_FREG_COUNT] = //234925c0
{
	//  8kHz        12khz       16khz       22.05khz     24khz      32kHz       44.1kHz     48kHz       96kHz
	{0x90d38044, 0x8cf12044, 0x90d38044, 0x9d63d444, 0x8ef1c001, 0x88d30068, 0x88931001, 0x82f10068, 0x92f20000},
	{0x8cf12044, 0x84506044, 0x8ef1c001, 0x9bc31012, 0x86508010, 0x82f10068, 0x8de24c00, 0x86508010, 0x86508010}
};

uint32_t auoutClkpwrFd12Prescale[2][AUOUT_SAMPLE_FREG_COUNT] = //23492608
{
	//  8kHz        12khz       16khz       22.05khz     24khz      32kHz       44.1kHz     48kHz       96kHz
	{0x0000000d, 0x00000008, 0x00000006, 0x00000004, 0x00000006, 0x00000002, 0x00000003, 0x00000001, 0x00000001},
	{0x00000008, 0x00000005, 0x00000006, 0x00000003, 0x00000003, 0x00000001, 0x00000002, 0x00000001, 0x00000000}
};


struct
{
	int amcClk; //0
	int swChannel; //4
	int parity; //8
	Struct_20611068* gpioSpdifH; //12 235f2df4

} auoutSpdif; //235f2de8


struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //0
	int Data_0xc; //12
	int Data_0x10; //16

} spdif_status; //235f2df8

int auoutSpeakerI2s[8]; //235f2e0c



void aout_SetInterruptMask_IntPtsFound(int);
void aout_SetDacControl_Osr(int);
void aout_SetDacControl_Fsys(int);
void aout_SetGeneralControl_1_SpdifSwChannel(int);
void aout_SetGeneralControl_1_SpdifClear(int);
void aout_SetGeneralControl_2_ClkSel(int);
void aout_SetI2sConfig_DualMono(int, int);
void aout_SetI2sConfig_OutputEnable(int, int);
void aout_SetGeneralControl_3_SyncI2s3(int);
void aout_SetFdclksel_Selfd1clk(int);
void aout_SetFdclksel_Selfd2clk(int);
void aout_SetGeneralControl_0_SwAmcClk(int);
void aout_SetGeneralControl_2_PassThrough(int);
void aout_SetAmcSpdif_ToSpdifChannel(int);
void aout_SetAmcPc_PcmEn(int);
void aout_SetI2sVolumeControl_VolumeLeft(int, int);
void aout_SetI2sVolumeControl_VolumeRight(int, int);
void aout_SetGeneralControl_0_EnableSpdif(int);
void aout_SetGeneralControl_1_EnableBits(int);
static void aout_SetConfigdmacaudio_Confdmacau23(int);



/* 23429da0 - todo */
void auoutProgramFdClk(Struct_2349251c* a)
{
#if 0
	console_send_string("auoutProgramFdClk (todo.c): TODO\r\n");
#endif

	int sf_index;

	switch (a->spdifSampleFreq)
	{
	case 8000:
		sf_index = 0;
		break;

	case 12000:
		sf_index = 1;
		break;

	case 16000:
		sf_index = 2;
		break;

	case 22050:
		sf_index = 3;
		break;

	case 24000:
		sf_index = 4;
		break;

	case 32000:
		sf_index = 5;
		break;

	case 44100:
		sf_index = 6;
		break;

	case 48000:
		sf_index = 7;
		break;

	case 96000:
		sf_index = 8;
		break;

	default:
		return;
	}
	//loc_23429e38
	int clkpwr_audio = auoutClkpwrFd12Audio[a->audioClk][sf_index];
	int clkpwr_prescale = auoutClkpwrFd12Prescale[a->audioClk][sf_index];

	int val;

	switch (a->fdClk)
	{
	case 1:
		//loc_23429eac
		FREG(0xca000054)[0] &= ~0x80000000; //FD0AUDIO:
		FREG(0xca000054)[0] = clkpwr_audio;

		val = (clkpwr_prescale << 8) & 0xff00;
		FREG(0xca000050)[0] = (FREG(0xca000050)[0] & ~0xff00) | val; //FDPRESCALE:FD1DIVIDER
		break;

	case 2:
		//0x23429e70
		FREG(0xca000058)[0] &= ~0x80000000; //FD1AUDIO
		FREG(0xca000058)[0] = clkpwr_audio;

		val = (clkpwr_prescale << 16) & 0xff0000;
		FREG(0xca000050)[0] = (FREG(0xca000050)[0] & ~0xff0000) | val; //FDPRESCALE:FD2DIVIDER
		break;

	default:
		//loc_23429e98
		break;
	}
	//loc_23429e98
	aout_SetFdclksel_Selfd1clk(1);
	aout_SetFdclksel_Selfd2clk(1);
}


/* 23429ed0 - complete */
void auoutSetSpdifStatus(Struct_2349251c* r0, int b)
{
#if 0
	console_send_string("auoutSetSpdifStatus (todo.c): TODO\r\n");
#endif

	if (r0->useSPDIF == 0)
	{
		return;
	}

	if (r0->speakerCount != 0)
	{
		spdif_status.Data_0 = 0x00;
	}
	else
	{
		spdif_status.Data_0 = 0x40;
	}

	if (b == 0)
	{
		spdif_status.Data_0 |= 0x20;
	}

	if (r0->spdifSampleFreq == 32000)
	{
		spdif_status.Data_0xc = 0xc0;
		//->loc_23429f2c
	}
	else if (r0->spdifSampleFreq == 48000)
	{
		spdif_status.Data_0xc = 0x40;
	}
	//loc_23429f2c
	aout_SetGeneralControl_1_EnableBits(0);
	aout_SetGeneralControl_1_SpdifClear(1);
	aout_SetGeneralControl_1_SpdifClear(0);

	aout_SetAmcSpdif_ToSpdifChannel(spdif_status.Data_0);
	aout_SetAmcSpdif_ToSpdifChannel(spdif_status.Data_4);
	aout_SetAmcSpdif_ToSpdifChannel(spdif_status.Data_8);
	aout_SetAmcSpdif_ToSpdifChannel(spdif_status.Data_0xc);
	aout_SetAmcSpdif_ToSpdifChannel(spdif_status.Data_0x10);

	aout_SetGeneralControl_1_EnableBits(1);
}


/* 23429f78 - todo */
void sub_23429f78(int r4)
{
#if 0
	console_send_string("sub_23429f78 (todo.c): TODO\r\n");
#endif

	if (r4 == -1)
	{
		Data_23492518 = -1;

		Data_23492504 = sub_23429f78;
	}
	else
	{
		if (Data_23492518 == r4)
		{
			uint32_t r0 = (FREG(0xcc000058)[0] & (1 << 9)); //GENERAL_CONTROL_0:ENABLE_SPDIF
			if ((r0 >> 9) == 0)
			{
				aout_SetGeneralControl_0_EnableSpdif(1);
			}

			Data_23492504 = 0;
		}
		//loc_23429fc4
		Data_23492518 = r4;
	}
}


/* 23429fcc - todo */
int auout_isr()
{
#if 0
	console_send_string("auout_isr (todo.c): TODO\r\n");
#endif

	//r5, #0xcc000000

	int r0_ = FREG(0xcc000004)[0]; //INTERRUPT_SRC
	int r1 = FREG(0xcc000000)[0]; //INTERRUPT_MASK

	if (r0_ == 0)
	{
		r0_ = FREG(0xcc000004)[0];
	}

	int r4 = r0_ & r1;
//	Struct_2349251c* r0 = Data_2349251c;

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "auout_isr: r0_=0x%x, r1=0x%x\r\n", r0_, r1);
		console_send_string(debug_string);
	}
#endif

	if (r4 == 0)
	{
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "auout_isr: r4=0, Data_2349251c->Data_0x98=0x%x\r\n",
					Data_2349251c->Data_0x98);
			console_send_string(debug_string);
		}
#endif

		if (Data_2349251c->Data_0x98 & 1)
		{
			//0x2342a000
			Data_2349251c->Data_0x98 &= ~1;

			uint32_t dac_power_down = (FREG(0xcc000090)[0] & (1 << 5)); //DAC_CONTROL:POWERDOWN

			if ((dac_power_down >> 5) == 0) //powerdown mode
			{
				FREG(0xcc000090)[0] |= (1 << 5); //normal operation
			}

			if (Data_23492500 != 0)
			{
				(Data_23492500)(Data_2349251c);
			}

			if (Data_23492504 == 0)
			{
				aout_SetGeneralControl_0_EnableSpdif(1);
			}
			//loc_2342a03c
		}
		//loc_2342a03c
		if (Data_2349251c->Data_0x98 & 2)
		{
			Data_2349251c->Data_0x98 &= ~2;

			if (Data_234924fc != 0)
			{
				(Data_234924fc)(Data_2349251c);
			}
		}

		sub_2341b570(0);
		//->loc_2342a2f8
		return 0;
	}
	//loc_2342a068
	uint32_t pts_found = (r4 & (1 << 12)); //PTS_FOUND
	if ((pts_found >> 12) != 0)
	{
		//0x2342a074
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "auout_isr: pts_found\r\n");
			console_send_string(debug_string);
		}
#endif

	}
	//loc_2342a174
	uint32_t header_found = (r4 & (1 << 11)); //AMC_conv header found
	if ((header_found >> 11) != 0)
	{
		//0x2342a180
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "auout_isr: header_found\r\n");
			console_send_string(debug_string);
		}
#endif

	}
	//loc_2342a2f8
	return 0;
}

#if 0

/* 2342a300 - complete */
void auoutSetHdmiSpeakerMapping(struct Struct_2342499c_Inner_0x20* r0, AUOUT_I2sBuffer* r1)
{
#if 0
	console_send_string("auoutSetHdmiSpeakerMapping (todo.c): TODO\r\n");
#endif

	switch (r1->leftCh)
	{
	case 0:
		//2342A358
		r0->left = 1; //r2
		break;

	case 1:
		//2342A360
		r0->left = 4; //r3
		break;

	case 2:
		//2342A368
		r0->left = 2; //ip
		break;

	case 3:
		//2342A370
		r0->left = 5; //lr
		break;

	case 4:
		//2342A378
		r0->left = 6; //r4
		break;

	case 5:
		//2342A380
		r0->left = 0x0a; //r5
		break;

	case 6:
		//2342A388
		r0->left = 0x0b; //r6
		break;

	case 7:
		//2342A390
		r0->left = 3; //r7
		break;

	default:
		//loc_2342a398
		r0->left = 0; //r8
		break;
	}

	switch (r1->rightCh)
	{
	case 0:
		r0->right = 1; //r2
		break;

	case 1:
		r0->right = 4; //r3
		break;

	case 2:
		r0->right = 2; //ip
		break;

	case 3:
		r0->right = 5; //lr
		break;

	case 4:
		r0->right = 6; //r4
		break;

	case 5:
		r0->right = 0x0a; //r5
		break;

	case 6:
		r0->right = 0x0b; //r6
		break;

	case 7:
		r0->right = 3; //r7
		break;

	default:
		//loc_2342a40c
		r0->right = 0; //r8
		break;
	}

}

#endif

/* 2342a4b4 - todo */
void sub_2342a4b4()
{
	console_send_string("sub_2342a4b4 (todo.c): TODO\r\n");

}


/* 2342a504 - todo */
int sub_2342a504(Struct_2349251c* r7, AUOUT_OpenParams* r4)
{
	BM_OpenParams bmOpenParams;
	TSD_PesParserParams sp;

#if 0
	console_send_string("sub_2342a504 (todo.c): TODO\r\n");
#endif

	bmOpenParams.Data_0 = 0x10000;
	bmOpenParams.Data_4 = -1;
	bmOpenParams.Data_0x14 = 0; //r8
	bmOpenParams.Data_0x18 = 0; //r8
	bmOpenParams.Data_0x1c = 0; //r8
	bmOpenParams.handleOverflow = 0; //r8
	bmOpenParams.Data_0x24 = 0; //r8
	bmOpenParams.Data_0x28 = 0; //r8

	if (r7->useSPDIF != 0)
	{
		//0x2342a54c
		bmOpenParams.pidChannel = 4; //SPDIF
		bmOpenParams.bufferAddress = r4->spdifBufferAddress;
		bmOpenParams.bufferSize = r4->spdifBufferSize;
		bmOpenParams.Data_0x2c = sub_2342a4b4;
		bmOpenParams.Data_0x30 = 0x80;

		memcpy(&sp.Data_4, &bmOpenParams, sizeof(BM_OpenParams));

		sp.bData_0 = 0; //r8
		sp.bData_1 = 0xff;
		sp.pid = 0; //r8
		sp.Data_0x38 = 0; //r8

		tsd_open_pes_parser(&Data_234924f8, &sp);

		if (Data_234924f8 == 0)
		{
			//->loc_2342a69c
			return 0;
		}

		r7->spdifBufferHandle = tsd_get_bm_handle(Data_234924f8);
		if (r7->spdifBufferHandle == 0)
		{
			//->loc_2342a69c
			return 0;
		}

		if (0 != sub_2341e600(r7->spdifBufferHandle, 0))
		{
			//->loc_2342a69c
			return 0;
		}
	}
	//loc_2342a5d4
	bmOpenParams.Data_0x2c = 0; //r8
	bmOpenParams.Data_0x30 = 0;
	bmOpenParams.Data_0x14 = 0;
	bmOpenParams.Data_0x18 = 0;

	for (uint8_t r6 = 0; r6 < 4; r6++)
	{
		//loc_2342a5e8
		AUOUT_I2sBuffer* r5 = &r7->i2sBufferArr[r6];

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2342a504: r6=%d, r5->i2sId=%d\r\n", r6, r5->i2sId);
			console_send_string(debug_string);
		}
#endif

		switch (r5->i2sId)
		{
		case -1:
			//2342A6B8
			return 1;
			//break;

		case 0:
			//2342A618
			bmOpenParams.pidChannel = 0; //I2S_0
			bmOpenParams.bufferAddress = r4->i2s0BufferAddress;
			bmOpenParams.bufferSize = r4->i2s0BufferSize;
			//->2342A670
			r5->bmHandle = bm_open(&bmOpenParams);
			if (r5->bmHandle == 0)
			{
				//->2342A69C
				return 0;
			}
			//loc_2342a688
			break;

		case 1:
			//2342A62C
			bmOpenParams.pidChannel = 1; //I2S_1
			bmOpenParams.bufferAddress = r4->Data_0x34;
			bmOpenParams.bufferSize = r4->Data_0x38;
			//->2342A670
			r5->bmHandle = bm_open(&bmOpenParams);
			if (r5->bmHandle == 0)
			{
				//->2342A69C
				return 0;
			}
			//loc_2342a688
			break;

		case 2:
			//2342A644
			bmOpenParams.pidChannel = 2; //I2S_2
			bmOpenParams.bufferAddress = r4->Data_0x3c;
			bmOpenParams.bufferSize = r4->Data_0x40;
			//->2342A670
			r5->bmHandle = bm_open(&bmOpenParams);
			if (r5->bmHandle == 0)
			{
				//->2342A69C
				return 0;
			}
			//loc_2342a688
			break;

		case 3:
			//2342A65C
			bmOpenParams.pidChannel = 3; //I2S_3
			bmOpenParams.bufferAddress = r4->Data_0x44;
			bmOpenParams.bufferSize = r4->Data_0x48;
			//2342A670
			r5->bmHandle = bm_open(&bmOpenParams);
			if (r5->bmHandle == 0)
			{
				//->2342A69C
				return 0;
			}
			//loc_2342a688
			break;

		default:
			//loc_2342a688
			break;
		}
		//loc_2342a688
		if (0 != sub_2341e600(r5->bmHandle, 1))
		{
			//loc_2342a69c
			return 0;
		}
		//loc_2342a6a8
	} //for (uint8_t r6 = 0; r6 < 4; r6++)
	//0x2342a6b8
	//r0, #0x1
	//->loc_2342a6a0
	return 1;
}


/* 2342a6c0 - todo */
void sub_2342a6c0(Struct_2349251c* r4)
{
#if 0
	console_send_string("sub_2342a6c0 (todo.c): TODO\r\n");
#endif

	if (r4->useSPDIF != 0)
	{
		aout_SetGeneralControl_1_EnableBits(0);

		if (r4->speakerCount == 0)
		{
			sub_2341e4a8(r4->spdifBufferHandle, 0, 0);

			sub_2341e524(r4->spdifBufferHandle, 0, 0);

			return;
		}
		//loc_2342a70c
	}
	//loc_2342a70c
	//r5, #0xcc000000
	switch (r4->i2sSync)
	{
	case 3:
		//loc_2342a7ac
		FREG(0xcc000064)[0] |= 0x10; //SYNC_I2S_10

		aout_SetI2sConfig_OutputEnable(0, 0);
		//loc_2342a7cc
		aout_SetI2sConfig_OutputEnable(1, 0);
		return;
		break;

	case 12:
		//0x2342a728
		FREG(0xcc000064)[0] |= 0x20; //SYNC_I2S_32
		//->loc_2342a764
		aout_SetI2sConfig_OutputEnable(2, 0);
		//loc_2342a770
		//->2342a7cc
		aout_SetI2sConfig_OutputEnable(3, 0);
		return;
		break;

	case 7:
		//loc_2342a77c
		FREG(0xcc000064)[0] |= 0x40; //SYNC_I2S_210

		aout_SetI2sConfig_OutputEnable(0, 0);
		aout_SetI2sConfig_OutputEnable(1, 0);
		//loc_2342a7cc
		aout_SetI2sConfig_OutputEnable(2, 0);
		return;
		break;

	case 15:
		//0x2342a740
		FREG(0xcc000064)[0] |= 0x80; //SYNC_I2S_3210

		aout_SetI2sConfig_OutputEnable(0, 0);
		aout_SetI2sConfig_OutputEnable(1, 0);
		//loc_2342a764
		aout_SetI2sConfig_OutputEnable(2, 0);
		//loc_2342a770
		//->2342a7cc
		aout_SetI2sConfig_OutputEnable(3, 0);
		return;
		break;

	default:
		//loc_2342a7d4
		break;
	}

	if (r4->i2sSync & 1)
	{
		FREG(0xcc000064)[0] |= 0x01; //SYNC_I2S_0

		aout_SetI2sConfig_OutputEnable(0, 0);
	}
	//loc_2342a7f4
	if (r4->i2sSync & 2)
	{
		FREG(0xcc000064)[0] |= 0x02; //SYNC_I2S_1

		aout_SetI2sConfig_OutputEnable(1, 0);
	}
	//loc_2342a818
	if (r4->i2sSync & 4)
	{
		FREG(0xcc000064)[0] |= 0x04; //SYNC_I2S_2

		aout_SetI2sConfig_OutputEnable(2, 0);
	}
	//loc_2342a83c
	if (r4->i2sSync & 8)
	{
		aout_SetGeneralControl_3_SyncI2s3(1); //SYNC_I2S_3
		//->loc_2342a770
		aout_SetI2sConfig_OutputEnable(3, 0);
	}
}


/* 2342a854 - complete */
void auoutEnableHardware(Struct_2349251c* handlePtr)
{
#if 0
	console_send_string("auoutEnableHardware (todo.c): TODO\r\n");
#endif

	int i2s_sync = 0;
	int r5 = handlePtr->fdClk - 1;
	if (r5 != 0)
	{
		r5 = 1;
	}

	if (handlePtr->useSPDIF != 0)
	{
		aout_SetGeneralControl_0_SwAmcClk(r5);

		if (handlePtr->speakerCount != 0)
		{
			aout_SetGeneralControl_2_PassThrough(1);
			aout_SetAmcPc_PcmEn(1);

			handlePtr->spdifSampleFreq = 48000;

			auoutSetSpdifStatus(handlePtr, 0);

			auoutProgramFdClk(handlePtr);
		}
		//loc_2342a8b8
	}
	//loc_2342a8b8
	int val;

	for (uint32_t i = 0; i < AUOUT_I2S_ALL; i++)
	{
		//loc_2342a8c0
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "auoutEnableHardware: handlePtr->i2sBufferArr[%d].i2sId=%d\r\n",
					i, handlePtr->i2sBufferArr[i].i2sId);
			console_send_string(debug_string);
		}
#endif

		switch (handlePtr->i2sBufferArr[i].i2sId)
		{
		case 0:
			//loc_2342a92c
			//FREG_AO_SetGeneralControl_0_SwI2sClk0
			val = (r5 << 0) & 1;
			FREG(0xcc000058)[0] = (FREG(0xcc000058)[0] & ~1) | val; //SW_I2S_CLK_0
			FREG(0xcc000058)[0] |= (1 << 5); //GENERAL_CONTROL_0:ENABLE_I2S_0

			i2s_sync |= 1;
			//loc_2342a910
			break;

		case 1:
			//loc_2342a954
			//FREG_AO_SetGeneralControl_0_SwI2sClk1
			val = (r5 << 1) & 2;
			FREG(0xcc000058)[0] = (FREG(0xcc000058)[0] & ~2) | val; //SW_I2S_CLK_1
			FREG(0xcc000058)[0] |= (1 << 6); //ENABLE_I2S_1

			i2s_sync |= 2;
			//loc_2342a910
			break;

		case 2:
			//loc_2342a980
			//FREG_AO_SetGeneralControl_0_SwI2sClk2
			val = (r5 << 2) & 4;
			FREG(0xcc000058)[0] = (FREG(0xcc000058)[0] & ~4) | val; //SW_I2S_CLK_2
			FREG(0xcc000058)[0] |= (1 << 7); //ENABLE_I2S_2

			i2s_sync |= 4;
			//loc_2342a910
			break;

		case 3:
			//0x2342a8e8
			//FREG_AO_SetGeneralControl_0_SwI2sClk3
			val = (r5 << 3) & 8;
			FREG(0xcc000058)[0] = (FREG(0xcc000058)[0] & ~8) | val; //SW_I2S_CLK_3
			FREG(0xcc000058)[0] |= (1 << 8); //ENABLE_I2S_3

			i2s_sync |= 8;
			//loc_2342a910
			break;

		default:
			//loc_2342a910
			break;
		}
		//loc_2342a910
	} //for (uint32_t i = 0; i < 4; i++)
	//0x2342a91c
	handlePtr->i2sSync = i2s_sync;

	sub_2342a6c0(handlePtr);
}


/* 2342a9ac / 23435d8c - complete */
void auoutOpenGpio(Struct_2349251c* sb)
{
	Struct_20401328 sp;

#if 0
	console_send_string("auoutOpenGpio (todo.c): TODO\r\n");
#endif

	sp.dwInFunction = 0xff;

	if (sb->useSPDIF != 0)
	{
		sp.bPin = 0x51;
		sp.dwOutFunction = 0x10; //sl //FAPI_GPIO_OUT_SPDIF_OUT

		gpio_open(&sp, &auoutSpdif.gpioSpdifH);
	}
	//loc_2342a9e4
	for (uint32_t i = 0; i < 4; i++)
	{
		//loc_2342a9f8
		if (sb->i2sBufferArr[i].i2sId == 0)
		{
			sp.dwOutFunction = 0x0c; //FAPI_GPIO_OUT_AD0_DATA
			sp.bPin = 0x0f;
			gpio_open(&sp, &auoutI2s[0].hGpio[0]);

			sp.dwOutFunction = 0x0e; //FAPI_GPIO_OUT_AD0_BCLK
			sp.bPin = 0x10;
			gpio_open(&sp, &auoutI2s[0].hGpio[1]);

			sp.dwOutFunction = 0x0d; //FAPI_GPIO_OUT_AD0_LRCLK
			sp.bPin = 0x09;
			gpio_open(&sp, &auoutI2s[0].hGpio[2]);

			sp.dwOutFunction = 0x0f; //FAPI_GPIO_OUT_AD0_CLK
			sp.bPin = 0x0a;
			gpio_open(&sp, &auoutI2s[0].hGpio[3]);
		}
		//loc_2342aa6c
		else if (sb->i2sBufferArr[i].i2sId == 1)
		{
			//0x2342aa74
			sp.dwOutFunction = 0x35;
			sp.bPin = 0x1d;
			gpio_open(&sp, &auoutI2s[1].hGpio[0]);

			sp.dwOutFunction = 0x37;
			sp.bPin = 0x19;
			gpio_open(&sp, &auoutI2s[1].hGpio[1]);

			sp.dwOutFunction = 0x36;
			sp.bPin = 0x1a;
			gpio_open(&sp, &auoutI2s[1].hGpio[2]);

			sp.dwOutFunction = 0x38;
			sp.bPin = 0x1b;
			gpio_open(&sp, &auoutI2s[1].hGpio[3]);
		}
		//loc_2342aad4
		else if (sb->i2sBufferArr[i].i2sId == 2)
		{
			//0x2342aadc
			sp.dwOutFunction = 0x39;
			sp.bPin = 0x1e;
			gpio_open(&sp, &auoutI2s[2].hGpio[0]);

			sp.dwOutFunction = 0x3b;
			sp.bPin = 0x19;
			gpio_open(&sp, &auoutI2s[2].hGpio[1]);

			sp.dwOutFunction = 0x3a;
			sp.bPin = 0x1a;
			gpio_open(&sp, &auoutI2s[2].hGpio[2]);

			sp.dwOutFunction = 0x3c;
			sp.bPin = 0x1b;
			gpio_open(&sp, &auoutI2s[2].hGpio[3]);
		}
		//loc_2342ab3c
		else if (sb->i2sBufferArr[i].i2sId == 3)
		{
			//0x2342ab44
			sp.dwOutFunction = 0x3d; //FAPI_GPIO_OUT_AD3_DATA
			sp.bPin = 0x1f;
			gpio_open(&sp, &auoutI2s[3].hGpio[0]);

			sp.dwOutFunction = 0x3f; //FAPI_GPIO_OUT_AD3_BCLK
			sp.bPin = 0x19;
			gpio_open(&sp, &auoutI2s[3].hGpio[1]);

			sp.dwOutFunction = 0x3e; //FAPI_GPIO_OUT_AD3_LRCLK
			sp.bPin = 0x1a;
			gpio_open(&sp, &auoutI2s[3].hGpio[2]);

			sp.dwOutFunction = 0x40; //FAPI_GPIO_OUT_AD3_CLK
			sp.bPin = 0x1b;
			gpio_open(&sp, &auoutI2s[3].hGpio[3]);
		}
		//loc_2342aba8
	} //for (uint32_t i = 0; i < 4; i++)
	//0x2342abb4
}


/* 2342abf8 / sub_23435fd8 - todo */
int aout_init(void* a)
{
	uint32_t val;

#if 1
	console_send_string("aout_init (todo.c): TODO\r\n");
#endif

	if (aout_sema != 0)
	{
		return 4;
	}

	Data_2349251c = a;

	for (uint32_t r7 = 0; r7 < 2; r7++)
	{
		//loc_2342ac24
		Struct_2349251c* r6 = &Data_2349251c[r7];

		memset(r6, 0, sizeof(Struct_2349251c));

		r6->Data_0x24 = -1; //r8
		r6->spdifSampleFreq = -1; //r8
		r6->Data_0x2c = 0; //r5
		r6->Data_0x30 = -1; //r8
		r6->Data_0x34 = -1; //r8

		for (uint32_t r0 = 0; r0 < 8; r0++)
		{
			//loc_2342ac54
			r6->speakerArr[r0] = -1; //r8
		}
		//0x2342ac68
		for (uint32_t r0 = 0; r0 < 4; r0++)
		{
			//loc_2342ac6c
			r6->i2sBufferArr[r0].i2sId = -1; //r8
			r6->i2sBufferArr[r0].leftCh = -1; //r8
			r6->i2sBufferArr[r0].rightCh = -1; //r8
		}
		//0x2342ac88
	} //for (uint32_t r7 = 0; r7 < 2; r7++)
	//0x2342ac94
	FREG(0xcc000004)[0]; //INTERRUPT_SRC
	FREG(0xcc000000)[0] = 0x27ff; //INTERRUPT_MASK

	aout_SetInterruptMask_IntPtsFound(1);

	for (uint32_t ii = 0; ii < 8; ii++)
	{
		//loc_2342acb4
		auoutSpeakerI2s[ii] = -1; //r8
	}
	//0x2342acc4
	for (uint32_t ii = 0; ii < 4; ii++)
	{
		//loc_2342accc
		if (auoutI2s[ii].leftCh > -1)
		{
			//0x2342ace0
			if (auoutSpeakerI2s[ auoutI2s[ii].leftCh ] != -1)
			{
				//loc_2342ad08
				return 0xff;
			}

			auoutSpeakerI2s[ auoutI2s[ii].leftCh ] = ii;
		}
		//loc_2342acf0
		if (auoutI2s[ii].rightCh > -1)
		{
			//0x2342ace0
			if (auoutSpeakerI2s[ auoutI2s[ii].rightCh ] != -1)
			{
				//loc_2342ad08
				return 0xff;
			}
			//loc_2342ad10
			auoutSpeakerI2s[ auoutI2s[ii].rightCh ] = ii;
		}
		//loc_2342ad14
		if ((auoutI2s[ii].bitClk == 1) && (auoutI2s[ii].aoClk == 0))
		{
			return 1;
		}
		//0x2342ad2c
	} //for (uint32_t ii = 0; ii < 4; ii++)
	//0x2342ad38
	for (uint32_t r0 = 0; r0 < 8; r0++)
	{
		//loc_2342ad3c
		/* empty */
	}

	//-------------------------------
	// set I2S initialization parameter
	//-------------------------------
	for (uint32_t ii = 0; ii < 4; ii++)
	{
		//loc_2342ad4c
		volatile uint32_t* r0 = &FREG(0xcc000000)[ii];

		r0[2] = 0; // r5; //I2S_CONFIG

		val = (auoutI2s[ii].aoClk & 1);
		r0[2] = (r0[2] & ~0x01) | val; //CLK_SEL

		val = ((auoutI2s[ii].bitClk << 1) & 0x06);
		r0[2] = (r0[2] & ~0x06) | val; //BCLK_SEL

		val = ((auoutI2s[ii].format << 3) & 0x18);
		r0[2] = (r0[2] & ~0x18) | val; //OUTPUT_FORMAT

		val = ((auoutI2s[ii].lrClkInv << 6) & 0x40);
		r0[2] = (r0[2] & ~0x40) | val; //LRCLK_INV

		// mute unused I2S channels
		int mute = 0;
		if (auoutI2s[ii].leftCh == -1)
		{
			mute |= 2;
		}

		if (auoutI2s[ii].rightCh == -1)
		{
			mute |= 1;
		}

		val = ((mute << 17) & 0x180);
		r0[2] = (r0[2] & ~0x180) | val; //MUTE

		r0[6] = 0; //I2S_SAMPLE_VALUE
		r0[10] = 0; //I2S_VOLUME_CONTROL
		//0x2342ae04
	} //for (uint32_t ii = 0; ii < 4; ii++)
	//0x2342ae10
	//-------------------------------
	// set DAC initialization parameter
	//-------------------------------
	FREG(0xcc000090)[0] = 0; //r5 //DAC_CONTROL

	if (auoutDacConnect != -1)
	{
		//0x2342ae20
		val = auoutDacConnect & 0x03;
		FREG(0xcc000090)[0] = (FREG(0xcc000090)[0] & ~0x03) | val; //IN_SEL

		int r0 = auoutI2s[ auoutDacConnect ].aoClk;
		switch (r0)
		{
		case 0:
			//loc_2342af30
			aout_SetDacControl_Osr(1);
			//r0, #0x0
			//->loc_2342ae5c
			aout_SetDacControl_Fsys(0);
			//loc_2342ae60
			break;

		case 1:
			aout_SetDacControl_Osr(0);
			aout_SetDacControl_Fsys(1);
			break;
		}
	}
	//loc_2342ae60
	//-------------------------------
	// set SPDIF initialization parameter
	//-------------------------------
	FREG(0xcc00005c)[0] = 0; //GENERAL_CONTROL_1

	aout_SetGeneralControl_1_SpdifSwChannel(auoutSpdif.swChannel);

	val = (auoutSpdif.parity << 11) & 0x800;
	FREG(0xcc00005c)[0] = (FREG(0xcc00005c)[0] & ~0x800) | val; //SPDIF_PARITY

	FREG(0xcc00005c)[0] = (FREG(0xcc00005c)[0] & ~0x3e0) | 0x220; //SpdifLsbLocation

	aout_SetGeneralControl_1_SpdifClear(1);
	aout_SetGeneralControl_1_SpdifClear(0);

	FREG(0xcc000060)[0] = 0x1f0; //GENERAL_CONTROL_2
	FREG(0xcc000060)[0] |= 0x800; //CONV_ENH_EN

	aout_SetGeneralControl_2_ClkSel(auoutSpdif.amcClk);

	FREG(0xcc00006c)[0] = 0; //AMC_PC
	FREG(0xcc000070)[0] = 0; //AMC_PD
	FREG(0xcc000074)[0] = 0; //AMC_HEADER
	FREG(0xcc000078)[0] = 0; //AMC_REPETITION_PERIOD
	FREG(0xcc00008c)[0] = 0; //AMC_SAMPLE_VALUE
	FREG(0xcc000058)[0] = 0; //GENERAL_CONTROL_0
	FREG(0xcc000064)[0] = 0; //GENERAL_CONTROL_3

	aout_SetFdclksel_Selfd1clk(1);
	aout_SetFdclksel_Selfd2clk(1);

	intr_set_isr(auout_isr, 0, 23); //FAPI_INTR_AUDIO
	sub_2341b3b8(23, 0);

#if 1
	console_send_string("aout_init: isr enabled\r\n");
#endif

	FREG(0xe000025c)[0] = 0xf;

	aout_sema = OSSemCreate(1);

	return 0;
}


/* 2342af40 / 2343632c - todo */
int auout_open(AUOUT_OpenParams* paramsPtr, void** pHandle)
{
	uint8_t err;
	Struct_2349251c* auout_handle_ptr = 0;

#if 0
	console_send_string("auout_open (todo.c): TODO\r\n");
#endif

	OSSemPend(aout_sema, 0, &err);

	if (err == 0)
	{
		for (uint8_t r0 = 0; r0 < 2; r0++)
		{
			//loc_2342af7c
			if (Data_2349251c[r0].inUse == 0)
			{
				auout_handle_ptr = &Data_2349251c[r0];

				auout_handle_ptr->inUse = 1; //r3
				auout_handle_ptr->id = AUOUT_HANDLE_ID;
				//->loc_2342afb4
				break;
			}
			//0x2342afa4
		} //for (uint8_t r0 = 0; r0 < 2; r0++)
		//loc_2342afb4
		if (auout_handle_ptr == 0)
		{
			OSSemPost(aout_sema);

			return 2;
		}
		//loc_2342afcc
		if (Data_234924f0 == (1 | 2))
		{
			//loc_2342afd8
			OSSemPost(aout_sema);

			return 0;
		}
	}
	else
	{
		//->loc_2342afe0
		return 0;
	}
	//loc_2342afe8
	if ((Data_234924f0 & 2) == 0)
	{
		Data_234924f0 |= 2;

		auout_handle_ptr->fdClk = 2;
		//->loc_2342b010
	}
	else if ((Data_234924f0 & 1) == 0)
	{
		Data_234924f0 |= 1;

		auout_handle_ptr->fdClk = 1; //r3
	}
	//loc_2342b010
	if (paramsPtr->enableSPDIF != 0)
	{
		//0x2342b01c
		for (uint8_t r0 = 0; r0 < 2; r0++)
		{
			//loc_2342b024
			if (&Data_2349251c[r0] == auout_handle_ptr)
			{
				auoutSpdifEnabIndex = r0;

				auout_handle_ptr->useSPDIF = 1; //r3
				auout_handle_ptr->audioClk = auoutSpdif.amcClk;
				//->loc_2342b058
				break;
			}
			//0x2342b048
		} //for (uint8_t r0 = 0; r0 < 2; r0++)
		//loc_2342b058
	}
	//loc_2342b058
	auout_handle_ptr->speakerCount = 0; //r7
	auout_handle_ptr->i2sBufferCount = 0; //r7

	for (uint8_t ii = 0; ii < AUOUT_SPEAKER_ALL; ii++)
	{
		//loc_2342b06c
		uint32_t i2s_id;
		uint32_t speaker_id;
		AUOUT_I2sBuffer* i2s_buffer_ptr;

		speaker_id = paramsPtr->speakerArr[ii];

		if (speaker_id == -1)
		{
			//->loc_2342b138
			break;
		}
		//0x2342b07c
		if (speaker_id < AUOUT_SPEAKER_ALL)
		{
			//0x2342b084
			auout_handle_ptr->speakerArr[ii] = speaker_id;

			auout_handle_ptr->speakerCount++;

			i2s_id = auoutSpeakerI2s[speaker_id];
			if (i2s_id < 4)
			{
				//0x2342b0a8
				i2s_buffer_ptr = 0;

				for (uint8_t jj = 0; jj < AUOUT_I2S_ALL; jj++)
				{
					//loc_2342b0b0
					if (auout_handle_ptr->i2sBufferArr[jj].i2sId == i2s_id)
					{
						i2s_buffer_ptr = &auout_handle_ptr->i2sBufferArr[jj];
						//->loc_2342b0f8
						break;
					}
					//0x2342b0c8
					if (auout_handle_ptr->i2sBufferArr[jj].i2sId == -1)
					{
						i2s_buffer_ptr = &auout_handle_ptr->i2sBufferArr[jj];
						i2s_buffer_ptr->i2sId = i2s_id;

						auout_handle_ptr->i2sBufferCount++;
						//->loc_2342b0f8
						break;
					}
					//0x2342b0e8
				} //for (uint8_t jj = 0; jj < 4; jj++)
				//loc_2342b0f8
				if (i2s_buffer_ptr == 0)
				{
					//->loc_2342b138
					break;
				}
				//0x2342b100
				if (auoutI2s[i2s_id].leftCh == speaker_id)
				{
					i2s_buffer_ptr->leftCh = speaker_id;
				}

				if (auoutI2s[i2s_id].rightCh == speaker_id)
				{
					i2s_buffer_ptr->rightCh = speaker_id;
				}

				auout_handle_ptr->audioClk = auoutI2s[i2s_id].aoClk;
			} //if (r3 < 4)
			//loc_2342b128
		} //if (r1 < 8)
		//loc_2342b128
	} //for (uint8_t ii = 0; ii < 8; ii++)
	//loc_2342b138
	if (0 == sub_2342a504(auout_handle_ptr, paramsPtr))
	{
		//->loc_2342afd8
		OSSemPost(aout_sema);

		return 0;
	}
	//0x2342b14c
	auoutEnableHardware(auout_handle_ptr);

	auoutOpenGpio(auout_handle_ptr);

	*pHandle = auout_handle_ptr;

	Data_234924fc = paramsPtr->Data_0x4c;
	Data_23492500 = paramsPtr->Data_0x50;

	auout_handle_ptr->Data_0x98 = 0; //r7;
	//->loc_2342afd8
	OSSemPost(aout_sema);

	return 0;
}


/* 2342b178 - complete */
void auout_set_volume(void* handle, int speaker, int volume)
{
	uint8_t sp;
	Struct_2349251c* auout_handle_ptr = handle;

#if 0
	console_send_string("auout_set_volume (todo.c): TODO\r\n");
#endif

	OSSemPend(aout_sema, 0, &sp);

	if (speaker == AUOUT_SPEAKER_ALL)
	{
		for (uint32_t i = 0; i < 4; i++)
		{
			//loc_2342b1a8
			AUOUT_I2sBuffer* i2s_buffer_ptr = &auout_handle_ptr->i2sBufferArr[i];

			int i2s_index = i2s_buffer_ptr->i2sId;
			if (i2s_index == -1)
			{
				//->loc_2342b250
				break;
			}
			//0x2342b1bc
			if (i2s_buffer_ptr->leftCh != -1)
			{
				aout_SetI2sVolumeControl_VolumeLeft(i2s_index, volume);
			}

			if (i2s_buffer_ptr->rightCh != -1)
			{
				aout_SetI2sVolumeControl_VolumeRight(i2s_index, volume);
			}
			//0x2342b1e4
		} //for (uint32_t i = 0; i < 4; i++)
		//0x2342b1f0 -> loc_2342b250
	}
	//loc_2342b1f4
	else if (speaker != AUOUT_SPEAKER_UNDEF) //-1)
	{
		//0x2342b1fc
		for (uint32_t i = 0; i < 4; i++)
		{
			//loc_2342b200
			AUOUT_I2sBuffer* i2s_buffer_ptr = &auout_handle_ptr->i2sBufferArr[i];

			int i2s_index = i2s_buffer_ptr->i2sId;
			if (i2s_index == -1)
			{
				//->loc_2342b250
				break;
			}
			//0x2342b214
			if (i2s_buffer_ptr->leftCh == speaker)
			{
				aout_SetI2sVolumeControl_VolumeLeft(i2s_index, volume);
				//->loc_2342b250
				break;
			}
			//loc_2342b22c
			if (i2s_buffer_ptr->rightCh == speaker)
			{
				aout_SetI2sVolumeControl_VolumeRight(i2s_index, volume);
				//->loc_2342b250
				break;
			}
			//loc_2342b244
		} //for (uint32_t i = 0; i < 4; i++)
		//loc_2342b250
	}
	//loc_2342b250
	OSSemPost(aout_sema);
}


/* 2342b2ac - todo */
int sub_2342b2ac(void* a, int r8)
{
	uint8_t sp;
	Struct_2349251c* r5 = a;

#if 0
	console_send_string("sub_2342b2ac (todo.c): TODO\r\n");
#endif

	OSSemPend(aout_sema, 0, &sp);
	if (sp == 0)
	{
		for (uint8_t r4 = 0; r4 < r5->i2sBufferCount; r4++)
		{
			//loc_2342b2e0
			sub_2341e4a8(r5->i2sBufferArr[r4].bmHandle, 0, 0);
			sub_2341e524(r5->i2sBufferArr[r4].bmHandle, 0, 0);
		}
		//0x2342b318
		if (r5->spdifBufferHandle != 0)
		{
			sub_2341e4a8(r5->spdifBufferHandle, 0, 0);
			sub_2341e524(r5->spdifBufferHandle, 0, 0);

			if (r8 != 0)
			{
				sub_2341e600(r5->spdifBufferHandle, 1);
			}
		}
		//loc_2342b350
		OSSemPost(aout_sema);
	}

	return 0;
}

#if 0

/* 2342b360 - todo */
int auout_start_hdmi(void* handle)
{
	Struct_2349251c* auout_handle_ptr = handle;

#if 0
	console_send_string("auout_start_hdmi (todo.c): TODO\r\n");
#endif

	int index;
	int hdmi_error;

	int i2s0_found = 0;

	uint8_t err;
	Struct_2342499c hdmi_params = {0}; //sp8
	Struct_234248a0 hdmi_open_params; //sp;

	OSSemPend(aout_sema, 0, &err);

	//sl, #0x0
	//fp, #0x2

	if (auoutHdmiHandle == 0)
	{
		hdmi_open_params.Data_0 = 2; //fp
		hdmi_open_params.Data_4 = 0; //sl

		hdmi_open(&hdmi_open_params, &auoutHdmiHandle);

		if (auoutHdmiHandle == 0)
		{
			OSSemPost(aout_sema);
			//->loc_2342b3e0
			return 0xff;
		}
	}
	//loc_2342b3d0
	if (auout_handle_ptr == 0)
	{
		//0x2342b3d8
		hdmi_audio_start(auoutHdmiHandle);
		//loc_2342b3e0
		return 0xff;
	}
	//loc_2342b3ec
	if (auoutHdmiEnabIndex >= 0)
	{
		hdmi_audio_stop(auout_handle_ptr);
	}

	FAPI_SYS_InvalidateDataCache(auout_handle_ptr, sizeof(Struct_2349251c));

	int sf_index;

	switch (auout_handle_ptr->spdifSampleFreq)
	{
	case 8000:
	case 12000:
	case 16000:
	case 22050:
	case 24000:
		//->loc_2342b3c4
		OSSemPost(aout_sema);
		//->loc_2342b3e0
		return 0xff;
		break;

	case 32000:
		sf_index = 5;
		//->loc_2342b478
		break;

	case 44100:
		sf_index = 6;
		//->loc_2342b478
		break;

	case 48000:
		sf_index = 7;
		//->loc_2342b478
		break;

	case 96000:
		sf_index = 8;
		//loc_2342b478
		break;

	default:
		//->loc_2342b3c4
		OSSemPost(aout_sema);
		//->loc_2342b3e0
		return 0xff;
		break;
	}
	//loc_2342b478
	//r7, sp, #0x8
	for (uint32_t ii = 0; ii < 4; ii++)
	{
		//loc_2342b480
		int r1 = auout_handle_ptr->i2sBufferArr[ii].i2sId;
		if (r1 == -1)
		{
			//->loc_2342b514
			break;
		}

		//AUOUT_I2sBuffer* r1_;
		//void* r0;

		if (r1 == 0)
		{
			i2s0_found = 1;
			hdmi_params.mode |= 0x10;
			//r1_ = &auout_handle_ptr->i2sBufferArr[ii];
			//r0 = &hdmi_params.speakerMapping;
			//->loc_2342b504
			auoutSetHdmiSpeakerMapping(&hdmi_params.speakerMapping[0], &auout_handle_ptr->i2sBufferArr[ii]);
		}
		else if (r1 == 1)
		{
			hdmi_params.mode |= 0x20;
			//r1_ = &auout_handle_ptr->i2sBufferArr[ii];
			//r0 = &hdmi_params.Data_0x24;
			//->loc_2342b504
			auoutSetHdmiSpeakerMapping(&hdmi_params.speakerMapping[1], &auout_handle_ptr->i2sBufferArr[ii]);
		}
		else if (r1 == 2)
		{
			hdmi_params.mode |= 0x40;
			//r1_ = &auout_handle_ptr->i2sBufferArr[ii];
			//r0 = &hdmi_params.Data_0x28;
			//->loc_2342b504
			auoutSetHdmiSpeakerMapping(&hdmi_params.speakerMapping[2], &auout_handle_ptr->i2sBufferArr[ii]);
		}
		else if (r1 == 3)
		{
			hdmi_params.mode |= 0x80;
			//r1_ = &auout_handle_ptr->i2sBufferArr[ii];
			//r0 = &hdmi_params.Data_0x2c;
			//->loc_2342b504
			auoutSetHdmiSpeakerMapping(&hdmi_params.speakerMapping[3], &auout_handle_ptr->i2sBufferArr[ii]);
		}
		//loc_2342b508
	} //for (uint32_t ii = 0; ii < 4; ii++)
	//loc_2342b514
	if (i2s0_found != 0)
	{
		//0x2342b524
		hdmi_params.audioClock = (auoutI2s[0].aoClk == 0)? 1: 2;
		hdmi_params.polarity = auoutI2s[0].lrClkInv;
		hdmi_params.format = auoutI2s[0].format + 1;
		//->loc_2342b580
	}
	else
	{
		//loc_2342b554
		if (auout_handle_ptr->useSPDIF == 0)
		{
			//->loc_2342b3c4
			OSSemPost(aout_sema);
			//->loc_2342b3e0
			return 0xff;
		}
		//0x2342b560
		hdmi_params.polarity = 0; //sl;
		hdmi_params.mode = 2; //fp;
		hdmi_params.audioClock = (auoutSpdif.amcClk == 0)? 1: 2;
	}
	//loc_2342b580
	int clkpwr_audio = auoutClkpwrFd12Audio[auout_handle_ptr->audioClk][sf_index];
	int clkpwr_prescale = auoutClkpwrFd12Prescale[auout_handle_ptr->audioClk][sf_index];

	for (index = 0; index < 2; index++)
	{
		//loc_2342b5a4
		if (&Data_2349251c[index] == auout_handle_ptr)
		{
			//->loc_2342b5c4
			break;
		}

	} //for (int index = 0; index < 2; index++)
	//0x2342b5c0 -> loc_2342b3c4
	//loc_2342b5c4
	if (index >= 2)
	{
		//->loc_2342b3c4
		OSSemPost(aout_sema);
		//->loc_2342b3e0
		return 0xff;
	}
	//0x2342b5cc
	hdmi_error = hdmi_SetAudioParameters(auoutHdmiHandle, &hdmi_params);
	if (hdmi_error == 0)
	{
		//0x2342b5e0
		hdmi_error = hdmi_SetAudioSampleFrequency(auoutHdmiHandle, sf_index - 4);
		if (hdmi_error == 0)
		{
			//0x2342b5f4
			if (FREG(0xca000028)[0] == 0)
			{
				//0x2342b604
				FREG(0xca00005c)[0] &= ~0x80000000; //FD2AUDIO:reset_FD2

				int mask = (0xff << 24);
				int val = (clkpwr_prescale << 24) & mask;
				FREG(0xca000050)[0] = (FREG(0xca000050)[0] & ~mask) | val; //FDPRESCALE

				FREG(0xca00005c)[0] = clkpwr_audio;
			}
			//loc_2342b62c
			auoutHdmiEnabIndex = index;

			OSSemPost(aout_sema);

			if (Data_23492508 != 0)
			{
				sub_234250c4(auoutHdmiHandle, 1);
			}

			int r0 = hdmi_audio_start(auoutHdmiHandle);
			//->loc_2342b3e4
			return r0;
		}
		else
		{
			//loc_2342b658
			OSSemPost(aout_sema);

			return hdmi_error;
		}
	}
	else
	{
		//loc_2342b658
		OSSemPost(aout_sema);

		return hdmi_error;
	}
}


/* 2342b668 - complete */
void auout_stop_hdmi()
{
#if 0
	console_send_string("auout_stop_hdmi (todo.c): TODO\r\n");
#endif

	if (auoutHdmiEnabIndex < 0)
	{
		return;
	}

	hdmi_audio_stop(auoutHdmiHandle);

	auoutHdmiEnabIndex = -1;
}

#endif

/* 2342b690 - todo */
void sub_2342b690(void* a, int pid)
{
#if 0
	console_send_string("sub_2342b690 (todo.c): TODO\r\n");
#endif

	uint8_t err;
	struct
	{
		int Data_0; //0
		int Data_4; //4
		int Data_8; //8
		int Data_12; //12
		int Data_16; //16
		//20 = 0x14
	} sp4;

	Struct_2349251c* r4 = a;

	memset(&sp4, 0, sizeof(sp4));

	OSSemPend(aout_sema, 0, &err);

	aout_SetGeneralControl_1_SpdifSwChannel(1);
	aout_SetGeneralControl_3_SyncI2s3(0);
	aout_SetGeneralControl_2_PassThrough(0);
	aout_SetAmcPc_PcmEn(0);
	aout_SetGeneralControl_2_ClkSel(0);

	sub_2341e8dc(r4->spdifBufferHandle, 1, 1, 0);
	sub_2341e8b0(r4->spdifBufferHandle, 0);
	sub_2341e600(r4->spdifBufferHandle, 0);
	sub_2341e4a8(r4->spdifBufferHandle, 0, 0);
	sub_2341e524(r4->spdifBufferHandle, 0, 0);
	aout_SetGeneralControl_0_SwAmcClk(1);

	sp4.Data_0 = 0x40;
	sp4.Data_12 = 0x40;

	aout_SetGeneralControl_1_EnableBits(0);

	aout_SetGeneralControl_1_SpdifClear(1);
	aout_SetGeneralControl_1_SpdifClear(0);

	aout_SetAmcSpdif_ToSpdifChannel(sp4.Data_0);
	aout_SetAmcSpdif_ToSpdifChannel(sp4.Data_4);
	aout_SetAmcSpdif_ToSpdifChannel(sp4.Data_8);
	aout_SetAmcSpdif_ToSpdifChannel(sp4.Data_12);
	aout_SetAmcSpdif_ToSpdifChannel(sp4.Data_16);

	aout_SetGeneralControl_1_EnableBits(1);

	if (Data_2349251c->Data_0x9c != 0)
	{
		Data_23492504 = 0;
		//->loc_2342b7b8
	}
	else
	{
		//0x2342b7a8
		Data_23492504 = sub_23429f78;

		sub_23429f78(-1);
	}
	//loc_2342b7b8
	sub_2341e600(r4->spdifBufferHandle, 1);

	Data_2349250c = 0;

	tsd_set_pes_pid_filter(Data_234924f8, pid);
	tsd_activate_pid_channel(Data_234924f8);

	OSSemPost(aout_sema);
}


/* 2342b7ec - todo */
void aout_reset(void* a)
{
	uint32_t arI2sConfig[4] = {0};
	uint32_t arGeneralControl[4] = {0};
	struct
	{
		int Data_0; //0
		int Data_4; //4
		int Data_8; //8
		int Data_12; //12
		int Data_16; //16
		//20 = 0x14
	} sp4 = {0};
	uint8_t err;

#if 0
	console_send_string("aout_reset (todo.c): TODO\r\n");
#endif

	Struct_2349251c* r4 = a;

	int r5 = r4->fdClk - 1;
	if (r5 != 0)
	{
		r5 = 1;
	}

	OSSemPend(aout_sema, 0, &err);

	tsd_deactivate_pid_channel(Data_234924f8);

	aout_SetGeneralControl_1_SpdifSwChannel(auoutSpdif.swChannel);

	sub_2341e8b0/*23429db8*/(r4->spdifBufferHandle, 1);
	sub_2341e8dc/*23429de4*/(r4->spdifBufferHandle, 0, 0, 0);

	int r8 = FREG(0xcc000100)[0]; //HWB_CONTENT
	int r7 = FREG(0xcc000090)[0]; //DAC_CONTROL

	arI2sConfig[0] = FREG(0xcc000008)[0]; //I2S_CONFIG[0]
	arI2sConfig[1] = FREG(0xcc00000C)[0]; //I2S_CONFIG[1]
	arI2sConfig[2] = FREG(0xcc000010)[0]; //I2S_CONFIG[2]
	arI2sConfig[3] = FREG(0xcc000014)[0]; //I2S_CONFIG[3]

	arGeneralControl[0] = FREG(0xcc000058)[0]; //GENERAL_CONTROL_0
	arGeneralControl[1] = FREG(0xcc00005C)[0]; //GENERAL_CONTROL_1
	arGeneralControl[2] = FREG(0xcc000060)[0]; //GENERAL_CONTROL_2
	arGeneralControl[3] = FREG(0xcc000064)[0]; //GENERAL_CONTROL_3

	aout_SetConfigdmacaudio_Confdmacau23(0);
	aout_SetConfigdmacaudio_Confdmacau23(1);

	FREG(0xcc000008)[0] = arI2sConfig[0]; //I2S_CONFIG[0]
	FREG(0xcc00000C)[0] = arI2sConfig[1]; //I2S_CONFIG[1]
	FREG(0xcc000010)[0] = arI2sConfig[2]; //I2S_CONFIG[2]
	FREG(0xcc000014)[0] = arI2sConfig[3]; //I2S_CONFIG[3]

	FREG(0xcc000058)[0] = arGeneralControl[0]; //GENERAL_CONTROL_0
	FREG(0xcc00005C)[0] = arGeneralControl[1]; //GENERAL_CONTROL_1
	FREG(0xcc000060)[0] = arGeneralControl[2]; //GENERAL_CONTROL_2
	FREG(0xcc000064)[0] = arGeneralControl[3]; //GENERAL_CONTROL_3

	FREG(0xcc000090)[0] = r7; //DAC_CONTROL
	FREG(0xcc000100)[0] = r8; //HWB_CONTENT

	FREG(0xcc000004)[0]; //INTERRUPT_SRC
	FREG(0xcc000000)[0] = 0x27ff; //INTERRUPT_MASK

	aout_SetInterruptMask_IntPtsFound(1);
	aout_SetGeneralControl_0_SwAmcClk(r5);
	aout_SetGeneralControl_3_SyncI2s3(1);
	aout_SetGeneralControl_2_PassThrough(1);
	aout_SetGeneralControl_0_SwAmcClk(1);

	sp4.Data_12 = 0x40;
	sp4.Data_0 = 0;

	aout_SetGeneralControl_1_EnableBits(0); //r4

	aout_SetGeneralControl_1_SpdifClear(1);
	aout_SetGeneralControl_1_SpdifClear(0);

	aout_SetAmcSpdif_ToSpdifChannel(sp4.Data_0);
	aout_SetAmcSpdif_ToSpdifChannel(sp4.Data_4);
	aout_SetAmcSpdif_ToSpdifChannel(sp4.Data_8);
	aout_SetAmcSpdif_ToSpdifChannel(sp4.Data_12);
	aout_SetAmcSpdif_ToSpdifChannel(sp4.Data_16);

	aout_SetAmcPc_PcmEn(1);

	Data_23492504 = 0; //r4

	OSSemPost(aout_sema);
}


/* 2342b9bc - complete */
void sub_2342b9bc(void* a, int b, int c)
{
#if 0
	console_send_string("sub_2342b9bc (todo.c): TODO\r\n");
#endif

	Struct_2349251c* r0 = a;

	r0->useSPDIF = b;
	Data_23492508 = c;
}


/* 2342b9cc - complete */
void sub_2342b9cc(void* a, int b)
{
#if 0
	console_send_string("sub_2342b9cc (todo.c): TODO\r\n");
#endif

	Struct_2349251c* r0 = a;

	r0->Data_0x9c = b;
}


/* 2342b9d4 - complete */
int sub_2342b9d4(void* a)
{
#if 0
	console_send_string("sub_2342b9d4 (todo.c): TODO\r\n");
#endif

	Struct_2349251c* r0 = a;

	return r0->Data_0xa0;
}


/* 2342b9dc - complete */
int sub_2342b9dc(void* a)
{
#if 0
	console_send_string("sub_2342b9dc (todo.c): TODO\r\n");
#endif

	Struct_2349251c* r0 = a;

	return r0->Data_0x2c;
}


/* 2342b9e4 - complete */
int sub_2342b9e4(void* a, int b)
{
#if 0
	console_send_string("sub_2342b9e4 (todo.c): TODO\r\n");
#endif

	Struct_2349251c* r0 = a;
	int r2 = r0->Data_0xa4;

	r0->Data_0xa4 = b;

	return r2;
}


/* 2342b9f4 - complete */
int sub_2342b9f4(void* a)
{
#if 0
	console_send_string("sub_2342b9f4 (todo.c): TODO\r\n");
#endif

	Struct_2349251c* r0 = a;

	return r0->Data_0xa8;
}


/* 2342b9fc - complete */
void sub_2342b9fc(void* a, int b)
{
#if 0
	console_send_string("sub_2342b9fc (todo.c): TODO\r\n");
#endif

	Struct_2349251c* r0 = a;

	r0->Data_0xa8 = b;
}


/* 2342ba04 - complete */
void* sub_2342ba04()
{
#if 0
	console_send_string("sub_2342ba04 (todo.c): TODO\r\n");
#endif

	return Data_234924f8;
}


/* 2342ba10 - todo */
int sub_2342ba10()
{
	int r4;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_2342ba10 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	r4 = Data_2349250c;
	Data_2349250c = 0;

	OS_EXIT_CRITICAL();

	return r4;
}


/* 2342ba34 - complete */
void sub_2342ba34(int r4)
{
	uint8_t sp;
//	int r1;

#if 0
	console_send_string("sub_2342ba34 (todo.c): TODO\r\n");
#endif

	OSSemPend(aout_sema, 0, &sp);

	if (r4 == 0)
	{
		//r1 = 0;
		aout_SetI2sConfig_DualMono(0, 0); //left and right channels behave as usual
	}
	else if (r4 == 1)
	{
		//r1 = 3;
		aout_SetI2sConfig_DualMono(0, 3); //left channel data on both output channels
	}
	else if (r4 == 2)
	{
		//r1 = 2;
		aout_SetI2sConfig_DualMono(0, 2); //right channel data on both output channels
	}

	OSSemPost(aout_sema);
}


/* 2342baa4 - complete */
void aout_SetInterruptMask_IntPtsFound(int a)
{
#if 0
	console_send_string("aout_SetInterruptMask_IntPtsFound (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 12) & (1 << 12));

	FREG(0xcc000000)[0] = (FREG(0xcc000000)[0] & ~(1<< 12)) | val; //INT_PTS_FOUND

}


/* 2342bac4 - complete */
void aout_SetI2sConfig_DualMono(int a, int b)
{
#if 0
	console_send_string("aout_SetInterruptMask_IntPtsFound (todo.c): TODO\r\n");
#endif

	uint32_t val = ((b << 10) & 0xc00);

	FREG(0xcc000008)[a] = (FREG(0xcc000008)[a] & ~0xc00) | val; //I2S_CONFIG:DUAL_MONO
}


/* 2342bae8 - complete */
void aout_SetI2sConfig_OutputEnable(int a, int b)
{
#if 0
	console_send_string("aout_SetI2sConfig_OutputEnable (todo.c): TODO\r\n");
#endif

	uint32_t val = (b << 9) & (1 << 9);

	FREG(0xcc000008)[a] = (FREG(0xcc000008)[a] & ~(1 << 9)) | val; //I2S_CONFIG:OUTPUT_ENABLE
}


/* 2342bb0c - complete */
void aout_SetI2sVolumeControl_VolumeLeft(int a, int b)
{
#if 0
	console_send_string("aout_SetI2sVolumeControl_VolumeLeft (todo.c): TODO\r\n");
#endif

	uint32_t val = (b << 8) & (0xff << 8);

	FREG(0xcc000028)[a] = (FREG(0xcc000028)[a] & ~(0xff << 8)) | val; //I2S_VOLUME_CONTROL:VOLUME_LEFT
}


/* 2342bb30 - complete */
void aout_SetI2sVolumeControl_VolumeRight(int a, int b)
{
#if 0
	console_send_string("aout_SetI2sVolumeControl_VolumeRight (todo.c): TODO\r\n");
#endif

	uint32_t val = (b << 0) & (0xff << 0);

	FREG(0xcc000028)[a] = (FREG(0xcc000028)[a] & ~(0xff << 0)) | val; //I2S_VOLUME_CONTROL:VOLUME_RIGHT
}


/* 2342bb50 - complete */
void aout_SetGeneralControl_0_EnableSpdif(int a)
{
#if 0
	console_send_string("aout_SetGeneralControl_0_EnableSpdif (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 9) & (1 << 9));

	FREG(0xcc000058)[0] = (FREG(0xcc000058)[0] & ~(1 << 9)) | val; //GENERAL_CONTROL_0:ENABLE_SPDIF
}


/* 2342bb70 - complete */
void aout_SetGeneralControl_0_SwAmcClk(int a)
{
#if 0
	console_send_string("aout_SetGeneralControl_0_SwAmcClk (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 4) & (1 << 4));

	FREG(0xcc000058)[0] = (FREG(0xcc000058)[0] & ~(1 << 4)) | val; //GENERAL_CONTROL_0:SW_AMC_CLK
}


/* 2342bb90 - complete */
void aout_SetGeneralControl_1_SpdifSwChannel(int a)
{
#if 0
	console_send_string("aout_SetGeneralControl_1_SpdifSwChannel (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 12) & (1 << 12));

	FREG(0xcc00005c)[0] = (FREG(0xcc00005c)[0] & ~(1<< 12)) | val; //Switch channel 1 and channel 2
}


/* 2342bbb0 - complete */
void aout_SetGeneralControl_1_EnableBits(int a)
{
#if 0
	console_send_string("aout_SetGeneralControl_1_EnableBits (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 2) & (1 << 2));

	FREG(0xcc00005c)[0] = (FREG(0xcc00005c)[0] & ~(1 << 2)) | val; //GENERAL_CONTROL_1:ENABLE_BITS
}


/* 2342bbd0 - complete */
void aout_SetGeneralControl_1_SpdifClear(int a)
{
#if 0
	console_send_string("aout_SetGeneralControl_1_SpdifClear (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 0) & (1 << 0));

	FREG(0xcc00005c)[0] = (FREG(0xcc00005c)[0] & ~(1<< 0)) | val; //GENERAL_CONTROL_1:SPDIF_CLEAR
}


/* 2342bbec - complete */
void aout_SetGeneralControl_2_PassThrough(int a)
{
#if 0
	console_send_string("aout_SetGeneralControl_2_PassThrough (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 10) & (1 << 10));

	FREG(0xcc000060)[0] = (FREG(0xcc000060)[0] & ~(1 << 10)) | val; //GENERAL_CONTROL_2:PASS_THROUGH
}


/* 2342bc0c - complete */
void aout_SetGeneralControl_2_ClkSel(int a)
{
#if 0
	console_send_string("aout_SetGeneralControl_2_ClkSel (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 0) & (1 << 0));

	FREG(0xcc000060)[0] = (FREG(0xcc000060)[0] & ~(1<< 0)) | val; //Frequency of AMC input clock
}


/* 2342bc28 - complete */
void aout_SetGeneralControl_3_SyncI2s3(int a)
{
#if 0
	console_send_string("aout_SetGeneralControl_3_SyncI2s3 (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 3) & (1 << 3));

	FREG(0xcc000064)[0] = (FREG(0xcc000064)[0] & ~(1 << 3)) | val; //SYNC_I2S_3
}


/* 2342bc48 - complete */
void aout_SetAmcSpdif_ToSpdifChannel(int a)
{
#if 0
	console_send_string("aout_SetAmcSpdif_ToSpdifChannel (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 8) & (0xff << 8));

	aout_AmcSpdifMirror = (aout_AmcSpdifMirror & ~(0xff << 8)) | val;

	FREG(0xcc000068)[0] = aout_AmcSpdifMirror; //AMC_SPDIF:TO_SPDIF_CHANNEL
}


/* 2342bc70 - complete */
void aout_SetAmcPc_PcmEn(int a)
{
#if 0
	console_send_string("aout_SetAmcPc_PcmEn (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 13) & (1 << 13));

	FREG(0xcc00006c)[0] = (FREG(0xcc00006c)[0] & ~(1 << 13)) | val; //AMC_PC:PCM_EN
}


/* 2342bc90 - complete */
void aout_SetDacControl_Fsys(int a)
{
#if 0
	console_send_string("aout_SetDacControl_Fsys (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 4) & 0x10);

	FREG(0xcc000090)[0] = (FREG(0xcc000090)[0] & ~0x10) | val; //System clock ratio of digital DAC
}


/* 2342bcb0 - complete */
void aout_SetDacControl_Osr(int a)
{
#if 0
	console_send_string("aout_SetDacControl_Osr (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 2) & 0x0c);

	FREG(0xcc000090)[0] = (FREG(0xcc000090)[0] & ~0x0c) | val; //Oversampling ratio of digital DAC
}


/* 2342bcd0 - complete */
void aout_SetFdclksel_Selfd1clk(int a)
{
#if 0
	console_send_string("aout_SetFdclksel_Selfd1clk (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 5) & 0x20);

	FREG(0xca000040)[0] = (FREG(0xca000040)[0] & ~0x20) | val; //FDCLKSEL:SELFD1CLK
}


/* 2342bcf0 - complete */
void aout_SetFdclksel_Selfd2clk(int a)
{
#if 0
	console_send_string("aout_SetFdclksel_Selfd2clk (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 4) & 0x10);

	FREG(0xca000040)[0] = (FREG(0xca000040)[0] & ~0x10) | val; //FDCLKSEL:SELFD2CLK
}


/* 2342bd10 - complete */
void aout_SetConfigdmacaudio_Confdmacau23(int a)
{
#if 0
	console_send_string("aout_SetConfigdmacaudio_Confdmacau23 (todo.c): TODO\r\n");
#endif

	uint32_t val = ((a << 23) & (1 << 23));

	FREG(0xca000074)[0] = (FREG(0xca000074)[0] & ~(1 << 23)) | val; //reset Audio output
}


