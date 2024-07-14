
#include "data.h"
#include "thumb2.h"
#include "sub_2346fac4.h"

#pragma thumb

#if 0

extern Menu_Item Data_23495c4c; //23495c4c
extern int sub_2346fa40();
extern int sub_2346fa54();

extern Menu Data_2349c158; //2349c158

int Data_23495c10 = 0; //23495C10 -4

Menu Data_23495c14 = //23495c14
{
		0x0192, //uint16_t stringId; //0
		&Data_23495c4c, //Menu_Item* Data_4; //4
		&Data_23495c4c, //Menu_Item* Data_8; //8
		0, //Struct_235fdf74_Inner12* Data_0xc; //12 = 0xc
		0, //Struct_235fdf74_Inner16* Data_0x10; //16 = 0x10
		0, //int Data_0x14; //20 = 0x14
		7, //uint8_t maxItem; //0x18 = 24 = 23495C2C
		0, //int8_t currentItem; //0x19 = 23495C2D
		0, //void (*Data_0x1c)(); //0x1c
		sub_2343d4c8, //void (*Data_0x20)(); //0x20
		sub_2346fa40, //void (*Data_0x24)(); //36 = 0x24
		sub_2346fa54, //int (*Data_0x28)(); //0x28
		1, //int Data_0x2c; //44 = 0x2c
		100, //int Data_0x30; //48
		0, //Menu_Item* (*Data_0x34)(struct Menu*); //52
#if 0
		23495c14                        dw         0x0192                               ; DATA XREF=sub_2346f950+8, sub_2346f950+16, sub_2346f9a6+6, sub_2346f9a6+122, sub_2346fa36, sub_2346fa40, sub_2346fa58+36, sub_2346fac4+16, sub_2346fac4+28, sub_2346fac4+40, dword_2346fb20
		23495c16 0000                   movs       r0, r0
		23495c18                        dd         0x23495c4c
		23495c1c                        dd         0x23495c4c
		23495c20                        dd         0x00000000
		23495c24                        dd         0x00000000
		23495c28                        dd         0x00000000
		                            byte_23495c2c:
		23495c2c                        db         0x07                                 ; DATA XREF=sub_2346fa58+42
		                            byte_23495c2d:
		23495c2d                        db         0x00                                 ; DATA XREF=sub_2346f9a6+10, sub_2346fac4+20
		23495c2e 0000                   movs       r0, r0
		23495c30                        dd         0x00000000
		23495c34                        dd         sub_2343d4c8+1
		23495c38                        dd         sub_2346fa40+1
		23495c3c                        dd         sub_2346fa54+1
		23495c40                        dd         0x00000001
		23495c44                        dd         0x00000064
		23495c48                        dd         0x00000000
#endif
		//0x38 = 56?
}; //->23495C4C

extern void sub_2346f9a6();
extern void sub_2346fa36();
Menu_Item Data_23495c4c = //23495c4c
{
		0xffff, //uint16_t wData_0; //0
		0xffff, //uint16_t wData_2; //2
		{0}, //int fill_4[5]; //4
		0, //void (*Data_0x18)(struct Menu_Item*); //0x18 = 24
		sub_2346f9a6, //void* Data_0x1c; //0x1c = 28
		sub_2343d6e2, //void* Data_0x20; //0x20 = 32
		sub_2346fa36, //void* Data_0x24; //0x24 = 36
		0, //void* Data_0x28; //0x28 = 40
		//0x2c = 44
#if 0
		23495c4c                        dw         0xffff                               ; DATA XREF=0x23495c18, 0x23495c1c
		23495c4e                        dw         0xffff
		23495c50                        dd         0x00000000
		23495c54                        dd         0x00000000
		23495c58                        dd         0x00000000
		23495c5c                        dd         0x00000000
		23495c60                        dd         0x00000000
		23495c64                        dd         0x00000000
		23495c68                        dd         sub_2346f9a6+1
		23495c6c                        dd         sub_2343d6e2+1
		23495c70                        dd         sub_2346fa36+1
		23495c74                        dd         0x00000000
#endif
}; //->23495C78

#endif

Struct_238ddb2c Data_238ddb2c; //238ddb2c address???

#if 0

/* 2346f90c - todo */
void* sub_2346f90c(FrontDisplay_Job* r5)
{
#if 1
	console_send_string("sub_2346f90c (todo.c): TODO\r\n");
#endif

	snprintf(r5->bData_8, 0x100, "%s",
			&Data_238ddb2c.Data_8[Data_23495c14.currentItem].bData_0);

	r5->bNumTextChars = 12;
	r5->bDisplayOffset = 0;
	r5->bNumDisplayChars = 12;
	r5->bData_0x10b = 0;
	r5->bData_0x10c = 0;
	r5->bData_0x110 = 0;
	r5->holdTime = 0;
	r5->Data_0 = frontdisplay_draw_text;
	r5->Data_4 = 0;
	r5->bData_0x10f = 0;

	return sub_2346f90c;
}


