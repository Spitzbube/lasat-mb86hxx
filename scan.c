
#include <stdint.h>
#include "data.h"
#include "sub_2343df02.h"
#include "nit.h"
#include "scan.h"


typedef struct
{
	int fill_0; //0
	uint16_t wData_4; //4
	int fill_8[412]; //8
	//0x678
} Struct_2354eba8_Inner_0x16c;

typedef struct
{
	int state; //0
	int PSISectionMask; //4
	uint16_t numItems; //8
	uint16_t currentItem; //10
	uint16_t wData_0x0c; //12 = 0x0c
	uint16_t wData_0x0e; //14 = 0x0e
	uint16_t wData_0x10; //16 = 0x10
	uint16_t wData_0x12; //18 = 0x12
	uint8_t bData_0x14; //0x14 = 20
	uint8_t bData_0x15; //0x15
	uint8_t bData_0x16; //0x16
	uint8_t bData_0x17; //0x17
	uint8_t bData_0x18; //0x18 = 24
	uint16_t wData_0x1a; //0x1a = 26
	uint16_t Data_0x1c[150]; //0x1c = 28
	Struct_235fdfac* pList; //0x148
	OS_EVENT* sema; //0x14c
	int (*pfUpdateTransponderList)(); //0x150
	void (*pfProgress)(); //0x154
	int Data_0x158; //0x158
	uint16_t wData_0x15c; //0x15c
	uint16_t threadPrio; //0x15e
	void (*pfOnPSIData)(); //0x160
	void (*Data_0x164)(); //0x164
	void (*pfNext)(); //0x168
	Struct_2354eba8_Inner_0x16c Data_0x16c[150]; //0x16c + 150*0x678 = 3CA50

} Scan_Data; //->2358B764????


struct
{
	void* Data_0; //0
	void* Data_4; //4
} Data_23492090[100]; //23492090, size???


int scan_threadStack[THREAD_STACK_SIZE_SCAN]; //2354df28 -> 2354EBA8
Scan_Data scanData; //2354eba8 / 235ab204



/* 2340f0c8 - todo */
void sub_2340f0c8()
{
	console_send_string("sub_2340f0c8 (todo.c): TODO\r\n");

}


/* 2340f460 - todo */
int scan_update_transponder_list()
{
	Struct_2344dc3c sp;

#if 1
	console_send_string("scan_update_transponder_list (todo.c): TODO\r\n");
#endif

	Struct_235fdfac* r4 = &scanData.pList[scanData.numItems];

	psi_get_network_info(&sp, main_hPSIDecoder1);

	struct Struct_23627118_Inner0x54* r5 = sp.Data_8;

	uint16_t r6 = scanData.numItems;

	for (uint16_t r7 = 0; r7 < 200; r7++)
	{
		//loc_2340f494
		if (r6 > 199)
		{
			//->loc_2340f5a4
			break;
		}

		if (r5 == 0)
		{
			//->loc_2340f5a4
			break;
		}

		if ((r5->transport_stream_id != 0) &&
				(r5->original_network_id != 0) &&
				//0x2340f4b8
				(0 == scan_check_NIT(r5, r6)))
		{
			//0x2340f4cc
			r4->Data_0.Data_4 = r5->frequency * 100;
			r4->Data_0.wData_8 = r5->symbol_rate;
			r4->Data_0.wData_0x0c = 0; //r8
			r4->Data_0.wData_0x0a = 0xffff;
			r4->Data_0.wData_0x0e = sub_234512d8(r4->Data_0.Data_4);
#if 1 //TODO!!!
			r4->Data_0.Data_0.Bitfield_0.Data_0_18 = 0;
			r4->Data_0.Data_0.Bitfield_0.Data_19 = 0;
			r4->Data_0.Data_0.Bitfield_0.Data_20_27 = 0;
#endif
			r4->Data_0.Data_0.Bitfield_0.Data_28_31 = r5->bData_0x17;

			r4->transport_stream_id = r5->transport_stream_id;
			r4->wData_0x12 = r5->original_network_id;
			r4->wData_0x14 = 0; //r8
			r4->bData_0x16 = scanData.pList[scanData.currentItem].bData_0x16;

			r6++;
			r4++;
		}
		//loc_2340f580
		r5++;
		if (r5->wData_4 != 0)
		{
			//->loc_2340f5a4
			break;
		}
	} //for (uint16_t r7 = 0; r7 < 200; r7++)
	//loc_2340f5a4
	return r6;
}


