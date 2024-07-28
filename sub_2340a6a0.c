


#include <stdint.h>
#include "data.h"
#include "auout.h"
#include "videc.h"
#include "sub_2345bc50.h"
#include "scan.h"
#include "sub_2340a6a0.h"


void channel_stop();
static void channel_on_psi_data(Struct_234a73e8*);
static void channel_check_streaming(void);
int sub_2340b55c();
#if 0
void sub_2340d300();
#endif
void sub_2344f79c();
void sub_23459188();


const uint8_t Data_23488068[] = //23488068
{
		0x00, 0x01, 0x03, 0x05, 0x08, 0x0c, 0x10, 0x15,
		0x1a, 0x1f, 0x25, 0x2c, 0x32, 0x39, 0x41, 0x49,
		0x51, 0x5a, 0x63, 0x6c, 0x76, 0x80, 0x8a, 0x94,
		0x9f, 0xaa, 0xb6, 0xc2, 0xce, 0xda, 0xe7, 0xf3, 0xff
};


typedef struct
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	uint8_t bData_2; //2
	int Data_4; //4
	//8
} Struct_23492040;


//0x23491ffc / 234ac60c
uint8_t bData_23491ffc = 0; //23491ffc +0
int Data_23492000 = 0; //23492000 +4
int Data_23492004 = 0; //23492004 +8
OS_EVENT* channel_sema/*sema*/ = 0; //23492008 +0x0c
int (*Data_23492014)() = sub_2340b55c; //23492014 +0x18
int (*Data_23492018)() = 0; //23492018 +0x1c
void (*Data_2349201c)() = 0; //2349201c / 234ac62c +0x20
void (*Data_23492020)() = 0; //23492020 +0x24
void (*Data_23492024)() = 0; //23492024 +0x28
void (*Data_23492028)() = 0; //23492028 +0x2c
void (*channel_pfCheckStreaming)() = 0; //2349202c +0x30
void (*Data_23492030)() = 0; //23492030 +0x34
void (*Data_23492034)() = 0; //23492034 +0x38
void (*channel_pfPSIDataCallback)(int) = 0; //23492038 +0x3c
Struct_2349203c* Data_2349203c = 0; //2349203c +0x40
Struct_23492040* Data_23492040 = 0; //23492040 +0x44
int channel_videoWritePtr = 0; //23492044 +0x48
int channel_audioWritePtr = 0; //23492048 +0x4c
int Data_2349204c = 200; //2349204c +0x50
int Data_23492050 = 300; //23492050 +0x54
int Data_23492054 = 0; //23492054 +0x58


Struct_234fd8f0 Data_234fd8f0; //234fd8f0 + 489f4 = 235462E4

#define CHANNEL_ACTIVE_STREAM_VIDEO      (1 << 0)
#define CHANNEL_ACTIVE_STREAM_AUDIO      (1 << 1)
#define CHANNEL_ACTIVE_STREAM_TTX        (1 << 3)
#define CHANNEL_ACTIVE_STREAM_PSI        (1 << 6)

struct
{
	void (*Data_0)(); //0 235462E4
	int currentChannel; //4 235462E8
	int prevChannel; //8 235462EC
	uint16_t arChannelIdx[CHANNELS_MAX_NUM]; //12 = 0xc, 235462F0, size????
	uint16_t numChannels; //0xEEC 235491d0
	uint16_t wData_235491d2; //0xEEE 235491d2
	uint16_t wData_235491d4; //235491D4 +0xf0
	uint16_t wData_235491d6; //235491d6 + 0xf2
	uint16_t wAudioPID; //235491d8
	uint16_t wVideoPID; //235491da
	uint8_t bData_235491dc; //0xef8 235491dc
	uint8_t currentChList; //0xEF9 235491dd
	uint8_t activeStreamMask; //235491de 235482e4 + 0xefa
	uint8_t bData_235491df; //235491df
	uint8_t bData_235491e0; //235491e0 0xefc
	uint8_t bData_235491e1; //235491e1 0xefd
	uint8_t bData_235491e2; //235491E2 0xefe

} Data_235462e4; //235462e4


/* 234085ac - complete */
int sub_234085ac(uint8_t* a, uint8_t* b, int c)
{
	int lr = c;

#if 0
	console_send_string("sub_234085ac (todo.c): TODO\r\n");
#endif

	while (c != 0)
	{
		uint8_t r3 = b[0];
		if (r3 == 0)
		{
			break;
		}

		if ((r3 >= 6) && (r3 < 0x20))
		{
			*a++ = ' ';
		}
		else
		{
			uint32_t r4 = r3;
			if ((r4 - 0x7f) >= 0x21)
			{
				*a++ = r3;
			}
		}

		b++;
		c--;
	}

	return lr - c;
}


/* 2340956c / 2340b8d0 - complete */
int channel_stop_audio()
{
#if 0
	console_send_string("channel_stop_audio (todo.c): TODO\r\n");
#endif

	if (main_hPESParserAudio == 0)
	{
		return 0xff;
	}

	auout_set_volume(main_hAuOut, AUOUT_SPEAKER_ALL, 0);

	auout_stop_hdmi();

	audec_stop_decoder(main_hAudec2);
	audec_stop_decoder(main_hAudec1);
	audec_stop_decoder(main_hAudec0);

	if (Data_235462e4.wAudioPID & 0x2000)
	{
		aout_reset(main_hAuOut);
		//->loc_234095e4
	}
	else
	{
		//loc_234095dc
		tsd_deactivate_pid_channel(main_hPESParserAudio);
	}
	//loc_234095e4
	Data_235462e4.wAudioPID = -1;

	return 0;
}


/* 234095f4 / 2340b958 - complete */
int channel_stop_video()
{
#if 1
	console_send_string("channel_stop_video (todo.c): TODO\r\n");
#endif

	hdmi_video_stop(main_hHdmi);

	tsd_deactivate_pid_channel(main_hPESParserVideo);

	videc_stop_decoder();

	Data_235462e4.wVideoPID = -1;

	return 0;
}


/* 23409628 / 2340b98c - todo */
void channel_stop_pes()
{
#if 0
	console_send_string("channel_stop_pes (todo.c): TODO\r\n");
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "channel_stop_pes: Data_235462e4.activeStreamMask=0x%x\r\n",
				Data_235462e4.activeStreamMask);
		console_send_string(debug_string);
	}
#endif

	if (Data_235462e4.activeStreamMask & CHANNEL_ACTIVE_STREAM_VIDEO)
	{
		Data_235462e4.activeStreamMask &= ~CHANNEL_ACTIVE_STREAM_VIDEO;

		channel_stop_video();
	}

	if (Data_235462e4.activeStreamMask & CHANNEL_ACTIVE_STREAM_AUDIO)
	{
		//Audio
		Data_235462e4.activeStreamMask &= ~CHANNEL_ACTIVE_STREAM_AUDIO;

		channel_stop_audio();

		sub_2342ba34(0);
	}
	//loc_23409664
#if 0
	if (Data_235462e4.activeStreamMask & CHANNEL_ACTIVE_STREAM_TTX)
	{
		//Video Text
		Data_235462e4.activeStreamMask &= ~CHANNEL_ACTIVE_STREAM_TTX;

		sub_23460bfc();

		if (Data_23492028 != 0)
		{
			(Data_23492028)(0);
		}
	}
#endif
	//loc_23409690
	if (Data_235462e4.activeStreamMask & 0x20)
	{
		Data_235462e4.activeStreamMask &= ~0x20;

		sub_2345bb88();
	}
	//r4 = 0;
	if (main_hCurrentPCR_TSD_Handle != 0)
	{
		if (main_hPCR_TSD_Handle == main_hCurrentPCR_TSD_Handle)
		{
			tsd_deactivate_pid_channel(main_hPCR_TSD_Handle);
		}

		int r0 = tsd_SetPidConfig_2_NewPcrIrqEn(main_hCurrentPCR_TSD_Handle, 0);

		main_hCurrentPCR_TSD_Handle = 0; //r4

		sync_SetStcRegulation(r0, 0);
	}
	//loc_234096e0
	sub_2345ac28();

	channel_pfCheckStreaming = 0; //r4
}


/* 234096ec / 2340ba50 - todo */
void channel_stop()
{
#if 0
	console_send_string("channel_stop (todo.c): TODO\r\n");
#endif

	channel_stop_pes();

	if (Data_2349201c != 0)
	{
		(Data_2349201c)(0);
	}

	psi_stop(main_hPSIDecoder1, 1);

	Data_235462e4.activeStreamMask &= ~CHANNEL_ACTIVE_STREAM_PSI;
}


/* 23409770 - complete */
void sub_23409770(void)
{
#if 0
	console_send_string("sub_23409770 (todo.c): TODO\r\n");
#endif

	if (bData_23491ffc == 0)
	{
		bData_23491ffc = 1;
	}
}


/* 23409788 - complete */
void sub_23409788(void)
{
#if 0
	console_send_string("sub_23409788 (todo.c): TODO\r\n");
#endif

	if (Data_23492000 == 0)
	{
		auout_set_volume(main_hAuOut, AUOUT_SPEAKER_ALL,
				Data_23488068[ Data_235462e4.bData_235491df ]);
	}
}


/* 234097f4 / 2340bb58 - complete */
void sub_234097f4(int r5)
{
#if 1
	console_send_string("sub_234097f4 (todo.c): TODO\r\n");
#endif

	void* bmHandle = tsd_get_bm_handle(main_hPESParserVideo);

	tsd_deactivate_pid_channel(main_hPESParserVideo);

	Data_235462e4.bData_235491e2 = r5;

	if (r5 != 0)
	{
		tsd_set_pes_config(main_hPESParserVideo, 0xf0);

		bm_SetAudCallback(bmHandle, 0, 0xe0, videc_audcallback_h264, 0);
	}
	else
	{
		//loc_23409844
		tsd_set_pes_config(main_hPESParserVideo, 0);

		bm_SetAudCallback(bmHandle, 0, 0x09, videc_audcallback_h264, 0);
	}

	bm_StopAudFiltering(bmHandle, 1);

	tsd_start_aud_filtering(main_hPESParserVideo);

	tsd_activate_pid_channel(main_hPESParserVideo);
}


/* 2340988c / 2340bbf0 - complete */
int channel_start_audio(uint16_t pid, void* hAudio)
{
#if 0
	console_send_string("channel_start_audio (todo.c): TODO\r\n");
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "channel_start_audio: main_hPESParserAudio=%p, main_hAuOut=%p, pid=0x%x\r\n",
				main_hPESParserAudio, main_hAuOut, pid);
		console_send_string(debug_string);
	}
#endif

	if (pid == 0)
	{
		return 0;
	}
	//loc_234098a4
	if (main_hPESParserAudio != 0)
	{
		if (pid & 0x2000)
		{
			sub_2342b9bc(main_hAuOut, 0x10000, Data_23492004);

			audec_start_decoder(hAudio);

			sub_2342b690(main_hAuOut, pid & ~0xe000);
			//->loc_23409914
		}
		else
		{
			//loc_234098ec
			tsd_set_pes_pid_filter(main_hPESParserAudio, pid & ~0xe000);

			sub_2342b9bc(main_hAuOut, 1, 0);

			audec_start_decoder(hAudio);

			tsd_activate_pid_channel(main_hPESParserAudio);
		}
		//loc_23409914
		bData_23491ffc = 0;
	}
	//loc_2340991c
	Data_235462e4.wAudioPID = pid;

	return 0;
}


