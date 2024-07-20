
#include <stdint.h>
#include "ucos_ii.h"
#include "sys_services.h"
#include "clkpwr.h"
#include "viout.h"


const struct
{
	int Data_0; //0
	int Data_4; //4
	//8
}
Data_23489b3c/*hfilter675*/[/*size???*/] = //23489b3c
{
	{0x8800051d, 0x0000717f},
	{0x95000615, 0x00007172},
	{0xa7000715, 0x0000715f},
	{0xb9000715, 0x0000514e},
	{0xcb00070d, 0x0000513d},
	{0xd900060e, 0x0000352c},
	{0xe6000507, 0x0000191d},
	{0xf3000307, 0x00001d0e},
	{0xfe020000, 0x00000000}, //8 = 23489B7C
	{0xfe0efc01, 0x000003f4},
	{0xf81ff802, 0x000005ea},
	{0xed31f40a, 0x000027e3},
	{0xe044ef13, 0x000028df},
	{0xd159ea1b, 0x000048dc},
	{0xc06ee623, 0x000048db},
	{0xad84e12b, 0x000067dc},
	{0x9999de33, 0x000066de},
	{0x84addc3b, 0x000065e1},
	{0x6ec0db42, 0x000064e6},
	{0x59d1dc42, 0x000063ea},
	{0x44e0df41, 0x000062ef},
	{0x31ede339, 0x000041f4},
	{0x1ff8ea28, 0x000040f8},
	{0x0efef418, 0x000020fc},
	{0x00ff0000, 0x00000000},
	{0x00f30ee8, 0x0000e003},
	{0x00e61dc8, 0x0000e005},
	{0x00d92ca9, 0x0000c106},
	{0x00cb3d8a, 0x0000a107},
	{0x00b94e8a, 0x0000a207},
	{0x00a75f8b, 0x0000a207},
	{0x0095728b, 0x0000a206},
	{0x00887f8b, 0x0000a305},
};


//234926a4
uint8_t bData_234926a4 = 0; //234926a4 +0
int Data_234926a8 = 0; //234926A8 +4
void (*Data_234926ac)() = 0; //234926AC +8
uint32_t Data_234926b0 = 0; //234926B0 +0xc
uint32_t Data_234926b4 = 0; //234926b4 +0x10
uint32_t Data_234926b8 = 0; //234926B8 +0x14
int Data_234926bc = 0; //234926bc +0x18
int Data_234926c0 = 0; //234926c0 +0x1c
int Data_234926c4 = 0; //234926c4 +0x20
int Data_234926c8 = 0; //234926c8 +0x24
int Data_234926cc = 0; //234926cc +0x28
int Data_234926d0 = 0; //234926d0 +0x2c
int Data_234926d4 = 0; //234926d4 +0x30
int Data_234926d8 = 0; //234926d8 +0x34
int Data_234926dc = 0; //234926dc +0x38
int Data_234926e0 = 0; //234926e0 +0x3c
int Data_234926e4 = 0; //234926e4 +0x40
int Data_234926e8 = 0; //234926e8 +0x44
int Data_234926ec = 0; //234926ec +0x48
int Data_234926f0 = 0; //234926f0 +0x4c
int Data_234926f4 = 0; //234926f4 +0x50
int Data_234926f8 = 0; //234926f8 +0x54
int Data_234926fc = 0; //234926fc +0x58
int Data_23492700 = 0; //23492700 +0x5c
int Data_23492704 = 0; //23492704 +0x60
int Data_23492708 = 0; //23492708 +0x64
int Data_2349270c = 0; //2349270c +0x68
int Data_23492710 = 0; //23492710 +0x6c
int Data_23492714 = 0; //23492714 +0x70
int Data_23492718 = 0; //23492718 +0x74
int Data_2349271c = 0; //2349271c +0x78
int Data_23492720 = 0; //23492720 +0x7c
int Data_23492724 = 0; //23492724 +0x80
int Data_23492728 = 0; //23492728 +0x84
int Data_2349272c = 0; //2349272c +0x88
int Data_23492730 = 0; //23492730 +0x8c
int Data_23492734 = 0; //23492734 +0x90
int Data_23492738 = 0; //23492738 +0x94
int Data_2349273c = 0; //2349273C +0x98


int VO_VohfltMirror[128]; //235f0cfc
int VO_Osd1hfltMirror[128]; //235f0efc -> 235F10FC
int VO_Osd2hfltMirror[128]; //235f10fc -> 235F12FC
int VO_SdhfltMirror[64/*size???*/]; //235f12fc -> 235F13FC
int VO_SdvfltMirror[64/*size???*/]; //235f13fc -> 235F14FC
int VO_Osd2clutMirror[256]; //235f14fc
int VO_CursorclutMirror[256/*size???*/]; //235f18fc

int32_t Data_235f3434[16]; //235f3434
int32_t Data_235f3474[16]; //235F3474 -> 235F34B4

struct Struct_235f34b4
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	int Data_0xc; //12
	int Data_0x10; //16
	int Data_0x14; //20
	int Data_0x18; //24
	int Data_0x1c; //28
	//32
} Data_235f34b4[16]; //235f34b4



void sub_2342f774(Struct_2342f774* r4, uint32_t r6, uint32_t sb, uint32_t sl);
void VO_SetOsdfiltermode_Verfilteron(int a, int b);
void VO_SetSdvflt_Sdvflt(int a, int b);
void VO_SetSdhflt_Sdhflt(int a, int b);


/* 2342e4cc - todo */
int sub_2342e4cc(uint32_t r0, uint32_t r1, uint32_t r2)
{
#if 0
	console_send_string("sub_2342e4cc (todo.c): TODO\r\n");
#endif

	uint32_t r4 = (r2 & 0x7f) + r1;
	uint32_t ip = r2 >> 7;
	uint32_t r1_ = (r1 + r2) & 0x7f;
	uint32_t r3 = r2 - (ip << 7) + 4;
	uint32_t lr = 0;
	if (r1_ >= 8)
	{
		lr = 0x7f;
		//->loc_2342e508
	}
	else
	{
		r3 = r3 - r1_;
		if (r3 < 4)
		{
			r3 = 4;
		}
	}
	//loc_2342e508
	int r1__ = ((r4 + lr) >> 7) - 1;
	if ((r3 - 0x80) <= 3)
	{
		r3 = 0x7f;
	}

	if (r1__ == 0)
	{
		r1__ = 1;
	}

	FREG(0xcb00002c)[0] = r0; //VO_VOHORDISPPIXEL
	FREG(0xcb000030)[0] = r4; //VO_VOHORREADPIXEL
	FREG(0xcb000010)[0] = r1__; //VO_VOHSIZE
	FREG(0xcb00000c)[0] = ip; //VO_VOHSTARTPOS
	FREG(0xcb000034)[0] = r3; //VO_VOINITIALSHIFT

	return r0;
}


/* 2342e544 - todo */
void sub_2342e544(int r6, int b, int r5, int sp_0x20, int r7)
{
#if 0
	console_send_string("sub_2342e544 (todo.c): TODO\r\n");
#else

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2342e544: r6=%d, r1=%d, r5=%d, sp_0x20=%d, r7=%d\r\n",
				r6, r1, r5, sp_0x20, r7);
		console_send_string(debug_string);
	}
