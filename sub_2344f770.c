#include "data.h"
#include "ucos_ii.h"
#include "sub_2340a6a0.h"


extern OS_EVENT* channel_sema;
extern Struct_234fd8f0 Data_234fd8f0;


/* 2344f770 - complete */
struct Struct_234fd8f0_Inner0* sub_2344f770()
{
	uint8_t err;
	struct Struct_234fd8f0_Inner0* r4;

#if 0
	console_send_string("sub_2344f770 (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &err);

	r4 = &Data_234fd8f0; //.Data_234fd8f0[0];

	OSSemPost(channel_sema);

	return r4;
}

