
#include "data.h"
#include "lwip/tcp.h"


uint16_t wData_2349c018 = 0x11c1;

typedef struct 
{
    void* Data_0; //0
    int* Data_4; //4

} Struct_23476eb8;


typedef struct
{
    struct tcp_pcb* Data_0; //0
    uint32_t Data_4; //4
    char* Data_8; //8
    void (*Data_0xc)(int, int); //12
    void* sema; //16
    //20
} Struct_238e0ae4;

Struct_238e0ae4 Data_238e0ae4[2]; //238e0ae4



/* 23476cc8 - todo */
static int sub_23476cc8(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
    Struct_238e0ae4* r4 = arg;
    struct pbuf* r5 = 0;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23476cc8: err=0x%x, p=%p\r\n", err, p);
		console_send_string(debug_string);
	}
#endif

    if ((err == 0) && (p != 0))
    {
#if 1
        {
            extern char debug_string[];
            sprintf(debug_string, "sub_23476cc8: p->tot_len=%d\r\n", p->tot_len);
            console_send_string(debug_string);
        }
#endif

        tcp_recved(tpcb, p->tot_len);

        r4->Data_4 = 0; //r5
        r5 = p;

        do 
        {
            //loc_23476cfc
            if (r4->Data_0xc != 0)
            {
                (r4->Data_0xc)(r5->payload, r5->len);
            }
            r5 = r5->next;
        }
        while (r5 != 0);

        pbuf_free(p);
    }
    //loc_23476d28
    else if ((err == 0) && (p == 0))
    {
        //0x23476d30
        tcp_recv(r4->Data_0, 0);
        tcp_err(r4->Data_0, 0);
        tcp_poll(r4->Data_0, 0, 0);
        tcp_sent(r4->Data_0, 0);

        if (r4->Data_0xc != 0)
        {
            (r4->Data_0xc)(0, 0);
        }

        if (0 != tcp_close(r4->Data_0))
        {
            tcp_abort(r4->Data_0);

            OS_ENTER_CRITICAL();

            r4->Data_0 = 0;

            OS_EXIT_CRITICAL();

            return -10;
        }
        //loc_23476da4
        OS_ENTER_CRITICAL();

        r4->Data_0 = 0;

        OS_EXIT_CRITICAL();
    }
    //loc_23476db0
    return 0;
}


/* 23476db8 - complete */
static void sub_23476db8(void *arg, err_t err)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
    Struct_238e0ae4* r4 = arg;

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23476db8: err=0x%x\r\n", err);
		console_send_string(debug_string);
	}
#endif

    if (r4->Data_0xc != 0)
    {
        (r4->Data_0xc)(0, 0);
    }

    OS_ENTER_CRITICAL();

    r4->Data_0 = 0;

    OS_EXIT_CRITICAL();
}


/* 23476de8 - todo */
static int sub_23476de8(void *arg, struct tcp_pcb *tpcb)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
    Struct_238e0ae4* r4 = arg;

#if 0
	console_send_string("sub_23476de8 (todo.c): TODO\r\n");
#endif

    r4->Data_4++;
    if (r4->Data_4 > 10)
    {
        tcp_abort(tpcb);

        if (r4->Data_0xc != 0)
        {
            (r4->Data_0xc)(0, -1);
        }

        OS_ENTER_CRITICAL();

        r4->Data_0 = 0;

        OS_EXIT_CRITICAL();

        return -10;
    }

    return 0;
}


/* 23476e3c - complete */
static int sub_23476e3c(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23476e3c: len=%d\r\n", len);
		console_send_string(debug_string);
	}
#endif

    Struct_238e0ae4* r0 = arg;

    r0->Data_4 = 0;

    return 0;
}


/* 23476e4c - complete */
static int sub_23476e4c(void *arg, struct tcp_pcb *tpcb, err_t err)
{
    Struct_238e0ae4* r4 = arg;

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23476e4c: err=0x%x\r\n", err);
		console_send_string(debug_string);
	}
#endif

    if (err != 0)
    {
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
        OS_CPU_SR  cpu_sr = 0u;
#endif

        tcp_close(r4->Data_0);

        OS_ENTER_CRITICAL();

        r4->Data_0 = 0;

        OS_EXIT_CRITICAL();
    }
    else
    {
        r4->Data_4 = 0;

        tcp_recv(tpcb, sub_23476cc8);
        tcp_sent(tpcb, sub_23476e3c);
        tcp_poll(tpcb, sub_23476de8, 10);

        OSSemPost(r4->sema);
    }

    return 0;
}


