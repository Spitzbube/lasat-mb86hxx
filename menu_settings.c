
#include "data.h"
#include "graphic.h"
#include "menu.h"

#pragma thumb

#ifndef VDR110

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12f8; //234c12f8
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c12d4; //234c12d4
extern Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234c134c; //234c134c

static uint8_t Data_2396b4c0[]; //2396b4c0
static uint8_t Data_2396b4e8[]; //2396b4e8
static uint8_t Data_2396b510[]; //2396b510

extern int menu_general_settings_entry(UI_Thread_Params*);
extern int menu_picture_entry(UI_Thread_Params*);
extern int menu_sound_entry(UI_Thread_Params*);

static Menu_Item menu_settings_items[]; //234dfb30

static Menu menu_settings;
static Graphic_Job_2_5_Item Data_234df368[]; //234df368
static Graphic_Job_2_5 menu_settings_graphic_data;

static Menu* menu_settings_p = &menu_settings; //234df1c0
static Menu menu_settings =  //234df1cc
{
		0x004a, //""
		&menu_settings_items[0], //Menu_Item* Data_4; //4
		&menu_settings_items[0], //Menu_Item* Data_8; //8
		&Data_234df368[1], //234df3a8, //Struct_235fdf74_Inner12* header; //12 = 0xc
		/*&Data_234df428*/0, //Struct_235fdf74_Inner16* help; //16 = 0x10
		&menu_settings_graphic_data, //int graphicData; //20 = 0x14
		2, //6, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		graphic_start_job_2_5, //void (*Data_0x1c)(); //0x1c
		menu_items_navigate, //void (*onNavigate)(); //0x20
		//TODO!!!
#if 0
		0x234df1cc                        dw         0x004a                             ; DATA XREF=menu_settings_entry+6, menu_settings_entry+12, menu_settings_entry+18, sub_2348c74a+6, sub_2348c74a+34, sub_2348c7aa+6, sub_2348c7aa+14, sub_2348c7aa+28, sub_2348c7aa+52, sub_2348c7aa+122, sub_2348c844+36
		0x234df1ce                        dw         0x0000
		0x234df1d0                        dd         0x234dfb30
		0x234df1d4                        dd         0x234dfb30
		0x234df1d8                        dd         0x234df3a8
		0x234df1dc                        dd         0x234df428
		                              dword_234df1e0:
		0x234df1e0                        dd         0x234dfae8                         ; DATA XREF=sub_2348c74a+16, sub_2348c74a+42, sub_2348c7aa+10, sub_2348c7aa+60, sub_2348c844+40
		0x234df1e4                        db         0x06                               ; DATA XREF=sub_2348c74a+10, sub_2348c74a+14, sub_2348c7aa+34, sub_2348c7aa+56
		0x234df1e5                        db  0x00 ; '.'
		0x234df1e6 0000                   movs       r0, r0
		0x234df1e8                        dd         graphic_start_job_2_5
		0x234df1ec                        dd         sub_2344dbb8+1
		0x234df1f0                        dd         0x00000000
		0x234df1f4                        dd         0x00000000
		0x234df1f8                        dd         0x00000000
		0x234df1fc                        dd         0x00000000
		0x234df200                        dd         0x00000000
		0x234df204                        dd         0x00000000
#endif
};

static uint8_t Data_2396b3a0[]; //2396b3a0, size???

static Graphic_Job_2_5_Item_Text Data_234df260 = //234df260
{
	0, 0x0051, 0x002c, 0x0136, 0x004f, 0x01, 0x06, 0x02, 0x00, &Data_2396b3a0[0], 0, 0, 0
#if 0
0x234df260                        db         0x00                               ; DATA XREF=0x234df3c8
0x234df261                        db         0x00
0x234df262                        dw         0x0051
0x234df264                        dw         0x002c
0x234df266                        dw         0x0136
0x234df268                        dw         0x004f
0x234df26a                        db         0x01
0x234df26b                        db         0x06
0x234df26c                        db         0x02
0x234df26d                        db         0x00
0x234df26e 0000                   movs       r0, r0
0x234df270                        dd         0x2396b3a0                         ; CODE XREF=dword_234ded68+244
0x234df274                        dw         0x0000
0x234df276                        db         0x00
0x234df277                        db         0x00
#endif
};