/* 23409928 / 2340bc8c - complete */
int channel_start_video(int pid, int r4)
{
#if 0
	console_send_string("channel_start_video (todo.c): TODO\r\n");
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "channel_start_video: main_hPESParserVideo=%p, pid=0x%x, r4=0x%x\r\n",
				main_hPESParserVideo, pid, r4);
		console_send_string(debug_string);
	}
#endif

	tsd_set_pes_pid_filter(main_hPESParserVideo, pid);

	void* r7 = tsd_get_bm_handle(main_hPESParserVideo);

	tsd_set_pes_config(main_hPESParserVideo, 0);

	Data_235462e4.bData_235491e2 = 0;

	if ((r4 & 0x10) == 0)
	{
		//0x23409970
		sub_234225c4(main_hPESParserVideo, 0x3ffc00);

		bm_SetAudCallback(r7, 0, 0xb3, videc_audcallback_mpeg, 0);

		bm_SetAudCallback(r7, 1, 0, videc_audcallback_mpeg, 0);

		tsd_start_aud_filtering(main_hPESParserVideo);

		sub_2341e4a8(r7, 0, 1);

		sub_2341e524(r7, 0, 1);

		sub_2345fea8(main_hPESParserVideo, r4 & 0xff00);
		//->loc_23409a54

//		sub_2341e600(r7, 1);
	}
	else
	{
		//loc_234099ec
		sub_234225c4(main_hPESParserVideo, 0x7ffc00);

		bm_SetAudCallback(r7, 0, 0x09, videc_audcallback_h264, 0);

		bm_StopAudFiltering(r7, 1);

		tsd_start_aud_filtering(main_hPESParserVideo);

		sub_2341e4a8(r7, 0, 1);

		sub_2341e524(r7, 0, 1);

//		sub_2341e600(r7, 1);

#if 0 //TEST!!!
		r4 |= 0x100;
#endif

		sub_23460000(main_hPESParserVideo, r4 & 0xff00);
	}
	//loc_23409a54
	tsd_activate_pid_channel(main_hPESParserVideo);

	Data_235462e4.wVideoPID = pid;

	return 0;
}


/* 23409a6c - todo */
void channel_start_pes(/*struct Struct_234fd8f0_Inner0_Inner_0 a, struct Struct_234fd8f0_Inner0_Inner_0x10 b*/Channel a)
{
#if 0
	console_send_string("channel_start_pes (todo.c): TODO\r\n");
#endif

	int sb = 0;

#if 1
	{
		extern char debug_string[];

		sprintf(debug_string, "channel_start_pes: a.Data_0.wPcrPID=0x%x\r\n",
				a.Data_0.wPcrPID);
		console_send_string(debug_string);

		sprintf(debug_string, "channel_start_pes: a.Data_0.wVideoPID=0x%x\r\n",
				a.Data_0.wVideoPID);
		console_send_string(debug_string);

		sprintf(debug_string, "channel_start_pes: a.Data_0.wData_12=0x%x\r\n",
				a.Data_0.wData_12);
		console_send_string(debug_string);

		sprintf(debug_string, "channel_start_pes: a.Data_0.wTtxPID=0x%x\r\n",
				a.Data_0.wTtxPID);
		console_send_string(debug_string);

		sprintf(debug_string, "channel_start_pes: a.Data_0x10.wAudioPID=0x%x\r\n",
				a.Data_0x10.wAudioPID);
		console_send_string(debug_string);

	}
#endif

//	int r1_ = a.Data_0.wFlags_2;
//	uint16_t r8 = a.Data_0.wData_10;
	if ((/*r8*/a.Data_0.wVideoPID != 0) &&
			((Data_235462e4.activeStreamMask & CHANNEL_ACTIVE_STREAM_VIDEO) == 0))
	{
		Data_235462e4.activeStreamMask |= CHANNEL_ACTIVE_STREAM_VIDEO;

		channel_start_video(/*r8*/a.Data_0.wVideoPID, a.Data_0.wFlags_2); //r1_);
	}
	//loc_23409aa4
//	int r0 = (a.Data_0.wFlags_2 >> 1) & 0x03;
//	uint16_t r7 = a.Data_0.wData_12;
//	uint16_t r5 = a.Data_0x10.wAudioPID;
	if ((/*r7*/a.Data_0.wData_12 != 0) && (/*r5*/a.Data_0x10.wAudioPID == 0) &&
			((Data_235462e4.activeStreamMask & CHANNEL_ACTIVE_STREAM_AUDIO) == 0))
	{
		Data_235462e4.activeStreamMask |= CHANNEL_ACTIVE_STREAM_AUDIO;

		sub_2342ba34((a.Data_0.wFlags_2 >> 1) & 0x03); //r0);
		//->loc_23409b24
		channel_start_audio(/*r7*/a.Data_0.wData_12, main_hAudec1);
		//loc_23409b28
	}
	//loc_23409af0
	if ((/*r5*/a.Data_0x10.wAudioPID != 0) && 
		((Data_235462e4.activeStreamMask & CHANNEL_ACTIVE_STREAM_AUDIO) == 0))
	{
		//loc_23409af8
		Data_235462e4.activeStreamMask |= CHANNEL_ACTIVE_STREAM_AUDIO;

		sub_2342ba34((a.Data_0.wFlags_2 >> 1) & 0x03); //r0);

		if (/*r5*/a.Data_0x10.wAudioPID & 0x4000)
		{
			channel_start_audio(/*r5*/a.Data_0x10.wAudioPID, main_hAudec0);
		}
		else
		{
			channel_start_audio(/*r5*/a.Data_0x10.wAudioPID, main_hAudec2);
		}
	}
	//loc_23409b28
	//uint16_t r1 = a.Data_0.wPcrPID;

#if 1 //TODO!!!
	if (/*r8*/a.Data_0.wVideoPID == a.Data_0.wPcrPID)
	{
		//->loc_23409b54 -> loc_23409b78
		sb = tsd_SetPidConfig_2_NewPcrIrqEn(main_hPESParserVideo, 1);
		main_hCurrentPCR_TSD_Handle = main_hPESParserVideo;
		//->loc_23409bd4
	}
	else
#endif
	{
		//0x23409b40
		if ((/*r5*/a.Data_0x10.wAudioPID & ~0xe000) == a.Data_0.wPcrPID)
		{
			//->loc_23409b78
			sb = tsd_SetPidConfig_2_NewPcrIrqEn(main_hPESParserAudio, 1);
			main_hCurrentPCR_TSD_Handle = main_hPESParserAudio;
			//->loc_23409bd4
		}
		else
		{
			//loc_23409b5c
			if ((/*r7*/a.Data_0.wData_12 & ~0xe000) == a.Data_0.wPcrPID)
			{
				void* r0 = main_hPESParserAudio;
				if (/*r7*/a.Data_0.wData_12 & 0x2000)
				{
					r0 = (void*) sub_2342ba04(r0);
				}
				sb = tsd_SetPidConfig_2_NewPcrIrqEn(r0 , 1);
				main_hCurrentPCR_TSD_Handle = main_hPESParserAudio;
				//->loc_23409bd4
			}
			else
			{
				//loc_23409b8c
				if (a.Data_0.wPcrPID != 0)
				{
					main_hCurrentPCR_TSD_Handle = main_hPCR_TSD_Handle;

					tsd_set_pes_pid_filter(main_hPCR_TSD_Handle, a.Data_0.wPcrPID & ~0xe000);

					sub_2341e4a8( tsd_get_bm_handle(main_hPCR_TSD_Handle), 0xfffc00, 1); //Set read pointer

					tsd_activate_pid_channel(main_hPCR_TSD_Handle);

					sb = tsd_SetPidConfig_2_NewPcrIrqEn(main_hPCR_TSD_Handle, 1);
				}
			}
		}
	}
	//loc_23409bd4
#if 0
	if (a.Data_0.wTtxPID != 0)
	{
		if ((Data_235462e4.activeStreamMask & CHANNEL_ACTIVE_STREAM_TTX) == 0)
		{
			//Video Text
			Data_235462e4.activeStreamMask |= CHANNEL_ACTIVE_STREAM_TTX;

			sub_23460b7c(a.Data_0.wTtxPID);
		}
	}
#endif
	//loc_23409bf4
	if (main_hCurrentPCR_TSD_Handle != 0)
	{
		sync_SetStcRegulation(sb, 1);
	}

	channel_pfCheckStreaming = channel_check_streaming;
}


