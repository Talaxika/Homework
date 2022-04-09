#include <stdio.h>

unsigned int binary(unsigned int* arr, unsigned int size, unsigned int key);

int main() {
    int arr[] = {1, 3, 6, 9, 12};
    int key = 3;
    int result = binary(arr, 5, key);
    if (result == 0xFFFF)
    {
        printf("Key not found");
    }
    else
        printf("Index is: %d", result);

    return 0;
}

unsigned int binary(unsigned int* arr, unsigned int size, unsigned int key){
    for (int i = 0; i < size; i++)
    {
        if (*(arr+i) == key)
        {
            return i;
        }
        
    }
    return 0xFFFF;
    



}
