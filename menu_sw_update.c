
#include <string.h>
#include "data.h"
#include "frontdisplay.h"
#include "usb_msd.h"
#include "fatfs.h"

#pragma thumb


static int menu_sw_update_filelist_on_navigate(int*);
static int menu_sw_update_filelist_on_enter(int);
static int menu_sw_update_filelist_on_exit(UI_Thread_Params*);
static int sub_2346fe1c(int);
static int sub_2346ffda(int); 
static int sub_2346ffe6(UI_Thread_Params*);
static int sub_2346ffea(int);
static Menu_Item Data_23495e1c[]; //23495e1c
static Menu_Item Data_23495e74[]; //23495e74

static Menu menu_sw_update_filelist = //23495dac
{
    0x015b,
    &Data_23495e1c[0],
    &Data_23495e1c[0],
    0, 0, 0,
    1, 0,
    0,
    menu_sw_update_filelist_on_navigate,
    menu_sw_update_filelist_on_enter,
    menu_sw_update_filelist_on_exit,
    0xff,
    10,
    0
};

static Menu menu_sw_update_no_media = //23495de4
{
    0x01cb, //"USB-Stick?"
    &Data_23495e74[0],
    &Data_23495e74[0],
    0, 0, 0,
    0, 0,
    0,
    0, //int (*onNavigate)(int*)
    sub_2346ffda, //int (*onEnter)(int);
    sub_2346ffe6, //int (*onExit)(UI_Thread_Params*);
    0xff,
    10,
    0
};

Menu_Item Data_23495e1c[] = //23495e1c
{
    {
        0xffff,
        0xffff,
        {0},
        0,
        sub_2346fe1c, //onEvent
        menu_event_thread,
        0,
        0
    },
    {
        0x0008
    },
};


Menu_Item Data_23495e74[] = //23495e74
{
    {
        0xffff,
        0xffff,
        {0},
        0,
        sub_2346ffea,
        menu_event_thread,
        0,
        0
    },
};

struct menu_sw_update
{
    int Data_238ddce0; //0 = 238ddce0
    uint32_t Data_4; //4
#if 0
    int Data_8; //8
    int Data_0xc; //12
    int fill_0x10[2]; //16
    uint8_t bData_0x18[256]; //24 = 0x18, size???
    int fill_0x118; //0x118
#else
    Struct_234168fc Data_8; //8
#endif
    int Data_0x11c; //0x11c
    uint16_t arData_0x120[1000]; //288 = 0x120, size???
    //???
} Data_238ddce0; //238ddce0


/* 2346fb48 - todo */
static void* sub_2346fb48(FrontDisplay_Job* a)
{
#if 0
	console_send_string("sub_2346fb48 (todo.c): TODO\r\n");
#endif

    text_table_get_string(0x1C8, &a->bData_8[0], 0xff);

    a->bNumTextChars = strlen(&a->bData_8[0]);
    a->bDisplayOffset = 0;
    a->bNumDisplayChars = 12;
    a->bData_0x10b = 0;
    a->bData_0x10c = 1;
    a->holdTime = 0;
    a->Data_0 = frontdisplay_draw_text;
    a->Data_4 = 0;
    a->bData_0x10f = 0;

    return 0;
}


