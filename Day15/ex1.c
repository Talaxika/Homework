#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

//run command -  gcc ex1.c -o ex1; ./ex1 file

#define COUNT 10

typedef struct{
    char title[150];
    char author[100];
    int pages;
    double price;
}Book;


char *rand_string(char *str, size_t size);
int randfromint(int min, int max);
double randfromdouble(double min, double max);


int main(int argc, char* argv[]){
    if (argc != 2)
    {
        printf("Invalid arguments count.\n");
        exit(-1);
    }
    
    
    srand(time(NULL));
    Book books[COUNT];
    
    for (int i = 0; i < COUNT; i++)
    {
        strcpy(books[i].title, rand_string(books[i].title, randfromint(10, 20)));
        strcpy(books[i].author, rand_string(books[i].author, randfromint(10, 20)));
        books[i].pages = randfromint(5, 2000);
        books[i].price = randfromdouble(1.00, 1000.00);
    }

    FILE *fp = fopen(argv[1], "wb");
    fwrite(books, sizeof(Book), COUNT, fp);
    fclose(fp);
    

    return 0;
}

int randfromint(int min, int max) 
{
    int range = (max - min); 
    int div = RAND_MAX / range;
    return min + (rand() / div);
}

double randfromdouble(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}
