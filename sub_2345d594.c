
#include "data.h"
#include "ts_play.h"
#include "sub_23459098.h"
#include "sub_23419cd0.h"


//234940a4 /  / 234dd7d0
void* Data_234940a4 = 0; //234940a4 +0 /  / 234dd7d0
int Data_234940a8 = 0; //234940a8 +4

//234940ac
Struct_23459098_Inner0 Data_234940ac = {0, 0}; //234940ac
//234940b4
Struct_23459098_Inner0 Data_234940b4 = {0, 0}; //234940b4


typedef struct
{
    int fill_0[8]; //0
    int Data_0x20; //0x20 = 32
    int fill_0x24[13]; //0x24
    struct
    {
        void* Data_0; //0
        //???
    }* Data_0x58; //0x58
    //
} Struct_2345d480;


struct
{
    int Data_0; //0
    int Data_4; //4
    int Data_8; //8
    int Data_0xc; //12 = 0xc
    int fill_0x10; //16 = 0x10
    void (*Data_0x14)(); //0x14
    int Data_0x18; //0x18
    int (*Data_0x1c)(); //0x1c
    int fill_0x20; //0x20
    uint32_t Data_0x24; //0x24
    int Data_0x28; //0x28
    int Data_0x2c; //0x2c
    int fill_0x30; //0x30
    struct Struct_23876c24_Inner_0x24
    {
        int Data_0; //0 = 0x34
        int Data_4; //4 = 0x38
        int fill_8[3]; //8 = 0x3c
        int Data_0x14; //0x14 = 0x48
        void* Data_0x18; //0x18 = 0x4c
        uint8_t Data_0x1c[1024]; //0x1c = 0x50
        //0x41c
    } Data_0x34; //0x34 = 23876c58 -> 23877074 /  / 2394817c
    int Data_0x450; //0x450 = 23877074
    uint8_t Data_23877078[300]; //23877078 /  / 2394859c
    uint8_t Data_238771a4[100]; //0x580 238771A4
    //???
} Data_23876c24; //23876c24 /  / 23948148


uint8_t Data_23877208[108]; //23877208, size??? /  / 2394872c
int Data_23877274[0x400]; //23877274, size??? /  / 23948798


int sub_2345d480(int, Struct_2345d480*);


/* 2345c45c - todo */
void sub_2345c45c()
{
#if 1
	console_send_string("sub_2345c45c (todo.c): TODO\r\n");
#endif

}


/* 2345c5c0 /  / 2347abbc - complete */
int sub_2345c5c0(uint8_t* url, uint8_t* r7, void* pCallback)
{
#if 0
	console_send_string("sub_2345c5c0 (todo.c): TODO\r\n");
#endif

    int res = 0;

    int port;
    int ip_addr;
    int sp_0x38 = 0;
    uint8_t sp_0x10[40]; 

    if (0 == network_is_link_up())
    {
        return 0;
    }

    if (0 == sub_2347718c(url, &ip_addr, &port, &sp_0x38))
    {
        int8_t r4 = 40;
        uint8_t* r5 = url + 7;
        uint8_t* r6 = &sp_0x10[0];
        uint8_t* sb = r7;

        memset(&sp_0x10[0], 0, r4);

        while (r4--)
        {
            if ((*r5 == 0) || (*r5 == '/') || (*r5 == ':'))
            {
                break;
            }

            *r6++ = *r5++;
        }

        if (r4 > 0)
        {
            sb = &sp_0x10[0];
        }

        if (sp_0x38 != 0)
        {
            snprintf(&Data_23877274[0], 0x3ff, 
                "GET /%s HTTP/1.1\r\nHost: %s\r\nIcy-MetaData: 1\r\nConnection: close\r\n\r\n",
                sp_0x38, sb);
        }
        else
        {
            snprintf(&Data_23877274[0], 0x3ff, 
                "GET / HTTP/1.1\r\nHost: %s\r\nIcy-MetaData: 1\r\nConnection: close\r\n\r\n",
                sb);
        }

        snprintf(r7, 16, "%d.%d.%d.%d",
            ip_addr & 0xff,
            (ip_addr >> 8) & 0xff,
            (ip_addr >> 16) & 0xff,
            (ip_addr >> 24) & 0xff);

        res = web_client_send_request(r7, (uint16_t)port, &Data_23877274[0], pCallback);
    }

    return res;
}


