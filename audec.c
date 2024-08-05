

#include "data.h"
#include "audec.h"

#define AUDEC_CMD_OPEN_DECODER         0x5015
#define AUDEC_CMD_START_DECODER        0x5035
#define AUDEC_CMD_STOP_DECODER         0x5045
#define AUDEC_CMD_GET_CAPABILITIES     0x5055
#define AUDEC_CMD_GET_STATUS           0x5065
#define AUDEC_CMD_SET_PARAMS           0x5075


static const uint32_t audio_crcTable[] = //23488eec
{
   0x00000000, 0x04c11db7, 0x09823b6e, 0x0d4326d9, 0x130476dc, 0x17c56b6b,
   0x1a864db2, 0x1e475005, 0x2608edb8, 0x22c9f00f, 0x2f8ad6d6, 0x2b4bcb61,
   0x350c9b64, 0x31cd86d3, 0x3c8ea00a, 0x384fbdbd, 0x4c11db70, 0x48d0c6c7,
   0x4593e01e, 0x4152fda9, 0x5f15adac, 0x5bd4b01b, 0x569796c2, 0x52568b75,
   0x6a1936c8, 0x6ed82b7f, 0x639b0da6, 0x675a1011, 0x791d4014, 0x7ddc5da3,
   0x709f7b7a, 0x745e66cd, 0x9823b6e0, 0x9ce2ab57, 0x91a18d8e, 0x95609039,
   0x8b27c03c, 0x8fe6dd8b, 0x82a5fb52, 0x8664e6e5, 0xbe2b5b58, 0xbaea46ef,
   0xb7a96036, 0xb3687d81, 0xad2f2d84, 0xa9ee3033, 0xa4ad16ea, 0xa06c0b5d,
   0xd4326d90, 0xd0f37027, 0xddb056fe, 0xd9714b49, 0xc7361b4c, 0xc3f706fb,
   0xceb42022, 0xca753d95, 0xf23a8028, 0xf6fb9d9f, 0xfbb8bb46, 0xff79a6f1,
   0xe13ef6f4, 0xe5ffeb43, 0xe8bccd9a, 0xec7dd02d, 0x34867077, 0x30476dc0,
   0x3d044b19, 0x39c556ae, 0x278206ab, 0x23431b1c, 0x2e003dc5, 0x2ac12072,
   0x128e9dcf, 0x164f8078, 0x1b0ca6a1, 0x1fcdbb16, 0x018aeb13, 0x054bf6a4,
   0x0808d07d, 0x0cc9cdca, 0x7897ab07, 0x7c56b6b0, 0x71159069, 0x75d48dde,
   0x6b93dddb, 0x6f52c06c, 0x6211e6b5, 0x66d0fb02, 0x5e9f46bf, 0x5a5e5b08,
   0x571d7dd1, 0x53dc6066, 0x4d9b3063, 0x495a2dd4, 0x44190b0d, 0x40d816ba,
   0xaca5c697, 0xa864db20, 0xa527fdf9, 0xa1e6e04e, 0xbfa1b04b, 0xbb60adfc,
   0xb6238b25, 0xb2e29692, 0x8aad2b2f, 0x8e6c3698, 0x832f1041, 0x87ee0df6,
   0x99a95df3, 0x9d684044, 0x902b669d, 0x94ea7b2a, 0xe0b41de7, 0xe4750050,
   0xe9362689, 0xedf73b3e, 0xf3b06b3b, 0xf771768c, 0xfa325055, 0xfef34de2,
   0xc6bcf05f, 0xc27dede8, 0xcf3ecb31, 0xcbffd686, 0xd5b88683, 0xd1799b34,
   0xdc3abded, 0xd8fba05a, 0x690ce0ee, 0x6dcdfd59, 0x608edb80, 0x644fc637,
   0x7a089632, 0x7ec98b85, 0x738aad5c, 0x774bb0eb, 0x4f040d56, 0x4bc510e1,
   0x46863638, 0x42472b8f, 0x5c007b8a, 0x58c1663d, 0x558240e4, 0x51435d53,
   0x251d3b9e, 0x21dc2629, 0x2c9f00f0, 0x285e1d47, 0x36194d42, 0x32d850f5,
   0x3f9b762c, 0x3b5a6b9b, 0x0315d626, 0x07d4cb91, 0x0a97ed48, 0x0e56f0ff,
   0x1011a0fa, 0x14d0bd4d, 0x19939b94, 0x1d528623, 0xf12f560e, 0xf5ee4bb9,
   0xf8ad6d60, 0xfc6c70d7, 0xe22b20d2, 0xe6ea3d65, 0xeba91bbc, 0xef68060b,
   0xd727bbb6, 0xd3e6a601, 0xdea580d8, 0xda649d6f, 0xc423cd6a, 0xc0e2d0dd,
   0xcda1f604, 0xc960ebb3, 0xbd3e8d7e, 0xb9ff90c9, 0xb4bcb610, 0xb07daba7,
   0xae3afba2, 0xaafbe615, 0xa7b8c0cc, 0xa379dd7b, 0x9b3660c6, 0x9ff77d71,
   0x92b45ba8, 0x9675461f, 0x8832161a, 0x8cf30bad, 0x81b02d74, 0x857130c3,
   0x5d8a9099, 0x594b8d2e, 0x5408abf7, 0x50c9b640, 0x4e8ee645, 0x4a4ffbf2,
   0x470cdd2b, 0x43cdc09c, 0x7b827d21, 0x7f436096, 0x7200464f, 0x76c15bf8,
   0x68860bfd, 0x6c47164a, 0x61043093, 0x65c52d24, 0x119b4be9, 0x155a565e,
   0x18197087, 0x1cd86d30, 0x029f3d35, 0x065e2082, 0x0b1d065b, 0x0fdc1bec,
   0x3793a651, 0x3352bbe6, 0x3e119d3f, 0x3ad08088, 0x2497d08d, 0x2056cd3a,
   0x2d15ebe3, 0x29d4f654, 0xc5a92679, 0xc1683bce, 0xcc2b1d17, 0xc8ea00a0,
   0xd6ad50a5, 0xd26c4d12, 0xdf2f6bcb, 0xdbee767c, 0xe3a1cbc1, 0xe760d676,
   0xea23f0af, 0xeee2ed18, 0xf0a5bd1d, 0xf464a0aa, 0xf9278673, 0xfde69bc4,
   0x89b8fd09, 0x8d79e0be, 0x803ac667, 0x84fbdbd0, 0x9abc8bd5, 0x9e7d9662,
   0x933eb0bb, 0x97ffad0c, 0xafb010b1, 0xab710d06, 0xa6322bdf, 0xa2f33668,
   0xbcb4666d, 0xb8757bda, 0xb5365d03, 0xb1f740b4
};


