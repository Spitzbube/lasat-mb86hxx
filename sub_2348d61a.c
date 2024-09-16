
#ifndef VDR110

#include "data.h"
#include "frontdisplay.h"
#include "texttable.h"
#include "graphic.h"
#include "menu.h"
#include "sub_2348d61a.h"

#pragma thumb

extern Graphic_Color_Data menu_main_graphic_color_data; //234c123c

static Graphic_Job_2_5_Item Data_234e0620[]; //234e0620
static Menu Data_234e1c78;
static Menu Data_234e1cf0;

static int sub_2348cbc8(void);
static void sub_2348d3f6(void);
static void sub_2348db56(Menu_Item*, uint16_t, uint8_t, uint8_t);
static void sub_2348db78(void);
/*static*/ void sub_2348dcd8(int);


//234dfe48
Menu* Data_234dfe54 = //234dfe54 +0xc
    &Data_234e1c78;

Menu* Data_234dfe58 = //234dfe58 +0x10
    &Data_234e1cf0; 

static Struct_2377ded0_Inner_0x1c_Inner_0x18 Data_234dfe74 = //234dfe74
{
	14, //uint16_t wData_0; //0
	4, //int Data_4; //4
	0x0b, //uint8_t bData_8; //8
#if 0
0x234dfe74                        dw         0x000e                             ; DATA XREF=sub_2348d81e+4, 0x234e0638
0x234dfe76 0000                   movs       r0, r0
0x234dfe78                        dd         0x00000004
0x234dfe7c                        db         0x0b
#endif
};

static Menu_Item Data_234e0190[] = //234e0190
{
    //[0]
    {
        0xffff,
        0xffff,
        {&Data_234e0620[8], /*234e0820*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e0190                        dw         0xffff                             ; DATA XREF=sub_2348ca2a+360, sub_2348cc10+158, dword_2348cce4, 0x234e1c7c, 0x234e1c80
0x234e0192                        dw         0xffff
0x234e0194                        dd         0x234e0820                         ; DATA XREF=sub_2348ca2a+370
0x234e0198                        dd         0x00000000
0x234e019c                        dd         0x00000000
0x234e01a0                        dd         0x00000000
0x234e01a4                        dd         0x00000000
0x234e01a8                        dd         0x00000000
0x234e01ac                        dd         sub_2348d3f6+1
0x234e01b0                        dd         mainfunction_thread+1
0x234e01b4                        dd         0x00000000
0x234e01b8                        dd         0x00000000    
#endif
    }, 
};

static Menu_Item Data_234e0298[] = //234e0298
{
    //[0]
    {
        0xffff,
        0xffff,
        {0/*&Data_234e0be0*/},
        0,
        sub_2348d3f6, //onEvent
        mainfunction_thread,
        0,
        0,
#if 0
0x234e0298                        dw         0xffff                             ; DATA XREF=sub_2348c8d4+94, sub_2348c8d4+108, sub_2348c8d4+120, sub_2348c8d4+248, dword_2348ccc0, 0x234e1cf4, 0x234e1cf8
0x234e029a                        dw         0xffff
0x234e029c                        dd         0x234e0be0                         ; DATA XREF=sub_2348c8d4+96, sub_2348c8d4+258
0x234e02a0                        dd         0x00000000
0x234e02a4                        dd         0x00000000
0x234e02a8                        dd         0x00000000
0x234e02ac                        dd         0x00000000
0x234e02b0 0000                   movs       r0, r0
0x234e02b2 0000                   movs       r0, r0                             ; CODE XREF=menu_settings_items+560
0x234e02b4                        dd         sub_2348d3f6+1
0x234e02b8                        dd         mainfunction_thread+1
0x234e02bc 0000                   movs       r0, r0
0x234e02be 0000                   movs       r0, r0
0x234e02c0 0000                   movs       r0, r0
0x234e02c2 0000                   movs       r0, r0
#endif
    }, 
};

