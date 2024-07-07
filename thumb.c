
#include "data.h"

#pragma thumb

UI_Thread_Params Data_235fdf28; //235fdf28 235fdf98 -0x70


/* 2343d610 - todo */
void mainfunction_thread(UI_Thread_Params* a)
{
    int timeout;
	uint8_t sp_0xc;
	int r7;
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2

	}* pMsg;

#if 0
	console_send_string("mainfunction_thread (thumb.c): entry\r\n");
#endif

	memcpy(&Data_235fdf28, a, sizeof(UI_Thread_Params));

	OSSemPost(Data_235fdf28.pSema);
	OSMboxAccept(Data_235fdf28.pMBox);

	while (1)
	{
		//loc_2343d642
        timeout = 0;

#if 0
		console_send_string("mainfunction_thread (thumb.c): before OSMboxPend\r\n");
#endif
		pMsg = (void*) OSMboxPend(Data_235fdf28.pMBox, timeout, &sp_0xc);
#if 1
        {
            extern char debug_string[];
            sprintf(debug_string, "mainfunction_thread (thumb.c): after OSMboxPend, sp_0xc=%d\r\n", sp_0xc);
            console_send_string(debug_string);
        }
#endif

		r7 = pMsg->bData_0;

		if (sp_0xc != 10)
		{
			//0x2343d68a
#if 1
			{
                extern char debug_string[];
				sprintf(debug_string, "mainfunction_thread: ir key=%d\r\n", r7);
				console_send_string(debug_string);
			}
#endif

		} //if (sp_0xc != 10)
		else
		{
			//->loc_2343d6c2
#if 0
			console_send_string("mainfunction_thread (thumb.c): timeout\r\n");
#endif
		}
		//loc_2343d6d0
		if (62 == OSTaskDelReq(0xff))
		{
			OSTaskDel(0xff);
		}
		//->loc_2343d642
	} //while (1)
}


