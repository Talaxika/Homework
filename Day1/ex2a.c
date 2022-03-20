#include <stdio.h>
#include <math.h>
int main() {
    double radius, height, volume;
    printf("Please enter radius: ");
    scanf("%lf", &radius);
    printf("Please enter height: ");
    scanf("%lf", &height);
    volume = 3.14*radius*radius*height;

    printf("Volume is: %.2lf", volume);


    return 0;
}