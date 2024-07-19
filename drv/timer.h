
#ifndef DRV_TIMER_H
#define DRV_TIMER_H

typedef struct
{
	int Data_0; //0
	void* Data_4; //4
	void (*Data_8)(); //8

} Timer_Params;


typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int Data_8; //8
	void* Data_12; //12
	void (*Func_16)(void*); //16
	//20
} Struct_235b1c24;


Struct_235b1c24* timer_user_open(Timer_Params*);
int timer_user_control(void* h, int);
void* sub_2341b85c(void* h);
uint64_t timer_get_timestamp(uint32_t resolution);

#endif //DRV_TIMER_H
