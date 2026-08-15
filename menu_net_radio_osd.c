
#include <string.h>
#include "data.h"
#include "eth.h"
#include "network.h"
#include "frontdisplay.h"
#include "graphic.h"
#include "menu.h"
#include "osd_list.h"

#ifndef VDR110

#pragma thumb

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern void sub_2344f102(UI_Thread_Params*);
extern void sub_2348dbf8();
extern int osd_list_draw(Menu*, int);

extern Graphic_Job_2_5_Item_Background Data_234e1e24; //234e1e24
extern uint8_t Data_234e1e68[];
extern uint8_t Data_234e1fd0[]; 

static Menu Data_23505e90;
static uint8_t Data_2396e104[]; 

static void sub_2349b146();
static int sub_2349b228(Struct_2348dc50*);
static int menu_net_radio_on_enter();
static void sub_2349b588();


// /  / 23504b2c
static Menu* Data_23504b30 = &Data_23505e90; // /  / 23504b30 +4
static char Data_23504b3c[300] = " Start Stream "; //23504b3c

static Graphic_Job_2_5_Item_Text Data_23504c68 = //23504c68
{
	0, 0x0051, 0x002c, 0x0176, 0x004f, 0x01, 0x06, 0x02, 0x00, &Data_2396e104[0], 0, 0, 0
#if 0
0x23504c68                        db         0x00                               ; DATA XREF=dword_23504ad0+36, 0x23504ef0
0x23504c69                        db         0x00
0x23504c6a                        dw         0x0051
0x23504c6c                        dw         0x002c                             ; DATA XREF=dword_23504ad0+40
0x23504c6e                        dw         0x0176
0x23504c70                        dw         0x004f
0x23504c72                        db         0x01
0x23504c73                        db         0x06
0x23504c74                        db         0x02
0x23504c75                        db         0x00
0x23504c76 0000                   movs       r0, r0
0x23504c78                        dd         0x2396e104
#endif
};

static Graphic_Job_2_5_Item_Text Data_23504c80 = //23504c80
{
	0, 0x0047, 0x0064, 0x0088, 0x0080, 0x01, 0x04, 0x03, 0x01, &Data_234e1e68[0], 0, 0, 0
#if 0
0x23504c80                        db         0x00                               ; DATA XREF=0x23505030
0x23504c81                        db         0x00
0x23504c82                        dw         0x0047
0x23504c84                        dw         0x0064
0x23504c86                        dw         0x0088
0x23504c88                        dw         0x0080
0x23504c8a                        db         0x01
0x23504c8b                        db         0x04
0x23504c8c                        db         0x03
0x23504c8d                        db         0x01
0x23504c8e 0000                   movs       r0, r0
0x23504c90                        dd         0x234e1e68                         ; "1"
#endif
};

static Graphic_Job_2_5_Item_Text Data_23504d70 = //23504d70
{
	0, 0x0098, 0x0064, 0x0175, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_234e1fd0[0], 0, 0, 0
#if 0
0x23504d70                        db         0x00                               ; DATA XREF=0x235052b0
0x23504d71                        db         0x00
0x23504d72                        dw         0x0098
0x23504d74                        dw         0x0064
0x23504d76                        dw         0x0175
0x23504d78                        dw         0x0080
0x23504d7a                        db         0x01
0x23504d7b                        db         0x04
0x23504d7c                        db         0x09
0x23504d7d                        db         0x01
0x23504d7e 0000                   movs       r0, r0
0x23504d80                        dd         0x234e1fd0                         ; "EINS"
#endif
};


