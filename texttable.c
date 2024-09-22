

#include "data.h"
#include "flash.h"
#include "graphic.h"
#include "av.h"


Struct_235f2e2c* Data_23491ff8/*pFlash*/; //23491ff8

uint8_t Data_234f9814[0x3000]; //234f9814, size???

struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	uint8_t bData_2; //2
	int fill_4[13]; //4
	int Data_0x38; //0x38
	int Data_0x3c; //0x3c
	//64 = 0x40
} Data_234fc814; //234fc814


struct Struct_234fc854
{
	int fill_0[2]; //0
	int Data_8; //8
	uint8_t bData_12; //12
	uint8_t bData_13; //13
	//16
} Data_234fc854[10]; //234fc854, size??

struct
{
	int fill_0[6]; //0
	int Data_0x18; //0x18 = 24
	int Data_0x1c; //0x1c = 28
	//32 = 0x20
} Data_234fc8f4[130]; //234fc8f4, size???

uint8_t Data_234fd894[24]; //234fd894, size???

struct
{
	uint16_t wData_0; //0
	uint16_t wData_2; //2
	int Data_4; //4
	int Data_8; //8
	//12
} Data_234fd8a0; //234fd8a0 


struct
{
	int language[16]; //0, size???
	uint8_t currentLanguage; //0x40
	uint8_t numLanguages; //0x41
	//0x44
} text_table_languages; //234fd8ac /  / 2356c670



/* 23407de8 /  / 2340a8c4 - todo */
int texttable_load_bitmap(uint16_t a, void* b, int c)
{
	a--;

	if ((a <= Data_234fc814.bData_1) && (a < 0x7d))
	{
		int r1 = Data_234fc8f4[a].Data_0x1c;
		if (c == 0)
		{
			c = Data_234fc8f4[a].Data_0x18;
		}

		flash_read(Data_23491ff8, r1, c, b);

#if 1
		hex_dump("texttable_load_bitmap", b, c);
#endif

		return 0;
	}

	return 0xff;
}


/* 23407f24 /  / 2340aa00 - todo */
int sub_23407f24(int a/*sp_0xc*/, char* b, 
	int c/*sp_0x14*/, int d/*sp_0x18*/, int e/*sp_0x40*/, 
	int sp_0x44, uint32_t sp_0x48)
{
#if 0
	console_send_string("sub_23407f24 (todo.c): TODO\r\n");
#endif

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23407f24: b[0]='%c'\r\n", b[0]);
		console_send_string(debug_string);
	}
#endif

	uint32_t sp8;
	uint32_t* sp4;

	uint8_t row = 0; //r5
	uint8_t col = 0; //r4
//	int r7 = g;
//	int r8 = f;

	sp4 = sub_2342d4a8(0);
	sp8 = (uint32_t) sub_2342d494(0) >> 3;

	sub_23407e40(b, sp_0x44/*r8*/, &Data_234f9814[0], 0x44);

	uint16_t* r6 = &Data_234f9814[0];

	uint32_t bitfield = *r6++;
	uint32_t width = (bitfield & 0x1f) + 1; //r0 = 5 bits
	uint8_t height = (bitfield >> 5) & 0x3f; //r1 = 6 bits
	int sb = (bitfield >> 11);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23407f24: width=%d, height=%d, sb=%d\r\n", 
			width, height, sb);
		console_send_string(debug_string);
	}
#endif

	if ((c/*sp_0x14*/ + width) > sp_0x48/*r7*/)
	{
		return 0;
	}
	//->loc_23408058
	while (height != 0)
	{
		//loc_23407fa8
		uint16_t wData = *r6++;
		uint16_t bits = 16;
		uint32_t bitmask = 0x8000;
		//->loc_23408048
		while ((bits--) != 0)
		{
			//loc_23407fb8
			if (wData & bitmask)
			{
				//0x23407fc0
				uint16_t lr = c/*sp_0x14*/ + col;
				uint32_t ip = (uint16_t)(d/*sp_0x18*/ + sb + row);
				ip = ip * sp8/*r7*/;
				uint32_t* ip_ = sp4 + ip;
				ip_ += (lr >> 3);
				lr = 28 - 4 * (lr & 0x07);
				uint32_t sl = ip_[0];
#if 1
				int r7 = ~(0x0f << lr);
				int fp = e; //sp_0x40;
				r7 = r7 & sl;
//				sl = sl & r7;
				fp = fp & 0x0f;
				ip_[0] = r7/*sl*/ | (fp << lr);
#else
				sl &= ~(0x0f << lr);
				((int*)ip)[0] = /*(sl & ~(0x0f << lr))*/sl | 
					((e/*sp_0x40*/ & 0x0f) << lr);
#endif
			}
			//loc_23408020
			bitmask >>= 1;
			col++;
			if (col >= width)
			{
				col = 0;
				row++;
				height--;
				if (height == 0)
				{
					//->loc_23408060
					return width;
				}
			}
			//loc_23408048
		} //while ((bits--) != 0)
		//loc_23408058
	} //while (height != 0)
	//loc_23408060
	return width;
}


/* 2340811c / 2340a4a8 - todo */
int text_table_init(Struct_235f2e2c* pFlash, int r8)
{
	uint32_t r4;
	int fp;
	int sp4;
	int sp = r8;

	flash_read(pFlash, r8, 4, &sp4);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "text_table_init: sp4=0x%x\r\n", sp4);
		console_send_string(debug_string);
	}
#endif

	fp = 0xffff;

	if (sp4 == 0x1234567)
	{
		sp += 4;

		flash_read(pFlash, sp, 4, &sp4);

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "text_table_init: sp4=0x%x\r\n", sp4);
			console_send_string(debug_string);
		}
#endif

		if (sp4 == 0xfedcba98)
		{
			sp += 4;

			flash_read(pFlash, sp, 4, &sp4); //401b9604

#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "text_table_init: sp4=0x%x\r\n", sp4);
				console_send_string(debug_string);
			}
#endif

			flash_read(pFlash, sp4, 64, &Data_234fc814);
			//r7 = 234fc814
			//sb = 234FC854
			//sl = 234FD894
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "text_table_init: Data_234fc814.Data_0x38=0x%x, Data_234fc814.bData_0=%d\r\n",
						Data_234fc814.Data_0x38, Data_234fc814.bData_0);
				console_send_string(debug_string);
			}
#endif

			sp4 = Data_234fc814.Data_0x38; //401b23a4
			//->loc_234081f4
			for (r4 = 0; r4 < Data_234fc814.bData_0; r4++)
			{
				//loc_234081c4
				struct Struct_234fc854* r5 = &Data_234fc854[r4];

				flash_read(pFlash, sp4, 16, r5);

				Data_234fd894[r4] = r5->bData_12;
#if 1
				{
					extern char debug_string[];
					sprintf(debug_string, "text_table_init: Data_234fd894[%d]=%d\r\n",
							r4, Data_234fd894[r4]);
					console_send_string(debug_string);
				}
#endif
				sp4 += 16;
			}
			//0x23408200
			Data_23491ff8 = pFlash;

			if ((Data_234fc814.bData_1 != 0) && (Data_234fc814.bData_1 < 0x7d))
			{
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "text_table_init: Data_234fc814.Data_0x3c=0x%x, Data_234fc814.bData_1=%d\r\n",
							Data_234fc814.Data_0x3c, Data_234fc814.bData_1);
					console_send_string(debug_string);
				}
#endif

				sp = Data_234fc814.Data_0x3c; //401b23b4
				//r5 = 234fc8f4
				//->loc_23408250
				for (r4 = 0; r4 < Data_234fc814.bData_1; r4++)
				{
					//loc_2340822c
					flash_read(pFlash, sp, 32, &Data_234fc8f4[r4]);

					sp += 32;
				}
				//0x2340825c
				memset(&text_table_languages, 0, 44);
				//r5 = 234fd8ac
				text_table_languages.numLanguages = Data_234fc814.bData_2;

				sp = r8 + 16; //401b0010

#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "text_table_init: sp=0x%x\r\n", sp);
					console_send_string(debug_string);
				}
#endif

				flash_read(pFlash, sp, 4, &sp); //401b9644

