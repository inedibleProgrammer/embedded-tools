.syntax unified
.cpu cortex-m4
.thumb

.word 0x20020000        /* _estack: top of RAM */
.word _start+1            /* Reset handler. The +1 is necessary to specify thumb mode */
.word Default_Handler   /* NMI_Handler */
.word Default_Handler   /* HardFault_Handler */

.text
.global _start
_start:
    b .                 /* Just infinite loop */

.type Default_Handler, %function
Default_Handler:
    b .                 /* Also infinite loop */
