

typedef struct Struct_23472f1c_Inner16
{
	int (*i2c_master_receive)(struct Struct_23472f1c_Inner16*, int addr, uint8_t* d, int count, int flags); //0
	int (*i2c_master_send)(struct Struct_23472f1c_Inner16*, int addr, uint8_t data[], int count, uint32_t flags); //4
	int (*i2c_read_reg)(struct Struct_23472f1c_Inner16*, int addr, int reg, uint8_t* d, int count); //8
	int (*i2c_write_reg)(struct Struct_23472f1c_Inner16*, int addr, int reg, void* data, uint32_t count); //12
	int (*i2c_write_reg_byte)(struct Struct_23472f1c_Inner16*, int addr, int reg, int data); //16 = 0x10
	uint8_t bData_0x14; //0x14 = 20
	uint8_t bData_0x15; //0x15 = 21
	int fill_0x18; //0x18
	void* Data_0x1c; //0x1c
	//32 = 0x20?
} Struct_23472f1c_Inner16;

typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	uint8_t bData_12; //12
	uint8_t bData_13; //13
	uint8_t bData_14; //14
	Struct_23472f1c_Inner16* Data_16; //16
	int fill_20; //20
	int Data_0x18; //0x18 = 24
	int Data_0x1c; //0x1c = 28
	int Data_0x20; //0x20 = 32
	int Data_0x24; //0x24 = 36
	int Data_0x28; //0x28 = 40
	int Data_0x2c; //0x2c = 44
	int Data_0x30; //0x30 = 48
	int fill_0x34[2]; //0x34 = 52
	int Data_0x3c; //0x3c = 60
	int Data_0x40; //0x40 = 64
	int Data_0x44; //0x44 = 68
	int fill_0x48; //0x48
	int Data_0x4c; //0x4c
	int fill_0x50; //0x50
	uint8_t bData_0x54; //0x54
	int fill_0x58; //0x58
	//0x5c = 92
} Struct_23472f1c;
//=
#if 0
typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int fill_8; //8
	uint8_t fill_12; //12
	uint8_t bData_13; //13
	uint8_t bData_14; //14
	void* Data_16; //16
	int fill_20[18]; //20
	//0x5c = 92
} Struct_23472ef0_4;
#endif


typedef struct
{
	int (*Data_0)(); //0
	void (*Data_4)(); //4
	void (*Data_8)(); //8
	void (*Data_12)(); //12
	int Data_0x10; //0x10 = 16
	int Data_0x14; //0x14 = 20
	uint8_t bData_0x18; //0x18 = 24
	int Data_0x1c; //0x1c = 28
	void* Data_0x20; //0x20 = 32
	uint8_t bData_0x24; //0x24 = 36
	int Data_0x28; //0x28 = 40
	void* Data_0x2c; //0x2c = 44
	//0x30, size?
} Struct_23442f9a_4;
//=
#if 0
typedef struct Struct_23442966_Inner4
{
	int (*Data_0)(struct Struct_23442966_Inner4*); //0

} Struct_23442966_Inner4;
#endif

typedef struct
{
	Struct_23472f1c* Data_0; //0
	/*Struct_23442966_Inner4*/Struct_23442f9a_4* Data_4; //4
	int Data_8; //8

} Struct_23442966;
//=
typedef struct
{
	void* Data_0; //0
	void* Data_4; //4
	int Data_8; //8

} Struct_23442940_4;


typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	int Data_12; //12
	int Data_0x10; //16 = 0x10
	void* Data_0x14; //0x14 = 20
	uint8_t bData_0x18; //0x18 = 24
	int Data_0x1c; //0x1c
	int Data_0x20; //0x20
	//0x24 = 36?
} Struct_23476318;