/* 23409c1c - todo */
void sub_23409c1c(PSI_Program* r7)
{
#if 0
	console_send_string("sub_23409c1c (todo.c): TODO\r\n");
#endif

	if ((Data_234fd8f0.Data_235441b0.Data_4 & 0xfc) == 0)
	{
		//loc_23409da4
		return;
	}

	//0x23409c34
	int fp = 0;

	if ((Data_2349203c == 0) && (Data_23492040 == 0))
	{
		//0x23409c4c
		if (r7->Data_0x340[0].Data_4[0] != 0)
		{
			int sb = 0;
			int sl = 0;
			for (uint16_t r5 = 0; r5 < 4; r5++)
			{
				//loc_23409c64
				if (r7->Data_0x340[r5].Data_4[0] == 0)
				{
					//->loc_23409cd0
					break;
				}
				//0x23409c78
				for (uint16_t r4 = 0; r4 < 4; r4++)
				{
					//loc_23409c7c
					if (r7->Data_0x340[r5].Data_4[r4] == 0)
					{
						//->loc_23409cc0
						break;
					}
					//0x23409c8c
					if (0 != sub_234093d4(r7->Data_0x340[r5].Data_4[r4] + 1,
							Data_234fd8f0.Data_235441b0.menuLanguage))
					{
						sl = r5;
						sb = r4;
						r5 = 4;
						fp = 1;
						//->loc_23409cc0
						break;
					}
					//0x23409cb0
				} //for (uint16_t r4 = 0; r4 < 4; r4++)
				//loc_23409cc0
			} //for (uint16_t r5 = 0; r5 < 4; r5++)
			//loc_23409cd0

			Struct_2349203c sp;

			sp.pid = r7->Data_0x340[sl].wData_0;
			struct
			{
				int fill_0; //0
				uint16_t fill_4; //4
				uint16_t wData_6; //6
				uint16_t wData_8; //8

			}* r0 = (void*) r7->Data_0x340[sl].Data_4[sb];

			sp.wData_2 = r0->wData_6;
			sp.wData_4 = r0->wData_8;

			Data_2349203c = &sp;
		} //if (r7->Data_0x340[0].Data_4[0] != 0)

		if (fp == 0)
		{
			//loc_23409d10
			Struct_23492040* r5 = (void*) r7->Data_0x390;

			for (uint16_t r4 = 0; r4 < 16; r4++)
			{
				//loc_23409d18
				int r0 = r5[r4].bData_0;

				if (r0 == 2)
				{
					//0x23409d24
					if (0 != sub_234093d4(&r5[r4].Data_4,
							Data_234fd8f0.Data_235441b0.menuLanguage))
					{
						Data_23492040 = &r5[r4];
						Data_2349203c = 0;
						//->loc_23409da8
						break;
					}
					//0x23409d50 -> loc_23409d5c
				}
				//loc_23409d54
				else if (r0 == 0)
				{
					//->loc_23409d6c
					break;
				}
				//loc_23409d5c
			} //for (uint16_t r4 = 0; r4 < 16; r4++)
			//loc_23409d6c
		} //if (fp == 0)
		//loc_23409d6c
	} //if ((Data_2349203c == 0) && (Data_23492040 == 0))
	//loc_23409d6c
	if (Data_2349203c != 0)
	{
		if (Data_2349203c->pid != 0)
		{
			//0x23409d88: Set the pid and start streaming
			sub_2345bbcc(Data_2349203c);

			Data_2349203c = 0;

			Data_235462e4.activeStreamMask |= 0x20;
		}
		//loc_23409da4
		return;
	}
	//loc_23409da8
	if (Data_23492040 == 0)
	{
		//0x23409db8
		Struct_23492040* r5 = (void*) r7->Data_0x390;

		for (uint16_t r4 = 0; r4 < 16; r4++)
		{
			//loc_23409dc0
			int r0 = r5[r4].bData_0;

			if (r0 == 2)
			{
				//0x23409dcc
				if (Data_23492040 == 0)
				{
					Data_23492040 = &r5[r4];
					//->loc_23409e0c
				}
				else
				{
					//0x23409de0
					if (0 != sub_234093d4(&r5[r4].Data_4,
							Data_234fd8f0.Data_235441b0.menuLanguage))
					{
						Data_23492040 = &r5[r4];
						//->loc_23409e1c
						break;
					}
					//0x23409e00 -> loc_23409e0c
				}
			}
			//loc_23409e04
			else if (r0 == 0)
			{
				//->loc_23409e1c
				break;
			}
			//loc_23409e0c
		} //for (uint16_t r4 = 0; r4 < 16; r4++)
		//loc_23409e1c
		if (Data_23492040 == 0)
		{
			return;
		}
		//loc_23409e28
	}
	//loc_23409e28
#if 0
	uint32_t r2 = Data_23492040->bData_2;
	uint32_t r0 = Data_23492040->bData_1;
	int r1 = r2 >> 4;
	r0 = r0 * 25;
	int r3 = r1 * 5;
	r2 = r2 & 0x0f;
	r2 = r2 + r3 * 2;
	r0 = r2 + r0 * 4;
#else
	int r0 = Data_23492040->bData_1 * 25 * 4 +
			(Data_23492040->bData_2 >> 4) * 10 +
			(Data_23492040->bData_2 & 0x0f);
#endif

	if (Data_23492028 != 0)
	{
		(Data_23492028)(r0);
	}

	Data_23492040 = 0;
}


/* 23409e64 - todo */
void channel_on_psi_data(Struct_234a73e8* a)
{
#if 1
	console_send_string("channel_on_psi_data (todo.c): TODO\r\n");
#endif

	int r6 = 1;
	int r5 = 0;
	int r8 = 1; //r6

	Channel sp_0x24;
	PSI_Program* pPrograms; //sp_0x20
	uint16_t wNumPrograms = 0; //r5 //sp_0x1c

	if (0 != psi_get_all_current_programs(a, &wNumPrograms, &pPrograms))
	{
		if (channel_pfPSIDataCallback != 0)
		{
			(channel_pfPSIDataCallback)(1);
		}
		//loc_23409ea4
		return;
	}
	//loc_23409eac
	if (channel_pfPSIDataCallback != 0)
	{
		(channel_pfPSIDataCallback)(0);
	}

	if (wNumPrograms == 0)
	{
		//loc_23409ea4
		return;
	}

	if (0 == OSSemAccept(channel_sema))
	{
		//loc_23409ea4
		return;
	}

//	Channel* r7 = &Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[ Data_235462e4.currentChannel ] ];
//	sp_0x24 = *r7; //memcpy

	sp_0x24 = Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[ Data_235462e4.currentChannel ] ];

//	int r2 = sp_0x24.Data_0.service_id;
//	struct Struct_234a73e8_Inner_0x248* r1 = pPrograms;
	//int r3 = wNumPrograms;
	//ip, #0x73
	//->loc_2340a17c
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "channel_on_psi_data: sp_0x24.Data_0.service_id=%d, wNumPrograms=%d\r\n",
				sp_0x24.Data_0.service_id, wNumPrograms);
		console_send_string(debug_string);
	}
#endif

	for (uint16_t r0 = 0; r0 < /*r3*/wNumPrograms; r0++)
	{
		//loc_23409f18
		if (/*r2*/sp_0x24.Data_0.service_id == /*r1*/pPrograms[r0].pat_program_number)
		{
			//0x23409f2c
			sub_2345b08c(&/*r1*/pPrograms[r0]);

			if (pPrograms[r0].service_name != 0)
			{
#if 1
				{
					extern char debug_string[];
					sprintf(debug_string, "channel_on_psi_data: pPrograms[%d].service_name='%s'\r\n",
							r0, pPrograms[r0].service_name);
					console_send_string(debug_string);
				}
#endif

				strncpy(/*r7->*/sp_0x24.Data_0x10.service_name, pPrograms[r0].service_name, 19);
			} //if (pPrograms[r0].service_name != 0)
			//0x23409f54
#if 0
			int r3 = sp_0x24.Data_0x10.wData_0;
			if (r3 == 0)
			{
				//0x23409f60
				if (sp_0x24.Data_0.wData_12 == 0)
				{
					//0x23409f70
					if (pPrograms[r0].wData_0x33c == 0)
					{
						r6 = 0;
					}

					if (pPrograms[r0].wData_0x338 != 0)
					{
						//0x23409f94 -> loc_2340a040
						if (r8 != 0)
						{
							//0x2340a048
							r5 = 1;

							sp_0x24.Data_0.wData_12 = pPrograms[r0].wData_0x338;

							if ((r3 == 0) && (sp_0x24.Data_0.wData_12 == 0))
							{
								sp_0x24.Data_0x10.wData_0 = pPrograms[r0].wData_0x33c;
							}
							//loc_2340a074
						}
						//loc_2340a074
					}
					//loc_2340a074
				}
				else
				{
					r6 = 0;
					//->loc_23409ff4
					uint16_t r0_ = 0;
					//int ip = sp_0x24.Data_0.wData_12 & ~0xe000;
					//->loc_2340a030
					while (pPrograms[r0].Data_0xd0[r0_] != 0)
					{
						//loc_2340a00c
						if ((pPrograms[r0].wData_6[r0_]) == /*ip*/(sp_0x24.Data_0.wData_12 & ~0xe000))
						{
							if (pPrograms[r0].Data_0x198[r0_] != 0)
							{
								r8 = 0;
							}
						}
						//loc_2340a028
						r0_++;
					}
					//loc_2340a040
					if (r8 != 0)
					{
						//0x2340a048
						r5 = 1;
						sp_0x24.Data_0.wData_12 = pPrograms[r0].wData_0x338;

						if ((r3 == 0) && (sp_0x24.Data_0.wData_12 == 0))
						{
							sp_0x24.Data_0x10.wData_0 = pPrograms[r0].wData_0x33c;
						}
					}
					//loc_2340a074
				}
			}
			else
			{
				//loc_23409f98
				uint16_t r0_ = 0;
				//int ip = r3 & ~0xe000;
				//r2 = &pPrograms[r0];
				//->loc_23409fd0
				while ((pPrograms[r0].Data_0xd0[r0_] == 0) && (pPrograms[r0].Data_0x260[r0_] != 0))
				{
					//loc_23409fac
					if ((pPrograms[r0].wData_6[r0_] & ~0xe000) == /*ip*/(r3 & ~0xe000))
					{
						if (pPrograms[r0].Data_0x198[r0_] == 0)
						{
							r6 = 0;
						}
					}

					r0_++;
				}
				//0x23409fe8
				if (sp_0x24.Data_0.wData_12 != 0)
				{
					//loc_23409ff4
					uint16_t r0_ = 0;
					//int ip = sp_0x24.Data_0.wData_12 & ~0xe000;
					//->loc_2340a030
					while (pPrograms[r0].Data_0xd0[r0_] != 0)
					{
						//loc_2340a00c
						if ((pPrograms[r0].wData_6[r0_]) == /*ip*/(sp_0x24.Data_0.wData_12 & ~0xe000))
						{
							if (pPrograms[r0].Data_0x198[r0_] != 0)
							{
								r8 = 0;
							}
						}
						//loc_2340a028
						r0_++;
					}
					//loc_2340a040
					if (r8 != 0)
					{
						//0x2340a048
						r5 = 1;
						sp_0x24.Data_0.wData_12 = pPrograms[r0].wData_0x338;

						if ((r3 == 0) && (sp_0x24.Data_0.wData_12 == 0))
						{
							sp_0x24.Data_0x10.wData_0 = pPrograms[r0].wData_0x33c;
						}
					}
					//loc_2340a074
				}
				//loc_2340a074
			}
			//loc_2340a074
			if (r6 != 0)
			{
				sp_0x24.Data_0x10.wData_0 = pPrograms[r0].wData_0x33c;
				r5 = 1;
			}
#endif

			if ((sp_0x24.Data_0.wFlags_2 & 0x10) != (pPrograms[r0].bData_0 & 0x10))
			{
				//0x2340a0ac
				sp_0x24.Data_0.wFlags_2 &= ~0x10;
				sp_0x24.Data_0.wFlags_2 |= (pPrograms[r0].bData_0 & 0x10);
				sp_0x24.Data_0.wFlags_2 &= ~0x100;
				sp_0x24.Data_0.wFlags_2 &= ~0x200;
				sp_0x24.Data_0.wFlags_2 &= ~0x400;
				sp_0x24.Data_0.wFlags_2 &= ~0x800;
				r5 = 1;
			}
			//loc_2340a0ec
			if (sp_0x24.Data_0.wVideoPID != pPrograms[r0].wVideoPID)
			{
				sp_0x24.Data_0.wVideoPID = pPrograms[r0].wVideoPID;
				r5 = 1;
			}

			if (sp_0x24.Data_0.wPcrPID != pPrograms[r0].wPcrPID)
			{
				sp_0x24.Data_0.wPcrPID = pPrograms[r0].wPcrPID;
				r5 = 1;
			}

			if (sp_0x24.Data_0.wTtxPID != pPrograms[r0].wTtxPID)
			{
				sp_0x24.Data_0.wTtxPID = pPrograms[r0].wTtxPID;
				r5 = 1;
			}
			//0x2340a130
#if 0
			if (r5 != 0)
			{
				//loc_2340a138
				channel_stop_pes();

				Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[ Data_235462e4.currentChannel ] ] = sp_0x24;
//				*r7 = sp_0x24;

				channel_start_pes(Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[ Data_235462e4.currentChannel ] ]);
			}
