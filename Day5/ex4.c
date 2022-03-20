#include <stdio.h>
#include <math.h>

// RUN COMMAND   gcc ex4.c -o ex4 -lm; ./ex4 2> errFile
// RUN COMMAND WITH INPUT FROM FILE  gcc ex4.c -o ex4 -lm; ./ex4 <numbers 2> errFile

int quadEq(double a, double b, double c, double* x1, double* x2);


int main(void) {
    double a, b, c, x1, x2;
    
    printf("Enter the three arguments: ");
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
    {
        if (quadEq(a, b, c, &x1, &x2) == -1)
        {
            if(a == 0){
            fprintf(stderr, "'a' cannot be zero.\n");
        }
            else if (b*b-4*a*c < 0)
        {
            fprintf(stderr, "No Real Roots\n");
        }
        return -1;        
        }
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
        
    }
    

    return 0;
}


int quadEq(double a, double b, double c, double* x1, double* x2){

    if(a == 0 || b*b-4*a*c < 0){
        return -1;
    }
    
    *x1 = (-b+sqrt(b*b-4*a*c))/2*a;
    *x2 = (-b-sqrt(b*b-4*a*c))/2*a;

    return 0;
}