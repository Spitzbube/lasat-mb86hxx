
#include "data.h"
#include "vfd.h"
#include "frontdisplay.h"
#include "sub_2340a6a0.h"
#include "clkpwr.h"
#include "hdmi.h"
#include "av.h"


OS_EVENT* Data_23492098 = 0; //23492098
void (*Data_2349209c)() = 0; //2349209c +4


int av_thread_stack[THREAD_STACK_SIZE_AV]; //2358b764 ->2358BDA4

typedef struct
{
	int Data_0; //0x2c
	int Data_4; //0x30
} Struct_2358bdd0;


typedef struct
{
	int Data_0; //0
	int Data_4; //4
	Struct_2358bdd0 Data_8; //8
	//16???
} Struct_23460180;


typedef struct
{
	uint32_t Data_0; //0
	int Data_4; //4
	uint8_t bData_8; //8
	//12???
} Struct_234601cc;



struct Struct_2358bda4
{
	int fill_0; //0
	Struct_20611068* Data_4; //4
	Struct_20611068* Data_8; //8
	int Data_12; //12
	int Data_16; //16
	int Data_20; //20
	int Data_24; //24
	int Data_28; //28
	int Data_32; //32
	int fill_36; //36 = 0x24
	int Data_0x28; //40 = 0x28
#if 1
	Struct_2358bdd0 Data_2358bdd0; //2358bdd0
#else
	int Data_0x2c; //44 = 0x2c //2358bdd0
	int Data_0x30; //48 = 0x30
#endif
	Struct_23410ea4 Data_0x34; //52 = 0x34 //2358bdd8
	Struct_235441b0 Data_0x40; //64 = 0x40
	Struct_235441b0* Data_0x5c; //92 = 0x5C
	int Data_0x60; //96 = 0x60
	int Data_0x64; //100 = 0x64
	int Data_0x68; //104 = 0x68
	int Data_0x6c; //108 = 0x6c
	int Data_0x70; //112 = 0x70
	int Data_0x74; //116 = 0x74
	void (*Data_0x78)(void*, void*); //120 = 0x78
	void (*Data_0x7c)(); //124 = 0x7c
	void (*frontDisplayTask)(); //128 = 0x80
	void (*pfPeriodicCheck)(); //132 = 0x84

} Data_2358bda4; //2358bda4

//2358bdd0