static Graphic_Job_2_5_Item Data_23504e90[] = //23504e90
{
	{0}, //[0] = 23504e90 
	{1, 0, 0, 0/*Data_8*/, 0x003d, 0x0029, 0x0139, 0x0026, 0, &Data_234e1e24, 2, 0, &Data_23504c68}, //[1] = 23504ED0: Header 
#if 0
0x23504ed0                        db         0x01                               ; DATA XREF=aLpslistingphpg+62, sub_2349b588+132, dword_23505e9c
0x23504ed1                        db  0x00 ; '.'
0x23504ed2 0000                   movs       r0, r0
0x23504ed4 0000                   movs       r0, r0
0x23504ed6 0000                   movs       r0, r0
0x23504ed8 0000                   movs       r0, r0
0x23504eda 0000                   movs       r0, r0
0x23504edc                        dw         0x003d
0x23504ede                        dw         0x0029
0x23504ee0                        dw         0x0139
0x23504ee2                        dw         0x0026
0x23504ee4 0000                   movs       r0, r0
0x23504ee6 0000                   movs       r0, r0
0x23504ee8                        dd         0x234e1e24
0x23504eec                        dw         0x0002
0x23504eee 0000                   movs       r0, r0
0x23504ef0                        dd         0x23504c68                         ; DATA XREF=aLpslistingphpg+64, sub_2349b588+134
#endif
	{0}, //[2] = 23504F10 
	{0}, //[3] = 23504F50 
	{0}, //[4] = 23504F90 
	{0}, //[5] = 23504FD0 
	{1, 0, 0, 0/*Data_8*/, 0x003d, 0x0060, 0x004b, 0x0020, 0, &menu_main_graphic_item_background_dark_blue_top_round_left_right, 3, 0, &Data_23504c80}, //[6] = 23505010: Item 1 Label
#if 0
0x23505010                        db         0x01                               ; DATA XREF=0x23505cdc
0x23505011                        db  0x00 ; '.'
0x23505012 0000                   movs       r0, r0
0x23505014 0000                   movs       r0, r0
0x23505016 0000                   movs       r0, r0
0x23505018 0000                   movs       r0, r0
0x2350501a 0000                   movs       r0, r0
0x2350501c                        dw         0x003d
0x2350501e                        dw         0x0060
0x23505020                        dw         0x004b
0x23505022                        dw         0x0020
0x23505024 0000                   movs       r0, r0
0x23505026 0000                   movs       r0, r0
0x23505028                        dd         0x234c12f8
0x2350502c                        dw         0x0003
0x2350502e 0000                   movs       r0, r0
0x23505030                        dd         0x23504c80
#endif
	{0}, //[7] = 23505050 
	{0}, //[8] = 23505090 
	{0}, //[9] = 235050D0 
	{0}, //[10] = 23505110 
	{0}, //[11] = 23505150 
	{0}, //[12] = 23505190 
	{0}, //[13] = 235051D0 
	{0}, //[14] = 23505210 
	{0}, //[15] = 23505250 
	{1, 0, 0, 0/*Data_8*/, 0x008e, 0x0060, 0x00e7, 0x0020, 0, &menu_main_graphic_item_background_dark_blue_top_round_left_right, 3, 0, &Data_23504d70}, //[16] = 23505290: Item 1 Value
#if 0
0x23505290                        db         0x01                               ; DATA XREF=0x23505ce0
0x23505291                        db  0x00 ; '.'
0x23505292 0000                   movs       r0, r0
0x23505294                        dd         0x00000000                         ; DATA XREF=dword_23504f70+640
0x23505298 0000                   movs       r0, r0
0x2350529a 0000                   movs       r0, r0
0x2350529c                        dw         0x008e
0x2350529e                        dw         0x0060
0x235052a0                        dw         0x00e7
0x235052a2                        dw         0x0020
0x235052a4 0000                   movs       r0, r0
0x235052a6 0000                   movs       r0, r0
0x235052a8                        dd         0x234c12f8
0x235052ac                        dw         0x0009
0x235052ae 0000                   movs       r0, r0
0x235052b0                        dd         0x23504d70
#endif
	{0}, //[17] = 235052D0 
	{0}, //[18] = 23505310 
	{0}, //[19] = 23505350 
	{0}, //[20] = 23505390 
	{0}, //[21] = 235053D0 
	{0}, //[22] = 23505410 
	{0}, //[23] = 23505450 
	{0}, //[24] = 23505490 
	{0}, //[25] = 235054D0 
	{0}, //[26] = 23505510 
	{0}, //[27] = 23505550 
	//23505590
};

