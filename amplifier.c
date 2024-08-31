
#include "data.h"
#include "amplifier.h"

#pragma thumb

#define CS4525_I2C_ADDRESS	0x96
#define CS4524_REG_INPUT_CONFIGURATION		0x02
#define CS4524_REG_TONE_CONTROL				0x08
#define CS4524_REG_MASTER_VOLUME_CONTROL	0x57
#define CS4524_REG_CHANNEL_A_VOLUME_CONTROL	0x58
#define CS4524_REG_CHANNEL_B_VOLUME_CONTROL	0x59
#define CS4524_REG_SUB_CHANNEL_VOLUME_CONTROL	0x5a
#define CS4524_REG_POWER_CONTROL			0x5f
#define CS4525_REG_DEVICE					0x63


Struct_20611068* amplifier_reset_gpio = 0; //23492d60
Struct_20611068* Data_23492d64 = 0; //23492d64
Struct_20611068* Data_23492d68 = 0; //23492d68
void (*Data_23492d6c)() = 0; //23492d6c / 234d8284 

struct
{
	Amplifier_Gpio_Params amplifier_gpio_params; //235fc28c

	Amplifier_Settings Data_235fc298; //235fc298 -> 235FC408

	struct Struct_235fc408
	{
		uint8_t bData_235fc408; //235FC408
		uint8_t bData_235fc409; //235FC409
		uint8_t bData_235fc40a[2]; //235fc40a
		uint8_t bData_235fc40c[2]; //235fc40c
		int fill_235FC410[5]; //235FC410
		uint16_t wData_235fc424; //235FC424
		uint8_t i2cAddr; //235FC426
		uint8_t bData_235fc427; //235fc427
		uint8_t powerOn; //235fc428
		uint8_t bData_235fc429; //235fc429

	} Data_235fc408;
	//0x1A0 = 416
} Data_235fc28c; //235fc28c -> 235FC42C

Amplifier_Interface_Functions amplifier_interface_fn; //235fc42c Addr??? -> 235FC468


/* 2343b174 - todo */
int amplifier_set_bass(uint8_t r5)
{
#if 0
	console_send_string("amplifier_set_bass (todo.c): TODO\r\n");
#endif

	uint16_t r0 = 32;

	if (r5 == 0xff)
	{
		r5 = Data_235fc28c.Data_235fc298.arEqualizerSettings[Data_235fc28c.Data_235fc408.bData_235fc429].bBass;
	}
	else
	{
		Data_235fc28c.Data_235fc298.arEqualizerSettings[Data_235fc28c.Data_235fc408.bData_235fc429].bBass = r5;
	}

	int r2 = Data_235fc28c.Data_235fc298.arEqualizerSettings[Data_235fc28c.Data_235fc408.bData_235fc429].bData_0x11;
	if (r2 == 3)
	{
		r0 = (((uint32_t)(Data_235fc28c.Data_235fc408.wData_235fc424 * Data_235fc28c.Data_235fc408.wData_235fc424)) << 11) >> 16;
		//->loc_2343b1d6
	}
	//loc_2343b1ae
	else if (r2 == 2)
	{
		//0x2343b1b2
		int x = Data_235fc28c.Data_235fc408.wData_235fc424 * Data_235fc28c.Data_235fc408.wData_235fc424;
		r0 = (x >> 4) / 3 + 10;
	}
	//loc_2343b1c2
	else if (r2 == 1)
	{
		int x = Data_235fc28c.Data_235fc408.wData_235fc424 * Data_235fc28c.Data_235fc408.wData_235fc424;
		r0 = (x >> 5) / 3 + 21;
	}
	//loc_2343b1d6
	Data_235fc28c.Data_235fc408.bData_235fc409 = r0 + 0x10;
	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_SUB_CHANNEL_VOLUME_CONTROL;

	int res = i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
				&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	r5 *= 2;
	if (r5)
	{
		//0x2343b1fa
		r5--;
	}
	//loc_2343b1fe: Read Tone Control
	res |= i2c_master_read_reg(main_hI2c0, CS4525_I2C_ADDRESS, CS4524_REG_TONE_CONTROL,
				&Data_235fc28c.Data_235fc408.bData_235fc408, 1);

	Data_235fc28c.Data_235fc408.bData_235fc409 = 
		(Data_235fc28c.Data_235fc408.bData_235fc408 & 0xf0) | (0x0f - r5);
	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_TONE_CONTROL;

	res |= i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
				&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	return res;
}


