
#include "data.h"
#include "eit.h"


//0x2349360c / 0x234c7820
uint8_t bData_2349360c = 0; //2349360c +0
void (*Data_23493610)(int) = 0; //23493610 / 234c7824 +4

struct Struct_2376ad90
{
	struct Struct_2376ad90_Inner0
	{
		uint8_t bData_0; //0
		uint8_t fill_1; //1
		struct Struct_2376ad90_Inner0_Inner2
		{
			uint8_t fill_0[2]; //0
			uint8_t bData_2; //2
			uint8_t bData_3; //3
			uint8_t bData_4; //4
			uint8_t fill_5[9]; //5
			//14
		} Data_2[32];
		uint16_t wData_0x1c2; //0x1c2
		uint16_t wData_0x1c4; //0x1c4
		uint8_t bData_0x1c6; //0x1c6
		uint8_t fill_0x1c7; //0x1c7
		//0x1c8 = 2376AF58
	} Data_0[150/*size???*/]; //0
	//0x10b30
} Data_2376ad90; //2376ad90 = 2376a990 + 0x400 + 0x10b30 -> 2377B8C0

struct
{
	uint16_t wData_2377b8c0; //2377B8C0 +0x30
	uint16_t wData_2377b8c2; //2377B8C2 +0x32
	int fill_2377b8c4; //2377b8c4
	int fill_2377b8c8; //2377b8c8
	uint8_t bData_2377b8cc; //2377b8cc
} Data_2377b8c0;

Struct_2377b8d0* Data_2377b8d0[1000]; //2377b8d0 / 2390c728



/* 2344dd34 - complete */
void* eit_free_memblk(struct Struct_2377b8d0_Inner8* r5)
{
#if 0
	console_send_string("eit_free_memblk (todo.c): TODO\r\n");
#endif

//	int r7 = 0;
	void* r8 = r5->next;
	struct Struct_2377b8d0_Inner8_Inner8* r0 = r5->Data_8;
	//r6, =main_hMemBlk1
	if (r0 != 0)
	{
		//0x2344dd54
		struct Struct_2377b8d0_Inner8_Inner8_Inner0* r4 = r0->Data_0;
		if (r4 != 0)
		{
			do
			{
				//loc_2344dd60
				if (r4->ISO_639_language_code != 0)
				{
					r4->ISO_639_language_code = (void*) memblk_free(main_hMemBlk1, r4->ISO_639_language_code);
				}
				//loc_2344dd78
				if (r4->strName != 0)
				{
					r4->strName = (void*) memblk_free(main_hMemBlk1, r4->strName);
				}
				//loc_2344dd90
				if (r4->strText != 0)
				{
					r4->strText = (void*) memblk_free(main_hMemBlk1, r4->strText);
				}
				//loc_2344dda8
				struct Struct_2377b8d0_Inner8_Inner8_Inner0* r1 = r4;
				r4 = r4->next;
				memblk_free(main_hMemBlk1, r1);
			}
			while (r4 != 0);
			//0x2344ddc0
			r0 = r5->Data_8;
			r0->Data_0 = 0; //r7
		}
		//loc_2344ddc8
		r0 = r5->Data_8;
		struct Struct_2377b8d0_Inner8_Inner8_Inner4* r4_ = r0->Data_4;
		if (r4_ != 0)
		{
			do
			{
				//loc_2344ddd8
				if (r4_->Data_0 != 0)
				{
					r4_->Data_0 = (void*) memblk_free(main_hMemBlk1, r4_->Data_0);
				}
				//loc_2344ddf0
				if (r4_->Data_4 != 0)
				{
					r4_->Data_4 = (void*) memblk_free(main_hMemBlk1, r4_->Data_4);
				}
				//loc_2344de08
				struct Struct_2377b8d0_Inner8_Inner8_Inner4* r1 = r4_;
				r4_ = r4_->next;
				memblk_free(main_hMemBlk1, r1);
			}
			while (r4_ != 0);
			//0x2344de20
			r0 = r5->Data_8;
			r0->Data_4 = 0; //r7
		}
		//loc_2344de28
		r5->Data_8 = (void*) memblk_free(main_hMemBlk1, r5->Data_8);
	}
	//loc_2344de38
	struct Component_Descriptor* r1 = r5->component_descriptor;
	if (r1 != 0)
	{
		do
		{
			//loc_2344de44
			struct Component_Descriptor* r4 = r1->next;
			memblk_free(main_hMemBlk1, r1);
			r1 = r4;
		}
		while (r1 != 0);
		//0x2344de58
		r5->component_descriptor = 0; //r7
	}
	//loc_2344de5c
	struct Struct_2377b8d0_Inner8_Inner4* r0_ = r5->Data_4;
	if (r0_ != 0)
	{
		r0_->bData_0 = 4;

		r5->Data_4 = (void*) memblk_free(main_hMemBlk1, r5->Data_4);
	}
	//loc_2344de80
	return r8;
}


