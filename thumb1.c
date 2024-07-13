
#include "data.h"

#pragma thumb

int menu_root_on_event(void*);
int menu_root_on_enter(int);
int menu_root_on_exit(int);

//0x23495984
struct
{
	uint8_t bData_0; //0
	int Data_23495974; //4    23495974
	void* (*Data_23495978)(); //8   23495978
	void (*Data_2349597c)(); //12  2349597c
	int fill_23495980; //16  23495980
	uint8_t strText[0x100]; //20  23495984
	int Data_23495a84; //23495a84
	int fill_23495a88[63]; //23495a88
	uint8_t bData_23495b84; //0x214 = 532, 23495b84
	int Data_23495b88; //0x218 = 536, 23495b88
	uint16_t wData_23495b8c; //0x21C = 540, 23495b8c
	int Data_23495b90; //544, 23495b90
	uint16_t fill_548; //548, 23495b94
	uint8_t bData_23495b96; //0x226 = 550   23495b96
	uint8_t fill_23495b97; //23495b97
	uint8_t bData_23495b98; //0x228 = 552, 23495b98
	int (*Data_23495b9c)(); //0x22C = 556, 23495b9c  0x23495b90 - 0x20 +0x2c
	uint8_t bData_23495ba0; //0x230 = 560, 23495ba0 23495b90 + 0x10
	uint32_t Data_23495ba4; //564, 23495ba4, 23495b90 +0x14
	uint8_t bData_23495ba8; //23495BA8 23495b90 +0x18
	//572?
} Data_23495970 = //23495970   0x23495984 - 0x14   + 0x23C -> 23495BAC
{
		1, //bData_0
};

//0x23495b90
//void (*Data_23495b9c)(); //0x22C = 556, 23495b9c  0x23495b90 - 0x20 +0x2c
//uint8_t bData_23495ba0; //23495ba0 23495b90 + 0x10
extern Menu_Item Data_23495be4; //23495be4
Menu Data_23495bac = //23495bac 0x23495b90 + 0x1c  -> 23495BE4
{
		0xffff, //wData_0
		&Data_23495be4, //Data_4
		&Data_23495be4, //Data_8
		0, //Data_0xc
		0, //Data_0x10
		0, //Data_0x14
		0, //maxItem
		0, //currentItem
		0, //Data_0x1c
		0, //onNavigate //0x20
		menu_root_on_enter, //onEnter //0x24
		menu_root_on_exit, //onExit //0x28
		0xff, //Data_0x2c
		25, //timeout //0x30
		0 //Data_0x34
#if 0
		0x23495bac                        dw         0xffff                             ; DATA XREF=sub_2346f708+66, sub_2346f708+74
		0x23495bae 0000                   movs       r0, r0
		0x23495bb0                        dd         0x23495be4
		0x23495bb4                        dd         0x23495be4
		0x23495bb8                        dd         0x00000000
		0x23495bbc                        dd         0x00000000
		0x23495bc0                        dd         0x00000000
		0x23495bc4                        db         0x00
		0x23495bc5                        db         0x00
		0x23495bc6 0000                   movs       r0, r0
		0x23495bc8                        dd         0x00000000
		0x23495bcc                        dd         0x00000000
		0x23495bd0                        dd         0x2346ecfd
		0x23495bd4                        dd         0x2346ed1d
		0x23495bd8                        dd         0x000000ff
		0x23495bdc                        dd         0x00000019
		0x23495be0                        dd         0x00000000
#endif
};
Menu_Item Data_23495be4 = //23495be4
{
		0xffff,
		0xffff,
		{0, 0, 0, 0, 0},
		0, //Data_0x18
		menu_root_on_event, //onEvent //0x1c
		mainfunction_thread, //inputThreadFunc //0x20
		0, //Data_0x24
		0 //Data_0x28
#if 0
		0x23495be4                        db  0xff ; '.'                                ; DATA XREF=0x23495bb0, 0x23495bb4
		0x23495be5                        db  0xff ; '.'
		0x23495be6                        db  0xff ; '.'
		0x23495be7                        db  0xff ; '.'
		0x23495be8 0000                   movs       r0, r0
		0x23495bea 0000                   movs       r0, r0
		0x23495bec 0000                   movs       r0, r0
		0x23495bee 0000                   movs       r0, r0
		0x23495bf0 0000                   movs       r0, r0
		0x23495bf2 0000                   movs       r0, r0
		0x23495bf4 0000                   movs       r0, r0
		0x23495bf6 0000                   movs       r0, r0
		0x23495bf8 0000                   movs       r0, r0
		0x23495bfa 0000                   movs       r0, r0
		0x23495bfc 0000                   movs       r0, r0
		0x23495bfe 0000                   movs       r0, r0
		0x23495c00                        dd         0x2346f37d
		0x23495c04                        dd         0x2343d611
		0x23495c08                        dd         0x00000000
		0x23495c0c                        dd         0x00000000
#endif
};