/* 2345c730 /  / 2347ad2c - todo */
void sub_2345c730()
{
#if 1
	console_send_string("sub_2345c730 (todo.c): TODO\r\n");
#endif

}


/* 2345c8d4 - todo */
void sub_2345c8d4()
{
#if 1
	console_send_string("sub_2345c8d4 (todo.c): TODO\r\n");
#endif

}


/* 2345ca5c - todo */
void sub_2345ca5c()
{
#if 1
	console_send_string("sub_2345ca5c (todo.c): TODO\r\n");
#endif

}


/* 2345cae0 - todo */
void sub_2345cae0()
{
#if 1
	console_send_string("sub_2345cae0 (todo.c): TODO\r\n");
#endif

}


/* 2345cc88 /   / 2347b284 - todo */
void sub_2345cc88()
{
#if 1
	console_send_string("sub_2345cc88 (todo.c): TODO\r\n");
#endif

}


/* 2345ce1c /  / 2347b418 - todo */
void sub_2345ce1c()
{
#if 1
	console_send_string("sub_2345ce1c (todo.c): TODO\r\n");
#endif

}


/* 2345ce38 /  / 2347b434 - todo */
void sub_2345ce38(int sb, int sp_0xc)
{
#if 0
	console_send_string("sub_2345ce38 (todo.c): TODO\r\n");
#endif

    uint8_t err; //sp4

    //r7, =dword_234940a4
    int r8 = sub_23419448() + 0x10000;
    //r6, =0x23876c24

    if (sb == 0)
    {
        //0x2345ce68
        OSSemPend(Data_234940a4, 0, &err);

        if (sp_0xc == -1)
        {
            Data_23876c24.Data_0x14 = sub_2345ce1c;
            //->loc_2345cf14
            Data_23876c24.Data_4 = (Data_23876c24.Data_4 + 1) & 0xfffff;
        }
        else
        {
            //0x2345ce7c
            //r5 = 0;
            Data_23876c24.Data_0 = 0;

            if (Data_23876c24.Data_0x34.Data_0x14 != 0)
            {
                Data_23876c24.Data_0x24 = 0x0f; //r8

                Data_23876c24.Data_23877078[0] = 0;

                Data_23876c24.Data_0x14 = sub_2345d480;
                //->loc_2345cf2c
            }
            else
            {
                //0x2345cea4
                int r4 = Data_23876c24.Data_4;

                uint8_t* r0 = sub_23419448();
                r0 += 0x10000;

                if (r4 != 0)
                {
                    //0x2345ceb8
                    //int r2 = 0x12b;
                    Data_23876c24.Data_0x24 = 0;
                    //->loc_2345cee8
                    while (r4--)
                    {
                        //loc_2345cec4
                        if (Data_23876c24.Data_0x24 < /*r2*/299)
                        {
                            //0x2345ced0
                            Data_23876c24.Data_23877078[Data_23876c24.Data_0x24] = *r0++;

                            Data_23876c24.Data_0x24++;
                        }
                        //loc_2345cee8
                    } //while (r4--)
                    //0x2345cef0 -> loc_2345cf04
                }
                else
                {
                    //loc_2345cef4
                    sprintf(&Data_23876c24.Data_23877078[0], " RST by Server ");

                    Data_23876c24.Data_0x24 = 0x0f; //r8
                }
                //loc_2345cf04
                Data_23876c24.Data_23877078[Data_23876c24.Data_0x24] = 0; //r5
                //loc_2345cf14
                Data_23876c24.Data_0x14 = sub_2345cc88;

                Data_23876c24.Data_4 = (Data_23876c24.Data_4 + 1) & 0xfffff;
            }
        }
        //loc_2345cf2c
        OSSemPost(Data_234940a4);        
    }
    else
    {
        //loc_2345cf38
        OSSemPend(Data_234940a4, 0, &err);

        if (err != 0)
        {
            return;
        }

        if (Data_23876c24.Data_0x1c != NULL)
        {
            sb = (Data_23876c24.Data_0x1c)(&sp_0xc, sb);
        }
        //loc_2345cf64
        int r4 = Data_23876c24.Data_4 - Data_23876c24.Data_8;
        if (r4 < 0)
        {
            r4 += 0x100000;
        }
        while ((sp_0xc + r4) >= 0x100000U)
        {
            //loc_2345cf74
            OSSemPost(Data_234940a4);
            rtos_task_wait(5);
            OSSemPend(Data_234940a4, 0, &err);
            //->loc_2345cf64
            r4 = Data_23876c24.Data_4 - Data_23876c24.Data_8;
            if (r4 < 0)
            {
                r4 += 0x100000;
            }
        }
        //0x2345cfa8
        if (Data_23876c24.Data_0x1c == NULL)
        {
            //0x2345cfb4
            int r0 = Data_23876c24.Data_4;
            int r5 = sp_0xc;
            uint32_t r1 = r8 + 0x100000;
            r0 = r0 + r8;
            uint32_t r2 = r0 + r5;
            int sl = 0;
            if (r2 > r1)
            {
                r2 = r5;
                r5 = r1 - r0;                
                sl = r2 - r5;
            }
            memcpy(r0, sb, r5);

            if (sl != 0)
            {
                memcpy(r8, sb + r5, sl);
            }

            Data_23876c24.Data_4 = (Data_23876c24.Data_4 + sp_0xc) & 0xfffff;
        }
        //loc_2345d014
        OSSemPost(Data_234940a4);

        if (r4 > 0x20000)
        {
            rtos_task_wait(1);
        }
    }
}


