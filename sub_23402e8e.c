

#include "data.h"
#include "sub_2340a6a0.h"
#include "Struct_23443080.h"


#pragma thumb



void sub_234448ec(Struct_23443080*, int);
void sub_23444da8();
void sub_23444700();
void sub_23447d2e(Struct_23443080*, int);
void sub_234483e8();
void sub_23447c3e();
void sub_2344a9d2(Struct_23443080*, int);
void sub_2344b04c();
void sub_2344a888();


const Struct_23491e28_Inner_0x98 Data_23487cb0 = //23487cb0
{
		sub_234448ec,
		sub_23444da8,
		sub_23444700
};
const Struct_23491e28_Inner_0x98 Data_23487cbc = //23487cbc
{
		sub_23447d2e,
		sub_234483e8,
		sub_23447c3e
};
const Struct_23491e28_Inner_0x98 Data_23487cc8 = //23487cc8
{
		sub_2344a9d2,
		sub_2344b04c,
		sub_2344a888
};


extern Struct_23491e28 Data_23491e28[];

//23491e20
Struct_23491e28* Data_23491e20 = Data_23491e28; //23491e20 +0
int Data_23491e24 = 0; //23491e24 +4
Struct_23491e28 Data_23491e28[2] = //23491e28 +8
{
		{.Data_0x98 = &Data_23487cb0},
		{.Data_0x98 = &Data_23487cb0}
};


static int WriteReg(uint8_t, uint8_t);
static uint8_t ReadReg(uint8_t);
int sub_23402efe(int);
void M88DC2000SetSym(uint32_t, uint32_t);


/* 2340257c - todo */
void M88DC2000SoftReset()
{
#if 0
	console_send_string("M88DC2000SoftReset (todo.c): TODO\r\n");
#endif

	WriteReg(0x80, 0x01);
	WriteReg(0x82, 0x00);

	rtos_task_wait(1);

	WriteReg(0x80, 0x00);
}


/* 2340259e - complete */
void M88DC2000SetTsType(int type)
{
	int r4 = 0xc7;

#if 0
	console_send_string("M88DC2000SetTsType (todo.c): TODO\r\n");
#endif

	if (type == 0)
	{
		WriteReg(0x84, 0x6c);
		WriteReg(0xc0, 0x43); /* parallel format */
		WriteReg(0xe2, 0x06);
		WriteReg(0xc2, (ReadReg(0xc2) & r4) | 0x10);
		WriteReg(0xc1, 0x60); /* common interface */
	}
	else if (type == 1)
	{
		WriteReg(0x84, 0x6a);
		WriteReg(0xc0, 0x47); /* serial format */
		WriteReg(0xe2, 0x02);
		WriteReg(0xc2, (ReadReg(0xc2) & r4) | 0x00);
		WriteReg(0xc1, 0x00);
	}
	else
	{
		WriteReg(0x84, 0x6c);
		WriteReg(0xc0, 0x43); /* parallel format */
		WriteReg(0xe2, 0x06);
		WriteReg(0xc2, (ReadReg(0xc2) & r4) | 0x00);
		WriteReg(0xc1, 0x00);
	}
}


/* 2340261e - todo */
void M88DC2000SetTxMode(int inverted, int j83)
{
	int value = 0;

#if 0
	console_send_string("M88DC2000SetTxMode (todo.c): TODO\r\n");
#endif

	if (inverted != 0)
	{
		value |= 8;
	}

	if (j83 != 0)
	{
		value |= 1;
	}

	WriteReg(0x83, value);
}


/* 2340263a - todo */
void M88DC2000SetQAM(int qam)
{
#if 0
	int reg8BH = 2; //r4
	int reg8EH; //reg8EH;
	int reg74H; //sp
	int reg4DH; //sp4
	int reg4CH; //sp8;
	int reg44H; //sp12
	int reg4AH; //sp16
	int reg00H; //r7;
	uint32_t regC2H; //r6
	int value; //r7
#else
	uint8_t reg00H, reg4AH, regC2H, reg44H, reg4CH, reg4DH, reg74H, value;
	uint8_t reg8BH, reg8EH;
#endif

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "M88DC2000SetQAM: qam=%d\r\n", qam);
		console_send_string(debug_string);
	}