//234924cc
int Data_234924cc; //234924cc +0
OS_EVENT* Data_234924d0; //234924d0 +4
OS_EVENT* audec_responseSemaphore; //234924d4 +8
int audec_responseValue; //234924d8 +0x0c
Struct_235f2e2c* Data_234924dc; //234924dc +0x10
int Data_234924e0; //Data_234924e0 +0x14

static uint8_t dictionary[0x1014]; //235f1cfc, size?

struct Struct_235f2d10
{
	Struct_23429ae8 Data_0; //0
	int Data_0x10; //16 = 0x10
	int fill_20; //20
	//24 = 0x18
} Data_235f2d10[5]; //235f2d10 -> 235F2D88


typedef struct
{
	int inUse; //0
	volatile uint32_t* Data_4; //4
	volatile uint32_t* Data_8; //8
	//12
} Struct_206116b0;

Struct_206116b0 Data_235f2d88[8]; //235f2d88


/* 23429468 - todo */
void audio_unzip_firmware(uint8_t* pInBuf, uint8_t* pOutBuf, int numInBytes)
{
	int i;
	uint8_t* pOutCh;
	uint32_t control; //lr
	int data; //ip
	int* pData = &data;
	uint32_t dict_p = 0xfee; //r3

#if 0
	console_send_string("audio_unzip_firmware (todo.c): TODO\r\n");
#endif

	for (i = 0; i < (int)dict_p; i++)
	{
		dictionary[i] = ' ';
	}

	control = 0;

	while (1)
	{
		//loc_23429494
		control >>= 1;

		if ((control & (1 << 8)) == 0)
		{
			data = *pInBuf++;
			numInBytes--;
			if (data == -1)
			{
				//loc_234294fc
				break; //return;
			}
			//0x234294b4
			control = data | 0xff00;
		}
		//loc_234294b8
		data = *pInBuf;
		numInBytes--;
		if (control & 1)
		{
			//0x234294c8
			pOutCh = pOutBuf++;
			*pOutCh = *pData;
			pInBuf++;
			if (numInBytes < 0)
			{
				//loc_234294fc
				break; //return;
			}

			dictionary[dict_p++] = data; //sp[0];
			dict_p %= 0x1000;
			//->loc_23429494
		}
		else
		{
			//loc_23429500
			int32_t len; //r7
			uint32_t addr = data; //r6
			pInBuf++;
			data = *pInBuf;
			numInBytes--;
			pInBuf++;

			addr |= ((data & 0xf0) << 4);
			len = (data & 0x0f) + 2;
			//->loc_23429568
			for (i = 0; i <= len; i++)
			{
				//loc_23429524
				pOutCh = pOutBuf++;
				data = dictionary[(addr + i) % 0x1000];
				*pOutCh = *pData;
				if (numInBytes < 0)
				{
					//->loc_23429494
					break;
				}
				//0x23429550
				dictionary[dict_p++] = data;
				dict_p %= 0x1000;
			}
			//->loc_23429494
		}
	}
	//loc_234294fc
	return;
}