static Graphic_Job_2_5_Item Data_234e0620[40] = //234e0620
{
    {1, 0, 0/*fill_4*/, 0/*Data_8*/, 0x0041, 0x0140, 0x0186, 0x0032, 0/*fill_0x14*/, &Data_234dfe74/*Data_0x18*/, 2/*wData_0x1c*/}, //[0] = 234e0620
#if 0
0x234e0620                        db         0x01                               ; DATA XREF=sub_2348c8d4+30, sub_2348ca2a+12, sub_2348cc10+22, sub_2348cc10+32, sub_2348cc10+42, sub_2348cc10+48, sub_2348cc10+54, sub_2348cc10+66, sub_2348cc10+72, sub_2348cc10+78, sub_2348cc10+82
0x234e0621                        db         0x00
0x234e0622 0000                   movs       r0, r0
0x234e0624 0000                   movs       r0, r0
0x234e0626 0000                   movs       r0, r0
0x234e0628 0000                   movs       r0, r0
0x234e062a 0000                   movs       r0, r0
0x234e062c                        dw         0x0041
0x234e062e                        dw         0x0140
0x234e0630                        dw         0x0186
0x234e0632                        dw         0x0032
0x234e0634                        db         0x00
0x234e0635                        db         0x00
0x234e0636                        db         0x00
0x234e0637                        db         0x00
0x234e0638                        dd         0x234dfe74
0x234e063c                        db         0x02                               ; DATA XREF=sub_2348cc10+60, dword_2348ccec+62, dword_2348ccec+74, dword_2348ccec+266, dword_2348ccec+278
0x234e063d                        db  0x00 ; '.'
0x234e063e 0000                   movs       r0, r0
0x234e0640                        dd         0x00000000                         ; DATA XREF=dword_2348ccec+100
0x234e0644 0000                   movs       r0, r0
0x234e0646 0000                   movs       r0, r0
0x234e0648 0000                   movs       r0, r0
0x234e064a 0000                   movs       r0, r0
0x234e064c 0000                   movs       r0, r0
0x234e064e 0000                   movs       r0, r0
0x234e0650 0000                   movs       r0, r0
0x234e0652 0000                   movs       r0, r0
0x234e0654 0000                   movs       r0, r0
0x234e0656 0000                   movs       r0, r0
0x234e0658 0000                   movs       r0, r0
0x234e065a 0000                   movs       r0, r0
0x234e065c 0000                   movs       r0, r0
0x234e065e 0000                   movs       r0, r0
#endif
    {0}, //[1] = 234e0660
#if 0
0x234e0660                        db         0x01                               ; DATA XREF=0x234e1c88
0x234e0661                        db         0x00
0x234e0662 0000                   movs       r0, r0
0x234e0664 0000                   movs       r0, r0
0x234e0666 0000                   movs       r0, r0
0x234e0668 0000                   movs       r0, r0
0x234e066a 0000                   movs       r0, r0
0x234e066c                        dw         0x0091
0x234e066e                        dw         0x016d
0x234e0670                        dw         0x01fe
0x234e0672                        dw         0x009b
0x234e0674                        db         0x00
0x234e0675                        db         0x00
0x234e0676                        db         0x00
0x234e0677                        db         0x00
0x234e0678                        dd         0x234dfebc
0x234e067c                        db         0x02
0x234e067d                        db  0x00 ; '.'
0x234e067e 0000                   movs       r0, r0
0x234e0680 0000                   movs       r0, r0
0x234e0682 0000                   movs       r0, r0
0x234e0684 0000                   movs       r0, r0
0x234e0686 0000                   movs       r0, r0
0x234e0688 0000                   movs       r0, r0
0x234e068a 0000                   movs       r0, r0
0x234e068c 0000                   movs       r0, r0
0x234e068e 0000                   movs       r0, r0
0x234e0690 0000                   movs       r0, r0
0x234e0692 0000                   movs       r0, r0
0x234e0694 0000                   movs       r0, r0
0x234e0696 0000                   movs       r0, r0
0x234e0698 0000                   movs       r0, r0
0x234e069a 0000                   movs       r0, r0
0x234e069c 0000                   movs       r0, r0
0x234e069e 0000                   movs       r0, r0
#endif
    {0}, //[2] = 234E06A0
    {0}, //[3] = 234E06E0
    {0}, //[4] = 234E0720
    {0}, //[5] = 234E0760
    {0}, //[6] = 234E07A0
    {0}, //[7] = 234E07E0
    {0}, //[8] = 234E0820
    {0}, //[9] = 234E0860
    {0}, //[10] = 234E08A0
    {0}, //[11] = 234E08E0
    {0}, //[12] = 234E0920
    {0}, //[13] = 234E0960
    {0}, //[14] = 234E09A0
    {0}, //[15] = 234e0660
    {0}, //[16] = 234e0660
    {0}, //[17] = 234e0660
    {0}, //[18] = 234e0660
    {0}, //[19] = 234e0660
    {0}, //[20] = 234e0660
    {0}, //[21] = 234e0660
    {0}, //[22] = 234e0660
    {0}, //[23] = 234e0660
    {0}, //[24] = 234e0660
    {0}, //[25] = 234e0660
    {0}, //[26] = 234e0660
    {0}, //[27] = 234e0660
    {0}, //[28] = 234e0660
    {0}, //[29] = 234e0660
    {0}, //[30] = 234e0660
    {0}, //[31] = 234e0660
    {0}, //[32] = 234e0660
    {0}, //[33] = 234e0660
    {0}, //[34] = 234e0660
    {0}, //[35] = 234e0660
    {0}, //[36] = 234e0660
    {0}, //[37] = 234e0660
    {0}, //[38] = 234e0660
    {0}, //[39] = 234e0660
};