/* 2344de88 - todo */
int sub_2344de88(int a)
{
#if 0
	console_send_string("sub_2344de88 (todo.c): TODO\r\n");
#endif

	if (a == 0)
	{
		//0x2344dea4
		if (bData_2349360c != 0)
		{
			//0x2344deb4
			if (Data_23493610 != 0)
			{
				(Data_23493610)(0);
			}

			int32_t r0 = 999;
			do
			{
				//loc_2344dec8
				Data_2377b8d0[r0] = 0; //r7
				r0--;
			}
			while (r0 != -1);

			memblk_init(main_hMemBlk1);
		}
		//loc_2344df4c
	}
	else
	{
		for (uint32_t r4 = 0; r4 < 1000; r4++)
		{
			//loc_2344dee0
			if ((Data_2377b8d0[r4] != 0) &&
					(Data_2377b8d0[r4]->service_id != a))
			{
				//0x2344def4
				struct Struct_2377b8d0_Inner8* r5 = Data_2377b8d0[r4]->Data_8;
				//->loc_2344df1c
				while (r5 != 0)
				{
					//loc_2344df00
					struct Struct_2377b8d0_Inner8* sb = eit_free_memblk(r5);

					memblk_free(main_hMemBlk1, r5);

					r5 = sb;
				}
				//0x2344df24
				Data_2377b8d0[r4]->Data_8 = 0; //r7

				memblk_free(main_hMemBlk1, Data_2377b8d0[r4]);

				Data_2377b8d0[r4] = 0; //r7
				//->loc_2344df4c
				break;
			}
			//loc_2344df40
		} //for (uint32_t r4 = 0; r4 < 1000; r4++)
	}
	//loc_2344df4c
	return 0;
}


/* 2344df54 - todo */
int decode_eit_descriptors(uint8_t* r4, int b, struct Struct_2377b8d0_Inner8* r8)
{
#if 0
	console_send_string("decode_eit_descriptors (todo.c): TODO\r\n");
#endif

	int fp = 0;

	struct Struct_2377b8d0_Inner8_Inner8* r5 = r8->Data_8;
	int r6 = 0; //fp
	MemBlk_Handle* r2 = main_hMemBlk1/*r7*/;

	uint8_t r0 = r4[0]; //descriptor_tag
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "decode_eit_descriptors: descriptor_tag=0x%02x\r\n", r0);
		console_send_string(debug_string);
	}