/* 23429574 - todo */
void audio_load_firmware(Struct_235f2e2c* r7, int r6)
{
	struct
	{
		char sp_0xc[32]; //sp_0xc
		uint32_t addr; //0x2c
		uint32_t size; //0x30
		//0x28
	} sp_0xc;

	uint32_t sp8;

	union
	{
		uint8_t bData[4];
		uint32_t dwData;
	} sp4; //4

	union
	{
		uint8_t bData[4];
		uint32_t dwData;
	} sp0; //0

	volatile uint32_t* r4 = (void*) 0x40000000;
	uint32_t r5; // = 0x01234567;
	uint32_t r1;
	uint32_t jumpAddr;

#if 0
	console_send_string("audio_load_firmware (todo.c): TODO\r\n");
#endif

	r4[0] = 0x01234567; //r5;

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "audio_load_firmware: r4[0]=0x%x\r\n", r4[0]);
			console_send_string(debug_string);
		}
#endif

//	r1 = ((uint32_t)r4 >> 31) - 0x01234567; //r5;
	sp8 = r4[0] - 0x01234567; //r1; //TODO!!!

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "audio_load_firmware: sp8=0x%x\r\n", sp8);
			console_send_string(debug_string);
		}
#endif

	if (sp8 != 0)
	{
		r4 = (void*) 0x20000000;
	}

	flash_read(r7, r6, 4, &sp8);

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "audio_load_firmware: sp8=0x%x\r\n", sp8);
			console_send_string(debug_string);
		}
#endif

	if (sp8 != 0x01234567) //r5)
	{
		//->loc_23429734
		return;
	}
	//0x234295c4
	r6 += 4;

	flash_read(r7, r6, 4, &sp8);

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "audio_load_firmware: sp8=0x%x\r\n", sp8);
			console_send_string(debug_string);
		}
#endif

	if (sp8 != 0xfedcba98)
	{
		//->loc_23429734
		return;
	}
	//0x234295ec
	r6 += 4;

	flash_read(r7, r6, 4, &sp8);

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "audio_load_firmware: sp8=0x%x\r\n", sp8);
			console_send_string(debug_string);
		}
#endif

	flash_read(r7, sp8, 4, &sp8);

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "audio_load_firmware: sp8=0x%x\r\n", sp8);
			console_send_string(debug_string);
		}
#endif

	r5 = sp8 >> 16;
	//->loc_2342973c
	while (r5--)
	{
		//loc_23429624
		r6 += 4;

		flash_read(r7, r6, 4, &sp8);

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "audio_load_firmware: sp8=0x%x\r\n", sp8);
			console_send_string(debug_string);
		}
