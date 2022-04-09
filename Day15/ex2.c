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

void push(Node** list, Book book);
int compareTitle (const void* t1, const void* t2);
Node* sortedMerge(Node* listA, Node* listB, int(*compareAuthor)(const void*, const void*));
void frontBackSplit(Node* list, Node** front, Node** back);
void mergeSort(Node** list, int(*compareAuthor)(const void*, const void*));
void listFree(Node** list);
Book getNth(Node* head, size_t n);

int main(int argc, char* argv[]){

    if (argc != 3)
    {
        printf("Invalid arguments count.\n");
        exit(-1);
    }
    
    struct  Node* head = NULL;
    
    FILE *fp = fopen(argv[1], "rb");
    
    for (int i = 0; i < COUNT; i++)
    {
        Book book;
        fread(&book, sizeof(Book), 1, fp);
        push(&head, book);
    }
    mergeSort(&head, compareTitle);
    
    FILE *fd = fopen(argv[2], "wb");
    for (int i = 0; i < COUNT; i++)
    {
        Book book;
        book = getNth(head, i);
        fwrite(&book, sizeof(Book), 1, fd) ;
    }
    

    fclose(fd);
    fclose(fp);
    listFree(&head);

    return 0;
}

void push(Node** list, Book book){
    Node* n = malloc(sizeof(Node));
    n->book = book;
    n->next = *list;
    *list = n;
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

Book getNth(Node* head, size_t n){
    Node* current = head;
    while (n)
    {
        current = current->next;
        n--;
    }
    return current->book;
    
}
