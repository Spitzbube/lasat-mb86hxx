

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


int fatfs_init(int);
int fatfs_volume_add_usb_device(USB_MSD_Interface*);
int fatfs_volume_remove_usb_device(int);
int sub_234168fc(int, Struct_234168fc*);


