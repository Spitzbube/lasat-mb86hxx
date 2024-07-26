

#include "data.h"


#pragma thumb

#if 0

void sub_2343d6e2();
int sub_2343e0aa(UI_Thread_Params*);
int sub_2343e0c2();
int sub_2343e154();

//23493114
uint8_t bData_23493134 = 0; //23493134 +0x20
uint8_t bData_23493135 = 1; //23493135

extern Menu_Item Data_23493174;

Menu Data_2349313c = //2349313c 23493114 + 0x28
{
		0x008c,
		&Data_23493174, //Data_4
		&Data_23493174, //Data_8
		0, //Data_0xc
		0, //Data_0x10
		0, //Data_0x14
		0, //fill_0x18
		0, //bData_0x19
		0, //Data_0x1c
		0, //Data_0x20
		sub_2343e154, //Data_0x24
		sub_2343e0c2, //Data_0x28
		1, //Data_0x2c
		0, //Data_0x30
		0, //Data_0x34

#if 0
		0x2349313c                        dw         0x008c                             ; DATA XREF=sub_2343e0fc+14, sub_2343e0fc+18, sub_2343e196+6, sub_2343e196+14, sub_2343e196+24
		0x2349313e                        dw         0x0000
		0x23493140                        dd         0x23493174
		0x23493144                        dd         0x23493174
		0x23493148                        dd         0x00000000
		0x2349314c                        dd         0x00000000
		0x23493150                        dd         0x00000000
		0x23493154                        db         0x00
		0x23493155                        db         0x00
		0x23493156 0000                   movs       r0, r0
		0x23493158                        dd         0x00000000
		0x2349315c                        dd         0x00000000
		0x23493160                        dd         sub_2343e154+1
		0x23493164                        dd         sub_2343e0c2+1
		0x23493168                        dd         0x00000001
		0x2349316c                        dd         0x00000000
		0x23493170                        dd         0x00000000
#endif
}; //->23493174

Menu_Item Data_23493174 = //23493174
{
		0xffff,
		0xffff,
		{0, 0, 0, 0, 0},
		0, //Data_0x18
		sub_2343e0aa, //Data_0x1c
		sub_2343d6e2, //Data_0x20
		0, //Data_0x24
		0 //Data_0x28

#if 0
		0x23493174                        dw         0xffff
		0x23493176                        dw         0xffff
		0x23493178                        dd         0x00000000
		0x2349317c                        dd         0x00000000
		0x23493180                        dd         0x00000000
		0x23493184                        dd         0x00000000
		0x23493188                        dd         0x00000000
		0x2349318c                        dd         0x00000000
		0x23493190                        dd         sub_2343e0aa+1
		0x23493194                        dd         sub_2343d6e2+1
		0x23493198                        dd         0x00000000
		0x2349319c                        dd         0x00000000
#endif
}; //->234931A0


Struct_235441b0 Data_235ff26c; //235ff26c


/* 2343dfcc - todo */
void sub_2343dfcc()
{
	console_send_string("sub_2343dfcc (todo.c): TODO\r\n");

}


/* 2343e0aa - complete */
int sub_2343e0aa(UI_Thread_Params* r4)
{
#if 1
	console_send_string("sub_2343e0aa (todo.c): TODO\r\n");
#endif

	sub_23438194(Data_23491dc8);

	sub_23470562(r4, sub_2343dfcc);

	return 0;
}


/* 2343e0c2 - complete */
int sub_2343e0c2()
{
	console_send_string("sub_2343e0c2 (todo.c): TODO\r\n");

	return 1;
}


/* 2343e0c6 - todo */
void* sub_2343e0c6(FrontDisplay_Job* r4)
{
	uint8_t* r5 = &r4->bData_8[0];

#if 0
	console_send_string("sub_2343e0c6 (todo.c): TODO\r\n");
#endif

	strcpy(r5, "Sendersuche?");

	r4->bNumTextChars = strlen(r5);
	r4->bDisplayOffset = 0;
	r4->bNumDisplayChars = 12;
	r4->bData_0x10b = 0;
	r4->bData_0x10c = 1;
	r4->holdTime = 0;

	r4->Data_0 = frontdisplay_draw_text;
	r4->Data_4 = 0;
	r4->bData_0x10f = 0;

	return sub_2343e0c6;
}


/* 2343e0fc - todo */
void* sub_2343e0fc(FrontDisplay_Job* r4)
{
	uint8_t* str;
	uint8_t len;

#if 1
	console_send_string("sub_2343e0fc (todo.c): TODO\r\n");
#endif

	r4->bData_8[0] = 0x22;

	text_table_get_string(Data_2349313c.stringId, &r4->bData_8[1], 12);

	str = &r4->bData_8[0];

	len = strlen(str);

	r4->bData_8[len++] = 0x22;
	r4->bData_8[len] = 0;

	r4->bNumTextChars = strlen(str);
	r4->bDisplayOffset = 0; //r5
	r4->bNumDisplayChars = 12;
	r4->bData_0x10b = 0; //r5
	r4->bData_0x10c = 0; //r5
	r4->bData_0x110 = 0; //r5
	r4->holdTime = 40;

	r4->Data_0 = frontdisplay_draw_text;
	r4->Data_4 = 0; //r5
	r4->bData_0x10f = 0; //r5

	return sub_2343e0c6;
}


/* 2343e154 - todo */
int sub_2343e154()
{
#if 0
	console_send_string("sub_2343e154 (todo.c): TODO\r\n");
#endif

	sub_2340c970(1, &Data_235ff26c);

	Data_235ff26c.Data_4 = (Data_235ff26c.Data_4 & ~0x1801f00) |
			(((uint32_t)bData_23493134 << 30) >> 7);

	Data_235ff26c.Data_0x10 = (Data_235ff26c.Data_0x10 & ~0x80) |
			(((uint32_t)bData_23493135 << 31) >> 24);

	sub_23413310(sub_2343dd2c, sub_2343deb4); //->onoff.c

	frontdisplay_start_text(sub_2343e0fc);

	return 0;
}

#endif

/* 2343e196 - todo */
int menu_guided_install_entry(UI_Thread_Params* r4)
{
#if 1
	console_send_string("menu_guided_install_entry (todo.c): TODO\r\n");
#endif

#if 0
	sub_2343d482(&Data_2349313c);

	sub_2343d3ac(&Data_2349313c);

	sub_2343d51e(&Data_2349313c, r4);
#endif

	return 0;
}


