.syntax unified
.cpu cortex-m4
.thumb

.equ RCC, 0x40023800

.word 0x20020000        /* _estack: top of RAM */
.word _start+1            /* Reset handler. The +1 is necessary to specify thumb mode */
.word Default_Handler   /* NMI_Handler */
.word Default_Handler   /* HardFault_Handler */

.text
.global _start
_start:
    /* Enable GPIOA clock (RCC_AHB1ENR |= (1 << 0)) */
    LDR   R0, =0x40023830     /* RCC_AHB1ENR */
    LDR   R1, [R0]
    ORR   R1, R1, #1          /* Set bit 0: GPIOAEN */
    STR   R1, [R0]

    /* Configure PA5 as output (MODER[11:10] = 01) */
    LDR   R0, =0x40020000     /* GPIOA base */
    LDR   R1, [R0]            /* GPIOA_MODER */
    BIC   R1, R1, #(3 << (5 * 2))  /* Clear bits 11:10 */
    ORR   R1, R1, #(1 << (5 * 2))  /* Set bit 10 (output) */
    STR   R1, [R0]

    /* Set PA5 high (GPIOA_ODR |= (1 << 5)) */
    LDR   R0, =0x40020014     /* GPIOA_ODR */
    LDR   R1, [R0]
    ORR   R1, R1, #(1 << 5)
    STR   R1, [R0]

.type Default_Handler, %function
Default_Handler:
    b .                 /* Also infinite loop */