#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "text_table_init: sp=0x%x, text_table_languages.numLanguages=%d\r\n",
							sp, text_table_languages.numLanguages);
					console_send_string(debug_string);
				}
#endif

				//->loc_234082b8
				for (r4 = 0; r4 < text_table_languages.numLanguages; r4++) //15
				{
					//loc_2340829c
					flash_read(pFlash, sp + r4 * 4, 4, &text_table_languages.language[r4]);
				}
				//0x234082c4
				text_table_languages.currentLanguage = av_get_language();

				if (text_table_languages.currentLanguage > text_table_languages.numLanguages)
				{
					text_table_languages.currentLanguage = 0;
				}

#if 0
				for (int i = 0; i < 2*0x1bb; i++)
				{
					static char buf[100];
					text_table_get_string(i, buf, sizeof(buf));
					extern char debug_string[];
					sprintf(debug_string, "text id=0x%x: '%s'\r\n", i, buf);
					console_send_string(debug_string);
				}
#endif

				return 0;
			}
		}
	}
	//->loc_23408294
	return fp;
}


/* 234082e8 /  / 2340adc4 - todo */
uint32_t text_table_get_num_languages(void)
{
	return text_table_languages.numLanguages;
}


/* 234082f4 /  / 2340add0 - todo */
void sub_234082f4(void)
{
	text_table_languages.currentLanguage = av_get_language();

#if 0
	if (text_table_languages.currentLanguage >
			text_table_languages.numLanguages)
	{
		text_table_languages.currentLanguage = 0;
	}
#else
	text_table_languages.currentLanguage = (text_table_languages.currentLanguage >
			text_table_languages.numLanguages)? 0: text_table_languages.currentLanguage;
#endif
}


/* 23408604 /  / 2340b0e0 - todo */
int sub_23408604(Graphic_Job_2_5_Item_Text a/*sp_0x58?*/, Graphic_Job_2_5_Item_Text* b/*sp_0x70?*/)
{
#if 0
	console_send_string("sub_23408604 (todo.c): TODO\r\n");
#endif

	uint16_t sp_0x30; //sp_0x30
	int sp_0x2c;
	int sp_0x28;
	uint8_t sp_0x24;
	uint8_t sp_0x20[4];
	uint8_t sp_0x1c;
	int sp_0x18;
	uint16_t sp_0x14;
	uint16_t sp_0x10 = 0;
	int sp_0xc;
	int sp8;

	memcpy(b, &a, 0x18);

	uint16_t sl;
	uint16_t sb;
	uint8_t* r8;
	uint8_t r7;
	uint32_t r6;
	uint16_t r5 = a.x1;
	uint8_t* r4 = a.pString;

	sp_0x30 = r5;
	sl = a.wData_0x14;
	sb = r5;
	sp_0x1c = a.bData_0xd;


	if (r4 == 0)
	{
		return 0;
	}
	//loc_2340865c
	if (*r4 == 3)
	{
		sp_0x1c += 5;
		r4++;
	}

	sp_0x14 = Data_234fd894[sp_0x1c];

	int r0 = sub_23409424(".", sp_0x1c);
	r6 = a.x2;
	r0 = r0 + 2 * r0;
	r7 = a.bData_0xb;

	sp_0x18 = r6 - r0;	
	sp_0x2c = a.bData_0;

	//->loc_2340898c
	while (*r4 != 0)
	{		
		//loc_234086b4
		if (*r4 == 7)
		{
			//0x234086bc
			uint8_t ch = r4[2];
			r8 = r4 + 2;
			if (ch == 0x2b)
			{
				//0x234086cc
				r4 = r8 + 1;
				//r1, sp, #0x20
				for (uint8_t i = 0; i < 3; i++)
				{
					//loc_234086d8
					sp_0x20[i] = *r4++;
				}
				//0x234086f0
				sp_0x20[3] = 0;

				r5 = atoi(&sp_0x20[0]);
				//->loc_2340898c
//				continue;
			} //if (ch == 0x2b)
			else
			{
				//loc_23408708
				int fp = a.bData_0xc;
				sp8 = sp_0x2c;
				sp_0xc = a.y1;

				texttable_load_bitmap((uint16_t)(ch - 0x30), &Data_234f9814[0], 0);

				uint8_t* r4_ = &Data_234f9814[0];
				uint16_t r0;
				if (0 == sub_2342cf84(sp8, r5, sp_0xc, r4_, fp))
				{
					r0 = (r4_[0] << 8) + r4_[1];
					sp_0x10 = (r4_[2] << 8) + r4_[3];
				}
				else
				{
					r0 = 0;
				}
				//loc_23408778
				r4 = r8 + 1;
				r5 += r0;

				if (r5 > sb)
				{
					sb = r5;
				}
				//->loc_2340898c
//			continue;
			}
		} //if (*r4 == 7)
		//loc_23408790
		else if (*r4 == 0x0a)
		{
			//0x23408798
			r5 = sp_0x30;
			r4++;

			uint16_t r0 = sp_0x10;
			if (r0 < sp_0x14)
			{
				r0 = sp_0x14;
			}
			else
			{
				sp_0x10 = 0;
			}
			a.y1 += r0;
			//->loc_2340898c
//			continue;
		} //else if (*r4 == 0x0a)
		//loc_234087c8
		else if (*r4 <= 5)
		{
			r4++;
			//->loc_2340898c
//			continue;
		} //else if (*r4 <= 5)
		else 
		{
			if ((*r4 < 0x20) || 
				((*r4 >= 0x7f) && (*r4 < 0xa0)))
			{
				//0x234087e4 /  / 2340b2c0
				sp_0x24 = ' ';

				sub_23407f24(sp_0x2c, 
					&sp_0x24, 
					r5, 
					a.y1,
					r7,
					sp_0x1c,
					r6);
			}
			//loc_2340880c
			int r0;
			if (sl != 0)
			{
				//0x23408814
				sl--;
				if (sl != 0)
				{
					//->loc_234088c4
					r0 = sub_23407f24(sp_0x2c,
						r4, 
						r5,
						a.y1,
						r7,
						sp_0x1c,
						r6);
				}
				else
				{
					//->loc_234088c4
					r0 = sub_23407f24(sp_0x2c,
						r4, 
						r5,
						a.y1,
						a.bData_0x16,
						sp_0x1c,
						r6);
				}
				//->loc_23408958
			} //if (sl != 0)
			else
			{
				//loc_2340883c
				sp_0x28 = a.y1;

				r0 = sub_23407f24(sp_0x2c,
					r4,
					r5,
					a.y1,
					r7,
					sp_0x1c,
					sp_0x18);

				if (r0 == 0)
				{
					//0x23408870
					uint16_t fp = r5;
					r8 = r4;
					//->loc_2340889c
					while (*r8 != 0)
					{
						//loc_2340887c
						if (*r8 == 0x0a)
						{
							//->loc_234088a8
							break;
						}
						//0x23408884
						int r0 = sub_23409424(r8++, sp_0x1c);
						
						fp += r0;
					}
					//loc_234088a8
					if (r6 > fp)
					{
						//0x234088b0
						sp_0x18 = r6;

						r0 = sub_23407f24(sp_0x2c,
							r4,
							r5,
							sp_0x28,
							r7,
							sp_0x1c,
							sp_0x18);
						//->loc_23408958
					}
					else
					{
						//loc_234088d8
						int r8 = sub_23407f24(sp_0x2c,
							".",
							r5,
							sp_0x28,
							r7,
							sp_0x1c,
							r6);

						r0 = sub_23407f24(sp_0x2c,
							".",
							(uint16_t)(r5 + r8),
							sp_0x28,
							r7,
							sp_0x1c,
							r6);

						r8 += r0;

						r0 = sub_23407f24(sp_0x2c,
							".",
							(uint16_t)(r5 + r8),
							sp_0x28,
							r7,
							sp_0x1c,
							r6);

						r0 += r8;
						r0 += r5;
						sb = r0;

						r0 = 0;
					}
				}
				//loc_23408958
			}
			//loc_23408958
			r5 += r0;

			if (r5 > sb)
			{
				sb = r5;
			}

			r4++;

			if (a.y1/*r2*/ >= (a.y2/*r3*/ - sp_0x14/*r1*/))
			{
				//->loc_23408998
				break;
			}

			if (r0 == 0)
			{
				//->loc_23408998
				break;
			}
			//loc_2340898c
		}
	} //while (*r4 != 0)
	//loc_23408998
	b->x2 = sb;
	b->y2 = a.y1 + sp_0x14;
	//->loc_2340864c
	return 0;
}


