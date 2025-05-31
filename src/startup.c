#include <stdint.h>

// Symbols from the linker script
extern uint32_t _sdata, _edata, _etext;
extern uint32_t _sbss, _ebss;
extern uint32_t _estack;

extern uint32_t _heap_start, _heap_end;
extern uint32_t _stack_start, _stack_end;

int main(void);

// Minimal weak handler declarations
void Reset_Handler(void);
void NMI_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)           __attribute__((weak, alias("Default_Handler")));

// STM32F401RET6 specific interrupt handlers
void WWDG_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));

// Default handler
void Default_Handler(void) {
    while (1);
}

// Vector table
__attribute__((section(".isr_vector")))
void (* const vector_table[])(void) =
{
    (void (*)(void))(&_estack), // Initial stack pointer. Cast to function pointer type to be consistent with vector table.
    Reset_Handler,                  // Reset Handler
    NMI_Handler,                    // NMI Handler
    HardFault_Handler,              // Hard Fault Handler
    MemManage_Handler,              // MPU Fault Handler
    BusFault_Handler,               // Bus Fault Handler
    UsageFault_Handler,             // Usage Fault Handler
    0, 0, 0, 0,                     // Reserved
    SVC_Handler,                    // SVCall Handler
    DebugMon_Handler,               // Debug Monitor Handler
    0,                              // Reserved
    PendSV_Handler,                 // PendSV Handler
    SysTick_Handler,                // SysTick Handler

    // External Interrupts (IRQs)
    WWDG_IRQHandler,                // Window Watchdog
    PVD_IRQHandler,                 // PVD through EXTI Line detect
    TAMP_STAMP_IRQHandler,          // Tamper and TimeStamp
    RTC_WKUP_IRQHandler,            // RTC Wakeup
    FLASH_IRQHandler,               // FLASH
    RCC_IRQHandler,                 // RCC
    EXTI0_IRQHandler,               // EXTI Line0
    EXTI1_IRQHandler,               // EXTI Line1
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
