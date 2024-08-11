
#include "data.h"
#include "ucos_ii.h"
#include "lwip/sockets.h"
#include "psi.h"


typedef struct
{
	int fill_0[3]; //0
	uint16_t fill_12; //12 = 0x0c
	struct Struct_2345b028_1_Inner14
	{
		uint16_t wPid; //0
		uint8_t bData_2; //2
		uint8_t fill_3; //3
		//4
	} arPackets[10]; //14 = 0x0e
	uint16_t fill_0x36; //0x36
	uint16_t wData_0x38; //0x38
	uint16_t fill_0x3a; //0x3a
	//0x3c
} Struct_2345b028_1;


uint8_t Data_237bfd6c[4000]; //237bfd6c +0xfa0 = 237C0D0C


//0x237c0d0c
struct
{
	int Data_0; //0
	int Data_237c0d10; //0x237c0d10 +4
	uint16_t wData_237c0d14; //237c0d14 +8
	int fill_12[3]; //12
	void* (*Data_237c0d24)(); //237c0d24 +0x18 = 24
	void (*Data_0x1c)(); //237C0D28 +0x1c = 28
	TSD_Handle** arhTsd; //237C0D2C +0x20
	int fill_0x24; //0x24
	Struct_2345b028_1 Data_237c0d34; //237c0d34 +0x28
	struct sockaddr_in Data_237c0d70; //237c0d70 +0x64

} Data_237c0d0c; //237c0d0c

#if 0

uint8_t bData_23493e7c; //23493e7c
#endif
int Data_23494094; //23494094


static void sub_2345ac74();
int sub_2345b29c(void);
int sub_2345b2b8(void);


/* 23459440 - todo */
int web_interface_start_streamout(int r5)
{
#if 0
	console_send_string("web_interface_start_streamout (todo.c): TODO\r\n");
#endif

#if 0
	struct sockaddr sp_0x4c0;
#else
	struct sockaddr_in sockaddr; //sp_0x4c0;
#endif
	Struct_2345b028_1 sp_0x484;
	PSI_Program sp_0xec; //r7
	socklen_t socklen; //sp_0xe8;
	struct
	{
		int fill_0[43]; //0
		uint16_t fill_0xac; //0xac
		uint16_t wData_0xae; //0xae
		int fill_0xb0[13]; //0xb0
		//0xe4
	} sp4;
	int r4 = 20;

	while (0 != sub_234066d0(main_hPSIDecoder1, &sp_0xec))
	{
		//loc_2345945c
		if (r4 == 0)
		{
			break;
		}
		r4--;
		rtos_task_wait(50);
	}
	//loc_23459484
	sub_23400530(&sp4, 0);

	if ((sp4.wData_0xae == 0x1830) && (sp_0xec.bData_0x394 != 0))
	{
		//->loc_23459620
		return 0xff;
	}
	//loc_234594b0
	//r4 = &sp_0x484;
	memset(&sp_0x484/*r4*/, 0, sizeof(sp_0x484));

	if (sp_0xec.pat_program_number != 0xffff)
	{
		int r0 = 1;

		sp_0x484.arPackets[0].bData_2/*bData_0x10*/ = 1;
		sp_0x484.arPackets[0].wPid/*wData_0xe*/ = 0x00; //PAT

		if (sp_0xec.bData_0 & 0x10)
		{
			//0x234594fc
			if (sp_0xec.wVideoPID/*r1*/ != 0)
			{
				//0x23459504
				//r0 = 7;
				//->loc_23459518
				r0 = 2;
				sp_0x484.arPackets[1].bData_2/*bData_0x14*/ = 7;
				sp_0x484.arPackets[1].wPid/*wData_0x12*/ = sp_0xec.wVideoPID;
			}
			//loc_23459528
		}
		else
		{
			//loc_2345950c
			if (sp_0xec.wVideoPID/*r1*/ != 0)
			{
				//0x23459514
				//r0 = 3;
				//loc_23459518
				r0 = 2;
				sp_0x484.arPackets[1].bData_2/*bData_0x14*/ = 3;
				sp_0x484.arPackets[1].wPid/*wData_0x12*/ = sp_0xec.wVideoPID;
			}
			//loc_23459528
		}
		//loc_23459528
		if (sp_0xec.wAudioPID != 0)
		{
			sp_0x484.arPackets[r0].bData_2/*bData_0x10*/ = 4;
			sp_0x484.arPackets[r0].wPid/*wData_0xe*/ = sp_0xec.wAudioPID;
			r0++;
		}

		if (sp_0xec.wData_0x338 != 0)
		{
			sp_0x484.arPackets[r0].bData_2/*bData_0x10*/ = 5;
			sp_0x484.arPackets[r0].wPid/*wData_0xe*/ = sp_0xec.wData_0x338;
			r0++;
		}
		//0x23459564
		if (sp_0xec.pmt_pid != 0)
		{
			sp_0x484.arPackets[r0].bData_2/*bData_0x10*/ = 6;
			sp_0x484.arPackets[r0].wPid/*wData_0xe*/ = sp_0xec.pmt_pid;
			r0++;
		}
		//0x23459580
		if ((sp_0xec.wPcrPID != sp_0xec.wVideoPID) &&
				(sp_0xec.wPcrPID != sp_0xec.wAudioPID) &&
				(sp_0xec.wPcrPID != sp_0xec.wData_0x338))
		{
			sp_0x484.arPackets[r0].bData_2/*bData_0x10*/ = 8;
			sp_0x484.arPackets[r0].wPid/*wData_0xe*/ = sp_0xec.wPcrPID;
		}
		//0x234595ac
		socklen = 0x10;

		lwip_getpeername(r5, (struct sockaddr *) &sockaddr, &socklen);

#if 0
		sockaddr.sa_family = 2;
		*((uint16_t*)(sockaddr.sa_data)) = lwip_htons(1234);
#else
		sockaddr.sin_family = 2;
		sockaddr.sin_port = lwip_htons(1234);
#endif

		if (0 == sub_2340d0d0())
		{
			//0x234595e8
			r0 = sub_234225f4();
			//->loc_234595fc
		}
		else
		{
			//loc_234595f0
			r0 = sub_234225f4();
			if (r0 != 2)
			{
				r0 = 1;
			}
		}
		//loc_234595fc
		sp_0x484.wData_0x38 = r0;

		sub_2345b028(&sp_0x484/*r4*/, sockaddr);
	} //if (sp_0xec.pat_program_number != 0xffff)
	//loc_2345961c
	return 0;
}