/* 2345d090 /  / 2347b68c - todo */
void* sub_2345d090(Struct_235b0b08* r4)
{
#if 0
	console_send_string("sub_2345d090 (todo.c): TODO\r\n");
#endif

    //sb = 0;
    if ((r4->Data_0 & 0xffff) != 0)
    {
        //0x2345d0b0
        uint8_t sp_0x48[20] = "255.255.255.255";
        int port; //sp_0x44;
        int sp_0x40;
        uint8_t* sp_0x3c = 0;
        Struct_23459098_Inner0* r5 = r4->Data_0x58.Data_0;
        Struct_2340ce18 sp_0x34;

        sub_2340ce18(&sp_0x34);

        sub_2341e524(tsd_get_bm_handle(sp_0x34.Data_4), 0, 1);

        Data_23876c24.Data_0x2c = 0;
        Data_23876c24.Data_4 = 0;
        Data_23876c24.Data_8 = 0;
        Data_23876c24.Data_0x14 = sub_2345c45c;
        Data_23876c24.Data_0xc = 0;
        Data_23876c24.Data_0x18 = 0;

        memset(&Data_23876c24.Data_238771a4[0], 0, 100);
        memset(&Data_23876c24.Data_23877078[0], 0, 300);
        memset(&Data_23877208[0], 0, 20);

        if (r5->Data_0 == NULL)
        {
            r5->Data_0 = &Data_23876c24.Data_0x34.Data_0x1c[0];

            sub_23419a64(r5->wData_4, r5->Data_0, 0x3ff);
        }

//        int r6 = 2;
        if (0 == network_is_link_up())
        {
            //loc_2345d170
            r4->Data_0 = 2; //r6
            //->loc_2345d2d8
            rtos_task_wait(5);

            return sub_2345d090;
        }
        if (0 != sub_2347718c(r5->Data_0, &sp_0x40, &port, &sp_0x3c))
        {
            //loc_2345d170
            r4->Data_0 = 2; //r6
            //->loc_2345d2d8
            rtos_task_wait(5);

            return sub_2345d090;
        }
        //loc_2345d178
        if (0 == strncmp("udp://", r5->Data_0, 6))
        {
            //0x2345d190
            int sp8;

            r4->Data_0 = -1;
            r4->Data_0x28 = NULL; //sb
            r4->Data_0x34 = sub_2345c730;

            sp8 = 1;

            if ((sp_0x3c[0] & 0xf0) == 0x30)
            {
                sscanf(sp_0x3c, "%d", &sp8);
            }

            Data_23876c24.Data_0 = 0; //sb

            sub_2345afdc(sp_0x40, (uint16_t)sp8, (uint16_t)port);
            //->loc_2345d350
        } //if (0 == strncmp("udp://", r5->Data_0, 6))
        else
        {
            //loc_2345d1e8
            uint8_t sp_0xc[40]; //size???
            uint8_t* r7 = r5->Data_0 + 7;
            int16_t r6 = 40;
            uint8_t* r8 = &sp_0xc[0];
            uint8_t* fp = &sp_0x48[0];

            memset(&sp_0xc[0], 0, r6);

            while (r6--)
            {
                //loc_2345d20c
                if ((r7[0] == 0) ||
                    (r7[0] == '/') ||
                    (r7[0] == ':'))
                {
                    //->loc_2345d238
                    break;
                }
                //0x2345d220
                *r8++ = *r7++;
            } //while (r6--)
            //loc_2345d238
            if (r6 > 0)
            {
                fp = &sp_0xc[0];
            }

            snprintf(&sp_0x48[0], 16, "%d.%d.%d.%d",
                sp_0x40 & 0xff,
                (sp_0x40 >> 8) & 0xff,
                (sp_0x40 >> 16) & 0xff,
                (sp_0x40 >> 24) & 0xff);

            if (sp_0x3c != 0)
            {
                snprintf(&Data_23877274[0], 0x3ff, 
                    "GET /%s HTTP/1.1\r\nHost: %s\r\nIcy-MetaData: 1\r\nConnection: close\r\n\r\n",
                    sp_0x3c, fp);    
            }
            else
            {
                snprintf(&Data_23877274[0], 0x3ff, 
                    "GET / HTTP/1.1\r\nHost: %s\r\nIcy-MetaData: 1\r\nConnection: close\r\n\r\n",
                    fp);
            }

            Data_23876c24.Data_0 = web_client_send_request(&sp_0x48, 
                (uint16_t)port, &Data_23877274[0], sub_2345ce38);

            if (&Data_23877274[0] == r5->Data_0)
            {
                r5->Data_0 = Data_234940a8;
            }

            if (Data_23876c24.Data_0 == 0)
            {
                //loc_2345d2d8
                rtos_task_wait(5);

                return sub_2345d090;
            }
            //loc_2345d2ec
            r4->Data_0 = -1;
            r4->Data_0x28 = sub_2345cae0;
            r4->Data_0x24 = sub_2345ca5c;
            r4->Data_0x30 = sub_2345c8d4;
            r4->Data_0x34 = sub_2345c730;
            r4->Data_0x50 = 0xff;
            r4->bData_0x54 = 0; //sb
            r4->Data_0x48 = 0x2f00;
            r4->Data_0x4c = 0; //sb
        }
        //->loc_2345d350
    } //if ((r4->Data_0 & 0xffff) != 0)
    else
    {
        //loc_2345d330
        if (r4->Data_0x34 != NULL)
        {
            r4->Data_0x34 = (r4->Data_0x34)(r4);
        }
        //loc_2345d348
        r4->Data_0x28 = NULL;
        r4->Data_0 = 0;
    }

    return NULL;
}


