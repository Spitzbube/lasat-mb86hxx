

#include "data.h"
#include "timer.h"
#include "bm.h"
#include "tsd.h"
#include "pat.h"
#include "pmt.h"
#include "nit.h"
#include "sdt.h"
#include "psi.h"


#define PSI_PID_CHANNEL_PAT			11
#define PSI_PID_CHANNEL_PMT			12
#define PSI_PID_CHANNEL_TDT			13
#define PSI_PID_CHANNEL_SDT_BAT		14
#define PSI_PID_CHANNEL_NIT			15
#define PSI_PID_CHANNEL_EIT			16
#define PSI_PID_CHANNEL_CAT			19


typedef struct
{
	uint8_t handled; //0
	int activeMask; //4
	int Data_8; //8
	void (*pfOnPSIData)(); //12 = 0x0c
	void (*Data_0x10)(); //16 = 0x10
	uint16_t wData_0x14; //20 = 0x14
	uint16_t wData_0x16; //22 = 0x16
	uint16_t wData_0x18; //24 = 0x18
	//0x1c
} Queue_Item_Data;

typedef struct
{
	int state; //0
	Queue_Item_Data* pData; //4
	//8
} Queue_Item;


const int psi_arLastSectionNumberMask[] = //23487e14
{
		0x00000000,
		0x00000001,
		0x00000003,
		0x00000007,
		0x0000000f,
		0x0000001f,
		0x0000003f,
		0x0000007f,
		0x000000ff,
		0x000001ff,
		0x000003ff,
		0x000007ff,
		0x00000fff,
		0x00001fff,
		0x00003fff,
		0x00007fff,
		0x0000ffff,
		0x0001ffff,
		0x0003ffff,
		0x0007ffff,
		0x000fffff,
		0x001fffff,
		0x003fffff,
		0x007fffff,
		0x00ffffff,
		0x01ffffff,
		0x03ffffff,
		0x07ffffff,
		0x0fffffff,
		0x1fffffff,
		0x3fffffff,
		0x7fffffff,
		0xffffffff
};

const int psi_arSectionNumberBits[] = //23487e98
{
		0x00000001,
		0x00000002,
		0x00000004,
		0x00000008,
		0x00000010,
		0x00000020,
		0x00000040,
		0x00000080,
		0x00000100,
		0x00000200,
		0x00000400,
		0x00000800,
		0x00001000,
		0x00002000,
		0x00004000,
		0x00008000,
		0x00010000,
		0x00020000,
		0x00040000,
		0x00080000,
		0x00100000,
		0x00200000,
		0x00400000,
		0x00800000,
		0x01000000,
		0x02000000,
		0x04000000,
		0x08000000,
		0x10000000,
		0x20000000,
		0x40000000,
		0x80000000
};


uint8_t psi_arAudioLanguage[4/*size???*/] = {0}; //23491f68


Queue_Item Data_234ac594 = //23491f84 / 234ac594
{
		5, (void*) 0x01
};

Queue_Item Data_234ac59c = //23491f8c / 234ac59c
{
		5, (void*) 0x08
};

Queue_Item Data_234ac5a4 = //23491f94 / 234ac5a4
{
		5, (void*) 0x40
};

Queue_Item Data_234ac5ac = //23491f9c / 234ac5ac
{
		5, (void*) 0x02
};

Queue_Item Data_234ac5b4 = //23491fa4 / 234ac5b4
{
		5, (void*) 0x80
};

Queue_Item Data_234ac5bc = //23491fac / 234ac5bc
{
		5, (void*) 0x100
};



struct
{
	int words[THREAD_STACK_SIZE_PSI];
} Data_234a5490/*stack*/[2]; //234a5490 -> 234A73D0

struct
{
	int fill_0[5]; //0
	uint16_t wData_0x14; //20 = 0x14

} Data_234a73d0; //234a73d0

Struct_234a73e8 Data_234a73e8[2]; //234a73e8 -> 234EB108 / 23503268 -> ?
int Data_234eb108[64]; //234eb108




void sub_23406a74(Struct_234a73e8*);
void sub_23406ac8(Struct_236e5834*);



/* 23403238 / 234056fc - complete */
void psi_register_version_number(Struct_234a73e8* r6, uint8_t r4, uint8_t versionNumber)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("psi_register_version_number (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	if (r4 & 1)
	{
		r6->bPAT_VersionNumber = versionNumber;
	}
	else if (r4 & 2)
	{
		r6->bPMT_VersionNumber = versionNumber;
	}
	else if (r4 & 0x08)
	{
		r6->bSDT_VersionNumber = versionNumber;
	}
	else if (r4 & 0x40)
	{
		r6->bNIT_VersionNumber = versionNumber;
	}
	else if (r4 & 4)
	{
		r6->bData_0x21e81 = versionNumber;
	}

	OS_EXIT_CRITICAL();
}


/* 2340362c / 23405af0 - todo */
int psi_timer_func(Struct_234a73e8* r5)
{
#if 1
#if 0
	console_send_string("psi_timer_func (todo.c): TODO\r\n");
#endif

#if 0
	uint32_t TSD01_PACKET_COUNTER = FREG(0xC8000110)[0];
	uint32_t TSD23_PACKET_COUNTER = FREG(0xC8800110)[0];
	uint32_t TSD01_VALID_PACKET_COUNTER = FREG(0xC8000118)[0];
	uint32_t TSD23_VALID_PACKET_COUNTER = FREG(0xC8800118)[0];

	{
		extern char debug_string[];
		sprintf(debug_string, "TSD01_PACKET_COUNTER=%d, TSD23_PACKET_COUNTER=%d\r\n",
				TSD01_PACKET_COUNTER, TSD23_PACKET_COUNTER);
		console_send_string(debug_string);
	}
#endif
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "TSD01_VALID_PACKET_COUNTER=%d, TSD23_VALID_PACKET_COUNTER=%d\r\n",
				TSD01_VALID_PACKET_COUNTER, TSD23_VALID_PACKET_COUNTER);
		console_send_string(debug_string);
	}
#endif

#if 0
	for (uint32_t i = 0; i < 32; i++)
	{
		volatile uint32_t* pTSD0_SB_CTRL = (void*) (0xC8500000 + i * 8);
		uint32_t TSD0_SB_CTRL = pTSD0_SB_CTRL[0];
		uint32_t TSD0_CRC = pTSD0_SB_CTRL[1];

		switch (i)
		{
#if 0
		case PSI_PID_CHANNEL_PAT:
		case PSI_PID_CHANNEL_PMT:
		case PSI_PID_CHANNEL_SDT_BAT:
		case PSI_PID_CHANNEL_NIT:
#endif
			{
				extern char debug_string[];
				sprintf(debug_string, "PID channel %d: TSD0_SB_CTRL=0x%08x, TSD0_CRC=0x%08x\r\n",
						i, TSD0_SB_CTRL, TSD0_CRC);
				console_send_string(debug_string);

#if 0
				uint32_t FILTER_INDEX = TSD0_SB_CTRL & 0x1f;
				uint32_t FILTER_MATCH = (TSD0_SB_CTRL >> 5) & 1;
				uint32_t RESIDUE_CNT  = (TSD0_SB_CTRL >> 8) & 0xfff;
				uint32_t RD_PTR = (TSD0_SB_CTRL >> 20) & 0x3f;
				uint32_t WR_PTR = (TSD0_SB_CTRL >> 26) & 0x3f;

				sprintf(debug_string, "FILTER_INDEX=0x%03x, FILTER_MATCH=%d, RESIDUE_CNT=%d, RD_PTR=%d, WR_PTR=%d\r\n",
						FILTER_INDEX, FILTER_MATCH, RESIDUE_CNT, RD_PTR, WR_PTR);
				console_send_string(debug_string);
#endif
			}
			break;

		default:
			break;
		}
	}
#endif

#if 0
	{
		uint32_t tsd01_status = FREG(0xC8000138)[0]; //TSD01_STATUS
		uint32_t pid_index = tsd01_status & 0x1f;
		switch (pid_index)
		{
			case 8:
			{
				extern char debug_string[];
				sprintf(debug_string, "psi_timer_func: pid_index=%d\r\n",
						pid_index);
				console_send_string(debug_string);
				break;
			}

			case 9:
			{
				extern char debug_string[];
				sprintf(debug_string, "psi_timer_func: pid_index=%d\r\n",
						pid_index);
				console_send_string(debug_string);
				break;
			}

			default:
			{
				extern char debug_string[];
				sprintf(debug_string, "psi_timer_func: tsd01_status=0x%x\r\n",
						tsd01_status);
				console_send_string(debug_string);
				break;
			}
		}
	}
#endif

#endif

	if (r5->wData_0x21e1c != 0)
	{
		//0x23403648
		r5->wData_0x21e1c--;
		if (r5->wData_0x21e1c == 0)
		{
			OSQPost(r5->queue, &Data_234ac594);
		}
	}
	//loc_23403668
	if (r5->wSDT_BAT_Timeout != 0)
	{
		r5->wSDT_BAT_Timeout--;
		if (r5->wSDT_BAT_Timeout == 0)
		{
			if (r5->activeMask & 0x08)
			{
				OSQPost(r5->queue, &Data_234ac59c); //23491f8c
			}
			else
			{
				OSQPost(r5->queue, &Data_234ac5b4); //23491fa4
			}
		}
	}
	//loc_234036a8
	if (r5->wNIT_Timeout != 0)
	{
		r5->wNIT_Timeout--;
		if (r5->wNIT_Timeout == 0)
		{
			OSQPost(r5->queue, &Data_234ac5a4); //23491f94
		}
	}
	//loc_234036d4
	if (r5->wData_0x21e1e != 0)
	{
		r5->wData_0x21e1e--;
		if (r5->wData_0x21e1e == 0)
		{
			OSQPost(r5->queue, &Data_234ac5ac); //23491f9c
		}
	}
	//loc_23403700
	if (r5->wData_0x21e26 != 0)
	{
		r5->wData_0x21e26--;
		if (r5->wData_0x21e26 == 0)
		{
			OSQPost(r5->queue, &Data_234ac5bc); //23491fac
		}
	}
	//loc_2340372c
	return 0;
}


/* 23403734 - todo */
void sub_23403734(Struct_234a73e8* r5)
{
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23403734 (TODO): r5->activeMask=0x%x\r\n", r5->activeMask);
		console_send_string(debug_string);
	}
#endif

	//r4, r0, #0x21000
	//r6, r5, #0x21e00

	if (r5->activeMask & 1)
	{
		r5->activeMask &= ~1;
		r5->wData_0x21e1c = 0; //r7

		tsd_deactivate_pid_channel(r5->Data_8.tsdPAT);
	}
	//r7 = 0;
	if (r5->activeMask & 2)
	{
		//0x23403774
		r5->activeMask &= ~2;

		r5->wData_0x21e1e = 0; //r7

		tsd_deactivate_pid_channel(r5->Data_8.tsdPMT);

		if (r5->pfOnPMTData != 0)
		{
			(r5->pfOnPMTData)(0, 0);
		}
	}
	//loc_2340379c
	if (r5->activeMask & 4)
	{
		//0x234037a8
		r5->activeMask &= ~4;

		tsd_deactivate_pid_channel(r5->Data_8.tsdCAT);

		if (r5->Data_0x22c != 0)
		{
			int sp;
			(r5->Data_0x22c)(&sp, 0, 0);
		}
	}
	//loc_234037d0
	if (r5->activeMask & 0x88)
	{
		//0x234037dc
		r5->wSDT_BAT_Timeout = 0; //r7

		if (r5->activeMask & 0x08)
		{
			r5->activeMask &= ~0x08;
		}

		if (r5->activeMask & 0x80)
		{
			r5->activeMask &= ~0x80;
		}

		tsd_deactivate_pid_channel(r5->Data_8.tsdSDT_BAT);
	}
	//loc_23403804
	if (r5->activeMask & 0x40)
	{
		//0x2340380c
		r5->wNIT_Timeout = 0; //r7
		r5->activeMask &= ~0x40;

		tsd_deactivate_pid_channel(r5->Data_8.tsdNIT);
	}

	if (r5->activeMask & 0x10)
	{
		r5->wData_0x21e24 = 0; //r7
		r5->activeMask &= ~0x10;

		tsd_deactivate_pid_channel(r5->Data_8.tsdTDT);
	}

	if (r5->activeMask & 0x100)
	{
		r5->wData_0x21e26 = 0; //r7
		r5->activeMask &= ~0x100;

		tsd_deactivate_pid_channel(r5->Data_8.Data_0x88);
	}

	if (r5->activeMask & 0x200)
	{
		r5->activeMask &= ~0x200;

		tsd_deactivate_pid_channel(r5->Data_8.Data_0xf8);
	}

	if (r5->activeMask & 0x20)
	{
		r5->activeMask &= ~0x20;

		tsd_deactivate_pid_channel(r5->Data_8.tsdEIT);
	}

	if (r5->activeMask & 0x10)
	{
		r5->activeMask &= ~0x10;

		tsd_deactivate_pid_channel(r5->Data_8.tsdTDT);
	}

	if (r5->activeMask & 0x400)
	{
		r5->activeMask &= ~0x400;

		tsd_deactivate_pid_channel(r5->Data_8.Data_0x14c);

		//TODO!!!
	}
	//loc_234038f8
	if (r5->activeMask & 0x800)
	{
		r5->activeMask &= ~0x800;

		tsd_deactivate_pid_channel(r5->Data_8.Data_0x168);
	}

	if (r5->activeMask & 0x1000)
	{
		r5->activeMask &= ~0x1000;

#if 0 //TODO!!!
		tsd_deactivate_pid_channel(r5->Data_8.Data_0x184);
#endif
	}

	if (r5->activeMask & 0x2000)
	{
		r5->activeMask &= ~0x2000;

		tsd_deactivate_pid_channel(r5->Data_8.Data_0x114);
	}
}


/* 23403948 - todo */
void sub_23403948(Struct_234a73e8* r5)
{
	//r4, r0, #0x21000

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23403948: r5->activeMask=0x%x, r5->Data_0x21e04=0x%x\r\n",
				r5->activeMask, r5->Data_0x21e04);
		console_send_string(debug_string);
	}
