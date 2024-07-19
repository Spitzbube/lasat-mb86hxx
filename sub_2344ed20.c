

#include "data.h"


void sub_2344eda4(uint8_t*, int);


/* 2344ed20 - complete */
void sub_2344ed20(/*Struct_236e5834*/uint8_t* r4, int b)
{
#if 0
	console_send_string("sub_2344ed20 (todo.c): TODO\r\n");
#endif

	int r0 = (r4[3] << 8) | r4[4];

	r4[12] = 0;

	sub_23411b0c(r0, r4 + 5);

	sub_2340052c(r4 + 3, 5);
}


/* 2344ed58 - todo */
void sub_2344ed58(/*Struct_236e5834*/uint8_t* a, int b)
{
#if 0
	console_send_string("sub_2344ed58 (todo.c): TODO\r\n");
#endif

	int16_t r4 = ((a[8] & 0x0f) << 8) | a[9];
	uint8_t* r5 = a + 10;

	while (r4 > 0)
	{
		//loc_2344ed74
		sub_2344eda4(r5, 0);

		r4 -= (r5[1] + 2);
		r5 += (r5[1] + 2);
	}
}


/* 2344eda4 - todo */
void sub_2344eda4(uint8_t* a, int b)
{
#if 0
	console_send_string("sub_2344eda4 (todo.c): TODO\r\n");
#endif

}



