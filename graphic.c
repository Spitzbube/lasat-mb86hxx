
#include "data.h"
#include "ucos_ii.h"
#include "viscale_osd.h"
#include "graphic.h"


static const uint8_t Data_2348fbac[] = //2348fbac /  / 234b257c
{
	1, 2, 3, 4, 5, 6, 7, 8, //TODO!!!
};

static const uint8_t Data_2348fc7c[] = //2348fc7c
{
	1, 2, 3, 4, 5, 6, 7, 8, //TODO!!!
};

static const uint8_t Data_2348fd4c[] = //2348fd4c
{
	1, 2, 3, 4, 5, 6, 7, 8, //TODO!!!
};

static const uint8_t Data_2348fe1c[] = //2348fe1c
{
	1, 2, 3, 4, 5, 6, 7, 8, //TODO!!!
};

static const uint8_t Data_2348feec[] = //2348feec /  / 234b28bc
{
	1, 2, 3, 4, 5, 6, 7, 8, //TODO!!!
};

static const uint8_t Data_2348ffbc[] = //2348ffbc
{
	1, 2, 3, 4, 5, 6, 7, 8, //TODO!!!
};

static const uint8_t Data_2349008c[] = //2349008c
{
	1, 2, 3, 4, 5, 6, 7, 8, //TODO!!!
};

static const uint8_t Data_2349015c[] = //2349015c
{
	1, 2, 3, 4, 5, 6, 7, 8, //TODO!!!
};



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
	void* hViscaleOsd1; //8
	uint8_t bData_0xc; //12
	uint8_t bData_0xd; //13
	uint8_t bData_0xe; //14
	uint8_t bData_0xf; //15
	void* hViscaleOsd2; //0x10
	uint16_t wData_0x14; //20 = 0x14
	uint16_t wData_0x16; //22 = 0x16
	uint16_t wData_0x18; //24 = 0x18
	Graphic_Job_2_5_Item* arData_0x1c[100]; //0x1c = 28
	int fill_0x1ac[2]; //0x1AC = 428
	//0x1b4
} graphics_data; //2377ded0 /  / 235b8608


typedef struct 
{
	uint16_t wData_0; //0
	uint16_t wData_2; //2
	uint16_t wData_4; //4
	uint16_t wData_6; //6
	//8
} Struct_23452584_b;


