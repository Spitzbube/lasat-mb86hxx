
#include "data.h"

#pragma thumb

extern void sub_2343d6e2(UI_Thread_Params*);


Menu_Item Data_23492f98[7] = //23492f98 +4
{
	//[0]
	{
		80, //"Allgemein"
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23471fa2, //void* Data_0x1c; //0x1c = 28
		sub_2343d6e2, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 0x23492fc4
#if 0
		0x23492f98                        dw         0x0050
		0x23492f9a                        dw         0xffff
		0x23492f9c                        dd         0x00000000
		                              dword_23492fa0:
		0x23492fa0                        dd         0x00000000                         ; DATA XREF=sub_2343d104+22, aTvradio+80
		0x23492fa4                        dd         0x00000000
		0x23492fa8                        dd         0x00000000
		0x23492fac                        dd         0x00000000
		0x23492fb0                        dd         0x00000000
		0x23492fb4                        dd         0x23471fa3
		0x23492fb8                        dd         0x2343d6e3
		0x23492fbc                        dd         0x00000000
		0x23492fc0                        dd         0x00000000
#endif
	},
	//[1]
#if 0
	{
		11, //"Sendersuche"
		0xffff, //uint16_t wData_2; //2
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_23470548, //void* Data_0x1c; //0x1c = 28
		sub_2343d6e2, //void* Data_0x20; //0x20 = 32
		0, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 23492FF0
#if 0
		0x23492fc4                        dw         0x000b                             ; DATA XREF=sub_2343d104+18
		0x23492fc6                        dw         0xffff
		                              dword_23492fc8:
		0x23492fc8                        dd         0x00000000                         ; DATA XREF=aIn1Optical+20
		0x23492fcc                        dd         0x00000000
		0x23492fd0                        dd         0x00000000
		0x23492fd4                        dd         0x00000000
		0x23492fd8                        dd         0x00000000
		                              dword_23492fdc:
		0x23492fdc                        dd         0x00000000                         ; DATA XREF=dword_23492eac+8
		0x23492fe0                        dd         0x23470549
		0x23492fe4                        dd         0x2343d6e3
		0x23492fe8                        dd         0x00000000
		                              dword_23492fec:
		0x23492fec                        dd         0x00000000
#endif
	},
	//[2]
	{
		401, //"Equalizer"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		sub_23471600,
		sub_2343d6e2,
		0,
		0
		//0x2349301c
#if 0
			0x23492ff0                        dw         0x0191                             ; DATA XREF=dword_23492ec0+8
			0x23492ff2                        dw         0xffff
			0x23492ff4                        dd         0x00000000
			0x23492ff8                        dd         0x00000000
			0x23492ffc                        dd         0x00000000
			0x23493000                        dd         0x00000000
			0x23493004                        dd         0x00000000
			0x23493008                        dd         0x00000000
			0x2349300c                        dd         0x23471601                         ; DATA XREF=dword_23492c7c+80
			0x23493010                        dd         0x2343d6e3
			0x23493014                        dd         0x00000000                         ; DATA XREF=dword_23492c7c+88
			0x23493018                        dd         0x00000000

#endif
	},
	//[3]
	{
		TEXT_ID_NETZWERK, //"Netzwerk"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		menu_network_on_entry,
		sub_2343d6e2,
		0,
		0
		//0x23493048
#if 0
			0x2349301c                        dw         0x015d
			0x2349301e                        dw         0xffff
			0x23493020                        dd         0x00000000
			0x23493024                        dd         0x00000000
			0x23493028                        dd         0x00000000
			0x2349302c                        dd         0x00000000
			0x23493030                        dd         0x00000000
			0x23493034                        dd         0x00000000
			0x23493038                        dd         0x23470f23
			0x2349303c                        dd         0x2343d6e3
			0x23493040                        dd         0x00000000
			0x23493044                        dd         0x00000000
#endif
	},
	//[4]
	{
		87, //"Werkszustand"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		sub_2343d1ca,
		sub_2343d6e2,
		0,
		0
		//0x23493074
#if 0
		0x23493048                        dw         0x0057
		0x2349304a                        dw         0xffff
		0x2349304c                        dd         0x00000000
		0x23493050                        dd         0x00000000
		0x23493054                        dd         0x00000000                         ; DATA XREF=dword_23492c7c+32
		0x23493058                        dd         0x00000000
		0x2349305c                        dd         0x00000000
		0x23493060                        dd         0x00000000
		0x23493064                        dd         0x2343d1cb
		0x23493068                        dd         0x2343d6e3
		0x2349306c                        dd         0x00000000
		0x23493070                        dd         0x00000000
#endif
	},
	//[5]
	{
		63, //"information"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		sub_23471d2c,
		sub_2343d6e2,
		0,
		0
		//0x234930a0
#if 0
		0x23493074                        dw         0x003f
		0x23493076                        dw         0xffff
		0x23493078                        dd         0x00000000
		0x2349307c                        dd         0x00000000
		0x23493080                        dd         0x00000000
		0x23493084                        dd         0x00000000
		0x23493088                        dd         0x00000000
		0x2349308c                        dd         0x00000000
		0x23493090                        dd         0x23471d2d
		0x23493094                        dd         0x2343d6e3
		0x23493098                        dd         0x00000000
		0x2349309c                        dd         0x00000000
#endif
	},
	//[6]
	{
		458, //"Software-Update"
		0xffff,
		{0, 0, 0, 0, 0}, //int fill_4[5]; //4
		0,
		sub_2347004a,
		sub_2343d6e2,
		0,
		0
		//0x234930cc
#if 0
		0x234930a0                        dw         0x01ca
		0x234930a2                        dw         0xffff                             ; DATA XREF=sub_2343d104+48
		0x234930a4                        dd         0x00000000                         ; DATA XREF=sub_2343d104+52
		0x234930a8                        dd         0x00000000                         ; DATA XREF=sub_2343d104+58
		0x234930ac                        dd         0x00000000
		0x234930b0                        dd         0x00000000
		0x234930b4                        dd         0x00000000
		0x234930b8                        dd         0x00000000
		0x234930bc                        dd         0x2347004b
		0x234930c0                        dd         0x2343d6e3
		0x234930c4                        dd         0x00000000
		0x234930c8                        dd         0x00000000
#endif
	}
#endif
};

