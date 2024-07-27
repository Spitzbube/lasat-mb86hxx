
#define THREAD_PRIO_UART_IN					10
#define THREAD_PRIO_PSI_1					11
#define THREAD_PRIO_PSI_2					12
#define THREAD_PRIO_GRAPHIC					15
#define THREAD_PRIO_IR_USER_IN				16
#define THREAD_PRIO_SCAN					20
#define THREAD_PRIO_AV						21
#define THREAD_PRIO_UI_1					49
#define THREAD_PRIO_UI_2					50
#define THREAD_PRIO_FE_MANAGER				51
#define THREAD_PRIO_OTA     				52
#define THREAD_PRIO_STARTUP					56
#define THREAD_PRIO_IDLE					63
//#define  OS_TASK_IDLE_PRIO  (OS_LOWEST_PRIO)
//#define OS_LOWEST_PRIO					63

//#define OS_TASK_IDLE_STK_SIZE				0x400
#define THREAD_STACK_SIZE_STARTUP			0x320
#define THREAD_STACK_SIZE_UART_IN			0x320
#define THREAD_STACK_SIZE_IR_USER_IN		0x190
#define THREAD_STACK_SIZE_AV				0x190
#define THREAD_STACK_SIZE_FE_MANAGER		1000
#define THREAD_STACK_SIZE_PSI				1000
#define THREAD_STACK_SIZE_SCAN				0x320
#define THREAD_STACK_SIZE_GRAPHIC			0x190