/* 234521d4 /  / 23413214 - todo */
int sub_234521d4(Graphic_Job_2_5_Item* pGraphicItem/*r4*/)
{
#if 0
	console_send_string("sub_234521d4 (todo.c): TODO\r\n");
#endif

	uint8_t pFlags/*r5*/ = pGraphicItem->background->bFlags;

	sub_2342ce8c(pGraphicItem->bData_1, pGraphicItem->x, pGraphicItem->y, 
		(pFlags & 2)? Data_2348feec: Data_2348fbac);

	sub_2342ce8c(pGraphicItem->bData_1, 
		pGraphicItem->x + pGraphicItem->width - 20, pGraphicItem->y, 
		(pFlags & 1)? Data_2349008c: Data_2348fc7c);

	sub_2342ce8c(pGraphicItem->bData_1, 
		pGraphicItem->x + pGraphicItem->width - 20, 
		pGraphicItem->y + pGraphicItem->height - 20, 
		(pFlags & 4)? Data_2349015c: Data_2348fd4c);

	sub_2342ce8c(pGraphicItem->bData_1, 
		pGraphicItem->x, 
		pGraphicItem->y + pGraphicItem->height - 20, 
		(pFlags & 8)? Data_2348ffbc: Data_2348fe1c);

	//Top row 1
	viscale_osd_fill_rect(pGraphicItem->bData_1, 
		pGraphicItem->x + 20, pGraphicItem->y, 
		pGraphicItem->width - 40, 2, 15);

	//Top row 2
	viscale_osd_fill_rect(pGraphicItem->bData_1, 
		pGraphicItem->x + 20, pGraphicItem->y + 2, 
		pGraphicItem->width - 40, 2, 13);

	//Top row 3
	viscale_osd_fill_rect(pGraphicItem->bData_1, 
		pGraphicItem->x + 20, pGraphicItem->y + 4, 
		pGraphicItem->width - 40, 1, 12);

#if 0
	viscale_osd_fill_rect(pGraphicItem->bData_1, pGraphicItem->x + 20, pGraphicItem->y + pGraphicItem->height - 6, 
		pGraphicItem->width - 40, 2, 15);

	viscale_osd_fill_rect(pGraphicItem->bData_1, pGraphicItem->x + 20, pGraphicItem->y + pGraphicItem->height - 4, 
		pGraphicItem->width - 40, 2, 13);

	viscale_osd_fill_rect(pGraphicItem->bData_1, pGraphicItem->x + 20, pGraphicItem->y + pGraphicItem->height - 2, 
		pGraphicItem->width - 40, 1, 12);

	viscale_osd_fill_rect(pGraphicItem->bData_1, pGraphicItem->x, pGraphicItem->y + 20, 
		2, pGraphicItem->height - 40, 15);

	viscale_osd_fill_rect(pGraphicItem->bData_1, pGraphicItem->x + 2, pGraphicItem->y + 20, 
		2, pGraphicItem->height - 40, 13);

	viscale_osd_fill_rect(pGraphicItem->bData_1, pGraphicItem->x + 4, pGraphicItem->y + 20, 
		1, pGraphicItem->height - 40, 12);

	viscale_osd_fill_rect(pGraphicItem->bData_1, pGraphicItem->x + pGraphicItem->width - 6, pGraphicItem->y + 20, 
		2, pGraphicItem->height - 40, 15);

	viscale_osd_fill_rect(pGraphicItem->bData_1, pGraphicItem->x + pGraphicItem->width - 4, pGraphicItem->y + 20, 
		2, pGraphicItem->height - 40, 13);

	viscale_osd_fill_rect(pGraphicItem->bData_1, pGraphicItem->x + pGraphicItem->width - 2, pGraphicItem->y + 20, 
		1, pGraphicItem->height - 40, 12);
#endif
}


