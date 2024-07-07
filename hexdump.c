

#include "data.h"

extern char debug_string[];


void hex_dump(const char* a, char* b, unsigned c)
{
	int r14;
	char fp20[20];
	unsigned i = 0;
	if (a != 0)
	{
		sprintf(debug_string, "DATA: %s", a);
		console_send_string(debug_string);
	}
	fp20[16] = 0;
	while (i != c)
	{
    char r0;
		int r19 = i % 16;
		if (r19 == 0)
		{
			if ((a != 0) || (i != 0))
			{
				sprintf(debug_string, "\n");
				console_send_string(debug_string);
			}
			sprintf(debug_string, "%04x ", i);
			console_send_string(debug_string);
		}
		else if ((i % 4) == 0)
		{
			sprintf(debug_string, " |");
			console_send_string(debug_string);
		}
		sprintf(debug_string, " %02X", *b);
		console_send_string(debug_string);

		r0 = *b;
		if ((r0 < ' ') || (r0 >= 0x80))
		{
			r0 = '.';
		}
		fp20[r19] = r0;
		if (r19 == 15)
		{
			sprintf(debug_string, "  %s", fp20);
			console_send_string(debug_string);
		}
		i++;
		b++;
	}
	while ((r14 = i % 16) != 0)
	{
		if ((i % 4) == 0)
		{
			sprintf(debug_string, "  ");
			console_send_string(debug_string);
		}
		sprintf(debug_string, "   ");
		console_send_string(debug_string);
		fp20[r14] = 0;
		if (r14 == 15)
		{
			sprintf(debug_string, "  %s", fp20);
			console_send_string(debug_string);
			break;
		}
		i++;
	}
	sprintf(debug_string, "\n");
	console_send_string(debug_string);
}

