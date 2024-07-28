

#include "data.h"
#include "pmt.h"


struct Struct_236001c8 Data_236001c8[4/*size???*/]; //236001c8



/* 2344bba0 - todo */
int pmt_decode_descriptor(uint8_t a, uint8_t* r5, int c, 
	PMT_ElementaryStream* r4, int r2)
{
#if 0
	console_send_string("pmt_decode_descriptor (todo.c): TODO\r\n");
#endif

#ifdef PMT_DESCRIPTORS_TAG_DEBUG
	{
		extern char debug_string[];
		sprintf(debug_string, "pmt_decode_descriptor: r5[0]=0x%x\r\n",
				r5[0]);
		console_send_string(debug_string);
	}
#endif

	switch (r5[0])
	{
	case 0x52:
		//loc_2344bd54: stream_identifier_descriptor
		if (r2 != 0)
		{
			r4->component_tag = r5[2]; //component_tag
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "pmt_decode_descriptor: r4->component_tag=%d\r\n",
						r4->component_tag);
				console_send_string(debug_string);
			}
#endif
		}
		//->loc_2344c07c
		break;

	case 0x56:
		//loc_2344bd64: teletext_descriptor
		//TODO!!!
		break;

	case 0x59:
		//0x2344bc18: subtitling_descriptor
		//TODO!!!
		break;

	case 0x66:
		//loc_2344be2c: data_broadcast_id_descriptor
		//TODO!!!
		break;

	case 0x6a:
		//loc_2344bdfc
		//TODO!!!
		break;

	case 0x6b:
		//loc_2344c07c: ancillary_data_descriptor
		//TODO!!!
		break;

	case 0x7a:
		//0x2344bc50
		//TODO!!!
		break;

	case 0x7b:
		//loc_2344c07c
		break;

	case 0x7c:
		//loc_2344bdf0: AAC_descriptor
		//TODO!!!
		break;

	case 0xc5:
		//0x2344bc74
		//TODO!!!
		break;

	case 0x09:
		//loc_2344bf04
		//TODO!!!
		break;

	case 0x0a:
		//0x2344bbf0: ISO-639 Language
		if (r2 != 0)
		{
			memcpy(&r4->language[0], &r5[2], 3);
		}
		//->loc_2344c07c
		break;

	default:
		break;
	}
	//loc_2344c07c
	return 0;
}


/* 2344c084 - complete */
struct Struct_236001c8* pmt_get_data(uint8_t a)
{
#if 0
	console_send_string("pmt_get_data (todo.c): TODO\r\n");
#endif

	return &Data_236001c8[a];
}


static PMT_ElementaryStream* func(struct Struct_236001c8* r6)
{
	for (uint8_t i = 0; i < 50; i++)
	{
		//loc_2344c1cc
		if (r6->arElementaryStreams[i].elementary_PID == 0)
		{
			return &r6->arElementaryStreams[i];
			//->loc_2344c208
		}
	}
	//0x2344c204
	return 0; //sb
}


/* 2344c098 - todo */
int pmt_decode_section(uint8_t a, uint8_t* b)
{
#if 0
	console_send_string("pmt_decode_section (todo.c): TODO\r\n");

	return 0;
#endif

	uint8_t* r4 = &b[12]; //pDescriptors;


	uint32_t sl = ((b[1] & 0x0f) << 8) | b[2]; //section_length
	struct Struct_236001c8* r6 = &Data_236001c8[a];
	Data_236001c8[a].Data_0 = &b[3];

	int16_t r8 = ((b[10] & 0x0f) << 8) | b[11]; //program_info_length
	int16_t r5 = r8;

	r6->program_number = (b[3] << 8) | b[4]; //program_number
	r6->version_number = (b[5] >> 1) & 0x1f; //version_number
	r6->PCR_PID = ((b[8] & 0x1f) << 8) | b[9]; //PCR_PID

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "pmt_decode_section: r6->program_number=%d, r6->PCR_PID=0x%04x\r\n",
				r6->program_number, r6->PCR_PID);
		console_send_string(debug_string);
	}
