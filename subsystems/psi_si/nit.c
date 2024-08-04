
#include "data.h"
#include "nit.h"

extern uint32_t Data_23492240; //23492240

//23493600
Struct_23627118* Data_23493600 = 0; //23493600 +0
int (*Data_23493604)() = 0; //23493604 +4
uint32_t nit_private_data_value = 0; //23493608 +8
#if 0
  STR_TABLE  Table[] = {
	// { Private Data Value, Private Data Value // Organisation" },
  	// -- updated 2003-10-16
	{ 0x00000000, 0x00000000,   "Reserved" },
	{ 0x00000001, 0x00000001,   "SES" },
	{ 0x00000002, 0x00000002,   "BskyB 1" },
	{ 0x00000003, 0x00000003,   "BskyB 2" },
	{ 0x00000004, 0x00000004,   "BskyB 3" },
	{ 0x00000005, 0x00000005,   "ARD, ZDF, ORF" },
	{ 0x00000006, 0x00000006,   "Nokia Multimedia Network Terminals" },
	{ 0x00000007, 0x00000007,   "AT Entertainment Ltd." },
	{ 0x00000008, 0x00000008,   "TV Cabo Portugal  " },
	{ 0x00000009, 0x0000000D,   "Nagravision SA // Kudelski " },
	{ 0x0000000E, 0x0000000E,   "Valvision SA  " },
	{ 0x0000000F, 0x0000000F,   "Quiero Televisión  " },
	{ 0x00000010, 0x00000010,   "La Télévision Par Satellite (TPS)" },
	{ 0x00000011, 0x00000011,   "Echostar Communications" },
	{ 0x00000012, 0x00000012,   "Telia AB" },
	{ 0x00000013, 0x00000013,   "Viasat  " },
	{ 0x00000014, 0x00000014,   "Senda (Swedish Terrestrial TV )" },
	{ 0x00000015, 0x00000015,   "MediaKabel " },
	{ 0x00000016, 0x00000016,   "Casema  " },
	{ 0x00000017, 0x00000017,   "Humax Electronics Co. Ltd ." },
	{ 0x00000018, 0x00000018,   "@Sky  " },
	{ 0x00000019, 0x00000019,   "Singapore Digital Terrestrial Television  " },
	{ 0x0000001A, 0x0000001A,   "Télédiffusion de France (TDF)" },
	{ 0x0000001B, 0x0000001B,   "Intellibyte Inc." },
	{ 0x0000001C, 0x0000001C,   "Digital Theater Systems Ltd" },
	{ 0x0000001D, 0x0000001D,   "Finlux Ltd." },
	{ 0x0000001E, 0x0000001E,   "Sagem SA" },
	{ 0x00000020, 0x00000023,   "Lyonnaise Cable" },
	{ 0x00000025, 0x00000025,   "MTV Europe " },
	{ 0x00000026, 0x00000026,   "Pansonic  " },
	{ 0x00000027, 0x00000027,   "Mentor Data System, Inc ." },
	{ 0x00000028, 0x00000028,   "EACEM  " },
	{ 0x00000029, 0x00000029,   "NorDig  " },
	{ 0x0000002A, 0x0000002A,   "Intelsis Sistemas Inteligentes S.A ." },
	{ 0x0000002D, 0x0000002D,   "Alpha Digital Synthesis S.A." },
	{ 0x0000002F, 0x0000002F,   "Conax A.S." },
	{ 0x00000030, 0x00000030,   "Telenor" },
	{ 0x00000031, 0x00000031,   "TeleDenmark " },
	{ 0x00000035, 0x00000035,   "Europe Online Networks S.A ." },
	{ 0x00000038, 0x00000038,   "OTE  " },
	{ 0x00000039, 0x00000039,   "Telewizja Polsat  " },
	{ 0x000000A0, 0x000000A0,   "Sentech  " },
	{ 0x000000A1, 0x000000A1,   "TechniSat Digital GmbH  " },
	{ 0x000000BE, 0x000000BE,   "BetaTechnik" },
	{ 0x000000C0, 0x000000C0,   "Canal+" },
	{ 0x000000D0, 0x000000D0,   "Dolby Laboratories Inc." },
	{ 0x000000E0, 0x000000E0,   "ExpressVu Inc." },
	{ 0x000000F0, 0x000000F0,   "France Telecom, CNES and DGA (STENTOR)" },
	{ 0x00000100, 0x00000100,   "OpenTV" },
	{ 0x00000150, 0x00000150,   "Loewe Opta GmbH " },
	{ 0x00000600, 0x00000601,   "UPC 1  " },
	{ 0x00000ACE, 0x00000ACE,   "Ortikon Interactive Oy" },
	{ 0x00001000, 0x00001000,   "La Télévision Par Satellite (TPS )" },
	{ 0x000022D4, 0x000022D4,   "Spanish Broadcasting Regulator " },
	{ 0x000022F1, 0x000022F1,   "Swedish Broadcasting Regulator " },
	{ 0x0000233A, 0x0000233A,   "Independent Television Commission " },
	{ 0x00003200, 0x0000320f,   "Australian Terrestrial Television Networks" },
	{ 0x00006000, 0x00006000,   "News Datacom" },
	{ 0x00006001, 0x00006006,   "NDC " },
	{ 0x00362275, 0x00362275,   "Irdeto" },
	{ 0x004E544C, 0x004E544C,   "NTL" },
	{ 0x00532D41, 0x00532D41,   "Scientific Atlanta" },
	{ 0x00600000, 0x00600000,   "Rhône Vision Cable" },
	{ 0x44414E59, 0x44414E59,   "News Datacom (IL) 1" },
	{ 0x46524549, 0x46524549,   "News Datacom (IL) 1" },
	{ 0x46545600, 0x46545620,   "FreeTV " },
	{ 0x4A4F4A4F, 0x4A4F4A4F,   "MSG MediaServices GmbH  " },
	{ 0x4F545600, 0x4F5456ff,   "OpenTV " },
	{ 0x50484900, 0x504849ff,   "Philips DVS" },
	{ 0x53415053, 0x53415053,   "Scientific Atlanta" },
	{ 0x5347444E, 0x5347444E,   "StarGuide Digital Networks " },
	{ 0x56444700, 0x56444700,   "Vía Digital" },
	{ 0xBBBBBBBB, 0xBBBBBBBB,   "Bertelsmann Broadband Group  " },
	{ 0xECCA0001, 0xECCA0001,   "ECCA (European Cable Communications Association )" },
	{ 0xFCFCFCFC, 0xFCFCFCFC,   "France Telecom" },
    {  0,0, NULL }
  };
