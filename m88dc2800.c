

#include "data.h"
#include "sub_2340a6a0.h"
#include "Struct_23443080.h"
#include "m88dc2800.h"


#pragma thumb


int sub_23443080(Struct_23443080*, int reg, void* pdata);
int sub_23444d74(Struct_23443080*, uint8_t reg, uint8_t data);
int sub_23448570(Struct_23443080*, uint8_t, uint8_t);


/* 234420fc - complete */
int sub_234420fc(Struct_23472f1c* r4, uint32_t* r5)
{
	uint8_t sp4 = 0;

#if 0
	console_send_string("sub_234420fc (todo.c): TODO\r\n");
#endif

	if ((r4 == 0) || (r5 == 0))
	{
		return 1;
	}

	if (0 != (r4->Data_16->i2c_write_reg_byte)(r4->Data_16, r4->bData_13, 0, 0))
	{
		return 2;
	}

	if (0 != (r4->Data_16->i2c_read_reg)(r4->Data_16, r4->bData_13, 0xfd, &sp4, 1))
	{
		return 2;
	}

	*r5 = sp4;

	return 0;
}


typedef struct
{
	int fill_0; //0
	int Data_4; //4
	int Data_8; //8

} Struct_sub_23442144;


/* 23442144 - complete */
int sub_23442144(Struct_sub_23442144* r0, int r1)
{
#if 0
	console_send_string("sub_23442144 (todo.c): TODO\r\n");
#endif

	if ((r0 == 0) || (r1 == 0))
	{
		//loc_2344214e
		return 1;
	}
	//loc_23442152
	if (r0->Data_4 != 3)
	{
		return 3;
	}
	//loc_2344215c
	switch (r0->Data_8)
	{
	case 2:
		//loc_2344216c
		return sub_234743ba(r0, r1);

	case 3:
		return sub_23475854(r0, r1);

	default:
		return 8;
	}
}


/* 23442940 - todo */
int sub_23442940(int a, int b, Struct_23472f1c_Inner16* r2, Struct_23472f1c* r3, Struct_23442f9a_4* r5, Struct_23442966* r4)
{
#if 0
	console_send_string("sub_23442940 (todo.c): TODO\r\n");
#endif

	if ((r3 == 0) || (r2 == 0) || (r4 == 0) || (r5 == 0))
	{
		return 1;
	}
	//loc_2344295a
	r4->Data_8 = 0;
	r4->Data_0 = r3;
	r4->Data_4 = r5;

	return sub_23472ef0(a, b, r2, r3);
}


/* 23442966 - complete */
int sub_23442966(Struct_23442966* r4)
{
	int res;

#if 0
	console_send_string("sub_23442966 (todo.c): TODO\r\n");
#endif

	if ((r4 == 0) || (r4->Data_0 == 0) ||
			(r4->Data_4 == 0) || (r4->Data_4->Data_0 == 0))
	{
		return 1;
	}

	res = sub_23472f1c(r4->Data_0);
	if (res != 0)
	{
		return res;
	}

	return (r4->Data_4->Data_0)(r4->Data_4);
}


/* 23442dcc - complete */
int sub_23442dcc(Struct_23472f1c_Inner16* r4, int addr, uint8_t reg, uint8_t* d, int count)
{
	int res;

#if 0
	console_send_string("sub_23442dcc (todo.c): TODO\r\n");
#endif

	if (r4 == 0)
	{
		return 1;
	}

	res = (r4->i2c_master_send)(r4, addr, &reg, 1, 1/*flags*/);
	if (res != 0)
	{
		return res;
	}

	res = (r4->i2c_master_receive)(r4, addr, d, count, 3/*flags?*/);
	return res;
}


/* 23442e04 - complete */
int sub_23442e04(Struct_23472f1c_Inner16* r4, int addr, int reg, void* data, uint32_t count)
{
	uint8_t buf[0x84];
#if 0
	console_send_string("sub_23442e04 (todo.c): TODO\r\n");
#endif


	if ((r4 == 0) || (count > 0x80))
	{
		return 1;
	}

	buf[0] = reg;

	memcpy(buf + 1, data, count);

	return (r4->i2c_master_send)(r4, addr, buf, count + 1, 3/*flags*/);
}


/* 23442e3c - complete */
int sub_23442e3c(Struct_23472f1c_Inner16* r0, int addr, int reg, int data)
{
#if 0
	console_send_string("sub_23442e3c (todo.c): TODO\r\n");
#endif

	if (r0 == 0)
	{
		return 1;
	}

	return (r0->i2c_write_reg)(r0, addr, reg, &data, 1);
}


/* 23442eac - todo */
void sub_23442eac()
{
#if 1
	console_send_string("sub_23442eac (todo.c): TODO\r\n");
#endif


}


/* 23442f40 - todo */
void sub_23442f40()
{
#if 1
	console_send_string("sub_23442f40 (todo.c): TODO\r\n");
#endif


}


/* 23442f5e - todo */
void sub_23442f5e()
{
#if 1
	console_send_string("sub_23442f5e (todo.c): TODO\r\n");
#endif


}


/* 23442f7c - todo */
void sub_23442f7c()
{
#if 1
	console_send_string("sub_23442f7c (todo.c): TODO\r\n");
#endif


}


/* 23442f9a - complete */
int sub_23442f9a(int a, int b, void* r6, int r5, Struct_23476318* r7, Struct_23442f9a_4* r4)
{
	int res;

#if 0
	console_send_string("sub_23442f9a (todo.c): TODO\r\n");
#endif

	if ((r4 == 0) || (r6 == 0) || (r7 == 0))
	{
		return 1;
	}
	//loc_23442fb8
	res = sub_23476318(a, b, r6, r5, 0, r7);
	if (res != 0)
	{
		return res;
	}

	r4->Data_0 = sub_23442f7c;
	r4->Data_4 = sub_23442f5e;
	r4->Data_12 = sub_23442f40;
	r4->Data_8 = sub_23442eac;
	r4->Data_0x14 = 0;
	r4->Data_0x10 = 0;
	r4->bData_0x18 = 0;
	r4->bData_0x24 = a;
	r4->Data_0x1c = b;
	r4->Data_0x2c = r7;
	r4->Data_0x20 = r6;
	r4->Data_0x28 = r5;

	return res;
}


/* 23443080 - complete */
int sub_23443080(Struct_23443080* r4, int reg, void* pdata)
{
#if 0
	console_send_string("sub_23443080 (todo.c): TODO\r\n");
#endif

	(r4->WriteReg)(0x86, 0xc0);

	if (0 != i2c_master_send(main_hI2c0, r4->tuner_dev_addr, &reg, 1))
	{
		return -1;
	}

	(r4->WriteReg)(0x86, 0xc0);

	if (0 != i2c_master_receive(main_hI2c0, r4->tuner_dev_addr, pdata, 1))
	{
		return -1;
	}

	return 0;
}


/* 23444700 - complete */
void sub_23444700(Struct_23443080* r4)
{
	uint8_t sp;

#if 0
	console_send_string("sub_23444700 (todo.c): TODO\r\n");
#endif

	if (r4->bData_0x19 != 0)
	{
		sub_23444d74(r4, 0x08, 0x00);
		sub_23444d74(r4, 0x07, 0x00);
	} //if (r4->bData_0x19 != 0)
	//loc_2344471e
	if (r4->wData_8 != 2)
	{
		//Set sleep registers
		sub_23444d74(r4, 0x16, 0xb0);
	    sub_23444d74(r4, 0x09, 0x6d);
	} //if (r4->wData_8 != 2)
	else
	{
		//loc_23444734
        sub_23443080(r4, 0x61, &sp);
        sp |= 0x10;
        sub_23444d74(r4, 0x61, sp);

        sub_23444d74(r4, 0x16, 0xb0);
        sub_23444d74(r4, 0x09, 0x75);
        sub_23444d74(r4, 0x0c, 0x08);
        sub_23444d74(r4, 0x71, 0x50);
        sub_23444d74(r4, 0x23, 0x40);
        sub_23444d74(r4, 0x70, 0x45);
        sub_23444d74(r4, 0x1d, 0x02);
        sub_23444d74(r4, 0x1c, 0x14);

        sub_23443080(r4, 0x1b, &sp);
        sp &= ~0x03;
        sub_23444d74(r4, 0x1b, sp);

        sub_23443080(r4, 0x21, &sp);
        sp &= 0x7f;

        if (r4->Data_4 > 500000) //0x7a120
        {
        	sp &= 0xdf;
        }
        //loc_234447e2
        sub_23444d74(r4, 0x21, sp);

        sub_23443080(r4, 0x5e, &sp);
        sp &= 0x7f;
        sub_23444d74(r4, 0x5e, sp);

        sub_23443080(r4, 0x3e, &sp);
        sp &= 0x7f;
        sp |= 0x02;
        sub_23444d74(r4, 0x3e, sp);

        sub_23443080(r4, 0x68, &sp);
        sp &= 0xf7;
        sub_23444d74(r4, 0x68, sp);
	}
	//loc_23444844
    sub_23444d74(r4, 0x28, 0x00);
}


/* 234448ec - todo */
void sub_234448ec(Struct_23443080* r5, uint32_t r4) //mt_fe_tn_set_freq_tc2800
{
	uint8_t sp4;
	uint8_t sp;

#if 0
	console_send_string("sub_234448ec (todo.c): TODO\r\n");
#endif

	sub_23444856(r5);

	r5->Data_4 = r4;

	if (r5->bData_0x19 != 0)
	{
		if (r4 > 106900) //0x1a194
		{
			sub_23444d74(r5, 0x08, 0x08);
			//->r2, #0x50
			//->loc_2344491e
			sub_23444d74(r5, 0x7, 0x50);
		}
		else
		{
			//loc_23444912
			sub_23444d74(r5, 0x08, 0x00);
			//r2, #0x0
			sub_23444d74(r5, 0x7, 0x00);
		}
	}
	//loc_23444926
	if (r4 > 500000) //r7 = 0x7a120)
	{
		//r2, #0xb9
		sub_23444d74(r5, 0x21, 0xb9);
		//->loc_23444932
	}
	else
	{
		//loc_23444930
		//r2, #0x99
		sub_23444d74(r5, 0x21, 0x99);
	}
	//0x2344493a
    sub_234445ae(r5); //mt_fe_tn_wakeup_tc2800
    sub_23444d74(r5, 0x05, 0x7f);
    sub_23444d74(r5, 0x06, 0xf8);
    sub_234430c0(r5); //_mt_fe_tn_set_RF_front_tc2800
    sub_2344392a(r5); //_mt_fe_tn_set_PLL_freq_tc2800
    sub_23443e82(r5); //_mt_fe_tn_set_DAC_tc2800
    sub_23443d00(r5); //_mt_fe_tn_set_BB_tc2800
    sub_2344433c(r5); //_mt_fe_tn_preset_tc2800
    sub_23444d74(r5, 0x05, 0x00);
    sub_23444d74(r5, 0x06, 0x00);
    //r6, =0x927c0 = 600000
    if (r5->chipId == 0xd1)
    {
        sub_23444d74(r5, 0x00, 0x01);
        sub_23444d74(r5, 0x00, 0x00);
        rtos_task_wait(0x1);
        sub_23444d74(r5, 0x41, 0x00);
        rtos_task_wait(0x1);
        sub_23444d74(r5, 0x41, 0x02);
        sub_23443080(r5, 0x69, &sp);
        sp &= 0x0f;

        sub_23443080(r5, 0x61, &sp4);
        sp4 &= 0x0f;

        if (sp4 == 0x0c)
        {
        	sub_23444d74(r5, 0x6a, 0x59);
        }
        //loc_234449f8
        if (sp > 2)
        {
        	if (r4 > 600000) //r6)
        	{
        		//r2, #0x44
        		//->loc_23444a12
        		sub_23444d74(r5, 0x66, 0x44);
        	}
        	//loc_23444a08
        	else if (r4 > 500000) //0x7a120
        	{
        		//r2, #0x64
        		//->loc_23444a12
        		sub_23444d74(r5, 0x66, 0x64);
        	}
        	else
        	{
        		//loc_23444a10
        		//r2, #0x74
        		sub_23444d74(r5, 0x66, 0x74);
        	}
        }
        //loc_23444a1a
        //r1, =0x493e0 = 300000
        //r2, =0x35b60 = 220000
        if (sp < 3)
        {
            if (r4 > 800000) //0xc3500)
            {
            	//r2 = 0x64;
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x64);
            }
            //loc_23444a30
            else if (r4 > 600000) //r6
            {
            	//loc_23444a38
            	//r2, #0x54
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x54);
            }
            else if (r4 > 500000) //r7
			{
            	//loc_23444a38
            	//r2, #0x54
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x54);
			}
            //loc_23444a94
            else if (r4 > 300000) //r1
            {
            	//loc_23444a3c
            	//r2, #0x43
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x43);
            }
            //0x23444a98
            else if (r4 > 220000) //r2
            {
            	//loc_23444a38
            	//r2, #0x54
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x54);
            }
            else if (r4 > 110000) //0x1adb0
            {
            	//loc_23444a40
            	//r2, #0x14
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x14);
            }
            else
            {
            	//->loc_23444a38
            	//r2, #0x54
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x54);
            }

            rtos_task_wait(1);
        }
        //loc_23444a44
        else if (sp4 < 12)
        {
        	if (r4 > 800000) //0xc3500
        	{
        		//loc_23444a40
            	//r2, #0x14
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x14);
        	}
        	else if (r4 > 600000) //r6)
        	{
        		//loc_23444a40
            	//r2, #0x14
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x14);
        	}
        	else if (r4 > 500000) //7)
        	{
        		//r2, #0x34
        		//loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x34);
        	}
        	//loc_23444a94
        	else if (r4 > 300000) //r1)
        	{
        		//loc_23444a3c
            	//r2, #0x43
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x43);
        	}
        	else if (r4 > 220000) //r2)
        	{
            	//loc_23444a38
            	//r2, #0x54
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x54);
        	}
            else if (r4 > 110000) //0x1adb0
            {
            	//loc_23444a40
            	//r2, #0x14
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x14);
            }
        	else
        	{
        		//loc_23444a38
            	//r2, #0x54
            	//->loc_23444a5a
        		sub_23444d74(r5, 0x87, 0x54);
        	}

        	rtos_task_wait(1);
        }
        //loc_23444a68
    }
    //loc_23444a6a -> loc_23444aa4
    else if (r5->chipId == 0xe1)
    {
    	//0x23444aa8

    	//TODO!!!
    }
    //loc_23444a68
}


/* 23444d3c - complete */
int m88dc2800_get_chip_version(Struct_23443080* a)
{
	uint8_t id;

	if (0 != sub_23443080(a, 0x01, &id))
	{
		//->loc_23444d70
		return 0xff;
	}

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "m88dc2800_get_chip_version: id=0x%02x\r\n", id);
		console_send_string(debug_string);
	}