#endif

	int r1 = r5->Data_0x21e04;
	//r6 = 0;
	//r0 = 1;

	if ((r5->activeMask/*r2*/ & 1) == 0)
	{
		r5->/*bData_0x21e70*/Data_0x21e6a[1].bData_2 = 0; //r6
	}
	//0x23403970
	else if ((/*r5->Data_0x21e04*/r1 & 1) == 0)
	{
		r5->/*bData_0x21e70*/Data_0x21e6a[1].bData_2 = 1; //r0
		r5->/*bData_0x21e71*/Data_0x21e6a[1].bData_3 = 0; //r6
	}
	//loc_2340397c
	if ((r5->activeMask/*r2*/ & 2) == 0)
	{
		r5->bPMT_State = 0; //r6
	}
	//0x2340398c
	else if ((/*r5->Data_0x21e04*/r1 & 2) == 0)
	{
		r5->bPMT_State = 0; //r6
		r5->bData_0x21e73 = 0; //r6
	}
	//loc_23403998
	r5->bSDT_BAT_State = 0; //r6
	if ((r5->activeMask/*r2*/ & 8) == 0)
	{
		/* empty */
	}
	//0x234039a8
	else if ((/*r5->Data_0x21e04*/r1 & 8) == 0)
	{
		r5->bSDT_BAT_State = 1; //r0
		r5->bData_0x21e8c = 1; //r0
		r5->bData_0x21e84 = 0; //r6
		r5->bData_0x21e82 = 0; //r6
		r5->bData_0x21e83 = 0; //r6
	}
	//loc_234039c0
	if ((r5->activeMask/*r2*/ & 0x80) == 0)
	{
		/* empty */
	}
	//0x234039cc
	else if ((/*r5->Data_0x21e04*/r1 & 0x80) == 0)
	{
		r5->bSDT_BAT_State = 1; //r0
		r5->bData_0x21e8d = 1; //r0
		r5->bData_0x21e8a = 0; //r6
		r5->bData_0x21e85 = 0; //r6
		r5->bData_0x21e89 = 0; //r6
	}
	//loc_234039e4
	if ((r5->activeMask/*r2*/ & 4) == 0)
	{
		r5->bData_0x21e75 = 0; //r6
	}
	//0x234039f4
	else if ((/*r5->Data_0x21e04*/r1 & 4) == 0)
	{
		r5->bData_0x21e75 = 1; //r0
		r5->bData_0x21e76 = 0; //r6
	}
	//loc_23403a00
	if ((r5->activeMask/*r2*/ & 0x40) == 0)
	{
		r5->bNIT_State = 0; //r6
	}
	//0x23403a10
	else if ((/*r5->Data_0x21e04*/r1 & 0x40) == 0)
	{
		r5->bNIT_State = 1; //r0
		r5->bData_0x21e8b = 1; //r0
		r5->bData_0x21e88 = 0; //r6
		r5->bNIT_SectionNumberBits = 0; //r6
		r5->bNIT_SectionNumberMask = 0; //r6
	}
	//loc_23403a28
	if (r5->activeMask/*r2*/ & 0x20)
	{
		r5->bEIT_State = 1; //r0
	}
	else
	{
		r5->bEIT_State = 0; //r6
	}
	//0x23403a38
	if (r5->activeMask/*r2*/ & 0x10)
	{
		r5->bData_0x21e78 = 1; //r0
	}
	else
	{
		r5->bData_0x21e78 = 0; //r6
	}
	//0x23403a48
	if ((r5->activeMask/*r2*/ & 0x100) == 0)
	{
		r5->bData_0x21e79 = 0; //r6
	}
	else
	{
		//0x23403a58
		r5->bData_0x21e79 = 1; //r0
		r5->bData_0x21e8e = 1; //r0

		memset(Data_234eb108, 0, 0x100);
	}
	//loc_23403a6c
	if (r5->activeMask/*r2*/ & 0x400)
	{
		for (uint32_t i = 0; i < 2; i++)
		{
			//loc_23403a7c
			r5->Data_0x21e6a[i].bData_0 = 0; //r6;
		}

		for (uint32_t i = 0; i < 2; i++)
		{
			//loc_23403a98
			r5->Data_0x21e62[i].bData_0 = 0; //r6;
		}
	}
}


/* 234044c4 / 23406938 - complete */
void psi_default_data_handler(Struct_234a73e8* a)
{
#if 0
	console_send_string("psi_default_data_handler (todo.c): TODO\r\n");
#endif

	uint16_t r1 = pat_get_num_programs(a->index);

	for (uint16_t i = 0; i < r1; i++)
	{
		/* empty */
	}
}


/* 23406a9c - complete */
PSI_Program* sub_23406a9c(Struct_234a73e8* a)
{
#if 0
	console_send_string("sub_23406a9c (todo.c): TODO\r\n");
#endif

	PSI_Program* r0 = a->programs;

	for (uint32_t i = 0; i < 150; i++)
	{
		if ((r0->bData_0 & 0x80) == 0)
		{
			return r0;
		}

		r0++;
	}

	return 0;
}


/* 23403ab4 - todo */
void sub_23403ab4(uint8_t r6, Struct_234a73e8* r7)
{
#if 0
	console_send_string("sub_23403ab4 (todo.c): TODO\r\n");
#endif

	if (r6 & 0x01)
	{
		//0x23403ac8
		//->loc_23403b20
		for (uint32_t i = 0; i < r7->wData_0x21e10; i++)
		{
			//loc_23403ad8
			PAT_Program* r5 = pat_get_program(r7->index, i);

			if (r5->program_number != 0)
			{
				//0x23403af8
				PSI_Program* r0 = sub_23406a9c(r7);

				r0->bData_0 |= 0xc0;
				r0->pat_program_number = r5->program_number;
				r0->pmt_pid = r5->pmt_pid;
			}
			//loc_23403b1c
		}
		//loc_23403b2c
	}
	//loc_23403b2c
	//fp, #0x0
	if ((r6 & 0x08) && (r7->Data_0x21e04 & 0x08))
	{
		//0x23403b44
		uint8_t r4 = sub_2344cd54(r7->index)->table_id;
		struct SDT_Service* r5 = sub_2344cd54(r7->index)->Data_8;

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_23403ab4: r4=0x%02x\r\n", r4);
			console_send_string(debug_string);
		}
#endif

		if (r4 == 0x42) //service_description_section - actual_transport_stream
		{
			//0x23403b6c -> loc_23403bc4
			while (r5 != 0)
			{
				//loc_23403b70
				PSI_Program* r0 = r7->programs;
				//->loc_23403bb4
				while (r0->bData_0 & 0x80)
				{
					//loc_23403b78
					if (r5->service_id == r0->pat_program_number)
					{
						//0x23403b88
						PSI_Program* r0 = sub_23406a9c(r7);

						if (r0 != 0)
						{
							r0->bData_0 |= 0xc0;
							r0->pat_program_number = r5->service_id;
							r0->pmt_pid = 0; //fp
						}
						//->loc_23403bc0
						break;
					}
					//loc_23403bb0
					r0++;
				}
				//loc_23403bc0
				r5 = r5->next;
			} //while (r5 != 0)
			//0x23403bcc
			r5 = sub_2344cd54(r7->index)->Data_8;
			//->loc_23403cf4
			while (r5 != 0)
			{
				//loc_23403be0
				PSI_Program* r4 = r7->programs;
				//->loc_23403ce4
				while (r4->bData_0 & 0x80)
				{
					//loc_23403be8
					if (r5->service_id == r4->pat_program_number)
					{
						//0x23403bf8
//						struct SDT_Service_Inner_0x10* r0 = r5->Data_0x10;
						if (/*r0*/r5->Data_0x10 != 0)
						{
							//0x23403c04
							r4->service_name = /*r0*/r5->Data_0x10->service_name;
							r4->transport_stream_id = sub_2344cd54(r7->index)->transport_stream_id;
							r4->original_network_id = sub_2344cd54(r7->index)->original_network_id;

							uint8_t r0 = r5->Data_0x10->service_type;

							if ((r0 == 0x11) || //MPEG-2 HD digital television service
									(r0 == 0x01) || //digital television service
									(r0 == 0x16) || //advanced codec SD digital television service
									(r0 == 0x19) || //advanced codec HD digital television service
									(r0 == 0x1f) ||
									(r0 == 0x86) ||
									(r0 == 0xd3) ||
									(r0 == 0xd5))
							{
								r4->bData_0 |= 0x08;
								//->loc_23403c7c
								r4->bData_0 &= 0xbf;
							}
							else if ((r0 == 0x02) || //digital radio sound service
									(r0 == 0x0a)) //advanced codec digital radio sound service
							{
								//0x23403c74
								r4->bData_0 &= ~0x08;
								//->loc_23403c7c
								r4->bData_0 &= 0xbf;
							}
							//loc_23403c84
							if (r5->free_CA_mode != 0)
							{
								r4->bData_0 |= 1;
							}
							else
							{
								r4->bData_0 &= ~1;
							}
							//->loc_23403cf0
						} //if (r5->Data_0x10 != 0)
						else
						{
							//loc_23403ca0
							r4->transport_stream_id = sub_2344cd54(r7->index)->transport_stream_id;
							r4->original_network_id = sub_2344cd54(r7->index)->original_network_id;

							r4->bData_0 |= 0x08;
							r4->bData_0 &= 0xbf;
							r4->service_name = 0; //fp
							//->loc_23403cf0
						}
						//loc_23403cf0
						break;
					} //if (r5->service_id == r4->pat_program_number)
					//loc_23403ce0
					r4++;
				} //while (r4->bData_0 & 0x80)
				//loc_23403cf0
				r5 = r5->next;
			} //while (r5 != 0)
			//0x23403cfc -> loc_23403de0
		}
		//loc_23403d00
		else if (r4 == 0x46) //service_description_section - other_transport_stream
		{
			//0x23403d08 -> loc_23403dd8
			while (r5 != 0)
			{
				//loc_23403d0c
				if (r5->Data_0x10 != 0)
				{
					//0x23403d18
					PSI_Program* r4 = sub_23406a9c(r7);

					r4->bData_0 |= 0xc0;
					r4->pat_program_number = r5->service_id;
					r4->pmt_pid = 0; //fp;
					r4->service_name = r5->Data_0x10->service_name;
					r4->transport_stream_id = sub_2344cd54(r7->index)->transport_stream_id;
					r4->original_network_id = sub_2344cd54(r7->index)->original_network_id;

					uint8_t r0 = r5->Data_0x10->service_type;

					if ((r0 == 0x11) || //MPEG-2 HD digital television service
							(r0 == 0x01) || //digital television service
							(r0 == 0x16) || //advanced codec SD digital television service
							(r0 == 0x19) || //advanced codec HD digital television service
							(r0 == 0x1f) ||
							(r0 == 0x86) ||
							(r0 == 0xd3))
					{
						r4->bData_0 |= 0x08;
						//->loc_23403db4
						r4->bData_0 &= 0xbf;
					}
					else if ((r0 == 0x02) || //digital radio sound service
							(r0 == 0x0a)) //advanced codec digital radio sound service
					{
						//0x23403dac
						r4->bData_0 &= ~0x08;
						//loc_23403db4
						r4->bData_0 &= 0xbf;
					}
					//loc_23403dbc
					if (r5->free_CA_mode != 0)
					{
						r4->bData_0 |= 1;
					}
					else
					{
						r4->bData_0 &= ~1;
					}
				} //if (r5->Data_0x10 != 0)
				//loc_23403dd4
				r5 = r5->next;
			}
			//loc_23403de0
		}
		//loc_23403de0
	}
	//loc_23403de0
	if (r6 & 0x02)
	{
		//0x23403de8
		int sb = 0;
		struct Struct_236001c8* sp4 = pmt_get_data(r7->index & 0xff);
		//sl = sp4 + 0x1000;
		PSI_Program* r5 = r7->programs;

		r7->programs[0].bData_1 = sp4->version_number;
		//->loc_234043a4
		while ((r5->bData_0 & 0x80) != 0)
		{
			//loc_23403e10
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_23403ab4: sp4->program_number=%d, r5->pat_program_number=%d\r\n",
						sp4->program_number, r5->pat_program_number);
				console_send_string(debug_string);
			}
#endif

			if (sp4->program_number == r5->pat_program_number)
			{
				//0x23403e20
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "sub_23403ab4: sp4->program_number=%d, r5->pat_program_number=%d\r\n",
							sp4->program_number, r5->pat_program_number);
					console_send_string(debug_string);
				}
