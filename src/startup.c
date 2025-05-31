#include <stdint.h>

// Symbols from the linker script
extern uint32_t _sdata, _edata, _etext;
extern uint32_t _sbss, _ebss;
extern uint32_t _estack;

extern uint32_t _heap_start, _heap_end;
extern uint32_t _stack_start, _stack_end;

int main(void);

void Reset_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void NMI_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void HardFault_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void MemManage_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void BusFault_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void UsageFault_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void SVC_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void DebugMon_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void PendSV_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void SysTick_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void WWDG_IRQHandler(void);                    /* Window WatchDog              */
__attribute__((weak, alias("Default_Handler"))) void PVD_IRQHandler(void);                     /* PVD through EXTI Line detection */
__attribute__((weak, alias("Default_Handler"))) void TAMP_STAMP_IRQHandler(void);              /* Tamper and TimeStamps through the EXTI line */
__attribute__((weak, alias("Default_Handler"))) void RTC_WKUP_IRQHandler(void);                /* RTC Wakeup through the EXTI line */
__attribute__((weak, alias("Default_Handler"))) void FLASH_IRQHandler(void);                   /* FLASH                        */
__attribute__((weak, alias("Default_Handler"))) void RCC_IRQHandler(void);                     /* RCC                          */
__attribute__((weak, alias("Default_Handler"))) void EXTI0_IRQHandler(void);                   /* EXTI Line0                   */
__attribute__((weak, alias("Default_Handler"))) void EXTI1_IRQHandler(void);                   /* EXTI Line1                   */
__attribute__((weak, alias("Default_Handler"))) void EXTI2_IRQHandler(void);                   /* EXTI Line2                   */
__attribute__((weak, alias("Default_Handler"))) void EXTI3_IRQHandler(void);                   /* EXTI Line3                   */
__attribute__((weak, alias("Default_Handler"))) void EXTI4_IRQHandler(void);                   /* EXTI Line4                   */
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream0_IRQHandler(void);            /* DMA1 Stream 0                */
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream1_IRQHandler(void);            /* DMA1 Stream 1                */
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream2_IRQHandler(void);            /* DMA1 Stream 2                */
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream3_IRQHandler(void);            /* DMA1 Stream 3                */
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream4_IRQHandler(void);            /* DMA1 Stream 4                */
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream5_IRQHandler(void);            /* DMA1 Stream 5                */
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream6_IRQHandler(void);            /* DMA1 Stream 6                */
__attribute__((weak, alias("Default_Handler"))) void ADC_IRQHandler(void);                     /* ADC1(void); ADC2 and ADC3s   */
__attribute__((weak, alias("Default_Handler"))) void EXTI9_5_IRQHandler(void);                 /* External Line[9:5]s          */
__attribute__((weak, alias("Default_Handler"))) void TIM1_BRK_TIM9_IRQHandler(void);           /* TIM1 Break and TIM9          */
__attribute__((weak, alias("Default_Handler"))) void TIM1_UP_TIM10_IRQHandler(void);           /* TIM1 Update and TIM10        */
__attribute__((weak, alias("Default_Handler"))) void TIM1_TRG_COM_TIM11_IRQHandler(void);      /* TIM1 Trigger and Commutation and TIM11 */
__attribute__((weak, alias("Default_Handler"))) void TIM1_CC_IRQHandler(void);                 /* TIM1 Capture Compare         */
__attribute__((weak, alias("Default_Handler"))) void TIM2_IRQHandler(void);                    /* TIM2                         */
__attribute__((weak, alias("Default_Handler"))) void TIM3_IRQHandler(void);                    /* TIM3                         */
__attribute__((weak, alias("Default_Handler"))) void TIM4_IRQHandler(void);                    /* TIM4                         */
__attribute__((weak, alias("Default_Handler"))) void I2C1_EV_IRQHandler(void);                 /* I2C1 Event                   */
__attribute__((weak, alias("Default_Handler"))) void I2C1_ER_IRQHandler(void);                 /* I2C1 Error                   */
__attribute__((weak, alias("Default_Handler"))) void I2C2_EV_IRQHandler(void);                 /* I2C2 Event                   */
__attribute__((weak, alias("Default_Handler"))) void I2C2_ER_IRQHandler(void);                 /* I2C2 Error                   */
__attribute__((weak, alias("Default_Handler"))) void SPI1_IRQHandler(void);                    /* SPI1                         */
__attribute__((weak, alias("Default_Handler"))) void SPI2_IRQHandler(void);                    /* SPI2                         */
__attribute__((weak, alias("Default_Handler"))) void USART1_IRQHandler(void);                  /* USART1                       */
__attribute__((weak, alias("Default_Handler"))) void USART2_IRQHandler(void);                  /* USART2                       */
__attribute__((weak, alias("Default_Handler"))) void EXTI15_10_IRQHandler(void);               /* External Line[15:10]s        */
__attribute__((weak, alias("Default_Handler"))) void RTC_Alarm_IRQHandler(void);               /* RTC Alarm (A and B) through EXTI Line */
__attribute__((weak, alias("Default_Handler"))) void OTG_FS_WKUP_IRQHandler(void);             /* USB OTG FS Wakeup through EXTI line */
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream7_IRQHandler(void);            /* DMA1 Stream7                 */
__attribute__((weak, alias("Default_Handler"))) void SDIO_IRQHandler(void);                    /* SDIO                         */
__attribute__((weak, alias("Default_Handler"))) void TIM5_IRQHandler(void);                    /* TIM5                         */
__attribute__((weak, alias("Default_Handler"))) void SPI3_IRQHandler(void);                    /* SPI3                         */
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream0_IRQHandler(void);            /* DMA2 Stream 0                */
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream1_IRQHandler(void);            /* DMA2 Stream 1                */
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream2_IRQHandler(void);            /* DMA2 Stream 2                */
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream3_IRQHandler(void);            /* DMA2 Stream 3                */
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream4_IRQHandler(void);            /* DMA2 Stream 4                */
__attribute__((weak, alias("Default_Handler"))) void OTG_FS_IRQHandler(void);                  /* USB OTG FS                   */
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream5_IRQHandler(void);            /* DMA2 Stream 5                */
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream6_IRQHandler(void);            /* DMA2 Stream 6                */
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream7_IRQHandler(void);            /* DMA2 Stream 7                */
__attribute__((weak, alias("Default_Handler"))) void USART6_IRQHandler(void);                  /* USART6                       */
__attribute__((weak, alias("Default_Handler"))) void I2C3_EV_IRQHandler(void);                 /* I2C3 event                   */
__attribute__((weak, alias("Default_Handler"))) void I2C3_ER_IRQHandler(void);                 /* I2C3 error                   */
__attribute__((weak, alias("Default_Handler"))) void FPU_IRQHandler(void);                     /* FPU                          */
__attribute__((weak, alias("Default_Handler"))) void SPI4_IRQHandler(void);                    /* SPI4                         */

