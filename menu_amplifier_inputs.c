
#include <string.h>
#include "data.h"
#include "amplifier.h"
#include "frontdisplay.h"
#include "menu_equalizer.h"

#pragma thumb

extern int sub_23439d92(uint8_t, void*);

static Menu_Item menu_amplifier_input_items[]; //2349c190 

static int menu_amplifier_inputs_on_enter(void);
static int menu_amplifier_inputs_on_exit(void);
static int menu_amplifier_input_on_event(int);
static void sub_234810d8(void);


extern int menu_amplifier_hold; //23495c10

Menu menu_amplifier_inputs = //2349c158
{
    0xffff, 
    &menu_amplifier_input_items[0], //Menu_Item* Data_4; //4
    &menu_amplifier_input_items[0], //Menu_Item* Data_8; //8
    0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
    0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
    0, //int Data_0x14; //20 = 0x14
    10, //uint8_t maxItem; //0x18 = 24 = 23495C2C
    0, //int8_t currentItem; //0x19 = 2349C171
    0, //void (*Data_0x1c)(); //0x1c
    menu_items_navigate, 
    menu_amplifier_inputs_on_enter, //void (*onEnter)(); //36 = 0x24
    menu_amplifier_inputs_on_exit, //int (*onExit)(); //0x28
    0xff, //int Data_0x2c; //44 = 0x2c
    100, //int Data_0x30; //48
    0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
    //0x38 = 56?
};

Menu_Item menu_amplifier_input_items[] = //2349c190 
{
	//[0]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_amplifier_input_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_234810d8, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	},
	//[1]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_amplifier_input_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_234810d8, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	},
	//[2]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_amplifier_input_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_234810d8, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	},
	//[3]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_amplifier_input_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_234810d8, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	},
	//[4]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_amplifier_input_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_234810d8, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	},
	//[5]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_amplifier_input_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_234810d8, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	},
	//[6]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_amplifier_input_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_234810d8, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	},
	//[7]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_amplifier_input_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_234810d8, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	},
	//[7]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_amplifier_input_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_234810d8, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	},
	//[9]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_amplifier_input_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_234810d8, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	},
	//[10]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_amplifier_input_on_event, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		sub_234810d8, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	}, //0x2349c374
};


/* 23480f84 - complete */
static void* sub_23480f84(FrontDisplay_Job* a)
{
    snprintf(&a->bData_8[0], 0x100, "%s", 
        &menu_amplifier_data.amplifierSettings.arInputs[menu_amplifier_inputs.currentItem].strName[0]);

    a->bNumTextChars = 12;
    a->bDisplayOffset = 0;
    a->bNumDisplayChars = 12;
    a->bData_0x10b = 0;
    a->bData_0x10c = 0;
    a->bData_0x110 = 0;
    a->holdTime = 0;
    a->Data_0 = frontdisplay_draw_text;
    a->Data_4 = 0;
    a->bData_0x10f = 0;

    return sub_23480f84;
}


/* 23480fc8 - complete */
static void* sub_23480fc8(FrontDisplay_Job* a)
{
    strcpy(&a->bData_8[0], "\"MODE\"");

    a->bNumTextChars = strlen(&a->bData_8[0]);
    a->bDisplayOffset = 0;
    a->bNumDisplayChars = 12;
    a->bData_0x10b = 0;
    a->bData_0x10c = 0;
    a->bData_0x110 = 0;
    a->holdTime = 20;
    a->Data_0 = frontdisplay_draw_text;
    a->Data_4 = 0;
    a->bData_0x10f = 0;

    return sub_23480f84;
}


/* 23481000 - todo */
void sub_23481000()
{
#if 1
	console_send_string("sub_23481000 (todo.c): TODO\r\n");
#endif

}