#endif
	switch (r0)
	{
	case 0x4a:
		//loc_2344dfe4: linkage_descriptor
		break;

	//r8, =0x20010
	case 0x4d:
		//loc_2344e0b8: short_event_descriptor
		{
			struct Struct_2377b8d0_Inner8_Inner8_Inner0* r7 = memblk_alloc(r2, 16);
			if (r7 == 0)
			{
				//loc_2344e530
				return 2;
			}
			//0x2344e0cc
			if (r5->Data_0 == 0)
			{
				r5->Data_0 = r7;
				//->loc_2344e0f0
			}
			else
			{
				struct Struct_2377b8d0_Inner8_Inner8_Inner0* r0 = r5->Data_0;
				while (1)
				{
					//loc_2344e0dc
					void* r1 = r0->next;
					if (r1 != 0)
					{
						r0 = r1;
						//->loc_2344e0dc
					}
					else
					{
						//0x2344e0ec
						r0->next = r7;
						//loc_2344e0f0
						break;
					}
				}
			}
			//loc_2344e0f0
			uint8_t* sp = r4 + 2;

			r7->ISO_639_language_code = memblk_alloc(main_hMemBlk1, sizeof(uint32_t));

			if (r5->Data_0->ISO_639_language_code == 0)
			{
				//loc_2344e530
				return 2;
			}
			//0x2344e11c
			memcpy(r7->ISO_639_language_code, sp, 3); //ISO_639_language_code

			uint8_t* r5 = sp + 3;

			int r0 = r5[0]; //event_name_length
			if (r0 == 0)
			{
				r7->strName = 0; //r6
				//->loc_2344e208
			}
			else
			{
				//0x2344e140
				r7->strName = memblk_alloc(main_hMemBlk1, r0 + 1);
				if (r7->strName == 0)
				{
					//loc_2344e530
					return 2;
				}
				//0x2344e158
				memcpy(r7->strName, r5 + 1, r5[0]);

				sub_2340925c(r7->strName, r5[0]);

				uint8_t* r2 = r7->strName;
				if ((*((uint32_t*)r2) & ~0xff000000) == 0x20010)
				{
					//0x2344e184
					sub_234091ec(r2, r5[0]);
					//->loc_2344e208
				}
				else
				{
					//loc_2344e194
					if (*r2 == 5)
					{
						//0x2344e1a0
						int r0 = *(r7->ISO_639_language_code);
						//TODO!!!
						//0x2344e1a8
					}
					//loc_2344e208
				}
			}
			//loc_2344e208
			r5 += (r5[0] + 1);

			r0 = r5[0]; //text_length
			if (r0 == 0)
			{
				r7->strText = 0; //r6
				//->loc_2344e654
			}
			else
			{
				//0x2344e224
				r7->strText = memblk_alloc(main_hMemBlk1, r0 + 1);
				if (r7->strText == 0)
				{
					//loc_2344e530
					return 2;
				}
				//0x2344e23c
				memcpy(r7->strText, r5 + 1, r5[0]);

				sub_2340925c(r7->strText, r5[0]);

				if (fp != 0)
				{
					sub_23409148(r7->strText, r5[0]);
				}

				uint8_t* r0 = r7->strText;
				if ((*((uint32_t*)r0) & ~0xff000000) == 0x20010)
				{
					//0x2344e278
					//int r1 = r5[0];
					//->loc_2344e574
					sub_234091ec(r0, r5[0]);
					//->loc_2344e654
				}
				//loc_2344e654
			}
			//loc_2344e654
		} //case 0x4d:
		break;

	case 0x4e:
		//0x2344dfa8: extended_event_descriptor
		break;

	case 0x4f:
		//loc_2344e5f4: time_shifted_event_descriptor
		break;

	case 0x50:
		//loc_2344e280: component_descriptor
		{
			struct Component_Descriptor* component_descriptor = memblk_alloc(r2, sizeof(struct Component_Descriptor));
			if (component_descriptor == 0)
			{
				//loc_2344e530
				return 2;
			}
			//0x2344e294
			if (r8->component_descriptor == 0)
			{
				r8->component_descriptor = component_descriptor;
				//->loc_2344e2b8
			}
			else
			{
				struct Component_Descriptor* list = r8->component_descriptor;
				while (1)
				{
					//loc_2344e2a4
					if (list->next != 0)
					{
						list = list->next;
					}
					else
					{
						break;
					}
				}
				//0x2344e2b4
				list->next = component_descriptor;
			}
			//loc_2344e2b8
			int n = r4[1] - 6;
			component_descriptor->stream_content = r4[2] & 0x0f; //stream_content
			component_descriptor->component_type = r4[3]; //component_type
			component_descriptor->component_tag = r4[4]; //component_tag
			memcpy(&component_descriptor->ISO_639_language_code, &r4[5], 3); //ISO_639_language_code

			if (n >= 20)
			{
				n = 19;
			}
			if (n != 0)
			{
				//loc_2344e300
				memcpy(&component_descriptor->text_char[0], &r4[8], n);
				component_descriptor->text_char[n + 1] = 0; //r6
				//->loc_2344e654
			}
			else
			{
				//loc_2344e31c
				memset(&component_descriptor->text_char[0], 0, sizeof(component_descriptor->text_char));
				//->loc_2344e654
			}
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "decode_eit_descriptors: component_descriptor->stream_content=%d, component_type=%d, component_tag=%d, text='%s'\r\n",
						component_descriptor->stream_content, component_descriptor->component_type,
						component_descriptor->component_tag, component_descriptor->text_char);
				console_send_string(debug_string);
			}
