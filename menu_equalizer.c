
#include <string.h>
#include "data.h"
#include "amplifier.h"
#include "frontdisplay.h"
#include "menu_equalizer.h"

#pragma thumb

extern Menu menu_amplifier_inputs; //2349c158

static Menu_Item menu_equalizer_items[]; //23495c4c
static int menu_equalizer_on_enter(void);
static int menu_equalizer_on_exit(void);

int menu_amplifier_hold = 0; //23495C10 -4

Menu menu_equalizer = //23495c14
{
		0x0192, //"Equalizer"
		&menu_equalizer_items[0], //Menu_Item* Data_4; //4
		&menu_equalizer_items[0], //Menu_Item* Data_8; //8
		0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
		0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
		0, //int Data_0x14; //20 = 0x14
		7, //uint8_t maxItem; //0x18 = 24 = 23495C2C
		0, //int8_t currentItem; //0x19 = 23495C2D
		0, //void (*Data_0x1c)(); //0x1c
		menu_items_navigate, 
		menu_equalizer_on_enter, //void (*onEnter)(); //36 = 0x24
		menu_equalizer_on_exit, //int (*onExit)(); //0x28
		1, //int Data_0x2c; //44 = 0x2c
		100, //int Data_0x30; //48
		0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
		//0x38 = 56?
}; //->23495C4C

static int menu_equalizer_on_event(int);
static void sub_2346fa36(void);
Menu_Item menu_equalizer_items[] = //23495c4c
{
	//[0]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_equalizer_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_2346fa36, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	}, //->23495C78
	//[1]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_equalizer_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_2346fa36, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	}, //->0x23495ca4
	//[2]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_equalizer_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_2346fa36, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	}, //->0x23495cd0
	//[3]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_equalizer_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_2346fa36, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	}, //->0x23495cfc
	//[4]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_equalizer_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_2346fa36, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	}, //->0x23495d28
	//[5]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_equalizer_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_2346fa36, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	}, //->0x23495d54
	//[6]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_equalizer_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_2346fa36, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	}, //->0x23495d80
	//[7]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_equalizer_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_2346fa36, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	}, //->0x23495dac
}; 

Menu_Amplifier_Data menu_amplifier_data; //238ddb2c address???
Amplifier_Interface_Functions menu_amplifier_interface_fn; //238ddca4


/* 2346f90c - todo */
void* sub_2346f90c(FrontDisplay_Job* r5)
{
#if 0
	console_send_string("sub_2346f90c (todo.c): TODO\r\n");
#endif

	snprintf(r5->bData_8, 0x100, "%s",
		&menu_amplifier_data.amplifierSettings.arEqualizerSettings[menu_equalizer.currentItem].strName[0]);

	r5->bNumTextChars = 12;
	r5->bDisplayOffset = 0;
	r5->bNumDisplayChars = 12;
	r5->bData_0x10b = 0;
	r5->bData_0x10c = 0;
	r5->bData_0x110 = 0;
	r5->holdTime = 0;
	r5->Data_0 = frontdisplay_draw_text;
	r5->Data_4 = 0;
	r5->bData_0x10f = 0;

	return sub_2346f90c;
}


/* 2346f950 - todo */
void* sub_2346f950(FrontDisplay_Job* r4)
{
#if 1
	console_send_string("sub_2346f950 (todo.c): TODO\r\n");
#endif

	r4->bData_8[0] = 0x22;

	text_table_get_string(menu_equalizer.stringId, &r4->bData_8[1], 0xfc);

	uint8_t len = strlen(r4->bData_8);

	r4->bData_8[len] = 0x22;
	len++;
	r4->bData_8[len] = 0;

	r4->bNumTextChars = strlen(r4->bData_8);
	r4->bDisplayOffset = 0;
	r4->bNumDisplayChars = 12;
	r4->bData_0x10b = 0;
	r4->bData_0x10c = 0;
	r4->bData_0x110 = 0;
	r4->holdTime = 20;
	r4->Data_0 = frontdisplay_draw_text;
	r4->Data_4 = 0;
	r4->bData_0x10f = 0;

	return sub_2346f90c;
}


/* 2346f9a6 - todo */
int menu_equalizer_on_event(int a)
{
#if 0
	console_send_string("menu_equalizer_on_event (todo.c): TODO\r\n");
#endif

	if (a != 0)
	{
		menu_amplifier_data.bEqualizer = menu_equalizer.currentItem;

		if (menu_amplifier_interface_fn.Data_235fc430 != 0)
		{
			(menu_amplifier_interface_fn.Data_235fc430)(menu_amplifier_data.bEqualizer);
		}
		//loc_2346f9c2
		if (menu_amplifier_interface_fn.Data_235fc434 != 0)
		{
			(menu_amplifier_interface_fn.Data_235fc434)(
				menu_amplifier_data.amplifierSettings.arEqualizerSettings[menu_amplifier_data.bEqualizer].bBass);
		}
		//loc_2346f9d6
		if (menu_amplifier_interface_fn.Data_235fc440 != 0)
		{
			(menu_amplifier_interface_fn.Data_235fc440)(
				menu_amplifier_data.amplifierSettings.arEqualizerSettings[menu_amplifier_data.bEqualizer].bTreble);
		}
		//loc_2346f9e8
		if (menu_amplifier_interface_fn.Data_235fc43c != 0)
		{
			(menu_amplifier_interface_fn.Data_235fc43c)(
				menu_amplifier_data.amplifierSettings.arEqualizerSettings[menu_amplifier_data.bEqualizer].bData_0x10);
		}
		//loc_2346f9fa
		if (menu_amplifier_interface_fn.Data_235fc450 != 0)
		{
			(menu_amplifier_interface_fn.Data_235fc450)(
				menu_amplifier_data.amplifierSettings.arEqualizerSettings[menu_amplifier_data.bEqualizer].bData_0x11);
		}
		//loc_2346fa0c
		if (menu_amplifier_interface_fn.Data_235fc438 != 0)
		{
			(menu_amplifier_interface_fn.Data_235fc438)(
				menu_amplifier_data.amplifierSettings.arEqualizerSettings[menu_amplifier_data.bEqualizer].bData_0xf);
		}
		//->loc_2346fa2a
		return 0xff;
	}
	//loc_2346fa20
	else if (menu_amplifier_hold == 0)
	{
		return 0xff;
	}
	else
	{
		//loc_2346fa2e
		menu_amplifier_hold--;
		return 0;
	}
}


