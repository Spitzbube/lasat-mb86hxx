

typedef struct
{
	uint8_t* Data_0; //0
	uint16_t wData_4; //4
	//8
} Struct_23459098_Inner0;

typedef struct
{
    Struct_23459098_Inner0* Data_0; //0
    int fill_4; //4
    uint16_t wData_8; //8
    //12
} Struct_23459098;


typedef struct Struct_235b0b08
{
	int Data_0; //0
	int Data_4; //4
	int fill_8[3]; //8
	int Data_0x14; //0x14 = 20
	int fill_0x18[2]; //0x18 = 24
	void* (*Data_0x20)(struct Struct_235b0b08*); //0x20 = 32
	int (*Data_0x24)(struct Struct_235b0b08*); //0x24 = 36
	void (*Data_0x28)(struct Struct_235b0b08*); //0x28 = 40
	void* (*Data_0x2c)(struct Struct_235b0b08*); //0x2c = 44
	void (*Data_0x30)(); //0x30 = 48
	void* (*Data_0x34)(struct Struct_235b0b08*); //0x34 = 52
	int fill_0x38[2]; //0x38 = 56
	int Data_0x40; //0x40
	int Data_0x44; //0x44
	int Data_0x48; //0x48
	int Data_0x4c; //0x4c
	int Data_0x50; //0x50
	uint8_t bData_0x54; //0x54
    Struct_23459098 Data_0x58; //0x58
    int fill_0x64[37]; //0x64
    int Data_0xf8; //0x150

} Struct_235b0b08;


typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	uint8_t threadPrio; //12

} Struct_23418b54;


int ts_play_init(Struct_23418b54*);

