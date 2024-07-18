
#include <stdint.h>
#include "ucos_ii.h"
#include "sys_services.h"
#include "gpio.h"
#include "bm.h"
#include "tsd.h"
//#include "rl_net.h"

struct unaligned_int
{
	uint32_t i;
} __attribute__((__packed__, __may_alias__));

//bm.c
extern int Data_234ac874; //234ac874
extern int Data_234ac878; //234ac878
extern int Data_234ac87c; //234ac87c / 23492354
extern int Data_234ac880; //234ac880 / 23492358
extern int Data_234ac884; //234ac884
extern int Data_234ac888; //234ac888
extern int Data_234ac88c; //234ac88c
extern int Data_234ac890; //234AC890

int sub_2342dea8(int, Struct_2342c4f8_Inner8*);
void sub_2342dd4c(int, int);
void sub_2342dd64(int, int);
void sub_2342ddcc(int);
uint32_t sub_2342292c(int);
uint32_t sub_23422944(int);

//234923a4 / 234ac8cc
int Data_234ac8cc = 0; //234ac8cc
int Data_234ac8d0 = 0; //234ac8d0 +4
void* tsd_sema/*sema*/ = 0; //234923AC / 234ac8d4 +8
int Data_234ac8d8 = 0; //234923B0 / 234ac8d8 +0xc
int Data_234ac8dc = 0; //234923B4 / 234AC8DC +0x10

//bm.c
extern int Data_236e0b14[]; //236e0b14 / 235b1cec
extern int Data_236e0b34[]; //236e0b34 / 235b1d0c

uint32_t FREG_TSD0_PidValueMirror[13]; //236e3484
uint32_t FREG_TSD0_PidConfig_1Mirror[32]; //236e34b8
uint32_t FREG_TSD0_PidConfig_2Mirror[32]; //236e3538
uint32_t Data_236e35b8[32]; //236e35b8
uint32_t Data_236e3638[32]; //236e3638
uint32_t Data_236e36b8[32]; //236e36b8
uint32_t Data_236e3738[32]; //236e3738
uint32_t FREG_TSD1_PidValueMirror[13]; //236e37b8
uint32_t FREG_TSD1_PidConfig_1Mirror[32]; //236e37ec
uint32_t FREG_TSD1_PidConfig_2Mirror[32]; //236e386c
uint32_t Data_236e38ec[32]; //236e38ec
uint32_t Data_236e396c[32]; //236e396c
uint32_t Data_236e39ec[32]; //236e39ec
uint32_t Data_236e3a6c[32]; //236e3a6c
uint32_t FREG_TSD2_PidValueMirror[13]; //236e3aec
uint32_t FREG_TSD2_PidConfig_1Mirror[32]; //236e3b20
uint32_t FREG_TSD2_PidConfig_2Mirror[32]; //236e3ba0
uint32_t Data_236e3c20[32]; //236e3c20
uint32_t Data_236e3ca0[32]; //236e3ca0
uint32_t Data_236e3d20[32]; //236e3d20
uint32_t Data_236e3da0[32]; //236e3da0
uint32_t FREG_TSD3_PidValueMirror[13]; //236e3e20
uint32_t FREG_TSD3_PidConfig_1Mirror[32]; //236e3e54
uint32_t FREG_TSD3_PidConfig_2Mirror[32]; //236e3ed4
uint32_t Data_236e3f54[32]; //236e3f54
uint32_t Data_236e3fd4[32]; //236e3fd4
uint32_t Data_236e4054[32]; //236e4054
uint32_t Data_236e40d4[32]; //236e40d4

struct Struct_236e4154
{
	uint8_t bData_0; //0
	int Data_4; //4 //TODO: Change to bitfield!!!
	//8
} Data_236e4154[4][128]; //236e4154 -> 236E5154


TSD_Handle Data_236e5154[40]; //236e5154 -> 236E5834

Struct_236e5834 Data_236e5834[40]; //236e5834 +39A80 = 2371F2B4 / 235b6a0c

struct
{
	int fill_0[242]; //0
	//0x3c8
} Data_2371f2b4; //2371f2b4 -> 2371F67C


TSD_InitParams Data_2371f67c; //2371f67c -> 2371F6C4

struct
{
	Struct_20611068* Data_0; //0
	Struct_20611068* Data_4; //4
	Struct_20611068* Data_8; //8
	Struct_20611068* Data_0xc; //12
	Struct_20611068* Data_0x10; //16
	Struct_20611068* Data_0x14; //20
	Struct_20611068* Data_0x18; //24
	Struct_20611068* Data_0x1c; //28
	Struct_20611068* Data_0x20; //32
	Struct_20611068* Data_0x24; //36
	Struct_20611068* Data_0x28; //40

} Data_2371f6c4;


Struct_235f048c Data_235f048c[22]; //235f048c



/* 2342a20c - todo */
void tsd_SetCrc(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8500000 + (b * 8));

	if (a == 0)
	{
		r3[1] = c; //FREG_TSD0_CRC
	}
	else if (a == 1)
	{
		r3[65] = c; //FREG_TSD1_CRC
	}
	else
	{
		r3 = (void*) (0xc8d00000 + (b * 8));
		if (a == 2)
		{
			r3[1] = c; //FREG_TSD2_CRC
		}
		else
		{
			r3[65] = c; //FREG_TSD3_CRC
		}
	}
}


/* 2342a244 - todo */
void sub_2342a244(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 16));

	if (a == 0)
	{
		Data_236e3738[b] = c;
		r3[80] = c; //?
	}
	else if (a == 1)
	{
		Data_236e3a6c[b] = c;
		r3[208] = c; //
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 16));
		if (a == 2)
		{
			Data_236e3da0[b] = c;
			r3[80] = c; //
		}
		else
		{
			Data_236e40d4[b] = c;
			r3[208] = c; //
		}
	}
}


/* 2342a294 - todo */
void sub_2342a294(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 16));

	if (a == 0)
	{
		Data_236e36b8[b] = c;
		r3[79] = c; //?
	}
	else if (a == 1)
	{
		Data_236e39ec[b] = c;
		r3[207] = c; //
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 16));
		if (a == 2)
		{
			Data_236e3d20[b] = c;
			r3[79] = c; //
		}
		else
		{
			Data_236e4054[b] = c;
			r3[207] = c; //
		}
	}
}


/* 2342a2e4 - todo */
void sub_2342a2e4(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 16));

	if (a == 0)
	{
		Data_236e3638[b] = c;
		r3[78] = c; //?
	}
	else if (a == 1)
	{
		Data_236e396c[b] = c;
		r3[206] = c; //
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 16));
		if (a == 2)
		{
			Data_236e3ca0[b] = c;
			r3[78] = c; //
		}
		else
		{
			Data_236e3fd4[b] = c;
			r3[206] = c; //
		}
	}
}


/* 2342a334 - complete */
void sub_2342a334(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 16));

	if (a == 0)
	{
		Data_236e35b8[b] = c;
		r3[77] = c; //FREG_TSD0_DSCODDKEYUPPER?
	}
	else if (a == 1)
	{
		Data_236e38ec[b] = c;
		r3[205] = c; //FREG_TSD1_DSCODDKEYUPPER
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 16));
		if (a == 2)
		{
			Data_236e3c20[b] = c;
			r3[77] = c; //FREG_TSD2_DSCODDKEYUPPER
		}
		else
		{
			Data_236e3f54[b] = c;
			r3[205] = c; //FREG_TSD2_DSCODDKEYUPPER
		}
	}
}


/* 2341ee7c / 2342a384 - complete */
void tsd_SetPidChannelActive(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8000000 + (b * 4));

	if (a == 0)
	{
		r3[0] = c; //FREG_TSD0_PIDCHANNELACTIVE
	}
	else if (a == 1)
	{
		r3[32] = c; //FREG_TSD1_PIDCHANNELACTIVE
	}
	else
	{
		r3 = (void*) (0xc8800000 + (b * 4));
		if (a == 2)
		{
			r3[0] = c; //FREG_TSD2_PIDCHANNELACTIVE
		}
		else
		{
			r3[32] = c; //FREG_TSD3_PIDCHANNELACTIVE
		}
	}
}


/* 2341eeb4 / 2342a3bc - complete */
void tsd_SetPidConfig_1(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 8));

	if (a == 0)
	{
		FREG_TSD0_PidConfig_1Mirror[b] = c;
		r3[13] = c; //FREG_TSD0_PIDCONFIG_1
	}
	else if (a == 1)
	{
		FREG_TSD1_PidConfig_1Mirror[b] = c;
		r3[141] = c; //FREG_TSD1_PIDCONFIG_1
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 8));
		if (a == 2)
		{
			FREG_TSD2_PidConfig_1Mirror[b] = c;
			r3[13] = c; //FREG_TSD2_PIDCONFIG_1
		}
		else
		{
			FREG_TSD3_PidConfig_1Mirror[b] = c;
			r3[141] = c; //FREG_TSD3_PIDCONFIG_1
		}
	}
}


/* 2341ef04 / 2342a40c - todo */
void tsd_SetPidConfig_1_BufferIndex(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 8));

	c = (c << 8) & (0x1f << 8);

	if (a == 0)
	{
		FREG_TSD0_PidConfig_1Mirror[b] = (FREG_TSD0_PidConfig_1Mirror[b] & ~(0x1f << 8)) | c;
		r3[13] = FREG_TSD0_PidConfig_1Mirror[b]; //FREG_TSD0_SetPidConfig_1_BufferIndex
	}
	else if (a == 1)
	{
		FREG_TSD1_PidConfig_1Mirror[b] = (FREG_TSD1_PidConfig_1Mirror[b] & ~(0x1f << 8)) | c;
		r3[141] = FREG_TSD1_PidConfig_1Mirror[b]; //
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 8));
		if (a == 2)
		{
			FREG_TSD2_PidConfig_1Mirror[b] = (FREG_TSD2_PidConfig_1Mirror[b] & ~(0x1f << 8)) | c;
			r3[13] = FREG_TSD2_PidConfig_1Mirror[b]; //
		}
		else
		{
			FREG_TSD3_PidConfig_1Mirror[b] = (FREG_TSD3_PidConfig_1Mirror[b] & ~(0x1f << 8)) | c;
			r3[141] = FREG_TSD3_PidConfig_1Mirror[b]; //
		}
	}
}


/* 2341ef74 / 2342a47c - complete */
void tsd_SetPidConfig_2(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 8));

	if (a == 0)
	{
		FREG_TSD0_PidConfig_2Mirror[b] = c;
		r3[14] = c; //FREG_TSD0_PIDCONFIG_2
	}
	else if (a == 1)
	{
		FREG_TSD1_PidConfig_2Mirror[b] = c;
		r3[142] = c; //FREG_TSD1_PIDCONFIG_2
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 8));
		if (a == 2)
		{
			FREG_TSD2_PidConfig_2Mirror[b] = c;
			r3[14] = c; //FREG_TSD2_PIDCONFIG_2
		}
		else
		{
			FREG_TSD3_PidConfig_2Mirror[b] = c;
			r3[142] = c; //FREG_TSD3_PIDCONFIG_2
		}
	}
}


/* 2342a4cc - todo */
void sub_2342a4cc(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 8));

	if (a == 0)
	{
		FREG_TSD0_PidConfig_2Mirror[b] = (FREG_TSD0_PidConfig_2Mirror[b] & ~0x01) | (c & 1);
		r3[14] = FREG_TSD0_PidConfig_2Mirror[b]; //FREG_TSD0_SetPidConfig_2_BypassDsc
	}
	else if (a == 1)
	{
		FREG_TSD1_PidConfig_2Mirror[b] = (FREG_TSD1_PidConfig_2Mirror[b] & ~0x01) | (c & 1);
		r3[142] = FREG_TSD1_PidConfig_2Mirror[b]; //FREG_TSD1_PIDCONFIG_2
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 8));
		if (a == 2)
		{
			FREG_TSD2_PidConfig_2Mirror[b] = (FREG_TSD2_PidConfig_2Mirror[b] & ~0x01) | (c & 1);
			r3[14] = FREG_TSD2_PidConfig_2Mirror[b]; //FREG_TSD2_PIDCONFIG_2
		}
		else
		{
			FREG_TSD3_PidConfig_2Mirror[b] = (FREG_TSD3_PidConfig_2Mirror[b] & ~0x01) | (c & 1);
			r3[142] = FREG_TSD3_PidConfig_2Mirror[b]; //FREG_TSD3_PIDCONFIG_2
		}
	}
}