#endif

	if ((id == 0xb1) || (id == 0xb2))
	{
		//loc_23444d56
		return 11;
	}
	//loc_23444d5a
	else if (((id >> 4) == 0x0b)) //VDR110: 0xb5
	{
		return 10;
	}
	//loc_23444d64
	else if ((id == 0x0d) //D1
			|| (id == 0x8e)) //E1
	{
		//loc_23444d6c
		return 1;
	}
	//loc_23444d70
	else
	{
		return 0xff;
	}
}


/* 23444d74 - complete */
int sub_23444d74(Struct_23443080* r4, uint8_t reg, uint8_t data)
{
	uint8_t buf[2];

	buf[0] = reg;
	buf[1] = data;

	(r4->WriteReg)(0x86, 0xc0);

	if (0 != i2c_master_send(main_hI2c0, r4->tuner_dev_addr, buf, 2))
	{
		return -1;
	}

	return 0;
}


/* 23445408 - todo */
int sub_23445408(Struct_23443080* r4, uint8_t reg, uint8_t* pdata)
{
#if 0
	console_send_string("sub_23445408 (todo.c): TODO\r\n");
#endif

	(r4->WriteReg)(0x86, 0xc0);

	if (0 != i2c_master_send(main_hI2c0, r4->tuner_dev_addr, &reg, 1))
	{
		return -1;
	}

	(r4->WriteReg)(0x86, 0xc0);

	if (0 != i2c_master_receive(main_hI2c0, r4->tuner_dev_addr, pdata, 1))
	{
		return -1;
	}

	return 0;
}


/* 23445448 - complete */
int sub_23445448(Struct_23443080* r5, uint8_t r6, int r2, uint8_t r0, uint8_t r1)
{
	uint8_t sp = 0; //r4
	uint8_t r4;
	uint8_t r7;

#if 0
	console_send_string("sub_23445448 (todo.c): TODO\r\n");
#endif

	if (r0 < r1)
	{
		return -1;
	}

	r1 -= r0;

	r4 = r2 << (7 + r1);
	r4 = r4 >> (7 - r0);

	r7 = 0xff << (7 + r1);
	r7 = r7 >> (7 - r0);

	sub_23445408(r5, r6, &sp);

	sp &= ~r7;
	sp |= r4;

	sub_23448570(r5, r6, sp);

	return 0;
}


/* 2344549a - todo */
void sub_2344549a(Struct_23443080* r4)
{
	uint8_t r6 = 0;
	uint8_t r7;
//	void* sp_0xc = &r4->Data_0x20;
	uint8_t sp8 = 0; //r6
	uint8_t sp4 = 0; //r6
	uint32_t sp = 112000; // 0x1b580;
	uint32_t r5 = r4->Data_4;
	uint32_t r7_ = 331000; //0x50cf8;

#if 0
	console_send_string("sub_2344549a (todo.c): TODO\r\n");
#endif

	if (r4->bData_0x30 == 0)
	{
		//0x234454ba
		sub_23448570(r4, 0x7b, 0x27);
		sub_23448570(r4, 0x7e, 0x22);

		if (r5 <= 800000) //0xC3500
		{
			//loc_234454d4
			//r2, #0xe7
			//->loc_23445520
			sub_23448570(r4, 0x7d, 0xe7);
		}
		else
		{
			//loc_234454d8
			if (((r4->wData_8 == 1) || (r4->wData_8 == 2))
					//loc_234454e4
					&& (r4->bData_0x1a >= 2))
			{
				//loc_234454d4
				//r2, #0xe7
				//->loc_23445520
				sub_23448570(r4, 0x7d, 0xe7);
			}
			else
			{
				//loc_234454ea
				//r2, #0x67
				//->loc_23445520
				sub_23448570(r4, 0x7d, 0x67);
			}
		}

	} //if (r4->bData_0x30 == 0)
	//loc_234454ee
	else if (r4->bData_0x30 == 1)
	{
		//0x234454f2
		sub_23448570(r4, 0x7b, 0x1b);
		sub_23448570(r4, 0x7e, 0x22);

		if (r5 <= 800000) //0xC3500
		{
			//loc_2344551e
			//r2, #0x9b
			//->loc_23445520
			sub_23448570(r4, 0x7d, 0x9b);
		}
		else
		{
			//0x2344550c
			if (((r4->wData_8 == 1) || (r4->wData_8 == 2))
					//loc_23445518
					&& (r4->bData_0x1a >= 2))
			{
				//loc_2344551e
				//r2, #0x9b
				//->loc_23445520
				sub_23448570(r4, 0x7d, 0x9b);
			}
			else
			{
				//loc_23445546
				//r2, #0x1b
				//->loc_23445520
				sub_23448570(r4, 0x7d, 0x1b);
			}
		}

	} //else if (r4->bData_0x30 == 1)
	else
	{
		//loc_2344554a
		sub_23448570(r4, 0x7b, 0x2b);
		sub_23448570(r4, 0x7e, 0x55);

		//r2, #0xab
		//->loc_23445520
		sub_23448570(r4, 0x7d, 0xab);
	}
	//0x23445528
	if (r5 <= sp) //112000) //sp)
	{
		//0x2344552e
		sub_23448570(r4, 0x71, 0x08);
		sub_23448570(r4, 0x82, 0xac);

		//r2, #0xfd
		//->loc_2344557c
		sub_23448570(r4, 0x0e, 0xfd);

		//r2, #0x8b
		//->loc_234455a8
		sub_23448570(r4, 0x76, 0x8b);
	}
	//loc_23445562
	else if (r5 <= r7_) //331000) //r7_)
	{
		//0x23445566
		sub_23448570(r4, 0x71, 0x04);
		sub_23448570(r4, 0x82, 0x8c);

		//r2, #0x7d
		//loc_2344557c
		sub_23448570(r4, 0x0e, 0x7d);

		//r2, #0x8b
		//->loc_234455a8
		sub_23448570(r4, 0x76, 0x8b);
	}
	else
	{
		//loc_23445588
		sub_23448570(r4, 0x71, 0x00);
		sub_23448570(r4, 0x82, 0x8c);
		sub_23448570(r4, 0x0e, 0x7d);

		//r2, #0x6b
		//loc_234455a8
		sub_23448570(r4, 0x76, 0x6b);
	}
	//0x234455b0
	if (r5 <= 283000) //0x45178
	{
		//0x234455b6
		//r2, #0xc0
		//->loc_234455c6
		sub_23448570(r4, 0x7a, 0xc0);
	}
	//loc_234455ba
	else if (r5 <= 498000) //0x79950
	{
		//0x234455c0
		// r2, #0xc2
		//->loc_234455c6
		sub_23448570(r4, 0x7a, 0xc2);
	}
	else
	{
		//loc_234455c4
		//r2, #0xc4
		sub_23448570(r4, 0x7a, 0xc4);
	}
	//0x234455ce
	if ((r4->bData_0x0c == 1) || (r4->bData_0x0c == 3) || (r4->bData_0x0c == 4))
	{
		//loc_234455dc
		if (r4->chipId == 0xb4)
		{
			//0x234455e2
			//r2, #0xe1
			//->loc_234455e8
			sub_23448570(r4, 0x1f, 0xe1);

			sp4 = 2;
			//->loc_23445624
		}
		else
		{
			//loc_234455e6
			//r2, #0xc1
			//loc_234455e8
			sub_23448570(r4, 0x1f, 0xc1);

			sp4 = 2;
			//->loc_23445624
		}
	}
	else
	{
		//loc_234455f6
		if ((r5 <= 331000) //0x50cf8
				//0x234455fc
				&& ((r4->bData_0x1c == 0) || (r4->bData_0x1c == 3)))
		{
			//loc_23445606
			r6 = 2;

#if 1
			if (r4->chipId == 0xb4)
			{
				//0x2344560e
				//r2, #0xe9
				//->loc_2344561c
				sub_23448570(r4, 0x1f, 0xe9);
			}
			else
			{
				//loc_23445612
				//r2, #0xc9
				//->loc_2344561c
				sub_23448570(r4, 0x1f, 0xc9);
			}
#else
			switch (r4->chipId)
			{
			case 0xb4:
				//0x2344560e
				r2 = 0xe9;
				break;

			default:
				//loc_23445612
				r2 = 0xc9;
				break;
			}
#endif
		}
		else
		{
			//loc_2344564a
			r6 = 1;
#if 1
			if (r4->chipId == 0xb4)
			{
				//loc_23445616
				//r2, #0xe5
				//->loc_2344561c
				sub_23448570(r4, 0x1f, 0xe5);
			}
			else
			{
				//loc_2344561a
				//r2, #0xc5
				//loc_2344561c
				sub_23448570(r4, 0x1f, 0xc5);
			}
#else
			switch (r4->chipId)
			{
			case 0xb4:
				//loc_23445616
				r2 = 0xe5;
				break;

			default:
				//loc_2344561a
				r2 = 0xc5;
				break;
			}
#endif
		}
		//loc_23445624
	}
	//loc_23445624
	if (((r4->wData_8 == 1) || (r4->wData_8 == 2))
		//loc_23445630
		&& (r4->bData_0x1a == 3))
	{
		//0x23445636
		if ((r4->bData_0x30 == 0) || (r4->bData_0x30 == 1))
		{
			//loc_23445642
			sp8 = 0x22;
			r7 = 0x22;
			//->loc_2344565e
		}
		else
		{
			//loc_23445654
			sp8 = 0x55;
			r7 = 0x55;
			//->loc_2344565e
		}
	}
	else
	{
		//loc_2344565c
		r7 = 0x77;
	}
	//loc_2344565e
	if ((r4->bData_0x1c == 0) || (r4->bData_0x1c == 3))
	{
		//loc_23445668
		sub_23448570(r4, 0xb6, 0x02);
		sub_23448570(r4, 0xb9, r6);
		sub_23448570(r4, 0xb9, sp8);
		//r2= r6
		//->loc_23445720
		sub_23448570(r4, 0xb9, r6);
		//0x23445728
		sub_23448570(r4, 0xb9, sp8);
		sub_23448570(r4, 0xb9, r6);
		sub_23448570(r4, 0xb9, sp8);
		sub_23448570(r4, 0xb9, r6);
		sub_23448570(r4, 0xb9, r7);
		sub_23448570(r4, 0xb9, r6);
		sub_23448570(r4, 0xb9, sp8);
		//r2 = sp8
		//loc_23445770
		sub_23448570(r4, 0x7e, sp8);
	}
	//loc_2344568a
	else if (r4->bData_0x1c == 1)
	{
		sub_23448570(r4, 0xb6, 0x02);
		sub_23448570(r4, 0xb9, r6);
		sub_23448570(r4, 0xb9, r7);
		sub_23448570(r4, 0xb9, r6);
		sub_23448570(r4, 0xb9, r7);
		sub_23448570(r4, 0xb9, r6);
		sub_23448570(r4, 0xb9, sp8);
		sub_23448570(r4, 0xb9, r6);
		sub_23448570(r4, 0xb9, r7);
		sub_23448570(r4, 0xb9, r6);
		sub_23448570(r4, 0xb9, r7);
		//r2 = r7
		//->loc_23445770
		sub_23448570(r4, 0x7e, r7);
	}
	else
	{
		//loc_23445700
		sub_23448570(r4, 0xb6, 0x02);
		sub_23448570(r4, 0xb9, sp4);
		sub_23448570(r4, 0xb9, sp8);
		//r2 = sp4
		//loc_23445720
		sub_23448570(r4, 0xb9, sp4);
		//0x23445728
		sub_23448570(r4, 0xb9, sp8);
		sub_23448570(r4, 0xb9, r6);
		sub_23448570(r4, 0xb9, sp8);
		sub_23448570(r4, 0xb9, r6);
		sub_23448570(r4, 0xb9, r7);
		sub_23448570(r4, 0xb9, r6);
		sub_23448570(r4, 0xb9, sp8);
		//r2 = sp8
		//loc_23445770
		sub_23448570(r4, 0x7e, sp8);
	}

	if (r4->bData_0x1d == 1)
	{
		//0x2344577e
		if (r5 <= sp) //112000) //sp)
		{
			//0x23445784
			if (r5 <= 54000) //0xd2f0
			{
				//0x2344578a
				//r2, #0x0
				//->loc_23445790
				sub_23448570(r4, 0x75, 0x00);
			}
			else
			{
				//loc_2344578e
				//r2, #0x7
				//loc_23445790
				sub_23448570(r4, 0x75, 0x07);
			}
		}
		else
		{
			//loc_2344579c
			//r2, #0x27
			//->loc_23445790
			sub_23448570(r4, 0x75, 0x27);
		}
	}
	//loc_23445798
	return;
}


/* 234457a0 - todo */
void sub_234457a0(Struct_23443080* r5)
{
	uint32_t r4 = r5->Data_4;

#if 0
	console_send_string("sub_234457a0 (todo.c): TODO\r\n");
#endif

	if (((r4 > 112000) && (r4 <= 331000)) ||
			((r4 <= 112000/*0x1b580*/) && (r5->bData_0x1d < 2)))
	{
		//loc_234457be
		sub_23448570(r5, 0x25, 0x02);
		sub_23448570(r5, 0x27, 0x95);

		if (r4 < 167000) //0x28c58
		{
			//0x234457d8
			//r2, #0xdd
			//->loc_234457fa
			sub_23448570(r5, 0x26, 0xdd);
		}
		//loc_234457e4
		else if (r4 < 231000) //0x38658
		{
			//0x234457ea
			// r2, #0x64
			//->loc_234457fa
			sub_23448570(r5, 0x26, 0x64);
		}
		//loc_234457ee
		else if (r4 < 335000) //0x51c98
		{
			//0x234457f4
			//r2, #0x94
			//->loc_234457fa
			sub_23448570(r5, 0x26, 0x94);
		}
		else
		{
			//loc_234457f8
			//r2, #0x2
			sub_23448570(r5, 0x26, 0x02);
		}
	}
	else
	{
		//loc_2344582c
		sub_23448570(r5, 0x25, 0x82);
		sub_23448570(r5, 0x27, 0x85);
	}
}