/* 23408d10 /  / 2340b7ec - todo */
int sub_23408d10(uint16_t a)
{
#if 0
	console_send_string("sub_23408d10 (todo.c): TODO\r\n");
#endif

	texttable_load_bitmap(a, &Data_234f9814[0], 0);

	return &Data_234f9814[0];
}


/* 23408d28 - complete */
int text_table_get_string(int idx, void* buf, int len)
{
	int addr;

	addr = text_table_languages.language[text_table_languages.currentLanguage] + idx * 4;

	flash_read(Data_23491ff8, addr, 4, &addr);

	flash_read(Data_23491ff8, addr, len, buf);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "text_table_get_string: idx=%d, len=%d, buf='%s'\r\n", idx, len, buf);
		console_send_string(debug_string);
	}
#endif

	return 0;
}


/* 23407e40 - complete */
int sub_23407e40(uint8_t* a, int b, void* sl, int fp)
{
#if 0
	console_send_string("sub_23407e40 (todo.c): TODO\r\n");
#endif

	uint32_t sp;
	uint8_t r1 = b;
	int r8 = 0;
	uint8_t r5 = *a;
	int r6 = Data_234fc854[r1].Data_8;
	uint16_t r4  = Data_234fc854[r1].bData_13;

	flash_read(Data_23491ff8, r6, 12, &Data_234fd8a0);

	while (1)
	{
		//loc_23407e84
		if ((Data_234fd8a0.wData_0 <= r5) &&
			(Data_234fd8a0.wData_2 >= r5))
		{
			//0x23407e9c
			uint16_t r0 = r5 - Data_234fd8a0.wData_0;
			flash_read(Data_23491ff8, Data_234fd8a0.Data_8 + r0 * 2, 4, &sp);

			r0 = sp;
			r8 = Data_234fd8a0.Data_4 + r0 * 2;
			//->loc_23407efc
			break;
		}
		else
		{
			//loc_23407ed4
			r6 += 12;

			flash_read(Data_23491ff8, r6, 12, &Data_234fd8a0);

			r4--;
			if (r4 == 0)
			{
				break;
			}
		}
	}
	//loc_23407efc
	if (r8 == 0)
	{
		return 0xff;
	}

	flash_read(Data_23491ff8, r8, fp, sl);

	return 0;
}


/* 2340beb0 - todo */
int sub_2340beb0(char* a, char* b)
{
#if 1
	console_send_string("sub_2340beb0 (todo.c): TODO\r\n");
#endif

	return 1;
}


/* 23409424 /  / 2340bf00 - complete */
uint16_t sub_23409424(char* a, int b)
{
#if 0
	console_send_string("sub_23409424 (todo.c): TODO\r\n");
#endif

	uint32_t r4 = 0;

	if (0 == sub_23407e40(a, b, &Data_234f9814[0], 4))
	{
		r4 = (((uint16_t*)&Data_234f9814[0])[0] & 0x1f) + 1;
	}

	return r4;
}