/* 2342a540 - todo */
void sub_2342a540(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 8));

	c = (c << 3) & (1 << 3);

	if (a == 0)
	{
		FREG_TSD0_PidConfig_2Mirror[b] = (FREG_TSD0_PidConfig_2Mirror[b] & ~(1 << 3)) | c;
		r3[14] = FREG_TSD0_PidConfig_2Mirror[b]; //FREG_TSD0_SetPidConfig_2_ExtractPcr
	}
	else if (a == 1)
	{
		FREG_TSD1_PidConfig_2Mirror[b] = (FREG_TSD1_PidConfig_2Mirror[b] & ~(1 << 3)) | c;
		r3[142] = FREG_TSD1_PidConfig_2Mirror[b]; //FREG_TSD1_PIDCONFIG_2
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 8));
		if (a == 2)
		{
			FREG_TSD2_PidConfig_2Mirror[b] = (FREG_TSD2_PidConfig_2Mirror[b] & ~(1 << 3)) | c;
			r3[14] = FREG_TSD2_PidConfig_2Mirror[b]; //FREG_TSD2_PIDCONFIG_2
		}
		else
		{
			FREG_TSD3_PidConfig_2Mirror[b] = (FREG_TSD3_PidConfig_2Mirror[b] & ~(1 << 3)) | c;
			r3[142] = FREG_TSD3_PidConfig_2Mirror[b]; //FREG_TSD3_PIDCONFIG_2
		}
	}
}


/* 2341f0a8 / 2342a5b0 - todo */
void setPidConfig_2_NewPcrIrqEn(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 8));

	c = (c << 11) & (1 << 11);

	if (a == 0)
	{
		FREG_TSD0_PidConfig_2Mirror[b] = (FREG_TSD0_PidConfig_2Mirror[b] & ~(1 << 11)) | c;
		r3[14] = FREG_TSD0_PidConfig_2Mirror[b]; //FREG_TSD0_SetPidConfig_2_NewPcrIrqEn
	}
	else if (a == 1)
	{
		FREG_TSD1_PidConfig_2Mirror[b] = (FREG_TSD1_PidConfig_2Mirror[b] & ~(1 << 11)) | c;
		r3[142] = FREG_TSD1_PidConfig_2Mirror[b]; //FREG_TSD1_PIDCONFIG_2
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 8));
		if (a == 2)
		{
			FREG_TSD2_PidConfig_2Mirror[b] = (FREG_TSD2_PidConfig_2Mirror[b] & ~(1 << 11)) | c;
			r3[14] = FREG_TSD2_PidConfig_2Mirror[b]; //FREG_TSD2_PIDCONFIG_2
		}
		else
		{
			FREG_TSD3_PidConfig_2Mirror[b] = (FREG_TSD3_PidConfig_2Mirror[b] & ~(1 << 11)) | c;
			r3[142] = FREG_TSD3_PidConfig_2Mirror[b]; //FREG_TSD3_PIDCONFIG_2
		}
	}
}


/* 2342a620 - todo */
void sub_2342a620(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 8));

	c = (c << 4) & 0x10;

	if (a == 0)
	{
		FREG_TSD0_PidConfig_2Mirror[b] = (FREG_TSD0_PidConfig_2Mirror[b] & ~0x10) | c;
		r3[14] = FREG_TSD0_PidConfig_2Mirror[b]; //FREG_TSD0_SetPidConfig_2_PesPayload
	}
	else if (a == 1)
	{
		FREG_TSD1_PidConfig_2Mirror[b] = (FREG_TSD1_PidConfig_2Mirror[b] & ~0x10) | c;
		r3[142] = FREG_TSD1_PidConfig_2Mirror[b]; //FREG_TSD1_PIDCONFIG_2
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 8));
		if (a == 2)
		{
			FREG_TSD2_PidConfig_2Mirror[b] = (FREG_TSD2_PidConfig_2Mirror[b] & ~0x10) | c;
			r3[14] = FREG_TSD2_PidConfig_2Mirror[b]; //FREG_TSD2_PIDCONFIG_2
		}
		else
		{
			FREG_TSD3_PidConfig_2Mirror[b] = (FREG_TSD3_PidConfig_2Mirror[b] & ~0x10) | c;
			r3[142] = FREG_TSD3_PidConfig_2Mirror[b]; //FREG_TSD3_PIDCONFIG_2
		}
	}
}


/* 2341f188 / 2342a690 - todo */
void tsd_SetPidConfig_2_StoreCompletePacket(int a, int b, int c)
{
#if 0
	console_send_string("tsd_SetPidConfig_2_StoreCompletePacket (todo.c): TODO\r\n");
#endif

	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 8));

	c = (c << 15) & 0x8000;

	if (a == 0)
	{
		FREG_TSD0_PidConfig_2Mirror[b] = (FREG_TSD0_PidConfig_2Mirror[b] & ~0x8000) | c;
		r3[14] = FREG_TSD0_PidConfig_2Mirror[b]; //FREG_TSD0_SetPidConfig_2_StoreCompletePacket
	}
	else if (a == 1)
	{
		FREG_TSD1_PidConfig_2Mirror[b] = (FREG_TSD1_PidConfig_2Mirror[b] & ~0x8000) | c;
		r3[142] = FREG_TSD1_PidConfig_2Mirror[b]; //FREG_TSD1_PIDCONFIG_2
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 8));
		if (a == 2)
		{
			FREG_TSD2_PidConfig_2Mirror[b] = (FREG_TSD2_PidConfig_2Mirror[b] & ~0x8000) | c;
			r3[14] = FREG_TSD2_PidConfig_2Mirror[b]; //FREG_TSD2_PIDCONFIG_2
		}
		else
		{
			FREG_TSD3_PidConfig_2Mirror[b] = (FREG_TSD3_PidConfig_2Mirror[b] & ~0x8000) | c;
			r3[142] = FREG_TSD3_PidConfig_2Mirror[b]; //FREG_TSD3_PIDCONFIG_2
		}
	}
}


/* 2342a700 - todo */
void sub_2342a700(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8100000 + (b * 4));

	if (a == 0)
	{
		FREG_TSD0_PidValueMirror[b] = c;
		r3[0] = c; //FREG_TSD0_PIDVALUE
	}
	else if (a == 1)
	{
		FREG_TSD1_PidValueMirror[b] = c;
		r3[128] = c; //FREG_TSD1_PIDVALUE
	}
	else
	{
		r3 = (void*) (0xc8900000 + (b * 4));
		if (a == 2)
		{
			FREG_TSD2_PidValueMirror[b] = c;
			r3[0] = c; //FREG_TSD2_PIDVALUE
		}
		else
		{
			FREG_TSD3_PidValueMirror[b] = c;
			r3[128] = c; //FREG_TSD3_PIDVALUE
		}
	}
}


/* 2342a750 - todo */
void tsd_SetSbCtrl(int a, int b, int c)
{
	volatile uint32_t* r3 = (void*) (0xc8500000 + (b * 8));

	if (a == 0)
	{
		r3[0] = c; //FREG_TSD0_SBCTRL
	}
	else if (a == 1)
	{
		r3[64] = c; //FREG_TSD1_SBCTRL
	}
	else
	{
		r3 = (void*) (0xc8d00000 + (b * 8));
		if (a == 2)
		{
			r3[0] = c; //FREG_TSD2_SBCTRL
		}
		else
		{
			r3[64] = c; //FREG_TSD3_SBCTRL
		}
	}
}