#endif

				r5->wPcrPID = sp4->PCR_PID;

				PMT_ElementaryStream* r4 = sp4->pFirstElementaryStreams;

				r5->wAudioPID = 0; //fp;
				r5->wData_0x338 = 0; //fp;

				for (uint32_t i = 0; i < 50; i++)
				{
					//loc_23403e3c
					r5->arAudioPids[i] = 0; //fp
					r5->arAudioComponentTags[i] = 0; //fp
					r5->arAudioLanguageStrings[i] = 0; //fp
					r5->Data_0x198[i] = 0; //fp
					r5->arAudioLanguage2Strings[i] = 0; //fp
				}
				//0x23403e64
				memset(r5->Data_0x340, 0, 0x50);

				r5->bData_0x394 = 0; //fp

				for (uint32_t i = 0; i < 20; i++)
				{
					//loc_23403e7c
					if (sp4->Data_4[i].wData_0x108 & 0x02)
					{
						r5->bData_0x394 = 1;
						//->loc_23404398
						break;
					}
				} //for (uint32_t i = 0; i < 20; i++)
				//0x23403ea8 -> loc_23404398
				while (r4 != 0)
				{
					//loc_23403eac
					char sp[4];

					text_table_get_string(0, &sp, 4);

#if 0
					{
						extern char debug_string[];
						sprintf(debug_string, "loc_23403eac: r4->bData_8=%d\r\n",
								r4->bData_8);
						console_send_string(debug_string);
					}
#endif

					if (r4->bData_8 != 0)
					{
						//0x23403ec8
						if (r5->wData_0x338 == 0)
						{
							r5->wData_0x338 = r4->elementary_PID;
							//->loc_23403f08
						}
						else
						{
							//0x23403edc
							if (0 != strlen(r4->language))
							{
								//0x23403eec
#if 1
								{
									extern char debug_string[];
									sprintf(debug_string, "loc_23403eac: r4->blanguage='%s'\r\n",
											r4->language);
									console_send_string(debug_string);
								}
#endif
								if (0 == strcmp(r4->language, sp))
								{
									r5->wData_0x338 = r4->elementary_PID;
									r5->wAudioPID = 0; //fp
								}
							}
							//loc_23403f08
						}
						//loc_23403f08

						//TODO!!!
					}
#if 1 //TODO!!!
#if 0
					{
						extern char debug_string[];
						sprintf(debug_string, "0x23403fe8: r4->stream_type=0x%x\r\n",
								r4->stream_type);
						console_send_string(debug_string);
					}
#endif
					//loc_23403fdc
					switch (r4->stream_type)
					{
					case 1: //ISO/IEC 11172-2 Video
					case 2: //ITU-T Rec H.262 | ISO/IEC 13818-2 Video stream descriptor or ISO/IEC 11172-2 constrained parameter video stream
						//2340424C
						//TODO!!!
						break;

					case 3: //ISO/IEC 11172-3 Audio stream descriptor
					case 4: //ISO/IEC 13818-3 Audio MPEG Audio layer 1/2
						//23404054
						if (sb == 0)
						{
							//0x2340405c
#if 0
							{
								extern char debug_string[];
								sprintf(debug_string, "0x2340405c: r5->wAudioPID=0x%x\r\n",
										r5->wAudioPID);
								console_send_string(debug_string);
							}
#endif
							if (r5->wAudioPID == 0)
							{
								//0x23404068
								r5->wAudioPID = r4->elementary_PID;

								if (0 == strlen(r4->language))
								{
									//0x23404084
									psi_arAudioLanguage[0] = 0; //fp
									//->loc_23404170
								}
								else
								{
									//r0, =0x23491f68
									//->loc_23404160
#if 0
									{
										extern char debug_string[];
										sprintf(debug_string, "loc_23404160: r4->language='%s'\r\n",
												r4->language);
										console_send_string(debug_string);
									}
#endif
									memcpy(psi_arAudioLanguage, r4->language, 4); //strcpy?
									//loc_23404170
								}
							} //if (r5->wAudioPID == 0)
							else
							{
								//loc_2340411c
								if ((0 != strcmp(psi_arAudioLanguage, sp)) &&
										(0 != strlen(r4->language)) &&
										(0 == strcmp(r4->language, sp)))
								{
									//0x23404154
									r5->wAudioPID = r4->elementary_PID;
									//loc_23404160
									memcpy(psi_arAudioLanguage, r4->language, 4); //strcpy?
								}
								//loc_23404170
							}
						} //if (sb == 0)
						//loc_23404170
						for (uint32_t langIdx = 0; langIdx < 50; langIdx++)
						{
							//loc_23404174
							if (r5->arAudioPids[langIdx] == 0)
							{
								//0x23404184
								r5->arAudioPids[langIdx] = r4->elementary_PID;
								r5->arAudioComponentTags[langIdx] = r4->component_tag;
								r5->Data_0x198[langIdx] = 0; //fp

								if (0 != strlen(r4->language))
								{
									//loc_234041b0
									//langIdx, r4, #0xa
									//->loc_23404104
									r5->arAudioLanguageStrings[langIdx] = &r4->language[0];
									//->loc_23404394
								}
								//loc_2340421c
								else if (0 != strlen(&r4->language[4]))
								{
									r5->arAudioLanguage2Strings[langIdx] = &r4->language[4];
									//->loc_23404394
								}
								else
								{
									//loc_23404234
									//ldr        langIdx, =aDefault
									//loc_23404104
									r5->arAudioLanguageStrings[langIdx] = "default";
								}
								//->loc_23404394
								break;
							}
							//loc_2340423c
						} //for (uint32_t langIdx = 0; langIdx < 50; langIdx++)
						//->loc_23404394
						break;

					case 6: //ITU-T Rec H.222.0 | ISO/IEC 13818-1 Private PES data packets
						//23404264
						//TODO!!!
						break;

					case 11: //ISO/IEC 13818-6 type B
					case 13: //ISO/IEC 13818-6 type D
						//loc_23404308
						//		//sl = sp4 + 0x1000;
						if (sp4->bData_0x14cc == 0)
						{
							//0x23404318
#if 0 //TODO!!!
							r7->bData_0x21d58 = 1;
#endif
							//->loc_23404394
						}
						else
						{
							//loc_23404334
							for (uint32_t r0 = 0; r0 < 10; r0++)
							{
								//loc_23404334

								//TODO!!!

								//loc_23404388
							}
							//loc_23404394
						}
						//loc_23404394
						break;

					case 15: //ISO/IEC 13818-7 MPEG2 Audio with ADTS transport syntax
					case 17: //ISO/IEC 14496-3 MPEG4 Audio with the LATM transport syntax as defined in ISO/IEC 14496-3
						//0x23404048
						r4->elementary_PID |= (1 << 14);
						
						if (sb == 0)
						{
							//0x2340405c
#if 0
							{
								extern char debug_string[];
								sprintf(debug_string, "0x2340405c: r5->wAudioPID=0x%x\r\n",
										r5->wAudioPID);
								console_send_string(debug_string);
							}
#endif
							if (r5->wAudioPID == 0)
							{
								//0x23404068
								r5->wAudioPID = r4->elementary_PID;

								if (0 == strlen(r4->language))
								{
									//0x23404084
									psi_arAudioLanguage[0] = 0; //fp
									//->loc_23404170
								}
								else
								{
									//r0, =0x23491f68
									//->loc_23404160
#if 0
									{
										extern char debug_string[];
										sprintf(debug_string, "loc_23404160: r4->language='%s'\r\n",
												r4->language);
										console_send_string(debug_string);
									}
#endif
									memcpy(psi_arAudioLanguage, r4->language, 4); //strcpy?
									//loc_23404170
								}
							} //if (r5->wAudioPID == 0)
							else
							{
								//loc_2340411c
								if ((0 != strcmp(psi_arAudioLanguage, sp)) &&
										(0 != strlen(r4->language)) &&
										(0 == strcmp(r4->language, sp)))
								{
									//0x23404154
									r5->wAudioPID = r4->elementary_PID;
									//loc_23404160
									memcpy(psi_arAudioLanguage, r4->language, 4); //strcpy?
								}
								//loc_23404170
							}
						} //if (sb == 0)
						//loc_23404170
						for (uint32_t langIdx = 0; langIdx < 50; langIdx++)
						{
							//loc_23404174
							if (r5->arAudioPids[langIdx] == 0)
							{
								//0x23404184
								r5->arAudioPids[langIdx] = r4->elementary_PID;
								r5->arAudioComponentTags[langIdx] = r4->component_tag;
								r5->Data_0x198[langIdx] = 0; //fp

								if (0 != strlen(r4->language))
								{
									//loc_234041b0
									//langIdx, r4, #0xa
									//->loc_23404104
									r5->arAudioLanguageStrings[langIdx] = &r4->language[0];
									//->loc_23404394
								}
								//loc_2340421c
								else if (0 != strlen(&r4->language[4]))
								{
									r5->arAudioLanguage2Strings[langIdx] = &r4->language[4];
									//->loc_23404394
								}
								else
								{
									//loc_23404234
									//ldr        langIdx, =aDefault
									//loc_23404104
									r5->arAudioLanguageStrings[langIdx] = "default";
								}
								//->loc_23404394
								break;
							}
							//loc_2340423c
						} //for (uint32_t langIdx = 0; langIdx < 50; langIdx++)
						//->loc_23404394
						break;

					case 27: //AVC video stream as defined in ITU-T Rec. H.264 | ISO/IEC 14496-10 Video
						//0x2340402c
						//TODO!!!
						break;

					case 0x80:
						//0x23404090
						//TODO!!!
						break;

					case 0x81:
						//0x234040a4
						//TODO!!!
						break;

					} //switch (r4->stream_type)
#endif
					//loc_23404394
					r4 = r4->next;
				} //while (r4 != 0)
				//loc_234043a0
			} //if (sp4->program_number == r5->program_number)
			//loc_234043a0
			r5++;
		} //while ((r5->bData_0 & 0x80) != 0)
		//loc_234043b0
	}
	//loc_234043b0
	return;
}


/* 234043b4 - todo */
void psi_change_activity(Struct_234a73e8* r5, int mask, int c)
{
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "psi_change_activity: mask=0x%x, c=0x%x\r\n", mask, c);
		console_send_string(debug_string);
	}
#endif
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "psi_change_activity: r5->bData_0x244=%d, r5->Data_0x21e04=0x%x, r5->Data_0x21dfc=0x%x\r\n",
				r5->bData_0x244, r5->Data_0x21e04, r5->Data_0x21dfc);
		console_send_string(debug_string);
	}
#endif

	if ((r5->bData_0x244 == 0) || ((r5->Data_0x21e04 & mask) == 0))
	{
		r5->Data_0x21e04 |= mask;

		if (c == 0)
		{
			r5->Data_0x21e08 &= ~mask;
		}
		else
		{
			//0x234043ec
			if (mask & 1)
			{
				r5->Data_0x21e08 |= 1;
			}

			if (mask & 2)
			{
				r5->Data_0x21e08 |= 2;
			}

			if (mask & 0x40)
			{
				r5->Data_0x21e08 |= 0x40;
			}

			if (mask & 0x08)
			{
				r5->Data_0x21e08 |= 0x08;
			}

			if (mask & 0x80)
			{
				r5->Data_0x21e08 |= 0x80;
			}

			if (mask & 0x100)
			{
				r5->Data_0x21e08 |= 0x100;
			}

			if (mask & 0x200)
			{
				r5->Data_0x21e08 |= 0x200;
			}

			if (mask & 4)
			{
				r5->Data_0x21e08 |= 4;
			}
		}
		//loc_23404470
		if ( (((r5->Data_0x21dfc & ~r5->Data_0x21e04) == 0) && ((r5->Data_0x21dfc & mask) != 0)) ||
				((mask & 1) && (c != 0)))
		{
			//loc_23404494
			if (r5->pfOnPSIData != 0)
			{
				sub_23403ab4(0x08, r5);

				(r5->pfOnPSIData)(r5);
			}
			//loc_234044b8
			r5->Data_0x21e00 = 0;
		}
	}
}


/* 23404d4c / 234071c0 - todo */
int psi_handle_queue_item(Struct_234a73e8* r5, Queue_Item* pItem/*r6*/)
{
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "psi_handle_queue_item: pItem->Data_0=%d\r\n", pItem->Data_0);
		console_send_string(debug_string);
	}
#endif

	//r8, #0x0
	//sb, #0x1
	//r4, r5, #0x21000
	// r7 = r5 + 21E00

	if (pItem->state == PSI_STATE_START)
	{
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "psi_handle_queue_item: r5->activeMask=0x%x\r\n", r5->activeMask);
		console_send_string(debug_string);
	}
#endif

		//0x23404d78
		if (r5->activeMask == 0)
		{
			//0x23404d84
			r5->pfOnPSIData = pItem->pData->pfOnPSIData;
			r5->Data_0x228 = pItem->pData->Data_0x10;

			r5->wData_0x21e10 = 0; //r8
			r5->Data_0x21dfc = pItem->pData->activeMask;
			r5->activeMask = pItem->pData->activeMask | pItem->pData->Data_8;
			r5->Data_0x21e04 = 0; //r8
			r5->Data_0x21e08 = 0; //r8
			r5->wData_0x21e14 = pItem->pData->wData_0x14;

			r5->bData_0x21e7c = sub_2344e65c(0, r5->wData_0x21e14, 1);

			r5->wData_0x21e18 = pItem->pData->wData_0x16;
			r5->wData_0x21e1a = pItem->pData->wData_0x18;

#if 1
			if (r5->wData_0x21e14 != 0)
			{
				r5->bData_0x244 = 0; //r8
			}
			else
			{
				r5->bData_0x244 = 1; //sb;
			}
#else
			r5->bData_0x244 = (r5->wData_0x21e14 != 0)? 0: 1;
#endif

			if (r5->activeMask & 0x300)
			{
				memcpy(r5->Data_0x21e28, ((int*)&pItem->pData->wData_0x18) + 1, 12);
			}

			sub_23406a74(r5);

			sub_23403948(r5);

			timer_user_control(r5->hTimer, 1);
		} //if (r5->activeMask == 0)
		//loc_23404e4c: Ack
		pItem->pData->handled = 1; //sb
		//->loc_23405080
	} //if (pItem->state == PSI_STATE_START)
	//loc_23404e58
	else if (pItem->state == PSI_STATE_STOP) 
	{
		//0x23404e60
		r5->pfOnPSIData = 0; //r8;
		r5->Data_0x228 = 0; //r8;

		sub_23403734(r5);

		timer_user_control(r5->hTimer, 0);

		sub_23422460(r5->index >> 1);

		if (pItem->pData->wData_0x14 != 0)
		{
			if (0 == sub_23458874())
			{
				sub_234224a0(r5->index);
			}
		}
		//loc_23404ea8
		sub_23400518(r5->index & 0xff);
		//->loc_23404e4c: Ack
		pItem->pData->handled = 1; //sb
		//->loc_23405080
	} //else if (pItem->state == PSI_STATE_STOP)
	//loc_23404eb8
	else if (pItem->state == 3)
	{
		//0x23404ec0: Section Data received
		r5->Data_0x240 = (Struct_236e5834*) pItem;

		uint32_t table_id = r5->Data_0x240->table_id;

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "psi_handle_queue_item: table_id=0x%x\r\n", table_id);
			console_send_string(debug_string);
		}
#endif

		if (table_id == 0x1)
		{
			r5->/*bData_0x21e70*/Data_0x21e6a[1].bData_2 = 2;
			//->loc_23405080
		}
		else if (table_id == 0x02)
		{
			r5->bPMT_State = 2;
		}
		//loc_23404ee8
		else if ((table_id == 0x08) || (table_id == 0x80))
		{
			r5->bSDT_BAT_State = 2;
		}
		else if (table_id == 0x40)
		{
			r5->bNIT_State = 2;
		}
		else if (table_id == 0x20)
		{
			r5->bEIT_State = 2;
		}
		else if (table_id == 0x10)
		{
			r5->bData_0x21e78 = 2;
		}
		else if (table_id == 0x100)
		{
			r5->bData_0x21e79 = 2;
		}
		else if (table_id == 0x04)
		{
			r5->bData_0x21e75 = 2;
		}
		else if (table_id == 0x400)
		{
			r5->Data_0x21e6a[0].bData_0 = 2;
		}
		else if (table_id == 0x800)
		{
			r5->Data_0x21e6a[1].bData_0 = 2;
		}
		else if (table_id == 0x1000)
		{
			//loc_23404ee0
			r5->bPMT_State = 2;
		}
		else if (table_id == 0x2000)
		{
			r5->Data_0x21e62[0].bData_0 = 2;
		}
		//->loc_23405080
	}
	//loc_23404f60
	else if (pItem->state == 5)
	{
		//0x23404f68
		int r0 = (int) pItem->pData;
		if (r0 == 0x01)
		{
			psi_change_activity(r5, 0x01, 1);
			//->loc_23405080
		}
		else if (r0 == 0x08)
		{
			psi_change_activity(r5, 0x08, 1);
			//->loc_23405080
		}
		else if (r0 == 0x80)
		{
			psi_change_activity(r5, 0x80, 1);
			//->loc_23405080
		}
		else if (r0 == 0x02)
		{
			//0x23404fa4
			if (r5->bData_0x244 == 0)
			{
				//r2 = 1;
				//->loc_23405014
				psi_change_activity(r5, 0x02, 1);
				//->loc_23405080
			}
			else
			{
				//0x23404fb4
				tsd_deactivate_pid_channel(r5->Data_8.tsdPMT);

				if (r5->wData_0x21e10-- != 0)
				{
					//0x23404fd4
					if (r5->Data_0x228 != 0)
					{
						(r5->Data_0x228)(r5->wData_0x21e10, r5->wData_0x21e12);
					}

					PAT_Program* r0 = pat_get_program(r5->index & 0xff, r5->wData_0x21e10 & 0xff);

#if 0
					{
						extern char debug_string[];
						sprintf(debug_string, "psi_handle_state: Starting PMT filter for PID=0x%x, r5->wData_0x21e10=%d\r\n",
								r0->pmt_pid, r5->wData_0x21e10);
						console_send_string(debug_string);
					}
#endif

					r5->wPMT_PID = r0->pmt_pid;
					r5->wData_0x21e14 = r0->program_number;

					r5->bPMT_State = 1; //sb
					//->loc_23405080
				} //if (r5->wData_0x21e10-- != 0)
				else
				{
					//loc_23405010
					psi_change_activity(r5, 0x02, 0);
					//->loc_23405080
				}
			}
		}
		//loc_23405024
		else if (r0 == 0x40)
		{
			psi_change_activity(r5, 0x40, 1);

			r5->bNIT_State = 0; //r8
			//->loc_23405080
		}
		//loc_23405044
		else if (r0 == 0x100)
		{
			psi_change_activity(r5, 0x100, 1);

			r5->bData_0x21e79 = 0; //r8
			//->loc_23405080
		}
		else if (r0 == 0x04)
		{
			psi_change_activity(r5, 0x04, 1);

			r5->bData_0x21e75 = 0; //r8
			//->loc_23405080
		}
		//loc_23405080
	} //else if (pItem->state == 5)
	//loc_23405080
	return 0;
}


