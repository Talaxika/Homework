#include <stdio.h>

int main () {
    int a, b, c, result;
    scanf("%d %d %d", &a, &b, &c);
    result = a^b^c;
    printf("%d\n", result);

    //run command --- gcc ex2.c -o ex2; ./ex2 < numbers.txt

    return 0;
}