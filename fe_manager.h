

typedef struct
{
	uint16_t threadPrio; //0
	uint8_t gpioPin; //2

} fe_manager_Params;


int fe_manager_tune(Frontend*, Transponder, void (*callbackFunc)(), uint16_t);
int fe_manager_register_measurement_callback(void* h, int (*)(Frontend_Measurement*));
int fe_manager_register_state_change_callback(Frontend*, void (*func)());

