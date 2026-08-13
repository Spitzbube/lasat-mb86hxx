#include "data.h"
#include "graphic.h"
#include "menu.h"
#include "eit.h"

#pragma thumb

#ifndef VDR110

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c
extern int* Data_234c1234; //234c1234
extern int* Data_234c1238; //234c1238
extern Graphic_Job_2_5_Item_Background Data_234c12a4; //234c12a4
extern Graphic_Job_2_5_Item_Background Data_234c12d4; //234c12d4
extern Graphic_Job_2_5_Item_Background Data_234c131c; //234c131c
extern Graphic_Job_2_5_Item_Background Data_234c1328; //234c1328
extern Graphic_Job_2_5_Item_Background Data_234c1334; //234c1334
extern Graphic_Job_2_5_Item_Background Data_234c1340; //234c1340

static void get_sound_channel_tv_value_string();
static void get_sound_channel_digital_value_string(int);
static int sound_channel_tv_change(uint32_t*);
static int sound_channel_digital_change();
static int sub_23490fe2();
static int menu_sound_on_enter();
static Menu menu_sound;
static uint8_t Data_23970e1c[]; //23970e1c
static uint8_t Data_23970f3c[]; //23970f3c
static uint8_t sound_channel_tv_caption_string[]; //23970f64
static uint8_t sound_channel_digital_caption_string[]; //23970f8c
static uint8_t Data_23970fb4[]; //23970fb4
static uint8_t sound_channel_tv_value_string[]; //23970a4c
static uint8_t Data_23970fdc[]; //23970fdc

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

