
#include <stdint.h>
#include "ucos_ii.h"
#include "sys_services.h"
#include "gpio.h"
#include "i2c.h"
#include "hdmi.h"


#define HDMI_OFFSET0_SYS_CTRL1        (0x08)
#define HDMI_OFFSET0_DATA_CTRL        (0x0d)
#define HDMI_OFFSET1_PB_CTRL1         (0x3e)
#define HDMI_OFFSET1_CP_BYTE1         (0xdf)
#define HDMI_OFFSET1_HW_SPDIF_FS      (0x18)


typedef struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	uint16_t wData_2; //2
	int Data_4; //4
	uint8_t edidBuffer[0x100]; //8
	int vic; //0x108
	int useDeGen; //0x10c
	int inColor; //0x110
	int outColor; //0x114
	int hdmiMode; //0x118
	int scanInfo; //0x11c
	int activeFormat; //0x120
	int fill_0x124; //0x124
	uint32_t hdcpState; //0x128
	int fill_0x12c[2]; //0x12c
	int Data_0x134; //0x134
	int fill_0x138; //0x138
	int Data_0x13c; //0x13c
	int Data_0x140; //0x140
	int channelCount; //0x144
	int channelAllocation; //0x148
	int Data_0x14c; //0x14c
	int Data_0x150; //0x150
	struct Struct_2342499c_Inner_0x20 speakerMapping[4]; //0x154
	int Data_0x164; //0x164
	int Data_0x168; //0x168
	int Data_0x16c; //0x16c
	int vsdbData6; //0x170
	int videoLatency; //0x174
	int audioLatency; //0x178
	int interlacedVideoLatency; //0x17c
	int interlacedAudioLatency; //0x180
	int audioMode; //0x184
	int audioClock; //0x188
	int audioPolarity; //0x18c
	int audioFormat; //0x190
	uint32_t chNum; //0x194
	int audioSource; //0x198
	int fs; //0x19c
	uint16_t wData_0x1a0[23]; //0x1a0
	uint16_t wData_0x1ce; //0x1ce
	uint16_t wData_0x1d0; //0x1d0
	uint16_t fill_0x1d2; //0x1d2
	//0x1d4
} hdmiHandleT;


static const uint8_t audioFormatTable[4] = //23488ae0
{
	0x45, 0x40, 0x49, 0x4d
};

static const uint8_t channelStatusTable[8] = //23488ae4
{
	0x01, 0x03, 0x00, 0x02, 0x08, 0x0a, 0x0c, 0x0e
};

static const struct
{
	int Data_0; //0
	int hActive; //4
	int hFp; //8
	int hTotal; //12
	int vActive; //16
	int vFp; //20
	int vTotal; //24
	int ratio; //0x1c = 28
	int repetition; //0x20 = 32
	int cscsel; //0x24 = 36
	//40
}
hdmiStandardVideoTiming[] = //23488aec
{
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{27000,   720, 0x00000010, 0x0000035a, 480, 0x00000009, 525, 0x00000001, 0x00000000, 0x00000000}, /*  2  720x p @ 59.94/60Hz */
	{27000,   720, 0x00000010, 0x0000035a, 480, 0x00000009, 525, 0x00000002, 0x00000000, 0x00000000}, /*  3  720x 480p @ 59.94/60Hz */
	{74250,  1280, 0x0000006e, 0x00000672, 720, 0x00000005, 750, 0x00000002, 0x00000000, 0x00000001}, /*  4 1280x 720p @ 59.94/60Hz */
	{74250,  1920, 0x00000058, 0x00000898, 540, 0x00000002, 562, 0x00000002, 0x00000000, 0x00000001}, /*  5 1920x1080i @ 59.94/60Hz */
	{27000,  1440, 0x00000026, 0x000006b4, 240, 0x00000004, 262, 0x00000001, 0x00000001, 0x00000000}, /*  6  720x 480i @ 59.94/60Hz */
	{27000,  1440, 0x00000026, 0x000006b4, 240, 0x00000004, 262, 0x00000002, 0x00000001, 0x00000000}, /*  7  720x 480i @ 59.94/60Hz */
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{27000,   720, 0x0000000c, 0x00000360, 576, 0x00000005, 625, 0x00000001, 0x00000000, 0x00000000}, /* 17  720x 576p @ 50Hz */
	{27000,   720, 0x0000000c, 0x00000360, 576, 0x00000005, 625, 0x00000002, 0x00000000, 0x00000000}, /* 18  720x 576p @ 50Hz */
	{74250,  1280, 0x000001b8, 0x000007bc, 720, 0x00000005, 750, 0x00000002, 0x00000000, 0x00000001}, /* 19 1280x 720p @ 50Hz */
	{74250,  1920, 0x00000210, 0x00000a50, 540, 0x00000002, 562, 0x00000002, 0x00000000, 0x00000001}, /* 20 1920x1080i @ 50Hz */
	{27000,  1440, 0x00000018, 0x000006c0, 288, 0x00000002, 312, 0x00000001, 0x00000001, 0x00000000}, /* 21  720x 576i @ 50Hz */
	{27000,  1440, 0x00000018, 0x000006c0, 288, 0x00000002, 312, 0x00000002, 0x00000001, 0x00000000}, /* 22  720x 576i @ 50Hz */
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
};

static const uint32_t N_value32[] = //23488eac
{
	4096, 4576, 11648, 11648
};
static const uint32_t N_value44[] = //23488ebc
{
	6272, 7007, 17836, 8918
};
static const uint32_t N_value48[] = //23488ecc
{
	6144, 6864, 11648, 5824
};


void* Data_234923ec = 0; //234923ec //i2c
void* hdmi_sema = 0; //234923f0 +4 //sema
uint8_t arData_234923f4[8] = {0}; //234923f4 +8

hdmiHandleT hdmiHandleArray[2]; //235f08c8 -> 235F0C70

struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	int Data_0xc; //0xc
	int Data_0x10; //0x10
	int fill_0x14[16]; //0x14
	int Data_0x54; //0x54
	int Data_0x58; //0x58

} Data_235f0c70; //235f0c70


int hdmiI2cWriteByte(int a, uint8_t, uint8_t);
uint8_t hdmiI2cReadByte(int a, int b);
void hdmiAvMute(int);
void hdmiI2cAndWrite(uint8_t, uint8_t, uint8_t);
void hdmiI2cOrWrite(uint8_t, uint8_t, uint8_t);
void hdmiClearInfoFrame(uint8_t infoframeType, int select);
void hdmiSendInfoFrame(uint8_t infoframeType, uint8_t select);
void hdmiSetVideoMode(hdmiHandleT* );



/* 23422cac - complete */
void hdmiInitializeVideoRegister()
{
#if 0
	console_send_string("hdmiInitializeVideoRegister (todo.c): TODO\r\n");
#endif

	hdmiI2cWriteByte(0x72, 0x0d, 0x04);
	hdmiI2cWriteByte(0x72, 0x0f, 0x00);
	hdmiI2cWriteByte(0x72, 0x27, 0x00);
	hdmiI2cWriteByte(0x72, 0x32, 0x00);
	hdmiI2cWriteByte(0x72, 0x33, 0x00);
	hdmiI2cWriteByte(0x72, 0x34, 0x00);
	hdmiI2cWriteByte(0x72, 0x36, 0x00);
	hdmiI2cWriteByte(0x72, 0x37, 0x00);
	hdmiI2cWriteByte(0x72, 0x38, 0x00);
	hdmiI2cWriteByte(0x72, 0x39, 0x00);
	hdmiI2cWriteByte(0x72, 0x3e, 0x04);
	hdmiI2cWriteByte(0x72, 0x48, 0x00);
	hdmiI2cWriteByte(0x72, 0x49, 0x00);
	hdmiI2cWriteByte(0x72, 0x4a, 0x18);
	hdmiI2cWriteByte(0x72, 0x4b, 0x00);
	hdmiI2cWriteByte(0x72, 0x4c, 0x00);
	hdmiI2cWriteByte(0x72, 0x4d, 0x00);
	hdmiI2cWriteByte(0x72, 0x75, 0x00);
	hdmiI2cWriteByte(0x72, 0x76, 0x00);
	hdmiI2cWriteByte(0x72, 0x77, 0x00);
	hdmiI2cWriteByte(0x72, 0x79, 0x02);
	hdmiI2cWriteByte(0x72, 0x82, 0x20);
	hdmiI2cWriteByte(0x72, 0xed, 0x00);
	hdmiI2cWriteByte(0x72, 0xee, 0x00);
	hdmiI2cWriteByte(0x72, 0xef, 0x00);
	hdmiI2cWriteByte(0x72, 0xf0, 0x00);
	hdmiI2cWriteByte(0x72, 0xf1, 0x00);
	hdmiI2cWriteByte(0x72, 0xf3, 0x00);
	hdmiI2cWriteByte(0x72, 0xf5, 0x00);
	hdmiI2cWriteByte(0x7a, 0x2f, 0x00);
	hdmiI2cWriteByte(0x7a, 0xdf, 0x00);
}


