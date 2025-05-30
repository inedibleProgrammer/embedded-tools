;; This file was written by chat gpt
;; 

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
    b .                       // Infinite loop
