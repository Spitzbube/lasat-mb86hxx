

#include "data.h"
#include "flash.h"
#include "av.h"


Struct_235f2e2c* Data_23491ff8/*pFlash*/; //23491ff8

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
	int fill_0[3]; //0
	uint8_t bData_12; //12
	//16
} Data_234fc854[10]; //234fc854, size??

struct
{
	int fill_0[8]; //0
	//32
} Data_234fc8f4[130]; //234fc8f4, size???

uint8_t Data_234fd894[24]; //234fd894, size???

struct
{
	int language[16]; //0, size???
	uint8_t currentLanguage; //0x40
	uint8_t numLanguages; //0x41
	//0x44
} Data_234fd8ac; //234fd8ac



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
				memset(&Data_234fd8ac, 0, 44);
				//r5 = 234fd8ac
				Data_234fd8ac.numLanguages = Data_234fc814.bData_2;

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
					sprintf(debug_string, "text_table_init: sp=0x%x, Data_234fd8ac.numLanguages=%d\r\n",
							sp, Data_234fd8ac.numLanguages);
					console_send_string(debug_string);
				}
#endif

				//->loc_234082b8
				for (r4 = 0; r4 < Data_234fd8ac.numLanguages; r4++) //15
				{
					//loc_2340829c
					flash_read(pFlash, sp + r4 * 4, 4, &Data_234fd8ac.language[r4]);
				}
				//0x234082c4
				Data_234fd8ac.currentLanguage = av_get_language();

				if (Data_234fd8ac.currentLanguage > Data_234fd8ac.numLanguages)
				{
					Data_234fd8ac.currentLanguage = 0;
				}

				return 0;
			}
		}
	}
	//->loc_23408294
	return fp;
}


/* 23408d28 - complete */
int text_table_get_string(int idx, void* buf, int len)
{
	int addr;

	addr = Data_234fd8ac.language[Data_234fd8ac.currentLanguage] + idx * 4;

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