static Graphic_Job_2_5_Item_Text Data_234df290 = //234df290
{
	0, 0x0051, 0x0064, 0x0136, 0x0080, 0x01, 0x04, 0x09, 0x01, &Data_2396b4c0[0], 0, 0, 0
#if 0
0x234df290                        db         0x00                               ; DATA XREF=0x234df4c8
0x234df291                        db  0x00 ; '.'
0x234df292                        dw         0x0051
0x234df294                        dw         0x0064
0x234df296                        dw         0x0136
0x234df298                        dw         0x0080
0x234df29a                        db         0x01
0x234df29b                        db         0x04
0x234df29c                        db         0x09
0x234df29d                        db         0x01
0x234df29e 0000                   movs       r0, r0
0x234df2a0                        dd         0x2396b4c0
0x234df2a4                        dw         0x0000
0x234df2a6                        db         0x00
0x234df2a7                        db         0x00
#endif
};

static Graphic_Job_2_5_Item_Text Data_234df2a8 = //234df2a8
{
	0, 0x0051, 0x0084, 0x0136, 0x00a0, 0x01, 0x04, 0x09, 0x01, &Data_2396b4e8[0], 0, 0, 0
#if 0
0x234df2a8                        db         0x00                               ; DATA XREF=0x234df508
0x234df2a9                        db  0x00 ; '.'
0x234df2aa                        dw         0x0051
0x234df2ac                        dw         0x0084
0x234df2ae                        dw         0x0136
0x234df2b0                        dw         0x00a0
0x234df2b2                        db         0x01
0x234df2b3                        db         0x04
0x234df2b4                        db         0x09
0x234df2b5                        db         0x01
0x234df2b6 0000                   movs       r0, r0
0x234df2b8                        dd         0x2396b4e8
0x234df2bc                        dw         0x0000
0x234df2be                        db         0x00
0x234df2bf                        db         0x00
#endif
};

static Graphic_Job_2_5_Item_Text Data_234df2c0 = //234df2c0
{
	0, 0x0051, 0x00a4, 0x0136, 0x00c0, 0x01, 0x04, 0x09, 0x01, &Data_2396b510[0], 0, 0, 0
#if 0
0x234df2c0                        db         0x00                               ; DATA XREF=0x234df548
0x234df2c1                        db         0x00
0x234df2c2                        dw         0x0051
0x234df2c4                        dw         0x00a4
0x234df2c6                        dw         0x0136
0x234df2c8                        dw         0x00c0
0x234df2ca                        db         0x01
0x234df2cb                        db         0x04
0x234df2cc                        db         0x09
0x234df2cd                        db         0x01
0x234df2ce 0000                   movs       r0, r0
0x234df2d0                        dd         0x2396b510
#endif
};

