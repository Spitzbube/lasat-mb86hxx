
#include "data.h"
#include "ucos_ii.h"
#include "timer.h"
#include "tdt.h"
#include "clocktime.h"


//234c0520
uint32_t Data_234c0520 = 0; //234c0520


typedef struct
{
	Clock_Time Data_0; //0
	Struct_235b1c24* hTimer; //12
	int Data_0x10; //0x10
	int Data_0x14; //0x14
	User_Settings Data_0x18; //24 = 0x18 = 2358BE74 +0x1c = 2358BE90
	//0x34 = 52
} Struct_2358be5c;

Struct_2358be5c Data_2358be5c; //2358be5c /  / 235fb434


uint8_t sub_23412e4c(uint8_t);


/* 23411944 /  / 23419344 - todo */
int clocktime_timer_callback(void)
{
#if 0
	console_send_string("clocktime_timer_callback (todo.c): TODO\r\n");
#endif

	uint32_t r5 = ((volatile int*)0xcf000048)[0]; //TIMER1_CNT_LOW

	if (Data_2358be5c.Data_0.bData_4 == 0)
	{
		Data_234c0520 = r5;
		//->loc_2341940c
	}
	else
	{
		//0x23419368
		//int64_t r0_r1 = Data_234c0520;
		//int64_t r5_r6 = r5;
		uint32_t diff = (uint64_t)Data_234c0520 - (uint64_t)r5;
		int64_t mill = 1000000;

		uint8_t r0 = /*(r0_r1 - r5_r6)*/(int64_t)(/*Data_234c0520 - r5*/diff) / mill;
		//->loc_234193f4
		while (r0--)
		{
			//loc_2341939c
			Data_2358be5c.Data_0.seconds++;
			if (Data_2358be5c.Data_0.seconds >= 60)
			{
				Data_2358be5c.Data_0.seconds = 0;
				Data_2358be5c.Data_0.minutes++;
				if (Data_2358be5c.Data_0.minutes >= 60)
				{
					Data_2358be5c.Data_0.minutes = 0;
					Data_2358be5c.Data_0.hours++;
					if (Data_2358be5c.Data_0.hours >= 24)
					{
						Data_2358be5c.Data_0.hours = 0;
						Data_2358be5c.Data_0.mjd++;
					}
				}
			}
		}
		//0x23419404
		Data_234c0520 = r5 + 1000000;
	}
	//loc_2341940c
	return 0;
}


/* 23411a14 /  / 23419414 - complete */
void clocktime_init(void)
{
	Timer_Params timer_params;

#if 0
	console_send_string("clocktime_init (todo.c): TODO\r\n");
#endif

	memset(&Data_2358be5c, 0, sizeof(Struct_2358be5c));

	timer_params.Data_0 = 100;
	timer_params.Data_8 = clocktime_timer_callback;
	timer_params.Data_4 = 0;

	Data_2358be5c.hTimer = timer_user_open(&timer_params);

	if (Data_2358be5c.hTimer != 0)
	{
		timer_user_control(Data_2358be5c.hTimer, 1);
	}
}


/* 23411b0c /  / 2341950c - complete */
void clocktime_set_from_utc(int mjd, uint8_t* r5)
{
#if 0
	console_send_string("clocktime_set_from_utc (todo.c): TODO\r\n");
#endif

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "clocktime_set_from_utc: mjd=0x%x, %02x:%02x:%02x\r\n", 
			mjd, r5[0], r5[1], r5[2]);
		console_send_string(debug_string);
	}
#endif

	Data_2358be5c.Data_0.seconds = sub_23412e4c(r5[2]);
	Data_2358be5c.Data_0.minutes = sub_23412e4c(r5[1]);
	Data_2358be5c.Data_0.hours = sub_23412e4c(r5[0]);
	Data_2358be5c.Data_0.bData_4 = 1;
	Data_2358be5c.Data_0.mjd = mjd;
}


