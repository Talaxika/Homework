#include <stdio.h>
#include <stdint.h>
void printBits(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2){
        (n & i) ? printf("1") : printf("0");
    }
    putchar('\n');
}

int clearBit(uint32_t* maskArr, size_t nitems, size_t bit);
int setBit(uint32_t* maskArr, size_t nitems, size_t bit);
int checkBit(uint32_t* maskArr, size_t len, size_t bit);

int main() {
    uint32_t num = 17;
    printBits(num);
    if(checkBit(&num, 32, 0) == 1){
        printf("Searched bit is one\n");
    }
    clearBit(&num, 32, 0);
    printBits(num);
    setBit(&num, 32, 10);
    printBits(num);
    

    return 0;
}

int clearBit(uint32_t* maskArr, size_t nitems, size_t bit){
    return *maskArr &= ~(1<<bit);
}
int setBit(uint32_t* maskArr, size_t nitems, size_t bit){
    return *maskArr |= (1<<bit);
}
int checkBit(uint32_t* maskArr, size_t len, size_t bit){
    int a1 = (*maskArr >> bit) & 1;
    if (a1 == 1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