/* 2341f280 / 2342a788 - todo */
int sub_2342a788(int a)
{
	uint32_t sp_0x530[8];
	uint32_t sp_0x4b0[32];
	uint32_t sp_0x430[32];
	uint32_t sp_0x3b0[32];
	uint32_t sp_0x330[32];
	uint32_t sp_0x2b0[32];
	uint32_t sp_0x230[32];
	uint32_t sp_0x1b0[32];
	uint32_t sp_0x130[32];
	uint32_t sp_0x88[32];
	uint32_t sp8[32];
	uint32_t r4 = 0;
	uint32_t r8 = 0;
#if 0
	int r7 = 0xC8800000;
	int r6 = 0xc8300000;
#endif

	if (a == 0)
	{
		//0x2342a7ac
		uint32_t sb = FREG(0xc8000100)[0]; //FREG_TSD01_INPUTCTRL
		uint32_t sl = FREG(0xc8000104)[0]; //FREG_TSD01_STARTDISTANCE
		uint32_t fp = FREG(0xc8000108)[0]; //FREG_TSD01_READSIGNALDISTANCE
		uint32_t sp_0x128 = FREG(0xc800010c)[0]; //FREG_TSD01_INPUTTIMEOUT
		uint32_t sp_0x124 = FREG(0xc8000114)[0]; //FREG_TSD01_VALIDINPUTTIMEOUT
		uint32_t sp_0x120 = FREG(0xc800011c)[0]; //FREG_TSD_IOCHANNELSELECT
		uint32_t sp_0x11c = FREG(0xc8000134)[0]; //FREG_TSD01_LOADPCR
		uint32_t sp_0x118 = FREG(0xc8210000)[0]; //FREG_TSD01_INRAMCFG
		uint32_t sp_0x108 = FREG(0xc800013c)[0]; //FREG_TSD01_PESCFG
		uint32_t sp_0x10c = FREG(0xc8000148)[0]; //???
		uint32_t sp_0x110 = FREG(0xc8000154)[0]; //???
		uint32_t sp_0x114 = FREG(0xc8000160)[0]; //???

		memcpy(&sp_0x88, FREG(0xc8000000), 0x80); //FREG_TSD0_PIDCHANNELACTIVE
		memcpy(&sp8, FREG(0xc8000080), 0x80); //FREG_TSD1_PIDCHANNELACTIVE

		uint32_t r5 = FREG(0xC880011c)[0]; //FREG_BM_HCBSELECT

		memcpy(&sp_0x530, FREG(0xC8300240), 32); //FREG_BM01_BUFHIGHLEV

		FREG(0xC8300210)[0] = 0xf0000000; //FREG_BM01_GLOBALOFFSET

		memcpy(&sp_0x4b0, FREG(0xc8300000), 0x80); //FREG_BM0_BUFSIZE
		memcpy(&sp_0x430, FREG(0xc8300080), 0x80); //FREG_BM0_WRPTR
		memcpy(&sp_0x3b0, FREG(0xc8300100), 0x80); //FREG_BM0_BASEADDR
		memcpy(&sp_0x330, FREG(0xc8300180), 0x80); //FREG_BM0_RDPTR

		memset(FREG(0xc8300080), 0, 0x80); //FREG_BM0_WRPTR
		memset(FREG(0xc8300180), 0, 0x80); //FREG_BM0_RDPTR
		memset(FREG(0xc8300000), 0, 0x80); //FREG_BM0_BUFSIZE

		memcpy(&sp_0x2b0, FREG(0xc8300400), 0x80); //FREG_BM1_BUFSIZE
		memcpy(&sp_0x230, FREG(0xc8300480), 0x80); //FREG_BM1_WRPTR
		memcpy(&sp_0x1b0, FREG(0xc8300500), 0x80); //FREG_BM1_BASEADDR
		memcpy(&sp_0x130, FREG(0xc8300580), 0x80); //FREG_BM1_RDPTR

		memset(FREG(0xc8300480), 0, 0x80); //FREG_BM1_WRPTR
		memset(FREG(0xc8300580), 0, 0x80); //FREG_BM1_RDPTR
		memset(FREG(0xc8300400), 0, 0x80); //FREG_BM1_BUFSIZE

		r8 = FREG(0xC8A10000)[0];
		FREG(0xC8A10000)[0] = r8 | 0x30; //FREG_TSD23_INRAMCFG

		sub_2342ddcc(0);
		sub_2342ddcc(1);

		FREG(0xC880011c)[0] = r5; //FREG_BM_HCBSELECT

		FREG(0xc8300210)[0] = Data_234ac87c; //FREG_BM01_GLOBALOFFSET
		FREG(0xc8300214)[0] = Data_234ac880; //FREG_BM01_ENDIANSWAPRD

		sub_2342dd64(0, Data_236e0b34[0]);
		sub_2342dd64(1, Data_236e0b34[1]);
		sub_2342dd64(2, Data_236e0b34[2]);
		sub_2342dd64(3, Data_236e0b34[3]);
		sub_2342dd64(4, Data_236e0b34[4]);

		memcpy(FREG(0xc8300000), &sp_0x4b0, 0x80); //FREG_BM0_BUFSIZE
		memcpy(FREG(0xc8300080), &sp_0x430, 0x80); //FREG_BM0_WRPTR
		memcpy(FREG(0xc8300100), &sp_0x3b0, 0x80); //FREG_BM0_BASEADDR
		memcpy(FREG(0xc8300180), &sp_0x330, 0x80); //FREG_BM0_RDPTR

		FREG(0xc8300218)[0] = Data_234ac884; //FREG_BM0_ENDIANSWAPWR

		memcpy(FREG(0xc8300400), &sp_0x2b0, 0x80); //FREG_BM1_BUFSIZE
		memcpy(FREG(0xc8300480), &sp_0x230, 0x80); //FREG_BM1_WRPTR
		memcpy(FREG(0xc8300500), &sp_0x1b0, 0x80); //FREG_BM1_BASEADDR
		memcpy(FREG(0xc8300580), &sp_0x130, 0x80); //FREG_BM1_RDPTR

		FREG(0xc8300618)[0] = Data_234ac88c; //FREG_BM1_ENDIANSWAPWR

		FREG(0xc8300200)[0] = Data_234ac874; //FREG_BM0_IRQMASK
		FREG(0xc8300600)[0] = Data_234ac888; //FREG_BM1_IRQMASK

		memcpy(FREG(0xC8300240), &sp_0x530, 32); //FREG_BM01_BUFHIGHLEV

		sub_2342dd4c(0, Data_236e0b14[0]);
		sub_2342dd4c(1, Data_236e0b14[1]);
		sub_2342dd4c(2, Data_236e0b14[2]);
		sub_2342dd4c(3, Data_236e0b14[3]);
		sub_2342dd4c(4, Data_236e0b14[4]);
		sub_2342dd4c(5, Data_236e0b14[5]);
		sub_2342dd4c(6, Data_236e0b14[6]);
		sub_2342dd4c(7, Data_236e0b14[7]);

		FREG(0xc83002f4)[0] = Data_234ac890; //FREG_BM01_AUDCFGEN

		FREG(0xc8300208)[0] = Data_234ac878; //FREG_BM01_READENABLE

		FREG(0xc8000100)[0] = sb; //FREG_TSD01_INPUTCTRL
		FREG(0xc8000104)[0] = sl; //FREG_TSD01_STARTDISTANCE
		FREG(0xc8000108)[0] = fp; //FREG_TSD01_READSIGNALDISTANCE
		FREG(0xc800010c)[0] = sp_0x128; //FREG_TSD01_INPUTTIMEOUT
		FREG(0xc8000114)[0] = sp_0x124; //FREG_TSD01_VALIDINPUTTIMEOUT
		FREG(0xc800011c)[0] = sp_0x120; //FREG_TSD_IOCHANNELSELECT
		FREG(0xc8000134)[0] = sp_0x11c; //FREG_TSD01_LOADPCR
		FREG(0xc8210000)[0] = sp_0x118; //FREG_TSD01_INRAMCFG
		FREG(0xc800013c)[0] = sp_0x108; //FREG_TSD01_PESCFG
		FREG(0xc8000148)[0] = sp_0x10c; //???
		FREG(0xc8000154)[0] = sp_0x110; //???
		FREG(0xc8000160)[0] = sp_0x114; //???

		//r2, r0, #0x500000
		//r1, #0x0
		//mvn        r3, #0x0
		//->loc_2342aeac
		for (r4 = 0; r4 < 32; r4++)
		{
			//loc_2342aeac
			FREG(0xc8500000)[r4 * 2] = 0; //FREG_TSD0_SBCTRL
			FREG(0xc8500100)[r4 * 2] = 0; //FREG_TSD1_SBCTRL
			FREG(0xc8500004)[r4 * 2] = 0xffffffff; //FREG_TSD0_CRC
			FREG(0xc8500104)[r4 * 2] = 0xffffffff; //FREG_TSD1_CRC
		}

		memcpy(FREG(0xc8000000), &sp_0x88, 0x80); //FREG_TSD0_PIDCHANNELACTIVE
		//->loc_2342af24
		memcpy(FREG(0xc8000080), &sp8, 0x80); //FREG_TSD1_PIDCHANNELACTIVE
	}
	else
	{
		//loc_2342ab30
		//TODO!!!!
#if 0
		console_send_string("sub_2342a788 (a != 0): TODO\r\n");
#endif
	}

	if (a == 0)
	{
		FREG(0xc8a10000)[0] = r8; // FREG_TSD23_INRAMCFG
		//->loc_2342af4c
	}
	else
	{
		//0x2342af3c

		//TODO!!!
#if 0
		console_send_string("sub_2342a788 (a != 0): TODO\r\n");
#endif
	}

	return 0;
}


/* 2341faa8 / 2342afb0 - complete */
int tsd_get_bm_write_pointer(TSD_BM_Buffer* r0, uint32_t blockIndex, int* pWritePtr)
{
#if 0
	console_send_string("tsd_get_bm_write_pointer (todo.c): TODO\r\n");
#endif

	uint32_t writePtr;
	uint32_t r3 = blockIndex & 0xffff;
	uint32_t r4 = blockIndex >> 16;
	uint32_t size = r0->bmSize;

	if (r3 == 0)
	{
		writePtr = FREG(0xc8300080 + (r4 * 4))[0];
	}
	else if (r3 == 1)
	{
		writePtr = FREG(0xc8300480 + (r4 * 4))[0];
	}
	else if (r3 == 2)
	{
		writePtr = FREG(0xc8b00080 + (r4 * 4))[0];
	}
	else if (r3 == 3)
	{
		writePtr = FREG(0xc8b00480 + (r4 * 4))[0];
	}
	else
	{
		writePtr = 0;
	}

	*pWritePtr = writePtr;

	int r0_ = writePtr - r0->Data_0;
	if (r0_ < 0)
	{
		r0_ += size;
	}

	return r0_;
}


/* 2341fc0c / 2342b114 - todo */
void tsd_copy_section_data(uint32_t* ip, uint16_t r1, uint32_t* c, uint16_t r3, void* e)
{
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "tsd_copy_section_data: r1=%d, r3=%d\r\n",
				r1, r3);
		console_send_string(debug_string);
	}
#endif

	uint32_t* r0 = e;
	if (r0 == 0)
	{
		return;
	}

	int32_t r1_ = r1 / 4;
	uint32_t r3_ = r3 / 4;

	do
	{
		//loc_2342b130
		r1_--;
		if (r1_ != -1)
		{
			*r0++ = *ip++;
		}
	}
	while (r1_ != -1);
	//->loc_2342b160
	while (r3_--)
	{
		//loc_2342b150
		*r0++ = *c++;
	}

#if 0
	{
		extern char debug_string[];
		for (int i = 0; (i < (r1+r3)) && (i < 32); i++)
		{
			sprintf(debug_string, "tsd_copy_section_data: e[%d]=0x%02x\r\n", i, ((uint8_t*)e)[i]);
			console_send_string(debug_string);
		}
	}
#endif
}


/* 2341ff34 / 2342b43c - todo */
void tsd_isr(int a)
{
	//r8 = 0xC8400000
	Struct_236e5834* r7 = 0;
	TSD_Handle* r4 = 0;
	//r6, r7

	volatile uint32_t* r2 = (void*) 0xC8400000;

	if (a == 1)
	{
		r2 = (void*) 0xC8C00000;
	}

	uint32_t r1 = FREG(r2)[0];

#if 0
	if (a == 0)
	{
		//TSD01_IRQ 0xC8400000
		r1 = FREG(0xC8400000)[0];
	}
	else if (a == 1)
	{
		//TSD23_IRQ 0xC8C00000
		r1 = FREG(0xC8C00000)[0];
	}
#endif

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "tsd_isr: r1=0x%08x\r\n", r1);
		console_send_string(debug_string);
	}
#endif

#if 0
	{
		uint32_t tsd01_status = FREG(0xC8000138)[0]; //TSD01_STATUS
		uint32_t pid_index = tsd01_status & 0x1f;
		switch (pid_index)
		{
			case 8: //Audio
			case 9: //Video
			{
				extern char debug_string[];
				sprintf(debug_string, "tsd_isr: pid_index=%d, tsd01_status=0x%x\r\n",
						pid_index, tsd01_status);
				console_send_string(debug_string);
				break;
			}

#if 0
			default:
			{
				extern char debug_string[];
				sprintf(debug_string, "tsd_isr: tsd01_status=0x%x\r\n",
						tsd01_status);
				console_send_string(debug_string);
				break;
			}
#endif
		}
	}
#endif

//	uint32_t r3 = r1 & (1 << 5);
//	r3 = r3 >> 5;
	int r5 = ((r1 & (1 << 5)/*TSD1_SELECT*/) >> 5) + a*2;

	if ((r1 & (1 << 29)/*IRQ_FIFO_OVF*/) != 0)
	{
		FREG(r2)[256] = 1; //FREG_TSD01_IRQCLEAR

		sub_2342a788(0); //Reset TSD settings

		return;
	}
	//0x2342b47c
	uint32_t r0 = (r1 >> 8) & 0xff; //IRQ_VALUE

	if ((r0 == 0xed/*TRANSPORT_ERROR_IRQ*/) || (r0 == 0xe6/*CRC_ERROR_IRQ*/))
	{
		//loc_2342b684
		return;
	}
	//0x2342b490
	//r2 = 0x0b;
	if (r0 == 0xe1/*SECTION_END_IRQ*/)
	{
		//0x2342b49c
		uint8_t r6 = r1 & 0x1f;
		if (r6 > 32)
		{
			//loc_2342b684
			return;
		}
		//0x2342b4a8
		for (uint32_t i = 0; i < 40; i++)
		{
			//loc_2342b4b4
			if (Data_236e5154[i].Data_4 == (r5 | (r6 << 16)))
			{
				r4 = &Data_236e5154[i];
				//->loc_2342b4dc
				break;
			}
		}
		//loc_2342b4dc
		if (r4 == 0)
		{
			//loc_2342b684
			return;
		}
		//0x2342b4e4
		uint32_t sp8 = r4->Data_0x18;

		uint32_t r0 = tsd_get_bm_write_pointer(&r4->Data_8, r4->Data_4, &sp8);
		if (r0 == 0)
		{
			//loc_2342b684
			return;
		}
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "tsd_isr: r0=%d, sp8=%d\r\n", r0, sp8);
			console_send_string(debug_string);
		}