/* 23422ea4 - complete */
void hdmiInitializeAudioRegister()
{
#if 0
	console_send_string("hdmiInitializeAudioRegister (todo.c): TODO\r\n");
#endif

	hdmiI2cWriteByte(0x7a, 0x01, 0x02);
	hdmiI2cWriteByte(0x7a, 0x02, 0x01);
	hdmiI2cWriteByte(0x7a, 0x03, 0x00);
	hdmiI2cWriteByte(0x7a, 0x04, 0x00);
	hdmiI2cWriteByte(0x7a, 0x05, 0x00);
	hdmiI2cWriteByte(0x7a, 0x14, 0x00);
	hdmiI2cWriteByte(0x7a, 0x1d, 0x45);
	hdmiI2cWriteByte(0x7a, 0x1e, 0x00);
	hdmiI2cWriteByte(0x7a, 0x1f, 0x00);
	hdmiI2cWriteByte(0x7a, 0x20, 0x00);
	hdmiI2cWriteByte(0x7a, 0x21, 0x0f);
	hdmiI2cWriteByte(0x7a, 0x22, 0x01);
	hdmiI2cWriteByte(0x7a, 0x23, 0x00);
	hdmiI2cWriteByte(0x7a, 0x24, 0x0b);
}


/* 23423030 - complete */
void hdmiMute(int mode)
{
#if 0
	console_send_string("hdmiMute (todo.c): TODO\r\n");
#endif

	switch (mode)
	{
	case 1:
		//loc_23423068
		hdmiAvMute(1);
		break;

	case 2:
		//loc_2342305c
		/* mute only video */
		hdmiI2cWriteByte(0x72, HDMI_OFFSET0_DATA_CTRL, 0x04);
		break;

	case 3:
		//loc_2342305c
		/* mute only audio */
		hdmiI2cWriteByte(0x72, HDMI_OFFSET0_DATA_CTRL, 0x02);
		break;

	case 4:
		//loc_2342305c
		/* mute audio and video */
		hdmiI2cWriteByte(0x72, HDMI_OFFSET0_DATA_CTRL, 0x06);
		break;

	default:
		//loc_2342306c
		hdmiAvMute(0);
		break;
	}
}


/* 23423074 - complete */
void hdmiPowerOn(int a)
{
#if 0
	console_send_string("hdmiPowerOn (todo.c): TODO\r\n");
#endif

	if (a == 0)
	{
		hdmiI2cWriteByte(0x72, 0x08, 0x00);
	}
	else
	{
		hdmiI2cWriteByte(0x72, 0x08, 0x35);
		hdmiI2cWriteByte(0x72, 0x05, 0x01);
		hdmiI2cWriteByte(0x72, 0x71, 0x60);
		hdmiI2cAndWrite(0x72, 0x05, 0x02);
		hdmiI2cWriteByte(0x72, 0x3e, 0x00);
		hdmiI2cWriteByte(0x72, 0x3f, 0x00);

		hdmiMute(0);
	}
}


/* 234230fc - complete */
void hdmiSetDeGenerator(int a, int b)
{
#if 0
	console_send_string("hdmiSetDeGenerator (todo.c): TODO\r\n");
#endif

	uint8_t  polarity = 0x30;

	if (a == 0)
	{
		if ((b == 4) || (b == 5) ||
				(b == 16) || (b == 19) || (b == 20))
		{
			polarity = 0x00;
		}

		hdmiI2cAndWrite(0x72, 0x33, polarity);
	}
	else
	{
		//loc_23423134
		uint32_t write_value = hdmiStandardVideoTiming[b].hTotal -
				(hdmiStandardVideoTiming[b].hActive + hdmiStandardVideoTiming[b].hFp);

		hdmiI2cWriteByte(0x72, 0x33, 0x40 | ((write_value >> 8) & 0x0f));
		hdmiI2cWriteByte(0x72, 0x32, write_value & 0xff);

		write_value = hdmiStandardVideoTiming[b].vTotal -
				(hdmiStandardVideoTiming[b].vActive + hdmiStandardVideoTiming[b].vFp);

		hdmiI2cWriteByte(0x72, 0x34, write_value & 0xff);
		hdmiI2cWriteByte(0x72, 0x36, hdmiStandardVideoTiming[b].hActive & 0xff);
		hdmiI2cWriteByte(0x72, 0x37, (hdmiStandardVideoTiming[b].hActive >> 8) & 0xff);
		hdmiI2cWriteByte(0x72, 0x38, (hdmiStandardVideoTiming[b].vActive) & 0xff);
		hdmiI2cWriteByte(0x72, 0x39, (hdmiStandardVideoTiming[b].vActive >> 8) & 0xff);
	}
}


/* 234231f4 - complete */
void hdmiUpdateChecksum(uint8_t* a)
{
#if 0
	console_send_string("hdmiUpdateChecksum (todo.c): TODO\r\n");
#endif

	int i = 0;
	a[3] = 0;

	int end = a[2] + 4;

	for (i = 0; i < end; i++)
	{
		if (i != 3)
		{
			a[3] += a[i];
		}
	}

	a[3] = 0x100 - a[3];
}


