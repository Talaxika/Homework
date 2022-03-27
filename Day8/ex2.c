#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#define COUNT 10
#define EPS 0.0001

int* search(void* key,void* arr, size_t n, size_t size);
int compareKey(void* b, void* k);
/*
void bubbleSort(void* arr, int n, size_t size, int(*comp)(const void*, const void*));
void swap(void* pt1, void* pt2, size_t size);
int compareTitle (const void* t1, const void* t2);
int compareAuthor (const void* t1, const void* t2);
int compareCost (const void* c1, const void* c2);
int comparePages (const void* c1, const void* c2);
*/
typedef struct{
    char title[150];
    char author[150];
    int pages;
    double cost;
}Book;

int main() {
    srand(time(NULL));
    Book books[COUNT];

    const char titles[][100] = {"Aitle", "Bitle", "Citle", "Ditle", "Eitle", "Fitle", "Gitle", "Hitle", "Itle" , "Jitle"};
    const char authors[][100] = {"Author", "Bauthor", "Cauthor", "Dauthor", "Eauthor", "Fauthor", "Hauthor", "Iauthor", "Jauthor"};
    const int pages[10] = {10, 20, 300, 400, 500, 600, 750, 888, 920, 1000};
    const double costs[10] = {1.30, 2.40, 3.75, 4.30, 5.15, 20.50, 20.50, 80.10, 90.50, 100.35};

    for (int i = 0; i < COUNT; i++)
    {
        strcpy(books[i].title, titles[rand()%10]);
        strcpy(books[i].author, authors[rand()%10]);
        books[i].pages = pages[rand()%10];
        books[i].cost = costs[rand()%10];
    }
    size_t N = (size_t)COUNT;
    size_t size = sizeof(Book);
    double key = 20.50;


    Book* searched = (Book*)search(&key, books, N, size);
    if (searched == NULL)
    {
        printf("Book doesnt exist");
    }
    else{
        printf("%s is the title of the book with the price of %.2lf\n", searched->title, searched->cost);
    }

    for (int j = 0; j < COUNT; j++)
        {
            printf("%d) %s / %s / %d / %.2lf\n", j+1,books[j].title, books[j].author, books[j].pages, books[j].cost);
        }

    return 0;
}

int* search(void* key,void* arr, size_t n, size_t size){
    for (int i = 0; i < n*size; i += size)
    {   
        if (compareKey(arr + i, key) == 1)
        {
            return arr + i;
        }
    }
    return NULL;
}

int compareKey(void* b,void* k){
    Book* book = (Book*) b;
    double cost = *(double*)k;
    if (fabs(book->cost - cost)<EPS)
    {
        return 1;
    }
    return 0;
}
