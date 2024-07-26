
#include "data.h"
#include "sub_2340a6a0.h"
#include "channel_list_update.h"
#include "ota.h"
#include "sub_23472004.h"

#pragma thumb


void* Data_23496474 = 0; //23496474

struct
{
    int fill_0[10/*size???*/]; //0
    //?
} Data_238e0ad4; //238e0ad4


/* 23472004 - todo */
int sub_23472004(int a)
{
    uint8_t err;
    Struct_235441b0 sp8;

#if 0
	console_send_string("sub_23472004 (todo.c): TODO\r\n");
#endif

    if (Data_23496474 != 0)
    {
        //0x23472012
        if (a != 0)
        {
            Data_23496474 = OSSemDel(Data_23496474, 1, &err);

            sub_2340c970(1, &sp8);

            if (sp8.Data_0x10 & (1 << 7))
            {
                powermode_set_onoff_callbacks(channel_list_update_start, sub_2343deb4);
            }
        }
        else
        {
            //loc_23472038
            OSSemPend(Data_23496474, 10, &err);

            if (err == 0)
            {
                //0x23472046
                Data_23496474 = OSSemDel(Data_23496474, 1, &err);

                sub_23414198(2, 1, 0, 0, &Data_238e0ad4);

                sub_2340c970(1, &sp8);

                if (sp8.Data_0x10 & (1 << 7))
                {
                    powermode_set_onoff_callbacks(channel_list_update_start, sub_2343deb4);
                }
            }
        }
    }
    //loc_23472078
    return 0;
}


/* 2347207e - todo */
static void sub_2347207e(int a)
{
#if 1
	console_send_string("sub_2347207e (todo.c): TODO\r\n");
#endif

}


/* 234720a4 - complete */
int sub_234720a4(int a)
{
    Struct_2341413c sp4;

#if 0
	console_send_string("sub_234720a4 (todo.c): TODO\r\n");
#endif

    if (Data_23496474 != 0)
    {
        return 0;
    }

    Data_23496474 = OSSemCreate(1);

    sub_2340b22c(0xff);

    sp4.bData_0 = 1;
    sp4.Data_4 = 1;
    sp4.Data_8 = sub_2347207e;

    sub_2341413c(&sp4);

    sub_23414198(1, 1, 0, 0, &Data_238e0ad4);

    return 1;
}


