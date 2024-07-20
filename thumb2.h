
#ifndef THUMB2_H
#define THUMB2_H

typedef struct
{
	void (*Data_235fc42c)(); //235FC42C  0x235fc3ec + 0x40
	void (*Data_235fc430)(); //235fc430 = 4
	int fill_235fc434[4]; //235fc434 = 8
	int Data_235fc444; //235fc444 = 0x18
	int Data_235fc448; //235FC448
	void (*Data_235fc44c)(); //235fc44c = 0x20
	int fill_235fc450; //235fc450 = 0x24
	int Data_235fc454; //235FC454 = 0x28
	int Data_235fc458; //235fc458 = 0x2c
	int fill_235fc45c[3]; //235fc45c = 0x30
	//0x3c
} Struct_235fc42c;


typedef struct
{
	uint32_t Data_0; //0
	uint32_t Data_4; //4
	uint32_t Data_8; //8
	//12
} Struct_2343b8e6;


extern int sub_2343b946(Struct_235fc42c* r0, void* r6, uint8_t* r4, uint8_t* r5);

#endif //THUMB2_H
