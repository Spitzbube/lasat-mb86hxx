

typedef struct
{
    uint32_t Data_0; //0
    uint8_t Data_4[0x100]; //4
    //0x104
} AUDEC_RadioText;

enum
{
    RDS_RADIOTEXT = 0,
    RDS_PS_NAME = 1,
};


void radiotext_init(void);
void radiotext_check_data(int channel);
void radiotext_get_string(int iText/*sb*/, uint8_t* pTextBuffer/*r4*/, uint32_t nTextBufSize);
