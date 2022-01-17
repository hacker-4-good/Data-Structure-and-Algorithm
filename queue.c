#include <stdio.h>
#include <stdlib.h>
#define max 5
#define and &&
#define or ||
int front_count=0;
int rear_count=0;
struct queue
{
    int items[max];
    int front;
    int rear;
};
typedef struct queue qe;
void createEmptyQueue(qe *q)
{
    q->front = -1;
    q->rear = -1;
}
int isfull(qe *q)
{
    if(q->rear == max-1)
        return 1;
    else
        return 0;
}
int isempty(qe *q)
{
    if(q->front==-1 and q->rear==-1)
        return 1;
    else
        return 0;
}
void enqueue(qe *q,int newitem)
{
    if(isfull(q))
    {
        printf("Queue is full");
        rear_count--;
    }
    else if(q->front==-1 and q->rear==-1)
    {
        q->front = 0;
        q->rear++;
        q->items[q->rear] = newitem;
        printf("Inserted item: %d",newitem);
    }
    else
    {
        q->rear++;
        q->items[q->rear] = newitem;
        printf("Inserted item: %d",newitem);
    }
    rear_count++;
    printf("\n");
}
void dequeue(qe *q)
{
    if(isempty(q))
    {
        printf("Queue is empty");
    }
    else if(q->front==q->rear)
    {
        printf("Deleted item: %d",q->items[q->front]);
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        printf("Deleted item: %d",q->items[q->front]);
        q->front++;
    }
    front_count++;
    printf("\n");
}
void printQueue(qe *q)
{
    printf("Queue: ");
    for(int i=front_count;i<rear_count;i++)
    {
        printf("%d ",q->items[i]);
    }
    printf("\n");
}
int main ()
{
    qe *q = (qe *)malloc(sizeof(qe));
    int choice,x;
    createEmptyQueue(q);
    printf("Queue Operation: \n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d",&x);
            enqueue(q,x);
            printQueue(q);
            break;

            case 2:
            dequeue(q);
            printQueue(q);
            break;

            case 3:
            exit(0);

            default:
            printf("Enter the correct choice");
        }
    }
    return 0;
}