/* 2346ecd4 - complete */
void* sub_2346ecd4(int* a)
{
#if 1
	console_send_string("sub_2346ecd4 (todo.c): TODO\r\n");
#endif

	(*a)--;

	if (*a != 0)
	{
		return sub_2346ecd4;
	}
	//loc_2346ece2
#if 0 
	if (0 == sub_2346faf6(&Data_23495970.strText[0]))
	{
		frontdisplay_start_text(sub_2346ec9c);
		//->loc_2346ecf8
	}
	else
	{
		//loc_2346ecf4
		sub_23411550(); //->av.c
	}
#endif
	//loc_2346ecf8
	return 0;
}


/* 2346ecfc - complete */
int menu_root_on_enter(int a)
{
#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "menu_root_on_enter: a=%d\r\n", a);
        console_send_string(debug_string);
    }
#endif

	if (a != 0)
	{
		Data_23495970.Data_23495978 = sub_2346ecd4;
		Data_23495970.Data_23495974 = 1;
		Data_23495970.Data_2349597c = 0;
	}
	//loc_2346ed10
	memset(&Data_23495970.Data_23495b90, 0, 8);

	return 0;
}


/* 2346ed1c - complete */
int menu_root_on_exit(int a)
{
#if 0
	console_send_string("menu_root_on_exit\r\n");
#endif

	return 0;
}


/* 2346f37c - todo */
int menu_root_on_event(void* r0)
{
#if 0
	Struct_2340bf0c sp4;
#endif

#if 0
	console_send_string("menu_root_on_event (todo.c): TODO\r\n");
#endif

	//r6 = 23495970
	//r4 = 23495B70

	//r3 = Data_23495970.Data_23495974;
	//r2 = Data_23495970.Data_23495978;

	if (r0 == 0)
	{
		//0x2346f390: handle timeout
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "menu_root_on_event: Data_23495970.Data_23495974=%d, Data_23495970.Data_23495978=%p\r\n",
					Data_23495970.Data_23495974, Data_23495970.Data_23495978);
			console_send_string(debug_string);
		}
#endif
		if (Data_23495970.Data_23495974 != 0)
		{
			if (Data_23495970.Data_23495978 != 0)
			{
				void* r0 = (Data_23495970.Data_23495978)(&Data_23495970.Data_23495974);
				//->loc_2346f47a
				Data_23495970.Data_23495978 = r0;
			}
			//loc_2346f3b6 -> loc_2346f6f0
		}
#if 0
		else
		{
			//loc_2346f39e
			if ((Data_23495970.Data_23495b9c == 0) ||
					(0 == (Data_23495970.Data_23495b9c)()))
			{
				//loc_2346f3aa
				if (0 != sub_2346f7e0())
				{
					//->loc_2346f3a8 -> loc_2346f3b6
				}
				else
				{
					//0x2346f3b2
					sub_2346f844();
					//loc_2346f3b6 -> loc_2346f6f0
				}
			}
			//loc_2346f3b6 -> loc_2346f6f0
		}
#endif        
	} //if (r0 == 0)
	else
	{
		//loc_2346f3b8
		//r5, =0x23495b90

		Menu_Event* r7 = r0;

		Data_23495970.bData_23495ba0 = 1;

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "menu_root_on_event: r7->keyCode=%d\r\n",
					r7->keyCode);
			console_send_string(debug_string);
		}
#endif

