
#include "data.h"
#include "ucos_ii.h"
#include "sub_2345bc50.h"


typedef struct sub_2345bc50
{
    int Data_0; //0
    int Data_4; //4
    int fill_8[32776]; //8
    //131112???
} Struct_237e5910;


struct
{
    //0x237e5900
    void* sema; //237e5900 +0
    void* Data_237e5904; //237e5904 +4
    int Data_237e5908; //237e5908 +8
    int Data_237e590c; //237e590c +12
    Struct_237e5910 Data_237e5910[2]; //237e5910 +0x10  + 2*131112 = 262224 -> 23825960
    int Data_23825960; //23825960
    Struct_2349203c Data_23825964; //23825964
    int Data_2382596c; //2382596c
    int Data_23825970[7]; //23825970
    uint16_t wData_2382598c; //2382598c
    //???
} Data_237e5900; //237e5900 +x = 




/* 2345b2e0 - todo */
void sub_2345b2e0(void)
{
    uint8_t i = 2;

#if 1
	console_send_string("sub_2345b2e0 (todo.c): TODO\r\n");
#endif

    while (i--)
    {
        sub_2345bd40(&Data_237e5900.Data_237e5910[i]);
    }

    Data_237e5900.Data_23825960 = 0;
    Data_237e5900.Data_2382596c = 0;
    Data_237e5900.wData_2382598c = 0xffff;

    sub_234216fc(Data_237e5900.Data_237e5904);
    tsd_set_pes_pid_filter(Data_237e5900.Data_237e5904, Data_237e5900.Data_23825964.pid);
    tsd_activate_pid_channel(Data_237e5900.Data_237e5904);
}


/* 2345b350 - todo */
static void sub_2345b350()
{
	console_send_string("sub_2345b350 (sub_2345bc50.c): TODO\r\n");

}


/* 2345b99c - todo */
void sub_2345b99c()
{
    if (0 == OSSemAccept(Data_237e5900.sema))
    {
        return;
    }

    if (Data_237e5900.Data_237e5908 != 0)
    {
#if 1
    	console_send_string("sub_2345b99c (sub_2345bc50.c): TODO\r\n");
#endif

        if (Data_237e5900.Data_237e5908 == 1)
        {
            Data_237e5900.Data_237e5908 = 0;
            //->loc_2345bb70
        }
        else
        {
            //0x2345b9d0

        }

        //TODO

        {
            //loc_2345bb70
            sub_23453b88(0, &Data_237e5900.Data_23825970[0]);
        }
    } 
    //loc_2345bb7c
    OSSemPost(Data_237e5900.sema);
}


/* 2345bb88 - complete */
void sub_2345bb88(void)
{
    uint8_t err; //sp

#if 0
	console_send_string("sub_2345bb88 (sub_2345bc50.c): TODO\r\n");
#endif

    OSSemPend(Data_237e5900.sema, 0, &err);

    if (Data_237e5900.Data_237e5908 == 2)
    {
        Data_237e5900.Data_237e5908 = 1;
        Data_237e5900.Data_237e590c = 0;

        tsd_deactivate_pid_channel(Data_237e5900.Data_237e5904);
    }

    OSSemPost(Data_237e5900.sema);
}


/* 2345bbcc - todo */
int sub_2345bbcc(Struct_2349203c* a)
{
    uint8_t err; //sp

#if 1
	console_send_string("sub_2345bbcc (sub_2345bc50.c): TODO\r\n");
#endif

    OSSemPend(Data_237e5900.sema, 0, &err);

    Data_237e5900.Data_23825964 = *a;

    Data_237e5900.Data_237e5908 = 2;

    sub_2345b2e0();

    OSSemPost(Data_237e5900.sema);

    return 0;
}


/* 2345bc50 / 23425e88 - todo */ //Initialization
int sub_2345bc50(Struct_2345bc50* pParams)
{
    BM_OpenParams sp_0x40; //sp_0x40
    TSD_PesParserParams sp4; //sp4
    int32_t r4;

    Data_237e5900.sema = OSSemCreate(1);

    Data_237e5900.Data_237e5908 = 0; //r6

    sp_0x40.Data_0 = 0x10000;
    sp_0x40.Data_4 = -1; //r8
    sp_0x40.Data_0x14 = 1;
    sp_0x40.Data_0x18 = 1;
    sp_0x40.Data_0x1c = 0; //r6
    sp_0x40.Data_0x24 = 0; //r6
    sp_0x40.handleOverflow = sub_2345b350;
    sp_0x40.pidChannel = 10;
    sp_0x40.Data_0x28 = 0; //r6
    sp_0x40.Data_0x2c = 0; //r6
    sp_0x40.Data_0x30 = 0; //r6
    sp_0x40.bufferAddress = pParams->Data_0;
    sp_0x40.bufferSize = pParams->Data_4;

    sp4.Data_4 = sp_0x40;

    sp4.bData_0 = 0; //r6
    sp4.bData_1 = 0xff;
    sp4.pid = 0; //r6
    sp4.Data_0x38 = 0; //r6

    for (r4 = 1; r4 >= 0; r4--)
    {
        //loc_2345bcf0
        sub_2345bd40(&Data_237e5900.Data_237e5910[r4]);

        Data_237e5900.Data_237e5910[r4].Data_0 = -1; //r8
        Data_237e5900.Data_237e5910[r4].Data_4 = 0xbd010000;
    }
 
    tsd_open_pes_parser(&Data_237e5900.Data_237e5904, &sp4);

    if (Data_237e5900.Data_237e5904 != 0)
    {
        tsd_get_bm_handle(Data_237e5900.Data_237e5904);
    }

    return 0;
}