/* 2344583c - todo */
void sub_2344583c(Struct_23443080* a, uint32_t r0, uint32_t r1, int sp_0x18, int arg_0, int arg_4, void* arg_8)
{
	struct
	{
		int Data_0; //0
		int Data_4; //4
		int Data_8; //8
		int Data_12; //12
		int Data_16; //16
		//20
	}* r4 = arg_8;
	uint32_t r7;
	uint32_t r5;
	uint32_t r6_;
	uint32_t r6 = 7;
	uint32_t r1_;

#if 0
	console_send_string("sub_2344583c (todo.c): TODO\r\n");
#endif

	if ((r1 == 8000) || (r1 == 24000))
	{
		//loc_23445892
		r6 = 6;
	}
	else if ((r1 == 16000) || (r1 == 48000) || (r1 == 28800))
	{
		//loc_23445894
		r6 = 7;
	}
	else if ((r1 == 32000) || (r1 == 59600))
	{
		//loc_2344587a
		r6 = 8;
	}
	else if (r1 == 54000)
	{
		//0x23445884
		r6 = 4;
	}
	else if (r1 == 27000)
	{
		//0x2344588e
		r6 = 3;
	}
	else
	{
		//loc_23445892
		r6 = 6;
	}

	r7 = (r0 << 10) / (r1 >> r6);
	r5 = 1 << (r6 + 10);
	r6_ = 1 << (10 - r6);

	if ((arg_0 == 0) && (arg_4 == 0))
	{
		//0x234458ba
		r4->Data_0 = (r7 + (r5 >> 1)) / r5;
		r4->Data_4 = 0;
		r4->Data_8 = 0;
	}
	//loc_234458cc
	else if ((arg_0 == 0) && (arg_4 == 1))
	{
		//0x234458d6
		uint32_t r0 = r7 / r5;
		r4->Data_0 = r0;
		r4->Data_4 = 0;
		r4->Data_8 = r6_ * (r7 - (r5 * r0));
	}
	//loc_234458ee
	else if ((arg_0 == 1) && (arg_4 == 0))
	{
		//0x234458f6
		r4->Data_0 = ((r5 / 4) + r7) / r5;

		if ((r7 - (r4->Data_0 * r5)) < (r5 / 4))
		{
			r4->Data_4 = 0;
		}
		else
		{
			r4->Data_4 = 1;
		}
		r4->Data_8 = 0;
	}
	else
	{
		//loc_2344591c
		r4->Data_0 = r7 / r5;

		if ((r7 - (r4->Data_0 * r5)) < (r5 / 2))
		{
			r4->Data_4 = 0;
		}
		else
		{
			r4->Data_4 = 1;
		}
		//0x23445938
		r4->Data_8 = (r6_ * 2) * ((r7 - (r4->Data_0 * r5)) - ((r4->Data_4 * r5)/2));
		//0x23445944
	}

	if (arg_0 == 0)
	{
		r7 = ((r4->Data_8 / r6_) + ((r4->Data_4 * r5)/2)) + (r4->Data_0 * r5);
	}
	else
	{
		r7 = ((r4->Data_8 / (r6_ * 2)) + ((r4->Data_4 * r5)/2)) + (r4->Data_0 * r5);
	}

	r1_ = ((r4->Data_8 / (r6_ * (r4->Data_4 + 1))) + ((r4->Data_4 * r5)/2)) + (r4->Data_0 * r5);

	r4->Data_12 = (((r1_ * (r1 >> r6)) / sp_0x18) + 0x200) >> 10;

	r4->Data_16 = ((r1 >> r6) * r7) >> 10;

	return;
}


/* 234459a2 - todo */
void sub_234459a2(Struct_23443080* sp_0x120)
{
	uint8_t r0, r5_;
	uint8_t sp_0x118 = 0;
	int sp_0x114 = 108000; //0x1a5e0
	uint32_t sp_0x110;
	uint32_t sp_0x10c;
	uint32_t r7 = 48000; //0xbb80
	struct
	{
		int Data_0; //0
		int Data_4; //4
		int Data_8; //8
		int Data_12; //12
		int Data_16; //16
		//20 = 0x14
	}
	sp_0xfc =
	{
			0,
	};
	int sp_0xf8;
	int sp_0xf4;
	int sp_0xf0;
	uint32_t r6 = 0;
	uint32_t sp_0x78[30] = //2348e764 + 0x78 = 2348E7DC
	{
			0x00010b94, 0x00025d78, 0x00031510, 0x000322bc,
			0x00033e14, 0x000372d0, 0x00045178, 0x0005e7b8,
			0x00064578, 0x000664b8, 0x000683f8, 0x00073b90,
			0x00081650, 0x00085ca0, 0x00089350, 0x0008a2f0,
			0x00096e10, 0x000975e0, 0x000ae510, 0x000b6210,
			0x000bcf70, 0x000c5440, 0x000c7b50, 0x000c8af0,
			0x000c9a90, 0x000cc970, 0x000cf850, 0x000d07f0,
			0x000dcb40, 0x000e7720
	};
	uint32_t sp_0x5c[7] = //2348E7DC + 0x1c = 2348E7F8
	{
			0x00030764, 0x00035778, 0x000374c4, 0x000a0a50,
			0x000c1d90, 0x000d5de0, 0x000dd310
	};
	uint32_t sp_0x40[7] = //2348E7F8 + 0x1c = 2348E814
	{
			0x000664b8, 0x00073b90, 0x00079950, 0x0007b890,
			0x0009eb10, 0x000b2390, 0x000bfe50
	};
	uint32_t sp_0x34[3] = //2348E814 + 0x0c = 2348E820
	{
			0x0009ac90, 0x000a48d0, 0x000bdf10
	};
	uint32_t sp_0x20[] = //2348E820 + 0x14 = 2348E834
	{
			0x00083590, 0x00094ed0, 0x00098d50, 0x000b8150,
			0x000cb9d0
	};
	uint32_t sp_0x10[] = //2348E834 + 0x10 = 2348E844
	{
			0x0000cd14, 0x0008d1d0, 0x000cd910, 0x000d1790
	};
	uint32_t r4 = sp_0x120->Data_4;
	//sp_0x11C = &sp_0x120->Data_0x20;
	uint32_t r5;

#if 0
	console_send_string("sub_234459a2 (todo.c): TODO\r\n");
#endif

	sp_0x120->bData_0x39 = 1;
	sp_0x120->bData_0x38 = 1;

	sub_23448570(sp_0x120, 0x38, 0x80);
	sub_23448570(sp_0x120, 0x39, 0x40);

	if (sp_0x120->tuner_crystal == 27000) //0x6978
	{
		r7 = 54000;
	}
	//loc_23445a28
	sub_23448570(sp_0x120, 0x56, 0x78);
	sub_23448570(sp_0x120, 0x4b, 0x39);
	sub_23448570(sp_0x120, 0x47, 0x0f);
	sub_23448570(sp_0x120, 0x42, 0x47);
	sub_23448570(sp_0x120, 0x41, 0xd0);
	sub_23448570(sp_0x120, 0x54, 0x08);

//	int r2 = r4 - 112000;
//  int r1 = 83500; //0x1462c;
//	int r5 = 167000; //83500 * 2

#if 0
	if (((r4 - 112001) <= 218999) ||
			((r4 <= 112001) && (sp_0x120->bData_0x1d < 2)))
//	if (((r4 > 112000) && (r4 <= 331000)) ||    //TODO!!!!!
//			((r4 <= 112000) && (sp_0x120->bData_0x1d < 2)))
#else
	if (((r4 > 112000) && (r4 <= 331000)) ||
			((r4 <= 112000) && (sp_0x120->bData_0x1d < 2)))
#endif
	{
		//loc_23445a80
		if (r4 < 56000) //0xdac0
		{
			//0x23445a86
			//r5, #0x48
			//r0, #0x1f
			/*sp_0x120->Data_0x40*/r5 = 0x48;
			sp_0x118 = 0x1f;
			//->loc_23445b28
		}
		//loc_23445a8c
		else if (r4 < 83500) //0x1462c
		{
			//0x23445a90
			//r5, #0x30
			//r0, #0x1b
			/*sp_0x120->Data_0x40*/r5  = 0x30;
			sp_0x118 = 0x1b;
			//->loc_23445b28
		}
		//loc_23445a96
		else if (r4 < 112000)
		{
			//0x23445a9a
			//r5, #0x24
			//r0, #0x17
			/*sp_0x120->Data_0x40*/r5  = 0x24;
			sp_0x118 = 0x17;
			//->loc_23445b28
		}
		//loc_23445aa0
		else if (r4 < 167000) //r5)
		{
			//0x23445aa4
			//r5, #0x18
			//r0, #0x13
			/*sp_0x120->Data_0x40*/r5  = 0x18;
			sp_0x118 = 0x13;
			//->loc_23445b28
		}
		//loc_23445aaa
		else if (r4 < 231000) //0x38658
		{
			//0x23445ab0
			//r5, #0x10
			//r0, #0x12
			/*sp_0x120->Data_0x40*/r5  = 0x10;
			sp_0x118 = 0x12;
			//->loc_23445b28
		}
		//loc_23445ab6
		else if (r4 < 335000) //0x51c98
		{
			//0x23445abc
			//r5, #0x0c
			//r0, #0x11
			/*sp_0x120->Data_0x40*/r5  = 0x0c;
			sp_0x118 = 0x11;
			//->loc_23445b28
		}
		else
		{
			//loc_23445ac2
			//r5, #0x08
			//r0, #0x10
			/*sp_0x120->Data_0x40*/r5  = 0x08;
			sp_0x118 = 0x10;
			//->loc_23445b28
		}
	}
	//loc_23445ac8
	else if (r4 < 62500) //0xf424
	{
		//0x23445ace
		//r5, #0x40
		//r0, #0x0b
		/*sp_0x120->Data_0x40*/r5  = 0x40;
		sp_0x118 = 0x0b;
		//->loc_23445b28
	}
	//loc_23445ad4
	else if (r4 < 83500) //r1)
	{
		//0x23445ad8
		//r5, #0x30
		//r0, #0x0e
		/*sp_0x120->Data_0x40*/r5  = 0x30;
		sp_0x118 = 0x0e;
		//->loc_23445b28
	}
	//loc_23445ade
	else if (r4 < 125000) //0x1e848
	{
		//0x23445ae4
		//r5, #0x20
		//r0, #0x0a
		/*sp_0x120->Data_0x40*/r5  = 0x20;
		sp_0x118 = 0x0a;
		//->loc_23445b28
	}
	//loc_23445aea
	else if (r4 < 167000) //r5)
	{
		//0x23445aee
		//r5, #0x18
		//r0, #0x0d
		/*sp_0x120->Data_0x40*/r5  = 0x18;
		sp_0x118 = 0x0d;
		//->loc_23445b28
	}
	//loc_23445af4
	else if (r4 < 250000) //0x3d090
	{
		//0x23445afa
		//r5, #0x10
		//r0, #0x09
		/*sp_0x120->Data_0x40*/r5  = 0x10;
		sp_0x118 = 0x09;
		//->loc_23445b28
	}
	//loc_23445b00
	else if (r4 < 335000) //0x51c98
	{
		//0x23445b06
		//r5, #0x0c
		//r0, #0x0c
		/*sp_0x120->Data_0x40*/r5  = 0x0c;
		sp_0x118 = 0x0c;
		//->loc_23445b28
	}
	//loc_23445b0c
	else if (r4 < 500000) //0x7a120
	{
		//0x23445b12
		//r5, #0x08
		//r0, #0x08
		/*sp_0x120->Data_0x40*/r5  = 0x08;
		sp_0x118 = 0x08;
		//->loc_23445b28
	}
	//loc_23445b18
	else if (r4 < 670000) //0xa3930
	{
		//0x23445b1e
		//r5, #0x06
		//r0, #0x04
		/*sp_0x120->Data_0x40*/r5  = 0x06;
		sp_0x118 = 0x04;
		//->loc_23445b28
	}
	else
	{
		//loc_23445b24
		//r5, #0x04
		//r0, #0x00
		/*sp_0x120->Data_0x40*/r5  = 0x04;
		sp_0x118 = 0x00;
		//->loc_23445b28
	}
	//loc_23445b28
	//sp_0x118 = r0;
	sp_0x120->Data_0x40 = r5;

	sub_23445448(sp_0x120, 0x11, sp_0x118, 4, 0);

	sp_0x110 = sp_0x120->Data_4 * r5;

	r5 = ((sp_0x120->tuner_crystal * 4) / r7 + 1) >> 1;

	if ((r5 << 31) == 0)
	{
		//0x23445b5c
		r0 = r5 & 0x0f;
		sub_23445448(sp_0x120, 0x4b, r0, 7, 4);
	}
	else
	{
		//loc_23445b70
		r0 = r5 & 0x07;
		sub_23445448(sp_0x120, 0x4b, r0, 7, 5);
		sub_23445448(sp_0x120, 0x4b, 1, 4, 4);
	}
	//0x23445b96
	sp_0x120->Data_0x3c = (sp_0x120->tuner_crystal * 2) / r5;

	r0 = sp_0x120->bData_0x38;
	r5_ = sp_0x120->bData_0x39; //r5
	sub_23445448(sp_0x120, 0x40, r0, 1, 1);
	sub_23445448(sp_0x120, 0x41, r5_, 7, 7);
	//0x23445bce
	sub_2344583c(sp_0x120, sp_0x110, sp_0x120->Data_0x3c, sp_0x114,
			sp_0x120->bData_0x38, sp_0x120->bData_0x39, &sp_0xfc);
	//0x23445be6
	sp_0xf8 = sp_0xfc.Data_0;
	sp_0xf4 = sp_0xfc.Data_4; //sp_0x100
	r7 = sp_0xfc.Data_8; //sp_0x104
	r5 = sp_0xfc.Data_12; //sp_0x108

	if (r7 == 0)
	{
		//0x23445bf6
		sub_23445448(sp_0x120, 0x41, 0x00, 7, 7);
		//->loc_23445c12
	}
	else
	{
		//loc_23445c08
		sub_23448570(sp_0x120, 0x46, 0xe8);
	}
	//loc_23445c12
	if (sp_0x120->tuner_crystal == 24000) //0x5dc0
	{
		//0x23445c1c
		if (((r4 - 51000) <= 2000)
				|| (r4 == 78000) //0x130b0
				|| (r4 == 79000) //0x13498
				|| ((r4 - 104000) <= 5000)
				|| ((r4 - 737001) < 999))
		{
			//loc_23445c48
			r5 -= 2;
		}
		//loc_23445c4a
		if ((r4 == 55000) //0xd6d8)
				|| (r4 == 56000)) //0xdac0))
		{
			//loc_23445cc0
			r5 -= 6;
		}
		//loc_23445cc2
		if ((r4 == 0xdea8)
				|| (r4 == 0x14438)
				|| (r4 == 0x14820)
				|| (r4 == 0x14c08)
				|| (r4 == 0x1adb0)
				|| (r4 == 0x1b198))
		{
			//loc_23445ce6
			r5 -= 3;
		}
		//loc_23445ce8
		for ( ; r6 < 30; r6++)
		{
			//->loc_23445cea
			if (r4 == sp_0x78[r6])
			{
				r5 -= 1;
			}
			//loc_23445cf4
		}
		//0x23445cfa
		{
			int r0;
			for (r0 = 0; r0 < 7; r0++)
			{
				//loc_23445cfe
				if (r4 == sp_0x5c[r0])
				{
					r5 -= 2;
				}
				//loc_23445d08
			}
			//->loc_23445d76
		}
	}
	//loc_23445d12
	else if (sp_0x120->tuner_crystal == 27000) //0x6978
	{
		for ( ; r6 < 7; r6++)
		{
			//->loc_23445d1a
			if (r4 == sp_0x40[r6])
			{
				r5 -= 1;
			}
			//loc_23445d24
		}
		//0x23445d2a
		{
			int r0;
			for (r0 = 0; r0 < 3; r0++)
			{
				//loc_23445d2e
				if (r4 == sp_0x34[r0])
				{
					r5 -= 2;
				}
				//loc_23445d38
			}
			//0x23445d3e
			for (r0 = 0; r0 < 5; r0++)
			{
				//loc_23445d42
				if (r4 == sp_0x20[r0])
				{
					r5 -= 3;
				}
				//loc_23445d4c
			}
			//0x23445d52
			for (r0 = 0; r0 < 4; r0++)
			{
				//loc_23445d56
				if (r4 == sp_0x10[r0])
				{
					r5 -= 4;
				}
				//loc_23445d60
			}
			//0x23445d66
			if (sp_0x120->bData_0x0c == 4)
			{
				if (r4 == 198500) //0x30764
				{
					r5 -= 1;
				}
			}
			//loc_23445d76
		}
	}
	//loc_23445d76
	sp_0x118 = sp_0xf8;
	sub_23448570(sp_0x120, 0x4f, sp_0xf8);

	sp_0x118 = r7 >> 8;
	sub_23448570(sp_0x120, 0x51, sp_0x118);

	sp_0x118 = r7 & 0xff;
	sub_23448570(sp_0x120, 0x52, sp_0x118);
	//0x23445da0
	r4 = ((sp_0xf8 >> 8) & 0x03) << 4;
	sp_0x118 = (sp_0xf4 & 0x01) << 6;
	r4 |= sp_0x118;
	sp_0x118 = (r7 >> 16) &0x0f;
	r4 |= sp_0x118;

	sub_23445408(sp_0x120, 0x4e, &sp_0x118);
	//0x23445dca
	sp_0x118 &= 0x80;
	sp_0x118 |= r4;
	sub_23448570(sp_0x120, 0x4e, sp_0x118);

	sp_0x118 = r5;
	sub_23448570(sp_0x120, 0x50, sp_0x118);
	//0x23445df0
	r6 = sp_0xfc.Data_16;
	sp_0xf0 = (r6 * 1000) / r5;

	sub_23448570(sp_0x120, 0x49, 0x76);
	sub_23448570(sp_0x120, 0x4a, 0x04);
	sub_23445448(sp_0x120, 0x48, 0x03, 2, 0);
	//0x23445e24
	{
		uint8_t r0 = (3680000 / r6) * 11; //0x382700

		r4 = sp_0x120->Data_0x3c;
		if (r4 == 8000)
		{
			//0x23445e3e
			r0 = 67830000 / r6;
		}
		//loc_23445e48
//		r5 = 24000; //0x5dc0
		if (r4 == 24000) //r5)
		{
			//0x23445e4e
			r0 = (((58880000 / r6) + 1) << 23) >> 24;
		}
		//loc_23445e5c
		if (r4 == 28800)
		{
			//0x23445e64
			r0 = 36800000 / r6;
		}
		//loc_23445e6e
		if (r4 == 57600)
		{
			//0x23445e76
			r0 = (((36800000 / r6) + 1) << 23) >> 24;
		}
		//loc_23445e84
		if (r4 == 54000) //0xd2f0
		{
			//0x23445e8a
			r0 = (((36800000 / r6) + 1) << 23) >> 24;
		}
		//loc_23445e98
		if (r4 == 48000) //0xbb80
		{
			//0x23445e9e
			r0 = (((36800000 / r6) + 1) << 23) >> 24;
		}
		//loc_23445eac
		if (r0 >= 31)
		{
			r0 = 31;
		}
		//loc_23445eb2
		if (r7 != 0)
		{
			//0x23445eb6
			if (r4 == 8000)
			{
				r0 = 59850000 / r6;
			}
			//loc_23445ec8
			if (r4 == 24000) //r5)
			{
				r0 = (((29440000 / r6) + 1) << 23) >> 24;
			}
			//loc_23445eda
			if (r4 == 28800)
			{
				//0x23445ee2
				r0 = (((44160000 / r6) + 1) << 23) >> 24;
			}
			//loc_23445ef0
			//r5 = 0x150ea00
			if (r4 == 57600)
			{
				//0x23445efa
				r0 = (((22080000 / r6) + 1) << 23) >> 24;
			}
			//loc_23445f08
			if (r4 == 54000) //0xd2f0
			{
				//0x23445f0e
				r0 = (((22080000 / r6) + 1) << 23) >> 24;
			}
			//loc_23445f1c
			if (r4 == 48000) //0xbb80
			{
				//0x23445f22
				r0 = (((22080000 / r6) + 1) << 23) >> 24;
			}
			//loc_23445f30
		}
		//loc_23445f30
		sp_0x118 = r0 & 0x1f;
		sub_23445448(sp_0x120, 0x48, sp_0x118, 7, 3);

		sp_0x120->Data_0x34 = sp_0xf0;

		sub_23445448(sp_0x120, 0x4b, 0x03, 3, 2);
		sub_23445448(sp_0x120, 0x4b, 0x02, 3, 2);
		sub_23445448(sp_0x120, 0x4b, 0x03, 3, 2);
		sub_23445448(sp_0x120, 0x4b, 0x00, 3, 2);

		rtos_task_wait(1);

		sub_23448570(sp_0x120, 0x56, 0xf8);
	}
	return;
}


