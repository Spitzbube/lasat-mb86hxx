
#include "data.h"
#include "menu.h"
#include "frontdisplay.h"
#include "sub_2340a6a0.h"
#include "channel_list_update.h"

#pragma thumb


static int on_channel_list_update_change();
static int on_deep_standby_change();
static int on_auto_standby_change();
static void get_deep_standby_value_string();
static void get_channel_list_update_value_string();
static void get_auto_standby_value_string();
static int on_menu_enter(int);
static int on_menu_exit(UI_Thread_Params*);
static void* caption_string_display(FrontDisplay_Job*);
static void* item_string_display(FrontDisplay_Job*);

static Menu_Item menu_general_settings_items[]; //234963f0

uint8_t bData_234963a4 = 0; //234963a4
Menu_Item* Data_234963a8 = 0; //234963a4

Menu menu_general_settings = //234963ac
{
		80, //"Allgemein"?
		&menu_general_settings_items[0], //Menu_Item* Data_4; //4
		&menu_general_settings_items[0], //Menu_Item* Data_8; //8
		0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
		0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
		0, //int Data_0x14; //20 = 0x14
		2, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		0, //void (*Data_0x1c)(); //0x1c
		menu_items_navigate, //void (*onNavigate)(); //0x20
		on_menu_enter, //void (*onEnter)(); //36 = 0x24
		on_menu_exit, //int (*onExit)(); //0x28
		0, //int Data_0x2c; //44 = 0x2c
		0, //int Data_0x30; //48
		0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
		//0x38 = 56?
}; //->234963E4

typedef void (*item_value_string_callback)(uint8_t* str, int len);

static item_value_string_callback item_value_string_callbacks[3] = //234963e4
{
		get_auto_standby_value_string,
		get_deep_standby_value_string,
		get_channel_list_update_value_string
};

Menu_Item menu_general_settings_items[] = //234963f0
{
	//[0]
	{
		382, //"Auto-Standby"
		0, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		on_auto_standby_change, //void* onEvent; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 2349641C
	}, //2349641C
	//[1]
	{
		341, //"Deep-Standby"
		0, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		on_deep_standby_change, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 23496448
	}, //23496448
	//[2]
	{
		394, //"Senderaktualisierung" // Channel list update
		0, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		on_channel_list_update_change, //void* Data_0x1c; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 23496474
	} //23496474
};

static User_Settings settings_work_copy; //238e0ab8


/* 23471d8c - todo */
int on_channel_list_update_change()
{
#if 0
	console_send_string("on_channel_list_update_change (todo.c): TODO\r\n");
#endif

	settings_work_copy.Data_0x10 ^= (1 << 7);

	if ((settings_work_copy.Data_0x10 >> 7) & 1)
	{
		powermode_set_onoff_callbacks(channel_list_update_start, sub_2343deb4);
	}
	else
	{
		//loc_23471da2
		powermode_set_onoff_callbacks(0, 0);
	}

	return 0;
}


/* 23471dae - complete */
void get_channel_list_update_value_string(uint8_t* str, int len)
{
#if 0
	console_send_string("get_channel_list_update_value_string (todo.c): TODO\r\n");
#endif

	if (settings_work_copy.Data_0x10 & (1 << 7))
	{
		text_table_get_string(20, str, len - 1);
	}
	else
	{
		//loc_23471dc0
		text_table_get_string(19, str, len - 1);
	}
}


/* 23471dcc - complete */
int on_deep_standby_change()
{
#if 0
	console_send_string("on_deep_standby_change (todo.c): TODO\r\n");
#endif

	settings_work_copy.Data_0x10 ^= (1 << 6);

	return 0;
}


/* 23471dda - complete */
void get_deep_standby_value_string(uint8_t* str, int len)
{
#if 0
	console_send_string("get_deep_standby_value_string (todo.c): TODO\r\n");
#endif

	if (settings_work_copy.Data_0x10 & (1 << 6))
	{
		text_table_get_string(19, str, len - 1);
	}
	else
	{
		//loc_23471dec
		text_table_get_string(20, str, len - 1);
	}
}


/* 23471df8 - complete */
int on_auto_standby_change()
{
#if 0
	console_send_string("on_auto_standby_change (todo.c): TODO\r\n");
#endif

	settings_work_copy.Data_0x10 ^= (1 << 15);

	menu_root_set_standby_timer_func((settings_work_copy.Data_0x10 >> 15) & 1);

	return 0;
}


/* 23471e12 - complete */
void get_auto_standby_value_string(uint8_t* str, int len)
{
#if 0
	console_send_string("get_auto_standby_value_string (todo.c): TODO\r\n");
#endif

	if (settings_work_copy.Data_0x10 & (1 << 15))
	{
		text_table_get_string(20, str, len - 1);
	}
	else
	{
		//loc_23471e24
		text_table_get_string(19, str, len - 1);
	}
}


