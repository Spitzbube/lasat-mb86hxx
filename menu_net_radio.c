
#include <string.h>
#include <stdio.h>
#include "data.h"
#include "eth.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "menu.h"
#include "network.h"

#pragma thumb

static Menu_Item menu_net_radio_items[]; //2349c4d8

static int sub_234813ac(uint8_t*);
static int sub_234813f4(int*);
static int menu_net_radio_on_enter();
static int sub_23481742(void);
static int sub_234817b2(int);

char Data_2349c374[300] = " Start Stream "; //2349c374

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


char Data_2399bb08[400]; //2399bb08
char Data_2399bc98[200]; //2399bc98 -> 2399BD60
char Data_2399bd60[200]; //2399BD60 -> 2399BE28

struct 
{
    int Data_0; //0 = 2399be28
    int Data_4; //4 = 2399be2c
    void* (*Data_8)(void); //8 = 2399BE30
    void (*Data_0xc)(void); //12 = 2399BE34
    int Data_0x10; //16 = 2399BE38
    int fill_0x14[24]; //20 = 2399BE3C
    char* Data_2399be9c[256]; //2399BE9C
    int Data_2399c29c; //0x474 = 2399C29C
    int Data_2399c2a0; //0x478 = 2399C2A0
    int Data_2399c2a4; //0x47c = 2399C2A4
    int Data_2399c2a8; //0x480 = 2399C2A8
    int Data_2399c2ac; //0x484 = 2399C2AC
    int Data_2399c2b0; //0x488 = 2399C2B0
    int Data_2399c2b4; //0x48c = 2399C2B4
    void* (*Data_2399c2b8)(int*); //0x490 = 2399C2B8
    int Data_2399c2bc; //0x494 = 2399C2BC

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


/* 234812f4 - todo */
void* sub_234812f4(int* a)
{
#if 1
	console_send_string("sub_234812f4 (todo.c): TODO\r\n");
#endif

}


/* 23481322 - todo */
void* sub_23481322(FrontDisplay_Job* a)
{
#if 1
	console_send_string("sub_23481322 (todo.c): TODO\r\n");
#endif

}


/* 234813ac - todo */
int sub_234813ac(uint8_t* a)
{
#if 0
	console_send_string("sub_234813ac (todo.c): TODO\r\n");
#endif

    if (a == 0)
    {
        if ((Data_2399be28.Data_2399c2b4 != 0) &&
           (Data_2399be28.Data_2399c2b8 != 0))
        {
            Data_2399be28.Data_2399c2b8 = 
                (Data_2399be28.Data_2399c2b8)(&Data_2399be28.Data_2399c2b4);
        }
        //loc_234813f0
    }
    else
    {
        //loc_234813ca
        uint8_t r0 = a[4];
        if (r0 == 17)
        {
            channel_change_volume(1, -1);

            frontdisplay_start_text(sub_23481322);

            Data_2399be28.Data_2399c2b8 = sub_234812f4;
            Data_2399be28.Data_2399c2b4 = 20;
        }
        else if (r0 == 16)
        {
            channel_change_volume(1, 1);

            frontdisplay_start_text(sub_23481322);

            Data_2399be28.Data_2399c2b8 = sub_234812f4;
            Data_2399be28.Data_2399c2b4 = 20;
        }
    }

    return 0;
}


/* 234813f4 - todo */
int sub_234813f4(int* a)
{
    int r0 = *a;

#if 0
	console_send_string("sub_234813f4 (todo.c): TODO\r\n");
#endif

    Data_2399be28.Data_2399c2b0 = 0x0f;

    if (r0 == 2)
    {
        Data_2399be28.Data_0--;
        if (Data_2399be28.Data_0 < 0)
        {
            Data_2399be28.Data_0 = Data_2399be28.Data_4;
        }
        //->loc_23481450
    }
    //loc_23481412
    else if (r0 == 1)
    {
        Data_2399be28.Data_0++;
        if (Data_2399be28.Data_0 > Data_2399be28.Data_4)
        {
            Data_2399be28.Data_0 = 0;
        }
        //->loc_23481450
    }
    //loc_23481424
    else if ((r0 == 4) || (r0 == 8))
    {
        //loc_2348142c
        menu_net_radio.currentItem = 1;
        menu_net_radio.Data_4 = menu_net_radio.Data_8 + 1;

        Data_2399be28.Data_2399c2b4 = 0;
        Data_2399be28.Data_2399c2b8 = 0;
        Data_2399be28.Data_2399c2bc = 0;

        uint8_t sp[5];

        sp[4] = (r0 == 4)? 17: 16;

        sub_234813ac(&sp);
    }
    //loc_23481450
    return 0;
}


/* 23481454 - complete */
void sub_23481454(char* a, int b)
{
#if 0
	console_send_string("sub_23481454 (todo.c): TODO\r\n");
#endif

#if 1
    if ((a != 0) && (b != 0))
    {
        hex_dump("sub_23481454", a, b);
    }
#endif

    char* pBuf = sub_2340147c();

    if (a == 0)
    {
        pBuf[Data_2399be28.Data_2399c2a0] = 0;
        Data_2399be28.Data_2399c29c = Data_2399be28.Data_2399c2a0;
        Data_2399be28.Data_2399c2a0 = 0;
        Data_2399be28.Data_2399c2a4 = 0;

        Data_2399be28.Data_8 = Data_2399be28.Data_0xc;
    }
    else
    {
        //loc_2348148c
        while (b--)
        {
            //loc_2348147c
            pBuf[Data_2399be28.Data_2399c2a0] = *a++;
            Data_2399be28.Data_2399c2a0 = (uint16_t)(Data_2399be28.Data_2399c2a0 + 1);
        } 
    }
}


/* 23481492 - todo */
void sub_23481492(char* a, void (*b)(void))
{
#if 0
	console_send_string("sub_23481492 (todo.c): TODO\r\n");
#endif

    Data_2399be28.Data_4 = 0;
    Data_2399be28.Data_0 = 0;
    
#if 1
    if (Data_2399be28.Data_0x10 != 0)
    {
        snprintf(&Data_2399bb08[0], 399, 
            "GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Tibor\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: de-de,de;q=0.8,en-us;q=0.5,en;q=0.3\r\nAccept-Encoding: deflate\r\nAccept-Charset: ISO-8859-1\r\nConnection: keep-alive\r\nCookie: %s\r\n\r\n",
            a, "85.214.222.229", &Data_2399be28.Data_0x10);
    }
    else
    {
        snprintf(&Data_2399bb08[0], 399, 
            "GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Tibor\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: de-de,de;q=0.8,en-us;q=0.5,en;q=0.3\r\nAccept-Encoding: deflate\r\nAccept-Charset: ISO-8859-1\r\nConnection: keep-alive\r\n\r\n",
            a, "85.214.222.229");
    }
#else
        snprintf(&Data_2399bb08[0], 399, 
            "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: Tibor\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: de-de,de;q=0.8,en-us;q=0.5,en;q=0.3\r\nAccept-Encoding: deflate\r\nAccept-Charset: ISO-8859-1\r\nConnection: keep-alive\r\n\r\n",
            "85.214.222.229");
#endif

    Data_2399be28.Data_2399c2a4 = web_client_send_request("85.214.222.229", 80, 
        &Data_2399bb08[0], sub_23481454);

    Data_2399be28.Data_0xc = b;
}


/* 234814de - todo */
void sub_234814de()
{
#if 1
	console_send_string("sub_234814de (todo.c): TODO\r\n");
#endif

}


/* 2348155a - todo */
void sub_2348155a(void)
{
#if 0
	console_send_string("sub_2348155a (todo.c): TODO\r\n");
#endif

    Struct_234012b0_a sp_0xc;
    Struct_234012b0_b sp4;

    if (network_pfGetMac != 0)
    {
        (network_pfGetMac)(&sp_0xc, &sp4);
    }

    Data_2349c374[0] = 0;

    snprintf(&Data_2399bd60[0], 200, 
        "%s/mylogin.php?mac=%s", 
        "senderliste",
        &sp_0xc.bData[0]);

    sub_23481492(&Data_2399bd60[0], sub_234814de);
}


/* 23481592 - todo */
void sub_23481592(void)
{
#if 1
	console_send_string("sub_23481592 (todo.c): TODO\r\n");
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


/* 23481742 - todo */
int sub_23481742(void)
{
#if 0
	console_send_string("sub_23481742 (todo.c): TODO\r\n");
#endif

    if (Data_2399be28.Data_2399c2a8 == 0)
    {
        //0x23481750
        int r4 = 200;

        if (Data_2399be28.Data_2399c2a4 != 0)
        {
            sub_23477120(Data_2399be28.Data_2399c2a4);
        }
        //loc_2348175e
        sub_23481492("senderliste/mylogin.php?mac=!", 0);
        //->loc_23481774
        while (r4--)
        {
            //loc_23481768
            if (Data_2399be28.Data_2399c2a4 == 0)
            {
                //loc_23481782
                break;
            }

            rtos_task_wait(1);
        }
        //0x23481778
        if (Data_2399be28.Data_2399c2a4 != 0)
        {
            sub_23477120(Data_2399be28.Data_2399c2a4);
        }
        //loc_23481782
        if (Data_2399be28.Data_2399c2ac != 0)
        {
            //0x23481788
            Struct_2340bf0c sp_0x2c;
            Channel sp4;

            sub_2340bf0c(&sp_0x2c);
            channel_start_number(&sp4, sp_0x2c.wCurrentChannel, sp_0x2c.wCurrentChannel);
        }
        //loc_2348179a
        return 0;
    }
    else
    {
        //loc_234817a0
        Data_2399be28.Data_2399c2a8--;

        sub_23481492("senderliste/top.php", sub_23481592);

        return 1;
    }
}


/* 234817b2 - todo */
int sub_234817b2(int a)
{
#if 0
	console_send_string("sub_234817b2 (todo.c): TODO\r\n");
#endif

    if (a == 0)
    {
        if (Data_2399be28.Data_8 != 0)
        {
            Data_2399be28.Data_8 = (Data_2399be28.Data_8)();
        }
        //->loc_234818a2
    }
    else
    {
        //loc_234817c8
        sub_23481916(Data_2399be28.Data_0, &Data_2399bc98[0], 199);
        sub_234811ec(3, &Data_2399bd60[0], 200);

        if (Data_2399bd60[0] == 0)
        {
            //0x234817ee
            char sp[32] = {0};

            sub_234811ec(4, &sp[0], 0xff);

            char* r5 = &Data_2399bc98[0];

            snprintf(r5, 200, "%s/listing.php?genre=", "senderliste");

            uint32_t r0 = strlen(r5);
            char* r1 = r5 + r0;
            int r3 = 199 - r0;
            char* r2 = &sp[0];
            //->loc_23481830
            while (r3--)
            {
                //loc_23481820
                char ch = *r2;
                if ((ch == 0x0a) || (ch == 0x0d))
                {
                    //->loc_23481834
                    break;
                }

                r2++;
                *r1 = ch;
                r1++;
            }
            //loc_23481834
            *r1 = 0; //r6

            Data_2399be28.Data_2399c2a8++;

            sub_23481492(r5, sub_23481592);
            //->loc_234818a2
        } //if (Data_2399bd60[0] == 0)
        //loc_23481846
        else if (Data_2399be28.Data_2399c2b0 != 0)
        {
            if (Data_2399be28.Data_2399c2b0 == 0x0f)
            {
                //0x23481850
                Data_2399be28.Data_2399c2ac = 1;
                Data_2349c374[0] = 0;

                sub_2340b4e8(&Data_2399bd60[0]);
            }
            //loc_23481860
            Data_2399be28.Data_2399c2b0--;

            if (Data_2399be28.Data_2399c2b0 == 0)
            {
                //0x23481868
                sub_234706aa();

                char sp_0xc[20];

                sub_234811ec(4, &sp_0xc[0], 19);

                int r1 = strlen(&Data_2399bd60[0]);

                if (0 == sub_23481936(&Data_2399bd60[0], r1, &sp_0xc[0], 1, 0))
                {
                    //0x23481894
                    channel_write_database();
                    channel_load_lists();
                }
                //loc_2348189c
                frontdisplay_start_text(sub_23481220);
            }
            //loc_234818a2
        }
        //loc_234818a2
    }
    //loc_234818a2
    return 0;
}


/* 234818a8 - todo */
int menu_net_radio_entry(void)
{
#if 0
	console_send_string("menu_net_radio_entry (todo.c): TODO\r\n");
#endif

    if (0 == network_is_link_up())
    {
        return 0xff;
    }

    menu_stack_operate(&menu_net_radio);
    menu_initialize(&menu_net_radio);
    void* r1 = sub_2343d572();
    sub_2343d51e(&menu_net_radio, r1);

    return 0;
}


/* 23481916 - complete */
void sub_23481916(int a, char* b, int c)
{
#if 0
	console_send_string("sub_23481916 (todo.c): TODO\r\n");
#endif

    char* r0 = Data_2399be28.Data_2399be9c[a];
    //->loc_2348192c
    while (c--)
    {
        //loc_23481920
        char ch = *r0;
        if (ch == 0x0a)
        {
            //->loc_23481930
            break;
        }

        r0++;
        *b = ch;
        b++;
    }
    //loc_23481930
    *b = 0;
}


/* 23481936 - todo */
int sub_23481936()
{
#if 1
	console_send_string("sub_23481936 (todo.c): TODO\r\n");
#endif

}


/*
Ich habe mal die Netzwerkverbindung analysiert und scheinbar versucht die Box einen Server zu kontaktieren:
[code]
0000  47 45 54 20 | 2F 73 65 6E | 64 65 72 6C | 69 73 74 65  GET /senderliste
0010  2F 6D 79 6C | 6F 67 69 6E | 2E 70 68 70 | 3F 6D 61 63  /mylogin.php?mac
0020  3D 30 30 30 | 44 46 32 30 | 30 31 45 30 | 36 20 48 54  =000DF2001E06 HT
0030  54 50 2F 31 | 2E 31 0D 0A | 48 6F 73 74 | 3A 20 38 35  TP/1.1..Host: 85
0040  2E 32 31 34 | 2E 32 32 32 | 2E 32 32 39 | 0D 0A 55 73  .214.222.229..Us
0050  65 72 2D 41 | 67 65 6E 74 | 3A 20 54 69 | 62 6F 72 0D  er-Agent: Tibor.
0060  0A 41 63 63 | 65 70 74 3A | 20 74 65 78 | 74 2F 68 74  .Accept: text/ht
0070  6D 6C 2C 61 | 70 70 6C 69 | 63 61 74 69 | 6F 6E 2F 78  ml,application/x
0080  68 74 6D 6C | 2B 78 6D 6C | 2C 61 70 70 | 6C 69 63 61  html+xml,applica
0090  74 69 6F 6E | 2F 78 6D 6C | 3B 71 3D 30 | 2E 39 2C 2A  tion/xml;q=0.9,*
00a0  2F 2A 3B 71 | 3D 30 2E 38 | 0D 0A 41 63 | 63 65 70 74  /*;q=0.8..Accept
00b0  2D 4C 61 6E | 67 75 61 67 | 65 3A 20 64 | 65 2D 64 65  -Language: de-de
00c0  2C 64 65 3B | 71 3D 30 2E | 38 2C 65 6E | 2D 75 73 3B  ,de;q=0.8,en-us;
00d0  71 3D 30 2E | 35 2C 65 6E | 3B 71 3D 30 | 2E 33 0D 0A  q=0.5,en;q=0.3..
00e0  41 63 63 65 | 70 74 2D 45 | 6E 63 6F 64 | 69 6E 67 3A  Accept-Encoding:
00f0  20 64 65 66 | 6C 61 74 65 | 0D 0A 41 63 | 63 65 70 74   deflate..Accept
0100  2D 43 68 61 | 72 73 65 74 | 3A 20 49 53 | 4F 2D 38 38  -Charset: ISO-88
0110  35 39 2D 31 | 0D 0A 43 6F | 6E 6E 65 63 | 74 69 6F 6E  59-1..Connection
0120  3A 20 6B 65 | 65 70 2D 61 | 6C 69 76 65 | 0D 0A 0D 0A  : keep-alive....
[/code]

Als Antwort kommt allerdings:
[code]
0000  48 54 54 50 | 2F 31 2E 31 | 20 34 30 34 | 20 4E 6F 74  HTTP/1.1 404 Not
0010  20 46 6F 75 | 6E 64 0D 0A | 53 65 72 76 | 65 72 3A 20   Found..Server:
0020  6E 67 69 6E | 78 2F 31 2E | 31 38 2E 30 | 20 28 55 62  nginx/1.18.0 (Ub
0030  75 6E 74 75 | 29 0D 0A 44 | 61 74 65 3A | 20 4D 6F 6E  untu)..Date: Mon
0040  2C 20 30 32 | 20 53 65 70 | 20 32 30 32 | 34 20 30 37  , 02 Sep 2024 07
0050  3A 30 35 3A | 32 32 20 47 | 4D 54 0D 0A | 43 6F 6E 74  :05:22 GMT..Cont
0060  65 6E 74 2D | 54 79 70 65 | 3A 20 74 65 | 78 74 2F 68  ent-Type: text/h
0070  74 6D 6C 0D | 0A 43 6F 6E | 74 65 6E 74 | 2D 4C 65 6E  tml..Content-Len
0080  67 74 68 3A | 20 31 36 32 | 0D 0A 43 6F | 6E 6E 65 63  gth: 162..Connec
0090  74 69 6F 6E | 3A 20 6B 65 | 65 70 2D 61 | 6C 69 76 65  tion: keep-alive
00a0  0D 0A 0D 0A | 3C 68 74 6D | 6C 3E 0D 0A | 3C 68 65 61  ....<html>..<hea
00b0  64 3E 3C 74 | 69 74 6C 65 | 3E 34 30 34 | 20 4E 6F 74  d><title>404 Not
00c0  20 46 6F 75 | 6E 64 3C 2F | 74 69 74 6C | 65 3E 3C 2F   Found</title></
00d0  68 65 61 64 | 3E 0D 0A 3C | 62 6F 64 79 | 3E 0D 0A 3C  head>..<body>..<
00e0  63 65 6E 74 | 65 72 3E 3C | 68 31 3E 34 | 30 34 20 4E  center><h1>404 N
00f0  6F 74 20 46 | 6F 75 6E 64 | 3C 2F 68 31 | 3E 3C 2F 63  ot Found</h1></c
0100  65 6E 74 65 | 72 3E 0D 0A | 3C 68 72 3E | 3C 63 65 6E  enter>..<hr><cen
0110  74 65 72 3E | 6E 67 69 6E | 78 2F 31 2E | 31 38 2E 30  ter>nginx/1.18.0
0120  20 28 55 62 | 75 6E 74 75 | 29 3C 2F 63 | 65 6E 74 65   (Ubuntu)</cente
0130  72 3E 0D 0A | 3C 2F 62 6F | 64 79 3E 0D | 0A 3C 2F 68  r>..</body>..</h
0140  74 6D 6C 3E | 0D 0A                                    tml>..
[/code]
*/