/* 2343b232 - todo */
int amplifier_set_treble(uint8_t r0)
{
#if 0
	console_send_string("amplifier_set_treble (todo.c): TODO\r\n");
#endif

	Data_235fc28c.Data_235fc298.arEqualizerSettings[Data_235fc28c.Data_235fc408.bData_235fc429].bTreble = r0;

	uint8_t r4 = r0 * 2;
	if (r4)
	{
		r4--;
	}

	int res = i2c_master_read_reg(main_hI2c0, CS4525_I2C_ADDRESS, CS4524_REG_TONE_CONTROL,
				&Data_235fc28c.Data_235fc408.bData_235fc408, 1);

	Data_235fc28c.Data_235fc408.bData_235fc409 = 
		(Data_235fc28c.Data_235fc408.bData_235fc408 & 0x0f) | ((0x0f - r4) << 4);
	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_TONE_CONTROL;

	res |= i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
				&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	return res;
}


/* 2343b28c - todo */
int sub_2343b28c(uint8_t a)
{
	Struct_2340bf0c sp;
	uint8_t r0;

#if 0
	console_send_string("sub_2343b28c (todo.c): TODO\r\n");
#endif

	/*235FC405*/Data_235fc28c.Data_235fc298.bData_16d = a;

	if (Data_235fc28c.Data_235fc298.bData_16d < 2)
	{
		/*235FC428*/Data_235fc28c.Data_235fc408.powerOn = Data_235fc28c.Data_235fc298.bData_16d;

		if (Data_235fc28c.Data_235fc408.powerOn != 0)
		{
			//->loc_2343b2da
			r0 = 0xe0;
			//->loc_2343b2bc
			//Data_235fc28c.Data_235fc408.bData_235fc409 = 0xe0;
		}
		else
		{
			//loc_2343b2ba
			r0 = 0xff;
			//Data_235fc28c.Data_235fc408.bData_235fc409 = 0xff;
		}
	}
	else
	{
		//loc_2343b2a8
		sub_2340bf0c(&sp);

		if (sp.bCurrentChList == 1)
		{
			//0x2343b2b6
			Data_235fc28c.Data_235fc408.powerOn = 0;
			//loc_2343b2ba
			r0 = 0xff;
			//Data_235fc28c.Data_235fc408.bData_235fc409 = 0xff;
		}
		else
		{
			//loc_2343b2d6
			Data_235fc28c.Data_235fc408.powerOn = 1;
			//loc_2343b2da
			r0 = 0xe0;
			//->loc_2343b2bc
			//Data_235fc28c.Data_235fc408.bData_235fc409 = 0xe0;
		}
	}

	Data_235fc28c.Data_235fc408.bData_235fc409 = r0;
	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_POWER_CONTROL;

	return i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
			&Data_235fc28c.Data_235fc408.bData_235fc408, 2);
}


/* 2343b2de - complete */
int amplifier_power_control(int a)
{
	uint8_t r0;

#if 0
	console_send_string("amplifier_power_control (todo.c): TODO\r\n");
#endif

	if (Data_235fc28c.Data_235fc298.bData_16d < 2)
	{
		Data_235fc28c.Data_235fc408.powerOn = Data_235fc28c.Data_235fc298.bData_16d;
		return 0;
	}

	if (a == 1)
	{
		r0 = 0;
	}
	else
	{
		r0 = 1;
	}

	if (Data_235fc28c.Data_235fc408.powerOn == r0)
	{
		return 0;
	}

	Data_235fc28c.Data_235fc408.powerOn = r0;

	if (Data_235fc28c.Data_235fc408.powerOn != 0)
	{
		r0 = 0xe0;
	}
	else
	{
		//Power down
		r0 = 0xe0 | 0x1f;
	}

	Data_235fc28c.Data_235fc408.bData_235fc409 = r0;
	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_POWER_CONTROL;

	return i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);
}


