
#include "data.h"


static void* Data_234940a0 = 0; //234940a0 +0 /  / 234c05b0


struct 
{
    int Data_0; //0
    int Data_4; //4
    int Data_8; //8
    int Data_0xc; //12
    int Data_0x10; //16

} Data_23876bf0; //23876bf0 /  / 236f32f0


struct
{
    int Data_0; //0
    int Data_4; //4
    int Data_8; //8
    int Data_0xc; //12
    int Data_0x10; //16
    int Data_0x14; //20
    int Data_0x18; //24
    int Data_0x1c; //28

} Data_23876c04; //23876c04 /  / 236f3304



/* 2345c024 /  / 23426600 - complete */
void sub_2345c024(void)
{
#if 0
	console_send_string("sub_2345c024 (todo.c): TODO\r\n");
#endif

    OSSemPost(Data_234940a0);
}


/* 2345c030 /  / 2342660c - complete */
void sub_2345c030(int r5, int r6, int r7, int r4)
{
    void* r0;
    uint8_t err;

#if 0
	console_send_string("sub_2345c030 (todo.c): TODO\r\n");
#endif

    r0 = lafat_get_semaphore();
    OSSemPend(r0, 0, &err);

    Data_23876bf0.Data_0x10 = r4;

    sub_23436688/*2344645c*/(r5, r6, r7, &Data_23876bf0, &Data_23876c04, 
        sub_2345c024/*23426600*/);

    OSSemPend(Data_234940a0, 0, &err);

    r0 = lafat_get_semaphore();
    OSSemPost(r0);
}


/* 2345c09c /  / 23426678 - todo */
int sub_23426678(void)
{
#if 0
	console_send_string("sub_23426678 (todo.c): TODO\r\n");
#endif

    Data_23876bf0.Data_0 = 0;
    Data_23876bf0.Data_4 = 0;
    Data_23876bf0.Data_8 = 0;
    Data_23876bf0.Data_0xc = 0;

    Data_23876c04.Data_0 = ((volatile uint32_t*)0xd5000138)[0];
    Data_23876c04.Data_4 = ((volatile uint32_t*)0xd500013c)[0];
    Data_23876c04.Data_8 = 0x55556666;
    Data_23876c04.Data_0xc = 0x77778888;
    Data_23876c04.Data_0x10 = 0x9999aaaa;
    Data_23876c04.Data_0x14 = 0xbbbbcccc;
    Data_23876c04.Data_0x18 = 0xfedcba98;
    Data_23876c04.Data_0x1c = 0x76543210;

    if (Data_234940a0 == 0)
    {
        Data_234940a0 = OSSemCreate(0);
    }
}


