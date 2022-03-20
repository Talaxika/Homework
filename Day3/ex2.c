#include <stdio.h>
#include <math.h>

int compare1(double a, double b){
    return a == b;
}
int compare2(double a, double b){
    return fabs(a-b) < __FLT_EPSILON__;
}
int compare3(double a, double b, double eps){
    return fabs(a-b) < eps;
}


int main(void){
    double a = 1.1;
    double b = 0;
    double eps = 0.003;
    for (int i = 0; i < 11; i++){
        b += 0.1;
    }
    printf("a = %.30lf, b = %.30lf\n", a, b);

    if (compare1(a, b) != 0)
    {
        printf("Not equal - compare1\n");
    }
    else if (compare1(a, b) ==0)
    {
        printf("Equal - compare1\n");
    }
    if (compare2(a, b) !=0)
    {
        printf("Not equal - compare2\n");
    }
    else if (compare2(a, b) ==0)
    {
        printf("Equal - compare2\n");
    }
    if (compare3(a, b, eps) != 0)
    {
        printf("Not equal - compare3\n");
    }
    else if (compare3(a, b, eps) ==0)
    {
        printf("Equal - compare2\n");
    }
    
    
    
    return 0;

}


