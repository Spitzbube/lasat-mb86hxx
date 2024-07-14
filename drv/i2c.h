
typedef struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	int clkPin; //4
	int dataPin; //8

} Struct_2341cd7c;


typedef struct
{
	Struct_20611068* clkGpio; //0
	Struct_20611068* dataGpio; //4
	uint8_t bData_8; //8
	uint8_t bData_9; //9
	uint8_t bData_10; //10
	uint8_t bData_11; //11
	uint8_t* pRxData; //12
	uint8_t* pTxData; //16
	OS_EVENT* sema; //20
	int dwErrorStatus; //24
	uint8_t bData_28; //28
   //32
} I2c_Bus;