#endif


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
int nit_decode_descriptors(uint8_t* a, NIT_TransportStream* b)
{
#if 0
	console_send_string("nit_decode_descriptors (todo.c): TODO\r\n");
#endif

	uint8_t* r4 = a + 2;
	uint8_t* r7 = 0;
	//r6, =dword_23493600
	uint8_t r5 = a[1];
	uint8_t r0 = a[0];
	Struct_23627118* r2 = Data_23493600;

#ifdef NIT_DESCRIPTORS_TAG_DEBUG
	{
		extern char debug_string[];
		sprintf(debug_string, "nit_decode_descriptors: descriptor=0x%02x, length=%d\r\n", r0, r5);
		console_send_string(debug_string);
	}
#endif

	switch (r0)
	{
	case 0x40:
	{
		//loc_2344d134: network_name_descriptor
		NIT_NetworkData* r6 = &r2->networkData;
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
#ifdef NIT_DESCRIPTORS_NETWORK_NAME_DEBUG
		{
			extern char debug_string[];
			sprintf(debug_string, "nit_decode_descriptors: network_name='%s'\r\n", r6->network_name);
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
			//NIT_TransportStream* r6 = b;
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
#ifdef NIT_DESCRIPTORS_SERVICE_LIST_DEBUG
				{
					extern char debug_string[];
					sprintf(debug_string, "nit_decode_descriptors: service[%d] id=0x%04x, type=0x%02x\r\n",
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

			b->modulation = r4[6] | (1 << 4);
#ifdef NIT_DESCRIPTORS_CABLE_SYSTEM_DEBUG
			{
				extern char debug_string[];
				sprintf(debug_string, "nit_decode_descriptors: frequency=%d, symbol_rate=%d, b->modulation=0x%02x\r\n",
						b->frequency, b->symbol_rate, b->modulation);
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
		{
			uint8_t linkage_type/*r0*/ = r4[6];
#ifdef NIT_DESCRIPTORS_LINKAGE_DEBUG
			{
				extern char debug_string[];
				sprintf(debug_string, "nit_decode_descriptors: linkage_type=0x%x\r\n", linkage_type);
				console_send_string(debug_string);
			}
#endif
			if (linkage_type == 0x0a)
			{
				//0x2344d6c4: TS containing SSU BAT or NIT
				uint8_t r0 = r4[7];
#ifdef NIT_DESCRIPTORS_LINKAGE_DEBUG
				{
					extern char debug_string[];
					sprintf(debug_string, "nit_decode_descriptors: r0=0x%x\r\n", r0);
					console_send_string(debug_string);
				}
#endif
				if ((r0 == 0x4a) || (r0 == 0x02) || (r0 == 0x01))
				{
					//->loc_2344d77c
				}
				//->loc_2344d714
			}
			//loc_2344d6dc
			else if (linkage_type == 0x09)
			{
				//0x2344d6e4: System Software Update (SSU) service
				uint32_t r0 = (r4[8] << 16) | (r4[9] << 8) | (r4[10]);
#ifdef NIT_DESCRIPTORS_LINKAGE_DEBUG
				{
					extern char debug_string[];
					sprintf(debug_string, "nit_decode_descriptors: r0=0x%x\r\n", r0);
					console_send_string(debug_string);
				}
#endif
#if 0 //TODO!!!
				if (r0 != Data_23492240)
				{
					//->loc_2344d8c0
					break;
				}
				//0x2344d70c
				void* r2_ = &r2->Data_8;
#endif
				//->loc_2344d77c
			} //else if (linkage_type == 0x09)
			else
			{
				//loc_2344d714
				if (Data_23493604 == 0)
				{
					//->loc_2344d8c0
					break;
				}
				//0x2344d720
				int r0 = (Data_23493604)(&r4[6], r5 - 7, nit_private_data_value);
#ifdef NIT_DESCRIPTORS_LINKAGE_DEBUG
				{
					extern char debug_string[];
					sprintf(debug_string, "nit_decode_descriptors: r0=0x%x\r\n", r0);
					console_send_string(debug_string);
				}
#endif
#if 0 //TODO!!!
				//r3 = 1
				if (r0 == 1)
				{
					//r2 = &Data_23493600->Data_0x10;
					Data_23493600->Data_0x10.bData_7 = 1; //r3
					//->loc_2344d77c
				} //if (r0 == 1)
				//0x2344d748
				//2 = 0xffff;
				else if (r0 == 2)
				{
					//0x2344d754
					if (Data_23493600->Data_0x10.wData_4 != 0xffff/*r2*/)
					{
						//->loc_2344d8c0
						break;
					}
					//0x2344d764
					uint8_t* r7_ = r7;
					if (r7_[7] == 1)
					{
						//->loc_2344d8c0
						break;
					}
					//0x2344d770
					r2 = &Data_23493600->Data_0x10;
					Data_23493600->Data_0x10.bData_7 = 2;
					//->loc_2344d77c
				} //else if (r0 == 2)
				//loc_2344d7cc
				else if (r0 == 3)
				{
					//0x2344d7d4
					if (Data_23493600->Data_0x10.bData_7 == 2)
					{
						Data_23493600->Data_0x10.wData_4 = 0xffff; //r2
					}
					Data_23493600->Data_0x10.bData_7 = 1; //r3
					//->loc_2344d8c0
					break;
				}
				else
				{
					//->loc_2344d8c0
					break;
				}
				//loc_2344d77c
				if (r2 != 0)
				{
					//0x2344d784

					//TODO
				}
#endif
				//->loc_2344d8c0
				break;
			} //else (linkage_type == ???)
		} //case 0x4a:: linkage_descriptor
		break;
	case 0x5a:
		//0x2344d054: terrestrial_delivery_system_descriptor
		break;
	case 0x5b:
		//loc_2344d8c0: multilingual_network_name_descriptor
		break;
	case 0x5f:
		//loc_2344d120: private_data_specifier_descriptor
		nit_private_data_value = (r4[0] << 24) | (r4[1] << 16) | (r4[2] << 8) | r4[3];
#ifdef NIT_DESCRIPTORS_PRIVATE_DATA_DEBUG
		{
			extern char debug_string[];
			sprintf(debug_string, "nit_decode_descriptors: private_data_specifier=0x%08x\r\n",
					nit_private_data_value);
			console_send_string(debug_string);
		}
#endif
		//->loc_2344d8c0
		break;
	case 0x62:
		//loc_2344d8c0: frequency_list_descriptor
		break;
	case 0x83:
		//0x2344d0f8
		if (b == 0)
		{
			//->loc_2344d864
			return 1;
		}
		//0x2344d100

		//TODO!!!
		break;
	case 0x87:
		//loc_2344d8c0
		break;
	case 0x88:
		//loc_2344d84c
		if (b == 0)
		{
			//->loc_2344d864
			return 1;
		}
		//0x2344d854

		//TODO!!!
		break;
	}
	//loc_2344d8c0
	//r0 = 0;
	//->loc_2344d868
	return 0;
}


static NIT_TransportStream* nit_decode_section_Inner(uint8_t* sp)
{
	NIT_TransportStream* r5 = Data_23493600->arTransportStreams;

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

		nit_private_data_value = 0; //r8

		Data_23493600->networkData.wData_0x1a = 0xff;

		NIT_TransportStream* r4 = Data_23493600->arTransportStreams;

		for (uint8_t r6 = 0; r6 < 200; r6++)
		{
			//loc_2344d9a4
			memset(r4, 0, sizeof(NIT_TransportStream));

			r4->wData_4 = 1; //sb

			r4++;
		}
	} //if (r2 != 0)
	//loc_2344d9cc
	int16_t r6 = ((r5[8] & 0x0f) << 8) | r5[9]; //network_descriptors_length
	uint32_t fp = ((r5[1] & 0x0f) << 8) | r5[2]; //section_length
	Data_23493600->networkData.network_id = (r5[3] << 8) | r5[4];

#if 0
	hex_dump("nit_decode_section", r5, fp);
#endif

	uint8_t* r4_ = r5 + 10;

	while (r6 > 0)
	{
		//loc_2344da0c: Decode Network Descriptors
		nit_decode_descriptors(r4_, 0);

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
		NIT_TransportStream* pTransportStream = Data_23493600->arTransportStreams;
		for (uint8_t r0 = 0; r0 < 200; r0++)
		{
			//loc_2344da5c
			if (pTransportStream->wData_4 == 1)
			{
				pTransportStream->wData_4 = 0; //r8
				//->loc_2344da8c
				break;
			}

			pTransportStream++;
		}
		//0x2344da84
		pTransportStream = 0;
		sp = 1; //sb
#else
		NIT_TransportStream* pTransportStream = nit_decode_section_Inner(&sp);
#endif
		//loc_2344da8c
		if (sp != 0)
		{
			//->loc_2344db18
			break;
		}
		//0x2344da98
		pTransportStream->transport_stream_id = (r4_[0] << 8) | r4_[1];
		pTransportStream->original_network_id = (r4_[2] << 8) | r4_[3];
		r7 -= 6;
		r6 = ((r4_[4] & 0x0f) << 8) | r4_[5]; //transport_descriptors_length
		r4_ += 6;
		r7 = r7 - r6;
		//->loc_2344db08
		while (r6 > 0)
		{
			//loc_2344dae4: Decode Transport Descriptors
			nit_decode_descriptors(r4_, pTransportStream);

			r6 = r6 - r4_[1] - 2;
			r4_ = r4_ + r4_[1] + 2;
		}
		//loc_2344db10
	} //while (r7 > 0)
	//loc_2344db18
	return fp + 3;
}


/* 2344dbdc - todo */
int sub_2344dbdc(uint8_t a, Struct_2344dbdc* b)
{
#if 0
	console_send_string("sub_2344dbdc (todo.c): TODO\r\n");
#endif

	Struct_23627118* r0 = &Data_23627118[a];

	b->pNetworkData = &r0->networkData;
	b->pTransportStream = &r0->arTransportStreams[0];

	if (r0->Data_8.wData_4 != 0xffff)
	{
		if ((r0->Data_8.wData_4 != 0) ||
			(r0->Data_8.wData_2 != 0) ||
			(r0->Data_8.bData_6 != 0))
		{
			b->Data_0 = &r0->Data_8;
		}
		else
		{
			b->Data_0 = 0;
		}
	}
	else
	{
		b->Data_0 = 0;
	}

	return 0;
}


/* 2344dc3c - todo */
int sub_2344dc3c(uint8_t a, Struct_2344dc3c* b)
{
#if 0
	console_send_string("sub_2344dc3c (todo.c): TODO\r\n");
#endif

	Struct_23627118* r0 = &Data_23627118[a];

	b->pNetworkData = &r0->networkData;
	b->pTransportStream = &r0->arTransportStreams[0];

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


/* 2344dc7c - todo */
int sub_2344dc7c(uint8_t a, Struct_2344dbdc* b)
{
#if 0
	console_send_string("sub_2344dc7c (todo.c): TODO\r\n");
#endif

	Struct_23627118* r0 = &Data_23627118[a];

	b->pNetworkData = &r0->networkData;
	b->pTransportStream = &r0->arTransportStreams[0];
	b->Data_0 = 0;

	if (Data_23493604 == 0)
	{
		if (r0->Data_8.wData_4 != 0xffff)
		{
			b->Data_0 = &r0->Data_8;
		}
	}
	else 
	{
		//loc_2344dccc
		if (r0->Data_0x10.wData_4 != 0xffff)
		{
			b->Data_0 = &r0->Data_0x10;
		}
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

	r0->networkData.wData_0x1a = b;

}