#endif

	regC2H = ReadReg(0xc2);
	regC2H &= 0xf8; //(regC2H >> 3) << 3;

	switch (qam)
	{
	case 1:
		//0x2340265a = 4 /* 16 QAM */
		reg00H = 0x08;
		reg4AH = 0x0f;
		//0x2340267e
		regC2H |= 2;
		reg44H = 0xaa;
		reg4CH = 0x0c;
		reg4DH = 0xf7;
		reg74H = 0x0e;
		//0x2340268e
//		regC2H |= 2;
		//0x23402690
		if (((ReadReg(0xe3) >> 7) != 0) &&
				//loc_23402660
				((ReadReg(0xe4) >> 7) != 0))
		{
			//0x2340266a
			reg8BH = 0x5a;
			reg8EH = 0xbd;
			//loc_2340266e
		}
		else
		{
			//loc_2340269a
			reg8BH = 0x5b;
			reg8EH = 0x9d;
			//->loc_2340266e
		}
		//loc_2340266e
		WriteReg(0x6e, 0x18);
		//->loc_23402710
		break;

	case 2:
		//0x23402678 = 13 /* 32 QAM */
		reg00H = 0x18;
		reg4AH = 0xfb;
		//0x2340267e
		regC2H |= 2;
		reg44H = 0xaa;
		reg4CH = 0x0c;
		reg4DH = 0xf7;
		reg74H = 0x0e;
		//0x2340268e
//		regC2H |= 2;
		//0x23402690
		if (((ReadReg(0xe3) >> 7) != 0) &&
				//loc_23402660
				((ReadReg(0xe4) >> 7) != 0))
		{
			//0x2340266a
			reg8BH = 0x5a;
			reg8EH = 0xbd;
			//loc_2340266e
		}
		else
		{
			//loc_2340269a
			reg8BH = 0x5b;
			reg8EH = 0x9d;
			//->loc_2340266e
		}
		//loc_2340266e
		WriteReg(0x6e, 0x18);
		//->loc_23402710
		break;

	case 3:
//	case 5:
		//234026A0 = 0x27 /* 64 QAM */
		reg00H = 0x48;
		reg4AH = 0xcd;
		regC2H |= 2;
		reg44H = 0xaa;
		reg4CH = 0x0c;
		reg4DH = 0xf7;
		reg74H = 0x0e;
//		reg00H = 0x48;
		//0x234026b6?
//		regC2H |= 2;

		if (((ReadReg(0xe3) >> 7) != 0) &&
				((ReadReg(0xe4) >> 7) != 0))
		{
			//0x234026cc
			reg8BH = 0x5a;
			reg8EH = 0xbd;
			//->23402710
		}
		else
		{
			//2340270C
			reg8BH = 0x5b;
			reg8EH = 0x9d;
		}
		//loc_23402710
		break;

	case 4:
		//0x234026d2 = 40 /* 128 QAM */
		reg00H = 0x28;
		reg4AH = 0xff;
		//->234026F4?
		regC2H |= 2;
		//->234026FC?
		reg44H = 0xa9;
		reg4CH = 0x08;
		reg4DH = 0xf5;
		reg74H = 0x0e;
		reg8BH = 0x5b;
		reg8EH = 0x9d;
		//loc_23402710
		break;

	case 5:
		//0x234026da = 44 /* 256 QAM */
		reg00H = 0x38;
		reg4AH = 0xcd;
//		reg00H = 0x38;
		//0x234026e0?
		if (((ReadReg(0xe3) >> 7) != 0) &&
				((ReadReg(0xe4) >> 7) != 0))
		{
			//0x234026f4
			regC2H |= 2;
			//->234026FC?
		}
		else
		{
			//->234026F8?
			regC2H |= 1;
		}
		//234026FC
		reg44H = 0xa9;
		reg4CH = 0x08;
		reg4DH = 0xf5;
		reg74H = 0x0e;
		reg8BH = 0x5b;
		reg8EH = 0x9d;
		//loc_23402710
		break;

	default:
		//234026A0 = 0x27 /* 64 QAM */
		reg00H = 0x48;
		reg4AH = 0xcd;
		regC2H |= 2;
		reg44H = 0xaa;
		reg4CH = 0x0c;
		reg4DH = 0xf7;
		reg74H = 0x0e;
//		reg00H = 0x48;
		//0x234026b6?
//		regC2H |= 2;

		if (((ReadReg(0xe3) >> 7) != 0) &&
				((ReadReg(0xe4) >> 7) != 0))
		{
			//0x234026cc
			reg8BH = 0x5a;
			reg8EH = 0xbd;
			//->23402710
		}
		else
		{
			//2340270C
			reg8BH = 0x5b;
			reg8EH = 0x9d;
		}
		//loc_23402710
		break;
	}
	//loc_23402710
	WriteReg(0x00, reg00H);

	value = ReadReg(0x88);
	value |= 0x08;
	WriteReg(0x88, value);
	WriteReg(0x4b, 0xff);
	WriteReg(0x4a, reg4AH);
	value &= 0xf7;
	WriteReg(0x88, value);
	WriteReg(0xc2, regC2H);
	WriteReg(0x44, reg44H);
	WriteReg(0x4c, reg4CH);
	WriteReg(0x4d, reg4DH);
	WriteReg(0x74, reg74H);
	WriteReg(0x8b, reg8BH);
	WriteReg(0x8e, reg8EH);
}