#endif

		flash_read(r7, sp8, 40, &sp_0xc);

		if (0 == strcmp(sp_0xc.sp_0xc, "audiocodec.app"))
		{
			//0x23429664
			//r5 = 0;
			//->loc_234296c4
			int crc;

#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "audio_load_firmware: sp_0xc.size=%d, sp_0xc.addr=0x%x\r\n",
						sp_0xc.size, sp_0xc.addr);
				console_send_string(debug_string);
			}
#endif

			for (r5 = 0; r5 < (sp_0xc.size / 4); r5++)
			{
				//loc_2342966c
				flash_read(r7, sp_0xc.addr, 4, &sp8);

				sp_0xc.addr += 4;

				sp4.dwData = sp8;
				sp0.bData[0] = sp4.bData[3]; //sp7;
				sp0.bData[1] = sp4.bData[2]; //sp6;
				sp0.bData[2] = sp4.bData[1]; //sp5;
				sp0.bData[3] = sp4.bData[0]; //sp4;
				sp8 = sp0.dwData;

				r4[r5] = sp8;
			} //for (r5 = 0; r5 < (size / 4); r5++)
			//0x234296d0
			crc = audio_crc32(&r4[7], r4[1] /* Size without header: 0x33870 = 211056 */);

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "audio_load_firmware: Compressed crc=0x%x, r4[3]=0x%x\r\n", crc, r4[3]);
			console_send_string(debug_string);
		}
#endif

			if (r4[3] /* CRC of compressed image */ != crc)
			{
				//->loc_23429734
				break;
			}
			//0x234296e8
			audio_unzip_firmware((void*) &r4[7],
					(void*) r4[4], /* Target address of uncompressed image: 0x214c0000 */
					r4[1]); /* Size of compressed image */

			crc = audio_crc32(r4[4], r4[0]); /* Size of uncompressed image: 0x87cc2 = 556226 */

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "audio_load_firmware: Deflated crc=0x%x, r4[2]=0x%x\r\n", crc, r4[2]);
			console_send_string(debug_string);
		}
#endif

			if (r4[2] /* CRC of uncompressed image */ != crc)
			{
				//->loc_23429734
				break;
			}
			//0x23429710
			jumpAddr = r4[5]; /* 0x214c005c */
			if ((*((volatile uint32_t*)0xcf000210) & 0x0f) == 1) //FREG_IRQ_CTRL_ARCSTATUS
			{
				*((volatile uint32_t*)0xcf000214) = jumpAddr; //ARCJMPADDRESS
				*((volatile uint32_t*)0xcf000210) = 0x40;
			}
			//->loc_23429734
			break;
		}
		//->loc_2342973c
	} //while (r5--)
	//loc_23429734
	return;
}


/* 23429748 - complete */
void audio_irq31_callback(int value)
{
	audec_responseValue = value;

	OSSemPost(audec_responseSemaphore);
}


/* 23429758 - complete */
int audio_send_command(int command, uint32_t nArgs, int* pArgs, int* pResponse)
{
	uint8_t err;
	uint32_t i;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "audio_send_command: command=0x%x, nArgs=%d\r\n", command, nArgs);
		console_send_string(debug_string);
	}
#endif

	if (0 == intr_write_pipe((command << 16) + nArgs, 2))
	{
		//->loc_234297a4
		while (nArgs--)
		{
			//loc_23429780
			i = 0xff;
			while (i--)
			{
				//loc_23429784: delay
			}
			//0x2342978c
			if (0 != intr_write_pipe(*pArgs++, 2))
			{
				//->loc_234297d4
				return 0xff;
			}
		}
		//0x234297ac
		OSSemPend(audec_responseSemaphore, 100, &err);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "audio_send_command: err=%d\r\n", err);
		console_send_string(debug_string);
	}
#endif

		if (err == 0)
		{
			*pResponse = audec_responseValue;
		}
	}
	//loc_234297d0
	return err;
}


