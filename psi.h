
#ifndef PSI_H
#define PSI_H

#define PSI_MASK_PAT       0x01
#define PSI_MASK_PMT       0x02
#define PSI_MASK_CAT       0x04
#define PSI_MASK_TDT       0x10
#define PSI_MASK_EIT       0x20
#define PSI_MASK_NIT       0x40

#define PSI_STATE_START    1
#define PSI_STATE_STOP     2

typedef struct
{
	uint16_t wData_0; //0
	int fill_4[2]; //4
	int PAT_bufferAddress; //0xc = 12
	int PAT_bufferSize; //0x10 = 16
	int PMT_bufferAddress; //0x14 = 20
	int PMT_bufferSize; //0x18 = 24
	int Data_0x1c; //0x1c = 28
	int Data_0x20; //0x20 = 32
	int Data_0x24; //0x24
	int Data_0x28; //0x28
	int EIT_bufferAddress; //0x2c
	int EIT_bufferSize; //0x30
	int NIT_bufferAddress; //0x34
	int NIT_bufferSize; //0x38
	int SDT_BAT_bufferAddress; //0x3c = 60
	int SDT_BAT_bufferSize; //0x40 = 64
	int TDT_bufferAddress; //0x44 = 68
	int TDT_bufferSize; //0x48 = 72
	int Data_0x4c; //0x4c
	int Data_0x50; //0x50
	int Data_0x54; //0x54
	int Data_0x58; //0x58
	int Data_0x5c; //0x5c
	int Data_0x60; //0x60
	int Data_0x64; //0x64
	int Data_0x68; //0x68
	int Data_0x6c; //0x6c
	int Data_0x70; //0x70
	//0x74???
} PSI_BufferParams;


struct Struct_234a73e8;
typedef struct
{
	uint16_t threadPrio; //0
	void (*onNewPSIDecoder)(struct Struct_234a73e8*); //4
	PSI_BufferParams bufferParams; //8
	void (*Data_0x7c)(); //124 = 0x7c
	void (*Data_0x80)(); //0x80
	void (*Data_0x84)(); //0x84
	void (*Data_0x88)(); //124 = 0x88
	void (*Data_0x8c)(); //124 = 0x8c
	//0x90
} PSI_Params;


typedef struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	int fill_4[5]; //4
	/*TSD_Handle*/void* tsdPAT; //24 = 0x18
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1

	} Data_0x1c; //0x1c;
	int fill_0x20[5]; //0x20 = 32
	/*TSD_Handle*/void* tsdCAT; //52 = 0x34
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2
		uint8_t bData_3; //3
		uint8_t bData_4; //4
		uint8_t bData_5; //5
		uint8_t bData_6; //6
		uint8_t bData_7; //7

	} Data_0x38; //0x38
	int fill_0x40[4]; //0x40
	/*TSD_Handle*/void* tsdPMT; //80 = 0x50
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2
		uint8_t bData_3; //3
		uint8_t bData_4; //4
		uint8_t bData_5; //5
		uint8_t bData_6; //6
		uint8_t bData_7; //7
		uint8_t bData_8; //8
		uint8_t bData_9; //9

	} Data_0x54; //0x54
	int fill_0x60[3]; //0x60
	/*TSD_Handle*/void* tsdSDT_BAT; //108 = 0x6c
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2
		uint8_t bData_3; //3
		uint8_t bData_4; //4
		uint8_t bData_5; //5
		uint8_t bData_6; //6
		uint8_t bData_7; //7
		uint8_t bData_8; //8
		uint8_t bData_9; //9
		uint8_t bData_10; //10
		uint8_t bData_11; //11
		uint8_t bData_12; //12
		uint8_t bData_13; //13
		uint8_t bData_14; //14
		uint8_t bData_15; //15
		uint8_t bData_16; //16

	} Data_0x70; //0x70
	int fill_0x84; //0x84
	/*TSD_Handle*/void* Data_0x88; //136 = 0x88
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2
		uint8_t bData_3; //3
		uint8_t bData_4; //4
		uint8_t bData_5; //5
		uint8_t bData_6; //6
		uint8_t bData_7; //7

	} NIT_Bytes; //0x8c
	int fill_0x94[4]; //0x94
	struct TSD_Handle* tsdNIT; //164 = 0xa4
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1

	} Data_0xa8; //0xa8
	int fill_0xac[5]; //0xac
	/*TSD_Handle*/void* tsdTDT; //192 = 0xc0
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2
		uint8_t bData_3; //3
		uint8_t bData_4; //4
		uint8_t bData_5; //5
		uint8_t bData_6; //6
		uint8_t bData_7; //7
		uint8_t bData_8; //8
		uint8_t bData_9; //9
		uint8_t bData_10; //10
		uint8_t bData_11; //11

	} Data_0xc4; //0xc4
	int fill_0xd0[3]; //0xd0
	/*TSD_Handle*/void* tsdEIT; //220 = 0xdc
	int fill_0xe0[6]; //0xe0
	void* Data_0xf8; //0xf8
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1

	} Data_0xfc; //0xfc
	int fill_0x100[5]; //0x100
	/*TSD_Handle*/void* Data_0x114; //276 = 0x114
	int fill_0x118[7]; //0x118
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1

	} Data_0x134; //0x134
	int fill_0x138[5]; //0x138
	/*TSD_Handle*/void* Data_0x14c; //332 = 0x14c
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1

	} Data_0x150; //0x150
	int fill_0x154[5]; //0x154
	/*TSD_Handle*/void* Data_0x168; //360 = 0x168
	//0x16c
} Struct_234a73e8_Inner8;

