#include <stdio.h>
#include <stdlib.h>


void Add( const char* p1, const char* p2, char* result);


int main() {
    char result[1000];
    char* c = "12";
    char* b = "2";
    Add(c, b, result);
    printf("%s", result);


    return 0;
}

void Add(const char* p1, const char* p2, char* result){
    int num1 = atoi(p1);
    int num2 = atoi(p2);
    int resultn = num1+num2;
    sprintf(result, "%d", resultn);

}