/* 2340f5ac - todo */
void sub_2340f5ac()
{
#if 0
	console_send_string("sub_2340f5ac (todo.c): TODO\r\n");
#endif

	if (scanData.Data_0x164 != 0)
	{
		(scanData.Data_0x164)();
	}
}


/* 2340f5c0 - todo */
void sub_2340f5c0(struct Struct_234a73e8_Inner_0x248* r4, uint16_t r1, int sb)
{
#if 0
	console_send_string("sub_2340f5c0 (todo.c): TODO\r\n");
#endif

	struct
	{
		struct Struct_234a73e8_Inner_0x248* Data_0; //0 = sp_0x28
		Struct_235fdfac* Data_4; //4 = sp_0x2c
		int Data_8; //8 = sp_0x30
		uint16_t wData_12; //12 = sp_0x34

	} sp_0x28;
	Struct_235fdfac sp_0x10;
	Struct_2344dc3c sp4;

	uint16_t r7 = 0;
	//sl, =0x2354eba8 = scanData
	//r8 = 2354ECA8
	//->loc_2340f76c
	for (r7 = 0; r7 < r1; r7++)
	{
		//loc_2340f5e0
		struct Struct_234a73e8_Inner_0x248* r6 = &r4[r7];
		sp_0x28.Data_0 = r6;

		if (((r6->bData_0 & 1) != 0) && (scanData.bData_0x16 != 0))
		{
			//loc_2340f764
			continue;
		}
		//0x2340f604
		if ((scanData.bData_0x17 != 0) && ((r6->bData_0 & 8) != 0))
		{
			//loc_2340f764
			continue;
		}
		//0x2340f614
		if (scanData.wData_0x10 != 0)
		{
			if (sb & 0x40)
			{
				//loc_2340f764
				continue;
			}
			//0x2340f628
			psi_get_network_info(&sp4, main_hPSIDecoder1);

			struct Struct_23627118_Inner0x18* r0 = sp4.Data_4;
			uint16_t r1 = scanData.wData_0x10;

			if (r0->network_id != r1)
			{
				//loc_2340f764
				continue;
			}
			//loc_2340f64c
		}
		//loc_2340f64c
		int fp = 1;

		if (sp_0x28.Data_0->bData_0 & 0x40)
		{
			//0x2340f660
			if ((sb & ~0x40) == 0x08)
			{
				//0x2340f66c
				if ((r6->service_name != 0) || (scanData.bData_0x17 != 0))
				{
					//loc_2340f764
					continue;
				}
				//0x2340f680
				r4[r7].bData_0 |= 0x08;
				//->loc_2340f6e4
			}
			else
			{
				//loc_2340f68c
				fp = 0;

				if (r6->wData_0x336 != 0)
				{
					//0x2340f6a0
					if (scanData.bData_0x17 != 0)
					{
						//loc_2340f764
						continue;
					}
					//0x2340f6ac
					r4[r7].bData_0 |= 0x08;
					//loc_2340f6d4
					r4[r7].bData_0 &= ~0x40;
					//loc_2340f6e4
				}
				else
				{
					//loc_2340f6b8
					if ((r6->wData_0x33c == 0) && (r6->wData_0x338 == 0))
					{
						//loc_2340f764
						continue;
					}
					//0x2340f6cc
					r4[r7].bData_0 &= ~0x08;
					r4[r7].bData_0 &= ~0x40;
				}
			}
			//loc_2340f6e4
		}
		//loc_2340f6e4
		sp_0x10 = scanData.pList[scanData.currentItem];
		sp_0x28.Data_4 = &sp_0x10;
		sp_0x28.Data_8 = 0;

		if (scanData.bData_0x15 == 0)
		{
			//0x2340f71c
			if (fp != 0)
			{
				sp_0x10.transport_stream_id = r6->Data_0x32c;
				sp_0x10.wData_0x12 = r6->Data_0x330;
			}
		}
		//loc_2340f730
		if (0 == sub_2340c538(&sp_0x28))
		{
			//0x2340f740
			scanData.wData_0x15c++;

			if ((scanData.wData_0x15c - 1) < 150)
			{
				scanData.Data_0x1c[scanData.wData_0x15c - 1] = sp_0x28.wData_12;
			}
		}
		//loc_2340f764
	} //for (r7 = 0; r7 < r1; r7++)
	//0x2340f778
}