/* 23402782 - todo */
void M88DC2000RegInitial_TC2800()
{
	uint32_t r5;
	uint32_t r4;

#if 0
	console_send_string("M88DC2000RegInitial_TC2800 (todo.c): TODO\r\n");
#endif

	WriteReg(0x00, 0x48);
	WriteReg(0x01, 0x09);
	WriteReg(0xfb, 0x0a);
	WriteReg(0xfc, 0x0b);
	WriteReg(0x02, 0x0b);
	WriteReg(0x03, 0x18);
	WriteReg(0x05, 0x0d);
	WriteReg(0x36, 0x80);
	WriteReg(0x43, 0x40);
	WriteReg(0x55, 0x7a);
	WriteReg(0x56, 0xd9);
	WriteReg(0x57, 0xdf);
	WriteReg(0x58, 0x39);
	WriteReg(0x5a, 0x00);
	WriteReg(0x5c, 0x71);
	WriteReg(0x5d, 0x23);
	WriteReg(0x86, 0x40);
	WriteReg(0xf9, 0x08);
	WriteReg(0x61, 0x40);
	WriteReg(0x62, 0x0a);
	WriteReg(0x90, 0x06);
	WriteReg(0xde, 0x00);
	WriteReg(0xa0, 0x03);
	WriteReg(0xdf, 0x81);
	WriteReg(0xfa, 0x40);
	WriteReg(0x37, 0x10);
	WriteReg(0xf0, 0x40);
	WriteReg(0xf2, 0x9c);
	WriteReg(0xf3, 0x40);

	r5 = ReadReg(0xe3);
	r4 = ReadReg(0xe4);

	if (Data_23491e20/*r6*/->Data_0x98 == &Data_23487cc8/*r7*/)
	{
		//0x2340288a
		WriteReg(0x30, 0xff);
	}
	else
	{
		//loc_2340288e
		WriteReg(0x30, 0xd0);
	}

	WriteReg(0x31, 0x00);
	WriteReg(0x32, 0x00);
	WriteReg(0x33, 0x00);
	WriteReg(0x35, 0x32);

	if (((r5 | r4) >> 6) == 0)
	{
		//0x234028be
		WriteReg(0x40, 0x00);
		WriteReg(0x41, 0x10);
		WriteReg(0xf1, 0x02);
		WriteReg(0xf4, 0x04);
		//r1 = 0;
		//->loc_2340292e
		WriteReg(0xf5, 0x00);
		//0x23402934
		WriteReg(0x42, 0x14);
		//->loc_23402aa6
		WriteReg(0xe1, 0x25);
		//0x23402aaa
	}
	else
	{
		//loc_234028e2
		if (((r5 >> 6) == 2)
			//0x234028e8
				&& ((r4 >> 6) == 1))
		{
			//0x234028ee
			WriteReg(0x39, 0x00);

			if (Data_23491e20/*r6*/->Data_0x98 == &Data_23487cc8/*r7*/)
			{
				//0x23402900
				WriteReg(0x3a, 0x00);
			}
			else
			{
				//loc_23402904
				WriteReg(0x3a, 0x60);
			}
			//0x2340290c
			WriteReg(0x40, 0x00);
			WriteReg(0x41, 0x10);
			WriteReg(0xf1, 0x00);
			WriteReg(0xf4, 0x00);
			//0x2340292c
			WriteReg(0xf5, 0x40);
			//0x23402934
			WriteReg(0x42, 0x14);
			//->loc_23402aa6
			WriteReg(0xe1, 0x25);
			//0x23402aaa
		}
		else
		{
			//loc_23402942
			if (((r5 == 0x80) || (r5 == 0x81))
				//loc_2340294a
					&& ((r4 == 0x80) || (r4 == 0x81)))
			{
				//loc_23402952
				WriteReg(0x39, 0x00);

				if (Data_23491e20/*r6*/->Data_0x98 == &Data_23487cc8/*r7*/)
				{
					//0x23402964
					WriteReg(0x3a, 0x00);
				}
				else
				{
					//loc_23402968
					WriteReg(0x3a, 0x60);
				}
				//0x23402970
				WriteReg(0xf1, 0x00);
				WriteReg(0xf4, 0x00);
				WriteReg(0xf5, 0x40);
				WriteReg(0x42, 0x24);
				WriteReg(0xe1, 0x25);
				WriteReg(0x92, 0x7f);
				WriteReg(0x93, 0x91);
				WriteReg(0x95, 0x00);
				WriteReg(0x2b, 0x33);
				WriteReg(0x2a, 0x2a);
				WriteReg(0x2e, 0x80);
				WriteReg(0x25, 0x25);
				WriteReg(0x2d, 0xff);
				WriteReg(0x26, 0xff);
				WriteReg(0x27, 0x00);
				WriteReg(0x24, 0x25);
				WriteReg(0xa4, 0xff);
				//r1 = 0x0d
				//->loc_23402aa4
				WriteReg(0xa3, 0x0d);
				//0x23402aaa
			}
			else
			{
				//loc_234029fc
				WriteReg(0x39, 0x00);

				if (Data_23491e20/*r6*/->Data_0x98 == &Data_23487cc8/*r7*/)
				{
					//0x23402a0e
					WriteReg(0x3a, 0x00);
				}
				else
				{
					//loc_23402a12
					WriteReg(0x3a, 0x60);
				}
				//0x23402a1a
				WriteReg(0xf1, 0x00);
				WriteReg(0xf4, 0x00);
				WriteReg(0xf5, 0x40);
				WriteReg(0x42, 0x24);
				WriteReg(0xe1, 0x27);
				WriteReg(0x92, 0x7f);
				WriteReg(0x93, 0x91);
				WriteReg(0x95, 0x00);
				WriteReg(0x2b, 0x33);
				WriteReg(0x2a, 0x2a);
				WriteReg(0x2e, 0x80);
				WriteReg(0x25, 0x25);
				WriteReg(0x2d, 0xff);
				WriteReg(0x26, 0xff);
				WriteReg(0x27, 0x00);
				WriteReg(0x24, 0x25);
				WriteReg(0xa4, 0xff);
				WriteReg(0xa3, 0x10);
				//0x23402aaa
			}
		}
	}
	//0x23402aaa
	WriteReg(0xf6, 0x4e);
	WriteReg(0xf7, 0x20);
	WriteReg(0x89, 0x02);
	WriteReg(0x14, 0x08);
	WriteReg(0x6f, 0x0d);
	WriteReg(0x10, 0xff);
	WriteReg(0x11, 0x00);
	WriteReg(0x12, 0x30);
	WriteReg(0x13, 0x23);
	WriteReg(0x60, 0x00);
	WriteReg(0x69, 0x00);
	WriteReg(0x6a, 0x03);
	WriteReg(0xe0, 0x75);
	WriteReg(0x8d, 0x29);
	WriteReg(0x4e, 0xd8);
	WriteReg(0x88, 0x80);
	WriteReg(0x52, 0x79);
	WriteReg(0x53, 0x00);
	WriteReg(0x59, 0x30);
	WriteReg(0x5e, 0x02);
	WriteReg(0x5f, 0x0f);
	WriteReg(0x71, 0x03);
	WriteReg(0x72, 0x12);
	WriteReg(0x73, 0x12);
}


