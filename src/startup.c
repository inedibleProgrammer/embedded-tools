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
void Default_Handler(void) { while (1); }

// Vector table
__attribute__((section(".isr_vector")))
void (* const vector_table[])(void) = {
    (void (*)(void))(&_estack), // Initial stack pointer
    Reset_Handler,              // Reset handler
    // Other IRQ handlers can go here...
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
