
#ifndef VDR110

#pragma thumb

// / / 0x234d0c2c
void* Data_234d0c34 = 0; // /  / 234d0c34 +8
void* Data_234d0c38 = 0; // /  / 234d0c34 +0xc
void* Data_234d0c3c = 0; // /  / 234d0c34 +0x10


/* /  / 2345b852 - todo */
void sub_2345b852(void* a, void* b, void* c)
{
#if 0
	console_send_string("sub_2345b852 (todo.c): TODO\r\n");
#endif

    Data_234d0c34 = a;
    Data_234d0c38 = b;
    Data_234d0c3c = c;
}


#endif //!VDR110