/* 23476eb8 - complete */
void sub_23476eb8(int a, int* b, Struct_23476eb8* c)
{
#if 0
	console_send_string("sub_23476eb8 (todo.c): TODO\r\n");
#endif

    void* sem = c->Data_0;

    if (sem != 0)
    {
        int* r2 = c->Data_4;
        *r2 = *b;
        OSSemPost(sem);
    }
}


/* 23476ed4 - todo */
void* sub_23476ed4(char* r6, int sl, char* r8, void (*sb)(int, int))
{
    Struct_238e0ae4* r4 = 0;
    void* fp;
    int sp_0xc;

#if 0
	console_send_string("sub_23476ed4 (todo.c): TODO\r\n");
#endif

    uint16_t r5 = 500;

    if (wData_2349c018++ == 0xffff)
    {
        wData_2349c018 = 0x11c1;
    }

    if (0 == strncmp("http://", r6, 7))
    {
        Struct_23476eb8 sp4;
        uint8_t err;

        sp4.Data_0 = fp = OSSemCreate(0);
        sp4.Data_4 = &sp_0xc;

        err = dns_gethostbyname(&r6[7], &sp_0xc, sub_23476eb8, &sp4);
        if (err != 0)
        {
            OSSemPend(fp, 0, &err);
        }

        OSSemDel(fp, 1, &err);
    }
    else
    {
        //loc_23476f84
        sp_0xc = ipaddr_addr(r6);
    }
    //loc_23476f90
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
    OS_ENTER_CRITICAL();

    for (uint16_t r1 = 0; r1 < 2; r1++)
    {
        //loc_23476f9c
        if (Data_238e0ae4[r1].Data_0 == 0)
        {
            r4 = &Data_238e0ae4[r1];
            r4->Data_0 = -1;
            //->loc_23476fcc
            break;
        }
    }
    //loc_23476fcc
    OS_EXIT_CRITICAL();

    if (r4 != 0)
    {
        //0x23476fd8
    	struct tcp_pcb *r6; //pcb;

        r6 = tcp_new();
        if (r6 != 0)
        {
            //0x23476fe8
            r4->Data_0 = r6;
            r4->Data_8 = r8;
            r4->Data_0xc = sb;
            //->loc_234770e0
            while (r5--)
            {
                //loc_23476ff4
                int res = tcp_bind(r6, IP_ADDR_ANY, wData_2349c018);
                if (res == 0)
                {
                    //0x2347700c
                    Struct_238e0ae4* r5_ = 0;

                    tcp_arg(r6, r4);
                    tcp_err(r6, sub_23476db8);

                    r4->sema = OSSemCreate(0);

                    tcp_connect(r6, &sp_0xc, sl, sub_23476e4c);

                    uint8_t sp8;
                    OSSemPend(r4->sema, 500, &sp8); 

                    if (sp8 == 0)
                    {
                        //0x23477064
#if 1
                        hex_dump("sub_23476ed4", r4->Data_8, strlen(r4->Data_8));
#endif
                        tcp_write(r6, r4->Data_8, strlen(r4->Data_8), 1);
                        tcp_output(r6);
                        //->loc_234770b4
                        r5_ = &Data_238e0ae4;
                    }
                    else
                    {
                        //loc_2347708c
                        if (r4->Data_0 != 0)
                        {
                            res = tcp_close(r4->Data_0);
                            if (res == 0)
                            {
                                //0x234770a4
                                OS_ENTER_CRITICAL();
                                r4->Data_0 = 0; //fp
                                OS_EXIT_CRITICAL();
                                //->loc_234770b8
                            }
                            else
                            {
                                //loc_234770b4
                                r5_ = &Data_238e0ae4;
                            }
                        }
                    }
                    //loc_234770b8
                    OSSemDel(r4->sema, 1, &sp8);

                    return r5_;
                }
                else
                {
                    //loc_234770d4
                    wData_2349c018++;
                    //loc_234770e0
                }
            } //while (r5--)
            //->loc_23477100
        }
        else
        {
            //->loc_234770f4
            OS_ENTER_CRITICAL();
            r4->Data_0 = 0; //fp
            OS_EXIT_CRITICAL();
            //loc_23477100
        }
    }
    //loc_23477100
    return r4;
}