/* 23410398 - todo */
int sub_23410398(uint8_t* r4)
{
#if 0
	console_send_string("sub_23410398 (todo.c): TODO\r\n");
#endif

	Struct_23460180 sp4;
	uint8_t sp;

	//r7 = 0;
	*r4 = 0; //r7

	sub_23460180(&sp4, &sp);
	if (sp != 0)
	{
		//r6 = 1;
		if ((sp4.Data_8.Data_4 != 0) && (sp4.Data_0 != 2))
		{
			if (0 != memcmp(&Data_2358bda4.Data_2358bdd0, &sp4.Data_8, sizeof(Struct_2358bdd0)))
			{
				Data_2358bda4.Data_2358bdd0 = sp4.Data_8;
				Data_2358bda4.Data_0x28 = 0; //r7
				*r4 = 1; //r6

				if (Data_2358bda4.Data_0x5c->bData_0x17/*r1*/ != 0)
				{
					if (Data_2358bda4.Data_0x5c->bData_0x15/*r0*/ != 0)
					{
						//0x23410430
						sub_23428184(3);

						switch (sp4.Data_8.Data_0)
						{
						case 8:
							//loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;

						case 9:
							//0x23410448
							//r0, #0x5
							//->loc_23410498
							sub_2343471c(5);
							//->loc_23410614
							break;

						case 10:
							//loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;

						case 11:
							//0x23410460
							//r0, #0x6
							//->loc_23410498
							sub_2343471c(6);
							//->loc_23410614
							break;

						default:
							//loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;
						} //switch (sp4.Data_8.Data_0)
					} //if (Data_2358bda4.Data_0x5c->bData_0x15/*r0*/ != 0)
					else
					{
						//loc_23410468
						switch (sp4.Data_8.Data_0)
						{
						case 8:
							//loc_2341051c
							//r0, #0x3
							//->loc_23410490
							sub_23428184(3);
							//->loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;

						case 9:
							//loc_2341050c
							//r0, #0x2
							//->loc_23410490
							sub_23428184(2);
							//->loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;

						case 10:
							//loc_2341051c
							//r0, #0x3
							//->loc_23410490
							sub_23428184(3);
							//->loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;

						case 11:
							//loc_2341052c
							//r0, #0x7
							//->loc_23410490
							sub_23428184(7);
							//->loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;

						default:
							//loc_2341051c
							//r0, #0x3
							//->loc_23410490
							sub_23428184(3);
							//->loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;
						}
					}
				} //if (Data_2358bda4.Data_0x5c->bData_0x17/*r1*/ != 0)
				else
				{
					//loc_234104a0
					if (Data_2358bda4.Data_0x5c->bData_0x15/*r0*/ == 0)
					{
						//0x234104a8
						sub_23428184(2);

						switch (sp4.Data_8.Data_0)
						{
						case 8:
							//loc_234104bc
							//r0, #0x2
							//->loc_23410498
							sub_2343471c(2);
							//->loc_23410614
							break;

						case 9:
							//loc_234104cc
							//r0, #0x4
							//->loc_23410498
							sub_2343471c(4);
							//->loc_23410614
							break;

						case 10:
							//loc_234104bc
							//r0, #0x2
							//->loc_23410498
							sub_2343471c(2);
							//->loc_23410614
							break;

						case 11:
						case 14:
							//r0, #0x7
							//->loc_23410498
							sub_2343471c(7);
							//->loc_23410614
							break;

						case 15:
							//loc_234104cc
							//r0, #0x4
							//->loc_23410498
							sub_2343471c(4);
							//->loc_23410614
							break;

						default:
							//loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;
						}
					} //if (Data_2358bda4.Data_0x5c->bData_0x15/*r0*/ == 0)
					else
					{
						//loc_234104fc
						switch (sp4.Data_8.Data_0)
						{
						case 8:
						case 9:
							//loc_2341050c
							//r0, #0x2
							//->loc_23410490
							sub_23428184(2);
							//->loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;

						case 10:
							//loc_2341051c
							//r0, #0x3
							//->loc_23410490
							sub_23428184(3);
							//->loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;

						case 11:
							//loc_2341052c
							//r0, #0x7
							//->loc_23410490
							sub_23428184(7);
							//->loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;

						default:
							//loc_2341050c
							//r0, #0x2
							//->loc_23410490
							sub_23428184(2);
							//->loc_234104f4
							//r0, #0x1
							//->loc_23410498
							sub_2343471c(1);
							//->loc_23410614
							break;
						}
					}
				}
			} //if (0 != memcmp(&Data_2358bda4.Data_2358bdd0, &sp4.Data_8, sizeof(struct Struct_2358bdd0)))
			//loc_23410614
		} //if ((sp4.Data_8.Data_4 != 0) && (sp4.Data_0 != 2))
		else
		{
			//loc_23410534
			if (Data_2358bda4.Data_0x28 != sp4.Data_0)
			{
				//0x23410544
				Data_2358bda4.Data_0x28 = sp4.Data_0;
#if 0
				Data_2358bda4.Data_2358bdd0.Data_0 = 0;
				Data_2358bda4.Data_2358bdd0.Data_4 = 0;
#else
				memset(&Data_2358bda4.Data_2358bdd0, 0, sizeof(Struct_2358bdd0));
#endif

				*r4 = 1;

				if (Data_2358bda4.Data_0x5c->bData_0x17 == 0)
				{
					//0x2341056c
					gpio_set(Data_2358bda4.Data_4, 0);

					if ((Data_2358bda4.Data_0x28 > 2) &&
							(Data_2358bda4.Data_0x5c->bData_0x15 == 0))
					{
						//0x23410594
						sub_2343471c(2);
						//r0, #0x2
						//->loc_234105d4
						sub_23428184(2);
						//->loc_23410614
					}
					else
					{
						//loc_234105a4
						sub_2343471c(1);
						//->loc_234105d0
						//r0, #0x3
						//->loc_234105d4
						sub_23428184(3);
						//->loc_23410614
					}
				}
				else
				{
					//loc_234105b0
					if (Data_2358bda4.Data_0x28 > 2)
					{
						//0x234105bc
						sub_2343471c(1);

						gpio_set(Data_2358bda4.Data_4, 0xff);
						//loc_234105d0
						//r0, #0x3
						//->loc_234105d4
						sub_23428184(3);
						//->loc_23410614
					}
					else
					{
						//loc_234105dc
						if (Data_2358bda4.Data_0x5c->bData_0x15 != 0)
						{
							//0x234105e8
							sub_2343471c(3);
							//r0, #0x3
							//->loc_23410604
							sub_23428184(3);

							gpio_set(Data_2358bda4.Data_4, 0);
						}
						else
						{
							//loc_234105f8
							sub_2343471c(1);
							//r0, #0x2
							//loc_23410604
							sub_23428184(2);

							gpio_set(Data_2358bda4.Data_4, 0);
						}
					}
				}
			}
			//loc_23410614
		}
	} //if (sp != 0)
	//loc_23410614
	return sp;
}


