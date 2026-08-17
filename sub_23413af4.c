
#include "data.h"
#include "ucos_ii.h"
#include "viscale_osd.h"
#include "graphic.h"


typedef struct{
    int Data_0; //0

} Struct_23413cfc_Inner8;

typedef struct{
    int fill_0; //0
    int fill_4; //4
    Struct_23413cfc_Inner8* Data_8; //8    
    uint16_t wData_0x0c; //0x0c
    uint16_t wData_0x0e; //0x0e
    uint16_t wData_0x10; //0x10
    uint16_t wData_0x12; //0x12
    //???
} Struct_23413cfc;


struct
{
    int fill_0; //0
    uint8_t fill_4; //4
    uint8_t bData_5; //5

} Data_235b8608; // 235b8608


/* /  / 23413af4 - todo */
void sub_23413af4(Struct_23413cfc* r6, int r7)
{
#if 0    
	console_send_string("sub_23413af4 (todo.c): TODO\r\n");
#endif    

    int sp4 = r6->wData_0x10;
    int sp = r6->wData_0x12;

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "sub_23413af4: r6->wData_0x10=%d, r6->wData_0x12=%d, TODO!!!\r\n", 
            r6->wData_0x10, r6->wData_0x12);
        console_send_string(debug_string);
    }
#endif

    sub_23408d10/*sub_2340b7ec*/(r6->Data_8->Data_0);

    int fp = sub_2342d494/*sub_2343c380*/(1);
    uint32_t r5 = 0; 
    //int r4 = 0x235685d8
    Data_235b8608.bData_5 = 1;
    //->loc_23413bf4
    while (1)
    //for (r5 = 0; r5 < sp; r5++)
    {
        //loc_23413bf4
        if (r5 >= sp) break;
        //loc_23413b44

#if 1
        {
            extern char debug_string[];
            sprintf(debug_string, "loc_23413b44: r5=%d, TODO!!!\r\n", 
                r5);
            console_send_string(debug_string);
        }
#endif

        //0x23413bf0
        r5++;
    }
    //0x23413c00
    return;
}


/* /  / 23413cfc - todo */
void sub_23413cfc(Struct_23413cfc* r4, int b/*???*/)
{
#if 0
	console_send_string("sub_23413cfc (todo.c): TODO\r\n");
#endif

    int sp = r4->wData_0x0c;
    int sb = r4->wData_0x0e;

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "sub_23413cfc: r4->wData_0x0c=%d, r4->wData_0x0e=%d, TODO!!!\r\n", 
            r4->wData_0x0c, r4->wData_0x0e);
        console_send_string(debug_string);
    }
#endif

    sub_23408d10/*sub_2340b7ec*/(r4->Data_8->Data_0 & 0xffff);

    int sl = r4->wData_0x10;
    int fp = r4->wData_0x12;

    int r8 = sub_2342d494/*sub_2343c380*/(1);
    uint32_t r5 = 0; 
    Data_235b8608.bData_5 = 1;

    //TODO!!!

    //->loc_23413de0
    while (1)
    //for (r5 = 0; r5 < sp; r5++)
    {
        //loc_23413de0
        if (r5 >= fp) break;
        //loc_23413d5c

#if 1
        {
            extern char debug_string[];
            sprintf(debug_string, "loc_23413d5c: r5=%d, TODO!!!\r\n", 
                r5);
            console_send_string(debug_string);
        }
#endif

        //0x23413ddc
        r5++;
    }
    //0x23413de8
    return;

}


