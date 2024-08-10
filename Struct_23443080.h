

typedef struct
{
	void (*tuner_set)(MT_FE_Tuner_Handle_TC3800, int); //0
	int (*tuner_get_strength)(); //4
	void (*tuner_sleep)(); //8
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
		double fBER; //24 = 0x18
		//32
	} Data_0; //0
	MT_FE_TN_DEVICE_SETTINGS_TC3800 Data_0x20; //0x20 == 32
	const Struct_23491e28_Inner_0x98* Data_0x98; //0x98 = 152
	uint8_t tuner_dev_addr; //0x9c
	uint8_t demod_address; //0x9d
	//0xa0 = 160
} Struct_23491e28;