typedef struct Struct_234a73e8_Inner_0x248
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	uint16_t pat_program_number; //2
	uint16_t pmt_pid; //4
	uint16_t arAudioPids[50]; //6
	uint16_t arAudioComponentTags[50]; //0x6A
	char* arAudioLanguageStrings[50]; //0xd0
	int Data_0x198[50]; //0x198
	char* arAudioLanguage2Strings[50]; //0x260
	uint8_t* service_name; //0x328
	int transport_stream_id; //0x32c
	int original_network_id; //0x330
	uint16_t wPcrPID; //0x334
	uint16_t wVideoPID; //0x336
	uint16_t wData_0x338; //0x338
	uint16_t wTtxPID; //0x33a
	uint16_t wAudioPID; //0x33c
	struct
	{
		uint16_t wData_0; //0
		int Data_4[4]; //4
		//20
	} Data_0x340[4]; //0x340
	int Data_0x390; //0x390
	uint8_t bData_0x394; //0x394
	//0x398 = 920
} PSI_Program;

typedef struct Struct_234a73e8
{
	uint32_t index; //0
	PSI_Params* Data_4; //4
	Struct_234a73e8_Inner8 Data_8; //8
	OS_EVENT* sema; //0x174
	OS_EVENT* queue; //0x178
	void* Data_0x17c; //0x17c
	int fill_0x180[39]; //0x180
	void (*pfHandleQueueItem)(); //0x21c
	void (*pfHandleState)(); //0x220
	void (*pfOnPSIData)(); //0x224
	void (*Data_0x228)(); //0x228
	void (*Data_0x22c)(); //0x22c
	void (*pfOnPMTData)(uint8_t*, int); //0x230
	void (*pfOnSDTData)(uint8_t*, int); //0x234
	void (*Data_0x238)(); //0x238
	void (*Data_0x23c)(); //0x23c
	Struct_236e5834* Data_0x240; //0x240
	uint8_t bData_0x244; //0x244
	PSI_Program programs[150]; //0x248
	int Data_0x21d58[40]; //0x21d58
	int activeMask; //0x21df8
	int Data_0x21dfc; //0x21dfc
#if 1
	int Data_0x21e00; //0x21e00
	int Data_0x21e04; //0x21e04
	int Data_0x21e08; //0x21e08
	Struct_235b1c24* hTimer; //0x21e0c
	uint16_t wData_0x21e10; //0x21e10
	uint16_t wData_0x21e12; //0x21e12
	uint16_t wData_0x21e14; //0x21e14
	uint16_t wPMT_PID; //0x21e16
	uint16_t wData_0x21e18; //0x21e18
	uint16_t wData_0x21e1a; //0x21e1a
	uint16_t wData_0x21e1c; //0x21e1c
	uint16_t wData_0x21e1e; //0x21e1e
	struct Struct_234a73e8_Inner0x21e00
	{
		int Data_0; //0x21e00
		int Data_4; //0x21e04
		int Data_8; //0x21e08
		Struct_235b1c24* Data_0x0c; //0x21e0c
		uint16_t wData_0x10; //0x21e10
		uint16_t wData_0x12; //0x21e12
		uint16_t wData_0x14; //0x21e14
		uint16_t wData_0x16; //0x21e16
		uint16_t wData_0x18; //0x21e18
		uint16_t wData_0x1a; //0x21e1a
		uint16_t wData_0x1c; //0x21e1c
		uint16_t wData_0x1e; //0x21e1e
		//??
	};
#else
	} Data_0x21e00; //0x21e00
