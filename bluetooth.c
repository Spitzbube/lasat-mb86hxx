
#include "data.h"
#include <string.h>

#pragma thumb


typedef struct
{
	uint8_t Data_235fc468[300]; //235fc468 -> 235FC594
	uint8_t Data_235fc594[22]; //235fc594
	int fill_0[3]; //0 = 235FC5AC
	uint8_t fill_235fc5b8; //235fc5b8
	uint8_t bData_235fc5b9; //235FC5B9
	void (*Data_235fc5bc)(); //340 = 0x154 = 235fc5bc
	//344 = 0x158 -> 235FC5C0
} Struct_235fc468;

Struct_235fc468 Data_235fc468_; //235fc468



void bt_strcpy(uint8_t* r0, uint8_t* r1, uint16_t r2);


/* 2343bad8 / 2345ec80 - complete */
int bt_uart_write(uint8_t* pData)
{
#if 0
	console_send_string("bt_uart_write (todo.c): TODO\r\n");
#endif

	for (uint8_t i = 0; i < 16; i++)
	{
		if (0 != uart_rx_empty(main_hUart1))
		{
			break;
		}

		uart_read_byte(main_hUart1);
	}

	while (*pData != 0)
	{
		uart_write_byte(main_hUart1, *pData++);
	}

	return 0;
}


/* 2343bb0c - complete */
int sub_2343bb0c(uint8_t* sp4, int r5)
{
#if 0
	console_send_string("sub_2343bb0c (todo.c): TODO\r\n");
#endif

	uint32_t r6 = 800000; //0xc3500;
	uint32_t r4 = 0;

	memset(&Data_235fc468_.Data_235fc468[0], 0, sizeof(Data_235fc468_.Data_235fc468));

	uint8_t* sp = Data_235fc468_.Data_235fc468;

	do
	{
		//->loc_2343bb5a
		while (0 == uart_rx_empty(main_hUart1))
		{
			//loc_2343bb26
			Data_235fc468_.Data_235fc468[r4] = uart_read_byte(main_hUart1);

#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_2343bb0c: ch=%c\r\n",
						Data_235fc468_.Data_235fc468[r4]);
				console_send_string(debug_string);
			}
#endif

			r4++;

			if (0 != strstr(sp, sp4))
			{
				//2343bb3e
				sp = Data_235fc468_.Data_235fc468 + r4;
				r5--;
				r5 = r5 & 0xff;
				if (r5 == 0)
				{
#if 0
					{
						extern char debug_string[];
						sprintf(debug_string, "sub_2343bb0c: Data_235fc468_.Data_235fc468='%s'\r\n",
								Data_235fc468_.Data_235fc468);
						console_send_string(debug_string);
					}
#endif
					return 0;
				}
				//loc_2343bb4e
			}
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_2343bb0c: Data_235fc468_.Data_235fc468='%s'\r\n",
						Data_235fc468_.Data_235fc468);
				console_send_string(debug_string);
			}
#endif
			if (r4 > 300)
			{
				//2343bb56
				return 2;
			}
			//loc_2343bb5a
		} //while (0 == uart_rx_empty(main_hUart1))
		//2343bb66
	}
	while (r6--);
	//2343bb6a
	return 11;
}


/* 2343bb6e / 2345ed16 - todo */
int sub_2343bb6e()
{
#if 0
	console_send_string("sub_2343bb6e (todo.c): TODO\r\n");
#endif

	bt_uart_write("D\r");

	if (0 == sub_2343bb0c("\r\n", 10))
	{
		//2343bb82
		uint8_t* r0 = (void*) strstr(Data_235fc468_.Data_235fc468, "BTName=");
		if (r0 != 0)
		{
			//2343bb8e
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_2343bb6e: r0='%s'\r\n", r0);
				console_send_string(debug_string);
			}
#endif
			bt_strcpy(Data_235fc468_.Data_235fc594, r0 + 7, 21);
		}
		//loc_2343bb98
		r0 = (void*) strstr(Data_235fc468_.Data_235fc468, "AudioRoute=");
		if (r0 != 0)
		{
			//2343bba4
#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_2343bb6e: r0='%s'\r\n", r0);
				console_send_string(debug_string);
			}
#endif
			uint8_t r1 = r0[12];
			uint32_t r0_ = r0[11];

			r0_ -= '0';
			r0_ *= 10;
			r0_ -= '0';
			r0_ = r1 + r0_;
			Data_235fc468_.bData_235fc5b9 = r0_;
		}
		//loc_2343bbb8
		return 0;
	}
	//loc_2343bbbc
	return 11;
}