#endif
			//loc_2340a164
			sub_23409c1c(&pPrograms[r0]);
			//->loc_2340a184
			break;
		} //if (/*r2*/sp_0x24.Data_0.service_id == /*r1*/pPrograms[r0].pat_program_number)
		//loc_2340a174
	} //for (uint16_t r0 = 0; r0 < /*r3*/wNumPrograms; r0++)
	//loc_2340a184
	OSSemPost(channel_sema);
	//->loc_23409ea4();
}


/* 2340a190 - todo */
void channel_check_streaming(void)
{
#if 0
	console_send_string("channel_check_streaming (todo.c): TODO\r\n");
#endif

	//r4, =0x235482e4

	int r6 = sub_2345f928(); //Get videc state?

	//r8, =0x23491ffc
	//r7, #0xc8

	if (Data_235462e4.activeStreamMask & CHANNEL_ACTIVE_STREAM_VIDEO)
	{
		//0x2340a1b8
		int writePtr = sub_23422268(main_hPESParserVideo);

		if (channel_videoWritePtr == writePtr)
		{
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "channel_check_streaming: channel_videoWritePtr=%d, writePtr=%d, Data_2349204c=%d\r\n",
						channel_videoWritePtr, writePtr, Data_2349204c);
				console_send_string(debug_string);
			}
#endif
			Data_2349204c--;
		}
		else
		{
			Data_2349204c = 200;
		}

		channel_videoWritePtr = writePtr;
	} //if (Data_235462e4.activeStreamMask & CHANNEL_ACTIVE_STREAM_VIDEO)
	//loc_2340a1e0
	if (Data_235462e4.activeStreamMask & CHANNEL_ACTIVE_STREAM_AUDIO)
	{
		//0x2340a1ec
		void* r0_ = main_hPESParserAudio;
		if (Data_235462e4.wAudioPID & 0x2000)
		{
			r0_ = (void*) sub_2342ba04(r0_);
		}

		int writePtr = sub_23422268(r0_);

		if (channel_audioWritePtr == writePtr)
		{
#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "channel_check_streaming: channel_audioWritePtr=%d, writePtr=%d, Data_2349204c=%d\r\n",
						channel_audioWritePtr, writePtr, Data_2349204c);
				console_send_string(debug_string);
			}
#endif

			Data_2349204c--;
		}
		else
		{
			Data_2349204c = 200;
		}

		channel_audioWritePtr = writePtr;
	} //if (Data_235462e4.activeStreamMask & CHANNEL_ACTIVE_STREAM_AUDIO)
	//loc_2340a224
	//sb, =0x235462e4
	//sl, =0x234fd8f0
	if (Data_2349204c <= 0)
	{
		//0x2340a238
		if (Data_23492024 != 0)
		{
			(Data_23492024)();
		}

		Channel sp_0x18 =
				Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[ Data_235462e4.currentChannel ] ];

		channel_start_pes(Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[ Data_235462e4.currentChannel ] ]);

		if (Data_2349201c != 0)
		{
			(Data_2349201c)(1);
		}

		psi_start_for_service(main_hPSIDecoder1, sp_0x18.Data_0.service_id, 0x7f, channel_on_psi_data);

		Data_235462e4.activeStreamMask |= CHANNEL_ACTIVE_STREAM_PSI;

		Data_2349204c = 200;
	} //if (Data_2349204c <= 0)
	//loc_2340a2b8
	if (r6 == 1)
	{
		//0x2340a2c0
		channel_stop_pes();

		Channel sp_0x18 =
				Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[ Data_235462e4.currentChannel ] ];

		channel_start_pes(Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[ Data_235462e4.currentChannel ] ]);
	}
	//loc_2340a308
	else if (r6 == 2)
	{
		sub_234097f4(1 & ~Data_235462e4.bData_235491e2);
	}
	//loc_2340a300
}


/* 2340a320 - todo */
void channel_periodic_check(int powerdown)
{
	uint8_t sp;

#if 0
	console_send_string("channel_periodic_check (todo.c): TODO\r\n");
#endif

	//int r7 = 0;
	//r4, =dword_23491dac
	//r5, =0x23491ffc

	if (powerdown != 0)
	{
		Data_23492054 = 0; //r7

		hdmi_power_down(main_hHdmi, 1);
	}
	else
	{
		//loc_2340a34c
		sub_2340d300();

		radiotext_check_data(Data_235462e4.currentChannel);

		OSSemPend(channel_sema, 0, &sp);

		if (channel_pfCheckStreaming != 0)
		{
			(channel_pfCheckStreaming)();
		}

		int r0 = sub_234253d0(main_hHdmi);
		//r0 = 23492054
		if (r0 != 0)
		{
			//0x2340a38c
			if (Data_23492054 == 0)
			{
				//0x2340a394
				hdmi_read_edid(main_hHdmi);
				//r0 = 23492054
				//->loc_2340a4a8
				Data_23492054++;
				//loc_2340a4b0
			}
			else
			{
				//loc_2340a3a4
				//r8, =main_hAuOut
				if (Data_23492054 == 10)
				{
					//0x2340a3b0
					hdmi_power_down(main_hHdmi, 0);
					hdmi_video_start(main_hHdmi);
					sub_23424f14(main_hHdmi);

					auout_start_hdmi(main_hAuOut);
					//mvn        r0, #0x0
					//->loc_2340a4ac
					Data_23492054 = -1;
					//loc_2340a4b0
				}
				//loc_2340a3dc
				else if (Data_23492054 == -1)
				{
					//0x2340a3e4
					if (Data_23492018 != 0)
					{
						//0x2340a3f0
						int r0 = (Data_23492018)(main_hHdmi);
						if (r0 == 0)
						{
							//0x2340a400
							Data_23492018 = 0; //r7

							sub_23424f14(main_hHdmi);

							if (bData_23491ffc == 2)
							{
								//0x2340a418
								auout_stop_hdmi();

								bData_23491ffc = 1;
								//->loc_2340a434
							}
							//loc_2340a428
						}
						//loc_2340a428
					}
					//loc_2340a428
					if (bData_23491ffc == 1)
					{
						//loc_2340a434
						bData_23491ffc = 2;

						auout_start_hdmi(main_hAuOut);
						//->loc_2340a4b0
					}
					//loc_2340a4b0
				} //else if (Data_23492054 == -1)
				else
				{
					//loc_2340a4a8
					Data_23492054++;
					//loc_2340a4b0
				}
			}
			//loc_2340a4b0
			sub_2342ba10();
			//->loc_2340a4cc
		} //if (r0 != 0)
		else
		{
			//loc_2340a4b8
			if (Data_23492054 != 0)
			{
				hdmi_power_down(main_hHdmi, 1);
			}

			Data_23492054 = 0;
		}
		//loc_2340a4cc
		OSSemPost(channel_sema);

		int r4 = sub_2345ff98(); //->videc.c

		OSSemPend(channel_sema, 0, &sp);

		if (Data_235462e4.activeStreamMask & CHANNEL_ACTIVE_STREAM_VIDEO)
		{
			//0x2340a500
			int r1 = Data_235462e4.arChannelIdx[ Data_235462e4.currentChannel ];

			Data_234fd8f0.arChannels[ r1 ].Data_0.wFlags_2 =
					(Data_234fd8f0.arChannels[ r1 ].Data_0.wFlags_2 & 0xff) | r4;
		}
		//loc_2340a528
		OSSemPost(channel_sema);
	}
}


/* 2340a59c - complete */
int sub_2340a59c(int pid)
{
#if 0
	console_send_string("sub_2340a59c (todo.c): TODO\r\n");
#endif

	if (pid == 0)
	{
		return 0;
	}
	//loc_2340a5b0
	if (main_hPESParserAudio != 0)
	{
		void* bmHandle = tsd_get_bm_handle(main_hPESParserAudio);

		if (pid & 0x2000)
		{
			//0x2340a5d8
			sub_2342b9bc(main_hAuOut, 0x10000, Data_23492004);

			sub_2341e524( sub_2342ba04(), 0, 1);

			sub_2342b690(main_hAuOut, pid & ~0xe000);
			//->loc_2340a63c
		}
		else
		{
			//loc_2340a608
			tsd_set_pes_pid_filter(main_hPESParserAudio, pid & ~0xe000);

			sub_2342b9bc(main_hAuOut, 1, 0);

			sub_2341e524(bmHandle, 0, 1);

			tsd_activate_pid_channel(main_hPESParserAudio);
		}
		//loc_2340a63c
		bData_23491ffc = 0;
	}
	//loc_2340a644
	Data_235462e4.wAudioPID = pid;
	//loc_2340a5a8
	return 0;
}


/* 2340a650 - complete */
int sub_2340a650(uint8_t r0)
{
	uint8_t i;
	uint8_t ip = 0;

#if 0
	console_send_string("sub_2340a650 (todo.c): TODO\r\n");
#endif

	if (r0 != 0)
	{
		for (i = 0; i < 32; i++)
		{
			//loc_2340a664
			if (r0 >= Data_23488068[i])
			{
				//0x2340a670
				if (r0 <= Data_23488068[i + 1])
				{
					ip = i + 1;
					//->loc_2340a698
					break;
				}
			}
			//loc_2340a688
		}
	}
	//loc_2340a698
	return ip;
}


/* 2340a6a0 / 2340c9e0 - todo */
int channel_init(int r5)
{
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "channel_init: r5=0x%x\r\n", r5);
		console_send_string(debug_string);
	}
#endif

	if (channel_sema != 0)
	{
		return 4;
	}

	channel_sema = OSSemCreate(1);

	Data_235462e4.wAudioPID = 0xffff;
	Data_235462e4.wVideoPID = 0xffff;

	if (r5 != 0)
	{
		Data_235462e4.bData_235491df = r5;
		//->loc_2340a6f8
	}
	else
	{
		//0x2340a6e8
		Data_235462e4.bData_235491df = sub_2340a650(Data_234fd8f0.Data_235441b0.bData_8/*235441b8*/);
	}
	//loc_2340a6f8
	auout_set_volume(main_hAuOut, AUOUT_SPEAKER_ALL, 0);

	return 0;
}


/* 2340a71c - todo */
void sub_2340a71c()
{
#if 0
	console_send_string("sub_2340a71c (todo.c): TODO\r\n");
#endif

	Channel* pChannel;
	uint32_t i = 0;
	Data_235462e4.numChannels = 0;

	pChannel = Data_234fd8f0.arChannels;

	for (i = 0; i < CHANNELS_MAX_NUM; i++)
	{
		if (pChannel[i].Data_0.service_id == 0xffff)
		{
			break;
		}

		if ((pChannel[i].Data_0.wFlags_2 & (1 << 7)) &&
				(((pChannel[i].Data_0.wFlags_2 & (1 << 3)) >> 3) == Data_235462e4.currentChList))
		{
			Data_235462e4.arChannelIdx[Data_235462e4.numChannels] = i;
			Data_235462e4.numChannels++;
		}
	}
}


