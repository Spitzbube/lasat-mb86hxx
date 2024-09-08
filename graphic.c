
#include "data.h"
#include "ucos_ii.h"
#include "viscale_osd.h"
#include "graphic.h"


//23493618
OS_EVENT* graphics_queue = 0; //23493618 +0 /  / 234c04b4
void (*Data_2349361c)() = 0; //2349361c +4
void (*Data_23493620)() = 0; //23493620 +8
void* Data_23493624 = 0; //23493624 +0xc

uint32_t graphic_thread_stack[THREAD_STACK_SIZE_GRAPHIC]; //2377d890 +4*0x190 = 2377DED0
struct
{
	int fill_0; //0
	uint8_t bData_4; //4
	uint8_t bData_5; //5
	uint8_t bData_6; //6
	uint8_t bData_7; //7
	void* Data_8; //8
	uint8_t bData_0xc; //12
	uint8_t bData_0xd; //13
	uint8_t bData_0xe; //14
	uint8_t bData_0xf; //15
	void* Data_0x10; //0x10
	uint16_t wData_0x14; //20 = 0x14
	uint16_t wData_0x16; //22 = 0x16
	uint16_t wData_0x18; //24 = 0x18
	Struct_2377ded0_Inner_0x1c* arData_0x1c[100]; //0x1c = 28
	int fill_0x1ac[2]; //0x1AC = 428
	//0x1b4
} Data_2377ded0; //2377ded0



