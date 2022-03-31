#include <stdio.h>
#define MAX1(x,y) ((x)>(y))?x:y
#define MIN1(x,y) ((x)<(y))?x:y
#define MAX(x,y,z) MAX1(MAX1((x),(y)),(z))
#define MIN(x,y,z) MIN1(MIN1((x),(y)),(z))
#define SETBIT(mask,bit) mask|=(1<<((bit)-1))
#define CLEARBIT(mask,bit) mask&=~(1<<((bit)-1))
#define INVERSEBIT(mask,bit) mask^=(1<<((bit)-1))
#define CHECKBIT(mask,bit) !(mask>>bit-1)
#define SWAP(a,b) a^=b^=a^=b


int main() {


    printf("%d\n",MAX(15, 10, 5));
    printf("%d\n",MIN(15, 10, 5));
    int a = 10;
    int b = 5;
    SWAP(a,b);
    printf("%d %d", a, b);


    return 0;   
}
