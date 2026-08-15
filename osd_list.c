#ifndef VDR110

#include "data.h"
#include "frontdisplay.h"
#include "texttable.h"
#include "graphic.h"
#include "menu.h"
#include "osd_list.h"

#pragma thumb

static void sub_2348db56(Menu_Item*, uint16_t, uint8_t, uint8_t);


//234e1d68
uint8_t bData_234e1d68 = 0; //234e1d68 +0
uint8_t bData_234e1d69 = 0; //234e1d69 +1
void (*Data_234e1d6c)(Menu_Item*, uint16_t, uint8_t, uint8_t) = sub_2348db56; //234e1d6c +4 
Struct_2348dc50* Data_234e1d70 = 0; //234e1d70 +8

Struct_2348dc50 Data_2396ca04[10]; //2396ca04???, size???



/* 2348db56 - complete */
void sub_2348db56(Menu_Item* a, uint16_t b, uint8_t c, uint8_t d)
{
#if 0
	console_send_string("sub_2348db56 (todo.c): TODO\r\n");
#endif

    Graphic_Job_2_5_Item* r4;

    do
    {
        r4 = a->Data_4[d];
        if (r4 == 0)
        {
            break;
        }

        d++;
        r4->wColor = b;
        r4->bData_0x3c = c;

        r4 = a->Data_4[d];
    }
    while (r4 != 0);
}


/* 2348db78 - todo */
int sub_2348db78(Menu_Item* a, int b)
{
#if 0
	console_send_string("sub_2348db78 (todo.c): TODO\r\n");
#endif

    int r5 = 0;

    if (b == 1)
    {
        (Data_234e1d6c)(a, Data_234e1d70->bData_0x5b, 1, 0);
    }
    else if (b == 2)
    {
        (Data_234e1d6c)(a, Data_234e1d70->bData_0x5a, 1, 0);

        r5 = 1;
    }

    return r5;
}


/* /  / 2348dbf8 - todo */
int sub_2348dbf8(Menu_Item* pItem, int r1)
{
#if 0
	console_send_string("sub_2348dbf8 (todo.c): TODO\r\n");
#endif

    uint16_t* r2 = &Data_234e1d70->arwData_0x28[0];
    uint8_t i = 0;

    do
    {
        //loc_2348dc10
        if (*r2 == (Data_234e1d70->wData_0x1e + 1))
        {
            //0x2348dc16
            if (r1 == 1)
            {
                //0x2348dc1a
                //r1 = Data_234e1d70->bData_0x5d;
                //->loc_2348dc24
                (Data_234e1d6c)(pItem, Data_234e1d70->bData_0x5d, 1, 0);
            }
            //loc_2348dc1e
            else if (r1 == 2)
            {
                //0x2348dc22
                //r1 = Data_234e1d70->bData_0x5c;
                //loc_2348dc24
                (Data_234e1d6c)(pItem, Data_234e1d70->bData_0x5c, 1, 0);
            }
            //loc_2348dc2a
            return 1;
        }
        //loc_2348dc2e
        i++;
        r2++;
    }
    while (i < 20);
    //0x2348dc38
    if (r1 == 1)
    {
        //0x2348dc3c
        //r1 = Data_234e1d70->bData_0x5b;
        //->loc_2348dc46
        (Data_234e1d6c)(pItem, Data_234e1d70->bData_0x5b, 1, 0);
    }
    //loc_2348dc40
    else if (r1 == 2)
    {
        //0x2348dc44
        //r1 = Data_234e1d70->bData_0x5a;
        //loc_2348dc46
        (Data_234e1d6c)(pItem, Data_234e1d70->bData_0x5a, 1, 0);
    }
    //loc_2348dc4c
    return 0;
}


/* /  / 2348dc50 - todo */
Struct_2348dc50* osd_list_create(Struct_2348dc50* a)
{
#if 0
	console_send_string("osd_list_create (todo.c): TODO\r\n");
#endif

    Struct_2348dc50* r3 = &Data_2396ca04[0];

    uint8_t i;
    for (i = 1; i < 7; i++)
    {
        if (r3->pMenu == NULL)
        {
            break;
        }

        r3++;
    }

    if (i < 8)
    {
        Data_234e1d70 = r3;

        *Data_234e1d70 = *a;

        Data_234e1d70->bData_0x5f = i;

        bData_234e1d68++;

        for (uint8_t k = 0; k < 21; k++)
        {
            Data_234e1d70->arwData_0x28[k] = 0;
        }
    }
    //loc_2348dc98
    return Data_234e1d70;
}


