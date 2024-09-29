
typedef struct 
{
    char Data_0[12]; //0
    uint32_t time_of_change_mjd; //0xc
    uint16_t weekDay; //0x10
    uint16_t day; //0x12
    uint16_t month; //0x14
    uint16_t year; //0x16
    uint16_t time_of_change_utc_hours; //0x18
    uint16_t time_of_change_utc_minutes; //0x1a
    uint16_t time_of_change_utc_seconds; //0x1c
    uint16_t fill_0x1e; //0x1e
	//32 = 0x20

} Struct_23419f50;


typedef struct 
{
	uint16_t next_time_offset; //0
	uint16_t local_time_offset; //2
    Struct_23419f50 Data_4; //4
    uint8_t country_code[4]; //0x24
    uint8_t country_region_id; //0x28
    uint8_t local_time_offset_polarity; //0x29

} Struct_23411b50;


