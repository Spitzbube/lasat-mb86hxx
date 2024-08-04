

typedef struct Struct_23627118_Inner0x18
{
	uint16_t network_id; //24 = 0x18
	int16_t wData_0x1a; //26 = 0x1a
	uint16_t fill_0x1c; //28 = 0x1c
	uint8_t fill_0x1e; //0x1e
	uint8_t network_name[50]; //0x1f
} NIT_NetworkData;


typedef struct Struct_23627118_Inner0x54
{
	uint16_t transport_stream_id; //0
	uint16_t original_network_id; //2
	uint16_t wData_4; //4
	uint32_t frequency; //8
	int fill_0xc; //12
	uint32_t symbol_rate; //16 = 0x10
	uint16_t fill_0x14; //20 = 0x14
	uint8_t fill_0x16; //22 = 0x16
	uint8_t modulation; //23 = 0x17
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
} NIT_TransportStream;


typedef struct
{
	uint16_t wData_0; //0
	uint16_t wData_2; //2
	uint16_t wData_4; //4
	uint8_t bData_6; //6
	uint8_t bData_7; //7
} Struct_23627118_Inner8;

typedef struct
{
	uint16_t wData_0; //0
	uint16_t fill_2; //2
	uint16_t fill_4; //4
	uint8_t bData_6; //6
	Struct_23627118_Inner8 Data_8; //8;
	Struct_23627118_Inner8 Data_0x10; //16 = 0x10
	NIT_NetworkData networkData; //0x18
	NIT_TransportStream arTransportStreams[200]; //0x54 -> 50E14
	int fill_0x50e14; //0x50E14
	//0x50E18
} Struct_23627118;


typedef struct
{
	Struct_23627118* Data_0; //0
	NIT_NetworkData* pNetworkData; //4
	NIT_TransportStream* pTransportStream; //8
	//12
} Struct_2344dc3c;


typedef struct 
{
	Struct_23627118_Inner8* Data_0; //0
	NIT_NetworkData* pNetworkData; //4
	NIT_TransportStream* pTransportStream; //8
	//12
} Struct_2344dbdc;


int sub_2344dc3c(uint8_t, Struct_2344dc3c*);
int sub_2344dbdc(uint8_t, Struct_2344dbdc*);
int sub_2344dc7c(uint8_t, Struct_2344dbdc*);
void sub_2344dcf4(uint8_t, int);


