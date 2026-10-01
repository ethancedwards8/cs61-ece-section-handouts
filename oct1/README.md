# October 1 Section

## Unions!

Let's make our own register! https://cs61.seas.harvard.edu/site/2026/Asm/#Registers

Remember: all elements in a union share the same address in memory

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
- `%rax`
- `leave; retq` - or `movq %rbp, %rsp; popq %rbp; retq`

```asm
0000000000401490 <_Z6functiPc>:
  401490:	55                   	push   %rbp
  401491:	31 d2                	xor    %edx,%edx
  401493:	48 89 e5             	mov    %rsp,%rbp
  401496:	48 83 ec 10          	sub    $0x10,%rsp
  40149a:	48 8d 75 f8          	lea    -0x8(%rbp),%rsi
  40149e:	e8 fd fc ff ff       	call   4011a0 <strtol@plt>
  4014a3:	48 3d e2 a1 00 00    	cmp    $0xaaff,%rax
  4014a9:	75 05                	jne    4014b0 <_Z6functiPc+0x20>
  4014ab:	c9                   	leave
  4014ac:	c3                   	ret
  4014ad:	0f 1f 00             	nopl   (%rax)
  4014b0:	e8 8b 09 00 00       	call   401e40 <_Z12functiontwoov>
  4014b5:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  4014bc:	00 00 00 00 
```
