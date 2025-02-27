
#include <stdint.h>
#include "ucos_ii.h"
#include "sys_services.h"
#include "vienc.h"


void sub_2342925c();
void sub_2342934c();
void VE_SetRgbconf_Colbar(int);
void VE_SetRgbconf_Ycrcb(int);
void VE_SetRgbconf_NtscOn(int);
void sub_23429150(int);
void VE_SetRgbconf_BlkOn(int);
void VE_SetRgbconf_SynconGree(int);
void VE_SetCeconf_Secam(int);
void VE_SetCeconf_Ipce1sel(int);
void VE_SetCeconf_Bwgui(int);
void VE_SetCeconf_Xsyncmx(int);
void VE_SetCeconf_Cydly(int);
void VE_SetCeconf_Cysel(int);
void VE_SetCeconf_M3db(int);
void VE_SetCeconf_Pal525(int);
void VE_SetCeconf_Pal(int);
void VE_SetCeconf_M1m0(int);
void VE_SetCeconf_Pslev(int);
void VE_SetCeburstint_Pal60mEn(int);
void VE_SetCeburstint_Fscint(int);
void VE_SetCeburstfra1_Fscfra(int);
void VE_SetCeburstfra2_Fscfra(int);
void VE_SetDacPd_CeFilterFlag(int);
void VE_SetDacPd_Pddac6(int);
void VE_SetDacPd_Pddac5(int);
void VE_SetDacPd_Pddac4(int);
void VE_SetDacPd_Pddac3(int);
void VE_SetDacPd_Pddac2(int);
void VE_SetDacPd_Pddac1(int);
void VE_SetDacPd_Pddac0(int);
void VE_SetLutConf_RgbLutEn(int);
void VE_SetLutConf_LutSel(int);
void VE_SetLutConf_LutEn(int);
void VO_SetDisphdmidehorstartstop_Dehorstart(int);
void VO_SetDisphdmidehorstartstop_Dehorstop(int);
void VO_SetDisphdmideverstartstop_Deverstart(int);
void VO_SetDisphdmideverstartstop_Deverstop(int);
void sub_23428cd0(int);
void sub_23428cf4(int);
void sub_23428d18(int);
void sub_23428d3c(int);
void sub_23428d60(int);
void sub_23428d84(int);
void sub_23428da8(int);
void sub_23428dcc(int);
void sub_23428df0(int);
void sub_23428e14(int);
void sub_23428e58(int);
void sub_23428e7c(int);
void VO_SetDispirq0_Dispirq0enable(int);
void VO_SetDispirq0_Dispfiedframeirq0(int);
void VO_SetDispirq0_Dispfiedirq0sel(int);
void VO_SetDispirq0_Dispverposirq0(int);
void sub_23428f24(int);
void sub_23428f44(int);
void sub_23428f64(int);
void sub_23428f84(int);
void VO_SetDispdachdmictrl_Dispdacsel5(int);
void VO_SetDispdachdmictrl_Dispdacsel4(int);
void VO_SetDispdachdmictrl_Dispdacsel012(int);
void sub_23429008(int);
void sub_23429028(int);
void sub_23429048(int);
void sub_23429074(int);
void sub_234290a0(int);
void sub_234290cc(int);
void sub_234290f8(int);
void sub_23429124(int);
void sub_23429178(int);
void sub_234291a0(int);
void sub_234291cc(int);
void sub_23429430(int);
void VE_HD_SetEnable_ConvEn(int);
void VE_HD_SetEnable_RgbEn(int);
void VE_HD_SetEnable_En(int);
void sub_234286b4(int);
void sub_234286d4(int);
void sub_234286f4(int);
void sub_23428718(int);
void sub_23428738(int);
void sub_23428758(int);
void sub_2342877c(int);
void sub_2342879c(int);
void sub_234287bc(int);
void sub_234287e0(int);
void sub_23428800(int);
void sub_2342881c(int);
void sub_23428840(int);
void sub_23428864(int);
void sub_23428888(int);
void sub_23428898(int);
void sub_234288bc(int);
void sub_234288e0(int);
void sub_23428904(int);
void sub_23428928(int);
void sub_2342894c(int);
void sub_23428970(int);
void sub_23428994(int, int);
void sub_234289b8(int, int);
void sub_234289e0(int, int);
void sub_23428a04(int, int);
void sub_23428a2c(int, int);
void sub_23428a88(int, int);
void sub_23428ab0(int, int);
void sub_23428ad4(int, int);
void sub_23428afc(int, int);
void sub_23428b20(int, int);
void sub_23428b48(int, int);
void sub_23428b5c(int, int);
void sub_23428b6c(int, int);
void VO_SetDisphorll_Disphorll(int);
void VO_SetDispversize_Dispversize(int);
void sub_23428be0(int);
void sub_23428c00(int);
void sub_23428c1c(int);
void sub_23428e38(int);
void sub_234291f8(int);
void VO_SetDisphorll1_Disphorll1(int);
void sub_2342923c(int);


//23492418
int Data_23492418 = 0; //23492418 +0
int Data_2349241c = 0; //2349241c +4
int Data_23492420 = 0; //23492420 +8
int Data_23492424 = 0; //23492424 +0xc
int Data_23492428 = 0; //23492428 +0x10
int Data_2349242c = 0; //2349242c +0x14
int Data_23492430 = 0; //23492430 +0x18
int Data_23492434 = 0; //23492434 +0x1c
int Data_23492438 = 0; //23492438 +0x20
int Data_2349243c = 0; //2349243c +0x24
int Data_23492440 = 0; //23492440 +0x28
int Data_23492444 = 0; //23492444 +0x2c
int Data_23492448 = 0; //23492448 +0x30
int Data_2349244c = 0; //2349244c +0x34
int Data_23492450 = 0; //23492450 +0x38
int Data_23492454 = 0; //23492454 +0x3c
void* vienc_sema = 0; //23492458 +0x40
int Data_23492480 = 0; //23492480
int Data_234924a8 = 0; //234924a8


struct Struct_235f0ccc
{
	int (*onEnable)(); //0
	void (*onDisable)(); //4
	Vienc_Params params; //8
	//24
} Data_235f0ccc[2]; //235f0ccc -> 235F0CFC



/* 23425940 - todo */
void sub_23425940()
{
#if 0
	console_send_string("sub_23425940 (todo.c): TODO\r\n");
#endif

	VE_SetRgbconf_NtscOn(1);
	VE_SetCeconf_Secam(0);
	VE_SetCeconf_Ipce1sel(0);
	VE_SetCeconf_Bwgui(0);
	VE_SetCeconf_Xsyncmx(0);
	VE_SetCeconf_Cydly(0);
	VE_SetCeconf_Cysel(0);
	VE_SetCeconf_M3db(0);
	VE_SetCeconf_Pal525(0);
	VE_SetCeconf_Pal(0);
	VE_SetCeconf_M1m0(3);
	VE_SetCeconf_Pslev(0);
	VE_SetCeburstint_Pal60mEn(0);
	VE_SetCeburstint_Fscint(0x43e);
	VE_SetCeburstfra1_Fscfra(0xf7a);
	VE_SetCeburstfra2_Fscfra(0xd7);
	sub_23429048(0xd68);
	sub_23429074(0x106);
	sub_234290a0(0x1e0);
	sub_234290cc(0xcf8);
	sub_234290f8(0x13);
	sub_23429124(0x103);

	FREG(0xcb010048)[0] = 0x100005;

	sub_234291cc(0x30);
	sub_234291a0(0x104);
	sub_23429178(1);
}


/* 23425a1c - complete */
void sub_23425a1c()
{
#if 0
	console_send_string("sub_23425a1c (todo.c): TODO\r\n");
#endif

	VE_SetRgbconf_BlkOn(0);
	VE_SetRgbconf_Ycrcb(0);
	VE_SetLutConf_RgbLutEn(0);
	VE_SetLutConf_LutSel(0);
	VE_SetLutConf_LutEn(0);
	VE_SetRgbconf_SynconGree(0);
	VE_SetDacPd_CeFilterFlag(0);
	VO_SetDispdachdmictrl_Dispdacsel012(0); //DAC012 input select: VE_HD input
	VO_SetDispdachdmictrl_Dispdacsel4(1); //DAC4 input select: SD RGB R signal
	VO_SetDispdachdmictrl_Dispdacsel5(1); //DAC5 input select: SD RGB G signal
	VE_SetDacPd_Pddac3(0);
	VE_SetDacPd_Pddac4(0);
	VE_SetDacPd_Pddac5(0);
	VE_SetDacPd_Pddac6(0);
	VE_SetCeconf_Ipce1sel(0);
	VE_SetRgbconf_Colbar(0);
	sub_23429150(1);

	FREG(0xcb013008)[0] = 0x2e2e; //VE_RGBChrom
}


