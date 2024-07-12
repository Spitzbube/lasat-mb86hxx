
#include "data.h"


//23492780
int Data_23492784; //23492784 +4
Struct_20611068* Data_2349278c; //2349278c +0xc
Struct_20611068* Data_23492790; //23492790 +0x10


typedef struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	uint8_t bData_2; //2

} Struct_234362e4;


/* 234362e4 - todo */
void fpc_init(Struct_234362e4* r4)
{
	Struct_20611068* sp_0xc;
	Struct_20401328 sp;

#if 0
	console_send_string("fpc_init (todo.c): TODO\r\n");
#endif

	sp.dwOutFunction = 5; //FAPI_GPIO_OUT_FPC_CLK
	sp.dwInFunction = 0xff;
	sp.bPin = r4->bData_0;

	gpio_open(&sp, &Data_23492790);

	sp.dwOutFunction = 6; //FAPI_GPIO_OUT_FPC_DATA
	sp.dwInFunction = 0xff;
	sp.bPin = r4->bData_1;

	gpio_open(&sp, &Data_2349278c);

	sp.dwOutFunction = 7; //FAPI_GPIO_OUT_FPC_STROBE
	sp.dwInFunction = 0xff;
	sp.bPin = r4->bData_2;

	gpio_open(&sp, &sp_0xc);

	//TODO

}


/* 234363d0 - todo */
void sub_234363d0()
{
#if 0
	console_send_string("sub_234363d0 (todo.c): TODO\r\n");
#endif

}


/* 234364a4 - todo */
void sub_234364a4()
{
#if 0
	console_send_string("sub_234364a4 (todo.c): TODO\r\n");
#endif

}


/* 2343655c - todo */
void sub_2343655c(int a)
{
#if 0
	console_send_string("sub_2343655c (todo.c): TODO\r\n");
#endif

	Data_23492784 = a;

	FREG(0xc1000030)[0] = Data_23492784; //FPC_SegData
}


/* 23436570 - todo */
void sub_23436570(void** a, void** b)
{
#if 0
	console_send_string("sub_23436570 (todo.c): TODO\r\n");
#endif

	*a = Data_2349278c;
	*b = Data_23492790;
}