/* 2343b32a - todo */
static int cs4524_shutdown(void)
{
#if 0
	console_send_string("cs4524_shutdown (todo.c): TODO\r\n");
#endif

	Data_235fc28c.Data_235fc408.powerOn = 0;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0xff;
	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_POWER_CONTROL;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	gpio_set(amplifier_reset_gpio, 0);
	gpio_set(Data_23492d68, 0);

	return 0;
}


/* 2343b364 - tood */
int sub_2343b364(uint8_t a)
{
#if 0
	console_send_string("sub_2343b364 (todo.c): TODO\r\n");
#endif

	uint8_t r1;
	uint32_t r0;

	Data_235fc28c.Data_235fc408.wData_235fc424 = r0 = a;

	if ((Data_235fc28c.Data_235fc408.bData_235fc427 < 3) ||
		(Data_235fc28c.Data_235fc298.Data_0xb8[Data_235fc28c.Data_235fc408.bData_235fc427].bData_0x12 & 1))
	{
		//loc_2343b388
		r1 = 0x3a;
	}
	else
	{
		//loc_2343b38c
		r0 <<= 2;
		r1 = 0x85;
	}

	Data_235fc28c.Data_235fc408.bData_235fc409 = r1 - r0;
	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_MASTER_VOLUME_CONTROL;

	int res = i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
				&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	if (Data_235fc28c.Data_235fc298.arEqualizerSettings[Data_235fc28c.Data_235fc408.bData_235fc429].bData_0x11 != 0)
	{
		amplifier_set_bass(0xff);
	}

	return res;
}


/* 2343b3c4 - todo */
int sub_2343b3c4(uint8_t a)
{
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2343b3c4: a=%d\r\n",
				a);
		console_send_string(debug_string);
	}
#endif

	Data_235fc28c.Data_235fc408.bData_235fc427 = a;

	uint32_t r1 = Data_235fc28c.Data_235fc298.Data_0xb8[a].bData_0x12;
	if (r1 & (1 << 0))
	{
		a = 0;
	}
	//loc_2343b3de
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x41;
	Data_235fc28c.Data_235fc408.bData_235fc40a[1] = 0xff;
	Data_235fc28c.Data_235fc408.bData_235fc40c[1] = 0xff;

	if (a == 0)
	{
		//r1 = 0;
		//->loc_2343b42a
		gpio_set(Data_23492d68, 0);
		//->loc_2343b452
	}
	//loc_2343b3f4
	else if (a == 3)
	{
		//0x2343b3f8
		Data_235fc28c.Data_235fc408.bData_235fc409 = 0x41 |
			(1 << 7)/*Analog input from the internal ADC*/;
		//->loc_2343b452
	}
	//loc_2343b3fe
	//r7 = 0x0c;
	else if (a == 4)
	{
		//0x2343b404
		if (0 != strcmp(/*235FC3A0*/&Data_235fc28c.Data_235fc298.Data_0xb8[4], "BLUETOOTH"))
		{
			//r0 = 0x80;
			//->loc_2343b44e
			Data_235fc28c.Data_235fc408.bData_235fc40a[1] = 0x80;
			Data_235fc28c.Data_235fc408.bData_235fc40c[1] = 0x0c;
			//loc_2343b452
		}
		else
		{
			//loc_2343b428
			//r1, #0x1
			//loc_2343b42a
			gpio_set(Data_23492d68, 1);
			//->loc_2343b452
		}
	}
	//loc_2343b416
	else if (a == 5)
	{
		//0x2343b41a
		if (0 == strcmp(/*235FC3B4*/&Data_235fc28c.Data_235fc298.Data_0xb8[5], "BLUETOOTH"))
		{
			//loc_2343b428
			gpio_set(Data_23492d68, 1);
			//->loc_2343b452
		}
		else
		{
			//loc_2343b432
			//r0, #0x89 
			//->loc_2343b44e
			Data_235fc28c.Data_235fc408.bData_235fc40a[1] = 0x89;
			Data_235fc28c.Data_235fc408.bData_235fc40c[1] = 0x0c;
			//loc_2343b452
		}
	}
	//loc_2343b436
	else if (a == 6)
	{
		//0x2343b43a
		Data_235fc28c.Data_235fc408.bData_235fc40c[1] = 0x00;
		//->loc_2343b452
	}
	//loc_2343b440
	else if (a == 7)
	{
		//0x2343b444
		//r0, #0x92
		//->loc_2343b44e
		Data_235fc28c.Data_235fc408.bData_235fc40a[1] = 0x92;
		Data_235fc28c.Data_235fc408.bData_235fc40c[1] = 0x0c;
	}
	//loc_2343b448
	else if (a == 8)
	{
		//0x2343b44c
		//r0, #0x9b
		//->loc_2343b44e
		Data_235fc28c.Data_235fc408.bData_235fc40a[1] = 0x9b;
		Data_235fc28c.Data_235fc408.bData_235fc40c[1] = 0x0c;
	}
	//loc_2343b452
	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_INPUT_CONFIGURATION;

	int r7 = i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
				&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	if (Data_235fc28c.Data_235fc408.i2cAddr != 0)
	{
		//0x2343b46e
		if (Data_235fc28c.Data_235fc408.bData_235fc40c[1] != 0xff)
		{
			//0x2343b474
			int r6 = gpio_set(Data_23492d68, 1);

			Data_235fc28c.Data_235fc408.bData_235fc40c[0] = 0x02;

			int r0 = i2c_master_send(main_hI2c0, Data_235fc28c.Data_235fc408.i2cAddr, 
						&Data_235fc28c.Data_235fc408.bData_235fc40c[0], 2);
			r0 |= r6;
			r7 = r0;
		}
		//loc_2343b494
		if (Data_235fc28c.Data_235fc408.bData_235fc40a[1] != 0xff)
		{
			Data_235fc28c.Data_235fc408.bData_235fc40a[0] = 0x04;

			r7 |= i2c_master_send(main_hI2c0, Data_235fc28c.Data_235fc408.i2cAddr, 
						&Data_235fc28c.Data_235fc408.bData_235fc40a[0], 2);
		}
		//loc_2343b4b0
	}
	//loc_2343b4b0
	sub_2343b364(Data_235fc28c.Data_235fc408.wData_235fc424);

	return r7;
}


