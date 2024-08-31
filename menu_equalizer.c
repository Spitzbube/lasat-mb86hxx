
#include "data.h"
#include "amplifier.h"
#include "frontdisplay.h"
#include "menu_equalizer.h"

#pragma thumb


static Menu_Item Data_23495c4c[]; //23495c4c
static int sub_2346fa40();
static int sub_2346fa54();

int Data_23495c10 = 0; //23495C10 -4

Menu menu_equalizer = //23495c14
{
		0x0192, //"Equalizer"
		&Data_23495c4c[0], //Menu_Item* Data_4; //4
		&Data_23495c4c[0], //Menu_Item* Data_8; //8
		0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
		0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
		0, //int Data_0x14; //20 = 0x14
		7, //uint8_t maxItem; //0x18 = 24 = 23495C2C
		0, //int8_t currentItem; //0x19 = 23495C2D
		0, //void (*Data_0x1c)(); //0x1c
		menu_items_navigate, 
		sub_2346fa40, //void (*onEnter)(); //36 = 0x24
		sub_2346fa54, //int (*onExit)(); //0x28
		1, //int Data_0x2c; //44 = 0x2c
		100, //int Data_0x30; //48
		0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
		//0x38 = 56?
}; //->23495C4C

static int sub_2346f9a6(int);
static void sub_2346fa36(void);
Menu_Item Data_23495c4c[] = //23495c4c
{
	//[0]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_2346f9a6, //void* onEvent; //0x1c = 28
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
		sub_2346f9a6, //void* onEvent; //0x1c = 28
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
		sub_2346f9a6, //void* onEvent; //0x1c = 28
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
		sub_2346f9a6, //void* onEvent; //0x1c = 28
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
		sub_2346f9a6, //void* onEvent; //0x1c = 28
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
		sub_2346f9a6, //void* onEvent; //0x1c = 28
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
		sub_2346f9a6, //void* onEvent; //0x1c = 28
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
		sub_2346f9a6, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_2346fa36, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	}, //->0x23495dac
}; 

//TODO!!!
Menu Data_2349c158 = //2349c158
{
		0x0192, //"Equalizer"
		&Data_23495c4c[0], //Menu_Item* Data_4; //4
		&Data_23495c4c[0], //Menu_Item* Data_8; //8
		0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
		0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
		0, //int Data_0x14; //20 = 0x14
		7, //uint8_t maxItem; //0x18 = 24 = 23495C2C
		0, //int8_t currentItem; //0x19 = 23495C2D
		0, //void (*Data_0x1c)(); //0x1c
		menu_items_navigate, 
		sub_2346fa40, //void (*onEnter)(); //36 = 0x24
		sub_2346fa54, //int (*onExit)(); //0x28
		1, //int Data_0x2c; //44 = 0x2c
		100, //int Data_0x30; //48
		0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
#if 0
		23495c14                        dw         0x0192                               ; DATA XREF=sub_2346f950+8, sub_2346f950+16, sub_2346f9a6+6, sub_2346f9a6+122, sub_2346fa36, sub_2346fa40, sub_2346fa58+36, sub_2346fac4+16, sub_2346fac4+28, sub_2346fac4+40, dword_2346fb20
		23495c16 0000                   movs       r0, r0
		23495c18                        dd         0x23495c4c
		23495c1c                        dd         0x23495c4c
		23495c20                        dd         0x00000000
		23495c24                        dd         0x00000000
		23495c28                        dd         0x00000000
		                            byte_23495c2c:
		23495c2c                        db         0x07                                 ; DATA XREF=sub_2346fa58+42
		                            byte_23495c2d:
		23495c2d                        db         0x00                                 ; DATA XREF=sub_2346f9a6+10, sub_2346fac4+20
		23495c2e 0000                   movs       r0, r0
		23495c30                        dd         0x00000000
		23495c34                        dd         sub_2343d4c8+1
		23495c38                        dd         sub_2346fa40+1
		23495c3c                        dd         sub_2346fa54+1
		23495c40                        dd         0x00000001
		23495c44                        dd         0x00000064
		23495c48                        dd         0x00000000
#endif
		//0x38 = 56?
};

Struct_238ddb2c Data_238ddb2c; //238ddb2c address???


