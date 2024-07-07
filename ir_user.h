
typedef struct
{
	unsigned char threadPrioUart; //0
	int fill_4; //4
	unsigned char threadPrioIR; //8
	unsigned char threadPrioUI_1; //9
	unsigned char threadPrioUI_2; //10
	unsigned char threadPrioUI; //11
	int fill_12[2]; //12
#if 0
	unsigned char bData_20; //20
	unsigned char bData_21; //21
#endif
	//24
} Struct_2340d784;

void* ir_user_init(Struct_2340d784*);
void inputhandler_register_uart_callback(int (*)(uint8_t*));

