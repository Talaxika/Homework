#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#define COUNT 10
#define EPS 0.0001


void bubbleSort(void* arr, int n, size_t size, int(*comp)(const void*, const void*));
void swap(void* pt1, void* pt2, size_t size);
int compareTitle (const void* t1, const void* t2);
int compareAuthor (const void* t1, const void* t2);
int compareCost (const void* c1, const void* c2);
int comparePages (const void* c1, const void* c2);

typedef struct{
    char title[150];
    char author[100];
    int pages;
    double cost;
}Book;

int main() {
    srand(time(NULL));
    Book books[COUNT];

    const char titles[][150] = {"Aitle", "Bitle", "Citle", "Ditle", "Eitle", "Fitle", "Gitle", "Hitle", "Itle" , "Jitle"};
    const char authors[][100] = {"Author", "Bauthor", "Cauthor", "Dauthor", "Eauthor", "Fauthor", "Hauthor", "Iauthor", "Jauthor"};
    const int pages[10] = {10, 20, 300, 400, 500, 600, 750, 888, 920, 1000};
    const double costs[10] = {1.30, 2.40, 3.75, 4.30, 5.15, 6.50, 7.80, 80.10, 90.50, 100.35};

    for (int i = 0; i < COUNT; i++)
    {
        strcpy(books[i].title, titles[rand()%10]);
        strcpy(books[i].author, authors[rand()%10]);
        books[i].pages = pages[rand()%10];
        books[i].cost = costs[rand()%10];
    }

    size_t size = sizeof(Book);

    int (*f[4])(const void*, const void*) = {compareTitle, compareAuthor,  compareCost, comparePages};
    for (int i = 0; i < 4; i++)
    {
        bubbleSort(books, COUNT, size, f[i]);

        if (i == 0)
        {
            printf("Compare Titles: \n");
            for (int j = 0; j < COUNT; j++)
            {
                printf("%d) %s\n", j+1, books[j].title);
            }
            
        }
        else if (i == 1)
        {
            printf("Compare Authors: \n");
            for (int j = 0; j < COUNT; j++)
            {
                printf("%d) %s\n", j+1, books[j].author);
            }
        }
        else if (i == 2)
        {
            printf("Compare Costs: \n");
            for (int j = 0; j < COUNT; j++)
            {
                printf("%d) %.2lf\n", j+1, books[j].cost);
            }
        }
        else{
            printf("Compare Pages: \n");
            for (int j = 0; j < COUNT; j++)
            {
                printf("%d) %d\n", j+1, books[j].pages);
            }
        }
    }


    return 0;
}


void swap(void* pt1, void* pt2, size_t size){
    uint8_t arr[size];
    memcpy(arr, pt1, size);
    memcpy(pt1, pt2, size);
    memcpy(pt2, arr, size);
}

void bubbleSort(void* arr, int n, size_t size, int(*comp)(const void*, const void*)){
    for (int i = 0; i < n - 1; i++)
    {
            for (int j = 0; j < (n-i-1)*size; j+=size)
            {
                if (comp((arr+j), (arr+j+size)) > 0)
                {
                    swap((arr+j),(arr+j+size), size);
                }
                
            }
            
    }
    
}

int compareTitle (const void* t1, const void* t2){
    Book *fst = (Book*) t1;
    Book *snd = (Book*) t2;
    char c1 = fst->title[0];
    char c2 = snd->title[0];
    if (c1 == c2)
    {
        return 0;
    }
    else if (c1>c2)
    {
        return 1;
    }
    return -1; 
}

int compareAuthor (const void* t1, const void* t2){
    Book *fst = (Book*) t1;
    Book *snd = (Book*) t2;
    char c1 = fst->author[0];
    char c2 = snd->author[0];
    if (c1 == c2)
    {
        return 0;
    }
    else if (c1<c2)
    {
        return 1;
    }
    return -1; 
}


int compareCost (const void* c1, const void* c2){
    Book *fst = (Book*)c1;
    Book *snd = (Book*)c2;
    if (fabs(fst->cost - snd->cost) < EPS)
    {
        return 0;
    }
    else if (fst->cost > snd->cost)
    {
        return 1;
    }
    return -1;   
}
int comparePages (const void* c1, const void* c2){
    Book *fst = (Book*)c1;
    Book *snd = (Book*)c2;
    return fst->pages > snd->pages; 
}