/* 23411b50 /  / 23419550 - todo */
void sub_23411b50(Struct_23411b50* r4)
{
#if 0
	console_send_string("sub_23411b50 (todo.c): TODO\r\n");
#endif

	char* countryCode;
	User_Settings sp4;
	uint8_t sp[4];

	channel_handle_user_settings(1, &sp4);

	if (sp4.Data_4.bitData.bit8 == 0)
	{
		countryCode = "DEU"; 
	}
	else if (sp4.Data_4.bitData.bit8 == 1)
	{
		countryCode = "AUT"; 
	}
	else if (sp4.Data_4.bitData.bit8 == 2)
	{
		countryCode = "CHE"; 
	}
	else if (sp4.Data_4.bitData.bit8 == 3)
	{
		countryCode = "ITA"; 
	}
	else if (sp4.Data_4.bitData.bit8 == 4)
	{
		countryCode = "GRC"; 
	}
	else if (sp4.Data_4.bitData.bit8 == 5)
	{
		countryCode = "PRT"; 
	}
	else if (sp4.Data_4.bitData.bit8 == 6)
	{
		countryCode = "HUN"; 
	}
	else if (sp4.Data_4.bitData.bit8 == 7)
	{
		countryCode = "DNK"; 
	}
	else if (sp4.Data_4.bitData.bit8 == 8)
	{
		countryCode = "SVN"; 
	}
	else if (sp4.Data_4.bitData.bit8 == 9)
	{
		countryCode = "CZE"; 
	}
	else if (sp4.Data_4.bitData.bit8 == 10)
	{
		countryCode = "ESP"; 
	}
	else if (sp4.Data_4.bitData.bit8 == 11)
	{
		countryCode = "SWE"; 
	}
	else if (sp4.Data_4.bitData.bit8 == 12)
	{
		countryCode = "LIE"; 
	}
	else
	{
		//loc_23411c70
		return;
	}
	//loc_23411c40
	if (0 != strcmp(&r4->country_code[0], countryCode))
	{
		return;
	}
	//0x23411c50
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	OS_ENTER_CRITICAL();

	if (Data_2358be5c.Data_0.bData_4 == 0)
	{
		//loc_23411c68
		OS_EXIT_CRITICAL();
		//loc_23411c70
		return;
	}
	//loc_23411c78
	Clock_Time* pClockTime = &Data_2358be5c.Data_0;

	sp[1] = sub_23412e4c(r4->Data_4.time_of_change_utc_seconds);
	sp[2] = sub_23412e4c(r4->Data_4.time_of_change_utc_minutes);
	sp[3] = sub_23412e4c(r4->Data_4.time_of_change_utc_hours);

	if ((Data_2358be5c.Data_0.mjd < r4->Data_4.time_of_change_mjd) ||
		((Data_2358be5c.Data_0.mjd == r4->Data_4.time_of_change_mjd) &&
		(pClockTime->hours < sp[3])) ||
		((Data_2358be5c.Data_0.mjd == r4->Data_4.time_of_change_mjd) &&
		(pClockTime->hours == sp[3]) && 
		(pClockTime->minutes < sp[2])))
	{
		//->loc_23411cf4
		Data_2358be5c.Data_0x10 = r4->local_time_offset;
		//loc_23411cd0
	}
	else
	{
		//loc_23411cfc
		Data_2358be5c.Data_0x10 = r4->next_time_offset;
		//loc_23411cd0
	}
	//0x23411d04
	Data_2358be5c.Data_0x10 = (r4->local_time_offset_polarity == 0)? 
		Data_2358be5c.Data_0x10: -Data_2358be5c.Data_0x10;

	Data_2358be5c.Data_0x14 = 1; //r7
	//->loc_23411c68
	OS_EXIT_CRITICAL();
	//loc_23411c70
	return;
}


/* 23411d74 /  / 23419788 - complete */
int clocktime_get(Clock_Time* a)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("clocktime_get (todo.c): TODO\r\n");
#endif

	if (a == 0)
	{
		return 1;
	}

	OS_ENTER_CRITICAL();

	*a = Data_2358be5c.Data_0;

	OS_EXIT_CRITICAL();

	return 0;
}


