
typedef struct
{
	int mode; //0
	int audioClock; //4
	int polarity; //8
	int format; //12
	int Data_0x10; //16
	int Data_0x14; //20
	int Data_0x18; //24
	int Data_0x1c; //28
	struct Struct_2342499c_Inner_0x20
	{
		uint16_t left; //0
		uint16_t right; //2
		//4
	} speakerMapping[4]; //0x20 = 32
	//0x30
} Struct_2342499c;


typedef struct
{
	int inputType; //0
	int outputType; //4
	uint32_t videoCode; //8
	int scanInfo; //12
	int activeFormat; //16 = 0x10

} HDMI_VideoParams;


typedef struct
{
	int Data_0; //0
	int Data_4; //4

} Struct_234248a0;



int hdmi_SetVideoParameters(void* h, HDMI_VideoParams*);
int hdmi_SetAudioParameters(void* h, Struct_2342499c*);
int hdmi_SetAudioSampleFrequency(void* h, int sampleFreq);

int hdmi_open(Struct_234248a0*, void**);