/* /  / 2348dc9c - complete */
void sub_2348dc9c()
{
#if 0
	console_send_string("sub_2348dc9c (todo.c): TODO\r\n");
#endif
}


/* 2348dc9e - todo */
int sub_2348dc9e(void)
{
#if 0
	console_send_string("sub_2348dc9e (todo.c): TODO\r\n");
#endif

    if (Data_234e1d70->bData_0x5f > 7)
    {
        return 4;
    }

    if (bData_234e1d68 == 0)
    {
        return 1;
    }

    bData_234e1d68--;

    memset(&Data_2396ca04[Data_234e1d70->bData_0x5f - 1], 0, sizeof(Struct_2348dc50));

    return 0;
}



/* 2348dcd2 - todo */
Struct_2348dc50* sub_2348dcd2(void)
{
#if 0
	console_send_string("sub_2348dcd2 (todo.c): TODO\r\n");
#endif

    return Data_234e1d70;
}


/* 2348dcd8 - todo*/
void sub_2348dcd8(int a)
{
#if 0 
	console_send_string("sub_2348dcd8 (todo.c): TODO\r\n");
#endif

    Data_234e1d70 = &Data_2396ca04[a - 1];
    bData_234e1d69 = a - 1;
}


/* /  / 2348dd36 - todo */
int osd_list_draw(Menu* r4, int b)
{
#if 0
	console_send_string("osd_list_draw (todo.c): TODO\r\n");
#endif

    Graphic_Queue_Item sp_0x44;
    struct 
    {
        int fill_0[13]; //0
    } sp_0x10;
    Menu_Item* r6;

    if (r4->onEnter != 0)
    {
        int r0 = (r4->onEnter)(r4);
        if (r0 != 0)
        {
            return r0;
        }
    }
    //loc_2348dd4a
    if ((r4->header != 0) &&
        (r4->header->pText != 0) &&
        (r4->stringId != 0xffff))
    {
        text_table_get_string(r4->stringId, r4->header->pText->pString, 35);

        r4->header->pText->bUpdate = 1;
    }
    //loc_2348dd6e
    if ((Data_234e1d70->pMenu != r4) ||
        ((r6 = r4->Data_8) == 0))
    {
        return 4;
    }
    //loc_2348dd84
    if (Data_234e1d70->Data_0x14 != 0)
    {
        (Data_234e1d70->Data_0x14)(Data_234e1d70);
    }
    //loc_2348dd8c
    uint8_t r5 = r4->maxItem;
    do
    {
        //loc_2348dd8e
        (Data_234e1d6c)(r6, Data_234e1d70->bData_0x5b, 1, 0);

        r6++;
    }
    while (r5--);
    //0x2348ddac
    r4->currentItem = Data_234e1d70->wCurrentItem;

    r6 = &r4->Data_8[Data_234e1d70->wCurrentItem];
    r4->Data_4 = r6;

    int r1;
    if (b != 0)
    {
        //0x2348ddc8
        if (Data_234e1d70->Data_0x54 != 0)
        {
            //0x2348ddce
            if ((Data_234e1d70->wData_0x1e + 1) ==
                ((uint16_t*)(Data_234e1d70->Data_0x54))[0])
            {
                //0x2348ddda
                r1 = Data_234e1d70->bData_0x5c;
                //loc_2348ddde
                (Data_234e1d6c)(r6, r1, 1, 0);
            }
            //loc_2348dde8
        } //if (Data_234e1d70->Data_0x54 != 0)
        else
        {
            //loc_2348de3c
            r1 = Data_234e1d70->bData_0x5a;
            //->loc_2348ddde
            (Data_234e1d6c)(r6, r1, 1, 0);
        }
    } //if (b != 0)
    else
    {
        //loc_2348de42
        r1 = Data_234e1d70->bData_0x5b;
        (Data_234e1d6c)(r6, r1, 1, 0);
    }
    //loc_2348dde8
    if ((r4->help != 0) && 
        (b == 1) && 
        (r4->help->pText != 0) &&
        (r6->helpStringId != 0xffff))
    {
        text_table_get_string(r6->helpStringId, r4->help->pText->pString, 243);

        r4->header->pText->bUpdate = 1;

        sub_234089e8(&sp_0x10, 
            r4->help->pText->pString, 
            r4->help->pText->bData_0xd, 
            r4->help->pText->x1, 
            r4->help->pText->y1,
            r4->help->pText->x2, 
            2);
    }
    //loc_2348de2c
    if (r4->graphicHandler != 0)
    {
        (r4->graphicHandler)(&sp_0x44, r4->graphicData);
    }
    //loc_2348de38
    return 0;
}