/* 2343b4bc - complete */
void sub_2343b4bc(uint8_t a)
{
#if 0
	console_send_string("sub_2343b4bc (todo.c): TODO\r\n");
#endif

	uint32_t r5 = a << 3;

	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_CHANNEL_B_VOLUME_CONTROL;
	Data_235fc28c.Data_235fc408.bData_235fc409 = r5 + 0x29;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
				&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_CHANNEL_A_VOLUME_CONTROL;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x59 - r5;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
				&Data_235fc28c.Data_235fc408.bData_235fc408, 2);
}


const uint8_t arData_23489e40[5][15] = //23489e40
{
   {0x38, 0xf9, 0x53, 0xe5, 0xc0, 0xd5, 0x1e, 0xbd, 0xb3, 0xc7, 0x06, 0xad, 0x1b, 0x81, 0x77},
   {0x29, 0x94, 0x02, 0xf1, 0x7f, 0xce, 0x39, 0x86, 0x63, 0xaa, 0x97, 0x4d, 0x20, 0xce, 0x80},
   {0x29, 0xed, 0xd4, 0xe6, 0xe6, 0x98, 0x1e, 0x47, 0x66, 0xd6, 0x12, 0x1c, 0x1a, 0xd2, 0x01},
   {0x3f, 0xe6, 0x00, 0xe0, 0x19, 0x1b, 0x20, 0x05, 0x2d, 0xc0, 0x1a, 0x00, 0x1f, 0xe1, 0xb8},
   {0x3f, 0xee, 0xb2, 0xe0, 0x0f, 0xe7, 0x1f, 0xfd, 0x10, 0xc0, 0x11, 0x4e, 0x1f, 0xf3, 0x08},
};


