cd "$(dirname "${0}")/.."

arm-none-eabi-gcc -g -mcpu=cortex-m4 -mthumb -nostdlib -Tstm32f401re.ld src/startup.c src/main.c -o build/main.elf
