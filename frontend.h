
#ifndef FRONTEND_H
#define FRONTEND_H

typedef struct Struct_2354dd70
{
	uint16_t wData_0; //0
	uint8_t bData_2; //2
#if 1
	struct
	{
		int Data_0[6]; //0 (4)
		int (*Data_0x18)(int); //0x18 = 24 (0x1c)
		int fill_0x1c[4]; //0x1c = 28 (0x20)
		//0x2c = 44
	} Data_4;
#else
	int Data_4[6]; //4
	int (*Data_0x1c)(int); //0x1c
	int fill_0x20[4]; //0x20
#endif
	struct
	{
		void (*Data_0)(); //0 (0x30)
		void (*Data_4)(); //4 (0x34)
		int (*Data_8)(); //8 (0x38)
		int (*Data_0x0c)(); //0x0c = 12 (0x3c)
		void (*Data_0x10)(); //0x10 = 0x40
		void (*Data_0x14)(); //0x14 = 0x44
		void (*Data_0x18)(); //0x18 = 24 (0x48)
		void (*Data_0x1c)(); //1c = 28 (0x4c)
		//0x20 = 32
	} Data_0x30; //0x30
	void (*threadFunc)(struct Struct_2354dd70*); //0x50 = 80
	void (*stateChangeCallback)(); //0x54 = 84
	void (*Data_0x58)(struct Struct_2354dd70*); //0x58 = 88
	void (*Data_0x5c)(); //0x5c
	int (*Data_0x60)(); //0x60
	Transponder Data_0x64; //0x64 +0x18
	Transponder Data_0x7c; //0x7c +0x18
	int Data_0x94; //0x94
	int Data_0x98; //0x98
	uint8_t bData_0x9c; //0x9c
	uint8_t bData_0x9d; //0x9d
	uint8_t bData_0x9e; //0x9e
	uint8_t bData_0x9f; //0x9f
	Struct_20611068* resetGpio; //0xa0
	Struct_20611068* Data_0xa4; //0xa4
	Struct_20611068* Data_0xa8; //0xa8
	Struct_20611068* Data_0xac; //0xac
	Struct_20611068* Data_0xb0; //0xb0
	int Data_0xb4; //0xb4
	Struct_20611068* Data_0xb8; //0xb8
	Struct_20611068* Data_0xbc; //0xbc
	void* hI2c; //0xc0
	int Data_0xc4; //0xc4
	int Data_0xc8; //0xc8
	uint8_t bData_0xcc; //0xcc
	int Data_0xd0; //0xd0
	int16_t wData_0xd4; //0xd4
	uint16_t fill_0xd6; //0xd6
	uint8_t bState; //0xd8 = 216
	uint8_t bData_0xd9; //0xd9
	uint8_t bData_0xda; //0xda = 218
	//220 = 0xdc?
} Struct_2354dd70;


typedef struct
{
	void* hI2c; //0
	int Data_4; //4
	uint8_t bData_8; //8
	uint8_t bData_9; //9
	uint8_t bData_10; //10
	uint8_t bData_11; //11
	uint8_t bData_12; //12
	uint8_t bData_13; //13
	uint8_t bData_14; //14
	uint8_t bData_15; //15
	uint8_t bData_16; //16
	uint8_t bData_17; //17
	//20
} Struct_2340e754;

#endif //FRONTEND_H