/* 23402b6c - todo */
int sub_23402b6c(/*Struct_235fdfac ???*/Struct_23491e28_Inner0* r4)
{
#if 0
	console_send_string("sub_23402b6c (todo.c): TODO\r\n");
#endif

	Data_23491e20->Data_0.Data_0x10 = r4;

	if (0 != memcmp(&Data_23491e20->Data_0, r4, 16))
	{
		//memcpy(&Data_23491e20->Data_0.Data_0, r4, 16);
		Data_23491e20->Data_0.Data_0 = *r4;

//		Data_23491e20->Data_0.bData_0x14 = (r4->bData_2 << 28) >> 31;
		Data_23491e20->Data_0.bData_0x14 = r4->Data_0.Bitfield_0.Data_19;
		//->loc_23402bbe
	}
	else
	{
		//loc_23402b96
		if ((ReadReg(0x85) & (1 << 3)) != 0) //Lock?
		{
			return 0;
		}
		//loc_23402ba4
		Data_23491e20->Data_0.bData_0x14 ^= 1;
//		r4->bData_2 = (r4->bData_2 & 0xf7) | ((Data_23491e20->Data_0.bData_0x14 << 31) >> 28);
		r4->Data_0.Bitfield_0.Data_19 = Data_23491e20->Data_0.bData_0x14;
	}
	//loc_23402bbe
	WriteReg(0x84, 0x2a);
	WriteReg(0x84, 0x6a);

	WriteReg(0x80, 0x01);

	sub_23402efe(r4->frequency / 10);

	M88DC2000RegInitial_TC2800();

	M88DC2000SetSym(r4->symbol_rate, 28800);

//	M88DC2000SetQAM(r4->bData_3 >> 4);
	M88DC2000SetQAM(r4->Data_0.Bitfield_0.Data_28_31);

	M88DC2000SetTxMode(Data_23491e20->Data_0.bData_0x14, 0);

	M88DC2000SetTsType(0);

	M88DC2000SoftReset();
	//->loc_23402ba0
	return 0;
}


