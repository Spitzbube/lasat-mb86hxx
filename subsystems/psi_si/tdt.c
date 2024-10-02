

#include "data.h"
#include "tdt.h"


void tot_decode_descriptors(uint8_t*, int);


/* 2344ed20 /  / 23476508 - complete */
void tdt_decode_utc(uint8_t* r4, int b)
{
#if 0
	console_send_string("tdt_decode_utc (todo.c): TODO\r\n");
#endif

	int mjd = (r4[3] << 8) | r4[4];

	r4[12] = 0;

	clocktime_set_from_utc(mjd, r4 + 5);

	sub_23480d78(r4 + 3, 5);
}


/* 2344ed58 /  / 23476540 - todo */
void tot_decode_section(uint8_t* a, int b)
{
#if 0
	console_send_string("tot_decode_section (todo.c): TODO\r\n");
#endif

	int16_t descriptors_loop_length = ((a[8] & 0x0f) << 8) | a[9];
	uint8_t* descriptor = a + 10;

	while (descriptors_loop_length > 0)
	{
		tot_decode_descriptors(descriptor, 0);

		descriptors_loop_length -= (descriptor[1] + 2);
		descriptor += (descriptor[1] + 2);
	}
}


/* 2344eda4 /  / 2347658c - todo */
void tot_decode_descriptors(uint8_t* a, int b)
{
#if 0
	console_send_string("tot_decode_descriptors (todo.c): TODO\r\n");
#endif

	Struct_23411b50 sp;

	if (a[0] == 0x58) //local_time_offset_descriptor
	{
		int16_t n = a[1] / 13;
		a += 2;
		//->loc_23476660
		while (n > 0)
		{
			//loc_234765bc
			sp.country_code[0] = a[0]; 
			sp.country_code[1] = a[1];
			sp.country_code[2] = a[2];
			sp.country_code[3] = 0;
			sp.country_region_id = a[3] >> 2;
			sp.local_time_offset_polarity = a[3] & (1 << 0);

			sp.local_time_offset = (a[5] << 8) | a[4];

			sp.Data_4.time_of_change_mjd = (a[6] << 8) | a[7];

			sp.Data_4.time_of_change_utc_hours = a[8];
			sp.Data_4.time_of_change_utc_minutes = a[9];
			sp.Data_4.time_of_change_utc_seconds = a[10];

			sp.next_time_offset = (a[10] << 8) | a[11];

#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "tot_decode_descriptors: country_code='%s', pol=%d, offset=%d, next_offset=%d\r\n", 
					&sp.country_code[0], sp.local_time_offset_polarity,
					sp.local_time_offset, sp.next_time_offset);
				console_send_string(debug_string);
			}
#endif

			sub_23412444(&sp.Data_4);

			sub_23411b50(&sp);

			n--;
			a += 13;
		}
	}
	//loc_23476668
	return;
}



