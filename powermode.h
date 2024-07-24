
typedef struct
{
	int gpioPin; //0
	int initialState; //4
	int (*pfOnSwitchOff)(int); //8
	int (*pfOnSwitchOn)(int); //12
	void (*Data_16)(int); //16
	void (*Data_20)(int); //20
	//24
} Powermode_Init_Params;

extern int powermode_init(Powermode_Init_Params*);
extern int powermode_set_onoff_callbacks(void* pfOnSwitchOff, void* pfOnSwitchOn);
