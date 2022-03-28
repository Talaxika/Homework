#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define COUNT 10

void printArr(int* arr, int n);
int compare(const void* a, const void* b);
void swapg(void *a, void* b, size_t size);
void bubbleSort(void* arr, size_t n, size_t size, int (*comp)(const void*,const void*));


void (*getSorting(char* fname))(void*,size_t,size_t,int(*)(const void*,const void*));

int main() {
    
    int arr[COUNT] = {10, 15, 4, 16, 8, 30, 25, 1, 55, 43};
    getSorting("bubbleSort")(arr, COUNT, sizeof(int), compare);
    printArr(arr, COUNT);
    getSorting("qsort")(arr, COUNT, sizeof(int), compare);
    printArr(arr, COUNT);


    return 0;
}

void (*getSorting(char* fname))(void*,size_t,size_t,int(*)(const void*,const void*)){
    if (fname == "qsort")
    {
        return qsort;
    }
    else if (fname == "bubbleSort")
    {
        return bubbleSort;
    }
    else{
        return NULL;
    }
    
    
}

void printArr(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

void swapg(void *a, void* b, size_t size){
    uint8_t temp[size];
    memmove(temp, a, size);
    memmove(a, b, size);
    memmove(b, temp, size);
}

void bubbleSort(void* arr, size_t n, size_t size, int (*comp)(const void*,const void*)){
   for (int i = 0; i < n-1; i++){
       for (int j = 0; j < (n-i-1) * size; j += size){
           if (comp(arr + j, arr + j + size) < 0){
              swapg(arr + j, arr + j + size, size);
              
           }
       }
   }
}