static Graphic_Job_2_5 Data_234e1a20 = //234e1a20
{
    0,
    0,
    1, //wData_2
    4, //bData_4
    &Data_234e0620[0], //pItems
    &menu_main_graphic_color_data, //pColorData
    16, //numColors
    0,
    40, //bNumItems
    1, //bData_0x19
    0, //sub_2348c8c8, //Data_0x1c
    0, //sub_2348c8b4, //Data_0x20
#if 0
0x234e1a20                        db         0x00                               ; DATA XREF=sub_2348c8d4+28, sub_2348ca2a+10, sub_2348cc10+16, sub_2348cc10+30, sub_2348cc10+40, sub_2348cc10+50, sub_2348cc10+62, sub_2348cc10+74, sub_2348cc10+84, sub_2348cc10+94, sub_2348cc10+106
0x234e1a21                        db         0x00
0x234e1a22                        dw         0x0001                             ; DATA XREF=sub_2348d7c2+16, sub_2348d7c2+36
0x234e1a24                        db         0x04
0x234e1a25                        db  0x00 ; '.'
0x234e1a26 0000                   movs       r0, r0
0x234e1a28                        dd         0x234e0620                         ; DATA XREF=sub_2348c8d4+30, sub_2348ca2a+12, sub_2348cc10+22, sub_2348cc10+32, sub_2348cc10+42, sub_2348cc10+54, sub_2348cc10+66, sub_2348cc10+78, sub_2348cc10+86, sub_2348cc10+98, sub_2348cc10+110
0x234e1a2c                        dd         0x234c123c
0x234e1a30                        db         0x10
0x234e1a31                        db  0x00 ; '.'
0x234e1a32 0000                   movs       r0, r0
0x234e1a34 0000                   movs       r0, r0
0x234e1a36 0000                   movs       r0, r0
0x234e1a38                        db         0x28
0x234e1a39                        db         0x01
0x234e1a3a 0000                   movs       r0, r0
0x234e1a3c                        dd         sub_2348c8c8+1
0x234e1a40                        dd         sub_2348c8b4+1    
#endif
};

Menu Data_234e1c78 = //234e1c78 +0x3c = 234E1CB4
{
    0,
    &Data_234e0190,
    &Data_234e0190,
    &Data_234e0620[0], //header
    0, //&Data_234e0660, //help
    &Data_234e1a20, //graphicData
    5, //maxItem
    0, //currentItem
    graphic_start_job_2_5,
    0, //sub_2348de88, //onNavigate
    sub_2348cbc8, //onEnter
    0, //sub_2348cecc, //onExit
    0xff,
    100,
#if 0
0x234e1c78                        dw         0x0000                             ; DATA XREF=sub_2348c8d4+24, sub_2348ca2a+8, sub_2348cbc8+8, sub_2348cc10+8, dword_2348ccec+52, dword_2348ccec+196, sub_2348d61a+6, sub_2348d61a+18, sub_2348d61a+56, sub_2348d660+84, sub_2348d78c+24
0x234e1c7a                        dw         0x0000
0x234e1c7c                        dd         0x234e0190
0x234e1c80                        dd         0x234e0190
0x234e1c84                        dd         0x234e0620
0x234e1c88                        dd         0x234e0660
0x234e1c8c                        dd         0x234e1a20                         ; DATA XREF=sub_2348c8d4+28, sub_2348ca2a+10, sub_2348cc10+16, sub_2348cc10+30, sub_2348cc10+40, sub_2348cc10+50, sub_2348cc10+62, sub_2348cc10+74, sub_2348cc10+84, sub_2348cc10+94, sub_2348cc10+106
0x234e1c90                        dw         0x0005
0x234e1c92                        dw         0x0000
0x234e1c94                        dd         graphic_start_job_2_5              ; DATA XREF=sub_2348d61a+8, sub_2348d61a+60
0x234e1c98                        dd         sub_2348de88+1
0x234e1c9c                        dd         sub_2348cbc8+1
0x234e1ca0                        dd         sub_2348cecc+1
0x234e1ca4 FF00                   lsls       r7, r7, #0x3
0x234e1ca6 0000                   movs       r0, r0
0x234e1ca8                        dd         0x00000064                         ; DATA XREF=sub_2348d660+86
0x234e1cac 0000                   movs       r0, r0
0x234e1cae 0000                   movs       r0, r0
0x234e1cb0 0000                   movs       r0, r0
0x234e1cb2 0000                   movs       r0, r0
#endif
};