/* 23405088 / 234074fc - todo */
int psi_handle_state(Struct_234a73e8* r4)
{
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "psi_handle_state: r5->activeMask=0x%x\r\n", r4->activeMask);
		console_send_string(debug_string);
	}
#endif

	Struct_23421780 sp_0x24;

	//r5, r0, #0x21000
	//r8, #0x0
	//sb, #0x1

	if (r4->activeMask & PSI_MASK_PAT)
	{
#if 1 //Program Association Table
		if (r4->/*bData_0x21e70*/Data_0x21e6a[1].bData_2 == 2)
		{
			//0x234050b8
			r4->/*bData_0x21e70*/Data_0x21e6a[1].bData_2 = 0; //r8

			int r7 = r4->Data_0x240->Data_0xc;

			sub_23421ce8(r4->Data_8.tsdPAT, r4->Data_0x240);

#if 0
			struct
			{
				int fill_0[4]; //0
				uint16_t wData_0x10; //16 = 0x10
				uint16_t wData_0x12; //18 = 0x12
				uint16_t wData_0x14; //20 = 0x14
				uint16_t wPMT_PID; //22 = 0x16
				int fill_0x18; //24 = 0x18
				uint16_t wData_0x1c; //28 = 0x1c

			}* r6 = (void*) &r4->Data_0x21e00;
#endif
			uint8_t* sl = (void*) &r4->Data_0x240->Data_0x10;
			uint8_t fp = sl[11];
			//->loc_23405188
			while (r7 > 0)
			{
				//loc_234050e4
				sl += 4;
				r7 -= 4;

				psi_register_version_number(r4, 0x01, (sl[5] >> 1) & 0x1f);

				uint16_t r0 = pat_decode_section(r4->index & 0xff, sl, 1);

				if (r0 & 0x03)
				{
					r0 += (4 - (r0 & 0x03));
				}

				sl += r0;
				r7 -= r0;

				if (r4->/*bData_0x21e71*/Data_0x21e6a[1].bData_3 < fp)
				{
					r4->/*bData_0x21e71*/Data_0x21e6a[1].bData_3++;

					/*r6->wData_0x1c*/r4->wData_0x21e1c = 6;
					//->loc_23405188
				}
				else
				{
					//0x23405154
					psi_change_activity(r4, 0x01, 0);

					/*r6->wData_0x12 = r6->wData_0x10 = */
					r4->wData_0x21e12 = r4->wData_0x21e10 = pat_get_num_programs(r4->index & 0xff);

					sub_23403ab4(0x01, r4);

					/*r6->wData_0x1c*/r4->wData_0x21e1c = 0; //r8
				}
				//loc_23405188
			} //while (r7 > 0)
			//0x23405190
			sub_23406ac8(r4->Data_0x240);

#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "psi_handle_state: r4->bData_0x244=%d\r\n",
						r4->bData_0x244);
				console_send_string(debug_string);
			}
#endif

			if (r4->bData_0x244 != 0)
			{
				//0x234051a8
				/*r6->wData_0x10*/r4->wData_0x21e10--;

				if (r4->Data_0x228 != 0)
				{
					(r4->Data_0x228)(/*r6->wData_0x10*/r4->wData_0x21e10, /*r6->wData_0x12*/r4->wData_0x21e12);
				}

				PAT_Program* r0 = pat_get_program(r4->index & 0xff, /*r6->wData_0x10*/r4->wData_0x21e10 & 0xff);

				if (r0 == 0)
				{
					/*r6->wPMT_PID*/r4->wPMT_PID = 0; //r8
					/*r6->wData_0x14*/r4->wData_0x21e14 = 0; //r8

					r4->bPMT_State = 0; //r8
					//->loc_234052e0
					psi_change_activity(r4, 0x02, 1);
					//loc_234052f0
				}
				else
				{
					//0x234051f0
#if 1
					{
						extern char debug_string[];
						sprintf(debug_string, "psi_handle_state: Starting PMT filter for PID=0x%x, r4->wData_0x21e10=%d\r\n",
								r0->pmt_pid, /*r6->wData_0x10*/r4->wData_0x21e10);
						console_send_string(debug_string);
					}
#endif

					/*r6->wPMT_PID*/r4->wPMT_PID = r0->pmt_pid;
					/*r6->wData_0x14*/r4->wData_0x21e14 = r0->program_number;

					r4->bPMT_State = 1; //sb
					//->loc_234052f0
				}
			} //if (r4->bData_0x244 != 0)
			else
			{
				uint16_t r7 = 0;
				//loc_23405270
				while (r7 < /*r6->wData_0x10*/r4->wData_0x21e10)
				{
					//loc_23405238
					PAT_Program* r0 = pat_get_program(r4->index & 0xff, r7 & 0xff);

					if (r0->program_number != /*r6->wData_0x14*/r4->wData_0x21e14)
					{
						r7++;
						//loc_23405270
					}
					else
					{
						//0x23405260
#if 0
						{
							extern char debug_string[];
							sprintf(debug_string, "psi_handle_state: Starting PMT filter for PID=0x%x, r7=%d\r\n",
									r0->pmt_pid, r7);
							console_send_string(debug_string);
						}
#endif
						r4->bPMT_State = 1; //sb

						/*r6->wPMT_PID*/r4->wPMT_PID = r0->pmt_pid;
						//loc_234052f0
						break;
					}
				} //while (r7 < r6->wData_0x10)
				//0x2340527c
				if (r4->bPMT_State == 0)
				{
					//0x23405288
					if ((/*r6->wData_0x14*/r4->wData_0x21e14 == 1) && (/*r6->wData_0x10*/r4->wData_0x21e10 != 0))
					{
						//0x234052a0
						int r7 = r4->activeMask;

						PAT_Program* r0 = pat_get_program(r4->index & 0xff, 0);

						/*r6->wData_0x14*/r4->wData_0x21e14 = r0->program_number;

						sub_23403734(r4);

						r4->activeMask = r7;
						r4->Data_0x21e04 = 0; //r8

						sub_23403948(r4);
						//->loc_234052f0
					}
					else
					{
						//loc_234052d8
						sub_23406a74(r4);
						//loc_234052e0
						psi_change_activity(r4, 0x02, 1);
						//loc_234052f0
					}
				}
				//loc_234052f0
			}
		}
		//loc_234052f0
		if (r4->/*bData_0x21e70*/Data_0x21e6a[1].bData_2 == 1)
		{
			//0x234052fc
			r4->/*bData_0x21e70*/Data_0x21e6a[1].bData_2 = 0; //r8
			r4->wData_0x21e1c = 6;  //timeout?

			psi_register_version_number(r4, 0x01, 0xff);
			sub_234216fc(r4->Data_8.tsdPAT);
			tsd_activate_pid_channel(r4->Data_8.tsdPAT);
		}
#endif
		//loc_2340532c
	} //if (r4->activeMask & PSI_MASK_PAT)
	//loc_2340532c
	if (r4->activeMask & PSI_MASK_PMT)
	{
		//0x23405338
#if 1 //Program Map Table
		if (r4->bPMT_State == 2)
		{
			//0x23405344
			r4->bPMT_State = 0; //r8

			int r7 = r4->Data_0x240->Data_0xc;

			sub_23421ce8(r4->Data_8.tsdPMT, r4->Data_0x240);

			uint8_t* r0 = (void*) &r4->Data_0x240->Data_0x10;

			uint8_t fp = r0[11]; //last_section number
			//->loc_234053f8
			while (r7 > 0)
			{
				//loc_23405368
				uint8_t* sl = r0 + 4;
				r7 -= 4;

				psi_register_version_number(r4, 0x02, ((sl[5] >> 1) & 0x1f)/*version_number*/);

				uint16_t r6 = pmt_decode_section(r4->index & 0xff, sl);

#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "psi_handle_state: r4->bData_0x244=%d, r4->bData_0x21e73=%d, fp=%d\r\n",
							r4->bData_0x244, r4->bData_0x21e73, fp);
					console_send_string(debug_string);
				}
#endif

				if (r4->bData_0x244 == 0)
				{
					//0x234053a8
					if (r4->pfOnPMTData)
					{
						(r4->pfOnPMTData)(sl, r6);
					}
				}
				//loc_234053bc
				if (r6 & 0x03)
				{
					r6 += (4 - r6 & 0x03);
				}

				r0 = sl + r6;
				r7 -= r6;

				if (r4->bData_0x21e73 < fp)
				{
					//0x234053e4
					r4->bData_0x21e73++;

					r4->wData_0x21e1e = 2;
					//->loc_234053f8
				}
				else
				{
					//loc_234054e4
					sub_23403ab4(0x02, r4);

#if 0
					struct
					{
						int fill_0[4]; //0
						uint16_t wData_0x10; //16 = 0x10
						uint16_t wData_0x12; //18 = 0x12
						uint16_t wData_0x14; //20 = 0x14
						uint16_t wPMT_PID; //22 = 0x16
						int fill_0x18; //24 = 0x18
						uint16_t wData_0x1c; //28 = 0x1c
						uint16_t wData_0x1e; //30 = 0x1e

					}* r6 = (void*) &r4->Data_0x21e00;
#endif

					/*r6->wData_0x1e*/r4->wData_0x21e1e = 0; //r8

					if (r4->bData_0x244 != 0)
					{
						//0x23405508
						tsd_deactivate_pid_channel(r4->Data_8.tsdPMT);

						if (/*r6->wData_0x10*/r4->wData_0x21e10--)
						{
							//0x23405528
							if (r4->Data_0x228 != 0)
							{
								(r4->Data_0x228)(/*r6->wData_0x10*/r4->wData_0x21e10, /*r6->wData_0x12*/r4->wData_0x21e12);
							}

							PAT_Program* r0 = pat_get_program(r4->index & 0xff, /*r6->wData_0x10*/r4->wData_0x21e10 & 0xff);

#ifdef PSI_PMT_FILTER_DEBUG
							{
								extern char debug_string[];
								sprintf(debug_string, "psi_handle_state: Continue PMT filter for PID=0x%x, r4->wData_0x21e10=%d\r\n",
										r0->pmt_pid, /*r6->wData_0x10*/r4->wData_0x21e10);
								console_send_string(debug_string);
							}
#endif

							/*r6->wPMT_PID*/r4->wPMT_PID = r0->pmt_pid;
							/*r6->wData_0x14*/r4->wData_0x21e14 = r0->program_number;

							r4->bPMT_State = 1; //sb
							//->loc_23405400
						}
						else
						{
							//loc_23405564
							psi_change_activity(r4, 0x02, 0);
							//->loc_23405400
						}
					} //if (r4->bData_0x244 != 0)
					else
					{
						//loc_23405578
						psi_change_activity(r4, 0x02, 0);

						int sp_0x20;
						int sp_0x1c;

						int r7 = sub_2344c7cc(r4->index & 0xff);
#if 0 //TODO!!!
						if (r7 & 0x03)
						{
							//0x234055a0
							sub_2344c82c(r4->Data_0 & 0xff, r7 & ~0x04, &sp_0x20, &sp_0x1c);

							Data_234a73d0.wData_0x14 = /*r6->wData_0x14*/r4->wData_0x21e14;

							if ((0 == sub_23418bf0()) || (r4->Data_0 != 0))
							{
								//loc_234055dc
								sub_2340051c(sp_0x1c, sp_0x20, r7, &Data_234a73d0);
							}
							//loc_234055f0
						}
						//loc_234055f0
						if (r7 & 0x04)
						{
							//0x234055f8
							sub_2344c82c(r4->Data_0 & 0xff, 0x04, &sp_0x20, &sp_0x1c);

							for (uint16_t r6 = 0; r6 < sp_0x1c; r6++)
							{
								//loc_2340561c
								if (r6 >= 2)
								{
									//->loc_23405400
									break;
								}
								//0x23405624
								if (r4->Data_0x238 != 0)
								{
									memcpy(&r4->Data_0x21e40[r6], sp_0x20 + r6 * 16, 16);

									r4->Data_0x21e6a[r6].bData_0 = 1; //sb

#if 0
									*(&r4->bData_0x13d + r6 * 28) = r7; //TODO!!!
#endif
								}
								//loc_23405664
							}
							//0x23405678 -> loc_23405400
						}
						//loc_23405400
#endif
					}
					//->loc_23405400
					break;
				}
			} //while (r7 > 0)
			//loc_23405400
			sub_23406ac8(r4->Data_0x240);
		} //if (r4->bPMT_State == 2)
		//loc_23405408
		if (r4->bPMT_State == 1)
		{
			//0x23405414
			r4->Data_8.Data_0x38.bData_0 = 0x02; //r7 //program_map_section
			r4->Data_8.Data_0x38.bData_1 = 0xff;
			r4->Data_8.Data_0x38.bData_2 = (r4->wData_0x21e14 >> 8) & 0xff;
			r4->Data_8.Data_0x38.bData_3 = 0xff;
			r4->Data_8.Data_0x38.bData_4 = (r4->wData_0x21e14 >> 0) & 0xff;
			r4->Data_8.Data_0x38.bData_5 = 0xff;

			r4->bPMT_State = 0; //r8

			psi_register_version_number(r4, 0x02, 0xff);

			r4->wData_0x21e1e = 2; //r7, timeout?

			sp_0x24.bData_0 = 1; // sb;
			sp_0x24.wData_2 = 2; //r7
			sp_0x24.Data_4 = &r4->Data_8.Data_0x38;
			sp_0x24.bData_8 = 1; // sb;

			tsd_set_section_filter(r4->Data_8.tsdPMT, r4->wPMT_PID, &sp_0x24);

			sub_234216fc(r4->Data_8.tsdPMT);

			tsd_activate_pid_channel(r4->Data_8.tsdPMT);

		} //if (r4->bPMT_State == 1)