/* 23459628 - todo */
void web_interface_send_channel_list(int s, int iList)
{
#if 0
	console_send_string("web_interface_send_channel_list (todo.c): TODO\r\n");
#endif

	uint8_t strId[10]; //size???
	Struct_2340bf0c sp4;
	uint32_t i;
	int idx = 0;
	Channel* pChannel = &sub_2344f770()->arChannels[0];

	sub_2340bf0c(&sp4);

	int r8 = 0xffff;
	for (i = 0; i < 6000; i++, pChannel++)
	{
		//loc_23459654
		if (pChannel->wFlags_2 == r8)
		{
			//->loc_2345970c
			break;
		}
		//0x23459660
		if (((pChannel->wFlags_2 & (1 << 3)) >> 3) == iList)
		{
			//0x2345966c
			lwip_write(s, "<option value=\"", 0x0f);
			sprintf(strId, "%d", idx);
			lwip_write(s, strId, strlen(strId));

			if ((sp4.wCurrentChannel == idx) && (sp4.bCurrentChList == iList))
			{
				lwip_write(s, "\" selected >", 0x0c);
			}
			else
			{
				lwip_write(s, "\">", 0x02);
			}

			lwip_write(s, pChannel->service_name, strlen(pChannel->service_name));
			lwip_write(s, "</option>\r\n", 0x0b);

			idx++;
		}
		//loc_234596f8
	} //for (uint32_t i = 0; i < 6000; i++, pChannel++)
	//loc_2345970c
}


