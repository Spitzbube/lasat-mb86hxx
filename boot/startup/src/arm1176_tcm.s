
    AREA    ARM1176INIT, CODE, READONLY

    EXPORT  ARM1176_TcmInitialise
    EXPORT  OS_CPU_ExceptStk


svc_stack
    DCD 0x0f004000

fiq_stack
    DCD 0x0f003000

irq_stack
    DCD 0x0f002c00

abort_stack
    DCD 0x0f001c00

undefined_stack
    DCD 0x0f001800

sys_stack
    DCD 0x0f001400

usr_stack
    DCD 0x0f001000

OS_CPU_ExceptStk
    dcd 0x0f000c00


ARM1176_TcmInitialise
    mov        r0, #0xf000000
    mov        r1, #0x15
    orr        r1, r1, r0
    mcr        p15, #0x0, r1, c9, c1, #0x0
    mov        r1, #0xd5000000
    ldr        r0, [r1]
    cmp        r0, #0x0
    beq        loc_234879f0

    mov        r0, #0xf000000
    mov        r1, #0x15
    orr        r1, r1, r0
    mcr        p15, #0x0, r1, c9, c1, #0x0
    mov        r1, #0x2000000
    str        r0, [r1, #132]
    mov        r0, #0xe000000
    mov        r1, #0x15
    orr        r1, r1, r0
    mcr        p15, #0x0, r1, c9, c1, #0x1
    mov        r1, #0x2000000
    str        r0, [r1, #120]

    ;/* Setup the stack for each mode */

    ldr r0, undefined_stack
    msr CPSR_c, #0xdb   ;/* Undefined Instruction Mode  */
    mov sp, r0

    ldr r0, abort_stack
    msr CPSR_c, #0xd7   ;/* Abort Mode */
    mov sp, r0

    ldr r0, irq_stack
    msr CPSR_c, #0xd2   ;/* IRQ Mode */
    mov sp, r0

    ldr r0, fiq_stack
    msr CPSR_c, #0xd1   ;/* FIQ Mode */
    mov sp, r0

    ldr r0, svc_stack
    msr CPSR_c, #0xd3   ;/* Supervisor Mode */
    mov sp, r0

    ldr r0, usr_stack
    msr CPSR_c, #0xdf   ;/* User Mode */
    mov sp, r0

    bx  lr

loc_234879f0
    mov        r0, #0xf000000
    mov        r1, #0x15
    orr        r1, r1, r0
    mcr        p15, #0x0, r1, c9, c1, #0x0
    mov        r1, #0x2000000
    str        r0, [r1, #120]
    mov        r0, #0xe000000
    mov        r1, #0x15
    orr        r1, r1, r0
    mcr        p15, #0x0, r1, c9, c1, #0x1
    mov        r1, #0x2000000
    str        r0, [r1, #112]

    ;/* Setup the stack for each mode */

    ldr r0, undefined_stack
    msr CPSR_c, #0xdb   ;/* Undefined Instruction Mode  */
    mov sp, r0

    ldr r0, abort_stack
    msr CPSR_c, #0xd7   ;/* Abort Mode */
    mov sp, r0

    ldr r0, irq_stack
    msr CPSR_c, #0xd2   ;/* IRQ Mode */
    mov sp, r0

    ldr r0, fiq_stack
    msr CPSR_c, #0xd1   ;/* FIQ Mode */
    mov sp, r0

    ldr r0, svc_stack
    msr CPSR_c, #0xd3   ;/* Supervisor Mode */
    mov sp, r0

    ldr r0, usr_stack
    msr CPSR_c, #0xdf   ;/* User Mode */
    mov sp, r0

    bx  lr

    END