#endif
		} //case 0x50:
		break;

	case 0x54:
		//loc_2344e630: content_descriptor
		break;

	case 0x69:
		//0x2344dfcc
		break;

	default:
		//loc_2344e654
		break;
	}
	//loc_2344e654
	return 0;
}


/* 2344e65c - todo */
int sub_2344e65c(uint8_t* r5, int fp, int c)
{
#if 0
	console_send_string("sub_2344e65c (todo.c): TODO\r\n");
#endif

	int r7 = (r5[5] & 0x3f) >> 1; //version_number
	uint8_t sp = r5[0]; //table_id
	uint16_t r8 = (r5[3] << 8) | r5[4]; //service_id
	uint8_t r6 = r5[6] + 1; //section_number
	uint8_t sl = r5[13]; //last_table_id
//	void* r0 = 0x2376a990 + 0x10000

	if ((c != 0) || (Data_2377b8c0.bData_2377b8cc == 1))
	{
		//loc_2344e6b4
		Data_2377b8c0.bData_2377b8cc = 0;

		memset(&Data_2376ad90, 0, sizeof(struct Struct_2376ad90)); //0x10b30);

		return 0x50;
	}
	else
	{
		//loc_2344e6d0
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2344e65c: table_id=0x%x, last_table_id=0x%x, service_id=%d, section_number=%d, version_number=%d\r\n",
					sp, sl, r8, r6, r7);
			console_send_string(debug_string);
		}
#endif

		if (Data_2377b8c0.wData_2377b8c0 != fp)
		{
			memset(&Data_2376ad90, 0, 0x10b30);
		}

		Data_2377b8c0.wData_2377b8c0 = fp;
		//->loc_2344e78c
		for (struct Struct_2376ad90_Inner0* r0 = Data_2376ad90.Data_0;
				r0->wData_0x1c4 != 0; r0++)
		{
			//loc_2344e6f4
			if (r0->wData_0x1c4 == fp)
			{
				//0x2344e700
				uint8_t r1;
				for (r1 = 0; r1 < 32; r1++)
				{
					//loc_2344e704
					if (r0->Data_2[r1].bData_3 == 0)
					{
						break;
					}
				} //for (uint8_t r1 = 0; r1 < 32; r1++)
				//0x2344e724
				if ((r0->bData_0x1c6 / 8 + 1) != r1)
				{
					//->loc_2344e79c
					break;
				}
				//0x2344e738 -> loc_2344e750
				while (r1--)
				{
					//loc_2344e73c
					if (r0->Data_2[r1].bData_2 == 0)
					{
						//->loc_2344e79c
						goto loc_2344e79c;
						//TODO!!!
						//break;
					}
				}
				//0x2344e760
				Data_2377b8c0.wData_2377b8c2++;
				if (Data_2377b8c0.wData_2377b8c2 > sl/*last_table_id*/)
				{
					Data_2377b8c0.wData_2377b8c2 = 0x50;
				}

				memset(&Data_2376ad90, 0, 0x10b30);
				//->loc_2344e8bc
				return Data_2377b8c0.wData_2377b8c2;
			} //if (r0->wData_0x1c4 == fp)
			//loc_2344e78c
		} //while (r0->wData_0x1c4 != 0)
		//loc_2344e79c
