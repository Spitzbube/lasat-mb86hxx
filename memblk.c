
#include "data.h"


typedef struct Struct_234920a0_Inner
{
	struct Struct_234920a0_Inner* Data_0; //0
	struct Struct_234920a0_Inner* Data_4; //4
	//8
} Struct_234920a0_Inner;

extern Struct_234920a0_Inner Data_234920ac;
extern Struct_234920a0_Inner Data_234920b4;
extern Struct_234920a0_Inner Data_234920bc;

struct Struct_234920a0
{
	int Data_0; //0
	struct Struct_234920a0* Data_4; //4
	uint32_t Data_8; //8

};

Struct_234920a0_Inner* Data_234920a0[3] = //234920a0
{
		&Data_234920ac,
		&Data_234920b4,
		&Data_234920bc
};

Struct_234920a0_Inner Data_234920ac = //234920ac
{
		&Data_234920ac, &Data_234920ac
};

Struct_234920a0_Inner Data_234920b4 = //234920b4
{
		&Data_234920b4, &Data_234920b4
};

Struct_234920a0_Inner Data_234920bc = //234920bc
{
		&Data_234920bc, &Data_234920bc
};


MemBlk_Handle memblk_handles[3]; //2358be2c


void sub_2341180c(Struct_234920a0_Inner*);
static void _memblk_free(Struct_234920a0_Inner*, int*);
static void _memblk_init(uint32_t, uint32_t, Struct_234920a0_Inner*);
static void sub_23411920(Struct_234920a0_Inner*, Struct_234920a0_Inner*);


/* 234115f8 - todo */
void* memblk_alloc(void* h, uint32_t size)
{
	MemBlk_Handle* r5 = h;
	uint8_t sp;

#if 0
	console_send_string("memblk_alloc (todo.c): TODO\r\n");
#endif

	OSSemPend(r5->sema, 0, &sp);

	if (size < 12)
	{
		size = 12;
	}

	size = ((size + 7) / 8) * 8;

	Struct_234920a0_Inner* r0 = Data_234920a0[r5->idx];

	uint32_t r2;
	if (size < 12)
	{
		r2 = 12;
	}
	else
	{
		r2 = size;
	}

	r2 = ((r2 + 7) / 8) * 8;

	struct Struct_234920a0* r4 = 0;
	struct Struct_234920a0* r1 = (void*) r0->Data_4;
	while (1)
	{
		//loc_2341164c
		if ((void*)r1 == (void*)r0)
		{
			//->loc_23411668
			break;
		}
		//0x23411654
		if (r2 > r1->Data_8)
		{
			r1 = r1->Data_4;
			//->loc_2341164c
		}
		else
		{
			r4 = r1;
			//loc_23411668
			break;
		}
	}
	//loc_23411668
	//r6 = 0;
	uint32_t* r1_;
	if (r4 != 0)
	{
		//0x23411678
		if ((r4->Data_8 - r2) < 12)
		{
			r2 = r4->Data_8;
		}

		if (r4->Data_8 == r2)
		{
			//0x23411690
			sub_2341180c((Struct_234920a0_Inner*) r4);
			//->loc_234116c0
		}
		else
		{
			//loc_2341169c
			r4->Data_8 -= (r2 + 8);

			r4 = (void*) ((((uint32_t)r4) + r4->Data_8 + 8) & ~3);

			r4->Data_4 = 0; //r6
			r4->Data_8 = r2;
			r4->Data_0 = 0; //r6
		}
		//loc_234116c0
		r1_ = &r4->Data_8;
		r4->Data_0 = r4->Data_8;
	}
	else
	{
		r1_ = 0;
	}
	//loc_234116cc
	void* r8 = r1_;

	uint32_t r2_ = size % 4;
	uint32_t r0_ = size / 4;
	//loc_234116d8
	while (r0_--)
	{
		*r1_++ = 0; //r6
	}
	//loc_234116f0
	while (r2_--)
	{
		//loc_234116ec
		*((uint8_t*)r1_)++ = 0; //r6
	}

	OSSemPost(r5->sema);

	return r8;
}


/* 23411708 - complete */
int memblk_free(void* h, void* r5)
{
	MemBlk_Handle* r4 = h;
	uint8_t sp;

#if 0
	console_send_string("memblk_free (todo.c): TODO\r\n");
#endif

	if (r5 != 0)
	{
		OSSemPend(r4->sema, 0, &sp);

		_memblk_free(Data_234920a0[r4->idx], r5);

		OSSemPost(r4->sema);
	}

	return 0;
}