/* 2343bbc0 - todo */
int sub_2343bbc0()
{
#if 0
	console_send_string("sub_2343bbc0 (todo.c): TODO\r\n");
#endif

	bt_uart_write("D\r");

	if (0 == sub_2343bb0c("\r\n", 14))
	{
		//0x2343bbd4
		uint8_t* r0 = strstr(Data_235fc468_.Data_235fc468, "BTName=");
		if (r0 != 0)
		{
			//0x2343bbe0
#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_2343bbc0(1): r0='%s'\r\n", r0);
				console_send_string(debug_string);
			}
#endif
			bt_strcpy(Data_235fc468_.Data_235fc594, r0 + 7, 21);
		}
		//loc_2343bbea
		r0 = strstr(Data_235fc468_.Data_235fc468, "AudioRoute=");
		if (r0 != 0)
		{
			//0x2343bbf6
#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_2343bbc0(2): r0='%s'\r\n", r0);
				console_send_string(debug_string);
			}
#endif
			r0 += 11;
			if ((r0[0] == 'I') &&
					(r0[1] == '2') &&
					(r0[2] == 'S'))
			{
				Data_235fc468_.bData_235fc5b9 = 1;
			}
			else
			{
				//loc_2343bc12
				Data_235fc468_.bData_235fc5b9 = 0;
			}
		}
		//loc_2343bc16
		return 0;
	}
	//loc_2343bc1a
	return 11;
}


/* 2343bc1e / 2345edc6 - todo */
int bt_check_version()
{
#if 0
	console_send_string("bt_check_version (todo.c): TODO\r\n");
#endif

	bt_uart_write("V\r");

	if (0 == sub_2343bb0c("\r\n", 1))
	{
		//0x2343bc36
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "bt_check_version(1): Data_235fc468='%s'\r\n",
					Data_235fc468_.Data_235fc468);
			console_send_string(debug_string);
		}
#endif
		if (0 != strstr(&Data_235fc468_.Data_235fc468[0], "Microchip"))
		{
			//0x2343bc42
			Data_235fc468_.Data_235fc5bc = sub_2343bbc0;
			return 0;
		}
		//loc_2343bc46
	}
	//loc_2343bc46
	bt_uart_write("V\r");

	if (0 == sub_2343bb0c("\r\n", 2))
	{
		//0x2343bc58
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "bt_check_version(2): Data_235fc468='%s'\r\n",
					Data_235fc468_.Data_235fc468);
			console_send_string(debug_string);
		}
#endif
		if (0 != strstr(&Data_235fc468_.Data_235fc468[0], "Microchip"))
		{
			//0x2343bc64
			Data_235fc468_.Data_235fc5bc = sub_2343bb6e;
			return 0;
		}
		//loc_2343bc6c
	}
#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "bt_check_version(3): Data_235fc468='%s'\r\n",
				Data_235fc468_.Data_235fc468);
		console_send_string(debug_string);
	}
#endif
	//loc_2343bc6c
	return 8;
}


/* 2343bc70 / 2345ee18 - complete */
int sub_2343bc70()
{
#if 0
	console_send_string("sub_2343bc70 (todo.c): TODO\r\n");
#endif

	uint8_t sp_0x20[12];
	uint8_t sp_0x14[12];
	uint8_t sp4[16];

	bt_uart_write("SF,1\r");
	rtos_task_wait(10);
	sub_2343bb0c("AOK", 1);

	sprintf(sp_0x20, "S|,%02X\r", 1);
	bt_uart_write(sp_0x20);
	sub_2343bb0c("AOK", 1);

	bt_uart_write("SD,04\r");
	sub_2343bb0c("AOK", 1);

	bt_uart_write("SK,04\r");
	sub_2343bb0c("AOK", 1);

	strncpy(sp4, "SOUNDBOX", 14);
	sprintf(sp_0x14, "S-,%s\r", sp4);
	bt_uart_write(sp_0x14);
	sub_2343bb0c("AOK", 1);

	bt_uart_write("R,1\r");
	sub_2343bb0c("Reboot!", 1);

	return 0;
}


/* 2343bcf2 / 2345ee9a - todo */
int sub_2343bcf2()
{
#if 0
	console_send_string("sub_2343bcf2 (todo.c): TODO\r\n");
#endif

	if (Data_235fc468_.Data_235fc5bc != 0)
	{
		(Data_235fc468_.Data_235fc5bc)();
	}

	if (Data_235fc468_.bData_235fc5b9 != 1)
	{
		sub_2343bc70();
	}

	return 0;
}


/* 2343bd0e / 2345eeb6 - complete */
int bt_init(void)
{
#if 0
	console_send_string("bt_init (todo.c): TODO\r\n");
#endif

	memset(&Data_235fc468_, 0, sizeof(Struct_235fc468));

	if (0 == bt_check_version())
	{
		sub_2343b9ae(sub_2343bc70);

		return 0;
	}

	return 8;
}


/* 2343bd30 / 2345eed8 - complete */
void bt_strcpy(uint8_t* to, uint8_t* from, uint16_t count)
{
#if 0
	console_send_string("bt_strcpy (todo.c): TODO\r\n");
#endif

	uint8_t r4 = 0;

	while (count--)
	{
		uint8_t c = *from;
		if ((c == 0) || (c == 0x0a))
		{
			*to = r4;
			return;
		}

		from++;
		*to++ = c;
	}
}