/* 23445f9e - complete */
void sub_23445f9e(Struct_23443080* r0)
{
#if 0
	console_send_string("sub_23445f9e (todo.c): TODO\r\n");
#endif

	if (r0->bData_0x0d == 6)
	{
		sub_23448570(r0, 0x2d, 0x57);
	}
	else if (r0->bData_0x0d == 7)
	{
		sub_23448570(r0, 0x2d, 0x56);
	}
	else if (r0->bData_0x0d == 10)
	{
		sub_23448570(r0, 0x2d, 0x54);
	}
	else
	{
		sub_23448570(r0, 0x2d, 0x55);
	}
}


/* 23445fc4 - todo */
void sub_23445fc4(Struct_23443080* r5, int r4)
{
	uint32_t sp_0x38;
	uint8_t sp_0x34;
	uint32_t sp_0x30;
	uint32_t sp_0x2c;
	uint32_t r7;
	uint32_t sp_0x28;
	uint32_t r6_;
	uint32_t sp_0x24;
	uint32_t sp_0x20;
	struct
	{
		int Data_0; //0
		int Data_4; //4
		int Data_8; //8
		int Data_12; //12
		int Data_16; //16
		//20
	} sp_0xc;
	void* sp8;
	int sp;
	int r3;
	int r4_;
	uint8_t r6;

#if 0
	console_send_string("sub_23445fc4 (todo.c): TODO\r\n");
#endif

	sp_0x38 = r5->Data_0x3c;
	sp_0x34 = r5->bData_0x38;
	r6 = r5->bData_0x39;

	memset(&sp_0xc, 0, 20);

	if (r4 == 6)
	{
		r3 = 36810; //0x8fca
		r4_ = 23310; //0x5b0e
		//->loc_2344601c
	}
	//loc_23445fec
	else if (r4 == 7)
	{
		r4_ = 27200;
		r3 = 42950; //0xa7c6
		//->loc_2344601c
	}
	//loc_23445ff8
	else if (r4 == 10)
	{
		r3 = 61350; //0xefa6
		r4_ = 38850; //0x97c2
		//->loc_2344601c
	}
	else
	{
		//loc_23446002
		if ((r5->bData_0x0c == 1) || (r5->bData_0x0c == 3) || (r5->bData_0x0c == 4))
		{
			//loc_23446010
			r3 = 49080; //0xbfb8
			r4_ = 31080; //0x7968
			//->loc_2344601c
		}
		else
		{
			//loc_23446016
			r3 = 34080; //0x8520
			r4_ = 30080;
		}
	}
	//loc_2344601c
	sub_2344583c(r5, 0x3ae620, sp_0x38, r3, sp_0x34, r6, &sp_0xc);

	sp_0x30 = sp_0xc.Data_0;
	sp_0x2c = sp_0xc.Data_4;
	r7 = sp_0xc.Data_8;
	sp_0x28 = sp_0xc.Data_12;

	sub_2344583c(r5, 0x2f6ca0, sp_0x38, r4_, sp_0x34, r6, &sp_0xc);

	r6_ = sp_0xc.Data_0;
	sp_0x24 = sp_0xc.Data_4;
	r4 = sp_0xc.Data_8;
	sp_0x20 = sp_0xc.Data_12;;

	sub_23445448(r5, 0x4c, 0x01, 7, 7);

	sub_23448570(r5, 0x4d, ((r7 >> 16) & 0x0f) | ((sp_0x30 >> 4) & 0x30) | ((sp_0x2c & 0x01) << 6));
	sub_23448570(r5, 0x4d, sp_0x30);
	sub_23448570(r5, 0x4d, sp_0x28);
	sub_23448570(r5, 0x4d, r7 >> 8);
	sub_23448570(r5, 0x4d, r7);

	sub_23448570(r5, 0x4d, ((r4 >> 16) & 0x0f) | ((r6_ >> 4) & 0x30) | ((sp_0x24 & 0x01) << 6));
	sub_23448570(r5, 0x4d, r6_);
	sub_23448570(r5, 0x4d, sp_0x20);
	sub_23448570(r5, 0x4d, r4 >> 8);
	sub_23448570(r5, 0x4d, r4);
}


/* 23446182 - todo */
void sub_23446182(Struct_23443080* r4)
{
	uint8_t r2;
	int32_t r5;
	int32_t r7;
	int32_t r6;

#if 0
	console_send_string("sub_23446182 (todo.c): TODO\r\n");
#endif

	//r1, =0x1004

	if (r4->bData_0x0c == 2)
	{
		r5 = 4100;
		//->loc_234461a2
//		r2 = 0x55;
		//->loc_234461b0
		sub_23448570(r4, 0x1e, 0x55);
	}
	else
	{
		//loc_23446192
		r5 = r4->tuner_dac;

		if (r4->bData_0x0c == 4)
		{
//			r2 = 0x85;
			//->loc_234461b0
			sub_23448570(r4, 0x1e, 0x85);
		}
		else
		{
			//loc_2344619c
			if (r5 == 4500) //0x1194
			{
				//loc_234461a2
//				r2 = 0x55;
				//->loc_234461b0
				sub_23448570(r4, 0x1e, 0x55);
			}
			//loc_234461a6
			else if (r5 == 7200)
			{
				//loc_234461ae
//				r2 = 0x95;
				//loc_234461b0
				sub_23448570(r4, 0x1e, 0x95);
			}
			//loc_234461fe
			else if (r5 == 4100) //r1)
			{
				//->loc_234461a2
//				r2 = 0x55;
				//->loc_234461b0
				sub_23448570(r4, 0x1e, 0x55);
			}
			else
			{
				//loc_234461ae
//				r2 = 0x95;
				//loc_234461b0
				sub_23448570(r4, 0x1e, 0x95);
			}
		}
	}
	//loc_234461b0
//	sub_23448570(r4, 0x1e, r2);

	r7 = r4->Data_0x34;
	r5 = r5 * 512000;
	r5 = (((uint32_t)r5 / (uint32_t)r7) << 7) + (((((uint32_t)r5 % (uint32_t)r7) << 5) / r7) << 2);

	sub_23448570(r4, 0xf7, r5 >> 8); //(r5 << 16) >> 24);
	sub_23448570(r4, 0xf8, r5);

	r6 = 1 << 12;

	if (r4->bData_0x0c == 4)
	{
		if (r4->bData_0x0d == 7)
		{
			r5 = 3400; //0xd48;
			//->loc_23446228
		}
		else
		{
			//loc_23446204
			r5 = (r4->bData_0x0d * 1000) >> 1;
			r5 -= 150; //0x96;
			//->loc_23446228
		}
	}
	//loc_23446210
	else if (r4->bData_0x0c == 1)
	{
		if (r4->bData_0x0d == 8)
		{
			r5 = 3850;
			//->loc_23446228
		}
		else
		{
			//loc_23446220
			r5 = (r4->bData_0x0d * 1000) >> 1;
		}
	}
	else
	{
		//loc_234462fc -> loc_23446220
		r5 = (r4->bData_0x0d * 1000) >> 1;
	}
	//loc_23446228
	r5 = (r5 * 108000) / (((uint32_t)r7 + 500) / 1000);

	r6 = (r6 - r5) << 15;

	r7 = r6 / r5; //TODO: sub_234858fc

	r6 = r6 - (r5 * r7);

	sub_23448570(r4, 0xe0, (r6 >> 8) & 0x0f); //(r6 << 20) >> 28);
	sub_23448570(r4, 0xe1, r6);
	sub_23448570(r4, 0xe2, (r5 >> 8)); //<< 16) >> 24);
	sub_23448570(r4, 0xe3, r5);
	sub_23448570(r4, 0xe4, (r7 >> 8)); //<< 16) >> 24);
	sub_23448570(r4, 0xe5, r7);

	r7 = (1 << 11);

	r6 = (r5 - r7) << 15;

	r6 -= (r6 / r7) << 11; //TODO: sub_234858fc

	r5 = ((r5 << 15) / r7) - (r7 << 4); //TODO: sub_234858fc

	sub_23448570(r4, 0xef, (r6 >> 8) & 0x0f); //(r6 << 20) >> 28);
	sub_23448570(r4, 0xf0, r6);
	sub_23448570(r4, 0xf1, 0x08);
	sub_23448570(r4, 0xf2, 0x00);

	sub_23448570(r4, 0xf3, (r5 >> 8)); //<< 16) >> 24);
	sub_23448570(r4, 0xf4, r5);
}


/* 234462fe - todo */
void sub_234462fe(Struct_23443080* r4)
{
#if 0
	console_send_string("sub_234462fe (todo.c): TODO\r\n");
#endif

	sub_23448570(r4, 0x0a, 0xef);
	sub_23448570(r4, 0x0b, 0x3f);
	sub_23448570(r4, 0x8a, 0x00);
	sub_23448570(r4, 0x8d, 0x3f);
	sub_23448570(r4, 0x2a, 0x00);
	sub_23448570(r4, 0x2b, 0x00);
	sub_23448570(r4, 0x9b, 0xd9);
	sub_23448570(r4, 0xac, 0x35);
	sub_23448570(r4, 0xad, 0x00);
	sub_23448570(r4, 0xa9, 0x9f);
	sub_23448570(r4, 0x31, 0x09);
	sub_23448570(r4, 0x33, 0x0f);
	sub_23448570(r4, 0x72, 0x00);
	sub_23448570(r4, 0x74, 0x00);

	if (r4->bData_0x1b == 1)
	{
		sub_23448570(r4, 0xa0, 0x08);
		sub_23448570(r4, 0x70, 0x12);
		sub_23445448(r4, 0x97, 0x01, 2, 0);

		if ((r4->bData_0x1c == 3) ||
				(r4->bData_0x0c == 3) || (r4->bData_0x0c == 4))
		{
			//loc_234463c6
			sub_23448570(r4, 0xb5, 0x14);
			sub_23448570(r4, 0xbb, 0x00);
		}
		//loc_234463da
	}
	else
	{
		//loc_234463ea
		sub_23448570(r4, 0xa0, 0x0a);
		sub_23448570(r4, 0x70, 0x13);
        //loc_234463da
	}
    //loc_234463da
	if ((r4->wData_8 == 1) || (r4->wData_8 == 2))
	{
		//loc_234463e6
		//r2, #0x24
		//->loc_234463fc
		sub_23448570(r4, 0x0c, 0x24);
	}
	else
	{
		//loc_234463fa
		sub_23448570(r4, 0x0c, 0x04);
	}
}


