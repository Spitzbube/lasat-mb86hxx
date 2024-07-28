

typedef struct
{
	struct
	{
		uint8_t bData_0; //0
		uint8_t service_name[20]; //1
		uint8_t service_provider_name[10]; //21
		//31
	} Data_0[150]; //0
	struct SDT_Service
	{
		uint16_t service_id; //0
		uint8_t free_CA_mode; //2
		uint8_t EIT_schedule_flag; //3
		uint8_t EIT_present_following_flag; //4
		int fill_8[2]; //8
		struct SDT_Service_Inner_0x10
		{
			uint8_t bData_0; //0
			uint8_t service_type; //1
			uint8_t* service_provider_name; //4
			uint8_t* service_name; //8
			//12
		}* Data_0x10; //16 = 0x10
		void* next; //20 = 0x14
		//24
	} service[150]; //0x122c
	struct SDT_Service_Inner_0x10 Data_0x203c[150]; //0x203c
	struct
	{
		int fill_0[30]; //0

	} Data_0x2744; //0x2744
	struct Struct_23622188_Inner_0x27bc
	{
		uint8_t fill_0; //0
		uint8_t table_id; //1 = 0x27bd
		uint16_t transport_stream_id; //2 = 0x27be
		uint16_t original_network_id; //4 = 0x27c0
		struct SDT_Service* Data_8; //8 = 0x27c4
		//12
	} Data_0x27bc; //0x27BC
	//0x27C8
} Struct_23622188;


struct Struct_23622188_Inner_0x27bc* sub_2344cd54(uint8_t);


