    AREA ARM1176IVT, CODE, READONLY, ALIGN=6
    PRESERVE8 

;*******************************************************************************
;** Far external symbols, required for linking
;*******************************************************************************

    IMPORT intr_set_vectaddrx
    IMPORT OSIntExit
    IMPORT OSTaskSwHook
    IMPORT OS_CPU_ExceptHndlr
    IMPORT OSIntNesting
    IMPORT OSRunning
    IMPORT OSTCBCur
    IMPORT OS_CPU_ExceptStkBase
    IMPORT Data_234942b0
    IMPORT  OSTCBHighRdy
    IMPORT  OSPrioCur
    IMPORT  OSPrioHighRdy
    EXPORT	OSStartHighRdy
    EXPORT  OSCtxSw
    EXPORT OS_CPU_SR_INT_En
    EXPORT OS_CPU_SR_INT_Dis
    EXPORT OSIntCtxSw
    EXPORT OS_CPU_SR_Save
    EXPORT OS_CPU_SR_Restore


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
;** ARM1176_INTR_VicSetIrqHandler
;** This macro writes one interrupt handler function into the VIC interrupt
;** table
;*******************************************************************************

    MACRO
    ARM1176_INTR_VicSetIrqHandler $index
    mov r0,#$index
    ldr r1,=ARM1176_INTR_IrqHandler_$index
    bl intr_set_vectaddrx
    MEND


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
    ARM1176_INTR_VicSetIrqHandler 5
    ARM1176_INTR_VicSetIrqHandler 6
    ARM1176_INTR_VicSetIrqHandler 7
    ARM1176_INTR_VicSetIrqHandler 8
    ARM1176_INTR_VicSetIrqHandler 9
    ARM1176_INTR_VicSetIrqHandler 10
    ARM1176_INTR_VicSetIrqHandler 11
    ARM1176_INTR_VicSetIrqHandler 12
    ARM1176_INTR_VicSetIrqHandler 13
    ARM1176_INTR_VicSetIrqHandler 14
    ARM1176_INTR_VicSetIrqHandler 15
    ARM1176_INTR_VicSetIrqHandler 16
    ARM1176_INTR_VicSetIrqHandler 17
    ARM1176_INTR_VicSetIrqHandler 18
    ARM1176_INTR_VicSetIrqHandler 19
    ARM1176_INTR_VicSetIrqHandler 20
    ARM1176_INTR_VicSetIrqHandler 21
    ARM1176_INTR_VicSetIrqHandler 22
    ARM1176_INTR_VicSetIrqHandler 23
    ARM1176_INTR_VicSetIrqHandler 24
    ARM1176_INTR_VicSetIrqHandler 25
    ARM1176_INTR_VicSetIrqHandler 26
    ARM1176_INTR_VicSetIrqHandler 27
    ARM1176_INTR_VicSetIrqHandler 28
    ARM1176_INTR_VicSetIrqHandler 29
    ARM1176_INTR_VicSetIrqHandler 30
    ARM1176_INTR_VicSetIrqHandler 31
    ldmfd sp!,{r0-r1,pc}
    ENDP 

;*******************************************************************************
;** The normal-IRQ handlers for IRQ#5 .. IRQ#31 handled by the VIC implemented
;** as macros. IRQs#0..4 are not used because they are internally used by the
;** ARC700 cpu.
;** This version can be used for a non-rtos environment, the interrupt handler
;** calls the ISR function (from FAPI_IsrFunctionTable) as well as the
;** BSR function (from FAPI_BsrFunctionTable) if set.
;** The ISR and the BSR will be called within cpu mode IRQ, the cpu mode will
;** not changed in this implementation.
;** The final mode change to the previous cpu mode will be switched
;** automatically by the "ldmfd sp!,{r0-r4,pc}^" call at the end.
;*******************************************************************************

    MACRO
    ARM1176_INTR_IrqHandler $index
    EXPORT ARM1176_INTR_IrqHandler_$index