/* 23411da0 /  / 234197b4 - todo */
void sub_23411da0(Clock_Time* r4, uint16_t r6)
{
#if 0
	console_send_string("sub_23411da0 (todo.c): TODO\r\n");
#endif

#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	int r5 = 1;

	if (r6 == 49)
	{
		r6 = 24;

		OS_ENTER_CRITICAL();

		r6 += Data_2358be5c.Data_0x10 * 2;

		OS_EXIT_CRITICAL();
	}

	uint8_t r0 = r6 & 0x7f;
	if (r0 != 24)
	{
		if (r0 > 24)
		{
			r0 -= 24;
		}
		else
		{
			r0 = 24 - r0;
			r5 = -1;
		}

		int r1 = r0 & 1;
		r1 = r1 * 30;

		int8_t r0_;
		if (r1 != 0)
		{
			r0_ = (r0 - 1) / 2;
		}
		else
		{
			r0_ = r0 / 2;
		}

		r0_ = r4->hours + (r5 * r0_);
		r4->hours = r0_;
		if (r0_ < 0)
		{
			r4->hours = 24 + r0_;
		}

		if (r4->hours >= 24)
		{
			r4->hours -= 24;
		}

		r4->minutes += (r5 * r1);
		if (r4->minutes >= 60)
		{
			r4->minutes -= 60;
			r4->hours++;
		}
	}
}


/* 23412148 /  / 23419b5c - todo */
void sub_23412148(Struct_23419f50* r4, uint16_t r6)
{
#if 0
	console_send_string("sub_23412148 (todo.c): TODO\r\n");
#endif

	uint8_t r8[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 255, 0, 0};

	int8_t r5 = 1;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

	if (r6 == 49)
	{
		r6 = 24;

		OS_ENTER_CRITICAL();

		r6 += Data_2358be5c.Data_0x10 * 2;

		OS_EXIT_CRITICAL();
	}

	uint8_t r0 = r6 & 0x7f;
	if (r0 == 24)
	{
		return;
	}

	if (r0 > 24)
	{
		r0 -= 24;
	}
	else
	{
		r0 = 24 - r0;
		r5 = -1;
	}

	int r1 = r0 & 1;
	int r6 = r1 * 30;

	int8_t r7;
	if (r6 != 0)
	{
		r7 = (r0 - 1) / 2;
	}
	else
	{
		r7 = r0 / 2;
	}

	if (0 != sub_23411e6c(r4->year))
	{
		r8[2] = 29;
	}
	else
	{
		r8[2] = 28;
	}

	r4->time_of_change_utc_minutes += (r5 * r6);
	if ((int8_t)r4->time_of_change_utc_minutes >= 60)
	{
		//0x23412210
		r4->time_of_change_utc_minutes += 60;
		r4->time_of_change_utc_hours++;
		if (r4->time_of_change_utc_hours >= 24)
		{
			//0x23412230
			r4->time_of_change_utc_hours -= 24;
			r4->day++;

			if (r4->day > r8[r4->month])
			{
				//0x23412258
				r4->day = 1; //fp
				r4->month++;

				if (r8[r4->month] == 0xff)
				{
					r4->month = 1; //fp
					r4->year++;
				}
			} 
			//loc_23412280
			//r1 = 1;
			//->loc_2341230c
			sub_23412e68(&r4->weekDay, 1);
		}
		//loc_23412314
	}
	//loc_23412288
	else if ((int8_t)r4->time_of_change_utc_minutes < 0)
	{
		//0x23412290
		r4->time_of_change_utc_minutes = (int8_t)r4->time_of_change_utc_minutes + 60;
		r4->time_of_change_utc_hours--;

		if ((int8_t)r4->time_of_change_utc_hours < 0)
		{
			//0x234122b8
			r4->time_of_change_utc_hours = (int8_t)r4->time_of_change_utc_hours + 24;
			r4->day--;
			if ((r4->day & 0xff) == 0)
			{
				r4->month--;
				if (r8[r4->month] == 0)
				{
					r4->month = 12; //sl
					r4->year--;
				}
				r4->day = r8[r4->month];
			}
			//loc_23412308
			sub_23412e68(&r4->weekDay, -1);
		}
		//loc_23412314
	}
	//loc_23412314
	r4->time_of_change_utc_hours = (int8_t)r4->time_of_change_utc_hours + (r5 * r7);
	if ((int8_t)r4->time_of_change_utc_hours < 0)
	{
		//0x23412334
		r4->time_of_change_utc_hours = (int8_t)r4->time_of_change_utc_hours + 24;
		r4->day--;
		if ((r4->day & 0xff) == 0)
		{
			//0x23412350
			r4->month--;
			if (r8[r4->month] == 0)
			{
				r4->month = 12; //sl
				r4->year--;				
			}
			r4->day = r8[r4->month];
		}
		//loc_23412384
		//r1 = -1;
		//->loc_234123e8
		sub_23412e68(&r4->weekDay, -1);
		//loc_234123f0
	}
	//loc_2341238c
	else if (r4->time_of_change_utc_hours >= 24)
	{
		//0x23412394
		r4->time_of_change_utc_hours -= 24;
		r4->day++;
		if (r4->day > r8[r4->month])
		{
			//0x234123bc
			r4->day = 1; //fp
			r4->month++;
			if (r8[r4->month] == 0xff)
			{
				r4->month = 1; //fp
				r4->year++;
			}
		}
		//loc_234123e4
		sub_23412e68(&r4->weekDay, 1);
	}
	//loc_234123f0
	if (r5 != 0)
	{
		//0x234123f8
		int x = r4->time_of_change_utc_minutes;
		int y = r6;
		y += (r7 * 60);
		x += (r4->time_of_change_utc_hours * 60);
		if (x < y)
		{
			r4->time_of_change_mjd++;
		}
	}
	//loc_23412420
	sprintf(&r4->Data_0[0], "%02d.%02d.%04d", 
		r4->day, r4->month, r4->year);

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_23412148: &r4->Data_0[0]='%s'\r\n", 
				&r4->Data_0[0]);
			console_send_string(debug_string);
		}