/* 23410620 / 234175d8 - todo */
void sub_23410620(int r0)
{
	Struct_23427f24 sp_0x18;
	HDMI_VideoParams sp4;

#if 0
	console_send_string("sub_23410620 (todo.c): TODO\r\n");
#endif

	while (1)
	{
		//loc_2341062c
		if ((FREG(0xcb0100a0)[0] & 0xfff)/*VO_DISPPICPOS*/ ==
				(FREG(0xcb010008)[0]/*VO_DISPVERSIZE*/ + 2043))
		{
			break;
		}
	}
	//0x2341064c
	sp4.inputType = 2;
	sp4.outputType = 2;
	sp4.scanInfo = 1;
	sp4.activeFormat = 8; //ip
	sp_0x18.Data_0 = 3; //r2
	sp_0x18.Data_8 = 0;

	if ((Data_2358bda4.Data_0x5c->Data_4 & 2) == 0)
	{
		sp_0x18.Data_12 = 4; //r1
	}
	else
	{
		sp_0x18.Data_12 = 3; //r2
	}

	if (r0 == 7)
	{
		/*  5 1920x1080i @ 59.94/60Hz */
		sp4.videoCode = 5; //r2
		sp_0x18.Data_4 = 10;

		viout_configure_video_layer(4);
		viout_configure_sd(6);
		graphics_configure_osd_layer(5);
		//loc_234107d0
	}
	//loc_234106c4
	else if (r0 == 6)
	{
		/*  4 1280x 720p @ 59.94/60Hz */
		sp4.videoCode = 4; //r1
		sp_0x18.Data_4 = 9;

		viout_configure_video_layer(3);
		viout_configure_sd(5);
		graphics_configure_osd_layer(6);
		//loc_234107d0
	}
	//loc_234106f0
	else if (r0 == 4)
	{
		/*  7  720x 480i @ 59.94/60Hz */
		//r3 = 7;
		sp4.videoCode = 7; //r3
		sp_0x18.Data_4 = 8; //ip

		viout_configure_video_layer(0);
		viout_configure_sd(0);
		graphics_configure_osd_layer(4);
		//loc_234107d0
	}
	//loc_2341071c
	else if (r0 == 0)
	{
		/* 22  720x 576i @ 50Hz */
		sp4.videoCode = 22;
		sp_0x18.Data_4 = 6;

		viout_configure_video_layer(1);
		viout_configure_sd(1);
		graphics_configure_osd_layer(0);
		//loc_234107d0
	}
	//loc_2341074c
	else if (r0 == 1)
	{
		/* 18  720x 576p @ 50Hz */
		sp4.videoCode = 18;
		sp_0x18.Data_4 = 7; //r3

		viout_configure_video_layer(2);
		viout_configure_sd(2);
		graphics_configure_osd_layer(1);
		//loc_234107d0
	}
	//loc_23410778
	else if (r0 == 2)
	{
		/* 19 1280x 720p @ 50Hz */
		sp4.videoCode = 19;
		sp_0x18.Data_4 = 5; //r2

		viout_configure_video_layer(3);
		viout_configure_sd(3);
		graphics_configure_osd_layer(2);
		//loc_234107d0
	}
	//loc_234107a4
	else if (r0 == 3)
	{
		/* 20 1920x1080i @ 50Hz */
		sp4.videoCode = 20;
		sp_0x18.Data_4 = 4; //r1

		viout_configure_video_layer(4);
		viout_configure_sd(4);
		graphics_configure_osd_layer(3);
	}
	//loc_234107d0
	sub_2342803c(&sp_0x18, Data_23491da8);
	sub_2345f8f8();
	hdmi_SetVideoParameters(main_hHdmi, &sp4);
	hdmi_video_start(main_hHdmi);
}


