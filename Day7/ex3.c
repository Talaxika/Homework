#include <stdio.h>

int sum(int* arr, int);

void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int));

int main() {

    int arr[] = {1, 2, 3};
    int n = 3;
    arrayEvaluate(arr, n, sum);


    return 0;
}

int sum(int* arr, int n){
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum+= *(arr+i);
    }
    return sum;
}

void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int)){
    printf("%d", sum(arr, n));
}