/* 23423238 - todo */
void hdmiAviInfoFrame(hdmiHandleT* handlePtr)
{
#if 0
	console_send_string("hdmiAviInfoFrame (todo.c): TODO\r\n");
#endif

	uint8_t info_frame[17] =
	{
		0x82, 0x02, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

	int i = 0;

	int outColor = handlePtr->outColor;
	info_frame[4] = (outColor & 0x03) << 5;
	info_frame[4] |= (handlePtr->scanInfo & 0x03);

	int activeFormat = handlePtr->activeFormat;
	if (activeFormat != 0)
	{
		info_frame[4] |= (1 << 4);
	}

    uint32_t vic = handlePtr->vic;

	info_frame[5] = (activeFormat & 0x0f) | (uint8_t)(hdmiStandardVideoTiming[vic].ratio << 4);

	if (outColor != 0)
	{
		info_frame[5] |= (uint8_t)((hdmiStandardVideoTiming[vic].cscsel + 1) << 6);
	}

	info_frame[7] = vic;
	info_frame[8] = hdmiStandardVideoTiming[vic].repetition;

	hdmiUpdateChecksum(&info_frame[0]);

	hdmiClearInfoFrame(2, 0);
	hdmiI2cWriteByte(0x72, 0x08, 0x00);
	hdmiI2cWriteByte(0x7a, 0x3d, 0x0e);

	for (i = 0; i < 17; i++)
	{
		//loc_2342330c
		hdmiI2cWriteByte(0x7a, 0x40 + i, info_frame[i]);
	}
	//0x2342332c
	hdmiI2cWriteByte(0x7a, 0x3d, 0x0f);
	hdmiI2cWriteByte(0x72, 0x08, 0x35);
	hdmiSendInfoFrame(2, 0);
}


/* 23423360 - todo */
void hdmiAudioInfoFrame(hdmiHandleT* handlePtr)
{
#if 0
	console_send_string("hdmiAudioInfoFrame (todo.c): TODO\r\n");
#endif

	uint8_t  info_frame[14] = {0x84, 0x01, 10, 0, 0, 0, 0,0,0,0,0,0,0,0};
	int32_t  i           = 0;

	/* InfoFrame type */
	/* info_frame[0] = 0x84; */
	/* version */
	/* info_frame[1] = 0x01; */
	/* Length of AVIInfoFrame */
	/* info_frame[2] = 10; */
	/* audio channel count */
	info_frame[4] = handlePtr->channelCount & 0x07;
	/* audio coding type = 0 (refer to stream header) */
	info_frame[4] |= 0x00 << 4;
	/* sample frequency = 0 (refer to stream header) */
	/* sample size = 0 (refer to stream header) */
	info_frame[5] = 0x00;
	/* audio format code extension = 0x00 */
	info_frame[6] = 0x00;
	/* channel allocation */
	info_frame[7] = (uint8_t)handlePtr->channelAllocation;
	/* level shift value */
	/* LFEPBL0,1 = 0x00 */
	info_frame[8] = (uint8_t)(handlePtr->Data_0x14c/*levelShiftValue*/ << 3);
	/* down-mix inhibit flag */
	info_frame[8] |= (uint8_t)(handlePtr->Data_0x150/*downMixFlag*/ << 7);

	hdmiUpdateChecksum( info_frame );
	hdmiClearInfoFrame( 0x20/*AUD*/, 0 );

	for (i = 0; i < 14; i++)
	{
		hdmiI2cWriteByte(0x7a, (uint8_t)(0x80 + i), info_frame[i]);
	}

	//    hdmiSendInfoFrame( AUD, 0 );
	hdmiI2cWriteByte(0x7a, 0x3e, 0x33);
}


static int hdmiGetN(int pixelClock, int fs)
{
	int n_value;

	switch (fs)
	{
	case 1:
		//->loc_23423480
		n_value = hdmiGetN_Value(pixelClock, N_value32);
		break;

	case 2:
		//->loc_23423480
		n_value = hdmiGetN_Value(pixelClock, N_value44);
		break;

	case 3:
		//->loc_2342347c
		//loc_23423480
		n_value = hdmiGetN_Value(pixelClock, N_value48);
		break;

	case 4:
		//0x23423468
		n_value = hdmiGetN_Value(pixelClock, N_value48);
		n_value *= 2;
		//->loc_23423488
		break;

	default:
		//loc_2342347c
		n_value = hdmiGetN_Value(pixelClock, N_value48);
		break;
	}

	return n_value;
}

/* 234233f0 - todo */
void hdmiUpdateNandMCLK(int mclk, int fs, int pixelClock)
{
#if 0
	console_send_string("hdmiUpdateNandMCLK (todo.c): TODO\r\n");
#endif

	hdmiI2cAndWrite(0x7a, 0x01, 0x01);
	hdmiI2cWriteByte(0x7a, 0x14, 0x00);
	hdmiI2cAndWrite(0x7a, 0x1d, 0x45);

	hdmiI2cWriteByte(0x7a, 0x02, mclk & 0xff);

	int n_value = hdmiGetN(pixelClock, fs);
	//loc_23423488
	hdmiI2cWriteByte(0x7a, 0x03, n_value & 0xff);
	hdmiI2cWriteByte(0x7a, 0x04, n_value >> 8);
	hdmiI2cWriteByte(0x7a, 0x05, n_value >> 16);

	hdmiI2cOrWrite(0x7a, 0x01, 0x02);
}


/* 2342350c - complete */
void hdmiInitSha()
{
#if 0
	console_send_string("hdmiInitSha (todo.c): TODO\r\n");
#endif

	Data_235f0c70.Data_0 = 0x67452301;
	Data_235f0c70.Data_4 = 0xefcdab89;
	Data_235f0c70.Data_8 = 0x98badcfe;
	Data_235f0c70.Data_0xc = 0x10325476;
	Data_235f0c70.Data_0x10 = 0xc3d2e1f0;
	Data_235f0c70.Data_0x54 = 0;
	Data_235f0c70.Data_0x58 = 0;
}


/* 23423548 - complete */
int hdmiCheckCrc()
{
	int32_t timeout;
	uint8_t result;

#if 0
	console_send_string("hdmiCheckCrc (todo.c): TODO\r\n");
#endif

	hdmiI2cWriteByte(0x72, 0xfa, 0x04);

	for (timeout = 100; timeout > 0; timeout--)
	{
		result = hdmiI2cReadByte(0x72, 0xf9);
		if (result & 1)
		{
			break;
		}
	}

	if (timeout == 0)
	{
		return -1;
	}

	if (result & 2)
	{
		return -1;
	}

	return 0;
}


/* 23423784 - complete */
int hdmiCheckMddcError()
{
#if 0
	console_send_string("hdmiCheckMddcError (todo.c): TODO\r\n");
#endif

	if (hdmiI2cReadByte(0x72, 0xf2) & 0x60)
	{
		hdmiI2cAndWrite(0x72, 0xf2, 0x1f);
		hdmiI2cWriteByte(0x72, 0xf3, 0x0f);
		hdmiI2cWriteByte(0x72, 0xf3, 0x0a);

		return 1;
	}

	return 0;
}


/* 234237d4 - complete */
int hdmiReadMddcFifo(uint32_t count, uint8_t *rxBuffer)
{
#if 0
	console_send_string("hdmiReadMddcFifo (todo.c): TODO\r\n");
#endif

	int r7 = 0;
	//->loc_23423894
	while (count > 0)
	{
		//loc_234237e8
        uint32_t n = ( count > 16 ) ? 16 : count;
        //->loc_23423854
        while (hdmiI2cReadByte(0x72, 0xf5) < n)
        {
        	//loc_234237f8
        	if (r7 > 50)
        	{
        		//0x23423800
        		hdmiI2cAndWrite(0x72, 0xf2, 0x1f);
        		hdmiI2cWriteByte(0x72, 0xf3, 0x0f);
        		hdmiI2cWriteByte(0x72, 0xf3, 0x0a);
        		//->loc_23423840
        		return ~0xff000000;
        	}
        	else
        	{
        		//loc_23423834
        		if (0 != hdmiCheckMddcError())
        		{
        			//loc_23423840
        			return ~0xff000000;
        		}
        		//loc_23423848
        		r7++;

        		rtos_task_wait(1);
        		//->loc_23423854
        	}
        } //while (hdmiI2cReadByte(0x72, 0xf5) < n)
        //0x23423868 -> loc_23423884
        for (uint32_t i = 0; i < n; i++)
        {
        	//loc_23423870
        	rxBuffer[i] = hdmiI2cReadByte(0x72, 0xf4);
        }
        //0x2342388c
        rxBuffer += n;
        count -= n;
	}

	return 0;
}


/* 234238a4 - complete */
void hdmiSetDdcAddress(uint8_t slaveAddr, uint8_t offset, uint32_t count)
{
#if 0
	console_send_string("hdmiSetDdcAddress (todo.c): TODO\r\n");
#endif

	uint32_t i = 0;

	hdmiI2cWriteByte(0x72, 0xf3, 0x0a);
	hdmiI2cWriteByte(0x72, 0xf3, 0x09);

	for (i = 0; i < 10; i++)
	{
		//loc_234238d8
		uint8_t status = hdmiI2cReadByte(0x72, 0xf2);

		if (status & 4)
		{
			//->loc_234238f8
			break;
		}
	}
	//loc_234238f8
	hdmiI2cWriteByte(0x72, 0xed, slaveAddr);
	hdmiI2cWriteByte(0x72, 0xef, offset);
	hdmiI2cWriteByte(0x72, 0xf0, count);
	hdmiI2cWriteByte(0x72, 0xf1, count >> 8);
}


/* 23423940 - complete */
int hdmiReadEddcBlock(uint8_t slaveAddr, uint8_t seg, int offset, int count, uint8_t* rxBuffer)
{
#if 0
	console_send_string("hdmiReadEddcBlock (todo.c): TODO\r\n");
#endif

	hdmiSetDdcAddress(slaveAddr, offset, count);

	if (seg == 0)
	{
		hdmiI2cWriteByte(0x72, 0xf3, 0x02);
	}
	else
	{
		hdmiI2cWriteByte(0x72, 0xee, seg);
		hdmiI2cWriteByte(0x72, 0xf3, 0x04);
	}

	int r0 = hdmiReadMddcFifo(count, rxBuffer);
	if (r0 < 0)
	{
		return r0;
	}

	r0 = hdmiCheckMddcError();
	if (r0 != 0)
	{
		return ~0xff000000;
	}

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "hdmiReadEddcBlock: count=%d, rxBuffer=%p\r\n",
				count, rxBuffer);
		console_send_string(debug_string);

		for (uint32_t i = 0; i < count; i++)
		{
			sprintf(debug_string, "hdmiReadEddcBlock: rxBuffer[%d]=0x%02x\r\n",
					i, rxBuffer[i]);
			console_send_string(debug_string);
		}
	}