ARM1176_INTR_IrqHandler_$index PROC
    sub lr,lr,#4
    stmfd sp!,{r0-r3}
    mov r2, lr
    mov r0, #0x6
    mov r1, #$index<<8
    add r0, r0, r1
    b OS_CPU_ARM_ExceptHndlr
    ENDP
    MEND

;*******************************************************************************
;** Instanciate the above macro for  IRQ#5 .. IRQ#31
;*******************************************************************************

    ARM1176_INTR_IrqHandler 5 ; 234868d4
    ARM1176_INTR_IrqHandler 6
    ARM1176_INTR_IrqHandler 7
    ARM1176_INTR_IrqHandler 8
    ARM1176_INTR_IrqHandler 9
    ARM1176_INTR_IrqHandler 10
    ARM1176_INTR_IrqHandler 11
    ARM1176_INTR_IrqHandler 12
    ARM1176_INTR_IrqHandler 13
    ARM1176_INTR_IrqHandler 14
    ARM1176_INTR_IrqHandler 15
    ARM1176_INTR_IrqHandler 16
    ARM1176_INTR_IrqHandler 17
    ARM1176_INTR_IrqHandler 18
    ARM1176_INTR_IrqHandler 19
    ARM1176_INTR_IrqHandler 20
    ARM1176_INTR_IrqHandler 21
    ARM1176_INTR_IrqHandler 22
    ARM1176_INTR_IrqHandler 23
    ARM1176_INTR_IrqHandler 24
    ARM1176_INTR_IrqHandler 25
    ARM1176_INTR_IrqHandler 26
    ARM1176_INTR_IrqHandler 27
    ARM1176_INTR_IrqHandler 28
    ARM1176_INTR_IrqHandler 29
    ARM1176_INTR_IrqHandler 30
    ARM1176_INTR_IrqHandler 31 ; 23486bac

;********************************************************************************************************
;                                  CRITICAL SECTION METHOD 3 FUNCTIONS
;
; Description: Disable/Enable interrupts by preserving the state of interrupts.  Generally speaking you
;              would store the state of the interrupt disable flag in the local variable 'cpu_sr' and then
;              disable interrupts.  'cpu_sr' is allocated in all of uC/OS-II's functions that need to
;              disable interrupts.  You would restore the interrupt disable state by copying back 'cpu_sr'
;              into the CPU's status register.
;
; Prototypes : OS_CPU_SR  OS_CPU_SR_Save    (void);
;              void       OS_CPU_SR_Restore (OS_CPU_SR  os_cpu_sr);
;
;
; Note(s)    : (1) These functions are used in general like this:
;
;                 void Task (void  *p_arg)
;                 {
;                                                               /* Allocate storage for CPU status register.            */
;                 #if (OS_CRITICAL_METHOD == 3)
;                      OS_CPU_SR  os_cpu_sr;
;                 #endif
;
;                          :
;                          :
;                      OS_ENTER_CRITICAL();                     /* os_cpu_sr = OS_CPU_SR_Save();                        */
;                          :
;                          :
;                      OS_EXIT_CRITICAL();                      /* OS_CPU_SR_Restore(cpu_sr);                           */
;                          :
;                          :
;                 }
;********************************************************************************************************
 
OS_CPU_SR_Save
    MRS     R0, CPSR
    ORR     R1, R0, #OS_CPU_ARM_CONTROL_INT_DIS                 ; Set IRQ and FIQ bits in CPSR to disable all interrupts.
    MSR     CPSR_c, R1
    BX      LR                                                  ; Disabled, return the original CPSR contents in R0.


OS_CPU_SR_Restore
    MSR     CPSR_c, R0
    BX      LR 

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
;                                           START MULTITASKING
;                                       void OSStartHighRdy(void)
;
; Note(s) : 1) OSStartHighRdy() MUST:
;              a) Call OSTaskSwHook() then,
;              b) Set OSRunning to TRUE,
;              c) Switch to the highest priority task.
;********************************************************************************************************