#endif


	int r4 = 0;
	int sp_0x8 = (r5 * 3) + b;
	int sp_0x10 = r6 * sp_0x8;
	int sp_0xc = r6 * r5;

	for (r4 = 0; r4 < 17; r4++)
	{
		//loc_2342e578
		//r2, =0x235f34b4
		uint32_t r3 = sp_0x10/*(r6 * sp_0x8)*/ + (r4 * r5);
		int sb = 0;
		//int r0 = 0; //sb
		for (int r0 = 0; r0 < 8; r0++)
		{
			//loc_2342e58c
			int r1;

			if ((sp_0xc/*(r6 * r5)*/ * r0) < r3)
			{
				//0x2342e59c
				int ip = (r5 * r0) + sp_0x20;
				r1 = ip - sp_0x8;
				ip = r5 * r4;
				r1 = r1 * r6;
				r1 = r1 - ip;
				//->loc_2342e5d8
			}
			else
			{
				//loc_2342e5bc
				int ip = r5 * r0;
				ip = sp_0x20 - ip;
				r1 = sp_0x8 + ip;
				r1 = r1 * r6;
				r1 = (r5 * r4) + r1;
			}
			//loc_2342e5d8
			int ip = r0 + (r4 * 8);
			if (r1 < 0)
			{
				r1 = 0;
			}
			sb += r1;

			((uint32_t*)&Data_235f34b4)[ip] = r1;

		} //for (int r0 = 0; r0 < 8; r0++)
		//0x2342e5f8
		int sl = 0;
		int fp = 0;
		int sp = 0;

		for (int r8 = 0; r8 < 8; r8++)
		{
			//loc_2342e608
			int sp4 = r8 + (r4 * 8);
			uint32_t r0 = ((uint32_t*)&Data_235f34b4)[sp4];
			r0 = (r0 << 8) / sb;
			if (r0 > fp)
			{
				fp = r0;
				sp = r8;
			}

			sl += r0;

			((uint32_t*)&Data_235f34b4)[sp4] = r0;

		} //for (int r8 = 0; r8 < 8; r8++)
		//0x2342e64c
		if (sl != 0x100)
		{
			//0x2342e654
			int r0 = sp + (r4 * 8);
			uint32_t r2 = ((uint32_t*)&Data_235f34b4)[r0];
			r2 = sl - r2;
			r2 = 0x100 - r2;
			((uint32_t*)&Data_235f34b4)[r0] = r2;
		}
		//loc_2342e670
		if (r7 == 6)
		{
			//0x2342e678

			//TODO!!!
		}
		//loc_2342e6a4
		else if (r7 == 4)
		{
			//0x2342e6ac
			int r1 = Data_235f34b4[r4].Data_0;
			int r2 = Data_235f34b4[r4].Data_4;
			int r3 = Data_235f34b4[r4].Data_8;

			r1 = r1 + r2;
			r1 = r1 + r3;

			Data_235f34b4[r4].Data_8 = r1;

			r1 = Data_235f34b4[r4].Data_0x18;
			r2 = Data_235f34b4[r4].Data_0x1c;
			r3 = Data_235f34b4[r4].Data_0x14;

			r1 = r1 + r2;
			r1 = r1 + r3;

			Data_235f34b4[r4].Data_0x14 = r1;
			//->loc_2342e730
		}
		//loc_2342e6e4
		else if (r7 == 2)
		{
			//0x2342e6ec

			//TODO!!!
		}
		//loc_2342e730
		int ip = 0xfe;
		int lr = 0xff;
		for (int r0 = 0; r0 < 8; r0++)
		{
			//loc_2342e744
			int r1 = r0 + (r4 * 8);
			if (((uint32_t*)&Data_235f34b4)[r1] == 0xff)
			{
				((uint32_t*)&Data_235f34b4)[r1] = ip; //0xfe

				Data_235f34b4[r4].Data_0x10 += 1;
			}

			if (((uint32_t*)&Data_235f34b4)[r1] == 0x100)
			{
				((uint32_t*)&Data_235f34b4)[r1] = lr; //0xff
			}

		} //for (int r0 = 0; r0 < 8; r0++)
		//0x2342e778
		if (r7 == 8)
		{
			//0x2342e780
			int r8 = /*r0*/0 + (r4 * 8);
			int r2 = /*r1*/7 + (r4 * 8);
			//->loc_2342e79c
			for (int r0 = 0; r0 < 4; r0++)
			{
				//loc_2342e794
				if (r0 == 0)
				{
					//loc_2342e79c
					uint32_t r1 = ((uint32_t*)&Data_235f34b4)[r8];
					if (r1 > 3)
					{
						//0x2342e7a8
						int lr = ((uint32_t*)&Data_235f34b4)[r8 + 1];
						r1 = r1 + lr;
						r1 = r1 - 3;
						((uint32_t*)&Data_235f34b4)[r8 + 1] = r1;
						((uint32_t*)&Data_235f34b4)[r8] = 3;
					}
					//loc_2342e7c4
					r1 = ((uint32_t*)&Data_235f34b4)[r2];
					if (r1 > 3)
					{
						//0x2342e7d4
						int lr = ((uint32_t*)&Data_235f34b4)[r2 - 1];
						r1 = r1 + lr;
						r1 = r1 - 3;
						((uint32_t*)&Data_235f34b4)[r2 - 1] = r1;
						((uint32_t*)&Data_235f34b4)[r2] = 3;
					}
					//loc_2342e8b8
				} //if (r0 == 0)
				//loc_2342e7f0
				else if (r0 == 1)
				{
					//0x2342e7f8
					int r1 = r0 + (r4 * 8);
					uint32_t ip = ((uint32_t*)&Data_235f34b4)[r1];
					if (ip > 15)
					{
						//0x2342e808
						int sb = ((uint32_t*)&Data_235f34b4)[r1 + 1];
						ip = ip + sb;
						ip = ip - 15;
						((uint32_t*)&Data_235f34b4)[r1 + 1] = ip;
						((uint32_t*)&Data_235f34b4)[r1] = 15;
					}
					//loc_2342e824
					r1 = 6;
					r1 = r1 + (r4 * 8);
					ip = ((uint32_t*)&Data_235f34b4)[r1];
					if (ip > 15)
					{
						//0x2342e838
						int sb = ((uint32_t*)&Data_235f34b4)[r1 - 1];
						ip = ip + sb;
						ip = ip - 15;
						((uint32_t*)&Data_235f34b4)[r1 - 1] = ip;
						((uint32_t*)&Data_235f34b4)[r1] = 15;
					}
					//loc_2342e8b8
				}
				//loc_2342e854
				else if (r0 == 2)
				{
					//0x2342e85c
					int r1 = r0 + (r4 * 8);
					uint32_t lr = ((uint32_t*)&Data_235f34b4)[r1];
					if (lr > 0x7f)
					{
						//0x2342e86c
						int sb = ((uint32_t*)&Data_235f34b4)[r1 + 1];
						lr = lr + sb;
						lr = lr - 0x7f;
						((uint32_t*)&Data_235f34b4)[r1 + 1] = lr;
						((uint32_t*)&Data_235f34b4)[r1] = 0x7f;
					}
					//loc_2342e888
					r1 = 5;
					r1 = r1 + (r4 * 8);
					uint32_t ip = ((uint32_t*)&Data_235f34b4)[r1];
					if (ip > 0x7f)
					{
						//0x2342e89c
						int sb = ((uint32_t*)&Data_235f34b4)[r1 - 1];
						ip = ip + sb;
						ip = ip - 0x7f;
						((uint32_t*)&Data_235f34b4)[r1 - 1] = ip;
						((uint32_t*)&Data_235f34b4)[r1] = 0x7f;
					}
					//loc_2342e8b8
				}
				//loc_2342e8b8
			} //for (int r0 = 0; r0 < 4; r0++)
			//loc_2342e8c4
		}
		//loc_2342e8c4
	} //for (r4 = 0; r4 < 17; r4++)
	//0x2342e8d0
#endif
}


