#!/bin/bash
set -euo pipefail

cd "$(dirname "${0}")/.."

# === Configuration ===
OPENOCD_CFG="-f interface/stlink.cfg -f target/stm32f4x.cfg"  # Modify as needed
GDB_EXEC="arm-none-eabi-gdb"                            # Adjust if needed
ELF_FILE="build/main.elf"                             # Your ELF file

# === Start OpenOCD in background ===
openocd $OPENOCD_CFG > tools/openocd.log 2>&1 &
OPENOCD_PID=$!

echo "Started OpenOCD with PID $OPENOCD_PID"
sleep 1  # Give OpenOCD time to initialize

# === Cleanup function ===
cleanup() {
    echo "Cleaning up..."
    if kill -0 "$OPENOCD_PID" 2>/dev/null; then
        kill "$OPENOCD_PID"
        wait "$OPENOCD_PID"
        echo "OpenOCD terminated"
    fi
}
trap cleanup EXIT INT TERM

# === Start GDB and connect ===
$GDB_EXEC -ex "source ./tools/.gdbinit" -ex "target remote localhost:3333" "$ELF_FILE"
