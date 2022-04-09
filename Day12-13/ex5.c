#include <stdio.h>
#include <stdlib.h>
# define SIZE 100
void enqueue(int);
void dequeue();
void show();
int inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;
int main()
{
    int ch, data;
    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(data);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            show();
            break;
            case 4:
            exit(0);
            default:
            printf("Incorrect choice \n");
        } 
    } 
} 
  
void enqueue(int data)
{
    
    if (Rear == SIZE - 1)
       printf("Queue empty \n");
    else
    {
        if (Front == - 1)
        Front = 0;
        Rear = Rear + 1;
        inp_arr[Rear] = data;
    }
} 
  
void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Queue full \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
        Front = Front + 1;
    }
} 
  
void show()
{
     
    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}