Menu Data_234e1cf0 = //234e1cf0 +0x3c = 234E1D2C
{
    0,
    &Data_234e0298,
    &Data_234e0298,
    &Data_234e0620[0], //header
    0, //&Data_234e0660, //help
    &Data_234e1a20, //graphicData
    5, //maxItem
    0, //currentItem
    graphic_start_job_2_5,
    0, //sub_2348de88, //onNavigate
    0, //sub_2348c9e0, //onEnter
    0, //sub_2348cecc, //onExit
    0xff,
    100,
#if 0
0x234e1cf0                        dw         0x0000                             ; DATA XREF=sub_2348c9e0+8, sub_2348d61a+10, sub_2348d61a+26, sub_2348d61a+62, sub_2348d660+88, dword_234dfe58
0x234e1cf2                        dw         0x0000
0x234e1cf4                        dd         0x234e0298
0x234e1cf8                        dd         0x234e0298
0x234e1cfc                        dd         0x234e0620
0x234e1d00                        dd         0x234e0660
0x234e1d04                        dd         0x234e1a20
0x234e1d08                        dw         0x0005
0x234e1d0a                        dw         0x0000
0x234e1d0c                        dd         graphic_start_job_2_5              ; DATA XREF=sub_2348d61a+12, sub_2348d61a+64
0x234e1d10                        dd         sub_2348de88+1
0x234e1d14                        dd         sub_2348c9e0+1
0x234e1d18                        dd         sub_2348cecc+1
0x234e1d1c                        dd         0x000000ff
0x234e1d20                        dd         0x00000064                         ; DATA XREF=sub_2348d660+90
0x234e1d24 0000                   movs       r0, r0
0x234e1d26 0000                   movs       r0, r0
0x234e1d28 0000                   movs       r0, r0
0x234e1d2a 0000                   movs       r0, r0
#endif
};

Struct_2348dc50* sub_2348dc50(Struct_2348dc50*);


//234e1d68
uint8_t bData_234e1d68 = 0; //234e1d68 +0
uint8_t bData_234e1d69 = 0; //234e1d69 +1
void (*Data_234e1d6c)(Menu_Item*, uint16_t, uint8_t, uint8_t) = sub_2348db56; //234e1d6c +4 
Struct_2348dc50* Data_234e1d70 = 0; //234e1d70 +8


struct 
{
    Struct_2348dc50* Data_0; //0
    int fill_4[61]; //4
    User_Settings Data_2396b720; //2396b720 0xf8 +0x1c = 2396B73C
    
} Data_2396b628; //2396b628

Struct_2348dc50 Data_2396ca04[10]; //2396ca04???, size???


/* 2348ca2a - todo */
static void sub_2348ca2a(void)
{
#if 1
	console_send_string("sub_2348ca2a (todo.c): TODO\r\n");
#endif

}