Menu menuMain = //234930cc
{
		10, //"Hauptmenu"
		&Data_23492f98[0], //Menu_Item* Data_4; //4
		&Data_23492f98[0], //Menu_Item* Data_8; //8
		0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
		0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
		0, //int Data_0x14; //20 = 0x14
		0, //6, //uint8_t maxItem; //0x18 = 24
		0, //int8_t currentItem; //0x19
		0, //void (*Data_0x1c)(); //0x1c
#if 0
		sub_2343d4c8, //void (*Data_0x20)(); //0x20
		sub_2343d1ac, //void (*Data_0x24)(); //36 = 0x24
		sub_2343d1be, //int (*Data_0x28)(); //0x28
		0, //int Data_0x2c; //44 = 0x2c
		0, //int Data_0x30; //48
		0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
		//0x38 = 56?
#if 0
		0x234930cc                        dw         0x000a
		0x234930ce                        dw         0x0000
		0x234930d0                        dd         0x23492f98
		0x234930d4                        dd         0x23492f98                         ; DATA XREF=sub_2343d104+10
		0x234930d8                        dd         0x00000000
		0x234930dc                        dd         0x00000000
		0x234930e0                        dd         0x00000000
		0x234930e4                        db  0x06 ; '.'
		                              byte_234930e5:
		0x234930e5                        db         0x00                               ; DATA XREF=sub_2343d104+8
		0x234930e6 0000                   movs       r0, r0
		0x234930e8                        dd         0x00000000
		0x234930ec                        dd         0x2343d4c9
		0x234930f0                        dd         0x2343d1ad
		0x234930f4                        dd         0x2343d1bf
		0x234930f8                        dd         0x00000000
		0x234930fc                        dd         0x00000000
		0x23493100                        dd         0x00000000
#endif
#endif
}; //23493104