/* 2340a794 - todo */
int channel_load_lists(void)
{
	void* sp_0x18;
	uint8_t err; //sp_0x14
	LastMode lastmode; //sp4

	int* sp;

#if 0
	console_send_string("channel_load_lists (todo.c): TODO\r\n");
#endif

	//r6, =0x234fd8f0

	OSSemPend(channel_sema, 0, &err);

	//r4, =0x235490e4
	//r7 = 0;
	//sub r5, r4, #0xe00 = 235482E4

	Data_235462e4.numChannels = 0; //r7
	Data_235462e4.wData_235491d6 = 0; //r7
	Data_235462e4.wData_235491d4 = 0; //r7
	Data_235462e4.currentChList = 1; //r0

	//sub sb, r5, #0x2000 = 235462E4

	Data_235462e4.bData_235491dc = 1; //r0

	Data_235462e4.Data_0 = sub_2340a71c;

	Data_235462e4.bData_235491e0 = 0; //r7
	Data_235462e4.bData_235491e1 = 0xff; //r0

	sub_23438084(Data_23491dc8, &lastmode, 0, sizeof(lastmode));

	int r8 = lastmode.crc;

	lastmode.crc = 0; //r7

	int r0 = crc32((void*) &lastmode, 0x10);

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "channel_load_lists: crc check r0=0x%x, r8=0x%x\r\n", r0, r8);
		console_send_string(debug_string);
	}
#endif

	int r1 = r8;

	r8 = 0xffff;
//	uint32_t sl = 6000; //0x1770;

	void* fp = &Data_234fd8f0;

	sp_0x18 = &Data_234fd8f0.Data_235441d8;

	if (r0 == r1)
	{
		//0x2340a840
		Data_235462e4.currentChannel = lastmode.currentChannel;
		Data_235462e4.prevChannel = lastmode.prevChannel;
		Data_235462e4.wData_235491d4 = lastmode.wData_8;
		Data_235462e4.wData_235491d6 = lastmode.wData_10;
		Data_235462e4.bData_235491dc = lastmode.bData_12;
		Data_235462e4.currentChList = lastmode.currentChList;

		if ((Data_235462e4.bData_235491dc & 0x02) != 0)
		{
			//0x2340a87c
			uint16_t* r6 = (void*) sp_0x18;
			sp = &Data_234fd8f0.Data_23546118;

			r0 = crc32((void*) r6, 2000/*0x7d0*/);

#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "channel_load_lists: crc check r0=0x%x, sp[0]=0x%x\r\n", r0, sp[0]);
				console_send_string(debug_string);
			}
#endif

			if (r0 == sp[0])
			{
				//0x2340a8a4
				for (Data_235462e4.numChannels = 0;
						Data_235462e4.numChannels < 1000;
						Data_235462e4.numChannels++)
				{
					//loc_2340a8a8
					if (r6[Data_235462e4.numChannels] == r8/*0xffff*/)
					{
						//->loc_2340a8d0
						break;
					}

				} //for (...)
				//loc_2340a8d0
				if (Data_235462e4.numChannels <= Data_235462e4.currentChannel)
				{
					Data_235462e4.currentChannel = 0; //r7
				}

				if (Data_235462e4.numChannels < Data_235462e4.prevChannel)
				{
					Data_235462e4.prevChannel = 0; //r7
				}

				if (Data_235462e4.currentChList == 1)
				{
					Data_235462e4.wData_235491d4 = Data_235462e4.currentChannel;
					//->loc_2340a90c
				}
				else if (Data_235462e4.currentChList == 0)
				{
					Data_235462e4.wData_235491d6 = Data_235462e4.currentChannel;
				}
				//loc_2340a90c
				memcpy(&Data_235462e4.arChannelIdx[0], r6, Data_235462e4.numChannels * 2);
				//->loc_2340a9c0
			} //if (r0 == sp[0])
			//loc_2340a9c0
		} //if ((Data_235462e4.bData_235491dc & 0x02) != 0)
		else
		{
			//loc_2340a920
			for (uint32_t i = 0; i < /*sl*/CHANNELS_MAX_NUM; i++)
			{
				//loc_2340a920
				Channel* pChannel = &Data_234fd8f0.arChannels[i];

				if (pChannel->Data_0.service_id == r8/*0xffff*/)
				{
					//->loc_2340a970
					break;
				}
				//0x2340a934
				if (pChannel->Data_0.wFlags_2 & (1 << 7))
				{
					//0x2340a940
					if (Data_235462e4.currentChList == ((pChannel->Data_0.wFlags_2 & (1 << 3)) >> 3))
					{
						Data_235462e4.arChannelIdx[Data_235462e4.numChannels] = i;
						Data_235462e4.numChannels++;
					}
				}
				//loc_2340a964
			} //for (uint32_t i = 0; i < CHANNELS_MAX_NUM; i++)
			//loc_2340a970
			if (Data_235462e4.numChannels <= Data_235462e4.currentChannel)
			{
				Data_235462e4.currentChannel = 0; //r7
			}

			if (Data_235462e4.bData_235491dc & 0x04)
			{
				sub_23487aa8(&Data_235462e4.arChannelIdx[0], Data_235462e4.numChannels, 2, sub_2344f79c);
			}
			//->loc_2340a9c0
		}
		//loc_2340a9c0
		while (((/*fp*/Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[ Data_235462e4.currentChannel ] ].Data_0.wData_6) >> 15) != 0)
		{
			//loc_2340a99c
			Data_235462e4.currentChannel++;
			Data_235462e4.prevChannel++;

			if (Data_235462e4.currentChannel >= /*sl*/6000)
			{
				Data_235462e4.currentChannel = 0; //r7
				Data_235462e4.prevChannel = 0; //r7
				//->loc_2340ab08
				break;
			}
		} //while (1)
		//->loc_2340ab08
	} //if (r0 == r1)
	else
	{
		//loc_2340a9e4
		sub_23438194(Data_23491dc8);

		//mov        r1, #0x2
		//loc_2340a9f4

		//TODO!!!
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "channel_load_lists: loc_2340a9f4: TODO!!!\r\n");
			console_send_string(debug_string);
		}
#endif
	}

	//loc_2340ab08
	r0 = crc32(sp_0x18, 2000);

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "loc_2340ab08: crc check r0=0x%x, Data_234fd8f0.Data_23546118=0x%x\r\n",
				r0, Data_234fd8f0.Data_23546118);
		console_send_string(debug_string);
	}
#endif

	if (r0 == Data_234fd8f0.Data_23546118)
	{
		Data_235462e4.bData_235491e0++;
		//->loc_2340ab40
	}
	else
	{
		memset(sp_0x18, 0xff, 2000);
	}
	//loc_2340ab40
	r0 = crc32((void*) &Data_234fd8f0.favourites, 
			sizeof(sizeof(Data_234fd8f0.favourites)));

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "loc_2340ab40: crc check r0=0x%x, Data_234fd8f0.dwCrcFavourites=0x%x\r\n",
				r0, Data_234fd8f0.dwCrcFavourites);
		console_send_string(debug_string);
	}
#endif

	if (r0 == Data_234fd8f0.dwCrcFavourites)
	{
		Data_235462e4.bData_235491e0++;
		//->loc_2340ab78
	}
	else
	{
		memset(&Data_234fd8f0.favourites, 0xff, 
			sizeof(Data_234fd8f0.favourites));
	}
	//loc_2340ab78
	r0 = crc32((void*) &Data_234fd8f0.Data_23545178, 2000);

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "loc_2340ab78: crc check r0=0x%x, Data_234fd8f0.Data_23546120=0x%x\r\n",
				r0, Data_234fd8f0.Data_23546120);
		console_send_string(debug_string);
	}
#endif

	if (r0 == Data_234fd8f0.Data_23546120)
	{
		Data_235462e4.bData_235491e0++;
		//->loc_2340abb0
	}
	else
	{
		memset(&Data_234fd8f0.Data_23545178, 0xff, 2000);
	}
	//loc_2340abb0
	r0 = crc32((void*) &Data_234fd8f0.Data_23545948, 2000);

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "loc_2340abb0: crc check r0=0x%x, Data_234fd8f0.Data_23546124=0x%x\r\n",
				r0, Data_234fd8f0.Data_23546124);
		console_send_string(debug_string);
	}
#endif

	if (r0 == Data_234fd8f0.Data_23546124)
	{
		Data_235462e4.bData_235491e0++;
		//->loc_2340abe8
	}
	else
	{
		memset(&Data_234fd8f0.Data_23545948, 0xff, 2000);
	}
	//loc_2340abe8
	OSSemPost(channel_sema);

	return 0;
}


/* 2340add4 - todo */
int sub_2340add4(int r5)
{
	uint8_t err;
	uint32_t i;
	int res = 0; //r4
	int crc;

#if 0
	console_send_string("sub_2340add4 (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &err);

	flash_read(main_hFlash, r5, 0x489f4, &Data_234fd8f0); //234fd8f0 + 489f4 = 235462E4

	crc = crc32((void*) &Data_234fd8f0.arChannels[0], sizeof(Channel) * CHANNELS_MAX_NUM);
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2340add4: Data_234fd8f0.dwCrcChannels=0x%x, crc=0x%x\r\n",
				Data_234fd8f0.dwCrcChannels, crc);
		console_send_string(debug_string);
	}
#endif
	if (crc != Data_234fd8f0.dwCrcChannels)
	{
		res = 7;
		//->loc_2340ae9c
	}
	else
	{
		Data_23492004 = (Data_234fd8f0.Data_235441b0.Data_0x10/*Data_235441c0*/ << 17) >> 31;

		crc = crc32((void*) &Data_234fd8f0.arTransponders, sizeof(Transponder) * TRANSPONDERS_MAX_NUM);
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2340add4: Data_234fd8f0.dwCrcTransponders=0x%x, crc=0x%x\r\n",
					Data_234fd8f0.dwCrcTransponders, crc);
			console_send_string(debug_string);
		}
#endif
		if (crc != Data_234fd8f0.dwCrcTransponders)
		{
			//->loc_2340ae6c
			res = 7;
		}

		crc = crc32((void*) &Data_234fd8f0.Data_23543df0, 0x3c0);
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2340add4: Data_234fd8f0.Data_235441d4=0x%x, crc=0x%x\r\n",
					Data_234fd8f0.Data_235441d4, crc);
			console_send_string(debug_string);
		}
#endif
		if (crc != Data_234fd8f0.Data_235441d4)
		{
			//loc_2340ae6c
			res = 7;
		}

		//loc_2340ae70
		for (i = 0; i < CHANNELS_MAX_NUM; i++)
		{
			//loc_2340ae80
			if (Data_234fd8f0.arChannels[i].Data_0.service_id == 0xffff)
			{
				break;
			}
		}
	}
	//loc_2340ae9c
	OSSemPost(channel_sema);

	return res;
}


