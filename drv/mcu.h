
typedef struct
{
	int Data_0; //0
	uint8_t bData_4; //4
	uint8_t bData_5; //5
	uint8_t bData_6; //6
	uint8_t bData_7; //7
	uint8_t bData_8; //8
	uint8_t bData_9; //9
	uint8_t bData_0xa; //10
	uint8_t bData_0xb; //11
	uint8_t Data_12[8]; //12
	//20
} Struct_23434e00;


int clkpwr_mcu_read(Struct_23434e00*);
void clkpwr_mcu_write(Struct_23434e00*, uint8_t, uint8_t, uint8_t*);
