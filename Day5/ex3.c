#include <stdio.h>
#include <math.h>

// RUN COMMAND   gcc ex3.c -o ex3; ./ex3 2> errFile
// RUN COMMAND WITH INPUT FROM FILE  gcc ex3.c -o ex3; ./ex3 <numbers 2> errFile

int rectangle(double a, double b, double* P, double* S){
    if (a<=0 || b<=0)
    {   
        return -1;
    }
    
    *P = 2*(a+b);
    *S = a*b;
    return 0;
}

int main(void) {
    double a, b, per, area;
    printf("Enter sides: ");
    while (scanf("%lf %lf", &a, &b) != EOF)
    {
        if (rectangle(a, b, &per, &area) == -1)
        {
            fprintf(stderr, "Invalid sides.");
        }
        printf("S = %.2lf, P = %.2lf", area, per);

    }
    

    return 0;
}