/* 234467f0 - todo */
void sub_234467f0(Struct_23443080* r4, uint32_t r5)
{
	uint16_t r0;

#if 0
	console_send_string("sub_234467f0 (todo.c): TODO\r\n");
#endif

	sub_23448570(r4, 0x04, 0x7f);
	sub_23448570(r4, 0x05, 0xf8);

	sub_2344549a(r4);
	sub_234457a0(r4);
	sub_234459a2(r4);
	sub_23445f9e(r4);
	sub_23445fc4(r4, r4->bData_0x0d);
	sub_23446182(r4);
	sub_234462fe(r4);

	sub_23448570(r4, 0x04, 0x00);
	sub_23448570(r4, 0x05, 0x00);

	if (r4->bData_0x18 == 1)
	{
		//r2, #0x67
		//->loc_23446854
		sub_23448570(r4, 0x13, 0x67);
	}
	else
	{
		//loc_23446852
		//r2, #0x66
		sub_23448570(r4, 0x13, 0x66);
	}

	sub_23448570(r4, 0x30, 0x10);
	sub_23448570(r4, 0x88, 0xf7);
	sub_23448570(r4, 0x89, 0x86);
	sub_23448570(r4, 0x99, 0xf6);
	sub_23448570(r4, 0x9a, 0x75);
	sub_23448570(r4, 0xbe, 0x01);
	sub_23448570(r4, 0x00, 0x01);
	sub_23448570(r4, 0x00, 0x00);

	if (r5 < 10)
	{
		r0 = 1;
		//loc_234468be
	}
	else
	{
		//loc_234468b4
		r0 = r5 / 10;
	}

	rtos_task_wait(r0);

	if (r4->bData_0x18 == 1)
	{
		//r2, #0x65
		//->loc_234468ce
		sub_23448570(r4, 0x13, 0x65);
	}
	else
	{
		//loc_234468cc
		//r2, #0x64
		sub_23448570(r4, 0x13, 0x64);
	}

	sub_23448570(r4, 0x30, 0x00);

	if ((r4->bData_0x0c == 1) || (r4->bData_0x0c == 3) || (r4->bData_0x0c == 4))
	{
		//loc_234468ee
		//r2, #0x93
		//->loc_234468f4
		sub_23448570(r4, 0x89, 0x93);
	}
	else
	{
		//loc_234468f2
		//r2, #0xb3
		sub_23448570(r4, 0x89, 0xb3);
	}

	sub_23448570(r4, 0x9a, 0x93);
}


/* 23446908 - todo */
void sub_23446908(Struct_23443080* r4)
{
#if 0
	console_send_string("sub_23446908 (todo.c): TODO\r\n");
#endif

	if (r4->bData_0x1b == 1)
	{
		sub_23448570(r4, 0xb5, 0x14);
		//r2 = 0;
		//->loc_23446940
		sub_23448570(r4, 0xbb, 0x00);
	}
	else
	{
		//loc_23446920
		sub_23448570(r4, 0xb5, 0x75);

		if ((r4->bData_0x1c == 3) ||
				(r4->bData_0x0c == 3) || (r4->bData_0x0c == 4))
		{
			//loc_2344693a
			sub_23448570(r4, 0xbb, 0xe8);
		}
		else
		{
			//loc_2344693e
			sub_23448570(r4, 0xbb, 0x28);
		}
	}
	//0x23446948
	sub_23448570(r4, 0xbc, 0x02);

	if (r4->bData_0x1c == 2)
	{
		sub_23445448(r4, 0xb6, 0x01, 3, 3);
		sub_23448570(r4, 0xb7, 0x00);
		sub_23448570(r4, 0xb7, 0x13);
		sub_23448570(r4, 0xb7, 0x00);
		sub_23448570(r4, 0xb7, 0x0d);
		sub_23448570(r4, 0xb7, 0x26);
		sub_23448570(r4, 0xb7, 0x3a);
		sub_23448570(r4, 0xb7, 0x00);
		sub_23448570(r4, 0xb7, 0x3f);
		sub_23448570(r4, 0xb7, 0x0f);
		sub_23448570(r4, 0xb7, 0x0f);
		sub_23448570(r4, 0xb7, 0x00);
		sub_23448570(r4, 0xb7, 0x13);
		sub_23448570(r4, 0xb7, 0x00);
		sub_23448570(r4, 0xb7, 0x10);
		sub_23448570(r4, 0xb7, 0x20);
		//r2 = 0x3a
		//->loc_23446adc
		sub_23448570(r4, 0xb7, 0x3a);
	}
	else
	{
		//loc_23446a02
		sub_23445448(r4, 0xb6, 0x01, 3, 3);
		sub_23448570(r4, 0xb7, 0x01);
		sub_23448570(r4, 0xb7, 0x00);
		sub_23448570(r4, 0xb7, 0x00);
		sub_23448570(r4, 0xb7, 0x0d);
		sub_23448570(r4, 0xb7, 0x26);
		sub_23448570(r4, 0xb7, 0x43);
		sub_23448570(r4, 0xb7, 0x00);
		sub_23448570(r4, 0xb7, 0x3f);
		sub_23448570(r4, 0xb7, 0x0f);
		sub_23448570(r4, 0xb7, 0x0f);
		sub_23448570(r4, 0xb7, 0x01);
		sub_23448570(r4, 0xb7, 0x00);
		sub_23448570(r4, 0xb7, 0x00);
		sub_23448570(r4, 0xb7, 0x13);
		sub_23448570(r4, 0xb7, 0x26);
		sub_23448570(r4, 0xb7, 0x43);
	}
	//0x23446ae4
	sub_23448570(r4, 0xb7, 0x00);
	sub_23448570(r4, 0xb7, 0x3f);
	sub_23448570(r4, 0xb7, 0x0f);
	sub_23448570(r4, 0xb7, 0x0f);

	if (r4->bData_0x1c == 0)
	{
		sub_23445448(r4, 0xb6, 0x01, 2, 2);
		sub_23448570(r4, 0xb8, 0x01);
		sub_23448570(r4, 0xb8, 0x00);
		sub_23448570(r4, 0xb8, 0x1d);
		sub_23448570(r4, 0xb8, 0x23);
		sub_23448570(r4, 0xb8, 0x2a);
		sub_23448570(r4, 0xb8, 0x43);
		sub_23448570(r4, 0xb8, 0x00);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x0f);
		sub_23448570(r4, 0xb8, 0x00);

		if ((r4->bData_0x0c == 1) || (r4->bData_0x0c == 3) || (r4->bData_0x0c == 4))
		{
			//loc_23446b94
			sub_23448570(r4, 0xb8, 0x0c);
		}
		else
		{
			//loc_23446b98
			sub_23448570(r4, 0xb8, 0x0d);
		}
		//r2, #0x13
		//->loc_23446c2a
		sub_23448570(r4, 0xb8, 0x13);
		//0x23446c32
		sub_23448570(r4, 0xb8, 0x17);
		sub_23448570(r4, 0xb8, 0x23);
		//r2, #0x2a
		//loc_23446c48
		sub_23448570(r4, 0xb8, 0x2a);
		sub_23448570(r4, 0xb8, 0x43);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x0f);
		sub_23448570(r4, 0xb8, 0x0f);
	}
	//loc_23446ba6
	else if (r4->bData_0x1c == 1)
	{
		sub_23445448(r4, 0xb6, 0x01, 2, 2);
		sub_23448570(r4, 0xb8, 0x00);
		sub_23448570(r4, 0xb8, 0x0b);
		sub_23448570(r4, 0xb8, 0x14);
		sub_23448570(r4, 0xb8, 0x23);
		sub_23448570(r4, 0xb8, 0x00);
		sub_23448570(r4, 0xb8, 0x43);
		sub_23448570(r4, 0xb8, 0x00);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x0f);
		sub_23448570(r4, 0xb8, 0x03);
		sub_23448570(r4, 0xb8, 0x12);
		sub_23448570(r4, 0xb8, 0x0e);
		//0x23446c32
		sub_23448570(r4, 0xb8, 0x17);
		sub_23448570(r4, 0xb8, 0x23);
		//r2, #0x2a
		//loc_23446c48
		sub_23448570(r4, 0xb8, 0x2a);
		sub_23448570(r4, 0xb8, 0x43);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x0f);
		sub_23448570(r4, 0xb8, 0x0f);
	}
	//loc_23446c84
	else if (r4->bData_0x1c == 2)
	{
		sub_23445448(r4, 0xb6, 0x01, 2, 2);
		sub_23448570(r4, 0xb8, 0x01);
		sub_23448570(r4, 0xb8, 0x00);
		sub_23448570(r4, 0xb8, 0x1d);
		sub_23448570(r4, 0xb8, 0x23);
		sub_23448570(r4, 0xb8, 0x2a);
		sub_23448570(r4, 0xb8, 0x43);
		sub_23448570(r4, 0xb8, 0x00);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x0f);
		sub_23448570(r4, 0xb8, 0x00);
		sub_23448570(r4, 0xb8, 0x0c);
		sub_23448570(r4, 0xb8, 0x13);
		sub_23448570(r4, 0xb8, 0x19);
		sub_23448570(r4, 0xb8, 0x23);
		//r2, #0x31
		//->loc_23446c48
		sub_23448570(r4, 0xb8, 0x31);
		sub_23448570(r4, 0xb8, 0x43);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x0f);
		sub_23448570(r4, 0xb8, 0x0f);
	}
	else
	{
		//loc_23446d28
		sub_23445448(r4, 0xb6, 0x01, 2, 2);
		sub_23448570(r4, 0xb8, 0x01);
		sub_23448570(r4, 0xb8, 0x00);
		sub_23448570(r4, 0xb8, 0x1d);
		sub_23448570(r4, 0xb8, 0x23);
		sub_23448570(r4, 0xb8, 0x2a);
		sub_23448570(r4, 0xb8, 0x43);
		sub_23448570(r4, 0xb8, 0x00);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x0f);
		sub_23448570(r4, 0xb8, 0x00);
		sub_23448570(r4, 0xb8, 0x0d);
		sub_23448570(r4, 0xb8, 0x13);
		sub_23448570(r4, 0xb8, 0x19);
		sub_23448570(r4, 0xb8, 0x23);
		//r2, #0x39
		//->loc_23446c48
		sub_23448570(r4, 0xb8, 0x39);
		sub_23448570(r4, 0xb8, 0x43);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x0f);
		sub_23448570(r4, 0xb8, 0x0f);
	}
}


/* 23446dc8 - todo */
void sub_23446dc8(Struct_23443080* r4)
{
#if 0
	console_send_string("sub_23446dc8 (todo.c): TODO\r\n");
#endif

	sub_23445448(r4, 0x3b, 0x33, 6, 0);
	sub_23445448(r4, 0x79, 0x0c, 7, 4);
	sub_23445448(r4, 0x7b, 0x00, 7, 6);
	sub_23445448(r4, 0x3b, 0x01, 7, 7);
	sub_23448570(r4, 0x3c, 0x4f);
	sub_23448570(r4, 0x3c, 0x47);
	sub_23448570(r4, 0x3c, 0x43);
	sub_23448570(r4, 0x3c, 0x3d);
	sub_23448570(r4, 0x3c, 0x52);
	sub_23448570(r4, 0x3c, 0x49);
	sub_23448570(r4, 0x3c, 0x43);
	sub_23448570(r4, 0x3c, 0x53);
	sub_23448570(r4, 0x3c, 0x4f);
	sub_23448570(r4, 0x3c, 0x49);
	sub_23448570(r4, 0x3c, 0x45);
	sub_23448570(r4, 0x3c, 0x41);
	sub_23448570(r4, 0x3c, 0x3d);
	sub_23448570(r4, 0x3c, 0x3b);
	sub_23448570(r4, 0x3c, 0x38);
	sub_23448570(r4, 0x3c, 0x52);
	sub_23448570(r4, 0x3c, 0x3c);
	sub_23448570(r4, 0x3c, 0x4b);
	sub_23448570(r4, 0x3c, 0x46);
	sub_23448570(r4, 0x3c, 0x41);
	sub_23448570(r4, 0x3c, 0x3b);
	sub_23448570(r4, 0x3c, 0x51);
	sub_23448570(r4, 0x3c, 0x49);
	sub_23448570(r4, 0x3c, 0x41);
	sub_23448570(r4, 0x3c, 0x39);
	sub_23448570(r4, 0x3c, 0x42);
	sub_23448570(r4, 0x3c, 0x50);
	sub_23448570(r4, 0x3c, 0x44);
	sub_23448570(r4, 0x3c, 0x3c);
	sub_23448570(r4, 0x3c, 0x4e);
	sub_23448570(r4, 0x3c, 0x23);
	sub_23448570(r4, 0x3c, 0x20);
	sub_23448570(r4, 0x3c, 0x1e);
	sub_23448570(r4, 0x3c, 0x1b);
	sub_23448570(r4, 0x3c, 0x25);
	sub_23448570(r4, 0x3c, 0x21);
	sub_23448570(r4, 0x3c, 0x1e);
	sub_23448570(r4, 0x3c, 0x25);
	sub_23448570(r4, 0x3c, 0x23);
	sub_23448570(r4, 0x3c, 0x21);
	sub_23448570(r4, 0x3c, 0x1f);
	sub_23448570(r4, 0x3c, 0x1d);
	sub_23448570(r4, 0x3c, 0x1b);
	sub_23448570(r4, 0x3c, 0x1a);
	sub_23448570(r4, 0x3c, 0x19);
	sub_23448570(r4, 0x3c, 0x25);
	sub_23448570(r4, 0x3c, 0x1b);
	sub_23448570(r4, 0x3c, 0x22);
	sub_23448570(r4, 0x3c, 0x1f);
	sub_23448570(r4, 0x3c, 0x1d);
	sub_23448570(r4, 0x3c, 0x1b);
	sub_23448570(r4, 0x3c, 0x24);
	sub_23448570(r4, 0x3c, 0x21);
	sub_23448570(r4, 0x3c, 0x1d);
	sub_23448570(r4, 0x3c, 0x1a);
	sub_23448570(r4, 0x3c, 0x1d);
	sub_23448570(r4, 0x3c, 0x24);
	sub_23448570(r4, 0x3c, 0x1e);
	sub_23448570(r4, 0x3c, 0x1b);
	sub_23448570(r4, 0x3c, 0x23);
	sub_23448570(r4, 0x3c, 0x80);
	sub_23448570(r4, 0x3c, 0x80);
	sub_23448570(r4, 0x3c, 0x80);
	sub_23448570(r4, 0x3c, 0x80);
	sub_23448570(r4, 0x3c, 0x44);
	sub_23448570(r4, 0x3c, 0x44);
	sub_23448570(r4, 0x3c, 0x44);
	sub_23448570(r4, 0x3c, 0x08);
	sub_23448570(r4, 0x3c, 0x08);
	sub_23448570(r4, 0x3c, 0xc8);
	sub_23448570(r4, 0x3c, 0xc8);
	sub_23448570(r4, 0x3c, 0xc8);
	sub_23448570(r4, 0x3c, 0xc8);
	sub_23448570(r4, 0x3c, 0x28);
	sub_23448570(r4, 0x3c, 0x88);
	sub_23448570(r4, 0x3c, 0xd1);
	sub_23448570(r4, 0x3c, 0xd1);
	sub_23448570(r4, 0x3c, 0xb2);
	sub_23448570(r4, 0x3c, 0x52);
	sub_23448570(r4, 0x3c, 0x12);
	sub_23448570(r4, 0x3c, 0xb2);
	sub_23448570(r4, 0x3c, 0x93);
	sub_23448570(r4, 0x3c, 0x93);
	sub_23448570(r4, 0x3c, 0x93);
	sub_23448570(r4, 0x3c, 0x93);
	sub_23448570(r4, 0x3c, 0x17);
	sub_23448570(r4, 0x3c, 0x1b);
	sub_23448570(r4, 0x3c, 0x9b);
	sub_23448570(r4, 0x3c, 0x9b);
	sub_23448570(r4, 0x3c, 0xdf);
	sub_23448570(r4, 0x3c, 0x00);
	sub_23448570(r4, 0x3c, 0x00);
	sub_23448570(r4, 0x3c, 0x00);
	sub_23448570(r4, 0x3c, 0x00);
	sub_23448570(r4, 0x3c, 0x00);
	sub_23448570(r4, 0x3c, 0x00);
	sub_23448570(r4, 0x3c, 0x00);
	sub_23448570(r4, 0x3c, 0x44);
	sub_23448570(r4, 0x3c, 0x95);
	sub_23448570(r4, 0x3c, 0xa5);
	sub_23448570(r4, 0x3c, 0xe5);
	sub_23448570(r4, 0x3c, 0xf5);
	sub_23448570(r4, 0x3c, 0xf9);
	sub_23448570(r4, 0x3c, 0xfa);
	sub_23448570(r4, 0x3c, 0xfa);
}


