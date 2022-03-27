#include <stdio.h>
#include <stdint.h>

void printBits(unsigned n)
{
    unsigned i;
    for (i = 1 << 15; i > 0; i = i / 2){
        (n & i) ? printf("1") : printf("0");
    }
    putchar('\n');
}

void swapBytes(uint16_t* word); 

int main() {
    uint16_t num = 9465;
    printBits(num);
    swapBytes(&num);
    printBits(num);
    

    return 0;
}

void swapBytes(uint16_t* word){
    int a1 = (*word>>0) & 1;
    printf("Rightmost bit - %d\n", a1);
    int b1 = (*word>>15) & 1;
    printf("Leftmost bit - %d\n", b1);
    int c = (a1 ^ b1);

	  c = (c << 0) | (c << 15);
    
    *word  = *word^c;
}