/* 23452584 /  / 234135c4 - todo */
int sub_23452584(uint8_t flags/*r5*/, 
	Struct_23452584_b* b, 
	Graphic_Job_2_5_Item* pGraphicItem/*r4*/)
{
#if 0
	console_send_string("sub_23452584 (todo.c): TODO\r\n");
#endif

	uint8_t r0 = 0;
	uint8_t r6 = 0;
//	int r2 = 1;

	if (flags & 2)
	{
		//0x234525a4
		r6 = 1;
		b->wData_0 = pGraphicItem->background->wData_0 + pGraphicItem->x;
		b->wData_4 = pGraphicItem->background->wData_0 + pGraphicItem->y;
		b->wData_6 = pGraphicItem->background->wData_0;
		b->wData_2 = 1; //r2
		b++;
	}
	//loc_234525e8
	if (flags & 8)
	{
		//0x234525f0
		b->wData_0 = pGraphicItem->background->wData_0 + pGraphicItem->x;
		b->wData_4 = (pGraphicItem->y + pGraphicItem->height) - pGraphicItem->background->wData_0;
		b->wData_6 = pGraphicItem->background->wData_0;
		b->wData_2 = 1; //r2
		r6++;
		b++;
	}
	//loc_23452640
	if (flags & 1)
	{
		//0x23452648
		b->wData_0 = pGraphicItem->width - pGraphicItem->background->wData_0 + pGraphicItem->x;
		b->wData_4 = pGraphicItem->background->wData_0 + pGraphicItem->y;
		b->wData_6 = pGraphicItem->background->wData_0;
		b->wData_2 = 1; //r2
		b++;
		r0 = 1;
	}
	//loc_23452694
	if (flags & 4)
	{
		//0x2345269c
		r0++;
		b->wData_0 = pGraphicItem->width - pGraphicItem->background->wData_0 + pGraphicItem->x;
		b->wData_4 = pGraphicItem->y + pGraphicItem->height - pGraphicItem->background->wData_0;
		b->wData_6 = pGraphicItem->background->wData_0;
		b->wData_2 = 1; //r2
	}
	//loc_234526ec
	if (r0 != 0)
	{
		//0x234526f4
		if (flags & 1)
		{
			viscale_osd_fill_rect(pGraphicItem->bData_1,
				pGraphicItem->width - pGraphicItem->background->wData_0 + pGraphicItem->x,
				pGraphicItem->y + pGraphicItem->background->wData_0,
				pGraphicItem->background->wData_0,
				pGraphicItem->height - pGraphicItem->background->wData_0 * r0,
				pGraphicItem->wColor);
		}
		else
		{
			viscale_osd_fill_rect(pGraphicItem->bData_1,
				pGraphicItem->width - pGraphicItem->background->wData_0 + pGraphicItem->x,
				pGraphicItem->y,
				pGraphicItem->background->wData_0,
				pGraphicItem->height - pGraphicItem->background->wData_0 * r0,
				pGraphicItem->wColor);
		}
		
		pGraphicItem->width -= pGraphicItem->background->wData_0;
	}
	//loc_23452768
	if (r6 != 0)
	{
		//0x23452770
		if (flags & 2)
		{
			viscale_osd_fill_rect(pGraphicItem->bData_1,
				pGraphicItem->x,
				pGraphicItem->y + pGraphicItem->background->wData_0,
				pGraphicItem->background->wData_0,
				pGraphicItem->height - pGraphicItem->background->wData_0 * r6,
				pGraphicItem->wColor);
		}
		else
		{
			viscale_osd_fill_rect(pGraphicItem->bData_1,
				pGraphicItem->x,
				pGraphicItem->y,
				pGraphicItem->background->wData_0,
				pGraphicItem->height - pGraphicItem->background->wData_0 * r6,
				pGraphicItem->wColor);
		}

		pGraphicItem->width -= pGraphicItem->background->wData_0;
		pGraphicItem->x += pGraphicItem->background->wData_0;
	}
	//loc_234527e4
}


/* 23452e88 /  / 23413ec8 - todo */
void sub_23452e88(Graphic_Job_2_5_Item* r4)
{
#if 0
	console_send_string("sub_23452e88 (todo.c): TODO\r\n");
#endif

	Graphic_Job_2_5_Item sp_0x34;
	Struct_23452584_b sp_0xc[5];

	Graphic_Job_2_5_Item_Background* r6 = r4->background;

	sp_0x34 = *r4;

	memset(&sp_0xc[0], 0, 5 * sizeof(Struct_23452584_b));

	int r0 = 1;

#ifdef GRAPHIC_sub_23452e88_DEBUG
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23452e88: '%s', r6->Data_4=%d, r6->bFlags=0x%02x\r\n", 
			r4->pText->pString, r6->Data_4, r6->bFlags);
		console_send_string(debug_string);
	}
#endif

