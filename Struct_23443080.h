
typedef struct
{
	uint8_t tuner_init_OK; //0
	uint8_t tuner_dev_addr; //1
	uint32_t Data_4; //4
	int16_t wData_8; //8
	uint8_t bData_10; //10 = 0x0a
	uint8_t bData_11; //11 = 0x0b
	uint8_t bData_0x0c; //12 = 0x0c
	uint8_t bData_0x0d; //13 = 0x0d
	int tuner_crystal; //16 = 0x10
	int tuner_dac; //20 = 0x14
	uint8_t bData_0x18; //24 = 0x18
	uint8_t bData_0x19; //25 = 0x19
	uint8_t bData_0x1a; //26 = 0x1a
	uint8_t bData_0x1b; //27 = 0x1b
	uint8_t bData_0x1c; //28 = 0x1c
	uint8_t bData_0x1d; //29 = 0x1d
	uint8_t bData_0x1e; //30 = 0x1e
	uint16_t Data_0x20; //32 = 0x20
	uint16_t chipId; //34 = 0x22
	uint16_t wData_0x24; //36 = 0x24
	int Data_0x28; //40 = 0x28
	int Data_0x2c; //44 = 0x2c
	uint8_t bData_0x30; //48 = 0x30
	uint32_t Data_0x34; //52 = 0x34
	uint8_t bData_0x38; //0x38
	uint8_t bData_0x39; //0x39
	uint32_t Data_0x3c; //0x3c
	int Data_0x40; //0x40
	int fill_0x44[10]; //0x44
	void (*WriteReg)(); //108 = 0x6c
	void (*ReadReg)(); //112 = 0x70
	uint8_t demod_address; //116 = 0x74
	//0x78 = 120
} Struct_23443080;


typedef struct
{
	void (*Data_0)(Struct_23443080*, int); //0
	int (*Data_4)(); //4
	void (*Data_8)(); //8
	//12 = 0x0c
} Struct_23491e28_Inner_0x98;


typedef struct
{
	struct
	{
		Struct_23491e28_Inner0 Data_0; //0
		Struct_23491e28_Inner0* Data_0x10; //16 = 0x10
		uint8_t bData_0x14; //20 = 0x14
		uint8_t bData_0x15; //21 = 0x15
 		int fill_0x18[2]; //24 = 0x18
		//32
	} Data_0; //0
	Struct_23443080 Data_0x20; //0x20 == 32
	const Struct_23491e28_Inner_0x98* Data_0x98; //0x98 = 152
	uint8_t tuner_dev_addr; //0x9c
	uint8_t demod_address; //0x9d
	//0xa0 = 160
} Struct_23491e28;


