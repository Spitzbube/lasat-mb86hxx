
#include <string.h>
#include "data.h"
#include "usb_msd.h"
#include "lafat.h"


struct 
{
    void* sema; //0x2377e084 /  / 0x2361f448
    struct
    {
        int fill_0[28]; //0
        //0x70
    } Data_4; //4    
    int Data_0x74; //0x74
    int fill_0x78[3]; //0x78
    void* Data_0x84; //0x84
    int fill_0x88; //0x88
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
#if 1
	console_send_string("sub_23455ee8 (lafat.c): TODO\r\n");
#endif

    return 3;
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