#endif
		//0x2342b504
		uint32_t r1 = FREG(0xC8400200)[0]; //FREG_TSD01_IRQRDPTR
		r1 = FREG(0xC8400100)[r1]; //FREG_TSD01_IRQDBG
		r1 = (r1 & 0xff00) >> 8;

		volatile uint32_t* r8 = (void*) 0xc8300000;
		volatile uint32_t* sb = (void*) 0xc8b00000;

		if (r1 != 0xe6/*CRC_ERROR_IRQ*/)
		{
			//0x2342b52c
			for (uint32_t i = 0; i < 40; i++)
			{
				//loc_2342b538
				if (Data_236e5834[i].Data_0xc == 0)
				{
					r7 = &Data_236e5834[i];
					r7->Data_0xc = r0;
					r7->Data_8 = r4->Data_0x18;
					//->loc_2342b56c
					break;
				}
			}
			//loc_2342b56c
			if (r7 == 0)
			{
				//loc_2342b684
				return;
			}
			//0x2342b574
			void* sp4 = &r7->Data_0x10;
			uint32_t sl = 24;
			uint32_t fp = 0;

			uint32_t global_offset = sub_23429994(r4->Data_4 & 0xffff);

			uint32_t endAddr = global_offset + r4->Data_8.bmEnd;
			uint32_t startAddr = global_offset + r4->Data_8.bmStart;
			uint32_t r0 = startAddr + r4->Data_8.Data_0;

			if ((r0 + 24) > endAddr)
			{
				sl = endAddr - r0;
				fp = 24 - sl;
			}

			uint32_t r1 = sl + fp;
			if (r1 <= 0x1700)
			{
				tsd_copy_section_data((void*)r0, sl & 0xffff, (void*)startAddr, fp & 0xffff, sp4);
			}

			if ((r7->Data_0x10.Data_0 & 0xffff) == 0)
			{
				//0x2342b5e4
				if (r4->sectionDataNotify == 0)
				{
					r7->Data_0xc = 0;
					//->loc_2342b608
				}
				else
				{
					//0x2342b5f8
					(r4->sectionDataNotify)(r7, r4->Data_0x24 & 0xff);
				}
				//loc_2342b608
				sp8 = (r7->Data_0x10.bData_5 & 0x0f) << 8;
				sp8 |= r7->Data_0x10.bData_6;
				sp8 += 7;

				if (sp8 & 0x03)
				{
					sp8 += (4 - (sp8 & 3));
				}

				r4->Data_8.Data_0 = r4->Data_0x18 = (r4->Data_0x18 + sp8) & (r4->Data_8.bmSize - 1);

				if (r5 == 0)
				{
					FREG(/*0xc8300180*/r8 + 0x60)[r6] = r4->Data_8.Data_0; //FREG_BM0_RDPTR
					//->loc_2342b680
				}
				else if (r5 == 1)
				{
					FREG(/*0xc8300580*/r8 + 0x160)[r6] = r4->Data_8.Data_0; //FREG_BM1_RDPTR
				}
				else if (r5 == 2)
				{
					FREG(/*0xc8b00180*/sb + 0x60)[r6] = r4->Data_8.Data_0; //FREG_BM2_RDPTR
				}
				else if (r5 == 3)
				{
					FREG(/*0xc8b00580*/sb + 0x160)[r6] = r4->Data_8.Data_0; //FREG_BM3_RDPTR
				}
				//loc_2342b684
				return;
			}
			else
			{
				//loc_2342b69c
				r7->Data_0xc = 0;
				//loc_2342b6a4

				//TODO!!!!
			}
		} //if (r1 != 0xe6/*CRC_ERROR_IRQ*/)
		else
		{
			r0 = 0;
			//loc_2342b6a4

			//TODO!!!!
		}
	} //if (r0 == 0xe1/*SECTION_END_IRQ*/)
	//loc_2342b6fc: TODO
	else if (r0 == 0xe0/*PACKET_END_IRQ*/)
	{
		return;
	}
	else if (r0 == 0xe5) //NEW_PCR_IRQ
	{
		sync_PcrNotifier(Data_234ac8d8, r1, 0, 0);
	}
	else if ((r0 == 0xe8) || //NEW_PTS_IRQ_0
			(r0 == 0xe9)) //NEW_PTS_IRQ_1
	{
		//0x2342b730
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "tsd_isr: r1=0x%08x\r\n", r1);
			console_send_string(debug_string);
		}
#endif
	}
	//loc_2342b684
	return;
}


/* 2342b824 - todo */
int tsd_isr_01()
{
#if 0
	console_send_string("tsd_isr_01 (todo.c): TODO\r\n");
#endif

	tsd_isr(0);

	return 0;
}


/* 2342b838 - todo */
int tsd_isr_23()
{
#if 1
	console_send_string("tsd_isr_23 (todo.c): TODO\r\n");
#endif

	tsd_isr(1);

	return 0;
}


/* 2342b84c - complete */
int sub_2342b84c(uint32_t a, int b, int c)
{
#if 0
	console_send_string("sub_2342b84c (todo.c): TODO\r\n");
#endif

	int ip = FREG(0xc800011c)[0]; //FREG_TSD_IOCHANNELSELECT
	int r3 = a / 2;

	if (b != 3)
	{
		ip = ip & ~(0x03 << (a * 2));
		b = b << (a * 2);
	}
	else
	{
		ip = ip & ~0x100;
		b = r3 << 8;
	}

	if (c != 0)
	{
		//0x2342b880
		b = b | (r3 << 12);

		if ((a == 0) || (a == 1))
		{
			Data_234ac8d8 = 0;
		}
		else
		{
			Data_234ac8d8 = 1;
		}
	}
	//loc_2342b89c
	FREG(0xc800011c)[0] = ip | b;

	return 0;
}


/* 234203a4 / 2342b8ac - todo */
int tsd_SetPidFilter(uint8_t a, uint8_t channelId, uint16_t pid)
{
	uint32_t* pid_register_mirror;
	volatile uint32_t* reg;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "tsd_SetPidFilter: a=%d, channelId=%d, pid=0x%04x\r\n",
				a, channelId, pid);
		console_send_string(debug_string);
	}
#endif

	if (a == 0)
	{
		pid_register_mirror = FREG_TSD0_PidValueMirror;
		reg = (void*) 0xc8100000; //FREG_TSD0_PIDVALUE
	}
	else if (a == 1)
	{
		pid_register_mirror = FREG_TSD1_PidValueMirror;
		reg = (void*) 0xc8100200; //FREG_TSD1_PIDVALUE
	}
	else if (a == 2)
	{
		pid_register_mirror = FREG_TSD2_PidValueMirror;
		reg = (void*) 0xc8900000;
	}
	else if (a == 3)
	{
		pid_register_mirror = FREG_TSD3_PidValueMirror;
		reg = (void*) 0xc8900200;
	}
	else
	{
		return 0xff;
	}
	//loc_2342b8f8
	pid_register_mirror[12] &= ~(1 << channelId);
	pid_register_mirror[11] &= ~(1 << channelId);
	pid_register_mirror[10] &= ~(1 << channelId);
	pid_register_mirror[9] &= ~(1 << channelId);
	pid_register_mirror[8] &= ~(1 << channelId);
	pid_register_mirror[7] &= ~(1 << channelId);
	pid_register_mirror[6] &= ~(1 << channelId);
	pid_register_mirror[5] &= ~(1 << channelId);
	pid_register_mirror[4] &= ~(1 << channelId);
	pid_register_mirror[3] &= ~(1 << channelId);
	pid_register_mirror[2] &= ~(1 << channelId);
	pid_register_mirror[1] &= ~(1 << channelId);
	pid_register_mirror[0] &= ~(1 << channelId);

	pid_register_mirror[12] |= (((pid >> 0) & 1) << channelId);
	pid_register_mirror[11] |= (((pid >> 1) & 1) << channelId); //(x << 30) >> 31
	pid_register_mirror[10] |= (((pid >> 2) & 1) << channelId); //(x << 29) >> 31
	pid_register_mirror[9] |= (((pid >> 3) & 1) << channelId); //(x << 28) >> 31
	pid_register_mirror[8] |= (((pid >> 4) & 1) << channelId); //(x << 27) >> 31
	pid_register_mirror[7] |= (((pid >> 5) & 1) << channelId); //(x << 26) >> 31
	pid_register_mirror[6] |= (((pid >> 6) & 1) << channelId); //(x << 25) >> 31
	pid_register_mirror[5] |= (((pid >> 7) & 1) << channelId); //(x << 24) >> 31
	pid_register_mirror[4] |= (((pid >> 8) & 1) << channelId); //(x << 23) >> 31
	pid_register_mirror[3] |= (((pid >> 9) & 1) << channelId); //(x << 22) >> 31
	pid_register_mirror[2] |= (((pid >> 10) & 1) << channelId); //(x << 21) >> 31
	pid_register_mirror[1] |= (((pid >> 11) & 1) << channelId); //(x << 20) >> 31
	pid_register_mirror[0] |= (((pid >> 12) & 1) << channelId); //(x << 19) >> 31

	for (uint32_t i = 0; i < 13; i++)
	{
		//loc_2342ba58
		reg[i] = pid_register_mirror[i];
	}

	return 0;
}


