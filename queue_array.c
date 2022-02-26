#include <stdio.h>
#define max 5
int queue[max];
int front = -1;
int rear  = -1;
int isfull()
{
    if(rear==max-1)
        return 1;
    return 0;
}
int isempty()
{
    if(front==-1 && rear==-1)
        return 1;
    return 0;
}
void enqueue(int value)
{
    if(isfull())
    {
        printf("Queue is full");
    }
    else if(front==-1 && rear==-1)
    {
        front = 0;
        rear = 0;
        queue[rear] = value;
        printf("Inserted item: %d",value);
    }
    else
    {
        rear = rear+1;
        queue[rear] = value;
        printf("Inserted item: %d",value);
    }
    printf("\n");
}
void dequeue()
{
    if(isempty())
    {
        printf("Queue is empty");
    }
    else if(front==rear)
    {
        printf("Deleted item: %d",queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Deleted item: %d",queue[front]);
        front = front+1;
    }
    printf("\n");
}
void printQueue()
{
    printf("Queue: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main ()
{
    int ch,val;
    printf("Enter the choice: ");
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Display");
    printf("\n4. Exit");
    do
    {
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the data: ");
            scanf("%d",&val);
            enqueue(val);
            break;

            case 2:
            dequeue();
            break;

            case 3:
            printQueue();
            break;

            case 4:
            break;

            default:
            printf("Enter the choice: ");
        }
    }while(ch!=4);
    return 0;
}