#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

#define COUNT 10

typedef struct{
    char title[150];
    char author[100];
    int pages;
    double price;
}Book;

typedef struct Node
{
    Book book;
    struct Node* next;
}Node;

void print_list(Node* list);
char *rand_string(char *str, size_t size);
int randfromint(int min, int max);
double randfromdouble(double min, double max);
void push(Node** list, Book book);
int compareTitle (const void* t1, const void* t2);
Node* sortedMerge(Node* listA, Node* listB, int(*compareAuthor)(const void*, const void*));
void frontBackSplit(Node* list, Node** front, Node** back);
void mergeSort(Node** list, int(*compareAuthor)(const void*, const void*));
void listFree(Node** list);

int main(){
    struct  Node* head = NULL;
    srand(time(NULL));
    Book books[COUNT];
    
    for (int i = 0; i < COUNT; i++)
    {
        strcpy(books[i].title, rand_string(books[i].title, randfromint(10, 20)));
        strcpy(books[i].author, rand_string(books[i].author, randfromint(10, 20)));
        books[i].pages = randfromint(5, 2000);
        books[i].price = randfromdouble(1.00, 1000.00);
    }
    
    for (int i = 0; i < COUNT; i++)
    {
        push(&head, books[i]);
    }
    mergeSort(&head, compareTitle);
    
    print_list(head);
    
    listFree(&head);

    return 0;
}

void push(Node** list, Book book){
    Node* n = malloc(sizeof(Node));
    n->book = book;
    n->next = *list;
    *list = n;
}

void print_list(Node* list){
    Node* current = list;
    int cnt = 1;
    while (current){
        printf("%d.  %s %s %d %.2lf\n",cnt, current->book.title, current->book.author, current->book.pages, current->book.price);
        current = current->next;
        cnt++;
    }
    putchar('\n');
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

int compareTitle (const void* t1, const void* t2){
    Book *fst = (Book*) t1;
    Book *snd = (Book*) t2;
    char c1 = tolower(fst->title[0]);
    char c2 = tolower(snd->title[0]);
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

Node* sortedMerge(Node* listA, Node* listB, int(*cmp)(const void*, const void*)){
    Node* sorted = NULL;
    if (listA == NULL){
        return listB;
    }
    if (listB == NULL){
        return listA;
    }
    if (cmp(listA->book.title, listB->book.title) > 0){
        sorted = listA;
        sorted->next = sortedMerge(listA->next, listB, cmp);
    } else {
        sorted = listB;
        sorted->next = sortedMerge(listA, listB->next, cmp);
    }
    return sorted;
}


void frontBackSplit(Node* list, Node** front, Node** back){
    Node* slow = list;
    Node* fast = list->next;
    while (fast != NULL){
        fast = fast->next;
        if (fast  != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = list;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(Node** list, int(*cmp)(const void*, const void*)){
    if (*list == NULL || (*list)->next == NULL){
        return;
    }
    Node *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front, cmp);
    mergeSort(&back, cmp);
    *list = sortedMerge(front, back, cmp);
}

void listFree(Node** list){
    Node *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}
