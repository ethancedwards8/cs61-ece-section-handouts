# October 1 Section

## Unions!

Let's make our own register! https://cs61.seas.harvard.edu/site/2026/Asm/#Registers

```c
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
```

Another usecase is:

```c
union Header {
    uint8_t bytes[4];

    struct {
        uint8_t type;
        uint8_t flags;
        uint8_t length_hi;
        uint8_t length_lo;
    };
};

union Header packet;

//         +----------+----------+----------+----------+
// Bytes   |   0x02   |   0x01   |   0x00   |   0x05   |
//         +----------+----------+----------+----------+
// Fields  |   type   |  flags   | length_hi| length_lo|
//         +----------+----------+----------+----------+
// Raw     | bytes[0] | bytes[1] | bytes[2] | bytes[3] |
//         +----------+----------+----------+----------+

packet.bytes[0] == packet.type;
```

## Strategies for reading assembly

The most important things are understanding:
- `%rip`
- `%rbp`
- `%rsp`
- `pop`/`push`
- `lea`