#if 1
	switch (r6->Data_4)
	{
		case 1:
			//0x23452ee0
			//ldrh       r1, [r4, #0xc]
			//->0x23452ef4
			sp_0xc[0].wData_0 = r4->x;
			sp_0xc[0].wData_4 = r4->height / 2 + r4->y;
			sp_0xc[0].wData_6 = r4->height / 2;
			sp_0xc[0].wData_2 = 1; //r0; 
			//->0x23452fa4
			break;

		case 2:
			//0x23452ee8
			sp_0xc[0].wData_0 = r4->x + r4->width;
			sp_0xc[0].wData_4 = r4->height / 2 + r4->y;
			sp_0xc[0].wData_6 = r4->height / 2;
			sp_0xc[0].wData_2 = 1; //r0; 
			//->0x23452fa4
			break;
		
		case 3:
			//0x23452f1c
			sp_0xc[0].wData_0 = r4->x;
			sp_0xc[0].wData_4 = r4->height / 2 + r4->y;
			sp_0xc[0].wData_6 = r4->height / 2;
			sp_0xc[0].wData_2 = 1; //r0; 

			sp_0xc[1].wData_0 = r4->x + r4->width;
			sp_0xc[1].wData_4 = r4->height / 2 + r4->y;
			sp_0xc[1].wData_6 = r4->height / 2;
			sp_0xc[1].wData_2 = 1; //r0; 
			//->0x23452fa4
			break;

		case 4:
			//0x23452f78 /  / 23413fb8: Solid round corner
			sub_23452584(r6->bFlags, &sp_0xc[0], &sp_0x34);
			//->0x23452fa4
			break;

		case 5:
			//0x23452f8c /  / 23413fcc: Shaded round corner
			sub_234521d4(r4);
			//->0x23452fa4
			break;

		default:
			//loc_23452f98
			sp_0xc[0].wData_2 = 0;
			sp_0xc[0].wData_0 = 0;
			//0x23452fa4
			break;
	} //switch (r6->Data_4)
	//0x23452fa4
	if (r6->Data_4 != 0)
	{
		//0x23452fb0
		//r5, #0x0
		//r7, sp, #0xc
		for (uint8_t r5 = 0; r5 < 5; r5++)
		{
			//loc_23452fb8
			if ((sp_0xc[r5].wData_2 == 0) || 
				(sp_0xc[r5].wData_0 == 0))
			{
				//->loc_23453000
				break;
			}

			sub_2342d080(r4->bData_1, 
				(int16_t) sp_0xc[r5].wData_0,
				(int16_t) sp_0xc[r5].wData_4,
				(int16_t) sp_0xc[r5].wData_6,
				1, r4->wColor);
		}
		//loc_23453000 /  / loc_23414040
		if ((r6->Data_4 == 5) ||
			(r6->Data_4 == 12) ||
			(r6->Data_4 == 13))
		{
			//->loc_2345309c /  / loc_234140dc
			return;
		}
		//loc_23453014
	} //if (r6->Data_4 != 0)
	//loc_23453014 /  / loc_23414054
#endif

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23452e88: %d, %d, %d, %d, %d\r\n", 
			sp_0x34.x,
			sp_0x34.y,
			sp_0x34.width,
			sp_0x34.height,
			sp_0x34.wColor);
		console_send_string(debug_string);
	}
#endif

#if 1
	viscale_osd_fill_rect(sp_0x34.bData_1,
		sp_0x34.x,
		sp_0x34.y,
		sp_0x34.width,
		sp_0x34.height,
		sp_0x34.wColor);
#endif

	if ((sp_0x34.wColor == 0) || (r6->Data_4 == 0))
	{
		//->loc_2345309c /  / loc_234140dc
		return;
	}

