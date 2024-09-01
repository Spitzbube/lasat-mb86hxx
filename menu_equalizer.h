

typedef struct
{
	int (*amplifier_get_data)(Amplifier_Interface_Functions*, Amplifier_Settings*, int, int); //0 = 238ddb2c
	Amplifier_Settings amplifierSettings; //4 = 238ddb30 +0x170 = 238DDCA0
	uint8_t bInput; //0x174 = 238ddca0
	uint8_t bEqualizer; //0x175 = 238ddca1
	//???
} Menu_Amplifier_Data; //->238DDCE0

extern Menu_Amplifier_Data menu_amplifier_data; //238ddb2c
extern Amplifier_Interface_Functions menu_amplifier_interface_fn; //238ddca4