/* 2342e8d8 - todo */
void sub_2342e8d8(int r4, int r6, int r2, int r3, int sp_0x38_arg_8, int sl/*sp_0x38_arg_c*/, uint32_t r5/*sp_0x38_arg_10*/)
{
#if 0
	console_send_string("sub_2342e8d8 (todo.c): TODO\r\n");
#else
	int sp8;

	Data_234926e8 = (r4 + 0xfff) >> 12;

	switch (r5)
	{
	case 0:
		Data_234926ec = 0xcb002000; //VO_VOHFLT
		Data_2349270c = 8; //ip
		break;

	case 1:
		Data_234926ec = 0xcb012800; //VO_SDVFLT
		Data_2349270c = 0x100;
		break;

	case 2:
		Data_234926ec = 0xcb006000; //VO_OSD1HFLT
		Data_2349270c = 8; //ip
		break;

	default:
		Data_234926ec = 0xcb00a000; //VO_OSD2HFLT
		Data_2349270c = 8; //ip
		break;
	}
	//loc_2342e944
	Data_23492700 = r2;
	Data_23492704 = Data_23492700 + r3;

	if (r4 < r6)
	{
		//0x2342e95c
		Data_234926cc = r6 * 0.7;

		if (Data_234926cc < r4)
		{
			//loc_2342e980
			Data_234926cc = r4;
		}
		//loc_2342e984
	}
	else
	{
		//loc_2342e980
		Data_234926cc = r4;
	}
	//loc_2342e984
	if (r5 < 2)
	{
		sub_2342e544(Data_234926e8 & 0xff, Data_23492700, r4, Data_234926cc, 4);
	}
	else
	{
		sub_2342e544(Data_234926e8 & 0xff, Data_23492700, r4, Data_234926cc, 2);
	}
	//0x2342e9a4
	//r8 = 0;
	//r0 = 0;
	//fp, =0x235f34b4
	//->loc_2342ea7c
	for (Data_234926d4 = 0; Data_234926d4 < Data_234926e8; Data_234926d4++)
	{
		//loc_2342e9b8
		if ((sl == 1) && (r5 == 0))
		{
			Data_234926d0 = (Data_234926d4 & 0x0c);
		}
		else
		{
			Data_234926d0 = Data_234926d4;
		}

		if (r4 >= r6)
		{
			//0x2342e9d4
			int r2 = Data_235f34b4[Data_234926d0].Data_8;
			r2 += (Data_235f34b4[Data_234926d0].Data_0xc << 8);
			r2 += (Data_235f34b4[Data_234926d0].Data_0x10 << 16);
			//->loc_2342ea14
			r2 += (Data_235f34b4[Data_234926d0].Data_0x14 << 24);
			Data_23492710 = r2;
		}
		else
		{
			//loc_2342e9f4
			int i = Data_234926e8 - Data_234926d0;

			int r2 = Data_235f34b4[i].Data_8;
			r2 += (Data_235f34b4[i].Data_0xc << 8);
			r2 += (Data_235f34b4[i].Data_0x10 << 16);
			//loc_2342ea14
			r2 += (Data_235f34b4[i].Data_0x14 << 24);
			Data_23492710 = r2;
		}
		//0x2342ea1c
#if 1
		if (r5 < 2)
		{
			//0x2342ea28
			FREG(Data_234926ec + Data_234926d4 * 16)[0] = Data_23492710;

			if (r5 == 1)
			{
				FREG(Data_234926ec + 8 + Data_234926d4 * 16)[0] = Data_23492710;
			}
			//->loc_2342ea70
		}
		else
		{
			//loc_2342ea48
			FREG(Data_234926ec + Data_234926d4 * 16)[0] = (Data_23492710 & 0xffff) + (Data_23492710 << 16);
			FREG(Data_234926ec + 4 + Data_234926d4 * 16)[0] = (Data_23492710 & 0xffff) + (Data_23492710 << 16);
		}
#endif
		//loc_2342ea70
	} //for (Data_234926d4 = 0; Data_234926d4 < Data_234926e8; Data_234926d4++)
	//0x2342ea88
	if (r5 < 2)
	{
		sub_2342e544(Data_234926e8 & 0xff, Data_23492704, r4, Data_234926cc, 4);
	}
	else
	{
		sub_2342e544(Data_234926e8 & 0xff, Data_23492704, r4, Data_234926cc, 2);
	}
	//->loc_2342eba0
	for (Data_234926d4/*r0*/ = 0; Data_234926d4 < Data_234926e8/*r7*/; Data_234926d4++)
	{
		//loc_2342eabc
		if ((sl == 1) && (r5 == 0))
		{
			Data_234926d0 = Data_234926d4/*r0*/ & 0x0c;
		}
		else
		{
			Data_234926d0 = Data_234926d4;
		}

		if (r4 >= r6)
		{
			//0x2342eadc
			int r2 = Data_235f34b4[Data_234926d0].Data_8;
			r2 += (Data_235f34b4[Data_234926d0].Data_0xc << 8);
			r2 += (Data_235f34b4[Data_234926d0].Data_0x10 << 16);
			//->loc_2342eb14
			r2 += (Data_235f34b4[Data_234926d0].Data_0x14 << 24);
			Data_23492710 = r2;
		}
		else
		{
			//loc_2342eaf8
			//int i = Data_234926e8/*r7*/ - Data_234926d0;

			int r2 = Data_235f34b4[/*i*/Data_234926e8/*r7*/ - Data_234926d0].Data_8;
			r2 += (Data_235f34b4[/*i*/Data_234926e8/*r7*/ - Data_234926d0].Data_0xc << 8);
			r2 += (Data_235f34b4[/*i*/Data_234926e8/*r7*/ - Data_234926d0].Data_0x10 << 16);
			//loc_2342ea14
			r2 += (Data_235f34b4[/*i*/Data_234926e8/*r7*/ - Data_234926d0].Data_0x14 << 24);
			Data_23492710 = r2;
		}
		//0x2342eb1c
#if 1
		if (r5 < 2)
		{
			//0x2342eb28
			FREG(Data_234926ec + Data_2349270c + Data_234926d4 * 16)[0] = Data_23492710;

			if (r5 == 1)
			{
				FREG(Data_234926ec + 8 + Data_2349270c + Data_234926d4 * 16)[0] = Data_23492710;
			}
			//->loc_2342eb94
		}
		else
		{
			//loc_2342eb5c
			FREG(Data_234926ec + Data_2349270c + Data_234926d4 * 16)[0] = (Data_23492710 & 0xffff) + (Data_23492710 << 16);
			FREG(Data_234926ec + 4 + Data_2349270c + Data_234926d4 * 16)[0] = (Data_23492710 & 0xffff) + (Data_23492710 << 16);
		}
#endif
		//loc_2342eb94
	} //for (Data_234926d4 = 0; Data_234926d4 < Data_234926e8; Data_234926d4++)
	//0x2342ebac
	Data_234926d8 = 0; //r8
	Data_234926dc = 0; //r8
	Data_234926ec = 0; //r8
	Data_234926c8 = 0; //r8
	Data_23492708 = 0; //r8

	if (r5 == 0)
	{
		//0x2342ebc8
		//r2, =0x235f3434
		//r1, #0x3e8
		//r3, r2, #0x40	; 235F3474
		for (Data_234926d4 = 0; Data_234926d4 < 16; Data_234926d4++)
		{
			//loc_2342ebd8
			Data_235f3434[Data_234926d4] = 1000;
			Data_235f3474[Data_234926d4] = 1000;
		}
		//0x2342ebf4
//		double d0 = r4;

//		int r0 = Data_23492700;
		if (sp_0x38_arg_8 < 2)
		{
			//0x2342ec0c
#if 0
			int r0 = Data_23492700 + r4;
			double d2 = r0;
			d2 = d2 - (d0 * 0.25);
			//double d1 = 0.75;
			r0 = d2;
			Data_23492700 = r0;

			r0 = Data_23492704 + r4;
			d2 = r0;
			d2 = d2 - (d0 * 0.75);
			r0 = d2;
			//->loc_2342ecc4
			Data_23492704 = r0;
#else
			Data_23492700 = (double)(Data_23492700 + r4) - (/*d0*/(double)r4 * 0.25);
			Data_23492704 = (double)(Data_23492704 + r4) - (/*d0*/(double)r4 * 0.75);
#endif
		}
		else
		{
			//loc_2342ec84
#if 0
			int r0 = Data_23492700 + r4;
			double d2 = 0.5;
			double d1 = 0.5;
			double d3 = r0;
			d3 = d3 - (d0 * d1);
			r0 = d3;
			Data_23492700 = r0;

			r0 = Data_23492704 + r4;
			d1 = r0;
			d1 = d1 - (d0 * d2);
			r0 = d1;
			//loc_2342ecc4
			Data_23492704 = r0;
#else
			Data_23492700 = (double)(Data_23492700 + r4) - (/*d0*/(double)r4 * 0.5);
			Data_23492704 = (double)(Data_23492704 + r4) - (/*d0*/(double)r4 * 0.5);
#endif
		}
		//0x2342ecc8
		//sp_0xc = Data_23492704;
		//sp_0x10 = Data_23492700;
		for (Data_234926d4 = 0; Data_234926d4 < 64; Data_234926d4++)
		{
			//loc_2342ecd4
			//int r8 = Data_234926d8;
			sp8 = (/*r8*/Data_234926d8 * r4) / Data_234926e8/*r7*/;
			/*uint32_t fp =*/ Data_234926e0 = ((sp8 + Data_23492700) << 8) / r4;

			Data_234926e4 = ((sp8 + Data_23492704) << 8) / r4;

			Data_234926f0 = 0;
			Data_234926f4 = 0;

			if (/*fp*/Data_234926e0 < 0)
			{
				//->loc_2342ed54
				Data_234926f0 = 0x100;
			}
			else if (/*fp*/Data_234926e0 >= 0x200)
			{
				Data_234926f4 = 0x100;
				//->loc_2342ed58
			}
			else
			{
				Data_234926f4 = /*fp*/Data_234926e0 / 2;
				Data_234926f0 = 0x100 - Data_234926f4;
			}
			//loc_2342ed58
			Data_234926f8 = 0;
			Data_234926fc = 0;

			if (Data_234926e4 < 0)
			{
				//->loc_2342ed8c
				Data_234926f8 = 0x100;
			}
			else if (Data_234926e4 >= 0x200)
			{
				Data_234926fc = 0x100;
				//->loc_2342ed90
			}
			else
			{
				Data_234926fc = Data_234926e4 / 2;
				Data_234926f8 = 0x100 - Data_234926fc;
			}
			//loc_2342ed90
			if ((sl == 1) && (r5 == 0))
			{
				if ((/*r8*/Data_234926d8 == 0) || (/*r8*/Data_234926d8 == Data_234926e8/*r7*/))
				{
					if (Data_234926d4 != 0)
					{
						Data_23492708 = (Data_23492708 + 1) & 0x03;
					}
				}
				//loc_2342edc0
			}
			//loc_2342edc0
			if (r4 >= r6)
			{
				//0x2342edc8
				int r0 = Data_23492708 + /*r8*/Data_234926d8;

				if (/*r8*/Data_234926d8 >= Data_234926e8/*r7*/)
				{
					r0 = r0 - Data_234926e8/*r7*/;
				}

				Data_234926ec = r0;

				if (Data_235f3434[Data_234926ec] != 1000)
				{
					Data_235f3434[Data_234926ec] = (Data_235f3434[Data_234926ec] + Data_234926f0 + 1) >> 1;
				}
				else
				{
					Data_235f3434[Data_234926ec] = Data_234926f0;
				}

				if (Data_235f3474[Data_234926ec] != 1000)
				{
					Data_235f3474[Data_234926ec] = (Data_235f3474[Data_234926ec] + Data_234926f8 + 1) >> 1;
				}
				else
				{
					Data_235f3474[Data_234926ec] = Data_234926f8;
				}
				//0x2342ee24
				Data_234926dc = (Data_234926dc + r6) % (r4 * 2);
				Data_234926d8 = Data_234926dc >> 12;
				//->loc_2342eed8
			} //if (r4 >= r6)
			else
			{
				//loc_2342ee44
				if (Data_235f3434[Data_234926ec] != 1000)
				{
					Data_235f3434[Data_234926ec] = (Data_235f3434[Data_234926ec] + Data_234926fc + 1) >> 1;
				}
				else
				{
					Data_235f3434[Data_234926ec] = Data_234926fc;
				}

				if (Data_235f3474[Data_234926ec] != 1000)
				{
					Data_235f3474[Data_234926ec] = (Data_235f3474[Data_234926ec] + Data_234926f4 + 1) >> 1;
				}
				else
				{
					Data_235f3474[Data_234926ec] = Data_234926f4;
				}
				//0x2342ee90
				Data_234926dc += r4;
				Data_234926c8 = 1 & ~Data_234926c8;

				if (Data_234926dc >= r6)
				{
					//0x2342eeb4
					Data_234926dc -= r6;

					if (Data_234926c8 == 0)
					{
						Data_234926d8 = (Data_234926dc >> 12);
					}
					else
					{
						Data_234926d8 = (Data_234926dc >> 12) - Data_234926e8/*r7*/;
					}

					Data_234926ec = Data_23492708 + (Data_234926dc >> 12);
				}
				//loc_2342eed8
			}
			//loc_2342eed8
		} //for (Data_234926d4 = 0; Data_234926d4 < 64; Data_234926d4++)
		//0x2342eeec
		for (Data_234926d4 = 0; Data_234926d4 < 16; Data_234926d4++)
		{
			//loc_2342ef0c
			if (Data_235f3434[Data_234926d4] == 1000)
			{
				Data_235f3434[Data_234926d4] = 0x8080; //r2
				//->loc_2342ef3c
			}
			else if (Data_235f3434[Data_234926d4] >= 0xff)
			{
				Data_235f3434[Data_234926d4] = 0xff; //r3
			}
			else if (Data_235f3434[Data_234926d4] <= 1)
			{
				Data_235f3434[Data_234926d4] = 0xff00; //ip
			}
			else
			{
				r6 = 0x100 - Data_235f3434[Data_234926d4];
				Data_235f3434[Data_234926d4] += (r6 << 8);
			}
			//loc_2342ef3c
			if (Data_235f3474[Data_234926d4] == 1000)
			{
				Data_235f3474[Data_234926d4] = 0x8080; //r2
				//->loc_2342ef6c
			}
			else if (Data_235f3474[Data_234926d4] >= 0xff)
			{
				Data_235f3474[Data_234926d4] = 0xff; //r3
			}
			else if (Data_235f3474[Data_234926d4] <= 1)
			{
				Data_235f3474[Data_234926d4] = 0xff00; //ip
			}
			else
			{
				r6 = 0x100 - Data_235f3474[Data_234926d4];
				Data_235f3474[Data_234926d4] += (r6 << 8);
			}
			//loc_2342ef6c
			FREG(0xcb002000 + 4 + Data_234926d4 * 16)[0] = Data_235f3434[Data_234926d4];
			FREG(0xcb002000 + 0xc + Data_234926d4 * 16)[0] = Data_235f3474[Data_234926d4];

		} //for (Data_234926d4 = 0; Data_234926d4 < 16; Data_234926d4++)
		//loc_2342ef90
	} //if (r5 == 0)
	//loc_2342ef90
	return;
#endif
}


