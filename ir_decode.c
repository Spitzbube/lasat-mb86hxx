
#include <stdint.h>
#include "data.h"
#include "ir.h"


#if 0 //VDR110
uint16_t wData_23493628; //23493628
#else //V241
uint16_t wData_23493628 = 0x3c0;
#endif


/* 23453d80 - todo */
void sub_23453d80()
{
	wData_23493628 = 0x580;
}


/* 23453d90 / 2346a944 - todo */
int sub_23453d90(int a, int b, uint8_t* c, uint8_t* sl, uint8_t* fp/*, uint8_t* sp8*/)
{
	signed short r6;
	int r4 = 0x30;
	int r5 = 0;
	volatile int r7 = 0;
//	int r8;
//	int sb;

	sub_2342e488(a, 1);

//	r8 = 0xffff;
//	sb = 0x7f;

	r6 = b;
	if (r6 == 26)
	{
#if 0
		console_send_string("sub_23453d90 (r6 = 26): TODO\r\n");
#endif
		while (1)
		{
			//loc_23453dc8
			uint8_t r0 = sub_2342e488(0, 0) >> 1;

			if (r6 > 0)
			{
				r6--;

				if ((r4 & 0x10) &&
						//0x23453df4
						((r0 & 0x80) == (r4 & 0x80)))
				{
					r0 &= 0x7f;
					if ((r0 > 2) && (r0 < 9))
					{
						uint8_t r1;

						r4 ^= 0x80;

						r0 = sub_2342e488(0, 0);
						r1 = r0 >> 1;

						if (r6 > 0)
						{
							//0x23453e38
							r6--;

							if ((r4 & 0x80) == (r1 & 0x80))
							{
								r0 = r1 & 0x7f;
								if (r0 > 24)
								{
									if (r0 < 32)
									{
										r5 = /*r8*/0xffff & (r5 << 1);
										//->loc_23453ec8
										r4 = r4 ^ 0x80;
										//->loc_23453e88
									}
									else
									{
										//0x23453e68
										if (r0 > 48)
										{
											if (r0 < 64)
											{
												//loc_23453ec0
												r0 = /*r8*/0xffff & (r5 << 1);
												r5 = r0 | 1;
												//loc_23453ec8
												r4 = r4 ^ 0x80;
												//->loc_23453e88
											}
											else
											{
												//0x23453e78
												r0 = /*sb*/0x7f & ~r1;
												if (r0 == 0) //TODO
												{
													r4 = r4 & ~0x20;
													//->loc_23453e88
												}
												else
												{
													//loc_23453e84
													r4 &= ~0x10;
													//loc_23453e88
												}
											}
										} //if (r0 > 48)
										else
										{
											//loc_23453e84
											r4 &= ~0x10;
											//loc_23453e88
										}
									}
								} //if (r0 > 24)
								else
								{
									//loc_23453e84
									r4 &= ~0x10;
									//loc_23453e88
								}
							}
							//loc_23453e88
						} //if (r6 > 0)
						else
						{
							//loc_23453ed0
							r4 = r4 & ~0x10;
							//->loc_23453e90
						}
					}
					else
					{
						//loc_23453e84
						r4 &= ~0x10;
						//loc_23453e88
					}
				}
				else
				{
					//loc_23453e84
					r4 &= ~0x10;
					//loc_23453e88
				}
				//loc_23453e88
				if (r6 > 0)
				{
					//->loc_23453dc8
					continue;
				}
				else
				{
					//loc_23453e90
					break;
				}
			} //if (r6 > 0)
			else
			{
				//loc_23453ed0
				r4 = r4 & ~0x10;
				//->loc_23453e90
				break;
			}
		} //while (1) -> loc_23453dc8
		//loc_23453e90
		if (r4 & 0x10)
		{
			//0x23453e98
			int r0;
			int r1;

			r0 = r5 & 0xf00;
			if ((r4 & 0x20) || (r0 == 0xc00))
			{
				//0x23453ea8
				*sl = r5 & 0x3f;
				*fp = r5 & 0x80;

#if 0
				r1 = r0 >> 8;
				//->loc_2345402c
				*sp8 = r1;
#endif
				return 0;
			}
			//->loc_23454048
//				return 1;
		}
		//->loc_23454048
//		return 1;
	} //if (r6 == 26)
	else
	{
		//loc_23453fc0 / loc_2346ab74
		while (r6 > 0)
		{
			//->loc_23453ed8 / loc_2346aa8c
			uint8_t r0 = sub_2342e488(0, 0) >> 1;

#if 0
	console_send_string("sub_23453d90 (r6 != 26)\r\n");
#endif

			if (r6 > 0)
			{
				//0x23453ef4
				r6--;

				if ((r4 & 0x10) &&
						((r0 & 0x80) == (r4 & 0x80)))
				{
					uint8_t r1 = r0 & 0x7f;

					if (r1 >= 8)
					{
						//0x23453f20
						if (r1 > 16)
						{
							//0x23453f28
							if (r1 >= 20)
							{
								if (r1 <= 32)
								{
									//0x23453f38
									r5 = /*r8*/0xffff & (r5 << 1);
									if ((r0 & 0x80) == 0)
									{
										r5 |= 1;
									}
									//->loc_23453f58
									r4 = r4 ^ 0x80;
									//->loc_23453fc0
								}
								else
								{
									//loc_23453fb4
									if ((/*sb*/0x7f & ~r0) == 0)
									{
										//loc_23453f48
										r4 = r4 & ~0x20;
										if ((r5 & 0x2000) == 0)
										{
											r5 = /*r8*/0xffff & (r5 << 1);
										}
										//->loc_23453fc0
									}
									else
									{
										//loc_23453fbc
										r4 = r4 & ~0x10;
									}
								}
							}
							else
							{
								//loc_23453fbc
								r4 = r4 & ~0x10;
							}
						} //if (r1 > 16)
						else
						{
							//->loc_23453f60
							r5 = /*r8*/0xffff & (r5 << 1);

							if ((r0 & 0x80) == 0)
							{
								r5 |= 1;
							}

							r4 = r4 ^ 0x80;

							r0 = sub_2342e488(0, 0) >> 1;

							if (r6 > 0)
							{
								//0x23453f8c
								r6--;

								if ((r0 & 0x80) == (r4 & 0x80))
								{
									//0x23453fa4
									r1 = r0 & 0x7f;
									if ((r1 > 7) && (r1 < 16)) //(r1 - 8) < 8)
									{
										//->loc_23453f58
										r4 = r4 ^ 0x80;
										//->loc_23453fc0
									}
									else
									{
										//loc_23453fb4
										if ((/*sb*/0x7f & ~r0) == 0)
										{
											//->loc_23453f48
											r4 = r4 & ~0x20;
											if ((r5 & 0x2000) == 0)
											{
												r5 = /*r8*/0xffff & (r5 << 1);
											}
											//->loc_23453fc0
										}
										else
										{
											//loc_23453fbc
											r4 = r4 & ~0x10;
											//loc_23453fc0
										}
									}
								}
								//loc_23453fc0
							} //if (r6 > 0)
							else
							{
								//loc_23454040
								r4 = r4 & ~0x10;
								//->loc_23453fc8
							}
						}
					} //if (r1 >= 8)
					else
					{
						//loc_23453fbc
						r4 = r4 & ~0x10;
					}
				}
				else
				{
					//loc_23453fbc
					r4 = r4 & ~0x10;
				}
				//loc_23453fc0
			} //if (r6 > 0)
			else
			{
				//loc_23454040
				r4 = r4 & ~0x10;
				//->loc_23453fc8
			}
		} //while (1) -> loc_23453ed8
		//loc_23453fc8 / loc_2346ab7c
#if 0
		console_send_string("sub_23453d90 (1)\r\n");
#endif
		if ((r4 & 0x10) && ((r4 & 0x20) == 0) &&
				(r5 & 0x2000) && (wData_23493628 == (r5 & 0x7c0)))
		{
			//0x23453ff4
#if 0
		console_send_string("sub_23453d90 (2)\r\n");
#endif
			r7 = r5 & 0x3f;

			if ((r5 & 0x1000) == 0)
			{
				r7 |= 0x40;
			}

			if (r5 & 0x800)
			{
				r7 |= 0x80;
			}

			r7 |= 0x100;
		}
		//loc_2345400c / loc_2346abb8
		if (r7 | 0x100)
		{
			int r1;
#if 0
		console_send_string("sub_23453d90 (3)\r\n");
#endif

			//0x23454014
			*sl = r7 & 0x7f;
			r1 = r7 & 0x80;
			*fp = r7 & 0x80;
#if 0
			*sp8 = r7 & 0xc0;
#endif

			return 0;
		}
	}
	//loc_23454048
	return 1;
}