static Graphic_Job_2_5 Data_23505c90 = //23505c90
{
	0, //uint8_t bData_0; //0
	0, //0xfa, //uint8_t bData_1; //1
	0x000c, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_23504e90[0], //Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	0x10, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	28, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
#if 0
0x23505c90                        db         0x00                               ; DATA XREF=0x23505ea4
0x23505c91                        db         0x00
0x23505c92                        dw         0x000c
0x23505c94                        db         0x04
0x23505c95                        db  0x00 ; '.'
0x23505c96 0000                   movs       r0, r0
0x23505c98                        dd         0x23504e90
0x23505c9c                        dd         menu_main_graphic_color_data
0x23505ca0                        db         0x10
0x23505ca1                        db  0x00 ; '.'
0x23505ca2 0000                   movs       r0, r0
0x23505ca4                        dd         0x00000000
0x23505ca8                        db         0x1c
0x23505ca9                        db         0x01
#endif
};

static Menu_Item Data_23505cd8[] = //23505cd8
{
	//[0]
	{
		0xffff, 
		0xffff, //0x100
		{
			&Data_23504e90[6], //23505010,
			&Data_23504e90[16], //23505290,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_2349b228, //void* onEvent; //0x1c = 28
		sub_2344f102, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 23505D04
#if 0
0x23505cd8                        dw         0xffff                             ; DATA XREF=sub_2349af7c+20, sub_2349b228+226, sub_2349b588+114, dword_23505e94, dword_23505e98
0x23505cda                        dw         0x0100
0x23505cdc                        dd         0x23505010
0x23505ce0                        dd         0x23505290
0x23505ce4 0000                   movs       r0, r0
0x23505ce6 0000                   movs       r0, r0
0x23505ce8 0000                   movs       r0, r0
0x23505cea 0000                   movs       r0, r0
0x23505cec 0000                   movs       r0, r0
0x23505cee 0000                   movs       r0, r0
0x23505cf0 0000                   movs       r0, r0
0x23505cf2 0000                   movs       r0, r0
0x23505cf4                        dd         sub_2349b228+1
0x23505cf8                        dd         sub_2344f102+1
#endif
	},
	//[1]
	//TODO!!!
};

static Menu Data_23505e90 = //23505e90
{
	0xffff,
	&Data_23505cd8[0], //Menu_Item* Data_4; //4
	&Data_23505cd8[0], //Menu_Item* Data_8; //8
	&Data_23504e90[1], //23504ed0, //Struct_235fdf74_Inner12* header; //12 = 0xc
	0, /*&Data_234df428*/ //23504f50 //Struct_235fdf74_Inner16* help; //16 = 0x10
	&Data_23505c90, //int graphicData; //20 = 0x14
	0, //9, //uint8_t maxItem; //0x18 = 24
	0, //int8_t currentItem; //0x19
	graphic_start_job_2_5, //void (*graphicHandler)(); //0x1c
	sub_2348de88, //void (*onNavigate)(); //0x20
	menu_net_radio_on_enter, //int (*onEnter)(int); //36 = 0x24
	sub_2349b588, //int (*onExit)(UI_Thread_Params*); //0x28
	0, //int Data_0x2c; //44 = 0x2c
	50, //int timeout; //48 = 0x30
	0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
	0, //sub_2348e0fa, void* (*Data_0x38)(struct FrontDisplay_Job*); //56
	//TODO!!!
#if 0
0x23505e90                        dw         0xffff                             ; DATA XREF=sub_2349af7c+18, sub_2349b228+220, aLpslistingphpg+60, aLpslistingphpg+80, sub_2349b50c+28, sub_2349b588+106, sub_2349b588+126, sub_2349b588+150, sub_2349b64e+14, sub_2349b64e+20, sub_2349b64e+28
0x23505e92 0000                   movs       r0, r0
0x23505e94                        dd         0x23505cd8                         ; DATA XREF=sub_2349b588+116, dword_23505ad4+28
0x23505e98                        dd         0x23505cd8                         ; DATA XREF=sub_2349af7c+20, sub_2349b228+226, sub_2349b588+114
0x23505e9c                        dd         0x23504ed0                         ; DATA XREF=aLpslistingphpg+62, sub_2349b588+132
0x23505ea0                        dd         0x23504f50                         ; DATA XREF=aLpslistingphpg+68, aLpslistingphpg+82, sub_2349b588+138, sub_2349b588+152
0x23505ea4                        dd         0x23505c90
0x23505ea8                        dw         0x0009
0x23505eaa 0000                   movs       r0, r0
0x23505eac                        dd         graphic_start_job_2_5
0x23505eb0                        dd         sub_2348de88+1
0x23505eb4                        dd         menu_net_radio_on_enter+1
0x23505eb8                        dd         sub_2349b588+1
0x23505ebc 0000                   movs       r0, r0
0x23505ebe 0000                   movs       r0, r0
0x23505ec0                        db         0x32
0x23505ec1                        db  0x00 ; '.'
0x23505ec2 0000                   movs       r0, r0
0x23505ec4 0000                   movs       r0, r0
0x23505ec6 0000                   movs       r0, r0
0x23505ec8                        dd         sub_2348e0fa+1
#endif
};


static uint8_t Data_2396e104[40]; //2396e104, size???

struct
{
	void* pOsdList; //2397ac68 +0
	void* (*Func_2397ac6c)(); //2397AC6C +4
	void (*Func_2397ac70)(); //2397AC70 +8
	int Data_2397ac74; //2397AC74 +0c
	int fill_2397AC78[280]; //2397AC78
	int Data_2397b0d8; //2397B0D8 +0x30
	int Data_2397b0dc; //2397B0DC +0x34
	int Data_2397b0e0; //2397B0E0 +0x38
	int Data_2397b0e4; //2397B0E4 +0x3c
	int Data_2397b0e8; //2397B0E8 +0x40
	int Data_2397b0ec; //2397B0Ec +0x44

} Data_2397ac6c;

static char menu_net_radio_http_get_request_string[400]; //2397b0f0
char Data_2397b280[200]; //2397b280
char Data_2397b348[200]; //2397b348



/* /  / 2348e0fa - todo */
void* sub_2348e0fa(FrontDisplay_Job* a)
{
#if 1
	console_send_string("sub_2348e0fa (todo.c): TODO\r\n");
#endif

	return NULL;
}


/* /  / 2349af7c - todo */
void sub_2349af7c()
{
#if 1
	console_send_string("sub_2349af7c (todo.c): TODO\r\n");
#endif

}


/* /  / 2349b010 - complete */
void sub_2349b010(char* a, int b)
{
#if 0
	console_send_string("sub_2349b010 (todo.c): TODO\r\n");
#endif

#if 0
    if ((a != 0) && (b != 0))
    {
        hex_dump("sub_2349b010", a, b);
    }
#endif

    char* pBuf = sub_2340147c/*sub_2342498c*/();

    if (a == 0)
    {
        pBuf[Data_2397ac6c.Data_2397b0dc] = 0;
        Data_2397ac6c.Data_2397b0d8 = Data_2397ac6c.Data_2397b0dc;
        Data_2397ac6c.Data_2397b0dc = 0;
        Data_2397ac6c.Data_2397b0e0 = 0;

        Data_2397ac6c.Func_2397ac6c = Data_2397ac6c.Func_2397ac70;
    }
    else
    {
        //loc_2349b046
        while (b--)
        {
            //loc_2349b036
            pBuf[Data_2397ac6c.Data_2397b0dc] = *a++;
            Data_2397ac6c.Data_2397b0dc = (uint16_t)(Data_2397ac6c.Data_2397b0dc + 1);
        } 
    }
}


/* /  / 2349b04c - todo */
void menu_net_radio_web_get_request(char* a, void (*cbk)(void))
{
#if 0
	console_send_string("menu_net_radio_web_get_request (todo.c): TODO\r\n");
#endif

	if (Data_2397ac6c.Data_2397ac74 != 0)
	{
		snprintf(&menu_net_radio_http_get_request_string[0], 399, 
			"GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Tibor\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: de-de,de;q=0.8,en-us;q=0.5,en;q=0.3\r\nAccept-Encoding: deflate\r\nAccept-Charset: ISO-8859-1\r\nConnection: keep-alive\r\nCookie: %s\r\n\r\n",
			a, "85.214.222.229", (uint8_t*)(&Data_2397ac6c.Data_2397ac74));
	}
	else
	{
		snprintf(&menu_net_radio_http_get_request_string[0], 399, 
			"GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Tibor\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: de-de,de;q=0.8,en-us;q=0.5,en;q=0.3\r\nAccept-Encoding: deflate\r\nAccept-Charset: ISO-8859-1\r\nConnection: keep-alive\r\n\r\n",
			a, "85.214.222.229");
	}

	Data_2397ac6c.Data_2397b0e0 = web_client_send_request("85.214.222.229", 80, 
		&menu_net_radio_http_get_request_string[0], sub_2349b010);

	Data_2397ac6c.Func_2397ac70 = cbk;
}


/* 234814de /  / 2349b094 - todo */
int sub_2349b094()
{
#if 0
	console_send_string("sub_2349b094 (todo.c): TODO\r\n");
#endif

	char* r4 = sub_2340147c/*sub_2342498c*/();
	int r5 = Data_2397ac6c.Data_2397b0d8;

	while (r5--)
	{
		//loc_2349b0a2
		if (0 == strncmp(r4, "PHPSESSID=", 10))
		{
			int r3 = 100;
			uint8_t* r0 = r4;
			uint8_t* r2 = (uint8_t*)(&Data_2397ac6c.Data_2397ac74);

			while (r3--)
			{
				//loc_2349b0ba
				if ((r0[0] == ';') || (r0[0] == 0x0a) || (r0[0] == 0x0d))
				{
					//->loc_2349b0d2
					break;
				}

				*r2 = *r0++;
				r2++;
			}
		}
		//loc_2349b0d2
		if (0 == strncmp(r4, "loginOK", 7))
		{
			//0x2349b0e0
			if (Data_2397ac6c.Data_2397b0e4 == 0)
			{
				menu_net_radio_web_get_request("senderliste/top.php", sub_2349b146);
			}
			else
			{
				menu_net_radio_web_get_request(&Data_2397b280[0], sub_2349b146);
			}
			//->loc_2349b108
			break;
		}
		//loc_2349b0f4
		if (0 == strncmp(r4, "loginNOK", 8))
		{
			//->loc_2349b108
			break;
		}
		//0x2349b102
		r4++;
	} //while (r5--)
	//loc_2349b108
	return 0;
}


/* 2348155a /  / 2349b10c - todo */
void menu_net_radio_list_server_login()
{
#if 0
	console_send_string("menu_net_radio_list_server_login (todo.c): TODO\r\n");
#endif

	Struct_234012b0_a sp_0xc; 
	Struct_234012b0_b sp4;

	if (network_pfGetMac != NULL)
	{
		(network_pfGetMac)(&sp_0xc, &sp4);
	}

	Data_23504b3c[0] = 0;

    snprintf(&Data_2397b348[0], 200, 
        "%s/mylogin.php?mac=%s", 
        "senderliste",
        &sp_0xc.bData[0]);

	menu_net_radio_web_get_request(&Data_2397b348[0], sub_2349b094);
}


/* /  / 2349b146 - todo */
static void sub_2349b146()
{
#if 1
	console_send_string("sub_2349b146 (todo.c): TODO\r\n");
#endif

}


/* /  / 2349b228 - todo */
static int sub_2349b228(Struct_2348dc50* sp_0x80)
{
#if 1
	console_send_string("sub_2349b228 (todo.c): TODO\r\n");
#endif

	Struct_2348dc50 sp_0x1c;

	if (sp_0x80 == NULL)
	{
		//0x2349b244
		if (Data_2397ac6c.Func_2397ac6c != NULL)
		{
			//0x2349b24a
			Data_2397ac6c.Func_2397ac6c = (Data_2397ac6c.Func_2397ac6c)();
			//0x2349b250

			//TODO!!!
		}
		//loc_2349b270

		//loc_2349b26e
		//->loc_2349b506
	}
	else
	{
		//loc_2349b2ba
		sp_0x1c = *sp_0x80;

		if (sp_0x1c.Data_0 & (1 << 4)) //TODO!!!
		{
			//0x2349b2ca
		}
		//loc_2349b348 -> loc_2349b4b4
		else if (sp_0x1c.Data_0 & (1 << 11)) //TODO!!!
		{
			//0x2349b4ba
		}
		//loc_2349b4cc
		else if (sp_0x1c.Data_0 & (1 << 9)) //TODO!!!
		{
			//0x2349b4d2
		}
		//loc_2349b4da
		else if (sp_0x1c.Data_0 & (1 << 10)) //TODO!!!
		{
			//0x2349b4e0
		}
		//loc_2349b4f0
		else if ((sp_0x1c.Data_0 & (1 << 2)) || //TODO!!!
			(sp_0x1c.Data_0 & (1 << 3))) //TODO!!!
		{
			//loc_2349b4fc
		}
		//loc_2349b506
	}
	//loc_2349b506
	return 0;
}


/* /  / 2349b50c - todo */
static int menu_net_radio_on_enter()
{
#if 0
	console_send_string("menu_net_radio_on_enter (todo.c): TODO\r\n");
#endif

	Struct_2348dc50 sp4;

	sprintf(&Data_2396e104[0], "Internet Radio");

    memset(&sp4, 0, sizeof(Struct_2348dc50));

    sp4.Data_0x10 = NULL; //r4
    sp4.pMenu = Data_23504b30;
    sp4.wData_0x1c = 0; //r4
    sp4.Data_0x54 = 0; //r4
    sp4.Data_0x14 = sub_2349af7c;
    sp4.Data_0x18 = sub_2348dbf8;
    sp4.wData_0x1e = 0; //r4
    sp4.wCurrentItem = 0; //r4
	sp4.wData_0x20 = 0; //r4
    sp4.wData_0x24 = 0; //r4
    sp4.wData_0x26 = 10;
    sp4.bData_0x58 = 10;
    sp4.bData_0x5c = 7;
    sp4.bData_0x5d = 8;
    sp4.bData_0x5e = 9;
    sp4.bData_0x59 = 2;
    sp4.bData_0x5a = 10;
    sp4.bData_0x5b = 9;

	Data_2397ac6c.pOsdList = osd_list_create(&sp4);

	Data_2397ac6c.Func_2397ac6c = NULL; //r4
	Data_2397ac6c.Data_2397b0dc = 0; //r4
	Data_2397ac6c.Data_2397b0e4 = 0; //r4
	Data_2397ac6c.Data_2397b0e8 = 0; //r4
	Data_2397ac6c.Data_2397b0ec = 0; //r4
	Data_2397ac6c.Data_2397b0e0 = 0; //r4
	Data_2397ac6c.Data_2397ac74 = 0; //r4

	menu_net_radio_list_server_login();

	return 0;
}


/* /  / 2349b588 - todo */
static void sub_2349b588()
{
#if 1
	console_send_string("sub_2349b588 (todo.c): TODO\r\n");
#endif

}


/* /  / 2349b64e - todo */
int menu_net_radio_osd_entry(UI_Thread_Params* a)
{
#if 1
	console_send_string("menu_net_radio_osd_entry (todo.c): TODO\r\n");
#endif

	if (0 != network_is_link_up())
	{
		menu_stack_operate(Data_23504b30);
		osd_list_draw(Data_23504b30, 1);
		sub_2343d51e(Data_23504b30, a);
#if 0 //TODO!!!
		frontdisplay_start_text(sub_2348e0fa);
#endif		
	}

	return 0;
}

#endif