#if 0
		if (!((r7->keyCode >= 90/*0x5a*/ && r7->keyCode < 98))) //S1...S8
		{
			//0x2346f3c8
			Data_23495970.Data_23495b88 = 0;
		}
		//loc_2346f3cc
		if ((r7->keyCode > 9) && (r7->keyCode != 87/*0x57*/))
		{
			Data_23495970.bData_23495b96 = 0;
		}
		//loc_2346f3da
		if ((r7->keyCode >= 225/*0xe1*/) && (r7->keyCode < 228/*0xe4*/))
		{
			Data_23495970.wData_23495b8c = r7->keyCode-224/*0xe0*/ + Data_23495970.bData_23495b84;
			Data_23495970.bData_23495b84 = 0;
			Data_23495970.Data_23495974 = 10;
			Data_23495970.Data_23495978 = sub_2346ee6c;
			Data_23495970.Data_2349597c = sub_2346f26c;
			//->loc_2346f408
			//loc_2346f40a -> loc_2346f6f0
		}
		//loc_2346f3fc
		else if (r7->keyCode == 224/*0xe0*/)
		{
			Data_23495970.Data_23495974 = 0;
			Data_23495970.Data_23495978 = 0;
			Data_23495970.Data_2349597c = sub_2346f314;
			//loc_2346f40a -> loc_2346f6f0
		}
		//loc_2346f40c
		else if (r7->keyCode == 130/*0x82*/)
		{
			sub_2346f7a8(-1);
			//->loc_2346f6f0
		}
		//loc_2346f416
		else if (r7->keyCode == 131/*0x83*/)
		{
			sub_2346f7a8(1);
			//->loc_2346f6f0
		}
		//loc_2346f422
		else if (r7->keyCode == 128/*0x80*/)
		{
			sub_2346f790(1);
			//->loc_2346f6f0
		}
		//loc_2346f42a
		else if (r7->keyCode == 129/*0x81*/)
		{
			sub_2346f790(-1);
			//->loc_2346f6f0
		}
		//loc_2346f438
		else if ((r7->keyCode >= 90/*0x5a*/) && (r7->keyCode < 97)) //S1...S8
		{
			sub_2340bf0c(&sp4);

			if (sp4.wData_0x28 != 0)
			{
				//0x2346f44e
				Data_23495970.wData_23495b8c = r7->keyCode - 89;

				if (Data_23495970.Data_23495b88 == 0)
				{
					Data_23495970.Data_23495974 = 3;
					Data_23495970.Data_23495978 = sub_2346f2ca;
					Data_23495970.Data_2349597c = 0;

					Data_23495970.Data_23495b88 = 10;
				}
				//loc_2346f46a
				Data_23495970.Data_23495b88--;

				if (Data_23495970.Data_23495b88 == 1)
				{
					//0x2346f472
					Data_23495970.Data_23495978 = sub_2346ee6c(&Data_23495970.Data_23495b88);
					//->loc_2346f6f0
				}
				//->loc_2346f3b6 -> loc_2346f6f0
			}
			//->loc_2346f3b6 -> loc_2346f6f0
		}
		//loc_2346f47e
		else if (r7->keyCode == 78/*0x4e*/) //Mode
		{
			sub_234810f6();
			//->loc_2346f6f0
		}
		//loc_2346f488
		else if (r7->keyCode == 70/*0x46*/) //USB
		{
			sub_2346ff0e();
			//->loc_2346f6f0
		}
		//loc_2346f492
		else if (r7->keyCode == 69/*0x45*/) //Radio
		{
			//r0 = 0;
			//->loc_2346f4b0: TODO
			if (0 == sub_2348112c(0))
			{
				//->loc_2346f49a
				sub_2346f77e();
				//->loc_2346f5dc
				Data_23495970.Data_23495974 = 1;
				//->loc_2346f6f0
			}
			//->loc_2346f6f0
		}
		//loc_2346f4a0
		else if (r7->keyCode == 54/*0x36*/)
		{
			//loc_2346f4a4
			sub_2346fac4(0);
			//->loc_2346f6f0
		}
		//loc_2346f4ac
		else if (r7->keyCode == 52/*0x34*/)
		{
			//loc_2346f4b0
			if (0 == sub_2348112c(52))
			{
				//->loc_2346f49a
				sub_2346f77e();
				//->loc_2346f5dc
				Data_23495970.Data_23495974 = 1;
				//->loc_2346f6f0
			}
			//->loc_2346f6f0
		}
		//loc_2346f4ba
		if (r7->keyCode == 55/*0x37*/)
		{
			//0x2346f4be

			//TODO
		}
		//loc_2346f550
		else if (r7->keyCode == 234/*0xea*/)
		{
			//->loc_2346f4a4
			sub_2346fac4(0);
			//->loc_2346f6f0
		}
		//0x2346f554
		else 
#endif		
			if (r7->keyCode == 82/*0x52*/) //Menu
		{
			menu_main_start();
			//->loc_2346f6f0
		}
		//loc_2346f55e
		else if (r7->keyCode == 12/*0x0c*/) //On-Off
		{
			powermode_set_state(2/*Off*/, sub_2343d572(), standby_thread);
			//->loc_2346f6f0
		}
		//loc_2346f572