loc_2344e79c:
		Data_2377b8c0.wData_2377b8c2 = sp/*table_id*/;
		//->loc_2344e7c0
		uint16_t r0;
		for (r0 = 0; Data_2376ad90.Data_0[r0].wData_0x1c4 != 0; r0++)
		{
			//loc_2344e7b0
			if (Data_2376ad90.Data_0[r0].wData_0x1c4 == r8/*service_id*/)
			{
				//->loc_2344e7d8
				break;
			}
		}
		//loc_2344e7d8
		if (Data_2376ad90.Data_0[r0].bData_0 != 0)
		{
			if (Data_2376ad90.Data_0[r0].wData_0x1c2 != r7/*version_number*/)
			{
				memset(&Data_2376ad90.Data_0[r0], 0, sizeof(struct Struct_2376ad90_Inner0));
			}
		}

		Data_2376ad90.Data_0[r0].wData_0x1c2 = r7/*version_number*/;
		Data_2376ad90.Data_0[r0].bData_0 = 0;
		Data_2376ad90.Data_0[r0].bData_0x1c6 = r5[7]; //last_section_number
		Data_2376ad90.Data_0[r0].wData_0x1c4 = (r5[3] << 8) | r5[4]; //service_id

		struct Struct_2376ad90_Inner0_Inner2* r0_;
		//->loc_2344e848
		for (r0_ = Data_2376ad90.Data_0[r0].Data_2; r0_->bData_4 != 0; r0_++)
		{
			//loc_2344e838
			if ((r0_->bData_4 >> 3) == (r6/*section_number*/ >> 3))
			{
				//->loc_2344e854
				break;
			}
		}
		//loc_2344e854
		if (r0_->bData_2 == 0)
		{
			//0x2344e860
			r0_->bData_3 = r5[12] - 8 * (r5[12] / 8) + 1; //segment_last_section_number
			uint8_t* r1 = &r0_->bData_4;
			uint16_t r2 = 0;
			//->loc_2344e898
			while ((*r1)/*r3*/ != 0)
			{
				//loc_2344e884
				if ((*r1)/*r3*/ == r6/*section_number*/)
				{
					//->loc_2344e8bc
					return Data_2377b8c0.wData_2377b8c2;
				}
				//0x2344e88c
				r2++;
				r1++;
			}
			//0x2344e8a4
			*r1 = r6; //section_number

			if ((r0_->bData_3 - 1) == r2)
			{
				r0_->bData_2 = 0xff;
			}
		}
		//loc_2344e8bc
		return Data_2377b8c0.wData_2377b8c2;
	}
}


/* 2344e8c4 - todo */
void decode_eit_section(uint8_t* r6, int b)
{
#if 0
	console_send_string("decode_eit_section (todo.c): TODO\r\n");
#endif

	int r1 = 0;
	Struct_2377b8d0* sb = 0;
	uint8_t sl = 0;
	int sp = 0;
	//r5, =0x2377b8d0

	r1 = (r6[3] << 8) | r6[4]; //service_id

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "decode_eit_section: service_id=%d\r\n", r1);
		console_send_string(debug_string);
	}
#endif

	for (uint32_t r4 = 0; r4 < 1000; r4++)
	{
		//loc_2344e8f4
		if (Data_2377b8d0[r4] == 0)
		{
			//0x2344e900
			sb = memblk_alloc(main_hMemBlk1, sizeof(Struct_2377b8d0));
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "decode_eit_section: (new slot) r4=%d, sb=%p\r\n",
						r4, sb);
				console_send_string(debug_string);
			}
#endif
			Data_2377b8d0[r4] = sb;
			//->loc_2344e938
			break;
		}
		//loc_2344e91c
		if (Data_2377b8d0[r4]->service_id == r1)
		{
			sb = Data_2377b8d0[r4];
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "decode_eit_section: (re-use slot) r4=%d, sb=%p\r\n",
						r4, sb);
				console_send_string(debug_string);
			}