/* 2340f8bc - todo */
void scan_psi_callback(Struct_234a73e8* r5_)
{
	Struct_2344dc3c sp_0x10;
	uint8_t sp_0xc;
	struct Struct_234a73e8_Inner_0x248* sp8;
	uint16_t sp4;

#if 0
	console_send_string("scan_psi_callback (todo.c): TODO\r\n");
#endif

	OSSemPend(scanData.sema, 0, &sp_0xc);

	if (scanData.state == 3)
	{
		//0x2340f8e8
		scanData.state = 5;
		scanData.wData_0x15c = 0;

		int r5 = sub_234067a8(r5_, &sp4, &sp8);

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "scan_psi_callback: r5=0x%x, sp4=%d\r\n",
					r5, sp4);
			console_send_string(debug_string);
		}
#endif

		if (r5 & 1)
		{
			//loc_2340f930
			OSSemPost(scanData.sema);
			return;
		}

		if (r5 & 2)
		{
			//loc_2340f930
			OSSemPost(scanData.sema);
			return;
		}
		//0x2340f91c
		if (sp4 == 0)
		{
			//loc_2340f930
			OSSemPost(scanData.sema);
			return;
		}
		//0x2340f928
		if (sp4 < 150)
		{
			//loc_2340f940
			if (scanData.PSISectionMask & 0x40)
			{
				psi_get_network_info(&sp_0x10, main_hPSIDecoder1);
			}

			if (scanData.bData_0x14 != 0)
			{
				sub_2340f1f0(sp_0x10.Data_8);
			}

			sub_2340f5c0(sp8, sp4, r5);
		}
	}
	//loc_2340f930
	OSSemPost(scanData.sema);
}


/* 2340f97c - todo */
int scan_frontend_callback(uint8_t r6, Struct_235fdfac* r4)
{
	uint8_t sp;

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "scan_frontend_callback: r6=%d, scanData.state=%d, scanData.currentItem=%d\r\n",
				r6, scanData.state, scanData.currentItem);
		console_send_string(debug_string);
	}
#endif

	OSSemPend(scanData.sema, 0, &sp);

	if (scanData.state == 3)
	{
		//0x2340f9a8
		if (r6 != 0)
		{
			scanData.state = 2;
			//->loc_2340fa38
		}
		else
		{
			//0x2340f9b8
			scanData.state = 4;

			Struct_235fdfac* r0 = &scanData.pList[scanData.currentItem];

			if (r4 != 0)
			{
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "scan_frontend_callback: r0->transport_stream_id=0x%x, r0->Data_0.wData_8=%d, r0->Data_0.Data_0.Bitfield_0.Data_19=%d\r\n",
							r0->transport_stream_id, r0->Data_0.wData_8, r0->Data_0.Data_0.Bitfield_0.Data_19);
					console_send_string(debug_string);
				}
#endif

				//0x2340f9d8
				if (r0->transport_stream_id == 0xffff)
				{
					//0x2340f9e8
					{
						extern char debug_string[];
						sprintf(debug_string, "scan_frontend_callback: r4->Data_0.wData_8=%d, r4->Data_0.Data_0.Bitfield_0.Data_19=%d\r\n",
								r4->Data_0.wData_8, r4->Data_0.Data_0.Bitfield_0.Data_19);
						console_send_string(debug_string);
					}

					int r2 = r4->Data_0.Data_0.Bitfield_0.Data_19;

					if (((r0->Data_0.wData_8 - 10) > r4->Data_0.wData_8) ||
							((r0->Data_0.wData_8 + 10) < r4->Data_0.wData_8))
					{
						//loc_2340fa14
						r0->Data_0.wData_8 = r4->Data_0.wData_8;
					}
					//loc_2340fa18
					if (r2 != r0->Data_0.Data_0.Bitfield_0.Data_19)
					{
						r0->Data_0.Data_0.Bitfield_0.Data_19 = r2;
					}
				}
				//loc_2340fa38
			}
			//loc_2340fa38
		}
	}
	//loc_2340fa38
	OSSemPost(scanData.sema);

	return 0;
}