OSStartHighRdy
    MSR      CPSR_c,#ARM1176_MODE_SVC_INT_OFF
    LDR      R0,=OSTaskSwHook
    MOV      LR, PC
    BX       R0
    ldr      r0, =OSRunning
    mov      r1, #0x1
    strb     r1, [r0]
    ldr      r0, =OSTCBHighRdy
    ldr      r0, [r0]
    ldr      sp, [r0]
    pop      {r0}
    msr      spsr_fsxc, r0
    ldm      sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip, lr, pc}^

;********************************************************************************************************
;                         PERFORM A CONTEXT SWITCH (From task level) - OSCtxSw()
;
; Note(s) : 1) OSCtxSw() is called in SVC mode with BOTH FIQ and IRQ interrupts DISABLED.
;
;           2) The pseudo-code for OSCtxSw() is:
;              a) Save the current task's context onto the current task's stack,
;              b) OSTCBCur->OSTCBStkPtr = SP;
;              c) OSTaskSwHook();
;              d) OSPrioCur             = OSPrioHighRdy;
;              e) OSTCBCur              = OSTCBHighRdy;
;              f) SP                    = OSTCBHighRdy->OSTCBStkPtr;
;              g) Restore the new task's context from the new task's stack,
;              h) Return to new task's code.
;
;           3) Upon entry:
;              OSTCBCur      points to the OS_TCB of the task to suspend,
;              OSTCBHighRdy  points to the OS_TCB of the task to resume.
;********************************************************************************************************

OSCtxSw
    stmdb    sp!, {lr}
    stmdb    sp!, {lr}
    push     {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip}
    mrs      r0, apsr
    tst      lr, #0x1
    orrne    r0, r0, #0x20
    stmdb    sp!, {r0}
    ldr      r0,=OSTCBCur
    ldr      r1, [r0]
    str      sp, [r1]
    ldr      r0, =OSTaskSwHook
    mov      lr, pc
    bx       r0
    ldr      r0, =OSPrioCur
    ldr      r1, =OSPrioHighRdy
    ldrb     r2, [r1]
    strb     r2, [r0]
    ldr      r0, =OSTCBCur
    ldr      r1, =OSTCBHighRdy
    ldr      r2, [r1]
    str      r2, [r0]
    ldr      sp, [r2]
    ldm      sp!, {r0}
    msr      spsr_fsxc, r0
    ldm      sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip, lr, pc}^


;********************************************************************************************************
;                     PERFORM A CONTEXT SWITCH (From interrupt level) - OSIntCtxSw()
;
; Note(s) : 1) OSIntCtxSw() is called in SVC mode with BOTH FIQ and IRQ interrupts DISABLED.
;
;           2) The pseudo-code for OSCtxSw() is:
;              a) OSTaskSwHook();
;              b) OSPrioCur             = OSPrioHighRdy;
;              c) OSTCBCur              = OSTCBHighRdy;
;              d) SP                    = OSTCBHighRdy->OSTCBStkPtr;
;              e) Restore the new task's context from the new task's stack,
;              f) Return to new task's code.
;
;           3) Upon entry:
;              OSTCBCur      points to the OS_TCB of the task to suspend,
;              OSTCBHighRdy  points to the OS_TCB of the task to resume.
;********************************************************************************************************

OSIntCtxSw
    ldr        r0, =OSTaskSwHook
    mov        lr, pc
    bx         r0                                                  ; OSTaskSwHook
    ldr        r0, =OSPrioCur                              ; dword_2348790c
    ldr        r1, =OSPrioHighRdy                                 ; dword_23487910
    ldrb       r2, [r1]
    strb       r2, [r0]
    ldr        r0, =OSTCBCur                              ; dword_23487914
    ldr        r1, =OSTCBHighRdy                                 ; dword_23487918
    ldr        r2, [r1]
    str        r2, [r0]
    ldr        sp, [r2]
    ldm        sp!, {r0}
    msr        spsr_fsxc, r0
    ldm      sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip, lr, pc}^


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

    ldr        r3, =OSRunning
    ldrb       r4, [r3]                                            ; byte_20410016
    cmp        r4, #0x1
    bne        OS_CPU_ARM_ExceptHndlr_BreakNothing

    ldr        r3, =OSIntNesting                                     ; dword_2040751c,0x20410010
    ldrb       r4, [r3]                                            ; 0x20410010
    add        r4, r4, #0x1
    strb       r4, [r3]                                            ; 0x20410010
    cmp        r4, #0x1
    bne        OS_CPU_ARM_ExceptHndlr_BreakExcept