/* 23410804 - complete */
int sub_23410804()
{
#if 0
	console_send_string("sub_23410804 (todo.c): TODO\r\n");
#endif

	uint8_t sp_0x20;
	Struct_234601cc sp_0x14;
	Struct_23460180 sp_0x4;

	int r4 = 0;

	sub_234601cc(&sp_0x14, &sp_0x20);
	if (sp_0x20 == 0)
	{
		return 1;
	}

	sub_23460180(&sp_0x4, &sp_0x20);
	if (sp_0x20 == 0)
	{
		return 1;
	}
	//loc_2341084c
//	int r1 = 1;
//	int r2 = 2;

	if (sp_0x14.Data_0 <= 576)
	{
		r4 = Data_2358bda4.Data_0x5c->wData_2 & 0x0f;
		//->loc_234108a0
	}
	else if (sp_0x14.Data_0 == 720)
	{
		r4 = (Data_2358bda4.Data_0x5c->wData_2 >> 4) & 0x0f;
		//loc_234108a0
	}
	else if (sp_0x14.Data_0 >= 1080)
	{
		r4 = (Data_2358bda4.Data_0x5c->wData_2 >> 8) & 0x0f;
		//loc_234108a0
	}

	if (r4 == 0)
	{
		//loc_234108a8
		int r0 = Data_2358bda4.Data_0x5c->Data_4;
		if ((r0 & 0x78000000) == 0)
		{
			//0x234108bc
			if (0 == sub_234251f4(main_hHdmi))
			{
				r4 = 1;
			}
			//->loc_23410990
		}
		else
		{
			//loc_234108d0
			if (((r0 >> 27) & 0x0f) != 1) //r1)
			{
				if (((r0 >> 27) & 0x0f) == 2) //r2)
				{
					//0x234108e4
					if (0 == sub_234251f4(main_hHdmi))
					{
						r4 = 1;
					}

					if (sp_0x4.Data_4 == 4)
					{
						//loc_23410900
						r4 = 4;
						//->loc_23410990
					}
					//loc_23410990
				}
				//loc_23410990
			}
			else
			{
				//loc_23410900
				r4 = 4;
				//->loc_23410990
			}
		}
	} //if (r4 == 0)
	//loc_23410908
	else if (r4 == 1)
	{
		//0x23410910
		int r0 = Data_2358bda4.Data_0x5c->Data_4;
		if ((r0 & 0x78000000) == 0)
		{
			r4 = 2;
			//->loc_23410990
		}
		else
		{
			//0x23410924
			if (((r0 >> 27) & 0x0f) == 1) //r1)
			{
				//loc_23410930
				r4 = 6;
				//->loc_23410990
			}
			//loc_23410938
			else if (((r0 >> 27) & 0x0f) == 2) //r2)
			{
				r4 = 2;

				if (sp_0x4.Data_4 == 4)
				{
					//->loc_23410930
					r4 = 6;
					//->loc_23410990
				}
				//->loc_23410990
			}
		}
	}
	//loc_23410950
	else if (r4 == 2)
	{
		//0x23410958
		int r0 = Data_2358bda4.Data_0x5c->Data_4;
		if ((r0 & 0x78000000) == 0)
		{
			r4 = 3;
			//->loc_23410990
		}
		else
		{
			//0x2341096c
			if (((r0 >> 27) & 0x0f) != 1) //r1)
			{
				//0x23410978
				if (((r0 >> 27) & 0x0f) == 2) //r2)
				{
					r4 = 3;

					if (sp_0x4.Data_4 == 4)
					{
						//loc_2341098c
						r4 = 7;
						//->loc_23410990
					}
					//->loc_23410990
				}
			}
			else
			{
				//loc_2341098c
				r4 = 7;
			}
		}
	}
	//loc_23410990
	if (Data_2358bda4.Data_0x60 == r4)
	{
		if (Data_2358bda4.Data_0x68 == ((Data_2358bda4.Data_0x5c->Data_4 >> 1) & 1))
		{
			//r0 = 0;
			//->loc_23410844
			return 0;
		}
	}
	//0x234109b4
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23410804: Data_2358bda4.Data_0x60=%d, r4=%d\r\n",
				Data_2358bda4.Data_0x60, r4);
		console_send_string(debug_string);
	}