/* 2340fa48 - todo */
void sub_2340fa48()
{
	console_send_string("sub_2340fa48 (todo.c): TODO\r\n");

}


/* 2340fb14 - todo */
void scan_next(int r0)
{
	int sp;

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "scan_next: scanData.currentItem=%d/%d\r\n",
				scanData.currentItem, scanData.numItems);
		console_send_string(debug_string);
	}
#endif

	scanData.currentItem++;

	if (scanData.pfUpdateTransponderList == scan_update_transponder_list)
	{
		if (scanData.bData_0x18 != 0)
		{
			if (r0 != 0xff)
			{
				//->loc_2340fb70
				scanData.wData_0x1a = 5;
				//loc_2340fb74
			}
			else
			{
				//0x2340fb54
				if (scanData.wData_0x1a > 3)
				{
					scanData.wData_0x1a = 3;
					scanData.currentItem--;
					//->loc_2340fb74
				}
				else
				{
					//loc_2340fb70
					scanData.wData_0x1a = 5;
				}
			}
			//loc_2340fb74
			if (scanData.currentItem < scanData.numItems)
			{
				scanData.pList[scanData.currentItem].Data_0.Data_0.Bitfield_0.Data_28_31 =
						scanData.wData_0x1a;
			}
			//loc_2340fbac
		}
		//loc_2340fbac
	}
	//loc_2340fbac
	psi_stop(main_hPSIDecoder1, 1);

#if 1 //Limit Scan to a few transponders
	if (scanData.currentItem < 40)
#else
	if (scanData.currentItem < scanData.numItems)
#endif
	{
		scanData.state = 2;
		//->loc_2340fbf4
	}
	else
	{
		//0x2340fbd4
		scanData.state = 0;

		sp = 2;

		if (scanData.pfProgress != 0)
		{
			(scanData.pfProgress)(&sp, 0, 3);
		}
	}
	//loc_2340fbf4
	return;
}


/* 234102d8 - todo */
int scan_check_NIT(struct Struct_23627118_Inner0x54* a, uint32_t r1)
{
#if 0
	console_send_string("scan_check_NIT (todo.c): TODO\r\n");
#endif

	Struct_235fdfac* pList = scanData.pList;
	uint32_t freq = a->frequency * 100;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "scan_check_NIT: a->frequency=%d, a->symbol_rate=%d\r\n",
				a->frequency, a->symbol_rate);
		console_send_string(debug_string);
	}
#endif

	if ((a->frequency < 4000) || (a->frequency > 86100))
	{
		return 1;
	}

	if ((a->symbol_rate < 2200) || (a->symbol_rate > 7200))
	{
		return 1;
	}

	//0x23410314
	uint32_t lr = a->bData_0x17 & 0x0f;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "scan_check_NIT: lr=%d\r\n",
				lr);
		console_send_string(debug_string);
	}
#endif

	if (lr > 5)
	{
		//loc_23410368
		return 1;
	}

//	uint8_t r5 = scanData.bData_0x18;
	//->loc_2341037c
	for (uint16_t i = 0; i < r1; i++)
	{
		//loc_23410330
		if (pList->Data_0.Data_4 == freq)
		{
			//0x2341033c
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "Frequency found!\r\n");
				console_send_string(debug_string);
			}