/* 23425ab8 - todo */
int sub_23425ab8() //1080i@50???
{
#if 0
	console_send_string("sub_23425ab8 (todo.c): TODO\r\n");
#endif

	sync_SetFd2to54Mhz(0);
	sub_2342923c(3);
	VO_SetDisphorll_Disphorll(2640); //0xa50/*r4*/);
	VO_SetDispversize_Dispversize(562); //0x232/*r4*/);
	sub_23428e38(0);
	sub_23428e58(1);
	sub_23428e7c(0);
	sub_23428c1c(3);
	sub_23428be0(0);
	sub_23428c00(1);
	sub_23429008(0);
	sub_23429028(1);
	sub_234291f8(0);
	VO_SetDisphorll1_Disphorll1(0xfff);
	VO_SetDispirq0_Dispirq0enable(1);
	VO_SetDispirq0_Dispfiedframeirq0(0);
	VO_SetDispirq0_Dispfiedirq0sel(0);

	int r0 = VO_GetDispversize_Dispversize();

	VO_SetDispirq0_Dispverposirq0(r0 - 3);

	sub_23428f24(1);
	sub_23428f44(0);
	sub_23428f64(0);

	r0 = VO_GetDispversize_Dispversize();

	sub_23428f84(r0 - 1);

	sub_23428cd0(1);
	sub_23428cf4(0x2d);
	sub_23428d18(1);
	sub_23428d3c(1);
	sub_23428d60(0);
	sub_23428d84(5);
	sub_23428da8(0x529/*r5*/);
	sub_23428dcc(0x529/*r5*/);
	sub_23428df0(0x232/*r4*/);
	sub_23428e14(0x804);
	VO_SetDisphdmidehorstartstop_Dehorstart(193);
	VO_SetDisphdmidehorstartstop_Dehorstop(2113);
	VO_SetDisphdmideverstartstop_Deverstart(20);
	VO_SetDisphdmideverstartstop_Deverstop(560);
	sub_23428904(0x14);
	sub_23428928(0x230);
	sub_2342894c(0x247);
	sub_23428970(0x463);
	sub_23428864(0);
	sub_23428840(0x12c);
	sub_2342881c(0x258);
	sub_234288e0(0);
	sub_234288bc(0x12c);
	sub_23428898(0x258);
	sub_234287e0(2);
	sub_23428800(6);
	sub_23428888(6);

	sub_23428994(0, 2);
	sub_234289b8(0, 0x2b);
	sub_234289e0(0, 1);
	sub_23428a04(0, 0x57);
	sub_23428a2c(0, 0);
	sub_23428a88(0, 0x36f/*r4*/);
	sub_23428ab0(0, 1);
	sub_23428ad4(0, 0x107/*r5*/);
	sub_23428afc(0, 0);
	sub_23428b20(0, 0x2b);
	sub_23428b48(0, 4);
	sub_23428b5c(0, 9);

	sub_23428994(1, 2);
	sub_234289b8(1, 0x2b);
	sub_234289e0(1, 1);
	sub_23428a04(1, 0x4CF/*r6*/);
	sub_23428a2c(1, 0);
	sub_23428a88(1, 0x2b);
	sub_23428b48(1, 2);
	sub_23428b5c(1, 1);

	sub_23428994(2, 2);
	sub_234289b8(2, 0x2b);
	sub_234289e0(2, 1);
	sub_23428a04(2, 0x93);
	sub_23428a2c(2, 3);
	sub_23428a88(2, 0x77F/*r7*/);
	sub_23428ab0(2, 1);
	sub_23428ad4(2, 0x1E3/*r8*/);
	sub_23428afc(2, 0);
	sub_23428b20(2, 0x2b);
	sub_23428b48(2, 4);
	sub_23428b5c(2, 0x22B);

	sub_23428994(3, 2);
	sub_234289b8(3, 0x2b);
	sub_234289e0(3, 1);
	sub_23428a04(3, 0x4CF/*r6*/);
	sub_23428a2c(3, 0);
	sub_23428a88(3, 0x2b);
	sub_23428b48(3, 2);
	sub_23428b5c(3, 0);

	sub_23428994(4, 2);
	sub_234289b8(4, 0x2b);
	sub_234289e0(4, 1);
	sub_23428a04(4, 0x57);
	sub_23428a2c(4, 0);
	sub_23428a88(4, 0x36f/*r4*/);
	sub_23428ab0(4, 1);
	sub_23428ad4(4, 0x107/*r5*/);
	sub_23428afc(4, 0);
	sub_23428b20(4, 0x2b);
	sub_23428b48(4, 4);
	sub_23428b5c(4, 9);

	sub_23428994(5, 2);
	sub_234289b8(5, 0x2b);
	sub_234289e0(5, 1);
	sub_23428a04(5, 0x4CF/*r6*/);
	sub_23428a2c(5, 0);
	sub_23428a88(5, 0x2b);
	sub_23428b48(5, 2);
	sub_23428b5c(5, 0);

	sub_23428994(6, 2);
	sub_234289b8(6, 0x2b);
	sub_234289e0(6, 1);
	sub_23428a04(6, 0x93);
	sub_23428a2c(6, 3);
	sub_23428a88(6, 0x77F/*r7*/);
	sub_23428ab0(6, 1);
	sub_23428ad4(6, 0x1E3/*r8*/);
	sub_23428afc(6, 0);
	sub_23428b20(6, 0x2b);
	sub_23428b48(6, 4);
	sub_23428b5c(6, 0x22b);

	VE_HD_SetEnable_En(1);

	return 0;
}


/* 23425fdc - todo */
void sub_23425fdc() //720p@50???
{
#if 0
	console_send_string("sub_23425fdc (todo.c): TODO\r\n");
#endif

	int r4 = 1980;
	int r5 = 749;

	sync_SetFd2to54Mhz(0);
	sub_2342923c(3);
	VO_SetDisphorll_Disphorll(r4); //0x7bc/*r4*/);
	VO_SetDispversize_Dispversize(r5); //0x2ed/*r5*/);
	sub_23428e38(1);
	sub_23428e58(20);
	sub_23428e7c(748); //0x2ec
	sub_23428c1c(1);
	sub_23428c1c(3);
	sub_23428be0(0);
	sub_23428c00(2);
	sub_23429008(1);
	sub_23429028(0);
	sub_234291f8(0);
	VO_SetDisphorll1_Disphorll1(0xfff);
	VO_SetDispirq0_Dispirq0enable(1);
	VO_SetDispirq0_Dispfiedframeirq0(0);
	VO_SetDispirq0_Dispfiedirq0sel(0);

	int r0 = VO_GetDispversize_Dispversize();

	VO_SetDispirq0_Dispverposirq0(r0 - 3);

	sub_23428f24(1);
	sub_23428f44(0);
	sub_23428f64(0);

	r0 = VO_GetDispversize_Dispversize();

	sub_23428f84(r0 - 1);

	sub_23428cd0(1);
	sub_23428cf4(0x29);
	sub_23428d18(1);
	sub_23428d3c(1);
	sub_23428d60(0);
	sub_23428d84(5);
	sub_23428da8(1);
	sub_23428dcc(1);
	sub_23428df0(0x800);
	sub_23428e14(0x805);
	VO_SetDisphdmidehorstartstop_Dehorstart(261);
	VO_SetDisphdmidehorstartstop_Dehorstop(1541);
	VO_SetDisphdmideverstartstop_Deverstart(25);
	VO_SetDisphdmideverstartstop_Deverstop(745);
	sub_23428904(0x19);
	sub_23428928(0x2E9);
	sub_2342894c(0x307);
	sub_23428970(0x5d7);
	sub_23428864(0);
	sub_23428840(0x12c);
	sub_2342881c(0x258);
	sub_234288e0(0);
	sub_234288bc(0x12c);
	sub_23428898(0x258);
	sub_234287e0(3);
	sub_23428800(3);
	sub_23428888(6);

	sub_23428b48(0, 4);
	sub_23428994(0, 2);
	sub_234289b8(0, 0x27);
	sub_234289e0(0, 1);
	sub_23428a04(0, 0xdb);
	sub_23428a2c(0, 0);
	sub_23428a88(0, 0x4ff/*r4*/);
	sub_23428ab0(0, 1);
	sub_23428ad4(0, 0x18F/*r5*/);
	sub_23428afc(0, 0);
	sub_23428b20(0, 0x27);
	sub_23428b5c(0, 4);

	sub_23428b48(1, 4);
	sub_23428994(1, 2);
	sub_234289b8(1, 0x27);
	sub_234289e0(1, 1);
	sub_23428a04(1, 0xdb);
	sub_23428a2c(1, 3);
	sub_23428a88(1, 0x4ff);
	sub_23428ab0(1, 1);
	sub_23428ad4(1, 0x18F/*r5*/);
	sub_23428afc(1, 0);
	sub_23428b20(1, 0x27);
	sub_23428b5c(1, 0x2e8);

	sub_23428b48(2, 4);
	sub_23428994(2, 2);
	sub_234289b8(2, 0x27);
	sub_234289e0(2, 1);
	sub_23428a04(2, 0xdb);
	sub_23428a2c(2, 0);
	sub_23428a88(2, 0x4ff/*r4*/);
	sub_23428ab0(2, 1);
	sub_23428ad4(2, 0x18F/*r5*/);
	sub_23428afc(2, 0);
	sub_23428b20(2, 0x27);
	sub_23428b5c(2, 4);

	sub_23428b48(3, 4);
	sub_23428994(3, 2);
	sub_234289b8(3, 0x27);
	sub_234289e0(3, 1);
	sub_23428a04(3, 0xdb);
	sub_23428a2c(3, 3);
	sub_23428a88(3, 0x4ff/*r4*/);
	sub_23428ab0(3, 1);
	sub_23428ad4(3, 0x18F/*r5*/);
	sub_23428afc(3, 0);
	sub_23428b20(3, 0x27);
	sub_23428b5c(3, 0x2e8);

	VE_HD_SetEnable_En(1);
}


