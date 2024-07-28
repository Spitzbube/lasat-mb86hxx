
#include "data.h"
#include "pat.h"


typedef struct
{
	int Data_0; //0
	int Data_4; //4
	uint8_t numPrograms; //8
	int Data_12; //12
	int Data_16; //16
	PAT_Program* Data_0x14; //20 = 0x14
	PAT_Program programs[150]; //0x18
	//0x720
} Struct_235ff388;

Struct_235ff388 Data_235ff388[4/*size???*/]; //235ff388



static struct PAT_Program* func(Struct_235ff388* r5)
{
	for (uint8_t i = 0; i < 150; i++)
	{
		//loc_2344ba3c
		if (r5->programs[i].pmt_pid == 0)
		{
			return &r5->programs[i];
			//->loc_2344ba70
			break;
		}
	}
	//0x2344ba6c
	return  0;
}


/* 2344b978 - todo */
int pat_decode_section(uint8_t a, uint8_t* r4, int r2)
{
#if 0
	console_send_string("pat_decode_section (todo.c): TODO\r\n");
#endif

	struct PAT_Program* r6 = 0;
	Struct_235ff388* r5 = &Data_235ff388[a];

	if (r2 != 0)
	{
		if (r5->Data_0x14 != 0)
		{
			memset(&r5->programs[0], 0, 150 * 12);
		}
	}

	uint16_t ip = ((r4[1] & 0x0f) << 8) | r4[2];

	r5->Data_4 = (r4[5] >> 1) & 0x1f;
	r5->Data_0 = (r4[3] << 8) | r4[4];
	r5->numPrograms = 0;
	r5->Data_12 = r4[7];
	r5->Data_16 = r4[6];

	uint8_t lr = (ip - 9) / 4;

	uint8_t* r1 = r4 + 8;
	//->loc_2344bac4
	for (uint8_t i = 0; i < lr; r1 += 4, i++)
	{
		//loc_2344ba1c
		if (((r1[0] << 8) | r1[1]) != 0)
		{
			//r7 = r5
#if 0
			for (uint8_t r0 = 0; r0 < 150; r0++)
			{
				//loc_2344ba3c
				if (r5->programs[r0].Data_4 == 0)
				{
					r4 = &r5->programs[r0];
					//->loc_2344ba70
					break;
				}
			}
			//0x2344ba6c
			r4 = 0;
#else
			struct PAT_Program* r4 = func(r5);
#endif
			//loc_2344ba70
			if (r4 == 0)
			{
				//->loc_2344bacc
				break;
			}
			//0x2344ba78
			r4->program_number = 0xffff & ((r1[0] << 8) | r1[1]); //r8
			r4->pmt_pid = ((r1[2] & 0x1f) << 8) | r1[3];

#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "pat_decode_section: program_number=%d, pid=0x%03x\r\n",
						r4->program_number, r4->pmt_pid);
				console_send_string(debug_string);
			}
#endif

			r5->numPrograms++;

			if (r6 != 0)
			{
				r6->next = r4;
				r4->next = 0;
			}
			else
			{
				r5->Data_0x14 = r4;
			}

			r6 = r4;
		}
		//loc_2344bab8
	}
	//loc_2344bacc
	return ip + 3;
}


/* 2344bad4 / 234675d8 - complete */
int pat_get_num_programs(uint8_t a)
{
#if 0
	console_send_string("pat_get_num_programs (todo.c): TODO\r\n");
#endif

	return Data_235ff388[a].numPrograms;
}


/* 2344bb4c - complete */
struct PAT_Program* pat_get_program(uint8_t a, uint8_t b)
{
#if 0
	console_send_string("pat_get_program (todo.c): TODO\r\n");
#endif

	struct PAT_Program* p = Data_235ff388[a].Data_0x14;

	if (p != 0)
	{
		for (uint8_t i = 0; i < Data_235ff388[a].numPrograms; i++)
		{
			if (i == b)
			{
				return p;
			}

			p = p->next;
		}
	}

	return 0;
}