#if 0
text id=0x0: 'ger'
text id=0x1: 'Fehlerhaftes Signal!'
text id=0x2: 'Deutsch'
text id=0x3: 'Montag'
text id=0x4: 'Dienstag'
text id=0x5: 'Mittwoch'
text id=0x6: 'Donnerstag'
text id=0x7: 'Freitag'
text id=0x8: 'Samstag'
text id=0x9: 'Sonntag'
text id=0xa: 'Hauptmen▒'
text id=0xb: 'Sendersuche'
text id=0xc: 'Bitte warten ...'
text id=0xd: 'Sendersuche'
text id=0xe: 'Sleep-Timer'
text id=0xf: 'Ausschalten in'
text id=0x10: 'Bild'
text id=0x11: 'TV-/Radioliste l▒schen'
text id=0x12: '---'
text id=0x13: 'Aus'
text id=0x14: 'Ein'
text id=0x15: 'Vorschau'
text id=0x16: 'Kanal'
text id=0x17: 'Bandbreite'
text id=0x18: 'Code Rate'
text id=0x19: 'Frequenz'
text id=0x1a: 'Polarisation'
text id=0x1b: 'Symbolrate'
text id=0x1c: 'Starte Sendersuche'
text id=0x1d: 'Suchmodus'
text id=0x1e: 'Verschl▒sselt'
text id=0x1f: 'Horizontal'
text id=0x20: 'Vertikal'
text id=0x21: 'Antennenspannung'
text id=0x22: 'Antenne'
text id=0x23: 'LOW Band'
text id=0x24: 'HIGH Band'
text id=0x25: 'DiSEqC-Schalter'
text id=0x26: 'Toneburst-Schalter'
text id=0x27: 'keine'
text id=0x28: 'keine Senderinformation'
text id=0x29: 'Kein Empfang'
text id=0x2a: 'Starte Download'
text id=0x2b: 'Jan'
text id=0x2c: 'Feb'
text id=0x2d: 'M▒r'
text id=0x2e: 'Apr'
text id=0x2f: 'Mai'
text id=0x30: 'Jun'
text id=0x31: 'Jul'
text id=0x32: 'Aug'
text id=0x33: 'Sep'
text id=0x34: 'Okt'
text id=0x35: 'Nov'
text id=0x36: 'Dez'
text id=0x37: 'Fehlerhaft'
text id=0x38: 'Senderliste'
text id=0x39: 'Gesamtliste'
text id=0x3a: 'Favoritenliste'
text id=0x3b: 'Radioliste'
text id=0x3c: 'TV-Liste'
text id=0x3d: 'Alphabet'
text id=0x3e: 'Liste w▒hlen'
text id=0x3f: 'Information'
text id=0x40: 'Ger▒teinformationen'
text id=0x41: 'Empfangseigenschaften'
text id=0x42: 'Update'
text id=0x43: 'Software'
text id=0x44: 'Senderliste'
text id=0x45: 'OSD-Texte'
text id=0x46: 'Netzwerk'
text id=0x47: 'Name:'
text id=0x48: 'Programm:'
text id=0x49: 'Status: '
text id=0x4a: 'Einstellungen'
text id=0x4b: 'Zeitverschiebung'
text id=0x4c: 'Std.'
text id=0x4d: 'Alle'
text id=0x4e: 'Einstellungen werden gespeichert,
bitte warten...'
text id=0x4f: 'Daten werden geladen,
bitte warten...'
text id=0x50: 'Allgemein'
text id=0x51: 'Information'
text id=0x52: 'Startlautst▒rke'
text id=0x53: 'Videosignal - Analog'
text id=0x54: 'Bildformat'
text id=0x55: 'Men▒sprache'
text id=0x56: 'Transparenz'
text id=0x57: 'Werkszustand'
text id=0x58: 'Softwareupdate'
text id=0x59: 'Favoritenliste bearbeiten'
text id=0x5a: 'Englisch'
text id=0x5b: 'Deutsch'
text id=0x5c: 'Franz▒sisch'
text id=0x5d: 'Schwedisch'
text id=0x5e: 'D▒nisch'
text id=0x5f: 'Finnisch'
text id=0x60: 'Norwegisch'
text id=0x61: 'Italienisch'
text id=0x62: 'Spanisch'
text id=0x63: 'Holl▒ndisch'
text id=0x64: 'Russisch'
text id=0x65: 'Chinesisch'
text id=0x66: '▒e▒tina'
text id=0x67: 'Magyar'
text id=0x68: 'Rum▒nisch'
text id=0x69: 'Polnisch'
text id=0x6a: 'Portugu▒s'
text id=0x6b: 'Japanisch'
text id=0x6c: 'T▒rkisch'
text id=0x6d: 'Griechisch'
text id=0x6e: 'Ja'
text id=0x6f: 'Nein'
text id=0x70: 'Bildanpassung'
text id=0x71: 'Vollbild'
text id=0x72: 'Empfangskonfiguration'
text id=0x73: 'Letterbox'
text id=0x74: 'Soundeinstellung'
text id=0x75: 'Zentrum'
text id=0x76: 'Video'
text id=0x77: 'Radio'
text id=0x78: 'Pillarbox'
text id=0x79: 'Installation'
text id=0x7a: 'Neue TV-Kan▒le:'
text id=0x7b: 'Stopp'
text id=0x7c: 'Neue Radio-Kan▒le:'
text id=0x7d: 'Suche l▒uft'
text id=0x7e: 'Suche beendet'
text id=0x7f: 'Gesamtliste bearbeiten'
text id=0x80: 'Stereo'
text id=0x81: 'Hardware'
text id=0x82: 'Version'
text id=0x83: 'Bildschirmgrafik'
text id=0x84: 'Einblenddauer'
text id=0x85: 'Speichern?'
text id=0x86: 'FBAS'
text id=0x87: 'RGB'
text id=0x88: 'Y/C'
text id=0x89: 'Ton'
text id=0x8a: 'Kurzschluss/▒berlast am Antenneneingang!'
text id=0x8b: 'Farbe'
text id=0x8c: 'Willkommen'
text id=0x8d: 'Men▒sprache'
text id=0x8e: 'Deutsch'
text id=0x8f: 'English'
text id=0x90: 'Fran▒ais'
text id=0x91: 'Italiano'
text id=0x92: 'T▒rk▒e'
text id=0x93: 'Espa▒ol'
text id=0x94: 'Suomi'
text id=0x95: 'Polski'
text id=0x96: 'Land'
text id=0x97: 'Deutschland'
text id=0x98: 'Frankreich'
text id=0x99: 'Italien'
text id=0x9a: 'Finnland'
text id=0x9b: 'Australien'
text id=0x9c: 'Spanien'
text id=0x9d: '▒sterreich'
text id=0x9e: 'Schweiz'
text id=0x9f: 'Polen'
text id=0xa0: 'Griechenland'
text id=0xa1: 'Antennenspannung'
text id=0xa2: 'Suchergebnis'
text id=0xa3: 'Ok'
text id=0xa4: 'Ausschalten um'
text id=0xa5: 'Uhr'
text id=0xa6: 'Timer'
text id=0xa7: 'Aufnahme-Timer'
text id=0xa8: 'Timer-Platz (1...30)'
text id=0xa9: 'Startzeit'
text id=0xaa: 'Stoppzeit'
text id=0xab: 'Aufnahmedatum'
text id=0xac: 'Programm'
text id=0xad: 'Status'
text id=0xae: ' +160Fehler: Ung▒ltige Startzeit!'
text id=0xaf: ' +160Fehler: Ung▒ltige Stoppzeit!'
text id=0xb0: ' +170Fehler: Ung▒ltiges Startdatum!'
text id=0xb1: ' +170Fehler: Keine Uhrzeit empfangen!'
text id=0xb2: ' +170Fehler: Konflikt mit Timer '
text id=0xb3: ' +150Fehler: Konflikt mit Sleep-Timer!'
text id=0xb4: 'Fehler: Konflikt mit Software-Update-Timer!'
text id=0xb5: ' +100Zur ▒nderung Timer vorher deaktivieren!'
text id=0xb6: ' +170Aufnahme l▒uft!'
text id=0xb7: 'Empfang'
text id=0xb8: 'Antennenspannung (5V)'
text id=0xb9: 'blau'
text id=0xba: 'schwarz'
text id=0xbb: 'orange'
text id=0xbc: 'grau'
text id=0xbd: 'Antenne'
text id=0xbe: 'Transponder'
text id=0xbf: 'Manuell'
text id=0xc0: 'Automatisch'
text id=0xc1: 'Tonkanal Digital'
text id=0xc2: 'Wie Tonkanal TV'
text id=0xc3: 'Untertitel'
text id=0xc4: 'Untertitelsprache'
text id=0xc5: 'Videokanal'
text id=0xc6: 'Tonkanal TV'
text id=0xc7: 'Mono links'
text id=0xc8: 'Mono rechts'
text id=0xc9: 'Dolby Digital'
text id=0xca: 'Neue Software verf▒gbar'
text id=0xcb: 'Warte auf %s...'
text id=0xcc: 'Ihre Software ist aktuell!'
text id=0xcd: 'Lade Info f▒r %s'
text id=0xce: 'Bitte erst Info f▒r Software laden'
text id=0xcf: 'Bitte erst Info f▒r Senderliste laden'
text id=0xd0: 'Bitte erst Info f▒r OSD-Texte laden'
text id=0xd1: 'Bitte warten...'
text id=0xd2: 'Software empfangen'
text id=0xd3: 'Senderliste empfangen'
text id=0xd4: 'OSD-Texte empfangen'
text id=0xd5: 'Compilation am: '
text id=0xd6: 'Info ▒ber Software empfangen'
text id=0xd7: 'Info ▒ber Senderliste empfangen'
text id=0xd8: 'Info ▒ber OSD-Texte empfangen'
text id=0xd9: 'Info ▒ber Software verf▒gbar'
text id=0xda: 'Info ▒ber Senderliste verf▒gbar'
text id=0xdb: 'Info ▒ber OSD-Texte verf▒gbar'
text id=0xdc: 'Umschalten auf Updatekanal'
text id=0xdd: 'Suche Herstellerdaten'
text id=0xde: 'Herstellerdaten gefunden'
text id=0xdf: 'Suche Ger▒tedaten'
text id=0xe0: 'Ger▒tedaten gefunden'
text id=0xe1: 'Suche Updateinformationen'
text id=0xe2: 'Ein Update ist nicht m▒glich'
text id=0xe3: 'DiSEqC-Modus'
text id=0xe4: 'Motor-Einstellungen'
text id=0xe5: 'Antennenposition'
text id=0xe6: ' '
text id=0xe7: ' '
text id=0xe8: ' '
text id=0xe9: ' '
text id=0xea: ' '
text id=0xeb: ' '
text id=0xec: ' '
text id=0xed: ' '
text id=0xee: ' '
text id=0xef: 'Speichern'
text id=0xf0: 'Osten'
text id=0xf1: 'Westen'
text id=0xf2: 'Modulation'
text id=0xf3: ' W Ausw▒hlen +280 8 Zur▒ck
        und aufrufen'
text id=0xf4: ' X Ausw▒hlen +280 8 Zur▒ck
        und ▒ndern'
text id=0xf5: ' R Ausw▒hlen +280 8 Zur▒ck
        und ▒ndern'
text id=0xf6: ' W Ausw▒hlen +280 8 Zur▒ck +420 F Information
        und ▒ndern'
text id=0xf7: ' W Ausw▒hlen +280 8 Zur▒ck
        und ▒ndern'
text id=0xf8: ' X Ausw▒hlen +280 8 Zur▒ck
        und ▒ndern +286 :  Wechseln'
text id=0xf9: ' R Ausw▒hlen +280 8 Zur▒ck +440 D L▒schen
        und markieren +280 F Verschieben'
text id=0xfa: ' R Programm +280 8 Zur▒ck +440 7 Liste
        ausw▒hlen'
text id=0xfb: ' R Ausw▒hlen +280 8 Zur▒ck +440 7 Liste
        und best▒tigen +286 :  Wechseln'
text id=0xfc: ' R Ausw▒hlen +280 8 Zur▒ck +440 D L▒schen
        und markieren +286 :  Wechseln'
text id=0xfd: ' R Ausw▒hlen +280 8 Zur▒ck
        und markieren +286 :  Wechseln'
text id=0xfe: ' R Ausw▒hlen +280 8 Zur▒ck +440 D L▒schen
        und einf▒gen +286 :  Wechseln +440 F VersNBEMON/SmartHD/0155'
text id=0xff: 'Ausw▒hlen
und aufrufen'
text id=0x100: ' R Ausw▒hlen +280 8 Zur▒ck
        und aufrufen'
text id=0x101: ' R Ausw▒hlen +280 8 Zur▒ck +450 3 Progr. +560+
        und aufrufen +286 b  Aufnehmen +450NBEMON/SmartHD/0155'
text id=0x102: ' V N▒chste +280 8 Zur▒ck
        Seite'
text id=0x103: ' S Ausw▒hlen +280 8 Zur▒ck
        und ▒ndern'
