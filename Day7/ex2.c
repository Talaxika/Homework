#include <stdio.h>

unsigned sumArrayDigits(const int* arr, size_t n);

int main() {

    int arr[] = {12, 34, 5, 70 };
    printf("%d", sumArrayDigits(arr, 4));



    return 0;
}

unsigned sumArrayDigits(const int* arr, size_t n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int N = arr[i];
        while (N)
        {
            int currDigit = N%10;
            sum += currDigit;
            N /=10;
        }
    }
    return sum;
}