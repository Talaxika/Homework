#include <stdio.h>
#include <stdint.h>
unsigned char CheckBit(uint16_t);

int main() {
    printf("%d\n", CheckBit(0x0400));
    printf("%d\n", CheckBit(0x0600));
    printf("%d\n", CheckBit(0x0000));

    return 0;
}

unsigned char CheckBit(uint16_t n){
    int cnt = 0;
    while (n)
    {
        cnt += n&1;
        n>>=1;
    }
    if (cnt == 1)
    {
        return 1;
    }
    return 0;
}