/* 2346f90c - todo */
void* sub_2346f90c(FrontDisplay_Job* r5)
{
#if 0
	console_send_string("sub_2346f90c (todo.c): TODO\r\n");
#endif

	snprintf(r5->bData_8, 0x100, "%s",
		&Data_238ddb2c.amplifierSettings.arEqualizerSettings[menu_equalizer.currentItem].strName[0]);

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
int sub_2346f9a6(int a)
{
#if 0
	console_send_string("sub_2346f9a6 (todo.c): TODO\r\n");
#endif

	if (a != 0)
	{
		Data_238ddb2c.bData_238ddca1 = menu_equalizer.currentItem;

		Amplifier_Interface_Functions* r6 = &Data_238ddb2c.amplifier_interface_fn;

		if (r6->Data_235fc430 != 0)
		{
			(r6->Data_235fc430)(Data_238ddb2c.bData_238ddca1);
		}
		//loc_2346f9c2
		if (r6->Data_235fc434 != 0)
		{
			(r6->Data_235fc434)(
				Data_238ddb2c.amplifierSettings.arEqualizerSettings[Data_238ddb2c.bData_238ddca1].bBass);
		}
		//loc_2346f9d6
		if (r6->Data_235fc440 != 0)
		{
			(r6->Data_235fc440)(
				Data_238ddb2c.amplifierSettings.arEqualizerSettings[Data_238ddb2c.bData_238ddca1].bTreble);
		}
		//loc_2346f9e8
		if (r6->Data_235fc43c != 0)
		{
			(r6->Data_235fc43c)(
				Data_238ddb2c.amplifierSettings.arEqualizerSettings[Data_238ddb2c.bData_238ddca1].bData_0x10);
		}
		//loc_2346f9fa
		if (r6->Data_235fc450 != 0)
		{
			(r6->Data_235fc450)(
				Data_238ddb2c.amplifierSettings.arEqualizerSettings[Data_238ddb2c.bData_238ddca1].bData_0x11);
		}
		//loc_2346fa0c
		if (r6->Data_235fc438 != 0)
		{
			(r6->Data_235fc438)(
				Data_238ddb2c.amplifierSettings.arEqualizerSettings[Data_238ddb2c.bData_238ddca1].bData_0xf);
		}
		//->loc_2346fa2a
		return 0xff;
	}
	//loc_2346fa20
	else if (Data_23495c10 == 0)
	{
		return 0xff;
	}
	else
	{
		//loc_2346fa2e
		Data_23495c10--;
		return 0;
	}
}


/* 2346fa36 - todo */
void sub_2346fa36(void)
{
#if 1
	console_send_string("sub_2346fa36 (todo.c): TODO\r\n");
#endif

	Data_23495c10 = 5;
}


/* 2346fa40 - todo */
int sub_2346fa40()
{
#if 1
	console_send_string("sub_2346fa40 (todo.c): TODO\r\n");
#endif

	Data_23495c10 = 5;

	frontdisplay_start_text(sub_2346f950);

	return 0;
}


/* 2346fa54 - todo */
int sub_2346fa54()
{
#if 1
	console_send_string("sub_2346fa54 (todo.c): TODO\r\n");
#endif

	return 0;
}


/* 2346fa58 - todo */
void sub_2346fa58(int (*r5)(Amplifier_Interface_Functions*, int, int, int))
{
#if 0
	console_send_string("sub_2346fa58 (todo.c): TODO\r\n");
#endif

	Data_238ddb2c.amplifier_get_data = r5;

	if (Data_238ddb2c.amplifier_get_data == 0)
	{
		//loc_2346fac2
		return;
	}

	if (0 != (Data_238ddb2c.amplifier_get_data)(&Data_238ddb2c.amplifier_interface_fn,
			&Data_238ddb2c.amplifierSettings,
			&Data_238ddb2c.bData_238ddca0,
			&Data_238ddb2c.bData_238ddca1))
	{
		//loc_2346fac2
		return;
	}
	//0x2346fa72
	strcpy(&Data_238ddb2c./*Data_238ddbe8[0].bData_238ddbe8[0]*/amplifierSettings.Data_0xb8[0].arData_0[0], "RADIO");

	menu_equalizer.maxItem = 0;

	uint32_t i;
	for (i = 0; i < 8; i++)
	{
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2346fa58: %d='%s'\r\n",
				i, &Data_238ddb2c.amplifierSettings.arEqualizerSettings[i].strName[0]);
		console_send_string(debug_string);
	}
#endif
		//loc_2346fa84
		if (Data_238ddb2c./*Data_8[i].bData_0*/amplifierSettings.arEqualizerSettings[i].strName[0] == 0)
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

	Data_2349c158.maxItem/*2349c170*/ = 0;

	for (i = 0; i < 9; i++)
	{
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2346fa58: %d='%s'\r\n",
				i, &Data_238ddb2c.amplifierSettings.Data_0xb8[i].arData_0[0]);
		console_send_string(debug_string);
	}
#endif
		//loc_2346faa4
		if (Data_238ddb2c./*Data_238ddbe8[i].bData_238ddbe8[0]*/amplifierSettings.Data_0xb8[i].arData_0[0] == 0)
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
	Data_2349c158.maxItem/*2349c170*/ = i;
}


/* 2346fac4 - todo */
int sub_2346fac4(int a)
{
#if 1
	console_send_string("sub_2346fac4 (todo.c): TODO\r\n");
#endif

	if (Data_238ddb2c.amplifier_get_data == 0)
	{
		return 8;
	}
	//loc_2346fad2
	menu_equalizer.currentItem = Data_238ddb2c.bData_238ddca1;

	sub_2343d482(&menu_equalizer);
	sub_2343d3ac(&menu_equalizer);
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

	if (Data_238ddb2c.amplifier_get_data == 0)
	{
		//loc_2346fb1c
		return 8;
	}
	//0x2346fb00
	if (0 == Data_238ddb2c./*Data_238ddbe8*/amplifierSettings.Data_0xb8[ Data_238ddb2c.bData_238ddca0 ].bData_0x11)
	{
		strcpy(a, &Data_238ddb2c./*Data_238ddbe8*/amplifierSettings.Data_0xb8[ Data_238ddb2c.bData_238ddca0 ].arData_0[0]);

		return 0;
	}
	//loc_2346fb1c
	return 8;
}


