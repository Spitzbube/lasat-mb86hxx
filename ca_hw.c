
#include "data.h"

#pragma thumb


int Data_235fd4ec; //235fd4ec  0x235fd50c - 0x40 +0x20
volatile void (*Data_235fd510)(); //235fd510  0x235fd50c + 4


/* 2343bdec - todo */
void sub_2343bdec()
{
	console_send_string("sub_2343bdec (todo.c): TODO\r\n");

}


/* 2343be30 - todo */
void sub_2343be30()
{
	console_send_string("sub_2343be30 (todo.c): TODO\r\n");

}


/* 2343c866 - todo */
void sub_2343c866()
{
	console_send_string("sub_2343c866 (todo.c): TODO\r\n");

}


/* 2343cc34 - todo */
void sub_2343cc34(int r7)
{
	uint8_t sp; //sp
	uint32_t r4 = 4096;

#if 0
	console_send_string("sub_2343cc34 (todo.c): TODO\r\n");
#endif

#if 0
	OSSemPend(Data_235fd4ec, 250, &sp);

	if (sp != 0)
	{
		//->loc_2343cc7a
		return;
	}

	//r5 = 0x235fd50c

	if (r7 != 0)
	{
		Data_235fd510 = sub_2343bdec;
	}
	else
	{
		//loc_2343cc5c
		Data_235fd510 = sub_2343be30;
	}

	sp = OSSemPost(Data_235fd4ec);
	//->loc_2343cc74
	while ((r4 > 0) && (Data_235fd510 != 0))
	{
		//loc_2343cc6a
		rtos_task_wait(1);

		r4--;
	}
	//loc_2343cc7a
#endif
}

