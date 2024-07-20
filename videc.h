

typedef struct
{
	uint8_t bData_0; //0
	int Data_4; //4
	uint8_t bData_8; //8
	uint8_t bData_9; //9
	uint8_t bData_10; //10
	uint8_t bData_11; //11
	int Data_12; //12
	int Data_16; //16
	int Data_20; //20
	uint8_t bData_24; //24 = 0x18
	int Data_28[12]; //28 = 0x1c
	int fill_76[483]; //76 = 0x4c
	int Data_0x7d8; //0x7d8
	int Data_0x7dc; //0x7dc
	int Data_0x7e0; //0x7e0
	int Data_0x7e4; //0x7e4
	int Data_0x7e8; //0x7e8
	int Data_0x7ec; //0x7ec
	int Data_0x7f0; //0x7f0
	int Data_0x7f4; //0x7f4
	int Data_0x7f8; //0x7f8
	int Data_0x7fc[256]; //0x7fc
	int Data_0xbfc; //0xbfc
	uint8_t bData_0xc00; //0xc00
	int Data_0xc04; //0xc04
	int Data_0xc08; //0xc08
	uint8_t bData_0xc0c; //0xc0c
	uint8_t bData_0xc0d; //0xc0d
	uint8_t bData_0xc0e; //0xc0e
	uint8_t bData_0xc0f; //0xc0f
	//0xc10???
} Struct_234774c4;


typedef struct
{
	uint32_t Data_0; //0
	int Data_4; //4
	uint8_t bData_8; //8
	//12???
} Struct_234601cc;


typedef struct
{
	int Data_0; //0x2c
	int Data_4; //0x30
} Struct_2358bdd0;


typedef struct
{
	int Data_0; //0
	int Data_4; //4
	Struct_2358bdd0 Data_8; //8
	//16???
} Struct_23460180;


typedef struct
{
	void* hFlash; //0
	int Data_4; //4

} Struct_2345fd98;


void vdec_init(Struct_2345fd98*);
void videc_audcallback_h264();
void videc_audcallback_mpeg();


