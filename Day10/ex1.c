#include <stdio.h>
#include <stdint.h>

void printBits(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}

int main() {
    uint32_t num;
    scanf("%d", &num);
    bin(num);
    
    
    return 0;
}
