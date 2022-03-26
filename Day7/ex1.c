#include <stdio.h>
#include <stdlib.h>



int secondMax(const int* arr, size_t n, int* secondMax);

int main() {
    int sm;
    int arr[] = {12, 34, 5, 70, 46};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = secondMax (arr,n, &sm);
    if (result==1)
    {
        printf("Empty array.");
    }
    else if (result==2)
    {
        printf("Array has only one element.");
    }
    else if (result==3)
    {
        printf("Array has the same elements.");
    }
    else{
        printf("Second biggest element = %d\n", sm);
    }
    
    
    

    return 0;
}

int secondMax(const int* arr, size_t n, int* secondMax){

    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 2;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i+1])
        {
            return 3;
        }
        
    }
    
    
    int largest = 0, secondLargest = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[largest])
            largest = i;
    }
 
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[largest]) {
            if (secondLargest == -1)
                secondLargest = i;
            else if (arr[i] > arr[secondLargest])
                secondLargest = i;
        }
    }
    *secondMax = arr[secondLargest];
    return 0;   

}
