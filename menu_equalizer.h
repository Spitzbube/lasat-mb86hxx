

typedef struct
{
	int (*amplifier_get_data)(Amplifier_Interface_Functions*, Amplifier_Settings*, int, int); //238ddb2c
	Amplifier_Settings amplifierSettings; //4 = 238ddb30 +0x170 = 238DDCA0
	uint8_t bData_238ddca0; //0x174 = 238ddca0
	uint8_t bData_238ddca1; //0x175 = 238ddca1
	Amplifier_Interface_Functions amplifier_interface_fn; //0x178 = 238ddca4
	//???
} Struct_238ddb2c; //->238DDCE0

extern Struct_238ddb2c Data_238ddb2c; //238ddb2c address???


