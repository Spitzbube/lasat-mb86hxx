

typedef void (*DMA_Channel_Callback)(uint32_t, void*);

int dma_init(void);
int dma_start_memcpy(uint32_t writeAddr, uint32_t readAddr, uint32_t length, DMA_Channel_Callback, int);
int dma_start_usb_transfer(void*, DMA_Channel_Callback, int, void*, uint32_t, uint16_t, uint8_t, uint8_t bWrite);