#endif

	Data_2358bda4.Data_0x60 = r4;
	Data_2358bda4.Data_0x68 = (Data_2358bda4.Data_0x5c->Data_4 >> 1) & 1;

	sub_2341159c();

	return 1;
}


/* 234109d4 - todo */
void sub_234109d4()
{
#if 0
	console_send_string("sub_234109d4 (todo.c): TODO\r\n");
#endif

	int r2 = Data_2358bda4.Data_0x64;

	if (Data_2358bda4.Data_0x5c->bData_0x16 != r2)
	{
		Data_2358bda4.Data_0x64 = Data_2358bda4.Data_0x5c->bData_0x16;

		int r1 = Data_2358bda4.Data_0x5c->bData_0x16;

		if ((r1 == 0) || (r1 == 1))
		{
			gpio_set(Data_2358bda4.Data_8, r1);
			//r0, #0x6
			//->loc_23410a34
			sub_2342808c(6, Data_23491da4);
			//->loc_23410a48
		}
		//loc_23410a1c
		else if (r1 == 2)
		{
			//0x23410a24
			gpio_set(Data_2358bda4.Data_8, 0);

			sub_2342808c(4, Data_23491da4);
			//->loc_23410a48
		}
		//loc_23410a3c
		else if (r1 == 3)
		{
			gpio_set(Data_2358bda4.Data_8, 0);
		}
	}
	//loc_23410a48
	//r5 = 0;
	if (Data_2358bda4.Data_0x5c->bData_0x15 != Data_2358bda4.Data_0x6c)
	{
		Data_2358bda4.Data_0x28 = 0; //r5

		memset(&Data_2358bda4.Data_2358bdd0, 0, sizeof(Struct_2358bdd0));

		uint8_t sp;
		if (0 != sub_23410398(&sp))
		{
			sub_2345f8f8();
		}

		Data_2358bda4.Data_0x6c = Data_2358bda4.Data_0x5c->bData_0x15;
	}
	//loc_23410a90
	if (Data_2358bda4.Data_0x5c->bData_0x17 != Data_2358bda4.Data_0x70)
	{
		Data_2358bda4.Data_0x28 = 0; //r5

		uint8_t sp;
		if (0 != sub_23410398(&sp))
		{
			sub_2345f8f8();
		}

		Data_2358bda4.Data_0x70 = Data_2358bda4.Data_0x5c->bData_0x17;
	}
	//loc_23410ac4
}


