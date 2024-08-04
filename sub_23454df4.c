
#include "data.h"
#include "fe_manager.h"
#include "ota.h"
#include "scan.h"
#include "nit.h"
#include "psi.h"


/* 23454764 - todo */
static void sub_23454764(void)
{
#if 1
	console_send_string("sub_23454764 (todo.c): TODO\r\n");
#endif

}


/* 23454848 - todo */
static void sub_23454848(void)
{
#if 1
	console_send_string("sub_23454848 (todo.c): TODO\r\n");
#endif

}


/* 234548c0 - todo */
static int sub_234548c0(int r5)
{
#if 0
	console_send_string("sub_234548c0 (todo.c): TODO\r\n");
#endif

    Struct_2358ca84* r4 = sub_23414244();

    sub_234101e8(); //->scan.c

    if (r5 != 0)
    {
        //loc_234548f0
        r4->wData_0x8d2a = 3;
    }
    else if (r4->wData_0x8d2c & (1 << 1))
    {
        //loc_234548f0
        r4->wData_0x8d2a = 3;
    }
    else
    {
        //loc_234548f8
        r4->wData_0x8d2a = 0;

        if (r4->Data_4 != 0)
        {
            (r4->Data_4)(5);
        }
    }

    return 0;
}


/* 23454918 - todo */
static void sub_23454918(void)
{
#if 0
	console_send_string("sub_23454918 (todo.c): TODO\r\n");
#endif
    Struct_2344dc3c sp;

    Struct_2358ca84* r4 = sub_23414244();

    psi_get_network_info(&sp, main_hPSIDecoder1);

    if (0 == sub_23454f30(r4->sema, 100))
    {
        //0x23454948
        if (sp.Data_0 == 0)
        {
            r4->bData_0x8d35 = 1; //r6
            r4->wData_0x8d28 = 1; //r6
            //->loc_234549cc
        }
        else
        {
            //0x23454968
            r4->bData_0x8d35 = sp.Data_0->bData_6;
            r4->wData_0x8d2c |= (1 << 0);

            NIT_TransportStream* r0 = sp.pTransportStream;
            uint32_t r1 = 200;
            while (r1 != 0)
            {
                //loc_23454994
                if (r0->transport_stream_id == sp.Data_0->wData_0)
                {
                    //0x234549a0
                    sub_2344db20(r0, &r4->Data_0x35c);

                    r4->wData_0x8d2c |= (1 << 1);
                    r4->wData_0x8d2a = 1; //r6
                    //->loc_234549cc
                    break;
                }
                //loc_234549bc
                r0++;
                r1--;
            }
            //loc_234549cc
        }
        //loc_234549cc
        OSSemPost(r4->sema);
    }
    //loc_234549d4
}


/* 234549d8 - todo */
static int sub_234549d8(int r5)
{
#if 0
	console_send_string("sub_234549d8 (todo.c): TODO\r\n");
#endif

    Struct_2358ca84* r4 = sub_23414244();

    sub_234101e8();

    if (r5 == 0)
    {
        r4->wData_0x8d2a = 4;
    }
    else
    {
        r4->wData_0x8d2a = 0;

        if (r4->Data_4 != 0)
        {
            (r4->Data_4)(5);
        }
    }

    if (r4->Data_0x10 != 0)
    {
        (r4->Data_0x10)(0, 1, 2);
    }

    return 0;
}