/* 2346f950 - todo */
void* sub_2346f950(FrontDisplay_Job* r4)
{
#if 1
	console_send_string("sub_2346f950 (todo.c): TODO\r\n");
#endif

	r4->bData_8[0] = 0x22;

	text_table_get_string(Data_23495c14.stringId, &r4->bData_8[1], 0xfc);

	uint8_t len = strlen(r4->bData_8);

	r4->bData_8[len] = 0x22;
	len++;
	r4->bData_8[len] = 0;

	r4->bNumTextChars = strlen(r4->bData_8);
	r4->bDisplayOffset = 0;
	r4->bNumDisplayChars = 12;
	r4->bData_0x10b = 0;
	r4->bData_0x10c = 0;
	r4->bData_0x110 = 0;
	r4->holdTime = 20;
	r4->Data_0 = frontdisplay_draw_text;
	r4->Data_4 = 0;
	r4->bData_0x10f = 0;

	return sub_2346f90c;
}


/* 2346f9a6 - todo */
void sub_2346f9a6()
{
	console_send_string("sub_2346f9a6 (todo.c): TODO\r\n");

}


/* 2346fa36 - todo */
void sub_2346fa36()
{
#if 1
	console_send_string("sub_2346fa36 (todo.c): TODO\r\n");
#endif

	Data_23495c10 = 5;
}


/* 2346fa40 - todo */
int sub_2346fa40()
{
#if 1
	console_send_string("sub_2346fa40 (todo.c): TODO\r\n");
#endif

	Data_23495c10 = 5;

	frontdisplay_start_text(sub_2346f950);

	return 0;
}


/* 2346fa54 - todo */
int sub_2346fa54()
{
#if 1
	console_send_string("sub_2346fa54 (todo.c): TODO\r\n");
#endif

	return 0;
}


/* 2346fa58 - todo */
void sub_2346fa58(void* r5)
{
#if 0
	console_send_string("sub_2346fa58 (todo.c): TODO\r\n");
#endif

	Data_238ddb2c.Data_238ddb2c = r5;

	if (Data_238ddb2c.Data_238ddb2c == 0)
	{
		//loc_2346fac2
		return;
	}

	if (0 != (Data_238ddb2c.Data_238ddb2c)(&Data_238ddb2c.Data_238ddca4,
			&Data_238ddb2c.Data_4,
			&Data_238ddb2c.bData_238ddca0,
			&Data_238ddb2c.bData_238ddca1))
	{
		//loc_2346fac2
		return;
	}
	//0x2346fa72
	strcpy(&Data_238ddb2c.Data_238ddbe8[0].bData_238ddbe8[0], "RADIO");

	Data_23495c14.maxItem/*23495c2c*/ = 0;

	uint32_t r0;
	for (r0 = 0; r0 < 8; r0++)
	{
		//loc_2346fa84
		if (Data_238ddb2c.Data_8[r0].bData_0 == 0)
		{
			//->loc_2346fa96
			break;
		}
	}
	//loc_2346fa96
	if (r0 != 0)
	{
		r0--;
	}
	//loc_2346fa9c
	Data_23495c14.maxItem/*23495c2c*/ = r0; //TODO!!!

	//----

	Data_2349c158.maxItem/*2349c170*/ = 0; //TODO!!!

	for (r0 = 0; r0 < 9; r0++)
	{
		//loc_2346faa4
		if (Data_238ddb2c.Data_238ddbe8[r0].bData_238ddbe8[0] == 0)
		{
			//->loc_2346faba
			break;
		}
	} //for (r0 = 0; r0 < 9; r0++)
	//->loc_2346fabe
	if (r0 != 0)
	{
		r0--;
	}
	//loc_2346fac0
	Data_2349c158.maxItem/*2349c170*/ = r0;
}


/* 2346fac4 - todo */
int sub_2346fac4(int a)
{
#if 1
	console_send_string("sub_2346fac4 (todo.c): TODO\r\n");
#endif

	if (Data_238ddb2c.Data_238ddb2c == 0)
	{
		return 8;
	}
	//loc_2346fad2
	Data_23495c14.currentItem = Data_238ddb2c.bData_238ddca1;

	sub_2343d482(&Data_23495c14);
	sub_2343d3ac(&Data_23495c14);
	void* r1 = sub_2343d572();
	sub_2343d51e(&Data_23495c14, r1);

	return 0;
}

#endif

/* 2346faf6 - complete */
int sub_2346faf6(uint8_t* a)
{
#if 0
	console_send_string("sub_2346faf6 (todo.c): TODO\r\n");
#endif

	if (Data_238ddb2c.Data_238ddb2c == 0)
	{
		//loc_2346fb1c
		return 8;
	}
	//0x2346fb00
	if (0 == Data_238ddb2c.Data_238ddbe8[ Data_238ddb2c.bData_238ddca0 ].bData_238ddbf9)
	{
		strcpy(a, &Data_238ddb2c.Data_238ddbe8[ Data_238ddb2c.bData_238ddca0 ].bData_238ddbe8[0]);

		return 0;
	}
	//loc_2346fb1c
	return 8;
}