static Graphic_Job_2_5_Item Data_234df368[15] = //234df368
{
	{0}, //[0] = 234df368 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x29, 0xf9, 0x26, 0, &Data_234c134c/*Data_0x18*/, 2, 0, &Data_234df260/*Data_0x20*/}, //[1] = 234DF3A8: header
#if 0
0x234df3a8                        db         0x01                               ; DATA XREF=0x234df1d8
0x234df3a9                        db         0x00
0x234df3aa                        db  0x00 ; '.'
0x234df3ab                        db  0x00 ; '.'
0x234df3ac                        dd         0x234df24c
0x234df3b0                        dd         0x00000000
0x234df3b4                        dw         0x003d
0x234df3b6                        dw         0x0029
0x234df3b8                        dw         0x00f9
0x234df3ba                        dw         0x0026
0x234df3bc                        dw         0x0000
0x234df3be                        db  0x00 ; '.'
0x234df3bf                        db  0x00 ; '.'
0x234df3c0                        dd         0x234c134c
0x234df3c4                        dw         0x0002
0x234df3c6                        dw         0x0000
0x234df3c8                        dd         0x234df260
0x234df3cc                        dd         0x00000000
0x234df3d0                        dd         0x00000000
0x234df3d4                        dd         0x00000000
0x234df3d8                        dd         0x00000000
0x234df3dc                        dd         0x00000000
0x234df3e0                        dd         0x00000000
0x234df3e4                        dd         0x00000000
#endif
	{0}, //[2] = 234DF3E8 
	{0}, //[3] = 234DF428 
	{0}, //[4] = 234DF468 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x60, 0xf9, 0x20, 0, &Data_234c12f8/*Data_0x18*/, 9, 0, &Data_234df290/*Data_0x20*/}, //[5] = 234DF4A8
#if 0
0x234df4a8                        db         0x01                               ; DATA XREF=0x234dfb34
0x234df4a9                        db         0x00
0x234df4aa 0000                   movs       r0, r0
0x234df4ac                        dd         0x234df250
0x234df4b0                        dd         0x00000000
0x234df4b4                        dw         0x003d
0x234df4b6                        dw         0x0060
0x234df4b8                        dw         0x00f9
0x234df4ba                        dw         0x0020
0x234df4bc 0000                   movs       r0, r0
0x234df4be 0000                   movs       r0, r0
0x234df4c0                        dd         0x234c12f8
0x234df4c4                        dw         0x0009
0x234df4c6                        dw         0x0000
0x234df4c8                        dd         0x234df290
0x234df4cc                        dd         0x00000000
0x234df4d0                        dd         0x00000000
0x234df4d4                        dd         0x00000000
0x234df4d8                        dd         0x00000000
0x234df4dc                        dd         0x00000000
0x234df4e0                        dd         0x00000000
0x234df4e4                        dd         0x00000000
#endif 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0x80, 0xf9, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234df2a8/*Data_0x20*/}, //[6] = 234DF4E8
#if 0
0x234df4e8                        db         0x01                               ; DATA XREF=0x234dfb60
0x234df4e9                        db         0x00
0x234df4ea 0000                   movs       r0, r0
0x234df4ec                        dd         0x234df250
0x234df4f0                        dd         0x00000000
0x234df4f4                        dw         0x003d
0x234df4f6                        dw         0x0080
0x234df4f8                        dw         0x00f9
0x234df4fa                        dw         0x0020
0x234df4fc 0000                   movs       r0, r0
0x234df4fe 0000                   movs       r0, r0
0x234df500                        dd         0x234c12d4
0x234df504                        dw         0x0009
0x234df506                        dw         0x0000
0x234df508                        dd         0x234df2a8
0x234df50c                        dd         0x00000000
0x234df510                        dd         0x00000000
0x234df514                        dd         0x00000000
0x234df518                        dd         0x00000000
0x234df51c                        dd         0x00000000
0x234df520                        dd         0x00000000
0x234df524                        dd         0x00000000
#endif 
	{1, 0, 0, 0/*Data_8*/, 0x3d, 0xa0, 0xf9, 0x20, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234df2c0/*Data_0x20*/}, //[7] = 234DF528: Sound
#if 0
0x234df528                        db         0x01                               ; DATA XREF=0x234dfb8c
0x234df529                        db  0x00 ; '.'
0x234df52a 0000                   movs       r0, r0
0x234df52c                        dd         0x234df250
0x234df530 0000                   movs       r0, r0
0x234df532 0000                   movs       r0, r0
0x234df534                        dw         0x003d
0x234df536                        dw         0x00a0
0x234df538                        dw         0x00f9
0x234df53a                        dw         0x0020
0x234df53c 0000                   movs       r0, r0
0x234df53e 0000                   movs       r0, r0
0x234df540                        dd         0x234c12d4
0x234df544                        dw         0x0009
0x234df546 0000                   movs       r0, r0
0x234df548                        dd         0x234df2c0
#endif
	{0}, //[8] = 234DF568 
	{0}, //[9] = 234DF5A8 
	{0}, //[10] = 234DF5E8 
	{0}, //[11] = 234DF628 
	{0}, //[12] = 234DF668 
	{0}, //[13] = 234DF6A8 
	{0}, //[14] = 234DF6E8 
};

static Graphic_Job_2_5 menu_settings_graphic_data = //234dfae8
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x001d, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&Data_234df368[0], //Graphic_Job_2_5_Item* pItems; //8
	&menu_main_graphic_color_data, //Graphic_Color_Data* Data_0xc; //12
	0x10, //uint8_t bData_0x10; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	15, //uint8_t bData_0x18; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
	0, //0x1c
	0, //0x20