/* 2342efac - todo */
void sub_2342efac(uint32_t r4, uint32_t r5, int r2, int sb, int* r6, int sl, int r8)
{
#if 0
	console_send_string("sub_2342efac (todo.c): TODO\r\n");
#else

	Data_23492738 = 0x10;
	Data_2349273c = 0x10;
	Data_23492730 = 0xffff;

	do
	{
		//loc_2342efe0
		if (r4 < r5)
		{
			Data_23492734 = (((r4 * Data_2349273c) << 8) / r5) & 0xff;
		}
		else
		{
			Data_23492734 = (((r5 * Data_2349273c) << 8) / r4) & 0xff;
		}

		if (Data_23492734 < Data_23492730)
		{
			Data_23492730 = Data_23492734;
			Data_23492738 = Data_2349273c;
		}

		Data_2349273c--;
	}
	while (Data_2349273c >= 1);
	//0x2342f02c
	Data_23492718 = Data_23492738 << 12;

	if (r4 >= r5)
	{
		//0x2342f040
		(*r6) += (1 << 4);

//		uint32_t fp = Data_23492718;

		Data_23492714 = (Data_23492718 * r5) / r4;
		Data_23492724 = Data_23492714;
		Data_23492728 = Data_23492718; //fp
	}
	//loc_2342f068
	if (r4 < r5)
	{
		//0x2342f070
		(*r6) += (3 << 4);

//		uint32_t fp = Data_23492718;

		Data_23492714 = (Data_23492718 * r4) / r5;
		Data_23492724 = Data_23492718; //fp
		Data_23492728 = Data_23492714;
	}
	//loc_2342f098
	if ((Data_23492714 == 0x10000) &&
			(Data_23492718 == 0x10000))
	{
		//0x2342f0ac
		Data_23492714 = 0x8000;
		Data_23492718 = 0x8000;
		Data_23492724 = 0x8000;
		Data_23492728 = 0x8000;
	}
	//loc_2342f0c0
	bData_234926a4 = 0; //r1

	if (r8 == 0)
	{
		Data_2349272c = 1; //r2
	}
	else
	{
		Data_2349272c = -1; //r0
	}

//	int r0 = 0 - 8;

	switch (sb)
	{
	case 0:
		//loc_2342f110
		Data_2349271c = (-r8 * Data_23492724) / 2;
		Data_23492720 = -((Data_23492724 / 2) * Data_2349272c) + (Data_23492728 / 2);
		//loc_2342f170
		break;

	case 1:
		//loc_2342f144
		Data_2349271c = (-r8 * Data_23492724) / 2;
		Data_23492720 = (Data_23492724 / 2) * -Data_2349272c;
		//loc_2342f170
		break;

	case 2:
		Data_2349271c = 0; //r1
		//0x2342f100
		Data_23492720 = (Data_23492728 / 2);
		//loc_2342f170
		break;

	default:
		Data_2349271c = 0; //r1
		Data_23492720 = 0; //r1
		//->loc_2342f170
		break;
	}

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2342efac: Data_23492714=0x%x, Data_23492718=0x%x\r\n",
				Data_23492714, Data_23492718);
		console_send_string(debug_string);
	}
#endif

	switch (sl)
	{
	case 0:
		//loc_2342f1c4
		FREG(0xcb000024)[0] = Data_23492714; //VO_VOVERNUM
		FREG(0xcb000028)[0] = Data_23492718; //VO_VOVERDENUM

		if ((r4 <= r5) &&
				(((Data_23492714 | Data_23492718) & 0x3f00) == 0))
		{
			//0x2342f1ec
			(*r6) = ((*r6) & 0x0f) + (0x23 << 4);

			bData_234926a4 = 1; //r2
		}
		//loc_2342f200
		sub_2342e8d8(Data_23492724, Data_23492728, Data_2349271c, Data_23492720, sb, bData_234926a4, sl);
		break;

	case 1:
		//0x2342f17c
		//->loc_2342f198
		FREG(0xcb00c024)[0] = Data_23492714; //VO_SDVERNUM
		FREG(0xcb00c028)[0] = Data_23492718; //VO_SDVERDENUM

		sub_2342e8d8(Data_23492724, Data_23492728, Data_2349271c, Data_23492720, sb, 0, sl);
		break;

	case 2:
		//->loc_2342f198
		FREG(0xcb004024)[0] = Data_23492714; //VO_OSDVERNUM
		FREG(0xcb004028)[0] = Data_23492718; //VO_OSDVERDENUM

		sub_2342e8d8(Data_23492724, Data_23492728, Data_2349271c, Data_23492720, sb, 0, sl);
		break;

	default:
		FREG(0xcb008024)[0] = Data_23492714;
		FREG(0xcb008028)[0] = Data_23492718;

		sub_2342e8d8(Data_23492724, Data_23492728, Data_2349271c, Data_23492720, sb, 0, sl);
		break;
	}
#endif
}


/* 2342f20c - todo */
void sub_2342f20c(int r5, int r6, int r4)
{
#if 0
	console_send_string("sub_2342f20c (todo.c): TODO\r\n");
#endif

	Struct_2342f774 sp4 = //23489c58
	{
		1440, 240, 238, 18, 1
	};

	sub_2342f774(&sp4, r5, r6, r4);
}


/* 2342f24c - todo */
void sub_2342f24c(int r5, int r6, int r4)
{
#if 0
	console_send_string("sub_2342f24c (todo.c): TODO\r\n");
#endif

	Struct_2342f774 sp4 = //23489c80
	{
		1440, 288, 264, 22, 1
	};

	sub_2342f774(&sp4, r5, r6, r4);
}


/* 2342f28c - todo */
void sub_2342f28c(uint32_t r4, uint32_t r6, int* r7, int r8, uint32_t sb)
{
#if 0
	console_send_string("sub_2342f28c (todo.c): TODO\r\n");
#endif

	int sl;
	//sl, #0x10000

	Data_234926b0 = 0x10000; //sl

	if (r4 > r6)
	{
		(*r7)++;

		Data_234926b0 = (r6 << 16) / r4;
	}
	//loc_2342f2dc
	if (r4 < r6)
	{
		(*r7) += 3;

		Data_234926b0 = (r4 << 16) / r6;
	}

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2342f28c: Data_234926b0=0x%x\r\n", Data_234926b0);
		console_send_string(debug_string);
	}
