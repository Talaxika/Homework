#include <stdio.h>

//NEPULNA

int sum(int n){
    int sum = 0;
    while (n)
    {
        int currdigit = n%10;
        sum+= currdigit;
        n/=10;
    }
    return sum;    
}

int recursive(int* arr, int size, int pos){
    printf("curr pos: %d\n", pos);
    if (sum(*(arr+pos)) % 2 == 0)
    {
        pos+=3;
    }
    else{
        pos-=2;
    }
    if (pos > size || pos < 0)
    {
        return -1;
    }
    
    return recursive(arr, size, pos);
    
}

int main() {
    int arr[] = {5, 23, 77, 123, 681, 9, 772, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pos = 4;
    recursive (arr, n, pos);


    return 0;
}