/* 2345d37c /  / 2347b978 - todo */
void sub_2345d37c()
{
#if 1
	console_send_string("sub_2345d37c (todo.c): TODO\r\n");
#endif

}


/* 2345d3c8 /  / 2347b9c4 - todo */
void sub_2345d3c8()
{
#if 1
	console_send_string("sub_2345d3c8 (todo.c): TODO\r\n");
#endif

}


/* 2345d480 /  / 2347ba7c - todo */
int sub_2345d480(int a, Struct_2345d480* r6)
{
#if 0
	console_send_string("sub_2345d480 (todo.c): TODO\r\n");
#endif

    char sp[20] = "255.255.255.255";

    int r0 = Data_23876c24.Data_4 - Data_23876c24.Data_8;
    if (r0 < 0)
    {
        r0 += 0x100000;
    }

    if (r0 <= 75200)
    {
        //r7 = 0;
        if (Data_23876c24.Data_0x34.Data_4 != 0)
        {
            Data_23876c24.Data_0x34.Data_4--;
            //->loc_2345d518
        }
        else
        {
            Data_23876c24.Data_0x34.Data_4 = 2;
            Data_23876c24.Data_0x34.Data_0 = 0; //r7

            Data_23876c24.Data_0 = sub_2345c5c0(&Data_23876c24.Data_0x34.Data_0x1c[0], 
                &sp[0], sub_2345d3c8);

            int r4 = 10;
            while (r4--)
            {
                //loc_2345d4f4
                if (Data_23876c24.Data_0 == 0)
                {
                    //->loc_2345d510
                    break;              
                }

                rtos_task_wait(1);
            }
            //loc_2345d510
            sub_23477120(Data_23876c24.Data_0);
        }
        //loc_2345d518
        Data_23876c24.Data_0x14 = 0;

        Data_23876c24.Data_0x34.Data_0x14++;
        Data_23876c24.Data_0x34.Data_0x18 = &Data_23877274[0];

        if (0 != sub_2345c13c(Data_23876c24.Data_0x450, 0x400, &Data_23876c24.Data_0x34))
        {
            Data_23876c24.Data_0x1c = sub_2345d37c;

            Data_23876c24.Data_0 = sub_2345c5c0(Data_23876c24.Data_0x34.Data_0x18,
                &sp[0], sub_2345ce38);
        }
        else
        {
            //loc_2345d568
            Data_23876c24.Data_0x34.Data_0x14 = 0; //r7

            r6->Data_0x20 = sub_2345d090;
            r6->Data_0x58->Data_0 = &Data_23876c24.Data_0x34.Data_0x1c[0];/*23876c74*/

            sub_2345c730(r6);
        }
    }
    //loc_2345d588
    return 1;
}