text id=0x104: ' +280 8 Zur▒ck'
text id=0x105: ' W Ausw▒hlen +280 8 Zur▒ck +440 D L▒schen
        und markieren'
text id=0x106: ' V Ausw▒hlen +280 8 Zur▒ck
        und ▒ndern'
text id=0x107: ' R Ausw▒hlen +265 8 Zur▒ck +450 D L▒schen
        und aufrufen +265 G Umbenennen  +450 7 SoNBEMON/SmartHD/0155'
text id=0x108: 'Bitte warten, Antenne wird gedreht...'
text id=0x109: ' +280 8 Zur▒ck'
text id=0x10a: 'Pay-TV Sender l▒schen'
text id=0x10b: 'Alle Programme l▒schen'
text id=0x10c: 'Tschechien'
text id=0x10d: ' R Ausw▒hlen +235 8 Zur▒ck +360  D Links +460  G Rechts
        u. ▒ndern +235 F L▒schen +NBEMON/SmartHD/0155'
text id=0x10e: 'Wiederg.'
text id=0x10f: 'Aufnahme'
text id=0x110: 'Wollen Sie die Aufnahme sichern?'
text id=0x111: '   L▒schen?'
text id=0x112: 'Festplatte ausschalten'
text id=0x113: 'AUFNAHMEN'
text id=0x114: 'Endzeit'
text id=0x115: 'Aufnehmen auf'
text id=0x116: 'Festplatte'
text id=0x117: 'Videorekorder'
text id=0x118: 'Aufnahmespeicher'
text id=0x119: 'Information'
text id=0x11a: 'Formatieren'
text id=0x11b: ' +165Fehler: Zu wenig freier Speicher!'
text id=0x11c: ' +165Fehler: Festplatte nicht formatiert!'
text id=0x11d: 'Wiederholung'
text id=0x11e: 'T▒glich'
text id=0x11f: 'W▒chentlich'
text id=0x120: 'Timer aktivieren'
text id=0x121: 'Timer deaktivieren'
text id=0x122: ' (aktiv)'
text id=0x123: ' (inaktiv)'
text id=0x124: 'Formatieren?'
text id=0x125: 'Aufnahmen: %d von %d'
text id=0x126: 'Freier Speicher: %dMB'
text id=0x127: 'Kindersicherung'
text id=0x128: 'Ger▒tesperre'
text id=0x129: 'Neue PIN'
text id=0x12a: 'PIN best▒tigen'
text id=0x12b: 'PIN ▒ndern'
text id=0x12c: 'Ger▒t sperren'
text id=0x12d: 'PIN eingeben'
text id=0x12e: 'Falsche PIN! Bitte neu eingeben...'
text id=0x12f: 'USB-Speicher nicht formatiert.'
text id=0x130: 'Das Dateisystem Ihres Ger▒tes ist nicht mehr aktuell.
Sie m▒ssen die Festplatte neu formatieren.
AcNBEMON/SmartHD/0155'
text id=0x131: 'Aufnahmespeicher voll! '
text id=0x132: 'Speicher fehlt/unformatiert!'
text id=0x133: 'Diese Liste hat keinen Eintrag!'
text id=0x134: 'Alphabetisch'
text id=0x135: ' '
text id=0x136: 'Archivierung'
text id=0x137: 'Aufnahmel▒nge'
text id=0x138: 'Dateisystem testen'
text id=0x139: 'Aufnahme beenden'
text id=0x13a: 'sofort'
text id=0x13b: 'in 15 Minuten'
text id=0x13c: 'in 45 Minuten'
text id=0x13d: 'in 120 Minuten'
text id=0x13e: 'in 180 Minuten'
text id=0x13f: ' +065Fehler: Konflikt mit Aufnahme-Beenden-Timer!'
text id=0x140: 'Defekte Aufnahme: %d/%d'
text id=0x141: 'Teste Aufnahme: %d/%d'
text id=0x142: 'Aufnahme l▒schen?'
text id=0x143: 'Test beenden?'
text id=0x144: 'Antennenanschluss'
text id=0x145: 'Nur IF DIGITAL IN B'
text id=0x146: 'IF DIGITAL IN A u. B'
text id=0x147: ' >Eingang 720x576'
text id=0x148: ' >Eingang 1280x720'
text id=0x149: ' >Eingang 1920x1080'
text id=0x14a: 'Ausgang 720x576'
text id=0x14b: 'Ausgang 1280x720'
text id=0x14c: 'Ausgang 1920x1080'
text id=0x14d: 'Hotelmode'
text id=0x14e: 'Bildskalierung:'
text id=0x14f: 'Svenska'
text id=0x150: ' +100Aufnahme l▒uft. Abbrechen?'
text id=0x151: 'komprimiert (Bitstrom)'
text id=0x152: 'unkomprimiert (PCM)'
text id=0x153: ' R Ausw▒hlen +280 8 Zur▒ck +420 : Wechseln'
text id=0x154: 'Portugal'
text id=0x155: 'Deep-Standby'
text id=0x156: 'HDMI Audio Bitstrom'
text id=0x157: 'Terrestrisch'
text id=0x158: 'Kabel'
text id=0x159: 'Ungarn'
text id=0x15a: ' R Ausw▒hlen +280 8 Zur▒ck
  +280 7 Senderliste speichern'
text id=0x15b: 'ARCHIV'
text id=0x15c: 'Daten werden gespeichert,
bitte warten...'
text id=0x15d: 'Netzwerk'
text id=0x15e: 'IP-Adresse'
text id=0x15f: 'Subnet-Maske'
text id=0x160: 'Gateway'
text id=0x161: ' i Ausw▒hlen +280 j Zur▒ck
        und aufrufen'
text id=0x162: ' k Ausw▒hlen +280 j Zur▒ck
        und ▒ndern'
text id=0x163: ' l Ausw▒hlen +280 j Zur▒ck
        und ▒ndern'
text id=0x164: ' m Ausw▒hlen +280 j Zur▒ck
        und ▒ndern'
text id=0x165: ' p Ausw▒hlen +280 j Zur▒ck
        und ▒ndern'
text id=0x166: ' m Ausw▒hlen +280 j Zur▒ck +440 q L▒schen
        und markieren +280 r Wechseln'
text id=0x167: ' m Ausw▒hlen +280 j Zur▒ck +440 q L▒schen
        und markieren +280 s Verschieben'
text id=0x168: ' m Ausw▒hlen +280 j Zur▒ck
        und markieren +280 r Wechseln'
text id=0x169: ' m Ausw▒hlen +280 j Zur▒ck +440 q L▒schen
        und einf▒gen +280 r Wechseln +440 s VerscNBEMON/SmartHD/0155'
text id=0x16a: ' i Ausw▒hlen +280 j Zur▒ck +440 q L▒schen
        und markieren'
text id=0x16b: ' k Ausw▒hlen +280 j Zur▒ck
        und ▒ndern +280 r Wechseln'
text id=0x16c: ' +280 j Zur▒ck'
text id=0x16d: ' m Programm +280 j Zur▒ck +440 u Liste
        ausw▒hlen'
text id=0x16e: ' m Ausw▒hlen +280 j Zur▒ck +440 u Liste
        und best▒tigen +280 r Wechseln'
text id=0x16f: ' m Ausw▒hlen +280 j Zur▒ck +450 { Progr. +545+
        und aufrufen +280 v Aufnehmen +450 NBEMON/SmartHD/0155'
text id=0x170: ' m Ausw▒hlen +280 j Zur▒ck +430 r Wechseln'
text id=0x171: ' m Ausw▒hlen +280 j Zur▒ck +450 q L▒schen
        und aufrufen +280 t Umbenennen  +450 u SoNBEMON/SmartHD/0155'
text id=0x172: ' m Ausw▒hlen +245 j Zur▒ck +365  q Links +465  t Rechts
        u. ▒ndern +245 s L▒schen +NBEMON/SmartHD/0155'
text id=0x173: ' m Ausw▒hlen +280 j Zur▒ck
  +280 u Senderliste speichern'
text id=0x174: ' l N▒chste +280 j Zur▒ck
        Seite'