#endif

	//loc_2342f300
	//r7, #0x0
	switch (r8)
	{
	case 0:
		//loc_2342f340
		FREG(0xcb00001c)[0] = Data_234926b0; //VO_VOHORNUM
		FREG(0xcb000020)[0] = 0x10000; //sl; //VO_VOHORDENUM

		Data_234926b8 = 0xCB002100;
		Data_234926c0 = 0; //r7
		sl = 8;
		//->loc_2342f3b0
		break;

	case 1:
		//loc_2342f364
		FREG(0xcb00c01c)[0] = Data_234926b0; //VO_SDHORNUM
		FREG(0xcb00c020)[0] = 0x10000; //sl //VO_SDHORDENUM

		Data_234926b8 = 0xCB012100;
		Data_234926c0 = Data_234926b0 + 0x10000;

		while (1)
		{
			//loc_2342f384
			if ((Data_234926c0 & 0xf000) == 0)
			{
				break;
			}
			Data_234926c0 += Data_234926b0;
		}
		//0x2342f394
		int r0 = 0 - Data_234926b0;
		r0 = Data_234926c0 + r0 * 2;
		r0 = r0 & 0xf000;
		Data_234926c0 = r0 >> 12;
		//loc_2342f3ac
		sl = 0;
		break;

	case 2:
		//
		FREG(0xcb00401c)[0] = Data_234926b0; //VO_OSDHORNUM
		FREG(0xcb004020)[0] = 0x10000; //sl //VO_OSDHORDENUM

		Data_234926b8 = 0xcb006100;
		Data_234926c0 = 0; //r7
		//->loc_2342f3ac
		sl = 0;
		break;

	default:
		FREG(0xcb00801c)[0] = Data_234926b0; //???
		FREG(0xcb008020)[0] = 0x10000; //sl //???

		Data_234926b8 = 0xcb00a100;
		Data_234926c0 = 0; //r7
		//->loc_2342f3ac
		sl = 0;
		break;
	}
	//loc_2342f3b0
	r6 = r6 / sb;

	if (r4 <= r6)
	{
		//0x2342f3c8
		for (Data_234926b4 = 0; Data_234926b4 < 16; Data_234926b4++)
		{
			//loc_2342f3d0
			FREG(Data_234926b8 + Data_234926b4 * 16)[0] = Data_23489b3c[Data_234926b4 + 8].Data_0;
			FREG(Data_234926b8 + 4 + Data_234926b4 * 16)[0] = Data_23489b3c[Data_234926b4 + 8].Data_4;
			FREG(Data_234926b8 + 8 + Data_234926b4 * 16)[0] = Data_23489b3c[Data_234926b4 + 8 + sl].Data_0;
			FREG(Data_234926b8 + 0xc + Data_234926b4 * 16)[0] = Data_23489b3c[Data_234926b4 + 8 + sl].Data_4;
		}
		//loc_2342f41c
		return;
	} //if (r4 <= r6)
	//loc_2342f428
	if ((sb * r6) >= r4)
	{
		Data_234926bc = 0x10;
	}
	else
	{
		Data_234926bc = (Data_234926b0 + 0x800) >> 12;
	}

	Data_234926b0 *= sb;

	if ((sb * r6) >= r4)
	{
		//int sp = 8; //r3
		//r3, #0x10000
		//sl, =0x235f34b4
		//0x2342f474
		sub_2342e544(Data_234926bc & 0xff, 0, Data_234926b0, 0x10000, 8);

		for (Data_234926b4 = 0; Data_234926b4 < 16; Data_234926b4++)
		{
			//loc_2342f47c
			int r2;
			int i = -Data_234926b4;
			r2 = Data_235f34b4[15 + i].Data_0;
			r2 += (Data_235f34b4[15 + i].Data_4 << 3);
			r2 += (Data_235f34b4[15 + i].Data_8 << 8);
			r2 += (Data_235f34b4[15 + i].Data_0xc << 16);
			r2 += (Data_235f34b4[15 + i].Data_0x10 << 24);
			Data_234926c4 = r2;
			FREG(Data_234926b8 + ((Data_234926b4 + Data_234926c0) & 0x0f) * 16)[0] = Data_234926c4;

			int j = -Data_234926b4;
			r2 = Data_235f34b4[15 + j].Data_0x14;
			r2 += (Data_235f34b4[15 + j].Data_0x18 << 8);
			r2 += (Data_235f34b4[15 + j].Data_0x1c << 13);
			Data_234926c4 = r2;
			FREG(Data_234926b8 + 4 + ((Data_234926b4 + Data_234926c0) & 0x0f) * 16)[0] = Data_234926c4;

		} //for (Data_234926b4 = 0; Data_234926b4 < 16; Data_234926b4++)
		//0x2342f50c
		if (r8 == 0)
		{
			sub_2342e544(Data_234926bc & 0xff, (int32_t)(Data_234926b0 * 0.5), Data_234926b0, 0x10000, 8);
		}
		//loc_2342f544
		for (Data_234926b4 = 0; Data_234926b4 < 16; Data_234926b4++)
		{
			//loc_2342f550
			int r2;
			r2 = Data_235f34b4[15 - Data_234926b4].Data_0;
			r2 += (Data_235f34b4[15 - Data_234926b4].Data_4 << 3);
			r2 += (Data_235f34b4[15 - Data_234926b4].Data_8 << 8);
			r2 += (Data_235f34b4[15 - Data_234926b4].Data_0xc << 16);
			r2 += (Data_235f34b4[15 - Data_234926b4].Data_0x10 << 24);
			FREG(Data_234926b8 + 8 + ((Data_234926b4 + Data_234926c0) & 0x0f) * 16)[0] = r2;

			r2 = Data_235f34b4[15 - Data_234926b4].Data_0x14;
			r2 += (Data_235f34b4[15 - Data_234926b4].Data_0x18 << 8);
			r2 += (Data_235f34b4[15 - Data_234926b4].Data_0x1c << 13);
			Data_234926c4 = r2;
			FREG(Data_234926b8 + 0x0c + ((Data_234926b4 + Data_234926c0) & 0x0f) * 16)[0] = Data_234926c4;

		} //for (Data_234926b4 = 0; Data_234926b4 < 16; Data_234926b4++)
		//0x2342f5b8 -> loc_2342f41c
		return;
	}
	//loc_2342f5bc
	sub_2342e544(Data_234926bc & 0xff, 0, Data_234926b0, 0x10000, 8);

	for (Data_234926b4 = 0; Data_234926b4 < 16; Data_234926b4++)
	{
		//loc_2342f5c4
		int r2;
		r2 = Data_235f34b4[Data_234926b4].Data_0;
		r2 += (Data_235f34b4[Data_234926b4].Data_4 << 3);
		r2 += (Data_235f34b4[Data_234926b4].Data_8 << 8);
		r2 += (Data_235f34b4[Data_234926b4].Data_0xc << 16);
		r2 += (Data_235f34b4[Data_234926b4].Data_0x10 << 24);
		Data_234926c4 = r2;
		FREG(Data_234926b8 + ((Data_234926b4 + Data_234926c0) & 0x0f) * 16)[0] = Data_234926c4;

		r2 = Data_235f34b4[Data_234926b4].Data_0x14;
		r2 += (Data_235f34b4[Data_234926b4].Data_0x18 << 8);
		r2 += (Data_235f34b4[Data_234926b4].Data_0x1c << 13);
		Data_234926c4 = r2;
		FREG(Data_234926b8 + 4 + ((Data_234926b4 + Data_234926c0) & 0x0f) * 16)[0] = Data_234926c4;

	} //for (Data_234926b4 = 0; Data_234926b4 < 16; Data_234926b4++)
	//0x2342f64c
	if (r8 == 0)
	{
		sub_2342e544(Data_234926bc & 0xff, (int32_t)(Data_234926b0 * 0.5), Data_234926b0, 0x10000, 8);
	}
	//loc_2342f684
	for (Data_234926b4 = 0; Data_234926b4 < 16; Data_234926b4++)
	{
		//loc_2342f690
		int r2;
		r2 = Data_235f34b4[Data_234926b4].Data_0;
		r2 += (Data_235f34b4[Data_234926b4].Data_4 << 3);
		r2 += (Data_235f34b4[Data_234926b4].Data_8 << 8);
		r2 += (Data_235f34b4[Data_234926b4].Data_0xc << 16);
		r2 += (Data_235f34b4[Data_234926b4].Data_0x10 << 24);
		FREG(Data_234926b8 + 8 + ((Data_234926b4 + Data_234926c0) & 0x0f) * 16)[0] = r2;

		r2 = Data_235f34b4[Data_234926b4].Data_0x14;
		r2 += (Data_235f34b4[Data_234926b4].Data_0x18 << 8);
		r2 += (Data_235f34b4[Data_234926b4].Data_0x1c << 13);
		Data_234926c4 = r2;
		FREG(Data_234926b8 + 0x0c + ((Data_234926b4 + Data_234926c0) & 0x0f) * 16)[0] = Data_234926c4;

	} //for (Data_234926b4 = 0; Data_234926b4 < 16; Data_234926b4++)
	//0x2342f6f8
	if ((Data_234926ac == sub_2342f24c) ||
			(Data_234926ac == sub_2342f20c))
	{
		if (r4 == (r6 * 2))
		{
			FREG(Data_234926b8 + (Data_234926c0 & 0x0f) * 16)[0] = 0xff0000;
			FREG(Data_234926b8 + 4 + (Data_234926c0 & 0x0f) * 16)[0] = 0;
			FREG(Data_234926b8 + 8 + (Data_234926c0 & 0x0f) * 16)[0] = 0xff0000;
			FREG(Data_234926b8 + 0x0c + (Data_234926c0 & 0x0f) * 16)[0] = 0;
		}
		//loc_2342f41c
	}
	//loc_2342f41c
}