#endif

	return 0;
}


/* 23423ab0 - complete */
void hdmiEncryptionHDCP(hdmiHandleT* a, int b)
{
#if 0
	console_send_string("hdmiEncryptionHDCP (todo.c): TODO\r\n");
#endif

	if (b != 0)
	{
		if (a->hdcpState < 0x70)
		{
			hdmiMute(0);

			hdmiI2cOrWrite(0x72, 0x0f, 0x01);
		}
		return;
	}
	//loc_23423ae4
	hdmiI2cWriteByte(0x72, 0x27, 0x00);

	uint8_t int_mask2 = hdmiI2cReadByte(0x72, 0x76);

	hdmiI2cWriteByte(0x72, 0x76, int_mask2 & 0xdf);
	hdmiI2cWriteByte(0x72, 0x0f, 0x00);
	hdmiI2cWriteByte(0x72, 0x72, 0x20);
	hdmiI2cWriteByte(0x72, 0x76, int_mask2);

	hdmiMute(1);
}


/* 2342425c - todo */
void hdmiSetAudioI2S(hdmiHandleT* handlePtr)
{
#if 1
	console_send_string("hdmiSetAudioI2S\r\n");
#endif

	uint8_t sp[8] = {0};
	uint8_t i = 0;
	uint8_t fifo_map = 0;

	int fs = handlePtr->fs;
	uint8_t swap_i2s = 9;

	hdmiUpdateNandMCLK(handlePtr->audioClock, fs, hdmiStandardVideoTiming[ handlePtr->vic ].Data_0);

	sp[0] = 0; //sb
	sp[1] = 0;
	sp[2] = 0;
	sp[3] = channelStatusTable[fs];
	sp[4] = ((channelStatusTable[fs] << 3) & 0xf0) | 0x02;

	hdmiI2cWriteByte(0x7a, 0x1e, sp[0]/*0*/);
	hdmiI2cWriteByte(0x7a, 0x1f, sp[1]);
	hdmiI2cWriteByte(0x7a, 0x20, sp[2]);
	hdmiI2cWriteByte(0x7a, 0x21, sp[3]);
	hdmiI2cWriteByte(0x7a, 0x22, sp[4]);
	hdmiI2cWriteByte(0x7a, 0x24, 0x02);

	//r2, #0x1

	if (handlePtr->chNum > 1)
	{
		handlePtr->audioSource = 0; //sb
	}

	for (i = 0; i < 4; i++)
	{
		//loc_2342433c
		if (handlePtr->speakerMapping[i].left == 1) //FAPI_HDMI_SPEAKER_FL
		{
			fifo_map |= i;
			//->loc_2342446c
		}
		else if (handlePtr->speakerMapping[i].right == 1) //FAPI_HDMI_SPEAKER_FL
		{
			fifo_map |= i;
			//->loc_2342445c
			swap_i2s |= ((1 << (i + 4)) & 0xff);
			//loc_2342446c
		}
		else if ((handlePtr->speakerMapping[i].left == 3) || //FAPI_HDMI_SPEAKER_LFE
				(handlePtr->speakerMapping[i].right == 4)) //FAPI_HDMI_SPEAKER_FC
		{
			//r0, i, lsl #2
			//->loc_234243b0
			fifo_map |= ((i << 2) & 0xff);
			//->loc_2342445c
			swap_i2s |= ((1 << (i + 4)) & 0xff);
			//loc_2342446c
		}
		else if ((handlePtr->speakerMapping[i].left == 4) || //FAPI_HDMI_SPEAKER_FC
				(handlePtr->speakerMapping[i].right == 3)) //FAPI_HDMI_SPEAKER_LFE
		{
			//r0, i, lsl #2
			//->loc_234243e4
			fifo_map |= ((i << 2) & 0xff);
			//->loc_2342446c
		}
		else if ((handlePtr->speakerMapping[i].left == 5) && //FAPI_HDMI_SPEAKER_RL
				(handlePtr->speakerMapping[i].right == 6)) //FAPI_HDMI_SPEAKER_RR
		{
			//r0, i, lsl #4
			//->loc_234243e4
			fifo_map |= ((i << 4) & 0xff);
			//->loc_2342446c
		}
		//loc_2342439c / loc_23424434
		else if ((handlePtr->speakerMapping[i].left == 6) && //FAPI_HDMI_SPEAKER_RR
				(handlePtr->speakerMapping[i].right == 5)) //FAPI_HDMI_SPEAKER_RL
		{
			//loc_23424454
			//r0, i, lsl #4
			//->loc_234243b0
			fifo_map |= ((i << 4) & 0xff);
			//->loc_2342445c
			swap_i2s |= ((1 << (i + 4)) & 0xff);
			//loc_2342446c
		}
		else if (((handlePtr->speakerMapping[i].left  == 8/*FAPI_HDMI_SPEAKER_FLC*/) &&
				(handlePtr->speakerMapping[i].right == 9/*FAPI_HDMI_SPEAKER_FRC*/)) ||
				((handlePtr->speakerMapping[i].left  == 10/*FAPI_HDMI_SPEAKER_RLC*/) &&
				(handlePtr->speakerMapping[i].right == 11/*FAPI_HDMI_SPEAKER_RRC*/)))
		{
			fifo_map |= (uint8_t)(i << 6);
		}
		else if (((handlePtr->speakerMapping[i].left  == 9/*FAPI_HDMI_SPEAKER_FRC*/) &&
			(handlePtr->speakerMapping[i].right == 8/*FAPI_HDMI_SPEAKER_FLC*/)) ||
			((handlePtr->speakerMapping[i].left  == 11/*FAPI_HDMI_SPEAKER_RRC*/) &&
			(handlePtr->speakerMapping[i].right == 10/*FAPI_HDMI_SPEAKER_RLC*/)))
		{
			fifo_map |= (uint8_t)(i << 6);
			swap_i2s |= (uint8_t)(1U<<(4 + i));
		}
		else if (handlePtr->speakerMapping[i].left  == 7/*FAPI_HDMI_SPEAKER_RC*/)
		{
			if ((handlePtr->channelAllocation >= 0x0c) &&
					(handlePtr->channelAllocation <= 0x0f))
			{
				fifo_map |= (uint8_t)(i << 6);
			}
			else
			{
				fifo_map |= (uint8_t)(i << 4);
			}
		}
		else if (handlePtr->speakerMapping[i].right  == 7/*FAPI_HDMI_SPEAKER_RC*/)
		{
			if((handlePtr->channelAllocation >= 0x0c) &&
					(handlePtr->channelAllocation <= 0x0f))
			{
				fifo_map |= (uint8_t)(i << 6);
			}
			else
			{
				fifo_map |= (uint8_t)(i << 4);
			}

			swap_i2s |= (uint8_t)(1U<<(4 + i));
		}
		//loc_2342446c
	} //for (i = 0; i < 4; i++)
	//0x2342447c
	hdmiI2cWriteByte(0x7a, 0x19, swap_i2s);
	hdmiI2cWriteByte(0x7a, 0x1c, fifo_map);
	hdmiI2cWriteByte(0x7a, 0x1d, audioFormatTable[handlePtr->audioFormat]);
	hdmiI2cWriteByte(0x7a, 0x23, handlePtr->audioSource & 0xff);
	hdmiI2cWriteByte(0x7a, 0x2f, (handlePtr->chNum == 1)? 0x21: 0x23);
	hdmiI2cWriteByte(0x7a, 0x14, (handlePtr->audioMode & 0xff) | 0x01);

	hdmiAudioInfoFrame(handlePtr);
}


