# Embedded Tools


# Microcontroller for Testing

STM32F401
Nucleo-64

STM32F401RET6 64 Pins
NUCLEO-F401RE


# Commands used

- arm-none-eabi-as -mcpu=cortex-m4 -mthumb main.s -o main.o
- arm-none-eabi-ld -Ttext=0x08000000 main.o -o main.elf
- openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program main.elf reset exit"
- openocd -f interface/stlink.cfg -f target/stm32f4x.cfg
- arm-none-eabi-gdb main.elf
 - target extended-remote localhost:3333
 - monitor reset halt
 - load
 - break Reset_Handler


