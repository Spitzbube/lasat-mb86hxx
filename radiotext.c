
#include <string.h>
#include "data.h"
#include "ucos_ii.h"
#include "radiotext.h"


#define SWAP(x)	((x>>8)|(x<<8))
#define LO(x)	(x&0xFF)

static uint8_t radiotext_strText[];
static uint8_t radiotext_strPS[];

//0x2349211c
uint8_t radiotext_bBufferIndex = 0; //2349211c +0
uint8_t radiotext_bMarker = 0xfe; //2349211d +1
uint16_t radiotext_writePtr = 0; //2349211e +2
uint8_t* radiotext_pBuffer = 0; //23492120 +4
uint32_t radiotext_readPtr = 0; //23492124 +8
OS_EVENT* radiotext_sema/*sem*/ = 0; //23492128 +0x0c
int radiotext_channel = -1; //2349212C +0x10
struct
{
	uint8_t* pBuffer; //0
	uint32_t nSize; //4
	//8
} 
radiotext_BufferList[] = //23492130
{
	{&radiotext_strText[0], 256}, 
	{&radiotext_strPS[0], 9}
};

uint8_t radiotext_charTranslation[] = //23492140
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x20, 0x21, 0x22, 0x23, 0xab, 0x25, 0x26, 0x27,
	0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
	0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
	0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
	0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
	0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
	0x27, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
	0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
	0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x00,
};


uint8_t radiotext_arBuffers[4][0x100]; //235b1198
uint8_t radiotext_strText[0x100]; //235b1598
uint8_t radiotext_strPS[0x100]; //235b1698


void radiotext_parse_rds(uint8_t* r0, uint16_t r1);


/* 2341a42c / / 2347bd7c - todo */
uint8_t radiotext_decode(uint8_t* r4, uint8_t b)
{
	uint8_t err;
	int ret;

#if 0
	console_send_string("radiotext_decode (todo.c): TODO\r\n");
#endif

#if 0
	hex_dump("radiotext_decode", r4, b);
#endif

	if (r4[0] == 10) //Radio Text
	{
		OSSemPend(radiotext_sema, 0, &err);

		memset(&radiotext_strText[0], 0, 0x100);
		memcpy(&radiotext_strText[0], &r4[5], r4[3] - 1);

		OSSemPost(radiotext_sema);

		ret = r4[3] + 4;
		return ret;
	}
	else if (r4[0] == 2) //PS
	{
		//0x2341a490
		OSSemPend(radiotext_sema, 0, &err);

		radiotext_strPS[0] = r4[3];
		radiotext_strPS[1] = r4[4];
		radiotext_strPS[2] = r4[5];
		radiotext_strPS[3] = r4[6];
		radiotext_strPS[4] = r4[7];
		radiotext_strPS[5] = r4[8];
		radiotext_strPS[6] = r4[9];
		radiotext_strPS[7] = r4[10];
		radiotext_strPS[8] = 0;

		OSSemPost(radiotext_sema);

		return 11;
	}
	else if (r4[0] == 3) //?
	{
		return 4;
	}
	else if (r4[0] == 0x30) //TMC?
	{
		ret = r4[1] + 2;
		return ret;
	}
	else
	{
		return b;
	}
}


/* 2341a520 - todo */
void radiotext_check_data(int channel)
{
	uint8_t err;
	uint32_t remainingBytes; //r5

#if 0
	console_send_string("radiotext_check_data (todo.c): TODO\r\n");
#endif

	AUDEC_RadioText* pAudecRadiotext = main_hAudecRadioText;
	if (pAudecRadiotext == 0)
	{
		//->loc_2341a648
		return;
	}

	if (channel != radiotext_channel)
	{
		OSSemPend(radiotext_sema, 0, &err);

		radiotext_strText[0] = 0;
		radiotext_strPS[0] = 0;

		OSSemPost(radiotext_sema);

		radiotext_channel = channel;
	}
	//loc_2341a578
#if 0
	hex_dump("radiotext_check_data", 
		pAudecRadiotext->Data_4, pAudecRadiotext->Data_0);
#endif

	remainingBytes = (pAudecRadiotext->Data_0 - radiotext_readPtr) 
		% sizeof(pAudecRadiotext->Data_4);
	if (remainingBytes != 0)
	{
		uint8_t* pbData = pAudecRadiotext->Data_4;
		//->loc_2341a640
		while (remainingBytes--)
		{
			//loc_2341a594
			uint8_t r1 = radiotext_readPtr + 1;
			uint8_t ch = pbData[radiotext_readPtr];
			radiotext_readPtr = r1 % 0x100;

			if (radiotext_bMarker == ch)
			{
				if (radiotext_bMarker == 0xfe) //Start Code
				{
					//0x2341a5bc
					radiotext_bMarker = 0xff; //Stop Code
					radiotext_writePtr = 0;

					uint8_t r2 = radiotext_bBufferIndex + 1;
					radiotext_pBuffer = radiotext_arBuffers[radiotext_bBufferIndex];
					radiotext_bBufferIndex = r2 % 4;
					//loc_2341a5e4
				}
				else
				{
					//loc_2341a608
					if (radiotext_pBuffer != 0)
					{
						//0x2341a614
						radiotext_pBuffer[radiotext_writePtr++] = ch;

						radiotext_parse_rds(radiotext_pBuffer, radiotext_writePtr);
					}
					//loc_2341a634
					radiotext_pBuffer = 0;
					radiotext_bMarker = 0xfe;
					continue;
				}
			}
			//loc_2341a5e4
			if (radiotext_pBuffer != 0)
			{
				radiotext_pBuffer[radiotext_writePtr] = ch;
				radiotext_writePtr = (radiotext_writePtr + 1) % 0x100;
			}
			//->loc_2341a640
		} //while (remainingBytes--)
	}
	//loc_2341a648
}


