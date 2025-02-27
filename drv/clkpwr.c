
#include <stdint.h>
#include "ucos_ii.h"
#include "sys_services.h"
#include "gpio.h"
#include "i2c.h"
#include "mcu.h"
#include "clkpwr.h"


extern int Data_2349242c; //2349242c


void sub_23434eb8(int);
void sub_23434ed8(int);
void sub_23434ef8(int);
void sub_23434f18(int);
void sub_23434f38(int);
void clkpwr_set_i2c_enable(int);
void sub_23434f78(int);
void sub_23434f98(int);
void sub_23434fb8(int);
void sub_23434fd4(int);
void sub_23434ff4(int);
void sub_23435050(int);
void sub_23435070(int);
void sub_2343528c(int);
void sub_23435014(int);
void sub_23435034(int);
void sub_23435050(int);
void sub_23435090(int);
void sub_234350b0(int);
void sub_234350d0(int);
void sub_234350f0(int);
void sub_23435110(int);
void sub_23435130(int);
void sub_23435150(int);
void sub_23435170(int);
void sub_23435190(int);
void sub_234351b0(int);
void sub_234351cc(int);
void sub_234351ec(int);
void sub_2343520c(int);
void sub_2343522c(int);
void sub_2343524c(int);
void sub_2343526c(int);
void sub_234352ac(int);
void sub_234352cc(int);
void sub_234352ec(int);
void sub_2343530c(int);
void sub_2343532c(int);
void sub_2343534c(int);
void sub_2343536c(int);
void sub_2343538c(int);
void sub_234353ac(int);


