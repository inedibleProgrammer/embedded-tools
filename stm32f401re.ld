/* Minimal STM32F401RE Linker Script */

ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
  RAM   (xrw) : ORIGIN = 0x20000000, LENGTH = 96K
}

_estack = ORIGIN(RAM) + LENGTH(RAM); /* End of RAM = start of stack */

_stack_size = 0x1000; /* 4 KB stack */
_heap_size  = 0x0800; /* 2 KB heap */

SECTIONS
{
  .isr_vector :
  {
    KEEP(*(.isr_vector))
  } > FLASH

  .text :
  {
    *(.text*)
    *(.rodata*)
    _etext = .;
  } > FLASH

  .data : AT(ADDR(.text) + SIZEOF(.text))
  {
    _sdata = .;
    *(.data*)
    _edata = .;
  } > RAM

  .bss :
  {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } > RAM

  .heap (NOLOAD) :
  {
    _heap_start = .;
    . = . + _heap_size;
    _heap_end = .;
  } > RAM

  .stack (NOLOAD) :
  {
    . = ALIGN(8);
    _stack_start = .;
    . = . + _stack_size;
    _stack_end = .;
  } > RAM

  _end = .;
}
