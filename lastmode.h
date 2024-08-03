
#ifndef LASTMODE_H
#define LASTMODE_H

typedef struct
{
	OS_EVENT* sema; //0
	uint32_t length; //4
	uint8_t* data; //8
	Struct_235f2e2c* pFlash; //12
	uint32_t Data_16; //16
	uint32_t Data_20; //20
	//0x18 = 24
} Struct_23438084;

typedef struct
{
	void* pData; //0
	uint32_t crc; //4
	uint32_t Data_8; //8
	uint32_t Data_12; //12
	uint32_t Data_16; //16
	//20
} Struct_235f3784_Inner_0x18;

typedef struct
{
	Struct_23438084 Data_0; //0
	Struct_235f3784_Inner_0x18 Data_24[10]; //24 = 0x18
//	int Data_24[50]; //24 = 0x18
	//0xe0 = 224
} Lastmode_Instance;

typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	Struct_235f2e2c* pFlash; //12
	void* pBuffer; //16

} Lastmode_Params;

void* lastmode_init(Lastmode_Params*);

int lastmode_read(Lastmode_Instance* p, void* buf, uint32_t offset, uint32_t count);
int lastmode_write(Lastmode_Instance* p, void* buf, uint32_t offset, uint32_t count);

#endif //LASTMODE_H
