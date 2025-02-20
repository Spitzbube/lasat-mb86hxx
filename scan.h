

typedef struct
{
	void* Data_0; //0
	uint16_t wData_4; //4
	int Data_8; //8
	void (*Data_12)(); //12
	uint8_t bData_16; //16

} Struct_23410148;

typedef struct
{
	uint16_t threadPrio; //0
	uint8_t bData_2;

} Scan_Params;


typedef struct
{
	PSI_Program* pPsiProgram; //0 = sp_0x28
	Transponder* pTransponder; //4 = sp_0x2c
	int Data_8; //8 = sp_0x30
	uint16_t wData_12; //12 = sp_0x34

} Scan_New_Channel;


#define SCAN_PROGRESS_CALLBACK_CHANNELS 1
#define SCAN_PROGRESS_CALLBACK_TRANSPONDER 2
#define SCAN_PROGRESS_CALLBACK_STATE 3

typedef struct
{
	uint16_t total; //0
	uint16_t current; //2
	Transponder* pTransponder; //4
	//8
} Scan_Progress_Transponder;

typedef struct
{
	uint32_t state; //0
	//4
} Scan_Progress_State; 


void scan_init(Scan_Params* pParams);
int sub_23410148(Struct_23410148* r5, int r6, void (*r7)(), int r8);