/* 23447226 - complete */
void sub_23447226(Struct_23443080* r4)
{
#if 0
	console_send_string("sub_23447226 (todo.c): TODO\r\n");
#endif

	sub_23445448(r4, 0x11, 0x00, 7, 7);

	if (r4->bData_0x18 == 1)
	{
		sub_23445448(r4, 0x13, 0x01, 0, 0);
	}
	else
	{
		//loc_23447246
		sub_23445448(r4, 0x13, 0x00, 0, 0);
	}

	if ((r4->bData_0x0c == 1) || (r4->bData_0x0c == 3) || (r4->bData_0x0c == 4))
	{
		//loc_23447262
		sub_23445448(r4, 0x10, 0x01, 7, 6);
	}
	//loc_23447272
	sub_23445448(r4, 0x2e, 0x00, 5, 5);
	sub_23445448(r4, 0x68, 0x03, 7, 6);
	sub_23448570(r4, 0x03, 0x00);
	sub_23445448(r4, 0x0f, 0x01, 4, 4);
	sub_23445448(r4, 0x55, 0x02, 5, 4);
	sub_23445448(r4, 0x79, 0x02, 3, 0);
	sub_23445448(r4, 0x85, 0x00, 1, 0);
	sub_23445448(r4, 0x17, 0x07, 2, 0);
	sub_23445448(r4, 0x77, 0x02, 6, 0);
	sub_23445448(r4, 0x78, 0x02, 6, 0);
	sub_23445448(r4, 0x75, 0x02, 5, 4);
	sub_23445448(r4, 0x34, 0x00, 3, 2);
	sub_23445448(r4, 0xad, 0x01, 5, 5);
	sub_23448570(r4, 0xae, 0x00);
	sub_23448570(r4, 0xae, 0x80);
	sub_23448570(r4, 0xae, 0x90);
	sub_23448570(r4, 0xae, 0xa0);
	sub_23448570(r4, 0xae, 0xa1);
	sub_23448570(r4, 0xae, 0xb1);
	sub_23448570(r4, 0xae, 0xb5);
	sub_23448570(r4, 0xae, 0xb7);
	sub_23448570(r4, 0xae, 0xf7);
	sub_23448570(r4, 0xae, 0xff);
	sub_23448570(r4, 0xae, 0x7f);
	sub_23448570(r4, 0xae, 0x00);
	sub_23448570(r4, 0xae, 0x04);
	sub_23445448(r4, 0x1c, 0x03, 6, 5);
	sub_23445448(r4, 0x1d, 0x00, 2, 0);
	sub_23448570(r4, 0x90, 0x10);

	if ((r4->bData_0x0c == 3) || (r4->bData_0x0c == 4))
	{
		//loc_234473ee
		sub_23445448(r4, 0x87, 0x04, 7, 5);
		//r2 = 0xff
		//->loc_23447414
		sub_23448570(r4, 0x23, 0xff);
	}
	else
	{
		//loc_23447402
		sub_23445448(r4, 0x87, 0x01, 7, 5);
		//r2 = 0x95
		sub_23448570(r4, 0x23, 0x95);
	}

	if (r4->bData_0x0c == 3)
	{
		//r2 = 0x10
		//->loc_2344742e
		sub_23448570(r4, 0x5d, 0x10);
	}
	//loc_23447426
	else if (r4->bData_0x19 == 0)
	{
		//r2 = 0x00
		sub_23448570(r4, 0x5d, 0x00);
	}
	//loc_23447436
	if (r4->bData_0x1b == 1)
	{
		sub_23445448(r4, 0x97, 0x01, 2, 0);
		//r2 = 0x03
		//->loc_23447462
		sub_23448570(r4, 0x61, 0x03);
	}
	else
	{
		//loc_23447450
		sub_23445448(r4, 0x97, 0x04, 2, 0);
		//r2, #0x4b
		sub_23448570(r4, 0x61, 0x4b);
	}

	sub_23448570(r4, 0x9c, 0xff);
	sub_23448570(r4, 0x9d, 0x0c);
	sub_23445448(r4, 0x1a, 0x07, 7, 5);
	sub_23448570(r4, 0x21, 0x91);
	sub_23448570(r4, 0xa1, 0x2a);
	sub_23448570(r4, 0xa2, 0xb2);

	if (r4->bData_0x0c == 0)
	{
		sub_23448570(r4, 0xa3, 0x4e);
		//r2, #0x6e
		//->loc_234474cc
		sub_23448570(r4, 0xa4, 0x6e);
	}
	else
	{
		//loc_234474c0
		sub_23448570(r4, 0xa3, 0x5e);
		// r2, #0x84
		sub_23448570(r4, 0xa4, 0x84);
	}

	sub_23448570(r4, 0xa5, 0x2a);
	sub_23448570(r4, 0xa6, 0xb2);
	sub_23448570(r4, 0xa8, 0x93);

	sub_23446908(r4);

	if ((r4->wData_8 == 1) || (r4->wData_8 == 2))
	{
		//loc_23447504
		if (r4->bData_0x1a >= 2)
		{
			sub_23446dc8(r4);

			sub_23448570(r4, 0x3a, 0x1d);
			sub_23448570(r4, 0x35, 0x18);
			sub_23448570(r4, 0x36, 0xe0);
			sub_23448570(r4, 0xb4, 0x00);
			sub_23448570(r4, 0x59, 0x34);

			sub_234467f0(r4, 2000);

			sub_23445448(r4, 0x60, 0x00, 0, 0);
		}
		//loc_2344755a
	}
	//loc_2344755a
	sub_23448570(r4, 0x3a, 0x5d);
}


/* 23447566 - todo */
void sub_23447566(Struct_23443080* r5)
{
	uint8_t sp_0x18 = 0;
	uint8_t sp_0x14 = 0;
	uint8_t sp_0x10 = 0;
	uint8_t sp_0xc;
	uint8_t sp8 = 0;
	uint8_t sp4 = 0;
	uint8_t r7;
	uint8_t r6;
	uint8_t r4;

#if 0
	console_send_string("sub_23447566 (todo.c): TODO\r\n");
#endif

	sub_23445408(r5, 0x8a, &sp_0x14);
	sp_0x14 |= 0x10;
	sub_23448570(r5, 0x8a, sp_0x14);

	sub_23445408(r5, 0x7e, &sp_0x10);
	sp_0x10 |= 0x88;
	sub_23448570(r5, 0x7e, sp_0x10);

	sub_23448570(r5, 0x22, 0x41);
	sub_23448570(r5, 0x35, 0x18);
	sub_23448570(r5, 0x36, 0x07);
	sub_23448570(r5, 0xb4, 0x00);
	sub_23448570(r5, 0x59, 0x34);
	sub_23448570(r5, 0x00, 0x01);
	sub_23448570(r5, 0x00, 0x00);

	rtos_task_wait(1);

	sub_23445408(r5, 0x31, &sp_0x18);

	sp_0xc = sp_0x18 & 0x3f;

	sub_23445408(r5, 0x33, &sp_0x18);

	r7 = sp_0x18 & 0x1f;

	sub_23445408(r5, 0x3f, &sp_0x18);

	r6 = sp_0x18 >> 4;

	if (r5->bData_0x1c == 3)
	{
		//->loc_2344765a
		r4 = 2;
		//->loc_23447660
	}
	else if (r5->bData_0x1c == 2)
	{
		//0x23447640
		if (r6 >= 12)
		{
			//0x23447644
			r4 = 4;
			//->loc_23447660
		}
		//loc_23447648
		else if (r6 >= 10)
		{
			//->loc_23447652
			r4 = 3;
			//->loc_23447660
		}
		else
		{
			//loc_2344765a
			r4 = 2;
			//->loc_23447660
		}
	}
	else
	{
		//loc_2344764e
		if (r6 >= 12)
		{
			//loc_23447652
			r4 = 3;
			//->loc_23447660
		}
		//loc_23447656
		else if (r6 >= 10)
		{
			//loc_2344765a
			r4 = 2;
			//->loc_23447660
		}
		else
		{
			//loc_2344765e
			r4 = 1;
		}
	}
	//loc_23447660
	if (r5->bData_0x0c == 3)
	{
		//0x23447666
		if (r5->Data_4 == 198500) //0x30764
		{
			if (r5->wData_0x24 == 1)
			{
				r4 = 0;
			}
			//loc_23447676
		}
		//loc_23447676
	}
	//loc_23447676
	sub_23448570(r5, 0xb6, 0x01);

	sp_0x18 = r4;
	sp_0x18 = (sp_0x18 << 5) | r7;

	sub_23448570(r5, 0xba, sp_0x18);
	sub_23448570(r5, 0xba, sp_0xc);

	sp_0x18 = r4;
	sp_0x18 = (sp_0x18 << 5) | r7;

	sub_23448570(r5, 0xba, sp_0x18);
	sub_23448570(r5, 0xba, sp_0xc);

	sp_0x18 = r4;
	sp_0x18 = (sp_0x18 << 5) | r7;

	sub_23448570(r5, 0xba, sp_0x18);
	sub_23448570(r5, 0xba, sp_0xc);

	sp_0x18 = r4;
	sp_0x18 = (sp_0x18 << 5) | r7;

	sub_23448570(r5, 0xba, sp_0x18);
	sub_23448570(r5, 0xba, sp_0xc);

	sp_0x18 = r4;
	sp_0x18 = (sp_0x18 << 5) | r7;

	sub_23448570(r5, 0xba, sp_0x18);
	sub_23448570(r5, 0xba, sp_0xc);

	if ((r5->bData_0x0c == 1) || (r5->bData_0x0c == 3) || (r5->bData_0x0c == 4))
	{
		//loc_2344772e
		r4 |= 0x20;
	}
	//loc_23447732
	sub_23448570(r5, 0x22, r4);
	sub_23448570(r5, 0x5f, r6);

	sp_0x14 &= 0xef;

	sub_23448570(r5, 0x8a, sp_0x14);
	sub_23448570(r5, 0x8a, 0x00);

	sp_0x10 &= 0x77;

	sub_23448570(r5, 0x7e, sp_0x10);

	rtos_task_wait(1);

	if ((r5->bData_0x0c == 3) || (r5->bData_0x0c == 4))
	{
		//loc_23447788
		if (r5->Data_4 < 780000)
		{
			return;
		}

		if (r5->Data_4 > 790000)
		{
			return;
		}
		//0x23447796
		if (r6 >= 12)
		{
			//0x2344779a
			sp8 = 4;

			if (r5->chipId == 0xb4)
			{
				sub_23448570(r5, 0x1f, 0xf1);
			}
			else
			{
				//loc_234477a8
				sub_23448570(r5, 0x1f, 0xd1);
			}

			r4 = 4;
			//->loc_234477ec
		}
		//loc_234477b6
		else if (r6 >= 10)
		{
			//0x234477ba
			sp8 = 2;

			if (r5->chipId == 0xb4)
			{
				sub_23448570(r5, 0x1f, 0xe9);
			}
			else
			{
				//loc_234477c8
				sub_23448570(r5, 0x1f, 0xc9);
			}

			r4 = 3;
			//->loc_234477ec
		}
		else
		{
			//loc_234477d6
			if (r5->chipId == 0xb4)
			{
				sub_23448570(r5, 0x1f, 0xe1);
			}
			else
			{
				//loc_234477e0
				sub_23448570(r5, 0x1f, 0xc1);
			}

			r4 = 2;
		}
		//loc_234477ec
		r6 = 0x77;

		sub_23448570(r5, 0xb6, 0x02);
		sub_23448570(r5, 0xb9, r4);
		sub_23448570(r5, 0xb9, sp4);
		sub_23448570(r5, 0xb9, r4);
		sub_23448570(r5, 0xb9, sp4);
		sub_23448570(r5, 0xb9, sp8);
		sub_23448570(r5, 0xb9, sp4);
		sub_23448570(r5, 0xb9, sp8);
		sub_23448570(r5, 0xb9, r6);
		sub_23448570(r5, 0xb9, sp8);
		sub_23448570(r5, 0xb9, sp4);
		sub_23448570(r5, 0x7e, sp4);
	}
	//loc_23447866
	return;
}


