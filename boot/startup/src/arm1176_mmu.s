

    EXPORT  ARM1176_MmuInitialise

    AREA    ARM1176INIT, CODE, READONLY

ARM1176_MmuInitialise

;*******************************************************************************
;** save link register on r11 as we are using bl commands internally
;*******************************************************************************

    MOV      r11,lr

;*******************************************************************************
;** if MMU/MPU enabled - disable (useful for ARMulator tests)
;*******************************************************************************

    MRC      p15,#0x0,r0,c1,c0,#0 ; read CP15 register 1 into r0
    BIC      r0,r0,#0x1000        ; disable I-cache
    BIC      r0,r0,#4             ; disable D-cache
    BIC      r0,r0,#1             ; disable MMU
    MCR      p15,#0x0,r0,c1,c0,#0 ; write value back

;*******************************************************************************
;** MMU Configuration
;**
;** Configure system to use extended v6 format pagetables
;** Set translation table base
;** Specify v6 format pagetables with no subpages
;** set bit 23 [XP] in CP15 control register.
;** ARM1176 supports two translation tables
;** Configure translation table base (TTB) control register cp15,c2
;** to a value of all zeros, indicates we are using TTB register 0.
;*******************************************************************************

    MRC      p15,#0x0,r0,c1,c0,#0
    MOV      r1,#0x800000
    ORR      r0,r0,r1
    MCR      p15,#0x0,r0,c1,c0,#0
    MOV      r0,#0
    MCR      p15,#0x0,r0,c2,c0,#2
    LDR      r0,Data_21b106e0  ; ARM1176_PHYSICAL_TTB_BASE
    MCR      p15,#0x0,r0,c2,c0,#0

;*******************************************************************************
;** PAGE TABLE generation
;**
;** Generate the page tables
;** Build a flat translation table for the whole address space.
;** ie: Create 4096 1MB sections from 0x000xxxxx to 0xFFFxxxxx
;**
;** |31................20|19..18|17|16| 15|14..12|11.10|9|8....5| 4|3.2|1.0|
;** |section base address| 0   0|nG| S|APX|   TEX|  AP |P|Domain|XN|C B|1 0|
;**
;** Bits[31:20] Top 12 bits of VA is pointer into table
;** nG[17]=0.   Non global, enables matching against ASID in the TLB when set.
;** S[16]=0.    Indicates normal memory is shared when set.
;** Access Permissions - configure for full read/write access in all modes
;** APX[15]=0 and AP[11:10]=11
;**
;** Set attributes to normal memory, non cacheable.
;** TEX[14:12]=001 and CB[3:2]= 00
;** P[9]=0.     ECC enabled memory (not supported on ARM1136).
;** Domain[5:8]=1111 = Set all pages to use domain 15
;** XN[4]:=0    Execute never disabled.
;** Bits[1:0]   Indicate entry is a 1MB section.
;**
;** r0 contains the address of the translation table base
;** r1 is loop counter
;** r2 is level1 descriptor (bits 19:0)
;**
;** use loop counter to create 4096 individual table entries
;** this writes from address 0x7FFC down to 0x4000 in word steps (4bytes).
;**
;** In this example we will set the cacheable attribute in the first descriptor
;**  only, so virtual memory from 0 to 1MB will be cacheable (write back mode).
;** TEX[14:12]=000 and CB[3:2]=11
;*******************************************************************************

;*******************************************************************************
;** create empty TTB entries to initialize entries 0..2047
;** r0 = TTB base address
;** r1 = unused
;** r2 = unused
;** r3 = virtual DDR address, upper 12 bits shifted 20 bits right (virt. index)
;** r4 = remap size upper 12 bits shifted 20 bits right (table max. index)
;** r5 = unused
;*******************************************************************************

    LDR      r0,Data_21b106e0
    MOV      r1,#0             ; 0x00000000 == disable access
    MOV      r2,#0             ; remap addresses from 0x00000000..
    MOV      r3,#0             ;                   to 0x00000000..
    MOV      r4,#0x80000000    ; fixed remap RAM size (2048MB)
    BL       func_21b106b4     ; update mmu table entries