/* 23402c22 - todo */
uint16_t sub_23402c22(uint32_t r4)
{
	int r7;
	int r6;
	int r5;
	int sp;
	int r0;
	uint32_t r1;
	uint32_t r2;
	int r3;

#if 0
	console_send_string("sub_23402c22 (todo.c): TODO\r\n");
#endif

	sp = ReadReg(0x55);
	r5 = ReadReg(0x56);
	r6 = ReadReg(0x57);
	r7 = ReadReg(0x58);

	r0 = ReadReg(0x51);

	r1 = (r7 << 24) + (r6 << 16) + (r5 << 8) + (sp << 0);

	r3 = r4 >> 8;
	r4 = r4 & 0xff;

	r2 = r1 >> 24;
	r5 = r2;

	r1 = (r1 << 8) >> 8;

	r2 = r4 * r2;
	r1 = r3 * r1;
	r5 = r3 * r5;

	r2 = r2 >> 8;
	r1 = r1 >> 24;

	r2 = r5 + r2;

	r1 = r1 - 10;

	r1 = r2 + r1;
	r4 = r1 & 0xffff;

	if (r0 > 0x80)
	{

	}
	//loc_23402c86

	r0 = r4 * r0;
	r0 = r0 * 5;

	return r4 - r0 / 10000;
}


/* 23402c9a - todo */
int sub_23402c9a(uint8_t* r4)
{
	uint16_t r0;
	uint8_t r0_;

#if 0
	{
		extern char debug_string[];

		uint8_t reg_0x80 = ReadReg(0x80);
		uint8_t reg_0x85 = ReadReg(0x85);
		uint8_t reg_0xdf = ReadReg(0xdf);
		uint8_t reg_0x91 = ReadReg(0x91);
		uint8_t reg_0x43 = ReadReg(0x43);

		sprintf(debug_string, "sub_23402c9a: reg_0x80=0x%02x, reg_0x85=0x%02x, reg_0xdf=0x%02x, reg_0x91=0x%02x, reg_0x43=0x%02x\r\n",
				reg_0x80, reg_0x85, reg_0xdf, reg_0x91, reg_0x43);
		console_send_string(debug_string);
	}
#endif

	if (ReadReg(0x80) < 0x06)
	{
		if (((ReadReg(0xdf) >> 7) != 0) &&
				((ReadReg(0x91) & 0x23) == 0x03) &&
				((ReadReg(0x43) & (1 << 3)) != 0))
		{
			//0x23402cce
			*r4 = 1;
		}
		else
		{
			//loc_23402d04
			*r4 = 0;
		}
	}
	else
	{
		//loc_23402d08
		if ((ReadReg(0x85) & (1 << 3)) != 0) //Lock?
		{
			//0x23402cce
			*r4 = 1;
		}
		else
		{
			//loc_23402d04
			*r4 = 0;
		}
	}
	//0x23402cce
	if (*r4 == 1)
	{
		r0 = sub_23402c22(28800);

		if (((Data_23491e20->Data_0.Data_0.symbol_rate - 10) > r0) ||
				(Data_23491e20->Data_0.Data_0.symbol_rate + 10) < r0)
		{
			//loc_23402cec
			Data_23491e20->Data_0.Data_0.symbol_rate = r0;
			Data_23491e20->Data_0.Data_0x10-> symbol_rate = r0;
		}
		//loc_23402cf2
		r0_ = ReadReg(0x83);

		Data_23491e20->Data_0.bData_0x15 = (r0_ & 0x08) >> 3;
	}
	else
	{
		*r4 = 0;
	}

	return 0;
}


