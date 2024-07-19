


struct Struct_236001c8
{
	char* Data_0; //0
	struct
	{
		uint16_t fill_0[132]; //0
		uint16_t wData_0x108; //0x108
		//0x10A = 266
	} Data_4[20]; //4
	uint8_t bData_0x14cc; //0x14cc
	int program_number; //0x14d0
	int version_number; //0x14d4
	int PCR_PID; //0x14d8
	struct Struct_236001c8_Inner_0x14e0* Data_0x14dc; //0x14dc
	struct Struct_236001c8_Inner_0x14e0
	{
		uint8_t* Data_0; //0
		uint8_t stream_type; //4
		uint8_t component_tag; //5
		uint16_t elementary_PID; //6
		uint8_t bData_8; //8
		uint8_t fill_9; //9
		char Data_0xa[206/*size??*/]; //10 = 0xa
		struct Struct_236001c8_Inner_0x14e0* next; //0xd8
		//220 = 0xdc
	} Data_0x14e0[50]; //0x14e0
	struct
	{
		int fill_0[13300]; //0
		//0xcfd0
	} Data_0x3fd8; //0x3FD8
	struct Struct_236001c8_Inner_0x10fa8
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint16_t* Data_4; //4
		//8
	} Data_0x10fa8[3]; //0x10fa8
	//0x10FC0 = 69568
};


struct Struct_236001c8* pmt_get_data(uint8_t);