#if 0
0x234dfae8                        db  0x00 ; '.'                                ; DATA XREF=sub_2348c74a+16, sub_2348c74a+42, sub_2348c7aa+10, sub_2348c7aa+60, sub_2348c844+40, dword_234df1e0
0x234dfae9                        db  0xfa ; '.'
0x234dfaea                        dw         0x001d
0x234dfaec                        db         0x04
0x234dfaed                        db  0x00 ; '.'
0x234dfaee 0000                   movs       r0, r0
0x234dfaf0                        dd         0x234df368                         ; DATA XREF=sub_2348c74a+18, sub_2348c74a+32, sub_2348c74a+50, sub_2348c74a+60, sub_2348c7aa+16, sub_2348c844+42
0x234dfaf4                        dd         0x234c123c
0x234dfaf8                        db         0x10
0x234dfaf9                        db  0x00 ; '.'
0x234dfafa 0000                   movs       r0, r0
0x234dfafc 0000                   movs       r0, r0
0x234dfafe 0000                   movs       r0, r0
0x234dfb00                        db         0x0f
0x234dfb01                        db         0x01
0x234dfb02 0000                   movs       r0, r0
0x234dfb04                        dd         0x00000000
0x234dfb08                        dd         0x00000000
#endif
};

static Menu_Item menu_settings_items[] = //23492f98 +4 //234dfb30
{
	//[0]
	{
		0x50, //80, //"Allgemein"
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234df368[5], //234df4a8,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_general_settings_entry, //void* onEvent; //0x1c = 28
		menu_event_thread, //void* inputThreadFunc; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234DFB5C
#if 0
		0x234dfb30                        dw         0x0050                             ; DATA XREF=0x234df1d0, 0x234df1d4
		0x234dfb32                        dw         0x00f3
		0x234dfb34                        dd         0x234df4a8
		0x234dfb38                        dd         0x00000000
		0x234dfb3c                        dd         0x00000000
		0x234dfb40                        dd         0x00000000
		0x234dfb44                        dd         0x00000000
		0x234dfb48                        dd         0x00000000
		0x234dfb4c                        dd         sub_23490aa4+1
		0x234dfb50                        dd         menu_event_thread+1
		0x234dfb54                        dd         0x00000000
		0x234dfb58                        dd         0x00000000
#endif
	},
	//[1]
	{
		16, //0x10 = "Bild",
		0xffff, //uint16_t wData_2; //2
		{
			&Data_234df368[6], //234df4e8,
		}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		menu_picture_entry, //sub_23470548, //void* Data_0x1c; //0x1c = 28
		menu_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 234DFB88
#if 0
		0x234dfb5c                        dw         0x0010
		0x234dfb5e                        dw         0x00f3
		0x234dfb60                        dd         0x234df4e8
		0x234dfb64                        dd         0x00000000
		0x234dfb68                        dd         0x00000000
		0x234dfb6c                        dd         0x00000000
		0x234dfb70                        dd         0x00000000
		0x234dfb74                        dd         0x00000000
		0x234dfb78                        dd         sub_23493050+1
		0x234dfb7c                        dd         menu_event_thread+1
		0x234dfb80                        dd         0x00000000
		0x234dfb84                        dd         0x00000000
#endif
	},
	//[2]
	{
		137, //0x89 = "Ton",
		0xffff,
		{
			&Data_234df368[7], //234df528,
			0, 0, 0, 0
		}, //int fill_4[5]; //4
		0,
		menu_sound_entry,
		menu_event_thread,
		0,
		0
		//0x2349301c
#if 0
		0x234dfb88                        dw         0x0089
		0x234dfb8a                        dw         0x00f3
		0x234dfb8c                        dd         0x234df528
		0x234dfb90                        dd         0x00000000
		0x234dfb94                        dd         0x00000000
		0x234dfb98                        dd         0x00000000
		0x234dfb9c                        dd         0x00000000
		0x234dfba0                        dd         0x00000000
		0x234dfba4                        dd         sub_2349118a+1
		0x234dfba8                        dd         menu_event_thread+1
		0x234dfbac                        dd         0x00000000
		0x234dfbb0                        dd         0x00000000
#endif
	},
	#if 0
	//[3]
	{
		0xc3, //"Untertitel"
		0xffff,
		{
			&Data_234df568,
			0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		menu_subtitles_entry,
		menu_event_thread,
		0,
		0
		//0x23493048
#if 0
		0x234dfbb4                        dw         0x00c3
		0x234dfbb6                        dw         0x00f3
		0x234dfbb8                        dd         0x234df568
		0x234dfbbc                        dd         0x00000000
		0x234dfbc0                        dd         0x00000000
		0x234dfbc4                        dd         0x00000000
		0x234dfbc8                        dd         0x00000000
		0x234dfbcc                        dd         0x00000000
		0x234dfbd0                        dd         sub_2349573e+1
		0x234dfbd4                        dd         menu_event_thread+1
		0x234dfbd8                        dd         0x00000000
		0x234dfbdc                        dd         0x00000000
#endif
	},
	//[4]
	{
		0x83, //"Bildschirmgrafik",  //87, //"Werkszustand"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		sub_2343d1ca,
		menu_event_thread,
		0,
		0
		//0x23493074
#if 0
		0x23493048                        dw         0x0057
		0x2349304a                        dw         0xffff
		0x2349304c                        dd         0x00000000
		0x23493050                        dd         0x00000000
		0x23493054                        dd         0x00000000                         ; DATA XREF=dword_23492c7c+32
		0x23493058                        dd         0x00000000
		0x2349305c                        dd         0x00000000
		0x23493060                        dd         0x00000000
		0x23493064                        dd         0x2343d1cb
		0x23493068                        dd         0x2343d6e3
		0x2349306c                        dd         0x00000000
		0x23493070                        dd         0x00000000
#endif
	},
	//[5]
	{
		0x127, //"Kindersicherung", //63, //"information"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		sub_23471d2c,
		menu_event_thread,
		0,
		0
		//0x234930a0
#if 0
		0x23493074                        dw         0x003f
		0x23493076                        dw         0xffff
		0x23493078                        dd         0x00000000
		0x2349307c                        dd         0x00000000
		0x23493080                        dd         0x00000000
		0x23493084                        dd         0x00000000
		0x23493088                        dd         0x00000000
		0x2349308c                        dd         0x00000000
		0x23493090                        dd         0x23471d2d
		0x23493094                        dd         0x2343d6e3
		0x23493098                        dd         0x00000000
		0x2349309c                        dd         0x00000000
#endif
	},
	//[6]
	{
		0x1ad, //"HDMI", 458, //"Software-Update"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		sub_2347004a,
		menu_event_thread,
		0,
		0
		//0x234930cc
#if 0
		0x234930a0                        dw         0x01ca
		0x234930a2                        dw         0xffff                             ; DATA XREF=sub_2343d104+48
		0x234930a4                        dd         0x00000000                         ; DATA XREF=sub_2343d104+52
		0x234930a8                        dd         0x00000000                         ; DATA XREF=sub_2343d104+58
		0x234930ac                        dd         0x00000000
		0x234930b0                        dd         0x00000000
		0x234930b4                        dd         0x00000000
		0x234930b8                        dd         0x00000000
		0x234930bc                        dd         0x2347004b
		0x234930c0                        dd         0x2343d6e3
		0x234930c4                        dd         0x00000000
		0x234930c8                        dd         0x00000000
#endif
	},
	//[7]
	{
		0x015d, //"Netzwerk", 458, //"Software-Update"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		0, //TODO!!!, sub_2347004a,
		menu_event_thread,
		0,
		0
	},
	//[8]
	{
		0x019c, //"Audio-Verstärker", 458, //"Software-Update"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		0, //TODO!!!, sub_2347004a,
		menu_event_thread,
		0,
		0
	}
#endif
};


uint8_t Data_2396b3a0[40]; //2396b3a0, size???
uint8_t Data_2396b4c0[40]; //2396b4c0
uint8_t Data_2396b4e8[40]; //2396b4e8
uint8_t Data_2396b510[40]; //2396b510
uint8_t Data_2396b538[40]; //2396b538


/*  /  / 2348c72c - todo */
int menu_settings_entry(UI_Thread_Params* r4)
{
#if 0
	console_send_string("menu_settings_entry (todo.c): TODO\r\n");
#endif

	menu_stack_operate(menu_settings_p);

	menu_initialize(menu_settings_p);

	sub_2343d51e(menu_settings_p, r4);

	return 0;
}

#endif //VDR110
