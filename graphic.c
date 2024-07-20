
#include "data.h"
#include "ucos_ii.h"
#include "graphic.h"


//23493618
OS_EVENT* Data_23493618/*queue*/ = 0; //23493618 +0
void (*Data_2349361c)() = 0; //2349361c +4
void (*Data_23493620)() = 0; //23493620 +8
void* Data_23493624 = 0; //23493624 +0xc


uint32_t graphic_thread_stack[THREAD_STACK_SIZE_GRAPHIC]; //2377d890 +4*0x190 = 2377DED0
struct
{
	int fill_0; //0
	uint8_t bData_4; //4
	uint8_t fill_5; //5
	uint8_t bData_6; //6
	uint8_t bData_7; //7
	int Data_8; //8
	uint8_t bData_0xc; //12
	uint8_t fill_0xd; //13
	uint8_t bData_0xe; //14
	uint8_t bData_0xf; //15
	int Data_0x10; //0x10
	int fill_0x14; //20 = 0x14
	uint16_t wData_0x18; //24 = 0x18
	int fill_0x1c[102]; //0x1c = 28
	//0x1b4
} Data_2377ded0; //2377ded0



/* 2345310c / 2341378c - todo */
void graphic_thread()
{
	uint8_t sp_0x40;

#if 0
	console_send_string("graphic_thread (todo.c): TODO\r\n");
#endif

	while (1)
	{
		//loc_23453128
		int r1;
		if (Data_2377ded0.wData_0x18 == 0)
		{
			r1 = 0;
		}
		else
		{
			r1 = 100;
		}

		struct
		{
			int fill_0; //0
			int Data_4; //4

		}* r7 = (void*) OSQPend(Data_23493618, r1, &sp_0x40);

		if (sp_0x40 == 0)
		{
			//0x2345315c
			if (r7->Data_4 == 5)
			{
				//0x23453168

				//TODO!!!
			}
			//loc_23453258
			console_send_string("graphic_thread (todo.c): loc_23453258: TODO\r\n");

			//TODO!!!
		}
		//->loc_23453128
	}
}


/* 234539f0 / 2341406c - complete */
int graphic_init(Struct_234539f0* r4)
{
#if 0
	console_send_string("graphic_init (todo.c): TODO\r\n");
#endif

	Struct_2342e0cc sp_0x18;

	if (Data_23493618 != 0)
	{
		return 4;
	}

	Data_23493618 = (void*) OSQCreate(&Data_23493624, 1);

	Data_23493620 = r4->Data_16;

	memset(&Data_2377ded0, 0, sizeof(Data_2377ded0));

	if (r4->Data_0 != 0)
	{
		sp_0x18.globalOffset = r4->Data_4;
		sp_0x18.Data_4 = r4->Data_0;
		sp_0x18.Data_8 = 0x4000;

		Data_2377ded0.bData_0xc = 0; //r6
		Data_2377ded0.bData_0xf = 0; //r6
		Data_2377ded0.bData_0xe = 1; //r7

		Data_2377ded0.Data_0x10 = sub_2342e0cc(&sp_0x18);
	}
	//loc_23453a7c
	if (r4->Data_8 == 0)
	{
		Data_2377ded0.Data_8 = 0;
		//->loc_23453ab8
	}
	else
	{
		sp_0x18.globalOffset = r4->Data_12;
		sp_0x18.Data_4 = r4->Data_8;
		sp_0x18.Data_8 = 0;

		Data_2377ded0.bData_4 = 1; //r7
		Data_2377ded0.bData_7 = 0; //r6
		Data_2377ded0.bData_6 = 1; //r7

		Data_2377ded0.Data_8 = sub_2342e0cc(&sp_0x18);
	}
	//loc_23453ab8
	int res = OSTaskCreateExt(graphic_thread, 0, &graphic_thread_stack[THREAD_STACK_SIZE_GRAPHIC-1]/*2377decc*/,
			r4->threadPrio & 0xff, r4->threadPrio, &graphic_thread_stack[0], THREAD_STACK_SIZE_GRAPHIC, "GRAPHIC_MANAGER", 3);

	if (res != 0)
	{
		return -1;
	}

	return 0;
}


/* 23453c5c - complete */
int graphics_configure_osd_layer(int r0)
{
#if 0
	console_send_string("graphics_configure_osd_layer (todo.c): TODO\r\n");
#endif

	if (r0 == 0)
	{
		Data_2349361c = sub_2342d878;
	}
	else if (r0 == 1)
	{
		Data_2349361c = sub_2342d6ec;
	}
	else if (r0 == 2)
	{
		Data_2349361c = sub_2342db04;
	}
	else if (r0 == 3)
	{
		Data_2349361c = sub_2342dde4;
	}
	else if (r0 == 4)
	{
		Data_2349361c = sub_2342d9e0;
	}
	else if (r0 == 5)
	{
		Data_2349361c = sub_2342df40;
	}
	else if (r0 == 6)
	{
		Data_2349361c = sub_2342dc7c;
	}
	else
	{
		return 0xff;
	}

	(Data_2349361c)(Data_2377ded0.Data_0x10, 720, 576);

	if (Data_2377ded0.Data_8 != 0)
	{
		(Data_2349361c)(Data_2377ded0.Data_8, 720, 576);
	}

	return 0;
}


