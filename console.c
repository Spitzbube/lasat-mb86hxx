

#include "data.h"



Uart_Module* consoleUart; //23492280 +0
//int Data_23492284; //23492284 +4
void (*Data_23492288)(); //23492288 +8



/* 2341af84 - complete */
void console_init(Uart_Module* pUart)
{
	consoleUart = pUart;

//	gpreg_open(0, &Data_23492284);
}


/* 2341af98 - complete */
void console_send_string(unsigned char* a)
{
	if (Data_23492288 != 0)
	{
		(Data_23492288)(a);
#if 1 //TODO!!!
		return;
#endif
	}

	if (consoleUart == 0)
	{
		return;
	}

	while (1)
	{
		unsigned char ch = *a++;
		if (ch == 0) break;
		uart_write_byte(consoleUart, ch);
		if (ch == 0x0a)
		{
			uart_write_byte(consoleUart, 0x0d);
		}
	}
}


/* 2341aff0 / 234264f8 - complete */
void console_send_number(uint32_t number, int numDigits)
{
#if 0
	console_send_string("console_send_number (todo.c): TODO\r\n");
#endif

	uint8_t buf[10]; //size???
	uint32_t i;

	for (i = 0; i < numDigits; i++)
	{
		uint8_t digit = number & 0x0f;
		if (digit > 9)
		{
			digit += '7';
		}
		else
		{
			digit += '0';
		}

		buf[numDigits - i - 1] = digit;
		number >>= 4;
	}

	buf[numDigits] = 0;
	console_send_string(buf);
}


/* 2341b094 / 2342659c - todo */
void sub_2341b094(int a, int b)
{
	console_send_string("sub_2341b094 (todo.c): TODO\r\n");

}


/* 2341b150 - todo */
int sub_2341b150()
{
#if 0
	console_send_string("sub_2341b150 (todo.c): TODO\r\n");
#endif

	return sub_2341ad64(consoleUart);
}


/* 2341b15c - complete */
void console_write_byte(uint8_t a)
{
#if 0
	console_send_string("console_write_byte (todo.c): TODO\r\n");
#endif

	uart_write_byte(consoleUart, a);
}


/* sub_2341b16c - todo */
void console_read_byte(char* a)
{
	*a = uart_read_byte(consoleUart);
}


/* 2341b1b0 - complete */
void console_out_redirect(void (*func)())
{
	Data_23492288 = func;
}




