.syntax unified
.cpu cortex-m4
.thumb


.section .text
.word 0x20020000        /* _estack: Top of 128KB RAM */
.word _start            /* Reset handler */


.global _start
_start:
    b .                 /* Infinite loop */