/* /  / 2348de88 - todo */
int sub_2348de88(int* a)
{
    int r6 = 0;
    int r4 = *a;

    Menu* r5 = Data_234e1d70->pMenu;
    Menu_Item* r0 = r5->Data_4;

    if (Data_234e1d70->wData_0x20 == 0)
    {
        r5->Data_4 = r5->Data_8;

        return 4;
    }

    if (Data_234e1d70->Data_0x18 != 0)
    {
        (Data_234e1d70->Data_0x18)(r0, 1);
    }

    if (r4 == 1)
    {
        r6 = -1;
    }
    else if (r4 == 2)
    {
        r6 = 1;
    }

    if ((((Data_234e1d70->wCurrentItem/*r2*/ == (Data_234e1d70->wData_0x26 - 1)/*r7*/) && (r6 > 0)) ||
        ((Data_234e1d70->wCurrentItem == 0) && (r6 < 0))) &&
        //loc_2348ded8
        (Data_234e1d70->wData_0x20 > Data_234e1d70->wData_0x26))
    {
        //0x2348dee0
        if (r6 > 0)
        {
            //0x2348dee4
            Data_234e1d70->wData_0x1e++;

            if (Data_234e1d70->wData_0x1e > (Data_234e1d70->wData_0x20 - 1))
            {
                Data_234e1d70->wData_0x1e = 0;
            }
            //loc_2348def6
            Data_234e1d70->wCurrentItem = 0;
            //->loc_2348df48
        }
        else
        {
            //loc_2348df18
            Data_234e1d70->wData_0x1e--;

            if (Data_234e1d70->wData_0x1e < 0)
            {
                //0x2348df24
                Data_234e1d70->wData_0x1e = Data_234e1d70->wData_0x20 - 1;

                uint8_t r0 = Data_234e1d70->wData_0x20 % Data_234e1d70->wData_0x26;
                if (r0 == 0)
                {
                    //loc_2348df32
                    Data_234e1d70->wCurrentItem = Data_234e1d70->wData_0x26 - 1; //r7
                    //->loc_2348df3c
                }
                else
                {
                    //loc_2348df36
                    r0--;
                    Data_234e1d70->wCurrentItem = r0;
                    //loc_2348df3c
                }
            }
            else
            {
                //loc_2348df32
                Data_234e1d70->wCurrentItem = Data_234e1d70->wData_0x26 - 1; //r7
            }
            //loc_2348df3c
            if (Data_234e1d70->wData_0x1e < Data_234e1d70->wCurrentItem)
            {
                //->loc_2348def6
                Data_234e1d70->wCurrentItem = 0;
                //->loc_2348df48
            }
        }
        //loc_2348df48
        (Data_234e1d70->Data_0x14)(Data_234e1d70);
        //->loc_2348dfe0
        r5->Data_4 = &r5->Data_8[Data_234e1d70->wCurrentItem];
    }
    else 
    {
        //loc_2348df50
        if ((r6 > 0) && (Data_234e1d70->wData_0x20 == (Data_234e1d70->wData_0x1e - 1)))
        {
            //0x2348df64
            Data_234e1d70->wData_0x1e = 0;
            Data_234e1d70->wCurrentItem = 0;

            (Data_234e1d70->Data_0x14)(Data_234e1d70);

            r5->Data_4 = &r5->Data_8[Data_234e1d70->wCurrentItem];
            //0x2348df82 -> loc_2348dfa6
        }
        else
        {
            //loc_2348df8c
            Data_234e1d70->wData_0x1e += r6;

            if (Data_234e1d70->wData_0x1e > Data_234e1d70->wData_0x20)
            {
                //0x2348df9c
                Data_234e1d70->wData_0x1e = 0;
                Data_234e1d70->wCurrentItem = 0;
                //r0, [r5, #0x8]
                //->loc_2348dfc2
                r5->Data_4 = r5->Data_8;
                //->loc_2348dfa6

                //TODO
            }
            //loc_2348dfae
            else if (Data_234e1d70->wData_0x1e < 0)
            {
                //0x2348dfb2
                Data_234e1d70->wData_0x1e = Data_234e1d70->wData_0x20 - 1;
                Data_234e1d70->wCurrentItem = Data_234e1d70->wData_0x1e;

                r5->Data_4 = &r5->Data_8[Data_234e1d70->wCurrentItem];
                //0x2348dfc4
                //->loc_2348dfa6
                //TODO
            }
            //loc_2348dfc8
            else if (r6 > 0)
            {
                //0x2348dfcc
                if (Data_234e1d70->wCurrentItem/*r2*/ < (Data_234e1d70->wData_0x26 - 1)/*r7*/)
                {
                    //0x2348dfd0
                    Data_234e1d70->wCurrentItem++;
                    //loc_2348dfe0
                }
                //loc_2348dfe0
                r5->Data_4 = &r5->Data_8[Data_234e1d70->wCurrentItem];
            }
            //loc_2348dfd4
            else if (r6 < 0)
            {
                //0x2348dfd8
                if (Data_234e1d70->wCurrentItem/*r2*/ > 0)
                {
                    //0x2348dfdc
                    Data_234e1d70->wCurrentItem--;
                }
                //loc_2348dfe0
                r5->Data_4 = &r5->Data_8[Data_234e1d70->wCurrentItem];
            }
            else
            {
                //loc_2348dfe0
                r5->Data_4 = &r5->Data_8[Data_234e1d70->wCurrentItem];
            }
        }
    }
    //loc_2348df80 -> loc_2348dfa6
    if (Data_234e1d70->Data_0x18 != 0)
    {
        //loc_2348df86
        (Data_234e1d70->Data_0x18)(r5->Data_4, 2);
    }
    //loc_2348dfaa
    return 0;
}


