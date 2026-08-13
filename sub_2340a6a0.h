
#ifndef SUB_2340a6a0
#define SUB_2340a6a0

#define CHANNELS_MAX_NUM 6000
#define TRANSPONDERS_MAX_NUM 2000

typedef struct
{
	uint16_t fill_0; //0 235441b0
	uint16_t wPictureScaling; //2
	union
	{
	/*
		Bit 1: Video signal digital: 0 = YCbCr, 1 = RGB
		Bit 23:2: Channel list sorting (automatic / manual)
	*/
		uint32_t dwData; //4
		struct
		{
			uint32_t fill_bit0: 1; //bit 0
			uint32_t digital_video_signal: 1; //bit 1
			uint32_t fill_bit2: 6; //bit 2
			uint32_t bit8: 5; //bit 8
			uint32_t fill_bit13: 10; //bit 13
			uint32_t bit23: 2; //bit23
			uint32_t fill_bit25: 2; //bit25
			uint32_t video_system: 4; //bit27
		} bitData;
	} Data_4; //4
	uint8_t initialVolume; //8 235441b8
	uint16_t timeDiff; //10
	uint8_t fill_0x0c; //12 235441bc
	uint8_t menuLanguage; //13 = 0x0d
	uint8_t bData_0xe; //14 = 0x0e
	/*
		Bit 0...3: Channel banner dialog hold time?
		Bit 4...5: Pin necessary?
		Bit 6: Deep standby
		Bit 7: Channel list update
		Bit 8...10: ? //(x << 21) >> 29
		Bit 11: Timer storage
		Bit 15: Auto standby
	 */
	uint32_t Data_0x10; //16 235441c0
	uint8_t fill_0x14; //20 = 0x14
	uint8_t bDisplayAdjustment; //21 = 0x15 // 0 = Letterbox, 
	uint8_t bVideoSignalAnalog; //22 = 0x16
	uint8_t displayFormat; //23 = 0x17 // 0 = 4:3, 1 = 16:9
	uint8_t fill_0x18; //24 235441c8
	uint8_t bData_0x19; //25 = 0x19
	//28 = 0x1c
} User_Settings;


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
			uint8_t modulation: 4; //bData_3 & 0xf0
		} Bitfield_0;
	} Data_0; //0
	uint32_t frequency; //4
	uint16_t symbol_rate; //8
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
			uint8_t modulation: 4;
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
	uint16_t original_network_id; //0x12 = 18
	uint16_t wData_0x14; //0x14 = 20
	uint8_t bData_0x16; //0x16
	//0x18 = 24
} Transponder;


typedef struct
{
	Transponder transponder; //0
	uint16_t wData_0x18; //0x18 = 24
	uint16_t wData_0x1a; //0x1a
	uint32_t crc; //0x1c
	//0x20
} Struct_2354613c;

typedef struct
{
	uint16_t service_id; //0
	/*
		Bit 3: TV=1 / Radio=0
	*/
	uint16_t wFlags_2; //2
	uint16_t wTransponderIndex; //4
	uint16_t wData_6; //6
	uint16_t wPcrPID; //8
	uint16_t wVideoPID; //10 = 0x0a
	uint16_t wAc3PID; //12 = 0x0c
	uint16_t wTtxPID; //14 ? = 0x0e
	uint16_t wAudioPID; //16 = 0x10
	uint16_t fill_2; //18
	uint8_t service_name[20]; //20
	//40 = 0x28
} Channel;

typedef struct
{
	int fill_0[2]; //0
	char Data_8[24]; //8, size?
	//0x20 = 32
} Struct_23543df0;


typedef struct Struct_234fd8f0_Inner_489DC
{
	int Data_0; //0
	uint32_t Data_4; //4
	int Data_8; //8
	uint16_t wData_12; //12
	int Data_16; //16
	//20 = 0x14
} Struct_234fd8f0_Inner_489DC;


typedef struct
{
	uint8_t strName[12]; //0
	uint8_t bBass; //0xc
	uint8_t fill_0xd; //0xd
	uint8_t bTreble; //0xe
	uint8_t bData_0xf; //0xf
	uint8_t bData_0x10; //0x10
	uint8_t bData_0x11; //0x11
	uint16_t fill_0x12; //0x12
	//0x14 = 20
} Equalizer_Settings;

typedef struct
{
	uint8_t strName[16]; //0
	uint8_t bData_16; //16 = 0x10
	uint8_t bData_0x11; //17 
	uint8_t bData_0x12; //0x12
	uint8_t fill_0x13; //19
	//0x14 = 20
} Amplifier_Inputs;