;********************************************************************************************************
;                                 EXCEPTION HANDLER: TASK INTERRUPTED
;
; Register Usage:  R0     Exception Type
;                  R1
;                  R2
;                  R3
;********************************************************************************************************

OS_CPU_ARM_ExceptHndlr_BreakTask

    ldr        r3, =OSTCBCur                                 ; dword_20407514,dword_20410024
    ldr        r4, [r3]                                            ; dword_20410024
    str        sp, [r4]
    ldr        r3, =OS_CPU_ExceptStkBase
    ldr        sp, [r3]
    ldr        r1, =OS_CPU_ExceptHndlr
    mov        lr, pc
    bx         r1
    msr        cpsr_c, #ARM1176_MODE_SVC_INT_OFF
    ldr        r0, =OSIntExit
    mov        lr, pc
    bx         r0
    ldr        r3, =OSTCBCur                                 ; dword_20407514
    ldr        r4, [r3]
    ldr        sp, [r4]
    ldm        sp!,{r0}
    msr        spsr_fsxc, r0
    ldmfd sp!,{r0-r3,r4-r12,lr,pc}^    ; continue with new tasks context

OS_CPU_ARM_ExceptHndlr_BreakExcept
    ldr        r3, =Data_234942b0
    str        sp, [r3]
    ldr        r3, =OS_CPU_ExceptHndlr
    mov        lr, pc
    bx         r3
    msr        cpsr_c, #ARM1176_MODE_SVC_INT_OFF
    ldr        r3, =OSIntNesting                                     ; dword_2040751c
    ldrb       r4, [r3]
    sub        r4, r4, #0x1
    strb       r4, [r3]
    ldm        sp!, {r0}
    msr        spsr_fsxc, r0
    ldmfd sp!, {r0-r3,r4-r12,lr,pc}^

OS_CPU_ARM_ExceptHndlr_BreakNothing
    ldr        r3, =OS_CPU_ExceptHndlr
    mov        lr, pc
    bx         r3
    msr        cpsr_c, #ARM1176_MODE_SVC_INT_OFF
    ldm        sp!, {r0}
    msr        spsr_fsxc, r0
    ldmfd sp!, {r0-r3,r4-r12,lr,pc}^


;********************************************************************************************************
;********************************************************************************************************
;                                 ENABLE & DISABLE INTERRUPTS, IRQs, FIQs
;********************************************************************************************************
;********************************************************************************************************

;********************************************************************************************************
;                                       ENABLE & DISABLE INTERRUPTS
;
; Note(s) : 1) OS_CPU_SR_INT_En() can be called by OS_CPU_ExceptHndlr() AFTER the external
;              interrupt source has been cleared.  This function will enable IRQs and FIQs so that
;              nesting can occur.
;
;           2) OS_CPU_ARM_INT_Dis() can be called to disable IRQs and FIQs so that nesting will not occur.
;********************************************************************************************************

OS_CPU_SR_INT_En
    mrs        r0, apsr
    bic        r0, r0, #OS_CPU_ARM_CONTROL_INT_DIS
    msr        cpsr_c, r0
    bx         lr

OS_CPU_SR_INT_Dis
    mrs        r0, apsr
    orr        r0, r0, #OS_CPU_ARM_CONTROL_INT_DIS
    msr        cpsr_c, r0
    bx         lr

;*******************************************************************************
;** End of file
;*******************************************************************************

    END 