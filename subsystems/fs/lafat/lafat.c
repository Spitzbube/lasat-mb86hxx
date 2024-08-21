
#include <string.h>
#include "data.h"
#include "usb_msd.h"
#include "lafat.h"


uint8_t Data_23493630[0x1000] =  //23493630, size???
{
    1, 2, 3, 4, 5, 6, 7 //TODO!!!
};

struct 
{
    void* sema; //0x2377e084 /  / 0x2361f448
    struct
    {
        int fill_0; //0
        char Data_4[36]; //4
        uint32_t Data_0x28; //0x28
        int fill_0x2c[5]; //0x2c
        uint32_t Data_0x40; //0x40
        uint32_t Data_0x44; //0x44
        uint32_t Data_0x48; //0x48
        int fill_0x4c[2]; //0x4c
        int Data_0x54; //0x54
        int fill_0x58[6]; //0x58
        //0x70
    } Data_4; //4    
    uint8_t* Data_0x74; //0x74
    int Data_0x78; //0x78
    int Data_0x7c; //0x7c
    int fill_0x80; //0x80
    void* Data_0x84; //0x84
    int Data_0x88; //0x88
    int (*read)(void* h, uint32_t dwStartBlockLo, void* pBuffer, uint16_t wBlockCount); //0x8c
    int (*write)(void* h, uint32_t dwStartBlockLo, void* pBuffer, uint16_t wBlockCount); //0x90
    int Data_0x94; //0x94
    int Data_0x98; //0x98
    int Data_0x9c; //0x9c
    void* pDev; //0xa0 = 2377E124
    int fill_0xa4[128]; //0xa4
    int Data_0x2a4; //0x2a4
    //???
} Data_2377e084; //2377e084???

struct 
{
    int fill_0[0x4000]; //0, size???
    //0x10000???
} Data_237aec10; //0x237aec10



int lafat_lock(void);
void lafat_unlock(void);


/* 23455eac /  / 2341f624 - complete */
int lafat_disable(int a)
{
#if 0
	console_send_string("lafat_disable (todo.c): TODO\r\n");
#endif

    lafat_lock();

    memset(&Data_2377e084.Data_4, 0, sizeof(Data_2377e084.Data_4));

    Data_2377e084.pDev = 0;
    Data_2377e084.read = 0;
    Data_2377e084.write = 0;
    Data_2377e084.Data_0x94 = 0;
    Data_2377e084.Data_0x98 = 0;

    lafat_unlock();

    return 0;
}


/* 23455ee8 /   / 2341f660 - todo */
int sub_23455ee8(int a)
{
#if 0
	console_send_string("sub_23455ee8 (lafat.c): TODO\r\n");
#endif

    int sp;
    int r6 = 0;

    Data_2377e084.Data_0x88 = 0; //r6

    if (0 != (Data_2377e084.read)(Data_2377e084.pDev, 0, Data_2377e084.Data_0x84, 1))
    {
        return 3;
    }
    //0x23455f18
    uint8_t* r2 = Data_2377e084.Data_0x84;
    if (((r2[0x1ff] << 8) + r2[0x1fe]) != 0xaa55)
    {
        return 3;
    }

    uint8_t r0;
    for (r0 = 0; r0 < 4; r0++)
    {
        //loc_23455f38
        if (r2[0x1c2 + r0 * 16] == 0xbb)
        {
            //->loc_23455f68
            break;
        }
    }

    if (r2[0x1c2 + r0 * 16] != 0xbb)
    {
        //loc_23456084
        return 3;
    }
    //loc_23455f68
    uint8_t* r0_ = &r2[r0 * 16];
    Data_2377e084.Data_0x88 = (r0_[0x1c9] << 24) + 
        (r0_[0x1c8] << 16) + (r0_[0x1c7] << 8) + (r0_[0x1c6] << 0);
    
    (Data_2377e084.read)(Data_2377e084.pDev, 
        Data_2377e084.Data_0x88, r2/*Data_2377e084.Data_0x84*/, 1);

    memcpy(&Data_2377e084.Data_4, Data_2377e084.Data_0x84, 0x70);

    uint32_t r1 = Data_2377e084.Data_4.Data_0x48 * Data_2377e084.Data_4.Data_0x28;
    if (r1 > 0x10000)
    {
        return 7;
    }
    //0x23455fc8
    if (Data_2377e084.Data_0x74 == 0)
    {
        Data_2377e084.Data_0x74 = &Data_237aec10;
    }
    else
    {
        memset(Data_2377e084.Data_0x74, 0, r1);
    }
    //loc_23455fe0
    (Data_2377e084.read)(Data_2377e084.pDev, 
        Data_2377e084.Data_4.Data_0x40, 
        Data_2377e084.Data_0x74, Data_2377e084.Data_4.Data_0x48);

    int r4 = 0;
    uint8_t* r3 = Data_2377e084.Data_0x74;
    uint32_t lr = Data_2377e084.Data_4.Data_0x44;
    if (r3 != 0)
    {
        //0x23456014
        for (uint32_t r2 = 0; r2 < lr; r2++)
        {
            uint8_t r1 = r3[r2];
            r4 += (Data_23493630[r1 & 0x0f] + Data_23493630[r1 << 4]);
        }
        //loc_23456054
    }
    else
    {
        r4 = r6;
        //->loc_23456054
    }
    //loc_23456054
    Data_2377e084.Data_4.Data_0x54 = r4;

    Data_2377e084.Data_0x7c = sub_23454f54(
        /*r3*/Data_2377e084.Data_0x74, 
        /*lr*/Data_2377e084.Data_4.Data_0x44, 
        &sp);
    Data_2377e084.Data_0x78 = Data_2377e084.Data_4.Data_0x44;

    if (0 != strcmp("LaSAT VideoFS V.201", Data_2377e084.Data_4.Data_4))
    {
        return 3;
    }
    //loc_2345608c
    sub_23457ab8(0);

    return 0;
}


/* 2345609c /  / 2341f814 - complete */
int lafat_add_usb_device(USB_MSD_Interface a)
{
#if 0
	console_send_string("lafat_add_usb_device (todo.c): TODO\r\n");
#endif

    Data_2377e084.read = a.read;
    Data_2377e084.write = a.write;
    Data_2377e084.Data_0x94 = a.Data_8;
    Data_2377e084.Data_0x98 = a.Data_12;
    Data_2377e084.Data_0x9c = a.Data_16;
    Data_2377e084.Data_0x84 = &Data_2377e084.Data_0x2a4;
    Data_2377e084.Data_0x74 = 0;

    if (Data_2377e084.sema == 0)
    {
        Data_2377e084.sema = OSSemCreate(1);
    }

    Data_2377e084.pDev = a.pDevice;

    return 0;
}


/* 234579c8 /  / 23421140 - todo */
void* lafat_get_semaphore(void)
{
#if 0
	console_send_string("lafat_get_semaphore (todo.c): TODO\r\n");
#endif

    return Data_2377e084.sema;
}


/* 234579d4 /  / 2342114c - todo */
int lafat_lock(void)
{
    uint8_t err;

    OSSemPend(Data_2377e084.sema, 0, &err);

    return err;
}


/* 234579f4 /  / 2342116c - todo */
void lafat_unlock(void)
{
    OSSemPost(Data_2377e084.sema);
}