text id=0x175: 'Aufnahmespeicher neu formatiert'
text id=0x176: 'Videosystem'
text id=0x177: 'SCR (Sat Channel Router)'
text id=0x178: 'SCR-ID'
text id=0x179: 'Satellitenempfang'
text id=0x17a: 'Standard'
text id=0x17b: 'Speichern'
text id=0x17c: 'SCR-ID - Tuner A'
text id=0x17d: 'SCR-ID - Tuner B'
text id=0x17e: 'Auto-Standby'
text id=0x17f: 'Auto-Standby in %ds. Abbrechen?'
text id=0x180: 'Dansk'
text id=0x181: 'Slovenski'
text id=0x182: 'D▒nemark'
text id=0x183: 'Slovenien'
text id=0x184: 'Senderaktualisierung speichern?'
text id=0x185: 'Sendersortierung'
text id=0x186: 'Videosignal - Digital'
text id=0x187: 'Schweden'
text id=0x188: 'Netzwerk ID'
text id=0x189: 'Nicht verf▒gbar'
text id=0x18a: 'Senderaktualisierung'
text id=0x18b: 'gr▒n'
text id=0x18c: 'Design'
text id=0x18d: 'Version 1'
text id=0x18e: 'Version 2'
text id=0x18f: 'Timer-Speicherung'
text id=0x190: ' W Ausw▒hlen +280 8 Zur▒ck +420 4 Startzeit -
        und best▒tigen +420 5 Stoppzeit +'
text id=0x191: ' i  +400 p  +128Ausw▒hlen +280 j Zur▒ck +450 Startzeit -
        und best▒tigen +450 StoppzeNBEMON/SmartHD/0155'
text id=0x192: 'EQUALIZER'
text id=0x193: '>Bass   '
text id=0x194: '>Middle '
text id=0x195: '>Treble '
text id=0x196: 'Lautsprecher'
text id=0x197: '>Loudness'
text id=0x198: '>3Deffekt'
text id=0x199: '>Balance'
text id=0x19a: 'ANSCHL▒SSE'
text id=0x19b: 'Aux '
text id=0x19c: 'Audio-Verst▒rker'
text id=0x19d: '>Anzeige Sendername'
text id=0x19e: '>Standard-Equalizer'
text id=0x19f: '>Standard-Eingang'
text id=0x1a0: 'Ein- und Ausg▒nge'
text id=0x1a1: 'Equalizereinstellung'
text id=0x1a2: 'Ein f▒r Radio'
text id=0x1a3: 'USB (R▒ckseite)'
text id=0x1a4: 'USB (Frontseite)'
text id=0x1a5: 'DHCP'
text id=0x1a6: 'DNS-Server'
text id=0x1a7: ' R Programm +280 8 Zur▒ck +440 7 Speichern
        ausw▒hlen'
text id=0x1a8: ' m Programm +280 j Zur▒ck +440 u Speichern
        ausw▒hlen'
text id=0x1a9: 'T▒rkei'
text id=0x1aa: ' +280 8 Speichern'
text id=0x1ab: ' +280 j Speichern'
text id=0x1ac: 'Neue Software verf▒gbar. Speichern?'
text id=0x1ad: 'HDMI'
text id=0x1ae: 'Update-Server'
text id=0x1af: 'Streaming Option'
text id=0x1b0: 'CEC'
text id=0x1b1: 'CEC Standby'
text id=0x1b2: 'Internet Radio'
text id=0x1b3: 'Liechtenstein'
text id=0x1b4: 'Zieladresse'
text id=0x1b5: 'Zielport'
text id=0x1b6: 'Kabelnetz'
text id=0x1b7: 'Nederlands'
text id=0x1b8: 'Niederlande'
text id=0x1b9: 'Belgien'
text id=0x1ba: 'N'
#endif

