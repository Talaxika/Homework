#include <stdio.h>

int main () {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a>=b && a>=c){
        printf("%d\n", a);
    }
    else if(b>=a && b>=c){
        printf("%d\n", b);
    }
    else {
        printf("%d\n", c);
    }

    //run command --- gcc ex1.c -o ex1; ./ex1 < numbers.txt

    return 0;
}