/* 23459714 - todo */
void sub_23459714(int s)
{
#if 0
	console_send_string("sub_23459714 (todo.c): TODO\r\n");
#endif

#if 0
	struct sockaddr sp_0x2c;
	struct Struct_23546128 sp_0x20;
	socklen_t sp_0x1c;

	sub_2340c9b0(1, &sp_0x20);

	sp_0x1c = 0x10;
	int r5 = sp_0x20.Data_0;

	lwip_getpeername(s, &sp_0x2c, &sp_0x1c);

	int r4 = *((uint32_t*)(&sp_0x2c.sa_data[2]));

	snprintf("<param name=\"src\" value=\"udp://192.168.018.105@192.168.018.103:1234\">\r\n",
			0x47, "<param name=\"src\" value=\"udp://%d.%d.%d.%d@%d.%d.%d.%d:1234\">\n\r",
			r5 & 0xff, (r5 >> 8) & 0xff, (r5 >> 16) & 0xff, (r5 >> 24) & 0xff,
			r4 & 0xff, (r4 >> 8) & 0xff, (r4 >> 16) & 0xff, (r4 >> 24) & 0xff);

	lwip_write(s, "<div class=\"right cont\">\r\n", 0x1a);
	lwip_write(s, "<fieldset>\r\n", 0x0c);
	lwip_write(s, "<legend>Aktueller Stream</legend>\r\n", 0x23);
	lwip_write(s, "<div style=\"text-align: right; width: 100%;\"><form action=\"ShowStream\"><input style=\"float: left;\" type=submit value=", 0x75);

	if (bData_23493e7c == 0)
	{
		lwip_write(s, "\"Anzeigen\"></form> </div>", 0x19);
		//->loc_234598e8
	}
	else
	{
		//0x234597fc
		lwip_write(s, "\"Verbergen\"></form> </div>", 0x1a);
		lwip_write(s, "<object classid=\"clsid:9BE31822-FDAD-461B-AD51-BE1D1C159921\" width=\"350\" height=\"280\">\r\n", 0x58);
		lwip_write(s, "<param name=\"src\" value=\"udp://192.168.018.105@192.168.018.103:1234\">\r\n",
				strlen("<param name=\"src\" value=\"udp://192.168.018.105@192.168.018.103:1234\">\r\n"));
		lwip_write(s, "<param name=\"autoplay\" value=\"true\">\r\n", 0x26);
		lwip_write(s, "<param name=\"Volume\" value=\"100\">\r\n", 0x23);
		lwip_write(s, "<object type=\"application/x-vlc-plugin\" width=\"350\" height=\"280\">\r\n", 0x43);
		lwip_write(s, "<param name=\"src\" value=\"udp://192.168.018.105@192.168.018.103:1234\">\r\n",
				strlen("<param name=\"src\" value=\"udp://192.168.018.105@192.168.018.103:1234\">\r\n"));
		lwip_write(s, "<param name=\"autoplay\" value=\"true\">\r\n", 0x26);
		lwip_write(s, "<param name=\"Volume\" value=\"100\">\r\n", 0x23);

		snprintf("Das VLC-Plugin scheint nicht installiert zu sein.<br>Die Stream-Adresse lautet: UDP://@192.168.018.103:1234",
				0x8b, "Das VLC-Plugin scheint nicht installiert zu sein.<br>Die Stream-Adresse lautet: UDP://@%d.%d.%d.%d:1234",
				r4 & 0xff, (r4 >> 8) & 0xff, (r4 >> 16) & 0xff, (r4 >> 24) & 0xff); //r7, r6, r8);

		lwip_write(s, "Das VLC-Plugin scheint nicht installiert zu sein.<br>Die Stream-Adresse lautet: UDP://@192.168.018.103:1234",
				strlen("Das VLC-Plugin scheint nicht installiert zu sein.<br>Die Stream-Adresse lautet: UDP://@192.168.018.103:1234"));
		lwip_write(s, "</object>\r\n", 0x0b);
		lwip_write(s, "</object>\r\n", 0x0b);
	}
	//0x234598f0
	lwip_write(s, "</fieldset>\r\n", 0x0d);
	//0x23459900
	lwip_write(s, "<fieldset>\r\n", 0x0c);
	lwip_write(s, "<legend>Hinweis</legend>\r\n", 0x1a);

	snprintf("Das VLC-Plugin scheint nicht installiert zu sein.<br>Die Stream-Adresse lautet: UDP://@192.168.018.103:1234",
			0x8b, "Das VLC-Plugin scheint nicht installiert zu sein.<br>Die Stream-Adresse lautet: UDP://@%d.%d.%d.%d:1234",
			r4 & 0xff, (r4 >> 8) & 0xff, (r4 >> 16) & 0xff, (r4 >> 24) & 0xff); //r7, r6, r8);

	lwip_write(s, "Das VLC-Plugin scheint nicht installiert zu sein.<br>Die Stream-Adresse lautet: UDP://@192.168.018.103:1234",
			strlen("Das VLC-Plugin scheint nicht installiert zu sein.<br>Die Stream-Adresse lautet: UDP://@192.168.018.103:1234"));
	lwip_write(s, "</fieldset>\r\n", 0x0d);
	lwip_write(s, "</dev>\r\n", 0x08);
#endif
	//0x2345996c
	lwip_write(s, "</body>\r\n</html>", 0x10);
}