/* 23454a3c - todo */
static void sub_23454a3c(void)
{
#if 0
	console_send_string("sub_23454a3c (todo.c): TODO\r\n");
#endif

    Struct_2358ca84* r5 = sub_23414244();
    Struct_2344dbdc sp_0x10;
    Struct_2344dbdc sp4;;

    if (r5->bData_0x8d35 == 1)
    {
        //0x23454a68
        sub_234067f0(&sp_0x10, main_hPSIDecoder1);
    }
    else
    {
        //loc_23454a70
        sub_234068ac(&sp_0x10, main_hPSIDecoder1);
    }
    //loc_23454a74
    if (0 == sub_23454f30(r5->sema, 100))
    {
        //0x23454a88
        r5->wData_0x8d28 = 5000;
        //r7 = 1;
        if (sp_0x10.Data_0 != 0)
        {
            //0x23454aa4
            r5->wData_0x8d2c |= (1 << 2);

            NIT_TransportStream* r0 = sp_0x10.pTransportStream;
            uint32_t r6 = 200;
            while (r6 != 0)
            {
                //loc_23454ac0
                if (r0->transport_stream_id == sp_0x10.Data_0->wData_0)
                {
                    //0x23454acc
                    sub_2344db20(r0, &r5->Data_0x35c);

                    r5->wData_0x89cc = sp_0x10.Data_0->wData_2;
                    r5->wData_0x89ce = sp_0x10.Data_0->wData_0;
                    r5->wData_0x89d0 = sp_0x10.Data_0->wData_4;

                    r5->wData_0x8d2c |= (1 << 3);
                    r5->wData_0x8d2a = 1; //r7
                    if (r6 != 0)
                    {
                        //->loc_23454bb8
                        #if 0
                        OSSemPost(r5->sema);
                        return;
                        #else
                        goto loc_23454bb8;
                        #endif
                    }
                    else
                    {
                        //->loc_23454b28
                        break;
                    }
                }
                //loc_23454b18
                r0++;
                r6--;
            } //while (r6 != 0)
            //loc_23454b28
            if (r5->bData_0x8d35 == 2)
            {
                //0x23454b34
                sub_234067f0(&sp4, main_hPSIDecoder1);

                r0 = sp4.pTransportStream;
                r6 = 200;
                while (r6 != 0)
                {
                    //loc_23454b4c
                    if (r0->transport_stream_id == sp_0x10.Data_0->wData_0)
                    {
                        //0x23454b58
                        sub_2344db20(r0, &r5->Data_0x35c);

                        r5->wData_0x89cc = sp_0x10.Data_0->wData_2;
                        r5->wData_0x89ce = sp_0x10.Data_0->wData_0;
                        r5->wData_0x89d0 = sp_0x10.Data_0->wData_4;

                        r5->wData_0x8d2c |= (1 << 3);
                        r5->wData_0x8d2a = 1; //r7
                        if (r6 != 0)
                        {
                            //->loc_23454bb8
                            #if 0
                            OSSemPost(r5->sema);
                            return;
                            #else
                            goto loc_23454bb8;
                            #endif
                        }
                        else
                        {
                            //->loc_23454bb4
                            break;
                        }
                    }
                    //loc_23454ba4
                    r0++;
                    r6--;
                } //while (r6 != 0)
            }
            //loc_23454bb4
        } //if (sp_0x10.Data_0 != 0)
        //loc_23454bb4
        r5->wData_0x8d28 = 1; //r7

loc_23454bb8:
        OSSemPost(r5->sema);
    }
    //loc_23454bc0
}


