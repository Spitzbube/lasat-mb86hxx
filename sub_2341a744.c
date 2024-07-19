
#include "data.h"
#include "ucos_ii.h"


//0x2349211c
#if 0
uint8_t bData_2349211c = 0; //2349211c +0
uint8_t bData_2349211d = 0; //2349211d +1
uint16_t wData_2349211e = 0; //2349211e +2
uint8_t* Data_23492120 = 0; //23492120 +4
uint32_t Data_23492124 = 0; //23492124 +8
#endif
OS_EVENT* Data_23492128/*sem*/ = 0; //23492128 +0x0c
#if 0
int Data_2349212c = 0; //2349212C +0x10

uint8_t Data_235b1198[4][0x100];

struct
{
	uint8_t bData_0; //0
	int fill_4[63]; //4
	//0x100
} Data_235b1598; //235b1598


struct
{
	uint8_t bData_0; //0
	int fill_4[63]; //4

} Data_235b1698; //235b1698


/* 2341a520 - todo */
void sub_2341a520(int r5)
{
	uint8_t sp;

#if 0
	console_send_string("sub_2341a520 (todo.c): TODO\r\n");
#endif

	struct
	{
		int Data_0; //0
		uint8_t Data_4[0x100]; //4

	}* r7 = (void*) Data_23491dec;
	if (r7 == 0)
	{
		//->loc_2341a648
		return;
	}

//	int r6 = 0;

	if (r5 != Data_2349212c)
	{
		OSSemPend(Data_23492128, 0, &sp);

		Data_235b1598.bData_0 = 0; //r6
		Data_235b1698.bData_0 = 0; //r6

		OSSemPost(Data_23492128);

		Data_2349212c = r5;
	}
	//loc_2341a578
	r5 = (r7->Data_0 - Data_23492124) & 0xff;
	if (r5 != 0)
	{
		uint8_t* r7_ = r7->Data_4;
		//->loc_2341a640
		while (r5--)
		{
			//loc_2341a594
			uint8_t r0 = r7_[Data_23492124++];
			Data_23492124 %= 0x100;

			if (bData_2349211d == r0)
			{
				if (bData_2349211d == 0xfe)
				{
					//0x2341a5bc
					bData_2349211d = 0xff;
					wData_2349211e = 0; //r6

					Data_23492120 = Data_235b1198[bData_2349211c];
					bData_2349211c = (bData_2349211c + 1) & 0x03;
					//loc_2341a5e4
				}
				else
				{
					//loc_2341a608
					if (Data_23492120 != 0)
					{
						//0x2341a614
						Data_23492120[wData_2349211e++] = r0;

						sub_2341a75c(Data_23492120, wData_2349211e);
					}
					//loc_2341a634
					Data_23492120 = 0; //r6
					bData_2349211d = 0xfe;
					continue;
				}
			}
			//loc_2341a5e4
			if (Data_23492120 != 0)
			{
				Data_23492120[wData_2349211e] = r0;
				wData_2349211e = (wData_2349211e + 1) % 0x100;
			}
			//->loc_2341a640
		} //while (r5--)
	}
	//loc_2341a648
}

#endif

/* 2341a744 - todo */
void sub_2341a744()
{
#if 0
	console_send_string("sub_2341a744 (todo.c): TODO\r\n");
#endif

	Data_23492128 = OSSemCreate(1);
}

