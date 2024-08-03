#include "data.h"
#include "ucos_ii.h"
#include "sub_2340a6a0.h"


extern OS_EVENT* channel_sema;
extern Channel_Database channel_database;


/* 2344f770 - complete */
struct Channel_Database* sub_2344f770()
{
	uint8_t err;
	struct Channel_Database* r4;

#if 0
	console_send_string("sub_2344f770 (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &err);

	r4 = &channel_database;

	OSSemPost(channel_sema);

	return r4;
}