/* /  / 2348dff2 - todo */
int sub_2348dff2(Struct_2348dc50* r4, int8_t r5)
{
#if 0
	console_send_string("sub_2348dff2 (todo.c): TODO\r\n");
#endif

    Menu* pMenu = r4->pMenu;

    if (r4 == 0)
    {
        return 4;
    }

    Menu_Item* pMenuItem = pMenu->Data_4;
    uint8_t r1;

    if (r5 > 0)
    {
        r1 = r5;
    }
    else
    {
        r1 = -r5;
    }

    if (r4->wData_0x20/*r2*/ >= r1)
    {
        //0x2348e016
        if (r4->Data_0x18 != 0)
        {
            (r4->Data_0x18)(pMenuItem, 1);
        }
        //loc_2348e020
        int r0 = r4->wData_0x1e + r5;
        if (r4->wData_0x20/*r2*/ <= r0)
        {
            //0x2348e02e
            r0 -= r4->wData_0x20;
            //->loc_2348e038
        }
        //loc_2348e032
        else if (r0 < 0)
        {
            r0 += r4->wData_0x20;
        }
        //loc_2348e038
        r4->wData_0x1e = r0;

        if (r4->wData_0x1e > r4->wData_0x26)
        {
            //0x2348e042
            if ((r4->wData_0x20 - r4->wData_0x26) <= r4->wData_0x1e)
            {
                //0x2348e048
                r4->wCurrentItem = 0;
            }
            //->loc_2348e054
        }
        else
        {
            //loc_2348e04e
            r4->wCurrentItem = r4->wData_0x1e % r4->wData_0x26;
        }
        //loc_2348e054
        if (r4->Data_0x14 != 0)
        {
            (r4->Data_0x14)(r4);
        }
        //loc_2348e05e
        pMenu->Data_4 = &pMenu->Data_8[r4->wCurrentItem];

        if (r4->Data_0x18 != 0)
        {
            (r4->Data_0x18)(pMenu->Data_4, 2);
        }
        //loc_2348e076
    }
    //loc_2348e076
    return 0;
}


#endif
