


typedef struct
{
	uint16_t fill_0; //0
	uint16_t transport_stream_id; //2
	uint16_t original_network_id; //4
	uint16_t service_id; //6
	struct Struct_2377b8d0_Inner8
	{
		int fill_0; //0
		struct Struct_2377b8d0_Inner8_Inner4
		{
			uint8_t bData_0; //0

		}* Data_4; //4
		struct Struct_2377b8d0_Inner8_Inner8
		{
			struct Struct_2377b8d0_Inner8_Inner8_Inner0
			{
				uint32_t* ISO_639_language_code; //0
				void* strName; //4
				void* strText; //8
				struct Struct_2377b8d0_Inner8_Inner8_Inner0* next; //12
				//16
			}* Data_0; //0
			struct Struct_2377b8d0_Inner8_Inner8_Inner4
			{
				void* Data_0; //0
				void* Data_4; //4
				struct Struct_2377b8d0_Inner8_Inner8_Inner4* next; //8
				//12?
			}* Data_4; //4

		}* Data_8; //8
		struct Component_Descriptor
		{
			struct Component_Descriptor* next; //0
			uint8_t stream_content; //4
			uint8_t component_type; //5
			uint8_t component_tag; //6
			int ISO_639_language_code; //8
			uint8_t text_char[20]; //12
			//32 = 0x20
		}* component_descriptor; //12 = 0xc
		struct Struct_2377b8d0_Inner8* next; //0x10 = 16
		uint16_t event_id; //0x14 = 20
		uint16_t wData_0x16; //0x16 = 22
		uint8_t table_id; //0x18 = 24
		uint8_t version_number; //0x19 = 25
		uint8_t section_number; //0x1a = 26
		uint8_t bData_0x1b; //0x1b = 27
		uint8_t bData_0x1c; //0x1c = 28
		uint8_t bData_0x1d; //0x1d = 29
		uint8_t bData_0x1e; //0x1e = 30
		uint8_t bData_0x1f; //0x1f = 31
		uint8_t bData_0x20; //0x20 = 32
		uint8_t bData_0x21; //0x21 = 33
		uint8_t running_status; //0x22 = 34
		uint8_t fill_0x23; //0x23 = 35
		//36 = 0x24
	}* Data_8; //8
	//12
} Struct_2377b8d0;


Struct_2377b8d0* eit_get_section_data(int service_id, int transport_stream_id);