/* 2344786a - todo */
void sub_2344786a(Struct_23443080* sp_0x10)
{
	int r0 = 0;
	uint8_t r7 = 0;
	uint32_t r0_;
	uint32_t r7_;
	uint32_t sp12;
	uint8_t sp8 = 0;
	uint8_t sp4 = 0;
	uint32_t r5;
	uint32_t r6;
	uint32_t r4 = sp_0x10->Data_4;
	uint32_t r4_;

#if 0
	console_send_string("sub_2344786a (todo.c): TODO\r\n");
#endif

	sub_23445408(sp_0x10, 0x60, &sp8);
	sp8 = sp8 & 1; //(sp8 << 31) >> 31;

	if ((sp_0x10->wData_8 == 1) || (sp_0x10->wData_8 == 2))
	{
		//loc_2344789a
		if (sp_0x10->bData_0x1a >= 2)
		{
			if (sp8 == 0)
			{
				//0x234478a4
				if (r4 >= 954000) //0xe8e90)
				{
					r5 = 1010000; //0xf6950;
					r6 = 954000; //0xe8e90
					//->loc_23447b1a
				}
				//loc_234478b0
				else if (r4 >= 858000) //0xd1790
				{
					r5 = 954000; //0xe8e90;
					r6 = 858000; //0xd1790
					r7 = 1;
					//->loc_23447b1a
				}
				//loc_234478be
				else if (r4 >= 810000) //r6 = 0xc5c10
				{
					r5 = 858000; //0xd1790
					r6 = 810000; //0xc5c10
					sp4 = 1;
					r7 = 2;
					//->loc_23447b1a
				}
				//loc_234478ce
				else if (r4 >= 738000) //r0 = 0xb42d0
				{
					r5 = 810000; //r6
					r6 = 738000; //r0
					sp4 = 2;
					r7 = 3;
					//->loc_23447b1a
				}
				//loc_234478e0
				else if (r4 >= 658000) //r6 = 0xa0a50
				{
					r5 = 738000; //r0;
					r6 = 658000;
					sp4 = 3;
					r7 = 4;
					//->loc_23447b1a
				}
				//loc_234478f0
				else if (r4 >= 586000) //r0 = 0x8f110
				{
					r5 = 658000; //r6
					r6 = 586000; //r0
					sp4 = 4;
					r7 = 5;
					//->loc_23447b1a
				}
				//loc_23447902
				else if (r4 >= 538000) //r6 = 0x83590
				{
					r5 = 586000;
					r6 = 538000;
					sp4 = 5;
					r7 = 6;
					//->loc_23447b1a
				}
				//loc_23447912
				else if (r4 >= 498000) //r0 = 0x79950
				{
					r5 = 538000; //r6
					r6 = 498000; //r0
					sp4 = 6;
					r7 = 7;
					//->loc_23447b1a
				}
				//loc_23447924
				else if (r4 >= 474000) //r6 = 0x73b90
				{
					r5 = 498000; //r0
					r6 = 474000;
					sp4 = 7;
					r7 = 8;
					//->loc_23447b1a
				}
				//loc_23447934
				else if (r4 >= 443000) //r0 = 0x6c278
				{
					r5 = 474000; //r6
					r6 = 443000; //r0
					sp4 = 8;
					r7 = 9;
					//->loc_23447b1a
				}
				//loc_23447946
				else if (r4 >= 419000) //r6 = 0x664b8
				{
					r5 = 443000; //r0
					r6 = 419000;
					sp4 = 9;
					r7 = 10;
					//->loc_23447b1a
				}
				//loc_23447956
				else if (r4 >= 395000) //r0 = 0x606f8
				{
					r5 = 419000; //r6
					r6 = 395000;
					sp4 = 10;
					r7 = 11;
					//->loc_23447b1a
				}
				//loc_23447968
				else if (r4 >= 371000) //r6 = 0x5a938
				{
					r5 = 395000; //r0
					r6 = 371000;
					sp4 = 11;
					r7 = 12;
					//->loc_23447b1a
				}
				//loc_23447978
				else if (r4 >= 355000) //r0 = 0x56ab8
				{
					r5 = 371000; //r6
					r6 = 355000; //r0
					sp4 = 12;
					r7 = 13;
					//->loc_23447b1a
				}
				//loc_2344798c
				else if (r4 >= 339000) //r6 = 0x52c38
				{
					r5 = 355000; //r0
					r6 = 339000;
					//->loc_234479a4
					sp4 = 13;
					r7 = 14;
					//->loc_23447b1a
				}
				//loc_23447998
				else if (r4 > 331000) //r0 = 0x50cf8
				{
					r5 = 339000; //r6
					r6 = 331000;
					sp4 = 14;
					r7 = 14;
					//->loc_23447b1a
				}
				//loc_234479aa
				else if (r4 >= 243000) //r6 = 0x3b538
				{
					r5 = 331000; //r0
					r6 = 243000;
					sp4 = 15;
					r7 = 16;
					//->loc_23447b1a
				}
				//loc_234479ba
				else if (r4 >= 227000) //r0 = 0x376b8
				{
					r5 = 243000; //r6
					r6 = 227000; //r0
					sp4 = 16;
					r7 = 17;
					//->loc_23447b1a
				}
				//loc_234479cc
				else if (r4 >= 211000) //r6 = 0x33838
				{
					r5 = 227000; //r0
					r6 = 211000;
					sp4 = 17;
					r7 = 18;
					//->loc_23447b1a
				}
				//loc_234479dc
				else if (r4 >= 195000) //r0 = 0x2f9b8
				{
					r5 = 211000; //r6
					r6 = 195000; //r0
					sp4 = 18;
					r7 = 19;
					//->loc_23447b1a
				}
				//loc_234479ee
				else if (r4 >= 179000) //r6 = 0x2bb38
				{
					r5 = 195000; //r0
					r6 = 179000;
					sp4 = 19;
					r7 = 20;
					//->loc_23447b1a
				}
				//loc_234479fe
				else if (r4 >= 163000) //r0 = 0x27cb8
				{
					r5 = 179000; //r6
					r6 = 163000; //r0
					sp4 = 20;
					r7 = 21;
					//->loc_23447b1a
				}
				//loc_23447a10
				else if (r4 >= 147000) //r6 = 0x23e38
				{
					r5 = 163000; //r0
					r6 = 147000;
					sp4 = 21;
					r7 = 22;
					//->loc_23447b1a
				}
				//loc_23447a20
				else if (r4 >= 131000) //r0 = 0x1ffb8
				{
					r5 = 147000; //r6
					r6 = 131000; //r0
					sp4 = 22;
					r7 = 23;
					//->loc_23447b1a
				}
				//loc_23447a32
				else if (r4 > 112000) //r5 = 0x1b580
				{
					r5 = 131000; //r0
					r6 = 115000;
					sp4 = 23;
					r7 = 24;
					//->loc_23447b1a
				}
				//loc_23447a44
				else if (r4 >= 88000) //r0 = 0x157c0
				{
					r5 = 112000; //r5
					r6 = 88000; //r0
					sp4 = 25;
					r7 = 25;
					//->loc_23447b1a
				}
				//loc_23447ad0
				else if (r4 >= 80000) //r6 = 0x13880
				{
					r5 = 88000; //r0
					r6 = 80000;
					sp4 = 25;
					r7 = 26;
					//->loc_23447b1a
				}
				//loc_23447ae0
				else if (r4 >= 68500) //r0 = 0x10b94
				{
					r5 = 80000; //r5
					r6 = 68500; //r0
					sp4 = 26;
					r7 = 27;
					//->loc_23447b1a
				}
				//loc_23447af2
				else if (r4 >= 60500) //r6 = 0xec54
				{
					r5 = 68500; //r0
					r6 = 60500;
					sp4 = 27;
					r7 = 28;
					//->loc_23447b1a
				}
				//loc_23447b02
				else if (r4 >= 52500) //r0 = 0xcd14
				{
					r5 = 60500; //r6
					r6 = 52500; //r0
					sp4 = 28;
					r7 = 29;
					//->loc_23447b1a
				}
				else
				{
					//loc_23447b10
					r5 = 52500; //r0
					r6 = 42500; //0xa604
					sp4 = 29;
					r7 = 29;
				}
			}
			else
			{
				//loc_2344798a -> loc_23447c1a
				return;
			}
		}
		else
		{
			//loc_2344798a -> loc_23447c1a
			return;
		}
	}
	else
	{
		//loc_2344798a -> loc_23447c1a
		return;
	}
	//loc_23447b1a
	sub_23448570(sp_0x10, 0x3d, sp4);

	sub_23445408(sp_0x10, 0x3d, &sp8);

	sp12 = (sp8 & 0x80) << 1;

	sub_23445408(sp_0x10, 0x3e, &sp8);

	sp12 += sp8;

	sub_23448570(sp_0x10, 0x3d, r7);

	sub_23445408(sp_0x10, 0x3d, &sp8);

	r7_ = (sp8 & 0x80) << 1;

	sub_23445408(sp_0x10, 0x3e, &sp8);

	r0_ = r7_ + sp8;

	if (r4 >= 1010000) //0xf6950
	{
		sp12 = 0;
		r0_ = 0;
		//->loc_23447b9e
	}
	//loc_23447b88
	else if (r4 >= 954000) //0xe8e90
	{
		//loc_23447b92
		sp12 = 0;
	}
	//loc_23447b96
	if (r0_ > sp12) //r1)
	{
		r0_ = r0_ - sp12; //r1
		//->loc_23447ba2
	}
	else
	{
		//loc_23447b9e
		r0_ = sp12 - r0_;
	}
	//loc_23447ba2
	r4_ = (((r0_ * (r5 - r4)) / (r5 - r6)) + sp12); // & 0xffff;

//	sp8 = ((r4_ >> 8) & 1) + 4;
	sp8 = ((r4_ & 0x0100) >> 8) + 4;

	sub_23448570(sp_0x10, 0x72, sp8);

	r4_ &= 0xff;
	sp8 = r4_;

	sub_23448570(sp_0x10, 0x73, sp8);

	r4_ |= 0x80;
	sp8 = r4_;

	sub_23448570(sp_0x10, 0x74, sp8);

	if (sp_0x10->bData_0x1b == 0)
	{
		//r2, #0x1b
		//->loc_23447bf4
		sub_23448570(sp_0x10, 0x70, 0x1b);
	}
	else
	{
		//loc_23447bf2
		//r2, #0x1a
		sub_23448570(sp_0x10, 0x70, 0x1a);
	}

	sub_23445408(sp_0x10, 0x71, &sp8);

	sp8 |= 0x10;

	sub_23448570(sp_0x10, 0x71, sp8);
	//loc_23447c1a
}


/* 23447c20 - complete */
void sub_23447c20(Struct_23443080* a)
{
#if 0
	console_send_string("sub_23447c20 (todo.c): TODO\r\n");
#endif

	sub_23448570(a, 0x06, 0x0d);
}


/* 23447c2c - complete */
void sub_23447c2c(Struct_23443080* a)
{
#if 0
	console_send_string("sub_23447c2c (todo.c): TODO\r\n");
#endif

	sub_23445448(a, 0x5d, 0x03, 6, 4);
}


/* 23447c3e - complete */
void sub_23447c3e(Struct_23443080* r4)
{
	uint8_t sp = 0;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23447c3e: r4->wData_8=%d, r4->bData_0x19=%d\r\n",
				r4->wData_8, r4->bData_0x19);
		console_send_string(debug_string);
	}
#endif

	sub_23445408(r4, 0x5d, &sp);

	sub_23448570(r4, 0x06, 0x05);

	if (r4->wData_8 == 2)
	{
		sub_23448570(r4, 0xbd, 0x00);

		if (r4->bData_0x19 == 1)
		{
			sub_23447c2c(r4);
		}
		//loc_23447c76
	}
	else
	{
		//loc_23447c78
		sub_23448570(r4, 0xbf, 0x01);

		if (r4->bData_0x19 == 1)
		{
			sub_23448570(r4, 0x5d, sp);
			//->loc_23447c70
			sub_23447c2c(r4);
		}
		//loc_23447c76
	}
	//loc_23447c76
}


/* 23447c96 - complete */
int mt_fe_tn_init_tc2800(Struct_23443080* r4)
{
	uint8_t chip_id;
	int res = 0;

#if 0
	console_send_string("mt_fe_tn_init_tc2800 (todo.c): TODO\r\n");
#endif

	if (r4->tuner_init_OK != 1)
	{
		r4->bData_0x0c = 0; //r1
		r4->bData_0x1e = 0x0f;
		r4->wData_8 = 2; //r2
		r4->bData_10 = 1; //r5
		r4->bData_11 = 8;
		r4->bData_0x0d = 8;
		r4->tuner_crystal = 24000;
		r4->tuner_dac = 7200;
		r4->chipId = 0; //r1
		r4->bData_0x1b = 1; //r5
		r4->bData_0x1a = 2; //r2
		r4->bData_0x18 = 0; //r1
		r4->bData_0x30 = 0; //r1
		r4->wData_0x24 = 0; //r1
		r4->Data_0x28 = 0x80;
		r4->Data_0x2c = 0x103ddd7;

		if ((r4->tuner_dev_addr == 0xc6)
			//0x23447cde
				&& (r4->demod_address == 0x3a))
		{
			//0x23447ce6
			r4->bData_0x19 = 1; //r5
		}
		else
		{
			//loc_23447cea
			r4->bData_0x19 = 0; //r1
		}
		//->loc_23447cf4
	} //if (r4->bData_0 != 1)
	//loc_23447cee
	if (r4->chipId == 0)
	{
		//loc_23447cf4
		chip_id = 0; //r1

		res = sub_23445408(r4, 0x01, &chip_id);

		switch (chip_id)
		{
		case 0xb4:
			r4->chipId = 0xb4;
			break;

		default:
			r4->chipId = 0xb5; //VDR110
			break;
		}
	}
	//loc_23447d0a
	if ((r4->tuner_init_OK != 1) && (res == 0))
	{
		r4->tuner_init_OK = 1;
	}
	//loc_23447d16
	return res;
}


/* 23447d2e - todo */
void sub_23447d2e(Struct_23443080* r4, int r5)
{
	uint8_t sp_0x18 = 0;
	uint8_t sp_0x14 = 0;
	uint8_t sp_0x10 = 0;
	uint8_t sp_0xc = 0;
	uint8_t sp8;
	uint8_t sp4;
	uint8_t r7;
	uint8_t r6;
	uint8_t i; //r5

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_23447d2e: r5=%d\r\n", r5);
		console_send_string(debug_string);
	}