/* 23410ac8 - complete */
void av_display_program_name(int r4)
{
#if 0
	console_send_string("av_display_program_name (todo.c): TODO\r\n");
#endif

//	int r6 = 0;
	uint8_t sp_0x6c = 0; //r6
	uint8_t chNumberString[8];
	uint8_t chNameString[32];
	Channel sp_0x1c;
	Transponder sp4;
	int r5 = 0;

	sub_234363d0(r4 + 1);

	if (r4 == -1)
	{
		chNameString[0] = ' ';
		chNameString[1] = 0;
		//->loc_23410bd8
		sub_2341a290(chNameString, 0);
	}
	else
	{
		//0x23410b00
		sub_2340bf94((uint16_t)r4, &sp_0x1c, &sp4);

		int r0 = sub_23458874();
		if (r0 != 0)
		{
			//0x23410b20
			if (Data_2358bda4.Data_24 == 0)
			{
				Data_2358bda4.Data_20 = r4;
			}

			if (Data_2358bda4.Data_20 == r4)
			{
				sp_0x6c = (char)0x1b;
			}
			else
			{
				sp_0x6c = (char)0x19;
			}
		}
		//loc_23410b40
		Data_2358bda4.Data_24 = r0;

		if (sp_0x6c != 0)
		{
			//0x23410b50
			sub_2341a290(&sp_0x6c, 0);

			r5 = 1;
		}
		//loc_23410b60
		sprintf(chNumberString, "%d ", r4 + 1);

		sub_2341a290(chNumberString, r5);

		uint8_t* r1 = sp_0x1c.Data_0x10.service_name;
		if ((r1[0] != 0) && (r1[0] < 0x21))
		{
			r1++;
		}

		uint8_t ch = r1[0];
		if (ch == 0)
		{
			//loc_23410be0
			return;
		}
		//0x23410b9c
		if (ch < 0x20)
		{
			//0x23410ba4
			ch = *(++r1);
			if (ch == 0)
			{
				//loc_23410be0
				return;
			}
		}
		//loc_23410bb0
		ch = r1[0];
		if (ch == 0xff)
		{
			//loc_23410be0
			return;
		}

		strncpy(chNameString, r1, 30);
		int len = strlen(chNumberString);
		len += r5;

		sub_2341a290(chNameString, len & 0xff);
	}
}


/* 23410be8 - complete */
void sub_23410be8(int* r6, int* r7)
{
#if 0
	console_send_string("sub_23410be8 (todo.c): TODO\r\n");
#endif

	uint8_t sp;
//	int r5 = 0;

	if ((Data_2358bda4.Data_12 != *r6) ||
			(Data_2358bda4.Data_16 != *r7))
	{
		extern void sub_2340c0dc(); 

		Data_2358bda4.Data_0x7c = sub_2340c0dc;
		Data_2358bda4.Data_0x74 = 100;
		Data_2358bda4.Data_28 = 0; //r5

		av_display_program_name(Data_2358bda4.Data_12 - 1);

		*r6 = Data_2358bda4.Data_12;
		*r7 = Data_2358bda4.Data_16;
	}
	//loc_23410c44
	if (Data_2358bda4.Data_28 != 0)
	{
		av_display_program_name(Data_2358bda4.Data_12 - 1);

		Data_2358bda4.Data_28 = 0; //r5
	}
	//loc_23410c60
	if (Data_2358bda4.Data_32 != 0)
	{
		sub_234364a4(0, 0, 0, Data_2358bda4.Data_32 & 1);

		Data_2358bda4.Data_32--;

		return;
	}
	//loc_23410c90
	int r0 = sub_23410398(&sp);
	if (r0 != 0)
	{
		r0 = sub_23410804();
		if (r0 == 0)
		{
			if (sp != 0)
			{
				sub_2345f8f8();
			}
			//loc_23410cdc
		}
		//loc_23410cdc
	}
	else
	{
		//loc_23410cbc
		if (((Data_2358bda4.Data_0x5c->Data_4 >> 1) & 1) != Data_2358bda4.Data_0x68)
		{
			Data_2358bda4.Data_0x68 = (Data_2358bda4.Data_0x5c->Data_4 >> 1) & 1;

			sub_2341159c();
		}
	}
	//loc_23410cdc
	sub_234109d4();
}


/* 23410ce4 - complete */
void av_periodic_check()
{
#if 0
	console_send_string("av_periodic_check (todo.c): TODO\r\n");
#endif

	channel_periodic_check(0);

	sub_23460c88();

	sub_2345b99c();
}