#endif

			if (pList->bData_0x16 != 0)
			{
				//loc_23410368
				return 1;
			}
			//0x23410348
			if (pList->Data_0.wData_8 == a->symbol_rate/*r4*/)
			{
				//0x23410354
#if 0
				{
					extern char debug_string[];
					sprintf(debug_string, "Symbolrate found!\r\n");
					console_send_string(debug_string);
				}
#endif

				if (scanData.bData_0x18/*r5*/ != 0)
				{
					//loc_23410368
					return 1;
				}
				//0x2341035c
				if (lr == pList->Data_0.Data_0.Bitfield_0.Data_28_31)
				{
					//loc_23410368
					return 1;
				}
			}
			//loc_23410370
		}
		//loc_23410370
		pList++;
	} //for (uint16_t i = 0; i < r1; i++)
	//0x23410384
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "scan_check_NIT: New Transponder!\r\n");
		console_send_string(debug_string);
	}
#endif
	return 0;
}


/* 2340fbf8 - todo */
void scan_thread()
{
	uint8_t err; //sp_0x2c
	struct
	{
		int Data_0; //0
		uint16_t wData_4; //4
		uint16_t wData_6; //6
		void* Data_8; //8
	} sp_0x20;
	int sb = 3;
	Struct_2354dd70** r8;
	Struct_2354dd70* sp_0x18[2];

	sp_0x18[0] = /*Data_23491d8c.Data_0x28*/main_hFrontend1;
	sp_0x18[1] = /*Data_23491d8c.Data_0x2c*/Data_23491db8;

	r8 = sp_0x18;

	while (1)
	{
		//loc_2340fc28
		OSSemPend(scanData.sema, 0, &err);

		if (err == 0)
		{
			if (scanData.state == 2)
			{
				int r0;
				int r4 = sub_2340ed18(&scanData.pList[scanData.currentItem]);
				if (r4 != 4)
				{
					scanData.state = sb; //3

					if (0 == sub_2340d0d0())
					{
						//0x2340fc80

						fe_manager_tune(r8[scanData.pList[scanData.currentItem].bData_0x16],
								scanData.pList[scanData.currentItem],
								scan_frontend_callback, 0);

						if (r4 == 0)
						{
							//->loc_2340fd44
							r0 = 0xc8;
							//->loc_2340fda0
						}
						//loc_2340fd90
						else if (r4 == 2)
						{
							r0 = 0x0f;
							//->loc_2340fda0
						}
						else
						{
							//loc_2340fd9c
							r0 = 0x16;
						}
						//loc_2340fda0
					} //if (0 == sub_2340d0d0())
					else
					{
						//loc_2340fccc
						if (r4 == 0)
						{
							//0x2340fcd4
							fe_manager_tune(/*Data_23491d8c.Data_0x2c*/Data_23491db8/*sl*/,
									scanData.pList[scanData.currentItem],
									0, 0);

							fe_manager_tune(/*Data_23491d8c.Data_0x28*/main_hFrontend1/*r6*/,
									scanData.pList[scanData.currentItem],
									scan_frontend_callback, 0);
							//loc_2340fd44
							r0 = 200;
							//->loc_2340fda0
						}
						//loc_2340fd4c
						else if (r4 == 1)
						{
							//0x2340fd54
							fe_manager_tune(/*Data_23491d8c.Data_0x28*/main_hFrontend1/*r6*/,
									scanData.pList[scanData.currentItem],
									scan_frontend_callback, 0);
							//->loc_2340fd9c
							r0 = 22;
						}
						//loc_2340fd90
						else if (r4 == 2)
						{
							r0 = 15;
							//->loc_2340fda0
						}
						else
						{
							//loc_2340fd9c
							r0 = 22;
						}
					}
					//loc_2340fda0
					scanData.wData_0x12 = r0;
					//0x2340fda4
					if (scanData.pfProgress != 0) //-> sub_23470298
					{
						//0x2340fdb0

						sp_0x20.wData_6 = scanData.currentItem;
						sp_0x20.Data_8 = &scanData.pList[scanData.currentItem];
						sp_0x20.wData_4 = scanData.numItems;
						sp_0x20.Data_0 = 1;

						(scanData.pfProgress)(&sp_0x20.wData_4, 0, 2);
						(scanData.pfProgress)(&sp_0x20, 0, 3);
					}
					//->loc_2340fee0
				} //if (r4 != 4)
				else
				{
					//loc_2340fe00
					//r1 = scanData.pfNext;
					//r0 = 0xff;
					//->loc_2340fedc
					(scanData.pfNext)(0xff);
					//loc_2340fee0
				}
			} //if (scanData.state == 2)
			//loc_2340fe0c
			else if (scanData.state == 3)
			{
				//0x2340fe14
				scanData.wData_0x12--;
				if (scanData.wData_0x12 == 0)
				{
					Struct_2354dd70* r4 = /*Data_23491d8c.Data_0x28*/main_hFrontend1;

					if (0 == sub_2340d0d0())
					{
						r4 = r8[scanData.pList[scanData.currentItem].bData_0x16];
					}

					sub_2340ec54(r4, 0);
					//->loc_2340fe00
					(scanData.pfNext)(0xff);
					//loc_2340fee0
				}
				//loc_2340fee0
			} //else if (scanData.state == 3)
			//loc_2340fe60
			else if (scanData.state == 4) //Frontend Lock
			{
				//0x2340fe68
				psi_start(main_hPSIDecoder1,
						scanData.PSISectionMask,
						scanData.pfOnPSIData,
						scanData.Data_0x158,
						scanData.wData_0x0c,
						scanData.wData_0x0e);

				scanData.wData_0x12 = 1000;
				scanData.state = 3; //sb;
				//->loc_2340fee0
			} //else if (scanData.state == 4)
			//loc_2340fe9c
			else if (scanData.state == 5) //PSI Data received
			{
				//0x2340fea4
				if ((scanData.wData_0x15c != 0) &&
						(scanData.pfProgress != 0))
				{
					(scanData.pfProgress)(&scanData.Data_0x1c[0], scanData.wData_0x15c, 1);
				}

				if (scanData.pfUpdateTransponderList != 0)
				{
					scanData.numItems = (scanData.pfUpdateTransponderList)();

#if 1
					{
						extern char debug_string[];
						sprintf(debug_string, "scan_thread: scanData.numItems=%d\r\n",
								scanData.numItems);
						console_send_string(debug_string);
					}
#endif
				}
				//loc_2340fed4
				(scanData.pfNext)(0x00);
				//loc_2340fee0
			} //else if (scanData.state == 5)
			//loc_2340fee0
			OSSemPost(scanData.sema);
		} //if (err == 0)
		//loc_2340fee8
		rtos_task_wait(10);
		//->loc_2340fc28
	} //while(1)

}