/* 2345310c / 2341378c - todo */
void graphic_thread()
{
	uint8_t err; //sp_0x40
	int sp_0x3c = 0;
	struct 
	{
		uint8_t bData_0; //0
		uint8_t bData_2; //2
		void* Data_4[10]; //4
		//0x2c = 44
	} sp_0x10;
	int sp_0xc = 0;
	int sp8;

	uint8_t sb = 0;
	int r8 = 0;

#if 0
	console_send_string("graphic_thread (todo.c): TODO\r\n");
#endif

	while (1)
	{
		//loc_23453128
		int timeout;
		if (Data_2377ded0.wData_0x18 == 0)
		{
			timeout = 0;
		}
		else
		{
			timeout = 100;
		}

		Graphic_Queue_Item* r7 = OSQPend(graphics_queue, timeout, &err);

		if (err == 0)
		{
			//0x2345315c
#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "graphic_thread: r7->command=%d\r\n", r7->command);
				console_send_string(debug_string);
			}
#endif

			if (r7->command == 5)
			{
				//0x23453168

			} //if (r7->command == 5)
			//loc_23453258
			else if (r7->command == 4)
			{
				//0x23453260

			} //else if (r7->command == 4)
			//loc_234534ac
			else
			{
				if (r7->command != 2)
				{
					//0x234534b4
					if (r7->command == 22)
					{
						//0x234534bc
						memcpy(&sp_0x10, r7->pPayload, 0x2c);

						void* r5 = sp_0x10.Data_4[0];
						sb = 0;

						viscale_osd_layer_clear(Data_2377ded0.bData_0xc);

						if (sp_0x10.bData_2 & 8)
						{
							Data_2377ded0.bData_5 = 1;

							viscale_osd_layer_clear(Data_2377ded0.bData_4);
						}
						//0x234534f8
						//int r0 = 0;
						//->loc_234535e0
						for (uint32_t i = 0; i < 100; i++)
						{
							Data_2377ded0.arData_0x1c[i] = 0; //r8
						}
						//->loc_234535f4

						//TODO!!!

					} //if (r7->command == 22)
					//loc_234538d8
					else if (r7->command == 3)
					{
						Data_2377ded0.wData_0x18 = 1;
						Data_2377ded0.wData_0x16 = 1;
						Data_2377ded0.wData_0x14 = 0; //r8
						//->loc_23453980
						r7->Data_0xc = 0; //r8
						//loc_23453984
					}
					else if (r7->command == 6)
					{
						//0x234538fc
					}
					//loc_23453954
					else if (r7->command == 7)
					{
						//0x2345395c
					}
					//loc_23453984
				} //if (r7->command != 2)
				else
				{
					//loc_23453500
					sp_0x10.bData_0 = 0; //r8

					Struct_23414b38_b* r5 = r7->pPayload;

#if 1
					{
						extern char debug_string[];
						sprintf(debug_string, "loc_23453500: r5->wData_2=0x%x, bData_0=%d, bData_0x19=%d, bData_4=%d\r\n",
								r5->wData_2, r5->bData_0, r5->bData_0x19, r5->bData_4);
						console_send_string(debug_string);
						sprintf(debug_string, "loc_23453500: r5->bData_18=%d\r\n",
								r5->bData_0x18);
						console_send_string(debug_string);
					}
#endif

					Data_2377ded0.wData_0x16 = r5->wData_2;
					Data_2377ded0.wData_0x18 = r5->bData_0;

					if (Data_2377ded0.wData_0x16 != Data_2377ded0.wData_0x14)
					{
						//0x2345352c
						if (r5->bData_0x19 == 1)
						{
							//0x23453538
							viscale_osd_layer_clear(Data_2377ded0.bData_0xc);

							if (r5->bData_4 & 8)
							{
								//0x2345354c
								Data_2377ded0.bData_5 = 1;

								viscale_osd_layer_clear(Data_2377ded0.bData_4);
								//->loc_23453580
							}
							else
							{
								//loc_23453560
								if ((Data_2377ded0.bData_6 & 1) == 0)
								{
									//0x2345356c
									viscale_osd_layer_disable(Data_2377ded0.Data_8);

									Data_2377ded0.bData_6 |= 1;
								}
							}
							//loc_23453580
							if ((r5->Data_0xc->Data_0 != sp_0xc) ||
								(r5->bData_1 != sp_0x3c))
							{
								//0x234535a0
								sub_2342d5e4(Data_2377ded0.bData_0xc, 
									r5->Data_0xc->Data_0, r5->bData_0x10, r5->bData_1);

								sp_0xc = r5->Data_0xc->Data_0;
								sp_0x3c = r5->bData_1;
							}
							//loc_234535c4
						} //if (r5->bData_0x19 == 1)
						//loc_234535c4
						for (uint32_t i = 0; i < 100; i++)
						{
							//loc_234535c8
							Data_2377ded0.arData_0x1c[i] = 0; //r8	
						}
						//->loc_234535f4
					} //if (Data_2377ded0.wData_0x16 != Data_2377ded0.wData_0x14)
					//loc_234535f4
					sub_23453d60(&Data_2377ded0.bData_0xc);

					Data_2377ded0.bData_0xd = 1;

					if (r5->bData_4 & 8)
					{
						//0x23453614
						if (0 == sub_2342e27c(1, 736, 576))
						{
							(Data_2349361c)(Data_2377ded0.Data_8, 720, 576);
						}

						sub_23453d60(&Data_2377ded0.bData_4);
					} //if (r5->bData_4 & 8)

					while (1)
					{
						//loc_23453648
						if (r5 != 0)
						{
							//0x23453650
							Struct_2377ded0_Inner_0x1c* r4 =  r5->Data_8;

							Data_2377ded0.wData_0x16 = r5->wData_2;
							Data_2377ded0.wData_0x18 = r5->bData_0;
							uint32_t sl = 0;
							//->loc_234537dc
							while (sl < r5->bData_0x18)
							{
								//loc_23453670

#if 1
								{
									extern char debug_string[];
									sprintf(debug_string, "loc_23453670: sl=%d, r4=%p\r\n", sl, r4);
									console_send_string(debug_string);
									hex_dump("r4", r4, 0x40);
								}
#endif
								if (r4->bData_0 == 1)
								{
									//0x2345367c
									if ((Data_2377ded0.arData_0x1c[sl] != r4) ||
										(r4->bData_0x3c != 0))
									{
										//0x23453698
										sub_23452e88(r4);

										if (r4->Data_8 != 0)
										{
											//0x234536ac
											if (r4->Data_8->Data_8 != 0)
											{
												//0x234536b8
												(r4->Data_8->Data_8)(r4, r5->bData_1);
												//->loc_23453710
											}
											else
											{
												//loc_234536c8
												sp8 = sub_23408d10((uint16_t)(r4->Data_8->Data_0));

												sub_2342cf84(r4->bData_1, 
													r4->Data_8->wData_4, 
													r4->Data_8->wData_6,
													sp8,
													r4->wData_0x1c & 0xff);

												if (((uint8_t*)sp8)[7] == 0)
												{
													Data_2377ded0.bData_5 = 1;
												}
											}
										}
										//loc_23453710
									}
									//loc_23453710
									if (r4->Data_0x20 != 0)
									{
										//0x2345371c
										r4->Data_0x20->bData_0xc = r4->wData_0x1c & 0xff;

										if ((Data_2377ded0.arData_0x1c[sl] != r4) ||
											(r4->bData_0x3c != 0) ||
											(r4->Data_0x20->bData_0x17 != 0))
										{
											//0x23453748
											Struct_2377ded0_Inner_0x1c_Inner_0x20* fp = r4->Data_0x20;
											Struct_2377ded0_Inner_0x1c_Inner_0x20* r6 = &r4->Data_0x24;

											if (r4->Data_0x24.Data_0x10 != 0)
											{
												//0x2345375c
												sub_2342d42c(r6->bData_0,
													(int16_t) r6->wData_2,
													(int16_t) r6->wData_4,
													(int16_t)(r6->wData_6 - r6->wData_2),
													(int16_t)(r6->wData_8 - r6->wData_4),
													r4->Data_0x20->bData_0xc);
											}
											//loc_23453790 -> loc_234537a8
											//sp8 = r6;
											sub_23408604(*fp, r6);
										}
										//loc_234537bc
										r4->Data_0x20->bData_0x17 = 0; //r8
									} //if (r4->Data_0x20 != 0)
									//loc_234537c4
									r4->bData_0x3c = 0; //r8
								} //if (r4->bData_0 == 1)
								//loc_234537c8
								Data_2377ded0.arData_0x1c[sl] = r4;
								sl++;
								r4++;
							} //while (sl < r5->bData_0x18)
							//loc_234537e8
						} //if (r5 != 0)
						//loc_234537e8
						if (sp_0x10.bData_0 != 0)
						{
							sp_0x10.bData_0--;

							if (sp_0x10.bData_0 != 0)
							{
								//0x23453804
								sb++;
								r5 = sp_0x10.Data_4[sb];

								for (uint32_t i = 0; i < 100; i++)
								{
									//loc_23453820
									Data_2377ded0.arData_0x1c[i] = 0; //r8
								}
								//0x23453834
							}
						} //if (sp_0x10.Data_0 != 0)
						//0x23453834
						if (sp_0x10.bData_0 == 0)
						{
							break;
						}
						//->loc_23453648
					} //while (1)
					//loc_2345383c
					sub_23453d60(&Data_2377ded0.bData_0xc);

					if (r5->bData_4 & 8)
					{
						sub_23453d60(&Data_2377ded0.bData_4);
					}

					Data_2377ded0.wData_0x14 = Data_2377ded0.wData_0x16;

					if (r5->bData_4 & 4)
					{
						//0x2345386c
						sub_2342ce64();

						if (Data_2377ded0.bData_0xe & 1)
						{
							//0x2345387c
							viscale_osd_layer_enable(Data_2377ded0.Data_0x10);

							Data_2377ded0.bData_0xe &= ~1;
						}
						//loc_23453890
					}
					//loc_23453890
					if ((r5->bData_4 & 8) && (Data_2377ded0.bData_6 & 1))
					{
						viscale_osd_layer_enable(Data_2377ded0.Data_8);

						Data_2377ded0.bData_6 &= ~1;
						Data_2377ded0.bData_6 &= ~2;
					}
					//loc_234538bc
					sub_23453d34(&Data_2377ded0.bData_0xc);

					if (r5->bData_4 & 8)
					{
						sub_23453d34(&Data_2377ded0.bData_4);
					}
					//->loc_23453980
					r7->Data_0xc = 0; //r8
					//loc_23453984
				} //if (r7->command == 2)
			}

			//loc_23453980
			r7->Data_0xc = 0; //r8
			//loc_23453984


			//TODO!!!
		} //if (err == 0)
		//->loc_23453128
	}
}