/* 23424508 - todo */
int hdmiProcess861Block(hdmiHandleT* handlePtr, uint8_t* eedid)
{
#if 0
	console_send_string("hdmiProcess861Block (todo.c): TODO\r\n");
#endif

	int r2_;
	int r7;
	int tag; //ip
	uint32_t num;
	int r5;
	int lr = 0;
	int hdmi_mode = 0; //r6

	if (eedid[0] != 2)
	{
		//loc_23424694
		return 0;
	}

	if (eedid[1] < 3)
	{
		//loc_23424694
		return 0;
	}

	r5 = eedid[2] - 4;
	if (r5 < 0)
	{
		r5 = 0;
		//->loc_23424544
	}

	if (r5 > 123)
	{
		r5 = 123;
	}
	//loc_23424544
	handlePtr->Data_0x164/*supportData*/ = eedid[3];
	//->loc_23424684
	for (lr = 0; lr < r5; lr += (num+1))
	{
		//loc_23424550
		uint8_t* r2 = &(eedid[lr + 4]);
		num = r2[0] & 0x1f;
		tag = (r2[0] >> 5) & 0x07;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "hdmiProcess861Block: tag=%d, num=%d\r\n", tag, num);
		console_send_string(debug_string);
	}
#endif

#if 0
	hdmiProcess861Block: tag=2, num=19
	hdmiProcess861Block: tag=1, num=6
	hdmiProcess861Block: tag=4, num=3
	hdmiProcess861Block: tag=3, num=20
	hdmiProcess861Block: tag=7, num=2
#endif

		switch (tag)
		{
		case 0:
		case 5:
		case 6:
			//23424694
			return 0;
			//break;

		case 1:
			//2342458C: SAD_TAG
			{
				uint32_t audio_data = 0;

				audio_data = r2[1];
				audio_data |= r2[2] << 8;
				audio_data |= r2[3] << 16;

				handlePtr->Data_0x168 = audio_data;
				//->2342467C
				break;
			}

		case 2:
			//234245A8: SVD_TAG
			r7 = r2[0] & 0x1f;
			//->234245D0
			for (int ip = 1; ip <= r7; ip++)
			{
				//234245B4
				int r3 = *r2++;
				r3 = r3 & 0x7f;
				if (r3 < 23)
				{
					handlePtr->wData_0x1a0[r3] = r3;
				}
			}
			//0x234245d8 -> 2342467C
			break;

		case 3:
			//234245DC: VSDB_TAG
			if ((r2[1] == 3) && (r2[2] == 12) && (r2[3] == 0))
			{
				handlePtr->wData_0x1ce/*physAddr[0]*/ = r2[4];
				handlePtr->wData_0x1d0/*physAddr[1]*/ = r2[5];

				if (num >= 8)
				{
					//0x23424614
					if (r2[8] & 0x80)
					{
						handlePtr->videoLatency = r2[9];
						handlePtr->audioLatency = r2[10];
					}

					if (r2[8] & 0x40)
					{
						handlePtr->interlacedVideoLatency = r2[11];
						handlePtr->interlacedAudioLatency = r2[12];
					}
				}
				//23424644
				if (num >= 6)
				{
					handlePtr->vsdbData6 = r2[6];

					if (r2[6] & 1)
					{
						//0x23424660
						r2_ = 0;
						//->2342466C
					}
					else
					{
						r2_ = 1;
					}
				}
				else
				{
					//23424668
					r2_ = 1;
				}
			}
			else
			{
				//23424660
				r2_ = 0;
			}
			//0x2342466c
			hdmi_mode |= r2_;
			//->2342467C
			break;

		case 4:
			//23424674: SADB_TAG
			handlePtr->Data_0x16c = r2[1];
			//0x2342467c
			break;

		case 7:
			//2342467C: Extended_TAG
			break;

		default:
			//loc_23424694
			return 0;
			//break;
		}
		//2342467C
	} //for (lr = 0; lr < r5; lr += (num+1))
	//0x2342468c
	return hdmi_mode;
}


/* 2342469c - todo */
int hdmiReadEDID(hdmiHandleT* r4)
{
#if 0
	console_send_string("hdmiReadEDID (todo.c): TODO\r\n");
#endif

	uint32_t i = 0;

	int hpd_status = hdmiI2cReadByte(0x72, 0x09) & 0x02;

	if (hpd_status != 0x02)
	{
		return ~0xff000000;
	}

	for (i = 0; i < 23; i++)
	{
		//loc_234246c8
		r4->wData_0x1a0[i] = 0;
	}
	//0x234246e0
	r4->hdmiMode = 0;
	r4->wData_0x1ce = 0xff;
	r4->wData_0x1d0 = 0xff;

	int r0 = hdmiReadEddcBlock(0xa0, 0, 0, 0x80, &r4->edidBuffer[0]);
	if (r0 < 0)
	{
		return r0;
	}

	uint8_t extension_blocks = r4->edidBuffer[0x7e/*ADDR_EDID_BLOCK_INDEX*/];
	for (uint32_t r5 = 1; r5 <= extension_blocks; r5++)
	{
		//loc_23424724
		r0 = hdmiReadEddcBlock(0xa0, (r5 & 0x1fe) >> 1, (r5 & 0x01) << 7, 0x80, &r4->edidBuffer[0x80]);
		if (r0 < 0)
		{
			return r0;
		}

		r0 = hdmiProcess861Block(r4, &r4->edidBuffer[0x80]);
		r4->hdmiMode |= r0;
	}
	//0x23424774
	for (i = 0; i < 23; i++)
	{
		//loc_234246c8
		if (r4->wData_0x1a0[i] != 0)
		{

		}
	}

	return 0;
}


/* 23424798 - todo */
int hdmi_init(void)
{
	uint16_t i;
	Struct_2341cd7c sp;

	sp.bData_0 = 2;
	sp.bData_1 = 1;
	sp.clkPin = 0;
	sp.dataPin = 0;

	if (0 != i2c_open(&sp, &Data_234923ec))
	{
		return 0xff;
	}

	for (i = 0; i < 2; i++)
	{
		//loc_234247dc
		memset(&hdmiHandleArray[i], 0, sizeof(hdmiHandleT));
	}

	if (hdmi_sema == 0)
	{
		hdmi_sema = OSSemCreate(1);
	}

	*((volatile uint32_t*)0xcb010084) = //FREG_VO_DISPDACHDMICTRL
			( *((volatile uint32_t*)0xcb010084) & ~0x700) | 0x300;

	*((volatile uint32_t*)0xcb010084) = //FREG_VO_DISPDACHDMICTRL
			( *((volatile uint32_t*)0xcb010084) & ~0x7000) | 0x5000;

	*((volatile uint32_t*)0xcb010084) |= //FREG_VO_DISPDACHDMICTRL
			0x80;
	*((volatile uint32_t*)0xcb010084) |= //FREG_VO_DISPDACHDMICTRL
			0x40;
	*((volatile uint32_t*)0xcb010084) &= //FREG_VO_DISPDACHDMICTRL
			~0x20;
	*((volatile uint32_t*)0xcb010084) &= //FREG_VO_DISPDACHDMICTRL
			~0x10;
	*((volatile uint32_t*)0xcb010084) &= //FREG_VO_DISPDACHDMICTRL
			~0x02;

	for (i = 0; i < 8; i++)
	{
		//loc_23424880
		arData_234923f4[i] = 0;
	}

	hdmiInitSha();

	return 0;
}