#if 0

	if (r6->Data_4 == 6)
	{
		//0x23453050
		viscale_osd_fill_rect(sp_0x34.bData_1,
			sp_0x34.x,
			sp_0x34.y,
			sp_0x34.width,
			2,
			sp_0x34.wData_0x1e);
		//->loc_23453084
		viscale_osd_fill_rect(sp_0x34.bData_1,
			sp_0x34.x,
			sp_0x34.y,
			2,
			sp_0x34.height,
			sp_0x34.wData_0x1e);
		//->loc_234530d4
		//->loc_23453098
	}
	//loc_23453074
	else if (r6->Data_4 == 7)
	{
		//loc_234530ec
		viscale_osd_fill_rect(sp_0x34.bData_1,
			sp_0x34.x,
			sp_0x34.y,
			sp_0x34.width,
			2,
			sp_0x34.wData_0x1e);
		//->loc_23453098
	}
	else if (r6->Data_4 == 8)
	{
		//loc_23453084
		viscale_osd_fill_rect(sp_0x34.bData_1,
			sp_0x34.x,
			sp_0x34.y,
			2,
			sp_0x34.height,
			sp_0x34.wData_0x1e);
		//->loc_23453098
	}
	else if (r6->Data_4 == 9)
	{
		//0x234530ac
		if (sp_0x34.height > 5)
		{
			//0x234530b8
			viscale_osd_fill_rect(sp_0x34.bData_1,
				sp_0x34.x,
				sp_0x34.y + 5,
				2,
				sp_0x34.height - 5,
				sp_0x34.wData_0x1e);
		}
#if 0
		else
		{
			//loc_2345309c
		}
#endif
	}
	//loc_234530e4
	else if (r6->Data_4 == 10)
	{
		//loc_234530ec
		viscale_osd_fill_rect(sp_0x34.bData_1,
			sp_0x34.x,
			sp_0x34.y,
			sp_0x34.width,
			2,
			sp_0x34.wData_0x1e);
		//->loc_23453098
	}
	//loc_2345309c
#endif
}