/* 23459a3c - todo */
void web_interface_send_response(int s, int sb, int sl, int fp)
{
#if 1
	console_send_string("web_interface_send_response (todo.c): TODO\r\n");
#endif

	Struct_2340bf0c sp_0x50;
	Channel sp_0x28;
	Transponder sp_0x10;

	sub_2340bf0c(&sp_0x50);

	uint8_t sp4[] = " disabled>";

	sub_2340bf94(sp_0x50.wCurrentChannel, &sp_0x28, &sp_0x10);
	//0x23459a78

	//TODO!!!

	//loc_23459b1c
	lwip_write(s, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", 0x2c);
	lwip_write(s, "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">\r\n", 0x68);
	lwip_write(s, "<html lang=\"de\">\r\n<head>\r\n<meta http-equiv=\"content-type\" content=\"text/html; charset=ISO-8859-1\">\r\n<meta http-equiv=\"content-style-type\" content=\"text/css\">\r\n<meta name=\"robots\" content=\"noindex,noarchive\">\r\n<title>Webinterface</title>\r\n", 0xee);
	lwip_write(s, "<style type=\"text/css\">\r\n", 0x19);
	lwip_write(s, "body {font: 100.01% sans-serif;}\r\ndiv {float: left; margin-right: 1em;}\r\ninput, select {margin-bottom: 1em; width: 9em;}\r\ninput {padding-left: 0.2em;}\r\n", 0x98);
	lwip_write(s, ".left {width: 12.3em;}\r\n.middle {width: 18em;}\r\n.right {width: 386px;}\r\n", 0x48);
	lwip_write(s, "h1 {color: #4CB9E6; text-shadow: black 0.07em 0.07em; font-size: 2.5em;}\r\nh2 {color: #4CB9E6; text-shadow: black 0.07em 0.07em; font-size: 1.5em; margin: 0; margin-bottom: 1em;}\r\n", 0xb3);
	lwip_write(s, "p {margin: 0.5em; font-weight: bold;}\r\n.red {color: red;}\r\n.green {color: green;}\r\n", 0x53);
	lwip_write(s, "fieldset {margin-bottom: 1em; padding: 1em 1em 0 1em; border: 2px solid; border-radius: 10px; text-align: center;}\r\n", 0x74);
	lwip_write(s, "label {float: left; margin-right: 0.5em; text-align: right; width: 7.5em;}\r\n", 0x4c);
	lwip_write(s, "legend {border: 1px solid; border-radius: 5px; font-weight: bold; text-align: left; background-color: #B0E0E6; padding: 0.1em 1em 0.1em 1em;}\r\n", 0x8f);
	lwip_write(s, "object {margin-bottom: 16px;}\r\n", 0x1f);
	lwip_write(s, "</style>\r\n", 0x0a);

	lwip_write(s, "<!--[if IE 8]>\r\n", 0x10);
	lwip_write(s, "<style type=\"text/css\">\r\n", 0x19);
	lwip_write(s, "fieldset {padding-top: 0;}\r\nlegend {margin-bottom: 1em;}\r\n", 0x3a);
	lwip_write(s, "</style>\r\n", 0x0a);
	lwip_write(s, "<![endif]-->\r\n", 0x0e);

	lwip_write(s, "<!--[if lte IE 7]>\r\n", 0x14);
	lwip_write(s, "<style type=\"text/css\">\r\n", 0x19);
	lwip_write(s, "input, select {margin: 0; display: block;}\r\nfieldset {margin-bottom: 0.2em;}\r\nlegend {display: inline;}\r\ndiv fieldset div {margin: 1em 0 1em 0;}\r\n", 0x92);
	lwip_write(s, "</style>\r\n", 0x0a);
	lwip_write(s, "<![endif]-->\r\n", 0x0e);
	//0x23459c88
	lwip_write(s, "</head>\r\n<body>\r\n", 0x11);
	lwip_write(s, "<h1>Webinterface V11-01-20</h1>\r\n", 0x21);

	lwip_write(s, "<div class=\"left cont\">\r\n", 0x19);

	lwip_write(s, "<fieldset>\r\n", 0x0c);
	lwip_write(s, "<legend>PC -&gt; Receiver</legend>\r\n", 0x24);
	lwip_write(s, "<form action=\"StreamIn\"><input type=submit value=\"Start Stream\">",
			strlen("<form action=\"StreamIn\"><input type=submit value=\"Start Stream\">"));
	lwip_write(s, "</form>\r\n", 0x09);
	lwip_write(s, "<form action=\"StopStreamIn\"><input type=submit value=\"Stop Stream\" disabled>",
			strlen("<form action=\"StopStreamIn\"><input type=submit value=\"Stop Stream\" disabled>"));
	lwip_write(s, "</form>\r\n", 0x09);
	lwip_write(s, "</fieldset>\r\n", 0x0d);

	lwip_write(s, "<fieldset>\r\n", 0x0c);
	lwip_write(s, "<legend>Receiver -&gt; PC</legend>\r\n", 0x24);
	lwip_write(s, "<form action=\"StreamOut\"><input type=submit value=\"Start Stream\">",
			strlen("<form action=\"StreamOut\"><input type=submit value=\"Start Stream\">"));
	lwip_write(s, "</form>\r\n", 0x09);
	lwip_write(s, "<form action=\"StopStreamOut\"><input type=submit value=\"Stop Stream\" disabled>",
			strlen("<form action=\"StopStreamOut\"><input type=submit value=\"Stop Stream\" disabled>"));
	lwip_write(s, "</form>\r\n", 0x09);
	lwip_write(s, "</fieldset>\r\n", 0x0d);
	//0x23459dbc
	lwip_write(s, "<fieldset>\r\n", 0x0c);
	lwip_write(s, "<legend>TV-Liste</legend>\r\n", 0x1b);
	lwip_write(s, "<form action=\"list\">\r\n", 0x16);
	//->loc_23459e80
	lwip_write(s, "<select name=\"program\" title=\"TV-List\">\r\n", 0x29);
	web_interface_send_channel_list(s, 1);
	lwip_write(s, "</select><br>\r\n", 0x0f);
	lwip_write(s, "<input type=submit value=\"Start\">\r\n", 0x23);
	lwip_write(s, "</form>\r\n", 0x09);
	lwip_write(s, "</fieldset>\r\n", 0x0d);
	//0x23459ed4
	lwip_write(s, "<fieldset>\r\n", 0x0c);
	lwip_write(s, "<legend>RADIO-Liste</legend>\r\n", 0x1e);
	lwip_write(s, "<form action=\"list_radio\">\r\n", 0x1c);
	lwip_write(s, "<select name=\"program\" title=\"RADIO-List\">\r\n", 0x2c);
	web_interface_send_channel_list(s, 0);
	lwip_write(s, "</select><br>\r\n", 0x0f);
	lwip_write(s, "<input type=submit value=\"Start\">\r\n", 0x23);
	lwip_write(s, "</form>\r\n", 0x09);
	lwip_write(s, "</fieldset>\r\n", 0x0d);
	//0x23459f60
	lwip_write(s, "<fieldset>\r\n", 0x0c);
	lwip_write(s, "<legend>Receiver</legend>\r\n", 0x1b);
	lwip_write(s, "<form action=\"channelup\"><input type=submit value=\"CH +\">", 0x39);
	lwip_write(s, "</form>\r\n", 0x09);
	lwip_write(s, "<form action=\"channeldown\"><input type=submit value=\"CH -\">", 0x3b);
	lwip_write(s, "</form>\r\n", 0x09);
	lwip_write(s, "<form action=\"record\"><input type=submit value=\"REC\" disabled>", 0x3e);
	lwip_write(s, "</form>\r\n", 0x09);
	lwip_write(s, "<form action=\"stop\"><input type=submit value=\"STOP\" disabled>", 0x3d);
	lwip_write(s, "</form>\r\n", 0x09);
	lwip_write(s, "</fieldset>\r\n", 0x0d);
	//0x2345a010
	lwip_write(s, "</div>\r\n", 0x08);

	lwip_write(s, "<div class=\"middle cont\">\r\n", 0x1b);

	lwip_write(s, "<fieldset>\r\n", 0x0c);
	lwip_write(s, "<legend>Status</legend>\r\n", 0x19);
	lwip_write(s, "<p><b style=\"text-transform: uppercase;\">", 0x29);
	lwip_write(s, sp_0x28.service_name, strlen(sp_0x28.service_name));
	lwip_write(s, "</b></p>\n", 0x09);
	//0x2345a08c
#if 0
	if (0 != sub_2343a150(0))
	{
		sub_23487af0(s, "<p>Speichermedium erkannt</p>", 0x1d);
	}

	if (0 != sub_23458874())
	{
		//0x2345a0b4
		lwip_write(s, "<p><span class=\"red\">", 0x15);
		lwip_write(s, "<p>Aufnahme l&auml;uft</p>", 0x1a);
		lwip_write(s, "</span></p>\r\n", 0x0d);
		lwip_write(s, "<p><span class=\"red\">", 0x15);
		lwip_write(s, "<p>Bedienung eingeschr&auml;nkt</p>", 0x23);
		lwip_write(s, "</span></p>\r\n", 0x0d);
	}
	//loc_2345a114
#endif
	if (sb != 0)
	{
		lwip_write(s, "<p>Streaming Receiver->PC aktiv</p>", 0x23);
		//->loc_2345a138
	}
	//0x2345a124
	else if (sl != 0)
	{
		lwip_write(s, "<p>Streaming PC->Receiver aktiv</p>", 0x23);
	}
	else
	{
		lwip_write(s, "<p>Streaming gestoppt</p>", 0x19);
	}
	//loc_2345a138
	if (fp != 0)
	{
		lwip_write(s, "<p><span class=\"red\">", 0x15);
		lwip_write(s, "<p>Funktion wird vom Sender nicht unterst&uuml;zt</p>", 0x35);
		lwip_write(s, "</span></p>\r\n", 0x0d);
	}
	//loc_2345a178
	lwip_write(s, "</fieldset>\r\n", 0x0d);
	lwip_write(s, "</div>\r\n", 0x08);
	//0x2345a198
	sub_23459714(s);
}


/* 2345a1a8 - todo */
void web_interface_decode_request(int r8, uint8_t sb[], int r2)
{
#if 1
	console_send_string("web_interface_decode_request (todo.c): TODO\r\n");
#endif

	Struct_2340bf0c sp_0x28;
    Channel sp;

	int r4; //bStreamingReceiver_PC
	int r5; //bStreamingPC_Receiver
	int r6 = 0;

	hex_dump("web_interface_decode_request", sb, r2);

	if ((r2 < 5) || (0 != strncmp(sb, "GET", 3)))
	{
		//loc_2345a42c
		return;
	}
	//0x2345a1dc
	r4 = sub_2345b29c();
	r5 = sub_2345b2b8();

	if (0 == strncmp(sb, "GET /channelup", 14))
	{
		channel_next();
		//->loc_2345a228
		r5 = 0;
		//->loc_2345a2ec
		r4 = 0;
		//->loc_2345a418
	}
	//loc_2345a20c
	else if (0 == strncmp(sb, "GET /channeldown", 16))
	{
		channel_prev();
		//loc_2345a228
		r5 = 0;
		//->loc_2345a2ec
		r4 = 0;
		//->loc_2345a418
	}
	//loc_2345a230
#if 0
	else if (0 == strncmp(sb, "GET /StreamIn", 13))
	{
		//0x2345a248
		if (0 == sub_23458874())
		{
			//0x2345a254
			sub_2345af48();

			r5 = 1;
		}
		//->loc_2345a418
	}
	//loc_2345a260
	else if (0 == strncmp(sb, "GET /StopStreamIn", 17))
	{
		//0x2345a278
		sub_2340bf0c(&sp_0x28);

		channel_start_number(&sp, sp_0x28.wData_0x2a, 0);

		r5 = 0;
		//->loc_2345a418
	}
#endif
	//loc_2345a298
	else if (0 == strncmp(sb, "GET /StreamOut", 14))
	{
		//0x2345a2b0
		if (0 == sub_23458874())
		{
			//0x2345a2bc
			r6 = web_interface_start_streamout(r8);
			if (r6 == 0)
			{
				r4 = 1;
			}
		}
		//loc_2345a418
	}
	//loc_2345a2d0
	else if (0 == strncmp(sb, "GET /StopStreamOut", 18))
	{
		//0x2345a2e8
		web_interface_stop_streamout();
		//loc_2345a2ec
		r4 = 0;
		//->loc_2345a418
	}
	//loc_2345a2f4
	//r7, #0xa
	else if (0 == strncmp(sb, "GET /list_radio", 15))
	{
		//0x2345a310
		uint8_t* digit = sb + sizeof("GET /list_radio?program=") - 1;
		int channelNr = 0;
		while (*digit != ' ')
		{
			//loc_2345a318
			channelNr = (channelNr * 10 + *digit++) - '0';
		}
		//0x2345a330
		sub_2340bf0c(&sp_0x28);

		if (sp_0x28.bCurrentChList != 0)
		{
			//->loc_2345a344: TV=1 -> Radio=0
			channel_switch_lists();
		}
		//loc_2345a398
		channel_start_number(&sp, (uint16_t)channelNr, 0);
		//->loc_2345a228
		r5 = 0;
		//->loc_2345a2ec
		r4 = 0;
		//->loc_2345a418
	}
	//loc_2345a34c
	else if (0 == strncmp(sb, "GET /list", 9))
	{
		//0x2345a364
		uint8_t* digit = sb + sizeof("GET /list?program=") - 1;
		int channelNr = 0;
		while (*digit != ' ')
		{
			//loc_2345a36c
			channelNr = (channelNr * 10 + *digit++) - '0';
		}
		//0x2345a384
		sub_2340bf0c(&sp_0x28);

		if (sp_0x28.bCurrentChList != 1)
		{
			//->loc_2345a344: Radio=0 -> TV=1
			channel_switch_lists();
		}
		//loc_2345a398
		channel_start_number(&sp, (uint16_t)channelNr, 0);
		//->loc_2345a228
		r5 = 0;
		//->loc_2345a2ec
		r4 = 0;
		//->loc_2345a418
	}
	//loc_2345a3ac
	//TODO!!!

	//loc_2345a418
	web_interface_send_response(r8, r4, r5, r6);
	//loc_2345a42c
}


/* 2345a550 - todo */
void web_interface_http_thread()
{
#if 1
	console_send_string("web_interface_http_thread (todo.c): TODO\r\n");
#endif

	int socket = lwip_socket(2, SOCK_STREAM, 0);

	if (socket < 0)
	{
		while (1)
		{
			/* loc_2345a570 - empty */
		}
	}
	//loc_2345a574
	struct sockaddr sp_0x20 = {0};
	struct sockaddr sp_0x10;
	socklen_t sp_0xc;
	fd_set sp8[2];
	fd_set sp4[2];

	sp_0x20.sa_family = AF_INET; //2;
	*((uint32_t*)&sp_0x20.sa_data[2]) = lwip_htonl(0);
	*((uint16_t*)&sp_0x20.sa_data[0]) = lwip_htons(8080);

#if 1
	console_send_string("web_interface_http_thread: lwip_bind\r\n");
#endif
	if (lwip_bind(socket, &sp_0x20, sizeof(struct sockaddr)) < 0)
	{
		while (1)
		{
			/* loc_2345a5c4 - empty */
		}
	}
#if 1
	console_send_string("web_interface_http_thread: lwip_listen\r\n");
#endif
	//loc_2345a5c8
	if (lwip_listen(socket, 5) < 0)
	{
		while (1)
		{
			/* loc_2345a5dc - empty */
		}
	}
	//loc_2345a5e0
#if 1
	memset(sp8, 0, sizeof(sp8));
#else
	FD_ZERO(sp8);
#endif
	FD_SET(socket, sp8);

	while (1)
	{
		//loc_2345a614
		memcpy(sp4, sp8, sizeof(sp8));

#if 1
		console_send_string("web_interface_http_thread: lwip_select\r\n");
#endif

		if (lwip_select(16, sp4, 0, 0, 0) <= 0)
		{
			//->loc_2345a718
			break;
		}
		//0x2345a63c
		//sl, sp, #0x4
		for (int r4 = 0; r4 < 16; r4++)
		{
			//loc_2345a644
			if (FD_ISSET(r4, sp4))
			{
				//0x2345a660
				if (r4 == socket)
				{
					//0x2345a668
					sp_0xc = 16;

#if 1
					console_send_string("web_interface_http_thread: lwip_accept\r\n");
#endif

					int r0 = lwip_accept(socket, &sp_0x10, &sp_0xc);

					FD_SET(r0, sp8);
					//->loc_2345a708
				}
				else
				{
					//loc_2345a6a0
#if 1
					console_send_string("web_interface_http_thread: lwip_read\r\n");
#endif
					int r0 = lwip_read(r4, Data_237bfd6c, sizeof(Data_237bfd6c));
					if (r0 <= 0)
					{
						//0x2345a6b8
						lwip_close(r4);

						FD_CLR(r4, sp8);
						//->loc_2345a614
						break;
					}
					else
					{
						//loc_2345a6e0
						web_interface_decode_request(r4, Data_237bfd6c, r0);

						lwip_close(r4);

						FD_CLR(r4, sp8);
						//loc_2345a708
					}
				}
			}
			//loc_2345a708
		} //for (int r4 = 0; r4 < 16; r4++)
		//0x2345a714 -> loc_2345a614
	} //while (1)
	//loc_2345a718
#if 1
	console_send_string("web_interface_http_thread: lwip_close\r\n");
#endif

	lwip_close(socket);

	FD_CLR(socket, sp8);
}

#if 0

/* 2345a740 - todo */
void sub_2345a740()
{
	console_send_string("sub_2345a740 (todo.c): TODO\r\n");

}

#endif

/* 2345aa18 - todo */
int sub_2345aa18()
{
#if 0
	console_send_string("sub_2345aa18 (todo.c): TODO\r\n");
#endif

	uint32_t sp_0x14;
	uint32_t sp_0x10;
	uint32_t sp_0xc;
	uint32_t sp8;

	void* sb = Data_237c0d0c.arhTsd[0];

	uint32_t r0 = tsd_get_write_pointer(sb);

	if (r0 < 0x20210/*131600*/)
	{
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_2345aa18: r0=%d\r\n", r0);
			console_send_string(debug_string);
		}
#endif
		return 0;
	}
	//loc_2345aa4c
	sub_23421eec(sb, r0);
	sub_23421e48(sb, 0x24b80, &sp_0x14, &sp_0x10, &sp_0xc, &sp8);

	//TODO!!!
}


/* 2345ab60 - complete */
static int web_interface_stop_streamout_tsd_pids(void)
{
#if 0
	console_send_string("web_interface_stop_streamout_tsd_pids (todo.c): TODO\r\n");
#endif

	struct Struct_2345b028_1_Inner14* r5 = Data_237c0d0c.Data_237c0d34.arPackets;

	for (uint32_t i = 0; i < 10; i++)
	{
		if (r5[i].bData_2 == 0)
		{
			break;
		}

		tsd_deactivate_pid_channel( Data_237c0d0c.arhTsd[i] );
	}

	Data_237c0d0c.Data_0x1c = 0;

	return 0;
}


/* 2345aba4 - complete */
int sub_2345aba4()
{
#if 0
	console_send_string("sub_2345aba4 (todo.c): TODO\r\n");
#endif

	void* r0;
	struct Struct_2345b028_1_Inner14* r5 = Data_237c0d0c.Data_237c0d34.arPackets;

	sub_23421a30(2, Data_237c0d0c.Data_237c0d34.wData_0x38);

	if (Data_237c0d0c.Data_237c0d34.wData_0x38 == 0)
	{
		r0 = main_hFrontend1;
	}
	else
	{
		r0 = Data_23491db8;
	}

	sub_2340ec54(r0, sub_2345ac74);

	for (uint32_t i = 0; i < 10; i++)
	{
		//loc_2345abdc
		if (r5[i].bData_2 == 0)
		{
			//->loc_2345ac18
			break;
		}

		tsd_set_pes_pid_filter(Data_237c0d0c.arhTsd[i], r5[i].wPid & 0x1fff);
		tsd_activate_pid_channel(Data_237c0d0c.arhTsd[i]);
	}
	//loc_2345ac18
	Data_237c0d0c.Data_0x1c = sub_2345aa18;

	return 0;
}


/* 2345ac28 - complete */
int web_interface_stop_streamout(void)
{
#if 0
	console_send_string("web_interface_stop_streamout (todo.c): TODO\r\n");
#endif

#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	OS_ENTER_CRITICAL();

	if (Data_237c0d0c.Data_0x1c == 0)
	{
		OS_EXIT_CRITICAL();
		//->loc_2345ac6c
	}
	else
	{
		//loc_2345ac48
		Data_237c0d0c.Data_237c0d24 = web_interface_stop_streamout_tsd_pids;

		OS_EXIT_CRITICAL();
		//->loc_2345ac60
		while (Data_237c0d0c.Data_0x1c != 0)
		{
			//loc_2345ac58
			rtos_task_wait(1);
		}
	}

	return 0;
}


/* 2345ac74 - todo */
void sub_2345ac74()
{
	console_send_string("sub_2345ac74 (todo.c): TODO\r\n");

}


/* 2345acb4 - complete */
void web_interface_streaming_thread()
{
#if 0
	console_send_string("web_interface_streaming_thread (todo.c): TODO\r\n");
#endif

	while (1)
	{
		if (Data_237c0d0c.Data_237c0d24 != 0)
		{
			Data_237c0d0c.Data_237c0d24 = (Data_237c0d0c.Data_237c0d24)();
		}

		if (Data_237c0d0c.Data_0x1c != 0)
		{
			(Data_237c0d0c.Data_0x1c)();
		}

		rtos_task_wait(1);
	}
}

#if 0

/* 2345ace8 - todo */
void sub_2345ace8() //Firsttime init thread
{
	console_send_string("sub_2345ace8 (todo.c): TODO\r\n");

}

#endif

/* 2345b028 - complete */
int sub_2345b028(Struct_2345b028_1* r4, struct sockaddr_in b)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sub_2345b028 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	Data_237c0d0c.Data_237c0d34 = *r4;
	Data_237c0d0c.Data_237c0d24 = sub_2345aba4;
	Data_237c0d0c.Data_237c0d70 = b;
	Data_237c0d0c.Data_237c0d10 = 0;
	Data_237c0d0c.wData_237c0d14 = 0;

	OS_EXIT_CRITICAL();

	return 0;
}


