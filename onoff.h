
typedef struct
{
	int gpioPin; //0
	int initialState; //4
	int (*Data_8)(int); //8
	int (*Data_12)(int); //12
#if 0
	void (*Data_16)(int); //16
	void (*Data_20)(int); //20
#endif
	//24
} Struct_23413284;