/* 2345310c / 2341378c / 2341414c - todo */
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
		if (graphics_data.wData_0x18 == 0)
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
			if (r7->command == 2)
			{
				//No trace
			}
			else
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
			//loc_23453258 /  / loc_23414298
			else if (r7->command == 4)
			{
				//0x23453260 /  / 0x234142a0

			} //else if (r7->command == 4)
			//loc_234534ac /  / loc_234144ec
			else
			{
				if (r7->command != 2)
				{
					//0x234534b4 /  / 0x234144f4
					if (r7->command == 22)
					{
						//0x234534bc
						memcpy(&sp_0x10, r7->pPayload, 0x2c);

						void* r5 = sp_0x10.Data_4[0];
						sb = 0;

						viscale_osd_layer_clear(graphics_data.bData_0xc);

						if (sp_0x10.bData_2 & 8)
						{
							graphics_data.bData_5 = 1;

							viscale_osd_layer_clear(graphics_data.bData_4);
						}
						//0x234534f8
						//int r0 = 0;
						//->loc_234535e0
						for (uint32_t i = 0; i < 100; i++)
						{
							graphics_data.arData_0x1c[i] = 0; //r8
						}
						//->loc_234535f4

						//TODO!!!

					} //if (r7->command == 22)
					//loc_234538d8 /  / loc_23414918
					else if (r7->command == 3)
					{
						graphics_data.wData_0x18 = 1;
						graphics_data.wData_0x16 = 1;
						graphics_data.wData_0x14 = 0; //r8
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
					//loc_23453500 /  / loc_23414540
					sp_0x10.bData_0 = 0; //r8

					Graphic_Job_2_5* r5 = r7->pPayload;

#if 0
					{
						extern char debug_string[];
						sprintf(debug_string, "loc_23453500: r5->wData_2=0x%x, bData_0=%d, bData_0x19=%d, bData_4=%d\r\n",
								r5->wData_2, r5->bData_0, r5->bData_0x19, r5->bData_4);
						console_send_string(debug_string);
						sprintf(debug_string, "loc_23453500: r5->bNumItems=%d, r5->pItems=%p, bData_1=%d\r\n",
								r5->bNumItems, r5->pItems, r5->bData_1);
						console_send_string(debug_string);
					}
#endif

					graphics_data.wData_0x16 = r5->wData_2;
					graphics_data.wData_0x18 = r5->bData_0;

					if (graphics_data.wData_0x16 != graphics_data.wData_0x14)
					{
						//0x2345352c
						if (r5->bData_0x19 == 1)
						{
							//0x23453538 /  / 0x23414578
							viscale_osd_layer_clear(graphics_data.bData_0xc);

							if (r5->bData_4 & 8)
							{
								//0x2345354c
								graphics_data.bData_5 = 1;

								viscale_osd_layer_clear(graphics_data.bData_4);
								//->loc_23453580
							}
							else
							{
								//loc_23453560
								if ((graphics_data.bData_6 & 1) == 0)
								{
									//0x2345356c
									viscale_osd_layer_disable(graphics_data.hViscaleOsd1);

									graphics_data.bData_6 |= 1;
								}
							}
							//loc_23453580: Change the colour scheme?
							if ((r5->pColorData->pClut != sp_0xc) ||
								(r5->bData_1 != sp_0x3c))
							{
								//0x234535a0
								viscale_osd_update_clut(graphics_data.bData_0xc, 
									r5->pColorData->pClut, r5->numColors, r5->bData_1);

								sp_0xc = r5->pColorData->pClut;
								sp_0x3c = r5->bData_1;
							}
							//loc_234535c4
						} //if (r5->bData_0x19 == 1)
						//loc_234535c4 /  / loc_23414604
						for (uint32_t i = 0; i < 100; i++)
						{
							//loc_234535c8
							graphics_data.arData_0x1c[i] = 0; //r8	
						}
						//->loc_234535f4
					} //if (graphics_data.wData_0x16 != graphics_data.wData_0x14)
					//loc_234535f4
					graphic_swap_buffer(&graphics_data.bData_0xc);

					graphics_data.bData_0xd = 1;

					if (r5->bData_4 & 8)
					{
						//0x23453614 /  / 0x23414654
						if (0 == sub_2342e27c(1, 736, 576))
						{
							(Data_2349361c)(graphics_data.hViscaleOsd1, 720, 576);
						}

						graphic_swap_buffer(&graphics_data.bData_4);
					} //if (r5->bData_4 & 8)

					while (1)
					{
						//loc_23453648
						if (r5 != 0)
						{
							//0x23453650
							Graphic_Job_2_5_Item* pItem/*r4*/ = r5->pItems;

							graphics_data.wData_0x16 = r5->wData_2;
							graphics_data.wData_0x18 = r5->bData_0;
							uint32_t i = 0; //sl
							//->loc_234537dc /  / loc_2341481c
							while (i < r5->bNumItems)
							{
								//loc_23453670 /  / loc_234146b0

#ifdef GRAPHIC_loc_23453670_DEBUG
								{
									extern char debug_string[];
									sprintf(debug_string, "loc_23453670: i=%d, pItem=%p\r\n", 
										i, pItem);
									console_send_string(debug_string);
									hex_dump("pItem", pItem, 0x40);
								}
#endif
								if (pItem->bEnable == 1)
								{
									//0x2345367c: Box handling
#if 1
									if ((graphics_data.arData_0x1c[i] != pItem) ||
										(pItem->bData_0x3c != 0))
									{
										//0x23453698 /  / 0x234146d8
#if 1
										sub_23452e88/*sub_23413ec8*/(pItem);
#endif

#if 0
										if (pItem->Data_8 != 0)
										{
											//0x234536ac
											if (pItem->Data_8->Data_8 != 0)
											{
												//0x234536b8
												(pItem->Data_8->Data_8)(pItem, r5->bData_1);
												//->loc_23453710
											}
											else
											{
												//loc_234536c8 /  / loc_23414708
												sp8 = sub_23408d10((uint16_t)(pItem->Data_8->Data_0));

												sub_2342cf84(pItem->bData_1, 
													pItem->Data_8->wData_4, 
													pItem->Data_8->wData_6,
													sp8,
													pItem->wColor & 0xff);

												if (((uint8_t*)sp8)[7] == 0)
												{
													graphics_data.bData_5 = 1;
												}
											}
										} //if (pItem->Data_8 != 0)
#endif
										//loc_23453710 /  / loc_23414750
									}
#endif
									//loc_23453710 /  / loc_23414750: Text handling
#if 1
									if (pItem->pText != 0)
									{
										//0x2345371c /  / 0x2341475c
										pItem->pText->bBackgroundColor = pItem->wColor & 0xff;

										if ((graphics_data.arData_0x1c[i] != pItem) ||
											(pItem->bData_0x3c != 0) ||
											(pItem->pText->bUpdate != 0))
										{
											//0x23453748
											Graphic_Job_2_5_Item_Text* fp = pItem->pText;
											Graphic_Job_2_5_Item_Text* r6 = &pItem->Data_0x24;

											if (pItem->Data_0x24.pString != 0)
											{
												//0x2345375c /  / 2341479c
												viscale_osd_fill_rect(r6->bData_0,
													(int16_t) r6->x1,
													(int16_t) r6->y1,
													(int16_t)(r6->x2 - r6->x1),
													(int16_t)(r6->y2 - r6->y1),
													pItem->pText->bBackgroundColor);
											}
											//loc_23453790 -> loc_234537a8
											//sp8 = r6;
											texttable_write_text(*fp, r6);
										}
										//loc_234537bc
										pItem->pText->bUpdate = 0; //r8
									} //if (pItem->pText != 0)
#endif
									//loc_234537c4 /  / loc_23414804
									pItem->bData_0x3c = 0; //r8
								} //if (pItem->bEnable == 1)
								//loc_234537c8 /  / loc_23414808
								graphics_data.arData_0x1c[i] = pItem;
								i++;
								pItem++;
							} //while (i < r5->bNumItems)
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
									graphics_data.arData_0x1c[i] = 0; //r8
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
					graphic_swap_buffer(&graphics_data.bData_0xc);

					if (r5->bData_4 & 8)
					{
						graphic_swap_buffer(&graphics_data.bData_4);
					}

					graphics_data.wData_0x14 = graphics_data.wData_0x16;

					if (r5->bData_4 & 4)
					{
						//0x2345386c
						sub_2342ce64();

						if (graphics_data.bData_0xe & 1)
						{
							//0x2345387c
							viscale_osd_layer_enable(graphics_data.hViscaleOsd2);

							graphics_data.bData_0xe &= ~1;
						}
						//loc_23453890
					}
					//loc_23453890
					if ((r5->bData_4 & 8) && (graphics_data.bData_6 & 1))
					{
						viscale_osd_layer_enable(graphics_data.hViscaleOsd1);

						graphics_data.bData_6 &= ~1;
						graphics_data.bData_6 &= ~2;
					}
					//loc_234538bc
					graphic_copy_buffer(&graphics_data.bData_0xc);

					if (r5->bData_4 & 8)
					{
						graphic_copy_buffer(&graphics_data.bData_4);
					}
					//->loc_23453980
					r7->Data_0xc = 0; //r8
					//loc_23453984
				} //if (r7->command == 2)
			} //else if (r7->command == ....

			//loc_23453984
			if (graphics_data.wData_0x18 != 0)
			{
				//0x23453994
				graphics_data.wData_0x18--;

				if (graphics_data.wData_0x18 == 0)
				{
					//0x234539a8
					sub_2342ce64();

					if ((graphics_data.bData_0xe & 1) == 0)
					{
						//0x234539b8
						viscale_osd_layer_disable(graphics_data.hViscaleOsd2);

						graphics_data.bData_0xe |= 1;
					}
					//loc_234539cc
					if ((graphics_data.bData_6 & 1) == 0)
					{
						//0x234539d8
						viscale_osd_layer_disable(graphics_data.hViscaleOsd1);

						graphics_data.bData_6 |= 1;
					}
					//->loc_23453128
				}
				//->loc_23453128
			} //if (graphics_data.wData_0x18 != 0)
			//->loc_23453128
		} //if (err == 0)
		//->loc_23453128 /  / loc_23414168
	} //while (1)
}


