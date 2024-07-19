
#ifndef DRV_TSD_H
#define DRV_TSD_H

typedef struct
{
	int msg_id; //0
	int table_id; //4
	int Data_8; //8
	int Data_0xc; //12
	struct
	{
		uint32_t Data_0; //0
		uint8_t fill_4; //4
		uint8_t bData_5; //5
		uint8_t bData_6; //6
		uint32_t Data_8; //8
		int fill_12[1469]; //12
	} Data_0x10; //16
	//5904
} Struct_236e5834;


typedef struct
{
	uint32_t Data_0; //0
	uint32_t bmStart; //4
	uint32_t bmEnd; //8
	uint32_t bmSize; //12
	//16?
} TSD_BM_Buffer;


typedef struct TSD_Handle
{
	uint8_t bData_0; //0
	int Data_4; //4
#if 0
	uint32_t Data_8; //8
	uint32_t bmStart; //12 = 0xc
	uint32_t bmEnd; //16 = 0x10
	uint32_t bmSize; //20 = 0x14
#else
	TSD_BM_Buffer Data_8; //8
#endif
	uint32_t Data_0x18; //24 = 0x18
	uint16_t pid; //0x1c = 28
	void (*sectionDataNotify)(Struct_236e5834*, uint8_t); //32 = 0x20
	int Data_0x24; //36 = 0x24
	int Data_0x28; //40 = 0x28
	//0x2c = 44
} TSD_Handle;


typedef struct
{
	uint8_t bData_0; //0
	uint32_t Data_4; //4
	int Data_8; //8
	int Data_12; //12
	int Data_0x10; //16 = 0x10
	int Data_0x14; //0x14 = 20
	int Data_0x18; //0x18 = 24
	uint16_t wData_0x1c; //0x1c
	void* bmHandle; //32 = 0x20
	int Data_0x24; //0x24
	uint8_t bData_0x28; //0x28
	//44 = 0x2c
} Struct_235f048c;


typedef struct
{
	uint8_t bNumTargetIndex; //0
	uint16_t wTargetLength; //2
	void* Data_4; //4
	uint8_t bData_8; //8

} TSD_SectionFilter;

typedef struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	uint16_t pid; //2
	TSD_SectionFilter* Data_4; //4
	BM_OpenParams bmOpenParams; //8
	void (*sectionDataNotify)(); //60 = 0x3c
} TSD_PidChannelParams;


typedef struct
{
	uint8_t bData_0; //0
	uint16_t wData_2; //2
	void* Data_4; //4
	uint8_t bData_8; //8

} Struct_23421780;


typedef struct
{
	int Data_0; //0
	int Data_4; //4
	//8
} Struct_2342c4f8_Inner8;


typedef struct
{
	uint32_t Data_0; //0
	int Data_4; //4
	Struct_2342c4f8_Inner8* Data_8; //8
	void* Data_12; //12
	//16
} Struct_2342c4f8;


typedef struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	uint16_t pid; //2
#if 0
	int Data_4; //4
	int Data_8; //8
	int Data_0xc; //12 = 0xc
	int Data_0x10; //0x10
	int Data_0x14; //0x14
	int Data_0x18; //0x18
	int Data_0x1c; //0x1c
	int Data_0x20; //0x20 = 32
	int Data_0x24; //0x24 = 36
	int Data_0x28; //0x28 = 40
	int Data_0x2c; //0x2c
	int Data_0x30; //0x30
	int Data_0x34; //0x34
#else
	BM_OpenParams Data_4; //4
#endif
	int Data_0x38; //0x38
	//0x3c
} TSD_PesParserParams;


typedef struct
{
	uint16_t wData_0; //0
	uint16_t wData_2; //2
	uint16_t wData_4; //4
	uint16_t wData_6; //6
	uint16_t wData_8; //8
	uint16_t wData_10; //10
	uint16_t wData_12; //12
	uint16_t wData_14; //14
	uint16_t wData_16; //16
	uint16_t wData_18; //18
	uint16_t wData_20; //20
	uint16_t wData_22; //22
	uint16_t wData_24; //24
	uint16_t wData_26; //26
	uint16_t wData_28; //28
	uint16_t wData_30; //30
	uint16_t wData_32; //32
	uint16_t wData_34; //34
	uint16_t wData_36; //36
	uint16_t wData_38; //38
	uint16_t wData_40; //40
	uint16_t wData_42; //42
	uint16_t wData_44; //44
	uint16_t wData_46; //46
	uint16_t wData_48; //48
	uint16_t wData_50; //50
	uint16_t wData_52; //52
	uint16_t wData_54; //54
	uint16_t wData_56; //56
	uint16_t wData_58; //58
	uint16_t wData_60; //60
	uint16_t wData_62; //62
	uint16_t wData_64; //64
	uint16_t wData_66; //66
	uint16_t wData_68; //68
	uint16_t fill_70; //70
	//0x48 = 72
} TSD_InitParams;


int sub_23421780(TSD_Handle*, uint16_t pid, Struct_23421780*);
uint32_t sub_234225f4();
void* tsd_get_bm_handle(void*);



#endif //DRV_TSD_H
