#include <stdlib.h>
#include <stdio.h>

union Register {
    uint16_t reg; // %ax
    struct {
        uint8_t l; // Low bytes %al
        uint8_t h; // High byte %ah
    };
};

int main()
{
    union Register cs61;

    cs61.reg = 0xafaf; // full 16 bytes - decimal 44975

    printf("Reg: %d\n", cs61.reg);

    // OR

    cs61.h = 0xcb; // 8 bytes - decimal 203
    cs61.l = 0x61; // 8 bytes - decimal 97

    printf("High: %d\nlow: %d\n", cs61.h, cs61.l);
}