#endif

	mt_fe_tn_init_tc2800(r4);

	if (r4->bData_0x19 != 0)
	{
		if (r4->Data_4 > 106900) //0x1a194)
		{
			sub_23447d1c(r4);
			//->loc_23447d5e
		}
		else
		{
			//loc_23447d5a
			sub_23447c2c(r4);
		}
	}
	//loc_23447d5e
	if (r4->bData_0x0c == 0)
	{
		//loc_23447d66
		r4->bData_0x1c = 1;
		//->loc_23447d86
		r4->bData_0x1d = 0;
	}
	//loc_23447d6a
	else if ((r4->bData_0x0c == 1)
			|| (r4->bData_0x0c == 3)
			|| (r4->bData_0x0c == 4))
	{
		//loc_23447d76
		r4->bData_0x1c = 2;
		r4->bData_0x1d = 2;
		//->loc_23447d88
	}
	//loc_23447d7e
	else if (r4->bData_0x0c == 2)
	{
		r4->bData_0x1c = 3;
		//loc_23447d86
		r4->bData_0x1d = 0; //r6
	}
	else
	{
		//loc_23447d66
		r4->bData_0x1c = 1;
		//->loc_23447d86
		r4->bData_0x1d = 0;
	}
	//loc_23447d88
	sub_23445408(r4, 0x60, &sp_0x18);

	sp_0x18 &= 0x0e;

	if (sp_0x18 == 0x0e)
	{
		//loc_23447da2 -> loc_23447dc8
		sub_23448570(r4, 0xbd, 0x00);
		//->loc_23447dce
		sp_0x18 = r4->bData_0x0c;

		sub_23445448(r4, 0x60, sp_0x18, 3, 1);
		//loc_23447de4
	}
	else
	{
		//loc_23447da8
		sp_0x18 >>= 1;

		if (r4->bData_0x0c/*r0*/ != sp_0x18/*r1*/)
		{
			//0x23447db6
			if (sp_0x18 == 3)
			{
				//0x23447dba
				if (r4->bData_0x0c == 4)
				{
					//0x23447dbe
					if (r4->bData_0x19 == 0)
					{
						//0x23447dc4
						sub_23448570(r4, 0x5d, 0x00);
					}
					//loc_23447dce
				}
				else
				{
					//loc_23447da2
					sub_23448570(r4, 0xbd, 0x00);
					//->loc_23447dce
				}
			}
			//loc_23447dfa
			else if (sp_0x18 == 4)
			{
				if (r4->bData_0x0c == 3)
				{
					//0x23447e02
					sub_23448570(r4, 0x5d, 0x10);
					//loc_23447dce
				}
				else
				{
					//->loc_23447da2
					sub_23448570(r4, 0xbd, 0x00);
					//->loc_23447dce
				}
			}
			else
			{
				//loc_23447da2
				sub_23448570(r4, 0xbd, 0x00);
				//loc_23447dce
			}
			//loc_23447dce
			sp_0x18 = r4->bData_0x0c;

			sub_23445448(r4, 0x60, sp_0x18, 3, 1);
			//loc_23447de4
		}
		//loc_23447de4
	}
	//loc_23447de4
	if (r4->bData_0x1b/*r0*/ == 1)
	{
		sp8 = 15;
		sp4 = 15;

		if (r4->bData_0x0c == 0)
		{
			r7 = 0x82;
			//->loc_23447e08
		}
		else
		{
			//loc_23447e06
			r7 = 0xc2;
			//loc_23447e08
		}
	}
	else
	{
		//loc_23447e24
		sp8 = 20;
		sp4 = 80;
		//->loc_23447e06
		r7 = 0xc2;
	}
	//loc_23447e08
	if ((r4->bData_0x1c == 2) || (r4->bData_0x1c == 3))
	{
		//loc_23447e12
		r7 &= ~0x02;
	}
	//loc_23447e16
	if ((r4->bData_0x0c == 3) || (r4->bData_0x0c == 4))
	{
		//loc_23447e20
		r6 = 0x80;
	}
	else
	{
		//loc_23447e2e
		r6 = 0x60;
	}
	//loc_23447e30
	r4->Data_4 = r5;

	sub_23447c20(r4);

	sub_23445408(r4, 0xbd, &sp_0x18);

	if (sp_0x18 == 0)
	{
		//0x23447e4a
		if (r4->chipId == 0xb4)
		{
			rtos_task_wait(10);

			sub_23448570(r4, 0x08, 0x20);
			sub_23448570(r4, 0x07, 0x20);
			sub_23448570(r4, 0x08, 0x00);
			sub_23448570(r4, 0x07, 0x00);

			rtos_task_wait(1);
		}
		//loc_23447e84
		sub_23447226(r4);

		sub_23448570(r4, 0xbd, 0xff);
	}
	else
	{
		//loc_23447f48 -> loc_23447f66 -> loc_23447e8e
		sub_23448570(r4, 0x3a, 0x5d);
	}
	//0x23447e94
	if ((r4->bData_0x0c == 3) && (r4->wData_0x24 == 1))
	{
		//0x23447ea0
		if (r4->Data_4 == 198500) //0x30764)
		{
			//0x23447ea8
			sub_23445448(r4, 0xb6, 1, 2, 2);

			sub_23448570(r4, 0xb8, 0x01);
			sub_23448570(r4, 0xb8, 0x00);
			sub_23448570(r4, 0xb8, 0x1d);
			sub_23448570(r4, 0xb8, 0x23);
			sub_23448570(r4, 0xb8, 0x2a);
			sub_23448570(r4, 0xb8, 0x43);
			sub_23448570(r4, 0xb8, 0x00);
			sub_23448570(r4, 0xb8, 0x3f);
			sub_23448570(r4, 0xb8, 0x0f);
			sub_23448570(r4, 0xb8, 0x00);
			//0x23447f4e
			sub_23448570(r4, 0xb8, 0x0c);
			sub_23448570(r4, 0xb8, 0x13);
			//->loc_23447ffa
			sub_23448570(r4, 0xb8, 0x15);
		}
		else
		{
			//loc_23447f6c
			sub_23445448(r4, 0xb6, 1, 2, 2);

			sub_23448570(r4, 0xb8, 0x01);
			sub_23448570(r4, 0xb8, 0x00);
			sub_23448570(r4, 0xb8, 0x1d);
			//->loc_23447f9a
			sub_23448570(r4, 0xb8, 0x23);
			sub_23448570(r4, 0xb8, 0x2a);
			sub_23448570(r4, 0xb8, 0x43);
			sub_23448570(r4, 0xb8, 0x00);
			sub_23448570(r4, 0xb8, 0x3f);
			sub_23448570(r4, 0xb8, 0x0f);
			sub_23448570(r4, 0xb8, 0x00);
			sub_23448570(r4, 0xb8, 0x0c);
			sub_23448570(r4, 0xb8, 0x13);
			//loc_23447ffa
			sub_23448570(r4, 0xb8, 0x19);
		}
		//0x23448002
		sub_23448570(r4, 0xb8, 0x23);
		sub_23448570(r4, 0xb8, 0x31);
		sub_23448570(r4, 0xb8, 0x43);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x3f);
		sub_23448570(r4, 0xb8, 0x0f);
		sub_23448570(r4, 0xb8, 0x0f);
	}
	//loc_23447f98 -> loc_23448048
	sub_23448570(r4, 0x04, 0x7f);
	sub_23448570(r4, 0x05, 0xf8);

	sub_2344549a(r4);
	sub_234457a0(r4);
	sub_234459a2(r4);
	sub_23445f9e(r4);
	sub_234462fe(r4);

	sub_23448570(r4, 0x04, 0x0f);
	sub_23448570(r4, 0x04, 0x00);
	sub_23448570(r4, 0x05, 0x00);

	if (r4->bData_0x18 == 1)
	{
		//0x234480a0
		sub_23448570(r4, 0x13, r6 | 0x07);
	}
	else
	{
		//loc_234480a4
		sub_23448570(r4, 0x13, r6 | 0x06);
	}

	sub_23448570(r4, 0x30, 0x10);

	sub_2344786a(r4);

	sub_23445fc4(r4, r4->bData_0x0d);

	sub_23447566(r4);
	sub_23446182(r4);

	if ((r4->bData_0x0c == 1) || (r4->bData_0x0c == 3))
	{
		//loc_234480de
		sub_23448570(r4, 0xc9, 0x05);
	}
	else
	{
		//loc_234480e2
		sub_23448570(r4, 0xc9, 0x15);
	}

	sub_23448570(r4, 0x35, 0x19);
	sub_23448570(r4, 0x36, 0xe0);
	sub_23448570(r4, 0x59, 0x34);

	if (((r4->wData_8 == 1) || (r4->wData_8 == 2))
			&& (r4->bData_0x1a >= 2))
	{
		//loc_23448116
		sub_23445408(r4, 0x8a, &sp_0x14);

		sp_0x14 |= 0x10;

		sub_23448570(r4, 0x8a, sp_0x14);

		sub_23448570(r4, 0x89, 0x95);
	}
	else
	{
		//loc_2344813e
		sub_23448570(r4, 0x89, 0x86);
	}

	sub_23448570(r4, 0x88, 0xf7);
	sub_23448570(r4, 0x99, 0xf6);
	sub_23448570(r4, 0x9a, 0x75);
	sub_23448570(r4, 0xbe, 0x01);
	sub_23448570(r4, 0x00, 0x01);
	sub_23448570(r4, 0x00, 0x00);

	i = 100;

	while (i > 0)
	{
		//loc_23448186
		sub_23445408(r4, 0x06, &sp_0x10);

		sp_0x10 &= 0x10;

		sub_23445408(r4, 0x56, &sp_0xc);

		sp_0xc &= 0x02;

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_23447d2e: sp_0x10=0x%x, sp_0xc=0x%x\r\n", sp_0x10, sp_0xc);
			console_send_string(debug_string);
		}
#endif

		if (sp_0xc == 2)
		{
			break;
			//->loc_23448240
		}

		if (sp_0x10 == 0x10)
		{
			//0x234481ba
			sub_23448570(r4, 0x39, 0xc2);
			sub_23448570(r4, 0x38, 0x80);
			sub_23448570(r4, 0x38, 0xc0);

			sub_23445448(r4, 0x4b, 0x03, 3, 2);
			sub_23445448(r4, 0x4b, 0x02, 3, 2);
			sub_23445448(r4, 0x4b, 0x03, 3, 2);
			sub_23445448(r4, 0x4b, 0x00, 3, 2);

			rtos_task_wait(1);

			sub_23448570(r4, 0x00, 0x01);
			sub_23448570(r4, 0x00, 0x00);
			//->loc_23448240
			break;
		}
		//loc_23448232
		rtos_task_wait(1),

		i--;
	} //while (i > 0)
	//loc_23448240
	sub_23448570(r4, 0xb4, r7);

	if (sp8 < 10)
	{
		rtos_task_wait(1);
	}
	else
	{
		rtos_task_wait(sp8 / 10);
	}
	//0x2344825e
	if (((r4->wData_8 == 1) || (r4->wData_8 == 2))
			&& (r4->bData_0x1a >= 2))
	{
		sp_0x14 &= ~0x10;

		sub_23448570(r4, 0x8a, sp_0x14);
	}
	//loc_23448284
	if (sp4 < 10)
	{
		rtos_task_wait(1);
	}
	else
	{
		rtos_task_wait(sp4 / 10);
	}
	//0x23448298
	if (r4->bData_0x1b == 1)
	{
		if ((r4->bData_0x0c == 3) || (r4->bData_0x0c == 4))
		{
			//loc_234482a8
			sub_23445448(r4, 0x97, 0x05, 2, 0);
		}
		else
		{
			//loc_234482b0
			sub_23445448(r4, 0x97, 0x03, 2, 0);
		}

		if ((r4->bData_0x1c == 3) ||
				(r4->bData_0x0c == 1) || (r4->bData_0x0c == 3) || (r4->bData_0x0c == 4))
		{
			//loc_234482d4
			sub_23448570(r4, 0xb5, 0x75);
			sub_23448570(r4, 0xbb, 0xe8);
		}
		//loc_234482e8
	}
	//loc_234482e8
	if (r4->bData_0x18 == 1)
	{
		sub_23448570(r4, 0x13, r6 | 0x05);
	}
	else
	{
		//loc_234482f4
		sub_23448570(r4, 0x13, r6 | 0x04);
	}

	sub_23448570(r4, 0x30, 0x00);

	if ((r4->bData_0x0c == 1) || (r4->bData_0x0c == 3) || (r4->bData_0x0c == 4))
	{
		//loc_23448318
		sub_23448570(r4, 0x89, 0x93);
	}
	else
	{
		//loc_2344831c
		sub_23448570(r4, 0x89, 0xb3);
	}

	sub_23448570(r4, 0x9a, 0x93);

	if ((r4->wData_8 == 1) || (r4->wData_8 == 2))
	{
		//loc_2344833c
		sub_23445408(r4, 0xbd, &sp_0x18);

		if (sp_0x18 == 0xff)
		{
			if (r4->bData_10 == 1)
			{
				//0x23448354
				sp_0x18 = r4->bData_11;

				sp_0x18 = (sp_0x18 << 4) + 5;
				//->loc_23448392
				sub_23448570(r4, 0x14, sp_0x18);
			}
			else
			{
				//loc_23448364
				sub_23445408(r4, 0x8a, &sp_0x18);

				sp_0x18 &= 0x0f;

				if (sp_0x18 > 9)
				{
					//0x2344837c
					//r2 = 0x95
					//-> loc_23448392
					sub_23448570(r4, 0x14, 0x95);
				}
				//loc_23448380
				else if (sp_0x18 > 6)
				{
					//0x23448384
					//r2 = 0x75
					//-> loc_23448392
					sub_23448570(r4, 0x14, 0x75);
				}
				//loc_23448388
				else if (sp_0x18 > 3)
				{
					//0x2344838c
					//r2 = 0x55
					//-> loc_23448392
					sub_23448570(r4, 0x14, 0x55);
				}
				else
				{
					//loc_23448390
					//r2 = 0x45
					//-> loc_23448392
					sub_23448570(r4, 0x14, 0x45);
				}
			}
			//0x2344839a
			sub_23448570(r4, 0xbd, 0x0f);
		}
		//loc_234483a4
	}
	//loc_234483a4
	if (r4->wData_8 == 0)
	{
		sub_23448570(r4, 0x0c, 0x04);
	}
	//loc_234483b0
	else if (r4->wData_8 == 1)
	{
		sub_23448570(r4, 0x0c, 0x24);
	}
	//loc_234483b8
	else if (r4->wData_8 == 2)
	{
		sub_23448570(r4, 0x0c, 0x3c);
	}
	else
	{
		//loc_234483ac
		sub_23448570(r4, 0x0c, 0x04);
	}

	if (r4->bData_0x0c == 3)
	{
		sub_23448570(r4, 0x59, 0xb7);
	}
	else
	{
		//loc_234483d0
		sub_23448570(r4, 0x59, 0x34);
	}
}


/* 23448570 - complete */
int sub_23448570(Struct_23443080* r4, uint8_t reg, uint8_t data)
{
	uint8_t buf[2]; //size??

	buf[0] = reg;
	buf[1] = data;

	(r4->WriteReg)(0x86, 0xc0);

	if (0 != i2c_master_send(main_hI2c0, r4->tuner_dev_addr, buf, 2))
	{
		return -1;
	}

	return 0;
}

