
#include "data.h"
#include "sdt.h"


Struct_23622188 Data_23622188[4]; //23622188, size???


static struct SDT_Service_Inner_0x10* sub_2344caec_inner(uint8_t r8)
{
	for (uint8_t i = 0; i < 150; i++)
	{
		//2344CB78
		if (Data_23622188[r8].Data_0x203c[i].bData_0 == 0)
		{
			Data_23622188[r8].Data_0x203c[i].bData_0 = 1;
			return &Data_23622188[r8].Data_0x203c[i];
		}
	}

	return 0;
}


/* 2344caec - todo */
int sub_2344caec(uint8_t r8, uint8_t* r6, uint16_t r7, struct SDT_Service* sb)
{
#if 0
	console_send_string("sub_2344caec (todo.c): TODO\r\n");
#endif

	uint8_t r0 = r6[0];

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2344caec: descriptor=0x%02x, length=%d\r\n", r0, r6[1]);
		console_send_string(debug_string);
	}
#endif

	switch (r0)
	{
	case 0x48:
	{
		//2344CB50: service_descriptor
		uint8_t* ip = r6 + 2;
#if 0
		struct SDT_Service_Inner_0x10* r4;
		for (uint8_t r0 = 0; r0 < 150; r0++)
		{
			//2344CB78
			if (Data_23622188[r8].Data_0x203c[r0].bData_0 == 0)
			{
				Data_23622188[r8].Data_0x203c[i].bData_0 = 1; //r3
				r4 = &Data_23622188[r8].Data_0x203c[i];
				//->2344CBA8
			}
		}
		//0x2344cba4
		r4 = 0;
#else
		//2344CBA8
		struct SDT_Service_Inner_0x10* r4 = sub_2344caec_inner(r8);
#endif
		if (r4 == 0)
		{
			//->2344CD4C
			break;
		}
		//0x2344cbb0
		sb->Data_0x10 = r4;
		r4->service_type = ip[0]; //service_type

		uint8_t* r5 = ip + 1; //@service_provider_name_length

		for (uint8_t r0 = 0; r0 < 150; r0++)
		{
			//2344CBC4
			if (Data_23622188[r8].Data_0[r0].bData_0 == 0)
			{
				//0x2344cbd4
				Data_23622188[r8].Data_0[r0].bData_0 = 1; //r3

				r4->service_name = Data_23622188[r8].Data_0[r0].service_name;
				r4->service_provider_name = Data_23622188[r8].Data_0[r0].service_provider_name;

				uint8_t r2 = r5[0]; //service_provider_name_length
				if (r2 == 0)
				{
					r4->service_provider_name = 0;
					//->2344CC1C
				}
				else
				{
					//0x2344cbfc
					if (r2 >= 10)
					{
						r2 = 9;
					}

					uint8_t r0 = sub_234085ac(r4->service_provider_name, r5 + 1, r2);
					r4->service_provider_name[r0 + 1] = 0;
				}
				//0x2344cc1c
				uint8_t* r1 = r5 + r5[0] + 1;
				r2 = r1[0]; //service_name_length
				if (r2 == 0)
				{
					r4->service_name = 0;
					//->2344CD4C
				}
				else
				{
					//0x2344cc38
					if (r2 >= 20)
					{
						r2 = 19;
					}

					uint8_t r0 = sub_234085ac(r4->service_name, r1 + 1, r2);
					r4->service_name[r0 + 1] = 0;
					//->2344CD4C
				}

				break;
			}
			//2344CC60
		} //for (uint8_t r0 = 0; r0 < 150; r0++)
		//0x2344cc70

		break;
	}

	case 0x4c:
		//loc_2344cd30: time_shifted_service_descriptor
		break;

	default:
		//loc_2344cd4c
		break;
	}
	//loc_2344cd4c
	return 0;
}


