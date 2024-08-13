
#include <stdint.h>
#include "ucos_ii.h"
#include "dma.h"

#define TRANSFER_LENGTH_MAX 0x1FFFFF

typedef struct
{
    int Data_0; //0

} Struct_234928d8;


typedef struct 
{
    uint32_t Data_0; //0
    uint8_t bData_4; //4
    uint32_t readAddr; //8
    uint32_t writeAddr; //0xc = 12
    int totalLength; //0x10 = 16
    int numLinkedTransfers; //0x14 = 20
    int Data_0x18; //0x18 = 24
    void (*Data_0x1c)(uint32_t, uint32_t); //0x1c = 28
    void (*Data_0x20)(int); //0x20 = 32
    int Data_0x24; //0x24 = 36
    void* sema; //0x28 = 40
    //0x2c
} DMA_Channel;

static DMA_Channel dma_arChannels[];
static Struct_234928d8 Data_234928d8;

//234927b4
int Data_234927b4 = 0; //234927b4 +0
int Data_234927b8 = 0; //234927b8 +4
Struct_234928d8* Data_234927bc = &Data_234928d8; //234927bc +8
DMA_Channel* Data_234927c0 = &dma_arChannels[0]; //234927c0 +0xc
int Data_234927c4; //234927c4 +0x10
int Data_234927c8 = 0; //234927c8 +0x14

DMA_Channel dma_arChannels[] = //234927d0 +0x1c
{
    {0xc7000100}, //234927d0
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
int dma_isr(void)
{
#if 1
	console_send_string("dma_isr (todo.c): TODO\r\n");
#endif

    uint32_t channel = 6;
    uint32_t int_status = ((volatile uint32_t*)0xc7000008)[0];
    uint32_t channelComplete = int_status & 0x3f;
    if (channelComplete != 0)
    {
        DMA_Channel* pChannel = Data_234927c0;

        while (channel--)
        {
            if (channelComplete & 1)
            {
                volatile uint32_t* r1 = (void*) pChannel->Data_0;
                if (pChannel->numLinkedTransfers != 0)
                {
                    pChannel->numLinkedTransfers--;
                }
                else
                {
                    r1[0] = 0;

                    if ((pChannel->bData_4 != 0) && (pChannel->writeAddr != 0))
                    {
                        sys_invalidate_data_cache(pChannel->writeAddr, pChannel->totalLength);
                    }

                    if (pChannel->Data_0x1c != 0)
                    {
                        (pChannel->Data_0x1c)(int_status, pChannel->Data_0x24);
                    }

                    if (pChannel->Data_0x20 != 0)
                    {
                        (pChannel->Data_0x20)(0);
                    }

                    if (pChannel->sema != 0)
                    {
                        OSSemPost(pChannel->sema);
                    }
                }
            }

            channelComplete >>= 1;
            pChannel++;

        } //while (channel--)
    }

    ((volatile uint32_t*)0xc700000c)[0] = int_status; //DMA_INT_CLEAR

    return 0;
}


/* 23436900 - todo */
int sub_23436900(uint32_t writeAddr/*r6*/, uint32_t readAddr/*r7*/, 
                uint32_t length, void (*r8)(uint32_t, uint32_t), int fp)
{
    uint8_t err;

#if 0
	console_send_string("sub_23436900 (todo.c): TODO\r\n");
#endif

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "sub_23436900: writeAddr=%p, readAddr=%p, length=%d\r\n", 
            writeAddr, readAddr, length);
        console_send_string(debug_string);
    }
#endif

    DMA_Channel* pChannel = Data_234927c0;
    volatile uint32_t* r5 = (void*) pChannel->Data_0;

    OSSemPend(pChannel->sema, 0, &err);

    sys_invalidate_data_cache(readAddr, length);