/* 2348cbc8 - todo */
int sub_2348cbc8(void) //onEnter
{
#if 0
	console_send_string("sub_2348cbc8 (todo.c): TODO\r\n");
#endif

    Struct_2348dc50 sp;

    sp.Data_4 = Data_234dfe54;
    sp.Data_0x10 = 0;
    sp.wData_0x1c = 4;
    sp.Data_0x14 = sub_2348ca2a;
    sp.Data_0x18 = sub_2348db78;
    sp.Data_0x54 = 0;
    sp.wData_0x24 = 0;
    sp.wData_0x26 = 6;
    sp.wData_0x20 = 0;
    sp.wData_0x1e = 0;
    sp.wData_0x22 = 0;
    sp.bData_0x5e = 9;
    sp.bData_0x59 = 2;
    sp.bData_0x5a = 10;
    sp.bData_0x5b = 9;

    Data_2396b628.Data_0 = sub_2348dc50(&sp);

    return 0;
}


/* 2348d3f6 - todo */
void sub_2348d3f6(void)
{
#if 1
	console_send_string("sub_2348d3f6 (todo.c): TODO\r\n");
#endif

}


/* 2348d61a - todo */
int sub_2348d61a(void)
{
#if 1
	console_send_string("sub_2348d61a (todo.c): TODO\r\n");
#endif

    Data_234dfe54->graphicHandler = 0;
    Data_234dfe58->graphicHandler = 0;

    MENU_STACK_PUSH(Data_234dfe54);

    sub_2348dd36(Data_234dfe54, 1);
    sub_2348dd36(Data_234dfe58, 0);

    sub_2348dcd8(Data_2396b628.Data_0->bData_0x5f);

    channel_handle_user_settings(1, &Data_2396b628.Data_2396b720);

    Data_234dfe54->graphicHandler = graphic_start_job_2_5;
    Data_234dfe58->graphicHandler = graphic_start_job_2_5;

    return 0;
}


/* 2348d660 - todo */
void sub_2348d660(int a)
{
#if 1
	console_send_string("sub_2348d660 (todo.c): TODO\r\n");
#endif

}


/* 2348db56 - complete */
void sub_2348db56(Menu_Item* a, uint16_t b, uint8_t c, uint8_t d)
{
#if 0
	console_send_string("sub_2348db56 (todo.c): TODO\r\n");
#endif

    Menu_Item_Inner4_Data_0* r4;

    do
    {
        r4 = a->Data_4[d];
        if (r4 == 0)
        {
            break;
        }

        d++;
        r4->wData_0x1c = b;
        r4->bData_0x3c = c;

        r4 = a->Data_4[d];
    }
    while (r4 != 0);
}


/* 2348db78 - todo */
void sub_2348db78(void)
{
#if 1
	console_send_string("sub_2348db78 (todo.c): TODO\r\n");
#endif

}


/* 2348dc50 - todo */
Struct_2348dc50* sub_2348dc50(Struct_2348dc50* a)
{
#if 0
	console_send_string("sub_2348dc50 (todo.c): TODO\r\n");
#endif

    Struct_2348dc50* r3 = &Data_2396ca04[0];

    uint8_t i;
    for (i = 1; i < 7; i++)
    {
        if (r3->Data_4 == 0)
        {
            break;
        }

        r3++;
    }

    if (i < 8)
    {
        Data_234e1d70 = r3;

        *Data_234e1d70 = *a;

        Data_234e1d70->bData_0x5f = i;

        bData_234e1d68++;

        for (uint8_t k = 0; k < 21; k++)
        {
            Data_234e1d70->arwData_0x28[k] = 0;
        }
    }
    //loc_2348dc98
    return Data_234e1d70;
}


/* 2348dcd2 - todo */
Struct_2348dc50* sub_2348dcd2(void)
{
#if 0
	console_send_string("sub_2348dcd2 (todo.c): TODO\r\n");
#endif

    return Data_234e1d70;
}


/* 2348dcd8 - todo*/
void sub_2348dcd8(int a)
{
#if 0 
	console_send_string("sub_2348dcd8 (todo.c): TODO\r\n");
#endif

    Data_234e1d70 = &Data_2396ca04[a - 1];
    bData_234e1d69 = a - 1;
}