UI_Thread_Params Data_235fdf28; //235fdf28 235fdf98 -0x70
UI_Thread_Params Data_235fdf58; //235fdf58 235fdf98 -0x40
UI_Thread_Params* Data_235fdf70; //235fdf70 / 2378336C -0x40 + 0x18
Menu* Data_235fdf74[13]; //235fdf74 -0x40 + 0x1c, size??? //menuStack
uint8_t bData_235fdfa8; //235fdfa8 235fdf98 + 0x10 //menuStackLvl


/* 2343d1d6 - todo */
int menu_main_start()
{
	UI_Thread_Params* r4;

#if 1
	console_send_string("menu_main_start (todo.c): TODO\r\n");
#endif

	r4 = sub_2343d572(); //Get the current UI thread params

	sub_2343d482(&menuMain); //Add to the menu stack
	sub_2343d3ac(&menuMain); //Initialize the menu
	sub_2343d51e(&menuMain, r4); //Backup UI thread params?

	return 0;
}


/* Menu Initialize */
/* 2343d3ac - complete */
void sub_2343d3ac(Menu* pMenu)
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

	Menu_Item* pMenuItem;

#if 0
	console_send_string("sub_2343d3ac (todo.c): TODO\r\n");
#endif

	if (pMenu->Data_0x24 != 0)
	{
		(pMenu->Data_0x24)(0);
	}
	//loc_2343d3bc
	//r6 = 0xffff;
	if ((pMenu->Data_0xc != 0) && (pMenu->Data_0xc->Data_0x20 != 0)
			&& (pMenu->stringId != 0xffff/*r6*/))
	{
		text_table_get_string(pMenu->stringId, pMenu->Data_0xc->Data_0x20->Data_0x10, 36);
	}
	//loc_2343d3d8
	if (pMenu->Data_8 != 0)
	{
		if (pMenu->Data_0x34 != 0)
		{
			pMenuItem = (pMenu->Data_0x34)(pMenu);
			//->loc_2343d40a
		}
		else
		{
			//loc_2343d3ec
			if (pMenu->Data_0x2c == 0)
			{
				pMenu->currentItem = 0;
			}
			//loc_2343d3f4
			pMenuItem = &pMenu->Data_8[pMenu->currentItem];

			pMenu->Data_4 = pMenuItem;

			if (pMenuItem->Data_0x18 != 0)
			{
				(pMenuItem->Data_0x18)(pMenuItem);
			}
			//loc_2343d40a
		}
		//loc_2343d40a
		if ((pMenu->Data_0x10 != 0) && (pMenu->Data_0x10->Data_0x20 != 0))
		{
			if (pMenuItem->wData_2 != 0xffff/*r6*/)
			{
				//0x2343d41c
				Struct_235fdf74_Inner16_Inner0x20* r5_;

				text_table_get_string(pMenuItem->wData_2, pMenu->Data_0x10->Data_0x20->Data_0x10, 244);

				r5_ = pMenu->Data_0x10->Data_0x20;

				sub_234089e8(&sp_0xc, r5_->Data_0x10, r5_->bData_0xd,
						r5_->wData_2, r5_->wData_4, r5_->wData_6, 4);
				//->loc_2343d448
			}
			else
			{
				//loc_2343d440
				memset(pMenu->Data_0x10->Data_0x20->Data_0x10, 0, 243);
			}
		}
		//loc_2343d448
		if (pMenu->Data_0x1c != 0)
		{
			(pMenu->Data_0x1c)(&sp_0x40, pMenu->Data_0x14);
		}
	} //if (pMenu->Data_8 != 0)
	//loc_2343d454
	return;
}


