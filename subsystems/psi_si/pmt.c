

#include "data.h"
#include "pmt.h"


struct Struct_236001c8 Data_236001c8[4/*size???*/]; //236001c8

static struct Struct_236001c8_Inner_0x3fd8* get_p(struct Struct_236001c8* r3)
{
	for (uint8_t i = 0; i < 10; i++)
	{
		if (r3->Data_0x3fd8[i].wData_6 == 0)
		{
			return &r3->Data_0x3fd8[i];
		}
	}

	return NULL;
}


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

	//ip, =0x236001c8
	//r6 = 1;
	//r3, ip, r3, lsl #6
	struct Struct_236001c8* r3 = &Data_236001c8[a];

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
		//loc_2344bdfc: AC-3_descriptor
		if (r2 != 0)
		{
			//loc_2344be04
			if (r5[2] & (1 << 7)/*component_type_flag*/)
			{
				r4->ac3_component_type = r5[3]; //component_type
				//->loc_2344c07c
			}
			else
			{
				//0x2344be1c
				if (r4->ac3_component_type == 0)
				{
					r4->ac3_component_type = 1; //r6
				}				
			}
		}
		//loc_2344c07c
		break;

	case 0x6b:
		//loc_2344c07c: ancillary_data_descriptor
		break;

	case 0x7a:
		//0x2344bc50: enhanced_AC-3_descriptor
		if (r2 != 0)
		{
			//0x2344bc58
			r4->ac3_component_type = 0x80;
			//->loc_2344be04
			if (r5[2] & (1 << 7)/*component_type_flag*/)
			{
				r4->ac3_component_type = r5[3]; //component_type
				//->loc_2344c07c
			}
			else
			{
				//0x2344be1c
				if (r4->ac3_component_type == 0)
				{
					r4->ac3_component_type = 1; //r6
				}				
			}
		}
		//loc_2344c07c
		break;

	case 0x7b:
		//loc_2344c07c: DTS® descriptor
		break;

	case 0x7c:
		//loc_2344bdf0: AAC_descriptor
		if (r2 != 0)
		{
			r4->bData_9 = 1;
		}
		//->loc_2344c07c
		break;

	case 0xc5:
		//0x2344bc74: Hyperlink Descriptor?
		if (r2 != 0)
		{
			//0x2344bc7c
			memcpy(&r4->Data_0xe[0], &r5[3], 16);

			r4->Data_0xe[16] = ' ';
		}
		//->loc_2344c07c
		break;

	case 0x09:
		//loc_2344bf04: CA_descriptor
		{
			struct Struct_236001c8_Inner_4* r4_;

			if (r2 == 0)
			{
				//r4 = r3 + 4;
				r4_ = &r3->Data_4[0];
				//->loc_2344bf88
			}
			else
			{
				//0x2344bf10
				if ((r4->stream_type != 0x02) &&
					(r4->stream_type != 0x0f) &&
					(r4->stream_type != 0x11) &&
					(r4->stream_type != 0x03) &&
					(r4->stream_type != 0x04) &&
					(r4->stream_type != 0x06) &&
					(r4->stream_type != 0x1b))
				{
					//->loc_2344c07c
					break;
				}
				//0x2344bf34
				if (r4->Data_0xd4 == 0)
				{
					//0x2344bf40
#if 0
					struct Struct_236001c8_Inner_0x3fd8* r1_ = NULL;
					uint8_t r1;
					for (r1 = 0; r1 < 10; r1++)
					{
						//loc_2344bf44
						if (r3->Data_0x3fd8[r1].wData_6 == 0)
						{
							r1_ = &r3->Data_0x3fd8[r1];
							//->loc_2344bf80
							break;
						}
					}
					//loc_2344bf80
					r4->Data_0xd4 = r1_;
#else
					r4->Data_0xd4 = get_p(r3);
#endif					
				}
				//loc_2344bf84
				r4_ = r4->Data_0xd4;
			}
			//loc_2344bf88
			int r1 = 20;
			while (r1--)
			{
				//loc_2344bf8c
				if (r4_->wData_6 == 0)
				{
					//->loc_2344bfac
					break;
				}
				r4_++;
			}

			if (r1 != 0)
			{
				//loc_2344bfb4
				r5++;
				r4_->wData_6 = *r5++; //descriptor_len
				r4_->wData_6 += 2;
				r4_->ca_system_id = (r5[0] << 8) | r5[1]; //ca_system_id

				if (0 == sub_2344ca6c(a, r4_->ca_system_id))
				{
					r4_->wData_6 = 0;
					//->loc_2344c07c
					break;
				}
				//0x2344bff0
				r4_->ca_pid = ((r5[2] << 8) | r5[3]) & 0x1fff; //ca_pid
				r5 += 2;

				if (r4_->wData_6 < 0x100)
				{
					memcpy(&r4_->arData_8[0], &r5[-4], r4_->wData_6);
				}

				int16_t r1 = r4_->wData_6 - 6;
				uint8_t* r0 = &r5[2];
				//->loc_2344c074
				while (r1 > 0)
				{
					//loc_2344c030
					uint8_t tag = *r0++;
					uint8_t len = *r0++;

					if (tag == 0x8c)
					{
						//0x2344c044
						r4_->wData_0x108 |= 2;
						if (r0[0] != 0)
						{
							r4_->wData_0x108 |= 1;
						}
					}
					//loc_2344c064
					r1 = r1 - len - 2;
					r0 += len;
				}
				//loc_2344c07c
			}
			//loc_2344c07c
		}
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
#ifdef PMT_DECODE_SECTION_DEBUG
	{
		extern char debug_string[];
		sprintf(debug_string, "pmt_decode_section: sl=0x%04x\r\n", sl);
		console_send_string(debug_string);
	}
#else
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

		memset(&r6->arElementaryStreams[0], 0, 50*0xdc/*0x2af8*/);
		memset(&r6->Data_0x3fd8[0], 0, 10*0x14c8/*0xcfd0*/);
		memset(&r6->Data_4[0], 0, 20*0x10A/*0x14c8*/);
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
#endif
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