/* 2340aeac /  / 2340d988 - todo */
int channel_clear_channel_list(void)
{
	uint8_t err;

#if 0
	console_send_string("channel_clear_channel_list (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &err);

	memset(&Data_234fd8f0.arChannels[0], 0xff, sizeof(Data_234fd8f0.arChannels));

	OSSemPost(channel_sema);

	return 0;
}


/* 2340aee4 - todo */
void sub_2340aee4()
{
	console_send_string("sub_2340aee4 (todo.c): TODO\r\n");

}


 /* 2340b22c / 2340d534 - todo */
int sub_2340b22c(int r4)
{
	uint8_t err; //sp_0x40
	Channel sp_0x18;
	struct Struct_234fd8f0_Inner0_Inner_0x10 sp;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2340b22c: r4=0x%x\r\n", r4);
		console_send_string(debug_string);
	}
#endif

	if (r4 == 0xff)
	{
		sub_2340ec54(Data_23491db8, 0);
		sub_2340ec54(main_hFrontend1, 0);
	}
	//loc_2340b260
	OSSemPend(channel_sema, 0, &err);

	if (err != OS_ERR_NONE)
	{
		return 0xff;
	}
	//0x2340b284
	if (r4 != 0)
	{
		if (Data_23492024 != 0)
		{
			(Data_23492024)();
		}

		if (r4 == 0x0f)
		{
			if (Data_23492020 != 0)
			{
				(Data_23492020)();
			}
		}
		//loc_2340b334
	} //if (r4 != 0)
	else
	{
		//loc_2340b2b0
		int r0 = Data_235462e4.arChannelIdx[ Data_235462e4.currentChannel ];

		//memcpy(&sp_0x18, &Data_234fd8f0.arChannels[r0], 0, 24);
		sp_0x18 = Data_234fd8f0.arChannels[r0];
//		sp = Data_234fd8f0.arChannels[r0].Data_0x10;

		//PES Parser (Audio, Video...)
		channel_start_pes(Data_234fd8f0.arChannels[r0]/*Data_234fd8f0.arChannels[r0].Data_0, Data_234fd8f0.arChannels[r0].Data_0x10*/);

		if (Data_2349201c != 0)
		{
			(Data_2349201c)(1);
		}
		//0x2340b304
		//Section Filter (EIT...)
		psi_start_for_service(main_hPSIDecoder1, sp_0x18.Data_0.service_id, 
			PSI_MASK_NIT | PSI_MASK_EIT | PSI_MASK_TDT |
			PSI_MASK_PAT | PSI_MASK_PMT | PSI_MASK_CAT | 0x08, //0x7f, 
			channel_on_psi_data);

		Data_235462e4.activeStreamMask |= CHANNEL_ACTIVE_STREAM_PSI;

		Data_23492024 = channel_stop;
	}
	//loc_2340b334
	OSSemPost(channel_sema);

	return 0;
}


/* 2340b348 - todo */
int sub_2340b348(uint8_t r6, Transponder* r5)
{
	uint8_t sp;

#if 0
	console_send_string("sub_2340b348 (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &sp);

	if (sp == 0)
	{
		if (r5 != 0)
		{
			Data_234fd8f0.arTransponders[
					Data_234fd8f0.arChannels[
							Data_235462e4.arChannelIdx[ Data_235462e4.currentChannel ] ].Data_0.wData_4 ] = *r5;
		}
		//loc_2340b3b8
		OSSemPost(channel_sema);
	}
	//loc_2340b3c0
	return sub_2340b22c(r6);
}


/* 2340b3cc - todo */
void sub_2340b3cc()
{
	console_send_string("sub_2340b3cc (todo.c): TODO\r\n");

}


/* 2340b55c - todo */
int sub_2340b55c()
{
	Channel sp_0x2c;
	Transponder sp_0x14;

#if 1
	console_send_string("sub_2340b55c (todo.c): TODO\r\n");
#endif

	Struct_2354dd70* r4 = 0;

	if (Data_23492024 != 0)
	{
		(Data_23492024)();
	}

	int r5 = Data_235462e4.currentChannel;

	sp_0x2c = Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[ r5 ] ];

	sp_0x14 = Data_234fd8f0.arTransponders[ sp_0x2c.Data_0.wData_4 ];

	Data_235462e4.wData_235491d2 = 0;

	//Send the channel number to the av module
	sub_23410f64(r5, Data_235462e4.currentChList);

	if ((sp_0x2c.Data_0.wData_6 >> 15) != 0)
	{
		//->loc_2340b67c
		return 0xff;
	}
	//0x2340b5ec
	r5 = 0xffff;
	if (sp_0x2c.Data_0.wData_4 == /*0xffff*/r5)
	{
		//0x2340b604
		sub_2340ec54(Data_23491db8, 0);
		sub_2340ec54(main_hFrontend1, 0);

		sub_2345d710(/*0xffff*/r5 & (*((int*)&sp_0x2c.Data_0.wPcrPID)>>16)); //TODO!!!

		Data_23492024 = sub_23459188;
		//->loc_2340b678
	}
	else
	{
		//loc_2340b634
		if (sp_0x14.bData_0x16 == 0)
		{
			r4 = main_hFrontend1;
		}
		else if (sp_0x14.bData_0x16 == 1)
		{
			r4 = Data_23491db8;
		}
		//loc_2340b64c

		fe_manager_tune(r4, sp_0x14, sub_2340b348, 0);
	}
	//loc_2340b678
	return 0;
}

#if 0

/* 2340b684 / 2340d98c - todo */
void sub_2340b684(Struct_234a73e8* a)
{
#if 0
	console_send_string("sub_2340b684 (todo.c): TODO\r\n");
#endif

	uint16_t sp_0x48;
	struct Struct_234a73e8_Inner_0x248* sp_0x44;
	Channel sp_0x1c;

	int r0 = psi_get_all_current_programs(a, &sp_0x48, &sp_0x44);
	if (r0 != 0)
	{
		//->loc_2340b744
		return;
	}

	if (sp_0x48 == 0)
	{
		//->loc_2340b744
		return;
	}

	for (uint16_t i = 0; i < sp_0x48; i++)
	{
		//loc_2340b6c4
		if (sp_0x44[i].pat_program_number == Data_235462e4.wData_235491d2)
		{
			sp_0x1c.Data_0x10.service_name[0] = 'D';
			sp_0x1c.Data_0x10.service_name[1] = 'A';
			sp_0x1c.Data_0x10.service_name[2] = 'T';
			sp_0x1c.Data_0x10.service_name[3] = 'A';
			sp_0x1c.Data_0x10.service_name[4] = 0;

			memcpy(&sp_0x1c.Data_0.wPcrPID, &sp_0x44[i].wPcrPID, 12);

			sp_0x1c.Data_0.wFlags_2 = sp_0x44[i].bData_0;

			channel_start_pes(sp_0x1c);

			Data_23492024 = channel_stop;
			//->loc_2340b744
			break;
		}
		//loc_2340b74c
	} //for (uint16_t r0 = 0; r0 < r3; r0++)
	//->loc_2340b744
	return;
}


/* 2340baf0 / 2340dd80 - todo */
int sub_2340baf0(int r7)
{
#if 0
	console_send_string("sub_2340baf0 (todo.c): TODO\r\n");
#endif

	uint8_t sp;

	OSSemPend(channel_sema, 0, &sp);

	if (sp != 0)
	{
		return 0xff;
	}

	if (r7 != 0)
	{
		channel_stop_pes();

		if (Data_2349201c != 0)
		{
			(Data_2349201c)(0);
		}

		psi_stop(main_hPSIDecoder1, 1);

		Data_235462e4.activeStreamMask &= ~CHANNEL_ACTIVE_STREAM_PSI;

		if (r7 == 0x0f)
		{
			if (Data_23492020 != 0)
			{
				(Data_23492020)();
			}
		}
	}
	else
	{
		if (Data_2349201c != 0)
		{
			(Data_2349201c)(1);
		}

		psi_start_for_service(main_hPSIDecoder1, Data_235462e4.wData_235491d2, 0x3f, sub_2340b684);

		Data_235462e4.activeStreamMask |= CHANNEL_ACTIVE_STREAM_PSI;
	}

	OSSemPost(channel_sema);

	return 0;
}

#endif

/* 2340bc38 / 2340dec4 - todo */
int channel_next()
{
	uint8_t sp;
	uint16_t r4 = 6000;

#if 0
	console_send_string("channel_next (todo.c): TODO\r\n");
#endif

	sub_2340ec54(Data_23491db8, 0);
	sub_2340ec54(main_hFrontend1, 0);

	OSSemPend(channel_sema, 5, &sp);

	if (sp == 0)
	{
		//0x2340bc80
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "channel_next: Data_235462e4.numChannels=%d, Data_235462e4.currentChannel=%d\r\n",
					Data_235462e4.numChannels, Data_235462e4.currentChannel);
			console_send_string(debug_string);
		}
#endif
		if (Data_235462e4.numChannels != 0)
		{
			//0x2340bc90
			//r5 = 235462E4
			Data_235462e4.prevChannel = Data_235462e4.currentChannel;

			while (1)
			{
				//loc_2340bca0
				Data_235462e4.currentChannel++;

				if (Data_235462e4.currentChannel >= Data_235462e4.numChannels)
				{
					Data_235462e4.currentChannel = 0;
				}

				if (r4-- == 0)
				{
					//->loc_2340bcd8
					break;
				}

				if (0 == (Data_23492014)())
				{
					//->loc_2340bcd8
					break;
				}
				//->loc_2340bca0
			} //while (1)
		}
		//loc_2340bcd8
		OSSemPost(channel_sema);
	}
	//loc_2340bce0
	return 0;
}


/* 2340bd30 / 2340dfb8 - todo */
int channel_prev()
{
	uint8_t sp;
	uint16_t r4 = 6000;

#if 0
	console_send_string("channel_prev (todo.c): TODO\r\n");
#endif

	sub_2340ec54(Data_23491db8, 0);
	sub_2340ec54(main_hFrontend1, 0);

	OSSemPend(channel_sema, 5, &sp);

	if (sp == 0)
	{
		if (Data_235462e4.numChannels != 0)
		{
			Data_235462e4.prevChannel = Data_235462e4.currentChannel;

			while (1)
			{
				//loc_2340bd98
				Data_235462e4.currentChannel--;

				if (Data_235462e4.currentChannel < 0)
				{
					if (Data_235462e4.numChannels != 0)
					{
						Data_235462e4.currentChannel = Data_235462e4.numChannels - 1;
					}
					else
					{
						Data_235462e4.currentChannel = 0;
					}
				}
				//loc_2340bdbc
				if (r4-- == 0)
				{
					//->loc_2340bddc
					break;
				}

				if (0 == (Data_23492014)())
				{
					//->loc_2340bddc
					break;
				}
				//->loc_2340bd98
			} //while (1)
		}
		//loc_2340bddc
		OSSemPost(channel_sema);
	}
	//loc_2340bde4
	return 0;
}


/* 2340bdec / 2340e074 - todo */
uint16_t channel_swap()
{
	uint8_t sp;

#if 0
	console_send_string("channel_swap (todo.c): TODO\r\n");
#endif

	sub_2340ec54(Data_23491db8, 0);
	sub_2340ec54(main_hFrontend1, 0);

	OSSemPend(channel_sema, 5, &sp);

	int r1 = Data_235462e4.prevChannel;
	Data_235462e4.prevChannel = (uint16_t) Data_235462e4.currentChannel;
	Data_235462e4.currentChannel = r1;

	(Data_23492014)();

	OSSemPost(channel_sema);

	return Data_235462e4.currentChannel;
}