#endif
			//->loc_2344e938
			break;
		}
	} //for (; r4 < 1000; r4++)
	//loc_2344e938
	if (sb == 0)
	{
		//->loc_2344ebc4
		sub_2344de88(0);
		return;
	}
	//0x2344e940
	uint8_t* r5 = r6 + 14;

	sb->service_id = (r6[3] << 8) | r6[4]; //service_id
	sb->transport_stream_id = (r6[8] << 8) | r6[9]; //transport_stream_id
	sb->original_network_id = (r6[10] << 8) | r6[11]; //original_network_id

	int16_t r8 = (((r6[1] & 0x0f) << 8) | r6[2]) - 15; //section_length

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "decode_eit_section: sb->wData_6=%d, sb->wData_2=%d, sb->wData_4=%d, r8=%d\r\n",
				sb->wData_6, sb->wData_2, sb->wData_4, r8);
		console_send_string(debug_string);
	}
#endif

	//->loc_2344ebb8
	while (r8 > 0)
	{
		//loc_2344e998
		uint8_t version_number = (r6[5] >> 1) & 0x1f; //(x << 26) >> 27 //version_number
		uint8_t table_id = r6[0]; //table_id
		uint8_t section_number = r6[6]; //section_number

		sp = 1;

		struct Struct_2377b8d0_Inner8* r4 = sb->Data_8;

		if (r4 != 0)
		{
			do
			{
				//loc_2344e9c0
				if ((r4->bData_0x1b == sl) &&
						(r4->table_id == table_id) &&
						(r4->section_number == section_number))
				{
					//0x2344e9dc
					if (r4->version_number == version_number)
					{
						sp = 0;
						//->loc_2344ea08
					}
					else
					{
						//0x2344e9f0
						eit_free_memblk(r4);
						//->loc_2344ea08
					}
					//->loc_2344ea08
					break;
				}
				//loc_2344e9fc
				r4 = r4->next;
			}
			while (r4 != 0);
		} //if (r4 != 0)
		//loc_2344ea08
		if (r4 != 0)
		{
			//0x2344ea10
			if (r4->wData_0x16 < ((r5[2] << 8) | r5[3]))
			{
				//0x2344ea2c
				if (r4->table_id != 0x4e)
				{
					Data_2377b8c0.bData_2377b8cc = 1;
					//->loc_2344ebc4
					sub_2344de88(0);
					return;
				}
				//0x2344ea44 -> loc_2344ea84
			}
			//loc_2344ea84
		} //if (r4 != 0)
		else
		{
			//loc_2344ea48
			r4 = memblk_alloc(main_hMemBlk1, sizeof(struct Struct_2377b8d0_Inner8));
			if (r4 == 0)
			{
				//->loc_2344ebc4
				sub_2344de88(0);
				return;
			}
			//0x2344ea60
			if (sb->Data_8 == 0)
			{
				sb->Data_8 = r4;
				//->loc_2344ea84
			}
			else
			{
				struct Struct_2377b8d0_Inner8* r0 = sb->Data_8;
				while (1)
				{
					//loc_2344ea70
					void* r1 = r0->next;
					if (r1 != 0)
					{
						r0 = r1;
					}
					else
					{
						break;
					}
				}
				//0x2344ea80
				r0->next = r4;
			}
		}
		//loc_2344ea84
		int16_t r7 = ((r5[10] & 0x0f) << 8) | r5[11]; //descriptors_loop_length

		int fp = sp;
		if (fp != 0)
		{
			//0x2344eaa0
			r4->event_id = (r5[0] << 8) | r5[1]; //event_id
			r4->wData_0x16 = (r5[2] << 8) | r5[3]; //start_time
			r4->bData_0x1b = sl;
			r4->table_id = r6[0]; //table_id
			r4->section_number = r6[6]; //section_number
			r4->version_number = (r6[5] >> 1) & 0x1f; //(x << 26) >> 27; //version_number
			r4->bData_0x1c = r5[4]; //start_time
			r4->bData_0x1d = r5[5]; //start_time
			r4->bData_0x1e = r5[6]; //start_time
			r4->bData_0x1f = r5[7]; //duration
			r4->bData_0x20 = r5[8]; //duration
			r4->bData_0x21 = r5[9]; //duration
			r4->running_status = r5[10] >> 5; //running_status

#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "decode_eit_section: r4->event_id=%d, r4->wData_0x16=%x/%x/%x/%x, %x/%x/%x\r\n",
						r4->event_id,
						r4->wData_0x16,
						r4->bData_0x1c, r4->bData_0x1d, r4->bData_0x1e,
						r4->bData_0x1f, r4->bData_0x20, r4->bData_0x21);
				console_send_string(debug_string);
			}