#if 1
    pChannel->Data_0x1c = r8;
    pChannel->writeAddr = writeAddr;
    pChannel->totalLength = length;
    pChannel->readAddr = readAddr;
    pChannel->Data_0x20 = 0; //r8
    pChannel->Data_0x18 = (fp << Data_234927bc->Data_0) | (1 << 2)/*Enable*/;
    pChannel->bData_4 = 0; //r8
    pChannel->numLinkedTransfers = 0;
    pChannel->Data_0x24 = 0;
#else //Order: TODO!
    pChannel->writeAddr = writeAddr;
    pChannel->readAddr = readAddr;
    pChannel->totalLength = length;
    pChannel->Data_0x1c = r8;
    pChannel->Data_0x20 = 0; //r8
    pChannel->Data_0x18 = (fp << Data_234927bc->Data_0) | (1 << 2)/*Enable*/;
    pChannel->bData_4 = 0; //r8
    pChannel->numLinkedTransfers = 0;
    pChannel->Data_0x24 = 0;
#endif

    r5[0] = 0; 

    int sp[] = //23489cb0
    {
        0x02000100, 0x02000200, 0x02000300, 0x02000400
    };
    int* r1 = &sp[0];
    
    int transferLength = length - TRANSFER_LENGTH_MAX;

    if (transferLength < 0)
    {
        r5[1] = length; //DMA_CH_LENGTH
        r5[2] = 0; //DMA_CH_LLADDR
    }
    else
    {
        r5[1] = TRANSFER_LENGTH_MAX; //DMA_CH_LENGTH
        r5[2] = sp[0]; //DMA_CH_LLADDR
        pChannel->Data_0x18 |= (1 << 3); //Linked List Enable
    }

    r5[3] = readAddr; //DMA_CH_RDADDR
    r5[4] = 0x3ff; //DMA_CH_RDLINE
    r5[5] = 0xfff; //DMA_CH_RDINC
    r5[6] = 0; //DMA_CH_RDLPADDR
    r5[7] = writeAddr; //DMA_CH_WRADDR
    r5[8] = 0x3ff; //DMA_CH_WRLINE
    r5[9] = 0xfff; //DMA_CH_WRINC
    r5[10] = 0; //DMA_CH_WRLPADDR
    //->loc_23436a50
    while (transferLength > 0)
    {
        //loc_234369ec
        volatile int* r0 = (void*) r1[0];
        int r2 = transferLength - TRANSFER_LENGTH_MAX;

        readAddr += 0x1ffffc;
        writeAddr += 0x1ffffc;
        r0[0] = pChannel->Data_0x18;

        if (r2 < 0)
        {
            r0[1] = transferLength;
            r0[2] = sp[0]; //Link to beginning
        } 
        else
        {
            r0[1] = TRANSFER_LENGTH_MAX;
            r0[2] = r1[1]; //Link next
        }   

        r0[3] = readAddr;
        r0[4] = 0x3ff;
        r0[5] = 0xfff;
        r0[6] = 0; //r8
        r0[7] = writeAddr;
        r0[8] = 0x3ff;
        r0[9] = 0xfff;
        r0[10] = 0;

        pChannel->numLinkedTransfers++;
        r1++;
        transferLength = r2;
    }
    //0x23436a58
    r5[0] = pChannel->Data_0x18;

    return 0;
}


/* 23436bc0 - todo */
int dma_init(void)
{
#if 0
	console_send_string("dma_init (todo.c): TODO\r\n");
#endif

    Data_234927c0->sema = OSSemCreate(1);
    ((volatile uint32_t*)0xc7000004)[0] = Data_234927b4 = 0; //DMA_INT_MASK
    ((volatile uint32_t*)0xc700000c)[0] = Data_234927b8 = 0x3ff; //DMA_INT_CLEAR

    intr_set_isr(dma_isr, 0, 20);
    sub_2341b3b8(20, 0);

    ((volatile uint32_t*)0xe0000250)[0] = 0x0f;

    return 0;
}




