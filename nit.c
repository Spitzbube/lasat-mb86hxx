
#include "data.h"
#include "nit.h"


//23493600
Struct_23627118* Data_23493600 = 0; //23493600 +0
int Data_23493608 = 0; //23493608 +8


Struct_23627118 Data_23627118[2/*size?*/]; //23627118
Struct_23627118 Data_236c8d48[2/*size?*/]; //236c8d48 -> 2376A978

struct
{
	int fill_0[3]; //0
} Data_2376a978; //2376a978

struct
{
	int fill_0[3]; //0
} Data_2376a984; //2376a984



/* 2344cfb4 - todo */
int sub_2344cfb4(uint8_t* a, struct Struct_23627118_Inner0x54* b)
{
#if 0
	console_send_string("sub_2344cfb4 (todo.c): TODO\r\n");
#endif

	uint8_t* r4 = a + 2;
	int r7 = 0;
	uint8_t r5 = a[1];
	uint8_t r0 = a[0];
	Struct_23627118* r2 = Data_23493600;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2344cfb4: descriptor=0x%02x, length=%d\r\n", r0, r5);
		console_send_string(debug_string);
	}
#endif

	switch (r0)
	{
	case 0x40:
	{
		//loc_2344d134: network_name_descriptor
		struct Struct_23627118_Inner0x18* r6 = &r2->Data_0x18;
		if (r5 != 0)
		{
			//0x2344d140
			if (r5 > 50)
			{
				r5 = 49;
			}
			memcpy(r6->network_name, r4, r5);
			r6->network_name[r5 + 1] = 0; //r8
		}
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2344cfb4: network_name='%s'\r\n", r6->network_name);
			console_send_string(debug_string);
		}
#endif
		//loc_2344d8c0
		break;
	} //case 0x40:
	case 0x41:
	{
		//0x2344d014: service_list_descriptor
		if (b != 0)
		{
			//struct Struct_23627118_Inner0x54* r6 = b;
			struct service_list* r7 = b->service_list;

			uint8_t bNumServices = r5 / 3;
			if (bNumServices >= 150)
			{
				bNumServices = 150;
			}
			//->loc_2344d4a8
			while (bNumServices--)
			{
				//loc_2344d46c
				r7[b->bNumServices].service_id = (r4[0] << 8) | r4[1];
				r7[b->bNumServices].service_type = r4[2];
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "sub_2344cfb4: service[%d] id=0x%04x, type=0x%02x\r\n",
							b->bNumServices, r7[b->bNumServices].service_id, r7[b->bNumServices].service_type);
					console_send_string(debug_string);
				}
#endif
				r4 += 3;
				b->bNumServices++;
			}
			//->loc_2344d8c0
		}
		else
		{
			//loc_2344d864
			return 1;
		}
		break;
	} //case 0x41:
	case 0x43:
		//loc_2344d164: satellite_delivery_system_descriptor
		break;
	case 0x44:
		//loc_2344d4bc: cable_delivery_system_descriptor
		if (b != 0)
		{
			//0x2344d4c4
			b->frequency = (r4[0] >> 4) * 100000.; //1e9 ?
			b->frequency += (r4[0] & 0x0f) * 10000.;
			b->frequency += (r4[1] >> 4) * 1000.;
			b->frequency += (r4[1] & 0x0f) * 100.; //1e6 ?
			b->frequency += (r4[2] >> 4) * 10.;
			b->frequency += (r4[2] & 0x0f) * 1.; //1e4 ?

			b->symbol_rate = (r4[7] >> 4) * 100000.; //1e9 ?
			b->symbol_rate += (r4[7] & 0x0f) * 10000.;
			b->symbol_rate += (r4[8] >> 4) * 1000.;
			b->symbol_rate += (r4[8] & 0x0f) * 100.; //1e6 ?
			b->symbol_rate += (r4[9] >> 4) * 10.;
			b->symbol_rate += (r4[9] & 0x0f) * 1.; //1e4 ?

			b->bData_0x17 = r4[6] | 0x10;
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_2344cfb4: frequency=%d, symbol_rate=%d, b->bData_0x17=0x%02x\r\n",
						b->frequency, b->symbol_rate, b->bData_0x17);
				console_send_string(debug_string);
			}
#endif
			//->loc_2344d8c0
		}
		else
		{
			//loc_2344d864
			return 1;
		}
		break;
	case 0x4a:
		//loc_2344d6b8: linkage_descriptor
		break;
	case 0x5a:
		//0x2344d054: terrestrial_delivery_system_descriptor
		break;
	case 0x5b:
		//loc_2344d8c0: multilingual_network_name_descriptor
		break;
	case 0x5f:
		//loc_2344d120: private_data_specifier_descriptor
		break;
	case 0x62:
		//loc_2344d8c0: frequency_list_descriptor
		break;
	case 0x83:
		//0x2344d0f8
		break;
	case 0x87:
		//loc_2344d8c0
		break;
	case 0x88:
		//loc_2344d84c
		break;
	}
	//loc_2344d8c0
	//r0 = 0;
	//->loc_2344d868
	return 0;
}


static struct Struct_23627118_Inner0x54* nit_decode_section_Inner(uint8_t* sp)
{
	struct Struct_23627118_Inner0x54* r5 = Data_23493600->Data_0x54;

	*sp = 0; //r8

	for (uint8_t i = 0; i < 200; i++)
	{
		//loc_2344da5c
		if (r5->wData_4 == 1)
		{
			r5->wData_4 = 0; //r8
			//->loc_2344da8c
			return r5;
		}

		r5++;
	}
	//0x2344da84
	r5 = 0;
	*sp = 1; //sb
	return r5;
}