/* 2340ff18 / 23416ef0 - todo */
void scan_init(Scan_Params* pParams)
{
	scanData.sema = OSSemCreate(1);

	scanData.threadPrio = pParams->threadPrio;
	scanData.bData_0x17 = pParams->bData_2;

	OSTaskCreateExt(scan_thread, 0, &scan_threadStack[THREAD_STACK_SIZE_SCAN-1],
			pParams->threadPrio & 0xff, pParams->threadPrio,
			scan_threadStack, THREAD_STACK_SIZE_SCAN, "SCAN", 3);
}


/* 2340ff80 - todo */
int scan_start(Struct_2343df02* r4)
{
	uint8_t err; //sp
	uint8_t i;

#if 0
	console_send_string("scan_start (todo.c): TODO\r\n");
#endif

	OSSemPend(scanData.sema, 0, &err);

	scanData.state = 2;

	scanData.pList = r4->pList;
	scanData.numItems = r4->listLen;
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "scan_start: scanData.numItems=%d\r\n",
				scanData.numItems);
		console_send_string(debug_string);
	}
#endif

#if 1 //Skip first transponders
	scanData.currentItem = 35;
#else
	scanData.currentItem = 0;
#endif
	scanData.pfProgress = r4->pfProgress;
	scanData.Data_0x158 = r4->Data_8;
	scanData.bData_0x16 = r4->bData_0x11;
	scanData.bData_0x14 = r4->bData_0x12;
	scanData.bData_0x18 = 0;
	scanData.wData_0x0c = 0;
	scanData.wData_0x0e = 0;
	scanData.wData_0x10 = 0;

	if (r4->wData_0x14 < 0)
	{
		scanData.pfNext = scan_next;
		scanData.pfOnPSIData = scan_psi_callback;
		scanData.PSISectionMask = 0x0b;

		if (r4->bData_0x10 == 0)
		{
			scanData.pfUpdateTransponderList = 0;
			//->loc_23410088
		}
		else
		{
			//0x23410024
			if (0 == sub_2340ed18(scanData.pList))
			{
				scanData.pfUpdateTransponderList = sub_2340f0c8;
				//->loc_2341007c
			}
			else
			{
				//0x23410038
				Struct_235fdfac* r0;

				scanData.pfUpdateTransponderList = scan_update_transponder_list;

				r0 = &scanData.pList[scanData.currentItem];

//				if ((r0->bData_3 >> 4) == 6)
				if (r0->Data_0.Data_0.Bitfield_0.Data_28_31 == 6)
				{
					//0x23410060
					scanData.bData_0x18 = 1; //r7
					scanData.wData_0x1a = 5;

//					r0->bData_3 = (r0->bData_3 & ~0xf0) | 0x50;
					r0->Data_0.Data_0.Bitfield_0.Data_28_31 = 5;
				}
				//loc_2341007c
			}
			//loc_2341007c
			scanData.PSISectionMask |= 0x40;
		}
		//loc_23410088
		if (r4->wData_0x14 == -2)
		{
			scanData.wData_0x10 = r4->wData_0x16;
		}
		//->loc_234100d0
	} //if (r4->wData_0x14 < 0)
	else
	{
		//loc_2341009c
		scanData.pfUpdateTransponderList = Data_23492090[r4->wData_0x14].Data_4;
		scanData.pfOnPSIData = Data_23492090[r4->wData_0x14].Data_0;

		scanData.PSISectionMask = 0x4b;
		scanData.wData_0x0e = r4->wData_0x16;
		scanData.pfNext = sub_2340fa48;
	}
	//loc_234100d0
	if (scanData.bData_0x14 != 0)
	{
		Struct_2354eba8_Inner_0x16c* r4;

		scanData.PSISectionMask |= 0x40;

		r4 = scanData.Data_0x16c;

		for (i = 0; i < 150; i++)
		{
			//loc_234100f4
			memset(r4, 0, sizeof(Struct_2354eba8_Inner_0x16c));

			r4->wData_4 = 1; //r7

			r4++; // r4 += 0x678; //3CA50
		}
	}
	//loc_2341011c
	OSSemPost(scanData.sema);

	return err;
}


