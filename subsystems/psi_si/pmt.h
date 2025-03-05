
typedef struct PMT_ElementaryStream
{
	uint8_t* Data_0; //0
	uint8_t stream_type; //4
	uint8_t component_tag; //5
	uint16_t elementary_PID; //6
	uint8_t ac3_component_type; //8
	uint8_t bData_9; //9
	char language[3]; //10 = 0x0a
	char bData_0x0d; //13 = 0xd
	char Data_0xe[198]; //14 = 0xe
	int Data_0xd4; //0xd4
	struct PMT_ElementaryStream* next; //0xd8
	//220 = 0xdc
} PMT_ElementaryStream;


struct Struct_236001c8
{
	char* Data_0; //0
	struct Struct_236001c8_Inner_4
	{
		uint16_t ca_system_id; //0
		uint16_t ca_pid; //2
		uint16_t fill_4; //4
		uint16_t wData_6; //6
		uint16_t arData_8[128]; //8
		uint16_t wData_0x108; //0x108
		//0x10A = 266
	} Data_4[20]; //4
	uint8_t bData_0x14cc; //0x14cc
	int program_number; //0x14d0
	int version_number; //0x14d4
	int PCR_PID; //0x14d8
	PMT_ElementaryStream* pFirstElementaryStreams; //0x14dc
	PMT_ElementaryStream arElementaryStreams[50]; //0x14e0
	struct Struct_236001c8_Inner_0x3fd8
	{
		int fill_0; //0
		uint16_t fill_4; //4
		uint16_t wData_6; //6
		int fill_8[1328]; //8
		//0x14c8
	} Data_0x3fd8[10]; //0x3FD8 +0x0a*0x14c8=0xcfd0
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