/* 2348dd36 - todo */
int sub_2348dd36(Menu* r4, int b)
{
#if 0
	console_send_string("sub_2348dd36 (todo.c): TODO\r\n");
#endif

    Graphic_Queue_Item sp_0x44;
    struct 
    {
        int fill_0[13]; //0
    } sp_0x10;
    Menu_Item* r6;

    if (r4->onEnter != 0)
    {
        int r0 = (r4->onEnter)(r4);
        if (r0 != 0)
        {
            return r0;
        }
    }
    //loc_2348dd4a
    if ((r4->header != 0) &&
        (r4->header->Data_0x20 != 0) &&
        (r4->stringId != 0xffff))
    {
        text_table_get_string(r4->stringId, r4->header->Data_0x20->pString, 35);

        r4->header->Data_0x20->bData_0x17 = 1;
    }
    //loc_2348dd6e
    if ((Data_234e1d70->Data_4 != r4) ||
        ((r6 = r4->Data_8) == 0))
    {
        return 4;
    }
    //loc_2348dd84
    if (Data_234e1d70->Data_0x14 != 0)
    {
        (Data_234e1d70->Data_0x14)(Data_234e1d70);
    }
    //loc_2348dd8c
    uint8_t r5 = r4->maxItem;
    do
    {
        //loc_2348dd8e
        (Data_234e1d6c)(r6, Data_234e1d70->bData_0x5b, 1, 0);

        r6++;
    }
    while (r5--);
    //0x2348ddac
    r4->currentItem = Data_234e1d70->wData_0x22;

    r6 = &r4->Data_8[Data_234e1d70->wData_0x22];
    r4->Data_4 = r6;

    int r1;
    if (b != 0)
    {
        //0x2348ddc8
        if (Data_234e1d70->Data_0x54 != 0)
        {
            //0x2348ddce
            if ((Data_234e1d70->wData_0x1e + 1) ==
                ((uint16_t*)(Data_234e1d70->Data_0x54))[0])
            {
                //0x2348ddda
                r1 = Data_234e1d70->bData_0x5c;
                //loc_2348ddde
                (Data_234e1d6c)(r6, r1, 1, 0);
            }
            //loc_2348dde8
        } //if (Data_234e1d70->Data_0x54 != 0)
        else
        {
            //loc_2348de3c
            r1 = Data_234e1d70->bData_0x5a;
            //->loc_2348ddde
            (Data_234e1d6c)(r6, r1, 1, 0);
        }
    } //if (b != 0)
    else
    {
        //loc_2348de42
        r1 = Data_234e1d70->bData_0x5b;
        (Data_234e1d6c)(r6, r1, 1, 0);
    }
    //loc_2348dde8
    if ((r4->help != 0) && 
        (b == 1) && 
        (r4->help->Data_0x20 != 0) &&
        (r6->helpStringId != 0xffff))
    {
        text_table_get_string(r6->helpStringId, r4->help->Data_0x20->pString, 243);

        r4->header->Data_0x20->bData_0x17 = 1;

        sub_234089e8(&sp_0x10, 
            r4->help->Data_0x20->pString, 
            r4->help->Data_0x20->bData_0xd, 
            r4->help->Data_0x20->x1, 
            r4->help->Data_0x20->y1,
            r4->help->Data_0x20->x2, 
            2);
    }
    //loc_2348de2c
    if (r4->graphicHandler != 0)
    {
        (r4->graphicHandler)(&sp_0x44, r4->graphicData);
    }
    //loc_2348de38
    return 0;
}


#if 0
mainfunction_thread: ir key=87
sub_2348d61a (todo.c): TODO
sub_2348ca2a (todo.c): TODO
sub_2348d660 (todo.c): TODO
mainfunction_thread: r7=0x2341fc51
sub_2348d3f6 (todo.c): TODO
mainfunction_thread: sp_0xc=0x2341a858
graphic_thread: r7->command=2
loc_23453500: r5->wData_2=0x1, bData_0=0, bData_0x19=1, bData_4=4
loc_23453500: r5->bNumItems=40, r5->pItems=23451274, bData_1=255
dma_start_memcpy: writeAddr=22048000, readAddr=22000000, length=221184
sub_2348d3f6 (todo.c): TODO
sub_2348d3f6 (todo.c): TODO
sub_2348d3f6 (todo.c): TODO
sub_2348d3f6 (todo.c): TODO
sub_2348d3f6 (todo.c): TODO
sub_2348d3f6 (todo.c): TODO
sub_2348d3f6 (todo.c): TODO
sub_2348d3f6 (todo.c): TODO
sub_2348d3f6 (todo.c): TODO
sub_2348d3f6 (todo.c): TODO
#endif


#endif //!VDR110