#if 0
		else if ((r7->keyCode == 32/*0x20*/) //Up
				|| (r7->keyCode == 48/*0x30*/))
		{
			//loc_2346f57a
			channel_next();
			//->loc_2346f58c
			sub_2346f76c();
			//->loc_2346f6f0
		}
		//loc_2346f580
		else if ((r7->keyCode == 33/*0x21*/) //Down
				|| (r7->keyCode == 49/*0x31*/))
		{
			//loc_2346f588
			channel_prev();
			//loc_2346f58c
			sub_2346f76c();
			//->loc_2346f6f0
		}
		//loc_2346f592
		else if (r7->keyCode == 34/*0x22*/) // <->
		{
			//0x2346f596
			channel_swap();
			//->loc_2346f58c
			sub_2346f76c();
			//->loc_2346f6f0
		}
		//loc_2346f59c
		else if ((r7->keyCode == 17/*0x11*/) //Left
				|| (r7->keyCode == 65/*0x41*/)) //Vol-
		{
			//loc_2346f5a4
			//->loc_2346f5b4
			sub_2340c01c(1, -1);

			frontdisplay_start_text(sub_2346ed20);

			sub_2346f2e2();
			//->loc_2346f6f0
		}
		//loc_2346f5aa
		else if ((r7->keyCode == 16/*0x10*/) //Right
				|| (r7->keyCode == 64/*0x40*/)) //Vol+
		{
			//loc_2346f5b2
			//movs       r1, #0x1
			//loc_2346f5b4
			sub_2340c01c(1, 1);

			frontdisplay_start_text(sub_2346ed20);

			sub_2346f2e2();
			//->loc_2346f6f0
		}
		//loc_2346f5c6
		else if (r7->keyCode == 87/*0x57*/) //OK
		{
			if (Data_23495970.bData_23495b96 == 0)
			{
				//->loc_2346f49a
				sub_2346f77e();
				//->loc_2346f5dc
			}
			else
			{
				//loc_2346f5d2
				frontdisplay_start_text(sub_2346ec9c);

				sub_2346f7c0();
				//loc_2346f5dc
			}
			Data_23495970.Data_23495974 = 1;
			//->loc_2346f6f0
		}
		//loc_2346f5e2
		else if (r7->keyCode < 9)
		{
			//TODO
		}
		//loc_2346f654
		else if (r7->keyCode == 42/*0x2a*/)
		{
			//TODO

		}
		//loc_2346f65e
		else if (r7->keyCode == 44/*0x2c*/) //Info / EPG
		{
			//0x2346f666
#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "menu_root_on_event: Info Key\r\n");
				console_send_string(debug_string);
			}
#endif
			if ((Data_23495970.Data_23495974/*r3*/ == 0) ||
					(Data_23495970.Data_23495978/*r2*/ == sub_2346eeee) ||
					(Data_23495970.Data_23495978/*r2*/ == sub_2346f118) ||
					(Data_23495970.Data_23495978/*r2*/ == sub_2346f1a8))
			{
				//loc_2346f678
				//r0, #0x0
				//->loc_2346f684
				Data_23495970.bData_23495b98/*[r5, #0x8]*/ = 0;

				sub_2346f7ce();
				//->loc_2346f6f0
			}
			else
			{
				//loc_2346f67c
				if (Data_23495970.bData_23495b98/*[r5, #0x8]*/ != 0)
				{
					//->loc_2346f5d0 -> loc_2346f49a
					sub_2346f77e();
					//->loc_2346f5dc
					Data_23495970.Data_23495974 = 1;
					//->loc_2346f6f0
				}
				else
				{
					//0x2346f682
					Data_23495970.bData_23495b98/*[r5, #0x8]*/ = 1;

					sub_2346f7ce();
					//->loc_2346f6f0
				}
			}
		}
		//loc_2346f68c
		else if (r7->keyCode == 13/*0x0d*/) //Mute
		{
			//TODO

		}
		//loc_2346f6c6
		else if (r7->keyCode == 47/*0x2f*/) // I / i
		{
			//TODO

		}
		//loc_2346f6e4
		else if (r7->keyCode == 0xff)
		{
			if (Data_23495970.Data_2349597c != 0)
			{
				(Data_23495970.Data_2349597c)();
			}
		}
#endif
		//loc_2346f6f0
	}

	return 0;
}


/* 2346f708 - todo */
int sub_2346f708()
{
	uint8_t r4;
	struct
	{
		int fill_0[4]; //0
		int Data_16; //16
		int fill_20[2]; //20
	} sp4;

#if 1
	console_send_string("sub_2346f708 (menu_root_start) (todo.c): TODO\r\n");
#endif

	r4 = Data_23495970.bData_0;

#if 0
	sub_2340c970(1, &sp4);
#endif

	memset(&Data_23495970, 0, sizeof(Data_23495970)); //4*143);

#if 0
	if ((sp4.Data_16 << 16) < 0)
	{
		//0x2346f72c
		Data_23495970.Data_23495b9c = sub_2346f342;
		Data_23495970.bData_23495ba0 = 1;
	}
	//loc_2346f73a
	if (r4 != 0)
	{
		sub_2340d1c8(sub_2346f6f6);
		sub_2346f76c();
	}
#endif
	//loc_2346f748
	sub_2343d482(&Data_23495bac); //Add to the menu stack
	sub_2343d3ac(&Data_23495bac); //Initialize the menu

	return 0;
}


