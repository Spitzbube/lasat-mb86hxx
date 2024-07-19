
#include "data.h"
#include "ucos_ii.h"


struct
{
	int fill_0[61]; //0
	int Data_0xf4; //0xf4

} Data_237bf890; //237bf890



/* 23458874 - complete */
int sub_23458874()
{
#if 0
	console_send_string("sub_23458874 (todo.c): TODO\r\n");
#endif

	int r4;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	OS_ENTER_CRITICAL();

	r4 = Data_237bf890.Data_0xf4;

	OS_EXIT_CRITICAL();

	return r4;
}