/* 234298cc - todo */
int audec_init(Struct_234298cc* r4)
{
	uint8_t i;

#if 0
	console_send_string("audec_init (todo.c): TODO\r\n");
#endif

	if (Data_234924d0 != 0)
	{
		return 12;
	}

	Data_234924dc = r4->pFlash;
	Data_234924e0 = r4->Data_4;

	for (i = 0; i < 5; i++)
	{
		//loc_23429900
		Data_235f2d10[i].Data_0.Data_0 = -1;
	}

	Data_234924d0 = OSSemCreate(1);
	audec_responseSemaphore = OSSemCreate(0);

	if ((*((volatile uint32_t*)0xcf000210) & 0x0f) == 1) //FREG_IRQ_CTRL_ARCSTATUS
	{
		audio_load_firmware(r4->pFlash, r4->Data_4);

		rtos_task_wait(5);
	}
	//loc_23429954
	intr_init_irq31();

	intr_register_irq31_callback(audio_irq31_callback);

	if (0 != audio_send_command(AUDEC_CMD_GET_CAPABILITIES, 0, 0, &Data_234924cc))
	{
		return 0xff;
	}

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "audec_init: Data_234924cc=0x%08x\r\n", Data_234924cc);
		console_send_string(debug_string);
	}
#endif

	return 0;
}


/* 23429980 - complete */
int audec_start_decoder(void* r0)
{
	uint8_t err = 0;
	struct Struct_235f2d10* r4 = r0;
	int resp;

#if 0
	console_send_string("audec_start_decoder (todo.c): TODO\r\n");
#endif

	if (r4 == 0)
	{
		return 0;
	}

	OSSemPend(Data_234924d0, 0, &err);
	if (err != 0)
	{
		return err;
	}

	sub_2342b2ac(r4->Data_0.audioOutHandle, 1);

	audio_send_command(AUDEC_CMD_START_DECODER, 1, &r4->Data_0x10, &resp);

	OSSemPost(Data_234924d0);

	return err;
}


/* 234299e0 - complete */
int audec_stop_decoder(void* h)
{
	uint8_t err;
	struct Struct_235f2d10* r4 = h;
	int resp;

#if 0
	console_send_string("audec_stop_decoder (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_234924d0, 0, &err);
	if (err != 0)
	{
		return err;
	}

	if (0 == audio_send_command(AUDEC_CMD_STOP_DECODER, 1, &r4->Data_0x10, &resp))
	{
		sub_2342b2ac(r4->Data_0.audioOutHandle, 0);
	}

	OSSemPost(Data_234924d0);

	return err;
}


/* 23429a3c - complete */
int audec_get_status(void* h)
{
	uint8_t err;
	int sp = 0;

#if 0
	console_send_string("audec_get_status (todo.c): TODO\r\n");
#endif

	struct Struct_235f2d10* r4 = h;

	OSSemPend(Data_234924d0, 0, &err);

	if (err != 0)
	{
		return err;
	}

	audio_send_command(AUDEC_CMD_GET_STATUS, 1, &r4->Data_0x10, &sp);

	OSSemPost(Data_234924d0);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "audec_get_status: sp=0x%x\r\n", sp);
		console_send_string(debug_string);
	}
#endif

	return sp;
}


/* 23429a90 - complete */
int audec_set_params(int* r5)
{
	uint8_t err;
	int sp;

#if 0
	console_send_string("audec_set_params (todo.c): TODO\r\n");
#endif

	OSSemPend(Data_234924d0, 0, &err);

	if (err != 0)
	{
		return err;
	}

	int res = audio_send_command(AUDEC_CMD_SET_PARAMS, 1, r5, &sp);
	if (res != 0)
	{
		sp = 0;
	}

	OSSemPost(Data_234924d0);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "audec_set_params: sp=0x%x\r\n", sp);
		console_send_string(debug_string);
	}
#endif

	return sp;
}


/* 23429ae8 - todo */
int audec_open_decoder(Struct_23429ae8* r4, void** pHandle)
{
	uint8_t err = 0; //r7
	int args[4];
	int resp = 0;
	struct Struct_235f2d10* h = 0; //r7

#if 0
	console_send_string("audec_open_decoder (todo.c): TODO\r\n");
#endif

	if ((Data_234924cc & (1 << r4->Data_0)) == 0)
	{
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "audec_open_decoder: r4->Data_0=%d not supported\r\n", r4->Data_0);
			console_send_string(debug_string);
		}
