

static Graphic_Job_2_5_Item menu_information_graphic_items[] = //234c89e0
{
	{0}, //[0] = 234c89e0 
	{1, 0, 0, 0, 0x3d, 0x1c3, 0x21a, 0x3a, 0, 
	&Data_234c134c/*Data_0x18*/, 
	3, 0, &Data_234c86cc/*Data_0x20*/}, //[1] = 234C8A20: ???
#if 0
0x234c8a20                        db         0x01                               ; DATA XREF=0x234ca4e4
0x234c8a21                        db         0x00
0x234c8a22                        db  0x00 ; '.'
0x234c8a23                        db  0x00 ; '.'
0x234c8a24                        dd         0x00000000
0x234c8a28                        dd         0x00000000
0x234c8a2c                        dw         0x003d
0x234c8a2e                        dw         0x01c3
0x234c8a30                        dw         0x021a
0x234c8a32                        dw         0x003a
0x234c8a34                        dd         0x00000000
0x234c8a38                        dd         0x234c134c
0x234c8a3c                        db         0x03
0x234c8a3d                        db         0x00
0x234c8a3e 0000                   movs       r0, r0
0x234c8a40                        dd         0x234c86cc
#endif
	{1, 0, 0, 0, 0x37, 0x5a, 0x104, 0x6c, 0, 
	&menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
	2}, //[2] = 234C8A60: Item 1 Top Border ???
#if 0
0x234c8a60                        db         0x01
0x234c8a61                        db  0x00 ; '.'
0x234c8a62 0000                   movs       r0, r0
0x234c8a64                        dd         0x00000000
0x234c8a68                        dd         0x00000000
0x234c8a6c                        dw         0x0037
0x234c8a6e                        dw         0x005a
0x234c8a70                        dw         0x0104
0x234c8a72                        dw         0x006c
0x234c8a74                        dd         0x00000000
0x234c8a78                        dd         0x234c128c
0x234c8a7c                        db         0x02
#endif
	{1, 0, 0, 0, 0x37, 0x23, 0x104, 0x32, 0, 
	&menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
	2}, //[3] = 234C8AA0: Header Item Top Border???
#if 0
0x234c8aa0                        db         0x01
0x234c8aa1                        db         0x00
0x234c8aa2 0000                   movs       r0, r0
0x234c8aa4                        dd         0x00000000
0x234c8aa8                        dd         0x00000000
0x234c8aac                        dw         0x0037
0x234c8aae                        dw         0x0023
0x234c8ab0                        dw         0x0104
0x234c8ab2                        dw         0x0032
0x234c8ab4                        dd         0x00000000
0x234c8ab8                        dd         0x234c128c
0x234c8abc                        db         0x02
#endif
	{1, 0, 0, 0, 0x3d, 0x60, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_top_round_left_right/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_item0/*Data_0x20*/}, //[4] = 234C8AE0: Text Item 0 (Frequency?)
#if 0
0x234c8ae0                        db         0x01                               ; DATA XREF=sub_234552f8+22
0x234c8ae1                        db         0x00
0x234c8ae2 0000                   movs       r0, r0
0x234c8ae4                        dd         0x00000000
0x234c8ae8                        dd         0x00000000
0x234c8aec                        dw         0x003d
0x234c8aee                        dw         0x0060
0x234c8af0                        dw         0x00f8
0x234c8af2                        dw         0x0020
0x234c8af4                        dd         0x00000000
0x234c8af8                        dd         0x234c12f8
0x234c8afc                        db         0x09
0x234c8afd                        db  0x00 ; '.'
0x234c8afe 0000                   movs       r0, r0
0x234c8b00                        dd         0x234c86b4                   ; DATA XREF=sub_234552f8+34
#endif
	{1, 0, 0, 0, 0x3d, 0x80, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_item1/*Data_0x20*/}, //[5] = 234C8B20: Text Item 1 (Symbolrate?)
#if 0
0x234c8b20                        db         0x01                               ; DATA XREF=sub_234552f8+30
0x234c8b21                        db         0x00
0x234c8b22 0000                   movs       r0, r0
0x234c8b24                        dd         0x00000000
0x234c8b28                        dd         0x00000000
0x234c8b2c                        dw         0x003d
0x234c8b2e                        dw         0x0080
0x234c8b30                        dw         0x00f8
0x234c8b32                        dw         0x0020
0x234c8b34                        dd         0x00000000
0x234c8b38                        dd         0x234c12e0
0x234c8b3c                        db         0x09
0x234c8b3d                        db  0x00 ; '.'
0x234c8b3e 0000                   movs       r0, r0
0x234c8b40                        dd         0x234c86e4                         ; DATA XREF=sub_234552f8+36
#endif
	{1, 0, 0, 0, 0x3d, 0xa0, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_bottom_round_left_right/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_item2/*Data_0x20*/}, //[6] = 234C8B60: Text Item 2 (Polarisation?)
#if 0
0x234c8b60                        db         0x01                               ; DATA XREF=sub_234552f8+26
0x234c8b61                        db  0x00 ; '.'
0x234c8b62 0000                   movs       r0, r0
0x234c8b64                        dd         0x00000000
0x234c8b68                        dd         0x00000000
0x234c8b6c                        dw         0x003d
0x234c8b6e                        dw         0x00a0
0x234c8b70                        dw         0x00f8
0x234c8b72                        dw         0x0020
0x234c8b74                        dd         0x00000000
0x234c8b78                        dd         0x234c12ec
0x234c8b7c                        db         0x09
0x234c8b7d                        db  0x00 ; '.'
0x234c8b7e 0000                   movs       r0, r0
0x234c8b80                        dd         0x234c86fc                         ; DATA XREF=sub_234552f8+32
#endif
	{1, 0, 0, 0, 0x37, 0xcb, 0x190, 0xe2, 0, 
	&Data_234c134c/*Data_0x18*/}, //[7] = 234C8BA0: ???
#if 0
0x234c8ba0                        db         0x01
0x234c8ba1                        db         0x00
0x234c8ba2 0000                   movs       r0, r0
0x234c8ba4                        dd         0x00000000
0x234c8ba8                        dd         0x00000000
0x234c8bac                        dw         0x0037
0x234c8bae                        dw         0x00cb
0x234c8bb0                        dw         0x0190
0x234c8bb2                        dw         0x00e2
0x234c8bb4 0000                   movs       r0, r0
0x234c8bb6 0000                   movs       r0, r0
0x234c8bb8                        dd         0x234c134c
#endif
	{0}, //[8] = 234C8BE0 
	{0}, //[9] = 234C8C20 
	{1, 0, 0, 0, 0x37, 0xcb, 0x190, 0x6c, 0, 
	&menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
	2}, //[10] = 234C8C60: ???
#if 0
0x234c8c60                        db         0x01
0x234c8c61                        db         0x00
0x234c8c62 0000                   movs       r0, r0
0x234c8c64                        dd         0x00000000
0x234c8c68                        dd         0x00000000
0x234c8c6c                        dw         0x0037
0x234c8c6e                        dw         0x00cb
0x234c8c70                        dw         0x0190
0x234c8c72                        dw         0x006c
0x234c8c74                        dd         0x00000000
0x234c8c78                        dd         0x234c128c
0x234c8c7c                        db         0x02
0x234c8c7d                        db  0x00 ; '.'
0x234c8c7e 0000                   movs       r0, r0
0x234c8c80                        dd         0x00000000
0x234c8c84                        dd         0x00000000
0x234c8c88                        dd         0x00000000
0x234c8c8c                        dd         0x00000000
0x234c8c90                        dd         0x00000000
0x234c8c94                        dd         0x00000000
0x234c8c98                        dd         0x00000000
0x234c8c9c                        dd         0x00000000
#endif
	{1, 0, 0, 0, 0x3d, 0xf1, 0x184, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_item4/*Data_0x20*/}, //[11] = 234C8CA0: Text Item 4 (C/N?)
#if 0
0x234c8ca0                        db         0x01
0x234c8ca1                        db         0x00
0x234c8ca2 0000                   movs       r0, r0
0x234c8ca4                        dd         0x00000000
0x234c8ca8                        dd         0x00000000
0x234c8cac                        dw         0x003d
0x234c8cae                        dw         0x00f1
0x234c8cb0                        dw         0x0184
0x234c8cb2                        dw         0x0020
0x234c8cb4                        dd         0x00000000
0x234c8cb8                        dd         0x234c12e0
0x234c8cbc                        db         0x09
0x234c8cbd                        db  0x00 ; '.'
0x234c8cbe 0000                   movs       r0, r0
0x234c8cc0                        dd         0x234c872c
#endif 
	{1, 0, 0, 0, 0x3d, 0xd1, 0x184, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_top_round_left_right/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_item3/*Data_0x20*/}, //[12] = 234C8CE0: Text Item 3 (Level: ?)
#if 0
0x234c8ce0                        db         0x01
0x234c8ce1                        db         0x00
0x234c8ce2 0000                   movs       r0, r0
0x234c8ce4                        dd         0x00000000
0x234c8ce8                        dd         0x00000000
0x234c8cec                        dw         0x003d
0x234c8cee                        dw         0x00d1
0x234c8cf0                        dw         0x0184
0x234c8cf2                        dw         0x0020
0x234c8cf4                        dd         0x00000000
0x234c8cf8                        dd         0x234c12f8
0x234c8cfc                        db         0x09
0x234c8cfd                        db  0x00 ; '.'
0x234c8cfe 0000                   movs       r0, r0
0x234c8d00                        dd         0x234c8714
0x234c8d04                        dd         0x00000000
0x234c8d08                        dd         0x00000000
0x234c8d0c                        dd         0x00000000
0x234c8d10                        dd         0x00000000
0x234c8d14                        dd         0x00000000
0x234c8d18                        dd         0x00000000
0x234c8d1c                        dd         0x00000000
#endif
	{1, 0, 0, 0, 0x3d, 0x111, 0x184, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_bottom_round_left_right/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_item5/*Data_0x20*/}, //[13] = 234C8D20: Text Item 5 (BER: ?)
#if 0
0x234c8d20                        db         0x01
0x234c8d21                        db         0x00
0x234c8d22                        db  0x00 ; '.'
0x234c8d23                        db  0x00 ; '.'
0x234c8d24                        dd         0x00000000
0x234c8d28                        dd         0x00000000
0x234c8d2c                        dw         0x003d
0x234c8d2e                        dw         0x0111
0x234c8d30                        dw         0x0184
0x234c8d32                        dw         0x0020
0x234c8d34 0000                   movs       r0, r0
0x234c8d36 0000                   movs       r0, r0
0x234c8d38                        dd         0x234c12ec
0x234c8d3c                        db         0x09
0x234c8d3d                        db  0x00 ; '.'
0x234c8d3e 0000                   movs       r0, r0
0x234c8d40                        dd         0x234c8744
#endif
	{0}, //[14] = 234C8D60:
#if 0
#endif 
	{0}, //[15] = 234C8DA0 
	{0}, //[16] = 234C8DE0 
	{0}, //[17] = 234C8E20 
	{1, 0, 0, 0, 0xd3, 0x115, 0x18, 0x18, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	11}, //[18] = 234C8E60: ???
#if 0
0x234c8e60                        db         0x01
0x234c8e61                        db         0x00
0x234c8e62                        dw         0x0000
0x234c8e64                        dd         0x00000000
0x234c8e68                        dd         0x00000000
0x234c8e6c                        dw         0x00d3
0x234c8e6e                        dw         0x0115
0x234c8e70                        dw         0x0018
0x234c8e72                        dw         0x0018
0x234c8e74 0000                   movs       r0, r0
0x234c8e76 0000                   movs       r0, r0
0x234c8e78                        dd         0x234c12e0
0x234c8e7c                        db         0x0b
0x234c8e7d                        db  0x00 ; '.'
0x234c8e7e 0000                   movs       r0, r0
#endif
	{1, 0, 0, 0, 0xf0, 0x111, 0x41, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &Data_234c875c/*Data_0x20*/}, //[19] = 234C8EA0:
#if 0
0x234c8ea0                        db         0x01
0x234c8ea1                        db         0x00
0x234c8ea2                        dw         0x0000
0x234c8ea4                        dd         0x00000000
0x234c8ea8                        dd         0x00000000
0x234c8eac                        dw         0x00f0
0x234c8eae                        dw         0x0111
0x234c8eb0                        dw         0x0041
0x234c8eb2                        dw         0x0020
0x234c8eb4                        dd         0x00000000
0x234c8eb8                        dd         0x234c12e0
0x234c8ebc                        db         0x09
0x234c8ebd                        db  0x00 ; '.'
0x234c8ebe 0000                   movs       r0, r0
0x234c8ec0                        dd         0x234c875c
#endif
	{0, 0, 0, 0, 0x137, 0x115, 0x18, 0x18, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	11}, //[20] = 234C8EE0: ???
#if 0
0x234c8ee0                        db         0x01
0x234c8ee1                        db  0x00 ; '.'
0x234c8ee2 0000                   movs       r0, r0
0x234c8ee4                        dd         0x00000000
0x234c8ee8                        dd         0x00000000
0x234c8eec                        dw         0x0137
0x234c8eee                        dw         0x0115
0x234c8ef0                        dw         0x0018
0x234c8ef2                        dw         0x0018
0x234c8ef4                        dd         0x00000000
0x234c8ef8                        dd         0x234c12e0
0x234c8efc                        db         0x0b
0x234c8efd                        db  0x00 ; '.'
0x234c8efe 0000                   movs       r0, r0
0x234c8f00                        dd         0x00000000
0x234c8f04                        dd         0x00000000
0x234c8f08                        dd         0x00000000
0x234c8f0c                        dd         0x00000000
0x234c8f10                        dd         0x00000000
0x234c8f14                        dd         0x00000000
0x234c8f18                        dd         0x00000000
0x234c8f1c                        dd         0x00000000
#endif
	{0}, //[21] = 234C8F20
	{0}, //[22] = 234C8F60 
	{0}, //[23] = 234C8FA0 
	{0}, //[24] = 234C8FE0 
	{0}, //[25] = 234C9020 
	{0}, //[26] = 234C9060 
	{0}, //[27] = 234C90A0 
	{0}, //[28] = 234C90E0 
	{0}, //[29] = 234C9120 
	{0}, //[30] = 234C9160 
	{0}, //[31] = 234C91A0 
	{0}, //[32] = 234C91E0 
	{0}, //[33] = 234C9220 
	{0}, //[34] = 234C9260 
	{0}, //[35] = 234C92A0 
	{0}, //[36] = 234C92E0 
	{0}, //[37] = 234C9320 
	{0, 0, 0, 0, 0x37, 0xcb, 0x104, 0xec, 0, 
	&menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
	2}, //[38] = 234C9360: Streams Pid Top Border
#if 0
0x234c9360                        db         0x00
0x234c9361                        db         0x00
0x234c9362                        dw         0x0000
0x234c9364                        dd         0x00000000
0x234c9368                        dd         0x00000000
0x234c936c                        dw         0x0037
0x234c936e                        dw         0x00cb
0x234c9370                        dw         0x0104
0x234c9372                        dw         0x00ec
0x234c9374                        dd         0x00000000
0x234c9378                        dd         0x234c128c
0x234c937c                        db         0x02
0x234c937d                        db  0x00 ; '.'
0x234c937e 0000                   movs       r0, r0
0x234c9380 0000                   movs       r0, r0
0x234c9382 0000                   movs       r0, r0
0x234c9384                        dd         0x00000000
0x234c9388                        dd         0x00000000
0x234c938c                        dd         0x00000000
0x234c9390                        dd         0x00000000
0x234c9394                        dd         0x00000000
0x234c9398                        dd         0x00000000
0x234c939c                        dd         0x00000000
#endif 
	{0, 0, 0, 0, 0x3d, 0xd1, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_top_round_left_right/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_video_pid/*Data_0x20*/}, //[39] = 234C93A0: "Video Pid"
#if 0
0x234c93a0                        db         0x00
0x234c93a1                        db  0x00 ; '.'
0x234c93a2 0000                   movs       r0, r0
0x234c93a4                        dd         0x00000000
0x234c93a8                        dd         0x00000000
0x234c93ac                        dw         0x003d
0x234c93ae                        dw         0x00d1
0x234c93b0                        dw         0x00f8
0x234c93b2                        dw         0x0020
0x234c93b4                        dd         0x00000000
0x234c93b8                        dd         0x234c12f8
0x234c93bc 0900                   movs       r1, r1
0x234c93be 0000                   movs       r0, r0
0x234c93c0                        dd         0x234c8860
#endif 
	{0, 0, 0, 0, 0x3d, 0xf1, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_audio_pid/*Data_0x20*/}, //[40] = 234C93E0: "Audio Pid"
#if 0
0x234c93e0                        db         0x00
0x234c93e1                        db  0x00 ; '.'
0x234c93e2                        dw         0x0000
0x234c93e4                        dd         0x00000000
0x234c93e8                        dd         0x00000000
0x234c93ec                        dw         0x003d
0x234c93ee                        dw         0x00f1
0x234c93f0                        dw         0x00f8
0x234c93f2                        dw         0x0020
0x234c93f4                        dd         0x00000000
0x234c93f8                        dd         0x234c12e0
0x234c93fc                        db         0x09
0x234c93fd                        db  0x00 ; '.'
0x234c93fe 0000                   movs       r0, r0
0x234c9400                        dd         0x234c888c
#endif
	{0, 0, 0, 0, 0x3d, 0x111, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_txt_pid/*Data_0x20*/}, //[41] = 234C9420: "Txt Pid"
#if 0
0x234c9420                        db         0x00
0x234c9421                        db  0x00 ; '.'
0x234c9422 0000                   movs       r0, r0
0x234c9424                        dd         0x00000000
0x234c9428                        dd         0x00000000
0x234c942c                        dw         0x003d
0x234c942e                        dw         0x0111
0x234c9430                        dw         0x00f8
0x234c9432                        dw         0x0020
0x234c9434                        dd         0x00000000
0x234c9438                        dd         0x234c12e0
0x234c943c                        db         0x09
0x234c943d                        db  0x00 ; '.'
0x234c943e 0000                   movs       r0, r0
0x234c9440                        dd         0x234c88b8
#endif 
	{0, 0, 0, 0, 0x3d, 0x131, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &menu_information_graphic_item_text_ac3_pid/*Data_0x20*/}, //[42] = 234C9460: "AC3 Pid"
#if 0
0x234c9460                        db         0x00
0x234c9461                        db  0x00 ; '.'
0x234c9462 0000                   movs       r0, r0
0x234c9464                        dd         0x00000000
0x234c9468                        dd         0x00000000
0x234c946c                        dw         0x003d
0x234c946e                        dw         0x0131
0x234c9470                        dw         0x00f8
0x234c9472                        dw         0x0020
0x234c9474                        dd         0x00000000
0x234c9478                        dd         0x234c12e0
0x234c947c                        db         0x09
0x234c947d                        db  0x00 ; '.'
0x234c947e 0000                   movs       r0, r0
0x234c9480                        dd         0x234c88e4
#endif
	{0, 0, 0, 0, 0x3d, 0x151, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &Data_234c8910/*Data_0x20*/}, //[43] = 234C94A0: ???
#if 0
0x234c94a0                        db         0x00
0x234c94a1                        db  0x00 ; '.'
0x234c94a2 0000                   movs       r0, r0
0x234c94a4                        dd         0x00000000
0x234c94a8                        dd         0x00000000
0x234c94ac                        dw         0x003d
0x234c94ae                        dw         0x0151
0x234c94b0                        dw         0x00f8
0x234c94b2                        dw         0x0020
0x234c94b4                        dd         0x00000000
0x234c94b8                        dd         0x234c12e0
0x234c94bc                        db         0x09
0x234c94bd                        db  0x00 ; '.'
0x234c94be 0000                   movs       r0, r0
0x234c94c0                        dd         0x234c8910
#endif
	{0, 0, 0, 0, 0x3d, 0x171, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &Data_234c893c/*Data_0x20*/}, //[44] = 234C94E0: ???
#if 0
0x234c94e0                        db         0x00
0x234c94e1                        db  0x00 ; '.'
0x234c94e2 0000                   movs       r0, r0
0x234c94e4                        dd         0x00000000
0x234c94e8                        dd         0x00000000
0x234c94ec                        dw         0x003d
0x234c94ee                        dw         0x0171
0x234c94f0                        dw         0x00f8
0x234c94f2                        dw         0x0020
0x234c94f4                        dd         0x00000000
0x234c94f8                        dd         0x234c12e0
0x234c94fc                        db         0x09
0x234c94fd                        db  0x00 ; '.'
0x234c94fe 0000                   movs       r0, r0
0x234c9500                        dd         0x234c893c
#endif
	{0, 0, 0, 0, 0x3d, 0x191, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_bottom_round_left_right/*Data_0x18*/, 
	9, 0, &Data_234c8968/*Data_0x20*/}, //[45] = 234C9520
#if 0
0x234c9520                        db         0x00
0x234c9521                        db         0x00
0x234c9522 0000                   movs       r0, r0
0x234c9524                        dd         0x00000000
0x234c9528                        dd         0x00000000
0x234c952c                        dw         0x003d
0x234c952e                        dw         0x0191
0x234c9530                        dw         0x00f8
0x234c9532                        dw         0x0020
0x234c9534                        dd         0x00000000
0x234c9538                        dd         0x234c12ec
0x234c953c                        db         0x09
0x234c953d                        db  0x00 ; '.'
0x234c953e 0000                   movs       r0, r0
0x234c9540                        dd         0x234c8968
#endif 
	{0, 0, 0, 0, 0x37, 0xcb, 0x104, 0x8c, 0, 
	&menu_main_graphic_item_background_header_dark_blue_top_bottom_round_left_right/*Data_0x18*/, 
	2}, //[46] = 234C9560: Inventory Bottom Border
#if 0
0x234c9560                        db         0x00
0x234c9561                        db  0x00 ; '.'
0x234c9562 0000                   movs       r0, r0
0x234c9564                        dd         0x00000000
0x234c9568                        dd         0x00000000
0x234c956c                        dw         0x0037
0x234c956e                        dw         0x00cb
0x234c9570                        dw         0x0104
0x234c9572                        dw         0x008c
0x234c9574 0000                   movs       r0, r0
0x234c9576 0000                   movs       r0, r0
0x234c9578                        dd         0x234c128c
0x234c957c                        db         0x02
0x234c957d                        db  0x00 ; '.'
#endif
	{0, 0, 0, 0, 0x3d, 0xd1, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_top_round_left_right/*Data_0x18*/, 
	9, 0, &Data_234c8980/*Data_0x20*/}, //[47] = 234C95A0: Inventory HW
#if 0
0x234c95a0                        db         0x00
0x234c95a1                        db  0x00 ; '.'
0x234c95a2 0000                   movs       r0, r0
0x234c95a4                        dd         0x00000000
0x234c95a8                        dd         0x00000000
0x234c95ac                        dw         0x003d
0x234c95ae                        dw         0x00d1
0x234c95b0                        dw         0x00f8
0x234c95b2                        dw         0x0020
0x234c95b4 0000                   movs       r0, r0
0x234c95b6 0000                   movs       r0, r0
0x234c95b8                        dd         0x234c12f8
0x234c95bc                        db         0x09
0x234c95bd                        db  0x00 ; '.'
0x234c95be 0000                   movs       r0, r0
0x234c95c0                        dd         0x234c8980
#endif 
	{0, 0, 0, 0, 0x3d, 0xf1, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &Data_234c8998/*Data_0x20*/}, //[48] = 234C95E0: Inventory SW
#if 0
0x234c95e0                        db         0x00
0x234c95e1                        db         0x00
0x234c95e2 0000                   movs       r0, r0
0x234c95e4                        dd         0x00000000
0x234c95e8                        dd         0x00000000
0x234c95ec                        dw         0x003d
0x234c95ee                        dw         0x00f1
0x234c95f0                        dw         0x00f8
0x234c95f2                        dw         0x0020
0x234c95f4                        dd         0x00000000
0x234c95f8                        dd         0x234c12e0
0x234c95fc                        db         0x09
0x234c95fd                        db         0x00
0x234c95fe 0000                   movs       r0, r0
0x234c9600                        dd         0x234c8998
#endif 
	{0, 0, 0, 0, 0x3d, 0x111, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue/*Data_0x18*/, 
	9, 0, &Data_234c89b0/*Data_0x20*/}, //[49] = 234C9620: Inventory List1
#if 0
0x234c9620                        db         0x00
0x234c9621                        db  0x00 ; '.'
0x234c9622 0000                   movs       r0, r0
0x234c9624                        dd         0x00000000
0x234c9628                        dd         0x00000000
0x234c962c                        dw         0x003d
0x234c962e                        dw         0x0111
0x234c9630                        dw         0x00f8
0x234c9632                        dw         0x0020
0x234c9634                        dd         0x00000000
0x234c9638                        dd         0x234c12e0
0x234c963c                        db         0x09
0x234c963d                        db  0x00 ; '.'
0x234c963e 0000                   movs       r0, r0
0x234c9640                        dd         0x234c89b0
#endif 
	{0, 0, 0, 0, 0x3d, 0x131, 0xf8, 0x20, 0, 
	&menu_main_graphic_item_background_dark_blue_bottom_round_left_right/*Data_0x18*/, 
	9, 0, &Data_234c89c8/*Data_0x20*/}, //[50] = 234C9660: Inventory List2
#if 0
0x234c9660                        db         0x00
0x234c9661                        db  0x00 ; '.'
0x234c9662 0000                   movs       r0, r0
0x234c9664                        dd         0x00000000
0x234c9668                        dd         0x00000000
0x234c966c                        dw         0x003d
0x234c966e                        dw         0x0131
0x234c9670                        dw         0x00f8
0x234c9672                        dw         0x0020
0x234c9674 0000                   movs       r0, r0
0x234c9676 0000                   movs       r0, r0
0x234c9678                        dd         0x234c12ec
0x234c967c                        db         0x09
0x234c967d                        db  0x00 ; '.'
0x234c967e 0000                   movs       r0, r0
0x234c9680                        dd         0x234c89c8
#endif 
	{1, 0, 0, 0, 0x3d, 0x29, 0xf8, 0x26, 0, &Data_234c134c/*Data_0x18*/, 
	2, 0, &menu_information_graphic_item_text_header/*Data_0x20*/}, //[51] = 234C96A0: header
#if 0
0x234c96a0                        db         0x01                               ; DATA XREF=0x234ca4e0
0x234c96a1                        db         0x00
0x234c96a2                        dw         0x0000
0x234c96a4                        dd         0x00000000
0x234c96a8                        dd         0x00000000
0x234c96ac                        dw         0x003d
0x234c96ae                        dw         0x0029
0x234c96b0                        dw         0x00f8
0x234c96b2                        dw         0x0026
0x234c96b4                        dd         0x00000000
0x234c96b8                        dd         0x234c134c
0x234c96bc                        dw         0x0002
0x234c96be                        dw         0x0000
0x234c96c0                        dd         0x234c869c
0x234c96c4                        dd         0x00000000
0x234c96c8                        dd         0x00000000
0x234c96cc                        dd         0x00000000
0x234c96d0                        dd         0x00000000
0x234c96d4                        dd         0x00000000
0x234c96d8                        dd         0x00000000
0x234c96dc                        dd         0x00000000
#endif 
	{0}, //[52] = 234C96E0 
	//->234C9720
};

