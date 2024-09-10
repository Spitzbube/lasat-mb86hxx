

typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	int Data_12; //12
	void (*Data_16)(); //16
	uint16_t threadPrio; //20

} Graphic_Params;

typedef struct
{
	void* Data_0; //0

} Struct_23414b38_b_Inner_0xc;

typedef struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	uint16_t wData_2; //2
	uint8_t bData_4; //4
	Struct_2377ded0_Inner_0x1c* Data_8; //8
	Struct_23414b38_b_Inner_0xc* Data_0xc; //12
	uint8_t bData_0x10; //0x10 = 16
	int fill_0x14; //0x14 = 20
	uint8_t bData_0x18; //0x18 = 24
	uint8_t bData_0x19; //0x19 = 25
	int fill_0x1c; //0x1c
	int fill_0x20; //0x20
	//???
} Struct_23414b38_b;

typedef struct
{
	uint8_t fill_0; //0
	uint8_t bData_1; //1
	//???
} Struct_23414c24;


typedef struct
{
	void* pPayload; //0
	int command; //4
	int Data_8; //8
	int Data_0xc; //12
	//16
} Graphic_Queue_Item;


extern int graphic_init(Graphic_Params*);
extern int sub_23414b38(Graphic_Queue_Item*, Struct_23414b38_b*);
extern int sub_23414c24(Graphic_Queue_Item*, Struct_23414c24*);

