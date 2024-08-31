
#ifndef AMPLIFIER_H
#define AMPLIFIER_H

typedef struct
{
	void (*shutdown)(); //235FC42C  0x235fc3ec + 0x40
	void (*Data_235fc430)(); //235fc430 = 4
	void (*Data_235fc434)(); //235fc434 = 8
	void (*Data_235fc438)(); //235fc438 = 12
	void (*Data_235fc43c)(); //235fc43c = 0x10
	void (*Data_235fc440)(); //235fc440 = 0x14
	void (*Data_235fc444)(); //235fc444 = 0x18
	void (*Data_235fc448)(); //235FC448 = 0x1c
	void (*input_configuration)(); //235fc44c = 0x20
	void (*Data_235fc450)(); //235fc450 = 0x24
	void (*Data_235fc454)(); //235FC454 = 0x28
	void (*Data_235fc458)(); //235fc458 = 0x2c
	void (*Data_235fc45c)(); //235fc45c = 0x30
	void (*Data_235fc460)(); //235fc460 = 0x34
	void (*Data_235fc464)(); //235FC464 = 0x38
	//0x3c
} Amplifier_Interface_Functions;


typedef struct
{
	uint32_t Data_0; //0
	uint32_t Data_4; //4
	uint32_t Data_8; //8
	//12
} Amplifier_Gpio_Params;


extern int amplifier_get_data(Amplifier_Interface_Functions*, Amplifier_Settings*, uint8_t* r4, uint8_t* r5);
extern int amplifier_switch_powermode(int);

#endif //AMPLIFIER_H