/* 2346fa36 - todo */
void sub_2346fa36(void)
{
#if 1
	console_send_string("sub_2346fa36 (todo.c): TODO\r\n");
#endif

	menu_amplifier_hold = 5;
}


/* 2346fa40 - todo */
int menu_equalizer_on_enter(void)
{
#if 1
	console_send_string("menu_equalizer_on_enter (todo.c): TODO\r\n");
#endif

	menu_amplifier_hold = 5;

	frontdisplay_start_text(sub_2346f950);

	return 0;
}


/* 2346fa54 - todo */
int menu_equalizer_on_exit(void)
{
#if 0
	console_send_string("menu_equalizer_on_exit (todo.c): TODO\r\n");
#endif

	return 0;
}


/* 2346fa58 - todo */
void sub_2346fa58(int (*r5)(Amplifier_Interface_Functions*, int, int, int))
{
#if 0
	console_send_string("sub_2346fa58 (todo.c): TODO\r\n");
#endif

	menu_amplifier_data.amplifier_get_data = r5;

	if (menu_amplifier_data.amplifier_get_data == 0)
	{
		//loc_2346fac2
		return;
	}

	if (0 != (menu_amplifier_data.amplifier_get_data)(&menu_amplifier_interface_fn,
			&menu_amplifier_data.amplifierSettings,
			&menu_amplifier_data.bInput,
			&menu_amplifier_data.bEqualizer))
	{
		//loc_2346fac2
		return;
	}
	//0x2346fa72
	strcpy(&menu_amplifier_data.amplifierSettings.arInputs[0].strName[0], "RADIO");

	menu_equalizer.maxItem = 0;

	uint32_t i;
	for (i = 0; i < 8; i++)
	{
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2346fa58: %d='%s'\r\n",
				i, &menu_amplifier_data.amplifierSettings.arEqualizerSettings[i].strName[0]);
		console_send_string(debug_string);
	}
#endif
		//loc_2346fa84
		if (menu_amplifier_data./*Data_8[i].bData_0*/amplifierSettings.arEqualizerSettings[i].strName[0] == 0)
		{
			//->loc_2346fa96
			break;
		}
	}
	//loc_2346fa96
	if (i != 0)
	{
		i--;
	}
	//loc_2346fa9c
	menu_equalizer.maxItem = i;

	menu_amplifier_inputs.maxItem = 0;

	for (i = 0; i < 9; i++)
	{
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2346fa58: %d='%s'\r\n",
				i, &menu_amplifier_data.amplifierSettings.arInputs[i].strName[0]);
		console_send_string(debug_string);
	}
#endif
		//loc_2346faa4
		if (menu_amplifier_data.amplifierSettings.arInputs[i].strName[0] == 0)
		{
			//->loc_2346faba
			break;
		}
	} //for (i = 0; i < 9; i++)
	//->loc_2346fabe
	if (i != 0)
	{
		i--;
	}
	//loc_2346fac0
	menu_amplifier_inputs.maxItem = i;
}


/* 2346fac4 - todo */
int menu_equalizer_entry(int a)
{
#if 0
	console_send_string("menu_equalizer_entry (todo.c): TODO\r\n");
#endif

	if (menu_amplifier_data.amplifier_get_data == 0)
	{
		return 8;
	}
	//loc_2346fad2
	menu_equalizer.currentItem = menu_amplifier_data.bEqualizer;

	menu_stack_operate(&menu_equalizer);
	menu_initialize(&menu_equalizer);
	void* r1 = sub_2343d572();
	sub_2343d51e(&menu_equalizer, r1);

	return 0;
}


/* 2346faf6 - complete */
int sub_2346faf6(uint8_t* a)
{
#if 0
	console_send_string("sub_2346faf6 (todo.c): TODO\r\n");
#endif

	if (menu_amplifier_data.amplifier_get_data == 0)
	{
		//loc_2346fb1c
		return 8;
	}
	//0x2346fb00
	if (0 == menu_amplifier_data.amplifierSettings.arInputs[ menu_amplifier_data.bInput ].bData_0x11)
	{
		strcpy(a, &menu_amplifier_data.amplifierSettings.arInputs[ menu_amplifier_data.bInput ].strName[0]);

		return 0;
	}
	//loc_2346fb1c
	return 8;
}