/* 234539f0 / 2341406c - complete */
int graphic_init(Graphic_Params* r4)
{
#if 0
	console_send_string("graphic_init (todo.c): TODO\r\n");
#endif

	Viscale_Osd_Params viscaleParams;

	if (graphics_queue != 0)
	{
		return 4;
	}

	graphics_queue = OSQCreate(&Data_23493624, 1);

	Data_23493620 = r4->Data_16;

	memset(&graphics_data, 0, sizeof(graphics_data));

	if (r4->Data_0 != 0)
	{
		//OSD2
		viscaleParams.globalOffset = r4->osd2globalOffset;
		viscaleParams.Data_4 = r4->Data_0;
		viscaleParams.registerOffset = 0x4000; //OSD2 has same registers with an offset of 0x00004000

		graphics_data.bData_0xc = 0; //r6
		graphics_data.bData_0xf = 0; //r6
		graphics_data.bData_0xe = 1; //r7

		graphics_data.hViscaleOsd2 = viscale_osd_open(&viscaleParams);
	}
	//loc_23453a7c
	if (r4->Data_8 == 0)
	{
		graphics_data.hViscaleOsd1 = 0;
		//->loc_23453ab8
	}
	else
	{
		//OSD1
		viscaleParams.globalOffset = r4->osd1globalOffset;
		viscaleParams.Data_4 = r4->Data_8;
		viscaleParams.registerOffset = 0;

		graphics_data.bData_4 = 1; //r7
		graphics_data.bData_7 = 0; //r6
		graphics_data.bData_6 = 1; //r7

		graphics_data.hViscaleOsd1 = viscale_osd_open(&viscaleParams);
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
int graphic_start_job_2_5(Graphic_Queue_Item* pQueueItem, Graphic_Job_2_5* r5)
{
#if 0
	console_send_string("graphic_start_job_2_5 (graphic.c): TODO\r\n");
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


/* 23453b88 /  / 23414bc8 - complete */
int sub_23453b88(int a, Graphic_Queue_Item* b)
{
#if 0
	console_send_string("sub_23453b88 (todo.c): TODO\r\n");
#endif

	if (a != 0)
	{
		b->command = 4;
	}
	else
	{
		b->command = 6;
	}

	b->Data_0xc = 1;
	b->pPayload = a;

	int res = OSQPost(graphics_queue, b);
	if (res == 0)
	{
		while (b->Data_0xc != 0)
		{
			rtos_task_wait(1);
		}
	}

	return 0;
}


/* 23453be4 /  / 23414c24 - complete */
int sub_23414c24(Graphic_Queue_Item* pQueueItem, Struct_23414c24* r5)
{
#if 0
	console_send_string("sub_23414c24 (graphic.c): TODO\r\n");
#endif

	if (graphics_queue == 0)
	{
		return 3;
	}

	r5->bData_1 = sub_23411190();

	pQueueItem->command = 7;
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

	(Data_2349361c)(graphics_data.hViscaleOsd2, 720, 576);

	if (graphics_data.hViscaleOsd1 != 0)
	{
		(Data_2349361c)(graphics_data.hViscaleOsd1, 720, 576);
	}

	return 0;
}


/* 23453d34 - complete */
void graphic_copy_buffer(uint8_t* a)
{
#if 0
	console_send_string("graphic_copy_buffer (todo.c): TODO\r\n");
#endif

	if (a[1] == 0)
	{
		return;
	}

	a[1] = 0;

	viscale_osd_memcpy(a[0]);

	rtos_task_wait(1);
}


/* 23453d60 - complete */
void graphic_swap_buffer(uint8_t* a)
{
#if 0
	console_send_string("graphic_swap_buffer (todo.c): TODO\r\n");
#endif

	if (a[3] == 0)
	{
		a[3] = 1;
	}
	else
	{
		a[3] = 0;

		viscale_osd_swap_buffer(a[0]);
	}
}

