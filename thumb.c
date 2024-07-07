
#include "data.h"

#pragma thumb

UI_Thread_Params Data_235fdf28; //235fdf28 235fdf98 -0x70
UI_Thread_Params* Data_235fdf70; //235fdf70 / 2378336C -0x40 + 0x18
Menu* Data_235fdf74[13]; //235fdf74 -0x40 + 0x1c, size??? //menuStack
uint8_t bData_235fdfa8; //235fdfa8 235fdf98 + 0x10 //menuStackLvl


/* 2343d3ac - complete */
void sub_2343d3ac(Menu* r4)
{
	struct
	{
		int fill_0[4]; //0
		//???
	} sp_0x40;

	struct
	{
		int fill[13]; //0
		//???
	} sp_0xc;

	Menu_Item* r5;

#if 0
	console_send_string("sub_2343d3ac (todo.c): TODO\r\n");
#endif

	if (r4->Data_0x24 != 0)
	{
		(r4->Data_0x24)(0);
	}
	//loc_2343d3bc
	//r6 = 0xffff;
	if ((r4->Data_0xc != 0) && (r4->Data_0xc->Data_0x20 != 0)
			&& (r4->stringId != 0xffff/*r6*/))
	{
		text_table_get_string(r4->stringId, r4->Data_0xc->Data_0x20->Data_0x10, 36);
	}
	//loc_2343d3d8
	if (r4->Data_8 != 0)
	{
		if (r4->Data_0x34 != 0)
		{
			r5 = (r4->Data_0x34)(r4);
			//->loc_2343d40a
		}
		else
		{
			//loc_2343d3ec
			if (r4->Data_0x2c == 0)
			{
				r4->currentItem = 0;
			}
			//loc_2343d3f4
			r5 = &r4->Data_8[r4->currentItem];

			r4->Data_4 = r5;

			if (r5->Data_0x18 != 0)
			{
				(r5->Data_0x18)(r5);
			}
			//loc_2343d40a
		}
		//loc_2343d40a
		if ((r4->Data_0x10 != 0) && (r4->Data_0x10->Data_0x20 != 0))
		{
			if (r5->wData_2 != 0xffff/*r6*/)
			{
				//0x2343d41c
				Struct_235fdf74_Inner16_Inner0x20* r5_;

				text_table_get_string(r5->wData_2, r4->Data_0x10->Data_0x20->Data_0x10, 244);

				r5_ = r4->Data_0x10->Data_0x20;

				sub_234089e8(&sp_0xc, r5_->Data_0x10, r5_->bData_0xd,
						r5_->wData_2, r5_->wData_4, r5_->wData_6, 4);
				//->loc_2343d448
			}
			else
			{
				//loc_2343d440
				memset(r4->Data_0x10->Data_0x20->Data_0x10, 0, 0xf3);
			}
		}
		//loc_2343d448
		if (r4->Data_0x1c != 0)
		{
			(r4->Data_0x1c)(&sp_0x40, r4->Data_0x14);
		}
	} //if (r4->Data_8 != 0)
	//loc_2343d454
	return;
}


//MenuStack Add or Remove
/* 2343d482 - todo */
Menu* sub_2343d482(Menu* r4)
{
	Menu* r0_;
	Menu** r0 = &Data_235fdf74[bData_235fdfa8];

	if (r4 != 0)
	{
		r0_ = *r0;

		bData_235fdfa8++;
		if (bData_235fdfa8 < 13)
		{
			Data_235fdf74[bData_235fdfa8] = r4;
			return r0_;
		}
		else
		{
			//loc_2343d4ac
			return 0;
		}
	}
	else
	{
		//loc_2343d4b0
		*r0 = 0;

		if (bData_235fdfa8 != 0)
		{
			bData_235fdfa8--;
		}
		//loc_2343d4be
		return Data_235fdf74[bData_235fdfa8];
	}
}


/* 2343d610 - todo */
void mainfunction_thread(UI_Thread_Params* a)
{
    int timeout;
	uint8_t sp_0xc;
	struct
	{
		int fill_0; //0
		uint8_t bData_4; //4
		int fill_8; //8
	} sp;
	int r7;
	Menu* r4;
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2

	}* pMsg;

	Menu_Item* r0;

	void (*r4_)(int);
	void (*r5)(int);

#if 0
	console_send_string("mainfunction_thread (thumb.c): entry\r\n");
#endif

	memcpy(&Data_235fdf28, a, sizeof(UI_Thread_Params));

	Data_235fdf70 = &Data_235fdf28/*r4*/;

	OSSemPost(Data_235fdf28.pSema);
	OSMboxAccept(Data_235fdf28.pMBox);

	if (bData_235fdfa8 == 0)
	{
		sub_2346f708();
	}

	while (1)
	{
		//loc_2343d642
		r4 = Data_235fdf74[bData_235fdfa8];
		if (r4 != 0)
		{
			timeout = r4->Data_0x30;
		}
		else
		{
			//loc_2343d656
			timeout = 0;
		}
		//loc_2343d658
#if 0
		console_send_string("mainfunction_thread (thumb.c): before OSMboxPend\r\n");
#endif
		pMsg = (void*) OSMboxPend(Data_235fdf28.pMBox, timeout, &sp_0xc);
#if 0
        {
            extern char debug_string[];
            sprintf(debug_string, "mainfunction_thread (thumb.c): after OSMboxPend, sp_0xc=%d\r\n", sp_0xc);
            console_send_string(debug_string);
        }
#endif

		r7 = pMsg->bData_0;

		if (r4 != 0)
		{
			r0 = r4->Data_4;
			r4_ = r0->Data_0x24;
			r5 = r0->Data_0x28;
			//->loc_2343d682
		}
		else
		{
			//loc_2343d67c
			r0 = 0;
			r4_ = 0;
			r5 = 0;
		}
		//loc_2343d682
		if (sp_0xc != 10)
		{
			//0x2343d68a
			void* r0_;
			void (*r7_)(void*);
#if 1
			{
                extern char debug_string[];
				sprintf(debug_string, "mainfunction_thread: ir key=%d\r\n", r7);
				console_send_string(debug_string);
			}
#endif
			if (bData_235fdfa8 == 0)
			{
				sub_2346f708();

				r0 = Data_235fdf74[bData_235fdfa8]->Data_4;
			}
			//loc_2343d6a0
			r0_ = r0->Data_0x1c;
			sp.bData_4 = r7;
			r7_ = r0_;

			if (r4_ != 0)
			{
				(r4_)(0);
			}
			//loc_2343d6b0
			if (r7_ != 0)
			{
				(r7_)(&sp);
			}
			//loc_2343d6b8
			if (r5 != 0)
			{
				(r5)(0);
			}
			//->loc_2343d6d0
		} //if (sp_0xc != 10)
		else
		{
			//->loc_2343d6c2
#if 0
			console_send_string("mainfunction_thread (thumb.c): timeout\r\n");
#endif
			if (r0 != 0)
			{
				void (*r1)(int) = r0->Data_0x1c;
				if (r1 != 0)
				{
					(r1)(0);
				}
			}
		}
		//loc_2343d6d0
		if (62 == OSTaskDelReq(0xff))
		{
			OSTaskDel(0xff);
		}
		//->loc_2343d642
	} //while (1)
}


