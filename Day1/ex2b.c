#include <stdio.h>
#include <math.h>
int main() {
    double radius, height, lenght, volume, area1, area2, area;
    printf("Please enter radius: ");
    scanf("%lf", &radius);
    printf("Please enter height: ");
    scanf("%lf", &height);
    printf("Please enter lenght: ");
    scanf("%lf", &lenght);
    area2 = (radius-height)*sqrt(2*radius*height-height*height);
    area1 = acos((radius-height)/radius)*radius*radius;
    area = area1-area2;
    volume = area*lenght;

    printf("Volume is: %.2lf", volume);


    return 0;
}