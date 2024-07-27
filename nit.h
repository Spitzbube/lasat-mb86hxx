


typedef struct
{
	int fill_0; //0
	uint16_t fill_4; //4
	uint8_t bData_6; //6
	struct
	{
		int fill_0[2]; //0
	} Data_8; //8;
	struct
	{
		int fill_0[2]; //0
	} Data_0x10; //16 = 0x10
	struct Struct_23627118_Inner0x18
	{
		uint16_t network_id; //24 = 0x18
		int16_t wData_0x1a; //26 = 0x1a
		uint16_t fill_0x1c; //28 = 0x1c
		uint8_t fill_0x1e; //0x1e
		uint8_t network_name[50]; //0x1f
	} Data_0x18;
	struct Struct_23627118_Inner0x54
	{
		uint16_t transport_stream_id; //0
		uint16_t original_network_id; //2
		uint16_t wData_4; //4
		uint32_t frequency; //8
		int fill_0xc; //12
		uint32_t symbol_rate; //16 = 0x10
		uint16_t fill_0x14; //20 = 0x14
		uint8_t fill_0x16; //22 = 0x16
		uint8_t bData_0x17; //23 = 0x17
		int fill_24[2]; //24 = 0x18
		uint16_t fill_0x20; //32 = 0x20
		uint8_t bNumServices; //34 = 0x22
		int fill_0x24[255]; //36 = 0x24
		struct service_list
		{
			uint16_t service_id; //0
			uint8_t service_type; //2
			//4
		} service_list[150]; //0x420 -> 0x678
		//0x678
	} Data_0x54[200]; //0x54 -> 50E14
	int fill_0x50e14; //0x50E14
	//0x50E18
} Struct_23627118;


typedef struct
{
	Struct_23627118* Data_0; //0
	struct Struct_23627118_Inner0x18* Data_4; //4
	struct Struct_23627118_Inner0x54* Data_8;
	//12
} Struct_2344dc3c;



int sub_2344dc3c(uint8_t, Struct_2344dc3c*);
void sub_2344dcf4(uint8_t, int);