/* 2344d8c8 - todo */
int nit_decode_section(uint8_t a, char* r5, int r2)
{
#if 0
	hex_dump("nit_decode_section", b, 64);
#endif

//	Struct_23627118* r0 = &Data_23627118[a];
//	Struct_23627118* r4 = &Data_236c8d48[a];

//	uint8_t table_id = r5[0];
	if (r5[0] == 0x40)
	{
		//loc_2344d910
		Data_23493600 = &Data_23627118[a]; //r0;
	}
	else if (r5[0] == 0x4a)
	{
		Data_23493600 = &Data_236c8d48[a]; //r4;
		//->loc_2344d914
	}
	else if (r5[0] == 0x41)
	{
		//loc_2344d910
		Data_23493600 = &Data_23627118[a]; //r0;
	}
	else
	{
		return -1;
	}
	//loc_2344d914
	//r8 = 0;
	//sb = 1;
	if (r2 != 0)
	{
		//0x2344d924
		memset(Data_23493600, 0, sizeof(Struct_23627118));

		if ((r5[0] == 0x40) || (r5[0] == 0x41))
		{
			//->loc_2344d978
			memset(&Data_2376a978, 0, 12);
		}
		else
		{
			memset(&Data_2376a984, 0, 12);
			memset(/*&r4->Data_0x10*/&Data_236c8d48[a].Data_0x10, 0xff, 8);
		}
		//loc_2344d978
		memset(/*&r4->Data_8*/&Data_236c8d48[a].Data_8, 0xff, 8);

		Data_23493608 = 0; //r8

		Data_23493600->Data_0x18.wData_0x1a = 0xff;

		struct Struct_23627118_Inner0x54* r4 = Data_23493600->Data_0x54;

		for (uint8_t r6 = 0; r6 < 200; r6++)
		{
			//loc_2344d9a4
			memset(r4, 0, sizeof(struct Struct_23627118_Inner0x54));

			r4->wData_4 = 1; //sb

			r4++;
		}
	} //if (r2 != 0)
	//loc_2344d9cc
	int16_t r6 = ((r5[8] & 0x0f) << 8) | r5[9]; //network_descriptors_length
	uint32_t fp = ((r5[1] & 0x0f) << 8) | r5[2]; //section_length
	Data_23493600->Data_0x18.network_id = (r5[3] << 8) | r5[4];

#if 0
	hex_dump("nit_decode_section", r5, fp);
#endif

	uint8_t* r4_ = r5 + 10;

	while (r6 > 0)
	{
		//loc_2344da0c
		sub_2344cfb4(r4_, 0); //Decode Network Descriptors

		r6 = r6 - r4_[1] - 2;
		r4_ = r4_ + r4_[1] + 2;
	}
	//0x2344da38
	int16_t r7 = ((r4_[0] & 0x0f) << 8) | r4_[1]; //transport_stream_loop_length
	r4_ += 2;
	//->loc_2344db10
	while (r7 > 0)
	{
		//loc_2344da4c
		uint8_t sp; //r8
#if 0
		struct Struct_23627118_Inner0x54* r5 = Data_23493600->Data_0x54;
		for (uint8_t r0 = 0; r0 < 200; r0++)
		{
			//loc_2344da5c
			if (r5->wData_4 == 1)
			{
				r5->wData_4 = 0; //r8
				//->loc_2344da8c
				break;
			}

			r5++;
		}
		//0x2344da84
		r5 = 0;
		sp = 1; //sb
#else
		struct Struct_23627118_Inner0x54* r5 = nit_decode_section_Inner(&sp);
#endif
		//loc_2344da8c
		if (sp != 0)
		{
			//->loc_2344db18
			break;
		}
		//0x2344da98
		r5->transport_stream_id = (r4_[0] << 8) | r4_[1];
		r5->original_network_id = (r4_[2] << 8) | r4_[3];
		r7 -= 6;
		r6 = ((r4_[4] & 0x0f) << 8) | r4_[5]; //transport_descriptors_length
		r4_ += 6;
		r7 = r7 - r6;
		//->loc_2344db08
		while (r6 > 0)
		{
			//loc_2344dae4
			sub_2344cfb4(r4_, r5); //Decode Transport Descriptors

			r6 = r6 - r4_[1] - 2;
			r4_ = r4_ + r4_[1] + 2;
		}
		//loc_2344db10
	} //while (r7 > 0)
	//loc_2344db18
	return fp + 3;
}


/* 2344dc3c - todo */
int sub_2344dc3c(uint8_t a, Struct_2344dc3c* b)
{
#if 0
	console_send_string("sub_2344dc3c (todo.c): TODO\r\n");
#endif

	Struct_23627118* r0 = &Data_23627118[a];

	b->Data_4 = &r0->Data_0x18;
	b->Data_8 = r0->Data_0x54;

	if ((r0->bData_6 == 0x4a) ||
			(r0->bData_6 == 0x01) ||
			(r0->bData_6 == 0x02))
	{
		b->Data_0 = r0;
	}
	else
	{
		b->Data_0 = 0;
	}

	return 0;
}


/* 2344dcf4 - complete */
void sub_2344dcf4(uint8_t a, int b)
{
#if 0
	console_send_string("sub_2344dcf4 (todo.c): TODO\r\n");
#endif

	Struct_23627118* r0 = &Data_23627118[a & 1];

	r0->Data_0x18.wData_0x1a = b;

}