/* 2342f774 - todo */
void sub_2342f774(Struct_2342f774* r4, uint32_t r6, uint32_t sb, uint32_t sl)
{
#if 0
	console_send_string("sub_2342f774 (todo.c): TODO\r\n");
#endif

//	int r5;
//	int r8;
	int fp = 0;
	uint32_t sp_0x18;
	int sp_0x14 = 0; //fp
	int sp_0x10;
	int sp_0xc;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2342f774: Data_234926a8 = %d, r6=%d, sb=%d, sl=%d\r\n",
				Data_234926a8, r6, sb, sl);
		console_send_string(debug_string);
	}
#endif
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2342f774: r4->Data_0=%d, r4->Data_4=%d, r4->Data_8=%d, r4->Data_12=%d, r4->bData_0x10=%d\r\n",
				r4->Data_0, r4->Data_4, r4->Data_8, r4->Data_12, r4->bData_0x10);
		console_send_string(debug_string);
	}
#endif

	uint32_t r5 = (Data_234926a8/*r7*/ == 3)? (r4->Data_0 * 75) / 100: r4->Data_0;
	//loc_2342f7bc
	uint32_t r8 = (Data_234926a8/*r7*/ == 2)? (r4->Data_4 * 72) / 100: r4->Data_4;

	int r0 = r4->bData_0x10;
	r0 = 1 - r0;
	r0 = r0 + (sl * 2);
	if (sl == 0)
	{
		sb = sb >> 1;
	}

	sp_0x10 = r0;

	if (sb == 0x220)
	{
		sb = 0x21c;
	}

	FREG(0xcb000008)[0] = 0; //r1 //VO_VOVSTARTPOS
	FREG(0xcb000014)[0] = 2; //VO_VOBITPERPIXEL
	FREG(0xcb000044)[0] = sl << 16; //VO_VOMODE

	//r2, #0x57
	sp_0xc = r5;
	sp_0x18 = r6 * 87;

	sl = r6;

	if (Data_234926a8/*r7*/ == 7)
	{
		//0x2342f834
		r8 = (r4->Data_4 * 85) / 100;

		//->loc_2342f86c
		int r0 = sp_0x18 / 100;
		uint32_t r1 = r6 - r0;
		sl = r0;
		//int r2 = r1 >> 1;
		//r1 = r0;
		//r0 = r4->Data_0;
		//->loc_2342f8d4
		r5 = sub_2342e4cc(r4->Data_0, r0, r1 >> 1);
		//->loc_2342f904
	}
	//loc_2342f858
	//r0 = r6 * 75;
	else if (Data_234926a8/*r7*/ == 4)
	{
		//0x2342f868
		int r0 = /*r0*/(r6 * 75) / 100;
		//loc_2342f86c
		uint32_t r1 = r6 - r0;
		sl = r0;
		//int r2 = r1 >> 1;
		//r1 = r0;
		//r0 = r4->Data_0;
		//->loc_2342f8d4
		r5 = sub_2342e4cc(r4->Data_0, r0, r1 >> 1);
		//->loc_2342f904
	}
	//loc_2342f888
	else if (Data_234926a8/*r7*/ == 5)
	{
		r5 = 75;
		//r1 = 100;
		//->loc_2342f8ac
		int r0 = /*r0*/(r6 * 75) / 100;
		uint32_t r1 = r6 - r0;
		int r7 = r0;
		r6 = r1 >> 1;
		r0 = (r0 * r5) / 100;
		//r2 = r6;
		//r1 = r7;
		//loc_2342f8d4
		r5 = sub_2342e4cc(r0, r7, r6);
		//->loc_2342f904
	}
	else if (Data_234926a8/*r7*/ == 6)
	{
		//0x2342f8a0
		r5 = 87; //r2
		//loc_2342f8ac
		int r0 = sp_0x18 / 100;
		uint32_t r1 = r6 - r0;
		int r7 = r0;
		r6 = r1 >> 1;
		r0 = (r0 * r5) / 100;
		//r2 = r6;
		//r1 = r7;
		//loc_2342f8d4
		r5 = sub_2342e4cc(r0, r7, r6);
		//->loc_2342f904
	}
	else
	{
		//loc_2342f8e0
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2342f774: Data_234926a8=%d, r5=%d, r6=%d\r\n",
					Data_234926a8, r5, r6);
			console_send_string(debug_string);
		}
#endif

		FREG(0xcb00000c)[0] = 0; //r1; //VO_VOHSTARTPOS
		FREG(0xcb000034)[0] = 4; //VO_VOINITIALSHIFT
		FREG(0xcb000010)[0] = ((r6 + 127) / 128) - 1; //VO_VOHSIZE
		FREG(0xcb000030)[0] = r6; //VO_VOHORREADPIXEL
		FREG(0xcb00002c)[0] = r5; //VO_VOHORDISPPIXEL
	}
	//loc_2342f904
	sub_2342f28c(sl, sp_0xc, &sp_0x14, 0, (r4->bData_0x10 + 1) & 0xff);

	sub_2342efac(sb, r8, r4->Data_4, sp_0x10, &sp_0x14, 0, 0);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2342f774: sp_0x14 = 0x%x\r\n",
				sp_0x14);
		console_send_string(debug_string);
	}
#endif

	FREG(0xcb000038)[0] = sp_0x14; //VO_VOFILTERMODE

	uint32_t r1_ = r4->Data_0;
	uint32_t r0_ = r4->Data_8;
	r1_ = r1_ - r5;
	r0_ = r0_ + (r1_ >> 1);
	r0_ = r0_ + (r0_ << 16);
	r0_ = r0_ + r5;
	FREG(0xcb010014)[0] = r0_; //VO_DISPVOHORSTARTSTOP

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2342f774: VO_DISPVOHORSTARTSTOP=0x%x, VOHORSTART=%d, VOHORSTOP=%d\r\n",
				r0_, (r0_ >> 16), (r0_ & 0xfff));
		console_send_string(debug_string);
	}
#endif

	r0_ = (r8 * 3) / sb;

	uint32_t r2_ = r4->Data_4;
	r1_ = r4->Data_12;
	r2_ = r2_ - r8;
	r1_ = r1_ + (r2_ >> 1);
	r1_ = r1_ + (r1_ << 16);
	r1_ = r1_ + r8;
	r0_ = r1_ - r0_;
	r0_ = r0_ - 1;
	FREG(0xcb010018)[0] = r0_; //VO_DISPVOVERSTARTSTOP

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2342f774: VO_DISPVOVERSTARTSTOP=0x%x, VOVERSTART=%d, VOVERSTOP=%d\r\n",
				r0_, (r0_ >> 16), (r0_ & 0x7ff));
		console_send_string(debug_string);
	}
#endif
}


/* 2342f9ac - todo */
void sub_2342f9ac(int r5, int r6, int r4)
{
#if 0
	console_send_string("sub_2342f9ac (todo.c): TODO\r\n");
#endif

	Struct_2342f774 sp4 = //23489c44
	{
		1280, 720, 260, 25, 0
	};

	sub_2342f774(&sp4, r5, r6, r4);
}


/* 2342f9ec - todo */
void sub_2342f9ec(int r5, int r6, int r4)
{
#if 0
	console_send_string("sub_2342f9ec (todo.c): TODO\r\n");
#endif

	Struct_2342f774 sp4 = //23489c6c
	{
		720, 576, 132, 44, 0
	};

	sub_2342f774(&sp4, r5, r6, r4);
}


/* 2342fa2c - todo */
void sub_2342fa2c(int r5, int r6, int r4)
{
#if 0
	console_send_string("sub_2342fa2c (todo.c): TODO\r\n");
#endif

	Struct_2342f774 sp4 = //23489c94
	{
		1920, 540, 192, 20, 1
	};

	sub_2342f774(&sp4, r5, r6, r4);
}