#endif
		//loc_23405490
	} //if (r4->activeMask & PSI_MASK_PMT)
	//loc_23405490
	//fp, =0x23487e14 = psi_arLastSectionNumberMask
	if (r4->activeMask & 0x88)
	{
#if 1 //Service Description Table / Bouquet Association Table
		//0x234054a0
		if (r4->bSDT_BAT_State == 2)
		{
			//0x234054ac
			r4->bSDT_BAT_State = 0; //r8
			r4->wSDT_BAT_Timeout = 0; //r8

			int r7 = r4->Data_0x240->Data_0xc;

			sub_23421ce8(r4->Data_8.tsdSDT_BAT, r4->Data_0x240);

			uint8_t* r0 = (void*) &r4->Data_0x240->Data_0x10;

			if ((r0[4] == 0x42/*service_description_section - actual_transport_stream*/)
					|| (r0[4] == 0x46)) //service_description_section - other_transport_stream
			{
				//loc_23405760
				while (r7 > 0)
				{
					//loc_2340567c
					int r7_;
					uint8_t lastSectionNumber = r0[11];
					uint8_t* r6 = r0 + 4;
					int sl = r7 - 4;
					r7_ = (r6[1] << 8);
					r7_ |= r6[2];
					r7_ &= ~0xf000;
					r7_ += 3;

					if (r4->bData_0x21e83 == 0)
					{
						r4->bData_0x21e83 = psi_arLastSectionNumberMask/*fp*/[lastSectionNumber + 1];
					}

					int sectionNumberBit = psi_arSectionNumberBits[ r6[6]/*section_number*/ ];
					if ((r4->bData_0x21e82 & sectionNumberBit) == 0)
					{
						//0x234056c8
						r4->bData_0x21e82 |= sectionNumberBit;

						sdt_decode_section(r4->index & 0xff, r6, r4->bData_0x21e8c);

						r4->bData_0x21e8c = 0; //r8
					}
					//loc_234056e8
					if (r4->bData_0x21e82 == r4->bData_0x21e83)
					{
						//0x234056f8
						if (r4->pfOnSDTData != 0)
						{
							(r4->pfOnSDTData)(r6, r7_);
						}

						psi_change_activity(r4, 0x08, 0);
						psi_register_version_number(r4, 0x08, ((r6[5] >> 1) & 0x1f)/*version_number*/);
						//->loc_23405744
					}
					else
					{
						//loc_23405738
						tsd_deactivate_pid_channel(r4->Data_8.tsdSDT_BAT);

						r4->bSDT_BAT_State = 1; //sb
					}
					//loc_23405744
					if (r7_ & 0x03)
					{
						r7_ += (4 - (r7_ & 0x03));
						r7_ &= 0xffff;
					}

					r0 = r6 + r7_;
					r7 = sl - r7_;
				} //while (r7 > 0)
				//0x23405768
				if (r4->bSDT_BAT_State != 0)
				{
					r4->bData_0x21e84++;
				}
				//->loc_23405864
			}
			//loc_23405780
			else if (r0[4] == 0x4a) //bouquet_association_section
			{
				//loc_23405848
				while (r7 > 0)
				{
					//loc_2340578c
					int r6;
					uint8_t* sl = r0 + 4;
					uint8_t lastSectionNumber = sl[7];
					r7 = r7 - 4;
					r6 = (sl[1] << 8);
					r6 |= sl[2];
					r6 &= ~0xf000;
					r6 += 3;

					if (r4->bData_0x21e89 == 0)
					{
						r4->bData_0x21e89 = psi_arLastSectionNumberMask/*fp*/[lastSectionNumber+ 1];
					}

					int sectionNumberBit = psi_arSectionNumberBits[ sl[6]/*section_number*/ ];
					if ((r4->bData_0x21e85 & sectionNumberBit) == 0)
					{
						//0x234057d8
						r4->bData_0x21e85 |= sectionNumberBit;

						nit_decode_section(r4->index & 0xff, sl, r4->bData_0x21e8d);

						r4->bData_0x21e8d = 0; //r8
					}
					//loc_234057f8
					if (r4->bData_0x21e85 == r4->bData_0x21e89)
					{
						tsd_deactivate_pid_channel(r4->Data_8.tsdSDT_BAT);

						psi_change_activity(r4, 0x80, 0);
						//->loc_2340582c
					}
					else
					{
						//loc_23405824
						tsd_deactivate_pid_channel(r4->Data_8.tsdSDT_BAT);

						r4->bSDT_BAT_State = 1; //sb
					}
					//loc_2340582c
					if (r6 & 0x03)
					{
						r6 += (4 - (r6 & 0x03));
						r6 &= 0xffff;
					}

					r0 = sl + r6;
					r7 = r7 - r6;
				} //while (r7 > 0)
				//0x23405850
				if (r4->bSDT_BAT_State != 0)
				{
					r4->bData_0x21e8a++;
				}
				//loc_23405864
			} //else if (r0[4] == 0x4a) //bouquet_association_section
			//loc_23405864
			sub_23406ac8(r4->Data_0x240);
		}
		//loc_2340586c
		if (r4->bSDT_BAT_State == 1)
		{
			//0x23405878
			if ((r4->activeMask & 0x80) == 0)
			{
				//0x23405884
				if (r4->wData_0x21e18 != 0)
				{
					//0x23405894
					r4->Data_8.Data_0x54.bData_0 = 0x46;
					r4->Data_8.Data_0x54.bData_1 = 0xff;
					r4->Data_8.Data_0x54.bData_2 = (r4->wData_0x21e18 >> 8) & 0xff;
					r4->Data_8.Data_0x54.bData_3 = 0xff;
					r4->Data_8.Data_0x54.bData_4 = (r4->wData_0x21e18 >> 0) & 0xff;
					r4->Data_8.Data_0x54.bData_5 = 0xff;
					//->loc_234058dc
				}
				else
				{
					//loc_234058bc
					r4->Data_8.Data_0x54.bData_0 = 0x42;
					r4->Data_8.Data_0x54.bData_1 = 0xff;
					r4->Data_8.Data_0x54.bData_2 = 0x00;
					r4->Data_8.Data_0x54.bData_3 = 0x00;
					r4->Data_8.Data_0x54.bData_4 = 0x00;
					r4->Data_8.Data_0x54.bData_5 = 0x00;
				}
				//loc_234058dc
				r4->Data_8.Data_0x54.bData_6 = 0x00;
				r4->Data_8.Data_0x54.bData_7 = 0x00;
				r4->Data_8.Data_0x54.bData_8 = r4->bData_0x21e84;
				r4->Data_8.Data_0x54.bData_9 = 0xff;
				//->loc_23405938
			}
			else
			{
				//loc_234058f8
				r4->Data_8.Data_0x54.bData_0 = 0x4a;
				r4->Data_8.Data_0x54.bData_1 = 0xff;
				r4->Data_8.Data_0x54.bData_2 = (r4->wData_0x21e18 >> 8) & 0xff;
				r4->Data_8.Data_0x54.bData_3 = 0xff;
				r4->Data_8.Data_0x54.bData_4 = (r4->wData_0x21e18 >> 0) & 0xff;
				r4->Data_8.Data_0x54.bData_5 = 0xff;
				r4->Data_8.Data_0x54.bData_6 = 0x00;
				r4->Data_8.Data_0x54.bData_7 = 0x00;
				r4->Data_8.Data_0x54.bData_8 = r4->bData_0x21e8a;
				r4->Data_8.Data_0x54.bData_9 = 0xff;
			}
			//loc_23405938
			r4->bSDT_BAT_State = 0;
			r4->wSDT_BAT_Timeout = 30; //timeout?

			psi_register_version_number(r4, 0x08, 0xff);

			sp_0x24.bData_0 = 1; // sb;
			sp_0x24.wData_2 = 4;
			sp_0x24.Data_4 = &r4->Data_8.Data_0x54;
			sp_0x24.bData_8 = 1; // sb;

			sub_234216fc(r4->Data_8.tsdSDT_BAT);

			tsd_set_section_filter(r4->Data_8.tsdSDT_BAT, 0x11, &sp_0x24);

			tsd_activate_pid_channel(r4->Data_8.tsdSDT_BAT);
			//loc_23405990
		} //if (r4->bSDT_BAT_State == 1)
		//loc_23405990
#endif
	} //if (r4->activeMask & 0x88)
	//loc_23405990
	if (r4->activeMask & PSI_MASK_NIT)
	{
#if 1 //Network Information Table (NIT)
		//0x2340599c
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "psi_handle_state: r4->bNIT_State=%d, r4->wData_0x21e1a=0x%x\r\n",
					r4->bNIT_State, r4->wData_0x21e1a);
			console_send_string(debug_string);
		}
#endif

		if (r4->bNIT_State == 2)
		{
			//0x234059a8
			//sp_0x38 = 0x21e00
			r4->bNIT_State = 0; //r8;
			r4->wNIT_Timeout = 30;
			int r7 = r4->Data_0x240->Data_0xc;

			sub_23421ce8(r4->Data_8.tsdNIT, r4->Data_0x240);

			uint8_t* r0 = (void*) &r4->Data_0x240->Data_0x10;
			//->loc_23405aa4
			while (r7 > 0)
			{
				//loc_234059dc
				int r7_;
				uint8_t lastSectionNumber = r0[11]; //last_section_number
				uint8_t* r6 = r0 + 4;
				int sl = r7 - 4;
				r7_ = (r6[1] << 8);
				r7_ |= r6[2];
				r7_ &= ~0xf000;
				r7_ += 3;

				if (r4->bNIT_SectionNumberMask == 0)
				{
					r4->bNIT_SectionNumberMask = psi_arLastSectionNumberMask/*fp*/[lastSectionNumber + 1];
				}

				int sectionNumberBit = psi_arSectionNumberBits[ r6[6]/*section_number*/ ];
				if ((r4->bNIT_SectionNumberBits & sectionNumberBit) == 0)
				{
					//0x23405a28
					r4->bNIT_SectionNumberBits |= sectionNumberBit;

					nit_decode_section(r4->index & 0xff, r6, r4->bData_0x21e8b);

					r4->bData_0x21e8b = 0; //r8
				}
				//loc_23405a48
				if (r4->bNIT_SectionNumberBits == r4->bNIT_SectionNumberMask)
				{
					//0x23405a58
					r4->wNIT_Timeout = 0; //r8

					psi_register_version_number(r4, 0x40, ((r6[5] >> 1) & 0x1f)/*version_number*/);
					psi_change_activity(r4, 0x40, 0);
				}
				//loc_23405a88
				if (r7_ & 0x03)
				{
					r7_ += (4 - (r7_ & 0x03));
					r7_ &= 0xffff;
				}

				r0 = r6 + r7_;
				r7 = sl - r7_;
			} //while (r7 > 0)
			//0x23405aac
			sub_23406ac8(r4->Data_0x240);
			//loc_23405ab4
		}
		//loc_23405ab4
		if (r4->bNIT_State == 1)
		{
			//0x23405ac0
			if (r4->wData_0x21e1a != 0)
			{
				//0x23405ad4
				r4->Data_8.NIT_Bytes.bData_0 = 0x41;
				r4->Data_8.NIT_Bytes.bData_1 = 0xff;
				r4->Data_8.NIT_Bytes.bData_2 = (r4->wData_0x21e1a >> 8) & 0xff;
				r4->Data_8.NIT_Bytes.bData_3 = 0xff;
				r4->Data_8.NIT_Bytes.bData_4 = (r4->wData_0x21e1a >> 0) & 0xff;
				r4->Data_8.NIT_Bytes.bData_5 = 0xff;
				//->loc_23405b1c
			}
			else
			{
				//loc_23405afc
				r4->Data_8.NIT_Bytes.bData_0 = 0x40;
				r4->Data_8.NIT_Bytes.bData_1 = 0xff;
				r4->Data_8.NIT_Bytes.bData_2 = 0; //r8
				r4->Data_8.NIT_Bytes.bData_3 = 0; //r8
				r4->Data_8.NIT_Bytes.bData_4 = 0; //r8
				r4->Data_8.NIT_Bytes.bData_5 = 0; //r8
			}
			//loc_23405b1c
			r4->bNIT_State = 0; //r8
			r4->wNIT_Timeout = 30;

			sp_0x24.bData_0 = 1; // sb;
			sp_0x24.wData_2 = 2;
			sp_0x24.Data_4 = &r4->Data_8.NIT_Bytes;
			sp_0x24.bData_8 = 1; // sb;

			psi_register_version_number(r4, 0x40, 0xff);

			sub_234216fc(r4->Data_8.tsdNIT);

			tsd_set_section_filter(r4->Data_8.tsdNIT, 0x10/*pid*/, &sp_0x24);

			tsd_activate_pid_channel(r4->Data_8.tsdNIT);
			//loc_23405b70
		}
		//loc_23405b70