/* 2343d458 - todo */
void sub_2343d458(UI_Thread_Params* a)
{
	memcpy(&Data_235fdf58, a, sizeof(UI_Thread_Params));
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


/* 2343d51e - todo */
int sub_2343d51e(Menu* r2, UI_Thread_Params* r0)
{
	UI_Thread_Params sp4;

#if 0
	console_send_string("sub_2343d51e (todo.c): TODO\r\n");
#endif

	if (r2 != 0)
	{
		//0x2343d528
		Menu_Item* pMenuItem = r2->Data_4;

		if (pMenuItem->inputThreadFunc == r0->threadFunc)
		{
			//loc_2343d532
			return 0;
		}
		//loc_2343d538
		else if (pMenuItem->inputThreadFunc == 0)
		{
			//loc_2343d53c
			r0 = &Data_235fdf58;
			//->loc_2343d550
		}
		else
		{
			//loc_2343d542
			if (r0 == 0)
			{
				r0 = &sp4;
			}
			//loc_2343d548
			r0->Data_20 = r0->threadFunc;
			r0->threadFunc = pMenuItem->inputThreadFunc;
			//loc_2343d550
		}
	}
	else
	{
		//loc_2343d53c
		r0 = &Data_235fdf58;
		//->loc_2343d550
	}
	//loc_2343d550
	ui_thread_create(r0);
	//->loc_2343d532
	return 0;
}


/* Get UI Thread Params */
/* 2343d572 - todo */
UI_Thread_Params* sub_2343d572(void)
{
#if 0
	console_send_string("sub_2343d572 (todo.c): TODO\r\n");
#endif

	return Data_235fdf70;
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


/* 2343d6e2 - todo */
void sub_2343d6e2(UI_Thread_Params* p)
{
//	Struct_235fdf98* sp_0x28;
	uint8_t err; //sp_0x24
	int sp_0x20;
	UI_Thread_Params sp8; //->sp0x20
	void (*sp4)();
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2

	}* pMsg;
	int r0;
	Menu* r4;
	Menu_Item* r1;
	void (*r7)() = 0;
	void (*r6)();
	int (*r5)() = 0;

#if 0
	console_send_string("sub_2343d6e2 (todo.c): TODO\r\n");
#endif

	sp8 = *p;

	Data_235fdf70 = &sp8;

	err = OSSemPost(sp8.pSema);
	OSMboxAccept(sp8.pMBox);

//	sp_0x28 = &Data_235fdf98;

	while (1)
	{
		//loc_2343d70e
		int timeout;
		if (Data_235fdf74[ /*sp_0x28->bData_0x10*/bData_235fdfa8 ] != 0)
		{
			//0x2343d71e
			timeout = Data_235fdf74[ /*sp_0x28->bData_0x10*/bData_235fdfa8 ]->Data_0x30;
		}
		else
		{
			timeout = 0;
		}
		//loc_2343d720
		pMsg = (void*) OSMboxPend(sp8.pMBox, (uint16_t)timeout, &err);

		r0 = pMsg->bData_0;

		r4 = Data_235fdf74[ /*sp_0x28->bData_0x10*/bData_235fdfa8 ];
		r1 = r4->Data_4;
		sp4 = r1->Data_0x24;
		r6 = r1->Data_0x28;

		if (err == 0)
		{
			//0x2343d746
			switch (r0)
			{
			case 0x21: //Down
			case 0x83:
				//loc_2343d77c
				sp_0x20 = 2;
				//loc_2343d77e
				r7 = r4->Data_0x20;
				//->loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
				break;

			case 0x20: //Up
			case 0x82:
				//0x2343d75e -> loc_2343d7d0
				sp_0x20 = 1;
				//loc_2343d77e
				r7 = r4->Data_0x20;
				//->loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
				break;

			case 0x2d: //EXIT
			case 0xe0:
				//loc_2343d78e
				if ((r4->Data_0x28 != 0) && ((r4->Data_0x28)(0) != 0))
				{
					//->loc_2343d7d6
					if (sp4 != 0)
					{
						(sp4)(0);
					}
					//loc_2343d7e2
				}
				else
				{
					//loc_2343d79c
					r4 = sub_2343d482(0);

					if (r4 != 0)
					{
						sp4 = r4->Data_4->Data_0x24;
						r6 = r4->Data_4->Data_0x28;

						if (r4->Data_0x24 != 0)
						{
							(r4->Data_0x24)(-1);
						}
						//loc_2343d7ba
						sub_2343d51e(r4, &sp8);
						//->loc_2343d7d6
						if (sp4 != 0)
						{
							(sp4)(0);
						}
						//loc_2343d7e2
					}
					else
					{
						//loc_2343d7c4
						sub_2343d51e(0, &sp8);
						//loc_2343d7cc
						r6 = 0;
						//->loc_2343d7e2
					}
				}
				break;

			case 0x57: //OK
			case 0xea:
				//0x2343d768 -> loc_2343d7d4
				r5 = r1->Data_0x1c;
				//loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
				break;

			case 0x11: //Left
			case 0x81:
				//loc_2343d820
				sp_0x20 = 4;
				//loc_2343d77e
				r7 = r4->Data_0x20;
				//->loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
				break;

			case 0x10: //Right
			case 0x80:
				//loc_2343d824
				sp_0x20 = 8;
				//loc_2343d77e
				r7 = r4->Data_0x20;
				//->loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
				break;

			case 0xff:
				//loc_2343d7d6
				if (sp4 != 0)
				{
					(sp4)(0);
				}
				//loc_2343d7e2
				break;

			default:
				//loc_2343d7cc
				r6 = 0;
				//->loc_2343d7e2
				break;
			} //switch (r0)
			//loc_2343d7e2
			if (r5 != 0)
			{
				//0x2343d7e6
				if (0 != (r5)(&sp8))
				{
					//0x2343d7ee
					if ((r4->Data_0x28 != 0) && ((r4->Data_0x28)(0) != 0))
					{
						//->loc_2343d8b0
						return;
					}
					//loc_2343d7fc
					r4 = sub_2343d482(0);

					if (r4 != 0)
					{
						r6 = r4->Data_4->Data_0x28;

						if (r4->Data_0x24 != 0)
						{
							(r4->Data_0x24)(-1);
						}
						//loc_2343d816
						sub_2343d51e(r4, &sp8);
						//->loc_2343d834
					}
					else
					{
						//loc_2343d82a
						sub_2343d51e(0, &sp8);

						r6 = 0;
					}
				} //if (0 != (r5)(&sp8))
				//loc_2343d834
				r5 = 0;
			} //if (r5 != 0)
			//loc_2343d836
			if (r7 != 0)
			{
				(r7)(&sp_0x20);

				err = sub_2343d51e(r4, &sp8);

				r7 = 0;
			} //if (r7 != 0)
			//loc_2343d84a
			if (r6 != 0)
			{
				(r6)(0);
			}
			//->loc_2343d89c
		} //if (err == 0)
		else
		{
			//->loc_2343d828 -> loc_2343d854
			if (r1 != 0)
			{
				r5 = r1->Data_0x1c;
				if (r5 != 0)
				{
					if (0 != (r5)(0))
					{
						if ((r4->Data_0x28 != 0) && ((r4->Data_0x28)(0) != 0))
						{
							//->loc_2343d8b0
							return;
						}
						//loc_2343d874
						r4 = sub_2343d482(0);

						if (r4 != 0)
						{
							if (r4->Data_0x24 != 0)
							{
								(r4->Data_0x24)(-1);
							}
							//loc_2343d88a
							sub_2343d51e(r4, &sp8);
							//->loc_2343d89a
						}
						else
						{
							//loc_2343d894
							sub_2343d51e(0, &sp8);
						}
					}
					//loc_2343d89a
					r5 = 0;
				} //if (r5 != 0)
				//loc_2343d89c
			} //if (r1 != 0)
			//loc_2343d89c
		}
		//loc_2343d89c
		if (62 == OSTaskDelReq(0xff))
		{
			//loc_2343d8a8
			OSTaskDel(0xff);
		}
		//->loc_2343d70e
	} //while (1)
	//loc_2343d8b0
	return;
}