/* 23427bec - complete */
int vienc_configure_sd(void* a)
{
	struct Struct_235f0ccc* r4 = a;

#if 0
	console_send_string("vienc_configure_sd (todo.c): TODO\r\n");
#endif

	sub_2342925c();

	if (r4->params.Data_8 == 4)
	{
		sub_2342934c();
		//->loc_23427c14
	}
	//loc_23427c0c
	else if (r4->params.Data_8 == 2)
	{
		sub_23425940();
	}
	//loc_23427c14
	if (r4->params.Data_12 == 5)
	{
		sub_23425a1c();
	}

	return 0;
}


/* 23427c28 - complete */
void sub_23427c28(struct Struct_235f0ccc* a)
{
#if 0
	console_send_string("sub_23427c28 (todo.c): TODO\r\n");
#endif

	if (a->params.Data_4 == 4)
	{
		sub_23425ab8();
	}
	else if (a->params.Data_4 == 5)
	{
		sub_23425fdc();
	}
	else if (a->params.Data_4 == 6)
	{
		sub_2342670c();
	}
	else if (a->params.Data_4 == 7)
	{
		sub_234263d8();
	}
	else if (a->params.Data_4 == 8)
	{
		sub_23426c60();
	}
	else if (a->params.Data_4 == 9)
	{
		sub_234272cc();
	}
	else if (a->params.Data_4 == 10)
	{
		sub_234276b8();
	}
}


/* 23427c68 - complete */
int vienc_configure_hd(void* a)
{
	struct Struct_235f0ccc* r4 = a;

#if 0
	console_send_string("vienc_configure_hd (todo.c): TODO\r\n");
#endif

	FREG(0xcb010000)[0] = 0x11; //VO_DISPRESTART
	FREG(0xcb010000)[0] = 0x111; //VO_DISPRESTART

	VO_SetDispdachdmictrl_Dispdacsel012(0); //DAC012 input select: VE_HD input

	if (r4->params.Data_12 == 3)
	{
		sub_23428b6c(0, 0x12a/*r5*/);
		sub_23428b6c(1, 0x79c);
		sub_23428b6c(2, 0x730);
		sub_23428b6c(3, 0x87);
		sub_23428b6c(4, 0x12a);
		sub_23428b6c(5, 0x204);
		sub_23428b6c(6, 0);
		sub_23428b6c(7, 0x6ec);
		sub_23428b6c(8, 0x12a);
		sub_23428b6c(9, 0);
		sub_23428b6c(10, 0x199);
		sub_23428b6c(11, 0x721);

		sub_234286b4(4);
		sub_234286d4(0x35);
		sub_234286f4(0xf5);
		sub_23428718(4);
		sub_23428738(0x35);
		sub_23428758(0xf5);
		sub_2342877c(4);
		sub_2342879c(0x35);
		sub_234287bc(0xf5);
		VE_SetDacPd_Pddac0(0);
		VE_SetDacPd_Pddac1(0);
		VE_SetDacPd_Pddac2(0);
		VE_HD_SetEnable_ConvEn(1);

		//r0, #0x1
		//->loc_23427ea0
		VE_HD_SetEnable_RgbEn(1);
		//->loc_23427ec8
	}
	//loc_23427d9c
	else if (r4->params.Data_12 == 4)
	{
		sub_23428b6c(0, 0x108);
		sub_23428b6c(1, 0);
		sub_23428b6c(2, 0);
		sub_23428b6c(3, 0xff0);
		sub_23428b6c(4, 0);
		sub_23428b6c(5, 0x100);
		sub_23428b6c(6, 0);
		sub_23428b6c(7, 0);
		sub_23428b6c(8, 0);
		sub_23428b6c(9, 0);
		sub_23428b6c(10, 0x100);
		sub_23428b6c(11, 0);

		sub_234286b4(4);
		sub_234286d4(0x35);
		sub_234286f4(0xf5);
		sub_23428718(3);
		sub_23428738(0x12);
		sub_23428758(0x0c);
		sub_2342877c(3);
		sub_2342879c(0x12);
		sub_234287bc(0x0c);
		VE_SetDacPd_Pddac0(0);
		VE_SetDacPd_Pddac1(0);
		VE_SetDacPd_Pddac2(0);
		VE_HD_SetEnable_ConvEn(0);
		VE_HD_SetEnable_RgbEn(0);
		//->loc_23427ec8
	}
	//loc_23427ea8
	else if (r4->params.Data_12 == 1)
	{
		// Power down DACs
		VE_SetDacPd_Pddac0(1);
		VE_SetDacPd_Pddac1(1);
		VE_SetDacPd_Pddac2(1);
	}
	//loc_23427ec8
	sub_23427c28(r4);

	return 0;
}


/* 23427ed8 - complete */
int vienc_sd_disable(void)
{
#if 0
	console_send_string("vienc_sd_disable (todo.c): TODO\r\n");
#endif

	return 0;
}


/* 23427ee0 /  / 234341c4 - todo */
int vienc_hd_disable(void)
{
#if 0
	console_send_string("vienc_hd_disable (todo.c): TODO\r\n");
#endif

	VE_HD_SetEnable_En(0);

	return 0;
}


/* 23427ef4 /  / 234341d8 - todo */
void vienc_init(void)
{
#if 0
	console_send_string("vienc_init (todo.c): TODO\r\n");
#endif

	memset(&Data_235f0ccc[0], 0, 2 * sizeof(struct Struct_235f0ccc));

	if (vienc_sema == 0)
	{
		vienc_sema = OSSemCreate(1);
	}
}


/* 23427f24 /  / 23434208 - todo */
int vienc_open(Vienc_Params* pParams, void** pHandle)
{
	uint8_t err;
	struct Struct_235f0ccc* h = 0;

#if 0
	console_send_string("vienc_open (todo.c): TODO\r\n");
#endif

	OSSemPend(vienc_sema, 0, &err);

	if (err != 0)
	{
		return err;
	}

	for (uint8_t i = 0; i < 2; i++)
	{
		//loc_23427f58
		if (Data_235f0ccc[i].onEnable == 0)
		{
			h = &Data_235f0ccc[i];
			//->loc_23427f80
			break;
		}
	}
	//loc_23427f80
	if (h != 0)
	{
		//0x23427f88
		h->params = *pParams;

		*pHandle = h;

		if (pParams->sd_hd == 2)
		{
			h->onEnable = vienc_configure_sd;
			//->loc_23427fc4
			h->onDisable = vienc_sd_disable;
		}
		else if (pParams->sd_hd == 3)
		{
			h->onEnable = vienc_configure_hd;
			h->onDisable = vienc_hd_disable;
		}
		//loc_23427fc8
		OSSemPost(vienc_sema);

		return 0;
	}
	else
	{
		//->loc_23427fd8
		OSSemPost(vienc_sema);

		return 0xff;
	}
}


/* 23427fe8 - todo */
int vienc_start(void* a)
{
	uint8_t sp;
	struct Struct_235f0ccc* r4 = a;

#if 0
	console_send_string("vienc_start (todo.c): TODO\r\n");
#endif

	OSSemPend(vienc_sema, 0, &sp);

	if (sp != 0)
	{
		return sp;
	}

	if (r4->onEnable == 0)
	{
		sp = 0xff;
	}
	else
	{
		sp = (r4->onEnable)(r4);
	}

	OSSemPost(vienc_sema);

	return sp;
}


/* 2342803c - complete */
int sub_2342803c(Vienc_Params* r6, void* r1)
{
	struct Struct_235f0ccc* r4 = r1;
	uint8_t err;

#if 0
	console_send_string("sub_2342803c (todo.c): TODO\r\n");
#endif

	OSSemPend(vienc_sema, 0, &err);
	if (err != 0)
	{
		return err;
	}

	r4->params = *r6;

	sub_23427c28(r4);

	OSSemPost(vienc_sema);

	return err;
}


/* 2342808c - complete */
int sub_2342808c(int r4, int b)
{
	uint8_t err;

#if 0
	console_send_string("sub_2342808c (todo.c): TODO\r\n");
#endif

	OSSemPend(vienc_sema, 0, &err);

	if (err != 0)
	{
		return err;
	}

	if (r4 == 6) // FBAS / RGB
	{
		sub_23425a1c();
		//->loc_23428168
	}
	//loc_234280c4
	else if (r4 == 4) // YUV
	{
		VE_SetRgbconf_BlkOn(0);
		VE_SetRgbconf_Ycrcb(1);
		VE_SetLutConf_RgbLutEn(0);
		VE_SetLutConf_LutSel(0);
		VE_SetLutConf_LutEn(0);
		VE_SetRgbconf_SynconGree(1);
		VE_SetDacPd_CeFilterFlag(0);
		VO_SetDispdachdmictrl_Dispdacsel012(0); //DAC012 input select: VE_HD input
		VO_SetDispdachdmictrl_Dispdacsel4(1); //DAC4 input select: SD RGB R signal
		VO_SetDispdachdmictrl_Dispdacsel5(1); //DAC5 input select: SD RGB G signal
		VE_SetDacPd_Pddac3(0);
		VE_SetDacPd_Pddac4(0);
		VE_SetDacPd_Pddac5(0);
		VE_SetDacPd_Pddac6(0);
		VE_SetCeconf_Ipce1sel(0);
		VE_SetRgbconf_Colbar(0);
		sub_23429150(1);

		FREG(0xcb013004)[0] = 0x5f2f; //VE_RGBLum
		FREG(0xcb013008)[0] = 0x5959; //VE_RGBChrom
	}
	//loc_23428168
	OSSemPost(vienc_sema);

	return 0;
}


/* 23428178 / 2343358c - complete */
int sub_23428178(void* h)
{
#if 0
	console_send_string("sub_23428178 (todo.c): TODO\r\n");
#endif

    struct Struct_235f0ccc* r0 = h;

	return r0->params.Data_12 & 0xff;
}


