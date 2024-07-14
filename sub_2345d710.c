
#include "data.h"



//234940ac
#if 0
int Data_234940ac = 0; //234940ac +0
uint16_t wData_234940b0 = 0; //234940b0 +4
#else
struct
{
	int Data_0; //0
	uint16_t wData_4; //4

}
Data_234940ac = //234940ac
{
	0, 0
};
#endif


/* 2345d710 - todo */
int sub_2345d710(int a)
{
#if 0
	console_send_string("sub_2345d710 (todo.c): TODO\r\n");
#endif

	void* sp;

	Data_234940ac.Data_0 = 0;
	Data_234940ac.wData_4 = a;

	sp = &Data_234940ac;
	sub_23459098(&sp);

	return 0;
}


