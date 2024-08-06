
typedef struct
{
	uint8_t tuner_init_OK; //0
	uint8_t tuner_dev_addr; //1
	uint32_t tuner_freq; //4
	int16_t tuner_mode; //8
	uint8_t lt_gain_fix; //10 = 0x0a
	uint8_t lt_gain_code; //11 = 0x0b
	uint8_t tuner_application; //12 = 0x0c
	uint8_t tuner_bandwidth; //13 = 0x0d
	int tuner_crystal; //16 = 0x10
	int tuner_dac; //20 = 0x14
	uint8_t tuner_clock_out; //24 = 0x18
	uint8_t tuner_gpio_out; //25 = 0x19
	uint8_t tuner_int_lt; //26 = 0x1a
	uint8_t tuner_int_fast_set; //27 = 0x1b
	uint8_t tuner_moni_type; //28 = 0x1c
	uint8_t tuner_lb_sen_boost; //29 = 0x1d
	uint8_t bData_0x1e; //30 = 0x1e
	uint16_t Data_0x20; //32 = 0x20
	uint16_t tuner_mtt; //34 = 0x22
	uint16_t wData_0x24; //36 = 0x24
	int Data_0x28; //40 = 0x28
	int Data_0x2c; //44 = 0x2c
	uint8_t tuner_int_im; //48 = 0x30
	uint32_t tuner_int_fm; //52 = 0x34
	uint8_t bData_0x38; //0x38
	uint8_t bData_0x39; //0x39
	uint32_t Data_0x3c; //0x3c
	int Data_0x40; //0x40
	int fill_0x44[10]; //0x44
	void (*WriteReg)(); //108 = 0x6c
	void (*ReadReg)(); //112 = 0x70
	uint8_t demod_address; //116 = 0x74
	//0x78 = 120
} MT_FE_TN_DEVICE_SETTINGS_TC3800, *MT_FE_Tuner_Handle_TC3800;

void mt_fe_tn_set_freq_tc3800(MT_FE_Tuner_Handle_TC3800, int);