/* 23428184 / 23433598 - complete */
void sub_23428184(int a)
{
#if 0
	console_send_string("sub_23428184 (todo.c): TODO\r\n");
#endif

	/* empty */
}


/* 23428188 / 2343359c / 2343446c - complete */
void VE_SetRgbconf_Colbar(int a)
{
#if 0
	console_send_string("VE_SetRgbconf_Colbar (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 12);

	a = (a << 12) & mask; //COLBAR

	Data_23492418 = (Data_23492418 & ~mask) | a;

	*((volatile uint32_t*)0xcb013000) = Data_23492418; //VE_RGBConf
}


/* 234281b0 /  / 23434494 - complete */
void VE_SetRgbconf_Ycrcb(int a)
{
#if 0
	console_send_string("VE_SetRgbconf_Ycrcb (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 11);

	a = (a << 11) & mask; //YCRCB

	Data_23492418 = (Data_23492418 & ~mask) | a;

	*((volatile uint32_t*)0xcb013000) = Data_23492418; //VE_RGBConf
}


/* 234281d8 /  / 234344bc - complete */
void VE_SetRgbconf_NtscOn(int a)
{
#if 0
	console_send_string("VE_SetRgbconf_NtscOn (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 10);

	a = (a << 10) & mask; //NTSC_ON

	Data_23492418 = (Data_23492418 & ~mask) | a;

	*((volatile uint32_t*)0xcb013000) = Data_23492418; //VE_RGBConf
}


/* 23428200 /  / 234344e4 - complete */
void VE_SetRgbconf_BlkOn(int a)
{
#if 0
	console_send_string("VE_SetRgbconf_BlkOn (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 9);

	a = (a << 9) & mask; //BLK_ON

	Data_23492418 = (Data_23492418 & ~mask) | a;

	*((volatile uint32_t*)0xcb013000) = Data_23492418; //VE_RGBConf
}


/* 23428228 /  / 2343450c - complete */
void VE_SetRgbconf_SynconGree(int a)
{
#if 0
	console_send_string("VE_SetRgbconf_SynconGree (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 7);

	a = (a << 7) & mask; //SYNCON_GREE

	Data_23492418 = (Data_23492418 & ~mask) | a;

	*((volatile uint32_t*)0xcb013000) = Data_23492418; //VE_RGBConf
}


/* 23428250 /  / 23434534 - complete */
void VE_SetCeconf_Secam(int a)
{
#if 0
	console_send_string("VE_SetCeconf_Secam (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 15);

	a = (a << 15) & mask; //SECAM

	Data_2349241c = (Data_2349241c & ~mask) | a;

	*((volatile uint32_t*)0xcb01300c) = Data_2349241c; //VE_CEConf
}


/* 23428278 /  / 2343455c - complete */
void VE_SetCeconf_Ipce1sel(int a)
{
#if 0
	console_send_string("VE_SetCeconf_Ipce1sel (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 13);

	a = (a << 13) & mask; //IPCE1SEL

	Data_2349241c = (Data_2349241c & ~mask) | a;

	*((volatile uint32_t*)0xcb01300c) = Data_2349241c; //VE_CEConf
}


/* 234282a0 /  / 23434584 - complete */
void VE_SetCeconf_Bwgui(int a)
{
#if 0
	console_send_string("VE_SetCeconf_Bwgui (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 12);

	a = (a << 12) & mask; //BWGUI

	Data_2349241c = (Data_2349241c & ~mask) | a;

	*((volatile uint32_t*)0xcb01300c) = Data_2349241c; //VE_CEConf
}


/* 234282c8 /  / 234345ac - complete */
void VE_SetCeconf_Xsyncmx(int a)
{
#if 0
	console_send_string("VE_SetCeconf_Xsyncmx (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 11);

	a = (a << 11) & mask; //XSYNCMX

	Data_2349241c = (Data_2349241c & ~mask) | a;

	*((volatile uint32_t*)0xcb01300c) = Data_2349241c; //VE_CEConf
}


/* 234282f0 /  / 234345d4 - complete */
void VE_SetCeconf_Cydly(int a)
{
#if 0
	console_send_string("VE_SetCeconf_Cydly (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x07 << 8);

	a = (a << 8) & mask; //CYDLY

	Data_2349241c = (Data_2349241c & ~mask) | a;

	*((volatile uint32_t*)0xcb01300c) = Data_2349241c; //VE_CEConf
}


/* 23428318 /  / 234345fc - complete */
void VE_SetCeconf_Cysel(int a)
{
#if 0
	console_send_string("VE_SetCeconf_Cysel (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 7);

	a = (a << 7) & mask; //CYSEL

	Data_2349241c = (Data_2349241c & ~mask) | a;

	*((volatile uint32_t*)0xcb01300c) = Data_2349241c; //VE_CEConf
}


/* 23428340 /  / 23434624 - complete */
void VE_SetCeconf_M3db(int a)
{
#if 0
	console_send_string("VE_SetCeconf_M3db (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x03 << 5);

	a = (a << 5) & mask; //M3DB

	Data_2349241c = (Data_2349241c & ~mask) | a;

	*((volatile uint32_t*)0xcb01300c) = Data_2349241c; //VE_CEConf
}


/* 23428368 /  / 2343464c - complete */
void VE_SetCeconf_Pal525(int a)
{
#if 0
	console_send_string("VE_SetCeconf_Pal525 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 4);

	a = (a << 4) & mask; //PAL525

	Data_2349241c = (Data_2349241c & ~mask) | a;

	*((volatile uint32_t*)0xcb01300c) = Data_2349241c; //VE_CEConf
}


/* 23428390 /  / 23434674 - complete */
void VE_SetCeconf_Pal(int a)
{
#if 0
	console_send_string("VE_SetCeconf_Pal (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 3);

	a = (a << 3) & mask; //PAL

	Data_2349241c = (Data_2349241c & ~mask) | a;

	*((volatile uint32_t*)0xcb01300c) = Data_2349241c; //VE_CEConf
}


/* 234283b8 /  / 2343469c - complete */
void VE_SetCeconf_M1m0(int a)
{
#if 0
	console_send_string("VE_SetCeconf_M1m0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x03 << 1);

	a = (a << 1) & mask; //M1M0

	Data_2349241c = (Data_2349241c & ~mask) | a;

	*((volatile uint32_t*)0xcb01300c) = Data_2349241c; //VE_CEConf
}


/* 234283e0 /  / 234346c4 - complete */
void VE_SetCeconf_Pslev(int a)
{
#if 0
	console_send_string("VE_SetCeconf_Pslev (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 0);

	a = (a << 0) & mask; //PSLEV

	Data_2349241c = (Data_2349241c & ~mask) | a;

	*((volatile uint32_t*)0xcb01300c) = Data_2349241c; //VE_CEConf
}


/* 23428404 /  / 234346e8 - complete */
void VE_SetCeburstint_Pal60mEn(int a)
{
#if 0
	console_send_string("VE_SetCeburstint_Pal60mEn (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 12);

	a = (a << 12) & mask; //PAL_60M_EN

	Data_23492420 = (Data_23492420 & ~mask) | a;

	*((volatile uint32_t*)0xcb013010) = Data_23492420; //VE_CEBurstInt
}


/* 2342842c /  / 23434710 - complete */
void VE_SetCeburstint_Fscint(int a)
{
#if 0
	console_send_string("VE_SetCeburstint_Fscint (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	a = (a << 0) & mask; //FSCINT

	Data_23492420 = (Data_23492420 & ~mask) | a;

	*((volatile uint32_t*)0xcb013010) = Data_23492420; //VE_CEBurstInt
}


/* 23428458 /  / 2343473c - complete */
void VE_SetCeburstfra1_Fscfra(int a)
{
#if 0
	console_send_string("VE_SetCeburstfra1_Fscfra (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xffff << 0);

	a = (a << 0) & mask; //FSCFRA_23_8

	Data_23492424 = (Data_23492424 & ~mask) | a;

	*((volatile uint32_t*)0xcb013014) = Data_23492424; //VE_CEBurstFra1
}


/* 23428480 /  / 23434764 - complete */
void VE_SetCeburstfra2_Fscfra(int a)
{
#if 0
	console_send_string("VE_SetCeburstfra2_Fscfra (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xff << 0);

	a = (a << 0) & mask; //FSCFRA_7_0

	Data_23492428 = (Data_23492428 & ~mask) | a;

	*((volatile uint32_t*)0xcb013018) = Data_23492428; //VE_CEBurstFra2
}


/* 234284a4 /  / 23434788 - complete */
void VE_SetDacPd_CeFilterFlag(int a)
{
#if 0
	console_send_string("VE_SetDacPd_CeFilterFlag (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 15);

	a = (a << 15) & mask; //CE_FILTER_FLAG

	Data_2349242c = (Data_2349242c & ~mask) | a;

	*((volatile uint32_t*)0xcb013020) = Data_2349242c; //VE_DAC_PD
}


/* 234284cc /  / 234347b0 - complete */
void VE_SetDacPd_Pddac6(int a)
{
#if 0
	console_send_string("VE_SetDacPd_Pddac6 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 14);

	a = (a << 14) & mask; //PDDAC6

	Data_2349242c = (Data_2349242c & ~mask) | a;

	*((volatile uint32_t*)0xcb013020) = Data_2349242c; //VE_DAC_PD
}


/* 234284f4 /  / 234347d8 - complete */
void VE_SetDacPd_Pddac5(int a)
{
#if 0
	console_send_string("VE_SetDacPd_Pddac5 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 13);

	a = (a << 13) & mask; //PDDAC5

	Data_2349242c = (Data_2349242c & ~mask) | a;

	*((volatile uint32_t*)0xcb013020) = Data_2349242c; //VE_DAC_PD
}


/* 2342851c /  / 23434800 - complete */
void VE_SetDacPd_Pddac4(int a)
{
#if 0
	console_send_string("VE_SetDacPd_Pddac4 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 12);

	a = (a << 12) & mask; //PDDAC4

	Data_2349242c = (Data_2349242c & ~mask) | a;

	*((volatile uint32_t*)0xcb013020) = Data_2349242c; //VE_DAC_PD
}


/* 23428544 /  / 23434828 - complete */
void VE_SetDacPd_Pddac3(int a)
{
#if 0
	console_send_string("VE_SetDacPd_Pddac3 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 11);

	a = (a << 11) & mask; //PDDAC3

	Data_2349242c = (Data_2349242c & ~mask) | a;

	*((volatile uint32_t*)0xcb013020) = Data_2349242c; //VE_DAC_PD
}


/* 2342856c /  / 23434850 - complete */
void VE_SetDacPd_Pddac2(int a)
{
#if 0
	console_send_string("VE_SetDacPd_Pddac2 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 10);

	a = (a << 10) & mask; //PDDAC2

	Data_2349242c = (Data_2349242c & ~mask) | a;

	*((volatile uint32_t*)0xcb013020) = Data_2349242c; //VE_DAC_PD
}


/* 23428594 /  / 23434878 - complete */
void VE_SetDacPd_Pddac1(int a)
{
#if 0
	console_send_string("VE_SetDacPd_Pddac1 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 9);

	a = (a << 9) & mask; //PDDAC1

	Data_2349242c = (Data_2349242c & ~mask) | a;

	*((volatile uint32_t*)0xcb013020) = Data_2349242c; //VE_DAC_PD
}


/* 234285bc /  / 234348a0 - complete */
void VE_SetDacPd_Pddac0(int a)
{
#if 0
	console_send_string("VE_SetDacPd_Pddac0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 8);

	a = (a << 8) & mask; //PDDAC0

	Data_2349242c = (Data_2349242c & ~mask) | a;

	*((volatile uint32_t*)0xcb013020) = Data_2349242c; //VE_DAC_PD
}


/* 234285e4 /  / 234348c8 - complete */
void VE_SetLutConf_RgbLutEn(int a)
{
#if 0
	console_send_string("VE_SetLutConf_RgbLutEn (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 2);

	a = (a << 2) & mask; //RGB_LUT_EN

	Data_23492430 = (Data_23492430 & ~mask) | a;

	*((volatile uint32_t*)0xcb013200) = Data_23492430; //VE_LUT_CONF
}


/* 2342860c /  / 234348f0 - complete */
void VE_SetLutConf_LutSel(int a)
{
#if 0
	console_send_string("VE_SetLutConf_LutSel (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 1);

	a = (a << 1) & mask; //LUT_SEL

	Data_23492430 = (Data_23492430 & ~mask) | a;

	*((volatile uint32_t*)0xcb013200) = Data_23492430; //VE_LUT_CONF
}


/* 23428634 /  / 23434918 - complete */
void VE_SetLutConf_LutEn(int a)
{
#if 0
	console_send_string("VE_SetLutConf_LutEn (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 0);

	a = (a << 0) & mask; //LUT_EN

	Data_23492430 = (Data_23492430 & ~mask) | a;

	*((volatile uint32_t*)0xcb013200) = Data_23492430; //VE_LUT_CONF
}


/* 23428658 /  / 2343493c - complete */
void VE_HD_SetEnable_ConvEn(int a)
{
#if 0
	console_send_string("VE_HD_SetEnable_ConvEn (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 2);

	a = (a << 2) & mask; //CONV_EN

	FREG(0xcb038000)[0] = (FREG(0xcb038000)[0] & ~mask) | a; //VE_HD_ENABLE
}


/* 23428678 /  / 2343495c - complete */
void VE_HD_SetEnable_RgbEn(int a)
{
#if 0
	console_send_string("VE_HD_SetEnable_RgbEn (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 1);

	a = (a << 1) & mask; //RGB_EN

	FREG(0xcb038000)[0] = (FREG(0xcb038000)[0] & ~mask) | a; //VE_HD_ENABLE
}


/* 23428698 /  / 2343497c - complete */
void VE_HD_SetEnable_En(int a)
{
#if 0
	console_send_string("VE_HD_SetEnable_En (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 0);

	a = (a << 0) & mask; //EN (Videoencoder enable)

	FREG(0xcb038000)[0] = (FREG(0xcb038000)[0] & ~mask) | a; //VE_HD_ENABLE
}


/* 234286b4 - complete */
void sub_234286b4(int a)
{
#if 0
	console_send_string("sub_234286b4 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x07 << 24);

	a = (a << 24) & mask; //RSH

	FREG(0xcb038004)[0] = (FREG(0xcb038004)[0] & ~mask) | a; //VE_HD_YLEVELSHIFT
}


/* 234286d4 - todo */
void sub_234286d4(int a)
{
#if 0
	console_send_string("sub_234286d4 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x7f << 16);

	a = (a << 16) & mask; //MUL

	FREG(0xcb038004)[0] = (FREG(0xcb038004)[0] & ~mask) | a; //VE_HD_YLEVELSHIFT
}


/* 234286f4 - complete */
void sub_234286f4(int a)
{
#if 0
	console_send_string("sub_234286f4 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x1ff << 0);

	a = (a << 0) & mask; //OFS

	FREG(0xcb038004)[0] = (FREG(0xcb038004)[0] & ~mask) | a; //VE_HD_YLEVELSHIFT
}


/* 23428718 - complete */
void sub_23428718(int a)
{
#if 0
	console_send_string("sub_23428718 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x07 << 24);

	a = (a << 24) & mask; //RSH

	FREG(0xcb038008)[0] = (FREG(0xcb038008)[0] & ~mask) | a; //VE_HD_CRLEVELSHIFT
}


/* 23428738 - complete */
void sub_23428738(int a)
{
#if 0
	console_send_string("sub_23428738 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x7f << 16);

	a = (a << 16) & mask; //MUL

	FREG(0xcb038008)[0] = (FREG(0xcb038008)[0] & ~mask) | a; //VE_HD_CRLEVELSHIFT
}


/* 23428758 - complete */
void sub_23428758(int a)
{
#if 0
	console_send_string("sub_23428758 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x1ff << 0);

	a = (a << 0) & mask; //OFS

	FREG(0xcb038008)[0] = (FREG(0xcb038008)[0] & ~mask) | a; //VE_HD_CRLEVELSHIFT
}


/* 2342877c - complete */
void sub_2342877c(int a)
{
#if 0
	console_send_string("sub_2342877c (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x07 << 24);

	a = (a << 24) & mask; //RSH

	FREG(0xcb03800c)[0] = (FREG(0xcb03800c)[0] & ~mask) | a; //VE_HD_CBLEVELSHIFT
}


/* 2342879c - complete */
void sub_2342879c(int a)
{
#if 0
	console_send_string("sub_2342879c (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x7f << 16);

	a = (a << 16) & mask; //MUL

	FREG(0xcb03800c)[0] = (FREG(0xcb03800c)[0] & ~mask) | a; //VE_HD_CBLEVELSHIFT
}


/* 234287bc - complete */
void sub_234287bc(int a)
{
#if 0
	console_send_string("sub_234287bc (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x1ff << 0);

	a = (a << 0) & mask; //OFS

	FREG(0xcb03800c)[0] = (FREG(0xcb03800c)[0] & ~mask) | a; //VE_HD_CBLEVELSHIFT
}


/* 234287e0 - complete */
void sub_234287e0(int a)
{
#if 0
	console_send_string("sub_234287e0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xf << 4);

	a = (a << 4) & mask; //HSYNC

	FREG(0xcb038010)[0] = (FREG(0xcb038010)[0] & ~mask) | a; //VE_HD_VINDEX_CNT
}


/* 23428800 - complete */
void sub_23428800(int a)
{
#if 0
	console_send_string("sub_23428800 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xf << 0);

	a = (a << 0) & mask; //MAX

	FREG(0xcb038010)[0] = (FREG(0xcb038010)[0] & ~mask) | a; //VE_HD_VINDEX_CNT
}


/* 2342881c - complete */
void sub_2342881c(int a)
{
#if 0
	console_send_string("sub_2342881c (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x3ff << 20);

	a = (a << 20) & mask; //LEV2

	FREG(0xcb038014)[0] = (FREG(0xcb038014)[0] & ~mask) | a; //VE_HD_LEVELS
}


/* 23428840 - complete */
void sub_23428840(int a)
{
#if 0
	console_send_string("sub_23428840 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x3ff << 10);

	a = (a << 10) & mask; //LEV1

	FREG(0xcb038014)[0] = (FREG(0xcb038014)[0] & ~mask) | a; //VE_HD_LEVELS
}


/* 23428864 - complete */
void sub_23428864(int a)
{
#if 0
	console_send_string("sub_23428864 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x3ff << 0);

	a = (a << 0) & mask; //LEV0

	FREG(0xcb038014)[0] = (FREG(0xcb038014)[0] & ~mask) | a; //VE_HD_LEVELS
}


/* 23428888 - complete */
void sub_23428888(int a)
{
#if 0
	console_send_string("sub_23428888 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x07 << 0);

	a = (a << 0) & mask; //MODE

	FREG(0xcb038018)[0] = a; //VE_HD_FILTER
}


/* 23428898 - complete */
void sub_23428898(int a)
{
#if 0
	console_send_string("sub_23428898 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x3ff << 20);

	a = (a << 20) & mask; //LEV2

	FREG(0xcb03801c)[0] = (FREG(0xcb03801c)[0] & ~mask) | a; //VE_HD_YLEVELS
}


/* 234288bc - complete */
void sub_234288bc(int a)
{
#if 0
	console_send_string("sub_234288bc (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x3ff << 10);

	a = (a << 10) & mask; //LEV1

	FREG(0xcb03801c)[0] = (FREG(0xcb03801c)[0] & ~mask) | a; //VE_HD_YLEVELS
}


/* 234288e0 - complete */
void sub_234288e0(int a)
{
#if 0
	console_send_string("sub_234288e0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x3ff << 0);

	a = (a << 0) & mask; //LEV0

	FREG(0xcb03801c)[0] = (FREG(0xcb03801c)[0] & ~mask) | a; //VE_HD_YLEVELS
}


/* 23428904 - complete */
void sub_23428904(int a)
{
#if 0
	console_send_string("sub_23428904 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 16);

	a = (a << 16) & mask; //START

	FREG(0xcb0381c0)[0] = (FREG(0xcb0381c0)[0] & ~mask) | a; //VE_HD_VIDEOLINESEL_0
}


/* 23428928 - complete */
void sub_23428928(int a)
{
#if 0
	console_send_string("sub_23428928 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	a = (a << 0) & mask; //END

	FREG(0xcb0381c0)[0] = (FREG(0xcb0381c0)[0] & ~mask) | a; //VE_HD_VIDEOLINESEL_0
}


/* 2342894c - complete */
void sub_2342894c(int a)
{
#if 0
	console_send_string("sub_2342894c (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 16);

	a = (a << 16) & mask; //START

	FREG(0xcb0381c4)[0] = (FREG(0xcb0381c4)[0] & ~mask) | a; //VE_HD_VIDEOLINESEL_1
}


/* 23428970 - complete */
void sub_23428970(int a)
{
#if 0
	console_send_string("sub_23428970 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	a = (a << 0) & mask; //END

	FREG(0xcb0381c4)[0] = (FREG(0xcb0381c4)[0] & ~mask) | a; //VE_HD_VIDEOLINESEL_1
}


/* 23428994 - complete */
void sub_23428994(int a, int b)
{
#if 0
	console_send_string("sub_23428994 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x03 << 12);

	b = (b << 12) & mask; //LEVEL

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 32);

	FREG((uint32_t)r0 + 0x20)[0] = (FREG((uint32_t)r0 + 0x20)[0] & ~mask) | b; //VE_HD_HLEVCNT_0
}


/* 234289b8 - complete */
void sub_234289b8(int a, int b)
{
#if 0
	console_send_string("sub_234289b8 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	b = (b << 0) & mask; //COUNT

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 32);

	FREG((uint32_t)r0 + 0x20)[0] = (FREG((uint32_t)r0 + 0x20)[0] & ~mask) | b; //VE_HD_HLEVCNT_0
}


/* 234289e0 - complete */
void sub_234289e0(int a, int b)
{
#if 0
	console_send_string("sub_234289e0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x03 << 12);

	b = (b << 12) & mask; //LEVEL

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 32);

	FREG((uint32_t)r0 + 0x24)[0] = (FREG((uint32_t)r0 + 0x24)[0] & ~mask) | b; //VE_HD_HLEVCNT_1
}


/* 23428a04 - complete */
void sub_23428a04(int a, int b)
{
#if 0
	console_send_string("sub_23428a04 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	b = (b << 0) & mask; //COUNT

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 32);

	FREG((uint32_t)r0 + 0x24)[0] = (FREG((uint32_t)r0 + 0x24)[0] & ~mask) | b; //VE_HD_HLEVCNT_1
}


/* 23428a2c - todo */
void sub_23428a2c(int a, int b)
{
#if 0
	console_send_string("sub_23428a2c (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x03 << 12);

	b = (b << 12) & mask; //LEVEL

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 32);

	FREG((uint32_t)r0 + 0x28)[0] = (FREG((uint32_t)r0 + 0x28)[0] & ~mask) | b; //VE_HD_HLEVCNT_2
}


/* 23428a88 - todo */
void sub_23428a88(int a, int b)
{
#if 0
	console_send_string("sub_23428a88 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	b = (b << 0) & mask; //COUNT

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 32);

	FREG((uint32_t)r0 + 0x28)[0] = (FREG((uint32_t)r0 + 0x28)[0] & ~mask) | b; //VE_HD_HLEVCNT_2
}


/* 23428ab0 - todo */
void sub_23428ab0(int a, int b)
{
#if 0
	console_send_string("sub_23428ab0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x03 << 12);

	b = (b << 12) & mask; //LEVEL

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 32);

	FREG((uint32_t)r0 + 0x2c)[0] = (FREG((uint32_t)r0 + 0x2c)[0] & ~mask) | b; //VE_HD_HLEVCNT_3
}


/* 23428ad4 - todo */
void sub_23428ad4(int a, int b)
{
#if 0
	console_send_string("sub_23428ad4 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	b = (b << 0) & mask; //COUNT

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 32);

	FREG((uint32_t)r0 + 0x2c)[0] = (FREG((uint32_t)r0 + 0x2c)[0] & ~mask) | b; //VE_HD_HLEVCNT_3
}


/* 23428afc - complete */
void sub_23428afc(int a, int b)
{
#if 0
	console_send_string("sub_23428afc (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x03 << 12);

	b = (b << 12) & mask; //LEVEL

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 32);

	FREG((uint32_t)r0 + 0x30)[0] = (FREG((uint32_t)r0 + 0x30)[0] & ~mask) | b; //VE_HD_HLEVCNT_4
}


/* 23428b20 - complete */
void sub_23428b20(int a, int b)
{
#if 0
	console_send_string("sub_23428b20 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	b = (b << 0) & mask; //COUNT

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 32);

	FREG((uint32_t)r0 + 0x30)[0] = (FREG((uint32_t)r0 + 0x30)[0] & ~mask) | b; //VE_HD_HLEVCNT_4
}


/* 23428b48 - complete */
void sub_23428b48(int a, int b)
{
#if 0
	console_send_string("sub_23428b48 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x07 << 0);

	b = (b << 0) & mask; //MAX

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 32);

	FREG((uint32_t)r0 + 0x34)[0] = b; //VE_HD_HINDEX_CNT
}


/* 23428b5c - complete */
void sub_23428b5c(int a, int b)
{
#if 0
	console_send_string("sub_23428b5c (todo.c): TODO\r\n");
#endif

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 32);

	FREG((uint32_t)r0 + 0x38)[0] = b; //VE_HD_VCNT
}


/* 23428b6c - complete */
void sub_23428b6c(int a, int b)
{
#if 0
	console_send_string("sub_23428b6c (todo.c): TODO\r\n");
#endif

	b = b & 0x7ff; //DATA

	volatile uint32_t* r0 = FREG(0xcb038000 + a * 4);

	FREG((uint32_t)r0 + 0x180)[0] = b; //VE_HD_YUVRGB
}


/* 23428b84 / 23433f98 - complete */
void VO_SetDisphorll_Disphorll(int a)
{
#if 0
	console_send_string("VO_SetDisphorll_Disphorll (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	a = (a << 0) & mask; //DISPHORLL

	FREG(0xcb010004)[0] = (FREG(0xcb010004)[0] & ~mask) | a; //VO_DISPHORLL
}


/* 23428ba8 - complete */
void VO_SetDispversize_Dispversize(int a)
{
#if 0
	console_send_string("VO_SetDispversize_Dispversize (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x7ff << 0);

	a = (a << 0) & mask; //DISPVERSIZE

	FREG(0xcb010008)[0] = (FREG(0xcb010008)[0] & ~mask) | a; //VO_DISPVERSIZE
}


/* 23428bcc - complete */
int VO_GetDispversize_Dispversize()
{
#if 0
	console_send_string("VO_GetDispversize_Dispversize (todo.c): TODO\r\n");
#endif

	int r0 = FREG(0xcb010008)[0];

	return r0 & 0x7ff; //DISPVERSIZE
}


/* 23428be0 - complete */
void sub_23428be0(int a)
{
#if 0
	console_send_string("sub_23428be0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 4);

	a = (a << 4) & mask; //VERCOUNT0

	FREG(0xcb01000c)[0] = (FREG(0xcb01000c)[0] & ~mask) | a; //VO_DISPVERCFG
}


/* 23428c00 - complete */
void sub_23428c00(int a)
{
#if 0
	console_send_string("sub_23428c00 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x07 << 0);

	a = (a << 0) & mask; //SECONDFIELDOFFSET

	FREG(0xcb01000c)[0] = (FREG(0xcb01000c)[0] & ~mask) | a; //VO_DISPVERCFG
}


/* 23428c1c - complete */
void sub_23428c1c(int a)
{
#if 0
	console_send_string("sub_23428c1c (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x7ff << 0);

	a = (a << 0) & mask; //DISPVOVERSYNC

	FREG(0xcb010010)[0] = (FREG(0xcb010010)[0] & ~mask) | a; //VO_DISPVOVERSYNC
}


/* 23428c40 - complete */
void VO_SetDisphdmidehorstartstop_Dehorstart(int a)
{
#if 0
	console_send_string("VO_SetDisphdmidehorstartstop_Dehorstart (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 16);

	a = (a << 16) & mask; //DEHORSTART

	FREG(0xcb010034)[0] = (FREG(0xcb010034)[0] & ~mask) | a; //VO_DISPHDMIDEHORSTARTSTOP
}


/* 23428c64 - complete */
void VO_SetDisphdmidehorstartstop_Dehorstop(int a)
{
#if 0
	console_send_string("VO_SetDisphdmidehorstartstop_Dehorstop (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	a = (a << 0) & mask; //DEHORSTOP

	FREG(0xcb010034)[0] = (FREG(0xcb010034)[0] & ~mask) | a; //VO_DISPHDMIDEHORSTARTSTOP
}


/* 23428c88 - complete */
void VO_SetDisphdmideverstartstop_Deverstart(int a)
{
#if 0
	console_send_string("VO_SetDisphdmideverstartstop_Deverstart (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x7ff << 16);

	a = (a << 16) & mask; //DEVERSTART

	FREG(0xcb010038)[0] = (FREG(0xcb010038)[0] & ~mask) | a; //VO_DISPHDMIDEVERSTARTSTOP
}


/* 23428cac - complete */
void VO_SetDisphdmideverstartstop_Deverstop(int a)
{
#if 0
	console_send_string("VO_SetDisphdmideverstartstop_Deverstop (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x7ff << 0);

	a = (a << 0) & mask; //DEVERSTOP

	FREG(0xcb010038)[0] = (FREG(0xcb010038)[0] & ~mask) | a; //VO_DISPHDMIDEVERSTARTSTOP
}


/* 23428cd0 - complete */
void sub_23428cd0(int a)
{
#if 0
	console_send_string("sub_23428cd0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 16);

	a = (a << 16) & mask; //DISPSYNCHORSTART

	FREG(0xcb01004c)[0] = (FREG(0xcb01004c)[0] & ~mask) | a; //VO_DISPSYNCHORSTARTSTOP
}


/* 23428cf4 - complete */
void sub_23428cf4(int a)
{
#if 0
	console_send_string("sub_23428cf4 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	a = (a << 0) & mask; //DISPSYNCHORSTOP

	FREG(0xcb01004c)[0] = (FREG(0xcb01004c)[0] & ~mask) | a; //VO_DISPSYNCHORSTARTSTOP
}


/* 23428d18 - complete */
void sub_23428d18(int a)
{
#if 0
	console_send_string("sub_23428d18 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 16);

	a = (a << 16) & mask; //DISPSYNCHOR1START

	FREG(0xcb010050)[0] = (FREG(0xcb010050)[0] & ~mask) | a; //VO_DISPSYNCHOR1STARTSTOP
}


/* 23428d3c - complete */
void sub_23428d3c(int a)
{
#if 0
	console_send_string("sub_23428d3c (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	a = (a << 0) & mask; //DISPSYNCHOR1STOP

	FREG(0xcb010050)[0] = (FREG(0xcb010050)[0] & ~mask) | a; //VO_DISPSYNCHOR1STARTSTOP
}


/* 23428d60 - complete */
void sub_23428d60(int a)
{
#if 0
	console_send_string("sub_23428d60 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 16);

	a = (a << 16) & mask; //DISPSYNCVER1START

	FREG(0xcb010054)[0] = (FREG(0xcb010054)[0] & ~mask) | a; //VO_DISPSYNCVER1STARTSTOP
}


/* 23428d84 - complete */
void sub_23428d84(int a)
{
#if 0
	console_send_string("sub_23428d84 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	a = (a << 0) & mask; //DISPSYNCVER1STOP

	FREG(0xcb010054)[0] = (FREG(0xcb010054)[0] & ~mask) | a; //VO_DISPSYNCVER1STARTSTOP
}


/* 23428da8 - complete */
void sub_23428da8(int a)
{
#if 0
	console_send_string("sub_23428da8 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 16);

	a = (a << 16) & mask; //DISPSYNCHOR2START

	FREG(0xcb010058)[0] = (FREG(0xcb010058)[0] & ~mask) | a; //VO_DISPSYNCHOR2STARTSTOP
}


/* 23428dcc - complete */
void sub_23428dcc(int a)
{
#if 0
	console_send_string("sub_23428dcc (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	a = (a << 0) & mask; //DISPSYNCHOR2STOP

	FREG(0xcb010058)[0] = (FREG(0xcb010058)[0] & ~mask) | a; //VO_DISPSYNCHOR2STARTSTOP
}


/* 23428df0 - complete */
void sub_23428df0(int a)
{
#if 0
	console_send_string("sub_23428df0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 16);

	a = (a << 16) & mask; //DISPSYNCVER2START

	FREG(0xcb01005c)[0] = (FREG(0xcb01005c)[0] & ~mask) | a; //VO_DISPSYNCVER2STARTSTOP
}


/* 23428e14 - complete */
void sub_23428e14(int a)
{
#if 0
	console_send_string("sub_23428e14 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	a = (a << 0) & mask; //DISPSYNCVER2STOP

	FREG(0xcb01005c)[0] = (FREG(0xcb01005c)[0] & ~mask) | a; //VO_DISPSYNCVER2STARTSTOP
}


/* 23428e38 - complete */
void sub_23428e38(int a)
{
#if 0
	console_send_string("sub_23428e38 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 28);

	a = (a << 28) & mask; //VEHDFIELDSYNC

	FREG(0xcb010060)[0] = (FREG(0xcb010060)[0] & ~mask) | a; //VO_DISPVEHDSYNC
}


/* 23428e58 - complete */
void sub_23428e58(int a)
{
#if 0
	console_send_string("sub_23428e58 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 16);

	a = (a << 16) & mask; //VEHDHPOS

	FREG(0xcb010060)[0] = (FREG(0xcb010060)[0] & ~mask) | a; //VO_DISPVEHDSYNC
}


/* 23428e7c - complete */
void sub_23428e7c(int a)
{
#if 0
	console_send_string("sub_23428e7c (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x7ff << 0);

	a = (a << 0) & mask; //VEHDVPOS

	FREG(0xcb010060)[0] = (FREG(0xcb010060)[0] & ~mask) | a; //VO_DISPVEHDSYNC
}


/* 23428ea0 /  / 23435184 - complete */
void VO_SetDispirq0_Dispirq0enable(int a)
{
#if 0
	console_send_string("VO_SetDispirq0_Dispirq0enable (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 13);

	a = (a << 13) & mask; //DISPIRQ0ENABLE

	FREG(0xcb010070)[0] = (FREG(0xcb010070)[0] & ~mask) | a; //VO_DISPIRQ0
}


/* 23428ec0 /  / 234351a4 - complete */
void VO_SetDispirq0_Dispfiedframeirq0(int a)
{
#if 0
	console_send_string("VO_SetDispirq0_Dispfiedframeirq0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 12);

	a = (a << 12) & mask; //DISPFIEDFRAMEIRQ0

	FREG(0xcb010070)[0] = (FREG(0xcb010070)[0] & ~mask) | a; //VO_DISPIRQ0
}


/* 23428ee0 /  / 234351c4 - complete */
void VO_SetDispirq0_Dispfiedirq0sel(int a)
{
#if 0
	console_send_string("VO_SetDispirq0_Dispfiedirq0sel (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 11);

	a = (a << 11) & mask; //DISPFIEDIRQ0SEL

	FREG(0xcb010070)[0] = (FREG(0xcb010070)[0] & ~mask) | a; //VO_DISPIRQ0
}


/* 23428f00 /  / 234351e4 - complete */
void VO_SetDispirq0_Dispverposirq0(int a)
{
#if 0
	console_send_string("VO_SetDispirq0_Dispverposirq0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x7ff << 0);

	a = (a << 0) & mask; //DISPVERPOSIRQ0

	FREG(0xcb010070)[0] = (FREG(0xcb010070)[0] & ~mask) | a; //VO_DISPIRQ0
}


/* 23428f24 - complete */
void sub_23428f24(int a)
{
#if 0
	console_send_string("sub_23428f24 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 13);

	a = (a << 13) & mask; //DISPIRQ1ENABLE

	FREG(0xcb010074)[0] = (FREG(0xcb010074)[0] & ~mask) | a; //VO_DISPIRQ1
}


/* 23428f44 - complete */
void sub_23428f44(int a)
{
#if 0
	console_send_string("sub_23428f44 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 12);

	a = (a << 12) & mask; //DISPFIEDFRAMEIRQ1

	FREG(0xcb010074)[0] = (FREG(0xcb010074)[0] & ~mask) | a; //VO_DISPIRQ1
}


/* 23428f64 - complete */
void sub_23428f64(int a)
{
#if 0
	console_send_string("sub_23428f64 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 11);

	a = (a << 11) & mask; //DISPFIEDIRQ1SEL

	FREG(0xcb010074)[0] = (FREG(0xcb010074)[0] & ~mask) | a; //VO_DISPIRQ1
}


/* 23428f84 - complete */
void sub_23428f84(int a)
{
#if 0
	console_send_string("sub_23428f84 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x7ff << 0);

	a = (a << 0) & mask; //DISPVERPOSIRQ1

	FREG(0xcb010074)[0] = (FREG(0xcb010074)[0] & ~mask) | a; //VO_DISPIRQ1
}


/* 23428fa8 /  / 2343528c - complete */
void VO_SetDispdachdmictrl_Dispdacsel5(int a)
{
#if 0
	console_send_string("VO_SetDispdachdmictrl_Dispdacsel5 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 19);

	a = (a << 19) & mask; //DISPDACSEL5

	FREG(0xcb010084)[0] = (FREG(0xcb010084)[0] & ~mask) | a; //VO_DISPDACHDMICTRL
}


/* 23428fc8 /  / 234352ac - complete */
void VO_SetDispdachdmictrl_Dispdacsel4(int a)
{
#if 0
	console_send_string("VO_SetDispdachdmictrl_Dispdacsel4 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 18);

	a = (a << 18) & mask; //DISPDACSEL4

	FREG(0xcb010084)[0] = (FREG(0xcb010084)[0] & ~mask) | a; //VO_DISPDACHDMICTRL
}


/* 23428fe8 /  / 234352cc - complete */
void VO_SetDispdachdmictrl_Dispdacsel012(int a)
{
#if 0
	console_send_string("VO_SetDispdachdmictrl_Dispdacsel012 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x03 << 16);

	a = (a << 16) & mask; //DISPDACSEL012

	FREG(0xcb010084)[0] = (FREG(0xcb010084)[0] & ~mask) | a; //VO_DISPDACHDMICTRL
}


/* 23429008 - complete */
void sub_23429008(int a)
{
#if 0
	console_send_string("sub_23429008 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 16);

	a = (a << 16) & mask; //VOFIELDMODE

	FREG(0xcb000044)[0] = (FREG(0xcb000044)[0] & ~mask) | a; //VO_VOMODE
}


/* 23429028 - complete */
void sub_23429028(int a)
{
#if 0
	console_send_string("sub_23429028 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 15);

	a = (a << 15) & mask; //VOPROGR

	FREG(0xcb000044)[0] = (FREG(0xcb000044)[0] & ~mask) | a; //VO_VOMODE
}


/* 23429048 - todo */
void sub_23429048(int a)
{
#if 0
	console_send_string("sub_23429048 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x1fff << 0);

	a = (a << 0) & mask; //HOR_LL

	Data_23492438 = (Data_23492438 & ~mask) | a;

	*((volatile uint32_t*)0xcb011000) = Data_23492438; //VO_SD_HorLineLength
}


/* 23429074 - todo */
void sub_23429074(int a)
{
#if 0
	console_send_string("sub_23429074 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x3ff << 0);

	a = (a << 0) & mask; //VER_SIZE

	Data_2349243c = (Data_2349243c & ~mask) | a;

	*((volatile uint32_t*)0xcb011004) = Data_2349243c; //VO_SD_VerSize
}


/* 234290a0 - todo */
void sub_234290a0(int a)
{
#if 0
	console_send_string("sub_234290a0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x1fff << 0);

	a = (a << 0) & mask; //VO_HOR_START

	Data_23492440 = (Data_23492440 & ~mask) | a;

	*((volatile uint32_t*)0xcb011040) = Data_23492440; //VO_SD_VOHorStart
}


/* 234290cc - todo */
void sub_234290cc(int a)
{
#if 0
	console_send_string("sub_234290cc (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x1fff << 0);

	a = (a << 0) & mask; //VO_HOR_STOP

	Data_23492444 = (Data_23492444 & ~mask) | a;

	*((volatile uint32_t*)0xcb011044) = Data_23492444; //VO_SD_VOHorStop
}


/* 234290f8 - todo */
void sub_234290f8(int a)
{
#if 0
	console_send_string("sub_234290f8 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x3ff << 0);

	a = (a << 0) & mask; //VO_VER_START

	Data_23492448 = (Data_23492448 & ~mask) | a;

	*((volatile uint32_t*)0xcb011048) = Data_23492448; //VO_SD_VOVerStart
}


/* 23429124 - todo */
void sub_23429124(int a)
{
#if 0
	console_send_string("sub_23429124 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x3ff << 0);

	a = (a << 0) & mask; //VO_VER_STOP

	Data_2349244c = (Data_2349244c & ~mask) | a;

	*((volatile uint32_t*)0xcb01104c) = Data_2349244c; //VO_SD_VOVerStop
}


/* 23429150 - todo */
void sub_23429150(int a)
{
#if 0
	console_send_string("sub_23429150 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 5);

	a = (a << 5) & mask; //SD_SYNC_ENABLE

	Data_23492450 = (Data_23492450 & ~mask) | a;

	*((volatile uint32_t*)0xcb011140) = Data_23492450; //VO_SDHVSYNCCFG
}


/* 23429178 - todo */
void sub_23429178(int a)
{
#if 0
	console_send_string("sub_23429178 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 10);

	a = (a << 10) & mask; //field

	Data_23492454 = (Data_23492454 & ~mask) | a;

	*((volatile uint32_t*)0xcb01114c) = Data_23492454; //VO_SDVSYNCOFFSET
}


/* 234291a0 - todo */
void sub_234291a0(int a)
{
#if 0
	console_send_string("sub_234291a0 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x3ff << 0);

	a = (a << 0) & mask; //SDVSYNCOFFSET

	Data_23492454 = (Data_23492454 & ~mask) | a;

	*((volatile uint32_t*)0xcb01114c) = Data_23492454; //VO_SDVSYNCOFFSET
}


/* 234291cc - todo */
void sub_234291cc(int a)
{
#if 0
	console_send_string("sub_234291cc (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x1fff << 0);

	a = (a << 0) & mask; //SDHSYNCOFFSET

	Data_23492434 = (Data_23492434 & ~mask) | a;

	*((volatile uint32_t*)0xcb011144) = Data_23492434; //VO_SDHSYNCOFFSET
}


/* 234291f8 - complete */
void sub_234291f8(int a)
{
#if 0
	console_send_string("sub_234291f8 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (1 << 12);

	a = (a << 12) & mask; //DISPHORLL1FIELD

	FREG(0xcb0100a8)[0] = (FREG(0xcb0100a8)[0] & ~mask) | a; //VO_DISPHORLL1
}


/* 23429218 - complete */
void VO_SetDisphorll1_Disphorll1(int a)
{
#if 0
	console_send_string("VO_SetDisphorll1_Disphorll1 (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0xfff << 0);

	a = (a << 0) & mask; //DISPHORLL1

	FREG(0xcb0100a8)[0] = (FREG(0xcb0100a8)[0] & ~mask) | a; //VO_DISPHORLL1
}


/* 2342923c - complete */
void sub_2342923c(int a)
{
#if 0
	console_send_string("sub_2342923c (todo.c): TODO\r\n");
#endif

	uint32_t mask = (0x1f << 8);

	a = (a << 8) & mask; //HDMIDIVIDER

	FREG(0xca000040)[0] = (FREG(0xca000040)[0] & ~mask) | a; //FDCLKSEL
}


/* 2342925c - complete */
void sub_2342925c(void)
{
#if 0
	console_send_string("sub_2342925c (todo.c): TODO\r\n");
#endif

	VE_SetRgbconf_NtscOn(0);
	VE_SetCeconf_Secam(0);
	VE_SetCeconf_Ipce1sel(0);
	VE_SetCeconf_Bwgui(0);
	VE_SetCeconf_Xsyncmx(0);
	VE_SetCeconf_Cydly(0);
	VE_SetCeconf_Cysel(0);
	VE_SetCeconf_M3db(0);
	VE_SetCeconf_Pal525(0);
	VE_SetCeconf_Pal(0);
	VE_SetCeconf_M1m0(0);
	VE_SetCeconf_Pslev(0);
	VE_SetCeburstint_Pal60mEn(0);
	VE_SetCeburstint_Fscint(0);
	VE_SetCeburstfra1_Fscfra(0);
	VE_SetCeburstfra2_Fscfra(0);
	sub_23429048(0);
	sub_23429074(0);
	sub_234290a0(0);
	sub_234290cc(0);
	sub_234290f8(0);
	sub_23429124(0);

	FREG(0xcb010048)[0] = 0; //VO_DISPCVBSVERSYNC

	sub_234291cc(0);
	sub_234291a0(0);
	sub_23429178(0);
	sub_23429150(0);
	sub_23429430(0);
	sub_23429430(1);
}


/* 2342934c - complete */
void sub_2342934c()
{
#if 0
	console_send_string("sub_2342934c (todo.c): TODO\r\n");
#endif

	VE_SetRgbconf_NtscOn(0);
	VE_SetCeconf_Secam(0);
	VE_SetCeconf_Ipce1sel(0);
	VE_SetCeconf_Bwgui(0);
	VE_SetCeconf_Xsyncmx(0);
	VE_SetCeconf_Cydly(4);
	VE_SetCeconf_Cysel(0);
	VE_SetCeconf_M3db(0);
	VE_SetCeconf_Pal525(0);
	VE_SetCeconf_Pal(1);
	VE_SetCeconf_M1m0(0);
	VE_SetCeconf_Pslev(1);
	VE_SetCeburstint_Pal60mEn(0);
	VE_SetCeburstint_Fscint(0x541);
	VE_SetCeburstfra1_Fscfra(0x3159);
	VE_SetCeburstfra2_Fscfra(0x68);
	sub_23429048(0xd80);
	sub_23429074(0x138);
	sub_234290a0(0x210);
	sub_234290cc(0xd50);
	sub_234290f8(0x17);
	sub_23429124(0x137);

	FREG(0xcb010048)[0] = 0x100005; //VO_DISPCVBSVERSYNC

	sub_234291cc(0x34);
	sub_234291a0(0x136);
	sub_23429178(1);
	sub_23429150(1);
}


