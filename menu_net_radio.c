
#include "data.h"
#include "frontdisplay.h"

#pragma thumb

static Menu_Item menu_net_radio_items[]; //2349c4d8

static int sub_234813ac();
static void sub_234813f4();
static int menu_net_radio_on_enter();
static void sub_23481742();
static int sub_234817b2();

Menu menu_net_radio = //0x2349c4a0
{
    0xffff, 
    &menu_net_radio_items[0], //Menu_Item* Data_4; //4
    &menu_net_radio_items[0], //Menu_Item* Data_8; //8
    0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
    0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
    0, //int Data_0x14; //20 = 0x14
    1, //uint8_t maxItem; //0x18 = 24 = 23495C2C
    0, //int8_t currentItem; //0x19 = 2349C171
    0, //void (*Data_0x1c)(); //0x1c
    sub_234813f4, //menu_items_navigate, 
    menu_net_radio_on_enter, //void (*onEnter)(); //36 = 0x24
    sub_23481742, //int (*onExit)(); //0x28
    0xff, //int Data_0x2c; //44 = 0x2c
    10, //int Data_0x30; //48
    0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
    //0x38 = 56?
};


Menu_Item menu_net_radio_items[] = //2349c4d8
{
	//[0]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_234817b2, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	},
	//[1]
	{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_234813ac, //void* onEvent; //0x1c = 28
		mainfunction_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
	},
};


char Data_2399bc98[200]; //2399bc98 ->2399BD60

struct 
{
    int Data_0; //0 = 2399be28
    int Data_4; //4 = 2399be2c
    int Data_8; //8 = 2399BE30
    int fill_0xc; //12 = 2399BE34
    int Data_0x10; //16 = 2399BE38
    int fill_0x14[281]; //20 = 2399BE3C
    int Data_2399c2a0; //0x478 = 2399C2A0
    int fill_2399c2a4; //0x47c = 2399C2A4
    int Data_2399c2a8; //0x480 = 2399C2A8
    int Data_2399c2ac; //0x484 = 2399C2AC
    int Data_2399c2b0; //0x488 = 2399C2B0

} Data_2399be28; //2399be28?


/* 234811ec - complete */
void sub_234811ec(int a, char* b, uint32_t c)
{
    int r4 = 199;
    char* r3 = &Data_2399bc98[0];

    while (r4--)
    {
        if (*r3 == 0x7c)
        {
            a--;
            if (a == 0)
            {
                r3++;

                while (c--)
                {
                    char ch = *r3;
                    if (ch == 0x7c)
                    {
                        break;
                    }
                    r3++;
                    *b = ch;
                    b++;
                }

                *b = 0;
                return;
            }
        }
        r3++;
    }
}


/* 23481220 - todo */
static void* sub_23481220(FrontDisplay_Job* a)
{
    if (Data_2399be28.Data_4 != 0)
    {
        sub_23481916(Data_2399be28.Data_0, &Data_2399bc98[0], 199);

        snprintf(&a->bData_8[0], 0x100, "%d ", Data_2399be28.Data_0 + 1);

        sub_234811ec(4, &a->bData_8[strlen(&a->bData_8[0])], 0xff);
    }
    else
    {
        //loc_23481260
        snprintf(&a->bData_8[0], 0x100, "connect...");
    }
    //loc_2348126a
    uint8_t len = strlen(&a->bData_8[0]);
    a->bNumTextChars = len;
    a->bDisplayOffset = 0;
    a->bNumDisplayChars = 12;
    a->bData_0x10b = 0;
    a->bData_0x110 = 0;
    a->holdTime = 0;
    a->Data_4 = 0;
    a->bData_0x10f = 0;
    a->bData_0x10c = 0;
    a->Data_0 = frontdisplay_draw_text;

    if (len > 12)
    {
        a->bData_0x10c = 1;
        a->Data_0 = frontdisplay_draw_scroll_text;
    }

    return sub_23481220;
}


/* 234812a0 - complete */
static void* sub_234812a0(FrontDisplay_Job* a)
{
    a->bData_8[0] = 0x22;

    snprintf(&a->bData_8[1], 0xfd, "NetRadio");

    uint8_t len = strlen(&a->bData_8[0]);
    a->bData_8[len] = 0x22;
    len++;
    a->bData_8[len] = 0;

    len = strlen(&a->bData_8[0]);

    a->bNumTextChars = len;
    a->bDisplayOffset = 0;
    a->bNumDisplayChars = 12;
    a->bData_0x10b = 0;
    a->bData_0x10c = 0;
    a->bData_0x110 = 0;
    a->holdTime = 20;
    a->Data_0 = frontdisplay_draw_text;
    a->Data_4 = 0;
    a->bData_0x10f = 0;

    return sub_23481220;
}


/* 234813ac - todo */
int sub_234813ac()
{
#if 1
	console_send_string("sub_234813ac (todo.c): TODO\r\n");
#endif

}


/* 234813f4 - todo */
void sub_234813f4(void)
{
#if 1
	console_send_string("sub_234813f4 (todo.c): TODO\r\n");
#endif
}


/*23481718 - todo */
int menu_net_radio_on_enter(void)
{
#if 0
	console_send_string("menu_net_radio_on_enter (todo.c): TODO\r\n");
#endif

    Data_2399be28.Data_8 = 0;
    Data_2399be28.Data_2399c2a0 = 0;
    Data_2399be28.Data_2399c2a8 = 0;
    Data_2399be28.Data_2399c2b0 = 0x0f;
    Data_2399be28.Data_2399c2ac = 0;
    Data_2399be28.Data_0x10 = 0;

    frontdisplay_start_text(sub_234812a0);
    sub_2348155a();

    return 0;
}


/* 2348155a - todo */
void sub_2348155a(void)
{
#if 1
	console_send_string("sub_2348155a (todo.c): TODO\r\n");
#endif
}


/* 23481742 - todo */
void sub_23481742(void)
{
#if 1
	console_send_string("sub_23481742 (todo.c): TODO\r\n");
#endif
}


/* 234817b2 - todo */
int sub_234817b2()
{
#if 1
	console_send_string("sub_234817b2 (todo.c): TODO\r\n");
#endif

}


/* 234818a8 - todo */
int menu_net_radio_entry(void)
{
#if 0
	console_send_string("menu_net_radio_entry (todo.c): TODO\r\n");
#endif

    if (0 == sub_23419428())
    {
        return 0xff;
    }

    sub_2343d482(&menu_net_radio);
    sub_2343d3ac(&menu_net_radio);
    void* r1 = sub_2343d572();
    sub_2343d51e(&menu_net_radio, r1);

    return 0;
}


/* 23481916 - todo */
void sub_23481916()
{
#if 1
	console_send_string("sub_23481916 (todo.c): TODO\r\n");
#endif

}