#endif
	uint16_t wSDT_BAT_Timeout; //0x21e20
	uint16_t wNIT_Timeout; //0x21e22
	uint16_t wData_0x21e24; //0x21e24
	uint16_t wData_0x21e26; //0x21e26
	int Data_0x21e28; //0x21e28
	int fill_0x21e2c[5]; //0x21e2c
	struct
	{
		int fill_0[4]; //0
		//16
	} Data_0x21e40[2]; //0x21e40
	uint16_t fill_0x21e60; //0x21e60
	struct
	{
		uint8_t bData_0; //0
		uint8_t fill_1; //1
		uint8_t fill_2; //2
		uint8_t fill_3; //3
		//4
	} Data_0x21e62[2]; //0x21e62
	struct
	{
		uint8_t bData_0; //0
		uint8_t fill_1; //1
		uint8_t bData_2; //2
		uint8_t bData_3; //3
		//4
	} Data_0x21e6a[2]; //0x21e6a
	//uint8_t bData_0x21e70; //0x21e70
	//uint8_t bData_0x21e71; //0x21e71
	uint8_t bPMT_State; //0x21e72
	uint8_t bData_0x21e73; //0x21e73
	uint8_t bSDT_BAT_State; //0x21e74
	uint8_t bData_0x21e75; //0x21e75
	uint8_t bData_0x21e76; //0x21e76
	uint8_t bNIT_State; //0x21e77
	uint8_t bData_0x21e78; //0x21e78
	uint8_t bData_0x21e79; //0x21e79
	uint8_t bEIT_State; //0x21e7a
	uint8_t fill_0x21e7b; //0x21e7b
	uint8_t bData_0x21e7c; //0x21e7c
	uint8_t bPAT_VersionNumber; //0x21e7d
	uint8_t bPMT_VersionNumber; //0x21e7e
	uint8_t bSDT_VersionNumber; //0x21e7f
	uint8_t bNIT_VersionNumber; //0x21e80
	uint8_t bData_0x21e81; //0x21e81
	uint8_t bData_0x21e82; //0x21e82
	uint8_t bData_0x21e83; //0x21e83
	uint8_t bData_0x21e84; //0x21e84
	uint8_t bData_0x21e85; //0x21e85
	uint8_t bNIT_SectionNumberBits; //0x21e86
	uint8_t bNIT_SectionNumberMask; //0x21e87
	uint8_t bData_0x21e88; //0x21e88
	uint8_t bData_0x21e89; //0x21e89
	uint8_t bData_0x21e8a; //0x21e8a
	uint8_t bData_0x21e8b; //0x21e8b
	uint8_t bData_0x21e8c; //0x21e8c
	uint8_t bData_0x21e8d; //0x21e8d
	uint8_t bData_0x21e8e; //0x21e8e
	//0x21E90
} Struct_234a73e8;

#endif //PSI_H