/* 23402da0 - complete */
int sub_23402da0(uint8_t* r4)
{
	int16_t r0;
	uint32_t res;

#if 0
	console_send_string("sub_23402da0 (todo.c): TODO\r\n");
#endif

	r0 = (Data_23491e20->Data_0x98->Data_4)(0x20);

	if (r0 < -109)
	{
		//loc_23402dc4
		res = 0;
	}
	else
	{
		uint8_t r0_ = r0 + 109;

		if (r0_ < 40)
		{
			//loc_23402dc4
			res = 0;
		}
		//loc_23402dc8
		else if (r0_ > 80)
		{
			res = 100;
		}
		else
		{
			//loc_23402dd0
			uint16_t r0__ = ((r0_ - 40) * 1000) / 40;

			if ((r0__ % 10) <= 4)
			{
				r0__ = (r0__ / 10);
			}
			else
			{
				r0__ = (r0__ / 10) + 1;
			}

			res = r0__;
		}
	}

	*r4 = res;
	return 0;
}


/* 23402df4 - complete */
int sub_23402df4()
{
	int mtt; //Montage Tuner Type

#if 0
	console_send_string("sub_23402df4 (todo.c): TODO\r\n");
#endif

	if (Data_23491e20->Data_0x20.tuner_init_OK != 0)
	{
		//loc_23402e60
		return 0;
	}

	memset(&Data_23491e20->Data_0, 0, 32);
	memset(&Data_23491e20->Data_0x20, 0, 0x78);

	Data_23491e20->Data_0x20.tuner_dev_addr = Data_23491e20->tuner_dev_addr;
	Data_23491e20->Data_0x20.demod_address = Data_23491e20->demod_address;
	Data_23491e20->Data_0x20.WriteReg = WriteReg;
	Data_23491e20->Data_0x20.ReadReg = ReadReg;

	mtt = m88dc2800_get_chip_version(&Data_23491e20->Data_0x20);

	if (mtt == 1)
	{
		Data_23491e20->Data_0x98 = &Data_23487cb0;
	}
	//loc_23402e38
	else if (mtt == 10)
	{
		//VDR110: 0xB5
		Data_23491e20->Data_0x98 = &Data_23487cbc;
	}
	//loc_23402e42
	else if (mtt == 11)
	{
		Data_23491e20->Data_0x98 = &Data_23487cc8;
	}
	else
	{
		//loc_23402e64
		return 1;
	}

	sub_23402efe(50500);

	if (Data_23491e20->Data_0x20.tuner_init_OK != 0)
	{
		//loc_23402e60
		return 0;
	}
	//loc_23402e64
	return 1;
}


/* 23402e68 - complete */
int sub_23402e68()
{
#if 0
	console_send_string("sub_23402e68 (todo.c): TODO\r\n");
#endif

	(Data_23491e20->Data_0x98->Data_8)(&Data_23491e20->Data_0x20); //->sub_23447c3e

	WriteReg(0xe2, 0x0e);

	memset(&Data_23491e20->Data_0.Data_0, 0xff, 16);

	return 0;
}


/* 23402e8e - todo */
int sub_23402e8e(uint32_t idx, uint8_t demod_address, uint8_t tuner_dev_addr)
{
	if (idx > 1)
	{
		return 1;
	}

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23402e8e: idx=%d, demod_address=0x%02x, tuner_dev_addr=0x%02x, Data_23491e20->Data_0x20.tuner_init_OK=%d\r\n",
				idx, demod_address, tuner_dev_addr, Data_23491e20->Data_0x20.tuner_init_OK);
		console_send_string(debug_string);
	}
