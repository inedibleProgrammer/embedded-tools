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


# Useful

```
User LD2: the green LED is a user LED connected to ARDUINO ® signal D13 corresponding
to STM32 I/O PA5 (pin 21) 
```

3322 2222 2222 1111 1111 1100 0000 0000
1098 7654 3210 9876 5432 1098 7654 3210

AHB1
0x40023800 - 0x40023BFF RCC
0x40020000 - 0x400203FF GPIOA

