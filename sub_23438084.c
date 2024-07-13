

#include "data.h"
#include "flash.h"
#include "sub_23438084.h"


Struct_235f3784 Data_235f3784[4]; //235f3784


/* 23437d9c - todo */
//crc32
void sub_23437d9c(uint32_t* a, uint8_t* b, uint32_t c)
{
#if 0
	console_send_string("sub_23437d9c (todo.c): TODO\r\n");
#endif

	//->loc_23437de0
	while (c--)
	{
		//loc_23437da8
		uint8_t bit;
		for (bit = 0x80; bit != 0; bit >>= 1)
		{
			//loc_23437dac
			if (((*((uint8_t*)a) * bit) & bit) != (*b & bit))
			{
				*a = (*a >> 1) ^ 0xedb88320;
			}
			else
			{
				*a = (*a >> 1);
			}
		}

		b++;
	}
}


/* 23437dec - todo */
int sub_23437dec(Struct_235f3784* r5)
{
	uint8_t sp_0xc;
	int32_t sp8 = r5->Data_0.length;
	uint8_t* sl = r5->Data_0.data;
	uint32_t fp;
	uint32_t sb;
	uint16_t r8;
	Struct_235f2e2c* pFlash = r5->Data_0.pFlash; //r7
	uint32_t sp4 = r5->Data_0.Data_16;

#if 0
	console_send_string("sub_23437dec (todo.c): TODO\r\n");
#endif

	if (pFlash->sema != 0)
	{
		//0x23437e14
		OSSemPend(pFlash->sema, 0, &sp_0xc);
		if (sp_0xc != 0)
		{
			//loc_23437fb8
			return sp_0xc;
		}
	}
	//loc_23437e2c -> loc_23437f9c
	for (r8 = 0; r8 < pFlash->numSectors; r8++)
	{
		//->loc_23437e34
		uint32_t sb = pFlash->Data_0x20[r8].Data_0;
		if (sb >= sp4)
//		if (r5->Data_0.Data_16 <= sb)
		{
			//0x23437e4c
			uint32_t i;
			Struct_235f3784_Inner_0x18* r4 = 0;
			for (i = 0; i < 10; i++)
			{
				//loc_23437e54
				if (r5->Data_24[i].pData == 0)
				{
					r5->Data_24[i].pData = sl;

					r4 = &r5->Data_24[i];
					//->loc_23437e84
					break;
				}
			} //for (i = 0; i < 10; i++)
			//loc_23437e84
			if (r4 == 0)
			{
				//->loc_23437fc0
				if (pFlash->sema != 0)
				{
					OSSemPost(pFlash->sema);
				}

				return 0xff;
			} //if (r4 == 0)
			//0x23437e8c
			r4->Data_8 = pFlash->Data_0x20[r8].Data_0;
			r4->Data_12 = pFlash->Data_0x20[r8].Data_4;
			r4->Data_16 = 0;

			fp = (r4->Data_12 - r4->Data_8 + 1) / r5->Data_0.Data_20;
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "fp=%d, r4->Data_8=%x, r4->Data_12=%x, r5->Data_0.Data_20=%d\r\n",
						fp, r4->Data_8, r4->Data_12, r5->Data_0.Data_20);
				console_send_string(debug_string);
			}
#endif
			//->loc_23437f28
			while (fp--)
			{
				//loc_23437ec0 -> loc_23437f14
				uint16_t r6;
				for (r6 = 0; r6 < r5->Data_0.Data_20; r6 += 4)
				{
					//loc_23437ec8
					uint32_t sp;
					(pFlash->Data_8.read_dwords)(sb + r6, 4, &sp);

#if 0
					{
						extern char debug_string[];
						sprintf(debug_string, "sp=0x%08x\r\n", sp);
						console_send_string(debug_string);
					}
#endif

					if (sp != 0xffffffff)
					{
						//0x23437ef0
						r4->Data_16 = (r4->Data_16 + r5->Data_0.Data_20) & (r4->Data_12 - r4->Data_8);
#if 0
						{
							extern char debug_string[];
							sprintf(debug_string, "r6=%d, r4->Data_16=%d\r\n", r6, r4->Data_16);
							console_send_string(debug_string);
						}
#endif
						//->loc_23437f20
						break;
					} //if (sp != 0xffffffff)
					//->loc_23437f14
				} //for (r6 = 0; r6 < r5->Data_0.Data_20; r6 += 4)
				//loc_23437f20
				sb += r5->Data_0.Data_20;
			} //while (fp--)
			//0x23437f30
			{
				int r0 = r4->Data_16 - r5->Data_0.Data_20;
				if (r0 < 0)
				{
					r0 = r4->Data_12 - r4->Data_8 + r0 + 1;
				}

				(pFlash->Data_8.read_dwords)(r0 + pFlash->Data_0x20[r8].Data_0,
						r5->Data_0.Data_20,
						sl);

#if 0
				for (i = 0; i < r5->Data_0.Data_20; i++)
				{
					extern char debug_string[];
					sprintf(debug_string, "sl[%d]=0x%02x\r\n", i, sl[i]);
					console_send_string(debug_string);
				}
#endif

				sub_23437d9c(&r4->crc, sl, r5->Data_0.Data_20);

				sl += r5->Data_0.Data_20;
				sp8 -= r5->Data_0.Data_20;
			}
		} //if (sp4 < sb)