#endif

			if (r7 == 0)
			{
				r4->Data_8 = 0;
				//->loc_2344eb54
			}
			else
			{
				r4->Data_8 = memblk_alloc(main_hMemBlk1, 16);
				if (r4->Data_8 == 0)
				{
					//loc_2344ebc4
					sub_2344de88(0);
					return;
				}
				//loc_2344eb54
			}
		}
		//loc_2344eb54
		sl++;
		r8 = r8 - 12; /* 96 Bits / 8 = 12 */
		r5 = r5 + 12;
		//->loc_2344ebb0
		while (r7 > 0)
		{
			//loc_2344eb6c
			if (fp != 0)
			{
				//0x2344eb74
				int r0 = decode_eit_descriptors(r5, 0, r4);
				if (r0 == 2)
				{
					//loc_2344ebc4
					sub_2344de88(0);
					return;
				}
			}
			//loc_2344eb8c
			r7 = r7 - r5[1] - 2;
			r8 = r8 - r5[1] - 2;
			r5 = r5 + r5[1] + 2;
		} //while (r7 > 0)
		//loc_2344ebb8
	} //while (r8 > 0)
	//0x2344ebc0
	return;
}


/* 2344ec24 - todo */
void sub_2344ec24/*sub_2346a6e0*/(void (*a)(int))
{
#if 0
	console_send_string("sub_2344ec24 (todo.c): TODO\r\n");
#endif

	for (uint32_t i = 0; i < 1000; i++)
	{
		Data_2377b8d0[i] = 0;
	}

	Data_23493610 = a;
}


/* 2344ec4c - todo */
Struct_2377b8d0* eit_get_section_data(int service_id, int transport_stream_id)
{
#if 0
	console_send_string("eit_get_section_data (todo.c): TODO\r\n");
#endif

	for (uint32_t i = 0; i < 1000; i++)
	{
		//loc_2344ec58
		if (Data_2377b8d0[i] == 0)
		{
			//->loc_2344ec88
			break;
		}

		if ((Data_2377b8d0[i]->service_id == service_id) &&
				(Data_2377b8d0[i]->transport_stream_id == transport_stream_id))
		{
			return Data_2377b8d0[i];
		}
	}
	//loc_2344ec88
	return 0;
}


/* 2344ec90 - complete */
struct Struct_2377b8d0_Inner8* sub_2344ec90(Struct_2377b8d0* a, uint8_t b)
{
#if 0
	console_send_string("sub_2344ec90 (todo.c): TODO\r\n");
#endif

	struct Struct_2377b8d0_Inner8* r0 = 0;

	if (a == 0)
	{
		return r0;
	}

	r0 = a->Data_8;

	if (r0 == 0)
	{
		return r0;
	}

	do
	{
		//loc_2344ecac
		int running_status = r0->running_status;

		if (b == 1)
		{
			//0x2344ecb8
			if ((running_status == 1/*not running*/) || (running_status == 0/*undefined*/))
			{
				//0x2344ecc4
				if ((r0->table_id == 0x4e/*actual TS, present/following event information*/) &&
						(r0->section_number == 1))
				{
					return r0;
				}
				//loc_2344ecfc
			}
			//loc_2344ecfc
		}
		else
		{
			//loc_2344ecdc
			if ((running_status == 4/*running*/) || (running_status == 0/*undefined*/))
			{
				//0x2344ece8
				if ((r0->table_id == 0x4e/*actual TS, present/following event information*/) &&
						(r0->section_number == 0))
				{
					return r0;
				}
			}
			//loc_2344ecfc
		}
		//loc_2344ecfc
		r0 = r0->next;
	}
	while (r0 != 0);
	//0x2344ed08
	return r0;
}


