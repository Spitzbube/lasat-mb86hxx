
typedef struct Menu
{
	uint16_t stringId; //0
	Menu_Item* Data_4; //4
	Menu_Item* Data_8; //8
	Graphic_Job_2_5_Item* header; //12 = 0xc
	Graphic_Job_2_5_Item/*Struct_235fdf74_Inner16*/* help; //16 = 0x10
	Graphic_Job_2_5* graphicData; //20 = 0x14
	uint8_t maxItem; //0x18 = 24
	int8_t currentItem; //0x19
	int (*graphicHandler)(Graphic_Queue_Item*, void*); //0x1c
	int (*onNavigate)(int*); //0x20
	int (*onEnter)(int); //36 = 0x24
	int (*onExit)(UI_Thread_Params*); //0x28
	int Data_0x2c; //44 = 0x2c
	int timeout; //48 = 0x30
	Menu_Item* (*Data_0x34)(struct Menu*); //52
#ifdef VDR110
	//0x38 = 56?
#else
	void* (*Data_0x38)(struct FrontDisplay_Job*); //56
	//0x3c = 60?
#endif
} Menu;


struct Menu_Data
{
	UI_Thread_Params Data_235fdf58; //0 235fdf58 235fdf98 -0x40 23796784
	UI_Thread_Params* Data_235fdf70; //24 = 0x18 235fdf70 / 2378336C -0x40 + 0x18 2379679C
	Menu* menu_stack[13]; //28 = 0x1c 235fdf74 -0x40, size??? 237967A0
	uint8_t menu_stack_level; //80 = 0x50 235fdfa8 235fdf98 + 0x10 237967D4
	uint8_t bData_235fdfa9;

};


extern Menu* menu_stack_operate(Menu*);

#define MENU_STACK_PUSH(pMenu)      menu_stack_operate(pMenu)
#define MENU_STACK_POP()           menu_stack_operate(0)

extern void menu_initialize(Menu*);

