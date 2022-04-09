#include <stdio.h>
#include <stdlib.h>

struct node *head = NULL;
struct node *tail = NULL;
struct node{
    int data;
    struct node *prev, *next;
};
struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void initialize(){
    head = createNode(0);
    tail = createNode(0);
    head->next = tail;
    tail->prev = head;
}

void enqueueFront(int data){
    struct node *newnode = createNode(data);
    struct node *temp;
    temp = head->next;
    head->next = newnode;
    newnode->prev = head;
    newnode->next = temp;
    temp->prev = newnode;
    
}
void enqueueRear(int data){
    struct node *newnode = createNode(data);
    struct node *temp;
    temp = tail->prev;
    tail->prev = newnode;
    newnode->next = tail;
    newnode->prev = temp;
    temp->next = newnode;
}
void deleteFront(){
    
    if (head->next == tail)
    {
        printf("Queue is empty.\n");
    }
    else{
        struct node *temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        free(temp);
    }
    return;
}
void deleteRear(){
    if (tail->prev == head)
    {
        printf("Queue is empty.\n");
    }
    else{
        struct node *temp = tail->prev;
        tail->prev = temp->prev;
        temp->prev->next = tail;
        free(temp);
    }
}
void display(){
    if (head->next == tail)
    {
        printf("Queue is empty.\n");
    }
    else{
        struct node* temp;
        temp = head->next;
        while (temp->next != tail)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }   
    }
}

int main() {
        int data, ch;
        initialize();
        while (1) {
                printf("1. Enqueue at front\n2. Enqueue at rear\n");
                printf("3. Dequeue at front\n4. Dequeue at rear\n");
                printf("5. Display\n6. Exit\n");
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter data:");
                                scanf("%d", &data);
                                enqueueFront(data);
                                break;

                        case 2:
                                printf("Enter data:");
                                scanf("%d", &data);
                                enqueueRear(data);
                                break;

                        case 3:
                                deleteFront();
                                break;

                        case 4:
                                deleteRear();
                                break;

                        case 5:
                                display();
                                break;

                        case 6:
                                exit(0);

                        default:
                                printf("Enter correct option\n");
                                break;
                }
        }
        return 0;
  }
