

#include "data.h"
#include "videc.h"


/* 23477360 - todo */
int sub_23477360(uint8_t* ip, int b, int* r2, int r3)
{
#if 0
	console_send_string("sub_23477360 (todo.c): TODO\r\n");
#endif

	int r5 = b >> 3;
	int r1 = 7 - (b & 0x07);
	int r0 = 1;
	int lr = 0;
	ip += r5;
	//->loc_234773a8
	while (((*ip >> r1) & 1) == 0)
	{
		//loc_23477384
		r1 = (r1 - 1) & 0x07;

		int r4;
		if (r1 == 7)
		{
			r4 = 1;
		}
		else
		{
			r4 = 0;
		}

		lr++;
		r0++;
		ip += r4;
		r5 += r4;
	}

	int r4 = lr + 7;
	r4 = (r4 >> 3) + r5;

	if (r4 > r3)
	{
		return -1;
	}

	int r3_ = 0;
	//->loc_23477400
	while (lr--)
	{
		//loc_234773d4
		r1 = (r1 - 1) & 0x07;
		ip += (r1 == 7)? 1: 0;
		r0++;
		r3_ = ((*ip >> r1) & 1) | (r3_ << 1);
	}

	*r2 = r3_;

	return r0;
}


/* 23477410 - todo */
int sub_23477410(uint8_t* r4, int b, int* r2, uint32_t r3, int ip)
{
#if 0
	console_send_string("sub_23477410 (todo.c): TODO\r\n");
#endif

	int res;

	uint32_t lr = b & 0x07;
	int r1 = b >> 3;
	res = ip;

	if ((r1 + ((ip + lr) >> 3)) > r3)
	{
		return -1;
	}

	int r3_ = 7 - lr;
	lr = 0;
	r4 += r1;

	while (1)
	{
		ip--;
		if (ip == -1)
		{
			break;
		}

		uint8_t bData = *r4;
		bData = bData >> r3_;
		r3_--;
		bData = bData & 1;
		r4 = r4 - (r3_ >> 3);
		lr = (lr << 1) | bData;
		r3_ = r3_ & 0x07;
	}

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_234774c4(1): b=%d, lr=0x%x\r\n",
				b, lr);
		console_send_string(debug_string);
	}
#endif

	*r2 = lr;

	return res;
}


/* 23477478 - complete */
void sub_23477478(int* r5, int r6, uint8_t* r8)
{
#if 0
	console_send_string("sub_23477478 (todo.c): TODO\r\n");
#endif

	int sp;

	for (uint32_t i = 0; i < r6; i++)
	{
		//loc_23477494
		*r5 += sub_23477360(r8, *r5, &sp, 0xffff);
	}
}


/* 234774c4 - complete */
int sub_234774c4(uint8_t* r7, Struct_234774c4* r4)
{
#if 0
	console_send_string("sub_234774c4 (todo.c): TODO\r\n");
#endif

	int sp8;
	int sp4 = 0;

	sp4 = sub_23477410(r7, sp4, &sp8, 0xffff, 8);

	r4->Data_4 = sp8;

	if ((r4->Data_4 == 0x42) ||
			(r4->Data_4 == 0x4d) ||
			(r4->Data_4 == 0x58) ||
			(r4->Data_4 == 0x64) ||
			(r4->Data_4 == 0x6e) ||
			(r4->Data_4 == 0x7a) ||
			(r4->Data_4 == 0xf4) ||
			(r4->Data_4 == 0x2c))
	{
		sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

		r4->bData_8 = sp8;

		sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

		r4->bData_9 = sp8;

		sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

		r4->bData_10 = sp8;

		sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

		r4->bData_11 = sp8;

		sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 4);

		sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 8);

		r4->Data_12 = sp8;

		sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

		r4->Data_16 = sp8;
		r4->Data_20 = 1; //r8
		r4->Data_0x7d8 = 0; //r5
		r4->Data_0x7dc = 0; //r5

		if ((r4->Data_4 == 0x64) ||
				(r4->Data_4 == 0x6e) ||
				(r4->Data_4 == 0x7a) ||
				(r4->Data_4 == 0xf4) ||
				(r4->Data_4 == 0x2c))
		{
			//0x23477690
			sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

			r4->Data_20 = sp8;

			if (r4->Data_20 == 3)
			{
				//0x234776bc
				sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);
			}
			//loc_234776e0
			sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

			r4->Data_0x7d8 = sp8;

			sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

			r4->Data_0x7dc = sp8;

			sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

			sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

			r4->bData_24 = sp8;

			if (r4->bData_24 != 0)
			{
				//0x23477784
				uint32_t sb = (r4->Data_20 != 3)? 8: 12;
				//->loc_234777f4
				for (uint32_t r5 = 0; r5 < sb; r5++)
				{
					//loc_2347779c
					sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

					r4->Data_28[r5] = sp8;

					if (r4->Data_28[r5] != 0)
					{
						//0x234777d8
						if (r5 < 6)
						{
							sub_23477478(&sp4, 0x10, r7);
						}
						else
						{
							sub_23477478(&sp4, 0x40, r7);
						}
					}
					//loc_234777f0
				} //for (uint32_t r5 = 0; r5 < sb; r5++)
			}
			//loc_234777fc
		}
		//loc_234777fc
		sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

		r4->Data_0x7e0 = sp8;

		sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

		r4->Data_0x7e4 = sp8;

		if (r4->Data_0x7e4 == 0)
		{
			//0x23477850
			sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

			r4->Data_0x7e8 = sp8;
			//->loc_2347795c
		}
		//loc_23477878
		else if (r4->Data_0x7e4 == 1)
		{
			//0x23477880
			sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

			r4->Data_0x7ec = sp8;

			sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

			r4->Data_0x7f0 = sp8;

			sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

			r4->Data_0x7f4 = sp8;

			sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

			r4->Data_0x7f8 = sp8;
			//->loc_23477950
			for (uint32_t r5 = 0; r5 < r4->Data_0x7f8; r5++)
			{
				//loc_23477920
				sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

				r4->Data_0x7fc[r5] = sp8;
			}
			//loc_2347795c
		}
		//loc_2347795c
		sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

		r4->Data_0xbfc = sp8;

		sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

		r4->bData_0xc00 = sp8;

		sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

		r4->Data_0xc04 = sp8;

		sp4 += sub_23477360(r7, sp4, &sp8, 0xffff);

		r4->Data_0xc08 = sp8;

		sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

		r4->bData_0xc0c = sp8;

		if (r4->bData_0xc0c == 0)
		{
			//0x23477a2c
			sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

			r4->bData_0xc0d = sp8;
		}
		//loc_23477a58
		sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

		r4->bData_0xc0e = sp8;

		sp4 += sub_23477410(r7, sp4, &sp8, 0xffff, 1);

		r4->bData_0xc0f = sp8;

		r4->bData_0 = 1; //r8

		return 0;
	}
	else
	{
		//loc_23477abc
		return 0xff;
	}
}


