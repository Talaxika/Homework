#include <stdio.h>
int getlen(char* ptr);
void reverse(char* ptr);

int main() {
    char str[100] = "This is a test\0";
    reverse(str);
    printf("%s", str);
    return 0;
}

void reverse(char* ptr){
    int i, len, temp;
    len = getlen(ptr);
    for (i = 0; i < len/2; i++)
    {
        temp = ptr[i];
        ptr[i] = ptr[len-i-1];
        ptr[len-i-1] = temp;
    }
    *(ptr+len) = '\0'; 
}
int getlen(char* ptr){
    int i;
    for (i = 0; *(ptr+i) != '\0'; i++);
    return i;
}