/* 23410cfc - todo */
void av_thread()
{
	int r0;
	uint8_t sp_0x14;
	int sp_0x10 = 0;
	int sp_0xc = 0;
	Struct_20401328 sp;

	if (Data_2358bda4.Data_0x34.Data_4 != 0xff)
	{
		sp.dwOutFunction = 0;
		sp.dwInFunction = 0xff;
		sp.bPin = Data_2358bda4.Data_0x34.Data_4;

		gpio_open(&sp, &Data_2358bda4.Data_4);
	}

	if (Data_2358bda4.Data_0x34.Data_8 != 0xff)
	{
		sp.dwOutFunction = 1;
		sp.dwInFunction = 0xff;
		sp.bPin = Data_2358bda4.Data_0x34.Data_8;

		gpio_open(&sp, &Data_2358bda4.Data_8);
	}
	//loc_23410d5c
	sub_2340c970(1, &Data_2358bda4.Data_0x40);

	Data_2358bda4.Data_12 = 0;
	Data_2358bda4.Data_16 = 0;
	Data_2358bda4.Data_20 = 0;
	Data_2358bda4.Data_24 = 0;
	Data_2358bda4.Data_28 = 0;
	Data_2358bda4.Data_32 = 0;
	Data_2358bda4.Data_0x6c = Data_2358bda4.Data_0x40.bData_0x15;
	Data_2358bda4.Data_0x70 = Data_2358bda4.Data_0x40.bData_0x17;
	Data_2358bda4.Data_0x64 = -1;
	Data_2358bda4.Data_0x60 = 3; /* HDMI: 20 1920x1080i @ 50Hz */
	Data_2358bda4.Data_0x68 = (Data_2358bda4.Data_0x40.Data_4 & 3) / 2;
	Data_2358bda4.Data_0x78 = 0;
	Data_2358bda4.pfPeriodicCheck = 0;

	sp_0x10 = 0;
	sp_0xc = 0;

	r0 = ((sub_23428178(Data_23491da8) - 4) != 0)? 1: 0;
	if (Data_2358bda4.Data_0x68 != r0)
	{
		sub_2341159c();
	}
	//r5 = dword_23492098
	while (1)
	{
		//loc_23410de4 / loc_23417d84
#if 0
		console_send_string("av_thread (todo.c): TODO\r\n");
#endif

		sub_2340c970(1, &Data_2358bda4.Data_0x40);

		if (Data_2358bda4.pfPeriodicCheck != 0)
		{
			(Data_2358bda4.pfPeriodicCheck)();
		}

		if (Data_2349209c != 0)
		{
			(Data_2349209c)();
		}

		OSSemPend(Data_23492098, 0, &sp_0x14);

		if (Data_2358bda4.Data_0x78 != 0)
		{
			(Data_2358bda4.Data_0x78)(&sp_0x10, &sp_0xc);
		}

		if (Data_2358bda4.Data_0x7c != 0)
		{
			if (Data_2358bda4.Data_0x74 != 0)
			{
				Data_2358bda4.Data_0x74--;
			}
			else
			{
				(Data_2358bda4.Data_0x7c)();

				Data_2358bda4.Data_0x7c = 0;
			}
			//loc_23410e54
		}
		//loc_23410e54
		if (Data_2358bda4.frontDisplayTask != 0)
		{
			(Data_2358bda4.frontDisplayTask)();
		}

		sub_2342e3bc();

		OSSemPost(Data_23492098);

		rtos_task_wait(5);
		//->loc_23410de4
	}
}


/* 23410ea4 - todo */
int av_init(Struct_23410ea4* r4)
{
	if (Data_23492098 != 0)
	{
		return 0xff;
	}

	memcpy(&Data_2358bda4.Data_0x34, r4, sizeof(Struct_23410ea4));

	Data_2358bda4.Data_0x5c = &Data_2358bda4.Data_0x40;

	Data_23492098 = OSSemCreate(1);

	OSTaskCreateExt(av_thread, 0, &av_thread_stack[THREAD_STACK_SIZE_AV-1],
			r4->threadPrio & 0xff, r4->threadPrio & 0xffff,
			av_thread_stack, THREAD_STACK_SIZE_AV, "AV ", 3);

	return 0;
}


