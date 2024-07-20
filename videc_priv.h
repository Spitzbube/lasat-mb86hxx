
#define MAINCPU_MESSAGE_VDPB_FREE_UPDATE                             0x10000000
#define MAINCPU_CMD_DECODE_END                                       0x04000000
#define MAINCPU_CMD_DECODE_START                                     0x01000000

#define FAPI_VIDEC_HW_RESET_ON                                       0x00030000
#define FAPI_VIDEC_HW_RESET_OFF                                      0x00000000

#define FAPI_VIDEC_START_ADDRESS_0                                   0x60000000

//!********** VDPB FREE IDX FIFO **********************************************
#define VDPB_FREE_IDX_FIFO_MAX_NUM                                           48
#define VDPB_FREE_IDX_FIFO_START_ADDR_OFFSET                         0x00048500

#define VDPB_FREE_IDX_FIFO_WRITE_POS_ADDR_0                                   \
           (FAPI_VIDEC_START_ADDRESS_0 + VDPB_FREE_IDX_FIFO_START_ADDR_OFFSET \
                                           + (VDPB_FREE_IDX_FIFO_MAX_NUM << 2))

//!********** VIDEO FIFOS *****************************************************
#define VDPB_FREE_IDX_FIFO_START_ADDR_0                                       \
            (FAPI_VIDEC_START_ADDRESS_0 + VDPB_FREE_IDX_FIFO_START_ADDR_OFFSET)

