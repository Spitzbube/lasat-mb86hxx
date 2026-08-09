
#ifndef VDR110

#pragma thumb

//0x234d1dc8
static void* Data_234d1dc8; // / / 0x234d1dc8+0



/* /  / 2345c930 - todo */
void sub_2345c930()
{
	console_send_string("sub_2345c930 (todo.c): TODO\r\n");

}


/* /  / 2345c9ba - todo */
void sub_2345c9ba()
{
	console_send_string("sub_2345c9ba (todo.c): TODO\r\n");

}


/* /  / 2345c9f8 - todo */
void sub_2345c9f8(int a)
{
#if 0
	console_send_string("sub_2345c9f8 (todo.c): TODO\r\n");
#endif

    if (a == 0)
    {
        Data_234d1dc8 = sub_2345c930;
    }
    else if (a == 1)
    {
        Data_234d1dc8 = sub_2345c9ba;
    }
}


#endif //VDR110
