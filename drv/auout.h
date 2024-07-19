
#ifndef DRV_AUOUT_H
#define DRV_AUOUT_H

#define AUOUT_SPEAKER_UNDEF	-1
#define AUOUT_SPEAKER_LEFT	0
#define AUOUT_SPEAKER_RIGHT	2
#define AUOUT_SPEAKER_ALL	8

#define AUOUT_I2S_ALL		4


typedef struct
{
	int enableSPDIF; //0
	int speakerArr[8]; //4
	int spdifBufferAddress; //36 = 0x24
	int spdifBufferSize; //40 = 0x28
	int i2s0BufferAddress; //44 = 0x2c
	int i2s0BufferSize; //48 = 0x30
	int Data_0x34; //0x34
	int Data_0x38; //0x38
	int Data_0x3c; //0x3c
	int Data_0x40; //0x40
	int Data_0x44; //0x44
	int Data_0x48; //0x48
	void (*Data_0x4c)(); //0x4c
	void (*Data_0x50)(); //0x50
	//0x54
} AUOUT_OpenParams;


int auout_open(AUOUT_OpenParams* paramsPtr, void**);
void auout_set_volume(void* handle, int speaker, int volume);

#endif // DRV_AUOUT_H
