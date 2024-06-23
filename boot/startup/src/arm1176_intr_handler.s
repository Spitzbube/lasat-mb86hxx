    AREA ARM1176IVT, CODE, READONLY, ALIGN=6
    PRESERVE8 

;*******************************************************************************
;** local CPU mode defines
;*******************************************************************************

ARM1176_MODE_USR         EQU 0x10       ; CPSR_c xxx10000
ARM1176_MODE_FIQ         EQU 0x11       ; CPSR_c xxx10001
ARM1176_MODE_IRQ         EQU 0x12       ; CPSR_c xxx10010
ARM1176_MODE_SVC         EQU 0x13       ; CPSR_c xxx10011
ARM1176_MODE_ABT         EQU 0x17       ; CPSR_c xxx10111
ARM1176_MODE_UND         EQU 0x1B       ; CPSR_c xxx11011
ARM1176_MODE_SYS         EQU 0x1F       ; CPSR_c xxx11111
OS_CPU_ARM_CONTROL_INT_DIS          EQU 0xC0       ; CPSR_c 110xxxxx
ARM1176_INT_ON           EQU 0x00       ; CPSR_c 000xxxxx
ARM1176_MODE_IRQ_INT_OFF EQU (ARM1176_MODE_IRQ+OS_CPU_ARM_CONTROL_INT_DIS)
ARM1176_MODE_SYS_INT_OFF EQU (ARM1176_MODE_SYS+OS_CPU_ARM_CONTROL_INT_DIS)
ARM1176_MODE_SVC_INT_OFF EQU (ARM1176_MODE_SVC+OS_CPU_ARM_CONTROL_INT_DIS)

;*******************************************************************************
;** ARM1176_INTR_Initialise
;** This functions tells the ARM core to use the interrupt vector table from
;** address "ARM1176_INTR_VectorTable" instead of 0x00000000.
;*******************************************************************************

    EXPORT ARM1176_INTR_Initialise
ARM1176_INTR_Initialise PROC ; 23486780
    stmfd sp!,{r0-r1,lr}
    ldr r0,arm1176_intr_vector_table
    mcr p15,0,r0,c12,c0,0 
    ldmfd sp!,{r0-r1,pc}
    ENDP 

;*******************************************************************************
;** The interrupt vector table
;*******************************************************************************

    EXPORT ARM1176_INTR_VectorTable
ARM1176_INTR_VectorTable ; 23487604
    ldr pc,arm1176_intr_reset_vector    ; jump to the RESET handler
    ldr pc,arm1176_intr_undef_vector    ; jump to the UNDEFINED instruction
    ldr pc,arm1176_intr_swi_vector      ; jump to the Software interrupt handler
    ldr pc,arm1176_intr_prefetch_vector      ; jump to the PREFETCH ABORT handler
    ldr pc,arm1176_intr_abort_vector ; jump to the DATA ABORT handler
    ldr pc,arm1176_intr_reserved_vector    ; reserved for future use
    ldr pc,arm1176_intr_irq_vector                                 ; jump to the Normal IRQ handler
    ldr pc,arm1176_intr_fiq_vector      ; jump to the Fast IRQ handler

arm1176_intr_reset_vector    dcd 0
arm1176_intr_undef_vector    dcd OS_CPU_ARM_ExceptUndefInstrHndlr
arm1176_intr_swi_vector      dcd OS_CPU_ARM_ExceptSwiHndlr
arm1176_intr_prefetch_vector dcd OS_CPU_ARM_ExceptPrefetchAbortHndlr
arm1176_intr_abort_vector    dcd OS_CPU_ARM_ExceptDataAbortHndlr
arm1176_intr_reserved_vector dcd 0
arm1176_intr_irq_vector      dcd OS_CPU_ARM_ExceptIrqHndlr
arm1176_intr_fiq_vector      dcd OS_CPU_ARM_ExceptFiqHndlr

arm1176_intr_vector_table    dcd ARM1176_INTR_VectorTable
 
;********************************************************************************************************
;********************************************************************************************************
;                                        EXCEPTION HANDLERS
;********************************************************************************************************
;********************************************************************************************************

;********************************************************************************************************
;                               UNDEFINED INSTRUCTION EXCEPTION HANDLER
;
; Register Usage:  R0     Exception Type
;                  R1
;                  R2     Return PC
;********************************************************************************************************

    EXPORT OS_CPU_ARM_ExceptUndefInstrHndlr
OS_CPU_ARM_ExceptUndefInstrHndlr PROC
    push       {r0, r1, r2, r3}
    mov        r2, lr
    mov        r0, #0x1
    b          OS_CPU_ARM_ExceptHndlr
    ENDP


;********************************************************************************************************
;                                SOFTWARE INTERRUPT EXCEPTION HANDLER
;
; Register Usage:  R0     Exception Type
;                  R1
;                  R2     Return PC
;********************************************************************************************************

    EXPORT OS_CPU_ARM_ExceptSwiHndlr
OS_CPU_ARM_ExceptSwiHndlr PROC
    push       {r0, r1, r2, r3}
    mov        r2, lr
    mov        r0, #0x2
    b          OS_CPU_ARM_ExceptHndlr
    ENDP


;********************************************************************************************************
;                                  PREFETCH ABORT EXCEPTION HANDLER
;
; Register Usage:  R0     Exception Type
;                  R1
;                  R2     Return PC
;********************************************************************************************************

    EXPORT OS_CPU_ARM_ExceptPrefetchAbortHndlr