;*******************************************************************************
;** set the the internal ROM to non-cachable/non-bufferable
;*******************************************************************************

    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4   ; 0xde2
    MOV      r2,#0              ; ARM1176_PHYSICAL_ROM_BASE
    MOV      r3,#0              ; ARM1176_REMAPPED_ROM_BASE
    MOV      r4,#0x100000       ; ARM1176_PHYSICAL_ROM_SIZE
    BL       func_21b106b4

;*******************************************************************************
;** set the the internal RAM to non-cachable/non-bufferable
;*******************************************************************************

    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4    ; 0xde2
    MOV      r2,#0x02000000      ; ARM1176_PHYSICAL_RAM_BASE
    MOV      r3,#0x02000000      ; ARM1176_REMAPPED_RAM_BASE
    MOV      r4,#0x00100000      ; ARM1176_PHYSICAL_RAM_SIZE
    BL       func_21b106b4

;*******************************************************************************
;** set the the internal TCM buffers to non-cachable/non-bufferable
;*******************************************************************************

    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4    ; 0xde2
    MOV      r2,#0x0f000000      ; ARM1176_PHYSICAL_TCM_BASE
    MOV      r3,#0x0f000000      ; ARM1176_REMAPPED_TCM_BASE
    MOV      r4,#0x00100000      ; ARM1176_PHYSICAL_TCM_SIZE
    BL       func_21b106b4

;*******************************************************************************
;** set entire 64 Mbytes in DDR1 memory to be cachable/bufferable
;*******************************************************************************

    LDR      r0,Data_21b106e0
    LDR      r1,=0xdea                 ; Data_21b106e8    ; 0xdee
    MOV      r2,#0x20000000      ; ARM1176_PHYSICAL_DDR1_BASE
    MOV      r3,#0x20000000      ; ARM1176_REMAPPED_DDR1_BASE
    MOV      r4,#0x04000000      ; ARM1176_PHYSICAL_DDR1_SIZE
    BL       func_21b106b4


;    LDR      r0,Data_21b106e0
;    LDR      r1,Data_21b106e4    ; 0xde2
;    MOV      r2,#0x20000000
;    MOV      r3,#0x20000000
;    MOV      r4,#0x1b00000
;    BL       func_21b106b4


    LDR      r0,Data_21b106e0
    LDR      r1,=0xde2
    MOV      r2,#0x20000000      ; ARM1176_PHYSICAL_DDR1_BASE
    MOV      r3,#0x20000000      ; ARM1176_REMAPPED_DDR1_BASE
    MOV      r4,#0x03400000      ; ?
    BL       func_21b106b4


    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e8     ; 0xdee
    MOV      r2,#0x40000000
    MOV      r3,#0x40000000
    MOV      r4,#0x4000000
    BL       func_21b106b4


    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4     ; 0xde2
    MOV      r2,#0x40000000
    MOV      r3,#0x40000000
    MOV      r4,#0x2000000
    BL       func_21b106b4


    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4
    MOV      r2,#0x60000000
    MOV      r3,#0x60000000
    MOV      r4,#0x1200000
    BL       func_21b106b4


    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4
    MOV      r2,#0x80000000
    MOV      r3,#0x80000000
    MOV      r4,#0x80000000
    BL       func_21b106b4


    MRC      p15,#0x0,r0,c3,c0,#0
    LDR      r0,Data_21b106ec
    MCR      p15,#0x0,r0,c3,c0,#0
    MRC      p15,#0x0,r0,c1,c0,#0
    ORR      r0,r0,#0x1000
    ORR      r0,r0,#4
    ORR      r0,r0,#1
    ORR      r0,r0,#0x400000
    MCR      p15,#0x0,r0,c1,c0,#0
    MOV      lr,r11
    BX       lr

func_21b106b4
    LSR      r2,r2,#20
    LSR      r3,r3,#20
    LSR      r4,r4,#20
    ADD      r4,r4,r3
l_21b106c4
    ORR      r5,r1,r2,LSL #20
    STR      r5,[r0,r3,LSL #2]
    ADD      r3,r3,#1
    ADD      r2,r2,#1
    CMP      r3,r4
    BNE      l_21b106c4
    BX       lr

Data_21b106e0
    DCD 0x02004000
Data_21b106e4
    DCD 0x00000de2
Data_21b106e8
    DCD 0x00000dee
Data_21b106ec
    DCD 0x55555555

    END

