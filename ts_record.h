
typedef struct
{
    int bufferAddress; //0
    int bufferSize; //4
    int Data_8; //8
    int Data_0xc; //0xc = 12
    uint8_t threadPrio; //0x10 = 16

}  TS_Record_Params;

int ts_record_init(TS_Record_Params*);
int sub_23458874(void);