/* 2341a64c - todo */
void radiotext_get_string(int iText/*sb*/, uint8_t* pTextBuffer/*r4*/, uint32_t nTextBufSize)
{
#if 0
	console_send_string("radiotext_get_string (todo.c): TODO\r\n");
#endif

	uint8_t err; //sp4

	uint32_t r5 = 0;
	uint8_t* r8 = pTextBuffer;
	uint32_t r6 = 0;
	uint32_t r7 = 0;
	uint8_t* pBuffer = radiotext_BufferList[iText].pBuffer;
	uint32_t nBufSize = radiotext_BufferList[iText].nSize;

	OSSemPend(radiotext_sema, 0, &err);

	//->loc_2341a6e4
	while ((pTextBuffer - r8) < (nTextBufSize - 1))
	{
		//loc_2341a69c
		uint8_t ch = pBuffer[r5];

		if ((ch == 0) || (r5 > nBufSize))
		{
			//->loc_2341a6f0
			break;
		}
		//0x2341a6b0
		if (ch > ' ')
		{
			r6 = 0;
			r7 = 4;
			ch = radiotext_charTranslation[ch];
			//->loc_2341a6dc
		}
		else
		{
			//0x2341a6c8
			r6++;
			if (r6 >= r7)
			{
				r5++;
				r6++;
				//->loc_2341a6e4
				continue;
			}
		}
		//loc_2341a6dc
		r5++;
		*pTextBuffer++ = ch;
		//loc_2341a6e4
	} //while ((pTextBuffer - r8) < (c - 1))
	//loc_2341a6f0
	*pTextBuffer = 0;

	OSSemPost(radiotext_sema);

	if (iText == RDS_RADIOTEXT)
	{
		//0x2341a70c
		uint32_t lineSize = pTextBuffer - r8;

		if ((lineSize != 0) && (lineSize < 12))
		{
			//0x2341a71c
			for (uint32_t i = 0; i < (12 - lineSize); i++)
			{
				//loc_2341a728
				*pTextBuffer++ = ' ';
			}
		}
		//loc_2341a738
		*pTextBuffer = 0;
	}
	//loc_2341a73c
}


/* 2341a744 - todo */
void radiotext_init(void)
{
#if 0
	console_send_string("radiotext_init (todo.c): TODO\r\n");
#endif

	radiotext_sema = OSSemCreate(1);
}


/* 2341a75c - todo */
void radiotext_parse_rds(uint8_t* pbData, uint16_t b)
{
	uint8_t lr;
	uint8_t ip = b;
	uint32_t r3 = ip;
	uint8_t* r1 = pbData;
	uint8_t* r2 = pbData;
	uint8_t sp[] = {0xfd, 0xfe, 0xff, 0x00};

#if 0
	console_send_string("radiotext_parse_rds (todo.c): TODO\r\n");
#endif

#if 0
	hex_dump("radiotext_parse_rds", pbData, b);
#endif

	//->loc_2341a7c0
	while (r3--)
	{
		//loc_2341a784
		if ((r1[0] == 0xfd) && (r1[1] < 3))
		{
			//0x2341a79c
			lr = sp[r1[1]];
			r1 += 2;
			r3--;
			ip--;
			*r2++ = lr;
			//->loc_2341a7c0
		}
		else
		{
			//loc_2341a7b8
			*r2++ = r1[0];
			r1++;
		}
		//loc_2341a7c0
	}
	//0x2341a7c8
	uint8_t* r3_ = pbData + 1;
	uint8_t lr_ = ip - 4;
	uint32_t crc = 0xffff;
	uint32_t r1_ = 0;
	//->loc_2341a80c
	while (r1_ < lr_)
	{
		//loc_2341a7e0
		crc = (crc >> 8) | (crc << 8);
		crc ^= r3_[r1_++];
		crc ^= ((crc & 0xff) >> 4);
		crc ^= (crc << 12);
		crc &= 0xffff;
		crc ^= ((crc & 0xff) << 5);
	}
	//0x2341a814
	crc ^= 0xff00;
	crc ^= 0xff;
	uint8_t* r5 = pbData + 5;
	uint32_t crc_read = ((pbData[ip - 3] << 8) | pbData[ip - 2]);

	if (crc == crc_read)
	{
		int16_t r4 = pbData[4];

		while (r4 > 0)
		{
			int r0 = radiotext_decode(r5, r4);
			r5 += r0;
			r4 -= r0;
		}
	}
}