#endif
	} //if (r4->activeMask & PSI_MASK_NIT)
	//loc_23405b70
	if (r4->activeMask & PSI_MASK_EIT)
	{
#if 1 //Event Information Table
		//0x23405b7c
		if (r4->bEIT_State == 2)
		{
			//0x23405b88
			r4->bEIT_State = 0; //r8

			sub_23421ce8(r4->Data_8.tsdEIT, r4->Data_0x240);

			uint8_t* r6 = ((uint8_t*) &r4->Data_0x240->Data_0x10) + 4;

			if (r4->Data_0x240->Data_0x10.Data_0 == 0x2000000)
			{
				//0x23405bac
				uint8_t r0 = 0xff & sub_2344e65c(r6, r4->wData_0x21e14, 0);

				if (r4->bData_0x21e7c != r0)
				{
					r4->bData_0x21e7c = r0;
					r4->bEIT_State = 1; //sb

					tsd_deactivate_pid_channel(r4->Data_8.tsdEIT);
				}
			}
			//loc_23405bdc
			decode_eit_section(r6, 0);

			sub_23406ac8(r4->Data_0x240);
		}
		//loc_23405bf0
		if (r4->bEIT_State == 1)
		{
			//0x23405bfc
			r4->bEIT_State = 0; //r8

			r4->Data_8.Data_0xc4.bData_0 = 0x4e; //event_information_section - actual_transport_stream, present/following
			r4->Data_8.Data_0xc4.bData_1 = 0xff;
			r4->Data_8.Data_0xc4.bData_2 = r4->bData_0x21e7c;
			r4->Data_8.Data_0xc4.bData_3 = 0xff;
			r4->Data_8.Data_0xc4.bData_4 = r4->wData_0x21e14 >> 8;
			r4->Data_8.Data_0xc4.bData_5 = 0xff;
			r4->Data_8.Data_0xc4.bData_6 = r4->wData_0x21e14 >> 8;
			r4->Data_8.Data_0xc4.bData_7 = 0xff;
			r4->Data_8.Data_0xc4.bData_8 = r4->wData_0x21e14;
			r4->Data_8.Data_0xc4.bData_9 = 0xff;
			r4->Data_8.Data_0xc4.bData_10 = r4->wData_0x21e14;
			r4->Data_8.Data_0xc4.bData_11 = 0xff;

#if 0
			sp.Data_4->bNumTargetIndex = 2; //sl
			sp.Data_4->wTargetLength = 2; //sl
			sp.Data_4->Data_4 = &r4->Data_0xc4;
			sp.Data_4->bData_8 = 1; //r8
#endif
			sp_0x24.bData_0 = 2;
			sp_0x24.wData_2 = 2;
			sp_0x24.Data_4 = &r4->Data_8.Data_0xc4;
			sp_0x24.bData_8 = 1; //sb

			tsd_set_section_filter(r4->Data_8.tsdEIT, 0x12, &sp_0x24);
			sub_234216fc(r4->Data_8.tsdEIT);
			tsd_activate_pid_channel(r4->Data_8.tsdEIT);
		}
#endif
		//loc_23405c80
	} //if (r4->activeMask & PSI_MASK_EIT)
	//loc_23405c80
	if (r4->activeMask & PSI_MASK_TDT)
	{
		//0x23405c8c
		if (r4->bData_0x21e78 == 2)
		{
			//0x23405c98
			r4->bData_0x21e78 = 0; //r8

			sub_23421ce8(r4->Data_8.tsdTDT, r4->Data_0x240);

			uint8_t* r0 = ((uint8_t*) &r4->Data_0x240->Data_0x10) + 4;
			uint8_t r1 = *r0;

			if (r1 == 0x70)
			{
				sub_2344ed20(r4->Data_0x240, 0);
				//->loc_23405cd0
			}
			else
			{
				//loc_23405cc4
				if (r1 == 0x73)
				{
					sub_2344ed58(r4->Data_0x240, 0);
				}
			}
			//loc_23405cd0
			sub_23406ac8(r4->Data_0x240);
		}
		//loc_23405cd8
		if (r4->bData_0x21e78 == 1)
		{
			//0x23405ce4
			r4->bData_0x21e78 = 0; //r8

			sub_234216fc(r4->Data_8.tsdTDT);

			tsd_activate_pid_channel(r4->Data_8.tsdTDT);
		}
		//loc_23405cf8
	} //if (r4->activeMask & PSI_MASK_TDT)
	//loc_23405cf8
	if (r4->activeMask & 0x100)
	{
		//0x23405d04
		if (r4->bData_0x21e79 == 2)
		{
			//0x23405d10
		}
		//loc_23405e40
		if (r4->bData_0x21e79 == 1)
		{
			//0x23405e4c
		}
		//loc_23405ee8
	} //if (r4->activeMask & 0x100)
	//loc_23405ee8
	if (r4->activeMask & PSI_MASK_CAT)
	{
		//0x23405ef4
#if 0 //Conditional Access Table
		if (r4->bData_0x21e75 == 2)
		{
			//0x23405f00
			r4->bData_0x21e75 = 0; //r8

			sub_23421ce8(r4->Data_8.tsdCAT, r4->Data_0x240);

			//TODO!!!
		}
		//loc_23405f88
		if (r4->bData_0x21e75 == 1)
		{
			//0x23405f94
			r4->bData_0x21e75 = 0; //r8

			psi_register_version_number(r4, 0x04, 0xff);

			tsd_activate_pid_channel(r4->Data_8.tsdCAT);
		}
#endif
		//loc_23405fb0
	} //if (r4->activeMask & PSI_MASK_CAT)
	//loc_23405fb0
	for (uint16_t r6 = 0; r6 < 2; r6++)
	{
		//loc_23405fb4
	}
	//loc_23406100
	//fp, #0x2000
	for (uint16_t r6 = 0; r6 < 2; r6++)
	{
		//loc_23406108
	}
	//loc_234061d8
	return 0;
}


/* 23405754 - todo */
int psi_handle_PAT_section(Struct_236e5834* r4, uint8_t b)
{
#if 0
	console_send_string("psi_handle_PAT_section (todo.c): TODO\r\n");
#endif

//	Struct_234a73e8* r0 = &Data_234a73e8[b];

	if (((r4->Data_0x10.Data_8 >> 9) & 0x1f) != /*r0->*/Data_234a73e8[b].bPAT_VersionNumber)
	{
		r4->table_id = 0x01;
		if (0 == OSQPost(/*r0->*/Data_234a73e8[b].queue, r4))
		{
			return 0;
		}
	}

	r4->Data_0xc = 0;

	return 0;
}


/* 234057b0 - todo */
int psi_handle_PMT_section(Struct_236e5834* r4, uint8_t b)
{
#if 0
	console_send_string("psi_handle_PMT_section (todo.c): TODO\r\n");
#endif

	Struct_234a73e8* r0 = &Data_234a73e8[b];

	if (r0->bPMT_VersionNumber != ((r4->Data_0x10.Data_8 >> 9) & 0x1f))
	{
		r4->table_id = 0x02;
		if (0 == OSQPost(r0->queue, r4))
		{
			return 0;
		}
	}

	r4->Data_0xc = 0;

	return 0;
}


/* 2340580c - todo */
int psi_handle_CAT_section(void* a, uint8_t b)
{
#if 0
	console_send_string("psi_handle_CAT_section (todo.c): TODO\r\n");
#endif

	Struct_236e5834* r4 = a;
	Struct_234a73e8* r0 = &Data_234a73e8[b];

	if (r0->bData_0x21e81 != ((r4->Data_0x10.Data_8 >> 9) & 0x1f))
	{
		r4->table_id = 0x04;
		if (0 == OSQPost(r0->queue, r4))
		{
			return 0;
		}
	}

	r4->Data_0xc = 0;

	return 0;
}


/* 23405868 - todo */
int psi_handle_SDT_BAT_section(Struct_236e5834* r4, uint8_t b)
{
#if 0
	console_send_string("psi_handle_SDT_BAT_section (todo.c): TODO\r\n");
#endif

	Struct_234a73e8* r0 = &Data_234a73e8[b];

	if (r0->activeMask & 0x08)
	{
		if (r0->bSDT_VersionNumber != ((r4->Data_0x10.Data_8 >> 9) & 0x1f))
		{
			r4->table_id = 0x08;
			if (0 == OSQPost(r0->queue, r4))
			{
				return 0;
			}
		}
	}
	else
	{
		//loc_234058ac
		r4->table_id = 0x80;
		if (0 == OSQPost(r0->queue, r4))
		{
			return 0;
		}
	}

	r4->Data_0xc = 0;

	return 0;
}


/*/ 234058d4 - todo */
int psi_handle_NIT_section(Struct_236e5834* r4, uint8_t b)
{
#if 0
	console_send_string("psi_handle_NIT_section (todo.c): TODO\r\n");
#endif

	Struct_234a73e8* r1 = &Data_234a73e8[b];
	int r0 = ((r4->Data_0x10.Data_8 >> 9) & 0x1f);

	if (r0 != r1->bNIT_VersionNumber)
	{
		r4->table_id = 0x40;

		if (0 == OSQPost(r1->queue, r4))
		{
			return 0;
		}
	}
	//loc_23405920
	r4->Data_0xc = 0;

	return 0;
}


/*  / 23405930 - todo */
int psi_handle_EIT_section(Struct_236e5834* r4, uint8_t b)
{
#if 0
	console_send_string("psi_handle_EIT_section (todo.c): TODO\r\n");
#endif

	r4->table_id = 0x20;

	if (0 != OSQPost(Data_234a73e8[b].queue, r4))
	{
		r4->Data_0xc = 0;
	}

	return 0;
}


/* 23405970 - complete */
int psi_handle_TDT_section(void* a, uint8_t b)
{
#if 0
	console_send_string("psi_handle_TDT_section (todo.c): TODO\r\n");
#endif

	Struct_236e5834* r4 = a;

	r4->table_id = 0x10;

	if (0 != OSQPost(Data_234a73e8[b].queue, r4))
	{
		r4->Data_0xc = 0;
	}

	return 0;
}


/* 234059b0 - todo */
void sub_234059b0()
{
	console_send_string("sub_234059b0 (todo.c): TODO\r\n");

}


/* 234059f0 - todo */
void sub_234059f0()
{
	console_send_string("sub_234059f0 (todo.c): TODO\r\n");

}


/* 23405a30 - todo */
void sub_23405a30()
{
	console_send_string("sub_23405a30 (todo.c): TODO\r\n");

}


/* 23405a70 - todo */
void sub_23405a70()
{
	console_send_string("sub_23405a70 (todo.c): TODO\r\n");

}


/* 23405ab0 - todo */
void sub_23405ab0()
{
	console_send_string("sub_23405ab0 (todo.c): TODO\r\n");

}


typedef struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	int fill_4[5]; //4
	/*TSD_Handle*/void* tsdPAT; //24 = 0x18
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1

	} Data_0x1c; //0x1c;
	int fill_0x20[5]; //0x20 = 32
	/*TSD_Handle*/void* tsdCAT; //52 = 0x34
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2
		uint8_t bData_3; //3
		uint8_t bData_4; //4
		uint8_t bData_5; //5
		uint8_t bData_6; //6
		uint8_t bData_7; //7

	} Data_0x38; //0x38
	int fill_0x40[4]; //0x40
	/*TSD_Handle*/void* tsdPMT; //80 = 0x50
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2
		uint8_t bData_3; //3
		uint8_t bData_4; //4
		uint8_t bData_5; //5
		uint8_t bData_6; //6
		uint8_t bData_7; //7
		uint8_t bData_8; //8
		uint8_t bData_9; //9

	} Data_0x54; //0x54
	int fill_0x60[3]; //0x60
	/*TSD_Handle*/void* tsdSDT_BAT; //108 = 0x6c
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2
		uint8_t bData_3; //3
		uint8_t bData_4; //4
		uint8_t bData_5; //5
		uint8_t bData_6; //6
		uint8_t bData_7; //7
		uint8_t bData_8; //8
		uint8_t bData_9; //9
		uint8_t bData_10; //10
		uint8_t bData_11; //11
		uint8_t bData_12; //12
		uint8_t bData_13; //13
		uint8_t bData_14; //14
		uint8_t bData_15; //15
		uint8_t bData_16; //16

	} Data_0x70; //0x70
	int fill_0x84; //0x84
	/*TSD_Handle*/void* Data_0x88; //136 = 0x88
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2
		uint8_t bData_3; //3
		uint8_t bData_4; //4
		uint8_t bData_5; //5
		uint8_t bData_6; //6
		uint8_t bData_7; //7

	} NIT_Bytes; //0x8c
	int fill_0x94[4]; //0x94
	TSD_Handle* tsdNIT; //164 = 0xa4
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1

	} Data_0xa8; //0xa8
	int fill_0xac[5]; //0xac
	/*TSD_Handle*/void* tsdTDT; //192 = 0xc0
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1
		uint8_t bData_2; //2
		uint8_t bData_3; //3
		uint8_t bData_4; //4
		uint8_t bData_5; //5
		uint8_t bData_6; //6
		uint8_t bData_7; //7
		uint8_t bData_8; //8
		uint8_t bData_9; //9
		uint8_t bData_10; //10
		uint8_t bData_11; //11

	} Data_0xc4; //0xc4
	int fill_0xd0[3]; //0xd0
	/*TSD_Handle*/void* tsdEIT; //220 = 0xdc
	int fill_0xe0[7]; //0xe0
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1

	} Data_0xfc; //0xfc
	int fill_0x100[5]; //0x100
	/*TSD_Handle*/void* Data_0x114; //276 = 0x114
	int fill_0x118[7]; //0x118
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1

	} Data_0x134; //0x134
	int fill_0x138[5]; //0x138
	/*TSD_Handle*/void* Data_0x14c; //332 = 0x14c
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1

	} Data_0x150; //0x150
	int fill_0x154[5]; //0x154
	/*TSD_Handle*/void* Data_0x168; //360 = 0x168
	//0x16c
#if 0 //TODO!!! Too long
	struct
	{
		uint8_t bData_0; //0
		uint8_t bData_1; //1

	} Data_0x16c; //0x16c
	int fill_0x170[5]; //0x170
	/*TSD_Handle*/void* Data_0x184; //388 = 0x184
#endif
} Struct_234a73e8_Inner8_Too_long;