/* 2343b4f4 - todo */
int sub_2343b4f4(void)
{
#if 0
	console_send_string("sub_2343b4f4 (todo.c): TODO\r\n");
#endif

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x64;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x55;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x69;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x08;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x64;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x00;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x01;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x20;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc409 = 0xff;
	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_POWER_CONTROL;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	int r0 = Data_235fc28c.Data_235fc298.Data_0xb8[Data_235fc28c.Data_235fc298.bData_16c].bData_16;

//	Equalizer_Settings* r6 = &Data_235fc28c.Data_235fc298.Data_4[r0];
	//->loc_2343b58c
	amplifier_set_bass(/*r6->*/Data_235fc28c.Data_235fc298.arEqualizerSettings[r0].bBass);
	amplifier_set_treble(/*r6->*/Data_235fc28c.Data_235fc298.arEqualizerSettings[r0].bTreble);
	sub_2343b4bc(/*r6->*/Data_235fc28c.Data_235fc298.arEqualizerSettings[r0].bData_0x10);
	sub_2343b3c4(Data_235fc28c.Data_235fc298.bData_16c);
	sub_2343b9b6(/*r6->*/Data_235fc28c.Data_235fc298.arEqualizerSettings[r0].bData_0x11);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x04;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x48;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x05;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x88;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x06;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x0f;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x07;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x67;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x09;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x80;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	for (uint8_t i = 0, reg = 0x0a; i < 5; i++)
	{
		//loc_2343b612
		//uint8_t* sp4 = &arData_23489e40[i];
		for (uint8_t k = 0; k < 15; k++)
		{
			//loc_2343b61e
			Data_235fc28c.Data_235fc408.bData_235fc408 = reg++;
			Data_235fc28c.Data_235fc408.bData_235fc409 = /*sp4*/arData_23489e40[i][k];

			i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
				&Data_235fc28c.Data_235fc408.bData_235fc408, 2);
		}
	}
	//0x2343b648
	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_CHANNEL_A_VOLUME_CONTROL;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x48;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = CS4524_REG_CHANNEL_B_VOLUME_CONTROL;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x48;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x09;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x23;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	Data_235fc28c.Data_235fc408.bData_235fc408 = 0x5c;
	Data_235fc28c.Data_235fc408.bData_235fc409 = 0x1d;

	i2c_master_send(main_hI2c0, CS4525_I2C_ADDRESS, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

	sub_2343b28c(Data_235fc28c.Data_235fc298.bData_16d);

	i2c_master_read_reg(main_hI2c0, CS4525_I2C_ADDRESS, 0x62, 
		&Data_235fc28c.Data_235fc408.bData_235fc408, 1);

	return 0;
}


/* 2343b6b2 - todo */
void sub_2343b6b2()
{
	console_send_string("sub_2343b6b2 (todo.c): TODO\r\n");

}


/* 2343b7b8 - todo */
void sub_2343b7b8()
{
	console_send_string("sub_2343b7b8 (todo.c): TODO\r\n");

}


/* 2343b7e6 - todo */
void sub_2343b7e6()
{
	console_send_string("sub_2343b7e6 (todo.c): TODO\r\n");

}


/* 2343b7fe - todo */
int sub_2343b7fe(int a)
{
#if 0
	console_send_string("sub_2343b7fe (todo.c): TODO\r\n");
#endif

	Data_235fc28c.Data_235fc408.bData_235fc429 = a;

#if 1
	Data_235fc28c.Data_235fc298.Data_0xb8[ Data_235fc28c.Data_235fc408.bData_235fc427 ].bData_16 = 
		Data_235fc28c.Data_235fc408.bData_235fc429;
#else
	struct Struct_2340d1f4_Inner_0xb8* p = &Data_235fc28c.Data_235fc298.Data_0xb8[ Data_235fc28c.Data_235fc408.bData_235fc427 ];
	p->bData_16 = Data_235fc28c.Data_235fc408.bData_235fc429;
#endif

	return 0;
}


/* 2343b81a - todo */
void sub_2343b81a()
{
	console_send_string("sub_2343b81a (todo.c): TODO\r\n");

}