/* 23481014 - todo */
int menu_amplifier_input_on_event(int a)
{
    if (a != 0)
    {
        //0x2348101a
        menu_amplifier_data.bInput = menu_amplifier_inputs.currentItem;
        menu_amplifier_data.bEqualizer = 
            menu_amplifier_data.amplifierSettings.arInputs[menu_amplifier_data.bInput].bData_16;

#if 1
        {
            extern char debug_string[];
            sprintf(debug_string, "menu_amplifier_input_on_event: bInput=%d, bEqualizer=%d\r\n",
                    menu_amplifier_data.bInput, menu_amplifier_data.bEqualizer);
            console_send_string(debug_string);
        }
#endif

        switch (menu_amplifier_data.bInput)
        {
            case 0: 
                //loc_234810b2: RADIO
                break;

            case 1: //USB (rear)
            case 2: //USB (front)
                //loc_23481040
                if (0 != sub_23439d92(menu_amplifier_data.bInput - 1, sub_23481000))
                {
                    //->loc_234810d4
                    return 0;
                }
                //0x2348104e
                (menu_amplifier_interface_fn.input_configuration)(0);
                (menu_amplifier_interface_fn.Data_235fc430)(menu_amplifier_data.bEqualizer);
                
                if (menu_amplifier_inputs.onExit != 0)
                {
                    (menu_amplifier_inputs.onExit)(0);
                }
                //loc_23481062
                sub_2343d482(0);
                if (0 != sub_2346ff0e())
                {
                    //loc_2348106e
                    sub_2343d482(&menu_amplifier_inputs);
                    //->loc_234810d4
                }
                //->loc_234810d4
                return 0;
                //break;

            default:
                //loc_23481076
                if (0 == strncmp(&menu_amplifier_data.amplifierSettings.arInputs[menu_amplifier_data.bInput].strName[0], "INTERNET", 8))
                {
                    //0x23481084
                    menu_amplifier_data.bInput = 0;
                    menu_amplifier_data.bEqualizer = menu_amplifier_data.amplifierSettings.arInputs[menu_amplifier_data.bInput/*0*/].bData_16;

                    (menu_amplifier_interface_fn.input_configuration)(menu_amplifier_data.bInput/*0*/);
                    (menu_amplifier_interface_fn.Data_235fc430)(menu_amplifier_data.bEqualizer);

                    if (menu_amplifier_inputs.onExit != 0)
                    {
                        (menu_amplifier_inputs.onExit)(0);
                    }
                    //loc_234810a2
                    sub_2343d482(0);
                    if (0 != menu_net_radio_entry())
                    {
                        //->loc_2348106e
                        sub_2343d482(&menu_amplifier_inputs);
                        //->loc_234810d4
                    }
                    //->loc_234810d4
                    return 0;
                }
                //loc_234810b2
                break;
        }
        //loc_234810b2
        if (menu_amplifier_interface_fn.input_configuration != 0)
        {
            //0x234810b8
            (menu_amplifier_interface_fn.input_configuration)(menu_amplifier_data.bInput);
            (menu_amplifier_interface_fn.Data_235fc430)(menu_amplifier_data.bEqualizer);
        }
        //loc_234810cc
        return 0xff;
    }
    else
    {
        //loc_234810c4
        if (menu_amplifier_hold == 0)
        {
            return 0xff;
        }
        else
        {
            menu_amplifier_hold--;
        }
    }
    //loc_234810d4
    return 0;
}


/* 234810d8 - todo */
void sub_234810d8(void)
{
    menu_amplifier_hold = 5;
}


/* 234810e0 - todo */
int menu_amplifier_inputs_on_enter(void)
{
    menu_amplifier_hold = 5;

    frontdisplay_start_text(sub_23480fc8);

    return 0;
}


/* 234810f2 - todo */
int menu_amplifier_inputs_on_exit(void)
{
    return 0;
}


/* 234810f6 - todo */
int menu_amplifier_inputs_enter(void)
{
#if 0
	console_send_string("menu_amplifier_inputs_enter (todo.c): TODO\r\n");
#endif

	if (menu_amplifier_data.amplifier_get_data == 0)
	{
        sub_234837cc();
		return 8;
	}
	//loc_23481108
	menu_amplifier_inputs.currentItem = menu_amplifier_data.bInput;

	sub_2343d482(&menu_amplifier_inputs);
	sub_2343d3ac(&menu_amplifier_inputs);
	void* r1 = sub_2343d572();
	sub_2343d51e(&menu_amplifier_inputs, r1);

	return 0;
}


#if 1 //def VDR110

/* 2348112c - todo */
int menu_amplifier_inputs_select_bluetooth(int key)
{
#if 0
	console_send_string("menu_amplifier_inputs_select_bluetooth (todo.c): TODO\r\n");
#endif

	if (menu_amplifier_data.amplifier_get_data == 0)
	{
		return 8;
	}

	if (key == 0)
	{
		if (menu_amplifier_data.bInput != 0)
		{
			menu_amplifier_data.bInput = 0;
			menu_amplifier_data.bEqualizer = 
				menu_amplifier_data.amplifierSettings.arInputs[menu_amplifier_data.bInput].bData_16;

			if (menu_amplifier_interface_fn.input_configuration != 0)
			{
				(menu_amplifier_interface_fn.input_configuration)(menu_amplifier_data.bInput);
				(menu_amplifier_interface_fn.Data_235fc430)(menu_amplifier_data.bEqualizer);
			}
		}
	}
	else if (key == 52) //BT
	{
		for (uint8_t i = 0; i < 9; i++)
		{
			if (0 == strcmp(&menu_amplifier_data.amplifierSettings.arInputs[i].strName[0], "BLUETOOTH"))
			{
				menu_amplifier_data.bInput = i;
				menu_amplifier_data.bEqualizer = 
					menu_amplifier_data.amplifierSettings.arInputs[i].bData_16;

				if (menu_amplifier_interface_fn.input_configuration != 0)
				{
					(menu_amplifier_interface_fn.input_configuration)(menu_amplifier_data.bInput);
					(menu_amplifier_interface_fn.Data_235fc430)(menu_amplifier_data.bEqualizer);
				}
			}
		}
	}

	return 0;
}

#endif