#if 0
text id=0x1bb: 'eng'
text id=0x1bc: 'No valid signal!'
text id=0x1bd: 'English'
text id=0x1be: 'Monday'
text id=0x1bf: 'Tuesday'
text id=0x1c0: 'Wednesday'
text id=0x1c1: 'Thursday'
text id=0x1c2: 'Friday'
text id=0x1c3: 'Saturday'
text id=0x1c4: 'Sunday'
text id=0x1c5: 'Main menu'
text id=0x1c6: 'Channel search'
text id=0x1c7: 'Please wait ...'
text id=0x1c8: 'Channel search'
text id=0x1c9: 'Sleep timer'
text id=0x1ca: 'Turn off in'
text id=0x1cb: 'Picture'
text id=0x1cc: 'Delete channel list'
text id=0x1cd: '---'
text id=0x1ce: 'Off'
text id=0x1cf: 'On'
text id=0x1d0: 'EPG'
text id=0x1d1: 'Channel'
text id=0x1d2: 'Bandwidth'
text id=0x1d3: 'Code rate'
text id=0x1d4: 'Frequency'
text id=0x1d5: 'Polarisation'
text id=0x1d6: 'Symbol rate'
text id=0x1d7: 'Start scan'
text id=0x1d8: 'Search mode'
text id=0x1d9: 'Encrypted'
text id=0x1da: 'Horizontal'
text id=0x1db: 'Vertical'
text id=0x1dc: 'Antenna power'
text id=0x1dd: 'Antenna'
text id=0x1de: 'LOW band'
text id=0x1df: 'HIGH band'
text id=0x1e0: 'DiSEqC switch'
text id=0x1e1: 'Toneburst switch'
text id=0x1e2: 'nothing'
text id=0x1e3: 'No information'
text id=0x1e4: 'Signal lock lost!'
text id=0x1e5: 'Start download'
text id=0x1e6: 'Jan'
text id=0x1e7: 'Feb'
text id=0x1e8: 'Mar'
text id=0x1e9: 'Apr'
text id=0x1ea: 'May'
text id=0x1eb: 'Jun'
text id=0x1ec: 'Jly'
text id=0x1ed: 'Aug'
text id=0x1ee: 'Sep'
text id=0x1ef: 'Oct'
text id=0x1f0: 'Nov'
text id=0x1f1: 'Dec'
text id=0x1f2: 'Error'
text id=0x1f3: 'Channel list'
text id=0x1f4: 'Main list'
text id=0x1f5: 'Favourites list'
text id=0x1f6: 'Radio list'
text id=0x1f7: 'TV List'
text id=0x1f8: 'Alphabetic list'
text id=0x1f9: 'Select list'
text id=0x1fa: 'Information'
text id=0x1fb: 'System information'
text id=0x1fc: 'Signal characteristics'
text id=0x1fd: 'Download'
text id=0x1fe: 'Software'
text id=0x1ff: 'Channel list'
text id=0x200: 'OSD texts'
text id=0x201: 'Network'
text id=0x202: 'Name:'
text id=0x203: 'Station:'
text id=0x204: 'Current status: '
text id=0x205: 'Settings'
text id=0x206: 'Time difference'
text id=0x207: 'hrs.'
text id=0x208: 'all'
text id=0x209: 'Saving modifications,
please wait...'
text id=0x20a: 'Loading data, please wait...'
text id=0x20b: 'Receiver setup'
text id=0x20c: 'Information'
text id=0x20d: 'Initial volume'
text id=0x20e: 'Analog video'
text id=0x20f: 'Display format'
text id=0x210: 'Menu language'
text id=0x211: 'OSD transparency'
text id=0x212: 'Factory reset'
text id=0x213: 'Software download'
text id=0x214: 'Edit favourites list'
text id=0x215: 'English'
text id=0x216: 'German'
text id=0x217: 'French'
text id=0x218: 'Swedish'
text id=0x219: 'Danish'
text id=0x21a: 'Finnish'
text id=0x21b: 'Norwegian'
text id=0x21c: 'Italian'
text id=0x21d: 'Spanish'
text id=0x21e: 'Dutch'
text id=0x21f: 'Russian'
text id=0x220: 'Chinese'
text id=0x221: '▒e▒tina'
text id=0x222: 'Magyar'
text id=0x223: 'Rumanian'
text id=0x224: 'Polish'
text id=0x225: 'Portuguese'
text id=0x226: 'Japanese'
text id=0x227: 'Turkish'
text id=0x228: 'Greek'
text id=0x229: 'Yes'
text id=0x22a: 'No'
text id=0x22b: 'Display adjustment'
text id=0x22c: 'Full format'
text id=0x22d: 'Antenna configuration'
text id=0x22e: 'Letterbox'
text id=0x22f: 'Sound settings'
text id=0x230: 'Centrum'
text id=0x231: 'Video'
text id=0x232: 'Radio'
text id=0x233: 'Pillarbox'
text id=0x234: 'Installation'
text id=0x235: 'New video:'
text id=0x236: 'Stop'
text id=0x237: 'New radio:'
text id=0x238: 'Scanning'
text id=0x239: 'Finished'
text id=0x23a: 'Edit main list'
text id=0x23b: 'Stereo'
text id=0x23c: 'Hardware'
text id=0x23d: 'Version'
text id=0x23e: 'OSD configuration'
text id=0x23f: 'Display time'
text id=0x240: 'Save?'
text id=0x241: 'FBAS'
text id=0x242: 'RGB'
text id=0x243: 'Y/C'
text id=0x244: 'Sound'
text id=0x245: 'Short circuit or overlaod at the antenna input!'
text id=0x246: 'OSD colour'
text id=0x247: 'Welcome'
text id=0x248: 'Menu language'
text id=0x249: 'Deutsch'
text id=0x24a: 'English'
text id=0x24b: 'Fran▒ais'
text id=0x24c: 'Italiano'
text id=0x24d: 'T▒rk▒e'
text id=0x24e: 'Espa▒ol'
text id=0x24f: 'Suomi'
text id=0x250: 'Polski'
text id=0x251: 'Country'
text id=0x252: 'Germany'
text id=0x253: 'France'
text id=0x254: 'Italy'
text id=0x255: 'Finland'
text id=0x256: 'Australia'
text id=0x257: 'Spain'
text id=0x258: 'Austria'
text id=0x259: 'Switzerland'
text id=0x25a: 'Poland'
text id=0x25b: 'Greece'
text id=0x25c: 'Antenna power'
text id=0x25d: 'Search result'
text id=0x25e: 'Ok'
text id=0x25f: 'Switch-off time'
text id=0x260: 'o'clock'
text id=0x261: 'Timer'
text id=0x262: 'Record timer'
text id=0x263: 'Timer index (1...30)'
text id=0x264: 'Start at'
text id=0x265: 'Stop time'
text id=0x266: 'Date of recording'
text id=0x267: 'Station'
text id=0x268: 'Status'
text id=0x269: ' +190Error: Invalid start time!'
text id=0x26a: ' +160Error: Start time before stop time!'
text id=0x26b: ' +170Error: Start time too far away!'
text id=0x26c: ' +200Error: No time received!'
text id=0x26d: ' +180Error: Conflict with timer '
text id=0x26e: ' +160Error: Conflict with sleep timer!'
text id=0x26f: ' +100Error: Conflict with software update timer!'
text id=0x270: ' +120Deactivate the timer before changing!'
text id=0x271: ' +160Device is recording!'
text id=0x272: 'Reception'
text id=0x273: 'Antenna Power (5V)'
text id=0x274: 'blue'
text id=0x275: 'black'
text id=0x276: 'orange'
text id=0x277: 'gray'
text id=0x278: 'Satellite'
text id=0x279: 'Transponder'
text id=0x27a: 'manually'
text id=0x27b: 'automatically'
text id=0x27c: 'Sound channel Dig.'
text id=0x27d: 'Same as TV'
text id=0x27e: 'Subtitle'
text id=0x27f: 'Subtitle language'
text id=0x280: 'Video channel'
text id=0x281: 'Sound channel TV'
text id=0x282: 'Mono left'
text id=0x283: 'Mono right'
text id=0x284: 'Dolby Digital'
text id=0x285: 'New software available'
text id=0x286: 'Waiting for %s...'
text id=0x287: 'Your software is up to date'
text id=0x288: 'Loading info about %s'
text id=0x289: 'Please load info for software first'
text id=0x28a: 'Please load info for channel list first'
text id=0x28b: 'Please load info for OSD texts first'
text id=0x28c: 'Please wait...'
text id=0x28d: 'Software received'
text id=0x28e: 'Channel list received'
text id=0x28f: 'OSD texts received'
text id=0x290: 'Compilation at: '
text id=0x291: 'Info about software received'
text id=0x292: 'Info about list info received'
text id=0x293: 'Info about OSD texts received'
text id=0x294: 'Info about software is available'
text id=0x295: 'Info about channel list is available'
text id=0x296: 'Info about OSD texte is available'
text id=0x297: 'Switching to update channel'
text id=0x298: 'Searching for manufacturer data'
text id=0x299: 'Manufacturer data found'
text id=0x29a: 'Searching for receiver data'
text id=0x29b: 'Receiver data found'
text id=0x29c: 'Searching for update information'
text id=0x29d: 'The receiver could not be updated'
text id=0x29e: 'DiSEqC mode'
text id=0x29f: 'Motor settings'
text id=0x2a0: 'Antenna position'
text id=0x2a1: ' '
text id=0x2a2: ' '
text id=0x2a3: ' '
text id=0x2a4: ' '
text id=0x2a5: ' '
text id=0x2a6: ' '
text id=0x2a7: ' '
text id=0x2a8: ' '
text id=0x2a9: ' '
text id=0x2aa: 'Save'
text id=0x2ab: 'East'
text id=0x2ac: 'West'
text id=0x2ad: 'Modulation'
text id=0x2ae: ' W Select +280 8 Back
        and open'
text id=0x2af: ' X Select +280 8 Back
        and change'
text id=0x2b0: ' R Select +280 8 Back
        and change'
text id=0x2b1: ' W Select +280 8 Back +420 F Information
        and change'
text id=0x2b2: ' W Select +280 8 Back
        and change'
text id=0x2b3: ' X Select +280 8 Back
        and change +287 :  Swap'
text id=0x2b4: ' R Select +280 8 Back +440 D Delete
        and highlight +280 F Move'
text id=0x2b5: ' R Station +280 8 Back +440 7 List
        select'
text id=0x2b6: ' R Select +280 8 Back +440 7 List
        and open +287 :  Swap'
text id=0x2b7: ' R Select +280 8 Back +420 D Delete
        and open +287 :  Swap'
text id=0x2b8: ' R Select +280 8 Back
        and highlight +287 :  Swap'
text id=0x2b9: ' R Select +280 8 Back +440 D Delete
        and insert +287 :  Swap +440 F Move'
text id=0x2ba: 'Select
and open'
text id=0x2bb: ' R Select +280 8 Back
        and open'
text id=0x2bc: ' R Select +280 8 Back +440 3 Station +556+
        and open +285 b  Record +440 2 StationNBEMON/SmartHD/0155'
text id=0x2bd: ' V Next +280 8 Back
        page'
text id=0x2be: ' S Select +280 8 Back
        and change'
text id=0x2bf: ' +280 8 Back'
text id=0x2c0: ' W Select +280 8 Back +440 D Delete
        and highlight'
text id=0x2c1: ' V Select +280 8 Back
        and change'
text id=0x2c2: ' W Select +280 8 Back +440 D Delete
        and open +280 G Rename +440 7 Sort'
text id=0x2c3: 'Please wait, antenna is moving...'
text id=0x2c4: ' +280 8 Back'
text id=0x2c5: 'Delete Pay-TV stations'
text id=0x2c6: 'Delete all channels'
text id=0x2c7: 'Czech rep.'
text id=0x2c8: ' R Select +245 8 Back +357 D Previous  G Next
        and change +245 F Delete +357 E UppeNBEMON/SmartHD/0155'