#endif
}


/* 23412444 /  / 23419e58 - todo */
void sub_23412444(Struct_23419f50* r4)
{
#if 0
	console_send_string("sub_23412444 (todo.c): TODO\r\n");
#endif

	if (r4 != 0)
	{
		int r1;
		int r6 = r4->time_of_change_mjd;
		uint32_t r5 = r6 * 10000;
		uint32_t r8 = (r5 - 150782000) / 3652500;
		uint32_t r0 = (r8 * 3652500) / 10000;
		r0 = r0 * -625;
		uint32_t r7 = r5 + r0 * 16;
		r5 = (r7 - 149561000) / 306001;
		r0 = (r5 * 306001) / 10000;
		r0 = r0 * -625;
		r0 = r7 + r0 * 16;
		r0 = (r0 - 149560000) / 10000;

		if ((r5 == 14) || (r5 == 15))
		{
			r1 = 1;
		}
		else
		{
			r1 = 0;
		}

		int r2 = r8 + r1;
		r1 = r5 - r1 * 12 - 1;

		r4->year = r2 + 1900;
		r4->month = r1;
		r4->day = r0;
		r4->weekDay = ((r6 + 2) % 7) + 1;

		sprintf(&r4->Data_0[0], "%02d.%02d.%04d", 
			r4->day, r4->month, r4->year);

#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_23412444: &r4->Data_0[0]='%s'\r\n", 
				&r4->Data_0[0]);
			console_send_string(debug_string);
		}
#endif
	}
	//loc_23412538
	return;
}


/* 2341253c /  / 23419f50 - complete */
int sub_23419f50(Struct_23419f50* r4, uint16_t r5)
{
#if 0
	console_send_string("sub_23419f50 (todo.c): TODO\r\n");
#endif

#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	Clock_Time sp;

	if (r5 == 49)
	{
		r5 = 24;

		OS_ENTER_CRITICAL();

		r5 += Data_2358be5c.Data_0x10 * 2;

		OS_EXIT_CRITICAL();
	}
	//loc_2341256c
	memset(r4, 0, sizeof(Struct_23419f50));

	clocktime_get(&sp);

	if ((sp.bData_4 == 0) ||
		((r5 == 49) && (Data_2358be5c.Data_0x14 == 0)))
	{
		//loc_2341259c
		return 4;
	}
	//loc_234125a4
	r4->time_of_change_mjd = sp.mjd;

	sub_23412444(r4);

	r4->time_of_change_utc_hours = sp.hours;
	r4->time_of_change_utc_minutes = sp.minutes;
	r4->time_of_change_utc_seconds = sp.seconds;

	sub_23412148(r4, r5);

	return 0;
}


