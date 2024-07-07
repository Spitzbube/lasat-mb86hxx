
#include "data.h"
#include "lwip/tcp.h"

typedef struct
{
	/*struct tcp_pcb*/void* pcb; //0
	int fill_4; //4
	void (*Data_8)(); //8
	uint8_t buffer_in[0x20/*size???*/]; //0xc = 12
	//0x2c = 44
} Struct_235b0d14;


Struct_235b0d14 Data_235b0d14; // 235b0d14 / 2364f054



/* 23419e0c - todo */
void tcp_console_send(void* data)
{
#if 0
	console_send_string("tcp_console_send (todo.c): TODO\r\n");
#endif

	struct tcp_pcb* pcb;

	if (Data_235b0d14.pcb != 0)
	{
		uint32_t len = strlen(data);

		pcb = Data_235b0d14.pcb;

#if 1 //TODO!!!
		if (len < pcb->snd_queuelen)
#endif
		{
			tcp_write(pcb, data, len, TCP_WRITE_FLAG_COPY);
		}
	}
}


/* 23419e54 - todo */
int tcp_console_receive(void* arg,
		struct tcp_pcb* pcb,
		struct pbuf* p,
		int err)
{
#if 0
	console_send_string("tcp_console_receive (todo.c): TODO\r\n");
#endif

	Struct_235b0d14* r4 = arg;

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "tcp_console_receive: err=%d, p->tot_len=%d, p->len=%d\r\n",
				err, p->tot_len, p->len);
		console_send_string(debug_string);
	}
#endif

//	int r7 = 0;

	if ((err == 0) && (p != 0))
	{
		//23419e78
		tcp_recved(pcb, p->tot_len);

#if 0
		hex_dump("tcp_console_receive", p->payload, p->len);
#endif

		uint32_t len = p->len;
#if 0 //Original
		if (len < 0x20)
		{
			//23419e90
			memcpy(&r4->buffer_in[0], p->payload, len);

			r4->buffer_in[len - 2] = 0; //r7
		}
		//loc_23419ea8
		if (r4->Data_8 != 0)
		{
			(r4->Data_8)(r4->buffer_in);
		}
		//->loc_23419ecc
#else
		if (len < 0x20)
		{
			if ((len == 2) && (0 == memcmp(p->payload, "\r\n", 2)))
			{
				/* Ignored */
			}
			else
			{
				memcpy(&r4->buffer_in[0], p->payload, len);
				r4->buffer_in[len] = 0;
				if (r4->Data_8 != 0)
				{
					(r4->Data_8)(r4->buffer_in);
				}
			}
		}
#endif
	}
	else
	{
		//loc_23419ebc
		Data_235b0d14.pcb = 0;

		console_out_redirect(0);
	}
	//loc_23419ecc
	return 0;
}


/* 23419ed4 - todo */
void tcp_console_err()
{
#if 1
	console_send_string("tcp_console_err (todo.c): TODO\r\n");
#endif

	return;
}


/* 23419ed8 - complete */
int tcp_console_poll()
{
#if 0
	console_send_string("tcp_console_poll (todo.c): TODO\r\n");
#endif

	return 0;
}


/* 23419ee0 - complete */
int tcp_console_sent()
{
#if 0
	console_send_string("tcp_console_sent (todo.c): TODO\r\n");
#endif

	return 0;
}


/* 23419ee8/ 23424674 - todo */
int tcp_console_connected(int a, struct tcp_pcb* pcb)
{
#if 1
	console_send_string("tcp_console_connected (todo.c): TODO\r\n");
#endif

	uint8_t start_msg[] = //23488a98 -> 23488AE0
			" \x1B[0;1;40;32m\x1B[2J\n\r***************MyDebugConsole******************\n\r";

	tcp_arg(pcb, &Data_235b0d14);
	tcp_recv(pcb, tcp_console_receive);
	tcp_err(pcb, tcp_console_err);
	tcp_poll(pcb, tcp_console_poll, 1);
	tcp_sent(pcb, tcp_console_sent);

	Data_235b0d14.pcb = pcb;

	tcp_write(pcb, start_msg, /*0x45*/sizeof(start_msg), 1/*TCP_WRITE_FLAG_COPY*/);

	tcp_output(pcb);

#if 0 //TODO!!!
	console_out_redirect(tcp_console_send);
#endif

	return 0;
}


/* 23419f7c - todo */
void tcp_console_init(void (*pFunc)())
{
#if 0
	console_send_string("tcp_console_init (todo.c): TODO\r\n");
#endif

	struct tcp_pcb/*Struct_2346982e*/ *pcb;

	memset(&Data_235b0d14, 0, sizeof(Data_235b0d14));

	Data_235b0d14.Data_8 = pFunc;

	pcb = tcp_new();

	tcp_bind(pcb, IP_ADDR_ANY, 8888);

	pcb = tcp_listen(pcb);

	tcp_accept(pcb, tcp_console_connected);
}