/* 2342ba78 - todo */
int sub_2342ba78(int r6, int r4, TSD_SectionFilter* fp, TSD_Handle* d/*?*/)
{
	struct Struct_236e4154* sp_0x30;
	uint16_t sp_0x2c;
	volatile uint32_t* sp_0x28;
	volatile uint32_t* sp_0x24;
	uint16_t sb;
	uint16_t r5 = 0;
	volatile uint32_t* r7;
	volatile uint32_t* r8;

#if 0
	console_send_string("sub_2342ba78 (todo.c): TODO\r\n");
#endif

	if (r6 == 0)
	{
		sp_0x28 = (void*) 0xc8501000; //FREG_TSD0_SFTARGETS
		sp_0x24 = (void*) 0xc8501400; //FREG_TSD0_SFPTR
	}
	else if (r6 == 1)
	{
		sp_0x28 = (void*) 0xc8501800;
		sp_0x24 = (void*) 0xc8501c00;
	}
	else if (r6 == 2)
	{
		sp_0x28 = (void*) 0xc8d01000;
		sp_0x24 = (void*) 0xc8d01400;
	}
	else if (r6 == 3)
	{
		sp_0x28 = (void*) 0xc8d01800;
		sp_0x24 = (void*) 0xc8d01c00;
	}
	else
	{
		return 0xff;
	}
	//0x2342bae4
	if (fp->bNumTargetIndex > 12)
	{
		return 0xffff;
	}

	sb = fp->bNumTargetIndex * fp->wTargetLength + fp->bNumTargetIndex;
	if (sb % 4)
	{
		sb += 4;
	}

	sb /= 4;
	if (sb == 0)
	{
		return 0xffff;
	}
	//0x2342bb14
	d->Data_0x28 = -1;
#if 0
	sp_0x2c = 0;
	r7 = &FREG(0xc8100000)[r4 * 2]; //FREG_TSD0_PIDVALUE
	r8 = &FREG(0xc8900000)[r4 * 2]; //FREG_TSD2_PIDVALUE
	sp_0x30 = &Data_236e4154[r6];
#endif

	for (sp_0x2c = 0; sp_0x2c < 128; sp_0x2c++)
	{
		//loc_2342bb44
		if (Data_236e4154[r6][sp_0x2c].bData_0 == 0)
		{
			r5++;
		}

		if (r5 == sb)
		{
			//0x2342bb60
			uint8_t* sl = fp->Data_4;
			r5 = 0xff;
			//->loc_2342be24
			while (sb--)
			{
				//loc_2342bb6c
				r5 = sub_2342df2c(r6, r5 & 0xff, sp_0x24);

				if (d->Data_0x28 == -1)
				{
					//0x2342bb90: Set TSDn_PID_CONFIG_2[31:25] PTR_TARGET: Pointer to the first target in SF_target_RAM.
					if (r6 == 0)
					{
						//0x2342bb98
						uint32_t val = ((r5 << 25) & 0xfe000000);
						FREG_TSD0_PidConfig_2Mirror[r4] = (FREG_TSD0_PidConfig_2Mirror[r4] & ~0xfe000000);
						FREG_TSD0_PidConfig_2Mirror[r4] |= val;
						FREG(0xc8100038)[r4 * 2] = FREG_TSD0_PidConfig_2Mirror[r4]; //FREG_TSD0_PIDCONFIG_2
						//->loc_2342bc14
					}
					//loc_2342bbbc
					else if (r6 == 1)
					{
						//0x2342bbc4
						FREG_TSD1_PidConfig_2Mirror[r4] = (FREG_TSD1_PidConfig_2Mirror[r4] & ~0xfe000000)
								| ((r5 << 25) & 0xfe000000);
						FREG(0xc8100238)[r4 * 2] = FREG_TSD1_PidConfig_2Mirror[r4]; //FREG_TSD1_PIDCONFIG_2
						//->loc_2342bc14
					}
					//loc_2342bbe8
					else if (r6 == 2)
					{
						FREG_TSD2_PidConfig_2Mirror[r4] = (FREG_TSD2_PidConfig_2Mirror[r4] & ~0xfe000000)
								| ((r5 << 25) & 0xfe000000);
						FREG(0xc8900038)[r4 * 2] = FREG_TSD2_PidConfig_2Mirror[r4]; //FREG_TSD2_PIDCONFIG_2
					}
					else
					{
						FREG_TSD3_PidConfig_2Mirror[r4] = (FREG_TSD3_PidConfig_2Mirror[r4] & ~0xfe000000)
								| ((r5 << 25) & 0xfe000000);
						FREG(0xc8900238)[r4 * 2] = FREG_TSD3_PidConfig_2Mirror[r4]; //FREG_TSD3_PIDCONFIG_2
					}
					//loc_2342bc14
					uint8_t sp[] = //2342be8c
					{
							0x00, 0x01, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00,
							0x09, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00,
							0x0b, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
							0x0d, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,
							0x0f, 0x00, 0x00, 0x00
					};
					uint8_t r0 = sp[fp->bNumTargetIndex];

					//Set TSDn_PID_CONFIG_2[24:21] N_TARGET: Number of filter target.
					if (r6 == 0)
					{
						//0x2342bc38
						FREG_TSD0_PidConfig_2Mirror[r4] = (FREG_TSD0_PidConfig_2Mirror[r4] & ~0x1e00000)
								| ((r0 << 21) & 0x1e00000);
						FREG(0xc8100038)[r4 * 2] = FREG_TSD0_PidConfig_2Mirror[r4]; //FREG_TSD0_PIDCONFIG_2
					}
					//loc_2342bc5c
					else if (r6 == 1)
					{
						//0x2342bc64
						FREG_TSD1_PidConfig_2Mirror[r4] = (FREG_TSD1_PidConfig_2Mirror[r4] & ~0x1e00000)
								| ((r0 << 21) & 0x1e00000);
						FREG(0xc8100238)[r4 * 2] = FREG_TSD1_PidConfig_2Mirror[r4]; //FREG_TSD1_PIDCONFIG_2
					}
					//loc_2342bc88
					else if (r6 == 2)
					{
						FREG_TSD2_PidConfig_2Mirror[r4] = (FREG_TSD2_PidConfig_2Mirror[r4]  & ~0x1e00000)
								| ((r0 << 21) & 0x1e00000);
						FREG(0xc8900038)[r4 * 2] = FREG_TSD2_PidConfig_2Mirror[r4]; //FREG_TSD2_PIDCONFIG_2
					}
					else
					{
						FREG_TSD3_PidConfig_2Mirror[r4] = (FREG_TSD3_PidConfig_2Mirror[r4] & ~0x1e00000)
								| ((r0 << 21) & 0x1e00000);
						FREG(0xc8900238)[r4 * 2] = FREG_TSD3_PidConfig_2Mirror[r4]; //FREG_TSD3_PIDCONFIG_2
					}
					//loc_2342bcb4
					sub_2342a620(r6, r4, 0);

					//Set TSDn_PID_CONFIG_2[9] SECTION_END_IRQ_EN
					if (r6 == 0)
					{
						FREG_TSD0_PidConfig_2Mirror[r4] |= (1 << 9);
						FREG(0xc8100038)[r4 * 2] = FREG_TSD0_PidConfig_2Mirror[r4]; //FREG_TSD0_PIDCONFIG_2
						//->loc_2342bd2c
					}
					else if (r6 == 1)
					{
						//0x2342bc64
						FREG_TSD1_PidConfig_2Mirror[r4] |= (1 << 9);
						FREG(0xc8100238)[r4 * 2] = FREG_TSD1_PidConfig_2Mirror[r4]; //FREG_TSD1_PIDCONFIG_2
					}
					else if (r6 == 2)
					{
						FREG_TSD2_PidConfig_2Mirror[r4] |= (1 << 9);
						FREG(0xc8900038)[r4 * 2] = FREG_TSD2_PidConfig_2Mirror[r4]; //FREG_TSD2_PIDCONFIG_2
					}
					else
					{
						FREG_TSD3_PidConfig_2Mirror[r4] |= (1 << 9);
						FREG(0xc8900238)[r4 * 2] = FREG_TSD3_PidConfig_2Mirror[r4]; //FREG_TSD3_PIDCONFIG_2
					}

#if 0 //Enable some more TSD Interrupts
					//[13] INPUT_TIMEOUT_IRQ_EN
					//[12] VALID_INPUT_TIMEOUT_IRQ_EN
					//[8] PACKET_END_IRQ_EN
					if (r6 == 0)
					{
						FREG_TSD0_PidConfig_2Mirror[r4] |= (1 << 13) | (1 << 12) | (1 << 8);
						FREG(0xc8100038)[r4 * 2] = FREG_TSD0_PidConfig_2Mirror[r4]; //FREG_TSD0_PIDCONFIG_2
						//->loc_2342bd2c
					}
					else if (r6 == 1)
					{
						//0x2342bc64
						FREG_TSD1_PidConfig_2Mirror[r4] |= (1 << 13) | (1 << 12) | (1 << 8);
						FREG(0xc8100238)[r4 * 2] = FREG_TSD1_PidConfig_2Mirror[r4]; //FREG_TSD1_PIDCONFIG_2
					}
					else if (r6 == 2)
					{
						FREG_TSD2_PidConfig_2Mirror[r4] |= (1 << 13) | (1 << 12) | (1 << 8);
						FREG(0xc8900038)[r4 * 2] = FREG_TSD2_PidConfig_2Mirror[r4]; //FREG_TSD2_PIDCONFIG_2
					}
					else
					{
						FREG_TSD3_PidConfig_2Mirror[r4] |= (1 << 13) | (1 << 12) | (1 << 8);
						FREG(0xc8900238)[r4 * 2] = FREG_TSD3_PidConfig_2Mirror[r4]; //FREG_TSD3_PIDCONFIG_2
					}
#endif

					//loc_2342bd2c: Set TSDn_PID_CONFIG_2[20:16] TARGET_LENGTH
					//r0 = fp->wTargetLength + 1;
					if (r6 == 0)
					{
						//0x2342bd3c
						FREG_TSD0_PidConfig_2Mirror[r4] = (FREG_TSD0_PidConfig_2Mirror[r4] & ~0x1f0000)
								| (((fp->wTargetLength + 1) << 16) & 0x1f0000);
						FREG(0xc8100038)[r4 * 2] = FREG_TSD0_PidConfig_2Mirror[r4]; //FREG_TSD0_PIDCONFIG_2
					}
					else if (r6 == 1)
					{
						FREG_TSD1_PidConfig_2Mirror[r4] = (FREG_TSD1_PidConfig_2Mirror[r4] & ~0x1f0000)
								| (((fp->wTargetLength + 1) << 16) & 0x1f0000);
						FREG(0xc8100238)[r4 * 2] = FREG_TSD1_PidConfig_2Mirror[r4]; //FREG_TSD1_PIDCONFIG_2
					}
					else if (r6 == 2)
					{
						//0x2342bd3c
						FREG_TSD2_PidConfig_2Mirror[r4] = (FREG_TSD2_PidConfig_2Mirror[r4] & ~0x1f0000)
								| (((fp->wTargetLength + 1) << 16) & 0x1f0000);
						FREG(0xc8900038)[r4 * 2] = FREG_TSD2_PidConfig_2Mirror[r4]; //FREG_TSD2_PIDCONFIG_2
					}
					else
					{
						FREG_TSD3_PidConfig_2Mirror[r4] = (FREG_TSD3_PidConfig_2Mirror[r4] & ~0x1f0000)
								| (((fp->wTargetLength + 1) << 16) & 0x1f0000);
						FREG(0xc8900238)[r4 * 2] = FREG_TSD3_PidConfig_2Mirror[r4]; //FREG_TSD3_PIDCONFIG_2
					}
					//loc_2342bdb8
					d->Data_0x28 = r5;
				} //if (d->Data_0x28 == -1)
				//loc_2342bdc0
				sp_0x28[r5 * 2] = __rev(((struct unaligned_int*)sl)->i);
				sp_0x28[r5 * 2 + 1] = __rev(((struct unaligned_int*)(sl + 4))->i);

				sl += 8;

				if (sb == 0)
				{
					Data_236e4154[r6][r5].Data_4 |= 0x80;
				}

				sp_0x24[r5] = Data_236e4154[r6][r5].Data_4 & 0xff;

				if (sb == 0)
				{
					return 0;
				}
			} //while (sb--)
			//loc_2342be34
		}
		//loc_2342be34
	} //for (sp_0x2c = 0; sp_0x2c < 128; sp_0x2c++)

	return 5;
}


