

typedef struct
{
	void* Data_0; //0
	uint16_t wData_4; //4
	int fill_8; //8
	void (*Data_12)(); //12

} Struct_23410148;

typedef struct
{
	uint16_t threadPrio; //0
	uint8_t bData_2;

} Scan_Params;


void scan_init(Scan_Params* pParams);
