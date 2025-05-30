.syntax unified
.cpu cortex-m4
.thumb

// Vector table section placed at beginning of flash
.section .isr_vector, "a", %progbits
.type g_pfnVectors, %object
.size g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
    .word _estack             // Initial stack pointer
    .word Reset_Handler       // Reset vector

// Top of stack: end of SRAM (STM32F401CC = 0x20018000)
.equ _estack, 0x20018000

.equ RCC_AHB1ENR,    0x40023830
.equ GPIOA_MODER,    0x40020000
.equ GPIOA_ODR,      0x40020014	

// Define the Reset Handler (entry point)
.section .text.Reset_Handler, "ax", %progbits
.global Reset_Handler
.type Reset_Handler, %function

Reset_Handler:
    b _start                  // Branch to _start (optional indirection)

// Define _start for symbolic/debugging use
.section .text._start, "ax", %progbits
.global _start
.type _start, %function

_start:
    /* Enable clock to GPIOA (bit 0 in RCC_AHB1ENR) */
    LDR R0, =RCC_AHB1ENR
    LDR R1, [R0]
    ORR R1, R1, #(1 << 0)
    STR R1, [R0]

    /* Set PA5 (bit 10/11 in GPIOA_MODER) to output (01) */
    LDR R0, =GPIOA_MODER
    LDR R1, [R0]
    BIC R1, R1, #(0b11 << (5 * 2))  /* Clear bits 11:10 */
    ORR R1, R1, #(0b01 << (5 * 2))  /* Set bits 11:10 to 01 */
    STR R1, [R0]

    /* Set PA5 high (bit 5 in GPIOA_ODR) */
    LDR R0, =GPIOA_ODR
    LDR R1, [R0]
    ORR R1, R1, #(1 << 5)
    STR R1, [R0]

loop:
    B loop    /* Infinite loop */
