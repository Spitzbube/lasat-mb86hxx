
#ifndef AMPLIFIER_H
#define AMPLIFIER_H

typedef struct
{
	void (*Data_235fc42c)(); //235FC42C  0x235fc3ec + 0x40
	void (*Data_235fc430)(); //235fc430 = 4
	void (*Data_235fc434)(); //235fc434 = 8
	int Data_235fc438; //235fc438 = 12
	void (*Data_235fc43c)(); //235fc43c = 0x10
	void (*Data_235fc440)(); //235fc440 = 0x14
	void (*Data_235fc444)(); //235fc444 = 0x18
	void (*Data_235fc448)(); //235FC448 = 0x1c
	void (*Data_235fc44c)(); //235fc44c = 0x20
	void (*Data_235fc450)(); //235fc450 = 0x24
	void (*Data_235fc454)(); //235FC454 = 0x28
	void (*Data_235fc458)(); //235fc458 = 0x2c
	void (*Data_235fc45c)(); //235fc45c = 0x30
	void (*Data_235fc460)(); //235fc460 = 0x34
	void (*Data_235fc464)(); //235FC464 = 0x38
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

#endif //AMPLIFIER_H
