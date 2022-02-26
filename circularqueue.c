#include <stdio.h>
#define max 5
int queue[max];
int front=-1, rear=-1;
int isfull()
{
    if((front==rear+1)||(front==0 && rear==max-1))
        return 1;
    return 0;
}
int isempty()
{
    if(front==-1)
        return 1;
    return 0;
}
void enqueue(int value)
{
    if(isfull())
    {
        printf("Queue is full");
    }
    else
    {
        if(front==-1)
        {
            front = 0;
        }
        rear = (rear+1)%max;
        queue[rear] = value;
        printf("Inserted --> %d",value);
    }
    printf("\n");
}
void dequeue()
{
    int element;
    if(isempty())
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        element = queue[front];
        if(front==rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front+1)%max;
        }
        printf("Deleted --> %d",element);
    }
    printf("\n");
}
void display()
{
    int i;
    if(isempty())
    {
        printf("Empty queue");
    }
    else
    {
        printf("Items --> ");
        for(i=front;i!=rear;i=(i+1)%max)
        {
            printf("%d ",queue[i]);
        }
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
            display();
            break;

            case 4:
            printf("Exit");
            break;

            default:
            printf("Enter the choice: ");
        }
    } while (ch!=4);
    return 0;
}