#include <stdio.h>
#include <stdarg.h>


//Zadachata e nepulna, nqma size


unsigned onesCount(unsigned count,...);


int main(void){
    int count;
    /*int size;
    */

    int result = onesCount(2, 4, 9);
    printf("%d\n", result);
    
    return 0;
}

unsigned onesCount(unsigned count,...){
    unsigned int counter = 0;
    va_list args;
    va_start (args, count);
    
    

    for (int i = 0; i < count; i++)
    {
        int number = va_arg(args, int);
        while (number) {
        counter += number & 1;
        number >>= 1;
    }
    }
    va_end(args);
    return counter;
    
}
