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
void printArr(uint32_t* maskArr, size_t nitems){
    for (int i = 0; i < nitems; i++)
    {
        printBits(*(maskArr+i));
    }
    
}

int clearBit(uint32_t* maskArr, size_t nitems, size_t bit);
int setBit(uint32_t* maskArr, size_t nitems, size_t bit);
int checkBit(uint32_t* maskArr, size_t len, size_t bit);

int main() {
    uint32_t arr[] = {10, 15, 17, 18};
    printBits(arr);
    if(checkBit(&arr, 4, 0) == 1){
        printf("Searched bit is one\n");
    }
    clearBit(&arr, 4, 0);
    printArr(&arr, 4);
    setBit(&arr, 4, 10);
    
    

    return 0;
}

int clearBit(uint32_t* maskArr, size_t nitems, size_t bit){
    for (int i = 0; i < nitems; i++)
    {
        *(maskArr+nitems) &= ~(1<<bit);
    }
    
    return 0;
}
int setBit(uint32_t* maskArr, size_t nitems, size_t bit){
    for (int i = 0; i < nitems; i++)
    {
        *maskArr |= (1<<bit);
    }
    return 0;
}
int checkBit(uint32_t* maskArr, size_t len, size_t bit){
    for (int i = 0; i < len; i++)
    {
        int a1 = (*(maskArr+i) >> bit) & 1;
        if (a1 == 1)
    {
        printf("maskArr[%d], bit number %d = 1", i, bit);
    }
    else{
        printf("maskArr[%d], bit number %d = 0", i, bit);
    }
    }
    return 0;
}
