

typedef struct
{
	int globalOffset; //0
	int Data_4; //4
	int registerOffset; //8
	int fill_12[2]; //12

} Viscale_Osd_Params;



extern void* viscale_osd_open(Viscale_Osd_Params*);
extern int viscale_osd_layer_enable(void*);
extern int viscale_osd_layer_disable(void*);
extern int sub_2342dde4(void*, uint32_t, uint32_t);
extern int sub_2342d42c(uint8_t, int16_t, int16_t, int16_t, int16_t, int);
extern int sub_2342ce8c(uint8_t, uint16_t, uint16_t, uint8_t*);