/* 2341174c - complete */
MemBlk_Handle* memblk_open(MemBlk_Params* r5)
{
#if 0
	console_send_string("memblk_open (todo.c): TODO\r\n");
#endif

	uint8_t i;
	MemBlk_Handle* h = 0;

	for (i = 0; i < 3; i++)
	{
		//loc_23411760
		if (memblk_handles[i].sema == 0)
		{
			h = &memblk_handles[i];

			h->idx = i;
			h->addr = r5->addr;
			h->size = r5->size;
			//->loc_23411794
			break;
		}
	}

	if (h != 0)
	{
		h->sema = OSSemCreate(1);
		if (h->sema == 0)
		{
			h = 0;
		}
		else
		{
			_memblk_init(r5->addr, r5->size, Data_234920a0[h->idx]);
		}
	}

	return h;
}


/* 234117d0 - complete */
int memblk_init(void* h)
{
#if 0
	console_send_string("memblk_init (todo.c): TODO\r\n");
#endif

	uint8_t sp;
	MemBlk_Handle* r4 = h;

	OSSemPend(r4->sema, 0, &sp);

	_memblk_init(r4->addr, r4->size, Data_234920a0[r4->idx]);

	OSSemPost(r4->sema);

	return 0;
}


#if 1
/* 2341180c - complete */
void sub_2341180c(Struct_234920a0_Inner* r0)
{
	r0->Data_4->Data_0 = r0->Data_0;
	r0->Data_0->Data_4 = r0->Data_4;
}
#endif


void sub_23411920(Struct_234920a0_Inner* r0, Struct_234920a0_Inner* r1)
{
	r0->Data_0 = r1->Data_0;
	r1->Data_0 = r0;

	r0->Data_0->Data_4 = r0;
	r0->Data_4 = r1;
}


/* 234118f8 / 23418894 - complete */
void _memblk_init(uint32_t addr, uint32_t size, Struct_234920a0_Inner* r1)
{
#if 0
	console_send_string("_memblk_init (todo.c): TODO\r\n");
#endif

	uint32_t end = addr + size;

	addr = addr + 16;

	((struct Struct_234920a0*)addr)->Data_8 = end - addr - 7;

	r1->Data_0 = r1;
	r1->Data_4 = r1;

	sub_23411920((void*) addr, r1);
}


/* 23411820 - todo */
void _memblk_free(Struct_234920a0_Inner* a, int* b)
{
#if 0
	console_send_string("_memblk_free (todo.c): TODO\r\n");
#endif

	int* ip = b - 2;
	ip[2] = ip[0];

	struct Struct_234920a0* r3 = (void*) a->Data_0;
	int r1 = (((uint32_t)ip) + /*r2*/ip[2] + 8) & ~3;

	while (1)
	{
		//loc_23411840
		if ((void*)r3 == (void*)a)
		{
			r1 = (int) a->Data_4;
			//->loc_234118ec
			break;
		}
		//0x2341184c
		if ((void*)r3 == (void*)r1)
		{
			//0x23411854
			void* r4 = r3->Data_4;

			sub_2341180c((void*) r3);

			ip[2] += (r3->Data_8 + 8);

			r1 = (int) r4;
			//->loc_234118ec
			break;
		}
		//loc_2341187c
		//void* lr = (void*) ((((uint32_t)r3) + r3->Data_8 + 8) & ~3);
		if ((void*) ((((uint32_t)r3) + r3->Data_8 + 8) & ~3) == ip)
		{
			//0x23411894
			r3->Data_8 += (ip[2] + 8);

			int ip = r3->Data_0;
			int r0 = (((uint32_t)r3) + r3->Data_8 + 8) & ~3;

			if (r0 == ip)
			{
				sub_2341180c((void*) ip);

				r3->Data_8 += ( ((uint32_t*)ip)[2] + 8 );
			}
			return;
		}
		//loc_234118dc
		if ((uint32_t) ip >= (uint32_t) r3)
		{
			r3 = (void*) r3->Data_0;
			//->loc_23411840
		}
		else
		{
			r1 = (int) r3->Data_4;
			//loc_234118ec
			break;
		}
	}
	//loc_234118ec
	sub_23411920((void*) ip, (void*) r1);
}

