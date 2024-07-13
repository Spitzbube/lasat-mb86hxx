
typedef struct
{
	int (*Data_0)(); //0
	int (*Data_4)(); //4
	uint8_t bData_8[0x100]; //8, size??
	uint8_t bNumTextChars; //0x108
	uint8_t bDisplayOffset; //0x109
	uint8_t bNumDisplayChars; //0x10a
	uint8_t bData_0x10b; //0x10b
	uint8_t bData_0x10c; //0x10c
	uint8_t bScrollTimer; //0x10d
	uint8_t holdTime; //0x10e
	uint8_t bData_0x10f; //0x10f
	uint8_t bData_0x110; //0x110
	//0x114?
} FrontDisplay_Job;


extern void frontdisplay_task();

