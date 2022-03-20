#include <stdio.h>
#include <math.h>

// RUN COMMAND   gcc ex2.c -o ex2 -lm ; ./ex2 2>errFile
// RUN COMMAND WITH INPU FROM FILE gcc ex2.c -o ex2 -lm ; ./ex2 < numbers 2>errFile

int triangle(double a, double b, double c, double* S, double *P);


int main (void) {

    double a = 0, b = 0, c = 0, P, S;
    printf("Enter the three sides: ");
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
    {
        
        if(triangle(a, b, c, &P, &S) == -1)
        {
            
            fprintf(stderr, "Invalid sides.\n");
            
        }
        else
        {
            
            printf("P = %.2lf, S = %.2lf\n", P, S);
            
        }
        
    }
    
    printf("\n");
    return 0;


    return 0;
}

int triangle(double a, double b, double c, double* S, double* P){
    if (a<=0 || b<=0 || c<=0 || a+b<=c || a+c<=b || b+c<=a)
    {
        return -1;
    }
    *P = a+b+c;
    double p = (a+b+c)/2;
    *S = sqrt(p*(p-a)*(p-b)*(p-c));
    return 0;
}