typedef struct
{
	Channel arChannels[CHANNELS_MAX_NUM]; //0 234fd8f0 +0x3a980 -> 23538270
	Transponder arTransponders[TRANSPONDERS_MAX_NUM]; //23538270 +0xbb80 -> 23543DF0
	Struct_23543df0 Data_23543df0[30]; //23543df0 -> 235441B0
	User_Settings Data_235441b0; //235441b0
	uint32_t dwCrcChannels; //235441cc 468DC
	uint32_t dwCrcTransponders; //235441d0 468E0
	uint32_t Data_235441d4; //235441d4 468E4
#if 0
	struct
	{
		uint16_t wData_0[1000]; //235441d8
		//0x7D0 size???
	} Data_235441d8; //235441d8 +0x7d0 = 235449A8
	struct
	{
		uint16_t arChannel[8]; //235449a8 470B8
		int fill_235449b8[496]; //235449b8
		//0x7D0 size???
	} favourites; //235449a8 470B8
	struct
	{
		int fill_0[500]; //0
		//0x7D0 size???
	} Data_23545178; //23545178
	struct
	{
		int fill_0[500]; //0
		//0x7D0 size???
	} Data_23545948; //23545948 +0x7d0 = 23546118
#else
	struct
	{
		uint16_t arChannel[1000]; //235441d8
		//0x7D0 size???
	} Data_235441d8[4]; //235441d8 +4*0x7d0 = 23546118
#endif
	uint32_t Data_23546118[4]; //23546118
	struct Struct_23546128
	{
		int Data_0; //0
		int Data_4; //4
		int Data_8; //8
		//12
	} Data_23546128; //23546128 / / 235b4eec
	int fill_23546134[2]; //23546134
	Struct_2354613c Data_2354613c; //2354613c +0x20 = 2354615C
	int Data_2354615c; //2354615C
	Equalizer_Settings arEqualizerSettings[9]; //23546160, 48870
	Amplifier_Inputs arAmplifierInputs[9]; //23546214, 48924
	uint8_t bData_235462c8; //235462C8, 489D8
	uint8_t bData_235462c9; //235462C9, 489D9
	uint8_t bData_235462ca; //235462ca, 489DA
	uint8_t bData_235462cb; //235462cb, 489DB
	Struct_234fd8f0_Inner_489DC Data_235462cc; //235462cc, 489DC
	int Data_235462e0; //235462E0, 489F0
	//0x489f4???? -> 235462E4
} Channel_Database;

typedef struct
{
	int Data_0; //0
	Equalizer_Settings arEqualizerSettings[9]; //4
	Amplifier_Inputs arInputs[9]; //0xb8
	uint8_t bData_16c; //0x16c
	uint8_t bData_16d; //0x16d
	uint8_t bData_16e; //0x16e
	uint8_t bData_16f; //0x16f
	//0x170
} Amplifier_Settings;


typedef struct
{
	Channel Data_0; //0
	uint16_t wNumChannels; //0x28 = 40
	uint16_t wCurrentChannel; //0x2a = 42
	uint16_t wData_0x2c; //0x2c
	uint16_t fill_0x2e; //0x2e
	uint8_t bCurrentChList; //0x30
	uint8_t bData_0x31; //0x31
	//0x32 = 50
} Struct_2340bf0c;


typedef struct
{
	void (*Data_0)(); //0 235462E4
	int currentChannel; //4 235462E8
	int prevChannel; //8 235462EC
	uint16_t arChannelIdx[CHANNELS_MAX_NUM]; //12 = 0xc, 235462F0, size????
	uint16_t numChannels; //0xEEC 235491d0
	uint16_t wData_235491d2; //0xEEE 235491d2
	uint16_t currentTvChannel; //235491D4 +0xf0
	uint16_t currentRadioChannel; //235491d6 + 0xf2
	uint16_t wAudioPID; //235491d8
	uint16_t wVideoPID; //235491da
	uint8_t bData_235491dc; //0xef8 235491dc
	uint8_t currentChList; //0xEF9 235491dd
	uint8_t activeStreamMask; //235491de 235482e4 + 0xefa
	uint8_t bVolume; //235491df
	uint8_t bData_235491e0; //235491e0 0xefc
	uint8_t bData_235491e1; //235491e1 0xefd
	uint8_t bData_235491e2; //235491E2 0xefe

} Struct_235462e4;


typedef struct
{
	void* Data_0; //0
	void* Data_4; //4
	
} Struct_2340ce18;


typedef struct
{
	void* hAuOut; //0
	void* hAudec2; //4
	void* hAudec1; //8
	void* hAudec0; //12
	void* hAudec4; //16
	void* hAudec5; //20
	//24 = 0x18
} Channel_Audio_Handles;



extern int channel_handle_user_settings(int get, User_Settings*);
extern void sub_2340bf94(int, Channel*, Transponder*);
extern void sub_2340bf0c(Struct_2340bf0c*);
extern void sub_23409770(void);
extern void sub_23409788(void);
extern void channel_write_lastmode(void);
extern Channel_Database* sub_2344f770(void);
void sub_2340d2cc(void (*set_volume)(uint8_t), void (*r5)(int));

#endif //SUB_2340a6a0
