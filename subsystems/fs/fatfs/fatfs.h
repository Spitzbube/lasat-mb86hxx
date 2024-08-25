

typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	int fill_0xc; //0xc
	uint8_t bData_0x10; //0x10
	uint8_t arFileName[0x100]; //0x11 = 17
    //0x111???
} Struct_234168fc;

typedef struct
{
	uint8_t bData_0; //0
	uint16_t wData_2; //2
	uint32_t dwSize; //4
	uint32_t Data_8; //8
	int Data_0xc; //12
	uint32_t Data_0x10; //16
	int fill_0x14; //20
	int Data_0x18; //0x18 = 24
	int Data_0x1c; //0x1c
	int Data_0x20; //0x20
	int Data_0x24; //0x24
	int fill_0x28[2]; //0x28
	int Data_0x30; //0x30
	uint8_t bData_0x34; //0x34
	uint8_t arData_0x35[267]; //0x35, size???
	int Data_0x140; //0x140
	int Data_0x144; //0x144
	int Data_0x148; //0x148
	int fill_0x14c[2]; //0x14c
	struct Struct_235af5d0* Data_0x154; //0x154
	//0x158
} Struct_235af620;


int fatfs_init(int);
int fatfs_volume_add_usb_device(USB_MSD_Interface*);
int fatfs_volume_remove_usb_device(int);
int sub_234168fc(int, Struct_234168fc*);
int sub_234160e8(/*Struct_235af620*/void**, char*, int, int);