#endif

	PMT_ElementaryStream* r0 = r6->pFirstElementaryStreams;
	if (r0 != 0)
	{
		do
		{
			//loc_2344c130
			r0 = r0->next;
		}
		while (r0 != 0);
		//0x2344c13c
		r6->Data_0x10fa8[0].bData_0 = 0; //sb;
		r6->Data_0x10fa8[1].bData_0 = 0; //sb;
		r6->Data_0x10fa8[2].bData_0 = 0; //sb;

		memset(&r6->arElementaryStreams, 0, 0x2af8);
		memset(&r6->Data_0x3fd8, 0, 0xcfd0);
		memset(&r6->Data_4, 0, 0x14c8);
		//->loc_2344c1ac
	}
	//loc_2344c1ac
	while (r5 > 0)
	{
		//loc_2344c17c: Decode Program Descriptors
		pmt_decode_descriptor(a, r4, r8, 0, 0);

		r5 = r5 - r4[1] - 2;
		r4 = r4 + r4[1] + 2;
	}
	//0x2344c1b4
	r8 = sl - r8 - 12;
	//->loc_2344c2b8
	while (r8 > 1)
	{
		//loc_2344c1c4
		PMT_ElementaryStream* r5;
#if 0
		for (uint8_t r0 = 0; r0 < 50; r0++)
		{
			//loc_2344c1cc
			if (r6->arElementaryStreams[r0].elementary_PID == 0)
			{
				r5 = &r6->arElementaryStreams[r0];
				//->loc_2344c208
			}
		}
		//0x2344c204
		r5 = 0; //sb
#else
		r5 = func(r6);
#endif
		//loc_2344c208
		r5->Data_0 = r4;
		PMT_ElementaryStream* r0 = r6->pFirstElementaryStreams;
		if (r0 == 0)
		{
			r6->pFirstElementaryStreams = r5;
			//->loc_2344c230
		}
		else
		{
			for (PMT_ElementaryStream* r1 = r0->next; r1 != 0; )
			{
				//loc_2344c21c
				r0 = r1;
				r1 = r0->next;
			}
			//0x2344c22c
			r0->next = r5;
		}
		//loc_2344c230
		r5->next = 0; //sb
		r5->stream_type = r4[0];
		r5->elementary_PID = ((r4[1] & 0x1f) << 8) | r4[2];
		r5->component_tag = 0xff;

#ifdef PMT_STREAM_DEBUG
		{
			extern char debug_string[];
			sprintf(debug_string, "pmt_decode_section: r5->stream_type=%d, r5->elementary_PID=0x%04x\r\n",
					r5->stream_type, r5->elementary_PID);
			console_send_string(debug_string);
		}
#endif

		uint16_t fp = ((r4[3] & 0x0f) << 8) | r4[4]; //ES_info_length

		r4 = r4 + 5;

		r8 = r8 - fp - 5;
		//->loc_2344c2b0
		while (fp != 0)
		{
			//loc_2344c27c: Decode Elementary stream descriptors
			pmt_decode_descriptor(a, r4, fp, r5, r5->elementary_PID);

			fp = fp - r4[1] - 2;
			r4 = r4 + r4[1] + 2;
		}
		//loc_2344c2b8
	} //while (r8 > 1)
	//0x2344c2c0
	return sl + 3;
}


/* 2344c730 - todo */
int sub_2344c730(uint8_t r0, uint16_t* r1, uint32_t r2, uint8_t r3)
{
#if 0
	console_send_string("sub_2344c730 (todo.c): TODO\r\n");
#endif

	if (r3 >= 3)
	{
		return 0xff;
	}

	Data_236001c8[r0].Data_0x10fa8[r3].bData_1 = r2;
	Data_236001c8[r0].Data_0x10fa8[r3].Data_4 = r1;

	uint8_t r1_ = r2;

	for (uint16_t i = 0; i < r1_; i++)
	{
		/*empty*/;
	}

	return 0;
}


/* 2344c79c - complete */
void sub_2344c79c(uint8_t r0, uint8_t r1)
{
#if 0
	console_send_string("sub_2344c79c (todo.c): TODO\r\n");
#endif

	if (r1 >= 3)
	{
		return;
	}

	Data_236001c8[r0].Data_0x10fa8[r1].bData_1 = 0;
	Data_236001c8[r0].Data_0x10fa8[r1].Data_4 = 0;
}


/* 2344c7cc - complete */
int sub_2344c7cc(uint8_t a)
{
#if 0
	console_send_string("sub_2344c7cc (todo.c): TODO\r\n");
#endif

	int res = 0;

	for (uint32_t i = 0; i < 3; i++)
	{
		if (Data_236001c8[a].Data_0x10fa8[i].bData_0 != 0)
		{
			if (i == 0)
			{
				res |= 1;
			}
			else if (i == 1)
			{
				res |= 2;
			}
			else if (i == 2)
			{
				res |= 4;
			}
		}
	}

	return res;
}


/* 2344c82c - todo */
int sub_2344c82c(uint8_t a, int b, void* c, void* d)
{
	console_send_string("sub_2344c82c (todo.c): TODO\r\n");

}


/* 2344ca6c - todo */
int sub_2344ca6c(uint8_t a, uint32_t b)
{
#if 0
	console_send_string("sub_2344ca6c (todo.c): TODO\r\n");
#endif

	uint8_t i, j, r4;
	int res = 0;

	for (i = 0; i < 3; i++)
	{
		//loc_2344ca8c
		if (Data_236001c8[a].Data_0x10fa8[i].Data_4 != 0)
		{
			r4 = Data_236001c8[a].Data_0x10fa8[i].bData_1;

			for (j = 0; j < r4; j++)
			{
				//loc_2344cab0
				if ((Data_236001c8[a].Data_0x10fa8[i].Data_4[j] >> 8) == (b >> 8))
				{
					res = 1;

					Data_236001c8[a].Data_0x10fa8[i].bData_0 = 1; //r5
				}
			}
		}
		//loc_2344cad8
	}

	return res;
}




