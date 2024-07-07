

extern void console_init(Uart_Module* pUart);
extern void console_send_string(unsigned char* a);
extern void console_read_byte(uint8_t* a);
extern int console_rx_empty(void);