/* 2343b822 - todo */
int sub_2343b822(void)
{
	User_Settings sp4;

#if 0
	console_send_string("sub_2343b822 (todo.c): TODO\r\n");
#endif

	memset(&amplifier_interface_fn, 0, sizeof(amplifier_interface_fn));
	memset(&Data_235fc28c, 0, sizeof(Data_235fc28c));

	channel_handle_amplifier_settings(1, &Data_235fc28c.Data_235fc298);

	channel_handle_user_settings(1, &sp4);

	gpio_set(amplifier_reset_gpio, 0);

	rtos_task_wait(1);

	gpio_set(amplifier_reset_gpio, 1);

	rtos_task_wait(1);

	int r0 = i2c_master_read_reg(main_hI2c0, CS4525_I2C_ADDRESS, CS4525_REG_DEVICE, 
					&Data_235fc28c.Data_235fc408.bData_235fc408, 1);

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2343b822: r0=%d, bData_235fc408=0x%02x\r\n", 
			r0, Data_235fc28c.Data_235fc408.bData_235fc408);
		console_send_string(debug_string);
	}
#endif

	if (r0 == 0)
	{
		//0x2343b884
		Data_235fc28c.Data_235fc408.wData_235fc424 = sub_2340a650(sp4.bData_8);

		Data_235fc28c.Data_235fc408.bData_235fc427 = Data_235fc28c.Data_235fc298.bData_16c;

		Data_235fc28c.Data_235fc408.bData_235fc429 =
				Data_235fc28c.Data_235fc298.Data_0xb8[ Data_235fc28c.Data_235fc408.bData_235fc427 ].bData_16;

		if ((Data_235fc28c.Data_235fc408.bData_235fc427 > 9) ||
				(Data_235fc28c.Data_235fc408.bData_235fc429 > 9))
		{
			//loc_2343b8b2
			sub_2343b6b2();
		}
		//loc_2343b8b6
		amplifier_set_interface_functions(0);

		sub_2343ba6a();

		if (0 == sub_2343b4f4())
		{
			//0x2343b8c8
			sub_2340d2cc(amplifier_interface_fn.Data_235fc454, amplifier_interface_fn.Data_235fc448);
		}
		//loc_2343b8d4
		return 0;
	}
	else
	{
		//loc_2343b8da
		gpio_set(amplifier_reset_gpio, 0);

		return 8;
	}
}


/* 2343b8e6 - todo */
int amplifier_gpio_init(Amplifier_Gpio_Params* a)
{
	Struct_20401328 sp;

#if 0
	console_send_string("amplifier_gpio_init (todo.c): TODO\r\n");
#endif

	if (a != 0)
	{
		Data_235fc28c.amplifier_gpio_params = *a;

		if (Data_235fc28c.amplifier_gpio_params.Data_0 != 0xff)
		{
			//0x2343b900
			sp.dwInFunction = 0xff;
			sp.dwOutFunction = 0x00;
			sp.bPin = Data_235fc28c.amplifier_gpio_params.Data_0;

			gpio_open(&sp, &amplifier_reset_gpio);
		}
		//loc_2343b912
		if (Data_235fc28c.amplifier_gpio_params.Data_4 != 0xff)
		{
			//0x2343b918
			sp.dwInFunction = 0xff;
			sp.dwOutFunction = 0x00;
			sp.bPin = Data_235fc28c.amplifier_gpio_params.Data_4;

			gpio_open(&sp, &Data_23492d64);
		}
		//loc_2343b92a
		if (Data_235fc28c.amplifier_gpio_params.Data_8 != 0xff)
		{
			//0x2343b930
			sp.dwInFunction = 0xff;
			sp.dwOutFunction = 0x00;
			sp.bPin = Data_235fc28c.amplifier_gpio_params.Data_8;

			gpio_open(&sp, &Data_23492d68);
		}
		//loc_2343b942
	}
	//loc_2343b942
	return 0;
}


/* 2343b946 - todo */
int amplifier_get_data(Amplifier_Interface_Functions* r0, Amplifier_Settings* r6, uint8_t* r4, uint8_t* r5)
{
#if 0
	console_send_string("amplifier_get_data (todo.c): TODO\r\n");
#endif

	if (amplifier_interface_fn.Data_235fc444 == 0)
	{
		return 8;
	}
	//loc_2343b95c
	if (r0 != 0)
	{
		memcpy(r0, &amplifier_interface_fn, sizeof(Amplifier_Interface_Functions));
	}
	//loc_2343b96a
	if (r6 != 0)
	{
		memcpy(r6, &Data_235fc28c.Data_235fc298, sizeof(Data_235fc28c.Data_235fc298));
	}
	//loc_2343b97a
	if (r4 != 0)
	{
		*r4 = Data_235fc28c.Data_235fc408.bData_235fc427;
	}
	//loc_2343b986
	if (r5 != 0)
	{
		*r5 = Data_235fc28c.Data_235fc408.bData_235fc429;
	}
	//loc_2343b98e
	return 0;
}


