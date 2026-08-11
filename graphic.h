

typedef struct
{
	int Data_0; //0
	int osd2globalOffset; //4
	int Data_8; //8
	int osd1globalOffset; //12
	void (*Data_16)(); //16
	uint16_t threadPrio; //20

} Graphic_Params;

typedef struct
{
	void* pClut; //0

} Graphic_Color_Data;

typedef struct
{
	int Data_0; //0
	uint16_t wData_4; //4
	uint16_t wData_6; //6
	void (*Data_8)(void*, uint8_t); //8
	//???
} Struct_2377ded0_Inner_0x1c_Inner_8;

typedef struct
{
	uint16_t wData_0; //0
	int Data_4; //4
	uint8_t bData_8; //8
	//???
} Struct_2377ded0_Inner_0x1c_Inner_0x18;

typedef struct
{
	uint8_t bData_0; //0
	uint16_t x1; //wData_2 = 2
	uint16_t y1; //wData_4 = 4
	uint16_t x2; //wData_6 = 6
	uint16_t y2; //wData_8 = 8
	uint8_t fill_0xa; //10
	uint8_t bData_0xb; //11
	uint8_t bData_0xc; //12
	uint8_t bData_0xd; //13
	uint8_t* pString; //16 = 0x10
	uint16_t wData_0x14; //20 = 0x14
	uint8_t bData_0x16; //22 = 0x16
	uint8_t bData_0x17; //23 = 0x17
	//0x18
} Graphic_Job_2_5_Item_Text; //Struct_2377ded0_Inner_0x1c_Inner_0x20;

typedef struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	int Data_4; //4
	Struct_2377ded0_Inner_0x1c_Inner_8* Data_8; //8
	uint16_t x; //0xc = 12
	uint16_t y; //0xe = 14
	uint16_t width; //0x10 = 16
	uint16_t height; //0x12 = 18
	int fill_0x14; //0x14
	Struct_2377ded0_Inner_0x1c_Inner_0x18* Data_0x18; //0x18
	uint16_t wColor; //0x1c
	uint16_t wData_0x1e; //0x1e
	Graphic_Job_2_5_Item_Text* Data_0x20; //0x20
	Graphic_Job_2_5_Item_Text Data_0x24; //0x24 +0x18
	uint8_t bData_0x3c; //0x3c
	//0x40
} Graphic_Job_2_5_Item; //Struct_2377ded0_Inner_0x1c;

typedef struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	uint16_t wData_2; //2
	uint8_t bData_4; //4
	Graphic_Job_2_5_Item* pItems; //8
	Graphic_Color_Data* pColorData; //12
	uint8_t numColors; //0x10 = 16
	int fill_0x14; //0x14 = 20
	uint8_t bNumItems; //0x18 = 24
	uint8_t bData_0x19; //0x19 = 25
	void (*unlock)(); //0x1c
	void (*lock)(); //0x20
	//???
} Graphic_Job_2_5;

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
extern int graphic_start_job_2_5(Graphic_Queue_Item*, Graphic_Job_2_5*);
extern int sub_23414c24(Graphic_Queue_Item*, Struct_23414c24*);