/* 2340be58 / 2340e0e0 - todo */
void channel_start_number(Channel* r8, uint32_t channelNr)
{
	uint8_t sp;

#if 0
	console_send_string("channel_start_number (todo.c): TODO\r\n");
#endif

	sub_2340ec54(Data_23491db8, 0);
	sub_2340ec54(main_hFrontend1, 0);

	OSSemPend(channel_sema, 0, &sp);

	Channel* r4 = &Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[channelNr] ];

	if ((r4->Data_0.service_id != 0xfffe) &&
			(channelNr < Data_235462e4.numChannels))
	{
		//0x2340becc
		int r7 = r4->Data_0.wData_6;
		int old = Data_235462e4.currentChannel;

		Data_235462e4.currentChannel = channelNr;
		Data_235462e4.prevChannel = old;

		r4->Data_0.wData_6 = 0;

		(Data_23492014)();

		r4->Data_0.wData_6 = r7;
	}
	//loc_2340bef0
	OSSemPost(channel_sema);

	memcpy(r8, r4, 40);
}


/* 2340bf0c / 2340e194 - todo */
void sub_2340bf0c(Struct_2340bf0c* r6)
{
	Struct_2340bf0c sp4;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_2340bf0c (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	int r4 = Data_235462e4.currentChannel;

	sp4.Data_0 = Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[r4] ];
	sp4.wCurrentChannel = r4;
	sp4.wNumChannels = Data_235462e4.numChannels;
	sp4.bData_0x30 = Data_235462e4.currentChList;
	sp4.bData_0x31 = Data_235462e4.bData_235491dc;
	sp4.wData_0x2c = Data_235462e4.wData_235491d2;

	OS_EXIT_CRITICAL();

	*r6 = sp4;
}


/* 2340bf94 / 2340e21c - todo */
void sub_2340bf94(int r7, Channel* pChannel, Transponder* pTransponder)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_2340bf94 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	*pChannel = Data_234fd8f0.arChannels[ Data_235462e4.arChannelIdx[r7] ];

	if (pChannel->Data_0.wData_4 == 0xffff)
	{
		memset(pTransponder, 0xff, sizeof(Transponder));
	}
	else
	{
		//loc_2340bff4
		*pTransponder = Data_234fd8f0.arTransponders[pChannel->Data_0.wData_4];
	}
#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2340bf94: r7=%d, pChannel->Data_0.service_id=%d, pChannel->Data_0.wData_4=%d, pTransponder->Data_0.Data_4=%d\r\n",
				r7, pChannel->Data_0.service_id, pChannel->Data_0.wData_4, pTransponder->Data_0.Data_4);
		console_send_string(debug_string);
	}
#endif
	//loc_2340c010
	OS_EXIT_CRITICAL();
}


/* 2340c01c / 2340e43c - todo */
int sub_2340c01c(int r5, int r7)
{
	uint8_t err; //sp
	int r4;

#if 0
	console_send_string("sub_2340c01c (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &err);

	if (r5 != 0)
	{
		Data_23492000 = 0;

		uint8_t r5 = Data_235462e4.bData_235491df;

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2340c01c: r7=%d, r5=%d\r\n",
					r7, r5);
			console_send_string(debug_string);
		}
#endif

		if (r7 > 0)
		{
			//0x2340c05c
			if (r5 == 32)
			{
				//->loc_2340c070
				OSSemPost(channel_sema);

				return r5;
			}
			//loc_2340c080
		}
		else
		{
			//loc_2340c068
			if (r5 == 0)
			{
				//loc_2340c070
				OSSemPost(channel_sema);

				return r5;
			}
			//loc_2340c080
		}
		//loc_2340c080
		Data_235462e4.bData_235491df += r7;

		if (Data_235462e4.bData_235491df > 32)
		{
			Data_235462e4.bData_235491df = 32;
		}

		auout_set_volume(main_hAuOut, 8, Data_23488068[Data_235462e4.bData_235491df]);

		if (Data_23492030 != 0)
		{
			(Data_23492030)(Data_235462e4.bData_235491df);
		}
	}
	//loc_2340c0c8
	r4 = Data_235462e4.bData_235491df;

	OSSemPost(channel_sema);

	return r4;
}


/* 2340c0dc - todo */
void sub_2340c0dc()
{
	LastMode sp;
	uint32_t crc;

	if (Data_235462e4.numChannels != 0)
	{
		sub_23438084(Data_23491dc8, &sp, 0, sizeof(sp));

		crc = sp.crc;
		sp.crc = 0; //r7

		uint32_t r0 = crc32(&sp, sizeof(sp));

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2340c0dc: crc check r0=0x%x, crc=0x%x\r\n", r0, crc);
			console_send_string(debug_string);
		}
#endif

		if (r0 == crc)
		{
			sp.currentChannel = Data_235462e4.currentChannel;
			sp.prevChannel = Data_235462e4.prevChannel;
			sp.wData_8 = Data_235462e4.wData_235491d4;
			sp.wData_10 = Data_235462e4.wData_235491d6;
			sp.bData_12 = Data_235462e4.bData_235491dc;
			sp.currentChList = Data_235462e4.currentChList;

			sp.bData_15 = sub_2340c01c(0, 0);

			sp.crc = 0;
			sp.crc = crc32(&sp, sizeof(sp));

			sub_23438108(Data_23491dc8, &sp, 0, sizeof(sp));
		}
	}
	//loc_2340c198
}


/* 2340c19c - complete */
void sub_2340c19c(int channelIdx, Channel* pChannel, Transponder* pTransponder)
{
	uint8_t err;

#if 0
	console_send_string("sub_2340c19c (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &err);

	*pChannel = Data_234fd8f0.arChannels[channelIdx];

	*pTransponder = Data_234fd8f0.arTransponders[pChannel->Data_0.wData_4];

	OSSemPost(channel_sema);
}


/* 2340c204 - todo */
void sub_2340c204(int a)
{
#if 1
	console_send_string("sub_2340c204 (todo.c): TODO\r\n");
#endif

}


/* 2340c368 - complete */
int sub_2340c368(int get, int* r4)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	OS_ENTER_CRITICAL();

	if (get != 0)
	{
		*r4 = Data_234fd8f0.Data_235462e0;
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2340c368: (get) *r4=%d\r\n", *r4);
			console_send_string(debug_string);
		}
	}
	else
	{
		Data_234fd8f0.Data_235462e0 = *r4;
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2340c368: (set) *r4=%d\r\n", *r4);
			console_send_string(debug_string);
		}
	}

	OS_EXIT_CRITICAL();

	return 0;
}


/* 2340c488 - todo */
uint16_t channel_get_transponder_list(uint16_t r6, Transponder list[], uint16_t maxNum)
{
	uint8_t err; //sp
	uint16_t i;
	uint16_t count = 0;

#if 0
	console_send_string("channel_get_transponder_list (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &err);

	for (i = 0; i < TRANSPONDERS_MAX_NUM; i++)
	{
		//loc_2340c4b8
		Transponder* pTransponder = &Data_234fd8f0.arTransponders[i];

		if (pTransponder->Data_0.frequency == -1)
		{
			//->loc_2340c510
			break;
		}

		if (pTransponder->Data_0.wData_0x0a == r6)
		{
			if (count >= maxNum)
			{
				//->loc_2340c510
				break;
			}
			//0x2340c4e8
			list[count++] = *pTransponder;
		}
		//loc_2340c500
	}
	//loc_2340c510
	OSSemPost(channel_sema);

	return count;
}


/* 2340c538 - todo */
int sub_2340c538(Struct_2340c538* r7)
{
	uint8_t err;
	uint16_t r4;
	Channel* pChannel;
	Transponder* sl;
	Transponder* r5 = r7->pTransponder;
	PSI_Program* r6 = r7->pPsiProgram;

#if 0
	console_send_string("sub_2340c538 (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &err);

	int transponderType = fe_manager_get_transponder_type(r5);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_2340c538: transponderType=%d\r\n", transponderType);
		console_send_string(debug_string);
	}
#endif

	if (transponderType == 0)
	{
		//0x2340c574
		console_send_string("sub_2340c538: transponderType=0: TODO!!!\r\n");
#if 0
		sl = 0;

		for (r4 = 0; r4 < 2000; r4++)
		{
			//loc_2340c57c
			uint32_t r0 = Data_234fd8f0.arTransponders[r4].Data_0.Data_0.Data_0;

			if (r0 == 0xffffffff)
			{
				//0x2340c594
				sl = &Data_234fd8f0.arTransponders[r4];
				*sl = *r5;
				//->loc_2340c63c
				break;
			}
			//loc_2340c5b8
			uint32_t ip = r5->Data_0.Data_0.Data_0;

			if (ip > (r0 - 2000))
			{
				//0x2340c5c8: TODO!!!
				r0 += 2000;
				if ((ip < r0) ||
					(Data_234fd8f0.arTransponders[r4].Data_0.symbol_rate == r5->Data_0.symbol_rate) ||
					(Data_234fd8f0.arTransponders[r4].transport_stream_id == r5->transport_stream_id) ||
					(Data_234fd8f0.arTransponders[r4].Data_0.wData_0x0a == r5->Data_0.wData_0x0a))
					{
						//0x2340c604
						sl = &Data_234fd8f0.arTransponders[r4];

						if (Data_234fd8f0.arTransponders[r4].Data_0.frequency != r5->Data_0.frequency)
						{
							Data_234fd8f0.arTransponders[r4].Data_0.frequency = r5->Data_0.frequency;
						}
						//->loc_2340c63c
						break;
					}
			}
			//loc_2340c62c
		} //for (r4 = 0; r4 < 2000; r4++)
		//loc_2340c63c
		if (sl == 0)
		{
			//->loc_2340c7b0
			OSSemPost(channel_sema);

			return 0xff;
		}
		//loc_2340c798

		//TODO
#endif
	} //if (transponderType == 0)
	//loc_2340c648
	else if (transponderType == 2)
	{
		//0x2340c650
		console_send_string("sub_2340c538: transponderType=2: TODO!!!\r\n");
#if 0
		r4 = 0;
		int r0 = 0;

		while (r4 < 2000)
		{
			//loc_2340c65c

		} //while (r4 < 2000)
		//loc_2340c6a8
		if (r0 == 0)
		{
			//->loc_2340c7b0
			OSSemPost(channel_sema);

			return 0xff;
		}
		//loc_2340c798

		//TODO
#endif
	} //else if (transponderType == 2)
	//loc_2340c6b4
	else if (transponderType == 1)
	{
		//0x2340c6bc
		r4 = 0; 
		Transponder* sl = 0;

		while (r4 < 2000)
		{
			//loc_2340c6c4
			uint32_t r0 = Data_234fd8f0.arTransponders[r4].Data_0.frequency;
			if (r0 == 0xffffffff)
			{
				sl = &Data_234fd8f0.arTransponders[r4];
				//->loc_2340c74c
				*r5 = *sl;
				//->loc_2340c770
				break;
			}
			else
			{
				//0x2340c6ec
				if ((Data_234fd8f0.arTransponders[r4].Data_0.wData_0x0a == 0xffff) &&
					(r5->Data_0.frequency > (r0 - 25001) &&
					(r5->Data_0.frequency < (r0 + 25001))))
				{
					sl = &Data_234fd8f0.arTransponders[r4];

					if (0 != memcmp(sl, r5, sizeof(Transponder)))
					{
						//loc_2340c74c
						*r5 = *sl;
					}
					//loc_2340c770
					break;
				}
			}
			//loc_2340c760
			r4++;
		} //while (r4 < 2000)
		//loc_2340c770
		if (sl == 0)
		{
			//->loc_2340c7b0
			//loc_2340c7b0
			OSSemPost(channel_sema);
			return 0xff;
		}
		//0x2340c774
		sl->transport_stream_id = r6->transport_stream_id;
		sl->original_network_id = r6->original_network_id;
		//->loc_2340c798
	}
	//loc_2340c78c
	else if (transponderType == 3)
	{
		//0x2340c794
		console_send_string("sub_2340c538: transponderType=3: TODO!!!\r\n");
#if 0
		r4 = 0xffff; //sb
		//loc_2340c798
#endif
	}
	else
	{
		//loc_2340c7b0
		OSSemPost(channel_sema);
		return 0xff;
	}
	//loc_2340c798
	r7->wData_12 = 0; //r3
	pChannel = &Data_234fd8f0.arChannels[0];
	uint16_t r0_ = 0; //r3

	while (r0_ < 5999)
	{
		//loc_2340c7c0
		if (pChannel->Data_0.wFlags_2 == 0xffff)
		{
			pChannel->Data_0.wFlags_2 = r6->bData_0 | (1 << 7);
			pChannel->Data_0.wData_6 = 0; //r3
			pChannel->Data_0.service_id = r6->pat_program_number;
			pChannel->Data_0.wData_4 = r4;

			memcpy(&pChannel->Data_0.wPcrPID, &r6->wPcrPID, 12);

			if (r6->service_name == 0)
			{
				//0x2340c804
				sprintf(&pChannel->Data_0x10.service_name[0], "SID %d", 
					pChannel->Data_0.service_id);
			}
			else
			{
				//loc_2340c818
				memcpy(&pChannel->Data_0x10.service_name[0], r6->service_name, 
					sizeof(pChannel->Data_0x10.service_name));
			}
			//loc_2340c824
			memset(pChannel + 1, 0xff, sizeof(Channel));

			OSSemPost(channel_sema);

			return 0;
		}
		//loc_2340c844
		if ((pChannel->Data_0.service_id == r6->pat_program_number) &&
			(pChannel->Data_0.wData_4 == r4))
		{
			//0x2340c85c
			pChannel->Data_0.wData_6 &= ~(1 << 14);

			OSSemPost(channel_sema);

			return 4;
		}
		//loc_2340c878
		r7->wData_12++;
		pChannel++;
		r0_++;
	}
	//0x2340c898
	OSSemPost(channel_sema);

	return 5;
}


/* 2340c8a8 - todo */
void sub_2340c8a8()
{
	console_send_string("sub_2340c8a8 (todo.c): TODO\r\n");

}


/* 2340c970 - complete */
int sub_2340c970(int get, Struct_235441b0* r6)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_2340c970 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	if (get != 0)
	{
		memcpy(r6, &Data_234fd8f0.Data_235441b0, 28);
	}
	else
	{
		memcpy(&Data_234fd8f0.Data_235441b0, r6, 28);
	}

	OS_EXIT_CRITICAL();

	return 0;
}