/* 23410f28 - todo */
void sub_23410f28(int r5)
{
	uint8_t sp;

#if 0
	console_send_string("sub_23410f28 (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_23492098, 0, &sp);

	if (r5 == 0)
	{
		Data_2358bda4.Data_0x78 = 0;
		Data_2358bda4.Data_0x7c = 0;
	}
	else
	{
		Data_2358bda4.Data_0x78 = sub_23410be8;
	}

	OSSemPost(Data_23492098);
}


/* 23410f64 / 23417f00 - todo */
void sub_23410f64(int channelNr, int r6)
{
	uint8_t err;

#if 0
	console_send_string("sub_23410f64 (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_23492098, 0, &err);

	Data_2358bda4.Data_12 = channelNr + 1;
	Data_2358bda4.Data_16 = r6;

	OSTimeDlyResume(Data_2358bda4.Data_0x34.threadPrio & 0xff);

	OSSemPost(Data_23492098);
}


/* 23410fe4 - complete */
void sub_23410fe4()
{
	uint8_t sp;

#if 0
	console_send_string("sub_23410fe4 (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_23492098, 0, &sp);

	Data_2358bda4.Data_32 = 3;

	OSTimeDlyResume(Data_2358bda4.Data_0x34.threadPrio & 0xff);

	OSSemPost(Data_23492098);
}


/* 234110a0 - todo */
void av_switch_powermode(int powerdown)
{
	uint8_t sp_0xc;
	Struct_23437974 sp;

#if 0
	console_send_string("av_switch_powermode (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_23492098, 0, &sp_0xc);

	if (powerdown != 0)
	{
		//0x234110cc
		if (Data_2358bda4.Data_0x7c != 0)
		{
			(Data_2358bda4.Data_0x7c)();

			Data_2358bda4.Data_0x7c = 0;
		}
		//loc_234110e0
		Data_2358bda4.Data_0x78 = 0;
		Data_2358bda4.frontDisplayTask = 0;
		Data_2358bda4.Data_0x64 = 0;
		Data_2358bda4.pfPeriodicCheck = 0;

		channel_periodic_check(1);

		sub_2343655c(2);

		sub_23437d58();

		gpio_set(Data_2358bda4.Data_4, 1);
		gpio_set(Data_2358bda4.Data_8, 0);
	} //if (powerdown != 0)
	else
	{
		//loc_23411128
		Data_2358bda4.Data_0x78 = sub_23410be8;
		Data_2358bda4.frontDisplayTask = frontdisplay_task;
		Data_2358bda4.pfPeriodicCheck = av_periodic_check;
		Data_2358bda4.Data_0x28 = 0;
		memset(&Data_2358bda4.Data_2358bdd0, 0, 8);
#if 0
		Data_2358bda4.Data_0x2c = 0; //2358bdd0
		Data_2358bda4.Data_0x30 = 0;
#endif

		vfd_init(&sp);

		av_display_program_name(Data_2358bda4.Data_12 - 1);
		//->loc_23411114
		gpio_set(Data_2358bda4.Data_4, 0);
	}

	OSSemPost(Data_23492098);
}


/* 234111a8 - complete */
int av_get_language()
{
#if 0
	console_send_string("av_get_language (todo.c): TODO\r\n");
#endif

	if (Data_2358bda4.Data_0x5c != 0)
	{
		return Data_2358bda4.Data_0x5c->menuLanguage;
	}

	return 0;
}


/* 2341151c - complete */
void sub_2341151c(uint8_t* r5)
{
	uint8_t err;

#if 0
	console_send_string("sub_2341151c (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_23492098, 0, &err);

	sub_2341a290(r5, 0);;

	OSSemPost(Data_23492098);
}


/* 23411550 - complete */
void sub_23411550()
{
	uint8_t sp;

#if 0
	console_send_string("sub_23411550 (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_23492098, 0, &sp);

	Data_2358bda4.Data_28 = 1;

	OSSemPost(Data_23492098);
}


/* 2341159c / 23418538 - complete */
void sub_2341159c()
{
#if 0
	console_send_string("sub_2341159c (todo.c): TODO\r\n");
#endif

	int r4 = FREG(0xca000028)[0]; //FREG_CLKPWR_FD2DELTA

	sub_23410620(Data_2358bda4.Data_0x60);

	if (FREG(0xca000028)[0] != r4)
	{
		sub_234097b8();
	}
}