#endif

	Data_23491e20 = &Data_23491e28[idx];

	if (Data_23491e20->Data_0x20.tuner_init_OK == 0)
	{
		Data_23491e20->tuner_dev_addr = tuner_dev_addr;
		Data_23491e20->demod_address = demod_address;
	}
	//loc_23402eb2
	return 0;
}


/* 23402eb6 - complete */
int WriteReg(uint8_t a, uint8_t b)
{
	uint8_t sp[2];

#if 0
	console_send_string("WriteReg (todo.c): TODO\r\n");
#endif

	sp[0] = a;
	sp[1] = b;

	if (0 != i2c_master_send(/*Data_23491d8c.hI2c0*/main_hI2c0, Data_23491e20->demod_address, sp, 2))
	{
		return 3;
	}

	return 0;
}


/* 23402eda - complete */
uint8_t ReadReg(uint8_t reg)
{
	uint8_t sp4 = 0;

#if 0
	console_send_string("ReadReg (todo.c): TODO\r\n");
#endif

	i2c_master_read_reg(main_hI2c0, Data_23491e20->demod_address, reg, &sp4, 1);

	return sp4;
}


/* 23402efe - complete */
int sub_23402efe(int a)
{
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23402efe: a=%d\r\n", a);
		console_send_string(debug_string);
	}
#endif

	(Data_23491e20->Data_0x98->Data_0)(&Data_23491e20->Data_0x20, a);

	return 0;
}


/* 23402f34 - todo */
void M88DC2000SetSym(uint32_t sym, uint32_t xtal)
{
	uint8_t value;
	uint8_t reg6FH, reg12H;
	uint32_t dwValue;
	double fValue;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "M88DC2000SetSym: sym=%d, xtal=%d\r\n", sym, xtal);
		console_send_string(debug_string);
	}
#endif

	fValue = 4294967296 * ((double)(sym + 10));
	fValue /= (double)xtal;

	/* fValue  = 4294967296 * (sym + 10) / xtal; */
	dwValue = (uint32_t) fValue;

	WriteReg(0x58, dwValue >> 24);
	WriteReg(0x57, dwValue >> 16);
	WriteReg(0x56, dwValue >> 8);
	WriteReg(0x55, dwValue >> 0);

	/* fValue = 2048 * xtal / sym; */
	fValue = 2048 * (double)xtal;
	fValue /= (double)sym;

	dwValue = (uint32_t) fValue;

	WriteReg(0x5D, dwValue >> 8);
	WriteReg(0x5C, dwValue >> 0);

	value = ReadReg(0x5A);
	if (((dwValue >> 16) & 0x0001) == 0)
	{
		value &= 0x7F;
	}
	else
	{
		value |= 0x80;
	}
	WriteReg(0x5A, value);

	value = ReadReg(0x89);
	if (sym <= 1800)
	{
		value |= 0x01;
	}
	else
	{
		value &= 0xFE;
	}
	WriteReg(0x89, value);

	if (sym >= 6700) //0x1a2c
	{
		reg6FH = 0x0D;
		reg12H = 0x30;
	}
	else if (sym >= 4000) //0xfa0
	{
		fValue = 22 * 4096 / sym;
		reg6FH = (uint8_t) fValue;
		reg12H = 0x30;
	}
	else if (sym >= 2000) //0x7d0
	{
		fValue = 14 * 4096 / sym;
		reg6FH = (uint8_t) fValue;
		reg12H = 0x20;
	}
	else
	{
		fValue = 7 * 4096 / sym;
		reg6FH = (uint8_t) fValue;
		reg12H = 0x10;
	}
	WriteReg(0x6F, reg6FH);
	WriteReg(0x12, reg12H);

	if (((ReadReg(0xE3) & 0x80) == 0x80)
	       && ((ReadReg(0xE4) & 0x80) == 0x80))
	{
		if (sym < 3000)
		{
			WriteReg(0x6C, 0x16);
			WriteReg(0x6D, 0x10);
			WriteReg(0x6E, 0x18);
		}
		else
		{
			WriteReg(0x6C, 0x14);
			WriteReg(0x6D, 0x0E);
			WriteReg(0x6E, 0x36);
		}
	}
	else
	{
		WriteReg(0x6C, 0x16);
		WriteReg(0x6D, 0x10);
		WriteReg(0x6E, 0x18);
	}
}


