
#ifndef DRV_FLASH_H
#define DRV_FLASH_H

typedef struct
{
	void (*read_dwords)(); //0
	void (*Data_4)(); //4
	void (*Data_8)(); //8
	void (*Data_12)(); //12
	void (*Data_16)(); //16
	void (*Data_20)(); //20
	//0x18 = 24
} Struct_235f2e2c_Inner_8;


typedef struct
{
	OS_EVENT* sema; //0
	int Data_4; //4
	Struct_235f2e2c_Inner_8 Data_8; //8
	struct
	{
		uint32_t Data_0; //0
		uint32_t Data_4; //4
		//8
	}* Data_0x20; //0x20 = 32
	int Data_0x24; //0x24
	uint32_t numSectors; //0x28
	int fill_0x2c[65]; //0x2c
	uint32_t jedec_id; //0x130
	//0x134 = 308
} Struct_235f2e2c;


extern int flash_read(Struct_235f2e2c* r4, int r5, int r6, void* r7);


#endif //DRV_FLASH_H
