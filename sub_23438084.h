

typedef struct
{
	OS_EVENT* sema; //0
	uint32_t length; //4
	uint8_t* data; //8
	Struct_235f2e2c* pFlash; //12
	uint32_t Data_16; //16
	int Data_20; //20
	//0x18 = 24
} Struct_23438084;

typedef struct
{
	void* pData; //0
	int crc; //4
	int Data_8; //8
	int Data_12; //12
	int Data_16; //16
	//20
} Struct_235f3784_Inner_0x18;

typedef struct
{
	Struct_23438084 Data_0; //0
	Struct_235f3784_Inner_0x18 Data_24[10]; //24 = 0x18
//	int Data_24[50]; //24 = 0x18
	//0xe0 = 224
} Struct_235f3784;

typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	Struct_235f2e2c* pFlash; //12
	void* Data_16; //16

} Struct_23437fd4;

void* sub_23437fd4(Struct_23437fd4*);

int sub_23438084(Struct_23438084* p, void* buf, uint32_t offset, uint32_t count);
int sub_23438108(Struct_23438084* p, void* buf, uint32_t offset, uint32_t count);

