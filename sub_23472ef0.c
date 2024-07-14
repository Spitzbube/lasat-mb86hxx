


#include "data.h"
#include "sub_2340a6a0.h"
#include "Struct_23443080.h"
#include "m88dc2800.h"


#pragma thumb



/* 23472ef0 - complete */
int sub_23472ef0(int r7, int r5, Struct_23472f1c_Inner16* r6, Struct_23472f1c* r4)
{
#if 0
	console_send_string("sub_23472ef0 (todo.c): TODO\r\n");
#endif

	if ((r4 == 0) || (r6 == 0))
	{
		return 1;
	}

	memset(r4, 0, 0x5c);

	r4->bData_13 = r5;
	r4->bData_14 = r5 + 4;
	r4->Data_0 = r7;
	r4->Data_16 = r6;
	r4->Data_4 = 0;

	return 0;
}

/* 23472f1c - todo */
int sub_23472f1c(Struct_23472f1c* r4)
{
	int res;

	if (r4 == 0)
	{
		return 1;
	}

	r4->Data_4 = 0;
	r4->Data_8 = 0;
	r4->bData_12 = 0;
	r4->Data_0x44 = 1;
	r4->bData_0x54 = 0x1a;

	if (r4->Data_0 == 1)
	{
		if (0 != (r4->Data_16->i2c_write_reg_byte)(r4->Data_16, r4->bData_14, 0x00, 0x00))
		{
			//->loc_23472fb4
			return 2;
		}

		if (0 != (r4->Data_16->i2c_write_reg_byte)(r4->Data_16, r4->bData_14, 0x00, 0x0f))
		{
			//->loc_23472fb4
			return 2;
		}

		if (0 != (r4->Data_16->i2c_write_reg_byte)(r4->Data_16, r4->bData_14, 0x14, 0x01))
		{
			//->loc_23472fb4
			return 2;
		}

		if (0 != (r4->Data_16->i2c_write_reg_byte)(r4->Data_16, r4->bData_14, 0x11, 0x00))
		{
			//->loc_23472fb4
			return 2;
		}

		if (0 != (r4->Data_16->i2c_write_reg_byte)(r4->Data_16, r4->bData_14, 0x14, 0x00))
		{
			//->loc_23472fb4
			return 2;
		}

		sub_23402130(0, 1);
	}
	//loc_23472f94
	if (0 != (r4->Data_16->i2c_write_reg_byte)(r4->Data_16, r4->bData_13, 0x00, 0x00))
	{
		//->loc_23472fb4
		return 2;
	}

	if (0 != (r4->Data_16->i2c_write_reg_byte)(r4->Data_16, r4->bData_13, 0x02, 0x00))
	{
		//->loc_23472fb4
		return 2;
	}
	//loc_23472fb8
	if (0 != (r4->Data_16->i2c_write_reg_byte)(r4->Data_16, r4->bData_13, 0xfe, 0x01))
	{
		r4->Data_4 = 4;
		//->loc_23472fb4
		return 2;
	}
	//loc_23472fce
	res = sub_234420fc(r4, &r4->Data_0x4c);
	if (0 != res)
	{
		r4->Data_4 = 4;

		return res;
	}
	//loc_23472fe0
#if 0
	if (r4->Data_0x4c == 0x28)
	{
		r4->Data_4 = 4;
		//loc_23472fee
		res = 8;
	}
	else if ((r4->Data_0x4c == 0x25) || (r4->Data_0x4c == 0x27))
	{
		r4->Data_4 = 2;
	}
	else
	{
		//loc_23472fee
		res = 8;
	}
#else
	switch (r4->Data_0x4c)
	{
	case 0x25:
	case 0x27:
		//loc_23472ff6
		r4->Data_4 = 2;
		break;

	case 0x28:
		//loc_23472ff2
		r4->Data_4 = 4;
		//loc_23472fee
		res = 8;
		break;

	default:
		//loc_23472fee
		res = 8;
		break;
	}

	return res;
#endif
}


/* 23476318 - todo */
int sub_23476318(uint8_t r5, int r1, void* r2, int r3, int r6, Struct_23476318* r4)
{
#if 0
	console_send_string("sub_23476318 (todo.c): TODO\r\n");
#endif

	if ((r4 == 0) || (r2 == 0))
	{
		return 1;
	}
	//loc_2347632c
	if ((r1 != 0x29) && (r1 != 0x04) && (r1 != 0x10))
	{
		return 8;
	}
	else
	{
		//loc_2347633c
		r4->Data_4 = 0;
		r4->Data_12 = 0;
		r4->Data_8 = 0;
		r4->Data_0 = 0;
		r4->bData_0x18 = r5;
		r4->Data_0x20 = r6;
		r4->Data_0x1c = r3;
		r4->Data_0x14 = r2;
		r4->Data_0x10 = r1;

		return 0;
	}
}