/* 2342c134 - todo */
int tsd_init(TSD_InitParams* r5)
{
	uint32_t r6;
	uint32_t ip;
	uint32_t r4 = 0;
//	int r7 = 0;

	Struct_20401328 sp;

#if 0
	console_send_string("tsd_init (todo.c): TODO\r\n");
#endif

	for (r4 = 0; r4 < 4; r4++)
	{
		//loc_2342c144
		for (ip = 0; ip < 8; ip++)
		{
			//loc_2342c148
			sub_2342a334(r4, ip, 0);
			sub_2342a2e4(r4, ip, 0);
			sub_2342a294(r4, ip, 0);
			sub_2342a244(r4, ip, 0);
		}
		//0x2342c194
		for (r6 = 0; r6 < 32; r6++)
		{
			//loc_2342c198
			tsd_SetPidChannelActive(r4, r6, 1);
			tsd_SetPidConfig_1(r4, r6, 0);
			tsd_SetPidConfig_2(r4, r6, 0);
			tsd_SetCrc(r4, r6, 0xffffffff);
			tsd_SetSbCtrl(r4, r6, 0);
			sub_2342a620(r4, r6, 1);
			sub_2342a4cc(r4, r6, 1);
			setPidConfig_2_NewPcrIrqEn(r4, r6, 0);
			sub_2342a540(r4, r6, 1);
		}
		//0x2342c234
		for (ip = 0; ip < 13; ip++)
		{
			//loc_2342c238
			sub_2342a700(r4, ip, 0);
		}
		//0x2342c254
		volatile uint32_t* r0;
		volatile uint32_t* r2;

		if (r4 == 0)
		{
			r0 = (void*) 0xc8501000; //FREG_TSD0_SFTARGETS
			r2 = (void*) 0xc8501400; //FREG_TSD0_SFPTR
			//->loc_2342c294
		}
		else if (r4 == 1)
		{
			r0 = (void*) 0xc8501800; //FREG_TSD1_SFTARGETS
			r2 = (void*) 0xc8501c00; //FREG_TSD1_SFPTR
			//->loc_2342c294
		}
		else if (r4 == 2)
		{
			r0 = (void*) 0xc8d01000; //FREG_TSD2_SFTARGETS
			r2 = (void*) 0xc8d01400; //FREG_TSD2_SFPTR
			//->loc_2342c294
		}
		else if (r4 == 3)
		{
			r0 = (void*) 0xc8d01800; //FREG_TSD3_SFTARGETS
			r2 = (void*) 0xc8d01c00; //FREG_TSD3_SFPTR
			//loc_2342c294
		}
		else
		{
			//->loc_2342c2e8
			break;
		}
		//loc_2342c294
		for (uint32_t r1 = 0; r1 < 0x100; r1++)
		{
			//loc_2342c298
			FREG(r0)[r1] = 0; //r7; //0
		}
		//0x2342c2a8
		for (uint32_t r1 = 0; r1 < 0x80; r1++)
		{
			//loc_2342c2ac
			FREG(r2)[r1] = 0; //r7; //0
		}
		//0x2342c2bc
		FREG(r0)[0] = 0; //r7; //0
		FREG(r0)[1] = 0; //r7; //0
		FREG(r2)[0] = 0x80;

		memset(Data_236e4154[r4], 0, 0x400);

	} //for (r4 = 0; r4 < 4; r4++)
	//loc_2342c2e8
	sp.dwOutFunction = 0xff;

	sp.dwInFunction = 0x2d;
	sp.bPin = r5->wData_0;
	gpio_open(&sp, &Data_2371f6c4.Data_0);

	sp.dwInFunction = 0x2e;
	sp.bPin = r5->wData_2;
	gpio_open(&sp, &Data_2371f6c4.Data_4);

	sp.dwInFunction = 0x2f;
	sp.bPin = r5->wData_4;
	gpio_open(&sp, &Data_2371f6c4.Data_8);

	sp.dwInFunction = 0x30;
	sp.bPin = r5->wData_6;
	gpio_open(&sp, &Data_2371f6c4.Data_0xc);

	sp.dwInFunction = 0x31;
	sp.bPin = r5->wData_8;
	gpio_open(&sp, &Data_2371f6c4.Data_0x10);

	sp.dwInFunction = 0x32;
	sp.bPin = r5->wData_10;
	gpio_open(&sp, &Data_2371f6c4.Data_0x14);

	sp.dwInFunction = 0x33;
	sp.bPin = r5->wData_12;
	gpio_open(&sp, &Data_2371f6c4.Data_0x18);

	sp.dwInFunction = 0x34;
	sp.bPin = r5->wData_14;
	gpio_open(&sp, &Data_2371f6c4.Data_0x1c);

	sp.dwInFunction = 0x35;
	sp.bPin = r5->wData_16;
	gpio_open(&sp, &Data_2371f6c4.Data_0x20);

	sp.dwInFunction = 0x36;
	sp.bPin = r5->wData_18;
	gpio_open(&sp, &Data_2371f6c4.Data_0x24);

	sp.dwInFunction = 0x37;
	sp.bPin = r5->wData_20;
	gpio_open(&sp, &Data_2371f6c4.Data_0x28);

	Data_234ac8cc = 0;
	FREG(0xc8400400)[0] = 0; //FREG_TSD01_IRQCLEAR

	Data_234ac8d0 = 0;
	FREG(0xC8C00400)[0] = 0; //FREG_TSD23_IRQCLEAR

	intr_set_isr(tsd_isr_01, 0, 26); //FAPI_INTR_TSD01
	sub_2341b3b8/*sub_234268c0*/(26, 0);

	FREG(0xe0000068)[128] = 0x0f; //r6

	intr_set_isr(tsd_isr_23, 0, 27); //FAPI_INTR_TSD23
	sub_2341b3b8/*sub_234268c0*/(27, 0);

	FREG(0xe000006c)[128] = 0x0f; //r6

	memset(Data_236e5154, 0, 40 * 44);
	memset(&Data_2371f2b4, 0, 0x3c8);

	for (uint32_t r0 = 0; r0 < 40; r0++)
	{
		//loc_2342c4b8
		Data_236e5834[r0].Data_0xc = 0; //r7
		Data_236e5834[r0].msg_id = 3;
	}
	//0x2342c4d4
	Data_2371f67c = *r5;

	tsd_sema = OSSemCreate(1);

	return 0;
}


/* 23421018 / 2342c4f8 - complete */
int sub_2342c4f8(Struct_2342c4f8* r4)
{
	uint8_t sp;

#if 0
	console_send_string("sub_2342c4f8 (todo.c): TODO\r\n");
#endif

	if (r4->Data_0 > 3)
	{
		return 0xff;
	}

	OSSemPend(tsd_sema, 0, &sp);
	if (sp != 0)
	{
		return sp;
	}

	if (r4->Data_8 != 0)
	{
		if (0 == sub_2342b84c(r4->Data_0, r4->Data_8->Data_0, r4->Data_4))
		{
			sub_2342dea8(r4->Data_0, r4->Data_8);
		}
	}
	//loc_2342c55c
	if (r4->Data_12 != 0)
	{
		if (0 == sub_2342b84c(r4->Data_0, 3, r4->Data_4))
		{
			//0x2342c57c
			int* r1_ = r4->Data_12;
			int r2 = r4->Data_0;
			int r0 = 0;
			int r1 = *r1_;

			if (r1 & 0x3fc)
			{
				//0x2342c594
				if (r1 & 1)
				{
					r0 |= 0x20000000;
				}

				if (r1 & 2)
				{
					r0 |= 0x3000000;
				}

				if ((r2 == 0) || (r2 == 1))
				{
					FREG(0xc8210000)[0] = r0 | 0xff0000; //FREG_TSD01_INRAMCFG
				}
				else
				{
					FREG(0xc8a10000)[0] = r0 | 0xff0000; //FREG_TSD23_INRAMCFG
				}
			}
			//loc_2342c5bc
		}
		//loc_2342c5bc
	}
	//loc_2342c5bc
	OSSemPost(tsd_sema);

	return 0;
}


/* 2342125c / 2342c73c - todo */
int tsd_open_pes_parser(void** pHandle, TSD_PesParserParams* r4)
{
	uint8_t err;
	Struct_235f048c* h = 0;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("tsd_open_pes_parser (todo.c): TODO\r\n");
#endif

	OSSemPend(tsd_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	for (uint32_t i = 0; i < 22; i++)
	{
		//loc_23421294
		if (Data_235f048c[i].bData_0 == 0)
		{
			Data_235f048c[i].bData_0 = 1;
			h = &Data_235f048c[i];
			//->loc_234212c0
			break;
		}
	}
	//loc_234212c0
	if (h == 0)
	{
		OSSemPost(tsd_sema);
		return 5;
	}
	//loc_234212d8
	void* bmHandle = bm_open(&r4->Data_4);

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "tsd_open_pes_parser: bmHandle=0x%p\r\n",
				bmHandle);
		console_send_string(debug_string);
	}
#endif

	tsd_SetPidConfig_1_BufferIndex(r4->bData_0, r4->Data_4.pidChannel, r4->Data_4.pidChannel);

	if (0 != tsd_SetPidFilter(r4->bData_0, r4->Data_4.pidChannel & 0xff, r4->pid))
	{
		h->bData_0 = 0; //r8

		OSSemPost(tsd_sema);
		return 1;
	}
	//loc_23421328
	tsd_SetPidConfig_2_StoreCompletePacket(r4->bData_0, r4->Data_4.pidChannel, 0);

	*pHandle = h;

	h->bData_0x28 = r4->bData_1;
	h->bmHandle = bmHandle;
	h->Data_0x24 = r4->Data_0x38;
	h->Data_4 = r4->bData_0;
	h->Data_4 |= (r4->Data_4.pidChannel << 16);
	h->Data_0x18 = 0; //r8
	h->Data_8 = 0; //r8
	h->Data_12 = r4->Data_4.bufferAddress;
	h->Data_0x10 = r4->Data_4.bufferAddress + r4->Data_4.bufferSize;
	h->Data_0x14 = r4->Data_4.bufferSize;

	if (r4->bData_1 != 0xff)
	{
		int r1 = 0;
		volatile uint32_t* pPESCfg;

		if (r4->bData_0 < 2)
		{
			pPESCfg = FREG(0xc800013c) + (r4->bData_1 & 0x0f) * 3; //TSD01_PES_CFG
		}
		else
		{
			pPESCfg = FREG(0xc880013c) + (r4->bData_1 & 0x0f) * 3;
			r1 |= (1 << 9); //TSD1_SELECT
		}

		r1 |= (r4->Data_4.pidChannel << 4); //PID_INDEX

		if ((r4->bData_1 >> 4) == 0)
		{
			r1 |= (1 << 2); //REMOVE_PES_HEADER
		}

		if (h->Data_0x24 != 0)
		{
			r1 |= (1 << 1); //NEW_PTS_IRQ_EN
		}

		r1 |= (1 << 0); //PES_EN

		OS_ENTER_CRITICAL();

		*pPESCfg = r1;

		OS_EXIT_CRITICAL();
	}
	//loc_234213ec
	OSSemPost(tsd_sema);

	return 0;
}


/* 234213fc / 2342c8dc - complete */
int tsd_set_pes_config(void* a, uint32_t r5)
{
	uint8_t sp;
	Struct_235f048c* r4 = a;

#if 0
	console_send_string("tsd_set_pes_config (todo.c): TODO\r\n");
#endif

#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	uint32_t r6 = r4->Data_4 & 0xffff;
	int pidChannel = r4->Data_4 >> 16;

	OSSemPend(tsd_sema, 0, &sp);
	if (sp != 0)
	{
		return sp;
	}

	if (r5 != 0xff)
	{
		//0x2342c91c
		int r1 = r5 & 0x0f;
		int pes_cfg = 0;

		uint32_t pPESCfg;

		if (r6 < 2)
		{
			pPESCfg = 0xc800013c + r1 * 12;
		}
		else
		{
			pPESCfg = 0xc880013c + r1 * 12;
			pes_cfg |= (1 << 9); //TSD1_SELECT
		}

		pes_cfg |= (pidChannel << 4); //PID_INDEX

		if ((r5 >> 4) == 0)
		{
			pes_cfg |= (1 << 2); //REMOVE_PES_HEADER
		}

		if (r4->Data_0x24 != 0)
		{
			pes_cfg |= (1 << 1); //NEW_PTS_IRQ_EN
		}

		pes_cfg |= (1 << 0); //PES_EN

		OS_ENTER_CRITICAL();

		FREG(pPESCfg)[0] = pes_cfg;

		OS_EXIT_CRITICAL();
	}
	//loc_2342c968
	OSSemPost(tsd_sema);

	return 0;
}