/* 2342fa6c / 2343da98 - todo */
void sub_2342fa6c(int a)
{
#if 0
	console_send_string("sub_2342fa6c (todo.c): TODO\r\n");
#endif

	VO_VohfltMirror[0] = 0xc040;
	FREG(0xcb002000)[0] = VO_VohfltMirror[0];
	VO_VohfltMirror[1] = 0xa060;
	FREG(0xcb002004)[0] = VO_VohfltMirror[1];
	VO_VohfltMirror[2] = 0x8080;
	FREG(0xcb002008)[0] = VO_VohfltMirror[2];
	VO_VohfltMirror[3] = 0xff;
	FREG(0xcb00200c)[0] = VO_VohfltMirror[3];
	VO_VohfltMirror[4] = 0xc040;
	FREG(0xcb002010)[0] = VO_VohfltMirror[4];
	VO_VohfltMirror[5] = 0xc040;
	FREG(0xcb002014)[0] = VO_VohfltMirror[5];
	VO_VohfltMirror[6] = 0x8080;
	FREG(0xcb002018)[0] = VO_VohfltMirror[6];
	VO_VohfltMirror[7] = 0x60A0;
	FREG(0xcb00201c)[0] = VO_VohfltMirror[7];
	VO_VohfltMirror[8] = 0xc040;
	FREG(0xcb002020)[0] = VO_VohfltMirror[8];
	VO_VohfltMirror[9] = 0xa060;
	FREG(0xcb002024)[0] = VO_VohfltMirror[9];
	VO_VohfltMirror[10] = 0x8080;
	FREG(0xcb002028)[0] = VO_VohfltMirror[10];
	VO_VohfltMirror[11] = 0xff;
	FREG(0xcb00202c)[0] = VO_VohfltMirror[11];
	VO_VohfltMirror[12] = 0xc040;
	FREG(0xcb002030)[0] = VO_VohfltMirror[12];
	VO_VohfltMirror[13] = 0xc040;
	FREG(0xcb002034)[0] = VO_VohfltMirror[13];
	VO_VohfltMirror[14] = 0x8080;
	FREG(0xcb002038)[0] = VO_VohfltMirror[14];
	VO_VohfltMirror[15] = 0x60A0;
	FREG(0xcb00203c)[0] = VO_VohfltMirror[15];
	VO_VohfltMirror[16] = 0xc040;
	FREG(0xcb002040)[0] = VO_VohfltMirror[16];
	VO_VohfltMirror[17] = 0xa060;
	FREG(0xcb002044)[0] = VO_VohfltMirror[17];
	VO_VohfltMirror[18] = 0x8080;
	FREG(0xcb002048)[0] = VO_VohfltMirror[18];
	VO_VohfltMirror[19] = 0xff;
	FREG(0xcb00204c)[0] = VO_VohfltMirror[19];
	VO_VohfltMirror[20] = 0xc040;
	FREG(0xcb002050)[0] = VO_VohfltMirror[20];
	VO_VohfltMirror[21] = 0xc040;
	FREG(0xcb002054)[0] = VO_VohfltMirror[21];
	VO_VohfltMirror[22] = 0x8080;
	FREG(0xcb002058)[0] = VO_VohfltMirror[22];
	VO_VohfltMirror[23] = 0x60A0;
	FREG(0xcb00205c)[0] = VO_VohfltMirror[23];
	VO_VohfltMirror[24] = 0xc040;
	FREG(0xcb002060)[0] = VO_VohfltMirror[24];
	VO_VohfltMirror[25] = 0xa060;
	FREG(0xcb002064)[0] = VO_VohfltMirror[25];
	VO_VohfltMirror[26] = 0x8080;
	FREG(0xcb002068)[0] = VO_VohfltMirror[26];
	VO_VohfltMirror[27] = 0xff;
	FREG(0xcb00206c)[0] = VO_VohfltMirror[27];
	VO_VohfltMirror[28] = 0xc040;
	FREG(0xcb002070)[0] = VO_VohfltMirror[28];
	VO_VohfltMirror[29] = 0xc040;
	FREG(0xcb002074)[0] = VO_VohfltMirror[29];
	VO_VohfltMirror[30] = 0x8080;
	FREG(0xcb002078)[0] = VO_VohfltMirror[30];
	VO_VohfltMirror[31] = 0x60A0;
	FREG(0xcb00207c)[0] = VO_VohfltMirror[31];
	VO_VohfltMirror[32] = 0x40c000;
	FREG(0xcb002080)[0] = VO_VohfltMirror[32];
	//0x2342fc18

	//TODO

	//0x23430194
	VO_Osd1hfltMirror[0] = 0xff00ff;
	FREG(0xcb006000)[0] = VO_Osd1hfltMirror[0]; //VO_OSD1HFLT

	//TODO

	//0x23430864
	VO_Osd2clutMirror[0] = 0x7a787bff;
	FREG(0xcb00b000)[0] = VO_Osd2clutMirror[0]; //VO_OSD2CLUT

	//TODO

	//0x23431a10
	VO_Osd2hfltMirror[0] = 0xFF00FF;
	FREG(0xcb00a000)[0] = VO_Osd2hfltMirror[0]; //VO_OSD2HFLT
	//0x23431e00

	//TODO

	//0x23432474
	VO_CursorclutMirror[0] = 0x7a787bff;
	FREG(0xcb020000)[0] = VO_CursorclutMirror[0]; //VO_CURSORCLUT

	//TODO

	//0x23433470

	//TODO

	//0x234335c4
	VO_SetSdhflt_Sdhflt(0, 0xb051da43);
	VO_SetSdhflt_Sdhflt(1, 0x7125);

	//TODO

	//0x234338c4
	VO_SetSdvflt_Sdvflt(0, 0x40804000);
	VO_SetSdvflt_Sdvflt(1, 0x40804000);
	VO_SetSdvflt_Sdvflt(2, 0x39794707);
	VO_SetSdvflt_Sdvflt(3, 0x39794707);
	VO_SetSdvflt_Sdvflt(4, 0x32724e0e);
	VO_SetSdvflt_Sdvflt(5, 0x32724e0e);
	VO_SetSdvflt_Sdvflt(6, 0x2b6b5515);
	VO_SetSdvflt_Sdvflt(7, 0x2b6b5515);
	VO_SetSdvflt_Sdvflt(8, 0x24645c1c);
	VO_SetSdvflt_Sdvflt(9, 0x24645c1c);
	VO_SetSdvflt_Sdvflt(10, 0x1d5d6323);
	VO_SetSdvflt_Sdvflt(11, 0x1d5d6323);
	VO_SetSdvflt_Sdvflt(12, 0x16566b2b/*r7*/);
	VO_SetSdvflt_Sdvflt(13, 0x16566b2b/*r7*/);
	VO_SetSdvflt_Sdvflt(14, 0xf4f7131/*r8*/);
	VO_SetSdvflt_Sdvflt(15, 0xf4f7131/*r8*/);
	VO_SetSdvflt_Sdvflt(16, 0x8487838/*sl*/);
	VO_SetSdvflt_Sdvflt(17, 0x8487838/*sl*/);
	VO_SetSdvflt_Sdvflt(18, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(19, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(20, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(21, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(22, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(23, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(24, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(25, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(26, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(27, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(28, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(29, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(30, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(31, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(32, 0x40804000);
	VO_SetSdvflt_Sdvflt(33, 0x40804000);
	VO_SetSdvflt_Sdvflt(34, 0x39794707);
	VO_SetSdvflt_Sdvflt(35, 0x39794707);
	VO_SetSdvflt_Sdvflt(36, 0x32724e0e);
	VO_SetSdvflt_Sdvflt(37, 0x32724e0e);
	//0x23433a9c
	VO_SetSdvflt_Sdvflt(38, 0x2b6b5515);
	VO_SetSdvflt_Sdvflt(39, 0x2b6b5515);
	VO_SetSdvflt_Sdvflt(40, 0x24645c1c);
	VO_SetSdvflt_Sdvflt(41, 0x24645c1c);
	VO_SetSdvflt_Sdvflt(42, 0x1d5d6323);
	VO_SetSdvflt_Sdvflt(43, 0x1d5d6323);
	VO_SetSdvflt_Sdvflt(44, 0x16566b2b/*r7*/);
	VO_SetSdvflt_Sdvflt(45, 0x16566b2b/*r7*/);
	VO_SetSdvflt_Sdvflt(46, 0xf4f7131/*r8*/);
	VO_SetSdvflt_Sdvflt(47, 0xf4f7131/*r8*/);
	VO_SetSdvflt_Sdvflt(48, 0x8487838/*sl*/);
	VO_SetSdvflt_Sdvflt(49, 0x8487838/*sl*/);
	VO_SetSdvflt_Sdvflt(50, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(51, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(52, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(53, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(54, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(55, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(56, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(57, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(58, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(59, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(60, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(61, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(62, 0x807F/*fp*/);
	VO_SetSdvflt_Sdvflt(63, 0x807F/*fp*/);
	//0x23433bd4
	Data_234924a8 = 0x200;
	FREG(0xcb0110e0)[0] = Data_234924a8; //VE_SD_CCFilterHorStart

	//TODO

	//0x23433ca4
	Data_23492480 = 0x140;
	FREG(0xcb0110a0)[0] = Data_23492480; //VE_SD_CCFilterLum8

	//TODO

	//0x23433dd8
	VO_SetOsdfiltermode_Verfilteron(0, 0);

	//TODO

	//0x23433e20
	VO_SetOsdfiltermode_Verfilteron(1, 0);
}


/* 23434180 - complete */
void sub_23434180()
{
#if 0
	console_send_string("sub_23434180 (todo.c): TODO\r\n");
#endif

	FREG(0xcb011000)[0] = 0xd80; //VO_SD_HorLineLength
	FREG(0xcb011004)[0] = 0x138; //VO_SD_VerSize
	FREG(0xcb011040)[0] = 0x220; //VO_SD_VOHorStart
	FREG(0xcb011044)[0] = 0xd60; //VO_SD_VOHorStop
	FREG(0xcb011048)[0] = 0x17; //VO_SD_VOVerStart
	FREG(0xcb01104c)[0] = 0x137; //VO_SD_VOVerStop
	FREG(0xCB010048)[0] = 0x100005; //VO_DISPCVBSVERSYNC
	FREG(0xcb011144)[0] = 0x34; //VO_SDHSYNCOFFSET
	FREG(0xcb01114c)[0] = 0x536; //VO_SDVSYNCOFFSET
	FREG(0xcb011140)[0] = 0x20; //VO_SDHVSYNCCFG
	FREG(0xCB01300c)[0] = 0x409; //VE_CEConf
	FREG(0xCB013010)[0] = 0x541; //VE_CEBurstInt
	FREG(0xCB013014)[0] = 0x3159; //VE_CEBurstFra1
	FREG(0xCB013018)[0] = 0x68; //VE_CEBurstFra2
}


/* 23434200 - todo */
void viout_configure_sd(int r0)
{
#if 0
	console_send_string("viout_configure_sd (todo.c): TODO\r\n");
#endif

	//r5 = 0x19 = 25;
	//r7 = 0;
	//ip = 0x2df = 735
	//r6 = 0x160239
	int sp_0xc = 0; //sp0x28var_1C = 0; //r7

	if (r0 == 6)
	{
		sub_234340e8();

		FREG(0xcb00c02c)[0] = 25; //0x19; //r5 //VO_SDHORWRITESTART
		FREG(0xcb00c030)[0] = 735; //0x2df; //ip //VO_SDHORWRITESTOP

		FREG(0xCB010040)[0] = 151 << 16; //0x970000; //VO_DISPCVBSHORSTARTSTOP
		FREG(0xCB010044)[0] = (22 << 16) | 569; //0x160239; //r6 //VO_DISPCVBSVERSTARTSTOP

		sub_2342f28c(1920, 720, &sp_0xc, 1, 1);

		//->loc_234344c8
		//r0, #0x21c
		//->loc_234342d0
		sub_2342efac(540, 240, 240, 2, &sp_0xc, 1, 0);

		FREG(0xcb00c038)[0] = sp_0xc; //r5 //VO_SDFILTERMODE

		return;
	}
	//loc_23434274
	else if (r0 == 5)
	{
		//TODO!!!

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "viout_configure_sd: r0=%d\r\n", r0);
		console_send_string(debug_string);
	}
#endif

	}
	//loc_234342e0
	else if (r0 == 0)
	{
		//TODO!!!

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "viout_configure_sd: r0=%d\r\n", r0);
		console_send_string(debug_string);
	}
#endif

	}
	//loc_2343433c
	else if (r0 == 1)
	{
		//TODO!!!

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "viout_configure_sd: r0=%d\r\n", r0);
		console_send_string(debug_string);
	}
#endif

	}
	//loc_234343a0
	else if (r0 == 2)
	{
		//TODO!!!

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "viout_configure_sd: r0=%d\r\n", r0);
		console_send_string(debug_string);
	}
#endif

	}
	//loc_23434408
	else if (r0 == 3)
	{
		//0x23434410
		sub_23434180();

		FREG(0xcb00c02c)[0] = 120; //0x78; //r5 //VO_SDHORWRITESTART
		FREG(0xcb00c030)[0] = 840; //0x348; //ip //VO_SDHORWRITESTOP

		FREG(0xCB010040)[0] = 66 << 16; //0x420000; //VO_DISPCVBSHORSTARTSTOP
		FREG(0xCB010044)[0] = (25 << 16) | 748; //0x1902ec; //VO_DISPCVBSVERSTARTSTOP

		sub_2342f28c(1280, 720, &sp_0xc, 1, 1);
		//->loc_234342d0
		sub_2342efac(720, 288, 288, 2, &sp_0xc, 1, 0);

		FREG(0xcb00c038)[0] = sp_0xc; //r5 //VO_SDFILTERMODE

		return;
	}
	//loc_23434470
	else if (r0 == 4)
	{
		//0x23434478
		sub_23434180();

		FREG(0xcb00c02c)[0] = 45; //0x2d //VO_SDHORWRITESTART
		FREG(0xcb00c030)[0] = 765; //0x2fd //VO_SDHORWRITESTOP

		FREG(0xCB010040)[0] = 96 << 16; //0x600000; //VO_DISPCVBSHORSTARTSTOP
		FREG(0xCB010044)[0] = (22 << 16) | 569; //0x160239; //r6 //VO_DISPCVBSVERSTARTSTOP

		sub_2342f28c(1920, 720, &sp_0xc, 1, 1);

		sub_2342efac(540, 288, 288, 0, &sp_0xc, 1, 0);

		FREG(0xcb00c038)[0] = sp_0xc; //r5 //VO_SDFILTERMODE
	}

	return;
}


/* 23434558 / 23442584 - todo */
void viout_configure_video_layer(int a)
{
#if 0
	console_send_string("viout_configure_video_layer (todo.c): TODO\r\n");
#endif

	if (a == 0)
	{
		Data_234926ac = sub_2342f20c;
	}
	else if (a == 1)
	{
		Data_234926ac = sub_2342f24c;
	}
	else if (a == 2)
	{
		Data_234926ac = sub_2342f9ec;
	}
	else if (a == 3)
	{
		Data_234926ac = sub_2342f9ac;
	}
	else if (a == 4)
	{
		Data_234926ac = sub_2342fa2c;
	}
}


/* 234345a4 - todo */
void sub_234345a4(int r6)
{
#if 0
	console_send_string("sub_234345a4 (todo.c): TODO\r\n");
#endif

	int r0 = FREG(0xcb010048)[0]; //VO_DISPCVBSVERSYNC
	r0 = (r0 & ~0xfff) | 0x05; //CVBSVERSYNC
	FREG(0xcb010048)[0] = r0;

	r0 = FREG(0xCB00C02c)[0]; //VO_SDHORWRITESTART
	r0 = (r0 & ~0x7ff) | 16;
	FREG(0xCB00C02c)[0] = r0;

	r0 = FREG(0xCB00C030)[0]; //VO_SDHORWRITESTOP
	r0 = (r0 & ~0x7ff) | 736;
	FREG(0xCB00C030)[0] = r0;

	Data_23492450 |= 0x20;
	FREG(0xCB011140)[0] = Data_23492450; //VO_SDHVSYNCCFG

	sub_23434870(0x30);

	Data_23492454 |= 0x400;
	FREG(0xCB01114c)[0] = Data_23492454; //VO_SDVSYNCOFFSET

	sub_23434870(0x135);

	FREG(0xCB010040)[0] = 0x2007a0; //VO_DISPCVBSHORSTARTSTOP

	r0 = FREG(0xCB010044)[0];
	r0 &= ~0x7000000;
	r0 &= ~0xff0000;
	r0 |= 0x160000;
	FREG(0xCB010044)[0] = r0; //VO_DISPCVBSVERSTARTSTOP

	r0 = FREG(0xCB010044)[0];
	r0 = (r0 & ~0x7ff);
	r0 |= 0x200;
	r0 |= 0x32;
	FREG(0xCB010044)[0] = r0; //VO_DISPCVBSVERSTARTSTOP

	Data_23492440 = (Data_23492440 & ~0x1fff) | 0x198;
	FREG(0xCB011040)[0] = Data_23492440; //VO_SD_VOHorStart

	Data_23492444 = (Data_23492444 & ~0x1fff) | 0xcd8;
	FREG(0xCB011044)[0] = Data_23492444; //VO_SD_VOHorStop

	Data_23492448 = (Data_23492448 & ~0x3ff) | 0x16;
	FREG(0xCB011048)[0] = Data_23492448; //VO_SD_VOVerStart

	Data_2349244c = (Data_2349244c & ~0x3ff) | 0x136;
	FREG(0xCB01104c)[0] = Data_2349244c; //VO_SD_VOVerStop

	viout_configure_sd(r6);

	FREG(0xCB00C040)[0] |= 1; //VO_SDENABLE
}


/* 234346fc - todo */
int sub_234346fc(int a, int b, int c)
{
#if 0
	console_send_string("sub_234346fc (todo.c): TODO\r\n");
#endif

	if (Data_234926ac != 0)
	{
		(Data_234926ac)(a, b, c);
	}

	return 0;
}


/* 23434718 - todo */
void sub_23434718(int a)
{
#if 0
	console_send_string("sub_23434718 (todo.c): TODO\r\n");
#endif

	sub_2342fa6c(a);
}


/* 2343471c - todo */
void sub_2343471c(int a)
{
#if 0
	console_send_string("sub_2343471c (todo.c): TODO\r\n");
#endif

	Data_234926a8 = a;
}


/* 23434728 - todo */
void sub_23434728(int r4)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_23434728 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();
	uint32_t r1 = 0xcb000000;
	uint32_t r2 = FREG(r1 + 0x44)[0];

	if (r4 != 0)
	{
		if ((r2 & (1 << 16)) == 0) //normal interlaced mode
		{
			FREG(r1 + 0x44)[0] = (1 << 16)/*progressive*/ | (1 << 15);
		}
	}
	else
	{
		//loc_23434754
		if ((r2 & (1 << 15)) != 0)
		{
			FREG(r1 + 0x44)[0] = 0;
		}
	}

	OS_EXIT_CRITICAL();
}


/* 2343476c - complete */
void VO_SetSdhflt_Sdhflt(int a, int b)
{
#if 0
	console_send_string("VO_SetSdvflt_Sdvflt (todo.c): TODO\r\n");
#endif

	VO_SdhfltMirror[a] = b;
	FREG(0xcb012100 + a * 4)[0] = b; //VO_SDHFLT
}


/* 234347f4 - complete */
void VO_SetOsdfiltermode_Verfilteron(int a, int b)
{
	uint32_t mask = (1 << 4); //VERFILTERON

	b = (b << 4) & mask;

	FREG(0xcb004038 + (a << 14))[0] = (FREG(0xcb004038 + (a << 14))[0] & ~mask) | b; //VO_OSDFILTERMODE
}


/* 23434858 - complete */
void VO_SetSdvflt_Sdvflt(int a, int b)
{
#if 0
	console_send_string("VO_SetSdvflt_Sdvflt (todo.c): TODO\r\n");
#endif

	VO_SdvfltMirror[a] = b;
	FREG(0xcb012800 + a * 8)[0] = b; //VO_SDVFLT
}