/* 23454bc8 - todo */
static int sub_23454bc8(void)
{
#if 0
	console_send_string("sub_23454bc8 (todo.c): TODO\r\n");
#endif

    Struct_23410148 sp_0x5c;
    Channel sp_0x34;
    Struct_2340bf0c sp;

    Struct_2358ca84* r4 = sub_23414244();

#if 0
    {
        extern char debug_string[];
        sprintf(debug_string, "sub_23454bc8: r4->wData_0x8d2a=%d\r\n",
            r4->wData_0x8d2a);
        console_send_string(debug_string);
    }
#endif

    if (r4->wData_0x8d2a == 0)
    {
        if (r4->wData_0x8d28 != 0)
        {
            r4->wData_0x8d28--;
            if (r4->wData_0x8d28 == 0)
            {
                if (r4->Data_8 != 0)
                {
                    (r4->Data_8)(2);
                }

                return 2;
            }
        }
        //loc_23454dec
    }
    //loc_23454c24
    else if (r4->wData_0x8d2a == 1)
    {
        if (r4->Data_8 != 0)
        {
            (r4->Data_8)(0);
        }
        //->loc_23454dec
    }
    //loc_23454c40
    //r7 = 5000;
    //r6 = 0;
    //r8 = 1;
    else if (r4->wData_0x8d2a == 2)
    {
        //0x23454c54
        sub_2340bf0c(&sp);
        sub_2340bf94(sp.wCurrentChannel, &sp_0x34, &r4->Data_0x35c);

        sp_0x5c.Data_0 = &r4->Data_0x35c;
        sp_0x5c.wData_4 = 1; //r8
        sp_0x5c.Data_8 = 0; //r6
        sp_0x5c.Data_12 = 0; //r6
        sp_0x5c.bData_16 = 0; //r6

        if (0 == sub_23410148(&sp_0x5c, 0x40, sub_23454918, 0)) //->scan.c
        {
            //->loc_23454de0
            r4->Data_8 = sub_234548c0;
            r4->wData_0x8d28 = 5000; //r7
            //loc_23454de8
            r4->wData_0x8d2a = 0; //r6
        }
        //->loc_23454dec
    }
    //loc_23454ca8
    else if (r4->wData_0x8d2a == 3)
    {
        //0x23454cb0
        int r0;

        sp_0x5c.Data_0 = &r4->Data_0x35c;
        sp_0x5c.wData_4 = 1; //r8
        sp_0x5c.Data_8 = 0; //r6
        sp_0x5c.Data_12 = 0; //r6
        sp_0x5c.bData_16 = 0; //r6

        if (r4->bData_0x8d35 == 2)
        {
            //->loc_23454d14
            r0 = sub_23410148(&sp_0x5c, 0x80, sub_23454a3c, 0xff00);
        }
        else 
        {
            if (r4->bData_0x8d35 != 1)
            {
                //0x23454cec
                sub_2340bf0c(&sp);
                sub_2340bf94(sp.wCurrentChannel, &sp_0x34, &r4->Data_0x35c);

                r4->bData_0x8d35 = 1; //r8
            }
            //loc_23454d08
            r0 = sub_23410148(&sp_0x5c, 0x40, sub_23454a3c, 0);
        }

        if (r0 == 0)
        {
            //0x23454d24
            r4->Data_8 = sub_234549d8;
            r4->wData_0x8d28 = 500; 
            //->loc_23454de8
            r4->wData_0x8d2a = 0; //r6
        }
        //->loc_23454dec
    }
    //loc_23454d38
    else if (r4->wData_0x8d2a == 4)
    {
        //0x23454d40
        if (r4->Data_0x10 != 0)
        {
            (r4->Data_0x10)(0, 0, 3);
        }

        int r0 = sub_2340d0d0();
        if (r0 == 0)
        {
            //0x23454d6c

            //->loc_23454dcc
            fe_manager_tune(main_hFrontend1, r4->Data_0x35c, sub_23454848, 0);
        }
        else
        {
            //loc_23454d88
            fe_manager_tune(Data_23491db8, r4->Data_0x35c, 0, 0);
            //loc_23454dcc
            fe_manager_tune(main_hFrontend1, r4->Data_0x35c, sub_23454848, 0);
        }

        r4->Data_8 = sub_23454764;
        r4->wData_0x8d28 = 5000; //r7
        //loc_23454de8
        r4->wData_0x8d2a = 0; //r6
    }
    //loc_23454dec
    return 0;
}


/* 23454df4 - todo */
void sub_23454df4(Struct_23414198* r6)
{
#if 0
	console_send_string("sub_23454df4 (todo.c): TODO\r\n");
#endif

    int sp;
    Struct_2358ca84* r4 = sub_23414244();

    if (r6->bData_0xe == 1)
    {
        r4->Data_0x10 = r6->Data_4; 
        r4->Data_0x14 = sub_23454bc8;
        r4->wData_0x8d2a = 2;
        r4->bData_0x8d32 = 20;
        r4->wData_0x8d2c = 0; 
        r4->wData_0x8d30 = 0; 
        r4->wData_0x8d2e = 31;
    }
    else if (r6->bData_0xe == 2)
    {
        r4->Data_4 = 0;

        if (r4->Data_8 != 0)
        {
            (r4->Data_8)(0xff);
        }

        r4->bData_0x8d32 = 0;
        r4->Data_0x14 = 0;
        r4->Data_0x1c = 0;
        r4->wData_0x8d28 = 0;
        r4->wData_0x8d2a = 0;
    }

    if (r6->mbox != 0)
    {
        OSMboxPost(r6->mbox, &sp);
    }
}


/* 23454f30 - complete */
int sub_23454f30(void* sema, uint32_t timeout)
{
#if 0
	console_send_string("sub_23454f30 (todo.c): TODO\r\n");
#endif

    uint8_t err = 0;
    OSSemPend(sema, timeout, &err);
    return err;
}