/* 2346fb82 - todo */
static void* sub_2346fb82(FrontDisplay_Job* r4)
{
#if 0
	console_send_string("sub_2346fb82 (todo.c): TODO\r\n");
#endif

//    void* sp[3];
    uint32_t r5;
    uint8_t r6 = 0;

    usb_lock();

    if (Data_238ddce0.Data_238ddce0 != 0)
    {
        r5 = Data_238ddce0.arData_0x120[Data_238ddce0.Data_238ddce0 - 1];

    }
    else
    {
        r5 = 0;
    }
    //loc_2346fba2
//    sp[2] = &r4->bData_8[0];
//    sp[1] = &Data_238ddce0.Data_0x100[0];
//    sp[0] = &Data_238ddce0.Data_8;
    //->loc_2346fbcc
    uint8_t r0 = 0;
    while (r5 <= Data_238ddce0.arData_0x120[Data_238ddce0.Data_238ddce0])
    {
        //loc_2346fbb4
        Data_238ddce0.Data_8.Data_0 = r5;
        Data_238ddce0.Data_8.Data_4 = Data_238ddce0.Data_0x11c;

        r0 = sub_234168fc(0, &Data_238ddce0.Data_8); 
        if (r0 != 0)
        {
            //->loc_2346fc44
            break;
        }
        //0x2346fbca
        r5++;
    }

    if (r0 == 0)
    {
        //0x2346fbdc
        //r5 = &Data_238ddce0.bData_0x18[1]
        if (Data_238ddce0.Data_8.bData_0x10 == 0)
        {
            //0x2346fbe6
            strncpy(/*sp[2]*/&r4->bData_8[0], &Data_238ddce0.Data_8.arFileName[0], 0xff);
            //->loc_2346fc3e
            //->loc_2346fc50
        }
        //loc_2346fbee
        else if (0 == strncmp(&Data_238ddce0.Data_8.arFileName[0], "..", 2))
        {
            //0x2346fbfc
            text_table_get_string(0x1C7, /*sp[2]*/&r4->bData_8[0], 0xff);
            //->loc_2346fc50
        }
        else
        {
            //loc_2346fc0a
            r4->bData_8[0] = 0x15;
            r4->bData_8[1] = 0;
            r4->bNumTextChars = 1;
            r4->bDisplayOffset = r6;
            r4->bNumDisplayChars = 1;
            r4->bData_0x10b = 0;
            r4->bData_0x110 = 0;
            r4->holdTime = 0;
            r4->Data_4 = 0;
            r4->bData_0x10f = 0;
            r4->bData_0x10c = 0;
            r4->Data_0 = frontdisplay_draw_text;

            r6++;
            r4++;

            strncpy(&r4->bData_8[0], &Data_238ddce0.Data_8.arFileName[0], 0xff);
            //->loc_2346fc50
        }        
    } //if (r0 == 0)
    else
    {
        snprintf(/*sp[2]*/&r4->bData_8[0], 0x100, "???");
        //loc_2346fc50
    }
    //loc_2346fc50
    usb_unlock();

    uint8_t len = strlen(&r4->bData_8[0]);
    r4->bNumTextChars = len;
    r4->bDisplayOffset = r6;
    r4->bNumDisplayChars = 12;
    r4->bData_0x10b = 0;
    r4->bData_0x110 = 0;
    r4->holdTime = 0;
    r4->Data_4 = 0;
    r4->bData_0x10f = 0;
    r4->bData_0x10c = 0;
    r4->Data_0 = frontdisplay_draw_text;

    if (len > 12)
    {
        r4->bData_0x10c = 1;
        r4->Data_0 = frontdisplay_draw_scroll_text;
    }

    return sub_2346fb82;
}


/* sub_2346fc8c - complete */
static void* sub_2346fc8c(FrontDisplay_Job a[])
{
#if 0
	console_send_string("sub_2346fc8c (todo.c): TODO\r\n");
#endif

    a[0].bData_8[0] = 0x22;

    text_table_get_string(menu_sw_update_filelist.stringId, &a[0].bData_8[1], 12);

    uint8_t len = strlen(&a[0].bData_8[0]);

    a[0].bData_8[len] = 0x22;
    len++;
    a[0].bData_8[len] = 0;

    a[0].bNumTextChars = strlen(&a[0].bData_8[0]);
    a[0].bDisplayOffset = 0;
    a[0].bNumDisplayChars = 12;
    a[0].bData_0x10b = 0;
    a[0].bData_0x10c = 0;
    a[0].bData_0x110 = 0;
    a[0].holdTime = 20;
    a[0].Data_0 = frontdisplay_draw_text;
    a[0].Data_4 = 0;
    a[0].bData_0x10f = 0;

    return sub_2346fb82;
}


/* 2346fce2 - todo */
int menu_sw_update_filelist_on_navigate(int* a)
{
#if 0
	console_send_string("menu_sw_update_filelist_on_navigate (todo.c): TODO\r\n");
#endif

    int r2 = *a;

    if (r2 == 2)
    {
        Data_238ddce0.Data_238ddce0--;
        if (Data_238ddce0.Data_238ddce0 < 0)
        {
            Data_238ddce0.Data_238ddce0 = Data_238ddce0.Data_4;
        }
        //->loc_2346fd08
    }
    else if (r2 == 1)
    {
        Data_238ddce0.Data_238ddce0++;
        if (Data_238ddce0.Data_238ddce0 > Data_238ddce0.Data_4)
        {
            Data_238ddce0.Data_238ddce0 = 0;
        }
    }

    return 0;
}