/* 2343b992 - todo */
int amplifier_switch_powermode(int r0)
{
#if 0
	console_send_string("amplifier_switch_powermode (todo.c): TODO\r\n");
#endif

	if (r0 != 0)
	{
		if (amplifier_interface_fn.shutdown != 0)
		{
			(amplifier_interface_fn.shutdown)();
		}
	}
	else
	{
		sub_2343b822();
	}

	return 0;
}


/* 2343b9ae / 2345eb56 - todo */
void sub_2343b9ae(void (*p)())
{
#if 0
	console_send_string("sub_2343b9ae (todo.c): TODO\r\n");
#endif

	Data_23492d6c = p;
}


/* 2343b9b6 - todo */
int sub_2343b9b6(uint8_t a)
{
#if 0
	console_send_string("sub_2343b9b6 (todo.c): TODO\r\n");
#endif

	Data_235fc28c.Data_235fc298.arEqualizerSettings[Data_235fc28c.Data_235fc408.bData_235fc429].bData_0x11 = a;

	amplifier_set_bass(0xff);

	return 0;
}


/* 2343b9d6 - todo */
void amplifier_set_interface_functions(int r4)
{
#if 0
	console_send_string("amplifier_set_interface_functions (todo.c): TODO\r\n");
#endif

	memset(&amplifier_interface_fn, 0, sizeof(amplifier_interface_fn));

	if (r4 == 0)
	{
		amplifier_interface_fn.Data_235fc430 = sub_2343b7fe;
		amplifier_interface_fn.shutdown = cs4524_shutdown;
		amplifier_interface_fn.Data_235fc434 = amplifier_set_bass;
		amplifier_interface_fn.Data_235fc438 = 0;
		amplifier_interface_fn.Data_235fc43c = sub_2343b4bc;
		amplifier_interface_fn.Data_235fc440 = amplifier_set_treble;
		amplifier_interface_fn.Data_235fc444 = sub_2343b28c;
		amplifier_interface_fn.Data_235fc448 = amplifier_power_control;
		amplifier_interface_fn.Data_235fc44c = sub_2343b3c4;
		amplifier_interface_fn.Data_235fc450 = sub_2343b9b6;
		amplifier_interface_fn.Data_235fc454 = sub_2343b364;
		amplifier_interface_fn.Data_235fc458 = sub_2343b6b2;
		amplifier_interface_fn.Data_235fc464 = sub_2343b7b8;
		amplifier_interface_fn.Data_235fc460 = sub_2343b7e6;
		amplifier_interface_fn.Data_235fc45c = sub_2343b81a;
	}
}


/* 2343ba6a - todo */
int sub_2343ba6a(void)
{
#if 0
	console_send_string("sub_2343ba6a (todo.c): TODO\r\n");
#endif

	int res = i2c_master_read_reg(main_hI2c0, 0x20, 0x7f, 
					&Data_235fc28c.Data_235fc408.bData_235fc408, 1);

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2343ba6a: res=%d, bData_235fc408=0x%02x\r\n", 
			res, Data_235fc28c.Data_235fc408.bData_235fc408);
		console_send_string(debug_string);
	}
#endif

	if (res == 0)
	{
		//0x2343ba84
		Data_235fc28c.Data_235fc408.i2cAddr = 0x20;
		Data_235fc28c.Data_235fc408.bData_235fc408 = 0x05;
		Data_235fc28c.Data_235fc408.bData_235fc409 = 0x05;

		i2c_master_send(main_hI2c0, 0x20, 
			&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

		Data_235fc28c.Data_235fc408.bData_235fc408 = 0x04;
		Data_235fc28c.Data_235fc408.bData_235fc409 = 0x80;

		i2c_master_send(main_hI2c0, 0x20, 
			&Data_235fc28c.Data_235fc408.bData_235fc408, 2);

		return 0;
	}
	//loc_2343bab8
	return 8;
}


