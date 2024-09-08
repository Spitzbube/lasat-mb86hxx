

typedef struct
{
	int globalOffset; //0
	int Data_4; //4
	int Data_8; //8
	int fill_12[2]; //12

} Viscale_Osd_Params;



extern void* viscale_osd_open(Viscale_Osd_Params*);
extern int viscale_osd_layer_enable(void*);
extern int viscale_osd_layer_disable(void*);
extern int sub_2342dde4(void*, uint32_t, uint32_t);

