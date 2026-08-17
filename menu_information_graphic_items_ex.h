

static Graphic_Job_2_5_Item menu_information_graphic_items_ex[] = //234C9720
{
	{0}, //[0] = 234C9720 
	{0}, //[1] = 234c9760 
	{0}, //[2] = 234C97A0 
	{0}, //[3] = 234C97E0 
	{1, 0, 0, 0, 0x3d, 0x60, 0xf8, 0x20, 0, 
	&Data_234c12d4/*Data_0x18*/, 
	0/*transparent?*/, 0, 
	&menu_information_graphic_item_text_item0/*Data_0x20*/}, //[4] = 234C9820: Text Item 0 (Frequency?)
#if 0
0x234c9820                        db         0x01
0x234c9821                        db  0x00 ; '.'
0x234c9822 0000                   movs       r0, r0
0x234c9824                        dd         0x00000000
0x234c9828                        dd         0x00000000
0x234c982c                        dw         0x003d
0x234c982e                        dw         0x0060
0x234c9830                        dw         0x00f8
0x234c9832                        dw         0x0020
0x234c9834                        dd         0x00000000
0x234c9838                        dd         0x234c12d4
0x234c983c                        dd         0x00000000
0x234c9840                        dd         0x234c86b4
#endif
	{0}, //[5] = 234C9860 
	{0}, //[6] = 234C98A0 
	{0}, //[7] = 234C98E0 
	{0}, //[8] = 234C9920 
	{0}, //[9] = 234C9960 
	{0}, //[10] = 234C99A0 
	{0}, //[11] = 234C99E0 
	{0}, //[12] = 234C9A20 
	{0}, //[13] = 234C9A60 
	{0}, //[14] = 234C9AA0 
	{0}, //[15] = 234C9AE0 
	{0}, //[16] = 234C9B20 
	{0}, //[17] = 234C9B60 
	{0}, //[18] = 234C9BA0 
	{0}, //[19] = 234C9BE0 
	{0}, //[20] = 234C9C20 
	{0}, //[21] = 234C9C60 
	{0}, //[22] = 234C9CA0 
	{0}, //[23] = 234C9CE0 
	{0}, //[24] = 234C9D20 
	{0}, //[25] = 234C9D60 
	{0}, //[26] = 234C9DA0 
	{0}, //[27] = 234C9DE0 
	{0}, //[28] = 234C9E20 
	{0}, //[29] = 234C9E60 
	{0}, //[30] = 234C9EA0 
	{0}, //[31] = 234C9EE0 
	{0}, //[32] = 234C9F20 
	{0}, //[33] = 234C9F60 
	{0}, //[34] = 234C9FA0 
	{1, 0, 0, 0, 0x14b, 0x60, 0x10c, 0x20, 0, 
	&Data_234c12d4/*Data_0x18*/, 
	0, 0, &menu_information_graphic_text_item_program/*Data_0x20*/}, //[35] = 234C9FE0 
#if 0
0x234c9fe0                        db         0x01
0x234c9fe1                        db  0x00 ; '.'
0x234c9fe2 0000                   movs       r0, r0
0x234c9fe4                        dd         0x00000000
0x234c9fe8                        dd         0x00000000
0x234c9fec                        dw         0x014b
0x234c9fee                        dw         0x0060
0x234c9ff0                        dw         0x010c
0x234c9ff2                        dw         0x0020
0x234c9ff4                        dd         0x00000000
0x234c9ff8                        dd         0x234c12d4
0x234c9ffc                        dd         0x00000000
0x234ca000                        dd         0x234c8804
#endif
	{0}, //[36] = 234CA020 
	{0}, //[37] = 234CA060 
	{0}, //[38] = 234CA0A0 
	{0, 0, 0, 0, 0x3d, 0xd1, 0xf8, 0x20, 0, 
	&Data_234c12d4/*Data_0x18*/, 
	0, 0, &menu_information_graphic_item_text_video_pid/*Data_0x20*/}, //[39] = 234CA0E0: "Video Pid"
#if 0
0x234ca0e0                        db         0x00
0x234ca0e1                        db  0x00 ; '.'
0x234ca0e2 0000                   movs       r0, r0
0x234ca0e4                        dd         0x00000000
0x234ca0e8                        dd         0x00000000
0x234ca0ec                        dw         0x003d
0x234ca0ee                        dw         0x00d1
0x234ca0f0                        dw         0x00f8
0x234ca0f2                        dw         0x0020
0x234ca0f4                        dd         0x00000000
0x234ca0f8                        dd         0x234c12d4
0x234ca0fc                        dd         0x00000000
0x234ca100                        dd         0x234c8860
#endif
	{0}, //[40] = 234CA120 
	{0}, //[41] = 234CA160 
	{0}, //[42] = 234CA1A0 
	{0}, //[43] = 234CA1E0 
	{0}, //[44] = 234CA220 
	{0}, //[45] = 234CA260 
	{0}, //[46] = 234CA2A0 
	{0}, //[47] = 234CA2E0 
	{0}, //[48] = 234CA320 
	{0}, //[49] = 234CA360 
	{0}, //[50] = 234CA3A0 
#if 0
0x234ca3a0                        db         0x00
0x234ca3a1                        db  0x00 ; '.'
0x234ca3a2 0000                   movs       r0, r0
0x234ca3a4                        dd         0x00000000
0x234ca3a8                        dd         0x00000000
0x234ca3ac                        dw         0x003d
0x234ca3ae                        dw         0x0131
0x234ca3b0                        dw         0x00f8
0x234ca3b2                        dw         0x0020
0x234ca3b4 0000                   movs       r0, r0
0x234ca3b6 0000                   movs       r0, r0
0x234ca3b8                        dd         0x234c12d4
0x234ca3bc 0000                   movs       r0, r0
0x234ca3be 0000                   movs       r0, r0
0x234ca3c0                        dd         0x234c89c8
#endif
	{1, 0, 0, 0, 0x3d, 0x29, 0xf8, 0x26, 0, &Data_234c134c/*Data_0x18*/, 
	0, 0, &menu_information_graphic_item_text_header/*Data_0x20*/}, //[51] = 234CA3E0: header
#if 0
0x234ca3e0                        db         0x01                               ; DATA XREF=0x234ca51c
0x234ca3e1                        db  0x00 ; '.'
0x234ca3e2 0000                   movs       r0, r0
0x234ca3e4                        dd         0x00000000
0x234ca3e8                        dd         0x00000000
0x234ca3ec                        dw         0x003d
0x234ca3ee                        dw         0x0029
0x234ca3f0                        dw         0x00f8
0x234ca3f2                        dw         0x0026
0x234ca3f4 0000                   movs       r0, r0
0x234ca3f6 0000                   movs       r0, r0
0x234ca3f8                        dd         0x234c134c
0x234ca3fc 0000                   movs       r0, r0
0x234ca3fe 0000                   movs       r0, r0
0x234ca400                        dd         0x234c869c
#endif
	{0}, //[52] = 234CA420 
	//->234CA460
};