/* 234044f0 / 23406964 - todo */
int sub_234044f0(Struct_234a73e8* r6, PSI_BufferParams* r5)
{
	TSD_SectionFilter sp_0x40;
	TSD_PidChannelParams sp;

#if 0
	console_send_string("sub_234044f0 (todo.c): TODO\r\n");
#endif

	/*Struct_234a73e8_Inner8*/Struct_234a73e8_Inner8_Too_long* r4 = (void*) &r6->Data_8;

	memset(r4, 0, sizeof(Struct_234a73e8_Inner8));
	memset(&sp, 0, sizeof(sp));

	sp.bData_1 = r5->wData_0;
	sp.Data_4 = &sp_0x40;

	if (r5->PAT_bufferSize != 0)
	{
		//0x234069b8
		sp.bData_0 = r6->index;
		sp.pid = 0x00; //r7 //PAT
		sp.sectionDataNotify = psi_handle_PAT_section;

		r4->bData_0 = 0; //r7 //program_association_section
		r4->bData_1 = 0xff; //sb

		sp.Data_4->bNumTargetIndex = 1; //r8
		sp.Data_4->wTargetLength = 0; //r7
		sp.Data_4->Data_4 = r4;
		sp.Data_4->bData_8 = 1; //r8
		sp.bmOpenParams.Data_4 = sp.bData_1;
		sp.bmOpenParams.pidChannel = PSI_PID_CHANNEL_PAT;
		sp.bmOpenParams.bufferAddress = r5->PAT_bufferAddress;
		sp.bmOpenParams.bufferSize = r5->PAT_bufferSize;
		sp.bmOpenParams.Data_0x14 = 1; //r8
		sp.bmOpenParams.Data_0x18 = 0; //r7
		sp.bmOpenParams.Data_0x1c = 0; //r7
		sp.bmOpenParams.handleOverflow = 0; //r7
		sp.bmOpenParams.Data_0x24 = 0; //r7
		sp.bmOpenParams.Data_0x28 = 0; //r7
		sp.bmOpenParams.Data_0x2c = 0; //r7
		sp.bmOpenParams.Data_0x30 = 0; //r7

		tsd_open_pid_channel(&r4->tsdPAT, &sp);
	}
	//loc_23406a40
	//int sl = 2;
	if (r5->PMT_bufferSize != 0)
	{
		//0x23406a50
		sp.bData_0 = r6->index;
		sp.pid = 0; //r7
		sp.sectionDataNotify = psi_handle_PMT_section;

		r4->Data_0x38.bData_0 = 0; //r7
		r4->Data_0x38.bData_1 = 0; //r7
		r4->Data_0x38.bData_2 = 0; //r7
		r4->Data_0x38.bData_3 = 0; //r7
		r4->Data_0x38.bData_4 = 0; //r7
		r4->Data_0x38.bData_5 = 0; //r7
		r4->Data_0x38.bData_6 = 0; //r7
		r4->Data_0x38.bData_7 = 0; //r7

		sp.Data_4->bNumTargetIndex = 1; //r8
		sp.Data_4->wTargetLength = 2; //sl
		sp.Data_4->Data_4 = &r4->Data_0x38;
		sp.Data_4->bData_8 = 1; //r8
		sp.bmOpenParams.Data_4 = sp.bData_1;
		sp.bmOpenParams.pidChannel = PSI_PID_CHANNEL_PMT;
		sp.bmOpenParams.bufferAddress = r5->PMT_bufferAddress;
		sp.bmOpenParams.bufferSize = r5->PMT_bufferSize;
		sp.bmOpenParams.Data_0x14 = 1; //r8
		sp.bmOpenParams.Data_0x18 = 0; //r7
		sp.bmOpenParams.Data_0x1c = 0; //r7
		sp.bmOpenParams.handleOverflow = 0; //r7
		sp.bmOpenParams.Data_0x24 = 0; //r7
		sp.bmOpenParams.Data_0x28 = 0; //r7
		sp.bmOpenParams.Data_0x2c = 0; //r7
		sp.bmOpenParams.Data_0x30 = 0; //r7

		tsd_open_pid_channel(&r4->tsdPMT, &sp);
	}
	//loc_23406af4
	//int fp = 4;
	if (r5->SDT_BAT_bufferSize != 0)
	{
		//0x23406b04
		sp.bData_0 = r6->index;
		sp.pid = 0x11; //SDT or BAT???
		sp.sectionDataNotify = psi_handle_SDT_BAT_section;

		r4->Data_0x54.bData_0 = 0x42; //service_description_section - actual_transport_stream
		r4->Data_0x54.bData_1 = 0xff; //sb;
		r4->Data_0x54.bData_2 = 0;
		r4->Data_0x54.bData_3 = 0;
		r4->Data_0x54.bData_4 = 0;
		r4->Data_0x54.bData_5 = 0;
		r4->Data_0x54.bData_6 = 0;
		r4->Data_0x54.bData_7 = 0;
		r4->Data_0x54.bData_8 = 0;
		r4->Data_0x54.bData_9 = 0xff; //sb;

		sp.Data_4->bNumTargetIndex = 1; //r8
		sp.Data_4->wTargetLength = 4; //fp
		sp.Data_4->Data_4 = &r4->Data_0x54;
		sp.Data_4->bData_8 = 1; //r8

		sp.bmOpenParams.Data_4 = sp.bData_1;
		sp.bmOpenParams.pidChannel = PSI_PID_CHANNEL_SDT_BAT;
		sp.bmOpenParams.bufferAddress = r5->SDT_BAT_bufferAddress;
		sp.bmOpenParams.bufferSize = r5->SDT_BAT_bufferSize;
		sp.bmOpenParams.Data_0x14 = 1; //r8
		sp.bmOpenParams.Data_0x18 = 0; //r7
		sp.bmOpenParams.Data_0x1c = 0; //r7
		sp.bmOpenParams.handleOverflow = 0; //r7
		sp.bmOpenParams.Data_0x24 = 0; //r7
		sp.bmOpenParams.Data_0x28 = 0; //r7
		sp.bmOpenParams.Data_0x2c = 0; //r7
		sp.bmOpenParams.Data_0x30 = 0; //r7

		tsd_open_pid_channel(&r4->tsdSDT_BAT, &sp);
	}
	//loc_23406bb8
	if (r5->NIT_bufferAddress != 0)
	{
		//0x23406bc4
		sp.bData_0 = r6->index;
		sp.pid = 0x10; //NIT???
		sp.sectionDataNotify = psi_handle_NIT_section;

		r4->NIT_Bytes.bData_0 = 0x40;
		r4->NIT_Bytes.bData_1 = 0xff; //sb;
		r4->NIT_Bytes.bData_2 = 0;
		r4->NIT_Bytes.bData_3 = 0;
		r4->NIT_Bytes.bData_4 = 0;
		r4->NIT_Bytes.bData_5 = 0;
		r4->NIT_Bytes.bData_6 = 0;
		r4->NIT_Bytes.bData_7 = 0;

		sp.Data_4->bNumTargetIndex = 1; //r8
		sp.Data_4->wTargetLength = 4; //fp
		sp.Data_4->Data_4 = &r4->NIT_Bytes;
		sp.Data_4->bData_8 = 1; //r8
		sp.bmOpenParams.Data_4 = sp.bData_1;
		sp.bmOpenParams.pidChannel = PSI_PID_CHANNEL_NIT;
		sp.bmOpenParams.bufferAddress = r5->NIT_bufferAddress;
		sp.bmOpenParams.bufferSize = r5->NIT_bufferSize;
		sp.bmOpenParams.Data_0x14 = 1; //r8
		sp.bmOpenParams.Data_0x18 = 0; //r7
		sp.bmOpenParams.Data_0x1c = 0; //r7
		sp.bmOpenParams.handleOverflow = 0; //r7
		sp.bmOpenParams.Data_0x24 = 0; //r7
		sp.bmOpenParams.Data_0x28 = 0; //r7
		sp.bmOpenParams.Data_0x2c = 0; //r7
		sp.bmOpenParams.Data_0x30 = 0; //r7

		tsd_open_pid_channel(&r4->tsdNIT, &sp);
	}
	//loc_23406c70
	//fp = 0x14
	if (r5->TDT_bufferAddress != 0)
	{
		//0x23406c80
		sp.bData_0 = r6->index;
		sp.pid = 0x14; //fp //TDT or TOT???
		sp.sectionDataNotify = psi_handle_TDT_section;

		r4->Data_0xa8.bData_0 = 0x70;
		r4->Data_0xa8.bData_1 = 0xf0;

		sp.Data_4->bNumTargetIndex = 1; //r8
		sp.Data_4->wTargetLength = 0; //r7
		sp.Data_4->Data_4 = &r4->Data_0xa8;
		sp.Data_4->bData_8 = 1; //r8

		sp.bmOpenParams.Data_4 = sp.bData_1;
		sp.bmOpenParams.pidChannel = PSI_PID_CHANNEL_TDT;
		sp.bmOpenParams.bufferAddress = r5->TDT_bufferAddress;
		sp.bmOpenParams.bufferSize = r5->TDT_bufferSize;
		sp.bmOpenParams.Data_0x14 = 1; //r8
		sp.bmOpenParams.Data_0x18 = 0; //r7
		sp.bmOpenParams.Data_0x1c = 0; //r7
		sp.bmOpenParams.handleOverflow = 0; //r7
		sp.bmOpenParams.Data_0x24 = 0; //r7
		sp.bmOpenParams.Data_0x28 = 0; //r7
		sp.bmOpenParams.Data_0x2c = 0; //r7
		sp.bmOpenParams.Data_0x30 = 0; //r7

		tsd_open_pid_channel(&r4->tsdTDT, &sp);
	}
	//loc_23406d14
	if (r5->EIT_bufferAddress != 0)
	{
		//0x23406d20
		sp.bData_0 = r6->index;
		sp.pid = 0x12; //EIT
		sp.sectionDataNotify = psi_handle_EIT_section;

		r4->Data_0xc4.bData_0 = 0; //r7
		r4->Data_0xc4.bData_1 = 0; //r7
		r4->Data_0xc4.bData_2 = 0; //r7
		r4->Data_0xc4.bData_3 = 0; //r7
		r4->Data_0xc4.bData_4 = 0; //r7
		r4->Data_0xc4.bData_5 = 0; //r7
		r4->Data_0xc4.bData_6 = 0; //r7
		r4->Data_0xc4.bData_7 = 0; //r7
		r4->Data_0xc4.bData_8 = 0; //r7
		r4->Data_0xc4.bData_9 = 0; //r7
		r4->Data_0xc4.bData_10 = 0; //r7
		r4->Data_0xc4.bData_11 = 0; //r7

		sp.Data_4->bNumTargetIndex = 2; //sl
		sp.Data_4->wTargetLength = 2; //sl
		sp.Data_4->Data_4 = &r4->Data_0xc4;
		sp.Data_4->bData_8 = 1; //r8

		sp.bmOpenParams.Data_4 = sp.bData_1;
		sp.bmOpenParams.pidChannel = PSI_PID_CHANNEL_EIT;
		sp.bmOpenParams.bufferAddress = r5->EIT_bufferAddress;
		sp.bmOpenParams.bufferSize = r5->EIT_bufferSize;
		sp.bmOpenParams.Data_0x14 = 1; //r8
		sp.bmOpenParams.Data_0x18 = 0; //r7
		sp.bmOpenParams.Data_0x1c = 0; //r7
		sp.bmOpenParams.handleOverflow = 0; //r7
		sp.bmOpenParams.Data_0x24 = 0; //r7
		sp.bmOpenParams.Data_0x28 = 0; //r7
		sp.bmOpenParams.Data_0x2c = 0; //r7
		sp.bmOpenParams.Data_0x30 = 0; //r7

		tsd_open_pid_channel(&r4->tsdEIT, &sp);
	}
	//loc_23406dd8
	if (r5->Data_0x24 != 0)
	{
		//0x23406de4
		sp.bData_0 = r6->index;
		sp.pid = 0; //r7
		sp.sectionDataNotify = sub_234059b0;

		r4->Data_0x70.bData_0 = 0; //r7
		r4->Data_0x70.bData_1 = 0; //r7
		r4->Data_0x70.bData_2 = 0; //r7
		r4->Data_0x70.bData_3 = 0; //r7
		r4->Data_0x70.bData_4 = 0; //r7
		r4->Data_0x70.bData_5 = 0; //r7
		r4->Data_0x70.bData_6 = 0; //r7
		r4->Data_0x70.bData_7 = 0; //r7
		r4->Data_0x70.bData_8 = 0; //r7
		r4->Data_0x70.bData_9 = 0; //r7
		r4->Data_0x70.bData_10 = 0; //r7
		r4->Data_0x70.bData_11 = 0; //r7
		r4->Data_0x70.bData_12 = 0; //r7
		r4->Data_0x70.bData_13 = 0; //r7
		r4->Data_0x70.bData_14 = 0; //r7
		r4->Data_0x70.bData_15 = 0; //r7
		r4->Data_0x70.bData_16 = 0; //r7

		sp.Data_4->bNumTargetIndex = 1; //r8
		sp.Data_4->wTargetLength = 2; //sl
		sp.Data_4->Data_4 = &r4->Data_0x70;
		sp.Data_4->bData_8 = 1; //r8

		sp.bmOpenParams.Data_4 = sp.bData_1;
		sp.bmOpenParams.pidChannel = 17;
		sp.bmOpenParams.bufferAddress = r5->Data_0x24;
		sp.bmOpenParams.bufferSize = r5->Data_0x28;
		sp.bmOpenParams.Data_0x14 = 1; //r8
		sp.bmOpenParams.Data_0x18 = 0; //r7
		sp.bmOpenParams.Data_0x1c = 0; //r7
		sp.bmOpenParams.handleOverflow = 0; //r7
		sp.bmOpenParams.Data_0x24 = 0; //r7
		sp.bmOpenParams.Data_0x28 = 0; //r7
		sp.bmOpenParams.Data_0x2c = 0; //r7
		sp.bmOpenParams.Data_0x30 = 0; //r7

		tsd_open_pid_channel(&r4->Data_0x88, &sp);
	}
	//loc_23406eac
	if (r5->Data_0x1c != 0)
	{
		//0x23406eb8
		sp.bData_0 = r6->index;
		sp.pid = 1; //r8 //CAT???
		sp.sectionDataNotify = psi_handle_CAT_section;
		sp.Data_4->bNumTargetIndex = 1; //r8

		r4->Data_0x1c.bData_0 = 1; //r8
		r4->Data_0x1c.bData_1 = 0xff; //sb

		sp.Data_4->bNumTargetIndex = 1; //r8
		sp.Data_4->wTargetLength = 0; //r7
		sp.Data_4->Data_4 = &r4->Data_0x1c;
		sp.Data_4->bData_8 = 1; //r8

		sp.bmOpenParams.Data_4 = sp.bData_1;
		sp.bmOpenParams.pidChannel = PSI_PID_CHANNEL_CAT;
		sp.bmOpenParams.bufferAddress = r5->Data_0x1c;
		sp.bmOpenParams.bufferSize = r5->Data_0x20;
		sp.bmOpenParams.Data_0x14 = 1; //r8
		sp.bmOpenParams.Data_0x18 = 0; //r7
		sp.bmOpenParams.Data_0x1c = 0; //r7
		sp.bmOpenParams.handleOverflow = 0; //r7
		sp.bmOpenParams.Data_0x24 = 0; //r7
		sp.bmOpenParams.Data_0x28 = 0; //r7
		sp.bmOpenParams.Data_0x2c = 0; //r7
		sp.bmOpenParams.Data_0x30 = 0; //r7

		tsd_open_pid_channel(&r4->tsdCAT, &sp);
	}
	//loc_23406f4c
	//sl = 0x80
	if (r5->Data_0x5c != 0)
	{
		//0x23406f5c
		sp.bData_0 = r6->index;
		sp.pid = 0; //r7
		sp.sectionDataNotify = sub_234059f0;

		r4->Data_0x134.bData_0 = 0x80; //sl;
		r4->Data_0x134.bData_1 = 0xff; //sb;

		sp.Data_4->bNumTargetIndex = 1; //r8
		sp.Data_4->wTargetLength = 0; //r7
		sp.Data_4->Data_4 = &r4->Data_0x134;
		sp.Data_4->bData_8 = 1; //r8

		sp.bmOpenParams.Data_4 = sp.bData_1;
		sp.bmOpenParams.pidChannel = 21;
		sp.bmOpenParams.bufferAddress = r5->Data_0x5c;
		sp.bmOpenParams.bufferSize = r5->Data_0x60;
		sp.bmOpenParams.Data_0x14 = 1; //r8
		sp.bmOpenParams.Data_0x18 = 0; //r7
		sp.bmOpenParams.Data_0x1c = 0; //r7
		sp.bmOpenParams.handleOverflow = 0; //r7
		sp.bmOpenParams.Data_0x24 = 0; //r7
		sp.bmOpenParams.Data_0x28 = 0; //r7
		sp.bmOpenParams.Data_0x2c = 0; //r7
		sp.bmOpenParams.Data_0x30 = 0; //r7

		tsd_open_pid_channel(&r4->Data_0x14c, &sp);
	}
	//loc_23406fe8
	if (r5->Data_0x64 != 0)
	{
		//0x23406ff4
		sp.bData_0 = r6->index;
		sp.pid = 0; //r7
		sp.sectionDataNotify = sub_23405a30;

		r4->Data_0x150.bData_0 = 0x80; //sl;
		r4->Data_0x150.bData_1 = 0xff; //sb;

		sp.Data_4->bNumTargetIndex = 1; //r8
		sp.Data_4->wTargetLength = 0; //r7
		sp.Data_4->Data_4 = &r4->Data_0x150;
		sp.Data_4->bData_8 = 1; //r8

		sp.bmOpenParams.Data_4 = sp.bData_1;
		sp.bmOpenParams.pidChannel = 22;
		sp.bmOpenParams.bufferAddress = r5->Data_0x64;
		sp.bmOpenParams.bufferSize = r5->Data_0x68;
		sp.bmOpenParams.Data_0x14 = 1; //r8
		sp.bmOpenParams.Data_0x18 = 0; //r7
		sp.bmOpenParams.Data_0x1c = 0; //r7
		sp.bmOpenParams.handleOverflow = 0; //r7
		sp.bmOpenParams.Data_0x24 = 0; //r7
		sp.bmOpenParams.Data_0x28 = 0; //r7
		sp.bmOpenParams.Data_0x2c = 0; //r7
		sp.bmOpenParams.Data_0x30 = 0; //r7

		tsd_open_pid_channel(&r4->Data_0x168, &sp);
	}
	//loc_23407080
#if 0 //TODO!!! r4->Data_0x184: Too long
	if (r5->Data_0x6c != 0)
	{
		//0x2340708c
		sp.bData_0 = r6->Data_0;
		sp.pid = 0; //r7
		sp.sectionDataNotify = sub_23405a70;

		r4->Data_0x16c.bData_0 = 0x80; //sl;
		r4->Data_0x16c.bData_1 = 0xff; //sb;

		sp.Data_4->bNumTargetIndex = 1; //r8
		sp.Data_4->wTargetLength = 0; //r7
		sp.Data_4->Data_4 = &r4->Data_0x16c;
		sp.Data_4->bData_8 = 1; //r8

		sp.bmOpenParams.Data_4 = sp.bData_1;
		sp.bmOpenParams.pidChannel = 23;
		sp.bmOpenParams.bufferAddress = r5->Data_0x6c;
		sp.bmOpenParams.bufferSize = r5->Data_0x70;
		sp.bmOpenParams.Data_0x14 = 1; //r8
		sp.bmOpenParams.Data_0x18 = 0; //r7
		sp.bmOpenParams.Data_0x1c = 0; //r7
		sp.bmOpenParams.handleOverflow = 0; //r7
		sp.bmOpenParams.Data_0x24 = 0; //r7
		sp.bmOpenParams.Data_0x28 = 0; //r7
		sp.bmOpenParams.Data_0x2c = 0; //r7
		sp.bmOpenParams.Data_0x30 = 0; //r7

		tsd_open_pid_channel(&r4->Data_0x184, &sp);
	}
#endif
	//loc_23407118
	if (r5->Data_0x54 != 0)
	{
		//0x23407124
		sp.bData_0 = r6->index;
		sp.pid = 0; //r7
		sp.sectionDataNotify = sub_23405ab0;

		r4->Data_0xfc.bData_0 = 0x82;
		r4->Data_0xfc.bData_1 = 0xf1;

		sp.Data_4->bNumTargetIndex = 1; //r8
		sp.Data_4->wTargetLength = 0; //r7
		sp.Data_4->Data_4 = &r4->Data_0xfc;
		sp.Data_4->bData_8 = 1; //r8

		sp.bmOpenParams.Data_4 = sp.bData_1;
		sp.bmOpenParams.pidChannel = 20; //fp
		sp.bmOpenParams.bufferAddress = r5->Data_0x54;
		sp.bmOpenParams.bufferSize = r5->Data_0x58;
		sp.bmOpenParams.Data_0x14 = 1; //r8
		sp.bmOpenParams.Data_0x18 = 0; //r7
		sp.bmOpenParams.Data_0x1c = 0; //r7
		sp.bmOpenParams.handleOverflow = 0; //r7
		sp.bmOpenParams.Data_0x24 = 0; //r7
		sp.bmOpenParams.Data_0x28 = 0; //r7
		sp.bmOpenParams.Data_0x2c = 0; //r7
		sp.bmOpenParams.Data_0x30 = 0; //r7

		tsd_open_pid_channel(&r4->Data_0x114, &sp);
	}
	//loc_234071b4
	return 0;
}