/* 2344cd54 - complete */
struct Struct_23622188_Inner_0x27bc* sub_2344cd54(uint8_t a)
{
	return &Data_23622188[a].Data_0x27bc;
}


static struct SDT_Service* func(struct SDT_Service* sb)
{
	for (uint8_t i = 0; i < 150; i++)
	{
		//loc_2344ce5c
		if (sb[i].service_id == 0)
		{
			return &sb[i];
			//->loc_2344ce8c
			break;
		}
	}

	return 0;
}


/* 2344cd8c - todo */
int sdt_decode_section(uint8_t a, uint8_t* r6, int r2)
{
#if 0
	hex_dump("sdt_decode_section", b, 64);
#endif

	struct SDT_Service* sb = Data_23622188[a].service;

	if (r2 != 0)
	{
		memset(&Data_23622188[a].Data_0x27bc, 0, 12);
		memset(&Data_23622188[a].Data_0[0], 0, 2325 * 2);
		memset(sb, 0, 24 * 150);
		memset(&Data_23622188[a].Data_0x203c, 0, 0x708);
		memset(&Data_23622188[a].Data_0x2744, 0, 0x78/*120*/);
	}
	//loc_2344ce08
	uint16_t section_length = ((r6[1] & 0x0f) << 8) | r6[2];

	Data_23622188[a].Data_0x27bc.table_id = r6[0];
	Data_23622188[a].Data_0x27bc.transport_stream_id = (r6[3] << 8) | r6[4];
	Data_23622188[a].Data_0x27bc.original_network_id = (r6[8] << 8) | r6[9];

	uint8_t* r4 = r6 + 11;
	//->loc_2344cf4c
	while ((r4 - r6 + 1) < section_length)
	{
		//loc_2344ce58
#if 0
		struct SDT_Service* pService = 0;
		for (uint8_t r0 = 0; r0 < 150; r0++)
		{
			//loc_2344ce5c
			if (sb[r0].service_id == 0)
			{
				pService = &sb[r0];
				//->loc_2344ce8c
				break;
			}
		}
		//0x2344ce88
		//pService = 0
#else
		struct SDT_Service* pService = func(sb);
#endif
		pService->Data_0x10 = 0;

		if (Data_23622188[a].Data_0x27bc.Data_8 == 0)
		{
			Data_23622188[a].Data_0x27bc.Data_8 = pService;
			//->loc_2344cebc
		}
		else
		{
			struct SDT_Service* r0;
			for (r0 = Data_23622188[a].Data_0x27bc.Data_8; r0->next != 0; )
			{
				//loc_2344cea4
				r0 = r0->next;
			}
			//0x2344ceb4
			r0->next = pService;
			pService->next = 0;
		}
		//loc_2344cebc
		pService->service_id = (r4[0] << 8) | r4[1];
		pService->free_CA_mode = (r4[3] >> 4) & 1;
		pService->EIT_schedule_flag = (r4[2] >> 1) & 1;
		pService->EIT_present_following_flag = (r4[2] >> 0) & 1;

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "sdt_decode_section: service_id=0x%04x, free_CA_mode=%d, EIT_schedule_flag=%d, EIT_present_following_flag=%d\r\n",
					pService->service_id, pService->free_CA_mode,
					pService->EIT_schedule_flag, pService->EIT_present_following_flag);
			console_send_string(debug_string);
		}
#endif

		uint16_t descriptors_loop_length = ((r4[3] & 0x0f) << 8) | r4[4];

		r4 += 5;
		//->loc_2344cf44
		for (int16_t sl = 0; sl < descriptors_loop_length; )
		{
			//loc_2344cf18
			sub_2344caec(a, r4, descriptors_loop_length - sl, pService);

			sl += (r4[1] + 2);
			r4 += (r4[1] + 2);
		}
		//loc_2344cf4c
	} //while ((r4 - r6 + 1) < section_length)
	//0x2344cf5c
	return section_length + 3;
}


