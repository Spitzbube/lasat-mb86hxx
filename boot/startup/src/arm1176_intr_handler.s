    AREA ARM1176IVT, CODE, READONLY, ALIGN=6
    PRESERVE8 


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
arm1176_intr_undef_vector    dcd 0
arm1176_intr_swi_vector      dcd 0
arm1176_intr_prefetch_vector dcd 0
arm1176_intr_abort_vector    dcd 0
arm1176_intr_reserved_vector dcd 0
arm1176_intr_irq_vector      dcd 0
arm1176_intr_fiq_vector      dcd 0

arm1176_intr_vector_table    dcd ARM1176_INTR_VectorTable
 
;*******************************************************************************
;** End of file
;*******************************************************************************

    END 