static Graphic_Job_2_5_Item_Text Data_234eae94 = //234eae94
{
	0, 0x0155, 0x0084, 0x0238, 0x00a0, 0x01, 0x04, 0x09, 0x01, &sound_channel_tv_value_string[0], //Data_0x10
#if 0
0x234eae94                        db         0x00                               ; DATA XREF=sub_23490cac+4, get_sound_channel_digital_value_string, get_sound_channel_digital_value_string+2, menu_sound_channel_tv_change, sub_23490fe2, menu_sound_on_enter, dword_234910b0, 0x234eb1dc
0x234eae95                        db         0x00
0x234eae96                        dw         0x0155
0x234eae98                        dw         0x0084
0x234eae9a                        dw         0x0238
0x234eae9c                        dw         0x00a0
0x234eae9e                        db         0x01
0x234eae9f                        db         0x04
0x234eaea0                        db         0x09
0x234eaea1                        db         0x01
0x234eaea2 0000                   movs       r0, r0
0x234eaea4                        dd         0x23970a4c                         ; DATA XREF=sub_23490cac+8
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eaeac = //234eaeac
{
	0, 0x0155, 0x00a4, 0x0238, 0x00c0, 0x01, 0x04, 0x09, 0x01, &Data_23970fdc[0], //Data_0x10
#if 0
0x234eaeac                        db         0x00                               ; DATA XREF=get_sound_channel_digital_value_string+8, 0x234eb21c
0x234eaead                        db         0x00
0x234eaeae                        dw         0x0155
0x234eaeb0                        dw         0x00a4
0x234eaeb2                        dw         0x0238
0x234eaeb4                        dw         0x00c0
0x234eaeb6                        db         0x01
0x234eaeb7                        db         0x04
0x234eaeb8                        db         0x09
0x234eaeb9                        db         0x01
0x234eaeba 0000                   movs       r0, r0
0x234eaebc                        dd         0x23970fdc                         ; DATA XREF=get_sound_channel_digital_value_string+14
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

static Graphic_Job_2_5_Item_Text Data_234eaf0c = //234eaf0c
{
	0, 0x0051, 0x0084, 0x012a, 0x00a0, 0x01, 0x04, 0x09, 0x01, &sound_channel_tv_caption_string[0], //Data_0x10
#if 0
0x234eaf0c                        db         0x00                               ; DATA XREF=0x234eb0dc
0x234eaf0d                        db         0x00
0x234eaf0e                        dw         0x0051
0x234eaf10                        dw         0x0084
0x234eaf12                        dw         0x012a
0x234eaf14                        dw         0x00a0
0x234eaf16                        db         0x01
0x234eaf17                        db         0x04
0x234eaf18                        db         0x09
0x234eaf19                        db         0x01
0x234eaf1a 0000                   movs       r0, r0
0x234eaf1c                        dd         0x23970f64                         ; DATA XREF=dword_234ea5d8+1472
#endif
};

static Graphic_Job_2_5_Item_Text Data_234eaf24 = //234eaf24
{
	0, 0x0051, 0x00a4, 0x012a, 0x00c0, 0x01, 0x04, 0x09, 0x01, &sound_channel_digital_caption_string[0], //Data_0x10
#if 0
0x234eaf24                        db         0x00                               ; DATA XREF=0x234eb11c
0x234eaf25                        db         0x00
0x234eaf26                        dw         0x0051
0x234eaf28                        dw         0x00a4
0x234eaf2a                        dw         0x012a
0x234eaf2c                        dw         0x00c0
0x234eaf2e                        db         0x01
0x234eaf2f                        db         0x04
0x234eaf30                        db         0x09
0x234eaf31                        db         0x01
0x234eaf32 0000                   movs       r0, r0
0x234eaf34                        dd         0x23970f8c                         ; DATA XREF=dword_234eae0c+68
#endif
};

static Graphic_Job_2_5_Item menu_sound_graphic_items[] = //234eaf3c
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
	{1, 0, 0, 0/*Data_8*/, 0x003d, 0x0060, 0x00ed, 0x0020, 0, &Data_234c1334/*Data_0x18*/, 9, 0, &Data_234eaef4}, //[5] = 234EB07C: 'Sound settings' Caption
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
	{1, 0, 0, 0/*Data_8*/, 0x003d, 0x0080, 0x00ed, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eaf0c}, //[6] = 234EB0BC: 'Sound channel TV' Label
#if 0
0x234eb0bc                        db         0x01                               ; 'Sound channel TV' Label, DATA XREF=0x234eb634
0x234eb0bd                        db  0x00 ; '.'
0x234eb0be 0000                   movs       r0, r0
0x234eb0c0 0000                   movs       r0, r0
0x234eb0c2 0000                   movs       r0, r0
0x234eb0c4 0000                   movs       r0, r0
0x234eb0c6 0000                   movs       r0, r0
0x234eb0c8                        dw         0x003d
0x234eb0ca                        dw         0x0080
0x234eb0cc                        dw         0x00ed
0x234eb0ce                        dw         0x0020
0x234eb0d0 0000                   movs       r0, r0
0x234eb0d2 0000                   movs       r0, r0
0x234eb0d4                        dd         0x234c12d4
0x234eb0d8                        dw         0x0009
0x234eb0da 0000                   movs       r0, r0
0x234eb0dc                        dd         0x234eaf0c
#endif
	{1, 0, 0, 0/*Data_8*/, 0x003d, 0x00a0, 0x00ed, 0x0020, 0, &Data_234c131c/*Data_0x18*/, 9, 0, &Data_234eaf24}, //[7] = 234EB0FC: 'Sound channel Dig.' Caption
#if 0
0x234eb0fc                        db         0x01                               ; DATA XREF=0x234eb660
0x234eb0fd                        db  0x00 ; '.'
0x234eb0fe 0000                   movs       r0, r0
0x234eb100 0000                   movs       r0, r0
0x234eb102 0000                   movs       r0, r0
0x234eb104 0000                   movs       r0, r0
0x234eb106 0000                   movs       r0, r0
0x234eb108                        dw         0x003d
0x234eb10a                        dw         0x00a0
0x234eb10c                        dw         0x00ed
0x234eb10e                        dw         0x0020
0x234eb110 0000                   movs       r0, r0
0x234eb112 0000                   movs       r0, r0
0x234eb114                        dd         0x234c131c
0x234eb118                        dw         0x0009
0x234eb11a 0000                   movs       r0, r0
0x234eb11c                        dd         0x234eaf24
#endif
	{0}, //[8] = 234EB13C
	{1, 0, 0, 0/*Data_8*/, 0x0141, 0x0060, 0x00f7, 0x0020, 0, &Data_234c1340/*Data_0x18*/, 9, 0, &Data_234eae7c}, //[9] = 234EB17C: 'Sound settings' Value
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
	{1, 0, 0, 0/*Data_8*/, 0x0141, 0x0080, 0x00f7, 0x0020, 0, &Data_234c12d4/*Data_0x18*/, 9, 0, &Data_234eae94}, //[10] = 234EB1BC: 'Sound channel TV' Value
#if 0
0x234eb1bc                        db         0x01                               ; 'Sound channel TV' Value, DATA XREF=0x234eb638
0x234eb1bd                        db  0x00 ; '.'
0x234eb1be 0000                   movs       r0, r0
0x234eb1c0 0000                   movs       r0, r0
0x234eb1c2 0000                   movs       r0, r0
0x234eb1c4 0000                   movs       r0, r0
0x234eb1c6 0000                   movs       r0, r0
0x234eb1c8                        dw         0x0141
0x234eb1ca                        dw         0x0080
0x234eb1cc                        dw         0x00f7
0x234eb1ce                        dw         0x0020
0x234eb1d0 0000                   movs       r0, r0
0x234eb1d2 0000                   movs       r0, r0
0x234eb1d4                        dd         0x234c12d4
0x234eb1d8                        dw         0x0009
0x234eb1da 0000                   movs       r0, r0
0x234eb1dc                        dd         0x234eae94
#endif
	{1, 0, 0, 0/*Data_8*/, 0x0141, 0x00a0, 0x00f7, 0x0020, 0, &Data_234c1328/*Data_0x18*/, 9, 0, &Data_234eaeac}, //[11] = 234EB1FC: 'Sound channel Dig.' Value
#if 0
0x234eb1fc                        db         0x01                               ; DATA XREF=0x234eb664
0x234eb1fd                        db  0x00 ; '.'
0x234eb1fe 0000                   movs       r0, r0
0x234eb200 0000                   movs       r0, r0
0x234eb202 0000                   movs       r0, r0
0x234eb204 0000                   movs       r0, r0
0x234eb206 0000                   movs       r0, r0
0x234eb208                        dw         0x0141
0x234eb20a                        dw         0x00a0
0x234eb20c                        dw         0x00f7
0x234eb20e                        dw         0x0020
0x234eb210 0000                   movs       r0, r0
0x234eb212 0000                   movs       r0, r0
0x234eb214                        dd         0x234c1328
0x234eb218                        dw         0x0009
0x234eb21a 0000                   movs       r0, r0
0x234eb21c                        dd         0x234eaeac
#endif
	{0}, //[12] = 234EB23C
    //234EB27C
};

static Graphic_Job_2_5 Data_234eb5bc = //234eb5bc
{
	0, //uint8_t bData_0; //0
	0xfa, //uint8_t bData_1; //1
	0x001e, //uint16_t wData_2; //2
	0x04, //uint8_t bData_4; //4
	&menu_sound_graphic_items[0], //pItems; //8
	&menu_main_graphic_color_data, //Struct_23414b38_b_Inner_0xc* pColorData; //12
	16, //uint8_t numColors; //0x10 = 16
	0, //int fill_0x14; //0x14 = 20
	13, //uint8_t bNumItems; //0x18 = 24
	0x01, //uint8_t bData_0x19; //0x19 = 25
	0, //0x1c
	0, //0x20
#if 0
0x234eb5bc                        db         0x00                               ; DATA XREF=get_sound_channel_digital_value_string+16, 0x234eb720
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
			&menu_sound_graphic_items[5], //234eb07c,
			&menu_sound_graphic_items[9], //234eb17c,
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
	//[1]
	{
		0x00c6, //'Tonkanal TV' / 'Sound channel TV'
		0xffff, //0xf4, //uint16_t wData_2; //2
		{
			&menu_sound_graphic_items[6], //234eb0bc,
			&menu_sound_graphic_items[10], //234eb1bc,
		}, //int fill_4[5]; //4
		get_sound_channel_tv_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sound_channel_tv_change, //void* onEvent; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//234EB65C
#if 0
0x234eb630                        dw         0x00c6
0x234eb632                        dw         0x00f4
0x234eb634                        dd         0x234eb0bc
0x234eb638                        dd         0x234eb1bc
0x234eb63c 0000                   movs       r0, r0
0x234eb63e 0000                   movs       r0, r0
0x234eb640 0000                   movs       r0, r0
0x234eb642 0000                   movs       r0, r0
0x234eb644 0000                   movs       r0, r0
0x234eb646 0000                   movs       r0, r0
0x234eb648                        dd         get_sound_channel_tv_value_string+1
0x234eb64c                        dd         menu_sound_channel_tv_change+1
0x234eb650                        dd         menu_item_event_thread+1
#endif
    },
	//[2]
	{
		0x00c1, //'Tonkanal Digital' / 'Sound channel Dig.'
		0xffff, //0xf4, //uint16_t wData_2; //2
		{
			&menu_sound_graphic_items[7], //234eb0fc,
			&menu_sound_graphic_items[11], //234eb1fc,
		}, //int fill_4[5]; //4
		get_sound_channel_digital_value_string, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sound_channel_digital_change, //void* onEvent; //0x1c = 28
		menu_item_event_thread, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//234EB688
#if 0
0x234eb65c                        dw         0x00c1
0x234eb65e                        dw         0x00f4
0x234eb660                        dd         0x234eb0fc
0x234eb664                        dd         0x234eb1fc
0x234eb668 0000                   movs       r0, r0
0x234eb66a 0000                   movs       r0, r0
0x234eb66c 0000                   movs       r0, r0
0x234eb66e 0000                   movs       r0, r0
0x234eb670 0000                   movs       r0, r0
0x234eb672 0000                   movs       r0, r0
0x234eb674                        dd         get_sound_channel_digital_value_string+1
0x234eb678                        dd         sound_channel_digital_change+1
0x234eb67c                        dd         menu_item_event_thread+1
#endif
    },
};

static Menu menu_sound = //234eb70c
{
	0x0089, //"Ton" / "Sound"
	&menu_sound_items[0], //Menu_Item* Data_4; //4
	&menu_sound_items[0], //Menu_Item* Data_8; //8
	&menu_sound_graphic_items[1], //234eaf7c, //Struct_235fdf74_Inner12* header; //12 = 0xc
	0, //234eaffc, //Struct_235fdf74_Inner16* help; //16 = 0x10
	&Data_234eb5bc, //Struct_235fdf74_Inner20* graphicData; //20 = 0x14
	2, //uint8_t maxItem; //0x18 = 24
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
0x234eb70c                        dw         0x0089                             ; DATA XREF=get_sound_channel_digital_value_string+10, menu_sound_channel_tv_change+8, sub_2349100c+10, menu_sound_entry+6, menu_sound_entry+12, menu_sound_entry+18, menu_sound_p, 0x234eae74
0x234eb70e                        db  0x00 ; '.'
0x234eb70f                        db  0x00 ; '.'
0x234eb710                        dd         menu_sound_items
0x234eb714                        dd         menu_sound_items                   ; DATA XREF=menu_sound_channel_tv_change+14, sub_2349100c+12
0x234eb718                        dd         0x234eaf7c
0x234eb71c                        dd         0x234eaffc
0x234eb720                        dd         0x234eb5bc                         ; DATA XREF=get_sound_channel_digital_value_string+16
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


static uint8_t sound_channel_tv_value_string[40]; //23970A4C -0x28

static struct
{
    EIT_Event* Data_23970a74; //23970a74
    PSI_Program psi; //23970a78 +0x398 = 23970E10
    uint16_t wData_23970e10; //23970e10
    uint16_t fill_23970e12; //23970e12
    uint8_t bData_23970e14; //23970e14
    int8_t bData_23970e15; //23970e15
    uint8_t bData_23970e16; //23970e16
    uint8_t bData_23970e17; //23970e17
    uint8_t bData_23970e18; //23970e18
    uint8_t bData_23970e19; //23970e19
} Data_23970e10;


static uint8_t Data_23970e1c[40]; //23970e1c, size???
static uint8_t Data_23970f3c[40]; //23970f3c, size???
static uint8_t sound_channel_tv_caption_string[40]; //23970f64, size???
static uint8_t sound_channel_digital_caption_string[40]; //23970f8c
static uint8_t Data_23970fb4[40]; //23970fb4
static uint8_t Data_23970fdc[40]; //23970fdc


/* /  / 23490cac - todo */
void get_sound_channel_tv_value_string()
{
#if 0
	console_send_string("get_sound_channel_tv_value_string (menu_sound.c): TODO\r\n");
#endif

    Struct_2340bf0c sp_0x48;
    Channel sp_0x20;
    Transponder sp8;

    EIT_Event* r7 = NULL;
    uint8_t* r6 = Data_234eae94.pString;

    /*sub_2340e9e8*/sub_2340bf0c(&sp_0x48);
    sub_2340bf94(sp_0x48.wCurrentChannel, &sp_0x20, &sp8);

    EIT_EventList* r0 = eit_get_section_data(sp_0x48.Data_0.service_id,
        sp8.transport_stream_id);

    if (r0 != NULL)
    {
        //0x23490cd8
        r7 = eit_get_present_following_event(r0, 4);
    }
    //loc_23490ce0
    Data_23970e10.Data_23970a74 = r7;
    memset(&sound_channel_tv_value_string[0], 0, 40);

    sound_channel_tv_value_string[0] = 0x2d;

    uint8_t* r3 = Data_23970e10.psi.arAudioLanguageStrings[Data_23970e10.bData_23970e15];
    if (r3 != NULL)
    {
        //0x23490d06
        uint8_t* r2 = Data_23970e10.psi.arAc3ChannelsStrings[Data_23970e10.bData_23970e15];
        if (r2 != 0)
        {
            //0x23490d10
            snprintf(r6, 40, "%s (%s)", r3, r2);
            //loc_23490d3c
        }
        else
        {
            //loc_23490d16
            snprintf(r6, 40, "%s", r3);
        }
    }
    else
    {
        //loc_23490d1a
        r3 = Data_23970e10.psi.arAudioLanguage2Strings[Data_23970e10.bData_23970e15];
        if (r3 != NULL)
        {
            //0x23490d26
            int pid = Data_23970e10.psi.arAudioPids[Data_23970e10.bData_23970e15];

            snprintf(r6, 40, "%s 0x%x", r3, pid & 0x1fff);
        }
    }
    //loc_23490d3c
    if ((sp_0x48.Data_0.service_id == Data_23970e10.psi.pat_program_number) &&
        (r7 != NULL) &&
        (r7->component_descriptor != NULL))
    {
        //0x23490d4a
        struct Component_Descriptor* r3 = r7->component_descriptor;
        //uint8_t r1 = Data_23970e10.psi.arAudioComponentTags[Data_23970e10.bData_23970e15];
        while (r3 != NULL)
        {
            //loc_23490d5e
            if ((r3->component_tag == (uint8_t)(Data_23970e10.psi.arAudioComponentTags[Data_23970e10.bData_23970e15])) &&
                (r3->text_char != NULL))
            {
                snprintf(r6, 40, "%s", r3->text_char);
                break;
            }
            //loc_23490d7a
            r3 = r3->next;
        }
    }
    //loc_23490d76
}


/* /  / 23490d82 - todo */
void get_sound_channel_digital_value_string(int a)
{
#if 0
	console_send_string("get_sound_channel_digital_value_string (menu_sound.c): TODO\r\n");
#endif

    Graphic_Job_2_5* r0 = menu_sound_p->graphicData;
    uint8_t* r4 = Data_234eaeac.pString;

    if (a == 0)
    {
        r0->pItems[11].bData_0x3c = 1;
    }
    //loc_23490da2
    if (Data_23970e10.wData_23970e10 & (1 << 13))
    {
        //'komprimiert (Bitstrom)'
        text_table_get_string(0x151, r4, 38);
    }
    else
    {
        //'unkomprimiert (PCM)'
        text_table_get_string(0x152, r4, 38);
    }

    r4[39] = 0;
}


/* /  / 23490dca - todo */
static int sound_channel_tv_change(uint32_t* a)
{
#if 0
	console_send_string("sound_channel_tv_change (menu_sound.c): TODO\r\n");
#endif

    Menu_Item* r5 = menu_sound_p->Data_8;
    int r6 = 200;
    int r7 = *a;

    if (0 == /*sub_234091ac*/sub_234066d0(main_hPSIDecoder1, &Data_23970e10.psi))
    {
        //0x23490dea
        int r0;
        int r2 = 1;
        //->loc_23490df8
        Data_23970e10.bData_23970e14 = 0;
        for (r0 = 0;  
            (Data_23970e10.psi.arAudioLanguageStrings[r0] != NULL) ||
            (Data_23970e10.psi.arAudioLanguage2Strings[r0] != NULL);
            r0++)
        {
            //loc_23490df0
            Data_23970e10.bData_23970e14++;
        }
        //0x23490e12
        if (r2 != 0)
        {
            //0x23490e16
            int** r0;

            if (Data_23970e10.bData_23970e14 != 1)
            {
                //0x23490e1c
                if (r7 & (1 << 3))
                {
                    //0x23490e20
                    Data_23970e10.bData_23970e15++;
                    if (Data_23970e10.bData_23970e15 >= Data_23970e10.bData_23970e14)
                    {
                        Data_23970e10.bData_23970e15 = 0;
                    }
                    //loc_23490e44
                }
                //loc_23490e30
                else if (r7 & (1 << 2))
                {
                    //0x23490e34
                    Data_23970e10.bData_23970e15--;
                    if (Data_23970e10.bData_23970e15 < 0)
                    {
                        Data_23970e10.bData_23970e15 += Data_23970e10.bData_23970e14;
                    }
                }
                //loc_23490e44
                if (Data_23970e10.bData_23970e14 == 0)
                {
                    //->loc_23490e84
                    goto loc_23490e84;
                }
            }
            //0x23490e48
            if (Data_23970e10.bData_23970e14 != 1)
            {
                //0x23490e4c
                r0 = &Data_234c1234;
            }
            else
            {
                //loc_23490e50
                r0 = &Data_234c1238;
            }
            //loc_23490e52
            r5[1].helpStringId = **r0;

            if ((Data_23970e10.psi.arAc3ChannelsStrings[Data_23970e10.bData_23970e15] == 0) ||
                (0 == strcmp(Data_23970e10.psi.arAc3ChannelsStrings[Data_23970e10.bData_23970e15], "E-AC3")))
            {
                //loc_23490e76
                r0 = &Data_234c1238;
            }
            else
            {
                //loc_23490e7a
                r0 = &Data_234c1234;
            }
            //loc_23490e7c
            r5[2].helpStringId = **r0;
        }
        //loc_23490e84
    }
    //loc_23490e84
loc_23490e84:
    Data_23970e10.wData_23970e10 = Data_23970e10.psi.arAudioPids[Data_23970e10.bData_23970e15];

    if (0 != /*sub_23424134*/sub_23418bf0()) //->ts_play.c
    {
        //0x23490ea2
        //int r1, r0;
        if (Data_23970e10.psi.arAc3ChannelsStrings[Data_23970e10.bData_23970e15] != 0)
        {
            //0x23490eb0
            //r1 = Data_23970e10.wData_23970e10;
            //r0 = 0;
            /*sub_234241ac*/sub_23418c68(0, Data_23970e10.wData_23970e10);
        }
        else
        {
            //loc_23490eb6
            //r0 = Data_23970e10.wData_23970e10;
            //r1 = 0;
            /*sub_234241ac*/sub_23418c68(Data_23970e10.wData_23970e10, 0);
        }
        //->loc_23490efa
    }
    else
    {
        //loc_23490ec0
        if (Data_23970e10.psi.arAc3ChannelsStrings[Data_23970e10.bData_23970e15] != 0)
        {
            //0x23490ece
            //r1 = Data_23970e10.wData_23970e10;
            //r0 = 0;
            channel_set_audio_pids(0, Data_23970e10.wData_23970e10);
        }
        else
        {
            //loc_23490ed4
            //r0 = Data_23970e10.wData_23970e10;
            //r1 = 0;
            channel_set_audio_pids(Data_23970e10.wData_23970e10, 0);
        }

        int r7;
        Data_23970e10.psi.pat_program_number = r7 = 0xffff;

        do 
        {
            //loc_23490ee0
            /*sub_234091ac*/sub_234066d0(main_hPSIDecoder1, &Data_23970e10.psi);

            if (r6-- == 0)
            {
                //->loc_23490f0e
                return 1;
            }
            //0x23490eee
            rtos_task_wait(1);
        }
        while (Data_23970e10.psi.pat_program_number == r7);
        //loc_23490efa
    }
    //loc_23490efa
    get_sound_channel_digital_value_string(0);

    if (Data_23970e10.bData_23970e15 != Data_23970e10.bData_23970e17)
    {
        return 0;
    }
    //loc_23490f0e
    return 1;
}


/*  /  / 23490f52 - todo  */
int sound_channel_digital_change()
{
#if 0
	console_send_string("sound_channel_digital_change (menu_sound.c): TODO\r\n");
#endif

    if ((Data_23970e10.psi.arAc3ChannelsStrings[Data_23970e10.bData_23970e15] != 0) &&
        (0 != strcmp(Data_23970e10.psi.arAc3ChannelsStrings[Data_23970e10.bData_23970e15], "E-AC3")))
    {
        //0x23490f74
        if (Data_23970e10.wData_23970e10 & (1 << 13))
        {
            Data_23970e10.wData_23970e10 &= ~(1 << 13);
        }
        else
        {
            Data_23970e10.wData_23970e10 |= (1 <<13);
        }
        //loc_23490f88
        if (0 != /*sub_23424134*/sub_23418bf0()) //->ts_play.c
        {
            //0x23490f96
            if (Data_23970e10.psi.arAc3ChannelsStrings[Data_23970e10.bData_23970e15] != 0)
            {
                //0x23490fa4
                //r1 = Data_23970e10.wData_23970e10;
                //r0 = 0;
                /*sub_234241ac*/sub_23418c68(0, Data_23970e10.wData_23970e10);
            }
            else
            {
                //loc_23490faa
                //r0 = Data_23970e10.wData_23970e10;
                //r1 = 0;
                /*sub_234241ac*/sub_23418c68(Data_23970e10.wData_23970e10, 0);
            }
            //->loc_23490fd0
        }
        else
        {
            //loc_23490fb4
            if (Data_23970e10.psi.arAc3ChannelsStrings[Data_23970e10.bData_23970e15] != 0)
            {
                //0x23490ece
                //r1 = Data_23970e10.wData_23970e10;
                //r0 = 0;
                channel_set_audio_pids(0, Data_23970e10.wData_23970e10);
            }
            else
            {
                //loc_23490ed4
                //r0 = Data_23970e10.wData_23970e10;
                //r1 = 0;
                channel_set_audio_pids(Data_23970e10.wData_23970e10, 0);
            }
        }
        //loc_23490fd0
        if (Data_23970e10.bData_23970e18 != (Data_23970e10.wData_23970e10 >> 8))
        {
            return 0;
        }
    }
    //loc_23490fde
    return 1;
}


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

    if (0 == /*sub_234091ac*/sub_234066d0(main_hPSIDecoder1, &Data_23970e10.psi))
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
        //int r3 = Data_23970e10.wData_23970e10 & 0x5fff;

        int r0;
        for (r0 = 0; 
            (Data_23970e10.psi.arAudioLanguageStrings[r0] != NULL) ||
            (Data_23970e10.psi.arAudioLanguage2Strings[r0] != NULL); r0++)
        {
            //loc_23491076
            Data_23970e10.bData_23970e14++;

            if (Data_23970e10.psi.arAudioPids[r0] == 
                (Data_23970e10.wData_23970e10 & 0x5fff)/*r3*/)
            {
                Data_23970e10.bData_23970e15 = r0;
            }
        }
        //0x234910a2
        if (Data_23970e10.bData_23970e14 != 0)
        {
            //0x234910a8
            int** r0;
            int** r7 = &Data_234c1238;
            if (Data_23970e10.bData_23970e14 != 1)
            {
                //loc_234910f0
                r0 = &Data_234c1234;
            }
            else
            {
                //loc_234910f4
                r0 = r7;
            }
            //loc_234910f6
            r5[1].helpStringId = **r0;

            if ((Data_23970e10.psi.arAc3ChannelsStrings[Data_23970e10.bData_23970e15] == 0) ||
                (0 == strcmp(Data_23970e10.psi.arAc3ChannelsStrings[Data_23970e10.bData_23970e15], "E-AC3")))
            {
                //loc_23491118
                r0 = r7;
            }
            else
            {
                //loc_2349111c
                r0 = &Data_234c1234;
            }
            //loc_2349111e
            r5[2].helpStringId = **r0;
        }
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