/* 23410148 - todo */
int sub_23410148(Struct_23410148* r5, int r6, void (*r7)(), int r8)
{
	uint8_t err; //sp

	OSSemPend(scanData.sema, 50, &err);

	if (err == 0)
	{
		scanData.state = 2;

		scanData.pList = r5->Data_0;
		scanData.numItems = r5->wData_4;
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_23410148: scanData.numItems=%d\r\n",
					scanData.numItems);
			console_send_string(debug_string);
		}
#endif
		scanData.currentItem = 0;
		scanData.pfProgress = r5->Data_12;
		scanData.Data_0x158 = 0;
		scanData.PSISectionMask = r6;
		scanData.pfUpdateTransponderList = 0;
		scanData.pfOnPSIData = sub_2340f5ac;
		scanData.Data_0x164 = r7;
		scanData.bData_0x16 = 0;
		scanData.bData_0x14 = 0;
		scanData.bData_0x18 = 0;
		scanData.wData_0x0c = r8;
		scanData.wData_0x10 = 0;
		scanData.pfNext = scan_next;

		OSSemPost(scanData.sema);
	}
	//loc_234101e0
	return err;
}


/* 234101e8 - complete */
int sub_234101e8()
{
	uint8_t err; //sp

	OSSemPend(scanData.sema, 0, &err);

	psi_stop(main_hPSIDecoder1, 1);

	scanData.state = 0;
	scanData.pfProgress = 0;
	scanData.Data_0x158 = 0;

	OSSemPost(scanData.sema);

	return err;
}