/* 23421498 / 2342c978 - todo */
int tsd_open_pid_channel(TSD_Handle** r8, TSD_PidChannelParams* r4)
{
	uint8_t sp;
	TSD_Handle* r5 = 0;
	uint32_t i;

	OSSemPend(tsd_sema, 0, &sp);
	if (sp != 0)
	{
		return sp;
	}

	for (i = 0; i < 40; i++)
	{
		//loc_2342c9b0
		if (Data_236e5154[i].bData_0 == 0)
		{
			Data_236e5154[i].bData_0 = 1;
			r5 = &Data_236e5154[i];
			//->loc_2342c9dc
			break;
		}
	}
	//loc_2342c9dc
	if (r5 == 0)
	{
		OSSemPost(tsd_sema);

		return 5;
	}
	//loc_2342c9f4
	bm_open(&r4->bmOpenParams);

	tsd_SetPidConfig_1_BufferIndex(r4->bData_1, r4->bmOpenParams.pidChannel, r4->bmOpenParams.pidChannel);

	if (0 != tsd_SetPidFilter(r4->bData_1, r4->bmOpenParams.pidChannel & 0xff, r4->pid)) //r6 = 0;
	{
		//loc_2342cac0
		r5->bData_0 = 0; //r6

		OSSemPost(tsd_sema);

		return 1;
	}
	//0x2342ca2c
	volatile uint32_t* r3 = (void*) (0xc8100000 + (/*b*/r4->bmOpenParams.pidChannel * 8));

	if (/*a*/r4->bData_1 == 0)
	{
		FREG_TSD0_PidConfig_2Mirror[/*b*/r4->bmOpenParams.pidChannel] |= 2;
		r3[14] = FREG_TSD0_PidConfig_2Mirror[/*b*/r4->bmOpenParams.pidChannel]; //FREG_TSD0_SetPidConfig_2_CrcErrIrqEn
	}
	else if (/*a*/r4->bData_1 == 1)
	{
		FREG_TSD1_PidConfig_2Mirror[/*b*/r4->bmOpenParams.pidChannel] |= 2;
		r3[142] = FREG_TSD1_PidConfig_2Mirror[/*b*/r4->bmOpenParams.pidChannel]; //FREG_TSD1_PIDCONFIG_2
	}
	else
	{
		r3 = (void*) (0xc8900000 + (/*b*/r4->bmOpenParams.pidChannel * 8));
		if (/*a*/r4->bData_1 == 2)
		{
			FREG_TSD2_PidConfig_2Mirror[/*b*/r4->bmOpenParams.pidChannel] |= 2;
			r3[14] = FREG_TSD2_PidConfig_2Mirror[/*b*/r4->bmOpenParams.pidChannel]; //FREG_TSD2_PIDCONFIG_2
		}
		else
		{
			FREG_TSD3_PidConfig_2Mirror[/*b*/r4->bmOpenParams.pidChannel] |= 2;
			r3[142] = FREG_TSD3_PidConfig_2Mirror[/*b*/r4->bmOpenParams.pidChannel]; //FREG_TSD3_PIDCONFIG_2
		}
	}
	//loc_2342ca90
	tsd_SetPidConfig_2_StoreCompletePacket(r4->bData_1, r4->bmOpenParams.pidChannel, 0);

	if (0 != sub_2342ba78(r4->bData_1, r4->bmOpenParams.pidChannel & 0xff, r4->Data_4, r5))
	{
		//loc_2342cac0
		r5->bData_0 = 0; //r6

		OSSemPost(tsd_sema);

		return 1;
	}
	//loc_2342cad4
	r5->pid = r4->pid;
	r5->Data_0x24 = r4->bData_0;
	r5->Data_4 = r4->bData_1;
	r5->Data_4 |= (r4->bmOpenParams.pidChannel << 16);
	r5->Data_8.Data_0 = 0; //r6
	r5->Data_0x18 = 0; //r6
	//0x2342cafc: Set BM Read and Write Pointer
	do
	{
		volatile uint32_t* r0;
		volatile uint32_t* r1 = (void*) (0xc8300000);
		volatile uint32_t* r2 = (void*) (0xC8B00000);
		if (r4->bData_1 == 0)
		{
			r0 = r1 + r4->bmOpenParams.pidChannel;
			//->loc_2342cb38
			r0[96] = 0; //r6 //FREG_BM0_RDPTR
			//->loc_2342cb54
		}
		else if (r4->bData_1 == 1)
		{
			r0 = r1 + r4->bmOpenParams.pidChannel;
			//->loc_2342cb50
			r0[352] = 0; //r6
		}
		else
		{
			if (r4->bData_1 == 2)
			{
				r0 = r2 + r4->bmOpenParams.pidChannel;
				//loc_2342cb38
				r0[96] = 0; //r6
				//->loc_2342cb54
			}
			else if (r4->bData_1 == 3)
			{
				r0 = r2 + r4->bmOpenParams.pidChannel;
				//->loc_2342cb50
				r0[352] = 0; //r6 //FREG_BM3_RDPTR
			}
			else
			{
				//->loc_2342cba4
				break;
			}
		}
		//loc_2342cb54
		if (r4->bData_1 == 0)
		{
			r0 = r1 + r4->bmOpenParams.pidChannel;
			//->loc_2342cb88
			r0[32] = 0; //r6 //FREG_BM0_WRPTR
			//->loc_2342cba4
		}
		else if (r4->bData_1 == 1)
		{
			r0 = r1 + r4->bmOpenParams.pidChannel;
			//->loc_2342cba0
			r0[288] = 0; //r6
		}
		else
		{
			if (r4->bData_1 == 2)
			{
				r0 = r2 + r4->bmOpenParams.pidChannel;
				//->loc_2342cb88
				r0[32] = 0; //r6
				//->loc_2342cba4
			}
			else if (r4->bData_1 == 3)
			{
				r0 = r2 + r4->bmOpenParams.pidChannel;
				//->loc_2342cb50
				r0[288] = 0; //r6
			}
			else
			{
				//->loc_2342cba4
				break;
			}
		}
	}
	while (0);
	//loc_2342cba4
	r5->Data_8.bmStart = r4->bmOpenParams.bufferAddress;
	r5->Data_8.bmEnd = r4->bmOpenParams.bufferAddress + r4->bmOpenParams.bufferSize;
	r5->Data_8.bmSize = r4->bmOpenParams.bufferSize;
	r5->sectionDataNotify = r4->sectionDataNotify;

	*r8 = r5;

	OSSemPost(tsd_sema);

	return 0;
}


/* 234216fc / 2342cbdc - todo */
int sub_234216fc(TSD_Handle* r6)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	int r4 = r6->Data_4 & 0xff;
	int r5 = (r6->Data_4 >> 16) & 0xff;

#if 0
	console_send_string("sub_234216fc (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	volatile uint32_t* r1 = (void*) (0xc8300000 + r5 * 4);

	r6->Data_8.Data_0 = 0;
	r6->Data_0x18 = 0;

	if (r4 == 0)
	{
		//loc_2342cc14
		r1[96] = 0; //FREG_BM0_RDPTR
		r1[32] = 0; //FREG_BM0_WRPTR
		//->loc_2342cc50
	}
	//loc_2342cc24
	else if (r4 == 1)
	{
		//loc_2342cc2c
		r1[352] = 0; //FREG_BM1_RDPTR
		r1[288] = 0; //FREG_BM1_WRPTR
		//->loc_2342cc50
	}
	else
	{
		r1 = (void*) (0xc8b00000 + r5 * 4);

		if (r4 == 2)
		{
			//loc_2342cc14
			r1[96] = 0; //FREG_BM2_RDPTR
			r1[32] = 0; //FREG_BM2_WRPTR
		}
		else if (r4 == 3)
		{
			//loc_2342cc2c
			r1[352] = 0; //FREG_BM3_RDPTR
			r1[288] = 0; //FREG_BM3_WRPTR
			//->loc_2342cc50
		}
	}
	//loc_2342cc50
	OS_EXIT_CRITICAL();

	return 0;
}


/* 23421780 / 2342cc60 - complete */
int tsd_set_section_filter(TSD_Handle* r4, uint16_t pid, Struct_23421780* sb)
{
	uint8_t sp;
	volatile uint32_t* r5;

#if 0
	console_send_string("tsd_set_section_filter (todo.c): TODO\r\n");
#endif

	uint8_t block = r4->Data_4 & 0xff;
	uint8_t channel = (r4->Data_4 >> 16) & 0xff;

	if (block == 0)
	{
		r5 = (void*) 0xc8501000; //FREG_TSD0_SFTARGETS
	}
	else if (block == 1)
	{
		r5 = (void*) 0xc8501800;
	}
	else if (block == 2)
	{
		r5 = (void*) 0xc8d01000;
	}
	else if (block == 3)
	{
		r5 = (void*) 0xc8d01800; //FREG_TSD3_SFTARGETS
	}
	else
	{
		return 0xff;
	}
	//loc_2342ccb0
	OSSemPend(tsd_sema, 0, &sp);
	if (sp != 0)
	{
		return sp;
	}
	//0x2342ccd0
	if (r4->pid != pid)
	{
		r4->pid = pid;

		tsd_SetPidFilter(block, channel, pid);
	}
	//0x2342ccec
	char* r6_ = sb->Data_4;
	int r4_ = r4->Data_0x28 & 0xff;

	while (1)
	{
		//loc_2342cd00
		uint32_t r0, r0_;

		r0 = __rev(((struct unaligned_int*)r6_)->i);
		r5[r4_ * 2] = r0;

		r0_ = __rev(((struct unaligned_int*)(r6_ + 4))->i);
		r5[r4_ * 2 + 1] = r0_;

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "tsd_set_section_filter: r5=%p, r4_=%d, r0=0x%08x, r0_=0x%08x\r\n",
					r5, r4_, r0, r0_);
			console_send_string(debug_string);
		}
#endif

		r6_ += 8;
		r4_ = Data_236e4154[block][r4_].Data_4 & 0x7f;
		if (r4_ == 0)
		{
			break;
		}
	}
	//0x2342cd38
	OSSemPost(tsd_sema);

	return 0;
}


/* 23421868 / 2342cd48 - complete */
int tsd_set_pes_pid_filter(void* h, uint16_t pid)
{
	uint8_t err;
	Struct_235f048c* r4 = h;
	uint8_t r6 = r4->Data_4 & 0xff;
	uint8_t r8 = (r4->Data_4 >> 16) & 0xff;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "tsd_set_pes_pid_filter: pid=0x%04x\r\n", pid);
		console_send_string(debug_string);
	}
#endif

	OSSemPend(tsd_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	tsd_SetPidFilter(r6, r8, pid);

	r4->wData_0x1c = pid;

	OSSemPost(tsd_sema);

	return 0;
}


/* 234218c8 / 2342cda8 - complete */
int tsd_activate_pid_channel(TSD_Handle* a)
{
	uint8_t err;
	int r5 = a->Data_4 & 0xff;
	int r6 = (a->Data_4 >> 16) & 0xff;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "tsd_activate_pid_channel: r5=%d, r6=%d\r\n", r5, r6);
		console_send_string(debug_string);
	}
#endif

	OSSemPend(tsd_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	tsd_SetPidChannelActive(r5, r6, 3);

	OSSemPost(tsd_sema);

	return 0;
}


/* 2342191c / 2342cdfc - complete */
void* tsd_get_bm_handle(void* h)
{
	Struct_235f048c* r4 = h;
	void* bmHandle;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("tsd_get_bm_handle (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	bmHandle = r4->bmHandle;

	OS_EXIT_CRITICAL();

	return bmHandle;
}


/* 23421938 / 2342ce18 - todo */
int tsd_deactivate_pid_channel(TSD_Handle* a)
{
	uint8_t err;
	int r5 = a->Data_4 & 0xff;
	int r6 = (a->Data_4 >> 16) & 0xff;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "tsd_activate_pid_channel: r5=%d, r6=%d\r\n", r5, r6);
		console_send_string(debug_string);
	}
#endif

	OSSemPend(tsd_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	tsd_SetPidChannelActive(r5, r6, 1);

	OSSemPost(tsd_sema);

	return 0;
}