/* 23429430 - complete */
void sub_23429430(int a)
{
#if 0
	console_send_string("sub_23429430 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 0);

	a = (a << 0) & mask; //reset_VE

	FREG(0xca000024)[0] = (FREG(0xca000024)[0] & ~mask) | a; //SOFTRESET54
}


/* 2343493c - todo */
void clkpwr_reset_modules(int a)
{
	if (a & (1 << 0))
	{
		sub_23435070(0x00);
		sub_23435070(0x0f);
	}
	//loc_2343495c
	if (a & (1 << 2))
	{
		sub_2343528c(0);
		sub_2343528c(1);
	}
	//loc_23434974
	if (a & (1 << 1))
	{
		sub_234351cc(0);
		sub_234351cc(1);
	}
	//loc_2343498c
	if (a & (1 << 3))
	{
		sub_23435034(0);
		sub_234352ac(0);
		sub_23435034(1);
		sub_234352ac(1);
	}
	//loc_234349b4
	if (a & (1 << 4)) //0x10
	{
		sub_23434fd4(0);
		sub_23435014(0);
		sub_23434fd4(1);
		sub_23435014(1);
	}
	//loc_234349dc
	if (a & (1 << 5)) //0x20
	{
		sub_2343522c(0);
		sub_2343522c(1);
	}
	//loc_234349f4
	if (a & (1 << 6)) //0x40
	{
		sub_234351ec(0);
		sub_234351ec(1);
	}
	//loc_23434a0c
	if (a & 0x400)
	{
		sub_23435170(0);
		sub_23435170(1);
	}
	//loc_23434a24
	if (a & (1 << 7))
	{
		sub_23435130(0);
		sub_23435110(0);
		sub_23435130(1);
		sub_23435110(1);
	}
	//loc_23434a4c
	if (a & (1 << 8)) //0x100
	{
		sub_23435150(0);
		sub_234351b0(0);
		sub_23435150(1);
		sub_234351b0(1);
	}
	//loc_23434a74
	if (a & 0x200)
	{
		sub_23435190(0);
		sub_23435190(1);
	}
	//loc_23434a8c
	if (a & 0x800)
	{
		sub_234350b0(0);
		sub_234350b0(1);
	}
	//loc_23434aa4
	if (a & 0x1000)
	{
		sub_234350d0(0);
		sub_234350d0(1);
	}
	//loc_23434abc
	if (a & 0x2000)
	{
		sub_2343526c(0);
		sub_2343524c(0);
		sub_2343526c(1);
		sub_2343524c(1);
	}
	//loc_23434ae4
	if (a & 0x4000)
	{
		sub_234350f0(0);
		sub_234350f0(1);
	}
	//loc_23434afc
	if (a & 0x8000)
	{
		sub_23434ff4(0);
		sub_23434ff4(1);
	}
	//loc_23434b14
	if (a & 0x10000)
	{
		sub_2343520c(0);
		sub_2343520c(1);
	}
	//loc_23434b2c
	if (a & 0x20000)
	{
		//0x23434b34
		sub_23434fb8(1);
		sub_23435050(1);

		// Reset VD, VO and OSD Scaler
		*((volatile uint32_t*)0xca000078) = 0xFFF0FFFF; //CONFIGVO
		*((volatile uint32_t*)0xca00007c) = 0xFFF0FFFF; //CONFIGVD
		*((volatile uint32_t*)0xca000024) = 0; //SOFTRESET54
		*((volatile uint32_t*)0xca000078) = 0xFFFFFFFF; //CONFIGVO
		*((volatile uint32_t*)0xca00007c) = 0xFFFFFFFF; //CONFIGVD
		*((volatile uint32_t*)0xca000024) = 0xFFFFFFFF; //SOFTRESET54
	}

	return;
}


/* 23434b70 - todo*/
void clkpwr_increase_module_clocks(int a)
{
	if ((a & 4) || (a & 8) || (a & 0x10) || (a & 0x20) || (a & 0x200))
	{
		return;
	}

	if (a & 1)
	{
		sub_23435090(0);
	}

	if (a & 2)
	{
		sub_234352cc(1);
	}

	if (a & 0x40)
	{
		sub_2343530c(1);
	}

	if (a & 0x400)
	{
		sub_23434f98(1);
	}

	if (a & 0x80)
	{
		clkpwr_set_i2c_enable(1);
		sub_23434f38(1);
	}
	//loc_23434bd8
	if (a & 0x100)
	{
		sub_23434f78(1);
	}

	if (a & 0x800)
	{
		sub_23434ed8(1);
	}

	if (a & 0x1000)
	{
		sub_23434ef8(1);
	}

	if (a & 0x2000)
	{
		sub_2343534c(1);
		sub_2343532c(1);
		sub_2343538c(1);
		sub_2343536c(1);
		sub_234353ac(1);
	}
	//loc_23434c2c
	if (a & 0x4000)
	{
		sub_23434f18(1);
	}

	if (a & 0x8000)
	{
		sub_23434eb8(1);
	}

	if (a & 0x10000)
	{
		sub_234352ec(1);
	}

	if (a & 0x20000)
	{
		//0x23434c58
		sub_23435050(1);

		*((volatile uint32_t*)0xca00007c) //CONFIGVD
				= 0xffffffff;

		sub_23434fb8(1);

		Data_2349242c &= ~0x7e00;

		*((volatile uint32_t*)0xcb013020) //FREG_VE_DACPD
				= Data_2349242c;
#if 0
		[2] CONFVO2 (enable for clock 81MHz in VD)
		[1] CONFVO1 (enable for clock 162MHz in VD)
		[0] CONFVD0 (enable for clock 216MHz in VD)
#endif
	}

	return;
}


/* 23434c90 - todo */
void clkpwr_reduce_module_clocks(int a)
{
#if 0
	console_send_string("clkpwr_reduce_module_clocks (clkpwr.c): TODO\r\n");
#endif

	if ((a & 4) || (a & 8) || (a & 0x10) || (a & 0x20) || (a & 0x200))
	{
		return;
	}

	if (a & 1)
	{
		sub_23435090(1);
	}

	if (a & 2)
	{
		*((volatile uint32_t*)0xcc000090) = //FREG_AO_DACCONTROL
				*((volatile uint32_t*)0xcc000090) & ~(1 << 5); //!POWERDOWN

		sub_234352cc(0);
	}

	if (a & 0x40)
	{
		sub_2343530c(0);
	}

	if (a & 0x400)
	{
		sub_23434f98(0);
	}

	if (a & 0x80)
	{
		clkpwr_set_i2c_enable(0);
		sub_23434f38(0);
	}
	//loc_23434d08
	if (a & 0x100)
	{
		sub_23434f78(0);
	}

	if (a & 0x800)
	{
		sub_23434ed8(0);
	}

	if (a & 0x1000)
	{
		sub_23434ef8(0);
	}

	if (a & 0x2000)
	{
		sub_2343534c(0);
		sub_2343532c(0);
		sub_2343538c(0);
		sub_2343536c(0);
		sub_234353ac(0);
	}
	//loc_23434d5c
	if (a & 0x4000)
	{
		sub_23434f18(0);
	}

	if (a & 0x8000)
	{
		sub_23434eb8(0);
	}

	if (a & 0x10000)
	{
		sub_234352ec(0);
	}

	if (a & 0x20000)
	{
		//0x23434d88
		Data_2349242c |= 0x7e00;

		*((volatile uint32_t*)0xcb013020) //FREG_VE_DACPD
				= Data_2349242c;

		sub_23434fb8(0);
		sub_23435050(0);

		*((volatile uint32_t*)0xca00007c) //CONFIGVD
				= ~0x07;
#if 0
		[2] CONFVO2 1 enable for clock 81MHz in VD
		[1] CONFVO1 1 enable for clock 162MHz in VD
		[0] CONFVD0 1 enable for clock 216MHz in VD
#endif
	}

	return;
}


/* 23434dc0 - todo */
int clkpwr_reset()
{
	int res = 0;

	clkpwr_reset_modules(0x20000);

	return res;
}


/* 23434dd8 - todo */
int clkpwr_low_power()
{
	clkpwr_reduce_module_clocks(0x3b9c3);

	return 0;
}


/* 23434dec - todo */
int clkpwr_full_power()
{
	clkpwr_increase_module_clocks(0x3b9c3);

	return 0;
}


extern void* main_hI2c0;


/* 23434e00 / 23442e34 - complete */
int clkpwr_mcu_read(Struct_23434e00* r4)
{
	int res;
	uint8_t sp[10];

#if 0
	console_send_string("clkpwr_mcu_read (todo.c): TODO\r\n");
#endif

	res = i2c_master_receive(main_hI2c0, 0x6c, &sp, 10);

	if (res == 0)
	{
#if 0
		for (int i = 0; i < 10; i++)
		{
			extern char debug_string[];
			sprintf(debug_string, "clkpwr_mcu_read: sp[%d]=0x%02x\r\n", i, sp[i]);
			console_send_string(debug_string);
		}
#endif

		r4->bData_8 = sp[0];
		r4->bData_9 = sp[1];
		r4->bData_6 = sp[2];
		r4->bData_7 = sp[3];
		r4->Data_0 = sp[4];
		r4->bData_4 = sp[8];
		r4->bData_5 = sp[9];
	}
#if 0
	else
	{
		console_send_string("clkpwr_mcu_read: i2c read error\r\n");
	}
#endif

	return res;
}


/* 23434e64 / 23442e98 - todo */
void clkpwr_mcu_write(Struct_23434e00* r0, uint8_t r1, uint8_t r2, uint8_t* r3)
{
#if 0
	console_send_string("clkpwr_mcu_write (todo.c): TODO\r\n");
#endif

	uint8_t lr, ip;

	r0->bData_0xa = r2;
	ip = r2;
	r0->bData_0xb = r1;

	lr = 0;

	while (1)
	{
		//loc_23434e78
		if (ip-- != 0)
		{
			r0->Data_12[lr++] = *r3++;
		}
		else
		{
			break;
		}
	}

#if 0 //TODO!!! This will cancel Debugging!
	i2c_master_send(main_hI2c0, 0x6c, &r0->bData_0xa, r2 + 2);
#else
	console_send_string("clkpwr_mcu_write: i2c_master_send disabled!\r\n");
#endif
}


/* 23434eb8 - todo */
void sub_23434eb8(int a)
{
	a = (a << 2) & (1 << 2); //CLK_162_UPI_EN (enable signal for clk UPI IF)

	*((volatile uint32_t*)0xca000004) = //CLK162ENABLE
			(*((volatile uint32_t*)0xca000004) & ~(1 << 2)) | a;
}


/* 23434ed8 - todo */
void sub_23434ed8(int a)
{
	a = (a << 8) & (1 << 8); //CLK_81_SFLASH_EN

	*((volatile uint32_t*)0xca000008) = //CLK81ENABLE
			(*((volatile uint32_t*)0xca000008) & ~(1 << 8)) | a;
}


/* 23434ef8 - todo */
void sub_23434ef8(int a)
{
	a = (a << 7) & (1 << 7); //CLK_81_SSP_EN

	*((volatile uint32_t*)0xca000008) = //CLK81ENABLE
			(*((volatile uint32_t*)0xca000008) & ~(1 << 7)) | a;
}


/* 23434f18 - todo */
void sub_23434f18(int a)
{
	a = (a << 6) & (1 << 6); //CLK_81_FPC_EN

	*((volatile uint32_t*)0xca000008) = //CLK81ENABLE
			(*((volatile uint32_t*)0xca000008) & ~(1 << 6)) | a;
}


/* 23434f38 - todo */
void sub_23434f38(int a)
{
	a = (a << 5) & (1 << 5); //CLK_81_IIC_2_EN

	*((volatile uint32_t*)0xca000008) = //CLK81ENABLE
			(*((volatile uint32_t*)0xca000008) & ~(1 << 5)) | a;
}


/* 23434f58 - todo */
void clkpwr_set_i2c_enable(int a)
{
#if 0
	console_send_string("clkpwr_set_i2c_enable (clkpwr.c)\r\n");
#endif

	a = (a << 4) & (1 << 4); //CLK_81_IIC_EN

	*((volatile uint32_t*)0xca000008) = //CLK81ENABLE
			(*((volatile uint32_t*)0xca000008) & ~(1 << 4)) | a;
}


/* 23434f78 - todo */
void sub_23434f78(int a)
{
	a = (a << 3) & (1 << 3); //CLK_81_ICC_EN

	*((volatile uint32_t*)0xca000008) = //CLK81ENABLE
			(*((volatile uint32_t*)0xca000008) & ~(1 << 3)) | a;
}


/* 23434f98 - todo */
void sub_23434f98(int a)
{
	a = (a << 2) & (1 << 2); //CLK_81_GPIO_EN

	*((volatile uint32_t*)0xca000008) = //CLK81ENABLE
			(*((volatile uint32_t*)0xca000008) & ~(1 << 2)) | a;
}


/* 23434fb8 - todo */
void sub_23434fb8(int a)
{
	a = (a << 0) & (1 << 0); //CLK_27_EN

	*((volatile uint32_t*)0xca00000c) = //CLK54ENABLE
			(*((volatile uint32_t*)0xca00000c) & ~(1 << 0)) | a;
}


/* 23434fd4 - todo */
void sub_23434fd4(int a)
{
	a = (a << 3) & (1 << 3); //reset_SDRAM162_1

	*((volatile uint32_t*)0xca000018) = //SOFTRESET162
			(*((volatile uint32_t*)0xca000018) & ~(1 << 3)) | a;
}


/* 23434ff4 - todo */
void sub_23434ff4(int a)
{
	a = (a << 2) & (1 << 2); //reset_UPI

	*((volatile uint32_t*)0xca000018) = //SOFTRESET162
			(*((volatile uint32_t*)0xca000018) & ~(1 << 2)) | a;
}


/* 23435014 - todo */
void sub_23435014(int a)
{
	a = (a << 1) & (1 << 1); //reset_SDRAM162_2

	*((volatile uint32_t*)0xca000018) = //SOFTRESET162
			(*((volatile uint32_t*)0xca000018) & ~(1 << 1)) | a;
}


/* 23435034 - todo */
void sub_23435034(int a)
{
	a = (a << 0) & (1 << 0); //reset_AXI162

	*((volatile uint32_t*)0xca000018) = //SOFTRESET162
			(*((volatile uint32_t*)0xca000018) & ~(1 << 0)) | a;
}


/* 23435050 - todo */
void sub_23435050(int a)
{
	a = (a << 6) & (1 << 6); //CLK_HDMI_EN

	*((volatile uint32_t*)0xca000040) = //FDCLKSEL
			(*((volatile uint32_t*)0xca000040) & ~(1 << 6)) | a;
}


/* 23435070 - todo */
void sub_23435070(int a)
{
	a = (a << 16) & (0x0f << 16); //RESETARM

	*((volatile uint32_t*)0xca000070) = //CONFIGARM
			(*((volatile uint32_t*)0xca000070) & ~(0x0f << 16)) | a;
}


/* 23435090 - todo */
void sub_23435090(int a)
{
	a = (a << 7) & (1 << 7); //CONFARM7 (clock select for ARM core (0 = 324MHz, 1 = 162MHz))

	*((volatile uint32_t*)0xca000070) = //CONFIGARM
			(*((volatile uint32_t*)0xca000070) & ~(1 << 7)) | a;
}


/* 234350b0 - todo */
void sub_234350b0(int a)
{
	a = (a << 8) & (1 << 8); //reset_SFLASH

	*((volatile uint32_t*)0xca00001c) = //SOFTRESET81
			(*((volatile uint32_t*)0xca00001c) & ~(1 << 8)) | a;
}


/* 234350d0 - todo */
void sub_234350d0(int a)
{
	a = (a << 7) & (1 << 7); //reset_SSP

	*((volatile uint32_t*)0xca00001c) = //SOFTRESET81
			(*((volatile uint32_t*)0xca00001c) & ~(1 << 7)) | a;
}


/* 234350f0 - todo */
void sub_234350f0(int a)
{
	a = (a << 6) & (1 << 6); //reset_UART_FPC

	*((volatile uint32_t*)0xca00001c) = //SOFTRESET81
			(*((volatile uint32_t*)0xca00001c) & ~(1 << 6)) | a;
}


/* 23435110 - todo */
void sub_23435110(int a)
{
	a = (a << 5) & (1 << 5); //reset_I2C_2

	*((volatile uint32_t*)0xca00001c) = //SOFTRESET81
			(*((volatile uint32_t*)0xca00001c) & ~(1 << 5)) | a;
}


/* 23435130 - todo */
void sub_23435130(int a)
{
	a = (a << 4) & (1 << 4); //reset_I2C_0_1

	*((volatile uint32_t*)0xca00001c) = //SOFTRESET81
			(*((volatile uint32_t*)0xca00001c) & ~(1 << 4)) | a;
}


/* 23435150 - todo */
void sub_23435150(int a)
{
	a = (a << 3) & (1 << 3); //reset_APB_E_ICC

	*((volatile uint32_t*)0xca00001c) = //SOFTRESET81
			(*((volatile uint32_t*)0xca00001c) & ~(1 << 3)) | a;
}


/* 23435170 - todo */
void sub_23435170(int a)
{
	a = (a << 2) & (1 << 2); //reset_GPIO

	*((volatile uint32_t*)0xca00001c) = //SOFTRESET81
			(*((volatile uint32_t*)0xca00001c) & ~(1 << 2)) | a;
}


/* 23435190 - todo */
void sub_23435190(int a)
{
	a = (a << 1) & (1 << 1); //reset_IRQ_CTRL

	*((volatile uint32_t*)0xca00001c) = //SOFTRESET81
			(*((volatile uint32_t*)0xca00001c) & ~(1 << 1)) | a;
}


/* 234351b0 - todo */
void sub_234351b0(int a)
{
	a = (a << 0) & (1 << 0); //Reserved

	*((volatile uint32_t*)0xca00001c) = //SOFTRESET81
			(*((volatile uint32_t*)0xca00001c) & ~(1 << 0)) | a;
}


/* 234351cc - todo */
void sub_234351cc(int a)
{
	a = (a << 23) & (1 << 23); //CONFDMACAU23 (reset Audio output)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 23)) | a;
}


/* 234351ec - todo */
void sub_234351ec(int a)
{
	a = (a << 22) & (1 << 22); //CONFDMACAU22 (reset Ethernet)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 22)) | a;
}


/* 2343520c - todo */
void sub_2343520c(int a)
{
	a = (a << 21) & (1 << 21); //CONFDMACAU21 (reset USB)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 21)) | a;
}


/* 2343522c - todo */
void sub_2343522c(int a)
{
	a = (a << 20) & (1 << 20); //CONFDMACAU20 (reset DMA)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 20)) | a;
}


/* 2343524c - todo */
void sub_2343524c(int a)
{
	a = (a << 19) & (1 << 19); //CONFDMACAU19 (reset TSD23)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 19)) | a;
}


/* 2343526c - todo */
void sub_2343526c(int a)
{
	a = (a << 18) & (1 << 18); //CONFDMACAU18 (reset TSD01)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 18)) | a;
}


/* 2343528c - todo */
void sub_2343528c(int a)
{
	a = (a << 17) & (1 << 17); //CONFDMACAU17 (reset Audio processor)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 17)) | a;
}


/* 234352ac - todo */
void sub_234352ac(int a)
{
	a = (a << 16) & (1 << 16); //CONFDMACAU16 (reset AXI_modules)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 16)) | a;
}


/* 234352cc - todo */
void sub_234352cc(int a)
{
	a = (a << 15) & (1 << 15); //CONFDMACAU15 (enable for 81 clock AUDIO)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 15)) | a;
}


/* 234352ec - todo */
void sub_234352ec(int a)
{
	a = (a << 14) & (1 << 14); //CONFDMACAU14 (enable for 81 clock USB)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 14)) | a;
}


/* 2343530c - todo */
void sub_2343530c(int a)
{
	a = (a << 13) & (1 << 13); //CONFDMACAU13 (enable for 81 clock Ethernet)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 13)) | a;
}


/* 2343532c - todo */
void sub_2343532c(int a)
{
	a = (a << 12) & (1 << 12); //CONFDMACAU12 (enable for 81 clock TSD23)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 12)) | a;
}


/* 2343534c - todo */
void sub_2343534c(int a)
{
	a = (a << 11) & (1 << 11); //CONFDMACAU11 (enable for 81 clock TSD01)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 11)) | a;
}


/* 2343536c - todo */
void sub_2343536c(int a)
{
	a = (a << 6) & (1 << 6); //CONFDMACAU6 (enable for 162 clock TSD23)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 6)) | a;
}


/* 2343538c - todo */
void sub_2343538c(int a)
{
	a = (a << 5) & (1 << 5); //CONFDMACAU5 (enable for 162 clock TSD01)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 5)) | a;
}


/* 234353ac - todo */
void sub_234353ac(int a)
{
	a = (a << 0) & (1 << 0); //CONFDMACAU0 (enable for 324MHz clock TSD's)

	*((volatile uint32_t*)0xca000074) = //CONFIGDMACAUDIO
			(*((volatile uint32_t*)0xca000074) & ~(1 << 0)) | a;
}


