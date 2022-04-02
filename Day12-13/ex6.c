#include <stdio.h>
#define COUNT 10

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* arr, unsigned int len){
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (arr[j] < arr[j+1])
            {
                swap(arr+j, arr+j+1);
            }
        }
    }
}
int printArr(int* arr, int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

int main() {

    int arr[COUNT] = {1, 5, 8, 7, 4, 3, 9, 2, 6, 10};
    bubbleSort(arr, COUNT);
    printArr(arr, COUNT);
}