#if 0

/* 2340c9b0 - complete */
int sub_2340c9b0(int get, struct Struct_23546128* r4)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_2340c9b0 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	if (get != 0)
	{
		*r4 = Data_234fd8f0.Data_23546128;
	}
	else
	{
		Data_234fd8f0.Data_23546128 = *r4;
	}

	OS_EXIT_CRITICAL();

	return 0;
}

^
/* 2340ca1c - complete */
int sub_2340ca1c(int r4, struct Struct_234fd8f0_Inner_489DC* r6)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_2340ca1c (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	if (r4 != 0)
	{
		memcpy(r6, &Data_234fd8f0.Data_235462cc, 20);
	}
	else
	{
		memcpy(&Data_234fd8f0.Data_235462cc, r6, 20);
	}

	OS_EXIT_CRITICAL();

	return 0;
}

#endif

/* 2340ca5c - todo */
int sub_2340ca5c(int get, void* r6)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_2340ca5c (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	if (get != 0)
	{
		memcpy(r6, &Data_234fd8f0.Data_2354613c, 32);
	}
	else
	{
		memcpy(&Data_234fd8f0.Data_2354613c, r6, 32);
	}

	OS_EXIT_CRITICAL();

	return 0;
}


/* 2340caf0 - complete */
int channel_switch_lists(void)
{
#if 0
	console_send_string("channel_switch_lists (todo.c): TODO\r\n");
#endif

	uint8_t sp;

	sub_2340ec54(Data_23491db8, 0);
	sub_2340ec54(main_hFrontend1, 0);

	OSSemPend(channel_sema, 0, &sp);

	if (Data_235462e4.currentChList == 1)
	{
		Data_235462e4.currentChList = 0;
		Data_235462e4.wData_235491d4 = Data_235462e4.currentChannel;
		//->loc_2340cb70
		Data_235462e4.currentChannel = Data_235462e4.wData_235491d6;
	}
	else if (Data_235462e4.currentChList == 0)
	{
		Data_235462e4.currentChList = 1;
		Data_235462e4.wData_235491d6 = Data_235462e4.currentChannel;
		Data_235462e4.currentChannel = Data_235462e4.wData_235491d4;
	}
	else
	{
		//loc_2340cbac
		OSSemPost(channel_sema);

		return 0;
	}
	//0x2340cb74
	Data_235462e4.bData_235491dc = 1;

	sub_2340a71c();

	if (Data_235462e4.numChannels != 0)
	{
		(Data_23492014)();
	}

	if (Data_23492034 != 0)
	{
		(Data_23492034)(Data_235462e4.currentChList);
	}

	OSSemPost(channel_sema);

	return Data_235462e4.numChannels;
}

#if 0

/* 2340cbc4 - complete */
int channel_get_audio_pid()
{
#if 0
	console_send_string("channel_get_audio_pid (todo.c): TODO\r\n");
#endif

	uint8_t sp;
	int r4;

	OSSemPend(channel_sema, 0, &sp);

	r4 = Data_235462e4.wAudioPID;

	OSSemPost(channel_sema);

	return r4;
}


#if 1
/* 2340ce18 - todo */
void sub_2340ce18(Struct_2340ce18* r0)
{
	r0->Data_0 = main_hPESParserVideo;
	r0->Data_4 = main_hPESParserAudio;
}
#else
/* 2340ce18 - todo */
void sub_2340ce18(void** r0)
{
	r0[1] = main_hPESParserAudio;
	r0[0] = main_hPESParserVideo;
}
#endif


/* 2340ce30 / 2340f04c - todo */
int sub_2340ce30(Transponder* r4, uint16_t* r5)
{
#if 0
	console_send_string("sub_2340ce30 (todo.c): TODO\r\n");
#endif

	void* r6 = 0;
	uint8_t sp_0x18;

	sub_2340ec54(Data_23491db8, 0);
	sub_2340ec54(main_hFrontend1, 0);

	OSSemPend(channel_sema, 0, &sp_0x18);

	if (Data_23492024 != 0)
	{
		(Data_23492024)();
	}

	Data_235462e4.wData_235491d2 = *r5;

	sub_23410f64(Data_235462e4.currentChannel, Data_235462e4.currentChList);

	if (Data_23492014 == sub_2340b55c)
	{
		if (r4->bData_0x16 == 0)
		{
			r6 = main_hFrontend1;
		}
		else if (r4->bData_0x16 == 1)
		{
			r6 = Data_23491db8;
		}

		fe_manager_tune(r6, *r4, sub_2340baf0, 0);
	}
	else
	{
		//loc_2340cf08
		fe_manager_tune(Data_23491db8, *r4, 0, 0);

		fe_manager_tune(main_hFrontend1, *r4, sub_2340baf0, 0);
	}

	OSSemPost(channel_sema);

	return 0;
}

#endif

/* 2340d0d0 - todo */
int sub_2340d0d0()
{
#if 0
	console_send_string("sub_2340d0d0 (todo.c): TODO\r\n");
#endif

	if (Data_23492014 == sub_2340b3cc)
	{
		return 1;
	}

	return 0;
}


/* 2340d1c8 / 2340f3b8 - todo */
void channel_set_psi_data_callback(void (*r5)())
{
	uint8_t err;

#if 0
	console_send_string("channel_set_psi_data_callback (todo.c): TODO\r\n");
#endif

	OSSemPend(channel_sema, 0, &err);

	channel_pfPSIDataCallback = r5;

	OSSemPost(channel_sema);
}


/* 2340d1f4 - complete */
int sub_2340d1f4(int r7, Struct_2340d1f4* r4)
{
	int res = 0;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_2340d1f4 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	if (r7 != 0)
	{
		//0x2340d230
		r4->Data_0 = Data_234fd8f0.Data_2354615c;

		memcpy(&r4->Data_4[0], &Data_234fd8f0.Data_23546160[0], 9 * sizeof(struct Struct_2340d1f4_Inner_4));
		memcpy(&r4->Data_0xb8[0], &Data_234fd8f0.Data_23546214[0], 9 * sizeof(struct Struct_2340d1f4_Inner_0xb8));

		r4->bData_16c = Data_234fd8f0.bData_235462c8;
		r4->bData_16d = Data_234fd8f0.bData_235462c9;
		r4->bData_16e = 0; //r8
		r4->bData_16f = 0; //r8
		//->loc_2340d2bc
	} //if (r7 != 0)
	else
	{
		//loc_2340d274
		if (r4 != 0)
		{
			//0x2340d27c
			memcpy(&Data_234fd8f0.Data_23546160[0], &r4->Data_4[0], 9 * sizeof(struct Struct_2340d1f4_Inner_4));
			memcpy(&Data_234fd8f0.Data_23546214[0], &r4->Data_0xb8[0], 9 * sizeof(struct Struct_2340d1f4_Inner_0xb8));

			Data_234fd8f0.bData_235462c8 = r4->bData_16c;
			Data_234fd8f0.bData_235462c9 = r4->bData_16d;
			Data_234fd8f0.bData_235462ca = 0; //r8
			Data_234fd8f0.bData_235462cb = 0; //r8

			int r0 = crc32((void*) &Data_234fd8f0.Data_2354615c, sizeof(uint32_t));
		}
		//loc_2340d2bc
	}

	OS_EXIT_CRITICAL();

	return res;
}


/* 2340d300 - complete */
void sub_2340d300()
{
	uint8_t err;

#if 0
	console_send_string("sub_2340d300 (todo.c): TODO\r\n");
#endif

	if (Data_23492050 != 0)
	{
		Data_23492050--;
	}
	else
	{
		Data_23492050 = 300;

		if (audec_get_status(main_hAudec2) == -1)
		{
			sub_2340ec54(Data_23491db8, 0);
			sub_2340ec54(main_hFrontend1, 0);

			OSSemPend(channel_sema, 0, &err);

#if 0
			int r5 = sub_23418bf0(); //->ts_play
#else
			int r5 = 0;
#endif

			if (Data_23492024 != 0)
			{
				(Data_23492024)();
			}

			sub_234297d8();

			sub_23400798();

			if (r5 == 0)
			{
				(Data_23492014)();
			}

			OSSemPost(channel_sema);
		}
	}
}