/* 23471e30 - todo */
void* item_string_display(FrontDisplay_Job* r7)
{
	FrontDisplay_Job* r4;
	Menu_Item* r5;
	uint8_t* sp;

#if 0
	console_send_string("item_string_display (todo.c): TODO\r\n");
#endif

	r5 = menu_general_settings.Data_4;
	sp = r7->bData_8;

	text_table_get_string(r5->wData_0, sp, 0xfe);

	r7->bData_8[0xff] = 0;
	r7->bNumTextChars = strlen(sp);
	r7->bDisplayOffset = 0;
	r7->bNumDisplayChars = 12;
	r7->bData_0x10b = 0;
	r7->bData_0x110 = 0;
	r7->holdTime = 15;
	r7->Data_4 = 0;
	r7->bData_0x10f = 0;
	r7->bData_0x10c = 0;
	r7->Data_0 = frontdisplay_draw_text;

	if (r7->bNumTextChars > 12)
	{
		r7->bData_0x10c = 1;
		r7->Data_0 = frontdisplay_draw_scroll_text;
	}
	//loc_23471e7c
	r4 = &r7[1];

	if ((uint8_t)menu_general_settings.currentItem < 3)
	{
		if (item_value_string_callbacks[menu_general_settings.currentItem] != 0)
		{
			(item_value_string_callbacks[menu_general_settings.currentItem])(r4->bData_8, 0xff);
		}
	}
	//loc_23471e9e
	r4->bNumTextChars = strlen(r4->bData_8);
	r4->bNumDisplayChars = 12;
	r4->bDisplayOffset = 6;
	r4->bData_0x10b = 0;
	r4->bData_0x10c = 0;
	r4->bData_0x110 = 1;
	r4->holdTime = 0;
	r4->bData_0x10f = 0;
	r4->Data_4 = 0;
	r4->Data_0 = frontdisplay_draw_text;

	if (r4->bNumTextChars < 6)
	{
		r4->bDisplayOffset = r4->bNumDisplayChars - r4->bNumTextChars - 1;
		//->loc_23471ede
	}
	else
	{
		//loc_23471ed8
		r4->bData_0x10c = 1;
		r4->Data_0 = frontdisplay_draw_scroll_text;
	}
	//loc_23471ede
	if (Data_234963a8 != r5)
	{
		r4->bData_0x10f = 1;
		//->loc_23471f04
	}
	else
	{
		//loc_23471eec
		if (r4->bNumTextChars < bData_234963a4)
		{
			r7->bData_0x10f = 1;
			r7->bNumDisplayChars = r4->bDisplayOffset;
			r7->holdTime = 0;
			r7->bData_0x10c = 0;
			r7->Data_0 = frontdisplay_draw_text;
		}
		//loc_23471f04
	}
	//loc_23471f04
	bData_234963a4 = r4->bNumTextChars;
	Data_234963a8 = r5;

	return item_string_display;
}


/* 23471f0e - todo */
void* caption_string_display(FrontDisplay_Job* r4)
{
	uint8_t* str; //r6
	uint8_t len;

#if 0
	console_send_string("caption_string_display (todo.c): TODO\r\n");
#endif

	r4->bData_8[0] = '"';

	text_table_get_string(menu_general_settings.stringId, &r4->bData_8[1], 252);

	str = &r4->bData_8[0];

	len = strlen(str);

	r4->bData_8[len++] = '""';
	r4->bData_8[len] = 0;

	r4->bNumTextChars = strlen(str);
	r4->bDisplayOffset = 0; //r5
	r4->bNumDisplayChars = 12;
	r4->bData_0x10b = 0; //r5
	r4->bData_0x10c = 0; //r5
	r4->bData_0x110 = 0; //r5
	r4->holdTime = 15;

	r4->Data_0 = frontdisplay_draw_text;
	r4->Data_4 = 0; //r5
	r4->bData_0x10f = 0; //r5

	return item_string_display;
}


/* 23471f64 - todo */
int on_menu_enter(int a)
{
#if 1
	console_send_string("on_menu_enter (todo.c): TODO\r\n");
#endif

	// Get the settings
	channel_handle_user_settings(1, &settings_work_copy);

	frontdisplay_start_text(caption_string_display);

	return 0;
}


/* 23471f78 - complete */
int on_menu_exit(UI_Thread_Params* r4)
{
#if 0
	console_send_string("on_menu_exit (todo.c): TODO\r\n");
#endif

	User_Settings oldSettings;

	// Get the old settings
	channel_handle_user_settings(1, &oldSettings);

	// Compare with the work copy
	if (0 != memcmp(&oldSettings, &settings_work_copy, sizeof(User_Settings)))
	{
		// To save dialog?
		sub_23470890(r4, 1);

		return 1;
	}
	//loc_23471f9e
	return 0;
}


/* 23471fa2 - complete */
int menu_general_settings_entry(UI_Thread_Params* r4)
{
#if 0
	console_send_string("menu_general_settings_entry (todo.c): TODO\r\n");
#endif

	sub_2343d482(&menu_general_settings);
	sub_2343d3ac(&menu_general_settings);
	sub_2343d51e(&menu_general_settings, r4);

	return 0;
}


/* 23471fbe - todo */
User_Settings* sub_23471fbe(void)
{
	return &settings_work_copy;
}