/* 234219d8 / 2342ce6c - complete */
int tsd_SetPidConfig_2_NewPcrIrqEn(void* h, int r4)
{
	uint8_t err;
	Struct_235f048c* r0 = h;
	uint8_t r6 = r0->Data_4 & 0xff;
	uint8_t r7 = (r0->Data_4 >> 16) & 0xff;

#if 0
	console_send_string("tsd_SetPidConfig_2_NewPcrIrqEn (todo.c): TODO\r\n");
#endif

	OSSemPend(tsd_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	setPidConfig_2_NewPcrIrqEn(r6, r7, r4);

	OSSemPost(tsd_sema);

	return Data_234ac8d8;
}


/* 23421a30 / 2342cf10 - todo */
int sub_23421a30(int r4, int r6)
{
	uint8_t sp_0x28;
	Struct_20401328 sp_0x1c;
	uint8_t r8;
	uint8_t sb;
	uint8_t sl;
	uint8_t fp;
	uint8_t sp_0x18;
	uint8_t sp_0x14;
	uint8_t sp_0x10;
	uint8_t sp_0xc;
	uint8_t sp8;
	uint8_t sp4;
	uint8_t sp;

#if 0
	console_send_string("sub_23421a30 (todo.c): TODO\r\n");
#endif

	OSSemPend(tsd_sema, 0, &sp_0x28);
	if (sp_0x28 != 0)
	{
		return sp_0x28;
	}

	if (r4 == 0)
	{
		if (Data_234ac8dc != r6)
		{
			//0x2342cf54
			r8 = 0x2d;
			sb = 0x2e;
			sl = 0x2f;
			fp = 0x30;
			sp_0x18 = 0x31;
			sp_0x14 = 0x32;
			sp_0x10 = 0x33;
			sp_0xc = 0x34;
			sp8 = 0x35;
			sp4 = 0x36;
			sp = 0x37;

			Data_234ac8dc = r6;
			//->loc_2342cff4
		}
		else
		{
			//loc_2342d1a4
			OSSemPost(tsd_sema);

			return r6;
		}
	}
	//loc_2342cfa4
	else if (r4 == 2)
	{
		//0x2342cfac
		r8 = 0x22;
		sb = 0x23;
		sl = 0x24;
		fp = 0x25;
		sp_0x18 = 0x26;
		sp_0x14 = 0x27;
		sp_0x10 = 0x28;
		sp_0xc = 0x29;
		sp8 = 0x2a;
		sp4 = 0x2b;
		sp = 0x2c;
		//loc_2342cff4
	}
	else
	{
		//loc_2342d1a4
		OSSemPost(tsd_sema);

		return r6;
	}
	//loc_2342cff4
	uint16_t* r4_;

	if (r6 == 0)
	{
		r4_ = &Data_2371f67c.wData_0;
	}
	else if (r6 == 1)
	{
		r4_ = &Data_2371f67c.wData_24;
	}
	else if (r6 == 2)
	{
		r4_ = &Data_2371f67c.wData_48;
	}
	else
	{
		//->loc_2342d1b8
		OSSemPost(tsd_sema);
		return -0x1000000; //TOOD
	}
	//loc_2342d01c
	gpio_close(Data_2371f6c4.Data_0);
	gpio_close(Data_2371f6c4.Data_4);
	gpio_close(Data_2371f6c4.Data_8);
	gpio_close(Data_2371f6c4.Data_0xc);
	gpio_close(Data_2371f6c4.Data_0x10);
	gpio_close(Data_2371f6c4.Data_0x14);
	gpio_close(Data_2371f6c4.Data_0x18);
	gpio_close(Data_2371f6c4.Data_0x1c);
	gpio_close(Data_2371f6c4.Data_0x20);
	gpio_close(Data_2371f6c4.Data_0x24);
	gpio_close(Data_2371f6c4.Data_0x28);

	sp_0x1c.dwOutFunction = 0xff;

	sp_0x1c.dwInFunction = r8;
	sp_0x1c.bPin = r4_[0];
	gpio_open(&sp_0x1c, &Data_2371f6c4.Data_0);

	sp_0x1c.dwInFunction = sb;
	sp_0x1c.bPin = r4_[1];
	gpio_open(&sp_0x1c, &Data_2371f6c4.Data_4);

	sp_0x1c.dwInFunction = sl;
	sp_0x1c.bPin = r4_[2];
	gpio_open(&sp_0x1c, &Data_2371f6c4.Data_8);

	sp_0x1c.dwInFunction = fp;
	sp_0x1c.bPin = r4_[3];
	gpio_open(&sp_0x1c, &Data_2371f6c4.Data_0xc);

	sp_0x1c.dwInFunction = sp_0x18;
	sp_0x1c.bPin = r4_[4];
	gpio_open(&sp_0x1c, &Data_2371f6c4.Data_0x10);

	sp_0x1c.dwInFunction = sp_0x14;
	sp_0x1c.bPin = r4_[5];
	gpio_open(&sp_0x1c, &Data_2371f6c4.Data_0x14);

	sp_0x1c.dwInFunction = sp_0x10;
	sp_0x1c.bPin = r4_[6];
	gpio_open(&sp_0x1c, &Data_2371f6c4.Data_0x18);

	sp_0x1c.dwInFunction = sp_0xc;
	sp_0x1c.bPin = r4_[7];
	gpio_open(&sp_0x1c, &Data_2371f6c4.Data_0x1c);

	sp_0x1c.dwInFunction = sp8;
	sp_0x1c.bPin = r4_[8];
	gpio_open(&sp_0x1c, &Data_2371f6c4.Data_0x20);

	sp_0x1c.dwInFunction = sp4;
	sp_0x1c.bPin = r4_[9];
	gpio_open(&sp_0x1c, &Data_2371f6c4.Data_0x24);

	sp_0x1c.dwInFunction = sp;
	sp_0x1c.bPin = r4_[10];
	gpio_open(&sp_0x1c, &Data_2371f6c4.Data_0x28);
	//loc_2342d1a4
	OSSemPost(tsd_sema);

	return r6;
}


/* 23421ce8 / 2342d1c8 - complete */
int sub_23421ce8(TSD_Handle* r0, Struct_236e5834* r6)
{
	uint32_t r5 = 0;
	TSD_BM_Buffer* r7 = &r0->Data_8;
	uint32_t r4 = r6->Data_0xc;

#if 0
	console_send_string("sub_23421ce8 (todo.c): TODO\r\n");
#endif

	uint32_t global_offset = sub_23429994(r0->Data_4 & 0xffff);

	uint32_t endAddr = global_offset + r7->bmEnd;
	uint32_t startAddr = global_offset + r7->bmStart;
	uint32_t r0_ = startAddr + r6->Data_8;
	uint32_t r3 = r0_ + r4;
	if (r3 > endAddr)
	{
		r3 = r4;
		r4 = endAddr - r0_;
		r5 = r3 - r4;
	}

	if ((r4 + r5) < 0x1700)
	{
		tsd_copy_section_data((void*) r0_, r4 & 0xffff, (void*) startAddr, r5 & 0xffff, (void*) &r6->Data_0x10);
	}

	return r6->Data_0xc + r5;
}


/* 23421dfc / 2342d2dc - complete */
int tsd_get_write_pointer(TSD_Handle* r4)
{
#if 0
	console_send_string("tsd_get_write_pointer (todo.c): TODO\r\n");
#endif

	uint8_t sp;
	int r4_;

	OSSemPend(tsd_sema, 0, &sp);
	if (sp != 0)
	{
		return sp;
	}

	r4_ = tsd_get_bm_write_pointer(&r4->Data_8, r4->Data_4, &r4->Data_0x18);

	OSSemPost(tsd_sema);

	return r4_;
}


/* 23421d5c / 2342d23c - todo */
uint32_t tsd_get_pts(void* a)
{
	uint64_t r1;
	Struct_235f048c* r4 = a;

#if 0
	console_send_string("tsd_get_pts (todo.c): TODO\r\n");
#endif

	uint16_t r0 = r4->Data_4;

	if (r4 == 0)
	{
		return 0;
	}

	if (r0 == 0)
	{
		r1 = (uint64_t) sub_2342292c(r4->bData_0x28 & 0x0f);
		r1 = r1 << 16;
		r1 = r1 << 16;
		r1 = r1 | FREG(0xc8000140 + (r4->bData_0x28 & 0x0f) * 12)[0]; //TSD01_PTS_0;
	}
	else
	{
		//loc_23421db0
		r1 = (uint64_t) sub_23422944(r4->bData_0x28 & 0x0f);
		r1 = r1 << 16;
		r1 = r1 << 16;
		r1 = r1 | FREG(0xc8800140 + (r4->bData_0x28 & 0x0f) * 12)[0]; //TSD23_PTS_0;
	}

	r1 *= 300; //TSD_EXTENSION_RESOLUTION

	return r1 / 2;
}


/* 23422268 - todo */
int sub_23422268(void* a)
{
	Struct_235f048c* h = a;

#if 0
	console_send_string("sub_23422268 (todo.c): TODO\r\n");
#endif

	int r0 = h->Data_4 & 0xffff;
	int r1 = h->Data_4 >> 16;

	if (r0 == 0)
	{
		return FREG(0xc8300080 + r1 * 4)[0]; //BM0_WR_PTR
	}
	//loc_2342228c
	else if (r0 == 1)
	{
		return FREG(0xc8300480 + r1 * 4)[0];
	}
	else if (r0 == 2)
	{
		return FREG(0xc8b00080 + r1 * 4)[0];
	}
	else if (r0 == 3)
	{
		return FREG(0xc8b00480 + r1 * 4)[0];
	}
	else
	{
		return 0;
	}
}


/* 23422460 / 2342d940 - todo */
void sub_23422460()
{
	uint32_t i;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_23422460 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	for (i = 0; i < 40; i++)
	{
		Data_236e5834[i].Data_0xc = 0;
		Data_236e5834[i].msg_id = 3;
	}

	OS_EXIT_CRITICAL();
}


/* 234224a0 / 2342d980 - complete */
void sub_234224a0(uint32_t a)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_234224a0 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	sub_2342a788(a);

	OS_EXIT_CRITICAL();
}


/* 234225c4 / 2342daa4 - complete */
void sub_234225c4(void* a, int r5)
{
	Struct_235f048c* r4 = a;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_234225c4 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	r4->Data_0x14 = r5;

	sub_2341e0f8(r4->bmHandle, r5);

	OS_EXIT_CRITICAL();
}


/* 234225f4 / x - todo */
uint32_t sub_234225f4()
{
#if 0
	console_send_string("sub_234225f4 (todo.c): TODO\r\n");
#endif

	return Data_234ac8dc;
}


/* 234228d4 / 2342dcc4 - complete */
int tsd_start_aud_filtering(void* a)
{
	Struct_235f048c* r4 = a;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("tsd_start_aud_filtering (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	bm_StartAudFiltering(r4->bmHandle);

	OS_EXIT_CRITICAL();

	return 0;
}

#if 0
/* 2342292c / 2342dd1c - todo */
uint32_t sub_2342292c(int a)
{
	return FREG(0xc8000144 + a * 12)[0] & 1; //TSD01_PTS_1:PTS_MSB
}


/* 23422944 / 2342dd34 - todo */
uint32_t sub_23422944(int a)
{
	return FREG(0xc8800144 + a * 12)[0] & 1; //TSD23_PTS_1:PTS_MSB
}
#endif

/* 2342295c / 2342dd4c - todo */
void sub_2342dd4c(int a, int b)
{
	Data_236e0b14[a] = b;
	FREG(0xc8300220)[a] = b; //FREG_BM01_BUFLOWLEV
}


/* 23422974 / 2342dd64 - complete */
void sub_2342dd64(int a, int b)
{
	Data_236e0b34[a] = b;
	FREG(0xc83002e0)[a] = b; //FREG_BM01_AUDVALUE
}


/* 234229dc / 2342ddcc - complete */
void sub_2342ddcc(int a)
{
	a = (a << 18) & (1 << 18);

	FREG(0xca000074)[0] =  //FREG_CLKPWR_CONFIGDMACAUDIO
			(FREG(0xca000074)[0] & ~(1 << 18)) | a;
}


/* 2342dea8 - complete */
int sub_2342dea8(int a, Struct_2342c4f8_Inner8* b)
{
#if 0
	console_send_string("sub_2342dea8 (todo.c): TODO\r\n");
#endif

	int r2 = 0;
	int r1 = b->Data_4;

	if (r1 & 1)
	{
		r2 |= 0x20;
	}

	if (r1 & 2)
	{
		r2 |= 0x10;
	}

	if (r1 & 4)
	{
		r2 |= 0x08;
	}

	if (r1 & 8)
	{
		r2 |= 0x04;
	}

	if (r1 & 0x30)
	{
		r2 |= ((r1 >> 4) & 0x03);
	}

	if ((a == 1) || (a == 3))
	{
		r2 = r2 << 8;
	}

	r1 = ((a == 0) || (a == 1))?
			FREG(0xc8000100)[0]: //FREG_TSD01_INPUTCTRL
			FREG(0xC8800100)[0]; //FREG_TSD23_INPUTCTRL

	r1 = ((a == 1) || (a == 3))? r1 & 0xff: r1 & 0xff00;
	r1 |= r2;

	if ((a == 0) || (a == 1))
	{
		FREG(0xc8000100)[0] = r1; //FREG_TSD01_INPUTCTRL
	}
	else
	{
		FREG(0xC8800100)[0] = r1; //FREG_TSD23_INPUTCTRL
	}

	return 0;
}


/* 2342df2c - todo */
int sub_2342df2c(int ip, int r1, volatile uint32_t* c)
{
	uint8_t i;

#if 0
	console_send_string("sub_2342df2c (todo.c): TODO\r\n");
#endif

	for (i = 0; i < 128; i++)
	{
		//loc_2342df40
		if (Data_236e4154[ip][i].bData_0 == 0)
		{
			if (r1 != 0xff)
			{
				struct Struct_236e4154* ip_ = &Data_236e4154[ip][r1];
				ip_->Data_4 &= ~0xff;
				ip_->Data_4 |= (i & 0x7f);

				c[r1] = ip_->Data_4;
			}
			//loc_2342df74
			Data_236e4154[ip][i].bData_0 = 1;
			return i;
		}
		//loc_2342df80
	}

	return -1;
}