/* 2345d594 /  / 2347bb90 - complete */
void sub_2345d594(void* a)
{
#if 0
	console_send_string("sub_2345d594 (todo.c): TODO\r\n");
#endif

    if (Data_234940a4 == NULL)
    {
        Data_234940a4 = OSSemCreate(1);
    }

    memset(&Data_23876c24.Data_0x34, 0, sizeof(struct Struct_23876c24_Inner_0x24));
}


/* 2345d5c4 /  / 2347bbc0 - complete */
int sub_2345d5c4(uint8_t* r4, int len)
{
#if 0
	console_send_string("sub_2345d5c4 (todo.c): TODO\r\n");
#endif

    if (0 != OSSemAccept(Data_234940a4))
    {
        if ((Data_23876c24.Data_0 != 0) &&
            (Data_23876c24.Data_0x28 != 0))
        {
            uint8_t* p = &Data_23876c24.Data_23877078[0];
            while (len--)
            {
                if ((*p == ';') || (*p == 0))
                {
                    break;
                }

                *r4++ = *p++;
            }

            *r4 = 0;
            
            OSSemPost(Data_234940a4);

            return 1;
        }

        OSSemPost(Data_234940a4);
    }

    return 0;
}


/* 2345d64c /  / 2347bc48 - complete */
int sub_2345d64c(uint8_t* r4, int len)
{
#if 0
	console_send_string("sub_2345d5c4 (todo.c): TODO\r\n");
#endif

    if (0 != OSSemAccept(Data_234940a4))
    {
        if ((Data_23876c24.Data_0 != 0) &&
            (Data_23876c24.Data_0x28 != 0))
        {
            uint8_t* p = &Data_23877208[0];
            while (len--)
            {
                if (*p == 0)
                {
                    *r4++ = ' ';
                    break;
                }

                *r4++ = *p++;
            }
            
            p = &Data_23876c24.Data_23877078[0];
            while (len--)
            {
                if ((*p == ';') || (*p == 0))
                {
                    break;
                }

                *r4++ = *p++;
            }

            if (len != 0)
            {
                *r4 = 0;
            }
            
            OSSemPost(Data_234940a4);

            return 1;
        }

        OSSemPost(Data_234940a4);
    }

    return 0;
}


/* 2345d710 /  / 2347bd0c - todo */
int sub_2345d710(int a)
{
#if 0
	console_send_string("sub_2345d710 (todo.c): TODO\r\n");
#endif

    Struct_23459098 sp;

	Data_234940ac.Data_0 = 0;
	Data_234940ac.wData_4 = a;

	sp.Data_0 = &Data_234940ac;
	sub_23459098(&sp);

	return 0;
}


/* 2345d738 /  / 2347bd34 - todo */
int sub_2345d738(int a)
{
#if 0
	console_send_string("sub_2345d738 (todo.c): TODO\r\n");
#endif

    Struct_23459098 sp;

    Data_234940b4.Data_0 = a;
    Data_234940b4.wData_4 = -1;

    sp.Data_0 = &Data_234940b4;

    sub_23459098(&sp);

    return 0;
}


