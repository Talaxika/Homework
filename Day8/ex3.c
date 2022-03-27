#include <stdio.h>

int binarySearch(int*, size_t, int);

int main(){
    int arr[] = {1, 2, 3, 4, 6 };
    size_t n = sizeof(arr) / sizeof(arr[0]);
    int key = 4;
    int result = binarySearch(arr, n-1, key);
    if (result == -1)
    {
        printf("Element is not in the array");
        return -1;
    }
    else{
        printf("%d is present at posiion %d", key, result+1);
    }
    

    return 0;
}

int binarySearch(int* arr, size_t n, int key)
{
    int l = 0;
    int r = n-1;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        
        if (*(arr+m) == key)
            return m;
 
        
        if (*(arr+m) < key)
            l = m + 1;
 
        
        else
            r = m - 1;
    }
 
    
    return -1;
}
