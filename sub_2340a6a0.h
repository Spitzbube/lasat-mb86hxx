
#ifndef SUB_2340a6a0
#define SUB_2340a6a0

typedef struct
{
	uint16_t fill_0; //0 235441b0
	uint16_t wData_2; //2
	uint32_t Data_4; //4
	uint8_t bData_8; //8 235441b8 //initialVolume
	uint16_t fill_0x0a; //10
	uint8_t fill_0x0c; //12 235441bc
	uint8_t menuLanguage; //13 = 0x0d
	/*
		Bit 6: Deep standby
		Bit 7: Channel list update
		Bit 15: Auto standby
	 */
	uint32_t Data_0x10; //16 235441c0
	uint8_t fill_0x14; //20 = 0x14
	uint8_t bData_0x15; //21 = 0x15
	uint8_t bData_0x16; //22 = 0x16
	uint8_t bData_0x17; //23 = 0x17 //displayFormat
	int fill_0x18; //24 235441c8
	//28 = 0x1c
} Struct_235441b0;


typedef struct
{
	union
	{

		uint32_t Data_0;
		struct
		{
	//		uint32_t Data_0_27: 28;
			uint32_t Data_0_18: 19;
			uint8_t Data_19: 1; //bData_2 & 0xf7
			uint32_t Data_20_27: 8; //
			uint8_t Data_28_31: 4; //bData_3 & 0xf0
		} Bitfield_0;
	} Data_0; //0
	uint32_t Data_4; //4
	uint16_t wData_8; //8
	uint16_t wData_0x0a; //10 = 0x0a
	uint16_t wData_0x0c; //12 = 0x0c
	uint16_t wData_0x0e; //14 = 0x0e
	//16
} Struct_23491e28_Inner0;


typedef struct
{
#if 0
	union
	{

		uint32_t Data_0;
		struct
		{
			uint32_t Data_0_27: 28;
			uint8_t Data_28_31: 4;
		} Bitfield_0;
	} Data_0; //0
	uint32_t Data_4; //4
	uint16_t fill_8; //8
	uint16_t wData_0x0a; //0x0a
	int fill_0x0c; //0x0c
#else
	Struct_23491e28_Inner0 Data_0; //0
#endif
	uint16_t transport_stream_id; //0x10 = 16
	uint16_t wData_0x12; //0x12 = 18
	uint16_t wData_0x14; //0x14 = 20
	uint8_t bData_0x16; //0x16
	//0x18 = 24
} Struct_235fdfac;


typedef struct
{
	Struct_235fdfac Data_0; //0
	uint16_t wData_0x18; //0x18 = 24
	uint16_t wData_0x1a; //0x1a
	uint32_t crc; //0x1c
	//0x20
} Struct_2354613c;


typedef struct
{
	struct Struct_234fd8f0_Inner0
	{
		struct Struct_234fd8f0_Inner0_Inner_0
		{
			uint16_t service_id; //0
			uint16_t wData_2; //2
			uint16_t wData_4; //4
			uint16_t wData_6; //6
//			int Data_8; //8
			uint16_t wPcrPID; //8
			uint16_t wVideoPID; //10
			uint16_t wData_12; //12
			uint16_t wTtxPID; //14
			//16 = 0x10
		} Data_0; //0
		struct Struct_234fd8f0_Inner0_Inner_0x10
		{
			uint16_t wAudioPID; //0
			uint16_t fill_2; //2
			uint8_t service_name[20]; //4
			//0x18 = 24
		} Data_0x10; //0x10
		//40 = 0x28
	} Data_234fd8f0[6000]; //234fd8f0 +0x3a980 -> 23538270
	Struct_235fdfac Data_23538270[2000]; //23538270 +0xbb80 -> 23543DF0
	struct
	{
		int fill_0[240]; //0
		//0x3c0
	} Data_23543df0; //23543df0 -> 235441B0
#if 0
	struct
	{
		int fill_235441b0[2]; //235441b0 0
		uint8_t bData_235441b8; //235441b8 8
		int fill_235441bc; //235441bc 12
		uint32_t Data_235441c0; //235441c0 16
		int fill_235441c4[2]; //235441c4 20
		//28 = 0x1c
	}
#else
	Struct_235441b0 Data_235441b0; //235441b0
#endif
	int Data_235441cc; //235441cc 468DC
	int Data_235441d0; //235441d0 468E0
	int Data_235441d4; //235441d4 468E4
	struct
	{
		int fill_0[500]; //235441d8
		//0x7D0 size???
	} Data_235441d8;
	struct
	{
		uint16_t wData_235449a8[8]; //235449a8 470B8
		int fill_235449b8[496]; //235449b8
		//0x7D0 size???
	} Data_235449a8; //235449a8 470B8
	struct
	{
		int fill_0[500]; //0
		//0x7D0 size???
	} Data_23545178; //23545178
	struct
	{
		int fill_0[500]; //0
		//0x7D0 size???
	} Data_23545948; //23545948
	int Data_23546118; //23546118
	uint32_t Data_2354611c; //2354611c
	uint32_t Data_23546120; //23546120
	uint32_t Data_23546124; //23546124
	struct Struct_23546128
	{
		int Data_0; //0
		int Data_4; //4
		int Data_8; //8
		//12
	} Data_23546128; //23546128
	int fill_23546134[2]; //23546134
	Struct_2354613c Data_2354613c; //2354613c +0x20 = 2354615C
	int Data_2354615c; //2354615C
	struct Struct_2340d1f4_Inner_4
	{
		int fill_0[5]; //0
		//0x14 = 20
	} Data_23546160[9]; //23546160, 48870
	struct Struct_2340d1f4_Inner_0xb8
	{
		int fill_0[4]; //0
		uint8_t bData_16; //16 = 0x10
		//0x14 = 20
	} Data_23546214[9]; //23546214, 48924
	uint8_t bData_235462c8; //235462C8, 489D8
	uint8_t bData_235462c9; //235462C9, 489D9
	uint8_t bData_235462ca; //235462ca, 489DA
	uint8_t bData_235462cb; //235462cb, 489DB
	struct Struct_234fd8f0_Inner_489DC
	{
		int Data_0; //0
		uint32_t Data_4; //4
		int Data_8; //8
		uint16_t wData_12; //12
		int Data_16; //16
		//20 = 0x14
	} Data_235462cc; //235462cc, 489DC
	int Data_235462e0; //235462E0, 489F0
	//0x489f4???? -> 235462E4
} Struct_234fd8f0;


typedef struct
{
	struct Struct_234fd8f0_Inner0 Data_0; //0
	uint16_t wData_0x28; //0x28 = 40
	uint16_t wData_0x2a; //0x2a = 42
	uint16_t wData_0x2c; //0x2c
	uint16_t fill_0x2e; //0x2e
	uint8_t bData_0x30; //0x30
	uint8_t bData_0x31; //0x31
	//0x32 = 50
} Struct_2340bf0c;



extern int sub_2340c970(int get, Struct_235441b0*);
extern void sub_2340bf0c(Struct_2340bf0c*);
extern void sub_23409770(void);
extern void sub_23409788(void);
 
#endif //SUB_2340a6a0
