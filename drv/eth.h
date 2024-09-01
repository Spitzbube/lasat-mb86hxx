

typedef struct
{
	uint8_t bData[13]; //0

} Struct_234012b0_a;

typedef struct
{
	uint32_t Data_0; //0
	uint32_t Data_4; //4
	//8
} Struct_234012b0_b;


typedef struct
{
	int Data_0; //0
	int Data_4; //4
	int speed; //8
	int duplex; //12 = 0xc
	int loop; //16 = 0x10
	void (*recvCallback)(); //20 = 0x14
	//24 = 0x18
} eth_open_params;


typedef struct
{
    /*FAPI_ETH_SpeedEnumT*/int  speed; //0 !< speed setting
    /*FAPI_ETH_DuplexEnumT*/int duplex;//4 !< duplex mode setting
    /*FAPI_ETH_LoopEnumT*/int   loop;  //8 !< local loopback mode setting
    /*FAPI_ETH_LinkEnumT*/int   linkup;//12 !< link is up or not
    /*FAPI_ETH_ErrorEnumT*/int  error; //16 !< error details (if available)
    //20
} eth_stat_params; //FAPI_ETH_StatParamsT;


typedef struct {
    uint32_t  rSize; //0
    /*char_t*/uint8_t*   rPtr; //4
    uint32_t  wSize; //8
    /*char_t*/uint8_t*   wPtr; //12
} eth_drv_data; //FAPI_ETH_DrvDataT

typedef uint8_t Eth_Mac[12];

typedef struct
{
	int id; //0
	int inUse; //4
	void* lock; //8
	eth_stat_params stat; //0xc = 12
	eth_drv_data data; //0x20 = 32
	Eth_Mac addr; //0x30 = 48
	int user_speed; //0x3c
	int (*start)(); //0x40
	int (*fill_0x44)(); //0x44
	int (*rUpdate)(); //0x48
	int (*wUpdate)(); //0x4c
	int (*intr)(); //0x50
	void (*recvCallback)(); //0x54
	void (*checklink)(); //0x58
	//92 = 0x5c
} ethHandleT;


typedef struct
{
    uint32_t des0; //0
    uint32_t des1; //4
    uint32_t des2; //8
    uint32_t des3; //12
    //16
} fmac3hDescT;

typedef struct
{
    fmac3hDescT desc; //0
    void*       prevPtr; //16          /* previous desc ptr */
    uint32_t    areaSiz; //20          /* all area size */
    //24 = 0x18
} fmac3hDescTxT;

/*DES1 common */
#define FMAC3H_DES1_sft_ER          (25)  /*1*/  /*RER&TER*/
#define FMAC3H_DES1_sft_CH          (24)  /*1*/  /*RCH&TCH*/
#define FMAC3H_DES1_sft_BS2         (11)  /*11*/ /*RBS2&TBS2*/
#define FMAC3H_DES1_sft_BS1         (0)   /*11*/ /*RBS1&TBS1*/
#define FMAC3H_DES1_bit_ER          (1)          /*RER&TER*/
#define FMAC3H_DES1_bit_CH          (1)          /*RCH&TCH*/
#define FMAC3H_DES1_bit_BS2         (0x7FF)      /*RBS2&TBS2*/
#define FMAC3H_DES1_bit_BS1         (0x7FF)      /*RBS1&TBS1*/
/*TDES1*/
#define FMAC3H_DES1_sft_IC          (31)  /*1*/
#define FMAC3H_DES1_sft_LS          (30)  /*1*/
#define FMAC3H_DES1_sft_FS          (29)  /*1*/
#define FMAC3H_DES1_sft_DC          (26)  /*1*/
#define FMAC3H_DES1_sft_DP          (23)  /*1*/
#define FMAC3H_DES1_bit_IC          (1)   /*1*/
#define FMAC3H_DES1_bit_LS          (1)   /*1*/
#define FMAC3H_DES1_bit_FS          (1)   /*1*/
#define FMAC3H_DES1_bit_DC          (1)   /*1*/
#define FMAC3H_DES1_bit_DP          (1)   /*1*/

#define FMAC3H_DESC_msk(I,X)     ((uint32_t)FMAC3H_DES##I##_bit_##X << FMAC3H_DES##I##_sft_##X)
#define FMAC3H_DESC_set(I,X,Y,Z) ((Y) = ((((Y)) & ~(FMAC3H_DESC_msk(I,X))) | ((uint32_t)(((Z)) & FMAC3H_DES##I##_bit_##X)<<FMAC3H_DES##I##_sft_##X)))
#define FMAC3H_DESC0_msk_OWN     (0x80000000)
