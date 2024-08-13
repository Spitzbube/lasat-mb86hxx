
#include "data.h"
#include "sub_2345609c.h"


struct 
{
    void* sema; //0x2377e084 /  / 0x2361f448
    int fill_4[28]; //4
    int Data_0x74; //0x74
    int fill_0x78[3]; //0x78
    void* Data_0x84; //0x84
    int fill_0x88; //0x88
    int Data_0x8c; //0x8c
    int Data_0x90; //0x90
    int Data_0x94; //0x94
    int Data_0x98; //0x98
    int Data_0x9c; //0x9c
    int Data_0xa0; //0xa0 = 2377E124
    int fill_0xa4[128]; //0xa4
    int Data_0x2a4; //0x2a4
    //???
} Data_2377e084; //2377e084???



/* 2345609c /  / 2341f814 - complete */
int sub_2345609c(Struct_23415f44 a)
{
#if 0
	console_send_string("sub_2345609c (todo.c): TODO\r\n");
#endif

    Data_2377e084.Data_0x8c = a.Data_0;
    Data_2377e084.Data_0x90 = a.Data_4;
    Data_2377e084.Data_0x94 = a.Data_8;
    Data_2377e084.Data_0x98 = a.Data_12;
    Data_2377e084.Data_0x9c = a.Data_16;
    Data_2377e084.Data_0x84 = &Data_2377e084.Data_0x2a4;
    Data_2377e084.Data_0x74 = 0;

    if (Data_2377e084.sema == 0)
    {
        Data_2377e084.sema = OSSemCreate(1);
    }

    Data_2377e084.Data_0xa0 = a.Data_0x18;

    return 0;
}


/* 234579c8 /  / 23421140 - todo */
void* sub_234579c8(void)
{
#if 0
	console_send_string("sub_234579c8 (todo.c): TODO\r\n");
#endif

    return Data_2377e084.sema;
}