/* 2345b08c - todo */
void sub_2345b08c(PSI_Program* r4)
{
	Struct_234fd8f0_Inner_489DC sp_0x54;
	struct sockaddr_in sp_0x44;
	Struct_2345b028_1 sp8;

#if 0
	console_send_string("sub_2345b08c (todo.c): TODO\r\n");
#endif

	sub_2340ca1c(1, &sp_0x54);

	int r0_ = (sp_0x54.Data_4 & (1 << 1));
	if ((r0_ >> 1) != 0) //TODO!!!
	{
		//loc_2345b268
		return;
	}
	//0x2345b0b4
	memset(&sp8, 0, sizeof(sp8));

	if (r4->pat_program_number == 0xffff)
	{
		//loc_2345b268
		return;
	}

	uint32_t r0 = 0;

	sp8.arPackets[r0].bData_2 = 1;
	sp8.arPackets[r0].wPid = 0x00; //PAT

	r0++;

	sp8.arPackets[r0].bData_2 = 2; //r5
	sp8.arPackets[r0].wPid = 0x11; //SDT/BAT

//	int r0 = 2; //r5
	r0++;

	//r3 = r4->wVideoPID;
	if ((r4->bData_0 & 0x10) && (r4->wVideoPID != 0))
	{
		//0x2345b110
		//r0, #0x7
		//->loc_2345b124
		sp8.arPackets[r0].bData_2 = 7;
		sp8.arPackets[r0].wPid = r4->wVideoPID; //r3
		//r0 = 3;
		r0++;
		//loc_2345b130
	}
	else if (r4->wVideoPID != 0)
	{
		//0x2345b120
		//r0, #0x3
		sp8.arPackets[r0].bData_2 = 3;
		sp8.arPackets[r0].wPid = r4->wVideoPID; //r3
		//r0 = 3;
		r0++;
	}
	//loc_2345b130
	if (r4->wAudioPID != 0)
	{
		sp8.arPackets[r0].bData_2 = 4;
		sp8.arPackets[r0].wPid = r4->wAudioPID;
		r0++;
	}

	if (r4->wData_0x338 != 0)
	{
		sp8.arPackets[r0].bData_2 = 5;
		sp8.arPackets[r0].wPid = r4->wData_0x338;
		r0++;
	}

	for (uint32_t r2 = 0; r2 < 50; r2++)
	{
		//loc_2345b174
		if ((r4->arAudioPids[r2] != 0) && (r2 >= 10))
		{
			//->loc_2345b1c0
			break;
		}
		//0x2345b188
		if ((r4->arAudioPids[r2] != r4->wAudioPID) &&
				(r4->arAudioPids[r2] != r4->wData_0x338))
		{
			sp8.arPackets[r0].bData_2 = r0 + 8;
			sp8.arPackets[r0].wPid = r4->arAudioPids[r2];
			r0++;
		}
		//loc_2345b1b4
	} //for (uint32_t r2 = 0; r2 < 50; r2++)
	//loc_2345b1c0
	if (r4->pmt_pid != 0)
	{
		sp8.arPackets[r0].bData_2 = 6;
		sp8.arPackets[r0].wPid = r4->pmt_pid;
		r0++;
	}

	if ((r4->wPcrPID != r4->wVideoPID) &&
			(r4->wPcrPID != r4->wAudioPID) &&
			(r4->wPcrPID != r4->wData_0x338))
	{
		sp8.arPackets[r0].bData_2 = 8;
		sp8.arPackets[r0].wPid = r4->wPcrPID;
	}
	//loc_2345b214
	sp_0x44.sin_family = 2; //r5
	sp_0x44.sin_port = lwip_htons(sp_0x54.wData_12);
	sp_0x44.sin_addr.s_addr = sp_0x54.Data_8;

	if (0 == sub_2340d0d0())
	{
		sp8.wData_0x38 = sub_234225f4(); //-> tsd.c
		//->loc_2345b24c
	}
	else
	{
		//loc_2345b240
		uint32_t r0 = sub_234225f4();
		if (r0 != 2)
		{
			r0 = 1;
		}

		sp8.wData_0x38 = r0;
	}
	//0x2345b250
	sub_2345b028(&sp8, sp_0x44);
	//loc_2345b268
	return;
}


/* 2345b270 - complete */
int sub_2345b270(void)
{
#if 0
	console_send_string("sub_2345b270 (todo.c): TODO\r\n");
#endif

	sub_2345897c(&Data_237c0d0c.arhTsd);

	Data_23494094 = lwip_socket(2, SOCK_DGRAM, 0);

	return 0;
}


/* 2345b29c - complete */
int sub_2345b29c(void)
{
#if 0
	console_send_string("sub_2345b29c (todo.c): TODO\r\n");
#endif

	int r4;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	OS_ENTER_CRITICAL();

	r4 = (int) Data_237c0d0c.Data_0x1c;

	OS_EXIT_CRITICAL();

	return r4;
}


/* 2345b2b8 - complete */
int sub_2345b2b8(void)
{
#if 0
	console_send_string("sub_2345b2b8 (todo.c): TODO\r\n");
#endif

	int r4;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	OS_ENTER_CRITICAL();

	r4 = (int) Data_237c0d0c.Data_0;

	OS_EXIT_CRITICAL();

	return r4;
}