text id=0x2c9: 'Play'
text id=0x2ca: 'Recording'
text id=0x2cb: 'Do you want to save the recording?'
text id=0x2cc: '   Delete?'
text id=0x2cd: 'Harddisk standby'
text id=0x2ce: 'Record list'
text id=0x2cf: 'End time'
text id=0x2d0: 'Record to'
text id=0x2d1: 'Harddisk'
text id=0x2d2: 'Video recorder'
text id=0x2d3: 'Mass Storage Device'
text id=0x2d4: 'Information'
text id=0x2d5: 'Formatting'
text id=0x2d6: ' +165Error: Not enough space available!'
text id=0x2d7: ' +165Error: Harddisk not formatted'
text id=0x2d8: 'Repetitions'
text id=0x2d9: 'Daily'
text id=0x2da: 'Weekly'
text id=0x2db: 'Activate'
text id=0x2dc: 'Deactivate'
text id=0x2dd: ' (active)'
text id=0x2de: ' (inactive)'
text id=0x2df: 'Format?'
text id=0x2e0: 'Recordings: %d of %d'
text id=0x2e1: 'Available space: %dMB'
text id=0x2e2: 'Parental lock'
text id=0x2e3: 'Device lock'
text id=0x2e4: 'New PIN'
text id=0x2e5: 'Confirm PIN'
text id=0x2e6: 'Change PIN'
text id=0x2e7: 'Lock device'
text id=0x2e8: 'Enter PIN'
text id=0x2e9: 'Wrong PIN! Please reenter PIN...'
text id=0x2ea: 'Harddisk is not formatted.'
text id=0x2eb: 'The file system of your receiver is not up to date.
Therefore you have to format the hard disk.
AtNBEMON/SmartHD/0155'
text id=0x2ec: 'Harddisk full! '
text id=0x2ed: 'No/unformatted USB memory!'
text id=0x2ee: 'This list is empty!'
text id=0x2ef: 'Alphabetically'
text id=0x2f0: 'Sort list'
text id=0x2f1: 'Entry'
text id=0x2f2: 'Record Length'
text id=0x2f3: 'Test filesystem'
text id=0x2f4: 'Stop recording'
text id=0x2f5: 'now'
text id=0x2f6: 'in 15 min'
text id=0x2f7: 'in 45 min'
text id=0x2f8: 'in 120 min'
text id=0x2f9: 'in 180 min'
text id=0x2fa: ' +065ERROR: Conflict with Record-Stop-Timer!'
text id=0x2fb: 'Defect record: %d/%d'
text id=0x2fc: 'Check record: %d/%d'
text id=0x2fd: 'Delete record?'
text id=0x2fe: 'Stop test?'
text id=0x2ff: 'Antenna input'
text id=0x300: 'IF DIGITAL IN B only'
text id=0x301: 'IF DIGITAL IN A + B'
text id=0x302: ' >Input 720x576'
text id=0x303: ' >Input 1280x720'
text id=0x304: ' >Input 1920x1080'
text id=0x305: 'Output 720x576'
text id=0x306: 'Output 1280x720'
text id=0x307: 'Output 1920x1080'
text id=0x308: 'Hotel mode'
text id=0x309: 'Picture scaling:'
text id=0x30a: 'Svenska'
text id=0x30b: ' +100Record active. Stop?'
text id=0x30c: 'compressed (Bitstream)'
text id=0x30d: 'uncompressed (PCM)'
text id=0x30e: ' R Select +280 8 Back +420 : Swap'
text id=0x30f: 'Portugal'
text id=0x310: 'Low-Power standby'
text id=0x311: 'HDMI Audio Bitstream'
text id=0x312: 'Terrestrial'
text id=0x313: 'Cable'
text id=0x314: 'Hungary'
text id=0x315: ' W Select +280 8 Back
  +280 7 Store channel list'
text id=0x316: 'Archive'
text id=0x317: 'Saving data,
please wait...'
text id=0x318: 'Network'
text id=0x319: 'IP Address'
text id=0x31a: 'Subnet Mask'
text id=0x31b: 'Gateway'
text id=0x31c: ' i Select +280 j Back
        and open'
text id=0x31d: ' k Select +280 j Back
        and change'
text id=0x31e: ' l Select +280 j Back
        and change'
text id=0x31f: ' m Select +280 j Back
        and change'
text id=0x320: ' p Select +280 j Back
        and change'
text id=0x321: ' m Select +280 j Back +420 q Delete
        and open +280 r Swap'
text id=0x322: ' m Select +280 j Back +420 q Delete
        and highlight +280 s Move'
text id=0x323: ' m Select +280 j Back
        and highlight +280 r Swap'
text id=0x324: ' m Select +280 j Back +440 q Delete
        and insert +280 r Swap +440 s Move'
text id=0x325: ' i Select +280 j Back +440 q Delete
        and highlight'
text id=0x326: ' k Select +280 j Back
        and change +280 r Swap'
text id=0x327: ' +280 j Back'
text id=0x328: ' m Station +280 j Back +440 u List
        select'
text id=0x329: ' m Select +280 j Back +440 u List
        and open +280 r Swap'
text id=0x32a: ' m Select +280 j Back +440 { Station +541+
        and open +280 v Record +440 | Station NBEMON/SmartHD/0155'
text id=0x32b: ' m Select +280 j Back +390 r Swap'
text id=0x32c: ' m Select +250 j Back +440 q Delete
        and open +250 t Rename +440 u Sort'
text id=0x32d: ' m Select +250 j Back +362 q Previous   t Next
        and change +250 s Delete +362 w UppNBEMON/SmartHD/0155'
text id=0x32e: ' m Select +280 j Back
  +280 u Store channel list'
text id=0x32f: ' l Next +280 j Back
        page'
text id=0x330: 'Mass Storage Device reformatted'
text id=0x331: 'Video system'
text id=0x332: 'SCR (Sat Channel Router)'
text id=0x333: 'SCR-ID'
text id=0x334: 'Satellite Reception'
text id=0x335: 'Standard'
text id=0x336: 'Store'
text id=0x337: 'SCR-ID - Tuner A'
text id=0x338: 'SCR-ID - Tuner B'
text id=0x339: 'Auto-Standby'
text id=0x33a: 'Auto-Standby in %ds. Cancel?'
text id=0x33b: 'Dansk'
text id=0x33c: 'Slovenski'
text id=0x33d: 'Denmark'
text id=0x33e: 'Slovenia'
text id=0x33f: 'Channel list updated. Store?'
text id=0x340: 'Channel list sorting'
text id=0x341: 'Digital video'
text id=0x342: 'Sweden'
text id=0x343: 'Network ID'
text id=0x344: 'Not available'
text id=0x345: 'Channel list update'
text id=0x346: 'green'
text id=0x347: 'Shape'
text id=0x348: 'Version 1'
text id=0x349: 'Version 2'
text id=0x34a: 'Timer storage'
text id=0x34b: ' W Select +280 8 Back +400 4 Start time -
        and confirm +400 5 Stop time +'
text id=0x34c: ' i  +400 p  +128Select +280 j Back +450 Start time -
        and confirm +450 Stop time +'
text id=0x34d: 'EQUALIZER'
text id=0x34e: '>Bass   '
text id=0x34f: '>Middle '
text id=0x350: '>Treble'
text id=0x351: 'Speaker'
text id=0x352: '>Loudness'
text id=0x353: '>3D effect'
text id=0x354: '>Balance'
text id=0x355: 'CONNECTIONS'
text id=0x356: 'Aux '
text id=0x357: 'Audio amplifier'
text id=0x358: '>Display channel name'
text id=0x359: '>Standard equalizer'
text id=0x35a: '>Standard input'
text id=0x35b: 'Inputs and Outputs'
text id=0x35c: 'Equalizer setup'
text id=0x35d: 'On for radio only'
text id=0x35e: 'USB (rear)'
text id=0x35f: 'USB (front)'
text id=0x360: 'DHCP'
text id=0x361: 'DNS Server'
text id=0x362: ' R Select +280 8 Back +440 7 Store
        channel'
text id=0x363: ' m Select +280 j Back +440 u Store
        channel'
text id=0x364: 'Turkey'
text id=0x365: ' +280 8 Store'
text id=0x366: ' +280 j Store'
text id=0x367: 'New software available. Save?'
text id=0x368: 'HDMI'
text id=0x369: 'Software Update'
text id=0x36a: 'Streaming Option'
text id=0x36b: 'CEC'
text id=0x36c: 'CEC Standby'
text id=0x36d: 'Internet Radio'
text id=0x36e: 'Liechtenstein'
text id=0x36f: 'Target address'
text id=0x370: 'Target port'
text id=0x371: 'Operator'
text id=0x372: 'Nederlands'
text id=0x373: 'Netherlands'
text id=0x374: 'Belgium'
text id=0x375: 'N'
#endif

