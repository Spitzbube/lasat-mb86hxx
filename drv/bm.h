
#ifndef DRV_BM_H
#define DRV_BM_H


typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int pidChannel; //8
	int bufferAddress; //12
	uint32_t bufferSize; //16 = 0x10
	int Data_0x14; //20 = 0x14
	int Data_0x18; //24 = 0x18
	int Data_0x1c; //28 = 0x1c
	void (*handleOverflow)(); //32 = 0x20
	void (*Data_0x24)(); //36 = 0x24
	uint32_t Data_0x28; //40 = 0x28
	void (*Data_0x2c)(); //44 = 0x2c
	uint32_t Data_0x30; //48 = 0x30
	//0x34 = 52
} BM_OpenParams;


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


extern void* bm_open(BM_OpenParams* pOpenParams);

#endif //DRV_BM_H