/* 234539f0 / 2341406c - complete */
int graphic_init(Graphic_Params* r4)
{
#if 0
	console_send_string("graphic_init (todo.c): TODO\r\n");
#endif

	Viscale_Osd_Params sp_0x18;

	if (graphics_queue != 0)
	{
		return 4;
	}

	graphics_queue = OSQCreate(&Data_23493624, 1);

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

		Data_2377ded0.Data_0x10 = viscale_osd_open(&sp_0x18);
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

		Data_2377ded0.Data_8 = viscale_osd_open(&sp_0x18);
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


/* 23453af8 /  / 23414b38 - todo */
int sub_23414b38(Graphic_Queue_Item* pQueueItem, Struct_23414b38_b* r5)
{
#if 0
	console_send_string("sub_23414b38 (graphic.c): TODO\r\n");
#endif

	if (graphics_queue == 0)
	{
		return 3;
	}

	r5->bData_1 = sub_23411190();

	if (r5 != 0)
	{
		if (r5->wData_2 == 0x32)
		{
			pQueueItem->command = 5;
		}
		else
		{
			pQueueItem->command = 2;
		}
	}
	else
	{
		pQueueItem->command = 3;
	}

	pQueueItem->Data_8 = 0;
	pQueueItem->Data_0xc = 1;
	pQueueItem->pPayload = r5;

	int res = OSQPost(graphics_queue, pQueueItem);
	if (res == 0)
	{
		while (pQueueItem->Data_0xc != 0)
		{
			rtos_task_wait(1);
		}
	}

	return res;
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


/* 23453d34 - complete */
void sub_23453d34(uint8_t* a)
{
#if 0
	console_send_string("sub_23453d34 (todo.c): TODO\r\n");
#endif

	if (a[1] == 0)
	{
		return;
	}

	a[1] = 0;

	sub_2342d51c(a[0]);

	rtos_task_wait(1);
}


/* 23453d60 - complete */
void sub_23453d60(uint8_t* a)
{
#if 0
	console_send_string("sub_23453d60 (todo.c): TODO\r\n");
#endif

	if (a[3] == 0)
	{
		a[3] = 1;
	}
	else
	{
		a[3] = 0;

		sub_2342d5ac(a[0]);
	}
}

