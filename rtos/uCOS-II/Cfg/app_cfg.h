/*
*********************************************************************************************************
*                                       APPLICATION CONFIGURATION
*
*                             (c) Copyright 2005, Micrium, Inc., Weston, FL
*                                          All Rights Reserved
*
*                                             NXP LPC2000
*********************************************************************************************************
*/

#ifndef  __APP_CFG_H__
#define  __APP_CFG_H__

#if 0
		
/*
*********************************************************************************************************
*                                            TASK PRIORITIES
*********************************************************************************************************
*/

#define  OS_TASK_TMR_PRIO             4

#define  APP_TASK_START_PRIO          5

#define  APP_TASK_USER_IF_PRIO        6

#define  OS_VIEW_TASK_PRIO            7
#define  OS_VIEW_TASK_ID              7


/*
*********************************************************************************************************
*                                            TASK STACK SIZES
*********************************************************************************************************
*/

#define  APP_TASK_START_STK_SIZE    100

#define  APP_TASK_USER_IF_STK_SIZE  100

#define  OS_VIEW_TASK_STK_SIZE      100


/*
*********************************************************************************************************
*                                          uC/LCD CONFIGURATION
*********************************************************************************************************
*/

#define  DISP_BUS_WIDTH               4        /* LCD controller is accessed with a 4 bit bus          */


/*
*********************************************************************************************************
*                                           uC/OS-View CONSTANTS
*********************************************************************************************************
*/

#define  OS_VIEW_PARSE_TASK           1        /* Parsing of received packets will be done by a task   */

#define  OS_VIEW_TMR_32_BITS          1        /* uC/OS-View timer is 32 bits                          */


#define  OS_VIEW_UART_0               0
#define  OS_VIEW_UART_1               1
#define  OS_VIEW_UART_2               2

#define  OS_VIEW_COMM_SEL             OS_VIEW_UART_1


#endif

#endif
