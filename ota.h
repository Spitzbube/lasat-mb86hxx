
typedef struct
{
	uint8_t bData_0; //0
	int Data_4; //4
	void (*Data_8)(); //8

} Struct_2341413c;


typedef struct
{
	void* mbox; //0
	int Data_4; //4
	int fill_8; //8
	uint16_t wData_0xc; //12 = 0xc
	uint8_t bData_0xe; //14 = 0xe

} Struct_23414198;


typedef struct
{
	int sema; //0
	void (*Data_4)(int); //4
	void (*Data_8)(int); //8
	void (*Data_0xc)(); //12
	int (*Data_0x10)(); //0x10 16
	int (*Data_0x14)(); //20 0x14
	int fill_0x18; //24 0x18
	void (*Data_0x1c)(); //28 0x1c
	int fill_0x20[207]; //32 0x20
	Transponder Data_0x35c; //0x35c +0x18
	int fill_0x374[8597]; //0x374
	int Data_0x89c8; //0x89c8 = 2359544C
	uint16_t wData_0x89cc; //0x89cc
	uint16_t wData_0x89ce; //0x89ce
	uint16_t wData_0x89d0; //0x89d0
	int fill_0x89d4[213]; //0x89d4
	uint16_t wData_0x8d28; //0x8d28
	uint16_t wData_0x8d2a; //0x8d2a
	uint16_t wData_0x8d2c; //0x8d2c
	uint16_t wData_0x8d2e; //0x8d2e
	uint16_t wData_0x8d30; //0x8d30
	uint8_t bData_0x8d32; //0x8d32 = 235957B6
	uint8_t bData_0x8d33; //0x8d33 = 235957B7
	uint8_t fill_0x8d34; //0x8d34
	uint8_t bData_0x8d35; //0x8d35
	
} Struct_2358ca84; 


extern Struct_2358ca84* sub_23414244(void);
extern int sub_23414198(uint8_t r7, int bCreateMbox, int r8, uint16_t sb, Struct_23414198* r4);


