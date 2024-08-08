

typedef struct
{
	uint16_t threadPrio; //0
	uint8_t gpioPin; //2

} fe_manager_Params;


int fe_manager_tune(Struct_2354dd70*, Transponder sp_0x24, void (*callbackFunc)(), uint16_t r7);
int fe_manager_register_measurement_callback(void* h, int (*r6)(Struct_2347192c*));

