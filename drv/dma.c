
#include <stdint.h>
#include "ucos_ii.h"

typedef struct 
{
    uint32_t Data_0; //0
    int fill_4[9]; //4
    void* Data_0x28; //0x28 = 40
    //0x2c
} Struct_234927c0;

static Struct_234927c0 Data_234927d0[];

//234927b4
int Data_234927b4 = 0; //234927b4 +0
int Data_234927b8 = 0; //234927b8 +4
int fill_234927bc = 0; //234927bc +8
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


/* 234365c8 - todo */
void sub_234365c8()
{
#if 1
	console_send_string("sub_234365c8 (todo.c): TODO\r\n");
#endif

}


/* 23436900 - todo */
int sub_23436900()
{
#if 1
	console_send_string("sub_23436900 (todo.c): TODO\r\n");
#endif

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




