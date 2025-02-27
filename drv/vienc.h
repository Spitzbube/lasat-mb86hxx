

typedef struct
{
	int sd_hd; //0
	int Data_4; //4
	int Data_8; //8
	int Data_12; //12

} Vienc_Params;


void vienc_init(void);
int vienc_open(Vienc_Params*, void**);
int vienc_start(void*);


