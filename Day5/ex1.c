#include <stdio.h>
#include <math.h>

// RUN COMMAND   gcc ex1.c -o ex1; ./ex1 2>errFile
// RUN COMMAND WITH INPUT FROM FILE  gcc ex1.c -o ex1; ./ex1 < numbers 2>errFile

int main (void) {
    double a, b;
    char c;
    printf("Enter the two numbers and operation: \n");
    printf("Possible operations- '+', '-', '/', '*'\n");
    while (scanf("%lf %c %lf", &a, &c, &b) != EOF){
        if (c == '+')
        {
            printf("%.2lf + %.2lf = %.2lf",a, b, a+b);
        }
        else if (c == '-')
        {
            printf("%.2lf - %.2lf = %.2lf",a, b, a-b);
        }
        else if (c == '*')
        {
            printf("%.2lf * %.2lf = %.2lf",a, b, a*b);
        }
        else if (c == '/')
        {
            printf("%.2lf / %.2lf = %.2lf",a, b, a/b);
        }
        else{
            fprintf(stderr, "Invalid operation\n");
        }
        printf("\n");
        

    }



    return 0;
}