#if 0
		else
		{
			r0 = sp8;
			//->loc_23437f8c
		}
#endif
		//loc_23437f8c
		if (sp8 <= 0)
		{
			//->loc_23437fa8
			break;
		}
	} //for (r8 = 0; r8 < pFlash->numSectors; r8++)
	//loc_23437fa8
	if (pFlash->sema != 0)
	{
		OSSemPost(pFlash->sema);
	}

	return 0;
}


/* 23437fd4 - complete */
void* sub_23437fd4(Struct_23437fd4* r5)
{
	uint8_t err;
	Struct_235f3784* h = &Data_235f3784[0];
	uint8_t i = 4;
#if 0
	console_send_string("sub_23437fd4 (todo.c): TODO\r\n");
#endif

	//->loc_2343806c
	while (i--)
	{
		//loc_23437fe8
		if (h->Data_0.sema == 0)
		{
			h->Data_0.sema = OSSemCreate(1);

			if (h->Data_0.sema == 0)
			{
				//->loc_2343807c
				return 0;
			}
			//0x23438008
			h->Data_0.length = r5->Data_8;
			h->Data_0.data = r5->Data_16;
			h->Data_0.Data_16 = r5->Data_4;
			h->Data_0.Data_20 = r5->Data_0;
			h->Data_0.pFlash = r5->pFlash;

			memset(h->Data_24, 0, 10*20);

			if (0 == sub_23437dec(h))
			{
				return h;
			}
			else
			{
				h->Data_0.sema = (void*) OSSemDel(h->Data_0.sema, 1, &err);
				//->loc_2343807c
				return 0;
			}
		}
		//loc_23438068
		h++;
	}
	//loc_2343807c
	return 0;
}


/* 23438084 - todo */
int sub_23438084(Struct_23438084* p, void* buf, uint32_t offset, uint32_t count)
{
	uint8_t err;

#if 0
	console_send_string("sub_23438084 (todo.c): TODO\r\n");
#endif

	if (p != 0)
	{
		OSSemPend(p->sema, 0, &err);

		if (err == 0)
		{
			if ((offset + count) > p->length)
			{
				OSSemPost(p->sema);
				return 0xff;
			}
			else
			{
				uint8_t* src = p->data + offset;
				uint8_t* dest = buf;
				//->loc_234380f0
				for (; count-- > 0; dest++)
				{
					//loc_234380e0
					*dest = *src++; //TODO
				}

				OSSemPost(p->sema);
			}
		}
	}
	//loc_23438100
	return 0;
}


/* 23438108 - todo */
int sub_23438108(Struct_23438084* p, void* buf, uint32_t offset, uint32_t count)
{
#if 1
	console_send_string("sub_23438108 (todo.c): TODO\r\n");
#endif

}


/* 23438194 - complete */
int sub_23438194(Struct_235f3784* r5)
{
	uint32_t i; //r4
	uint8_t err1;
	uint8_t err2;
	Struct_235f2e2c* pFlash/*r6*/ = r5->Data_0.pFlash;

	if (r5 != 0)
	{
		OSSemPend(r5->Data_0.sema, 0, &err1);

		if (err1 == 0)
		{
			if (pFlash->sema != 0)
			{
				OSSemPend(pFlash->sema, 0, &err2);

				if (err2 != 0)
				{
					return err2;
				}
			}
			//loc_234381e4
			for (i = 0; i < 10; i++)
			{
				//loc_234381e8
				if (r5->Data_24[i].pData == 0)
				{
					//->loc_23438214
					break;
				}
				//0x234381fc
				(pFlash->Data_8.Data_12)(r5->Data_24[i].Data_8);
			}
			//loc_23438214
			if (pFlash->sema != 0)
			{
				OSSemPost(pFlash->sema);
			}

			memset(r5->Data_24, 0, 10*20);

			sub_23437dec(r5);

			OSSemPost(r5->Data_0.sema);
		}
		//loc_2343823c
	}
	//loc_2343823c
	return 0;
}