/* 2346fd0c - complete */
int sub_2346fd0c(int a)
{
#if 0
	console_send_string("sub_2346fd0c (todo.c): TODO\r\n");
#endif

    int r1 = 0;
    uint8_t r0 = 0;
    uint32_t r4 = 0;
    uint16_t* r5 = &Data_238ddce0.arData_0x120[0];

    Data_238ddce0.Data_238ddce0 = r1;
    Data_238ddce0.Data_0x11c = a;
    Data_238ddce0.Data_4 = r1;

    for (r4 = 0; r4 < 1000; r4++)
    {
        //loc_2346fd26
        Data_238ddce0.Data_8.Data_0 = r4;
        Data_238ddce0.Data_8.Data_4 = Data_238ddce0.Data_0x11c;

        r0 = sub_234168fc(0, &Data_238ddce0.Data_8);
        if (r0 != 0)
        {
            //->loc_2346fd5c
            break;
        }
        //0x2346fd3a
        if (Data_238ddce0.Data_8.arFileName[0] != 0)
        {
            //0x2346fd40
            if ((Data_238ddce0.Data_8.arFileName[0] != 0x2e) || (r4 != 0))
            {
                //loc_2346fd48
                *r5 = r4;
                r5++;
                Data_238ddce0.Data_4++;
            }
        }
        //loc_2346fd52
    }
    //loc_2346fd5c
    Data_238ddce0.Data_4--;

    return 0;
}


/* 2346fd66 - complete */
int menu_sw_update_filelist_on_enter(int a)
{
#if 0
	console_send_string("menu_sw_update_filelist_on_enter (todo.c): TODO\r\n");
#endif

    sub_2346fd0c(2);
    frontdisplay_start_text(sub_2346fc8c);

    return 0;
}


/* 2346fd78 - complete */
int menu_sw_update_filelist_on_exit(UI_Thread_Params* a)
{
    Struct_2340bf0c sp_0x28;
    Channel sp;

#if 0
	console_send_string("menu_sw_update_filelist_on_exit (todo.c): TODO\r\n");
#endif

    sub_2340bf0c(&sp_0x28);

    if (sp_0x28.wNumChannels != 0)
    {
        channel_start_number(&sp, sp_0x28.wCurrentChannel, sp_0x28.wCurrentChannel);
    }
    else
    {
        sub_2340b22c(0xff);
    }

    return 0;
}


/* 2346fda2 - todo */
int sub_2346fda2(char* a, int b)
{
#if 1
	console_send_string("sub_2346fda2 (todo.c): TODO\r\n");
#endif

    int sp4 = 0; //r5
    int sp;

    int r0 = fatfs_open_file(&sp4, a, 0x100, b);

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "sub_2346fda2: r0=%d\r\n", 
            r0);
        console_send_string(debug_string);
    }
#endif

    if (r0 == 0)
    {
        frontdisplay_start_text(sub_2346fb48);

        sub_2340b22c(0xff);

        volatile uint32_t* r4 = (void*) 0x40000000;
        r4[0] = 0x01234567;
        uint32_t r0 = r4[0] - 0x01234567; 
        if (r0 != 0)
        {
            r4 = (void*) 0x20000000;
        }
        //loc_2346fdda
        int r7 = fatfs_get_file_size(sp4);

        int r0_ = fatfs_read_file(&sp4, r4, r7, &sp);

#if 0
        hex_dump("sub_2346fda2", r4, r7);
#endif

#if 1
        {
            extern char debug_string[];
            sprintf(debug_string, "sub_2346fda2: r7=%d, r0_=%d\r\n", 
                r7, r0_);
            console_send_string(debug_string);
        }
#endif

#if 0
        if (r7 == r0_)
        {
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
            OS_CPU_SR  cpu_sr = 0u;
#endif

            OS_ENTER_CRITICAL();

            ((volatile uint32_t*)0xCA00003C)[0] = 0;

            sub_234018e0(r4, r7);

            OS_EXIT_CRITICAL();

            sub_23438990();

            ((volatile uint32_t*)0xCA00003C)[0] = 0xffff000;

            while (1) {}
        }
        //loc_2346fe18
#endif
    }
    //loc_2346fe18
    return 0;
}


