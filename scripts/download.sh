cd "$(dirname "${0}")/.."

echo "Compiling..."
arm-none-eabi-as -g -mcpu=cortex-m4 -mthumb src/main.s -o build/main.o

echo "Linking..."
arm-none-eabi-ld -g -Ttext=0x08000000 build/main.o -o build/main.elf
# arm-none-eabi-ld -g -Ttext=0 build/main.o -o build/main.elf

echo "Downloading..."
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program build/main.elf reset exit"

echo "Finished"
