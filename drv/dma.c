
#include <stdint.h>
#include "ucos_ii.h"


typedef struct
{
    int Data_0; //0

} Struct_234928d8;


typedef struct 
{
    uint32_t Data_0; //0
    uint8_t bData_4; //4
    int Data_8; //8
    void* Data_0xc; //0xc = 12
    int Data_0x10; //0x10 = 16
    int Data_0x14; //0x14 = 20
    int Data_0x18; //0x18 = 24
    void* Data_0x1c; //0x1c = 28
    int Data_0x20; //0x20 = 32
    int Data_0x24; //0x24 = 36
    void* Data_0x28; //0x28 = 40
    //0x2c
} Struct_234927c0;

static Struct_234927c0 Data_234927d0[];
static Struct_234928d8 Data_234928d8;

//234927b4
int Data_234927b4 = 0; //234927b4 +0
int Data_234927b8 = 0; //234927b8 +4
Struct_234928d8* Data_234927bc = &Data_234928d8; //234927bc +8
Struct_234927c0* Data_234927c0 = &Data_234927d0[0]; //234927c0 +0xc
int Data_234927c4; //234927c4 +0x10
int Data_234927c8 = 0; //234927c8 +0x14

Struct_234927c0 Data_234927d0[] = //234927d0 +0x1c
{
    {0xc7000100}, //234927d0 //DMA_CH_CONFIG
    {0xc7000140}, //234927fc
    {0xc7000180}, //23492828
    {0xc70001c0}, //23492854
    {0xc7000200}, //23492880
    {0xc7000240}, //234928ac
}; //->234928d8

Struct_234928d8 Data_234928d8 = //234928d8
{
    20, //Endian Swap Write

};


/* 234365c8 - todo */
void sub_234365c8()
{
#if 1
	console_send_string("sub_234365c8 (todo.c): TODO\r\n");
#endif

}


/* 23436900 - todo */
int sub_23436900(uint8_t* r6, int r7, int sb, void* r8, int fp)
{
    uint8_t sp_0x10;

#if 0
	console_send_string("sub_23436900 (todo.c): TODO\r\n");
#endif

    Struct_234927c0* r4 = Data_234927c0;
    volatile int* r5 = (void*) r4->Data_0;

    OSSemPend(r4->Data_0x28, 0, &sp_0x10);

    sys_invalidate_data_cache(r7, sb);

    r4->Data_0x1c = r8;
    r4->Data_0xc = r6;
    r4->Data_0x10 = sb;
    r4->Data_8 = r7;
    r4->Data_0x20 = 0; //r8
    r4->Data_0x18 = (fp << Data_234927bc->Data_0) | (1 << 2)/*Enable*/;
    r4->bData_4 = 0; //r8
    r4->Data_0x14 = 0;
    r4->Data_0x24 = 0;
    r5[0] = 0; 

    int sp[] = //23489cb0
    {
        0x02000100, 0x02000200, 0x02000300, 0x02000400
    };

    int* r1 = &sp[0];
    
    int lr = sb - 0x1FFFFF;
    int sl = 0x1FFFFF; //0 - fp;

    if (lr < 0)
    {
        r5[1] = sb;
        r5[2] = 0; 
    }
    else
    {
        r5[1] = sl;
        r5[2] = sp[0];
        r4->Data_0x18 |= (1 << 3); //Linked List Enable
    }

    r5[3] = r7;
    r5[4] = 0x3ff;
    r5[5] = 0xfff; //ip
    r5[6] = 0;
    r5[7] = (int) r6;
    r5[8] = 0x3ff;
    r5[9] = 0xfff;
    r5[10] = 0;
    //->loc_23436a50
    while (lr > 0)
    {
        //loc_234369ec
        volatile int* r0 = (void*) r1[0];
        int r2 = lr - 0x1FFFFF/*fp*/;

        r7 += 0x1ffffc;
        r6 += 0x1ffffc;
        r0[0] = r4->Data_0x18;

        if (r2 < 0)
        {
            r0[1] = lr;
            lr = sp[0];
        } 
        else
        {
            r0[1] = sl;
            lr = r1[1];
        }   

        r0[2] = lr;
        r0[3] = r7;
        r0[4] = 0x3ff;
        r0[5] = 0xfff;
        r0[6] = 0; //r8
        r0[7] = (int) r6;
        r0[8] = 0x3ff;
        r0[9] = 0xfff;
        r0[10] = 0;

        r4->Data_0x14++;
        r1++;
        lr = r2;
    }
    //0x23436a58
    r5[0] = r4->Data_0x18;

    return 0;
}


/* 23436bc0 - todo */
int dma_init(void)
{
#if 0
	console_send_string("dma_init (todo.c): TODO\r\n");
#endif

    Data_234927c0->Data_0x28 = OSSemCreate(1);
    ((volatile uint32_t*)0xc7000004)[0] = Data_234927b4 = 0; //DMA_INT_MASK
    ((volatile uint32_t*)0xc700000c)[0] = Data_234927b8 = 0x3ff; //DMA_INT_CLEAR

    intr_set_isr(sub_234365c8, 0, 20);
    sub_2341b3b8(20, 0);

    ((volatile uint32_t*)0xe0000250)[0] = 0x0f;

    return 0;
}




