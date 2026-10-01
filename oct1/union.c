#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

union Register {
    uint16_t reg; // %ax
    struct {
        uint8_t high; // High byte %ah
        uint8_t low; // Low bytes %al
    };
};

int main()
{
    union Register cs61;

    cs61.reg = 0xafaf; // full 16 bytes - decimal 44975

    printf("Reg: %d\n", cs61.reg);

    // OR

    cs61.high = 0xcb; // 8 bytes - decimal 203
    cs61.low = 0x61; // 8 bytes - decimal 97

    printf("High: %d\nlow: %d\n", cs61.high, cs61.low);
}