/* 234248a0 - todo */
int hdmi_open(Struct_234248a0* r5, void** r7)
{
#if 0
	console_send_string("hdmi_open (todo.c): TODO\r\n");
#endif

	uint8_t err;
	hdmiHandleT* r4 = 0;

	OSSemPend(hdmi_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	for (uint8_t i = 0; i < 2; i++)
	{
		//loc_234248d8
		if (hdmiHandleArray[i].bData_0 == 0)
		{
			r4 = &hdmiHandleArray[i];
			r4->bData_0 = 1;
			//->loc_23424908
			break;
		}
	} //for (uint8_t i = 0; i < 2; i++)
	//loc_23424908
	if (r4 != 0)
	{
		if (r5->Data_0 & 1)
		{
			r4->bData_1 = 0; //r8

			hdmiInitializeVideoRegister();
		}

		if (r5->Data_0 & 2)
		{
			hdmiInitializeAudioRegister();
		}

		if (r5->Data_0 & 3)
		{
			r4->Data_0x134 = hdmiCheckCrc();
			r4->Data_0x13c/*efuseStatus*/ = FREG(0xd5000000)[0] & 0x06;
			r4->hdcpState = 0x10;
		}
		//loc_2342495c
		r4->Data_4 = r5->Data_0;

		*r7 = r4;

		r4->hdmiMode = 0; //r8
		r4->wData_0x1ce = 0xff;
		r4->wData_0x1d0 = 0xff;

		OSSemPost(hdmi_sema);

		return 0;
	}
	else
	{
		//loc_2342498c
		OSSemPost(hdmi_sema);

		return 0xffff;
	}
}


/* 2342499c - todo */
int hdmi_SetAudioParameters(void* h, Struct_2342499c* r6)
{
	hdmiHandleT* r4 = h;

#if 0
	console_send_string("hdmi_SetAudioParameters (todo.c): TODO\r\n");
#endif

	int sl = 0;
	uint32_t i = 0;
	int sum = 0;

	uint8_t err; //sp_0x24
	uint32_t speaker_data[8] = {0};

	//sb, =0xffff

	if ((r6->mode & 0x0d) != 0)
	{
		//loc_23424a10
		return 0xffff;
	}

	if ((r6->audioClock != 1) && (r6->audioClock != 2))
	{
		//loc_23424a10
		return 0xffff;
	}

	if ((r6->polarity != 0) && (r6->polarity != 1))
	{
		//loc_23424a10
		return 0xffff;
	}

	if ((r6->mode != 0) && (r6->mode != 2) &&
			(r6->format != 1) && (r6->format != 2) && (r6->format != 3))
	{
		//loc_23424a10
		return 0xffff;
	}
	//loc_23424a1c
	OSSemPend(hdmi_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	int mode = r6->mode;

	if (mode == 2)
	{
		r4->chNum = 1;
		//->loc_23424a74
	}
	else
	{
		if (mode & 0x10)
		{
			sl++;
		}

		if (mode & 0x20)
		{
			sl++;
		}

		if (mode & 0x40)
		{
			sl++;
		}

		if (mode & 0x80)
		{
			sl++;
		}

		r4->chNum = sl;
	}
	//loc_23424a74
	int ch = 0;

	r4->audioMode = mode;
	r4->audioClock = r6->audioClock;
	r4->audioPolarity = r6->polarity;
	r4->audioFormat = r6->format;
	r4->audioSource = r6->Data_0x10;
	r4->Data_0x140 = r6->Data_0x14;
	r4->Data_0x14c = r6->Data_0x18;
	r4->Data_0x150 = r6->Data_0x1c;

	//ip, sp, #0x4

	for (i = 0; i < 4; i++)
	{
		//loc_23424ab8
		if (r6->speakerMapping[i].left != 0)
		{
			speaker_data[ch] = r6->speakerMapping[i].left;
			sum += r6->speakerMapping[i].left;
			ch++;
		}

		if (r6->speakerMapping[i].right != 0)
		{
			speaker_data[ch] = r6->speakerMapping[i].right;
			sum += r6->speakerMapping[i].right;
			ch++;
		}

		r4->speakerMapping[i] = r6->speakerMapping[i];
	}
	//0x23424b04
	if (mode == 2)
	{
		r4->channelCount = 0; //r2
		//->loc_23424d5c
		OSSemPost(hdmi_sema);

		return 0;
	}
	else
	{
		//0x23424b14
		r4->channelCount = ch - 1;
	}

	switch (ch)
	{
	case 2:
		//23424B48
		r4->channelAllocation = 0; //r2;
		//->23424D5C
		break;

	case 3:
		//23424B50
		if (sum == 6)
		{
			r4->channelAllocation = 1; //r3;
		}
		else if (sum == 7)
		{
			r4->channelAllocation = 2;
		}
		else if (sum == 10)
		{
			r4->channelAllocation = 4;
		}
		else
		{
			//23424D6C
			OSSemPost(hdmi_sema);
			//->loc_23424a10
			return 0xffff;
		}
		break;

	case 4:
		//23424B78
		if (sum == 14)
		{
			for (uint32_t i = 0; i < 4; i++)
			{
				//23424B84
				if (speaker_data[i] == 4)
				{
					r4->channelAllocation = 6;
					//->23424D58
					break;
				}
				else if (speaker_data[i] == 5)
				{
					r4->channelAllocation = 8;
					//->23424D58
					break;
				}
			}
			//23424D5C
		}
		//23424BB0
		else if (sum == 10)
		{
			r4->channelAllocation = 3;
		}
		else if (sum == 13)
		{
			r4->channelAllocation = 5;
		}
		else if (sum == 20)
		{
			r4->channelAllocation = 0x14;
		}
		else
		{
			//23424D6C
			OSSemPost(hdmi_sema);
			//->loc_23424a10
			return 0xffff;
		}
		break;

	case 5:
		//23424BD8
		if (sum == 17)
		{
			for (uint32_t i = 0; i < 5; i++)
			{
				if (speaker_data[i] == 4)
				{
					r4->channelAllocation = 7;
					break;
				}
				else if (speaker_data[i] == 5)
				{
					r4->channelAllocation = 9;
					break;
				}
			}
		}
		else if (sum == 18)
		{
			r4->channelAllocation = 0x0a;
		}
		else if (sum == 21)
		{
			r4->channelAllocation = 0x0c;
		}
		else if (sum == 23)
		{
			r4->channelAllocation = 0x15;
		}
		else if (sum == 24)
		{
			r4->channelAllocation = 0x16;
		}
		else if (sum == 27)
		{
			r4->channelAllocation = 0x18;
		}
		else
		{
			//23424D6C
			OSSemPost(hdmi_sema);
			//->loc_23424a10
			return 0xffff;
		}
		break;

	case 6:
		//23424C50
		if (sum == 31)
		{
			for (uint32_t i = 0; i < 6; i++)
			{
				if (speaker_data[i] == 4)
				{
					r4->channelAllocation = 0x1a;
					break;
				}
				else if (speaker_data[i] == 5)
				{
					r4->channelAllocation = 0x1c;
					break;
				}
			}
		}
		else if (sum == 21)
		{
			r4->channelAllocation = 0x0b;
		}
		else if (sum == 24)
		{
			r4->channelAllocation = 0x0d;
		}
		else if (sum == 25)
		{
			r4->channelAllocation = 0x0e;
		}
		else if (sum == 35)
		{
			r4->channelAllocation = 0x10;
		}
		else if (sum == 27)
		{
			r4->channelAllocation = 0x17;
		}
		else if (sum == 30)
		{
			r4->channelAllocation = 0x19;
		}
		else
		{
			//23424D6C
			OSSemPost(hdmi_sema);
			//->loc_23424a10
			return 0xffff;
		}
		break;

	case 7:
		//23424CD4
		if (sum == 34)
		{
			for (uint32_t i = 0; i < 7; i++)
			{
				if (speaker_data[i] == 4)
				{
					r4->channelAllocation = 0x1b;
					break;
				}
				else if (speaker_data[i] == 5)
				{
					r4->channelAllocation = 0x1d;
					break;
				}
			}
		}
		else if (sum == 28)
		{
			r4->channelAllocation = 0x0f;
		}
		else if (sum == 38)
		{
			r4->channelAllocation = 0x11;
		}
		else if (sum == 39)
		{
			r4->channelAllocation = 0x12;
		}
		else if (sum == 35)
		{
			r4->channelAllocation = 0x1e;
		}
		else
		{
			//23424D6C
			OSSemPost(hdmi_sema);
			//->loc_23424a10
			return 0xffff;
		}
		break;

	case 8:
		//23424D40
		if (sum == 42)
		{
			r4->channelAllocation = 0x13;
		}
		else if (sum == 38)
		{
			r4->channelAllocation = 0x1f;
		}
		else
		{
			//23424D6C
			OSSemPost(hdmi_sema);
			//->loc_23424a10
			return 0xffff;
		}
		break;

	default:
		//loc_23424d6c
		OSSemPost(hdmi_sema);
		//->loc_23424a10
		return 0xffff;
		//break;
	}
	//loc_23424d5c
	OSSemPost(hdmi_sema);

	return 0;
}


/* 23424d78 - complete */
int hdmi_SetVideoParameters(void* h, HDMI_VideoParams* pVParams)
{
	uint8_t err;
	hdmiHandleT* hdmi_handle_ptr = h;

#if 0
	console_send_string("hdmi_SetVideoParameters (todo.c): TODO\r\n");
#endif

	OSSemPend(hdmi_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	if (((pVParams->videoCode != 0) && (pVParams->videoCode >= 23)) ||
			(hdmiStandardVideoTiming[pVParams->videoCode].Data_0 == 0))
	{
		//loc_23424dc8
		OSSemPost(hdmi_sema);

		return 0xffff;
	}
	//loc_23424dd8
	hdmi_handle_ptr->inColor = pVParams->inputType;
	hdmi_handle_ptr->outColor = pVParams->outputType;
	hdmi_handle_ptr->vic = pVParams->videoCode;
	hdmi_handle_ptr->useDeGen = 0;
	hdmi_handle_ptr->scanInfo = pVParams->scanInfo;
	hdmi_handle_ptr->activeFormat = pVParams->activeFormat;

	OSSemPost(hdmi_sema);

	return 0;
}


/* 23424e18 - complete */
int hdmi_check_hpd(hdmiHandleT* r5)
{
#if 0
	console_send_string("hdmi_check_hpd (todo.c): TODO\r\n");
#endif

	int hpd_int = hdmiI2cReadByte(0x72, 0x71) & 0x60;
	int hpd_status = hdmiI2cReadByte(0x72, 0x09) & 0x06;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "hdmi_check_hpd: hpd_int=0x%x, hpd_status=0x%x\r\n",
				hpd_int, hpd_status);
		console_send_string(debug_string);
	}
#endif

	if (hpd_int & 0x40)
	{
		hdmiI2cWriteByte(0x72, 0x71, 0x40);
	}

	if (hpd_int & 0x20)
	{
		hdmiI2cWriteByte(0x72, 0x71, 0x20);
	}

	if (hpd_int != 0)
	{
		if ((hpd_int & 0x44) == 0x40)
		{
			if (r5->hdcpState != 0x90/*NO_ENCRYPTION*/)
			{
				r5->hdcpState = 0x10/*FIRST_AUTHENTICATION*/;

				if (r5->Data_4 & 3)
				{
					hdmiEncryptionHDCP(r5, 0);
				}
			}
		}
	}
	//loc_23424ea0
	return hpd_int | hpd_status;
}


/* 23424ea8 - complete */
int hdmi_video_start(void* a)
{
	uint8_t err;
	hdmiHandleT* h = a;

#if 0
	console_send_string("hdmi_video_start (todo.c): TODO\r\n");
#endif

	OSSemPend(hdmi_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	int r0 = hdmi_check_hpd(h) & 0x0f;
	if (r0 == 6)
	{
		hdmiSetDeGenerator(h->useDeGen, h->vic & 0xff);

		if (h->hdmiMode == 1)
		{
			hdmiAviInfoFrame(h);
		}
	}

	OSSemPost(hdmi_sema);

	return 0;
}


/* 23422f8c - complete */
void hdmiSendInfoFrame(uint8_t infoframeType, uint8_t select)
{
#if 0
	console_send_string("hdmiSendInfoFrame (todo.c): TODO\r\n");
#endif

	uint8_t offset_address = 0;
	uint8_t en_bit = 0;

	offset_address = HDMI_OFFSET1_PB_CTRL1+ select;
	en_bit= infoframeType;
	/* enable and repeat bit */
	en_bit |= en_bit >> 1;
#if 0
	hdmiI2cOrWrite(HDMI_DEVICE2_ADDR, offset_address, en_bit);
#endif

	hdmiI2cOrWrite(0x7a, offset_address, en_bit);

	for (uint32_t i = 0; i < 10; i++)
	{
		int r0 = hdmiI2cReadByte(0x7a, offset_address);
		if ((en_bit & ~r0) == 0)
		{
			break;
		}

		hdmiI2cOrWrite(0x7a, offset_address, en_bit);
	}
}


/* 23422fe4 - complete */
void hdmiClearInfoFrame(uint8_t infoframeType, int select)
{
#if 0
	console_send_string("hdmiClearInfoFrame (todo.c): TODO\r\n");
#endif

	int i = 0;

	uint8_t offset_address = HDMI_OFFSET1_PB_CTRL1 + select;
	uint8_t en_bit = infoframeType;

	hdmiI2cAndWrite(0x7a, offset_address, ~(en_bit >> 1));

	for (i = 0; i < 10; i++)
	{
		int r0 = hdmiI2cReadByte(0x7a, offset_address);
		if ((r0 & en_bit) == 0)
		{
			break;
		}
	}
}


/* 23424f14 - todo */
int sub_23424f14(void* a)
{
	uint8_t err; //sp4
	uint8_t sp[4];
	hdmiHandleT* r4 = a;

#if 0
	console_send_string("sub_23424f14 (todo.c): TODO\r\n");
#endif

//	int r5 = 0;

	if (r4->hdmiMode == 0)
	{
		r4->outColor = 0; //r5
	}

	OSSemPend(hdmi_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	hdmiSetDeGenerator(r4->useDeGen, r4->vic & 0xff);

	hdmiSetVideoMode(r4);

	uint8_t r0 = hdmiI2cReadByte(0x7a, 0x2f);

	if (r4->hdmiMode == 0)
	{
		hdmiI2cWriteByte(0x7a, 0x2f, 0x00);
	}
	else
	{
		hdmiI2cWriteByte(0x7a, 0x2f, (r0 & 0x03) | 0x01);
	}

	if (r4->outColor == 0)
	{
		sp[0] = 0;
		sp[1] = 0;
		sp[2] = 0;
		//->loc_23424fc8
	}
	else if (r4->outColor == 2)
	{
		sp[0] = 0x80;
		sp[1] = 0x10;
		sp[2] = 0x80;
	}
	else
	{
		sp[0] = 0x00;
		sp[1] = 0x10;
		sp[2] = 0x80;
	}
	//loc_23424fc8
	hdmiI2cWriteByte(0x72, 0x4b, sp[0]);
	hdmiI2cWriteByte(0x72, 0x4c, sp[1]);
	hdmiI2cWriteByte(0x72, 0x4d, sp[2]);

	hdmiI2cWriteByte(0x72, 0x82, 0x20);

	if (r4->hdmiMode == 1)
	{
		hdmiAviInfoFrame(r4);
	}

	OSSemPost(hdmi_sema);

	return 0;
}


/* 23425028 - complete */
int hdmi_video_stop(void* a)
{
	uint8_t err;
	hdmiHandleT* h = a;

#if 0
	console_send_string("hdmi_video_stop (todo.c): TODO\r\n");
#endif

	OSSemPend(hdmi_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	hdmiMute(2);

	OSSemPost(hdmi_sema);

	return 0;
}


/* 23425064 - complete */
int hdmi_read_edid(void* a)
{
	uint8_t err;
	hdmiHandleT* h = a;

#if 0
	console_send_string("hdmi_read_edid (todo.c): TODO\r\n");
#endif

	OSSemPend(hdmi_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	int r5 = hdmiReadEDID(h);

	h->wData_2 = r5;

	OSSemPost(hdmi_sema);

	return r5;
}


/* 2342510c - complete */
int hdmi_audio_start(void* h)
{
	uint8_t err;
	hdmiHandleT* r4 = h;

#if 0
	console_send_string("hdmi_audio_start (todo.c): TODO\r\n");
#endif

	OSSemPend(hdmi_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	if (r4->audioMode == 2/*FAPI_HDMI_SPDIF*/)
	{
		r4->fs = hdmiI2cReadByte(0x7a, HDMI_OFFSET1_HW_SPDIF_FS) & 0x0f;

		hdmiSetAudioSPDIF(r4);
		//->loc_23425168
	}
	else
	{
		//loc_23425160
		hdmiSetAudioI2S(r4);
	}
	//loc_23425168
	hdmiMute(0);

	OSSemPost(hdmi_sema);

	return 0;
}


/* 23425180 - complete */
int hdmi_SetAudioSampleFrequency(void* h, int sampleFreq)
{
	uint8_t err;
	hdmiHandleT* r4 = h;

#if 0
	console_send_string("hdmi_SetAudioSampleFrequency (todo.c): TODO\r\n");
#endif

	OSSemPend(hdmi_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	r4->fs = sampleFreq;

	OSSemPost(hdmi_sema);

	return 0;
}


/* 234251c0 - complete */
int hdmi_audio_stop()
{
	uint8_t err;

#if 0
	console_send_string("hdmi_audio_stop (todo.c): TODO\r\n");
#endif

	OSSemPend(hdmi_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	OSSemPost(hdmi_sema);

	return 0;
}


/* 23425270 / 23430684 - todo */
void sub_23425270(int a)
{
	console_send_string("sub_23425270 (todo.c): TODO\r\n");

}


/* 23425318 / 2343072c - todo */
void sub_23425318(int a)
{
	console_send_string("sub_23425318 (todo.c): TODO\r\n");

}


/* 234253d0 - complete */
int sub_234253d0(void* a)
{
	uint8_t err;
	hdmiHandleT* h = a;

#if 0
	console_send_string("sub_234253d0 (todo.c): TODO\r\n");
#endif

	OSSemPend(hdmi_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	if ((hdmi_check_hpd(h) & 0x0f) != 6)
	{
		OSSemPost(hdmi_sema);

		return 0;
	}
	else
	{
		OSSemPost(hdmi_sema);

		return 0xff;
	}
}


/* 23425428 - complete */
int hdmi_power_down(void* a, int r5)
{
	uint8_t err;
//	hdmiHandleT* h = a;

#if 0
	console_send_string("hdmi_power_down (todo.c): TODO\r\n");
#endif

	OSSemPend(hdmi_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	if (r5 == 0)
	{
		hdmiPowerOn(1);
		hdmiMute(0);
	}
	else
	{
		//loc_2342546c
		hdmiMute(1);
		hdmiPowerOn(0);
	}
	//loc_23425478
	OSSemPost(hdmi_sema);

	return 0;
}


/* 234254d0 - complete */
int hdmiI2cWriteByte(int a, uint8_t b, uint8_t c)
{
	uint8_t sp[2];

	sp[0] = b;
	sp[1] = c;

	return i2c_master_send(Data_234923ec, a, sp, 2);
}


/* 234254f8 - complete */
uint8_t hdmiI2cReadByte(int a, int b)
{
#if 0
	console_send_string("hdmiI2cReadByte (todo.c): TODO\r\n");
#endif

	uint8_t sp4;

	i2c_master_read_reg(Data_234923ec, a, b, &sp4, 1);

	return sp4;
}


/* 23425524 - complete */
void hdmiI2cAndWrite(uint8_t r5, uint8_t r6, uint8_t r4)
{
#if 0
	console_send_string("hdmiI2cAndWrite (todo.c): TODO\r\n");
#endif

	uint8_t r0 = hdmiI2cReadByte(r5, r6);

	r0 &= r4;

	hdmiI2cWriteByte(r5, r6, r0);
}


/* 2342554c - complete */
void hdmiI2cOrWrite(uint8_t r5, uint8_t r6, uint8_t r4)
{
#if 0
	console_send_string("hdmiI2cAndWrite (todo.c): TODO\r\n");
#endif

	uint8_t r0 = hdmiI2cReadByte(r5, r6);

	r0 |= r4;

	hdmiI2cWriteByte(r5, r6, r0);
}


/* 23425574 - complete */
void hdmiAvMute(int a)
{
#if 0
	console_send_string("hdmiAvMute (todo.c): TODO\r\n");
#endif

	uint8_t r4;

	if (a == 0)
	{
		r4 = 0x10;
	}
	else
	{
		r4 = 0x01;
	}

	hdmiClearInfoFrame(0x08, 0x01);
	hdmiI2cWriteByte(0x7a, HDMI_OFFSET1_CP_BYTE1, r4);
	hdmiSendInfoFrame(0x08, 0x01);
}


/* 234255b0 - todo */
void hdmiSetVideoMode(hdmiHandleT* r0)
{
#if 0
	console_send_string("hdmiSetVideoMode (todo.c): TODO\r\n");
#endif

	uint8_t video_setup[4] = {0};

	video_setup[0] |= hdmiStandardVideoTiming[r0->vic].repetition & 0x03;
	video_setup[0] |= hdmiStandardVideoTiming[r0->vic].cscsel << 4;

	if (r0->inColor != r0->outColor)
	{
		switch (r0->inColor)
		{
		case 0: //FAPI_HDMI_RGB
			//loc_2342564c
			break;

		case 2: //FAPI_HDMI_YUV444
			//0x2342560c
			if (r0->outColor == 0) //FAPI_HDMI_RGB
			{
				video_setup[2] |= 0x18;
			}
			else
			{
				video_setup[1] |= 0x01;
			}
			break;

		default:
			//loc_2342562c
			video_setup[2] |= 0x20;

			if (r0->outColor == 0) //FAPI_HDMI_RGB
			{
				video_setup[2] |= 0x1c;
			}
			else
			{
				video_setup[2] |= 0x04;
			}
			break;
		}
	}
	//loc_2342564c
	hdmiI2cWriteByte(0x72, 0x48, video_setup[0]);
	hdmiI2cWriteByte(0x72, 0x49, video_setup[1]);
	hdmiI2cWriteByte(0x72, 0x4a, video_setup[2]);
}


/* 23425680 - complete */
int hdmiGetN_Value(uint32_t r0, const uint32_t* r1)
{
#if 0
	console_send_string("hdmiGetN_Value (todo.c): TODO\r\n");
#endif

	if ((r0 > 25163) && (r0 < 25188))
	{
		return r1[1];
	}
	else if ((r0 > 74137) && (r0 < 74213))
	{
		return r1[2];
	}
	else
	{
		return r1[0];
	}
}


/* 234257c4 - todo */
int hdmiSetAudioSPDIF(hdmiHandleT* handlePtr)
{
	uint8_t chst[5];

#if 1
	console_send_string("hdmiSetAudioSPDIF\r\n");
#endif

	int fs = handlePtr->fs;

	hdmiUpdateNandMCLK(handlePtr->audioClock, fs, hdmiStandardVideoTiming[ handlePtr->vic ].Data_0);

	hdmiI2cWriteByte(0x7a, 0x14, 0x03);

	chst[0] = 0;
	chst[1] = 0;
	chst[2] = 0;
	chst[3] = channelStatusTable[fs];
	chst[4] = (channelStatusTable[fs] << 4) & 0xf0;
	chst[4] |= 2;

	hdmiI2cWriteByte(0x7a, 0x1e, chst[0]);
	hdmiI2cWriteByte(0x7a, 0x1f, chst[1]);
	hdmiI2cWriteByte(0x7a, 0x20, chst[2]);
	hdmiI2cWriteByte(0x7a, 0x21, chst[3]);
	hdmiI2cWriteByte(0x7a, 0x22, chst[4]);
	hdmiI2cWriteByte(0x7a, 0x2f, 0x21);

	hdmiAudioInfoFrame(handlePtr);
}



