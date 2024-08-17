
typedef struct
{
	int (*read)(void* h, uint32_t dwStartBlockLo, void* pBuffer, uint16_t wBlockCount); //0
	int (*write)(void* h, uint32_t dwStartBlockLo, void* pBuffer, uint16_t wBlockCount); //4
	void (*Data_8)(); //8
	void (*Data_12)(); //12
	void (*Data_16)(); //16
	void (*Data_20)(); //20
	USB_MSD_Device* Data_0x18; //24
} Struct_23415f44;