/* 23412698 - todo */
int sub_23412698(void)
{
#if 0
	console_send_string("sub_23412698 (todo.c): TODO\r\n");
#endif

	uint32_t r0;

	channel_handle_user_settings(1, &Data_2358be5c.Data_0x18);

	r0 = Data_2358be5c.Data_0x18.timeDiff & 0x07f;

	if (r0 == 49)
	{
		r0 = 24;
		r0 += Data_2358be5c.Data_0x10 * 2;
	}

	if (r0 == 24)
	{
		r0 = 0;
	}
	else
	{
		r0 -= 24;
	}

	return r0 * 30;
}


/* 234126dc /  / 2341a0f0 - todo */
void clocktime_get_event_time_string(uint8_t startHoursBcd, uint8_t startMinutesBcd, 
	uint8_t durationHoursBcd, uint8_t durationMinutesBcd, 
	char* strBufIn, uint32_t maxBufLen)
{
#if 0
	console_send_string("clocktime_get_event_time_string (todo.c): TODO\r\n");
#endif

	char strBuf[32];

	int16_t r0_ = sub_23412698();

	int r4 = r0_ / 60;
	int sl = r0_ % 60;

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "clocktime_get_event_time_string: r0_=%d, r4=%d, sl=%d, %02x:%02x (%02x:%02x)\r\n",
				r0_, r4, sl, 
				startHoursBcd, startMinutesBcd, 
				durationHoursBcd, durationMinutesBcd);
		console_send_string(debug_string);
	}
#endif

	memset(&strBuf[0], 0, sizeof(strBuf));
	memset(strBufIn, 0, maxBufLen);

	int16_t startHours = ((startHoursBcd & 0xf0) >> 4) * 10.0;
	int r1 = startHours + (double)(startHoursBcd & 0x0f);
	//0x2341278c
	startHours = r1 + r4;

	int16_t startMinutes = ((startMinutesBcd & 0xf0) >> 4) * 10.0;
	int r2 = startMinutes + (double)(startMinutesBcd & 0x0f);
	//0x234127d0
	startMinutes = r2 + sl;

	if (startMinutes < 0)
	{
		startMinutes += 60;
		startHours--;
	}
	if (startHours < 0)
	{
		startHours += 24;
	}

	int16_t endHours = ((durationHoursBcd & 0xf0) >> 4) * 10.0;
	r2 = endHours + (double)(durationHoursBcd & 0x0f);
	endHours = r2 + startHours;

	int16_t endMinutes = ((durationMinutesBcd & 0xf0) >> 4) * 10.0;
	int r3_ = endMinutes + (double)(durationMinutesBcd & 0x0f);
	endMinutes = r3_ + startMinutes;

	if (endMinutes > 59)
	{
		endMinutes -= 60;
		endHours++;
	}
	if (endHours >= 24)
	{
		endHours -= 24;
	}
	if (startMinutes > 59)
	{
		startMinutes -= 60;
		startHours++;
	}
	if (startHours >= 24)
	{
		startHours -= 24;
	}

	sprintf(&strBuf[0], "%d:%02d - %d:%02d",
		startHours, startMinutes, endHours, endMinutes);

	strncat(strBufIn, &strBuf[0], maxBufLen);
}


/* 23412da8 - todo */
int sub_23412da8(void)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
	uint16_t r4 = (0x16 << 11) | (0x16 << 5); //0xB2C0;

#if 0
	console_send_string("sub_23412da8 (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	if (Data_2358be5c.Data_0.bData_4 != 0)
	{
		uint8_t* r1 = &Data_2358be5c.Data_0.seconds;
		r4 = *(r1+0);
		r4 |= (*(r1+1) << 5);
		r4 |= (*(r1+2) << 11);
	}

	OS_EXIT_CRITICAL();

	return r4;
}


