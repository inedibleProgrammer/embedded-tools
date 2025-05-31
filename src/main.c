#include <stdint.h>

int main(void)
{
    // Test that we're alive
    volatile int counter = 0;
    while (1) {
        counter++;
    }
}
