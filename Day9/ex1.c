#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


void swap(void* pt1, void* pt2, size_t size){
    uint8_t arr[size];
    memcpy(arr, pt1, size);
    memcpy(pt1, pt2, size);
    memcpy(pt2, arr, size);
}

int partition (int* arr, int low, int high)
{   
    size_t size = sizeof(int);
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {
        
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j], size);
        }
    }
    swap(&arr[i + 1], &arr[high], size);
    return (i + 1);
}

void quickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", *(arr+i));
    }
        
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
