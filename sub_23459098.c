

#include "data.h"
#include "ts_play.h"
#include "sub_23459098.h"

extern void sub_2345d090();

//23493e54
Struct_235b0b08* Data_23493e54 = NULL; //23493e54 +0
void (*Data_23493e58)() = NULL; //23493e58 +4

struct Struct_23493e60
{
    uint8_t bData_0; //0
    uint8_t bData_1; //1
    int fill_4[2]; //4
    int Data_0xc; //12 = 0xc
    //???
} Data_23493e60 = {0xff, /*TODO!!!*/}; //23493e60


static void* sub_234593d0(Struct_235b0b08*);


/* 23458c44 - todo */
void sub_23458c44()
{
#if 1
	console_send_string("sub_23458c44 (todo.c): TODO\r\n");
#endif

}


/* 23458d44 - todo */
void sub_23458d44()
{
#if 1
	console_send_string("sub_23458d44 (todo.c): TODO\r\n");
#endif

}


/* 23458dd8 - todo */
void sub_23458dd8()
{
#if 1
	console_send_string("sub_23458dd8 (todo.c): TODO\r\n");
#endif

}


/* 23458ed0 /  / 23477c90 - todo */
void* sub_23458ed0(Struct_235b0b08* r4)
{
#if 0
	console_send_string("sub_23458ed0 (todo.c): TODO\r\n");
#endif

    Struct_2340ce18 sp;

    if ((r4->Data_0 & 0xffff) != 0)
    {
        r4->Data_0 = -1;
        r4->Data_0x28 = sub_23458d44;
        r4->Data_0x24 = sub_23458dd8;
        r4->Data_0x30 = sub_23458c44;
        r4->Data_0x34 = sub_234593d0;

        r4->Data_0x50 = 0xff;
        r4->bData_0x54 = 0;
        r4->Data_0x48 = 0x23400;
        r4->Data_0x4c = 0;

        sub_2340ce18(&sp);

        sub_2341e524(tsd_get_bm_handle(sp.Data_4), 0, 1);
    } //if ((r4->Data_0 & 0xffff) != 0)
    else
    {
        if (r4->Data_0x34 != NULL)
        {
            r4->Data_0x34 = (r4->Data_0x34)(r4);
        }

        Data_23493e60.bData_0 = 0xff;

        r4->Data_0x28 = NULL;
        r4->Data_0 = 0;
    }

    return NULL;
}


/* 23459084 /  / 23477e44 - complete */
void* sub_23459084()
{
#if 0
	console_send_string("sub_23459084 (todo.c): TODO\r\n");
#endif

    Data_23493e54->Data_0 = 0;

    return NULL;
}



/* 23459098 /  / 23477e58 - todo */
int sub_23459098(Struct_23459098* r6)
{
#if 0
	console_send_string("sub_23459098 (todo.c): TODO\r\n");
#endif

    int r4 = 32;

    OS_CPU_SR  cpu_sr = 0u;

	OS_ENTER_CRITICAL();

    //r7 = 0;
    if (Data_23493e54->Data_0 == 0)
    {
        struct Struct_23493e60* r1 = &Data_23493e60;
        r1->Data_0xc = 0; //r7
        //->loc_23459100
    }
    else
    {
        //0x234590c8
        Data_23493e54->Data_0x20 = sub_23459084;
        Data_23493e54->Data_0 &= 0xffff0000;
        OS_EXIT_CRITICAL();
        //->loc_234590ec
        while (Data_23493e54->Data_0 != 0)
        {
            //loc_234590e4
            rtos_task_wait(1);
        }
        //0x234590fc
        OS_ENTER_CRITICAL();
    }
    //loc_23459100
    if (r6->wData_8 == 0xff)
    {
        Data_23493e54->Data_0x20 = sub_23458ed0;
    }
    else
    {
        Data_23493e54->Data_0x20 = sub_2345d090;
    }

    Data_23493e54->Data_0 = 1;
    Data_23493e54->Data_0x58 = *r6;
    Data_23493e54->Data_0xf8 = 0; //r7

    OS_EXIT_CRITICAL();
    //loc_23459158
    while (r4--)
    {
        //loc_2345913c
        if (Data_23493e54->Data_0 != 1)
        {
            return Data_23493e54;
        }

        rtos_task_wait(1);
    }

    return 0;
}

 
/* 23459168 - todo */
int sub_23459168(Struct_23459168* a)
{
#if 0
	console_send_string("sub_23459168 (todo.c): TODO\r\n");
#endif

    if (Data_23493e54 == NULL)
    {
        Data_23493e54 = a->Data_0;
        Data_23493e58 = a->Data_4;
    }
}


/* 23459188 /  / 23477f48 - todo */
int sub_23459188()
{
#if 0
	console_send_string("sub_23459188 (todo.c): TODO\r\n");
#endif

    OS_CPU_SR  cpu_sr = 0u;

    OS_ENTER_CRITICAL();

    if (Data_23493e54->Data_0 == 0)
    {
        OS_EXIT_CRITICAL();
    }
    else
    {
        if (Data_23493e54->Data_0x58.wData_8 != 0xff)
        {
            Data_23493e54->Data_0x20 = sub_2345d090;
        }
        else
        {
            Data_23493e54->Data_0x20 = sub_23458ed0;
        }

        Data_23493e54->Data_0 &= 0xffff0000;
        
        OS_EXIT_CRITICAL();

        while (Data_23493e54->Data_0 != 0)
        {
            rtos_task_wait(1);
        }
    }

    return 0;
}


/* 234593d0 /  / 23478190 - complete */
void* sub_234593d0(Struct_235b0b08* a)
{
#if 0
	console_send_string("sub_234593d0 (todo.c): TODO\r\n");
#endif

    Channel_Audio_Handles h;

    channel_get_audio_handles(&h);
    auout_set_volume(h.hAuOut, 8, 0);
    auout_stop_hdmi();
    audec_stop_decoder(h.hAudec5);
    sub_2342b9cc(h.hAuOut, 0);

    return NULL;
}