/* 23406210 / 2340866c - todo */
void psi_thread(Struct_234a73e8* r4)
{
	uint8_t sp = 0;

	if (0 != sub_234044f0(r4, &r4->Data_4->bufferParams))
	{
		r4 = 0;
	}

	if (r4->Data_4->onNewPSIDecoder != 0)
	{
		(r4->Data_4->onNewPSIDecoder)(r4);
	}

	r4->queue = (void*) OSQCreate(&r4->Data_0x17c, 0x28);
	r4->sema = OSSemCreate(1);

	r4->pfHandleQueueItem = psi_handle_queue_item;
	r4->pfHandleState = psi_handle_state;

	while (1)
	{
		//loc_23406278
		void* item = (void*) OSQPend(r4->queue, 0, &sp);
		if (item != 0)
		{
			if (r4->pfHandleQueueItem != 0)
			{
				(r4->pfHandleQueueItem)(r4, item);
			}
		}

		OSSemPend(r4->sema, 100, &sp);
		if (sp == 0)
		{
			if (r4->pfHandleState != 0)
			{
				(r4->pfHandleState)(r4);
			}

			OSSemPost(r4->sema);
		}
	} //while (1)
}


/* 234062d8 / 23408734 - complete */
void* psi_open(PSI_Params* r5)
{
	Timer_Params sp_0x18;

	Struct_234a73e8* r4 = 0;

#if 0
	console_send_string("psi_open (todo.c): TODO\r\n");
#endif

	for (uint8_t i = 0; i < 2; i++)
	{
		if (Data_234a73e8[i].sema == 0)
		{
			r4 = &Data_234a73e8[i];

			r4->Data_4 = r5;
			//->loc_23406324
			break;
		}
	}
	//loc_23406324
	if (r4 == 0)
	{
		return (void*) 5;
	}
	//0x23406330
	sp_0x18.Data_0 = 100;
	sp_0x18.Data_4 = r4;
	sp_0x18.Data_8 = psi_timer_func;

	r4->hTimer = timer_user_open(&sp_0x18);

	r4->pfOnPMTData = r5->Data_0x80;
	r4->pfOnSDTData = r5->Data_0x84;
	r4->Data_0x22c = r5->Data_0x7c;
	r4->Data_0x238 = r5->Data_0x88;
	r4->Data_0x23c = r5->Data_0x8c;

	OSTaskCreateExt(psi_thread, r4, &Data_234a5490[r4->index].words[THREAD_STACK_SIZE_PSI-1],
			r5->threadPrio & 0xff, r5->threadPrio,
			Data_234a5490[r4->index].words, THREAD_STACK_SIZE_PSI,
			"FILTER_MANAGER", 3);

	return r4;
}


/* 234063cc / 23408828 - complete */
int psi_init(int sb)
{
#if 0
	console_send_string("psi_init (todo.c): TODO\r\n");
#endif

	for (uint8_t i = 0; i < 2; i++)
	{
		memset(&Data_234a73e8[i], 0, sizeof(Struct_234a73e8));

		Data_234a73e8[i].index = i;
	}

	sub_2344ec24(sb);

	return 0;
}


/* 23406418 - complete */
int psi_start_for_service(Struct_234a73e8* r0, int r1, int sectionMask, void (*onPSIData)(Struct_234a73e8*))
{
	Queue_Item queueItem; //sp_0x20
	Queue_Item_Data sp4;

#if 0
	console_send_string("psi_start_for_service (todo.c): TODO\r\n");
#endif

	queueItem.state = PSI_STATE_START;
	queueItem.pData = &sp4;

	sp4.handled = 0;

	sp4.activeMask = sectionMask & 
		~(PSI_MASK_CAT | PSI_MASK_TDT | PSI_MASK_EIT | PSI_MASK_NIT); //0x74;

	sp4.Data_8 = (sectionMask & PSI_MASK_EIT);
	sp4.Data_8 |= (sectionMask & PSI_MASK_TDT);
	sp4.Data_8 |= (sectionMask & PSI_MASK_CAT);
	sp4.Data_8 |= (sectionMask & PSI_MASK_NIT);
	sp4.Data_8 |= 0x3c00;

	sp4.Data_0x10 = 0;
	sp4.wData_0x14 = r1;
	sp4.wData_0x16 = 0;
	sp4.wData_0x18 = 0;

	if (onPSIData != 0)
	{
		sp4.pfOnPSIData = onPSIData;
	}
	else
	{
		sp4.pfOnPSIData = psi_default_data_handler;
	}

	if (0 == OSQPost(r0->queue, &queueItem))
	{
		//->loc_234064a4
		while (sp4.handled != 1)
		{
			//loc_2340649c
			rtos_task_wait(5);
		}
	}
	//loc_234064b0
	return 0;
}


/* 234064bc / 23408918 - todo */
int psi_start(Struct_234a73e8* r0, int sectionMask, void (*onPSIData)(), void (*r3)(), int arg_0, int arg_4)
{
	Queue_Item queueItem; //sp_0x20
	Queue_Item_Data sp4;

	int res;

#if 0
	console_send_string("psi_start\r\n");
#endif

	queueItem.state = PSI_STATE_START;
	queueItem.pData = &sp4;

	sp4.handled = 0;
	sp4.activeMask = sectionMask;
	sp4.Data_8 = 0;
	sp4.Data_0x10 = r3;
	sp4.wData_0x14 = 0;
	sp4.wData_0x16 = arg_0; //lr;
	sp4.wData_0x18 = arg_4; //r4;
	if (onPSIData != 0)
	{
		sp4.pfOnPSIData = onPSIData;
	}
	else
	{
		sp4.pfOnPSIData = psi_default_data_handler;
	}

	res = OSQPost(r0->queue, &queueItem);
	if (res == 0)
	{
		//->loc_2340652c
		while (sp4.handled != 1)
		{
			//loc_23406524
			rtos_task_wait(5);
		}
	}
	//loc_23406538
	return 0;
}


/* 234065f8 / 23408a54 - complete */
int psi_stop(Struct_234a73e8* r0, uint16_t r1)
{
	Queue_Item queueItem; //sp_0x20
	Queue_Item_Data sp4;
	int res;

#if 0
	console_send_string("psi_stop\r\n");
#endif

	queueItem.state = PSI_STATE_STOP;
	queueItem.pData = &sp4;

	sp4.handled = 0;
	sp4.wData_0x14 = r1;

	res = OSQPost(r0->queue, &queueItem);

	if (res == 0)
	{
		//->loc_2340663c
		while (sp4.handled != 1)
		{
			//loc_23406634
			rtos_task_wait(5);
		}
	}
	//loc_23406648
	return res;
}


/* 23406654 / 23408ab0 - complete */
int sub_23406654(void* h, uint32_t r5, PSI_Program* r6)
{
#if 0
	console_send_string("sub_23406654 (todo.c): TODO\r\n");
#endif

	uint8_t sp = 0;
	Struct_234a73e8* r4 = h;

	if (r5 > 150)
	{
		return 1;
	}

	OSSemPend(r4->sema, 100, &sp);

	uint32_t r0 = pat_get_num_programs(r4->index & 0xff);
	if (r0 <= r5)
	{
		sp = 7;
	}
	else
	{
		*r6 = r4->programs[r5];
	}

	OSSemPost(r4->sema);

	return sp;
}


/* 234066d0 - complete */
int sub_234066d0(void* h, PSI_Program* r6)
{
#if 0
	console_send_string("sub_234066d0 (todo.c): TODO\r\n");
#endif

	uint8_t sp = 0;
	Struct_234a73e8* r4 = h;

	OSSemPend(r4->sema, 0, &sp);

	if ((r4->activeMask != 0) &&
			(((r4->Data_0x21e04 & 0x02) | 0x09) == 0x0b) &&
			(r4->wData_0x21e14 != 0))
	{
		uint16_t r0 = pat_get_num_programs(r4->index & 0xff);
		//->loc_23406788
		while (r0--)
		{
			//loc_23406744
			if (r4->programs[r0].pat_program_number == r4->wData_0x21e14)
			{
				//memcpy(r6, &r4->programs[r0], sizeof(PSI_Program));
				*r6 = r4->programs[r0];

				OSSemPost(r4->sema);

				return 0;
			}
			//loc_23406788
		}
	}
	//loc_23406798
	OSSemPost(r4->sema);

	return 0xff;
}


/* 234067a8 - complete */
int psi_get_all_current_programs(Struct_234a73e8* r4, 
		uint16_t* pNumPrograms, PSI_Program** ppPrograms)
{
#if 0
	console_send_string("psi_get_all_current_programs (todo.c): TODO\r\n");
#endif

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "psi_get_all_current_programs: r4->Data_0x21e08=0x%x\r\n", r4->Data_0x21e08);
		console_send_string(debug_string);
	}
#endif

	if (r4->Data_0x21e08 & 1)
	{
		*pNumPrograms = 0;
	}
	else
	{
		*pNumPrograms = pat_get_num_programs(r4->index);
		*ppPrograms = r4->programs;
	}

	return r4->Data_0x21e08;
}


/* 23406834 - complete */
void sub_23406834(Struct_234a73e8* r4)
{
	uint8_t sp;

#if 0
	console_send_string("sub_23406834 (todo.c): TODO\r\n");
#endif

	OSSemPend(r4->sema, 100, &sp);

	sub_2344dcf4(r4->index, -1);

	OSSemPost(r4->sema);
}


/* 23406868 - complete */
void psi_get_network_info(Struct_2344dc3c* r5, Struct_234a73e8* r4)
{
	uint8_t sp_0xc;
	Struct_2344dc3c sp;

#if 0
	console_send_string("psi_get_network_info (todo.c): TODO\r\n");
#endif

	OSSemPend(r4->sema, 100, &sp_0xc);

	sub_2344dc3c(r4->index, &sp);

	OSSemPost(r4->sema);

	*r5 = sp;
}


/* 234068f0 - complete */
void sub_234068f0(Struct_234a73e8* r4, int r6, int r7, int r5, int r8)
{
	uint8_t sp;

#if 0
	console_send_string("sub_234068f0 (todo.c): TODO\r\n");
#endif

	OSSemPend(r4->sema, 100, &sp);

	if (r8 != 0)
	{
		sub_2344c730(r4->index & 0xff, r6, r7 & 0xff, r5);
		//->loc_2340694c
	}
	else
	{
		//loc_2340693c
		sub_2344c79c(r4->index & 0xff, r5);
	}
	//loc_2340694c
	OSSemPost(r4->sema);
}


/* 23406a74 - complete */
void sub_23406a74(Struct_234a73e8* r4)
{
#if 0
	console_send_string("sub_23406a74 (todo.c): TODO\r\n");
#endif

	memset(r4->programs, 0, 150 * sizeof(PSI_Program));
	memset(r4->Data_0x21d58, 0, 0xa0);
}


/* 23406ac8 / 23408ef0 - complete */
void sub_23406ac8(Struct_236e5834* r4)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_23406ac8 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	r4->Data_0xc = 0;

	OS_EXIT_CRITICAL();
}