OS_CPU_ARM_ExceptPrefetchAbortHndlr PROC
    sub        lr, lr, #0x4
    push       {r0, r1, r2, r3}
    mov        r2, lr
    mov        r0, #0x3
    b          OS_CPU_ARM_ExceptHndlr
    ENDP


;********************************************************************************************************
;                                    DATA ABORT EXCEPTION HANDLER
;
; Register Usage:  R0     Exception Type
;                  R1
;                  R2     Return PC
;********************************************************************************************************

    EXPORT OS_CPU_ARM_ExceptDataAbortHndlr
OS_CPU_ARM_ExceptDataAbortHndlr PROC
    sub        lr, lr, #0x8
    push       {r0, r1, r2, r3}
    mov        r2, lr
    mov        r0, #0x4
    b          OS_CPU_ARM_ExceptHndlr
    ENDP


;********************************************************************************************************
;                                   ADDRESS ABORT EXCEPTION HANDLER
;
; Register Usage:  R0     Exception Type
;                  R1
;                  R2     Return PC
;********************************************************************************************************

OS_CPU_ARM_ExceptAddrAbortHndlr PROC
    sub        lr, lr, #0x8
    push       {r0, r1, r2, r3}
    mov        r2, lr
    mov        r0, #0x5
    b          OS_CPU_ARM_ExceptHndlr
    ENDP


;********************************************************************************************************
;                                 INTERRUPT REQUEST EXCEPTION HANDLER
;
; Register Usage:  R0     Exception Type
;                  R1
;                  R2     Return PC
;********************************************************************************************************

    EXPORT OS_CPU_ARM_ExceptIrqHndlr
OS_CPU_ARM_ExceptIrqHndlr PROC
    sub        lr, lr, #0x4
    push       {r0, r1, r2, r3}
    mov        r2, lr
    mov        r0, #0x6
    b          OS_CPU_ARM_ExceptHndlr
    ENDP


;********************************************************************************************************
;                              FAST INTERRUPT REQUEST EXCEPTION HANDLER
;
; Register Usage:  R0     Exception Type
;                  R1
;                  R2     Return PC
;********************************************************************************************************

    EXPORT OS_CPU_ARM_ExceptFiqHndlr
OS_CPU_ARM_ExceptFiqHndlr PROC
    sub        lr, lr, #0x4
    push       {r0, r1, r2, r3}
    mov        r2, lr
    mov        r0, #0x7
    b          OS_CPU_ARM_ExceptHndlr
    ENDP


;********************************************************************************************************
;                                      GLOBAL EXCEPTION HANDLER
;
; Register Usage:  R0     Exception Type
;                  R1     Exception's SPSR
;                  R2     Return PC
;                  R3     Exception's SP
;
; Note(s)       : 1) An exception can occur in three different circumstances; in each of these, the
;                    SVC stack pointer will point to a different entity :
;
;                    a) CONDITION: An exception occurs before the OS has been fully initialized.
;                       SVC STACK: Should point to a stack initialized by the application's startup code.
;                       STK USAGE: Interrupted context -- SVC stack.
;                                  Exception           -- SVC stack.
;                                  Nested exceptions   -- SVC stack.
;
;                    b) CONDITION: An exception interrupts a task.
;                       SVC STACK: Should point to task stack.
;                       STK USAGE: Interrupted context -- Task stack.
;                                  Exception           -- Exception stack 'OS_CPU_ExceptStk[]'.
;                                  Nested exceptions   -- Exception stack 'OS_CPU_ExceptStk[]'.
;
;                    c) CONDITION: An exception interrupts another exception.
;                       SVC STACK: Should point to location in exception stack, 'OS_CPU_ExceptStk[]'.
;                       STK USAGE: Interrupted context -- Exception stack 'OS_CPU_ExceptStk[]'.
;                                  Exception           -- Exception stack 'OS_CPU_ExceptStk[]'.
;                                  Nested exceptions   -- Exception stack 'OS_CPU_ExceptStk[]'.
;********************************************************************************************************

OS_CPU_ARM_ExceptHndlr
    mrs r1,spsr                         ; store spsr in r1 to be passed to SYS mode
    mov r3,sp                           ; save surrent stack pointer in r3 to be passed to SYS mode
    add sp,sp,#16                       ; adjust IRQ stack pointer to initial value
    msr cpsr_c,#ARM1176_MODE_SVC_INT_OFF; switch to SVC mode with interrupts disabled
    stmfd sp!,{r2}                      ; store passed pc value of interrupted task on current task stack
    stmfd sp!,{lr}                      ; store lr of interrupted task on current task stack
    stmfd sp!,{r4-r12}                  ; store current registers r12..r4 on current task stack
    ldmfd r3!,{r5-r8}                   ; load previous r3..r1 from IRQ sp (passed in r1) into r6..r4
    stmfd sp!,{r5-r8}                   ; store previous r3..r1 from IRQ stack on current task stack
    stmfd sp!,{r1}                      ; store spsr (passed in r1) current task stack (16 regs are stored)

    msr        cpsr_c, #ARM1176_MODE_SVC_INT_OFF
    ldm        sp!, {r0}
    msr        spsr_fsxc, r0
    ldmfd sp!, {r0-r3,r4-r12,lr,pc}^

;*******************************************************************************
;** End of file
;*******************************************************************************

    END 