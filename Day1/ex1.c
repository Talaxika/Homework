#include <stdio.h>
#include <math.h>
int main() {
    double mass, height, bodymass;
    printf("Enter mass: ");
    scanf("%lf", &mass);
    printf("Enter height: ");
    scanf("%lf", &height);
    bodymass = 1.3*(mass/pow(height, 2.5));

    printf("Bodymass is: %.2lf\n", bodymass);


    return 0;
}
