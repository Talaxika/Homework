#include <stdio.h>

double mysqrt(double number)
{
    double error = 0.00001; //precision
    double s = number;

    while ((s - number / s) > error)  
    {
        s = (s + number / s) / 2;
    }
    return s;
}

double mysin(double x, int n)
{
   double t = x;
   double sine = t;
   for ( int a=1; a<n; ++a)
   {
      double mult = -x*x/((2*a+1)*(2*a));
      t *= mult;
      sine += t;
   }
   return sine;
}


int main() {
    double test = 9;
    printf("%lf\n", mysqrt(test));

    printf("%lf", mysin(3.5, 20));

    return 0;

}