/* 2346fe1c - todo */
int sub_2346fe1c(int r4)
{
#if 0
	console_send_string("sub_2346fe1c (todo.c): TODO\r\n");
#endif

    usb_lock();

    if (r4 != 0)
    {
        //0x2346fe28
        uint32_t r4;

        if (Data_238ddce0.Data_238ddce0 != 0)
        {
            r4 = Data_238ddce0.arData_0x120[Data_238ddce0.Data_238ddce0 - 1];
            //->loc_2346fe3e
        }
        else
        {
            //loc_2346fe3c
            r4 = 0;
        }
        //loc_2346fe3e
        //r5 = 238DDDE0; //&Data_238ddce0.Data_0x100;
        //r7 = &Data_238ddce0.Data_8;
        //->loc_2346fe58
        while (r4 <= Data_238ddce0.arData_0x120[Data_238ddce0.Data_238ddce0])
        {
            //loc_2346fe48
            Data_238ddce0.Data_8.Data_0 = r4;
            Data_238ddce0.Data_8.Data_4 = Data_238ddce0.Data_0x11c;

            sub_234168fc(0, &Data_238ddce0.Data_8);

            r4++;
        }
        //0x2346fe6a
        if (Data_238ddce0.Data_8.bData_0x10 == 0)
        {
            //0x2346fe70
            char* r4 = &Data_238ddce0.Data_8.arFileName[0];
#if 0
            if (0 == strncmp(r4, "DECODER APP", 11) ||
                (0 == strncmp(r4, "decoder.app", 11)))
#endif
            {
                //loc_2346fe90
                sub_2346fda2(r4, Data_238ddce0.Data_0x11c);
            }
            //->loc_2346fee8
        }
        else
        {
            //loc_2346fe9a
            sub_2346fd0c(Data_238ddce0.Data_8.Data_4);
        }
        //->loc_2346fee8
    } //if (r4 != 0)
    else
    {
        //loc_2346fea2
        if (0 == fatfs_volume_get_usb_device(0))
        {
            usb_unlock();

            extern uint32_t sub_2343d580(void);

            if (sub_2343d580() <= 2)
            {
                //->loc_2346fef0
                return 0xff;
            }
            //0x2346feb8
            if (menu_sw_update_filelist.onExit != 0)
            {
                (menu_sw_update_filelist.onExit)(0);
            }
            //loc_2346fec4
            sub_2343d482(0);
            sub_2343d482(&menu_sw_update_no_media);
            sub_2343d3ac(&menu_sw_update_no_media);
            sub_2343d51e(&menu_sw_update_no_media, sub_2343d572());
        }
        //loc_2346fee8
    }
    //loc_2346fee8
    usb_unlock();

    return 0;
}


/* 2346ff0e - todo */
void sub_2346ff0e()
{
	console_send_string("sub_2346ff0e (todo.c): TODO\r\n");

}


/* 2346ff46 - todo */
static void* sub_2346ff46(FrontDisplay_Job a[])
{
#if 0
	console_send_string("sub_2346ff46 (todo.c): TODO\r\n");
#endif

    text_table_get_string(menu_sw_update_no_media.stringId, &a[0].bData_8[0], 12);

    uint8_t len = strlen(&a[0].bData_8[0]);
    len++;
    a[0].bData_8[len] = 0;

    a[0].bNumTextChars = strlen(&a[0].bData_8[0]);
    a[0].bDisplayOffset = 0;
    a[0].bNumDisplayChars = 12;
    a[0].bData_0x10b = 0;
    a[0].bData_0x10c = 0;
    a[0].bData_0x110 = 0;
    a[0].holdTime = 0;
    a[0].Data_0 = frontdisplay_draw_text;
    a[0].Data_4 = 0;
    a[0].bData_0x10f = 0;

    return sub_2346ff46;
}


/* 2346ffda - complete */
static int sub_2346ffda(int a)
{
#if 0
	console_send_string("sub_2346ffda (todo.c): TODO\r\n");
#endif

    frontdisplay_start_text(sub_2346ff46);

    return 0;
}


/* 2346ffe6 - todo */
int sub_2346ffe6(UI_Thread_Params* a)
{
#if 0
	console_send_string("sub_2346ffe6 (todo.c): TODO\r\n");
#endif

    return 0;
}


/* 2346ffea - todo */
int sub_2346ffea(int r4)
{
#if 0
	console_send_string("sub_2346ffea (todo.c): TODO\r\n");
#endif

    usb_lock();

    if (r4 != 0)
    {
        if (0 == fatfs_volume_get_usb_device(0))
        {
            usb_unlock();

            return 0xff;
        }
    }
    else
    {
        if (0 != fatfs_volume_get_usb_device(0))
        {
            if (menu_sw_update_no_media.onExit != 0)
            {
                (menu_sw_update_no_media.onExit)(0);
            }

            sub_2343d482(0);
            sub_2343d482(&menu_sw_update_filelist);
            sub_2343d3ac(&menu_sw_update_filelist);
            sub_2343d51e(&menu_sw_update_filelist, sub_2343d572());
        }
    }

    usb_unlock();

    return 0;
}


/* 2347004a - complete */
int menu_sw_update_entry(UI_Thread_Params* p)
{
#if 0
	console_send_string("menu_sw_update_entry (todo.c): TODO\r\n");
#endif

    Menu* pMenu;

    usb_lock();

    if (fatfs_volume_get_usb_device(0) == 0)
    {
        pMenu = &menu_sw_update_no_media;   
    }
    else
    {
        pMenu = &menu_sw_update_filelist;
    }

    usb_unlock();

    sub_2343d482(pMenu);
    sub_2343d3ac(pMenu);
    sub_2343d51e(pMenu, sub_2343d572());

    return 0;
}


