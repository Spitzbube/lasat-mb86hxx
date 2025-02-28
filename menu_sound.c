#include "data.h"
#include "graphic.h"
#include "menu.h"

#pragma thumb

#ifndef VDR110

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12a4; //234c12a4
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c1334; //234c1334
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c1340; //234c1340

static int sub_23490fe2();
static int menu_sound_on_enter();
static Menu menu_sound;
static uint8_t Data_23970e1c[]; //23970e1c
static uint8_t Data_23970f3c[]; //23970f3c
static uint8_t Data_23970fb4[]; //23970fb4


static Menu* menu_sound_p = &menu_sound; //234eae70


static Graphic_Job_2_5_Item_Text Data_234eae7c = //234eae7c
{
	0, 0x0155, 0x0064, 0x0238, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_23970fb4[0], //Data_0x10
#if 0
0x234eae7c                        db         0x00                               ; DATA XREF=sub_23490fe2+4, dword_234ea5d8+1408, 0x234eb19c
0x234eae7d                        db         0x00
0x234eae7e                        dw         0x0155
0x234eae80                        dw         0x0064
0x234eae82                        dw         0x0238
0x234eae84                        dw         0x0080
0x234eae86                        db         0x01
0x234eae87                        db         0x04
0x234eae88                        db         0x09
0x234eae89                        db         0x01
0x234eae8a 0000                   movs       r0, r0
0x234eae8c                        dd         0x23970fb4                         ; DATA XREF=sub_23490fe2+6
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eaec4 = //234eaec4
{
	0, 0x0051, 0x002c, 0x012a, 0x004f, 0x01, 0x06, 0x02, 0x00, &Data_23970e1c[0], //Data_0x10
#if 0
0x234eaec4                        db         0x00                               ; DATA XREF=0x234eaf9c, 0x234eb2dc
0x234eaec5                        db         0x00
0x234eaec6                        dw         0x0051
0x234eaec8                        dw         0x002c
0x234eaeca                        dw         0x012a
0x234eaecc                        dw         0x004f
0x234eaece                        db         0x01
0x234eaecf                        db         0x06
0x234eaed0                        db         0x02
0x234eaed1                        db         0x00
0x234eaed2 0000                   movs       r0, r0
0x234eaed4                        dd         0x23970e1c
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eaef4 = //234eaef4
{
	0, 0x0051, 0x0064, 0x012a, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_23970f3c[0], //Data_0x10
#if 0
0x234eaef4                        db         0x00                               ; DATA XREF=0x234eb09c
0x234eaef5                        db         0x00
0x234eaef6                        dw         0x0051
0x234eaef8                        dw         0x0064
0x234eaefa                        dw         0x012a
0x234eaefc                        dw         0x0080
0x234eaefe                        db         0x01
0x234eaeff                        db         0x04
0x234eaf00                        db         0x09
0x234eaf01                        db         0x01
0x234eaf02 0000                   movs       r0, r0
0x234eaf04                        dd         0x23970f3c
#endif
};


static Graphic_Job_2_5_Item Data_234eaf3c[] = //234eaf3c
{
	{0}, //[0] = 234eaf3c
	{1, 0, 0, 0/*Data_8*/, 0x003d, 0x0029, 0x00ed, 0x0026, 0, &Data_234c12a4/*Data_0x18*/, 2, 0, &Data_234eaec4}, //[1] = 234EAF7C: Header
#if 0
0x234eaf7c                        db         0x01                               ; DATA XREF=0x234eb718
0x234eaf7d                        db  0x00 ; '.'
0x234eaf7e 0000                   movs       r0, r0
0x234eaf80 0000                   movs       r0, r0
0x234eaf82 0000                   movs       r0, r0
0x234eaf84 0000                   movs       r0, r0
0x234eaf86 0000                   movs       r0, r0
0x234eaf88                        dw         0x003d
0x234eaf8a                        dw         0x0029
0x234eaf8c                        dw         0x00ed
0x234eaf8e                        dw         0x0026
0x234eaf90 0000                   movs       r0, r0
0x234eaf92 0000                   movs       r0, r0
0x234eaf94                        dd         0x234c12a4
0x234eaf98                        dw         0x0002
0x234eaf9a 0000                   movs       r0, r0
0x234eaf9c                        dd         0x234eaec4
#endif
	{0}, //[2] = 234EAFBC
	{0}, //[3] = 234EAFFC
	{0}, //[4] = 234EB03C
	{1, 0, 0, 0/*Data_8*/, 0x003d, 0x0060, 0x00ed, 0x0020, 0, &Data_234c1334/*Data_0x18*/, 2, 0, &Data_234eaef4}, //[5] = 234EB07C: 'Sound settings' Caption
#if 0
0x234eb07c                        db         0x01                               ; DATA XREF=0x234eb608
0x234eb07d                        db  0x00 ; '.'
0x234eb07e 0000                   movs       r0, r0
0x234eb080 0000                   movs       r0, r0
0x234eb082 0000                   movs       r0, r0
0x234eb084 0000                   movs       r0, r0
0x234eb086 0000                   movs       r0, r0
0x234eb088                        dw         0x003d
0x234eb08a                        dw         0x0060
0x234eb08c                        dw         0x00ed
0x234eb08e                        dw         0x0020
0x234eb090 0000                   movs       r0, r0
0x234eb092 0000                   movs       r0, r0
0x234eb094                        dd         0x234c1334
0x234eb098                        dw         0x0009
0x234eb09a 0000                   movs       r0, r0
0x234eb09c                        dd         0x234eaef4
#endif
	{0}, //[6] = 234EB0BC
	{0}, //[7] = 234EB0FC
	{0}, //[8] = 234EB13C
	{1, 0, 0, 0/*Data_8*/, 0x0141, 0x0060, 0x00f7, 0x0020, 0, &Data_234c1340/*Data_0x18*/, 2, 0, &Data_234eae7c}, //[9] = 234EB17C: 'Sound settings' Value
#if 0
0x234eb17c                        db         0x01                               ; DATA XREF=0x234eb60c
0x234eb17d                        db  0x00 ; '.'
0x234eb17e 0000                   movs       r0, r0
0x234eb180 0000                   movs       r0, r0
0x234eb182 0000                   movs       r0, r0
0x234eb184 0000                   movs       r0, r0
0x234eb186 0000                   movs       r0, r0
0x234eb188                        dw         0x0141
0x234eb18a                        dw         0x0060
0x234eb18c                        dw         0x00f7
0x234eb18e                        dw         0x0020
0x234eb190 0000                   movs       r0, r0
0x234eb192 0000                   movs       r0, r0
0x234eb194                        dd         0x234c1340
0x234eb198 0900                   movs       r1, r1
0x234eb19a 0000                   movs       r0, r0
0x234eb19c                        dd         0x234eae7c
#endif
	{0}, //[10] = 234EB1BC
	{0}, //[11] = 234EB1FC
	{0}, //[12] = 234EB23C
    //234EB27C
};

static Graphic_Job_2_5 Data_234eb5bc = //234eb5bc
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x001e, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234eaf3c[0], //pItems; //8
	&menu_main_graphic_color_data, //Struct_23414b38_b_Inner_0xc* pColorData; //12
	16, //uint8_t numColors; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	13, //uint8_t bNumItems; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
	0, //0x1c
	0, //0x20
#if 0
0x234eb5bc                        db         0x00                               ; DATA XREF=sub_23490d82+16, 0x234eb720
0x234eb5bd                        db         0xfa
0x234eb5be                        dw         0x001e
0x234eb5c0                        db         0x04
0x234eb5c1                        db  0x00 ; '.'
0x234eb5c2 0000                   movs       r0, r0
0x234eb5c4                        dd         0x234eaf3c
0x234eb5c8                        dd         menu_main_graphic_color_data
0x234eb5cc                        db         0x10
0x234eb5cd                        db  0x00 ; '.'
0x234eb5ce 0000                   movs       r0, r0
0x234eb5d0                        dd         0x00000000
0x234eb5d4                        db         0x0d
0x234eb5d5                        db         0x01
#endif
};

static Menu_Item menu_sound_items[] = //234eb604
{
	//[0]
	{
		0x0074, //'Soundeinstellung' / 'Sound settings'
		0xffff, //0xf4, //uint16_t wData_2; //2
		{
			&Data_234eaf3c[5], //234eb07c,
			&Data_234eaf3c[9], //234eb17c,
		}, //int fill_4[5]; //4
		sub_23490fe2, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		0, //menu_sound_settings_change, //void* onEvent; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//234EB630
#if 0
0x234eb604                        dw         0x0074                             ; DATA XREF=menu_sound_channel_tv_change+14, sub_2349100c+12, 0x234eb710, 0x234eb714
0x234eb606                        dw         0x00f4
0x234eb608                        dd         0x234eb07c
0x234eb60c                        dd         0x234eb17c
0x234eb610 0000                   movs       r0, r0
0x234eb612 0000                   movs       r0, r0
0x234eb614 0000                   movs       r0, r0
0x234eb616 0000                   movs       r0, r0
0x234eb618 0000                   movs       r0, r0
0x234eb61a 0000                   movs       r0, r0
0x234eb61c                        dd         sub_23490fe2+1
0x234eb620                        dd         menu_sound_settings_change+1
0x234eb624                        dd         menu_item_event_thread+1
#endif
	},

};

static Menu menu_sound = //234eb70c
{
	0x0089, //"Ton" / "Sound"
	&menu_sound_items[0], //Menu_Item* Data_4; //4
	&menu_sound_items[0], //Menu_Item* Data_8; //8
	&Data_234eaf3c[1], //234eaf7c, //Struct_235fdf74_Inner12* header; //12 = 0xc
	0, //234eaffc, //Struct_235fdf74_Inner16* help; //16 = 0x10
	&Data_234eb5bc, //Struct_235fdf74_Inner20* graphicData; //20 = 0x14
	0, //2, //uint8_t maxItem; //0x18 = 24
	0, //int8_t currentItem; //0x19
	graphic_start_job_2_5, //void (*Data_0x1c)(); //0x1c
	menu_items_navigate, //void (*onNavigate)(); //0x20
	menu_sound_on_enter, //void (*onEnter)(); //36 = 0x24
	0, //sub_2349113a, //int (*onExit)(); //0x28
	0, //int Data_0x2c; //44 = 0x2c
	0, //int Data_0x30; //48
	0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
	0, //void* (*Data_0x38)(struct FrontDisplay_Job*); //56
	//0x3c = 60?
#if 0
0x234eb70c                        dw         0x0089                             ; DATA XREF=sub_23490d82+10, menu_sound_channel_tv_change+8, sub_2349100c+10, menu_sound_entry+6, menu_sound_entry+12, menu_sound_entry+18, menu_sound_p, 0x234eae74
0x234eb70e                        db  0x00 ; '.'
0x234eb70f                        db  0x00 ; '.'
0x234eb710                        dd         menu_sound_items
0x234eb714                        dd         menu_sound_items                   ; DATA XREF=menu_sound_channel_tv_change+14, sub_2349100c+12
0x234eb718                        dd         0x234eaf7c
0x234eb71c                        dd         0x234eaffc
0x234eb720                        dd         0x234eb5bc                         ; DATA XREF=sub_23490d82+16
0x234eb724                        db  0x02 ; '.'
0x234eb725                        db  0x00 ; '.'
0x234eb726                        db  0x00 ; '.'
0x234eb727                        db  0x00 ; '.'
0x234eb728                        dd         graphic_start_job_2_5
0x234eb72c                        dd         menu_items_navigate+1
0x234eb730                        dd         sub_2349100c+1
0x234eb734                        dd         sub_2349113a+1
#endif
};



static struct
{
    PSI_Program Data_23970a78; //23970a78 +0x398 = 23970E10
    uint16_t wData_23970e10; //23970e10
    uint16_t fill_23970e12; //23970e12
    uint8_t bData_23970e14; //23970e14
    uint8_t bData_23970e15; //23970e15
    uint8_t bData_23970e16; //23970e16
    uint8_t bData_23970e17; //23970e17
    uint8_t bData_23970e18; //23970e18
    uint8_t bData_23970e19; //23970e19
} Data_23970e10;


static uint8_t Data_23970e1c[40]; //23970e1c, size???
static uint8_t Data_23970f3c[40]; //23970f3c, size???
static uint8_t Data_23970fb4[40]; //23970fb4, size???



/* /  / 23490fe2 - todo */
int sub_23490fe2()
{
#if 0
	console_send_string("sub_23490fe2 (menu_sound.c): TODO\r\n");
#endif

    uint8_t* r1 = Data_234eae7c.pString;
    int r0;

    switch (Data_23970e10.bData_23970e16)
    {
        case 0:
            //loc_23490ffa: 'Stereo'
            r0 = 0x80;
            break;

        case 1:
            //loc_23490ffe: 'Mono links'
            r0 = 0xc7;
            break;

        case 2:
            //loc_23491002: 'Mono rechts'
            r0 = 0xc8;
            break;

        default:
            //loc_23490ffa: 'Stereo'
            r0 = 0x80;
            break;
    }

    text_table_get_string(r0, r1, 38);
}



/* /  / 2349100c - todo */
int menu_sound_on_enter()
{
#if 0
	console_send_string("menu_sound_on_enter (menu_sound.c): TODO\r\n");
#endif

    Struct_2340bf0c sp_0x40;
    Transponder sp_0x28;
    Channel sp;

    int r7 = 0;
    Menu_Item* r5 = menu_sound.Data_8;

    /*sub_2340e9e8*/sub_2340bf0c(&sp_0x40);
    sub_2340bf94(sp_0x40.wCurrentChannel, &sp, &sp_0x28);

    Data_23970e10.wData_23970e10 = channel_get_audio_pid();

    if (0 == /*sub_234091ac*/sub_234066d0(main_hPSIDecoder1, &Data_23970e10.Data_23970a78))
    {
        r7 = 1;
    }
    //loc_23491048
    Data_23970e10.bData_23970e14 = 0;
    Data_23970e10.bData_23970e15 = 0;
    Data_23970e10.bData_23970e16 = 0;

    if (sp.wFlags_2 & (1 << 1))
    {
        Data_23970e10.bData_23970e16 = 1;
    }
    else if (sp.wFlags_2 & (1 << 2))
    {
        Data_23970e10.bData_23970e16 = 2;
    }
    //loc_23491066
    if (r7 != 0)
    {
        //0x2349106a

        //TODO!!!
    }
    //loc_23491126
    Data_23970e10.bData_23970e17 = Data_23970e10.bData_23970e15;
    Data_23970e10.bData_23970e18 = Data_23970e10.wData_23970e10 >> 8;
    Data_23970e10.bData_23970e19 = Data_23970e10.bData_23970e16;

    return 0;
}



/*  /  / 2349118a - todo */
int menu_sound_entry(UI_Thread_Params* p)
{
#if 0
	console_send_string("menu_sound_entry (menu_sound.c): TODO\r\n");
#endif

	menu_stack_operate(menu_sound_p);

	menu_initialize(menu_sound_p);

	sub_2343d51e(menu_sound_p, p);

	return 0;
}

#endif