// Default handler
void Default_Handler(void) {
    while (1);
}

// Vector table
__attribute__((section(".isr_vector")))
void (* const vector_table[])(void) =
{
    (void (*)(void))(&_estack), // Initial stack pointer. Cast to function pointer type to be consistent with vector table.
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,

    /* External Interrupts */
    WWDG_IRQHandler,                    /* Window WatchDog              */
    PVD_IRQHandler,                     /* PVD through EXTI Line detection */
    TAMP_STAMP_IRQHandler,              /* Tamper and TimeStamps through the EXTI line */
    RTC_WKUP_IRQHandler,                /* RTC Wakeup through the EXTI line */
    FLASH_IRQHandler,                   /* FLASH                        */
    RCC_IRQHandler,                     /* RCC                          */
    EXTI0_IRQHandler,                   /* EXTI Line0                   */
    EXTI1_IRQHandler,                   /* EXTI Line1                   */
    EXTI2_IRQHandler,                   /* EXTI Line2                   */
    EXTI3_IRQHandler,                   /* EXTI Line3                   */
    EXTI4_IRQHandler,                   /* EXTI Line4                   */
    DMA1_Stream0_IRQHandler,            /* DMA1 Stream 0                */
    DMA1_Stream1_IRQHandler,            /* DMA1 Stream 1                */
    DMA1_Stream2_IRQHandler,            /* DMA1 Stream 2                */
    DMA1_Stream3_IRQHandler,            /* DMA1 Stream 3                */
    DMA1_Stream4_IRQHandler,            /* DMA1 Stream 4                */
    DMA1_Stream5_IRQHandler,            /* DMA1 Stream 5                */
    DMA1_Stream6_IRQHandler,            /* DMA1 Stream 6                */
    ADC_IRQHandler,                     /* ADC1, ADC2 and ADC3s         */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    EXTI9_5_IRQHandler,                 /* External Line[9:5]s          */
    TIM1_BRK_TIM9_IRQHandler,           /* TIM1 Break and TIM9          */
    TIM1_UP_TIM10_IRQHandler,           /* TIM1 Update and TIM10        */
    TIM1_TRG_COM_TIM11_IRQHandler,      /* TIM1 Trigger and Commutation and TIM11 */
    TIM1_CC_IRQHandler,                 /* TIM1 Capture Compare         */
    TIM2_IRQHandler,                    /* TIM2                         */
    TIM3_IRQHandler,                    /* TIM3                         */
    TIM4_IRQHandler,                    /* TIM4                         */
    I2C1_EV_IRQHandler,                 /* I2C1 Event                   */
    I2C1_ER_IRQHandler,                 /* I2C1 Error                   */
    I2C2_EV_IRQHandler,                 /* I2C2 Event                   */
    I2C2_ER_IRQHandler,                 /* I2C2 Error                   */
    SPI1_IRQHandler,                    /* SPI1                         */
    SPI2_IRQHandler,                    /* SPI2                         */
    USART1_IRQHandler,                  /* USART1                       */
    USART2_IRQHandler,                  /* USART2                       */
    0,                                  /* Reserved                     */
    EXTI15_10_IRQHandler,               /* External Line[15:10]s        */
    RTC_Alarm_IRQHandler,               /* RTC Alarm (A and B) through EXTI Line */
    OTG_FS_WKUP_IRQHandler,             /* USB OTG FS Wakeup through EXTI line */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    DMA1_Stream7_IRQHandler,            /* DMA1 Stream7                 */
    0,                                  /* Reserved                     */
    SDIO_IRQHandler,                    /* SDIO                         */
    TIM5_IRQHandler,                    /* TIM5                         */
    SPI3_IRQHandler,                    /* SPI3                         */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    DMA2_Stream0_IRQHandler,            /* DMA2 Stream 0                */
    DMA2_Stream1_IRQHandler,            /* DMA2 Stream 1                */
    DMA2_Stream2_IRQHandler,            /* DMA2 Stream 2                */
    DMA2_Stream3_IRQHandler,            /* DMA2 Stream 3                */
    DMA2_Stream4_IRQHandler,            /* DMA2 Stream 4                */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    OTG_FS_IRQHandler,                  /* USB OTG FS                   */
    DMA2_Stream5_IRQHandler,            /* DMA2 Stream 5                */
    DMA2_Stream6_IRQHandler,            /* DMA2 Stream 6                */
    DMA2_Stream7_IRQHandler,            /* DMA2 Stream 7                */
    USART6_IRQHandler,                  /* USART6                       */
    I2C3_EV_IRQHandler,                 /* I2C3 event                   */
    I2C3_ER_IRQHandler,                 /* I2C3 error                   */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    FPU_IRQHandler,                     /* FPU                          */
    0,                                  /* Reserved                     */
    0,                                  /* Reserved                     */
    SPI4_IRQHandler                     /* SPI4                         */
};

// Reset handler
void Reset_Handler(void)
{
    // Copy .data section from Flash to RAM
    uint32_t *src = &_etext;
    uint32_t *dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    // Zero-initialize .bss section
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

    // Optional: Heap and stack are just defined via symbols now;
    // you can add custom memory alloc or use them directly

    // Call main()
    main();

    // If main exits, loop forever
    while (1);
}