#endif
		return 8;
	}
	//0x23429b28
	OSSemPend(Data_234924d0, 0, &err);
	if (err != 0)
	{
		return err;
	}
	//0x23429b44
	for (uint8_t r0 = 0; r0 < 5; r0++)
	{
		//loc_23429b48
		if (Data_235f2d10[r0].Data_0.Data_0 == -1)
		{
			h = &Data_235f2d10[r0];

			h->Data_0 = *r4;
			//->loc_23429b78
			break;
		}
	}
	//loc_23429b78
	if (h == 0)
	{
		err = 2;
		//->loc_23429be0
	}
	else
	{
		//0x23429b84
		args[0] = r4->Data_0;
		args[1] = r4->Data_4;
		args[2] = (int) r4->bmHandle;
		args[3] = (int) r4->audioOutHandle;

		int res = audio_send_command(AUDEC_CMD_OPEN_DECODER, 4, &args[0], &resp);
		if (res != 0)
		{
			h->Data_0.Data_0 = -1;
			*pHandle = 0; //r7
			//->loc_23429be4
		}
		else
		{
			if (resp != 0)
			{
				h->Data_0x10 = resp;
				*pHandle = h;
				//->loc_23429be4
			}
			else
			{
				//loc_23429be0
				err = 2;
			}
		}
	}
	//loc_23429be4
	OSSemPost(Data_234924d0);

	return err;
}


/* 23429bf8 - complete */
int sub_23429bf8(void)
{
	return Data_234924cc & (1 << 0);
}


/* 23429c08 - complete */
int audio_crc32(uint8_t* buf, int len)
{
	uint32_t crc = 0xFFFFFFFF;

#if 0
	console_send_string("audio_crc32 (todo.c): TODO\r\n");
#endif

	while (len != 0)
	{
		len--;
		crc = audio_crcTable[ *buf++ ^ (crc >> 24) ] ^ (crc << 8);
	}

	return crc;
}


/* 23429c50 - todo */
int gpreg_init(void)
{
	uint8_t i;

	for (i = 0; i < 8; i++)
	{
		//loc_23429c68
		Data_235f2d88[i].inUse = 0;
		Data_235f2d88[i].Data_4 = &((volatile uint32_t*)0xcf000380)[i]; //FREG_IRQ_CTRL_GPX
		Data_235f2d88[i].Data_8 = &((volatile uint32_t*)0xcf000100)[i]; //FREG_IRQ_CTRL_MUTEXX
	}

	return 0;
}


/* 23429c9c - complete */
int gpreg_open(uint32_t r0, void** h)
{
#if 0
	console_send_string("gpreg_open (todo.c): TODO\r\n");
#endif

	if (r0 < 8)
	{
		if (Data_235f2d88[r0].inUse == 0)
		{
			Data_235f2d88[r0].inUse = 1;
			*h = &Data_235f2d88[r0];

			return 0;
		}
	}

	return 0xff;
}


/* 23429cd4 - complete */
void gpreg_unlock_mutex(Struct_206116b0* a)
{
	volatile uint32_t* p = a->Data_8;

	if ((a != 0) && (p != 0))
	{
		*p = 0;
	}
}


/* 23429cec - complete */
void gpreg_lock_mutex(Struct_206116b0* a)
{
	volatile uint32_t* p = a->Data_8;

	if ((a != 0) && (p != 0))
	{
		do
		{
			*p = 1;

		}
		while (*p != 1);
	}
}


/* 23429d14 - complete */
int gpreg_write(Struct_206116b0* r3, int r4)
{
	int res = 0;

#if 0
	console_send_string("gpreg_write (todo.c): TODO\r\n");
#endif

	if (r3->inUse == 0)
	{
		return 7;
	}

	gpreg_lock_mutex(r3);

	*(r3->Data_4) = r4;

	gpreg_unlock_mutex(r3);

	return res;
}


/* 23429d54 - todo */
int gpreg_read(Struct_206116b0* r3)
{
	int res;
	volatile uint32_t* p;

#if 0
	console_send_string("gpreg_read (todo.c): TODO\r\n");
#endif

	if (r3->inUse == 0)
	{
		return 0xff;
	}

	gpreg_lock_mutex(r3);

	p = r3->Data_4;
	*p;
	*p;
	*p;
	res = *p;

	gpreg_unlock_mutex(r3);

	return res;
}


